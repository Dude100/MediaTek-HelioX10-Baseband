/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 * common_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * The common definition used in audio module.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#if defined(MT6270A) || defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
   #include "../../v2/inc/l1audio_def.h"
#endif

#ifndef __COMMON_DEF_H
#define __COMMON_DEF_H

#include "kal_public_api.h"
#include "reg_base.h"

/* -------------------------------------------------------------------------- */
/* Data Type Definition                                                       */
/* -------------------------------------------------------------------------- */
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

/* -------------------------------------------------------------------------- */
/* Internal definition of audio module                                        */
/* -------------------------------------------------------------------------- */

#if defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
#define AUDIO_DELAY_OFF
#endif
#if defined(MT6575) || defined(MT6573) || defined(MT6577)
 #define AUDIO_CLOSE_DELAY 0 
#else
  #define AUDIO_CLOSE_DELAY 500 //500 ms, unit is 10ms
#endif

#define BESLOUDNESS_I2S_MODE_LOUDSPEAKER 0x1E
#define BESLOUDNESS_I2S_MODE_EARPHONE    0x1F
 

// 20100602 KH add for different driver
#if defined(MT6276) || defined(MT6573) || defined(MT6575) || defined(MT6577)
   #define __DSP_CHIP_DUALMAC__
#else
   #define __DSP_CHIP_FD216__ 
#endif

//change mcu and dsp share memory to internal memory [chip after MT6256_S01]
#if defined(MT6256_S01)
#define _DSP_INTERSHAREMEM_EN_ 
#define L1AUDIO_IDMA_ALL_ADDRESS_MODE
#endif

//Video playback MPL interface
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
#define __AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__  
#endif

#define TDDNC_SUPPORT (defined(MT6253) || defined(MT6251) || defined(MT6252) || defined(MT6256) || defined(MT6255))


/* -------------------------------------------------------------------------- */
/* Hardware Definition                                                        */
/* -------------------------------------------------------------------------- */
//#define IS_EV_BOARD  (defined(MT6235_EVB) || defined(MT6253_EVB) || defined(MT6236_EVB) || defined(MT6256_S00_EVB) || defined(MT6251_EVB) || defined(MT6253E_EVB) || defined(MT6253L_EVB)|| defined(MT6252_EVB) || defined(MT6252H_EVB) )

/* -------------------------------------------------------------------------- */
/* Assertion check                                                            */
/* -------------------------------------------------------------------------- */
#define ASSERT_REBOOT(st)  EXT_ASSERT(st,0,0,0)

#endif //__COMMON_DEF_H
