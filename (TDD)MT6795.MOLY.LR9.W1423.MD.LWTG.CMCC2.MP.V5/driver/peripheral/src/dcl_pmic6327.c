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
 *  dcl_pmic6327.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is pmic6327 driver
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
#include "i2c_pmic_sw.h"
#include "kal_public_api.h"

#if defined(__MODEM_CCCI_EXIST__)
#include "ccci.h"
#endif

#include "dcm_sw.h"

#if defined(PMIC_6327_REG_API)

// ARM Section RW/RO/ZI Use Internal SRAM
#define PMIC_INTERNAL_SRAM

#define ACCEPTABLE_RETRY_COUNT  2
#define PMIC_RETRY_STATISTICS_ENABLE

#if !defined(__FUE__)
#define SAVEANDSETIRQMASK()      SaveAndSetIRQMask()
#define RESTOREIRQMASK(mask)     RestoreIRQMask(mask)
#else /*defined(__FUE__)*/
#define SAVEANDSETIRQMASK()      0
#define RESTOREIRQMASK(mask)     {}
#endif /*defined(__FUE__)*/

#define BANKS_NUM                       1
#define PMIC_MAX_REG_NUM                PMIC_BANK0_REG_NUM//((PMIC_BANK0_REG_NUM > PMIC_BANK1_REG_NUM) ? PMIC_BANK0_REG_NUM : PMIC_BANK1_REG_NUM)

#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
__attribute__ ((zero_init/*, section ("INTERNZI")*/)) 
#endif /* __MTK_TARGET__ */
kal_uint8 pmic6327_reg[BANKS_NUM][PMIC_MAX_REG_NUM];

//#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
//__attribute__ ((section ("INTERNCONST"))) 
//#endif /* __MTK_TARGET__ */
const PMU_FLAG_TABLE_ENTRY pmic_flags_table[] = 
{
    {VIO18_STATUS,      VIO18_STATUS_ADDR,      VIO18_STATUS_MASK,      VIO18_STATUS_SHIFT,     },
    {VRF18_STATUS,      VRF18_STATUS_ADDR,      VRF18_STATUS_MASK,      VRF18_STATUS_SHIFT,     },
    {VTCXO_STATUS,      VTCXO_STATUS_ADDR,      VTCXO_STATUS_MASK,      VTCXO_STATUS_SHIFT,     },
    {PMU_THR_STATUS,    PMU_THR_STATUS_ADDR,    PMU_THR_STATUS_MASK,    PMU_THR_STATUS_SHIFT,   },
    {RG_VRF18_EN,       RG_VRF18_EN_ADDR,       RG_VRF18_EN_MASK,       RG_VRF18_EN_SHIFT,      },
    {RG_VRF18_VOSEL,    RG_VRF18_VOSEL_ADDR,    RG_VRF18_VOSEL_MASK,    RG_VRF18_VOSEL_SHIFT,   },
    {RG_VRF18_ON_CTRL,  RG_VRF18_ON_CTRL_ADDR,  RG_VRF18_ON_CTRL_MASK,  RG_VRF18_ON_CTRL_SHIFT, },
    {RG_VRF18_MODESET,  RG_VRF18_MODESET_ADDR,  RG_VRF18_MODESET_MASK,  RG_VRF18_MODESET_SHIFT, },
    {RG_VIO18_EN,       RG_VIO18_EN_ADDR,       RG_VIO18_EN_MASK,       RG_VIO18_EN_SHIFT,      },
    {RG_VSIM_CAL,       RG_VSIM_CAL_ADDR,       RG_VSIM_CAL_MASK,       RG_VSIM_CAL_SHIFT,      },
    {RG_VSIM_VOSEL,     RG_VSIM_VOSEL_ADDR,     RG_VSIM_VOSEL_MASK,     RG_VSIM_VOSEL_SHIFT,    },
    {RG_VSIM_EN,        RG_VSIM_EN_ADDR,        RG_VSIM_EN_MASK,        RG_VSIM_EN_SHIFT,       },
    {RG_VMC_CAL,        RG_VMC_CAL_ADDR,        RG_VMC_CAL_MASK,        RG_VMC_CAL_SHIFT,       },
    {RG_VMC_VOSEL,      RG_VMC_VOSEL_ADDR,      RG_VMC_VOSEL_MASK,      RG_VMC_VOSEL_SHIFT,     },
    {RG_VMC_EN,         RG_VMC_EN_ADDR,         RG_VMC_EN_MASK,         RG_VMC_EN_SHIFT,        },
    {RG_VTCXO_CAL,      RG_VTCXO_CAL_ADDR,      RG_VTCXO_CAL_MASK,      RG_VTCXO_CAL_SHIFT,     },
    {VTCXO_ON_CTRL,     VTCXO_ON_CTRL_ADDR,     VTCXO_ON_CTRL_MASK,     VTCXO_ON_CTRL_SHIFT,    },
    {RG_VTCXO_EN,       RG_VTCXO_EN_ADDR,       RG_VTCXO_EN_MASK,       RG_VTCXO_EN_SHIFT,      }
};

#if (defined(__MTK_TARGET__) && defined(PMIC_INTERNAL_SRAM))
__attribute__ ((zero_init/*, section ("INTERNZI")*/)) 
#endif /* __MTK_TARGET__ */
kal_uint8 pmic6327_eco_version;
#if !defined(__UBL__) && !defined(__FUE__)
kal_uint8 lockDcmCnt = 0;
kal_uint8 i2cDcmHandle;
#endif
//////////////////////////////////////////////////
//                  WRITE APIs                  //
//////////////////////////////////////////////////
extern void i2c_pmic_speedup(kal_uint32 token);
extern kal_bool pmic6327_reg_write_fast(kal_uint8 reg, kal_uint8 val,kal_uint32 token);
extern kal_bool pmic6327_reg_read_fast(kal_uint8 reg, kal_uint8 *pVal,kal_uint32 token);
extern kal_uint32 i2c_pmic_getToken(void);

#if defined(PMIC_RETRY_STATISTICS_ENABLE)
kal_uint32 aNumOfRetryCnt[20];
kal_uint32 maxRetryCnt = 0;

static void updateRetryCnt(kal_uint32 retryCnt)
{
    kal_uint32 savedMask = 0;

    if (retryCnt == 0)
        return;
    
    savedMask=SAVEANDSETIRQMASK();
    if (retryCnt >= 20)
    {
        aNumOfRetryCnt[0]++;
        if (retryCnt > maxRetryCnt)
            maxRetryCnt = retryCnt;
    }
    else if (retryCnt > 0)
    {
        aNumOfRetryCnt[retryCnt]++;
    }
    RestoreIRQMask(savedMask);
}
#else //#if defined(PMIC_RETRY_STATISTICS_ENABLE)
static void updateRetryCnt(kal_uint32 retryCnt) {}
#endif //#if defined(PMIC_RETRY_STATISTICS_ENABLE)

#if !defined(__UBL__) && !defined(__FUE__)
static void pmic_DCM_Disable()
{
    kal_uint32 savedMask = 0;
    
    savedMask=SAVEANDSETIRQMASK();
    if (lockDcmCnt == 0)
    {
        DCM_Disable(i2cDcmHandle);
    }
    lockDcmCnt++;
    RestoreIRQMask(savedMask);
}
#else //#if !defined(__UBL__) && !defined(__FUE__)
static void pmic_DCM_Disable() {}
#endif //#if !defined(__UBL__) && !defined(__FUE__)

#if !defined(__UBL__) && !defined(__FUE__)
static void pmic_DCM_Enable()
{
    kal_uint32 savedMask = 0;
    
    savedMask=SAVEANDSETIRQMASK();
    lockDcmCnt--;
    if (lockDcmCnt == 0)
    {
        DCM_Enable(i2cDcmHandle);
    }
    RestoreIRQMask(savedMask);
}
#else //#if !defined(__UBL__) && !defined(__FUE__)
static void pmic_DCM_Enable() {}
#endif //#if !defined(__UBL__) && !defined(__FUE__)

// Write Whole Bytes
void dcl_pmic6327_byte_write(DCL_UINT8 addr, DCL_UINT8 val, DCL_UINT32 bank)
{
    kal_uint32 token;
    kal_bool result = KAL_FALSE;
    
    kal_uint32 retryCnt = 0;

    pmic_DCM_Disable();
    do{
        token=i2c_pmic_getToken();
        i2c_pmic_speedup(token);
        I2C_PMIC_LOG(I2C_byte_write,token);	
        pmic6327_reg[bank][addr] = val;
        result = pmic6327_reg_write_fast(addr, pmic6327_reg[bank][addr],token);

        if (KAL_TRUE == result)
        {
            break;
        }

        retryCnt++;
        if (retryCnt > ACCEPTABLE_RETRY_COUNT)
        {
            ASSERT(0);
        }
    }while(1);
    pmic_DCM_Enable();

    updateRetryCnt(retryCnt);
}

// Write register field
void dcl_pmic6327_field_write(PMU_FLAGS_LIST_ENUM flag, DCL_UINT8 sel)
{
    const PMU_FLAG_TABLE_ENTRY *pTable = pmic_flags_table;
    DCL_UINT32 i, table_size = 0;
    kal_uint32 token;
    kal_bool result = KAL_FALSE;

    kal_uint32 retryCnt = 0;

    table_size = GETARRNUM(pmic_flags_table);

    for (i = 0; i < table_size; i++)
    {
        if (flag == pTable[i].flagname)
        {
            break;
        }
    }

    if (i >= table_size)
        ASSERT(0); // Flag Unknown

    pmic_DCM_Disable();
    do{
        token=i2c_pmic_getToken();
        i2c_pmic_speedup(token);
        I2C_PMIC_LOG(I2C_field_write,token);        
        pmic6327_reg[PMIC_BANK0][pTable[i].offset] &= ~(pTable[i].mask);
        pmic6327_reg[PMIC_BANK0][pTable[i].offset] |= ((kal_uint8)sel << pTable[i].shift);    
        result = pmic6327_reg_write_fast(pTable[i].offset, pmic6327_reg[PMIC_BANK0][pTable[i].offset],token);

        if (KAL_TRUE == result)
        {
            break;
        }

        retryCnt++;
        if (retryCnt > ACCEPTABLE_RETRY_COUNT)
        {
            ASSERT(0);
        }
    }while(1);
    pmic_DCM_Enable();

    updateRetryCnt(retryCnt);
}
//////////////////////////////////////////////////
//                  READ APIs                   //
//////////////////////////////////////////////////

// Read Whole Bytes
DCL_UINT8 dcl_pmic6327_byte_return(DCL_UINT8 addr, DCL_UINT32 bank)
{
    kal_uint32 token;
    kal_bool result = KAL_FALSE;

    kal_uint32 retryCnt = 0;

    pmic_DCM_Disable();
    do{
        token=i2c_pmic_getToken();
        i2c_pmic_speedup(token);
        I2C_PMIC_LOG(I2C_byte_return,token);      
        result = pmic6327_reg_read_fast(addr, &pmic6327_reg[bank][addr],token);

        if (KAL_TRUE == result)
        {
            break;
        }

        retryCnt++;
        if (retryCnt > ACCEPTABLE_RETRY_COUNT)
        {
            ASSERT(0);
        }
    }while(1);
    pmic_DCM_Enable();

    updateRetryCnt(retryCnt);
        
    return pmic6327_reg[bank][addr];
}

// Exported for EM used
void pmic6327_EM_reg_write(kal_uint8 reg, kal_uint8 val, kal_uint32 bank){
    dcl_pmic6327_byte_write(reg, val, bank);
}

kal_uint8 pmic6327_EM_reg_read(kal_uint8 reg, kal_uint32 bank){
    return  dcl_pmic6327_byte_return(reg, bank);
}

PMU_CTRL_PMIC_ECO_VERSION_ENUM pmic_get_ECO_version()
{
    return PMIC_ECO_E1;
}

#if defined(__MODEM_CCCI_EXIST__) && !defined(__UBL__) && !defined(__FUE__)
void pmic6327_ccci_callback(CCCI_BUFF_T *buff)
{
    PMIC6327_CCCI_DATA *req_data = (PMIC6327_CCCI_DATA *)(&(buff->data[1]));
    PMIC6327_CCCI_DATA rsp_data;

	ASSERT(buff->channel == CCCI_PMIC_ACK_CHANNEL);

    switch(req_data->pmic6327_op)
    {
        case PMIC6327_VMC_SET_ENABLE:
        {
            dcl_pmic6327_field_write(RG_VMC_EN, req_data->pmic6327_param1);
            rsp_data.pmic6327_op = PMIC6327_VMC_SET_ENABLE;
            rsp_data.pmic6327_param1 = 0;
        }
        break;

        case PMIC6327_VMC_SET_VOLTAGE:
        {
            DCL_UINT16	regVal;
            regVal = PMU_Parameter_to_Value(ENC(LDO_BUCK_SET_VOLTAGE, VMC), buff->reserved);
            
            dcl_pmic6327_field_write(RG_VMC_VOSEL, regVal);
            rsp_data.pmic6327_op = PMIC6327_VMC_SET_VOLTAGE;
            rsp_data.pmic6327_param1 = 0;
        }
        break;

        default:
        {
            ASSERT(0);
        }
        break;
    }

    ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&rsp_data), 0);
}
#endif

const DCL_UINT32 vrf18_vosel[] =
{
    PMU_VOLT_01_450000_V,   PMU_VOLT_01_475000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_525000_V,
    PMU_VOLT_01_550000_V,   PMU_VOLT_01_575000_V,   PMU_VOLT_01_600000_V,   PMU_VOLT_01_625000_V,
    PMU_VOLT_01_650000_V,   PMU_VOLT_01_675000_V,   PMU_VOLT_01_700000_V,   PMU_VOLT_01_725000_V,
    PMU_VOLT_01_750000_V,   PMU_VOLT_01_775000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_01_825000_V,
    PMU_VOLT_01_850000_V,   PMU_VOLT_01_875000_V,   PMU_VOLT_01_900000_V,   PMU_VOLT_01_925000_V,
    PMU_VOLT_01_950000_V,   PMU_VOLT_01_975000_V,   PMU_VOLT_02_000000_V,   PMU_VOLT_02_025000_V,
    PMU_VOLT_02_050000_V,   PMU_VOLT_02_075000_V,   PMU_VOLT_02_100000_V,   PMU_VOLT_02_125000_V,
    PMU_VOLT_02_150000_V,   PMU_VOLT_02_175000_V,   PMU_VOLT_02_200000_V,   PMU_VOLT_02_225000_V,
};

const DCL_UINT32 vsim_vosel[] =
{
    PMU_VOLT_01_800000_V,   PMU_VOLT_03_000000_V,
};

const DCL_UINT32 vmc_io_vosel[] =
{
    PMU_VOLT_01_300000_V,   PMU_VOLT_01_500000_V,   PMU_VOLT_01_800000_V,   PMU_VOLT_02_500000_V,
    PMU_VOLT_02_800000_V,   PMU_VOLT_03_000000_V,   PMU_VOLT_03_100000_V,   PMU_VOLT_03_300000_V,
};

PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
    {ENC(LDO_BUCK_SET_VOLTAGE, VRF18),		vrf18_vosel,		NULL,				GETARRNUM(vrf18_vosel)		},    
	{ENC(LDO_BUCK_SET_VOLTAGE, VSIM),		vsim_vosel,		    NULL,				GETARRNUM(vsim_vosel)		},
    {ENC(LDO_BUCK_SET_VOLTAGE, VMC),		vmc_io_vosel,		NULL,				GETARRNUM(vmc_io_vosel)	}, 
};

extern PMU_CONTROL_HANDLER pmu_control_handler;

DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6327_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
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
                    dcl_pmic6327_field_write(RG_VRF18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VIO18:
                {
                    dcl_pmic6327_field_write(RG_VIO18_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM:
                {
                    dcl_pmic6327_field_write(RG_VSIM_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                case VMC:
                {
                    dcl_pmic6327_field_write(RG_VMC_EN, pLdoBuckCtrl->enable);
                    return_val = STATUS_OK;
                }
                break;

                //1. It's not allow to disable VTCXO in register control mode,
                //   because of MT6280 may not have external 32K.
                //2. Control VTCXO on/off status in srclken control mode is meaningless.
                //1+2 => There is no requirement to configure VTCXO on/off status.
#if defined(__MEUT__)
                case VTCXO:
                {
                    dcl_pmic6327_field_write(RG_VTCXO_EN, pLdoBuckCtrl->enable);
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
        
        case LDO_BUCK_SET_ON_SEL:
        {
            PMU_CTRL_LDO_BUCK_SET_ON_SEL *pLdoBuckCtrl=&(data->rPMULdoBuckSetOnSel);

            switch(pLdoBuckCtrl->mod)
            {
                case VTCXO:
                {
                	  // ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6327_field_write(VTCXO_ON_CTRL, !(pLdoBuckCtrl->onSel));
                    return_val = STATUS_OK;
                }
                break;
                case VRF18:
                {
                	  // ENABLE_WITH_SRCLKEN = 0, but 6329 SRCLKEN = 1, therefore we need NOT pLdoBuckCtrl->onsel
                    dcl_pmic6327_field_write(RG_VRF18_ON_CTRL, !(pLdoBuckCtrl->onSel));
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
                case VRF18:
                {
                    dcl_pmic6327_field_write(RG_VRF18_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VSIM:
                {
                    dcl_pmic6327_field_write(RG_VSIM_VOSEL, regVal);
                    return_val = STATUS_OK;
                }
                break;

                case VMC:
                {
                    dcl_pmic6327_field_write(RG_VMC_VOSEL, regVal);
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
                case VSIM:
                {
                    dcl_pmic6327_field_write(RG_VSIM_CAL, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
                }
                break;

                case VMC:
                {
                    dcl_pmic6327_field_write(RG_VMC_CAL, pLdoBuckCtrl->voltageCalibrationCode);
                    return_val = STATUS_OK;
                }
                break;

                case VTCXO:
                {
                    dcl_pmic6327_field_write(RG_VTCXO_CAL, pLdoBuckCtrl->voltageCalibrationCode);
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
            dcl_pmic6327_field_write(RG_VRF18_MODESET, pVrf18SetFpwm->enable);
            return_val = STATUS_OK;
        }
        break;

        case MISC_SET_REGISTER_VALUE:
        {			
            PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl = &(data->rPMUMiscSetRegisterValue);
            DCL_UINT8 bank = (DCL_UINT8)((pChrCtrl->offset & 0x80000000) >> 31);

            pmic6327_EM_reg_write((kal_uint8)pChrCtrl->offset,(kal_uint8)pChrCtrl->value, (kal_uint32)bank);
            return_val = STATUS_OK;
        }
        break;
        
        case MISC_GET_REGISTER_VALUE:
        {
            PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
            DCL_UINT8 bank = (DCL_UINT8)((pChrCtrl->offset & 0x80000000) >> 31);

            pChrCtrl->value = pmic6327_EM_reg_read((kal_uint8)pChrCtrl->offset, (kal_uint32)bank);
            return_val = STATUS_OK;
        }
        break;

        default:				
            return_val = STATUS_UNSUPPORTED;
        break;
    }

    return return_val;

}

extern void i2c_pmic_set_speed(kal_uint8 Sample,kal_uint8 Step);
extern void dcl_pmic6327_internal_init(void);
extern void i2c_pmic_init(void);
extern void pmu_drv_tool_customization_init(void);

void dcl_pmic6327_init(void){
    kal_uint32 i;

#if defined(__MODEM_CCCI_EXIST__) && !defined(__UBL__) && !defined(__FUE__)
    ccci_init(CCCI_PMIC_CHANNEL, NULL);
	ccci_init(CCCI_PMIC_ACK_CHANNEL, pmic6327_ccci_callback);
#endif

	i2c_pmic_init();
	pmu_control_handler = PMIC6327_control_handler;
	pmu_parameter_size = GETARRNUM(pmu_parameter_table);

#if !defined(__UBL__) && !defined(__FUE__)
    i2cDcmHandle=DCM_GetHandle();
#endif

    //Disable deglitch.
    dcl_pmic6327_byte_write(0x01, 0x00, PMIC_BANK0);
    //Speed up I2C
    i2c_pmic_set_speed(0, 5);

    pmic6327_eco_version = PMIC6327_ECO_1_VERSION;

    // Get PMIC6327 ECO version
    {
        kal_uint16 eco_version = 0;
        eco_version = dcl_pmic6327_byte_return(VERSION_ADDR, PMIC_BANK0);       

        if (eco_version == PMIC6327_E1_VERSION)
        {
            pmic6327_eco_version = PMIC6327_ECO_1_VERSION;
        }
        else// if(eco_version == PMIC6327_E2_CID_CODE)
        {
            pmic6327_eco_version = PMIC6327_ECO_2_VERSION;
        }
        
    }

    for (i = 0;i < PMIC_BANK0_REG_NUM;i++){
        pmic6327_reg[PMIC_BANK0][i] = dcl_pmic6327_byte_return(i, PMIC_BANK0); 
    }

    dcl_pmic6327_internal_init();

#if (defined(MT6280_S00))
    //Set VCore sleep voltage to 1.1V for MT6280 E1
    dcl_pmic6327_byte_write(0x56, 0x10, 0);
#elif (defined(MT6280_S01))
    //Set VCore normal voltage to 1.1V for MT6280 E2
    dcl_pmic6327_byte_write(0x55, 0x10, 0);
#endif
    
    pmic6327_customization_init();

#if !defined(__UBL__) && !defined(__FUE__)
    pmu_drv_tool_customization_init();
#endif //#if !defined(__UBL__) && !defined(__FUE__)
}

DCL_UINT32 DRV_Read_PMIC_Data(DCL_UINT32 pmic_addr)
{
    DCL_UINT8 bank = (DCL_UINT8)((pmic_addr & 0x80000000) >> 31);
    return dcl_pmic6327_byte_return((DCL_UINT8)pmic_addr, bank);
}

void DRV_Write_PMIC_Data(DCL_UINT32 pmic_addr, DCL_UINT32 value)
{
    DCL_UINT8 bank = (DCL_UINT8)((pmic_addr & 0x80000000) >> 31);
    dcl_pmic6327_byte_write((DCL_UINT8)pmic_addr, value, bank);
}

#endif //#if (defined(PMIC_6327_REG_API))

