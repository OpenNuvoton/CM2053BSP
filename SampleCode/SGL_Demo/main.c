/****************************************************************************
 * @file     main.c
 * @brief    CM2053 + ILI9341：SGL_Demo 竖屏仪表（单页、无触摸）
 * @details  启动链：SYS_Init → UartDebugInit → sgl_logdev/fbdev → tft_init →
 *           SysTick → sgl_init → 建 UI → 死循环内 dashboard_update + sgl_task_handle。
 *           SGL 源码：`ThirdParty/sgl`；堆与队列：`sgl_config.h`。
 ******************************************************************************/

#include "NuMicro.h"
#include "sgl.h"

#include "panel_config.h"
#include "tft.h"

#ifndef SGL_SAMPLE_UART_LOG
#define SGL_SAMPLE_UART_LOG  1
#endif

/** 车速条与数字刷新周期（ms）；慢速区见 DASH_SLOW_MS */
#define DASH_SPEED_MS  1u
#define DASH_SLOW_MS   150u

/* FontAwesome / iconfont：UTF-8，与对应 .c 字库一致 */
#define SGL_ICON_F013_USER_NAME "\xEF\x80\x93"
#define SGL_ICON_F015_USER_NAME "\xEF\x80\x95"
#define SGL_ICON_F028_USER_NAME "\xEF\x80\xA8"
#define SGL_ICON_F14D_USER_NAME "\xEF\x85\x8D"
#define SGL_ICON_E612_USER_NAME "\xEE\x98\x92"
#define SGL_ICON_E613_USER_NAME "\xEE\x98\x93"

/* 行缓冲高度：↑RAM、↓分段次数；与 sgl_config.h 中堆等一起调 */
#ifndef PANEL_STRIP_MAX_LINES
    #define PANEL_STRIP_MAX_LINES  1
#endif
#define PANEL_STRIP_LINES  ((PANEL_HEIGHT) < PANEL_STRIP_MAX_LINES ? (PANEL_HEIGHT) : PANEL_STRIP_MAX_LINES)

static sgl_color_t panel_buffer[PANEL_WIDTH * PANEL_STRIP_LINES];

/** SGL 日志与样例提示；阻塞写 UART4（与 UartDebugInit 一致） */
static void uart_puts(const char *str)
{
    while (*str) {
        while (UART_IS_TX_FULL(UART4)) {}
        UART_WRITE(UART4, *str++);
    }
}

#define DASH_SPEED_BLOCK_COUNT 16

/* 仪表控件句柄，由 dashboard_update() 周期性刷新 */
typedef struct {
    sgl_obj_t *speed_blocks[DASH_SPEED_BLOCK_COUNT];
    sgl_obj_t *lbl_speed;
    sgl_obj_t *lbl_speed_unit;
    sgl_obj_t *lbl_mpa;
    sgl_obj_t *lbl_v;
    sgl_obj_t *lbl_trip_km;
    sgl_obj_t *lbl_trip_m;
} dashboard_widgets_t;

static dashboard_widgets_t s_dash;
static uint32_t s_dash_trip_m;
/** 演示车速：仅在速度区按步进刷新，0~120 每次 +5 */
static unsigned s_dash_speed_demo;

/* sgl_label 只保存指针；各域独立静态缓冲（勿合并为单 buf） */
static char s_dash_buf_speed[8];
static char s_dash_buf_mpa[8];
static char s_dash_buf_v[8];
static char s_dash_buf_trip_km[12];
static char s_dash_buf_trip_m[8];

/* 车速条配色 */
static const sgl_color_t s_dash_rainbow[DASH_SPEED_BLOCK_COUNT] = {
    sgl_rgb(0xFF, 0x00, 0x00), sgl_rgb(0xFF, 0x5A, 0x00), sgl_rgb(0xFF, 0xA0, 0x00), sgl_rgb(0xFF, 0xD0, 0x00),
    sgl_rgb(0xE8, 0xFF, 0x00), sgl_rgb(0x9C, 0xFF, 0x00), sgl_rgb(0x30, 0xFF, 0x00), sgl_rgb(0x00, 0xFF, 0x66),
    sgl_rgb(0x00, 0xFF, 0xC8), sgl_rgb(0x00, 0xC8, 0xFF), sgl_rgb(0x00, 0x66, 0xFF), sgl_rgb(0x24, 0x20, 0xFF),
    sgl_rgb(0x70, 0x00, 0xFF), sgl_rgb(0xB0, 0x00, 0xFF), sgl_rgb(0xE0, 0x00, 0xE8), sgl_rgb(0xFF, 0x00, 0xA0)
};

/* 四线段画矩形边框（rect 全透明时单独描边更直观） */
static void dash_draw_box_border(sgl_obj_t *parent, int16_t x, int16_t y, int16_t w, int16_t h,
                                 uint8_t border_w, sgl_color_t color)
{
    const int16_t xr = (int16_t)(x + w - 1);
    const int16_t yb = (int16_t)(y + h - 1);
    const struct {
        int16_t x1, y1, x2, y2;
    } seg[4] = {
        { x, y, xr, y },
        { x, yb, xr, yb },
        { x, y, x, yb },
        { xr, y, xr, yb },
    };
    unsigned i;
    for (i = 0u; i < 4u; i++) {
        sgl_obj_t *ln = sgl_line_create(parent);
        sgl_line_set_pos(ln, seg[i].x1, seg[i].y1, seg[i].x2, seg[i].y2);
        sgl_line_set_width(ln, border_w);
        sgl_line_set_color(ln, color);
        sgl_line_set_alpha(ln, SGL_ALPHA_MAX);
        sgl_obj_set_dirty(ln);
    }
}

/** 卡片左上角 iconfont 装饰图标 */
static void dash_card_side_icon(sgl_obj_t *parent, const char *utf8, sgl_color_t color)
{
    sgl_obj_t *lbl = sgl_label_create(parent);
    sgl_obj_set_pos(lbl, 6, 6);
    sgl_obj_set_size(lbl, 38, 26);
    sgl_label_set_text(lbl, utf8);
    sgl_label_set_text_color(lbl, color);
    sgl_label_set_text_align(lbl, SGL_ALIGN_LEFT_MID);
    sgl_label_set_font(lbl, &iconfont_23);
    sgl_obj_set_dirty(lbl);
}

/** 透明圆角 rect + 在 root 上画蓝边框 */
static sgl_obj_t *dash_card_create(sgl_obj_t *root, int16_t x, int16_t y, int16_t w, int16_t h, uint8_t radius)
{
    sgl_obj_t *card = sgl_rect_create(root);
    sgl_obj_set_pos(card, x, y);
    sgl_obj_set_size(card, w, h);
    sgl_rect_set_radius(card, radius);
    sgl_rect_set_border_width(card, 0);
    sgl_rect_set_color(card, SGL_COLOR_BLACK);
    sgl_rect_set_alpha(card, SGL_ALPHA_MIN);
    sgl_obj_set_dirty(card);
    dash_draw_box_border(root, x, y, w, h, 2, SGL_COLOR_BLUE);
    return card;
}

/** 创建标签并 set_dirty；返回指针供后续 set_text */
static sgl_obj_t *dash_label(sgl_obj_t *parent, int16_t x, int16_t y, int16_t w, int16_t h,
                            const char *text, sgl_color_t color, sgl_align_type_t align, const sgl_font_t *font)
{
    sgl_obj_t *lbl = sgl_label_create(parent);
    sgl_obj_set_pos(lbl, x, y);
    sgl_obj_set_size(lbl, w, h);
    sgl_label_set_text(lbl, text);
    sgl_label_set_text_color(lbl, color);
    sgl_label_set_text_align(lbl, align);
    sgl_label_set_font(lbl, font);
    sgl_obj_set_dirty(lbl);
    return lbl;
}

static void dash_nav_btn_set_fa_icon(sgl_obj_t *p, const char *icon_utf8)
{
    sgl_button_set_text(p, icon_utf8);
    sgl_button_set_text_color(p, SGL_COLOR_WHITE);
    sgl_button_set_text_align(p, SGL_ALIGN_CENTER);
    sgl_button_set_font(p, &FontAwesome_23);
    sgl_obj_set_dirty(p);
}

static const char *const s_dash_nav_fa[4] = {
    SGL_ICON_F015_USER_NAME, SGL_ICON_F013_USER_NAME, SGL_ICON_F028_USER_NAME, SGL_ICON_F14D_USER_NAME,
};

/** 底部四枚 FontAwesome 按钮：纯装饰，无触摸回调 */
static void dash_create_bottom_nav_buttons(sgl_obj_t *parent, int16_t trip_y, int16_t trip_h)
{
    const int16_t trip_bottom = (int16_t)(trip_y + trip_h);
    const int16_t bh = 34;
    const int16_t by = (int16_t)(trip_bottom + (PANEL_HEIGHT - trip_bottom - bh) / 2);
    const int16_t bw = 55;
    const int16_t gap = 3;
    const int16_t x0 = 5;
    unsigned i;

    for (i = 0u; i < 4u; i++) {
        int16_t bx = (int16_t)(x0 + (int16_t)i * (bw + gap));
        sgl_obj_t *btn = sgl_button_create(parent);
        sgl_obj_set_pos(btn, bx, by);
        sgl_obj_set_size(btn, bw, bh);
        sgl_button_set_radius(btn, 4);
        sgl_button_set_border_width(btn, 1);
        sgl_button_set_color(btn, sgl_rgb(0x18, 0x28, 0x48));
        sgl_button_set_border_color(btn, SGL_COLOR_BLUE);
        sgl_button_set_alpha(btn, SGL_ALPHA_MAX);
        sgl_button_set_text(btn, NULL);
        sgl_obj_set_dirty(btn);
        dash_nav_btn_set_fa_icon(btn, s_dash_nav_fa[i]);
    }
}

/** 车速区 16 根柱（写入 s_dash.speed_blocks[]） */
static void dash_build_speed_bars(sgl_obj_t *gauge_card)
{
    const int16_t block_w = 9;
    const int16_t gap = 2;
    const int16_t x0 = 5;
    const int16_t y_base = 48;
    const int16_t h_min = 8;
    unsigned i;

    for (i = 0u; i < DASH_SPEED_BLOCK_COUNT; i++) {
        int16_t bh = (int16_t)(h_min + (int16_t)i);
        sgl_obj_t *blk = sgl_rect_create(gauge_card);
        sgl_obj_set_pos(blk, (int16_t)(x0 + (int16_t)i * (block_w + gap)), (int16_t)(y_base - bh));
        sgl_obj_set_size(blk, block_w, bh);
        sgl_rect_set_radius(blk, 2);
        sgl_rect_set_border_width(blk, 0);
        sgl_rect_set_color(blk, sgl_rgb(0x00, 0x18, 0x38));
        sgl_rect_set_alpha(blk, SGL_ALPHA_MAX);
        sgl_obj_set_dirty(blk);
        s_dash.speed_blocks[i] = blk;
    }
}

/** MPa / 电压 / Trip 三卡片 + 标签（写入 s_dash 对应 lbl） */
static void dash_build_metric_cards(sgl_obj_t *root)
{
    sgl_obj_t *card_mpa = dash_card_create(root, 10, 126, 110, 76, 10);
    dash_card_side_icon(card_mpa, SGL_ICON_E612_USER_NAME, SGL_COLOR_TOMATO);
    dash_label(card_mpa, 44, 6, 60, 26, "MPa", SGL_COLOR_WHITE, SGL_ALIGN_LEFT_MID, &song23);
    s_dash.lbl_mpa = dash_label(card_mpa, 5, 36, 100, 34, "0.0", SGL_COLOR_GOLD, SGL_ALIGN_CENTER, &song23);

    sgl_obj_t *card_v = dash_card_create(root, 120, 126, 110, 76, 10);
    dash_card_side_icon(card_v, SGL_ICON_E613_USER_NAME, SGL_COLOR_GREEN);
    dash_label(card_v, 58, 6, 38, 26, "V", SGL_COLOR_WHITE, SGL_ALIGN_LEFT_MID, &song23);
    s_dash.lbl_v = dash_label(card_v, 5, 36, 100, 34, "12.0", SGL_COLOR_YELLOW_GREEN, SGL_ALIGN_CENTER, &song23);

    sgl_obj_t *card_trip = dash_card_create(root, 10, 204, 220, 60, 10);
    dash_label(card_trip, 8, 4, 96, 22, "Trip", SGL_COLOR_SAND, SGL_ALIGN_TOP_LEFT, &song23);
    s_dash.lbl_trip_km = dash_label(card_trip, 80, 30, 80, 28, "0Km", SGL_COLOR_WHITE, SGL_ALIGN_CENTER, &song23);
    s_dash.lbl_trip_m = dash_label(card_trip, 160, 30, 60, 28, "0m", SGL_COLOR_WHITE, SGL_ALIGN_CENTER, &song23);
}

/** 无符号十进制转字符串（不拉 printf） */
static void u_to_dec_str(unsigned v, char *buf, unsigned buf_sz)
{
    if (buf_sz == 0u)
        return;
    if (v == 0u) {
        buf[0] = '0';
        buf[1] = '\0';
        return;
    }

    char tmp[10];
    unsigned n = 0u;
    while (v != 0u && n < (sizeof(tmp) / sizeof(tmp[0])))
    {
        tmp[n++] = (char)('0' + (v % 10u));
        v /= 10u;
    }

    unsigned i = 0u;
    while (n != 0u && i + 1u < buf_sz) {
        buf[i++] = tmp[--n];
    }
    buf[i] = '\0';
}

/** buf 末尾追加 ASCII 后缀（cap 含 '\0'） */
static void str_append_ascii(char *buf, unsigned cap, const char *suf)
{
    unsigned i = 0u;
    while (i + 1u < cap && buf[i] != '\0')
        i++;
    while (suf != NULL && *suf != '\0' && i + 1u < cap)
        buf[i++] = *suf++;
    if (i < cap)
        buf[i] = '\0';
}

/** 按车速刷新 16 根彩色柱 */
static void dash_speed_bar_apply(unsigned speed, uint32_t t)
{
    unsigned active = (speed * DASH_SPEED_BLOCK_COUNT + 119u) / 120u;
    unsigned phase = (unsigned)((t / 50u) % DASH_SPEED_BLOCK_COUNT);
    unsigned i;
    for (i = 0u; i < DASH_SPEED_BLOCK_COUNT; i++) {
        sgl_color_t c = sgl_rgb(0x00, 0x18, 0x38);
        if (i < active)
            c = s_dash_rainbow[(i + phase) % DASH_SPEED_BLOCK_COUNT];
        sgl_rect_set_color(s_dash.speed_blocks[i], c);
        sgl_obj_set_dirty(s_dash.speed_blocks[i]);
    }
}

/** MPa / V / Trip：演示波形与累计米数（由 dashboard_update 按 DASH_SLOW_MS 调用） */
static void dash_slow_metrics_apply(uint32_t t)
{
    unsigned v100 = (unsigned)((t / 90u) % 100u);
    unsigned d0 = v100 / 10u;
    unsigned d1 = v100 % 10u;
    s_dash_buf_mpa[0] = (char)('0' + d0);
    s_dash_buf_mpa[1] = '.';
    s_dash_buf_mpa[2] = (char)('0' + d1);
    s_dash_buf_mpa[3] = '\0';
    sgl_label_set_text(s_dash.lbl_mpa, s_dash_buf_mpa);
    sgl_obj_set_dirty(s_dash.lbl_mpa);

    {
        unsigned idx = (unsigned)((t / 110u) % 51u);
        unsigned v10 = 100u + idx;
        unsigned ip = v10 / 10u;
        unsigned fp = v10 % 10u;
        s_dash_buf_v[0] = (char)('0' + (ip / 10u));
        s_dash_buf_v[1] = (char)('0' + (ip % 10u));
        s_dash_buf_v[2] = '.';
        s_dash_buf_v[3] = (char)('0' + fp);
        s_dash_buf_v[4] = '\0';
        sgl_label_set_text(s_dash.lbl_v, s_dash_buf_v);
        sgl_obj_set_dirty(s_dash.lbl_v);
    }

    {
        uint32_t m = s_dash_trip_m;
        unsigned km = (unsigned)(m / 1000u);
        unsigned rm = (unsigned)(m % 1000u);
        u_to_dec_str(km, s_dash_buf_trip_km, sizeof(s_dash_buf_trip_km));
        str_append_ascii(s_dash_buf_trip_km, sizeof(s_dash_buf_trip_km), "Km");
        sgl_label_set_text(s_dash.lbl_trip_km, s_dash_buf_trip_km);
        sgl_obj_set_dirty(s_dash.lbl_trip_km);
        u_to_dec_str(rm, s_dash_buf_trip_m, sizeof(s_dash_buf_trip_m));
        str_append_ascii(s_dash_buf_trip_m, sizeof(s_dash_buf_trip_m), "m");
        sgl_label_set_text(s_dash.lbl_trip_m, s_dash_buf_trip_m);
        sgl_obj_set_dirty(s_dash.lbl_trip_m);
    }
}

/** 演示数据：车速 0~120 步进 +5；慢速区减轻 SPI */
static void dashboard_update(void)
{
    static uint32_t s_last_ms;
    static uint32_t s_last_speed_ms;
    uint32_t t = sgl_tick_get();

    if (s_last_speed_ms == 0u || (t - s_last_speed_ms) >= DASH_SPEED_MS) {
        s_last_speed_ms = t;
        unsigned speed = s_dash_speed_demo;
        s_dash_speed_demo += 5u;
        if (s_dash_speed_demo > 120u)
            s_dash_speed_demo = 0u;
        dash_speed_bar_apply(speed, t);
        u_to_dec_str(speed, s_dash_buf_speed, sizeof(s_dash_buf_speed));
        sgl_label_set_text(s_dash.lbl_speed, s_dash_buf_speed);
        sgl_obj_set_dirty(s_dash.lbl_speed);
    }

    if (s_last_ms != 0u && (t - s_last_ms) < DASH_SLOW_MS)
        return;

    {
        uint32_t dt = (s_last_ms == 0u) ? 0u : (t - s_last_ms);
        s_last_ms = t;
        s_dash_trip_m += (dt > 500u) ? 1u : (dt / 5u);
    }
    dash_slow_metrics_apply(t);
}

/** HIRC、GPIO/SPI0、ILI9341 脚、调试 UART MFP；SPI0=PB12~15，DC/RST=PA6/7，背光 PC2 */
void SYS_Init(void)
{
    CLK_EnableXtalRC(CLK_PWRCTL_HIRCEN_Msk);
    CLK_WaitClockReady(CLK_STATUS_HIRCSTB_Msk);
    CLK_SetHCLK(CLK_CLKSEL0_HCLKSEL_HIRC, CLK_CLKDIV0_HCLK(1));
    CLK->PCLKDIV = CLK_PCLKDIV_APB0DIV_DIV1 | CLK_PCLKDIV_APB1DIV_DIV1;

    CLK_EnableModuleClock(GPA_MODULE);
    CLK_EnableModuleClock(GPB_MODULE);
    CLK_EnableModuleClock(GPC_MODULE);
    UartDebugCLK();
    CLK_EnableModuleClock(SPI0_MODULE);
    CLK_SetModuleClock(SPI0_MODULE, CLK_CLKSEL2_SPI0SEL_PCLK1, MODULE_NoMsk);
    UartDebugMFP();

    SYS->GPA_MFPL = (SYS->GPA_MFPL & ~(SYS_GPA_MFPL_PA0MFP_Msk | SYS_GPA_MFPL_PA1MFP_Msk | SYS_GPA_MFPL_PA6MFP_Msk | SYS_GPA_MFPL_PA7MFP_Msk)) |
                    SYS_GPA_MFPL_PA0MFP_GPIO | SYS_GPA_MFPL_PA1MFP_GPIO |
                    SYS_GPA_MFPL_PA6MFP_GPIO | SYS_GPA_MFPL_PA7MFP_GPIO;

    SYS->GPB_MFPH = (SYS->GPB_MFPH & ~(SYS_GPB_MFPH_PB12MFP_Msk | SYS_GPB_MFPH_PB13MFP_Msk |
                                         SYS_GPB_MFPH_PB14MFP_Msk | SYS_GPB_MFPH_PB15MFP_Msk)) |
                    SYS_GPB_MFPH_PB12MFP_SPI0_MOSI | SYS_GPB_MFPH_PB13MFP_SPI0_MISO |
                    SYS_GPB_MFPH_PB14MFP_SPI0_CLK | SYS_GPB_MFPH_PB15MFP_GPIO;
    SYS->GPC_MFPL = (SYS->GPC_MFPL & ~(SYS_GPC_MFPL_PC2MFP_Msk)) | SYS_GPC_MFPL_PC2MFP_GPIO;

    PB->SMTEN |= GPIO_SMTEN_SMTEN14_Msk;

    GPIO_SetMode(PA, BIT6 | BIT7, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PB, BIT15, GPIO_MODE_OUTPUT);
    GPIO_SetMode(PC, BIT2, GPIO_MODE_OUTPUT);
    PB15 = 1;
    PC2 = 1;

    SPI_Open(SPI0, SPI_MASTER, SPI_MODE_0, 8, 24000000);
    SPI_SET_MSB_FIRST(SPI0);
    SPI_DisableAutoSS(SPI0);

    SystemCoreClockUpdate();
}

/** SysTick 1ms → `sgl_tick_inc(1)`；须先 `SystemCoreClockUpdate()` */
static void enable_systick_for_sgl(void)
{
    SysTick->LOAD = SystemCoreClock / 1000 - 1;
    SysTick->VAL  = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE_Msk |
                    SysTick_CTRL_TICKINT_Msk   |
                    SysTick_CTRL_ENABLE_Msk;
    __enable_irq();
}

void SysTick_Handler(void)
{
    (void)SysTick->CTRL;
    sgl_tick_inc(1);
}

int main(void)
{
    SYS_UnlockReg();
    SYS_Init();
    SYS_LockReg();
    UartDebugInit();

#if SGL_SAMPLE_UART_LOG
    uart_puts("\n\n+-----------------------------------------------------+\n");
    uart_puts("|                 SGL on CM2053 + ILI9341            |\n");
    uart_puts("+-----------------------------------------------------+\n");
#endif

    sgl_logdev_register(uart_puts);
    {
        sgl_fbinfo_t fbinfo = {
            .xres        = PANEL_WIDTH,
            .yres        = PANEL_HEIGHT,
            .flush_area  = demo_panel_flush_area,
            .buffer      = { panel_buffer, },
            .buffer_size = SGL_ARRAY_SIZE(panel_buffer),
        };
        sgl_fbdev_register(&fbinfo);
    }

    uart_puts("LCD init start...\n");
    tft_init();
    uart_puts("LCD init done.\n");

    enable_systick_for_sgl();

    if (sgl_init() != 0) {
        uart_puts("sgl_init failed!\n");
        for (;;) {}
    }

#if SGL_SAMPLE_UART_LOG
    uart_puts("SGL init done, entering main loop.\n");
#endif

    sgl_obj_t *root = sgl_rect_create(NULL);
    sgl_obj_set_pos(root, 0, 0);
    sgl_obj_set_size(root, PANEL_WIDTH, PANEL_HEIGHT);
    sgl_rect_set_radius(root, 0);
    sgl_rect_set_border_width(root, 0);
    sgl_rect_set_color(root, SGL_COLOR_BLACK);
    sgl_rect_set_alpha(root, SGL_ALPHA_MAX);
    sgl_obj_set_dirty(root);

    {
        sgl_obj_t *gauge = dash_card_create(root, 10, 6, 220, 118, 14);
        dash_build_speed_bars(gauge);
        s_dash.lbl_speed =
            dash_label(gauge, 0, 52, 220, 28, "0", SGL_COLOR_WHITE, SGL_ALIGN_CENTER, &song23);
        s_dash.lbl_speed_unit =
            dash_label(gauge, 0, 78, 220, 22, "Km/h", SGL_COLOR_DEEP_PINK, SGL_ALIGN_CENTER, &song23);
    }

    dash_build_metric_cards(root);

    s_dash_trip_m = 0u;
    s_dash_speed_demo = 0u;
    dash_create_bottom_nav_buttons(root, 204, 60);

    sgl_screen_load(root);
    sgl_task_handle_sync();
    dashboard_update();
    sgl_task_handle_sync();

    for (;;) {
        dashboard_update();
        sgl_task_handle();
    }
}
