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
 *    keypad_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for keypad driver and adaption.
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _KEYPAD_H
#define _KEYPAD_H

#include "drv_features.h"
#include "intrCtrl.h"
#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "keypad_sw.h"
#include "dcl.h"


typedef enum {
   kbd_1_key_det_mode = 0,
   kbd_2_keys_det_mode,
   kbd_3_keys_det_mode
} kbd_key_det_mode;





#define __DCL_KBD_SUPPORT__

#if defined(__EXTEND_QWERTY_KEYPAD__)

#define KBD_MASKIRQ          SetINTMask(IRQ_KPAD_CODE)
#define KBD_UNMASKIRQ      RestoreINTMask(IRQ_KPAD_CODE)
#else

#define KBD_MASKIRQ          IRQMask(IRQ_KPAD_CODE)
#define KBD_UNMASKIRQ      IRQUnmask(IRQ_KPAD_CODE)

#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)

#ifdef __EXTRA_A_B_KEY_SUPPORT__
#define KBD_EX_GPT_HDL_CNT 2
#else
#define KBD_EX_GPT_HDL_CNT  0
#endif

#if defined(__TWO_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 2
#elif defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #define KBD_KEY_DETECTION_CNT 3
#else
    #define KBD_KEY_DETECTION_CNT 1
#endif 

#define KBD_GPT_HDL_CNT (KBD_EX_GPT_HDL_CNT + KBD_KEY_DETECTION_CNT)

#define EVENT_REQUESTED  (KBD_STATUS_CHANGE_EVENT|KBD_SWITCH_DETCTION_MODE_EVENT |KEY_UP_EVENT| KEY_DOWN_EVENT| KEY_RIGHT_EVENT | KEY_LEFT_EVENT)

#if defined(TWO_KEY_ENABLE)
   #if defined(__TWO_KEY_DETECTION_SWITCHABLE__) || defined(__THREE_KEY_DETECTION_SWITCHABLE__)
   #error " kbd config conflicts!!"
   #endif
#endif


typedef struct
{
    kal_uint32  kbdmap_reg;
    kal_uint32   kbdmap_reg1; 
   kal_uint32    kbdmap_reg2; 
}kbd_map_reg_struct;

typedef enum
{
    KEY_DIRECTION_EVENT_NUll,
    KBD_STATUS_CHANGE_EVENT = 0x01, /*keypad status changes event id */
    KBD_SWITCH_DETCTION_MODE_EVENT = 0x02, /*keypad switch detection mode event id*/
    
    KEY_UP_EVENT = 0x10,
    KEY_DOWN_EVENT = 0x20,
    KEY_LEFT_EVENT = 0x40,
    KEY_RIGHT_EVENT = 0x80,
    KEY_DIRECTION_EVENT_ALL = 0xF0
}kbd_task_event;


typedef struct
{
   kal_eventgrpid    event;  
   DCL_HANDLE	gpthandle[KBD_GPT_HDL_CNT];
   
#ifdef __EXTRA_A_B_KEY_SUPPORT__
	kal_bool       ext_status[2];
#endif/*__EXTRA_A_B_KEY_SUPPORT__*/

#ifdef __KBD_2STEP_KEY_SUPPORT__
DCL_HANDLE         kbd_2key_handle;   
#endif
#if defined(__EXTEND_QWERTY_KEYPAD__)
   DCL_HANDLE         kbd_extend_gpthandle;
   kal_uint32        polling_timeout;
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint32        longpress_timeout;
   kal_uint32        repeat_time;
} kbd_struct;


#if defined(__EXTEND_QWERTY_KEYPAD__)

typedef struct
{
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
}keypad_Ext_QwertyKey_Status;
 typedef struct
 {
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
    
    kal_uint8   kbd_press_GND_column[KBD_KEY_DETECTION_CNT]; // which column pressed
    kal_uint8   kbd_press_GPO_column[KBD_KEY_DETECTION_CNT]; // which column pressed
 }keypad_Ext_QwertyKey_detect_info_struct;
 
#endif

 /*keypad detect keys result during one key event*/
 typedef struct 
 {
 #if defined(__EXTEND_QWERTY_KEYPAD__)
        keypad_Ext_QwertyKey_detect_info_struct  kbd_Ext_Qwerty_key_info;
#endif
    kal_uint8   key_presscount;
    kal_uint8   key_releasecount;
    kal_uint8   key_total_count;

    kal_uint8   kbd_press_key[KBD_KEY_DETECTION_CNT];
    kal_uint8   kbd_release_key[KBD_KEY_DETECTION_CNT];

 } keypad_detect_info_struct;

typedef enum
{
    Normal_ROW = 0,
    Ext_GPO_ROW,
    Ext_GND_ROW
}Keypad_ROW_Type;

/*every key information*/
 typedef struct
 {
    kal_bool bKeyStatus;                /*0: press; 1: release */
    kal_uint16 key_index;               /*key index defined during customization*/

#if defined(__EXTEND_QWERTY_KEYPAD__)
    kal_uint8 key_column;             /*extend keys in which column*/  
    Keypad_ROW_Type Row_Type;
#endif
 }keypad_key_info;

typedef struct
{
    kbd_map_reg_struct kbd_map_reg;    
#if defined(__EXTEND_QWERTY_KEYPAD__)
    kal_bool    key_column_all_low_GND[KBD_COLUMN]; //column all low cause by GND_ROW
    kal_bool    key_column_all_low_GPO[KBD_COLUMN]; //column all low cause by GPO_ROW
    kal_bool    extend_switch_mode_key;//when switch mode, the extend key is pressed
    kal_uint8   extend_key_switch_pressed_num;
    kal_uint8   kbd_switch_mode_extend_press_key[KBD_KEY_DETECTION_CNT];
    
#endif

}keypad_status_struct;

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
      extern const kal_uint8    EXTRA_A_KEY_EINT_NO;
      extern const kal_uint8    EXTRA_B_KEY_EINT_NO;
      #define  EINT_A_KEY     EXTRA_A_KEY_EINT_NO
      #define  EINT_B_KEY     EXTRA_B_KEY_EINT_NO
#endif

#if defined(__TC01__)
#define kbd_push_time_stamp() \
{\
  kal_get_time(&(kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_windex].keytimestamp));\
}

#define kbd_pop_time_stamp(_key_data) \
{\
kbd_data* key_data = (kbd_data*)(_key_data);\
key_data->keytimestamp = kbd_buffer.kbd_data_buffer[kbd_buffer.kbd_data_buffer_rindex].keytimestamp;\
}

#else
#define kbd_push_time_stamp() ;
#define kbd_pop_time_stamp(_key_data) ;
#endif

extern void kbdbuffer_get_roomleft_(kal_uint8* pleft);

#define kbdbuffer_get_roomleft(_left)   \
{\
   kbdbuffer_get_roomleft_(&(_left));\
}


extern void Kbd_Initiaze(void);
extern kal_bool Kbd_GetDetectionMode(kal_uint8 *pmode);
extern kal_bool kbd_SetDetectionMode(kbd_key_det_mode mode);
extern kal_bool kbd_IsKeySupported(kal_uint8 key);
extern kal_bool kbd_IsKeymutiple(kal_uint8 key);
extern kal_uint32 Kbd_GetKeyCount(void);
extern kal_bool Kbd_GetKeyDatas(kbd_data *keydata);
extern kal_bool Kbd_PeekKeyDatas(kbd_data *keydata, kal_bool specify_read, 
											kal_uint32 read_pointer,kal_uint32* current_read_pointer);
extern kal_uint32 kbd_SendKey(kal_uint8 key);
extern void Kbd_SetLongPreTime(kal_uint32 ticks);
extern void Kbd_SetRepeatPreTime(kal_uint32 ticks);


//#include "us_timer.h"
extern kal_uint32 L1I_GetTimeStamp(void);
#define KBD_GetTimeStamp L1I_GetTimeStamp
#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT) && !defined(__MAUI_BASIC__) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && defined(__EXTEND_QWERTY_KEYPAD__)
#define DRV_KBD_MEMORY_TRACE
typedef struct{
   kal_uint16      tag;
   kal_uint32      time;
   kal_uint32      data1;
   kal_uint32      data2;
}KBD_DRV_DBG_DATA;
#define MAX_KBD_DRV_DBG_INFO_SIZE 512
typedef struct{
   KBD_DRV_DBG_DATA   dbg_data[MAX_KBD_DRV_DBG_INFO_SIZE];
   kal_uint16         dbg_data_idx;
}KBD_DRV_DBG_STRUCT;
extern void kbd_drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2);
#define KBD_DBG(a,b,c,d) kbd_drv_dbg_trace(a,b,c,d);
#else //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)
#define KBD_DBG(a,b,c,d) ;
#endif //#if defined(__MTK_INTERNAL__) && !defined(LOW_COST_SUPPORT)


#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_KBD_REG_DBG__)
#define DRV_KBD_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_KBD_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_KBD_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_KBD_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_KBD_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_KBD_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_KBD_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_KBD_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_KBD_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_KBD_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_KBD_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_KBD_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_KBD_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_KBD_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_KBD_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_KBD_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_KBD_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_KBD_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_KBD_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_KBD_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_KBD_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_KBD_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_KBD_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_KBD_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_KBD_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_KBD_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_KBD_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_KBD_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_KBD_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_KBD_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_KBD_REG_DBG__)

#endif





