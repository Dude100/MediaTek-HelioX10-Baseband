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
 * sdio_fw_api_public.h
 *
 * Project:
 * --------
 *   SDIO Device Firmware
 *
 * Description:
 * ------------
 *
 *   This file list APIs provided to target environment in which ISR and
 *   multi-tasking are available.
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef _SDIO_FW_API_PUBLIC_H_
#define _SDIO_FW_API_PUBLIC_H_

#include "sdio_fw_api_data.h"


///////////////////////////////////////////////////////////////////
//
// Data structure Section
//
///////////////////////////////////////////////////////////////////

typedef struct _SDIO_TX_DATA_HEADER {
    unsigned tx_byte_count:12;
    unsigned reserved1:4;
    unsigned ether_type:8;                      //Unsed for 6280
    unsigned IP_Checksum_Calc_Required:1;       //Unsed for 6280
    unsigned UDP_TCP_Checksum_Calc_Required:1;  //Unsed for 6280
    unsigned reserved2:4;                       //Unsed for 6280
    unsigned queue_type:2;                      //for TX queue with 1-to-4 dispatch
} SDIO_TX_DATA_HEADER, *PSDIO_TX_DATA_HEADER;


///////////////////////////////////////////////////////////////////
//
// API Section
//
///////////////////////////////////////////////////////////////////

SDIO_STATUS sdio_init(
    void
    );

#if defined(SDIO_MAUI_ENV)
#include "drv_hisr.h"
void sdio_start_interrupt(
    DRV_HISR_ID ID,
    void (*sdio_HISR_funcp)(void)
    );
#endif


SDIO_STATUS sdio_open(
    kal_uint32 **Generic_Handle, //PSDIO_USER_HANDLE         *ppUser_Handle,
    PSDIO_USER_REQ_DESCRIPTOR pUser_Req
    );


SDIO_STATUS sdio_load_dummy_GPD(
    kal_uint32 *Generic_Handle,
    void *Generic_Descriptor,
    kal_uint32 isTX,
    kal_uint32 GPD_Length
    );


SDIO_STATUS sdio_rx(
    kal_uint32 *Generic_Handle,
    void *Generic_Descriptor
    );


SDIO_STATUS sdio_tx_load (
    kal_uint32 *Generic_Handle,
    void *Generic_Descriptor
    );


SDIO_STATUS sdio_query_information(
    kal_uint32 *pQuery_TX_Result_Buffers_Ptrs,
    kal_uint32 *pQuery_RX_Result_Buffers_Ptrs
    );


SDIO_STATUS sdio_recycle_single_buffer(
    kal_uint32 *Generic_Handle,
    kal_uint32 Return_Buffer_Address
    );


SDIO_STATUS sdio_recycle_multiple_buffer (
    kal_uint32 *Generic_Handle,
    kal_uint32 *pReturn_Information,
    kal_uint32 Information_Cnt_Total
    );


kal_uint32 sdio_query_queue_space(
    kal_uint32 *Generic_Handle,
    kal_uint32 priority,
    kal_uint32 isTX
    );


kal_bool sdio_query_txqueue_data_available(
    kal_uint32 *Generic_Handle
    );


SDIO_STATUS sdio_set_wdt_reset_reason(
    SDIO_WDT_RESET_REASON reason
    );


#endif
