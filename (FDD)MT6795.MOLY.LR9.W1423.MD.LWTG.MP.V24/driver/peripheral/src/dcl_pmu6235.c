


#include "reg_base.h"
#include "drv_comm.h"
#include "init.h"
#include "intrCtrl.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

#if defined(PMIC_6223_REG_API) || defined(PMIC_6238_REG_API)

#if !defined(DRV_PMIC_OFF)

#ifndef __DRV_DEBUG_dcl_pmu6235_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PMU_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PMU_DRV_ReadReg32(addr)               DRV_Reg32(addr)
#else // #ifndef __DRV_DEBUG_dcl_pmu6235_REG_READ_WRITE__
#define PMU_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PMU_DRV_SetBits16(addr, data)         DRV_DBG_SetBits(addr, data)
#define PMU_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PMU_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define PMU_DRV_ReadReg32(addr)               DRV_DBG_Reg32(addr)
#endif // #ifndef __DRV_DEBUG_dcl_pmu6235_REG_READ_WRITE__

#else //!defined(DRV_PMIC_OFF)

#define PMU_DRV_ClearBits16(addr,data)
#define PMU_DRV_SetBits16(addr, data) 
#define PMU_DRV_WriteReg16(addr, data)
#define PMU_DRV_ReadReg16(addr)               drv_dummy_return()
#define PMU_DRV_ReadReg32(addr)               drv_dummy_return()

#endif //!defined(DRV_PMIC_OFF)

#if ( defined(MT6238PMU) || defined(MT6235PMU) )
#include "init.h"
static ECO_VERSION ECONumber;
//static kal_bool pmuDeFeatureMax2ChrCurrent;
#endif // #if defined(PMIC_6238_REG_API)


const kal_uint8 cv_vth[]=
{
	14,10,6,2,30,26,22,18,15,11,7,3,31,27,23,19,12,8,4,0,28,24,20,16,13,9,5,1,29,25,21,17
};

/******************************************************************
         PMIC_CON0 API
******************************************************************/
/*
* FUNCTION
*	dcl_pmu6235_get_vrf_status
*
* DESCRIPTION
*  To get RF LDO status
*
* CALLS
*
*
* PARAMETERS
*	None
*
* RETURNS
*	DCL_TRUE: RF LDO is enable. DCL_FALSE: RF LDO is disable
*
* GLOBALS AFFECTED
*   external_global
*/
DCL_BOOL dcl_pmu6235_get_vrf_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (reg_val16 & VRF_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vrf(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (enable == DCL_TRUE)
      reg_val16 |= VRF_EN;
   else
      reg_val16 &= (~VRF_EN);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrf_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (enable == DCL_TRUE)
      reg_val16 |= VRF_EN_FORCE;
   else
      reg_val16 &= (~VRF_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrf_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (enable == DCL_TRUE)
      reg_val16 |= VRF_PLNMOS_DIS;
   else
      reg_val16 &= (~VRF_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalrf(pmu_icalrf_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   reg_val16 &= (~ICALRF_EN);
   reg_val16 |= ((code<<ICALRF_EN_SHIFT) & ICALRF_EN);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrf_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   reg_val16 &= (~VRF_CAL);
   reg_val16 |= ((value<<VRF_CAL_SHIFT) & VRF_CAL);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

#if defined(PMIC_6238_REG_API)
void dcl_pmu6235_sel_vrf_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (enable == DCL_TRUE)
      reg_val16 |= VRF_ON_SEL;
   else
      reg_val16 &= (~VRF_ON_SEL);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}
#endif /* PMIC_6238_REG_API */

void dcl_pmu6235_set_tpsel(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   reg_val16 &= (~TPSEL);
   reg_val16 |= ((value<<TPSEL_SHIFT) & TPSEL);
   PMU_DRV_WriteReg16(PMIC_CON0, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON1 API
******************************************************************/
void dcl_pmu6235_set_vcore_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (enable == DCL_TRUE)
      reg_val16 |= VCORE_EN_FORCE;
   else
      reg_val16 &= (~VCORE_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

#if defined(PMIC_6223_REG_API)
void dcl_pmu6235_set_icalcore(dcl_pmu6235_icalcore_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   reg_val16 &= (~ICALCORE_EN);
   reg_val16 |= ((code<<ICALCORE_EN_SHIFT) & ICALCORE_EN);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vcore_sel(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   reg_val16 &= (~VCORE_SEL);
   reg_val16 |= ((value<<VCORE_SEL_SHIFT) & VCORE_SEL);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vcore_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   reg_val16 &= (~VCORE_CAL);
   reg_val16 |= ((value<<VCORE_CAL_SHIFT) & VCORE_CAL);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vtcxo_pwrsave(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (enable == DCL_TRUE)
      reg_val16 |= VCTXO_PWRSAVE_EN;
   else
      reg_val16 &= (~VCTXO_PWRSAVE_EN);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrf_pwrsave(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (enable == DCL_TRUE)
      reg_val16 |= VRF_PWRSAVE_EN;
   else
      reg_val16 &= (~VRF_PWRSAVE_EN);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}
#endif /*PMIC_6223_REG_API*/

#if defined(PMIC_6238_REG_API)
void dcl_pmu6235_set_adc_in_edge(DCL_BOOL positive)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (positive == DCL_TRUE)
      reg_val16 |= ADC_IN_EDGE;
   else
      reg_val16 &= (~ADC_IN_EDGE);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_fast_slow(DCL_BOOL fast)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (fast == DCL_TRUE)
      reg_val16 |= FAST_SLOW;
   else
      reg_val16 &= (~FAST_SLOW);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_pwmb_resol(DCL_BOOL four_bits)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (four_bits == DCL_TRUE)
      reg_val16 |= PWMB_SHIFT;
   else
      reg_val16 &= (~PWMB_SHIFT);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_acc_out_init(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   reg_val16 &= (~ACC_OUT_INIT);
   reg_val16 |= ((value<<ACC_OUT_INIT_SHIFT) & ACC_OUT_INIT);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

#endif /*PMIC_6238_REG_API*/

DCL_BOOL dcl_pmu6235_get_vrtc_staus(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 & VRTC_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vrtc_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (enable == DCL_TRUE)
      reg_val16 |= VRTC_EN_FORE;
   else
      reg_val16 &= (~VRTC_EN_FORE);
   PMU_DRV_WriteReg16(PMIC_CON1, reg_val16);
   RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6235_get_vio_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 & VIO_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

#if defined(PMIC_6223_REG_API)
DCL_BOOL dcl_pmu6235_get_vm_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 & VM_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}
#endif /*PMIC_6223_REG_API*/

/******************************************************************
         PMIC_CON2 API
******************************************************************/
void dcl_pmu6235_set_vio_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   if (enable == DCL_TRUE)
      reg_val16 |= VIO_EN_FORCE;
   else
      reg_val16 &= (~VIO_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalio(pmu_icalio_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   reg_val16 &= (~VCALIO_EN);
   reg_val16 |= ((code<<VCALIO_EN_SHIFT) & VCALIO_EN);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_antiudsh_io_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_IO_DN;
   else
      reg_val16 &= (~ANTIUDSH_IO_DN);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vio_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   reg_val16 &= (~VIO_CAL);
   reg_val16 |= ((value<<VIO_CAL_SHIFT) & VIO_CAL);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vm_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   if (enable == DCL_TRUE)
      reg_val16 |= VM_EN_FORCE;
   else
      reg_val16 &= (~VM_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalm(pmu_icalm_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   reg_val16 &= (~ICALM_EN);
   reg_val16 |= ((code<<ICALM_EN_SHIFT) & ICALM_EN);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_antiudsh_m_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_M_DN;
   else
      reg_val16 &= (~ANTIUDSH_M_DN);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vm_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   reg_val16 &= (~VM_CAL);
   reg_val16 |= ((value<<VM_CAL_SHIFT) & VM_CAL);
   PMU_DRV_WriteReg16(PMIC_CON2, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON3 API
******************************************************************/
DCL_BOOL dcl_pmu6235_get_vsim_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   if (reg_val16 & VSIM_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vsim_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM_EN_FORCE;
   else
      reg_val16 &= (~VSIM_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalsim(pmu_icalsim_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   reg_val16 &= (~ICALSIM_EN);
   reg_val16 |= ((code<<ICALSIM_EN_SHIFT) & ICALSIM_EN);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_antiudsh_sim_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_SIM_DN;
   else
      reg_val16 &= (~ANTIUDSH_SIM_DN);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM_PLNMOS_DIS;
   else
      reg_val16 &= (~VSIM_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   reg_val16 &= (~VSIM_CAL);
   reg_val16 |= ((value<<VSIM_CAL_SHIFT) & VSIM_CAL);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrtc_step1_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   reg_val16 &= (~VRTC_STEP1_CAL);
   reg_val16 |= ((value<<VRTC_STEP1_CAL_SHIFT) & VRTC_STEP1_CAL);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrtc_step2_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   reg_val16 &= (~VRTC_STEP2_CAL);
   reg_val16 |= ((value<<VRTC_STEP2_CAL_SHIFT) & VRTC_STEP2_CAL);
   PMU_DRV_WriteReg16(PMIC_CON3, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON4 API
******************************************************************/
DCL_BOOL dcl_pmu6235_get_vtcxo_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (reg_val16 & VCTXO_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vtcxo_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VCTXO_EN_FORCE;
   else
      reg_val16 &= (~VCTXO_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vtcxo(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VCTXO_EN;
   else
      reg_val16 &= (~VCTXO_EN);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vtcxo_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VCTXO_PLNMOS_DIS;
   else
      reg_val16 &= (~VCTXO_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vtcxo_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   reg_val16 &= (~VCTXO_CAL);
   reg_val16 |= ((value<<VCTXO_CAL_SHIFT) & VCTXO_CAL);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6235_get_va_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (reg_val16 & VA_STATUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_va_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VA_EN_FORCE;
   else
      reg_val16 &= (~VA_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_va(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VA_EN_SEL;
   else
      reg_val16 &= (~VA_EN_SEL);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_va_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   reg_val16 &= (~VA_CAL);
   reg_val16 |= ((value<<VA_CAL_SHIFT) & VA_CAL);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vrtc_cal_latch(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (enable == DCL_TRUE)
      reg_val16 |= VRTC_CAL_LATCH_EN;
   else
      reg_val16 &= (~VRTC_CAL_LATCH_EN);
   PMU_DRV_WriteReg16(PMIC_CON4, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON5 API
******************************************************************/
void dcl_pmu6235_set_vibr(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= VIBR_EN;
   else
      reg_val16 &= (~VIBR_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_kpled(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= KPLEN_EN;
   else
      reg_val16 &= (~KPLEN_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_rled(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= RLED_EN;
   else
      reg_val16 &= (~RLED_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_gled(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= GLEN_EN;
   else
      reg_val16 &= (~GLEN_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_bled(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= BLEN_EN;
   else
      reg_val16 &= (~BLEN_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM_EN;
   else
      reg_val16 &= (~VSIM_EN);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim_sel(pmu_vsim_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   reg_val16 &= (~VSIM_SEL);
   reg_val16 |= ((volt<<VSIM_SEL_SHIFT) & VSIM_SEL);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
   RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6235_is_ovp_occurred(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 & OVP)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_is_chr_det(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 & CHR_DET)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_is_bat_on(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 & BAT_ON)
      return DCL_FALSE;
   else
      return DCL_TRUE;
}

DCL_BOOL dcl_pmu6235_is_cv_mode(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 & CV)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}


void dcl_pmu6235_set_adc_meas_on(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
#if defined(PMIC_6238_REG_API)
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   if (enable == DCL_TRUE)
      reg_val16 |= (ISENSE_OUT_EN|VBAT_OUT_EN);
   else
      reg_val16 &= (~(ISENSE_OUT_EN|VBAT_OUT_EN));
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
#elif defined(PMIC_6223_REG_API)
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (enable == DCL_TRUE)
      reg_val16 |= INT_NODE_MUX_MSB;
   else
      reg_val16 &= (~INT_NODE_MUX_MSB);
   PMU_DRV_WriteReg16(PMIC_CON5, reg_val16);
#endif
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON6 API
******************************************************************/
void dcl_pmu6235_set_chron(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   if (enable == DCL_TRUE)
      reg_val16 |= CHR_EN;
   else
      reg_val16 &= (~CHR_EN);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_chron_internal(DCL_BOOL enable)
{
    DCL_UINT16  reg_val16;
    //DCL_UINT32  savedMask;

    reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
    if (enable == DCL_TRUE)
        reg_val16 |= CHR_EN;
    else
        reg_val16 &= (~CHR_EN);
    PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
}



void dcl_pmu6235_set_chr_cur_offset(pmu_chr_cur_offset offset)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16 &= (~CHOFST);
   reg_val16 |= ((offset<<CHOFST_SHIFT) & CHOFST);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

pmu_chr_cur_level dcl_pmu6235_get_chr_cur_level(void);
void dcl_pmu6235_set_chr_cur_level(pmu_chr_cur_level level)
{
    DCL_UINT16  reg_val16;
    DCL_UINT32  savedMask;
    DCL_UINT16  chr_status = 0x0000;
    pmu_chr_cur_level current_level;

#if defined(PMIC_6238_REG_API)
	#if defined(MT6235PMU)
	{
		if ((DCL_UINT8)level >= (DCL_UINT8)CHR_CUR_650)
		{
			level = CHR_CUR_450;
		}
	}
	#endif // #if defined(MT6235PMU)
#endif //#if defined(PMIC_6238_REG_API)

    current_level = dcl_pmu6235_get_chr_cur_level();
    if(current_level > level)
    {
    // turn off charger, prevent below case 1 happen.
    // level 6  change to level 4:  	6 -> 7 -> 0 -> 1 -> 2 -> 3 -> 4
       dcl_pmu6235_set_chron_internal(DCL_FALSE);
    // level 6  change to level 4:  	6 -> off -> 0 -> 1 -> 2 -> 3 -> 4
    }


    savedMask = SaveAndSetIRQMask();
    chr_status = PMU_DRV_ReadReg16(PMIC_CON6) & CHR_EN;
    // turn off charger
       //dcl_pmu6235_set_chron_internal(DCL_FALSE);

    reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
    reg_val16 &= (~CLASS_D);
    reg_val16 |= ((level<<CLASS_D_SHIFT) & CLASS_D);
    PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);

    if (chr_status & CHR_EN)
    {
        // turn on charger
        dcl_pmu6235_set_chron_internal(DCL_TRUE);
    }
    RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_chron_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   if (enable == DCL_TRUE)
      reg_val16 |= CHRON_FORCE;
   else
      reg_val16 &= (~CHRON_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

#if defined(PMIC_6223_REG_API)
void dcl_pmu6235_set_chr_thermal_thres(dcl_pmu6235_chr_thermal_thres thres)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16 &= (~CHR_AUX_THERMAL);
   reg_val16 |= ((thres<<CHR_AUX_THERMAL_SHIFT) & CHR_AUX_THERMAL);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_chr_ref_volt(dcl_pmu6235_ref_volt_step step)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16 &= (~CHR_AUX_REF_VOLT);
   reg_val16 |= ((step<<CHR_AUX_REF_VOLT_SHIFT) & CHR_AUX_REF_VOLT);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}
#endif /*PMIC_6223_REG_API*/

void dcl_pmu6235_set_chr_cv_volt(pmu_vbg_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
#if defined(PMIC_6223_REG_API)
   reg_val16 &= (~CHR_AUX_CV_VOLT);
   reg_val16 |= ((volt<<CHR_AUX_CV_VOLT_SHIFT) & CHR_AUX_CV_VOLT);
#elif defined(PMIC_6238_REG_API)
   reg_val16 &= (~CV_TUNE);
   reg_val16 |= ((volt<<CV_TUNE_SHIFT) & CV_TUNE);
#endif
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

#if defined(PMIC_6238_REG_API)
void dcl_pmu6235_set_cv_rt(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16 &= (~CV_RT);
   reg_val16 |= ((value<<CV_RT_SHIFT) & CV_RT);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_mtv_enable(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   if (enable == DCL_TRUE)
      reg_val16 |= MTV_EN;
   else
      reg_val16 &= (~MTV_EN);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_gpio_drv(pmu_gpio_drv_strength strength)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16 &= (~GPIO_DRV);
   reg_val16 |= ((strength<<GPIO_DRV_SHIFT) & GPIO_DRV);
   PMU_DRV_WriteReg16(PMIC_CON6, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_cv(kal_uint8 vth)
{
	kal_uint8 cv_rt;
	kal_uint8 cv_tune;

	if (vth>=32)
		ASSERT(0);

	cv_rt=vth&0x3;
	cv_tune=(vth&0x1c)>>2;
		
	
   	dcl_pmu6235_set_cv_rt(cv_rt);
   	dcl_pmu6235_set_chr_cv_volt(cv_tune); 	
}

kal_uint8 dcl_pmu6235_get_cv(void)
{
   kal_uint16  reg_val16;
   kal_uint16 val; 

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   reg_val16=(reg_val16&0x1f00)>>8;

   return (kal_uint8)reg_val16;
}

void dcl_pmu6235_reduce_cv_level(void)
{
	kal_uint8 cvlevel;
	kal_uint32 i;

	cvlevel=dcl_pmu6235_get_cv();

	for (i=0;i<32;i++)
	{
		if (cv_vth[i]==cvlevel)
			break;
	}

	if(i>0)
	{
		dcl_pmu6235_set_cv(cv_vth[i-1]);
	}
	else
	{
		ASSERT(0);
	} 

}
#endif /*PMIC_6238_REG_API*/

/******************************************************************
         PMIC_CON7 API
******************************************************************/
void dcl_pmu6235_set_uv_sel(pmu_uvlo_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~UV_SEL);
   reg_val16 |= ((volt<<UV_SEL_SHIFT) & UV_SEL);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_rbgsel(pmu_rbgsel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~RBGSEL);
   reg_val16 |= ((sel<<RBGSEL_SHIFT) & RBGSEL);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_ibgsel(pmu_ibgsel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~IBGSEL);
   reg_val16 |= ((sel<<IBGSEL_SHIFT) & IBGSEL);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_osc(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   if (enable == DCL_TRUE)
      reg_val16 &= (~OSCDIS);
   else
      reg_val16 |= OSCDIS;
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_cksel(pmu_cksel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~CKSEL);
   reg_val16 |= ((sel<<CKSEL_SHIFT) & CKSEL);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vbssel(pmu_vbssel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~VBSSEL);
   reg_val16 |= ((sel<<VBSSEL_SHIFT) & VBSSEL);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

#if defined(PMIC_6223_REG_API)
void dcl_pmu6235_reset_drv(DCL_BOOL reset)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   if (reset == DCL_TRUE)
      reg_val16 |= RESET_DRV;
   else
      reg_val16 &= (~RESET_DRV);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}
#endif /*PMIC_6223_REG_API*/

#if defined(PMIC_6238_REG_API)
void dcl_pmu6235_set_bias_gen_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   if (enable == DCL_TRUE)
      reg_val16 |= BIAS_GEN_FORCE;
   else
      reg_val16 &= (~BIAS_GEN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

#endif /*PMIC_6238_REG_API*/

void dcl_pmu6235_set_ov_hys_enb(pmu_ov_hys_enb value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~OV_HYS_ENB);
   reg_val16 |= ((value<<OV_HYS_ENB_SHIFT) & OV_HYS_ENB);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_ov_thfreeze(pmu_ov_thfreeze value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   reg_val16 &= (~OV_THFREEZE);
   reg_val16 |= ((value<<OV_THFREEZE_SHIFT) & OV_THFREEZE);
   PMU_DRV_WriteReg16(PMIC_CON7, reg_val16);
   RestoreIRQMask(savedMask);
}

DCL_BOOL dcl_pmu6235_is_pwrkey_deb_disable(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   if (reg_val16 & PWRKEY_DEB)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

#if defined(PMIC_6238_REG_API)
/******************************************************************
         PMIC_CON8 API
******************************************************************/
void dcl_pmu6235_set_sdm_order(pmu_sdm_order order)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~SDM_ORDER);
   reg_val16 |= ((order<<SDM_ORDER_SHIFT) & SDM_ORDER);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_pid_gain_p(pmu_pid_gain_p gain)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~GAIN_P);
   reg_val16 |= ((gain<<GAIN_P_SHIFT) & GAIN_P);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_pid_gain(pmu_pid_gain gain)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~GAIN);
   reg_val16 |= ((gain<<GAIN_SHIFT) & GAIN);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_pid_gain_d(pmu_pid_gain_d gain)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~GAIN_D);
   reg_val16 |= ((gain<<GAIN_D_SHIFT) & GAIN_D);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_duty_init(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~DUTY_INIT);
   reg_val16 |= ((value<<DUTY_INIT_SHIFT) & DUTY_INIT);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vcore_volt(pmu_vcore_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   reg_val16 &= (~VOSEL);
   reg_val16 |= ((volt<<VOSEL_SHIFT) & VOSEL);
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_sdm_fb_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   if (enable == DCL_TRUE)
      reg_val16 &= (~SDM_FB_EN);
   else
      reg_val16 |= SDM_FB_EN;
   PMU_DRV_WriteReg16(PMIC_CON8, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CON9 API
******************************************************************/
void dcl_pmu6235_set_vfbadj(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~VFBADJ);
   reg_val16 |= ((value<<VFBADJ_SHIFT) & VFBADJ);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_direct_ctrl_en(DCL_BOOL enable)
{
	DCL_UINT16  reg_val16;
	DCL_UINT32  savedMask;
	DCL_BOOL invert_setting;
/*
   Invert setting:
   Before MT6238/MT6235 E2 (Included E2)
   0: DVFS ==> dcl_pmu6235_set_direct_ctrl_en(DCL_FALSE)
   1: Direct feed through ==> dcl_pmu6235_set_direct_ctrl_en(DCL_TRUE)
   After MT6238/MT6235 E3 (Included E3)
	1: DVFS ==> dcl_pmu6235_set_direct_ctrl_en(DCL_FALSE)
   0: Direct feed through ==> dcl_pmu6235_set_direct_ctrl_en(DCL_TRUE)
*/
#if defined(MT6238PMU)
	if (ECONumber <= ENG_E2){
		invert_setting = DCL_FALSE;
	}else{
		invert_setting = DCL_TRUE;
	}
#elif defined(MT6235PMU) // #if defined(MT6238PMU)
	if (ECONumber <= ECO_E2){
		invert_setting = DCL_FALSE;
	}else{
		invert_setting = DCL_TRUE;
	}
#endif // #if defined(MT6238PMU)

 	if (invert_setting == DCL_TRUE){
		savedMask = SaveAndSetIRQMask();
		reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
		if (enable == DCL_TRUE)
			reg_val16 &= (~DIRECT_CTRL_EN);
		else
			reg_val16 |= DIRECT_CTRL_EN;
		PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
		RestoreIRQMask(savedMask);
	}else{
		savedMask = SaveAndSetIRQMask();
		reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
		if (enable == DCL_TRUE)
			reg_val16 |= DIRECT_CTRL_EN;
		else
			reg_val16 &= (~DIRECT_CTRL_EN);
		PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
		RestoreIRQMask(savedMask);
	}
}

void dcl_pmu6235_set_dcv_ck(pmu_dcv_ck clk)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~DCV_CK_SEL);
   reg_val16 |= ((clk<<DCV_CK_SEL_SHIFT) & DCV_CK_SEL);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_isel(pmu_isel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~ISEL);
   reg_val16 |= ((sel<<ISEL_SHIFT) & ISEL);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_adjcksel(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~ADJCKSEL);
   reg_val16 |= ((value<<ADJCKSEL_SHIFT) & ADJCKSEL);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_manual_mode(pmu_mode_set mode)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~MODESET);
   reg_val16 |= ((mode<<MODESET_SHIFT) & MODESET);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_auto_mode_en(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (value & 0x01)
      reg_val16 |= MODEEN0;
   else
      reg_val16 &= (~MODEEN0);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (value & 0x02)
      reg_val16 |= MODEEN1;
   else
      reg_val16 &= (~MODEEN1);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);

   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_mode_cmp(pmu_mode_cmp cmp)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~MODECMP);
   reg_val16 |= ((cmp<<MODECMP_SHIFT) & MODECMP);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_ave_current_mode(pmu_mode_ave_current mode)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   reg_val16 &= (~MODESEL1A);
   reg_val16 |= ((mode<<MODESEL1A_SHIFT) & MODESEL1A);
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_dcv_test_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (enable == DCL_TRUE)
      reg_val16 &= (~DCV_TEST_EN);
   else
      reg_val16 |= DCV_TEST_EN;
   PMU_DRV_WriteReg16(PMIC_CON9, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONA API
******************************************************************/
void dcl_pmu6235_set_pfm_max_current(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~PFMSEL_CURRENT);
   reg_val16 |= ((value<<PFMSEL_CURRENT_SHIFT) & PFMSEL_CURRENT);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_pfm_resistor(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~PFMSEL_RESISTOR);
   reg_val16 |= ((value<<PFMSEL_RESISTOR_SHIFT) & PFMSEL_RESISTOR);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_ndc_offset(pmu_ndc_offset offset)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~NCDOF);
   reg_val16 |= ((offset<<NCDOF_SHIFT) & NCDOF);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_dcv_trim(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~DCVTRIM);
   reg_val16 |= ((value<<DCVTRIM_SHIFT) & DCVTRIM);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_iasel(pmu_iasel volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~IASEL);
   reg_val16 |= ((volt<<IASEL_SHIFT) & IASEL);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_rsel(pmu_rsel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   reg_val16 &= (~RSEL);
   reg_val16 |= ((sel<<RSEL_SHIFT) & RSEL);
   PMU_DRV_WriteReg16(PMIC_CONA, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONB API
******************************************************************/
DCL_BOOL dcl_pmu6235_get_vusb_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (reg_val16 & VUSB_STAUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vusb_en_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (enable == DCL_TRUE)
      reg_val16 |= VUSB_EN_FORCE;
   else
      reg_val16 &= (~VUSB_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vusb_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (enable == DCL_TRUE)
      reg_val16 |= VUSB_EN;
   else
      reg_val16 &= (~VUSB_EN);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalusb(pmu_icalusb_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   reg_val16 &= (~ICALUSB_EN);
   reg_val16 |= ((code<<ICALUSB_EN_SHIFT) & ICALUSB_EN);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_antiudsh_usb_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_USB_DN;
   else
      reg_val16 &= (~ANTIUDSH_USB_DN);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vusb_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (enable == DCL_TRUE)
      reg_val16 |= VUSB_PLNMOS_DIS;
   else
      reg_val16 &= (~VUSB_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vusb_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   reg_val16 &= (~VUSB_CAL);
   reg_val16 |= ((value<<VUSB_CAL_SHIFT) & VUSB_CAL);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vfbadj_slp(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   reg_val16 &= (~VFBADJ_SLP);
   reg_val16 |= ((value<<VFBADJ_SLP_SHIFT) & VFBADJ_SLP);
   PMU_DRV_WriteReg16(PMIC_CONB, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONC API
******************************************************************/
DCL_BOOL dcl_pmu6235_get_vsim2_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (reg_val16 & VSIM2_STAUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

void dcl_pmu6235_set_vsim2_en_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM2_EN_FORCE;
   else
      reg_val16 &= (~VSIM2_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icalsim2(pmu_icalsim2_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   reg_val16 &= (~ICALSIM2_EN);
   reg_val16 |= ((code<<ICALSIM2_EN_SHIFT) & ICALSIM2_EN);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_antiudsh_sim2_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_SIM2_DN;
   else
      reg_val16 &= (~ANTIUDSH_SIM2_DN);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim2_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM2_PLNMOS_DIS;
   else
      reg_val16 &= (~VSIM2_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim2_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   reg_val16 &= (~VSIM2_CAL);
   reg_val16 |= ((value<<VSIM2_CAL_SHIFT) & VSIM2_CAL);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_clk_source_sel(pmu_clk_src_sel source)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   reg_val16 &= (~CLK_SOURCE_SEL);
   reg_val16 |= ((source<<CLK_SOURCE_SEL_SHIFT) & CLK_SOURCE_SEL);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vtcxo_on_sel(pmu_vtcxo_on_sel sel)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   reg_val16 &= (~VTCXO_ON_SEL);
   reg_val16 |= ((sel<<VTCXO_ON_SEL_SHIFT) & VTCXO_ON_SEL);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim_pwr_saving_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM_PWR_SAVING;
   else
      reg_val16 &= (~VSIM_PWR_SAVING);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim2_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (enable == DCL_TRUE)
      reg_val16 |= VSIM2_EN;
   else
      reg_val16 &= (~VSIM2_EN);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vsim2_sel(pmu_vsim_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   reg_val16 &= (~VSIM2_SEL);
   reg_val16 |= ((volt<<VSIM2_SEL_SHIFT) & VSIM2_SEL);
   PMU_DRV_WriteReg16(PMIC_CONC, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_COND API
******************************************************************/
//DCL_BOOL dcl_pmu6235_get_vmc_status(void)
DCL_BOOL dcl_pmu6235_get_vbt_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (reg_val16 & VBT_STAUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

//void dcl_pmu6235_set_vmc_en_force(DCL_BOOL enable)
void dcl_pmu6235_set_vbt_en_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (enable == DCL_TRUE)
      reg_val16 |= VBT_EN_FORCE;
   else
      reg_val16 &= (~VBT_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_icalmc(dcl_pmu6235_icalmc_code code)
void dcl_pmu6235_set_icalbt(pmu_icalbt_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   reg_val16 &= (~ICALBT_EN);
   reg_val16 |= ((code<<ICALBT_EN_SHIFT) & ICALBT_EN);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_antiudsh_mc_dn(DCL_BOOL enable)
void dcl_pmu6235_set_antiudsh_bt_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_BT_DN;
   else
      reg_val16 &= (~ANTIUDSH_BT_DN);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vmc_plnmos_dis(DCL_BOOL enable)
void dcl_pmu6235_set_vbt_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (enable == DCL_TRUE)
      reg_val16 |= VBT_PLNMOS_DIS;
   else
      reg_val16 &= (~VBT_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vmc_cal(DCL_UINT8 value)
void dcl_pmu6235_set_vbt_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   reg_val16 &= (~VBT_CAL);
   reg_val16 |= ((value<<VBT_CAL_SHIFT) & VBT_CAL);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vmc_en(DCL_BOOL enable)
void dcl_pmu6235_set_vbt_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (enable == DCL_TRUE)
      reg_val16 |= VBT_EN;
   else
      reg_val16 &= (~VBT_EN);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vmc_sel(dcl_pmu6235_vmc_volt volt)
void dcl_pmu6235_set_vbt_sel(pmu_vbt_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   reg_val16 &= (~VBT_SEL);
   reg_val16 |= ((volt<<VBT_SEL_SHIFT) & VBT_SEL);
   PMU_DRV_WriteReg16(PMIC_COND, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONE API
******************************************************************/
//DCL_BOOL dcl_pmu6235_get_vcamera_status(void)
DCL_BOOL dcl_pmu6235_get_vcam_d_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (reg_val16 & VCAM_D_STAUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

//void dcl_pmu6235_set_vcamera_en_force(DCL_BOOL enable)
void dcl_pmu6235_set_vcam_d_en_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (enable == DCL_TRUE)
      reg_val16 |= VCAM_D_EN_FORCE;
   else
      reg_val16 &= (~VCAM_D_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_icalcamera(dcl_pmu6235_icalcamera_code code)
void dcl_pmu6235_set_icalcam_d(pmu_icalcam_d_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   reg_val16 &= (~ICALCAM_D_EN);
   reg_val16 |= ((code<<ICALCAM_D_EN_SHIFT) & ICALCAM_D_EN);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_antiudsh_camera_dn(DCL_BOOL enable)
void dcl_pmu6235_set_antiudsh_cam_d_dn(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (enable == DCL_TRUE)
      reg_val16 |= ANTIUDSH_CAM_D_DN;
   else
      reg_val16 &= (~ANTIUDSH_CAM_D_DN);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vcamera_plnmos_dis(DCL_BOOL enable)
void dcl_pmu6235_set_vcam_d_plnmos_dis(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (enable == DCL_TRUE)
      reg_val16 |= VCAM_D_PLNMOS_DIS;
   else
      reg_val16 &= (~VCAM_D_PLNMOS_DIS);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vcamera_cal(DCL_UINT8 value)
void dcl_pmu6235_set_vcam_d_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   reg_val16 &= (~VCAM_D_CAL);
   reg_val16 |= ((value<<VCAM_D_CAL_SHIFT) & VCAM_D_CAL);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_dcv_slew_ctrl(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   reg_val16 &= (~DCV_SLEW_CTRL);
   reg_val16 |= ((value<<DCV_SLEW_CTRL_SHIFT) & DCV_SLEW_CTRL);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vcamera_en(DCL_BOOL enable)
void dcl_pmu6235_set_vcam_d_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (enable == DCL_TRUE)
      reg_val16 |= VCAM_D_EN;
   else
      reg_val16 &= (~VCAM_D_EN);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vcamera_sel(dcl_pmu6235_vcamera_volt volt)
void dcl_pmu6235_set_vcam_d_sel(pmu_vcam_d_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   reg_val16 &= (~VCAM_D_SEL);
   reg_val16 |= ((volt<<VCAM_D_SEL_SHIFT) & VCAM_D_SEL);
   PMU_DRV_WriteReg16(PMIC_CONE, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONF API
******************************************************************/
//DCL_BOOL dcl_pmu6235_get_vsw_a_status(void)
DCL_BOOL dcl_pmu6235_get_vcam_a_status(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   if (reg_val16 & VCAM_A_STAUS)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

//void dcl_pmu6235_set_vsw_a_en_force(DCL_BOOL enable)
void dcl_pmu6235_set_vcam_a_en_force(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   if (enable == DCL_TRUE)
      reg_val16 |= VCAM_A_EN_FORCE;
   else
      reg_val16 &= (~VCAM_A_EN_FORCE);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_icalsw(dcl_pmu6235_icalsw_code code)
void dcl_pmu6235_set_icalcam_a(pmu_icalcam_a_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   reg_val16 &= (~ICALCAM_A_EN);
   reg_val16 |= ((code<<ICALCAM_A_EN_SHIFT) & ICALCAM_A_EN);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vsw_a_sel(dcl_pmu6235_vsw_a_volt volt)
void dcl_pmu6235_set_vcam_a_sel(pmu_vcam_a_volt volt)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   reg_val16 &= (~VCAM_A_SEL);
   reg_val16 |= ((volt<<VCAM_A_SEL_SHIFT) & VCAM_A_SEL);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vsw_a_cal(DCL_UINT8 value)
void dcl_pmu6235_set_vcam_a_cal(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   reg_val16 &= (~VCAM_A_CAL);
   reg_val16 |= ((value<<VCAM_A_CAL_SHIFT) & VCAM_A_CAL);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icala(pmu_icala_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   reg_val16 &= (~ICALA_EN);
   reg_val16 |= ((code<<ICALA_EN_SHIFT) & ICALA_EN);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_icaltcxo(pmu_icaltcxo_code code)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   reg_val16 &= (~ICALTCXO_EN);
   reg_val16 |= ((code<<ICALTCXO_EN_SHIFT) & ICALTCXO_EN);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

//void dcl_pmu6235_set_vsw_a_en(DCL_BOOL enable)
void dcl_pmu6235_set_vcam_a_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   if (enable == DCL_TRUE)
      reg_val16 |= VCAM_A_EN;
   else
      reg_val16 &= (~VCAM_A_EN);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_oc_fold_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   if (enable == DCL_TRUE)
      reg_val16 |= OC_FOLD_EN;
   else
      reg_val16 &= (~OC_FOLD_EN);
   PMU_DRV_WriteReg16(PMIC_CONF, reg_val16);
   RestoreIRQMask(savedMask);
}

/******************************************************************
         PMIC_CONG API
******************************************************************/
void dcl_pmu6235_set_vref_bg(pmu_vref_bg value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   reg_val16 &= (~VREF_BG);
   reg_val16 |= ((value<<VREF_BG_SHIFT) & VREF_BG);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_thr_sel(pmu_thr_sel value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   reg_val16 &= (~THR_SEL);
   reg_val16 |= ((value<<THR_SEL_SHIFT) & THR_SEL);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_ldo_soft_st_dis(DCL_BOOL disable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   if (disable == DCL_TRUE)
      reg_val16 |= LDO_SOFT_ST;
   else
      reg_val16 &= (~LDO_SOFT_ST);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_tpsel_led(DCL_UINT8 value)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   reg_val16 &= (~TPSEL_LED);
   reg_val16 |= ((value<<TPSEL_LED_SHIFT) & TPSEL_LED);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_isense_out_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   if (enable == DCL_TRUE)
      reg_val16 |= ISENSE_OUT_EN;
   else
      reg_val16 &= (~ISENSE_OUT_EN);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

void dcl_pmu6235_set_vbat_out_en(DCL_BOOL enable)
{
   DCL_UINT16  reg_val16;
   DCL_UINT32  savedMask;

   savedMask = SaveAndSetIRQMask();
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONG);
   if (enable == DCL_TRUE)
      reg_val16 |= VBAT_OUT_EN;
   else
      reg_val16 &= (~VBAT_OUT_EN);
   PMU_DRV_WriteReg16(PMIC_CONG, reg_val16);
   RestoreIRQMask(savedMask);
}

#endif /*PMIC_6238_REG_API*/


/******************************************************************
         PMU CV calibration API
******************************************************************/
void dcl_pmu6235_set_cv_calib(DCL_UINT32 index)
{
#if defined(PMIC_6223_REG_API)
   dcl_pmu6235_vbg_volt   volt;

   if (index > 31)
      return;

   if (index & 0x10)
      dcl_pmu6235_set_cksel(CK_SEL_5KHZ);
   else
      dcl_pmu6235_set_cksel(CK_SEL_10KHZ);

   if (index & 0x08)
      dcl_pmu6235_reset_drv(DCL_TRUE);
   else
      dcl_pmu6235_reset_drv(DCL_FALSE);

   volt = (index+4) & 0x07;
   dcl_pmu6235_set_chr_cv_volt(volt);
#elif  defined(PMIC_6238_REG_API)
   DCL_UINT8   value;

   if (index > 31)
      return;
   value = ((index+0x10) >> 3) & 0x3;
   dcl_pmu6235_set_cv_rt(value);
   value = 0x7 - ((index+0x4) & 0x07);
   dcl_pmu6235_set_chr_cv_volt((pmu_vbg_volt)value);
#endif /*PMIC_6223_REG_API*/
}

DCL_UINT8 dcl_pmu6235_get_cv_calib(void)
{
#if defined(PMIC_6223_REG_API)
   dcl_pmu6235_vbg_volt   volt;
   DCL_UINT16  reg_val16;
   DCL_UINT8   index;

   index = 0;
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   if (reg_val16|CKSEL)
      index |= 0x10;

   if (reg_val16|RESET_DRV)
      index |= 0x08;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   volt = (reg_val16 & CHR_AUX_CV_VOLT) >> CHR_AUX_CV_VOLT_SHIFT;
   index = index | ((volt+4) & 0x07);
   return index;
#elif defined(PMIC_6238_REG_API)
   DCL_UINT16  reg_val16;
   DCL_UINT8   index;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   index = (reg_val16 & (CV_TUNE|CV_TUNE)) >> CV_RT_SHIFT;
   index = ((((index<<3) + 0x10) & 0x18) | ((0x11 - (index>>2)) & 0x7));
   return index;
#endif /*PMIC_6223_REG_API*/
}

/******************************************************************
         PMU engineer mode
******************************************************************/
#if defined(PMIC_6223_REG_API)
#define dcl_pmu6235_MAX_REG_NUM    7
#elif defined(PMIC_6238_REG_API)
#define dcl_pmu6235_MAX_REG_NUM    16
#endif
void dcl_pmu6235_set_con_reg(DCL_UINT8 reg_num, DCL_UINT16 value)
{
   //DCL_UINT32 reg_base;

   if (reg_num > dcl_pmu6235_MAX_REG_NUM)
      return;
   //reg_base = PMIC_CON0+reg_num*4;
   PMU_DRV_WriteReg16((PMIC_CON0+reg_num*4), value);
}

DCL_UINT16 dcl_pmu6235_get_con_reg(DCL_UINT8 reg_num)
{
   DCL_UINT16 value;
   //DCL_UINT32 reg_base;

   if (reg_num > dcl_pmu6235_MAX_REG_NUM)
      return 0;
   //reg_base = PMIC_CON0+reg_num*4;
   value = PMU_DRV_ReadReg16(PMIC_CON0+reg_num*4);
   return value;
}

DCL_BOOL dcl_pmu6235_get_chron_force(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   if (reg_val16|CHRON_FORCE)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

pmu_chr_cur_level dcl_pmu6235_get_chr_cur_level(void)
{
   DCL_UINT16  reg_val16;
   pmu_chr_cur_level level;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   level = (pmu_chr_cur_level)((reg_val16 & CLASS_D) >> CLASS_D_SHIFT);
   return level;
}

pmu_chr_cur_offset dcl_pmu6235_get_chr_cur_offset(void)
{
   DCL_UINT16  reg_val16;
   pmu_chr_cur_offset offset;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON6);
   offset = (pmu_chr_cur_offset)((reg_val16 & CHOFST) >> CHOFST_SHIFT);
   return offset;
}

pmu_ov_thfreeze dcl_pmu6235_get_ov_thfreeze(void)
{
   DCL_UINT16  reg_val16;
   pmu_ov_thfreeze value;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   value = (pmu_ov_thfreeze)((reg_val16 & OV_THFREEZE) >> OV_THFREEZE_SHIFT);
   return value;
}

pmu_ov_hys_enb dcl_pmu6235_get_ov_hys_enb(void)
{
   DCL_UINT16  reg_val16;
   pmu_ov_hys_enb value;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON7);
   value = (pmu_ov_hys_enb)((reg_val16 & OV_HYS_ENB) >> OV_HYS_ENB_SHIFT);
   return value;
}

DCL_BOOL dcl_pmu6235_get_vibr(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | VIBR_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_kpled(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | KPLEN_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_rled(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | RLED_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_gled(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | GLEN_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_bled(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | BLEN_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_UINT8 dcl_pmu6235_get_vrf_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   value = (reg_val16 & VRF_CAL) >> VRF_CAL_SHIFT;
   return value;
}

#if defined(PMIC_6223_REG_API)
DCL_UINT8 dcl_pmu6235_get_vcore_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   value = (reg_val16 & VCORE_CAL) >> VCORE_CAL_SHIFT;
   return value;
}
#endif /*PMIC_6223_REG_API*/

DCL_UINT8 dcl_pmu6235_get_vm_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   value = (reg_val16 & VM_CAL) >> VM_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vio_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   value = (reg_val16 & VIO_CAL) >> VIO_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_va_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   value = (reg_val16 & VA_CAL) >> VA_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vtcxo_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   value = (reg_val16 & VCTXO_CAL) >> VCTXO_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vsim_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   value = (reg_val16 & VSIM_CAL) >> VSIM_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vrtc_step1_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   value = (reg_val16 & VRTC_STEP1_CAL) >> VRTC_STEP1_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vrtc_step2_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   value = (reg_val16 & VRTC_STEP2_CAL) >> VRTC_STEP2_CAL_SHIFT;
   return value;
}

DCL_BOOL dcl_pmu6235_get_vrf_force(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (reg_val16 | VRF_EN_FORCE)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vcore_force(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 | VCORE_EN_FORCE)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

/*
DCL_BOOL dcl_pmu6235_get_vsim_force(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   if (reg_val16 | VSIM_EN_FORCE)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}
*/
DCL_BOOL dcl_pmu6235_get_vsim(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON5);
   if (reg_val16 | VSIM_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

pmu_icalrf_code dcl_pmu6235_get_icalrf(void)
{
   pmu_icalrf_code  code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   code = (pmu_icalrf_code)((reg_val16 & ICALRF_EN) >> ICALRF_EN_SHIFT);
   return code;
}

pmu_icalm_code dcl_pmu6235_get_icalm(void)
{
   pmu_icalm_code   code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   code = (pmu_icalm_code)((reg_val16 & ICALM_EN) >> ICALM_EN_SHIFT);
   return code;
}

pmu_icalio_code dcl_pmu6235_get_icalio(void)
{
   pmu_icalio_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON2);
   code = (pmu_icalio_code)((reg_val16 & VCALIO_EN) >> VCALIO_EN_SHIFT);
   return code;
}

pmu_icalsim_code dcl_pmu6235_get_icalsim(void)
{
   pmu_icalsim_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON3);
   code = (pmu_icalsim_code)((reg_val16 & ICALSIM_EN) >> ICALSIM_EN_SHIFT);
   return code;
}

#if defined(PMIC_6223_REG_API)
pmu_icalcore_code dcl_pmu6235_get_icalcore(void)
{
pmu_icalcore_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   code = (reg_val16 & ICALCORE_EN) >> ICALCORE_EN_SHIFT;
   return code;
}
#endif /*PMIC_6223_REG_API*/

#if defined(PMIC_6238_REG_API)

pmu_vsim_volt dcl_pmu6235_get_vsim2_sel(void)
{
   pmu_vsim_volt volt;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   volt = (pmu_vsim_volt)((reg_val16 & VSIM2_SEL) >> VSIM2_SEL_SHIFT);
   return volt;
}

DCL_UINT8 dcl_pmu6235_get_vusb_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   value = (reg_val16 & VUSB_CAL) >> VUSB_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vsim2_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   value = (reg_val16 & VSIM2_CAL) >> VSIM2_CAL_SHIFT;
   return value;
}

DCL_BOOL dcl_pmu6235_get_vrf(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (reg_val16 &VRF_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vrf_sel_vrf_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON0);
   if (reg_val16 & VRF_ON_SEL)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

pmu_vtcxo_on_sel dcl_pmu6235_get_vtcxo_on_sel(void)
{
   pmu_vtcxo_on_sel sel;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   sel = (pmu_vtcxo_on_sel)((reg_val16 & VTCXO_ON_SEL) >> VTCXO_ON_SEL_SHIFT);
   return sel;
}

DCL_BOOL dcl_pmu6235_get_vtcxo(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON4);
   if (reg_val16 & VCTXO_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vusb_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (reg_val16 & VUSB_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vsim2_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   if (reg_val16 & VSIM2_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

/*
DCL_BOOL dcl_pmu6235_get_fast_slow(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 & FAST_SLOW)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_pwmb_resol(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON1);
   if (reg_val16 & PWMB_SHIFT)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

dcl_pmu6235_sdm_order dcl_pmu6235_get_sdm_order(void)
{
   dcl_pmu6235_sdm_order order;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   order = (reg_val16 & SDM_ORDER) >> SDM_ORDER_SHIFT;
   return order;
}
*/
pmu_pid_gain_p dcl_pmu6235_get_pid_gain_p(void)
{
   pmu_pid_gain_p gain;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   gain = (pmu_pid_gain_p)((reg_val16 & GAIN_P) >> GAIN_P_SHIFT);
   return gain;
}

pmu_pid_gain dcl_pmu6235_get_pid_gain(void)
{
  pmu_pid_gain gain;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   gain = (pmu_pid_gain)((reg_val16 & GAIN) >> GAIN_SHIFT);
   return gain;
}

pmu_pid_gain_d dcl_pmu6235_get_pid_gain_d(void)
{
   pmu_pid_gain_d gain;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   gain = (pmu_pid_gain_d)((reg_val16 & GAIN_D) >> GAIN_D_SHIFT);
   return gain;
}
/*
DCL_BOOL dcl_pmu6235_get_sdm_fb_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON8);
   if (reg_val16 & SDM_FB_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}
*/
DCL_BOOL dcl_pmu6235_get_direct_ctrl_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (reg_val16 & DIRECT_CTRL_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

pmu_dcv_ck dcl_pmu6235_get_dcv_ck(void)
{
   pmu_dcv_ck  clk;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   clk = (pmu_dcv_ck)((reg_val16 & DCV_CK_SEL) >> DCV_CK_SEL_SHIFT);
   return clk;
}

pmu_isel dcl_pmu6235_get_isel(void)
{
   pmu_isel    sel;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   sel = (pmu_isel)((reg_val16 & ISEL) >> ISEL_SHIFT);
   return sel;
}

DCL_UINT8 dcl_pmu6235_get_adjcksel(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   value = (reg_val16 & ADJCKSEL) >> ADJCKSEL_SHIFT;
   return value;
}

pmu_mode_set dcl_pmu6235_get_manual_mode(void)
{
   pmu_mode_set mode;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   mode = (pmu_mode_set)((reg_val16 & MODESET) >> MODESET_SHIFT);
   return mode;
}
/*
DCL_BOOL dcl_pmu6235_get_auto_mode_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (reg_val16 & MODEEN0)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}
*/
DCL_UINT8 dcl_pmu6235_get_auto_mode_en(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (reg_val16 & MODEEN0)
      value = 0x01;
   else
      value = 0;
   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   if (reg_val16 & MODEEN1)
      value |= 0x02;
   return value;
}

/*
dcl_pmu6235_mode_cmp dcl_pmu6235_get_mode_cmp(void)
{
   dcl_pmu6235_mode_cmp cmp;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   cmp = (reg_val16 & MODECMP) >> MODECMP_SHIFT;
   return cmp;
}

dcl_pmu6235_mode_ave_current dcl_pmu6235_get_ave_current_mode(void)
{
   dcl_pmu6235_mode_ave_current mode;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   mode = (reg_val16 & MODESEL1A) >> MODESEL1A_SHIFT;
   return mode;
}

DCL_BOOL dcl_pmu6235_get_dcv_test_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   if (reg_val16 & DCV_TEST_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}
*/
DCL_UINT8 dcl_pmu6235_get_pfm_max_current(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   value = (reg_val16 & PFMSEL_CURRENT) >> PFMSEL_CURRENT_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_pfm_resistor(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   value = (reg_val16 & PFMSEL_RESISTOR) >> PFMSEL_RESISTOR_SHIFT;
   return value;
}
/*
dcl_pmu6235_ndc_offset dcl_pmu6235_get_ndc_offset(void)
{
   dcl_pmu6235_ndc_offset offset;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   offset = (reg_val16 & NCDOF) >> NCDOF_SHIFT;
   return offset;
}

DCL_UINT8 dcl_pmu6235_get_dcv_trim(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   value = (reg_val16 & DCVTRIM) >> DCVTRIM_SHIFT;
   return value;
}
*/
pmu_iasel dcl_pmu6235_get_iasel(void)
{
   pmu_iasel   volt;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   volt = (pmu_iasel)((reg_val16 & IASEL) >> IASEL_SHIFT);
   return volt;
}
/*
dcl_pmu6235_rsel dcl_pmu6235_get_rsel(void)
{
   dcl_pmu6235_rsel    sel;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONA);
   sel = (reg_val16 & RSEL) >> RSEL_SHIFT;
   return sel;
}
*/
DCL_UINT8 dcl_pmu6235_get_dcv_slew_ctrl(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   value = (reg_val16 & DCV_SLEW_CTRL) >> DCV_SLEW_CTRL_SHIFT;
   return value;
}

pmu_icala_code dcl_pmu6235_get_icala(void)
{
   pmu_icala_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   code = (pmu_icala_code)((reg_val16 & ICALA_EN) >> ICALA_EN_SHIFT);
   return code;
}

pmu_icaltcxo_code dcl_pmu6235_get_icaltcxo(void)
{
   pmu_icaltcxo_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   code = (pmu_icaltcxo_code)((reg_val16 & ICALTCXO_EN) >> ICALTCXO_EN_SHIFT);
   return code;
}

pmu_icalusb_code dcl_pmu6235_get_icalusb(void)
{
   pmu_icalusb_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   code = (pmu_icalusb_code)((reg_val16 & ICALUSB_EN) >> ICALUSB_EN_SHIFT);
   return code;
}

pmu_icalsim2_code dcl_pmu6235_get_icalsim2(void)
{
   pmu_icalsim2_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONC);
   code = (pmu_icalsim2_code)((reg_val16 & ICALSIM2_EN) >> ICALSIM2_EN_SHIFT);
   return code;
}

pmu_vbt_volt dcl_pmu6235_get_vbt_sel(void)
{
   pmu_vbt_volt volt;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   volt = (pmu_vbt_volt)((reg_val16 & VBT_SEL) >> VBT_SEL_SHIFT);
   return volt;
}

pmu_vcam_d_volt dcl_pmu6235_get_vcam_d_sel(void)
{
   pmu_vcam_d_volt volt;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   volt = (pmu_vcam_d_volt)((reg_val16 & VCAM_D_SEL) >> VCAM_D_SEL_SHIFT);
   return volt;
}

pmu_vcam_a_volt dcl_pmu6235_get_vcam_a_sel(void)
{
   pmu_vcam_a_volt volt;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   volt = (pmu_vcam_a_volt)((reg_val16 & VCAM_A_SEL) >> VCAM_A_SEL_SHIFT);
   return volt;
}

DCL_UINT8 dcl_pmu6235_get_vfbadj(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CON9);
   value = (reg_val16 & VFBADJ) >> VFBADJ_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vfbadj_slp(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONB);
   value = (reg_val16 & VFBADJ_SLP) >> VFBADJ_SLP_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vbt_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   value = (reg_val16 & VBT_CAL) >> VBT_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vcam_d_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   value = (reg_val16 & VCAM_D_CAL) >> VCAM_D_CAL_SHIFT;
   return value;
}

DCL_UINT8 dcl_pmu6235_get_vcam_a_cal(void)
{
   DCL_UINT8   value;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   value = (reg_val16 & VCAM_A_CAL) >> VCAM_A_CAL_SHIFT;
   return value;
}

DCL_BOOL dcl_pmu6235_get_vbt_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   if (reg_val16 & VBT_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vcam_d_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   if (reg_val16 & VCAM_D_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

DCL_BOOL dcl_pmu6235_get_vcam_a_en(void)
{
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   if (reg_val16 & VCAM_A_EN)
      return DCL_TRUE;
   else
      return DCL_FALSE;
}

pmu_icalbt_code dcl_pmu6235_get_icalbt(void)
{
   pmu_icalbt_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_COND);
   code = (pmu_icalbt_code)((reg_val16 & ICALBT_EN) >> ICALBT_EN_SHIFT);
   return code;
}

pmu_icalcam_d_code dcl_pmu6235_get_icalcam_d(void)
{
   pmu_icalcam_d_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONE);
   code = (pmu_icalcam_d_code)((reg_val16 & ICALCAM_D_EN) >> ICALCAM_D_EN_SHIFT);
   return code;
}

pmu_icalcam_a_code dcl_pmu6235_get_icalcam_a(void)
{
   pmu_icalcam_a_code code;
   DCL_UINT16  reg_val16;

   reg_val16 = PMU_DRV_ReadReg16(PMIC_CONF);
   code = (pmu_icalcam_a_code)((reg_val16 & ICALCAM_A_EN) >> ICALCAM_A_EN_SHIFT);
   return code;
}

#endif


//CHR CURRENT
DCL_UINT32 cs_vth[]=
{
	PMU_CHARGE_CURRENT_50_00_MA,PMU_CHARGE_CURRENT_87_50_MA,
	PMU_CHARGE_CURRENT_150_00_MA,PMU_CHARGE_CURRENT_225_00_MA,
	PMU_CHARGE_CURRENT_300_00_MA,PMU_CHARGE_CURRENT_450_00_MA,
	PMU_CHARGE_CURRENT_650_00_MA,PMU_CHARGE_CURRENT_800_00_MA
};

DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_800000_V,PMU_VOLT_03_000000_V
};

DCL_UINT32 vbt_vosel[]=
{
	PMU_VOLT_02_800000_V,PMU_VOLT_03_000000_V
};

DCL_UINT32 vcama_vosel[]=
{
	PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_500000_V,PMU_VOLT_02_800000_V
};

DCL_UINT32 vcamd_vosel[]=
{
	PMU_VOLT_01_300000_V,PMU_VOLT_01_500000_V,PMU_VOLT_01_800000_V,PMU_VOLT_02_800000_V
};


PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{

	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),		vsim_vosel,	NULL,					GETARRNUM(vsim_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VBT),		vbt_vosel,		NULL,				GETARRNUM(vbt_vosel)	},	
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMA),		vcama_vosel,	NULL,				GETARRNUM(vcama_vosel)	},
	{ENC(LDO_BUCK_SET_VOLTAGE,VCAMD),		vcamd_vosel,	NULL,				GETARRNUM(vcamd_vosel)	},
	//CHR
	{ENC(CHR_SET_CHR_CURRENT,ALLMOD),				cs_vth,				NULL,				GETARRNUM(cs_vth)		}
};



DCL_STATUS dcl_pmu6235_Ldo_Set_Voltage(PMU_LDO_BUCK_LIST_ENUM mod,DCL_UINT16 regVal)
{
	switch(mod)
	{
		case VSIM:
		{
			dcl_pmu6235_set_vsim_sel(regVal);
		}
		break;	
		case VSIM2:
		{
			dcl_pmu6235_set_vsim2_sel(regVal);
		}
		break;	
		case VBT:
		{
			dcl_pmu6235_set_vbt_sel(regVal);
		}
		break;
		case VCAMA:
		{
			dcl_pmu6235_set_vcam_a_sel(regVal);
		}
		break;	
		case VCAMD:
		{
			dcl_pmu6235_set_vcam_d_sel(regVal);
		}
		break;			
		default:				
		return STATUS_UNSUPPORTED;
		break;			
	}	

	return STATUS_OK;
}


void dcl_pmu6235_set_vbat_cv_calibration(DCL_INT32 vbat)
{
	static kal_uint8  bmt_cv_calibration_by_adc_en=KAL_FALSE; 
	if (bmt_cv_calibration_by_adc_en==KAL_TRUE)
	{
		if(vbat > PMU_BMT_CV_TARGET_VOLTAGE && dcl_pmu6235_is_cv_mode()!=KAL_TRUE)
		{
			dcl_pmu6235_reduce_cv_level();
		}
		else
		{
			bmt_cv_calibration_by_adc_en=KAL_FALSE;
		}
	}

	if (vbat > PMU_BMT_CV_TARGET_VOLTAGE && bmt_cv_calibration_by_adc_en==KAL_FALSE && dcl_pmu6235_is_cv_mode()==KAL_FALSE)
	{
	   bmt_cv_calibration_by_adc_en=KAL_TRUE;	   
	}

}

extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6235_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_UINT32	val;
	
	switch(cmd)
	{
		//LDO/BUCK
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);

			switch(pLdoBuckCtrl->mod)
			{
				case VRF:
				{
					dcl_pmu6235_set_vrf(pLdoBuckCtrl->enable);
				}
				break;
				case VM:
				{
					dcl_pmu6235_set_vm_force(pLdoBuckCtrl->enable);
				}
				break;	
				case VSIM:
				{
					dcl_pmu6235_set_vsim(pLdoBuckCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmu6235_set_vsim2_en(pLdoBuckCtrl->enable);
				}
				break;				
				case VBT:
				{
					dcl_pmu6235_set_vbt_en(pLdoBuckCtrl->enable);
				}
				break;
				case VCAMA:
				{
					dcl_pmu6235_set_vcam_a_en(pLdoBuckCtrl->enable);
				}
				break;		
				case VCAMD:
				{
					dcl_pmu6235_set_vcam_d_en(pLdoBuckCtrl->enable);
				}
				break;						
				case VIBR:
				{
					dcl_pmu6235_set_vibr(pLdoBuckCtrl->enable);
				}
				break;					
				case VUSB:
				{
					dcl_pmu6235_set_vusb_en(pLdoBuckCtrl->enable);
				}
				break;			
				default:				
				return STATUS_UNSUPPORTED;
				break;			
			}
		}
		break;
		case LDO_BUCK_SET_VOLTAGE:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltage);			
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
			return dcl_pmu6235_Ldo_Set_Voltage(pLdoBuckCtrl->mod,regVal);
		}	
		break;			
		//CHR
		case CHR_SET_CHR_EN:
		{
			PMU_CTRL_CHR_SET_CHR_EN *pChrCtrl=&(data->rPMUChrSetChrEn);
			dcl_pmu6235_set_chron(pChrCtrl->enable);
		}
		break;		
		case CHR_GET_CHR_DET_STATUS:
		{
			PMU_CTRL_CHR_GET_CHR_DET_STATUS *pChrCtrl=&(data->rPMUChrGetChrDetStatus);
			pChrCtrl->enable=(DCL_BOOL)dcl_pmu6235_is_chr_det();
		}	
		break;			
		case CHR_GET_IS_BATTERY_ON:
		{	//always return TRUE (why?)
			PMU_CTRL_CHR_GET_IS_BATTERY_ON *pChrCtrl=&(data->rPMUChrGetIsBatteryOn);		
			pChrCtrl->enable=dcl_pmu6235_is_bat_on();
		}
		break;				
		case CHR_SET_ADC_MEASURE_EN:
		{
			PMU_CTRL_CHR_SET_ADC_MEASURE_EN *pChrCtrl=&(data->rPMUChrSetAdcMeasureEn);
			dcl_pmu6235_set_adc_meas_on(pChrCtrl->enable);
		}
		break;	
		case CHR_SET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_SET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrSetChrCurrent);	
			regVal=PMU_Parameter_to_Value(ENC(cmd,CHR),pChrCtrl->current);

			if (regVal==PARAMETER_UNKNOWN)
				ASSERT(0);

			dcl_pmu6235_set_chr_cur_level((pmu_chr_cur_level)regVal);
		}
		break;	
		case CHR_GET_CHR_CURRENT:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT *pChrCtrl=&(data->rPMUChrGetChrCurrent);
			regVal=dcl_pmu6235_get_chr_cur_level();
			pChrCtrl->current=PMU_Value_to_Parameter(ENC(CHR_SET_CHR_CURRENT,CHR),regVal);			
		}
		break;	
		case CHR_GET_CHR_CURRENT_LIST:
		{
			PMU_CTRL_CHR_GET_CHR_CURRENT_LIST *pChrCtrl=&(data->rPMUChrGetChrCurrentList);
			pChrCtrl->pCurrentList=cs_vth;
			pChrCtrl->number=GETARRNUM(cs_vth);
		}
		break;
		
		case CHR_SET_VBAT_CV_CALIBRATION:
		{
    		PMU_CTRL_CHR_SET_VBAT_CV_CALIBRATION *pChrCtrl = &(data->rPMUChrSetVbatCvCalibration);
			dcl_pmu6235_set_vbat_cv_calibration(pChrCtrl->vbat);
		}
		break;

		case MISC_SET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_SET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscSetRegisterValue);
                        if ((PMU_BASE+pChrCtrl->offset)>PMU_END)
                              return STATUS_UNSUPPORTED;
			PWIC_DRV_WriteReg16((PMU_BASE+pChrCtrl->offset), pChrCtrl->value);
		}
		break;	
		case MISC_GET_REGISTER_VALUE:
		{
			PMU_CTRL_MISC_GET_REGISTER_VALUE	*pChrCtrl=&(data->rPMUMiscGetRegisterValue);
                        if ((PMU_BASE+pChrCtrl->offset)>PMU_END)
                              return STATUS_UNSUPPORTED;
			pChrCtrl->value= PWIC_DRV_ReadReg16((PMU_BASE+pChrCtrl->offset));
		}
		break;					
		default:				
		return STATUS_UNSUPPORTED;
		break;
	}

	return STATUS_OK;

}

/*
* FUNCTION
*	dcl_pmu6235_init
*
* DESCRIPTION
*   MT6223 Power Management Uint(PMU) driver initial function
*
* CALLS
*
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*/
void dcl_pmu6235_init(void)
{
   extern void dcl_pmu6235_customization_init(void);

	pmu_control_handler=PMIC6235_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);

#if defined(PMIC_6238_REG_API)
	ECONumber = INT_ecoVersion();

	//pmuDeFeatureMax2ChrCurrent = DCL_FALSE;
	//
	//#if defined(MT6235PMU)
	//if ((DCL_UINT8)ECONumber < (DCL_UINT8)AL_E1)
	//{
	//	pmuDeFeatureMax2ChrCurrent = DCL_TRUE;
	//}
	//#endif // #if defined(MT6235PMU)

#endif //#if defined(PMIC_6238_REG_API)

   dcl_pmu6235_set_vrf_plnmos_dis(DCL_FALSE);
   dcl_pmu6235_set_cksel(CK_SEL_10KHZ);
#if defined(PMIC_6223_REG_API)
   dcl_pmu6235_reset_drv(DCL_FALSE);
#elif defined(PMIC_6238_REG_API)
   dcl_pmu6235_set_cv_rt(1);
   dcl_pmu6235_set_chr_cv_volt(VBG_VOLT_1_2_V);  //dcl_pmu6235_set_chr_cv_volt(VBG_VOLT_1_210_V);

   // Set sleep mode vcore voltage to 1.1V
   // MT6235, MT6238 vcore voltage under sleep mode can NOT be set to low
   // or vcore(Default 0.8V) becomres unstable, which will impact PWM duty.
   // And user may see blinking
   dcl_pmu6235_set_vfbadj_slp(8); // change 1. 1.2v

   dcl_pmu6235_set_vbt_sel(VBT_SEL_2_8);				// Add from Jimmy's suggestion
   dcl_pmu6235_set_vcam_d_sel(VCAM_D_SEL_1_8);		// Add from Jimmy's suggestion
   dcl_pmu6235_set_vcam_a_sel(VCAM_A_SEL_2_8);		// Add from Jimmy's suggestion
   dcl_pmu6235_set_vtcxo_on_sel(VTCXO_LDO_WITH_VTCXO_EN);	// Add from Jimmy's suggestion

   dcl_pmu6235_set_direct_ctrl_en(DCL_TRUE);		// Change2. Disable DVFS mode Add from Jimmy's request

   // For CR_768583 (38/35 all apply)
   // Set SRCLKEN mode only
   //dcl_pmu6235_set_auto_mode_en(0); //Change3



#endif
   pmu_customization_init();

#if defined(PMIC_6235_CV_TRIM_CALIBRATION)
   {
      DCL_UINT32 efuse_val;
      //efuse_val = *(volatile DCL_UINT32 *)(0x80000020);
      efuse_val = PMU_DRV_ReadReg32(EFUSE_base + 0x0020);
      if ( (efuse_val & 0x00080000) != 0) // Bit19
      {
         //efuse_val = *(volatile DCL_UINT32 *)(0x80000020);
         efuse_val = PMU_DRV_ReadReg32(EFUSE_base + 0x0020);
         // Bit[2..0]: CV_TUNE
         dcl_pmu6235_set_chr_cv_volt((pmu_vbg_volt)(efuse_val&0x00000007));
         // Bit[4..3]: CV_RT
         dcl_pmu6235_set_cv_rt((DCL_UINT8)((efuse_val&0x00000018) >> 3));
      }
   }
#endif // #if defined(PMIC_6235_CV_TRIM_CALIBRATION)

}


#endif /* defined(PMIC_6223_REG_API) || defined(PMIC_6238_REG_API) */


