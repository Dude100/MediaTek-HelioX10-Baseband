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
 *    adc_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for adc driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ADC_HW_H
#define _ADC_HW_H 
#include "drv_features_adc.h"
#include "drvpdn.h"

#if defined(DRV_ADC_6236_SERIES)
/*
MT6236 BASE=0x801c_0000
Check bit of ADC (1b)     *(BASE+0x0020)[13]=[333]
ADC_B (6b)             *(BASE+0x0020)[12:7]=[332:327]
ADC_A (7b)             *(BASE+0x0020)[6:0]=[326:320]
*/
#define EFUSE_ADC_BASE 0x801c0020
#define EFUSE_ADC_A 0x801c0020
#define EFUSE_ADC_B 0x801c0020
#define EFUSE_ADC_ENABLE 0x2000
#define EFUSE_ADC_A_MASK 0x7F
#define EFUSE_ADC_B_MASK 0x1F80
#define EFUSE_ADC_A_SHIFT 0
#define EFUSE_ADC_B_SHIFT 7

#elif defined(DRV_ADC_6252_SERIES)
/*
MT6252 BASE=0x8000_0000
Check bit of ADC (1b), *(BASE+0x0020)[13]=[333]
ADC_B (6b), *(BASE+0x0020)[12:7]=[332:327]
ADC_A (7b), *(BASE+0x0020)[6:0]=[326:320]
*/
#define EFUSE_ADC_BASE 0x80000020
#define EFUSE_ADC_A 0x80000020
#define EFUSE_ADC_B 0x80000020
#define EFUSE_ADC_ENABLE 0x2000
#define EFUSE_ADC_A_MASK 0x7F
#define EFUSE_ADC_B_MASK 0x1F80
#define EFUSE_ADC_A_SHIFT 0
#define EFUSE_ADC_B_SHIFT 7

#elif defined(DRV_ADC_6251_SERIES)

#define EFUSE_ADC_BASE 0x80000100
#define EFUSE_ADC_A 0x80000100
#define EFUSE_ADC_B 0x80000100
#define EFUSE_ADC_ENABLE 0x0002
#define EFUSE_ADC_A_MASK 0x7FC00
#define EFUSE_ADC_B_MASK 0x3FC
#define EFUSE_ADC_A_SHIFT 10
#define EFUSE_ADC_B_SHIFT 2

#elif defined(DRV_ADC_6256_SERIES)

#define EFUSE_ADC_BASE 0x80000100
#define EFUSE_ADC_A 0x80000100
#define EFUSE_ADC_B 0x80000100
#define EFUSE_ADC_ENABLE 0x0002
#define EFUSE_ADC_A_MASK 0x7FC00
#define EFUSE_ADC_B_MASK 0x3FC
#define EFUSE_ADC_A_SHIFT 10
#define EFUSE_ADC_B_SHIFT  2

#elif defined(DRV_ADC_6575_SERIES)

#define EFUSE_ADC_BASE 0xC1019040
#define EFUSE_ADC_ENABLE 0x0
#define EFUSE_O_VBG 0xC1019040
#define EFUSE_O_VBG_MASK	0x1FF00
#define EFUSE_O_VBG_SHIFT	0x8
#define EFUSE_ADC_OE    0xC1019044
#define EFUSE_ADC_OE_MASK	0xFF
#define EFUSE_ADC_OE_SHIFT  0
#define EFUSE_ADC_GE    0xC1019048
#define EFUSE_ADC_GE_MASK    0xFF
#define EFUSE_ADC_GE_SHIFT   0

#define TS_CON1     0xC0007804
#define TS_CON2     0xC0007808

#elif defined(DRV_ADC_6250_SERIES)	// 10 bits ADC

#define EFUSE_ADC_BASE 0xA01C0200
#define EFUSE_ADC_A 0xA01C0200
#define EFUSE_ADC_B 0xA01C0200
#define EFUSE_ADC_ENABLE 0x0002
#define EFUSE_ADC_A_MASK 0x1FC00	// 7 bits
#define EFUSE_ADC_B_MASK 0xFC	// 6 bits
#define EFUSE_ADC_A_SHIFT 10
#define EFUSE_ADC_B_SHIFT  2


#else
/*
1. Check bit of ADC (1b), *(0x80000020)[18]=[210]
2. ADC_B (6b), *(0x80000020)[17:12]=[209:204]
3. ADC_A (7b), *(0x80000020)[11:5]=[203:197]
*/
#define EFUSE_ADC_BASE 0x80000020
#define EFUSE_ADC_A 0x80000020
#define EFUSE_ADC_B 0x80000020
#define EFUSE_ADC_ENABLE 0x40000
#define EFUSE_ADC_A_MASK 0xFE0
#define EFUSE_ADC_B_MASK 0x3F000
#define EFUSE_ADC_A_SHIFT 5
#define EFUSE_ADC_B_SHIFT 12

#endif

#if defined(DRV_ADC_6583_SERIES)   
#define AUXADC_base			    	(0xA1003000)	//AUXADC
#endif //#if defined(DRV_ADC_6583_SERIES)  

#if defined(DRV_ADC_LIMIT_REG) || defined(FPGA)
#if !defined(DRV_ADC_OFF)
   /*******************
    * GPADC Registers *
    *******************/
   #define AUXADC_DATA  (AUXADC_base+0x0000)	/* Sampled data             */
   #define AUXADC_CTRL  (AUXADC_base+0x0004)	/* Control of A/D Converter */
   #define AUXADC_STAT  (AUXADC_base+0x0008)	/* A/D Status..reg=0,if write AUXADC_CTRL reg*/
   #define AUXADC_CTRL2 (AUXADC_base+0x000c)	/* Special Control of A/D Converter */
   
   #define AUXADC_STAT_RDY             0x0001      /*ADC ready*/
   
   #define AUXADC_CTRL2_CALI           0x0001      /*ADC Calibration*/
   #define AUXADC_CTRL2_MON            0x0020      /*DACMON*/
   #define AUXADC_CTRL2_BYP            0x0040      /*DACBYP*/
#endif // #if !defined(DRV_ADC_OFF)
   
   /*ADC pin selection, ADC phy. channel*/
  
   #define ADC_MAX_CHANNEL  5
   #define ADC_ERR_CHANNEL_NO       50
#endif   /*(DRV_ADC_LIMIT_REG,FPGA)*/
/*************************************************************************/
#if defined(DRV_ADC_BASIC_REG)
#if !defined(DRV_ADC_OFF)
   #define AUXADC_SYNC                    (AUXADC_base+0x0000)
   #define AUXADC_IMM                     (AUXADC_base+0x0004)
#if defined(DRV_ADC_6575_SERIES)   
   #define AUXADC_CON1_SET           	  (AUXADC_base+0x0008) 
   #define AUXADC_CON1_CLR           	  (AUXADC_base+0x000C) 
   #define AUXADC_SYN                     (AUXADC_base+0x0010)
   #define AUXADC_CON                     (AUXADC_base+0x0014)
   #define AUXADC_DAT(_line)              (AUXADC_base+0x0018+(4*_line))
#elif defined(DRV_ADC_6583_SERIES)   
   #define AUXADC_CON1_SET           	  (AUXADC_base+0x0008) 
   #define AUXADC_CON1_CLR           	  (AUXADC_base+0x000C) 
   #define AUXADC_CON                     (AUXADC_base+0x0010)
   #define AUXADC_DAT(_line)              (AUXADC_base+0x0014+(4*_line))
#else
	#define AUXADC_SYN					   (AUXADC_base+0x0008)
	#define AUXADC_CON					   (AUXADC_base+0x000c)
	#define AUXADC_DAT(_line)			   (AUXADC_base+0x0010+(4*_line))
#endif

#if defined(DRV_ADC_6256_SERIES)   
	#define AUX_CON2						(PLL_base+0x1708)
#else
	#define AUX_CON2						(ABBSYS_base+0x8708)
#endif

#if defined(DRV_ADC_6250_SERIES) 

	#define ABBA_WR_PATH0                   (ABBSYS_base + 0x0)
	#define ABB_WR_PATH0					(ABB_D_base + 0x0010)
	#define ABB_AUX_CON0					(ABB_D_base + 0x0028)
	#define ABB_RSV_CON1					(ABB_D_base + 0x0004)
	#define AUXADC_TS_CON						(AUXADC_base + 0x0058)


	#define ABBA_AUX_PWDB                    0x0100
    #define F26M_CLK_EN                 	 0x8000
    #define AUX_PWDB                     	 0x0100
    #define AUX_FIFO_CLK_EN			  		 0x8000
    #define AUX_FIFO_EN				         0x0080
	#define AUXADC_FSM_CTRL					 0x0040
	#define AUXADC_26M_CLK_CTRL				 0x0004
	#define AUXADC_TP_SPL                    0x0001
#endif

   /*AUXADC_SYNC*/
   #define AUXADC_SYNC_CHAN(_line)        (0x0001<<_line)   /*Time event 1*/
   
   /*AUXADC_IMM*/
   #define AUXADC_IMM_CHAN(_line)         (0x0001<<_line)
   
   /*AUXADC_SYN*/
   #define AUXADC_SYN_BIT                 (0x0001)          /*Time event 0*/
   
   /*AUXADC_CON*/
   #define AUXADC_CON_RUN                 (0x0001)
#ifndef DRV_ADC_NO_TEST_DACMON
   #define AUXADC_CON_CALI_MASK           (0x007c)
   #define AUXADC_CON_TESTDACMON          (0x0080)
#endif // #ifndef DRV_ADC_NO_TEST_DACMON
#if defined(DRV_ADC_SW_RESET)
   #define AUXADC_CON_SW_RESET            (0x0080)
#endif // #if defined(DRV_ADC_SW_RESET)
   #define AUXADC_CON_AUTOCLR0            (0x0100)
   #define AUXADC_CON_AUTOCLR1            (0x0200)
   #define AUXADC_CON_PUWAIT_EN           (0x0800)
   #define AUXADC_CON_AUTOSET             (0x8000)
#endif // #if !defined(DRV_ADC_OFF)


   #define ADC_ERR_CHANNEL_NO       50
#endif   /*(MT6205B,MT6218)*/

#if ( defined(DRV_ADC_BASIC_REG) || defined(DRV_ADC_TDMA_TIME) )
#if !defined(DRV_ADC_OFF)
   #if defined(DRV_ADC_TDMA_EVENT_REG_POS1)
   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x1c0)
   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x1c4)   
   #elif defined(DRV_ADC_TDMA_EVENT_REG_POS2)
   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x400)
   
   #if defined(MT6229_S00)
   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x400)/*HW bug*/
   #else
   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x404)/**/   
   #endif
   
   #else
   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x1b0)
   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x1b4)
   #endif
   
   #if defined(DRV_ADC_TDMA_EN_REG_POS1)
   #define AUXADC_TDMA_EN                 (TDMA_base+0x16C)
   #else
   #define AUXADC_TDMA_EN                 (TDMA_base+0x164)
   #endif
   /*AUXADC_TDMA_EN*/
   #define AUXADC_TDMA_EN_EVT0            (0x0001)
   #define AUXADC_TDMA_EN_EVT1            (0x0002)
#endif // #if !defined(DRV_ADC_OFF)
#endif // #if ( defined(DRV_ADC_BASIC_REG) || defined(DRV_ADC_TDMA_TIME) )


#if defined(__OLD_PDN_ARCH__)
#if defined(ADC_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(DRVPDN_CON0)
    #define ADC_CG_PDN_CON_BIT		(DRVPDN_CON0_AUXADC)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(CG_CON0)
    #define ADC_CG_PDN_CON_BIT		(CG_CON0_AUXADC)
  #endif // #if defined(__OLD_PDN_DEFINE__)
  
#elif defined(ADC_CG_PDN_CON1) // #if defined(ADC_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(DRVPDN_CON1)
    #define ADC_CG_PDN_CON_BIT		(DRVPDN_CON1_AUXADC)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(CG_CON1)
    #define ADC_CG_PDN_CON_BIT		(CG_CON1_AUXADC)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#elif defined(ADC_CG_PDN_CON3) // #if defined(ADC_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(DRVPDN_CON3)
    #define ADC_CG_PDN_CON_BIT		(DRVPDN_CON3_AUXADC)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(CG_CON3)
    #define ADC_CG_PDN_CON_BIT		(CG_CON3_AUXADC)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#else // #if defined(ADC_CG_PDN_CON0)
  #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(DRVPDN_CON2)
    #define ADC_CG_PDN_CON_BIT		(DRVPDN_CON2_AUXADC)
  #elif defined(__CLKG_DEFINE__) // #if defined(__OLD_PDN_DEFINE__)
    #define ADC_CG_PDN_CON_ADDR		(CG_CON2)
    #define ADC_CG_PDN_CON_BIT		(CG_CON2_AUXADC)
  #endif // #if defined(__OLD_PDN_DEFINE__)
#endif // #if defined(ADC_CG_PDN_CON0)
#endif // #if defined(__OLD_PDN_ARCH__)


#if defined(DRV_ADC_NOT_EXIST)
   #define ADC_ERR_CHANNEL_NO       50
#endif // #if defined(DRV_ADC_NOT_EXIST)

#if !defined(DRV_ADC_OFF)
#if !defined(ADC_MAX_CHANNEL)
   #define ADC_MAX_CHANNEL  1
   #define ADC_ERR_CHANNEL_NO       50
#endif // #if defined(DRV_ADC_NOT_EXIST)
#endif // #if !defined(DRV_ADC_OFF)

#endif   /*_ADC_HW_H*/

