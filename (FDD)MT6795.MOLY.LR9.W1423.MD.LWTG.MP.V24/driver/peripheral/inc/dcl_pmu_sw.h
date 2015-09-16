

#include "dcl_pmic_features.h"


#if defined(MT6276PMU)
#include "dcl_pmu6276_sw.h"
#include "dcl_pmu6276_hw.h"
#include "dcl_pmu_hw.h"


#elif defined(MT6238PMU) || defined(MT6235PMU)
#include "dcl_pmu6235_sw.h"
#include "dcl_pmu6235_hw.h"

#elif defined(MT6236PMU)
#include "dcl_pmu6236_sw.h"
#include "dcl_pmu6236_hw.h"

#elif defined(MT6251PMU)
#include "dcl_pmu6251_sw.h"
#include "dcl_pmu6251_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6253PMU)
#include "dcl_pmu6253_sw.h"
#include "dcl_pmu6253_hw.h"

#elif defined(MT6253ELPMU) || defined(MT6252PMU)
#include "dcl_pmu6252_sw.h"
#include "dcl_pmu6252_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6255PMU)
#include "dcl_pmu6255_sw.h"
#include "dcl_pmu6255_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6256PMU)
#include "dcl_pmu6256_sw.h"
#include "dcl_pmu6256_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6573PMU)
#include "dcl_pmu6573_sw.h"
#include "dcl_pmu6573_hw.h"
#include "dcl_pmu_hw.h"


#elif defined(MT6326)
#include "dcl_pmic6326_sw.h"
#include "dcl_pmic6326_hw.h"

#elif defined(MT6326_CCCI)
#include "dcl_pmic6326_ccci_sw.h"

#elif defined(MT6329)
#include "dcl_pmic6329_sw.h"
#include "dcl_pmic6329_hw.h"

#elif defined(MT6327)
#include "dcl_pmic6327_sw.h"
#include "dcl_pmic6327_hw.h"

#elif defined(MT6320)
#include "dcl_pmic6320_sw.h"
#include "dcl_pmic6320_hw.h"

#elif defined(MT6323)
#include "dcl_pmic6323_sw.h"
#include "dcl_pmic6323_hw.h"

#elif defined(MT6325)
#include "dcl_pmic6325_sw.h"
#include "dcl_pmic6325_hw.h"
#include "dcl_pmu_hw.h"
#endif //#if defined(MT6276PMU)

#include "dcl_pmu_common_sw.h"

#if defined(PMIC_FIXED_3_ADC_CH)
/* adc number for measuring VBAT/VISENSE/VCHARGER is fixed internally. */
#define PMIC_ADC_VCHARGER_CH_NUM     PMU_ADC_VCHARGER_CH_NUM
#define PMIC_ADC_VISENSE_CH_NUM      PMU_ADC_VISENSE_CH_NUM
#define PMIC_ADC_VBAT_CH_NUM         PMU_ADC_VBAT_CH_NUM
#if defined(PMIC_FIXED_4_ADC_CH)
#define PMIC_ADC_VBATTEMP_CH_NUM     PMU_ADC_VBATTEMP_CH_NUM
#endif // #if defined(PMIC_FIXED_4_ADC_CH)

/* adc factor for VBAT/VISENSE/VCHARGER */
#define PMIC_ADC_FACTOR_VBAT      PMU_ADC_FACTOR_VBAT
#define PMIC_ADC_FACTOR_VISENSE   PMU_ADC_FACTOR_VISENSE
#define PMIC_ADC_FACTOR_VCHARGER  PMU_ADC_FACTOR_VCHARGER
#if defined(PMIC_FIXED_4_ADC_CH)
#define PMIC_ADC_FACTOR_VBATTEMP  PMU_ADC_FACTOR_VBATTEMP
#endif // #if defined(PMIC_FIXED_4_ADC_CH)

#endif // #if defined(PMIC_FIXED_3_ADC_CH)

#if defined(PMIC_FIXED_CHR_EINT)
#define PMIC_CHR_EINT_PIN      PMU_CHR_EINT_PIN
#endif // #if defined(PMIC_FIXED_CHR_EINT)

#define DCL_PMU_DEV_MAGIC_NUM		(0x80000000)
#define DCL_PMU_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_PMU_DEV_MAGIC_NUM)


#ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__
#define PWIC_DRV_ClearBits16(addr, data)       DRV_ClearBits(addr,data)
#define PWIC_DRV_SetBits16(addr, data)         DRV_SetBits(addr,data)
#define PWIC_DRV_WriteReg16(addr, data)        DRV_WriteReg(addr, data)
#define PWIC_DRV_WriteReg32(addr, data)        DRV_WriteReg32(addr, data)
#define PWIC_DRV_ReadReg16(addr)               DRV_Reg(addr)
#define PWIC_DRV_ReadReg32(addr)               DRV_Reg32(addr)
#else // #ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__
#define PWIC_DRV_ClearBits16(addr,data)        DRV_DBG_ClearBits(addr,data)
#define PWIC_DRV_SetBits16(addr)               DRV_DBG_SetBits(addr)
#define PWIC_DRV_WriteReg16(addr, data)        DRV_DBG_WriteReg(addr, data)
#define PWIC_DRV_WriteReg32(addr, data)        DRV_DBG_WriteReg32(addr, data)
#define PWIC_DRV_ReadReg16(addr)               DRV_DBG_Reg(addr)
#define PWIC_DRV_ReadReg32(addr)               DRV_DBG_Reg32(addr)
#endif // #ifndef __DRV_DEBUG_PWIC_REG_READ_WRITE__

