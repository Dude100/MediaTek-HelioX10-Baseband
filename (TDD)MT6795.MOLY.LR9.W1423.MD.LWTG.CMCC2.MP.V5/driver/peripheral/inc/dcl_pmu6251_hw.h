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
 *    dcl_pmu6251_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMIC 6251 driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PMU6251_HW_H__
#define __PMU6251_HW_H__

#if defined(PMIC_6251_REG_API)

#define PMU_BASE        MIXED_base
#define PMU_END         (PMU_BASE+0x1000)

///////////////////////////////////////////////////////////////////////////////
// LDO group
#define VRF_CON0          (PMU_BASE + 0x0800)
#define VTCXO_CON0        (PMU_BASE + 0x0810)
#define VA_CON0           (PMU_BASE + 0x0820)
#define VIO28_CON0        (PMU_BASE + 0x0850)
#define VUSB_CON0         (PMU_BASE + 0x0860)
#define VSF_CON0          (PMU_BASE + 0x0870)
#define VSIM_CON0         (PMU_BASE + 0x0880)
#define VSIM2_CON0        (PMU_BASE + 0x0890)
#define VRTC_CON0         (PMU_BASE + 0x08A0)
#define VIBR_CON0         (PMU_BASE + 0x08B0)
#define VFM_CON0          (PMU_BASE + 0x08D0)
#define VIO18_CON0        (PMU_BASE + 0x08F0)

// BUCK group
#define VCORE_CON0        (PMU_BASE + 0x0900)

// BOOST group
#define BOOST_CON0        (PMU_BASE + 0x0B00)

// iSINK group
#define ISINK0_CON0       (PMU_BASE + 0x0C00)
#define ISINK1_CON0       (PMU_BASE + 0x0C10)
#define ISINK2_CON0       (PMU_BASE + 0x0C20)
#define ISINK3_CON0       (PMU_BASE + 0x0C30)

// KPLED group
#define KPLED_CON0        (PMU_BASE + 0x0C80)

// SPK
#define SPK_CON0          (PMU_BASE + 0x0D00)

// CHR
#define CHR_CON0          (PMU_BASE + 0x0A00)

#if defined(__MT6251PMU_E1_BC11_VSRC_EN_AT_TEST_CON1_BIT4__)
#define TEST_CON1         (PMU_BASE + 0x0F04)
#endif // #if defined(__MT6251PMU_E1_BC11_VSRC_EN_AT_TEST_CON1_BIT4__)

// STARTUP
#define STRUP_CON0        (PMU_BASE + 0x0A80)

///////////////////////////////////////////////////////////////////////////////


// BC11 VSRC_EN
#define MT6251_E1_BC11_VSRC_EN_MASK      0x0030
#define MT6251_E1_BC11_VSRC_EN_SHIFT     4


#define CON0_OFFSET           0x00
#define CON1_OFFSET           0x04
#define CON2_OFFSET           0x08
#define CON3_OFFSET           0x0C
#define CON4_OFFSET           0x10
#define CON5_OFFSET           0x14
#define CON6_OFFSET           0x18
#define CON7_OFFSET           0x1C
#define CON8_OFFSET           0x20
#define CON9_OFFSET           0x24

// LDO and BUCK cmds
#define LDO_BUCK_EN_OFFSET          CON0_OFFSET
#define LDO_BUCK_EN_MASK               0x0001
#define LDO_BUCK_EN_SHIFT              0

#define LDO_BUCK_VOL_SEL_OFFSET		CON0_OFFSET
#define LDO_BUCK_VOL_SEL_MASK          0x01F0
#define LDO_BUCK_VOL_SEL_SHIFT         4

#define LDO_BUCK_OC_AUTO_OFF_OFFSET CON0_OFFSET
#define LDO_BUCK_OC_AUTO_OFF_MASK      0x1000
#define LDO_BUCK_OC_AUTO_OFF_SHIFT     12

#define LDO_BUCK_STB_EN_OFFSET		CON0_OFFSET
#define LDO_BUCK_STB_EN_MASK           0x0800
#define LDO_BUCK_STB_EN_SHIFT          11

#define LDO_BUCK_ON_SEL_OFFSET		CON0_OFFSET
#define LDO_BUCK_ON_SEL_MASK           0x0002
#define LDO_BUCK_ON_SEL_SHIFT          1

#define LDO_BUCK_NDIS_EN_OFFSET		CON0_OFFSET
#define LDO_BUCK_NDIS_EN_MASK          0x0400
#define LDO_BUCK_NDIS_EN_SHIFT         10

#define LDO_BUCK_OCFB_EN_OFFSET		CON0_OFFSET
#define LDO_BUCK_OCFB_EN_MASK          0x2000
#define LDO_BUCK_OCFB_EN_SHIFT         13


// LDO cmds
#define LDO_CAL_OFFSET		CON1_OFFSET
#define LDO_CAL_MASK              0x01F0
#define LDO_CAL_SHIFT             4

#define LDO_STB_TD_OFFSET		CON1_OFFSET
#define LDO_STB_TD_MASK           0x0003
#define LDO_STB_TD_SHIFT          0

#define LDO_OC_TD_OFFSET		CON2_OFFSET
#define LDO_OC_TD_MASK            0x0030
#define LDO_OC_TD_SHIFT           4

// BUCK cmds
#define BUCK_VFBADJ_SLEEP_OFFSET	CON1_OFFSET
#define BUCK_VFBADJ_SLEEP_MASK    0x01F0
#define BUCK_VFBADJ_SLEEP_SHIFT   4

#define BUCK_ICAL_EN_OFFSET	CON3_OFFSET
#define BUCK_ICAL_EN_MASK         0x3000
#define BUCK_ICAL_EN_SHIFT        12

#define BUCK_CSL_OFFSET	CON5_OFFSET
#define BUCK_CSL_MASK             0x0700
#define BUCK_CSL_SHIFT            8

#define BUCK_STB_TD_OFFSET		CON3_OFFSET
#define BUCK_STB_TD_MASK          0x00C0
#define BUCK_STB_TD_SHIFT         6

#define BUCK_OC_THD_OFFSET	CON3_OFFSET
#define BUCK_OC_THD_MASK          0x0300
#define BUCK_OC_THD_SHIFT         8

#define BUCK_BURST_OFFSET		CON5_OFFSET
#define BUCK_BURST_MASK           0x3000
#define BUCK_BURST_SHIFT          12

// SPK
#define SPK_EN_OFFSET				CON0_OFFSET
#define SPK_EN_MASK				0x0001
#define SPK_EN_SHIFT				0

#define SPK_VOL_OFFSET              CON0_OFFSET
#define SPK_VOL_MASK              0x01F0
#define SPK_VOL_SHIFT             4

#define SPK_CCODE_OFFSET         CON1_OFFSET
#define SPK_CCODE_MASK            0x00F0
#define SPK_CCODE_SHIFT           4

#define SPK_OC_EN_OFFSET 	    CON3_OFFSET  
#define SPK_OC_EN_MASK            0x0400
#define SPK_OC_EN_SHIFT           10

#define SPK_OSC_ISEL_OFFSET         CON3_OFFSET
#define SPK_OSC_ISEL_MASK         0x00C0
#define SPK_OSC_ISEL_SHIFT        6

#define SPK_NG_DT_DLY_OFFSET         CON4_OFFSET
#define SPK_NG_DT_DLY_MASK         0x000f
#define SPK_NG_DT_DLY_SHIFT        0

#define SPK_OCP_BIAS_OFFSET         CON4_OFFSET
#define SPK_OCP_BIAS_MASK            0x7000
#define SPK_OCP_BIAS_SHIFT           12

#define SPK_OCN_BIAS_OFFSET         CON4_OFFSET
#define SPK_OCN_BIAS_MASK            0x0700
#define SPK_OCN_BIAS_SHIFT           8


#define SPK_PG_SLEW_I_OFFSET	     CON5_OFFSET
#define SPK_PG_SLEW_I_MASK            0x3000
#define SPK_PG_SLEW_I_SHIFT           12

#define SPK_NG_SLEW_DLY_OFFSET         CON5_OFFSET
#define SPK_NG_SLEW_DLY_MASK            0x0007
#define SPK_NG_SLEW_DLY_SHIFT           0

#define SPK_PG_SLEW_DLY_OFFSET         CON5_OFFSET
#define SPK_PG_SLEW_DLY_MASK            0x0700
#define SPK_PG_SLEW_DLY_SHIFT           8

#define SPK_AB_OBIAS_OFFSET         CON7_OFFSET
#define SPK_AB_OBIAS_MASK         0x0030
#define SPK_AB_OBIAS_SHIFT        4

#define SPK_MODE_OFFSET         CON7_OFFSET
#define SPK_MODE_MASK             0x0001
#define SPK_MODE_SHIFT            0

#define SPK_AB_OC_EN_OFFSET      CON7_OFFSET
#define SPK_AB_OC_EN_MASK         0x0100
#define SPK_AB_OC_EN_SHIFT        8

//ISINK
#define ISINK_EN_OFFSET		CON0_OFFSET
#define ISINK_EN_MASK             0x0001
#define ISINK_EN_SHIFT            0

#define ISINK_MODE_OFFSET		CON0_OFFSET
#define ISINK_MODE_MASK           0x0002
#define ISINK_MODE_SHIFT          1

#define ISINK_STEP_OFFSET		CON0_OFFSET
#define ISINK_STEP_MASK           0x01F0
#define ISINK_STEP_SHIFT          4

#define ISINK_VREF_CAL_OFFSET		CON1_OFFSET
#define ISINK_VREF_CAL_MASK       0x1F00
#define ISINK_VREF_CAL_SHIFT      8


//BOOST
#define BOOST_TYPE_OFFSET        CON0_OFFSET
#define BOOST_TYPE_MASK           0x0002
#define BOOST_TYPE_SHIFT          1

#define BOOST_HW_SEL_OFFSET     CON6_OFFSET
#define BOOST_HW_SEL_MASK         0x0001
#define BOOST_HW_SEL_SHIFT        0


//KPLED
#define KPLED_EN_OFFSET		CON0_OFFSET
#define KPLED_EN_MASK             0x0001
#define KPLED_EN_SHIFT            0

#define KPLED_MODE_OFFSET		CON0_OFFSET
#define KPLED_MODE_MASK           0x0002
#define KPLED_MODE_SHIFT          1

#define KPLED_SEL_OFFSET		CON0_OFFSET
#define KPLED_SEL_MASK            0x0070
#define KPLED_SEL_SHIFT           4


//CHR
#define CSDAC_EN_OFFSET		CON0_OFFSET
#define CSDAC_EN_MASK             0x0800
#define CSDAC_EN_SHIFT            11

#define CHR_EN_OFFSET		CON0_OFFSET
#define CHR_EN_MASK               0x1000
#define CHR_EN_SHIFT              12

#define CHRDET_OFFSET		CON0_OFFSET
#define CHRDET_MASK               0x2000
#define CHRDET_SHIFT              13

#define VCDT_HV_VTH_OFFSET        CON0_OFFSET			
#define VCDT_HV_VTH_MASK          0x00F0
#define VCDT_HV_VTH_SHIFT         4

#define VCDT_HV_EN_OFFSET        CON0_OFFSET			
#define VCDT_HV_EN_MASK          0x0100
#define VCDT_HV_EN_SHIFT         8

#define VBAT_CV_VTH_OFFSET		CON1_OFFSET
#define VBAT_CV_VTH_MASK          0x001F
#define VBAT_CV_VTH_SHIFT         0

#define VBAT_CV_EN_OFFSET		CON1_OFFSET
#define VBAT_CV_EN_MASK           0x0100
#define VBAT_CV_EN_SHIFT          8

#define VBAT_CV_DET_OFFSET		CON1_OFFSET
#define VBAT_CV_DET_MASK          0x4000
#define VBAT_CV_DET_SHIFT         14

#define CS_VTH_OFFSET		CON2_OFFSET
#define CS_VTH_MASK               0x0700
#define CS_VTH_SHIFT              8

#define BATON_HT_EN_OFFSET        CON3_OFFSET	
#define BATON_HT_EN_MASK		0x0400
#define BATON_HT_EN_SHIFT 		10

#define CSDAC_DLY_OFFSET         CON3_OFFSET
#define CSDAC_DLY_MASK            0x0030
#define CSDAC_DLY_SHIFT           4

#define CSDAC_STP_OFFSET         CON3_OFFSET
#define CSDAC_STP_MASK            0x0003
#define CSDAC_STP_SHIFT           0

#define BATON_UNDET_OFFSET         CON3_OFFSET
#define BATON_UNDET_MASK          0x8000
#define BATON_UNDET_SHIFT         15

#define OTG_BVALID_EN_OFFSET     CON5_OFFSET
#define OTG_BVALID_EN_MASK        0x1000
#define OTG_BVALID_EN_SHIFT       12

#define CHRWDT_EN_OFFSET		CON6_OFFSET
#define CHRWDT_EN_MASK            0x0010
#define CHRWDT_EN_SHIFT           4

#define CHRWDT_TD_OFFSET		CON6_OFFSET 
#define CHRWDT_TD_MASK            0x000F  // TTTTTTTTT
#define CHRWDT_TD_SHIFT           0

#define CHRWDT_OUT_OFFSET	CON7_OFFSET 
#define CHRWDT_OUT_MASK           0x8000
#define CHRWDT_OTU_SHIFT          15

#define CHRWDT_INT_EN_OFFSET	CON7_OFFSET  
#define CHRWDT_INT_EN_MASK        0x0001
#define CHRWDT_INT_EN_SHIFT       0

#define CHRWDT_FLAG_WR_OFFSET	CON7_OFFSET  
#define CHRWDT_FLAG_WR_MASK       0x0002
#define CHRWDT_FLAG_WR_SHIFT      1

#define ADC_EN_OFFSET		 CON8_OFFSET
#define ADC_EN_MASK               0x7000   // All ADC channels are enabled at same time
#define ADC_EN_SHIFT              12

#define BC11_VREF_VTH_OFFSET     CON9_OFFSET
#define BC11_VREF_VTH_MASK        0x0001
#define BC11_VREF_VTH_SHIFT       0

#define BC11_CMP_EN_OFFSET       CON9_OFFSET
#define BC11_CMP_EN_MASK          0x0006
#define BC11_CMP_EN_SHIFT         1

#define BC11_IPD_EN_OFFSET      CON9_OFFSET
#define BC11_IPD_EN_MASK          0x0018
#define BC11_IPD_EN_SHIFT         3

#define BC11_IPU_EN_OFFSET	     CON9_OFFSET
#define BC11_IPU_EN_MASK          0x0060
#define BC11_IPU_EN_SHIFT         5

#define BC11_BIAS_EN_OFFSET	CON9_OFFSET
#define BC11_BIAS_EN_MASK         0x0080
#define BC11_BIAS_EN_SHIFT        7

#define BC11_BB_CTRL_OFFSET	CON9_OFFSET
#define BC11_BB_CTRL_MASK         0x0100
#define BC11_BB_CTRL_SHIFT        8

#define BC11_RST_OFFSET	  CON9_OFFSET
#define BC11_RST_MASK             0x0200
#define BC11_RST_SHIFT            9

#define BC11_VSRC_EN_OFFSET     CON9_OFFSET
#define BC11_VSRC_EN_MASK         0x0C00
#define BC11_VSRC_EN_SHIFT        10

#define BC11_CMP_OUT_OFFSET     CON9_OFFSET
#define BC11_CMP_OUT_MASK         0x8000
#define BC11_CMP_OUT_SHIFT        15


// STRUP
// STRUP_XXX CON0
#define USBDL_EN_OFFSET	CON0_OFFSET
#define USBDL_EN_MASK             0x0010
#define USBDL_EN_SHIFT            4

// BOOST
#define BOOST_CKS_PRG_OFFSET	CON3_OFFSET  
#define BOOST_CKS_PRG_MASK        0x003F
#define BOOST_CKS_PRG_SHIFT       0

//MISC
#define CCI_SRCLKEN_OFFSET CON2_OFFSET
#define CCI_SRCLKEN_MASK 	0x0002
#define CCI_SRCLKEN_SHIFT 	1

#endif // #if defined(PMIC_6251_REG_API)

#endif // #ifndef __PMU6251_HW_H__
