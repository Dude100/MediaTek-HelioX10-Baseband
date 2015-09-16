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
 *   l1_interface_reg.h
 *
 * Project:
 * --------
 *   MT6280
 *
 * Description:
 * ------------
 *   Registers and constants definitions for interface
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision: $
 * $Modtime:  $
 * $Log:      $
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 * 
 *******************************************************************************/

#ifndef  _L1_INTERFACE_REG_H_
#define  _L1_INTERFACE_REG_H_

#include "reg_base.h"
#include "l1_option.h"

#ifndef _COMMON_REG_H_
typedef volatile unsigned short* APBADDR;          /* APB addr is 32 bits   */
typedef volatile unsigned long*  APBADDR32;        /* APB addr is 32 bits   */
#endif

/***************************************************************************************************************************
 * Rigister definition for other modules                                                                                   *
 ***************************************************************************************************************************/

/* TDMA */
#define TQ_CURRENT_COUNT         ((APBADDR  )(TDMA_base+0x0000))          /*                read quater bit counter [13:0] */
#define TQ_WRAP                  ((APBADDR  )(TDMA_base+0x0004))          /*    latched Qbit counter reset position [13:0] */
#define TQ_EVENT_VALID           ((APBADDR  )(TDMA_base+0x000C))          /*                   event latch position [13:0] */
#define CTIRQ1                   ((APBADDR  )(TDMA_base+0x0014))          /*                   CPU tdma interrupt 1 [13:0] */
#define EVENT_ENA(n)             ((APBADDR32)(TDMA_base+0x0150+((n)*4)+(n/8)*2176))  /* event enable control n                        */
#define TQ_BIAS_CONT             ((APBADDR  )(TDMA_base+0x0174))          /* Qbit Timer Biasing Control Register           */
#define TDMA_AUXEV0              ((APBADDR  )(TDMA_base+0x0400))          /* Auxiliary ADC event 0                         */
#define TDMA_AUXEV1              ((APBADDR  )(TDMA_base+0x0404))          /* Auxiliary ADC event 1                         */
#define TDMA_AUXEVENA            EVENT_ENA(7)                             /* Auxiliary ADC event enable register           */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Sleep mode */
#if MD_DRV_IS_CENTRALIZED_SMM_CHIP
   #if MD_DRV_IS_CHIP_MT6250
#define SleepMode_base           MCU_TOPSM_base
   #elif MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define SleepMode_base           TOPSM_base
   #else
#error "Please check Sleep Mode base"
   #endif
#else
#define SleepMode_base           SM_base
#endif

#if MD_DRV_IS_CENTRALIZED_SMM_CHIP
#define RTCCOUNT                 ((APBADDR32)(SleepMode_base+0x0104))     /* 32K count                                     */
#else
#define RTCCOUNT                 ((APBADDR32)(SleepMode_base+0x0030))     /* 32K count                                     */
#endif

#if MD_DRV_IS_CENTRALIZED_SMM_CHIP
#define SM_FRC_CON               ((APBADDR32)(SleepMode_base+0x0080))     /* Free Running Counter Control Register         */
   #if MD_DRV_IS_CHIP_MT6290
#define SM_FM_CAL                ((APBADDR32)(SleepMode_base+0x00B4))     /* Frequency Measurement Calibration Control     */
#define SM_FM_T0                 ((APBADDR32)(SleepMode_base+0x00B8))     /* Frequency Measurement Start Time              */
#define SM_FM_T1                 ((APBADDR32)(SleepMode_base+0x00BC))     /* Frequency Measurement End   Time              */
   #else
#define SM_FM_CAL                ((APBADDR32)(SleepMode_base+0x00A4))     /* Frequency Measurement Calibration Control     */
#define SM_FM_T0                 ((APBADDR32)(SleepMode_base+0x00A8))     /* Frequency Measurement Start Time              */
#define SM_FM_T1                 ((APBADDR32)(SleepMode_base+0x00AC))     /* Frequency Measurement End   Time              */
   #endif
   #if MD_DRV_IS_CHIP_MT6290
#define SM_FM_CON                ((APBADDR32)(SleepMode_base+0x00B0))     /* Frequency Measurement Control Register        */
   #elif MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575
#define SM_FM_CON                ((APBADDR  )(SleepMode_base+0x00A0))     /* Frequency Measurement Control Register        */
   #else
#define SM_FM_CON                ((APBADDR32)(SleepMode_base+0x00A0))     /* Frequency Measurement Control Register        */
   #endif
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* Frequency hopping */
#if MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
// Frequency hopping is controled by System Service.
#elif MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define TDMA_FHCON(m)            ((APBADDR)(PLL_MIXEDSYS_base+0x0500+(m)*4))          /* m:0~5                             */
#define MNPLL_FHSET(m,n)         ((APBADDR)(PLL_MIXEDSYS_base+0x0524+(m)*16 +(n)*4 )) /* m:0~5, n:0~3                      */
#define EFPLL_FHSET(m,n)         ((APBADDR)(PLL_MIXEDSYS_base+0x0524+(m)*16 +(n)*4 )) /* m:0~5, n:0~3                      */
#elif MD_DRV_IS_CHIP_MT6280
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define TDMA_FHCON(m)            ((APBADDR)(MIX_ABB_base+0x0500+(m)*4))               /* m:0~7                             */
#define MNPLL_FHSET(m,n)         ((APBADDR)(MIX_ABB_base+0x0524+(m)*16 +(n)*4 ))      /* m:0~5, n:0~3                      */
#define EFPLL_FHSET(m,n)         ((APBADDR)(MIX_ABB_base+0x0524+(m)*16 +(n)*4 ))      /* m:0~5, n:0~3                      */
#elif MD_DRV_IS_CHIP_MT6250
#define TDMA_FHSTR(n)            ((APBADDR)(TDMA_base+0x0320+(4*(n))))
#define TDMA_FHCON(m)            ((APBADDR)(MIXED_base+0x0500+(m)*4))                 /* m:0~5                             */
#define MNPLL_FHSET(m,n)         ((APBADDR)(MIXED_base+0x0520+(m)*16 +(n)*4 ))        /* m:0~5, n:0~3, TDMA_FHCON8~31      */
#define EFPLL_FHSET(m,n)         ((APBADDR)(MIXED_base+0x0520+(m)*16 +(n)*4 ))        /* m:0~5, n:0~3, TDMA_FHCON8~31      */
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* MCU PDN */
#if MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1
/*MT6290~*/ #define MODEM_CG_CON0            ((APBADDR32)(MODEM2G_CONFG_base+0x000))    /* MODEM_CG_CON0 reg                    */
/*MT6290~*/ #define MODEM_CG_SET0            ((APBADDR32)(MODEM2G_CONFG_base+0x020))    /* MODEM_CG_CON0 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR0            ((APBADDR32)(MODEM2G_CONFG_base+0x010))    /* MODEM_CG_CON0 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON1            ((APBADDR32)(MODEM2G_CONFG_base+0x004))    /* MODEM_CG_CON1 reg                    */
/*MT6290~*/ #define MODEM_CG_SET1            ((APBADDR32)(MODEM2G_CONFG_base+0x024))    /* MODEM_CG_CON1 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR1            ((APBADDR32)(MODEM2G_CONFG_base+0x014))    /* MODEM_CG_CON1 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON2            ((APBADDR32)(MODEM2G_CONFG_base+0x008))    /* MODEM_CG_CON2 reg                    */
/*MT6290~*/ #define MODEM_CG_SET2            ((APBADDR32)(MODEM2G_CONFG_base+0x028))    /* MODEM_CG_CON2 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR2            ((APBADDR32)(MODEM2G_CONFG_base+0x018))    /* MODEM_CG_CON2 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON4            ((APBADDR32)(MODEM2G_CONFG_base+0x088))    /* MODEM_CG_CON4 reg                    */
/*MT6290~*/ #define MODEM_CG_SET4            ((APBADDR32)(MODEM2G_CONFG_base+0x0A8))    /* MODEM_CG_CON4 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR4            ((APBADDR32)(MODEM2G_CONFG_base+0x098))    /* MODEM_CG_CON4 write 1 clear reg      */
/*MT6290~*/ #define PDN_CON0                 MODEM_CG_CON0
/*MT6290~*/ #define PDN_SET0                 MODEM_CG_SET0
/*MT6290~*/ #define PDN_CLR0                 MODEM_CG_CLR0
/*MT6290~*/ #define PDN_CON1                 MODEM_CG_CON1
/*MT6290~*/ #define PDN_SET1                 MODEM_CG_SET1
/*MT6290~*/ #define PDN_CLR1                 MODEM_CG_CLR1
/*MT6290~*/ #define PDN_CON2                 MODEM_CG_CON2
/*MT6290~*/ #define PDN_SET2                 MODEM_CG_SET2
/*MT6290~*/ #define PDN_CLR2                 MODEM_CG_CLR2
/*MT6290~*/ #define PDN_CON4                 MODEM_CG_CON4                         /* immediate mode                       */
/*MT6290~*/ #define PDN_SET4                 MODEM_CG_SET4                         /* immediate mode                       */
/*MT6290~*/ #define PDN_CLR4                 MODEM_CG_CLR4                         /* immediate mode                       */
/*MT6290~*/
/*MT6290~*/ #define MPERI_APB_R2T            ((APBADDR32)(MODEM2G_CONFG_base+0x100))    /* MODEM_PERI APB READ 2T REG           */
/*MT6290~*/ #define MPERI_APB_W2T            ((APBADDR32)(MODEM2G_CONFG_base+0x104))    /* MODEM_PERI APB WRITE 2T REG          */
/*MT6290~*/ #define MPERI_APB3_SEL           ((APBADDR32)(MODEM2G_CONFG_base+0x108))    /* MODEM_PERI APB3.0 SELECT REG         */
/*MT6290~*/ #define MPERI_PWR_AWARE          ((APBADDR32)(MODEM2G_CONFG_base+0x400))    /* Modemsys bus active aware            */
/*MT6290~*/
/*MT6290~*/ #define PDN_CON_TDMA             0x0001                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_BSI              0x0004                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_BPI              0x0008                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_AFC              0x0010                                /* The same as MT6276                   */
/*MT6290~*/
#elif MD_DRV_IS_CHIP_MT6752_MD2
/*MT6290~*/ #define MODEM_CG_CON0            ((APBADDR32)(MDCONFIG_base+0x000))    /* MODEM_CG_CON0 reg                    */
/*MT6290~*/ #define MODEM_CG_SET0            ((APBADDR32)(MDCONFIG_base+0x020))    /* MODEM_CG_CON0 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR0            ((APBADDR32)(MDCONFIG_base+0x010))    /* MODEM_CG_CON0 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON1            ((APBADDR32)(MDCONFIG_base+0x004))    /* MODEM_CG_CON1 reg                    */
/*MT6290~*/ #define MODEM_CG_SET1            ((APBADDR32)(MDCONFIG_base+0x024))    /* MODEM_CG_CON1 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR1            ((APBADDR32)(MDCONFIG_base+0x014))    /* MODEM_CG_CON1 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON2            ((APBADDR32)(MDCONFIG_base+0x008))    /* MODEM_CG_CON2 reg                    */
/*MT6290~*/ #define MODEM_CG_SET2            ((APBADDR32)(MDCONFIG_base+0x028))    /* MODEM_CG_CON2 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR2            ((APBADDR32)(MDCONFIG_base+0x018))    /* MODEM_CG_CON2 write 1 clear reg      */
/*MT6290~*/ #define MODEM_CG_CON4            ((APBADDR32)(MDCONFIG_base+0x088))    /* MODEM_CG_CON4 reg                    */
/*MT6290~*/ #define MODEM_CG_SET4            ((APBADDR32)(MDCONFIG_base+0x0A8))    /* MODEM_CG_CON4 write 1 set reg        */
/*MT6290~*/ #define MODEM_CG_CLR4            ((APBADDR32)(MDCONFIG_base+0x098))    /* MODEM_CG_CON4 write 1 clear reg      */
/*MT6290~*/ #define PDN_CON0                 MODEM_CG_CON0
/*MT6290~*/ #define PDN_SET0                 MODEM_CG_SET0
/*MT6290~*/ #define PDN_CLR0                 MODEM_CG_CLR0
/*MT6290~*/ #define PDN_CON1                 MODEM_CG_CON1
/*MT6290~*/ #define PDN_SET1                 MODEM_CG_SET1
/*MT6290~*/ #define PDN_CLR1                 MODEM_CG_CLR1
/*MT6290~*/ #define PDN_CON2                 MODEM_CG_CON2
/*MT6290~*/ #define PDN_SET2                 MODEM_CG_SET2
/*MT6290~*/ #define PDN_CLR2                 MODEM_CG_CLR2
/*MT6290~*/ #define PDN_CON4                 MODEM_CG_CON4                         /* immediate mode                       */
/*MT6290~*/ #define PDN_SET4                 MODEM_CG_SET4                         /* immediate mode                       */
/*MT6290~*/ #define PDN_CLR4                 MODEM_CG_CLR4                         /* immediate mode                       */
/*MT6290~*/
/*MT6290~*/ #define MPERI_APB_R2T            ((APBADDR32)(MDCONFIG_base+0x100))    /* MODEM_PERI APB READ 2T REG           */
/*MT6290~*/ #define MPERI_APB_W2T            ((APBADDR32)(MDCONFIG_base+0x104))    /* MODEM_PERI APB WRITE 2T REG          */
/*MT6290~*/ #define MPERI_APB3_SEL           ((APBADDR32)(MDCONFIG_base+0x108))    /* MODEM_PERI APB3.0 SELECT REG         */
/*MT6290~*/ #define MPERI_PWR_AWARE          ((APBADDR32)(MDCONFIG_base+0x400))    /* Modemsys bus active aware            */
/*MT6290~*/
/*MT6290~*/ #define PDN_CON_TDMA             0x0001                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_BSI              0x0004                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_BPI              0x0008                                /* The same as MT6276                   */
/*MT6290~*/ #define PDN_CON_AFC              0x0010                                /* The same as MT6276                   */
/*MT6290~*/
#elif MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572
/*MT6250~*/ #define MODEM_CG_CON0            ((APBADDR32)(MDCONFIG_base+0x000))    /* MODEM_CG_CON0 reg                    */
/*MT6250~*/ #define MODEM_CG_SET0            ((APBADDR32)(MDCONFIG_base+0x020))    /* MODEM_CG_CON0 write 1 set reg        */
/*MT6250~*/ #define MODEM_CG_CLR0            ((APBADDR32)(MDCONFIG_base+0x010))    /* MODEM_CG_CON0 write 1 clear reg      */
/*MT6250~*/ #define MODEM_CG_CON1            ((APBADDR32)(MDCONFIG_base+0x004))    /* MODEM_CG_CON1 reg                    */
/*MT6250~*/ #define MODEM_CG_SET1            ((APBADDR32)(MDCONFIG_base+0x024))    /* MODEM_CG_CON1 write 1 set reg        */
/*MT6250~*/ #define MODEM_CG_CLR1            ((APBADDR32)(MDCONFIG_base+0x014))    /* MODEM_CG_CON1 write 1 clear reg      */
/*MT6250~*/ #define MODEM_CG_CON2            ((APBADDR32)(MDCONFIG_base+0x008))    /* MODEM_CG_CON2 reg                    */
/*MT6250~*/ #define MODEM_CG_SET2            ((APBADDR32)(MDCONFIG_base+0x028))    /* MODEM_CG_CON2 write 1 set reg        */
/*MT6250~*/ #define MODEM_CG_CLR2            ((APBADDR32)(MDCONFIG_base+0x018))    /* MODEM_CG_CON2 write 1 clear reg      */
/*MT6250~*/ #define MODEM_CG_CON4            ((APBADDR32)(MDCONFIG_base+0x088))    /* MODEM_CG_CON4 reg                    */
/*MT6250~*/ #define MODEM_CG_SET4            ((APBADDR32)(MDCONFIG_base+0x0A8))    /* MODEM_CG_CON4 write 1 set reg        */
/*MT6250~*/ #define MODEM_CG_CLR4            ((APBADDR32)(MDCONFIG_base+0x098))    /* MODEM_CG_CON4 write 1 clear reg      */
/*MT6250~*/ #define PDN_CON0                 MODEM_CG_CON0
/*MT6250~*/ #define PDN_SET0                 MODEM_CG_SET0
/*MT6250~*/ #define PDN_CLR0                 MODEM_CG_CLR0
/*MT6250~*/ #define PDN_CON1                 MODEM_CG_CON1
/*MT6250~*/ #define PDN_SET1                 MODEM_CG_SET1
/*MT6250~*/ #define PDN_CLR1                 MODEM_CG_CLR1
/*MT6250~*/ #define PDN_CON2                 MODEM_CG_CON2
/*MT6250~*/ #define PDN_SET2                 MODEM_CG_SET2
/*MT6250~*/ #define PDN_CLR2                 MODEM_CG_CLR2
/*MT6250~*/ #define PDN_CON4                 MODEM_CG_CON4                         /* immediate mode                       */
/*MT6250~*/ #define PDN_SET4                 MODEM_CG_SET4                         /* immediate mode                       */
/*MT6250~*/ #define PDN_CLR4                 MODEM_CG_CLR4                         /* immediate mode                       */
/*MT6250~*/
/*MT6250~*/ #define MPERI_APB_R2T            ((APBADDR32)(MDCONFIG_base+0x100))    /* MODEM_PERI APB READ 2T REG           */
/*MT6250~*/ #define MPERI_APB_W2T            ((APBADDR32)(MDCONFIG_base+0x104))    /* MODEM_PERI APB WRITE 2T REG          */
/*MT6250~*/ #define MPERI_APB3_SEL           ((APBADDR32)(MDCONFIG_base+0x108))    /* MODEM_PERI APB3.0 SELECT REG         */
/*MT6250~*/ #define MPERI_PWR_AWARE          ((APBADDR32)(MDCONFIG_base+0x400))    /* Modemsys bus active aware            */
/*MT6250~*/
/*MT6250~*/ #define PDN_CON_TDMA             0x0001                                /* The same as MT6276                   */
/*MT6250~*/ #define PDN_CON_BSI              0x0004                                /* The same as MT6276                   */
/*MT6250~*/ #define PDN_CON_BPI              0x0008                                /* The same as MT6276                   */
/*MT6250~*/ #define PDN_CON_AFC              0x0010                                /* The same as MT6276                   */
/*MT6250~*/
#elif MD_DRV_IS_CHIP_MT6573
/*MT6573~*/ #define MCU_CG_CON0              ((APBADDR32)(CONFIG_base+0x300))      /* Power Down Control 0 Register        */
/*MT6573~*/ #define MCU_CG_CON1              ((APBADDR32)(CONFIG_base+0x310))      /* Power Down Control 1 Register        */
/*MT6573~*/ #define MCU_CG_SET0              ((APBADDR32)(CONFIG_base+0x304))      /* Power Down Disable 0 Register        */
/*MT6573~*/ #define MCU_CG_SET1              ((APBADDR32)(CONFIG_base+0x314))      /* Power Down Disable 1 Register        */
/*MT6573~*/ #define MCU_CG_CLR0              ((APBADDR32)(CONFIG_base+0x308))      /* Power Down Enable  0 Register        */
/*MT6573~*/ #define MCU_CG_CLR1              ((APBADDR32)(CONFIG_base+0x318))      /* Power Down Enable  1 Register        */
/*MT6573~*/ #define PDN_CON2                 MCU_CG_CON0
/*MT6573~*/ #define PDN_CON4                 MCU_CG_CON1
/*MT6573~*/ #define PDN_SET2                 MCU_CG_SET0
/*MT6573~*/ #define PDN_SET4                 MCU_CG_SET1
/*MT6573~*/ #define PDN_CLR2                 MCU_CG_CLR0
/*MT6573~*/ #define PDN_CLR4                 MCU_CG_CLR1
/*MT6573~*/
/*MT6573~*/ #define APMCU_CG_CON0            ((APBADDR32)(APCONFIG_base+0x300))    /* AP Power Down Control 0 Register     */
/*MT6573~*/ #define APMCU_CG_CON1            ((APBADDR32)(APCONFIG_base+0x310))    /* AP Power Down Control 1 Register     */
/*MT6573~*/ #define APMCU_CG_SET0            ((APBADDR32)(APCONFIG_base+0x304))    /* AP Power Down Disable 0 Register     */
/*MT6573~*/ #define APMCU_CG_SET1            ((APBADDR32)(APCONFIG_base+0x314))    /* AP Power Down Disable 1 Register     */
/*MT6573~*/ #define APMCU_CG_CLR0            ((APBADDR32)(APCONFIG_base+0x308))    /* AP Power Down Enable  0 Register     */
/*MT6573~*/ #define APMCU_CG_CLR1            ((APBADDR32)(APCONFIG_base+0x318))    /* AP Power Down Enable  1 Register     */
/*MT6573~*/ #define AP_PDN_CON0              APMCU_CG_CON0
/*MT6573~*/ #define AP_PDN_CON1              APMCU_CG_CON1
/*MT6573~*/ #define AP_PDN_SET0              APMCU_CG_SET0
/*MT6573~*/ #define AP_PDN_SET1              APMCU_CG_SET1
/*MT6573~*/ #define AP_PDN_CLR0              APMCU_CG_CLR0
/*MT6573~*/ #define AP_PDN_CLR1              APMCU_CG_CLR1
/*MT6573~*/
/*MT6573~*/ #define PDN_CON_TDMA             0x0080
/*MT6573~*/ #define PDN_CON_BSI              0x0040
/*MT6573~*/ #define PDN_CON_BPI              0x0020
/*MT6573~*/ #define PDN_CON_AFC              0x0010
/*MT6573~*/
#elif MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6575
/*MT6276~*/ #define MCU_CG_CON0              ((APBADDR)(CONFIG_base+0x300))        /* Power Down Control 0 Register        */
/*MT6276~*/ #define MCU_CG_CON1              ((APBADDR)(CONFIG_base+0x304))        /* Power Down Control 1 Register        */
/*MT6276~*/ #define MCU_CG_CON2              ((APBADDR)(CONFIG_base+0x308))        /* Power Down Control 2 Register        */
/*MT6276~*/ #define MCU_CG_CON3              ((APBADDR)(CONFIG_base+0x30C))        /* Power Down Control 3 Register        */
/*MT6276~*/ #define MCU_CG_CON4              ((APBADDR)(CONFIG_base+0x330))        /* Power Down Control 4 Register        */
/*MT6276~*/ #define MCU_CG_SET0              ((APBADDR)(CONFIG_base+0x310))        /* Power Down Disable 0 Register        */
/*MT6276~*/ #define MCU_CG_SET1              ((APBADDR)(CONFIG_base+0x314))        /* Power Down Disable 1 Register        */
/*MT6276~*/ #define MCU_CG_SET2              ((APBADDR)(CONFIG_base+0x318))        /* Power Down Disable 2 Register        */
/*MT6276~*/ #define MCU_CG_SET3              ((APBADDR)(CONFIG_base+0x31C))        /* Power Down Disable 3 Register        */
/*MT6276~*/ #define MCU_CG_SET4              ((APBADDR)(CONFIG_base+0x334))        /* Power Down Disable 4 Register        */
/*MT6276~*/ #define MCU_CG_CLR0              ((APBADDR)(CONFIG_base+0x320))        /* Power Down Enable  0 Register        */
/*MT6276~*/ #define MCU_CG_CLR1              ((APBADDR)(CONFIG_base+0x324))        /* Power Down Enable  1 Register        */
/*MT6276~*/ #define MCU_CG_CLR2              ((APBADDR)(CONFIG_base+0x328))        /* Power Down Enable  2 Register        */
/*MT6276~*/ #define MCU_CG_CLR3              ((APBADDR)(CONFIG_base+0x32C))        /* Power Down Enable  3 Register        */
/*MT6276~*/ #define MCU_CG_CLR4              ((APBADDR)(CONFIG_base+0x338))        /* Power Down Enable  4 Register        */
/*MT6276~*/ #define PDN_CON0                 MCU_CG_CON0
/*MT6276~*/ #define PDN_CON1                 MCU_CG_CON1
/*MT6276~*/ #define PDN_CON2                 MCU_CG_CON2
/*MT6276~*/ #define PDN_CON3                 MCU_CG_CON3
/*MT6276~*/ #define PDN_CON4                 MCU_CG_CON4
/*MT6276~*/ #define PDN_SET0                 MCU_CG_SET0
/*MT6276~*/ #define PDN_SET1                 MCU_CG_SET1
/*MT6276~*/ #define PDN_SET2                 MCU_CG_SET2
/*MT6276~*/ #define PDN_SET3                 MCU_CG_SET3
/*MT6276~*/ #define PDN_SET4                 MCU_CG_SET4
/*MT6276~*/ #define PDN_CLR0                 MCU_CG_CLR0
/*MT6276~*/ #define PDN_CLR1                 MCU_CG_CLR1
/*MT6276~*/ #define PDN_CLR2                 MCU_CG_CLR2
/*MT6276~*/ #define PDN_CLR3                 MCU_CG_CLR3
/*MT6276~*/ #define PDN_CLR4                 MCU_CG_CLR4
/*MT6276~*/
/*MT6276~*/ #define PDN_CON_TDMA             0x0001
/*MT6276~*/ #define PDN_CON_BSI              0x0004
/*MT6276~*/
#else
/*else   */ #error "Please check MCU PDN related settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* MD2G PDN */
#if MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
/*MT6250~*/ #define MD2GSYS_CG_CON0         ((APBADDR)(MD2GCONFG_base+0x000))      /* Power Down Control 0 Register        */
/*MT6250~*/ #define MD2GSYS_CG_CON2         ((APBADDR)(MD2GCONFG_base+0x008))      /* Power Down Control 2 Register        */
/*MT6250~*/ #define MD2GSYS_CG_CON4         ((APBADDR)(MD2GCONFG_base+0x030))      /* Power Down Control 4 Register        */
/*MT6250~*/ #define MD2GSYS_CG_SET0         ((APBADDR)(MD2GCONFG_base+0x010))      /* Power Down Disable 0 Register        */
/*MT6250~*/ #define MD2GSYS_CG_SET2         ((APBADDR)(MD2GCONFG_base+0x018))      /* Power Down Disable 2 Register        */
/*MT6250~*/ #define MD2GSYS_CG_SET4         ((APBADDR)(MD2GCONFG_base+0x034))      /* Power Down Disable 4 Register        */
/*MT6250~*/ #define MD2GSYS_CG_CLR0         ((APBADDR)(MD2GCONFG_base+0x020))      /* Power Down Enable  0 Register        */
/*MT6250~*/ #define MD2GSYS_CG_CLR2         ((APBADDR)(MD2GCONFG_base+0x028))      /* Power Down Enable  2 Register        */
/*MT6250~*/ #define MD2GSYS_CG_CLR4         ((APBADDR)(MD2GCONFG_base+0x038))      /* Power Down Enable  4 Register        */
/*MT6250~*/ #define MD2G_PDN_CON0           MD2GSYS_CG_CON0                        /* not used                             */
/*MT6250~*/ #define MD2G_PDN_CON2           MD2GSYS_CG_CON2                        /* not used                             */
/*MT6250~*/ #define MD2G_PDN_CON4           MD2GSYS_CG_CON4                        /* not used                             */
/*MT6250~*/ #define MD2G_PDN_SET0           MD2GSYS_CG_SET0
/*MT6250~*/ #define MD2G_PDN_SET2           MD2GSYS_CG_SET2
/*MT6250~*/ #define MD2G_PDN_SET4           MD2GSYS_CG_SET4
/*MT6250~*/ #define MD2G_PDN_CLR0           MD2GSYS_CG_CLR0
/*MT6250~*/ #define MD2G_PDN_CLR2           MD2GSYS_CG_CLR2
/*MT6250~*/ #define MD2G_PDN_CLR4           MD2GSYS_CG_CLR4
/*MT6250~*/
#elif MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575
/*MT6276~*/ #define GCG_CON0                ((APBADDR)(MD2G_CFG_base+0x300))
/*MT6276~*/ #define GCG_CON1                ((APBADDR)(MD2G_CFG_base+0x304))
/*MT6276~*/ #define GCG_CON2                ((APBADDR)(MD2G_CFG_base+0x308))
/*MT6276~*/ #define GCG_SET0                ((APBADDR)(MD2G_CFG_base+0x310))
/*MT6276~*/ #define GCG_SET1                ((APBADDR)(MD2G_CFG_base+0x314))
/*MT6276~*/ #define GCG_SET2                ((APBADDR)(MD2G_CFG_base+0x318))
/*MT6276~*/ #define GCG_CLR0                ((APBADDR)(MD2G_CFG_base+0x320))
/*MT6276~*/ #define GCG_CLR1                ((APBADDR)(MD2G_CFG_base+0x324))
/*MT6276~*/ #define GCG_CLR2                ((APBADDR)(MD2G_CFG_base+0x328))
/*MT6276~*/ #define MD2G_PDN_CON0           GCG_CON0
/*MT6276~*/ #define MD2G_PDN_CON1           GCG_CON1
/*MT6276~*/ #define MD2G_PDN_CON2           GCG_CON2
/*MT6276~*/ #define MD2G_PDN_SET0           GCG_SET0
/*MT6276~*/ #define MD2G_PDN_SET1           GCG_SET1
/*MT6276~*/ #define MD2G_PDN_SET2           GCG_SET2
/*MT6276~*/ #define MD2G_PDN_CLR0           GCG_CLR0
/*MT6276~*/ #define MD2G_PDN_CLR1           GCG_CLR1
/*MT6276~*/ #define MD2G_PDN_CLR2           GCG_CLR2
/*MT6276~*/
/*MT6276~*/ // For MD2G Logger
/*MT6276~*/ #define MD2G_LOG_SWRST          ((APBADDR32)(MD2G_LOG_base+0x000))
/*MT6276~*/ #define MD2G_LOG_EN             ((APBADDR32)(MD2G_LOG_base+0x004))
/*MT6276~*/ #define MD2G_LOG_STA            ((APBADDR32)(MD2G_LOG_base+0x020))
/*MT6276~*/
#else
/*else   */ #error "Please check MD2G PDN related settings"
#endif
/* ======================================================================================================================= */


/***************************************************************************************************************************
 * Global constant and data definition for other modules                                                                   *
 ***************************************************************************************************************************/

/* Magic value */
#if MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define  CMD_MAGIC_VALUE                    0x65930000
#define  FRC_CMD_MAGIC_VALUE                0x11530000
#elif MD_DRV_IS_CHIP_MT6290
#define  CMD_MAGIC_VALUE                    0x72080000
#define  FRC_CMD_MAGIC_VALUE                CMD_MAGIC_VALUE
#elif MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572
#define  CMD_MAGIC_VALUE                    0x11530000
#define  FRC_CMD_MAGIC_VALUE                CMD_MAGIC_VALUE
#elif MD_DRV_IS_CHIP_MT6575
#define  CMD_MAGIC_VALUE                    0x65750000
#define  FRC_CMD_MAGIC_VALUE                CMD_MAGIC_VALUE
#elif MD_DRV_IS_CHIP_MT6573
#define  CMD_MAGIC_VALUE                    0x65730000
#define  FRC_CMD_MAGIC_VALUE                CMD_MAGIC_VALUE
#elif MD_DRV_IS_CHIP_MT6276
#define  CMD_MAGIC_VALUE                    0x62760000
#define  FRC_CMD_MAGIC_VALUE                CMD_MAGIC_VALUE
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

 /* PDN mask and sleep mode settings */
#if MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
/*MT6280*/  #define MODEMSYS_MASK           0x101D  // ModemSYS(CLR2): FCS, AFC, BPI, BSI, TDMA
/*MT6280*/  #define MD2G_MASK1              0x0002  // MD2G(CLR0):     GCC
/*MT6280*/  #define MD2G_MASK2              0x0220  // MD2G(CLR2):     BFE, APC
/*MT6280*/  #define SLPON                   0x0001  // Clock on  module in sleep mode: TDMA
/*MT6280*/  #define SLPOFF                  0x023E  // Clock off module in sleep mode: else
#elif MD_DRV_IS_CHIP_MT6250
/*MT6250*/  #define MODEMSYS_MASK           0x100D  // ModemSYS(CLR2): FCS, BPI, BSI, TDMA
/*MT6250*/  #define MD2G_MASK1              0x0002  // MD2G(CLR0):     GCC
/*MT6250*/  #define MD2G_MASK2              0x0220  // MD2G(CLR2):     BFE, APC
/*MT6250*/  #define SLPON                   0x0001  // Clock on  module in sleep mode: TDMA
/*MT6250*/  #define SLPOFF                  0x122E  // Clock off module in sleep mode: else
#elif MD_DRV_IS_CHIP_MT6575
/*MT6575*/  #define MCUSYS_MASK1            0x021D
/*MT6575*/  #define MCUSYS_MASK2            0x2000
/*MT6575*/  #define MD2G_MASK               0x1C42
/*MT6575*/  #define SLPON                   0x0211
/*MT6575*/  #define SLPOFF                  0x3C4E
#elif MD_DRV_IS_CHIP_MT6573
/*MT6573*/  #define APMCUSYS_MASK           0x0040
/*MT6573*/  #define MCUSYS_MASK             0x00F0
/*MT6573*/  #define MD2G_MASK               0x1CC2
/*MT6573*/  #define SLPON                   0x00D0
/*MT6573*/  #define SLPOFF                  0x1CE2
#elif MD_DRV_IS_CHIP_MT6276
/*MT6276*/  #define MCUSYS_MASK             0x021D
/*MT6276*/  #define MD2G_MASK               0x1CC2
/*MT6276*/  #define SLPON                   0x0211
/*MT6276*/  #define SLPOFF                  0x1CCE
#else
/*else  */  #error "Please check PDN mask and sleep mode settings"
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#if MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
   #if (defined L1D_TEST)
/*MT6250~*/ #define PWR_ON_SETTLE           4
   #else
/*MT6250~*/ #define PWR_ON_SETTLE           2
   #endif
#endif
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* TDMA timing */
#if MD_DRV_IS_AST_B2S_SUPPORT
#define MD_DRV_TQ_AFC_READY                 245
#else
#define MD_DRV_TQ_AFC_READY                 256
#endif

#if MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define MD_DRV_TQ_MAXIMUM                   16383                                        /*16383: 0x3FFF*/
#else
#define MD_DRV_TQ_MAXIMUM                   (2*MD_DRV_TQ_WRAP_COUNT+MD_DRV_TQ_SLOT_LEN)  /*10624: 2 frames + 1 slot*/
#endif
#define MD_DRV_TQ_SLOT_LEN                  (156*4)
#define MD_DRV_TQ_WRAP_COUNT                5000
#define MD_DRV_TQ_VALIDATE_COUNT            4939
#define MD_DRV_TQ_CTIRQ1                    (MD_DRV_TQ_AFC_READY+625*5)
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

// MT6573E1, MD2G sleep ECO for pause abort on preclock_off rising edge
#if MD_DRV_IS_CHIP_MT6573
#define MD_DRV_EVTENA0_SLOW_EN_SEL          (0x1<<4)
#else
#define MD_DRV_EVTENA0_SLOW_EN_SEL          (0)
#endif
/*=========================================================================================================================*/

#endif
