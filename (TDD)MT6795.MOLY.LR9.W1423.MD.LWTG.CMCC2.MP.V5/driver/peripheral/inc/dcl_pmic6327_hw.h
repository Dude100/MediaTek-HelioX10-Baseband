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

#if defined(PMIC_6327_REG_API)
#define PMIC_BANK0                                          0

#define PMIC6327_E1_VERSION                                0x01

#define PMIC6327_E1_CID_CODE                               0x27

//RegisterTOP

// (0x000) CID0
// (RO)
#define    CID0_ADDR                                       0x00
#define    CID0_MASK                                       0xFF
#define    CID0_SHIFT                                      0

// (0x001) I2C0
// (RW)
#define    SDA_DE_ADDR                                     0x01
#define    SDA_DE_MASK                                     0xF0
#define    SDA_DE_SHIFT                                    4

// (RW)
#define    SCL_DE_ADDR                                     0x01
#define    SCL_DE_MASK                                     0x0F
#define    SCL_DE_SHIFT                                    0

// (0x002) STATUS0
// (RO)
#define    VMD_STATUS_ADDR                                 0x02
#define    VMD_STATUS_MASK                                 0x80
#define    VMD_STATUS_SHIFT                                7

// (RO)
#define    VIO18_STATUS_ADDR                               0x02
#define    VIO18_STATUS_MASK                               0x20
#define    VIO18_STATUS_SHIFT                              5

// (RO)
#define    VRF18_STATUS_ADDR                               0x02
#define    VRF18_STATUS_MASK                               0x10
#define    VRF18_STATUS_SHIFT                              4

// (RO)
#define    VTCXO_STATUS_ADDR                               0x02
#define    VTCXO_STATUS_MASK                               0x02
#define    VTCXO_STATUS_SHIFT                              1

// (RO)
#define    VA25_STATUS_ADDR                                0x02
#define    VA25_STATUS_MASK                                0x01
#define    VA25_STATUS_SHIFT                               0

// (0x003) STATUS1
// (RO)
#define    VM_STATUS_ADDR                                  0x03
#define    VM_STATUS_MASK                                  0x40
#define    VM_STATUS_SHIFT                                 6

// (RO)
#define    VSIM_STATUS_ADDR                                0x03
#define    VSIM_STATUS_MASK                                0x08
#define    VSIM_STATUS_SHIFT                               3

// (0x004) STATUS2
// (RO)
#define    VMC_STATUS_ADDR                                 0x04
#define    VMC_STATUS_MASK                                 0x20
#define    VMC_STATUS_SHIFT                                5

// (0x005) PGSTATUS0
// (RO)
#define    VMD_PG_STATUS_ADDR                              0x05
#define    VMD_PG_STATUS_MASK                              0x80
#define    VMD_PG_STATUS_SHIFT                             7

// (RO)
#define    VTCXO_PG_STATUS_ADDR                            0x05
#define    VTCXO_PG_STATUS_MASK                            0x01
#define    VTCXO_PG_STATUS_SHIFT                           0

// (0x006) PGSTATUS1
// (RO)
#define    VIO18_PG_STATUS_ADDR                            0x06
#define    VIO18_PG_STATUS_MASK                            0x20
#define    VIO18_PG_STATUS_SHIFT                           5

// (RO)
#define    VA25_PG_STATUS_ADDR                             0x06
#define    VA25_PG_STATUS_MASK                             0x08
#define    VA25_PG_STATUS_SHIFT                            3

// (0x007) OCSTATUS0
// (RO)
#define    QI_VM_OC_STATUS_ADDR                            0x07
#define    QI_VM_OC_STATUS_MASK                            0x40
#define    QI_VM_OC_STATUS_SHIFT                           6

// (RO)
#define    QI_VMC_OC_STATUS_ADDR                           0x07
#define    QI_VMC_OC_STATUS_MASK                           0x20
#define    QI_VMC_OC_STATUS_SHIFT                          5

// (RO)
#define    QI_VSIM_OC_STATUS_ADDR                          0x07
#define    QI_VSIM_OC_STATUS_MASK                          0x08
#define    QI_VSIM_OC_STATUS_SHIFT                         3

// (0x008) OCSTATUS1
// (RO)
#define    QI_VMD_OC_STATUS_ADDR                           0x08
#define    QI_VMD_OC_STATUS_MASK                           0x80
#define    QI_VMD_OC_STATUS_SHIFT                          7

// (RO)
#define    QI_VIO18_OC_STATUS_ADDR                         0x08
#define    QI_VIO18_OC_STATUS_MASK                         0x20
#define    QI_VIO18_OC_STATUS_SHIFT                        5

// (RO)
#define    QI_VRF18_OC_STATUS_ADDR                         0x08
#define    QI_VRF18_OC_STATUS_MASK                         0x10
#define    QI_VRF18_OC_STATUS_SHIFT                        4

// (RO)
#define    QI_VTCXO_OC_STATUS_ADDR                         0x08
#define    QI_VTCXO_OC_STATUS_MASK                         0x02
#define    QI_VTCXO_OC_STATUS_SHIFT                        1

// (RO)
#define    QI_VA25_OC_STATUS_ADDR                          0x08
#define    QI_VA25_OC_STATUS_MASK                          0x01
#define    QI_VA25_OC_STATUS_SHIFT                         0

// (0x009) BGR0
// (RW)
#define    RG_BGR_RSEL_ADDR                                0x09
#define    RG_BGR_RSEL_MASK                                0x70
#define    RG_BGR_RSEL_SHIFT                               4

// (RW)
#define    rg_sw_bgr_trim_ADDR                             0x09
#define    rg_sw_bgr_trim_MASK                             0x04
#define    rg_sw_bgr_trim_SHIFT                            2

// (RW)
#define    RG_BGR_UNCHOP_PH_ADDR                           0x09
#define    RG_BGR_UNCHOP_PH_MASK                           0x02
#define    RG_BGR_UNCHOP_PH_SHIFT                          1

// (RW)
#define    RG_BGR_UNCHOP_ADDR                              0x09
#define    RG_BGR_UNCHOP_MASK                              0x01
#define    RG_BGR_UNCHOP_SHIFT                             0

// (0x00A) BGR1
// (RW)
#define    RG_BGR_TEST_EN_ADDR                             0x0A
#define    RG_BGR_TEST_EN_MASK                             0x80
#define    RG_BGR_TEST_EN_SHIFT                            7

// (RW)
#define    RG_BGR_TEST_RSTB_ADDR                           0x0A
#define    RG_BGR_TEST_RSTB_MASK                           0x40
#define    RG_BGR_TEST_RSTB_SHIFT                          6

// (RW)
#define    RG_BGR_TRIM_EN_ADDR                             0x0A
#define    RG_BGR_TRIM_EN_MASK                             0x20
#define    RG_BGR_TRIM_EN_SHIFT                            5

// (RW)
#define    RG_BGR_TRIM_ADDR                                0x0A
#define    RG_BGR_TRIM_MASK                                0x1F
#define    RG_BGR_TRIM_SHIFT                               0

// (0x00B) I2C_RST0
// (RW)
#define    I2C_RST0_ADDR                                   0x0B
#define    I2C_RST0_MASK                                   0xFF
#define    I2C_RST0_SHIFT                                  0

// (0x00C) MODES
// (RW)
#define    SDA_DRV_SEL_ADDR                                0x0C
#define    SDA_DRV_SEL_MASK                                0x04
#define    SDA_DRV_SEL_SHIFT                               2

// (RW)
#define    RG_BGR_TRIM_MODE_ADDR                           0x0C
#define    RG_BGR_TRIM_MODE_MASK                           0x02
#define    RG_BGR_TRIM_MODE_SHIFT                          1

// (RW)
#define    RG_BUCK_TRIM_MODE_ADDR                          0x0C
#define    RG_BUCK_TRIM_MODE_MASK                          0x01
#define    RG_BUCK_TRIM_MODE_SHIFT                         0

// (0x00D) SCAN_MODE
// (RW)
#define    RG_SCAN_KEY_ADDR                                0x0D
#define    RG_SCAN_KEY_MASK                                0xFF
#define    RG_SCAN_KEY_SHIFT                               0

// (0x00E) I2C_TIMEOUT
// (RW)
#define    I2C_TIMEOUT_ADDR                                0x0E
#define    I2C_TIMEOUT_MASK                                0xF0
#define    I2C_TIMEOUT_SHIFT                               4

// (0x00F) PAD_GPO
// (RW)
#define    PAD_SRCLKEN_GPO_ADDR                            0x0F
#define    PAD_SRCLKEN_GPO_MASK                            0xF0
#define    PAD_SRCLKEN_GPO_SHIFT                           4

// (RW)
#define    PAD_SYSRSTB_GPO_ADDR                            0x0F
#define    PAD_SYSRSTB_GPO_MASK                            0x0E
#define    PAD_SYSRSTB_GPO_SHIFT                           1

//Register STRUP

// (0x020) STRUP_CTRL1
// (RW)
#define    RG_THRDET_SEL_ADDR                              0x20
#define    RG_THRDET_SEL_MASK                              0x40
#define    RG_THRDET_SEL_SHIFT                             6

// (RW)
#define    RG_THR_HWPDN_EN_ADDR                            0x20
#define    RG_THR_HWPDN_EN_MASK                            0x20
#define    RG_THR_HWPDN_EN_SHIFT                           5

// (RW)
#define    RG_STRUP_THR_SEL_ADDR                           0x20
#define    RG_STRUP_THR_SEL_MASK                           0x18
#define    RG_STRUP_THR_SEL_SHIFT                          3

// (RW)
#define    RG_THR_TMODE_ADDR                               0x20
#define    RG_THR_TMODE_MASK                               0x02
#define    RG_THR_TMODE_SHIFT                              1

// (RW)
#define    RG_PMU_PGDET_DIS_ADDR                           0x20
#define    RG_PMU_PGDET_DIS_MASK                           0x01
#define    RG_PMU_PGDET_DIS_SHIFT                          0

// (0x021) STRUP_CTRL2
// (RW)
#define    RG_VREF_BG_ADDR                                 0x21
#define    RG_VREF_BG_MASK                                 0x70
#define    RG_VREF_BG_SHIFT                                4

// (RW)
#define    RG_STRUP_IREF_TRIM_ADDR                         0x21
#define    RG_STRUP_IREF_TRIM_MASK                         0x0F
#define    RG_STRUP_IREF_TRIM_SHIFT                        0

// (0x022) STRUP_CTRL3
// (RW)
#define    RG_RST_DRVSEL_ADDR                              0x22
#define    RG_RST_DRVSEL_MASK                              0x40
#define    RG_RST_DRVSEL_SHIFT                             6

// (RW)
#define    RG_UVLO_VTHL_ADDR                               0x22
#define    RG_UVLO_VTHL_MASK                               0x03
#define    RG_UVLO_VTHL_SHIFT                              0

// (0x023) STRUP_RSV1
// (RW)
#define    RG_PMU_RSV_ADDR                                 0x23
#define    RG_PMU_RSV_MASK                                 0xF0
#define    RG_PMU_RSV_SHIFT                                4

// (0x024) STRUP_TST_CTL
// (RW)
#define    RG_BIAS_GEN_EN_FORCE_ADDR                       0x24
#define    RG_BIAS_GEN_EN_FORCE_MASK                       0x20
#define    RG_BIAS_GEN_EN_FORCE_SHIFT                      5

// (RW)
#define    RG_STRUP_PWRON_FORCE_ADDR                       0x24
#define    RG_STRUP_PWRON_FORCE_MASK                       0x10
#define    RG_STRUP_PWRON_FORCE_SHIFT                      4

// (RW)
#define    RG_STRUP_FT_CTRL_ADDR                           0x24
#define    RG_STRUP_FT_CTRL_MASK                           0x03
#define    RG_STRUP_FT_CTRL_SHIFT                          0

// (0x025) STRUP_THR_CTL
// (RO)
#define    PMU_THR_STATUS_ADDR                             0x25
#define    PMU_THR_STATUS_MASK                             0x70
#define    PMU_THR_STATUS_SHIFT                            4

// (RW)
#define    RG_THERMAL_TEST_ADDR                            0x25
#define    RG_THERMAL_TEST_MASK                            0x0C
#define    RG_THERMAL_TEST_SHIFT                           2

// (RW)
#define    RG_ESDDEG_EN_ADDR                               0x25
#define    RG_ESDDEG_EN_MASK                               0x01
#define    RG_ESDDEG_EN_SHIFT                              0

//RegisterVCORE

// (0x050) VMD_CON0
// (RW)
#define    RG_VMD_CSL_ADDR                                 0x50
#define    RG_VMD_CSL_MASK                                 0x30
#define    RG_VMD_CSL_SHIFT                                4

// (RW)
#define    RG_VMD_CC_ADDR                                  0x50
#define    RG_VMD_CC_MASK                                  0x0C
#define    RG_VMD_CC_SHIFT                                 2

// (RW)
#define    RG_VMD_RZSEL_ADDR                               0x50
#define    RG_VMD_RZSEL_MASK                               0x03
#define    RG_VMD_RZSEL_SHIFT                              0

// (0x051) VMD_CON1
// (RW)
#define    RG_VMD_SLP_ADDR                                 0x51
#define    RG_VMD_SLP_MASK                                 0xC0
#define    RG_VMD_SLP_SHIFT                                6

// (RW)
#define    RG_VMD_ZX_OS_ADDR                               0x51
#define    RG_VMD_ZX_OS_MASK                               0x30
#define    RG_VMD_ZX_OS_SHIFT                              4

// (RW)
#define    RG_VMD_SLEW_ADDR                                0x51
#define    RG_VMD_SLEW_MASK                                0x0C
#define    RG_VMD_SLEW_SHIFT                               2

// (RW)
#define    RG_VMD_SLEW_NMOS_ADDR                           0x51
#define    RG_VMD_SLEW_NMOS_MASK                           0x03
#define    RG_VMD_SLEW_NMOS_SHIFT                          0

// (0x052) VMD_CON2
// (RW)
#define    RG_VMD_MODESET_ADDR                             0x52
#define    RG_VMD_MODESET_MASK                             0x01
#define    RG_VMD_MODESET_SHIFT                            0

// (0x053) VMD_CON3
// (RO)
#define    QI_VMD_EN_ADDR                                  0x53
#define    QI_VMD_EN_MASK                                  0x80
#define    QI_VMD_EN_SHIFT                                 7

// (RW)
#define    RG_VMD_EN_ADDR                                  0x53
#define    RG_VMD_EN_MASK                                  0x01
#define    RG_VMD_EN_SHIFT                                 0

// (0x054) VMD_CON4
// (RW)
#define    RG_VMD_VFBADJ_ADDR                              0x54
#define    RG_VMD_VFBADJ_MASK                              0x0E
#define    RG_VMD_VFBADJ_SHIFT                             1

// (RW)
#define    RG_VMD_NDIS_EN_ADDR                             0x54
#define    RG_VMD_NDIS_EN_MASK                             0x01
#define    RG_VMD_NDIS_EN_SHIFT                            0

// (0x055) VMD_CON5
// (RW)
#define    RG_VMD_VOSEL_ADDR                               0x55
#define    RG_VMD_VOSEL_MASK                               0x1F
#define    RG_VMD_VOSEL_SHIFT                              0

// (0x056) VMD_CON6
// (RW)
#define    RG_VMD_VOSEL_CON1_ADDR                          0x56
#define    RG_VMD_VOSEL_CON1_MASK                          0x1F
#define    RG_VMD_VOSEL_CON1_SHIFT                         0

// (0x057) VMD_CON7
// (RW)
#define    RG_VMD_VOSEL_SFCHG_EN_ADDR                      0x57
#define    RG_VMD_VOSEL_SFCHG_EN_MASK                      0x04
#define    RG_VMD_VOSEL_SFCHG_EN_SHIFT                     2

// (RW)
#define    RG_VMD_CTRL_ADDR                                0x57
#define    RG_VMD_CTRL_MASK                                0x01
#define    RG_VMD_CTRL_SHIFT                               0

// (0x058) VMD_CON8
// (RO)
#define    QI_VMD_VOSEL_ADDR                               0x58
#define    QI_VMD_VOSEL_MASK                               0x1F
#define    QI_VMD_VOSEL_SHIFT                              0

// (0x05A) VMD_CON10
// (RW)
#define    RG_TIMESTEP_ADDR                                0x5A
#define    RG_TIMESTEP_MASK                                0x01
#define    RG_TIMESTEP_SHIFT                               0

// (RW)
#define    RG_VOLTSTEP_ADDR                                0x5A
#define    RG_VOLTSTEP_MASK                                0x02
#define    RG_VOLTSTEP_SHIFT                               1

// (0x05B) VMD_CON11
// (RW)
#define    RG_VMD_VH_ADDR                                  0x5B
#define    RG_VMD_VH_MASK                                  0x70
#define    RG_VMD_VH_SHIFT                                 4

// (RW)
#define    RG_VMD_VL_ADDR                                  0x5B
#define    RG_VMD_VL_MASK                                  0x0E
#define    RG_VMD_VL_SHIFT                                 1

// (RW)
#define    RG_VMD_GM_ADDR                                  0x5B
#define    RG_VMD_GM_MASK                                  0x01
#define    RG_VMD_GM_SHIFT                                 0

// (0x05C) VMD_CON12
// (RW)
#define    RG_VMD_CSR_ADDR                                 0x5C
#define    RG_VMD_CSR_MASK                                 0x07
#define    RG_VMD_CSR_SHIFT                                0

// (0x05D) VMD_CON13
// (RW)
#define    VMD_OC_WND_ADDR                                 0x5D
#define    VMD_OC_WND_MASK                                 0x0C
#define    VMD_OC_WND_SHIFT                                2

// (RW)
#define    VMD_OC_THD_ADDR                                 0x5D
#define    VMD_OC_THD_MASK                                 0x03
#define    VMD_OC_THD_SHIFT                                0

//RegisterVRF18

// (0x060) VRF18_CON0
// (RW)
#define    RG_VRF18_CSL_ADDR                               0x60
#define    RG_VRF18_CSL_MASK                               0x30
#define    RG_VRF18_CSL_SHIFT                              4

// (RW)
#define    RG_VRF18_CC_ADDR                                0x60
#define    RG_VRF18_CC_MASK                                0x0C
#define    RG_VRF18_CC_SHIFT                               2

// (RW)
#define    RG_VRF18_RZSEL_ADDR                             0x60
#define    RG_VRF18_RZSEL_MASK                             0x03
#define    RG_VRF18_RZSEL_SHIFT                            0

// (0x061) VRF18_CON1
// (RW)
#define    RG_VRF18_SLP_ADDR                               0x61
#define    RG_VRF18_SLP_MASK                               0xC0
#define    RG_VRF18_SLP_SHIFT                              6

// (RW)
#define    RG_VRF18_ZX_OS_ADDR                             0x61
#define    RG_VRF18_ZX_OS_MASK                             0x30
#define    RG_VRF18_ZX_OS_SHIFT                            4

// (RW)
#define    RG_VRF18_SLEW_ADDR                              0x61
#define    RG_VRF18_SLEW_MASK                              0x0C
#define    RG_VRF18_SLEW_SHIFT                             2

// (RW)
#define    RG_VRF18_SLEW_NMOS_ADDR                         0x61
#define    RG_VRF18_SLEW_NMOS_MASK                         0x03
#define    RG_VRF18_SLEW_NMOS_SHIFT                        0

// (0x062) VRF18_CON2
// (RW)
#define    RG_VRF18_AVP_EN_ADDR                            0x62
#define    RG_VRF18_AVP_EN_MASK                            0x02
#define    RG_VRF18_AVP_EN_SHIFT                           1

// (RW)
#define    RG_VRF18_MODESET_ADDR                           0x62
#define    RG_VRF18_MODESET_MASK                           0x01
#define    RG_VRF18_MODESET_SHIFT                          0

// (0x063) VRF18_CON3
// (RO)
#define    QI_VRF18_EN_ADDR                                0x63
#define    QI_VRF18_EN_MASK                                0x80
#define    QI_VRF18_EN_SHIFT                               7

// (RW)
#define    RG_VRF18_ON_CTRL_ADDR                           0x63
#define    RG_VRF18_ON_CTRL_MASK                           0x02
#define    RG_VRF18_ON_CTRL_SHIFT                          1

// (RW)
#define    RG_VRF18_EN_ADDR                                0x63
#define    RG_VRF18_EN_MASK                                0x01
#define    RG_VRF18_EN_SHIFT                               0

// (0x064) VRF18_CON4
// (RW)
#define    RG_VRF18_STBTD_ADDR                             0x64
#define    RG_VRF18_STBTD_MASK                             0xC0
#define    RG_VRF18_STBTD_SHIFT                            6

// (RW)
#define    RG_VRF18_BURST_ADDR                             0x64
#define    RG_VRF18_BURST_MASK                             0x30
#define    RG_VRF18_BURST_SHIFT                            4

// (RW)
#define    RG_VRF18_OCFB_EN_ADDR                           0x64
#define    RG_VRF18_OCFB_EN_MASK                           0x02
#define    RG_VRF18_OCFB_EN_SHIFT                          1

// (RW)
#define    RG_VRF18_NDIS_EN_ADDR                           0x64
#define    RG_VRF18_NDIS_EN_MASK                           0x01
#define    RG_VRF18_NDIS_EN_SHIFT                          0

// (0x065) VRF18_CON5
// (RW)
#define    RG_VRF18_VOSEL_ADDR                             0x65
#define    RG_VRF18_VOSEL_MASK                             0x1F
#define    RG_VRF18_VOSEL_SHIFT                            0

// (0x066) VRF18_CON6
// (RW)
#define    RG_VRF18_RSV_ADDR                               0x66
#define    RG_VRF18_RSV_MASK                               0x0F
#define    RG_VRF18_RSV_SHIFT                              0

// (0x069) VRF18_CON9
// (RW)
#define    RG_VRF18_VH_ADDR                                0x69
#define    RG_VRF18_VH_MASK                                0x70
#define    RG_VRF18_VH_SHIFT                               4

// (RW)
#define    RG_VRF18_VL_ADDR                                0x69
#define    RG_VRF18_VL_MASK                                0x0E
#define    RG_VRF18_VL_SHIFT                               1

// (RW)
#define    RG_VRF18_GMSEL_ADDR                             0x69
#define    RG_VRF18_GMSEL_MASK                             0x01
#define    RG_VRF18_GMSEL_SHIFT                            0

// (0x06A) VRF18_CON10
// (RW)
#define    RG_VRF18_CSR_ADDR                               0x6A
#define    RG_VRF18_CSR_MASK                               0x07
#define    RG_VRF18_CSR_SHIFT                              0

// (0x06B) VRF18_CON11
// (RW)
#define    RG_VRF18_OC_WND_ADDR                            0x6B
#define    RG_VRF18_OC_WND_MASK                            0x0C
#define    RG_VRF18_OC_WND_SHIFT                           2

// (RW)
#define    RG_VRF18_OC_THD_ADDR                            0x6B
#define    RG_VRF18_OC_THD_MASK                            0x03
#define    RG_VRF18_OC_THD_SHIFT                           0

//RegisterDigLDO

// (0x080) DIGLDO_CON0
// (RW)
#define    RG_VIO18_CAL_ADDR                               0x80
#define    RG_VIO18_CAL_MASK                               0x0F
#define    RG_VIO18_CAL_SHIFT                              0

// (0x082) DIGLDO_CON1
// (RW)
#define    RG_VIO18_STBTD_ADDR                             0x82
#define    RG_VIO18_STBTD_MASK                             0x30
#define    RG_VIO18_STBTD_SHIFT                            4

// (RW)
#define    RG_VIO18_OCFB_EN_ADDR                           0x82
#define    RG_VIO18_OCFB_EN_MASK                           0x04
#define    RG_VIO18_OCFB_EN_SHIFT                          2

// (RW)
#define    RG_VIO18_NDIS_EN_ADDR                           0x82
#define    RG_VIO18_NDIS_EN_MASK                           0x02
#define    RG_VIO18_NDIS_EN_SHIFT                          1

// (RW)
#define    RG_VIO18_EN_ADDR                                0x82
#define    RG_VIO18_EN_MASK                                0x01
#define    RG_VIO18_EN_SHIFT                               0

// (0x083) DIGLDO_CON2
// (RW)
#define    RG_VSIM_CAL_ADDR                                0x83
#define    RG_VSIM_CAL_MASK                                0x0F
#define    RG_VSIM_CAL_SHIFT                               0

// (0x084) DIGLDO_CON3
// (RW)
#define    RG_VSIM_VOSEL_ADDR                              0x84
#define    RG_VSIM_VOSEL_MASK                              0x10
#define    RG_VSIM_VOSEL_SHIFT                             4

// (RW)
#define    RG_VSIM_EN_ADDR                                 0x84
#define    RG_VSIM_EN_MASK                                 0x01
#define    RG_VSIM_EN_SHIFT                                0

// (0x085) DIGLDO_CON4
// (RW)
#define    RG_VSIM_STBTD_ADDR                              0x85
#define    RG_VSIM_STBTD_MASK                              0x30
#define    RG_VSIM_STBTD_SHIFT                             4

// (RW)
#define    RG_VSIM_OCFB_EN_ADDR                            0x85
#define    RG_VSIM_OCFB_EN_MASK                            0x02
#define    RG_VSIM_OCFB_EN_SHIFT                           1

// (RW)
#define    RG_VSIM_NDIS_EN_ADDR                            0x85
#define    RG_VSIM_NDIS_EN_MASK                            0x01
#define    RG_VSIM_NDIS_EN_SHIFT                           0

// (0x086) DIGLDO_CON5
// (RW)
#define    RG_VMC_CAL_ADDR                                 0x86
#define    RG_VMC_CAL_MASK                                 0x0F
#define    RG_VMC_CAL_SHIFT                                0

// (0x087) DIGLDO_CON6
// (RW)
#define    RG_VMC_VOSEL_ADDR                               0x87
#define    RG_VMC_VOSEL_MASK                               0x70
#define    RG_VMC_VOSEL_SHIFT                              4

// (0x088) DIGLDO_CON7
// (RW)
#define    RG_VMC_STBTD_ADDR                               0x88
#define    RG_VMC_STBTD_MASK                               0x30
#define    RG_VMC_STBTD_SHIFT                              4

// (RW)
#define    RG_VMC_STB_SEL_ADDR                             0x88
#define    RG_VMC_STB_SEL_MASK                             0x08
#define    RG_VMC_STB_SEL_SHIFT                            3

// (RW)
#define    RG_VMC_OCFB_EN_ADDR                             0x88
#define    RG_VMC_OCFB_EN_MASK                             0x04
#define    RG_VMC_OCFB_EN_SHIFT                            2

// (RW)
#define    RG_VMC_NDIS_EN_ADDR                             0x88
#define    RG_VMC_NDIS_EN_MASK                             0x02
#define    RG_VMC_NDIS_EN_SHIFT                            1

// (RW)
#define    RG_VMC_EN_ADDR                                  0x88
#define    RG_VMC_EN_MASK                                  0x01
#define    RG_VMC_EN_SHIFT                                 0

// (0x089) DIGLDO_CON8
// (RW)
#define    RG_VM_CAL_ADDR                                  0x89
#define    RG_VM_CAL_MASK                                  0x0F
#define    RG_VM_CAL_SHIFT                                 0

// (0x08A) DIGLDO_CON9
// (RW)
#define    RG_VM_VOSEL_ADDR                                0x8A
#define    RG_VM_VOSEL_MASK                                0x30
#define    RG_VM_VOSEL_SHIFT                               4

// (RW)
#define    RG_VM_EN_ADDR                                   0x8A
#define    RG_VM_EN_MASK                                   0x01
#define    RG_VM_EN_SHIFT                                  0

// (0x08B) DIGLDO_CON10
// (RW)
#define    RG_VM_STBTD_ADDR                                0x8B
#define    RG_VM_STBTD_MASK                                0x30
#define    RG_VM_STBTD_SHIFT                               4

// (RW)
#define    RG_VM_OCFB_EN_ADDR                              0x8B
#define    RG_VM_OCFB_EN_MASK                              0x02
#define    RG_VM_OCFB_EN_SHIFT                             1

// (RW)
#define    RG_VM_NDIS_EN_ADDR                              0x8B
#define    RG_VM_NDIS_EN_MASK                              0x01
#define    RG_VM_NDIS_EN_SHIFT                             0

// (0x08C) DIGLDO_CON11
// (RO)
#define    QI_VMC_MODE_ADDR                                0x8C
#define    QI_VMC_MODE_MASK                                0x80
#define    QI_VMC_MODE_SHIFT                               7

// (RW)
#define    VMC_LP_MODE_SET_ADDR                            0x8C
#define    VMC_LP_MODE_SET_MASK                            0x02
#define    VMC_LP_MODE_SET_SHIFT                           1

// (RW)
#define    VMC_LP_SEL_ADDR                                 0x8C
#define    VMC_LP_SEL_MASK                                 0x01
#define    VMC_LP_SEL_SHIFT                                0

// (0x08D) DIGLDO_CON12
// (RO)
#define    QI_VM_MODE_ADDR                                 0x8D
#define    QI_VM_MODE_MASK                                 0x80
#define    QI_VM_MODE_SHIFT                                7

// (RW)
#define    VM_LP_MODE_SET_ADDR                             0x8D
#define    VM_LP_MODE_SET_MASK                             0x02
#define    VM_LP_MODE_SET_SHIFT                            1

// (RW)
#define    VM_LP_SEL_ADDR                                  0x8D
#define    VM_LP_SEL_MASK                                  0x01
#define    VM_LP_SEL_SHIFT                                 0

// (0x08F) DIGLDO_CON14
// (RW)
#define    RG_RSV_DLDOS_ADDR                               0x8F
#define    RG_RSV_DLDOS_MASK                               0xFF
#define    RG_RSV_DLDOS_SHIFT                              0

//RegisterAnaLDO

// (0x0A0) ANALDO_CON0
// (RW)
#define    RG_VTCXO_CAL_ADDR                               0xA0
#define    RG_VTCXO_CAL_MASK                               0x0F
#define    RG_VTCXO_CAL_SHIFT                              0

// (0x0A1) ANALDO_CON1
// (RO)
#define    QI_VTCXO_EN_ADDR                                0xA1
#define    QI_VTCXO_EN_MASK                                0x80
#define    QI_VTCXO_EN_SHIFT                               7

// (RW)
#define    VTCXO_ON_CTRL_ADDR                              0xA1
#define    VTCXO_ON_CTRL_MASK                              0x02
#define    VTCXO_ON_CTRL_SHIFT                             1

// (RW)
#define    RG_VTCXO_EN_ADDR                                0xA1
#define    RG_VTCXO_EN_MASK                                0x01
#define    RG_VTCXO_EN_SHIFT                               0

// (0x0A2) ANALDO_CON2
// (RW)
#define    RG_VTCXO_STBTD_ADDR                             0xA2
#define    RG_VTCXO_STBTD_MASK                             0x30
#define    RG_VTCXO_STBTD_SHIFT                            4

// (RW)
#define    RG_VTCXO_OCFB_EN_ADDR                           0xA2
#define    RG_VTCXO_OCFB_EN_MASK                           0x02
#define    RG_VTCXO_OCFB_EN_SHIFT                          1

// (RW)
#define    RG_VTCXO_NDIS_EN_ADDR                           0xA2
#define    RG_VTCXO_NDIS_EN_MASK                           0x01
#define    RG_VTCXO_NDIS_EN_SHIFT                          0

// (0x0A3) ANALDO_CON3
// (RW)
#define    RG_VA25_CAL_ADDR                                0xA3
#define    RG_VA25_CAL_MASK                                0x0F
#define    RG_VA25_CAL_SHIFT                               0

// (0x0A4) ANALDO_CON4
// (RO)
#define    QI_VA25_EN_ADDR                                 0xA4
#define    QI_VA25_EN_MASK                                 0x80
#define    QI_VA25_EN_SHIFT                                7

// (RW)
#define    RG_VA25_EN_ADDR                                 0xA4
#define    RG_VA25_EN_MASK                                 0x01
#define    RG_VA25_EN_SHIFT                                0

// (0x0A5) ANALDO_CON5
// (RW)
#define    RG_VA25_STBTD_ADDR                              0xA5
#define    RG_VA25_STBTD_MASK                              0x30
#define    RG_VA25_STBTD_SHIFT                             4

// (RW)
#define    RG_VA25_OCFB_EN_ADDR                            0xA5
#define    RG_VA25_OCFB_EN_MASK                            0x02
#define    RG_VA25_OCFB_EN_SHIFT                           1

// (RW)
#define    RG_VA25_NDIS_EN_ADDR                            0xA5
#define    RG_VA25_NDIS_EN_MASK                            0x01
#define    RG_VA25_NDIS_EN_SHIFT                           0

// (0x0A6) ANALDO_CON6
// (RO)
#define    QI_VA25_MODE_ADDR                               0xA6
#define    QI_VA25_MODE_MASK                               0x80
#define    QI_VA25_MODE_SHIFT                              7

// (RW)
#define    VA25_LP_SET_ADDR                                0xA6
#define    VA25_LP_SET_MASK                                0x02
#define    VA25_LP_SET_SHIFT                               1

// (RW)
#define    VA25_LP_SEL_ADDR                                0xA6
#define    VA25_LP_SEL_MASK                                0x01
#define    VA25_LP_SEL_SHIFT                               0

// (0x0A7) ANALDO_CON7
// (RO)
#define    QI_VTCXO_MODE_ADDR                              0xA7
#define    QI_VTCXO_MODE_MASK                              0x80
#define    QI_VTCXO_MODE_SHIFT                             7

// (RW)
#define    VTCXO_LP_SET_ADDR                               0xA7
#define    VTCXO_LP_SET_MASK                               0x02
#define    VTCXO_LP_SET_SHIFT                              1

// (RW)
#define    VTCXO_LP_SEL_ADDR                               0xA7
#define    VTCXO_LP_SEL_MASK                               0x01
#define    VTCXO_LP_SEL_SHIFT                              0

// (0x0A8) ANALDO_CON8
// (RW)
#define    RG_VA25_STB_ADDR                                0xA8
#define    RG_VA25_STB_MASK                                0x02
#define    RG_VA25_STB_SHIFT                               1

// (RW)
#define    RG_VTCXO_STB_ADDR                               0xA8
#define    RG_VTCXO_STB_MASK                               0x01
#define    RG_VTCXO_STB_SHIFT                              0

//RegisterBuckK

// (0x0B0) BUCK_K_CON0
// (RW)
#define    RG_SMPS_TESTMODE_ADDR                           0xB0
#define    RG_SMPS_TESTMODE_MASK                           0x3F
#define    RG_SMPS_TESTMODE_SHIFT                          0

// (0x0B2) BUCK_K_CON2
// (RW)
#define    RG_SMPS_RSV_ADDR                                0xB2
#define    RG_SMPS_RSV_MASK                                0xFF
#define    RG_SMPS_RSV_SHIFT                               0

// (0x0B3) BUCK_K_CON3
// (RW)
#define    rg_auto_k_ADDR                                  0xB3
#define    rg_auto_k_MASK                                  0x40
#define    rg_auto_k_SHIFT                                 6

// (RW)
#define    rg_k_start_manual_ADDR                          0xB3
#define    rg_k_start_manual_MASK                          0x10
#define    rg_k_start_manual_SHIFT                         4

// (RW)
#define    rg_k_map_sel_ADDR                               0xB3
#define    rg_k_map_sel_MASK                               0x02
#define    rg_k_map_sel_SHIFT                              1

// (RW)
#define    rg_k_rst_done_ADDR                              0xB3
#define    rg_k_rst_done_MASK                              0x01
#define    rg_k_rst_done_SHIFT                             0

// (0x0B4) BUCK_K_CON4
// (RW)
#define    rg_k_control_smps_ADDR                          0xB4
#define    rg_k_control_smps_MASK                          0x3F
#define    rg_k_control_smps_SHIFT                         0

// (0x0B5) BUCK_K_CON5
// (RO)
#define    k_control_ADDR                                  0xB5
#define    k_control_MASK                                  0xFC
#define    k_control_SHIFT                                 2

// (RO)
#define    k_done_ADDR                                     0xB5
#define    k_done_MASK                                     0x02
#define    k_done_SHIFT                                    1

// (RO)
#define    k_result_ADDR                                   0xB5
#define    k_result_MASK                                   0x01
#define    k_result_SHIFT                                  0

// (0x0B6) BUCK_K_CON6
// (RW)
#define    efuse_enb_ADDR                                  0xB6
#define    efuse_enb_MASK                                  0x80
#define    efuse_enb_SHIFT                                 7

// (RW)
#define    efuse_read_ADDR                                 0xB6
#define    efuse_read_MASK                                 0x40
#define    efuse_read_SHIFT                                6

// (RW)
#define    efuse_program_ADDR                              0xB6
#define    efuse_program_MASK                              0x20
#define    efuse_program_SHIFT                             5

// (RW)
#define    efuse_address_ADDR                              0xB6
#define    efuse_address_MASK                              0x1F
#define    efuse_address_SHIFT                             0

// (0x0B7) BUCK_K_CON7
// (RW)
#define    efuse_address_msb_ADDR                          0xB7
#define    efuse_address_msb_MASK                          0x80
#define    efuse_address_msb_SHIFT                         7

// (RW)
#define    rg_sw_osc_trim_ADDR                             0xB7
#define    rg_sw_osc_trim_MASK                             0x01
#define    rg_sw_osc_trim_SHIFT                            0

// (0x0B8) BUCK_K_CON8
// (RO)
#define    efuse_dout0_ADDR                                0xB8
#define    efuse_dout0_MASK                                0xFF
#define    efuse_dout0_SHIFT                               0

// (0x0B9) BUCK_K_CON9
// (RO)
#define    efuse_dout1_ADDR                                0xB9
#define    efuse_dout1_MASK                                0xFF
#define    efuse_dout1_SHIFT                               0

// (0x0BA) BUCK_K_CON10
// (RO)
#define    efuse_dout2_ADDR                                0xBA
#define    efuse_dout2_MASK                                0xFF
#define    efuse_dout2_SHIFT                               0

// (0x0BB) BUCK_K_CON11
// (RO)
#define    efuse_dout3_ADDR                                0xBB
#define    efuse_dout3_MASK                                0xFF
#define    efuse_dout3_SHIFT                               0

// (0x0BC) BUCK_K_CON12
// (RO)
#define    efuse_dout4_ADDR                                0xBC
#define    efuse_dout4_MASK                                0xFF
#define    efuse_dout4_SHIFT                               0

// (0x0BD) BUCK_K_CON13
// (RO)
#define    efuse_dout5_ADDR                                0xBD
#define    efuse_dout5_MASK                                0xFF
#define    efuse_dout5_SHIFT                               0

// (0x0BE) BUCK_K_CON14
// (RO)
#define    efuse_dout6_ADDR                                0xBE
#define    efuse_dout6_MASK                                0xFF
#define    efuse_dout6_SHIFT                               0

// (0x0BF) BUCK_K_CON15
// (RO)
#define    efuse_dout7_ADDR                                0xBF
#define    efuse_dout7_MASK                                0xFF
#define    efuse_dout7_SHIFT                               0

//RegisterPAD

// (0x0D0) PAD_CTRL_CON0
// (RW)
#define    SCK_PU_ADDR                                     0xD0
#define    SCK_PU_MASK                                     0x20
#define    SCK_PU_SHIFT                                    5

// (RW)
#define    SCK_PD_ADDR                                     0xD0
#define    SCK_PD_MASK                                     0x10
#define    SCK_PD_SHIFT                                    4

// (RW)
#define    SCK_E2_ADDR                                     0xD0
#define    SCK_E2_MASK                                     0x08
#define    SCK_E2_SHIFT                                    3

// (RW)
#define    SCK_E4_ADDR                                     0xD0
#define    SCK_E4_MASK                                     0x04
#define    SCK_E4_SHIFT                                    2

// (RW)
#define    SCK_SMT_ADDR                                    0xD0
#define    SCK_SMT_MASK                                    0x02
#define    SCK_SMT_SHIFT                                   1

// (RW)
#define    SCK_SR_ADDR                                     0xD0
#define    SCK_SR_MASK                                     0x01
#define    SCK_SR_SHIFT                                    0

// (0x0D1) PAD_CTRL_CON1
// (RW)
#define    SDA_PU_ADDR                                     0xD1
#define    SDA_PU_MASK                                     0x20
#define    SDA_PU_SHIFT                                    5

// (RW)
#define    SDA_PD_ADDR                                     0xD1
#define    SDA_PD_MASK                                     0x10
#define    SDA_PD_SHIFT                                    4

// (RW)
#define    SDA_E2_ADDR                                     0xD1
#define    SDA_E2_MASK                                     0x08
#define    SDA_E2_SHIFT                                    3

// (RW)
#define    SDA_E4_ADDR                                     0xD1
#define    SDA_E4_MASK                                     0x04
#define    SDA_E4_SHIFT                                    2

// (RW)
#define    SDA_SMT_ADDR                                    0xD1
#define    SDA_SMT_MASK                                    0x02
#define    SDA_SMT_SHIFT                                   1

// (RW)
#define    SDA_SR_ADDR                                     0xD1
#define    SDA_SR_MASK                                     0x01
#define    SDA_SR_SHIFT                                    0

// (0x0D2) PAD_CTRL_CON2
// (RW)
#define    SRCLKEN_PU_ADDR                                 0xD2
#define    SRCLKEN_PU_MASK                                 0x20
#define    SRCLKEN_PU_SHIFT                                5

// (RW)
#define    SRCLKEN_PD_ADDR                                 0xD2
#define    SRCLKEN_PD_MASK                                 0x10
#define    SRCLKEN_PD_SHIFT                                4

// (RW)
#define    SRCLKEN_E2_ADDR                                 0xD2
#define    SRCLKEN_E2_MASK                                 0x08
#define    SRCLKEN_E2_SHIFT                                3

// (RW)
#define    SRCLKEN_E4_ADDR                                 0xD2
#define    SRCLKEN_E4_MASK                                 0x04
#define    SRCLKEN_E4_SHIFT                                2

// (RW)
#define    SRCLKEN_SMT_ADDR                                0xD2
#define    SRCLKEN_SMT_MASK                                0x02
#define    SRCLKEN_SMT_SHIFT                               1

// (RW)
#define    SRCLKEN_SR_ADDR                                 0xD2
#define    SRCLKEN_SR_MASK                                 0x01
#define    SRCLKEN_SR_SHIFT                                0

// (0x0E0) VERSION
// (RO)
#define    VERSION_ADDR                                    0xE0
#define    VERSION_MASK                                    0xFF
#define    VERSION_SHIFT                                   0

// (0x0F0) BIST_CTRL_CON0
// (RW)
#define    RG_VTCXO_BIST_EN_ADDR                           0xF0
#define    RG_VTCXO_BIST_EN_MASK                           0x08
#define    RG_VTCXO_BIST_EN_SHIFT                          3

// (RW)
#define    RG_VA25_BIST_EN_ADDR                            0xF0
#define    RG_VA25_BIST_EN_MASK                            0x01
#define    RG_VA25_BIST_EN_SHIFT                           0

// (0x0F1) BIST_CTRL_CON1
// (RW)
#define    RG_VM_BIST_EN_ADDR                              0xF1
#define    RG_VM_BIST_EN_MASK                              0x08
#define    RG_VM_BIST_EN_SHIFT                             3

// (RW)
#define    RG_VMC_BIST_EN_ADDR                             0xF1
#define    RG_VMC_BIST_EN_MASK                             0x04
#define    RG_VMC_BIST_EN_SHIFT                            2

// (RW)
#define    RG_VIO18_BIST_EN_ADDR                           0xF1
#define    RG_VIO18_BIST_EN_MASK                           0x02
#define    RG_VIO18_BIST_EN_SHIFT                          1

// (RW)
#define    RG_VSIM_BIST_EN_ADDR                            0xF1
#define    RG_VSIM_BIST_EN_MASK                            0x01
#define    RG_VSIM_BIST_EN_SHIFT                           0

// (0x0F2) BIST_CTRL_CON2
// (RW)
#define    RG_ABIST_MUX_ADDR                               0xF2
#define    RG_ABIST_MUX_MASK                               0x0F
#define    RG_ABIST_MUX_SHIFT                              0

//Register Group

//Memory

#define PMIC_BANK0_MAX_REG_IDX                             RG_ABIST_MUX_ADDR
#define PMIC_BANK0_REG_NUM                                 (PMIC_BANK0_MAX_REG_IDX + 1)

#endif //#if defined(PMIC_6327_REG_API)

#endif // #ifndef __DCL_PMIC6327_HW_H_STRUCT__
