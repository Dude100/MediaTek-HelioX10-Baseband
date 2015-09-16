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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   global_def.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  global parameters definition
 *
 * Author:
 * -------
 * 
 *
 *==============================================================================
 * 				HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _GLBOAL_DEF_H
#define _GLBOAL_DEF_H

/***** global constant *****/

/* MAX_SIM_NUM */
#ifdef __GEMINI__
#ifdef GEMINI_PLUS
#define MAX_SIM_NUM (GEMINI_PLUS)
#else
#define MAX_SIM_NUM (2)
#endif /* GEMINI_PLUS */
#else
#ifdef __SGLTE__
#define MAX_SIM_NUM (2)
#else /* __SGLTE__ */
#define MAX_SIM_NUM (1)
#endif /* __SGLTE__ */
#endif /* __GEMINI__ */

/* MAX_GSM_NUM */
#ifdef __GEMINI_GSM__
#ifdef GEMINI_PLUS_GSM
#define MAX_GSM_NUM (GEMINI_PLUS_GSM)
#else
#define MAX_GSM_NUM (2)
#endif /* GEMINI_PLUS_GSM */
#else
#ifdef __SGLTE__
#define MAX_GSM_NUM (2)
#else
#define MAX_GSM_NUM (1)
#endif /* __SGLTE__ */
#endif /* __GEMINI_GSM__ */

/* MAX_UMTS_NUM */
#ifdef __GEMINI_WCDMA__
#ifdef GEMINI_PLUS_WCDMA
#define MAX_UMTS_NUM (GEMINI_PLUS_WCDMA)
#else
#define MAX_UMTS_NUM (2)
#endif /* GEMINI_PLUS_WCDMA */
#else
#define MAX_UMTS_NUM (1)
#endif /* __GEMINI_WCDMA__ */

/* MAX_LTE_NUM */
#ifdef __LTE_RAT__
#define MAX_LTE_NUM (1)
#endif /* __LTE_RAT__ */

/*weitang:only for SIM editor requested by moja*/
#ifdef __SGLTE_DSDS__
typedef enum{
	SIM_CARD_NUM = 2,
	SIM_CARD_1 = 1,
	SIM_CARD_2 = 3,
}sim_card_module_mapping;
#endif

/***** global structure *****/


#endif

