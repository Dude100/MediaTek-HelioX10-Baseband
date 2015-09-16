#ifndef __DRV_FEATURES_WDT_H__
#define __DRV_FEATURES_WDT_H__

#include "drv_features_chip_select.h"

/****************** WDT Feature Option List ************************
*	[H] means hardware feature option.  [S] means software feature option.
*1. [H]DRV_WDT_BASIC_REG
*2. [H]DRV_WDT_LENGTH_11BITS
*3. [H]DRV_WDT_SWRST
*4. [H]DRV_WDT_DSP
*5. [H]DRV_WDT_6573_REG
*6. [H]DRV_WDT_BASIC_REG
*****************************************************************/
/**************** WDT ******************/
#if defined(DRV_WDT_6205_SERIES)
   #define DRV_WDT_LIMIT_REG
   #define DRV_WDT_RESET_PKEY_RELEASE
   #define DRV_WDT_6205_CHECK_STAT
#elif defined(DRV_WDT_6205B_SERIES)
   #define DRV_WDT_LIMIT_REG
#elif defined(DRV_WDT_6208_SERIES)
   #define DRV_WDT_LIMIT_REG
   #define DRV_WDT_RESET_PKEY_RELEASE
#elif defined(DRV_WDT_6217_SERIES)
   #define DRV_WDT_BASIC_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
#elif defined(DRV_WDT_6276_SERIES)
   #define DRV_WDT_BASIC_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
   #define DRV_WDT_DSP
#elif defined(DRV_WDT_6573_SERIES)
   #define DRV_WDT_6573_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
   #define DRV_WDT_IRQ_MODE
#elif defined(DRV_WDT_6575_SERIES)
   #define DRV_WDT_6575_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
#elif defined(DRV_WDT_6280_SERIES)
   #define DRV_WDT_BASIC_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
   #define DRV_WDT_RETN_REG
   #if defined(__MODEM_CCCI_EXIST__)
   #define DRV_WDT_IRQ_MODE
   #endif

 #elif defined(DRV_WDT_6589_SERIES)
   #define DRV_WDT_BASIC_REG
   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
   #define DRV_WDT_RETN_REG	
   #define DRV_WDT_IRQ_MODE
   #define DRV_WDT_WAKE_UP_AP_SIDE_BEFORE_SEND_INT
   /*
   	  WDT send WDT reset interrupt to AP side while AP side in sleep,it will can not receive the 
   	  interrupt.So must send msg via CCCI to wake up AP side.the bug will be fix on MT658*,beacuse 
   	  WDT interrupt will be AP wake up source. 

	1.For USBlv2
	2. because add 32bit retention register,SW reset and restart register also from 16bit to 32bit

    */
   
#elif defined(DRV_WDT_6290_SERIES)
//   #define DRV_WDT_BASIC_REG
//   #define DRV_WDT_LENGTH_11BITS
   #define DRV_WDT_SWRST
//   #define DRV_WDT_DSP
   #if defined(__MODEM_CCCI_EXIST__)
   #define DRV_WDT_IRQ_MODE
   #endif
#elif defined(DRV_WDT_6595_SERIES)
   #define DRV_WDT_SWRST
   #define DRV_WDT_IRQ_MODE

#elif defined(DRV_WDT_6752_SERIES)
	#define DRV_WDT_BASIC_REG
	#define DRV_WDT_LENGTH_11BITS
	#define DRV_WDT_SWRST
	#define DRV_WDT_RETN_REG 
	#define DRV_WDT_IRQ_MODE
	#define DRV_WDT_32K_MODE   //from 6572,wdt can config the ways interrupt sendded out. 32K  clock, or bus clock.

#endif

#ifdef __MEUT__
#define DCL_WDT_INTERFACE
#endif

/* Features for WDT */
#if defined(DRV_WDT_BASIC_REG) && defined(DRV_WDT_LIMIT_REG)
#error "WDT feature conflict!!"
#endif

#endif
