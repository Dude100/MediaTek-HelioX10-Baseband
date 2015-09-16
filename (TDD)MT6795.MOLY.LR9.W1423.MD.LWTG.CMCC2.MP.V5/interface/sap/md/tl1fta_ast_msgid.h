/*****************************************************************************
 *
 * Filename:
 * ---------
 * tl1ft_ast_sap.h
 *
 * Project:
 * --------
 *   Astroanut
 *
 * Description:
 * ------------
 *   TL1_FT SAP
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "module_msg_range.h"

#ifndef _TL1FTA_MSG_H
#define _TL1FTA_MSG_H

#ifdef __BUILD_DOM__
enum{
#endif

MODULE_MSG_BEGIN( MSG_ID_TL1FTA_AST_MSG_CODE_BEGIN )
/* FTA -> L1 TASK */
MSG_ID_RFCAL_RESET_REQ = MSG_ID_TL1FTA_AST_MSG_CODE_BEGIN,

MSG_ID_RFCAL_CS_REQ,

MSG_ID_RFCAL_DCH_REQ,

MSG_ID_RFCAL_DCH_REL_REQ,

MSG_ID_RFCAL_GETINFO_REQ,

MSG_ID_RFCAL_ABBREG_REQ,

MSG_ID_NSFT_SET_PARA_REQ,

MSG_ID_RFTEST_RXTX_REQ,

MSG_ID_FHC_START_REQ,

MSG_ID_FHC_START_EX_REQ,

/* L1 TASK -> FTA */
MSG_ID_RFCAL_RESET_CNF,

MSG_ID_RFCAL_CS_IND,

MSG_ID_RFCAL_DCH_CNF,

MSG_ID_RFCAL_DCH_REL_CNF,

MSG_ID_RFCAL_GETINFO_CNF,

MSG_ID_RFCAL_ABBREG_IND,

MSG_ID_NSFT_SET_PARA_CNF,

MSG_ID_RFTEST_RXTX_CNF,

MSG_ID_FHC_START_CNF,

MSG_ID_FHC_FINISH_IND,

MSG_ID_FHC_FINISH_EX_IND,

MSG_ID_SLT_TEST_REQ,

#ifdef __BUILD_DOM__
};
#endif
MODULE_MSG_END( MSG_ID_TL1FTA_AST_MSG_CODE_TAIL )

#endif   //_TL1FTA_MSG_H
