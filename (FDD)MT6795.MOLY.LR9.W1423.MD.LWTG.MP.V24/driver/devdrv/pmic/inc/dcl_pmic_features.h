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
 ****************************************************************************/

#ifndef DCL_PMIC_FEATURES_H
#define DCL_PMIC_FEATURES_H

#ifndef DRV_PMIC_OFF

#if defined(MT6339)
    #ifndef PMIC_PRESENT
	#define PMIC_PRESENT
    #endif // #ifndef PMIC_PRESENT

#elif defined(MT6331) || defined(MT6332) 
    /* For internal use. */
    #define PMIC_6331_REG_API
    #define PMIC_6332_REG_API

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

#endif // #if defined(MT6339)

#endif //  DRV_PMIC_OFF 

#endif // #ifndef DCL_PMIC_FEATURES_H
