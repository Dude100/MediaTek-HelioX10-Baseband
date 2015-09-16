/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_auto_gen.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for generating NVRAM information.
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_AUTO_GEN_H
#define NVRAM_AUTO_GEN_H

//MSBB remove #include "kal_non_specific_general_types.h"

#ifndef __packed
#define __packed
#endif

#define COPYRIGHTS_HEADER "/*****************************************************************************\n"\
    "*  Copyright Statement:\n"\
    "*  --------------------\n"\
    "*  This software is protected by Copyright and the information contained\n"\
    "*  herein is confidential. The software may not be copied and the information\n"\
    "*  contained herein may not be used or disclosed except with the written\n"\
    "*  permission of MediaTek Inc. (C) 2008\n"\
    "*\n"\
    "*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES\n"\
    "*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS (\"MEDIATEK SOFTWARE\")\n"\
    "*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON\n"\
    "*  AN \"AS-IS\" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,\n"\
    "*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF\n"\
    "*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.\n"\
    "*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE\n"\
    "*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR\n"\
    "*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH\n"\
    "*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO\n"\
    "*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S\n"\
    "*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.\n"\
    "*\n"\
    "*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE\n"\
    "*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,\n"\
    "*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,\n"\
    "*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO\n"\
    "*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE. \n"\
    "*\n"\
    "*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE\n"\
    "*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF\n"\
    "*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND\n"\
    "*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER\n"\
    "*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).\n"\
    "*\n"\
    "*****************************************************************************/\n"\
    "\n"\
    "/*****************************************************************************\n"\
    " *\n"\
    " * Filename:\n"\
    " *   %s\n"\
    " *\n"\
    " * Project:\n"\
    " *   MAUI\n"\
    " *\n"\
    " * Description:\n"\
    " *   This file is intends for NVRAM auto gen statistics\n"\
    " *\n"\
    " * Author:\n"\
    " *   nvram auto gen !\n"\
    " * -------\n"\
    " *\n"\
    " *============================================================================\n"\
    " *\n"\
    " * This file is automatically generated by the nvram gen procedure\n"\
    " *\n"\
    " ****************************************************************************/\n"

#define NVRAM_FUNCTION_HEAD \
"/*****************************************************************************\n"\
"* FUNCTION\n"\
"*  %s\n"\
"* DESCRIPTION\n"\
"*  used to restore mmi_cache_%s to default value\n"\
"* PARAMETERS\n"\
"*  buffer    [IN]\n"\
"* RETURNS\n"\
"*  none\n"\
"*****************************************************************************/\n"


#define NVRAM_RESTORE_FUNCTION_NAME \
"void nvram_restore_%s_cache(nvram_reset_category_enum category, nvram_app_id_enum app_id, kal_uint8 *buffer)\n"\
"{\n"\
"    /*----------------------------------------------------------------*/\n"\
"    /* Code Body                                                      */\n"\
"    /*----------------------------------------------------------------*/\n"\
"    switch(app_id)\n"\
"    {\n"

#define NVRAM_RESTORE_FUNCTION_BREAK    \
"\n"\
"            if (category == NVRAM_RESET_CERTAIN)\n"\
"            {\n"\
"                break;\n"\
"            }\n"

#define NVRAM_RESTORE_FUNCTION_TAIL \
"        default:\n"\
"        break;\n"\
"    }\n"\
"}\n"\
"\n"\
"\n"

#define NVRAM_AUTO_GEN_COMMENT  \
"            /* Reset: %s */\n"\

#define R_F_DOM_COMMENT    \
"/* %s system settings */\n"

#define R_F_DOM_ENUM_BEGIN  \
"typedef enum\n"\
"{\n"

#define R_F_DOM_CONTENT_ID     \
"    %s,    "\

#define R_F_DOM_CONTENT_DESCRIPTION     \
"/* %s */\n"\

#define R_F_DOM_ENUM_END    \
"    NVRAM_LAST_%s_ELEMENT\n"\
"}%sDATA;\n"\
"\n"

#define NVRAM_AUTO_GEN_MAX_PATH_LEN 128
#define NVRAM_EXIT_CODE_ERROR 3

#endif/*NVRAM_AUTO_GEN_H*/
