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
 *    dcl_pmu6236_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMU6236
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMIC6236_HW_H_STRUCT__
#define __DCL_PMIC6236_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6236_REG_API)

#define PMU_BASE        MIXED_base
#define PMU_END         (PMU_BASE+0x1000) 

// =====================================================================================

#define PMIC_LDO_BASE0       (PMU_BASE+0x800) 
#define PMIC_LDO_BASE1       (PMU_BASE+0x804) 

#define PMIC_VRF_CON0       (PMU_BASE+0x800) 
#define PMIC_VRF_CON1       (PMU_BASE+0x804) 
#define PMIC_VRF_CON2       (PMU_BASE+0x808) 
#define PMIC_VRF_CON3       (PMU_BASE+0x80C) 

#define PMIC_VTCXO_CON0     (PMU_BASE+0x810) 
#define PMIC_VTCXO_CON1     (PMU_BASE+0x814) 
#define PMIC_VTCXO_CON2     (PMU_BASE+0x818) 

#define PMIC_VA_CON0        (PMU_BASE+0x820) 
#define PMIC_VA_CON1        (PMU_BASE+0x824) 
#define PMIC_VA_CON2        (PMU_BASE+0x828) 

#define PMIC_VCAMA_CON0     (PMU_BASE+0x830) 
#define PMIC_VCAMA_CON1     (PMU_BASE+0x834) 
#define PMIC_VCAMA_CON2     (PMU_BASE+0x838) 

#define PMIC_VCAMD_CON0     (PMU_BASE+0x840) 
#define PMIC_VCAMD_CON1     (PMU_BASE+0x844) 
#define PMIC_VCAMD_CON2     (PMU_BASE+0x848) 

#define PMIC_VIO_CON0       (PMU_BASE+0x850) 
#define PMIC_VIO_CON1       (PMU_BASE+0x854) 
#define PMIC_VIO_CON2       (PMU_BASE+0x858) 

#define PMIC_VUSB_CON0      (PMU_BASE+0x860) 
#define PMIC_VUSB_CON1      (PMU_BASE+0x864) 
#define PMIC_VUSB_CON2      (PMU_BASE+0x868) 

#define PMIC_VBT_CON0       (PMU_BASE+0x870) 
#define PMIC_VBT_CON1       (PMU_BASE+0x874) 
#define PMIC_VBT_CON2       (PMU_BASE+0x878) 

#define PMIC_VSIM_CON0      (PMU_BASE+0x880) 
#define PMIC_VSIM_CON1      (PMU_BASE+0x884) 
#define PMIC_VSIM_CON2      (PMU_BASE+0x888) 
#define PMIC_VSIM_CON3      (PMU_BASE+0x88C) 

#define PMIC_VSIM2_CON0     (PMU_BASE+0x890) 
#define PMIC_VSIM2_CON1     (PMU_BASE+0x894) 
#define PMIC_VSIM2_CON2     (PMU_BASE+0x898) 
#define PMIC_VSIM2_CON3     (PMU_BASE+0x89C) 

#define PMIC_VBACKUP_CON0   (PMU_BASE+0x8A0) 
#define PMIC_VBACKUP_CON1   (PMU_BASE+0x8A4) 
#define PMIC_VBACKUP_CON2   (PMU_BASE+0x8A8) 

#define PMIC_VBIR_CON0      (PMU_BASE+0x8B0) 
#define PMIC_VBIR_CON1      (PMU_BASE+0x8B4) 
#define PMIC_VBIR_CON2      (PMU_BASE+0x8B8) 

#define PMIC_VMC_CON0       (PMU_BASE+0x8C0) 
#define PMIC_VMC_CON1       (PMU_BASE+0x8C4) 
#define PMIC_VMC_CON2       (PMU_BASE+0x8C8) 

#define PMIC_VCORE_CON0     (PMU_BASE+0x900)
#define PMIC_VCORE_CON1     (PMU_BASE+0x904)
#define PMIC_VCORE_CON2     (PMU_BASE+0x908)
#define PMIC_VCORE_CON3     (PMU_BASE+0x90C)
#define PMIC_VCORE_CON4     (PMU_BASE+0x910)
#define PMIC_VCORE_CON5     (PMU_BASE+0x914)
#define PMIC_VCORE_CON6     (PMU_BASE+0x918)

#define PMIC_VM_CON0        (PMU_BASE+0x920)
#define PMIC_VM_CON1        (PMU_BASE+0x924)
#define PMIC_VM_CON2        (PMU_BASE+0x928)
#define PMIC_VM_CON3        (PMU_BASE+0x92C)
#define PMIC_VM_CON4        (PMU_BASE+0x930)
#define PMIC_VM_CON5        (PMU_BASE+0x934)
#define PMIC_VM_CON6        (PMU_BASE+0x938)


#define PMIC_BOOST_CON0     (PMU_BASE+0xB00) 
#define PMIC_BOOST_CON1     (PMU_BASE+0xB04) 
#define PMIC_BOOST_CON2     (PMU_BASE+0xB08) 
#define PMIC_BOOST_CON3     (PMU_BASE+0xB0C) 

#define PMIC_BL_CON0        (PMU_BASE+0xB80) 
#define PMIC_BL_CON1        (PMU_BASE+0xB84) 


#define PMIC_CHR_CON0       (PMU_BASE+0xA00) 
#define PMIC_CHR_CON1       (PMU_BASE+0xA04)
#define PMIC_CHR_CON2       (PMU_BASE+0xA08)
#define PMIC_CHR_CON3       (PMU_BASE+0xA0C)
#define PMIC_CHR_CON4       (PMU_BASE+0xA10)
#define PMIC_CHR_CON5       (PMU_BASE+0xA14)
#define PMIC_CHR_CON6       (PMU_BASE+0xA18)
#define PMIC_CHR_CON7       (PMU_BASE+0xA1C)
#define PMIC_CHR_CON8       (PMU_BASE+0xA20)
#define PMIC_CHR_CON9       (PMU_BASE+0xA24)

#define PMIC_STRUP_CON0     (PMU_BASE+0xA80) 
#define PMIC_STRUP_CON1     (PMU_BASE+0xA84) 

#define PMIC_ISINK0_CON0    (PMU_BASE+0xC00) 
#define PMIC_ISINK0_CON1    (PMU_BASE+0xC04) 

#define PMIC_ISINK1_CON0    (PMU_BASE+0xC10) 
#define PMIC_ISINK2_CON0    (PMU_BASE+0xC20) 
#define PMIC_ISINK3_CON0    (PMU_BASE+0xC30) 
#define PMIC_ISINK4_CON0    (PMU_BASE+0xC40) 

#define PMIC_KPLED_CON0     (PMU_BASE+0xC80) 
#define PMIC_KPLED_CON1     (PMU_BASE+0xC84)   

#define PMIC_FLASH_CON0     (PMU_BASE+0xC90) 
#define PMIC_FLASH_CON1     (PMU_BASE+0xC94)   


#define PMIC_SPK_CON0       (PMU_BASE+0xD00)
#define PMIC_SPK_CON1       (PMU_BASE+0xD04)
#define PMIC_SPK_CON2       (PMU_BASE+0xD08)
#define PMIC_SPK_CON3       (PMU_BASE+0xD0C)


#define PMIC_TEST_CON0      (PMU_BASE+0xF00)
#define PMIC_TEST_CON1      (PMU_BASE+0xF04)

#define PMIC_OC_CON0        (PMU_BASE+0xE00) 
#define PMIC_OC_CON1        (PMU_BASE+0xE04) 
#define PMIC_OC_CON2        (PMU_BASE+0xE08) 
#define PMIC_OC_CON3        (PMU_BASE+0xE0C) 
#define PMIC_OC_CON4        (PMU_BASE+0xE10) 
#define PMIC_OC_CON5        (PMU_BASE+0xE14) 
#define PMIC_OC_CON6        (PMU_BASE+0xE18) 
#define PMIC_OC_CON7        (PMU_BASE+0xE1C) 


#define LDO_EN_MASK             0x0001
#define LD0_EN_SHIFT            0
#define LDO_ON_SEL_MASK         0x0002
#define LDO_ON_SEL_SHIFT        1
#define LDO_SENSE_MASK          0x0004
#define LDO_SENSE_SHIFT         2
#define LDO_OCFB_EN_MASK        0x2000
#define LDO_OCFB_EN_SHIFT       13
#define LDO_STATUS_MASK         0x8000
#define LDO_STATUS_SHIFT        15

#define LDO_CAL_MASK            0x00F0
#define LDO_CAL_SHIFT           4


// =====================================================================================
// (0x800) VRF_CON0
#define VRF_EN_MASK             0x0001
#define VRF_EN_SHIFT            0
#define VRF_ON_SEL_MASK         0x0002
#define VRF_ON_SEL_SHIFT        1
#define VRF_REMOTE_SENSE_MASK   0x0004
#define VRF_REMOTE_SENSE_SHIFT  2
#define VRF_NDIS_EN_MASK        0x0400
#define VRF_NDIS_EN_SHIFT       10
#define VRF_STB_EN_MASK         0x0800
#define VRF_STB_EN_SHIFT        11
#define VRF_OC_AUTO_OFF_MASK    0x1000
#define VRF_OC_AUTO_OFF_SHIFT   12
#define VRF_OCFB_EN_MASK        0x2000
#define VRF_OCFB_EN_SHIFT       13
#define VRF_STATUS_MASK         0x8000
#define VRF_STATUS_SHIFT        15

// (0x804) VRF_CON1
#define VRF_CAL_MASK            0x00F0
#define VRF_CAL_SHIFT           4

// (0x810) VTCXO_CON0
#define VTCXO_EN_MASK               0x0001
#define VTCXO_EN_SHIFT              0
#define VTCXO_ON_SEL_MASK           0x0002
#define VTCXO_ON_SEL_SHIFT          1
#define VTCXO_REMOTE_SENSE_MASK     0x0004
#define VTCXO_REMOTE_SENSE_SHIFT    2
#define VTCXO_NDIS_EN_MASK          0x0400
#define VTCXO_NDIS_EN_SHIFT         10
#define VTCXO_STB_EN_MASK           0x0800
#define VTCXO_STB_EN_SHIFT          11
#define VTCXO_OC_AUTO_OFF_MASK      0x1000
#define VTCXO_OC_AUTO_OFF_SHIFT     12
#define VTCXO_OCFB_EN_MASK          0x2000
#define VTCXO_OCFB_EN_SHIFT         13
#define VTCXO_STATUS_MASK           0x8000
#define VTCXO_STATUS_SHIFT          15

// (0x814) VTCXO_CON1
#define VTCXO_CAL_MASK              0x00F0
#define VTCXO_CAL_SHIFT             4

// (0x820) VA_CON0
#define VA_REMOTE_SENSE_MASK        0x0004
#define VA_REMOTE_SENSE_SHIFT       2
#define VA_NDIS_EN_MASK             0x0400
#define VA_NDIS_EN_SHIFT            10
#define VA_STB_EN_MASK              0x0800
#define VA_STB_EN_SHIFT             11
#define VA_OC_AUTO_OFF_MASK         0x1000
#define VA_OC_AUTO_OFF_SHIFT        12
#define VA_OCFB_EN_MASK             0x2000
#define VA_OCFB_EN_SHIFT            13
#define VA_STATUS_MASK              0x8000
#define VA_STATUS_SHIFT             15

// (0x824) VA_CON1
#define VA_CAL_MASK                 0x00F0
#define VA_CAL_SHIFT                4

// (0x830) VCAMA_CON0
#define VCAMA_EN_MASK               0x0001
#define VCAMA_EN_SHIFT              0
#define VCAMA_ON_SEL_MASK           0x0002
#define VCAMA_ON_SEL_SHIFT          1
#define VCAMA_VOSEL_MASK            0x0030
#define VCAMA_VOSEL_SHIFT           4
#define VCAMA_NDIS_EN_MASK          0x0400
#define VCAMA_NDIS_EN_SHIFT         10
#define VCAMA_STB_EN_MASK           0x0800
#define VCAMA_STB_EN_SHIFT          11
#define VCAMA_OC_AUTO_OFF_MASK      0x1000
#define VCAMA_OC_AUTO_OFF_SHIFT     12
#define VCAMA_OCFB_EN_MASK          0x2000
#define VCAMA_OCFB_EN_SHIFT         13
#define VCAMA_STATUS_MASK           0x8000
#define VCAMA_STATUS_SHIFT          15

// (0x834) VCAMA_CON1
#define VCAMA_CAL_MASK              0x00F0
#define VCAMA_CAL_SHIFT             4

// (0x838) VCAMA_CON2
#define VCAMA_OC_TD_MASK            0x0030
#define VCAMA_OC_TD_SHIFT           4
#define VCAMA_STB_TD_MASK           0x00C0
#define VCAMA_STB_TD_SHIFT          6

// (0x840) VCAMD_CON0
#define VCAMD_EN_MASK               0x0001
#define VCAMD_EN_SHIFT              0
#define VCAMD_ON_SEL_MASK           0x0002
#define VCAMD_ON_SEL_SHIFT          1
#define VCAMD_VOSEL_MASK            0x0070
#define VCAMD_VOSEL_SHIFT           4
#define VCAMD_NDIS_EN_MASK          0x0400
#define VCAMD_NDIS_EN_SHIFT         10
#define VCAMD_STB_EN_MASK           0x0800
#define VCAMD_STB_EN_SHIFT          11
#define VCAMD_OC_AUTO_OFF_MASK      0x1000
#define VCAMD_OC_AUTO_OFF_SHIFT     12
#define VCAMD_OCFB_EN_MASK          0x2000
#define VCAMD_OCFB_EN_SHIFT         13
#define VCAMD_STATUS_MASK           0x8000
#define VCAMD_STATUS_SHIFT          15
                 
// (0x844) VCAMD CON1
#define VCAMD_CAL_MASK              0x00F0
#define VCAMD_CAL_SHIFT             4

// (0x850) VIO_CON0
#define VIO_REMOTE_SENSE_MASK       0x0004
#define VIO_REMOTE_SENSE_SHIFT      2
#define VIO_OC_AUTO_OFF_MASK        0x1000
#define VIO_NDIS_EN_MASK            0x0400
#define VIO_NDIS_EN_SHIFT           10
#define VIO_STB_EN_MASK             0x0800
#define VIO_STB_EN_SHIFT            11
#define VIO_OC_AUTO_OFF_SHIFT       12
#define VIO_OCFB_EN_MASK            0x2000
#define VIO_OCFB_EN_SHIFT           13
#define VIO_STATUS_MASK             0x8000
#define VIO_STATUS_SHIFT            15

// (0x854) VIO_CON1
#define VIO_CAL_MASK                0x00F0
#define VIO_CAL_SHIFT               4

// (0x858) VIO_CON2
#define VIO_OC_TD_MASK              0x0030
#define VIO_OC_TD_SHIFT             4

// (0x860) VUSB_CON0
#define VUSB_EN_MASK                0x0001
#define VUSB_EN_SHIFT               0
#define VUSB_NDIS_EN_MASK           0x0400
#define VUSB_NDIS_EN_SHIFT          10
#define VUSB_STB_EN_MASK            0x0800
#define VUSB_STB_EN_SHIFT           11
#define VUSB_OC_AUTO_OFF_MASK       0x1000
#define VUSB_OC_AUTO_OFF_SHIFT      12
#define VUSB_OCFB_EN_MASK           0x2000
#define VUSB_OCFB_EN_SHIFT          13
#define VUSB_STATUS_MASK            0x8000
#define VUSB_STATUS_SHIFT           15

// (0x864) VUSB_CON1
#define VUSB_CAL_MASK               0x00F0
#define VUSB_CAL_SHIFT              4

// (0x868) VUSB_CON2
#define VUSB_OC_TD_MASK             0x0030
#define VUSB_OC_TD_SHIFT            4
#define VUSB_STB_TD_MASK            0x00C0
#define VUSB_STB_TD_SHIFT           6

// (0x870) VBT CON0
#define VBT_EN_MASK                 0x0001
#define VBT_EN_SHIFT                0
#define VBT_VOSEL_MASK              0x0010
#define VBT_VOSEL_SHIFT             4
#define VBT_NDIS_EN_MASK            0x0400
#define VBT_NDIS_EN_SHIFT           10
#define VBT_STB_EN_MASK             0x0800
#define VBT_STB_EN_SHIFT            11
#define VBT_OC_AUTO_OFF_MASK        0x1000
#define VBT_OC_AUTO_OFF_SHIFT       12
#define VBT_OCFB_EN_MASK            0x2000
#define VBT_OCFB_EN_SHIFT           13
#define VBT_STATUS_MASK             0x8000
#define VBT_STATUS_SHIFT            15

// (0x874) VBT CON1
#define VBT_CAL_MASK                0x00F0
#define VBT_CAL_SHIFT               4

// (0x878) VBT CON2
#define VBT_OC_TD_MASK              0x0030
#define VBT_OC_TD_SHIFT             4
#define VBT_STB_TD_MASK             0x00C0
#define VBT_STB_TD_SHIFT            6

// (0x880) VSIM CON0
#define VSIM_EN_MASK                0x0001
#define VSIM_EN_SHIFT               0
#define VSIM_VOSEL_MASK             0x0010
#define VSIM_VOSEL_SHIFT            4
#define VSIM_NDIS_EN_MASK           0x0400
#define VSIM_NDIS_EN_SHIFT          10
#define VSIM_STB_EN_MASK            0x0800
#define VSIM_STB_EN_SHIFT           11
#define VSIM_OC_AUTO_OFF_MASK       0x1000
#define VSIM_OC_AUTO_OFF_SHIFT      12
#define VSIM_OCFB_EN_MASK           0x2000
#define VSIM_OCFB_EN_SHIFT          13
#define VSIM_STATUS_MASK            0x8000
#define VSIM_STATUS_SHIFT           15

// (0x884) VSIM_CON1
#define VSIM_CAL_MASK               0x00F0
#define VSIM_CAL_SHIFT              4

// (0x888) VSIM_CON2
#define VSIM_OC_TD_MASK             0x0030
#define VSIM_OC_TD_SHIFT            4
                 
// (0x890) VSIM2 CON0
#define VSIM2_EN_MASK               0x0001
#define VSIM2_EN_SHIFT              0
#define VSIM2_VOSEL_MASK            0x0070
#define VSIM2_VOSEL_SHIFT           4
#define VSIM2_NDIS_EN_MASK          0x0400
#define VSIM2_NDIS_EN_SHIFT         10
#define VSIM2_STB_EN_MASK           0x0800
#define VSIM2_STB_EN_SHIFT          11
#define VSIM2_OC_AUTO_OFF_MASK      0x1000
#define VSIM2_OC_AUTO_OFF_SHIFT     12
#define VSIM2_OCFB_EN_MASK          0x2000
#define VSIM2_OCFB_EN_SHIFT         13
#define VSIM2_STATUS_MASK           0x8000
#define VSIM2_STATUS_SHIFT          15

// (0x894) VSIM2_CON1
#define VSIM2_CAL_MASK              0x00F0
#define VSIM2_CAL_SHIFT             4

// (0x898) VSIM2_CON2
#define VSIM2_GPLDO_EN_MASK         0x0002
#define VSIM2_GPLDO_EN_SHIFT        1


// (0x8A0) VBACKUP_CON0
#define VBACKUP_EN_MASK             0x0001
#define VBACKUP_EN_SHIFT            0
#define VBACKUP_NDIS_EN_MASK        0x0400
#define VBACKUP_NDIS_EN_SHIFT       10
#define VBACKUP_STB_EN_MASK         0x0800
#define VBACKUP_STB_EN_SHIFT        11
#define VBACKUP_OC_AUTO_OFF_MASK    0x1000
#define VBACKUP_OC_AUTO_OFF_SHIFT   12
#define VBACKUP_OCFB_EN_MASK        0x2000
#define VBACKUP_OCFB_EN_SHIFT       13
#define VBACKUP_STATUS_MASK         0x8000
#define VBACKUP_STATUS_SHIFT        15

// (0x8B0) Vibr_CON0
#define VIBR_EN_MASK                0x0001
#define VIBR_EN_SHIFT               0
#define VIBR_VOSEL_MASK             0x0070
#define VIBR_VOSEL_SHIFT            4
#define VIBR_NDIS_EN_MASK           0x0400
#define VIBR_NDIS_EN_SHIFT          10
#define VIBR_STB_EN_MASK            0x0800
#define VIBR_STB_EN_SHIFT           11
#define VIBR_OC_AUTO_OFF_MASK       0x1000
#define VIBR_OC_AUTO_OFF_SHIFT      12
#define VIBR_OCFB_EN_MASK           0x2000
#define VIBR_OCFB_EN_SHIFT          13
#define VIBR_STATUS_MASK            0x8000
#define VIBR_STATUS_SHIFT           15

// (0x8B4) VIBR_CON1
#define VIBR_CAL_MASK               0x00F0
#define VIBR_CAL_SHIFT              4

// (0x8C0) VMC_CON0
#define VMC_EN_MASK                 0x0001
#define VMC_EN_SHIFT                0
#define VMC_VOSEL_MASK              0x0070
#define VMC_VOSEL_SHIFT             4
#define VMC_NDIS_EN_MASK            0x0400
#define VMC_NDIS_EN_SHIFT           10
#define VMC_STB_EN_MASK             0x0800
#define VMC_STB_EN_SHIFT            11
#define VMC_OC_AUTO_OFF_MASK        0x1000
#define VMC_OC_AUTO_OFF_SHIFT       12
#define VMC_OCFB_EN_MASK            0x2000
#define VMC_OCFB_EN_SHIFT           13
#define VMC_STATUS_MASK             0x8000
#define VMC_STATUS_SHIFT            15

// (0x08C4) VMC_CON1
#define VMC_CAL_MASK                0x00F0
#define VMC_CAL_SHIFT               4

// (0x900) VCORE_CON0
#define VCORE_EN_MASK               0x0001
#define VCORE_EN_SHIFT              0
#define VCORE_REMOTE_SENSE_MASK     0x0004
#define VCORE_REMOTE_SENSE_SHIFT    2
#define VCORE_VFBADJ_MASK           0x01F0
#define VCORE_VFBADJ_SHIFT          4
#define VCORE_STB_EN_MASK           0x0800
#define VCORE_STB_EN_SHIFT          11
#define VCORE_OC_AUTO_OFF_MASK      0x1000
#define VCORE_OC_AUTO_OFF_SHIFT     12
#define VCORE_OCFB_EN_MASK          0x2000
#define VCORE_OCFB_EN_SHIFT         13
#define VCORE_STATUS_MASK           0x8000
#define VCORE_STATUS_SHIFT          15

// (0x904) VCORE_CON1
#define VCORE_MODE_SET_MASK         0x0001
#define VCORE_MODE_SET_SHIFT        0
#define VCORE_VFBADJ_SLEEP_MASK     0x01F0
#define VCORE_VFBADJ_SLEEP_SHIFT    4
#define VCORE_CPMCKSEL_MASK         0x0400
#define VCORE_CPMCKSEL_SHIFT        10

// (0x908) VCORE_CON2
#define VCORE_VOSEL_MASK            0x0007
#define VCORE_VOSEL_SHIFT           0
#define VCORE_CAL_MASK              0x00F0
#define VCORE_CAL_SHIFT             4
                 
// (0x90C) VCORE_CON3
#define VCORE_ICAL_EN_MASK          0x3000
#define VCORE_ICAL_EN_SHIFT         12

// (0x914) VCORE_CON5
#define VCORE_CSL_MASK              0x0700
#define VCORE_CSL_SHIFT             8
#define VCORE_BURST_MASK            0x3000
#define VCORE_BURST_SHIFT           12

// (0x920) VM_CON0
#define VM_REMOTE_SENSE_MASK        0x0004
#define VM_REMOTE_SENSE_SHIFT       2
#define VM_STB_EN_MASK              0x0800
#define VM_STB_EN_SHIFT             11
#define VM_OC_AUTO_OFF_MASK         0x1000
#define VM_OC_AUTO_OFF_SHIFT        12
#define VM_OCFB_EN_MASK             0x2000
#define VM_OCFB_EN_SHIFT            13
#define VM_STATUS_MASK              0x8000
#define VM_STATUS_SHIFT             15

// (0x928) VM_CON2
#define VM_CAL_MASK         0x00F0
#define VM_CAL_SHIFT        4

// (0x92C) VM_CON3
#define VM_ICAL_EN_MASK     0x3000
#define VM_ICAL_EN_SHIFT    12

// (0x92C) VM_CON5
#define VM_CSL_MASK         0x0700
#define VM_CSL_SHIFT        8
#define VM_BURST_MASK       0x3000
#define VM_BURST_SHIFT      12
                 
// (0xA00)  CHR_CON0
#define VCDT_LV_VTH_MASK            0x000F
#define VCDT_LV_VTH_SHIFT           0
#define VCDT_HV_VTH_MASK            0x00F0
#define VCDT_HV_VTH_SHIFT           4
#define VCDT_HV_EN_MASK             0x0100
#define VCDT_HV_EN_SHIFT            8
#define CSDAC_EN_MASK               0x0800
#define CSDAC_EN_SHIFT              11
#define CHR_EN_MASK                 0x1000
#define CHR_EN_SHIFT                12
#define CHRDET_MASK                 0x2000
#define CHRDET_SHIFT                13
#define VCDT_HV_DET_MASK            0x8000
#define VCDT_HV_DET_SHIFT           15

// (0xA04)  CHR_CON1
#define VBAT_CV_VTH_MASK    0x001F
#define VBAT_CV_VTH_SHIFT   0
#define VBAT_CC_VTH_MASK    0x00C0
#define VBAT_CC_VTH_SHIFT   6
#define VBAT_CV_EN_MASK     0x0100
#define VBAT_CV_EN_SHIFT    8
#define VBAT_CC_EN_MASK     0x0200
#define VBAT_CC_EN_SHIFT    9
#define VBAT_CV_DET_MASK            0x4000
#define VBAT_CV_DET_SHIFT           14
#define VBAT_CC_DET_MASK    0x8000
#define VBAT_CC_DET_SHIFT   15

// (0xA08)  CHR_CON2
#define CS_EN_MASK                 0x1000
#define CS_EN_SHIFT                12
#define CS_VTH_MASK                0x0700
#define CS_VTH_SHIFT               8

// (0xA0C)  CHR_CON3
#define CSDAC_DLY_MASK             0x30
#define CSDAC_DLY_SHIFT            4
#define CSDAC_STP_MASK             0x3
#define CSDAC_STP_SHIFT            0

// (0xA14)  CHR_CON5
#define PCHR_FLAG_SEL_MASK         0x000F
#define PCHR_FLAG_SEL_SHIFT        0
#define PCHR_FLAG_EN_MASK          0x0080
#define PCHR_FLAG_EN_SHIFT         7
#define PCHR_FLAG_OUT_MASK         0x0F00
#define PCHR_FLAG_OUT_SHIFT        8
  // PCHR command result (The value is filled into PCHR_FLAG_OUT)
  #define PCHR_STATE_MASK          0x7
  #define PCHR_STATE_SHIFT         0


// (0xA18) CHR_CON6
#define CHRWDT_TD_MASK             0x0007
#define CHRWDT_TD_SHIFT            0
#define CHRWDT_EN_MASK             0x0010
#define CHRWDT_EN_SHIFT            4

// (0xA1C) CHR_CON7
#define CHRWDT_INT_EN_MASK         0x0001
#define CHRWDT_INT_EN_SHIFT        0
#define CHRWDT_FLAG_MASK           0x0002
#define CHRWDT_FLAG_SHIFT          1

// (0xA20) CHR_CON8
#define ADCIN_VBAT_EN              0x1000
#define ADCIN_VBAT_EN_SHIFT        12
#define ADCIN_VSEN_EN              0x2000
#define ADCIN_VSEN_EN_SHIFT        13
#define ADCIN_VCHR_EN              0x4000
#define ADCIN_VCHR_EN_SHIFT        14

// (0xB00) BOOST_CON0
#define VBOOST_EN_MASK              0x0001
#define VBOOST_EN_SHIFT             0
#define VBOOST_TYPE_MASK            0x0002
#define VBOOST_TYPE_SHIFT           1
#define VBOOST_MODE_MASK            0x0004
#define VBOOST_MODE_SHIFT           2
#define VBOOST_VRSEL_MASK           0x01F0
#define VBOOST_VRSEL_SHIFT          4

// (0xB0C) BOOST_CON3
#define VBOOST_CKS_PRG_MASK         0x003F
#define VBOOST_CKS_PRG_SHIFT        0

// (0xC00) ISINK0_CON0
#define ISINK0_EN_MASK              0x0001
#define ISINK0_EN_SHIFT             0
#define ISINK0_MODE_MASK            0x0002
#define ISINK0_MODE_SHIFT           1
#define ISINK0_STEP_MASK            0x0070
#define ISINK0_STEP_SHIFT           4
#define ISINK0_STATUS_MASK          0x8000
#define ISINK0_STATUS_SHIFT         15

// (0xC10) ISINK1_CON0
#define ISINK1_EN_MASK              0x0001
#define ISINK1_EN_SHIFT             0
#define ISINK1_MODE_MASK            0x0002
#define ISINK1_MODE_SHIFT           1
#define ISINK1_STEP_MASK            0x0070
#define ISINK1_STEP_SHIFT           4
#define ISINK1_STATUS_MASK          0x8000
#define ISINK1_STATUS_SHIFT         15

// (0xC20) ISINK2_CON0
#define ISINK2_EN_MASK              0x0001
#define ISINK2_EN_SHIFT             0
#define ISINK2_MODE_MASK            0x0002
#define ISINK2_MODE_SHIFT           1
#define ISINK2_STEP_MASK            0x0070
#define ISINK2_STEP_SHIFT           4
#define ISINK2_STATUS_MASK          0x8000
#define ISINK2_STATUS_SHIFT         15

// (0xC30) ISINK3_CON0
#define ISINK3_EN_MASK              0x0001
#define ISINK3_EN_SHIFT             0
#define ISINK3_MODE_MASK            0x0002
#define ISINK3_MODE_SHIFT           1
#define ISINK3_STEP_MASK            0x0070
#define ISINK3_STEP_SHIFT           4
#define ISINK3_STATUS_MASK          0x8000
#define ISINK3_STATUS_SHIFT         15

// (0xC40) ISINK4_CON0
#define ISINK4_EN_MASK              0x0001
#define ISINK4_EN_SHIFT             0
#define ISINK4_MODE_MASK            0x0002
#define ISINK4_MODE_SHIFT           1
#define ISINK4_STEP_MASK            0x0070
#define ISINK4_STEP_SHIFT           4
#define ISINK4_STATUS_MASK          0x8000
#define ISINK4_STATUS_SHIFT         15

// (0xC80) KPLED CON0
#define KPLED_EN_MASK               0x0001
#define KPLED_EN_SHIFT              0
#define KPLED_MODE_MASK             0x0002
#define KPLED_MODE_SHIFT            1
#define KPLED_SEL_MASK              0x0070
#define KPLED_SEL_SHIFT             4
#define KPLED_STATUS_MASK           0x8000
#define KPLED_STATUS_SHIFT          15

// (0xC90) FLASH_CON0
#define FLASH_EN_MASK               0x0001
#define FLASH_EN_SHIFT              0
#define FLASH_MODE_MASK             0x0002
#define FLASH_MODE_SHIFT            1
#define FLASH_SEL_MASK              0x0070
#define FLASH_SEL_SHIFT             4
#define FLASH_STATUS_MASK           0x8000
#define FLASH_STATUS_SHIFT          15

// (0xD00) SPK_CON0
#define SPK_EN_MASK                 0x0001
#define SPK_EN_SHIFT                0
#define SPK_VOL_MASK                0x0010
#define SPK_VOL_SHIFT               4
#define SPK_OCFB_EN_MASK            0x2000
#define SPK_OCFB_EN_SHIFT           13

// (0xE00) PMIC_OC_CON0
#define VRF_OC_INT_EN_MASK          0x0001
#define VRF_OC_INT_EN_SHIFT         0
#define VTCXO_OC_INT_EN_MASK        0x0002
#define VTCXO_OC_INT_EN_SHIFT       1
#define VA_OC_INT_EN_MASK           0x0004
#define VA_OC_INT_EN_SHIFT          2
#define VCAMA_OC_INT_EN_MASK        0x0008
#define VCAMA_OC_INT_EN_SHIFT       3
#define VCAMD_OC_INT_EN_MASK        0x0010
#define VCAMD_OC_INT_EN_SHIFT       4
#define VIO_OC_INT_EN_MASK          0x0020
#define VIO_OC_INT_EN_SHIFT         5
#define VUSB_OC_INT_EN_MASK         0x0040
#define VUSB_OC_INT_EN_SHIFT        6
#define VBT_OC_INT_EN_MASK          0x0080
#define VBT_OC_INT_EN_SHIFT         7
#define VSIM_OC_INT_EN_MASK         0x0100
#define VSIM_OC_INT_EN_SHIFT        8
#define VSIM2_OC_INT_EN_MASK        0x0200
#define VSIM2_OC_INT_EN_SHIFT       9
#define VBACKUP_OC_INT_EN_MASK      0x0400
#define VBACKUP_OC_INT_EN_SHIFT     10
#define VIBR_OC_INT_EN_MASK         0x0800
#define VIBR_OC_INT_EN_SHIFT        11
#define VMC_OC_INT_EN_MASK          0x1000
#define VMC_OC_INT_EN_SHIFT         12

// (0xE04) PMIC_OC_CON1
#define VCORE_OC_INT_EN_MASK        0x0001
#define VCORE_OC_INT_EN_SHIFT       0
#define VM_OC_INT_EN_MASK           0x0002
#define VM_OC_INT_EN_SHIFT          1
                 



////////////////////////////////////////////////////////////////



#endif // #if defined(PMIC_6236_REG_API)

#endif // #ifndef __DCL_PMIC6236_HW_H_STRUCT__




