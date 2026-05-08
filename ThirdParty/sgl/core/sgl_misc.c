/* source/core/sgl_misc.c
 *
 * MIT License
 *
 * Copyright(c) 2023-present All contributors of SGL  
 * Document reference link: https://sgl-docs.readthedocs.io
 * 
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#include <sgl.h>

#if (CONFIG_SGL_BOOT_LOGO)

typedef struct sgl_logo {
    sgl_obj_t       obj;
    uint8_t         progress;
    uint8_t         alpha;
}sgl_logo_t;

#define SGL_LOGO_W    (26)
#define SGL_LOGO_H    (14)

const uint8_t sgl_logo_s[][4] = {
    {0, 0, 8, 2},
    {0, 2, 2, 8},
    {2, 6, 8, 8},
    {6, 8, 8, 14},
    {0, 12, 6, 14},
};

const uint8_t sgl_logo_g[][4] = {
    {9,  0,  17, 2},
    {9,  2,  11, 14},
    {11, 12, 17, 14},
    {15, 6,  17, 12},
    {13, 6,  15, 8},
};

const uint8_t sgl_logo_l[][4] = {
    {18, 0, 20, 14},
    {20, 12, 26, 14},
};

/* "nuvoton" block wordmark (49x14 grid), axis-aligned rects */
#define NUVOTON_LOGO_W    (49)
#define NUVOTON_LOGO_H    (14)

static const uint8_t nuvoton_logo_rects[][4] = {
    /* n */
    {0, 0, 1, 14}, {5, 0, 6, 14}, {1, 2, 2, 5}, {2, 5, 3, 8}, {3, 8, 4, 11}, {4, 11, 5, 14},
    /* u */
    {7, 0, 8, 11}, {12, 0, 13, 11}, {7, 11, 13, 14},
    /* v */
    {14, 0, 15, 5}, {15, 5, 16, 8}, {16, 8, 17, 11}, {17, 11, 18, 14},
    {19, 0, 20, 5}, {18, 5, 19, 8}, {17, 8, 18, 11},
    /* o */
    {22, 0, 26, 2}, {21, 2, 22, 12}, {26, 2, 27, 12}, {22, 12, 26, 14},
    /* t */
    {28, 0, 35, 2}, {30, 2, 32, 14},
    /* o */
    {36, 0, 40, 2}, {35, 2, 36, 12}, {40, 2, 41, 12}, {36, 12, 40, 14},
    /* n */
    {42, 0, 43, 14}, {47, 0, 48, 14}, {43, 2, 44, 5}, {44, 5, 45, 8}, {45, 8, 46, 11}, {46, 11, 47, 14},
};

static void sgl_logo_construct_cb(sgl_surf_t *surf, sgl_obj_t* obj, sgl_event_t *evt)
{
    sgl_logo_t *logo = (sgl_logo_t*)obj;
    int16_t w = obj->area.x2 - obj->area.x1 + 1;
    int16_t h = obj->area.y2 - obj->area.y1 + 1;

    const float scale_x = w / SGL_LOGO_W;
    const float scale_y = h / SGL_LOGO_H;
    sgl_rect_t rect;

    if(evt->type == SGL_EVENT_DRAW_MAIN) {
        sgl_area_t clip;

        if (!sgl_surf_clip(surf, &obj->area, &clip)) {
            return;
        }

        for (uint32_t i = 0; i < SGL_ARRAY_SIZE(sgl_logo_s); i++) {
            rect.x1 = sgl_logo_s[i][0] * scale_x + obj->area.x1;
            rect.y1 = sgl_logo_s[i][1] * scale_y + obj->area.y1;
            rect.x2 = sgl_logo_s[i][2] * scale_x + obj->area.x1 - 1;
            rect.y2 = sgl_logo_s[i][3] * scale_y + obj->area.y1 - 1;

            sgl_draw_fill_rect_with_border(surf, &clip, &rect, obj->radius, SGL_COLOR_RED, SGL_COLOR_BLUE, 0, logo->alpha);
        }

        for (uint32_t i = 0; i < SGL_ARRAY_SIZE(sgl_logo_g); i++) {
            rect.x1 = sgl_logo_g[i][0] * scale_x + obj->area.x1;
            rect.y1 = sgl_logo_g[i][1] * scale_y + obj->area.y1;
            rect.x2 = sgl_logo_g[i][2] * scale_x + obj->area.x1 - 1;
            rect.y2 = sgl_logo_g[i][3] * scale_y + obj->area.y1 - 1;

            sgl_draw_fill_rect_with_border(surf, &clip, &rect, obj->radius, SGL_COLOR_GREEN, SGL_COLOR_BLUE, 0, logo->alpha);
        }

        for (uint32_t i = 0; i < SGL_ARRAY_SIZE(sgl_logo_l); i++) {
            rect.x1 = sgl_logo_l[i][0] * scale_x + obj->area.x1;
            rect.y1 = sgl_logo_l[i][1] * scale_y + obj->area.y1;
            rect.x2 = sgl_logo_l[i][2] * scale_x + obj->area.x1 - 1;
            rect.y2 = sgl_logo_l[i][3] * scale_y + obj->area.y1 - 1;

            sgl_draw_fill_rect_with_border(surf, &clip, &rect, obj->radius, SGL_COLOR_BLUE, SGL_COLOR_BLUE, 0, logo->alpha);
        }
    }
}

static void sgl_nuvoton_logo_construct_cb(sgl_surf_t *surf, sgl_obj_t* obj, sgl_event_t *evt)
{
    sgl_logo_t *logo = (sgl_logo_t*)obj;
    int16_t w = obj->area.x2 - obj->area.x1 + 1;
    int16_t h = obj->area.y2 - obj->area.y1 + 1;

    const float scale_x = (float)w / (float)NUVOTON_LOGO_W;
    const float scale_y = (float)h / (float)NUVOTON_LOGO_H;
    sgl_rect_t rect;

    if (evt->type == SGL_EVENT_DRAW_MAIN) {
        sgl_area_t clip;

        if (!sgl_surf_clip(surf, &obj->area, &clip)) {
            return;
        }

        for (uint32_t i = 0; i < SGL_ARRAY_SIZE(nuvoton_logo_rects); i++) {
            rect.x1 = (int16_t)((float)nuvoton_logo_rects[i][0] * scale_x + obj->area.x1);
            rect.y1 = (int16_t)((float)nuvoton_logo_rects[i][1] * scale_y + obj->area.y1);
            rect.x2 = (int16_t)((float)nuvoton_logo_rects[i][2] * scale_x + obj->area.x1 - 1);
            rect.y2 = (int16_t)((float)nuvoton_logo_rects[i][3] * scale_y + obj->area.y1 - 1);

            sgl_draw_fill_rect_with_border(surf, &clip, &rect, obj->radius,
                SGL_COLOR_RED, sgl_rgb(0x99, 0x00, 0x00), 0, logo->alpha);
        }
    }
}

static sgl_obj_t* sgl_nuvoton_logo_create(sgl_obj_t* parent)
{
    sgl_logo_t *logo = sgl_malloc(sizeof(sgl_logo_t));
    if (logo == NULL) {
        SGL_LOG_ERROR("sgl_nuvoton_logo_create: malloc failed");
        return NULL;
    }

    memset(logo, 0, sizeof(sgl_logo_t));

    sgl_obj_t *obj = &logo->obj;
    sgl_obj_init(&logo->obj, parent);
    obj->construct_fn = sgl_nuvoton_logo_construct_cb;
    logo->alpha = SGL_ALPHA_MAX;
    sgl_obj_set_border_width(obj, 0);
    return obj;
}

sgl_obj_t* sgl_logo_create(sgl_obj_t* parent)
{
    sgl_logo_t *logo = sgl_malloc(sizeof(sgl_logo_t));
    if (logo == NULL) {
        SGL_LOG_ERROR("sgl_logo_create: malloc failed");
        return NULL;
    }

    /* set object all member to zero */
    memset(logo, 0, sizeof(sgl_logo_t));

    sgl_obj_t *obj = &logo->obj;
    sgl_obj_init(&logo->obj, parent);
    obj->construct_fn = sgl_logo_construct_cb;
    logo->alpha = SGL_ALPHA_MAX;
    sgl_obj_set_border_width(obj, 0);
    return obj;
}

void sgl_logo_set_alpha(sgl_obj_t* obj, uint8_t alpha)
{
    sgl_logo_t *logo = (sgl_logo_t*)obj;
    logo->alpha = alpha;
    sgl_obj_set_dirty(obj);
}

void sgl_logo_anim(sgl_anim_t *anim, int32_t value)
{
    sgl_obj_t *logo = (sgl_obj_t*)anim->data;
    sgl_logo_set_alpha(logo, value);
}

/**
 * @brief to show the SGL logo then the Nuvoton wordmark after sgl init
 * @param none
 * @return none
 * @note: you can call this function in your main function to show the boot logos
 */
void sgl_boot_logo(void)
{
#if 0
    sgl_obj_t *logo = sgl_logo_create(NULL);
    sgl_obj_set_size(logo, SGL_SCREEN_WIDTH / 3, SGL_SCREEN_HEIGHT / 3);
    sgl_obj_set_pos_align(logo, SGL_ALIGN_CENTER);
    sgl_obj_set_radius(logo, 0);

    sgl_anim_t *anim = sgl_anim_create();
    sgl_anim_set_data(anim, logo);
    sgl_anim_set_act_duration(anim, 1000);
    sgl_anim_set_start_value(anim, SGL_ALPHA_MAX);
    sgl_anim_set_end_value(anim, SGL_ALPHA_MIN);
    sgl_anim_set_path(anim, sgl_logo_anim, SGL_ANIM_PATH_LINEAR);
    sgl_anim_start(anim, SGL_ANIM_REPEAT_ONCE);

    while (!sgl_anim_is_finished(anim)) {
        sgl_task_handle();
    }

    sgl_anim_delete(anim);
    sgl_obj_delete(logo);
#endif
    sgl_obj_t *nlogo = sgl_nuvoton_logo_create(NULL);
    sgl_obj_set_size(nlogo, (SGL_SCREEN_WIDTH * 4) / 5, SGL_SCREEN_HEIGHT / 5);
    sgl_obj_set_pos_align(nlogo, SGL_ALIGN_CENTER);
    sgl_obj_set_radius(nlogo, 0);

    sgl_anim_t *animN = sgl_anim_create();
    sgl_anim_set_data(animN, nlogo);
    sgl_anim_set_act_duration(animN, 1000);
    sgl_anim_set_start_value(animN, SGL_ALPHA_MAX);
    sgl_anim_set_end_value(animN, SGL_ALPHA_MIN);
    sgl_anim_set_path(animN, sgl_logo_anim, SGL_ANIM_PATH_LINEAR);
    sgl_anim_start(animN, SGL_ANIM_REPEAT_ONCE);

    while (!sgl_anim_is_finished(animN)) {
        sgl_task_handle();
    }

    sgl_anim_delete(animN);
    sgl_obj_delete(nlogo);
}

#endif // !CONFIG_SGL_BOOT_LOGO
