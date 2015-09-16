/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *    dcl_pmu6327_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC6327 H/W configuration.
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


#ifndef __DCL_PMIC6327_HW_H_STRUCT__
#define __DCL_PMIC6327_HW_H_STRUCT__


#include "dcl_pmic_features.h"


//RegisterTOP
// (RW)
#define CID0_ADDR                                       0x00
#define CID0_MASK                                       0xFFFF
#define CID0_SHIFT                                      0

// (RW)
#define ECO_VERSION_ADDR                                0x01
#define ECO_VERSION_MASK                                0xFFFF
#define ECO_VERSION_SHIFT                               0


// (RW)
#define RG_VIO28_VOSEL_ADDR				0x30
#define RG_VIO28_VOSEL_MASK				0x7
#define RG_VIO28_VOSEL_SHIFT				0

// (RW)
#define RG_VIO28_EN_ADDR				0x32
#define RG_VIO28_EN_MASK				0x1
#define RG_VIO28_EN_SHIFT				0

// (RW)
#define RG_VUSB11_EN_ADDR				0x51
#define RG_VUSB11_EN_MASK				0x1
#define RG_VUSB11_EN_SHIFT				0


// (RW)
#define RG_VCORE_VOSEL_ADDR				0x65
#define RG_VCORE_VOSEL_MASK				0x1F
#define RG_VCORE_VOSEL_SHIFT				0

// (RW)
#define RG_VRF18_MODESET_ADDR				0x72
#define RG_VRF18_MODESET_MASK				0x1
#define RG_VRF18_MODESET_SHIFT				0

// (RW)
#define RG_VRF18_ON_CTRL_ADDR				0x73
#define RG_VRF18_ON_CTRL_MASK				0x2
#define RG_VRF18_ON_CTRL_SHIFT				1

// (RW)
#define RG_VRF18_EN_ADDR					0x73
#define RG_VRF18_EN_MASK					0x1
#define RG_VRF18_EN_SHIFT					0

// (RW)
#define VRF18_srclken_sel_ADDR				0x7A
#define VRF18_srclken_sel_MASK				0xc0
#define VRF18_srclken_sel_SHIFT				6

// (RW)
#define RG_VRF18_2_MODESET_ADDR				0x7E
#define RG_VRF18_2_MODESET_MASK				0x1
#define RG_VRF18_2_MODESET_SHIFT			0

// (RW)
#define RG_VRF18_2_ON_CTRL_ADDR				0x7F
#define RG_VRF18_2_ON_CTRL_MASK				0x2
#define RG_VRF18_2_ON_CTRL_SHIFT			1

// (RW)
#define RG_VRF18_2_EN_ADDR					0x7F
#define RG_VRF18_2_EN_MASK					0x1
#define RG_VRF18_2_EN_SHIFT					0

// (RW)
#define VRF18_2_srclken_sel_ADDR			0x86
#define VRF18_2_srclken_sel_MASK			0xc0
#define VRF18_2_srclken_sel_SHIFT			6

// (RW)
#define RG_VPA_MODESET_ADDR					0x91
#define RG_VPA_MODESET_MASK					0x100
#define RG_VPA_MODESET_SHIFT				8

// (RW)
#define VPA_VOSEL_MAP_EN_ADDR					0x94
#define VPA_VOSEL_MAP_EN_MASK					0x10
#define VPA_VOSEL_MAP_EN_SHIFT					4

// (RW)
#define RG_VPA_EN_ADDR						0x94
#define RG_VPA_EN_MASK						0x1
#define RG_VPA_EN_SHIFT						0
	
// (RW)
#define VPA_VOSEL_ADDR						0x96
#define VPA_VOSEL_MASK						0x3f
#define VPA_VOSEL_SHIFT						0

// (RW)
#define RG_VRF18_BK_LDO_ADDR				0x7B
#define RG_VRF18_BK_LDO_MASK				0x1
#define RG_VRF18_BK_LDO_SHIFT				0

// (RW)
#define RG_VRF18_2_BK_LDO_ADDR				0x87
#define RG_VRF18_2_BK_LDO_MASK				0x1
#define RG_VRF18_2_BK_LDO_SHIFT				0

// (RW)
#define RG_VSIM1_VOSEL_ADDR					0x46
#define RG_VSIM1_VOSEL_MASK					0x70
#define RG_VSIM1_VOSEL_SHIFT				4
// (RW)
#define RG_VSIM1_EN_ADDR					0x46
#define RG_VSIM1_EN_MASK					0x1
#define RG_VSIM1_EN_SHIFT					0

// (RW)
#define RG_VSIM1_CAL_ADDR					0x45
#define RG_VSIM1_CAL_MASK					0xF
#define RG_VSIM1_CAL_SHIFT					0

// (RW)
#define RG_VSIM2_VOSEL_ADDR					0x40
#define RG_VSIM2_VOSEL_MASK					0x70
#define RG_VSIM2_VOSEL_SHIFT				4

// (RW)
#define RG_VSIM2_EN_ADDR					0x40
#define RG_VSIM2_EN_MASK					0x1
#define RG_VSIM2_EN_SHIFT					0

// (RW)
#define RG_VSIM2_CAL_ADDR					0x3F
#define RG_VSIM2_CAL_MASK					0xF
#define RG_VSIM2_CAL_SHIFT					0

// (RW)
#define RG_VMC_VOSEL_ADDR					0x36
#define RG_VMC_VOSEL_MASK					0x70
#define RG_VMC_VOSEL_SHIFT					4

// (RW)
#define RG_VMC_EN_ADDR						0x38
#define RG_VMC_EN_MASK						0x1
#define RG_VMC_EN_SHIFT						0

// (RW)
#define RG_VMCH_VOSEL_ADDR					0x39
#define RG_VMCH_VOSEL_MASK					0x70
#define RG_VMCH_VOSEL_SHIFT					4

// (RW)
#define RG_VMCH_EN_ADDR						0x3b
#define RG_VMCH_EN_MASK						0x1
#define RG_VMCH_EN_SHIFT					0

// (RW)
#define RG_VMIPI_EN_ADDR					0x3D
#define RG_VMIPI_EN_MASK					0x1
#define RG_VMIPI_EN_SHIFT					0

// (RW)
#define RG_VIO18_EN_ADDR					0xA3
#define RG_VIO18_EN_MASK					0x1
#define RG_VIO18_EN_SHIFT					0

// (RW)
#define VPA_TABLE0_ADDR					        0xF0
#define VPA_TABLE0_MASK					        0xFC00
#define VPA_TABLE0_SHIFT					10

// (RW)
#define VPA_TABLE1_ADDR					        0xF1
#define VPA_TABLE1_MASK					        0xFC00
#define VPA_TABLE1_SHIFT					10

// (RW)
#define VPA_TABLE2_ADDR					        0xF2
#define VPA_TABLE2_MASK					        0xFC00
#define VPA_TABLE2_SHIFT					10

// (RW)
#define VPA_TABLE3_ADDR					        0xF3
#define VPA_TABLE3_MASK					        0xFC00
#define VPA_TABLE3_SHIFT					10

// (RW)
#define VPA_TABLE4_ADDR					        0xF4
#define VPA_TABLE4_MASK					        0xFC00
#define VPA_TABLE4_SHIFT					10

// (RW)
#define VPA_TABLE5_ADDR					        0xF5
#define VPA_TABLE5_MASK					        0xFC00
#define VPA_TABLE5_SHIFT					10

// (RW)
#define VPA_TABLE6_ADDR					        0xF6
#define VPA_TABLE6_MASK					        0xFC00
#define VPA_TABLE6_SHIFT					10

// (RW)
#define VPA_TABLE7_ADDR					        0xF7
#define VPA_TABLE7_MASK					        0xFC00
#define VPA_TABLE7_SHIFT					10

// (RW)
#define VPA_MAP_SEL_ADDR					0xFA
#define VPA_MAP_SEL_MASK					0x7
#define VPA_MAP_SEL_SHIFT					0

//Register Group

//Memory

#define PMIC_MAX_REG_IDX                             0xFE
#define PMIC_REG_NUM                                 (PMIC_MAX_REG_IDX + 1)


#endif // #ifndef __DCL_PMIC6327_HW_H_STRUCT__
