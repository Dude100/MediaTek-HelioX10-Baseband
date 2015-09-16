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

/*******************************************************************************
 *
 * Filename:
 * ---------
 * ostd_public.h
 *
 * Project:
 * --------
 *   MTK6276
 *
 * Description:
 * ------------
 *   This is the driver layer and corresponding Sleep Mode of ARM OS Timer HW
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CENTRALIZED_SLEEP_MANAGER__

#ifndef OSTD_PUBLIC_H
#define OSTD_PUBLIC_H

#include "kal_general_types.h"

typedef enum
{
   OSTD_SUCCESS_FALSE = 0, /*OSTD read back AFN/UFN and found that current value is <=2*/
   OSTD_SUCCESS_TRUE, /*OSTD has successfully set the AFN value into ARM OS Timer HW*/
   OSTD_TIME_OUT, /*OSTD failed to poll ready bit*/
   OSTD_FAIL, /* Other unknown fail reason */
   OSTD_RESULT_NUM
} OSTD_RESULT_E;

#if defined(MT6752)
    typedef enum
    {
       OSTD_INPUT_2G = 0, /* Input module is 2G */
       OSTD_INPUT_3G        /* Input module is 3G */
    } OSTD_INPUT_MODULE;
#endif

typedef struct _OSTD_FRM_INFO_T
{
   kal_uint32          curr_afn;            /* for OSTD to fill back current AFN value */
   kal_uint32          curr_ufn;            /* for OSTD to fill back current UFN value */
   kal_uint32          curr_afn_dly;            /* for OSTD to fill back current AFN_DLY value */
} OSTD_FRM_INFO_T;

typedef enum _OSTD_TIMER_TYPE_E
{
   OSTD_TDMA,
   OSTD_RTR
} OSTD_TIMER_TYPE_E;

/*****************************************************************************
* Functions provided by OSTD
*****************************************************************************/
extern void OSTD_CheckAfnUfn2TriggerISR(void);
/* For ARM Side OS Timer Upper Layer */
extern void OSTD_Init( void );
extern void OSTD_EnOST( kal_bool enable );
extern void OSTD_SetFrmDur( kal_uint16 frm_dur );
extern void OSTD_GetCurrFrm( OSTD_FRM_INFO_T *pFrm_Info );
extern OSTD_RESULT_E OSTD_SetAfn( kal_uint32 afn );
extern OSTD_RESULT_E OSTD_SetUfn( kal_uint32 ufn );
extern void OSTD_SetOstIntMask( kal_bool is_afn, kal_bool req_to_mask );

/* For ARM Side OS Timer Sleep Mode Manager */
extern kal_bool OSTD_CheckSleep( void );
extern kal_uint32 OSTD_CheckIsSleepLock(void);

extern void OSTD_EnableNIRQ( void );
extern void OSTD_DisableNIRQ( void );

extern kal_bool OSTD_Is_Slept(void);

/* For Modem Infinite Sleep */
extern kal_bool OSTD_Infinite_Sleep_Query(void);
extern OSTD_RESULT_E OSTD_MD_Infinite_Sleep(void);
extern OSTD_RESULT_E OSTD_Infinite_Sleep_Timer_CB(OSTD_TIMER_TYPE_E timer, kal_bool sta);

#endif

#endif /*__CENTRALIZED_SLEEP_MANAGER__*/

