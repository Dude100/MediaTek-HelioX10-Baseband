/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_misc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Misc Function
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FT_FNC_MISC_EX_H_
#define _FT_FNC_MISC_EX_H_
#include "kal_public_api.h"

#define FT_MISC_EX_DATA_FRAME_SIZE 1800

kal_uint32 FT_MiscExCheckFunctionSupported(kal_uint32 query_op_code);
void FT_MISC_EX_Operation(ilm_struct *ptrMsg);
void FT_Handle_CNF_From_NVRAM(ilm_struct* ptrMsgCnf);
extern kal_uint16 ft_gl_misc_ex_token;

enum META_BP_AREA_STATUS_E
{
	META_BP_AREA_STATUS_OK = 0
   ,META_BP_AREA_STATUS_EMPTY
   ,META_BP_AREA_STATUS_BROKEN
   ,META_BP_AREA_STATUS_NO_SYNC
   ,META_BP_AREA_STATUS_UNKNOWN

};

#endif  // end of #ifndef _FT_FNC_MISC_H_
