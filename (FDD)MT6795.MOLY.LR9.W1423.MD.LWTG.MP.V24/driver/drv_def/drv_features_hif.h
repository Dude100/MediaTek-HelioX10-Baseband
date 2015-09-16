#ifndef __DRV_FEATURES_HIF_H__
#define __DRV_FEATURES_HIF_H__

#include "drv_features_chip_select.h"

#if defined(DRV_HIF_LEGACY_SERIES)
    #define DRV_HIF_SUPPORT
    #define DRV_HIF_LEGACY
#elif defined(DRV_HIF_V1_SERIES)
    #define DRV_HIF_SUPPORT
    #define DRV_HIF_V1
#elif defined(DRV_HIF_V2_SERIES)
    #define DRV_HIF_SUPPORT
    #define DRV_HIF_V2
#endif


#endif
