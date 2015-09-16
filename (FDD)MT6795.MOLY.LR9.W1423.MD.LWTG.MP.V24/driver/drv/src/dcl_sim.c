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


#include "intrCtrl.h"

#include "cache_sw.h"
#include "init.h"

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
#else   /* __RVCT__ */
        /* get the return address */
        __asm {
            MOV retAddr,lr
        }
#endif  /* __RVCT__ */
	thdId = (kal_uint32)kal_get_current_thread_ID();


	/*
		In SIM DCL open, we only mark control block as assigned and return handle to user.
		We don't support one resource used by multiple applications, so the control block will be not re-assigned.
		Every time this function is called, we just find an unused control block, mark it assigned, and return the handle.
	*/
	
	kal_take_sem(dclSimArb, 1);
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
	return 0;
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
*  	STATUS_INVALID_HANDLE - It's a invalid handle.
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
		ASSERT(0);
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
			resource->driverHandle = 0;
			status = STATUS_OK;
			break;
		default:
			ASSERT(0);
			status = STATUS_INVALID_CONFIGURATION;
			break;
	}

	return status;
}
DCL_STATUS DclSIM_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
	ASSERT(0);
	return 	STATUS_UNSUPPORTED;
}

typedef DCL_STATUS (*DCL_SIM_CTRL_API) (DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);

DCL_STATUS DCL_SIM_CTRL_API_RST(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SIM_STATUS status;
	SIM_CTRL_RST_T *prRst;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prRst = &(data->rSIMRst);
	status = resource->driver->rst(prRst->ExpectVolt, prRst->ResultVolt, prRst->warm, resource->driverHandle);
	prRst->rstResult = status;
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_CMD(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	kal_uint32 status;
	SIM_CTRL_CMD_T *prCmd;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prCmd = &(data->rSIMCmd);
	status = resource->driver->cmd(prCmd->txData, prCmd->txSize, prCmd->rxData, prCmd->rxSize, resource->driverHandle);
	*prCmd->statusWord = status;
		
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_PWOFF(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	resource->driver->pwOff(resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_GET_CARD_INFO(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_GET_CARD_INFO_T *prInfo;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prInfo = &(data->rSIMGetCardInfo);
	resource->driver->getCardInfo(prInfo->info, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_SPEED(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_MAX_SPEED_T *prSetSpeed;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prSetSpeed = &(data->rSIMSetMaxSpeed);
	resource->driver->setSpeed(prSetSpeed->speed, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_PREFER_PROTOCOL(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_PREFER_PROTOCOL_T *prSetT;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prSetT = &(data->rSIMSetPreferProtocol);
	resource->driver->setPreferT(prSetT->T, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_STATUS DCL_SIM_CTRL_API_SET_CLK_STOP_MODE(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	SIM_CTRL_SET_CLK_STOP_MODE_T *prSetClkStop;
	DCL_SIM_RESOURCE *resource;

	/*check the handle*/
	if(0 == handle)
		ASSERT(0);
	resource = (DCL_SIM_RESOURCE *)handle;
	if(SIM_RESOURCE_HEAD != resource->guardHead || SIM_RESOURCE_TAIL != resource->guardTail)
		ASSERT(0);

	/*state check*/
	if (SIM_RSC_HANDLE_UDEF == resource->driverHandle)
		ASSERT(0);
	
	prSetClkStop = &(data->rSIMSetClkStopMode);
	resource->driver->setClockStopMode(prSetClkStop->mode, resource->driverHandle);
	
	return STATUS_OK;
}

DCL_SIM_CTRL_API	DclSIM_APITbl[] = 
{
	DCL_SIM_CTRL_API_RST,
	DCL_SIM_CTRL_API_CMD,
	DCL_SIM_CTRL_API_PWOFF,
	DCL_SIM_CTRL_API_GET_CARD_INFO,
	DCL_SIM_CTRL_API_SET_SPEED,
	DCL_SIM_CTRL_API_SET_PREFER_PROTOCOL,
	DCL_SIM_CTRL_API_SET_CLK_STOP_MODE,
};


DCL_STATUS DclSIM_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	DCL_STATUS status;

	/*dispatch*/
	if(SIM_CTRL_CMD_DUMMY_END > cmd){
		status = DclSIM_APITbl[cmd](handle, cmd, data);
	}
	else{
		ASSERT(0);
		status = STATUS_INVALID_CMD;
	}
	


	return status;	
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
