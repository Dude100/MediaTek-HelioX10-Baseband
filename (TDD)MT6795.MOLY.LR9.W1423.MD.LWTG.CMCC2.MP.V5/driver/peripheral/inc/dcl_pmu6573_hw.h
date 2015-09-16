


#ifndef __DCL_PMU6573_HW_H_STRUCT__
#define __DCL_PMU6573_HW_H_STRUCT__

#if defined(PMIC_6573_REG_API)


#define PMU_BASE        MIX_PMU_base
#define PMU_END         (PMU_BASE+0x1000)

///////////////////////////////////////////////////////////////////////////////
// LDO group
#define VRF_CON0  			(PMU_BASE+0x0700)
#define VTCXO_CON0  			(PMU_BASE+0x0710)
#define VSIM_CON0  			(PMU_BASE+0x0780)
#define VSIM2_CON0  			(PMU_BASE+0x0790)

//BUCK group
#define VRF18_CON0	 		(PMU_BASE+0x0960)
#define VPA_CON0		  	(PMU_BASE+0x0b00)



#endif //#if defined(PMIC_6573_REG_API)

#endif //#ifndef __DCL_PMU6573_HW_H_STRUCT__



