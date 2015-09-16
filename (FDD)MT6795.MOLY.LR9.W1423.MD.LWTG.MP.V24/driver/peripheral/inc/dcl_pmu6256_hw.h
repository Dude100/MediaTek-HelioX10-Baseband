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
 *    dcl_pmu6256_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intended for PMU 6256 driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PMU6256_HW_H__
#define __PMU6256_HW_H__


#if defined(PMIC_6256_REG_API)

#define PMU_BASE            MIXED_base

#define PMU_END             (PMU_BASE+0x1000)

///////////////////////////////////////////////////////////////////////////////
// ABIST Group
#define ABIST_CON0          (PMU_BASE + 0x0010)
#define ABIST_CON1          (PMU_BASE + 0x0014)
#define ABIST_CON2          (PMU_BASE + 0x0018)
#define ABIST_CON3          (PMU_BASE + 0x001C)

// EFUSE Group
#define EFUSE_CON0          (PMU_BASE + 0x0100) // Only for 6256 E2
#define EFUSE_CON1          (PMU_BASE + 0x0104) // Only for 6256 E2
#define EFUSE_CON2          (PMU_BASE + 0x0108) // Only for 6256 E2
#define EFUSE_CON3          (PMU_BASE + 0x010C) // Only for 6256 E2

// LDO group
#define VRF_CON0            (PMU_BASE + 0x0800)
#define VTCXO_CON0          (PMU_BASE + 0x0810)
#define VA_CON0             (PMU_BASE + 0x0820)
#define VCAMA_CON0          (PMU_BASE + 0x0830)
#define VCAMD_CON0          (PMU_BASE + 0x0840)
#define VIO28_CON0          (PMU_BASE + 0x0850)
#define VUSB_CON0           (PMU_BASE + 0x0860)
#define VBT_CON0            (PMU_BASE + 0x0870)
#define VSIM_CON0           (PMU_BASE + 0x0880)
#define VSIM2_CON0          (PMU_BASE + 0x0890)
#define VRTC_CON0           (PMU_BASE + 0x08A0)
#define VIBR_CON0           (PMU_BASE + 0x08B0)
#define VMC_CON0            (PMU_BASE + 0x08C0)
#define VFM_CON0            (PMU_BASE + 0x08D0) // Only for 6256 E1
#define VM12_CON0           (PMU_BASE + 0x08E0) // Only for 6256 E1
#if !defined(MT6256_S00)
#define VIO18_CON0          (PMU_BASE + 0x08F0) // Only for 6256 E2
#endif // End of #if !defined(MT6256_S00)

// BUCK group
#define VCORE_CON0          (PMU_BASE + 0x0900)
#if defined(MT6256_S00)
#define VIO18_CON0          (PMU_BASE + 0x0920) // Only for 6256 E1
#endif // End of #if defined(MT6256_S00)

// BOOST group
#define BOOST_CON0          (PMU_BASE + 0x0B00) // Only for 6256 E1

// CHR
#define CHR_CON0            (PMU_BASE + 0x0A00)

// STARTUP
#define STRUP_CON0          (PMU_BASE + 0x0A80)

// iSINK group
#define ISINK0_CON0         (PMU_BASE + 0x0C00)
#define ISINK1_CON0         (PMU_BASE + 0x0C10)
#define ISINK2_CON0         (PMU_BASE + 0x0C20)
#define ISINK3_CON0         (PMU_BASE + 0x0C30)
#define ISINK4_CON0         (PMU_BASE + 0x0C40) // Only for 6256 E2
#define ISINK5_CON0         (PMU_BASE + 0x0C50) // Only for 6256 E2

// KPLED group
#define KPLED_CON0          (PMU_BASE + 0x0C80)

// SPK
#define SPK_CON0            (PMU_BASE + 0x0D00)

// PMIC_OC
#define PMIC_OC_CON0        (PMU_BASE + 0x0E00)
#define PMIC_OC_CON1        (PMU_BASE + 0x0E04)
#define PMIC_OC_CON2        (PMU_BASE + 0x0E08)
#define PMIC_OC_CON3        (PMU_BASE + 0x0E0C)
#define PMIC_OC_CON4        (PMU_BASE + 0x0E10)
#define PMIC_OC_CON5        (PMU_BASE + 0x0E14)
#define PMIC_OC_CON6        (PMU_BASE + 0x0E18)
#define PMIC_OC_CON7        (PMU_BASE + 0x0E1C)

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

// ABIST
#define ABIST_LMON_SEL_OFFSET           CON1_OFFSET
#define ABIST_LMON_SEL_MASK             0x00FF
#define ABIST_LMON_SEL_SHIFT            0

#define ABIST_HMON_SEL_OFFSET           CON1_OFFSET
#define ABIST_HMON_SEL_MASK             0xFF00
#define ABIST_HMON_SEL_SHIFT            8

#define ABIST_LMON_DATA_OFFSET          CON3_OFFSET
#define ABIST_LMON_DATA_MASK            0x000F
#define ABIST_LMON_DATA_SHIFT           0

#define ABIST_HMON_DATA_OFFSET          CON3_OFFSET
#define ABIST_HMON_DATA_MASK            0x00F0
#define ABIST_HMON_DATA_SHIFT           4

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

// LDO_CON2 MISC
#define CCI_SRCLKEN_OFFSET          	CON2_OFFSET
#define CCI_SRCLKEN_MASK 	        	0x0002
#define CCI_SRCLKEN_SHIFT 	        	1
                                    	
#define VA_LP_EN_OFFSET             	CON2_OFFSET
#define VA_LP_EN_MASK 	            	0x0002
#define VA_LP_EN_SHIFT 	            	1
                                    	
#define VSIM_GPLDO_EN_OFFSET        	CON2_OFFSET
#define VSIM_GPLDO_EN_MASK 	        	0x0002
#define VSIM_GPLDO_EN_SHIFT 	    	1
                                    	
#define VSIM2_GPLDO_EN_OFFSET       	CON2_OFFSET
#define VSIM2_GPLDO_EN_MASK 	    	0x0002
#define VSIM2_GPLDO_EN_SHIFT 	    	1

#define SIM2_GPIO_EN_OFFSET       	    CON3_OFFSET
#define SIM2_GPIO_EN_MASK 	    	    0x0001
#define SIM2_GPIO_EN_SHIFT 	    	    0

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

// CHR cmds
// CHR_CON0
#define VCDT_HV_EN_OFFSET	    		CON0_OFFSET
#define VCDT_HV_EN_MASK					0x0001
#define VCDT_HV_EN_SHIFT				0

#define CHR_LDO_DET_OFFSET	    		CON0_OFFSET
#define CHR_LDO_DET_MASK				0x0002
#define CHR_LDO_DET_SHIFT				1

#define PCHR_AUTOMODE_OFFSET    		CON0_OFFSET	
#define PCHR_AUTOMODE_MASK				0x0004
#define PCHR_AUTOMODE_SHIFT				2

#define CSDAC_EN_OFFSET	    			CON0_OFFSET
#define CSDAC_EN_MASK					0x0008
#define CSDAC_EN_SHIFT					3

#define CHR_EN_OFFSET   				CON0_OFFSET	
#define CHR_EN_MASK						0x0010
#define CHR_EN_SHIFT					4
                        				
#define CHRDET_OFFSET   				CON0_OFFSET	
#define CHRDET_MASK						0x0020
#define CHRDET_SHIFT					5

#define VCDT_LV_DET_OFFSET				CON0_OFFSET
#define VCDT_LV_DET_MASK				0x0040
#define VCDT_LV_DET_SHIFT				6
                            			
#define VCDT_HV_DET_OFFSET				CON0_OFFSET
#define VCDT_HV_DET_MASK				0x0080
#define VCDT_HV_DET_SHIFT				7
                            			
#define VCDT_LV_VTH_OFFSET				CON0_OFFSET
#define VCDT_LV_VTH_MASK				0x0F00
#define VCDT_LV_VTH_SHIFT				8
                            			
#define VCDT_HV_VTH_OFFSET				CON0_OFFSET
#define VCDT_HV_VTH_MASK				0xF000
#define VCDT_HV_VTH_SHIFT				12

// CHR_CON1
#define VBAT_CV_EN_OFFSET				CON1_OFFSET
#define VBAT_CV_EN_MASK					0x0001
#define VBAT_CV_EN_SHIFT				0

#define VBAT_CC_EN_OFFSET	            CON1_OFFSET
#define VBAT_CC_EN_MASK					0x0002
#define VBAT_CC_EN_SHIFT				1

#define VBAT_CV_DET_OFFSET				CON1_OFFSET
#define VBAT_CV_DET_MASK				0x0004
#define VBAT_CV_DET_SHIFT				2

#define VBAT_CC_DET_OFFSET				CON1_OFFSET
#define VBAT_CC_DET_MASK				0x0008
#define VBAT_CC_DET_SHIFT				3

#define VBAT_CC_VTH_OFFSET				CON1_OFFSET
#define VBAT_CC_VTH_MASK				0x0030
#define VBAT_CC_VTH_SHIFT				4
                            			
#define VBAT_CV_VTH_OFFSET				CON1_OFFSET
#define VBAT_CV_VTH_MASK				0x1F00
#define VBAT_CV_VTH_SHIFT				8

// CHR_CON2
#define CS_VTH_OFFSET					CON2_OFFSET
#define CS_VTH_MASK						0x000F
#define CS_VTH_SHIFT					0
                        				
#define CS_EN_OFFSET					CON2_OFFSET
#define CS_EN_MASK						0x0100
#define CS_EN_SHIFT						8
                        				
#define CS_DET_OFFSET					CON2_OFFSET
#define CS_DET_MASK						0x8000
#define CS_DET_SHIFT					15

// CHR_CON3                             
#define TOHTC_OFFSET					CON3_OFFSET
#define TOHTC_MASK						0x0007
#define TOHTC_SHIFT						0

#define TOLTC_OFFSET					CON3_OFFSET	
#define TOLTC_MASK						0x0700
#define TOLTC_SHIFT						8

// CHR_CON4
#define CSDAC_STP_INC_OFFSET	        CON4_OFFSET
#define CSDAC_STP_INC_MASK				0x0007
#define CSDAC_STP_INC_SHIFT				0
                            			
#define CSDAC_STP_DEC_OFFSET			CON4_OFFSET	
#define CSDAC_STP_DEC_MASK				0x0070
#define CSDAC_STP_DEC_SHIFT				4

#define CSDAC_STP_OFFSET	            CON4_OFFSET
#define CSDAC_STP_MASK					0x0700
#define CSDAC_STP_SHIFT					8
                        				
#define CSDAC_DLY_OFFSET				CON4_OFFSET	
#define CSDAC_DLY_MASK					0x7000
#define CSDAC_DLY_SHIFT					12

// CHR_CON5
#define VBAT_OV_EN_OFFSET				CON5_OFFSET
#define VBAT_OV_EN_MASK					0x0001
#define VBAT_OV_EN_SHIFT				0
                            			
#define VBAT_OV_DEG_OFFSET				CON5_OFFSET
#define VBAT_OV_DEG_MASK				0x0002
#define VBAT_OV_DEG_SHIFT				1
                            			
#define VBAT_OV_DET_OFFSET				CON5_OFFSET
#define VBAT_OV_DET_MASK				0x0008
#define VBAT_OV_DET_SHIFT				3
                            			
#define VBAT_OV_VTH_OFFSET				CON5_OFFSET
#define VBAT_OV_VTH_MASK				0x0030
#define VBAT_OV_VTH_SHIFT				4
                            			
#define BATON_EN_OFFSET	    			CON5_OFFSET
#define BATON_EN_MASK					0x0100
#define BATON_EN_SHIFT					8
                            			
#define BATON_HT_EN_OFFSET				CON5_OFFSET
#define BATON_HT_EN_MASK				0x0200
#define BATON_HT_EN_SHIFT				9
                            			
#define BATON_UNDET_OFFSET				CON5_OFFSET
#define BATON_UNDET_MASK				0x0400
#define BATON_UNDET_SHIFT				10

// CHR_CON6
#define CSDAC_DATA_OFFSET				CON6_OFFSET	
#define CSDAC_DATA_MASK					0x03FF
#define CSDAC_DATA_SHIFT				0

// CHR_CON7
#define OTG_BVALID_EN_OFFSET			CON7_OFFSET	
#define OTG_BVALID_EN_MASK				0x0001
#define OTG_BVALID_EN_SHIFT				0
                            			
#define OTG_BVALID_OFFSET				CON7_OFFSET
#define OTG_BVALID_MASK					0x0008
#define OTG_BVALID_SHIFT				3
                            			
#define PCHR_TESTMODE_OFFSET			CON7_OFFSET	
#define PCHR_TESTMODE_MASK				0x0010
#define PCHR_TESTMODE_SHIFT				4

#define CSDAC_TESTMODE_OFFSET			CON7_OFFSET
#define CSDAC_TESTMODE_MASK				0x0020
#define CSDAC_TESTMODE_SHIFT			5
                                		
#define PCHR_RST_OFFSET	        		CON7_OFFSET
#define PCHR_RST_MASK					0x0040
#define PCHR_RST_SHIFT					6
                                		
#define PCHR_FT_CTRL_OFFSET				CON7_OFFSET
#define PCHR_FT_CTRL_MASK				0x0700
#define PCHR_FT_CTRL_SHIFT				8

// CHR_CON8
#define PCHR_FLAG_OUT_OFFSET			CON8_OFFSET	
#define PCHR_FLAG_OUT_MASK				0x000F
#define PCHR_FLAG_OUT_SHIFT				0
                            			
#define PCHR_FLAG_EN_OFFSET				CON8_OFFSET
#define PCHR_FLAG_EN_MASK				0x0080
#define PCHR_FLAG_EN_SHIFT				7
                            			
#define PCHR_FLAG_SEL_OFFSET			CON8_OFFSET	
#define PCHR_FLAG_SEL_MASK				0x1F00
#define PCHR_FLAG_SEL_SHIFT				8

// CHR_CON9
#define CHRWDT_TD_OFFSET				CON9_OFFSET	
#define CHRWDT_TD_MASK					0x000F
#define CHRWDT_TD_SHIFT					0

#define CHRWDT_EN_OFFSET	            CON9_OFFSET
#define CHRWDT_EN_MASK					0x0010
#define CHRWDT_EN_SHIFT					4

#define CHRWDT_INT_EN_OFFSET			CON9_OFFSET	
#define CHRWDT_INT_EN_MASK				0x0100
#define CHRWDT_INT_EN_SHIFT				8
                            			
#define CHRWDT_FLAG_OFFSET				CON9_OFFSET
#define CHRWDT_FLAG_MASK				0x0200
#define CHRWDT_FLAG_SHIFT				9
                            			
#define CHRWDT_OUT_OFFSET				CON9_OFFSET
#define CHRWDT_OUT_MASK					0x8000
#define CHRWDT_OUT_SHIFT				15

// CHR_CON10
#define UVLO_VTHL_OFFSET				CON10_OFFSET	
#define UVLO_VTHL_MASK					0x0003
#define UVLO_VTHL_SHIFT					0

#define ADC_EN_OFFSET		            CON10_OFFSET
#define ADC_EN_MASK                     0x0070   // All ADC channels are enabled at same time
#define ADC_EN_SHIFT                    4

#define ADCIN_VBAT_EN_OFFSET			CON10_OFFSET	
#define ADCIN_VBAT_EN_MASK				0x0010
#define ADCIN_VBAT_EN_SHIFT				4
                            			
#define ADCIN_VSEN_EN_OFFSET			CON10_OFFSET	
#define ADCIN_VSEN_EN_MASK				0x0020
#define ADCIN_VSEN_EN_SHIFT				5
                            			
#define ADCIN_CHR_EN_OFFSET				CON10_OFFSET
#define ADCIN_CHR_EN_MASK				0x0040
#define ADCIN_CHR_EN_SHIFT				6
                            			
#define BGR_RSEL_OFFSET	    			CON10_OFFSET
#define BGR_RSEL_MASK					0x0700
#define BGR_RSEL_SHIFT					8
                            			
#define BGR_UNCHOP_PH_OFFSET			CON10_OFFSET	
#define BGR_UNCHOP_PH_MASK				0x1000
#define BGR_UNCHOP_PH_SHIFT				12
                            			
#define BGR_UNCHOP_OFFSET				CON10_OFFSET
#define BGR_UNCHOP_MASK					0x2000
#define BGR_UNCHOP_SHIFT				13
                            			
#define USBDL_RST_OFFSET				CON10_OFFSET
#define USBDL_RST_MASK					0x4000
#define USBDL_RST_SHIFT					14
                            			
#define USBDL_SET_OFFSET				CON10_OFFSET
#define USBDL_SET_MASK					0x8000
#define USBDL_SET_SHIFT					15

// CHR_CON11
#define BC11_CMP_EN_OFFSET				CON11_OFFSET
#define BC11_CMP_EN_MASK				0x0003
#define BC11_CMP_EN_SHIFT				0
                                		
#define BC11_VSRC_EN_OFFSET				CON11_OFFSET
#define BC11_VSRC_EN_MASK				0x000C
#define BC11_VSRC_EN_SHIFT				2
                                		
#define BC11_IPD_EN_OFFSET	    		CON11_OFFSET
#define BC11_IPD_EN_MASK				0x0030
#define BC11_IPD_EN_SHIFT				4
                            			
#define BC11_IPU_EN_OFFSET	    		CON11_OFFSET
#define BC11_IPU_EN_MASK				0x00C0
#define BC11_IPU_EN_SHIFT				6
                            			
#define BC11_VREF_VTH_OFFSET			CON11_OFFSET	
#define BC11_VREF_VTH_MASK				0x0100
#define BC11_VREF_VTH_SHIFT				8
                            			
#define BC11_BIAS_EN_OFFSET				CON11_OFFSET
#define BC11_BIAS_EN_MASK				0x0200
#define BC11_BIAS_EN_SHIFT				9
                            			
#define BC11_BB_CTRL_OFFSET				CON11_OFFSET
#define BC11_BB_CTRL_MASK				0x0400
#define BC11_BB_CTRL_SHIFT				10
                            			
#define BC11_RST_OFFSET	        		CON11_OFFSET
#define BC11_RST_MASK					0x0800
#define BC11_RST_SHIFT					11
                        				
#define BC11_CMP_OUT_OFFSET	    		CON11_OFFSET
#define BC11_CMP_OUT_MASK				0x8000
#define BC11_CMP_OUT_SHIFT				15

// CHR_CON12
#define CV_MODE_OFFSET					CON12_OFFSET
#define CV_MODE_MASK					0x0001
#define CV_MODE_SHIFT					0
                            			
#define VCDT_MODE_OFFSET				CON12_OFFSET
#define VCDT_MODE_MASK					0x0002
#define VCDT_MODE_SHIFT					1
                            			
#define CSDAC_MODE_OFFSET				CON12_OFFSET
#define CSDAC_MODE_MASK					0x0004
#define CSDAC_MODE_SHIFT				2
                            			
#define TRACKING_EN_OFFSET				CON12_OFFSET
#define TRACKING_EN_MASK				0x0010
#define TRACKING_EN_SHIFT				4
                            			
#define HWCV_EN_OFFSET	    			CON12_OFFSET
#define HWCV_EN_MASK					0x0040
#define HWCV_EN_SHIFT					6
                            			
#define ULC_DET_EN_OFFSET				CON12_OFFSET
#define ULC_DET_EN_MASK					0x0080
#define ULC_DET_EN_SHIFT				7
                            			
#define LOW_ICH_DB_OFFSET				CON12_OFFSET
#define LOW_ICH_DB_MASK					0x3F00
#define LOW_ICH_DB_SHIFT				8
                            			
// CHR_CON13
#define OVP_TRIM_OFFSET					CON13_OFFSET
#define OVP_TRIM_MASK					0x000F
#define OVP_TRIM_SHIFT					0
                        				
#define DRV_ITUNE_OFFSET				CON14_OFFSET	
#define DRV_ITUNE_MASK					0x0300
#define DRV_ITUNE_SHIFT					8

// STRUP cmds
// STRUP_CON0
#define USBDL_EN_OFFSET	                CON0_OFFSET
#define USBDL_EN_MASK                   0x0010
#define USBDL_EN_SHIFT                  4

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

// KPLED
// KPLED_CON0
#define KPLED_EN_OFFSET					CON0_OFFSET
#define KPLED_EN_MASK             		0x0001
#define KPLED_EN_SHIFT            		0

#define KPLED_MODE_OFFSET				CON0_OFFSET
#define KPLED_MODE_MASK           		0x0002
#define KPLED_MODE_SHIFT          		1

#define KPLED_SEL_OFFSET				CON0_OFFSET
#define KPLED_SEL_MASK            		0x0070
#define KPLED_SEL_SHIFT           		4

#define KPLED_SFSTRTC_OFFSET			CON0_OFFSET
#define KPLED_SFSTRTC_MASK            	0x0300
#define KPLED_SFSTRTC_SHIFT           	8

#define KPLED_SFSTREN_OFFSET			CON0_OFFSET
#define KPLED_SFSTREN_MASK            	0x0400
#define KPLED_SFSTREN_SHIFT           	10

#define KPLED_STATUS_OFFSET				CON0_OFFSET
#define KPLED_STATUS_MASK            	0x8000
#define KPLED_STATUS_SHIFT           	15

// KPLED_CON1
#define KPLED_FORCE_OFF_OFFSET			CON1_OFFSET
#define KPLED_FORCE_OFF_MASK       		0x0001
#define KPLED_FORCE_OFF_SHIFT      		0

// SPK
// SPK_CON0
#define SPK_EN_OFFSET					CON0_OFFSET
#define SPK_EN_MASK						0x0001
#define SPK_EN_SHIFT					0

#define SPK_RST_OFFSET					CON0_OFFSET
#define SPK_RST_MASK					0x0002
#define SPK_RST_SHIFT					1

#define SPK_DTCAL_OFFSET				CON0_OFFSET
#define SPK_DTCAL_MASK					0x0008
#define SPK_DTCAL_SHIFT					3

#define SPK_VOL_OFFSET					CON0_OFFSET
#define SPK_VOL_MASK              		0x0010
#define SPK_VOL_SHIFT             		4

#define SPK_OC_AUTOFF_OFFSET			CON0_OFFSET
#define SPK_OC_AUTOFF_MASK              0x1000
#define SPK_OC_AUTOFF_SHIFT             12

#define SPK_OC_FLAG_EN_OFFSET			CON0_OFFSET  
#define SPK_OC_FLAG_EN_MASK            	0x4000
#define SPK_OC_FLAG_EN_SHIFT           	14

// SPK_CON1
#define SPK_PFD_MODE_OFFSET				CON1_OFFSET
#define SPK_PFD_MODE_MASK              	0x0001
#define SPK_PFD_MODE_SHIFT             	0

#define SPK_CMODE_OFFSET				CON1_OFFSET
#define SPK_CMODE_MASK              	0x000C
#define SPK_CMODE_SHIFT             	2

#define SPK_CCODE_OFFSET				CON1_OFFSET  
#define SPK_CCODE_MASK            		0x00F0
#define SPK_CCODE_SHIFT           		4

// SPK_CON2
#define SPK_OC_THD_OFFSET         		CON2_OFFSET
#define SPK_OC_THD_MASK           		0x0030
#define SPK_OC_THD_SHIFT          		4

#define SPK_OC_WND_OFFSET				CON2_OFFSET
#define SPK_OC_WND_MASK           		0x00C0
#define SPK_OC_WND_SHIFT          		6

// SPK_CON3
#define SPK_OC_EN_OFFSET         		CON3_OFFSET
#define SPK_OC_EN_MASK           		0x0400
#define SPK_OC_EN_SHIFT          		10


// SPK_CON5
#define SPK_PG_SLEW_I_OFFSET         	CON5_OFFSET
#define SPK_PG_SLEW_I_MASK           	0x3000
#define SPK_PG_SLEW_I_SHIFT          	12

// SPK_CON7
#define SPKMODE_OFFSET					CON7_OFFSET
#define SPKMODE_MASK           			0x0001
#define SPKMODE_SHIFT          			0

#define SPKAB_OBIAS_OFFSET				CON7_OFFSET
#define SPKAB_OBIAS_MASK           		0x0030
#define SPKAB_OBIAS_SHIFT          		4

#define SPKAB_OC_EN_OFFSET				CON7_OFFSET
#define SPKAB_OC_EN_MASK           		0x0010
#define SPKAB_OC_EN_SHIFT          	    8

// SPK_CON8
#define SPK_CALIBR_EN_OFFSET			CON8_OFFSET
#define SPK_CALIBR_EN_MASK           	0x0040
#define SPK_CALIBR_EN_SHIFT          	6

#define SPK_CALIBR_SEL_OFFSET			CON8_OFFSET
#define SPK_CALIBR_SEL_MASK           	0x0200
#define SPK_CALIBR_SEL_SHIFT          	9

// PMIC_OC
// PMIC_OC_CON0
#define VRF_OC_INT_EN_OFFSET			CON0_OFFSET
#define VRF_OC_INT_EN_MASK           	0x0001
#define VRF_OC_INT_EN_SHIFT          	0

#define VTCXO_OC_INT_EN_OFFSET			CON0_OFFSET
#define VTCXO_OC_INT_EN_MASK           	0x0002
#define VTCXO_OC_INT_EN_SHIFT          	1

#define VA_OC_INT_EN_OFFSET			    CON0_OFFSET
#define VA_OC_INT_EN_MASK           	0x0004
#define VA_OC_INT_EN_SHIFT          	2

#define VCAMA_OC_INT_EN_OFFSET			CON0_OFFSET
#define VCAMA_OC_INT_EN_MASK           	0x0008
#define VCAMA_OC_INT_EN_SHIFT          	3

#define VCAMD_OC_INT_EN_OFFSET			CON0_OFFSET
#define VCAMD_OC_INT_EN_MASK           	0x0010
#define VCAMD_OC_INT_EN_SHIFT          	4

#define VIO28_OC_INT_EN_OFFSET			CON0_OFFSET
#define VIO28_OC_INT_EN_MASK           	0x0020
#define VIO28_OC_INT_EN_SHIFT          	5

#define VUSB_OC_INT_EN_OFFSET			CON0_OFFSET
#define VUSB_OC_INT_EN_MASK           	0x0040
#define VUSB_OC_INT_EN_SHIFT          	6

#define VBT_OC_INT_EN_OFFSET			CON0_OFFSET
#define VBT_OC_INT_EN_MASK           	0x0080
#define VBT_OC_INT_EN_SHIFT          	7

#define VSIM_OC_INT_EN_OFFSET			CON0_OFFSET
#define VSIM_OC_INT_EN_MASK           	0x0100
#define VSIM_OC_INT_EN_SHIFT          	8

#define VSIM2_OC_INT_EN_OFFSET			CON0_OFFSET
#define VSIM2_OC_INT_EN_MASK           	0x0200
#define VSIM2_OC_INT_EN_SHIFT          	9

#define VRTC_OC_INT_EN_OFFSET			CON0_OFFSET
#define VRTC_OC_INT_EN_MASK           	0x0400
#define VRTC_OC_INT_EN_SHIFT          	10

#define VIBR_OC_INT_EN_OFFSET			CON0_OFFSET
#define VIBR_OC_INT_EN_MASK           	0x0800
#define VIBR_OC_INT_EN_SHIFT          	11

#define VMC_OC_INT_EN_OFFSET			CON0_OFFSET
#define VMC_OC_INT_EN_MASK           	0x1000
#define VMC_OC_INT_EN_SHIFT          	12

// PMIC_OC_CON1
#define VCORE_OC_INT_EN_OFFSET			CON1_OFFSET
#define VCORE_OC_INT_EN_MASK           	0x0001
#define VCORE_OC_INT_EN_SHIFT          	0

#define VIO18_OC_INT_EN_OFFSET			CON1_OFFSET
#define VIO18_OC_INT_EN_MASK           	0x0002
#define VIO18_OC_INT_EN_SHIFT          	1

// PMIC_OC_CON3
#define SPK_OC_INT_EN_OFFSET			CON3_OFFSET
#define SPK_OC_INT_EN_MASK           	0x0001
#define SPK_OC_INT_EN_SHIFT          	0

// PMIC_OC_CON4
#define VRF_OC_FLAG_OFFSET			    CON4_OFFSET
#define VRF_OC_FLAG_MASK           	    0x0001
#define VRF_OC_FLAG_SHIFT          	    0

#define VTCXO_OC_FLAG_OFFSET			CON4_OFFSET
#define VTCXO_OC_FLAG_MASK           	0x0002
#define VTCXO_OC_FLAG_SHIFT          	1

#define VA_OC_FLAG_OFFSET			    CON4_OFFSET
#define VA_OC_FLAG_MASK           	    0x0004
#define VA_OC_FLAG_SHIFT          	    2

#define VCAMA_OC_FLAG_OFFSET			CON4_OFFSET
#define VCAMA_OC_FLAG_MASK           	0x0008
#define VCAMA_OC_FLAG_SHIFT          	3

#define VCAMD_OC_FLAG_OFFSET			CON4_OFFSET
#define VCAMD_OC_FLAG_MASK           	0x0010
#define VCAMD_OC_FLAG_SHIFT          	4

#define VIO28_OC_FLAG_OFFSET			CON4_OFFSET
#define VIO28_OC_FLAG_MASK           	0x0020
#define VIO28_OC_FLAG_SHIFT          	5

#define VUSB_OC_FLAG_OFFSET			    CON4_OFFSET
#define VUSB_OC_FLAG_MASK           	0x0040
#define VUSB_OC_FLAG_SHIFT          	6

#define VBT_OC_FLAG_OFFSET			    CON4_OFFSET
#define VBT_OC_FLAG_MASK           	    0x0080
#define VBT_OC_FLAG_SHIFT           	7

#define VSIM_OC_FLAG_OFFSET			    CON4_OFFSET
#define VSIM_OC_FLAG_MASK           	0x0100
#define VSIM_OC_FLAG_SHIFT          	8

#define VSIM2_OC_FLAG_OFFSET			CON4_OFFSET
#define VSIM2_OC_FLAG_MASK           	0x0200
#define VSIM2_OC_FLAG_SHIFT          	9

#define VRTC_OC_FLAG_OFFSET			    CON4_OFFSET
#define VRTC_OC_FLAG_MASK           	0x0400
#define VRTC_OC_FLAG_SHIFT          	10

#define VIBR_OC_FLAG_OFFSET			    CON4_OFFSET
#define VIBR_OC_FLAG_MASK           	0x0800
#define VIBR_OC_FLAG_SHIFT          	11

#define VMC_OC_FLAG_OFFSET			    CON4_OFFSET
#define VMC_OC_FLAG_MASK           	    0x1000
#define VMC_OC_FLAG_SHIFT          	    12

// PMIC_OC_CON5
#define VCORE_OC_FLAG_OFFSET			CON5_OFFSET
#define VCORE_OC_FLAG_MASK           	0x0001
#define VCORE_OC_FLAG_SHIFT          	0

#define VIO18_OC_FLAG_OFFSET			CON5_OFFSET
#define VIO18_OC_FLAG_MASK           	0x0002
#define VIO18_OC_FLAG_SHIFT          	1

// PMIC_OC_CON7
#define SPK_OC_FLAG_OFFSET			    CON7_OFFSET
#define SPK_OC_FLAG_MASK            	0x0001
#define SPK_OC_FLAG_SHIFT          	    0

// PMIC_OC_CON8
#define VRF_OC_STATUS_OFFSET			CON8_OFFSET
#define VRF_OC_STATUS_MASK           	0x0001
#define VRF_OC_STATUS_SHIFT          	0

#define VTCXO_OC_STATUS_OFFSET			CON8_OFFSET
#define VTCXO_OC_STATUS_MASK           	0x0002
#define VTCXO_OC_STATUS_SHIFT          	1

#define VA_OC_STATUS_OFFSET			    CON8_OFFSET
#define VA_OC_STATUS_MASK           	0x0004
#define VA_OC_STATUS_SHIFT          	2

#define VCAMA_OC_STATUS_OFFSET			CON8_OFFSET
#define VCAMA_OC_STATUS_MASK           	0x0008
#define VCAMA_OC_STATUS_SHIFT          	3

#define VCAMD_OC_STATUS_OFFSET			CON8_OFFSET
#define VCAMD_OC_STATUS_MASK           	0x0010
#define VCAMD_OC_STATUS_SHIFT          	4

#define VIO28_OC_STATUS_OFFSET			CON8_OFFSET
#define VIO28_OC_STATUS_MASK           	0x0020
#define VIO28_OC_STATUS_SHIFT          	5

#define VUSB_OC_STATUS_OFFSET			CON8_OFFSET
#define VUSB_OC_STATUS_MASK           	0x0040
#define VUSB_OC_STATUS_SHIFT          	6

#define VBT_OC_STATUS_OFFSET			CON8_OFFSET
#define VBT_OC_STATUS_MASK           	0x0080
#define VBT_OC_STATUS_SHIFT           	7

#define VSIM_OC_STATUS_OFFSET			CON8_OFFSET
#define VSIM_OC_STATUS_MASK           	0x0100
#define VSIM_OC_STATUS_SHIFT          	8

#define VSIM2_OC_STATUS_OFFSET			CON8_OFFSET
#define VSIM2_OC_STATUS_MASK           	0x0200
#define VSIM2_OC_STATUS_SHIFT          	9

#define VRTC_OC_STATUS_OFFSET			CON8_OFFSET
#define VRTC_OC_STATUS_MASK           	0x0400
#define VRTC_OC_STATUS_SHIFT          	10

#define VIBR_OC_STATUS_OFFSET			CON8_OFFSET
#define VIBR_OC_STATUS_MASK           	0x0800
#define VIBR_OC_STATUS_SHIFT          	11

#define VMC_OC_STATUS_OFFSET			CON8_OFFSET
#define VMC_OC_STATUS_MASK           	0x1000
#define VMC_OC_STATUS_SHIFT          	12

// PMIC_OC_CON9
#define VCORE_OC_STATUS_OFFSET			CON9_OFFSET
#define VCORE_OC_STATUS_MASK           	0x0001
#define VCORE_OC_STATUS_SHIFT          	0

#define VIO18_OC_STATUS_OFFSET			CON9_OFFSET
#define VIO18_OC_STATUS_MASK           	0x0002
#define VIO18_OC_STATUS_SHIFT          	1

// PMIC_OC_CONB
#define SPK_OC_STATUS_OFFSET			CONB_OFFSET
#define SPK_OC_STATUS_MASK            	0x0001
#define SPK_OC_STATUS_SHIFT          	0

#endif // #if defined(PMIC_6256_REG_API)

#endif // #ifndef __PMU6256_HW_H__
