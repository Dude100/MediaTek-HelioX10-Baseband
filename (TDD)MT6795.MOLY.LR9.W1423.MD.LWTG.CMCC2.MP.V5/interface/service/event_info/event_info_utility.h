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

 /******************************************************************************
 * Filename:
 * ---------
 *   event_info_utility.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 *-----------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 20120222_MAUI_03136337_Adeline_MODEM_WARNING_MESSAGE.xls.
 *
 * 03 16 2012 jp.lien
 * removed!
 * 
 * For l1simulation, define MODEM_WARNING_MESSAGE to null op
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * 
 *
 ******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _EVENT_INFO_UTILITY_H
#define _EVENT_INFO_UTILITY_H

/*****************************
 Exported Function Prototypes
******************************/
#include "kal_general_types.h"
#include "kal_trace.h"

/* Disable EVENT_INFO for memory reduction */
#ifdef __CATCHER_EVENT_INFO__
extern void ps_event_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char *arg_type,...);
#elif !defined(__MINGW32__) && (defined(KAL_ON_OSCAR) || defined(L1_SIM))  /* DEBUG_KAL */
__inline void ps_event_trace(trace_class_enum trc_class, kal_uint32 msg_index, const kal_char* arg_type, ...)
{
    return ;
}
#else /* __CATCHER_EVENT_INFO__ */
#define ps_event_trace(...)
#endif

extern kal_char *md_strrchr(const kal_char *str, kal_char ch);
extern void assert_bypass_sys_trace(kal_char * filename, kal_uint32 line, ...);

#ifndef L1_SIM
#if !defined(MCD_DLL_EXPORT) /* skip in MCDDLL gen*/
#ifdef LOW_COST_SUPPORT
#define MODEM_WARNING_MESSAGE(expr, ...) do {if(!(expr)) {} } while (0)
#else
#ifdef __MODEM_DEBUG_ASSERT__
#define MODEM_WARNING_MESSAGE(expr, ...) do{if (!(expr)) {\
	                  assert_bypass_sys_trace((kal_char *)__FILE__,  __LINE__, ##__VA_ARGS__, NULL);\
                          ASSERT(0);}\
                          }while(0)
#else
#define MODEM_WARNING_MESSAGE(expr, ...) do{if (!(expr)) {\
                          assert_bypass_sys_trace((kal_char *)__FILE__,  __LINE__, ##__VA_ARGS__, NULL);}\
                          }while(0)
#endif /* __MODEM_DEBUG_ASSERT__ */
#endif /*LOW_COST_SUPPORT*/
#endif /*MCD_DLL_EXPORT*/
#else /*L1_SIM*/
#define MODEM_WARNING_MESSAGE
#endif /*L1_SIM*/

#endif /*_EVENT_INFO_UTILITY_H*/


