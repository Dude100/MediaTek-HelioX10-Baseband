

#ifndef __DCL_PMU_COMMON_HW_STRUCT__
#define __DCL_PMU_COMMON_HW_STRUCT__

#define CON0_OFFSET           0x00
#define CON1_OFFSET           0x04
#define CON2_OFFSET           0x08
#define CON3_OFFSET           0x0C
#define CON4_OFFSET           0x10
#define CON5_OFFSET           0x14
#define CON6_OFFSET           0x18
#define CON7_OFFSET           0x1C
#define CON8_OFFSET           0x20
#define CON9_OFFSET           0x24

#if defined(__DRV_UPMU_VPA_V1__)

//VPA CON0
#define VPA_EN_OFFSET CON0_OFFSET
#define VPA_EN_MASK  0x1000
#define VPA_EN_SHIFT 12

#define VPA_ANTI_RING_OFFSET CON0_OFFSET
#define VPA_ANTI_RING_MASK  0x0800
#define VPA_ANTI_RING_SHIFT 11

#define VPA_RC_OFFSET CON0_OFFSET
#define VPA_RC_MASK  0x000c
#define VPA_RC_SHIFT 2


//VPA CON2
#define VPA_VOTUNE0_OFFSET	CON2_OFFSET
#define VPA_VOTUNE0_MASK	0x001F
#define VPA_VOTUNE0_SHIFT	0

#define VPA_VOTUNE1_OFFSET	CON2_OFFSET
#define VPA_VOTUNE1_MASK	0x1F00
#define VPA_VOTUNE1_SHIFT	8

//VPA CON3
#define VPA_VOTUNE2_OFFSET	CON3_OFFSET
#define VPA_VOTUNE2_MASK	0x001F
#define VPA_VOTUNE2_SHIFT	0

#define VPA_VOTUNE3_OFFSET	CON3_OFFSET
#define VPA_VOTUNE3_MASK	0x1F00
#define VPA_VOTUNE3_SHIFT	8

//VPA CON4
#define VPA_VOTUNE4_OFFSET	CON4_OFFSET
#define VPA_VOTUNE4_MASK	0x001F
#define VPA_VOTUNE4_SHIFT	0

#define VPA_VOTUNE5_OFFSET	CON4_OFFSET
#define VPA_VOTUNE5_MASK	0x1F00
#define VPA_VOTUNE5_SHIFT	8

//VPA CON5
#define VPA_VOTUNE6_OFFSET	CON5_OFFSET
#define VPA_VOTUNE6_MASK	0x001F
#define VPA_VOTUNE6_SHIFT	0

#define VPA_VOTUNE7_OFFSET	CON5_OFFSET
#define VPA_VOTUNE7_MASK	0x1F00
#define VPA_VOTUNE7_SHIFT	8

#endif //#if defined(__DRV_UPMU_VPA_V1__)

#if defined(__DRV_UPMU_LPOSC_V1__)
#define LPOSC_CON0_OFFSET           0x00
#define LPOSC_CON1_OFFSET           0x04
#define LPOSC_CON2_OFFSET           0x08
#define LPOSC_CON3_OFFSET           0x0C
#define LPOSC_CON4_OFFSET           0x10

// LPOSC CON0
#define LPOSC_EN_MASK               0x1000
#define LPOSC_EN_SHIFT              12

//LPOSC CON1
#define LPOSC_FREQ_SET_MASK  0x00ff
#define LPOSC_FREQ_SET_SHIFT 0

#define LPOSC_BUCK_FREQ_SET_MASK  0x0700
#define LPOSC_BUCK_FREQ_SET_SHIFT 8

#define LPOSC_ACALI_EN_MASK  0x4000
#define LPOSC_ACALI_EN_SHIFT 14

#define LPOSC_FREQ_SET_MASK 0x00ff
#define LPOSC_FREQ_SET_SHIFT 0

// LPOSC CON2
#define LPOSC_FD_RES_MASK               0x0007
#define LPOSC_FD_RES_SHIFT              0

#define LPOSC_SSC_EN_MASK               0x0008
#define LPOSC_SSC_EN_SHIFT              3

#define LPOSC_SSC_MOD_AMP_MASK               0x0700
#define LPOSC_SSC_MOD_AMP_SHIFT              8

#define LPOSC_RG_BUCK_BOOST_EN_MASK               0x0800
#define LPOSC_RG_BUCK_BOOST_EN_SHIFT              11

#define LPOSC_SSC_CODE_DUR_MASK               0x7000
#define LPOSC_SSC_CODE_DUR_SHIFT              12

#define LPOSC_LPOSC_PG_EN_MASK               0x8000
#define LPOSC_LPOSC_PG_EN_SHIFT              15

//LPOSC CON4
#define LPOSC_SW_MODE_EN_MASK	0x1000
#define LPOSC_SW_MODE_EN_SHIFT	12

#endif //#if defined(__DRV_UPMU_BUCK_V1__)

#if defined(__DRV_UPMU_LDO_V1__)
#define LDO_CON0_OFFSET           0x00
#define LDO_CON1_OFFSET           0x04
#define LDO_CON2_OFFSET           0x08
#define LDO_CON3_OFFSET           0x0C
// LDO H/W register bitmap definition
  // LDO_XXX CON0
 #define LDO_EN_OFFSET          CON0_OFFSET
#define LDO_EN_MASK               0x0001
#define LDO_EN_SHIFT              0

#define LDO_ON_SEL_OFFSET		CON0_OFFSET
#define LDO_ON_SEL_MASK           0x0002
#define LDO_ON_SEL_SHIFT          1

#define LDO_RS_MASK               0x0004
#define LDO_RS_SHIFT              2

#define LDO_VOL_SEL_OFFSET		CON0_OFFSET
#define LDO_VOL_SEL_MASK          0x01F0
#define LDO_VOL_SEL_SHIFT         4

#define LDO_NDIS_EN_OFFSET		CON0_OFFSET
#define LDO_NDIS_EN_MASK          0x0400
#define LDO_NDIS_EN_SHIFT         10

#define LDO_STB_EN_OFFSET		CON0_OFFSET
#define LDO_STB_EN_MASK           0x0800
#define LDO_STB_EN_SHIFT          11

#define LDO_OC_AUTO_OFF_OFFSET CON0_OFFSET
#define LDO_OC_AUTO_OFF_MASK      0x1000
#define LDO_OC_AUTO_OFF_SHIFT     12

#define LDO_OCFB_EN_OFFSET		CON0_OFFSET
#define LDO_OCFB_EN_MASK          0x2000
#define LDO_OCFB_EN_SHIFT         13

#define LDO_OC_STATUS_MASK        0x4000
#define LDO_OC_STATUS_SHIFT       14

#define LDO_STATUS_MASK           0x8000
#define LDO_STATUS_SHIFT          15

  // LDO_XXX CON1
#if defined(__DRV_UPMU_LDO_V1_STB_TD_AT_CON1_BIT0__)
#define LDO_STB_TD_OFFSET		CON1_OFFSET
#define LDO_STB_TD_MASK           0x0003
#define LDO_STB_TD_SHIFT          0
#else
#define LDO_STB_TD_OFFSET		CON2_OFFSET
#define LDO_STB_TD_MASK           0x00c0
#define LDO_STB_TD_SHIFT          6
#endif // #if defined(__DRV_UPMU_LDO_V1_STB_TD_AT_CON1_BIT0__)

#define LDO_FORCE_LOW_MASK  0x0004
#define LDO_FORCE_LOW_SHIFT 2

#define LDO_CAL_OFFSET		CON1_OFFSET
#define LDO_CAL_MASK              0x01F0
#define LDO_CAL_SHIFT             4
#if defined(__DRV_UPMU_LDO_CAL_AS_SLEEP_VOLTAGE__)
#define LDO_VOL_SEL_SLEEP_MASK    0x01F0
#define LDO_VOL_SEL_SLEEP_SHIFT   4
#endif // #if defined(__DRV_UPMU_LDO_CAL_AS_SLEEP_VOLTAGE__)

  // LDO_XXX CON2
#define LDO_GP_LDOEN_MASK         0x0002
#define LDO_GP_LDOEN_SHIFT        1

#define LDO_OC_TD_OFFSET		CON2_OFFSET
#define LDO_OC_TD_MASK            0x0030
#define LDO_OC_TD_SHIFT           4
/*
#if defined(__DRV_UPMU_LDO_V1_STB_TD_AT_CON2_BIT6__)
#define LDO_STB_TD_OFFSET		CON2_OFFSET
#define LDO_STB_TD_MASK           0x00C0
#define LDO_STB_TD_SHIFT          6
#endif // #if defined(__DRV_UPMU_LDO_V1_STB_TD_AT_CON2_BIT6__)
*/

#define LDO_ICAL_EN_MASK          0x3000
#define LDO_ICAL_EN_SHIFT         12

  // LDO_XXX CON3
  // Only for VSIM/VSIM2 LDO
#define SIMIO_DRV_MASK            0x000E
#define SIMIO_DRV_SHIFT           1
#define SIM_BIAS_MASK             0x0030
#define SIM_BIAS_SHIFT            4
#define SIM_SRN_MASK              0x00C0
#define SIM_SRN_SHIFT             6
#define SIM_SRP_MASK              0x0300
#define SIM_SRP_SHIFT             8
#define SIM_CSTOP_MASK            0x0400    // Only for 6256 E2
#define SIM_CSTOP_SHIFT           10        // Only for 6256 E2

//////////////////// SIM control 
#if defined(__DRV_UPMU_LDO_SIM_SPECIFIC_CONFIG_FIELD_AT_CON2__)
#define LDO_SIM_GPIO_EN_OFFSET CON2_OFFSET
#define LDO_SIM_SIMIO_DRV_OFFSET CON2_OFFSET
#define LDO_SIM_BIAS_OFFSET CON2_OFFSET
#define LDO_SIM_SRN_OFFSET CON2_OFFSET
#define LDO_SIM_SRP_OFFSET CON2_OFFSET
#else
#define LDO_SIM_GPIO_EN_OFFSET CON3_OFFSET
#define LDO_SIM_SIMIO_DRV_OFFSET CON3_OFFSET
#define LDO_SIM_BIAS_OFFSET CON3_OFFSET
#define LDO_SIM_SRN_OFFSET CON3_OFFSET
#define LDO_SIM_SRP_OFFSET CON3_OFFSET
#define LDO_SIM_CSTOP_OFFSET CON3_OFFSET    // Only for 6256 E2
#endif //#if defined(__DRV_UPMU_LDO_SIM_SPECIFIC_CONFIG_FIELD_AT_CON2__)
#define LDO_SIM_GPIO_EN_MASK           0x0001
#define LDO_SIM_GPIO_EN_SHIFT          0

#define LDO_SIM_SIMIO_DRV_MASK           0x000E
#define LDO_SIM_SIMIO_DRV_SHIFT          1

#define LDO_SIM_BIAS_MASK           0x0030
#define LDO_SIM_BIAS_SHIFT          4

#define LDO_SIM_SRN_MASK           0x00C0
#define LDO_SIM_SRN_SHIFT          6

#define LDO_SIM_SRP_MASK           0x0300
#define LDO_SIM_SRP_SHIFT          8

#define LDO_SIM_CSTOP_MASK            0x0400    // Only for 6256 E2
#define LDO_SIM_CSTOP_SHIFT           10        // Only for 6256 E2
///////////////////// SIM control end


#endif // #if defined(__DRV_UPMU_LDO_V1__)

#if defined(__DRV_UPMU_BUCK_V1__)
#define BUCK_CON0_OFFSET          0x00
#define BUCK_CON1_OFFSET          0x04
#define BUCK_CON2_OFFSET          0x08
#define BUCK_CON3_OFFSET          0x0C
#define BUCK_CON4_OFFSET          0x10
#define BUCK_CON5_OFFSET          0x14
#define BUCK_CON6_OFFSET          0x18
// BUCK H/W register bitmap definition
  // BUCK_XXX CON0
#define BUCK_EN_OFFSET              CON0_OFFSET
#define BUCK_EN_MASK              0x0001
#define BUCK_EN_SHIFT             0

#define BUCK_ON_SEL_OFFSET		CON0_OFFSET
#define BUCK_ON_SEL_MASK          0x0002
#define BUCK_ON_SEL_SHIFT         1

#define BUCK_RS_OFFSET              CON0_OFFSET
#define BUCK_RS_MASK              0x0004
#define BUCK_RS_SHIFT             2

#define BUCK_ST_STR_MASK          0x0008
#define BUCK_ST_STR_SHIFT         3

#define BUCK_VFBADJ_OFFSET		CON0_OFFSET
#define BUCK_VFBADJ_MASK          0x01F0
#define BUCK_VFBADJ_SHIFT         4

#define BUCK_DIS_ANTIUNSH_MASK    0x0400
#define BUCK_DIS_ANTIUNSH_SHIFT   10

#define BUCK_STB_EN_MASK          0x0800
#define BUCK_STB_EN_SHIFT         11

#define BUCK_OC_AUTO_OFF_MASK     0x1000
#define BUCK_OC_AUTO_OFF_SHIFT    12

#define BUCK_OCFB_EN_OFFSET	CON0_OFFSET
#define BUCK_OCFB_EN_MASK         0x2000
#define BUCK_OCFB_EN_SHIFT        13

  // BUCK_XXX CON1
#define BUCK_MODESET_MASK         0x0001
#define BUCK_MODESET_SHIFT        0

#define BUCK_VFBADJ_SLEEP_OFFSET	CON1_OFFSET
#define BUCK_VFBADJ_SLEEP_MASK    0x01F0
#define BUCK_VFBADJ_SLEEP_SHIFT   4

#define BUCK_CLK_SRC_MASK         0x0400
#define BUCK_CLK_SRC_SHIFT        10

  // BUCK_XXX CON2
#define BUCK_CAL_MASK             0x01F0
#define BUCK_CAL_SHIFT            4

  // BUCK_XXX CON3
#define BUCK_OC_TD_OFFSET		CON3_OFFSET
#define BUCK_OC_TD_MASK           0x0030
#define BUCK_OC_TD_SHIFT          4

#define BUCK_STB_TD_OFFSET		CON3_OFFSET
#define BUCK_STB_TD_MASK          0x00C0
#define BUCK_STB_TD_SHIFT         6

#define BUCK_OC_THD_MASK          0x0300
#define BUCK_OC_THD_SHIFT         8

#define BUCK_OC_WND_MASK          0x0C00
#define BUCK_OC_WND_SHIFT         10

#define BUCK_ICAL_EN_OFFSET	CON3_OFFSET
#define BUCK_ICAL_EN_MASK         0x3000
#define BUCK_ICAL_EN_SHIFT        12

  // BUCK XXX CON4
#define BUCK_ADJCKSEL_OFFSET	CON4_OFFSET
#define BUCK_ADJCKSEL_MASK           0x0070
#define BULK_ADJCKSEL_SHIFT  4  

  // BUCK XXX CON5
#define BUCK_CSR_OFFSET       CON5_OFFSET
#define BUCK_CSR_MASK           0x000F
#define BULK_CSR_SHIFT  0

#define BUCK_RZSEL_OFFSET       CON5_OFFSET
#define BUCK_RZSEL_MASK           0x0070
#define BULK_RZSEL_SHIFT  4

#define BUCK_CSL_OFFSET	CON5_OFFSET
#define BUCK_CSL_MASK             0x0700
#define BUCK_CSL_SHIFT            8

#define BUCK_BURST_OFFSET		CON5_OFFSET
#define BUCK_BURST_MASK           0x3000
#define BUCK_BURST_SHIFT          12

#define BUCK_GMSEL_OFFSET		CON5_OFFSET
#define BUCK_GMSEL_MASK           0x4000
#define BUCK_GMSEL_SHIFT          14

#define BUCK_ZX_PDN_OFFSET	CON5_OFFSET
#define BUCK_ZX_PDN_MASK           0x8000
#define BUCK_ZX_PDN_SHIFT          15

  // BUCK XXX CON6
#define BUCK_CKS_PRG_OFFSET     CON6_OFFSET
#define BUCK_CKS_PRG_MASK           0x001f
#define BUCK_CKS_PRG_SHIFT          0


#endif // #if defined(__DRV_UPMU_BUCK_V1__)

#if defined(__DRV_UPMU_BOOST_V1__)
#define BOOST_CON0_OFFSET         0x00
#define BOOST_CON1_OFFSET         0x04
#define BOOST_CON2_OFFSET         0x08
#define BOOST_CON3_OFFSET         0x0C
#define BOOST_CON4_OFFSET         0x10
#define BOOST_CON5_OFFSET         0x14
#define BOOST_CON6_OFFSET         0x18
// BOOST H/W register bitmap definition
  // BOOST_XXX CON0
#define BOOST_EN_OFFSET		CON0_OFFSET
#define BOOST_EN_MASK             0x0001
#define BOOST_EN_SHIFT            0

#define BOOST_TYPE_MASK           0x0002
#define BOOST_TYPE_SHIFT          1

#define BOOST_MODE_MASK           0x0004
#define BOOST_MODE_SHIFT          2

#define BOOST_VRSEL_MASK          0x01F0
#define BOOST_VRSEL_SHIFT         4

#define BOOST_OC_AUTO_OFF_MASK    0x1000
#define BOOST_OC_AUTO_OFF_SHIFT   12

#define BOOST_OC_FLAG_MASK        0x4000
#define BOOST_OC_FLAG_SHIFT       14

  // BOOST_XXX CON1
#define BOOST_CL_OFFSET	 CON1_OFFSET
#define BOOST_CL_MASK             0x0007
#define BOOST_CL_SHIFT            0

#define BOOST_CS_MASK             0x0070
#define BOOST_CS_SHIFT            4

#define BOOST_RC_MASK             0x0700
#define BOOST_RC_SHIFT            8

#define BOOST_SS_MASK             0x7000
#define BOOST_SS_SHIFT            12

  // BOOST_XXX CON2
#define BOOST_CKSEL_MASK          0x0002
#define BOOST_CKSEL_SHIFT         1

#define BOOST_SR_PMOS_MASK        0x0070
#define BOOST_SR_PMOS_SHIFT       4

#define BOOST_SR_NMOS_MASK        0x0700
#define BOOST_SR_NMOS_SHIFT       8

#define BOOST_SLP_MASK            0xC000
#define BOOST_SLP_SHIFT           14

  // BOOST_XXX CON3
#define BOOST_CKS_PRG_MASK        0x003F
#define BOOST_CKS_PRG_SHIFT       0

  // BOOST_XXX CON4
#define BOOST_OC_THD_MASK         0x0030
#define BOOST_OC_THD_SHIFT        4

#define BOOST_OC_WND_MASK         0x00C0
#define BOOST_OC_WND_SHIFT        6

#define BOOST_CLK_CAL_OFFSET	CON4_OFFSET
#define BOOST_CLK_CAL_MASK        0x7000
#define BOOST_CLK_CAL_SHIFT       12

  // BOOST_XXX CON6
#define BOOST_HW_SEL_MASK         0x0001
#define BOOST_HW_SEL_SHIFT        0

#define BOOST_CC_MASK             0x0070
#define BOOST_CC_SHIFT            4

#endif // #if defined(__DRV_UPMU_BOOST_V1__)


#if defined(__DRV_UPMU_ISINK_V1__)
#define ISINK_CON0_OFFSET         0x00
#define ISINK_CON1_OFFSET         0x04
#define ISINK_CON2_OFFSET         0x08
// iSINK H/W register bitmap definition
  // ISINK_XXX CON0
#define ISINK_EN_OFFSET		CON0_OFFSET
#define ISINK_EN_MASK             0x0001
#define ISINK_EN_SHIFT            0

#define ISINK_MODE_OFFSET		CON0_OFFSET
#define ISINK_MODE_MASK           0x0002
#define ISINK_MODE_SHIFT          1

#define ISINK_STEP_OFFSET		CON0_OFFSET
#define ISINK_STEP_MASK           0x01F0
#define ISINK_STEP_SHIFT          4

#define ISINK_STATUS_MASK         0x8000
#define ISINK_STATUS_SHIFT        15

  // ISINK_XXX CON1
#define ISINK_VREF_CAL_MASK       0x1F00
#define ISINK_VREF_CAL_SHIFT      8

#endif // #if defined(__DRV_UPMU_ISINK_V1__)


#if defined(__DRV_UPMU_KPLED_V1__)
#define KPLED_CON0_OFFSET         0x00
#define KPLED_CON1_OFFSET         0x04
// KPLED H/W register bitmap definition
  // KPLED_XXX CON0
#define KPLED_EN_OFFSET		CON0_OFFSET
#define KPLED_EN_MASK             0x0001
#define KPLED_EN_SHIFT            0

#define KPLED_MODE_OFFSET		CON0_OFFSET
#define KPLED_MODE_MASK           0x0002
#define KPLED_MODE_SHIFT          1

#define KPLED_SEL_OFFSET		CON0_OFFSET
#define KPLED_SEL_MASK            0x0070
#define KPLED_SEL_SHIFT           4

#define KPLED_SFSTRT_C_OFFSET		CON0_OFFSET
#define KPLED_SFSTRT_C_MASK       0x0300
#define KPLED_SFSTRT_C_SHIFT      8

#define KPLED_SFSTRT_EN_OFFSET	CON0_OFFSET
#define KPLED_SFSTRT_EN_MASK      0x0400
#define KPLED_SFSTRT_EN_SHIFT     10

#define KPLED_STATUS_OFFSET	CON0_OFFSET
#define KPLED_STATUS_MASK         0x8000
#define KPLED_STATUS_SHIFT        15

#endif // #if defined(__DRV_UPMU_KPLED_V1__)


#if defined(__DRV_UPMU_SPK_V1__)
#define SPK_CON0_OFFSET           0x00
#define SPK_CON1_OFFSET           0x04
#define SPK_CON2_OFFSET           0x08
#define SPK_CON3_OFFSET           0x0C
#define SPK_CON4_OFFSET           0x10
#define SPK_CON5_OFFSET           0x14
#define SPK_CON6_OFFSET           0x18
#define SPK_CON7_OFFSET           0x1C
// SPK H/W register bitmap definition
  // SPK_XXX CON0
#define SPK_EN_MASK               0x0001
#define SPK_EN_SHIFT              0

#define SPK_RST_MASK              0x0002
#define SPK_RST_SHIFT             1

#define SPK_VOL_OFFSET		CON0_OFFSET
#define SPK_VOL_MASK              0x01F0
#define SPK_VOL_SHIFT             4

#define SPK_OC_AUTO_OFF_MASK      0x1000
#define SPK_OC_AUTO_OFF_SHIFT     12

#define SPK_OCFB_EN_MASK          0x2000
#define SPK_OCFB_EN_SHIFT         13

#define SPK_OC_FLAG_MASK          0x4000
#define SPK_OC_FLAG_SHIFT         14

  // SPK_XXX CON1
#define SPK_PFD_MODE_MASK         0x0001
#define SPK_PFD_MODE_SHIFT        0

#define SPK_CMODE_MASK            0x000C
#define SPK_CMODE_SHIFT           2

#define SPK_CCODE_MASK            0x00F0
#define SPK_CCODE_SHIFT           4

  // SPK_XXX CON2
#define SPK_OC_THD_MASK           0x0030
#define SPK_OC_THD_SHIFT          4

#define SPK_OC_WND_MASK           0x00C0
#define SPK_OC_WND_SHIFT          6

  // SPK_XXX CON3
#define SPK_OC_EN_OFFSET	CON3_OFFSET  
#define SPK_OC_EN_MASK            0x0400
#define SPK_OC_EN_SHIFT           10

#define SPK_OSC_ISEL_MASK         0x00C0
#define SPK_OSC_ISEL_SHIFT        6

  // SPK_XXX CON4
#define SPK_NG_DT_DLY_MASK         0x000f
#define SPK_NG_DT_DLY_SHIFT        0
#define SPK_OCN_BIAS_MASK            0x0700
#define SPK_OCN_BIAS_SHIFT           8
#define SPK_OCP_BIAS_MASK            0x7000
#define SPK_OCP_BIAS_SHIFT           12

  // SPK_XXX CON5
#define SPK_NG_SLEW_DLY_MASK            0x0007
#define SPK_NG_SLEW_DLY_SHIFT           0
#define SPK_PG_SLEW_DLY_MASK            0x0700
#define SPK_PG_SLEW_DLY_SHIFT           8
#define SPK_PG_SLEW_I_MASK            0x3000
#define SPK_PG_SLEW_I_SHIFT           12


  // SPK_XXX CON7
#define SPK_AB_OBIAS_MASK         0x0030
#define SPK_AB_OBIAS_SHIFT        4
#define SPK_AB_OC_EN_MASK         0x0100
#define SPK_AB_OC_EN_SHIFT        8
#define SPK_MODE_MASK             0x0001
#define SPK_MODE_SHIFT            0


#endif // #if defined(__DRV_UPMU_SPK_V1__)


#if defined(__DRV_UPMU_SPK_V2__)
#define SPK_CON0_OFFSET           0x00
#define SPK_CON1_OFFSET           0x04
// SPK H/W register bitmap definition
  // SPK_XXX CON0
#define SPK_EN_MASK               0x0001
#define SPK_EN_SHIFT              0

#define SPK_VOL_OFFSET		CON0_OFFSET
#define SPK_VOL_MASK              0x001E
#define SPK_VOL_SHIFT             1

#define SPK_OUT_FLOAT_B_MASK      0x0020
#define SPK_OUT_FLOAT_B_SHIFT     5

#define SPK_OC_EN_OFFSET	CON0_OFFSET  
#define SPK_OC_EN_MASK            0x0040
#define SPK_OC_EN_SHIFT           6

#define SPK_OBIAS_MASK            0x00C0
#define SPK_OBIAS_SHIFT           7

#define SPK_IN_TIE_HIGH_MASK      0x0400
#define SPK_IN_TIE_HIGH_SHIFT     10

#define SPK_IN_FLOAT_B_MASK       0x0800
#define SPK_IN_FLOAT_B_SHIFT      11

#define SPK_MINUS_GAIN_MASK       0x3000
#define SPK_MINUS_GAIN_SHIFT      12

  // SPK_XXX CON1
#define SPK_OC_THD_MASK           0x0003   // OC_TRG
#define SPK_OC_THD_SHIFT          0

#define SPK_OC_WND_MASK           0x000C
#define SPK_OC_WND_SHIFT          2

#define SPK_OC_AUTO_OFF_MASK      0x0040
#define SPK_OC_AUTO_OFF_SHIFT     6

#define SPK_OC_FLAG_MASK          0x8000
#define SPK_OC_FLAG_SHIFT         15

#endif // #if defined(__DRV_UPMU_SPK_V2__)


#if defined(__DRV_UPMU_CHARGER_V1__)
#define CHR_CON0_OFFSET           0x00
#define CHR_CON1_OFFSET           0x04
#define CHR_CON2_OFFSET           0x08
#define CHR_CON3_OFFSET           0x0C
#define CHR_CON4_OFFSET           0x10
#define CHR_CON5_OFFSET           0x14
#define CHR_CON6_OFFSET           0x18
#define CHR_CON7_OFFSET           0x1C
#define CHR_CON8_OFFSET           0x20
#define CHR_CON9_OFFSET           0x24
#define CHR_BC11_CON0_OFFSET      CHR_CON9_OFFSET
#define CHR_CON10_OFFSET          0x28
#define CHR_BC11_CON1_OFFSET      CHR_CON10_OFFSET
// CHARGER H/W register bitmap definition
  // CHR_XXX CON0
#define VCDT_LV_VTH_MASK          0x001F
#define VCDT_LV_VTH_SHIFT         0
#define VCDT_HV_VTH_MASK          0x00F0
#define VCDT_HV_VTH_SHIFT         4
#define VCDT_HV_EN_MASK           0x0100
#define VCDT_HV_EN_SHIFT          8
#define PCHR_AUTO_MASK            0x0400
#define PCHR_AUTO_SHIFT           10

#define CSDAC_EN_OFFSET		CON0_OFFSET
#define CSDAC_EN_MASK             0x0800
#define CSDAC_EN_SHIFT            11

#define CHR_EN_OFFSET		CON0_OFFSET
#define CHR_EN_MASK               0x1000
#define CHR_EN_SHIFT              12

#define CHRDET_OFFSET		CON0_OFFSET
#define CHRDET_MASK               0x2000
#define CHRDET_SHIFT              13

#define VCDT_LV_DET_MASK          0x4000
#define VCDT_LV_DET_SHIFT         14
#define VCDT_HV_DET_MASK          0x8000
#define VCDT_HV_DET_SHIFT         15
  // CHR_XXX CON1
#define VBAT_CV_VTH_OFFSET		CON1_OFFSET
#define VBAT_CV_VTH_MASK          0x001F
#define VBAT_CV_VTH_SHIFT         0

#define VBAT_CC_VTH_MASK          0x00C0
#define VBAT_CC_VTH_SHIFT         6

#define VBAT_CV_EN_OFFSET		CON1_OFFSET
#define VBAT_CV_EN_MASK           0x0100
#define VBAT_CV_EN_SHIFT          8

#define VBAT_CC_EN_MASK           0x0200
#define VBAT_CC_EN_SHIFT          9

#define VBAT_CV_DET_OFFSET		CON1_OFFSET
#define VBAT_CV_DET_MASK          0x4000
#define VBAT_CV_DET_SHIFT         14

#define VBAT_CC_DET_MASK          0x8000
#define VBAT_CC_DET_SHIFT         15
  // CHR_XXX CON2
#define PCHR_TOHTC_MASK           0x0007
#define PCHR_TOHTC_SHIFT          0
#define PCHR_TOLTC_MASK           0x0070
#define PCHR_TOLTC_SHIFT          4

#define CS_VTH_OFFSET		CON2_OFFSET
#define CS_VTH_MASK               0x0700
#define CS_VTH_SHIFT              8

#define CS_EN_MASK                0x1000
#define CS_EN_SHIFT               12
#if defined(__DRV_OTG_BVALID_DET_AT_CON2_BIT14__)
#define OTG_BVALID_DET_MASK       0x4000
#define OTG_BVALID_DET_SHIFT      14
#endif // #if defined(__DRV_OTG_BVALID_DET_AT_CON2_BIT14__)
#define CS_DET_MASK               0x8000
#define CS_DET_SHIFT              15
  // CHR_XXX CON3
#define CSDAC_STP_MASK            0x0003
#define CSDAC_STP_SHIFT           0
#if defined(__DRV_VBAT_OV_EN_AT_CON3_BIT3__)
#define VBAT_OV_EN_MASK           0x0008
#define VBAT_OV_EN_SHIFT          3
#endif // #if defined(__DRV_VBAT_OV_EN_AT_CON3_BIT3__)
#define CSDAC_DLY_MASK            0x0030
#define CSDAC_DLY_SHIFT           4
#define VBAT_OV_VTH_MASK          0x00C0
#define VBAT_OV_VTH_SHIFT         6
#if defined(__DRV_VBAT_OV_EN_AT_CON3_BIT8__)
#define VBAT_OV_EN_MASK           0x0100
#define VBAT_OV_EN_SHIFT          8
#endif // #if defined(__DRV_VBAT_OV_EN_AT_CON3_BIT8__)
#if defined(__DRV_BATON_EN_AT_CON3_BIT9__)
#define BATON_EN_MASK             0x0200
#define BATON_EN_SHIFT            9
#endif // #if defined(__DRV_BATON_EN_AT_CON3_BIT9__)

#define BATON_HT_EN_MASK		0x0400
#define BATON_HT_EN_SHIFT 		10

#if defined(__DRV_BATON_EN_AT_CON3_BIT12__)
#define BATON_EN_MASK             0x1000
#define BATON_EN_SHIFT            12
#endif // #if defined(__DRV_BATON_EN_AT_CON3_BIT12__)
#if defined(__DRV_OTG_BVALID_EN_AT_CON3_BIT13__)
#define OTG_BVALID_EN_OFFSET     CON3_OFFSET
#define OTG_BVALID_EN_MASK        0x2000
#define OTG_BVALID_EN_SHIFT       13
#endif // #if defined(__DRV_OTG_BVALID_EN_AT_CON3_BIT13__)
#define VBAT_OV_DET_MASK          0x4000
#define VBAT_OV_DET_SHIFT         14
#define BATON_UNDET_MASK          0x8000
#define BATON_UNDET_SHIFT         15
  // CHR_XXX CON4
#define PCHR_TEST_MASK            0x0001
#define PCHR_TEST_SHIFT           0
#define PCHR_CSDAC_TEST_MASK      0x0002
#define PCHR_CSDAC_TEST_SHIFT     1
#define PCHR_RST_MASK             0x0004
#define PCHR_RST_SHIFT            2
#define CSDAC_DAT_MASK            0xFF00
#define CSDAC_DAT_SHIFT           8
  // CHR_XXX CON5
#define PCHR_FLAG_SEL_MASK        0x000F
#define PCHR_FLAG_SEL_SHIFT       0
#define PCHR_FLAG_EN_MASK         0x0080
#define PCHR_FLAG_EN_SHIFT        7
#define PCHR_FLAG_OUT_MASK        0x0F00
#define PCHR_FLAG_OUT_SHIFT       8
#if defined(__DRV_OTG_BVALID_EN_AT_CON5_BIT12__)
#define OTG_BVALID_EN_OFFSET     CON5_OFFSET
#define OTG_BVALID_EN_MASK        0x1000
#define OTG_BVALID_EN_SHIFT       12
#endif // #if defined(__DRV_OTG_BVALID_EN_AT_CON5_BIT12__)
#if defined(__DRV_OTG_BVALID_DET_AT_CON5_BIT15__)
#define OTG_BVALID_DET_MASK       0x8000
#define OTG_BVALID_DET_SHIFT      15
#endif // #if defined(__DRV_OTG_BVALID_DET_AT_CON5_BIT15__)

  // CHR_XXX CON6

#define CHRWDT_TD_OFFSET		CON6_OFFSET 
#define CHRWDT_TD_MASK            0x000F  // TTTTTTTTT
#define CHRWDT_TD_SHIFT           0

#define CHRWDT_EN_OFFSET		CON6_OFFSET
#define CHRWDT_EN_MASK            0x0010
#define CHRWDT_EN_SHIFT           4

  // CHR_XXX CON7
#define CHRWDT_INT_EN_OFFSET	CON7_OFFSET  
#define CHRWDT_INT_EN_MASK        0x0001
#define CHRWDT_INT_EN_SHIFT       0

#define CHRWDT_FLAG_WR_MASK       0x0002
#define CHRWDT_FLAG_WR_SHIFT      1
#define CHRWDT_OUT_MASK           0x8000
#define CHRWDT_OTU_SHIFT          15
  // CHR_XXX CON8
#define BGR_RSEL_MASK             0x0007
#define BGR_RSEL_SHIFT            0
#define BGR_UNCHOP_PH_MASK        0x0010
#define BGR_UNCHOP_PH_SHIFT       4
#define BGR_UNCHOP_MASK           0x0020
#define BGR_UNCHOP_SHIFT          5
#define UVLO_VTHL_MASK            0x0300
#define UVLO_VTHL_SHIFT           8

#define ADC_EN_OFFSET		 CON8_OFFSET
#define ADC_EN_MASK               0x7000   // All ADC channels are enabled at same time
#define ADC_EN_SHIFT              12
  // CHR_XXX CON9 (CHR_BC11_CON0)

#if defined(__DRV_UPMU_BC11_V1__)

#if defined(__DRV_UPMU_BC11_MAPPING_V1__)
#define BC11_VREF_VTH_OFFSET     CON9_OFFSET
#define BC11_VREF_VTH_MASK        0x0001
#define BC11_VREF_VTH_SHIFT       0

#define BC11_CMP_EN_OFFSET       CON9_OFFSET
#define BC11_CMP_EN_MASK          0x0006
#define BC11_CMP_EN_SHIFT         1

#define BC11_IPD_EN_OFFSET      CON9_OFFSET
#define BC11_IPD_EN_MASK          0x0018
#define BC11_IPD_EN_SHIFT         3

#define BC11_IPU_EN_OFFSET	     CON9_OFFSET
#define BC11_IPU_EN_MASK          0x0060
#define BC11_IPU_EN_SHIFT         5

#define BC11_BIAS_EN_OFFSET	CON9_OFFSET
#define BC11_BIAS_EN_MASK         0x0080
#define BC11_BIAS_EN_SHIFT        7

#define BC11_BB_CTRL_OFFSET	CON9_OFFSET
#define BC11_BB_CTRL_MASK         0x0100
#define BC11_BB_CTRL_SHIFT        8

#define BC11_RST_OFFSET	  CON9_OFFSET
#define BC11_RST_MASK             0x0200
#define BC11_RST_SHIFT            9

#if defined(__MT6251PMU_E1_BC11_VSRC_EN_AT_TEST_CON1_BIT4__)
#define BC11_VSRC_EN_OFFSET     0x0504   //CHR_CON0+0x0504=TEST_CON1
#define BC11_VSRC_EN_MASK         0x0030
#define BC11_VSRC_EN_SHIFT        4
#else
#define BC11_VSRC_EN_OFFSET     CON9_OFFSET
#define BC11_VSRC_EN_MASK         0x0C00
#define BC11_VSRC_EN_SHIFT        10
#endif //#if defined(__MT6251PMU_E1_BC11_VSRC_EN_AT_TEST_CON1_BIT4__)

#define BC11_CMP_OUT_OFFSET     CON9_OFFSET
#define BC11_CMP_OUT_MASK         0x8000
#define BC11_CMP_OUT_SHIFT        15
#endif //#if defined(__DRV_UPMU_BC11_MAPPING_V1)

#if defined(__DRV_UPMU_BC11_MAPPING_V2__)
#define BC11_VREF_VTH_OFFSET    CHR_CON10_OFFSET
#define BC11_VREF_VTH_MASK        0x0040
#define BC11_VREF_VTH_SHIFT       6

#define BC11_CMP_EN_OFFSET	CHR_CON10_OFFSET
#define BC11_CMP_EN_MASK          0x0003
#define BC11_CMP_EN_SHIFT         0

#define BC11_IPD_EN_OFFSET	CHR_CON10_OFFSET
#define BC11_IPD_EN_MASK          0x000c
#define BC11_IPD_EN_SHIFT         2

#define BC11_IPU_EN_OFFSET		CHR_CON10_OFFSET
#define BC11_IPU_EN_MASK          0x0030
#define BC11_IPU_EN_SHIFT         4

#define BC11_BIAS_EN_OFFSET        CHR_CON10_OFFSET
#define BC11_BIAS_EN_MASK         0x0080
#define BC11_BIAS_EN_SHIFT        7

#define BC11_BB_CTRL_OFFSET     CHR_CON10_OFFSET
#define BC11_BB_CTRL_MASK         0x0100
#define BC11_BB_CTRL_SHIFT        8

#define BC11_RST_OFFSET	   CHR_CON9_OFFSET
#define BC11_RST_MASK             0x0100
#define BC11_RST_SHIFT            8

#define BC11_VSRC_EN_OFFSET     CHR_CON9_OFFSET
#define BC11_VSRC_EN_MASK         0x0003
#define BC11_VSRC_EN_SHIFT        0

#define BC11_CMP_OUT_OFFSET     CHR_CON10_OFFSET
#define BC11_CMP_OUT_MASK         0x0200
#define BC11_CMP_OUT_SHIFT        9

#endif //#if defined(__DRV_UPMU_BC11_MAPPING_V2__)
#endif // #if defined(__DRV_UPMU_BC11_V1__)


#endif // #if defined(__DRV_UPMU_CHARGER_V1__)

#if defined(__DRV_UPMU_STRUP_V1__)
#define STRUP_CON0_OFFSET         0x00

  // STRUP_XXX CON0
#define USBDL_EN_OFFSET	CON0_OFFSET
#define USBDL_EN_MASK             0x0010
#define USBDL_EN_SHIFT            4
#endif // #if defined(__DRV_UPMU_STRUP_V1__)





#endif //#define __DCL_PMU_COMMON_HW_STRUCT__

