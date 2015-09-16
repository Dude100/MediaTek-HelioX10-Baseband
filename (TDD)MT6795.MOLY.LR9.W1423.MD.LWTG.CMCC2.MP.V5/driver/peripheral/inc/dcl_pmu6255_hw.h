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
 *    dcl_pmu6255_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMU 6255 driver.
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
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PMU6255_HW_H__
#define __PMU6255_HW_H__


#if defined(PMIC_6255_REG_API)

#define PMU_BASE            MIXED_base

#define PMU_END             (PMU_BASE + 0x1000)

///////////////////////////////////////////////////////////////////////////////

#define WR_PATH             (PMU_BASE + 0x0000)
#define AFUNC_DIN           (PMU_BASE + 0x0004)
#define AFUNC_XOSC          (PMU_BASE + 0x0008)
#define ABIST_CON0          (PMU_BASE + 0x0010)
#define ABIST_CON1          (PMU_BASE + 0x0014)
#define ABIST_CON2          (PMU_BASE + 0x0018)
#define ABIST_CON3          (PMU_BASE + 0x001C)
#define AFUNC_RTC           (PMU_BASE + 0x0020)
#define EFUSE_CON0          (PMU_BASE + 0x0100)
#define EFUSE_CON1          (PMU_BASE + 0x0104)
#define EFUSE_CON2          (PMU_BASE + 0x0108)
#define EFUSE_CON3          (PMU_BASE + 0x010C)
#define EFUSE_CON4          (PMU_BASE + 0x0110)
#define VSF_CON0            (PMU_BASE + 0x0700)
#define VSF_CON1            (PMU_BASE + 0x0704)
#define VSF_CON2            (PMU_BASE + 0x0708)
#define VSF_CON3            (PMU_BASE + 0x070C)
#define VRF_CON0            (PMU_BASE + 0x0800)
#define VRF_CON1            (PMU_BASE + 0x0804)
#define VRF_CON2            (PMU_BASE + 0x0808)
#define VRF_CON3            (PMU_BASE + 0x080C)
#define VTCXO_CON0          (PMU_BASE + 0x0810)
#define VTCXO_CON1          (PMU_BASE + 0x0814)
#define VTCXO_CON2          (PMU_BASE + 0x0818)
#define VA_CON0             (PMU_BASE + 0x0820)
#define VA_CON1             (PMU_BASE + 0x0824)
#define VA_CON2             (PMU_BASE + 0x0828)
#define VCAMA_CON0          (PMU_BASE + 0x0830)
#define VCAMA_CON1          (PMU_BASE + 0x0834)
#define VCAMA_CON2          (PMU_BASE + 0x0838)
#define VCAMD_CON0          (PMU_BASE + 0x0840)
#define VCAMD_CON1          (PMU_BASE + 0x0844)
#define VCAMD_CON2          (PMU_BASE + 0x0848)
#define VIO28_CON0          (PMU_BASE + 0x0850)
#define VIO28_CON1          (PMU_BASE + 0x0854)
#define VIO28_CON2          (PMU_BASE + 0x0858)
#define VUSB_CON0           (PMU_BASE + 0x0860)
#define VUSB_CON1           (PMU_BASE + 0x0864)
#define VUSB_CON2           (PMU_BASE + 0x0868)
#define VBT_CON0            (PMU_BASE + 0x0870)
#define VBT_CON1            (PMU_BASE + 0x0874)
#define VBT_CON2            (PMU_BASE + 0x0878)
#define VSIM_CON0           (PMU_BASE + 0x0880)
#define VSIM_CON1           (PMU_BASE + 0x0884)
#define VSIM_CON2           (PMU_BASE + 0x0888)
#define VSIM_CON3           (PMU_BASE + 0x088C)
#define VSIM2_CON0          (PMU_BASE + 0x0890)
#define VSIM2_CON1          (PMU_BASE + 0x0894)
#define VSIM2_CON2          (PMU_BASE + 0x0898)
#define VSIM2_CON3          (PMU_BASE + 0x089C)
#define VRTC_CON0           (PMU_BASE + 0x08A0)
#define VRTC_CON1           (PMU_BASE + 0x08A4)
#define VRTC_CON2           (PMU_BASE + 0x08A8)
#define VIBR_CON0           (PMU_BASE + 0x08B0)
#define VIBR_CON1           (PMU_BASE + 0x08B4)
#define VIBR_CON2           (PMU_BASE + 0x08B8)
#define VMC_CON0            (PMU_BASE + 0x08C0)
#define VMC_CON1            (PMU_BASE + 0x08C4)
#define VMC_CON2            (PMU_BASE + 0x08C8)
#define VIO18_CON0          (PMU_BASE + 0x08F0)
#define VIO18_CON1          (PMU_BASE + 0x08F4)
#define VIO18_CON2          (PMU_BASE + 0x08F8)
#define VCORE_CON0          (PMU_BASE + 0x0900)
#define VCORE_CON1          (PMU_BASE + 0x0904)
#define VCORE_CON2          (PMU_BASE + 0x0908)
#define VCORE_CON3          (PMU_BASE + 0x090C)
#define VCORE_CON4          (PMU_BASE + 0x0910)
#define VCORE_CON5          (PMU_BASE + 0x0914)
#define VCORE_CON6          (PMU_BASE + 0x0918)
#define CHR_CON0            (PMU_BASE + 0x0A00)
#define CHR_CON1            (PMU_BASE + 0x0A04)
#define CHR_CON2            (PMU_BASE + 0x0A08)
#define CHR_CON3            (PMU_BASE + 0x0A0C)
#define CHR_CON4            (PMU_BASE + 0x0A10)
#define CHR_CON5            (PMU_BASE + 0x0A14)
#define CHR_CON6            (PMU_BASE + 0x0A18)
#define CHR_CON7            (PMU_BASE + 0x0A1C)
#define CHR_CON8            (PMU_BASE + 0x0A20)
#define CHR_CON9            (PMU_BASE + 0x0A24)
#define CHR_CON10           (PMU_BASE + 0x0A28)
#define CHR_CON11           (PMU_BASE + 0x0A2C)
#define CHR_CON12           (PMU_BASE + 0x0A30)
#define CHR_CON13           (PMU_BASE + 0x0A34)
#define CHR_CON14           (PMU_BASE + 0x0A38)
#define STRUP_CON0          (PMU_BASE + 0x0A80)
#define STRUP_CON1          (PMU_BASE + 0x0A84)
#define STRUP_CON2          (PMU_BASE + 0x0A88)
#define STRUP_CON3          (PMU_BASE + 0x0A8C)
#define BOOST_CON3          (PMU_BASE + 0x0B0C)
#define ISINK0_CON0         (PMU_BASE + 0x0C00)
#define ISINK0_CON1         (PMU_BASE + 0x0C04)
#define ISINK0_CON2         (PMU_BASE + 0x0C08)
#define ISINK1_CON0         (PMU_BASE + 0x0C10)
#define ISINK2_CON0         (PMU_BASE + 0x0C20)
#define ISINK3_CON0         (PMU_BASE + 0x0C30)
#define ISINK4_CON0         (PMU_BASE + 0x0C40)
#define ISINK5_CON0         (PMU_BASE + 0x0C50)
#define KPLED_CON0          (PMU_BASE + 0x0C80)
#define KPLED_CON1          (PMU_BASE + 0x0C84)
#define SPK_CON0            (PMU_BASE + 0x0D00)
#define SPK_CON3            (PMU_BASE + 0x0D0C)
#define SPK_CON7            (PMU_BASE + 0x0D1C)
#define SPK_CON8            (PMU_BASE + 0x0D20)
#define PMU_OC_CON0         (PMU_BASE + 0x0E00)
#define PMU_OC_CON1         (PMU_BASE + 0x0E04)
#define PMU_OC_CON3         (PMU_BASE + 0x0E0C)
#define PMU_OC_CON4         (PMU_BASE + 0x0E10)
#define PMU_OC_CON5         (PMU_BASE + 0x0E14)
#define PMU_OC_CON7         (PMU_BASE + 0x0E1C)
#define PMU_OC_CON8         (PMU_BASE + 0x0E20)
#define PMU_OC_CON9         (PMU_BASE + 0x0E24)
#define PMU_OC_CONB         (PMU_BASE + 0x0E2C)
#define PMU_TEST_CON0       (PMU_BASE + 0x0F00)
#define PMU_TEST_CON1       (PMU_BASE + 0x0F04)
#define PMU_TEST_CON2       (PMU_BASE + 0x0F08)

///////////////////////////////////////////////////////////////////////////////

#define CON0_OFFSET           			0x00
#define CON1_OFFSET           			0x04
#define CON2_OFFSET           			0x08
#define CON3_OFFSET           			0x0C
#define CON4_OFFSET           			0x10
#define CON5_OFFSET           			0x14
#define CON6_OFFSET           			0x18
#define CON7_OFFSET           			0x1C
#define CON8_OFFSET           			0x20
#define CON9_OFFSET           			0x24
#define CON10_OFFSET           			0x28
#define CONA_OFFSET           			0x28
#define CON11_OFFSET           			0x2C
#define CONB_OFFSET           			0x2C
#define CON12_OFFSET           			0x30
#define CON13_OFFSET           			0x34
#define CON14_OFFSET           			0x38


#define SIMLS_PWDB_OFFSET               CON0_OFFSET
#define SIMLS_PWDB_MASK                 0x0100
#define SIMLS_PWDB_SHIFT                8

#define PRST_MODE_OFFSET                CON0_OFFSET
#define PRST_MODE_MASK                  0x0004
#define PRST_MODE_SHIFT                 2

#define ABIST_MODE_OFFSET               CON0_OFFSET
#define ABIST_MODE_MASK                 0x0002
#define ABIST_MODE_SHIFT                1

#define ACD_MODE_OFFSET                 CON0_OFFSET
#define ACD_MODE_MASK                   0x0001
#define ACD_MODE_SHIFT                  0

#define A_FUNC_DOE_OFFSET               CON0_OFFSET
#define A_FUNC_DOE_MASK                 0xFFFF
#define A_FUNC_DOE_SHIFT                0

#define XOSC_LPDTB_OFFSET               CON0_OFFSET
#define XOSC_LPDTB_MASK                 0x8000
#define XOSC_LPDTB_SHIFT                15

#define XOSC_CPDTB_OFFSET               CON0_OFFSET
#define XOSC_CPDTB_MASK                 0x4000
#define XOSC_CPDTB_SHIFT                14

#define XOSC_LPDRST_OFFSET              CON0_OFFSET
#define XOSC_LPDRST_MASK                0x0200
#define XOSC_LPDRST_SHIFT               9

#define XOSC_LPDEN_OFFSET               CON0_OFFSET
#define XOSC_LPDEN_MASK                 0x0100
#define XOSC_LPDEN_SHIFT                8

#define XOSC_PWDB_OFFSET                CON0_OFFSET
#define XOSC_PWDB_MASK                  0x0080
#define XOSC_PWDB_SHIFT                 7

#define XOSC_AMPSEL_OFFSET              CON0_OFFSET
#define XOSC_AMPSEL_MASK                0x0040
#define XOSC_AMPSEL_SHIFT               6

#define XOSC_AMPEN_OFFSET               CON0_OFFSET
#define XOSC_AMPEN_MASK                 0x0020
#define XOSC_AMPEN_SHIFT                5

#define XOSC_CALI_OFFSET                CON0_OFFSET
#define XOSC_CALI_MASK                  0x001F
#define XOSC_CALI_SHIFT                 0

#define ABIST_FINISH_OFFSET             CON0_OFFSET
#define ABIST_FINISH_MASK               0x8000
#define ABIST_FINISH_SHIFT              15

#define ABIST_PASS_OFFSET               CON0_OFFSET
#define ABIST_PASS_MASK                 0x4000
#define ABIST_PASS_SHIFT                14

#define ABIST_MON_CFG_OFFSET            CON0_OFFSET
#define ABIST_MON_CFG_MASK              0x0100
#define ABIST_MON_CFG_SHIFT             8

#define ABIST_HMON_SEL_OFFSET           CON1_OFFSET
#define ABIST_HMON_SEL_MASK             0xFF00
#define ABIST_HMON_SEL_SHIFT            8

#define ABIST_LMON_SEL_OFFSET           CON1_OFFSET
#define ABIST_LMON_SEL_MASK             0x00FF
#define ABIST_LMON_SEL_SHIFT            0

#define ABIST_HMON_OUT_OFFSET           CON2_OFFSET
#define ABIST_HMON_OUT_MASK             0x00F0
#define ABIST_HMON_OUT_SHIFT            4

#define ABIST_LMON_OUT_OFFSET           CON2_OFFSET
#define ABIST_LMON_OUT_MASK             0x000F
#define ABIST_LMON_OUT_SHIFT            0

#define ABIST_HMON_DATA_OFFSET          CON3_OFFSET
#define ABIST_HMON_DATA_MASK            0x00F0
#define ABIST_HMON_DATA_SHIFT           4

#define ABIST_LMON_DATA_OFFSET          CON3_OFFSET
#define ABIST_LMON_DATA_MASK            0x000F
#define ABIST_LMON_DATA_SHIFT           0

#define EOSC32_STP_CHOP_EN_OFFSET       CON0_OFFSET
#define EOSC32_STP_CHOP_EN_MASK         0x0002
#define EOSC32_STP_CHOP_EN_SHIFT        1

#define DCXO_STP_LVSH_EN_OFFSET         CON0_OFFSET
#define DCXO_STP_LVSH_EN_MASK           0x0001
#define DCXO_STP_LVSH_EN_SHIFT          0

#define EFUSE_CK_OFFSET                 CON0_OFFSET
#define EFUSE_CK_MASK                   0x0001
#define EFUSE_CK_SHIFT                  0

#define EFUSE_A_OFFSET                  CON1_OFFSET
#define EFUSE_A_MASK                    0x3F00
#define EFUSE_A_SHIFT                   8

#define EFUSE_DELSEL_OFFSET             CON1_OFFSET
#define EFUSE_DELSEL_MASK               0x0030
#define EFUSE_DELSEL_SHIFT              4

#define EFUSE_WE_OFFSET                 CON1_OFFSET
#define EFUSE_WE_MASK                   0x0004
#define EFUSE_WE_SHIFT                  2

#define EFUSE_RD_OFFSET                 CON1_OFFSET
#define EFUSE_RD_MASK                   0x0002
#define EFUSE_RD_SHIFT                  1

#define EFUSE_CKSEL_OFFSET              CON1_OFFSET
#define EFUSE_CKSEL_MASK                0x0001
#define EFUSE_CKSEL_SHIFT               0

#define EFUSE_OSC_OFFSET                CON2_OFFSET
#define EFUSE_OSC_MASK                  0xFC00
#define EFUSE_OSC_SHIFT                 10

#define SKIP_EFUSE_OUT_OFFSET           CON2_OFFSET
#define SKIP_EFUSE_OUT_MASK             0x0200
#define SKIP_EFUSE_OUT_SHIFT            9

#define EFUSE_FORCE_OFFSET              CON2_OFFSET
#define EFUSE_FORCE_MASK                0x0100
#define EFUSE_FORCE_SHIFT               8

#define EFUSE_MONSEL_OFFSET             CON2_OFFSET
#define EFUSE_MONSEL_MASK               0x000F
#define EFUSE_MONSEL_SHIFT              0

#define EFUSE_MONOUT_OFFSET             CON3_OFFSET
#define EFUSE_MONOUT_MASK               0x00FF
#define EFUSE_MONOUT_SHIFT              0

#define EFUSE_ICGR_OFFSET               CON4_OFFSET
#define EFUSE_ICGR_MASK                 0x0F00
#define EFUSE_ICGR_SHIFT                8

#define EFUSE_BGR_OFFSET                CON4_OFFSET
#define EFUSE_BGR_MASK                  0x001F
#define EFUSE_BGR_SHIFT                 0

#define VRF_STATUS_OFFSET               CON0_OFFSET
#define VRF_STATUS_MASK                 0x8000
#define VRF_STATUS_SHIFT                15

#define VRF_OC_FLAG_OFFSET              CON0_OFFSET
#define VRF_OC_FLAG_MASK                0x4000
#define VRF_OC_FLAG_SHIFT               14

#define VRF_OCFB_EN_OFFSET              CON0_OFFSET
#define VRF_OCFB_EN_MASK                0x2000
#define VRF_OCFB_EN_SHIFT               13

#define VRF_OC_AUTOFF_OFFSET            CON0_OFFSET
#define VRF_OC_AUTOFF_MASK              0x1000
#define VRF_OC_AUTOFF_SHIFT             12

#define VRF_STB_EN_OFFSET               CON0_OFFSET
#define VRF_STB_EN_MASK                 0x0800
#define VRF_STB_EN_SHIFT                11

#define VRF_NDIS_EN_OFFSET              CON0_OFFSET
#define VRF_NDIS_EN_MASK                0x0400
#define VRF_NDIS_EN_SHIFT               10

#define VRF_RS_OFFSET                   CON0_OFFSET
#define VRF_RS_MASK                     0x0004
#define VRF_RS_SHIFT                    2

#define VRF_ON_SEL_OFFSET               CON0_OFFSET
#define VRF_ON_SEL_MASK                 0x0002
#define VRF_ON_SEL_SHIFT                1

#define VRF_EN_OFFSET                   CON0_OFFSET
#define VRF_EN_MASK                     0x0001
#define VRF_EN_SHIFT                    0

#define VRF_CAL_OFFSET                  CON1_OFFSET
#define VRF_CAL_MASK                    0x00F0
#define VRF_CAL_SHIFT                   4

#define VRF_STB_TD_OFFSET               CON2_OFFSET
#define VRF_STB_TD_MASK                 0x00C0
#define VRF_STB_TD_SHIFT                6

#define VRF_OC_TD_OFFSET                CON2_OFFSET
#define VRF_OC_TD_MASK                  0x0030
#define VRF_OC_TD_SHIFT                 4

#define VRF_EN_FORCE_OFFSET             CON2_OFFSET
#define VRF_EN_FORCE_MASK               0x0001
#define VRF_EN_FORCE_SHIFT              0

#define OCFB_CAL_OFFSET                 CON3_OFFSET
#define OCFB_CAL_MASK                   0x6000
#define OCFB_CAL_SHIFT                  13

#define LDOS_TEST_EN_OFFSET             CON3_OFFSET
#define LDOS_TEST_EN_MASK               0x1000
#define LDOS_TEST_EN_SHIFT              12

#define VOSEL_TEST_OFFSET               CON3_OFFSET
#define VOSEL_TEST_MASK                 0x0F00
#define VOSEL_TEST_SHIFT                8

#define LDOS_RSV_OFFSET                 CON3_OFFSET
#define LDOS_RSV_MASK                   0x00FF
#define LDOS_RSV_SHIFT                  0

#define VTCXO_STATUS_OFFSET             CON0_OFFSET
#define VTCXO_STATUS_MASK               0x8000
#define VTCXO_STATUS_SHIFT              15

#define VTCXO_OC_FLAG_OFFSET            CON0_OFFSET
#define VTCXO_OC_FLAG_MASK              0x4000
#define VTCXO_OC_FLAG_SHIFT             14

#define VTCXO_OCFB_EN_OFFSET            CON0_OFFSET
#define VTCXO_OCFB_EN_MASK              0x2000
#define VTCXO_OCFB_EN_SHIFT             13

#define VTCXO_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VTCXO_OC_AUTOFF_MASK            0x1000
#define VTCXO_OC_AUTOFF_SHIFT           12

#define VTCXO_STB_EN_OFFSET             CON0_OFFSET
#define VTCXO_STB_EN_MASK               0x0800
#define VTCXO_STB_EN_SHIFT              11

#define VTCXO_NDIS_EN_OFFSET            CON0_OFFSET
#define VTCXO_NDIS_EN_MASK              0x0400
#define VTCXO_NDIS_EN_SHIFT             10

#define VTCXO_RS_OFFSET                 CON0_OFFSET
#define VTCXO_RS_MASK                   0x0004
#define VTCXO_RS_SHIFT                  2

#define VTCXO_ON_SEL_OFFSET             CON0_OFFSET
#define VTCXO_ON_SEL_MASK               0x0002
#define VTCXO_ON_SEL_SHIFT              1

#define VTCXO_EN_OFFSET                 CON0_OFFSET
#define VTCXO_EN_MASK                   0x0001
#define VTCXO_EN_SHIFT                  0

#define VTCXO_CAL_OFFSET                CON1_OFFSET
#define VTCXO_CAL_MASK                  0x00F0
#define VTCXO_CAL_SHIFT                 4

#define VTCXO_MODE_SEL_OFFSET           CON1_OFFSET
#define VTCXO_MODE_SEL_MASK             0x0002
#define VTCXO_MODE_SEL_SHIFT            1

#define VTCXO_LP_EN_OFFSET              CON1_OFFSET
#define VTCXO_LP_EN_MASK                0x0001
#define VTCXO_LP_EN_SHIFT               0

#define VTCXO_STB_TD_OFFSET             CON2_OFFSET
#define VTCXO_STB_TD_MASK               0x00C0
#define VTCXO_STB_TD_SHIFT              6

#define VTCXO_OC_TD_OFFSET              CON2_OFFSET
#define VTCXO_OC_TD_MASK                0x0030
#define VTCXO_OC_TD_SHIFT               4

#define CCI_SRCLKEN_OFFSET              CON2_OFFSET
#define CCI_SRCLKEN_MASK                0x0002
#define CCI_SRCLKEN_SHIFT               1

#define VTCXO_EN_FORCE_OFFSET           CON2_OFFSET
#define VTCXO_EN_FORCE_MASK             0x0001
#define VTCXO_EN_FORCE_SHIFT            0

#define VA_STATUS_OFFSET                CON0_OFFSET
#define VA_STATUS_MASK                  0x8000
#define VA_STATUS_SHIFT                 15

#define VA_OC_FLAG_OFFSET               CON0_OFFSET
#define VA_OC_FLAG_MASK                 0x4000
#define VA_OC_FLAG_SHIFT                14

#define VA_OCFB_EN_OFFSET               CON0_OFFSET
#define VA_OCFB_EN_MASK                 0x2000
#define VA_OCFB_EN_SHIFT                13

#define VA_OC_AUTOFF_OFFSET             CON0_OFFSET
#define VA_OC_AUTOFF_MASK               0x1000
#define VA_OC_AUTOFF_SHIFT              12

#define VA_STB_EN_OFFSET                CON0_OFFSET
#define VA_STB_EN_MASK                  0x0800
#define VA_STB_EN_SHIFT                 11

#define VA_NDIS_EN_OFFSET               CON0_OFFSET
#define VA_NDIS_EN_MASK                 0x0400
#define VA_NDIS_EN_SHIFT                10

#define VA_RS_OFFSET                    CON0_OFFSET
#define VA_RS_MASK                      0x0004
#define VA_RS_SHIFT                     2

#define VA_ON_SEL_OFFSET                CON0_OFFSET
#define VA_ON_SEL_MASK                  0x0002
#define VA_ON_SEL_SHIFT                 1

#define VA_EN_OFFSET                    CON0_OFFSET
#define VA_EN_MASK                      0x0001
#define VA_EN_SHIFT                     0

#define VA_CAL_OFFSET                   CON1_OFFSET
#define VA_CAL_MASK                     0x00F0
#define VA_CAL_SHIFT                    4

#define VA_MODE_SEL_OFFSET              CON1_OFFSET
#define VA_MODE_SEL_MASK                0x0002
#define VA_MODE_SEL_SHIFT               1

#define VA_LP_EN_OFFSET                 CON1_OFFSET
#define VA_LP_EN_MASK                   0x0001
#define VA_LP_EN_SHIFT                  0

#define VA_STB_TD_OFFSET                CON2_OFFSET
#define VA_STB_TD_MASK                  0x00C0
#define VA_STB_TD_SHIFT                 6

#define VA_OC_TD_OFFSET                 CON2_OFFSET
#define VA_OC_TD_MASK                   0x0030
#define VA_OC_TD_SHIFT                  4

#define VA_EN_FORCE_OFFSET              CON2_OFFSET
#define VA_EN_FORCE_MASK                0x0001
#define VA_EN_FORCE_SHIFT               0

#define VCAMA_STATUS_OFFSET             CON0_OFFSET
#define VCAMA_STATUS_MASK               0x8000
#define VCAMA_STATUS_SHIFT              15

#define VCAMA_OC_FLAG_OFFSET            CON0_OFFSET
#define VCAMA_OC_FLAG_MASK              0x4000
#define VCAMA_OC_FLAG_SHIFT             14

#define VCAMA_OCFB_EN_OFFSET            CON0_OFFSET
#define VCAMA_OCFB_EN_MASK              0x2000
#define VCAMA_OCFB_EN_SHIFT             13

#define VCAMA_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VCAMA_OC_AUTOFF_MASK            0x1000
#define VCAMA_OC_AUTOFF_SHIFT           12

#define VCAMA_STB_EN_OFFSET             CON0_OFFSET
#define VCAMA_STB_EN_MASK               0x0800
#define VCAMA_STB_EN_SHIFT              11

#define VCAMA_NDIS_EN_OFFSET            CON0_OFFSET
#define VCAMA_NDIS_EN_MASK              0x0400
#define VCAMA_NDIS_EN_SHIFT             10

#define VCAMA_VOSEL_OFFSET              CON0_OFFSET
#define VCAMA_VOSEL_MASK                0x0030
#define VCAMA_VOSEL_SHIFT               4

#define VCAMA_RS_OFFSET                 CON0_OFFSET
#define VCAMA_RS_MASK                   0x0004
#define VCAMA_RS_SHIFT                  2

#define VCAMA_ON_SEL_OFFSET             CON0_OFFSET
#define VCAMA_ON_SEL_MASK               0x0002
#define VCAMA_ON_SEL_SHIFT              1

#define VCAMA_EN_OFFSET                 CON0_OFFSET
#define VCAMA_EN_MASK                   0x0001
#define VCAMA_EN_SHIFT                  0

#define VCAMA_CAL_OFFSET                CON1_OFFSET
#define VCAMA_CAL_MASK                  0x00F0
#define VCAMA_CAL_SHIFT                 4

#define VCAMA_STB_TD_OFFSET             CON2_OFFSET
#define VCAMA_STB_TD_MASK               0x00C0
#define VCAMA_STB_TD_SHIFT              6

#define VCAMA_OC_TD_OFFSET              CON2_OFFSET
#define VCAMA_OC_TD_MASK                0x0030
#define VCAMA_OC_TD_SHIFT               4

#define VCAMA_EN_FORCE_OFFSET           CON2_OFFSET
#define VCAMA_EN_FORCE_MASK             0x0001
#define VCAMA_EN_FORCE_SHIFT            0

#define VCAMD_STATUS_OFFSET             CON0_OFFSET
#define VCAMD_STATUS_MASK               0x8000
#define VCAMD_STATUS_SHIFT              15

#define VCAMD_OC_FLAG_OFFSET            CON0_OFFSET
#define VCAMD_OC_FLAG_MASK              0x4000
#define VCAMD_OC_FLAG_SHIFT             14

#define VCAMD_OCFB_EN_OFFSET            CON0_OFFSET
#define VCAMD_OCFB_EN_MASK              0x2000
#define VCAMD_OCFB_EN_SHIFT             13

#define VCAMD_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VCAMD_OC_AUTOFF_MASK            0x1000
#define VCAMD_OC_AUTOFF_SHIFT           12

#define VCAMD_STB_EN_OFFSET             CON0_OFFSET
#define VCAMD_STB_EN_MASK               0x0800
#define VCAMD_STB_EN_SHIFT              11

#define VCAMD_NDIS_EN_OFFSET            CON0_OFFSET
#define VCAMD_NDIS_EN_MASK              0x0400
#define VCAMD_NDIS_EN_SHIFT             10

#define VCAMD_VOSEL_OFFSET              CON0_OFFSET
#define VCAMD_VOSEL_MASK                0x0070
#define VCAMD_VOSEL_SHIFT               4

#define VCAMD_RS_OFFSET                 CON0_OFFSET
#define VCAMD_RS_MASK                   0x0004
#define VCAMD_RS_SHIFT                  2

#define VCAMD_ON_SEL_OFFSET             CON0_OFFSET
#define VCAMD_ON_SEL_MASK               0x0002
#define VCAMD_ON_SEL_SHIFT              1

#define VCAMD_EN_OFFSET                 CON0_OFFSET
#define VCAMD_EN_MASK                   0x0001
#define VCAMD_EN_SHIFT                  0

#define VCAMD_CAL_OFFSET                CON1_OFFSET
#define VCAMD_CAL_MASK                  0x00F0
#define VCAMD_CAL_SHIFT                 4

#define VCAMD_STB_TD_OFFSET             CON2_OFFSET
#define VCAMD_STB_TD_MASK               0x00C0
#define VCAMD_STB_TD_SHIFT              6

#define VCAMD_OC_TD_OFFSET              CON2_OFFSET
#define VCAMD_OC_TD_MASK                0x0030
#define VCAMD_OC_TD_SHIFT               4

#define VCAMD_EN_FORCE_OFFSET           CON2_OFFSET
#define VCAMD_EN_FORCE_MASK             0x0001
#define VCAMD_EN_FORCE_SHIFT            0

#define VIO28_STATUS_OFFSET             CON0_OFFSET
#define VIO28_STATUS_MASK               0x8000
#define VIO28_STATUS_SHIFT              15

#define VIO28_OC_FLAG_OFFSET            CON0_OFFSET
#define VIO28_OC_FLAG_MASK              0x4000
#define VIO28_OC_FLAG_SHIFT             14

#define VIO28_OCFB_EN_OFFSET            CON0_OFFSET
#define VIO28_OCFB_EN_MASK              0x2000
#define VIO28_OCFB_EN_SHIFT             13

#define VIO28_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VIO28_OC_AUTOFF_MASK            0x1000
#define VIO28_OC_AUTOFF_SHIFT           12

#define VIO28_STB_EN_OFFSET             CON0_OFFSET
#define VIO28_STB_EN_MASK               0x0800
#define VIO28_STB_EN_SHIFT              11

#define VIO28_NDIS_EN_OFFSET            CON0_OFFSET
#define VIO28_NDIS_EN_MASK              0x0400
#define VIO28_NDIS_EN_SHIFT             10

#define VIO28_RS_OFFSET                 CON0_OFFSET
#define VIO28_RS_MASK                   0x0004
#define VIO28_RS_SHIFT                  2

#define VIO28_ON_SEL_OFFSET             CON0_OFFSET
#define VIO28_ON_SEL_MASK               0x0002
#define VIO28_ON_SEL_SHIFT              1

#define VIO28_EN_OFFSET                 CON0_OFFSET
#define VIO28_EN_MASK                   0x0001
#define VIO28_EN_SHIFT                  0

#define VIO28_CAL_OFFSET                CON1_OFFSET
#define VIO28_CAL_MASK                  0x00F0
#define VIO28_CAL_SHIFT                 4

#define VIO28_STB_TD_OFFSET             CON2_OFFSET
#define VIO28_STB_TD_MASK               0x00C0
#define VIO28_STB_TD_SHIFT              6

#define VIO28_OC_TD_OFFSET              CON2_OFFSET
#define VIO28_OC_TD_MASK                0x0030
#define VIO28_OC_TD_SHIFT               4

#define VIO28_EN_FORCE_OFFSET           CON2_OFFSET
#define VIO28_EN_FORCE_MASK             0x0001
#define VIO28_EN_FORCE_SHIFT            0

#define VUSB_STATUS_OFFSET              CON0_OFFSET
#define VUSB_STATUS_MASK                0x8000
#define VUSB_STATUS_SHIFT               15

#define VUSB_OC_FLAG_OFFSET             CON0_OFFSET
#define VUSB_OC_FLAG_MASK               0x4000
#define VUSB_OC_FLAG_SHIFT              14

#define VUSB_OCFB_EN_OFFSET             CON0_OFFSET
#define VUSB_OCFB_EN_MASK               0x2000
#define VUSB_OCFB_EN_SHIFT              13

#define VUSB_OC_AUTOFF_OFFSET           CON0_OFFSET
#define VUSB_OC_AUTOFF_MASK             0x1000
#define VUSB_OC_AUTOFF_SHIFT            12

#define VUSB_STB_EN_OFFSET              CON0_OFFSET
#define VUSB_STB_EN_MASK                0x0800
#define VUSB_STB_EN_SHIFT               11

#define VUSB_NDIS_EN_OFFSET             CON0_OFFSET
#define VUSB_NDIS_EN_MASK               0x0400
#define VUSB_NDIS_EN_SHIFT              10

#define VUSB_RS_OFFSET                  CON0_OFFSET
#define VUSB_RS_MASK                    0x0004
#define VUSB_RS_SHIFT                   2

#define VUSB_ON_SEL_OFFSET              CON0_OFFSET
#define VUSB_ON_SEL_MASK                0x0002
#define VUSB_ON_SEL_SHIFT               1

#define VUSB_EN_OFFSET                  CON0_OFFSET
#define VUSB_EN_MASK                    0x0001
#define VUSB_EN_SHIFT                   0

#define VUSB_CAL_OFFSET                 CON1_OFFSET
#define VUSB_CAL_MASK                   0x00F0
#define VUSB_CAL_SHIFT                  4

#define VUSB_STB_TD_OFFSET              CON2_OFFSET
#define VUSB_STB_TD_MASK                0x00C0
#define VUSB_STB_TD_SHIFT               6

#define VUSB_OC_TD_OFFSET               CON2_OFFSET
#define VUSB_OC_TD_MASK                 0x0030
#define VUSB_OC_TD_SHIFT                4

#define VUSB_EN_FORCE_OFFSET            CON2_OFFSET
#define VUSB_EN_FORCE_MASK              0x0001
#define VUSB_EN_FORCE_SHIFT             0

#define VBT_STATUS_OFFSET               CON0_OFFSET
#define VBT_STATUS_MASK                 0x8000
#define VBT_STATUS_SHIFT                15

#define VBT_OC_FLAG_OFFSET              CON0_OFFSET
#define VBT_OC_FLAG_MASK                0x4000
#define VBT_OC_FLAG_SHIFT               14

#define VBT_OCFB_EN_OFFSET              CON0_OFFSET
#define VBT_OCFB_EN_MASK                0x2000
#define VBT_OCFB_EN_SHIFT               13

#define VBT_OC_AUTOFF_OFFSET            CON0_OFFSET
#define VBT_OC_AUTOFF_MASK              0x1000
#define VBT_OC_AUTOFF_SHIFT             12

#define VBT_STB_EN_OFFSET               CON0_OFFSET
#define VBT_STB_EN_MASK                 0x0800
#define VBT_STB_EN_SHIFT                11

#define VBT_NDIS_EN_OFFSET              CON0_OFFSET
#define VBT_NDIS_EN_MASK                0x0400
#define VBT_NDIS_EN_SHIFT               10

#define VBT_VOSEL_OFFSET                CON0_OFFSET
#define VBT_VOSEL_MASK                  0x0070
#define VBT_VOSEL_SHIFT                 4

#define VBT_RS_OFFSET                   CON0_OFFSET
#define VBT_RS_MASK                     0x0004
#define VBT_RS_SHIFT                    2

#define VBT_ON_SEL_OFFSET               CON0_OFFSET
#define VBT_ON_SEL_MASK                 0x0002
#define VBT_ON_SEL_SHIFT                1

#define VBT_EN_OFFSET                   CON0_OFFSET
#define VBT_EN_MASK                     0x0001
#define VBT_EN_SHIFT                    0

#define VBT_CAL_OFFSET                  CON1_OFFSET
#define VBT_CAL_MASK                    0x00F0
#define VBT_CAL_SHIFT                   4

#define VBT_STB_TD_OFFSET               CON2_OFFSET
#define VBT_STB_TD_MASK                 0x00C0
#define VBT_STB_TD_SHIFT                6

#define VBT_OC_TD_OFFSET                CON2_OFFSET
#define VBT_OC_TD_MASK                  0x0030
#define VBT_OC_TD_SHIFT                 4

#define VBT_EN_FORCE_OFFSET             CON2_OFFSET
#define VBT_EN_FORCE_MASK               0x0001
#define VBT_EN_FORCE_SHIFT              0

#define VSIM_STATUS_OFFSET              CON0_OFFSET
#define VSIM_STATUS_MASK                0x8000
#define VSIM_STATUS_SHIFT               15

#define VSIM_OC_FLAG_OFFSET             CON0_OFFSET
#define VSIM_OC_FLAG_MASK               0x4000
#define VSIM_OC_FLAG_SHIFT              14

#define VSIM_OCFB_EN_OFFSET             CON0_OFFSET
#define VSIM_OCFB_EN_MASK               0x2000
#define VSIM_OCFB_EN_SHIFT              13

#define VSIM_OC_AUTOFF_OFFSET           CON0_OFFSET
#define VSIM_OC_AUTOFF_MASK             0x1000
#define VSIM_OC_AUTOFF_SHIFT            12

#define VSIM_STB_EN_OFFSET              CON0_OFFSET
#define VSIM_STB_EN_MASK                0x0800
#define VSIM_STB_EN_SHIFT               11

#define VSIM_NDIS_EN_OFFSET             CON0_OFFSET
#define VSIM_NDIS_EN_MASK               0x0400
#define VSIM_NDIS_EN_SHIFT              10

#define VSIM_VOSEL_OFFSET               CON0_OFFSET
#define VSIM_VOSEL_MASK                 0x0010
#define VSIM_VOSEL_SHIFT                4

#define VSIM_RS_OFFSET                  CON0_OFFSET
#define VSIM_RS_MASK                    0x0004
#define VSIM_RS_SHIFT                   2

#define VSIM_ON_SEL_OFFSET              CON0_OFFSET
#define VSIM_ON_SEL_MASK                0x0002
#define VSIM_ON_SEL_SHIFT               1

#define VSIM_EN_OFFSET                  CON0_OFFSET
#define VSIM_EN_MASK                    0x0001
#define VSIM_EN_SHIFT                   0

#define VSIM_CAL_OFFSET                 CON1_OFFSET
#define VSIM_CAL_MASK                   0x00F0
#define VSIM_CAL_SHIFT                  4

#define VSIM_STB_TD_OFFSET              CON2_OFFSET
#define VSIM_STB_TD_MASK                0x00C0
#define VSIM_STB_TD_SHIFT               6

#define VSIM_OC_TD_OFFSET               CON2_OFFSET
#define VSIM_OC_TD_MASK                 0x0030
#define VSIM_OC_TD_SHIFT                4

#define VSIM_GPLDO_EN_OFFSET            CON2_OFFSET
#define VSIM_GPLDO_EN_MASK              0x0002
#define VSIM_GPLDO_EN_SHIFT             1

#define VSIM_EN_FORCE_OFFSET            CON2_OFFSET
#define VSIM_EN_FORCE_MASK              0x0001
#define VSIM_EN_FORCE_SHIFT             0

#define VSIM_CSTOP_OFFSET               CON3_OFFSET
#define VSIM_CSTOP_MASK                 0x0400
#define VSIM_CSTOP_SHIFT                10

#define VSIM_SRP_OFFSET                 CON3_OFFSET
#define VSIM_SRP_MASK                   0x0300
#define VSIM_SRP_SHIFT                  8

#define VSIM_SRN_OFFSET                 CON3_OFFSET
#define VSIM_SRN_MASK                   0x00C0
#define VSIM_SRN_SHIFT                  6

#define VSIM_BIAS_OFFSET                CON3_OFFSET
#define VSIM_BIAS_MASK                  0x0030
#define VSIM_BIAS_SHIFT                 4

#define SIMIO_DRV_OFFSET                CON3_OFFSET
#define SIMIO_DRV_MASK                  0x000E
#define SIMIO_DRV_SHIFT                 1

#define VSIM2_STATUS_OFFSET             CON0_OFFSET
#define VSIM2_STATUS_MASK               0x8000
#define VSIM2_STATUS_SHIFT              15

#define VSIM2_OC_FLAG_OFFSET            CON0_OFFSET
#define VSIM2_OC_FLAG_MASK              0x4000
#define VSIM2_OC_FLAG_SHIFT             14

#define VSIM2_OCFB_EN_OFFSET            CON0_OFFSET
#define VSIM2_OCFB_EN_MASK              0x2000
#define VSIM2_OCFB_EN_SHIFT             13

#define VSIM2_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VSIM2_OC_AUTOFF_MASK            0x1000
#define VSIM2_OC_AUTOFF_SHIFT           12

#define VSIM2_STB_EN_OFFSET             CON0_OFFSET
#define VSIM2_STB_EN_MASK               0x0800
#define VSIM2_STB_EN_SHIFT              11

#define VSIM2_NDIS_EN_OFFSET            CON0_OFFSET
#define VSIM2_NDIS_EN_MASK              0x0400
#define VSIM2_NDIS_EN_SHIFT             10

#define VSIM2_VOSEL_OFFSET              CON0_OFFSET
#define VSIM2_VOSEL_MASK                0x0070
#define VSIM2_VOSEL_SHIFT               4

#define VSIM2_RS_OFFSET                 CON0_OFFSET
#define VSIM2_RS_MASK                   0x0004
#define VSIM2_RS_SHIFT                  2

#define VSIM2_ON_SEL_OFFSET             CON0_OFFSET
#define VSIM2_ON_SEL_MASK               0x0002
#define VSIM2_ON_SEL_SHIFT              1

#define VSIM2_EN_OFFSET                 CON0_OFFSET
#define VSIM2_EN_MASK                   0x0001
#define VSIM2_EN_SHIFT                  0

#define VSIM2_CAL_OFFSET                CON1_OFFSET
#define VSIM2_CAL_MASK                  0x00F0
#define VSIM2_CAL_SHIFT                 4

#define VSIM2_STB_TD_OFFSET             CON2_OFFSET
#define VSIM2_STB_TD_MASK               0x00C0
#define VSIM2_STB_TD_SHIFT              6

#define VSIM2_OC_TD_OFFSET              CON2_OFFSET
#define VSIM2_OC_TD_MASK                0x0030
#define VSIM2_OC_TD_SHIFT               4

#define VSIM2_GPLDO_EN_OFFSET           CON2_OFFSET
#define VSIM2_GPLDO_EN_MASK             0x0002
#define VSIM2_GPLDO_EN_SHIFT            1

#define VSIM2_EN_FORCE_OFFSET           CON2_OFFSET
#define VSIM2_EN_FORCE_MASK             0x0001
#define VSIM2_EN_FORCE_SHIFT            0

#define GPIO_SIO2_OFFSET                CON3_OFFSET
#define GPIO_SIO2_MASK                  0x8000
#define GPIO_SIO2_SHIFT                 15

#define GPIO_SCLK2_OFFSET               CON3_OFFSET
#define GPIO_SCLK2_MASK                 0x4000
#define GPIO_SCLK2_SHIFT                14

#define GPIO_SRST2_OFFSET               CON3_OFFSET
#define GPIO_SRST2_MASK                 0x2000
#define GPIO_SRST2_SHIFT                13

#define SIM2_CSTOP_OFFSET               CON3_OFFSET
#define SIM2_CSTOP_MASK                 0x0400
#define SIM2_CSTOP_SHIFT                10

#define SIM2_SRP_OFFSET                 CON3_OFFSET
#define SIM2_SRP_MASK                   0x0300
#define SIM2_SRP_SHIFT                  8

#define SIM2_SRN_OFFSET                 CON3_OFFSET
#define SIM2_SRN_MASK                   0x00C0
#define SIM2_SRN_SHIFT                  6

#define SIM2_BIAS_OFFSET                CON3_OFFSET
#define SIM2_BIAS_MASK                  0x0030
#define SIM2_BIAS_SHIFT                 4

#define SIMIO2_DRV_OFFSET               CON3_OFFSET
#define SIMIO2_DRV_MASK                 0x000E
#define SIMIO2_DRV_SHIFT                1

#define SIM2_GPIO_EN_OFFSET             CON3_OFFSET
#define SIM2_GPIO_EN_MASK               0x0001
#define SIM2_GPIO_EN_SHIFT              0

#define VRTC_STATUS_OFFSET              CON0_OFFSET
#define VRTC_STATUS_MASK                0x8000
#define VRTC_STATUS_SHIFT               15

#define VRTC_OC_FLAG_OFFSET             CON0_OFFSET
#define VRTC_OC_FLAG_MASK               0x4000
#define VRTC_OC_FLAG_SHIFT              14

#define VRTC_OCFB_EN_OFFSET             CON0_OFFSET
#define VRTC_OCFB_EN_MASK               0x2000
#define VRTC_OCFB_EN_SHIFT              13

#define VRTC_OC_AUTOFF_OFFSET           CON0_OFFSET
#define VRTC_OC_AUTOFF_MASK             0x1000
#define VRTC_OC_AUTOFF_SHIFT            12

#define VRTC_STB_EN_OFFSET              CON0_OFFSET
#define VRTC_STB_EN_MASK                0x0800
#define VRTC_STB_EN_SHIFT               11

#define VRTC_NDIS_EN_OFFSET             CON0_OFFSET
#define VRTC_NDIS_EN_MASK               0x0400
#define VRTC_NDIS_EN_SHIFT              10

#define VRTC_RS_OFFSET                  CON0_OFFSET
#define VRTC_RS_MASK                    0x0004
#define VRTC_RS_SHIFT                   2

#define VRTC_ON_SEL_OFFSET              CON0_OFFSET
#define VRTC_ON_SEL_MASK                0x0002
#define VRTC_ON_SEL_SHIFT               1

#define VRTC_EN_OFFSET                  CON0_OFFSET
#define VRTC_EN_MASK                    0x0001
#define VRTC_EN_SHIFT                   0

#define VRTC_CAL_OFFSET                 CON1_OFFSET
#define VRTC_CAL_MASK                   0x00F0
#define VRTC_CAL_SHIFT                  4

#define VRTC_STB_TD_OFFSET              CON2_OFFSET
#define VRTC_STB_TD_MASK                0x00C0
#define VRTC_STB_TD_SHIFT               6

#define VRTC_OC_TD_OFFSET               CON2_OFFSET
#define VRTC_OC_TD_MASK                 0x0030
#define VRTC_OC_TD_SHIFT                4

#define VRTC_EN_FORCE_OFFSET            CON2_OFFSET
#define VRTC_EN_FORCE_MASK              0x0001
#define VRTC_EN_FORCE_SHIFT             0

#define VIBR_STATUS_OFFSET              CON0_OFFSET
#define VIBR_STATUS_MASK                0x8000
#define VIBR_STATUS_SHIFT               15

#define VIBR_OC_FLAG_OFFSET             CON0_OFFSET
#define VIBR_OC_FLAG_MASK               0x4000
#define VIBR_OC_FLAG_SHIFT              14

#define VIBR_OCFB_EN_OFFSET             CON0_OFFSET
#define VIBR_OCFB_EN_MASK               0x2000
#define VIBR_OCFB_EN_SHIFT              13

#define VIBR_OC_AUTOFF_OFFSET           CON0_OFFSET
#define VIBR_OC_AUTOFF_MASK             0x1000
#define VIBR_OC_AUTOFF_SHIFT            12

#define VIBR_STB_EN_OFFSET              CON0_OFFSET
#define VIBR_STB_EN_MASK                0x0800
#define VIBR_STB_EN_SHIFT               11

#define VIBR_NDIS_EN_OFFSET             CON0_OFFSET
#define VIBR_NDIS_EN_MASK               0x0400
#define VIBR_NDIS_EN_SHIFT              10

#define VIBR_VOSEL_OFFSET               CON0_OFFSET
#define VIBR_VOSEL_MASK                 0x0070
#define VIBR_VOSEL_SHIFT                4

#define VIBR_RS_OFFSET                  CON0_OFFSET
#define VIBR_RS_MASK                    0x0004
#define VIBR_RS_SHIFT                   2

#define VIBR_ON_SEL_OFFSET              CON0_OFFSET
#define VIBR_ON_SEL_MASK                0x0002
#define VIBR_ON_SEL_SHIFT               1

#define VIBR_EN_OFFSET                  CON0_OFFSET
#define VIBR_EN_MASK                    0x0001
#define VIBR_EN_SHIFT                   0

#define VIBR_STB_SEL_OFFSET             CON1_OFFSET
#define VIBR_STB_SEL_MASK               0x1000
#define VIBR_STB_SEL_SHIFT              12

#define VIBR_CAL_OFFSET                 CON1_OFFSET
#define VIBR_CAL_MASK                   0x00F0
#define VIBR_CAL_SHIFT                  4

#define VIBR_STB_TD_OFFSET              CON2_OFFSET
#define VIBR_STB_TD_MASK                0x00C0
#define VIBR_STB_TD_SHIFT               6

#define VIBR_OC_TD_OFFSET               CON2_OFFSET
#define VIBR_OC_TD_MASK                 0x0030
#define VIBR_OC_TD_SHIFT                4

#define VIBR_EN_FORCE_OFFSET            CON2_OFFSET
#define VIBR_EN_FORCE_MASK              0x0001
#define VIBR_EN_FORCE_SHIFT             0

#define VMC_STATUS_OFFSET               CON0_OFFSET
#define VMC_STATUS_MASK                 0x8000
#define VMC_STATUS_SHIFT                15

#define VMC_OC_FLAG_OFFSET              CON0_OFFSET
#define VMC_OC_FLAG_MASK                0x4000
#define VMC_OC_FLAG_SHIFT               14

#define VMC_OCFB_EN_OFFSET              CON0_OFFSET
#define VMC_OCFB_EN_MASK                0x2000
#define VMC_OCFB_EN_SHIFT               13

#define VMC_OC_AUTOFF_OFFSET            CON0_OFFSET
#define VMC_OC_AUTOFF_MASK              0x1000
#define VMC_OC_AUTOFF_SHIFT             12

#define VMC_STB_EN_OFFSET               CON0_OFFSET
#define VMC_STB_EN_MASK                 0x0800
#define VMC_STB_EN_SHIFT                11

#define VMC_NDIS_EN_OFFSET              CON0_OFFSET
#define VMC_NDIS_EN_MASK                0x0400
#define VMC_NDIS_EN_SHIFT               10

#define VMC_VOSEL_OFFSET                CON0_OFFSET
#define VMC_VOSEL_MASK                  0x0070
#define VMC_VOSEL_SHIFT                 4

#define VMC_RS_OFFSET                   CON0_OFFSET
#define VMC_RS_MASK                     0x0004
#define VMC_RS_SHIFT                    2

#define VMC_ON_SEL_OFFSET               CON0_OFFSET
#define VMC_ON_SEL_MASK                 0x0002
#define VMC_ON_SEL_SHIFT                1

#define VMC_EN_OFFSET                   CON0_OFFSET
#define VMC_EN_MASK                     0x0001
#define VMC_EN_SHIFT                    0

#define VMC_STB_SEL_OFFSET              CON1_OFFSET
#define VMC_STB_SEL_MASK                0x1000
#define VMC_STB_SEL_SHIFT               12

#define VMC_CAL_OFFSET                  CON1_OFFSET
#define VMC_CAL_MASK                    0x00F0
#define VMC_CAL_SHIFT                   4

#define VMC_STB_TD_OFFSET               CON2_OFFSET
#define VMC_STB_TD_MASK                 0x00C0
#define VMC_STB_TD_SHIFT                6

#define VMC_OC_TD_OFFSET                CON2_OFFSET
#define VMC_OC_TD_MASK                  0x0030
#define VMC_OC_TD_SHIFT                 4

#define VMC_EN_FORCE_OFFSET             CON2_OFFSET
#define VMC_EN_FORCE_MASK               0x0001
#define VMC_EN_FORCE_SHIFT              0

#define VIO18_STATUS_OFFSET             CON0_OFFSET
#define VIO18_STATUS_MASK               0x8000
#define VIO18_STATUS_SHIFT              15

#define VIO18_OC_FLAG_OFFSET            CON0_OFFSET
#define VIO18_OC_FLAG_MASK              0x4000
#define VIO18_OC_FLAG_SHIFT             14

#define VIO18_OCFB_EN_OFFSET            CON0_OFFSET
#define VIO18_OCFB_EN_MASK              0x2000
#define VIO18_OCFB_EN_SHIFT             13

#define VIO18_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VIO18_OC_AUTOFF_MASK            0x1000
#define VIO18_OC_AUTOFF_SHIFT           12

#define VIO18_NDIS_EN_OFFSET            CON0_OFFSET
#define VIO18_NDIS_EN_MASK              0x0400
#define VIO18_NDIS_EN_SHIFT             10

#define VIO18_RS_OFFSET                 CON0_OFFSET
#define VIO18_RS_MASK                   0x0004
#define VIO18_RS_SHIFT                  2

#define VIO18_ON_SEL_OFFSET             CON0_OFFSET
#define VIO18_ON_SEL_MASK               0x0002
#define VIO18_ON_SEL_SHIFT              1

#define VIO18_EN_OFFSET                 CON0_OFFSET
#define VIO18_EN_MASK                   0x0001
#define VIO18_EN_SHIFT                  0

#define VIO18_CAL_OFFSET                CON1_OFFSET
#define VIO18_CAL_MASK                  0x00F0
#define VIO18_CAL_SHIFT                 4

#define VIO18_STB_TD_OFFSET             CON2_OFFSET
#define VIO18_STB_TD_MASK               0x00C0
#define VIO18_STB_TD_SHIFT              6

#define VIO18_OC_TD_OFFSET              CON2_OFFSET
#define VIO18_OC_TD_MASK                0x0030
#define VIO18_OC_TD_SHIFT               4

#define VIO18_EN_FORCE_OFFSET           CON2_OFFSET
#define VIO18_EN_FORCE_MASK             0x0001
#define VIO18_EN_FORCE_SHIFT            0

#define VSF_STATUS_OFFSET               CON0_OFFSET
#define VSF_STATUS_MASK                 0x8000
#define VSF_STATUS_SHIFT                15

#define VSF_OC_FLAG_OFFSET              CON0_OFFSET
#define VSF_OC_FLAG_MASK                0x4000
#define VSF_OC_FLAG_SHIFT               14

#define VSF_OCFB_EN_OFFSET              CON0_OFFSET
#define VSF_OCFB_EN_MASK                0x2000
#define VSF_OCFB_EN_SHIFT               13

#define VSF_OC_AUTOFF_OFFSET            CON0_OFFSET
#define VSF_OC_AUTOFF_MASK              0x1000
#define VSF_OC_AUTOFF_SHIFT             12

#define VSF_STB_EN_OFFSET               CON0_OFFSET
#define VSF_STB_EN_MASK                 0x0800
#define VSF_STB_EN_SHIFT                11

#define VSF_NDIS_EN_OFFSET              CON0_OFFSET
#define VSF_NDIS_EN_MASK                0x0400
#define VSF_NDIS_EN_SHIFT               10

#define VSF_VOSEL_OFFSET                CON0_OFFSET
#define VSF_VOSEL_MASK                  0x0070
#define VSF_VOSEL_SHIFT                 4

#define VSF_RS_OFFSET                   CON0_OFFSET
#define VSF_RS_MASK                     0x0004
#define VSF_RS_SHIFT                    2

#define VSF_EN_OFFSET                   CON0_OFFSET
#define VSF_EN_MASK                     0x0001
#define VSF_EN_SHIFT                    0

#define VSF_CAL_OFFSET                  CON1_OFFSET
#define VSF_CAL_MASK                    0x00F0
#define VSF_CAL_SHIFT                   4

#define VSF_STB_TD_OFFSET               CON2_OFFSET
#define VSF_STB_TD_MASK                 0x00C0
#define VSF_STB_TD_SHIFT                6

#define VSF_OC_TD_OFFSET                CON2_OFFSET
#define VSF_OC_TD_MASK                  0x0030
#define VSF_OC_TD_SHIFT                 4

#define VSF_EN_FORCE_OFFSET             CON2_OFFSET
#define VSF_EN_FORCE_MASK               0x0001
#define VSF_EN_FORCE_SHIFT              0

#define VSF_AUTOFF_DLY_SEL_OFFSET       CON3_OFFSET
#define VSF_AUTOFF_DLY_SEL_MASK         0x00F0
#define VSF_AUTOFF_DLY_SEL_SHIFT        4

#define VSF_AUTOFF_EN_OFFSET            CON3_OFFSET
#define VSF_AUTOFF_EN_MASK              0x0001
#define VSF_AUTOFF_EN_SHIFT             0

#define VCORE_STATUS_OFFSET             CON0_OFFSET
#define VCORE_STATUS_MASK               0x8000
#define VCORE_STATUS_SHIFT              15

#define VCORE_OC_FLAG_OFFSET            CON0_OFFSET
#define VCORE_OC_FLAG_MASK              0x4000
#define VCORE_OC_FLAG_SHIFT             14

#define VCORE_OCFB_EN_OFFSET            CON0_OFFSET
#define VCORE_OCFB_EN_MASK              0x2000
#define VCORE_OCFB_EN_SHIFT             13

#define VCORE_OC_AUTOFF_OFFSET          CON0_OFFSET
#define VCORE_OC_AUTOFF_MASK            0x1000
#define VCORE_OC_AUTOFF_SHIFT           12

#define VCORE_STB_EN_OFFSET             CON0_OFFSET
#define VCORE_STB_EN_MASK               0x0800
#define VCORE_STB_EN_SHIFT              11

#define VCORE_ANTIUNSH_DN_OFFSET        CON0_OFFSET
#define VCORE_ANTIUNSH_DN_MASK          0x0400
#define VCORE_ANTIUNSH_DN_SHIFT         10

#define VCORE_VFBADJ_OFFSET             CON0_OFFSET
#define VCORE_VFBADJ_MASK               0x01F0
#define VCORE_VFBADJ_SHIFT              4

#define VCORE_SFSTREN_OFFSET            CON0_OFFSET
#define VCORE_SFSTREN_MASK              0x0008
#define VCORE_SFSTREN_SHIFT             3

#define VCORE_RS_OFFSET                 CON0_OFFSET
#define VCORE_RS_MASK                   0x0004
#define VCORE_RS_SHIFT                  2

#define VCORE_ON_SEL_OFFSET             CON0_OFFSET
#define VCORE_ON_SEL_MASK               0x0002
#define VCORE_ON_SEL_SHIFT              1

#define VCORE_EN_OFFSET                 CON0_OFFSET
#define VCORE_EN_MASK                   0x0001
#define VCORE_EN_SHIFT                  0

#define VCORE_BUCK_STATUS_OFFSET        CON1_OFFSET
#define VCORE_BUCK_STATUS_MASK          0x8000
#define VCORE_BUCK_STATUS_SHIFT         15

#define VCORE_CPMCKSEL_OFFSET           CON1_OFFSET
#define VCORE_CPMCKSEL_MASK             0x0400
#define VCORE_CPMCKSEL_SHIFT            10

#define VCORE_VFBADJ_SLEEP_OFFSET       CON1_OFFSET
#define VCORE_VFBADJ_SLEEP_MASK         0x01F0
#define VCORE_VFBADJ_SLEEP_SHIFT        4

#define VCORE_CPMCKSEL_MODE_OFFSET      CON1_OFFSET
#define VCORE_CPMCKSEL_MODE_MASK        0x0002
#define VCORE_CPMCKSEL_MODE_SHIFT       1

#define VCORE_MODESET_OFFSET            CON1_OFFSET
#define VCORE_MODESET_MASK              0x0001
#define VCORE_MODESET_SHIFT             0

#define VCORE_VOSEL_OFFSET              CON2_OFFSET
#define VCORE_VOSEL_MASK                0x0007
#define VCORE_VOSEL_SHIFT               0

#define VCORE_ICAL_LDO_OFFSET           CON3_OFFSET
#define VCORE_ICAL_LDO_MASK             0x3000
#define VCORE_ICAL_LDO_SHIFT            12

#define VCORE_OC_WND_OFFSET             CON3_OFFSET
#define VCORE_OC_WND_MASK               0x0C00
#define VCORE_OC_WND_SHIFT              10

#define VCORE_OC_THD_OFFSET             CON3_OFFSET
#define VCORE_OC_THD_MASK               0x0300
#define VCORE_OC_THD_SHIFT              8

#define VCORE_STB_TD_OFFSET             CON3_OFFSET
#define VCORE_STB_TD_MASK               0x00C0
#define VCORE_STB_TD_SHIFT              6

#define VCORE_OC_TD_OFFSET              CON3_OFFSET
#define VCORE_OC_TD_MASK                0x0030
#define VCORE_OC_TD_SHIFT               4

#define VCORE_EN_FORCE_OFFSET           CON3_OFFSET
#define VCORE_EN_FORCE_MASK             0x0001
#define VCORE_EN_FORCE_SHIFT            0

#define VCORE_RSV_OFFSET                CON4_OFFSET
#define VCORE_RSV_MASK                  0xFF00
#define VCORE_RSV_SHIFT                 8

#define VCORE_ADJCKSEL_OFFSET           CON4_OFFSET
#define VCORE_ADJCKSEL_MASK             0x0070
#define VCORE_ADJCKSEL_SHIFT            4

#define VCORE_SLEW_OFFSET               CON4_OFFSET
#define VCORE_SLEW_MASK                 0x000C
#define VCORE_SLEW_SHIFT                2

#define VCORE_SLEW_NMOS_OFFSET          CON4_OFFSET
#define VCORE_SLEW_NMOS_MASK            0x0003
#define VCORE_SLEW_NMOS_SHIFT           0

#define VCORE_ZX_PDN_OFFSET             CON5_OFFSET
#define VCORE_ZX_PDN_MASK               0x8000
#define VCORE_ZX_PDN_SHIFT              15

#define VCORE_GMSEL_OFFSET              CON5_OFFSET
#define VCORE_GMSEL_MASK                0x4000
#define VCORE_GMSEL_SHIFT               14

#define VCORE_BURST_OFFSET              CON5_OFFSET
#define VCORE_BURST_MASK                0x3000
#define VCORE_BURST_SHIFT               12

#define VCORE_CSL_OFFSET                CON5_OFFSET
#define VCORE_CSL_MASK                  0x0700
#define VCORE_CSL_SHIFT                 8

#define VCORE_RZSEL_OFFSET              CON5_OFFSET
#define VCORE_RZSEL_MASK                0x0070
#define VCORE_RZSEL_SHIFT               4

#define VCORE_CSR_OFFSET                CON5_OFFSET
#define VCORE_CSR_MASK                  0x000F
#define VCORE_CSR_SHIFT                 0

#define BUCK_CKS_CHG_OFFSET             CON6_OFFSET
#define BUCK_CKS_CHG_MASK               0x8000
#define BUCK_CKS_CHG_SHIFT              15

#define BUCK_CKS_PRG_OFFSET             CON6_OFFSET
#define BUCK_CKS_PRG_MASK               0x003F
#define BUCK_CKS_PRG_SHIFT              0

#define VCDT_HV_VTH_OFFSET              CON0_OFFSET
#define VCDT_HV_VTH_MASK                0xF000
#define VCDT_HV_VTH_SHIFT               12

#define VCDT_LV_VTH_OFFSET              CON0_OFFSET
#define VCDT_LV_VTH_MASK                0x0F00
#define VCDT_LV_VTH_SHIFT               8

#define VCDT_HV_DET_OFFSET              CON0_OFFSET
#define VCDT_HV_DET_MASK                0x0080
#define VCDT_HV_DET_SHIFT               7

#define VCDT_LV_DET_OFFSET              CON0_OFFSET
#define VCDT_LV_DET_MASK                0x0040
#define VCDT_LV_DET_SHIFT               6

#define CHRDET_OFFSET                   CON0_OFFSET
#define CHRDET_MASK                     0x0020
#define CHRDET_SHIFT                    5

#define CHR_EN_OFFSET                   CON0_OFFSET
#define CHR_EN_MASK                     0x0010
#define CHR_EN_SHIFT                    4

#define CSDAC_EN_OFFSET                 CON0_OFFSET
#define CSDAC_EN_MASK                   0x0008
#define CSDAC_EN_SHIFT                  3

#define PCHR_AUTOMODE_OFFSET            CON0_OFFSET
#define PCHR_AUTOMODE_MASK              0x0004
#define PCHR_AUTOMODE_SHIFT             2

#define CHR_LDO_DET_OFFSET              CON0_OFFSET
#define CHR_LDO_DET_MASK                0x0002
#define CHR_LDO_DET_SHIFT               1

#define VCDT_HV_EN_OFFSET               CON0_OFFSET
#define VCDT_HV_EN_MASK                 0x0001
#define VCDT_HV_EN_SHIFT                0

#define VBAT_CV_VTH_OFFSET              CON1_OFFSET
#define VBAT_CV_VTH_MASK                0x1F00
#define VBAT_CV_VTH_SHIFT               8

#define VBAT_CC_VTH_OFFSET              CON1_OFFSET
#define VBAT_CC_VTH_MASK                0x0030
#define VBAT_CC_VTH_SHIFT               4

#define VBAT_CC_DET_OFFSET              CON1_OFFSET
#define VBAT_CC_DET_MASK                0x0008
#define VBAT_CC_DET_SHIFT               3

#define VBAT_CV_DET_OFFSET              CON1_OFFSET
#define VBAT_CV_DET_MASK                0x0004
#define VBAT_CV_DET_SHIFT               2

#define VBAT_CC_EN_OFFSET               CON1_OFFSET
#define VBAT_CC_EN_MASK                 0x0002
#define VBAT_CC_EN_SHIFT                1

#define VBAT_CV_EN_OFFSET               CON1_OFFSET
#define VBAT_CV_EN_MASK                 0x0001
#define VBAT_CV_EN_SHIFT                0

#define CS_DET_OFFSET                   CON2_OFFSET
#define CS_DET_MASK                     0x8000
#define CS_DET_SHIFT                    15

#define CS_EN_OFFSET                    CON2_OFFSET
#define CS_EN_MASK                      0x0100
#define CS_EN_SHIFT                     8

#define CS_VTH_OFFSET                   CON2_OFFSET
#define CS_VTH_MASK                     0x000F
#define CS_VTH_SHIFT                    0

#define TOLTC_OFFSET                    CON3_OFFSET
#define TOLTC_MASK                      0x0700
#define TOLTC_SHIFT                     8

#define TOHTC_OFFSET                    CON3_OFFSET
#define TOHTC_MASK                      0x0007
#define TOHTC_SHIFT                     0

#define CSDAC_DLY_OFFSET                CON4_OFFSET
#define CSDAC_DLY_MASK                  0x7000
#define CSDAC_DLY_SHIFT                 12

#define CSDAC_STP_OFFSET                CON4_OFFSET
#define CSDAC_STP_MASK                  0x0700
#define CSDAC_STP_SHIFT                 8

#define CSDAC_STP_DEC_OFFSET            CON4_OFFSET
#define CSDAC_STP_DEC_MASK              0x0070
#define CSDAC_STP_DEC_SHIFT             4

#define CSDAC_STP_INC_OFFSET            CON4_OFFSET
#define CSDAC_STP_INC_MASK              0x0007
#define CSDAC_STP_INC_SHIFT             0

#define BATON_UNDET_OFFSET              CON5_OFFSET
#define BATON_UNDET_MASK                0x0400
#define BATON_UNDET_SHIFT               10

#define BATON_HT_EN_OFFSET              CON5_OFFSET
#define BATON_HT_EN_MASK                0x0200
#define BATON_HT_EN_SHIFT               9

#define BATON_EN_OFFSET                 CON5_OFFSET
#define BATON_EN_MASK                   0x0100
#define BATON_EN_SHIFT                  8

#define VBAT_OV_VTH_OFFSET              CON5_OFFSET
#define VBAT_OV_VTH_MASK                0x0030
#define VBAT_OV_VTH_SHIFT               4

#define VBAT_OV_DET_OFFSET              CON5_OFFSET
#define VBAT_OV_DET_MASK                0x0008
#define VBAT_OV_DET_SHIFT               3

#define VBAT_OV_DEG_OFFSET              CON5_OFFSET
#define VBAT_OV_DEG_MASK                0x0002
#define VBAT_OV_DEG_SHIFT               1

#define VBAT_OV_EN_OFFSET               CON5_OFFSET
#define VBAT_OV_EN_MASK                 0x0001
#define VBAT_OV_EN_SHIFT                0

#define CSDAC_DATA_OFFSET               CON6_OFFSET
#define CSDAC_DATA_MASK                 0x03FF
#define CSDAC_DATA_SHIFT                0

#define PCHR_FT_CTRL_OFFSET             CON7_OFFSET
#define PCHR_FT_CTRL_MASK               0x0700
#define PCHR_FT_CTRL_SHIFT              8

#define PCHR_RST_OFFSET                 CON7_OFFSET
#define PCHR_RST_MASK                   0x0040
#define PCHR_RST_SHIFT                  6

#define CSDAC_TESTMODE_OFFSET           CON7_OFFSET
#define CSDAC_TESTMODE_MASK             0x0020
#define CSDAC_TESTMODE_SHIFT            5

#define PCHR_TESTMODE_OFFSET            CON7_OFFSET
#define PCHR_TESTMODE_MASK              0x0010
#define PCHR_TESTMODE_SHIFT             4

#define OTG_BVALID_OFFSET               CON7_OFFSET
#define OTG_BVALID_MASK                 0x0008
#define OTG_BVALID_SHIFT                3

#define OTG_BVALID_EN_OFFSET            CON7_OFFSET
#define OTG_BVALID_EN_MASK              0x0001
#define OTG_BVALID_EN_SHIFT             0

#define PCHR_FLAG_SEL_OFFSET            CON8_OFFSET
#define PCHR_FLAG_SEL_MASK              0x1F00
#define PCHR_FLAG_SEL_SHIFT             8

#define PCHR_FLAG_EN_OFFSET             CON8_OFFSET
#define PCHR_FLAG_EN_MASK               0x0080
#define PCHR_FLAG_EN_SHIFT              7

#define PCHR_FLAG_OUT_OFFSET            CON8_OFFSET
#define PCHR_FLAG_OUT_MASK              0x000F
#define PCHR_FLAG_OUT_SHIFT             0

#define CHRWDT_OUT_OFFSET               CON9_OFFSET
#define CHRWDT_OUT_MASK                 0x8000
#define CHRWDT_OUT_SHIFT                15

#define CHRWDT_FLAG_OFFSET              CON9_OFFSET
#define CHRWDT_FLAG_MASK                0x0200
#define CHRWDT_FLAG_SHIFT               9

#define CHRWDT_INT_EN_OFFSET            CON9_OFFSET
#define CHRWDT_INT_EN_MASK              0x0100
#define CHRWDT_INT_EN_SHIFT             8

#define CHRWDT_EN_OFFSET                CON9_OFFSET
#define CHRWDT_EN_MASK                  0x0010
#define CHRWDT_EN_SHIFT                 4

#define CHRWDT_TD_OFFSET                CON9_OFFSET
#define CHRWDT_TD_MASK                  0x000F
#define CHRWDT_TD_SHIFT                 0

#define USBDL_SET_OFFSET                CON10_OFFSET
#define USBDL_SET_MASK                  0x8000
#define USBDL_SET_SHIFT                 15

#define USBDL_RST_OFFSET                CON10_OFFSET
#define USBDL_RST_MASK                  0x4000
#define USBDL_RST_SHIFT                 14

#define BGR_UNCHOP_OFFSET               CON10_OFFSET
#define BGR_UNCHOP_MASK                 0x2000
#define BGR_UNCHOP_SHIFT                13

#define BGR_UNCHOP_PH_OFFSET            CON10_OFFSET
#define BGR_UNCHOP_PH_MASK              0x1000
#define BGR_UNCHOP_PH_SHIFT             12

#define BGR_RSEL_OFFSET                 CON10_OFFSET
#define BGR_RSEL_MASK                   0x0700
#define BGR_RSEL_SHIFT                  8

#define ADCIN_CHR_EN_OFFSET             CON10_OFFSET
#define ADCIN_CHR_EN_MASK               0x0040
#define ADCIN_CHR_EN_SHIFT              6

#define ADCIN_VSEN_EN_OFFSET            CON10_OFFSET
#define ADCIN_VSEN_EN_MASK              0x0020
#define ADCIN_VSEN_EN_SHIFT             5

#define ADCIN_VBAT_EN_OFFSET            CON10_OFFSET
#define ADCIN_VBAT_EN_MASK              0x0010
#define ADCIN_VBAT_EN_SHIFT             4

#define UVLO_VTHL_OFFSET                CON10_OFFSET
#define UVLO_VTHL_MASK                  0x0003
#define UVLO_VTHL_SHIFT                 0

#define BC11_CMP_OUT_OFFSET             CON11_OFFSET
#define BC11_CMP_OUT_MASK               0x8000
#define BC11_CMP_OUT_SHIFT              15

#define BC11_RST_OFFSET                 CON11_OFFSET
#define BC11_RST_MASK                   0x0800
#define BC11_RST_SHIFT                  11

#define BC11_BB_CTRL_OFFSET             CON11_OFFSET
#define BC11_BB_CTRL_MASK               0x0400
#define BC11_BB_CTRL_SHIFT              10

#define BC11_BIAS_EN_OFFSET             CON11_OFFSET
#define BC11_BIAS_EN_MASK               0x0200
#define BC11_BIAS_EN_SHIFT              9

#define BC11_VREF_VTH_OFFSET            CON11_OFFSET
#define BC11_VREF_VTH_MASK              0x0100
#define BC11_VREF_VTH_SHIFT             8

#define BC11_IPU_EN_OFFSET              CON11_OFFSET
#define BC11_IPU_EN_MASK                0x00C0
#define BC11_IPU_EN_SHIFT               6

#define BC11_IPD_EN_OFFSET              CON11_OFFSET
#define BC11_IPD_EN_MASK                0x0030
#define BC11_IPD_EN_SHIFT               4

#define BC11_VSRC_EN_OFFSET             CON11_OFFSET
#define BC11_VSRC_EN_MASK               0x000C
#define BC11_VSRC_EN_SHIFT              2

#define BC11_CMP_EN_OFFSET              CON11_OFFSET
#define BC11_CMP_EN_MASK                0x0003
#define BC11_CMP_EN_SHIFT               0

#define LOW_ICH_DB_OFFSET               CON12_OFFSET
#define LOW_ICH_DB_MASK                 0x3F00
#define LOW_ICH_DB_SHIFT                8

#define ULC_DET_EN_OFFSET               CON12_OFFSET
#define ULC_DET_EN_MASK                 0x0080
#define ULC_DET_EN_SHIFT                7

#define HWCV_EN_OFFSET                  CON12_OFFSET
#define HWCV_EN_MASK                    0x0040
#define HWCV_EN_SHIFT                   6

#define TRACKING_EN_OFFSET              CON12_OFFSET
#define TRACKING_EN_MASK                0x0010
#define TRACKING_EN_SHIFT               4

#define CSDAC_MODE_OFFSET               CON12_OFFSET
#define CSDAC_MODE_MASK                 0x0004
#define CSDAC_MODE_SHIFT                2

#define VCDT_MODE_OFFSET                CON12_OFFSET
#define VCDT_MODE_MASK                  0x0002
#define VCDT_MODE_SHIFT                 1

#define CV_MODE_OFFSET                  CON12_OFFSET
#define CV_MODE_MASK                    0x0001
#define CV_MODE_SHIFT                   0

#define DRV_ITUNE_OFFSET                CON13_OFFSET
#define DRV_ITUNE_MASK                  0x0300
#define DRV_ITUNE_SHIFT                 8

#define OVP_TRIM_OFFSET                 CON13_OFFSET
#define OVP_TRIM_MASK                   0x000F
#define OVP_TRIM_SHIFT                  0

#define PCHR_RV_OFFSET                  CON14_OFFSET
#define PCHR_RV_MASK                    0xFFFF
#define PCHR_RV_SHIFT                   0

#define PWRKEY_DEB_OFFSET               CON0_OFFSET
#define PWRKEY_DEB_MASK                 0x8000
#define PWRKEY_DEB_SHIFT                15

#define PWRKEY_VCORE_OFFSET             CON0_OFFSET
#define PWRKEY_VCORE_MASK               0x4000
#define PWRKEY_VCORE_SHIFT              14

#define TEST_MODE_POR_OFFSET            CON0_OFFSET
#define TEST_MODE_POR_MASK              0x2000
#define TEST_MODE_POR_SHIFT             13

#define USBDL_MDOE_OFFSET               CON0_OFFSET
#define USBDL_MDOE_MASK                 0x1000
#define USBDL_MDOE_SHIFT                12

#define PMU_THR_PWROFF_OFFSET           CON0_OFFSET
#define PMU_THR_PWROFF_MASK             0x0800
#define PMU_THR_PWROFF_SHIFT            11

#define PMU_THR_STATUS_OFFSET           CON0_OFFSET
#define PMU_THR_STATUS_MASK             0x0700
#define PMU_THR_STATUS_SHIFT            8

#define USBDL_EN_OFFSET                 CON0_OFFSET
#define USBDL_EN_MASK                   0x0010
#define USBDL_EN_SHIFT                  4

#define THR_HWPDN_EN_OFFSET             CON0_OFFSET
#define THR_HWPDN_EN_MASK               0x0008
#define THR_HWPDN_EN_SHIFT              3

#define THERMAL_DIS_OFFSET              CON0_OFFSET
#define THERMAL_DIS_MASK                0x0004
#define THERMAL_DIS_SHIFT               2

#define THR_SEL_OFFSET                  CON0_OFFSET
#define THR_SEL_MASK                    0x0003
#define THR_SEL_SHIFT                   0

#define BIAS_GEN_FORCE_OFFSET           CON1_OFFSET
#define BIAS_GEN_FORCE_MASK             0x4000
#define BIAS_GEN_FORCE_SHIFT            14

#define PMU_LEV_UNGATE_OFFSET           CON1_OFFSET
#define PMU_LEV_UNGATE_MASK             0x0100
#define PMU_LEV_UNGATE_SHIFT            8

#define RST_DRVSEL_OFFSET               CON1_OFFSET
#define RST_DRVSEL_MASK                 0x0020
#define RST_DRVSEL_SHIFT                5

#define STRUP_TEST_OFFSET               CON1_OFFSET
#define STRUP_TEST_MASK                 0x0010
#define STRUP_TEST_SHIFT                4

#define PMU_PGDET_DIS_OFFSET            CON1_OFFSET
#define PMU_PGDET_DIS_MASK              0x0008
#define PMU_PGDET_DIS_SHIFT             3

#define VREF_BG_OFFSET                  CON1_OFFSET
#define VREF_BG_MASK                    0x0007
#define VREF_BG_SHIFT                   0

#define STRUP_FLAG_OUT_OFFSET           CON2_OFFSET
#define STRUP_FLAG_OUT_MASK             0x0F00
#define STRUP_FLAG_OUT_SHIFT            8

#define STRUP_FLAG_EN_OFFSET            CON2_OFFSET
#define STRUP_FLAG_EN_MASK              0x0080
#define STRUP_FLAG_EN_SHIFT             7

#define STRUP_FLAG_SEL_OFFSET           CON2_OFFSET
#define STRUP_FLAG_SEL_MASK             0x000F
#define STRUP_FLAG_SEL_SHIFT            0

#define ESDDEG_DLYSEL_OFFSET            CON3_OFFSET
#define ESDDEG_DLYSEL_MASK              0x000E
#define ESDDEG_DLYSEL_SHIFT             1

#define ESDDEG_EN_OFFSET                CON3_OFFSET
#define ESDDEG_EN_MASK                  0x0001
#define ESDDEG_EN_SHIFT                 0

#define BOOST_CKS_CHG_OFFSET            CON3_OFFSET
#define BOOST_CKS_CHG_MASK              0x8000
#define BOOST_CKS_CHG_SHIFT             15

#define BOOST_CKS_PRG_OFFSET            CON3_OFFSET
#define BOOST_CKS_PRG_MASK              0x003F
#define BOOST_CKS_PRG_SHIFT             0

#define ISINK0_STATUS_OFFSET            CON0_OFFSET
#define ISINK0_STATUS_MASK              0x8000
#define ISINK0_STATUS_SHIFT             15

#define ISINK0_STEP_OFFSET              CON0_OFFSET
#define ISINK0_STEP_MASK                0x0070
#define ISINK0_STEP_SHIFT               4

#define ISINK0_MODE_OFFSET              CON0_OFFSET
#define ISINK0_MODE_MASK                0x0002
#define ISINK0_MODE_SHIFT               1

#define ISINK0_EN_OFFSET                CON0_OFFSET
#define ISINK0_EN_MASK                  0x0001
#define ISINK0_EN_SHIFT                 0

#define ISINKS_VREF_CAL_OFFSET          CON1_OFFSET
#define ISINKS_VREF_CAL_MASK            0x1F00
#define ISINKS_VREF_CAL_SHIFT           8

#define ISINKS_FORCE_OFF_OFFSET         CON1_OFFSET
#define ISINKS_FORCE_OFF_MASK           0x0001
#define ISINKS_FORCE_OFF_SHIFT          0

#define ISINKS_TEST_SEL_OFFSET          CON2_OFFSET
#define ISINKS_TEST_SEL_MASK            0x0700
#define ISINKS_TEST_SEL_SHIFT           8

#define ISINKS_RSV_OFFSET               CON2_OFFSET
#define ISINKS_RSV_MASK                 0x00FF
#define ISINKS_RSV_SHIFT                0

#define ISINK1_STATUS_OFFSET            CON0_OFFSET
#define ISINK1_STATUS_MASK              0x8000
#define ISINK1_STATUS_SHIFT             15

#define ISINK1_STEP_OFFSET              CON0_OFFSET
#define ISINK1_STEP_MASK                0x0070
#define ISINK1_STEP_SHIFT               4

#define ISINK1_MODE_OFFSET              CON0_OFFSET
#define ISINK1_MODE_MASK                0x0002
#define ISINK1_MODE_SHIFT               1

#define ISINK1_EN_OFFSET                CON0_OFFSET
#define ISINK1_EN_MASK                  0x0001
#define ISINK1_EN_SHIFT                 0

#define ISINK2_STATUS_OFFSET            CON0_OFFSET
#define ISINK2_STATUS_MASK              0x8000
#define ISINK2_STATUS_SHIFT             15

#define ISINK2_STEP_OFFSET              CON0_OFFSET
#define ISINK2_STEP_MASK                0x0070
#define ISINK2_STEP_SHIFT               4

#define ISINK2_MODE_OFFSET              CON0_OFFSET
#define ISINK2_MODE_MASK                0x0002
#define ISINK2_MODE_SHIFT               1

#define ISINK2_EN_OFFSET                CON0_OFFSET
#define ISINK2_EN_MASK                  0x0001
#define ISINK2_EN_SHIFT                 0

#define ISINK3_STATUS_OFFSET            CON0_OFFSET
#define ISINK3_STATUS_MASK              0x8000
#define ISINK3_STATUS_SHIFT             15

#define ISINK3_STEP_OFFSET              CON0_OFFSET
#define ISINK3_STEP_MASK                0x0070
#define ISINK3_STEP_SHIFT               4

#define ISINK3_MODE_OFFSET              CON0_OFFSET
#define ISINK3_MODE_MASK                0x0002
#define ISINK3_MODE_SHIFT               1

#define ISINK3_EN_OFFSET                CON0_OFFSET
#define ISINK3_EN_MASK                  0x0001
#define ISINK3_EN_SHIFT                 0

#define ISINK4_STATUS_OFFSET            CON0_OFFSET
#define ISINK4_STATUS_MASK              0x8000
#define ISINK4_STATUS_SHIFT             15

#define ISINK4_STEP_OFFSET              CON0_OFFSET
#define ISINK4_STEP_MASK                0x0070
#define ISINK4_STEP_SHIFT               4

#define ISINK4_MODE_OFFSET              CON0_OFFSET
#define ISINK4_MODE_MASK                0x0002
#define ISINK4_MODE_SHIFT               1

#define ISINK4_EN_OFFSET                CON0_OFFSET
#define ISINK4_EN_MASK                  0x0001
#define ISINK4_EN_SHIFT                 0

#define ISINK5_STATUS_OFFSET            CON0_OFFSET
#define ISINK5_STATUS_MASK              0x8000
#define ISINK5_STATUS_SHIFT             15

#define ISINK5_STEP_OFFSET              CON0_OFFSET
#define ISINK5_STEP_MASK                0x0070
#define ISINK5_STEP_SHIFT               4

#define ISINK5_MODE_OFFSET              CON0_OFFSET
#define ISINK5_MODE_MASK                0x0002
#define ISINK5_MODE_SHIFT               1

#define ISINK5_EN_OFFSET                CON0_OFFSET
#define ISINK5_EN_MASK                  0x0001
#define ISINK5_EN_SHIFT                 0

#define KPLED_STATUS_OFFSET             CON0_OFFSET
#define KPLED_STATUS_MASK               0x8000
#define KPLED_STATUS_SHIFT              15

#define KPLED_SFSTREN_OFFSET            CON0_OFFSET
#define KPLED_SFSTREN_MASK              0x0400
#define KPLED_SFSTREN_SHIFT             10

#define KPLED_SFSTRTC_OFFSET            CON0_OFFSET
#define KPLED_SFSTRTC_MASK              0x0300
#define KPLED_SFSTRTC_SHIFT             8

#define KPLED_SEL_OFFSET                CON0_OFFSET
#define KPLED_SEL_MASK                  0x0070
#define KPLED_SEL_SHIFT                 4

#define KPLED_MODE_OFFSET               CON0_OFFSET
#define KPLED_MODE_MASK                 0x0002
#define KPLED_MODE_SHIFT                1

#define KPLED_EN_OFFSET                 CON0_OFFSET
#define KPLED_EN_MASK                   0x0001
#define KPLED_EN_SHIFT                  0

#define KPLED_FORCE_OFF_OFFSET          CON1_OFFSET
#define KPLED_FORCE_OFF_MASK            0x0001
#define KPLED_FORCE_OFF_SHIFT           0

#define SPK_OC_FLAG_OFFSET              CON0_OFFSET
#define SPK_OC_FLAG_MASK                0x4000
#define SPK_OC_FLAG_SHIFT               14

#define SPK_OC_AUTOFF_OFFSET            CON0_OFFSET
#define SPK_OC_AUTOFF_MASK              0x1000
#define SPK_OC_AUTOFF_SHIFT             12

#define SPK_VOL_OFFSET                  CON0_OFFSET
#define SPK_VOL_MASK                    0x0030
#define SPK_VOL_SHIFT                   4

#define SPK_EN_OFFSET                   CON0_OFFSET
#define SPK_EN_MASK                     0x0001
#define SPK_EN_SHIFT                    0

#define SPK_EN_VIEW_CLK_OFFSET          CON3_OFFSET
#define SPK_EN_VIEW_CLK_MASK            0x4000
#define SPK_EN_VIEW_CLK_SHIFT           14

#define SPK_OC_CTRL_OFFSET              CON3_OFFSET
#define SPK_OC_CTRL_MASK                0x000C
#define SPK_OC_CTRL_SHIFT               2

#define SPK_BIAS_OFFSET                 CON7_OFFSET
#define SPK_BIAS_MASK                   0x6000
#define SPK_BIAS_SHIFT                  13

#define SPK_2IN1_OFFSET                 CON7_OFFSET
#define SPK_2IN1_MASK                   0x1000
#define SPK_2IN1_SHIFT                  12

#define SPK_PBIAS_OFFSET                CON7_OFFSET
#define SPK_PBIAS_MASK                  0x0400
#define SPK_PBIAS_SHIFT                 10

#define SPKAB_OC_EN_OFFSET              CON7_OFFSET
#define SPKAB_OC_EN_MASK                0x0100
#define SPKAB_OC_EN_SHIFT               8

#define SPKAB_VCM_SEL_OFFSET            CON7_OFFSET
#define SPKAB_VCM_SEL_MASK              0x0080
#define SPKAB_VCM_SEL_SHIFT             7

#define VCM_IBSEL_OFFSET                CON7_OFFSET
#define VCM_IBSEL_MASK                  0x0040
#define VCM_IBSEL_SHIFT                 6

#define SPKAB_OBIAS_OFFSET              CON7_OFFSET
#define SPKAB_OBIAS_MASK                0x0030
#define SPKAB_OBIAS_SHIFT               4

#define SPK_RSV_OFFSET                  CON8_OFFSET
#define SPK_RSV_MASK                    0xF000
#define SPK_RSV_SHIFT                   12

#define SPK_CALIBR_SEL_OFFSET           CON8_OFFSET
#define SPK_CALIBR_SEL_MASK             0x0200
#define SPK_CALIBR_SEL_SHIFT            9

#define SPK_CALIBR_EN_OFFSET            CON8_OFFSET
#define SPK_CALIBR_EN_MASK              0x0040
#define SPK_CALIBR_EN_SHIFT             6

#define VSF_OC_INT_EN_OFFSET            CON0_OFFSET
#define VSF_OC_INT_EN_MASK              0x2000
#define VSF_OC_INT_EN_SHIFT             13

#define VMC_OC_INT_EN_OFFSET            CON0_OFFSET
#define VMC_OC_INT_EN_MASK              0x1000
#define VMC_OC_INT_EN_SHIFT             12

#define VIBR_OC_INT_EN_OFFSET           CON0_OFFSET
#define VIBR_OC_INT_EN_MASK             0x0800
#define VIBR_OC_INT_EN_SHIFT            11

#define VRTC_OC_INT_EN_OFFSET           CON0_OFFSET
#define VRTC_OC_INT_EN_MASK             0x0400
#define VRTC_OC_INT_EN_SHIFT            10

#define VSIM2_OC_INT_EN_OFFSET          CON0_OFFSET
#define VSIM2_OC_INT_EN_MASK            0x0200
#define VSIM2_OC_INT_EN_SHIFT           9

#define VSIM_OC_INT_EN_OFFSET           CON0_OFFSET
#define VSIM_OC_INT_EN_MASK             0x0100
#define VSIM_OC_INT_EN_SHIFT            8

#define VBT_OC_INT_EN_OFFSET            CON0_OFFSET
#define VBT_OC_INT_EN_MASK              0x0080
#define VBT_OC_INT_EN_SHIFT             7

#define VUSB_OC_INT_EN_OFFSET           CON0_OFFSET
#define VUSB_OC_INT_EN_MASK             0x0040
#define VUSB_OC_INT_EN_SHIFT            6

#define VIO28_OC_INT_EN_OFFSET          CON0_OFFSET
#define VIO28_OC_INT_EN_MASK            0x0020
#define VIO28_OC_INT_EN_SHIFT           5

#define VCAMD_OC_INT_EN_OFFSET          CON0_OFFSET
#define VCAMD_OC_INT_EN_MASK            0x0010
#define VCAMD_OC_INT_EN_SHIFT           4

#define VCAMA_OC_INT_EN_OFFSET          CON0_OFFSET
#define VCAMA_OC_INT_EN_MASK            0x0008
#define VCAMA_OC_INT_EN_SHIFT           3

#define VA_OC_INT_EN_OFFSET             CON0_OFFSET
#define VA_OC_INT_EN_MASK               0x0004
#define VA_OC_INT_EN_SHIFT              2

#define VTCXO_OC_INT_EN_OFFSET          CON0_OFFSET
#define VTCXO_OC_INT_EN_MASK            0x0002
#define VTCXO_OC_INT_EN_SHIFT           1

#define VRF_OC_INT_EN_OFFSET            CON0_OFFSET
#define VRF_OC_INT_EN_MASK              0x0001
#define VRF_OC_INT_EN_SHIFT             0

#define VIO18_OC_INT_EN_OFFSET          CON1_OFFSET
#define VIO18_OC_INT_EN_MASK            0x0002
#define VIO18_OC_INT_EN_SHIFT           1

#define VCORE_OC_INT_EN_OFFSET          CON1_OFFSET
#define VCORE_OC_INT_EN_MASK            0x0001
#define VCORE_OC_INT_EN_SHIFT           0

#define SPK_OC_INT_EN_OFFSET            CON3_OFFSET
#define SPK_OC_INT_EN_MASK              0x0001
#define SPK_OC_INT_EN_SHIFT             0
/*
#define VSF_OC_FLAG_OFFSET              CON4_OFFSET
#define VSF_OC_FLAG_MASK                0x2000
#define VSF_OC_FLAG_SHIFT               13

#define VMC_OC_FLAG_OFFSET              CON4_OFFSET
#define VMC_OC_FLAG_MASK                0x1000
#define VMC_OC_FLAG_SHIFT               12

#define VIBR_OC_FLAG_OFFSET             CON4_OFFSET
#define VIBR_OC_FLAG_MASK               0x0800
#define VIBR_OC_FLAG_SHIFT              11

#define VRTC_OC_FLAG_OFFSET             CON4_OFFSET
#define VRTC_OC_FLAG_MASK               0x0400
#define VRTC_OC_FLAG_SHIFT              10

#define VSIM2_OC_FLAG_OFFSET            CON4_OFFSET
#define VSIM2_OC_FLAG_MASK              0x0200
#define VSIM2_OC_FLAG_SHIFT             9

#define VSIM_OC_FLAG_OFFSET             CON4_OFFSET
#define VSIM_OC_FLAG_MASK               0x0100
#define VSIM_OC_FLAG_SHIFT              8

#define VBT_OC_FLAG_OFFSET              CON4_OFFSET
#define VBT_OC_FLAG_MASK                0x0080
#define VBT_OC_FLAG_SHIFT               7

#define VUSB_OC_FLAG_OFFSET             CON4_OFFSET
#define VUSB_OC_FLAG_MASK               0x0040
#define VUSB_OC_FLAG_SHIFT              6

#define VIO28_OC_FLAG_OFFSET            CON4_OFFSET
#define VIO28_OC_FLAG_MASK              0x0020
#define VIO28_OC_FLAG_SHIFT             5

#define VCAMD_OC_FLAG_OFFSET            CON4_OFFSET
#define VCAMD_OC_FLAG_MASK              0x0010
#define VCAMD_OC_FLAG_SHIFT             4

#define VCAMA_OC_FLAG_OFFSET            CON4_OFFSET
#define VCAMA_OC_FLAG_MASK              0x0008
#define VCAMA_OC_FLAG_SHIFT             3

#define VA_OC_FLAG_OFFSET               CON4_OFFSET
#define VA_OC_FLAG_MASK                 0x0004
#define VA_OC_FLAG_SHIFT                2

#define VTCXO_OC_FLAG_OFFSET            CON4_OFFSET
#define VTCXO_OC_FLAG_MASK              0x0002
#define VTCXO_OC_FLAG_SHIFT             1

#define VRF_OC_FLAG_OFFSET              CON4_OFFSET
#define VRF_OC_FLAG_MASK                0x0001
#define VRF_OC_FLAG_SHIFT               0

#define VIO18_OC_FLAG_OFFSET            CON5_OFFSET
#define VIO18_OC_FLAG_MASK              0x0002
#define VIO18_OC_FLAG_SHIFT             1

#define VCORE_OC_FLAG_OFFSET            CON5_OFFSET
#define VCORE_OC_FLAG_MASK              0x0001
#define VCORE_OC_FLAG_SHIFT             0

#define SPK_OC_FLAG_OFFSET              CON7_OFFSET
#define SPK_OC_FLAG_MASK                0x0001
#define SPK_OC_FLAG_SHIFT               0
*/
#define VSF_OC_STATUS_OFFSET            CON8_OFFSET
#define VSF_OC_STATUS_MASK              0x2000
#define VSF_OC_STATUS_SHIFT             13

#define VMC_OC_STATUS_OFFSET            CON8_OFFSET
#define VMC_OC_STATUS_MASK              0x1000
#define VMC_OC_STATUS_SHIFT             12

#define VIBR_OC_STATUS_OFFSET           CON8_OFFSET
#define VIBR_OC_STATUS_MASK             0x0800
#define VIBR_OC_STATUS_SHIFT            11

#define VRTC_OC_STATUS_OFFSET           CON8_OFFSET
#define VRTC_OC_STATUS_MASK             0x0400
#define VRTC_OC_STATUS_SHIFT            10

#define VSIM2_OC_STATUS_OFFSET          CON8_OFFSET
#define VSIM2_OC_STATUS_MASK            0x0200
#define VSIM2_OC_STATUS_SHIFT           9

#define VSIM_OC_STATUS_OFFSET           CON8_OFFSET
#define VSIM_OC_STATUS_MASK             0x0100
#define VSIM_OC_STATUS_SHIFT            8

#define VBT_OC_STATUS_OFFSET            CON8_OFFSET
#define VBT_OC_STATUS_MASK              0x0080
#define VBT_OC_STATUS_SHIFT             7

#define VUSB_OC_STATUS_OFFSET           CON8_OFFSET
#define VUSB_OC_STATUS_MASK             0x0040
#define VUSB_OC_STATUS_SHIFT            6

#define VIO28_OC_STATUS_OFFSET          CON8_OFFSET
#define VIO28_OC_STATUS_MASK            0x0020
#define VIO28_OC_STATUS_SHIFT           5

#define VCAMD_OC_STATUS_OFFSET          CON8_OFFSET
#define VCAMD_OC_STATUS_MASK            0x0010
#define VCAMD_OC_STATUS_SHIFT           4

#define VCAMA_OC_STATUS_OFFSET          CON8_OFFSET
#define VCAMA_OC_STATUS_MASK            0x0008
#define VCAMA_OC_STATUS_SHIFT           3

#define VA_OC_STATUS_OFFSET             CON8_OFFSET
#define VA_OC_STATUS_MASK               0x0004
#define VA_OC_STATUS_SHIFT              2

#define VTCXO_OC_STATUS_OFFSET          CON8_OFFSET
#define VTCXO_OC_STATUS_MASK            0x0002
#define VTCXO_OC_STATUS_SHIFT           1

#define VRF_OC_STATUS_OFFSET            CON8_OFFSET
#define VRF_OC_STATUS_MASK              0x0001
#define VRF_OC_STATUS_SHIFT             0

#define VIO18_OC_STATUS_OFFSET          CON9_OFFSET
#define VIO18_OC_STATUS_MASK            0x0002
#define VIO18_OC_STATUS_SHIFT           1

#define VCORE_OC_STATUS_OFFSET          CON9_OFFSET
#define VCORE_OC_STATUS_MASK            0x0001
#define VCORE_OC_STATUS_SHIFT           0

#define SPK_OC_STATUS_OFFSET            CONB_OFFSET
#define SPK_OC_STATUS_MASK              0x0001
#define SPK_OC_STATUS_SHIFT             0

#define INT_NODE_MUX_OFFSET             CON0_OFFSET
#define INT_NODE_MUX_MASK               0x0007
#define INT_NODE_MUX_SHIFT              0

#define IBIAS_TRIM_OFFSET               CON1_OFFSET
#define IBIAS_TRIM_MASK                 0xF000
#define IBIAS_TRIM_SHIFT                12

#define TPSEL_OFFSET                    CON1_OFFSET
#define TPSEL_MASK                      0x0F00
#define TPSEL_SHIFT                     8

#define TP_BUCK_OFFSET                  CON1_OFFSET
#define TP_BUCK_MASK                    0x0030
#define TP_BUCK_SHIFT                   4

#define TP_LED_OFFSET                   CON1_OFFSET
#define TP_LED_MASK                     0x000F
#define TP_LED_SHIFT                    0

#define TESTMODE_RSV_OFFSET             CON2_OFFSET
#define TESTMODE_RSV_MASK               0xFC00
#define TESTMODE_RSV_SHIFT              10

#define PMU_SV12_TMODE_OFFSET           CON2_OFFSET
#define PMU_SV12_TMODE_MASK             0x0200
#define PMU_SV12_TMODE_SHIFT            9

#define PMU_THR_TMODE_OFFSET            CON2_OFFSET
#define PMU_THR_TMODE_MASK              0x0100
#define PMU_THR_TMODE_SHIFT             8

#define IBIAS_TRIM_EN_OFFSET            CON2_OFFSET
#define IBIAS_TRIM_EN_MASK              0x0020
#define IBIAS_TRIM_EN_SHIFT             5

#define PMU_TMSEL_OFFSET                CON2_OFFSET
#define PMU_TMSEL_MASK                  0x001F
#define PMU_TMSEL_SHIFT                 0

#define PMIC_RSV0_OFFSET                CON0_OFFSET
#define PMIC_RSV0_MASK                  0x00FF
#define PMIC_RSV0_SHIFT                 0

#define PMIC_RSV1_OFFSET                CON1_OFFSET
#define PMIC_RSV1_MASK                  0x00FF
#define PMIC_RSV1_SHIFT                 0

#define PMIC_RSV2_OFFSET                CON2_OFFSET
#define PMIC_RSV2_MASK                  0x00FF
#define PMIC_RSV2_SHIFT                 0

#define PMIC_RSV3_OFFSET                CON3_OFFSET
#define PMIC_RSV3_MASK                  0x00FF
#define PMIC_RSV3_SHIFT                 0


///////////////////////////////////////////////////////////
/* Special Command */

// LDO cmds
// LDO_CON0
#define LDO_BUCK_EN_OFFSET          	CON0_OFFSET
#define LDO_BUCK_EN_MASK               	0x0001
#define LDO_BUCK_EN_SHIFT              	0

#define LDO_BUCK_ON_SEL_OFFSET     		CON0_OFFSET
#define LDO_BUCK_ON_SEL_MASK            0x0002
#define LDO_BUCK_ON_SEL_SHIFT           1

#define LDO_BUCK_RS_OFFSET				CON0_OFFSET
#define LDO_BUCK_RS_MASK               	0x0004
#define LDO_BUCK_RS_SHIFT              	2

#define LDO_BUCK_VOL_SEL_OFFSET			CON0_OFFSET // For VCAMA, VCAMD, VBT, VSIM, VSIM2, VIBR, VMC, VCORE
#define LDO_BUCK_VOL_SEL_MASK          	0x01F0
#define LDO_BUCK_VOL_SEL_SHIFT         	4

#define LDO_BUCK_NDIS_EN_OFFSET			CON0_OFFSET // BUCK: ANTIUNSH_DN
#define LDO_BUCK_NDIS_EN_MASK          	0x0400
#define LDO_BUCK_NDIS_EN_SHIFT         	10

#define LDO_BUCK_STB_EN_OFFSET			CON0_OFFSET
#define LDO_BUCK_STB_EN_MASK           	0x0800
#define LDO_BUCK_STB_EN_SHIFT          	11

#define LDO_BUCK_OC_AUTO_OFF_OFFSET 	CON0_OFFSET
#define LDO_BUCK_OC_AUTO_OFF_MASK      	0x1000
#define LDO_BUCK_OC_AUTO_OFF_SHIFT     	12

#define LDO_BUCK_OCFB_EN_OFFSET			CON0_OFFSET
#define LDO_BUCK_OCFB_EN_MASK          	0x2000
#define LDO_BUCK_OCFB_EN_SHIFT         	13

#define LDO_BUCK_OC_FLAG_OFFSET			CON0_OFFSET
#define LDO_BUCK_OC_FLAG_MASK          	0x4000
#define LDO_BUCK_OC_FLAG_SHIFT         	14

#define LDO_BUCK_STATUS_OFFSET			CON0_OFFSET
#define LDO_BUCK_STATUS_MASK          	0x8000
#define LDO_BUCK_STATUS_SHIFT         	15

// LDO_CON1
#define LDO_CAL_OFFSET					CON1_OFFSET
#define LDO_CAL_MASK              		0x01F0
#define LDO_CAL_SHIFT             		4

#define LDO_STB_SEL_OFFSET				CON1_OFFSET // For VIBR & VMC
#define LDO_STB_SEL_MASK              	0x1000
#define LDO_STB_SEL_SHIFT             	12

// LDO_CON2
#define LDO_EN_FORCE_OFFSET				CON2_OFFSET
#define LDO_EN_FORCE_MASK              	0x0001
#define LDO_EN_FORCE_SHIFT             	0

#define LDO_OC_TD_OFFSET		        CON2_OFFSET
#define LDO_OC_TD_MASK                  0x0030
#define LDO_OC_TD_SHIFT                 4

#define LDO_STB_TD_OFFSET		        CON2_OFFSET
#define LDO_STB_TD_MASK                 0x00C0
#define LDO_STB_TD_SHIFT                6

// BUCK cmds
#define BUCK_VFBADJ_SLEEP_OFFSET	    CON1_OFFSET
#define BUCK_VFBADJ_SLEEP_MASK          0x01F0
#define BUCK_VFBADJ_SLEEP_SHIFT         4

#define BUCK_EN_FORCE_OFFSET		    CON3_OFFSET
#define BUCK_EN_FORCE_MASK              0x0001
#define BUCK_EN_FORCE_SHIFT             0

#define BUCK_OC_TD_OFFSET		        CON3_OFFSET
#define BUCK_OC_TD_MASK                 0x0030
#define BUCK_OC_TD_SHIFT                4

#define BUCK_STB_TD_OFFSET		        CON3_OFFSET
#define BUCK_STB_TD_MASK                0x00C0
#define BUCK_STB_TD_SHIFT               6

#define BUCK_OC_THD_OFFSET	            CON3_OFFSET
#define BUCK_OC_THD_MASK                0x0300
#define BUCK_OC_THD_SHIFT               8

#define BUCK_OC_WND_OFFSET	            CON3_OFFSET
#define BUCK_OC_WND_MASK                0x0C00
#define BUCK_OC_WND_SHIFT               10

#define BUCK_ICAL_EN_OFFSET	            CON3_OFFSET
#define BUCK_ICAL_EN_MASK               0x3000
#define BUCK_ICAL_EN_SHIFT              12

#define BUCK_CSL_OFFSET         	    CON5_OFFSET
#define BUCK_CSL_MASK                   0x0700
#define BUCK_CSL_SHIFT                  8

#define BUCK_BURST_OFFSET		        CON5_OFFSET
#define BUCK_BURST_MASK                 0x3000
#define BUCK_BURST_SHIFT                12

// CHR CMDS
#define ADC_EN_OFFSET		            CON10_OFFSET
#define ADC_EN_MASK                     0x0070   // All ADC channels are enabled at same time
#define ADC_EN_SHIFT                    4

// ISINK cmds
// ISINK_CON0
#define ISINK_EN_OFFSET					CON0_OFFSET
#define ISINK_EN_MASK             		0x0001
#define ISINK_EN_SHIFT            		0

#define ISINK_MODE_OFFSET				CON0_OFFSET
#define ISINK_MODE_MASK           		0x0002
#define ISINK_MODE_SHIFT          		1

#define ISINK_STEP_OFFSET				CON0_OFFSET
#define ISINK_STEP_MASK           		0x0070
#define ISINK_STEP_SHIFT          		4

#define ISINK_STATUS_OFFSET				CON0_OFFSET
#define ISINK_STATUS_MASK           	0x8000
#define ISINK_STATUS_SHIFT          	15

// ISINK_CON1 
#define ISINK_FORCE_OFF_OFFSET			CON1_OFFSET
#define ISINK_FORCE_OFF_MASK       		0x0001
#define ISINK_FORCE_OFF_SHIFT      		0
                                    
#define ISINK_VREF_CAL_OFFSET			CON1_OFFSET
#define ISINK_VREF_CAL_MASK       		0x1F00
#define ISINK_VREF_CAL_SHIFT      		8 

#endif // #if defined(PMIC_6255_REG_API)

#endif // #ifndef __PMU6255_HW_H__
