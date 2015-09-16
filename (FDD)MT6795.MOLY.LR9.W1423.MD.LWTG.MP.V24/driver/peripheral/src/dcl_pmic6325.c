/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2014
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
 *     dcl_pmic6325.c
 *
 * Project:
 * --------
 *     MOLY Software
 *
 * Description:
 * ------------
 *     This file is for PMIC 6325
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 * HISTORY
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
 * removed!
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

#if defined(FPGA_CTP)
#include <common.h>
#endif

#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"
#include "pmic_wrap.h"
#include "kal_public_api.h"
#include "us_timer.h"
#include "dhl_trace.h"
#if defined(PMIC_6325_REG_API)

// Start PMIC_UNIT_TEST
//#define PMIC_UNIT_TEST
// ARM Section RW/RO/ZI Use Internal SRAM
//#define PMIC_INTERNAL_SRAM
#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#define BANKS_NUM                       1
#define PMIC6325_MAX_REG_NUM                0x0F50 // 0x0000~0x0F48
//#define PMIC_MAX_REG_NUM                0x40FF // Register BUCK1, Register ANALDO, Register DIGLDO (0x0470)

#define MT6325_HW_CID_E1            0x2510
#define MT6325_HW_CID_E2            0x2520
#define MT6325_HW_CID_E3            0x2530
#define MT6325_SW_CID_E1            0x2510
#define MT6325_SW_CID_E2            0x2520
#define MT6325_SW_CID_E3            0x2530

#define PMIC_READ                   0
#define PMIC_WRITE                  1

#define PMIC_6325                   0x6325

//////////////////////////////////////////////////
//                Exported APIs                 //
//////////////////////////////////////////////////
extern kal_bool pmic6325_reg_write(kal_uint16 reg, kal_uint16 val);
extern kal_bool pmic6325_reg_read(kal_uint16 reg, kal_uint16 *pVal);

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

//#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
//__attribute__ ((zero_init)) 
//#endif /* __MTK_TARGET__ */
kal_uint8 pmic6325_hw_version;
kal_uint8 pmic6325_sw_version;
kal_uint16 pmic6325_reg[PMIC6325_MAX_REG_NUM];
DCL_BOOL pmic_init_done = DCL_FALSE;

const PMIC_FLAG_TABLE_ENTRY pmic6325_flags_table[] = 
{
    {MT6325_HWCID,		MT6325_HWCID_MASK,		MT6325_HWCID_SHIFT,		},
    {MT6325_SWCID,		MT6325_SWCID_MASK,		MT6325_SWCID_SHIFT,		},
    {MT6325_VPA_ANA_CON1,		MT6325_RG_VPA_MODESET_MASK,		MT6325_RG_VPA_MODESET_SHIFT,		},
    {MT6325_VRF18_0_ANA_CON1,		MT6325_RG_VRF18_0_MODESET_MASK,		MT6325_RG_VRF18_0_MODESET_SHIFT,		},
    {MT6325_VRF18_0_CON7,		MT6325_VRF18_0_EN_CTRL_MASK,		MT6325_VRF18_0_EN_CTRL_SHIFT,		},
    {MT6325_VRF18_0_CON7,		MT6325_VRF18_0_VOSEL_CTRL_MASK,		MT6325_VRF18_0_VOSEL_CTRL_SHIFT,		},
    {MT6325_VRF18_0_CON8,		MT6325_VRF18_0_EN_SEL_MASK,		MT6325_VRF18_0_EN_SEL_SHIFT,		},
    {MT6325_VRF18_0_CON8,		MT6325_VRF18_0_VOSEL_SEL_MASK,		MT6325_VRF18_0_VOSEL_SEL_SHIFT,		},
    {MT6325_VRF18_0_CON9,		MT6325_VRF18_0_EN_MASK,		MT6325_VRF18_0_EN_SHIFT,		},
    {MT6325_VRF18_0_CON11,		MT6325_VRF18_0_VOSEL_MASK,		MT6325_VRF18_0_VOSEL_SHIFT,		},
    {MT6325_VRF18_0_CON12,		MT6325_VRF18_0_VOSEL_ON_MASK,		MT6325_VRF18_0_VOSEL_ON_SHIFT,		},
    {MT6325_VRF18_0_CON13,		MT6325_VRF18_0_VOSEL_SLEEP_MASK,		MT6325_VRF18_0_VOSEL_SLEEP_SHIFT,		},
    {MT6325_VRF18_0_CON18,		MT6325_VRF18_0_VSLEEP_EN_MASK,		MT6325_VRF18_0_VSLEEP_EN_SHIFT,		},
    {MT6325_VPA_CON8,		MT6325_VPA_EN_SEL_MASK,		MT6325_VPA_EN_SEL_SHIFT,		},
    {MT6325_VPA_CON8,		MT6325_VPA_VOSEL_SEL_MASK,		MT6325_VPA_VOSEL_SEL_SHIFT,		},
    {MT6325_VPA_CON9,		MT6325_VPA_EN_MASK,		MT6325_VPA_EN_SHIFT,		},
    {MT6325_VPA_CON11,		MT6325_VPA_VOSEL_MASK,		MT6325_VPA_VOSEL_SHIFT,		},
    {MT6325_VPA_CON12,		MT6325_VPA_VOSEL_ON_MASK,		MT6325_VPA_VOSEL_ON_SHIFT,		},
    {MT6325_VPA_CON13,		MT6325_VPA_VOSEL_SLEEP_MASK,		MT6325_VPA_VOSEL_SLEEP_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_RG_VTCXO0_MODE_SET_MASK,		MT6325_RG_VTCXO0_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_RG_VTCXO0_EN_MASK,		MT6325_RG_VTCXO0_EN_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_RG_VTCXO0_MODE_CTRL_MASK,		MT6325_RG_VTCXO0_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_RG_VTCXO0_ON_CTRL_MASK,		MT6325_RG_VTCXO0_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_RG_VTCXO0_SRCLK_MODE_SEL_MASK,		MT6325_RG_VTCXO0_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON0,		MT6325_QI_VTCXO0_MODE_MASK,		MT6325_QI_VTCXO0_MODE_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_RG_VTCXO1_MODE_SET_MASK,		MT6325_RG_VTCXO1_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_RG_VTCXO1_EN_MASK,		MT6325_RG_VTCXO1_EN_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_RG_VTCXO1_MODE_CTRL_MASK,		MT6325_RG_VTCXO1_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_RG_VTCXO1_ON_CTRL_MASK,		MT6325_RG_VTCXO1_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_RG_VTCXO1_SRCLK_MODE_SEL_MASK,		MT6325_RG_VTCXO1_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON1,		MT6325_QI_VTCXO1_MODE_MASK,		MT6325_QI_VTCXO1_MODE_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_MODE_SET_MASK,		MT6325_RG_VRF18_1_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_EN_MASK,		MT6325_RG_VRF18_1_EN_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_MODE_CTRL_MASK,		MT6325_RG_VRF18_1_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_ON_CTRL_MASK,		MT6325_RG_VRF18_1_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_SRCLK_MODE_SEL_MASK,		MT6325_RG_VRF18_1_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_QI_VRF18_1_MODE_MASK,		MT6325_QI_VRF18_1_MODE_SHIFT,		},
    {MT6325_LDO_CON8,		MT6325_RG_VRF18_1_SRCLK_EN_SEL_MASK,		MT6325_RG_VRF18_1_SRCLK_EN_SEL_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_MODE_SET_MASK,		MT6325_RG_VSIM1_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_EN_MASK,		MT6325_RG_VSIM1_EN_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_MODE_CTRL_MASK,		MT6325_RG_VSIM1_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_ON_CTRL_MASK,		MT6325_RG_VSIM1_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_SRCLK_MODE_SEL_MASK,		MT6325_RG_VSIM1_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_QI_VSIM1_MODE_MASK,		MT6325_QI_VSIM1_MODE_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_STBTD_MASK,		MT6325_RG_VSIM1_STBTD_SHIFT,		},
    {MT6325_LDO_CON17,		MT6325_RG_VSIM1_SRCLK_EN_SEL_MASK,		MT6325_RG_VSIM1_SRCLK_EN_SEL_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_MODE_SET_MASK,		MT6325_RG_VSIM2_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_EN_MASK,		MT6325_RG_VSIM2_EN_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_MODE_CTRL_MASK,		MT6325_RG_VSIM2_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_ON_CTRL_MASK,		MT6325_RG_VSIM2_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_SRCLK_MODE_SEL_MASK,		MT6325_RG_VSIM2_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_QI_VSIM2_MODE_MASK,		MT6325_QI_VSIM2_MODE_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_STBTD_MASK,		MT6325_RG_VSIM2_STBTD_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_RG_VSIM2_SRCLK_EN_SEL_MASK,		MT6325_RG_VSIM2_SRCLK_EN_SEL_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_QI_VSIM2_STB_MASK,		MT6325_QI_VSIM2_STB_SHIFT,		},
    {MT6325_LDO_CON18,		MT6325_QI_VSIM2_EN_MASK,		MT6325_QI_VSIM2_EN_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_MODE_SET_MASK,		MT6325_RG_VMIPI_MODE_SET_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_EN_MASK,		MT6325_RG_VMIPI_EN_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_MODE_CTRL_MASK,		MT6325_RG_VMIPI_MODE_CTRL_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_ON_CTRL_MASK,		MT6325_RG_VMIPI_ON_CTRL_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_SRCLK_MODE_SEL_MASK,		MT6325_RG_VMIPI_SRCLK_MODE_SEL_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_QI_VMIPI_MODE_MASK,		MT6325_QI_VMIPI_MODE_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_STBTD_MASK,		MT6325_RG_VMIPI_STBTD_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_RG_VMIPI_SRCLK_EN_SEL_MASK,		MT6325_RG_VMIPI_SRCLK_EN_SEL_SHIFT,		},
    {MT6325_LDO_CON19,		MT6325_QI_VMIPI_EN_MASK,		MT6325_QI_VMIPI_EN_SHIFT,		},
    {MT6325_LDO_VCON9,		MT6325_RG_VSIM2_VOSEL_MASK,		MT6325_RG_VSIM2_VOSEL_SHIFT,		},
    {MT6325_LDO_VCON9,		MT6325_RG_VSIM1_VOSEL_MASK,		MT6325_RG_VSIM1_VOSEL_SHIFT,		},
    {MT6325_LDO_OCFB1,		MT6325_RG_VSIM2_OCFB_EN_MASK,		MT6325_RG_VSIM2_OCFB_EN_SHIFT,		},    
    {MT6325_LDO_OCFB1,		MT6325_RG_VSIM1_OCFB_EN_MASK,		MT6325_RG_VSIM1_OCFB_EN_SHIFT,		},    
    {MT6325_SPK_CON8,		MT6325_RG_SPK_CCODE_MASK,		MT6325_RG_SPK_CCODE_SHIFT,		},
    {MT6325_SPK_CON8,		MT6325_RG_SPK_EN_VIEW_VCM_MASK,		MT6325_RG_SPK_EN_VIEW_VCM_SHIFT,		},
    {MT6325_SPK_CON8,		MT6325_RG_SPK_FBRC_EN_MASK,		MT6325_RG_SPK_FBRC_EN_SHIFT,		},
    {MT6325_SPK_CON9,		MT6325_SPK_TEST_MODE0_MASK,		MT6325_SPK_TEST_MODE0_SHIFT,		},
    {MT6325_SPK_CON10,		MT6325_SPK_TD_DONE_MASK,		MT6325_SPK_TD_DONE_SHIFT,		},
    {MT6325_AUXADC_RQST1_SET,		MT6325_AUXADC_RQST1_SET_MASK,		MT6325_AUXADC_RQST1_SET_SHIFT,		},
    {MT6325_AUXADC_RQST1_CLR,		MT6325_AUXADC_RQST1_CLR_MASK,		MT6325_AUXADC_RQST1_CLR_SHIFT,		},
    {MT6325_AUXADC_ADC15,		MT6325_RG_ADC_OUT_MD_MASK,		MT6325_RG_ADC_OUT_MD_SHIFT,		},
    {MT6325_AUXADC_ADC16,		MT6325_RG_ADC_RDY_MD_MASK,		MT6325_RG_ADC_RDY_MD_SHIFT,		},
    {MT6325_AUXADC_CON20,		MT6325_RG_MD_RQST_MASK,		MT6325_RG_MD_RQST_SHIFT,		},
    {MT6325_AUXADC_CON27,		MT6325_RG_VREF18_ENB_MD_MASK,		MT6325_RG_VREF18_ENB_MD_SHIFT,		},
};
//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////

// Write Whole Bytes
void dcl_pmic6325_byte_write(DCL_UINT16 addr, DCL_UINT16 val)
{
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)     
    
#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    pmic6325_reg[addr] = val;
             
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
void dcl_pmic6325_field_write(PMIC6325_FLAGS_LIST_ENUM flag, DCL_UINT16 sel)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic6325_flags_table;
    kal_uint32 savedMask = 0;
#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)  

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

    pmic_reg_log.command_flag = flag;
    pmic_reg_log.reg_before_write = pmic6325_reg[pTable[flag].offset];

    pmic6325_reg[pTable[flag].offset] &= ~(pTable[flag].mask << pTable[flag].shift);
    pmic6325_reg[pTable[flag].offset] |= ((kal_uint16)sel << pTable[flag].shift);    

#if defined(__MD1__)    
    DrvPWRAP_WACS0(PMIC_WRAP_WRITE, pTable[flag].offset, pmic6325_reg[pTable[flag].offset], 0x00);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_WRITE, pTable[flag].offset, pmic6325_reg[pTable[flag].offset], 0x00);
#endif

    pmic_reg_log.write_value = sel;
    pmic_reg_log.address_offset = pTable[flag].offset;
    pmic_reg_log.reg_mask = pTable[flag].mask;
    pmic_reg_log.reg_shift = pTable[flag].shift;
    pmic_reg_log.reg_addr = pTable[flag].offset;
    pmic_reg_log.reg_data = pmic6325_reg[pTable[flag].offset];

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
DCL_UINT16 dcl_pmic6325_byte_return(DCL_UINT16 addr)
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
    DrvPWRAP_WACS0(PMIC_WRAP_READ, (DCL_UINT32)addr, 0x00, &reg_temp);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, (DCL_UINT32)addr, 0x00, &reg_temp);    
#endif

    pmic6325_reg[addr] = reg_temp;
  
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
DCL_UINT16 dcl_pmic6325_field_read(PMIC6325_FLAGS_LIST_ENUM flag)
{
    const PMIC_FLAG_TABLE_ENTRY *pTable = pmic6325_flags_table;
    kal_uint32 savedMask = 0;
    DCL_UINT16 reg_return = 0;

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__) 

#if defined(DCL_PMIC_ACCESS_TIME_LOG)
    pmic_access_duration_log[PMIC_INTERFACE_DBG][pmic_access_duration_index].start_time = ust_get_current_time();
#endif

#if defined(__MD1__)
    DrvPWRAP_WACS0(PMIC_WRAP_READ, pTable[flag].offset, 0x00, &pmic6325_reg[pTable[flag].offset]);
#else
    DrvPWRAP_WACS1(PMIC_WRAP_READ, pTable[flag].offset, 0x00, &pmic6325_reg[pTable[flag].offset]);
#endif

    reg_return = ((pmic6325_reg[pTable[flag].offset] & (pTable[flag].mask << pTable[flag].shift)) >> pTable[flag].shift);
    
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
void pmic6325_EM_reg_write(kal_uint16 reg, kal_uint16 val){
    dcl_pmic6325_byte_write(reg, val);
}

kal_uint16 pmic6325_EM_reg_read(kal_uint16 reg){
    return  dcl_pmic6325_byte_return(reg);
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic6325_get_HW_ECO_version(void)
{
    return pmic6325_hw_version;
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic6325_get_SW_version(void)
{
    return pmic6325_sw_version;
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

// 3'b001: 1.65, 3'b010: 1.8 V, 3'b011: 1.85 V, 3'b101: 2.75V, 3'b110: 3.0 V, 3'b111: 3.1 V
const DCL_UINT32 vsim1_vosel[] =
{
    PMU_VOLT_INVALID,       PMU_VOLT_01_650000_V,  PMU_VOLT_01_800000_V,   PMU_VOLT_01_850000_V,  
    PMU_VOLT_INVALID,       PMU_VOLT_02_750000_V,  PMU_VOLT_03_000000_V,   PMU_VOLT_03_100000_V,
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	{ENC(LDO_BUCK_SET_VOLTAGE, VPA_SW),		    vpa_vosel,		    NULL,	    		GETARRNUM(vpa_vosel)		},    
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM1),		    vsim1_vosel,		NULL,	    		GETARRNUM(vsim1_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VSIM2),		    vsim1_vosel,		NULL,   			GETARRNUM(vsim1_vosel)	    },            
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size = 0;

DCL_STATUS PMIC6325_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
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
                case VRF18_1:
                {
                    dcl_pmic6325_field_write(MT6325_VRF18_0_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;
                
                case VRF18_2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VRF18_1_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM1:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM1_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM2_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VMIPI:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VMIPI_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }            
                break;

                case VPA_SW:
                {
                    dcl_pmic6325_field_write(MT6325_VPA_EN, pLdoBuckCtrl->enable);
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
                    // 1'b0:Normal mode, 1'b1:Low power mode
                    dcl_pmic6325_field_write(MT6325_RG_VSIM1_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    // 1'b0:Normal mode, 1'b1:Low power mode                    
                    dcl_pmic6325_field_write(MT6325_RG_VSIM2_MODE_SET, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;                

                case VRF18_2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VRF18_1_MODE_SET, pLdoBuckCtrl->enable);
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
                    // 1'b0: SW control by VSIM1_MODE_SET, 1'b1: HW control by SRCLKEN
                    dcl_pmic6325_field_write(MT6325_RG_VSIM1_MODE_CTRL, pLdoBuckCtrl->onSel);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM2_MODE_CTRL, pLdoBuckCtrl->onSel);
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
                    dcl_pmic6325_field_write(MT6325_RG_VSIM1_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM2_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VPA_SW:
                {
                    dcl_pmic6325_field_write(MT6325_VPA_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;                

                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
        }
        break;
              
		case LDO_BUCK_SET_EN_CTRL:
		{
    	    PMU_CTRL_LDO_BUCK_SET_EN_CTRL *pLdoBuckCtrl = &(data->rPMULdoBuckSetEnCtrl);

            switch(pLdoBuckCtrl->mod)
            {
                case VRF18_1:
                {
                    // 0: SW control1: HW control
                    dcl_pmic6325_field_write(MT6325_VRF18_0_EN_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;    

                case VRF18_2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VRF18_1_ON_CTRL, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;  

                case VMIPI:
                {
                    // 0: SW control, 1: HW
                    dcl_pmic6325_field_write(MT6325_RG_VMIPI_ON_CTRL, pLdoBuckCtrl->mode);                    
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
                        dcl_pmic6325_field_write(MT6325_RG_VSIM1_OCFB_EN, pLdoBuckCtrl->enable);
                        return_val = STATUS_OK;
                    }
                    break;
        
                    case VSIM2:
                    {
                        dcl_pmic6325_field_write(MT6325_RG_VSIM2_OCFB_EN, pLdoBuckCtrl->enable);
                        return_val = STATUS_OK;
                    }
                    break;
                    
                    default:
                        return_val = STATUS_UNSUPPORTED;
                    break;
                }
        }
        break;  
        		

		case LDO_BUCK_SET_EN_SEL:
		{
    	    PMU_CTRL_LDO_BUCK_SET_EN_SEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetEnSel);

            switch(pLdoBuckCtrl->mod)
            {
                case VRF18_1:
                {
                    dcl_pmic6325_field_write(MT6325_VRF18_0_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;    

                case VRF18_2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VRF18_1_SRCLK_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;    

                case VSIM1:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM1_SRCLK_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;    

                case VSIM2:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VSIM2_SRCLK_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;    

                case VMIPI:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VMIPI_SRCLK_EN_SEL, pLdoBuckCtrl->sel);
                    return_val = STATUS_OK;
                }
                break;
                
                default:
                    return_val = STATUS_UNSUPPORTED;
                break;
            }
		}
		break;

                case LDO_BUCK_SET_SRCLK_MODE_SEL:
                {
                    PMU_CTRL_LDO_BUCK_SET_SRCLK_MODE_SEL *pLdoBuckCtrl = &(data->rPMULdoBuckSetSrclkModeSel);

                    switch(pLdoBuckCtrl->mod)
                    {
                        case VSIM1:
                        {
                            dcl_pmic6325_field_write(MT6325_RG_VSIM1_SRCLK_MODE_SEL, pLdoBuckCtrl->sel);
                            return_val = STATUS_OK;
                        }
                        break;    

                        case VSIM2:
                        {
                            dcl_pmic6325_field_write(MT6325_RG_VSIM2_SRCLK_MODE_SEL, pLdoBuckCtrl->sel);
                            return_val = STATUS_OK;
                        }
                        break;    

                        default:
                        return_val = STATUS_UNSUPPORTED;
                        break;
                    }
                }
		break;
                
		case LDO_BUCK_SET_MODESET:
		{
    	    PMU_CTRL_LDO_BUCK_SET_MODESET *pLdoBuckCtrl = &(data->rPMULdoBuckSetModeset);

            switch(pLdoBuckCtrl->mod)
            {
                case VPA_SW:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VPA_MODESET, pLdoBuckCtrl->mode);
                    return_val = STATUS_OK;
                }
                break;
                
                case VRF18_1:
                {
                    dcl_pmic6325_field_write(MT6325_RG_VRF18_0_MODESET, pLdoBuckCtrl->mode);
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
            dcl_pmic6325_field_write(MT6325_VPA_EN, pVpaSetEn->enable);
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

        
        case ADC_SET_RQST:
        {
            PMU_CTRL_ADC_SET_RQST *pAdcCtrl = &(data->rPMUAdcSetRqst);
            if((AUXADC_Status != AUXADC_READ_INIT) && (AUXADC_Status != AUXADC_READ_DATA))
            {
                ASSERT(0);
            }

            dcl_pmic6325_byte_write(MT6325_TOP_CLKSQ_SET, (0x1 << 3));
            dcl_pmic6325_byte_write(MT6325_AUXADC_CON27, (0x0 << MT6325_RG_VREF18_ENB_MD_SHIFT));
            dcl_pmic6325_field_write(MT6325_RG_MD_RQST, 0x0); // Need Set 0 first
			
            dcl_pmic6325_field_write(MT6325_RG_MD_RQST, pAdcCtrl->enable);
            AUXADC_Status = AUXADC_READ_REQUEST;
            return_val = STATUS_OK;
        }
        break;

        case ADC_GET_RDY_MD:
        {
            PMU_CTRL_ADC_GET_RDY_MD *pAdcCtrl = &(data->rPMUAdcGetRdyMd);

            pAdcCtrl->status = (DCL_BOOL)dcl_pmic6325_field_read(MT6325_RG_ADC_RDY_MD);
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
            pAdcCtrl->data = (DCL_UINT32)dcl_pmic6325_field_read(MT6325_RG_ADC_OUT_MD); 
            AUXADC_Status = AUXADC_READ_DATA;
            dcl_pmic6325_field_write(MT6325_RG_MD_RQST, 0x0);
            dcl_pmic6325_byte_write(MT6325_TOP_CLKSQ_CLR, (0x1 << 3));
            dcl_pmic6325_byte_write(MT6325_AUXADC_CON27, (0x1 << MT6325_RG_VREF18_ENB_MD_SHIFT));
			
            return_val = STATUS_OK;
        }
        break;

        case MISC_GET_HW_VERSION:
        {
            PMU_CTRL_MISC_GET_HW_VERSION	*pMiscCtrl = &(data->rPMUMiscGetHwVersion);
            if(pMiscCtrl->chip_name == PMIC_MT_6325)
            {
                pMiscCtrl->version = pmic6325_hw_version;
            }
            return_val = STATUS_OK;            
        }
        break;
        case MISC_SET_REGISTER_VALUE:
        {			
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            pmic6325_EM_reg_write(pChrCtrl->offset, pChrCtrl->value);
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            pChrCtrl->value = pmic6325_EM_reg_read(pChrCtrl->offset);
            return_val = STATUS_OK;
        }
        break;

        default:				
            return_val = STATUS_UNSUPPORTED;
        break;
    }

    return return_val;

}

extern void dcl_pmic6325_modem_only_init(void);
extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern kal_uint32 PMIC_Config_Interface(kal_bool action, kal_uint32 address, kal_uint32 wdata, kal_uint32 *rdata, kal_uint32 chip_name);
extern void PMIC_Read_All(void);
#if defined(PMIC_UNIT_TEST)
extern void PMIC_Read_All(void);
extern void PMIC_Unit_Test(void);
#endif

#if defined(__DUAL_TALK_SUPPORT__)
static void PMIC_DRV_SetData(DCL_UINT32 addr, DCL_UINT32 bitmask, DCL_UINT16 value, DCL_UINT32 bank)
{
extern void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value);
extern DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr);
   DCL_UINT32 temp;
   addr |= (bank << 31);
   temp = (~(bitmask)) & DRV_Read_PMIC_Data(addr);
   temp |= ((value) & (bitmask));
   DRV_Write_PMIC_Data(addr,temp);
}
#endif

void dcl_pmic6325_internal_init(void)
{
#if defined(__DUAL_TALK_SUPPORT__)
PMIC_DRV_SetData(0xA02     , 0x2    , 0x2    , 0x0);
#endif
}

#if defined(__DHL_MODULE__)
extern kal_bool dhl_register_custom_mem_read(DHL_CUSTOM_MEM_TYPE mem_type, DHL_CUSTOM_READ_MEM_CALLBACK read_cb);
extern kal_bool dhl_register_custom_mem_write(DHL_CUSTOM_MEM_TYPE mem_type, DHL_CUSTOM_WRITE_MEM_CALLBACK write_cb);
extern void PMIC_Read_Callback_For_DHL(void* read_addr, kal_uint32 len, kal_uint32 option, void** read_buffer_addr, kal_uint32 *read_buffer_len);
extern void PMIC_Write_Callback_For_DHL(void* write_addr, kal_uint32 len, kal_uint32 option, void* write_buffer_addr);
#endif

void dcl_pmic6325_init(void){
    extern void pmic_wrap_dump_init(void);
    pmu_control_handler = PMIC6325_control_handler;
    pmu_parameter_size = GETARRNUM(pmu_parameter_table);
#if defined(__DHL_MODULE__)   
    dhl_register_custom_mem_read(DHL_CUSTOM_MEM_PMIC, PMIC_Read_Callback_For_DHL);
    dhl_register_custom_mem_write(DHL_CUSTOM_MEM_PMIC, PMIC_Write_Callback_For_DHL);
#endif    
    pmic_wrap_dump_init();

#if  !defined(__SMART_PHONE_MODEM__)    
    DrvPWRAP_Init();
#endif    
    pmic6325_hw_version = PMIC_ECO_E1;
    pmic6325_sw_version = PMIC_ECO_E1;

    // Get MT6325 ECO version
    {
        kal_uint16 pmic6325_hw_eco_version = 0;
        kal_uint16 pmic6325_sw_eco_version = 0;
        pmic6325_hw_eco_version = dcl_pmic6325_byte_return(MT6325_HWCID);
        pmic6325_sw_eco_version = dcl_pmic6325_byte_return(MT6325_SWCID);

        if (pmic6325_hw_eco_version == MT6325_HW_CID_E1)
        {
            pmic6325_hw_version = PMIC_ECO_E1;
        }
        else
        {
            pmic6325_hw_version = PMIC_ECO_E2;
        }

        if (pmic6325_sw_eco_version == MT6325_SW_CID_E1)
        {
            pmic6325_sw_version = PMIC_ECO_E1;
        }
        else
        {
            pmic6325_sw_version = PMIC_ECO_E2;
        }    
    }

    PMIC_Read_All();

#if !defined(__SMART_PHONE_MODEM__)    
    dcl_pmic6325_modem_only_init();
#endif
    dcl_pmic6325_internal_init();

    //  pmic6325_customization_init();
#if defined(PMIC_UNIT_TEST)
    PMIC_Read_All();
    PMIC_Unit_Test();
    PMIC_Read_All();
#endif    
    pmic_init_done = DCL_TRUE;
    
}

#if defined(__DHL_MODULE__)
kal_uint32 pmic_read_data;
void PMIC_Read_Callback_For_DHL(void* read_addr, kal_uint32 len, kal_uint32 option, void** read_buffer_addr, kal_uint32 *read_buffer_len)
{
    kal_uint32 write_buffer_addr = 0;
    kal_uint32 read_data_addr = (kal_uint32)read_addr;
    // Write Workaround
    if(read_data_addr & 0x00000001)        
    {
         write_buffer_addr = (read_data_addr & 0xFFFF0000) >> 16;
         read_data_addr = (read_data_addr & 0x0000FFFE);
         PMIC_Config_Interface(PMIC_WRITE, read_data_addr, (kal_uint32)write_buffer_addr, NULL, option);
    }
    PMIC_Config_Interface(PMIC_READ, read_data_addr, 0, &pmic_read_data, option);
    *read_buffer_addr = (kal_uint32*)&pmic_read_data;
    *read_buffer_len = 4;
}

void PMIC_Write_Callback_For_DHL(void* write_addr, kal_uint32 len, kal_uint32 option, void* write_buffer_addr)
{
    PMIC_Config_Interface(PMIC_WRITE, (kal_uint32)write_addr, (kal_uint32)write_buffer_addr, NULL, option);
}
#endif // End of #if defined(__DHL_MODULE__)
kal_uint32 PMIC_Config_Interface(kal_bool action, kal_uint32 address, kal_uint32 wdata, kal_uint32 *rdata, kal_uint32 chip_name)
{
    // Check argument validation
    if((action  & ~(0x1))    != 0)  return 0; // Write should be 1 bit
    if((address & ~(0xffff)) != 0)  return 0; // Address should no larger than 0xFFFF
    if((wdata   & ~(0xffff)) != 0)  return 0; // Write DATA should be no larger than 0xFFFF
            
    if(action == PMIC_READ)
    {
        if(chip_name == PMIC_6325)
        {
            *rdata = (kal_uint32)DRV_Read_PMIC_Data(address);
        }
        else
        {
            ASSERT(0);
        }
    }
    else if(action == PMIC_WRITE)
    {
        if(chip_name == PMIC_6325)
        {
            DRV_Write_PMIC_Data(address, wdata);
        }
        else
        {
            ASSERT(0);
        }                            
    }
    return 1;
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

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    return dcl_pmic6325_byte_return(pmic_addr);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    dcl_pmic6325_byte_write(pmic_addr, value);
}

void PMIC_Read_All(void)
{
    volatile kal_uint32 i;
    for (i = 0; i < PMIC6325_MAX_REG_NUM; i += 2){
        pmic6325_reg[i] = dcl_pmic6325_byte_return(i); 
    }
}

#if defined(PMIC_UNIT_TEST)
void PMIC_Unit_Test(void)
{
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_ON_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_ON_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VPA_SW;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VPA_SW;
val.voltage = PMU_VOLT_01_800000_V; 
/*     PMU_VOLT_00_500000_V,      PMU_VOLT_00_600000_V,      
        PMU_VOLT_00_700000_V,      PMU_VOLT_00_800000_V,      
        PMU_VOLT_00_900000_V,      PMU_VOLT_01_000000_V,      
        PMU_VOLT_01_100000_V,      PMU_VOLT_01_200000_V,      
        PMU_VOLT_01_300000_V,      PMU_VOLT_01_400000_V,      
        PMU_VOLT_01_500000_V,      PMU_VOLT_01_600000_V,      
        PMU_VOLT_01_700000_V,      PMU_VOLT_01_800000_V,      
        PMU_VOLT_01_900000_V,      PMU_VOLT_02_000000_V,    
        PMU_VOLT_02_100000_V,      PMU_VOLT_02_200000_V,      
        PMU_VOLT_02_300000_V,      PMU_VOLT_02_400000_V,      
        PMU_VOLT_02_500000_V,      PMU_VOLT_02_600000_V,      
        PMU_VOLT_02_700000_V,      PMU_VOLT_02_800000_V,      
        PMU_VOLT_02_900000_V,      PMU_VOLT_03_000000_V,      
        PMU_VOLT_03_100000_V,      PMU_VOLT_03_200000_V,      
        PMU_VOLT_03_300000_V,      PMU_VOLT_03_400000_V,      
        PMU_VOLT_03_500000_V,      PMU_VOLT_03_600000_V,      */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VPA_SW;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF1;
DclPMU_Control(handle, LDO_BUCK_SET_EN_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL; 
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VRF1;
DclPMU_Control(handle, LDO_BUCK_SET_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VRF1;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_SET_MODESET_CKPDN_SET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.regval = 0x7; // (0x0~0xF)
DclPMU_Control(handle, VRF1_SET_MODESET_CKPDN_SET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_SET_MODESET_CKPDN_CLR val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.regval = 0x7; // (0x0~0xF)
DclPMU_Control(handle, VRF1_SET_MODESET_CKPDN_CLR, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_VRF1_GET_MODESET_CKPDN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
// val.regval will be your request value ( no need do any shift)
DclPMU_Control(handle, VRF1_GET_MODESET_CKPDN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_CTRL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mode = HW_CONTROL; // (SW_CONTROL_BY_REG / HW_CONTROL)
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN_CTRL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL; 
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VRF2;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_MODESET val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod = VRF1;
val.mode = FORCE_PWM_MODE; // (AUTO_MODE / FORCE_PWM_MODE)
DclPMU_Control(handle, LDO_BUCK_SET_MODESET, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_SRCLK_EN_SEL val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.sel = SRCLKEN_IN1_SEL; 
/* SRCLKEN_IN1_SEL / SRCLKEN_IN2_SEL/ SRCLKEN_IN1_OR_SRCLKEN_IN2_SEL/
    SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL/ SRCLKEN_IN1_AND_SRCLKEN_IN2_SEL */
val.mod = VMIPI;
DclPMU_Control(handle, LDO_BUCK_SET_SRCLK_EN_SEL, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM1;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_EN val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.enable = DCL_TRUE; // (DCL_TRUE / DCL_FALSE);
val.mod = VSIM2;
DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VSIM1;
val.voltage = PMU_VOLT_01_800000_V; 
/*  PMU_VOLT_01_800000_V,      PMU_VOLT_03_000000_V,   */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
{
DCL_HANDLE handle;
PMU_CTRL_LDO_BUCK_SET_VOLTAGE val;
handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
val.mod=VSIM2;
val.voltage = PMU_VOLT_01_800000_V; 
/*  PMU_VOLT_01_800000_V,      PMU_VOLT_03_000000_V,   */
DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&val);
DclPMU_Close(handle);
}
}
#endif // End of #if defined(PMIC_UNIT_TEST)

#endif // End of #if defined(PMIC_6325_REG_API)

