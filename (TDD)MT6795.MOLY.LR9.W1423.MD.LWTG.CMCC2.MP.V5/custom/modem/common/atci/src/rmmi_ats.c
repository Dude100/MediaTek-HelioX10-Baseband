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
 * RMMI_ATS.C
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#include <stdio.h>
#include <string.h>
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "kal_trace.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "drv_msgid.h"
#if defined(__TC01__)
//#include "stack_ltlcom.h" //MSBB change #include "app_ltlcom.h" /* Task message communiction */
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"   /* Basic type for dll, evshed, stacktimer */
//MSBB remove #include "app_buff_alloc.h"
#include "stack_timer.h"
#include "event_shed.h"
#include "nvram_editor_data_item.h"
//#include "custom_nvram_editor_data_item.h"

#include "l4c_common_enum.h"
#include "mcd_l4_common.h"
#include "l4c_aux_struct.h"

//#include "l4c_rspfmttr.h"
#include "l4c_sendmsg.h"

#ifdef __MOD_SMU__
#include "ps2sim_struct.h"
#include "sim_common_enums.h"
#include "smu_common_enums.h"
#endif /* __MOD_SMU__ */ 



#include "csmcc_atfunc.h"
#include "csmcc_common_enums.h"
#include "csmss_atfunc.h"
#include "csmss_common_enums.h"

#include "rmmi_common_enum.h"
#include "rmmi_context.h"

#include "l4c_context.h"
#include "layer4_context.h"

#include "l4c_nw_cmd.h"
#include "l4c_eq_cmd.h"
#include "l4c2smsal_struct.h"
#include "l4crac_enums.h"
#include "l3_inc_enums.h"

#include "rmmi_rspfmttr.h"
#include "rmmi_msghdlr.h"
#include "rmmi_custom_parser.h"
#include "rmmi_utility.h"

#include "device.h"
#include "uem_context.h" 
#include "custom_equipment.h"
#include "kbd_table.h"
#include "nvram_struct.h"
#include "nvram_interface.h"
#include "uem_proc_cmd.h"
#include "uem_utility.h"
#include "bmt.h"
#include "l4a.h"
#include "custom_nvram_extra.h"
#include "l4c_utility.h"
#include "rmmi_custom_inc.h"
#include "aud_defs.h"
#include "lcd_if.h"
#include "mtcdef.h"
#include "csmcc_atfunc.h"
#if defined(EXTERNAL_MMI)
/* include header file from LG MMI */
#include "Pal_QualcommRemove.h"
#include "PalDef_OemDevMgr.h"
#include "..\..\..\..\..\Api\BasicApiLib\Include\ProcMngr.h"
#else
/* include header file from MTK MMI */
#include "gdi_include.h"
#include "GpioSrvGprot.h" //MAUI_02961708
#include "GlobalConstants.h"
#include "jam_interface.h"
#ifdef __BT_SUPPORT__
#include "btcmSrvGprot.h" 
#endif
#endif
#include "lcd_sw_inc.h"
#include "lcd_sw.h"
//#include "mmi_msg_struct.h"
//#include "stack_ltlcom.h"
#include "Tcm_common.h"

extern const kal_uint8 facSwVerModel[]; 
extern const kal_uint8 facSwVerType[];
extern const kal_uint8 facSwVerSimlock[];
extern const kal_uint8 facSwVerVersion[];
extern const kal_uint8 facSwVerMcc[];
extern const kal_uint8 facSwVerMnc[];
extern const kal_uint8 facSwVerDate[];
extern const kal_uint8 facSwVerHidden[];

#include "che_api.h" //protex add

//Note: Please define proper compile option here!!
#define __MTC_ATS_SUPPORT__
#define __MTC_ATS_DEBUG_INFO__


#if defined(__MTC_ATS_SUPPORT__) && defined(__MTK_TARGET__)  /* Only support ATS test on target , not support in simulator */
#define XX 127
static const kal_uint8 Base64Code[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";

static const kal_uint8 index_64[] =
{
	XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
	XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,XX,
	XX,XX,XX,XX, XX,XX,XX,XX, XX,XX,XX,62, XX,XX,XX,63,
	52,53,54,55,  56,57,58,59,	60,61,XX,XX,  XX,XX,XX,XX,
	XX, 0, 1, 2,  3, 4, 5, 6,	7, 8, 9, 10,   11,12,13,14,
	15,16,17,18,  19,20,21,22,	23,24,25,XX,  XX,XX,XX,XX,
	XX,26,27,28,  29,30,31,32,	33,34,35,36,  37,38,39,40,
	41,42,43,44,  45,46,47,48,	49,50,51,XX,  XX,XX,XX,XX
};


/***************************************************************************
 * Macros
 ***************************************************************************/
#define CHAR64(c)  ( ((c) > 127) ? XX : index_64[(c)])
///#define isascii(c) !(c & ~0177) 
#define isascii(a)  (((a) & ~0x7F) == 0)
#define	isspace(c)	(c=='\n' || c=='\t' || c=='\v' || c==' ' || c=='\r' || c=='\f')
#if 1 /* branden.you@lge.com 20100305 */ //mtk01616_20100324: merge LGE's patch
#define MAX_MTC_DATA_LENGTH (512+10) //shall be smaller than MAX_DATA_QUEUE_LENGTH
#else
/* under construction !*/
#endif

#define LOGMASK_DISABLE_ALL 0x00000000
#define LOGMASK_ENABLE_ALL 0xffffffff
#define LOGMASK_ITEM_KEY 0x00000001
#define LOGMASK_ITEM_TOUCHPAD 0x00000002

#define ATS_IC_PIXELSIZE					(2)
#define ATS_IC_BMPBODYSIZE(width,height) \
	( ( ((width)*ATS_IC_PIXELSIZE+3) >> 2 ) << 2 )  * (height)

#define ATS_IC_DISPLAYID_MAIN			(0)
#define ATS_IC_DISPLAYID_SUB			(1)
#ifdef LGE_SUBLCD
#define ATS_IC_DISPLAYID_MAX			(1)
#else
#define ATS_IC_DISPLAYID_MAX			(0)
#endif

#define ATS_IC_REFRESHTYPE_WAIT		(0)
//#define ATS_IC_REFRESHTYPE_REQUEST	(1)
#define ATS_IC_REFRESHTYPE_IMMEDIATE	(1)
#define ATS_IC_REFRESHTYPE_MAX		(1)

#define ATS_IC_DATATYPE_PLAIN			(0)
#define ATS_IC_DATATYPE_BLACKWHITE	(1)
#define ATS_IC_DATATYPE_HASH			(2)
#define ATS_IC_DATATYPE_MAX			(2)

#define ATS_IC_PACKTYPE_NONE			(0)
#define ATS_IC_PACKTYPE_RLE			(1)
#define ATS_IC_PACKTYPE_DPCMRLE		(2)
#define ATS_IC_PACKTYPE_SVF32			(3)
#define ATS_IC_PACKTYPE_JPEG			(4)
#define ATS_IC_PACKTYPE_MD5			(5)
#define ATS_IC_PACKTYPE_MAX			(5)

#define ATS_IC_MASKTYPE_OPAQUE		(0)
#define ATS_IC_MASKTYPE_TRANSPARENT	(1)
#define ATS_IC_MASKTYPE_MAX			(1)

#define ATS_IC_NMASK_MAX				(5)

#define RLE_MAX_BIT_REPETITION 255
#define RLE_REPETITION_MODULE  (RLE_MAX_BIT_REPETITION+1)

#define RLE_MAX_OUTPUT_CHUNK  (6)

/* To avoid compile error integrating library files */
#define IN
#define OUT

#define MD5_DIGEST_LENGTH (16) //Protex move


typedef struct ATSImageCaptureRectTag {
	kal_uint16	left, right, up, down;		/* rectangle coordinates from upper-left corner */
} ATSImageCaptureRect;

typedef struct ATSImageCaptureMaskTag {
	kal_uint16				maskType;	
	ATSImageCaptureRect	maskArea;	/* masked rectangle */
} ATSImageCaptureMask;

typedef struct ATSImageCaptureContextTag {
	kal_uint8* 	screenshotBuffer;		/* allocated by mtc agent */
	kal_uint32	fileSize;					/* size of data in mtc agent response */
	mtc_lcd_info_type* lcd_info;           /* mtc agent lcd_info */
	mtc_ats_capture_rsp_type* rsp_ptr;	/* mtc agent response */
	
	kal_uint16	dataType;				/* returned image data type */
	kal_uint16	packType;				/* image compressing */
	kal_uint16	dataThreshold;			/* YUV -> B/W threshold and DPCM quantizer */
	ATSImageCaptureRect	baseArea;	/* cropped rectangle */
	kal_uint16	nmask;					/* number of received masks */
	ATSImageCaptureMask masks[ATS_IC_NMASK_MAX];

}ATSImageCaptureContext;

typedef	enum ATSImageDataFormatTag {
		ATS_IC_DataRaw,
		ATS_IC_DataBPlane,
		ATS_IC_DataCPlanes,
		ATS_IC_DataRLE
} ATSImageDataFormat;

ATSImageCaptureContext atsImageCaptureContext;
static mtc_lcd_info_type lcd_info;
/******************************************************************************
* State (bytes):	
* 0 ¡V Phone request (0x20)
* 1 ¡V Screen Request (MTC,0)
* 2 ¡V Screen Capture (MTC,1)
* 3 ¡V Screen Capture (ETA, 1)
* 4 ¡V Key press (MTC, 0x3)
* 5 ¡V Key press notification (0x33) 
* 6 ¡V Phone restart (0x10)
* 7 ¡V Phone factory reset (0x11)	8 ¡V Memory (0x40)
* 9 ¡V Battery (0x41)
* 10 ¡V Backlight (0x42)
* 11 ¡V Batch key press (0x34)
* 12 ¡V Netmonitor (0x80,0x81), enable/disable (0x30)
* 13 ¡V Phone state (0x21)
* 14 ¡V Key press (ETA, 0x33), enable/disable (0x30)
* 15 ¡V Touch event (0x04)
* The bit sequence is bit15, bit14 ,..... bit0
******************************************************************************/
static kal_uint16 mtc_ats_supported_commamds = 0x27ff; //0010,0111,1111,1011
static kal_bool mtc_ats_key_report_enabled = KAL_FALSE;
static kal_uint32 mtc_ats_key_log_mask = LOGMASK_DISABLE_ALL;
static mtcVersion_type mtcVersion;
static kal_uint8 mtcVersion_Display[40];
static kal_uint16 mtc_max_at_command_length = 254;
static kal_uint16 mtc_transfer_timeout = 100;
kal_uint8 mtcats_atbuffer[MAX_MTC_DATA_LENGTH];
//use to store the complete screen caputre data
#define ATS_SCREEN_CAPTURE_HEADER_SIZE		sizeof(mtc_ats_capture_rsp_type)
kal_uint8 mtcats_bmp_buffer[MTC_SCRN_BUF_SIZE_MAX + ATS_SCREEN_CAPTURE_HEADER_SIZE];
static kal_uint32 bmp_buffer_ptr = 0;
static kal_uint8 ats_src_id = RMMI_SRC; /* For USB_MULTIPLE_COMPORT,we need to keep the ATS command src_id */

extern kal_bool l4c_nw_get_imei_req(kal_uint8 src_id, kal_uint8 *imei, kal_uint8 *svn);
extern void lcd_get_screen_para_info(LCD_TYPE_ENUM screen_id,kal_uint32* scren_width,kal_uint32* screen_height,kal_uint32* color_depth);
extern kal_uint32 encode_BASE64(kal_uint8* des, kal_uint8* src, kal_uint32 length);
extern kal_uint32 decode_BASE64(kal_uint8* des, kal_uint8* src, kal_uint32 length);
extern void mtc_SWVersion(void);
extern kal_uint32 parseStrDateToInt(kal_uint8* strDate);
extern kal_uint8 mtc_convert_keypad_code(kal_uint8 keycode);
extern kal_bool mtc_check_keypad_code(kal_uint8 *key,kal_uint8 *keycode,kal_uint8 keypad_type);
extern kal_bool valid_memory_range_check(kal_uint32 req_start_addr,kal_uint32 req_size);
extern kal_bool ws_is_camera_videorecord_mode();
extern void ws_capturedimage_sw_rotate_ats(    kal_uint8* pDst,kal_uint8* pSrc, kal_uint32 const src_width, kal_uint32 const src_height);
extern kal_uint8 *ws_camera_osd_current_buf();
extern rmmi_custom_frst_cmd_enum rmmi_custom_frst_cmd; 


/***************************************************************************** 
 *           Below are Callback Functions for MTC ATS feature                * 
 *****************************************************************************/

/*****************************************************************************
 * FUNCTION
 *  ws_output_screen_capture_info
 * DESCRIPTION
 *  Callback function to output screen capture BMP raw data(with base64 encoding) to UART
 *
 * PARAMETERS
 *  screen_capture_buf      [IN]        
 *  length           		[IN]       
 *
 * RETURNS
 *  void
 *****************************************************************************/
void ws_output_screen_capture_info(kal_uint8* screen_capture_buf,kal_uint32 length)
{
    kal_mem_cpy((kal_uint8*)&(mtcats_bmp_buffer[bmp_buffer_ptr]),(kal_uint8*)screen_capture_buf,length);
    bmp_buffer_ptr += length;

    return;
}

kal_bool ws_is_camera_videorecord_mode()
{
#if defined(EXTERNAL_MMI)	
    void *hPXE;
    kal_bool retv;
    
    retv = KAL_FALSE;
    hPXE = NULL;

    hPXE = (void*)ProcMngr_SearchApp(L"PVoiceRecorder.PXO");
    if(hPXE != NULL)
    {
        retv = KAL_TRUE;
    }
    else
    {
        hPXE =(void*)ProcMngr_SearchApp(L"Camera.PXO");
        if(hPXE != NULL)
        {
            retv = KAL_TRUE;
        }
    }
    return retv;
#endif    
}

void ws_capturedimage_sw_rotate_ats(
    kal_uint8* pDst,
    kal_uint8* pSrc,
    kal_uint32 const src_width,
    kal_uint32 const src_height)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    kal_uint32 i, j;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    for (i = 0; i < LCD_WIDTH ; i++)
    {
        for (j = 0; j <LCD_HEIGHT; j++)
        {
            *(pDst+(j*LCD_WIDTH*2)+((LCD_WIDTH-i-1)*2)) = *(pSrc++);
            *(pDst+(j*LCD_WIDTH*2)+((LCD_WIDTH-i-1)*2+1)) = *(pSrc++);
            bmp_buffer_ptr+=2;
        }
    }

}
/*****************************************************************************
 * FUNCTION
 *  ws_key_event_notification
 * DESCRIPTION
 *  This is a callback function for device BAL to invoke when it process the
 *  keypad event. So that we can send the keypad notification to PC.
 *
 * PARAMETERS
 *  key_code       [IN]        key code
 *  key_type       [IN]        ws_kbd_onekey_release or ws_kbd_onekey_press
 *
 * RETURNS
 *  void
 *****************************************************************************/
void ws_key_event_notification(kal_uint8 key_code ,kal_uint8 key_type,kal_uint32 time_stamp)
{
    mmi_em_keypad_event_output_req_struct *param_ptr = NULL;
    module_type src;
    sap_type sap;

    /* branden.you@lge.com 20100316 MTR */ //mtk01616_20100324: merge LGE's patch
    if((mtc_ats_key_report_enabled == KAL_TRUE) ||
       ((mtc_ats_key_log_mask & LOGMASK_ITEM_KEY) == LOGMASK_ITEM_KEY)	)
    {
        param_ptr = (mmi_em_keypad_event_output_req_struct*) construct_local_para(
                                                    (kal_uint16) sizeof(mmi_em_keypad_event_output_req_struct),
                                                    TD_RESET);
        param_ptr->keypad_status = key_type;
        param_ptr->keypad_code= key_code;
        param_ptr->time_stamp= time_stamp;

        #if defined(EXTERNAL_MMI)	
        src = MOD_WISE;
        sap = WISE_L4C_SAP;
        #else
        src = MOD_MMI;
        sap = MMI_L4C_SAP;
        #endif

   
        msg_send5(src, MOD_L4C, sap, MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ, (local_para_struct *) param_ptr);
    }

    return;	
}

/*****************************************************************************
 * FUNCTION
 *  ws_output_key_event_notification
 * DESCRIPTION
 *  This is a callback function for L4C to invoke when processing
 *  MSG_ID_MMI_EM_KEYPAD_EVENT_OUTPUT_REQ. 
 *  This function will output key event notification to PC.
 *
 * PARAMETERS
 *  key_code       [IN]        key code
 *  key_type       [IN]        ws_kbd_onekey_release or ws_kbd_onekey_press
 *
 * RETURNS
 *  void
 *****************************************************************************/
void ws_output_key_event_notification(kal_uint8 key_code ,kal_uint8 key_type,kal_uint32 time_stamp)
{
    mtc_key_event_ind_type ats_key_ind;	
    mtc_ats_key_log_event_ind_type ats_log_data_ind;
    kal_uint8 encoded_ind_data[50]; // 50 shall be enough
    kal_uint16 i;
    kal_uint32 tick_count = 0;	
    kal_uint8 temp_src;

    /* For USB_MULTIPLE_COMPORT, current_src might be changed to other port. 
       we set ats_src_id here. So that the data can be sent to the port ATS is using*/
    temp_src = RMMI_PTR->current_src; //save current cmd port	   
    RMMI_PTR->current_src = ats_src_id; 

    if(mtc_ats_key_report_enabled == KAL_TRUE)
    {
        kal_mem_set((void*)&ats_key_ind,0,sizeof(mtc_key_event_ind_type));
        kal_mem_set(encoded_ind_data,0,sizeof(encoded_ind_data));	

        ats_key_ind.hdr.cmd_code = MTC_CMD_CODE; //0xf0
        ats_key_ind.hdr.sub_cmd = MTC_KEY_EVENT_REQ_CMD; //notification use the same cmd id with request
        ats_key_ind.KeyCode = mtc_convert_keypad_code(key_code);
        if(key_type == 0) // Press: 0 , Release:1 (Refer to WS_KBD_EVENT enum)
            ats_key_ind.KeyHoldType = 1; 
        else
            ats_key_ind.KeyHoldType = 0; 			
		
        encode_BASE64(encoded_ind_data,(kal_uint8*)&ats_key_ind, sizeof(mtc_key_event_ind_type));
        rmmi_write_to_uart(encoded_ind_data,strlen((char*)encoded_ind_data),KAL_TRUE);
    }
    /* branden.you@lge.com 20100316 MTR */ //mtk01616_20100324: merge LGE's patch
    else if((mtc_ats_key_log_mask & LOGMASK_ITEM_KEY) == LOGMASK_ITEM_KEY)
    {
        kal_mem_set((void*)&ats_log_data_ind,0,sizeof(mtc_ats_key_log_event_ind_type));
        kal_mem_set(encoded_ind_data,0,sizeof(encoded_ind_data));	

        ats_log_data_ind.hdr.cmd_code = MTC_CMD_CODE; //0xf0
        ats_log_data_ind.hdr.sub_cmd = MTC_KEY_LOG_DATA_IND; 
        ats_log_data_ind.log_id = LOGMASK_ITEM_KEY; 
       	ats_log_data_ind.log_len = 18; // Time(8) + Press(1) + key_code(1) + active_UIID(8)	
        
     ///   kal_get_time(&tick_count);	 // Number of ticks elapsed since the system was started	
     ////   ats_log_data_ind.time = tick_count * 4.6153846; // 1 tick is 4.615 ms
     /* MTK PATCH for MAUI_02389069: MMI might be delayed to process the keypad event from keypad driver. we shall get the time stmamp in driver layer */
        ats_log_data_ind.time = time_stamp * 4.6153846; // 1 tick is 4.615 ms
        ats_log_data_ind.active_UIID = 0;

        if(key_type == 0) // Press: 0 , Release:1 (Refer to WS_KBD_EVENT enum)
            ats_log_data_ind.press = 1; 
        else
            ats_log_data_ind.press = 0;  
            
        ats_log_data_ind.key_code =  mtc_convert_keypad_code(key_code); 

        encode_BASE64(encoded_ind_data,(kal_uint8*)&ats_log_data_ind, sizeof(mtc_ats_key_log_event_ind_type));
        rmmi_write_to_uart(encoded_ind_data,strlen((char*)encoded_ind_data),KAL_TRUE);
    }    	

    RMMI_PTR->current_src = temp_src; //restore current cmd port	   

#if defined(__MTC_ATS_DEBUG_INFO__)
    for(i=0;i<strlen((char*)encoded_ind_data);i++)
        kal_prompt_trace(l4c_current_mod_id,"encoded_ind_data[%d]=%x,%d",i,encoded_ind_data[i],encoded_ind_data[i]);								
#endif
}


/*****************************************************************************
 * FUNCTION
 *  ws_output_gpio_event_notification
 * DESCRIPTION
 *  This is a callback function for L4C to gpio device(CLAM) event
 *
 * PARAMETERS
 *  gpio_device       [IN]        Refer to ext_device_enum
 *  on_off      	        [IN]        KAL_TRUE or KAL_FALSE
 *
 * RETURNS
 *  void
 *****************************************************************************/
void ws_output_gpio_event_notification(kal_uint8 gpio_device, kal_bool on_off)
{
    mtc_key_event_ind_type ats_key_ind;	
    mtc_ats_key_log_event_ind_type ats_log_data_ind;
    kal_uint8 encoded_ind_data[50]; // 50 shall be enough
    kal_uint8 key_code;
    kal_uint16 i;
    kal_uint32 tick_count = 0;	

    if(gpio_device == EXT_DEV_CLAM_OPEN)
    {
        key_code = RMMI_CHAR_I;
    }
    else if(gpio_device == EXT_DEV_CLAM_CLOSE)
    {
        key_code = RMMI_CHAR_J;
    }
    else
    {
        return;
    }		

    if(mtc_ats_key_report_enabled == KAL_TRUE)
    {
        kal_mem_set((void*)&ats_key_ind,0,sizeof(mtc_key_event_ind_type));
        kal_mem_set(encoded_ind_data,0,sizeof(encoded_ind_data));	

        ats_key_ind.hdr.cmd_code = MTC_CMD_CODE; //0xf0
        ats_key_ind.hdr.sub_cmd = MTC_KEY_EVENT_REQ_CMD; //notification use the same cmd id with request
        ats_key_ind.KeyCode = key_code; 
        ats_key_ind.KeyHoldType = 0; // LGE: send press or release for FLIP OPEN/CLOSE event for one time.
		
        encode_BASE64(encoded_ind_data,(kal_uint8*)&ats_key_ind, sizeof(mtc_key_event_ind_type));
        rmmi_write_to_uart(encoded_ind_data,strlen((char*)encoded_ind_data),KAL_TRUE);
    }
    /* branden.you@lge.com 20100316 MTR */ //mtk01616_20100324: merge LGE's patch
    else if((mtc_ats_key_log_mask & LOGMASK_ITEM_KEY) == LOGMASK_ITEM_KEY)
    {
        kal_mem_set((void*)&ats_log_data_ind,0,sizeof(mtc_ats_key_log_event_ind_type));
        kal_mem_set(encoded_ind_data,0,sizeof(encoded_ind_data));	

        ats_log_data_ind.hdr.cmd_code = MTC_CMD_CODE; //0xf0
        ats_log_data_ind.hdr.sub_cmd = MTC_KEY_LOG_DATA_IND; 
        ats_log_data_ind.log_id = LOGMASK_ITEM_KEY; 
        ats_log_data_ind.log_len = 18; // Time(8) + Press(1) + key_code(1) + active_UIID(8)	
        kal_get_time(&tick_count);	 // Number of ticks elapsed since the system was started	
        ats_log_data_ind.time = tick_count * 4.6153846; // 1 tick is 4.615 ms
        ats_log_data_ind.active_UIID = 0;
        ats_log_data_ind.press = 0;              
        ats_log_data_ind.key_code = key_code; 

        encode_BASE64(encoded_ind_data,(kal_uint8*)&ats_log_data_ind, sizeof(mtc_ats_key_log_event_ind_type));
        rmmi_write_to_uart(encoded_ind_data,strlen((char*)encoded_ind_data),KAL_TRUE);
    }    	

#if defined(__MTC_ATS_DEBUG_INFO__)
    for(i=0;i<strlen((char*)encoded_ind_data);i++)
        kal_prompt_trace(l4c_current_mod_id,"encoded_ind_data[%d]=%x,%d",i,encoded_ind_data[i],encoded_ind_data[i]);								
#endif
}


/*****************************************************************************
 *          Below are Utility Functions for MTC ATS feature                  * 
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  encode_BASE64
 * DESCRIPTION
 *  encode to base64 format data
 *
 * PARAMETERS
 *  des      [IN]     base64 encoded data
 *  src      [IN]     source data 
 *  length   [IN]     length of source data  
 *
 * RETURNS
 *  length of base64 encoded data. return 0 if encode fail
 *****************************************************************************/
kal_uint32 encode_BASE64(kal_uint8* des, kal_uint8* src, kal_uint32 length)
{
	kal_uint32 c1,c2,src_len,pos=0;
	kal_uint8* dbufp;
	kal_uint8* sbufp;
    kal_uint16 i;
	
	if(src == NULL || length == 0)
		return 0;

	src_len =  length;
	dbufp = des;
	sbufp = src;

	while(pos < src_len)
	{
	
		c1 = *sbufp++;
		pos++;

		*dbufp++ = Base64Code[(c1 >> 2)];
		c1 = (c1 & 0x03) << 4;
		
		if(pos == src_len)
		{
			*dbufp++ = Base64Code[c1];
			*dbufp++ = '=';
			*dbufp++ = '=';
			break;
		}
		
		c2 = *sbufp++;		
		pos++;
		
		c1 |= (c2 >> 4) & 0x0f;
		
		*dbufp++ = Base64Code[c1];
		c1 = (c2 & 0x0f) << 2;
	
		if(pos == src_len)
		{	
			*dbufp++ = Base64Code[c1];
			*dbufp++ = '=';
			break;
		}

		c2 = *sbufp++;		
		pos++;
		
		c1 |= (c2 >> 6) & 0x03;		
		*dbufp++ = Base64Code[c1];	
		*dbufp++ = Base64Code[c2 & 0x3f];
	}
	*dbufp = '\0';

	return (kal_uint32)strlen((kal_char*)des);
}


/*****************************************************************************
 * FUNCTION
 *  decode_BASE64
 * DESCRIPTION
 *  decode base64 format data 
 *
 * PARAMETERS
 *  des      [IN]     decoded data
 *  src      [IN]     source data (base64 encoded data)
 *  length   [IN]     length of source data  
 *
 * RETURNS
 *  length of decoded data. return 0 if encode fail
 *****************************************************************************/
kal_uint32 decode_BASE64(kal_uint8* des, kal_uint8* src, kal_uint32 length)
{

	kal_uint8* dbufp;
	kal_uint8* ebufp;
	kal_uint32 c1, c2, c3, c4, len=0;

	if( length == 0 ) return 0;

	ebufp = src;
	dbufp = des;

	while( (c1 = *ebufp++) != 0x00 )
	{
		if (isascii(c1) && isspace(c1))
			continue;
		
		do
		{
			c2 = *ebufp++;
		} while (isascii(c2) && isspace(c2));
		if (c2 == 0x00)
			break;
		
		do
		{
			c3 = *ebufp++;
		} while (isascii(c3) && isspace(c3));
		if (c3 == 0x00)
			break;
		
		do
		{
			c4 = *ebufp++;
		} while (isascii(c4) && isspace(c4));
		if (c4 == 0x00)
			break;
		
		if (c1 == '=' || c2 == '=')
			continue;

		c1 = CHAR64(c1);
		c2 = CHAR64(c2);
		*dbufp++ = (c1 << 2) | ((c2 & 0x30) >> 4);
		len++;

		if (c3 == '=')
			continue;

		c3 = CHAR64(c3);
		*dbufp++ = ((c2 & 0x0f) << 4) | ((c3 & 0x3c) >> 2);
		len++;

		if (c4 == '=')
			continue;

		c4 = CHAR64(c4);
		*dbufp++ = ((c3 & 0x03) << 6) | c4;
		len++;

	}
	//for char string...
	*dbufp = '\0';

	return len;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_SWVersion
 * DESCRIPTION
 *  Phone Version information for MTC (MTC_PHONE_REPORT_REQ_CMD)
 *
 * PARAMETERS
 * void  
 *
 * RETURNS
 *  void
 *****************************************************************************/
void mtc_SWVersion(void)
{
    kal_mem_set(mtcVersion_Display, 0, 40);

    strcat(mtcVersion_Display, facSwVerModel);
    strcat(mtcVersion_Display, facSwVerType);
    strcat(mtcVersion_Display, facSwVerSimlock);
    strcat(mtcVersion_Display, facSwVerVersion);
    strcat(mtcVersion_Display, facSwVerMcc);
    strcat(mtcVersion_Display, facSwVerMnc);
    strcat(mtcVersion_Display, facSwVerDate);
    strcat(mtcVersion_Display, facSwVerHidden);
}


/*****************************************************************************
 * FUNCTION
 *  parseStrDateToInt
 * DESCRIPTION
 *  Convert date (MON DD YYYY) to uint32 value (YYYYMMDD)
 *
 * PARAMETERS
 * strDate   [IN]
 *
 * RETURNS
 *  void
 *****************************************************************************/
kal_uint32 parseStrDateToInt(kal_uint8* strDate)
{
	kal_uint32 rezDate = 0;
	kal_uint8* date_ptr = NULL;
	kal_uint8 tmp[5];
	kal_uint8 day = 0xff;
	kal_uint8 month = 0xff;
	kal_uint16 year = 0xffff;

	date_ptr = strDate;
	kal_mem_cpy ( tmp, date_ptr, 3 );	//copy month to tmp
	tmp[3] = '\0';
	if ( strcmp ( (char*)tmp, "Jan" ) == 0 )
		month = 1;
	else if ( strcmp ( (char*)tmp, "Feb" ) == 0 )
		month = 2;
	else if ( strcmp ( (char*)tmp, "Mar" ) == 0 )
		month = 3;
	else if ( strcmp ( (char*)tmp, "Apr" ) == 0 )
		month = 4;
	else if ( strcmp ( (char*)tmp, "May" ) == 0 )
		month = 5;
	else if ( strcmp ( (char*)tmp, "Jun" ) == 0 )
		month = 6;
	else if ( strcmp ( (char*)tmp, "Jul" ) == 0 )
		month = 7;
	else if ( strcmp ( (char*)tmp, "Aug" ) == 0 )
		month = 8;
	else if ( strcmp ( (char*)tmp, "Sep" ) == 0 )
		month = 9;
	else if ( strcmp ( (char*)tmp, "Oct" ) == 0 )
		month = 10;
	else if ( strcmp ( (char*)tmp, "Nov" ) == 0 )
		month = 11;
	else if ( strcmp ( (char*)tmp, "Dec" ) == 0 )
		month = 12;


	date_ptr += 4;	//position on day	
	tmp[0] = *date_ptr;
	date_ptr++;
	tmp[1] = *date_ptr;
	tmp[2] = '\0';
	date_ptr += 2;	//position on year
	day = atoi ((kal_char*) tmp );

	memcpy ( tmp, date_ptr, 4 );
	tmp[4] = '\0';
	year = atoi ((kal_char*) tmp );

	rezDate += day;
	rezDate <<= 8;
	rezDate += month;
	rezDate <<= 16;
	rezDate += year;

	return rezDate;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_check_keypad_code
 * DESCRIPTION
 *  Convert MTC keypad request(character) to keycode value 
 *
 * PARAMETERS
 *  key         [IN]  keypad request(character)   
 *  keycode     [OUT] keycode value
 *  keypad_type [IN]  Numberic or QWERTY
 * RETURNS
 *  false for invalid or unsupported keypad request
 *****************************************************************************/
kal_bool mtc_check_keypad_code(kal_uint8 *key,kal_uint8 *keycode,kal_uint8 keypad_type)
{
    kal_uint8 index = 0;
    kal_bool ret_val = KAL_TRUE;

    /* Numberic Keypad */
    if(keypad_type == 0) 
    {
        while((key[index] != 0) && (ret_val == KAL_TRUE))
        {
            switch (key[index])
            {
                case RMMI_CHAR_0:
                case RMMI_CHAR_1:
                case RMMI_CHAR_2:
                case RMMI_CHAR_3:
                case RMMI_CHAR_4:
                case RMMI_CHAR_5:
                case RMMI_CHAR_6:
                case RMMI_CHAR_7:
                case RMMI_CHAR_8:
                case RMMI_CHAR_9:
                    keycode[index] = DEVICE_KEY_0 + (key[index] - '0');
                    break;
                case RMMI_CHAR_STAR:
                    keycode[index] = DEVICE_KEY_STAR;
                    break;
                case RMMI_CHAR_POUND:
                    keycode[index] = DEVICE_KEY_HASH;
                    break;
                case RMMI_CHAR_U:
                case rmmi_char_u:
                    keycode[index] = DEVICE_KEY_VOL_UP;
                    break;
                case RMMI_CHAR_Y:
                case rmmi_char_y:
                    keycode[index] = DEVICE_KEY_CLEAR;
                    break;
                case RMMI_CHAR_D:
                case rmmi_char_d:
                    keycode[index] = DEVICE_KEY_VOL_DOWN;
                    break;
                case RMMI_HAT:
                    keycode[index] = DEVICE_KEY_BACKSPACE;
                    break;
                case RMMI_FORWARD_SLASH:
                    keycode[index] = DEVICE_KEY_UP;
                    break;					
                case RMMI_CHAR_V:
                case rmmi_char_v:
                    keycode[index] = DEVICE_KEY_DOWN;
                    break;
                case RMMI_CHAR_L:
                case rmmi_char_l:
        	          keycode[index] = DEVICE_KEY_LEFT;
                    break;
                case RMMI_CHAR_R:
                case rmmi_char_r:
                    keycode[index] = DEVICE_KEY_RIGHT;
                    break;			
                case RMMI_L_SQ_BRACKET:
                    keycode[index] = DEVICE_KEY_SK_LEFT;
                    break;
                case RMMI_R_SQ_BRACKET:
                    keycode[index] = DEVICE_KEY_SK_RIGHT;
                    break;
                case RMMI_CHAR_S:
                case rmmi_char_s:
                    keycode[index] = DEVICE_KEY_SEND;
                    break;
                case RMMI_CHAR_E:
                case rmmi_char_e:
                    keycode[index] = DEVICE_KEY_END;
                    break;
                /* The following keycode mapping might change in different project. Need confirmation */				
                case RMMI_CHAR_G:
                case rmmi_char_g:
                    keycode[index] = DEVICE_KEY_MENU;
                    break;
                case RMMI_CHAR_O:
                case rmmi_char_o:
                    keycode[index] = DEVICE_KEY_MENU;
                    break;
                case RMMI_CHAR_A:
                case rmmi_char_a:
                    keycode[index] = DEVICE_KEY_FUNCTION;
                    break;		
                default:
                    ret_val = KAL_FALSE;
                    break;
            }
            index++;
        }// end while    
    }
	else   /* QWERTY Keypad */
	{
        while((key[index] != 0) && (ret_val == KAL_TRUE))
        {
            if((key[index]>='a') && (key[index]<='z'))  
            {
                keycode[index] = DEVICE_KEY_A + (key[index] - rmmi_char_a);
            }       
            else if(key[index] == RMMI_CHAR_F)			
            {
                keycode[index] = DEVICE_KEY_FN;
            } 
            else if(key[index] == RMMI_CHAR_C)						
            {
                keycode[index] = DEVICE_KEY_CLEAR;
            }                				
            else if(key[index] == RMMI_CHAR_B)			
            {
                keycode[index] = DEVICE_KEY_SYMBOL;
            }                				
            else if(key[index] == RMMI_CHAR_H)			
            {
                keycode[index] = DEVICE_KEY_SHIFT;
            }  
            else if(key[index] == RMMI_CHAR_N)			
            {
                keycode[index] = DEVICE_KEY_ENTER;
            } 
            else if(key[index] == RMMI_CHAR_P)			
            {
                keycode[index] = DEVICE_KEY_SPACE;
            } 
            else if(key[index] == RMMI_CHAR_O)			
            {
                keycode[index] = DEVICE_KEY_MESSAGE;
            } 	
            else
            {
                ret_val = KAL_FALSE;
            } 				
        }// end while    
    }
	
    keycode[index] = 0xff;
    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_convert_keypad_code
 * DESCRIPTION
 *  Convert keycode value to MTC keypad character
 *
 * PARAMETERS
 *  keycode   [IN]   keycode value  
 * RETURNS
 *  MTC keypad character , return NULL character for invalid keycode
 *****************************************************************************/
kal_uint8 mtc_convert_keypad_code(kal_uint8 keycode)
{
    kal_uint8 key = 0;

    if((keycode >= DEVICE_KEY_0) && (keycode <= DEVICE_KEY_9)) /* Numberic Keypad */
    {
        key	= RMMI_CHAR_0 + (keycode - DEVICE_KEY_0);
    }
    else if((keycode >= DEVICE_KEY_A) && (keycode <= DEVICE_KEY_Z)) /* QWERTY Keypad */
    {
        key	= rmmi_char_a + (keycode - DEVICE_KEY_A);
    }     	
    else
    {
        switch(keycode)
        {
            /* Numberic Keypad */    
            case DEVICE_KEY_STAR:
            {
                key = RMMI_CHAR_STAR;
                break;		
            }			
            case DEVICE_KEY_HASH:
            {
                key = RMMI_CHAR_POUND;
                break;		
            }
            case DEVICE_KEY_VOL_UP:
            {
                key = RMMI_CHAR_U;
                break;		
            }
            case DEVICE_KEY_CLEAR:
            {
                key = RMMI_CHAR_Y;
                break;		
            }
            case DEVICE_KEY_VOL_DOWN:
            {
                key = RMMI_CHAR_D;
                break;		
            }
            case DEVICE_KEY_BACKSPACE:
            {
                key = RMMI_HAT;
                break;		
            }	
            case DEVICE_KEY_UP:
            {
                key = RMMI_FORWARD_SLASH;
                break;		
            }	
            case DEVICE_KEY_DOWN:
            {
                key = RMMI_CHAR_V;
                break;		
            }	
            case DEVICE_KEY_LEFT:
            {
                key = RMMI_CHAR_L;
                break;		
            }	
            case DEVICE_KEY_RIGHT:
            {
                key = RMMI_CHAR_R;
                break;		
            }	
            case DEVICE_KEY_SK_LEFT:
            {
                key = RMMI_L_SQ_BRACKET;
                break;		
            }
            case DEVICE_KEY_SK_RIGHT:
            {
                key = RMMI_R_SQ_BRACKET;
                break;		
            }		
            case DEVICE_KEY_SEND:
            {
                key = RMMI_CHAR_S;
                break;		
            }	
            case DEVICE_KEY_END:
            {
                key = RMMI_CHAR_E;
                break;		
            }	
            /* QWERTY keypad CLEAR key will conflict with Numeric keypad CLEAR key 'Y' */
#if 0			
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif            
            case DEVICE_KEY_SHIFT:
            {
                key = RMMI_CHAR_H;
                break;		
            }
            case DEVICE_KEY_ENTER:
            {
                key = RMMI_CHAR_N;
                break;		
            }	
            case DEVICE_KEY_SPACE:
            {
                key = RMMI_CHAR_P;
                break;		
            }
        
            /* mtk01616_091217 :Need confirmation for the following keycode mapping */						
            case DEVICE_KEY_OK:
            {
                key = RMMI_CHAR_G;
                break;		
            }	
            case DEVICE_KEY_MENU:
            {
                // Please confirm if keypad driver use Keycode DEVICE_KEY_MENU for  "OK" button
                key = RMMI_CHAR_G; 
                break;		
            }		
            case DEVICE_KEY_FUNCTION:
            {
                key = RMMI_CHAR_A;
                break;		
            }					
            default:
            {
                key = RMMI_END_OF_STRING_CHAR;
                break;		
            }		
        } //end switch   
    }//end else 
	
    return key;
}

#if !defined(EXTERNAL_MMI) //MTK MMI ex: V32/V33 Pluto MMI
/*****************************************************************************
 * FUNCTION
 *  get_LCD_buffer
 * DESCRIPTION
 *  This function is to get screen data buffer in MTK MMI project (ex: V32/V33) 
 *  For WISE MMI project get_LCD_buffer() function is implemented in BAL(ws_lcd_cmd.c)
 *
 * PARAMETERS
 *  screen_id           [IN]   mtc_scrn_id_type    
 *
 * RETURNS
 *  NULL or valid screen buffer pointer
 *****************************************************************************/
kal_uint8* get_LCD_buffer(kal_uint8 screen_id)
{
#if defined(PLUTO_MMI)
    gdi_handle lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
    gdi_screen_shot_info_struct* p;
	
    if(screen_id == MTC_MAIN_LCD)
    {
        lcd_handle = GDI_LCD_MAIN_LCD_HANDLE;
    }
	else if(screen_id == MTC_SUB_LCD)
    {
        lcd_handle = GDI_LCD_SUB_LCD_HANDLE;
    }		
    
    p = gdi_screen_shot_capture(lcd_handle,0);
	
    if(p != NULL)
    {
        return (kal_uint8*)p->buf_ptr;
    }		
    else	
    {
        kal_sys_trace("Error: Invalid screen buf_ptr returned from get_LCD_buffer()");
        return NULL;
    }
#else
    /* currently only PlutoMMI supports this feature */
    return NULL;
#endif /* defined(PLUTO_MMI) */
}
#endif /* EXTERNAL_MMI */


/*****************************************************************************
 * FUNCTION
 *  valid_memory_range_check
 * DESCRIPTION
 * Do Memory range check.
 * Not all memory can be read ,if we read periferial area,exception will happen
 *
 * PARAMETERS
 *  req_start_addr [IN] start address
 *  req_size       [IN] size
 *
 * RETURNS
 *  MTC keypad character , return NULL character for invalid keycode
 *****************************************************************************/
kal_bool valid_memory_range_check(kal_uint32 req_start_addr,kal_uint32 req_size)
{
    kal_uint32 u32NumberOfPages = 0;
    kal_uint32 *pageInfo = NULL;
	kal_bool valid = KAL_FALSE;
    kal_uint32 page_start_addr;
    kal_uint32 page_size;
    kal_uint32 n;  	
	
	/* INT_GetSysMemoryInfo will return a pageInfo array,which describle all valid memory page.  *
	 * pageInfo[2n] is starting address of the page.  pageInfo[2n+1 is size of the page          */
    INT_GetSysMemoryInfo(&pageInfo, (kal_uint16*) &u32NumberOfPages); 

	for(n=0; n<u32NumberOfPages; n++)
    {
        page_start_addr =  pageInfo[n*2];
        page_size = pageInfo[n*2+1];			
		
        if(page_size == 0) continue;

        if((req_start_addr < page_start_addr) &&
           ((req_start_addr + req_size) < (page_start_addr + page_size)))
        {
            /* found a valid memory range request */        
            valid = KAL_TRUE;
        }		
    }

    return valid;	
}
	

/*****************************************************************************
 *      Below are Functions to process each MTC ATS sub command              * 
 *****************************************************************************/
 
/*****************************************************************************
 * FUNCTION
 *  mtc_ats_screen_info_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :Get screen information (0x00)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *  encoded_rsp_data  [OUT]      
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_screen_info_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
	mtc_screen_info_rsp_type* ats_rsp;
    LCD_TYPE_ENUM screen_id;
    kal_uint32 scren_width,screen_height,color_depth;	
	
	ats_rsp = (mtc_screen_info_rsp_type*)rsp_ptr;	
	kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_screen_info_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

	switch(req_ptr->mtc_req.info.screen_id)
	{
		case MTC_MAIN_LCD:
            screen_id = MAIN_LCD;		
			break;
		case MTC_SUB_LCD:
            screen_id = SUB_LCD;					
			break;
		default:
			return KAL_FALSE;
	}

	ats_rsp->hdr = req_ptr->hdr;
	ats_rsp->scrn_id = req_ptr->mtc_req.info.screen_id;

/* return value of color_depth :
    4 color = 2          16 color = 4            256 color = 8       65K color = 16    
    262K color = 18    RGB 24bit = 24       RGB 32bit = 32 */
    lcd_get_screen_para_info(screen_id,&scren_width,&screen_height,&color_depth);

	ats_rsp->scrn_width = (kal_uint16)scren_width;
	ats_rsp->scrn_height = (kal_uint16)screen_height;
	ats_rsp->bits_pixel = (kal_uint8)color_depth;

	encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp, sizeof(mtc_screen_info_rsp_type));

	return KAL_TRUE;
}




/*****************************************************************************
 * FUNCTION
 *  mem_move
 * DESCRIPTION
 *  copy memory.
 * PARAMETERS
 *  dst_void        [OUT]        Destination buffer.
 *  src_void        [IN]         Source buffer.
 *  length          [IN]         Buffer length.
 * RETURNS
 *  void *
 *****************************************************************************/
void *mem_move(void *dst_void, const void *src_void, int length)
{
    char *dst;
    const char *src;

    if (src_void == NULL || dst_void == NULL || length <= 0)
    {
        return NULL;
    }

    dst = (char *)dst_void;
    src = (const char *)src_void;

    if (src < dst && dst < src + length)
    {
        src += length;
        dst += length;
        while (length--)
        {
            *--dst = *--src;
        }
    }
    else
    {
        while (length--)
        {
            *dst++ = *src++;
        }
    }

    return dst_void;
}


/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_simple_dpcm.c																	*
  *																																						*
  ******************************************************************************/
void ia_simple_dpcm_encode(
  const kal_uint8 * IN     in_plane
, int          IN     width                  // stride = width
, int           IN     height
, int           IN     exponential_quantizer
, kal_int8 *           OUT out_plane
)
{
  int y, prediction, line_prediction = DPCM_INITIAL_PREDICTION;
  for (y=0; y<height; ++y)
  {
    int           x;
    const kal_int8 * in_line  = (kal_int8 *)&in_plane [width*y];
    kal_int8 *       out_line = (kal_int8 *)&out_plane[width*y];

    out_line[0] = (kal_int8)((in_line[0] - line_prediction) >> exponential_quantizer);
    line_prediction = line_prediction + (out_line[0] << exponential_quantizer);

    prediction = line_prediction;
    for (x=1; x<width; ++x)
    {
      out_line[x] = (kal_int8)((in_line[x] - prediction) >> exponential_quantizer);
      prediction = prediction + (out_line[x] << exponential_quantizer);
    }
  }
}



/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_grayscale.c																		*
  *																																						*
  ******************************************************************************/
//------------------------------------------------------------------------------
// 16-bit RGB 565 BMP to 1-byte Black/White plane conversion.
void ia_rgb565_to_bwplane( const kal_uint8 * IN rgbdata,
                          kal_uint8 * OUT bwdata,
                          kal_uint16 IN width, kal_uint16 IN height, kal_uint8 threshold )
{
	kal_uint16 xcnt, ycnt;
	kal_uint16 rgb;
	kal_uint8 r, g, b;
	kal_uint32 y;

	for( ycnt = 0; ycnt < height; ycnt++ ) {

		for( xcnt = 0; xcnt < width; xcnt++ ) {

			rgb = *(rgbdata++);
			rgb |= (*(rgbdata++))<<8;

			r = (rgb & RGB565_REDMASK) >> RGB565_REDSHIFT;
			g = (rgb & RGB565_GREENMASK) >> RGB565_GREENSHIFT;
			b = (rgb & RGB565_BLUEMASK) >> RGB565_BLUESHIFT;

			/* rgb565 -> rgb888 */
			r = (r * 255 + 15) / 31;
			g = (g * 255 + 31) / 63;
			b = (b * 255 + 15) / 31;

			/* rgb888 -> yuv */
			y = ( r*77 + g*150 + b*29 ) >> 8;

			// y = (r*2104 + g*4130 + b*802 + 4096 + 131072)>>13;
			// if( y > 235) y = 235;

			/* y is in range [16,235] */
			//y = ( ( 66*r + 129*g +  25*b + 128) >> 8) +  16;
			/* y is in range [0,255] */
			//y -= 16;
			//y = ( y*255 + 109 ) / 219;

			if( y >= threshold )
				y = 0x01;
			else
				y = 0x00;

			*bwdata++ = (kal_uint8)y;
			 
		}
    
	}

	return;
}




//------------------------------------------------------------------------------
// 1-byte Black/White plane to 16-bit BMP-file data conversion.

void ia_bwplane_to_bmp16( const kal_uint8 * IN bwdata,  kal_uint8 * OUT bmpdata,
                          kal_uint16 IN width, kal_uint16 IN height )
{
	kal_uint16 xcnt, ycnt;
	kal_uint8 y;
	kal_uint32 bwbits_perline;
	kal_uint16 bwbits, bwbits_cnt;

	bwbits_perline = ( ( width + 31 ) / 32 ) * 32 ;

	for( ycnt = 0; ycnt < height; ycnt++ ) {

		bwbits = 0;
		bwbits_cnt = 0;

		for( xcnt = 0; xcnt < width; xcnt++ ) {
			y = *bwdata++;

			bwbits = ( bwbits << 1 ) | y;
			bwbits_cnt++;

			/* emit full data byte */
			if( bwbits_cnt == 8 ) {
				*bmpdata++ = bwbits;
				bwbits = 0;

				bwbits_cnt = 0;
			}
		}

		/* emit the trailing data bits */
		if( bwbits_cnt ) {
			bwbits <<= ( 8 - bwbits_cnt );
			
			*bmpdata++ = bwbits;
			bwbits = 0;
		}
    		bwbits_cnt = ( ( width + 7 ) >> 3 ) << 3;

		/* emit zeroes up to the 4-bytes boundary */
		while( bwbits_cnt < bwbits_perline ) {
			*bmpdata++ = bwbits;
			bwbits = 0;

			bwbits_cnt += 8;
		}
		
	}

}



/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_raw.c																				*
  *																																						*
  ******************************************************************************/
//------------------------------------------------------------------------------
// 16-bit RGB 565 BMP to 16-bit BMP-file data conversion.
// 
// Make all line lengths to be divisible by 4
void ia_rgb565_to_bmp16( const kal_uint8 * IN rgbdata, kal_uint8 * OUT bmpdata,
                          			kal_uint16 IN width, kal_uint16 IN height )
{
	kal_uint16 ycnt;
	kal_uint16 raw_line, bmp_line;
	const kal_uint16 bpp = 2;			/* bytes per pixel */

	if( (width % 2) == 0 )			/* images with even width are aligned already */
		return;
	
	raw_line = width*bpp;
	bmp_line = width*bpp + bpp;
	
	rgbdata += raw_line*height;
	bmpdata += bmp_line*height;
				
	for( ycnt = 0; ycnt < height; ycnt++ ) {
		rgbdata -= raw_line;
		bmpdata -= bmp_line;

		mem_move( bmpdata, rgbdata, raw_line );		
		kal_mem_set( bmpdata + raw_line, 0, bpp );
	}

	return;
}


//------------------------------------------------------------------------------
// 16-bit RGB 565 BMP to 8-bit RGB plane

void ia_rgb565_get_plane( const kal_uint8 * IN rgbdata, 
							kal_uint8 * OUT plane_data,
                          			kal_uint16 IN width, kal_uint16 IN height, kal_uint16 IN plane )
{
	kal_uint16 xcnt, ycnt;
	kal_uint16 rgb;
	kal_uint8 r, g, b;

	for( ycnt = 0; ycnt < height; ycnt++ ) {
		for( xcnt = 0; xcnt < width; xcnt++ ) {

			rgb = *(rgbdata++);
			rgb |= (*(rgbdata++))<<8;

			switch( plane ) {
			case RGB_PLANE_RED:
				r = (rgb & RGB565_REDMASK) >> RGB565_REDSHIFT;
				r = (r * 255 + 15) / 31;
				*plane_data++ = (kal_uint8)r;
				break;

			case RGB_PLANE_GREEN:			
				g = (rgb & RGB565_GREENMASK) >> RGB565_GREENSHIFT;
				g = (g * 255 + 31) / 63;
				*plane_data++ = (kal_uint8)g;
				break;
			
			case RGB_PLANE_BLUE:			
				b = (rgb & RGB565_BLUEMASK) >> RGB565_BLUESHIFT;
				b = (b * 255 + 15) / 31;
				*plane_data++ = (kal_uint8)b;
				break;
			}

		}
	}			

	return;
}


#if defined(__MTK_TARGET__)
#if defined (__ARMCC_VERSION)
#define INLINE __inline
#elif defined (__GNUC__)
#define INLINE inline
#endif /* ARMCC , GNUC */
#else  /* __MTK_TARGET__ */
#define INLINE __inline
#endif /* __MTK_TARGET__ */

/******************************************************************************
  *																																						*
  *					Integrate RFWS library - ia_rle.c																				*
  *																																						*
  ******************************************************************************/
//------------------------------------------------------------------------------
// This function puts bytes in the format of RLE
// Marker value is RLE_MAX_BIT_REPETITION.
static void __inline  ia_rle_put_count(
  kal_int32   IN     sequence_length                // the RL sequence length
, kal_uint8 *    OUT compressed_data                // the buffer for output data
, kal_int32 *    OUT out_index                      // The output length
)
{
  kal_int32 index = *out_index;

  if (sequence_length < RLE_MAX_BIT_REPETITION)
  {                                              
    compressed_data[index++] = (kal_uint8)sequence_length;
  }
  else
  {
    if (sequence_length >= RLE_REPETITION_MODULE*RLE_MAX_BIT_REPETITION)
    {
      kal_int32 decade3 =  sequence_length / (RLE_REPETITION_MODULE*RLE_REPETITION_MODULE);
      sequence_length -= decade3*(RLE_REPETITION_MODULE*RLE_REPETITION_MODULE);

      compressed_data[index++] = (kal_uint8)RLE_MAX_BIT_REPETITION;
      compressed_data[index++] = (kal_uint8)RLE_MAX_BIT_REPETITION;
      compressed_data[index++] = (kal_uint8) decade3;
      compressed_data[index++] = (kal_uint8)( sequence_length / RLE_REPETITION_MODULE );
      compressed_data[index++] = (kal_uint8)( sequence_length % RLE_REPETITION_MODULE );
    }
    else
    {
      compressed_data[index++] = (kal_uint8)RLE_MAX_BIT_REPETITION;
      compressed_data[index++] = (kal_uint8)( sequence_length / RLE_REPETITION_MODULE );
      compressed_data[index++] = (kal_uint8)( sequence_length % RLE_REPETITION_MODULE );
    }
  }
  
  *out_index = index;
}

//------------------------------------------------------------------------------
// Compression functions for byte data (0-255)
kal_int32 ia_rle_compress_buffer(
  const kal_uint8 * IN     data                     		 // the input data buffer
, kal_int32         IN     data_length                      // the length of input data [byte]
, kal_uint8 *      OUT  compressed_data              // the output data buffer
, kal_int32         IN     compressed_limit             // max length of output data [byte]
)
{
  kal_int32 index = 0, start_index;
  kal_int32 out_index = 0;
  kal_uint8 symbol;
  
  compressed_limit -= RLE_MAX_OUTPUT_CHUNK;
  if( out_index > compressed_limit )
    return -1;

  if (data_length > 0)
  {
    while (index < data_length)
    {
      symbol = data[ index++ ];
      compressed_data[out_index++] = symbol;

      start_index = index;

      while (symbol == data[ index ])
      {
        if (++index >= data_length)
        {
          ia_rle_put_count( index - start_index, compressed_data, &out_index );
          return out_index;
        }
      }
      
      ia_rle_put_count( index - start_index, compressed_data, &out_index );
      if( out_index > compressed_limit )
        return -1;
    }
  }
  
  return out_index;
}


//------------------------------------------------------------------------------
// Compression functions for bit data (0/1)
// This function performs RL compression of bit data.
kal_int32 ia_rle_compress_bit_buffer(
  const kal_uint8 * IN     data                     // Data buffer to compress
                                                // Value set of data buffer contains two values only
, kal_int32         IN     data_length              // Length of the data [byte]
, kal_uint8 *          OUT compressed_data          // the output data buffer
, kal_int32         IN     compressed_limit             // max length of output data [byte]
)
{
  kal_int32 index = 0, start_index;
  kal_int32 out_index = 0;
  kal_uint8 bit;

  compressed_limit -= RLE_MAX_OUTPUT_CHUNK;
  if( out_index > compressed_limit )
    return 0;

  if (data_length > 0)
  {
    bit = data[ index++ ];
    compressed_data[out_index++] = bit;

    while ( index < data_length )
    {
      start_index = index;

      while ( bit == data[ index ] )
      {
        if (++index >= data_length)
        {
          ia_rle_put_count( index - start_index, compressed_data, &out_index );
          return out_index;
        }
      }
      
      ia_rle_put_count( index - start_index, compressed_data, &out_index );
      if( out_index > compressed_limit )
        return -1;

      bit = data[ index++ ];
    }
  }
  
  return out_index;
}


/*****************************************************************************
 * FUNCTION
 *  MTCATSGetRectParameter
 *
 * DESCRIPTION
 *  Get the area for Area cropping and Masking
 *
 *
 * PARAMETERS
 *  context_p           [IN]       
 *  area_p           	 [IN]       
 *  rect_req             [IN]       
 *
 *
 * RETURNS
 *  KAL_TRUE / KAL_FALSE
 *****************************************************************************/
static kal_bool MTCATSGetRectParameter(
                                                              ATSImageCaptureContext* context_p,
	                                                        ATSImageCaptureRect* area_p, 
                                                              mtc_ats_capture_rect_type* rect_req ) {
    if( rect_req->left >= context_p->lcd_info->width_max )
        return KAL_FALSE;
    if( rect_req->top >= context_p->lcd_info->height_max )
        return KAL_FALSE;

    if( rect_req->width == 0 )
        rect_req->width = context_p->lcd_info->width_max - rect_req->left;
    if( rect_req->height == 0 )
        rect_req->height = context_p->lcd_info->height_max - rect_req->top;

    area_p->left = rect_req->left;
    area_p->up = rect_req->top;
    area_p->right = rect_req->left + rect_req->width;
    area_p->down = rect_req->top + rect_req->height;

    if( area_p->right <= area_p->left )
        return KAL_FALSE;
    if( area_p->down <= area_p->up )
        return KAL_FALSE;
	
    if( area_p->right > context_p->lcd_info->width_max )
        return KAL_FALSE;
    if( area_p->down > context_p->lcd_info->height_max )
        return KAL_FALSE;

	return KAL_TRUE;	
}


/*****************************************************************************
 * FUNCTION
 *  MTCATSSetContext
 *
 * DESCRIPTION
 *  Check the screen capture information and set parameters to atsImageCaptureContext
 *
 *
 * PARAMETERS
 *  req_ptr           	[IN]       
 *  req_len           	[IN]       
 *  lcd_info             [IN]       
 *
 *
 * RETURNS
 *  KAL_TRUE / KAL_FALSE
 *****************************************************************************/
kal_bool MTCATSSetContext( mtc_ats_capture_req_type* req_ptr, 
                                                   kal_uint16 req_len, mtc_lcd_info_type* lcd_info )
{
	kal_bool result = TRUE;
	ATSImageCaptureContext* context_p;
  
	context_p = &atsImageCaptureContext;

	context_p->lcd_info = lcd_info;

	/*  check parameters: base area */
	result = MTCATSGetRectParameter( context_p, &context_p->baseArea, &req_ptr->base_area );
	if( result == FALSE )
		return FALSE;

	/*  check parameters: request lenght and masks */ 
	for( context_p->nmask = 0; context_p->nmask <= ATS_IC_NMASK_MAX; context_p->nmask++ ) {
		kal_uint16 diff;
		diff = (ATS_IC_NMASK_MAX - context_p->nmask)*sizeof(mtc_ats_capture_mask_req_type);
		if( req_len == sizeof(mtc_ats_capture_req_type) -	diff )
			break;
#if 1 /* branden.you@lge.com 20100316 MTR Temperally */ //mtk01616_20100324: merge LGE's patch
		else if( req_len < sizeof(mtc_ats_capture_req_type) -	diff )
		{
			context_p->nmask--;
			break;
		}
#endif
	}
	if( context_p->nmask > ATS_IC_NMASK_MAX )
		return FALSE;

	if( context_p->nmask ) {
		kal_uint16 i;
		for( i = 0; i< context_p->nmask; i++ ) {
			if( req_ptr->masks[i].mask_type > ATS_IC_MASKTYPE_MAX )
				return KAL_FALSE;
			context_p->masks[i].maskType = (kal_int16)req_ptr->masks[i].mask_type;
			result = MTCATSGetRectParameter( context_p, &context_p->masks[i].maskArea, &req_ptr->masks[i].rect );
			if( result == KAL_FALSE )
				return KAL_FALSE;
		}
	}

	context_p->dataType = req_ptr->data_type;
	if( context_p->dataType > ATS_IC_DATATYPE_MAX)
		return KAL_FALSE;


	context_p->packType = req_ptr->pack_type;
	if( context_p->packType > ATS_IC_PACKTYPE_MAX)
		return KAL_FALSE;

	if( context_p->dataType == ATS_IC_DATATYPE_PLAIN  ) {
		/* pack types for bitmap data */
		if( context_p->packType != ATS_IC_PACKTYPE_NONE && 
			context_p->packType != ATS_IC_PACKTYPE_RLE && 
			context_p->packType != ATS_IC_PACKTYPE_DPCMRLE )
			return KAL_FALSE;
	}

	if( context_p->dataType == ATS_IC_DATATYPE_BLACKWHITE ) {
		/* pack types for bw bitmap data */
		if( context_p->packType != ATS_IC_PACKTYPE_NONE && 
			context_p->packType != ATS_IC_PACKTYPE_RLE )
			return KAL_FALSE;
	}

	if( context_p->dataType == ATS_IC_DATATYPE_HASH ) {
		/* pack types for hash data */
		if( context_p->packType != ATS_IC_PACKTYPE_SVF32 && 
			context_p->packType != ATS_IC_PACKTYPE_MD5 )
			return KAL_FALSE;
	}

	/* optional parameters */

	/* threshold */
	if( context_p->dataType == ATS_IC_DATATYPE_BLACKWHITE || 
		context_p->packType == ATS_IC_PACKTYPE_DPCMRLE ) {

		if( context_p->dataType == ATS_IC_DATATYPE_BLACKWHITE ) {
			context_p->dataThreshold = req_ptr->threshold;
			if( context_p->dataThreshold > 255 ) /* grayscale is in range [0;255] */
			  	return KAL_FALSE;
		}

		if( context_p->packType == ATS_IC_PACKTYPE_DPCMRLE ) {
			context_p->dataThreshold = req_ptr->quantizer;
			if( context_p->dataThreshold < DPCM_MINIMAL_QUANTIZER || 
				context_p->dataThreshold > DPCM_MAXIMAL_QUANTIZER  ) 	/* color is in range [2**0;2**8) */
			  	return KAL_FALSE;
		}
	}

	return result;
}



/*****************************************************************************
 * FUNCTION
 *  MTCATSScreenshotCrop
 *
 * DESCRIPTION
 *  Process Area cropping
 *
 *
 * PARAMETERS
 *       
 * 
 *
 * RETURNS
 *  
 *****************************************************************************/
void MTCATSScreenshotCrop( void )
{
	ATSImageCaptureContext* context_p;
	mtc_ats_capture_rsp_type* rsp_ptr;
	
	ATSImageCaptureRect* area_p;
	kal_uint16 ycnt;
	kal_uint32 skipup;
	kal_uint16 skipleft, copywidth, skipright;
	kal_uint8* srcptr, *dstptr;

	context_p = &atsImageCaptureContext;
	rsp_ptr = context_p->rsp_ptr;

	if( rsp_ptr->bmp_width == context_p->lcd_info->width_max &&
		rsp_ptr->bmp_height == context_p->lcd_info->height_max )
		return;

	srcptr = (kal_uint8*)(rsp_ptr) + sizeof(mtc_ats_capture_rsp_type);
	dstptr = (kal_uint8*)(rsp_ptr) + sizeof(mtc_ats_capture_rsp_type);


	area_p = &context_p->baseArea;
	skipup = area_p->up * context_p->lcd_info->width_max * ATS_IC_PIXELSIZE;
	skipleft = area_p->left * ATS_IC_PIXELSIZE;
	copywidth = (area_p->right - area_p->left) * ATS_IC_PIXELSIZE;
	skipright = (kal_uint16)(context_p->lcd_info->width_max - area_p->right) * ATS_IC_PIXELSIZE;

	srcptr += skipup;
	for( ycnt = area_p->up; ycnt < area_p->down; ycnt++ ) {
		srcptr += skipleft;

		mem_move( dstptr, srcptr, copywidth );
		dstptr += copywidth;
		srcptr += copywidth;
		srcptr += skipright;
	}

	rsp_ptr->bmp_size = (area_p->down - area_p->up)*copywidth;

	return;
}



/*****************************************************************************
 * FUNCTION
 *  vgATSApplyMasks
 *
 * DESCRIPTION
 *  Process Masking function
 *
 *
 * PARAMETERS
 *  context_p           [IN]       
 * 
 *
 * RETURNS
 *  
 *****************************************************************************/
static void vgATSApplyMasks( ATSImageCaptureContext* context_p )
{
	kal_uint16 xcnt, ycnt, i;
	ATSImageCaptureMask* mask_p, *maskLast_p, *maskFirst_p;
	kal_bool isMasked;
	kal_uint8* data_p;
	const kal_uint8 blank = 0x00;			/* black */

	if( context_p->nmask == 0 )
		return;

	data_p = context_p->screenshotBuffer;
	maskFirst_p = &context_p->masks[0];
	maskLast_p = &context_p->masks[context_p->nmask-1];

	for( ycnt = context_p->baseArea.up; ycnt < context_p->baseArea.down; ycnt++ )
	for( xcnt = context_p->baseArea.left; xcnt < context_p->baseArea.right; xcnt++ ) {

		isMasked = FALSE;
		for( mask_p = maskFirst_p; ; mask_p++ ) {
			if( (xcnt >= mask_p->maskArea.left) && (xcnt < mask_p->maskArea.right) )
			if( (ycnt>= mask_p->maskArea.up) &&  (ycnt < mask_p->maskArea.down) ) {
				isMasked = (mask_p->maskType == ATS_IC_MASKTYPE_OPAQUE );
			}
			if( mask_p == maskLast_p )
				break;
		}
		
		
		if (!isMasked) {
			if( (xcnt < mask_p->maskArea.left) || (xcnt >= mask_p->maskArea.right)  ||
				 (ycnt < mask_p->maskArea.up) ||  (ycnt >= mask_p->maskArea.down) ) {
				isMasked = (mask_p->maskType == ATS_IC_MASKTYPE_TRANSPARENT);
			}
		} else {
			data_p += ATS_IC_PIXELSIZE;
		}
	}

	return;
}



/*****************************************************************************
 * FUNCTION
 *  vgATSApplyPack
 *
 * DESCRIPTION
 *  Process Color depth change
 *
 *
 * PARAMETERS
 *  context_p           [IN]       
 * 
 *
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 vgATSApplyFormat( ATSImageCaptureContext* context_p ) {
	kal_uint16 width, height;
	ATSImageDataFormat dataFormat;
	kal_uint32 planeSize;
	const kal_uint16 planeOrder[3] = {RGB_PLANE_BLUE, RGB_PLANE_GREEN, RGB_PLANE_RED};

	dataFormat = ATS_IC_DataRaw;

	width = context_p->baseArea.right - context_p->baseArea.left;
	height = context_p->baseArea.down - context_p->baseArea.up; 
	planeSize = width * height;
			
	if ( context_p->dataType == ATS_IC_DATATYPE_BLACKWHITE ) {
			
		ia_rgb565_to_bwplane(
			(kal_uint8 *)context_p->screenshotBuffer, 
			(kal_uint8 *)context_p->screenshotBuffer,
			width, height, (kal_uint8)context_p->dataThreshold );

		context_p->fileSize = planeSize;
		dataFormat = ATS_IC_DataBPlane;
	}


	if ( context_p->packType == ATS_IC_PACKTYPE_RLE || 
		context_p->packType == ATS_IC_PACKTYPE_DPCMRLE ) {

		if( dataFormat == ATS_IC_DataRaw ) {
			kal_uint8 *RLEBuf, *planeBuf;
			kal_uint32 compressedSize, compressedLimit;
			kal_uint16 planeId;
			kal_int32 retval;

			/* RLE-compressed data size should not be more than non-compressed data size */			
			compressedSize = 0;
			compressedLimit = context_p->fileSize;

			RLEBuf = NULL;
			RLEBuf = get_ctrl_buffer(compressedLimit);
			if( RLEBuf == NULL ) {
				context_p->packType = ATS_IC_PACKTYPE_NONE;
  				goto pack_done;
			}

			planeBuf = NULL;
			planeBuf = get_ctrl_buffer(planeSize);
			if( planeBuf == NULL ) {
				context_p->packType = ATS_IC_PACKTYPE_NONE;
				free_ctrl_buffer(RLEBuf);
  				goto pack_done;
			}

			for( planeId = 0; planeId < 3; planeId++ ) {
	 			ia_rgb565_get_plane(
					(kal_uint8 *)context_p->screenshotBuffer, (kal_uint8 *)planeBuf,
					width, height, planeOrder[planeId] );

				if( context_p->packType == ATS_IC_PACKTYPE_DPCMRLE ) {
					ia_simple_dpcm_encode( (kal_uint8*)planeBuf, 
						width, height, context_p->dataThreshold, (kal_int8*)planeBuf );
				}

				retval = compressedLimit - compressedSize;
				if( retval <= 0 )
					break;

				retval = ia_rle_compress_buffer( 
					planeBuf, planeSize, 
					RLEBuf+compressedSize, retval );
				if( retval < 0 )
					break;
				compressedSize += retval;
			}
			if( retval < 0 ){
				context_p->packType = ATS_IC_PACKTYPE_NONE;
				free_ctrl_buffer(planeBuf);
				free_ctrl_buffer(RLEBuf);
				goto pack_done;
			}

			mem_move( context_p->screenshotBuffer, RLEBuf, compressedSize );
			context_p->fileSize = compressedSize;
		
			free_ctrl_buffer(planeBuf);
			free_ctrl_buffer(RLEBuf);

			dataFormat = ATS_IC_DataRLE;
		} else{

			kal_uint8 *RLEBuf;
			kal_uint32 compressedSize, compressedLimit;
			kal_int32 retval;

			/* RLE-compressed data size should not be more than non-compressed data size */
			compressedSize = 0;
			compressedLimit = context_p->fileSize/8;	  	/* plane bytes may be squeezed into bits */

			RLEBuf = NULL;
			RLEBuf = get_ctrl_buffer(compressedLimit);
			if( RLEBuf == NULL ) {
				context_p->packType = ATS_IC_PACKTYPE_NONE;
  				goto pack_done;
			}

			retval = ia_rle_compress_bit_buffer(
				(kal_uint8 *)context_p->screenshotBuffer, planeSize, 
				RLEBuf, compressedLimit );
			if( retval < 0 ) {
				context_p->packType = ATS_IC_PACKTYPE_NONE;
				free_ctrl_buffer(RLEBuf);
				goto pack_done;
			}
			compressedSize += retval;

			mem_move( context_p->screenshotBuffer, RLEBuf, compressedSize );
			context_p->fileSize = compressedSize;
			
			free_ctrl_buffer(RLEBuf);

			dataFormat = ATS_IC_DataRLE;
		}
	
	}

pack_done:

	/* prepare output data format, whatever it is */

	switch( dataFormat ) {
	case ATS_IC_DataRaw:
		{
			/*
			 * Convert RGB565 data to BMP-file body. We have to
			 * 1) Align BMP lines to 4-bytes boundaries
		 	 */
			ia_rgb565_to_bmp16( 
				(kal_uint8 *)context_p->screenshotBuffer, 
				(kal_uint8 *)context_p->screenshotBuffer,
				width, height );
			context_p->fileSize = ATS_IC_BMPBODYSIZE( width,  height );;
		}
		break;
	case ATS_IC_DataBPlane:
		{
			/*
			 * Convert Black-White plane data to BMP-file body. We have to
			 * 1) Squeeze bytes to bits
			 * 2) Align BMP lines to 4-bytes boundaries
			 */
			ia_bwplane_to_bmp16( 
				(kal_uint8 *)context_p->screenshotBuffer, 
				(kal_uint8 *)context_p->screenshotBuffer,
				width, height );
			context_p->fileSize = ( ( ( width + 31 ) >> 5 ) * 4 ) * height;
		}
	}
	
	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  vgATSApplyPack
 *
 * DESCRIPTION
 *  Process Hashing function
 *
 *
 * PARAMETERS
 *  context_p           [IN]       
 * 
 *
 * RETURNS
 *  
 *****************************************************************************/
static kal_uint16 vgATSApplyPack( ATSImageCaptureContext* context_p ) {
	kal_uint8* pdataBuf = NULL;
	kal_uint16 pdataSize;

	switch( context_p->packType ) {
	case ATS_IC_PACKTYPE_MD5:
		{
            STCHE md5Context;

			pdataSize = MD5_DIGEST_LENGTH;

			pdataBuf = NULL;
			pdataBuf = get_ctrl_buffer(pdataSize);
			
			if( pdataBuf == NULL )
	  			return 1;
            che_init(&md5Context, CHE_MD5);

            che_process(&md5Context, 
                        CHE_MD5, 
                        CHE_MODE_NULL, 
                        CHE_HASH, 
                        context_p->screenshotBuffer, 
                        pdataBuf, 
                        MD5_DIGEST_LENGTH, 
                        KAL_TRUE);
            
            che_deinit(&md5Context);
            
			mem_move( context_p->screenshotBuffer, pdataBuf, pdataSize );
			context_p->fileSize = pdataSize;

			free_ctrl_buffer(pdataBuf);
		}
		break;
		
	default:
		break; 
	}

	return 0;
}


/*****************************************************************************
 * FUNCTION
 *  MTCATSProcessScreenshot
 *
 * DESCRIPTION
 *  Process Advance screen capture procedure
 *	 Area cropping -> Masking -> Color depth change -> Hashing
 *
 * PARAMETERS
 * 
 *
 * RETURNS
 *  KAL_TRUE / KAL_FALSE
 *****************************************************************************/
static kal_bool MTCATSProcessScreenshot( void ) {
	
	ATSImageCaptureContext* context_p;
	mtc_ats_capture_rsp_type* rsp_ptr;

	context_p = &atsImageCaptureContext;
	rsp_ptr = context_p->rsp_ptr;

	MTCATSScreenshotCrop();
	context_p->fileSize = rsp_ptr->bmp_size;				// fileSize is updated

	vgATSApplyMasks( context_p );					

	if( vgATSApplyFormat( context_p ) != 0 )  			// fileSize is updated
		return FALSE;

	if ( vgATSApplyPack( context_p ) != 0 ) 				// fileSize is updated
		return FALSE;

	/* preparing to send the rsp packet */
	rsp_ptr->bmp_size = context_p->fileSize;
	bmp_buffer_ptr = context_p->fileSize + sizeof(mtc_ats_capture_rsp_type);	

	/*
		In case Black and White display is needed, bpp should be set to 1,
		other cases bpp is set in mtc_ats_capture_req_proc()		
	*/
	rsp_ptr->bits_pixel = 0;
	rsp_ptr->bits_pixel = context_p->dataType ==  ATS_IC_DATATYPE_BLACKWHITE ? 1 : 16;
		
	rsp_ptr->data_type = context_p->dataType;
	rsp_ptr->pack_type = context_p->packType;

	return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  MTCATSScreenshotTaken
 *
 * DESCRIPTION
 *  Prepare ATS screen capture response
 *
 * PARAMETERS
 *  rsp_ptr           [IN]       mtcats_bmp_buffer
 * 
 *
 * RETURNS
 *  KAL_TRUE / KAL_FALSE
 *****************************************************************************/
kal_bool MTCATSScreenshotTaken( mtc_ats_capture_rsp_type* rsp_ptr )
{
	ATSImageCaptureContext* context_p;

	context_p = &atsImageCaptureContext;
	context_p->rsp_ptr = rsp_ptr;
	context_p->screenshotBuffer = (kal_uint8*)(rsp_ptr) + sizeof(mtc_ats_capture_rsp_type);	
	context_p->fileSize = rsp_ptr->bmp_size;

	if( MTCATSProcessScreenshot() != TRUE )
		return KAL_FALSE;

	return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  ATS_output_screen_capture
 * DESCRIPTION
 *  Store bmp data to mtcats_bmp_buffer
 *
 * PARAMETERS
 *  x           [IN]       
 *  y           [IN]        
 *  w           [IN]       
 *  h           [IN]        
 *  screenData  [IN]        
 *
 * RETURNS
 *  KAL_TRUE / KAL_FALSE
 *****************************************************************************/
kal_bool ATS_output_screen_capture( kal_uint32 x, kal_uint32 y,kal_uint32 w, kal_uint32 h,kal_uint8 *screenData )
{
    kal_int32 startX, startY;	
    kal_uint16 *captureData;
    kal_uint32 destIndex=0;
    kal_uint32 srcIndex=0;

    if(screenData == NULL)
    {
        return KAL_FALSE;
    }

    captureData = (kal_uint16 *) screenData;

	bmp_buffer_ptr = sizeof(mtc_ats_capture_rsp_type);
    /* ATS will read Buffer data from end of Y-axis, so we just send buffer data as it is */
    while(destIndex < MTC_SCRN_BUF_SIZE_MAX)
    {
        mtcats_bmp_buffer[bmp_buffer_ptr++] = (kal_uint8) (captureData[srcIndex] & 0xFF);
        mtcats_bmp_buffer[bmp_buffer_ptr++] = (kal_uint8) (captureData[srcIndex++] >> 8);		
        destIndex += 2;
    }

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_capture_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :screen capture (0x01)
 *
 * PARAMETERS
 *  req_ptr           [IN]       
 *  req_len           [IN]
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_capture_req_proc(diag_mtc_req_type *req_ptr, kal_uint32 req_len)
{
	kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    kal_uint8* get_image_buf = NULL;
	mtc_capture_type CaptureInfo;
    kal_uint32 bmp_data_len = 0;
	LCD_TYPE_ENUM screen_id;
	kal_uint32 scren_width,screen_height,color_depth;	

	mtc_ats_capture_rsp_type *ats_rsp;
	diag_mtc_rsp_type *rsp_ptr;
	kal_bool ret_val;
    kal_uint32 ptr = 0;	
	kal_uint32 splitData = ((MAX_MTC_DATA_LENGTH - 4)/4)*3;
	kal_uint32 lastDataLen;
	kal_uint32 encodedLen;

	rsp_ptr = (diag_mtc_rsp_type *)mtcats_bmp_buffer;
	
	ats_rsp = ( mtc_ats_capture_rsp_type * ) ( rsp_ptr );

	kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

	if ( req_ptr == NULL || rsp_ptr == NULL )
		return KAL_FALSE;


    switch(req_ptr->mtc_req.info.screen_id)
    {
        case MTC_MAIN_LCD:
           screen_id = MAIN_LCD;		
           break;

        /* If SUB_LCD is not supported, ATS tool contains incorrect parameter so it should be returned as FALSE */
        #if defined (SUB_LCD_16BIT_MODE) || defined(SUB_LCD_8BIT_MODE) ||defined(SUB_LCD_9BIT_MODE) || defined(SUB_LCD_18BIT_MODE)
        case MTC_SUB_LCD:
           screen_id = SUB_LCD;					
           break;
        #endif
		
        default:
           return KAL_FALSE;
    }

    lcd_get_screen_para_info(screen_id,&scren_width,&screen_height,&color_depth);

    lcd_info.id = req_ptr->mtc_req.info.screen_id;
	lcd_info.width_max = scren_width;
	lcd_info.height_max = screen_height;

    /* return value of color_depth :
    4 color = 2          16 color = 4            256 color = 8       65K color = 16    
    262K color = 18    RGB 24bit = 24       RGB 32bit = 32 */
    if(color_depth == 16)
    {
        lcd_info.mask.blue = MTC_65K_CMASK_BLUE;
        lcd_info.mask.green = MTC_65K_CMASK_GREEN;
        lcd_info.mask.red = MTC_65K_CMASK_RED;			 			 			 
        lcd_info.bits_pixel = MTC_BIT_65K;			 			 			 
    }   	   
    else if(color_depth == 18)
    {
        lcd_info.mask.blue = MTC_262K_CMASK_BLUE;
        lcd_info.mask.green = MTC_262K_CMASK_GREEN;
        lcd_info.mask.red = MTC_262K_CMASK_RED;			 			 
        lcd_info.bits_pixel = MTC_BIT_262K;			 			 			 
    }   	

    lcd_info.degrees = 0; //No rotation .. manual Data	

    if ( MTCATSSetContext ( ( mtc_ats_capture_req_type * ) req_ptr, req_len, &lcd_info ) == KAL_FALSE )
       return KAL_FALSE;

	rsp_ptr->mtc_rsp.capture.bmp_width = lcd_info.width_max;
	rsp_ptr->mtc_rsp.capture.bmp_height = lcd_info.height_max;
	rsp_ptr->mtc_rsp.capture.bits_pixel = 0;
	rsp_ptr->mtc_rsp.capture.bits_pixel = lcd_info.bits_pixel;
	rsp_ptr->mtc_rsp.capture.mask.blue = lcd_info.mask.blue;
	rsp_ptr->mtc_rsp.capture.mask.green = lcd_info.mask.green;
	rsp_ptr->mtc_rsp.capture.mask.red = lcd_info.mask.red;

	CaptureInfo.start_x = 0;
	CaptureInfo.start_y = 0;
	CaptureInfo.width = lcd_info.width_max;
	CaptureInfo.height = lcd_info.height_max;

	kal_mem_set ( ( kal_uint8 * ) (mtcats_bmp_buffer)+sizeof(mtc_ats_capture_rsp_type), 0x00, MTC_SCRN_BUF_SIZE_MAX );

#if defined(EXTERNAL_MMI)
    if( ws_is_camera_videorecord_mode() )
    {

       get_image_buf = ws_camera_osd_current_buf();

        if(get_image_buf == NULL)
        {
            bmp_buffer_ptr = sizeof(mtc_ats_capture_rsp_type);
            ws_capturedimage_sw_rotate_ats( &(mtcats_bmp_buffer[bmp_buffer_ptr]),(kal_uint8 *)get_LCD_buffer(req_ptr->mtc_req.info.screen_id), 
                lcd_info.width_max, lcd_info.height_max);
            ret_val = KAL_TRUE;
        }
        else
        {
            ret_val = ATS_output_screen_capture(0, 0, lcd_info.width_max, lcd_info.height_max,(kal_uint8 *)get_image_buf);
        }
    }
    else
#endif    	
    {
        /* Output BMP data part */
	ret_val = ATS_output_screen_capture(0, 0, lcd_info.width_max, lcd_info.height_max,   (kal_uint8 *)get_LCD_buffer(req_ptr->mtc_req.info.screen_id));
    }
	
	if(ret_val == KAL_FALSE)
            return KAL_FALSE;	

	bmp_data_len = lcd_info.width_max*lcd_info.height_max*sizeof(mtc_pixel_16_type);

	if ( bmp_data_len == 0 )
		return KAL_FALSE;	

	ats_rsp->hdr = req_ptr->hdr;
	ats_rsp->bmp_width = req_ptr->mtc_req.capture.width;
	ats_rsp->bmp_height = req_ptr->mtc_req.capture.height;
	//memmove ( ( byte * ) ats_rsp->bmp_data, ( byte * ) rsp_ptr->mtc_rsp.capture.bmp_data, MTC_SCRN_BUF_SIZE_MAX );
	ats_rsp->bits_pixel = 0;
	ats_rsp->data_type = req_ptr->mtc_req.ats_capture.data_type;
	ats_rsp->pack_type = req_ptr->mtc_req.ats_capture.pack_type;
	ats_rsp->quantizer = req_ptr->mtc_req.ats_capture.quantizer;
	ats_rsp->threshold = req_ptr->mtc_req.ats_capture.threshold;
	ats_rsp->bmp_size = bmp_data_len;	

	if ( MTCATSScreenshotTaken ( ats_rsp ) != TRUE )
		return KAL_FALSE;

    while(bmp_buffer_ptr > 0)
    {
       if(bmp_buffer_ptr >= splitData)
       	{
             encodedLen = encode_BASE64(encoded_rsp_data,(kal_uint8*)&mtcats_bmp_buffer[ptr], splitData);
             rmmi_write_to_uart((kal_uint8*)encoded_rsp_data, encodedLen, KAL_FALSE);		

             bmp_buffer_ptr -= splitData;   
             ptr +=splitData;	
       	}
        else
        {   		
             lastDataLen = bmp_buffer_ptr;
             encodedLen = encode_BASE64(encoded_rsp_data,(kal_uint8*)&mtcats_bmp_buffer[ptr], lastDataLen);
             rmmi_write_to_uart((kal_uint8*) encoded_rsp_data, encodedLen, KAL_FALSE);			
             bmp_buffer_ptr = 0;   
        }
    }

    /* Output "OK" */
    if(ret_val == KAL_TRUE)    
    {
        rmmi_write_to_uart((kal_uint8*)"OK", 2, KAL_TRUE);
    }
	
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_key_log_mask_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :screen capture (0x01)
 *
 * PARAMETERS
 *  req_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_key_log_mask_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_key_log_mask_rsp_type *ats_rsp;
	
    ats_rsp = (mtc_ats_key_log_mask_rsp_type* )rsp_ptr;	
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_key_log_mask_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    kal_prompt_trace(l4c_current_mod_id,"set mtc_ats_key_log_mask=%d",mtc_ats_key_log_mask);									
    mtc_ats_key_log_mask = req_ptr->mtc_req.ats_key_log_mask.log_mask;

    ats_rsp->hdr = req_ptr->hdr;
#if 1 /* branden.you@lge.com 20100304 */ //mtk01616_20100324: merge LGE's patch
	{
		kal_uint32 tmp_mtc_ats_key_log_mask;
		kal_uint8 i = 0 ;
		kal_uint32 mask = 1;
		kal_uint32 mask_id = 0;
		mask_id  = req_ptr->mtc_req.ats_key_log_mask.log_mask;
		tmp_mtc_ats_key_log_mask = 0;
		for(i=0; i<sizeof(mask_id)*8; i++)
		{
			if((mask_id>>i) & mask)
			{
				tmp_mtc_ats_key_log_mask |= mask<<i;
			}
			else
			{
				tmp_mtc_ats_key_log_mask &= ~(mask<<i);
			}
		}
		ats_rsp->log_mask = tmp_mtc_ats_key_log_mask;
	}	
#else
/* under construction !*/
#endif

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_ats_key_log_mask_rsp_type));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_phone_restart_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :Phone Restart (0x10)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *  encoded_rsp_data  [OUT]        
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_phone_restart_req_proc (diag_mtc_req_type *req_ptr)
{
    l4cuem_power_reset(NORMAL_RESET);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_phone_restart_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :Phone Restart (0x10)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *  encoded_rsp_data  [OUT]        
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_factory_rst_req_proc(diag_mtc_req_type *req_ptr)
{
    /* Behave just  same as at%frst but no need to response to ATS */
    l4c_eq_factory_reset_lind(0);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_phone_report_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :Get phone report(MODEL,RELEASE_DATA,SW_VER,IMEI,etc.)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *  encoded_rsp_data  [OUT]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_phone_report_req_proc (diag_mtc_req_type *req_ptr, diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_phone_report_rsp_type* ats_rsp;
    kal_uint8 imei[16];  	
    kal_uint8 svn[3];

    ats_rsp = (mtc_ats_phone_report_rsp_type*)rsp_ptr;
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_phone_report_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));	
    kal_mem_set(imei,0,sizeof(imei));
    kal_mem_set(svn,0,sizeof(svn));

    ats_rsp->hdr = req_ptr->hdr;
	
#if defined(EXTERNAL_MMI)	//mtk01616_100111
    /* model name (10 bytes) */
    strncpy((char *)ats_rsp->model_name, "LIPTON",10);

    /* release date (4 bytes) */
	
    ats_rsp->release_date = parseStrDateToInt(__DATE__);	
#else
    /* model name (10 bytes) */
    strcpy((char *)ats_rsp->model_name, facSwVerModel);

    /* release date (4 bytes) */

    ats_rsp->release_date = parseStrDateToInt((kal_uint8*)__DATE__);	
#endif
	
    /* softare version (40 bytes) */
    mtc_SWVersion();

    kal_mem_cpy((void *)ats_rsp->software_ver, (void *)mtcVersion_Display, 40);

	/* IMEI (15 bytes) */
    if(l4c_nw_get_imei_req(RMMI_SRC,imei,svn) == KAL_TRUE)
    {
        kal_mem_cpy((void *)ats_rsp->IMEI,(void *)imei,15);
    }
	
    /* phone num */
    //NOT implemented in ADI solution
	
    /* supported functions */
    ats_rsp->enabled_functions = mtc_ats_supported_commamds;

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp, sizeof(mtc_ats_phone_report_rsp_type));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_phone_state_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd :Get phone state
 *
 * State (bits):
 * 0 ¡V Call in progress
 * 1 ¡V Ringing
 * 2 ¡V Outgoing call establishing
 * 3 ¡V SMS is sending
 * 4 ¡V MMS is sending
 * 5 ¡V Videocall in progress
 * 6 ¡V Data (GPRS/EDGE) connection established
 * 7 ¡V Java game is started
 * 8 ¡V Web/WAP browser is started
 * 9 ¡V IrDA is ON
 * 10 ¡V Bluetooth is ON
 * 11 ¡V Headset is connected
 * 
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *  encoded_rsp_data  [OUT]        
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_phone_state_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_phone_state_rsp_type *ats_rsp;
    kal_uint8 call_id;
    kal_uint8 num = 0;
    kal_uint8 i;
    kal_uint8 state_list[MMI_TOT_CONTEXT][2];
    kal_bool gprs_connection_exist = KAL_FALSE;	
    
    ats_rsp = (mtc_ats_phone_state_rsp_type* )rsp_ptr;		
    kal_mem_set((void*)ats_rsp,0,sizeof(mtc_ats_phone_state_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    ats_rsp->hdr = req_ptr->hdr;

    if(l4ccsm_cc_get_in_call(&call_id) == KAL_TRUE)    	
    {
        ats_rsp->phone_state |= 1;				//call in progress    
    }

    if(l4ccsm_cc_get_mt_call(&call_id) == KAL_TRUE)    	
    {
        ats_rsp->phone_state |= ( 1 << 1 );			//ringing		
    }

    if(l4ccsm_cc_get_outgoing_call(&call_id) == KAL_TRUE)
    {
	    ats_rsp->phone_state |= (1<<2);  				//outgoing call
    }

    if((l4c_search_all_src(l4c_current_mod_id,CMGS_EXE) == KAL_TRUE)||
       (l4c_search_all_src(l4c_current_mod_id,CMGS_PDU_EXE) == KAL_TRUE)||	
       (l4c_search_all_src(l4c_current_mod_id,CMSS_EXE) == KAL_TRUE))	
    {
        ats_rsp->phone_state |= ( 1 << 3 ); 	//SMS is sending
    }

#if defined(__MOD_TCM__)
    l4ctcm_get_context_state(&num,(kal_uint8*)state_list);

    for (i = 0; i < num; i++)
    {
        if (state_list[i][1] == 1) // 0: deactivated , 1: activated
        {
            kal_prompt_trace(l4c_current_mod_id,"ATS state:gprs_connection_exist");                    
            gprs_connection_exist = KAL_TRUE;
            break;
        }
    }    

    if(gprs_connection_exist == KAL_TRUE)
    {	
       ats_rsp->phone_state |= ( 1 << 6 );  //GPRS connection is established
    }
#endif	

#if defined(EXTERNAL_MMI) /*LG MMI project ex: WISE MMI */
////    ats_rsp->phone_state |= (1<<4); //MMS is sending

////	ats_rsp->phone_state |= (1<<5);							//videocall in progress

////    ats_rsp->phone_state |= ( 1 << 6 ); 		//GPRS connection is established

////	ats_rsp->phone_state |= (1<<7);					//Java is started

////	ats_rsp->phone_state |= (1<<8);		//Web/WAP browser is started

////	ats_rsp->phone_state |= (1<<9);							//IrDA is ON

////    ats_rsp->phone_state |= ( 1 << 10 );			//Bluetooth is ON

    if(ws_DeviceHS_GetHeadsetState() == KAL_TRUE)
    {
        ats_rsp->phone_state |= (1<<11);		//Headset is connected  - headset can not be connected to KG800 if communication cabel is connected
    }		
#else /* MTK MMI project ex: V32/V33 */


#if defined(MMS_SUPPORT) || defined(__MMI_MMS_2__)
    if(srv_mms_check_app_is_sending_mms() == KAL_TRUE)
    {
        kal_prompt_trace(l4c_current_mod_id,"ATS state:MMS is sending");    
        ats_rsp->phone_state |= (1<<4); //MMS is sending
    }
#endif

#if defined(__J2ME__)
    if(jam_get_running_storage_name()!= NULL) //get current running Java midlet name
    {	    
        kal_prompt_trace(l4c_current_mod_id,"ATS state:Java is started");
        ats_rsp->phone_state |= (1<<7);					//Java is started
    }        
#endif

#if defined(WAP_SUPPORT)
    if(wap_browser_is_open() == 1)
    {	
        kal_prompt_trace(l4c_current_mod_id,"ATS state:Web/WAP browser is started");        
        ats_rsp->phone_state |= (1<<8);		//Web/WAP browser is started
    }
#endif

#if defined(__BT_SUPPORT__)
    if(srv_bt_cm_get_power_status() == SRV_BT_CM_POWER_ON)
    {
        kal_prompt_trace(l4c_current_mod_id,"ATS state:Bluetooth is ON");            
        ats_rsp->phone_state |= ( 1 << 10 );	//Bluetooth is ON
    }
#endif

#endif

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_ats_phone_state_rsp_type));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_data_transfer_setup_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Request to setup data transfer parameters(0x22)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_data_transfer_setup_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr) 
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_transfer_setup_rsp_type *ats_rsp;
	
    ats_rsp = (mtc_ats_transfer_setup_rsp_type* )rsp_ptr;		
    kal_mem_set((void*)ats_rsp,0,sizeof(mtc_ats_transfer_setup_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    if(req_ptr->mtc_req.ats_setup.transfer_delay > 0)
    {
        kal_prompt_trace(l4c_current_mod_id,"set mtc_ats_key_log_mask=%d",mtc_ats_key_log_mask);												
        mtc_transfer_timeout = req_ptr->mtc_req.ats_setup.transfer_delay;
    }		
	
    if(req_ptr->mtc_req.ats_setup.packet_size > 0)
    {
    	if ( mtc_max_at_command_length > MAX_MTC_DATA_LENGTH )
        {			
            mtc_max_at_command_length = MAX_MTC_DATA_LENGTH;
        }		
        else
        {
            mtc_max_at_command_length = req_ptr->mtc_req.ats_setup.packet_size;
        }		

        
        kal_prompt_trace(l4c_current_mod_id,"set mtc_ats_key_log_mask=%d",mtc_ats_key_log_mask);											
    }

    ats_rsp->hdr = req_ptr->hdr;
    ats_rsp->packet_size = mtc_max_at_command_length;
    ats_rsp->transfer_delay = mtc_transfer_timeout;

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_ats_transfer_setup_rsp_type));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_key_report_en_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Enable/Disable key press notification(0x30)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_key_report_en_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_key_report_en_rsp_type *ats_rsp;
	
    ats_rsp = (mtc_ats_key_report_en_rsp_type* )rsp_ptr;
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_key_report_en_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    /* request_area 0: keypad notificator, 1: handover notificator, 2: touch screen */
    if (req_ptr->mtc_req.ats_key_report_en.request_area == 0)
    {
        kal_prompt_trace(l4c_current_mod_id,"set mtc_ats_key_report_enabled=%d",mtc_ats_key_report_enabled);										
	mtc_ats_key_report_enabled = req_ptr->mtc_req.ats_key_report_en.value;
    }

    ats_rsp->hdr = req_ptr->hdr;
    ats_rsp->request_area = req_ptr->mtc_req.ats_key_report_en.request_area;
    ats_rsp->value = req_ptr->mtc_req.ats_key_report_en.value;

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp, sizeof(mtc_ats_key_report_en_rsp_type));

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_key_event_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Normal key press emulation(0x33)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_key_event_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr,kal_uint8 src_id)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_key_event_rsp_type *ats_rsp;	
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 keycode[2]={0,0};
    kal_uint8 key[2]={0,0};	
	
    ats_rsp = (mtc_key_event_rsp_type* )rsp_ptr;		
    kal_mem_set((void*)ats_rsp,0,sizeof(mtc_key_event_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    key[0] = req_ptr->mtc_req.keyevent.KeyCode;
		
    if((key[0] == RMMI_CHAR_I) ||(key[0] == rmmi_char_i) )
    {
        /* FLIP_OPEN */    
        uemdrv_gpio_detect_ind (EXT_DEV_CLAM_OPEN);    
        encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_key_event_rsp_type));
    }	
    else if((key[0] == RMMI_CHAR_J) ||(key[0] == rmmi_char_j) )
    {
        /* FLIP_CLOSE */
        uemdrv_gpio_detect_ind (EXT_DEV_CLAM_CLOSE);    
        encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_key_event_rsp_type));
    }		
    else if(mtc_check_keypad_code(key,keycode,0) == KAL_TRUE)
    {
        ats_rsp->hdr = req_ptr->hdr;  
        ats_rsp->KeyCode = req_ptr->mtc_req.keyevent.KeyCode;
        ats_rsp->KeyHoldType = req_ptr->mtc_req.keyevent.KeyHoldType;
	
        // KeyHoldType press :1 , release :0 
        if(req_ptr->mtc_req.keyevent.KeyHoldType == 1)
        {
            /* press */        
            ret_val = l4c_eq_set_keypad_press_req(src_id,keycode);
        }
        else
        {
            /* emulate key release */        
            ret_val = l4c_eq_set_keypad_release_req();
        }			

        if(ret_val == KAL_TRUE)
        {
            encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_key_event_rsp_type));
        }
    }

    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_fast_key_event_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Fast key press emulation(0x35)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_fast_key_event_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr,kal_uint8 src_id)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_fast_key_event_resp *ats_rsp;	
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 keycode[2]={0,0};
    kal_uint8 key[2]={0,0};	
    kal_uint16 time,pause;
	
    ats_rsp = (mtc_fast_key_event_resp* )rsp_ptr;		
    kal_mem_set((void*)ats_rsp,0,sizeof(mtc_fast_key_event_resp));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    key[0] = req_ptr->mtc_req.fastkeyevent.KeyCode;
		
    if((key[0] == RMMI_CHAR_I) ||(key[0] == rmmi_char_i) )
    {
        /* FLIP_OPEN */    
        uemdrv_gpio_detect_ind (EXT_DEV_CLAM_OPEN);    
        encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_fast_key_event_resp));		
    }	
    else if((key[0] == RMMI_CHAR_J) ||(key[0] == rmmi_char_j) )
    {
        /* FLIP_CLOSE */
        uemdrv_gpio_detect_ind (EXT_DEV_CLAM_CLOSE);    
        encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_fast_key_event_resp));		
    }			
    else if(mtc_check_keypad_code(key,keycode,0) == KAL_TRUE)
    {
        ats_rsp->hdr = req_ptr->hdr;  
        ats_rsp->KeyCode = req_ptr->mtc_req.fastkeyevent.KeyCode;
        ats_rsp->Delay = req_ptr->mtc_req.fastkeyevent.Delay;
    
        time = req_ptr->mtc_req.fastkeyevent.Delay; /* time unit:0.1 sec */      
        pause = rmmi_get_ckpd_default_pause();

        /* Behave just like AT+CKPD, "OK" will be responsed by L4C later. */		
        ret_val = l4c_eq_set_keypad_input_req(src_id,keycode,(kal_uint8)time,(kal_uint8)pause);

        if(ret_val == KAL_TRUE)
        {
            encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_fast_key_event_resp));
        }
    }

    return ret_val;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_memory_dump_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Memory dump request(0x40)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_memory_dump_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_memory_rsp_type *ats_rsp;
    kal_uint32 tmpAdr = 0;
	
    ats_rsp = (mtc_ats_memory_rsp_type* )rsp_ptr;
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_memory_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));

    if(req_ptr->mtc_req.ats_dump.size > 64)
    {
        kal_prompt_trace(l4c_current_mod_id,"Try to do memory dump with invalid size =%d",req_ptr->mtc_req.ats_dump.size);										
        return KAL_FALSE;
    }

    /* Memory range check: Not all memory can be read ,if we read periferial area,exception will happen*/
    if(valid_memory_range_check(req_ptr->mtc_req.ats_dump.address,(kal_uint32)req_ptr->mtc_req.ats_dump.size) == KAL_FALSE)
    {
        kal_prompt_trace(l4c_current_mod_id,"Try to do memory dump with invalid address =%d,size=%d",req_ptr->mtc_req.ats_dump.address,req_ptr->mtc_req.ats_dump.size);										
        return KAL_FALSE;
    }	
	
    ats_rsp->hdr = req_ptr->hdr;
    tmpAdr = req_ptr->mtc_req.ats_dump.address;
    ats_rsp->address = (kal_uint32*)req_ptr->mtc_req.ats_dump.address;		
    ats_rsp->size = req_ptr->mtc_req.ats_dump.size;	
	
    kal_mem_cpy((void *)&ats_rsp->data[0],(void *)&tmpAdr,ats_rsp->size);

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp, sizeof(mtc_ats_memory_rsp_type)-64+ats_rsp->size);

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_backlight_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Get backlight state information(0x42)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_backlight_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
/* This function is implemented in WISE BAL. so we wrap with WISE MMI compile option */					
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_backlight_rsp_type *ats_rsp;
#if defined(EXTERNAL_MMI)						
    lgoem_dev_param_type vptr;	
#endif
	
    ats_rsp = (mtc_ats_backlight_rsp_type*)rsp_ptr;
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_backlight_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));
	
    ats_rsp->hdr = req_ptr->hdr;
	
    switch(req_ptr->mtc_req.ats_backlight.request_area)
    {
        case 0:
        {
#if defined(EXTERNAL_MMI)						
            /* MAIN LCD */
            lgoem_devmgr_function(DEV_FUNC_DISP_MAIN_GET_BRIGHTNESS,&vptr);		
				
	    /* brintness value is 0~16. Please refer to enum in WS_LIGHT_LEVEL */		 				
           /// ats_rsp->value = (vptr.data_byte * 255) / 16 ;											
           //mtk01616_100222: LGE only need ON/OFF state
           if(vptr.data_byte == 0)
           {
               ats_rsp->value = 0;
           }
           else		
           {
               ats_rsp->value = 255;
           }
		   	
#elif defined(PLUTO_MMI)
            /* For MTK MMI project */
            //mtk01616_100307: LGE only need ON/OFF state
            //mtk02508, MAUI_02961708 remove old API
            ats_rsp->value = srv_backlight_get_level(SRV_BACKLIGHT_TYPE_MAINLCD);
            if(ats_rsp->value == LED_LIGHT_LEVEL0)
            {
               ats_rsp->value = 0;
            }
            else		
            {
               ats_rsp->value = 255;
            }
#else
            /* TODO: Neptune porting */
            return KAL_FALSE;
#endif
            break;
        }			
        case 1:
        {			
#if defined(EXTERNAL_MMI)									
	    /*SUB LCD*/
            lgoem_devmgr_function(DEV_FUNC_DISP_SUB_GET_BRIGHTNESS,&vptr);		
			
	    /* brintness value is 0~16. Please refer to enum in WS_LIGHT_LEVEL */		 			
////            ats_rsp->value = (vptr.data_byte * 255) / 16 ;								
           //mtk01616_100222: LGE only need ON/OFF state
           if(vptr.data_byte == 0)
           {
               ats_rsp->value = 0;
           }
           else		
           {
               ats_rsp->value = 255;
           }            
#elif defined(PLUTO_MMI)
            /* For MTK MMI project */
            //mtk02508, MAUI_02961708 remove old API
            ats_rsp->value = srv_backlight_get_level(SRV_BACKLIGHT_TYPE_SUBLCD);

           //mtk01616_100307: LGE only need ON/OFF state
           if(ats_rsp->value == LED_LIGHT_LEVEL0)
           {
               ats_rsp->value = 0;
           }
           else		
           {
               ats_rsp->value = 255;
           }
#else
           /* TODO: Neptune porting */
           return KAL_FALSE;
#endif
            break;
	}			
        case 2:
        {			
#if defined(EXTERNAL_MMI)									
	    /*KEY PAD*/
            lgoem_devmgr_function(DEV_FUNC_GET_KEYLED,&vptr);		

	    /* brintness value is 0~16. Please refer to enum in WS_LIGHT_LEVEL */		 			
            ats_rsp->value = (vptr.data_byte * 255) / 16 ;					
#elif defined(PLUTO_MMI)
            /* For MTK MMI project */
            //mtk02508, MAUI_02961708 remove old API
            ats_rsp->value = (srv_backlight_get_level(SRV_BACKLIGHT_TYPE_KEYPAD)*255)/LED_LIGHT_LEVEL_MAX;
#else
            /* TODO: Neptune porting */
            return KAL_FALSE;
#endif
	    break;
	}
	default:
        {			
	    ats_rsp->value = 0xFF;
	    break;
        }			
    }	

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_ats_backlight_rsp_type));	

    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  mtc_ats_battery_level_req_proc
 * DESCRIPTION
 *  To process ATS sub_cmd : Get battery state information(0x41)
 *
 * PARAMETERS
 *  req_ptr           [IN]        
 *  rsp_ptr           [IN]       
 *
 * RETURNS
 *  TRUE or FALSE
 *****************************************************************************/
static kal_uint8 mtc_ats_battery_level_req_proc(diag_mtc_req_type *req_ptr,diag_mtc_rsp_type *rsp_ptr)
{
/* This function is implemented in WISE BAL. so we wrap with WISE MMI compile option */					
    kal_uint8* encoded_rsp_data = mtcats_atbuffer;
    mtc_ats_battery_rsp_type* ats_rsp;
    kal_uint8 battery_status;
    kal_uint32 battery_vol;

    ats_rsp = (mtc_ats_battery_rsp_type*)rsp_ptr;	
    kal_mem_set((void*)ats_rsp, 0, sizeof(mtc_ats_battery_rsp_type));
    kal_mem_set(encoded_rsp_data,0,sizeof((char*)mtcats_atbuffer));
		
    ats_rsp->hdr = req_ptr->hdr;

    /* battery_vol/100 represent the percentage value. max value of battery_vol is 10000  */
    l4c_eq_get_battery_capacity_status_req(RMMI_SRC, &battery_status, &battery_vol);

    ats_rsp->capacity = ((battery_vol / 100) * 255) /100;
#if defined(EXTERNAL_MMI)		
    /* WS_DEV_EXT_PWR_CHARGER means normal charger, WS_DEV_EXT_PWR_USB_CHARGER means USB cable charging*/	
    if (lgoem_DeviceHS_GetExtPwrState() == 0)// 0: WS_DEV_EXT_PWR_NONE 
#else
    if (uem_get_charging_status() == KAL_FALSE) /* for MTK MMI project */
#endif    
    {
        ats_rsp->isCharging = KAL_FALSE;
    }
    else
    {
        ats_rsp->isCharging = KAL_TRUE;
    }

    encode_BASE64(encoded_rsp_data,(kal_uint8*)ats_rsp,sizeof(mtc_ats_battery_rsp_type));

    return KAL_TRUE;
}

#if 1 /* branden.you@lge.com 20100305 */
static kal_uint8 mtc_ats_flex_data_req_proc (diag_mtc_req_type *req_ptr, diag_mtc_rsp_type *rsp_ptr)
{
#if defined(EXTERNAL_MMI)
	int flex_mcc_val=0;	

	flex_mcc_val = (int)Nm_Get_Flex_Mcc();
	
	kal_mem_set(mtcats_atbuffer, 0x00, sizeof(mtcats_atbuffer));

	PalDB_GetFlexValue((int)flex_mcc_val,(char *)(&(req_ptr->mtc_req)),(char *)mtcats_atbuffer);

	return KAL_TRUE;
#endif
}
#endif

/*****************************************************************************
 * FUNCTION
 *  rmmi_mtc_hdlr
 * DESCRIPTION
 *  AT+MTC command for ATS
 * PARAMETERS
 *  source_string_ptr       [IN]        At cmd string
 * RETURNS
 *  void
 *****************************************************************************/
void rmmi_mtc_hdlr(rmmi_string_struct *source_string_ptr)
{
    kal_bool ret_val = KAL_FALSE;
    kal_uint8 decode_param[((MAX_MTC_DATA_LENGTH/4)+1)*3];
    kal_uint32 decode_param_len = 0;
    kal_uint8 rsp_str[((MAX_MTC_DATA_LENGTH/4)+1)*3];	
    diag_mtc_req_type *req_ptr;
    diag_mtc_rsp_type *rsp_ptr;		
    kal_uint32 param_len = 0; /* MTC CMD parameter length */
    kal_uint16 param_index = 0; /* MTC CMD parameter index pointer */	
    kal_uint32 i = 0;	
	
    param_index	= source_string_ptr->index; /* param_index now point to the first char of MTC CMD parameter */
    kal_mem_set(decode_param,0,sizeof(decode_param));   
    kal_mem_set(rsp_str,0,sizeof(rsp_str));   	
	
    ats_src_id = source_string_ptr->src_id; 
	
    switch (source_string_ptr->cmd_mode)
    {
        case RMMI_SET_OR_EXECUTE_MODE:  //AT+MTC=xxxx , NOTE: no double quote
        {				
            if(strlen((char*)source_string_ptr->string_ptr) == 0)
            {			
                /*NO MTC request CMD parameter exist */            
                break;
            }

            /* get MTC request CMD parameter length */
            for(i=param_index; i<MAX_MTC_DATA_LENGTH; i++)            			
            {
                //AT+MTC=xxx<CR><LF>
                if((source_string_ptr->string_ptr[source_string_ptr->index]!=0x0A) && (source_string_ptr->string_ptr[source_string_ptr->index]!=0x0D))
                {					
                    param_len++;          
                    source_string_ptr->index++;					
                }	                            
				else
                {	
                    /* <CR> or <LF> found */                
				    break;
                }	   
            }
		
			if(param_len == MAX_MTC_DATA_LENGTH)
            {			
                /* MTC request CMD parameter is too long */            
                break;
            }

            decode_param_len = decode_BASE64(decode_param,&(source_string_ptr->string_ptr[param_index]), param_len);

            if(decode_param_len > 0)
            {			
                req_ptr = (diag_mtc_req_type*) decode_param;
                rsp_ptr = (diag_mtc_rsp_type*) rsp_str;				
            }			
			else
            {			
	            /* fail to decode base64 format parameter */            
                break;
            }	
			
            #if defined(__MTC_ATS_DEBUG_INFO__)
            kal_prompt_trace(l4c_current_mod_id,"decode_param_len=%d",decode_param_len);							
			
            for(i=0;i<decode_param_len;i++)
                kal_prompt_trace(l4c_current_mod_id,"decode_param[%d]=%d,%x",i,decode_param[i],decode_param[i]);				
            #endif
			
            switch(req_ptr->hdr.sub_cmd)
            {
                case MTC_SCREEN_INFO_REQ_CMD:
                {					
                    ret_val = mtc_ats_screen_info_req_proc(req_ptr,rsp_ptr);
                    break;
                }					
				
                case MTC_CAPTURE_REQ_CMD:
                {					
                    ret_val = mtc_ats_capture_req_proc(req_ptr,decode_param_len);

                    /* For scrren capture,ALL response data will be handled in mtc_ats_capture_req_proc() */					
                    if(ret_val == KAL_TRUE)
                        return;						

                    break;                        					
                }

                case MTC_KEY_LOG_MASK_CMD:
                {			
                    ret_val = mtc_ats_key_log_mask_req_proc(req_ptr,rsp_ptr);
                    break;
                }

                case MTC_PHONE_RESTART_REQ_CMD:
                {            					
                    if (decode_param_len != sizeof(mtc_req_hdr_type))
                    {
                        kal_prompt_trace(l4c_current_mod_id,"Invalid parameter size:decode_param_len=%d,expected_len=%d",decode_param_len,sizeof(mtc_req_hdr_type));							
                        break; 
                    }
					
                    ret_val = mtc_ats_phone_restart_req_proc(req_ptr);
                    break;
                }					
				
                case MTC_PHONE_FACTORY_RST_CMD:
                {			
                    rmmi_custom_frst_cmd = RMMI_CUSTOM_FRST_FROM_MTC;
                    L4C_PTR->route_thru_lmmi_user = source_string_ptr->src_id;
                    L4C_PTR->route_thru_lmmi = KAL_TRUE;

                    ret_val = mtc_ats_factory_rst_req_proc(req_ptr);

                    if(ret_val == KAL_TRUE)
                        return;
					
                    break;
                }

                case MTC_PHONE_REPORT_REQ_CMD:
                {			
                    ret_val = mtc_ats_phone_report_req_proc(req_ptr,rsp_ptr);
                    break;
                }
			
                case MTC_PHONE_STATE_REQ_CMD:
                {					
                    ret_val = mtc_ats_phone_state_req_proc(req_ptr,rsp_ptr);
                    break;
                }

                case MTC_DATA_TRANSFER_SETUP_CMD:
                {			
                    ret_val = mtc_ats_data_transfer_setup_req_proc(req_ptr,rsp_ptr);
                    break;
                }

                case MTC_KEY_REPORT_EN_REQ_CMD:
                {			
                    ret_val = mtc_ats_key_report_en_req_proc(req_ptr,rsp_ptr);
                    break;
                }
						
                case MTC_KEY_EVENT_REQ_CMD:
                {
                    ret_val = mtc_ats_key_event_req_proc(req_ptr,rsp_ptr,source_string_ptr->src_id);  						
                    break;
                }
				
                case MTC_FAST_KEY_EVENT_REQ_CMD:
                {					
                    if(decode_param_len != sizeof(mtc_fast_key_event_req_type))
                    {

                        kal_prompt_trace(l4c_current_mod_id,"Invalid parameter size:decode_param_len=%d,expected_len=%d",decode_param_len,sizeof(mtc_fast_key_event_req_type));							                    
                        break; 
                    }
					
                    ret_val = mtc_ats_fast_key_event_req_proc(req_ptr,rsp_ptr,source_string_ptr->src_id);

                    /* Behave just like AT+CKPD, "OK" will be responsed by L4C later. We only return encoded rsp data first. */		
                    if(ret_val == KAL_TRUE)
                    {
                    #if defined(__MTC_ATS_DEBUG_INFO__)                    
                        for(i=0;i<strlen((char*)mtcats_atbuffer);i++)
                            kal_prompt_trace(l4c_current_mod_id,"encoded_rsp[%d]=%d",i,mtcats_atbuffer[i]);							
                    #endif                    
                        rmmi_write_to_uart((kal_uint8*) mtcats_atbuffer, strlen((char*)mtcats_atbuffer), KAL_TRUE);
                        return;
                    }										
                    break;
                }                			

                case MTC_MEMORY_DUMP_REQ_CMD:
                {			
                    if (decode_param_len != sizeof(mtc_ats_memory_req_type))
                    {
                        kal_prompt_trace(l4c_current_mod_id,"Invalid parameter size:decode_param_len=%d,expected_len=%d",decode_param_len,sizeof(mtc_ats_memory_req_type));							                    
                        break;
                    }

                    ret_val = mtc_ats_memory_dump_req_proc(req_ptr,rsp_ptr);
                    break;
                }
		
                case MTC_BATTERY_LEVEL_REQ_CMD:
                {			
                    ret_val = mtc_ats_battery_level_req_proc(req_ptr,rsp_ptr);
                    break;
                }			
				
                case MTC_BACKLIGHT_REQ_CMD:
                {			
                    if (decode_param_len != sizeof(mtc_ats_backlight_req_type))
                    {
                        kal_prompt_trace(l4c_current_mod_id,"Invalid parameter size:decode_param_len=%d,expected_len=%d",decode_param_len,sizeof(mtc_ats_backlight_req_type));							                    
                        break;
                    }

                    ret_val = mtc_ats_backlight_req_proc(req_ptr,rsp_ptr);					
                    break;
                }			
			
                case MTC_FLEX_DATA_REQ_CMD :
                {			
#if 1 /* branden.you@lge.com 20100305 */
                    ret_val = mtc_ats_flex_data_req_proc(req_ptr,rsp_ptr);
#endif
                    break;
                }

                default:
                    break;
            }/* end of the switch */
			
        }

        case RMMI_ACTIVE_MODE: //AT+MTC
        case RMMI_TEST_MODE: //AT+MTC=?
        case RMMI_READ_MODE:  //AT+MTC?		
        default:
        {
            /* unrecognized format of AT command line */
            break;
        }
    }/* end of the switch */

#if defined(__MTC_ATS_DEBUG_INFO__)
    for(i=0;i<strlen((char*)mtcats_atbuffer);i++)
        kal_prompt_trace(l4c_current_mod_id,"encoded_rsp[%d]=%x,%d",i,mtcats_atbuffer[i],mtcats_atbuffer[i]);							
#endif

    rmmi_final_rsp_generator(source_string_ptr->src_id, ret_val, (kal_uint8*) mtcats_atbuffer, strlen((char*)mtcats_atbuffer));
    return;
}
#else 
/* dummy callback function */
void ws_key_event_notification(kal_uint8 key_code ,kal_uint8 key_type,kal_uint32 time_stamp){}
void ws_output_screen_capture_info(kal_uint8* screen_capture_buf,kal_uint32 length){}
void mtc_ats_factory_rst_rsp(kal_bool result){}
void rmmi_mtc_hdlr(rmmi_string_struct *source_string_ptr){}
void ws_output_key_event_notification(kal_uint8 key_code ,kal_uint8 key_type,kal_uint32 time_stamp){}
void ws_output_gpio_event_notification(kal_uint8 gpio_device, kal_bool on_off){}
#endif /* defined(__MTC_ATS_SUPPORT__) && defined(__MTK_TARGET__) */
#endif /*__TC01__*/

