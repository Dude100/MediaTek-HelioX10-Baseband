#ifndef __DRV_FEATURES_PWM_H__
#define __DRV_FEATURES_PWM_H__

#include "drv_features_chip_select.h"

/****************** PWM Feature Option List ************************
*	[H] means hardware feature option.  [S] means software feature option.
*1. [H]DRV_PWM_PWM*.		--> this is old PWM feature option,chip support PWM *
*2.	[H]DRV_PWM_CLK_SEL  --> this is old PWM feature option, control register support clock select.
*3. [H]DRV_PWM_NONE_CLK -->	this due to some 23P have clock select problem
*4. [H]DRV_PWM_RWG      --> Random Wavefront Generate, this is new version of PWM.
*5. [H]DRV_PWM_RWG_MAIN_POWER_BEFORE_ACCESS --> hardware bug,Need to turn on PWM main power before access PWM module register
*6. [H]DRV_PWM_RWG_ONLY_ONE_POWER_BIT -->Indicate only one power down(clock gating) bit for all PWM channels
*****************************************************************/

/**************** PWM Feature Option******************/
#if defined(DRV_PWM_6205B_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_CLK_SEL
#elif defined(DRV_PWM_6223_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_CLK_SEL
   #define DRV_PWM_NONE_CLK
#elif defined(DRV_PWM_6238_SERIES)
   #define DRV_PWM_RWG
   #define DRV_PWM_RWG_MAIN_POWER_BEFORE_ACCESS
#elif defined(DRV_PWM_6253_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_PWM3
   #define DRV_PWM_CLK_SEL
#elif defined(DRV_PWM_6268A_SERIES)
   #define DRV_PWM_RWG
   #define DRV_PWM_RWG_MAIN_POWER_BEFORE_ACCESS
   #define DRV_PWM_RWG_ONLY_ONE_POWER_BIT
#elif defined(DRV_PWM_6216_AP_SERIES)
   #define DRV_PWM_RWG
#elif defined(DRV_PWM_6255_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_PWM3
   #define DRV_PWM_PWM4
   #define DRV_PWM_CLK_SEL
   #define DRV_ALERTER_NOT_EXIST
#elif defined(DRV_PWM_6575_SERIES)
   #define DRV_PWM_RWG
   #define DRV_PWM_OFF
   #define DRV_ALERTER_NOT_EXIST
#elif defined(DRV_PWM_6250_SERIES)
   #define DRV_PWM_PWM2
   #define DRV_PWM_PWM3
   #define DRV_PWM_CLK_SEL  
   #define DRV_ALERTER_NOT_EXIST
   #define DRV_PWM_2CH_ADDRESS
   #define DRV_PWM_ISINK_SOURCE
#elif defined(DRV_PWM_6280_SERIES)
    #define DRV_PWM_PWM1
    #define DRV_PWM_CLK_SEL
    #define DRV_ALERTER_NOT_EXIST 
#elif defined(DRV_PWM_6290_SERIES)    
    #define DRV_PWM_NOT_EXIST
    #define DRV_ALERTER_NOT_EXIST     
#else
	#define DRV_PWM_NOT_EXIST
	#define DRV_ALERTER_NOT_EXIST  
#endif


#if defined(__MEUT__) && defined(DRV_PWM_RWG)
#define DCL_RWG_INTERFACE
#endif
/**************** PWM Feature End******************/

#endif
