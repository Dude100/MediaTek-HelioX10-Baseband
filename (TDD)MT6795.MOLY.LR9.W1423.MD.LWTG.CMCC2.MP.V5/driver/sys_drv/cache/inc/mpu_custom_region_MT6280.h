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
 *   mpu_custom_region_MT6280.h
 *
 * Project:
 * --------
 *   MOLY Software
 *
 * Description:
 * ------------
 *   Custom MPU region setting for MT6280
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
/****************************************************************************
 * DRIVER Note:
 * Custom Region Set by MpuPreInit and MPU_init are configured independently
 * The meaning of each parameter is also deffernet between these 2 settings
 * Please take extra attension to make correct configuration
 * 
 * [Custom Region in MpuPreInit]
 * Define with X-Macro: X_MPU_PREINIT_REGION
 * This X-Macro will gen function call to mpu_set_region_primitive()
 * The parameter mappings are:
 *    mpu_set_region_primitive(current_region++, START_ADDRESS, REGION_SIZE, REGION_ATTRIBUTE, ENABLE);
 * [*] The 1st parameter is auto increased, so it's not specified here.
 * [*] NAME - this is only for identification, you can set anything you like.
 * [*] REGION_SIZE - PLEASE BEAWARE, this parameter should use the enum RGN_SIZE_TYPE defined in mpu.h
 *
 * [Custom Region in MPU_Init]
 * Define with X-Macro: X_MPU_INIT_REGION
 * This X-Macro will gen function call to mpu_auto_make_region()
 * The parameter mappings are:
 *    mpu_auto_make_region(START_ADDRESS, REGION_SIZE, REGION_ATTRIBUTE, FIT); 
 * [*] For more information on START_ADDRESS, REGION_SIZE setting, please see mpu_auto_make_region() comment
 * [*] REGION_SIZE - this is the actually region size, not enum RGN_SIZE_TYPE
 *
 * [Other Note]
 * If custom region setting exceeds maximum MPU channel count, it should trigger a compile error on "dummy_var_for_check" array
 ****************************************************************************/
/*               (    NAME,            START_ADDRESS,  REGION_SIZE,     REGION_ATTRIBUTE,                ENABLE            )   */
X_MPU_PREINIT_REGION( MDSYS_APB_SO,    0x80000000,     RGN_SIZE_128MB,  MPU_SOM|MPU_PRW_URW,             1                 )
X_MPU_PREINIT_REGION( APSYS_APB_SO,    0xA0000000,     RGN_SIZE_128MB,  MPU_SOM|MPU_PRW_URW,             1                 )

/*               (    NAME,            START_ADDRESS,  REGION_SIZE, REGION_ATTRIBUTE,                    FIT LARGER/SMALLER)   */
X_MPU_INIT_REGION(    MDSYS_APB_SO,    0x80000000,     0x08000000,  MPU_SOM|MPU_PRW_URW,                 1                 )
#if defined(MT6280_S00) // MT6280 E1 
X_MPU_INIT_REGION(    MDSYS_APB_SD,    0x88000000,     0x02000000,  MPU_DEVICE_INS_OUTDEV|MPU_PRW_URW,   1                 )
#else // MT6280 E2 and later
X_MPU_INIT_REGION(    MDSYS_APB_SD,    0x88000000,     0x08000000,  MPU_DEVICE_INS_OUTDEV|MPU_PRW_URW,   1                 )
#endif
X_MPU_INIT_REGION(    APSYS_APB_SO,    0xA0000000,     0x08000000,  MPU_SOM|MPU_PRW_URW,                 1                 )
X_MPU_INIT_REGION(    APSYS_APB_SD,    0xA8000000,     0x08000000,  MPU_DEVICE_INS_OUTDEV|MPU_PRW_URW,   1                 )
X_MPU_INIT_REGION(    LMU,             0x60000000,     0x10000000,  MPU_SOM|MPU_PRW_URW,                 1                 )
 
