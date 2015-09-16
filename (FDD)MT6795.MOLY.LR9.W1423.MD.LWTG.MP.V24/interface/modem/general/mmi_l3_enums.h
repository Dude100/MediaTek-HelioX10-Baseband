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
 *
 * Filename:
 * ---------
 *   mmi_l3_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


#ifndef _MMI_L3_ENUMS_H
#define _MMI_L3_ENUMS_H

//#include "ps_public_enum.h"

/* Modified by: CH_Liang 2005.01.25 */
#ifndef MAX_EXT_PDP_CONTEXT
 // if the global compile option is not defined, use the local definition
 #error MAX_EXT_PDP_CONTEXT is not defined in make files
#endif
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

/* SM/SNDCP related enumerations */ 

/* Modified by: CH_Liang 2005.01.25 */
#define TOT_NSAPI     GPRS_MAX_PDP_SUPPORT 
/* End of Modification, 2005.03.19. Reviewed by: Joseph */

#define SM_REL97_QOS_LEN 3
#define QOS_LEN       11 /* 11 bytes is the Qos length */
#define SM_QOS_LEN_12 12 //__REL5__
#define SM_QOS_LEN_14 14//__REL5__
#define SM_QOS_LEN_WITH_EXT_MAX_RATE_DL 13
#define SM_QOS_LEN_WITH_EXT_GUARANTEE_RATE_DL 14
#define SM_QOS_LEN_WITH_EXT_MAX_RATE_UL 15 // __REL7_
#define SM_QOS_LEN_WITH_EXT_GUARANTEE_RATE_UL 16 // __REL7_
#define SM_CORRECT_QOS_LEN 16 // __REL7_

#define SM_QOS_IE_CONTENT_MAX_LEN 16 // until release 9
#define SM_TFT_IE_CONTENT_MAX_LEN 255 // until release 9
#define SM_PCO_IE_CONTENT_MAX_LEN 251 // until release 9

#define TCM_MAX_RECORDING_MSGS_NUM (GPRS_MAX_PDP_SUPPORT*2)

#define PS_TOT_NSAPI_NUM       11
#define PS_TOT_CONTEXT         PS_TOT_NSAPI_NUM

#define PS_MIN_CONTEXT_ID      1
#define PS_MAX_CONTEXT_ID      (1 + PS_TOT_CONTEXT -1)

typedef enum
{
     NO_NSAPI = 0X00,
     MIN_VALID_NSAPI = 0X05,
     MAX_VALID_NSAPI = MIN_VALID_NSAPI + GPRS_MAX_PDP_SUPPORT - 1,
     MAX_THEORETICAL_VALID_NSAPI = 0x0F // nsapi is from 5~15
}nsapi_session_enum;

typedef enum
{
/* Modified by: CH_Liang 2005.01.25 */
     TOT_MS_INITIATED_CONTEXT = GPRS_MAX_PDP_SUPPORT,
     TOT_NW_INITIATED_CONTEXT = GPRS_MAX_PDP_SUPPORT
/* End of Modification, 2005.03.19. Reviewed by: Joseph */
}max_contexts_enum;

/* Joseph:
 * This enum defination is used between 
 * TCM and SM and should SYNC with l4c_source_id_enum@l4c_common_enums.h
 */
typedef enum
{
   LMMI_ID,
   RMMI_ID,
   SAT_ID,
   INVALID_MMI_ID
} mmi_source_id_enum;


/* The following definitions have been packed in enumeration for future
 * increase of compression algorithms */

typedef enum
{
    SND_RFC_1144,
    SND_NUM_OF_PCOMP_ALGOS,
    SND_NO_PCOMP,
    SND_PCOMP_TOTAL_NUM
}snd_pcomp_algo_enum;

typedef enum
{
    SND_V42_BIS,
    SND_NUM_OF_DCOMP_ALGOS,
    SND_NO_DCOMP,
    SND_DCOMP_TOTAL_NUM
}snd_dcomp_algo_enum;

typedef enum
{
   PAP_AUTH,
   CHAP_AUTH
} pdp_auth_enum;

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

typedef enum {
    DATA_ACCT_CSD_PROF,			/* normal csd profile */
    DATA_ACCT_GPRS_PROF,		/* normal gprs profile */
    DATA_ACCT_SAT_PROF,	  		/* sat csd profile */
    DATA_ACCT_SPA_PROF			/* sim provisioning csd profile */
} data_account_profile_type_enum;

typedef enum
{
  SM_GPRS_AUTHENTICATION_PAP = 0,
  SM_GPRS_AUTHENTICATION_CHAP = 1,
  SM_GPRS_AUTHENTICATION_NONE =2,
  SM_GPRS_AUTHENTICATION_PAP_CHAP = 3,
  SM_GPRS_AUTHENTICATION_MAX_VALID_ENUM_VALUE = SM_GPRS_AUTHENTICATION_PAP_CHAP
}sm_gprs_authentication_type_enum;

#endif


