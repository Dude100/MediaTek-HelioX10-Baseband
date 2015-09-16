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
 * Filename:
 * ---------
 *	mmcm_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for enum definition about mm and cm layer.
 *
 * Author:
 * -------
 * -------
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

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


 
#ifndef _MMCM_ENUMS_H
#define _MMCM_ENUMS_H


typedef enum
{
    GCC_PD              = 0x00, /* GROUP_CALL_CONTROL */
    BCC_PD              = 0x01, /* BROADCAST_CALL_CONTROL */
    PDSS1_PD            = 0x02,
    CC_PD               = 0x03, /* CALL_CONTROL */
                                 /* TRANSPARENT TRANSPORT PTOTOCOL*/
    GTTP_PD             = 0x04,
    MM_PD               = 0x05,
    RRM_PD              = 0x06,
    GMM_PD              = 0x08,
    SMS_PD              = 0x09,
    SM_PD               = 0x0A,
    CISS_PD             = 0x0B, /* NON_CALL_RLTD_SS_PD  */
    LOC_SERV_PD         = 0x0C,
    TC_PD               = 0x0F  
}pd_list_enum;

/* Skip Indicator Value */
#define SKIP_IND                0

typedef enum {
   EMLPP_NO_PRIORITY = 0,
   EMLPP_PRIORITY_4 = 1,
   EMLPP_PRIORITY_3 = 2,
   EMLPP_PRIORITY_2 = 3,
   EMLPP_PRIORITY_1 = 4,
   EMLPP_PRIORITY_0 = 5,
   EMLPP_PRIORITY_B = 6,
   EMLPP_PRIORITY_A = 7   
} emlpp_priority_enum;

typedef enum
{
    CM_BASIC_CALL      =   EMLPP_PRIORITY_3,
    CM_EMERGENCY_CALL  =   EMLPP_PRIORITY_0
}call_type_enum;

typedef enum
{
    TI_EXHAUSTED,
    CCBS_NOT_SUPPORTED 
}prompt_rej_cause;

typedef enum
{
    GMMCM_SUCCESS              = 0,
    GMMCM_DETACH               = 1,
    GMMCM_REATTACH_REQ         = 2, /* Reject cause #9, #10 */   
    GMMCM_T3317_EXPIRY         = 3,
    GMMCM_OTHER_REJ_CAUSE      = 4, /* Service reject with other causes */
    GMMCM_LOWER_LAYER_FAILURE  = 5, 
    GMMCM_INCOMPATIBLE_RAT     = 6, /* Receive MM_RATCM_REESTABLISH_RAB_IND in GSM RAT */
    GMMCM_INCOMPATIBLE_STATE   = 7, /* Limited, No service, Access class not granted */
    GMMCM_INTER_RAT_COLLISION  = 8,
    GMMCM_T3319_RUNNING        = 9,  /* __REL6__ */
    GMMCM_INCOMPATIBLE_NSAPI   = 10  /* GMM discover NSAPI inactive while dequeu service */
}gmmcm_result_enum;

typedef enum
{
    GMMCM_INTER_RAT            = 0,
    GMMCM_LOCAL_RELEASE        = 1,
}gmmcm_service_proc_cause_enum;

#endif


