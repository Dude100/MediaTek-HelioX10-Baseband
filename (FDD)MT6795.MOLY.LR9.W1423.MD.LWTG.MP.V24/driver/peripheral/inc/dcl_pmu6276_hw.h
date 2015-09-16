

#ifndef __DCL_PMU6276_HW_H_STRUCT__
#define __DCL_PMU6276_HW_H_STRUCT__

#if defined(PMIC_6276_REG_API)


#define PMU_BASE        MIX_PMU_base
#define PMU_END         (PMU_BASE+0x1000)

///////////////////////////////////////////////////////////////////////////////
// LDO group
#define VA12_CON0  			(PMU_BASE+0x0620)
#define VRTC_CON0  			(PMU_BASE+0x0628)
#define VMIC_CON0  			(PMU_BASE+0x0630)
#define VAUDN_CON0  		(PMU_BASE+0x0640)
#define VAUDP_CON0  		(PMU_BASE+0x0650)
#define VRF_CON0  			(PMU_BASE+0x0700)
#define VTCXO_CON0  			(PMU_BASE+0x0710)
#define VA25_CON0  			(PMU_BASE+0x0720)
#define VCAMA_CON0  		(PMU_BASE+0x0730)
#define VCAMD_CON0  		(PMU_BASE+0x0740)
#define VIO_CON0  			(PMU_BASE+0x0750)
#define VUSB_CON0  			(PMU_BASE+0x0760)
#define VBT_CON0  			(PMU_BASE+0x0770)
#define VSIM_CON0  			(PMU_BASE+0x0780)
#define VSIM2_CON0  			(PMU_BASE+0x0790)
#define VIBR_CON0  			(PMU_BASE+0x07b0)
#define VMC_CON0  			(PMU_BASE+0x07c0)
#define VCAMA2_CON0 		(PMU_BASE+0x07d0)
#define VCAMD2_CON0 		(PMU_BASE+0x07e0)
#define VFM_CON0		  	(PMU_BASE+0x07f0)
#define VM12_CON0	  		(PMU_BASE+0x0800)

//BUCK group
#define VCORE_CON0 			(PMU_BASE+0x0900)
#define VIO18_CON0 			(PMU_BASE+0x0920)
#define VPROC_CON0 			(PMU_BASE+0x0940)
#define VRF18_CON0	 		(PMU_BASE+0x0960)
#define VPA_CON0		  	(PMU_BASE+0x0b00)

//KPLED
#define KPLED_CON0  			(PMU_BASE+0x0c80)

//CHR
#define CHR_CON0 			(PMU_BASE+0x0a00)

#define PMUA_CON0	  		(PMU_BASE+0x0680)
#define OC_CON0	  			(PMU_BASE+0x0e00)
#define LPOSC_CON0 	 		(PMU_BASE+0x0100)
#define STRUP_CON0   		(PMU_BASE+0x0200)


#endif //#if defined(PMIC_6276_REG_API)

#endif //#ifndef __DCL_PMU6276_HW_H_STRUCT__

