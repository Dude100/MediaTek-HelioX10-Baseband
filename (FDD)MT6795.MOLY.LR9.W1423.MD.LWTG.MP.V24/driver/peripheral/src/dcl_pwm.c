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
 *    dcl_PWM.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the PWM driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features_pwm.h"
#include "drv_comm.h"

#include "dcl.h"
#include "custom_hw_default.h"
#include "kal_general_types.h"
#include "pwm_sw.h"
#include "rwg_sw.h"
#include "alerter_sw.h"
#include "kal_public_api.h"
//#include "kal_active_module.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#if !defined(DRV_PWM_OFF) && !defined(DRV_PWM_NOT_EXIST)
//#include "drvtest.h"
//#ifdef DCL_PWM_INTERFACE

#define PWM_HANDLE_MAGIC_NUM 		0x1000000
#define DCL_PWM_IS_HANDLE_MAGIC(handle_) ((handle_)& PWM_HANDLE_MAGIC_NUM)
#define DCL_PWM_GET_DEV(handle_) ((handle_) & (~PWM_HANDLE_MAGIC_NUM))

#define ALERTER_HANDLER_MAGIC_NUM	0x2000000
#define DCL_ALERTER_IS_HANDLE_MAGIC(handle_) ((handle_)& ALERTER_HANDLER_MAGIC_NUM)
#define DCL_ALERTER_GET_DEV(handle_) ((handle_) & (~ALERTER_HANDLER_MAGIC_NUM))
typedef struct
{
   kal_uint32 PWMUsed;
   kal_uint32 owner[PWM_COUNT];
} DCL_PWM_T;

kal_bool alerter_status;
PWMDriver_t *comm_pwm_driver;

#if !defined(DRV_ALERTER_NOT_EXIST)
AlerterDriver_t   *comm_alerter_driver;
#endif

#if !defined(DRV_PWM_RWG)
extern PWMDriver_t pwm_driver;
extern kal_uint8 pwm_count;
#else
extern PWMDriver_t rwg_driver;
extern kal_uint8 pwm_count;
#endif

#if !defined(DRV_ALERTER_NOT_EXIST)
extern AlerterDriver_t alerter_driver;
#endif

#if defined(DRV_PWM_RWG)
#if defined(__PWM456_SUPPORT_OLD_PWM_API__)
extern kal_uint8 PWM_LEVEL_SAVE[6];
#else
extern kal_uint8 PWM_LEVEL_SAVE[3];
#endif
#else
extern kal_uint8 PWM_LEVEL_SAVE[4];
#endif
/* Global variable*/
DCL_PWM_T rDclPWM;

/*-----------------------------------------------------------------------------------*
* FUNCTION                                                            
*	DclPWM_Initialize
*
* DESCRIPTION                                                           
*   	This function is to initialize PWM module
*
* CALLS  
*	It is called to initialize PWM module
*
* PARAMETERS
*	None
*	
* RETURNS
*	DCL_STATUS_OK
*
* GLOBALS AFFECTED
*   external_global
*---------------------------------------------------------------------------------------*/
DCL_STATUS DclPWM_Initialize(void)
{
   #if defined(DRV_PWM_RWG)
   comm_pwm_driver=&rwg_driver;
   #else
   comm_pwm_driver=&pwm_driver;
   #endif
   #if !defined(DRV_ALERTER_NOT_EXIST)
   comm_alerter_driver=&alerter_driver;
   #endif
   comm_pwm_driver->pwmInit();
   return STATUS_OK;
}

/*-----------------------------------------------------------------------------------*
* FUNCTION                                                            
*	DclPWM_Open
*
* DESCRIPTION                                                           
*   	This function is to open the PWM module and return a handle
*
* CALLS  
*	It is called to open PWM module
*
* PARAMETERS
*	dev - valid for DCL_PWM1 ~ DCL_PWM6
*	flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*    DCL_HANDLE_OCCUPIED - Open failed.
*   STATUS_INVALID_ARGUMENT - invalid arguments
*   other value - a valid handle
*
* GLOBALS AFFECTED
*   external_global
*---------------------------------------------------------------------------------------*/
DCL_HANDLE DclPWM_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   DCL_HANDLE  ret_handle = 0;
   kal_uint32 savedMask;

   //put alerter in the front to easy coding effort.
   if(dev==DCL_ALERTER)
   {
      #if defined(DRV_ALERTER_NOT_EXIST)
      EXT_ASSERT(0,dev,flags,0);
      #else
         #if !defined(__FUE__) && !defined(__UBL__)
         savedMask = SaveAndSetIRQMask();
         #endif
         alerter_status=KAL_TRUE;
         #if !defined(__FUE__) && !defined(__UBL__)
         RestoreIRQMask(savedMask);
         #endif
         return (ALERTER_HANDLER_MAGIC_NUM|DCL_ALERTER);
		#endif	
   }

   //if open PWM number don't fall between available numbers. 
   if ( (dev < DCL_PWM1) || (dev > DCL_PWM6) )
   {	
      EXT_ASSERT(0,dev,flags,0);
      return STATUS_INVALID_ARGUMENT;
   }
   dev -= DCL_PWM1;
   //pwm_count is define in pwm.c rwg.c, this judgment is to avoid error open. <this maybe toooo simple>
   if(dev>PWM_COUNT)
   {
      EXT_ASSERT(0,dev,flags,0);
      return STATUS_INVALID_ARGUMENT;
   }
   #if !defined(__FUE__) && !defined(__UBL__)
   savedMask = SaveAndSetIRQMask();
   #endif
   if((rDclPWM.PWMUsed & 1<<dev) == 0 && rDclPWM.owner[dev] != flags)
   {
      rDclPWM.PWMUsed |= 1<<dev;
      rDclPWM.owner[dev]=flags;
      //rDclPWM.owner[dev] = kal_get_active_module_id();// Get the cureent active module ID	   	
      ret_handle = (dev | PWM_HANDLE_MAGIC_NUM);
      #if !defined(__FUE__) && !defined(__UBL__)
      RestoreIRQMask(savedMask);
      #endif
      return ret_handle;
   }
   else
   {
      #if !defined(__FUE__) && !defined(__UBL__)
      RestoreIRQMask(savedMask);
      #endif
      //If multi open happen, we do different error handle according to pwm owner. 
      if(rDclPWM.owner[dev] == flags)
         return DCL_HANDLE_OCCUPIED;
      else
      {
         EXT_ASSERT(0,dev,rDclPWM.owner[dev],flags);
         return STATUS_INVALID_ARGUMENT;
      }
   }
}

/*-----------------------------------------------------------------------------------*
* FUNCTION                                                            
*	DclPWM_Close
*
* DESCRIPTION                                                           
*   	This function is to close the PWM module.
*
* CALLS  
*	It is called to close PWM(1~6) module
*
* PARAMETERS
*	None
*	
* RETURNS
*	DCL_STATUS_OK
*   STATUS_INVALID_ARGUMENT: invalid arguments
*
* GLOBALS AFFECTED
*   external_global
*-------------------------------------------------------------------------------------*/
DCL_STATUS DclPWM_Close(DCL_HANDLE handle)
{
   kal_uint32 iPWMNum;
   kal_uint32 iPWMMap;
   kal_uint32 savedMask;
   
   //as open, we do alerter frist.
   if(DCL_ALERTER_IS_HANDLE_MAGIC(handle))
   {
      #if !defined(__FUE__) && !defined(__UBL__)
      savedMask = SaveAndSetIRQMask();
      #endif
      alerter_status=KAL_FALSE;
      #if !defined(__FUE__) && !defined(__UBL__)
      RestoreIRQMask(savedMask);
	  	#endif
      return STATUS_OK;
   }
   
   // remove magic number
   iPWMNum = handle & (~PWM_HANDLE_MAGIC_NUM) ;
   iPWMMap = (1<<iPWMNum);
   
   // if PWM number incorrect or this PWMUsed flag is 0, return invalid.
   if( (iPWMNum > PWM_COUNT) || (!(rDclPWM.PWMUsed & iPWMMap)) )
   {
       return STATUS_INVALID_ARGUMENT;
   }

   //delete bitamp and owner record array.
   #if !defined(__FUE__) && !defined(__UBL__)
   savedMask = SaveAndSetIRQMask();
   #endif
   rDclPWM.PWMUsed &= ~iPWMMap;
   rDclPWM.owner[iPWMNum]=0;
   #if !defined(__FUE__) && !defined(__UBL__)
   RestoreIRQMask(savedMask);
   #endif
   return STATUS_OK;
}

/*-----------------------------------------------------------------------------------*
* FUNCTION                                                            
*	DclPWM_Configure
*
* DESCRIPTION                                                           
*   	This function is to configure the PWM module.
*
* CALLS  
*	It is called to configure of the PWM module.
*
* PARAMETERS
*	handle - a valid handle return by DclPWM_Configure()
*   configure - a structure which include the PWM configuration.  
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*
* GLOBALS AFFECTED
*   external_global
*-------------------------------------------------------------------------------------*/
DCL_STATUS DclPWM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   PWM_CONFIG_T    *rPWMConfig;
   kal_uint32 		iPWMNum;
   kal_uint32  		iPWMMap;
   
   // remove magic number
   iPWMNum = handle & (~PWM_HANDLE_MAGIC_NUM) ;
   iPWMMap = (1<<iPWMNum);
   
   // if PWM number incorrect or this PWMUsed flag is 0, return invalid.
   if((iPWMNum > PWM_COUNT) || (!(rDclPWM.PWMUsed & iPWMMap)) )
   {
      return STATUS_INVALID_ARGUMENT;
   }
   //this is just configure clock sources and div.
   rPWMConfig = (PWM_CONFIG_T *)&configure->rPWMConfig;
   comm_pwm_driver->pwmClkInit(rDclPWM.owner[iPWMNum], iPWMNum,rPWMConfig->clksrc,rPWMConfig->clkdiv);
   return STATUS_OK;
}

/*-----------------------------------------------------------------------------------*
*
*  This function is not supported for the PWM module now.
*
*------------------------------------------------------------------------------------*/
DCL_STATUS DclPWM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------------------*
* FUNCTION                                                            
*	DclPWM_Control
*
* DESCRIPTION                                                           
*   	This function is to send command to control the PWM module.
*
* CALLS  
*	It is called to send command to control the PWM module.
*
* PARAMETERS
*   handle:  - a valid handle return by DclPWM_Open()
*   cmd:   - a control command for PWM module
*          1. PWM_CMD_START: to start a PWM timer
*          2. PWM_CMD_STOP: to stop a PWM timer
*          3. PWM_CMD_CONFIG: to config a pwm timer.
*          4. PWM_CMD_SEQ_OPEN: 
*          5. PWM_CMD_SEQ_START:
*          6. PWM_CMD_SEQ_STOP:
*          7. PWM_CMD_GET_CURRENT_LEVEL:
*          8. PWM_CMD_GET_CURRENT_DUTY:
*          9. PWM_CMD_GET_CURRENT_FREQ:
*         10. PWM_CMD_SET_BUF_VALID:
*         11. PWM_CMD_SET_DELAY:
*         12. PWM_CMD_SEQ_OPEN
*         13. PWM_CMD_SEQ_OPEN
*   data - for 1. PWM_CMD_START: poiter to a PWM_CTRL_START_T structure
*             2. PWM_CMD_STOP: a NULL pointer
*	
* RETURNS
*	STATUS_OK: command is executed successfully.
*	STATUS_FAIL: command is failed.
*   STATUS_INVALID_CMD: It's a invalid command.
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------------------*/
DCL_STATUS DclPWM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   kal_uint32  iPWMNum;
   kal_uint32  iPWMMap;
   #if defined(DRV_PWM_RWG)
   kal_uint32  idx;
   #endif
   if(DCL_PWM_IS_HANDLE_MAGIC(handle))
   {
      // remove magic number
      iPWMNum = handle & (~PWM_HANDLE_MAGIC_NUM) ;
      iPWMMap = (1<<iPWMNum);
      // if PWM number incorrect or this PWMUsed flag is 0, return invalid.
      if((iPWMNum > PWM_COUNT) || (!(rDclPWM.PWMUsed & iPWMMap)) )
      {
         EXT_ASSERT(0,handle,cmd,rDclPWM.PWMUsed);
         return STATUS_INVALID_ARGUMENT;
      }
      switch (cmd)
      {
         //this command is support by both RWG and PWM.
         case PWM_CMD_START:
         {
            comm_pwm_driver->pwmStart(rDclPWM.owner[iPWMNum], iPWMNum);
            break;
         }
         case PWM_CMD_STOP:
         {
            comm_pwm_driver->pwmStop(rDclPWM.owner[iPWMNum], iPWMNum);
            break;
         }
         case PWM_CMD_GET_CURRENT_LEVEL:
         {
            PWM_DATA_T	*pdata;
            pdata=&(data->rPWMSaveData);
            pdata->pwm_level=comm_pwm_driver->pwmGetCurrent_level(iPWMNum);
            break;
         }
         case PWM_CMD_GET_CURRENT_DUTY:
         {
            PWM_DATA_T	*pdata;
            pdata=&(data->rPWMSaveData);
            pdata->pwm_duty=comm_pwm_driver->pwmGetCurrent_Duty(iPWMNum);
            break;
         }
         case PWM_CMD_GET_CURRENT_FREQ:
         {
            PWM_DATA_T	*pdata;
            pdata=&(data->rPWMSaveData);
            pdata->pwm_freq=comm_pwm_driver->pwmGetCurrent_Freq(iPWMNum);
            break;
         }
         case PWM_CMD_CONFIG_OLD:
         {
            PWM_CMD_CONFIG_OLD_T *pdata;
            pdata=&(data->rPWMConfigOld);
            comm_pwm_driver->pwmConfigOld(rDclPWM.owner[iPWMNum], iPWMNum,pdata->freq,pdata->duty);
            break;
         }
         
         //this command is for RWG only.
         #if defined(DRV_PWM_RWG)
         case PWM_CMD_SEQ_OPEN:
         {
            comm_pwm_driver->pwmSeqOpen(rDclPWM.owner[iPWMNum]);
            for (idx=(kal_uint32)PWM3; idx < (kal_uint32)PWM_COUNT; idx++)
            {
               rDclPWM.PWMUsed |= (1<<idx);
            }
            break;
         }
         case PWM_CMD_CONFIG:
         {
            PWM_CTRL_CONFIG_T  *prCtrlConfig;
            prCtrlConfig = &(data->rPWMConfig);
            comm_pwm_driver->pwmConfigure(rDclPWM.owner[iPWMNum], iPWMNum,prCtrlConfig->mode,prCtrlConfig->para);
            break;
         }
         case PWM_CMD_OPEN:
         {
            comm_pwm_driver->pwmOpen(rDclPWM.owner[iPWMNum], iPWMNum);
            break;
         }
         case	PWM_CMD_CLOSE:
         {
            comm_pwm_driver->pwmClose(rDclPWM.owner[iPWMNum], iPWMNum);
            break;
         }
         
         //pwm test command.
         case PWM_CMD_TEST_SEL:
         {
            PWM_CTRL_TS_T   *prCtrlTS;
            prCtrlTS = &(data->rPWMCtrlTS);
            comm_pwm_driver->pwmTestSelect(prCtrlTS->bTestSel);
            break; 
         }
         
         //pwm seq mode.
         case PWM_CMD_SEQ_START:
         {
            PWM_CTRL_SS_T   *prCtrlSS;
            prCtrlSS = &(data->rPWMCtrlSS);
            comm_pwm_driver->pwmSeqStart(rDclPWM.owner[iPWMNum], prCtrlSS->uEnCount);
            break;
         } 
         case PWM_CMD_SEQ_STOP:
         {
            comm_pwm_driver->pwmSeqStop(rDclPWM.owner[iPWMNum]);
            break;
         }
         case PWM_CMD_SEQ_CLOSE:
         {
            comm_pwm_driver->pwmSeqClose(rDclPWM.owner[iPWMNum]);
            for (idx=(kal_uint32)PWM3; idx < (kal_uint32)PWM_COUNT; idx++)
            {
               rDclPWM.PWMUsed &= ~(1<<idx);
            }
            break;
         }
         case PWM_CMD_SET_BUF_VALID:
         {
            PWM_CTRL_SBV_T   *prCtrlSBV;
            prCtrlSBV = &(data->rPWMCtrlSBV);
            comm_pwm_driver->pwmSetBufValid(rDclPWM.owner[iPWMNum], iPWMNum, (kal_uint32 *)prCtrlSBV->pu4BufAddr, prCtrlSBV->u2BufSize, prCtrlSBV->fgIsBuf0);
            break;
         }
         case PWM_CMD_SET_DELAY:
         {
            PWM_CTRL_SD_T *pPWMCtrlSD;
            pPWMCtrlSD=&(data->rPWMCtrlSD);
            comm_pwm_driver->pwmSetDelay(rDclPWM.owner[iPWMNum], iPWMNum,pPWMCtrlSD->u4ClkSel,pPWMCtrlSD->u2DelayCnt);
            break;
         }
         case PWM_CONFIG_FREQ_STEPS:
         {
            PWM_CONFIG_FREQ_STEPS_T *prPWMFreqConfig;
            prPWMFreqConfig=&(data->rPWMFreqConfig);
            comm_pwm_driver->pwm_config_freq_steps(rDclPWM.owner[iPWMNum], iPWMNum,prPWMFreqConfig->freq,prPWMFreqConfig->steps);
            break;
         }
         case PWM_CMD_SET_DUTY:
         {
            PWM_DUTY_T *prPWMCtrlDuty;
            prPWMCtrlDuty=&(data->rPWMCtrlDuty);
            comm_pwm_driver->pwmSetDuty(rDclPWM.owner[iPWMNum], iPWMNum,prPWMCtrlDuty->duty);
            break;
         }
         #endif //#if defined(DRV_PWM_RWG)
         	   
         //task run here in two case, one is commnad invaild ,the other is pwm call rwg command.
         default:
         {
            //"unknow PWM command in this chip"
            EXT_ASSERT(0,iPWMNum,cmd,0);
            return STATUS_INVALID_CMD;
         }
      }
      return STATUS_OK;
   }
   #if !defined(DRV_ALERTER_NOT_EXIST)
   else if(DCL_ALERTER_IS_HANDLE_MAGIC(handle))
   {
      switch(cmd)
      {
         case ALERTER_CMD_CONFIGURE :
         { 
            ALERTER_CONFIGURE_T *palertConfigure;
            palertConfigure=&(data->ralertConfigure);
            comm_alerter_driver->configure(palertConfigure->freq,palertConfigure->duty);
            break;
         }	
         case ALERTER_CMD_START :
         {
            comm_alerter_driver->start();
            break;
         }
  			case ALERTER_CMD_STOP :
         {
            comm_alerter_driver->stop();
            break;
         }
         case ALERTER_CMD_PWROPEN :
         {
            ALERTER_PWROPEN_T *palertPwrOpen;
            palertPwrOpen=&(data->ralertPwrOpen);
            comm_alerter_driver->pwropen(palertPwrOpen->poweron);
            break;
         }
         case ALERTER_CMD_OUTPUT :
         {
            ALERTER_OUTPUT_T *palertoutput;
            palertoutput=&(data->ralertOutput);
            comm_alerter_driver->output(palertoutput->output);
            break;
         }
         case ALERTER_CMD_PLAYNOTES :
         {
            ALERTER_PLAYNOTE_T *palertPlayNote;
            palertPlayNote= &(data->ralertPlayNote);
            comm_alerter_driver->playnotes(palertPlayNote->GetNotecallbac,palertPlayNote->endofAlter);
            break;
         }
         case ALERTER_CMD_STOPNOTES :
         {
            comm_alerter_driver->stop();
            break;
         }
         case ALERTER_CMD_SETBUZVOLUME:
         {
            ALERTER_SETVOLUMN_T *palertSetVolumn;
            palertSetVolumn = &(data->ralertSetVolumn);
            comm_alerter_driver->setbuzvolume(palertSetVolumn->volumn);
            break;
         }
         default:
         {
            //"unkonw alerter command"
            EXT_ASSERT(0,handle,cmd,0);
            return STATUS_INVALID_CMD;
         }
      }
   }
   #endif
   return STATUS_OK;
}

void PWM_level(kal_uint8 level)
{
   //extern kal_uint8  PWM1_LEVEL_SAVE;  
   int range = 0;  
   kal_uint32 owner=0;
   DCL_HANDLE pwm_handle;
   DCL_CTRL_DATA_T control;

   control.rPWMConfigOld.freq=PWM1_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM1_Level_Info[level-1][1];
   
   range = sizeof(PWM1_Level_Info) / (sizeof(kal_uint32)*2); 
   if (level > range)
      ASSERT(0);
   PWM_LEVEL_SAVE[0] = level;
    //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
      owner=kal_get_active_module_id();
   #endif
      if(0 == owner)
         owner=MOD_UEM;
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM1,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM1,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);
   }
}

void PWM2_level(kal_uint8 level)
{
   //extern kal_uint8  PWM2_LEVEL_SAVE; 
   int range = 0;  
   kal_uint32 owner=0;
   DCL_HANDLE pwm_handle;
   DCL_CTRL_DATA_T control;

   control.rPWMConfigOld.freq=PWM2_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM2_Level_Info[level-1][1];
   
   range = sizeof(PWM2_Level_Info) / (sizeof(kal_uint32)*2); 
   if (level > range)
      ASSERT(0);
   
   PWM_LEVEL_SAVE[1] = level;
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
      owner=kal_get_active_module_id();
   #endif
      if(0==owner)
         owner=MOD_UEM;
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM2,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);	
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM2,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);	  
   }
}

void PWM3_level(kal_uint8 level)
{
   #if defined(__PWM3_FOR_MMI__) ||defined(DRV_PWM_PWM3)
   //extern kal_uint8  PWM3_LEVEL_SAVE; 
   int range = 0;  
   kal_uint32 owner=0;
   DCL_HANDLE pwm_handle;
   DCL_CTRL_DATA_T control;

   control.rPWMConfigOld.freq=PWM3_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM3_Level_Info[level-1][1];
   
   range = sizeof(PWM3_Level_Info) / (sizeof(kal_uint32)*2); 
   if (level > range)
      ASSERT(0);
   
   PWM_LEVEL_SAVE[2] = level;
   
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
      owner=kal_get_active_module_id();
   #endif
      if(0==owner)
         owner=MOD_UEM;	
   
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM3,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);	
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM3,owner);   
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);	
   }
   #endif /*defined(__PWM3_FOR_MMI__) ||defined(DRV_PWM_PWM3)*/
}

#if defined(DRV_PWM_RWG) || defined(DRV_PWM_PWM4)
void PWM4_level(kal_uint8 level)
{
   //pwm_handle_s   *handle;
   //extern kal_uint8  PWM4_LEVEL_SAVE; 
   kal_uint32     range;
   kal_uint32 owner=0;
   DCL_HANDLE pwm_handle;
   DCL_CTRL_DATA_T control;
   control.rPWMConfigOld.freq=PWM4_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM4_Level_Info[level-1][1];

   range = sizeof(PWM4_Level_Info) / (sizeof(kal_uint32)*2);
   if (level > range)
      ASSERT(0); 
   PWM_LEVEL_SAVE[3] = level;
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
      owner=kal_get_active_module_id();
   #endif
      if(0==owner)
         owner=MOD_UEM;
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM4,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);	
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM4,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);	
   }
}
#endif //if defined(DRV_PWM_RWG) || defined(DRV_PWM_PWM4)

#if defined(DRV_PWM_RWG)
void PWM5_level(kal_uint8 level)
{
   //extern kal_uint8  PWM5_LEVEL_SAVE; 
   kal_uint32	    range;
   kal_uint32 		owner=0;
   DCL_HANDLE 		pwm_handle;
   DCL_CTRL_DATA_T control;
   control.rPWMConfigOld.freq=PWM5_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM5_Level_Info[level-1][1];

   range = sizeof(PWM5_Level_Info) / (sizeof(kal_uint32)*2);
   if (level > range)
      ASSERT(0);

   PWM_LEVEL_SAVE[4] = level;
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
   owner=kal_get_active_module_id();
   #endif
   if(0==owner)
      owner=MOD_UEM;
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM5,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM5,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);
   }
}

void PWM6_level(kal_uint8 level)
{
   //extern kal_uint8  PWM6_LEVEL_SAVE; 
   kal_uint32 	 range;
   kal_uint32 	 owner=0;
   DCL_HANDLE 	 pwm_handle;
   DCL_CTRL_DATA_T control;

   control.rPWMConfigOld.freq=PWM6_Level_Info[level-1][0];
   control.rPWMConfigOld.duty=PWM6_Level_Info[level-1][1];
	 
   range = sizeof(PWM6_Level_Info) / (sizeof(kal_uint32)*2);
   if(level > range)
      ASSERT(0);

   PWM_LEVEL_SAVE[5] = level;
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
   owner=kal_get_active_module_id();
   #endif
   if(0==owner)
      owner=MOD_UEM;
   if (level && level <= range)
   {
      pwm_handle=DclPWM_Open(DCL_PWM6,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_CONFIG_OLD,&control);
      DclPWM_Control(pwm_handle,PWM_CMD_START,0);
      DclPWM_Close(pwm_handle);
   }
   else
   {
      pwm_handle=DclPWM_Open(DCL_PWM6,owner);
      DclPWM_Control(pwm_handle,PWM_CMD_STOP,0);
      DclPWM_Close(pwm_handle);
   }
}
#endif //#if defined(DRV_PWM_RWG)

void Alter_level(kal_uint8 level)
{

#if !defined(DRV_ALERTER_NOT_EXIST)
extern kal_uint8  ALTER_LEVEL_SAVE;
   kal_uint32 range = 0;
   kal_uint32 	 owner=0;
   DCL_HANDLE	  alerter_handle;
   DCL_CTRL_DATA_T Configure;

#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/

   if (level > 5)
      ASSERT(0);
#if !defined(DRV_ALERTER_NOT_EXIST)
   ALTER_LEVEL_SAVE = level;
   //fota mode.
   #if !defined(__FUE__) && !defined(__UBL__)
	   owner=kal_get_active_module_id();
   #endif 
   if(0==owner)
      owner=MOD_UEM;  

   	 Configure.ralertConfigure.duty=Alter_Level_Info[level-1][1];
	 Configure.ralertConfigure.freq=Alter_Level_Info[level-1][0];
	 
	 range = sizeof(Alter_Level_Info) / (sizeof(kal_uint32)*2);
	 if (level && level <= range)
   {
    //  Alter_Configure(Alter_Level_Info[level-1][0],Alter_Level_Info[level-1][1]);
    //  Alter_Start();
      alerter_handle=DclPWM_Open(DCL_ALERTER,owner);
      DclPWM_Control(alerter_handle,ALERTER_CMD_CONFIGURE,&Configure);
      DclPWM_Control(alerter_handle,ALERTER_CMD_START,0);
      DclPWM_Close(alerter_handle);
   }
   else
   {
       alerter_handle=DclPWM_Open(DCL_ALERTER,owner);
	   DclPWM_Control(alerter_handle,ALERTER_CMD_START,0);
       DclPWM_Close(alerter_handle);
   }
#endif /*!defined(DRV_ALERTER_NOT_EXIST)*/
}
//#endif //#if defined(DRV_PWM_PWM)
//#endif //DCL_PWM_INTERFACE
#else
DCL_STATUS DclPWM_Close(DCL_HANDLE handle)
{
   return STATUS_UNSUPPORTED;	
}
DCL_STATUS DclPWM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;	
}

DCL_STATUS DclPWM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
   return STATUS_UNSUPPORTED;	
}
DCL_STATUS DclPWM_Initialize(void)
{
   return STATUS_UNSUPPORTED;	
}
DCL_HANDLE DclPWM_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return STATUS_UNSUPPORTED;	
}
DCL_STATUS DclPWM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}
void PWM2_level(kal_uint8 level)
{
  
}
void PWM_level(kal_uint8 level)
{

}
void PWM3_level(kal_uint8 level)
{

}
void PWM4_level(kal_uint8 level)
{

}
void PWM5_level(kal_uint8 level)
{

}
void PWM6_level(kal_uint8 level)
{

}
void Alter_level(kal_uint8 level)
{
   
}
#endif