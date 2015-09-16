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
 *   ebm_if.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for EMI BUS Monitor abstration interface.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __EBM_IF_H__
#define __EBM_IF_H__

/*******************************************************************************
 * Include chip dependent defines
 *******************************************************************************/


/*****************************************************************/

/**
  * Define this if we want to include those header that RHR suggested to add.
  */
#define RHR_SUGGEST_ADD

/**
  * Define this if we want to exclude those header that RHR suggested to add.
  */
//#define RHR_SUGGEST_REMOVE

/*****************************************************************/



#if defined(TK6280)
#include "ebm_tk6280_series.h"
#endif /* MT6276 */

#if defined(MT6280)
#include "ebm_mt6280_series.h"
#endif /* MT6276 */

#if defined(MT6290)
#include "ebm_mt6290_series.h"
#endif /* MT6290 */


/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* data structure EBM_LOG_T should be defined for each projects */


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

/*
 * EBM_INIT(): initialize
 */
#ifndef EBM_INIT
#error "EBM_INIT() should be implemented"
#endif  /* !EBM_INIT */

/*
 * EBM_START(): start to monitor
 */
#ifndef EBM_START
#error "EBM_START() should be implemented"
#endif  /* !EBM_START */

/*
 * EBM_PAUSE(): pause the monitor
 */
#ifndef EBM_PAUSE
#error "EBM_PAUSE() should be implemented"
#endif

/*
 * EBM_GET_MCU_IBUS_LOG(l): get log for MCU I_BUS
 * @l: pointer to EBM_LOG_T
 */
#ifndef EBM_GET_MCU_IBUS_LOG
#error "EBM_GET_MCU_IBUS_LOG() should be implemented"
#endif

/*
 * EBM_GET_MCU_DBUS_LOG(l): get log for MCU D_BUS
 * @l: pointer to EBM_LOG_T
 */
#ifndef EBM_GET_MCU_DBUS_LOG
#error "EBM_GET_MCU_DBUS_LOG() should be implemented"
#endif

/*
 * EBM_RESUME(): resume the monitor
 */
#ifndef EBM_RESUME
#error "EBM_RESUME() should be implemented"
#endif

/*
 * EBM_STOP(): stop monitor and clear counter
 */
#ifndef EBM_STOP
#error "EBM_STOP() should be implemented"
#endif

#endif  /* __EBM_IF_H__ */

