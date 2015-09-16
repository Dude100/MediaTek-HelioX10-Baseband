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
 * audio_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  This file defines all the audio registers used in audio module.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef __AUDIO_DEF_H
#define __AUDIO_DEF_H

#include "kal_public_api.h"
#include "audio_dsp_d2c_def.h"
#include "common_def.h"

#if defined(MT6280)
   #include "dpram_6280.h"
#endif

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Ring buffer handling
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
/*
   Example: define a ring buffer of 8 integers (size must be a power of two)
   , put the value 3 and get it again:
   
   RINGBUFFER_T(int,8) myBuffer;
   RB_PUT( myBuffer, 3 );

   int value;
   RB_GET( myBuffer, value );
*/


#ifndef RINGBUFFER_T
#define RINGBUFFER_T(elemtype,size) \
   struct \
   { \
      volatile uint32 write; /* must be unsigned */ \
      volatile uint32 read;  /* must be unsigned */ \
      elemtype volatile queue[size]; \
   }

#define RB_SIZE( rb ) \
   ( sizeof( rb.queue ) / sizeof( *rb.queue ) )

#define RB_MASK( rb ) \
   ( RB_SIZE( rb ) - 1 )

#define RB_INIT( rb ) \
   ( rb.read = rb.write = 0 )

#define RB_COUNT( rb ) \
   ( rb.write - rb.read )

#define RB_FULL( rb ) \
   ( RB_COUNT( rb ) >= RB_SIZE( rb ) )

#define RB_EMPTY( rb ) \
   ( rb.write == rb.read )

#define RB_PUT( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   rb.queue[ rb.write & RB_MASK( rb ) ] = value; \
   ++rb.write; \
}

#define RB_GET( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
   ++rb.read; \
}

#define RB_PEEK( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   value = rb.queue[ rb.read & RB_MASK( rb ) ]; \
}

#define RB_PEEK_THROUGH( rb, idx, value ) \
{ \
   ASSERT( (rb.read+idx) < rb.write ); \
   value = rb.queue[ (rb.read+idx) & RB_MASK( rb ) ]; \
}

#define RB_CONSUME( rb ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   ++rb.read; \
}

#define RB_UNPUT( rb, value ) \
{ \
   ASSERT( !RB_EMPTY( rb ) ); \
   --rb.write; \
   value = rb.queue[ rb.write & RB_MASK( rb ) ]; \
}

#define RB_UNGET( rb, value ) \
{ \
   ASSERT( !RB_FULL( rb ) ); \
   --rb.read; \
   rb.queue[ rb.read & RB_MASK( rb ) ] = value; \
}

#endif /* RINGBUFFER_T */


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       Feature Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  Definitions
//=============================================================================================
#define DSP_ENA_VM_INTERRUPT     0x0010   /* DSP to CPU interrupt for Voice Memo (SHARE_D2MCON) */
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020   /* DSP to CPU interrupt for A/V Sync (SHARE_D2MCON) */
#define DP_AAC_CTRL_ASP          0x0001
#define DP_PCM_R_DIS             0x0002

//=============================================================================================
//                  Options
//=============================================================================================


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       AUDIO SHERIF BASE ADDRESS
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/
   #define DP_AUDIO_CTRL_base(a)              (DPRAM2_base(DP2_AUDIO_CTRL_FIELD_BASE)        +(a))
   #define DP_AV_SYNC_CTRL_base(a)            (DPRAM2_base(A2V_BASE)                         +(a))
   #define DP_WAV_CTRL_base(a)                (DPRAM2_base(DP2_WAV_CTRL_FIELD_BASE)          +(a))
   #define DP_WT_CTRL_base(a)                 (DPRAM2_base(DP2_WT_CTRL_FIELD_BASE)           +(a))
   #define DP_DAF_CTRL_base(a)                (DPRAM2_base(DP2_MP3_CTRL_FIELD_BASE)          +(a))
   #define DP_AUDIO_PP_CTRL_base(a)           (DPRAM2_base(DP2_AUDIO_PP_CTRL_BASE)           +(a))
   #define DP_EXTRA_APPLICATION_base(a)       (DPRAM2_base(DP2_EXTRA_APPLICATION_FILED_BASE) +(a))
   #define DP_DYNAMIC_LOAD_base(a)            (DPRAM2_base(DP2_Dynamic_Load_field_BASE)      +(a))

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                        AUDIO DSP Decoder Control Sherifs
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  AUDIO DSP Playback Control
//=============================================================================================
   #define DP_ASP_TYPE                        DP_AUDIO_CTRL_base(0)
   #define DP_ASP_FS                          DP_AUDIO_CTRL_base(1)
   #define DP_ASP_DEL_W                       DP_AUDIO_CTRL_base(2)
   #define DP_ASP_DEL_M                       DP_AUDIO_CTRL_base(4)

//=============================================================================================
//                  PCM DSP Playback Control
//=============================================================================================
   #define DSP_PCM_CTRL                       DP_WAV_CTRL_base(0)
   #define DSP_PCM_W                          DP_WAV_CTRL_base(1)
   #define DSP_PCM_R                          DP_WAV_CTRL_base(2)
   #define DSP_PCM_MS                         DP_WAV_CTRL_base(3)


/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       AUDIO DSP Functionalities Control Sherifs
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/

//=============================================================================================
//                  DSP SLOW IDLE Control
//=============================================================================================
   #define DP_SLOW_IDLE_CTRL                  (*DPRAM2_base(DP_SLOW_IDLE_DIVIDER))

/*
============================================================================================================
------------------------------------------------------------------------------------------------------------
||                       DM/PM Address Definitions
------------------------------------------------------------------------------------------------------------
============================================================================================================
*/


#endif //__AUDIO_DEF_H

