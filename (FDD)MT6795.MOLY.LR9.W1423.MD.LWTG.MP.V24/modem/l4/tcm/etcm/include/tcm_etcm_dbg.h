/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _TCM_ETCM_DBG_H
#define _TCM_ETCM_DBG_H

//mtk04121 - build code
#if 0
/* under construction !*/
/* under construction !*/
#endif
#include "tcm_trc.h"
#include "tcm_assert.h"

/*etcm headers */
#include "tcm_etcm_def.h"

#if __ETCM_UT__ && __LINUX_UT__

#define ETCM_TR3(...) \
    {                                   \
        printf("\n[TR3:%s.%d] ", __FUNCTION__, __LINE__ );      \
        printf(__VA_ARGS__);              \
        fflush(stdout);                    \
    }                                   \

#define ETCM_TR2(...) \
    {                                   \
        printf("\n[TR2:%s.%d] ", __FUNCTION__, __LINE__ );      \
        printf(__VA_ARGS__);              \
        fflush(stdout);                    \
    }                                   \

#define ETCM_TR_WAR(...) \
    {                                   \
        printf("\n[WAN:%s.%d] ", __FUNCTION__, __LINE__ );      \
        printf(__VA_ARGS__);              \
        fflush(stdout);                    \
    }                                   \

#define ETCM_TR_ERR(...) \
    {                                   \
        printf("\n[ERR:%s.%d] ", __FUNCTION__, __LINE__ );      \
        printf(__VA_ARGS__);              \
        fflush(stdout);                    \
    }                                   \

#define ETCM_TR_TODO(...) \
    {                                   \
        printf("\n[TODO:%s.%d] ", __FUNCTION__, __LINE__ );      \
        printf(__VA_ARGS__);              \
        fflush(stdout);                    \
    }                                   \


#define ETCM_TR_INF(a ...) \
    {                                   \
        fflush(stdout);                    \
    }                                   \

#define ETCM_FN_BEGIN(FN) \
    ETCM_TR3("=Enter= %s", # FN);
/*
    TCM_CONTROL_PLANE_FN_ENTRY_LOG                  \
       ( MOD_TCM,                                   \
         MMI_FN_ENTER_##FN##_SUBOP );   \
*/

#define ETCM_FN_END_M ETCM_FN_END(__FUNCTION__)

#define ETCM_FN_END(FN) \
    ETCM_TR3("=Exit = %s", # FN);
/*
  TCM_CONTROL_PLANE_FN_NORMAL_EXIT_LOG            \
     ( MOD_TCM,                                   \
       MMI_FN_EXIT_##FN##_SUBOP );    \
*/

#else /* ETCM_UT */

#define ETCM_LOG kal_brief_trace
#define ETCM_WARN(...) \
{ \
  ETCM_LOG(__VA_ARGS__);\
  ETCM_LOG(TCM_TRACE_INFO, TCM_TRACE_INFO_ETCM_CODE_LINE, __LINE__);\
}


#endif /* ETCM_UT */





#ifdef __MTK_TARGET__

#define ETCM_DBG_MODE_DO    if (0) {
#define ETCM_DBG_MODE_END   }
#define ETCM_ASSERT(c)   			{if (!(c)) ASSERT(c);				}
#define ETCM_D_ASSERT(c) 			{if (!(c)) DEBUG_ASSERT(c); }

#else

#define ETCM_DBG_MODE_DO    {
#define ETCM_DBG_MODE_END   }

//mtk04121 - build code
#if 1
#define ETCM_ASSERT(c)   {if (!(c)) etcm_ETCM_ASSERT(__FUNCTION__, __LINE__, #c); }
#define ETCM_D_ASSERT(c) {if (!(c)) etcm_ETCM_D_ASSERT(__FUNCTION__, __LINE__, #c); }
#else
/* under construction !*/
/* under construction !*/
#endif

void  etcm_ETCM_ASSERT(kal_uint8 *func, kal_uint16 line, kal_uint8 *conditon);
void  etcm_ETCM_D_ASSERT(kal_uint8 *func, kal_uint16 line, kal_uint8 *conditon);

#endif /*__MTK_TARGET__*/

#endif  /* _TCM_ETCM_H */
