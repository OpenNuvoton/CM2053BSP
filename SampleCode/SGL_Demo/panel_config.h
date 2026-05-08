/**************************************************************************//**
 * @file     panel_config.h
 * @brief    SGL_Demo 屏分辨率（须与 ILI9341 MADCTL 竖屏方向一致）
 *
 * @details  在包含 tft.h 之前须先包含本文件，使 `TFT_LCD_HOR_RES_MAX` / `VER` 与
 *           tft.c 中 ILI9341 窗口一致；否则易出现分辨率错配、带状花屏。
 ******************************************************************************/
#ifndef PANEL_CONFIG_H
#define PANEL_CONFIG_H

/* 竖屏 240×320：水平 240、垂直 320 */
#define PANEL_WIDTH            240
#define PANEL_HEIGHT           320

#define TFT_LCD_HOR_RES_MAX    PANEL_WIDTH
#define TFT_LCD_VER_RES_MAX    PANEL_HEIGHT

/* 供可选的 touch_adc_bsp.c 使用；当前 Keil 工程未编入该文件，保留宏便于日后接入触摸 */
#ifndef PANEL_TOUCH_REMAP_CAL_TO_240X320
#define PANEL_TOUCH_REMAP_CAL_TO_240X320  1
#endif

#endif /* PANEL_CONFIG_H */
