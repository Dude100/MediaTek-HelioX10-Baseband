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
 *    dcl_sim.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	This Module defines DCL (Driver Common Layer) of the SIM card driver.
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
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "dcl.h"
#include "dma_sw.h"
#include "sim_al.h"
#include "sim_drv_HW_reg_MTK.h"
#include "sim_drv_HW_def_MTK.h"
#include "sim_drv_SW_struct.h"
#include "sim_drv_SW_function.h"
#include "sim_drv_SW_API.h"
#include "multi_icc_custom.h"

#include "intrCtrl.h"

#include    "sim_reg_adp.h"

#include "cache_sw.h"
#include "init.h"
#include "kal_public_api.h"
#ifdef DCL_SIM_INTERFACE

#if !defined(DRV_SIM_OFF)
/**************************************************************************
following defines static global variables used in this file
***************************************************************************/
static kal_bool fgSIMInit = KAL_FALSE;
static kal_semid dclSimArb;


#define SIM_RESOURCE_HEAD 0x5a5a5a5a
#define SIM_RESOURCE_TAIL 0xa5a5a5a5

#define SIM_RSC_HANDLE_UDEF	0xffffffff

typedef struct{
	kal_uint32 guardHead;
	kal_bool assigned;
	kal_uint32 thdId;
	kal_uint32 allocatedPoint;
	DCL_SIMDriver_t *driver;
	DCL_SIM_HW_CB driverHandle;
	kal_uint32 guardTail;
} DCL_SIM_RESOURCE;

static DCL_SIM_RESOURCE	simResource[DCL_SIM_MAX_INTERFACE];

/******************************************************************************************
*following are extern variables from other file
******************************************************************************************/
extern sim_ctrlDriver sim_ctrlDriver_All;

extern void sim_init_all_cb(void);


/***************************************************************************************
followings special test API for customer 
*****************************************************************************************/

DCL_HANDLE simFunctionalTestHandle[2] = {0,0};
#define LOCAL_MODE_MAGIC 0xc0
kal_bool simfactorytest=KAL_FALSE;
char simtest[50];

kal_bool SIM_ATP_functional_test(kal_uint32 SIM_index)
{

	usim_dcb_struct *usim_dcb;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(SIM_index);
   	usim_dcb = GET_USIM_CB(simInterface);

	sprintf(simtest,"=>SIM_ATP_functional_test:%d , mode:%d simif:%d",SIM_index,kal_query_boot_mode(),simInterface);
	DRV_ICC_print_str(simtest);

	simfactorytest=KAL_TRUE;

      	{
		DCL_CTRL_DATA_T reset_data;
		DCL_SIM_POWER ResultVolt_ptr;

		reset_data.rSIMRst.ExpectVolt = DCL_CLASS_C_18V;
		reset_data.rSIMRst.ResultVolt = &ResultVolt_ptr;
		reset_data.rSIMRst.warm = KAL_FALSE;
		reset_data.rSIMRst.rstResult = DCL_USIM_NO_ERROR;

		if(0 == simFunctionalTestHandle[SIM_index])
		{
			DCL_CONFIGURE_T configure;

			simFunctionalTestHandle[SIM_index] = DclSIM_Open(DCL_SIM, 0);
			configure.rSimConfig.apType = SIM_index | LOCAL_MODE_MAGIC; //SIM_index start from 0, SIM_ICC_APPLICATION_PHONE1 also start from 0
			DclSIM_Configure(simFunctionalTestHandle[SIM_index], &configure);
		}

		DclSIM_Control(simFunctionalTestHandle[SIM_index], SIM_CTRL_CMD_RST, &reset_data);


		usim_dcb->ownerTask=0;
		simfactorytest=KAL_FALSE;


		if(DCL_USIM_NO_ERROR == reset_data.rSIMRst.rstResult)
		{
			sprintf(simtest,"=>SIM_ATP_functional_test:%d , success",SIM_index);
			DRV_ICC_print_str(simtest);
			return 1;
		}
		else
		{
			sprintf(simtest,"=>SIM_ATP_functional_test:%d , fail",SIM_index);
			DRV_ICC_print_str(simtest);		
			return 0;
			//return 1000+reset_data.rSIMRst.rstResult;
		}
      	}
}

int usim_iftest_for_smt(kal_uint32 SIM_index)
{

	usim_dcb_struct *usim_dcb;
	kal_uint32 simInterface;

	simInterface = sim_get_logicalNum_from_app(SIM_index);
   	usim_dcb = GET_USIM_CB(simInterface);

	sprintf(simtest,"=>usim_iftest_for_smt:%d , mode:%d simif:%d",SIM_index,kal_query_boot_mode(),simInterface);
	DRV_ICC_print_str(simtest);

	simfactorytest=KAL_TRUE;

	{
		DCL_CTRL_DATA_T reset_data;
		DCL_SIM_POWER ResultVolt_ptr;

		reset_data.rSIMRst.ExpectVolt = DCL_CLASS_C_18V;
		reset_data.rSIMRst.ResultVolt = &ResultVolt_ptr;
		reset_data.rSIMRst.warm = KAL_FALSE;
		reset_data.rSIMRst.rstResult = DCL_USIM_NO_ERROR;
			
		if(0 == simFunctionalTestHandle[SIM_index])
                {
			DCL_CONFIGURE_T configure;
			
			simFunctionalTestHandle[SIM_index] = DclSIM_Open(DCL_SIM, 0);
			configure.rSimConfig.apType = SIM_index | LOCAL_MODE_MAGIC; //SIM_index start from 0, SIM_ICC_APPLICATION_PHONE1 also start from 0
			DclSIM_Configure(simFunctionalTestHandle[SIM_index], &configure);
		}

		DclSIM_Control(simFunctionalTestHandle[SIM_index], SIM_CTRL_CMD_RST, &reset_data);


		usim_dcb->ownerTask=0;
		simfactorytest=KAL_FALSE;


		return reset_data.rSIMRst.rstResult;
		
	}
}

int usim_iftest_for_smt_sim_test(void)
{
	int r1,r2;

	r1=usim_iftest_for_smt(0);
	r2=usim_iftest_for_smt(1);

	if (r1==0 && r2==0)
	{
		return 0;
	}
	else if(r1!=0 && r2==0)
	{
		return 1;
	}
	else if(r1==0 && r2!=0)
	{
		return 2;
	}
	else
	{
		return 3;
	}

	return 4;
}



/***************************************************************************************
followings are DCL SD API exported 
*****************************************************************************************/
/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to initialize the SD driver related resource.
*	This function should be called in system initialization before tasks are scheduling.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_OK : this should be the only return value since MSDC_initialize returns nothing.
*
*************************************************************************/
#if 0//defined SIM_DRV_IC_USB
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
DCL_STATUS DclSIM_Initialize(void)
{
	kal_uint32	maskedValue;
	kal_uint32	loopIndex;
	


	maskedValue = SaveAndSetIRQMask();
	if(KAL_FALSE == fgSIMInit){
		fgSIMInit = KAL_FALSE;
		RestoreIRQMask(maskedValue);
		kal_mem_set(simResource, 0, sizeof(DCL_SIM_RESOURCE) * DCL_SIM_MAX_INTERFACE);
		dclSimArb = kal_create_sem("SIM_DCL", 1);
		for(loopIndex = 0; DCL_SIM_MAX_INTERFACE > loopIndex; loopIndex ++){
			simResource[loopIndex].guardHead = SIM_RESOURCE_HEAD;
			simResource[loopIndex].guardTail = SIM_RESOURCE_TAIL;
			simResource[loopIndex].driverHandle = SIM_RSC_HANDLE_UDEF;
		}
		sim_init_all_cb();
#ifdef MEUT_ON_FPGA
		MT6302_test();
#endif
	}
	else{
		RestoreIRQMask(maskedValue);
	}
	
	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclSD_Initialize
*
* DESCRIPTION
* 	This function is to get SD DCL handler.
*
* PARAMETERS
*	eDev - only valid for DCL_SD.
*	flags -following bit stand for specific meaning.
*		DCL_SD_FLAGS_CARD1: to get a handle for card 1
*		DCL_SD_FLAGS_CARD2: to get a handle for card 2
*		DCL_SD_FLAGS_SIMPLUS: to get a handle for sim plus
*		Other values are prohibited
* RETURNS
*  DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*************************************************************************/
DCL_HANDLE DclSIM_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 retAddr = 0;
	kal_uint32 thdId;
	kal_uint32 loopIndex;
	
	
	if (dev != DCL_SIM)
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}

#if defined(__RVCT__)
        /* RVCT doesn't support inline assemlber; bypass temporarily */
        retAddr = 0;
#elif defined(__GCC__)
        /* GCC has function to support this */
        retAddr = (kal_uint32) __builtin_return_address (0);
#else   /* __RVCT__ */
        /* GCC has function to support this */
        retAddr = (kal_uint32) __builtin_return_address (0);

//        /* get the return address */
//        __asm {
//            MOV retAddr,lr
//        }
#endif  /* __RVCT__ */
	thdId = (kal_uint32)kal_get_current_thread_ID();


	/*
		In SIM DCL open, we only mark control block as assigned and return handle to user.
		We don't support one resource used by multiple applications, so the control block will be not re-assigned.
		Every time this function is called, we just find an unused control block, mark it assigned, and return the handle.
	*/
	
	kal_take_sem(dclSimArb, KAL_INFINITE_WAIT);
	for(loopIndex = 0; DCL_SIM_MAX_INTERFACE > loopIndex; loopIndex ++){
		if (KAL_FALSE == simResource[loopIndex].assigned){
			simResource[loopIndex].assigned = KAL_TRUE;
			simResource[loopIndex].thdId = thdId;
			simResource[loopIndex].allocatedPoint = retAddr;
			kal_give_sem(dclSimArb);
			return (DCL_HANDLE)(&simResource[loopIndex]);
		}
	}
	kal_give_sem(dclSimArb);
	return DCL_HANDLE_NONE;
}

DCL_STATUS DclSIM_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}
DCL_STATUS DclSIM_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclSIM_Configure
*
* DESCRIPTION
* 	This function is to configure SIM interface. This is an important funciton since we rely on this function to hook correct function table.
*
* PARAMETERS
*	handle - a valid handle return by DclSIM_Open()
*	configure - a ponter to SIM_CONFIG_T structure which is a member of union 
*              DCL_CONFIGURE_T.
* RETURNS
*	STATUS_OK - the configuration is done correctly.
*  	STATUS_INVALID_DCL_HANDLE - It's a invalid handle.
*  	STATUS_NOT_OPENED - The module has not been opened.
*  	STATUS_INVALID_CONFIGURATION - the configuration is not valid.
*
*************************************************************************/
DCL_STATUS DclSIM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	SIM_CONFIG_T *prConfg;
	DCL_SIM_RESOURCE *resource;
	DCL_STATUS status;

	/*check the handle*/
	if(0 == handle)
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
	
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF != resource->driverHandle || NULL != resource->driver)
		ASSERT(0);

	/*configure to use sim_ctrlDriver_Single for single SIM platform*/
	prConfg = (SIM_CONFIG_T *)configure;

	switch(prConfg->apType){
		case SIM_CONFIG_AP_TYPE_PHONE1:
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = SIM_ICC_APPLICATION_PHONE1;
			status = STATUS_OK;
			break;

		case (SIM_CONFIG_AP_TYPE_PHONE1 | LOCAL_MODE_MAGIC):
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = (SIM_ICC_APPLICATION_PHONE1 | LOCAL_MODE_MAGIC);
			status = STATUS_OK;
			break;

		case SIM_CONFIG_AP_TYPE_PHONE2:
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = SIM_ICC_APPLICATION_PHONE2;
			status = STATUS_OK;
			break;
			
		case (SIM_CONFIG_AP_TYPE_PHONE2 | LOCAL_MODE_MAGIC):
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = (SIM_ICC_APPLICATION_PHONE2 | LOCAL_MODE_MAGIC);
			status = STATUS_OK;
			break;			
			
		case SIM_CONFIG_AP_TYPE_PHONE3:
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = SIM_ICC_APPLICATION_PHONE3;
			status = STATUS_OK;
			break;
		case SIM_CONFIG_AP_TYPE_PHONE4:
			resource->driver = (DCL_SIMDriver_t *)&sim_ctrlDriver_All;
			/*driver handle will be the pointer to hw control block in the future, but before we finish SMD, we fix a workable uint32 here*/
			resource->driverHandle = SIM_ICC_APPLICATION_PHONE4;
			status = STATUS_OK;
			break;
		default:
			ASSERT(0);
			status = STATUS_INVALID_CONFIGURATION;
			break;
	}
#ifdef __SIM_HOT_SWAP_SUPPORT__    
	SIM_RegHotPlugCb((SIM_ICC_APPLICATION)prConfg->apType, prConfg->hotPlugInCb, prConfg->hotPlugOutCb);
#endif    
	return status;
}
DCL_STATUS DclSIM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}

typedef DCL_STATUS (*DCL_SIM_CTRL_API) (DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

/*dcl add new api : 6. add to new DCL control function*/

DCL_STATUS DCL_SIM_CTRL_API_RST(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SIM_STATUS status;
	SIM_CTRL_RST_T *prRst;
	DCL_SIM_RESOURCE *resource;

	resource = (DCL_SIM_RESOURCE *)handle;
	prRst = &(data->rSIMRst);
	status = resource->driver->rst(prRst->ExpectVolt, prRst->ResultVolt, prRst->warm, resource->driverHandle);
	prRst->rstResult = status;
	
#if 0//defined SIM_DRV_IC_USB
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_CMD(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	kal_uint32 status;
	SIM_CTRL_CMD_T *prCmd;
	DCL_SIM_RESOURCE *resource;

	resource = (DCL_SIM_RESOURCE *)handle;
	prCmd = &(data->rSIMCmd);
	status = resource->driver->cmd(prCmd->txData, prCmd->txSize, prCmd->rxData, prCmd->rxSize, resource->driverHandle);
	*prCmd->statusWord = status;
		
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_PWOFF(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SIM_RESOURCE *resource;

	
	resource = (DCL_SIM_RESOURCE *)handle;
	resource->driver->pwOff(resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_GET_CARD_INFO(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_GET_CARD_INFO_T *prInfo;
	DCL_SIM_RESOURCE *resource;

	
	resource = (DCL_SIM_RESOURCE *)handle;
	prInfo = &(data->rSIMGetCardInfo);
	resource->driver->getCardInfo(prInfo->info, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_SPEED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_MAX_SPEED_T *prSetSpeed;
	DCL_SIM_RESOURCE *resource;

	
	resource = (DCL_SIM_RESOURCE *)handle;
	prSetSpeed = &(data->rSIMSetMaxSpeed);
	resource->driver->setSpeed(prSetSpeed->speed, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_PREFER_PROTOCOL(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_PREFER_PROTOCOL_T *prSetT;
	DCL_SIM_RESOURCE *resource;

	
	resource = (DCL_SIM_RESOURCE *)handle;
	prSetT = &(data->rSIMSetPreferProtocol);
	resource->driver->setPreferT(prSetT->T, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_CLK_STOP_MODE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_CLK_STOP_MODE_T *prSetClkStop;
	DCL_SIM_RESOURCE *resource;

	
	resource = (DCL_SIM_RESOURCE *)handle;
	prSetClkStop = &(data->rSIMSetClkStopMode);
	resource->driver->setClockStopMode(prSetClkStop->mode, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_TOUT_TEST(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_TOUT_TEST_T *toutTest;
	DCL_SIM_RESOURCE *resource;	


	resource = (DCL_SIM_RESOURCE *)handle;
	toutTest = &(data->rSIMToutTest);
	resource->driver->toutTest(toutTest->toutValue, resource->driverHandle);

	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_GET_CARD_SPEED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_GET_SPEED_T *prSpeed; /*dcl add new api : 8. declare a pointer for the type*/
	DCL_SIM_RESOURCE *resource;


	resource = (DCL_SIM_RESOURCE *)handle;
	prSpeed = &(data->rSIMGetSpeed); /*dcl add new api : 9. cast to the pointer of the type*/
	*prSpeed->speed = resource->driver->getCardSpeed(resource->driverHandle); /*dcl add new api : 10. call the driver function*/

	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_QUERY_9000(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_QUERY_9000_T *prQuery9000;
	DCL_SIM_RESOURCE *resource;


	resource = (DCL_SIM_RESOURCE *)handle;
	prQuery9000 = &(data->rSIMQuery9000);
	*prQuery9000->got9000 = resource->driver->query9000WhenSelect(resource->driverHandle);

	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_SLT_RLT(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
#ifdef IC_MODULE_TEST
	SIM_CTRL_SET_SLT_RLT_T *pSIMSetSltRlt;
	DCL_SIM_RESOURCE *resource;

	resource = (DCL_SIM_RESOURCE *)handle;

   pSIMSetSltRlt = &(data->rSIMSetSltRlt);
	L1sim_Set_Slt_Rlt(pSIMSetSltRlt->rlt, resource->driverHandle);
#endif	
	return STATUS_OK;
}

/*dcl add new api : 7. add to function table*/
DCL_SIM_CTRL_API	DclSIM_APITbl[] = 
{
	DCL_SIM_CTRL_API_RST, // 0-th
	DCL_SIM_CTRL_API_CMD,
	DCL_SIM_CTRL_API_PWOFF,
	DCL_SIM_CTRL_API_GET_CARD_INFO,
	DCL_SIM_CTRL_API_SET_SPEED,
	DCL_SIM_CTRL_API_SET_PREFER_PROTOCOL, // 5-th
	DCL_SIM_CTRL_API_SET_CLK_STOP_MODE,
	DCL_SIM_CTRL_API_TOUT_TEST,
	DCL_SIM_CTRL_API_GET_CARD_SPEED,
	DCL_SIM_CTRL_API_QUERY_9000,
	DCL_SIM_CTRL_API_SET_SLT_RLT
};


DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS status;

	/*dispatch*/
	if(SIM_CTRL_CMD_MAX_VALUE > cmd){
		status = DclSIM_APITbl[cmd](handle, cmd, data);
	}
	else{
		ASSERT(0);
		status = STATUS_INVALID_CMD;
	}
	


	return status;	
}

DCL_STATUS DclSIM_Close(DCL_HANDLE handle)
{	
  DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
	{
		ASSERT(0);
		return STATUS_INVALID_DCL_HANDLE;
	}
	resource = (DCL_SIM_RESOURCE *)handle;
	
	kal_take_sem(dclSimArb, KAL_INFINITE_WAIT);
	resource->assigned = KAL_FALSE;
	resource->thdId = 0;
	resource->allocatedPoint = 0;
	/*Blue added*/
	resource->driverHandle = SIM_RSC_HANDLE_UDEF;
	resource->driver = NULL;
	kal_give_sem(dclSimArb);
	
	return STATUS_OK;
}
#else /*!defined(DRV_SIM_OFF)*/


DCL_STATUS DclSIM_Initialize(void)
{
	return STATUS_FAIL;
}

DCL_HANDLE DclSIM_Open(DCL_DEV dev, DCL_FLAGS flags)
{
   return DCL_HANDLE_INVALID;
}

DCL_STATUS DclSIM_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSIM_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSIM_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
	return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSIM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	return STATUS_FAIL;
}

DCL_STATUS DclSIM_Close(DCL_HANDLE handle)
{
	return STATUS_FAIL;
}

#endif /*!defined(DRV_SIM_OFF)*/

#endif /*DCL_SIM_INTERFACE*/

