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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * audcoeff.c
 *
 * Project:
 * --------
 *   MAUI Project
 *
 * Description:
 * ------------
 *   Default FIR Coefficients Table
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
 *==============================================================================
 *******************************************************************************/
#include "l1audio.h"
#include "audcoeff_default.h"
#include "AudCoeff.h"
#include "audio_nvram_def.h"

#include "device.h"

const unsigned char  L1SP_MICROPHONE1  = L1SP_LNA_0;
const unsigned char  L1SP_MICROPHONE2  = L1SP_LNA_1;

const unsigned char  L1SP_SPEAKER1     = L1SP_BUFFER_0;
const unsigned char  L1SP_SPEAKER2     = L1SP_BUFFER_ST;
const unsigned char  L1SP_LOUD_SPEAKER = L1SP_BUFFER_ST|L1SP_BUFFER_EXT;

const signed short Speech_Input_FIR_Coeff[6][45] = SPEECH_INPUT_FIR_COEFF_DEFAULT;
const signed short Speech_Output_FIR_Coeff[6][45] = SPEECH_OUTPUT_FIR_COEFF_DEFAULT;

#ifdef __AMRWB_LINK_SUPPORT__
const signed short WB_Speech_Input_FIR_Coeff[6][90] = WB_SPEECH_INPUT_FIR_COEFF_DEFAULT;
const signed short WB_Speech_Output_FIR_Coeff[6][90] = WB_SPEECH_OUTPUT_FIR_COEFF_DEFAULT;
#endif

/*
const unsigned short Ext_op_on_delay   = 0;     // count in frames, 1 frame = 4.615ms 
const unsigned short Ext_op_off_delay  = 0;     // count in frames, 1 frame = 4.615ms 
*/

const unsigned short   DG_DL_Speech    = 0x1000;
const unsigned short   DG_Microphone   = 0x1400;
const unsigned short   DG_DAF          = 32767;
const unsigned short   DG_MIDI         = 304;
const unsigned short   DG_IMY          = 3072;
const unsigned short   DG_IMY_NOTE     = 512;
const unsigned short   DG_SMF_NOTE     = 96;
const unsigned short   DG_JTS_NOTE     = 2048;


/*
 * Loudness Configuration Parameter
 * Refer to audcoeff_default.h
 */
/*
const unsigned char Loudness_Ringtone_Mode = DEFAULT_LOUDNESS_RINGTONE_MODE;
const unsigned char Loudness_NonRingtone_Mode = DEFAULT_LOUDNESS_NON_RINGTONE_MODE;
*/

/*
 * The Bluetooth DAI Hardware COnfiguration Parameter
 * Refer to audcoeff_default.h
 */
 /*
const unsigned char Bluetooth_Sync_Type = DEFAULT_BLUETOOTH_SYNC_TYPE;
const unsigned char Bluetooth_Sync_Length = DEFAULT_BLUETOOTH_SYNC_LENGTH;
*/

/*
 * The Digital Microphone Hardware COnfiguration Parameter
 * Refer to audcoeff_default.h
 */
/* 
const unsigned char Digital_Mic1_Phase = DEFAULT_DIGITAL_MIC_CHANNEL1_PHASE;
const unsigned char Digital_Mic2_Phase = DEFAULT_DIGITAL_MIC_CHANNEL2_PHASE;
const unsigned char Digital_Mic_Clock_Selection = DEFAULT_DIGITAL_MIC_CLOCK_SELECTION;
*/

/*
 * 3D Surround Loudspeaker Mode Customization Parameter.
 * Details about these three variables are illustrated in Audio Post-Processing Interface doc.
 */
/*
#if defined(__BES_SURROUND_LSPK__) || defined(__BES_SURROUND_EARP__)
const int D_Distance = DEFAULT_D_DISTANCE;
const int D_Loudspeaker = DEFAULT_D_LOUDSPEAKER;
const int SurroundLevelLoudspeaker = DEFAULT_SURROUNDLEVELLOUDSPEAKER;
#endif
*/


#if !defined(__FUE__)
/*
*   Function
*      custom_cfg_audio_ec_range
*   DESCRIPTION
*      The function is used to customize the audio volume level for echo cancellation.
*     And it will be used by media task.
*   PARAMETERS
* 	   min_vol   min volume level
* 	   max_vol   max volume level
*   RETURNS
*      void
*   GLOBALS AFFECTED
*/
void custom_cfg_audio_ec_range
(
 kal_uint8 *min_vol, /* min volume level */
 kal_uint8 *max_vol /* max volume level */
 )
{
   ASSERT(min_vol!=NULL && max_vol!=NULL);

   *min_vol=1;
   *max_vol=6;
}


kal_uint8 custom_cfg_hw_aud_output_path(  kal_uint8 speaker_id )
{
   /*----------------------------------------------------------------*/
   /* Local Variables                                                */
   /*----------------------------------------------------------------*/
   kal_uint8 audio_device_out = L1SP_SPEAKER1;
   /*----------------------------------------------------------------*/
   /* Code Body                                                      */
   /*----------------------------------------------------------------*/
   switch(speaker_id)
   {
   case AUDIO_DEVICE_SPEAKER/*AUDIO_OUT_SPEAKER1*/:
      audio_device_out = L1SP_SPEAKER1;
      break;
   case AUDIO_DEVICE_SPEAKER2/*AUDIO_OUT_SPEAKER2*/:
      audio_device_out = L1SP_SPEAKER2;
      break;
   case AUDIO_DEVICE_LOUDSPEAKER/*AUDIO_OUT_LOUDSPEAKER*/:
      audio_device_out = L1SP_LOUD_SPEAKER;
      break;
   case AUDIO_DEVICE_SPEAKER_BOTH: /* AUDIO_OUT_SPEAKER1 and AUDIO_OUT_SPEAKER2 */
      audio_device_out = (L1SP_LOUD_SPEAKER| L1SP_SPEAKER2);
      break;
   case AUDIO_DEVICE_BUZZER/*AUDIO_OUT_BUZZER*/:
   case AUDIO_DEVICE_GMI/*AUDIO_OUT_GMI*/:
      audio_device_out = L1SP_LOUD_SPEAKER;
      break;
   default:
      break;
   }

   return audio_device_out;
}



kal_uint8 custom_cfg_hw_aud_input_path(  kal_uint8 mic_id )
{
   kal_uint8 mic_device = 0;

   switch(mic_id)
   {
   case AUDIO_DEVICE_MIC1:
      mic_device = 0;
      break;
   case AUDIO_DEVICE_MIC2:
      mic_device = 1;
      break;
   case AUDIO_DEVICE_FMRR:
      mic_device = 3;  /*L1SP_LNA_FMRR*/
   default:
      break;
   }

   return mic_device;
}
#endif //!defined(__FUE__)

