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
 *   ratcm_urlc_struct.h
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
 * 10 02 2012 ij.liao
 * removed!
 * 
 * removed!
 * removed!
 * header file.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * merge MSBB.
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

#ifndef _RATCM_URLC_STRUCT_H
#define _RATCM_URLC_STRUCT_H

#if defined(__UMTS_FDD_MODE__) 

/* MAUI_02828210, redundant header removal */
#include "uas_common_enums.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

typedef struct
{
    ExtendedRbId    RBId;
    kal_uint16             SDUSize;
}tRBLoopBackInfo;
# if 0
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
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_open_loop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8               noOfRBs;
    tRBLoopBackInfo  RBInfo[MAX_RB_LOOPED_BACK]; 
}ratcm_urlc_utest_close_loop_m1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_close_loop_m1_cnf_struct;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_close_loop_m2_cnf_struct;

#endif  /*__UMTS_FDD_MODE__*/



#if defined(__UMTS_TDD128_MODE__) 

/* MAUI_02828210, redundant header removal */
#include "uas_common_enums.h"
#include "kal_general_types.h"
#include "kal_public_api.h"

typedef struct
{
    ExtendedRbId    RBId;
    kal_uint16             SDUSize;
}tRBLoopBackInfo;
# if 0
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
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_open_loop_cnf_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_uint8               noOfRBs;
    tRBLoopBackInfo  RBInfo[MAX_RB_LOOPED_BACK]; 
}ratcm_urlc_utest_close_loop_m1_req_struct;

typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_close_loop_m1_cnf_struct;
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
typedef struct
{
    LOCAL_PARA_HDR

    kal_bool     result;
}ratcm_urlc_utest_close_loop_m2_cnf_struct;

#endif  /*__UMTS_TDD128_MODE__*/


#endif /* _RATCM_URLC_STRUCT_H */
