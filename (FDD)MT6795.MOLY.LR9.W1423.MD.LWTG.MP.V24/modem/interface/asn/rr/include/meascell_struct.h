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
 *  meascell_struct.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
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


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : meascell_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _MEASCELL_STRUCT_H
#define _MEASCELL_STRUCT_H

#include "rr_common_def.h"
#include "kal_general_types.h"

typedef struct {
    kal_uint8 gprsmin; /* GPRS RXLEV ACCESS  MIN*/
    kal_uint8 gprscch; /* GPRS MS TXPWR MAX CCH*/
} gprs_struct;

typedef struct {
    kal_uint8 gprsoffset; /* GPRS  TEMPORARY OFFSET*/
    kal_uint8 gprstime; /* GPRS PENALITY TIME*/
} gprs_one_struct;

typedef struct {
    kal_uint8 gprspriclass; /* GPRS PRIORITY CLASS*/
    kal_uint8 gprshcsthr; /* GPRS HCS THR*/
} hcs_struct;

typedef struct {
    kal_uint8 pbcchloc; /* PBCCH LOCATION*/
    kal_uint8 psiperiod; /* PSI  REPEAT PERIOD*/
} loc_per_struct;

typedef struct {
    ispresent loc_per_struct_choice_tag;
    union {
        kal_uint8 asiloc;
        loc_per_struct psiloc;
    } loc_per_struct_choice_value;
} si_pbcch_struct;

typedef struct {
    kal_uint8 cell_bar; /* CELL BAR ACCESS*/
    kal_uint8 exc_acc; /* EXC_ACCESS*/
    kal_uint8 same_cell; /* SAME RA AS SERVING CELL*/
    ispresent gprs_struct_choice_tag;
    union {
        gprs_struct pgprs;
    } gprs_struct_choice_value;
    ispresent gprs_ones_struct_choice_tag;
    union {
        gprs_one_struct pgprsone;
    } gprs_ones_struct_choice_value;
    ispresent gprs_resl_off_choice_tag;
    union {
        kal_uint8 pgprsresoffsset;
    } gprs_resl_off_choice_value;
    ispresent hcs_params_choice_tag;
    union {
        hcs_struct phcspara;
    } hcs_params_choice_value;
    ispresent si_pbcch_loc_choice_tag;
    union {
        si_pbcch_struct psipbcch;
    } si_pbcch_loc_choice_value;
} cell_selection_struct;
#endif 


