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
 *		dcl_pmic6323.c
 *
 * Project:
 * --------
 *   	Maui_Software
 *
 * Description:
 * ------------
 *		This file is for PMIC 6323
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "pmic_wrap.h"
#include "kal_public_api.h"
#include "us_timer.h"

#if defined(PMIC_6323_REG_API)

// Start PMIC_UNIT_TEST
// #define PMIC_UNIT_TEST

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
#define PMIC_MAX_REG_NUM                0x0800 // 0x0001~0x07FF
#define GPIO_MAX_REG_NUM                0x0100 // 0x0001~0x00FF
//#define PMIC_MAX_REG_NUM                0x40FF // Register BUCK1, Register ANALDO, Register DIGLDO (0x0470)

//////////////////////////////////////////////////
//                Exported APIs                 //
//////////////////////////////////////////////////
extern kal_bool pmic6323_reg_write(kal_uint16 reg, kal_uint16 val);
extern kal_bool pmic6323_reg_read(kal_uint16 reg, kal_uint16 *pVal);
extern DCL_BOOL dcl_pmic_init_done_query(void);
typedef enum
{
    AUXADC_READ_INIT = 0,
    AUXADC_READ_REQUEST = 1,
    AUXADC_READ_READY = 2,
    AUXADC_READ_BUSY = 3,
    AUXADC_READ_DATA = 4
}AUXADC_FSM;

typedef struct
{
    kal_uint32 command_flag;
    kal_uint32 reg_before_write;
    kal_uint32 write_value;
    kal_uint32 address_offset;
    kal_uint32 reg_mask;
    kal_uint32 reg_shift;
    kal_uint32 reg_addr;
    kal_uint32 reg_data;
}PMIC_REG_LOG;

AUXADC_FSM AUXADC_Status = AUXADC_READ_INIT;
PMIC_REG_LOG pmic_reg_log;

#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
__attribute__ ((zero_init)) 
#endif /* __MTK_TARGET__ */
kal_uint8 pmic6323_eco_version;
kal_uint16 pmic6323_reg[PMIC_MAX_REG_NUM];
kal_uint16 pmic6323_gpio_reg[GPIO_MAX_REG_NUM];
DCL_BOOL pmic_init_done = DCL_FALSE;
const PMIC_FLAG_TABLE_ENTRY pmic_flags_table[] = 
{
    {VPA_CON2,		RG_VPA_MODESET_MASK,		RG_VPA_MODESET_SHIFT,		},
    {VPA_CON7,		VPA_EN_MASK,		VPA_EN_SHIFT,		},
    {DIGLDO_CON12,		RG_STB_SIM1_SIO_MASK,		RG_STB_SIM1_SIO_SHIFT,		},
    {DIGLDO_CON13,		RG_VSIM1_EN_MASK,		RG_VSIM1_EN_SHIFT,		},
    {DIGLDO_CON13,		VSIM1_LP_MODE_SET_MASK,		VSIM1_LP_MODE_SET_SHIFT,		},
    {DIGLDO_CON13,		VSIM1_LP_SEL_MASK,		VSIM1_LP_SEL_SHIFT,		},
    {DIGLDO_CON14,		RG_VSIM2_EN_MASK,		RG_VSIM2_EN_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_LP_MODE_SET_MASK,		VSIM2_LP_MODE_SET_SHIFT,		},
    {DIGLDO_CON14,		VSIM2_LP_SEL_MASK,		VSIM2_LP_SEL_SHIFT,		},
    {DIGLDO_CON20,		RG_STB_SIM2_SIO_MASK,		RG_STB_SIM2_SIO_SHIFT,		},
    {DIGLDO_CON34,		RG_VSIM1_VOSEL_MASK,		RG_VSIM1_VOSEL_SHIFT,		},
    {DIGLDO_CON35,		RG_VSIM2_VOSEL_MASK,		RG_VSIM2_VOSEL_SHIFT,		},
    {DIGLDO_CON45,		RG_VRF18_EN_MASK,		RG_VRF18_EN_SHIFT,		},
    {DIGLDO_CON45,		VRF18_LP_MODE_SET_MASK,		VRF18_LP_MODE_SET_SHIFT,		},
    {DIGLDO_CON45,		VRF18_LP_SEL_MASK,		VRF18_LP_SEL_SHIFT,		},
    {DIGLDO_CON46,		VRF18_ON_CTRL_MASK,		VRF18_ON_CTRL_SHIFT,		},
    {AUXADC_ADC15,		RG_ADC_OUT_MD_MASK,		RG_ADC_OUT_MD_SHIFT,		},
    {AUXADC_ADC16,		RG_ADC_RDY_MD_MASK,		RG_ADC_RDY_MD_SHIFT,		},
    {AUXADC_CON20,		RG_MD_RQST_MASK,		RG_MD_RQST_SHIFT,		},
	{GPIO_DOUT1_SET,		GPIO15_DOUT_SET_MASK,		GPIO15_DOUT_SET_SHIFT,		},	
	{GPIO_DOUT1_CLR,		GPIO15_DOUT_CLR_MASK,		GPIO15_DOUT_CLR_SHIFT,		},	
	{GPIO_DOUT2_SET,		GPIO17_DOUT_SET_MASK,		GPIO17_DOUT_SET_SHIFT,		},	
	{GPIO_DOUT2_CLR,		GPIO17_DOUT_CLR_MASK,		GPIO17_DOUT_CLR_SHIFT,		},	
};

//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////

// Write Whole Bytes
void dcl_pmic6323_byte_write(DCL_UINT16 addr, DCL_UINT16 val)
{
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)     
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    if(addr <= PMIC_MAX_REG_NUM)
    {
        pmic6323_reg[addr] = val;
    }
       
#if defined(__MD1__)    
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, addr, val, 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, addr, val, 0x00);
#endif

#if defined(DCL_PMIC_ACCESS_TIME_LOG)    
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)   
}

// Write register field
void dcl_pmic6323_field_write(PMIC_FLAGS_LIST_ENUM flag, DCL_UINT16 sel)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)  

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    pmic_reg_log.command_flag = flag;
    pmic_reg_log.reg_before_write = pmic6323_reg[pTable[flag].offset];

    pmic6323_reg[pTable[flag].offset] &= ~(pTable[flag].mask << pTable[flag].shift);
    pmic6323_reg[pTable[flag].offset] |= ((kal_uint16)sel << pTable[flag].shift);    

#if defined(__MD1__)    
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, PMIC_BASE + pTable[flag].offset, pmic6323_reg[pTable[flag].offset], 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, PMIC_BASE + pTable[flag].offset, pmic6323_reg[pTable[flag].offset], 0x00);
#endif

    pmic_reg_log.write_value = sel;
    pmic_reg_log.address_offset = pTable[flag].offset;
    pmic_reg_log.reg_mask = pTable[flag].mask;
    pmic_reg_log.reg_shift = pTable[flag].shift;
    pmic_reg_log.reg_addr = PMIC_BASE + pTable[flag].offset;
    pmic_reg_log.reg_data = pmic6323_reg[pTable[flag].offset];

#if defined(DCL_PMIC_ACCESS_TIME_LOG)    
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)  
}

// Write register field for GPIO
void dcl_pmic6323_gpio_field_write(PMIC_FLAGS_LIST_ENUM flag, DCL_UINT16 sel)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

    pmic_reg_log.command_flag = flag;
    pmic_reg_log.reg_before_write = pmic6323_gpio_reg[pTable[flag].offset];
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    pmic6323_gpio_reg[pTable[flag].offset] &= ~(pTable[flag].mask << pTable[flag].shift);
    pmic6323_gpio_reg[pTable[flag].offset] |= ((kal_uint16)sel << pTable[flag].shift);    

#if defined(__MD1__)
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, GPIO_BASE + pTable[flag].offset, pmic6323_gpio_reg[pTable[flag].offset], 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, GPIO_BASE + pTable[flag].offset, pmic6323_gpio_reg[pTable[flag].offset], 0x00);
#endif

    pmic_reg_log.write_value = sel;
    pmic_reg_log.address_offset = pTable[flag].offset;
    pmic_reg_log.reg_mask = pTable[flag].mask;
    pmic_reg_log.reg_shift = pTable[flag].shift;
    pmic_reg_log.reg_addr = GPIO_BASE + pTable[flag].offset;
    pmic_reg_log.reg_data = pmic6323_gpio_reg[pTable[flag].offset];
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)    
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)    
}

//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
DCL_UINT16 dcl_pmic6323_byte_return(DCL_UINT16 addr)
{
    DCL_UINT16 reg_temp;
    kal_uint32 savedMask = 0;    
    
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

#if defined(__MD1__)   
    DrvPWRAP_WACS0(PMIC_WRAP_READ, PMIC_BASE + (DCL_UINT32)addr, 0x00, &reg_temp);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, PMIC_BASE + (DCL_UINT32)addr, 0x00, &reg_temp);    
#endif
    if(addr <= PMIC_MAX_REG_NUM)
    {
        pmic6323_reg[addr] = reg_temp;
        
    }
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)    
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)   

    return reg_temp;
}

// Read register field
DCL_UINT16 dcl_pmic6323_field_read(PMIC_FLAGS_LIST_ENUM flag)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    kal_uint32 savedMask = 0;
    DCL_UINT16 reg_return = 0;

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

#if defined(__MD1__)
    DrvPWRAP_WACS0(PMIC_WRAP_READ, PMIC_BASE + pTable[flag].offset, 0x00, &pmic6323_reg[pTable[flag].offset]);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, PMIC_BASE + pTable[flag].offset, 0x00, &pmic6323_reg[pTable[flag].offset]);
#endif

    reg_return = ((pmic6323_reg[pTable[flag].offset] & (pTable[flag].mask << pTable[flag].shift)) >> pTable[flag].shift);
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)    
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time = ust_get_current_time();
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].duration_time = ust_get_duration(pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time, pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].end_time);
#endif

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)    

    return reg_return;   
}

// Exported for EM used
void pmic6323_EM_reg_write(kal_uint16 reg, kal_uint16 val){
    dcl_pmic6323_byte_write(reg, val);
}

kal_uint16 pmic6323_EM_reg_read(kal_uint16 reg){
    return  dcl_pmic6323_byte_return(reg);
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

const DCL_UINT32 vsim1_vosel[] =
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_03_000000_V
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
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM),		    vsim1_vosel,		NULL,	    		GETARRNUM(vsim1_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		    vsim1_vosel,		NULL,   			GETARRNUM(vsim1_vosel)	    }, 
	{ENC(LDO_SET_CAL, VSIM1),			        vsim1_cal,	        NULL,				GETARRNUM(vsim1_cal)	    },        
	{ENC(LDO_SET_CAL, VSIM2),			        vsim1_cal,	        NULL,				GETARRNUM(vsim1_cal)	    },                
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6323_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
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
                case VRF18:
                {
                    dcl_pmic6323_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
               
                case VSIM:
                {
                    dcl_pmic6323_field_write(RG_VSIM1_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6323_field_write(RG_VSIM2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                //1. It's not allow to disable VTCXO in register control mode,
                //   because of MT6323 may not have external 32K.
                //2. Control VTCXO on/off status in srclken control mode is meaningless.
                //1+2 => There is no requirement to configure VTCXO on/off status.
#if defined(__MEUT__)
                case VTCXO:
                {
                    //dcl_pmic6323_field_write(RG_VTCXO_EN, pLdoBuckCtrl->enable);
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

        case LDO_BUCK_SET_LP_MODE_SET:
        {
            PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET *pLdoBuckCtrl =& (data->rPMULdoBuckSetLpModeSet);

            switch(pLdoBuckCtrl->mod)
            {               
                case VRF18:
                {
                    dcl_pmic6323_field_write(VRF18_LP_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    dcl_pmic6323_field_write(VSIM1_LP_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6323_field_write(VSIM2_LP_MODE_SET, pLdoBuckCtrl->enable);
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
                case VRF18:
                {
                    dcl_pmic6323_field_write(VRF18_LP_MODE_SET, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    dcl_pmic6323_field_write(VSIM1_LP_MODE_SET, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6323_field_write(VSIM2_LP_MODE_SET, pLdoBuckCtrl->onSel);
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
                case VSIM1:
                {
                    dcl_pmic6323_field_write(RG_VSIM1_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6323_field_write(RG_VSIM2_VOSEL, regVal);
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
                case VRF18:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6323_field_write(VRF18_ON_CTRL, pLdoBuckCtrl->mode);                    
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
            dcl_pmic6323_field_write(VPA_EN, pVpaSetEn->enable);
            return_val = STATUS_OK;
        }
        break;

        case VPA_SET_FPWM:
        {
            PMU_CTRL_VPA_SET_FPWM *pVpaSetFpwm = (PMU_CTRL_VPA_SET_FPWM *)data;
            dcl_pmic6323_field_write(RG_VPA_MODESET, pVpaSetFpwm->enable);
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

        case SIM_SET_STB_SIO_MODE:
        {
            PMU_CTRL_SIM_SET_STB_SIO_MODE *pSimCtrl = &(data->rPMUSimSetStbSioMode);

			switch(pSimCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6323_field_write(RG_STB_SIM1_SIO, pSimCtrl->mode);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6323_field_write(RG_STB_SIM2_SIO, pSimCtrl->mode);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}		
        }
        break;

        case SIMRST_SET_GPIO_SET:
        {   
            PMU_CTRL_SIMRST_SET_GPIO_SET *pSimrstCtrl = &(data->rPMUSimrstSetGpioSet);

			switch(pSimrstCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6323_gpio_field_write(GPIO15_DOUT_SET, DCL_TRUE);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6323_gpio_field_write(GPIO17_DOUT_SET, DCL_TRUE);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}		
        }
        break;        

        case SIMRST_SET_GPIO_CLR:
        {   
            PMU_CTRL_SIMRST_SET_GPIO_CLR *pSimrstCtrl = &(data->rPMUSimrstSetGpioClr);

			switch(pSimrstCtrl->vsimIdx)
			{
				case PMIC_VSIM1:
				{
                    dcl_pmic6323_gpio_field_write(GPIO15_DOUT_CLR, DCL_TRUE);
                    return_val = STATUS_OK;
				}
				break;	
                
				case PMIC_VSIM2:
				{
					dcl_pmic6323_gpio_field_write(GPIO17_DOUT_CLR, DCL_TRUE);
                    return_val = STATUS_OK;
				}
				break;					
                
				default:				
				return_val = STATUS_UNSUPPORTED;
				break;			
			}		
        }
        break;

        case ADC_SET_RQST:
        {
            PMU_CTRL_ADC_SET_RQST *pAdcCtrl = &(data->rPMUAdcSetRqst);
            if((AUXADC_Status != AUXADC_READ_INIT) && (AUXADC_Status != AUXADC_READ_DATA))
            {
                ASSERT(0);
            }

            dcl_pmic6323_byte_write(TOP_CKPDN1_SET, (0x1 << RG_CLKSQ_EN_AUX_MD_SHIFT));
            dcl_pmic6323_byte_write(AUXADC_CON27, (0x0 << 15));
            dcl_pmic6323_field_write(RG_MD_RQST, 0x0); // Need Set 0 first
			
            dcl_pmic6323_field_write(RG_MD_RQST, pAdcCtrl->enable);
            AUXADC_Status = AUXADC_READ_REQUEST;
            return_val = STATUS_OK;
        }
        break;

        case ADC_GET_RDY_MD:
        {
            PMU_CTRL_ADC_GET_RDY_MD *pAdcCtrl = &(data->rPMUAdcGetRdyMd);
#if defined(FPGA_CTP)
            dbg_print("[PMIC_WRAP_MD] ADC Data Status = %x\n", dcl_pmic6323_field_read(RG_ADC_RDY_MD));
#endif
            pAdcCtrl->status = (DCL_BOOL)dcl_pmic6323_field_read(RG_ADC_RDY_MD);
            if((AUXADC_Status != AUXADC_READ_REQUEST) && (AUXADC_Status != AUXADC_READ_BUSY))
            {
                ASSERT(0);
            }            
            
            if(pAdcCtrl->status == DCL_TRUE)
            {
                AUXADC_Status = AUXADC_READ_READY;
            }
            else
            {
                AUXADC_Status = AUXADC_READ_BUSY;    
            }
                     
            return_val = STATUS_OK;
        }
        break;

        case ADC_GET_OUT_MD:
        {
            PMU_CTRL_ADC_GET_OUT_MD *pAdcCtrl = &(data->rPMUAdcGetOutMd);
            if(AUXADC_Status != AUXADC_READ_READY)
            {
                ASSERT(0);
            }
            pAdcCtrl->data = (DCL_UINT32)dcl_pmic6323_field_read(RG_ADC_OUT_MD); 
            AUXADC_Status = AUXADC_READ_DATA;
            dcl_pmic6323_field_write(RG_MD_RQST, 0x0);
            dcl_pmic6323_byte_write(TOP_CKPDN1_CLR, (0x1 << RG_CLKSQ_EN_AUX_MD_SHIFT));
            dcl_pmic6323_byte_write(AUXADC_CON27, (0x1 << 15));
			
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_SET_REGISTER_VALUE:
        {			
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            pmic6323_EM_reg_write(pChrCtrl->offset, pChrCtrl->value);
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            pChrCtrl->value = pmic6323_EM_reg_read(pChrCtrl->offset);
            return_val = STATUS_OK;
        }
        break;

        default:				
            return_val = STATUS_UNSUPPORTED;
        break;
    }

    return return_val;

}

extern void dcl_pmic6323_internal_init(void);
#if defined(PMIC_UNIT_TEST)
extern void PMIC_Read_All(void);
extern void PMIC_Unit_Test(void);
#endif
    

void dcl_pmic6323_init(void){
    kal_uint32 i;

	pmu_control_handler = PMIC6323_control_handler;
	pmu_parameter_size = GETARRNUM(pmu_parameter_table);
    
    pmic_wrap_dump_init();

#if  !defined(__SMART_PHONE_MODEM__)    
     DrvPWRAP_Init();
#endif    
    pmic6323_eco_version = PMIC6323_ECO_1_VERSION;

    // Get PMIC6323 ECO version
    {
        kal_uint16 eco_version = 0;
        eco_version = dcl_pmic6323_byte_return(CID);       

        if (eco_version == MT6323_E1_CID)
        {
            pmic6323_eco_version = PMIC6323_ECO_1_VERSION;
        }
        else
        {
            pmic6323_eco_version = PMIC6323_ECO_2_VERSION;
        }
        
    }

    for (i = 0; i < PMIC_MAX_REG_NUM; i += 2){
        pmic6323_reg[i] = dcl_pmic6323_byte_return(i); 
    }

#if !defined(__SMART_PHONE_MODEM__)    
    dcl_pmic6323_modem_init();
#endif
    dcl_pmic6323_internal_init();

  //  pmic6323_customization_init();
#if defined(PMIC_UNIT_TEST)
    PMIC_Read_All();
    PMIC_Unit_Test();
    PMIC_Read_All();
#endif    
    pmic_init_done = DCL_TRUE;
}

DCL_BOOL dcl_pmic_init_done_query(void)
{
        if(pmic_init_done == DCL_TRUE)
        {
                return DCL_TRUE;
        }
        else
        {
                return DCL_FALSE;
        }
}
void dcl_pmic6323_modem_init(void)
{
}

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    return dcl_pmic6323_byte_return(pmic_addr);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    dcl_pmic6323_byte_write(pmic_addr, value);
}

void PMIC_Read_All(void)
{
    volatile kal_uint32 i;
    for (i = 0; i < PMIC_MAX_REG_NUM; i += 2){
        pmic6323_reg[i] = dcl_pmic6323_byte_return(i); 
    }
}

#if defined(PMIC_UNIT_TEST)
void PMIC_Unit_Test(void)
{
{
DCL_HANDLE handle;
PMU_CTRL_VPA_SET_EN val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, VPA_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIM_SET_STB_SIO_MODE val;
val.vsimIdx = PMIC_VSIM1;
val.mode = SW_ENABLE; // SW_ENABLE / HW_ENABLE
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIM_SET_STB_SIO_MODE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM1;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM2;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIM_SET_STB_SIO_MODE val;
val.vsimIdx = PMIC_VSIM2;
val.mode = SW_ENABLE; // SW_ENABLE / HW_ENABLE
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIM_SET_STB_SIO_MODE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
val.mod = VSIM1;
val.voltage = PMU_VOLT_03_000000_V; /* PMU_VOLT_01_800000_V/ PMU_VOLT_03_000000_V */
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
val.mod = VSIM2;
val.voltage = PMU_VOLT_03_000000_V; /* PMU_VOLT_01_800000_V/ PMU_VOLT_03_000000_V */
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_LP_SEL val;
val.onSel = SRCLKEN_CONTROL; // (SW_CONTROL / SRCLKEN_CONTROL)
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_LP_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_LP_SEL val;
val.onSel = SRCLKEN_CONTROL; // (SW_CONTROL / SRCLKEN_CONTROL)
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_LP_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_LP_MODE_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_LP_MODE_SET val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_LP_MODE_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_ON_CTRL val;
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_ON_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_ON_CTRL val;
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF18;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, LDO_BUCK_SET_ON_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIMRST_SET_GPIO_SET val;
val.vsimIdx = PMIC_VSIM1;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIMRST_SET_GPIO_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIMRST_SET_GPIO_CLR val;
val.vsimIdx = PMIC_VSIM1;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIMRST_SET_GPIO_CLR, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIMRST_SET_GPIO_SET val;
val.vsimIdx = PMIC_VSIM2;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIMRST_SET_GPIO_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_SIMRST_SET_GPIO_CLR val;
val.vsimIdx = PMIC_VSIM2;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, SIMRST_SET_GPIO_CLR, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VPA_SET_FPWM val;
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, VPA_SET_FPWM, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_ADC_SET_RQST val;
#if 0 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_FALSE; // (DCL_TRUE / DCL_FALSE);
DclPMU_Control(handle, ADC_SET_RQST, (DCL_CTRL_DATA_T *)&val);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
DclPMU_Control(handle, ADC_SET_RQST, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_ADC_GET_RDY_MD val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

while(1)
{	
	DclPMU_Control(handle, ADC_GET_RDY_MD, (DCL_CTRL_DATA_T *)&val);
	// Result: val.status = (DCL_TRUE / DCL_FALSE)
#if defined(FPGA_CTP)
	dbg_print("[PMIC_WRAP_MD] ADC Data Status =%d\n", val.status);
#endif
	if(val.status == DCL_TRUE)
	{
    	break;	
	}
}
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_ADC_GET_OUT_MD val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
DclPMU_Control(handle, ADC_GET_OUT_MD, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
// Result: val.data = 0x0000~0xFFFF;
#if defined(FPGA_CTP)
dbg_print("[PMIC_WRAP_MD] ADC Data: val.data =%x\n", val.data);
#endif
}
}
#endif // End of #if defined(PMIC_UNIT_TEST)

#endif //#if (defined(PMIC_6323_REG_API))

