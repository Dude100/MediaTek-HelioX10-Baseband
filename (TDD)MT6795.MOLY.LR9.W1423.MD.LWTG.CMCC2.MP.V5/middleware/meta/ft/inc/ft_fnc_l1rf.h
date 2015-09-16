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
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_fnc_l1rf.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   FT private API definition (Category: L1RF)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_FNC_L1RF_H__
#define __FT_FNC_L1RF_H__
#include "ft_msg.h"
#include "l1_types_public.h"
#include "kal_public_defs.h"
#include "l1cal.h"
/* RF Report */
void FT_DispatchReports( Report_FT *report );
void FT_ReportPowerScanDone    (PM_TST_Data                 *pm_tst);
void FT_ReportFCB              (SChData                     *sch);
/************************
 * L1 CID (titly bonded)
 ***********************/
#if  MD_DRV_IS_FHC_SUPPORT == 1
void FT_ReportDTS(ResultDTS *dtsResult);
void FT_ReportDTS_Ex(ResultDTS *dtsResult);
void FT_ReportUTS(void);
#endif //#if  MD_DRV_IS_FHC_SUPPORT == 1
#if  MD_DRV_IS_NSFT_SUPPORT == 1
void FT_ReportNSFT(SChData *nsftResult);
#endif // #if  MD_DRV_IS_NSFT_SUPPORT == 1

/* RF testing */
void FT_L1RfDataInit(void);
void FT_FtRfTestReq            (ft_rf_test_req_T  *req, peer_buff_struct *p_peer_buff_ptr);
void Meta_32KCalibrationHandler(kal_int32 result);
void FT_Send32KCalibraResultBack(void);
kal_uint32 FT_L1RfCheckFunctionSuppported(kal_uint32 query_op_code);
/*******************************
 * FT set L1 runtime APIs
 ******************************/
void setPathLossTableToL1D(peer_buff_struct* peer_buff_ptr,l1cal_agcPathLoss_T *l1cal_agcPathLoss_ft);
void setRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr,l1cal_rampTable_T *l1cal_rampTable_ft);
void setAFcDataToL1C(peer_buff_struct* peer_buff_ptr,l1cal_afcData_T *l1cal_afcData_ft);
void TOL1_CALTXIQ(peer_buff_struct* peer_buff_ptr,l1cal_txiq_T *l1cal_txiq_ft);
int setInterRampTableToL1D(FrequencyBand  band, peer_buff_struct  *peer_buff_ptr, l1cal_interRampData_T  *inter_ramp_data);
int setCrystalAfcDataToL1D(peer_buff_struct  *peer_buff_ptr, l1cal_crystalAfcData_T  *crystalAfcData);
int setCrystalCapDataToL1D(peer_buff_struct  *peer_buff_ptr, l1cal_crystalCapData_T  *crystalCapData);
#if MD_DRV_IS_EPSK_TX_SUPPORT == 1
void setEPSKRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr,l1cal_rampTable_T *l1cal_rampTable_ft);
void setEPSKInterRampTableToL1D(FrequencyBand band, peer_buff_struct* peer_buff_ptr, l1cal_EPSK_interRampData_T *l1cal_inter_rampTable_ft);
#endif // #if MD_DRV_IS_EPSK_TX_SUPPORT == 1
void setEPSKTXRollbackTableToL1D(peer_buff_struct* peer_buff_ptr, l1cal_tx_power_rollback_T *tx_rollback_epsk);
void setGMSKTXRollbackTableToL1D(peer_buff_struct* peer_buff_ptr, l1cal_tx_power_rollback_T *tx_rollback_epsk);
void setRFSpecialCoefToL1D(peer_buff_struct* peer_buff_ptr, l1cal_rfspecialcoef_T *l1cal_rfspecialcoef_ft);
void setTXPCToL1D(peer_buff_struct* peer_buff_ptr, l1cal_txpc_T *txpc_table_input, kal_bool b_epsk);
void setLnaPathLossToL1D(peer_buff_struct* peer_buff_ptr, void *input);
void setTemperatureADCToL1D(peer_buff_struct* peer_buff_ptr, void *temperature_adc_input);

#endif // #ifndef __FT_FNC_L1RF_H__

