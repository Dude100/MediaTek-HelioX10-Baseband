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
 *   emi_trace.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file for EMI DHL Trace.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(__EMI_DHL_TRACE_H__)
#define __EMI_DHL_TRACE_H__
/* ==================== */
/*	CONFIGURATIONS		*/
/* ==================== */
/* ==================== */
/*	INCLUDES			*/
/* ==================== */
#if !defined(GEN_FOR_PC)
#if defined (__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
	#include "dhl_trace.h"
	#include "emi_trace_gen.h"
#endif
#endif
/* ================ */
/*	DEFINITIONS		*/
/* ================ */
BEGIN_TRACE_MAP(MOD_EMI)
	TRC_MSG(EMI_PROFILING_MSG, "EMI_PROFILING [%d]: v1(%d), v2(%d), v3(%d)")
END_TRACE_MAP(MOD_EMI)

#if defined (__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
#define EMI_PROFILING_LOG(idx, var1, var2, var3) \
	do {\
		dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, EMI_PROFILING_MSG, idx, var1, var2, var3);\
	} while(0);
#else
#define EMI_PROFILING_LOG(idx, var1, var2, var3) \
	do {\
		dbg_print("EMI_PROFILING [%d]: v1(%d), v2(%d), v3(%d)\r\n", (idx), (var1), (var2), (var3));\
	} while(0);
#endif
/* ==================== */
/*	EXPORTED FUNCTIONS	*/
/* ==================== */
#endif  /* !__EMI_DHL_TRACE_H__ */
