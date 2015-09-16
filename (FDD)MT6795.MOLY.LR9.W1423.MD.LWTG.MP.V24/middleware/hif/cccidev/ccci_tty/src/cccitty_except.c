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
 *   cccitty_except.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Implements the CCCI TTY exception mode
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
 * removed!
 * removed!
 * [CCCI] Change exception flow.
 *
 * removed!
 * removed!
 * 	.
 *
 * removed!
 * removed!
 * Sync from MP branch
 *
 * removed!
 * removed!
 * 	[CCCITTY] add new exception command handling
 *
 * removed!
 * removed!
 * 	1. revise ccci exception handshake I/O
 * 	2. add global variable state for debugging
 *
 ****************************************************************************/
#include "cccitty_hdr.h"
#include "cccitty_common.h"
#include "cccitty_sm.h"
#include "cccitty_data.h"
#include "cccitty_qbm.h"

#if defined(ATEST_SYS_CCCI_TTY)
#define ccci_set_gpd_ex  cccitty_ut_except_set_gpd
#define ccci_clear_ch_ex cccitty_ut_except_clear_ch
#define ccci_poll_gpd_ex cccitty_ut_except_poll_gpd
#define ccci_hif_st_ex   cccitty_ut_except_hif_st
#define ccci_hif_isr_ex  cccitty_ut_except_hif_isr
#else
#define ccci_set_gpd_ex  ccci_except_set_gpd
#define ccci_clear_ch_ex ccci_except_clear_ch
#define ccci_poll_gpd_ex ccci_except_poll_gpd
#define ccci_hif_st_ex   ccci_except_hif_st
#define ccci_hif_isr_ex  ccci_except_hif_isr
#endif

#define CCCI_EXPT_DHL_DL CCCI_MD_LOG_RX
#define CCCI_EXPT_DHL_UL CCCI_MD_LOG_TX
#define CCCI_EXPT_DHL_CTRL_DL CCCI_TST_CHANNEL
#define CCCI_EXPT_DHL_CTRL_UL CCCI_TR_CHANNEL

static kal_bool valid_gpd = KAL_FALSE;
extern volatile CCCI_EXPT_STATE_E ccci_exception_state;

/*====================Exception Mode APIs===========================*/
/*!
 * @function        [Exception]cccitty_ttyc_hdr_expt_init
 * @brief           TTY_CMD_EXCEPTION_HIF_INIT command handler
 *
 * @param port      [IN] UART port number
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_expt_init(UART_PORT port)
{
    return STATUS_OK;
}

/*!
 * @function        [Exception]cccitty_ttyc_hdr_expt_clear_ch
 * @brief           TTY_CMD_EXCEPTION_CLEAR_CHANNEL command handler
 *
 * @param port      [IN] UART port number
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_hdr_expt_clear_ch(UART_PORT port)
{
    // Move to hmu_except_hmu()
    //ccci_clear_ch_ex(CCCI_EXPT_DHL_DL); /* clear DL channel */
    //ccci_clear_ch_ex(CCCI_EXPT_DHL_UL); /* clear UL channel */

    ccci_exception_state = CCCI_EXPT_CLEAR_CH_ST;
    return STATUS_OK;
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_tx_gpd
 * @brief           TTY_CMD_EXCEPTION_TX_GPD command handler, for exception mode DL data
 *
 * @param port       [IN] UART port number
 * @param p_first_gpd[IN] first_gpd_pointer
 * @param p_last_gpd [IN] last_gpd_pointer
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_tx_gpd(UART_PORT port, void *p_first_gpd, void *p_last_gpd)
{
    CCCI_RETURNVAL_T    ccci_ret;
    CCCI_BUFF_T         *p_ccci_head;
    qbm_gpd             *current_gpd, *tail_gpd;
    kal_uint32          except_dl_ch;

    //4 1. Insert CCCI Header
    current_gpd  = (qbm_gpd*) p_first_gpd; 
    tail_gpd     = (qbm_gpd*) p_last_gpd; 
    if(uart_port_dhl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_DL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_CTRL_DL;
    }else{
        return STATUS_FAIL;
    }
    
    do {
        //4 <1> append CCCI header CCCI_BUFF_T
#ifdef __CCCI_N_USE_TGPD_EXT__ 
        /*move data buffer pointer forward for ccci header, increase the gpd, bd length*/
        CCCITTY_PUSH_QBM_DATAHEAD(current_gpd, sizeof(CCCI_BUFF_T));
        p_ccci_head   = (CCCI_BUFF_T *)CCCITTY_GET_QBM_DATAPTR(current_gpd);
        CCCI_STREAM_SET_LEN(p_ccci_head, CCCITTY_GET_QBM_DATALEN(current_gpd));
#else
        /* Store the DL CCCI header in the GPD extention part */
        QBM_DES_SET_EXTLEN(current_gpd, sizeof(CCCI_BUFF_T));
        p_ccci_head = (CCCI_BUFF_T *)QBM_DES_GET_EXT(current_gpd);
        CCCI_STREAM_SET_LEN(p_ccci_head, CCCITTY_GET_QBM_DATALEN(current_gpd)+sizeof(CCCI_BUFF_T));
#endif
        /*Construct the CCCI header*/
        CCCI_SET_CH_NO(p_ccci_head, except_dl_ch);

        /*Add sequence number*/
        ccci_debug_add_seq(p_ccci_head, CCCI_DEBUG_ASSERT_BIT);
        
        QBM_CACHE_FLUSH(p_ccci_head, sizeof(CCCI_BUFF_T));

        if ( current_gpd == tail_gpd )
        {
            break;
        }
        current_gpd = QBM_DES_GET_NEXT(current_gpd);
    } while ( current_gpd != NULL );

    //4 2. submit to ccci exception DL function
    ccci_ret = ccci_set_gpd_ex(except_dl_ch, p_first_gpd, p_last_gpd);
    
    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_tx_done_info
 * @brief           TTY_CMD_EXCEPTION_TX_DONE_INFO command handler, for retriving exception mode DL done TGPDs
 *
 * @param port         [IN] UART port number
 * @param pp_first_gpd [OUT] pointer of first_gpd_pointer
 * @param pp_last_gpd  [OUT] pointer of last_gpd_pointer
 * @param gpd_num      [OUT] pointer of number of gpd returned by hif
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_tx_done_info(UART_PORT port, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num)
{
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          except_dl_ch;

    if(uart_port_dhl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_DL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_CTRL_DL;
    }else{
        return STATUS_FAIL;
    }
    
    ccci_ret = ccci_poll_gpd_ex(
                                except_dl_ch,       /* DL channel */
                                pp_first_gpd,       /* pp_first_gpd */
                                pp_last_gpd,        /* pp_last_gpd */
                                gpd_num);           /* gpd_num */

    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_assign_rx_gpd
 * @brief           TTY_CMD_EXCEPTION_ASSIGN_RX_GPD command handler, for exception mode UL HIF buffer
 *
 * @param port       [IN] UART port number
 * @param p_first_gpd[IN] first_gpd_pointer
 * @param p_last_gpd [IN] last_gpd_pointer
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_assign_rx_gpd(UART_PORT port, void *p_first_gpd, void *p_last_gpd)
{
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          except_ul_ch;

    if(uart_port_dhl_sp_expt == port){
        except_ul_ch = CCCI_EXPT_DHL_UL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_ul_ch = CCCI_EXPT_DHL_CTRL_UL;
    }else{
        return STATUS_FAIL;
    }

    ccci_ret = ccci_set_gpd_ex(except_ul_ch, p_first_gpd, p_last_gpd);

    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_get_rx_gpd
 * @brief           TTY_CMD_EXCEPTION_GET_RX_GPD command handler, for retriving exception mode UL RGPDs
 *
 * @param port         [IN] UART port number
 * @param pp_first_gpd [OUT] pointer of first_gpd_pointer
 * @param pp_last_gpd  [OUT] pointer of last_gpd_pointer
 * @param gpd_num      [OUT] pointer of number of gpd returned by hif
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_get_rx_gpd(UART_PORT port, void **pp_first_gpd, void **pp_last_gpd, kal_uint32 *gpd_num)
{
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          except_ul_ch;
    qbm_gpd             *current_gpd, *tail_gpd, *next_gpd;
    //kal_bool            valid_gpd = KAL_FALSE;
    kal_uint8           *data_ptr;
    kal_uint32          size;

    if(uart_port_dhl_sp_expt == port){
        except_ul_ch = CCCI_EXPT_DHL_UL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_ul_ch = CCCI_EXPT_DHL_CTRL_UL;
    }else{
        return STATUS_FAIL;
    }

    ccci_ret = ccci_poll_gpd_ex(
                                except_ul_ch,     /* DHL exception DL channel */
                                pp_first_gpd,     /* pp_first_gpd */
                                pp_last_gpd,      /* pp_last_gpd */
                                gpd_num);         /* gpd_num */

    if(*gpd_num != 0)
    {
        current_gpd  = (qbm_gpd*) *pp_first_gpd; 
        tail_gpd     = (qbm_gpd*) *pp_last_gpd; 

        do {
            next_gpd = QBM_DES_GET_NEXT(current_gpd);

            //invalid data, including CCCI header
            data_ptr = CCCIDEV_GET_QBM_DATAPTR(current_gpd);
            size = CCCIDEV_GET_QBM_DATALEN(current_gpd);
            QBM_CACHE_INVALID(data_ptr, size);

            /*Check sequence number*/
            ccci_debug_check_seq((CCCI_BUFF_T*)data_ptr);
            
            //4 <1> remove CCCI header CCCI_BUFF_T
            valid_gpd = CCCITTY_RM_CCCI_HEADERS(except_ul_ch, current_gpd);
            if(!valid_gpd) while(1);
            // TODO: how to handler invalid GPD? free or just return?

            if ( current_gpd == tail_gpd )
            {
                break;
            }
            current_gpd = next_gpd;
        } while ( current_gpd != NULL );
    }

    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_hif_state
 * @brief           TTY_CMD_EXCEPTION_HIF_STATE command handler, for querying HIF state to see if DL is allowed
 *
 * @param port         [IN] UART port number
 * @param p_link_state [OUT] pointer of the HIF link state
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_hif_state(UART_PORT port, tty_excp_hif_state *p_link_state)
{
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          except_dl_ch;

    if(uart_port_dhl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_DL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_CTRL_DL;
    }else{
        return STATUS_FAIL;
    }

    ccci_ret = ccci_hif_st_ex(except_dl_ch);

    if (CCCI_SUCCESS == ccci_ret) {
        *p_link_state = HIF_STATE_NORMAL;
    } else {
        *p_link_state = HIF_STATE_TXERROR;
    }
    
    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        [Exception]cccitty_ttyc_cmd_expt_hif_poll
 * @brief           TTY_CMD_EXCEPTION_HIF_POLL command handler, 
 *                  for periodically trigger HIF driver to handle the interrupt
 *
 * @param port      [IN] UART port number
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_cmd_expt_hif_poll(UART_PORT port, DCL_BOOL *reset_event)
{
    CCCI_RETURNVAL_T    ccci_ret;
    kal_uint32          except_dl_ch;

	/*Backward compatible with USB bus reset event, CCCI just return false*/
	*reset_event = KAL_FALSE;
	
    if(uart_port_dhl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_DL;
    }else if(uart_port_dhl_ctrl_sp_expt == port){
        except_dl_ch = CCCI_EXPT_DHL_CTRL_DL;
    }else{
        return STATUS_FAIL;
    }
    
    ccci_ret = ccci_hif_isr_ex(except_dl_ch);

    return ((CCCI_SUCCESS == ccci_ret) ?STATUS_OK :STATUS_FAIL);
}

/*!
 * @function        cccitty_ttyc_expt_hdr
 * @brief           TTY core exception command handler
 *                 
 * @param dev       [IN] UART port number
 * @param cmd       [IN] UART / TTY command, UART_CMDS defined in dcl_uart.h
 * @param data      [IN] pointer to ext data structure, refer to each case
 *
 * @return          DCL_STATUS
 */
DCL_STATUS cccitty_ttyc_expt_hdr(DCL_DEV dev, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_STATUS ret_status = STATUS_OK;

    switch (cmd)
    {
        /*
         * Exception command - Begin.
         */
        case TTY_CMD_EXCEPTION_HIF_INIT:
        {
            cccitty_ttyc_hdr_expt_init(dev);
        }
            break;

        case TTY_CMD_EXCEPTION_CLEAR_CHANNEL:
        {
            cccitty_ttyc_hdr_expt_clear_ch(dev);
        }
            break;

        case TTY_CMD_EXCEPTION_RESET:
        {
            /* backward compatible to USB, nothing to do in CCCI */
        }
            break;

        case TTY_CMD_EXCEPTION_TX_GPD:
        {
            TTY_CTRL_EXCP_TX_GPD_T* prCtrlExptTxGpd;
            prCtrlExptTxGpd = &(data->rTTYCtrlExcpTxGPD);
            cccitty_ttyc_cmd_expt_tx_gpd(dev, prCtrlExptTxGpd->first_gpd, prCtrlExptTxGpd->last_gpd);
        }
            break;
            
        case TTY_CMD_EXCEPTION_TX_DONE_INFO:
        {
            TTY_CTRL_EXCP_TX_DONE_INFO_T* prCtrlExptTxDoneInfo; 
            prCtrlExptTxDoneInfo = &(data->rTTYCtrlExcpTxDoneInfo);
            cccitty_ttyc_cmd_expt_tx_done_info(dev, &(prCtrlExptTxDoneInfo->first_gpd), &(prCtrlExptTxDoneInfo->last_gpd), (kal_uint32*)&(prCtrlExptTxDoneInfo->num));
        }
            break;

        case TTY_CMD_EXCEPTION_ASSIGN_RX_GPD:
        {
            TTY_CTRL_EXCP_ASSIGN_RX_GPD_T* prCtrlExptAssignRxGpd;
            prCtrlExptAssignRxGpd = &(data->rTTYCtrlExcpAssignRxGPD);
            cccitty_ttyc_cmd_expt_assign_rx_gpd(dev, prCtrlExptAssignRxGpd->first_gpd, prCtrlExptAssignRxGpd->last_gpd);
        }
            break;

        case TTY_CMD_EXCEPTION_GET_RX_GPD:
        {
            TTY_CTRL_EXCP_GET_RX_GPD_T* prCtrlExptGetRxGpd;
            prCtrlExptGetRxGpd = &(data->rTTYCtrlExcpGetRxGPD);
            cccitty_ttyc_cmd_expt_get_rx_gpd(dev, &(prCtrlExptGetRxGpd->first_gpd), &(prCtrlExptGetRxGpd->last_gpd), (kal_uint32*)&(prCtrlExptGetRxGpd->num));
        }
            break;

        case TTY_CMD_EXCEPTION_HIF_STATE:
        {   
            TTY_CTRL_EXCP_HIF_STATE_T* prCtrlExptHifState;
            prCtrlExptHifState = &(data->rTTYCtrlExcpHifState);
            cccitty_ttyc_cmd_expt_hif_state(dev, &(prCtrlExptHifState->hif_state));
        }
            break;
 
        case TTY_CMD_EXCEPTION_HIF_POLL:
        {
			/*Backward compatible with USB, return bus reset_event*/
			TTY_CTRL_EXCP_HIF_POLL_T* prCtrlExptHifPoll;
			prCtrlExptHifPoll = &(data->rTTYCtrlExcpHifPoll);
            cccitty_ttyc_cmd_expt_hif_poll(dev, &(prCtrlExptHifPoll->reset_event));
        }
            break;

        case TTY_CMD_GET_CHUNK_SIZE:
        {
            UART_CTRL_GET_CHUNK_SIZE_T *prCtrlChunkSize;
            prCtrlChunkSize = &(data->rUARTCtrlGETCHUNKSIZE);
            ret_status = cccitty_ttyc_hdr_cmd_get_chunk_size(dev, &(prCtrlChunkSize->chunkSize));
        }
            break;

        case TTY_CMD_GET_MTU_SIZE:
        {
            UART_CTRL_GET_MTU_SIZE_T *prCtrlMTUSize;
            prCtrlMTUSize = &(data->rUARTCtrlGETMTUSIZE);
            ret_status = cccitty_ttyc_hdr_cmd_get_mtu_size(dev, &(prCtrlMTUSize->dlmtu_sz), &(prCtrlMTUSize->ulmtu_sz));
            
        }
            break;

        /*
         * Exception command - End.
         */
        default:
        {
            ret_status = STATUS_INVALID_CMD;
        }
            break;
    }
    
    return ret_status;

}
Seriport_HANDLER_T  Uart_CCCI_Expt_Drv_Handler = {DCL_UART_CCCI_TYPE, cccitty_ttyc_expt_hdr};
/*!
 * @function        [Exception]cccitty_dev_expt_init
 * @brief           exception initialization function
 *
 * @return          kal_bool
 */
kal_bool cccitty_dev_expt_init(void)
{
    DCL_HANDLE  tty_expt_handler; /* TTY exception handler. */

    //4 <1> DclSerialPort_Open
    tty_expt_handler = DclSerialPort_Open(uart_port_dhl_sp_expt, FLAGS_NONE);
    //4 <2> DclSerialPort_DrvRegisterCb
    DclSerialPort_DrvRegisterCb(tty_expt_handler, &Uart_CCCI_Expt_Drv_Handler);
    //4 <3> DclSerialPort_DrvAttach
    DclSerialPort_DrvAttach(tty_expt_handler);

    //4 <1> DclSerialPort_Open
    tty_expt_handler = DclSerialPort_Open(uart_port_dhl_ctrl_sp_expt, FLAGS_NONE);
    //4 <2> DclSerialPort_DrvRegisterCb
    DclSerialPort_DrvRegisterCb(tty_expt_handler, &Uart_CCCI_Expt_Drv_Handler);
    //4 <3> DclSerialPort_DrvAttach
    DclSerialPort_DrvAttach(tty_expt_handler);

    return KAL_TRUE;
}
