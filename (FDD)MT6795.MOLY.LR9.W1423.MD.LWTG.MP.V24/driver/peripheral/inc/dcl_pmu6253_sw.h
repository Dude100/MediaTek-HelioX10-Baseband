


#ifndef __DCL_PMU6253_SW_H_STRUCT__
#define __DCL_PMU6253_SW_H_STRUCT__

#include "dcl_pmic_features.h"

#if defined(PMIC_6253_REG_API)

/* Charger external interrupt is fixed. */

#define PMU_CHR_EINT_PIN      7


/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#if defined(PMIC_6253_REG_API)
#if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)
#define PMU_ADC_VBAT_CH_NUM      0
#define PMU_ADC_VISENSE_CH_NUM   1
#define PMU_ADC_VCHARGER_CH_NUM  2
#else // #if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)
#define PMU_ADC_VBAT_CH_NUM      3
#define PMU_ADC_VISENSE_CH_NUM   4
#define PMU_ADC_VCHARGER_CH_NUM  5
#endif // #if defined(DRV_MISC_PMU_ADC_CHANNEL_FROM_0)
#endif // #elif defined(PMIC_6253_REG_API)

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMU_ADC_FACTOR_VBAT      100
#define PMU_ADC_FACTOR_VISENSE   100
#define PMU_ADC_FACTOR_VCHARGER  250


// Define to enable PMU6253 charger watch dog timer kick
// When enable charger, PMU6253 will enable a watch dog timer
// We need to kick the timer periodically, to ontify PMU6253 that BB is alive
// If timeout, PMU6253 will disable charge automatically
// #### If this is NOT enabled, we will disable the watch dog timer function at boot time
// This should be defined when PMU driver need to perform WDT clear 
// BMT already support charge WDT, so this should be comment
//#define PMU6253_ENABLE_DRIVER_CHARGE_WDT


// Define to disable charge WDT of PMU6253
// Define only for debug purpose
//#define DEBUG_DISABLE_CHARGE_WDT



// (0x800) VRF CON
typedef enum{
	VRF_ON_SEL_SRCLKENA=0,
	VRF_ON_SEL_VRF_EN
}pmu6253_vrf_on_sel_enum;

typedef enum{
	VD_SENSE_FROM_LOCAL_VOLTAGE=0,
	VD_SENSE_FROM_REMOTE_VOLTAGE
}pmu6253_vd_sense_enum;

// (0x810) VTCXO CON
typedef enum{
	VTCXO_ON_SEL_SRCLKENA=0,
	VTCXO_ON_SEL_VTCXO_EN
}pmu6253_vtcxo_on_sel_enum;

// (0x814) VA CON
typedef enum{
	VA_ON_SEL_ALWAYS_ON = 0,
	VA_ON_SEL_SRCLKENA
}pmu6253_va_on_sel_enum;

// (0x818) VSIM CON
typedef enum{
	PMU6253_VSIM_1_8V = 0,
	PMU6253_VSIM_3_0V
}pmu6253_vsim_sel_enum;

#if defined(__DRV_PMU53_SPEC_V1__)

// (0x824) VBT CON ==> VBT move to 0x890
typedef enum{
	VBT_SEL_2_8V = 0,
	VBT_SEL_3_0V
}pmu6253_vbt_sel_enum;

#else // #if defined(__DRV_PMU53_SPEC_V1__)

// (0x890) VBT CON
typedef enum{
	VBT_SEL_1_5V = 0,
	VBT_SEL_1_8V,
	VBT_SEL_2_5V,
	VBT_SEL_3_0V
}pmu6253_vbt_sel_enum;

#endif // #if defined(__DRV_PMU53_SPEC_V1__)

// (0x828) VCAMD CON
typedef enum{
	VCAMD_SEL_1_3V = 0,
	VCAMD_SEL_1_5V,
	VCAMD_SEL_1_8V,
	VCAMD_SEL_2_8V
}pmu6253_vcamd_sel_enum;

// (0x82C) VCAMA CON
typedef enum{
	VCAMA_SEL_1_5V = 0,
	VCAMA_SEL_1_8V,
	VCAMA_SEL_2_5V,
	VCAMA_SEL_2_8V
}pmu6253_vcama_sel_enum;

// (0x834) GPIO CON
typedef enum{
	GPIO_DRV_8_MA=0,
	GPIO_DRV_4_MA
}pmu6253_gpio_drv_sel_enum;

// (0x844) VCORE CON1
typedef enum{
	VCORE_MODESET_PWM = 0,
	VCORE_MODESET_PFM
}pmu6253_vcore_modeset_enum;

typedef enum{
	VCORE_ADC_IN_NEGATIVE_EDGE = 0,
	VCORE_ADC_IN_POSITIVE_EDGE
}pmu6253_vcore_adc_in_enum;

typedef enum{
	VCORE_26MHZ_DIVIDED_BY_32 = 0,
	VCORE_26MHZ_DIVIDED_BY_16
}pmu6253_vcore_fast_slow_enum;

typedef enum{
	VCORE_PWMB_3_BITS = 0,
	VCORE_PWMB_4_BITS
}pmu_6253_vcore_pwmb_enum;

// (0x848) VCORE CON2
typedef enum{
	VCORE_VOLSEL_1_4V_TO_2_2V = 0,
	VCORE_VOLSEL_0_8V_TO_1_6V
}pmu6253_vcore_volsel_enum;

// (0x84C) VCORE CON3
typedef enum{
	VCORE_VFBADJ_0_85V = 0,
	VCORE_VFBADJ_0_90V,
	VCORE_VFBADJ_0_95V,
	VCORE_VFBADJ_1_00V,
	VCORE_VFBADJ_1_05V,
	VCORE_VFBADJ_1_10V,
	VCORE_VFBADJ_1_15V,
	VCORE_VFBADJ_1_20V,
	VCORE_VFBADJ_1_25V,
	VCORE_VFBADJ_1_30V,
	VCORE_VFBADJ_1_35V,
	VCORE_VFBADJ_1_40V,
	VCORE_VFBADJ_1_45V,
	VCORE_VFBADJ_1_50V,
	VCORE_VFBADJ_1_55V,
	VCORE_VFBADJ_1_60V
}pmu6253_vcore_vfbadj_enum;

typedef enum{
	VCORE_DIRECT_CTRL_DVFS = 0,
	VCORE_DIRECT_CTRL_DIRECT_FEED_THROUGH
}pmu6253_vcore_direct_ctrl_enum;

typedef enum{
	VCORE_DCVCLKSEL_INTERNAL = 0,
	VCORE_DCVCLKSEL_EXTERNAL
}pmu6253_vcore_dcvclksel_enum;

typedef enum{
	VCORE_MODEEN_MANUAL_CHANGE_MODE = 0,
	VCORE_MODEEN_MANUAL_AUTO_CHANGE_MODE,
	VCORE_MODEEN_MANUAL_SW_CHANGE_MODE
}pmu6253_vcore_modeen_enum;

typedef enum{
	VCORE_MODECMP_LOW_OFFSET = 0,
	VCORE_MODECMP_AUTO_ZERO
}pmu6253_vcore_modecmp_enum;

typedef enum{
	VCORE_MODESEL1A_NCD_MODE = 0,
	VCORE_MODESEL1A_AVG_CURRENT_MODE
}pmu6253_vcore_modesel1a_enum;

typedef enum{
	VCORE_CLK_SOURCE_FROM_CLKSQ = 0,
	VCORE_CLK_SOURCE_FROM_TCXO26M_CK
}pmu6253_vcore_clk_source_enum;

// (0x860) STARTUP CON0
typedef enum{
	UV_SEL_2_90V = 0,
	UV_SEL_2_75V,
	UV_SEL_2_60V,
	UL_SEL_FOLLOW_DDLO
}pmu6253_uv_sel_enum;

typedef enum{
	PWRKEY_LOW = 0,
	PWRKEY_HIGH
}pmu6253_pwrkey_signal_enum;

// (0x864) STARTUP CON1
typedef enum{
	THR_INIT_SETTING = 0,
	THR_PLUS_10_DEGREE_C,
	THR_MINUS_20_DEGREE_C,
	THR_MINUS_10_DEGREE_C
}pmu6253_thr_sel_num;

// (0x870) CHR CON0
typedef enum{
	CHOFST_PLUS_0_STEP = 0,
	CHOFST_PLUS_1_STEP = 1,
	CHOFST_PLUS_2_STEP = 2,
	CHOFST_MINUS_2_STEP = 6,
	CHOFST_MINUS_1_STEP = 7
}pmu6253_chofst_enum;

typedef enum{
	CHR_CURR_50_0MA = 0,
	CHR_CURR_87_5MA,
	CHR_CURR_150_0MA,
	CHR_CURR_225_0MA,
	CHR_CURR_300_0MA,
	CHR_CURR_450_0MA,
	CHR_CURR_650_0MA,
	CHR_CURR_800_0MA
}pmu6253_chr_current_enum;

typedef enum{
	CV_TUNE_1_200V = 0,
	CV_TUNE_1_205V,
	CV_TUNE_1_210V,
	CV_TUNE_1_215V,
	CV_TUNE_1_180V,
	CV_TUNE_1_185V,
	CV_TUNE_1_190V,
	CV_TUNE_1_195V
}pmu6253_cv_tune_enum;

// (0x874) CHR CON1
typedef enum{
	CAL_PRECC_50_0MA = 0,
	CAL_PRECC_87_5_MA,
	CAL_PRECC_150_0MA,
	CAL_PRECC_225_0MA
}pmu6253_cal_precc_enum;

typedef enum{
	SYSTEM_PWR_SRC_DEFAULT = 0,
	SYSTEM_PWR_SRC_REFER_PS_SET
}pmu6253_ps_sel_enum;

typedef enum{
	SYSTEM_PWR_SRC_VBAT = 0,
	SYSTEM_PWR_SRC_AC
}pmu6253_ps_set_enum;

typedef enum{
	CHR_OV_5_5V = 0,
	CHR_OV_6_0V,
	CHR_OV_6_5V,
	CHR_OV_7_0V
}pmu6253_chr_ov_enum;

// (0x87C) CHR CON3
typedef enum{
	CHR_WDT_4_SEC = 0,
	CHR_WDT_8_SEC,
	CHR_WDT_16_SEC,
	CHR_WDT_32_SEC
}pmu6253_chr_wdt_td_enum;

// (0x880) DRIVER CON0
typedef enum{
	KPLED_WLED = 0,
	KPLED_RLED
}pmu6253_kpled_type_enum;


typedef enum{
	LED_1_SET = 1,
	LED_4_WLED_4_RLED = 3,
	LED_4_WLED_8_RLED = 7
}pmu6253_kpled_sel_enum;

typedef enum{
	ISINK1_TURN_ON = 1,		// Bit 0
	ISINK2_TURN_ON = 2,		// Bit 1
	ISINK3_TURN_ON = 4,		// Bit 2
	ISINK4_TURN_ON = 8,		// Bit 3
	ISINKALL_TURN_ON = 0xF  // 0xF (Bit[3..0])
}pmu6253_isinks_chsel_enum;

// (0x888) DRIVER CON2
typedef enum{
	ISINKS_VLED_STEP_5_MA = 0,
	ISINKS_VLED_STEP_10_MA,
	ISINKS_VLED_STEP_15_MA,
	ISINKS_VLED_STEP_20_MA
}pmu6253_isinks_vled_enum;

#if defined(__DRV_PMU53_SPEC_V1__)

// (0x890) DRIVER CON4
typedef enum{
	VIBR_SEL_1_5V = 0,
	VIBR_SEL_1_8V,
	VIBR_SEL_2_5V,
	VIBR_SEL_3_0V
}pmu6253_vibr_sel_enum;

#else // #if defined(__DRV_PMU53_SPEC_V1__)

// (0x824) DRIVER CON4
typedef enum{
	VIBR_SEL_2_8V = 0,
	VIBR_SEL_3_0V
}pmu6253_vibr_sel_enum;

#endif // #if defined(__DRV_PMU53_SPEC_V1__)

typedef enum{
	VBOOST_SS_SPEED_NORMAL = 0,
	VBOOST_SS_SPEED_2_OVER_3
}pmu6253_vboost_ss_speed_enum;

// (0x8B0) CLASSD CON0
typedef enum{
	SPK_EMODE_NO_EXTENSION = 1,
	SPK_EMODE_LEAD_EXTENSION,
	SPK_EMODE_LAG_EXTENSION
}pmu6253_spk_emode_enum;

typedef enum{
	PMU6253_SPK_CLASS_D_MODE = 0,
	PMU6253_SPK_CLASS_AB_MODE
}pmu6253_spk_mode_enum;

typedef enum{
	SPK_AB_BIAS_3_225MA = 0,
	SPK_AB_BIAS_6_381MA,
	SPK_AB_BIAS_9_533MA,
	SPK_AB_BIAS_12_684MA
}pmu6253_spkab_obias_enum;

// (0x8B8) CLASSD CON2
typedef enum{
	SPK_DMODE_FB_FORCED = 0,
	SPK_DMODE_FB_AUTO,
	SPK_DMODE_FF_FORCED,
	SPK_DMODE_FF_AUTO
}pmu6253_spk_dmode_enum;

typedef enum{
	SPK_PCHG_103_0NS = 0,
	SPK_PCHG_55_67NS,
	SPK_PCHG_39_09NS,
	SPK_PCHG_30_47NS
}pmu6253_spk_pchg_enum;

typedef enum{
	SPK_SPK_CCODE = 1,
	SPK_TRIANGLE_WAVE = 2,
	SPK_PRNG_WAVE = 3
}pmu6253_spk_freq_ctrl_enum;

typedef enum{
	SPK_SLEW_2_OVER_4 = 0,
	SPK_SLEW_1_OVER_4,
	SPK_SLEW_4_OVER_4,
	SPK_SLEW_3_OVER_4
}pmu6253_spk_slew_enum;

// (0x8D0) OC CON0
typedef enum{
	OC_GEAR_100_US = 0,
	OC_GEAR_200_US,
	OC_GEAR_400_US,
	OC_GEAR_800_US
}pmu6253_gear_enum;

// (0x8E0) OC CON4
typedef enum{
	SS_DELAY_200US = 0,
	SS_DELAY_400US,
	SS_DELAY_600US,
	SS_DELAY_800US
}pmu6253_soft_start_delay;


// (0x8E4) OC CON5
typedef enum{
	SPK_OC_FLAG = 0x0001,
	VIBR_OC_FLAG = 0x0002,
	VBOOST_OC_FLAG = 0x0004,
	VSIM_OC_FLAG = 0x0008,
	VBT_OC_FLAG = 0x0010,
	VUSB_OC_FLAG = 0x0020,
	VCAMD_OC_FLAG = 0x0040,
	VCAMA_OC_FLAG = 0x0080,
	VTCXO_OC_FLAG = 0x0800,
	VRF_OC_FLAG = 0x1000,
	VIO_OC_FLAG = 0x2000,
	VM_OC_FLAG = 0x4000,
	VA_OC_FLAG = 0x8000
}pmu6253_oc_bit_enum;


// =====================================================================================
// (0x800) VRF CON
extern void dcl_pmu6253_vrf_enable(kal_bool enable);
extern void dcl_pmu6253_vrf_cal(kal_uint8 val);
extern void dcl_pmu6253_vrf_on_sel(pmu6253_vrf_on_sel_enum sel);
extern void dcl_pmu6253_vrf_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vrf_status(void);

// (0x804) VIO CON
extern void dcl_pmu6253_vio_cal(kal_uint8 val);
extern void dcl_pmu6253_vio_vd_sense(pmu6253_vd_sense_enum sel);
extern void dcl_pmu6253_vio_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vio_status(void);

// (0x808) VM CON
extern void dcl_pmu6253_vm_cal(kal_uint8 val);
extern void dcl_pmu6253_vm_vd_sense(pmu6253_vd_sense_enum sel);
extern void dcl_pmu6253_vm_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vm_status(void);

// (0x80C) VRTC CON
extern void dcl_pmu6253_vrtc_cal(kal_uint8 val);
extern kal_bool dcl_pmu6253_vrtc_status(void);

// (0x810) VTCXO CON
extern void dcl_pmu6253_vtcxo_enable(kal_bool enable);
extern void dcl_pmu6253_vtcxo_cal(kal_uint8 val);
extern void dcl_pmu6253_vtcxo_on_sel(pmu6253_vtcxo_on_sel_enum sel);
extern void dcl_pmu6253_vtcxo_srclken(kal_bool enable);
extern void dcl_pmu6253_vtcxo_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vtcxo_status(void);

// (0x814) VA CON
extern void dcl_pmu6253_va_cal(kal_uint8 val);
extern void dcl_pmu6253_va_vd_sense(pmu6253_vd_sense_enum sel);
extern void dcl_pmu6253_va_on_sel(pmu6253_va_on_sel_enum sel);
extern void dcl_pmu6253_va_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_va_status(void);

// (0x818) VSIM CON
extern void dcl_pmu6253_vsim_enable(kal_bool enable);
extern void dcl_pmu6253_vsim_cal(kal_uint8 val);
extern void dcl_pmu6253_vsim_datal(kal_bool pull_low);
extern void dcl_pmu6253_vsim_sel(pmu6253_vsim_sel_enum sel);
extern void dcl_pmu6253_vsim_pwr_saving(kal_bool enable);
extern void dcl_pmu6253_vsim_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vsim_status(void);

// (0x81C) VSIM2 CON
extern void dcl_pmu6253_vsim2_enable(kal_bool enable);
extern void dcl_pmu6253_vsim2_cal(kal_uint8 val);
extern void dcl_pmu6253_vsim2_datal(kal_bool pull_low);
extern void dcl_pmu6253_vsim2_sel(pmu6253_vsim_sel_enum sel);
extern kal_bool dcl_pmu6253_vsim2_status(void);

// (0x820) VUSB CON
extern void dcl_pmu6253_vusb_enable(kal_bool enable);
extern void dcl_pmu6253_vusb_cal(kal_uint8 val);
extern void dcl_pmu6253_vusb_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vusb_status(void);

// (0x824) VBT CON
extern void dcl_pmu6253_vbt_enable(kal_bool enable);
extern void dcl_pmu6253_vbt_cal(kal_uint8 val);
extern void dcl_pmu6253_vbt_sel(pmu6253_vbt_sel_enum sel);
extern void dcl_pmu6253_vbt_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vbt_status(void);

// (0x828) VCAMD CON
extern void dcl_pmu6253_vcamd_enable(kal_bool enable);
extern void dcl_pmu6253_vcamd_cal(kal_uint8 val);
extern void dcl_pmu6253_vcamd_sel(pmu6253_vcamd_sel_enum sel);
extern void dcl_pmu6253_vcamd_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vcamd_status(void);

// (0x82C) VCAMA CON
extern void dcl_pmu6253_vcama_enable(kal_bool enable);
extern void dcl_pmu6253_vcama_cal(kal_uint8 val);
extern void dcl_pmu6253_vcama_sel(pmu6253_vcama_sel_enum sel);
extern void dcl_pmu6253_vcama_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vcama_status(void);

// (0x834) GPIO CON
extern void dcl_pmu6253_gpio_drv(pmu6253_gpio_drv_sel_enum sel);
extern void dcl_pmu6253_mtv_enable(kal_bool enable);

// (0x840) VCORE CON
extern void dcl_pmu6253_vcore_en_force(kal_bool enable);
extern void dcl_pmu6253_vcore_cal(kal_uint8 val);
extern void dcl_pmu6253_vcore_vd_sense(pmu6253_vd_sense_enum sel);
extern kal_bool dcl_pmu6253_vcore_status(void);

// (0x844) VCORE CON1
extern void dcl_pmu6253_vcore_modeset(pmu6253_vcore_modeset_enum mode);
extern void dcl_pmu6253_vcore_adc_in_edge(pmu6253_vcore_adc_in_enum edge);
extern void dcl_pmu6253_vcore_fast_slow(pmu6253_vcore_fast_slow_enum sel);
extern void dcl_pmu6253_vcore_pwmb(pmu_6253_vcore_pwmb_enum sel);
extern void dcl_pmu6253_vcore_acc_out_init(kal_uint8 val);

// (0x848) VCORE CON2
extern void dcl_pmu6253_vcore_volsel(pmu6253_vcore_volsel_enum sel);
extern void dcl_pmu6253_vcore_fben(kal_bool enable);

// (0x84C) VCORE CON3
extern void dcl_pmu6253_vcore_vfbadj(pmu6253_vcore_vfbadj_enum sel);
extern void dcl_pmu6253_vcore_direct_ctrl_en(pmu6253_vcore_direct_ctrl_enum sel);
extern void dcl_pmu6253_vcore_dcvclksel(pmu6253_vcore_dcvclksel_enum sel);
extern void dcl_pmu6253_vcore_modeen(pmu6253_vcore_modeen_enum sel);
extern void dcl_pmu6253_vcore_modecmp(pmu6253_vcore_modecmp_enum sel);
extern void dcl_pmu6253_vcore_modesel1A(pmu6253_vcore_modesel1a_enum sel);

// (0x854) VCORE CON5
extern void dcl_pmu6253_vcore_vfbadj_slp(pmu6253_vcore_vfbadj_enum sel);
extern void dcl_pmu6253_vcore_clk_source_sel(pmu6253_vcore_clk_source_enum sel);

// (0x860) STARTUP CON0
extern void dcl_pmu6253_uv_sel(pmu6253_uv_sel_enum sel);
extern void dcl_pmu6253_pwrkey_vcore(pmu6253_pwrkey_signal_enum sel);
extern void dcl_pmu6253_pwrkey_deb(pmu6253_pwrkey_signal_enum sel);

// (0x864) STARTUP CON1
extern void dcl_pmu6253_thr_sel(pmu6253_thr_sel_num sel);

// (0x870) CHR CON0
extern void dcl_pmu6253_chr_enable(kal_bool enable);
extern void dcl_pmu6253_chofst(pmu6253_chofst_enum sel);
extern void dcl_pmu6253_chr_current(pmu6253_chr_current_enum sel);
extern pmu6253_chr_current_enum pmu6253_chr_get_current(void);
extern void dcl_pmu6253_chr_force_enable(kal_bool enable);
extern void dcl_pmu6253_cv_rt(kal_uint8 val);
extern void dcl_pmu6253_cv_tune(pmu6253_cv_tune_enum sel);

// (0x874) CHR CON1
extern void dcl_pmu6253_cal_precc(pmu6253_cal_precc_enum sel);
extern void dcl_pmu6253_ps_sel(pmu6253_ps_sel_enum sel);
extern void dcl_pmu6253_ps_set(pmu6253_ps_set_enum sel);
extern void dcl_pmu6253_chr_ov_sel(pmu6253_chr_ov_enum sel);

// (0x878) CHR CON2
extern kal_bool dcl_pmu6253_chrdet(void);
extern kal_bool dcl_pmu6253_ovp(void);
extern kal_bool dcl_pmu6253_bat_on(void);
extern kal_bool dcl_pmu6253_bad_bat(void);
extern kal_bool dcl_pmu6253_cv_mode(void);

// (0x87C) CHR CON3
extern void dcl_pmu6253_chr_wdt_td(pmu6253_chr_wdt_td_enum sel);
extern void dcl_pmu6253_chr_wdt_enable(kal_bool enable);

// (0x8F0) CHR CON4
extern void dcl_pmu6253_chr_wdt_intr_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_chr_wdt_status(void);
extern void dcl_pmu6253_chr_wdt_clear(void);

// (0x8F4) CHR CON5
//extern void dcl_pmu6253_chr_wdt_cnt(kal_uint32 val32);

// (0x880) DRIVER CON0
extern void dcl_pmu6253_isinks_enable(kal_bool enable);
extern void dcl_pmu6253_isinks_force_off(kal_bool off);
extern void dcl_pmu6253_kpled_type(pmu6253_kpled_type_enum sel);
extern void dcl_pmu6253_kpled_enable(kal_bool enable);
extern void dcl_pmu6253_kpled_force_off(kal_bool off);
extern void dcl_pmu6253_kpled_sel(pmu6253_kpled_sel_enum sel);
extern kal_bool dcl_pmu6253_isink1_status(void);
extern kal_bool dcl_pmu6253_isink2_status(void);
extern kal_bool dcl_pmu6253_isink3_status(void);
extern kal_bool dcl_pmu6253_isink4_status(void);
extern kal_bool dcl_pmu6253_kpled_status(void);

// (0x884) DRIVER CON1
extern void dcl_pmu6253_isinks_dimm(kal_uint8 sel);
extern void dcl_pmu6253_isinks_chsel(pmu6253_isinks_chsel_enum sel);

// (0x888) DRIVER CON2
extern void dcl_pmu6253_sinks_irset_cal(kal_uint8 val);
extern void dcl_pmu6253_isinks_vled_step(pmu6253_isinks_vled_enum sel);

// (0x88C) DRIVER CON3
extern void dcl_pmu6253_bl_enable(kal_bool enable);
extern void dcl_pmu6253_vboost_enable(kal_bool enable);
extern void dcl_pmu6253_bl_vgen_forceon(kal_bool on);
extern void dcl_pmu6253_bl_mode(kal_uint8 val);
extern void dcl_pmu6253_dimm_duty(kal_uint8 val);

// (0x890) DRIVER CON4
extern void dcl_pmu6253_vibr_enable(kal_bool enable);
extern void dcl_pmu6253_vibr_sel(pmu6253_vibr_sel_enum sel);
extern void dcl_pmu6253_vibr_cal(kal_uint8 val);
extern void dcl_pmu6253_vibr_ocfb_enable(kal_bool enable);
extern kal_bool dcl_pmu6253_vibr_status(void);

// (0x8A0) BOOST CON0
extern void dcl_pmu6253_vboost_sync_enable(kal_bool enable);
extern void dcl_pmu6253_vboost_ss_speed(pmu6253_vboost_ss_speed_enum sel);
extern void dcl_pmu6253_vboost_tune(kal_uint8 val);
extern void dcl_pmu6253_vboost_cal(kal_uint8 val);
extern kal_bool dcl_pmu6253_vboost_trk_status(void);
extern kal_bool dcl_pmu6253_vboost_status(void);

// (0x8A4) BOOST CON1
extern void dcl_pmu6253_isns_cal(kal_uint8 val);

// (0x8A8) BOOST CON2
extern void dcl_pmu6253_vboost_forceon_clk(kal_bool forceon);
extern void dcl_pmu6253_vboost_disclk(kal_bool forceoff);

// (0x8B0) CLASSD CON0
extern void dcl_pmu6253_spk_enable(kal_bool enable);
extern void dcl_pmu6253_spk_reset(kal_bool reset);
extern void dcl_pmu6253_spk_emode(pmu6253_spk_emode_enum sel);
extern void dcl_pmu6253_spk_mode(pmu6253_spk_mode_enum sel);
extern void dcl_pmu6253_spkab_float(kal_bool enable);
extern void dcl_pmu6253_spkab_sended(kal_bool enable);
extern void dcl_pmu6253_spkab_oc_enable(kal_bool enable);
extern void dcl_pmu6253_spkab_depop_enable(kal_bool enable);
extern void dcl_pmu6253_spkab_obias(pmu6253_spkab_obias_enum sel);

// (0x8B4) CLASSD CON1
extern void dcl_pmu6253_spk_dtin(kal_uint8 val);
extern void dcl_pmu6253_spk_dtip(kal_uint8 val);
extern void dcl_pmu6253_spk_dtcn(kal_uint8 val);
extern void dcl_pmu6253_spk_dtcp(kal_uint8 val);

// (0x8B8) CLASSD CON2
extern void dcl_pmu6253_spk_dmode(pmu6253_spk_dmode_enum sel);
extern void dcl_pmu6253_spk_pchg(pmu6253_spk_pchg_enum sel);
extern void dcl_pmu6253_spk_dtcal(kal_bool enable);
extern void dcl_pmu6253_spk_pmode_enable(kal_bool enable);
extern void dcl_pmu6253_spk_cmode(pmu6253_spk_freq_ctrl_enum sel);
extern void dcl_pmu6253_spk_ccode(kal_uint8 val);

// (0x8BC) CLASSD CON3
extern void dcl_pmu6253_spk_enable_view_clk(kal_bool enable);
extern void dcl_pmu6253_spk_enable_view_vref(kal_bool enable);
extern void dcl_pmu6253_spk_slew(pmu6253_spk_slew_enum sel);
extern void dcl_pmu6253_spk_oc_enable(kal_bool enable);
extern void dcl_pmu6253_spk_oscisel_half(kal_bool half);
extern void dcl_pmu6253_spk_vol(kal_uint8 val);
extern kal_uint8 pmu6253_spk_get_vol(void);

// (0x8C8) TEST CON2
extern void dcl_pmu6253_adc_vol_divided_by_2(kal_bool enable);
extern void dcl_pmu6253_adc_meas_on(kal_bool enable);

// (0x8D0) OC CON0
extern void dcl_pmu6253_vrf_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vrf_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vrf_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vio_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vio_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vio_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vm_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vm_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vm_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_va_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_va_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_va_oc_int_enable(kal_bool enable);

// (0x8D4) OC CON1
extern void dcl_pmu6253_vtcxo_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vtcxo_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vtcxo_oc_int_enable(kal_bool enable);

// (0x8D8) OC CON2
extern void dcl_pmu6253_vbt_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vbt_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vbt_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vusb_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vusb_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vusb_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vcamd_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vcamd_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vcamd_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vcama_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vcama_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vcama_oc_int_enable(kal_bool enable);

// (0x8DC) OC CON3
extern void dcl_pmu6253_spk_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_spk_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_spk_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vibr_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vibr_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vibr_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vboost_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vboost_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vboost_oc_int_enable(kal_bool enable);
extern void dcl_pmu6253_vsim_oc_gear(pmu6253_gear_enum sel);
extern void dcl_pmu6253_vsim_oc_auto_off(kal_bool enable);
extern void dcl_pmu6253_vsim_oc_int_enable(kal_bool enable);

// (0x8E0) OC CON4
extern void dcl_pmu6253_vibr_stbtd(pmu6253_soft_start_delay sel);
extern void dcl_pmu6253_vsim_stbtd(pmu6253_soft_start_delay sel);
extern void dcl_pmu6253_vbt_stbtd(pmu6253_soft_start_delay sel);
extern void dcl_pmu6253_vusb_stbtd(pmu6253_soft_start_delay sel);
extern void dcl_pmu6253_vcamd_stbtd(pmu6253_soft_start_delay sel);
extern void dcl_pmu6253_vcama_stbtd(pmu6253_soft_start_delay sel);

// (0x8E4) OC CON5
extern kal_bool dcl_pmu6253_oc_flag(pmu6253_oc_bit_enum sel);
extern void dcl_pmu6253_clear_oc_flag(pmu6253_oc_bit_enum sel);
extern void dcl_pmu6253_clear_all_oc_flag(void);


// ====== Other exported APIs =============
extern pmu6253_chr_current_enum pmu6253_ret_chr_current(void);
extern pmu6253_chr_current_enum pmu6253_ret_usb_current(void);
extern void dcl_pmu6253_init(void);



/*
typedef enum
{
	PMU_FAKE_LDO_BUCK_MAX
}PMU_FAKE_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VRF,
	VIO,
	VM,
	VRTC,
	VTCXO,
	VA,
	VSIM,
	VSIM2,
	VUSB,
	VBT,
	VCAMA,
	VCAMD,
	VCORE,
	VIBR,
	PMU_LDO_BUCK_MAX,
	VRF18,
	VFM,
	VMC
}PMU_LDO_BUCK_LIST_ENUM;

typedef enum
{
	VPA1,
	PMU_VPA_MAX
}PMU_VPA_LIST_ENUM;

typedef enum
{
	CHR,
	PMU_CHR_MAX
}PMU_CHR_LIST_ENUM;

typedef enum
{
	SPK,
	SPKL,
	SPKR,
	PMU_SPK_MAX
}PMU_SPK_LIST_ENUM;

typedef enum
{
	PMU_ISINK_MAX
}PMU_ISINK_LIST_ENUM;

typedef enum
{
	PMU_BOOST_MAX
}PMU_BOOST_LIST_ENUM;
*/


#endif // #ifdef PMIC_6253_REG_API
#endif // #ifndef __DCL_PMU6253_SW_H_STRUCT__



