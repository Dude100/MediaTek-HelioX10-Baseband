#ifndef __spi_define_h__
#define __spi_define_h__

//#define SPI_DVT_LOAD
#define SPI_MAUI_LOAD

#if defined(SPI_DVT_LOAD)

/* DVT load */
#include <typedefs.h>

#define SPI_FAKE_KAL_SUPPORT
#define SPI_FAKE_DRV_SUPPORT

#define SPI_FULL_ISR_SUPPORT

#define ENABLE_UT 1

#include <spi_fake_reg_base.h>
#include <spi_fake_intrCtrl.h>

#elif defined(SPI_MAUI_LOAD)

/* MAUI load */
#define SPI_DRVPDN_SUPPORT

#define SPI_FULL_KAL_SUPPORT
#define SPI_FULL_DRV_SUPPORT
#define SPI_FULL_ISR_SUPPORT

#define SPI_HISR_SUPPORT


//////////////////RHR ADD//////////////////////////
#include "kal_public_defs.h"
///////////////////////////////////////////////////

//////////////////RHR-REMOVE//////////////////////
//#include <reg_base.h>
//#include <intrCtrl.h>
//#include <drv_comm.h>
//#include <drv_hisr.h>
//#include <spi.h>
//#include <spi_internal.h>
//#include <gpio_hw.h>
//#include <Stack_utils.h>
//#if defined(__MTK_TARGET__)
//#include <cache_sw.h>
//#include <init.h>
//#endif
//#include <kal_non_specific_general_types.h>
//#include <kal_release.h>
//#if defined(SPI_DRVPDN_SUPPORT)
//#include <drvpdn.h>
//#endif
//////////////////////////////////////////////////

/* for kal_get_current_thread_ID() */
//#include <rtfiles.h>
//#include <Fs_kal.h>
//extern kal_taskid kal_get_current_thread_ID(void);


#else
#error
#endif

#if defined(SPI_FULL_KAL_SUPPORT)
#elif defined(SPI_FAKE_KAL_SUPPORT)
#include <spi_fake_kal.h>
#else
#error
#endif

#if defined(SPI_FULL_DRV_SUPPORT)
#include <drv_features.h>
#elif defined(SPI_FAKE_DRV_SUPPORT)
#include <spi_fake_drv.h>
#else
#error
#endif


#endif
