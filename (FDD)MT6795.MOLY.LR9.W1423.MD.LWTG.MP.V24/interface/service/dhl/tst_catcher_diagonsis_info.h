/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
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
*******************************************************************************/


/*****************************************************************************
 *
 * Filename:
 * ---------
 * tst_catcher_diagonsis_info.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains the exception handle diagnosis Info of Catcher
 *   With this file, catcher can detect the memory dump failure cause and find the proper owner.
 * 
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __TST_CATCHER_DIAGONOSIS_INFO_H__
#define __TST_CATCHER_DIAGONOSIS_INFO_H__


#if defined(GEN_FOR_PC)

typedef enum
{
  //Format: CATCHER_EXC_MODULES_[Function],
  //Format: CATCHER_EXC_OWNER_[Function]_[Owner Fist Name]_[Owner Last Name]  = CATCHER_EXC_MODULES_[Function],
  CATCHER_EXC_MODULES_UARTUSB,
#if defined(__DHL_SP_LOGGING_SUPPORT__)
    CATCHER_EXC_OWNER_USB_Wenbo_Ning=CATCHER_EXC_MODULES_UARTUSB, //owners should be up-to-date
#else
    CATCHER_EXC_OWNER_USB_TJ_Chang=CATCHER_EXC_MODULES_UARTUSB, //owners should be up-to-date
#endif 
  CATCHER_EXC_OWNER_UART_Shenghui_Shi=CATCHER_EXC_MODULES_UARTUSB, //owners should be up-to-date
  CATCHER_EXC_MODULES_COMPORT,  
#if defined(__DHL_SP_LOGGING_SUPPORT__)
    CATCHER_EXC_OWNER_COMPORT_Justin_Hsieh=CATCHER_EXC_MODULES_COMPORT, //owners should be up-to-date
#else
    CATCHER_EXC_OWNER_COMPORT_TJ_Chang=CATCHER_EXC_MODULES_COMPORT, //owners should be up-to-date
#endif   
  CATCHER_EXC_MODULES_WATCHDOG,
  CATCHER_EXC_OWNER_WATCHDOG_Mick_Lin = CATCHER_EXC_MODULES_WATCHDOG, //owners should be up-to-date
  CATCHER_EXC_MODULES_CORESONIC_DSP,
  CATCHER_EXC_OWNER_DSP_KirkLee = CATCHER_EXC_MODULES_CORESONIC_DSP, //owners should be up-to-date 
  CATCHER_EXC_MODULES_CCCI,
  CATCHER_EXC_OWNER_CCCI_Iwei_Tsai = CATCHER_EXC_MODULES_CCCI, //owners should be up-to-date
  CATCHER_EXC_MODULES_FLC,
  CATCHER_EXC_OWNER_FLC_TC_Chang = CATCHER_EXC_MODULES_FLC, //owners should be up-to-date
  CATCHER_EXC_MODULES_FLASH,
  CATCHER_EXC_OWNER_FLASH_Yaohua_Liu = CATCHER_EXC_MODULES_FLASH, //owners should be up-to-date  
  CATCHER_EXC_MODULES_FS,
  CATCHER_EXC_OWNER_FS_Stanley_Chu = CATCHER_EXC_MODULES_FS, //owners should be up-to-date    
  CATCHER_EXC_MODULES_NVRAM,
  CATCHER_EXC_OWNER_NVRAM_Qinghua_Yu = CATCHER_EXC_MODULES_NVRAM, //owners should be up-to-date
  CATCHER_EXC_MODULES_SS,
  CATCHER_EXC_OWNER_ExceptionHandle_Qmei_Yang = CATCHER_EXC_MODULES_SS,
  CATCHER_EXC_MODULES_SWLA,
  CATCHER_EXC_OWNER_ExceptionHandle_Woody_Kuo = CATCHER_EXC_MODULES_SWLA,
  CATCHER_EXC_MODULES_TIMER,
  CATCHER_EXC_OWNER_ExceptionHandle_ChinChieh_Hung = CATCHER_EXC_MODULES_TIMER, //owners should be up-to-date
  CATCHER_EXC_MODULES_TOPSM,
  CATCHER_EXC_OWNER_ExceptionHandle_Alvin_Chen = CATCHER_EXC_MODULES_TOPSM, //owners should be up-to-date
  CATCHER_EXC_MODULES_DHL,  
  CATCHER_EXC_OWNER_DHL_Mojo_Lai = CATCHER_EXC_MODULES_DHL, //owners should be up-to-date
}
catcher_exception_handler_owner_list_t;

typedef enum
{ //format OWNER____[trace name]
  //____ can't be shown in the trace name
  OWNER____TST_EX_MSG_NESTED_EX_DETECTED                      = CATCHER_EXC_MODULES_SS,
  OWNER____TST_EX_MSG_DUMP_SST_LOG_START                      = CATCHER_EXC_MODULES_SS,
  OWNER____TST_EX_MSG_DUMP_SST_LOG_END                        = CATCHER_EXC_MODULES_DHL,
  OWNER____TST_EX_MSG_REDUMP_PS_BUF_START                     = CATCHER_EXC_MODULES_DHL,
  OWNER____TST_EX_MSG_REDUMP_PS_BUF_END                       = CATCHER_EXC_MODULES_DHL,
  
  OWNER____SST_EXC_WATCHDOG_RESET_ENTER                    = CATCHER_EXC_MODULES_WATCHDOG,
  OWNER____SST_EXC_WATCHDOG_RESET_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_WATCHDOG_DISABLE_ENTER                  = CATCHER_EXC_MODULES_WATCHDOG,
  OWNER____SST_EXC_WATCHDOG_DISABLE_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OPEN_LOGGING_PORT_ENTER                 = CATCHER_EXC_MODULES_DHL,
  OWNER____SST_EXC_OPEN_LOGGING_PORT_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_UST_GET_TIME_ENTER                      = CATCHER_EXC_MODULES_TIMER,
  OWNER____SST_EXC_UST_GET_TIME_EXIT                       = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_USC_GET_TIME_ENTER                      = CATCHER_EXC_MODULES_TIMER,
  OWNER____SST_EXC_USC_GET_TIME_EXIT                       = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_NOTIFY_DSP_ENTER                        = CATCHER_EXC_MODULES_CORESONIC_DSP,
  OWNER____SST_EXC_NOTIFY_DSP_EXIT                         = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CCCI_HANDSHAKING_ENTER                  = CATCHER_EXC_MODULES_CCCI,
  OWNER____SST_EXC_CCCI_HANDSHAKING_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_TOPSM_ENABLE_FRC_ENTER                  = CATCHER_EXC_MODULES_TOPSM,
  OWNER____SST_EXC_TOPSM_ENABLE_FRC_EXIT                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_RESET_HARDWARE_ENTER                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_RESET_HARDWARE_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_EXCEPTION_RECORD_ENTER             = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_EXCEPTION_RECORD_EXIT              = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_VFP_REGISTER_DUMP_ENTER                 = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_VFP_REGISTER_DUMP_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CLEAR_PENDING_LOG_ENTER                 = CATCHER_EXC_MODULES_DHL,
  OWNER____SST_EXC_CLEAR_PENDING_LOG_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXC_MSG_ENTER                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXC_MSG_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INVOKE_SST_ENGINE_ENTER                 = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INVOKE_SST_ENGINE_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXCEPTION_RECORD_ENTER           = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_OUTPUT_EXCEPTION_RECORD_EXIT            = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_SWLA_PRINT_LOWRAM_ENTER                 = CATCHER_EXC_MODULES_SWLA,
  OWNER____SST_EXC_SWLA_PRINT_LOWRAM_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_PASS_CCCI_EXCINFO_ENTER                 = CATCHER_EXC_MODULES_CCCI,
  OWNER____SST_EXC_PASS_CCCI_EXCINFO_EXIT                  = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FLC_DEBUG_INFO_ENTER                    = CATCHER_EXC_MODULES_FLC,
  OWNER____SST_EXC_FLC_DEBUG_INFO_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_FDD_TABLE_ENTER                    = CATCHER_EXC_MODULES_FLASH,
  OWNER____SST_EXC_INIT_FDD_TABLE_EXIT                     = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_SAVE_EXCEPTION_RECORD_ENTER             = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_SAVE_EXCEPTION_RECORD_EXIT              = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FS_UNLOCK_ALL_ENTER                     = CATCHER_EXC_MODULES_FS,
  OWNER____SST_EXC_FS_UNLOCK_ALL_EXIT                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_FS_SHUTDOWN_ENTER                       = CATCHER_EXC_MODULES_FS,
  OWNER____SST_EXC_FS_SHUTDOWN_EXIT                        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_NVRAM_WRITE_EXC_ENTER                   = CATCHER_EXC_MODULES_NVRAM,
  OWNER____SST_EXC_NVRAM_WRITE_EXC_EXIT                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_TST_DUMP2FILE_ENTER                     = CATCHER_EXC_MODULES_DHL,
  OWNER____SST_EXC_TST_DUMP2FILE_EXIT                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_DUMP_USB_DEBUG_DATA_ENTER               = CATCHER_EXC_MODULES_UARTUSB,
  OWNER____SST_EXC_DUMP_USB_DEBUG_DATA_EXIT                = CATCHER_EXC_MODULES_SS,
  
  OWNER____SST_EXC_RESET_EXCSP_ENTER                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_RESET_EXCSP_EXIT                       = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_MINILOG_DUMP_ENTER                     = CATCHER_EXC_MODULES_DHL,
  OWNER____SST_EXC_MINILOG_DUMP_EXIT                      = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CLEAN_RES_PROT_ENTER                   = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CLEAN_RES_PROT_EXIT                    = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_UNGUARD_STACKSPACE_ENTER               = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_UNGUARD_STACKSPACE_EXIT                = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_DUMP_ENTER                        = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_INIT_DUMP_EXIT                         = CATCHER_EXC_MODULES_SS,
  OWNER____SST_EXC_CORESONIC_DSP_DUMP_DEBUGINFO_ENTER     = CATCHER_EXC_MODULES_CORESONIC_DSP,
  OWNER____SST_EXC_CORESONIC_DSP_DUMP_DEBUGINFO_EXIT      = CATCHER_EXC_MODULES_SS,

  OWNER____SST_EXC_HANDOVER2TST                                       = CATCHER_EXC_MODULES_DHL,
}
catcher_exception_handler_owner_mapping_t;

typedef enum{
        sys_mem___Qmei_Yang,
        bb_reg___Qmei_Yang,
        swla___Woody_Kuo,
        dsp_mem___Sean_Yang,
        coresonic_dsp_mem___Ethan_Hsieh,
        ast_mem___Fanzhi_Meng,
}catcher_BEE_failed_readmem_owner;

#endif //#if defined(GEN_FOR_PC) 
 
#endif //__TST_CATCHER_DIAGONOSIS_INFO_H__
