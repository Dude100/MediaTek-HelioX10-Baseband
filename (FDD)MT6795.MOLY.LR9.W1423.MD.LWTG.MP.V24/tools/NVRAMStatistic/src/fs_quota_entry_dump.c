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
 *   This file is intends for dump the fs quota setting
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
 * removed!
 * removed!
 * removed!
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

#ifdef __FS_QM_SUPPORT__

#include "flash_opt.h"
#include "kal_public_defs.h"
#include "fs_gprot.h"

/***************************************************************************** 
* Define
* Aim to pass compile, dummy function or gloabl variable here
*****************************************************************************/
FS_QuotaStruct *gFS_IntQuotaSet;
UINT        FS_MAX_QSET;

/***************************************************************************** 
* Local Variable
*****************************************************************************/
extern void nvram_gen_create_file(FILE **file_handle, char *file_path, char *file_name);

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
void FS_QuotaInit(FS_QuotaStruct *quota, kal_uint32 total)
{
    
    printf("FS_QuotaInit: %X, %d\n", quota, total);
    gFS_IntQuotaSet = quota;
    FS_MAX_QSET = total;
}

int nvram_gen_fs_quota(char *pathname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    #ifndef __PUBLIC_DRIVE_AVAILABLE__
        #ifdef MMS_SUPPORT
	        #ifdef MMS_IN_LARGE_STORAGE
	            fprintf(stderr, "Please set APP_STORAGE_IN_SYS_DRV as TRUE for those projects which disable phone drive!\n");        
	            exit(2);
	        #endif
        #endif
    #endif

    nvram_gen_create_file(&outputLog, pathname, "cksysdrv/~fs_quota_usage.log");
    
    fprintf(outputLog, "gFS_ExtQuotaSet[]\n");
    fprintf(outputLog, "-----------------------------------------------------------\n");

    for (i = 0; i < FS_MAX_QSET ; i++)
    {
       printf("{ %-20s , %5d , %10d , 0x%x , 0x%x },\n",
                 gFS_IntQuotaSet[i].Path,
                 gFS_IntQuotaSet[i].Priority,
                 gFS_IntQuotaSet[i].Qmin,
                 gFS_IntQuotaSet[i].Qmax,
                 gFS_IntQuotaSet[i].Uint);

       fprintf(outputLog, "{ %-20s , %5d , %10d , 0x%x , 0x%x },\n",
                gFS_IntQuotaSet[i].Path,
                gFS_IntQuotaSet[i].Priority,
                gFS_IntQuotaSet[i].Qmin,
                gFS_IntQuotaSet[i].Qmax,
                gFS_IntQuotaSet[i].Uint);
    }
    printf("output finish\n");
    fclose(outputLog);
    printf("close successfully\n");
}

#else /* __FS_QM_SUPPORT__ */
int nvram_gen_fs_quota(char *pathname)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE* outputLog;
    int   i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_gen_create_file(&outputLog, pathname, "cksysdrv/~fs_quota_usage.log");
    
    fprintf(outputLog, "__FS_QM_SUPPORT__ Off\n");

    fclose(outputLog);
    return 0;
}
#endif
