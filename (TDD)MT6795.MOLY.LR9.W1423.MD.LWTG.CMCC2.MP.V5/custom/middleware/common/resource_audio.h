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
 * RESOURCE_AUDIO.H
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for audio resource database.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MMI_AUDIO_H
#define _MMI_AUDIO_H

//#include "MMI_features.h"

//#include "custom_user_profiles_defs.h"

#include "kal_general_types.h"

typedef enum
{
   MIN_TONE_ID = 0,                         
   TONE_DTMF_0 = MIN_TONE_ID,            	/* 0 */
   TONE_DTMF_1,            					/* 1 */
   TONE_DTMF_2,            					/* 2 */
   TONE_DTMF_3,            					/* 3 */
   TONE_DTMF_4,            					/* 4 */
   TONE_DTMF_5,            					/* 5 */
   TONE_DTMF_6,            					/* 6 */
   TONE_DTMF_7,            					/* 7 */
   TONE_DTMF_8,            					/* 8 */
   TONE_DTMF_9,								/* 9 */
   TONE_KEY_STAR,          					/* 10 */
   TONE_KEY_HASH,          					/* 11 */
   TONE_KEY_NORMAL,							/* 12 */
   TONE_KEY_VOL_UP = TONE_KEY_NORMAL,     /* 12 */   
   TONE_KEY_VOL_DOWN = TONE_KEY_NORMAL,  /* 12 */   
   TONE_KEY_UP = TONE_KEY_NORMAL,         /* 12 */   
   TONE_KEY_DOWN = TONE_KEY_NORMAL,      /* 12 */   
   TONE_KEY_LEFT = TONE_KEY_NORMAL,       /* 12 */   
   TONE_KEY_RIGHT = TONE_KEY_NORMAL,     /* 12 */    
   TONE_KEY_MENU = TONE_KEY_NORMAL,      /* 12 */    
   TONE_KEY_FUNCTION = TONE_KEY_NORMAL,  /* 12 */    
   TONE_KEY_SK_LEFT = TONE_KEY_NORMAL,   /* 12 */    
   TONE_KEY_SK_RIGHT = TONE_KEY_NORMAL,  /* 12 */    
   TONE_KEY_SEND = TONE_KEY_NORMAL,      /* 12 */    
   TONE_KEY_END = TONE_KEY_NORMAL,       /* 12 */    
   TONE_KEY_POWER = TONE_KEY_NORMAL,     /* 12 */   

   TONE_KEY_CLICK,						/* 13 */

   TONE_CALL_CONNECT,					/* 14 */
   TONE_MT_SMS_IN_CALL,					/* 15 */
   TONE_CALL_TIME_REMINDER,				/* 16 */

   TONE_DIAL_CALL_GSM,    				/* 17 */
   TONE_DIAL_CALL_PCS,     				/* 18 */
   TONE_BUSY_CALL_GSM,    				/* 19 */
   TONE_BUSY_CALL_PCS,    				/* 20 */
   TONE_CONGESTION_GSM,  				/* 21 */ 
   TONE_CONGESTION_PCS,   				/* 22 */
   TONE_RADIO_PATH,       				/* 23 */
   TONE_RADIO_NA,         				/* 24 */
   TONE_ERROR_INFO,        				/* 25 */
   TONE_NUM_UNOBTAIN,     				/* 26 */
   TONE_AUTH_ERROR,       				/* 27 */
   TONE_CALL_WAITING,      				/* 28 */
   TONE_RINGING_CALL_GSM, 				/* 29 */
   TONE_RINGING_CALL_PCS, 				/* 30 */
   TONE_POSITIVE_ACK,      				/* 31 */
   TONE_NEGATIVE_ACK,     				/* 32 */   
													
   TONE_DIAL_CALL_GSM_STK,				/* 33 */
   TONE_DIAL_CALL_PCS_STK,				/* 34 */
   TONE_BUSY_CALL_GSM_STK,				/* 35 */
   TONE_BUSY_CALL_PCS_STK,				/* 36 */
   TONE_CONGESTION_GSM_STK,				/* 37 */
   TONE_CONGESTION_PCS_STK,				/* 38 */
   TONE_RADIO_PATH_STK,   				/* 39 */
   TONE_RADIO_NA_STK,     				/* 40 */
   TONE_ERROR_INFO_STK,   			    /* 41 */
   TONE_NUM_UNOBTAIN_STK, 				/* 42 */
   TONE_AUTH_ERROR_STK,   				/* 43 */
   TONE_CALL_WAITING_STK, 				/* 44 */
   TONE_RINGING_CALL_GSM_STK,			/* 45 */
   TONE_RINGING_CALL_PCS_STK,			/* 46 */
   TONE_POSITIVE_ACK_STK, 				/* 47 */
   TONE_NEGATIVE_ACK_STK, 				/* 48 */
			
			
   TONE_WARNING1,						/* 49 */
   TONE_WARNING2,						/* 50 */
   TONE_ERROR1,							/* 51 */
   TONE_ERROR2,							/* 52 */
   TONE_GENERAL_BEEP,					/* 53 */
   TONE_BATTERY_LOW,					/* 54 */
   TONE_BATTERY_WARNING,				/* 55 */
   TONE_AUX_IND,						/* 56 */
   TONE_DATA_CALL,						/* 57 */
#ifdef __OP01_FWPBW__
   TONE_CONTINUE_SOUND,		    		/* 58 */
#endif
   NUM_RESOURCE_TONES,

   MAX_TONE_ID = 80
}audio_id_enum;

/*
** Define the tone format: Keypad, DTMF, Call Tone.
*/
typedef struct {
   kal_uint16   freq1;            /* First frequency                                    */
   kal_uint16   freq2;            /* Second frequency                                   */
   kal_uint16   on_duration;      /* Tone on duation, in ms unit, 0 for continuous tone */
   kal_uint16   off_duration;     /* Tone off duation, in ms unit, 0 for end of playing */
   kal_int8     next_operation;   /* Index of the next tone                             */
} device_tones_struct;

typedef struct {
   const unsigned char *data;
   kal_uint32  len;
   kal_int32 format;
}
audio_resource_struct;

typedef struct {
	short start;
	short end;
}
start_end_t;
       
extern device_tones_struct** resource_tones;

#endif // _MMI_AUDIO_H
