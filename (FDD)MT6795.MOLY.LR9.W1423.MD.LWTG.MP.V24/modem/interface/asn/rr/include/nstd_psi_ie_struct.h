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
 *  nstd_psi_ie_struct.h
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
 *  FILENAME : nstd_psi_ie_struct.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifndef _NSTD_PSI_IE_STRUCT_H
#define _NSTD_PSI_IE_STRUCT_H

/* Suggest Add for RHR */
#include "meascell_struct.h"
#include "rr_common_def.h"
/* W1043 Suggest Add for RHR */
#include "kal_general_types.h"

typedef struct {
    kal_uint8 bsic; /* BSIC part of cell selection structure in PSI3 case*/
    cell_selection_struct cell_selection; /* cell selection struct*/
} remain_cell_para_struct;

typedef struct {
    kal_uint16 startfreq; /* START FREQUENCY*/
    kal_uint8 bsic; /* BSIC*/
    cell_selection_struct cell_selection; /* CELL SELECTION STRUCTURE*/
    kal_uint8 freq_diff_len; /* freq. diff length*/
    kal_uint8 no_freq_diff;
    kal_uint8 freq_diff_size;
    kal_uint8 *freq_diff; /* freq. diff*/
    kal_uint8 no_remain_cell_para;
    kal_uint8 remain_cell_para_size;
    remain_cell_para_struct *remain_cell_para; /* remaining cell params*/
} neighcellparastruct;

typedef struct {
    kal_uint8 same_ra_as_serv_cell;
    kal_uint8 cell_bar_access2;
    kal_uint8 bcc;
} remain_cell_para_struct2;

typedef struct {
    kal_uint16 startfreq; /* START FREQUENCY*/
    kal_uint8 rasercell; /* SAME RA SERVING CELL*/
    kal_uint8 cellbaracc; /* CELL BAR ACCESS*/
    kal_uint8 bcc; /* BCC*/
    kal_uint8 freq_diff_len; /* freq. diff length*/
    kal_uint8 no_freq_diff;
    kal_uint8 freq_diff_size;
    kal_uint8 *freq_diff; /* freq. diff*/
    kal_uint8 no_remain_cell_para2;
    kal_uint8 remain_cell_para2_size;
    remain_cell_para_struct2 *remain_cell_para2; /* remaining cell params*/
} structure2;

typedef struct {
    unsigned int no_secondstruct;
    unsigned int secondstruct_size;
    structure2 *secondstruct;
    kal_uint8 cellparaptr; /* CELL PARA PTR*/
} structure1;

typedef struct {
    ispresent ch232_tag;
    union {
        kal_uint8 ncc;
    } ch232_value;
    kal_uint8 excacc; /* EXC ACC*/
    ispresent ch233_tag;
    union {
        kal_uint8 rxlev;
    } ch233_value;
    ispresent ch234_tag;
    union {
        kal_uint8 mstxpwr;
    } ch234_value;
    ispresent ch235_tag;
    union {
        kal_uint8 priority;
    } ch235_value;
    ispresent ch236_tag;
    union {
        kal_uint8 hcthr;
    } ch236_value;
    ispresent ch237_tag;
    union {
        si_pbcch_struct si13pbcch;
    } ch237_value;
    kal_uint8 gprstempoff; /* GPRS TEMP OFFSET*/
    kal_uint8 gprspentime; /* GPRS PENALTY TIME*/
    kal_uint8 gprsoffset; /* GPRS RESELECT OFFSET*/
} neighparasetstruct;

typedef struct {
    kal_uint8 generation; /* GENERATION*/
    unsigned int no_firststruct;
    unsigned int firststruct_size;
    structure1 *firststruct;
    kal_uint8 max_cell_para_ptr;
    kal_uint8 no_neighparaset;
    kal_uint8 neighparaset_size;
    neighparasetstruct *neighparaset; /* NEIGHPARASET*/
} neighcellpara2struct;
#endif 


