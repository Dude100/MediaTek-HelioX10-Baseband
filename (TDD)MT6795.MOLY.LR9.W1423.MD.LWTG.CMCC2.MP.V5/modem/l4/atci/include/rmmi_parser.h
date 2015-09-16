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
 * rmmi_parser.h
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for �K.
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

#ifndef _RMMI_PARSER_H
#define _RMMI_PARSER_H

#include "kal_general_types.h"

#define RMMI_HASH_TABLE_SPAN  5

#define RMMI_NUMBER_OFFSET_IN_PARSER_TABLE   26

#if defined (__CS_SERVICE__) && defined (__PS_SERVICE__)
/* GSM & GPRS */
#define RMMI_TOT_EXT_CMD 250


#elif defined (__PS_SERVICE__)  /* GPRS only */

#define RMMI_TOT_EXT_CMD 50


#else /* GSM only case */

#define RMMI_TOT_EXT_CMD 230    /* to be changed */


#endif 

#define RMMI_HASH_TABLE_ROW   37

#define RMMI_HASH_TABLE_COL   5

/*
* rmmi_extended_cmd_id_enum is used to count the number of supportted extended command
*/
typedef enum
{
    #define BASIC_CMD(AT_NAME, AT_HASH, FUNC, ENUM)
    #define EXTEND_CMD(AT_NAME, HASH1, HASH2, TEST_STRING, ENUM, FUNC) __##ENUM##__,
    #define CMD_ENUM(ENUM)
        #include "at_cmd.def"
        #include "at_custom_cmd_op01.h"
    #undef BASIC_CMD
    #undef EXTEND_CMD
    #undef CMD_ENUM

    RMMI_TOT_EXTEND_CMD
} rmmi_extended_cmd_id_enum;

/*
* rmmi_basic_cmd_id_enum is used to count the number of supportted basic command
*/
typedef enum
{    
    #define BASIC_CMD(AT_NAME, AT_HASH, FUNC, ENUM) __##ENUM##__,
    #define EXTEND_CMD(AT_NAME, HASH1, HASH2, TEST_STRING, ENUM, FUNC)
    #define CMD_ENUM(ENUM)
        #include "at_cmd.def"    
    #undef BASIC_CMD
    #undef EXTEND_CMD
    #undef CMD_ENUM
    
    RMMI_TOT_BASIC_CMD
} rmmi_basic_cmd_id_enum;

typedef enum
{
    #define BASIC_CMD(AT_NAME, AT_HASH, FUNC, ENUM)
    #define EXTEND_CMD(AT_NAME, HASH1, HASH2, TEST_STRING, ENUM, FUNC)
    #define CMD_ENUM(ENUM) ENUM,
        #include "at_cmd.def"    
        #include "at_custom_cmd_op01.h"
    #undef BASIC_CMD
    #undef EXTEND_CMD
    #undef CMD_ENUM
    
    RMMI_MAX_CMD_NUM,
/* please add other basic command enums in the following */
    RMMI_CMD_ATAMPC, // actually, its no use
    RMMI_CMD_ATAMPD, // actually, its no use
    RMMI_NO_CMD
}rmmi_cmd_id_enum;

extern kal_uint32 const rmmi_extended_cmd_table[RMMI_TOT_EXTEND_CMD][2]; 

extern kal_uint8 const rmmi_basic_cmd_table[RMMI_TOT_BASIC_CMD];

extern rmmi_cmd_id_enum const rmmi_extended_cmd_id_table[RMMI_TOT_EXTEND_CMD]; 

/* mtk00924 20050222 for __test_mode__ modification */
extern const kal_char *const rmmi_test_mode_string_table[RMMI_TOT_EXTEND_CMD]; 

/* mtk00924 20050222 for __test_mode__ modification */

#endif /* _RMMI_PARSER_H */

