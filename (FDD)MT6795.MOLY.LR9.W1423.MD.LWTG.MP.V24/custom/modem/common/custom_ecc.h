/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2009
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
 *   custom_ecc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file defines ECC function prototype.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
#ifndef _APP_ECC_H
#define _APP_ECC_H

#include "kal_general_types.h"

#define ECC_CUSTOM_MAX_BCD_LENGTH 3
#define ECC_CUSTOM_MAX_SIM_RECORD 5
#define ECC_CUSTOM_MAX_NW_RECORD 16
#define ECC_CUSTOM_MAX_NVRAM_RECORD 16

#define ECC_CUSTOM_DEFAULT_ECC_LENGTH 4 /* including 0x00 */

typedef enum
{
    ECC_SIM1_CALL, /* verifying SIM1 ECC for call */
    ECC_SIM2_CALL, /* verifying SIM2 ECC for call */
// Gemini+
    ECC_SIM3_CALL, /* verifying SIM3 ECC for call */
    ECC_SIM4_CALL, /* verifying SIM4 ECC for call */
    ECC_ALL_CALL,  /* verifying all ECC for call */
    ECC_SAT_CALL
} ecc_call_type_enum;

typedef enum
{
    ECC_SRC_SIM1,  /* update ECC number of SIM1 */
    ECC_SRC_SIM2,  /* update ECC number of SIM2 */
// Gemini+
    ECC_SRC_SIM3,  /* update ECC number of SIM3 */
    ECC_SRC_SIM4,  /* update ECC number of SIM4 */
    ECC_SRC_NW1,   /* update ECC number of NW1 */
    ECC_SRC_NW2,   /* update ECC number of NW2 */
// Gemini+
    ECC_SRC_NW3,   /* update ECC number of NW3 */
    ECC_SRC_NW4,   /* update ECC number of NW4 */
    ECC_SRC_NVRAM, /* update ECC number of NVRAM1 */
    ECC_SRC_PREDEFINED /* pre-defined ECC */
} ecc_src_type_enum;

typedef enum
{
    ECC_ENCODING_ANSII, /* ex: 112 => 0x31, 0x31, 0x32 */
    ECC_ENCODING_UCS2,  /* ex: 112 => 0x0031, 0x0031, 0x0032 */
    ECC_ENCODING_BCD    /* ex: 112 => 0x11, 0xF2 */
} ecc_num_encoding_enum;

typedef enum
{
    ECC_NOT_MATCH,
    ECC_PARTIALLY_MATCH,
    ECC_FULLY_MATCH
} ecc_verify_detail_enum;

typedef enum
{
    ECC_RESULT_OK,
    ECC_RESULT_INVALID_ENTRY = -1,
    ECC_RESULT_CAPACITY_EXCEEDED = -2
} ecc_update_result_enum;

typedef struct
{
    kal_uint8 ecc_number[(ECC_CUSTOM_MAX_BCD_LENGTH * 2 + 1) * 2 /*ENCODING_LENGTH*/]; /* in UCS2, max bytes: 14 */
#ifdef __REL5__
    /*
     * Emergency Service Category Value
     * Bit 1	Police
     * Bit 2	Ambulance
     * Bit 3	Fire Brigade
     * Bit 4	Marine Guard
     * Bit 5	Mountain Rescue
     * Bits 6,7,8 are spare and set to "0"
     */
    kal_uint8 ecc_category; /* supported in protocol but no icon in MMI */
#ifdef PLUTO_MMI
    kal_uint8 *ecc_display; /* supported in MMI only */
#endif
#endif /* __REL5__ */
    kal_bool ecc_always;    /* 1: ECC always, 0: ECC only when no SIM */
} ecc_record_struct;

extern kal_bool ecc_custom_verify_emergency_number(
                    kal_uint8 *number,                  /* number (with null terminator) to verify */
                    kal_uint8 num_length,               /* number length */
                    ecc_num_encoding_enum num_encoding, /* ANSII, UCS2, or BCD */
                    ecc_call_type_enum call_type,       /* SIM1, SIM2, or ALL */
                    kal_uint8 *ecc_category,            /* Returned ECC category */
                    kal_uint8 **ecc_display,            /* Returned ECC display name (in UCS2) */
                    kal_uint8 *verify_detail);          /* Returned ECC verify detail (only for idle) */

extern void ecc_custom_update_emergency_number(
                kal_uint8 *number,                      /* number (with null terminator) to configure */
                ecc_num_encoding_enum num_encoding,     /* ANSII, UCS2, or BCD */
                ecc_src_type_enum ecc_src,              /* SIM1, SIM2, NW1, NW2, or NVRAM */
                kal_uint8 ecc_category,                 /* ECC category */
                kal_uint8 *ecc_display,                 /* ECC display name (in UCS2) */
                kal_uint8 index,                        /* index, if total = 5, index = 1 ~ 5 */
                kal_uint8 total);                       /* total */

extern ecc_update_result_enum ecc_custom_update_emergency_number_ex(
                kal_uint8 *number,                      /* number (with null terminator) to configure */
                ecc_num_encoding_enum num_encoding,     /* ANSII, UCS2, or BCD */
                kal_uint8 ecc_category,                 /* ECC category */
                kal_bool ecc_always);                   /* 1: ECC always, 0: ECC only when no SIM */

extern void ecc_custom_get_first_2_default_num(
                kal_uint8 **ecc_num1,
                kal_uint8 **ecc_num2);

extern kal_bool ecc_custom_support_enhance_retry(void);

#endif /* _APP_ECC_H */

