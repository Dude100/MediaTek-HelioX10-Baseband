/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * dummy_audio.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Provide APIs when speech functionality is disabled 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#include "kal_public_api.h"
#include "syscomp_config.h"
#include "l1audio.h"


/************************************/
/* Tasl Creation (temp solution)    */
/* Should modify task_config.h      */
/************************************/

void L1Audio_HISR( void )
{
}

kal_bool l1sp_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct l1sp_handler_info =
   {
      NULL,          /* task entry function */
      NULL,          /* task initialization function */
      NULL,          /* task configuration function */
      NULL,          /* task reset handler */
      NULL           /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&l1sp_handler_info;

   return KAL_TRUE;
}

kal_bool l1audio_sph_srv_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct l1audio_sph_srv_handler_info =
   {
      NULL,
      NULL,
      NULL,
      NULL,
      NULL,
   };
   *handle = (comptask_handler_struct *)&l1audio_sph_srv_handler_info;

   return KAL_TRUE;
}

kal_bool audl_create(comptask_handler_struct **handle)
{
   static const comptask_handler_struct audl_handler_info =
   {
      NULL,          /* task entry function */
      NULL,          /* task initialization function */
      NULL,          /* task configuration function */
      NULL,          /* task reset handler */
      NULL           /* task termination handler */
   };

   *handle = (comptask_handler_struct *)&audl_handler_info;
   return KAL_TRUE;
}

/************************************/
/* Audio Manager                    */
/************************************/

#ifndef uint16
typedef kal_uint16   uint16;
typedef kal_int16    int16;
typedef kal_uint32   uint32;
typedef kal_int32    int32;
typedef kal_uint8    uint8;
typedef kal_int8     int8;
typedef kal_bool     bool;
#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)
#endif

bool AM_IsSpeechOn( void )
{
   return false;
}

kal_uint32 AM_Get2GResyncThreshold( void )
{
   return 1083;
}

void AM_SetLoopBackTest(bool enable)
{
   (void) enable;
}

bool AM_AudioManager( bool handover, uint16 speech_mode, int8 sub_channel )
{
   (void) handover;
   (void) speech_mode;
   (void) sub_channel;
   
   return false;
}

/************************************/
/* Speech                           */
/************************************/

void L1SP_Set_DAI_Mode( uint8 mode )
{
   (void) mode;
}

void L1SP_SetAfeLoopback( bool enable )
{
   (void) enable;
}

void L1Audio_EnterDedicatedMode( void )
{
}

void L1Audio_LeaveDedicatedMode( void )
{
}

void L1SP_D2C_LISR( uint16 itype )
{
   (void) itype;
}

void L1SP_TCH_Notify( bool bOn )
{
   (void) bOn;
}

void L1SP_SetOutputVolume( kal_uint8 volume1, kal_int8 digital_gain_index )
{
   (void) volume1;
   (void) digital_gain_index;
}

void L1SP_SetMicrophoneVolume( kal_uint8 mic_volume )
{
   (void) mic_volume;
}

void L1SP_Speech_On( uint8 RAT_Mode )
{
   (void) RAT_Mode;
}

void L1SP_Speech_Off( void )
{
}

void L1SP_SetSidetoneVolume( uint8 sidetone )
{
   (void) sidetone;
}

/************************************/
/* Speech 3G                        */
/************************************/

typedef struct
{
   kal_uint8 RSSI;
   kal_uint8 RSCP;
   kal_uint8 ECIO;
   kal_uint8 HHO_SHO;

   /* Used by UMAC */ 
   /* Modified CRC = CRC |(S value decision) 
        S value decision=1 => S value < S Threshold. this frame is not reliable
        S value decision =0 => S value > S Threshold. This frame is reliable

        Modified CRC =0, speech good, CRC=0, S value decision =0 
        Modified CRC=1, CRC =1 or S value decision=1

        crc_result value meaning : 
        0 : Modified CRC =  0
        1 : Modified CRC = 1, CRC = 0
        2 : Modified CRC = 1, CRC = 1
        */
   kal_uint8 crc_result[3]; /* For Class A/B/C */
   kal_uint32 s_value[3];  /* For Class A/B/C */

   kal_int16      tpc_SIR_lta;            // For recording into speech VM
   kal_int16      dpdch_SIR_lta;          // For recording into speech VM
   kal_int16      TFCI_max_corr;          // For recording into speech VM                                              
}L1_info_struct;

kal_bool CS_NeedSpeechExtraLog( void )
{
   return KAL_FALSE;
}

void SP3G_UpdateL1AInFo( kal_uint8 bitmap, kal_uint8 value )
{
   (void) bitmap;
   (void) value;
}

void SP3G_Log_L1_Info(uint32 CFN, L1_info_struct *p_L1_Info)
{
   (void) CFN;
   (void) p_L1_Info;
}

void SP3G_Closed_Confirm( void )
{
}

void SP3G_Rab_Est( uint32 rab_id, kal_uint8 default_speech_codec )
{
   (void) rab_id;
   (void) default_speech_codec;
}

void SP3G_Rab_Deest( void )
{
}

void SP3GHSPA_DL_SetMaxCsDelay(kal_uint8 max_cs_delay)
{
   (void) max_cs_delay;
}

void SP3GHSPA_DL_PutSpeechFrame(kal_uint32 CFN, kal_uint8 frame_type, kal_bool crc_status, kal_uint8 *subflow)
{
   (void) CFN;
   (void) frame_type;
   (void) crc_status;
   (void) subflow;
}

void SP3GHSPA_UL_GetSpeechFrame(kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{
   (void) frame_type;
   (void) rab_byte_array;
   (void) len;
}

void SP3G_DL_PutSpeechFrame(uint32 CFN, uint8 sub_flow_id, uint8 frame_type, bool crc_status, uint8 *subflow)
{
   (void) CFN;
   (void) sub_flow_id;
   (void) frame_type;
   (void) crc_status;
   (void) subflow;
}

void SP3G_UL_SetFrameType(uint8 amr_frame_type)
{
   (void) amr_frame_type;
}

void SP3G_UL_GetSpeechFrame(kal_uint16*frame_index, kal_uint8 *frame_type, kal_uint8 *rab_byte_array, kal_uint8 *len)
{
   (void) frame_index;
   (void) frame_type;
   (void) rab_byte_array;
   (void) len;
}

/************************************/
/* Misc.                            */
/************************************/

void TONE_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   (void) volume1;
   (void) digital_gain_index;
}

void KT_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   (void) volume1;
   (void) digital_gain_index;
}

void Media_SetOutputVolume( uint8 volume1, int8 digital_gain_index )
{
   (void) volume1;
   (void) digital_gain_index;
}

void L1Audio_ResetDevice(void)
{
}

// Temp solution here.
// Formal solution: modify TrcMod.c
unsigned char L1Audio_Trace_Filter[5] = { 0x1, 0x3, 0x0, 0x0, 0x0 };

void Set_L1Audio_Filter(unsigned char *setting)
{
   int i;

   for(i=0; i<5; i++)
      L1Audio_Trace_Filter[i] = setting[i];
}


void SP_L4C_SetEvent(L1SP_L4C_Event event, L1SP_L4C_Event_Mode mode)
{
}
