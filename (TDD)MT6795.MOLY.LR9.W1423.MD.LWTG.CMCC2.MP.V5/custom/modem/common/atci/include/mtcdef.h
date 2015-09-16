/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * MTCDEF.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implementing custom commands for some customers
 *   which should not be released to other customers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __MTK_TARGET__  /* Only support ATS test on target , not support in simulator */
#ifndef MTCDEF_H
#define MTCDEF_H

#include "lcd_sw_inc.h"
#include "lcd_sw.h"

/*===============================================================*/
#define MTC_CMD_CODE 0xF0


/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_raw.h																				*
  *																																						*
  ******************************************************************************/
#define RGB565_REDMASK		(0xf800)
#define RGB565_REDSHIFT		(11)
#define RGB565_GREENMASK	(0x07e0)
#define RGB565_GREENSHIFT	(5)
#define RGB565_BLUEMASK	(0x001f)
#define RGB565_BLUESHIFT	(0)

#define RGB_PLANE_RED		(1)
#define RGB_PLANE_GREEN	(2)
#define RGB_PLANE_BLUE		(3)


/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_simple_dpcm.h																	*
  *																																						*
  ******************************************************************************/
#define DPCM_MINIMAL_QUANTIZER	(1)
#define DPCM_MAXIMAL_QUANTIZER	(7)

#define DPCM_INITIAL_PREDICTION	(128)


typedef enum 
{
	MTC_SCREEN_INFO_REQ_CMD = 0x00, 	/* Screen Info Request */
	MTC_CAPTURE_REQ_CMD  = 0x01,		/* Screen Capture Request */
	MTC_KEY_LOG_MASK_CMD = 0x07,
	MTC_KEY_LOG_DATA_IND = 0x08,
	MTC_PHONE_RESTART_REQ_CMD = 0x10,	/* Phone Restart Request */
	MTC_PHONE_FACTORY_RST_CMD = 0x11,	/* Phone Factory Reset Request*/
	MTC_PHONE_REPORT_REQ_CMD = 0x20,	/* Phone Report request */
	MTC_PHONE_STATE_REQ_CMD = 0x21,		/* Phone status request*/
	MTC_DATA_TRANSFER_SETUP_CMD = 0x22,	/* Request to setup data transfer parameters*/	
	MTC_KEY_REPORT_EN_REQ_CMD = 0x30, 	/* Enable/Disable key press notification*/
	MTC_KEY_EVENT_REQ_CMD  = 0x33,		/* Key Event notification or key press emulation */
	MTC_FAST_KEY_EVENT_REQ_CMD = 0x35,  /* Fast key event request cmd */
	MTC_MEMORY_DUMP_REQ_CMD = 0x40,		/* Memory Dump Request*/
	MTC_BATTERY_LEVEL_REQ_CMD = 0x41,	/* Battery Level Request*/
	MTC_BACKLIGHT_REQ_CMD = 0x42,		/* Backlight State Request*/
	MTC_FLEX_DATA_REQ_CMD = 0x50,
	MTC_ERROR_CMD = 0x7F,
	MTC_CURRENT_CELL_REQ_CMD = 0x80		/*Current cell, codec and data transfer quality information*/
}mtc_sub_cmd_type;

typedef enum
{
	MTC_MAIN_LCD = 0,
	MTC_SUB_LCD,
	MTC_LCD_PADDING = 0x7F
}mtc_scrn_id_type;


typedef struct                                     
{
    kal_uint8      sw_ver[45];
    kal_uint8      hw_ver[16];
    kal_uint8      sw_sub_ver;
} mtcVersion_type;

/*================================================================*/
typedef __packed struct 
{
	kal_uint8 cmd_code;
	kal_uint8 sub_cmd;
}mtc_req_hdr_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	mtc_scrn_id_type screen_id;
}mtc_info_req_type;

/*=================================================================*/
typedef __packed struct
{
	mtc_req_hdr_type hdr;
	mtc_scrn_id_type screen_id;
	kal_uint16 left;	/* Upper left X-Coord */
	kal_uint16 top;	/* Upper left Y-Coord */
	kal_uint16 width;  /* Width of the capture screen */
	kal_uint16 height;  /* Height of the capture screen */
}mtc_capture_req_type;

/*=================================================================*/

typedef __packed struct
{
	kal_uint16 left;	/* Upper left X-Coord */
	kal_uint16 top;	/* Upper left Y-Coord */
	kal_uint16 width;  /* Width of the area */
	kal_uint16 height;  /* Height of the area */
} mtc_ats_capture_rect_type;


typedef __packed struct
{
	kal_uint8 mask_type;
	mtc_ats_capture_rect_type rect; /* masked area */
}mtc_ats_capture_mask_req_type;

#define MTC_ATS_NMASK_MAX (5)

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	mtc_scrn_id_type screen_id;
	mtc_ats_capture_rect_type base_area;
	kal_uint8 refresh;
	kal_uint8 data_type;
	kal_uint8 pack_type;
	kal_uint8 quantizer;
	kal_uint8 threshold;
	mtc_ats_capture_mask_req_type masks[MTC_ATS_NMASK_MAX];
}mtc_ats_capture_req_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 request_area;
	kal_uint8 value;
}mtc_ats_key_report_en_req_type;

#if 1 /* LGE_L1_NUGUYU_20091119 */
typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint32 log_mask;
}mtc_ats_key_log_mask_req_type;
#endif

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint32 address;
	kal_uint32 reserved;
	kal_uint8 size;
}mtc_ats_memory_req_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
}mtc_ats_battery_req_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 request_area;
}mtc_ats_backlight_req_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 request_cell;
}mtc_ats_cell_req_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint16 packet_size;
	kal_uint16 transfer_delay;
}mtc_ats_transfer_setup_req_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 KeyHoldType; /* Press or Depress */
	kal_uint8 KeyCode;		/* Virtual key Code */
}mtc_key_event_req_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 KeyCode;		/* Virtual key Code */
	kal_uint16 Delay;		/* delay measured in 1\10 of a second  */
}mtc_fast_key_event_req_type;

typedef __packed union
{
	mtc_info_req_type info;
	mtc_capture_req_type capture;
	mtc_ats_capture_req_type ats_capture;
	mtc_ats_key_report_en_req_type ats_key_report_en;
	mtc_ats_key_log_mask_req_type ats_key_log_mask;
	mtc_ats_memory_req_type ats_dump;
	mtc_ats_battery_req_type ats_battery;
	mtc_ats_backlight_req_type ats_backlight;
	mtc_ats_cell_req_type ats_cell_info;
	mtc_ats_transfer_setup_req_type ats_setup;
	mtc_key_event_req_type keyevent;
	mtc_fast_key_event_req_type fastkeyevent;
}mtc_req_type;

typedef  __packed union
{
	mtc_req_hdr_type hdr;
	mtc_req_type mtc_req;
}diag_mtc_req_type;

/*==============================================================*/

#define MTC_262K_CMASK_RED				0x0000FC00
#define MTC_262K_CMASK_GREEN				0x000003F0
#define MTC_262K_CMASK_BLUE				0xC000000F

#define MTC_65K_CMASK_RED					0xF800
#define MTC_65K_CMASK_GREEN				0x07E0
#define MTC_65K_CMASK_BLUE				0x001F

typedef enum
{
	MTC_BIT_UNDEF			=	0,
	MTC_BIT_MONO			=	1,
	MTC_BIT_4				=	2,
	MTC_BIT_16				=	4,
	MTC_BIT_256			=	8,
	MTC_BIT_65K			=	16,
	MTC_BIT_262K			=	18,
	MTC_BIT_RGB24			=	24,
	MTC_BIT_RGB_32		=	32,
	MTC_BIT_PADDING		=	0x7F
}mtc_bits_pixel_type;

typedef unsigned long		mtc_pixel_18_type;	/* 4 kal_uint8 */
typedef unsigned short		mtc_pixel_16_type;  /* 2 kal_uint8 */

/*	
	We have to make sure that MTC_SCRN_BUF_SIZE_MAX is set correctly in various project .
	The only thing we can confirm is that bpp of MAIN_LCD_16BIT_MODE is displayed 2 bytes length,
	the other cases MTC_SCRN_BUF_SIZE_MAX is set to maximum size
	It may be revised in later projects	
*/
#if defined (MAIN_LCD_16BIT_MODE)
	#define MTC_SCRN_BUF_SIZE_MAX	(LCD_WIDTH*LCD_HEIGHT*(sizeof(mtc_pixel_16_type)))
#else
	#define MTC_SCRN_BUF_SIZE_MAX	(LCD_WIDTH*LCD_HEIGHT*(sizeof(mtc_pixel_18_type)))
#endif


/*=========================================================*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef mtc_req_hdr_type mtc_rsp_hdr_type;

typedef  __packed struct
{
	mtc_rsp_hdr_type	hdr;
	mtc_scrn_id_type	scrn_id;
	kal_uint16	scrn_width;					/* Screen Width in Pixels */
	kal_uint16	scrn_height;					/* Screen Height in Pixcels */
	mtc_bits_pixel_type	bits_pixel;		/* Color bits for each Pixel */ 
}mtc_screen_info_rsp_type;

typedef  __packed struct
{
	kal_uint32	blue;
	kal_uint32	green;
	kal_uint32	red;
}mtc_mask_type;

typedef  __packed struct
{
	mtc_rsp_hdr_type	hdr;
	mtc_scrn_id_type	scrn_id;
	kal_uint16	bmp_width;	                  /* Width of the BMP */
	kal_uint16	bmp_height;	                  /* Height of the BMP */
	mtc_bits_pixel_type	bits_pixel; /* Color bits for each pixel */
	mtc_mask_type	mask;
////	kal_uint8 bmp_data[MTC_SCRN_BUF_SIZE_MAX];
//mtk01616_091217: we output data directly ,without keeping all bmp_data in a buffer first.
}mtc_capture_rsp_type;

typedef  __packed struct
{
	mtc_rsp_hdr_type hdr;
	mtc_scrn_id_type scrn_id;
	kal_uint16 bmp_width;	                  		/* Width of the BMP */
	kal_uint16 bmp_height;	                  	/* Height of the BMP */
	mtc_bits_pixel_type bits_pixel;  	/* must be zero */
	kal_uint8 data_type;
	kal_uint8 pack_type;
	kal_uint8 quantizer;
	kal_uint8 threshold;
	kal_uint32 bmp_size;
////	kal_uint8 bmp_data[ MTC_SCRN_BUF_SIZE_MAX ];
//mtk01616_091217: we output data directly ,without keeping all bmp_data in a buffer first.
}mtc_ats_capture_rsp_type;

typedef __packed struct
{
	mtc_rsp_hdr_type hdr;
	kal_uint8 keyState;
	kal_uint8 keyCode;
}mtc_ats_key_report_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 model_name[10]; 
	kal_uint32 release_date;
	kal_uint8 software_ver[40];
	kal_uint8 IMEI[15];
	kal_uint8 phone_num[15];
	kal_uint16 enabled_functions;
}mtc_ats_phone_report_rsp_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint16 phone_state;
}mtc_ats_phone_state_rsp_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 request_area;
	kal_uint8 value;
}mtc_ats_key_report_en_rsp_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint32 log_mask;
}mtc_ats_key_log_mask_rsp_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint32 *reserved;
	kal_uint32 *address;
	kal_uint8 size;
	kal_uint8 data[64];
}mtc_ats_memory_rsp_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 isCharging;
	kal_uint8 capacity;
}mtc_ats_battery_rsp_type;

typedef  __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint8 value;
}mtc_ats_backlight_rsp_type;

typedef __packed struct
{
	mtc_req_hdr_type hdr;
	kal_uint16 packet_size;
	kal_uint16 transfer_delay;
}mtc_ats_transfer_setup_rsp_type;

 
/*==========================================================*/

typedef __packed struct
{
	mtc_rsp_hdr_type hdr;
	kal_uint8 KeyHoldType;     /* Press or Release */
	kal_uint8 KeyCode;		/* Virtual key Code */
}mtc_key_event_rsp_type;

typedef mtc_key_event_rsp_type mtc_key_event_ind_type;

typedef __packed struct
{
	mtc_rsp_hdr_type hdr;
	kal_uint8 log_id;     /* Press or Release */
	kal_uint16 log_len;		/* Virtual key Code */
	kal_uint64 time;
	kal_uint8 press;
	kal_uint8 key_code;
	kal_uint64 active_UIID;
}mtc_ats_key_log_event_rsp_type;

typedef mtc_ats_key_log_event_rsp_type mtc_ats_key_log_event_ind_type;

typedef __packed struct
{
	mtc_rsp_hdr_type hdr;
	kal_uint8 KeyCode;		/* Virtual key Code */
	short Delay;		/* delay measured in 1\10 of a second  */
}mtc_fast_key_event_resp;

/*==========================================================*/

typedef __packed union
{
	mtc_screen_info_rsp_type info;
	mtc_capture_rsp_type capture;
	mtc_ats_capture_rsp_type ats_capture;  
	mtc_ats_memory_rsp_type ats_dump;
	mtc_ats_battery_rsp_type ats_battery;
	mtc_ats_backlight_rsp_type ats_backlight;
	mtc_ats_transfer_setup_rsp_type ats_setup;
	mtc_key_event_rsp_type keyevent;
	mtc_ats_key_log_event_rsp_type ats_keylogevent;
	mtc_fast_key_event_resp fastkeyevent;
}mtc_rsp_type;

typedef __packed union 
{
	mtc_rsp_hdr_type hdr;
	mtc_rsp_type mtc_rsp;
}diag_mtc_rsp_type;

/*============================================================*/

typedef struct 
{
	mtc_scrn_id_type id;		       /* lcd id: MAIN, SUB */
	int width_max;				/* max width in current rotation mode */
	int height_max;				/* max height in current rotation mode */
	int degrees;				       /* LCD degrees of rotation: 0, 90, 180 */
	mtc_bits_pixel_type bits_pixel;  /* Color Bit: 16, 18 */
	mtc_mask_type mask;			/* Color mask: R, G, B */
}mtc_lcd_info_type;

typedef struct 
{
	int start_x;                   /* Start X-Coord for capture area */
	int start_y;                   /* Start Y- Coord for capture area */
	int width;                     /* Width of the capture area */
	int height;                   /* Height of the capture area */
}mtc_capture_type;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/*=================================================*/

#endif
#endif /* __MTK_TARGET__ */

