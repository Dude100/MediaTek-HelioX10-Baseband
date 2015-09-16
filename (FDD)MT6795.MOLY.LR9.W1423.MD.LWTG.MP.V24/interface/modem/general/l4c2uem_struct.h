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
 *   l4c2uem_struct.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : l4c2uem_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _L4C2UEM_STRUCT_H
#define _L4C2UEM_STRUCT_H

#include "ps_public_struct.h"
#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
#include "custom_hw_default.h"
#endif

#define MAX_MELODY_FILE_NAME 50

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
} l4cuem_startup_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_startup_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type;
    kal_uint8 data1;
    kal_uint8 data2;
    kal_uint8 data3;
} l4cuem_set_profile_req_struct;

typedef struct {

   kal_uint8 mode;
   kal_uint8 melody[7];
   kal_uint8 keytone[7];
   kal_uint8 speech[7];
   kal_uint8 mic;
   kal_uint8 sidetone;
   
} l4cuem_audio_profile_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8	mode;
	kal_uint8	melody[7];
	kal_uint8	keytone[7];
	kal_uint8	speech[7];
	kal_uint8	mic;
	kal_uint8	sidetone;

} l4cuem_set_audio_profile_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_set_profile_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_set_audio_profile_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_set_audio_param_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 type;
    kal_uint8 index;
    kal_uint16 length;
    kal_uint8 imelody[300];
} l4cuem_store_imelody_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_store_imelody_cnf_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 index;
} l4cuem_delete_imelody_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_delete_imelody_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8  src_id;
   kal_uint16  file_name[MAX_MELODY_FILE_NAME];
   kal_uint8   play_style;
   kal_uint16  identifier;
} 
l4cuem_audio_play_by_name_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint16  file_name[MAX_MELODY_FILE_NAME];
} 
l4cuem_audio_stop_by_name_req_struct;

typedef struct {
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8  src_id;
    kal_uint8   result;
} 
l4cuem_audio_play_by_name_cnf_struct;

typedef struct {
   kal_uint8 ref_count;
   kal_uint16 msg_len;
   kal_uint8  src_id;
   kal_uint8   result;
} 
l4cuem_audio_stop_by_name_cnf_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;

	kal_uint32 PWM1_freq_Level_Info[5];
	kal_uint32 PWM1_duty_Level_Info[5]; 
	kal_uint32 PWM2_freq_Level_Info[5]; 
	kal_uint32 PWM2_duty_Level_Info[5];
	kal_uint32 PWM3_freq_Level_Info[5]; 
	kal_uint32 PWM3_duty_Level_Info[5]; 

	kal_uint8   MainLCD_Contrast_Level_Info[15];
	kal_uint8   MainLCD_Bias_Level_Info[5];
	kal_uint8   MainLCD_Linerate_Level_Info[5];
	kal_uint8   MainLCD_Temp_Level_Info[5];
   
	kal_uint8   SubLCD_Contrast_Level_Info[15];
	kal_uint8   SubLCD_Bias_Level_Info[5];
	kal_uint8   SubLCD_Linerate_Level_Info[5];
	kal_uint8   SubLCD_Temp_Level_Info[5];

	kal_uint32   Battery_Level_Info[10];
#ifdef __MULTI_LEVEL_BACKLIGHT_SUPPORT__
        kal_uint32 bl_PWM_freq_Level_Info[PWM_MAX_BACKLIGHT_LEVEL]; 
	kal_uint32 bl_PWM_duty_Level_Info[PWM_MAX_BACKLIGHT_LEVEL]; 
#endif
} l4cuem_set_hw_level_req_struct;

typedef struct
{
    kal_uint8 ref_count;
    kal_uint16 msg_len;
    kal_uint8 src_id;
    kal_uint8 response;
    kal_uint8 cause;
} l4cuem_set_hw_level_cnf_struct;


#endif 


