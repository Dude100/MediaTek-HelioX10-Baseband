/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   emi.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the functionality of Code and Data cache.
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

/********************************************************************************************
 * README
 * Test platform after revision
 * [1] NOR Flash boot without remap , MT6229_EVB
 * [2] NAND Flash boot , MT6228_EVB
 * [3] NOR Flash boot with remap , MT6225 + Single Bank NOR Flash , for example CRYSTAL25 V3 SB
 ********************************************************************************************/


/*******************************************************************************
 * Include header files.
 *******************************************************************************/
#include "reg_base.h"
#include "emi_hw.h"
#include "emi_sw.h"
#include "cp15.h"
#include "init.h"
#include "intrCtrl.h"
#include "custom_EMI_release.h"

#include "drv_comm.h"
#include "dramc_hw.h"
#include "emi_trace.h"
#include "mcu_pmu_montr.h"
#include "ebm_if.h"
#include "elm.h"

#ifdef __MTK_TARGET__

/*******************************************************************************
  *
  * Define import global data.
  *
  *******************************************************************************/
#define	EMI_TTYPE_PROFILING			1
#define EMI_LATENCY_PROFILING		0
#define IDLE_TIME_PROFILING			0
// us * 1000 / (1000 / 26MHz)
#define ELM_HW_PERIOD_US(us)			((us) * 26)

/*******************************************************************************
  * 
  * Define global data.
  *
  *******************************************************************************/

/*******************************************************************************
  * 
  * Declare Internal function
  *
  *******************************************************************************/


/*************************************************************************
* FUNCTION
*
*  EMI_profiling_init
*
* DESCRIPTION
*  initialize EMI profiling
*
* PARAMETERS
*  VOID
*
* RETURNS
*  0 means successful
*
*************************************************************************/
#if !defined (ATEST_DRV_ENABLE)
static kal_uint32 ebm_rw = EBM_READ_ONLY;
#endif
#if (IDLE_TIME_PROFILING)
extern kal_uint32 pre_idle_in_dsp_period;
#endif
/* ==================== */
/*	EXPORTED FUNCTIONS	*/
/* ==================== */
#if !defined (ATEST_DRV_ENABLE)
kal_int32 emi_profiling_init() {
#else
kal_int32 emi_profiling_init(kal_uint32 ebm_rw) {
#endif
#if (EMI_TTYPE_PROFILING)
	ELM_SET_MODE(ELM_HW_MODE);
	ELM_SET_HW_PERIOD(ELM_HW_PERIOD_US(250));

	EBM_SET_FUNC(EBM_FUNC_NORMAL);

	if (EBM_READ_ONLY == ebm_rw) {
		EBM_SET_RW_REQ(EBM_READ_ONLY);
		// TTYPE common part
		EBM_MSEL_SET(0, EMI_LYRBMP_MDMCU, WR4_8B, 0);
		EBM_MSEL_SET(1, EMI_LYRBMP_MDPERI, INC1_8B, 0);
		EBM_MSEL_SET(2, EMI_LYRBMP_MODEM, INC1_4B, 0);
		EBM_MSEL_SET(3, EMI_LYRBMP_HARQ, INC16_8B, 0);

		// M0
		EBM_MSEL_SET(4, EMI_LYRBMP_MDMCU, INC1_1B, 0);
		EBM_MSEL_SET(5, EMI_LYRBMP_MDMCU, INC1_2B, 0);
		EBM_MSEL_SET(6, EMI_LYRBMP_MDMCU, INC1_4B, 0);

		// M1
		EBM_MSEL_SET(7, EMI_LYRBMP_MDPERI, INC2_8B, 0);
		EBM_MSEL_SET(8, EMI_LYRBMP_MDPERI, INC3_8B, 0);
		EBM_MSEL_SET(9, EMI_LYRBMP_MDPERI, INC4_8B, 0);
		EBM_MSEL_SET(10, EMI_LYRBMP_MDPERI, INC5_8B, 0);
		EBM_MSEL_SET(11, EMI_LYRBMP_MDPERI, INC6_8B, 0);
		EBM_MSEL_SET(12, EMI_LYRBMP_MDPERI, INC7_8B, 0);
		EBM_MSEL_SET(13, EMI_LYRBMP_MDPERI, INC8_8B, 0);

		// M4
		EBM_MSEL_SET(14, EMI_LYRBMP_MODEM, INC4_4B, 0);
		EBM_MSEL_SET(15, EMI_LYRBMP_MODEM, INC8_4B, 0);
		EBM_MSEL_SET(16, EMI_LYRBMP_MODEM, INC16_4B, 0);
		EBM_MSEL_SET(17, EMI_LYRBMP_MODEM, INC2_8B, 0);
		EBM_MSEL_SET(18, EMI_LYRBMP_MODEM, INC4_8B, 0);
		EBM_MSEL_SET(19, EMI_LYRBMP_MODEM, INC8_8B, 0);

		// M5
	}
	else {
		EBM_SET_RW_REQ(EBM_WRITE_ONLY);
		// TTYPE common part
		EBM_MSEL_SET(0, EMI_LYRBMP_MDMCU, INC1_8B, 0);
		EBM_MSEL_SET(1, EMI_LYRBMP_MDPERI, INC1_8B, 0);
		EBM_MSEL_SET(2, EMI_LYRBMP_MODEM, INC1_1B, 0);
		EBM_MSEL_SET(3, EMI_LYRBMP_HARQ, INC4_8B, 0);

		// M0
		EBM_MSEL_SET(4, EMI_LYRBMP_MDMCU, INC2_8B, 0);
		EBM_MSEL_SET(5, EMI_LYRBMP_MDMCU, INC3_8B, 0);
		EBM_MSEL_SET(6, EMI_LYRBMP_MDMCU, INC4_8B, 0);

		// M1
		EBM_MSEL_SET(7, EMI_LYRBMP_MDPERI, INC4_8B, 0);
		EBM_MSEL_SET(8, EMI_LYRBMP_MDPERI, INC5_8B, 0);
		EBM_MSEL_SET(9, EMI_LYRBMP_MDPERI, INC8_8B, 0);

		// M4
		EBM_MSEL_SET(10, EMI_LYRBMP_MODEM, INC1_2B, 0);
		EBM_MSEL_SET(11, EMI_LYRBMP_MODEM, INC1_4B, 0);
		EBM_MSEL_SET(12, EMI_LYRBMP_MODEM, INC4_4B, 0);
		EBM_MSEL_SET(13, EMI_LYRBMP_MODEM, INC8_4B, 0);
		EBM_MSEL_SET(14, EMI_LYRBMP_MODEM, INC16_4B, 0);
		EBM_MSEL_SET(15, EMI_LYRBMP_MODEM, INC2_8B, 0);
		EBM_MSEL_SET(16, EMI_LYRBMP_MODEM, INC4_8B, 0);
		EBM_MSEL_SET(17, EMI_LYRBMP_MODEM, INC8_8B, 0);

		// M5
		EBM_MSEL_SET(18, EMI_LYRBMP_HARQ, INC16_8B, 0);
	}
#elif (EMI_LATENCY_PROFILING)
	// ELM Configuration
	ELM_SET_MODE(ELM_HW_MODE);
	ELM_SET_HW_PERIOD(ELM_HW_PERIOD_US(250));

	EBM_SET_FUNC(EBM_FUNC_LATENCY);
	EBM_SET_RW_REQ(ebm_rw);

	EBM_MSEL_SET(0, EMI_LYRBMP_MDMCU, INC4_8B, 0);
	EBM_MSEL_SET(1, EMI_LYRBMP_MDPERI, INC8_8B, 0);
	EBM_MSEL_SET(2, EMI_LYRBMP_MODEM, INC8_8B, 0);
	EBM_MSEL_SET(3, EMI_LYRBMP_HARQ, INC16_8B, 0);
#endif

#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	// Limit BWL for All Lyrs
	UNLOCK_EMI_REG();

	// BWL Filter Window & Overhead
	// 0: 256, 1: 512, 2: 1024, 3:2048
	DRV_WriteReg32(EMI_TESTD, DRV_Reg32(EMI_TESTD) & 0xFFFFFCFF);
	DRV_WriteReg32(EMI_TESTD, DRV_Reg32(EMI_TESTD) | 0x00000000);

	// Set Overhead value according to pre-calculation (depend on BWL window)
	DRV_WriteReg32(EMI_CONB, 0x42656FAD);
	DRV_WriteReg32(EMI_CONC, 0x313E3857);
	DRV_WriteReg32(EMI_COND, 0x42656FAD);
	DRV_WriteReg32(EMI_CONE, 0x313E3857);

	// BWL Settings per Layer
	//DRV_WriteReg32(EMI_ARBA, 0x00005829);
	//DRV_WriteReg32(EMI_ARBB, 0x00005820);
	//DRV_WriteReg32(EMI_ARBC, 0x00005820);
	//DRV_WriteReg32(EMI_ARBD, 0x00005820);
	//DRV_WriteReg32(EMI_ARBE, 0x00005808);
	//DRV_WriteReg32(EMI_ARBF, 0x00005820);

	LOCK_EMI_REG();

	// Set PMU
	MCU_PMU_SetEvent(PMU_EVENT_COUNTER_1, PMU_EVENT_ICACHE_ACCESS);
	MCU_PMU_SetEvent(PMU_EVENT_COUNTER_2, PMU_EVENT_DCACHE_ACCESS);
	MCU_PMU_SetEvent(PMU_EVENT_COUNTER_3, PMU_EVENT_DCACHE_MISS);

	// Reset PMU counters
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_1);
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_2);
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_3);
#endif

	return 0;
}

kal_int32 emi_profiling_start() {

#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	// ELM Counters
	ELM_START();

	// EBM Counters
	EBM_START();

	// DRAMC
	DRV_WriteReg32(BASE_ADDR_DRAMC + 0x01D8, DRV_Reg32(BASE_ADDR_DRAMC + 0x01D8) | 0x00000008);

	// CR4 PMU
	MCU_PMU_StartCounter(PMU_EVENT_COUNTER_1);
	MCU_PMU_StartCounter(PMU_EVENT_COUNTER_2);
	MCU_PMU_StartCounter(PMU_EVENT_COUNTER_3);

	// PFB Counters
	DRV_WriteReg32_NPW(BASE_ADDR_MDMCUMISC + 0x0C, DRV_Reg32(BASE_ADDR_MDMCUMISC + 0x0C) | 0x00000002);
#endif

	return 0;
}

kal_int32 emi_profiling_pause() {

#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	// ELM Counter
	ELM_PAUSE();

	// EBM Counters
	EBM_PAUSE();

	// DRAMC
	DRV_WriteReg32(BASE_ADDR_DRAMC + 0x01D8, DRV_Reg32(BASE_ADDR_DRAMC + 0x01D8) | 0x00000004);

	// CR4 PMU
	MCU_PMU_StopCounter(PMU_EVENT_COUNTER_1);
	MCU_PMU_StopCounter(PMU_EVENT_COUNTER_2);
	MCU_PMU_StopCounter(PMU_EVENT_COUNTER_3);

	// PFB counter has no pause support
#endif
	return 0;
}

kal_int32 emi_profiling_clear() {

#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	// ELM Counter
	ELM_CLR();

	// EBM Counters
	EBM_CLR();

	// DRAMC
	DRV_WriteReg32(BASE_ADDR_DRAMC + 0x01D8, DRV_Reg32(BASE_ADDR_DRAMC + 0x01D8) & 0xFFFFFFF3);

	// CR4 PMU
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_1);
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_2);
	MCU_PMU_ResetCounter(PMU_EVENT_COUNTER_3);

	// PFB Counters
	DRV_WriteReg32_NPW(BASE_ADDR_MDMCUMISC + 0x0C, DRV_Reg32(BASE_ADDR_MDMCUMISC + 0x0C) & 0xFFFFFFFD);
#endif

	return 0;
}

kal_int32 emi_profiling_dump() {
#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	kal_uint32 idx = 0;
	kal_uint32 wr_accu_lat[4];
	kal_uint32 wr_accu_trans[4];
	kal_uint32 rd_accu_lat[4];
	kal_uint32 rd_accu_trans[4];
	kal_uint32 cm_total_cnt = DRV_Reg32(BASE_ADDR_MDMCUMISC + 0x14);
	kal_uint32 pf_total_cnt = DRV_Reg32(BASE_ADDR_MDMCUMISC + 0x18);
	kal_uint32 pf_hit_cnt = DRV_Reg32(BASE_ADDR_MDMCUMISC + 0x1C);

	ebm_cnt_t ebm_cnts;

	// 0: page hit, 1: page miss, 2: interbank
	kal_uint32 rr_cnt[3];
	kal_uint32 rw_cnt[3];
	kal_uint32 wr_cnt[3];
	kal_uint32 ww_cnt[3];

	kal_uint32 dramc_idle_cnt = DRV_Reg32(BASE_ADDR_DRAMC + 0x02B0);
	kal_uint32 dramc_free_cnt = DRV_Reg32(BASE_ADDR_DRAMC + 0x02B4);	// Count in 26MHz
	kal_uint32 dramc_refresh_cnt = DRV_Reg32(BASE_ADDR_DRAMC + 0x02B8);

	for (idx = 0; idx < 4; idx++) {
		ELM_GET_CNT(ELM_RD, ELM_TYPE_TRANS, idx, &rd_accu_trans[idx]);
		ELM_GET_CNT(ELM_RD, ELM_TYPE_LATENCY, idx, &rd_accu_lat[idx]);
		ELM_GET_CNT(ELM_WR, ELM_TYPE_TRANS, idx, &wr_accu_trans[idx]);
		ELM_GET_CNT(ELM_WR, ELM_TYPE_LATENCY, idx, &wr_accu_lat[idx]);

		EMI_PROFILING_LOG(1, idx, rd_accu_lat[idx], rd_accu_trans[idx]);
		EMI_PROFILING_LOG(2, idx, wr_accu_lat[idx], wr_accu_trans[idx]);
	}

	for (idx = 0; idx < 3; idx++) {
		rr_cnt[idx] = DRV_Reg32(BASE_ADDR_DRAMC + 0x0280 + (idx << 2));
		rw_cnt[idx] = DRV_Reg32(BASE_ADDR_DRAMC + 0x028C + (idx << 2));
		wr_cnt[idx] = DRV_Reg32(BASE_ADDR_DRAMC + 0x0298 + (idx << 2));
		ww_cnt[idx] = DRV_Reg32(BASE_ADDR_DRAMC + 0x02A4 + (idx << 2));
	}

	EBM_GET_CNTS(&ebm_cnts);
#endif

#if (EMI_TTYPE_PROFILING)
	EMI_PROFILING_LOG(3, ebm_cnts.emi_bus_cyc, ebm_cnts.total_trans_cnt, ebm_cnts.total_dword_cnt);
	EMI_PROFILING_LOG(4, ebm_cnts.bw_ddword_cnt, ebm_cnts.overhead_dword_cnt, ebm_cnts.dword_cnt[0]);
	EMI_PROFILING_LOG(5, ebm_cnts.dword_cnt[1], ebm_cnts.dword_cnt[2], ebm_cnts.dword_cnt[3]);
	EMI_PROFILING_LOG(6, ebm_cnts.norm.trans_cnt[0], ebm_cnts.norm.trans_cnt[1], ebm_cnts.norm.trans_cnt[2]);
	EMI_PROFILING_LOG(7, ebm_cnts.norm.ttype_cnt[0], ebm_cnts.norm.ttype_cnt[1], ebm_cnts.norm.ttype_cnt[2]);
	EMI_PROFILING_LOG(8, ebm_cnts.norm.ttype_cnt[3], ebm_cnts.norm.ttype_cnt[4], ebm_cnts.norm.ttype_cnt[5]);
	EMI_PROFILING_LOG(9, ebm_cnts.norm.ttype_cnt[6], ebm_cnts.norm.ttype_cnt[7], ebm_cnts.norm.ttype_cnt[8]);
	EMI_PROFILING_LOG(10, ebm_cnts.norm.ttype_cnt[9], ebm_cnts.norm.ttype_cnt[10], ebm_cnts.norm.ttype_cnt[11]);
	EMI_PROFILING_LOG(11, ebm_cnts.norm.ttype_cnt[12], ebm_cnts.norm.ttype_cnt[13], ebm_cnts.norm.ttype_cnt[14]);
	EMI_PROFILING_LOG(12, ebm_cnts.norm.ttype_cnt[15], ebm_cnts.norm.ttype_cnt[16], ebm_cnts.norm.ttype_cnt[17]);
	EMI_PROFILING_LOG(13, ebm_cnts.norm.ttype_cnt[18], ebm_cnts.norm.ttype_cnt[19], ebm_cnts.norm.ttype_cnt[20]);
#elif (EMI_LATENCY_PROFILING)
	EMI_PROFILING_LOG(3, ebm_cnts.emi_bus_cyc, ebm_cnts.total_trans_cnt, ebm_cnts.total_dword_cnt);
	EMI_PROFILING_LOG(4, ebm_cnts.bw_ddword_cnt, ebm_cnts.overhead_dword_cnt, ebm_cnts.dword_cnt[0]);
	EMI_PROFILING_LOG(5, ebm_cnts.dword_cnt[1], ebm_cnts.dword_cnt[2], ebm_cnts.dword_cnt[3]);
	EMI_PROFILING_LOG(6, ebm_cnts.lat.max_m0_lat_cnt, ebm_cnts.lat.min_m0_lat_cnt, ebm_cnts.lat.accu_m0_lat_cnt);
	EMI_PROFILING_LOG(7, ebm_cnts.lat.accu_m0_trans_cnt, ebm_cnts.lat.max_m1_lat_cnt, ebm_cnts.lat.min_m1_lat_cnt);
	EMI_PROFILING_LOG(8, ebm_cnts.lat.accu_m1_lat_cnt, ebm_cnts.lat.accu_m1_trans_cnt, ebm_cnts.lat.max_m2_lat_cnt);
	EMI_PROFILING_LOG(9, ebm_cnts.lat.min_m2_lat_cnt, ebm_cnts.lat.accu_m2_lat_cnt, ebm_cnts.lat.accu_m2_trans_cnt);
	EMI_PROFILING_LOG(10, ebm_cnts.lat.max_m3_lat_cnt, ebm_cnts.lat.min_m3_lat_cnt, ebm_cnts.lat.accu_m3_lat_cnt);
	EMI_PROFILING_LOG(11, ebm_cnts.lat.accu_m3_trans_cnt, ebm_cnts.lat.max_m4_lat_cnt, ebm_cnts.lat.min_m4_lat_cnt);
	EMI_PROFILING_LOG(12, ebm_cnts.lat.accu_m4_lat_cnt, ebm_cnts.lat.accu_m4_trans_cnt, ebm_cnts.lat.max_m5_lat_cnt);
	EMI_PROFILING_LOG(13, ebm_cnts.lat.min_m5_lat_cnt, ebm_cnts.lat.accu_m5_lat_cnt, ebm_cnts.lat.accu_m5_trans_cnt);
#endif

#if (EMI_TTYPE_PROFILING) | (EMI_LATENCY_PROFILING)
	EMI_PROFILING_LOG(14, MCU_PMU_ReadCounter(PMU_EVENT_COUNTER_1), MCU_PMU_ReadCounter(PMU_EVENT_COUNTER_2), MCU_PMU_ReadCounter(PMU_EVENT_COUNTER_3));
	EMI_PROFILING_LOG(15, cm_total_cnt, pf_total_cnt, pf_hit_cnt);
	EMI_PROFILING_LOG(16, rr_cnt[0], rr_cnt[1], rr_cnt[2]);
	EMI_PROFILING_LOG(17, rw_cnt[0], rw_cnt[1], rw_cnt[2]);
	EMI_PROFILING_LOG(18, wr_cnt[0], wr_cnt[1], wr_cnt[2]);
	EMI_PROFILING_LOG(19, ww_cnt[0], ww_cnt[1], ww_cnt[2]);
	EMI_PROFILING_LOG(20, dramc_idle_cnt, dramc_free_cnt, dramc_refresh_cnt);
#endif
#if (IDLE_TIME_PROFILING)
	EMI_PROFILING_LOG(21, pre_idle_in_dsp_period, 0, 0);
#endif

	return 0;
}

kal_uint32 emi_get_dram_refresh_rate(void) {
#if defined(MT6290)
    kal_uint32 refresh_rate;
    refresh_rate = (DRV_Reg32(DRAMC_SPCMDRESP)>>8)&0x7;

    return refresh_rate;
#else
    return 0x7FFFFFFF;
#endif
}

kal_int16 emi_get_dram_temp(void) {
#if defined(MT6290)
    kal_uint32 refresh_rate;
    kal_int16 temp;

    refresh_rate = (DRV_Reg32(DRAMC_SPCMDRESP)>>8)&0x7;

    switch (refresh_rate) {
        case 0:
            temp = -25;
            break;
        case 1:
        case 2:
            temp = 0;
            break;
        case 3:
            temp = 55;
            break;
        case 5:
            temp = 90;
            break;
        case 6:
            temp = 100;
            break;
        case 7:
            temp = 105;
            break;
        default:
            temp = 0x7FFF;
    }

    return temp;
#else
    return 0x7FFF;
#endif
}

#endif /* __MTK_TARGET__ */


