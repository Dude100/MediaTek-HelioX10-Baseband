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
 *    dcl_pmu.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the PMU driver.
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

#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "drv_features.h"
#include "drv_comm.h"
#include "syscomp_config.h"   /*MOD_BMT*/
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */

#include "kal_public_api.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "intrCtrl.h"
#include "dcl_pmu_common_sw.h"
#include "us_timer.h"

#ifndef DRV_PMIC_OFF

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
PMIC_ACCESS_DURATION_DBG pmic_access_duration_log[PMIC_DURATION_LOG_MAX][MAX_PMIC_DURATION_INFO_SIZE];
DCL_UINT32 pmic_access_duration_index = 0;
DCL_UINT32 pmic_access_timing_issue_log[MAX_PMIC_DURATION_INFO_SIZE];
DCL_UINT32 pmic_access_timing_issue_index = 0;
#endif // End of #if defined(DCL_PMIC_ACCESS_TIME_LOG)

PMU_CONTROL_HANDLER pmu_control_handler = 0;
static DCL_UINT32 dcl_pmu_handle_count = 0;
#if defined(__DRV_UPMU_SHARE_LDO__)
extern DCL_HANDLE LdoShareIdxTable[PMU_MULTIUSERS_HANDLE_NO];
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)

/*************************************************************************
* FUNCTION
*  DclPMU_Initialize
*
* DESCRIPTION
*  This function is to initialize PMU module
*
* PARAMETERS
*  None
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPMU_Initialize(void)
{
#if defined(MT6235PMU)
extern void dcl_pmu6235_init(void);
	dcl_pmu6235_init();
#elif defined(MT6236PMU)
extern void dcl_pmu6236_init(void);
	dcl_pmu6236_init();
#elif defined(MT6253PMU)
extern void dcl_pmu6253_init(void);
	dcl_pmu6253_init();
#elif defined(MT6326_CCCI)
extern void dcl_pmic6326_ccci_init(void);
	dcl_pmic6326_ccci_init();
#elif defined(MT6326)
extern void dcl_pmic6326_init(void);
	dcl_pmic6326_init();
#elif defined(MT6251PMU)
extern void dcl_pmu6251_init(void);
	dcl_pmu6251_init();
#elif defined(MT6252PMU)
extern void dcl_pmu6252_init(void);
	dcl_pmu6252_init();
#elif defined(MT6255PMU)
extern void dcl_pmu6255_init(void);
	dcl_pmu6255_init();
#elif defined(MT6256PMU)
extern void dcl_pmu6256_init(void);
	dcl_pmu6256_init();	
#elif defined(MT6276PMU)
extern void dcl_pmu6276_init(void);
	dcl_pmu6276_init();
#elif defined(MT6573PMU)
extern void dcl_pmu6573_init(void);
	dcl_pmu6573_init();
#elif defined(MT6329)
extern void dcl_pmic6329_init(void);
	dcl_pmic6329_init();    
#elif defined(MT6327)
extern void dcl_pmic6327_init(void);
	dcl_pmic6327_init();
#elif defined(MT6320)
extern void dcl_pmic6320_init(void);
	dcl_pmic6320_init();

#elif defined(MT6323)
extern void dcl_pmic6323_init(void);
	dcl_pmic6323_init();
#elif defined(MT6325)
extern void dcl_pmic6325_init(void);
	dcl_pmic6325_init();    
#endif //#if defined(MT6276PMU)

	return STATUS_OK;
}

/*************************************************************************
* FUNCTION
*  DclPMU_Open
*
* DESCRIPTION
*  This function is to open the PMU module and return a handle
*
* PARAMETERS
*  dev: only valid for DCL_PMU
*  flags: no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*  DCL_HANDLE_INVALID: Open failed.
*  other value: a valid handle
*
*************************************************************************/
DCL_HANDLE DclPMU_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	kal_uint32 handle;
#if !defined(__UBL__)		
	kal_uint32 savedMask=0;
#endif //#endif //#if !defined(__UBL__)
	
	if (dev != DCL_PMU){
		return DCL_HANDLE_INVALID;		// Incorrecr device ID
	}


#if defined(__DRV_UPMU_SHARE_LDO__)	
	while(DCL_TRUE)
	{
	kal_uint32 i;
#if !defined(__UBL__)	
	if(KAL_FALSE==kal_query_systemInit())
	{savedMask = SaveAndSetIRQMask();}
#endif //#if !defined(__UBL__)

		dcl_pmu_handle_count++;
		handle = dcl_pmu_handle_count;
		
	
		for (i=0;i<PMU_MULTIUSERS_HANDLE_NO;i++)
		{
			if (LdoShareIdxTable[i] == handle)
				break;
		}


#if !defined(__UBL__)		
	if(KAL_FALSE==kal_query_systemInit())
	{RestoreIRQMask(savedMask);}
#endif //#if !defined(__UBL__)	

		if(i>=PMU_MULTIUSERS_HANDLE_NO)
		{break;}


	}
#else

#if !defined(__UBL__)	
	if(KAL_FALSE==kal_query_systemInit())
	{savedMask = SaveAndSetIRQMask();}
#endif //#if !defined(__UBL__)

	dcl_pmu_handle_count++;
	handle = dcl_pmu_handle_count;

#if !defined(__UBL__)		
	if(KAL_FALSE==kal_query_systemInit())
	{RestoreIRQMask(savedMask);}
#endif //#if !defined(__UBL__)	

#endif //#if defined(__DRV_UPMU_SHARE_LDO__)	

	

	// Register DCL default lisr
	return handle;
}

/*************************************************************************
* FUNCTION
*  DclPMU_ReadData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPMU_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{

	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPMU_WriteData
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPMU_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{

	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPMU_Configure
*
* DESCRIPTION
*  This function is not supported for the PMU module now.
*
* PARAMETERS
*	N/A
*
* RETURNS
*	STATUS_UNSUPPORTED
*
*************************************************************************/
DCL_STATUS DclPMU_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{

	return STATUS_UNSUPPORTED;
}

/*************************************************************************
* FUNCTION
*  DclPMU_RegisterCallback
*
* DESCRIPTION
*  This function is to set callback function for the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*  event: Supported events:
*         EVENT_PMU_TIMEOUT: Watch dog time out interrupt
*  callback: the callback function for registered events
*
* RETURNS
*  STATUS_OK: Successfully register the callback function.
*  STATUS_INVALID_HANDLE: It's a invalid handle.
*  STATUS_NOT_OPENED: The module has not been opened.
*  STATUS_INVALID_EVENT: The event parameter is invalid.
*  STATUS_UNSUPPORTED: The function is NOT supported
*
*************************************************************************/
DCL_STATUS DclPMU_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{	
	return STATUS_UNSUPPORTED;
}


/*************************************************************************
* FUNCTION
*  DclPMU_Control
*
* DESCRIPTION
*  This function is to send command to control the PMU module.
*
* PARAMETERS
*  handle: The handle value returned from DclPMU_Open
*  cmd: a control command for PMU module
*       PMU38: Refer dcl_pmu38.c
*
*
*  data: The data of the control command
*        PMU38: Refer dcl_pmu38.c
*
*
* RETURNS
*  STATUS_OK: command is executed successfully.
*  STATUS_FAIL: command is failed.
*  STATUS_INVALID_CMD: It's a invalid command.
*
*************************************************************************/
DCL_STATUS DclPMU_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
#ifndef PMIC_PRESENT
	return STATUS_OK; // For PMIC = NONE
#else
#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    DCL_STATUS pmu_control_status;

    pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].start_time = ust_get_current_time();

    pmu_control_status = pmu_control_handler(handle,cmd,data);

    pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].cmd = cmd;
    pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].end_time);

    if(pmic_access_duration_log[PMIC_DCL_DBG][pmic_access_duration_index].duration_time > PMIC_ACCESS_DURATION_THRESHOLD)
    {
        pmic_access_timing_issue_log[pmic_access_timing_issue_index] = pmic_access_duration_index;
        pmic_access_timing_issue_index++;
        pmic_access_timing_issue_index = pmic_access_timing_issue_index&(MAX_PMIC_DURATION_INFO_SIZE - 1);
    }

    pmic_access_duration_index++;
    pmic_access_duration_index = pmic_access_duration_index&(MAX_PMIC_DURATION_INFO_SIZE - 1);
	return pmu_control_status;
#else
	return pmu_control_handler(handle, cmd, data);
#endif // End of #if defined(DCL_PMIC_ACCESS_TIME_LOG)
#endif	
	//return STATUS_INVALID_CMD;
}

/*************************************************************************
* FUNCTION
*  DclPMU_Close
*
* DESCRIPTION
*  This function is to close the PMU module.
*
* PARAMETERS
*  handle: the returned handle value of DclPMU_Open
*
* RETURNS
*  STATUS_OK
*
*************************************************************************/
DCL_STATUS DclPMU_Close(DCL_HANDLE handle)
{



#if defined(__DRV_UPMU_SHARE_LDO__)
	ldoShare_free_idx(handle);
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)

	return STATUS_OK;
}


#else // DRV_PMIC_OFF
DCL_STATUS DclPMU_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclPMU_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclPMU_Close(DCL_HANDLE handle)
{
    return STATUS_UNSUPPORTED;
}

#endif // DRV_PMIC_OFF


