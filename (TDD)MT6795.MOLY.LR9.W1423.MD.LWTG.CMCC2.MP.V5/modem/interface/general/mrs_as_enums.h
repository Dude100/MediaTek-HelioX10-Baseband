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
 *   mrs_as_enums.h
 *
 * Project:
 * --------
 *   Multimode
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *
 * ----------------------------------------------------------------------------
 * $Log:$
 *
 * removed!
 * removed!
 * 	.
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
 * Merging
 *  	
 * 	//MOLY/BRANCHES_LR9/LR9.W1349.MD.LFWG.MP/mcu/...
 *  	
 * 	to //MOLY/TRUNK/MOLY/mcu/...
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * 	.
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
 * [MT6290] CSFB_enhancements inject message extension.
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * MRS support MMDC.
 *
 * removed!
 * removed!
 * .
 * 
 ******************************************************************************/
#ifndef _MRS_AS_ENUMS_H
#define _MRS_AS_ENUMS_H

#include "global_def.h"
#include "l3_inc_enums.h"
#include "ps_public_enum.h"

typedef enum 
{
    INITIAL,
    SHARED,
    OCCUPIED
}lower_layer_availability_enum;

typedef enum 
{
    MRS_GSM_RAT,
    MRS_UMTS_RAT,
    MRS_LTE_RAT,
    MRS_NULL_RAT,
    MRS_RAT_NONE
}MRS_RAT_MODE_TYPE;

typedef enum 
{
    MRS_SIM1,
    MRS_SIM2,
    MRS_SIM3,
    MRS_SIM4
}MRS_SIM_INDEX;

#if defined(__GEMINI__) || defined(__SGLTE__)
#define MAX_GAS_CAPABILITY      MAX_GSM_NUM
#define MAX_UAS_CAPABILITY      MAX_UMTS_NUM
#define MAX_EAS_CAPABILITY      1
#define MAX_MM_CAPABILITY       MAX_GSM_NUM /* assume GSM number > UMTS number */
#define MAX_EMM_CAPABILITY      1
#else
#define MAX_GAS_CAPABILITY      1
#define MAX_UAS_CAPABILITY      1
#define MAX_EAS_CAPABILITY      1
#define MAX_MM_CAPABILITY       1
#define MAX_EMM_CAPABILITY      1
#endif

#define MAX_ASSOCIATION_LAI_CELL_INFO 12
#define MAX_ASSOCIATION_SAME_LAI_CELL_INFO 24

/* Already in l3_inc_enums.h
typedef enum 
{
    DEL_CSG,
    ADD_CSG
}csg_update_type_enum;
*/

typedef enum 
{
    NO_CHANGE,
    ALLOWED_CSG_LIST_CHANGED,
    OPERATOR_CSG_LIST_CHANGED,
    BOTH_CSG_LIST_CHANGED
}white_list_update_type;

/* Already in ps_public_enum.h
typedef enum 
{
    NOT_IN_WHITE_LIST,
    ALLOWED_CSG,
    OPERATOR_CSG,
    UNAUTH_OPERATOR_CSG
}csg_type_enum;
*/

typedef enum 
{
    SIM_NEW_INSERTED,
    SIM_FILE_UPDATED,
    AS_UPDATED
}csg_white_list_update_cause;

typedef enum 
{
    MRS_MAJOR_PROC, /* By active rat only */
    MRS_LIST_PROC,
    MRS_ACTIVE_RAT_CSG_AUTO_SEARCH,
    MRS_INACTIVE_RAT_CSG_AUTO_SEARCH,
    MRS_4G_NW_SEARCH_PROC,
    MRS_OCCUPY_NONE
}MRS_OCCUPY_PROCEDURE;

typedef enum
{
    CSFB_REDUCE_LAU = 1,
    CSFB_DEFER_SI13,
    CSFB_2G_AFR,
    CSFB_3G_AFR,
#ifdef __ECSFB__
    CSFB_2G_FDD_eCSFB,
    CSFB_3G_FDD_eCSFB,
    CSFB_2G_TDD_eCSFB,
    CSFB_3G_TDD_eCSFB,
#endif /* __ECSFB__ */
    CSFB_ENHANCEMENT_ITEM_END
}csfb_enhancement_enum;

typedef enum 
{
    BAND_39_DISABLE,
    BAND_39_ENABLE
}band_39_control_enum;

typedef enum
{
    BG_SEARCH_2G4_FDD,
    BG_SEARCH_3G4_FDD,
    BG_SEARCH_2G4_TDD,
    BG_SEARCH_3G4_TDD
}background_search_enum;
#endif /* _MRS_AS_ENUMS_H */
