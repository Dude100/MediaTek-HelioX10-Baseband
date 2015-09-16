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
 *    adc_sw.h
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
#ifndef _ADC_SW_H
#define _ADC_SW_H 

#include "drv_features_adc.h"
#include "adc_hw.h"
#include "adc_cali.h"

typedef struct {
	double  ADC_ISENSE_RESISTANCE_FACTOR;        /*1/0.4*/
	ADC_CALIDATA adc_cali_param;              /*ratio = adc_volt_factor/100*/
	kal_uint16 adc_volt_factor[ADC_MAX_CHANNEL];   
}adc_customized_struct;

typedef struct {
   kal_int32  TEMPV2;
   kal_int32  TEMPA12;   
   kal_int32  TEMPA23;  
   kal_int32  TEMPM12;
   kal_int32  TEMPM23;
   kal_int32  TEMPSCALE;
} VolToTempStruct;

typedef enum {
   vbat_adc_channel=0,
   visense_adc_channel,
   vbattmp_adc_channel,
   battype_adc_channel,
   vcharger_adc_channel,
   pcbtmp_adc_channel,
   aux_adc_channel,
   chr_usb_adc_channel,
   otg_vbus_adc_channel,
   rftmp_adc_channel
} adc_channel_type;


/*************************************************************************/
#if defined(DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK)
// Define to perform ADC race condition check when processing critical data process
#define ADC_RACE_CONDITION_CHECK
// Define to remove IRQ mask/restore for ADC measurement
#define ADC_REMOVE_IRQMASK
#endif // #if defined(DRV_MISC_ADC_MEASURE_REMOVE_IRQMASK)

#if defined(ADC_RACE_CONDITION_CHECK)
extern kal_bool gADC_RC_Check;
// MoDIS parser skip start
// The following two APIs are private APIs, NOT exported as public APIs
extern void ADCRCCheckAndLock(void);
extern void ADCRCRelease(void);
// MoDIS parser skip end
#endif // #if defined(ADC_RACE_CONDITION_CHECK)

#if defined(ADC_REMOVE_IRQMASK)
#define ADCSAVEANDSETIRQMASK(mask)	{}
#define ADCRESTOREIRQMASK(mask)		{}
#else // #if defined(ADC_REMOVE_IRQMASK)
#define ADCSAVEANDSETIRQMASK(mask)	{mask = SaveAndSetIRQMask();}
#define ADCRESTOREIRQMASK(mask)		RestoreIRQMask(mask)
#endif // #if defined(ADC_REMOVE_IRQMASK)

extern void dbg_print(char *fmt,...);

/*************************************************************************/
// MoDIS parser skip start
// The following APIs are private APIs
extern kal_uint16 ADC_GetData(kal_uint8 sel);
// adc.c
extern kal_int32 adc_measureVoltage(kal_uint8 chann, double *adc_value);
extern void adc_read_calibration_data(void);
extern kal_uint16 ADC_IMM_Data(kal_uint16 channel);
extern kal_uint16 ADC_SYNC_Data(kal_uint16 channel);
extern void ADC_Init(void);
extern void adc_pwrdown_enable(void);
extern void adc_pwrdown_disable(void);
extern kal_uint32 ADC_GetData2Meta(kal_uint8 sel, kal_uint16 meacount);
extern kal_uint32 ADC_GetMeaData(kal_uint8 sel, kal_uint16 meacount);
extern void ADC_IMM_Data_on_Booting(kal_uint32 channel, kal_uint32 counts, kal_uint16 * data);
extern kal_int16 ADC_GetImmTemp(kal_uint8 chann);
extern kal_int16 ADC_GetPhysicalChannel(kal_uint16 adcname);

// MoDIS parser skip end

#if !defined(DRV_ADC_OFF)
#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ADC_REG_DBG__)
#define DRV_ADC_WriteReg(addr,data)              DRV_DBG_WriteReg(addr,data)
#define DRV_ADC_Reg(addr)                        DRV_DBG_Reg(addr)                      
#define DRV_ADC_WriteReg32(addr,data)            DRV_DBG_WriteReg32(addr,data)          
#define DRV_ADC_Reg32(addr)                      DRV_DBG_Reg32(addr)                    
#define DRV_ADC_WriteReg8(addr,data)             DRV_DBG_WriteReg8(addr,data)           
#define DRV_ADC_Reg8(addr)                       DRV_DBG_Reg8(addr)                     
#define DRV_ADC_ClearBits(addr,data)             DRV_DBG_ClearBits(addr,data)           
#define DRV_ADC_SetBits(addr,data)               DRV_DBG_SetBits(addr,data)             
#define DRV_ADC_SetData(addr, bitmask, value)    DRV_DBG_SetData(addr, bitmask, value)  
#define DRV_ADC_ClearBits32(addr,data)           DRV_DBG_ClearBits32(addr,data)         
#define DRV_ADC_SetBits32(addr,data)             DRV_DBG_SetBits32(addr,data)           
#define DRV_ADC_SetData32(addr, bitmask, value)  DRV_DBG_SetData32(addr, bitmask, value)
#define DRV_ADC_ClearBits8(addr,data)            DRV_DBG_ClearBits8(addr,data)          
#define DRV_ADC_SetBits8(addr,data)              DRV_DBG_SetBits8(addr,data)            
#define DRV_ADC_SetData8(addr, bitmask, value)   DRV_DBG_SetData8(addr, bitmask, value) 
#else
#define DRV_ADC_WriteReg(addr,data)              DRV_WriteReg(addr,data)
#define DRV_ADC_Reg(addr)                        DRV_Reg(addr)                      
#define DRV_ADC_WriteReg32(addr,data)            DRV_WriteReg32(addr,data)          
#define DRV_ADC_Reg32(addr)                      DRV_Reg32(addr)                    
#define DRV_ADC_WriteReg8(addr,data)             DRV_WriteReg8(addr,data)           
#define DRV_ADC_Reg8(addr)                       DRV_Reg8(addr)                     
#define DRV_ADC_ClearBits(addr,data)             DRV_ClearBits(addr,data)           
#define DRV_ADC_SetBits(addr,data)               DRV_SetBits(addr,data)             
#define DRV_ADC_SetData(addr, bitmask, value)    DRV_SetData(addr, bitmask, value)  
#define DRV_ADC_ClearBits32(addr,data)           DRV_ClearBits32(addr,data)         
#define DRV_ADC_SetBits32(addr,data)             DRV_SetBits32(addr,data)           
#define DRV_ADC_SetData32(addr, bitmask, value)  DRV_SetData32(addr, bitmask, value)
#define DRV_ADC_ClearBits8(addr,data)            DRV_ClearBits8(addr,data)          
#define DRV_ADC_SetBits8(addr,data)              DRV_SetBits8(addr,data)            
#define DRV_ADC_SetData8(addr, bitmask, value)   DRV_SetData8(addr, bitmask, value) 
#endif //#if defined(__DRV_COMM_REG_DBG__) && defined(__DRV_ADC_REG_DBG__)

#else //!defined(DRV_ADC_OFF)

#define DRV_ADC_WriteReg(addr,data)              
#define DRV_ADC_Reg(addr)                        drv_dummy_return()
#define DRV_ADC_WriteReg32(addr,data)            
#define DRV_ADC_Reg32(addr)                      drv_dummy_return()
#define DRV_ADC_WriteReg8(addr,data)             
#define DRV_ADC_Reg8(addr)                       drv_dummy_return()
#define DRV_ADC_ClearBits(addr,data)             
#define DRV_ADC_SetBits(addr,data)               
#define DRV_ADC_SetData(addr, bitmask, value)    
#define DRV_ADC_ClearBits32(addr,data)           
#define DRV_ADC_SetBits32(addr,data)             
#define DRV_ADC_SetData32(addr, bitmask, value)  
#define DRV_ADC_ClearBits8(addr,data)            
#define DRV_ADC_SetBits8(addr,data)              
#define DRV_ADC_SetData8(addr, bitmask, value)   

#endif //!defined(DRV_ADC_OFF)

#endif   /*_ADC_SW_H*/

