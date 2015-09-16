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
 *    adc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the auxiliary ADC driver and adaption layer.
 *
 * Author:
 * -------
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
#include "drv_features.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "adc_hw.h"
#include "adc_sw.h"
#include "drvpdn.h"
#include "rtc_hw.h"
#include "bmt.h"
#include "adcsche.h"
#include "kal_public_api.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif   /*__MULTI_BOOT__*/

#if (defined(DRV_ADC_FULL_FUNC) || defined(DRV_ADC_TDMA_TIME) )
extern void adc_tdma_time_setup(kal_uint16 idle_time, kal_uint16 trx_time);
#endif   /*DRV_ADC_TDMA_TIME*/
#if defined(DRV_ADC_TDMA_TIME)
#include "l1_interface.h"
#endif   /*DRV_ADC_TDMA_TIME*/
#include "dcl.h"

// For RHR ADD
#include "adc_channel.h"
#include "init.h"

extern kal_bool adc_sync_mode_on;
extern kal_uint16 adc_imm_mode_cnt;
extern kal_uint32 adc_sche_rw_status;

#if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
kal_bool ADCIMMModeActive;
#endif // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)

#if defined(DRV_ADC_OFF)
   #if !defined(DRV_ADC_NOT_EXIST)
   #define DRV_ADC_NOT_EXIST
   #endif
#endif

extern const kal_uint8 ADC_VBAT;
extern const kal_uint8 ADC_VISENSE;
extern const kal_uint8 ADC_VCHARGER;



/*
* FUNCTION
*	   adc_pwrdown_enable
*
* DESCRIPTION                                                           
*   	This function is to enable adc power down control
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     Note that this function must be called between SaveAndSetIRQMask()
*   and RestoreIRQMask().
*/
#if (defined(__MTK_TARGET__) && defined(ADC_INTERNAL_SRAM))
__attribute__ ((section ("INTERNCODE"))) 
#endif /* __MTK_TARGET__ */
void adc_pwrdown_enable(void)
{
#ifndef DRV_ADC_NOT_EXIST
#ifndef DRV_ADC_NO_PDN

   #if (!defined(DRV_ADC_6208_PWRDOWN)) && (!defined(DRV_ADC_MODEM_SIDE))
   if((adc_sche_rw_status==0)&&!(DRV_ADC_Reg(AUXADC_CON) & AUXADC_CON_RUN))
   #endif // #if (!defined(DRV_ADC_6208_PWRDOWN)) && (!defined(DRV_ADC_MODEM_SIDE))
   {
      #if defined(__OLD_PDN_ARCH__)
      #ifdef ADC_DRVPDN_FAST
      DRVPDN_ENABLE2(ADC_CG_PDN_CON_ADDR,ADC_CG_PDN_CON_BIT,PDN_ADC);
      #else /*ADC_DRVPDN_FAST*/
      DRVPDN_Enable(ADC_CG_PDN_CON_ADDR,ADC_CG_PDN_CON_BIT,PDN_ADC);
      #endif /*ADC_DRVPDN_FAST*/
      #else // #if defined(__OLD_PDN_ARCH__)
      #ifdef ADC_DRVPDN_FAST
      DRVPDN_ENABLE2(PDN_ADC);
      #else /*ADC_DRVPDN_FAST*/
      DRVPDN_Enable(PDN_ADC);
      #endif /*ADC_DRVPDN_FAST*/
      #endif // #if defined(__OLD_PDN_ARCH__)
   }

#endif //#ifndef DRV_ADC_NO_PDN
#endif // #ifndef DRV_ADC_NOT_EXIST

}

/*
* FUNCTION
*	   adc_pwrdown_disable
*
* DESCRIPTION                                                           
*   	This function is to disable adc power down control
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     Note that this function must be called between SaveAndSetIRQMask()
*   and RestoreIRQMask().
*/
#if (defined(__MTK_TARGET__) && defined(ADC_INTERNAL_SRAM))
__attribute__ ((section ("INTERNCODE"))) 
#endif 
void adc_pwrdown_disable(void)
{
#ifndef DRV_ADC_NOT_EXIST
#ifndef DRV_ADC_NO_PDN

   #if defined(__OLD_PDN_ARCH__)
   #ifdef ADC_DRVPDN_FAST
	DRVPDN_DISABLE2(ADC_CG_PDN_CON_ADDR,ADC_CG_PDN_CON_BIT,PDN_ADC);
   #else /*ADC_DRVPDN_FAST*/
	DRVPDN_Disable(ADC_CG_PDN_CON_ADDR,ADC_CG_PDN_CON_BIT,PDN_ADC);
   #endif /*ADC_DRVPDN_FAST*/
   #else // #if defined(__OLD_PDN_ARCH__)
   #ifdef ADC_DRVPDN_FAST
	DRVPDN_DISABLE2(PDN_ADC);
   #else /*ADC_DRVPDN_FAST*/
	DRVPDN_Disable(PDN_ADC);
   #endif /*ADC_DRVPDN_FAST*/
   #endif // #if defined(__OLD_PDN_ARCH__)
   
#endif //#ifdef DRV_ADC_NO_PDN
#endif // #ifndef DRV_ADC_NOT_EXIST
}


/*
* FUNCTION                                                            
*	ADC_GetData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the measured data
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*	
* RETURNS
*	return the value of ADC output
*
* GLOBALS AFFECTED
*   external_global
*/
/*must add power on function before this function*/
#if (defined(__MTK_TARGET__) && defined(DRV_MISC_ADD_ADC_GETDATA_TO_INTERNAL_RAM))
__attribute__ ((section ("INTERNCODE"))) 
#endif 
kal_uint16 ADC_GetData(kal_uint8 sel)
{
#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)

#ifndef DRV_ADC_NOT_EXIST

#if defined(DRV_ADC_MODEM_SIDE)
   kal_uint32 saved_current_time = 0;
#endif
   kal_uint16 data;
#if !defined(ADC_REMOVE_IRQMASK)
   kal_uint32 savedMask;
#endif //#if !defined(ADC_REMOVE_IRQMASK)   
#if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
	kal_uint32 savedMask2;
#else
   kal_uint16 i;
#endif // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
   
   #ifdef __MULTI_BOOT__
      //ASSERT(kal_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   ASSERT(sel < ADC_MAX_CHANNEL);
   
#if defined(DRV_ADC_NO_IMM) || defined(FPGA)
   ADCSAVEANDSETIRQMASK(savedMask);  //savedMask = SaveAndSetIRQMask();	
   adc_pwrdown_disable();
#ifndef DRV_ADC_MODEM_SIDE
   DRV_ADC_WriteReg(AUXADC_CTRL,sel);
#endif // #ifndef DRV_ADC_MODEM_SIDE
   adc_imm_mode_cnt++;
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
   while(!(DRV_ADC_Reg(AUXADC_STAT) & AUXADC_STAT_RDY));
   data = DRV_ADC_Reg(AUXADC_DATA);
#endif   /*(DRV_ADC_NO_IMM,FPGA)*/
#if defined(DRV_ADC_IMM)
   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
   adc_imm_mode_cnt++;
   adcsche_adc_measure_en(KAL_TRUE);
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);

   #if defined(__DRV_ADC_PMIC_TURN_ON_MEASURE_DELAY__)
   if((ADC_VBAT == sel)    ||
   	  (ADC_VISENSE == sel) ||
   	  (ADC_VCHARGER == sel))
   {
      kal_sleep_task(1); //delay 2 frames for HEPHAESTUS68 need delay to measure
   }
   #endif //#if defined(__DRV_ADC_PMIC_TURN_ON_MEASURE_DELAY__)

   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
   adc_pwrdown_disable();
#if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
	{
		savedMask2 = SaveAndSetIRQMask();
	}
#endif // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)

#if defined(DRV_ADC_VCHARGER_EXTEND_READING)   	
   if(ADC_VCHARGER == sel)
   {
	DRV_ADC_SetBits(MIX_ABB_base + 0x0b00,0x01f0);	//extend to MAX ticks while reading 
   }
#endif

#ifdef DRV_ADC_SET_CLR
   DRV_ADC_SetBits(AUXADC_CON1_CLR, (1<<sel));
   DRV_ADC_SetBits(AUXADC_CON1_SET, (1<<sel));
#else
   DRV_ADC_WriteReg(AUXADC_IMM, 0);
   //DRV_ADC_Reg(AUXADC_IMM) = 0;
   DRV_ADC_SetBits(AUXADC_IMM, (1<<sel));
   //DRV_ADC_Reg(AUXADC_IMM) |= (1<<sel);
#endif   
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
#if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
	{
		volatile kal_uint32 tmp_32;
		for (tmp_32=20;tmp_32!=0;tmp_32--){
			;
		}
	}
#else // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
   for(i=100;i!=0;i--);		/* delay for avoid reading invalid status bit */   
#endif // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)

#if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)
	{
		RestoreIRQMask(savedMask2);
	}
#endif // #if defined(DRV_MT6268A_ADC_TP_MIXED_ISSUE_WA)

#if !defined(DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK)
#if defined(DRV_ADC_MODEM_SIDE)
#ifdef DRV_ADC_SET_CLR
  while((DRV_ADC_Reg(AUXADC_CON) & AUXADC_CON_RUN));
#else  
  while((DRV_ADC_Reg(AUXADC_DAT(sel)) & 0x1000) == 0x1000);
#endif   
#else
   while((DRV_ADC_Reg(AUXADC_CON) & AUXADC_CON_RUN));
#endif   
#endif // #if !defined(DRV_MISC_IGNORE_ADC_RUN_STATUS_CHECK)

       
   data = (DRV_ADC_Reg(AUXADC_DAT(sel)) & 0x0FFF);
#if defined(DRV_ADC_MODEM_SIDE)
   saved_current_time = drv_get_current_time();
   while(drv_get_duration_tick(saved_current_time, drv_get_current_time()) <= 2) // 64us
   {
      ;// Polling 32K reference clock
   }
#endif   
#endif   /*DRV_ADC_IMM*/
   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
   adc_imm_mode_cnt--;
   if ((((kal_uint16)adc_imm_mode_cnt) == 0) && (((kal_bool)adc_sync_mode_on) == KAL_FALSE))
   {
      adc_pwrdown_enable();
   }
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);
   ADCSAVEANDSETIRQMASK(savedMask);	//savedMask = SaveAndSetIRQMask();	
   if ((((kal_uint16)adc_imm_mode_cnt) == 0) && (((kal_bool)adc_sync_mode_on) == KAL_FALSE))
   {
   	#if !defined(DRV_ADC_MODEM_SIDE)	//don't write pmu bit to 0
      adcsche_adc_measure_en(KAL_FALSE);
	#endif
   }
   ADCRESTOREIRQMASK(savedMask); //RestoreIRQMask(savedMask);

   return data;

#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
* FUNCTION                                                            
*	ADC_GetMeaData
*
* DESCRIPTION                                                           
*   	This function is to run ADC, and obtain the average value of measured data
*     Note that: This function only called before other tasks are running.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetMeaData(kal_uint8 sel, kal_uint16 meacount)
{
#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)

#ifndef DRV_ADC_NOT_EXIST

   kal_uint32 index;
   kal_uint32 sum=0;
   #ifdef __MULTI_BOOT__
      ASSERT(kal_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   //DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_disable();
   for(index=meacount;index!=0;index--)
   {
      sum += (kal_uint32)ADC_GetData(sel);
   }
   //DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_enable();
   sum = sum/meacount;
   return sum;

#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
* FUNCTION                                                            
*	ADC_GetData2Meta
*
* DESCRIPTION                                                           
*   	This function is called by META, and return the sum value.
*
* CALLS  
*
* PARAMETERS
*	sel :  selection of input signal source(0-4)
*  meacount: measure count
*	
* RETURNS
*	return the average value of ADC output
*
* GLOBALS AFFECTED
*   None
*/
kal_uint32 ADC_GetData2Meta(kal_uint8 sel, kal_uint16 meacount)
{
#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)

#ifndef DRV_ADC_NOT_EXIST
   kal_uint32 index;
   kal_uint32 sum=0;
   #ifdef __MULTI_BOOT__
      ASSERT(kal_query_boot_mode() == FACTORY_BOOT);
   #endif   /*__MULTI_BOOT__*/
   //DRVPDN_Disable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_disable();
   for(index=meacount;index!=0;index--)
   {
      sum += (kal_uint32)ADC_GetData(sel);
   }
   //DRVPDN_Enable(DRVPDN_CON2,DRVPDN_CON2_AUXADC,PDN_ADC);
   //adc_pwrdown_enable();
   return sum;
#endif // #ifndef DRV_ADC_NOT_EXIST
}

void ADC_Init(void)
{
#if (!defined(DRV_ADC_NOT_EXIST)) && (!defined(DRV_ADC_MODEM_SIDE))

#if defined(DRV_ADC_TDMA_TIME)
   adc_tdma_time_setup(0,6000);
   #ifndef DRV_ADC_NO_TEST_DACMON
   DRV_ADC_WriteReg(AUXADC_CON,(AUXADC_CON_AUTOCLR0|AUXADC_CON_AUTOCLR1|AUXADC_CON_PUWAIT_EN|AUXADC_CON_TESTDACMON|0x0018));
   #endif // #ifndef DRV_ADC_NO_TEST_DACMON
   #if defined(DRV_ADC_SW_RESET)
   DRV_ADC_WriteReg(AUXADC_CON,(AUXADC_CON_AUTOCLR0|AUXADC_CON_AUTOCLR1|AUXADC_CON_PUWAIT_EN));
   #endif // #if defined(DRV_ADC_SW_RESET)

   #ifdef DRV_ADC_NO_PUWAIT_EN
   DRV_ADC_ClearBits(AUXADC_CON,AUXADC_CON_PUWAIT_EN);
   #endif

#if defined(DRV_ADC_DELAY_FOR_ADCCAP )
	/* AuxADC sampling period control */
	DRV_ADC_SetBits(AUX_CON2,0x0064);	//delay 25us
#endif
   
   #if defined(DRV_ADC_BIAS_CURRENT_ENLARGE)
   {
   	ECO_VERSION MT6276ipVersion = INT_ecoVersion();
	if(ECO_E2 == MT6276ipVersion)
	{
		DRV_ADC_WriteReg((MIX_ABB_base + 0x0B00),0x0022);	//AUX_CON0
	}	
   }
   #endif
	
#ifndef DRV_ADC_NO_ADC_DEF_CONFIG

#if defined(DRV_AUX_AC_CON_DEF_F)
   /*AUX_AC_CON*/
   DRV_ADC_WriteReg(0x80500700,0x00f);
#endif   
#if defined(DRV_AUX_AC_CON_DEF_0)
   /*AUX_AC_CON*/
   DRV_ADC_WriteReg(0x80500700,0x0);
#endif   

#if defined(DRV_AUX_AC_CON_DEF_X)
   /*AUX_AC_CON*/
   if(DRV_ADC_Reg(0x80500004)==0x8c01)
   {      
      DRV_ADC_WriteReg(0x80500700,0xf);
   } 
   else if(DRV_ADC_Reg(0x80500004)==0x8d00)
   {
      DRV_ADC_WriteReg(0x80500700,0x0);
   }
   else if(DRV_ADC_Reg(0x80500004)==0x8d01)
   {
      DRV_ADC_WriteReg(0x80500700,0x0);
   }
         
#endif   /*DRV_AUX_AC_CON_DEF_X*/

#endif // #ifndef DRV_ADC_NO_ADC_DEF_CONFIG

#endif   /*DRV_ADC_TDMA_TIME*/

#endif // #if (!defined(DRV_ADC_NOT_EXIST)) && (!defined(DRV_ADC_MODEM_SIDE))
}


// Add variable to check ADC race condition
#if defined(ADC_RACE_CONDITION_CHECK)
kal_bool gADC_RC_Check = KAL_FALSE;
void ADCRCCheckAndLock(void){
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	if (gADC_RC_Check == KAL_TRUE){
		ASSERT(0);
	}
	gADC_RC_Check = KAL_TRUE;
	RestoreIRQMask(savedMask);
}
void ADCRCRelease(void){
	kal_uint32 savedMask;
	savedMask = SaveAndSetIRQMask();
	if (gADC_RC_Check == KAL_FALSE){
		ASSERT(0);
	}
	gADC_RC_Check = KAL_FALSE;
	RestoreIRQMask(savedMask);
}
#endif // #if defined(ADC_RACE_CONDITION_CHECK)

/*
   ADC IMM sample command only
   This function is exported for DCL only
*/
kal_uint16 ADC_IMM_Data(kal_uint16 channel){

#ifndef DRV_ADC_NOT_EXIST
	kal_uint16 data;
	kal_uint32 i;
#endif //#ifndef DRV_ADC_NOT_EXIST
#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)
#ifndef DRV_ADC_NOT_EXIST
	ASSERT(channel < ADC_MAX_CHANNEL);
   

	// Add PMIC ADC measurement circuit turn on here
	adcsche_adc_measure_en(KAL_TRUE);
   
#if defined(DRV_ADC_NO_IMM) || defined(FPGA)
	DRV_ADC_WriteReg(AUXADC_CTRL,channel);
	while(!(DRV_ADC_Reg(AUXADC_STAT) & AUXADC_STAT_RDY));
	data = DRV_ADC_Reg(AUXADC_DATA);
#endif // #if defined(DRV_ADC_NO_IMM) || defined(FPGA)
#if defined(DRV_ADC_IMM)
   DRV_ADC_WriteReg(AUXADC_IMM, 0);
   //DRV_ADC_Reg(AUXADC_IMM) = 0;
   DRV_ADC_SetBits(AUXADC_IMM, (1<<channel));
   //DRV_ADC_Reg(AUXADC_IMM) |= (1<<channel);
   for(i=100;i!=0;i--);		/* delay for avoid reading invalid status bit */   
   while((DRV_ADC_Reg(AUXADC_CON) & AUXADC_CON_RUN));
   data = DRV_ADC_Reg(AUXADC_DAT(channel));
#endif // #if defined(DRV_ADC_IMM)

	// Add PMIC ADC measurement circuit turn off here
   	#if !defined(DRV_ADC_MODEM_SIDE)	//don't write pmu bit to 0
	adcsche_adc_measure_en(KAL_FALSE);
	#endif

   return data;
#endif // #ifndef DRV_ADC_NOT_EXIST
}

void ADC_IMM_Data_on_Booting(kal_uint32 channel, kal_uint32 counts, kal_uint16 *data){

#ifndef DRV_ADC_NOT_EXIST
	volatile kal_uint32 i;
	kal_uint32 j;
#endif //#ifndef DRV_ADC_NOT_EXIST
#if defined(DRV_ADC_NOT_EXIST)
	return;
#endif // #if defined(DRV_ADC_NOT_EXIST)

    // Enalbe ADC power
    adc_pwrdown_disable();
#ifndef DRV_ADC_NOT_EXIST
	ASSERT(channel < ADC_MAX_CHANNEL);
   
	// Add PMIC ADC measurement circuit turn on here
	adcsche_adc_measure_en(KAL_TRUE);
   
   for(j=0;j<counts;j++)
   {
#if defined(DRV_ADC_NO_IMM) || defined(FPGA)
		DRV_ADC_WriteReg(AUXADC_CTRL,channel);
		while(!(DRV_ADC_Reg(AUXADC_STAT) & AUXADC_STAT_RDY));
		data += DRV_ADC_Reg(AUXADC_DATA);
#endif // #if defined(DRV_ADC_NO_IMM) || defined(FPGA)
#if defined(DRV_ADC_IMM)
   	DRV_ADC_WriteReg(AUXADC_IMM, 0);
   	DRV_ADC_SetBits(AUXADC_IMM, (1<<channel));
   	for(i=100;i!=0;i--);		/* delay for avoid reading invalid status bit */   
   	while((DRV_ADC_Reg(AUXADC_CON) & AUXADC_CON_RUN));
   	*(data+j) = DRV_ADC_Reg(AUXADC_DAT(channel));
#endif // #if defined(DRV_ADC_IMM)
	}
	// Add PMIC ADC measurement circuit turn off here
   	#if !defined(DRV_ADC_MODEM_SIDE)	//don't write pmu bit to 0
	adcsche_adc_measure_en(KAL_FALSE);
	#endif
#endif // #ifndef DRV_ADC_NOT_EXIST
}

/*
   ADC SYNC sample command only
   This function is exported for DCL only
*/
kal_uint16 ADC_SYNC_Data(kal_uint16 channel){
#ifndef DRV_ADC_NOT_EXIST
	kal_uint16 data;
#endif //#ifndef DRV_ADC_NOT_EXIST
#if defined(DRV_ADC_NOT_EXIST)
	return 0;
#endif // #if defined(DRV_ADC_NOT_EXIST)
#ifndef DRV_ADC_NOT_EXIST
	ASSERT(channel < ADC_MAX_CHANNEL);


	// Add PMIC ADC measurement circuit turn on here
	adcsche_adc_measure_en(KAL_TRUE);

#if defined(DRV_ADC_FULL_FUNC)
	DRV_ADC_SetBits(AUXADC_SYNC, (1<<channel));
	//DRV_ADC_Reg(AUXADC_SYNC) |= (1<<channel);
	while(DRV_ADC_Reg(AUXADC_SYNC)&(1<<channel));
	data = DRV_ADC_Reg(AUXADC_DAT(channel));
#endif // #if defined(DRV_ADC_FULL_FUNC)
   

	// Add PMIC ADC measurement circuit turn off here
   	#if !defined(DRV_ADC_MODEM_SIDE)	//don't write pmu bit to 0
	adcsche_adc_measure_en(KAL_FALSE);
	#endif
   
	return data;
#endif // #ifndef DRV_ADC_NOT_EXIST
}



