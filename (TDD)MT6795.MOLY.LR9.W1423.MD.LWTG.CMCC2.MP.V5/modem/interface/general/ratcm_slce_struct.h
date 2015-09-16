/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *   ratcm_slce_struct.h
 *
 * Project:
 * --------
 *   MONZA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log:$
 * 
 * 09 28 2012 bao.han
 * removed!
 * .
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
 * Integration change.
 *
 * removed!
 * removed!
 * [RATCM][RHR]Check in ratcm file in uas\interface
 *
 * removed!
 * removed!
 * 
 *
 * removed!
 * removed!
 * Add copyright header.
 ****************************************************************************/

#ifndef _RATCM_SLCE_STRUCT_H
#define _RATCM_SLCE_STRUCT_H

/* MAUI_02828210, redundant header removal */
#include "ratcm_slce_enums.h"
//#include "kal_general_types.h"
//#include "app_ltlcom.h"  Elle20111011 - MSBB private header in BSP cleaning
#include "kal_public_api.h"//Austin: remove stack_ltlcom.h and replace to kal_public_api.h
#include "l3_inc_enums.h"
#include "uas_common_enums.h"

typedef kal_uint8 RAB_Identity;
typedef kal_uint8  NAS_Synchronisation_Indicator;

typedef struct
{
   LOCAL_PARA_HDR

   kal_uint8                    validity;
   
   RAB_Identity               rabId;  /* Range from 5~15 */
   channel_mode_enum          rab_mode;
   NAS_Synchronisation_Indicator    nasSyncIndicator;

} udc_rab_generic_ind_struct;

/************************/
/* UDC_RAB_ESTABLISHMENT */
/************************/
/* Description: These operations allow the transfer of control
   messages for radio access bearer establishment between non-access
   strata elements on each side of the access interface. The
   operations allow the IF side to initialise a radio access
   bearer. The operation also implies a request to the AS to allocate
   transmission resources to the radio access bearer.

   A radio access bearer identification uniquely identifies the radio
   access bearer. It is used in all primitives that pertain to the
   radio access bearer. It also serves as the binding to a NAS call.

   The Iu bearer identification identifies the Iu connection.  A
   quality of service request specifies the bearer characteristics
   that apply to the radio access bearer (ref: [23.110;6.2.2.3.4]).
*/
typedef udc_rab_generic_ind_struct ratcm_slce_rab_establishment_ind_struct ;

/************************/
/* UDC_RAB_MODIFY */
/************************/
/* Description: These operations allow the transfer of control
   messages for radio access bearer modification between non-access
   strata elements on each side of the access interface. The
   operations allow the IF side to modify a radio access
   bearer.
   A radio access bearer identification uniquely identifies the radio
   access bearer. It is used in all primitives that pertain to the
   radio access bearer. It also serves as the binding to a NAS call.
*/
typedef udc_rab_generic_ind_struct ratcm_slce_rab_modify_ind_struct ;

/******************/
/* UDC_RAB_RELEASE */
/******************/
/* Description: These operations allow the transfer of radio access
   bearer release messages between non-access strata elements on each
   side of the access interface. The operations allow IF side to
   release a radio access bearer (ref: [23.110;6.2.2.3.5]).

   This primitive indicates the release of the radio access bearer to upper layers. */

typedef struct
{
   LOCAL_PARA_HDR

   RAB_Identity               rabId;     /* Range from 5~15 */
   rab_release_cause_enum    rel_cause;
   
}ratcm_slce_rab_release_ind_struct ;


typedef struct
{
    LOCAL_PARA_HDR

    CRC_Append_Cmd   cmd;
}ratcm_slce_monitoring_close_loop_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

}ratcm_slce_monitoring_close_loop_cnf_struct;


/****************************************************************************
 * RATCM_SLCE_MONITORING_CLOSE_LOOP_IND
 *
 * Sent by SLCE to RATCM to indicate that the loop test mode 2 has been stopped by lower lower layer.
 *
 ****************************************************************************/
typedef struct
{
   LOCAL_PARA_HDR
   	
} ratcm_slce_monitoring_close_loop_ind_struct ;

#endif /* _RATCM_SLCE_STRUCT_H */
