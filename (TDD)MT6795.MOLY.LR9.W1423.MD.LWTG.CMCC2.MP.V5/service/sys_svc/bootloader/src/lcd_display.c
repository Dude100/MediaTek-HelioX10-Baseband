/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. 
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   lcd_display.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is BL firmware update engine display function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __LCD_DRIVER_IN_BL__

/* include LCD driver setting and predefined MACROs */
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "lcd_if.h"
#include "lcd_fota.h"
#include "lcd_sw_inc.h"
#include "lcd_sw_rnd.h"

#ifdef __BG_IMAGE__
#include "gdi_image_alpha_bmp_v2_internal.h"
#endif

/* information of progressive bar image resource */
#if (UI_DEVICE_WIDTH == 128) && ((UI_DEVICE_HEIGHT == 128) || (UI_DEVICE_HEIGHT == 160))
    #define BG_WIDTH		116
    #define BG_HEIGHT		47
    #define BAR_X			11
    #define BAR_Y			23
    #define BAR_WIDTH		95
    #define BAR_HEIGHT		6
#elif (UI_DEVICE_WIDTH == 176) && (UI_DEVICE_HEIGHT == 220)
    #define BG_WIDTH		160
    #define BG_HEIGHT		65
    #define BAR_X			15
    #define BAR_Y			31
    #define BAR_WIDTH		131
    #define BAR_HEIGHT		9
#elif (UI_DEVICE_WIDTH == 240) && (UI_DEVICE_HEIGHT == 320)
    #define BG_WIDTH		200
    #define BG_HEIGHT		81
    #define BAR_X			18
    #define BAR_Y			39
    #define BAR_WIDTH		165
    #define BAR_HEIGHT		11
#elif (UI_DEVICE_WIDTH == 320) && (UI_DEVICE_HEIGHT == 240)
    #define BG_WIDTH		200
    #define BG_HEIGHT		81
    #define BAR_X			27
    #define BAR_Y			35
    #define BAR_WIDTH		147
    #define BAR_HEIGHT		14
#elif (UI_DEVICE_WIDTH == 240) && (UI_DEVICE_HEIGHT == 400)
    #define BG_WIDTH		200
    #define BG_HEIGHT		81
    #define BAR_X			18
    #define BAR_Y			39
    #define BAR_WIDTH		165
    #define BAR_HEIGHT		11
#elif (UI_DEVICE_WIDTH == 320) && (UI_DEVICE_HEIGHT == 480)
    #define BG_WIDTH		200
    #define BG_HEIGHT		81
    #define BAR_X			18
    #define BAR_Y			39
    #define BAR_WIDTH		165
    #define BAR_HEIGHT		11
#elif (UI_DEVICE_WIDTH == 480) && (UI_DEVICE_HEIGHT == 800)
    #define BG_WIDTH		200
    #define BG_HEIGHT		81
    #define BAR_X			18
    #define BAR_Y			39
    #define BAR_WIDTH		165
    #define BAR_HEIGHT		11
#else
    #error "Unsupported LCD resolution."
#endif

/* color format */
#if DRV_MAINLCD_BIT_PER_PIXEL == 16
    #define BL_COLOR_FORMAT    LCD_LAYER_SOURCE_COLOR_RGB565
#elif DRV_MAINLCD_BIT_PER_PIXEL == 24
    #define BL_COLOR_FORMAT    LCD_LAYER_SOURCE_COLOR_RGB888
#elif DRV_MAINLCD_BIT_PER_PIXEL == 32
    #define BL_COLOR_FORMAT    LCD_LAYER_SOURCE_COLOR_ARGB8888
#else
    #error "Unsupported color format."
#endif

#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
    #if defined(DRV_LCD_ROI_BACKGROUND_COLOR_RGB888)
        #define COLOR_TRANSFORM
    #elif (defined(DRV_LCD_ROI_BACKGROUND_COLOR_RGB565)) 
        #define COLOR_TRANSFORM LCD_RGB888_TO_RGB565
    #else
        #error "Unsupported LCD color format."
    #endif	
#endif /* defined(DRV_LCD_ROI_BACKGROUND_COLOR) */


/* size of the required memory of the progressive bar */
#define BL_PBAR_BUFF_SIZE  ((BG_WIDTH * BG_HEIGHT * DRV_MAINLCD_BIT_PER_PIXEL + 7) >> 3)
#define BL_BACKGROUND_BUFF_SIZE ((UI_DEVICE_WIDTH * UI_DEVICE_HEIGHT * DRV_MAINLCD_BIT_PER_PIXEL + 7) >> 3)

/* size of the background image resource header */
#define IMG_RES_HEADER_SIZE     21

#if defined(__BG_IMAGE__) && defined(__CARD_DOWNLOAD__)
/* include raw data of background image */
#include "CustBLImgData.h"
#endif /* __BG_IMAGE__ */

/* global variables */
#ifndef __MTK_TARGET__
#define __align(X)
#endif

#ifdef __MTK_TARGET__
#pragma arm section zidata = "NONCACHEDZI"
#ifdef __UBL__
#pragma arm section zidata = "EXT_UN_INIT_ZI"
#endif 
#endif 

#if defined(__MTK_TARGET__)
__attribute__((aligned(4)))
#endif
 static kal_uint8 g_bl_pbar_buff[BL_BACKGROUND_BUFF_SIZE];  /* for background */

#ifdef __MTK_TARGET__
#pragma arm section zidata 
#endif

static ddv2_lcd_layer_para_struct g_bl_layer_data;
static ddv2_lcd_roi_para_struct g_bl_lcd_para = {0};
static kal_bool g_have_initialized = KAL_TRUE;


static void BL_FillBuffer(kal_uint8* buffer_ptr, kal_uint16 pitch, kal_uint16 x, kal_uint16 y, kal_uint16 w, kal_uint16 h, kal_uint32 color);
   
/*****************************************************************************
 * FUNCTION
 *  BL_InitLCDScreenConfiguration 
 * DESCRIPTION
 *  initialize LCD configuration
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void BL_InitLCDScreenConfiguration(kal_uint16 bg_width, kal_uint16 bg_height, kal_int32 bg_color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    /* init LCD */
    //lcd_fue_init(DRV_MAINLCD_INIT_COLOR);
    lcd_init(MAIN_LCD, DRV_MAINLCD_INIT_COLOR);

    /* configure layer */
    g_bl_layer_data.source_key_enable = KAL_FALSE;
    g_bl_layer_data.opacity_enable = KAL_FALSE;
    g_bl_layer_data.source_color_format = BL_COLOR_FORMAT;
    g_bl_layer_data.opacity_value = 0;
    g_bl_layer_data.rotate_value = LCD_LAYER_ROTATE_NORMAL;
    g_bl_layer_data.x_offset = ((UI_DEVICE_WIDTH - bg_width) >> 1);
    g_bl_layer_data.y_offset = ((UI_DEVICE_HEIGHT - bg_height) >> 1);
    g_bl_layer_data.row_number = bg_height;
    g_bl_layer_data.column_number = bg_width;
    g_bl_layer_data.source_key = 0xFFFF;
    g_bl_layer_data.frame_buffer_address = (kal_uint32)g_bl_pbar_buff;

#ifndef __BG_IMAGE__
    BL_FillBuffer((kal_uint8 *)g_bl_pbar_buff, (kal_uint16)bg_width, 0, 0, bg_width, bg_height, (kal_uint32)DRV_RGB_TO_HW(255, 255, 255));
    BL_FillBuffer((kal_uint8 *)g_bl_pbar_buff, (kal_uint16)bg_width, BAR_X, BAR_Y, BAR_WIDTH, BAR_HEIGHT, (kal_uint32)DRV_RGB_TO_HW(0, 0, 0));
#endif /* !__BG_IMAGE__ */

    //lcd_fue_config_layer_window(1, &g_bl_layer_data);
    lcd_config_layer(1, &g_bl_layer_data);

    /* configure LCD */
    g_bl_lcd_para.tgt_start_x = 0;
    g_bl_lcd_para.tgt_start_y = 0;
    g_bl_lcd_para.tgt_end_x = UI_DEVICE_WIDTH - 1;
    g_bl_lcd_para.tgt_end_y = UI_DEVICE_HEIGHT - 1;
    g_bl_lcd_para.roi_offset_x = 0;
    g_bl_lcd_para.roi_offset_y = 0;
    g_bl_lcd_para.update_layer = LCD_LAYER1_ENABLE;
    g_bl_lcd_para.block_mode_flag = KAL_TRUE;
#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
    g_bl_lcd_para.roi_background_color = COLOR_TRANSFORM(bg_color);
#endif 
}


/*****************************************************************************
 * FUNCTION
 *  BL_UpdateLCDScreen 
 * DESCRIPTION
 *  update LCD
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
static void BL_UpdateLCDScreen(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    //lcd_fue_fb_update(&g_bl_lcd_para);
    lcd_config_roi(&g_bl_lcd_para);
    lcd_start(g_bl_lcd_para.update, 
              g_bl_lcd_para.block_mode_flag,
              g_bl_lcd_para.tgt_start_x,
              g_bl_lcd_para.tgt_start_y,
              g_bl_lcd_para.tgt_end_x,
              g_bl_lcd_para.tgt_end_y);

}

#ifdef __CARD_DOWNLOAD__
/*****************************************************************************
 * FUNCTION
 *  BL_ShowUpdateFirmwareInitBackground
 * DESCRIPTION
 *  Initialize the progressive bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BL_ShowUpdateFirmwareInitBackground(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_have_initialized = KAL_TRUE;
    
    /* init LCD and layer configuration */
    BL_InitLCDScreenConfiguration(BG_WIDTH, BG_HEIGHT, 0xFFFFFF);

#ifdef __BG_IMAGE__
    {   /* draw background */
        gdi_image_ab2_img_buf_struct img_buf;
        
        img_buf.ptr = g_bl_pbar_buff;
        img_buf.pixel_bytes = DRV_MAINLCD_BIT_PER_PIXEL >> 3;
        img_buf.pitch_bytes = BG_WIDTH * img_buf.pixel_bytes;
        gdi_image_ab2_draw_to_buf(&img_buf, 0, 0, BL_PBAR_IMG_DATA);
    }
#endif /* __BG_IMAGE__ */

    /* blt to LCD (first time) */
    BL_UpdateLCDScreen();
}


/*****************************************************************************
 * FUNCTION
 *  BL_FillBuffer
 * DESCRIPTION
 *  fill buffer with specific color
 * PARAMETERS
 *  buffer_ptr  [IN]   buffer pointer
 *  pitch       [IN]   pixel in line 
 *  x           [IN]   fill region x 
 *  y           [IN]   fill region y
 *  w           [IN]   fill region width
 *  h           [IN]   fill region height 
 *  color       [IN]   color
 * RETURNS
 *  void
 *****************************************************************************/
static void BL_FillBuffer(kal_uint8* buffer_ptr, kal_uint16 pitch, kal_uint16 x, kal_uint16 y, kal_uint16 w, kal_uint16 h, kal_uint32 color)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/    
    /* in order to re-use the predefined MACROs
     * which are customized for GDI provided by LCD driver,
     * we must creat a fake GDI interface to cheat LCD driver */
    typedef struct
    {
        kal_uint8* act_buf_ptr;
        kal_uint16 act_pitch; /* pixel in width */
    } MY_GDI_LAYER_STRUCT;

    #ifdef GDI_LAYER
    #undef GDI_LAYER
    #endif
    
    /* a fake GDI layer */
    MY_GDI_LAYER_STRUCT GDI_LAYER;
    
    kal_uint16 i = 0, j = 0;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/    
    /* initialize the fake GDI layer */
    GDI_LAYER.act_buf_ptr = buffer_ptr;
    GDI_LAYER.act_pitch = pitch;
    
    for (j = y; j < y + h; j++)
    {
        for (i = x; i < x + w; i++)
        {
            /* use the predefined MACRO to fill the memory */
            DRV_MAINLCD_SET_BUFFER_PIXEL(i, j, color);
        }
    }
}


/*****************************************************************************
 * FUNCTION
 *  BL_ShowUpdateFirmwareProgress
 * DESCRIPTION
 *  Update the progressive bar
 * PARAMETERS
 *  percentage  [IN]    percentage of the progressive bar, must be 0~100
 * RETURNS
 *  void
 *****************************************************************************/
void BL_ShowUpdateFirmwareProgress(kal_uint16 percentage)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint16 width = 0;
    kal_uint16 percent = 0;
    
    /* color of the progressive bar,
     * using the predefined MACRO to covert RGB value to HW color format */
    kal_uint32 color = (kal_uint32)DRV_RGB_TO_HW(255, 0, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* draw percentage */
    percent = ((percentage) > ((kal_uint16)100) ? ((kal_uint16)100) : (percentage));
    width = (kal_uint16)(BAR_WIDTH*((kal_int32)percent)/100);
    BL_FillBuffer((kal_uint8 *)g_bl_pbar_buff, (kal_uint16)BG_WIDTH, BAR_X, BAR_Y, width, BAR_HEIGHT, color);
    
    /* blt to LCD */
    BL_UpdateLCDScreen();
}


/*****************************************************************************
 * FUNCTION
 *  BL_ShowUpdateFirmwareOK
 * DESCRIPTION
 *  Update the progressive bar
 * PARAMETERS
 *  None
 * RETURNS
 *  void
 *****************************************************************************/
void BL_ShowUpdateFirmwareOK(void)
{
    /* color of the progressive bar,
     * using the predefined MACRO to covert RGB value to HW color format */
    kal_uint32 color = (kal_uint32)DRV_RGB_TO_HW(0, 255, 0);

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    BL_FillBuffer((kal_uint8 *)g_bl_pbar_buff, (kal_uint16)BG_WIDTH, BAR_X, BAR_Y, BAR_WIDTH, BAR_HEIGHT, color);
    
    /* blt to LCD */
    BL_UpdateLCDScreen();
}

/*****************************************************************************
 * FUNCTION
 *  BL_ShowUpdateFirmwareFail
 * DESCRIPTION
 *  Show Update the progressive bar fail image
 *  IMPORTANT: The image of fail notification "MUST" have same size with progress bar background.
 * PARAMETERS
 *  r    [IN]   r value
 *  g    [IN]   g value
 *  b    [IN]   b value
 * RETURNS
 *  void
 *****************************************************************************/
void BL_ShowUpdateFirmwareFail(kal_int32 r, kal_int32 g, kal_int32 b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
    kal_uint32 rgb888_data = 0;
#else
    kal_uint32 color;
#endif /* DRV_LCD_ROI_BACKGROUND_COLOR */
    
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    ASSERT(g_have_initialized == KAL_TRUE);

    /* draw background color */
    if ((r >= 0) && (r <= 255) &&
        (g >= 0) && (g <= 255) &&
        (b >= 0) && (b <= 255))
    {
#if defined(DRV_LCD_ROI_BACKGROUND_COLOR)
        /* rgb888_data is R:16~24bit, G:8~15bit, B: 0~7 bit */
        rgb888_data = (((r << 16) | (g << 8) | b) << 8 ) >> 8 ;
        g_bl_lcd_para.roi_background_color = COLOR_TRANSFORM(rgb888_data);
#else
     
        /* set full screen to a specific color */
        
        /* configure layer */
        g_bl_layer_data.x_offset = 0;
        g_bl_layer_data.y_offset = 0;
        g_bl_layer_data.row_number = UI_DEVICE_HEIGHT;
        g_bl_layer_data.column_number = UI_DEVICE_WIDTH;
        //lcd_fue_config_layer_window(1, &g_bl_layer_data);
        lcd_config_layer(1, &g_bl_layer_data);
        
        /* fill g_bl_pbar_buff with r, g, b */
        color = (kal_uint32)DRV_RGB_TO_HW(r, g, b);
        memset(g_bl_pbar_buff, 0, BL_BACKGROUND_BUFF_SIZE);
        BL_FillBuffer((kal_uint8 *)g_bl_pbar_buff, (kal_uint16)UI_DEVICE_WIDTH, 0, 0, UI_DEVICE_WIDTH, UI_DEVICE_HEIGHT, color);
        
        /* configure LCD */
        g_bl_lcd_para.lcm_start_x = 0;
        g_bl_lcd_para.lcm_start_y = 0;
        g_bl_lcd_para.lcm_end_x = UI_DEVICE_WIDTH - 1;
        g_bl_lcd_para.lcm_end_y = UI_DEVICE_HEIGHT - 1;
        
        BL_UpdateLCDScreen();

        /* configure layer */   
        g_bl_layer_data.x_offset = 0;
        g_bl_layer_data.y_offset = 0;
        g_bl_layer_data.row_number = BG_HEIGHT;
        g_bl_layer_data.column_number = BG_WIDTH; 
        //lcd_fue_config_layer_window(1, &g_bl_layer_data);  
        lcd_config_layer(1, &g_bl_layer_data);
        
        /* configure LCD */
        g_bl_lcd_para.lcm_start_x = ((UI_DEVICE_WIDTH - BG_WIDTH) >> 1);
        g_bl_lcd_para.lcm_start_y = ((UI_DEVICE_WIDTH - BG_HEIGHT) >> 1);
        g_bl_lcd_para.lcm_end_x = g_bl_lcd_para.lcm_start_x + BG_WIDTH - 1;
        g_bl_lcd_para.lcm_end_y = g_bl_lcd_para.lcm_start_y + BG_HEIGHT - 1;
             
#endif /* defined(DRV_LCD_ROI_BACKGROUND_COLOR) */
    }

#ifdef __BG_IMAGE__
    /* clear */
    memset(g_bl_pbar_buff, 0, BL_PBAR_BUFF_SIZE);

    {   /* draw image */
        gdi_image_ab2_img_buf_struct img_buf;
        
        img_buf.ptr = g_bl_pbar_buff;
        img_buf.pixel_bytes = DRV_MAINLCD_BIT_PER_PIXEL >> 3;
        img_buf.pitch_bytes = BG_WIDTH * img_buf.pixel_bytes;
        gdi_image_ab2_draw_to_buf(&img_buf, 0, 0, BL_FAIL_IMG_DATA);
    }
#endif /* __BG_IMAGE__ */

    /* blt to LCD */
    BL_UpdateLCDScreen();
}

#endif /* __CARD_DOWNLOAD__ */
/*****************************************************************************
 * FUNCTION
 *  BL_ShowUpdateFirmwareInitBackgroundByImage
 * DESCRIPTION
 *  Initialize the progressive bar
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void BL_ShowUpdateFirmwareInitBackgroundByImage(U8 *imageSrc)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    gdi_image_ab2_info_struct info;
    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    
    g_have_initialized = KAL_TRUE;

    gdi_image_ab2_read_header(&info, imageSrc);
        
    /* init LCD and layer configuration */
    BL_InitLCDScreenConfiguration(info.width, info.height, 0);

    {   /* draw background */
        gdi_image_ab2_img_buf_struct img_buf;
        
        img_buf.ptr = g_bl_pbar_buff;
        img_buf.pixel_bytes = DRV_MAINLCD_BIT_PER_PIXEL >> 3;
        img_buf.pitch_bytes = info.width * img_buf.pixel_bytes;
        gdi_image_ab2_draw_to_buf(&img_buf, 0, 0, imageSrc);
    }

    /* blt to LCD (first time) */
    BL_UpdateLCDScreen();
}

#endif /* __LCD_DRIVER_IN_BL__ */
 
