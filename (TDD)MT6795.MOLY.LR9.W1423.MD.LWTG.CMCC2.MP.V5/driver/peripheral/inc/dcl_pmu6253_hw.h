

#ifndef __DCL_PMIC6253_HW_H_STRUCT__
#define __DCL_PMIC6253_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6253_REG_API)

#define PMU_BASE		MIXED_base
#define PMU_END         (PMU_BASE+0x1000) 

// =====================================================================================
#define PMIC_VRF_CON		(PMU_BASE+0x800) 
#define PMIC_VIO_CON		(PMU_BASE+0x804) 
#define PMIC_VM_CON			(PMU_BASE+0x808) 
#define PMIC_VRTC_CON		(PMU_BASE+0x80C) 
#define PMIC_VTCXO_CON		(PMU_BASE+0x810) 
#define PMIC_VA_CON			(PMU_BASE+0x814) 
#define PMIC_VSIM_CON		(PMU_BASE+0x818) 
#define PMIC_VSIM2_CON		(PMU_BASE+0x81C) 
#define PMIC_VUSB_CON		(PMU_BASE+0x820) 
#if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_VBT_CON		(PMU_BASE+0x824) 
#else // #if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_DRIVER_CON4	(PMU_BASE+0x824)
#endif // #if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_VCAMD_CON		(PMU_BASE+0x828) 
#define PMIC_VCAMA_CON		(PMU_BASE+0x82C) 
#define PMIC_GPIO_CON		(PMU_BASE+0x834) 
#define PMIC_VCORE_CON		(PMU_BASE+0x840) 
#define PMIC_VCORE_CON1		(PMU_BASE+0x844) 
#define PMIC_VCORE_CON2		(PMU_BASE+0x848) 
#define PMIC_VCORE_CON3		(PMU_BASE+0x84C) 
#define PMIC_VCORE_CON5		(PMU_BASE+0x854) 
#define PMIC_STARTUP_CON0	(PMU_BASE+0x860) 
#define PMIC_STARTUP_CON1	(PMU_BASE+0x864) 
#define PMIC_CHR_CON0		(PMU_BASE+0x870) 
#define PMIC_CHR_CON1		(PMU_BASE+0x874)
#define PMIC_CHR_CON2		(PMU_BASE+0x878)
#define PMIC_CHR_CON3		(PMU_BASE+0x87C)
//#define PMIC_CHR_CON4		(PMU_BASE+0x8F0)  ==> In 0x8F0
//#define PMIC_CHR_CON5		(PMU_BASE+0x8F4)  ==> In 0x8F4
#define PMIC_DRIVER_CON0	(PMU_BASE+0x880) 
#define PMIC_DRIVER_CON1	(PMU_BASE+0x884) 
#define PMIC_DRIVER_CON2	(PMU_BASE+0x888) 
#define PMIC_DRIVER_CON3	(PMU_BASE+0x88C) 
#if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_DRIVER_CON4	(PMU_BASE+0x890) 
#else // #if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_VBT_CON		(PMU_BASE+0x890)
#endif // #if defined(__DRV_PMU53_SPEC_V1__)
#define PMIC_BOOST_CON0		(PMU_BASE+0x8A0) 
#define PMIC_BOOST_CON1		(PMU_BASE+0x8A4) 
#define PMIC_BOOST_CON2		(PMU_BASE+0x8A8) 
#define PMIC_CLASSD_CON0	(PMU_BASE+0x8B0) 
#define PMIC_CLASSD_CON1	(PMU_BASE+0x8B4) 
#define PMIC_CLASSD_CON2	(PMU_BASE+0x8B8) 
#define PMIC_CLASSD_CON3	(PMU_BASE+0x8BC)
#define PMIC_TEST_CON2		(PMU_BASE+0x8C8)
#define PMIC_OC_CON0		(PMU_BASE+0x8D0) 
#define PMIC_OC_CON1		(PMU_BASE+0x8D4) 
#define PMIC_OC_CON2		(PMU_BASE+0x8D8) 
#define PMIC_OC_CON3		(PMU_BASE+0x8DC) 
#define PMIC_OC_CON4		(PMU_BASE+0x8E0) 
#define PMIC_OC_CON5		(PMU_BASE+0x8E4) 
#define PMIC_CHR_CON4		(PMU_BASE+0x8F0)
#define PMIC_CHR_CON5		(PMU_BASE+0x8F4)

// =====================================================================================
// (0x800) VRF CON
#define VRF_EN_MASK				0x0001
#define VRF_EN_SHIFT			0
#define VRF_CAL_MASK			0x00F0
#define VRF_CAL_SHIFT			4
#define VRF_ON_SEL_MASK			0x0400
#define VRF_ON_SEL_SHIFT		10
#define VRF_OCFB_EN_MASK		0x1000
#define VRF_OCFB_EN_SHIFT		12
#define VRF_STATUS_MASK			0x8000
#define VRF_STATUS_SHIFT		15
                 
// (0x804) VIO CON
#define VIO_CAL_MASK				0x00F0
#define VIO_CAL_SHIFT				4
#define VIO_VD_SENSE_MASK			0x0200
#define VIO_VD_SENSE_SHIFT			9
#define VIO_OCFB_EN_MASK			0x1000
#define VIO_OCFB_EN_SHIFT			12
#define VIO_STATUS_MASK				0x8000
#define VIO_STATUS_SHIFT			15
                 
// (0x808) VM CON
#define VM_CAL_MASK			0x00F0
#define VM_CAL_SHIFT		4
#define VM_VD_SENSE_MASK	0x0200
#define VM_VD_SENSE_SHIFT	9
#define VM_OCFB_EN_MASK		0x1000
#define VM_OCFB_EN_SHIFT	12
#define VM_STATUS_MASK		0x8000
#define VM_STATUS_SHIFT		15
                 
// (0x80C) VRTC CON
#define VRTC_CAL_MASK		0x00F0
#define VRTC_CAL_SHIFT		4
#define VRTC_STATUS_MASK	0x8000
#define VRTC_STATUS_SHIFT	15
                 
// (0x810) VTCXO CON
#define VTCXO_EN_MASK				0x0001
#define VTCXO_EN_SHIFT				0
#define VTCXO_CAL_MASK				0x00F0
#define VTCXO_CAL_SHIFT				4
#define VTCXO_ON_SEL_MASK			0x0400
#define VTCXO_ON_SEL_SHIFT			10
#define VTCXO_CCI_SRCLKEN_MASK		0x0800
#define VTCXO_CCI_SRCLKEN_SHIFT		11
#define VTCXO_OCFB_EN_MASK			0x1000
#define VTCXO_OCFB_EN_SHIFT			12
#define VTCXO_STATUS_MASK			0x8000
#define VTCXO_STATUS_SHIFT			15
                 
// (0x814) VA CON
#define VA_CAL_MASK					0x00F0
#define VA_CAL_SHIFT				4
#define VA_VD_SENSE_MASK			0x0200
#define VA_VD_SENSE_SHIFT			9
#define VA_ON_SEL_MASK				0x0400
#define VA_ON_SEL_SHIFT				10
#define VA_OCFB_EN_MASK				0x1000
#define VA_OCFB_EN_SHIFT			12
#define VA_STATUS_MASK				0x8000
#define VA_STATUS_SHIFT				15
                 
// (0x818) VSIM CON
#define VSIM_CCI_EN_MASK			0x0001
#define VSIM_CCI_EN_SHIFT			0
#define VSIM_CAL_MASK				0x00F0
#define VSIM_CAL_SHIFT				4
#define VSIM_DATAL_MASK				0x0200
#define VSIM_DATAL_SHIFT			9
#define VSIM_CCI_SEL_MASK			0x0400
#define VSIM_CCI_SEL_SHIFT			10
#define VSIM_CCI_PWR_SAVING_MASK	0x0800
#define VSIM_CCI_PWR_SAVING_SHIFT	11
#define VSIM_OCFB_EN_MASK			0x1000
#define VSIM_OCFB_EN_SHIFT			12
#define VSIM_STATUS_MASK			0x8000
#define VSIM_STATUS_SHIFT			15
                 
// (0x81C) VSIM2 CON
#define VSIM2_CCI_EN_MASK			0x0001
#define VSIM2_CCI_EN_SHIFT			0
#define VSIM2_CAL_MASK				0x00F0
#define VSIM2_CAL_SHIFT				4
#define VSIM2_DATAL_MASK			0x0200
#define VSIM2_DATAL_SHIFT			9
#define VSIM2_SEL_MASK				0x0400
#define VSIM2_SEL_SHIFT				10
#define VSIM2_STATUS_MASK			0x8000
#define VSIM2_STATUS_SHIFT			15
                 
// (0x820) VUSB CON
#define VUSB_EN_MASK				0x0001
#define VUSB_EN_SHIFT				0
#define VUSB_CAL_MASK				0x00F0
#define VUSB_CAL_SHIFT				4
#define VUSB_OCFB_EN_MASK				0x1000
#define VUSB_OCFB_EN_SHIFT				12
#define VUSB_STATUS_MASK			0x8000
#define VUSB_STATUS_SHIFT			15
                 
#if defined(__DRV_PMU53_SPEC_V1__)

// (0x824) VBT CON
#define VBT_EN_MASK					0x0001
#define VBT_EN_SHIFT				0
#define VBT_CAL_MASK				0x00F0
#define VBT_CAL_SHIFT				4
#define VBT_SEL_MASK				0x0400
#define VBT_SEL_SHIFT				10
#define VBT_OCFB_EN_MASK				0x1000
#define VBT_OCFB_EN_SHIFT				12
#define VBT_STATUS_MASK				0x8000
#define VBT_STATUS_SHIFT			15
                 
#else // #if defined(__DRV_PMU53_SPEC_V1__)

// (0x824) PMIC_DRIVER_CON4
#define CCI_VIBR_EN_MASK			0x0001
#define CCI_VIBR_EN_SHIFT			0
#define VIBR_CAL_MASK				0x00F0
#define VIBR_CAL_SHIFT				4
#define VIBR_SEL_MASK				0x0400
#define VIBR_SEL_SHIFT			    10
#define VIBR_OCFB_EN_MASK			0x1000
#define VIBR_OCFB_EN_SHIFT			12
#define VIBR_STATUS_MASK			0x8000
#define VIBR_STATUS_SHIFT			15

#endif // #if defined(__DRV_PMU53_SPEC_V1__)
                 
// (0x828) VCAMD CON
#define VCAMD_EN_MASK				0x0001
#define VCAMD_EN_SHIFT				0
#define VCAMD_CAL_MASK				0x00F0
#define VCAMD_CAL_SHIFT				4
#define VCAMD_SEL_MASK				0x0C00
#define VCAMD_SEL_SHIFT				10
#define VCAMD_OCFB_EN_MASK				0x1000
#define VCAMD_OCFB_EN_SHIFT			12
#define VCAMD_STATUS_MASK			0x8000
#define VCAMD_STATUS_SHIFT			15
                 
// (0x82C) VCAMA CON
#define VCAMA_EN_MASK				0x0001
#define VCAMA_EN_SHIFT				0
#define VCAMA_CAL_MASK				0x00F0
#define VCAMA_CAL_SHIFT				4
#define VCAMA_SEL_MASK				0x0C00
#define VCAMA_SEL_SHIFT				10
#define VCAMA_OCFB_EN_MASK				0x1000
#define VCAMA_OCFB_EN_SHIFT			12
#define VCAMA_STATUS_MASK			0x8000
#define VCAMA_STATUS_SHIFT			15
                 
// (0x834) GPIO CON
#define GPIO_DRV_MASK				0x0100
#define GPIO_DRV_SHIFT				8
#define CCI_MTV_EN_MASK				0x0200
#define CCI_MTV_EN_SHIFT			9
                 
// (0x840) VCORE CON
#define VCORE_EN_FORCE_MASK			0x0002
#define VCORE_EN_FORCE_SHIFT		1
#define VCORE_CAL_MASK				0x00F0
#define VCORE_CAL_SHIFT				4
#define VCORE_VD_SENSE_MASK			0x0200
#define VCORE_VD_SENSE_SHIFT		9
#define VCORE_STATUS_MASK			0x8000
#define VCORE_STATUS_SHIFT			15
                 
// (0x844) VCORE CON1
#define VCORE_MODE_SET_MASK			0x0001
#define VCORE_MODE_SET_SHIFT		0
#define VCORE_ADC_IN_EDGE_MASK		0x0002
#define VCORE_ADC_IN_EDGE_SHIFT		1
#define VCORE_FAST_SLOW_MASK		0x0004
#define VCORE_FAST_SLOW_SHIFT		2
#define VCORE_PWMB_MASK				0x0008
#define VCORE_PWMB_SHIFT			3
#define VCORE_ACC_OUT_INIT_MASK		0x00F0
#define VCORE_ACC_OUT_INIT_SHIFT	4
                 
// (0x848) VCORE CON2
#define VCORE_VOLSEL_MASK			0x4000
#define VCORE_VOLSEL_SHIFT			14
#define VCORE_FBEN_MASK				0x8000
#define VCORE_FBEN_SHIFT			15
                 
                 
// (0x84C) VCORE CON3
#define VCORE_CCI_VFBADJ_MASK		0x000F
#define VCORE_CCI_VFBADJ_SHIFT		0
#define VCORE_DIRECT_CTRL_EN_MASK	0x0010
#define VCORE_DIRECT_CTRL_EN_SHIFT	4
#define VCORE_DCVCKSEL_MASK			0x0020
#define VCORE_DCVCKSEL_SHIFT		5
#define VCORE_MODEEN_MASK			0x1800
#define VCORE_MODEEN_SHIFT			11
#define VCORE_MODECMP_MASK			0x2000
#define VCORE_MODECMP_SHIFT			13
#define VCORE_MODESEL1A_MASK		0x4000
#define VCORE_MODESEL1A_SHIFT		14
                 
// (0x854) VCORE CON5
#define VCORE_CCI_VFBADJ_SLP_MASK	0x000F
#define VCORE_CCI_VFBADJ_SLP_SHIFT	0
#define VCORE_CLK_SRC_SEL_MASK		0x0010
#define VCORE_CLK_SRC_SEL_SHIFT		4
                 
// (0x860) STARTUP CON0
#define UV_SEL_MASK					0x0003
#define UV_SEL_SHIFT				0
#define PWRKEY_VCORE_MASK			0x4000
#define PWRKEY_VCORE_SHIFT			14
#define PWRKEY_DEB_MASK				0x8000
#define PWRKEY_DEB_SHIFT			15
                 
// (0x864) STARTUP CON1
#define THR_SEL_MASK				0x0018
#define THR_SEL_SHIFT				3
                 
// (0x870) CHR CON0
#define CHR_EN_MASK					0x0001
#define CHR_EN_SHIFT				0
#define CHOFST_MASK					0x000E
#define CHOFST_SHIFT				1
#define CHR_CC_CURRENT_MASK			0x00F0
#define CHR_CC_CURRENT_SHIFT		4
#define CHRON_FORCE_MASK			0x0100
#define CHRON_FORCE_SHIFT			8
#define CV_RT_MASK					0x0600
#define CV_RT_SHIFT					9
#define CV_TUNE_MASK				0x3800
#define CV_TUNE_SHIFT				11
                 
// (0x874) CHR CON1
#define CAL_PRE_CC_MASK				0x0003
#define CAL_PRE_CC_SHIFT			0
#define PS_SEL_MASK					0x0040
#define PS_SEL_SHIFT				6
#define PS_SET_MASK					0x0080
#define PS_SET_SHIFT				7
#define CHROV_SEL_MASK				0x6000
#define CHROV_SEL_SHIFT				13
                 
// (0x878) CHR CON2
// We use CHR_RSV[0] as CV trim extra bit, the bit is the extension of CV_RT
// But only control in CV_TRIM_CALIBRATION process
#define CV_TRIM_EXTRA_MASK          0x0001
#define CV_TRIM_EXTRA_SHIFT         0        
#define OVP_MASK	        		0x0400
#define OVP_SHIFT					10
#define CHRDET_MASK					0x0800
#define CHRDET_SHIFT				11
#define BAT_ON_MASK					0x1000
#define BAT_ON_SHIFT				12
#define BAD_BATT_MASK				0x2000
#define BAD_BATT_SHIFT				13
#define CV_MASK		        				0x4000
#define CV_SHIFT	        				14
                 
// (0x87C) CHR CON3
#define WDTIMER_TD_MASK				0x0003
#define WDTIMER_TD_SHIFT			0
#define WDTIMER_EN_MASK				0x0004
#define WDTIMER_EN_SHIFT			2

// (0x8F0) CHR CON4 ==> Refer 0x8F0
#define WDTIMER_INT_EN_MASK			0x0001
#define WDTIMER_INT_EN_SHIFT		0
#define WDTIMER_FLAG_MASK			0x0002
#define WDTIMER_FLAG_SHIFT		    1
#define WDTIMER_CNT_19_16_MASK		0xF000
#define WDTIMER_CNT_19_16_SHIFT		12

// (0x8F4) CHR CON5 ==> Refer 0x8F4
#define WDTIMER_CNT_15_00_MASK		0xFFFF
#define WDTIMER_CNT_15_00_SHIFT		0

                 
// (0x880) DRIVER CON0
#define ISINKS_EN_MASK				0x0001
#define ISINKS_EN_SHIFT				0
#define ISINKS_FORCES_OFF_MASK		0x0002
#define ISINKS_FORCES_OFF_SHIFT		1
#define KPLED_TYPE_MASK				0x0004
#define KPLED_TYPE_SHIFT			2
#define CCI_KPLED_EN_MASK			0x0008
#define CCI_KPLED_EN_SHIFT			3
#define KPLED_FORCE_OFF_MASK		0x0010
#define KPLED_FORCE_OFF_SHIFT		4
#define KPLED_SEL_MASK				0x00E0
#define KPLED_SEL_SHIFT				5
#define ISINK1_STATUS_MASK			0x0800
#define ISINK1_STATUS_SHIFT			11
#define ISINK2_STATUS_MASK			0x1000
#define ISINK2_STATUS_SHIFT			12
#define ISINK3_STATUS_MASK			0x2000
#define ISINK3_STATUS_SHIFT			13
#define ISINK4_STATUS_MASK			0x4000
#define ISINK4_STATUS_SHIFT			14
#define KPLED_STATUS_MASK			0x8000
#define KPLED_STATUS_SHIFT			15
                 
// (0x884) DRIVER CON1
#define ISINKS_DIMM_MASK			0x001F
#define ISINKS_DIMM_SHIFT			0
#define ISINKS_CHSEL_MASK			0x0F00
#define ISINKS_CHSEL_SHIFT			8
                 
// (0x888) DRIVER CON2
#define ISINKS_IRSET_CAL_MASK		0x001F
#define ISINKS_IRSET_CAL_SHIFT		0
#define ISINKS_VLED_STEP_MASK		0x00C0
#define ISINKS_VLED_STEP_SHIFT		6
                 
// (0x88C) DRIVER CON3
#define VBL_EN_MASK					0x0001
#define VBL_EN_SHIFT				0
#define VBOOST_EN_MASK				0x0002
#define VBOOST_EN_SHIFT				1
#define BL_VGEN_FORCEON_MASK		0x0004
#define BL_VGEN_FORCEON_SHIFT		2
#define BL_MODE_MASK				0x0010
#define BL_MODE_SHIFT				4
#define BL_DIMM_DUTY_MASK			0x1F00
#define BL_DIMM_DUTY_SHIFT			8
                 
#if defined(__DRV_PMU53_SPEC_V1__)

// (0x890) DRIVER CON4
#define CCI_VIBR_EN_MASK			0x0001
#define CCI_VIBR_EN_SHIFT			0
#define VIBR_SEL_MASK				0x000C
#define VIBR_SEL_SHIFT				2
#define VIBR_CAL_MASK				0x00F0
#define VIBR_CAL_SHIFT				4
#define VIBR_OCFB_EN_MASK			0x1000
#define VIBR_OCFB_EN_SHIFT			12
#define VIBR_STATUS_MASK			0x8000
#define VIBR_STATUS_SHIFT			15
                 
#else // #if defined(__DRV_PMU53_SPEC_V1__)

// (0x890) VBT CON  ==> VBT move to 0x890
#define VBT_EN_MASK					0x0001
#define VBT_EN_SHIFT				0
#define VBT_SEL_MASK				0x000C
#define VBT_SEL_SHIFT				2
#define VBT_CAL_MASK				0x00F0
#define VBT_CAL_SHIFT				4
#define VBT_OCFB_EN_MASK			0x1000
#define VBT_OCFB_EN_SHIFT			12
#define VBT_STATUS_MASK				0x8000
#define VBT_STATUS_SHIFT			15

#endif // #if defined(__DRV_PMU53_SPEC_V1__)
                 
// (0x8A0) BOOST CON0
#define VBOOST_SYNC_EN_MASK			0x0001
#define VBOOST_SYNC_EN_SHIFT		0
#define VBOOST_SS_SPEED_MASK		0x0002
#define VBOOST_SS_SPEED_SHIFT		1
#define VBOOST_TUNE_MASK			0x00F0
#define VBOOST_TUNE_SHIFT			4
#define VBOOST_CAL_MASK				0x0F00
#define VBOOST_CAL_SHIFT			8
#define VBOOST_TRK_STATUS_MASK		0x4000
#define VBOOST_TRK_STATUS_SHIFT		14
#define VBOOST_STATUS_MASK			0x8000
#define VBOOST_STATUS_SHIFT			15
                 
// (0x8A4) BOOST CON1
#define VBOOST_ISNS_CAL_MASK		0x0007
#define VBOOST_ISNS_CAL_SHIFT		0
                 
// (0x8A8) BOOST CON2
#define VBOOST_FORCEON_CLK_MASK		0x0001
#define VBOOST_FORCEON_CLK_SHIFT	0
#define VBOOST_DISCLK_MASK			0x0002
#define VBOOST_DISCLK_SHIFT			1
#define VBOOST_I_SINK_CURRECT_MATCH 0x0009

                 
// (0x8B0) CLASSD CON0
#define SPK_EN_MASK					0x0001
#define SPK_EN_SHIFT				0
#define SPK_RST_MASK				0x0002
#define SPK_RST_SHIFT				1
#define SPK_EMODE_MASK				0x0004
#define SPK_EMODE_SHIFT				2
#define SPK_MODE_MASK				0x0008
#define SPK_MODE_SHIFT				3
#define SPKAB_FLOAT_MASK			0x0010
#define SPKAB_FLOAT_SHIFT			4
#define SPKAB_SENDED_MASK			0x0020
#define SPKAB_SENDED_SHIFT			5
#define SPKAB_OC_EN_MASK			0x0040
#define SPKAB_OC_EN_SHIFT			6
#define SPKAB_DEPOP_EN_MASK			0x0080
#define SPKAB_DEPOP_EN_SHIFT		7
#define SPKAB_OBIAS_MASK			0x0300
#define SPKAB_OBIAS_SHIFT			8
                 
// (0x8B4) CLASSD CON1
#define SPK_DTIN_MASK				0x000F
#define SPK_DTIN_SHIFT				0
#define SPK_DTIP_MASK				0x00F0
#define SPK_DTIP_SHIFT				4
#define SPK_DTCN_MASK				0x0F00
#define SPK_DTCN_SHIFT				8
#define SPK_DTCP_MASK				0xF000
#define SPK_DTCP_SHIFT				12
                 
// (0x8B8) CLASSD CON2
#define SPK_DMODE_MASK				0x0003
#define SPK_DMODE_SHIFT				0
#define SPK_PCHG_MASK				0x000C
#define SPK_PCHG_SHIFT				2
#define SPK_DTCAL_MASK				0x0010
#define SPK_DTCAL_SHIFT				4
#define SPK_PMODE_MASK				0x0020
#define SPK_PMODE_SHIFT				5
#define SPK_CMODE_MASK				0x00C0
#define SPK_CMODE_SHIFT				6
#define SPK_CCODE_MASK				0x0F00
#define SPK_CCODE_SHIFT				8
                 
// (0x8BC) CLASSD CON3
#define SPK_EN_VIEW_CLK_MASK		0x0001
#define SPK_EN_VIEW_CLK_SHIFT		0
#define SPK_EN_VIEW_VREF_MASK		0x0002
#define SPK_EN_VIEW_VREF_SHIFT		1
#define SPK_SLEW_MASK				0x000C
#define SPK_SLEW_SHIFT				2
#define SPK_OC_EN_MASK				0x0010
#define SPK_OC_EN_SHIFT				4
#define SPK_OSCISEL_MASK			0x0020
#define SPK_OSCISEL_SHIFT			5
#define SPK_VOL_MASK				0x0700
#define SPK_VOL_SHIFT				8

// (0x8C8) TEST CON2
#define ADC_TMR_MASK				0x0020
#define ADC_TMR_SHIFT				5
#define ADC_VBAT_OUT_EN_MASK		0x0040
#define ADC_VBAT_OUT_EN_SHIFT		6
#define ADC_ISENSE_OUT_EN_MASK		0x0080
#define ADC_ISENSE_OUT_EN_SHIFT		7
                 
// (0x8D0) OC CON0
#define VRF_OC_GEAR_MASK			0x0003
#define VRF_OC_GEAR_SHIFT			0
#define VRF_OC_AUTO_OFF_MASK		0x0004
#define VRF_OC_AUTO_OFF_SHIFT		2
#define VRF_OC_INT_EN_MASK			0x0008
#define VRF_OC_INT_EN_SHIFT			3
#define VIO_OC_GEAR_MASK			0x0030
#define VIO_OC_GEAR_SHIFT			4
#define VIO_OC_AUTO_OFF_MASK		0x0040
#define VIO_OC_AUTO_OFF_SHIFT		6
#define VIO_OC_INT_EN_MASK			0x0080
#define VIO_OC_INT_EN_SHIFT			7
#define VM_OC_GEAR_MASK				0x0300
#define VM_OC_GEAR_SHIFT			8
#define VM_OC_AUTO_OFF_MASK			0x0400
#define VM_OC_AUTO_OFF_SHIFT		10
#define VM_OC_INT_EN_MASK			0x0800
#define VM_OC_INT_EN_SHIFT			11
#define VA_OC_GEAR_MASK				0x3000
#define VA_OC_GEAR_SHIFT			12
#define VA_OC_AUTO_OFF_MASK			0x4000
#define VA_OC_AUTO_OFF_SHIFT		14
#define VA_OC_INT_EN_MASK			0x8000
#define VA_OC_INT_EN_SHIFT			15
                 
// (0x8D4) OC CON1
#define VTCXO_OC_GEAR_MASK				0x3000
#define VTCXO_OC_GEAR_SHIFT				12
#define VTCXO_OC_AUTO_OFF_MASK			0x4000
#define VTCXO_OC_AUTO_OFF_SHIFT			14
#define VTCXO_OC_INT_EN_MASK			0x8000
#define VTCXO_OC_INT_EN_SHIFT			15
                 
// (0x8D8) OC CON2
#define VBT_OC_GEAR_MASK			0x0003
#define VBT_OC_GEAR_SHIFT			0
#define VBT_OC_AUTO_OFF_MASK		0x0004
#define VBT_OC_AUTO_OFF_SHIFT		2
#define VBT_OC_INT_EN_MASK			0x0008
#define VBT_OC_INT_EN_SHIFT			3
#define VUSB_OC_GEAR_MASK			0x0030
#define VUSB_OC_GEAR_SHIFT			4
#define VUSB_OC_AUTO_OFF_MASK		0x0040
#define VUSB_OC_AUTO_OFF_SHIFT		6
#define VUSB_OC_INT_EN_MASK			0x0080
#define VUSB_OC_INT_EN_SHIFT			7
#define VCAMD_OC_GEAR_MASK				0x0300
#define VCAMD_OC_GEAR_SHIFT			8
#define VCAMD_OC_AUTO_OFF_MASK			0x0400
#define VCAMD_OC_AUTO_OFF_SHIFT		10
#define VCAMD_OC_INT_EN_MASK			0x0800
#define VCAMD_OC_INT_EN_SHIFT			11
#define VCAMA_OC_GEAR_MASK				0x3000
#define VCAMA_OC_GEAR_SHIFT			12
#define VCAMA_OC_AUTO_OFF_MASK			0x4000
#define VCAMA_OC_AUTO_OFF_SHIFT		14
#define VCAMA_OC_INT_EN_MASK			0x8000
#define VCAMA_OC_INT_EN_SHIFT			15

// (0x8DC) OC CON3
#define VSPK_OC_GEAR_MASK			0x0003
#define VSPK_OC_GEAR_SHIFT			0
#define VSPK_OC_AUTO_OFF_MASK		0x0004
#define VSPK_OC_AUTO_OFF_SHIFT		2
#define VSPK_OC_INT_EN_MASK			0x0008
#define VSPK_OC_INT_EN_SHIFT			3
#define VIBR_OC_GEAR_MASK			0x0030
#define VIBR_OC_GEAR_SHIFT			4
#define VIBR_OC_AUTO_OFF_MASK		0x0040
#define VIBR_OC_AUTO_OFF_SHIFT		6
#define VIBR_OC_INT_EN_MASK			0x0080
#define VIBR_OC_INT_EN_SHIFT			7
#define VBOOST_OC_GEAR_MASK				0x0300
#define VBOOST_OC_GEAR_SHIFT			8
#define VBOOST_OC_AUTO_OFF_MASK			0x0400
#define VBOOST_OC_AUTO_OFF_SHIFT		10
#define VBOOST_OC_INT_EN_MASK			0x0800
#define VBOOST_OC_INT_EN_SHIFT			11
#define VSIM_OC_GEAR_MASK				0x3000
#define VSIM_OC_GEAR_SHIFT			12
#define VSIM_OC_AUTO_OFF_MASK			0x4000
#define VSIM_OC_AUTO_OFF_SHIFT		14
#define VSIM_OC_INT_EN_MASK			0x8000
#define VSIM_OC_INT_EN_SHIFT			15

// (0x8E0) OC CON4
#define VIBR_STBTD_MASK				0x0003
#define VIBR_STBTD_SHIFT			0
#define VSIM_STBTD_MASK				0x000C
#define VSIM_STBTD_SHIFT			2
#define VBT_STBTD_MASK				0x0030
#define VBT_STBTD_SHIFT				4
#define VUSB_STBTD_MASK				0x00C0
#define VUSB_STBTD_SHIFT			6
#define VCAMD_STBTD_MASK			0x0300
#define VCAMD_STBTD_SHIFT			8
#define VCAMA_STBTD_MASK			0x0C00
#define VCAMA_STBTD_SHIFT			10

// (0x8E4) OC CON5
#define SPK_OC_FLAG_MASK			0x0001
#define SPK_OC_FLAG_SHIFT			0
#define VIBR_OC_FLAG_MASK			0x0002
#define VIBR_OC_FLAG_SHIFT			1
#define VBOOST_OC_FLAG_MASK			0x0004
#define VBOOST_OC_FLAG_SHIFT		2
#define VSIM_OC_FLAG_MASK			0x0008
#define VSIM_OC_FLAG_SHIFT			3
#define VBT_OC_FLAG_MASK			0x0010
#define VBT_OC_FLAG_SHIFT			4
#define VUSB_OC_FLAG_MASK			0x0020
#define VUSB_OC_FLAG_SHIFT			5
#define VCAMD_OC_FLAG_MASK			0x0040
#define VCAMD_OC_FLAG_SHIFT			6
#define VCAMA_OC_FLAG_MASK			0x0080
#define VCAMA_OC_FLAG_SHIFT			7
#define VTCXO_OC_FLAG_MASK			0x0800
#define VTCXO_OC_FLAG_SHIFT			11
#define VRF_OC_FLAG_MASK			0x1000
#define VRF_OC_FLAG_SHIFT			12
#define VIO_OC_FLAG_MASK			0x2000
#define VIO_OC_FLAG_SHIFT			13
#define VM_OC_FLAG_MASK				0x4000
#define VM_OC_FLAG_SHIFT			14
#define VA_OC_FLAG_MASK				0x8000
#define VA_OC_FLAG_SHIFT			15


// (0x8F0) CHR CON4

// (0x8F4) CHR CON5

#endif // #if defined(PMIC_6253_REG_API)


#endif // #ifndef __DCL_PMIC6253_HW_H_STRUCT__




