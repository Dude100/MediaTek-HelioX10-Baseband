/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *		dcl_pmic6320.c
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6320
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
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
#include "mt6589_pmic_wrap_sw.h"
#include "kal_public_api.h"

#if defined(PMIC_6320_REG_API)

// ARM Section RW/RO/ZI Use Internal SRAM
#define PMIC_INTERNAL_SRAM

#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#define BANKS_NUM                       1
#define PMIC_MAX_REG_NUM                0x0FFF // Register BUCK1, Register ANALDO, Register DIGLDO (0x0470)
//#define PMIC_MAX_REG_NUM                0x40FF // Register BUCK1, Register ANALDO, Register DIGLDO (0x0470)

#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
__attribute__ ((zero_init)) 
#endif /* __MTK_TARGET__ */
kal_uint16 pmic6320_reg[PMIC_MAX_REG_NUM];
kal_uint32 ANDERSON_DEBUG = 99;
kal_uint32 ANDERSON_PMIC_CONTROL = 99;
kal_uint32 Anderson_before = 99;
kal_uint32 Anderson_sel = 0;
kal_uint32 Anderson_flag = 0;
kal_uint32 Anderson_offset = 0;
kal_uint32 Anderson_mask = 0;
kal_uint32 Anderson_shift = 0;
kal_uint32 Anderson_wacs1_addr = 0;
kal_uint32 Anderson_wacs1_data = 0;

const PMIC_FLAG_TABLE_ENTRY pmic_flags_table[] = 
{
    {STATUS0,		STATUS_VSIM1_EN_MASK,		STATUS_VSIM1_EN_SHIFT,		},
    {STATUS0,		STATUS_VSIM2_EN_MASK,		STATUS_VSIM2_EN_SHIFT,		},
    {OCSTATUS0,		OC_STATUS_VSIM1_MASK,		OC_STATUS_VSIM1_SHIFT,		},
    {OCSTATUS0,		OC_STATUS_VSIM2_MASK,		OC_STATUS_VSIM2_SHIFT,		},
    {SIMLS_CON,		RG_SIMLS2_SRST_CONF_MASK,		RG_SIMLS2_SRST_CONF_SHIFT,		},
    {SIMLS_CON,		RG_SIMLS2_SCLK_CONF_MASK,		RG_SIMLS2_SCLK_CONF_SHIFT,		},
    {SIMLS_CON,		RG_SIMLS1_SRST_CONF_MASK,		RG_SIMLS1_SRST_CONF_SHIFT,		},
    {SIMLS_CON,		RG_SIMLS1_SCLK_CONF_MASK,		RG_SIMLS1_SCLK_CONF_SHIFT,		},
    {TDSEL_CON,		RG_SIMLS_TDSEL_MASK,		RG_SIMLS_TDSEL_SHIFT,		},
    {TDSEL_CON,		RG_SIMAP_TDSEL_MASK,		RG_SIMAP_TDSEL_SHIFT,		},
    {RDSEL_CON,		RG_SIMLS_RDSEL_MASK,		RG_SIMLS_RDSEL_SHIFT,		},
    {RDSEL_CON,		RG_SIMAP_RDSEL_MASK,		RG_SIMAP_RDSEL_SHIFT,		},
    {DRV_CON10,		RG_OCTL_SIM1_AP_SRST_MASK,		RG_OCTL_SIM1_AP_SRST_SHIFT,		},
    {DRV_CON10,		RG_OCTL_SIM1_AP_SCLK_MASK,		RG_OCTL_SIM1_AP_SCLK_SHIFT,		},
    {DRV_CON11,		RG_OCTL_SIMLS1_SRST_MASK,		RG_OCTL_SIMLS1_SRST_SHIFT,		},
    {DRV_CON11,		RG_OCTL_SIMLS1_SCLK_MASK,		RG_OCTL_SIMLS1_SCLK_SHIFT,		},
    {DRV_CON11,		RG_OCTL_SIM2_AP_SRST_MASK,		RG_OCTL_SIM2_AP_SRST_SHIFT,		},
    {DRV_CON11,		RG_OCTL_SIM2_AP_SCLK_MASK,		RG_OCTL_SIM2_AP_SCLK_SHIFT,		},
    {DRV_CON12,		RG_OCTL_SIMLS2_SRST_MASK,		RG_OCTL_SIMLS2_SRST_SHIFT,		},
    {DRV_CON12,		RG_OCTL_SIMLS2_SCLK_MASK,		RG_OCTL_SIMLS2_SCLK_SHIFT,		},
    {VIO18_CON2,		RG_VIO18_MODESET_MASK,		RG_VIO18_MODESET_SHIFT,		},
    {VPA_CON2,		RG_VPA_MODESET_MASK,		RG_VPA_MODESET_SHIFT,		},
    {VPA_CON7,		VPA_EN_MASK,		VPA_EN_SHIFT,		},
    {VRF18_CON2,		RG_VRF18_MODESET_MASK,		RG_VRF18_MODESET_SHIFT,		},
    {VRF18_CON4,		RG_VRF18_BK_LDO_MASK,		RG_VRF18_BK_LDO_SHIFT,		},
    {VRF18_CON5,		VRF18_EN_CTRL_MASK,		VRF18_EN_CTRL_SHIFT,		},
    {VRF18_CON7,		VRF18_EN_MASK,		VRF18_EN_SHIFT,		},
    {VRF18_2_CON2,		RG_VRF18_2_MODESET_MASK,		RG_VRF18_2_MODESET_SHIFT,		},
    {VRF18_2_CON4,		RG_VRF18_2_BK_LDO_MASK,		RG_VRF18_2_BK_LDO_SHIFT,		},
    {VRF18_2_CON5,		VRF18_2_EN_CTRL_MASK,		VRF18_2_EN_CTRL_SHIFT,		},
    {VRF18_2_CON6,		VRF18_2_EN_SEL_MASK,		VRF18_2_EN_SEL_SHIFT,		},
    {VRF18_2_CON7,		VRF18_2_EN_MASK,		VRF18_2_EN_SHIFT,		},
    {ANALDO_CON0,		VRF28_ON_CTRL_MASK,		VRF28_ON_CTRL_SHIFT,		},
    {ANALDO_CON0,		RG_VRF28_EN_MASK,		RG_VRF28_EN_SHIFT,		},
    {ANALDO_CON0,		VRF28_SRCLK_EN_SEL_MASK,		VRF28_SRCLK_EN_SEL_SHIFT,		},
    {ANALDO_CON13,		VRF28_ON_2_CTRL_MASK,		VRF28_ON_2_CTRL_SHIFT,		},
    {ANALDO_CON13,		RG_VRF28_2_EN_MASK,		RG_VRF28_2_EN_SHIFT,		},
    {ANALDO_CON13,		VRF28_2_SRCLK_EN_SEL_MASK,		VRF28_2_SRCLK_EN_SEL_SHIFT,		},
    {DIGLDO_CON13,		RG_VSIM1_EN_MASK,		RG_VSIM1_EN_SHIFT,		},
    {DIGLDO_CON13,		RG_VSIM1_STBTD_MASK,		RG_VSIM1_STBTD_SHIFT,		},
    {DIGLDO_CON13,		QI_VSIM1_MODE_MASK,		QI_VSIM1_MODE_SHIFT,		},
    {DIGLDO_CON13,		VSIM1_SRCLK_MODE_SEL_MASK,		VSIM1_SRCLK_MODE_SEL_SHIFT,		},
    {DIGLDO_CON13,		VSIM1_LP_MODE_SET_MASK,		VSIM1_LP_MODE_SET_SHIFT,		},
    {DIGLDO_CON13,		VSIM1_LP_SEL_MASK,		VSIM1_LP_SEL_SHIFT,		},
    {DIGLDO_CON14,		RG_VSIM2_EN_MASK,		RG_VSIM2_EN_SHIFT,		},
    {DIGLDO_CON14,		RG_VSIM2_STBTD_MASK,		RG_VSIM2_STBTD_SHIFT,		},
    {DIGLDO_CON14,		QI_VSIM2_MODE_MASK,		QI_VSIM2_MODE_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_SRCLK_MODE_SEL_MASK,		VSIM2_SRCLK_MODE_SEL_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_THER_SHDN_EN_MASK,		VSIM2_THER_SHDN_EN_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_LP_MODE_SET_MASK,		VSIM2_LP_MODE_SET_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_LP_SEL_MASK,		VSIM2_LP_SEL_SHIFT,		},
    {DIGLDO_CON19,		QI_VSIM1_OC_STATUS_MASK,		QI_VSIM1_OC_STATUS_SHIFT,		},
    {DIGLDO_CON19,		QI_VSIM2_OC_STATUS_MASK,		QI_VSIM2_OC_STATUS_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_CAL_MASK,		RG_VSIM1_CAL_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_VOSEL_MASK,		RG_VSIM1_VOSEL_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_STB_SEL_MASK,		RG_VSIM1_STB_SEL_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_OCFB_MASK,		RG_VSIM1_OCFB_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_NDIS_EN_MASK,		RG_VSIM1_NDIS_EN_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_CAL_MASK,		RG_VSIM2_CAL_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_VOSEL_MASK,		RG_VSIM2_VOSEL_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_STB_SEL_MASK,		RG_VSIM2_STB_SEL_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_OCFB_MASK,		RG_VSIM2_OCFB_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_NDIS_EN_MASK,		RG_VSIM2_NDIS_EN_SHIFT,		},
    {DIGLDO_CON44,		VSIM1_ON_CTRL_MASK,		VSIM1_ON_CTRL_SHIFT,		},
    {DIGLDO_CON44,		VSIM2_ON_CTRL_MASK,		VSIM2_ON_CTRL_SHIFT,		},
};

#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
__attribute__ ((zero_init)) 
#endif /* __MTK_TARGET__ */
kal_uint8 pmic6320_eco_version;

//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////
extern kal_bool pmic6320_reg_write(kal_uint16 reg, kal_uint16 val);
extern kal_bool pmic6320_reg_read(kal_uint16 reg, kal_uint16 *pVal);

// Write Whole Bytes
void dcl_pmic6320_byte_write(DCL_UINT16 addr, DCL_UINT16 val)
{
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)     
    
    if(addr <= PMIC_MAX_REG_NUM)
    {
        pmic6320_reg[addr] = val;
    }
       
#if defined(__MD1__)    
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, addr, val, 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, addr, val, 0x00);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)   
}

// Write register field
void dcl_pmic6320_field_write(PMIC_FLAGS_LIST_ENUM flag, DCL_UINT16 sel)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)  

    Anderson_before = pmic6320_reg[pTable[flag].offset];
    pmic6320_reg[pTable[flag].offset] &= ~(pTable[flag].mask << pTable[flag].shift);
    pmic6320_reg[pTable[flag].offset] |= ((kal_uint16)sel << pTable[flag].shift);    
#if defined(__MD1__)    
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, PMIC_BASE + pTable[flag].offset, pmic6320_reg[pTable[flag].offset], 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, PMIC_BASE + pTable[flag].offset, pmic6320_reg[pTable[flag].offset], 0x00);
#endif
    Anderson_sel = sel;
    Anderson_flag = flag;
    Anderson_offset = pTable[flag].offset;
    Anderson_mask = pTable[flag].mask;
    Anderson_shift = pTable[flag].shift;
    Anderson_wacs1_addr = PMIC_BASE + pTable[flag].offset;
    Anderson_wacs1_data = pmic6320_reg[pTable[flag].offset];

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)  
}

// Read register field
DCL_UINT16 dcl_pmic6320_field_read(PMIC_FLAGS_LIST_ENUM flag)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    kal_uint32 savedMask = 0;
    DCL_UINT16 reg_return = 0;
    
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

#if defined(__MD1__)
    DrvPWRAP_WACS0(PMIC_WRAP_READ, PMIC_BASE + pTable[flag].offset, 0x00, &pmic6320_reg[pTable[flag].offset]);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, PMIC_BASE + pTable[flag].offset, 0x00, &pmic6320_reg[pTable[flag].offset]);
#endif

    reg_return = ((pmic6320_reg[pTable[flag].offset] & (pTable[flag].mask << pTable[flag].shift)) >> pTable[flag].shift);

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)    

    return reg_return;   
}

//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
DCL_UINT16 dcl_pmic6320_byte_return(DCL_UINT16 addr)
{
    DCL_UINT16 reg_temp;
    kal_uint32 savedMask = 0;    
    
#if !defined(__UBL__) && !defined(__FUE__)
    savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

#if defined(__MD1__)   
    DrvPWRAP_WACS0(PMIC_WRAP_READ, PMIC_BASE + (DCL_UINT32)addr, 0x00, &reg_temp);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, PMIC_BASE + (DCL_UINT32)addr, 0x00, &reg_temp);    
#endif
    if(addr <= PMIC_MAX_REG_NUM)
    {
        pmic6320_reg[addr] = reg_temp;
        
    }

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)   

    return reg_temp;
}

// Exported for EM used
void pmic6320_EM_reg_write(kal_uint16 reg, kal_uint16 val){
    dcl_pmic6320_byte_write(reg, val);
}

kal_uint8 pmic6320_EM_reg_read(kal_uint16 reg){
    return  dcl_pmic6320_byte_return(reg);
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic_get_ECO_version()
{
    return PMIC_ECO_E1;
}

/*
const DCL_UINT32 vpa_vosel[] =
{
    PMU_VOLT_00_500000_V,   PMU_VOLT_00_550000_V,   PMU_VOLT_00_600000_V,   PMU_VOLT_00_650000_V,   
    PMU_VOLT_00_700000_V,   PMU_VOLT_00_750000_V,   PMU_VOLT_00_800000_V,   PMU_VOLT_00_850000_V,   
    PMU_VOLT_00_900000_V,   PMU_VOLT_00_950000_V,   PMU_VOLT_01_000000_V,   PMU_VOLT_01_050000_V,   
    PMU_VOLT_01_100000_V,   PMU_VOLT_01_150000_V,   PMU_VOLT_01_200000_V,   PMU_VOLT_01_250000_V,   
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_350000_V,   PMU_VOLT_01_400000_V,   PMU_VOLT_01_450000_V,   
    PMU_VOLT_01_500000_V,   PMU_VOLT_01_550000_V,   PMU_VOLT_01_600000_V,   PMU_VOLT_01_650000_V,   
    PMU_VOLT_01_700000_V,   PMU_VOLT_01_750000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_850000_V,   
    PMU_VOLT_01_900000_V,   PMU_VOLT_01_950000_V,   PMU_VOLT_02_000000_V,   PMU_VOLT_02_050000_V,   
    PMU_VOLT_02_100000_V,   PMU_VOLT_02_150000_V,   PMU_VOLT_02_200000_V,   PMU_VOLT_02_250000_V,   
    PMU_VOLT_02_300000_V,   PMU_VOLT_02_350000_V,   PMU_VOLT_02_400000_V,   PMU_VOLT_02_450000_V,   
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_550000_V,   PMU_VOLT_02_600000_V,   PMU_VOLT_02_650000_V,   
    PMU_VOLT_02_700000_V,   PMU_VOLT_02_750000_V,   PMU_VOLT_02_800000_V,   PMU_VOLT_02_850000_V,   
    PMU_VOLT_02_900000_V,   PMU_VOLT_02_950000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_050000_V,   
    PMU_VOLT_03_100000_V,   PMU_VOLT_03_150000_V,   PMU_VOLT_03_200000_V,   PMU_VOLT_03_250000_V,   
    PMU_VOLT_03_300000_V,   PMU_VOLT_03_350000_V,   PMU_VOLT_03_400000_V,   PMU_VOLT_03_450000_V,   
    PMU_VOLT_03_500000_V,   PMU_VOLT_03_550000_V,   PMU_VOLT_03_600000_V,   PMU_VOLT_03_650000_V,   

};
*/

const DCL_UINT32 vpa_vosel[] =
{
    PMU_VOLT_00_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_600000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_00_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_00_800000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_00_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_000000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_01_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_200000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_01_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_400000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_01_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_600000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_01_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_01_800000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_01_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_000000_V,   PMU_VOLT_INVALID, 
    PMU_VOLT_02_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_200000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_02_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_400000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_02_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_600000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_02_700000_V,   PMU_VOLT_INVALID,   PMU_VOLT_02_800000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_02_900000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_000000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_03_100000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_200000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_03_300000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_400000_V,   PMU_VOLT_INVALID,   
    PMU_VOLT_03_500000_V,   PMU_VOLT_INVALID,   PMU_VOLT_03_600000_V,   PMU_VOLT_INVALID,   

};
const DCL_UINT32 vrf18_vosel[] =
{
    PMU_VOLT_01_050000_V,   PMU_VOLT_01_075000_V,   PMU_VOLT_01_100000_V,   PMU_VOLT_01_125000_V,
    PMU_VOLT_01_150000_V,   PMU_VOLT_01_175000_V,   PMU_VOLT_01_200000_V,   PMU_VOLT_01_225000_V,
    PMU_VOLT_01_250000_V,   PMU_VOLT_01_275000_V,   PMU_VOLT_01_300000_V,   PMU_VOLT_01_325000_V,
    PMU_VOLT_01_350000_V,   PMU_VOLT_01_375000_V,   PMU_VOLT_01_400000_V,   PMU_VOLT_01_425000_V,
    PMU_VOLT_01_450000_V,   PMU_VOLT_01_475000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_525000_V,    
    PMU_VOLT_01_550000_V,   PMU_VOLT_01_575000_V,   PMU_VOLT_01_600000_V,   PMU_VOLT_01_625000_V,    
    PMU_VOLT_01_650000_V,   PMU_VOLT_01_675000_V,   PMU_VOLT_01_700000_V,   PMU_VOLT_01_725000_V,        
    PMU_VOLT_01_750000_V,   PMU_VOLT_01_775000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_825000_V,    
};

const DCL_UINT32 vrf28_vosel[] =
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_02_800000_V,    
};

const DCL_UINT32 vsim1_vosel[] =
{
    PMU_VOLT_01_200000_V,   PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,
    PMU_VOLT_02_500000_V,   PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_300000_V,
};

const DCL_INT32 vsim1_cal[]=
{
    PMU_VOLT_CAL_00_000000_V,       PMU_VOLT_CAL_MINUS_00_020000_V, PMU_VOLT_CAL_MINUS_00_040000_V,	PMU_VOLT_CAL_MINUS_00_060000_V,
	PMU_VOLT_CAL_MINUS_00_080000_V, PMU_VOLT_CAL_MINUS_00_100000_V,	PMU_VOLT_CAL_MINUS_00_120000_V,	PMU_VOLT_CAL_MINUS_00_140000_V,
	PMU_VOLT_CAL_00_160000_V,		PMU_VOLT_CAL_00_140000_V,	    PMU_VOLT_CAL_00_120000_V,		PMU_VOLT_CAL_00_100000_V,
	PMU_VOLT_CAL_00_080000_V,		PMU_VOLT_CAL_00_060000_V,       PMU_VOLT_CAL_00_040000_V,		PMU_VOLT_CAL_00_020000_V
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF18_1),		vrf18_vosel,		NULL,				GETARRNUM(vrf18_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF18_2),		vrf18_vosel,		NULL,				GETARRNUM(vrf18_vosel)		},          
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF28_1),		vrf28_vosel,		NULL,				GETARRNUM(vrf28_vosel)		},    
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF28_2),		vrf28_vosel,		NULL,				GETARRNUM(vrf28_vosel)		},     
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM),		    vsim1_vosel,		NULL,	    		GETARRNUM(vsim1_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		    vsim1_vosel,		NULL,   			GETARRNUM(vsim1_vosel)	    }, 
	{ENC(LDO_SET_CAL, VSIM1),			        vsim1_cal,	        NULL,				GETARRNUM(vsim1_cal)	    },        
	{ENC(LDO_SET_CAL, VSIM2),			        vsim1_cal,	        NULL,				GETARRNUM(vsim1_cal)	    },                
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6320_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
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
                case VPA:
                {
                    dcl_pmic6320_field_write(VPA_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                case VRF18_1:
                {
                    dcl_pmic6320_field_write(VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF18_2:
                {
                    dcl_pmic6320_field_write(VRF18_2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_1:
                {
                    dcl_pmic6320_field_write(RG_VRF28_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_2:
                {
                    dcl_pmic6320_field_write(RG_VRF28_2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                case VSIM:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                //1. It's not allow to disable VTCXO in register control mode,
                //   because of MT6320 may not have external 32K.
                //2. Control VTCXO on/off status in srclken control mode is meaningless.
                //1+2 => There is no requirement to configure VTCXO on/off status.
#if defined(__MEUT__)
                case VTCXO:
                {
                    //dcl_pmic6320_field_write(RG_VTCXO_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
#endif

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_SET_THER_SHDN_EN:
        {
            PMU_CTRL_LDO_BUCK_SET_THER_SHDN_EN *pLdoBuckCtrl =& (data->rPMULdoBuckSetTherShdnEn);

            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    return_val = STATUS_UNSUPPORTED;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(VSIM2_THER_SHDN_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        
        case LDO_BUCK_SET_LP_MODE_SET:
        {
            PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET *pLdoBuckCtrl =& (data->rPMULdoBuckSetLpModeSet);

            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(VSIM1_LP_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(VSIM2_LP_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        
        case LDO_BUCK_SET_LP_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_LP_SEL *pLdoBuckCtrl =& (data->rPMULdoBuckSetLpSel);

            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(VSIM1_LP_SEL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(VSIM2_LP_SEL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;        

        case LDO_BUCK_SET_STB_TD:
        {
            PMU_CTRL_LDO_BUCK_SET_STB_TD *pLdoBuckCtrl =& (data->rPMULdoBuckSetStbTd);

            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_STBTD, pLdoBuckCtrl->delayTimeIdx);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_STBTD, pLdoBuckCtrl->delayTimeIdx);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        
        case LDO_BUCK_GET_EN_STATUS:
        {
            PMU_CTRL_LDO_BUCK_GET_EN_STATUS *pLdoBuckCtrl = &(data->rPMULdoBuckGetEnStatus);
            switch(pLdoBuckCtrl->mod)
            {
                case VSIM:
                {
                    pLdoBuckCtrl->enable = (DCL_BOOL)dcl_pmic6320_field_read(STATUS_VSIM1_EN);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    pLdoBuckCtrl->enable = (DCL_BOOL)dcl_pmic6320_field_read(STATUS_VSIM2_EN);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_1:
                {
                    //dcl_pmic6320_field_write(RG_VRF18_ON_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_UNSUPPORTED;
                }
                break;

                case VRF28_2:
                {
                    return_val = STATUS_UNSUPPORTED;
                }
                break;                

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        
        case LDO_BUCK_GET_QI_MODE:
        {
            PMU_CTRL_LDO_BUCK_GET_QI_MODE *pLdoBuckCtrl = &(data->rPMULdoBuckGetQiMode);
            switch(pLdoBuckCtrl->mod)
            {
                case VSIM1:
                {
                    pLdoBuckCtrl->mode = (DCL_BOOL)dcl_pmic6320_field_read(QI_VSIM1_MODE);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    pLdoBuckCtrl->mode = (DCL_BOOL)dcl_pmic6320_field_read(QI_VSIM2_MODE);
                    return_val = STATUS_OK;
                }
                break;          
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_GET_OC_STATUS:
        {
            PMU_CTRL_LDO_BUCK_GET_OC_STATUS *pLdoBuckCtrl = &(data->rPMULdoBuckGetOcStatus);
            switch(pLdoBuckCtrl->mod)
            {
                case VSIM:
                {
                    pLdoBuckCtrl->status = (DCL_BOOL)dcl_pmic6320_field_read(OC_STATUS_VSIM1);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    pLdoBuckCtrl->status = (DCL_BOOL)dcl_pmic6320_field_read(OC_STATUS_VSIM2);
                    return_val = STATUS_OK;
                }
                break;      

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;

        case LDO_BUCK_GET_QI_OC_STATUS:
        {
            PMU_CTRL_LDO_BUCK_GET_QI_OC_STATUS *pLdoBuckCtrl = &(data->rPMULdoBuckGetQiOcStatus);
            switch(pLdoBuckCtrl->mod)
            {
                case VSIM:
                {
                    pLdoBuckCtrl->status = (DCL_BOOL)dcl_pmic6320_field_read(QI_VSIM1_OC_STATUS);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    pLdoBuckCtrl->status = (DCL_BOOL)dcl_pmic6320_field_read(QI_VSIM2_OC_STATUS);
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
                case VRF18_1:
                {
                    dcl_pmic6320_field_write(VRF18_EN_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;

                case VRF18_2:
                {
                    dcl_pmic6320_field_write(VRF18_2_EN_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_1:
                {
                    dcl_pmic6320_field_write(VRF28_ON_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;  
                
                case VRF28_2:
                {
                    dcl_pmic6320_field_write(VRF28_ON_2_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;                
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;        
                
        
        case LDO_BUCK_SET_SRCLKEN_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_SRCLKEN_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetSrclkenSel);
            ANDERSON_PMIC_CONTROL = pLdoBuckCtrl->mod;
            switch(pLdoBuckCtrl->mod)
            {
                case VRF18_1:
                {
                    //dcl_pmic6320_field_write(VRF18_2_EN_SEL, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_UNSUPPORTED;
                }
                break;

                case VRF18_2:
                {
                    dcl_pmic6320_field_write(VRF18_2_EN_SEL, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_1:
                {
                    dcl_pmic6320_field_write(VRF28_SRCLK_EN_SEL, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_2:
                {
                    dcl_pmic6320_field_write(VRF28_2_SRCLK_EN_SEL, pLdoBuckCtrl->SrclkenSel);
                    ANDERSON_DEBUG = pLdoBuckCtrl->SrclkenSel;
                    return_val = STATUS_OK;
                }
                break;                

                case VSIM1:
                {
                    dcl_pmic6320_field_write(VSIM1_SRCLK_MODE_SEL, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(VSIM2_SRCLK_MODE_SEL, pLdoBuckCtrl->SrclkenSel);
                    return_val = STATUS_UNSUPPORTED;
                }
                break;   
                
                default:
                    return_val = STATUS_OK;
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
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_VOSEL, regVal);
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
                case VRF18_1:
                {
                    //dcl_pmic6320_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF18_2:
                {
                    //dcl_pmic6320_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_1:
                {
                    //dcl_pmic6320_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VRF28_2:
                {
                    //dcl_pmic6320_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                case VSIM:
                {
                    //dcl_pmic6320_field_write(RG_VSIM_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    //dcl_pmic6320_field_write(RG_VSIM_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }	
        break;
        
		case LDO_BUCK_SET_STB_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_STB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetStbEn);
	
            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_STB_SEL, !(pLdoBuckCtrl->enable));
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_STB_SEL, !(pLdoBuckCtrl->enable));
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }            
		}
		break;      
        
		case LDO_BUCK_SET_OCFB_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_OCFB_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetOcfbEn);
	
            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_OCFB, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_OCFB, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }            
		}
		break;            

		case LDO_BUCK_SET_NDIS_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_NDIS_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetNdisEn);
	
            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_NDIS_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_NDIS_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }            
		}
		break;   

		case LDO_BUCK_SET_ON_CTRL:
		{
			PMU_CTRL_LDO_BUCK_SET_ON_CTRL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnCtrl);
	
            switch(pLdoBuckCtrl->mod)
            {               
                case VSIM1:
                {
                    dcl_pmic6320_field_write(VSIM1_ON_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(VSIM2_ON_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }            
		}
		break;   
                
        case LDO_SET_CAL:
        {
            PMU_CTRL_LDO_SET_CAL *pLdoCtrl = &(data->rPMULdoSetCal);
            DCL_UINT16 val;
            
            val = PMU_Parameter_to_Value(ENC(LDO_SET_CAL, pLdoCtrl->mod), pLdoCtrl->voltage);
		    if (val == PARAMETER_UNKNOWN)
			    return STATUS_UNSUPPORTED;
            
            switch(pLdoCtrl->mod)
            {
                case VSIM1:
                {
                    dcl_pmic6320_field_write(RG_VSIM1_CAL, val);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6320_field_write(RG_VSIM2_CAL, val);
                    return_val = STATUS_OK;
                }
                break;

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
        
        case VPA_SET_EN:
        {
            PMU_CTRL_VPA_SET_EN *pVpaSetEn = &(data->rPMUVpaSetEn);
            dcl_pmic6320_field_write(VPA_EN, pVpaSetEn->enable);
            return_val = STATUS_OK;
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
        
		case VRF18_SET_MODESET:
		{		
			PMU_CTRL_VRF18_SET_MODESET *pVrf18Ctrl = &(data->rPMUVrf18SetModeset);

			switch(pVrf18Ctrl->vrf18Idx)
			{
				case PMIC_VRF18_1:
				{
                    dcl_pmic6320_field_write(RG_VRF18_MODESET, pVrf18Ctrl->enable);
                    // This is for MT6320 E1 VIO28 Coupling VRF18 issue.
                    if(pmic6320_eco_version == PMIC6320_ECO_1_VERSION)
                    {
                        dcl_pmic6320_field_write(RG_VIO18_MODESET, pVrf18Ctrl->enable);
                    }
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VRF18_2:
				{
					dcl_pmic6320_field_write(RG_VRF18_2_MODESET, pVrf18Ctrl->enable);
                    // This is for MT6320 E1 VIO28 Coupling VRF18 issue.
                    if(pmic6320_eco_version == PMIC6320_ECO_1_VERSION)
                    {
                        dcl_pmic6320_field_write(RG_VIO18_MODESET, pVrf18Ctrl->enable);
                    }              
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;
        
		case VRF18_SET_BUCK_LDO_MODE:
		{		
			PMU_CTRL_VRF18_SET_BUCK_LDO_MODE *pVrf18Ctrl = &(data->rPMUVrf18SetBuckLdoMode);

			switch(pVrf18Ctrl->vrf18Idx)
			{
				case PMIC_VRF18_1:
				{
                    dcl_pmic6320_field_write(RG_VRF18_BK_LDO, pVrf18Ctrl->mode);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VRF18_2:
				{
					dcl_pmic6320_field_write(RG_VRF18_2_BK_LDO, pVrf18Ctrl->mode);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;
        
        case VRF18_SET_FPWM:
        {
            PMU_CTRL_VRF18_SET_FPWM *pVrf18SetFpwm = (PMU_CTRL_VRF18_SET_FPWM *)data;
            dcl_pmic6320_field_write(RG_VRF18_MODESET, pVrf18SetFpwm->enable);
           // dcl_pmic6320_field_write(RG_VRF18_MODESET, pVrf18SetFpwm->enable);
            return_val = STATUS_OK;
        }
        break;

        case VPA_SET_FPWM:
        {
            PMU_CTRL_VPA_SET_FPWM *pVpaSetFpwm = (PMU_CTRL_VPA_SET_FPWM *)data;
            dcl_pmic6320_field_write(RG_VPA_MODESET, pVpaSetFpwm->enable);
            return_val = STATUS_OK;
        }
        break;        

        case SIMLS_SET_SRST_CONF:
		{		
            PMU_CTRL_SIMLS_SET_SRST_CONF *pSimLsCtrl = &(data->rPMUSimlsSetSrstConf);

			switch(pSimLsCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_SIMLS1_SRST_CONF, (DCL_UINT16)pSimLsCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_SIMLS2_SRST_CONF, (DCL_UINT16)pSimLsCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;

        case SIMLS_SET_SCLK_CONF:
		{		
            PMU_CTRL_SIMLS_SET_SCLK_CONF *pSimLsCtrl = &(data->rPMUSimlsSetSclkConf);

			switch(pSimLsCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_SIMLS1_SCLK_CONF, (DCL_UINT16)pSimLsCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_SIMLS2_SCLK_CONF, (DCL_UINT16)pSimLsCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;       

        case OCTL_SET_SIM_AP_SRST:
		{		
            PMU_CTRL_OCTL_SET_SIM_AP_SRST *pSimCtrl = &(data->rPMUOctlSetSimApSrst);

			switch(pSimCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_OCTL_SIM1_AP_SRST, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_OCTL_SIM2_AP_SRST, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;    

        case OCTL_SET_SIM_AP_SCLK:
		{		
            PMU_CTRL_OCTL_SET_SIM_AP_SCLK *pSimCtrl = &(data->rPMUOctlSetSimApSclk);

			switch(pSimCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_OCTL_SIM1_AP_SCLK, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_OCTL_SIM2_AP_SCLK, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;    

        case OCTL_SET_SIMLS_SRST:
		{		
            PMU_CTRL_OCTL_SET_SIMLS_SRST *pSimCtrl = &(data->rPMUOctlSetSimlsSrst);

			switch(pSimCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_OCTL_SIMLS1_SRST, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_OCTL_SIMLS2_SRST, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;    
        
        case OCTL_SET_SIMLS_SCLK:
		{		
            PMU_CTRL_OCTL_SET_SIMLS_SCLK *pSimCtrl = &(data->rPMUOctlSetSimlsSclk);

			switch(pSimCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6320_field_write(RG_OCTL_SIMLS1_SCLK, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6320_field_write(RG_OCTL_SIMLS2_SCLK, (DCL_UINT16)pSimCtrl->regval);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}			
		}
		break;   
        
        case SIMLS_SET_TDSEL:
        {
            PMU_CTRL_SIMLS_SET_TDSEL *pSimlsCtrl = &(data->rPMUSimlsSetTdsel);
            dcl_pmic6320_field_write(RG_SIMLS_TDSEL, (DCL_UINT16)pSimlsCtrl->regval);
            return_val = STATUS_OK;
        }
        break;
        
        case SIMAP_SET_TDSEL:
        {
            PMU_CTRL_SIMAP_SET_TDSEL *pSimlsCtrl = &(data->rPMUSimapSetTdsel);
            dcl_pmic6320_field_write(RG_SIMAP_TDSEL, (DCL_UINT16)pSimlsCtrl->regval);
            return_val = STATUS_OK;
        }
        break;

        case SIMLS_SET_RDSEL:
        {
            PMU_CTRL_SIMLS_SET_RDSEL *pSimlsCtrl = &(data->rPMUSimlsSetRdsel);
            dcl_pmic6320_field_write(RG_SIMLS_RDSEL, (DCL_UINT16)pSimlsCtrl->regval);
            return_val = STATUS_OK;
        }
        break;
        
        case SIMAP_SET_RDSEL:
        {
            PMU_CTRL_SIMAP_SET_RDSEL *pSimlsCtrl = &(data->rPMUSimapSetRdsel);
            dcl_pmic6320_field_write(RG_SIMAP_RDSEL, (DCL_UINT16)pSimlsCtrl->regval);
            return_val = STATUS_OK;
        }
        break;        
                
/*
        case VRF18_SET_BUCK_LDO_MODE:
        {
            PMU_CTRL_VRF18_SET_BUCK_LDO_MODE *pVrf18SetBuckLdoMode = (PMU_CTRL_VRF18_SET_BUCK_LDO_MODE *)data;
            dcl_pmic6320_field_write(RG_VRF18_BK_LDO, pVrf18SetBuckLdoMode->mode);
            return_val = STATUS_OK;
        }
        break;        
*/
        case MISC_SET_REGISTER_VALUE:
        {			
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            pmic6320_EM_reg_write(pChrCtrl->offset, pChrCtrl->value);
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            pChrCtrl->value = pmic6320_EM_reg_read(pChrCtrl->offset);
            return_val = STATUS_OK;
        }
        break;

        default:				
            return_val = STATUS_UNSUPPORTED;
        break;
    }

    return return_val;

}

extern void dcl_pmic6320_internal_init(void);

void dcl_pmic6320_init(void){
    kal_uint32 i;

	pmu_control_handler = PMIC6320_control_handler;
	pmu_parameter_size = GETARRNUM(pmu_parameter_table);
#if  !defined(__SMART_PHONE_MODEM__)    
    DrvPWRAP_Init();
#endif    
    pmic6320_eco_version = PMIC6320_ECO_1_VERSION;

    // Get PMIC6320 ECO version
    {
        kal_uint16 eco_version = 0;
        eco_version = dcl_pmic6320_byte_return(CID);       

        if (eco_version == MT6320_E1_CID)
        {
            pmic6320_eco_version = PMIC6320_ECO_1_VERSION;
        }
        else
        {
            pmic6320_eco_version = PMIC6320_ECO_2_VERSION;
        }
        
    }

    for (i = 0;i < PMIC_MAX_REG_NUM; i++){
        pmic6320_reg[i] = dcl_pmic6320_byte_return(i); 
    }
#if !defined(__SMART_PHONE_MODEM__)    
    dcl_pmic6320_internal_init();
#endif
   
  //  pmic6320_customization_init();

}

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    return dcl_pmic6320_byte_return(pmic_addr);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    dcl_pmic6320_byte_write(pmic_addr, value);
}

void PMIC6320_Read_All(void)
{
    kal_uint32 i;
    for (i = 0;i < PMIC_MAX_REG_NUM; i++){
        pmic6320_reg[i] = dcl_pmic6320_byte_return(i); 
    }
}

#endif //#if (defined(PMIC_6320_REG_API))

