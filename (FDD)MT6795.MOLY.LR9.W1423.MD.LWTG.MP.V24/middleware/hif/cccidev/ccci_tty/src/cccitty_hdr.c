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
 *   cccitty_hdr.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements CCCI TTY handler functions for TTYCore
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
 * 	Add cccitty sequence support(Merging from MP5 CL:641385 to MP6)
 *
 * removed!
 * removed!
 * 	add cccitty sequence support and status update support
 *
 * 11 18 2013 ap.wang
 * removed!
 * 	Remove MD Log data path log
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add new cmd support (TTY_CMD_GET_MTU_SIZE)
 *
 * removed!
 * removed!
 * remove ccci DHL Tx data path log: CCCI_TTY, CCCI
 *
 * removed!
 * removed!
 * [MOLY][CCCI_SDIO] 1st version of MT6290 CCCI feature
 ****************************************************************************/
#include "cccitty_hdr.h"
#include "cccitty_common.h"
#include "cccitty_sm.h"
#include "cccitty_data.h"
/*!
 * @function        cccitty_ttyc_hdr_cmd_init
 * @brief           SIO_CMD_INIT command handler
 *                  reference: cdcacm_ttyhdr_cmd_init
 * @param port      [IN] UART port number
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_init(UART_PORT port)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    
    UART_CONFIG_T uart_defaultConfig =
    {
        UART_BAUD_115200,    /* baud */
        len_8,               /* dataBits */
        sb_1,                /* stopBits */
        pa_none,             /* parity */
        fc_none,             /* no flow control */
        0x11,                /* xonChar */
        0x13,                /* xoffChar */
        KAL_FALSE
    };

    kal_mem_cpy(&p_cccidev->dcb, &uart_defaultConfig, sizeof(UART_CONFIG_T));

    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_init
 * @brief           SIO_CMD_OPEN command handler
 *                  reference: cdcacm_ttyhdr_cmd_open
 * @param port      [IN] UART port number
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_open(UART_PORT port, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));

    /* This port is occupied */
    if (MOD_NIL != p_cccidev->ownerid) {
        cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_OPEN_OWNER_IS_NOT_NULL, ownerid,p_cccidev->ownerid);
        return STATUS_INVALID_DCL_HANDLE;
    }

    p_cccidev->ownerid = ownerid;
    p_cccidev->tty_need_tx_done_cb = DCL_FALSE;
    cccitty_on_dev_event(p_cccidev, CCCI_TTY_EVT_SIO_OPEN);

    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_close
 * @brief           SIO_CMD_CLOSE command handler
 *                  reference: cdcacm_ttyhdr_cmd_close
 * @param port      [IN] UART port number
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 */
DCL_STATUS  cccitty_ttyc_hdr_cmd_close(UART_PORT port, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));

    EXT_ASSERT(ownerid == p_cccidev->ownerid, ownerid, p_cccidev->ownerid, port);
    //4 <NOTE> CCCI doesn't provide flush service

    p_cccidev->ownerid = MOD_NIL;

    /*
     * 20120730 synced with TTYCore owner HaoRen
     * Because CCCI over SDIO doesn't have "Flush funciont", the Tx flush is achieved by Tx done callback.
     * The user behavior is expected like 
     *   Case 1. Tx Flush --> Wait for Tx done come back --> Close Port.
     *   Case 2. Tx Flush --> Close Port. 
     * To support case 2, CCCI TTY has to callback the Tx done GPDs even if the Port is closed.
     * TTY Core will help to free the TGPDs if the port is closed.
     */
//    p_cccidev->tty_need_tx_done_cb = DCL_FALSE;
    cccitty_on_dev_event(p_cccidev, CCCI_TTY_EVT_SIO_CLOSE);

    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_need_tx_done_cb
 * @brief           TTY_CMD_NEED_TX_DONE_CB command handler
 *                  reference: cdcacm_ttyhdr_cmd_need_tx_done_cb
 * @param port      [IN] UART port number
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 * @param need_tx_done [IN] ttycore / user need Tx done notify
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_need_tx_done_cb(UART_PORT port, module_type ownerid, DCL_BOOL need_tx_done)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    
    EXT_ASSERT(ownerid == p_cccidev->ownerid, port, ownerid, p_cccidev->ownerid);
    p_cccidev->tty_need_tx_done_cb = need_tx_done;

    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_get_chunk_size
 * @brief           TTY_CMD_GET_CHUNK_SIZE command handler
 *                  reference: cdcacm_ttyhdr_cmd_get_chunk_size
 * @param port      [IN] UART port number
 * @param p_chunkSize [OUT] return the chunksize to TTYCore
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_get_chunk_size(UART_PORT port, DCL_UINT32 *p_chunkSize)
{
    /* 
    * USB request User to reload RGPD with m*chunkSize, 
    * while SDIO doesn't have this limitation
    */
    *p_chunkSize = 1;
    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_get_mtu_size
 * @brief           TTY_CMD_GET_MTU_SIZE command handler
 * @param port      [IN] UART port number
 * @param p_dlMTUSize [OUT] return the downlink MTU size
 * @param p_dlMTUSize [OUT] return the uplink MTU size
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_get_mtu_size(UART_PORT port, DCL_UINT32 *p_dlMTUSize, DCL_UINT32 *p_ulMTUSize)
{
    
#if defined(__HIF_CLDMA_SUPPORT__)
    /*Request by TH.Cheng, CLDMA MTU setting*/
    *p_dlMTUSize = 2048 - 22;
    *p_ulMTUSize = 2048 - 22;
#else
    /*SDIO case MTU setting*/
    *p_dlMTUSize = CCCI_TTY_DL_BUF_SZ - 128;
    *p_ulMTUSize = CCCI_TTY_UL_BUF_SZ - 128;
#endif
    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_get_owner_id
 * @brief           SIO_CMD_GET_OWNER_ID command handler
 *                  reference: cdcacm_ttyhdr_cmd_get_owner_id
 * @param port      [IN] UART port number
 *
 * @return          module_type
 */
module_type cccitty_ttyc_hdr_cmd_get_owner_id(UART_PORT port)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    return p_cccidev->ownerid;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_set_owner
 * @brief           SIO_CMD_SET_OWNER command handler
 *                  reference: cdcacm_ttyhdr_cmd_set_owner
 * @param port      [IN] UART port number
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_set_owner(UART_PORT port, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));
    p_cccidev->ownerid = ownerid;

    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_set_flow_ctrl
 * @brief           SIO_CMD_SET_FLOW_CTRL command handler
 *                  reference: cdcacm_ttyhdr_cmd_set_flow_ctrl
 * @param port      [IN] UART port number
 * @param xOn       [IN] UART xOn
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_set_flow_ctrl(UART_PORT port, kal_bool xOn, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));

    EXT_ASSERT(ownerid == p_cccidev->ownerid, port, ownerid, p_cccidev->ownerid);
    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_set_dcb_config
 * @brief           SIO_CMD_SET_DCB_CONFIG command handler
 *                  reference: cdcacm_ttyhdr_cmd_set_dcb_config
 * @param port      [IN] UART port number
 * @param uart_config [IN] UART config
 * @param ownerid   [IN] module_type for the one opening this port, ex. MOD_xxx
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_set_dcb_config(UART_PORT port, UART_CONFIG_T *uart_config, module_type ownerid)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));

    EXT_ASSERT(ownerid == p_cccidev->ownerid, port, ownerid, p_cccidev->ownerid);
    kal_mem_cpy(&(p_cccidev->dcb), uart_config, sizeof(UART_CONFIG_T));
    return STATUS_OK;
}

/*!
 * @function        cccitty_ttyc_hdr_cmd_read_dcb_config
 * @brief           SIO_CMD_READ_DCB_CONFIG command handler
 *                  reference: cdcacm_ttyhdr_cmd_read_dcb_config
 * @param port      [IN] UART port number
 * @param dcb       [OUT] UART_CONFIG_T
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_cmd_read_dcb_config(UART_PORT port, UART_CONFIG_T *dcb)
{
    cccitty_dev_t       *p_cccidev = cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(port));

    kal_mem_cpy(dcb, &(p_cccidev->dcb), sizeof(UART_CONFIG_T));
    return STATUS_OK;
}


/*!
 * @function        cccitty_ttyc_hdr
 * @brief           TTY core command handler
 *                  reference: cdcacm_ttyhdr_main
 * @param dev       [IN] UART port number
 * @param cmd       [IN] UART / TTY command, UART_CMDS defined in dcl_uart.h
 * @param data      [IN] pointer to ext data structure, refer to each case
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_STATUS ret_status = STATUS_OK;
	if(cmd != TTY_CMD_PUT_BYTES_IOR &&
	   cmd != TTY_CMD_PUT_BYTES_IOR_LIGHT
	){
	    if (cccitty_get_dev_instance(CCCITTY_UARTP_TO_DEVID(dev))->ccci_ch.cccitty_ch_dl != CCCI_MD_LOG_RX){
		    cccitty_trace(CCCI_TTY_TRACE, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_RCV_CMD, cmd);
	    }
	}
    
    switch (cmd)
    {
        case SIO_CMD_INIT:
        {
            cccitty_ttyc_hdr_cmd_init(dev); 
            ret_status = STATUS_OK;
        }
            break;

        case SIO_CMD_OPEN:
        {
            UART_CTRL_OPEN_T *prCtrlOpen;
            prCtrlOpen = &(data->rUARTCtrlOPEN);
            ret_status = cccitty_ttyc_hdr_cmd_open(dev, (module_type)prCtrlOpen->u4OwenrId);
        }
            break;        

        case SIO_CMD_CLOSE:
        {
            UART_CTRL_CLOSE_T *prCtrlClose;
            prCtrlClose = &(data->rUARTCtrlCLOSE);
            //4 <flush>
            ret_status = cccitty_ttyc_hdr_cmd_clr_rx_buf(dev, (module_type)prCtrlClose->u4OwenrId, KAL_TRUE);
            //4 <close>
            ret_status = cccitty_ttyc_hdr_cmd_close(dev, (module_type)prCtrlClose->u4OwenrId);
        }
            break;

        case TTY_CMD_NEED_TX_DONE_CB:
        {
            UART_CTRL_NEED_TX_DONE_CB_T *prCtrlNeedTxDoneCb;
            prCtrlNeedTxDoneCb = &(data->rUARTCtrlNeedTxDoneCb);
            ret_status = cccitty_ttyc_hdr_cmd_need_tx_done_cb(dev, (module_type)prCtrlNeedTxDoneCb->u4OwnerId, prCtrlNeedTxDoneCb->needTxDoneCb);
        }
            break;

        case TTY_CMD_ASSIGN_RX_IOR:
        {
            UART_CTRL_ASSIGN_RX_IOR_T *prCtrlAssignRxIor;
            prCtrlAssignRxIor = &(data->rUARTCtrlAssignRxIor);
            //4 <RX reload flow>
            //4 <NOT support New Rx user>            
            ret_status = cccitty_ttyc_hdr_cmd_assign_rx_ior(dev, prCtrlAssignRxIor->ior, (module_type)prCtrlAssignRxIor->u4OwnerId);
        }
            break;
        
        case TTY_CMD_PUT_BYTES_IOR:
        {
            UART_CTRL_PUT_BYTES_IOR_T *prCtrlPutBytesIor;
            prCtrlPutBytesIor = &(data->rUARTCtrlPUTBYTESIOR);
            //4 <TX flow>
            ret_status = cccitty_ttyc_hdr_cmd_put_bytes_ior(dev, prCtrlPutBytesIor->putIor, (module_type)prCtrlPutBytesIor->u4OwnerId, NULL);
        }
            break;

        case TTY_CMD_PUT_BYTES_IOR_LIGHT:
        {
            UART_CTRL_PUT_BYTES_IOR_T *prCtrlPutBytesIor;
            ccci_io_ext_info_t io_type;
            prCtrlPutBytesIor = &(data->rUARTCtrlPUTBYTESIOR);
            io_type.type      = CCCI_IO_TX_NO_FLUSH;
 
            //4 <TX flow>
            ret_status = cccitty_ttyc_hdr_cmd_put_bytes_ior(dev, prCtrlPutBytesIor->putIor, (module_type)prCtrlPutBytesIor->u4OwnerId, &io_type);

        }
            break;

        case TTY_CMD_GET_CHUNK_SIZE:
        {
            UART_CTRL_GET_CHUNK_SIZE_T *prCtrlChunkSize;
            prCtrlChunkSize = &(data->rUARTCtrlGETCHUNKSIZE);
            ret_status = cccitty_ttyc_hdr_cmd_get_chunk_size(dev, &(prCtrlChunkSize->chunkSize));
        }
            break;

        case SIO_CMD_GET_OWNER_ID:
        {
            UART_CTRL_OWNER_T *prCtrlOwner;
            prCtrlOwner = &(data->rUARTCtrlOWNER);
            prCtrlOwner->u4OwenrId = cccitty_ttyc_hdr_cmd_get_owner_id(dev);
            ret_status = STATUS_OK;
        }
            break;

        case SIO_CMD_SET_OWNER:
        {
            UART_CTRL_OWNER_T *prCtrlOwner;
            prCtrlOwner = &(data->rUARTCtrlOWNER);
            //4 <RX flush flow>
            /* Do not check the flush owner, since the SIO_CMD_SET_OWNER is issued by new owner*/
            ret_status = cccitty_ttyc_hdr_cmd_clr_rx_buf(dev, (module_type)prCtrlOwner->u4OwenrId, KAL_FALSE);
            ret_status = cccitty_ttyc_hdr_cmd_set_owner(dev, (module_type)prCtrlOwner->u4OwenrId);
        }
            break;

        case SIO_CMD_CLR_RX_BUF:
        {
            UART_CTRL_CLR_BUFFER_T *prCtrlClrBuffer;
            prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
            //4 <RX flush flow>
            ret_status = cccitty_ttyc_hdr_cmd_clr_rx_buf(dev, (module_type)prCtrlClrBuffer->u4OwenrId, KAL_TRUE);
        }
            break;
        
        case SIO_CMD_CLR_TX_BUF:
        {
            //UART_CTRL_CLR_BUFFER_T *prCtrlClrBuffer;
            //prCtrlClrBuffer = &(data->rUARTCtrlCLRBUFFER);
            //4 <Note> Do nothing, wait for HIF driver Tx done callback
        }
            break;

        case SIO_CMD_SET_FLOW_CTRL:
        {
            UART_CTRL_FLOW_CTRL_T *prCtrlFlowCtrl;
            prCtrlFlowCtrl = &(data->rUARTCtrlFLOWCTRL);
            ret_status = cccitty_ttyc_hdr_cmd_set_flow_ctrl(dev, (kal_bool)prCtrlFlowCtrl->bXON, (module_type)prCtrlFlowCtrl->u4OwenrId);
        }
            break;

        case SIO_CMD_SET_DCB_CONFIG:
        {
            UART_CONFIG_T *prDCB;
            UART_CTRL_DCB_T *prCtrlDCB;
            prCtrlDCB = &(data->rUARTCtrlDCB);
            prDCB = (UART_CONFIG_T*)(&(prCtrlDCB->rUARTConfig));
            ret_status = cccitty_ttyc_hdr_cmd_set_dcb_config(dev, prDCB, (module_type)prCtrlDCB->u4OwenrId);
        }
            break;

        case SIO_CMD_CTRL_DCD:
        {
            /* Do nothing. */
            //UART_CTRL_DCD_T *prCtrlDCD;
            //prCtrlDCD = &(data->rUARTCtrlDCD);
			//ret_status = STATUS_FAIL;
            
            cccitty_trace(CCCI_TTY_WARN, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_NONSUPPORT_CMD, cmd);
        }
            break;

        case SIO_CMD_READ_DCB_CONFIG:
        {
            UART_CONFIG_T *prDCB;
            UART_CTRL_DCB_T *prCtrlDCB;
            prCtrlDCB = &(data->rUARTCtrlDCB);
            prDCB = (UART_CONFIG_T*)(&(prCtrlDCB->rUARTConfig));
            ret_status = cccitty_ttyc_hdr_cmd_read_dcb_config(dev, (UART_CONFIG_T*)prDCB);
        }
            break;

        case SIO_CMD_READ_HW_STATUS:
        {
            /* refer to cdcacm_ttyhdr_cmd_read_hw_status */
            IO_LEVEL_T* pSDSR;
            IO_LEVEL_T* pSCTS;
            UART_CTRL_RHS_T* prCtrlRHS;
            prCtrlRHS = &(data->rUARTCtrlRHS);
            pSDSR = (IO_LEVEL_T*)(&(prCtrlRHS->rIOLevelDSR));
            pSCTS = (IO_LEVEL_T*)(&(prCtrlRHS->rIOLevelCTS));
            kal_mem_set(pSDSR, 0, sizeof(IO_LEVEL_T));
            kal_mem_set(pSCTS, 0, sizeof(IO_LEVEL_T));
        }
            break;
            
#if defined (__CCCITTY_EXCEPT_TODO__)
        /*
         * Exception command - Begin.
         */
        case TTY_CMD_EXCEPTION_HIF_INIT:
        {
            cdcacm_ttyhdr_cmd_expt_hif_init(dev);
        }
            break;

        case TTY_CMD_EXCEPTION_CLEAR_CHANNEL:
        {
            cdcacm_ttyhdr_cmd_expt_clear_ch(dev);
        }
            break;

        case TTY_CMD_EXCEPTION_RESET:
        {
            cdcacm_ttyhdr_cmd_expt_reset(dev);
        }
            break;

        case TTY_CMD_EXCEPTION_TX_GPD:
        {
            TTY_CTRL_EXCP_TX_GPD_T* prCtrlExptTxGpd;
            prCtrlExptTxGpd = &(data->rTTYCtrlExcpTxGPD);
            cdcacm_ttyhdr_cmd_expt_tx_gpd(dev, prCtrlExptTxGpd->first_gpd, prCtrlExptTxGpd->last_gpd);
        }
            break;

        case TTY_CMD_EXCEPTION_TX_DONE_INFO:
        {
            TTY_CTRL_EXCP_TX_DONE_INFO_T* prCtrlExptTxDoneInfo; 
            prCtrlExptTxDoneInfo = &(data->rTTYCtrlExcpTxDoneInfo);
            cdcacm_ttyhdr_cmd_expt_tx_done_info(dev, &(prCtrlExptTxDoneInfo->first_gpd), &(prCtrlExptTxDoneInfo->last_gpd), (kal_uint32*)&(prCtrlExptTxDoneInfo->num));
        }
            break;

        case TTY_CMD_EXCEPTION_ASSIGN_RX_GPD:
        {
            TTY_CTRL_EXCP_ASSIGN_RX_GPD_T* prCtrlExptAssignRxGpd;
            prCtrlExptAssignRxGpd = &(data->rTTYCtrlExcpAssignRxGPD);
            cdcacm_ttyhdr_cmd_expt_assign_rx_gpd(dev, prCtrlExptAssignRxGpd->first_gpd, prCtrlExptAssignRxGpd->last_gpd);
        }
            break;

        case TTY_CMD_EXCEPTION_GET_RX_GPD:
        {
            TTY_CTRL_EXCP_GET_RX_GPD_T* prCtrlExptGetRxGpd;
            prCtrlExptGetRxGpd = &(data->rTTYCtrlExcpGetRxGPD);
            cdcacm_ttyhdr_cmd_expt_get_rx_gpd(dev, &(prCtrlExptGetRxGpd->first_gpd), &(prCtrlExptGetRxGpd->last_gpd), (kal_uint32*)&(prCtrlExptGetRxGpd->num));
        }
            break;

        case TTY_CMD_EXCEPTION_HIF_STATE:
        {   
            TTY_CTRL_EXCP_HIF_STATE_T* prCtrlExptHifState;
            prCtrlExptHifState = &(data->rTTYCtrlExcpHifState);
            cdcacm_ttyhdr_cmd_expt_hif_state(dev, &(prCtrlExptHifState->hif_state));
        }
            break;

        case TTY_CMD_EXCEPTION_HIF_POLL:
        {
            cdcacm_ttyhdr_cmd_expt_hif_poll(dev);
        }
            break;
        /*
         * Exception command - End.
         */
#else
        case TTY_CMD_EXCEPTION_HIF_INIT:
        case TTY_CMD_EXCEPTION_CLEAR_CHANNEL:
        case TTY_CMD_EXCEPTION_RESET:
        case TTY_CMD_EXCEPTION_TX_GPD: 
        case TTY_CMD_EXCEPTION_TX_DONE_INFO:
        case TTY_CMD_EXCEPTION_ASSIGN_RX_GPD:
        case TTY_CMD_EXCEPTION_GET_RX_GPD:
        case TTY_CMD_EXCEPTION_HIF_STATE:
        case TTY_CMD_EXCEPTION_HIF_POLL: 
        {
            // TODO: Exception Mode
            cccitty_trace(CCCI_TTY_WARN, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_NONSUPPORT_CMD, cmd);
        }
            break;
#endif // __CCCITTY_EXCEPT_TODO__

        case SIO_CMD_PURGE:
        case SIO_CMD_CTRL_BREAK:
        case SIO_CMD_SET_BAUDRATE:
        case SIO_CMD_SET_AUTOBAUD_DIV:
        case SIO_CMD_CTRL_RI:
        case SIO_CMD_CTRL_DTR:
        case SIO_CMD_GET_ESCAPE_INFO:
        case SIO_CMD_CONFIG_ESCAPE:
        case UART_CMD_GET_FLOW_CONTROL:
        case UART_CMD_SLEEP_TX_ENABLE:
        {
            /* Do nothing. */
            cccitty_trace(CCCI_TTY_WARN, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_NONSUPPORT_CMD, cmd);
        }
            break;
        case SIO_CMD_GET_UART_BYTE:
        case SIO_CMD_PUT_UART_BYTE:
        case SIO_CMD_PUT_UART_BYTES:
        case SIO_CMD_PUT_BYTES: 
        case SIO_CMD_PUT_ISR_BYTES:
        {
            cccitty_trace(CCCI_TTY_WARN, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_NONSUPPORT_CMD, cmd);
            ret_status = STATUS_INVALID_CMD;
        }
            break;
        case TTY_CMD_GET_MTU_SIZE:
        {
            UART_CTRL_GET_MTU_SIZE_T *prCtrlMTUSize;
            prCtrlMTUSize = &(data->rUARTCtrlGETMTUSIZE);
            ret_status = cccitty_ttyc_hdr_cmd_get_mtu_size(dev, &(prCtrlMTUSize->dlmtu_sz), &(prCtrlMTUSize->ulmtu_sz));
            
        }
            break;            
        default:
        {
            cccitty_trace(CCCI_TTY_ERR, CCCI_TTY_MOD_HDR, CCCI_TTY_TR_HDR_UNKNOWN_CMD, cmd);
            ret_status = STATUS_INVALID_CMD;
        }
            break;
    }
    
    return ret_status;
}    
