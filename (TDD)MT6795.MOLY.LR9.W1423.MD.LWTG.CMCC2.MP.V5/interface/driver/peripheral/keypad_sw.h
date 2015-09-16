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
#ifndef _KEYPAD_SW_H
#define _KEYPAD_SW_H

#include "intrCtrl.h"
#include "drv_features_kbd.h"
#include "drv_comm.h"
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"


#if defined(DRV_KBD_25_KEYS) || defined(FPGA)
   #define  kbd_allkeys          25
   #define  KBD_ROW              5
   #define  KBD_COLUMN_MASK      0x1F //5 bits mask
   #define  KBD_COLUMN           5
#elif defined(DRV_KBD_36_KEYS)
   #define  kbd_allkeys          36
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           6
#elif defined(DRV_KBD_42_KEYS)
   #define  kbd_allkeys          42   
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           7
#elif defined(DRV_KBD_35_KEYS)
   #define  kbd_allkeys          35
   #define  KBD_ROW              5
   #define  KBD_COLUMN_MASK      0x1F //5 bits mask
   #define  KBD_COLUMN           7
#elif defined(DRV_KBD_54_KEYS)
   #define  kbd_allkeys          54
   #define  KBD_ROW              6
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           9
#elif defined(DRV_KBD_63_KEYS)
   #define  kbd_allkeys          63
   #define  KBD_ROW              7
   #define  KBD_COLUMN_MASK      0x3F //6 bits mask
   #define  KBD_COLUMN           9 
#elif defined(DRV_KBD_72_KEYS)
   #define  kbd_allkeys          72
   #define  KBD_ROW              8
   #define  KBD_COLUMN_MASK      0xFF //8 bits mask
   #define  KBD_COLUMN           9
#elif defined(DRV_KBD_NOT_EXIST)
   #define  kbd_allkeys          1
   #define  KBD_ROW              1
   #define  KBD_COLUMN_MASK      0x1 //1 bits mask
   #define  KBD_COLUMN           1
#endif   /*DRV_KBD_25_KEYS,FPGA*/


/*keypad*/
typedef enum {
      kbd_onekey_press=0,
      kbd_onekey_release,
#ifdef TWO_KEY_ENABLE
      kbd_twokey_press,
      kbd_twokey_release,
#endif   /*TWO_KEY_ENABLE*/
      kbd_onekey_longpress,
      kbd_onekey_repeated,
      kbd_onekey_fullpress,
      kbd_twokey_detection_enable,
      kbd_threekey_detection_enable,
      kbd_multikey_detection_disable
} kbd_event;

#define  kbd_buffer_size         32


typedef struct
{
   kbd_event   Keyevent;
#ifdef TWO_KEY_ENABLE
   kal_uint8   Keydata[2];
#else /*!TWO_KEY_ENABLE*/
   kal_uint8   Keydata[1];
#endif   /*TWO_KEY_ENABLE*/
#if defined(__TC01__)
   kal_uint32  keytimestamp;
#endif
} kbd_data;


typedef struct
{
   kbd_data       kbd_data_buffer[kbd_buffer_size];
   kal_uint8      kbd_data_buffer_rindex;
   kal_uint8      kbd_data_buffer_windex;
} kbd_buffer_struct;

/*Customizae Keypad*/
typedef struct {
	/*keypad mapping*/
#if defined(DRV_KBD_DRVTOOL_EXTEND_72_KEYS)
   kal_uint8 keypad[72];//kbd_allkeys+KBD_COLUMN*2]; //reserve one GND row and GPO row.   
#else
   kal_uint8 keypad[kbd_allkeys];
#endif//#if defined(DRV_KBD_DRVTOOL_EXTEND_72_KEYS)
#if defined(__EXTEND_QWERTY_KEYPAD__)
   kal_uint16 kbd_extend_row_GPO;  //extend row use which GPO
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__)
	/*power on period*/
   kal_uint32 Custom_Keypress_Period;
   /*power key  position*/
   kal_uint8 powerkey_position;   
} keypad_struct;

typedef struct {  
   const keypad_struct * (*keypad_Get_Data)(void);
   #ifdef __KBD_2STEP_KEY_SUPPORT__   
   kal_bool (*keypad_is_fullpress)(kal_uint8 key);
   kal_bool (*keypad_check_fullpress)(void);   
   #endif 
}keypad_customize_function_struct; 

/*keypad*/
typedef enum {
      low_key=0,
#if defined(DRV_KBD_32KEYS_ABOVE)
      medium_key,
#elif defined(DRV_KBD_48KEYS_ABOVE)
      medium_key,
      medium_key1,
#elif defined(DRV_KBD_64KEYS_ABOVE)
      medium_key,
      medium_key1,
      medium_key2,
#endif      
      high_key

} kbd_type;


 
/*
extern void Kbd_Init(void);
extern void keypad_customize_init(void);

kal_bool kbd_key_det_mode_switch(kbd_key_det_mode mode);
 kal_bool kbd_IsKeyButtonSupported(kal_uint8 key);

extern kal_bool PowerKey_Pressed(void);
extern kal_bool kbd_is_mutiple_key(kal_uint8 key);
extern kal_bool kbd_IsKeyPressed(kal_uint8 key);

extern kal_uint32 Kbd_GetKeyEventCount(void);
extern kal_bool Kbd_GetKeyData(kbd_data *keydata);
extern kal_bool Kbd_PeekBuffer(kbd_data *keydata, kal_bool specify_read, 
											kal_uint32 read_pointer,kal_uint32* current_read_pointer);
extern kal_uint32 kbd_PutKeyData(kal_uint8 key);

extern void Kbd_SetLongPressTime(kal_uint32 ticks);
extern void Kbd_SetRepeatTime(kal_uint32 ticks);
*/

#endif

