/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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

/*******************************************************************************
 * Filename:
 * ---------
 *   ccci_fs_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Defines CCCI FS DHL debug messages
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI FS] Add CCCI FS DL trace log & sequence number between PS & L2
 *
 * removed!
 * removed!
 * [CCCI FS] Debug enhancement & Add log.
 *
 * removed!
 * removed!
 * [CCCI FS] Fix CMPT READ API LOG
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace (sdio)
 *
 * removed!
 * removed!
 * 	CCCI_FS compact read and profile trace
 *
 * removed!
 * removed!
 * Fix CCCIFS memory cpy offset issues
 *
 * removed!
 * removed!
 * a. Check-in cccifs new features (support 16KB I/O)
 * b. add __CCCIFS_SUPPORT__ option to related files
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#ifndef _CCCI_FS_TRACH_H
#define _CCCI_FS_TRACH_H


#if HIF_CONSOLE_TRACE_ENABLED != 1

#ifndef GEN_FOR_PC
 #include "kal_public_defs.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "ccci_fs_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

#endif /* HIF_CONSOLE_TRACE_ENABLED != 1 */

BEGIN_TRACE_MAP(MOD_CCCIFS)
   //4  <fatal_error_msg>, follow by ASSERT(0);

   TRC_MSG(CCCIFS_TR_PUT_BUF_ERR, "[CCCI_FS] size over FS shared buffer size in ccci_fs_put_buff")
   TRC_MSG(CCCIFS_TR_OPID_NG, "[CCCI_FS] the mismatch op id in ccci_fs_get_buff")
   TRC_MSG(CCCIFS_TR_VNUM_NG, "[CCCI_FS] the mismatch variable number in ccci_fs_get_buff")
   TRC_MSG(CCCIFS_TR_LV_LEN_NG, "[CCCI_FS] user reserved not enough memory space for carrying AP response at index (%d) (pLV[i].len (%d) < pTmp->len (%d))")
   TRC_MSG(CCCIFS_TR_RXEVNT_NG, "[CCCI_FS] ccci_fs_wait_rx received event NG with error code (%x)")
   TRC_MSG(CCCIFS_TR_RGPD_RELOAD_1ST_ERR, "[CCCI_FS] ccci_fs_task_init: cannot alloc enough gpd for CCCI_FS UL to_alloc(%d) num_alloc(%d)") 

   //4  <error_msg>
   TRC_MSG(CCCIFS_TR_GET_PORT_ERR, "[CCCI_FS] ccci_fs_get_port no free port busy port number (%d) return CCCI_FAIL")
   TRC_MSG(CCCIFS_TR_RGPD_DL_GET_TGPD_ERR, "[CCCI_FS] ccci_fs_put_buff allocate TGPD fail to_alloc(%d) num_alloc(%d)")
   TRC_MSG(CCCIFS_TR_DL_CCCI_W_ERR, "[CCCI_FS] ccci_fs_put_buff ccci_write fail return (%x)")
   TRC_MSG(CCCIFS_TR_WRAPPER_RET_ERR, "[CCCI_FS] CCCI_FS_OP_Wrapper return error (%d) port_index (%d)")
   TRC_MSG(CCCIFS_TR_CMPTREAD_OPIDMAP_ERR, "[CCCI_FS] NVRAM_CMPT_READ OPID bitmap error (%x)")

   //4 <warning>
   TRC_MSG(CCCIFS_TR_NO_COPY, "[CCCI_FS] Note the this is the NO COPY == 1 condition") 


   
   //4 <info_msg>
   TRC_MSG(CCCIFS_TR_RX_INFO, "[CCCI_FS] ccci_fs_ul_buff_process: CCCI_H addr(%x) CCCI_H(%x)(%x)(%x)(%x) ") 
   TRC_MSG(CCCIFS_TR_RGPD_RELOAD_1ST, "[CCCI_FS] ccci_fs_task_init: initialize reload RGPD (%d) current hwo_rgpd_count (%d) ") 
   TRC_MSG(CCCIFS_TR_RGPD_RELOAD, "[CCCI_FS] ccci_fs_ul_cb: reload RGPD (%d) current hwo_rgpd_count (%d) ") 
   TRC_MSG(CCCIFS_TR_DL_LT_4K, "[CCCI_FS] ccci_fs_put_buff: meet the case that downlink buffer size > MTU(4K). DL size(%d) TGPD request num(%d)") 

   //4 <trace_msg>
   /* CCCI_FS Wrapper */
   TRC_MSG(CCCIFS_TR_WRAPPER_GET_PORT_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper [GET_PORT] PASS return (%d) port_index (%d)") 
   TRC_MSG(CCCIFS_TR_WRAPPER_PUT_BUF_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper [PUT_BUF] PASS return (%d) port_index (%d) op_id (0x%x) in_para_cnt (%d)") 
   TRC_MSG(CCCIFS_TR_WRAPPER_WAIT_RX_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper [WAIT_RX] PASS port_index (%d) ") 
   TRC_MSG(CCCIFS_TR_WRAPPER_GET_BUF_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper [GETT_BUF] PASS return (%d) port_index (%d) op_id (0x%x) out_para_cnt (%d)") 
   TRC_MSG(CCCIFS_TR_WRAPPER_PUT_PORT_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper [PUT_PORT] PASS return (%d) port_index (%d)")
   TRC_MSG(CCCIFS_TR_WRAPPER_RET_OK, "[CCCI_FS] CCCI_FS_OP_Wrapper PASS total(%d) op(0x%x) ret(%d) idx(%d) time(%dus)(%d total_t)## s(%d)e(%d)dur(%d)")    
   TRC_MSG(CCCIFS_TR_WRAPPER_DL_SEQ, "[CCCI_FS] CCCI_FS_OP_Wrapper [DL SEQ] (%d)")

   /* CCCI_FS APIs */
   TRC_MSG(CCCIFS_TR_CMPTREAD_IN, "[CCCI_FS] ===> MD_NVARM_FS_CMPT_Read ") 
   TRC_MSG(CCCIFS_TR_CMPTREAD_RET, "[CCCI_FS] MD_NVARM_FS_CMPT_Read LV ret_val[%x][%x][%x] FileSize[%x][%x] read_bytes[%x][%x] read_data[%x][%x]") 
   TRC_MSG(CCCIFS_TR_CMPTREAD_OUT, "[CCCI_FS] <=== MD_NVARM_FS_CMPT_Read ") 
   TRC_MSG(CCCIFS_TR_CMPTREAD_USER_INPUT, "[CCCI_FS] User's CMPT_Read input: opid_map[%x] Flag[%x] Offset[%x] Whence[%x] Length[%x]") 

   TRC_MSG(CCCIFS_TR_OPEN_IN, "[CCCI_FS] ===> MD_FS_Open ") 
   TRC_MSG(CCCIFS_TR_OPEN_RET, "[CCCI_FS] MD_FS_Open LV [%x][%x]") 
   TRC_MSG(CCCIFS_TR_OPEN_OUT, "[CCCI_FS] <=== MD_FS_Open ") 

   TRC_MSG(CCCIFS_TR_OPENHINT_IN, "[CCCI_FS] ===> MD_FS_Open ") 
   TRC_MSG(CCCIFS_TR_OPENHINT_RET, "[CCCI_FS] MD_FS_Open LV [%x][%x][%x][%x]") 
   TRC_MSG(CCCIFS_TR_OPENHINT_OUT, "[CCCI_FS] <=== MD_FS_Open ")

   TRC_MSG(CCCIFS_TR_GETDKINFO_IN, "[CCCI_FS] ===> MD_FS_GetDiskInfo ") 
   TRC_MSG(CCCIFS_TR_GETDKINFO_RET, "[CCCI_FS] MD_FS_GetDiskInfo LV [%x][%x][%x][%x]") 
   TRC_MSG(CCCIFS_TR_IT_GETDKINFO_AP_TRACE, "[CCCI_FS] MD_FS_GetDiskInfo SectorsPerCluster(%d) TotalClusters(%d) FreeClusters(%d) ret(%d)") 
   TRC_MSG(CCCIFS_TR_GETDKINFO_OUT, "[CCCI_FS] <=== MD_FS_GetDiskInfo ") 

   TRC_MSG(CCCIFS_TR_CLOSE_IN,  "[CCCI_FS] ===> MD_FS_Close ") 
   TRC_MSG(CCCIFS_TR_CLOSE_RET, "[CCCI_FS] MD_FS_Close LV [%x][%x]") 
   TRC_MSG(CCCIFS_TR_CLOSE_OUT, "[CCCI_FS] <=== MD_FS_Close ") 

   TRC_MSG(CCCIFS_TR_READ_IN,  "[CCCI_FS] ===> MD_FS_Read ") 
   TRC_MSG(CCCIFS_TR_READ_RET, "[CCCI_FS] MD_FS_Read LV ret_val[%x][%x] read_bytes[%x][%x] read_data[%x][%x]") 
   TRC_MSG(CCCIFS_TR_READ_OUT, "[CCCI_FS] <=== MD_FS_Read ") 

   TRC_MSG(CCCIFS_TR_WRITE_IN,  "[CCCI_FS] ===> MD_FS_Write ") 
   TRC_MSG(CCCIFS_TR_WRITE_RET, "[CCCI_FS] MD_FS_Write LV ret_val[%x][%x] write_bytes[%x][%x]") 
   TRC_MSG(CCCIFS_TR_WRITE_OUT, "[CCCI_FS] <=== MD_FS_Write ") 

   TRC_MSG(CCCIFS_TR_SEEK_IN,  "[CCCI_FS] ===> MD_FS_Seek ") 
   TRC_MSG(CCCIFS_TR_SEEK_RET, "[CCCI_FS] MD_FS_Seek LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_SEEK_OUT, "[CCCI_FS] <=== MD_FS_Seek ") 

   TRC_MSG(CCCIFS_TR_GETFSZ_IN,  "[CCCI_FS] ===> MD_FS_GetFileSize ") 
   TRC_MSG(CCCIFS_TR_GETFSZ_RET, "[CCCI_FS] MD_FS_GetFileSize LV ret_val[%x][%x] file_size[%x][%x]") 
   TRC_MSG(CCCIFS_TR_GETFSZ_OUT, "[CCCI_FS] <=== MD_FS_GetFileSize ") 

   TRC_MSG(CCCIFS_TR_DEL_IN,  "[CCCI_FS] ===> MD_FS_Delete ") 
   TRC_MSG(CCCIFS_TR_DEL_RET, "[CCCI_FS] MD_FS_Delete LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_DEL_OUT, "[CCCI_FS] <=== MD_FS_Delete ") 

   TRC_MSG(CCCIFS_TR_GATT_IN,  "[CCCI_FS] ===> MD_FS_GetAttributes ") 
   TRC_MSG(CCCIFS_TR_GATT_RET, "[CCCI_FS] MD_FS_GetAttributes LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_GATT_OUT, "[CCCI_FS] <=== MD_FS_GetAttributes ") 

   TRC_MSG(CCCIFS_TR_MKDIR_IN,  "[CCCI_FS] ===> MD_FS_CreateDir ") 
   TRC_MSG(CCCIFS_TR_MKDIR_RET, "[CCCI_FS] MD_FS_CreateDir LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_MKDIR_OUT, "[CCCI_FS] <=== MD_FS_CreateDir ") 

   TRC_MSG(CCCIFS_TR_RMDIR_IN,  "[CCCI_FS] ===> MD_FS_RemoveDir ") 
   TRC_MSG(CCCIFS_TR_RMDIR_RET, "[CCCI_FS] MD_FS_RemoveDir LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_RMDIR_OUT, "[CCCI_FS] <=== MD_FS_RemoveDir ") 

   TRC_MSG(CCCIFS_TR_GDSZ_IN,  "[CCCI_FS] ===> MD_FS_GetFolderSize ") 
   TRC_MSG(CCCIFS_TR_GDSZ_RET, "[CCCI_FS] MD_FS_GetFolderSize LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_GDSZ_OUT, "[CCCI_FS] <=== MD_FS_GetFolderSize ")

   TRC_MSG(CCCIFS_TR_FSRENAME_IN,  "[CCCI_FS] ===> MD_FS_Rename ") 
   TRC_MSG(CCCIFS_TR_FSRENAME_RET, "[CCCI_FS] MD_FS_Rename LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FSRENAME_OUT, "[CCCI_FS] <=== MD_FS_Rename ")

   TRC_MSG(CCCIFS_TR_FSMV_IN,  "[CCCI_FS] ===> MD_FS_Move ") 
   TRC_MSG(CCCIFS_TR_FSMV_RET, "[CCCI_FS] MD_FS_Move LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FSMV_OUT, "[CCCI_FS] <=== MD_FS_Move ")

   TRC_MSG(CCCIFS_TR_FSCNT_IN,  "[CCCI_FS] ===> MD_FS_Count ") 
   TRC_MSG(CCCIFS_TR_FSCNT_RET, "[CCCI_FS] MD_FS_Count LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FSCNT_OUT, "[CCCI_FS] <=== MD_FS_Count ")

   TRC_MSG(CCCIFS_TR_XDEL_IN,  "[CCCI_FS] ===> MD_FS_XDelete ") 
   TRC_MSG(CCCIFS_TR_XDEL_RET, "[CCCI_FS] MD_FS_XDelete LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_XDEL_OUT, "[CCCI_FS] <=== MD_FS_XDelete ")

   TRC_MSG(CCCIFS_TR_FNDFST_IN,  "[CCCI_FS] ===> MD_FS_FindFirst ") 
   TRC_MSG(CCCIFS_TR_FNDFST_RET, "[CCCI_FS] MD_FS_FindFirst LV ret_val[%x][%x] File Info[%x][%x] File Name[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FNDFST_OUT, "[CCCI_FS] <=== MD_FS_FindFirst ")

   TRC_MSG(CCCIFS_TR_FNDNXT_IN,  "[CCCI_FS] ===> MD_FS_FindNext ") 
   TRC_MSG(CCCIFS_TR_FNDNXT_RET, "[CCCI_FS] MD_FS_FindNext LV ret_val[%x][%x] File Info[%x][%x] File Name[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FNDNXT_OUT, "[CCCI_FS] <=== MD_FS_FindNext ")

   TRC_MSG(CCCIFS_TR_FNDCLS_IN,  "[CCCI_FS] ===> MD_FS_FindClose ") 
   TRC_MSG(CCCIFS_TR_FNDCLS_RET, "[CCCI_FS] MD_FS_FindClose LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_FNDCLS_OUT, "[CCCI_FS] <=== MD_FS_FindClose ")

   TRC_MSG(CCCIFS_TR_GETDRV_IN,  "[CCCI_FS] ===> MD_FS_GetDrive ") 
   TRC_MSG(CCCIFS_TR_GETDRV_RET, "[CCCI_FS] MD_FS_GetDrive LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_GETDRV_OUT, "[CCCI_FS] <=== MD_FS_GetDrive ")

   TRC_MSG(CCCIFS_TR_GETCLUSZ_IN,  "[CCCI_FS] ===> MD_FS_GetClusterSize ") 
   TRC_MSG(CCCIFS_TR_GETCLUSZ_RET, "[CCCI_FS] MD_FS_GetClusterSize LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_GETCLUSZ_OUT, "[CCCI_FS] <=== MD_FS_GetClusterSize ")

   TRC_MSG(CCCIFS_TR_SETDKFG_IN,  "[CCCI_FS] ===> MD_FS_SetDiskFlag ") 
   TRC_MSG(CCCIFS_TR_SETDKFG_RET, "[CCCI_FS] MD_FS_SetDiskFlag LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_SETDKFG_OUT, "[CCCI_FS] <=== MD_FS_SetDiskFlag ")

   TRC_MSG(CCCIFS_TR_CLOSEALL_IN,  "[CCCI_FS] ===> MD_FS_CloseAll ") 
   TRC_MSG(CCCIFS_TR_CLOSEALL_RET, "[CCCI_FS] MD_FS_CloseAll LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_CLOSEALL_OUT, "[CCCI_FS] <=== MD_FS_CloseAll ")

   TRC_MSG(CCCIFS_TR_CLRDISKFG_IN,  "[CCCI_FS] ===> MD_FS_ClearDiskFlag ") 
   TRC_MSG(CCCIFS_TR_CLRDISKFG_RET, "[CCCI_FS] MD_FS_ClearDiskFlag LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_CLRDISKFG_OUT, "[CCCI_FS] <=== MD_FS_ClearDiskFlag ")

   TRC_MSG(CCCIFS_TR_SHUTDN_IN,  "[CCCI_FS] ===> MD_FS_ShutDown ") 
   TRC_MSG(CCCIFS_TR_SHUTDN_OUT, "[CCCI_FS] <=== MD_FS_ShutDown ")

   TRC_MSG(CCCIFS_TR_ULKALL_IN,  "[CCCI_FS] ===> MD_FS_UnlockAll ") 
   TRC_MSG(CCCIFS_TR_ULKALL_RET, "[CCCI_FS] MD_FS_UnlockAll LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_ULKALL_OUT, "[CCCI_FS] <=== MD_FS_UnlockAll ")

   TRC_MSG(CCCIFS_TR_LKFAT_IN,  "[CCCI_FS] ===> MD_FS_LockFAT ") 
   TRC_MSG(CCCIFS_TR_LKFAT_RET, "[CCCI_FS] MD_FS_LockFAT LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_LKFAT_OUT, "[CCCI_FS] <=== MD_FS_LockFAT ")

   TRC_MSG(CCCIFS_TR_OTPWR_IN,  "[CCCI_FS] ===> MD_FS_OTPWrite ") 
   TRC_MSG(CCCIFS_TR_OTPWR_RET, "[CCCI_FS] MD_FS_OTPWrite LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_OTPWR_OUT, "[CCCI_FS] <=== MD_FS_OTPWrite ")

   TRC_MSG(CCCIFS_TR_OTPRD_IN,  "[CCCI_FS] ===> MD_FS_OTPRead ") 
   TRC_MSG(CCCIFS_TR_OTPRD_RET, "[CCCI_FS] MD_FS_OTPRead LV ret_val[%x][%x] param1 [%x][%x]") 
   TRC_MSG(CCCIFS_TR_OTPRD_OUT, "[CCCI_FS] <=== MD_FS_OTPRead ")

   TRC_MSG(CCCIFS_TR_OTPQLEN_IN,  "[CCCI_FS] ===> MD_FS_OTPQueryLength ") 
   TRC_MSG(CCCIFS_TR_OTPQLEN_RET, "[CCCI_FS] MD_FS_OTPQueryLength LV ret_val[%x][%x] param1 [%x][%x]") 
   TRC_MSG(CCCIFS_TR_OTPQLEN_OUT, "[CCCI_FS] <=== MD_FS_OTPQueryLength ")

   TRC_MSG(CCCIFS_TR_OTPLK_IN,  "[CCCI_FS] ===> MD_FS_OTPLock ") 
   TRC_MSG(CCCIFS_TR_OTPLK_RET, "[CCCI_FS] MD_FS_OTPLock LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_OTPLK_OUT, "[CCCI_FS] <=== MD_FS_OTPLock ")

   TRC_MSG(CCCIFS_TR_OTPRSTORE_IN,  "[CCCI_FS] ===> MD_FS_Restore ") 
   TRC_MSG(CCCIFS_TR_OTPRSTORE_RET, "[CCCI_FS] MD_FS_Restore LV ret_val[%x][%x]") 
   TRC_MSG(CCCIFS_TR_OTPRSTORE_OUT, "[CCCI_FS] <=== MD_FS_Restore ")
   //4 <ut msg>

   //4 <misc_info_msg>
   TRC_MSG(CCCIFS_TR_TASK_INIT, "[CCCI_FS] Init Stage!! %d")

   //4 <IT>
   //4 <trace_msg>
   TRC_MSG(CCCIFS_TR_IT_START, "[CCCI_FS_IT] ===> cccifsit_task_main ") 
   TRC_MSG(CCCIFS_TR_IT_TRIGGER, "[CCCI_FS] cccifsit_task_main trigger test case") 
   TRC_MSG(CCCIFS_TR_IT_IDLE, "[CCCI_FS] cccifsit_task_main idle") 
   TRC_MSG(CCCIFS_TR_IT_END, "[CCCI_FS_IT] <=== cccifsit_task_main ")
   TRC_MSG(CCCIFS_TR_IT_PASS, "[CCCI_FS_IT] PASS!!!!! ")
   TRC_MSG(CCCIFS_TR_IT_FAIL, "[CCCI_FS_IT] FAIL!!!!! ")
   TRC_MSG(CCCIFS_TR_IT_CLN_PASS, "[CCCI_FS_IT_CLN] PASS!!!!! ")
   
   TRC_MSG(CCCIFS_TR_IT_CLN_FAIL, "[CCCI_FS_IT_CLN] FAIL!!!!! ")
   TRC_MSG(CCCIFS_TR_IT_SHUTDOWN_ERR, "[CCCI_FS] MD_FS_CloseAll/MD_FS_ShutDown test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FOLDER_T1_ERR, "[CCCI_FS] cccifs_it_create_dir test 1 FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FOLDER_T2_ERR, "[CCCI_FS] cccifs_it_create_dir test 2 FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FOLDER_T3_ERR, "[CCCI_FS] cccifs_it_create_dir test 3 FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FOLDER_T4_ERR, "[CCCI_FS] cccifs_it_create_dir test 4 FAIL!! ret(%d)")    

   TRC_MSG(CCCIFS_TR_IT_REMOVE_FOLDER_T1_ERR, "[CCCI_FS] cccifs_it_remove_dir test 1 FAIL!! ret(%d)")    

   TRC_MSG(CCCIFS_TR_IT_CREATE_FILE_T1_ERR, "[CCCI_FS] cccifs_it_file_op create CCCI_FS_IT_FILE_A FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FILE_T2_ERR, "[CCCI_FS] cccifs_it_file_op create CCCI_FS_IT_FILE_B FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CREATE_FILE_T3_ERR, "[CCCI_FS] cccifs_it_file_op create CCCI_FS_IT_FILE_C FAIL!! ret(%d)") 
   TRC_MSG(CCCIFS_TR_IT_WRITE_FILE_T1_ERR, "[CCCI_FS] cccifs_it_file_op write CCCI_FS_IT_FILE_A FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_WRITE_FILE_T2_ERR, "[CCCI_FS] cccifs_it_file_op write CCCI_FS_IT_FILE_B FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_WRITE_FILE_T3_ERR, "[CCCI_FS] cccifs_it_file_op write CCCI_FS_IT_FILE_C FAIL!! ret(%d)") 

   TRC_MSG(CCCIFS_TR_IT_READ_CREATE_FILE_T1_ERR, "[CCCI_FS] cccifs_it_read_op create CCCI_FS_IT_FILE_A FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_CREATE_FILE_T2_ERR, "[CCCI_FS] cccifs_it_read_op create CCCI_FS_IT_FILE_B FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_CREATE_FILE_T3_ERR, "[CCCI_FS] cccifs_it_read_op create CCCI_FS_IT_FILE_C FAIL!! ret(%d)") 
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_T1_ERR, "[CCCI_FS] cccifs_it_read_op read CCCI_FS_IT_FILE_A FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_T2_ERR, "[CCCI_FS] cccifs_it_read_op read CCCI_FS_IT_FILE_B FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_T3_ERR, "[CCCI_FS] cccifs_it_read_op read CCCI_FS_IT_FILE_C FAIL!! ret(%d)") 
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_C_T1_ERR, "[CCCI_FS] cccifs_it_read_op CCCI_FS_IT_FILE_A content not match FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_C_T2_ERR, "[CCCI_FS] cccifs_it_read_op CCCI_FS_IT_FILE_B WITH SEEK content not match FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_C_T3_ERR, "[CCCI_FS] cccifs_it_read_op CCCI_FS_IT_FILE_C content not match FAIL!! ret(%d)") 
   TRC_MSG(CCCIFS_TR_IT_SEEK_FILE_T1_ERR, "[CCCI_FS] cccifs_it_read_op CCCI_FS_IT_FILE_A seek FAIL!! ret(%d)")    

   TRC_MSG(CCCIFS_TR_IT_GETDKINFO_ERR, "[CCCI_FS] MD_FS_GetDiskInfo test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_LOCKFAT_ERR, "[CCCI_FS] MD_FS_LockFAT test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_UNLOCKALL_ERR, "[CCCI_FS] MD_FS_UnlockAll test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_CLRDFLAG_ERR, "[CCCI_FS] MD_FS_ClearDiskFlag test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_SETDFLAG_ERR, "[CCCI_FS] MD_FS_SetDiskFlag test FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_GETCSZ_ERR, "[CCCI_FS] MD_FS_GetClusterSize test FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_GET_DRV_ERR, "[CCCI_FS] MD_FS_GetDrive test FAIL!! ret(%d)")

   TRC_MSG(CCCIFS_TR_IT_OTP_READ_ERR, "[CCCI_FS] MD_FS_OTPRead test FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_OTP_WRITE_ERR, "[CCCI_FS] MD_FS_OTPWrite test FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_OTP_LEN_ERR, "[CCCI_FS] MD_FS_OTPQueryLength test FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_OTP_LOCK_ERR, "[CCCI_FS] MD_FS_OTPLock test FAIL!! ret(%d)")

   TRC_MSG(CCCIFS_TR_IT_CREATE_FILE_FF_ERR, "[CCCI_FS] cccifs_it_find_op create CCCI_FS_IT_FILE_A_LV2 FAIL!! ret(%d)")  
   TRC_MSG(CCCIFS_TR_IT_FF_ERR, "[CCCI_FS] cccifs_it_find_op MD_FS_FindFirst FAIL!! ret(%d)")  
   TRC_MSG(CCCIFS_TR_IT_FN_ERR, "[CCCI_FS] cccifs_it_find_op MD_FS_FindNext FAIL!! ret(%d)")  
   TRC_MSG(CCCIFS_TR_IT_FC_ERR, "[CCCI_FS] cccifs_it_find_op MD_FS_FindNext FAIL!! ret(%d)")   
   
   TRC_MSG(CCCIFS_TR_IT_FMISC_CREATE_FILE_ERR, "[CCCI_FS] cccifs_it_file_path_op open CCCI_FS_IT_FILE_A FAIL!! ret(%d)")  
   TRC_MSG(CCCIFS_TR_IT_FMISC_GSZ_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_GetFileSize FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_GFA_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_GetAttributes FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_FSC_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Count FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_RENAME_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Rename FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_RNCREATE_ERR, "[CCCI_FS] cccifs_it_file_path_op rename open new file FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_READ_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Read Rename FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_READRLT_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Read Rename result FAIL!! ret(%d)")     

   TRC_MSG(CCCIFS_TR_IT_FMISC_MV_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Move FAIL!! ret(%d)")  
   TRC_MSG(CCCIFS_TR_IT_FMISC_MVCREATE_ERR, "[CCCI_FS] cccifs_it_file_path_op move open new file FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_READMV_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Read move FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_FMISC_READRLTMV_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Read result move FAIL!! ret(%d)")     

   TRC_MSG(CCCIFS_TR_IT_FMISC_DELF_ERR, "[CCCI_FS] cccifs_it_file_path_op MD_FS_Delete FAIL!! ret(%d)")  


   TRC_MSG(CCCIFS_TR_IT_READ_CREATE_FILE_16K_ERR, "[CCCI_FS] cccifs_it_16kio_process create CCCI_FS_MAX_IO_16K FAIL!! ret(%d)")    
   TRC_MSG(CCCIFS_TR_IT_WRITE_FILE_16K_ERR, "[CCCI_FS] cccifs_it_16kio_process write CCCI_FS_MAX_IO_16K FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_SEEK_FILE_16K_ERR, "[CCCI_FS] cccifs_it_16kio_process seek FAIL!! ret(%d)")
   TRC_MSG(CCCIFS_TR_IT_READ_FILE_16K_ERR, "[CCCI_FS] cccifs_it_16kio_process MD_FS_Read FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_READ_RESULT_16K_ERR, "[CCCI_FS] cccifs_it_16kio_process result comparing FAIL!! ret(%d)")     
   TRC_MSG(CCCIFS_TR_IT_16K_PASS, "[CCCI_FS] cccifs_it_16kio_process PASS!!!!! ")
   
   TRC_MSG(CCCIFS_TR_OP_TIME, "[CCCI_FS] CCCI_FS_OP_Wrapper idx(%d) time(%dms) (%dqbit) ")
   
END_TRACE_MAP(MOD_CCCIFS)


#endif //#ifndef _CCCI_FS_TRACH_H
