/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_pmic_features.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for PMU feature options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef DCL_PMIC_FEATURES_H
#define DCL_PMIC_FEATURES_H

#ifndef DRV_PMIC_OFF

#if defined(MT6238PMU) || defined(MT6235PMU)
   #define PMIC_FIXED_3_ADC_CH
   #define PMIC_FIXED_CHR_EINT
   #define PMIC_6238_CUSTOMIZATION
   #define PMIC_6238_USB_FUNCTION

   #define PMIC_PMU_SERIES	
   /* Charger/USB detect through USB PHY */
   #define PMIC_CHR_USB_DETECT_THROUGH_USB
   #define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW // Charger det EINT interrupt LEVEL trigger active LOW
   #define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger

   #define PMIC_6235_CV_TRIM_CALIBRATION

   /* For internal use. */
   #define PMIC_6238_REG_API
   #define __CHARGER_SOFT_START__



   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif

#elif defined(MT6326_CCCI)
	/* Provide VSIM sel and enable interface */
	#define PMIC_VSIM_SEL_AND_ENABLE
	/* Provide VSIM enable interface */
	#define PMIC_VSIM_ENABLE
	/* Provide VSIM2 sel and enable interface */
	#define PMIC_VSIM2_SEL_AND_ENABLE
	/* Provide VSIM2 enable interface */
	#define PMIC_VSIM2_ENABLE
	/* Provide PMIC LOCK interface */
	#define PMIC_LOCK
	/* For internal use. */
	#define PMIC_6326_CCCI_REG_API

	#define PMIC_CHR_DETECT_NONE

	#ifndef PMIC_PRESENT
	#define PMIC_PRESENT
	#endif // #ifndef PMIC_PRESENT

#elif defined(MT6253PMU)

   #define PMIC_VSIM2_SEL
   #define PMIC_FIXED_3_ADC_CH
   #define PMIC_FIXED_CHR_EINT
   #define PMIC_6253_CUSTOMIZATION
   #define PMIC_6253_USB_FUNCTION


   #define PMIC_PMU_SERIES
   #define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW // Charger det EINT interrupt LEVEL trigger active LOW
   #define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
   #define PMIC_CHR_USB_DETECT_THROUGH_USB


   // PMIC support charge WDT functionality
   // BMT driver will refer the compile option to enable/disable BMT level WDT
   #define PMIC_CHARGE_WDT
   /* For internal use. */
   #define PMIC_6253_REG_API
   #define __CHARGER_SOFT_START__

   #define PMIC_6253_CV_TRIM_CALIBRATION



   #ifndef PMIC_PRESENT
   #define PMIC_PRESENT
   #endif

#define PMIC_FIXED_CHR_EINT
#if defined(PMIC_FIXED_CHR_EINT)
#define PMIC_FIXED_CHR_EINT_PIN      7
#endif // #if defined(PMIC_FIXED_CHR_EINT)

#elif defined(MT6236PMU)

    #define PMIC_6236_REG_API
    #define PMIC_6236_CUSTOMIZATION
    //#define PMIC_6238_USB_FUNCTION

    #define PMIC_PMU_SERIES
    #define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW // Charger det EINT interrupt LEVEL trigger active LOW
    #define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
    #define PMIC_CHR_USB_DETECT_THROUGH_USB	   /* Charger/USB detect through USB PHY */

    #define PMIC_6236_CV_TRIM_CALIBRATION

    #define PMIC_FIXED_3_ADC_CH
    //#define PMIC_FIXED_4_ADC_CH
    #define PMIC_FIXED_CHR_EINT
    #define PMIC_6236_USB_FUNCTION


    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT

#elif defined(MT6251PMU)

#define PMIC_6251_REG_API
#define PMIC_6251_CUSTOMIZATION
#define PMIC_SLIM_V3

#define PMIC_FIXED_3_ADC_CH
#define PMIC_FIXED_4_ADC_CH
#define PMIC_FIXED_CHR_EINT

#define PMIC_PMU_SERIES
#define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW // Charger det EINT interrupt LEVEL trigger active LOW
#define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
#define PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11

#ifndef PMIC_PRESENT
#define PMIC_PRESENT
#endif // #ifndef PMIC_PRESENT

#define PMIC_FIXED_CHR_EINT

/*
#define __DRV_UPMU_LDO_V1__
#define __DRV_UPMU_LDO_V1_STB_TD_AT_CON2_BIT6__
#define __DRV_UPMU_BUCK_V1__
#define __DRV_UPMU_KPLED_V1__
#define __DRV_UPMU_BC11_V1__
#define __DRV_UPMU_STRUP_V1__
#define __DRV_UPMU_BOOST_V1__
#define __DRV_UPMU_SPK_V1__
#define __DRV_UPMU_ISINK_V1__
*/
#define __DRV_UPMU_CHARGER_V1__
      #define __DRV_OTG_BVALID_DET_AT_CON5_BIT15__
      #define __DRV_VBAT_OV_EN_AT_CON3_BIT8__
      #define __DRV_BATON_EN_AT_CON3_BIT9__
      #define __DRV_OTG_BVALID_EN_AT_CON5_BIT12__
      #define __DRV_OTG_BVALID_DET_AT_CON5_BIT15__
      #define __DRV_CHR_WDT_CLEAR_WAIT_2MS__ // design limitation, need to wait for clock sync
      #define __DRV_VBAT_OV_VTH_CON3_3BIT_WIDTH_VTH2_AT_BIT12__
      #define __DRV_UPMU_BC11_V1__
        // Use USB module 1.5KOhm pull high resistor for group B identify process
        // Need to isolate USB DP/MP line to make 1.5KOhm resistor work
        // (1.5KOhm resistor has some enable dependency on isolation switch)
        //#define __DRV_BC11_USE_USB_100_K_RESISTOR_4_GROUP_B__
        // Use USB module provided USB line status check API
        // 1. USB module provide line status check API: 2.0V <-> 0.8V
        //    Higher than 2.0V ==> HIGH
        //    Lower than 0.8V ==> LOW
        // 2. PMU BC11 circuit provide 1.2V comparator
        //#define __DRV_BC11_USE_USB_LINE_STATUS_API__
        #define __DRV_UPMU_BC11_VSRC_EN_AT_TEST_CON1_BIT4__
#if defined(MT6251_S00)		
        #define __MT6251PMU_E1_BC11_VSRC_EN_AT_TEST_CON1_BIT4__
#endif //#if defined(MT6251_S00)	
        #define __DRV_CHR_FLAG_SEL_5BIT_WIDTH_SEL4_AT_BIT13__

#elif defined(MT6252PMU) || defined(MT6253ELPMU)
#define PMIC_6252_REG_API
#define PMIC_6252_CUSTOMIZATION

#define PMIC_FIXED_3_ADC_CH
#define PMIC_FIXED_CHR_EINT
#define PMIC_SLIM_V3

#define PMIC_PMU_SERIES
#define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW // Charger det EINT interrupt LEVEL trigger active HIGH
#define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
#define PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11

#ifndef PMIC_PRESENT
#define PMIC_PRESENT
#endif // #ifndef PMIC_PRESENT

#define __DRV_UPMU_BC11_V1__

#elif defined(MT6255PMU)
#define PMIC_6255_REG_API

    #define PMIC_FIXED_3_ADC_CH
    #define PMIC_FIXED_4_ADC_CH
    #define PMIC_FIXED_CHR_EINT
    #define PMIC_SLIM_V3    

#define PMIC_PMU_SERIES
#define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW// Charger det EINT interrupt LEVEL trigger active low
#define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
#define PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
#define __DRV_UPMU_BC11_V1__

#ifndef PMIC_PRESENT
#define PMIC_PRESENT
#endif // #ifndef PMIC_PRESENT


#elif defined(MT6256PMU)
#define PMIC_6256_REG_API
#define PMIC_6256_CUSTOMIZATION

    #define PMIC_FIXED_3_ADC_CH
    #define PMIC_FIXED_4_ADC_CH
    #define PMIC_FIXED_CHR_EINT
    #define PMIC_SLIM_V3    

#define PMIC_PMU_SERIES
#define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_LOW// Charger det EINT interrupt LEVEL trigger active low
#define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
#define PMIC_CHR_USB_DETECT_THROUGH_PMU_BC11
#define __DRV_UPMU_BC11_V1__

#ifndef PMIC_PRESENT
#define PMIC_PRESENT
#endif // #ifndef PMIC_PRESENT

#elif defined(MT6276PMU)

#define PMIC_6276_REG_API
#define PMIC_6276_CUSTOMIZATION


#define PMIC_PMU_SERIES
#define PMIC_CHR_USB_DET_EINT_LEVEL_ACTIVE_HIGH // Charger det EINT interrupt LEVEL trigger active HIGH
#define PMIC_CHR_USB_DET_EINT_LEVEL_TRIGGER // CHR/USB detection is LEVEL trigger
#define PMIC_CHR_USB_DETECT_THROUGH_USB

#ifndef PMIC_PRESENT
#define PMIC_PRESENT
#endif // #ifndef PMIC_PRESENT

#define PMIC_FIXED_3_ADC_CH
#define PMIC_FIXED_CHR_EINT
#if defined(PMIC_FIXED_CHR_EINT)
#define PMIC_FIXED_CHR_EINT_PIN      29
#endif // #if defined(PMIC_FIXED_CHR_EINT)

#define __DRV_UPMU_LPOSC_V1__
#define __DRV_UPMU_LDO_V1__
#define __DRV_UPMU_SHARE_LDO__
#if defined(MT6276_S00)
#define __MT6276PMU_E1_VSIM2_VOLSEL_ISSUE__
#endif //#if defined(MT6276_S00)
#define __DRV_UPMU_LDO_V1_STB_TD_AT_CON1_BIT0__
#define __DRV_UPMU_BUCK_V1__
#define __DRV_UPMU_VPA_V1__
#define __DRV_UPMU_KPLED_V1__
#define __DRV_UPMU_CHARGER_V1__
#define __DRV_OTG_BVALID_EN_AT_CON3_BIT13__
#define __DRV_BATON_EN_AT_CON3_BIT12__
#define __DRV_UPMU_BC11_V1__
#define __DRV_UPMU_BC11_MAPPING_V2__

#elif defined(MT6573PMU)

	#define PMIC_6573_REG_API
	
	#define __DRV_UPMU_BUCK_V1__
        #define __MT6573PMU_E1_VSIM2_VOLSEL_ISSUE__
	#define __DRV_UPMU_VPA_V1__

        #define PMIC_FIXED_3_ADC_CH
        #define PMIC_FIXED_CHR_EINT
	#define PMIC_CHR_DETECT_NONE

	#ifndef PMIC_PRESENT
	#define PMIC_PRESENT
	#endif // #ifndef PMIC_PRESENT

#elif defined(MT6326)
	#define PMIC_VSIM_SEL
	#define PMIC_VSIM2_SEL
	#define PMIC_AUDIO_AMP
	#define PMIC_6326_CUSTOMIZATION
	#define PMIC_6326_USB_FUNCTION
	#define PMIC_VCAMD_SEL
	#define PMIC_VCAMD_EN
	#define PMIC_VCAMA_SEL
	#define PMIC_VCAMA_EN

	#define PMIC_CHR_USB_DET_EINT_EDGE_TRIGGER // CHR/USB detection is edge trigger

	/* For internal use. */
	#define PMIC_6326_REG_API
	// PMIC support charge WDT functionality
	// BMT driver will refer the compile option to enable/disable BMT level WDT
	#define PMIC_CHARGE_WDT

	#define PMIC_6326_CV_TRIM_CALIBRATION

	#define PMIC_PMIC_SERIES
	/* Charger/USB detect through USB PHY */
	#define PMIC_CHR_USB_DETECT_THROUGH_USB

	#ifndef PMIC_PRESENT
	#define PMIC_PRESENT
	#endif // #ifndef PMIC_PRESENT

  #define __CHARGER_SOFT_START__

#elif defined(MT6329)
    #define PMIC_VSIM_SEL
    #define PMIC_VSIM2_SEL
    #define PMIC_AUDIO_AMP
    #define PMIC_6329_CUSTOMIZATION
    #define PMIC_6329_USB_FUNCTION
    #define PMIC_VCAMD_SEL
    #define PMIC_VCAMD_EN
    #define PMIC_VCAMA_SEL
    #define PMIC_VCAMA_EN

    #define PMIC_CHR_USB_DET_EINT_EDGE_TRIGGER // CHR/USB detection is edge trigger

    /* For internal use. */
    #define PMIC_6329_REG_API
    // PMIC support charge WDT functionality
    // BMT driver will refer the compile option to enable/disable BMT level WDT
    #define PMIC_CHARGE_WDT

    #define PMIC_6329_CV_TRIM_CALIBRATION

    #define PMIC_PMIC_SERIES
    /* Charger/USB detect through USB PHY */
    #define PMIC_CHR_USB_DETECT_THROUGH_USB

    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT

    #define __CHARGER_SOFT_START__

#elif defined(MT6327)
    #define PMIC_VSIM_SEL

    /* For internal use. */
    #define PMIC_6327_REG_API

    #define PMIC_PMIC_SERIES
    
    #define PMIC_CHR_DETECT_NONE

    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT

#elif defined(MT6320)

    /* For internal use. */
    #define PMIC_6320_REG_API

    #define PMIC_PMIC_SERIES
    
    #define PMIC_CHR_DETECT_NONE

    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT
    
#elif defined(MT6323)

    /* For internal use. */
    #define PMIC_6323_REG_API

    #define PMIC_PMIC_SERIES
    
    #define PMIC_CHR_DETECT_NONE

    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT

#elif defined(MT6325)
    /* For internal use. */
    #define PMIC_6325_REG_API

    #define PMIC_CHR_DETECT_NONE

    #ifndef PMIC_PRESENT
    #define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT        
#else

    #define PMIC_CHR_DETECT_NONE

#endif

#endif //  DRV_PMIC_OFF 
#endif // #ifndef DCL_PMIC_FEATURES_H
