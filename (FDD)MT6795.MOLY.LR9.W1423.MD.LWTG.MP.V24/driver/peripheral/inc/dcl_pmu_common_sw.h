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
 *    dcl_pmu_common_sw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU common function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMU_COMMON_SW_H__
#define __DCL_PMU_COMMON_SW_H__

#include "dcl.h"
#if defined(__MTK_TARGET__)
#include "intrCtrl.h"
#endif

#if !defined(__UBL__)
// PMIC DCL ACCESS Time Log Enable
#define DCL_PMIC_ACCESS_TIME_LOG
#endif

#ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr, data)             DRV_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)               DRV_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)              DRV_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)                     DRV_Reg(addr)
#define PMU_DRV_ReadReg32(addr)                     DRV_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)     DRV_SetData(addr, bitmask, value)
#else // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr,data)              DRV_DBG_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)               DRV_DBG_SetBits(addr, data)
#define PMU_DRV_WriteReg16(addr, data)              DRV_DBG_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)                     DRV_DBG_Reg(addr)
#define PMU_DRV_ReadReg32(addr)                     DRV_DBG_Reg32(addr)
#define PMU_DRV_SetData16(addr, bitmask, value)     DRV_DBG_SetData(addr, bitmask, value)
#endif // #ifndef __DRV_DEBUG_PMU_REG_READ_WRITE__

#define PMU_SaveAndSetIRQMask()    SaveAndSetIRQMask()
#define PMU_RestoreIRQMask(n)      RestoreIRQMask(n)

#define M(mod) (((DCL_UINT64)1)<<mod)
#define NM(mod)  (~(((DCL_UINT64)1)<<mod))
#define ONSEL(modlist) (modlist)
#define OFFSEL(modlist) (~(modlist))


#define ISLDO(mod) ((M(mod)&LDO_GROUP)>0)

// module control
#define PMU_UNSUPPORT_MOD 0x00

// PARAMETER control
#define PARAMETERVAL_UNKNOWN 0xffffffff
#define PARAMETER_UNKNOWN 0xffff

#define ALLMOD	0xff
#define MODMASK ALLMOD
#define CMDMASK 0xffff00
#define ENC(cmd,mod) (((cmd<<8)+mod))
#define GETARRNUM(array) (sizeof(array)/sizeof(array[0]))
#define GENFUN(fun) fun,GETARRNUM(fun)

#define GETLDOIDX(mod) (pmuModtoIdx[mod])
#define GETBUCKIDX(mod) (pmuModtoIdx[mod])

#define PMU_SaveAndSetIRQMask()    SaveAndSetIRQMask()
#define PMU_RestoreIRQMask(n)      RestoreIRQMask(n)

typedef void    DCL_VOID;

typedef struct
{
	DCL_UINT32 cmd;
	const DCL_VOID *pVals;
	const DCL_VOID  *pRegVals;
	DCL_UINT8 size;
}PMU_PARAMETER_TABLE_ENTRY;

typedef struct
{
	DCL_UINT32 modidx;
	DCL_UINT32	addr;
	DCL_UINT32	usageBitMap;
}PMU_MOD_BASEADDR_ENTRY;


typedef struct
{
	DCL_UINT8 flagname;
	DCL_UINT8 offset;
	DCL_UINT16 mask;
	DCL_UINT8 shift;	
}PMU_FLAG_TABLE_ENTRY;

typedef struct
{
	DCL_UINT16 offset;
	DCL_UINT16 mask;
	DCL_UINT8 shift;	
}PMIC_FLAG_TABLE_ENTRY;

#if defined(__DRV_UPMU_BOOST_V1__)
typedef enum
{
	BOOST_TYPE_VOLTAGE_CONTROLLER = 0,
	BOOST_TYPE_CURRENT_CONVERTER
}upmu_boost_type_enum;

typedef enum
{
	BOOST_PWM_MODE = 0,
	BOOST_REGISTER_CTRL_MODE = 1
}upmu_boost_mode_enum;

typedef enum
{
	BOOST_OC_THD_4_DIVIDED_BY_8 = 0,
	BOOST_OC_THD_3_DIVIDED_BY_8 = 1,
	BOOST_OC_THD_2_DIVIDED_BY_8 = 2,
	BOOST_OC_THD_1_DIVIDED_BY_8 = 3
}upmu_boost_oc_thd_enum;

typedef enum
{
	BOOST_OC_WND_8_US = 0,
	BOOST_OC_WND_16_US = 1,
	BOOST_OC_WND_32_US = 2,
	BOOST_OC_WND_64_US = 3
}upmu_boost_oc_wnd_enum;

typedef enum
{
	BOOST_HW_SEL_ISINK = 0,
	BOOST_HW_SEL_BOOST
}upmu_boost_hw_sel_enum;


#endif // #if defined(__DRV_UPMU_BOOST_V1__)


#if defined(__DRV_UPMU_BC11_V1__)
typedef enum
{
	COMP_VTH_00_325000 = 0,
	COMP_VTH_01_200000 = 1
}PMU_CTRL_BC11_COMP_VTH_ENUM;

typedef enum
{
	COMP_DISABLE = 0,
	COMP_EN_ON_DM = 1,
	COMP_EN_ON_DP = 2
}PMU_CTRL_BC11_COMP_EN_ENUM;

typedef enum
{
	IPD_DISABLE = 0,
	IPD_EN_ON_DM = 1,
	IPD_EN_ON_DP = 2
}PMU_CTRL_BC11_IPD_EN_ENUM;

typedef enum
{
	VSRC_DISABLE = 0,
	VSRC_EN_ON_DM = 1,
	VSRC_EN_ON_DP = 2,
	VSRC_EN_ON_DPDM = 3
}PMU_CTRL_BC11_VSRC_EN_ENUM;


typedef enum
{
	IPU_DISABLE = 0,
	IPU_EN_ON_DM = 1,
	IPU_EN_ON_DP = 2
}PMU_CTRL_BC11_IPU_EN_ENUM;
#endif //#if defined(__DRV_UPMU_BC11_V1__)

typedef enum
{
	PMIC_ECO_E1 = 0,
	PMIC_ECO_E2,
	PMIC_ECO_E3,
	PMIC_ECO_E4,
	PMIC_ECO_E5,
	PMIC_ECO_E6,
	PMIC_ECO_E7,
	PMIC_ECO_E8,
	PMIC_ECO_E9,
	PMIC_ECO_E10,
}PMU_CTRL_PMIC_ECO_VERSION_ENUM;

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
#define MAX_PMIC_DURATION_INFO_SIZE				256
#define PMIC_ACCESS_DURATION_THRESHOLD			60

typedef struct
{
   DCL_UINT32 start_time;
   DCL_UINT32 end_time;
   DCL_UINT32 duration_time;
   DCL_UINT32 cmd;
   DCL_UINT32 pmu_time_start;
   DCL_UINT32 pmu_time_end;
   DCL_UINT32 pmu_time_duration;
   DCL_UINT32 pmu_time_qbit;
   DCL_UINT32 gpt3_time_start;
   DCL_UINT32 gpt3_time_end;   
   DCL_UINT32 gpt4_time_start;
   DCL_UINT32 gpt4_time_end;
   DCL_UINT32 ust_get_current_time_action1;
   DCL_UINT32 ust_get_current_time_action2;
   DCL_UINT32 ust_get_current_time_action3;
   DCL_UINT32 ust_get_current_time_action4;
   DCL_UINT32 ust_get_current_time_action5;   
   DCL_UINT32 drv_get_current_time_start;
   DCL_UINT32 drv_get_current_time_start1;
   DCL_UINT32 drv_get_current_time_start2;
   DCL_UINT32 drv_get_current_time_action1;
   DCL_UINT32 drv_get_current_time_action2;   
   DCL_UINT32 drv_get_current_time_action3;
   DCL_UINT32 drv_get_current_time_action4;
   DCL_UINT32 drv_get_current_time_action5;   
   DCL_UINT32 drv_get_current_time_end;   
   DCL_UINT32 drv_get_current_time_end1;   
   DCL_UINT32 drv_get_current_time_end2;      
}PMIC_ACCESS_DURATION_DBG;

typedef enum
{
	PMIC_DCL_DBG = 0,
	PMIC_INTERFACE_DBG = 1,
    PMIC_WRAPPER_WAIT_FOR_WACS_FSM_IDLE_DBG = 2,
    PMIC_WRAPPER_WAIT_FOR_WACS_FSM_WFVLDCLR_DBG = 3,
    PMIC_WRAPPER_READ_DBG = 4,
    PMIC_WRAPPER_INIT_DONE_DBG = 5,
    PMIC_WRAPPER_WACS0_WRITE0_DBG = 6,
    PMIC_WRAPPER_WACS0_WRITE1_DBG = 7,
    PMIC_WRAPPER_WACS1_WRITE0_DBG = 8,
    PMIC_WRAPPER_WACS1_WRITE1_DBG = 9,
    PMIC_DURATION_LOG_MAX   
}PMIC_DURATION_DBG_ENUM;

extern PMIC_ACCESS_DURATION_DBG pmic_access_duration_log[PMIC_DURATION_LOG_MAX][MAX_PMIC_DURATION_INFO_SIZE];
extern DCL_UINT32 pmic_access_duration_index;
extern DCL_UINT32 pmic_access_timing_issue_log[MAX_PMIC_DURATION_INFO_SIZE];
extern DCL_UINT32 pmic_access_timing_issue_index;
#endif // End of #if defined(DCL_PMIC_ACCESS_TIME_LOG)

DCL_UINT16 PMU_get_Parameter_Idx(DCL_CTRL_CMD cmd);
DCL_UINT16 PMU_Parameter_to_Value(DCL_CTRL_CMD cmd,DCL_UINT32 val);
DCL_UINT32 PMU_Value_to_Parameter(DCL_CTRL_CMD cmd,DCL_UINT32 val);
void PMU_SetData16(DCL_UINT32 Addr,DCL_UINT16 mask,DCL_UINT16 val);

#if defined(PMIC_SLIM_V3)
DCL_STATUS pmu_set_register_value(DCL_UINT32 address,PMU_FLAGS_LIST_ENUM flagname,DCL_UINT32 val);
DCL_UINT16 pmu_get_register_value(DCL_UINT32 address,PMU_FLAGS_LIST_ENUM flagname);
#endif //#if defined(PMIC_SLIM_V3)

#if defined(__DRV_UPMU_SHARE_LDO__)
DCL_BOOL ldoShare_free_idx(DCL_HANDLE handle);
DCL_UINT16 ldoShare_get_idx(DCL_HANDLE handle);
void ldoShare_set_bitmap(DCL_UINT16 idx,DCL_HANDLE handle,PMU_LDO_BUCK_LIST_ENUM ldo,DCL_BOOL enable);
DCL_STATUS ldoShare_set_enable(DCL_HANDLE handle,PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
#endif //#if defined(__DRV_UPMU_SHARE_LDO__)


#if defined(__DRV_UPMU_LPOSC_V1__)
// LPOSC 
void lposc_set_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
void lposc_set_buckboost_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
void lposc_set_acali_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
void lposc_set_freq_set(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val);
void lposc_set_freq(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT16 val);
void lposc_set_buck_freq(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT16 val);
// LPOSC CON2
void lposc_set_fd_res(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val);
void lposc_set_ssc_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
void lposc_set_ssc_mod_amp(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val);
void lposc_set_ssc_code_dur(PMU_LPOSC_LIST_ENUM lposc,DCL_UINT8 val);
void lposc_set_pg_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
void lposc_set_sw_mode_enable(PMU_LPOSC_LIST_ENUM lposc,DCL_BOOL enable);
#endif //#if defined(__DRV_UPMU_LPOSC_V1__)


#if defined(__DRV_UPMU_LDO_V1__)

void initLdoBuckMapping(void);
// LDO CON0
DCL_STATUS ldo_set_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
DCL_STATUS ldo_set_voltage(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 vol);
void ldo_set_oc_auto_off(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL auto_off);
void ldo_set_stb_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
void ldo_set_on_sel(PMU_LDO_BUCK_LIST_ENUM ldo, PMU_ON_SEL_ENUM sel);
void ldo_set_ocfb_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
void ldo_set_ndis_enable(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
//LDO CON1
void ldo_set_voltage_calibration_code(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 val);
void ldo_set_current_limit(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 val);
// LDO CON2
void ldo_set_oc_td(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 sel);
void ldo_set_stb_td(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT32 sel);
void ldo_set_ctrl_sel(PMU_LDO_BUCK_LIST_ENUM ldo, PMU_CTRL_LDO_CTRL_MODE_ENUM sel);
void ldo_set_sim_gpio_en(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_BOOL enable);
void ldo_set_simio_drv(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val);
void ldo_set_bias(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val);
void ldo_set_srn(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val);
void ldo_set_srp(PMU_LDO_BUCK_LIST_ENUM ldo, DCL_UINT8 val);

#endif //#if defined(__DRV_UPMU_LDO_V1__)



#if defined(__DRV_UPMU_BUCK_V1__)
// BUCK CON0
DCL_STATUS buck_set_enable(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL enable);
DCL_STATUS buck_set_voltage(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 vol);
void buck_set_on_sel(PMU_LDO_BUCK_LIST_ENUM buck, PMU_ON_SEL_ENUM sel);
void buck_set_rs(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 sel);
void buck_set_oc_auto_off(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL auto_off);
void buck_set_dis_antiunsh(PMU_LDO_BUCK_LIST_ENUM buck, DCL_BOOL off);
//BUCK CON3
void buck_set_ical(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val);
void buck_set_oc_td(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val);
void buck_set_stb_td(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val);
//BUCK CON5
DCL_STATUS buck_set_sleep_voltage(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 vol);
void buck_set_burst_threshold(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 threshold);
void buck_set_current_limit(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val);
void buck_set_ocfb_enable(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT32 val);
void buck_set_adjcksel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
void buck_set_rzsel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
void buck_set_csr(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
void buck_set_cks_prg(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
void buck_set_gmsel(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
void buck_set_zx_pdn(PMU_LDO_BUCK_LIST_ENUM buck, DCL_UINT8 val);
#endif //#if defined(__DRV_UPMU_BUCK__)

#if defined(__DRV_UPMU_VPA_V1__)
void vpa_set_enable(PMU_VPA_LIST_ENUM vpa,DCL_BOOL enable);
void vpa_set_antiring_enable(PMU_VPA_LIST_ENUM vpa,DCL_BOOL enable);
void vpa_set_rc(PMU_VPA_LIST_ENUM vpa,DCL_BOOL val);
//VPA CON2
void vpa_set_votune0(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
void vpa_set_votune1(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
//VPA CON3
void vpa_set_votune2(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
void vpa_set_votune3(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
//VPA CON4
void vpa_set_votune4(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
void vpa_set_votune5(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
//VPA CON5
void vpa_set_votune6(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
void vpa_set_votune7(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 voltage);
DCL_STATUS vpa_set_votune(PMU_VPA_LIST_ENUM vpa, DCL_UINT32 idx,DCL_UINT32 val);
#endif //#if defined(__DRV_UPMU_VPA_V1__)

#if defined(__DRV_UPMU_KPLED_V1__)
// KPLED CON0
void kpled_set_enable(PMU_KPLED_LIST_ENUM kpled, DCL_BOOL enable);
void kpled_set_mode(PMU_KPLED_LIST_ENUM kpled, PMU_CTRL_KPLED_MODE_ENUM val);
void kpled_set_sel(PMU_KPLED_LIST_ENUM kpled, DCL_UINT8 val);
DCL_BOOL kpled_get_status(PMU_KPLED_LIST_ENUM kpled);
#endif // #if defined(__DRV_UPMU_KPLED_V1__)


#if defined(__DRV_UPMU_CHARGER_V1__)
// CHR_CON0
void chr_set_csdac_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable);
DCL_BOOL chr_get_is_chr_det(PMU_CHR_LIST_ENUM chr);
void chr_wdt_clear_internal(PMU_CHR_LIST_ENUM chr);
void chr_set_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable);
// CHR_CON1
DCL_BOOL chr_get_is_vbat_cv_det(PMU_CHR_LIST_ENUM chr);
DCL_STATUS chr_set_vbat_cv_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage);
DCL_STATUS chr_set_vbat_cv_vth_value(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val);
void chr_set_vbat_cv_det_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable);
// CHR_CON2
DCL_UINT32 chr_get_cs_vth(PMU_CHR_LIST_ENUM chr);
DCL_STATUS chr_set_cs_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 current);
// CHR_CON3
void chr_set_csdac_stp(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val);
void chr_set_csdac_dly(PMU_CHR_LIST_ENUM chr, DCL_UINT16 val);
DCL_BOOL chr_get_is_bat_on(PMU_CHR_LIST_ENUM chr);
// CHR_CON6
void chr_wdt_clear_internal(PMU_CHR_LIST_ENUM chr);
void chr_set_wdt_td(PMU_CHR_LIST_ENUM chr,DCL_UINT32 sec);
void chr_set_wdt_clear(PMU_CHR_LIST_ENUM chr);
void chr_set_wdt_enable(PMU_CHR_LIST_ENUM chr, DCL_UINT8 enable);
// CHR_CON7
void chr_set_wdt_int_enable(PMU_CHR_LIST_ENUM chr, DCL_UINT8 enable);
// CHR_CON8
void chr_set_adc_measure_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable);

DCL_STATUS chr_set_vbat_hv_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage);
DCL_STATUS chr_set_vbat_ov_vth(PMU_CHR_LIST_ENUM chr, DCL_UINT32 voltage);
void chr_set_baton_ht_en(PMU_CHR_LIST_ENUM chr, DCL_UINT16 enable);
void chr_set_otg_bvalid_en(PMU_CHR_LIST_ENUM chr, DCL_UINT16 enable);

#if defined(__DRV_UPMU_BC11_V1__)
void chr_bc11_comp_vth(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_COMP_VTH_ENUM sel);
void chr_bc11_comp_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_COMP_EN_ENUM sel);
void chr_bc11_ipd_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_IPD_EN_ENUM  sel);
void chr_bc11_ipu_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_IPU_EN_ENUM sel);
void chr_bc11_bias_enable(PMU_CHR_LIST_ENUM chr, DCL_BOOL enable);
void chr_bc11_bb_ctrl(PMU_CHR_LIST_ENUM chr);
void chr_bc11_reset(PMU_CHR_LIST_ENUM chr);
void chr_bc11_vsrc_en_ctrl(PMU_CHR_LIST_ENUM chr,PMU_CTRL_BC11_VSRC_EN_ENUM sel);
DCL_BOOL chr_bc11_get_cmp_out(PMU_CHR_LIST_ENUM chr);
#endif // #if defined(__DRV_UPMU_BC11_V1__)
#endif //#if defined(__DRV_UPMU_CHARGER_V1__)

#if defined(__DRV_UPMU_STRUP_V1__) 
void strup_usbdl_mode_enable(PMU_STRUP_LIST_ENUM strup,DCL_BOOL enable);
#endif // #if defined(__DRV_UPMU_STRUP_V1__)


#if defined(__DRV_UPMU_BOOST_V1__) 
// BOOST CON0
void boost_set_enable(PMU_BOOST_LIST_ENUM boost, DCL_BOOL enable);
void boost_set_type(PMU_BOOST_LIST_ENUM boost, upmu_boost_type_enum val);
void boost_set_mode(PMU_BOOST_LIST_ENUM boost, upmu_boost_mode_enum val);
void boost_set_vrsel(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_oc_auto_off(PMU_BOOST_LIST_ENUM boost, DCL_BOOL auto_off);
DCL_BOOL boost_get_oc_status(PMU_BOOST_LIST_ENUM boost);
// BOOST CON1
void boost_set_cl(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_cs(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_rc(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_ss(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
// BOOST CON2
void boost_set_cksel(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_sr_pmos(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_sr_nmos(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
void boost_set_slp(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
// BOOST CON3
void boost_set_cks_prg(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
// BOOST CON4
void boost_set_oc_thd(PMU_BOOST_LIST_ENUM boost, upmu_boost_oc_thd_enum val);
void boost_set_oc_wnd(PMU_BOOST_LIST_ENUM boost, upmu_boost_oc_wnd_enum val);
void boost_set_clk_cal(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
// BOOST CON6
void boost_set_hw_sel(PMU_BOOST_LIST_ENUM boost, upmu_boost_hw_sel_enum val);
void boost_set_cc(PMU_BOOST_LIST_ENUM boost, DCL_UINT8 val);
#endif //#if defined(__DRV_UPMU_BOOST_V1__)

#if defined(__DRV_UPMU_ISINK_V1__)
// ISINK CON0
void isink_set_enable(PMU_ISINK_LIST_ENUM isink, DCL_BOOL enable);
void isinks_set_vref_cal(PMU_ISINK_LIST_ENUM isink, kal_uint8 val);
void isink_set_mode(PMU_ISINK_LIST_ENUM isink, PMU_CTRL_ISINK_MODE_ENUM val);
void isink_set_step(PMU_ISINK_LIST_ENUM isink, DCL_UINT8 val);
#endif //#if defined(__DRV_UPMU_ISINK_V1__)

#if defined(__DRV_UPMU_SPK_V1__)
// SPK CON0
void spk_set_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable);
void spk_set_reset(PMU_SPK_LIST_ENUM spk, DCL_BOOL reset);
DCL_STATUS spk_set_vol(PMU_SPK_LIST_ENUM spk, PMU_SPK_VOL_ENUM vol);
void spk_set_oc_auto_off(PMU_SPK_LIST_ENUM spk, DCL_BOOL auto_off);
void spk_set_ocfb_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable);
DCL_BOOL spk_set_get_oc_status(PMU_SPK_LIST_ENUM spk);
// SPK CON1
void spk_set_pfd_mode_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable);
void spk_set_cmode(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
void spk_set_ccode(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
// SPK CON2
void spk_set_oc_thd(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
void spk_set_oc_wnd(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
// SPK CON3
void spk_set_osc_isel(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
void spk_set_oc_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable);
// SPK CON4
void spk_set_ocn_bias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
void spk_set_ocp_bias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
// SPK CON5
void spk_set_pg_slew_dly(PMU_SPK_LIST_ENUM spk,DCL_UINT8 val);
void spk_set_pg_slew_l(PMU_SPK_LIST_ENUM spk,DCL_UINT8 val);
// SPK CON7
void spk_set_mode(PMU_SPK_LIST_ENUM spk, PMU_CTRL_SPK_MODE_ENUM val);
void spk_set_ab_obias(PMU_SPK_LIST_ENUM spk, DCL_UINT8 val);
void spk_set_ab_oc_enable(PMU_SPK_LIST_ENUM spk, DCL_BOOL enable);
#endif // #if defined(__DRV_UPMU_SPK_V1__)

#if defined(__DRV_UPMU_SPK_V2__)
// SPK CON0
void spk_set_enable(PMU_SPK_LIST_ENUM spk, kal_bool enable);
DCL_STATUS spk_set_vol(PMU_SPK_LIST_ENUM spk, PMU_SPK_VOL_ENUM vol);
void spk_set_oc_enable(PMU_SPK_LIST_ENUM spk, kal_bool enable);
void spk_set_obias(PMU_SPK_LIST_ENUM spk, kal_uint8 val);
void spk_set_oc_thd(PMU_SPK_LIST_ENUM spk, kal_uint8 val);
void spk_set_oc_wnd(PMU_SPK_LIST_ENUM spk, kal_uint8 val);
#endif // #if defined(__DRV_UPMU_SPK_V2__)
#endif //#define __DCL_PMU_COMMON_SW_H__


