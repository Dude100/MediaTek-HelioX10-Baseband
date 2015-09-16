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
 *   ft_main.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 * removed!
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
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
 *
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
 * removed!
 * removed!
 *
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements for KAL
 *************************************************************************/
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "task_config.h"
#include "syscomp_config.h"
#include "svc_sap.h"
#include "nvram_msgid.h"
#include "ft_msgid.h"
//#include "wndrv_msgid.h"
#include "l1hisr_msgid.h"
#include "sim_public_msgid.h"
/*************************************************************************
 * System Service header
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
//MSBB remove #include "fctycomp_config.h"
#include "stdio.h"
#include "init.h"
/*************************************************************************
 * NVRAM header
 *************************************************************************/
#include "nvram_data_items.h"
#include "nvram_struct.h"
#include "nvram_enums.h"
/*************************************************************************
 * Custom header
 *************************************************************************/
#include "custom_nvram_config.h"
#include "custom_equipment.h"
/*************************************************************************
 * HAL header
 *************************************************************************/
#if !defined(__L1_STANDALONE__)
#include "device.h"  // for GPIO_DEV_LED_MAINLCD and LED_LIGHT_LEVEL5
#endif
/*************************************************************************
 * FT header
 *************************************************************************/
#include "ft_msg.h"
#include "ft_mem.h"
#include "ft_private.h"
#include "ft_customize.h"
#include "ft_fnc_l1rf.h"
//#include "ft_fnc_audio.h"
#include "ft_fnc_misc.h"
#include "ft_fnc_misc_ex.h"
#include "ft_fnc_custom.h"
#include "ft_fnc_aux.h"
#include "ft_fnc_wcdma.h"
//20130206 
#include "ft_fnc_tdscdma.h" 
#include "ft_fnc_fat.h"
#include "ft_fnc_nvram.h"
#include "ft_fnc_lterf.h"
/*************************************************************************
 * SIM header
 *************************************************************************/
#include "ps2sim_struct.h"
/*************************************************************************
 * Function declaration
 *************************************************************************/
void FT_Task(task_entry_struct * task_entry_ptr);
extern void L1T_DispatchReports(void);
kal_uint16   ft_gl_token=0;
kal_uint16   ft_gl_rf_token;
kal_uint16   ft_gl_l4aud_token;
kal_uint16   ft_gl_l4aud_ind_token;
kal_uint16   ft_gl_nvram_token;
kal_uint16   ft_gl_customer_token;
kal_uint16          ft_gl_l4aud_current_volume = 3;
peer_buff_struct    *ft_gl_l4aud_peer_buf = NULL;
extern kal_uint8    ft_gl_sim_cmd_type;  // sim cmd type from ft_fnc_misc.c

kal_char g_FT_debug_buf[128];
kal_uint16   FT_GetGolbalToken(void)
{
    return ft_gl_token;
}
/*************************************************************************
 * FUNCTION
 *  ft_create
 *
 * DESCRIPTION
 *
 * PARAMETERS
 *
 * RETURNS
 *  None
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
kal_bool
ft_create(comptask_handler_struct **handle)
{
    static const comptask_handler_struct ft_handler_info =
    {
        FT_Task,  /* task entry function */
        NULL,  /* task initialization function */
        NULL,  /* task configuration function */
        NULL,  /* task reset handler */
        NULL,  /* task termination handler */
    };

    *handle = (comptask_handler_struct *)&ft_handler_info;
    return KAL_TRUE;
}
/* ------------------------------------------------------------------------- */


/*******************************************************************************
 * FUNCTION
 *   FT_InitCalibrationData
 *
 * DESCRIPTION
 *   The calibration data fetch in power-on stage
 *
 * CALLS
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/
void FT_InitCalibrationData(task_entry_struct *task_entry_ptr)
{
    nvram_startup_req_struct *ptrMsg;
    ptrMsg = (nvram_startup_req_struct*)construct_local_para(sizeof(nvram_startup_req_struct), TD_CTRL);
    if(NULL == ptrMsg)
    {
        ASSERT(0);    
    }    
    ptrMsg->poweron_mode=NVRAM_POWERON_NORMAL;        
    msg_send5(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_STARTUP_REQ, (local_para_struct*)ptrMsg);
}

/*******************************************************************************
*
*  Local Functions
*
*******************************************************************************/
#ifdef L1_CATCHER
void Trc_Init(void);
#endif
static void FT_Initialization(task_entry_struct *task_entry_ptr)
{
    // active module ID in task_active_module_g
    kal_set_active_module_id(MOD_FT);
    FtInitMemoryPool();
    // custom init
    FT_CustomInit();
#if !defined(__L1_STANDALONE__)
    // enable main LCD backlight
    custom_cfg_gpio_set_level(GPIO_DEV_LED_MAINLCD, LED_LIGHT_LEVEL5);
#endif // #if !defined(__L1_STANDALONE__)
#ifdef L1_CATCHER
    // L1 logging initialization
    Trc_Init();
#endif // #ifdef L1_CATCHER
#if !defined(__LTE_SM__)
    L1TST_Init();
#endif // #if !defined(__LTE_SM__)    
    FT_InitCalibrationData(task_entry_ptr);
    FT_InitFtData();
#if ( defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) ) && defined(__MODEM_CARD__)
    /// clear USB download RTC bit for HSPA data card project 
    INT_SetCmdToSys(SYS_CMD_CLR_DL_FLAG);
#endif // #if ( defined(__HSDPA_SUPPORT__) || defined(__HSUPA_SUPPORT__) ) && defined(__MODEM_CARD__)
}

#ifdef __TOOL_ACCESS_CTRL__
// the definition should not be customized keep in FT task
typedef enum
{
    E_FT_IS_ALIVE_REQ_ID = 0
    ,E_FT_POWER_OFF_REQ_ID
    ,E_FT_VER_INFO_REQ_ID
    ,E_FT_RF_TEST_REQ_ID
    ,E_FT_URF_TEST_REQ_ID
    ,E_FT_UTILITY_COMMAND_REQ_ID
    ,E_FT_MISC_CMD_REQ_ID
    ,E_MAX_FT_BASIC_META_OPERATION
}E_FT_BASIC_META_OPERATION;
static const kal_uint16 FT_META_BasicOperationList[E_MAX_FT_BASIC_META_OPERATION] =
{
    FT_IS_ALIVE_REQ_ID // connecting META
    ,FT_POWER_OFF_REQ_ID // power off
    ,FT_VER_INFO_REQ_ID // query version information
    ,FT_RF_TEST_REQ_ID // 2G RF operation
    ,FT_URF_TEST_REQ_ID // 3G RF operation
    ,FT_UTILITY_COMMAND_REQ_ID // utility operation
    ,FT_MISC_CMD_REQ_ID // misc operations (including BK&RS request)
};
/*******************************************************************************
 * FUNCTION
 *   FT_META_IsBasicOperation
 *
 * DESCRIPTION
 *   Check the message ID belongs to one of the basic META mode operation
 *
 * CALLS
 *   none
 *
 * PARAMETERS
 *   msg_id the message ID of the request message
 *
 * RETURNS
 *   The indicator of the operation is basic META mode operation cross any state (MODE_ENTRY_SRC)
 *
 *******************************************************************************/
kal_bool FT_META_IsBasicOperation(kal_uint16 msg_id)
{
    kal_uint16 i;
    for(i=0;i<E_MAX_FT_BASIC_META_OPERATION;i++)
    {
        // check if the oepration is basic META mode operation
        if(FT_META_BasicOperationList[i] == msg_id)
        {
            // yes
            return KAL_TRUE;
        }
    }
    // not listed in the basic META mode operation
    return KAL_FALSE;
}
#endif // #ifdef __TOOL_ACCESS_CTRL__
void FT_DispatchMessage(ilm_struct* ptrMsg)
{
    FT_H  *ft_header;
    ft_header=(FT_H *)(ptrMsg->local_para_ptr);
#if !defined(__DHL_MODULE__)       
    if((ptrMsg->src_mod_id == MOD_TST_READER))
#else
    if((ptrMsg->src_mod_id == MOD_DHL))
#endif // #if !defined(__DHL_MODULE__)        	
    {
        ft_gl_token=ft_header->token;
#ifdef __TOOL_ACCESS_CTRL__
        // if it's not basic META mode operation, check the limited operation state
        if(!FT_META_IsBasicOperation(ft_header->ft_msg_id))
        {
            // check if the operation is allowed
            if(KAL_TRUE != Custom_META_IsAllowedLimitedStateOperation(ptrMsg))
            {
                return;
            }
        }
#endif // #ifdef __TOOL_ACCESS_CTRL__
        switch (ft_header->ft_msg_id)
        {
            /********************************************
             * L1 RF test functionality
             ********************************************/
#if !defined(__LTE_SM__)
            case FT_RF_TEST_REQ_ID:
            {
                FT_FtRfTestReq((ft_rf_test_req_T*)ptrMsg->local_para_ptr, ptrMsg->peer_buff_ptr);
                break;
            }
#endif // #if !defined(__LTE_SM__)
            /********************************************
             * BB test functionality
             ********************************************/
            case FT_REG_READ_ID:
            {
                FT_FtRegisterRead((ft_RegisterRead_req_T*)ptrMsg->local_para_ptr,FT_BaseBandReg);
                break;
            }
            case FT_REG_WRITE_ID:
            {
                FT_FtRegisterWrite((ft_RegisterWrite_req_T*)ptrMsg->local_para_ptr,FT_BaseBandReg);
                break;
            }
            case FT_PMIC_REG_READ_ID:
            {
                FT_FtPMICRegisterRead((ft_PMICRegisterRead_req_T*)ptrMsg->local_para_ptr,FT_PMICReg);
                break;
            }
            case FT_PMIC_REG_WRITE_ID:
            {
                FT_FtPMICRegisterWrite((ft_PMICRegisterWrite_req_T*)ptrMsg->local_para_ptr,FT_PMICReg);
                break;
            }
            case FT_ADC_GETMEADATA_ID:
            {
                FT_FtADC_GetMeaData((ft_FtADC_GetMeaData_req_T*)ptrMsg->local_para_ptr);
                break;
            }          
            /********************************************
             * UL1 RF test functionality
             ********************************************/
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
            case FT_URF_TEST_REQ_ID:
            {
                if(KAL_TRUE == UL1_IS_3G_FDD_EXIST())  //20130206
                {
                FT_FtURfTestReq( (ft_urf_test_req_T*)ptrMsg->local_para_ptr, ptrMsg->peer_buff_ptr );
                }
                else
                {
                    sprintf(g_FT_debug_buf, "[FT_DispatchMessage][FT_URF_TEST_REQ_ID] HW FDD does not exist.");
            	  tst_sys_trace(g_FT_debug_buf);
                }    
                break;
            }
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
            /********************************************
             *
             *  NVRAM functionality
             *
             ********************************************/
            case FT_NVRAM_GET_DISK_INFO_REQ_ID:
            {
                ilm_struct ilm_ptr;
                FT_NVRAM_GET_DISK_INFO_CNF *ptr_loc_para;
                // store nvram token id, because any of NVRAM command won't return immediately.
                ft_gl_nvram_token = ft_header->token;
                FT_ALLOC_OTHER_MSG(&ilm_ptr,sizeof(FT_NVRAM_GET_DISK_INFO_CNF));                
                ptr_loc_para=(FT_NVRAM_GET_DISK_INFO_CNF *)(ilm_ptr.local_para_ptr);
                /* if ptr_ilm != NULL*/
                ptr_loc_para->header.ft_msg_id=FT_NVRAM_GET_DISK_INFO_CNF_ID;
#if defined(__MOD_NVRAM__)
                if(nvram_get_disk_file_info(&(ptr_loc_para->diskfilesize), &(ptr_loc_para->freespace), &(ptr_loc_para->overhead))) {
                    ptr_loc_para->status = 0;
                }
                else {
                    ptr_loc_para->diskfilesize = 0;
                    ptr_loc_para->freespace = 0;
                    ptr_loc_para->overhead = 0;
                    ptr_loc_para->status = 1;
                }
#endif // #if defined(__MOD_NVRAM__)
                FT_SEND_MSG_TO_PC(&ilm_ptr);
                break;
            }
            case FT_NVRAM_RESET_REQ_ID:
            {   
                ilm_struct ptr_ilm;
                nvram_reset_req_struct *ptr_loc_para;
                // store nvram token id, because any of NVRAM command won't return immediately.
                ft_gl_nvram_token = ft_header->token;
                FT_ALLOC_OTHER_MSG(&ptr_ilm,sizeof( nvram_reset_req_struct));
                /* if ptr_ilm != NULL*/
                ptr_loc_para=(nvram_reset_req_struct *)(ptr_ilm.local_para_ptr);

                if( ((ft_nvram_reset_req_struct_T*)ptrMsg->local_para_ptr)->reset_category == 0) // reset all
                {

                    ptr_loc_para->reset_category= NVRAM_RESET_ALL; 
                } 
                else if( ((ft_nvram_reset_req_struct_T*)ptrMsg->local_para_ptr)->reset_category == 3) // reset certain
                {

                    ptr_loc_para->reset_category= NVRAM_RESET_CERTAIN; 
                } 
                else if( ((ft_nvram_reset_req_struct_T*)ptrMsg->local_para_ptr)->reset_category == 4) // reset factory
                {
                    ptr_loc_para->reset_category= NVRAM_RESET_FACTORY; 
                }
                else
                {
                    destroy_ilm(&ptr_ilm);
                    break; // directly break!, Let PC side timeout!
                }
                ptr_loc_para->app_id = NVRAM_APP_RESERVED;
                ptr_loc_para->LID=((ft_nvram_reset_req_struct_T*)ptrMsg->local_para_ptr)->file_idx;
                /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
                FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_RESET_REQ, &ptr_ilm);
                break;
            }
            case FT_NVRAM_READ_REQ_ID:
            {
                // store nvram token id, because any of NVRAM command won't return immediately.
                ft_gl_nvram_token = ft_header->token;
                FT_ReadFrom_NVRAM((ft_nvram_read_req_struct_T*)ptrMsg->local_para_ptr);
                break;
            }
            case FT_NVRAM_WRITE_REQ_ID:
            {
                ft_nvram_write_req_struct_T  *ptr_msg = (ft_nvram_write_req_struct_T*)( ptrMsg->local_para_ptr );
                // store nvram token id, because any of NVRAM command won't return immediately.
                ft_gl_nvram_token = ft_header->token;
                FT_WriteTo_NVRAM(ptr_msg,ptrMsg->peer_buff_ptr, ptrMsg);
                // ptrMsg->peer_buff_ptr=NULL;/* make sure the NVRAM will release the mem*/
                break;
            }
            case FT_NVRAM_LOCK_REQ_ID:
            {
                ilm_struct ptr_ilm;
                nvram_set_lock_req_struct *ptr_loc_para;
                ft_nvram_lock_req_struct_T  *ptr_msg = (ft_nvram_lock_req_struct_T *)(ptrMsg->local_para_ptr);
                // store nvram token id, because NVRAM command won't return immediately.
                ft_gl_nvram_token = ft_header->token;
                FT_ALLOC_OTHER_MSG(&ptr_ilm, sizeof(nvram_set_lock_req_struct));
                /* if ptr_ilm != NULL*/
                ptr_loc_para=(nvram_set_lock_req_struct *)(ptr_ilm.local_para_ptr);
                // if OTP lock or NVRAM lock
                if( NVRAM_LOCK_OTP == ptr_msg->lock_en ) {
                    ptr_loc_para->lock_en = NVRAM_LOCK_OTP;
                }
                else {
                    ptr_loc_para->lock_en = NVRAM_LOCK_ENABLE;
                }
                /* FT_SEND_MSG(src_mod, dest_mod, sap_id, msg_id, ilm_ptr) */
                FT_SEND_MSG(MOD_FT, MOD_NVRAM, PS_NVRAM_SAP, MSG_ID_NVRAM_SET_LOCK_REQ, &ptr_ilm);
                break;
            }
            /********************************************
             *
             *  FAT functionality
             *
             ********************************************/
            case FT_FAT_OPERATION_ID:
            {
                FT_FAT_Operation((FT_FAT_OPERATION *)ptrMsg->local_para_ptr, ptrMsg->peer_buff_ptr);
                break;
            }
            /********************************************
             *
             *  Version Info functionality
             *
             ********************************************/
            case FT_VER_INFO_REQ_ID:
            {
                FT_GetVersionInfo();
                break;
            }
            /********************************************
             *
             *  FT task test alive
             *
             ********************************************/
            case FT_IS_ALIVE_REQ_ID:
            {
                FT_TestAlive();
                break;
            }
            /********************************************
             *
             *  FT task Power Off
             *
             ********************************************/
            case FT_POWER_OFF_REQ_ID:
            {
                FT_PowerOff();
                break;
            }
            /********************************************
             *
             *  FT task utility command
             *
             ********************************************/
            case FT_UTILITY_COMMAND_REQ_ID:
            {
                FT_UtilityCommand(ptrMsg);
                break;
            }
            /********************************************
             *
             *  Misc utility command
             *
             ********************************************/
            case FT_MISC_CMD_REQ_ID:
            {
                FT_MISC_Operation(ptrMsg);
                break;
            }
            /********************************************
             *
             *  Misc EX utility command
             *
             ********************************************/
            case FT_MISC_EX_CMD_REQ_ID:
            {
                FT_MISC_EX_Operation(ptrMsg);
                break;
            }
            case FT_CUSTOM_REQ_ID:
            {
                // send message to FTC task
                ft_gl_customer_token = ft_header->token;
                FT_Custom_Operation(ptrMsg);
                break;
            }
#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
            case FT_AUX_REQ_ID:
            {
                if(KAL_TRUE == tl1_is_tdd_hw_exist())  //20130206
                {
                // send message to FTA task
                ft_gl_customer_token = ft_header->token;
                FT_Aux_Operation(ptrMsg);
            }
            else
            {
                 sprintf(g_FT_debug_buf, "[FT_DispatchMessage][FT_AUX_REQ_ID] HW TDD does not exist.");
            	 tst_sys_trace(g_FT_debug_buf);
            }               
            break;
            }
#endif // #if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
#if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
            case FT_ERF_TEST_REQ_ID:
            case FT_PHY_TOOL_REQ_ID:            	
            {
                FT_Erf_Operation(ptrMsg);
                break;
            }
#endif // #if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
            default:
            break;
        }
    }
    else if( (ptrMsg->src_mod_id == MOD_FTC) )
    {
        ft_gl_token = ft_gl_customer_token;
        FT_Handle_FTC_CNF(ptrMsg);
        ptrMsg->peer_buff_ptr=NULL; /* make sure the TST will release the mem*/
    }
#if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
    else if( (ptrMsg->src_mod_id == MOD_FTA) )
    {
        ft_gl_token = ft_gl_customer_token;
        FT_Handle_FTA_CNF(ptrMsg);
        ptrMsg->peer_buff_ptr=NULL; /* make sure the TST will release the mem*/
    }
#endif // #if defined(__UMTS_TDD128_MODE__) && defined(__AST_TL1_TDD__)
#if defined(__MOD_NVRAM__)
    else if( (ptrMsg->src_mod_id == MOD_NVRAM) )
    {
       switch (ptrMsg->msg_id)
       {
           case MSG_ID_NVRAM_READ_CNF:
           {
               nvram_read_cnf_struct *msg_ptr = NULL;
               // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
               ft_gl_token = ft_gl_nvram_token;
               msg_ptr=(nvram_read_cnf_struct*)ptrMsg->local_para_ptr;
               FT_ReadFrom_NVRAM_CNF(msg_ptr, ptrMsg->peer_buff_ptr );
               ptrMsg->peer_buff_ptr=NULL; /* make sure the TST will release the mem*/
               break;
           }
#if defined(__MOD_NVRAM__)&& defined(__SYSDRV_BACKUP_DISK_RAW__)
           case MSG_ID_NVRAM_CREATE_IMAGE_CNF:
           case MSG_ID_NVRAM_VERIFY_IMAGE_CNF:
           {
               FT_Handle_CNF_From_NVRAM(ptrMsg);
               break;
           }
#endif // #if defined(__MOD_NVRAM__)&& defined(__SYSDRV_BACKUP_DISK_RAW__)
           case MSG_ID_NVRAM_WRITE_CNF:
           {
               nvram_write_cnf_struct*  msg_ptr = NULL;
               // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
               ft_gl_token = ft_gl_nvram_token;
               msg_ptr=(nvram_write_cnf_struct*)ptrMsg->local_para_ptr;
               FT_WriteTo_NVRAM_CNF(msg_ptr);
               break;
           }
           case MSG_ID_NVRAM_RESET_CNF:
           {
               nvram_reset_cnf_struct*       msg_ptr;
               ilm_struct                    ilm_ptr;
               ft_nvram_reset_cnf_struct_T*  pMsg;
               // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
               ft_gl_token = ft_gl_nvram_token;
               msg_ptr=(nvram_reset_cnf_struct*)ptrMsg->local_para_ptr;
               FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_nvram_reset_cnf_struct_T));
               /* if ptrMsg != NULL*/
               pMsg=(ft_nvram_reset_cnf_struct_T*)ilm_ptr.local_para_ptr;
               pMsg->header.ft_msg_id=FT_NVRAM_RESET_CNF_ID;
               pMsg->status = msg_ptr->result;
               FT_SEND_MSG_TO_PC(&ilm_ptr);
               break;
           }
           case MSG_ID_NVRAM_SET_LOCK_CNF:
           {
               nvram_set_lock_cnf_struct*    msg_ptr;
               ilm_struct                    ilm_ptr;
               ft_nvram_lock_cnf_struct_T*   pMsg;
               // restore the previous token id to ft_gl_token, ft_gl_token will be used in FT_SEND_MSG().
               ft_gl_token = ft_gl_nvram_token;
               msg_ptr=(nvram_set_lock_cnf_struct*)ptrMsg->local_para_ptr;
               FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_nvram_lock_cnf_struct_T));
               /* if ptrMsg != NULL*/
               pMsg=(ft_nvram_lock_cnf_struct_T*)ilm_ptr.local_para_ptr;
               pMsg->header.ft_msg_id=FT_NVRAM_LOCK_CNF_ID;
               pMsg->status = msg_ptr->result;
               FT_SEND_MSG_TO_PC(&ilm_ptr);
               break;
           }
#if defined(__MTK_INTERNAL__)
           case MSG_ID_NVRAM_WRITE_IMEI_CNF:
           {
               nvram_write_imei_cnf_struct*    msg_ptr;
               FT_MISC_CNF           misc_cnf;
               msg_ptr=(nvram_write_imei_cnf_struct*)ptrMsg->local_para_ptr;
               misc_cnf.type = FT_MISC_OP_SET_IMEI_VALUE;
               if(msg_ptr->result == NVRAM_ERRNO_SUCCESS)
               {
                   misc_cnf.result.m_u2RecordIndex = msg_ptr->record_index;
                   misc_cnf.status = FT_CNF_OK;
               }
               else
               {
                   misc_cnf.result.m_u2RecordIndex = msg_ptr->result;
                   misc_cnf.status = FT_CNF_FAIL;
               }
               FT_MISC_SendCnf(&misc_cnf, NULL);
               break;
           }
#endif  //#if defined(__MTK_INTERNAL__)
           case MSG_ID_NVRAM_SDS_CNF:
           case MSG_ID_NVRAM_BIN_REGION_CNF:           	
           {
               FT_Handle_CNF_From_NVRAM(ptrMsg);
               break;
           }
           default:
               break;
       }
    }
#endif // end of #if defined(__MOD_NVRAM__)
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
    else if( (ptrMsg->src_mod_id == MOD_UL1TST) )
    {
       FT_UL1TST_SEND_CNF_BACK(ptrMsg);
    }
#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#if !defined(__LTE_SM__)
    else if(  MOD_MPH_L1HISR  == ptrMsg->src_mod_id && MSG_ID_L1TASK_WAKEUP == ptrMsg->msg_id )
    {
        /********************************************
         *
         *  Dispatch report from L1
         *
         ********************************************/
        L1T_DispatchReports();
    }
#endif // #if !defined(__LTE_SM__)    
#ifndef SIM_NOT_PRESENT
    else if( (ptrMsg->src_mod_id == MOD_SIM) && (ft_gl_sim_cmd_type != FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED))
    {
       switch (ptrMsg->msg_id)
       {
           case MSG_ID_SIM_RESET_CNF:
           {
               FT_MISC_CNF misc_cnf;
               sim_reset_cnf_struct *msg_ptr;
               msg_ptr=(sim_reset_cnf_struct*)ptrMsg->local_para_ptr;
               misc_cnf.type = FT_MISC_OP_CHECK_SIM1_INSERTED;
               misc_cnf.result.m_u1SIMInserted = (kal_bool)msg_ptr->is_sim_inserted; // get SIM inserted status here.  1:insert  , 0: not insert
               misc_cnf.status = FT_CNF_OK;
               FT_MISC_SendCnf(&misc_cnf, NULL);
           }
               break;
           default:
               break;
       }
    }
#ifdef __GEMINI__
    else if((ptrMsg->src_mod_id == MOD_SIM_2) && (ft_gl_sim_cmd_type != FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED))
    {
        switch (ptrMsg->msg_id)
        {
            case MSG_ID_SIM_RESET_CNF:
            {
                FT_MISC_CNF misc_cnf;
                sim_reset_cnf_struct *msg_ptr;
                msg_ptr=(sim_reset_cnf_struct*)ptrMsg->local_para_ptr;
                misc_cnf.type = FT_MISC_OP_CHECK_SIM2_INSERTED;
                misc_cnf.result.m_u1SIMInserted = (kal_bool)msg_ptr->is_sim_inserted; // get SIM inserted status here.  1:insert  , 0: not insert
                misc_cnf.status = FT_CNF_OK;
                FT_MISC_SendCnf(&misc_cnf, NULL);
                break;
            }
            default:
                break;
        }
    }
#endif // __GEMINI__
#ifdef GEMINI_PLUS
    else if((ptrMsg->src_mod_id >= MOD_SIM) && (ptrMsg->src_mod_id < MOD_SIM + GEMINI_PLUS) && 
            (ft_gl_sim_cmd_type == FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED))
    {
        switch (ptrMsg->msg_id)
        {
            case MSG_ID_SIM_RESET_CNF:
            {
                FT_MISC_CNF misc_cnf;
                sim_reset_cnf_struct *msg_ptr;
                msg_ptr=(sim_reset_cnf_struct*)ptrMsg->local_para_ptr;
                misc_cnf.type = FT_MISC_OP_CHECK_GEMINI_PLUS_SIM_INSERTED;
                misc_cnf.result.m_u1SIMInserted = (kal_bool)msg_ptr->is_sim_inserted; // get SIM inserted status here.  1:insert  , 0: not insert
                misc_cnf.status = FT_CNF_OK;
                FT_MISC_SendCnf(&misc_cnf, NULL);
                break;
            }
            default:
                break;
        }
    }
#endif // GEMINI_PLUS
#endif // SIM_NOT_PRESENT
#if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
    else if( MOD_ETSTM == ptrMsg->src_mod_id)
    {
        FT_Erf_ConfirmHandler(ptrMsg);
    }
#endif // #if defined(__LTE_RAT__)&&defined(__TSTM_ENABLE__)
}
/*******************************************************************************
 * FUNCTION
 *   FT_Task
 *
 * DESCRIPTION
 *   Entry point for the factory testing task. The function performs initialisation,
 *   then sits in an infinite loop reading messages or reports and dispatching
 *   them.
 *
 * CALLS
 *
 * PARAMETERS
 *   None
 *
 * RETURNS
 *   None
 *
 * GLOBALS AFFECTED
 *   None
 *******************************************************************************/

#define META_Version_Check_Fail  0
#define META_Version_Check_Required 0

void FT_Task(task_entry_struct * task_entry_ptr)
{
    ilm_struct current_ilm;
    FT_Initialization(task_entry_ptr);
    while ( 1 )
    {
        msg_receive_extq(&current_ilm );
        FT_DispatchMessage(&current_ilm );
        destroy_ilm(&current_ilm);
    }
}
