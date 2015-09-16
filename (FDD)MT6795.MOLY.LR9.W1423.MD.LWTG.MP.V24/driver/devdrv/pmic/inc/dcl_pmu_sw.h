#include "dcl_pmic_features.h"
#include "dcl_pmu_common_sw.h"

#if defined(MT6339)
#include "dcl_pmic6339_sw.h"
#include "dcl_pmic6339_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6331) || defined(MT6332)
#include "dcl_pmic6331_sw.h"
#include "dcl_pmic6331_hw.h"
#include "dcl_pmic6332_sw.h"
#include "dcl_pmic6332_hw.h"
#include "dcl_pmu_hw.h"

#elif defined(MT6325)
#include "dcl_pmic6325_sw.h"
#include "dcl_pmic6325_hw.h"
#include "dcl_pmu_hw.h"

#else
typedef enum
{
FLAGS_LIST_ENUM_MAX
}PMU_FLAGS_LIST_ENUM;
#endif

