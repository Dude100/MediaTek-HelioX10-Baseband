/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_wcdma.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  WCDMA Function header
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
#ifndef _FT_FNC_WCDMA_H_
#define _FT_FNC_WCDMA_H_
#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)

#include "ft_msg.h"
#include "ul1cal.h"
//20130206
/*************************************************************************
 * Include Statements for MAUI
 *************************************************************************/ 
#include "hal_ul1_struct.h"
kal_uint32 FT_UL1RfCheckFunctionSuppported(kal_uint32 query_op_code);
void FT_FtURfTestReq( ft_urf_test_req_T  *req, peer_buff_struct *p_peer_buff_ptr );
void FT_UL1TST_SEND_CNF_BACK(ilm_struct *ptrMsg_ul1tst);

// ul1/ul1tst/ul1tst_cfg.c
// extern void UL1TST_Init(void);
// extern declaration for API located in u1l/u1ld/wrgeneral.c
extern kal_uint8 UL1D_RF_Get_pwr_dt_step(void);
extern kal_uint16 UL1D_RF_Get_pwr_dt_dac(void);
extern kal_uint8 UL1D_RF_Get_pwr_dt_default_thr( kal_uint8 rf_band );
/*******************************
 * FT set UL1 runtime APIs
 ******************************/
void setTempDacToL1D( peer_buff_struct* peer_buff_ptr, ul1cal_tempdacData_T *ul1cal_tempdacData_ft );
void setPathLossToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_pathlossData_T *ul1cal_pathlossData_ft);
void setTxDacToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_txdacData_T *ul1cal_txdacData_ft);
#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__) 
void setPaOctLevDataToL1D(kal_uint8 rf_band, peer_buff_struct* peer_buff_ptr, ul1cal_txPaOctLevData_T *ul1cal_txPaOctLevData_ft);
#endif // #if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)

void FT_UL1TST_UpdateRuntimeReq( kal_uint32 lid );

#endif // #if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#endif // #ifndef _FT_FNC_WCDMA_H_
