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
*    BMT_main.c
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module defines main function of the BMT task.
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
#include    "drv_comm.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include    "task_config.h"     /* Task creation */
#include    "bmt.h"
#include	"bmt_trc.h"
#include    "drvsignals.h"
// For RHR ADD Usage
#include "kal_public_defs.h" //MSBB change #include	"stack_config.h"
#include	"kal_trace.h"
#include    "bmt_sw.h"
#include    "dcl.h"
#include    "kal_general_types.h"
#include    "kal_public_api.h"
#include    "hisr_config.h"
#include    "kal_public_defs.h"
#include	"drv_msgid.h"
#include	"l4_msgid.h"
#include	"nvram_msgid.h"
#include	"sysservice_msgid.h"
#include	"md_sap.h" 

extern const kal_uint8 gCHRDET_EINT_NO;
#if defined(DRV_GPT_GPT3)
#if (defined(__CS_SERVICE__) && defined(__PS_SERVICE__))
#define PERIOD_RST_TO_DRVINT 1000
#else // #if (defined(__CS_SERVICE__) && defined(__PS_SERVICE__))
#define PERIOD_RST_TO_DRVINT 100
#endif // #if (defined(__CS_SERVICE__) && defined(__PS_SERVICE__))
#endif // #if defined(DRV_GPT_GPT3)
extern void bmt_adc_init(void);
extern void bmt_charge_start(void);
extern void bmt_charge_end(void);
extern void BMT_CHARSTOP(void);

extern void USB_PowerControl(kal_bool enable);
extern kal_uint32 Customer_Period_Period(void);

extern BMTStruct BMT;
extern stack_timer_struct      *timer_adcsche;   /*Normal Measure, only monitor VBAT*/
extern stack_timer_struct      *timer_stopcharge;
extern event_scheduler     *adc_sche_event_scheduler_ptr;
extern const kal_uint8 adc_timer_index;

kal_uint32 VBAT_OFF = 3900000;
double ADCBAT_OFF = 0;
//extern ADC_CALIDATA adc_cali_param;
extern stack_timer_struct      ChargeTimeout_timer;
//#ifdef PMIC_PRESENT
#if defined(PMIC_PRESENT)
static Charger_Status previous_chr_status=bmt_chr_uninit;
#endif // #if defined(PMIC_PRESENT)
static Charger_Status chr_status;
static kal_uint8 chr_read_flag;
#if defined(__USB_ENABLE__)
static bmt_usb_state_enum bmt_usb_state = USB_INIT_STATE;
PMU_CHR_CURRENT_ENUM bmt_usb_chr_current=PMU_CHARGE_CURRENT_0_00_MA;

#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)
extern void BMT_VbatInHISR_Init(void);
#endif //#if defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__)

#endif // #if defined(__USB_ENABLE__)

#if (( defined(__USB_ENABLE__)  && defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(DRV_USB_IP_V3)) || defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__) )

volatile kal_uint8 bmt_event_sche_active = 0;

#endif // #if !defined(DRV_USB_IP_V3)


#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__
DCL_HANDLE bmt_without_battery_handle = 0x7F;

void bmt_without_battery_callback(void *parameter)
{
 		DCL_HANDLE pmu_handle;
		pmu_handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);  
		DclPMU_Control(pmu_handle, CHR_SET_WDT_CLEAR, NULL);	
		DclPMU_Close(pmu_handle);
		
		{   	  
			SGPT_CTRL_START_T start;	  
			start.u2Tick=200;	  // 2 secs
			start.pfCallback=bmt_without_battery_callback;	  
			start.vPara=NULL;	  
			DclSGPT_Control(bmt_without_battery_handle,SGPT_CMD_START,(DCL_CTRL_DATA_T*)&start);		
		}
		
}
#endif //#ifdef __BACKUP_DOWNLOAD_RESTORE_WITHOUT_BATTERY__

#if defined(__DRV_BATTERY_EXIST_DETECTION__)
stack_timer_struct timer_batt_det;
static kal_bool batt_exist_flag = KAL_TRUE;  // Assume batt is mounted at init state
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)

#ifdef __BMT_CHARGE_GUARD_TIME__
extern stack_timer_struct      *timer_guardcharge;
#endif // #if defined(__BMT_CHARGE_GUARD_TIME__)

#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
extern stack_timer_struct      *timer_estimative;
#endif // #if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)

//#define BOOTING_DELAY         20 //need longer than first plugin debounce.
#if defined(DRV_BMT_BOOTING_DELAY_EXTEND)
kal_uint32 BOOTING_DELAY    =     100; //need longer than first plugin debounce.
#else
kal_uint32 BOOTING_DELAY    =     40; //need longer than first plugin debounce.
#endif
kal_bool   aux_first_booting = KAL_TRUE; // for inform MMI already finish booting AUX detection

DCL_HANDLE bmt_PmuHandler;


extern kal_bool BMT_Current_Voltage(DCL_ADC_CHANNEL_TYPE_ENUM ch, kal_uint32 *voltage, double *adc_value);

// default adc scheduler complete call back
void adc_sche_task_complete_callback(DCL_INT32 handle, DCL_INT32 volt_result, DCL_DOUBLE adc_result)
{
#ifndef L4_NOT_PRESENT
   ilm_struct      bmt_ilm_local;
   ilm_struct *BMT_ilm=&bmt_ilm_local;
   
   bmt_adc_measure_done_conf_struct *BMT_Prim;
   ADC_CTRL_GET_PHYSICAL_CHANNEL_T adc_ch;   
   ADC_CTRL_GET_SCHEDULER_PARAMETER_T  SchedulerPara;
   
   adc_ch.u2AdcName = DCL_VBAT_ADC_CHANNEL;
   DclSADC_Control(handle, ADC_CMD_GET_CHANNEL, (DCL_CTRL_DATA_T *)&adc_ch);

   SchedulerPara.u4Handle = handle;
   DclSADC_Control(handle, ADC_CMD_GET_SCHEDULER_PARAMETER, (DCL_CTRL_DATA_T *)&SchedulerPara);   
   
   if (SchedulerPara.pPara.bSend_primitive)
   {
      BMT_Prim = (bmt_adc_measure_done_conf_struct*)
         construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
      BMT_Prim->adc_handle = handle;
      if ((SchedulerPara.pPara.u1Adc_phy_id == adc_ch.u1AdcPhyCh) &&
         (SchedulerPara.pPara.u4Ownerid == MOD_UEM) )
      {
         switch(BMT.VBAT_UEM)
         {
         case VBAT_UEM_CHR_OUT:
            BMT_Prim->volt= volt_result;
            BMT_Prim->adc_value = adc_result;
            break;
         case VBAT_UEM_CHR_IN:
            BMT_Prim->volt= (kal_int32)VBAT_OFF;
            BMT_Prim->adc_value = ADCBAT_OFF;	
            break;	 		
         case VBAT_UEM_CHR_IN_FISRT:
            BMT_Prim->volt= volt_result;
            BMT_Prim->adc_value = adc_result;	
            BMT.VBAT_UEM = VBAT_UEM_CHR_IN;
            break;
         case VBAT_UEM_CHR_OUT_FIRST:
            BMT_Prim->volt= (kal_int32)VBAT_OFF;
            BMT_Prim->adc_value = ADCBAT_OFF;	
            BMT.VBAT_UEM = VBAT_UEM_CHR_OUT;
            break;	 			
         }
      }
      else
      {	
         BMT_Prim->volt= volt_result;
         BMT_Prim->adc_value = adc_result;
      }
      if (SchedulerPara.pPara.u4Ownerid == MOD_L1)
      {
         DRV_SendPrimitive(BMT_ilm,
            MOD_BMT,
            (module_type)SchedulerPara.pPara.u4Ownerid,
            MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
            BMT_Prim,
            DRIVER_L1_SAP); // DCL can use SchedulerPara.pPara.u4Sapid
         msg_send(BMT_ilm);
      } 
      else
      {
         DRV_BuildPrimitive(BMT_ilm,
            MOD_BMT,
            (module_type)SchedulerPara.pPara.u4Ownerid,
            MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
            BMT_Prim);
         msg_send(BMT_ilm);
      }
   }
#endif // #ifndef L4_NOT_PRESENT
}

/*
* FUNCTION
*	   BMT_sendMes
*
* DESCRIPTION                                                           
*   	This function is used to send message to BMT task
*
* CALLS  
*
* PARAMETERS
*	   queue: BMT_QUEUE
*     message_id: the message id
*	
* RETURNS
*	   None
*
* GLOBALS AFFECTED
*     None
*/
/*send to BMT task*/
void BMT_sendMes(module_type srcid, msg_type msgid)
{
   ilm_struct      bmt_ilm_local;
   ilm_struct *BMT_ilm=&bmt_ilm_local;
   
   DRV_BuildPrimitive(BMT_ilm,
      srcid,
      MOD_BMT,
      msgid,
      NULL);
   
   msg_send(BMT_ilm);
}

void BMT_sendMes2UEM(BMT_CHR_STAT status)
{
#ifndef L4_NOT_PRESENT
   ilm_struct  bmt_ilm_local;
   ilm_struct *BMT_ilm=&bmt_ilm_local;
#if (defined(__UART1_WITH_CHARGER__) || defined(__UART2_WITH_CHARGER__) || defined(__UART3_WITH_CHARGER__))
#if defined(__TST_MODULE__)
   ilm_struct  TST_ilm_local;
   ilm_struct *TST_ilm=&TST_ilm_local;
#endif
#endif
   
   drvuem_pmic_ind_struct *BMT_Prim;
   module_type src_mod;
   
   if(kal_if_hisr() == KAL_TRUE)
   		src_mod = MOD_DRV_HISR;
   else
   	  src_mod = MOD_BMT;
   
   BMT_Prim = (drvuem_pmic_ind_struct*)
      construct_local_para(sizeof(drvuem_pmic_ind_struct), TD_CTRL);
   BMT_Prim->status= status;
   
   DRV_BuildPrimitive(BMT_ilm,
      src_mod,
      MOD_UEM,
      MSG_ID_DRVUEM_PMIC_IND,
      BMT_Prim);
   
   msg_send(BMT_ilm);
   
#if (defined(__UART1_WITH_CHARGER__) || defined(__UART2_WITH_CHARGER__) || defined(__UART3_WITH_CHARGER__))
#if defined(__TST_MODULE__)
   // If add any plug-in/out status in drvsignals.h, need to add the new status here!!
   if( (status == BMT_CHARGER_IN) || 
      (status == BMT_INVALID_CHARGER))
   {
      BMT_Prim->status= BMT_CHARGER_IN;
   }
   DRV_BuildPrimitive(TST_ilm,
      src_mod,
      MOD_TST_READER,
      MSG_ID_DRVUEM_PMIC_IND,
      BMT_Prim);
   msg_send(TST_ilm);
#endif //#if defined(__TST_MODULE__)
#endif //__UART1_WITH_CHARGER__   
#endif  // #ifndef L4_NOT_PRESENT
}

void bmt_set_chr_status(Charger_Status status)
{
   chr_status = status;
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)
   HW_Plug_Status = status; // To save current H/W plug status
#endif   
   if (chr_read_flag == 0)
   {
      chr_read_flag = 1;
      BMT_sendMes(MOD_EINT_HISR/*MOD_BMT*/,MSG_ID_BMT_CHARGER_IND);
   }
}

Charger_Status bmt_read_chr_status(void)
{
   chr_read_flag = 0;
   return chr_status;
}

void bmt_adc_sche_add_item(local_para_struct *buf)
{
	DCL_STATUS adc_status;
	ADC_CTRL_REGISTER_COMPLETE_CB_T registerCB;		
    
    bmt_adc_add_item_req_struct *ptr=(bmt_adc_add_item_req_struct *)buf;
	registerCB.pfComplete_cb = (PFN_DCLSADC_COMPLETE_CALLBACK)adc_sche_task_complete_callback;
	adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_REGISTER_COMPLETE_CB, (DCL_CTRL_DATA_T *)&registerCB);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);  		
	}
	adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_START_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);  		
	}
}

void bmt_adc_sche_remove_item(local_para_struct *buf)
{
	DCL_STATUS adc_status;
    
    bmt_adc_remove_item_req_struct *ptr=(bmt_adc_remove_item_req_struct *)buf;
	adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_STOP_MEASURE, NULL);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}
}

void bmt_adc_sche_modify_parameters(local_para_struct *buf)
{
	DCL_STATUS adc_status;
	ADC_CTRL_MODIFY_PARAM_T adc_para;
    bmt_adc_modify_parameters_req_struct *ptr=(bmt_adc_modify_parameters_req_struct *)buf;
	adc_para.u4Period = ptr->period;
	adc_para.u1EvaluateCount = ptr->evaluate_count;
	adc_status = DclSADC_Control(ptr->adc_handle, ADC_CMD_MODIFY_PARAM, (DCL_CTRL_DATA_T *)&adc_para);
	if(adc_status != STATUS_OK)
	{
		ASSERT(0);
	}
}

/*
* FUNCTION
*	   bmt_check_poweron
*
* DESCRIPTION                                                           
*   	This function is to check if AC/USB exists at CHRPWRON/USBPWRON
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/


void bmt_check_poweron(kal_uint8 power_on)
{      
    kal_bool state=KAL_FALSE;
    DCL_HANDLE dcl_wdt_handle;
    DCL_HANDLE pw_handle;
#if !defined(__DRV_EXT_CHARGER_DETECTION__)
    PMU_CTRL_CHR_GET_CHR_DET_STATUS chr_det_status;
    
#endif

    dcl_wdt_handle = DclWDT_Open(DCL_WDT, FLAGS_NONE);
	pw_handle = DclPW_Open(DCL_PW, FLAGS_NONE);

#if defined(__DRV_EXT_CHARGER_DETECTION__)
	if (ext_charger_det->det_charger_present() != NO_PRESENT)
	{
	state = KAL_TRUE;
	}
	if (ext_charger_det->support_usb_det() != KAL_TRUE)
	{
		ASSERT(0); // Need to find a way to detect USB
	}
	state = KAL_FALSE;
#else
    DclPMU_Control(bmt_PmuHandler, CHR_GET_CHR_DET_STATUS, (DCL_CTRL_DATA_T *)&chr_det_status);
    state = (kal_bool)chr_det_status.enable;
           
#endif // #if defined(__DRV_EXT_CHARGER_DETECTION__)
   
	#if !defined(__USB_ENABLE__)
	if (power_on==(kal_uint8)CHRPWRON||power_on==(kal_uint8)PRECHRPWRON)
	#else // #if !defined(__USB_ENABLE__)
   if(power_on==(kal_uint8)CHRPWRON||power_on==(kal_uint8)PRECHRPWRON||
      power_on==(kal_uint8)USBPWRON||power_on==(kal_uint8)USBPWRON_WDT)   
	#endif // #if !defined(__USB_ENABLE__) 
   {           
      if(state==KAL_FALSE)
      {
         while(1)
         {
            kal_uint32 delay=0;
        	DclPW_Control(pw_handle,PW_CMD_POWEROFF,NULL);
        	DclPW_Close(pw_handle);              
            for(delay=0;delay<5000;delay++){};
			DclWDT_Control(dcl_wdt_handle,WDT_CMD_DRV_RESET,0);	          	
         }	
      }   
   }             
}   

// first_time_det: Means whether it is first time to perform battery detection
// If first time, then need to send the battery status to UEM
void bmt_batt_exist_detection(kal_bool first_time_det)
{
#if defined(__DRV_BATTERY_EXIST_DETECTION__)
   kal_bool batt_exist_state;
   
#ifdef __CS_FAC_DET__
   {
      cs_fac_boot_mode_enum fac_boot_mode;
      fac_boot_mode = cs_fac_det->factory_det_get_boot_mode();
      switch (fac_boot_mode)
      {
      case CS_FAC_BOOT_IDLE:
         ; // We boot into IDLE on purpose, skip battery check
         return;
         break;
      case CS_FAC_BOOT_CHARGING:
         ;
         break;
      case CS_FAC_BOOT_USB_CHARGING:
         ;
         break;
      default:
         break;
      }
   }
#endif // #ifdef __CS_FAC_DET__
   
   batt_exist_state = bmt_is_bat_on();
   drv_trace1(TRACE_GROUP_10, BMT_MSG_BATT_ON_DET, batt_exist_state);
   if ( (batt_exist_flag != batt_exist_state) || (first_time_det) )
   {
      if (batt_exist_state == KAL_FALSE)
      {
			// A temp workaround
			// It seems UEM expect to receive charger in message first in charger boot mode,
			// then be able to process other messages from BMT
			if (first_time_det)
			{
				if (BMT_AC_IN == bmt_IsUSBorCharger())
				{
					// Send charger in to UEM
					BMT_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
				}
			}
         // Batt removal
         BMT_sendMes2UEM(BMT_BATT_OUT);
      }
      else
      {
         // Batt attached
         BMT_sendMes2UEM(BMT_BATT_IN);
         
         // When program run to here, it means we are CHARGER or USB boot mode
         // Manually trigger cable plug-in HISR to perform charging procedure
         //pmic_adpt_sw_trigger_chr_usb_intr
         if ( (!first_time_det) && (batt_exist_flag != batt_exist_state) )
         {
            BMT_sendMes(MOD_EINT_HISR/*MOD_BMT*/,MSG_ID_BMT_CHARGER_IND);
         }
         
      }
      batt_exist_flag = batt_exist_state;
   }
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)
}


kal_bool bmt_is_bat_on_pw()
{
   kal_uint32 voltage=0;
   double adc_value=0;

    BMT_Current_Voltage(DCL_VBATTMP_ADC_CHANNEL, &voltage, &adc_value);
    if(voltage < bmt_charging_para->BATT_EXIST_ADC_THRESHOLD)
       return KAL_TRUE;
    else
       return KAL_FALSE;
}


kal_bool bmt_is_bat_on()
{
   if(bmt_charging_para->bmt_check_battery)
   {
       return bmt_is_bat_on_pw();
   }
   else
   {
      return bmt_check_if_bat_on();
   }
}
/*
* FUNCTION
*	   BMT_Task
*
* DESCRIPTION                                                           
*   	This function is used to send message to BMT task.
*     This Module defines main function of the BMT task.
*
* CALLS  
*
* PARAMETERS
*	  
*	
* RETURNS
*	   Receive primitive from the specified queue.
*
* GLOBALS AFFECTED
*     None
*/
void bmt_task_main(task_entry_struct *task_entry_ptr)
{
#if defined (WISDOM35B_DEMO_BB)
   extern const char gpio_ext_chr_ctrl_pin; //for power consumption
   DCL_HANDLE gpio_handle;
#endif
   stack_timer_struct  aux_timer; //for detect earphone plug in before booting.
   aux_id_struct       *aux_id_data;
   ilm_struct          aux_ilm_local;
   ilm_struct          *aux_ilm=&aux_ilm_local;
   ilm_struct	current_ilm;
   ilm_struct bmt_ilm_local;
   ilm_struct *BMT_ilm=&bmt_ilm_local;
   drvuem_power_on_ind_struct *power_on_ind;
   kal_uint16    UEM_RECEIVE_PWR_IND=2012;
   DCL_HANDLE dcl_adc_handle; 
   DCL_HANDLE pmu_handle;
#if defined(__UMTS_RAT__)
   boot_mode_type boot_mode;
#endif  /* __UMTS_RAT__ */
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   nvram_read_req_struct* nvram_read_req;
#endif   /*BMT_ACTIVE_TO_READ_NVRAM_DATA*/
#if defined(DRV_GPT_GPT3)
	DCL_HANDLE gpt_handle;
	FGPT_CTRL_RETURN_COUNT_T current_count;
#endif

   drv_trace0(TRACE_GROUP_10, BMT_TASK_MAIN_TRC);
   
   
	bmt_PmuHandler=DclPMU_Open(DCL_PMU, FLAGS_NONE);
   
   
#if ( (!defined(__MAUI_BASIC__)) && (!defined(L4_NOT_PRESENT)) )
   // If not Basic load, then we init the timer
   // In Basic load, L1S load, there is no L4, send message to UEM module(L4 module) will make ASSERT
   stack_init_timer(&aux_timer, "AUX timeout timer", MOD_BMT);
   stack_start_timer(&aux_timer, 0, BOOTING_DELAY);
#endif // #if ( (!defined(__MAUI_BASIC__)) && (!defined(L4_NOT_PRESENT)) )
   
   
#if defined(__UMTS_RAT__)
   boot_mode = Drv_query_boot_mode();
#endif  /* __UMTS_RAT__ */

	#ifdef PMIC_PRESENT
	#if defined(__UMTS_RAT__)
	if (boot_mode != FACTORY_BOOT)
	{
	#endif // #if defined(__UMTS_RAT__)
        pmu_handle = Dcl_Chr_Det_Open(DCL_CHR_USB_DET, FLAGS_NONE);
        Dcl_Chr_Det_Control(pmu_handle, CHR_DET_CMD_REGISTER_CHR_USB, NULL);
        Dcl_Chr_Det_Close(pmu_handle);    

	#if defined(__UMTS_RAT__)
	} /* if (boot_mode != FACTORY_BOOT) */
	#endif // #if defined(__UMTS_RAT__)
	#endif   /*PMIC_PRESENT*/

#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (!defined(PMIC_PRESENT)))
   //if( INT_USBBoot() == KAL_FALSE )
#if defined(__UMTS_RAT__)
   if (boot_mode != FACTORY_BOOT)
#endif  /* __UMTS_RAT__ */
   {
#if defined(DRV_GPT_GPT3)
	  gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
      DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&current_count);
      UEM_RECEIVE_PWR_IND = current_count+PERIOD_RST_TO_DRVINT;
      DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
      DclFGPT_Close(gpt_handle);
#endif // #if defined(DRV_GPT_GPT3)
      power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
      power_on_ind->power_on = bmt_Get_PowerOn_Type();
      if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
      {
         power_on_ind->poweron_time_left=0;
      }
      else
      {
         power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
      }
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_UEM,
         MSG_ID_DRVUEM_POWER_ON_IND,
         power_on_ind);
      msg_send(BMT_ilm);
      
   }
#endif // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (!defined(PMIC_PRESENT)))
   
   
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (defined(PMIC_PRESENT)) )
#if defined(__UMTS_RAT__)
   if (boot_mode != FACTORY_BOOT)
#endif  /* __UMTS_RAT__ */
   {
#if defined(__MTK_INTERNAL__)
      ASSERT(bmt_Get_PowerOn_Type() != (kal_uint8)ABNRESET);
#endif // #if defined(__MTK_INTERNAL__)
#if defined(DRV_GPT_GPT3)
	  gpt_handle=DclFGPT_Open(DCL_GPT_FreeRUN3,0);
      DclFGPT_Control(gpt_handle,FGPT_CMD_RETURN_COUNT,(DCL_CTRL_DATA_T*)&current_count);
      UEM_RECEIVE_PWR_IND = current_count+PERIOD_RST_TO_DRVINT;
      DclFGPT_Control(gpt_handle,FGPT_CMD_STOP,0);
      DclFGPT_Close(gpt_handle);
#endif // #if defined(DRV_GPT_GPT3)
      bmt_check_poweron(bmt_Get_PowerOn_Type());      
      
      power_on_ind = (drvuem_power_on_ind_struct *) construct_local_para(sizeof(drvuem_power_on_ind_struct),TD_UL);		    
      power_on_ind->power_on = (PW_CTRL_POWER_ON_REASON)bmt_Get_PowerOn_Type();
      // Alarm wakeup, we set poweron_time_left as PWRKEY power on
      // To avoid earphone plug-in message late than power on time
      // If earphone plug-in message ia later than power on time, MMI will choose general profile
      //if(BMT.PWRon == (kal_uint8)PWRKEYPWRON)
      if ( (bmt_Get_PowerOn_Type() == (kal_uint8)PWRKEYPWRON) || (bmt_Get_PowerOn_Type() == (kal_uint8)RTCPWRON) )
      {
         if (UEM_RECEIVE_PWR_IND>Customer_Period_Period())
         {
            power_on_ind->poweron_time_left=0;
         }
         else
         {
            power_on_ind->poweron_time_left=Customer_Period_Period()-UEM_RECEIVE_PWR_IND;
         }
      }
      else
      {
         power_on_ind->poweron_time_left = 0;
      }
      
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_UEM,
         MSG_ID_DRVUEM_POWER_ON_IND,
         power_on_ind);
      msg_send(BMT_ilm);
#ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
      /*send to read the ADC calibration data req.*/
      nvram_read_req = (nvram_read_req_struct*)construct_local_para(
         sizeof(nvram_read_req_struct), 
         TD_CTRL);
      nvram_read_req->file_idx = NVRAM_EF_ADC_LID;
      nvram_read_req->para = 1;
      nvram_read_req->access_id = 0;
      
      DRV_BuildPrimitive(BMT_ilm,
         MOD_BMT,
         MOD_NVRAM,
         MSG_ID_NVRAM_READ_REQ,
         nvram_read_req);
      msg_send(BMT_ilm);
#endif // #ifdef BMT_ACTIVE_TO_READ_NVRAM_DATA
   } /* if (boot_mode != FACTORY_BOOT) */
#endif // #if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) && (defined(PMIC_PRESENT)) )
   
   
#ifdef PMIC_PRESENT
#if defined(__UMTS_RAT__)
   if (boot_mode != FACTORY_BOOT)
   {
#endif  /* __UMTS_RAT__ */
      /*Charging algorithm initial*/
      bmt_adc_init();
      
#if defined(__UMTS_RAT__)
   } /* if (boot_mode != FACTORY_BOOT) */
#endif  /* __UMTS_RAT__ */
#endif   /*PMIC_PRESENT*/
#if defined(__UMTS_RAT__)
   if (boot_mode != FACTORY_BOOT)
   {
#endif  /* __UMTS_RAT__ */

      drv_trace1(TRACE_GROUP_10, BMT_PWRON_TRC, bmt_Get_PowerOn_Type());
      dcl_adc_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
      DclSADC_Control(dcl_adc_handle, ADC_CMD_READ_CALIBRATION_INFORM_IN_USBBOOT, NULL);
      DclSADC_Close(dcl_adc_handle);
      stack_init_timer(&ChargeTimeout_timer, "chr timeout timer", MOD_BMT);
#if defined(__UMTS_RAT__)
   } /* if (boot_mode != FACTORY_BOOT) */
#endif  /* __UMTS_RAT__ */
   
#if defined(__DRV_BATTERY_EXIST_DETECTION__)
   stack_init_timer(&timer_batt_det, "Batt det Timer", MOD_BMT);
   stack_start_timer(&timer_batt_det, 0, bmt_get_batt_exist_det_period());
   bmt_batt_exist_detection(KAL_TRUE);  // First time perform battery detection
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)
   
   while(1)
   {
      msg_receive_extq(&current_ilm);
      
      switch(current_ilm.msg_id)
      {
         kal_uint32 savedMask1;
		 kal_uint32 timer_index;
         
      case MSG_ID_TIMER_EXPIRY:
         // Need to check Aux detection status no matter PMIC_PRESENT or NOT
         // This is no notify UEM that aux detection is done

		 timer_index = evshed_get_index(&current_ilm);
		         
         if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)&aux_timer))
         {
            savedMask1 = SaveAndSetIRQMask();
            if(aux_first_booting)
            {
               aux_first_booting = KAL_FALSE;
               RestoreIRQMask(savedMask1);
               aux_id_data = (aux_id_struct*)construct_local_para(sizeof(aux_id_struct), TD_CTRL);
               aux_id_data->aux_id = AUX_ID_DETECTION_DONE;
               DRV_BuildPrimitive(aux_ilm,
                  MOD_BMT,
                  MOD_UEM,
                  MSG_ID_AUX_ID,
                  aux_id_data);
               msg_send(aux_ilm);
            }
            else
            {
               RestoreIRQMask(savedMask1);
            }
         }
#if !defined(PMIC_PRESENT)
         // If PMIC NOT PRESENT, we DO NOT need to handle the following 
         // messages
         break;
#endif // #if !defined(PMIC_PRESENT)
#ifdef PMIC_PRESENT
//         if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_adcsche))
         if (timer_index == adc_timer_index)
         {
#if (( defined(__USB_ENABLE__)  && defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(DRV_USB_IP_V3)) || defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__) )
            {
               // Add to avoid race condition
               // stack timer APIs can NOT suffer race condition between Task and HISR
               // We may call event scheduler APIs in HISR for USB/Charger detection
               kal_uint32 savedMask;
               savedMask = SaveAndSetIRQMask();
               bmt_event_sche_active = 1;
               RestoreIRQMask(savedMask);
            }
#endif // #if defined(__USB_ENABLE__)
            /* Check if the base timer is stopped or not */
               /* Execute event's timeout handler */
               evshed_timer_handler(adc_sche_event_scheduler_ptr);
            /* Shoulbe be paired with stack_is_time_out_valid() */
#if (( defined(__USB_ENABLE__)  && defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__) && !defined(DRV_USB_IP_V3)) || defined(__DRV_BMT_PRECHARGE_TO_FULL_DIRECTLY__) )
            {
               kal_uint32 savedMask;
               savedMask = SaveAndSetIRQMask();
               bmt_event_sche_active = 0;
               RestoreIRQMask(savedMask);
            }
#endif // #if defined(__USB_ENABLE__)
         }
         
         if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_stopcharge))
         {
            if (stack_is_time_out_valid(timer_stopcharge)) 
            {
               drv_trace0(TRACE_GROUP_10, BMT_STOP_TIMER_EXPIRE_TRC);
               
               BMT_CHARSTOP();
#ifdef __BMT_CHARGE_GUARD_TIME__
                  bmt_stop_guardtimer(); //Here to stop guard timer
#endif
#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
						bmt_stop_estimativetimer(); //Here to stop guard timer
#endif //#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
            }
            stack_process_time_out(timer_stopcharge);            	
            
         }
#ifdef __BMT_CHARGE_GUARD_TIME__
				if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_guardcharge))
            {
					if (stack_is_time_out_valid(timer_guardcharge))
               {
						drv_trace1(TRACE_GROUP_10, BMT_CHARGE_GUARD_TIMER_EXPIRE_TRC, BMT_CHARGE_GUARD_TIME_PERIOD);
						BMT_CHARSTOP();
                  bmt_stop_stoptimer(); //Here to stop 30min timer
                  				bmt_stop_estimativetimer();
                  				#ifdef __DRV_BMT_CHARGING_COMPLETE_MSG__
						if(BMT_VBatVoltageIsFull(VBAT_OFF))
						#endif //__DRV_BMT_CHARGING_COMPLETE_MSG__
						BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
               }
					stack_process_time_out(timer_guardcharge);
         }
#endif

#if defined(__DRV_BMT_ESTIMATIVE_TIMER_ON_TOPOFF__)
				if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)timer_estimative))
				{
					if (stack_is_time_out_valid(timer_estimative))
					{
						drv_trace1(TRACE_GROUP_10, BMT_CHARGE_GUARD_TIMER_EXPIRE_TRC, BMT_CHARGE_GUARD_TIME_PERIOD);
						BMT_CHARSTOP();
						bmt_stop_stoptimer(); //Here to stop 30min timer
                  				#ifdef __DRV_BMT_CHARGING_COMPLETE_MSG__
						if(BMT_VBatVoltageIsFull(VBAT_OFF))
						#endif //__DRV_BMT_CHARGING_COMPLETE_MSG__
							BMT_sendMes2UEM(BMT_CHARGE_COMPLETE);
					}
					stack_process_time_out(timer_estimative);
				}
#endif

         if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)&ChargeTimeout_timer))
         {
            if (stack_is_time_out_valid(&ChargeTimeout_timer)) 
            {
#if defined(DRV_BMT_HIGH_VCHG_ADAPTIVE_CHARGE_CURRENT_SUPPORT)
                  drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_EXPIRE_TRC, bmt_total_charge_time);
#else
                  drv_trace1(TRACE_GROUP_10, BMT_SAFETY_TIMER_EXPIRE_TRC, BMT_TOTAL_CHARGE_TIME);
#endif
#ifndef __BMT_CHARGE_GUARD_TIME__
                  //When BMT has guard time, it won't need safty time
                  BMT_sendMes2UEM(BMT_CHARGE_TIMEOUT);
                  bmt_charge_end();
#endif
               }
            stack_process_time_out(&ChargeTimeout_timer);                 	
         }         
#if defined(__DRV_BATTERY_EXIST_DETECTION__)
         if (((kal_uint32)current_ilm.local_para_ptr) == ((kal_uint32)&timer_batt_det))
         {
            bmt_batt_exist_detection(KAL_FALSE);
            stack_process_time_out(&timer_batt_det);
            // Re-start timer
            stack_start_timer(&timer_batt_det, 0, bmt_get_batt_exist_det_period());
         }
#endif // #if defined(__DRV_BATTERY_EXIST_DETECTION__)
         
         break;
         
         case MSG_ID_BMT_CHARGER_IND:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_CHARGER_TRC);
            
            // If battery is NOT attached, we just skip the message
            if (!bmt_is_bat_on())
            {
               drv_trace0(TRACE_GROUP_10, BMT_MSG_BATT_OFF_BLOCK);
               break;
            }
            
            if (bmt_read_chr_status() == bmt_chr_in)
            {
                drv_trace0(TRACE_GROUP_10, BMT_CHR_STATUS_CHARGE_IN_TRC);                
#if defined (WISDOM35B_DEMO_BB)
				gpio_handle=DclGPIO_Open(DCL_GPIO, gpio_ext_chr_ctrl_pin);
				DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
				DclGPIO_Close(handle);
#endif
               //dbg_print("bmt_chr_in \r\n");
               if ( (previous_chr_status == bmt_chr_uninit) || (previous_chr_status != bmt_chr_in) )
               {
                  previous_chr_status = bmt_chr_in;
                  
#if defined(__USB_ENABLE__)
                  /*06102004 TY*/	            		
#if defined(PMIC_DET_USB_CHR)
#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
	            		   if(bmt_is_chr_det(PMIC_AC_CHR))/*AC exists*/
#else // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
                           if(bmt_IsUSBorCharger() != BMT_USB_IN)		            	
#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
                           {
                              if(bmt_is_chr_valid())/*check if it's a valid charger*/
                              {	            	       
                                 drv_trace0(TRACE_GROUP_10, BMT_AC_IN_TRC);
                                 //pmic_charging_currnet_ctrl(CHR_CURRENT_650);	         	       
                                 BMT_sendMes2UEM(BMT_CHARGER_IN);
                                 bmt_charge_start();
                                 drv_trace0(TRACE_GROUP_10, BMT_AC_IN_AND_START_CHARGE_TRC);
                              }
                              else
                              {	            		    
                                 drv_trace0(TRACE_GROUP_10, BMT_INV_AC_IN_TRC);
                                 bmt_charge_end();
                                 BMT_sendMes2UEM(BMT_INVALID_CHARGER);
                                 drv_trace0(TRACE_GROUP_10, BMT_INV_AC_IN_AND_START_CHARGE_TRC);
                              }   
                           }   
#else // #if defined(PMIC_DET_USB_CHR)
                           // check USB or AC 
                           if(bmt_IsUSBorCharger() == BMT_USB_IN)
                           {
                              drv_trace0(TRACE_GROUP_10, BMT_USB_IN_TRC);
                              //dbg_print("BMT_USB_IN \r\n");            			
                              // a USB cable is plugged in            			
                              bmt_usb_state = USB_IN_STATE;
                           }
                           else
                           {
                              drv_trace0(TRACE_GROUP_10, BMT_AC_IN_TRC);
                              //dbg_print("AC_IN_STATE and bmt_charge_start \r\n");
                              bmt_usb_state = AC_IN_STATE;
                              // a AC charger is plugged in 	                  
                              BMT_sendMes2UEM(BMT_CHARGER_IN);
                              bmt_charge_start();                 
                              drv_trace0(TRACE_GROUP_10, BMT_AC_IN_AND_START_CHARGE_TRC);
                           }
#endif // #if defined(PMIC_DET_USB_CHR)
#else // #if defined(__USB_ENABLE__)
                           /*06102004 TY*/
#if defined(PMIC_DET_USB_CHR)
                           if(bmt_is_chr_det(PMIC_AC_CHR))/*AC exists*/
                           {
                              if(bmt_is_chr_valid())/*check if it's a valid charger*/
                              {	            	         
                                 drv_trace0(TRACE_GROUP_10, BMT_AC_IN_TRC);
                                 //pmic_charging_currnet_ctrl(CHR_CURRENT_650);	    	            	         
                                 BMT_sendMes2UEM(BMT_CHARGER_IN);
                                 bmt_charge_start();                 
                                 drv_trace0(TRACE_GROUP_10, BMT_AC_IN_AND_START_CHARGE_TRC);
                              }
                              else
                              {	            		      
                                 drv_trace0(TRACE_GROUP_10, BMT_INV_AC_IN_TRC);
                                 bmt_charge_end();
                                 BMT_sendMes2UEM(BMT_INVALID_CHARGER);                 
                                 drv_trace0(TRACE_GROUP_10, BMT_INV_AC_IN_AND_START_CHARGE_TRC);
                              }   
                           }    
#else // #if defined(PMIC_DET_USB_CHR)
                           drv_trace0(TRACE_GROUP_10, BMT_AC_IN_TRC);
                           BMT_sendMes2UEM(BMT_CHARGER_IN);	                  
                           bmt_charge_start();	           
                           drv_trace0(TRACE_GROUP_10, BMT_AC_IN_AND_START_CHARGE_TRC);
#endif // #if defined(PMIC_DET_USB_CHR)
#endif // #if defined(__USB_ENABLE__)
               }
            }
            else if(bmt_read_chr_status() == bmt_chr_out)
            {
#if defined(DRV_BMT_HW_PRECC_WORKAROUND)

               drv_trace0(TRACE_GROUP_10, BMT_CHR_STATUS_CHARGE_OUT_TRC);                
#if defined(__USB_ENABLE__)               
               if((SW_Workaround_Flag == KAL_TRUE) && (bmt_usb_state == AC_IN_STATE))       
#else
          		 if(SW_Workaround_Flag == KAL_TRUE)
#endif          		 
               {
                    drv_trace0(TRACE_GROUP_10, BMT_HW_PLUG_OUT_INSIDE_SW_WORKAROUND_RANGE_TRC);               
                    break;
               }

#endif // End of #if defined(DRV_BMT_HW_PRECC_WORKAROUND)

#if defined (WISDOM35B_DEMO_BB)
				gpio_handle=DclGPIO_Open(DCL_GPIO, gpio_ext_chr_ctrl_pin);
				DclGPIO_Control(handle,GPIO_CMD_SET_DIR_OUT,0);
				DclGPIO_Close(handle);
#endif
               //dbg_print("bmt_chr_out \r\n");
               if ( (previous_chr_status == bmt_chr_uninit) || (previous_chr_status != bmt_chr_out) )
               {
                  previous_chr_status = bmt_chr_out;
                  
#if defined(__USB_ENABLE__)
#if defined(PMIC_DET_USB_CHR)
		ASSERT(0);
#else // #if defined(PMIC_DET_USB_CHR)
                  drv_trace1(TRACE_GROUP_10, BMT_USB_STATE_TRC, bmt_usb_state);
                  // current sate != previous state
                  switch(bmt_usb_state)
                  {
                  case AC_IN_STATE:        
                     //dbg_print("AC_CHARGER_OUT \r\n");
                     bmt_usb_state = AC_OUT_STATE;
                     BMT_sendMes2UEM(BMT_CHARGER_OUT);
                     bmt_charge_end();
                     drv_trace0(TRACE_GROUP_10, BMT_AC_OUT_AND_STOP_CHARGE_TRC);
                     break;
                  case USB500_STATE:
                     //dbg_print("USB_OUT_STATE \r\n"); 	
                     drv_trace0(TRACE_GROUP_10, BMT_USB_OUT_TRC);
                     {			
                        bmt_usb_state = USB_OUT_STATE;
                        BMT_sendMes2UEM(BMT_USB_CHARGER_OUT);
                        bmt_charge_end();
                        drv_trace0(TRACE_GROUP_10, BMT_USB_500_OUT_AND_STOP_CHARGE_TRC);
                     }
                     break;            				
		    case USB_IN_STATE:
                  case USB100_STATE:
                     drv_trace0(TRACE_GROUP_10, BMT_USB_OUT_TRC);
                     //dbg_print("USB_OUT_STATE \r\n"); 	
                     {			
                        bmt_usb_state = USB_OUT_STATE;
                        BMT_sendMes2UEM(BMT_USB_NO_CHARGING_OUT);
                        drv_trace0(TRACE_GROUP_10, BMT_USB_100_OUT_TRC);
                     }
                     break;            				
                  default:
                     break;
                  } 
#endif // // #if defined(PMIC_DET_USB_CHR)
#else // #if defined(__USB_ENABLE__)
               			drv_trace0(TRACE_GROUP_10, BMT_AC_OUT_TRC);
                        BMT_sendMes2UEM(BMT_CHARGER_OUT);
                        bmt_charge_end();
                        drv_trace0(TRACE_GROUP_10, BMT_AC_OUT_AND_STOP_CHARGE_TRC);
#endif // #if defined(__USB_ENABLE__)
               }
            }
            else
            {
               ASSERT(0);
            }
            break;
#if defined (__USB_ENABLE__)
         case MSG_ID_BMT_USB_IND:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_USB);
            //dbg_print("receive MSG_ID_BMT_USB_IND \r\n");
            
            // If battery is NOT attached, we just skip the message
            if (!bmt_is_bat_on())
            {
               drv_trace0(TRACE_GROUP_10, BMT_MSG_BATT_OFF_BLOCK);
               break;
            }
            
            {
               //EXT_ASSERT((bmt_usb_state == USB_IN_STATE),bmt_usb_state,0,0);
               bmt_usb_ind_struct *ind = (bmt_usb_ind_struct*)current_ilm.local_para_ptr;
               /* This message may send again, so we have to deal with this case. */
               if((bmt_usb_state == USB_IN_STATE) || (bmt_usb_state == USB500_STATE) || (bmt_usb_state == USB100_STATE))
               {

			/* Set the allowed current index for USB. */
			bmt_usb_chr_current=ind->usb_ind;
			if((ind->usb_ind) == PMU_CHARGE_CURRENT_0_00_MA)
			{

                        drv_trace0(TRACE_GROUP_10, BMT_USB_100_TRC);
                        //dbg_print("receive MSG_ID_BMT_USB_IND with BMT_USB_100  \r\n");
                        /* If state is from USB_IN_STATE or USB500_STATE to USB100_STATE. */
                        if (bmt_usb_state != USB100_STATE)
                        {
                              /* If state is from USB500_STATE(usb charging), charging should stop. */
                              if(bmt_usb_state == USB500_STATE)
                              {
                                 bmt_charge_end();
                                 drv_trace0(TRACE_GROUP_10, BMT_CHARGING_CURRENT_NOT_SUPPORTED_STOP_CHARGING_TRC);
                              }
                              bmt_usb_state = USB100_STATE;      			
                              BMT_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
                        }
			
			}
                     else if((ind->usb_ind) <= PMU_CHARGE_CURRENT_500_00_MA)
                     {
				drv_trace0(TRACE_GROUP_10, BMT_USB_500_TRC);
				/* If state is from USB_IN_STATE or USB100_STATE to USB500_STATE. */
				if (bmt_usb_state != USB500_STATE)
				{
				   drv_trace0(TRACE_GROUP_10, BMT_USB_500_AND_START_CHARGE_TRC);
				   bmt_usb_state = USB500_STATE;
				   // modify for test
				   BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
				   bmt_charge_start();
				}
                     }
			else
			{
				ASSERT(0);// usb should not send current > 500
			}


#ifdef PMU_REFERENCE_WY	   
#ifdef __USB_MULTI_CHARGE_CURRENT__
                  /* If chargin current is allowed. */
                  if((ind->usb_ind) <= PMU_CHARGE_CURRENT_500_00_MA)
#else // #ifdef __USB_MULTI_CHARGE_CURRENT__
                     if(ind->usb_ind == BMT_USB_500)
#endif // #ifdef __USB_MULTI_CHARGE_CURRENT__
                     {
                        drv_trace0(TRACE_GROUP_10, BMT_USB_500_TRC);
                        /*06102004 TY*/
#if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                        /* If state is from USB_IN_STATE or USB100_STATE to USB500_STATE. */
                        if (bmt_usb_state != USB500_STATE)
                        {
                           bmt_usb_state = USB500_STATE;
                           BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
#if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
                           if(bmt_is_chr_det(PMIC_AC_CHR))/*check if AC exists*/
#else // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
                              if(bmt_IsUSBorCharger() != BMT_USB_IN)
#endif // #if !defined(__CHARGER_USB_DETECT_WIHT_ONE_EINT__)
                              {
                                 drv_trace0(TRACE_GROUP_10, BMT_USB_500_AC_ALREAY_IN_TRC);
                                 /*change state but not charge*/
                              }
                              else
                              {
                                 drv_trace0(TRACE_GROUP_10, BMT_USB_500_AND_START_CHARGE_TRC);
                                 bmt_charge_start();
                              }      
                        }
#ifdef __USB_MULTI_CHARGE_CURRENT__
                        /* Set the allowed current index for USB. */
                        bmt_find_and_set_the_nearest_current(ind->usb_ind);
#endif // #ifdef __USB_MULTI_CHARGE_CURRENT__
#else // #if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                        //dbg_print("receive MSG_ID_BMT_USB_IND with BMT_USB_500  \r\n");
                        /* If state is from USB_IN_STATE or USB100_STATE to USB500_STATE. */
                        if (bmt_usb_state != USB500_STATE)
                        {
                           drv_trace0(TRACE_GROUP_10, BMT_USB_500_AND_START_CHARGE_TRC);
                           bmt_usb_state = USB500_STATE;
                           // modify for test
                           BMT_sendMes2UEM(BMT_USB_CHARGER_IN);
                           bmt_charge_start();
                        }
#ifdef __USB_MULTI_CHARGE_CURRENT__
                        /* Set the allowed current index for USB. */
                        bmt_find_and_set_the_nearest_current(ind->usb_ind);
#endif // #ifdef __USB_MULTI_CHARGE_CURRENT__
#endif // // #if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                     }
                     else
                     {
                        drv_trace0(TRACE_GROUP_10, BMT_USB_100_TRC);
                        //dbg_print("receive MSG_ID_BMT_USB_IND with BMT_USB_100  \r\n");
                        /* If state is from USB_IN_STATE or USB500_STATE to USB100_STATE. */
                        if (bmt_usb_state != USB100_STATE)
                        {
#if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                           /* If state is from USB500_STATE and there's no AC, charging should stop. */
                           if((KAL_FALSE==bmt_is_chr_det(PMIC_AC_CHR)) && (bmt_usb_state == USB500_STATE))
#else // #if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                              /* If state is from USB500_STATE(usb charging), charging should stop. */
                              if(bmt_usb_state == USB500_STATE)
#endif // #if defined(PMIC_WAIT_USB_FOR_CHARGING)//defined(MT6318)
                              {
                                 bmt_charge_end();
                                 drv_trace0(TRACE_GROUP_10, BMT_CHARGING_CURRENT_NOT_SUPPORTED_STOP_CHARGING_TRC);
                              }
                              bmt_usb_state = USB100_STATE;      			
                              BMT_sendMes2UEM(BMT_USB_NO_CHARGING_IN);
                        }
                     }

#endif


               }
            }
            break;                     
#endif // // #if defined (__USB_ENABLE__)
            /***********ADC scheduler***********/
         case MSG_ID_BMT_ADC_ADD_ITEM_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_ADD);
            bmt_adc_sche_add_item(current_ilm.local_para_ptr);
            break;
            
         case MSG_ID_BMT_ADC_REMOVE_ITEM_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_REMOVE);
            bmt_adc_sche_remove_item(current_ilm.local_para_ptr);
            break;
            
         case MSG_ID_BMT_ADC_MODIFY_PARAMETERS_REQ:
            drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_PARAM);
            bmt_adc_sche_modify_parameters(current_ilm.local_para_ptr);
            break;
#endif // #ifdef PMIC_PRESENT
            
#if ( (!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL)) )
         case MSG_ID_NVRAM_READ_CNF:
			{
            	DCL_HANDLE dcl_handle;
            	ADC_CTRL_SET_CALIBRATION_DATA_T  prSetCalibrationData;
#if defined(__DRV_BMT_REPORT_VBAT_IN_BOOTING__)
                ilm_struct     BMT_ilm2_local;
            	ilm_struct     *BMT_ilm2=&BMT_ilm2_local;
            	bmt_adc_measure_done_conf_struct *BMT_Prim;
#endif //#if defined(DRV_BMT_REPORT_VBAT_IN_BOOTING)
            	drv_trace0(TRACE_GROUP_10, BMT_MSG_ADC_NVRAM_READ_CNF);
                prSetCalibrationData.ilm_ptr = (void *)&current_ilm;
                dcl_handle = DclSADC_Open(DCL_ADC, FLAGS_NONE);
                DclSADC_Control(dcl_handle, ADC_CMD_SET_CALIBRATION_DATA, (DCL_CTRL_DATA_T *)&prSetCalibrationData);
                DclSADC_Close(dcl_handle);

#if defined(__DRV_BMT_REPORT_VBAT_IN_BOOTING__)
                BMT_Prim = (bmt_adc_measure_done_conf_struct*)
			                 construct_local_para(sizeof(bmt_adc_measure_done_conf_struct), TD_CTRL);
                BMT_Current_Voltage(DCL_VBAT_ADC_CHANNEL, &VBAT_OFF, &ADCBAT_OFF);
                BMT_Prim->volt= VBAT_OFF;
                DRV_BuildPrimitive(BMT_ilm2,
			                 MOD_BMT,
			                 MOD_UEM,
			                 MSG_ID_BMT_ADC_MEASURE_DONE_CONF,
			                 BMT_Prim);
                msg_send(BMT_ilm2);
#endif //#if defined(DRV_BMT_REPORT_VBAT_IN_BOOTING)
        		break;
			}
#endif   /*(!defined(L4_NOT_PRESENT)) && (!defined(DUMMY_PROTOCOL))*/
            
			default:
            break;
      }
      destroy_ilm(&current_ilm);
   }
}

