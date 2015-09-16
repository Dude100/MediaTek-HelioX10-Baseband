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
 *    dcl_pmu6329_hw.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for PMIC6329 H/W configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __DCL_PMIC6329_HW_H_STRUCT__
#define __DCL_PMIC6329_HW_H_STRUCT__


#include "dcl_pmic_features.h"

#if defined(PMIC_6329_REG_API)

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

#define PMIC6329_E1_CID_CODE				0x2900
#define PMIC6329_E2_CID_CODE				0x2910
                                    		
#define CID_1_REG_INDEX						0x0
#define CID_2_REG_INDEX						0x1

//#define PMIC_MAX_REG_IDX					0x96
//#define PMIC_REG_NUM						0x97	// ###***** PMIC_REG_NUM must equal (PMIC_MAX_REG_IDX + 1)
// Anderson Modify 20110331 Start
#define PMIC_BANK0_MAX_REG_IDX      		0xF7
#define PMIC_BANK0_REG_NUM          		(PMIC_BANK0_MAX_REG_IDX + 1)    // ###***** PMIC_BANK0_REG_NUM must equal (PMIC_BANK0_MAX_REG_IDX + 1)
#define PMIC_BANK1_MAX_REG_IDX      		0xA5
#define PMIC_BANK1_REG_NUM          		(PMIC_BANK1_MAX_REG_IDX + 1)    // ###***** PMIC_BANK1_REG_NUM must equal (PMIC_BANK1_MAX_REG_IDX + 1)

////////////////////////////////
/*      PMIC 6329 BANK 0      */
////////////////////////////////
// (0x00) CID0 (RO)
#define CID0_ADDR                           0x00

#define CID0_MASK               	        0xFF
#define CID0_MASK_SHIFT              	    0x0

// (0x01) CID1 (RO)
#define CID1_ADDR                           0x01

#define CID1_MASK               	        0xFF
#define CID01_MASK_SHIFT              	    0x0

// (0x02) STATUS0 (RO)
#define STATUS0_ADDR                        0x02

#define VCORE_STATUS_MASK               	0x1
#define VCORE_STATUS_SHIFT              	0x7
#define VPROC_STATUS_MASK               	0x1
#define VPROC_STATUS_SHIFT              	0x6
#define VIO18_STATUS_MASK               	0x1
#define VIO18_STATUS_SHIFT              	0x5
#define VRF18_STATUS_MASK               	0x1
#define VRF18_STATUS_SHIFT              	0x4
#define VPA_STATUS_MASK                 	0x1
#define VPA_STATUS_SHIFT                	0x3
#define VRF_STATUS_MASK                 	0x1
#define VRF_STATUS_SHIFT                	0x2
#define VTCXO_STATUS_MASK               	0x1
#define VTCXO_STATUS_SHIFT              	0x1
#define VA1_STATUS_MASK                 	0x1
#define VA1_STATUS_SHIFT                	0x0
                                        	
// (0x03) STATUS1 (RO)
#define STATUS1_ADDR                        0x03

#define VCAMA_STATUS_MASK               	0x1
#define VCAMA_STATUS_SHIFT              	0x7
#define VM12_1_STATUS_MASK              	0x1
#define VM12_1_STATUS_SHIFT             	0x6
#define VM12_INT_STATUS_MASK            	0x1
#define VM12_INT_STATUS_SHIFT           	0x5
#define VIO28_STATUS_MASK               	0x1
#define VIO28_STATUS_SHIFT              	0x4
#define VSIM1_STATUS_MASK               	0x1
#define VSIM1_STATUS_SHIFT              	0x3
#define VSIM2_STATUS_MASK               	0x1
#define VSIM2_STATUS_SHIFT              	0x2
#define VUSB_STATUS_MASK                	0x1
#define VUSB_STATUS_SHIFT               	0x1
#define VCAMD_STATUS_MASK               	0x1
#define VCAMD_STATUS_SHIFT              	0x0
                                        	
// (0x04) STATUS2 (RO)
#define STATUS2_ADDR                        0x04

#define VCAM_IO_STATUS_MASK	            	0x1	
#define VCAM_IO_STATUS_SHIFT	        	0x7
#define VCAM_AF_STATUS_MASK	            	0x1	
#define VCAM_AF_STATUS_SHIFT	        	0x6
#define VMC_STATUS_MASK	                	0x1	
#define VMC_STATUS_SHIFT	            	0x5
#define VMCH_STATUS_MASK	            	0x1	
#define VMCH_STATUS_SHIFT	            	0x4
#define VGP_STATUS_MASK	                	0x1	
#define VGP_STATUS_SHIFT	            	0x3
#define VGP2_STATUS_MASK	            	0x1	
#define VGP2_STATUS_SHIFT					0x2
#define VM12_2_STATUS_MASK					0x1	
#define VM12_2_STATUS_SHIFT					0x1
#define VIBR_STATUS_MASK					0x1	
#define VIBR_STATUS_SHIFT					0x0
                                        	
// (0x05) STATUS3 (RO)
#define STATUS3_ADDR                        0x05

#define VA2_STATUS_MASK						0x1	
#define VA2_STATUS_SHIFT					0x5
#define VRTC_STATUS_MASK					0x1	
#define VRTC_STATUS_SHIFT					0x4
#define VTCXO_PG_STATUS_MASK				0x1	
#define VTCXO_PG_STATUS_SHIFT				0x0
                                        	
// (0x06) PGSTATUS0 (RO)
#define PGSTATUS0_ADDR                      0x06

#define VCORE_PG_STATUS_MASK				0x1	
#define VCORE_PG_STATUS_SHIFT				0x7
#define VPROC_PG_STATUS_MASK				0x1	
#define VPROC_PG_STATUS_SHIFT				0x6
#define VIO18_PG_STATUS_MASK				0x1	
#define VIO18_PG_STATUS_SHIFT				0x5
#define VIO28_PG_STATUS_MASK				0x1	
#define VIO28_PG_STATUS_SHIFT				0x4
#define VA1_PG_STATUS_MASK					0x1	
#define VA1_PG_STATUS_SHIFT					0x3
#define VM12_1_PG_STATUS_MASK				0x1	
#define VM12_1_PG_STATUS_SHIFT				0x2
#define VM12_2_PG_STATUS_MASK				0x1	
#define VM12_2_PG_STATUS_SHIFT				0x1
#define VM12_INT_PG_STATUS_MASK				0x1	
#define VM12_INT_PG_STATUS_SHIFT			0x0
                                        	
// (0x07) RESERVERD                     	
                                        	
// (0x08) RESERVERD                     	
                                        	
// (0x09) CHRSATUS (RO)
#define CHRSTATUS_ADDR						0x09

#define CV_MASK								0x1	
#define CV_SHIFT							0x7
#define RO_BATON_UNDET_MASK					0x1	
#define RO_BATON_UNDET_SHIFT				0x6
#define PCHR_CHRDET_MASK					0x1	
#define PCHR_CHRDET_SHIFT					0x5
#define VBAT_OV_MASK						0x1	
#define VBAT_OV_SHIFT						0x4
#define PWRKEY_DEB_MASK						0x1	
#define PWRKEY_DEB_SHIFT					0x3
#define USBDL_MASK							0x1	
#define USBDL_SHIFT							0x2
#define TEST_MODE_POR_MASK					0x1	
#define TEST_MODE_POR_SHIFT					0x0
                            				
// (0x0A) OCSTATUS0 (RO)               
#define OCSTATUS0_ADDR						0x0A

#define VCAMA_OC_STATUS_MASK				0x1	
#define VCAMA_OC_STATUS_SHIFT				0x7
#define VM12_1_OC_STATUS_MASK				0x1	
#define VM12_1_OC_STATUS_SHIFT				0x6
#define VM12_OC_STATUS_MASK					0x1	
#define VM12_OC_STATUS_SHIFT				0x5
#define VIO28_OC_STATUS_MASK				0x1	
#define VIO28_OC_STATUS_SHIFT				0x4
#define VSIM1_OC_STATUS_MASK				0x1	
#define VSIM1_OC_STATUS_SHIFT				0x3
#define VSIM2_OC_STATUS_MASK				0x1	
#define VSIM2_OC_STATUS_SHIFT				0x2
#define VUSB_OC_STATUS_MASK					0x1	
#define VUSB_OC_STATUS_SHIFT				0x1
#define VCAMD_OC_STATUS_MASK				0x1	
#define VCAMD_OC_STATUS_SHIFT				0x0
                                        	
// (0x0B) OCSTATUS1 (RO)  
#define OCSTATUS1_ADDR						0x0B

#define VCAM_IO_OC_STATUS_MASK				0x1	
#define VCAM_IO_OC_STATUS_SHIFT				0x7
#define VCAM_AF_OC_STATUS_MASK				0x1	
#define VCAM_AF_OC_STATUS_SHIFT				0x6
#define VMC_OC_STATUS_MASK					0x1	
#define VMC_OC_STATUS_SHIFT					0x5
#define VMCH_OC_STATUS_MASK					0x1	
#define VMCH_OC_STATUS_SHIFT				0x4
#define VGP_OC_STATUS_MASK					0x1	
#define VGP_OC_STATUS_SHIFT					0x3
#define VGP2_OC_STATUS_MASK					0x1	
#define VGP2_OC_STATUS_SHIFT				0x2
#define VM12_2_OC_STATUS_MASK				0x1	
#define VM12_2_OC_STATUS_SHIFT				0x1
#define VIBR_OC_STATUS_MASK					0x1	
#define VIBR_OC_STATUS_SHIFT				0x0
                                        	
// (0x0C) OCSTATUS2 (RO) 
#define OCSTATUS2_ADDR						0x0C

#define HOMEKEY_DEB_MASK					0x1	
#define HOMEKEY_DEB_SHIFT					0x6
#define BOOST_OC_STATUS_MASK				0x1	
#define BOOST_OC_STATUS_SHIFT				0x5
#define VA2_OC_STATUS_MASK					0x1	
#define VA2_OC_STATUS_SHIFT					0x4
#define NI_SPK_OC_DET_D_R_MASK				0x1	
#define NI_SPK_OC_DET_D_R_SHIFT				0x3
#define NI_SPK_OC_DET_D_L_MASK				0x1	
#define NI_SPK_OC_DET_D_L_SHIFT				0x2
#define NI_SPK_OC_DET_AB_R_MASK				0x1	
#define NI_SPK_OC_DET_AB_R_SHIFT			0x1
#define NI_SPK_OC_DET_AB_L_MASK				0x1	
#define NI_SPK_OC_DET_AB_L_SHIFT			0x0
                                        	
// (0x0D) OCSTATUS3 (RO) 
#define OCSTATUS3_ADDR						0x0D

#define VCORE_OC_STATUS_MASK				0x1	
#define VCORE_OC_STATUS_SHIFT				0x7
#define VPROC_OC_STATUS_MASK				0x1	
#define VPROC_OC_STATUS_SHIFT				0x6
#define VIO18_OC_STATUS_MASK				0x1	
#define VIO18_OC_STATUS_SHIFT				0x5
#define VRF18_OC_STATUS_MASK				0x1	
#define VRF18_OC_STATUS_SHIFT				0x4
#define VPA_OC_STATUS_MASK					0x1
#define VPA_OC_STATUS_SHIFT					0x3
#define VRF_OC_STATUS_MASK					0x1	
#define VRF_OC_STATUS_SHIFT					0x2
#define VTCXO_OC_STATUS_MASK				0x1	
#define VTCXO_OC_STATUS_SHIFT				0x1
#define VA1_OC_STATUS_MASK					0x1	
#define VA1_OC_STATUS_SHIFT					0x0
                                        	
// (0x0E) STRUP_CTRL1 (RW)  
#define STRUP_CTRL1_ADDR 					0x0E

#define RG_THRDET_SEL_MASK	            	0x1	
#define RG_THRDET_SEL_SHIFT	            	0x6
#define RG_THR_HWPDN_EN_MASK	        	0x1	
#define RG_THR_HWPDN_EN_SHIFT	        	0x5
#define RG_STRUP_THR_SEL_MASK	        	0x3	
#define RG_STRUP_THR_SEL_SHIFT	        	0x3
#define RG_THR_TMODE_MASK	            	0x1	
#define RG_THR_TMODE_SHIFT	            	0x1
#define RG_FORCE_NON_THERMAL_MASK	    	0x1	
#define RG_FORCE_NON_THERMAL_SHIFT	    	0x0
                                        	
// (0x0F) STRUP_CTRL2 (RW)   
#define STRUP_CTRL2_ADDR 					0x0F

#define RG_VREF_BG_MASK	                	0x7	
#define RG_VREF_BG_SHIFT	            	0x4
#define RG_STRUP_IREF_TRIM_MASK	        	0xF	
#define RG_STRUP_IREF_TRIM_SHIFT	    	0x0
                                        	
// (0x10) STRUP_CTRL3 (RW)        
#define STRUP_CTRL3_ADDR 					0x10

#define RG_BB_PROC_SEL_MASK					0x1	
#define RG_BB_PROC_SEL_SHIFT				0x7
#define RG_STRUP_RST_DRVSEL_MASK			0x1	
#define RG_STRUP_RST_DRVSEL_SHIFT			0x6
#define RG_PMU_LEV_UNGATE_MASK				0x1	
#define RG_PMU_LEV_UNGATE_SHIFT				0x1
#define RG_USBDL_EN_MASK					0x1	
#define RG_USBDL_EN_SHIFT					0x0
                                        	
// (0x11) STRUP_RSV1 (RW)         
#define STRUP_RSV1_ADDR 					0x11

#define RG_PMU_RSV_MASK	                	0xF	
#define RG_PMU_RSV_SHIFT	            	0x4
                                        	
// (0x12) STRUP_TST_CTL (RW)      
#define STRUP_TST_CTL_ADDR 					0x12

#define RG_BIAS_GEN_EN_FORCE_MASK			0x1	
#define RG_BIAS_GEN_EN_FORCE_SHIFT			0x5
#define RG_STRUP_PWRON_FORCE_MASK			0x1	
#define RG_STRUP_PWRON_FORCE_SHIFT			0x4
#define RG_STRUP_TEST_MASK					0x1	
#define RG_STRUP_TEST_SHIFT					0x3
#define RG_STRUP_FT_CTRL_MASK				0x3	
#define RG_STRUP_FT_CTRL_SHIFT				0x0
                                        	
// (0x13) STRUP_THR_CTL (RO/RW)         
#define STRUP_THR_CTL_ADDR 					0x13

#define PMU_THR_STATUS_MASK	   				0x7	
#define PMU_THR_STATUS_SHIFT				0x4
#define RG_THERMAL_TEST_MASK				0x3	
#define RG_THERMAL_TEST_SHIFT				0x2
                                        	
// (0x14) STRUP_VPG_EN1 (RW)  
#define STRUP_VPG_EN1_ADDR 					0x14

#define RG_VCORE_PG_ENB_MASK				0x1	
#define RG_VCORE_PG_ENB_SHIFT				0x7
#define RG_VPROC_PG_ENB_MASK				0x1	
#define RG_VPROC_PG_ENB_SHIFT				0x6
#define RG_VIO18_PG_ENB_MASK				0x1	
#define RG_VIO18_PG_ENB_SHIFT				0x5
#define RG_VIO28_PG_ENB_MASK				0x1	
#define RG_VIO28_PG_ENB_SHIFT				0x4
#define RG_VA1_PG_ENB_MASK	    			0x1	
#define RG_VA1_PG_ENB_SHIFT	    			0x3
#define RG_VM12_1_PG_ENB_MASK				0x1	
#define RG_VM12_1_PG_ENB_SHIFT				0x2
#define RG_VM12_2_PG_ENB_MASK				0x1	
#define RG_VM12_2_PG_ENB_SHIFT				0x1
#define RG_VM12_INT_PG_ENB_MASK				0x1	
#define RG_VM12_INT_PG_ENB_SHIFT			0x0
                                        	
// (0x15) STRUP_VPG_EN2 (RW)           
#define STRUP_VPG_EN2_ADDR 					0x15

#define RG_STRUP_DIG_RSV_MASK				0xF	
#define RG_STRUP_DIG_RSV_SHIFT				0x4
#define RG_VTCXO_PG_ENB_MASK				0x1	
#define RG_VTCXO_PG_ENB_SHIFT				0x0
                                        	
// (0x16) INT_CON0 (RW)              
#define INT_CON0_ADDR 						0x16 

#define RG_OV_INT_EN_MASK					0x1	
#define RG_OV_INT_EN_SHIFT					0x7
#define RG_CHRDET_INT_EN_MASK				0x1	
#define RG_CHRDET_INT_EN_SHIFT				0x6
#define RG_BVALID_DET_INT_EN_MASK			0x1
#define RG_BVALID_DET_INT_EN_SHIFT			0x5
#define RG_VBATON_UNDET_INT_EN_MASK			0x1	
#define RG_VBATON_UNDET_INT_EN_SHIFT		0x4
#define RG_THR_H_INT_EN_MASK				0x1	
#define RG_THR_H_INT_EN_SHIFT				0x3
#define RG_THR_L_INT_EN_MASK				0x1	
#define RG_THR_L_INT_EN_SHIFT				0x2
#define RG_PWRKEY_INT_EN_MASK				0x1	
#define RG_PWRKEY_INT_EN_SHIFT				0x1
#define RG_WATCHDOG_INT_EN_MASK				0x1	
#define RG_WATCHDOG_INT_EN_SHIFT			0x0
                                        	
// (0x17) INT_CON1 (RW)     
#define INT_CON1_ADDR 						0x17

#define RG_FG_BAT_H_INT_EN_MASK				0x1	
#define RG_FG_BAT_H_INT_EN_SHIFT			0x7
#define RG_FG_BAT_L_INT_EN_MASK				0x1	
#define RG_FG_BAT_L_INT_EN_SHIFT			0x6
#define RG_HIGH_BAT_INT_EN_MASK				0x1	
#define RG_HIGH_BAT_INT_EN_SHIFT			0x5
#define RG_LOW_BAT_INT_EN_MASK				0x1	
#define RG_LOW_BAT_INT_EN_SHIFT				0x4
#define RG_SPKR_D_OC_INT_EN_MASK			0x1
#define RG_SPKR_D_OC_INT_EN_SHIFT			0x3
#define RG_SPKL_D_OC_INT_EN_MASK			0x1	
#define RG_SPKL_D_OC_INT_EN_SHIFT			0x2
#define RG_SPKR_AB_OC_INT_EN_MASK			0x1	
#define RG_SPKR_AB_OC_INT_EN_SHIFT			0x1
#define RG_SPKL_AB_OC_INT_EN_MASK			0x1	
#define RG_SPKL_AB_OC_INT_EN_SHIFT			0x0
                                        	
// (0x18) INT_CON2 (RW)      
#define INT_CON2_ADDR 						0x18

#define RG_HOMEKEY_INT_EN_MASK				0x1	
#define RG_HOMEKEY_INT_EN_SHIFT				0x5
#define RG_VRF18_OC_INT_EN_MASK				0x1
#define RG_VRF18_OC_INT_EN_SHIFT			0x4
#define RG_VPA_OC_INT_EN_MASK				0x1	
#define RG_VPA_OC_INT_EN_SHIFT				0x3
#define RG_LDO_OC_INT_EN_MASK				0x1	
#define RG_LDO_OC_INT_EN_SHIFT				0x2
                                	    	
// (0x19) INT_STATUS5 (RO)    
#define INT_STATUS5_ADDR 					0x19

#define RG_OV_INT_STATUS_MASK				0x1	
#define RG_OV_INT_STATUS_SHIFT				0x7
#define RG_CHRDET_INT_STATUS_MASK			0x1	
#define RG_CHRDET_INT_STATUS_SHIFT			0x6
#define RG_BVALID_DET_INT_STATUS_MASK		0x1	
#define RG_BVALID_DET_INT_STATUS_SHIFT		0x5
#define RG_VBATON_UNDET_INT_STATUS_MASK		0x1	
#define RG_VBATON_UNDET_INT_STATUS_SHIFT	0x4
#define RG_THR_H_INT_STATUS_MASK			0x1	
#define RG_THR_H_INT_STATUS_SHIFT			0x3
#define RG_THR_L_INT_STATUS_MASK			0x1	
#define RG_THR_L_INT_STATUS_SHIFT			0x2
#define RG_PWRKEY_INT_STATUS_MASK			0x1	
#define RG_PWRKEY_INT_STATUS_SHIFT			0x1
#define RG_WATCHDOG_INT_STATUS_MASK			0x1	
#define RG_WATCHDOG_INT_STATUS_SHIFT		0x0

// (0x1A) INT_STATUS6 (RO)
#define INT_STATUS6_ADDR 					0x1A

#define RG_FG_BAT_H_INT_STATUS_MASK			0x1	
#define RG_FG_BAT_H_INT_STATUS_SHIFT		0x7
#define RG_FG_BAT_L_INT_STATUS_MASK			0x1	
#define RG_FG_BAT_L_INT_STATUS_SHIFT		0x6
#define RG_HIGH_BAT_INT_STATUS_MASK			0x1	
#define RG_HIGH_BAT_INT_STATUS_SHIFT		0x5
#define RG_LOW_BAT_INT_STATUS_MASK			0x1	
#define RG_LOW_BAT_INT_STATUS_SHIFT			0x4
#define RG_SPKR_D_OC_INT_STATUS_MASK		0x1	
#define RG_SPKR_D_OC_INT_STATUS_SHIFT		0x3
#define RG_SPKL_D_OC_INT_STATUS_MASK		0x1	
#define RG_SPKL_D_OC_INT_STATUS_SHIFT		0x2
#define RG_SPKR_AB_OC_INT_STATUS_MASK		0x1	
#define RG_SPKR_AB_OC_INT_STATUS_SHIFT		0x1
#define RG_SPKL_AB_OC_INT_STATUS_MASK		0x1	
#define RG_SPKL_AB_OC_INT_STATUS_SHIFT		0x0

// (0x1B) INT_STATUS7 (RO)
#define INT_STATUS7_ADDR 					0x1B

#define RG_HOMEKEY_INT_STATUS_MASK			0x1	
#define RG_HOMEKEY_INT_STATUS_SHIFT			0x5
#define RG_VRF18_OC_INT_STATUS_MASK			0x1	
#define RG_VRF18_OC_INT_STATUS_SHIFT		0x4
#define RG_VPA_OC_INT_STATUS_MASK			0x1	
#define RG_VPA_OC_INT_STATUS_SHIFT			0x3
#define RG_LDO_OC_INT_STATUS_MASK			0x1	
#define RG_LDO_OC_INT_STATUS_SHIFT			0x2

// (0x21) CHR_CON0 (RO/RW)
#define CHR_CON0_ADDR 						0x21

#define VCDT_HV_DET_MASK					0x1	
#define VCDT_HV_DET_SHIFT					0x7
#define VCDT_LV_DET_MASK					0x1	
#define VCDT_LV_DET_SHIFT					0x6
#define CHRDET_MASK							0x1	
#define CHRDET_SHIFT						0x5
#define CHR_EN_MASK							0x1	
#define CHR_EN_SHIFT						0x4
#define CSDAC_EN_MASK						0x1	
#define CSDAC_EN_SHIFT						0x3
#define PCHR_AUTO_MASK						0x1	
#define PCHR_AUTO_SHIFT						0x2
#define CHR_LDO_DET_MASK					0x1	
#define CHR_LDO_DET_SHIFT					0x1
#define VCDT_HV_EN_MASK						0x1	
#define VCDT_HV_EN_SHIFT					0x0

// (0x22) CHR_CON1 (RW)
#define CHR_CON1_ADDR 						0x22

#define VCDT_HV_VTH_MASK					0xF
#define VCDT_HV_VTH_SHIFT					0x4
#define VCDT_LV_VTH_MASK					0xF	
#define VCDT_LV_VTH_SHIFT					0x0

// (0x23) CHR_CON2 (RO/RW)
#define CHR_CON2_ADDR 						0x23

#define VBAT_CC_DET_MASK					0x1	
#define VBAT_CC_DET_SHIFT					0x7
#define VBAT_CV_DET_MASK					0x1	
#define VBAT_CV_DET_SHIFT					0x6
#define CS_DET_MASK							0x1	
#define CS_DET_SHIFT						0x5
#define CS_EN_MASK							0x1	
#define CS_EN_SHIFT							0x3
#define VBAT_CC_EN_MASK						0x1	
#define VBAT_CC_EN_SHIFT					0x2
#define VBAT_CV_EN_MASK						0x1	
#define VBAT_CV_EN_SHIFT					0x1

// (0x24) CHR_CON3 (RW)
#define CHR_CON3_ADDR 						0x24

#define VBAT_CC_VTH_MASK					0x3	
#define VBAT_CC_VTH_SHIFT					0x6
#define VBAT_CV_VTH_MASK					0x1F	
#define VBAT_CV_VTH_SHIFT					0x0

// (0x25) CHR_CON4 (RW)
#define CHR_CON4_ADDR 						0x25

#define CS_VTH_MASK							0xF	
#define CS_VTH_SHIFT						0x0

// (0x26) CHR_CON5 (RW)
#define CHR_CON5_ADDR 						0x26

#define TOLTC_MASK							0x7
#define TOLTC_SHIFT							0x4
#define TOHTC_MASK							0x7
#define TOHTC_SHIFT							0x0

// (0x27) CHR_CON6 (RO/RW)
#define CHR_CON6_ADDR 						0x27

#define VBAT_OV_DET_MASK					0x1
#define VBAT_OV_DET_SHIFT					0x6
#define VBAT_OV_DEG_MASK					0x1
#define VBAT_OV_DEG_SHIFT					0x5
#define VBAT_OV_VTH_MASK					0x3
#define VBAT_OV_VTH_SHIFT					0x1
#define VBAT_OV_EN_MASK						0x1	
#define VBAT_OV_EN_SHIFT					0x0

// (0x28) CHR_CON7 (RO/RW)
#define CHR_CON7_ADDR 						0x28

#define BATON_UNDET_MASK					0x1
#define BATON_UNDET_SHIFT					0x7
#define BATON_HT_TRIM_MASK					0x7	
#define BATON_HT_TRIM_SHIFT					0x4
#define BATON_HT_EN_MASK					0x1	
#define BATON_HT_EN_SHIFT					0x2
#define BATON_EN_MASK						0x1
#define BATON_EN_SHIFT						0x1

// (0x29) CHR_CON8 (RW)
#define CHR_CON8_ADDR 						0x29

#define CSDAC_DAT_H_MASK					0x3
#define CSDAC_DAT_H_SHIFT					0x0
                            				
// (0x2A) CHR_CON9 (RW)     	
#define CHR_CON9_ADDR 						0x2A

#define CSDAC_DAT_L_MASK					0xFF	
#define CSDAC_DAT_L_SHIFT					0x0

// (0x2B) CHR_CONA (RO/RW)
#define CHR_CONA_ADDR 						0x2B

#define OTG_BVALID_MASK						0x1	
#define OTG_BVALID_SHIFT					0x6
#define OTG_BVALID_EN_MASK					0x1	
#define OTG_BVALID_EN_SHIFT					0x5
#define PCHR_FLAG_EN_MASK					0x1
#define PCHR_FLAG_EN_SHIFT					0x4
#define PCHR_FLAG_OUT_MASK					0xF	
#define PCHR_FLAG_OUT_SHIFT					0x0

// (0x2C) CHR_CONB (RW)
#define CHR_CONB_ADDR 						0x2C

#define PCHR_FLAG_SEL_MASK					0x3F	
#define PCHR_FLAG_SEL_SHIFT					0x0

// (0x2D) CHR_CONC (RW)
#define CHR_CONC_ADDR 						0x2D

#define PCHR_FT_CTRL_MASK					0x7	
#define PCHR_FT_CTRL_SHIFT					0x4
#define PCHR_RST_MASK						0x1	
#define PCHR_RST_SHIFT						0x2
#define CSDAC_TEST_MASK						0x1	
#define CSDAC_TEST_SHIFT					0x1
#define PCHR_TEST_MASK						0x1	
#define PCHR_TEST_SHIFT						0x0

// (0x2E) CHR_COND (RW)
#define CHR_COND_ADDR 						0x2E

#define CHRWDT_EN_MASK						0x1	
#define CHRWDT_EN_SHIFT						0x4
#define CHRWDT_TD_MASK						0xF	
#define CHRWDT_TD_SHIFT						0x0
                        					
// (0x2F) CHR_CONE (RW) 
#define CHR_CONE_ADDR 						0x2F

#define PCHR_RV_MASK						0xFF	
#define PCHR_RV_SHIFT						0x0

// (0x30) CHR_CONF (RO/RW)
#define CHR_CONF_ADDR 						0x30

#define CHRWDT_OUT_MASK						0x1	
#define CHRWDT_OUT_SHIFT					0x2
#define CHRWDT_FLAG_WR_MASK					0x1	
#define CHRWDT_FLAG_WR_SHIFT				0x1
#define CHRWDT_INT_EN_MASK					0x1	
#define CHRWDT_INT_EN_SHIFT					0x0

// (0x31) CHR_CON11 (RW)
#define CHR_CON11_ADDR 						0x31

#define ADCIN_VCHR_EN_MASK					0x1
#define ADCIN_VCHR_EN_SHIFT					0x6
#define ADCIN_VSEN_EN_MASK					0x1
#define ADCIN_VSEN_EN_SHIFT					0x5
#define ADCIN_VBAT_EN_MASK					0x1	
#define ADCIN_VBAT_EN_SHIFT					0x4
#define USBDL_SET_MASK						0x1
#define USBDL_SET_SHIFT						0x3
#define USBDL_RST_MASK						0x1	
#define USBDL_RST_SHIFT						0x2
#define UVLO_VTHL_MASK						0x3	
#define UVLO_VTHL_SHIFT						0x0

// (0x32) CHR_CON12 (RW)
#define CHR_CON12_ADDR 						0x32

#define BGR_UNCHOP_MASK						0x1	
#define BGR_UNCHOP_SHIFT					0x5
#define BGR_UNCHOP_PH_MASK					0x1	
#define BGR_UNCHOP_PH_SHIFT					0x4
#define BGR_RSEL_MASK						0x7	
#define BGR_RSEL_SHIFT						0x0
                            				
// (0x33) CHR_CON13 (RO/RW) 				
#define BC11_CMP_OUT_MASK					0x1
#define BC11_CMP_OUT_SHIFT					0x7
#define RG_BC11_VSRC_EN_MASK				0x3	
#define RG_BC11_VSRC_EN_SHIFT				0x2
#define BC11_RST_MASK						0x1
#define BC11_RST_SHIFT						0x1
#define BC11_BB_CTRL_MASK					0x1
#define BC11_BB_CTRL_SHIFT					0x0
                                			
// (0x34) CHR_CON14 (RW)        			
#define BC11_BIAS_EN_MASK					0x1
#define BC11_BIAS_EN_SHIFT					0x7
#define BC11_IPU_EN_MASK					0x3	
#define BC11_IPU_EN_SHIFT					0x5
#define BC11_IPD_EN_MASK					0x3
#define BC11_IPD_EN_SHIFT					0x3
#define BC11_CMP_EN_MASK					0x3
#define BC11_CMP_EN_SHIFT					0x1
#define BC11_VREF_VTH_MASK					0x1	
#define BC11_VREF_VTH_SHIFT					0x0

// (0x35) CHR_CON15 (RW)
#define CSDAC_STP_DEC_MASK					0x7	
#define CSDAC_STP_DEC_SHIFT					0x4
#define CSDAC_STP_INC_MASK					0x7	
#define CSDAC_STP_INC_SHIFT					0x0
                            				
// (0x36) CHR_CON16 (RW)    				
#define CSDAC_STP_MASK						0x7	
#define CSDAC_STP_SHIFT						0x4
#define CSDAC_DLY_MASK						0x7	
#define CSDAC_DLY_SHIFT						0x0
                                			
// (0x37) CHR_CON17 (RW)        			
#define RG_CHRIND_DIMMING_MASK				0x1	
#define RG_CHRIND_DIMMING_SHIFT				0x7
#define RG_CHRIND_ON_MASK					0x1
#define RG_CHRIND_ON_SHIFT					0x6
#define RG_LOW_ICH_DB_MASK					0x3F	
#define RG_LOW_ICH_DB_SHIFT					0x0
                            				
// (0x38) CHR_CON18 (RW)    				
#define RG_ULC_DET_EN_MASK					0x1	
#define RG_ULC_DET_EN_SHIFT					0x7
#define RG_HWCV_EN_MASK						0x1	
#define RG_HWCV_EN_SHIFT					0x6
#define BATON_TDET_EN_MASK					0x1	
#define BATON_TDET_EN_SHIFT					0x5
#define TRACKING_EN_MASK					0x1	
#define TRACKING_EN_SHIFT					0x4
#define CSDAC_MODE_MASK						0x1
#define CSDAC_MODE_SHIFT					0x2
#define VCDT_MODE_MASK						0x1
#define VCDT_MODE_SHIFT						0x1
#define CV_MODE_MASK						0x1
#define CV_MODE_SHIFT						0x0

// (0x39) CHR_CON19 (RW)
#define RG_ICHRG_TRIM_MASK					0xF	
#define RG_ICHRG_TRIM_SHIFT					0x4
#define RG_BGR_TRIM_EN_MASK					0x1	
#define RG_BGR_TRIM_EN_SHIFT				0x0
                                			
// (0x3A) CHR_CON1A (RW)        			
#define RG_BGR_TRIM_MASK					0x1F
#define RG_BGR_TRIM_SHIFT					0x0
                            				
// (0x3B) CHR_CON1B (RW)    				
#define RG_OVP_TRIM_MASK					0xF	
#define RG_OVP_TRIM_SHIFT					0x0

// (0x3C) CHR_CON1C (RW)
#define CHR_RSV0_MASK						0x1	
#define CHR_RSV0_SHIFT						0x7
#define RG_BGR_TEST_RSTB_MASK				0x1	
#define RG_BGR_TEST_RSTB_SHIFT				0x6
#define RG_BGR_TEST_EN_MASK					0x1
#define RG_BGR_TEST_EN_SHIFT				0x5
#define RG_CHR_OSC_TRIM_MASK				0x1F
#define RG_CHR_OSC_TRIM_SHIFT				0x0

// (0x3D) CHR_CON1D (RW)
#define CHR_RSV1_MASK						0x3F	
#define CHR_RSV1_SHIFT						0x2
#define RG_DAC_USBDL_MAX_9_8_MASK			0x3
#define RG_DAC_USBDL_MAX_9_8_SHIFT			0x0
                                    		
// (0x3E) CHR_CON1E (RW)            		
#define RG_DAC_USBDL_MAX_7_0_MASK			0xFF
#define RG_DAC_USBDL_MAX_7_0_SHIFT			0x0

// (0x3F) VPROC_CON0 (RW)
#define RG_VPROC_CSL_MASK					0x3
#define RG_VPROC_CSL_SHIFT					0x6
#define RG_VPROC_CSR_MASK					0x3	
#define RG_VPROC_CSR_SHIFT					0x4
#define RG_VPROC_CC_MASK					0x3	
#define RG_VPROC_CC_SHIFT					0x2
#define RG_VPROC_RZSEL_MASK					0x3	
#define RG_VPROC_RZSEL_SHIFT				0x0
                                			
// (0x40) VPROC_CON1 (RW)       			
#define RG_VPROC_SLP_MASK					0x3	
#define RG_VPROC_SLP_SHIFT					0x6
#define RG_VPROC_ZX_OS_MASK					0x3
#define RG_VPROC_ZX_OS_SHIFT				0x4
#define RG_VPROC_SLEW_MASK					0x3	
#define RG_VPROC_SLEW_SHIFT					0x2
#define RG_VPROC_SLEW_NMOS_MASK				0x3	
#define RG_VPROC_SLEW_NMOS_SHIFT			0x0

// (0x41) VPROC_CON2 (RW)
#define RG_VPROC_AVP_OS_MASK				0x7	
#define RG_VPROC_AVP_OS_SHIFT				0x4
#define RG_VPROC_AVP_EN_MASK				0x1
#define RG_VPROC_AVP_EN_SHIFT				0x1
#define RG_VPROC_MODESET_MASK				0x1
#define RG_VPROC_MODESET_SHIFT				0x0
                                			
// (0x42) VPROC_CON3 (RO/RW)    			
#define VPROC_CON3_ADDR 					0x42

#define QI_VPROC_EN_MASK					0x1	
#define QI_VPROC_EN_SHIFT					0x7
#define RG_VPROC_EN_MASK					0x1	
#define RG_VPROC_EN_SHIFT					0x0
                                			
// (0x43) VPROC_CON4 (RW)       			
#define RG_VPROC_BURST_MASK					0x3	
#define RG_VPROC_BURST_SHIFT				0x4
#define RG_VPROC_VFBADJ_MASK				0x7	
#define RG_VPROC_VFBADJ_SHIFT				0x1
#define RG_VPROC_NDIS_EN_MASK				0x1	
#define RG_VPROC_NDIS_EN_SHIFT				0x0
                                			
// (0x44) VPROC_CON5 (RW)     
#define VPROC_CON5_ADDR 					0x44

#define RG_VPROC_VOSEL_MASK					0x1F
#define RG_VPROC_VOSEL_SHIFT				0x0
                                    		
// (0x45) VPROC_CON6 (RW)           		
#define VPROC_VOSEL_SRCLKEN0_MASK			0x1F	
#define VPROC_VOSEL_SRCLKEN0_SHIFT			0x0

// (0x46) VPROC_CON7 (RW)
#define VPROC_VOSEL_SRCLKEN1_MASK			0x1F
#define VPROC_VOSEL_SRCLKEN1_SHIFT			0x0
                                   	
// (0x47) VPROC_CON8 (RW)
#define VPROC_VOSEL_DVS00_MASK				0x1F	
#define VPROC_VOSEL_DVS00_SHIFT				0x0
                                			
// (0x48) VPROC_CON9 (RW)       			
#define VPROC_VOSEL_DVS01_MASK				0x1F	
#define VPROC_VOSEL_DVS01_SHIFT				0x0
                                			
// (0x49) VPROC_CONA (RW)       			
#define VPROC_VOSEL_DVS10_MASK				0x1F	
#define VPROC_VOSEL_DVS10_SHIFT				0x0

// (0x4A) VPROC_CONB (RW)
#define VPROC_VOSEL_DVS11_MASK				0x1F	
#define VPROC_VOSEL_DVS11_SHIFT				0x0

// (0x4B) VPROC_CONC (RW)
#define RG_VPROC_RSV_MASK					0xF	
#define RG_VPROC_RSV_SHIFT					0x4
#define RG_VPROC_VOSEL_SFCHG_EN_MASK		0x1	
#define RG_VPROC_VOSEL_SFCHG_EN_SHIFT		0x2
#define RG_VPROC_CTRL_MASK					0x3	
#define RG_VPROC_CTRL_SHIFT					0x0

// (0x4C) VPROC_COND (RW)
#define RG_SMPS_TESTMODE_MASK				0x3F
#define RG_SMPS_TESTMODE_SHIFT				0x0

// (0x4D) VPROC_CONE (RW)
#define RG_SMPS_RSV_MASK					0xFF	
#define RG_SMPS_RSV_SHIFT					0x0
                            				
// (0x4E) VPROC_CONF (RO)   				
#define QI_VPROC_VOSEL_MASK					0x1F	
#define QI_VPROC_VOSEL_SHIFT				0x0

// (0x4F) BUCK_RSV (RW)
#define RG_BUCK_RSV_MASK					0xFF	
#define RG_BUCK_RSV_SHIFT					0x0
                            				
// (0x52) VCORE_CON0 (RW)   				
#define RG_VCORE_CSL_MASK					0x3
#define RG_VCORE_CSL_SHIFT					0x6
#define RG_VCORE_CSR_MASK					0x3	
#define RG_VCORE_CSR_SHIFT					0x4
#define RG_VCORE_CC_MASK					0x3	
#define RG_VCORE_CC_SHIFT					0x2
#define RG_VCORE_RZSEL_MASK					0x3	
#define RG_VCORE_RZSEL_SHIFT				0x0

// (0x53) VCORE_CON1 (RW)
#define RG_VCORE_SLP_MASK					0x3	
#define RG_VCORE_SLP_SHIFT					0x6
#define RG_VCORE_ZX_OS_MASK					0x3	
#define RG_VCORE_ZX_OS_SHIFT				0x4
#define RG_VCORE_SLEW_MASK					0x3	
#define RG_VCORE_SLEW_SHIFT					0x2
#define RG_VCORE_SLEW_NMOS_MASK				0x3	
#define RG_VCORE_SLEW_NMOS_SHIFT			0x0

// (0x54) VCORE_CON2 (RW)
#define RG_VCORE_AVP_OS_MASK				0x7	
#define RG_VCORE_AVP_OS_SHIFT				0x4
#define RG_VCORE_AVP_EN_MASK				0x1	
#define RG_VCORE_AVP_EN_SHIFT				0x1
#define RG_VCORE_MODESET_MASK				0x1	
#define RG_VCORE_MODESET_SHIFT				0x0

// (0x55) VCORE_CON3 (RO/RW)
#define VCORE_CON3_ADDR 					0x55

#define QI_VCORE_EN_MASK					0x1
#define QI_VCORE_EN_SHIFT					0x7
#define RG_VCORE_EN_MASK					0x1
#define RG_VCORE_EN_SHIFT					0x0

// (0x56) VCORE_CON4 (RW)
#define RG_VCORE_BURST_MASK					0x3	
#define RG_VCORE_BURST_SHIFT				0x4
#define RG_VCORE_VFBADJ_MASK				0x7	
#define RG_VCORE_VFBADJ_SHIFT				0x1
#define RG_VCORE_NDIS_EN_MASK				0x1	
#define RG_VCORE_NDIS_EN_SHIFT				0x0
                                			
// (0x57) VCORE_CON5 (RW)
#define VCORE_CON5_ADDR 					0x57

#define RG_VCORE_VOSEL_MASK					0x1F	
#define RG_VCORE_VOSEL_SHIFT				0x0

// (0x58) VCORE_CON6 (RW)
#define RG_VCORE_VOSEL_CON1_MASK			0x1F	
#define RG_VCORE_VOSEL_CON1_SHIFT			0x0

// (0x59) VCORE_CON7 (RW)
#define RG_VCORE_RSV_MASK					0xF	
#define RG_VCORE_RSV_SHIFT					0x4
#define RG_VCORE_VOSEL_SFCHG_EN_MASK		0x1	
#define RG_VCORE_VOSEL_SFCHG_EN_SHIFT		0x2
#define RG_VCORE_CTRL_MASK					0x1	
#define RG_VCORE_CTRL_SHIFT					0x0

// (0x5A) VCORE_CON8 (RO)
#define QI_VCORE_VOSEL_MASK					0x1F
#define QI_VCORE_VOSEL_SHIFT				0x0

// (0x5D) VRF18_CON0 (RW)
#define RG_VRF18_CSL_MASK					0x3	
#define RG_VRF18_CSL_SHIFT					0x6
#define RG_VRF18_CSR_MASK					0x3	
#define RG_VRF18_CSR_SHIFT					0x4
#define RG_VRF18_CC_MASK					0x3	
#define RG_VRF18_CC_SHIFT					0x2
#define RG_VRF18_RZSEL_MASK					0x3	
#define RG_VRF18_RZSEL_SHIFT				0x0

// (0x5E) VRF18_CON1 (RW)
#define RG_VRF18_SLP_MASK					0x3	
#define RG_VRF18_SLP_SHIFT					0x6
#define RG_VRF18_ZX_OS_MASK					0x3	
#define RG_VRF18_ZX_OS_SHIFT				0x4
#define RG_VRF18_SLEW_MASK					0x3	
#define RG_VRF18_SLEW_SHIFT					0x2
#define RG_VRF18_SLEW_NMOS_MASK				0x3	
#define RG_VRF18_SLEW_NMOS_SHIFT			0x0

// (0x5F) VRF18_CON2 (RW)
#define VRF18_CON2_ADDR 					0x5F

#define RG_VRF18_AVP_EN_MASK				0x1
#define RG_VRF18_AVP_EN_SHIFT				0x1
#define RG_VRF18_MODESET_MASK				0x1	
#define RG_VRF18_MODESET_SHIFT				0x0

// (0x60) VRF18_CON3 (RO/RW)
#define VRF18_CON3_ADDR 					0x60

#define QI_VRF18_EN_MASK					0x1	
#define QI_VRF18_EN_SHIFT					0x7
#define RG_VRF18_ON_CTRL_MASK				0x1
#define RG_VRF18_ON_CTRL_SHIFT				0x1
#define RG_VRF18_EN_MASK					0x1	
#define RG_VRF18_EN_SHIFT					0x0

// (0x61) VRF18_CON4 (RW)
#define RG_VRF18_STBTD_MASK					0x3	
#define RG_VRF18_STBTD_SHIFT				0x6
#define RG_VRF18_BURST_MASK					0x3	
#define RG_VRF18_BURST_SHIFT				0x4
#define RG_VRF18_OCFB_EN_MASK				0x1	
#define RG_VRF18_OCFB_EN_SHIFT				0x1
#define RG_VRF18_NDIS_EN_MASK				0x1
#define RG_VRF18_NDIS_EN_SHIFT				0x0
                                			
// (0x62) VRF18_CON5 (RW)   
#define VRF18_CON5_ADDR 					0x62
    			
#define RG_VRF18_VOSEL_MASK					0x1F	
#define RG_VRF18_VOSEL_SHIFT				0x0
                                			
// (0x63) VRF18_CON6 (RW)       			
#define RG_VRF18_RSV_MASK					0xF	
#define RG_VRF18_RSV_SHIFT					0x0
                                    		
// (0x62) VRF18_CON7 (RO)           		
#define RO_QI_VRF18_OC_STATUS_MASK			0x1
#define RO_QI_VRF18_OC_STATUS_SHIFT			0x0

// (0x67) VM_CON0 (RW)
#define RG_VIO18_CSL_MASK					0x3	
#define RG_VIO18_CSL_SHIFT					0x6
#define RG_VIO18_CSR_MASK					0x3	
#define RG_VIO18_CSR_SHIFT					0x4
#define RG_VIO18_CC_MASK					0x3
#define RG_VIO18_CC_SHIFT					0x2
#define RG_VIO18_RZSEL_MASK					0x3	
#define RG_VIO18_RZSEL_SHIFT				0x0
                                			
// (0x68) VM_CON1 (RW)          			
#define RG_VIO18_SLP_MASK					0x3	
#define RG_VIO18_SLP_SHIFT					0x6
#define RG_VIO18_ZX_OS_MASK					0x3
#define RG_VIO18_ZX_OS_SHIFT				0x4
#define RG_VIO18_SLEW_MASK					0x3
#define RG_VIO18_SLEW_SHIFT					0x2
#define RG_VIO18_SELW_NMOS_MASK				0x3	
#define RG_VIO18_SELW_NMOS_SHIFT			0x0

// (0x69) VM_CON2 (RW)
#define RG_VIO18_AVP_EN_MASK				0x1
#define RG_VIO18_AVP_EN_SHIFT				0x1
#define RG_VIO18_MODESET_MASK				0x1
#define RG_VIO18_MODESET_SHIFT				0x0
                                			
// (0x6A) VM_CON3 (RO/RW)       			
#define VM_CON3_ADDR 						0x6A

#define NI_VIO18_EN_MASK					0x1	
#define NI_VIO18_EN_SHIFT					0x7
#define RG_VIO18_EN_MASK					0x1
#define RG_VIO18_EN_SHIFT					0x0
                                			
// (0x6B) VM_CON4 (RW)          			
#define RG_VIO18_BURST_MASK					0x3
#define RG_VIO18_BURST_SHIFT				0x4
#define RG_VIO18_NDIS_EN_MASK				0x1	
#define RG_VIO18_NDIS_EN_SHIFT				0x0

// (0x6C) VM_CON5 (RW)
#define VM_CON5_ADDR 						0x6C

#define RG_VIO18_VOSEL_MASK					0x1F	
#define RG_VIO18_VOSEL_SHIFT				0x0
                                			
// (0x6D) VM_CON6 (RW)          			
#define RG_VIO18_RSV_MASK					0xF	
#define RG_VIO18_RSV_SHIFT					0x4
                                			
// (0x70) VPA_CON0 (RW)         			
#define RG_VPA_CSL_MASK						0x3	
#define RG_VPA_CSL_SHIFT					0x6
#define RG_VPA_CSR_MASK						0x3	
#define RG_VPA_CSR_SHIFT					0x4
#define RG_VPA_CC_MASK						0x3	
#define RG_VPA_CC_SHIFT						0x2
#define RG_VPA_RZSEL_MASK					0x3	
#define RG_VPA_RZSEL_SHIFT					0x0
                                			
// (0x71) VPA_CON1 (RW)         			
#define RG_VPA_SLP_MASK						0x3	
#define RG_VPA_SLP_SHIFT					0x6
#define RG_VPA_ZX_OS_MASK					0x3	
#define RG_VPA_ZX_OS_SHIFT					0x4
#define RG_VPA_SLEW_MASK					0x3	
#define RG_VPA_SLEW_SHIFT					0x2
#define RG_VPA_SLEW_NMOS_MASK				0x3
#define RG_VPA_SLEW_NMOS_SHIFT				0x0
                                			
// (0x72) VPA_CON2 (RW)         			
#define RG_VPA_AVP_EN_MASK					0x1 			
#define RG_VPA_AVP_EN_SHIFT					0x1 			
#define RG_VPA_MODESET_MASK					0x1				
#define RG_VPA_MODESET_SHIFT				0x0
                            				    			
// (0x73) VPA_CON3 (RW)     				    	
#define VPA_CON3_ADDR 						0x73
		
#define RG_VPA_EN_MASK						0x1 				    			
#define RG_VPA_EN_SHIFT						0x0 				    			
                            				    			
// (0x74) VPA_CON4 (RW)     				    			
#define RG_VPA_BURST_MASK					0x3				
#define RG_VPA_BURST_SHIFT					0x4 			
#define RG_VPA_NDIS_EN_MASK					0x1				
#define RG_VPA_NDIS_EN_SHIFT				0x0

// (0x75) VPA_CON5 (RW)                    
#define VPA_CON5_ADDR 						0x75

#define RG_VPA_VOSEL_MASK					0x1F	
#define RG_VPA_VOSEL_SHIFT					0x0
                            				                           				
// (0x76) VPA_CON6 (RW)     			
#define VPA_CON6_ADDR 						0x76
	
#define RG_PASEL_SET0_MASK					0x1F
#define RG_PASEL_SET0_SHIFT					0x0
                            				
// (0x77) VPA_CON7 (RW)     
#define VPA_CON7_ADDR 						0x77
				
#define RG_PASEL_SET1_MASK					0x1F
#define RG_PASEL_SET1_SHIFT					0x0
                            				
// (0x78) VPA_CON8 (RW)     	
#define VPA_CON8_ADDR 						0x78
			
#define RG_PASEL_SET2_MASK					0x1F
#define RG_PASEL_SET2_SHIFT					0x0

// (0x79) VPA_CON9 (RW)
#define VPA_CON9_ADDR 						0x79

#define RG_PASEL_SET3_MASK					0x1F	
#define RG_PASEL_SET3_SHIFT					0x0
                            				
// (0x7A) VPA_CONA (RW)     		
#define VPA_CONA_ADDR 						0x7A
		
#define RG_PASEL_SET4_MASK					0x1F
#define RG_PASEL_SET4_SHIFT					0x0
                            				
// (0x7B) VPA_CONB (RW)     	
#define VPA_CONB_ADDR 						0x7B
			
#define RG_PASEL_SET5_MASK					0x1F
#define RG_PASEL_SET5_SHIFT					0x0
                            				
// (0x7C) VPA_CONC (RW)     
#define VPA_CONC_ADDR 						0x7C
				
#define RG_PASEL_SET6_MASK					0x1F
#define RG_PASEL_SET6_SHIFT					0x0
                            				
// (0x7D) VPA_COND (RW)
#define VPA_COND_ADDR 						0x7D

#define RG_PASEL_SET7_MASK					0x1F
#define RG_PASEL_SET7_SHIFT					0x0
                            				
// (0x7E) VPA_CONE (RW)     		
#define VPA_CONE_ADDR 						0x7E
		
#define RG_VPA_RSV_MASK						0xF
#define RG_VPA_RSV_SHIFT					0x4
#define RG_VPA_CTRL_MASK					0x1
#define RG_VPA_CTRL_SHIFT					0x0
                            				
// (0x7F) VPA_CONF (RO)     				
#define QI_VPA_VOSEL_MASK					0x1F
#define QI_VPA_VOSEL_SHIFT					0x0

// (0x82) DIGLDO_CON0 (RW)
#define DIGLDO_CON0_ADDR 					0x82

#define RG_VM12_1_CAL_MASK					0xF	
#define RG_VM12_1_CAL_SHIFT					0x0
                            				
// (0x83) DIGLDO_CON1 (RO/RW)
#define DIGLDO_CON1_ADDR 					0x83

#define QI_VM12_1_EN_MASK					0x1	
#define QI_VM12_1_EN_SHIFT					0x7
#define VM12_1_EN_MASK						0x1	
#define VM12_1_EN_SHIFT						0x0

// (0x84) DIGLDO_CON2 (RW)
#define RG_VM12_1_STBTD_MASK				0x3
#define RG_VM12_1_STBTD_SHIFT				0x4
#define RG_VM12_1_OCFB_EN_MASK				0x1
#define RG_VM12_1_OCFB_EN_SHIFT				0x1
#define RG_VM12_1_NDIS_EN_MASK				0x1
#define RG_VM12_1_NDIS_EN_SHIFT				0x0

// (0x85) DIGLDO_CON3 (RO/RW)
#define QI_VM12_1_MODE_MASK					0x1
#define QI_VM12_1_MODE_SHIFT				0x7
#define VM12_1_LP_SET_MASK					0x1
#define VM12_1_LP_SET_SHIFT					0x1
#define VM12_1_LP_SEL_MASK					0x1	
#define VM12_1_LP_SEL_SHIFT					0x0

// (0x86) DIGLDO_CON4 (RW)
#define DIGLDO_CON4_ADDR 					0x86

#define RG_VM12_2_CAL_MASK					0xF
#define RG_VM12_2_CAL_SHIFT					0x0

// (0x87) DIGLDO_CON5 (RO/RW)
#define DIGLDO_CON5_ADDR 					0x87

#define QI_VM12_2_EN_MASK					0x1	
#define QI_VM12_2_EN_SHIFT					0x7
#define VM12_2_EN_MASK						0x1	
#define VM12_2_EN_SHIFT						0x0

// (0x88) DIGLDO_CON6 (RW)
#define RG_VM12_2_STBTD_MASK				0x3
#define RG_VM12_2_STBTD_SHIFT				0x4
#define RG_VM12_2_OCFB_EN_MASK				0x1
#define RG_VM12_2_OCFB_EN_SHIFT				0x1
#define RG_VM12_2_NDIS_EN_MASK				0x1
#define RG_VM12_2_NDIS_EN_SHIFT				0x0
                                			
// (0x89) DIGLDO_CON7 (RO/RW)   			
#define QI_VM12_2_MODE_MASK					0x1 			
#define QI_VM12_2_MODE_SHIFT				0x7
#define VM12_2_LP_SET_MASK					0x1
#define VM12_2_LP_SET_SHIFT					0x1
#define VM12_2_LP_SEL_MASK					0x1	
#define VM12_2_LP_SEL_SHIFT					0x0

// (0x8A) DIGLDO_CON8 (RW)
#define DIGLDO_CON8_ADDR 					0x8A

#define RG_VM12_INT_CAL_MASK				0x1F
#define RG_VM12_INT_CAL_SHIFT				0x0
                                			
// (0x8B) DIGLDO_CON9 (RW)      			
#define VM12_INT_SLEEP_MASK					0x1F
#define VM12_INT_SLEEP_SHIFT				0x0
                                			
// (0x8C) DIGLDO_CONA (RW)      			
#define VM12_INT_LOW_BOUND_MASK				0x1F	
#define VM12_INT_LOW_BOUND_SHIFT			0x0

// (0x8D) DIGLDO_CONB (RO/RW)
#define DIGLDO_CONB_ADDR 					0x8D

#define QI_VM12_INT_EN_MASK					0x1	
#define QI_VM12_INT_EN_SHIFT				0x7
#define VM12_INT_EN_MASK					0x1
#define VM12_INT_EN_SHIFT					0x0

// (0x8E) DIGLDO_CONC (RW)
#define RG_VM12_INT_STBTD_MASK				0x3
#define RG_VM12_INT_STBTD_SHIFT				0x4
#define RG_VM12_INT_OCFB_EN_MASK			0x1
#define RG_VM12_INT_OCFB_EN_SHIFT			0x1
#define RG_VM12_INT_NDIS_EN_MASK			0x1
#define RG_VM12_INT_NDIS_EN_SHIFT			0x0

// (0x8F) DIGLDO_COND (RW)
#define VM12_INT_CTRL_SEL_MASK				0x1
#define VM12_INT_CTRL_SEL_SHIFT				0x4
#define RG_VM12_INT_TRIM_MASK				0x7	
#define RG_VM12_INT_TRIM_SHIFT				0x1
#define RG_VM12_INT_CAL_SFCHG_EN_MASK		0x1
#define RG_VM12_INT_CAL_SFCHG_EN_SHIFT		0x0

// (0x90) DIGLDO_CONE (RO/RW)
#define QI_VM12_INT_MODE_MASK				0x1
#define QI_VM12_INT_MODE_SHIFT				0x7
#define VM12_INT_LP_SET_MASK				0x1	
#define VM12_INT_LP_SET_SHIFT				0x1
#define VM12_INT_LP_SEL_MASK				0x1	
#define VM12_INT_LP_SEL_SHIFT				0x0

// (0x91) DIGLDO_CONF (RW)
#define DIGLDO_CONF_ADDR 					0x91

#define RG_VIO28_CAL_MASK					0xF	
#define RG_VIO28_CAL_SHIFT					0x0

// (0x92) DIGLDO_CON10 (RO/RW)
#define DIGLDO_CON10_ADDR 					0x92

#define QI_VIO28_EN_MASK					0x1	
#define QI_VIO28_EN_SHIFT					0x7
#define VIO28_EN_MASK						0x1
#define VIO28_EN_SHIFT						0x0

// (0x93) DIGLDO_CON11 (RW)
#define RG_VIO28_STBTD_MASK					0x3
#define RG_VIO28_STBTD_SHIFT				0x4
#define RG_VIO28_OCFB_EN_MASK				0x1
#define RG_VIO28_OCFB_EN_SHIFT				0x1
#define RG_VIO28_NDIS_EN_MASK				0x1	
#define RG_VIO28_NDIS_EN_SHIFT				0x0

// (0x94) DIGLDO_CON12 (RW)
#define DIGLDO_CON12_ADDR 					0x94

#define RG_VSIM_CAL_MASK					0xF
#define RG_VSIM_CAL_SHIFT					0x0
                                			
// (0x95) DIGLDO_CON13 (RW)     			
#define DIGLDO_CON13_ADDR 					0x95

#define RG_VSIM_VOSEL_MASK					0x1	
#define RG_VSIM_VOSEL_SHIFT					0x4
#define RG_VSIM_EN_MASK						0x1	
#define RG_VSIM_EN_SHIFT					0x0
                                			
// (0x96) DIGLDO_CON14 (RW)     			
#define RG_VSIM_STBTD_MASK					0x3	
#define RG_VSIM_STBTD_SHIFT					0x4
#define RG_VSIM_OCFB_EN_MASK				0x1
#define RG_VSIM_OCFB_EN_SHIFT				0x1
#define RG_VSIM_NDIS_EN_MASK				0x1
#define RG_VSIM_NDIS_EN_SHIFT				0x0

// (0x97) DIGLDO_CON15 (RW)
#define DIGLDO_CON15_ADDR 					0x97

#define RG_VSIM2_CAL_MASK					0xF	
#define RG_VSIM2_CAL_SHIFT					0x0
                            				
// (0x98) DIGLDO_CON16 (RW) 	
#define DIGLDO_CON16_ADDR 					0x98
			
#define RG_VSIM2_VOSEL_MASK					0x7	
#define RG_VSIM2_VOSEL_SHIFT				0x4
#define RG_VSIM2_EN_MASK					0x1	
#define RG_VSIM2_EN_SHIFT					0x0

// (0x99) DIGLDO_CON17 (RW)
#define RG_VSIM2_STBTD_MASK					0x3	
#define RG_VSIM2_STBTD_SHIFT				0x4
#define RG_VSIM2_OCFB_EN_MASK				0x1	
#define RG_VSIM2_OCFB_EN_SHIFT				0x1
#define RG_VSIM2_NDIS_EN_MASK				0x1
#define RG_VSIM2_NDIS_EN_SHIFT				0x0

// (0x9A) DIGLDO_CON18 (RW)
#define DIGLDO_CON18_ADDR 					0x9A

#define RG_VUSB_CAL_MASK					0xF
#define RG_VUSB_CAL_SHIFT					0x0

// (0x9B) DIGLDO_CON19 (RO/RW)
#define DIGLDO_CON19_ADDR 					0x9B

#define QI_VUSB_EN_MASK						0x1
#define QI_VUSB_EN_SHIFT					0x7
#define RG_VUSB_EN_MASK						0x1	
#define RG_VUSB_EN_SHIFT					0x0

// (0x9C) DIGLDO_CON1A (RW)
#define RG_VUSB_STBTD_MASK					0x3
#define RG_VUSB_STBTD_SHIFT					0x4
#define RG_VUSB_OCFB_EN_MASK				0x1
#define RG_VUSB_OCFB_EN_SHIFT				0x1
#define RG_VUSB_NDIS_EN_MASK				0x1
#define RG_VUSB_NDIS_EN_SHIFT				0x0

// (0x9D) DIGLDO_CON1B (RW)
#define DIGLDO_CON1B_ADDR 					0x9D

#define RG_VCAMD_CAL_MASK					0xF	
#define RG_VCAMD_CAL_SHIFT					0x0

// (0x9E) DIGLDO_CON1C (RW)
#define DIGLDO_CON1C_ADDR 					0x9E

#define RG_VCAMD_VOSEL_MASK					0x7
#define RG_VCAMD_VOSEL_SHIFT				0x4
#define RG_VCAMD_EN_MASK					0x1	
#define RG_VCAMD_EN_SHIFT					0x0

// (0x9F) DIGLDO_CON1D (RW)
#define RG_VCAMD_STBTD_MASK					0x3	
#define RG_VCAMD_STBTD_SHIFT				0x4
#define RG_VCAMD_OCFB_EN_MASK				0x1	
#define RG_VCAMD_OCFB_EN_SHIFT				0x1
#define RG_VCAMD_NDIS_EN_MASK				0x1
#define RG_VCAMD_NDIS_EN_SHIFT				0x0

// (0xA0) DIGLDO_CON1E (RW)
#define DIGLDO_CON1E_ADDR 					0xA0

#define RG_VCAM_IO_CAL_MASK					0xF
#define RG_VCAM_IO_CAL_SHIFT				0x0
                                			
// (0xA1) DIGLDO_CON1F (RW)  
#define DIGLDO_CON1F_ADDR 					0xA1
   			
#define RG_VCAM_IO_VOSEL_MASK				0x7	
#define RG_VCAM_IO_VOSEL_SHIFT				0x4
#define RG_VCAM_IO_EN_MASK					0x1	
#define RG_VCAM_IO_EN_SHIFT					0x0

// (0xA2) DIGLDO_CON20 (RW)
#define RG_VCAM_IO_STBTD_MASK				0x3	
#define RG_VCAM_IO_STBTD_SHIFT				0x4
#define RG_VCAM_IO_OCFB_EN_MASK				0x1
#define RG_VCAM_IO_OCFB_EN_SHIFT			0x1
#define RG_VCAM_IO_NDIS_EN_MASK				0x1
#define RG_VCAM_IO_NDIS_EN_SHIFT			0x0

// (0xA3) DIGLDO_CON21 (RW)
#define DIGLDO_CON21_ADDR 					0xA3

#define RG_VCAM_AF_CAL_MASK					0xF	
#define RG_VCAM_AF_CAL_SHIFT				0x0
                                			
// (0xA4) DIGLDO_CON22 (RW)    
#define DIGLDO_CON22_ADDR 					0xA4
 			
#define RG_VCAM_AF_VOSEL_MASK				0x7
#define RG_VCAM_AF_VOSEL_SHIFT				0x4
#define RG_VCAM_AF_EN_MASK					0x1	
#define RG_VCAM_AF_EN_SHIFT					0x0

// (0xA5) DIGLDO_CON23 (RW)
#define RG_VCAM_AF_STBTD_MASK				0x3	
#define RG_VCAM_AF_STBTD_SHIFT				0x4
#define RG_VCAM_AF_OCFB_EN_MASK				0x1	
#define RG_VCAM_AF_OCFB_EN_SHIFT			0x1
#define RG_VCAM_AF_NDIS_EN_MASK				0x1	
#define RG_VCAM_AF_NDIS_EN_SHIFT			0x0

// (0xA6) DIGLDO_CON24 (RW)
#define DIGLDO_CON24_ADDR 					0xA6

#define RG_VMC_CAL_MASK						0xF	
#define RG_VMC_CAL_SHIFT					0x0

// (0xA7) DIGLDO_CON25 (RO/RW)
#define DIGLDO_CON25_ADDR 					0xA7

#define QI_VMC_EN_MASK						0x1	
#define QI_VMC_EN_SHIFT						0x7
#define RG_VMC_VOSEL_MASK					0x7
#define RG_VMC_VOSEL_SHIFT					0x4
#define RG_VMC_EN_MASK						0x1	
#define RG_VMC_EN_SHIFT						0x0

// (0xA8) DIGLDO_CON26 (RW)
#define RG_VMC_STBTD_MASK					0x3	
#define RG_VMC_STBTD_SHIFT					0x4
#define RG_VMC_OCFB_EN_MASK					0x1
#define RG_VMC_OCFB_EN_SHIFT				0x1
#define RG_VMC_NDIS_EN_MASK					0x1	
#define RG_VMC_NDIS_EN_SHIFT				0x0

// (0xA9) DIGLDO_CON27 (RO/RW)
#define QI_VMC_MODE_MASK					0x1	
#define QI_VMC_MODE_SHIFT					0x7
#define VMC_LP_MODE_SET_MASK				0x1	
#define VMC_LP_MODE_SET_SHIFT				0x1
#define VMC_LP_SEL_MASK						0x1	
#define VMC_LP_SEL_SHIFT					0x0

// (0xAA) DIGLDO_CON28 (RW)
#define DIGLDO_CON28_ADDR 					0xAA

#define RG_VMCH_CAL_MASK					0xF	
#define RG_VMCH_CAL_SHIFT					0x0

// (0xAB) DIGLDO_CON29 (RO/RW)
#define DIGLDO_CON29_ADDR 					0xAB

#define QI_VMCH_EN_MASK						0x1
#define QI_VMCH_EN_SHIFT					0x7
#define RG_VMCH_VOSEL_MASK					0x7	
#define RG_VMCH_VOSEL_SHIFT					0x4
#define RG_VMCH_EN_MASK						0x1	
#define RG_VMCH_EN_SHIFT					0x0

// (0xAC) DIGLDO_CON2A (RW)
#define RG_VMCH_STBTD_MASK					0x3	
#define RG_VMCH_STBTD_SHIFT					0x4
#define RG_VMCH_OCFB_EN_MASK				0x1
#define RG_VMCH_OCFB_EN_SHIFT				0x1
#define RG_VMCH_NDIS_EN_MASK				0x1	
#define RG_VMCH_NDIS_EN_SHIFT				0x0
                                			
// (0xAD) DIGLDO_CON2B (RO/RW)  			
#define QI_VMCH_MODE_MASK					0x1	
#define QI_VMCH_MODE_SHIFT					0x7
#define VMCH_LP_MODE_SET_MASK				0x1	
#define VMCH_LP_MODE_SET_SHIFT				0x1
#define VMCH_LP_SEL_MASK					0x1
#define VMCH_LP_SEL_SHIFT					0x0
                            				
// (0xAE) DIGLDO_CON2C (RW) 		
#define DIGLDO_CON2C_ADDR 					0xAE
		
#define RG_VGP_CAL_MASK						0xF	
#define RG_VGP_CAL_SHIFT					0x0
                            				
// (0xAF) DIGLDO_CON2D (RW)
#define DIGLDO_CON2D_ADDR 					0xAF
 				
#define RG_VGP_VOSEL_MASK					0x7	
#define RG_VGP_VOSEL_SHIFT					0x4
#define RG_VGP_EN_MASK						0x1	
#define RG_VGP_EN_SHIFT						0x0
                            				
// (0xB0) DIGLDO_CON2E (RW) 				
#define RG_VGP_STBTD_MASK					0x3
#define RG_VGP_STBTD_SHIFT					0x4
#define RG_VGP_OCFB_EN_MASK					0x1
#define RG_VGP_OCFB_EN_SHIFT				0x1
#define RG_VGP_NDIS_EN_MASK					0x1
#define RG_VGP_NDIS_EN_SHIFT				0x0
                                			
// (0xB1) DIGLDO_CON2F (RW)    
#define DIGLDO_CON2F_ADDR 					0xB1
 			
#define RG_VGP2_CAL_MASK					0xF
#define RG_VGP2_CAL_SHIFT					0x0
                                			
// (0xB2) DIGLDO_CON30 (RW)     			
#define DIGLDO_CON30_ADDR 					0xB2

#define RG_VGP2_VOSEL_MASK					0x7	
#define RG_VGP2_VOSEL_SHIFT					0x4
#define RG_VGP2_EN_MASK						0x1		
#define RG_VGP2_EN_SHIFT					0x0
                                			
// (0xB3) DIGLDO_CON31 (RW)     			
#define RG_VGP2_STBTD_MASK					0x3
#define RG_VGP2_STBTD_SHIFT					0x4
#define RG_VGP2_OCFB_EN_MASK				0x1	
#define RG_VGP2_OCFB_EN_SHIFT				0x1
#define RG_VGP2_NDIS_EN_MASK				0x1
#define RG_VGP2_NDIS_EN_SHIFT				0x0

// (0xB4) DIGLDO_CON32 (RW)
#define DIGLDO_CON32_ADDR 					0xB4

#define RG_VIBR_CAL_MASK					0xF
#define RG_VIBR_CAL_SHIFT					0x0
                            				
// (0xB5) DIGLDO_CON33 (RW) 
#define DIGLDO_CON33_ADDR 					0xB5
				
#define RG_VIBR_VOSEL_MASK					0x7	
#define RG_VIBR_VOSEL_SHIFT					0x4
#define RG_VIBR_EN_MASK						0x1	
#define RG_VIBR_EN_SHIFT					0x0
                            				
// (0xB6) DIGLDO_CON34 (RW) 				
#define RG_VIBR_STBTD_MASK					0x3
#define RG_VIBR_STBTD_SHIFT					0x4
#define RG_VIBR_THR_SHDN_EN_MASK			0x1
#define RG_VIBR_THR_SHDN_EN_SHIFT			0x3
#define RG_VIBR_STB_SEL_MASK				0x1	
#define RG_VIBR_STB_SEL_SHIFT				0x2
#define RG_VIBR_OCFB_EN_MASK				0x1	
#define RG_VIBR_OCFB_EN_SHIFT				0x1
#define RG_VIBR_NDIS_EN_MASK				0x1	
#define RG_VIBR_NDIS_EN_SHIFT				0x0
                                    		
// (0xB7) DIGLDO_CON35 (RO)         		
#define RO_QI_VUSB_OC_STATUS_MASK			0x1	
#define RO_QI_VUSB_OC_STATUS_SHIFT			0x6
#define RO_QI_VSIM2_OC_STATUS_MASK			0x1	
#define RO_QI_VSIM2_OC_STATUS_SHIFT			0x5
#define RO_QI_VSIM_OC_STATUS_MASK			0x1	
#define RO_QI_VSIM_OC_STATUS_SHIFT			0x4
#define RO_QI_VIO28_OC_STATUS_MASK			0x1
#define RO_QI_VIO28_OC_STATUS_SHIFT			0x3
#define RO_QI_VM12_INT_OC_STATUS_MASK		0x1
#define RO_QI_VM12_INT_OC_STATUS_SHIFT		0x2
#define RO_QI_VM12_2_OC_STATUS_MASK			0x1	
#define RO_QI_VM12_2_OC_STATUS_SHIFT		0x1
#define RO_QI_VM12_1_OC_STATUS_MASK			0x1	
#define RO_QI_VM12_1_OC_STATUS_SHIFT		0x0

// (0xB8) DIGLDO_CON36 (RO)
#define RO_QI_VIBR_OC_STATUS_MASK			0x1	
#define RO_QI_VIBR_OC_STATUS_SHIFT			0x7
#define RO_QI_VGP2_OC_STATUS_MASK			0x1	
#define RO_QI_VGP2_OC_STATUS_SHIFT			0x6
#define RO_QI_VGP_OC_STATUS_MASK			0x1
#define RO_QI_VGP_OC_STATUS_SHIFT			0x5
#define RO_QI_VMCH_OC_STATUS_MASK			0x1	
#define RO_QI_VMCH_OC_STATUS_SHIFT			0x4
#define RO_QI_VMC_OC_STATUS_MASK			0x1	
#define RO_QI_VMC_OC_STATUS_SHIFT			0x3
#define RO_QI_VCAM_AF_OC_STATUS_MASK		0x1
#define RO_QI_VCAM_AF_OC_STATUS_SHIFT		0x2
#define RO_QI_VCAM_IO_OC_STATUS_MASK		0x1	
#define RO_QI_VCAM_IO_OC_STATUS_SHIFT		0x1
#define RO_QI_VCAMD_OC_STATUS_MASK			0x1	
#define RO_QI_VCAMD_OC_STATUS_SHIFT			0x0
                                       	
// (0xB9) DIGLDO_CON37 (RO)            	
#define QI_VM12_INT_CAL_MASK				0x1F	
#define QI_VM12_INT_CAL_SHIFT				0x0
                                       	
// (0xBA) DIGLDO_RSV (RW)
#define RG_DIGLDO_RSV_MASK					0xF	
#define RG_DIGLDO_RSV_SHIFT					0x0
                            				
// (0xBD) ANALDO_CON0 (RW) 
#define ANALDO_CON0_ADDR 					0xBD
 				
#define RG_VRF_CAL_MASK						0xF	
#define RG_VRF_CAL_SHIFT					0x0

// (0xBE) ANALDO_CON1 (RO/RW)
#define ANALDO_CON1_ADDR 					0xBE

#define QI_VRF_EN_MASK						0x1	
#define QI_VRF_EN_SHIFT						0x7
#define VRF_ON_CTRL_MASK					0x1	
#define VRF_ON_CTRL_SHIFT					0x1
#define RG_VRF_EN_MASK						0x1	
#define RG_VRF_EN_SHIFT						0x0
                           	
// (0xBF) ANALDO_CON2 (RW) 	
#define RG_VRF_STBTD_MASK					0x3
#define RG_VRF_STBTD_SHIFT					0x4
#define RG_VRF_OCFB_EN_MASK					0x1
#define RG_VRF_OCFB_EN_SHIFT				0x1
#define RG_VRF_NDIS_EN_MASK					0x1	
#define RG_VRF_NDIS_EN_SHIFT				0x0
                                			
// (0xC0) ANALDO_CON3 (RW)      		
#define ANALDO_CON3_ADDR 					0xC0
	
#define RG_VTCXO_CAL_MASK					0xF	
#define RG_VTCXO_CAL_SHIFT					0x0
                                			
// (0xC1) ANALDO_CON4 (RO/RW)
#define ANALDO_CON4_ADDR 					0xC1   			

#define QI_VTCXO_EN_MASK					0x1	
#define QI_VTCXO_EN_SHIFT					0x7
#define VTCXO_ON_CTRL_MASK					0x1	
#define VTCXO_ON_CTRL_SHIFT					0x1
#define RG_VTCXO_EN_MASK					0x1	
#define RG_VTCXO_EN_SHIFT					0x0
                                			
// (0xC2) ANALDO_CON5 (RW)      			
#define RG_VTCXO_STBTD_MASK					0x3
#define RG_VTCXO_STBTD_SHIFT				0x4
#define RG_VTCXO_OCFB_EN_MASK				0x1	
#define RG_VTCXO_OCFB_EN_SHIFT				0x1
#define RG_VTCXO_NDIS_EN_MASK				0x1	
#define RG_VTCXO_NDIS_EN_SHIFT				0x0
                                			
// (0xC3) ANALDO_CON6 (RW)
#define ANALDO_CON6_ADDR 					0xC3     
 			
#define RG_VA1_CAL_MASK						0xF
#define RG_VA1_CAL_SHIFT					0x0
                                			
// (0xC4) ANALDO_CON7 (RO/RW)   	
#define ANALDO_CON7_ADDR 					0xC4		

#define QI_VA1_EN_MASK						0x1	
#define QI_VA1_EN_SHIFT						0x7
#define RG_VA1_VOSEL_MASK					0x3	
#define RG_VA1_VOSEL_SHIFT					0x4
#define RG_VA1_EN_MASK						0x1
#define RG_VA1_EN_SHIFT						0x0
                                			
// (0xC5) ANALDO_CON8 (RW)      			
#define RG_VA1_STBTD_MASK					0x3	
#define RG_VA1_STBTD_SHIFT					0x4
#define RG_VA1_OCFB_EN_MASK					0x1
#define RG_VA1_OCFB_EN_SHIFT				0x1
#define RG_VA1_NDIS_EN_MASK					0x1	
#define RG_VA1_NDIS_EN_SHIFT				0x0
                                			
// (0xC6) ANALDO_CON9 (RO/RW)
#define QI_VA1_MODE_MASK					0x1
#define QI_VA1_MODE_SHIFT					0x7
#define VA1_LP_SET_MASK						0x1	
#define VA1_LP_SET_SHIFT					0x1
#define VA1_LP_SEL_MASK						0x1	
#define VA1_LP_SEL_SHIFT					0x0
                            				
// (0xC7) ANALDO_CONA (RW) 
#define ANALDO_CONA_ADDR 					0xC7
 				
#define RG_VA2_CAL_MASK						0xF	
#define RG_VA2_CAL_SHIFT					0x0

// (0xC8) ANALDO_CONB (RO/RW)
#define ANALDO_CONB_ADDR 					0xC8

#define QI_VA2_EN_MASK						0x1	
#define QI_VA2_EN_SHIFT						0x7
#define RG_VA2_VOSEL_MASK					0x1
#define RG_VA2_VOSEL_SHIFT					0x4
#define RG_VA2_EN_MASK						0x1
#define RG_VA2_EN_SHIFT						0x0
                           	
// (0xC9) ANALDO_CONC (RW)
#define RG_VA2_STBTD_MASK					0x3	
#define RG_VA2_STBTD_SHIFT					0x4
#define RG_VA2_OCFB_EN_MASK					0x1	
#define RG_VA2_OCFB_EN_SHIFT				0x1
#define RG_VA2_NDIS_EN_MASK					0x1	
#define RG_VA2_NDIS_EN_SHIFT				0x0

// (0xCA) ANALDO_COND (RW)
#define ANALDO_COND_ADDR 					0xCA

#define RG_VCAMA_CAL_MASK					0xF	
#define RG_VCAMA_CAL_SHIFT					0x0

// (0xCB) ANALDO_CONE (RW)
#define ANALDO_CONE_ADDR 					0xCB

#define RG_VCAMA_VOSEL_MASK					0x3	
#define RG_VCAMA_VOSEL_SHIFT				0x4
#define RG_VCAMA_EN_MASK					0x1
#define RG_VCAMA_EN_SHIFT					0x0

// (0xCC) ANALDO_CONF (RW)
#define RG_VCAMA_STBTD_MASK					0x3	
#define RG_VCAMA_STBTD_SHIFT				0x4
#define RG_VCAMA_OCFB_EN_MASK				0x1	
#define RG_VCAMA_OCFB_EN_SHIFT				0x1
#define RG_VCAMA_NDIS_EN_MASK				0x1	
#define RG_VCAMA_NDIS_EN_SHIFT				0x0

// (0xCD) ANALDO_CON10 (RW)
#define RG_VCAMA_FBSEL_MASK					0x3	
#define RG_VCAMA_FBSEL_SHIFT				0x0

// (0xCE) ANALDO_CON11 (RW)
#define ANALDO_CON11_ADDR 					0xCE

#define RG_VRTC_VOSEL_MASK					0x3	
#define RG_VRTC_VOSEL_SHIFT					0x0

// (0xCF) ANALDO_CON12 (RO/RW)
#define ANALDO_CON12_ADDR 					0xCF

#define QI_VRTC_EN_MASK						0x1	
#define QI_VRTC_EN_SHIFT					0x7
#define VRTC_EN_MASK						0x1	
#define VRTC_EN_SHIFT						0x0

// (0xD0) ANALDO_CON13 (RO)
#define RO_QI_VRF_OC_STATUS_MASK			0x1	
#define RO_QI_VRF_OC_STATUS_SHIFT			0x0
#define RO_QI_VTCXO_OC_STATUS_MASK			0x1	
#define RO_QI_VTCXO_OC_STATUS_SHIFT			0x1
#define RO_QI_VA1_OC_STATUS_MASK			0x1	
#define RO_QI_VA1_OC_STATUS_SHIFT			0x2
#define RO_QI_VA2_OC_STATUS_MASK			0x1
#define RO_QI_VA2_OC_STATUS_SHIFT			0x3
#define RO_QI_VCAMA_OC_STATUS_MASK			0x1
#define RO_QI_VCAMA_OC_STATUS_SHIFT			0x4
                                    		
// (0xD1) ANALDO_RSV (RW)
#define RG_ANALDO_RSV_MASK					0xF
#define RG_ANALDO_RSV_SHIFT					0x0

// (0xD5) BUCK_K_CON0 (RW)
#define RG_AUTO_K_MASK						0x1	
#define RG_AUTO_K_SHIFT						0x6
#define RG_K_SRC_SEL_MASK					0x1	
#define RG_K_SRC_SEL_SHIFT					0x5
#define RG_K_START_MANUAL_MASK				0x1
#define RG_K_START_MANUAL_SHIFT				0x4
#define RG_K_ONCE_MASK						0x1	
#define RG_K_ONCE_SHIFT						0x3
#define RG_K_ONCE_EN_MASK					0x1
#define RG_K_ONCE_EN_SHIFT					0x2
#define RG_K_MAP_SEL_MASK					0x1	
#define RG_K_MAP_SEL_SHIFT					0x1
#define RG_K_RST_DONE_MASK					0x1
#define RG_K_RST_DONE_SHIFT					0x0

// (0xD6) BUCK_K_CON1 (RW)
#define RG_K_CONTROL_SMPS_MASK				0xF
#define RG_K_CONTROL_SMPS_SHIFT				0x0

// (0xD7) BUCK_K_CON2 (RO)
#define K_CONTROL_MASK						0x1F	
#define K_CONTROL_SHIFT						0x3
#define K_DONE_MASK							0x1	
#define K_DONE_SHIFT						0x1
#define K_RESULT_MASK						0x1	
#define K_RESULT_SHIFT						0x0

// (0xDA) AUXADC_CON0 (RO)
#define RG_ADC_OUT_C0_7_0_MASK				0xFF	
#define RG_ADC_OUT_C0_7_0_SHIFT				0x0

// (0xDB) AUXADC_CON1 (RO)
#define RG_ADC_RDY_C0_MASK					0x1	
#define RG_ADC_RDY_C0_SHIFT					0x7
#define RG_ADC_OUT_C0_9_8_MASK				0x3
#define RG_ADC_OUT_C0_9_8_SHIFT				0x0

// (0xDC) AUXADC_CON2 (RO)
#define RG_ADC_OUT_C1_7_0_MASK				0xFF	
#define RG_ADC_OUT_C1_7_0_SHIFT				0x0
                                			
// (0xDD) AUXADC_CON3 (RO)
#define RG_ADC_RDY_C1_MASK					0x1	
#define RG_ADC_RDY_C1_SHIFT					0x7
#define RG_ADC_OUT_C1_9_8_MASK				0x3
#define RG_ADC_OUT_C1_9_8_SHIFT				0x0

// (0xDE) AUXADC_CON4 (RO)
#define RG_ADC_OUT_C2_7_0_MASK				0xFF	
#define RG_ADC_OUT_C2_7_0_SHIFT				0x0

// (0xDF) AUXADC_CON5 (RO)
#define RG_ADC_RDY_C2_MASK					0x1
#define RG_ADC_RDY_C2_SHIFT					0x7
#define RG_ADC_OUT_C2_9_8_MASK				0x3	
#define RG_ADC_OUT_C2_9_8_SHIFT				0x0
                               		
// (0xE0) AUXADC_CON6 (RO)     	
#define RG_ADC_OUT_C3_7_0_MASK				0xFF
#define RG_ADC_OUT_C3_7_0_SHIFT				0x0

// (0xE1) AUXADC_CON7 (RO)
#define RG_ADC_RDY_C3_MASK					0x1	
#define RG_ADC_RDY_C3_SHIFT					0x7
#define RG_ADC_OUT_C3_9_8_MASK				0x3
#define RG_ADC_OUT_C3_9_8_SHIFT				0x0

// (0xE2) AUXADC_CON8 (RO)
#define RG_ADC_OUT_WAKEUP_7_0_MASK			0xFF
#define RG_ADC_OUT_WAKEUP_7_0_SHIFT			0x0

// (0xE3) AUXADC_CON9 (RO)
#define RG_ADC_RDY_WAKEUP_MASK				0x1	
#define RG_ADC_RDY_WAKEUP_SHIFT				0x7
#define RG_ADC_OUT_WAKEUP_9_8_MASK			0x3
#define RG_ADC_OUT_WAKEUP_9_8_SHIFT			0x0
                                    		
// (0xE4) AUXADC_CON10 (RO)         		
#define RG_ADC_OUT_LBAT_7_0_MASK			0xFF	
#define RG_ADC_OUT_LBAT_7_0_SHIFT			0x0

// (0xE5) AUXADC_CON11 (RO)
#define RG_ADC_RDY_LBAT_MASK				0x1
#define RG_ADC_RDY_LBAT_SHIFT				0x7
#define RG_ADC_OUT_LBAT_9_8_MASK			0x3
#define RG_ADC_OUT_LBAT_9_8_SHIFT			0x0

// (0xE6) AUXADC_CON12 (RO)
#define RG_ADC_OUT_TRIM_7_0_MASK			0xFF	
#define RG_ADC_OUT_TRIM_7_0_SHIFT			0x0
                                    		
// (0xE7) AUXADC_CON13 (RO)         		
#define RG_ADC_RDY_TRIM_MASK				0x1	
#define RG_ADC_RDY_TRIM_SHIFT				0x7
#define RG_ADC_OUT_TRIM_9_8_MASK			0x3
#define RG_ADC_OUT_TRIM_9_8_SHIFT			0x0
                                    		
// (0xE8) AUXADC_CON14 (RW)         		
#define RG_AUXADC_CHSEL_MASK				0xF	
#define RG_AUXADC_CHSEL_SHIFT				0x4
#define RG_ADC_TRIM_COMP_MASK				0x1	
#define RG_ADC_TRIM_COMP_SHIFT				0x2
#define RG_AUXADC_BIST_ENB_MASK				0x1	
#define RG_AUXADC_BIST_ENB_SHIFT			0x1
#define RG_AUXADC_START_MASK				0x1	
#define RG_AUXADC_START_SHIFT				0x0

// (0xE9) AUXADC_CON15 (RW)
#define RG_SPL_NUM_MASK						0xF	
#define RG_SPL_NUM_SHIFT					0x4
#define RG_AVG_NUM_MASK						0x3	
#define RG_AVG_NUM_SHIFT					0x2
#define RG_BUF_PWD_B_MASK					0x1	
#define RG_BUF_PWD_B_SHIFT					0x1
#define RG_ADC_PWD_B_MASK					0x1	
#define RG_ADC_PWD_B_SHIFT					0x0
                                			
// (0xEA) AUXADC_CON16 (RW)     			
#define RG_LBAT_DEBT_MAX_MASK				0xFF	
#define RG_LBAT_DEBT_MAX_SHIFT				0x0
                                			
// (0xEB) AUXADC_CON17 (RW)     			
#define RG_LBAT_DEBT_MIN_MASK				0xFF
#define RG_LBAT_DEBT_MIN_SHIFT				0x0
                                    		
// (0xEC) AUXADC_CON18 (RW)         		
#define RG_LBAT_DET_PRD_7_0_MASK			0xFF
#define RG_LBAT_DET_PRD_7_0_SHIFT			0x0
                                    		
// (0xED) AUXADC_CON19 (RW)         		
#define RG_LBAT_DET_PRD_15_8_MASK			0xFF	
#define RG_LBAT_DET_PRD_15_8_SHIFT			0x0

// (0xEE) AUXADC_CON20 (RW)
#define RG_LBAT_DET_PRD_19_16_MASK			0xF
#define RG_LBAT_DET_PRD_19_16_SHIFT			0x0
                                    		
// (0xEF) AUXADC_CON21 (RW)         		
#define RG_LBAT_VOLT_MAX_7_0_MASK			0xFF	
#define RG_LBAT_VOLT_MAX_7_0_SHIFT			0x0

// (0xF0) AUXADC_CON22 (RW)
#define RG_LBAT_EN_MAX_MASK					0x1	
#define RG_LBAT_EN_MAX_SHIFT				0x7
#define RG_LBAT_IRQ_EN_MAX_MASK				0x1
#define RG_LBAT_IRQ_EN_MAX_SHIFT			0x4
#define RG_LBAT_VOLT_MAX_9_8_MASK			0x3
#define RG_LBAT_VOLT_MAX_9_8_SHIFT			0x0

// (0xF1) AUXADC_CON23 (RW)
#define RG_LBAT_VOLT_MIN_7_0_MASK			0xFF
#define RG_LBAT_VOLT_MIN_7_0_SHIFT			0x0
                                    		
// (0xF2) AUXADC_CON24 (RW)         		
#define RG_LBAT_EN_MIN_MASK					0x1	
#define RG_LBAT_EN_MIN_SHIFT				0x7
#define RG_LBAT_IRQ_EN_MIN_MASK				0x1
#define RG_LBAT_IRQ_EN_MIN_SHIFT			0x4
#define RG_LBAT_VOLT_MIN_9_8_MASK			0x3
#define RG_LBAT_VOLT_MIN_9_8_SHIFT			0x0

// (0xF3) AUXADC_CON25 (RO)
#define RG_LBAT_MAX_IRQ_B_MASK				0x1	
#define RG_LBAT_MAX_IRQ_B_SHIFT				0x7
#define RG_LBAT_MIN_IRQ_B_MASK				0x1	
#define RG_LBAT_MIN_IRQ_B_SHIFT				0x6

// (0xF4) AUXADC_CON26 (RW)
#define RG_DA_DAC_7_0_MASK					0xFF	
#define RG_DA_DAC_7_0_SHIFT					0x0

// (0xF5) AUXADC_CON27 (RO/RW)
#define RG_NI_COMP_MASK						0x1	
#define RG_NI_COMP_SHIFT					0x7
#define RG_DA_DAC_9_8_MASK					0x3	
#define RG_DA_DAC_9_8_SHIFT					0x0
                            				
// (0xF6) AUXADC_CON28 (RW) 				
#define RG_AUXADC_RSV_MASK					0x7
#define RG_AUXADC_RSV_SHIFT					0x5
#define RG_DA_DAC_SEL_MASK					0x1	
#define RG_DA_DAC_SEL_SHIFT					0x4
#define RG_AUX_OUT_SEL_MASK					0x1	
#define RG_AUX_OUT_SEL_SHIFT				0x3
#define RG_ARB_PRIO_2_MASK					0x1	
#define RG_ARB_PRIO_2_SHIFT					0x2
#define RG_ARB_PRIO_1_MASK					0x1	
#define RG_ARB_PRIO_1_SHIFT					0x1
#define RG_ARB_PRIO_0_MASK					0x1	
#define RG_ARB_PRIO_0_SHIFT					0x0

// (0xF7) AUXADC_CON29 (RW)
#define RG_AUXADC_CALI_MASK					0x3
#define RG_AUXADC_CALI_SHIFT				0x4
#define RG_BUF_CALI_MASK					0x3	
#define RG_BUF_CALI_SHIFT					0x0
                               	
////////////////////////////////
/*      PMIC 6329 BANK 1      */
////////////////////////////////
// (0x00) TEST_CON0 (RW)
#define RG_MON_GRP_SEL_MASK					0xF	
#define RG_MON_GRP_SEL_SHIFT				0x0
                                			
// (0x01) TEST_CON1 (RW)        			
#define RG_MON_FLAG_SEL_MASK				0xFF
#define RG_MON_FLAG_SEL_SHIFT				0x0
                                			
// (0x02) TEST_CON2 (RW)        			
#define RG_IO_PASEL0_SEL_MASK				0xF	
#define RG_IO_PASEL0_SEL_SHIFT				0x4
#define RG_IO_PASEL1_SEL_MASK				0xF
#define RG_IO_PASEL1_SEL_SHIFT				0x0
                                			
// (0x03) TEST_CON3 (RW)        			
#define RG_IO_PASEL2_SEL_MASK				0xF	
#define RG_IO_PASEL2_SEL_SHIFT				0x4
#define RG_IO_INT_SEL_MASK					0xF
#define RG_IO_INT_SEL_SHIFT					0x0
                            				
// (0x04) TEST_CON4 (RW)    				
#define RG_DIO_SMT_MASK						0x1					
#define RG_DIO_SMT_SHIFT					0x5
#define RG_DIO_E2_MASK						0x1	
#define RG_DIO_E2_SHIFT						0x4
#define RG_DIO_E4_MASK						0x1	
#define RG_DIO_E4_SHIFT						0x3
#define RG_DIO_SR_MASK						0x1	
#define RG_DIO_SR_SHIFT						0x2
#define RG_SCK_PU_MASK						0x1	
#define RG_SCK_PU_SHIFT						0x1
#define RG_SCK_PD_MASK						0x1	
#define RG_SCK_PD_SHIFT						0x0
                        					
// (0x05) TEST_CON5 (RW)					
#define RG_SDA_E2_MASK						0x1	
#define RG_SDA_E2_SHIFT						0x7
#define RG_SDA_E4_MASK						0x1	
#define RG_SDA_E4_SHIFT						0x6
#define RG_SDA_PU_MASK						0x1	
#define RG_SDA_PU_SHIFT						0x5
#define RG_SDA_PD_MASK						0x1	
#define RG_SDA_PD_SHIFT						0x4
#define RG_INT_E2_MASK						0x1	
#define RG_INT_E2_SHIFT						0x3
#define RG_INT_E4_MASK						0x1
#define RG_INT_E4_SHIFT						0x2
#define RG_INT_PU_MASK						0x1	
#define RG_INT_PU_SHIFT						0x1
#define RG_INT_PD_MASK						0x1
#define RG_INT_PD_SHIFT						0x0
                        					
// (0x06) TEST_CON6 (RW)					
#define RG_DVS_PU_MASK						0x1	
#define RG_DVS_PU_SHIFT						0x5
#define RG_DVS_PD_MASK						0x1
#define RG_DVS_PD_SHIFT						0x4
#define RG_PASEL_PU_MASK					0x1
#define RG_PASEL_PU_SHIFT					0x3
#define RG_PASEL_PD_MASK					0x1
#define RG_PASEL_PD_SHIFT					0x2
#define RG_SYSRSTB_PU_MASK					0x1
#define RG_SYSRSTB_PU_SHIFT					0x1
#define RG_SYSRSTB_PD_MASK					0x1	
#define RG_SYSRSTB_PD_SHIFT					0x0
                            				
// (0x07) TEST_CON7 (RW)    				
#define RG_SRCLKEN_PU_MASK					0x1
#define RG_SRCLKEN_PU_SHIFT					0x3
#define RG_SRCLKEN_PD_MASK					0x1
#define RG_SRCLKEN_PD_SHIFT					0x2
#define RG_BL_PWM_PU_MASK					0x1	
#define RG_BL_PWM_PU_SHIFT					0x1
#define RG_BL_PWM_PD_MASK					0x1
#define RG_BL_PWM_PD_SHIFT					0x0

// (0x08) TEST_CON8 (RW)
#define RG_SDA_IO_CONFIG_MASK				0x1	
#define RG_SDA_IO_CONFIG_SHIFT				0x3
#define RG_TEST_STRUP_MASK					0x1
#define RG_TEST_STRUP_SHIFT					0x2
#define RG_OTP_W_MODE_MASK					0x1	
#define RG_OTP_W_MODE_SHIFT					0x1
#define RG_NANDTREE_MODE_MASK				0x1
#define RG_NANDTREE_MODE_SHIFT				0x0
                                			
// (0x09) TEST_CON9 (RW)        			
#define RG_TEST_AUXADC_MASK					0x1 			
#define RG_TEST_AUXADC_SHIFT				0x7
#define RG_TEST_FGPLL_MASK					0x1
#define RG_TEST_FGPLL_SHIFT					0x6
#define RG_TEST_FG1_MASK					0x1
#define RG_TEST_FG1_SHIFT					0x5
#define RG_TEST_FG2_MASK					0x1
#define RG_TEST_FG2_SHIFT					0x4
#define RG_TEST_IO_FG_SEL_MASK				0x1	
#define RG_TEST_IO_FG_SEL_SHIFT				0x3
#define RG_TEST_CLASSD_MASK					0x1	
#define RG_TEST_CLASSD_SHIFT				0x2
#define RG_TEST_DRIVER_MASK					0x1	
#define RG_TEST_DRIVER_SHIFT				0x1
#define RG_TEST_BOOST_MASK					0x1	
#define RG_TEST_BOOST_SHIFT					0x0

// (0x0A) TEST_CON10 (RO)
#define RO_MON_MASK							0xFF	
#define RO_MON_SHIFT						0x0
                            				
// (0x0B) TEST_CON11 (RO)   				
#define RO_DVS1_IN_MASK						0x1	
#define RO_DVS1_IN_SHIFT					0x7
#define RO_DVS2_IN_MASK						0x1
#define RO_DVS2_IN_SHIFT					0x6
#define RO_PASEL0_IN_MASK					0x1	
#define RO_PASEL0_IN_SHIFT					0x5
#define RO_PASEL1_IN_MASK					0x1	
#define RO_PASEL1_IN_SHIFT					0x4
#define RO_PASEL2_IN_MASK					0x1	
#define RO_PASEL2_IN_SHIFT					0x3
#define RO_SYSRSTB_IN_MASK					0x1	
#define RO_SYSRSTB_IN_SHIFT					0x2
#define RO_SRCLKEN_IN_MASK					0x1	
#define RO_SRCLKEN_IN_SHIFT					0x1
#define RO_BLPWM_IN_MASK					0x1	
#define RO_BLPWM_IN_SHIFT					0x0

// (0x0C) RST_CON0 (RW)
#define RG_PWRKEY_RST_EN_MASK				0x1
#define RG_PWRKEY_RST_EN_SHIFT				0x4
#define RG_HOMEKEY_RST_EN_MASK				0x1	
#define RG_HOMEKEY_RST_EN_SHIFT				0x3
#define RG_PWRKEY_RST_TD_MASK				0x3	
#define RG_PWRKEY_RST_TD_SHIFT				0x1
#define RG_PWRRST_TMR_DIS_MASK				0x1	
#define RG_PWRRST_TMR_DIS_SHIFT				0x0
                                			
// (0x0D) RST_CON1 (RW)         			
#define RG_RST_PART_SEL_MASK				0x1
#define RG_RST_PART_SEL_SHIFT				0x7
#define RG_OTP_MAN_RST_MASK					0x1
#define RG_OTP_MAN_RST_SHIFT				0x5
#define RG_PCHR_MAN_RST_EN_MASK				0x1
#define RG_PCHR_MAN_RST_EN_SHIFT			0x4
#define RG_PCHR_MAN_RST_MASK				0x1
#define RG_PCHR_MAN_RST_SHIFT				0x3
#define RG_STRUP_MAN_RST_EN_MASK			0x1
#define RG_STRUP_MAN_RST_EN_SHIFT			0x2
#define RG_SIF_TST_CK_DIS_MASK				0x1
#define RG_SIF_TST_CK_DIS_SHIFT				0x1
#define RG_SYSRSTB_EN_MASK					0x1	
#define RG_SYSRSTB_EN_SHIFT					0x0
                                	
// (0x14) TOP2_CON0 (RW)
#define RG_75K_EXT_SEL_MASK					0x1	
#define RG_75K_EXT_SEL_SHIFT				0x7
#define RG_FG_TST_CK_SEL_MASK				0x1	
#define RG_FG_TST_CK_SEL_SHIFT				0x6
#define RG_CHR1M_TST_CK_SEL_MASK			0x1
#define RG_CHR1M_TST_CK_SEL_SHIFT			0x5
#define RG_CLK_TST_MASK						0x1	
#define RG_CLK_TST_SHIFT					0x4
#define RG_AUXADC_CK_RST_MASK				0x1	
#define RG_AUXADC_CK_RST_SHIFT				0x3
#define RG_AUXADC_CK_SEL_MASK				0x7
#define RG_AUXADC_CK_SEL_SHIFT				0x0
                                    		
// (0x15) TOP2_CON1 (RW)            		
#define RG_10M_CK_DIV_RST_MASK				0x1
#define RG_10M_CK_DIV_RST_SHIFT				0x5
#define RG_FGADC_CK_PDN_MASK				0x1
#define RG_FGADC_CK_PDN_SHIFT				0x4
#define RG_OTPC_CK_PDN_MASK					0x1 	
#define RG_OTPC_CK_PDN_SHIFT				0x3
#define RG_BST_DRV_CK_PDN_MASK				0x1
#define RG_BST_DRV_CK_PDN_SHIFT				0x2
#define RG_SPK_CK_PDN_MASK					0x1
#define RG_SPK_CK_PDN_SHIFT					0x1
#define RG_PWMOC_CK_PDN_MASK				0x1
#define RG_PWMOC_CK_PDN_SHIFT				0x0
                                    		
// (0x16) CC_CTL1 (RW)              		
#define OC_GEAR_BVALID_DET_MASK				0x3	
#define OC_GEAR_BVALID_DET_SHIFT			0x6
#define OC_GEAR_VBATON_UNDET_MASK			0x3
#define OC_GEAR_VBATON_UNDET_SHIFT			0x4
#define OC_GEAR_LDO_MASK					0x3
#define OC_GEAR_LDO_SHIFT					0x0

// (0x17) INT2_RSV (RW)
#define RG_INT_RSV_MASK						0x1F	
#define RG_INT_RSV_SHIFT					0x3
#define POLARITY_BVALID_DET_MASK			0x1
#define POLARITY_BVALID_DET_SHIFT			0x2
#define POLARITY_VBATON_UNDET_MASK			0x1
#define POLARITY_VBATON_UNDET_SHIFT			0x1
#define POLARITY_MASK						0x1	
#define POLARITY_SHIFT						0x0

// (0x18) OC_PWMCTL1 (RW)
#define VPA_OC_WND_MASK						0x3	
#define VPA_OC_WND_SHIFT					0x6
#define VPA_OC_THD_MASK						0x3	
#define VPA_OC_THD_SHIFT					0x4
#define VRF18_OC_WND_MASK					0x3	
#define VRF18_OC_WND_SHIFT					0x2
#define VRF18_OC_THD_MASK					0x3	
#define VRF18_OC_THD_SHIFT					0x0
                            				
// (0x22) FLASH_CON0 (RW)   				
#define FLASH_RSV0_MASK						0x7	
#define FLASH_RSV0_SHIFT					0x5
#define FLASH_DIM_DUTY_MASK					0x1F	
#define FLASH_DIM_DUTY_SHIFT				0x0

// (0x23) FLASH_CON1 (RW)
#define FLASH_THER_SHDN_EN_MASK				0x1	
#define FLASH_THER_SHDN_EN_SHIFT			0x1
#define FLASH_EN_MASK						0x1
#define FLASH_EN_SHIFT						0x0
                                    		
// (0x24) FLASH_CON2 (RW)           		
#define FLASH_DIM_DIV_MASK					0xFF	
#define FLASH_DIM_DIV_SHIFT					0x0
                            				
// (0x25) FLASH_CON3 (RW)   				
#define FLASH_RSV1_MASK						0x1F			
#define FLASH_RSV1_SHIFT					0x3
#define FLASH_SEL_MASK						0x7	
#define FLASH_SEL_SHIFT						0x0
                                    		
// (0x26) FLASH_CON4 (RW)           		
#define FLASH_SFSTREN_MASK					0x1	
#define FLASH_SFSTREN_SHIFT					0x7
#define FLASH_SFSTR_MASK					0x3	
#define FLASH_SFSTR_SHIFT					0x4
#define FLASH_MODE_MASK						0x1 		
#define FLASH_MODE_SHIFT					0x0

// (0x27) KPLED_CON0 (RW)
#define KPLED_RSV0_MASK						0x7	
#define KPLED_RSV0_SHIFT					0x5
#define KPLED_DIM_DUTY_MASK					0x1F
#define KPLED_DIM_DUTY_SHIFT				0x0

// (0x28) KPLED_CON1 (RW)
#define KPLED_THER_SHDN_EN_MASK				0x1	
#define KPLED_THER_SHDN_EN_SHIFT			0x1
#define KPLED_EN_MASK						0x1	
#define KPLED_EN_SHIFT						0x0

// (0x29) KPLED_CON2 (RW)
#define KPLED_DIM_DIV_MASK					0xFF	
#define KPLED_DIM_DIV_SHIFT					0x0
                            				
// (0x2A) KPLED_CON3 (RW)   				
#define KPLED_RSV1_MASK						0x1F	
#define KPLED_RSV1_SHIFT					0x3
#define KPLED_SEL_MASK						0x7	
#define KPLED_SEL_SHIFT						0x0

// (0x2B) KPLED_CON4 (RW)
#define KPLED_SFSTREN_MASK					0x1	
#define KPLED_SFSTREN_SHIFT					0x7
#define KPLED_SFSTR_MASK					0x3	
#define KPLED_SFSTR_SHIFT					0x4
#define KPLED_MODE_MASK						0x1	
#define KPLED_MODE_SHIFT					0x0
                            				
// (0x2C) ISINKS_CON0 (RW)
#define ISINK_RSV0_MASK						0x7
#define ISINK_RSV0_SHIFT					0x5
#define ISINK_DIM0_DUTY_MASK				0xF	
#define ISINK_DIM0_DUTY_SHIFT				0x0

// (0x2D) ISINKS_CON1 (RW)
#define ISINK_DIM0_FSEL_MASK				0x1F
#define ISINK_DIM0_FSEL_SHIFT				0x0
                                			
// (0x2E) ISINKS_CON2 (RW)      			
#define ISINK_RSV1_MASK						0x7	
#define ISINK_RSV1_SHIFT					0x5
#define ISINK_DIM1_DUTY_MASK				0x1F
#define ISINK_DIM1_DUTY_SHIFT				0x0
                                			
// (0x2F) ISINKS_CON3 (RW)      			
#define ISINK_DIM1_FSEL_MASK				0x1F
#define ISINK_DIM1_FSEL_SHIFT				0x0

// (0x30) ISINKS_CON4 (RW)
#define ISINK_RSV2_MASK						0x7	
#define ISINK_RSV2_SHIFT					0x5
#define ISINK_DIM2_DUTY_MASK				0x1F	
#define ISINK_DIM2_DUTY_SHIFT				0x0
                                			
// (0x31) ISINKS_CON5 (RW)      			
#define ISINK_DIM2_FSEL_MASK				0x1F
#define ISINK_DIM2_FSEL_SHIFT				0x0

// (0x32) ISINKS_CON6 (RW)
#define ISINK_RSV3_MASK						0x3	
#define ISINK_RSV3_SHIFT					0x6
#define ISINKS_CH5_EN_MASK					0x1	
#define ISINKS_CH5_EN_SHIFT					0x5
#define ISINKS_CH4_EN_MASK					0x1	
#define ISINKS_CH4_EN_SHIFT					0x4
#define ISINKS_CH3_EN_MASK					0x1	
#define ISINKS_CH3_EN_SHIFT					0x3
#define ISINKS_CH2_EN_MASK					0x1	
#define ISINKS_CH2_EN_SHIFT					0x2
#define ISINKS_CH1_EN_MASK					0x1	
#define ISINKS_CH1_EN_SHIFT					0x1
#define ISINKS_CH0_EN_MASK					0x1
#define ISINKS_CH0_EN_SHIFT					0x0

// (0x33) ISINKS_CON7 (RW)
#define ISINK_RSV4_MASK						0x3	
#define ISINK_RSV4_SHIFT					0x6
#define ISINKS_CH5_CABC_EN_MASK				0x1	
#define ISINKS_CH5_CABC_EN_SHIFT			0x5
#define ISINKS_CH4_CABC_EN_MASK				0x1 
#define ISINKS_CH4_CABC_EN_SHIFT			0x4
#define ISINKS_CH3_CABC_EN_MASK				0x1	
#define ISINKS_CH3_CABC_EN_SHIFT			0x3
#define ISINKS_CH2_CABC_EN_MASK				0x1	
#define ISINKS_CH2_CABC_EN_SHIFT			0x2
#define ISINKS_CH1_CABC_EN_MASK				0x1	
#define ISINKS_CH1_CABC_EN_SHIFT			0x1
#define ISINKS_CH0_CABC_EN_MASK				0x1	
#define ISINKS_CH0_CABC_EN_SHIFT			0x0

// (0x34) ISINKS_CON8 (RW)
#define ISINKS_CH0_STEP_MASK				0x7	
#define ISINKS_CH0_STEP_SHIFT				0x4
#define ISINKS_CH0_MODE_MASK				0x3	
#define ISINKS_CH0_MODE_SHIFT				0x0
                                			
// (0x35) ISINKS_CON9 (RW)      			
#define ISINKS_CH1_STEP_MASK				0x7
#define ISINKS_CH1_STEP_SHIFT				0x4
#define ISINKS_CH1_MODE_MASK				0x3	
#define ISINKS_CH1_MODE_SHIFT				0x0
                                			
// (0x36) ISINKS_CON10 (RW)     			
#define ISINKS_CH2_STEP_MASK				0x7	
#define ISINKS_CH2_STEP_SHIFT				0x4
#define ISINKS_CH2_MODE_MASK				0x3	
#define ISINKS_CH2_MODE_SHIFT				0x0
                                			
// (0x37) ISINKS_CON11 (RW)     			
#define ISINKS_CH3_STEP_MASK				0x7
#define ISINKS_CH3_STEP_SHIFT				0x4
#define ISINKS_CH3_MODE_MASK				0x3	
#define ISINKS_CH3_MODE_SHIFT				0x0
                                			
// (0x38) ISINKS_CON12 (RW)     			
#define ISINKS_CH4_STEP_MASK				0x7
#define ISINKS_CH4_STEP_SHIFT				0x4
#define ISINKS_CH4_MODE_MASK				0x3	
#define ISINKS_CH4_MODE_SHIFT				0x0

// (0x39) ISINKS_CON13 (RW)
#define ISINKS_CH5_STEP_MASK				0x7
#define ISINKS_CH5_STEP_SHIFT				0x4
#define ISINKS_CH5_MODE_MASK				0x3	
#define ISINKS_CH5_MODE_SHIFT				0x0

// (0x3A) ISINKS_CON14 (RW)
#define IBIAS_TRIM_EN_MASK					0x1
#define IBIAS_TRIM_EN_SHIFT					0x6
#define ISINKS_VREF_CAL_MASK				0x1F
#define ISINKS_VREF_CAL_SHIFT				0x0

// (0x3B) ISINKS_CON15 (RW)
#define ISINK_RSV5_MASK						0xF	
#define ISINK_RSV5_SHIFT					0x4
#define ISINKS_RSV_MASK						0xF	
#define ISINKS_RSV_SHIFT					0x0

// (0x3C) ISINKS_CON16 (RW)
#define DRV_RSV0_MASK						0xFF	
#define DRV_RSV0_SHIFT						0x0

// (0x3F) BOOST_CON0 (RW)
#define BOOST_ISINK_HW_SEL_MASK				0x1	
#define BOOST_ISINK_HW_SEL_SHIFT			0x7
#define BOOST_MODE_MASK						0x3	
#define BOOST_MODE_SHIFT					0x4
#define BOOST_CABC_EN_MASK					0x1	
#define BOOST_CABC_EN_SHIFT					0x2
#define BOOST_EN_MASK						0x1	
#define BOOST_EN_SHIFT						0x0
                            				
// (0x40) BOOST_CON1 (RW)   				
#define BOOST_SR_NMOS_MASK					0x3	
#define BOOST_SR_NMOS_SHIFT					0x6
#define BOOST_VRSEL_MASK					0xF	
#define BOOST_VRSEL_SHIFT					0x0
                            				
// (0x41) BOOST_CON2 (RW)
#define BOOST_RC_MASK						0x3	
#define BOOST_RC_SHIFT						0x4
#define BOOST_CS_MASK						0x3	
#define BOOST_CS_SHIFT						0x2
#define BOOST_CC_MASK						0x3	
#define BOOST_CC_SHIFT						0x0

// (0x42) BOOST_CON3 (RW)
#define BOOST_SLP_MASK						0x3
#define BOOST_SLP_SHIFT						0x2
#define BOOST_CL_MASK						0x3	
#define BOOST_CL_SHIFT						0x0

// (0x43) BOOST_CON4 (RW)
#define BOOST_SS_MASK						0x7	
#define BOOST_SS_SHIFT						0x4
#define BOOST_RSV_MASK						0xF	
#define BOOST_RSV_SHIFT						0x0

// (0x46) SPK_CON0 (RW)
#define SPK_THER_SHDN_L_EN_MASK				0x1
#define SPK_THER_SHDN_L_EN_SHIFT			0x6
#define SPK_TRIM_EN_L_MASK					0x1	
#define SPK_TRIM_EN_L_SHIFT					0x4
#define SPKMODE_L_MASK						0x1
#define SPKMODE_L_SHIFT						0x2
#define SPK_EN_L_MASK						0x1	
#define SPK_EN_L_SHIFT						0x0

// (0x47) SPK_CON1 (RW)
#define SPK_OC_EN_L_MASK					0x1
#define SPK_OC_EN_L_SHIFT					0x7
#define SPKAB_OC_EN_L_MASK					0x1
#define SPKAB_OC_EN_L_SHIFT					0x6
#define SPK_OC_SHDN_DL_MASK					0x1	
#define SPK_OC_SHDN_DL_SHIFT				0x4
#define SPK_VOL_L_MASK						0x7
#define SPK_VOL_L_SHIFT						0x0
                        					
// (0x48) SPK_CON2 (RO/RW)      			
#define SPK_RSV0_MASK						0x3F	
#define SPK_RSV0_SHIFT						0x2
#define SPK_AB_OC_L_DEG_MASK				0x1	
#define SPK_AB_OC_L_DEG_SHIFT				0x1
#define SPK_D_OC_L_DEG_MASK					0x1	
#define SPK_D_OC_L_DEG_SHIFT				0x0

// (0x49) SPK_CON3 (RO/RW)
#define SPK_OFFSET_L_OV_MASK				0x1	
#define SPK_OFFSET_L_OV_SHIFT				0x7
#define SPK_OFFSET_L_MODE_MASK				0x1	
#define SPK_OFFSET_L_MODE_SHIFT				0x6
#define SPK_LEAD_L_SW_MASK					0x1	
#define SPK_LEAD_L_SW_SHIFT					0x5
#define SPK_OFFSET_L_SW_MASK				0x1F	
#define SPK_OFFSET_L_SW_SHIFT				0x0
                                			
// (0x4A) SPK_CON4 (RO)
#define SPK_TRIM_DONE_L_MASK				0x1	
#define SPK_TRIM_DONE_L_SHIFT				0x7
#define SPK_LEAD_L_FLAG_MASK				0x1	
#define SPK_LEAD_L_FLAG_SHIFT				0x6
#define SPK_LEAD_L_FLAG_DEG_MASK			0x1
#define SPK_LEAD_L_FLAG_DEG_SHIFT			0x5
#define SPK_OFFSET_L_MASK					0x1F	
#define SPK_OFFSET_L_SHIFT					0x0

// (0x4B) SPK_CON5 (RW)
#define SPK_RSV1_MASK						0x1	
#define SPK_RSV1_SHIFT						0x7
#define SPKRCV_EN_L_MASK					0x1	
#define SPKRCV_EN_L_SHIFT					0x6
#define SPKAB_OBIAS_L_MASK					0x3
#define SPKAB_OBIAS_L_SHIFT					0x4
#define SPK_SLEW_L_MASK						0x3	
#define SPK_SLEW_L_SHIFT					0x2
#define SPK_FORCE_EN_L_MASK					0x1	
#define SPK_FORCE_EN_L_SHIFT				0x1
#define SPK_INTG_RST_L_MASK					0x1
#define SPK_INTG_RST_L_SHIFT				0x0

// (0x4C) SPK_CON6 (RW)
#define SPK_THER_SHDN_R_EN_MASK				0x1
#define SPK_THER_SHDN_R_EN_SHIFT			0x6
#define SPK_TRIM_EN_R_MASK					0x1
#define SPK_TRIM_EN_R_SHIFT					0x4
#define SPKMODE_R_MASK						0x1	
#define SPKMODE_R_SHIFT						0x2
#define SPK_EN_R_MASK						0x1
#define SPK_EN_R_SHIFT						0x0
                                    		
// (0x4D) SPK_CON7 (RW)             		
#define SPK_OC_EN_R_MASK					0x1	
#define SPK_OC_EN_R_SHIFT					0x7
#define SPKAB_OC_EN_R_MASK					0x1	
#define SPKAB_OC_EN_R_SHIFT					0x6
#define SPK_OC_SHDN_DR_MASK					0x1
#define SPK_OC_SHDN_DR_SHIFT				0x4
#define SPK_VOL_R_MASK						0x7
#define SPK_VOL_R_SHIFT						0x0

// (0x4E) SPK_CON8 (RO/RW)
#define SPK_RSV2_MASK						0x3F	
#define SPK_RSV2_SHIFT						0x2
#define SPK_AB_OC_R_DEG_MASK				0x1
#define SPK_AB_OC_R_DEG_SHIFT				0x1
#define SPK_D_OC_R_DEG_MASK					0x1
#define SPK_D_OC_R_DEG_SHIFT				0x0

// (0x4F) SPK_CON9 (RO/RW)
#define SPK_OFFSET_R_OV_MASK				0x1
#define SPK_OFFSET_R_OV_SHIFT				0x7
#define SPK_OFFSET_R_MODE_MASK				0x1
#define SPK_OFFSET_R_MODE_SHIFT				0x6
#define SPK_LEAD_R_SW_MASK					0x1	
#define SPK_LEAD_R_SW_SHIFT					0x5
#define SPK_OFFSET_R_SW_MASK				0x1F	
#define SPK_OFFSET_R_SW_SHIFT				0x0

// (0x50) SPK_CON10 (RO)
#define SPK_TRIM_DONE_R_MASK				0x1	
#define SPK_TRIM_DONE_R_SHIFT				0x7
#define SPK_LEAD_R_FLAG_MASK				0x1	
#define SPK_LEAD_R_FLAG_SHIFT				0x6
#define SPK_LEAD_R_FLAG_DEG_MASK			0x1
#define SPK_LEAD_R_FLAG_DEG_SHIFT			0x5
#define SPK_OFFSET_R_MASK					0x1F	
#define SPK_OFFSET_R_SHIFT					0x0

// (0x51) SPK_CON11 (RW)
#define SPK_RSV3_MASK						0x1	
#define SPK_RSV3_SHIFT						0x7
#define SPKRCV_EN_R_MASK					0x1
#define SPKRCV_EN_R_SHIFT					0x6
#define SPKAB_OBIAS_R_MASK					0x3	
#define SPKAB_OBIAS_R_SHIFT					0x4
#define SPK_SLEW_R_MASK						0x3	
#define SPK_SLEW_R_SHIFT					0x2
#define SPK_FORCE_EN_R_MASK					0x1	
#define SPK_FORCE_EN_R_SHIFT				0x1
#define SPK_INTG_RST_R_MASK					0x1
#define SPK_INTG_RST_R_SHIFT				0x0

// (0x52) SPK_CON12 (RW)
#define SPK_OC_AUTOFF_MASK					0x1	
#define SPK_OC_AUTOFF_SHIFT					0x3
#define SPK_OC_DGLH_MASK					0x3	
#define SPK_OC_DGLH_SHIFT					0x1
#define SPK_OCTH_D_MASK						0x1	
#define SPK_OCTH_D_SHIFT					0x0
                            				
// (0x53) SPK_CON13 (RW)
#define SPK_OC_WND_MASK						0x3
#define SPK_OC_WND_SHIFT					0x4
#define SPK_OC_THD_MASK						0x3
#define SPK_OC_THD_SHIFT					0x0

// (0x54) SPK_CON14 (RW)
#define SPK_TRIM_DIV_MASK					0x3
#define SPK_TRIM_DIV_SHIFT					0x4
#define SPK_TRIM_DEG_MASK					0x3	
#define SPK_TRIM_DEG_SHIFT					0x0
                            				
// (0x55) SPK_CON15 (RW)    				
#define SPKAB_OBIAS_MASK					0x3	
#define SPKAB_OBIAS_SHIFT					0x6
#define SPKAB_FB_ATT_MASK					0x3
#define SPKAB_FB_ATT_SHIFT					0x2
#define SPKAB_OVDRV_MASK					0x1	
#define SPKAB_OVDRV_SHIFT					0x0
                            				
// (0x56) SPK_CON16 (RW)    				
#define SPK_FBRC_EN_MASK					0x1	
#define SPK_FBRC_EN_SHIFT					0x6
#define SPK_IBIAS_SEL_MASK					0x3	
#define SPK_IBIAS_SEL_SHIFT					0x4
#define SPK_VCM_IBSEL_MASK					0x1	
#define SPK_VCM_IBSEL_SHIFT					0x3
#define SPK_VCM_SEL_MASK					0x1
#define SPK_VCM_SEL_SHIFT					0x2
#define SPK_EN_VIEW_CLK_MASK				0x1	
#define SPK_EN_VIEW_CLK_SHIFT				0x1
#define SPK_EN_VIEW_VCM_MASK				0x1	
#define SPK_EN_VIEW_VCM_SHIFT				0x0

// (0x57) SPK_CON17 (RW)
#define SPK_CCODE_MASK						0xF	
#define SPK_CCODE_SHIFT						0x4
#define SPK_BTL_SET_MASK					0x3	
#define SPK_BTL_SET_SHIFT					0x0
                            				
// (0x58) SPK_CON18 (RW)
#define SPK_RSV_MASK						0xF
#define SPK_RSV_SHIFT						0x0
                        					
// (0x59) SPK_CON19 (RW)					
#define SPK_TD1_MASK						0x3
#define SPK_TD1_SHIFT						0x4
#define SPK_TD2_MASK						0x3	
#define SPK_TD2_SHIFT						0x0

// (0x5A) SPK_CON20 (RW)
#define SPK_DEPOP_EN_L_SW_MASK				0x1
#define SPK_DEPOP_EN_L_SW_SHIFT				0x7
#define SPK_DEPOP_EN_R_SW_MASK				0x1	
#define SPK_DEPOP_EN_R_SW_SHIFT				0x6
#define SPKMODE_L_SW_MASK					0x1				
#define SPKMODE_L_SW_SHIFT					0x5
#define SPKMODE_R_SW_MASK					0x1	
#define SPKMODE_R_SW_SHIFT					0x4
#define SPK_RST_L_SW_MASK					0x1	
#define SPK_RST_L_SW_SHIFT					0x3
#define SPK_RST_R_SW_MASK					0x1
#define SPK_RST_R_SW_SHIFT					0x2
#define SPK_EN_MODE_MASK					0x1	
#define SPK_EN_MODE_SHIFT					0x0

// (0x5B) SPK_CON21 (RW)
#define SPK_TRIM_EN_L_SW_MASK				0x1
#define SPK_TRIM_EN_L_SW_SHIFT				0x7
#define SPK_TRIM_EN_R_SW_MASK				0x1
#define SPK_TRIM_EN_R_SW_SHIFT				0x6
#define SPK_OUTSTG_EN_L_SW_MASK				0x1	
#define SPK_OUTSTG_EN_L_SW_SHIFT			0x5
#define SPK_OUTSTG_EN_R_SW_MASK				0x1	
#define SPK_OUTSTG_EN_R_SW_SHIFT			0x4
#define SPK_EN_L_SW_MASK					0x1	
#define SPK_EN_L_SW_SHIFT					0x3
#define SPK_EN_R_SW_MASK					0x1	
#define SPK_EN_R_SW_SHIFT					0x2
#define SPK_VCM_FAST_SW_MASK				0x1	
#define SPK_VCM_FAST_SW_SHIFT				0x0
                                			
// (0x5C) SPK_CON22 (RW)           	
#define SPK_TRIM_STOP_L_SW_MASK				0x1	
#define SPK_TRIM_STOP_L_SW_SHIFT			0x1
#define SPK_TRIM_STOP_R_SW_MASK				0x1	
#define SPK_TRIM_STOP_R_SW_SHIFT			0x0
                                   	
// (0x5F) ASW_CON0 (RW)            	
#define RG_ANA_SW_SEL_MASK					0x1	
#define RG_ANA_SW_SEL_SHIFT					0x0
                            				
// (0x60) FGPLL_CON0 (RW)   				
#define FGPLL_PDIV1_MASK					0xF	
#define FGPLL_PDIV1_SHIFT					0x4
#define FGPLL_PDIV1_EN_MASK					0x1
#define FGPLL_PDIV1_EN_SHIFT				0x3
#define FGPLL_BS_RST_MASK					0x1
#define FGPLL_BS_RST_SHIFT					0x1
#define FGPLL_EN_MASK						0x1 				
#define FGPLL_EN_SHIFT						0x0        	

// (0x61) FGPLL_CON1 (RW)
#define FGPLL_DIV1_MASK						0x3F	
#define FGPLL_DIV1_SHIFT					0x0
                            				
// (0x62) FGPLL_CON2 (RW)   				
#define FGPLL_BC_MASK						0x3	
#define FGPLL_BC_SHIFT						0x4
#define FGPLL_BP_MASK						0x3	
#define FGPLL_BP_SHIFT						0x2
#define FGPLL_BR_MASK						0x3	
#define FGPLL_BR_SHIFT						0x0
                            				
// (0x63) FGPLL_CON3 (RW)   				
#define FGPLL_CDIV_MASK						0x7					
#define FGPLL_CDIV_SHIFT					0x5
#define FGPLL_VCOBAND_MASK					0x7
#define FGPLL_VCOBAND_SHIFT					0x2
#define FGPLL_CKO_SEL_MASK					0x3	
#define FGPLL_CKO_SEL_SHIFT					0x0
                            				
// (0x64) FGPLL_CON4 (RW)   				
#define FGPLL_IBSEL_MASK					0x3	
#define FGPLL_IBSEL_SHIFT					0x6
#define FGPLL_RLATCH_EN_MASK				0x1
#define FGPLL_RLATCH_EN_SHIFT				0x5
#define FGPLL_CKDRV_EN_MASK					0x1	
#define FGPLL_CKDRV_EN_SHIFT				0x4
#define FGPLL_VCT_EN_MASK					0x1	
#define FGPLL_VCT_EN_SHIFT					0x3
#define FGPLL_CKT_SEL_MASK					0x3	
#define FGPLL_CKT_SEL_SHIFT					0x1
#define FGPLL_CKT_EN_MASK					0x1	
#define FGPLL_CKT_EN_SHIFT					0x0

// (0x65) FGPLL_CON5 (RW)
#define FGPLL_RSVA_MASK						0xFF	
#define FGPLL_RSVA_SHIFT					0x0
                            				
// (0x66) FGPLL_CON6 (RW)   				
#define FGPLL_RSVB_MASK						0xFF	
#define FGPLL_RSVB_SHIFT					0x0
                            				
// (0x69) FGADC_CON0 (RW)   				
#define FG_CLKSRC_MASK						0x1	
#define FG_CLKSRC_SHIFT						0x7
#define FG_AUTOCALRATE_MASK					0x7
#define FG_AUTOCALRATE_SHIFT				0x4
#define FG_CAL_MASK							0x3	
#define FG_CAL_SHIFT						0x2
#define FG_VMODE_MASK						0x1	
#define FG_VMODE_SHIFT						0x1
#define FG_ON_MASK							0x1	
#define FG_ON_SHIFT							0x0

// (0x6A) FGADC_CON1 (RO/RW)
#define FG_SW_RSTCLR_MASK					0x1	
#define FG_SW_RSTCLR_SHIFT					0x7
#define FG_CHARGE_RST_MASK					0x1	
#define FG_CHARGE_RST_SHIFT					0x6
#define FG_TIME_RST_MASK					0x1	
#define FG_TIME_RST_SHIFT					0x5
#define FG_OFFSET_RST_MASK					0x1	
#define FG_OFFSET_RST_SHIFT					0x4
#define FG_SW_CLEAR_MASK					0x1	
#define FG_SW_CLEAR_SHIFT					0x3
#define FG_LATCHDATA_ST_MASK				0x1
#define FG_LATCHDATA_ST_SHIFT				0x2
#define FG_SW_READ_PRE_MASK					0x1	
#define FG_SW_READ_PRE_SHIFT				0x1
#define FG_SW_CR_MASK						0x1	
#define FG_SW_CR_SHIFT						0x0

// (0x6B) FGADC_CON2 (RO)
#define FG_CAR_35_32_MASK					0xF	
#define FG_CAR_35_32_SHIFT					0x0
                            				
// (0x6C) FGADC_CON3 (RO)   				
#define FG_CAR_31_24_MASK					0xFF	
#define FG_CAR_31_24_SHIFT					0x0
                            				
// (0x6D) FGADC_CON4 (RO)   				
#define FG_CAR_23_16_MASK					0xFF	
#define FG_CAR_23_16_SHIFT					0x0
                            				
// (0x6E) FGADC_CON5 (RO)   				
#define FG_CAR_15_08_MASK					0xFF
#define FG_CAR_15_08_SHIFT					0x0
                            				
// (0x6F) FGADC_CON6 (RO)   				
#define FG_CAR_07_00_MASK					0xFF	
#define FG_CAR_07_00_SHIFT					0x0
                            				
// (0x70) FGADC_CON7 (RO)   				
#define FG_NTER_29_24_MASK					0x3F
#define FG_NTER_29_24_SHIFT					0x0
                            				
// (0x71) FGADC_CON8 (RO)   				
#define FG_NTER_23_16_MASK					0xFF	
#define FG_NTER_23_16_SHIFT					0x0
                            				
// (0x72) FGADC_CON9 (RO)   				
#define FG_NTER_15_08_MASK					0xFF	
#define FG_NTER_15_08_SHIFT					0x0

// (0x73) FGADC_CON10 (RO)
#define FG_NTER_07_00_MASK					0xFF
#define FG_NTER_07_00_SHIFT					0x0
                            				
// (0x74) FGADC_CON11 (RW)  				
#define FG_BLTR_15_08_MASK					0xFF
#define FG_BLTR_15_08_SHIFT					0x0
                            				
// (0x75) FGADC_CON12 (RW)  				
#define FG_BLTR_07_00_MASK					0xFF	
#define FG_BLTR_07_00_SHIFT					0x0
                            				
// (0x76) FGADC_CON13 (RW)  				
#define FG_BFTR_15_08_MASK					0xFF	
#define FG_BFTR_15_08_SHIFT					0x0
                            				
// (0x77) FGADC_CON14 (RW)  				
#define FG_BFTR_07_00_MASK					0xFF
#define FG_BFTR_07_00_SHIFT					0x0
                                    		
// (0x78) FGADC_CON15 (RO)          		
#define FG_CURRENT_OUT_15_08_MASK			0xFF	
#define FG_CURRENT_OUT_15_08_SHIFT			0x0
                                    		
// (0x79) FGADC_CON16 (RO)          		
#define FG_CURRENT_OUT_07_00_MASK			0xFF
#define FG_CURRENT_OUT_07_00_SHIFT			0x0

// (0x7A) FGADC_CON17 (RW)
#define FG_ADJUST_OFFSET_VALUE_15_08_MASK	0xFF	
#define FG_ADJUST_OFFSET_VALUE_15_08_SHIFT	0x0

// (0x7B) FGADC_CON18 (RW)
#define FG_ADJUST_OFFSET_VALUE_07_00_MASK	0xFF	
#define FG_ADJUST_OFFSET_VALUE_07_00_SHIFT	0x0

// (0x7C) FGADC_CON19 (RO)
#define FG_OFFSET_15_08_MASK				0xFF	
#define FG_OFFSET_15_08_SHIFT				0x0
                                			
// (0x7D) FGADC_CON20 (RO)      			
#define FG_OFFSET_07_00_MASK				0xFF	
#define FG_OFFSET_07_00_SHIFT				0x0
                                			
// (0x7E) FGADC_CON21 (RW)      			
#define FG_RSV0_MASK						0xF	
#define FG_RSV0_SHIFT						0x4
#define FG_ANALOGTEST_MASK					0xF
#define FG_ANALOGTEST_SHIFT					0x0
                            	
// (0x7F) FGADC_CON22 (RW)  	
#define FG_SPARE_MASK						0xFF
#define FG_SPARE_SHIFT						0x0
                                			
// (0x80) FGADC_CON23 (RW)      			
#define FG_BLTR_BFTR_EN_MASK				0x1	
#define FG_BLTR_BFTR_EN_SHIFT				0x7
#define FG_ADC_AUTORST_MASK					0x1	
#define FG_ADC_AUTORST_SHIFT				0x6
#define FG_ADJ_OFFSET_EN_MASK				0x1	
#define FG_ADJ_OFFSET_EN_SHIFT				0x4
#define FG_OSR_MASK							0x7	
#define FG_OSR_SHIFT						0x0
                                			
// (0x81) FGADC_CON24 (RW)      			
#define VOL_OSR_MASK						0x7	
#define VOL_OSR_SHIFT						0x0
                        					
// (0x82) FGADC_CON25 (RO/RW)   			
#define FG_ADC_RSTDETECT_MASK				0x1
#define FG_ADC_RSTDETECT_SHIFT				0x7
#define FG_H_INT_STS_MASK					0x1
#define FG_H_INT_STS_SHIFT					0x5
#define FG_L_INT_STS_MASK					0x1	
#define FG_L_INT_STS_SHIFT					0x4
#define VOL_FIR1BYPASS_MASK					0x1	
#define VOL_FIR1BYPASS_SHIFT				0x2
#define FG_FIR2BYPASS_MASK					0x1	
#define FG_FIR2BYPASS_SHIFT					0x1
#define FG_FIR1BYPASS_MASK					0x1	
#define FG_FIR1BYPASS_SHIFT					0x0

// (0x83) FGADC_CON26 (RO)
#define VOL_CURRENT_OUT_15_08_MASK			0xFF	
#define VOL_CURRENT_OUT_15_08_SHIFT			0x0
                                    		
// (0x84) FGADC_CON27 (RO)          		
#define VOL_CURRENT_OUT_07_00_MASK			0xFF
#define VOL_CURRENT_OUT_07_00_SHIFT			0x0

// (0x85) FGADC_CON28 (RO)
#define FG_CIC2_15_08_MASK					0xFF
#define FG_CIC2_15_08_SHIFT					0x0
                            				
// (0x86) FGADC_CON29 (RO)  				
#define FG_CIC2_07_00_MASK					0xFF	
#define FG_CIC2_07_00_SHIFT					0x0

// (0x87) FGADC_CON30 (RW)
#define FG_RSV1_MASK						0x7
#define FG_RSV1_SHIFT						0x5
#define FG_VMODE_SW_MASK					0x1
#define FG_VMODE_SW_SHIFT					0x4
#define FG_FGADC_EN_SW_MASK					0x1
#define FG_FGADC_EN_SW_SHIFT				0x3
#define FG_FGCAL_EN_SW_MASK					0x1
#define FG_FGCAL_EN_SW_SHIFT				0x2
#define FG_RST_SW_MASK						0x1	
#define FG_RST_SW_SHIFT						0x1
#define FG_MODE_MASK						0x1
#define FG_MODE_SHIFT						0x0

// (0x88) FGADC_CON31 (RO)
#define FG_MON_MASK							0xFF	
#define FG_MON_SHIFT						0x0

// (0x89) FGADC_CON32 (RW)
#define FG_RSV2_MASK						0xFF
#define FG_RSV2_SHIFT						0x0

// (0x8C) OTPC_CON0 (RO)
#define RG_OTP_PDO_7_0_MASK					0xFF	
#define RG_OTP_PDO_7_0_SHIFT				0x0
                                			
// (0x8D) OTPC_CON1 (RO)        			
#define RG_OTP_PDO_15_8_MASK				0xFF
#define RG_OTP_PDO_15_8_SHIFT				0x0
                                			
// (0x8E) OTPC_CON2 (RO)        			
#define RG_OTP_PDO_23_16_MASK				0xFF	
#define RG_OTP_PDO_23_16_SHIFT				0x0
                                			
// (0x8F) OTPC_CON3 (RO)        			
#define RG_OTP_PDO_31_24_MASK				0xFF	
#define RG_OTP_PDO_31_24_SHIFT				0x0
                                			
// (0x90) OTPC_CON4 (RO)        			
#define RG_OTP_PDO_39_32_MASK				0xFF
#define RG_OTP_PDO_39_32_SHIFT				0x0
                                			
// (0x91) OTPC_CON5 (RO)        			
#define RG_OTP_PDO_47_40_MASK				0xFF	
#define RG_OTP_PDO_47_40_SHIFT				0x0
                                			
// (0x92) OTPC_CON6 (RO)        			
#define RG_OTP_PDO_55_48_MASK				0xFF
#define RG_OTP_PDO_55_48_SHIFT				0x0
                                			
// (0x93) OTPC_CON7 (RO)        			
#define RG_OTP_PDO_63_56_MASK				0xFF	
#define RG_OTP_PDO_63_56_SHIFT				0x0
                                			
// (0x94) OTPC_CON8 (RW)
#define RG_OTP_PDIN_MASK					0xFF	
#define RG_OTP_PDIN_SHIFT					0x0
                            				
// (0x95) OTPC_CON9 (RW)    				
#define RG_OTP_PA_MASK						0x3	
#define RG_OTP_PA_SHIFT						0x6
#define RG_OTP_PTM_MASK						0x3	
#define RG_OTP_PTM_SHIFT					0x4
#define RG_OTP_PWE_MASK						0x3	
#define RG_OTP_PWE_SHIFT					0x2
#define RG_OTP_PPROG_MASK					0x1	
#define RG_OTP_PPROG_SHIFT					0x1
#define RG_OTP_READ_MASK					0x1	
#define RG_OTP_READ_SHIFT					0x0

// (0x96) OTPC_CON10 (RW)
#define RG_OTP_READ_PRD_MASK				0x3	
#define RG_OTP_READ_PRD_SHIFT				0x6
                                			
// (0x97) OTPC_CON11 (RW)       			
#define RG_OTP_TEST_SEL_MASK				0x7
#define RG_OTP_TEST_SEL_SHIFT				0x5
#define RG_OTP_SKIP_OUT_MASK				0x1	
#define RG_OTP_SKIP_OUT_SHIFT				0x4
#define RG_OTP_OUT_SEL_MASK					0x3
#define RG_OTP_OUT_SEL_SHIFT				0x2
#define RG_OTP_RSV_MASK						0x3	
#define RG_OTP_RSV_SHIFT					0x0
                                			
// (0x98) OTPC_CON12 (RW)       			
#define RG_OTP_VAL_7_0_MASK					0xFF
#define RG_OTP_VAL_7_0_SHIFT				0x0
                                			
// (0x99) OTPC_CON13 (RW)       			
#define RG_OTP_VAL_15_8_MASK				0xFF
#define RG_OTP_VAL_15_8_SHIFT				0x0
                                			
// (0x9A) OTPC_CON14 (RW)       			
#define RG_OTP_VAL_23_16_MASK				0xFF
#define RG_OTP_VAL_23_16_SHIFT				0x0
                                			
// (0x9B) OTPC_CON15 (RW)       			
#define RG_OTP_VAL_31_24_MASK				0xFF	
#define RG_OTP_VAL_31_24_SHIFT				0x0
                                			
// (0x9C) OTPC_CON16 (RW)       			
#define RG_OTP_VAL_39_32_MASK				0xFF	
#define RG_OTP_VAL_39_32_SHIFT				0x0
                                			
// (0x9D) OTPC_CON17 (RW)       			
#define RG_OTP_VAL_47_40_MASK				0xFF	
#define RG_OTP_VAL_47_40_SHIFT				0x0
                                			
// (0x9E) OTPC_CON18 (RW)       			
#define RG_OTP_VAL_55_48_MASK				0xFF
#define RG_OTP_VAL_55_48_SHIFT				0x0
                                			
// (0x9F) OTPC_CON19 (RW)       			
#define RG_OTP_VAL_63_56_MASK				0xFF
#define RG_OTP_VAL_63_56_SHIFT				0x0

// (0xA0) OTPC_CON20 (RO/RW)
#define RG_OTP_BUSY_MASK					0x1
#define RG_OTP_BUSY_SHIFT					0x7
#define RG_OTP_VLD_MASK						0x1
#define RG_OTP_VLD_SHIFT					0x6
#define RG_OTP_READ_RDY_BYPASS_MASK			0x1	
#define RG_OTP_READ_RDY_BYPASS_SHIFT		0x3

// (0xA1) OTPC_CON21 (RW)
#define RG_OTP_W_LOCK_MASK					0x1	
#define RG_OTP_W_LOCK_SHIFT					0x7
#define RG_OTP_W_LOCK_KEY_TOG_MASK			0x1
#define RG_OTP_W_LOCK_KEY_TOG_SHIFT			0x4
#define RG_OTP_W_LOCK_KEY_MASK				0xF	
#define RG_OTP_W_LOCK_KEY_SHIFT				0x0

// (0xA4) I2C_CON0 (RW)
#define I2C_CON0_ADDR 					    0xA4

#define SCL_DE_MASK							0x1F	
#define SCL_DE_SHIFT						0x0
                        					
// (0xA5) I2C_CON1 (RW) 					
#define I2C_CON1_ADDR 					    0xA5

#define SDA_DE_MASK							0x1F	
#define SDA_DE_SHIFT						0x0

#endif //#if defined(PMIC_6329_REG_API)

#endif // #ifndef __DCL_PMIC6329_HW_H_STRUCT__
