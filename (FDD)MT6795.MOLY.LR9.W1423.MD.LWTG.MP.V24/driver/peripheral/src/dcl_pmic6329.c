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
 *  dcl_pmic6329.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is pmic6329 driver
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "i2c_dual_sw.h"
#include "kal_public_api.h"

#if defined(PMIC_6329_REG_API)

// Define to check race condition
// #define PMIC6329_RACE_CONDITION_CHECK

// Define to mask IRQ when performing PMIC APIs
#define PMIC6329_MASKIRQ_WHEN_PERFORM

// ARM Section RW/RO/ZI Use Internal SRAM
#define PMIC_INTERNAL_SRAM

#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

// For Charger Detection Callback Function
pmic6329_chrdect_callbac_struct PMIC_CHRDET;

#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata = "INTERNRW" , rodata = "INTERNCONST" , zidata = "INTERNZI"
#endif // #ifdef PMIC_INTERNAL_SRAM

#define BANKS_NUM                       2
#define PMIC_MAX_REG_NUM                ((PMIC_BANK0_REG_NUM > PMIC_BANK1_REG_NUM) ? PMIC_BANK0_REG_NUM : PMIC_BANK1_REG_NUM)
kal_uint8 pmic6329_reg[BANKS_NUM][PMIC_MAX_REG_NUM];

#if defined(PMIC6329_RACE_CONDITION_CHECK)
kal_bool gPerformPMIC6329Func = KAL_FALSE;
#endif // #if defined(PMIC6329_RACE_CONDITION_CHECK)

void i2c_dual_speedup(void);
#if defined(PMIC6329_MASKIRQ_WHEN_PERFORM)
static volatile kal_bool gPMIC6329IRQMasked = KAL_FALSE;
static volatile kal_uint32 gsavedMask;
#endif // #if defined(PMIC6329_MASKIRQ_WHEN_PERFORM)

typedef struct
{
    DCL_UINT32 name;
    DCL_UINT8 mask;
    DCL_UINT8 shift;
}PMIC_REG_ENTRY;

typedef enum
{
    RG_VPROC_VOSEL_W,
    RG_VCORE_VOSEL_W,
    RG_VRF18_VOSEL_W,
    RG_VIO18_VOSEL_W,
    RG_VPA_VOSEL_W,
    RG_VSIM_VOSEL_W,
    RG_VSIM2_VOSEL_W,
    RG_VCAMD_VOSEL_W,
    RG_VCAM_IO_VOSEL_W,
    RG_VCAM_AF_VOSEL_W,
    RG_VMC_VOSEL_W,
    RG_VMCH_VOSEL_W,
    RG_VGP_VOSEL_W,
    RG_VGP2_VOSEL_W,
    RG_VIBR_VOSEL_W,
    RG_VA1_VOSEL_W,
    RG_VA2_VOSEL_W,
    RG_VCAMA_VOSEL_W,
    RG_VRTC_VOSEL_W,
	RG_VM12_1_CAL_W,
	RG_VM12_2_CAL_W,
	RG_VM12_INT_CAL_W,
	RG_VIO28_CAL_W,
	RG_VSIM_CAL_W,
	RG_VSIM2_CAL_W,
	RG_VUSB_CAL_W,
	RG_VCAMD_CAL_W,
	RG_VCAM_IO_CAL_W,
	RG_VCAM_AF_CAL_W,
	RG_VMC_CAL_W,
	RG_VMCH_CAL_W,
	RG_VGP_CAL_W,
	RG_VGP2_CAL_W,
	RG_VIBR_CAL_W,
	RG_VRF_CAL_W,
	RG_VTCXO_CAL_W,
	RG_VA1_CAL_W,
	RG_VA2_CAL_W,
	RG_VCAMA_CAL_W,    
	RG_PASEL_SET0_W,
	RG_PASEL_SET1_W,
	RG_PASEL_SET2_W,
	RG_PASEL_SET3_W,
	RG_PASEL_SET4_W,
	RG_PASEL_SET5_W,
	RG_PASEL_SET6_W,
	RG_PASEL_SET7_W	
}PMIC_BITS_WRITE_LIST_ENUM;

PMIC_REG_ENTRY pmic_bits_write_table[] =
{
	{RG_VPROC_VOSEL_W,		RG_VPROC_VOSEL_MASK,		RG_VPROC_VOSEL_SHIFT,		},
	{RG_VCORE_VOSEL_W,		RG_VCORE_VOSEL_MASK,		RG_VCORE_VOSEL_SHIFT,		},
	{RG_VRF18_VOSEL_W,		RG_VRF18_VOSEL_MASK,		RG_VRF18_VOSEL_SHIFT,		},
	{RG_VIO18_VOSEL_W,		RG_VIO18_VOSEL_MASK,		RG_VIO18_VOSEL_SHIFT,		},
	{RG_VPA_VOSEL_W,		RG_VPA_VOSEL_MASK,		    RG_VPA_VOSEL_SHIFT,		    },
	{RG_VSIM_VOSEL_W,		RG_VSIM_VOSEL_MASK,		    RG_VSIM_VOSEL_SHIFT,		},
	{RG_VSIM2_VOSEL_W,		RG_VSIM2_VOSEL_MASK,		RG_VSIM2_VOSEL_SHIFT,		},
	{RG_VCAMD_VOSEL_W,		RG_VCAMD_VOSEL_MASK,		RG_VCAMD_VOSEL_SHIFT,		},
	{RG_VCAM_IO_VOSEL_W,	RG_VCAM_IO_VOSEL_MASK,		RG_VCAM_IO_VOSEL_SHIFT,		},
	{RG_VCAM_AF_VOSEL_W,	RG_VCAM_AF_VOSEL_MASK,		RG_VCAM_AF_VOSEL_SHIFT,		},
	{RG_VMC_VOSEL_W,		RG_VMC_VOSEL_MASK,		    RG_VMC_VOSEL_SHIFT,		    },
	{RG_VMCH_VOSEL_W,		RG_VMCH_VOSEL_MASK,		    RG_VMCH_VOSEL_SHIFT,		},
	{RG_VGP_VOSEL_W,		RG_VGP_VOSEL_MASK,		    RG_VGP_VOSEL_SHIFT,		    },
	{RG_VGP2_VOSEL_W,		RG_VGP2_VOSEL_MASK,		    RG_VGP2_VOSEL_SHIFT,		},
	{RG_VIBR_VOSEL_W,		RG_VIBR_VOSEL_MASK,		    RG_VIBR_VOSEL_SHIFT,		},
	{RG_VA1_VOSEL_W,		RG_VA1_VOSEL_MASK,		    RG_VA1_VOSEL_SHIFT,		    },
    {RG_VA2_VOSEL_W,        RG_VA2_VOSEL_MASK,          RG_VA2_VOSEL_SHIFT,         },
	{RG_VCAMA_VOSEL_W,		RG_VCAMA_VOSEL_MASK,		RG_VCAMA_VOSEL_SHIFT,		},
	{RG_VRTC_VOSEL_W,		RG_VRTC_VOSEL_MASK,		    RG_VRTC_VOSEL_SHIFT,		},
	{RG_VM12_1_CAL_W,		RG_VM12_1_CAL_MASK,			RG_VM12_1_CAL_SHIFT,		},
	{RG_VM12_2_CAL_W,		RG_VM12_2_CAL_MASK,			RG_VM12_2_CAL_SHIFT,		},
	{RG_VM12_INT_CAL_W,		RG_VM12_INT_CAL_MASK,		RG_VM12_INT_CAL_SHIFT,		},
	{RG_VIO28_CAL_W,		RG_VIO28_CAL_MASK,			RG_VIO28_CAL_SHIFT,			},
	{RG_VSIM_CAL_W,			RG_VSIM_CAL_MASK,			RG_VSIM_CAL_SHIFT,			},
	{RG_VSIM2_CAL_W,		RG_VSIM2_CAL_MASK,			RG_VSIM2_CAL_SHIFT,			},
	{RG_VUSB_CAL_W,			RG_VUSB_CAL_MASK,			RG_VUSB_CAL_SHIFT,			},
	{RG_VCAMD_CAL_W,		RG_VCAMD_CAL_MASK,			RG_VCAMD_CAL_SHIFT,			},
	{RG_VCAM_IO_CAL_W,		RG_VCAM_IO_CAL_MASK,		RG_VCAM_IO_CAL_SHIFT,		},
	{RG_VCAM_AF_CAL_W,		RG_VCAM_AF_CAL_MASK,		RG_VCAM_AF_CAL_SHIFT,		},
	{RG_VMC_CAL_W,			RG_VMC_CAL_MASK,			RG_VMC_CAL_SHIFT,			},
	{RG_VMCH_CAL_W,			RG_VMCH_CAL_MASK,			RG_VMCH_CAL_SHIFT,			},
	{RG_VGP_CAL_W,			RG_VGP_CAL_MASK,			RG_VGP_CAL_SHIFT,			},
	{RG_VGP2_CAL_W,			RG_VGP2_CAL_MASK,			RG_VGP2_CAL_SHIFT,			},
	{RG_VIBR_CAL_W,			RG_VIBR_CAL_MASK,			RG_VIBR_CAL_SHIFT,			},
	{RG_VRF_CAL_W,			RG_VRF_CAL_MASK,			RG_VRF_CAL_SHIFT,			},
	{RG_VTCXO_CAL_W,		RG_VTCXO_CAL_MASK,			RG_VTCXO_CAL_SHIFT,			},
	{RG_VA1_CAL_W,			RG_VA1_CAL_MASK,			RG_VA1_CAL_SHIFT,			},
	{RG_VA2_CAL_W,			RG_VA2_CAL_MASK,			RG_VA2_CAL_SHIFT,			},
	{RG_VCAMA_CAL_W,		RG_VCAMA_CAL_MASK,			RG_VCAMA_CAL_SHIFT,			},
	{RG_PASEL_SET0_W,		RG_PASEL_SET0_MASK,			RG_PASEL_SET0_SHIFT,		},
	{RG_PASEL_SET1_W,		RG_PASEL_SET1_MASK,			RG_PASEL_SET1_SHIFT,		},
	{RG_PASEL_SET2_W,		RG_PASEL_SET2_MASK,			RG_PASEL_SET2_SHIFT,		},
	{RG_PASEL_SET3_W,		RG_PASEL_SET3_MASK,			RG_PASEL_SET3_SHIFT,		},
	{RG_PASEL_SET4_W,		RG_PASEL_SET4_MASK,			RG_PASEL_SET4_SHIFT,		},
	{RG_PASEL_SET5_W,		RG_PASEL_SET5_MASK,			RG_PASEL_SET5_SHIFT,		},
	{RG_PASEL_SET6_W,		RG_PASEL_SET6_MASK,			RG_PASEL_SET6_SHIFT,		},
	{RG_PASEL_SET7_W,		RG_PASEL_SET7_MASK,			RG_PASEL_SET7_SHIFT,		}                                                   	
};                                                   	

typedef enum
{
    RG_VPROC_EN_W, 
    RG_VCORE_EN_W,    
    RG_VRF18_EN_W,    
    RG_VIO18_EN_W,
	RG_VPA_EN_W,
	VM12_1_EN_W,
	VM12_2_EN_W,
	VM12_INT_EN_W,
	VIO28_EN_W,
	RG_VSIM_EN_W,
	RG_VSIM2_EN_W,
	RG_VUSB_EN_W,
	RG_VCAMD_EN_W,
	RG_VCAM_IO_EN_W,
	RG_VCAM_AF_EN_W,
	RG_VMC_EN_W,
	RG_VMCH_EN_W,
	RG_VGP_EN_W,
	RG_VGP2_EN_W,
	RG_VIBR_EN_W,
	RG_VRF_EN_W,
	RG_VTCXO_EN_W,
	RG_VA1_EN_W,
	RG_VA2_EN_W,
	RG_VCAMA_EN_W,
	VRTC_EN_W,	
	VRF_ON_CTRL_W,
	VTCXO_ON_CTRL_W,
	RG_VRF18_MODESET_W
	
}PMIC_BIT_WRITE_LIST_ENUM;

PMIC_REG_ENTRY pmic_bit_write_table[] =
{
    {RG_VPROC_EN_W,			RG_VPROC_EN_MASK,		RG_VPROC_EN_SHIFT,		},
    {RG_VCORE_EN_W,			RG_VCORE_EN_MASK,		RG_VCORE_EN_SHIFT,		},    
	{RG_VRF18_EN_W,			RG_VRF18_EN_MASK,		RG_VRF18_EN_SHIFT,		},
   	{RG_VIO18_EN_W,			RG_VIO18_EN_MASK,		RG_VIO18_EN_SHIFT,		},
	{RG_VPA_EN_W,			RG_VPA_EN_MASK,			RG_VPA_EN_SHIFT,		},
	{VM12_1_EN_W,			VM12_1_EN_MASK,			VM12_1_EN_SHIFT,		},
	{VM12_2_EN_W,			VM12_2_EN_MASK,			VM12_2_EN_SHIFT,		},
	{VM12_INT_EN_W,			VM12_INT_EN_MASK,		VM12_INT_EN_SHIFT,		},
	{VIO28_EN_W,			VIO28_EN_MASK,			VIO28_EN_SHIFT,			},
	{RG_VSIM_EN_W,			RG_VSIM_EN_MASK,		RG_VSIM_EN_SHIFT,		},
	{RG_VSIM2_EN_W,			RG_VSIM2_EN_MASK,		RG_VSIM2_EN_SHIFT,		},
	{RG_VUSB_EN_W,			RG_VUSB_EN_MASK,		RG_VUSB_EN_SHIFT,		},
	{RG_VCAMD_EN_W,			RG_VCAMD_EN_MASK,		RG_VCAMD_EN_SHIFT,		},
	{RG_VCAM_IO_EN_W,		RG_VCAM_IO_EN_MASK,		RG_VCAM_IO_EN_SHIFT,	},
	{RG_VCAM_AF_EN_W,		RG_VCAM_AF_EN_MASK,		RG_VCAM_AF_EN_SHIFT,	},
	{RG_VMC_EN_W,			RG_VMC_EN_MASK,			RG_VMC_EN_SHIFT,		},
	{RG_VMCH_EN_W,			RG_VMCH_EN_MASK,		RG_VMCH_EN_SHIFT,		},
	{RG_VGP_EN_W,			RG_VGP_EN_MASK,			RG_VGP_EN_SHIFT,		},
	{RG_VGP2_EN_W,			RG_VGP2_EN_MASK,		RG_VGP2_EN_SHIFT,		},
	{RG_VIBR_EN_W,			RG_VIBR_EN_MASK,		RG_VIBR_EN_SHIFT,		},
	{RG_VRF_EN_W,			RG_VRF_EN_MASK,			RG_VRF_EN_SHIFT,		},
	{RG_VTCXO_EN_W,			RG_VTCXO_EN_MASK,		RG_VTCXO_EN_SHIFT,		},
	{RG_VA1_EN_W,			RG_VA1_EN_MASK,			RG_VA1_EN_SHIFT,		},
	{RG_VA2_EN_W,			RG_VA2_EN_MASK,			RG_VA2_EN_SHIFT,		},
	{RG_VCAMA_EN_W,			RG_VCAMA_EN_MASK,		RG_VCAMA_EN_SHIFT,		},
	{VRTC_EN_W,				VRTC_EN_MASK,			VRTC_EN_SHIFT,			},
	{VRF_ON_CTRL_W,			VRF_ON_CTRL_MASK,		VRF_ON_CTRL_SHIFT,		},
	{VTCXO_ON_CTRL_W,		VTCXO_ON_CTRL_MASK,		VTCXO_ON_CTRL_SHIFT,	},
	{RG_VRF18_MODESET_W,	RG_VRF18_MODESET_MASK,	RG_VRF18_MODESET_SHIFT,	}
	
};

typedef enum
{
    PMU_THR_STATUS_R,
    PCHR_FLAG_OUT_R,
    QI_VPROC_VOSEL_R,
    QI_VCORE_VOSEL_R,
    QI_VM12_INT_CAL_R,    
    RG_ADC_OUT_C0_9_8_R,
    RG_ADC_OUT_C1_9_8_R,
    RG_ADC_OUT_C2_9_8_R,
    RG_ADC_OUT_C3_9_8_R,
    RG_ADC_OUT_WAKEUP_9_8_R,
    RG_ADC_OUT_LBAT_9_8_R,
    RG_ADC_OUT_TRIM_9_8_R
}PMIC_BITS_READ_LIST_ENUM;


PMIC_REG_ENTRY pmic_bits_read_table[] =
{
	{PMU_THR_STATUS_R,				PMU_THR_STATUS_MASK,				PMU_THR_STATUS_SHIFT,			},     
	{PCHR_FLAG_OUT_R,				PCHR_FLAG_OUT_MASK,					PCHR_FLAG_OUT_SHIFT,			},     
	{QI_VPROC_VOSEL_R,				QI_VPROC_VOSEL_MASK,				QI_VPROC_VOSEL_SHIFT,			},     
	{QI_VCORE_VOSEL_R,				QI_VCORE_VOSEL_MASK,				QI_VCORE_VOSEL_SHIFT,			},     
	{QI_VM12_INT_CAL_R,				QI_VM12_INT_CAL_MASK,				QI_VM12_INT_CAL_SHIFT,			},     
	{RG_ADC_OUT_C0_9_8_R,			RG_ADC_OUT_C0_9_8_MASK,				RG_ADC_OUT_C0_9_8_SHIFT,		},     
	{RG_ADC_OUT_C1_9_8_R,			RG_ADC_OUT_C1_9_8_MASK,				RG_ADC_OUT_C1_9_8_SHIFT,		},     
	{RG_ADC_OUT_C2_9_8_R,			RG_ADC_OUT_C2_9_8_MASK,				RG_ADC_OUT_C2_9_8_SHIFT,		},     
	{RG_ADC_OUT_C3_9_8_R,			RG_ADC_OUT_C3_9_8_MASK,				RG_ADC_OUT_C3_9_8_SHIFT,		},     
	{RG_ADC_OUT_WAKEUP_9_8_R,		RG_ADC_OUT_WAKEUP_9_8_MASK,			RG_ADC_OUT_WAKEUP_9_8_SHIFT,	},     
	{RG_ADC_OUT_LBAT_9_8_R,			RG_ADC_OUT_LBAT_9_8_MASK,			RG_ADC_OUT_LBAT_9_8_SHIFT,		},     
	{RG_ADC_OUT_TRIM_9_8_R,			RG_ADC_OUT_TRIM_9_8_MASK,			RG_ADC_OUT_TRIM_9_8_SHIFT,		}
};

typedef enum
{
    VCORE_STATUS_R,
    VPROC_STATUS_R,
    VIO18_STATUS_R,
    VRF18_STATUS_R,
    VPA_STATUS_R,
    VRF_STATUS_R,
    VTCXO_STATUS_R,
    VA1_STATUS_R
}PMIC_BIT_READ_LIST_ENUM;

PMIC_REG_ENTRY pmic_bit_read_table[] =
{
	{VCORE_STATUS_R,		VCORE_STATUS_MASK,		VCORE_STATUS_SHIFT,		},
	{VPROC_STATUS_R,		VPROC_STATUS_MASK,		VPROC_STATUS_SHIFT,		},
	{VIO18_STATUS_R,		VIO18_STATUS_MASK,		VIO18_STATUS_SHIFT,		},
	{VRF18_STATUS_R,		VRF18_STATUS_MASK,		VRF18_STATUS_SHIFT,		},
	{VPA_STATUS_R,			VPA_STATUS_MASK,		VPA_STATUS_SHIFT,		},
	{VRF_STATUS_R,			VRF_STATUS_MASK,		VRF_STATUS_SHIFT,		},
	{VTCXO_STATUS_R,		VTCXO_STATUS_MASK,		VTCXO_STATUS_SHIFT,		},
	{VA1_STATUS_R,			VA1_STATUS_MASK,		VA1_STATUS_SHIFT,		},
};


kal_uint8 pmic6329_eco_version = 0;

// BL, Flash, OTG LDOs need higher voltage output, we also need to enable vboost1 when enabling the 3 LDOs
/*
#define VBOOST1_SET_FLAG_BL   0x01  // Bit00
#define VBOOST1_SET_FLAG_FLASH  0x02  // Bit01
#define VBOOST1_SET_FLAG_OTG   0x04  // Bit02
#define VBOOST1_SET_FLAG_BOOST1  0x08  // Bit03
kal_uint8 pmic6329_vboost1_set_flag = 0;
// Internal usage only, called insided PMIC6329 driver
// Do NOT need protection check, because it is called inside PMIC API
#define dcl_pmic6329_boost1_enable_internal(flag)  {\
 kal_uint8 enable;\
 enable = (flag == 0)?0:1;\
 pmic6329_reg[0x5D] &= ~(BOOST1_EN_MASK << BOOST1_EN_SHIFT);\
 pmic6329_reg[0x5D] |= (enable << BOOST1_EN_SHIFT);\
 pmic6329_ch2_reg_write(0x5D, pmic6329_reg[0x5D]);\
}
// FLASH, Keypad LED, Vibrator LDOs need to control DIM, so we need to turn on 0x72 when any of them are turned on
#define DIM_CK_ON_FLAG_CK    0x01  // Bit00
#define DIM_CK_ON_FLAG_FLASH   0x02  // Bit01
#define DIM_CK_ON_FLAG_KEY    0x04  // Bit02
#define DIM_CK_ON_FLAG_VIB    0x08  // Bit03
// Internal usage only, called insided PMIC6329 driver
// Do NOT need protection check, because it is called inside PMIC API
kal_uint8 pmic6329_dim_ck_set_flag = 0;
#define dcl_pmic6329_dim_ck_force_on_internal(flag)  {\
 kal_uint8 enable;\
 enable = (flag == 0)?0:1;\
 pmic6329_reg[0x72] &= ~(DIM_CK_FORCE_ON_MASK << DIM_CK_FORCE_ON_SHIFT);\
 pmic6329_reg[0x72] |= (enable << DIM_CK_FORCE_ON_SHIFT);\
 pmic6329_ch2_reg_write(0x72, pmic6329_reg[0x72]);\
}
*/

#ifdef PMIC_INTERNAL_SRAM
#pragma arm section rwdata, rodata , zidata
#endif // #ifdef PMIC_INTERNAL_SRAM

#if defined(PMIC6329_RACE_CONDITION_CHECK)
#define LOCK_PMIC6329_CHECK {\
    kal_uint32 savedMask = 0;\
    if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
        savedMask = SaveAndSetIRQMask();\
    }\
    if (gPerformPMIC6329Func == KAL_TRUE){\
        ASSERT(0);\
    }\
    gPerformPMIC6329Func = KAL_TRUE;\
    if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
        RestoreIRQMask(savedMask);\
    }\
}

#define RELEASE_PMIC6329_CHECK {\
    kal_uint32 savedMask = 0;\
    if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
        savedMask = SaveAndSetIRQMask();\
    }\
    gPerformPMIC6329Func = KAL_FALSE;\
    if ( (!kal_if_hisr()) && (!kal_if_lisr()) ){\
    RestoreIRQMask(savedMask);\
    }\
}
#elif defined(PMIC6329_MASKIRQ_WHEN_PERFORM)// #if defined(PMIC6329_RACE_CONDITION_CHECK)

#define I_BIT_SET				0x80
#define F_BIT_SET				0x40
#define I_BIT_AND_F_BIT_SET		0xC0

#define LOCK_PMIC6329_CHECK  {\
    if (!kal_query_systemInit()){\
		gsavedMask = SaveAndSetIRQMask();\
		gPMIC6329IRQMasked = KAL_TRUE;\
    }\
}

#define RELEASE_PMIC6329_CHECK {\
    if (gPMIC6329IRQMasked == KAL_TRUE){\
        gPMIC6329IRQMasked = KAL_FALSE;\
        RestoreIRQMask(gsavedMask);\
    }\
}

#else // #if defined(PMIC6329_RACE_CONDITION_CHECK)
#define LOCK_PMIC6329_CHECK  ;
#define RELEASE_PMIC6329_CHECK ;
#endif // #if defined(PMIC6329_RACE_CONDITION_CHECK)

//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////

// Write Whole Bytes
void dcl_pmic6329_byte_write(DCL_UINT8 addr, DCL_UINT8 val, DCL_UINT32 bank)
{
#if defined(MEASURE_I2C_DUAL_PERIOD)
#include "us_timer.h"               /* For ust_get_current_time() API*/
#endif    
    i2c_dual_speedup();
    
#if defined(MEASURE_I2C_DUAL_PERIOD)    
    i2c_dual_time1 = ust_get_current_time();
#endif
    pmic6329_reg[bank][addr] = val;
    pmic6329_ch2_reg_write(addr, pmic6329_reg[bank][addr], bank);
#if defined(MEASURE_I2C_DUAL_PERIOD)    
    i2c_dual_time2 = ust_get_current_time();
#endif    
    RELEASE_PMIC6329_CHECK;
}

// Write Several Bits
void dcl_pmic6329_bits_write(DCL_UINT8 addr, DCL_UINT32 bank, PMIC_BITS_WRITE_LIST_ENUM flag, DCL_UINT8 sel)
{
    PMIC_REG_ENTRY *pTable = pmic_bits_write_table;
    DCL_UINT32 i, table_size = 0;

    table_size = GETARRNUM(pmic_bits_write_table);
    
    for(i = 0; i < table_size; i++)
    {
        if(flag == (PMIC_BITS_WRITE_LIST_ENUM)pTable[i].name)
        {
            break;          
        }
    }

    if (i >= table_size)
        ASSERT(0); // Flag Unknown
        
    i2c_dual_speedup();
    pmic6329_reg[bank][addr] &= ~(pTable[i].mask << pTable[i].shift);
    pmic6329_reg[bank][addr] |= ((kal_uint8)sel << pTable[i].shift);    
    pmic6329_ch2_reg_write(addr, pmic6329_reg[bank][addr], bank);
    RELEASE_PMIC6329_CHECK;
}

// Write Single Bit
void dcl_pmic6329_bit_write(DCL_UINT8 addr, DCL_UINT32 bank,  PMIC_BIT_WRITE_LIST_ENUM flag, DCL_BOOL set)
{
    PMIC_REG_ENTRY *pTable = pmic_bit_write_table;
    DCL_UINT32 i, table_size = 0;

	table_size = GETARRNUM(pmic_bit_write_table);

    for(i = 0; i < table_size; i++)
    {
        if(flag == (PMIC_BIT_WRITE_LIST_ENUM)pTable[i].name)
        {
            break;          
        }
    }

    if (i >= table_size)
        ASSERT(0); // Flag Unknown
        
    i2c_dual_speedup();
    pmic6329_reg[bank][addr] &= ~(pTable[i].mask << pTable[i].shift);
    pmic6329_reg[bank][addr] |= ((kal_uint8)set << pTable[i].shift);    
    pmic6329_ch2_reg_write(addr, pmic6329_reg[bank][addr], bank);
    RELEASE_PMIC6329_CHECK;
}

//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
DCL_UINT8 dcl_pmic6329_byte_return(DCL_UINT8 addr, DCL_UINT32 bank)
{
    i2c_dual_speedup();
    pmic6329_ch2_reg_read(addr, &pmic6329_reg[bank][addr], bank);
    RELEASE_PMIC6329_CHECK;
    return pmic6329_reg[bank][addr];
}

// Read Several Bits
DCL_UINT8 dcl_pmic6329_bits_return(DCL_UINT8 addr, DCL_UINT32 bank, PMIC_BITS_READ_LIST_ENUM flag)
{
    PMIC_REG_ENTRY *pTable = pmic_bits_read_table;
    DCL_UINT8 reg_return = 0;
    DCL_UINT32 i, table_size = 0;

    table_size = GETARRNUM(pmic_bits_read_table);

    for(i = 0; i < table_size; i++)
    {
        if(flag == (PMIC_BITS_READ_LIST_ENUM)pTable[i].name)
        {
            break;          
        }
    }

    if (i >= table_size)
        ASSERT(0); // Flag Unknown
            
    i2c_dual_speedup();
    pmic6329_ch2_reg_read(addr, &pmic6329_reg[bank][addr], bank);  
    RELEASE_PMIC6329_CHECK;

    reg_return = pmic6329_reg[bank][addr] & (pTable[i].mask << pTable[i].shift);
    
    return reg_return;
}

// Read Single Bit
DCL_BOOL dcl_pmic6329_bit_return(DCL_UINT8 addr, DCL_UINT32 bank, PMIC_BIT_READ_LIST_ENUM flag)
{
    PMIC_REG_ENTRY *pTable = pmic_bit_read_table;
    DCL_UINT32 i, table_size = 0;

    table_size = GETARRNUM(pmic_bit_read_table);

    for(i = 0; i < table_size; i++)
    {
        if(flag == (PMIC_BIT_READ_LIST_ENUM)pTable[i].name)
        {
            break;          
        }
    }
    
    if (i >= table_size)
        ASSERT(0); // Flag Unknown    
    
    i2c_dual_speedup();
    pmic6329_ch2_reg_read(addr, &pmic6329_reg[bank][addr], bank);
    
    if (pmic6329_reg[bank][addr] & (pTable[i].mask << pTable[i].shift)){
        RELEASE_PMIC6329_CHECK;
        return KAL_TRUE;
    }else{
        RELEASE_PMIC6329_CHECK;
        return KAL_FALSE;
    }
}

void dcl_pmic6329_HISR(void){
    kal_uint8 stat1, stat2, stat3;

    stat1 = dcl_pmic6329_byte_return(INT_STATUS5_ADDR, PMIC_BANK0);
    stat2 = dcl_pmic6329_byte_return(INT_STATUS6_ADDR, PMIC_BANK0);
    stat3 = dcl_pmic6329_byte_return(INT_STATUS7_ADDR, PMIC_BANK0);    

    kal_prompt_trace(MOD_BMT, "PMIC6329 intr: %x, %x, %x, %x", stat1, stat2, stat3);

    // Just call ac_det(), no matter there is real CHR intr or NOT
    // 1. At boot time (Device is reset while cable is inserted, PMIC 6329 won't assert INTR at next reset)
    //    ==> EINT will be UnMask immediately, has no effect at boot time
    // 2. If current state of chr is same as read back stat, "CHRDet status is same as chr_usb_state" is shown to catcher
    //    ==> EINT will be UnMask immediately
    // 3. If other PMIC events (Ex: OC) occurs, "CHRDet status is same as chr_usb_state" is shown to catcher
    //    ==> EINT will be UnMask immediately
    // 4. If there is CHR events, corresponding Tasks, HISRs will take over the charger detection process
    //    ==> Normal path, the EINT will be UnMask after charger detection process is done

    // ==> We force to call ac_det in order to make EINT to be UnMask again
    PMIC_CHRDET.pmic_ac_det();

// // show intr state via catcher of each int status
// if (stat3 & (kal_uint8)CHRDET_INT_STAT)
// {
//  kal_prompt_trace(MOD_BMT,"CHRDet");
//  PMIC_CHRDET.pmic_ac_det();
//  perform_ac_det = TRUE;
// }
// else
// {
//  // When Device idle -> Insert cable -> USB/Charger in -> Reboot device -> PMIC 6329 won't assert INTR
//  // Need to refer boot check flag to indicate the INTR service is taken in last boot
//  if (pmic6236_boot_check_charge_source == KAL_TRUE)
//  {
//   if (pmic_chrdet_status())
//   {
//    kal_prompt_trace(MOD_BMT,"CHRDet(Boot check)");
//    PMIC_CHRDET.pmic_ac_det();
//   }
//  }
// }
// pmic6236_boot_check_charge_source = KAL_FALSE;
}

void dcl_pmic6329_ChrDet_Registration(chr_callback_type type, void (*Callback)(void))
{
    if (type == AC_CHR_CALLBACK)
    {
        PMIC_CHRDET.pmic_ac_det = Callback;
    }
    else if (type == USB_CHR_CALLBACK)
    {
        PMIC_CHRDET.pmic_usb_det = Callback;
    }
    else{
        ASSERT(0);
    }
}

// Exported for EM used
void pmic6329_EM_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank){
    dcl_pmic6329_byte_write(reg, val, bank);
}

kal_uint8 pmic6329_EM_reg_read(kal_uint8 reg, kal_uint32 bank){
    return  dcl_pmic6329_byte_return(reg, bank);
}

const DCL_UINT32 vproc_vosel[] =
{
    PMU_VOLT_00_700000_V,   PMU_VOLT_00_725000_V,   PMU_VOLT_00_750000_V,   PMU_VOLT_00_775000_V,
    PMU_VOLT_00_800000_V,   PMU_VOLT_00_825000_V,   PMU_VOLT_00_850000_V,   PMU_VOLT_00_875000_V,
    PMU_VOLT_00_900000_V,   PMU_VOLT_00_925000_V,   PMU_VOLT_00_950000_V,   PMU_VOLT_00_975000_V,
    PMU_VOLT_01_000000_V,   PMU_VOLT_01_025000_V,   PMU_VOLT_01_050000_V,   PMU_VOLT_01_075000_V,
    PMU_VOLT_01_100000_V,   PMU_VOLT_01_125000_V,   PMU_VOLT_01_150000_V,   PMU_VOLT_01_175000_V,
    PMU_VOLT_01_200000_V,   PMU_VOLT_01_225000_V,   PMU_VOLT_01_250000_V,   PMU_VOLT_01_275000_V,
    PMU_VOLT_01_300000_V, 
};

const DCL_UINT32 vrf18_vosel[] =
{
    PMU_VOLT_01_520000_V,   PMU_VOLT_01_540000_V,   PMU_VOLT_01_560000_V,   PMU_VOLT_01_580000_V,
    PMU_VOLT_01_600000_V,   PMU_VOLT_01_620000_V,   PMU_VOLT_01_640000_V,   PMU_VOLT_01_660000_V,
    PMU_VOLT_01_680000_V,   PMU_VOLT_01_700000_V,   PMU_VOLT_01_720000_V,   PMU_VOLT_01_740000_V,
    PMU_VOLT_01_760000_V,   PMU_VOLT_01_780000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_820000_V,
    PMU_VOLT_01_840000_V,   PMU_VOLT_01_860000_V,   PMU_VOLT_01_880000_V,   PMU_VOLT_01_900000_V,
    PMU_VOLT_01_920000_V,   PMU_VOLT_01_940000_V,   PMU_VOLT_01_960000_V,   PMU_VOLT_01_980000_V,
    PMU_VOLT_02_000000_V,   PMU_VOLT_02_020000_V,   PMU_VOLT_02_040000_V,   PMU_VOLT_02_060000_V,
    PMU_VOLT_02_080000_V,   PMU_VOLT_02_100000_V,   PMU_VOLT_02_120000_V,   PMU_VOLT_02_140000_V,
};

const DCL_UINT32 vio18_vosel[] =
{
    PMU_VOLT_01_500000_V,   PMU_VOLT_01_520000_V,   PMU_VOLT_01_540000_V,   PMU_VOLT_01_560000_V,
    PMU_VOLT_01_580000_V,   PMU_VOLT_01_600000_V,   PMU_VOLT_01_620000_V,   PMU_VOLT_01_640000_V,
    PMU_VOLT_01_660000_V,   PMU_VOLT_01_680000_V,   PMU_VOLT_01_700000_V,   PMU_VOLT_01_720000_V,
    PMU_VOLT_01_740000_V,   PMU_VOLT_01_760000_V,   PMU_VOLT_01_780000_V,   PMU_VOLT_01_800000_V,
    PMU_VOLT_01_820000_V,   PMU_VOLT_01_840000_V,   PMU_VOLT_01_860000_V,   PMU_VOLT_01_880000_V,
    PMU_VOLT_01_900000_V,   PMU_VOLT_01_920000_V,   PMU_VOLT_01_940000_V,   PMU_VOLT_01_960000_V,
    PMU_VOLT_01_980000_V,   PMU_VOLT_02_000000_V,   PMU_VOLT_02_020000_V,   PMU_VOLT_02_040000_V,
    PMU_VOLT_02_060000_V,   PMU_VOLT_02_080000_V,   PMU_VOLT_02_100000_V,   PMU_VOLT_02_120000_V,

};

const DCL_UINT32 vpa_vosel[] =
{
    PMU_VOLT_00_900000_V,   PMU_VOLT_01_000000_V,   PMU_VOLT_01_100000_V,   PMU_VOLT_01_200000_V,
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_400000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_600000_V,
    PMU_VOLT_01_700000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_900000_V,   PMU_VOLT_02_000000_V,
    PMU_VOLT_02_100000_V,   PMU_VOLT_02_200000_V,   PMU_VOLT_02_300000_V,   PMU_VOLT_02_400000_V,
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_600000_V,   PMU_VOLT_02_700000_V,   PMU_VOLT_02_800000_V,
    PMU_VOLT_02_900000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_100000_V,   PMU_VOLT_03_200000_V,
    PMU_VOLT_03_300000_V,   PMU_VOLT_03_400000_V,   PMU_VOLT_03_400000_V,   PMU_VOLT_03_400000_V,
    PMU_VOLT_03_400000_V,
};

const DCL_UINT32 vsim_vosel[] =
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_03_000000_V,
};

const DCL_UINT32 vsim2_vosel[] =
{
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,
    PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V,   PMU_VOLT_03_300000_V,
};

const DCL_UINT32 vcamd_vosel[] =
{
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,
    PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V,   PMU_VOLT_01_200000_V,
};

const DCL_UINT32 vcam_io_vosel[] =
{
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,
    PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,
};

const DCL_UINT32 va1_vosel[] =
{
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_100000_V,   PMU_VOLT_02_000000_V,   PMU_VOLT_01_800000_V,
};

const DCL_UINT32 va2_vosel[] =
{
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_800000_V,
};

const DCL_UINT32 vcama_vosel[] =
{
    PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,   PMU_VOLT_02_800000_V,
};

const DCL_UINT32 vrtc_vosel[] =
{
    PMU_VOLT_02_800000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_000000_V,   PMU_VOLT_02_100000_V,
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE, VPROC),		vproc_vosel,		NULL,				GETARRNUM(vproc_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VCORE),		vproc_vosel,		NULL,				GETARRNUM(vproc_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF18),		vrf18_vosel,		NULL,				GETARRNUM(vrf18_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VIO18),		vio18_vosel,		NULL,				GETARRNUM(vio18_vosel)		}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VPA),		vpa_vosel,		    NULL,				GETARRNUM(vpa_vosel)		}, 
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM),		vsim_vosel,		    NULL,				GETARRNUM(vsim_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		vsim2_vosel,		NULL,				GETARRNUM(vsim2_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VCAMD),		vcamd_vosel,		NULL,				GETARRNUM(vcamd_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VCAM_IO),    vcam_io_vosel,		NULL,				GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VCAM_AF),	vcam_io_vosel,		NULL,				GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VMC),		vcam_io_vosel,		NULL,				GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VMC1),		vcam_io_vosel,		NULL,				GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VGP),		vcam_io_vosel,		NULL,				GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VGP2),		vcam_io_vosel,		NULL,			    GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VIBR),		vcam_io_vosel,		NULL,			    GETARRNUM(vcam_io_vosel)	}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VA1),		va1_vosel,		    NULL,				GETARRNUM(va1_vosel)		}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VA2),		va2_vosel,		    NULL,				GETARRNUM(va2_vosel)		}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VCAMA),		vcama_vosel,		NULL,			    GETARRNUM(vcama_vosel)		}, 
    {ENC(LDO_BUCK_SET_VOLTAGE, VRTC),		vrtc_vosel,		    NULL,				GETARRNUM(vrtc_vosel)		}, 
    {ENC(VPA_SET_VOLTAGE, ALLMOD),			vpa_vosel,		    NULL,				GETARRNUM(vpa_vosel)	    },         
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6329_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_INT32	return_val = STATUS_FAIL;

	switch(cmd)
	{
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);

			switch(pLdoBuckCtrl->mod)
			{
                case VPROC:
                {
                    dcl_pmic6329_bit_write(VPROC_CON3_ADDR, PMIC_BANK0, RG_VPROC_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE:
                {
                    dcl_pmic6329_bit_write(VCORE_CON3_ADDR, PMIC_BANK0, RG_VCORE_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;                    
                }
                break;

                case VRF18:
                {
                    dcl_pmic6329_bit_write(VRF18_CON3_ADDR, PMIC_BANK0, RG_VRF18_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VIO18:
                {
                    dcl_pmic6329_bit_write(VM_CON3_ADDR, PMIC_BANK0, RG_VIO18_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VPA_SW:
                {
                    dcl_pmic6329_bit_write(VPA_CON3_ADDR, PMIC_BANK0, RG_VPA_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                case VM12_1:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CON1_ADDR, PMIC_BANK0, VM12_1_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VM12_2:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CON5_ADDR, PMIC_BANK0, VM12_2_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VM12_INT:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CONB_ADDR, PMIC_BANK0, VM12_INT_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VIO28:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CON10_ADDR, PMIC_BANK0, VIO28_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;           

                case VSIM:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CON13_ADDR, PMIC_BANK0, RG_VSIM_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;    

                case VSIM2:
                {
                    dcl_pmic6329_bit_write(DIGLDO_CON16_ADDR, PMIC_BANK0, RG_VSIM2_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;  
                
				case VUSB:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON19_ADDR, PMIC_BANK0, RG_VUSB_EN_W, pLdoBuckCtrl->enable);
                   
                    return_val = STATUS_OK;
				}
				break;

				case VCAMD:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON1C_ADDR, PMIC_BANK0, RG_VCAMD_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VCAM_IO:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON1F_ADDR, PMIC_BANK0, RG_VCAM_IO_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VCAM_AF:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON22_ADDR, PMIC_BANK0, RG_VCAM_AF_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VMC:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON25_ADDR, PMIC_BANK0, RG_VMC_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;                

				case VMC1:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON29_ADDR, PMIC_BANK0, RG_VMCH_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VGP:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON2D_ADDR, PMIC_BANK0, RG_VGP_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;
                
				case VGP2:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON30_ADDR, PMIC_BANK0, RG_VGP2_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;                
                
				case VIBR:
				{	
                    dcl_pmic6329_bit_write(DIGLDO_CON33_ADDR, PMIC_BANK0, RG_VIBR_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break; 

				case VRF:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CON1_ADDR, PMIC_BANK0, RG_VRF_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;      

				case VTCXO:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CON4_ADDR, PMIC_BANK0, RG_VTCXO_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;     

				case VA1:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CON7_ADDR, PMIC_BANK0, RG_VA1_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VA2:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CONB_ADDR, PMIC_BANK0, RG_VA2_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;

				case VCAMA:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CONB_ADDR, PMIC_BANK0, RG_VCAMA_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;                

				case VRTC:
				{	
                    dcl_pmic6329_bit_write(ANALDO_CON12_ADDR, PMIC_BANK0, VRTC_EN_W, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
				}
				break;                
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;
        
		case LDO_BUCK_SET_ON_SEL:
		{
			PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);
            
			switch(pLdoBuckCtrl->mod)
			{
                case VRF:
                {
                    // ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6329_bit_write(ANALDO_CON1_ADDR, PMIC_BANK0, VRF_ON_CTRL_W, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;
      				
				case VTCXO:
				{
                    // ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6329_bit_write(ANALDO_CON4_ADDR, PMIC_BANK0, VTCXO_ON_CTRL_W, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
				}
				break;				
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;		
        
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltage);	
            
			regVal = PMU_Parameter_to_Value(ENC(cmd, pLdoBuckCtrl->mod), pLdoBuckCtrl->voltage);
            
			switch(pLdoBuckCtrl->mod)
			{
                case VPROC:
                {
                    dcl_pmic6329_bits_write(VPROC_CON5_ADDR, PMIC_BANK0, RG_VPROC_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VCORE:
                {
                    dcl_pmic6329_bits_write(VCORE_CON5_ADDR, PMIC_BANK0, RG_VCORE_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VRF18:
                {
                    dcl_pmic6329_bits_write(VRF18_CON5_ADDR, PMIC_BANK0, RG_VRF18_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VIO18:
                {
                    dcl_pmic6329_bits_write(VM_CON5_ADDR, PMIC_BANK0, RG_VIO18_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break; 
                
                case VPA_SW:
                {
                    dcl_pmic6329_bits_write(VPA_CON5_ADDR, PMIC_BANK0, RG_VPA_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VSIM:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON13_ADDR, PMIC_BANK0, RG_VSIM_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VSIM2:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON16_ADDR, PMIC_BANK0, RG_VSIM2_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VCAMD:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON1C_ADDR, PMIC_BANK0, RG_VCAMD_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VCAM_IO:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON1F_ADDR, PMIC_BANK0, RG_VCAM_IO_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VCAM_AF:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON22_ADDR, PMIC_BANK0, RG_VCAM_AF_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 

                case VMC:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON25_ADDR, PMIC_BANK0, RG_VMC_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;   

                case VMC1:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON29_ADDR, PMIC_BANK0, RG_VMCH_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                   

                case VGP:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON2D_ADDR, PMIC_BANK0, RG_VGP_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;   

                case VGP2:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON30_ADDR, PMIC_BANK0, RG_VGP2_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;     

                case VIBR:
                {
                    dcl_pmic6329_bits_write(DIGLDO_CON33_ADDR, PMIC_BANK0, RG_VIBR_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;  

                case VA1:
                {
                    dcl_pmic6329_bits_write(ANALDO_CON7_ADDR, PMIC_BANK0, RG_VA1_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;       

                case VA2:
                {
                    dcl_pmic6329_bits_write(ANALDO_CONB_ADDR, PMIC_BANK0, RG_VA2_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;    

                case VCAMA:
                {
                    dcl_pmic6329_bits_write(ANALDO_CONE_ADDR, PMIC_BANK0, RG_VCAMA_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break; 

                case VRTC:
                {
                    dcl_pmic6329_bits_write(ANALDO_CON11_ADDR, PMIC_BANK0, RG_VRTC_VOSEL_W, regVal);
                    return_val = STATUS_OK;
                }
                break;                 
        
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}
		}	
		break;
        
		case LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE_CALIBRATION_CODE *pLdoBuckCtrl = &(data->rPMULdoBuckSetVoltageCalibrationCode);			
			switch(pLdoBuckCtrl->mod)
			{
				case VM12_1:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON0_ADDR, PMIC_BANK0, RG_VM12_1_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	
                
				case VM12_2:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON4_ADDR, PMIC_BANK0, RG_VM12_2_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VM12_INT:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON8_ADDR, PMIC_BANK0, RG_VM12_INT_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	
                
				case VIO28:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CONF_ADDR, PMIC_BANK0, RG_VIO28_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VSIM:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON12_ADDR, PMIC_BANK0, RG_VSIM_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VSIM2:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON15_ADDR, PMIC_BANK0, RG_VSIM2_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VUSB:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON18_ADDR, PMIC_BANK0, RG_VUSB_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VCAMD:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON1B_ADDR, PMIC_BANK0, RG_VCAMD_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	               

				case VCAM_IO:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON1E_ADDR, PMIC_BANK0, RG_VCAM_IO_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VCAM_AF:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON21_ADDR, PMIC_BANK0, RG_VCAM_AF_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VMC:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON24_ADDR, PMIC_BANK0, RG_VMC_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VMC1:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON28_ADDR, PMIC_BANK0, RG_VMCH_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VGP:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON2C_ADDR, PMIC_BANK0, RG_VGP_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VGP2:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON2F_ADDR, PMIC_BANK0, RG_VGP2_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VIBR:
				{
                    dcl_pmic6329_bits_write(DIGLDO_CON32_ADDR, PMIC_BANK0, RG_VIBR_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VRF:
				{
                    dcl_pmic6329_bits_write(ANALDO_CON0_ADDR, PMIC_BANK0, RG_VRF_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	                

				case VTCXO:
				{
                    dcl_pmic6329_bits_write(ANALDO_CON3_ADDR, PMIC_BANK0, RG_VTCXO_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VA1:
				{
                    dcl_pmic6329_bits_write(ANALDO_CON6_ADDR, PMIC_BANK0, RG_VA1_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;	

				case VA2:
				{
                    dcl_pmic6329_bits_write(ANALDO_CONA_ADDR, PMIC_BANK0, RG_VA2_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;

				case VCAMA:
				{
                    dcl_pmic6329_bits_write(ANALDO_COND_ADDR, PMIC_BANK0, RG_VCAMA_CAL_W, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
				}
				break;
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}
		}	
		break;
		//VPA
		case VPA_SET_EN:
		{
			PMU_CTRL_VPA_SET_EN *pVpaCtrl = &(data->rPMUVpaSetEn);
            dcl_pmic6329_bit_write(VPA_CON3_ADDR, PMIC_BANK0, RG_VPA_EN_W, pVpaCtrl->enable); 
            return_val = STATUS_OK;
		}
		break;
        
		case VPA_SET_VOLTAGE: // Deside By PASEL2/1/0
		{		
			PMU_CTRL_VPA_SET_VOLTAGE *pVpaCtrl = &(data->rPMUVpaSetVoltage);
			regVal = PMU_Parameter_to_Value(ENC(cmd,pVpaCtrl->vpa), pVpaCtrl->voltage);
			switch(pVpaCtrl->vpaIdx)
			{
				case PMU_VPA0:
				{
                    dcl_pmic6329_bits_write(VPA_CON6_ADDR, PMIC_BANK0, RG_PASEL_SET0_W, regVal);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMU_VPA1:
				{
					dcl_pmic6329_bits_write(VPA_CON7_ADDR, PMIC_BANK0, RG_PASEL_SET1_W, regVal);
                    return_val = STATUS_OK;
				}
				break;					

				case PMU_VPA2:
				{
					dcl_pmic6329_bits_write(VPA_CON8_ADDR, PMIC_BANK0, RG_PASEL_SET2_W, regVal);
                    return_val = STATUS_OK;
				}
				break;			

				case PMU_VPA3:
				{
					dcl_pmic6329_bits_write(VPA_CON9_ADDR, PMIC_BANK0, RG_PASEL_SET3_W, regVal);
                    return_val = STATUS_OK;
				}
				break;
                
				case PMU_VPA4:
				{
					dcl_pmic6329_bits_write(VPA_CONA_ADDR, PMIC_BANK0, RG_PASEL_SET4_W, regVal);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMU_VPA5:
				{
					dcl_pmic6329_bits_write(VPA_CONB_ADDR, PMIC_BANK0, RG_PASEL_SET5_W, regVal);
                    return_val = STATUS_OK;
				}
				break;			
                
				case PMU_VPA6:
				{
					dcl_pmic6329_bits_write(VPA_CONC_ADDR, PMIC_BANK0, RG_PASEL_SET6_W, regVal);
                    return_val = STATUS_OK;
				}
				break;		
                
				case PMU_VPA7:
				{
					dcl_pmic6329_bits_write(VPA_COND_ADDR, PMIC_BANK0, RG_PASEL_SET7_W, regVal);
                    return_val = STATUS_OK;
				}
				break;			
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;

		case VPA_GET_VOLTAGE_LIST:
		{
			PMU_CTRL_VPA_GET_VOLTAGE_LIST *pVpaCtrl = &(data->rPMUVpaGetVoltageList);
			pVpaCtrl->pVoltageList = vpa_vosel;
			pVpaCtrl->number = GETARRNUM(vpa_vosel);			
            return_val = STATUS_OK;
		}
		break;	
        
		case VPA_CTRL_SEL:
		{
			PMU_CTRL_VPA_CTRL_SEL *pVpaCtrl = &(data->rPMUVpaCtrlSel);
            dcl_pmic6329_bit_write(VPA_CONE_ADDR, PMIC_BANK0, RG_VPA_EN_W, pVpaCtrl->byPASEL);            	
            return_val = STATUS_OK;
		}
		break; 

		case VRF18_SET_FPWM:
		{
			PMU_CTRL_VRF18_SET_FPWM *pVrf18SetFpwm = &(data->rPMUVrf18SetFpwm);
            dcl_pmic6329_bit_write(VRF18_CON2_ADDR, PMIC_BANK0, RG_VRF18_MODESET_W, pVrf18SetFpwm->enable);            	
            return_val = STATUS_OK;
		}
		break; 
		
		case MISC_SET_REGISTER_VALUE:
		{			
			PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            DCL_UINT8 bank = (DCL_UINT8)((pChrCtrl->offset & 0x80000000) >> 31);
            
            pmic6329_EM_reg_write((kal_uint8)pChrCtrl->offset,(kal_uint8)pChrCtrl->value, (kal_uint32)bank);
            return_val = STATUS_OK;
		}
		break;	
		case MISC_GET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            DCL_UINT8 bank = (DCL_UINT8)((pChrCtrl->offset & 0x80000000) >> 31);
            
			pChrCtrl->value = pmic6329_EM_reg_read((kal_uint8)pChrCtrl->offset, (kal_uint32)bank);
            return_val = STATUS_OK;
		}
		break;	        

		default:				
		return_val = STATUS_UNSUPPORTED;
		break;
	}

	return return_val;

}

extern void dcl_pmic6329_internal_init(void);

#define I2C_DUAL_MEMORY_DUMP_SUPPORT

#if defined(I2C_DUAL_MEMORY_DUMP_SUPPORT)

#define MAX_POLLING_TIME_LOG_SIZE	128

kal_uint32 I2C_DUAL_POLLING_TIME[MAX_POLLING_TIME_LOG_SIZE];

typedef struct{
	kal_uint32		index;
    kal_uint32      polling_start;
   	kal_uint32      polling_time;
   	kal_uint32      polling_result;
}DRV_I2C_DUAL_POLLING_TIME_DBG_DATA;

typedef struct{
   DRV_I2C_DUAL_POLLING_TIME_DBG_DATA   dbg_data[MAX_POLLING_TIME_LOG_SIZE];
   kal_uint16     		   dbg_data_idx;
}DRV_I2C_DUAL_POLLING_TIME_STRUCT;

DRV_I2C_DUAL_POLLING_TIME_STRUCT	I2C_DUAL_POLLING_TIME_DATA;

typedef enum{
    I2C_DUAL_UNDER_POLLING_LOOP = 0,
	I2C_DUAL_TRANSCATION_COMPLETE,
	I2C_DUAL_FIFO_EMPTY,
	I2C_DUAL_START_BIT_CLEAR,
	I2C_DUAL_POLLING_TIME_OUT,
}I2C_DUAL_ACTION;

kal_uint32 I2C_DUAL_MEMORY_DUMP[50];
#endif

void i2c_dual_speedup(void)
{
   	kal_bool return_value;
   	volatile kal_uint32 counter = 0;
    kal_uint32 saved_current_time;
    DRV_I2C_DUAL_POLLING_TIME_DBG_DATA *dbg_ptr;
    
    LOCK_PMIC6329_CHECK;
	saved_current_time = drv_get_current_time();
    dbg_ptr = &(I2C_DUAL_POLLING_TIME_DATA.dbg_data[I2C_DUAL_POLLING_TIME_DATA.dbg_data_idx&(MAX_POLLING_TIME_LOG_SIZE - 1)]);
    dbg_ptr->index = I2C_DUAL_POLLING_TIME_DATA.dbg_data_idx;
    dbg_ptr->polling_start = saved_current_time;
    I2C_DUAL_POLLING_TIME_DATA.dbg_data_idx++;
    RELEASE_PMIC6329_CHECK;

    while(1)
    {
        LOCK_PMIC6329_CHECK;
        dbg_ptr->polling_time = drv_get_duration_tick(saved_current_time, drv_get_current_time());
        dbg_ptr->polling_result = I2C_DUAL_UNDER_POLLING_LOOP;
#if defined(MT6575_S00)
	 	return_value  = PMU_DRV_ReadReg16(I2CDUAL_base + 0xA4);
#else
        return_value = i2c_dual_polling_trans_comp(I2C_DUAL_CHANNEL2);
#endif

#if defined(MT6575_S00)
		if(return_value == 0)
#else
        if(return_value)
#endif
        {
        	counter = 0;
            dbg_ptr->polling_result = I2C_DUAL_TRANSCATION_COMPLETE;
            break;
        }
        else
        {
            if(I2C_DUAL_GET_FIFO_STAT(I2C_DUAL_CHANNEL2) == 0x0001)
            {
                dbg_ptr->polling_result = I2C_DUAL_FIFO_EMPTY;
            }

            if(counter > 100000)
            {
                dbg_ptr->polling_result = I2C_DUAL_POLLING_TIME_OUT;
#if defined(I2C_DUAL_MEMORY_DUMP_SUPPORT)
            	{
            		volatile kal_uint32 i = 0;
            		for(i = 0; i < 50; i++)
            		{
            			I2C_DUAL_MEMORY_DUMP[i] = PMU_DRV_ReadReg16(I2CDUAL_base + 4*i);
            		}
            	}
#endif // End of #if defined(I2C_DUAL_MEMORY_DUMP)
            	ASSERT(0);
            }            
            RELEASE_PMIC6329_CHECK;
            counter++;
            continue;
        }
    }    
}

void dcl_pmic6329_init(void){
    kal_uint32 i, SAMPLE_CNT_DIV , STEP_CNT_DIV;

	pmu_control_handler = PMIC6329_control_handler;
	pmu_parameter_size = GETARRNUM(pmu_parameter_table);

#if defined(PMIC6329_MASKIRQ_WHEN_PERFORM)
    gPMIC6329IRQMasked = KAL_FALSE;
#endif // #if defined(PMIC6329_MASKIRQ_WHEN_PERFORM)

    i2c_dual_init();
    dcl_pmic6329_byte_write(0x3C, 0x10, PMIC_BANK1); // [4]=1, SYNC_EN = 1
    dcl_pmic6329_byte_write(I2C_CON0_ADDR, 0x00, PMIC_BANK1);
    dcl_pmic6329_byte_write(I2C_CON1_ADDR, 0x00, PMIC_BANK1);
    // i2c_v1_set_speed(I2C_CLK_RATE, FS_MODE, MAX_FS_MODE_SPEED);   

    pmic6329_eco_version = PMIC6329_ECO_2_VERSION;

    // Get PMIC6329 ECO version
    {
        kal_uint16 eco_version = 0;
        kal_uint8 tmp8;
        kal_bool result_tmp;
        // Low part of CID
        //result_tmp = pmic6329_ch2_reg_read(CID_1_REG_INDEX, &tmp8, PMIC_BANK0);
        tmp8 = dcl_pmic6329_byte_return(CID_1_REG_INDEX, PMIC_BANK0);       
        eco_version |= (tmp8 << 8);
        // High part of CID
        //result_tmp = pmic6329_ch2_reg_read(CID_2_REG_INDEX, &tmp8, PMIC_BANK0);
        tmp8 = dcl_pmic6329_byte_return(CID_2_REG_INDEX, PMIC_BANK0);       
        
        eco_version |= tmp8;

        if (eco_version == PMIC6329_E1_CID_CODE)
        {
            pmic6329_eco_version = PMIC6329_ECO_1_VERSION;
        }
        else if(eco_version == PMIC6329_E2_CID_CODE)
        {
            pmic6329_eco_version = PMIC6329_ECO_2_VERSION;
        }
        
    }

    if(pmic6329_eco_version == PMIC6329_ECO_1_VERSION)
    {
        if(mt6575_get_bus_freq() <= 217000) 
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x5;
        }
        else if(mt6575_get_bus_freq() <= 252000)
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x6;
        }
        else if(mt6575_get_bus_freq() <= 287000)
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x7;           
        }
        else
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x8;
        }
    }
    else
    {
		/*
        if(mt6575_get_bus_freq() <= 217000) 
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x2;
        }
        else if(mt6575_get_bus_freq() <= 287000)
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x3;           
        }
        else
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x4;
        }
		*/
        if(mt6575_get_bus_freq() <= 217000) 
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x5;
        }
        else if(mt6575_get_bus_freq() <= 252000)
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x6;
        }
        else if(mt6575_get_bus_freq() <= 287000)
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x7;           
        }
        else
        {
            SAMPLE_CNT_DIV = 0;
            STEP_CNT_DIV = 0x8;
        }
    }

    i2c_dual_set_timing(I2C_DUAL_CHANNEL2, SAMPLE_CNT_DIV, STEP_CNT_DIV);
#if defined(I2C_DUAL_AP_MD_TEST)    
    i2c_dual_set_timing(I2C_DUAL_CHANNEL1, SAMPLE_CNT_DIV, STEP_CNT_DIV);
    i2c_dual_ap_md_test();
#endif

// for (i=0;i<PMIC_REG_NUM;i++){
//  result = pmic6329_ch2_reg_read(i, &pmic6329_reg[i]);
// }
// It is OK to read intr status register here (The operation will cause PMIC6329 deassert intr
// We will trigger PMIC HISR if there is intr event
    for (i = 0;i < PMIC_BANK0_REG_NUM;i++){
        // We skip intr state read back
        // If there is intr asserted, after enable EINT intr, pmic hisr will handle the intr
        if ( (i != INT_STATUS5_ADDR) && (i != INT_STATUS6_ADDR) && (i != INT_STATUS7_ADDR) ){
            pmic6329_reg[PMIC_BANK0][i] = dcl_pmic6329_byte_return(i, PMIC_BANK0); 
        }
    }

    for (i = 0;i < PMIC_BANK1_REG_NUM;i++){
		pmic6329_reg[PMIC_BANK1][i] = dcl_pmic6329_byte_return(i, PMIC_BANK1);  
    }
    dcl_pmic6329_internal_init();
    pmic6329_customization_init();

#if (defined(MT6575) || defined(MT6577)) && defined(AD6548_RF) && defined(AFC_VCXO)
	// VTCXO use SW control for AD6548RF
	PMIC_DRV_SetData(0xC1,0x02,0x00,0x0);
#endif

}

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    DCL_UINT8 bank = (DCL_UINT8)((pmic_addr & 0x80000000) >> 31);
    return dcl_pmic6329_byte_return((DCL_UINT8)pmic_addr, bank);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    DCL_UINT8 bank = (DCL_UINT8)((pmic_addr & 0x80000000) >> 31);
    dcl_pmic6329_byte_write((DCL_UINT8)pmic_addr, value, bank);
}

#endif //#if (defined(PMIC_6329_REG_API))

