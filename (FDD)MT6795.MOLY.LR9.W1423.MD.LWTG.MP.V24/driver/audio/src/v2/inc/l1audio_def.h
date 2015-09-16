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
 * l1audio_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines all the hardware/DSP registers used in l1audio module.
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
 *==============================================================================
 *******************************************************************************/

#ifndef __L1AUDIO_DEF_H
#define __L1AUDIO_DEF_H

#include "kal_public_api.h"
#include "reg_base.h"

typedef volatile unsigned short* APBADDR;          /* APB addr is 32 bits   */

//-----------------------------------------------------------------------------
// Configurations
//-----------------------------------------------------------------------------

// FIXME ... should move to option.mak
#ifdef __SMART_PHONE_MODEM__
#define __BT_SUPPORT__
#endif

/* ------------------------------------------------------------------------------ */
//KH 20100625: For Audio MT CMOS power on/off
#if defined(MT6276)
#define AUDSYS_CCF_CLK_CON    ((volatile kal_uint16 *) (TOPSM_base + 0x200))
#define AUDSYS_RM_PWR_CON     ((volatile kal_uint16 *) (TOPSM_base + 0x810))
#define AUDSYS_RM_PWR_ACK     ((volatile kal_uint16 *) (TOPSM_base + 0x820))
#define AUDSYS_INFRA_BUS_CON0 ((volatile kal_uint32 *) (CONFG_base + 0x548))
#define AUDSYS_RG_CK_ALW_ON   ((volatile kal_uint32 *) (CONFG_base + 0x824))
#define AUDSYS_MPLL_CON1      ((volatile kal_uint32 *) (MIX_ABB_base + 0x144))
#endif

/* ------------------------------------------------------------------------------ */

//temp solution, must update
#ifndef MIXED_base
#define MIXED_base MIX_ABB_base
#endif

#ifndef AFE_base
#define AFE_base AUDIOSYS_base
#endif

#ifndef DPRAM_CPU_base
#define DPRAM_CPU_base MIX_ABB_base
#endif

#ifndef DPRAM2_CPU_base
#define DPRAM2_CPU_base MIX_ABB_base
#endif

#ifndef SHARE_base
#define SHARE_base MIX_ABB_base
#endif

#define MUTE_UL_FRAME_SIZE (6)//de-popup noise (turn on/off mic-bias)

/* -------------------------------------------------------------------------- */
/* Hardware Definition                                                        */
/* -------------------------------------------------------------------------- */
#define IS_EV_BOARD  (defined(MT6235_EVB) || defined(MT6253_EVB) || defined(MT6236_EVB) || defined(MT6256_S00_EVB) || defined(MT6251_EVB) || defined(MT6253E_EVB) || defined(MT6253L_EVB)|| defined(MT6252_EVB) || defined(MT6252H_EVB) )

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
/* Assertion check                                                            */
/* -------------------------------------------------------------------------- */
#define ASSERT_REBOOT(st)  EXT_ASSERT(st,0,0,0)

/* -------------------------------------------------------------------------- */
/* ring buffer handling                                                       */
/* -------------------------------------------------------------------------- */

/*
   Example: define a ring buffer of 8 integers, put the value 3 and get it again:

   RINGBUFFER_T(int,8) myBuffer;
   RB_PUT( myBuffer, 3 );

   int value;
   RB_GET( myBuffer, value );
*/

/*
   size must be a power of two
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
/* -------------------------------------------------------------------------- */

/* DSP to CPU interrupt for Voice Memo (SHARE_D2MCON) */
#define DSP_ENA_VM_INTERRUPT     0x0010
/* DSP to CPU interrupt for A/V Sync (SHARE_D2MCON) */
#define DSP_ENA_AVSYNC_INTERRUPT 0x0020


/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/* Audio Front End Hardware Control Register                                  */
/* -------------------------------------------------------------------------- */
#define  AFE_VMCU_CON   ((APBADDR)(AFE_base+0x0000))        /* AFE MCU Cpntrol Register               */
#define  AFE_VMCU_CON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VMCU_CON2  ((APBADDR)(AFE_base+0x0010))        /* AFE Voice Analog Circuit Control Register 2   */
#define  AFE_VAC_DCON1  ((APBADDR)(AFE_base+0x000C))        /* AFE Voice Analog Circuit Control Register 1   */
#define  AFE_VDB_CON    ((APBADDR)(AFE_base+0x0014))        /* AFE Voice DAI Blue Tooth Control Register     */
#define  AFE_VLB_CON    ((APBADDR)(AFE_base+0x0018))        /* AFE Voice Loop-back Mode Control Register     */
#define  AFE_AMCU_CON0  ((APBADDR)(AFE_base+0x0020))        /* AFE Audio MCU Control Register 0gister        */
#define  AFE_AMCU_CON1  ((APBADDR)(AFE_base+0x0024))        /* AFE Audio Control Register 1                  */
#define  AFE_EDI_CON    ((APBADDR)(AFE_base+0x0028))        /* AFE Audio EDI(I2S , EIAJ) Control Register    */
#define  AFE_AMCU_CON2  ((APBADDR)(AFE_base+0x002C))        /* AFE Audio Control Register 2                  */
#define  AFE_DAC_TEST   ((APBADDR)(AFE_base+0x0030))        /* AUDIO/VOICE sinewave generator and others     */
#define  AFE_AMCU_CON3  ((APBADDR)(AFE_base+0x0038))        /* AFE Audio Control Register 3                  */
#define  AFE_EQCOEF     ((APBADDR)(AFE_base+0x0040))        /* AFE Audio EQ Coefficients                     */
#define  AFE_VAGC_CON0  ((APBADDR)(AFE_base+0x0100))        /* AFE Audio AGC Control Register 0              */
#define  AFE_VAGC_CON1  ((APBADDR)(AFE_base+0x0104))        /* AFE Audio AGC Control Register 1              */
#define  AFE_VAGC_CON2  ((APBADDR)(AFE_base+0x0108))        /* AFE Audio AGC Control Register 2              */
#define  AFE_VAGC_CON3  ((APBADDR)(AFE_base+0x010c))        /* AFE Audio AGC Control Register 3              */
#define  AFE_VAGC_CON4  ((APBADDR)(AFE_base+0x0110))        /* AFE Audio AGC Control Register 4              */
#define  AFE_VAGC_CON5  ((APBADDR)(AFE_base+0x0114))        /* AFE Audio AGC Control Register 5              */
#define  AFE_VAGC_CON6  ((APBADDR)(AFE_base+0x0118))        /* AFE Audio AGC Control Register 6              */
#define  ACIF_AC_HW_VER ((APBADDR)(MIXED_base+0x0004))      /* Mix-signal Chip Version Control               */
#define  AFE_VAG_CON    ((APBADDR)(MIXED_base+0x0100))      /* AFE Voice Analog Gain Control Register        */
#define  AFE_VAC_CON0   ((APBADDR)(MIXED_base+0x0104))      /* AFE Voice Analog-Circuit Control Register 0   */
#define  AFE_VAC_CON1   ((APBADDR)(MIXED_base+0x0108))      /* AFE Voice Analog-Circuit Control Register 1   */
#define  AFE_VAPDN_CON  ((APBADDR)(MIXED_base+0x010C))      /* AFE Voice Analog Power Down Control Register  */
#define  AFE_VAGC_CON   ((APBADDR)(MIXED_base+0x0110))      /* AFE Voice AGC Control Register  */
#define  AFE_VAC_CON2   ((APBADDR)(MIXED_base+0x0110))      /* AFE Voice Analog-Circuit Control Register 2   */
#define  AFE_AAG_CON    ((APBADDR)(MIXED_base+0x0200))      /* AFE Audio Analog Gain Control Register        */
#define  AFE_AAC_CON    ((APBADDR)(MIXED_base+0x0204))      /* AFE Audio Analog-Circuit Control Register     */
#define  AFE_AAPDN_CON  ((APBADDR)(MIXED_base+0x0208))      /* AFE Audio Analog Power Down Control Register  */
#define  AFE_AAC_NEW    ((APBADDR)(MIXED_base+0x020C))      /* Enhanced Audio AFE Control and Parameters     */
#define  AFE_AAC_CON1   ((APBADDR)(MIXED_base+0x0210))      /* AFE Audio Analog-Circuit Control Register 1   */

/* -------------------------------------------------------------------------- */

//To avoid build error
#define AFE_READ16(Reg)                        (*((volatile kal_uint16*)(Reg)))
#define AFE_WRITE16(Reg, Value)	               (*((volatile kal_uint16*)(Reg)) = (Value))

#define AFE_SET_BIT(Reg, Bit)                  AFE_WRITE16(Reg, AFE_READ16(Reg) | (Bit))
#define AFE_CLR_BIT(Reg, Bit)                  AFE_WRITE16(Reg, AFE_READ16(Reg) & (~(Bit)))

#define AUDSYS_READ32(Reg)                     (*((volatile kal_uint32*)(Reg)))
#define AUDSYS_WRITE32(Reg, Value)	           (*((volatile kal_uint32*)(Reg)) = (Value))

#define AUDSYS_SET_BIT(Reg, Bit)               AUDSYS_WRITE32(Reg, AUDSYS_READ32(Reg) | (Bit))
#define AUDSYS_CLR_BIT(Reg, Bit)               AUDSYS_WRITE32(Reg, AUDSYS_READ32(Reg) & (~(Bit)))

#if defined(MT6276)
#undef   PLL_CON2
#endif

#define  PLL_CON2       ((APBADDR)(MIX_ABB_base+0x0108))      /* PLL Control Register 2                        */

#if defined(MT6575) || defined(MT6577)
#define  WR_PATH0		((APBADDR)(MIX_ABB_base+0x0100)) 
#define  AUDIO_CON0     ((APBADDR)(MIX_ABB_base+0x0300))      /* AFE Audio Control register 0                  */
#define  AUDIO_CON1     ((APBADDR)(MIX_ABB_base+0x0304))      /* AFE Audio Control register 1                  */
#define  AUDIO_CON2     ((APBADDR)(MIX_ABB_base+0x0308))      /* AFE Audio Control register 2                  */
#define  AUDIO_CON3     ((APBADDR)(MIX_ABB_base+0x030C))      /* AFE Audio Control register 3                  */
#define  AUDIO_CON4     ((APBADDR)(MIX_ABB_base+0x0310))      /* AFE Audio Control register 4                  */
#define  AUDIO_CON5     ((APBADDR)(MIX_ABB_base+0x0314))      /* AFE Audio Control register 5                  */
#define  AUDIO_CON6     ((APBADDR)(MIX_ABB_base+0x0318))      /* AFE Audio Control register 6                  */
#define  AUDIO_CON7     ((APBADDR)(MIX_ABB_base+0x031C))      /* AFE Audio Control register 7                  */
#define  AUDIO_CON8     ((APBADDR)(MIX_ABB_base+0x0320))      /* AFE Audio Control register 8                  */
#define  AUDIO_CON9     ((APBADDR)(MIX_ABB_base+0x0324))      /* AFE Audio Control register 9                  */
#define  AUDIO_CON10    ((APBADDR)(MIX_ABB_base+0x0328))      /* AFE Audio Control register 10                 */
#define  AUDIO_CON14    ((APBADDR)(MIX_ABB_base+0x0338))      /* AFE Audio Control register 14                 */
#define  AUDIO_CON17    ((APBADDR)(MIX_ABB_base+0x0344))      /* AFE Audio Control register 17                 */
#define  AUDIO_CON20    ((APBADDR)(MIX_ABB_base+0x0380))      /* AFE Audio Control register 20                 */
#define  AUDIO_CON21    ((APBADDR)(MIX_ABB_base+0x0384))      /* AFE Audio Control register 21                 */
#define  AUDIO_CON22    ((APBADDR)(MIX_ABB_base+0x0388))      /* AFE Audio Control register 22                 */
#define  AUDIO_CON23    ((APBADDR)(MIX_ABB_base+0x038C))      /* AFE Audio Control register 23                 */
#define  AUDIO_CON24    ((APBADDR)(MIX_ABB_base+0x0390))      /* AFE Audio Control register 24                 */
#define  AUDIO_CON25    ((APBADDR)(MIX_ABB_base+0x0394))      /* AFE Audio Control register 25                 */
#define  AUDIO_CON26    ((APBADDR)(MIX_ABB_base+0x0398))      /* AFE Audio Control register 26                 */
#define  AUDIO_CON27    ((APBADDR)(MIX_ABB_base+0x039C))      /* AFE Audio Control register 27                 */
#define  AUDIO_CON28    ((APBADDR)(MIX_ABB_base+0x03A0))      /* AFE Audio Control register 28                 */
#define  AUDIO_CON29    ((APBADDR)(MIX_ABB_base+0x03A4))      /* AFE Audio Control register 29                 */
#define  AUDIO_CON30    ((APBADDR)(MIX_ABB_base+0x03A8))      /* AFE Audio Control register 30                 */
#define  AUDIO_CON31    ((APBADDR)(MIX_ABB_base+0x03AC))      /* AFE Audio Control register 31                 */
#define  AUDIO_CON32    ((APBADDR)(MIX_ABB_base+0x03B0))      /* AFE Audio Control register 32                 */
#define  AUDIO_CON33    ((APBADDR)(MIX_ABB_base+0x03B4))      /* AFE Audio Control register 33                 */
#define  AUDIO_CON34    ((APBADDR)(MIX_ABB_base+0x03B8))      /* AFE Audio Control register 34                 */

#define  AUDIO_NCP0    ((APBADDR)(MIX_ABB_base+0x0400)) 
#define  AUDIO_NCP1    ((APBADDR)(MIX_ABB_base+0x0404)) 
#define  AUDIO_LDO0    ((APBADDR)(MIX_ABB_base+0x0440)) 
#define  AUDIO_LDO1    ((APBADDR)(MIX_ABB_base+0x0444)) 
#define  AUDIO_LDO2    ((APBADDR)(MIX_ABB_base+0x0448)) 
#define  AUDIO_GLB0    ((APBADDR)(MIX_ABB_base+0x0480)) 
#define  AUDIO_GLB1    ((APBADDR)(MIX_ABB_base+0x0484)) 
#define  AUDIO_GLB2    ((APBADDR)(MIX_ABB_base+0x0488)) 
#define  AUDIO_LDO3    ((APBADDR)(MIX_ABB_base+0x044C)) 
#define  AUDIO_REG0    ((APBADDR)(MIX_ABB_base+0x04C0)) 
#define  AUDIO_REG1    ((APBADDR)(MIX_ABB_base+0x04C4)) 
#else
#define  WR_PATH0       ((APBADDR)(MIX_ABB_base+0x0800)) 
#define  AUDIO_CON0     ((APBADDR)(MIX_ABB_base+0x0900))      /* AFE Audio Control register 0                  */
#define  AUDIO_CON1     ((APBADDR)(MIX_ABB_base+0x0904))      /* AFE Audio Control register 1                  */
#define  AUDIO_CON2     ((APBADDR)(MIX_ABB_base+0x0908))      /* AFE Audio Control register 2                  */
#define  AUDIO_CON3     ((APBADDR)(MIX_ABB_base+0x090C))      /* AFE Audio Control register 3                  */
#define  AUDIO_CON4     ((APBADDR)(MIX_ABB_base+0x0910))      /* AFE Audio Control register 4                  */
#define  AUDIO_CON5     ((APBADDR)(MIX_ABB_base+0x0914))      /* AFE Audio Control register 5                  */
#define  AUDIO_CON6     ((APBADDR)(MIX_ABB_base+0x0918))      /* AFE Audio Control register 6                  */
#define  AUDIO_CON7     ((APBADDR)(MIX_ABB_base+0x091C))      /* AFE Audio Control register 7                  */
#define  AUDIO_CON8     ((APBADDR)(MIX_ABB_base+0x0920))      /* AFE Audio Control register 8                  */
#define  AUDIO_CON9     ((APBADDR)(MIX_ABB_base+0x0924))      /* AFE Audio Control register 9                  */
#define  AUDIO_CON10     ((APBADDR)(MIX_ABB_base+0x0928))      /* AFE Audio Control register 10                  */
#define  AUDIO_CON20    ((APBADDR)(MIX_ABB_base+0x0980))      /* AFE Audio Control register 20                 */
#define  AUDIO_CON21    ((APBADDR)(MIX_ABB_base+0x0984))      /* AFE Audio Control register 21                 */
#define  AUDIO_CON22    ((APBADDR)(MIX_ABB_base+0x0988))      /* AFE Audio Control register 22                 */
#define  AUDIO_CON23    ((APBADDR)(MIX_ABB_base+0x098C))      /* AFE Audio Control register 23                 */
#define  AUDIO_CON24    ((APBADDR)(MIX_ABB_base+0x0990))      /* AFE Audio Control register 24                 */
#define  AUDIO_CON25    ((APBADDR)(MIX_ABB_base+0x0994))      /* AFE Audio Control register 25                 */
#define  AUDIO_CON26    ((APBADDR)(MIX_ABB_base+0x0998))      /* AFE Audio Control register 26                 */
#define  AUDIO_CON27    ((APBADDR)(MIX_ABB_base+0x099C))      /* AFE Audio Control register 27                 */
#define  AUDIO_CON28    ((APBADDR)(MIX_ABB_base+0x09A0))      /* AFE Audio Control register 28                 */
#define  AUDIO_CON29    ((APBADDR)(MIX_ABB_base+0x09A4))      /* AFE Audio Control register 29                 */
#define  AUDIO_CON30    ((APBADDR)(MIX_ABB_base+0x09A8))      /* AFE Audio Control register 30                 */
#define  AUDIO_CON31    ((APBADDR)(MIX_ABB_base+0x09AC))      /* AFE Audio Control register 31                 */
#define  AUDIO_CON32    ((APBADDR)(MIX_ABB_base+0x09B0))      /* AFE Audio Control register 32                 */
#define  AUDIO_CON33    ((APBADDR)(MIX_ABB_base+0x09B4))      /* AFE Audio Control register 33                 */

#define  VAUDN_CON0     ((APBADDR)(MIX_PMU_base+0x0640))      /* AFE Audio Control register 32                 */
#define  VAUDP_CON0     ((APBADDR)(MIX_PMU_base+0x0650))      /* AFE Audio Control register 32                 */
#define  VAUDP_CON1     ((APBADDR)(MIX_PMU_base+0x0654))      /* AFE Audio Control register 32                 */
#define  VAUDP_CON2     ((APBADDR)(MIX_PMU_base+0x0658))      /* AFE Audio Control register 32                 */
#define  VA12_CON0      ((APBADDR)(MIX_PMU_base+0x0620))      /* AFE Audio Control register 32                 */
#define  VMIC_CON0      ((APBADDR)(MIX_PMU_base+0x0630))      /* AFE Audio Control register 32                 */
#define  VM25_CON0      ((APBADDR)(MIX_PMU_base+0x0720))      /* AFE Audio Control register 32                 */
#define  PMUA_CON2      ((APBADDR)(MIX_PMU_base+0x0688))      /* PMU Control Register 2      2                 */

#endif

/* -------------------------------------------------------------------------- */
/* Hardware Mute Support Platform                                             */
/* -------------------------------------------------------------------------- */
#define HW_MUTE_SUPPORT_PLATFORM (1)

/* -------------------------------------------------------------------------- */
/* Audio Post-Processing Control Field                                           */
/* -------------------------------------------------------------------------- */
#define APM_SUPPORT  ( !defined( MED_MODEM ) && !defined( MED_NOT_PRESENT ) )

/* -------------------------------------------------------------------------- */
/* VoRTP Support Definition                                                   */
/* -------------------------------------------------------------------------- */
#define VORTP_SUPPORT ( defined(__VOIP__) && defined(MT6276) )
#define VORTP_SUPPORT_G711_G726_VAD (defined(__VOIP__) && defined(MT6276) )
#define VORTP_G711_G726_COMPENSATE_BY_CNG (defined(__VOIP__) && defined(MT6276) )

#if (defined(__VOIP__) && defined(MT6276) )
#define FIRST_CODEC RTP_AUDIO_G729 | RTP_AUDIO_G7231 | \
				         RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40 | \
				         RTP_AUDIO_PCMA | RTP_AUDIO_PCMU
				         
#define SECOND_CODEC RTP_AUDIO_G729 | RTP_AUDIO_G7231 | \
				         RTP_AUDIO_G726_16 | RTP_AUDIO_G726_24 | RTP_AUDIO_G726_32 | RTP_AUDIO_G726_40 | \
				         RTP_AUDIO_PCMA | RTP_AUDIO_PCMU
#endif


// HQA relative setting
//#define __HQA_AUDIO__
#if defined(__HQA_AUDIO__)
   #define __HQA_AUDIO_HARDWARE_AGC__ 0
#endif

#if (defined(MT6276) && defined(__FMRADIO_I2S_SUPPORT__)) 
#define __INTERAL_FM_VIA_I2S__
#endif

#if defined(MT6276) 
#define __I2S_FOC_SUPPORT__ //for I2S slave mode
#endif

//Video playback MPL interface
#if !defined(__SMART_PHONE_MODEM__) && !defined(__L1_STANDALONE__) && !defined(MED_MODEM)
#define __AUDIO_STREAMING_NON_RINGBUFFER_SUPPORT__  
#endif

#define BESLOUDNESS_I2S_MODE_LOUDSPEAKER 0x1E
#define BESLOUDNESS_I2S_MODE_EARPHONE    0x1F

#endif /* __L1AUDIO_DEF_H */
