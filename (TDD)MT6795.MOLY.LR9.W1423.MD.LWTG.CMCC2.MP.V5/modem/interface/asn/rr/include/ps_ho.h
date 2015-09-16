/**************************************************************************
 *                                                                        *
 *  Copyright (c) 2001 Sasken Communication Technologies Limited (SASKEN) *
 *  All Rights Reserved.                                                  *
 *                                                                        *
 *  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF SASKEN                 *
 *  The above copyright notice does not evidence any actual or intended   *
 *  publication of such source code.                                      *
 *                                                                        *
 **************************************************************************
 *
 *  FILE NAME:
 *  SYNOPSIS :
 *
 */

/* Evelyn 20090415: Merge R6 */

#ifndef _PS_HO_H_
#define _PS_HO_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifdef TEST_TOOL
#include "tt_defs.h"
#else
#include "kal_public_api.h"
#endif
#include "nstd_alloc_bitmap.h"

#include "nstd_pmo.h"
#include "gprs_rlcmac_common.h"
#include "gprs_rlcmac_dl.h"
#include "gprs_rlcmac_ul.h"
#include "gprs_mtbf.h"

#include "ps_ho_struct.h"
#include "ps_ho_pun.h"
#include "error_struct_enum.h"

#ifdef TOOL
#include "set_nstd_alloc_bitmap.h"
#include "get_nstd_alloc_bitmap.h"
#include "set_ps_ho.h"
#include "get_ps_ho.h"
#endif
#ifdef __cplusplus
}
#endif

#endif
