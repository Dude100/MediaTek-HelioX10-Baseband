/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_misc_info.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Functons used to query information in misc info runtime data.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [K2 MD2] Add CCCI/CCIF new feature for K2 MD2
 *
 * removed!
 * removed!
 * [CCCI] Support CCCI MISC info.
 *
 ****************************************************************************/
#include "kal_public_api.h"
#include "ccci_misc_data.h"
#include "ccci_common.h"
#include "ccci_if.h"


/*************************************************************************
* FUNCTION
*  ccci_misc_info_feature_support
*
* DESCRIPTION
*  This function returns wheteher a feature in CCCI misc info is supported,
*  and copy the output data if required.
*
* PARAMETERS
*  op_id        -    Feature ID.
*  len          -    Length of output data
*  pReturn      -    Pointer to output.
*
* RETURNS
*  CCCI_INVALID_PARAM         - Invalid input parameter
*  CCCI_MISC_INFO_NOT_EXIST   - Feature doesn't exist on AP side.
*  CCCI_MISC_INFO_NOT_SUPPORT - Feature exists, but not supported.
*  CCCI_MISC_INFO_SUPPORT       - Feature is supported.
*  CCCI_MISC_INFO_PARTIALLY_SUPPORT - Feature is partially supported.
*
*************************************************************************/

kal_int32 ccci_misc_data_feature_support(kal_uint32 op_id, kal_uint32 len, void *pReturn)
{
    kal_uint32       ret;
    MODEM_RUNTIME_DATA  *pdata;
    kal_uint32       *ptr;

    if(op_id >= CCCI_MISC_INFO_QUERY_END || len > CCCI_MISC_INFO_DATA_SIZE)
        return CCCI_INVALID_PARAM;

    /* If caller request to copy data to a NULL pointer, return fail */
    if(len != 0 && !pReturn)
        return CCCI_INVALID_PARAM;


    /* Get corresponding misc info structure */
    pdata = ccci_get_share_data();

    /* AP doesn't fill the prefix, meaning this misc_info_t is not valid */
    if(pdata->MiscInfo.MiscPrefix != CCCI_MISC_INFO_STRUCT_PATTERN || pdata->MiscInfo.MiscPostfix != CCCI_MISC_INFO_STRUCT_PATTERN)
        return CCCI_MISC_INFO_NOT_EXIST;


    /* get return value from shared memory */
    ret = (pdata->MiscInfo.SupportMask >> (CCCI_MISC_INFO_RET_OFF(op_id))) & CCCI_MISC_INFO_RET_MASK;
    
    // feature data base address + each misc size
    ptr = &pdata->MiscInfo.element[0].Feature[0] + ((CCCI_MISC_INFO_DATA_SIZE  / sizeof(kal_int32)) * CCCI_MISC_INFO_INDEX_TRANSFORM(op_id));
    /* copy output parameter */
    if(len != 0 && CCCI_MISC_INFO_SUPPORT == ret)
    {
        kal_mem_cpy(pReturn, ptr, len);
    }

    return (kal_int32)ret;
}

