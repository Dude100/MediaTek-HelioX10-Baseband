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
 *    dcl_pmu6326_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC6326
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMIC6326_HW_H_STRUCT__
#define __DCL_PMIC6326_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6326_REG_API)


#define BIT00		0x00000001
#define BIT01		0x00000002
#define BIT02		0x00000004
#define BIT03		0x00000008

#define BIT04		0x00000010
#define BIT05		0x00000020
#define BIT06		0x00000040
#define BIT07		0x00000080

#define BIT08		0x00000100
#define BIT09		0x00000200
#define BIT10		0x00000400
#define BIT11		0x00000800

#define BIT12		0x00001000
#define BIT13		0x00002000
#define BIT14		0x00004000
#define BIT15		0x00008000

#define BIT16		0x00010000
#define BIT17		0x00020000
#define BIT18		0x00040000
#define BIT19		0x00080000

#define BIT20		0x00100000
#define BIT21		0x00200000
#define BIT22		0x00400000
#define BIT23		0x00800000

#define BIT24		0x01000000
#define BIT25		0x02000000
#define BIT26		0x04000000
#define BIT27		0x08000000

#define BIT28		0x10000000
#define BIT29		0x20000000
#define BIT30		0x40000000
#define BIT31		0x80000000


#define PMIC6326_E1_CID_CODE		0x0000
#define PMIC6326_E2_CID_CODE		0x0009
#define PMIC6326_E3_CID_CODE		0x000A
#define PMIC6326_E4_CID_CODE		0x000B

#define CID_1_REG_INDEX				0x0
#define CID_2_REG_INDEX				0x1

#define EFUSE_BUFF_4_REG_INDEX      0x12

#define PMIC_MAX_REG_IDX				0x96
#define PMIC_REG_NUM						0x97	// ###***** PMIC_REG_NUM must equal (PMIC_MAX_REG_IDX + 1)


// (0x09) STATUS 6 (RO)
#define BOOST2_OC_STATUS_MASK			0x1
#define BOOST2_OC_STATUS_SHIFT		0x0
#define SPKR_OC_DET_MASK				0x1
#define SPKR_OC_DET_SHIFT				0x1
#define SPKL_OC_DET_MASK				0x1
#define SPKL_OC_DET_SHIFT				0x2
#define PWRKEY_DEB_MASK					0x1
#define PWRKEY_DEB_SHIFT				0x3
#define OVP_MASK							0x1
#define OVP_SHIFT							0x4
#define CHRDET_MASK						0x1
#define CHRDET_SHIFT						0x5
#define BAT_ON_MASK						0x1
#define BAT_ON_SHIFT						0x6
#define CV_MASK							0x1
#define CV_SHIFT							0x7

// (0x0D) INT STATUS 3 (RO)
#define VSDIO_OC_FLAG_STATUS_MASK		0x1
#define VSDIO_OC_FLAG_STATUS_SHIFT		0x0
#define VGP_OC_FLAG_STATUS_MASK			0x1
#define VGP_OC_FLAG_STATUS_SHIFT			0x1
#define VUSB_OC_FLAG_STATUS_MASK			0x1
#define VUSB_OC_FLAG_STATUS_SHIFT		0x2
#define OVP_INT_FLAG_STATUS_MASK			0x1
#define OVP_INT_FLAG_STATUS_SHIFT		0x3
#define CHRDET_INT_FLAG_STATUS_MASK		0x1
#define CHRDET_INT_FLAG_STATUS_SHIFT	0x4

// (0x0E) INT STATUS 4 (RO)
#define WATCHDOG_INT_FLAG_STATUS_MASK	0x1
#define WATCHDOG_INT_FLAG_STATUS_SHIFT	0x0

// (0x1A) LDO CTRL 1 VGP2
#define VGP2_EN_MASK						0x1
#define VGP2_EN_SHIFT					0x2
// (0x1B) LDO CTRL 2 VRF
#define VRF_ICAL_EN_MASK				0x3
#define VRF_ICAL_EN_SHIFT				0x0
#define VRF_OC_AUTO_OFF_MASK			0x1
#define VRF_OC_AUTO_OFF_SHIFT			0x1
#define VRF_EN_MASK						0x1
#define VRF_EN_SHIFT						0x3
#define VRF_CAL_MASK						0xF
#define VRF_CAL_SHIFT					0x4

// (0x1C) LDO CTRL 3 VRF
#define VRF_CALST_MASK					0x3
#define VRF_CALST_SHIFT					0x0
#define VRF_CALOC_MASK					0x3
#define VRF_CALOC_SHIFT					0x2
#define VRF_ON_SEL_MASK					0x1
#define VRF_ON_SEL_SHIFT				0x4
#define VRF_EN_FORCE_MASK				0x1
#define VRF_EN_FORCE_SHIFT				0x5
#define VRF_PLNMOS_DIS_MASK			0x1
#define VRF_PLNMOS_DIS_SHIFT			0x6
#define VRF_CM_MASK						0x1
#define VRF_CM_SHIFT						0x7
// (0x1E) LDO CTRL 5 VTCXO
#define VTCXO_ICAL_EN_MASK				0x3
#define VTCXO_ICAL_EN_SHIFT			0x0
#define VTCXO_OC_AUTO_OFF_MASK		0x1
#define VTCXO_OC_AUTO_OFF_SHIFT		0x2
#define VTCXO_EN_MASK					0x1
#define VTCXO_EN_SHIFT					0x3
#define VTCXO_CAL_MASK					0xF
#define VTCXO_CAL_SHIFT					0x4
// (0x1F) LDO CTRL 6 VTCXO
#define VTCXO_CALST_MASK				0x3
#define VTCXO_CALST_SHIFT				0x0
#define VTCXO_CALOC_MASK				0x3
#define VTCXO_CALOC_SHIFT				0x2
#define VTCXO_ON_SEL_MASK				0x1
#define VTCXO_ON_SEL_SHIFT				0x4
#define VTCXO_EN_FORCE_MASK			0x1
#define VTCXO_EN_FORCE_SHIFT			0x5
#define VTCXO_PLNMOS_DIS_MASK			0x1
#define VTCXO_PLNMOS_DIS_SHIFT		0x6
#define VTCXO_CM_MASK					0x1
#define VTCXO_CM_SHIFT					0x7
// (0x21) LDO CTRL 8 V3GTX
#define V3GTX_SEL_MASK					0x3
#define V3GTX_SEL_SHIFT					0x0
#define V3GTX_ICAL_EN_MASK				0x3
#define V3GTX_ICAL_EN_SHIFT			0x2
#define V3GTX_CAL_MASK					0xF
#define V3GTX_CAL_SHIFT					0x4
// (0x22) LDO CTRL 9 V3GTX
#define V3GTX_CALST_MASK				0x3
#define V3GTX_CALST_SHIFT				0x0
#define V3GTX_CALOC_MASK				0x3
#define V3GTX_CALOC_SHIFT				0x2
#define V3GTX_OC_AUTO_OFF_MASK		0x1
#define V3GTX_OC_AUTO_OFF_SHIFT		0x4
#define V3GTX_EN_MASK					0x1
#define V3GTX_EN_SHIFT					0x5
#define V3GTX_ON_SEL_MASK				0x1
#define V3GTX_ON_SEL_SHIFT				0x6
#define V3GTX_EN_FORCE_MASK			0x1
#define V3GTX_EN_FORCE_SHIFT			0x7

// (0X23) LDO CTRL 10 V3GTX
#define V3GTX_PLNMOS_DIS_MASK			0x1
#define V3GTX_PLNMOS_DIS_SHIFT			0x0

// (0x24) LDO CTRL 11 V3GRX
#define V3GRX_SEL_MASK					0x3
#define V3GRX_SEL_SHIFT					0x0
#define V3GRX_ICAL_EN_MASK				0x3
#define V3GRX_ICAL_EN_SHIFT			0x2
#define V3GRX_CAL_MASK					0xf
#define V3GRX_CAL_SHIFT					0x4
// (0x25) LDO CTRL 12 V3GRX
#define V3GRX_CALST_MASK				0x3
#define V3GRX_CALST_SHIFT				0x0
#define V3GRX_CALOC_MASK				0x3
#define V3GRX_CALOC_SHIFT				0x2
#define V3GRX_OC_AUTO_OFF_MASK		0x1
#define V3GRX_OC_AUTO_OFF_SHIFT		0x4
#define V3GRX_EN_MASK					0x1
#define V3GRX_EN_SHIFT					0x5
#define V3GRX_ON_SEL_MASK				0x1
#define V3GRX_ON_SEL_SHIFT				0x6
#define V3GRX_EN_FORCE_MASK			0x1
#define V3GRX_EN_FORCE_SHIFT			0x7

// (0X26) LDO CTRL 10 V3GRX
#define V3GRX_PLNMOS_DIS_MASK			0x1
#define V3GRX_PLNMOS_DIS_SHIFT			0x0


// (0x2E) LDO CTRL 21 VCAMA
#define VCAMA_SEL_MASK					0x3
#define VCAMA_SEL_SHIFT					0x0
#define VCAMA_ICAL_EN_MASK				0x3
#define VCAMA_ICAL_EN_SHIFT			0x2
#define VCAMA_CAL_MASK					0xf
#define VCAMA_CAL_SHIFT					0x4
// (0x2F) LDO CTRL 22 VCAMA
#define VCAMA_CALST_MASK				0x3
#define VCAMA_CALST_SHIFT				0x0
#define VCAMA_CALOC_MASK				0x3
#define VCAMA_CALOC_SHIFT				0x2
#define VCAMA_EN_MASK					0x1
#define VCAMA_EN_SHIFT					0x4
#define VCAMA_EN_FORCE_MASK			0x1
#define VCAMA_EN_FORCE_SHIFT			0x5
#define VCAMA_PLNMOS_DIS_MASK			0x1
#define VCAMA_PLNMOS_DIS_SHIFT		0x6
#define VCAMA_CM_MASK					0x1
#define VCAMA_CM_SHIFT					0x7

// (0x31) LDO CTRL 24 VWIFI3V3
#define VWIFI3V3_SEL_MASK					0x3
#define VWIFI3V3_SEL_SHIFT					0x0
#define VWIFI3V3_ICAL_EN_MASK				0x3
#define VWIFI3V3_ICAL_EN_SHIFT			0x2
#define VWIFI3V3_CAL_MASK					0xf
#define VWIFI3V3_CAL_SHIFT					0x4
// (0x32) LDO CTRL 25 VWIFI3V3
#define VWIFI3V3_CALST_MASK				0x3
#define VWIFI3V3_CALST_SHIFT				0x0
#define VWIFI3V3_CALOC_MASK				0x3
#define VWIFI3V3_CALOC_SHIFT				0x2
#define VWIFI3V3_EN_MASK					0x1
#define VWIFI3V3_EN_SHIFT					0x4
#define VWIFI3V3_EN_FORCE_MASK			0x1
#define VWIFI3V3_EN_FORCE_SHIFT			0x5
#define VWIFI3V3_PLNMOS_DIS_MASK			0x1
#define VWIFI3V3_PLNMOS_DIS_SHIFT		0x6
#define VWIFI3V3_CM_MASK					0x1
#define VWIFI3V3_CM_SHIFT					0x7

// (0x34) LDO CTRL 27 VWIFI2V8
#define VWIFI2V8_SEL_MASK					0x3
#define VWIFI2V8_SEL_SHIFT					0x0
#define VWIFI2V8_ICAL_EN_MASK				0x3
#define VWIFI2V8_ICAL_EN_SHIFT			0x2
#define VWIFI2V8_CAL_MASK					0xf
#define VWIFI2V8_CAL_SHIFT					0x4

// (0x35) LDO CTRL 28 VWIFI2V8
#define VWIFI2V8_CALST_MASK				0x3
#define VWIFI2V8_CALST_SHIFT				0x0
#define VWIFI2V8_CALOC_MASK				0x3
#define VWIFI2V8_CALOC_SHIFT				0x2
#define VWIFI2V8_EN_MASK					0x1
#define VWIFI2V8_EN_SHIFT					0x4
#define VWIFI2V8_EN_FORCE_MASK			0x1
#define VWIFI2V8_EN_FORCE_SHIFT			0x5
#define VWIFI2V8_PLNMOS_DIS_MASK			0x1
#define VWIFI2V8_PLNMOS_DIS_SHIFT		0x6
#define VWIFI2V8_CM_MASK					0x1
#define VWIFI2V8_CM_SHIFT					0x7


// (0x37) LDO CTRL 30 VSIM
#define VSIM_SEL_MASK					0x7
#define VSIM_SEL_SHIFT					0x0
#define VSIM_EN_MASK						0x1
#define VSIM_EN_SHIFT					0x3
#define VSIM_ICAL_EN_MASK				0x3
#define VSIM_ICAL_EN_SHIFT				0x4
#define VSIM_EN_FORCE_MASK				0x1
#define VSIM_EN_FORCE_SHIFT			0x6
#define VSIM_PLNMOS_DIS_MASK			0x1
#define VSIM_PLNMOS_DIS_SHIFT			0x7

// (0x38) LDO CTRL 31 VSIM
#define VSIM_CAL_MASK					0xf
#define VSIM_CAL_SHIFT					0x0

// (0x3A) LDO CTRL 33 VUSB (From E3, USB LDO controls are moved to 0x3D ~ 0x3F)

   // From E3, VGP2 OCFB enable control is at 0x3D
#define VGP2_OCFB_EN_MASK               0x1
#define VGP2_OCFB_EN_SHIFT              0x0

#define VUSB_SEL_MASK					0x7
#define VUSB_SEL_SHIFT					0x0
#define VUSB_EN_MASK						0x1
#define VUSB_EN_SHIFT					0x3
#define VUSB_ICAL_EN_MASK				0x3
#define VUSB_ICAL_EN_SHIFT				0x4
#define VUSB_EN_FORCE_MASK				0x1
#define VUSB_EN_FORCE_SHIFT			0x6
#define VUSB_PLNMOS_DIS_MASK			0x1
#define VUSB_PLNMOS_DIS_SHIFT			0x7

// (0x3B) LDO CTRL 34 VUSB (From E3, USB LDO controls are moved to 0x3D ~ 0x3F)
#define VUSB_CAL_MASK					0xf
#define VUSB_CAL_SHIFT					0x0
#define VUSB_CALST_MASK					0x3
#define VUSB_CALST_SHIFT				0x4
#define VUSB_CALOC_MASK					0x3
#define VUSB_CALOC_SHIFT				0x6

// (0x3D) LDO CTRL 36 VBT (From E3, BT LDO controls are moved to 0x3A ~ 0x3C)
#define VBT_SEL_MASK						0x7
#define VBT_SEL_SHIFT					0x0
#define VBT_EN_MASK						0x1
#define VBT_EN_SHIFT						0x3
#define VBT_ICAL_EN_MASK				0x3
#define VBT_ICAL_EN_SHIFT				0x4
#define VBT_EN_FORCE_MASK				0x1
#define VBT_EN_FORCE_SHIFT				0x6
#define VBT_PLNMOS_DIS_MASK			0x1
#define VBT_PLNMOS_DIS_SHIFT			0x7

// (0x3E) LDO CTRL 37 VBT (From E3, BT LDO controls are moved to 0x3A ~ 0x3C)
#define VBT_CAL_MASK						0xf
#define VBT_CAL_SHIFT					0x0
#define VBT_CALST_MASK					0x3
#define VBT_CALST_SHIFT					0x4
#define VBT_CALOC_MASK					0x3
#define VBT_CALOC_SHIFT					0x6

// (0x40) LDO CTRL 39 VCAMD
#define VCAMD_SEL_MASK						0x7
#define VCAMD_SEL_SHIFT						0x0
#define VCAMD_EN_MASK						0x1
#define VCAMD_EN_SHIFT						0x3
#define VCAMD_ICAL_EN_MASK					0x3
#define VCAMD_ICAL_EN_SHIFT				0x4
#define VCAMD_EN_FORCE_MASK				0x1
#define VCAMD_EN_FORCE_SHIFT				0x6
#define VCAMD_PLNMOS_DIS_MASK				0x1
#define VCAMD_PLNMOS_DIS_SHIFT			0x7

// (0x41) LDO CTRL 40 VCAMD
#define VCAMD_CAL_MASK						0xf
#define VCAMD_CAL_SHIFT						0x0
#define VCAMD_CALST_MASK					0x3
#define VCAMD_CALST_SHIFT					0x4
#define VCAMD_CALOC_MASK					0x3
#define VCAMD_CALOC_SHIFT					0x6

// (0x43) LDO CTRL 42 VGP
#define VGP_SEL_MASK							0x7
#define VGP_SEL_SHIFT						0x0
#define VGP_EN_MASK							0x1
#define VGP_EN_SHIFT							0x3
#define VGP_PLNMOS_DIS_MASK					0x1
#define VGP_PLNMOS_DIS_SHIFT				0x7

// (0x44) LDO CTRL 43 VGP
#define VGP_CAL_MASK							0xf
#define VGP_CAL_SHIFT						0x0

// (0x46) LDO CTRL 45 VSDIO
#define VSDIO_ICAL_EN_MASK					0x3
#define VSDIO_ICAL_EN_SHIFT				0x0
#define VSDIO_EN_MASK						0x1
#define VSDIO_EN_SHIFT						0x2
#define VSDIO_EN_FORCE_MASK				0x1
#define VSDIO_EN_FORCE_SHIFT				0x3
#define VSDIO_CAL_MASK						0xf
#define VSDIO_CAL_SHIFT						0x4

// (0x47) LDO CTRL 46 VSDIO
#define VSDIO_CALST_MASK					0x3
#define VSDIO_CALST_SHIFT					0x0
#define VSDIO_CALOC_MASK					0x3
#define VSDIO_CALOC_SHIFT					0x2
#define VSDIO_PLNMOS_DIS_MASK				0x1
#define VSDIO_PLNMOS_DIS_SHIFT			0x4
#define VSDIO_SEL_MASK						0x1
#define VSDIO_SEL_SHIFT						0x5
#define VSDIO_CM_MASK						0x1
#define VSDIO_CM_SHIFT						0x6

// (0x48) LDO CTRL 47 VSDIO
#define VCORE1_DVFS_STEP_INC_MASK		0x1f
#define VCORE1_DVFS_STEP_INC_SHIFT		0x3

// (0x49) BULK CTRL 1 VGP2 (SEL L)
#define VGP2_SELL_MASK					0x3
#define VGP2_SELL_SHIFT					0x4

// (0x4B) BULK CTRL 3 VGP2 (SEL H)
#define VGP2_SELH_MASK					0x1
#define VGP2_SELH_SHIFT					0x4

// (0x4E) BUCK CTRL 6 VCORE1
#define VCORE1_DVFS_0_ECO3_MASK		0xf
#define VCORE1_DVFS_0_ECO3_SHIFT		0x4

// (0x4F) BUCK CTRL 7 VCORE1
#define VCORE1_SLEEP_0_ECO3_MASK		0x1
#define VCORE1_SLEEP_0_ECO3_SHIFT	0x3
#define VCORE1_DVFS_RAMP_EN_MASK		0x1
#define VCORE1_DVFS_RAMP_EN_SHIFT	0x6
#define VCORE1_DVFS_TARGET_UPDATE_MASK			0x1
#define VCORE1_DVFS_TARGET_UPDATE_SHIFT		0x7

// (0x51) BUCK CTRL 9 VCORE2
#define VCORE2_DVFS_0_ECO3_MASK			0x4
#define VCORE2_DVFS_0_ECO3_SHIFT		0xF

// (0x52) BUCK CTRL 10 VCORE2
#define VCORE2_EN_MASK					0x1
#define VCORE2_EN_SHIFT					0x7
#define VCORE2_SLEEP_0_ECO3_MASK		0x1
#define VCORE2_SLEEP_0_ECO3_SHIFT		0x3



// (0x53) BUCK CTRL 11 VCORE2
#define VCORE2_ON_SEL_MASK				0x1
#define VCORE2_ON_SEL_SHIFT			0x3

// (0x54)
#define VCORE2_PLNMOS_DIS_MASK			0x1			
#define VCORE2_PLNMOS_DIS_SHIFT			0x0


// (0x57) BUCK CTRL 15 VMEM
#define VCORE1_SLEEP_1_ECO3_MASK		0x1
#define VCORE1_SLEEP_1_ECO3_SHIFT	0x0
#define VCORE1_DVFS_1_ECO3_MASK		0xf
#define VCORE1_DVFS_1_ECO3_SHIFT		0x4

// (0x58) BULK CTRL 16 VPA
#define VPA_TUNEH_MASK					0x1F
#define VPA_TUNEH_SHIFT					0x0
#define VPA_EN_FORCE_MASK				0x1
#define VPA_EN_FORCE_SHIFT				0x5
#define VPA_PLNMOS_DIS_MASK			0x1
#define VPA_PLNMOS_DIS_SHIFT			0x6
#define VPA_EN_MASK						0x1
#define VPA_EN_SHIFT						0x7

// (0x59) BULK CTRL 17 VPA
#define VPA_TUNEL_MASK					0x1F
#define VPA_TUNEL_SHIFT					0x0

// (0x5A) BUCK CTRL 18 VPA
#define VPA_OC_TH_MASK					0x7
#define VPA_OC_TH_SHIFT					0x0


#define VPA_BAT_LOW_MASK                0x1
#define VPA_BAT_LOW_SHIFT               0x3

// (0x5C) BOOST CTRL 1 BOOST1
#define VBOOST1_TUNE_MASK				0xF
#define VBOOST1_TUNE_SHIFT				0x0
#define VBOOST1_TATT_MASK				0xF
#define VBOOST1_TATT_SHIFT				0x4

// (0x5D) BOOST CTRL 2 BOOST1
#define BOOST1_OC_TH_MASK				0x7
#define BOOST1_OC_TH_SHIFT				0x0
#define BOOST1_EN_MASK					0x1
#define BOOST1_EN_SHIFT					0x3
#define BOOST1_PRE_SR_CON_MASK		0x7
#define BOOST1_PRE_SR_CON_SHIFT		0x4
#define BOOST1_SOFT_ST_SPEED_MASK	0x1
#define BOOST1_SOFT_ST_SPEED_SHIFT	0x7

// (0x5E) BOOST CTRL 3 BOOST1
#define BOOST1_DIO_SR_CON_MASK		0x7
#define BOOST1_DIO_SR_CON_SHIFT		0x0
#define BOOST1_SYNC_EN_MASK			0x1
#define BOOST1_SYNC_EN_SHIFT			0x3
// #### D4 is used as VGP2_SEL[2]

// (0x5F) BOOST CTRL 4 BOOST2
#define BOOST2_TUNE_MASK			0xF
#define BOOST2_TUNE_SHIFT			0x0
#define BOOST2_OC_TH_MASK			0x3
#define BOOST2_OC_TH_SHIFT			0x4
#define BOOST2_DIM_SOURCE_MASK		0x1
#define BOOST2_DIM_SOURCE_SHIFT		0x6

// (0x60) BOOST CTRL 5 BOOST2
#define BOOST2_PRE_SR_CON_MASK		0x7
#define BOOST2_PRE_SR_CON_SHIFT		0x0
#define BOOST2_EN_MASK				0x1
#define BOOST2_EN_SHIFT				0x4

// (0x61) BOOST CTRL 6 BOOST2 and BOOST
#define BOOST_MODE_MASK					0x3
#define BOOST_MODE_SHIFT				0x4

// (0x63) DRIVER CTRL 2
#define VBUS_EN_MASK				0x1
#define VBUS_EN_SHIFT				0x0


// (0x64) DRIVER CTRL 3 GEN
#define IGEN_DRV_ISEL_MASK				0x3
#define IGEN_DRV_ISEL_SHIFT			0x0
#define IGEN_DRV_FORCE_MASK			0x4
#define IGEN_DRV_FORCE_SHIFT			0x2
#define VGEN_DRV_BGSEL_MASK			0x7
#define VGEN_DRV_BGSEL_SHIFT			0x4

// (0x65) DRIVER CTRL 4 FLASH
#define FLASH_I_TUNE_MASK		0xf
#define FLASH_I_TUNE_SHIFT		0x0
#define FLASH_DIM_DIV_MASK				0xf
#define FLASH_DIM_DIV_SHIFT			0x4

// (0x66) DRIVER CTRL 5 FLASH
#define FLASH_DIM_DUTY_MASK			0x1F
#define FLASH_DIM_DUTY_SHIFT			0x0
#define FLASH_EN_MASK					0x1
#define FLASH_EN_SHIFT					0x5
#define FLASH_BYPASS_MASK				0x1
#define FLASH_BYPASS_SHIFT				0x6

// (0x67) DRIVER CTRL 6 BL
#define BL_DIM_DUTY_MASK				0x1F
#define BL_DIM_DUTY_SHIFT				0x0
#define BL_EN_MASK						0x1
#define BL_EN_SHIFT						0x5
#define BL_I_CAL_EN_MASK				0x1
#define BL_I_CAL_EN_SHIFT				0x6
#define BL_BYPASS_MASK					0x1
#define BL_BYPASS_SHIFT					0x7

// (0x68) DRIVER CTRL 7 BL
#define BL_I_CORSE_TUNE_MASK			0x7
#define BL_I_CORSE_TUNE_SHIFT			0x0
#define BL_I_FINE_TUNE_MASK			0x7
#define BL_I_FINE_TUNE_SHIFT			0x4

// (0x6D) DRIVER CTRL 12 BL
#define BL_DIM_DIV_MASK					0xF
#define BL_DIM_DIV_SHIFT				0x0
#define BL_NUMBER_MASK					0x7
#define BL_NUMBER_SHIFT					0x4

// (0x6E) DRIVER CTRL 13 KP
#define KP_DIM_DIV_MASK					0xF
#define KP_DIM_DIV_SHIFT				0x0
#define KP_EN_MASK						0x1
#define KP_EN_SHIFT						0x4

// (0x6F) DRIVER CTRL 14 KP
#define KP_DIM_DUTY_MASK				0x1F
#define KP_DIM_DUTY_SHIFT				0x0

// (0x70) DRIVER CTRL 15 VIBR
#define VIBR_DIM_DIV_MASK				0xF
#define VIBR_DIM_DIV_SHIFT				0x0
#define VIBR_EN_MASK						0x1
#define VIBR_EN_SHIFT					0x4

// (0x71) DRIVER CTRL 16 VIBR
#define VIBR_DIM_DUTY_MASK				0x1F
#define VIBR_DIM_DUTY_SHIFT			0x0

// (0x72) DRIVER CTRL 17
#define DIM_CK_FORCE_ON_MASK			0x1
#define DIM_CK_FORCE_ON_SHIFT			0x0

// (0x73) CLASS_D CTRL 3 SPKL
#define SPKL_DTIN_MASK					0xf
#define SPKL_DTIN_SHIFT					0x0
#define SPKL_DTIP_MASK					0xf
#define SPKL_DTIP_SHIFT					0x4

// (0x74) CLASS_D CTRL 4 SPKL
#define SPKL_DMODE_MASK					0x3
#define SPKL_DMODE_SHIFT				0x2
#define SPKL_EN_MASK						0x1
#define SPKL_EN_SHIFT					0x6
#define SPKL_DTCAL_MASK					0x1
#define SPKL_DTCAL_SHIFT				0x7

// (0x75) CLASS_D CTRL 5 SPKL
#define SPKL_SLEW_MASK					0x3
#define SPKL_SLEW_SHIFT				    0x6

// (0x76) CLASS_D CTRL 6 SPKL
#define SPKL_VOL_MASK					0x7
#define SPKL_VOL_SHIFT				    0x0

// (0x77) CLASS_D CTRL 7 SPKL
#define SPKL_OC_MASK					0x1
#define SPKL_OC_SHIFT					0x0


// (0x78) CLASS_D CTRL 8 SPKR
#define SPKR_DTIN_MASK					0xf
#define SPKR_DTIN_SHIFT					0x0
#define SPKR_DTIP_MASK					0xf
#define SPKR_DTIP_SHIFT					0x4

// (0x79) CLASS_D CTRL 9 SPKR
#define SPKR_DMODE_MASK					0x3
#define SPKR_DMODE_SHIFT				0x2
#define SPKR_EN_MASK						0x1
#define SPKR_EN_SHIFT					0x6
#define SPKR_DTCAL_MASK					0x1
#define SPKR_DTCAL_SHIFT				0x7

// (0x7A) CLASS_D CTRL 10 SPKR
#define SPKR_SLEW_MASK					0x3
#define SPKR_SLEW_SHIFT				    0x6


// (0x7B) CLASS_D CTRL 11 SPKR
#define SPKR_VOL_MASK					0x7
#define SPKR_VOL_SHIFT				    0x0

// (0x7C) CLASS_D CTRL 12 SPKR
#define SPKR_OC_MASK					0x1
#define SPKR_OC_SHIFT					0x0



// (0x81) CHARGER CTRL 1
#define CHR_CHOFST_MASK					0x7
#define CHR_CHOFST_SHIFT				0x0
#define CHR_OV_TH_HIGH_MASK			0x1
#define CHR_OV_TH_HIGH_SHIFT			0x3
#define CHR_CHR_CURRENT_MASK			0x7
#define CHR_CHR_CURRENT_SHIFT			0x4
#define CHR_OV_TH_FREEZE_MASK			0x1
#define CHR_OV_TH_FREEZE_SHIFT		0x7

// (0x82) CHARGER CTRL 2
#define CHR_CV_RT_MASK					0x3
#define CHR_CV_RT_SHIFT					0x0
#define CHR_CHRON_FORCE_MASK			0x1
#define CHR_CHRON_FORCE_SHIFT			0x2
#define CHR_CHR_EN_MASK					0x1
#define CHR_CHR_EN_SHIFT				0x3
#define CHR_CV_TUNE_MASK				0x7
#define CHR_CV_TUNE_SHIFT				0x4


// (0x83) TESTMODE CTRL 3 Analog Switch
#define ASW_ASEL_MASK					0x3
#define ASW_ASEL_SHIFT					0x0
#define ASW_BSEL_MASK					0x3
#define ASW_BSEL_SHIFT					0x2
#define ASW_A1_SEL_MASK					0x1
#define ASW_A1_SEL_SHIFT				0x4
#define ASW_A2_SEL_MASK					0x1
#define ASW_A2_SEL_SHIFT				0x5


// (0x84) TESTMODE CTRL 4 Testmode
#define VGP2_ON_SEL_MASK				0x1
#define VGP2_ON_SEL_SHIFT				0x7



// (0x86) TESTMODE CTRL 6 BB AUXADC Related
#define ADC_ISENSE_OUT_EN_MASK		0x1
#define ADC_ISENSE_OUT_EN_SHIFT		0x0
#define ADC_VBAT_OUT_EN_MASK			0x1
#define ADC_VBAT_OUT_EN_SHIFT			0x1


// (0x89) INT CTRL 1
// #define in pmic6326_sw.h
// (0x8A) INT CTRL 2
// #define in pmic6326_sw.h
// (0x8B) INT CTRL 3
// #define in pmic6326_sw.h

// (0x8C)
#define VCAMA_OC_AUTO_OFF_SHIFT			0x1
#define VCAMA_OC_AUTO_OFF_MASK			0x1

#define VCAMD_OC_AUTO_OFF_SHIFT			0x6
#define VCAMD_OC_AUTO_OFF_MASK			0x1

// (0x8F)
#define ST_GEAR_VWIFI3V3_SHIFT			0x0
#define ST_GEAR_VWIFI3V3_MASK			0x3

#define ST_GEAR_VWIFI2V8_SHIFT			0x2
#define ST_GEAR_VWIFI2V8_MASK			0x3

// (0x90)
#define ST_GEAR_VSDIO_SHIFT				0x2
#define ST_GEAR_VSDIO_MASK				0x3

// (0x92)
#define OC_GEAR_VWIFI3V3_SHIFT			0x0
#define OC_GEAR_VWIFI3V3_MASK			0x3

#define OC_GEAR_VWIFI2V8_SHIFT			0x2
#define OC_GEAR_VWIFI2V8_MASK			0x3

// (0x93)
#define OC_GEAR_VSDIO_SHIFT				0x2
#define OC_GEAR_VSDIO_MASK				0x3


// (0x96) WATCHDOG CTRL and INT CTRL 4
#define WDT_TIMEOUT_MASK				0x3
#define WDT_TIMEOUT_SHIFT				0x0
#define INTR_POLARITY_MASK				0x1
#define INTR_POLARITY_SHIFT			0x2
#define WDT_DISABLE_MASK				0x1
#define WDT_DISABLE_SHIFT				0x3


#endif //#if defined(PMIC_6326_REG_API)

#endif // #ifndef __DCL_PMIC6326_HW_H_STRUCT__




