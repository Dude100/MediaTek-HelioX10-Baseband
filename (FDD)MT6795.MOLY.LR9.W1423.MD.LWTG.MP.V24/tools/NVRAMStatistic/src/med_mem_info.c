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
 * fs_quota_entry_dump.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for dump med memory run-time info
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/***************************************************************************** 
* Include
*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdarg.h>

#ifndef MED_NOT_PRESENT
#ifdef __inline
    #undef __inline
#endif /* __inline */

#ifdef __GNUC__
    #define __inline static inline
#else
    #define __inline static
#endif

//MSBB remove #include "kal_non_specific_general_types.h"
#include "med_global.h"

/***************************************************************************** 
* Define
* Aim to pass compile, dummy function or gloabl variable here
*****************************************************************************/
kal_int32 system_boot_mode;
/***************************************************************************** 
* Local Variable
*****************************************************************************/
#ifdef _STACK_LTLCOM_H
void free_int_ilm(ilm_struct *ilm_ptr, kal_char* file_name, kal_uint32 line)
{   return;
}
#endif

/*****************************************************************************
* FUNCTION
*  main
* DESCRIPTION
*  main function.
* PARAMETERS
*  None
* RETURNS
*  None
*****************************************************************************/
int main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    outputLog = fopen("..\\..\\..\\~med_mem_info.log","w+");
    
    fprintf(outputLog, "***********************************************************************\n");
    fprintf(outputLog, "Med Memory Information\n");
    fprintf(outputLog, "***********************************************************************\n");
    fprintf(outputLog, "sizeof(aud_ext_mem_union) == %d\n", sizeof(aud_ext_mem_union));
    fprintf(outputLog, "sizeof(med_ext_mem_union) == %d\n", sizeof(med_ext_mem_union));
    fprintf(outputLog, "sizeof(med_int_mem_union) == %d\n", sizeof(med_int_mem_union));
    fclose(outputLog);
    return 0;
}

#else /* MED_NOT_PRESENT */
int main()
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    outputLog = fopen("..\\..\\..\\~med_mem_info.log","w+");
    
    fprintf(outputLog, "MED_NOT_PRESENT\n");

    fclose(outputLog);
    return 0;
}
#endif
