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
 *   bl_SDIO_drv.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   This file defines the SDIO driver used for X-Booting
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __X_BOOTING__

#include "kal_general_types.h"
#include "bl_SDIO_drv.h"
#include "br_sd_sdio_export_v1.h"
#include "br_sd_common_export_v1.h"
#include "sdio_gpd.h"
#include "sdio_fw_api.h"
#include "bl_sectiondef.h"

/*************************************************************************
 * Macro and const definition
 *************************************************************************/
#define SDIO_TX_GPDH_NUM               (5)     //real BL need this
#define SDIO_RX_GPDH_NUM               (1)     //real BL need this

/*************************************************************************
 * Structure definition
 *************************************************************************/
//[CAUTION] SDIO can only send 4091 bytes actual data + 4 bytes header.
//The SDIO driver needs a temp buffer to re-org the receieve data and then copy to actual destination.
//It is awkward!!!
//Here we define the temp buffer, NOTE. It must be 4 bytes aligned!!
union {
    U32 m_data32 ;                      //keep the buffer 4B aligned
    U8  m_data[SDIO_TX_GPDB_SIZE*SDIO_TX_GPDH_NUM];       //Use max size buffer to avoid Host send overflow. ex: slave hook 1 byte buffer, but host send 4 bytes data.
} BL_SDIO_buf;

/*************************************************************************
 * Global variables definition
 *************************************************************************/
SD_R_SDIO_FuncTable_v1* SDIO_funcTable;
SDIO_USER_HANDLE BL_SDIO_handle;                                            //real BL need this
SD_R_Common_FuncTable_v1* Common_funcTable;

__ext_un_init_zi__ SDIO_GPDH_Node BL_SDIO_GPD_Header_buf[SDIO_TX_GPDH_NUM+SDIO_RX_GPDH_NUM];   //real BL need this

/*************************************************************************
 * Main code
 *************************************************************************/
kal_uint32 SDIO_BL_set_shared_drv(SD_R_SDIO_FuncTable_v1 *pSDIO_FuncTable, SD_R_Common_FuncTable_v1 *pCommon_FuncTable)
{
   SDIO_funcTable = pSDIO_FuncTable;
   Common_funcTable = pCommon_FuncTable;
   return 0;
}

kal_uint32 SDIO_BL_drv_init(void)
{
   U32 status;
   SDIO_USER_REQ_DESCRIPTOR SDIO_descriptor; 

   memset(BL_SDIO_GPD_Header_buf, 0x00, sizeof(BL_SDIO_GPD_Header_buf));

   SDIO_descriptor.pGPDH_List              = BL_SDIO_GPD_Header_buf;
   SDIO_descriptor.TX_GPDH_Number          = SDIO_TX_GPDH_NUM;
   SDIO_descriptor.RX_GPDH_Number          = SDIO_RX_GPDH_NUM;
   SDIO_descriptor.timer_callback          = Common_funcTable->m_r_gpt4_busy_wait_ms;
   SDIO_descriptor.TX_GPDB_Pool            = (kal_uint32*)&BL_SDIO_buf;
   SDIO_descriptor.TX_GPDB_Backup_Num      = SDIO_TX_GPDH_NUM;
   SDIO_descriptor.TQ_start_threshold      = 2;
   SDIO_descriptor.TQ_supplement_threshold = 2;

   status = SDIO_funcTable->m_sdio_open(&BL_SDIO_handle, &SDIO_descriptor);

   return status;
}

U32 SDIO_BL_GetData(U8* buf, U32 len, U32 timeout)
{
   U32 status = 0;    
   SDIO_BUFFER_DESCRIPTOR SDIO_buffer_desc;

   SDIO_buffer_desc.length = (U32)len;
   SDIO_buffer_desc.address = (U32)buf;  

   status = SDIO_funcTable->m_sdio_tx(&BL_SDIO_handle, &SDIO_buffer_desc, timeout); 

   return status;
}

U32 SDIO_BL_PutData(U8* buf, U32 len, U32 timeout)
{
   U32 status = 0;
   SDIO_BUFFER_DESCRIPTOR SDIO_buffer_desc;

   SDIO_buffer_desc.address = (U32)buf;  
   SDIO_buffer_desc.length = (U32)len;
   //NOTE: buffer don't need to be 4 bytes aligned. It can be 1-bytes aligned.
   status = SDIO_funcTable->m_sdio_rx(&BL_SDIO_handle, &SDIO_buffer_desc, timeout);

   return status;
}

U32 SDIO_BL_SendMailBox(U32 data, U32 timeout)
{   
   U32 status = 0;

   status = SDIO_funcTable->m_sdio_send_mailbox(&BL_SDIO_handle, data, timeout);

   return status;
}

U32 SDIO_BL_ReadMailBox(U32* data, U32 timeout)
{
   U32 status = 0;

   status = SDIO_funcTable->m_sdio_receive_mailbox(&BL_SDIO_handle, data, timeout);

   return status;
}

#endif /* __X_BOOTING__ */

