/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   dtmf_exp.h
 *
 * Project:
 * --------
 *
 *
 * Description:
 * ------------
 *   The DTMF Tone Generator include file
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
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _DTMF_EXP_H
#define _DTMF_EXP_H

/*
********************************************************************************
*                         INCLUDE FILES
********************************************************************************
*/
 
/*
********************************************************************************
*                         DEFINITION OF DATA TYPES
********************************************************************************
*/

typedef enum {
   DTMFKEY_0 = 0,
   DTMFKEY_1,
   DTMFKEY_2,
   DTMFKEY_3,
   DTMFKEY_4,
   DTMFKEY_5,
   DTMFKEY_6,
   DTMFKEY_7,
   DTMFKEY_8,
   DTMFKEY_9,
   DTMFKEY_STAR,
   DTMFKEY_HASH,
   DTMFKEY_A,
   DTMFKEY_B,
   DTMFKEY_C,
   DTMFKEY_D,
   DTMFKEY_Ext0,
   DTMFKEY_Ext1,
   DTMFKEY_Ext2,
   DTMFKEY_Ext3,
   DTMFKEY_Ext4,
   DTMFKEY_Ext5,
   DTMFKEY_Ext6,
   DTMFKEY_Ext7
} DTMF_KEY;

typedef enum {
   DTMF_8K = 0,
   DTMF_11K,
   DTMF_12K,
   DTMF_16K,
   DTMF_22K,
   DTMF_24K,
   DTMF_32K,
   DTMF_44K,
   DTMF_48K
} DTMF_SR;

typedef enum{
   DTMF_MONO = 0,
   DTMF_STEREO
}DTMF_CHANNEL;

typedef enum {
   DTMF_SUCCESS = 0,
   DTMF_FAIL,
   DTMF_DONE
} DTMF_STATUS;

typedef enum{
   DTMF_CONTINUOUS = 0,
   DTMF_FIXPERIOD
}DTMF_MODE;

/*****************************************************************************
 * STRUCTURE
 *  DTMF_HANDLE
 *
 * DESCRIPTION
 *  DTMF Generator handler
 *
 *
********************************************************************************
*                         DECLARATION OF PROTOTYPES
********************************************************************************
*/
 
/*****************************************************************************
 * FUNCTION
 *  DTMF_GetBufferSize
 *
 * DESCRIPTION
 *  This function gets the buffers size for DTMF Generator.
 *
 * PARAMETERS
 *  InterBufSize     Internal buffer size
 *  PcmBufSize       Output PCM buffer size 
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_GetBufferSize( unsigned int *InterBufSize, 
                                unsigned int *PcmBufSize,
                                DTMF_SR samplerate, 
                                DTMF_CHANNEL channel
                                );

/*****************************************************************************
 * FUNCTION
 *  DTMF_Init
 *
 * DESCRIPTION
 *  This function initializes DTMF Generator.
 *
 * PARAMETERS
 *  InterBuf     Internal buffer 
 *  channel      Output channels, DTMF_MONO --> mono, DTMF_STEREO --> stereo
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
void* DTMF_Init( void *InterBuf, 
                 DTMF_MODE mode,
                 DTMF_SR samplerate,
                 DTMF_CHANNEL channel
                 );

/*****************************************************************************
 * FUNCTION
 *  DTMF_Gen
 *
 * DESCRIPTION
 *  This function generates PCM data of DTMF tones.
 *
 * PARAMETERS
 *  PcmBuf       Output PCM buffer 
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_Gen( void *hdl, 
                      void *PcmBuf
                      );

/*****************************************************************************
 * FUNCTION
 *  DTMF_Tone
 *
 * DESCRIPTION
 *  This function is used to turn on/off DTMF tones
 *
 * PARAMETERS
 *  key              Specify a key
 *  dtmfswitch       1 --> press the key, 0 --> release the key 
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_Tone( void *hdl, 
                       DTMF_KEY key, 
                       int dtmfswitch
                       );

/*****************************************************************************
 * FUNCTION
 *  DTMF_SetDuration
 *
 * DESCRIPTION
 *  This function specifies the DTMF duration of each tone on FIXDURATION mode.
 *
 * PARAMETERS
 *  duration     To specify the frame counts
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_SetDuration( void *hdl, 
                              unsigned int duration
                              );

/*****************************************************************************
 * FUNCTION
 *  DTMF_GetKey
 *
 * DESCRIPTION
 *  This function is used to get the frequency of specified key.
 *
 * PARAMETERS
 *  key         Specify a key
 *  freq1       Frequency of the first tone
 *  freq2       Frequency of the second tone
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_GetKey( void *hdl, 
                         DTMF_KEY key, 
                         int *freq1, 
                         int *freq2
                         );

/*****************************************************************************
 * FUNCTION
 *  DTMF_SetKey
 *
 * DESCRIPTION
 *  This function is used to define the frequency of DTMF tone.
 *
 * PARAMETERS
 *  key         Specify a key
 *  freq1       Frequency of the first tone
 *  freq2       Frequency of the second tone
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_SetKey( void *hdl, 
                         DTMF_KEY key, 
                         int freq1, 
                         int freq2
                         );

/*****************************************************************************
 * FUNCTION
 *  DTMF_SetGain
 *
 * DESCRIPTION
 *  This function is used to set the digital gain of each DTMF tone.
 *
 * PARAMETERS
 *  gain       Digital gain, ranges from 0~0x3FFF
 *
 * RETURNS
 *  DTMF_Status
 *****************************************************************************
 */
DTMF_STATUS DTMF_SetGain( void *hdl, 
                          int gain
                          );

#endif
