/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_wcdma.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  WCDMA Function
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)


/*************************************************************************
* Include Statements for KAL
 *************************************************************************/

#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "md_sap.h"
#include "svc_sap.h"
#include "ft_msgid.h"

#include "ul1tst_public.h"


/*************************************************************************
* Include Statements for MAUI
 *************************************************************************/
#include "ft_msg.h"
#include "ft_private.h"
#include "ft_public.h"
#include "ft_fnc_wcdma.h"
// added in RHR first round
#include "l1_types_public.h"
// added in RHR first round
#include "ul1tst_msg.h"
// added in RHR first round
//MSBB remove #include "fctycomp_config.h"
// added in RHR first round
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
UL1D_RF_FHC_CNF_T *g_pFtWcdmaFHCRes = NULL;
kal_bool g_bFtWcdmaFhcWaiting = KAL_FALSE;
kal_bool g_bFtWcdmaNsftWaiting = KAL_FALSE;
kal_bool g_bFtWcdmaFhcResultReady = KAL_FALSE;
/***********************************************
 * UL1 runtime setting API (Start)
 **********************************************/
void setTempDacToL1D( peer_buff_struct* peer_buff_ptr, ul1cal_tempdacData_T *ul1cal_tempdacData_ft )
{
    ul1cal_tempdacData_T *tempdacData;
    kal_uint16        pdu_length;
    if(ul1cal_tempdacData_ft==NULL)
    {
        tempdacData = (ul1cal_tempdacData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        tempdacData = ul1cal_tempdacData_ft;
    }
    UL1D_RF_SetTempDac(tempdacData);
}

void setPathLossToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_pathlossData_T *ul1cal_pathlossData_ft)
{
    ul1cal_pathlossData_T *pathlossData;
    kal_uint16        pdu_length;
    if(ul1cal_pathlossData_ft==NULL)
    {
        pathlossData = (ul1cal_pathlossData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        pathlossData = ul1cal_pathlossData_ft;
    }
    UL1D_RF_SetPathLossTable((UMTSBand)rf_band, pathlossData);
}

void setTxDacToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_txdacData_T *ul1cal_txdacData_ft)
{
    ul1cal_txdacData_T *txdacData;
    kal_uint16        pdu_length;
    if(ul1cal_txdacData_ft==NULL)
    {
        txdacData = (ul1cal_txdacData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        txdacData = ul1cal_txdacData_ft;
    }
    UL1D_RF_SetTxDacData((UMTSBand)rf_band, txdacData);
}
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
void setPaOctLevDataToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_txPaOctLevData_T *ul1cal_txPaOctLevData_ft)
{
    ul1cal_txPaOctLevData_T *txPaOctLevData;
    kal_uint16        pdu_length;
    if(ul1cal_txPaOctLevData_ft==NULL)
    {
        txPaOctLevData = (ul1cal_txPaOctLevData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        txPaOctLevData = ul1cal_txPaOctLevData_ft;
    }
    UL1D_RF_SetTxPaOctLevData((UMTSBand)rf_band, txPaOctLevData);
}

#if defined (__UMTS_R8__)
//For R8
void setRxdPathlossL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_pathlossRxdData_T *ul1cal_pathlossRxdData_ft)
{
    ul1cal_pathlossRxdData_T *rxd_pathlossData;
    kal_uint16        pdu_length;
    if(ul1cal_pathlossRxdData_ft==NULL)
    {
        rxd_pathlossData = (ul1cal_pathlossRxdData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        rxd_pathlossData = ul1cal_pathlossRxdData_ft;
    }
    UL1D_RF_SetPathLossRxdTable((UMTSBand)rf_band, rxd_pathlossData);
}
//For R8
void setTxPaDriftL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_txPaDriftCompData_T *ul1cal_paDriftCompData_ft)
{
    ul1cal_txPaDriftCompData_T *paDriftCompData;
    kal_uint16        pdu_length;
    if(ul1cal_paDriftCompData_ft==NULL)
    {
        paDriftCompData = (ul1cal_txPaDriftCompData_T *)get_peer_buff_pdu( peer_buff_ptr, &pdu_length );
    }
    else
    {
        paDriftCompData = ul1cal_paDriftCompData_ft;
    }
    UL1D_RF_SetTxPaDriftData((UMTSBand)rf_band, paDriftCompData);
}
#endif

#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
/***********************************************
 * UL1 runtime setting API (End)
 **********************************************/
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
UL1D_RF_FHC_EX_CNF_T *g_pFtWcdmaFHCResEx = NULL;
kal_bool g_bFtWcdmaFhcResultReadyEx = KAL_FALSE;
static void get_fhc_ex_result_handler(ft_urf_test_cnf_T* ptrMsg, ilm_struct* ilm_ptr)
{
    if(g_bFtWcdmaFhcResultReadyEx &&  g_pFtWcdmaFHCResEx != NULL)
    {
        ptrMsg->param.ok = KAL_TRUE;
    }
    else
    {
        ptrMsg->param.ok = KAL_FALSE;
    }
    if(ptrMsg->param.ok)
    {
        // send the confirm by peer buffer
        if( NULL != (ilm_ptr->peer_buff_ptr=construct_peer_buff(sizeof(UL1D_RF_FHC_EX_CNF_T), 0, 0, TD_CTRL)) )
        {
            if(g_pFtWcdmaFHCResEx != NULL)
            {
                kal_mem_cpy(get_peer_buff_pdu(ilm_ptr->peer_buff_ptr, &(ilm_ptr->peer_buff_ptr->pdu_len)), g_pFtWcdmaFHCResEx, sizeof(UL1D_RF_FHC_EX_CNF_T));
                free_ctrl_buffer(g_pFtWcdmaFHCResEx);
                g_pFtWcdmaFHCResEx = NULL;
            }
        }
    }
}
static void ul1tst_cmd_mqc_octlev_handler(ul1tst_ft_cnf_T *ptrMsgbody)
{
    kal_int32 i;
    kal_int32 j;
    // store the result in local control buffer
    if(g_pFtWcdmaFHCResEx == NULL)
    {
        g_pFtWcdmaFHCResEx = (UL1D_RF_FHC_EX_CNF_T *)get_ctrl_buffer(sizeof(UL1D_RF_FHC_EX_CNF_T));
    }
    ASSERT(g_pFtWcdmaFHCResEx);
    {
        tst_sys_trace("handle UL1D data");
        g_pFtWcdmaFHCResEx->ok = ptrMsgbody->param.mqc_octlev.ok;
        g_pFtWcdmaFHCResEx->freq_count = ptrMsgbody->param.mqc_octlev.freq_count;
        g_pFtWcdmaFHCResEx->pwr_count = ptrMsgbody->param.mqc_octlev.pwr_count;
        g_pFtWcdmaFHCResEx->freq_start_idx = ptrMsgbody->param.mqc_octlev.freq_start_idx;
        g_pFtWcdmaFHCResEx->pwr_start_idx = ptrMsgbody->param.mqc_octlev.pwr_start_idx;
        kal_mem_cpy(g_pFtWcdmaFHCResEx->rx_lna_mode,ptrMsgbody->param.mqc_octlev.rx_lna_mode, sizeof(kal_int8)*400);
        kal_mem_cpy(g_pFtWcdmaFHCResEx->rssi,ptrMsgbody->param.mqc_octlev.rssi, sizeof(kal_int16)*400);

        kal_mem_cpy(g_pFtWcdmaFHCResEx->rxd_lna_mode, ptrMsgbody->param.mqc_octlev.rxd_lna_mode, sizeof(kal_uint8)*400);
        kal_mem_cpy(g_pFtWcdmaFHCResEx->rxd_rssi, ptrMsgbody->param.mqc_octlev.rssi_rxd, sizeof(kal_int16)*400);
        kal_mem_cpy(g_pFtWcdmaFHCResEx->Gbb_Offset, ptrMsgbody->param.mqc_octlev.mqc_tx_gvgabb0_report, sizeof(kal_int16)*400);
        for(i=0;i<g_pFtWcdmaFHCResEx->freq_count;i++)
        {
            for(j=0;j<3;j++)
            {
                g_pFtWcdmaFHCResEx->pwr_det_value[i][j] = ptrMsgbody->param.mqc_octlev.pwr_det_value[i][j];
            }
        }
    }
    g_bFtWcdmaFhcResultReadyEx = KAL_TRUE;
}
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
void FT_FtURfTestReq( ft_urf_test_req_T  *req, peer_buff_struct *p_peer_buff_ptr )
{
    kal_uint8         i;
    kal_uint8         j;
    kal_uint16        pdu_length;
    switch (req->type)
    {
/*R8*/  case URF_TEST_CMD_SET_TX_PA_DRIFT_COMPENSATION:      
/*R8*/  case URF_TEST_CMD_SET_ICS_CELL_POWER:      
        case URF_TEST_CMD_TXACCESS:
        case URF_TEST_CMD_STOP:
        case URF_TEST_CMD_TX_DPCH:
        case URF_TEST_CMD_RSSI:
        case URF_TEST_CMD_RSSI_RXD: /**< \breif R8 get both rx path RSSI */
        case URF_TEST_CMD_SET_RX_ANTENNA:  /**< \breif R8 set rx path */
        case URF_TEST_CMD_CONTINUOUS_RX:
        case URF_TEST_CMD_RSCP:
        case URF_TEST_CMD_AFC:
        case URF_TEST_CMD_START_FHC:
        case URF_TEST_CMD_START_FHC_NO_WAIT:
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
        case URF_TEST_CMD_AFC_EX:
        case URF_TEST_CMD_START_FHC_EX:
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case URF_TEST_CMD_START_NSFT:
        case URF_TEST_CMD_START_NSFT_EX:
#if defined (__HSDPA_SUPPORT__)
        case URF_TEST_CMD_START_HSDPA_NSFT:
#endif // defined (__HSDPA_SUPPORT__)
#if defined (__HSUPA_SUPPORT__)
        case URF_TEST_CMD_START_HSUPA_NSFT:
#endif // defined (__HSUPA_SUPPORT__)
#if defined (__UL1_HS_PLUS_PLATFORM__)
        case URF_TEST_CMD_GET_RF_TEMP_BSI:
        case URF_TEST_CMD_GET_RF_CAPABILITY:
#endif // #if defined (__UL1_HS_PLUS_PLATFORM__)
        case URF_TEST_CMD_START_NSFT_LIST_MODE:
        case URF_TEST_CMD_SET_RF_MIPI_CODEWORD:
        case URF_TEST_CMD_GET_RF_MIPI_CODEWORD:
        case URF_TEST_CMD_GET_TEMPERATURE_INFO:
        case URF_TEST_CMD_RX_GAIN_SWEEP:
        {
            //FT_FtURfTestReq_Advanced(req, p_peer_buff_ptr);
            ft_urf_test_cnf_T *ptrMsg;
            ft_ul1tst_req_T *ptrMsg_ul1tst;
            ilm_struct         ilm_ptr;
            ilm_struct         ilm_ptr_ul1tst;
            bool send_cnf_immediately = false;
            // allocate message to send to ul1tst;
            FT_ALLOC_MSG(&ilm_ptr_ul1tst, sizeof( ft_ul1tst_req_T ));
            ptrMsg_ul1tst = ( ft_ul1tst_req_T* )ilm_ptr_ul1tst.local_para_ptr;
            switch (req->type)
            {
        /*R8*/  case URF_TEST_CMD_SET_TX_PA_DRIFT_COMPENSATION:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_PA_DRIFT_SWITCH;
                    ptrMsg_ul1tst->param.is_PaDrift = req->param.is_PaDrift;
                    send_cnf_immediately = false;
                    break;
                }
        /*R8*/  case URF_TEST_CMD_SET_ICS_CELL_POWER:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_RX_CELL_POWER;
                    ptrMsg_ul1tst->param.rx_cell_power = req->param.m_i4IcsCellPower;
                    send_cnf_immediately = false;
                    break;
                }
                case URF_TEST_CMD_SET_RX_ANTENNA:  /**< \breif R8 set rx path */
                    ptrMsg_ul1tst->type = UL1TST_CMD_ANT_MODE;
                    ptrMsg_ul1tst->param.rxdMode = req->param.is_main;
                    break;
                case URF_TEST_CMD_TXACCESS:
                    ptrMsg_ul1tst->type = UL1TST_CMD_TXACCESS;
                    // 20100124 YH changed (Rick provided new API and don't need backward compatibility)
                    ptrMsg_ul1tst->param.txaccess.ul_uarfcn = req->param.txaccess.ul_uarfcn;
                    ptrMsg_ul1tst->param.txaccess.dl_uarfcn = req->param.txaccess.dl_uarfcn;
                    ptrMsg_ul1tst->param.txaccess.dl_psc = req->param.txaccess.dl_psc;
                    ptrMsg_ul1tst->param.txaccess.signature = req->param.txaccess.signature;
                    ptrMsg_ul1tst->param.txaccess.pa_mode = req->param.txaccess.pa_mode;
                    ptrMsg_ul1tst->param.txaccess.init_power = req->param.txaccess.init_power;
                    ptrMsg_ul1tst->param.txaccess.power_step = req->param.txaccess.power_step;
                    ptrMsg_ul1tst->param.txaccess.max_retrans = req->param.txaccess.max_retrans;
                    ptrMsg_ul1tst->param.txaccess.asc = req->param.txaccess.asc;
                    // Return CNF to META.
                    send_cnf_immediately = true;
                    break;
                case URF_TEST_CMD_STOP:
                    ptrMsg_ul1tst->type = UL1TST_CMD_STOP;
                    send_cnf_immediately = true;
                    break;
                case URF_TEST_CMD_TX_DPCH:
                    ptrMsg_ul1tst->type = UL1TST_CMD_TX_DPCH;
                    ptrMsg_ul1tst->param.txdpch.ul_freq = req->param.txdpch.ul_freq;
                    ptrMsg_ul1tst->param.txdpch.psc = req->param.txdpch.psc;
                    ptrMsg_ul1tst->param.txdpch.sc_code = req->param.txdpch.sc_code;
                    ptrMsg_ul1tst->param.txdpch.power_ctrl_mode = req->param.txdpch.power_ctrl_mode;
                    ptrMsg_ul1tst->param.txdpch.pa_mode = req->param.txdpch.pa_mode;
                    ptrMsg_ul1tst->param.txdpch.idx = req->param.txdpch.idx;
                    ptrMsg_ul1tst->param.txdpch.afc_dac = req->param.txdpch.afc_dac;
                    ptrMsg_ul1tst->param.txdpch.dpcch_pwr = req->param.txdpch.dpcch_pwr;
                    ptrMsg_ul1tst->param.txdpch.dpdch_pwr = req->param.txdpch.dpdch_pwr;
                    //ptrMsg_ul1tst->param.txdpch.no_loop_ctrl = req->param.txdpch.no_loop_ctrl;
                    ptrMsg_ul1tst->param.txdpch.rf_band = req->param.txdpch.rf_band;
                    ptrMsg_ul1tst->param.txdpch.vm1 = req->param.txdpch.vm1;
                    ptrMsg_ul1tst->param.txdpch.vm2 = req->param.txdpch.vm2;
                    ptrMsg_ul1tst->param.txdpch.dc2dc_dac = req->param.txdpch.dc2dc_dac;
                    ptrMsg_ul1tst->param.txdpch.vbias_dac = req->param.txdpch.vbias_dac;
                    ptrMsg_ul1tst->param.txdpch.pwr_det = req->param.txdpch.pwr_det;
                    ptrMsg_ul1tst->param.txdpch.apc_dac = req->param.txdpch.apc_dac;
                    //FT_SEND_MSG( MOD_FT, MOD_UL1TST, FT_UL1TST_SAP, MSG_ID_FT_TO_UL1TST, &ilm_ptr_ul1tst );
                    send_cnf_immediately = true;
                    break;
                case URF_TEST_CMD_RSSI_RXD: /**< \breif R8 get both rx path RSSI */
                case URF_TEST_CMD_RSSI:
                case URF_TEST_CMD_CONTINUOUS_RX:
                {
                    if(req->type == URF_TEST_CMD_CONTINUOUS_RX)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_RSSI_CONT;
                    }
                    else
                    {
                        ptrMsg_ul1tst->type = (req->type == URF_TEST_CMD_RSSI)? UL1TST_CMD_RSSI:UL1TST_CMD_RSSI_RXD;
                    }

                    // extract the request from peer buffer
                    if(p_peer_buff_ptr != NULL)
                    {
                        URfTestCmdRSSI  *ft_rssi_req_t = (URfTestCmdRSSI*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );
                        ptrMsg_ul1tst->param.rssi.temperature = ft_rssi_req_t->temperature;
                        ptrMsg_ul1tst->param.rssi.hwAGC =ft_rssi_req_t->hwAGC;
                        ptrMsg_ul1tst->param.rssi.mode = ft_rssi_req_t->mode;
                        ptrMsg_ul1tst->param.rssi.gain = ft_rssi_req_t->gain;
                        ptrMsg_ul1tst->param.rssi.LNAmode = ft_rssi_req_t->LNAmode;
                        ptrMsg_ul1tst->param.rssi.pga = ft_rssi_req_t->pga;
                        ptrMsg_ul1tst->param.rssi.num_freq = ft_rssi_req_t->num_freq;
                        ptrMsg_ul1tst->param.rssi.rssi_continue = (req->type == URF_TEST_CMD_CONTINUOUS_RX)? true:false;
                        for( i = 0 ; i < ft_rssi_req_t->num_freq ; i++ )
                            ptrMsg_ul1tst->param.rssi.dl_freq[ i ] = ft_rssi_req_t->dl_freq[ i ];
                    }
                    break;
                }
                case URF_TEST_CMD_RSCP:
                    ptrMsg_ul1tst->type = UL1TST_CMD_RSCP;
                    ptrMsg_ul1tst->param.rscp.hwAGC = req->param.rscp.hwAGC;
                    ptrMsg_ul1tst->param.rscp.mode = req->param.rscp.mode;
                    ptrMsg_ul1tst->param.rscp.gain = req->param.rscp.gain;
                    ptrMsg_ul1tst->param.rscp.LNAmode = req->param.rscp.LNAmode;
                    ptrMsg_ul1tst->param.rscp.pga = req->param.rscp.pga;
                    ptrMsg_ul1tst->param.rscp.dl_freq = req->param.rscp.dl_freq;
                    ptrMsg_ul1tst->param.rscp.sample_num_per_cell = req->param.rscp.sample_num_per_cell;
                    break;
                case URF_TEST_CMD_AFC:
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_AFC_EX:
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                {
                    if(req->type == URF_TEST_CMD_AFC)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_AFC;
                    }
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                    else if(req->type == URF_TEST_CMD_AFC_EX)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_AFC_EXT;
                    }
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                    ptrMsg_ul1tst->param.afc.dl_freq = req->param.afc.dl_freq;
                    ptrMsg_ul1tst->param.afc.hwAGC = req->param.afc.hwAGC;
                    ptrMsg_ul1tst->param.afc.mode = req->param.afc.mode;
                    ptrMsg_ul1tst->param.afc.gain = req->param.afc.gain;
                    ptrMsg_ul1tst->param.afc.LNAmode = req->param.afc.LNAmode;
                    ptrMsg_ul1tst->param.afc.pga = req->param.afc.pga;
                    ptrMsg_ul1tst->param.afc.afc_dac = req->param.afc.afc_dac;
                    break;
                }
                case URF_TEST_CMD_START_FHC:
                case URF_TEST_CMD_START_FHC_NO_WAIT:
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_START_FHC_EX:
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                {
                    if(p_peer_buff_ptr != NULL)
                    {
                        UL1D_RF_FHC_REQ_T  *ft_fhc_req_t = (UL1D_RF_FHC_REQ_T*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );
                        ptrMsg_ul1tst->param.mqc.no_loop_ctrl    = ft_fhc_req_t->no_loop_ctrl;
                        ptrMsg_ul1tst->param.mqc.afc_dac         = ft_fhc_req_t->afc_dac;
                        ptrMsg_ul1tst->param.mqc.pwr_det         = ft_fhc_req_t->pwr_det;
                        ptrMsg_ul1tst->param.mqc.power_ctrl_mode = ft_fhc_req_t->power_ctrl_mode;
                        for( i = 0 ; i < 10 ; i++ )
                        {
                            for(j = 0; j< 3; j++)
                            {
                                ptrMsg_ul1tst->param.mqc.vm1[i][j]       = ft_fhc_req_t->vm1[i][j];
                                ptrMsg_ul1tst->param.mqc.vm2[i][j]       = ft_fhc_req_t->vm2[i][j];
                                ptrMsg_ul1tst->param.mqc.dc2dc_dac[i][j] = ft_fhc_req_t->dc2dc_dac[i][j];
                                ptrMsg_ul1tst->param.mqc.vbias_dac[i][j] = ft_fhc_req_t->vbias_dac[i][j];
                            }
                        }
                        ptrMsg_ul1tst->param.mqc.init_tx_onoff         = ft_fhc_req_t->init_tx_onoff;
                        ptrMsg_ul1tst->param.mqc.ready_tx_onoff        = ft_fhc_req_t->ready_tx_onoff;
                        ptrMsg_ul1tst->param.mqc.init_pa_mode          = ft_fhc_req_t->init_pa_mode;
                        ptrMsg_ul1tst->param.mqc.ready_pa_mode         = ft_fhc_req_t->ready_pa_mode;
                        ptrMsg_ul1tst->param.mqc.init_pa_gain          = ft_fhc_req_t->init_pa_gain;
                        ptrMsg_ul1tst->param.mqc.ready_pa_gain         = ft_fhc_req_t->ready_pa_gain;
                        ptrMsg_ul1tst->param.mqc.init_vga_dac_tpc_idx  = ft_fhc_req_t->init_vga_dac_tpc_idx;
                        ptrMsg_ul1tst->param.mqc.ready_vga_dac_tpc_idx = ft_fhc_req_t->ready_vga_dac_tpc_idx;
                        ptrMsg_ul1tst->param.mqc.temperature           = ft_fhc_req_t->temperature;
                        ptrMsg_ul1tst->param.mqc.hwAGC                 = ft_fhc_req_t->hwAGC;
                        ptrMsg_ul1tst->param.mqc.gain_init             = ft_fhc_req_t->gain_init;
                        ptrMsg_ul1tst->param.mqc.init_condition        = ft_fhc_req_t->init_condition;
                        ptrMsg_ul1tst->param.mqc.step_duration         = ft_fhc_req_t->step_duration;
                        ptrMsg_ul1tst->param.mqc.ready_duration        = ft_fhc_req_t->ready_duration;
                        ptrMsg_ul1tst->param.mqc.retune_duration       = ft_fhc_req_t->retune_duration;
                        ptrMsg_ul1tst->param.mqc.gain_stable_time      = ft_fhc_req_t->gain_stable_time;
                        ptrMsg_ul1tst->param.mqc.max_vga_dac           = ft_fhc_req_t->max_vga_dac;
                        ptrMsg_ul1tst->param.mqc.min_vga_dac           = ft_fhc_req_t->min_vga_dac;
                        ptrMsg_ul1tst->param.mqc.jump_vga_dac          = ft_fhc_req_t->jump_vga_dac;
                        ptrMsg_ul1tst->param.mqc.freq_count            = ft_fhc_req_t->freq_count;
                        ptrMsg_ul1tst->param.mqc.pwr_count             = ft_fhc_req_t->pwr_count;
                        ptrMsg_ul1tst->param.mqc.freq_start_idx        = ft_fhc_req_t->freq_start_idx;
                        ptrMsg_ul1tst->param.mqc.pwr_start_idx         = ft_fhc_req_t->pwr_start_idx;
                        ptrMsg_ul1tst->param.mqc.odd_record            = ft_fhc_req_t->odd_record;
                        ptrMsg_ul1tst->param.mqc.pa_gain_start_idx     = ft_fhc_req_t->pa_gain_start_idx;
                        ptrMsg_ul1tst->param.mqc.pd_gain_start_idx     = ft_fhc_req_t->pd_gain_start_idx;

                        for( i = 0 ; i < 40 ; i++ )
                        {
                            ptrMsg_ul1tst->param.mqc.dl_band[i] = ft_fhc_req_t->dl_band[i];
                            ptrMsg_ul1tst->param.mqc.ul_band[i] = ft_fhc_req_t->ul_band[i];
                            ptrMsg_ul1tst->param.mqc.dl_freq[i] = ft_fhc_req_t->dl_freq[i];
                            ptrMsg_ul1tst->param.mqc.ul_freq[i] = ft_fhc_req_t->ul_freq[i];
                            ptrMsg_ul1tst->param.mqc.pa_mode[i] = ft_fhc_req_t->pa_mode[i];
                            ptrMsg_ul1tst->param.mqc.vga_dac_tpc_idx[i] = ft_fhc_req_t->vga_dac_tpc_idx[i];
                            ptrMsg_ul1tst->param.mqc.pa_gain[i] = ft_fhc_req_t->pa_gain[i];
                            ptrMsg_ul1tst->param.mqc.pd_gain[i] = ft_fhc_req_t->pd_gain[i];
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                            if(req->type == URF_TEST_CMD_START_FHC_EX)
                            {
                                UL1D_RF_FHC_EX_REQ_T *ft_fhc_ex_req_t = (UL1D_RF_FHC_EX_REQ_T *)ft_fhc_req_t;
                                ptrMsg_ul1tst->param.mqc.pa_section[i] = ft_fhc_ex_req_t->pa_section[i];
                                ptrMsg_ul1tst->param.mqc.dl_meta_gain[i] = ft_fhc_ex_req_t->lna_gain[i];
                            }
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                        }
                    }
                    if(req->type == URF_TEST_CMD_START_FHC)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_MQC;
                        send_cnf_immediately = KAL_FALSE;
                        g_bFtWcdmaFhcWaiting = KAL_TRUE;
                        g_bFtWcdmaFhcResultReady = KAL_FALSE;
                    }
                    else if(req->type == URF_TEST_CMD_START_FHC_NO_WAIT)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_MQC;
                        send_cnf_immediately = KAL_TRUE;
                        g_bFtWcdmaFhcWaiting = KAL_FALSE;
                        g_bFtWcdmaFhcResultReady = KAL_FALSE;
                    }
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                    else if(req->type == URF_TEST_CMD_START_FHC_EX)
                    {
                        ptrMsg_ul1tst->type = UL1TST_CMD_MQC_OCTLEV;
                        send_cnf_immediately = KAL_TRUE;
                        g_bFtWcdmaFhcWaiting = KAL_FALSE;
                        g_bFtWcdmaFhcResultReadyEx = KAL_FALSE;
                }
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                break;
                }
                case URF_TEST_CMD_START_NSFT:
                case URF_TEST_CMD_START_NSFT_EX:
#if defined (__HSDPA_SUPPORT__)
                case URF_TEST_CMD_START_HSDPA_NSFT:
#endif // #if defined (__HSDPA_SUPPORT__)
#if defined (__HSUPA_SUPPORT__)
                case URF_TEST_CMD_START_HSUPA_NSFT:
#endif // #if defined (__HSUPA_SUPPORT__)
                {
                    if(p_peer_buff_ptr != NULL)
                    {
                        UL1D_RF_NSFT_REQ_T  *ft_nsft_req_t = (UL1D_RF_NSFT_REQ_T*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );
                        ptrMsg_ul1tst->param.nsft.afc_dac_valid    = ft_nsft_req_t->b_afc_dac_valid;
                        ptrMsg_ul1tst->param.nsft.afc_dac    = ft_nsft_req_t->u2_afc_dac;
                        ptrMsg_ul1tst->param.nsft.loopbackType    = ft_nsft_req_t->u1_loopbackType;
                        ptrMsg_ul1tst->param.nsft.frame_shift    = ft_nsft_req_t->u1_frame_shift;
                        ptrMsg_ul1tst->param.nsft.rmc_type    = ft_nsft_req_t->u1_rmc_type;
                        for(i=0; i<4; i++)
                        {
                            ptrMsg_ul1tst->param.nsft.ctfc[i]    = ft_nsft_req_t->u1_ctfc[i];
                        }
                        ptrMsg_ul1tst->param.nsft.bit_pattern    = ft_nsft_req_t->u1_bit_pattern;
                        ptrMsg_ul1tst->param.nsft.dl_freq    = ft_nsft_req_t->i2_dl_freq;
                        ptrMsg_ul1tst->param.nsft.dl_psc    = ft_nsft_req_t->i2_dl_psc;
                        ptrMsg_ul1tst->param.nsft.dl_ovsf    = ft_nsft_req_t->i2_dl_ovsf;
                        ptrMsg_ul1tst->param.nsft.ul_freq    = ft_nsft_req_t->i2_ul_freq;
                        ptrMsg_ul1tst->param.nsft.ul_tfci    = ft_nsft_req_t->u2_ul_tfci;
                        ptrMsg_ul1tst->param.nsft.ul_sc_code    = ft_nsft_req_t->u4_ul_sc_code;
                        ptrMsg_ul1tst->param.nsft.iq_pwr_valid    = ft_nsft_req_t->b_iq_pwr_valid;
                        ptrMsg_ul1tst->param.nsft.dpcch_pwr    = ft_nsft_req_t->u1_dpcch_pwr;
                        ptrMsg_ul1tst->param.nsft.dpdch_pwr    = ft_nsft_req_t->u1_dpdch_pwr;
                        if(req->type == URF_TEST_CMD_START_NSFT || req->type == URF_TEST_CMD_START_NSFT_EX)
                        {
                            ptrMsg_ul1tst->type = UL1TST_CMD_NSFT;
                        }
#if defined (__HSDPA_SUPPORT__)
                        else if(req->type == URF_TEST_CMD_START_HSDPA_NSFT)
                        {
                            ptrMsg_ul1tst->type = UL1TST_CMD_HSDPA_NSFT;
                            ptrMsg_ul1tst->param.nsft.subtest = ((URfTestCmdHspaNsft*)ft_nsft_req_t)->subTest;
                        }
#endif // #if defined (__HSDPA_SUPPORT__)
#if defined (__HSUPA_SUPPORT__)
                        else if(req->type == URF_TEST_CMD_START_HSUPA_NSFT)
                        {
                            ptrMsg_ul1tst->type = UL1TST_CMD_HSUPA_NSFT;
                            ptrMsg_ul1tst->param.nsft.subtest = ((URfTestCmdHspaNsft*)ft_nsft_req_t)->subTest;
                        }
#endif // #if defined (__HSUPA_SUPPORT__)
                    }
                    // 20100129 wait for Report
                    if(URF_TEST_CMD_START_NSFT == req->type)
                    {
                        send_cnf_immediately = true; // the UL1TST will send back link status report when the DCH is synced
                        g_bFtWcdmaNsftWaiting = KAL_FALSE; // indication of the report should be discarded
                    }
                    else
                    {
                        send_cnf_immediately = false;
                        g_bFtWcdmaNsftWaiting = KAL_TRUE;
                    }
                }
                break;
#if defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_GET_RF_TEMP_BSI:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_GET_RF_TEMP;
                    ptrMsg_ul1tst->param.rfTemperature.measure_count = req->param.rfTemperature.measure_count;
                    break;
                }
                case URF_TEST_CMD_GET_RF_CAPABILITY:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_GET_RF_CAPABILITY;
                    break;
                }
#endif // #if defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_START_NSFT_LIST_MODE:
                {                          
                    if(p_peer_buff_ptr != NULL)
                    {
                        URfNsftListModeReq *ft_nsft_list_mode_req_t = (URfNsftListModeReq*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );            	
                        ptrMsg_ul1tst->param.listmode.afc_dac_valid    = ft_nsft_list_mode_req_t->afc_dac_valid;
                        ptrMsg_ul1tst->param.listmode.afc_dac    = ft_nsft_list_mode_req_t->afc_dac;
                        ptrMsg_ul1tst->param.listmode.loopbackType    = ft_nsft_list_mode_req_t->loopbackType;
                        ptrMsg_ul1tst->param.listmode.frame_shift    = ft_nsft_list_mode_req_t->frame_shift;
                        ptrMsg_ul1tst->param.listmode.rmc_type    = ft_nsft_list_mode_req_t->rmc_type;
                        for(i=0; i<4; i++)
                        {
                            ptrMsg_ul1tst->param.listmode.ctfc[i]    = ft_nsft_list_mode_req_t->ctfc[i];
                        }
                        ptrMsg_ul1tst->param.listmode.bit_pattern    = ft_nsft_list_mode_req_t->bit_pattern;
                        for(i=0; i<50; i++)
                        {
                            ptrMsg_ul1tst->param.listmode.dl_freq[i]    = ft_nsft_list_mode_req_t->dl_freq[i];
                        }                        
                        ptrMsg_ul1tst->param.listmode.dl_psc    = ft_nsft_list_mode_req_t->dl_psc;
                        ptrMsg_ul1tst->param.listmode.dl_ovsf    = ft_nsft_list_mode_req_t->dl_ovsf;
                        for(i=0; i<50; i++)
                        {
                            ptrMsg_ul1tst->param.listmode.ul_freq[i]    = ft_nsft_list_mode_req_t->ul_freq[i];
                        }                                 
                        ptrMsg_ul1tst->param.listmode.ul_tfci    = ft_nsft_list_mode_req_t->ul_tfci;
                        ptrMsg_ul1tst->param.listmode.ul_sc_code    = ft_nsft_list_mode_req_t->ul_sc_code;
                        ptrMsg_ul1tst->param.listmode.iq_pwr_valid    = ft_nsft_list_mode_req_t->iq_pwr_valid;
                        ptrMsg_ul1tst->param.listmode.dpcch_pwr    = ft_nsft_list_mode_req_t->dpcch_pwr;
                        ptrMsg_ul1tst->param.listmode.dpdch_pwr    = ft_nsft_list_mode_req_t->dpdch_pwr;
                        ptrMsg_ul1tst->param.listmode.valid_freq    = ft_nsft_list_mode_req_t->valid_freq;
						for(i=0; i<50; i++)
                        {
                            ptrMsg_ul1tst->param.listmode.test_item[i]    = ft_nsft_list_mode_req_t->test_item[i];
						}
                        ptrMsg_ul1tst->param.listmode.full_test_time    = ft_nsft_list_mode_req_t->full_test_time;
						ptrMsg_ul1tst->param.listmode.ready_time    = ft_nsft_list_mode_req_t->ready_time;
                        ptrMsg_ul1tst->param.listmode.sync_time    = ft_nsft_list_mode_req_t->sync_time;
                        ptrMsg_ul1tst->param.listmode.retrial    = ft_nsft_list_mode_req_t->retrial;                        
                        ptrMsg_ul1tst->param.listmode.test_time    = ft_nsft_list_mode_req_t->test_time;
						for(i=0; i<3; i++)
                        {
                            ptrMsg_ul1tst->param.listmode.rx_rssi_start_time[i]    = ft_nsft_list_mode_req_t->rx_rssi_start_time[i];
                            ptrMsg_ul1tst->param.listmode.rx_rssi_duration[i]    = ft_nsft_list_mode_req_t->rx_rssi_duration[i];
						}
						ptrMsg_ul1tst->param.listmode.rx_ber_start_time    = ft_nsft_list_mode_req_t->rx_ber_start_time;
                        ptrMsg_ul1tst->param.listmode.rx_ber_duration    = ft_nsft_list_mode_req_t->rx_ber_duration;
                        ptrMsg_ul1tst->param.listmode.ILPC_ABC_time    = ft_nsft_list_mode_req_t->ILPC_ABC_time;
                        ptrMsg_ul1tst->param.listmode.ILPC_EF_time    = ft_nsft_list_mode_req_t->ILPC_EF_time;
                        ptrMsg_ul1tst->param.listmode.ILPC_GH_time    = ft_nsft_list_mode_req_t->ILPC_GH_time;
                        ptrMsg_ul1tst->param.listmode.transition_time    = ft_nsft_list_mode_req_t->transition_time;
                        ptrMsg_ul1tst->type = UL1TST_CMD_LIST_MODE;
                    }
                    break; 
                }
                case URF_TEST_CMD_SET_RF_MIPI_CODEWORD:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_SET_RF_MIPI_CODEWORD;
                    ptrMsg_ul1tst->param.setMipiPaCwParam.rf_band_idx = req->param.set_mipi_cw_param.rf_band_idx;
                    ptrMsg_ul1tst->param.setMipiPaCwParam.power_level_num = req->param.set_mipi_cw_param.power_level_num;
                    ptrMsg_ul1tst->param.setMipiPaCwParam.code_word_num = req->param.set_mipi_cw_param.code_word_num;
                    if(NULL != p_peer_buff_ptr)
                    {
                        hold_peer_buff(p_peer_buff_ptr);
                        ilm_ptr_ul1tst.peer_buff_ptr = p_peer_buff_ptr;                         
                    }                        
                    break;
                }
                case URF_TEST_CMD_GET_RF_MIPI_CODEWORD:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_GET_RF_MIPI_CODEWORD;
                    ptrMsg_ul1tst->param.mipi_rf_band = req->param.rf_band_idx;                         
                    break;
                }
                case URF_TEST_CMD_GET_TEMPERATURE_INFO:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_GET_RF_TEMP_INFO;                
                    break;    
                }
                case URF_TEST_CMD_RX_GAIN_SWEEP:
                {
                    ptrMsg_ul1tst->type = UL1TST_CMD_RX_GAIN_SWEEP;
                    // extract the request from peer buffer
                    if(p_peer_buff_ptr != NULL)
                    {
                        URfTestCmdRxGainSweep  *ft_rx_gain_sweep_req_t = (URfTestCmdRxGainSweep*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );
                        ptrMsg_ul1tst->param.rx_gain_sweep.temperature = ft_rx_gain_sweep_req_t->temperature;
                        ptrMsg_ul1tst->param.rx_gain_sweep.hwAGC =ft_rx_gain_sweep_req_t->hwAGC;
                        ptrMsg_ul1tst->param.rx_gain_sweep.mode = ft_rx_gain_sweep_req_t->mode;
                        ptrMsg_ul1tst->param.rx_gain_sweep.gain = ft_rx_gain_sweep_req_t->gain;
                        ptrMsg_ul1tst->param.rx_gain_sweep.LNAmode = ft_rx_gain_sweep_req_t->LNAmode;
                        ptrMsg_ul1tst->param.rx_gain_sweep.pga = ft_rx_gain_sweep_req_t->pga;
                        ptrMsg_ul1tst->param.rx_gain_sweep.num_freq = ft_rx_gain_sweep_req_t->num_freq;
                        ptrMsg_ul1tst->param.rx_gain_sweep.rssi_continue = (req->type == URF_TEST_CMD_CONTINUOUS_RX)? true:false;
                        for( i = 0 ; i < ft_rx_gain_sweep_req_t->num_freq ; i++ )
                            ptrMsg_ul1tst->param.rx_gain_sweep.dl_freq[ i ] = ft_rx_gain_sweep_req_t->dl_freq[ i ];
                    }
                    break;
                }
                default:
                break;
            }
            FT_SEND_MSG( MOD_FT, MOD_UL1TST, FT_UL1TST_SAP, MSG_ID_FT_TO_UL1TST, &ilm_ptr_ul1tst );

            // send confirm to PC side
            if(send_cnf_immediately)
            {
                FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_urf_test_cnf_T));
                ptrMsg = (ft_urf_test_cnf_T*)ilm_ptr.local_para_ptr;
                ptrMsg->header.ft_msg_id = FT_URF_TEST_CNF_ID;
                ptrMsg->type = req->type;
                ptrMsg->param.ok = KAL_TRUE;
                FT_SEND_MSG_TO_PC(&ilm_ptr);
            }
            break;
        }
        case URF_TEST_CMD_TX_PAAPC:
        case URF_TEST_CMD_CONFIG_HWTPC:
        case URF_TEST_CMD_GET_RFID:
        case URF_TEST_CMD_GET_PWR_DT_STEP:
        case URF_TEST_CMD_GET_PWR_DT_DAC:
        case URF_TEST_CMD_GET_PWR_DT_DEFAULT_THR:
        case URF_TEST_CMD_SET_IMMEDIATE_BSI:
        case URF_TEST_CMD_GET_IMMEDIATE_BSI:
        case URF_TEST_CMD_SET_TXDAC_DATA:
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case URF_TEST_CMD_SET_PA_OCT_LEVEL_DATA:
        case URF_TEST_CMD_GET_FHC_EX_RESULT:
        case URF_TEST_CMD_GET_CURRENT_LNA_MODE:
        case URF_TEST_CMD_GET_CURRENT_RXD_LNA_MODE: /**< \brief R8 get Rx diversity path LNA mode */
        case URF_TEST_CMD_SET_RX_BANDWIDTH:
        /* DCXO development */
        case URF_TEST_CMD_SET_CAPID:
        case URF_TEST_CMD_GET_MAX_CAPID:
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case URF_TEST_CMD_GET_PWR_DET_MEASURE_RES:
        case URF_TEST_CMD_SET_PWR_CTRL_MODE:
        case URF_TEST_CMD_REPLACE_GAIN_TABLE_FOR_CAL:
        case URF_TEST_CMD_QUERY_TARGET_CAPABILITY:
        case URF_TEST_CMD_GET_FHC_RESULT:
        case URF_TEST_CMD_GET_BIT_COUNT_FOR_SINGLE_ENDED_BER:
        case URF_TEST_CMD_NSFT_SET_ILPC_STEP:
        {
            //FT_FtURfTestReq_Basic(req, p_peer_buff_ptr);
            ilm_struct  ilm_ptr;
            ft_urf_test_cnf_T *ptrMsg;
            FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_urf_test_cnf_T) );
            ptrMsg = (ft_urf_test_cnf_T*)ilm_ptr.local_para_ptr;
            ptrMsg->header.ft_msg_id = FT_URF_TEST_CNF_ID;
            ptrMsg->type = req->type;
            switch(req->type)
            {
                case URF_TEST_CMD_TX_PAAPC:
                {
                     UL1D_RF_SetPaApcDac((UMTSBand)req->param.m_rTxPaApc.m_cRfBand, req->param.m_rTxPaApc.m_u2Idx,
                                                      req->param.m_rTxPaApc.m_ucPaMode,
                                                      req->param.m_rTxPaApc.m_ucVm1,
                                                      req->param.m_rTxPaApc.m_ucVm2,
                                                      req->param.m_rTxPaApc.m_u2DC2DC_Dac,
                                                      req->param.m_rTxPaApc.m_u2Vbias_Dac,
                                                      req->param.m_rTxPaApc.m_u2ApcDac);
                    ptrMsg->param.ok = KAL_TRUE;
                    break;
                }
                case URF_TEST_CMD_CONFIG_HWTPC:
                {
                    // extract the request from peer buffer
                    if(p_peer_buff_ptr != NULL)
                    {
                        UL1D_RF_HWTPC_CONFIG_REQ_T  *ft_hw_tpc_req_t = (UL1D_RF_HWTPC_CONFIG_REQ_T*) get_peer_buff_pdu( p_peer_buff_ptr, &pdu_length );
                        if(sizeof(META_HWTPC_FRAME_INFO) == sizeof(UL1D_RF_HWTPC_FRAME_INFO))
                        {
                            UL1D_Meta_HWTPC_Config(ft_hw_tpc_req_t->pc_algo,
                                    ft_hw_tpc_req_t->tpc_used_frame,
                                    ft_hw_tpc_req_t->p_ini,
                                    (META_HWTPC_FRAME_INFO*)ft_hw_tpc_req_t->frame_info);
                            ptrMsg->param.ok = KAL_TRUE;
                        }
                        else
                        {
                            ptrMsg->param.ok = KAL_FALSE;
                        }
                    }
                    ptrMsg->param.ok = KAL_TRUE;
                    break;
                }
                case URF_TEST_CMD_GET_RFID:
                {
                    ptrMsg->param.rfid.m_u4Rfid = UL1D_RF_GetID();
                    break;
                }
                case URF_TEST_CMD_GET_PWR_DT_STEP:
                {
                    ptrMsg->param.pwr_dt_step.m_u1Result = UL1D_RF_Get_pwr_dt_step();
                    break;
                }
                case URF_TEST_CMD_GET_PWR_DT_DAC:
                {
                    ptrMsg->param.pwr_dt_dac.m_u2Result = UL1D_RF_Get_pwr_dt_dac();
                    break;
                }
                case URF_TEST_CMD_GET_PWR_DT_DEFAULT_THR:
                {
                    ptrMsg->param.pwr_dt_default_thr.m_u1Result = UL1D_RF_Get_pwr_dt_default_thr(req->param.m_rGetPwrThr.rf_band);
                    break;
                }
                case URF_TEST_CMD_SET_IMMEDIATE_BSI:
                {
                    UL1D_RF_SetImmediateBSI(req->param.m_rBSIData);
                    ptrMsg->param.ok = KAL_TRUE;
                    break;
                }
                case URF_TEST_CMD_GET_IMMEDIATE_BSI:
                {
                    UL1D_RF_GetImmediateBSI(req->param.m_rBSIAddr, &(ptrMsg->param.bsi_data));
                    break;
                }
                case URF_TEST_CMD_SET_TXDAC_DATA:
                {
                    if(p_peer_buff_ptr != NULL)
                    {
                        setTxDacToL1D(req->param.m_u1RfBand, p_peer_buff_ptr, NULL);
                        ptrMsg->param.ok = true;
                    }
                    else
                        ptrMsg->param.ok = false;
                    break;
                }
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_SET_PA_OCT_LEVEL_DATA:
                {
                    if(p_peer_buff_ptr != NULL)
                    {
                        setPaOctLevDataToL1D(req->param.m_u1RfBand, p_peer_buff_ptr, NULL);
                        ptrMsg->param.ok = KAL_TRUE;
                    }
                    else
                        ptrMsg->param.ok = KAL_FALSE;
                    break;
                }
                case URF_TEST_CMD_GET_FHC_EX_RESULT:
                {
                    get_fhc_ex_result_handler(ptrMsg, &ilm_ptr);
                    break;
                }
                case URF_TEST_CMD_GET_CURRENT_RXD_LNA_MODE: /**< \brief R8 get Rx diversity path LNA mode */
                case URF_TEST_CMD_GET_CURRENT_LNA_MODE:
                {
#if defined (__UMTS_R8__)
                    ptrMsg->param.currentLnaMode = /* next line */
                       (req->type == URF_TEST_CMD_GET_CURRENT_LNA_MODE)? /* next line */
                        UL1D_RF_GetCurrRxLnaStatus():UL1D_RF_GetCurrRxDLnaStatus();
#else
                    ptrMsg->param.currentLnaMode = UL1D_RF_GetCurrRxLnaStatus();                                        
#endif //#if defined (__UMTS_R8__)                    
                    break;
                }
                /* R8 RF tool */
#if defined (__UMTS_R8__)
                case URF_TEST_CMD_SET_RX_BANDWIDTH:
                {
                    UL1D_RF_SetRxBandwidth(req->param.is_5mhz == 1 ? KAL_TRUE : KAL_FALSE);
                    break;
                }
#endif //#if defined (__UMTS_R8__)                    
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_GET_PWR_DET_MEASURE_RES:
                {
                    UL1D_RF_GetPwrDetMeas( req->param.m_u2TxPclIndex, &(ptrMsg->param.m_u2PwrDetResult) );
                    break;
                }
                case URF_TEST_CMD_SET_PWR_CTRL_MODE:
                {
                    UL1D_RF_SetPwrCtrlMode(req->param.m_u1PwrCtrlMode);
                    ptrMsg->param.ok = true;
                    break;
                }
                case URF_TEST_CMD_REPLACE_GAIN_TABLE_FOR_CAL:
                {
                    kal_int8 ret = UL1D_RF_Replace_Gain_Table_for_Cal(req->param.m_u1TableType);
                    if(ret < 0) ptrMsg->param.replace_gain_table.ok = false; // action is invalid!
                    else        ptrMsg->param.replace_gain_table.ok = true;
                    ptrMsg->param.replace_gain_table.m_i1CurGainTableState = ret;
                    break;
                }
                case URF_TEST_CMD_QUERY_TARGET_CAPABILITY:
                {
                    UMTS_MsCapabilityEx ms_cap;
                    UL1TST_MsCapability(&ms_cap);
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
#if defined (__UMTS_R8__)
                    ptrMsg->param.m_rTargetCapability.rxd_band_support = ms_cap.rxd_band_support;
                    ptrMsg->param.m_rTargetCapability.padrift_band_support = ms_cap.padrift_band_support;
#else
                    ptrMsg->param.m_rTargetCapability.rxd_band_support = 0; // not support
                    ptrMsg->param.m_rTargetCapability.padrift_band_support = 0; // not support
#endif //  #if defined (__UMTS_R8__)
#endif //  #if defined (__UL1_HS_PLATFORM__)
                    ptrMsg->param.m_rTargetCapability.band_support = ms_cap.band_support;
                    ptrMsg->param.m_rTargetCapability.capability = ms_cap.capability;
                    break;
                }
                case URF_TEST_CMD_GET_FHC_RESULT:
                {
                    UL1D_RF_FHC_CNF_T  *pFhcCnf = NULL;
                    peer_buff_struct *peer_buff_ret = NULL;
                    if(g_bFtWcdmaFhcResultReady &&  g_pFtWcdmaFHCRes != NULL)
                        ptrMsg->param.ok = true;
                    else
                        ptrMsg->param.ok = false;
                    if(ptrMsg->param.ok)
                    {
                        // send the confirm by peer buffer
                        if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(UL1D_RF_FHC_CNF_T), 0, 0, TD_CTRL)) )
                        {
                            pFhcCnf = (UL1D_RF_FHC_CNF_T*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                            // assign peer buffer
                            peer_buff_ret->pdu_len = sizeof(UL1D_RF_FHC_CNF_T);
                            ilm_ptr.peer_buff_ptr = peer_buff_ret;
                        }
                        if(g_pFtWcdmaFHCRes != NULL && pFhcCnf != NULL)
                        {
                            kal_mem_cpy(pFhcCnf, g_pFtWcdmaFHCRes, sizeof(UL1D_RF_FHC_CNF_T));
                            free_ctrl_buffer(g_pFtWcdmaFHCRes);
                            g_pFtWcdmaFHCRes = NULL;
                        }
                    }
                    break;
                }
                case URF_TEST_CMD_GET_BIT_COUNT_FOR_SINGLE_ENDED_BER:
                {
                     ptrMsg->param.m_rNSFTBERResult.bDataValid = UL1TST_GET_BIT_COUNT(&(ptrMsg->param.m_rNSFTBERResult.u4TotalBits),
                         &(ptrMsg->param.m_rNSFTBERResult.u4ErrorBits) );
                     break;
                }
                case URF_TEST_CMD_NSFT_SET_ILPC_STEP:
                {
                    ptrMsg->param.ok = UL1TST_NSFT_SetILPC_Step(req->param.m_u1ILPCStep);
                    break;
                }
                /* DCXO development */
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                case URF_TEST_CMD_SET_CAPID:
                {
                    UL1D_RF_SetCrystalCap(req->param.m_u4CapId);
                    ptrMsg->param.ok = KAL_TRUE;
                    break;
                }
                case URF_TEST_CMD_GET_MAX_CAPID:
                {
                    ptrMsg->param.m_u4MaxCapId = UL1TST_CAPID_MAX();
                    break;
                }
#endif //  #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
                default:
                    break;
            }
            FT_SEND_MSG_TO_PC(&ilm_ptr);
            break;
        }
        default:
              break;
    }
}
static void _ft_ul1tst_allocate_cnf_msg(ilm_struct* ilm, ft_urf_test_cnf_T** ft_urf_cnf_msg)
{
    FT_ALLOC_MSG(ilm, sizeof(ft_urf_test_cnf_T));
    *ft_urf_cnf_msg = (ft_urf_test_cnf_T*)ilm->local_para_ptr;
    (*ft_urf_cnf_msg)->header.ft_msg_id = FT_URF_TEST_CNF_ID;
}
void FT_UL1TST_SEND_CNF_BACK(ilm_struct *ptrMsg_ul1tst)
{
    kal_uint8 i;
    kal_uint16    pdu_length;
    ilm_struct       ilm_ptr;
    ft_urf_test_cnf_T *ptrMsg = NULL;
    ul1tst_ft_cnf_T *ptrMsgbody = NULL;
    ptrMsgbody = (ul1tst_ft_cnf_T*)ptrMsg_ul1tst->local_para_ptr;
    switch (ptrMsgbody->type)
    {
        case UL1TST_CMD_ANT_MODE: /**< \breif R8 set rx path */
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_SET_RX_ANTENNA;
            ptrMsg->param.ok = ptrMsgbody->param.ok; 
            break;          
        }
/*R8*/  case UL1TST_CMD_PA_DRIFT_SWITCH:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_SET_TX_PA_DRIFT_COMPENSATION;
            ptrMsg->param.ok = true;
            break;
        }
/*R8*/  case UL1TST_CMD_RX_CELL_POWER:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_SET_ICS_CELL_POWER;
            ptrMsg->param.ok = true;
            break;
        }
        case UL1TST_CMD_RSSI_RXD: /**< \breif R8 get both rx path RSSI */
        {
            URfTestResultRSSIRxD  *p_rssi_rxd_result;
            peer_buff_struct *peer_buff_ret = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_RSSI_RXD;//ptrMsgbody->type;
            // send the confirm by peer buffer
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(URfTestResultRSSIRxD), 0, 0, TD_CTRL)) ) 
            {
                p_rssi_rxd_result = (URfTestResultRSSIRxD*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                //kal_mem_cpy(pdu_ptr, &(ptrMsgbody->param.mqc), sizeof(URfTestResultMQC));
                p_rssi_rxd_result->ok = ptrMsgbody->param.rssi.ok;// = true;
                p_rssi_rxd_result->num_freq=ptrMsgbody->param.rssi.num_freq ;
                for( i = 0 ; i < ptrMsgbody->param.rssi.num_freq ; i++ )
                {
                    p_rssi_rxd_result->dl_freq[i]=ptrMsgbody->param.rssi_rxd.dl_freq[i];
                    p_rssi_rxd_result->rssi[i]=ptrMsgbody->param.rssi_rxd.rssi[i] ;
                    p_rssi_rxd_result->rssi_rxd[i]=ptrMsgbody->param.rssi_rxd.rssi_rxd[i] ;
                }
                peer_buff_ret->pdu_len = sizeof(URfTestResultRSSIRxD);
                // assign peer buffer
                ilm_ptr.peer_buff_ptr = peer_buff_ret;
            }
        }
        break;        
        case UL1TST_CMD_RSSI:
        {
            URfTestResultRSSI  *p_rssi_result;
            peer_buff_struct *peer_buff_ret = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_RSSI;//ptrMsgbody->type;
            // send the confirm by peer buffer
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(URfTestResultRSSI), 0, 0, TD_CTRL)) )
            {
                p_rssi_result = (URfTestResultRSSI*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                //kal_mem_cpy(pdu_ptr, &(ptrMsgbody->param.mqc), sizeof(URfTestResultMQC));
                p_rssi_result->ok = ptrMsgbody->param.rssi.ok;// = true;
                p_rssi_result->num_freq=ptrMsgbody->param.rssi.num_freq ;
                for( i = 0 ; i < ptrMsgbody->param.rssi.num_freq ; i++ )
                {
                    p_rssi_result->dl_freq[i]=ptrMsgbody->param.rssi.dl_freq[i];
                    p_rssi_result->rssi[i]=ptrMsgbody->param.rssi.rssi[i] ;
                }
                peer_buff_ret->pdu_len = sizeof(URfTestResultRSSI);
                // assign peer buffer
                ilm_ptr.peer_buff_ptr = peer_buff_ret;
            }
        }
        break;
        case UL1TST_CMD_RSSI_CONT:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_CONTINUOUS_RX;//ptrMsgbody->type;
            ptrMsg->param.ok =  true;
            break;
        }
        case UL1TST_CMD_RSCP:
        {
            URfTestResultRSCP  *p_rscp_result;
            peer_buff_struct *peer_buff_ret = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_RSCP;
            // send the confirm by peer buffer
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(URfTestResultRSCP), 0, 0, TD_CTRL)) )
            {
                p_rscp_result = (URfTestResultRSCP*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                p_rscp_result->ok = ptrMsgbody->param.rscp.ok;
                p_rscp_result->num_cell = ptrMsgbody->param.rscp.num_cell;
                for(i=0 ; i < ptrMsgbody->param.rscp.num_cell ; i++)
                {
                    p_rscp_result->cpich_result[i].psc = ptrMsgbody->param.rscp.cpich_result[i].psc;
                    p_rscp_result->cpich_result[i].tm = ptrMsgbody->param.rscp.cpich_result[i].tm;
                    p_rscp_result->cpich_result[i].off = ptrMsgbody->param.rscp.cpich_result[i].off;
                    p_rscp_result->cpich_result[i].sttd = ptrMsgbody->param.rscp.cpich_result[i].sttd;
                    p_rscp_result->cpich_result[i].sample_num = ptrMsgbody->param.rscp.cpich_result[i].sample_num;
                    p_rscp_result->cpich_result[i].rscp_sum = ptrMsgbody->param.rscp.cpich_result[i].rscp_sum;
                    p_rscp_result->cpich_result[i].freq_error = ptrMsgbody->param.rscp.cpich_result[i].freq_error; // for anthony 0514
                }
                // assign peer buffer
                peer_buff_ret->pdu_len = sizeof(URfTestResultRSCP);
                ilm_ptr.peer_buff_ptr = peer_buff_ret;
            }
            break;
        }
        case UL1TST_CMD_AFC:
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case UL1TST_CMD_AFC_EXT:
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            if(ptrMsgbody->type == UL1TST_CMD_AFC)
            {
                ptrMsg->type = URF_TEST_CMD_AFC;
                ptrMsg->param.afc.freq_error = ptrMsgbody->param.afc.freq_error;
            }
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
            else if(ptrMsgbody->type == UL1TST_CMD_AFC_EXT)
            {
                ptrMsg->type = URF_TEST_CMD_AFC_EX;
                ptrMsg->param.afc_ex.freq_error = ptrMsgbody->param.afc_ext.freq_error;
            }
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
            ptrMsg->param.afc.ok = ptrMsgbody->param.afc.ok;
            ptrMsg->param.afc.psc = ptrMsgbody->param.afc.psc;
            ptrMsg->param.afc.tm = ptrMsgbody->param.afc.tm;
            ptrMsg->param.afc.sttd = ptrMsgbody->param.afc.sttd;
            ptrMsg->param.afc.rscp_sum = ptrMsgbody->param.afc.rscp_sum;
            break;
        }
        case UL1TST_CMD_MQC:  //UL1D_RF_FHC_CNF_T *g_pFtWcdmaFHCRes = NULL;
        {
            UL1D_RF_FHC_CNF_T  *pFhcCnf = NULL;
            peer_buff_struct *peer_buff_ret = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            if(g_bFtWcdmaFhcWaiting) // return the confirm to PC side
            {
                FT_ALLOC_MSG(&ilm_ptr, sizeof(ft_urf_test_cnf_T) );
                ptrMsg = (ft_urf_test_cnf_T*)ilm_ptr.local_para_ptr;
                ptrMsg->header.ft_msg_id = FT_URF_TEST_CNF_ID;
                ptrMsg->type = URF_TEST_CMD_START_FHC;
                ptrMsg->param.ok = KAL_TRUE;
                // send the confirm by peer buffer
                if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(UL1D_RF_FHC_CNF_T), 0, 0, TD_CTRL)) )
                {
                    pFhcCnf = (UL1D_RF_FHC_CNF_T*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );
                    // assign peer buffer
                    peer_buff_ret->pdu_len = sizeof(UL1D_RF_FHC_CNF_T);
                    ilm_ptr.peer_buff_ptr = peer_buff_ret;
                }
            }
            else  // triggered by URF_TEST_CMD_START_FHC_NO_WAIT
            {
                // store the result in local control buffer
                if(g_pFtWcdmaFHCRes == NULL)
                    g_pFtWcdmaFHCRes = (UL1D_RF_FHC_CNF_T *)get_ctrl_buffer(sizeof(UL1D_RF_FHC_CNF_T));
                pFhcCnf = g_pFtWcdmaFHCRes;
            }
            if(pFhcCnf != NULL)
            {
                pFhcCnf->ok = ptrMsgbody->param.mqc.ok;
                pFhcCnf->freq_count = ptrMsgbody->param.mqc.freq_count;
                pFhcCnf->pwr_count = ptrMsgbody->param.mqc.pwr_count;
                pFhcCnf->freq_start_idx = ptrMsgbody->param.mqc.freq_start_idx;
                pFhcCnf->pwr_start_idx = ptrMsgbody->param.mqc.pwr_start_idx;
                kal_mem_cpy(pFhcCnf->rssi,ptrMsgbody->param.mqc.rssi, sizeof(kal_int16)*400);
                kal_mem_cpy(pFhcCnf->pwr_det_value,ptrMsgbody->param.mqc.pwr_det_value, sizeof(kal_uint16)*40);
            }
            if(!g_bFtWcdmaFhcWaiting)
            {
                g_bFtWcdmaFhcResultReady = true;
                return;  // must return here, because don't send the confirm to PC side here
            }
            break;
        }
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case UL1TST_CMD_MQC_OCTLEV:
        case UL1TST_CMD_MQC_EXT:
        {
            ul1tst_cmd_mqc_octlev_handler((ul1tst_ft_cnf_T*)ptrMsg_ul1tst->local_para_ptr);
            return;
        }
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
        case UL1TST_CMD_NSFT:
#if defined (__HSDPA_SUPPORT__)
        case UL1TST_CMD_HSDPA_NSFT:
#endif // #if defined (__HSDPA_SUPPORT__)
#if defined (__HSUPA_SUPPORT__)
        case UL1TST_CMD_HSUPA_NSFT:
#endif // #if defined (__HSUPA_SUPPORT__)
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            if(ptrMsgbody->type == UL1TST_CMD_NSFT)
            {
                ptrMsg->type = URF_TEST_CMD_START_NSFT_EX;
            }
#if defined (__HSDPA_SUPPORT__)
            else if(ptrMsgbody->type == UL1TST_CMD_HSDPA_NSFT)
            {
                ptrMsg->type = URF_TEST_CMD_START_HSDPA_NSFT;
            }
#endif // #if defined (__HSDPA_SUPPORT__)
#if defined (__HSUPA_SUPPORT__)
            else if(ptrMsgbody->type == UL1TST_CMD_HSUPA_NSFT)
            {
                ptrMsg->type = URF_TEST_CMD_START_HSUPA_NSFT;
            }
#endif // #if defined (__HSUPA_SUPPORT__)
            ptrMsg->param.m_rNSFTLinkStatusReport.ok = ptrMsgbody->param.nsft.ok;
            ptrMsg->param.m_rNSFTLinkStatusReport.link_status = ptrMsgbody->param.nsft.link_status;
            // 20100219
            if(!g_bFtWcdmaNsftWaiting)
            {
                // not wait for the DCH-sync status just discard the report
                return;
            }
            break;
        }
#if defined (__UL1_HS_PLUS_PLATFORM__)
        case UL1TST_CMD_GET_RF_TEMP:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_GET_RF_TEMP_BSI;
            ptrMsg->param.rfTemperature.ok = ptrMsgbody->param.rfTemperature.ok;
            ptrMsg->param.rfTemperature.sum = ptrMsgbody->param.rfTemperature.sum;
            break;
        }
        case UL1TST_CMD_GET_RF_CAPABILITY:
        {
            void* src = NULL;
            void* dst = NULL;
            peer_buff_struct* cnf_peer_buf = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            /* local parameter */
            ptrMsg->type = URF_TEST_CMD_GET_RF_CAPABILITY;
            ptrMsg->param.ok = ptrMsgbody->param.ok;
            src = get_peer_buff_pdu( ptrMsg_ul1tst->peer_buff_ptr, &pdu_length );
            /* peer buffer: directly copy the peer buffer from UL1 TST */
            if( NULL != (cnf_peer_buf=construct_peer_buff(pdu_length, 0, 0, TD_RESET)) )
            {
                dst = get_peer_buff_pdu( cnf_peer_buf, &pdu_length );
                kal_mem_cpy(dst, src, pdu_length);
                ilm_ptr.peer_buff_ptr = cnf_peer_buf;
            }
            break;
        }
#endif // #if defined (__UL1_HS_PLUS_PLATFORM__)
        case UL1TST_CMD_LIST_MODE:
        {
            void* src = NULL;
            void* dst = NULL;
            peer_buff_struct* cnf_peer_buf = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            /* local parameter */
            ptrMsg->param.ok = ptrMsgbody->param.ok;
            ptrMsg->type = URF_TEST_CMD_START_NSFT_LIST_MODE;
            src = get_peer_buff_pdu( ptrMsg_ul1tst->peer_buff_ptr, &pdu_length );
            /* peer buffer: directly copy the peer buffer from UL1 TST */
            if( NULL != (cnf_peer_buf=construct_peer_buff(pdu_length, 0, 0, TD_RESET)) )
            {
                dst = get_peer_buff_pdu( cnf_peer_buf, &pdu_length );
                kal_mem_cpy(dst, src, pdu_length);
                ilm_ptr.peer_buff_ptr = cnf_peer_buf;
            }
            break;
        }
        case UL1TST_CMD_SET_RF_MIPI_CODEWORD:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_SET_RF_MIPI_CODEWORD;
            ptrMsg->param.ok = ptrMsgbody->param.mipiPaSetCwData.ok;
            break;
        }
        case UL1TST_CMD_GET_RF_MIPI_CODEWORD:
        {
            void* src = NULL;
            void* dst = NULL;
            peer_buff_struct* cnf_peer_buf = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            /* local parameter */        
            ptrMsg->type = URF_TEST_CMD_GET_RF_MIPI_CODEWORD;        
            ptrMsg->param.get_mipi_cw_param.status = ptrMsgbody->param.mipiPaGetCwData.status;
            ptrMsg->param.get_mipi_cw_param.power_level_num = ptrMsgbody->param.mipiPaGetCwData.power_level_num;
            ptrMsg->param.get_mipi_cw_param.code_word_num = ptrMsgbody->param.mipiPaGetCwData.code_word_num;
            src = get_peer_buff_pdu( ptrMsg_ul1tst->peer_buff_ptr, &pdu_length );
            /* peer buffer: directly copy the peer buffer from UL1 TST */
            if( NULL != (cnf_peer_buf=construct_peer_buff(pdu_length, 0, 0, TD_RESET)) )
            {
                dst = get_peer_buff_pdu( cnf_peer_buf, &pdu_length );
                kal_mem_cpy(dst, src, pdu_length);
                ilm_ptr.peer_buff_ptr = cnf_peer_buf;
            }
            break;
        }
        case UL1TST_CMD_GET_RF_TEMP_INFO:
        {
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);        
            ptrMsg->type = URF_TEST_CMD_GET_TEMPERATURE_INFO;
            ptrMsg->param.rfTemperatureInfo.status = ptrMsgbody->param.temperature_info.status;
            ptrMsg->param.rfTemperatureInfo.tadc_dac = ptrMsgbody->param.temperature_info.tadc_dac;
            ptrMsg->param.rfTemperatureInfo.temperature = ptrMsgbody->param.temperature_info.temperature;
            ptrMsg->param.rfTemperatureInfo.temp_idx = ptrMsgbody->param.temperature_info.temp_idx;                
            break;    
        }        
        case UL1TST_CMD_RX_GAIN_SWEEP:
        {
            URfTestResultRxGainSweep  *p_RxGainSweep_result;
            peer_buff_struct *peer_buff_ret = NULL;
            _ft_ul1tst_allocate_cnf_msg(&ilm_ptr, &ptrMsg);
            ptrMsg->type = URF_TEST_CMD_RX_GAIN_SWEEP;//ptrMsgbody->type;
            // send the confirm by peer buffer
            if( NULL != (peer_buff_ret=construct_peer_buff(sizeof(URfTestResultRxGainSweep), 0, 0, TD_CTRL)) )
            {
                p_RxGainSweep_result = (URfTestResultRxGainSweep*)get_peer_buff_pdu( peer_buff_ret, &pdu_length );             
                p_RxGainSweep_result->ok = ptrMsgbody->param.inband_pow.ok;// = true;
                p_RxGainSweep_result->num_freq=ptrMsgbody->param.inband_pow.num_freq ;
                for( i = 0 ; i < ptrMsgbody->param.inband_pow.num_freq ; i++ )
                {
                    p_RxGainSweep_result->dl_freq[i]=ptrMsgbody->param.inband_pow.dl_freq[i];
                    p_RxGainSweep_result->inband_pow[i]=ptrMsgbody->param.inband_pow.inband_pow[i] ;
                }
                peer_buff_ret->pdu_len = sizeof(URfTestResultRxGainSweep);
                // assign peer buffer
                ilm_ptr.peer_buff_ptr = peer_buff_ret;
            }
            break;
        }
        default:
            return;
    }
    // send confirm to PC
    FT_SEND_MSG_TO_PC(&ilm_ptr);
}
kal_uint32 FT_UL1RfCheckFunctionSuppported(kal_uint32 query_op_code)
{
    kal_uint32 cnf_code;
    if( URF_TEST_CMD_END > query_op_code )
    {
        switch(query_op_code)
        {
            case URF_TEST_CMD_SET_PA_OCT_LEVEL_DATA:
            case URF_TEST_CMD_START_FHC_EX:
            case URF_TEST_CMD_GET_FHC_EX_RESULT:
            case URF_TEST_CMD_GET_CURRENT_RXD_LNA_MODE: /**< \brief R8 get Rx diversity path LNA mode */
            {
                UMTS_MsCapabilityEx ms_cap;
                UL1TST_MsCapability(&ms_cap);
                // 0x40 => UmtsFddRxDiversitySupport, the bit map should not change
                cnf_code = (ms_cap.capability & 0x40)? FT_CNF_OK : FT_CNF_FAIL;
                break;
            }
            case URF_TEST_CMD_GET_CURRENT_LNA_MODE:
            case URF_TEST_CMD_AFC_EX:
            case URF_TEST_CMD_SET_CAPID:
            case URF_TEST_CMD_GET_MAX_CAPID:
            {
#if !defined (__UL1_HS_PLATFORM__) && !defined (__UL1_HS_PLUS_PLATFORM__)
                cnf_code = FT_CNF_FAIL;
#else // #if !defined (__UL1_HS_PLATFORM__) && !defined (__UL1_HS_PLUS_PLATFORM__)
                cnf_code = FT_CNF_OK;
#endif
                break;
            }
            case URF_TEST_CMD_START_HSDPA_NSFT:
            {
#if !defined (__HSDPA_SUPPORT__)
                cnf_code = FT_CNF_FAIL;
#else // #if !defined (__HSDPA_SUPPORT__)
                cnf_code = FT_CNF_OK;
#endif
                break;
            }
            case URF_TEST_CMD_START_HSUPA_NSFT:
            {
#if !defined (__HSUPA_SUPPORT__)
                cnf_code = FT_CNF_FAIL;
#else // #if !defined (__HSUPA_SUPPORT__)
                cnf_code = FT_CNF_OK;
#endif
                break;
            }
            default:
            {
                cnf_code = FT_CNF_OK;
                break;
            }
        }
    }
    else
    {
        cnf_code = FT_CNF_FAIL;
    }
    return cnf_code;
}

void FT_UL1TST_UpdateRuntimeReq(kal_uint32 lid )
{
    if(UL1_IS_3G_FDD_EXIST())  //for 3G disable feature
    {
         // retrieved events
         kal_uint32 retrieved_events = 0;

         // allocate message to send to ul1tst;
         ft_ul1tst_req_T   *ptrMsg_ul1tst;
         ilm_struct         ilm_ptr_ul1tst;
         
         FT_ALLOC_MSG(&ilm_ptr_ul1tst, sizeof( ft_ul1tst_req_T ) );
         ptrMsg_ul1tst  = ( ft_ul1tst_req_T* )ilm_ptr_ul1tst.local_para_ptr;
         ptrMsg_ul1tst->type = UL1TST_CMD_Reload_NVRAM;
         ptrMsg_ul1tst->param.reload.lid = lid;
         ptrMsg_ul1tst->param.reload.eg_ptr = ft_event_group_ptr;
         /* TODO: gotta make sure UL1TST will free the space just allocated */
         // send 3G wcdma runtime update request
         FT_SEND_MSG( MOD_FT, MOD_UL1TST, FT_UL1TST_SAP, MSG_ID_FT_TO_UL1TST, &ilm_ptr_ul1tst ); 

         // wait until UL1 update run-time value finish or timeout
         while( KAL_SUCCESS == kal_retrieve_eg_events_timeout( (kal_eventgrpid) ft_event_group_ptr, 
                                         (kal_uint32)FT_UL1_UPDATE_RUNTIME_EVENT, 
                                         KAL_OR_CONSUME, &retrieved_events, FT_EVENT_TIMEOUT) )
         {
            if( retrieved_events & FT_UL1_UPDATE_RUNTIME_EVENT ) break;
         }
    }
}

#endif  // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
