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
 * smmm_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains enum definition between SM and MM. 
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

#ifndef _SMMM_ENUMS_H
#define _SMMM_ENUMS_H

/* Protocol Discriminator Values to be used */
#define SM_MSG                                0x0A
#define MAX_NPDU_LIST                           11
#define RECEIVE_NPDU_LIST_IEI                 0x26

// Carlson 2013.07.22 please check the gmmsm_cause_enum and the DC_Status together
// 1. For suspend due to CM/MM/GMM procedure, GMM will send GMMSM_SUSPEND_REQ to SM, using only one of the 2 causes: PS_SUSPEND_LR / PS_SUSPEND_CM
// 2. For Gemini suspend, GMM will not relay UNITDATA_REQ if other SIM is busy, and GMM will send UNITDATA_CNF.DC_Status_Gemini_Suspend_Discard to SM
// 3. For gmmsm_cause_enum: GMMSM_INSUFFICIENT_RESOURCE, it is only used in GMMSM_ATTACH_REJ due to Gemini
typedef enum
{
    NORM_DETACH,
    POWER_OFF_DETACH,
    REATTACH_REQ,
    SIM_REMOVAL,
    RAU_START,
    PS_SERVICE_SUSPEND,
    GMMSM_GMM_IN_INCOMPATIBLE_STATE,
    UN_SPECIFIED,
    DETACH_ONGOING, //erica 20070522
    PS_SUSPEND_LR,  /* PS is suspended because of LU, IMSI detach */
    PS_SUSPEND_CM   /* PS is suspended because of CM connection */
#ifdef __GEMINI__
    , GMMSM_INSUFFICIENT_RESOURCE  /* mtk00714: RR in suspend mode or the otherside is attached already */
#endif
    ,SETUP_RAB_START  /*ps is suspend because of SETUP RAB,this only used in GMM source code (won't be used in GMM-SM interface)*/
} gmmsm_cause_enum;

typedef enum
{
    MS_IDLE,
    MS_CONNECTED
} gmmsm_state_enum;
    
typedef enum
{
    NW_FOP_INFO_INVALID,    /* Field follow_on_status in gmmsm_attach_cnf shall not be referenced */
    NW_FOP_OFF,             /* NW did not specified follow-on-proceed in attach accept, 3G PS signaling connection shall not be reused */
    NW_FOP_ON               /* NW sepcified follow-on-proceed in attach accept, 3G PS signaling connection can be reused */
} gmmsm_fop_status_enum;

#endif

/* End of file smmm_interface.h */


