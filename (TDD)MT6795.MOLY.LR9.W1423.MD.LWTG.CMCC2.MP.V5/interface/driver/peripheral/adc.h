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
 *    adc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for GPT driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _ADC_H
#define _ADC_H 

//#include "adc_hw.h"
//#include "adc_sw.h"
//#include "adc_channel.h" //remove this when check in MAUI. remind UEM not use ADC_VBAT

//#include "drv_features.h"
//#include "adc_channel.h"
//
//typedef enum {
//   vbat_adc_channel=0,
//   visense_adc_channel,
//   vbattmp_adc_channel,
//   battype_adc_channel,
//   vcharger_adc_channel,
//   pcbtmp_adc_channel,
//   aux_adc_channel,
//   chr_usb_adc_channel,
//   otg_vbus_adc_channel,
//   rftmp_adc_channel
//} adc_channel_type;
//
///*
//1. Check bit of ADC (1b), *(0x80000020)[18]=[210]
//2. ADC_B (6b), *(0x80000020)[17:12]=[209:204]
//3. ADC_A (7b), *(0x80000020)[11:5]=[203:197]
//*/
//#define EFUSE_ADC_BASE 0x80000020
//#define EFUSE_ADC_A 0x80000020
//#define EFUSE_ADC_B 0x80000020
//#define EFUSE_ADC_ENABLE 0x40000
//#define EFUSE_ADC_A_MASK 0xFE0
//#define EFUSE_ADC_B_MASK 0x3F000
//#define EFUSE_ADC_A_SHIFT 5
//#define EFUSE_ADC_B_SHIFT 12
//
//
//#if defined(DRV_ADC_LIMIT_REG) || defined(FPGA)
//#if !defined(DRV_ADC_OFF)
//   /*******************
//    * GPADC Registers *
//    *******************/
//   #define AUXADC_DATA  (AUXADC_base+0x0000)	/* Sampled data             */
//   #define AUXADC_CTRL  (AUXADC_base+0x0004)	/* Control of A/D Converter */
//   #define AUXADC_STAT  (AUXADC_base+0x0008)	/* A/D Status..reg=0,if write AUXADC_CTRL reg*/
//   #define AUXADC_CTRL2 (AUXADC_base+0x000c)	/* Special Control of A/D Converter */
//   
//   #define AUXADC_STAT_RDY             0x0001      /*ADC ready*/
//   
//   #define AUXADC_CTRL2_CALI           0x0001      /*ADC Calibration*/
//   #define AUXADC_CTRL2_MON            0x0020      /*DACMON*/
//   #define AUXADC_CTRL2_BYP            0x0040      /*DACBYP*/
//#endif // #if !defined(DRV_ADC_OFF)
//   
//   /*ADC pin selection, ADC phy. channel*/
//  
//   #define ADC_MAX_CHANNEL  5
//   #define ADC_ERR_CHANNEL_NO       50
//#endif   /*(DRV_ADC_LIMIT_REG,FPGA)*/
///*************************************************************************/
//#if defined(DRV_ADC_BASIC_REG)
//#if !defined(DRV_ADC_OFF)
//   #define AUXADC_SYNC                    (AUXADC_base+0x0000)
//   #define AUXADC_IMM                     (AUXADC_base+0x0004)
//   #define AUXADC_SYN                     (AUXADC_base+0x0008)
//   #define AUXADC_CON                     (AUXADC_base+0x000c)
//   #define AUXADC_DAT(_line)              (AUXADC_base+0x0010+(4*_line))
//
//   /*AUXADC_SYNC*/
//   #define AUXADC_SYNC_CHAN(_line)        (0x0001<<_line)   /*Time event 1*/
//   
//   /*AUXADC_IMM*/
//   #define AUXADC_IMM_CHAN(_line)         (0x0001<<_line)
//   
//   /*AUXADC_SYN*/
//   #define AUXADC_SYN_BIT                 (0x0001)          /*Time event 0*/
//   
//   /*AUXADC_CON*/
//   #define AUXADC_CON_RUN                 (0x0001)
//#ifndef DRV_ADC_NO_TEST_DACMON
//   #define AUXADC_CON_CALI_MASK           (0x007c)
//   #define AUXADC_CON_TESTDACMON          (0x0080)
//#endif // #ifndef DRV_ADC_NO_TEST_DACMON
//#if defined(DRV_ADC_SW_RESET)
//   #define AUXADC_CON_SW_RESET            (0x0080)
//#endif // #if defined(DRV_ADC_SW_RESET)
//   #define AUXADC_CON_AUTOCLR0            (0x0100)
//   #define AUXADC_CON_AUTOCLR1            (0x0200)
//   #define AUXADC_CON_PUWAIT_EN           (0x0800)
//   #define AUXADC_CON_AUTOSET             (0x8000)
//#endif // #if !defined(DRV_ADC_OFF)
//
//
//
//   #if defined(DRV_ADC_MAX_CH_5)
//      #define ADC_MAX_CHANNEL  5
//   #endif   /*DRV_ADC_MAX_CH_5*/
//   
//   #if defined(DRV_ADC_MAX_CH_6)
//      #define ADC_MAX_CHANNEL  6
//   #endif   /*DRV_ADC_MAX_CH_6*/
//
//   #if defined(DRV_ADC_MAX_CH_7)
//      #define ADC_MAX_CHANNEL  7
//   #endif   /*DRV_ADC_MAX_CH_7*/
//   
//   #if defined(DRV_ADC_MAX_CH_8)
//      #define ADC_MAX_CHANNEL  8
//   #endif   /*DRV_ADC_MAX_CH_8*/
//   
//   #if defined(DRV_ADC_MAX_CH_9)
//      #define ADC_MAX_CHANNEL  9
//   #endif   /*DRV_ADC_MAX_CH_9*/
//   
//   #if defined(DRV_ADC_MAX_CH_10)
//      #define ADC_MAX_CHANNEL  10
//   #endif   /*DRV_ADC_MAX_CH_10*/
//   
//   #if defined(DRV_ADC_MAX_CH_13)
//      #define ADC_MAX_CHANNEL  13
//   #endif   /*DRV_ADC_MAX_CH_10*/
//
//   #define ADC_ERR_CHANNEL_NO       50
//#endif   /*(MT6205B,MT6218)*/
//
//#if ( defined(DRV_ADC_BASIC_REG) || defined(DRV_ADC_TDMA_TIME) )
//#if !defined(DRV_ADC_OFF)
//   #if defined(DRV_ADC_TDMA_EVENT_REG_POS1)
//   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x1c0)
//   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x1c4)   
//   #elif defined(DRV_ADC_TDMA_EVENT_REG_POS2)
//   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x400)
//   
//   #if defined(MT6229_S00)
//   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x400)/*HW bug*/
//   #else
//   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x404)/**/   
//   #endif
//   
//   #else
//   #define AUXADC_TDMA_EVENT0             (TDMA_base+0x1b0)
//   #define AUXADC_TDMA_EVENT1             (TDMA_base+0x1b4)
//   #endif
//   
//   #if defined(DRV_ADC_TDMA_EN_REG_POS1)
//   #define AUXADC_TDMA_EN                 (TDMA_base+0x16C)
//   #else
//   #define AUXADC_TDMA_EN                 (TDMA_base+0x164)
//   #endif
//   /*AUXADC_TDMA_EN*/
//   #define AUXADC_TDMA_EN_EVT0            (0x0001)
//   #define AUXADC_TDMA_EN_EVT1            (0x0002)
//#endif // #if !defined(DRV_ADC_OFF)
//#endif // #if ( defined(DRV_ADC_BASIC_REG) || defined(DRV_ADC_TDMA_TIME) )
//
//
//#if defined(DRV_ADC_NOT_EXIST)
//   #define ADC_MAX_CHANNEL  1
//   #define ADC_ERR_CHANNEL_NO       50
//#endif // #if defined(DRV_ADC_NOT_EXIST)
//
//#if !defined(DRV_ADC_OFF)
//#if !defined(ADC_MAX_CHANNEL)
//   #define ADC_MAX_CHANNEL  1
//   #define ADC_ERR_CHANNEL_NO       50
//#endif // #if defined(DRV_ADC_NOT_EXIST)
//#endif // #if !defined(DRV_ADC_OFF)
//
//#if 1
//   typedef struct
//   {
//      kal_int32 ADCSlope[ADC_MAX_CHANNEL];
//      kal_int32 ADCOffset[ADC_MAX_CHANNEL];
//   }ADC_CALIDATA;
//#else
//   typedef struct
//   {
//      kal_int32 ADCSlope[ADC_MAX_CHANNEL];
//      kal_int32 ADCOffset[ADC_MAX_CHANNEL];
//   }ADC_CALIDATA;
//#endif
///*************************************************************************/
//#if defined(DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK)
//// Define to perform ADC race condition check when processing critical data process
//#define ADC_RACE_CONDITION_CHECK
//// Define to remove IRQ mask/restore for ADC measurement
//#define ADC_REMOVE_IRQMASK
//#endif // #if defined(DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK)
//
//#if defined(ADC_RACE_CONDITION_CHECK)
//extern kal_bool gADC_RC_Check;
//// MoDIS parser skip start
//// The following two APIs are private APIs, NOT exported as public APIs
//extern void ADCRCCheckAndLock(void);
//extern void ADCRCRelease(void);
//// MoDIS parser skip end
//#endif // #if defined(ADC_RACE_CONDITION_CHECK)
//
//#if defined(ADC_REMOVE_IRQMASK)
//#define ADCSAVEANDSETIRQMASK(mask)	{}
//#define ADCRESTOREIRQMASK(mask)		{}
//#else // #if defined(ADC_REMOVE_IRQMASK)
//#define ADCSAVEANDSETIRQMASK(mask)	{mask = SaveAndSetIRQMask();}
//#define ADCRESTOREIRQMASK(mask)		RestoreIRQMask(mask)
//#endif // #if defined(ADC_REMOVE_IRQMASK)
//
///*************************************************************************/
//
//// MoDIS parser skip start
//// The following APIs are private APIs
//extern kal_uint16 ADC_GetData(kal_uint8 sel);
//// adc.c
//extern kal_uint16 ADC_IMM_Data(kal_uint16 channel);
//extern kal_uint16 ADC_SYNC_Data(kal_uint16 channel);
//extern void ADC_Init(void);
//
//// MoDIS parser skip end
//
//#if !defined(DRV_ADC_OFF)
//#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ADC_REG_DBG__)
//#define DRV_ADC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
//#define DRV_ADC_Reg(addr)                        DRV_DBG_Reg(addr)                      
//#define DRV_ADC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
//#define DRV_ADC_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
//#define DRV_ADC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
//#define DRV_ADC_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
//#define DRV_ADC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
//#define DRV_ADC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
//#define DRV_ADC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
//#define DRV_ADC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
//#define DRV_ADC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
//#define DRV_ADC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
//#define DRV_ADC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
//#define DRV_ADC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
//#define DRV_ADC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
//#else
//#define DRV_ADC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
//#define DRV_ADC_Reg(addr)                        DRV_Reg(addr)                      
//#define DRV_ADC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
//#define DRV_ADC_Reg32(addr)                      DRV_Reg32(addr)                    
//#define DRV_ADC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
//#define DRV_ADC_Reg8(addr)                       DRV_Reg8(addr)                     
//#define DRV_ADC_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
//#define DRV_ADC_SetBits(addr,data)               DRV_SetBits(addr,data)             
//#define DRV_ADC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
//#define DRV_ADC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
//#define DRV_ADC_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
//#define DRV_ADC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
//#define DRV_ADC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
//#define DRV_ADC_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
//#define DRV_ADC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
//#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ADC_REG_DBG__)
//
//#else //!defined(DRV_ADC_OFF)
//
//#define DRV_ADC_WriteReg(addr,data)              
//#define DRV_ADC_Reg(addr)                        drv_dummy_return()
//#define DRV_ADC_WriteReg32(addr,data)            
//#define DRV_ADC_Reg32(addr)                      drv_dummy_return()
//#define DRV_ADC_WriteReg8(addr,data)             
//#define DRV_ADC_Reg8(addr)                       drv_dummy_return()
//#define DRV_ADC_ClearBits(addr,data)             
//#define DRV_ADC_SetBits(addr,data)               
//#define DRV_ADC_SetData(addr, bitmask, value)    
//#define DRV_ADC_ClearBits32(addr,data)           
//#define DRV_ADC_SetBits32(addr,data)             
//#define DRV_ADC_SetData32(addr, bitmask, value)  
//#define DRV_ADC_ClearBits8(addr,data)            
//#define DRV_ADC_SetBits8(addr,data)              
//#define DRV_ADC_SetData8(addr, bitmask, value)   
//
//#endif //!defined(DRV_ADC_OFF)

#endif   /*_ADC_H*/

