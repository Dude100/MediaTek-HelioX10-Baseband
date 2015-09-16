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
 * nvram_auto_gen.c
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
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT
#if defined(NEPTUNE_MMI)
/*****************************************************************************
* Include
*****************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <io.h>

#include "nvram_auto_gen.h"

#if defined(__MMI_FMI__)
#include "nvram_common_defs.h"
#include "nvram_mmi_cache_defs.h"
#endif

#define BYTE_ENTRY_COUNT    (NVRAM_CACHE_SIZE)
#define SHORT_ENTRY_COUNT   (NVRAM_CACHE_SIZE >> 1)
#define DOUBLE_ENTRY_COUNT  (NVRAM_CACHE_SIZE >> 3)

extern mmi_cache_byte_entry common_mmi_cache_byte[];
extern mmi_cache_short_entry common_mmi_cache_short[];
extern mmi_cache_double_entry common_mmi_cache_double[];

extern mmi_cache_byte_entry custom_mmi_cache_byte[];
extern mmi_cache_short_entry custom_mmi_cache_short[];
extern mmi_cache_double_entry custom_mmi_cache_double[];

#ifndef __OPTR_NONE__
extern mmi_cache_byte_entry operator_mmi_cache_byte[];
extern mmi_cache_short_entry operator_mmi_cache_short[];
extern mmi_cache_double_entry operator_mmi_cache_double[];
#endif /* __OPTR_NONE__ */

static int nvram_gen_compare_byte(const void *a, const void *b);
static int nvram_gen_compare_short(const void *a, const void *b);
static int nvram_gen_compare_double(const void *a, const void *b);
static int nvram_sort_byte(void);
static int nvram_sort_short(void);
static int nvram_sort_double(void);
static int nvram_merge_byte(
            mmi_cache_byte_entry[],
            int,
            mmi_cache_byte_entry[],
            int,
            mmi_cache_byte_entry[]);
static int nvram_merge_short(
            mmi_cache_short_entry[],
            int,
            mmi_cache_short_entry[],
            int,
            mmi_cache_short_entry[]);
static int nvram_merge_double(
            mmi_cache_double_entry[],
            int,
            mmi_cache_double_entry[],
            int,
            mmi_cache_double_entry[]);

/* get user fills count */
static int nvram_get_byte_entry_count(mmi_cache_byte_entry[]);
static int nvram_get_short_entry_count(mmi_cache_short_entry[]);
static int nvram_get_double_entry_count(mmi_cache_double_entry[]);

/* The following should be initialized in main function */
static int nvram_common_byte_count;
static int nvram_common_short_count;
static int nvram_common_double_count;

static int nvram_custom_byte_count;
static int nvram_custom_short_count;
static int nvram_custom_double_count;

/* if operator exists */
#ifndef __OPTR_NONE__
static int nvram_operator_byte_count;
static int nvram_operator_short_count;
static int nvram_operator_double_count;
#endif


/* After merge */
/* used to save the result of merging common and custom part */
static int nvram_byte_count;
static int nvram_short_count;
static int nvram_double_count;

/* used to save the result of final result */
#ifndef __OPTR_NONE__
static int nvram_op_byte_count;
static int nvram_op_short_count;
static int nvram_op_double_count;
#endif /* __OPTR_NONE__ */


/* used to save the final result */
static mmi_cache_byte_entry nvram_mmi_cache_byte[BYTE_ENTRY_COUNT];
static mmi_cache_short_entry nvram_mmi_cache_short[SHORT_ENTRY_COUNT];
static mmi_cache_double_entry nvram_mmi_cache_double[DOUBLE_ENTRY_COUNT];


/* used to save the result of merging common and custom part */
#ifndef __OPTR_NONE__
static mmi_cache_byte_entry nvram_op_byte[BYTE_ENTRY_COUNT];
static mmi_cache_short_entry nvram_op_short[SHORT_ENTRY_COUNT];
static mmi_cache_double_entry nvram_op_double[DOUBLE_ENTRY_COUNT];
#endif /* __OPTR_NONE__ */
static int nvram_restore_cache_byte[NVRAM_APP_TOTAL][BYTE_ENTRY_COUNT];
static int nvram_restore_cache_short[NVRAM_APP_TOTAL][SHORT_ENTRY_COUNT];
static int nvram_restore_cache_double[NVRAM_APP_TOTAL][DOUBLE_ENTRY_COUNT];
/* record total number of each application */
static int nvram_restore_byte_idx[NVRAM_APP_TOTAL];
static int nvram_restore_short_idx[NVRAM_APP_TOTAL];
static int nvram_restore_double_idx[NVRAM_APP_TOTAL];

/* record max length of id str */
static int nvram_max_length_byte_id_str;
static int nvram_max_length_short_id_str;
static int nvram_max_length_double_id_str;

static char nvram_auto_gen_output_path[NVRAM_AUTO_GEN_MAX_PATH_LEN];

/*****************************************************************************
* FUNCTION
*  nvram_gen_compare_byte
* DESCRIPTION
*  used by quick sort function
* PARAMETERS
*  a    [IN]
*  b    [IN]
* RETURNS
*  none
*****************************************************************************/
int nvram_gen_compare_byte(const void *a, const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cache_byte_entry *former, *latter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    former = a;
    latter = b;
    if ((former->id < 0 || former->id >= BYTE_ENTRY_COUNT) ||
        (latter->id < 0 || latter->id >= BYTE_ENTRY_COUNT))
    {
        /* assert(0); */
        return 0;
    }
    if (former->id < latter->id)
    {
        return -1;
    }
    else if (former->id > latter->id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  nvram_gen_compare_short
* DESCRIPTION
*  used by quick sort function
* PARAMETERS
*  a    [IN]
*  b    [IN]
* RETURNS
*  none
*****************************************************************************/
int nvram_gen_compare_short(const void *a, const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cache_short_entry *former, *latter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    former = a;
    latter = b;
    if ((former->id < 0 || former->id >= SHORT_ENTRY_COUNT) ||
        (latter->id < 0 || latter->id >= SHORT_ENTRY_COUNT))
    {
        /* assert(0); */
        return 0;
    }
    if (former->id < latter->id)
    {
        return -1;
    }
    else if (former->id > latter->id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*  nvram_gen_compare_double
* DESCRIPTION
*  used by quick sort function
* PARAMETERS
*  a    [IN]
*  b    [IN]
* RETURNS
*  none
*****************************************************************************/
int nvram_gen_compare_double(const void *a, const void *b)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    mmi_cache_double_entry *former, *latter;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    former = a;
    latter = b;
    if ((former->id < 0 || former->id >= DOUBLE_ENTRY_COUNT) ||
        (latter->id < 0 || latter->id >= DOUBLE_ENTRY_COUNT))
    {
        /* assert(0); */
        return 0;
    }
    if (former->id < latter->id)
    {
        return -1;
    }
    else if (former->id > latter->id)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    return 0;
}


/*****************************************************************************
* FUNCTION
*   nvram_merge_byte
* DESCRIPTION
*   merge two byte_cache array
* PARAMETERS
*   low_pri      [IN]
*   low_count    [IN]
*   high_pri     [IN]
*   high_count   [IN]
*   result_array [OUT]
* RETURNS
*   the count of result array after merging
*****************************************************************************/
int nvram_merge_byte(
        mmi_cache_byte_entry low_pri[],
        int low_count,
        mmi_cache_byte_entry high_pri[],
        int high_count,
        mmi_cache_byte_entry result_array[]
        )
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, low_pri_p, high_pri_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    low_pri_p = 0;
    high_pri_p = 0;
    while (low_pri_p < low_count || high_pri_p < high_count)
    {
        if (low_pri_p >= low_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_byte_entry));
            i++;
            high_pri_p++;
            continue;
        }
        if (high_pri_p >= high_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_byte_entry));
            i++;
            low_pri_p++;
            continue;
        }
        if (low_pri[low_pri_p].id == high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_byte_entry));
            i++;
            low_pri_p++;
            high_pri_p++;
        }
        else if (low_pri[low_pri_p].id < high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_byte_entry));
            i++;
            low_pri_p++;
        }
        else
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_byte_entry));
            i++;
            high_pri_p++;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_merge_short
* DESCRIPTION
*   merge two short_cache array
* PARAMETERS
*   low_pri      [IN]
*   low_count    [IN]
*   high_pri     [IN]
*   high_count   [IN]
*   result_array [OUT]
* RETURNS
*   the count of result array after merging
*****************************************************************************/
int nvram_merge_short(
        mmi_cache_short_entry low_pri[],
        int low_count,
        mmi_cache_short_entry high_pri[],
        int high_count,
        mmi_cache_short_entry result_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, low_pri_p, high_pri_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    low_pri_p = 0;
    high_pri_p = 0;
    while (low_pri_p < low_count || high_pri_p < high_count)
    {
        if (low_pri_p >= low_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_short_entry));
            i++;
            high_pri_p++;
            continue;
        }
        if (high_pri_p >= high_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_short_entry));
            i++;
            low_pri_p++;
            continue;
        }
        if (low_pri[low_pri_p].id == high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_short_entry));
            i++;
            low_pri_p++;
            high_pri_p++;
        }
        else if (low_pri[low_pri_p].id < high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_short_entry));
            i++;
            low_pri_p++;
        }
        else
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_short_entry));
            i++;
            high_pri_p++;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_merge_double
* DESCRIPTION
*   merge two double_cache array
* PARAMETERS
*   low_pri      [IN]
*   low_count    [IN]
*   high_pri     [IN]
*   high_count   [IN]
*   result_array [OUT]
* RETURNS
*   the count of result array after merging
*****************************************************************************/
int nvram_merge_double(
        mmi_cache_double_entry low_pri[],
        int low_count,
        mmi_cache_double_entry high_pri[],
        int high_count,
        mmi_cache_double_entry result_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i, low_pri_p, high_pri_p;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    low_pri_p = 0;
    high_pri_p = 0;
    while (low_pri_p < low_count || high_pri_p < high_count)
    {
        if (low_pri_p >= low_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_double_entry));
            i++;
            high_pri_p++;
            continue;
        }
        if (high_pri_p >= high_count)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_double_entry));
            i++;
            low_pri_p++;
            continue;
        }
        if (low_pri[low_pri_p].id == high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_double_entry));
            i++;
            low_pri_p++;
            high_pri_p++;
        }
        else if (low_pri[low_pri_p].id < high_pri[high_pri_p].id)
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == low_pri[low_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                low_pri + low_pri_p,
                sizeof(mmi_cache_double_entry));
            i++;
            low_pri_p++;
        }
        else
        {
            /* Avoid same */
            if (i > 0)
            {
                if (result_array[i - 1].id == high_pri[high_pri_p].id)
                {
                    return -1;
                }
            }
            memcpy(result_array + i,
                high_pri + high_pri_p,
                sizeof(mmi_cache_double_entry));
            i++;
            high_pri_p++;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_get_byte_entry_count
* DESCRIPTION
*   get entries count of a byte_cache
* PARAMETERS
*   mmi_cache_byte_array    [IN]
* RETURNS
*   the count of the entries
*****************************************************************************/
int nvram_get_byte_entry_count(mmi_cache_byte_entry mmi_cache_byte_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (mmi_cache_byte_array[i].id == 0xFF &&
            mmi_cache_byte_array[i].value == 0xFF &&
            *(mmi_cache_byte_array[i].id_str) == '\0')
        {
            break;
        }
        else
        {
            i++;
        }
        if (i >= BYTE_ENTRY_COUNT)
        {
            /* exceed the max count */
            return -1;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_get_short_entry_count
* DESCRIPTION
*   get entries count of a short_cache
* PARAMETERS
*   mmi_cache_short_array    [IN]
* RETURNS
*   the count of the entries
*****************************************************************************/
int nvram_get_short_entry_count(mmi_cache_short_entry mmi_cache_short_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (mmi_cache_short_array[i].id == 0xFF &&
            mmi_cache_short_array[i].value1 == 0xFF &&
            mmi_cache_short_array[i].value2 == 0xFF &&
            *(mmi_cache_short_array[i].id_str) == '\0')
        {
            break;
        }
        else
        {
            i++;
        }
        if (i >= SHORT_ENTRY_COUNT)
        {
            /* exceed the max count */
            return -1;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_get_double_entry_count
* DESCRIPTION
*   get entries count of a double_cache
* PARAMETERS
*   mmi_cache_double_array    [IN]
* RETURNS
*   the count of the entries
*****************************************************************************/
int nvram_get_double_entry_count(mmi_cache_double_entry mmi_cache_double_array[])
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int i;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    i = 0;
    while (1)
    {
        if (mmi_cache_double_array[i].id == 0xFF &&
            mmi_cache_double_array[i].value1 == 0xFF &&
            mmi_cache_double_array[i].value2 == 0xFF &&
            mmi_cache_double_array[i].value3 == 0xFF &&
            mmi_cache_double_array[i].value4 == 0xFF &&
            mmi_cache_double_array[i].value5 == 0xFF &&
            mmi_cache_double_array[i].value6 == 0xFF &&
            mmi_cache_double_array[i].value7 == 0xFF &&
            mmi_cache_double_array[i].value8 == 0xFF &&
            *(mmi_cache_double_array[i].id_str) == '\0')
        {
            break;
        }
        else
        {
            i++;
        }
        if (i >= DOUBLE_ENTRY_COUNT)
        {
            /* exceed the max count */
            return -1;
        }
    }
    return i;
}


/*****************************************************************************
* FUNCTION
*   nvram_sort_byte
* DESCRIPTION
*   sort one byte_cache
* PARAMETERS
*   none
* RETURNS
*   none
*****************************************************************************/
int nvram_sort_byte(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sort common */
    qsort((void *)common_mmi_cache_byte, nvram_common_byte_count, sizeof(mmi_cache_byte_entry), &nvram_gen_compare_byte);

    /* sort custom */
    qsort((void *)custom_mmi_cache_byte, nvram_custom_byte_count, sizeof(mmi_cache_byte_entry), &nvram_gen_compare_byte);

    /* sort operator */
#ifndef __OPTR_NONE__
    qsort((void *)operator_mmi_cache_byte, nvram_operator_byte_count, sizeof(mmi_cache_byte_entry), &nvram_gen_compare_byte);
#endif
    return 0;
}


/*****************************************************************************
* FUNCTION
*   nvram_sort_short
* DESCRIPTION
*   sort one short_cache
* PARAMETERS
*   none
* RETURNS
*   none
*****************************************************************************/
int nvram_sort_short(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sort common */
    qsort((void *)common_mmi_cache_short, nvram_common_short_count, sizeof(mmi_cache_short_entry), &nvram_gen_compare_short);

    /* sort custom */
    qsort((void *)custom_mmi_cache_short, nvram_custom_short_count, sizeof(mmi_cache_short_entry), &nvram_gen_compare_short);

    /* sort operator */
#ifndef __OPTR_NONE__
    qsort((void *)operator_mmi_cache_short, nvram_operator_short_count, sizeof(mmi_cache_short_entry), &nvram_gen_compare_short);
#endif
    return 0;
}


/*****************************************************************************
* FUNCTION
*   nvram_sort_double
* DESCRIPTION
*   sort one double_cache
* PARAMETERS
*   none
* RETURNS
*   none
*****************************************************************************/
int nvram_sort_double(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /* sort common */
    qsort((void *)common_mmi_cache_double, nvram_common_double_count, sizeof(mmi_cache_double_entry), &nvram_gen_compare_double);

    /* sort custom */
    qsort((void *)custom_mmi_cache_double, nvram_custom_double_count, sizeof(mmi_cache_double_entry), &nvram_gen_compare_double);

#ifndef __OPTR_NONE__
    qsort((void *)operator_mmi_cache_double, nvram_operator_double_count, sizeof(mmi_cache_double_entry), &nvram_gen_compare_double);
#endif
    return 0;
}

/*****************************************************************************
* FUNCTION
*   nvram_gen_mmi_cache
* DESCRIPTION
*   output mmi cache default value to nvram_mmi_cust_pack.h
* PARAMETERS
*   project_name    [IN]
*   broad_ver       [IN]
* RETURNS
*   none
*****************************************************************************/
void nvram_gen_mmi_cache(char *project_name, char *broad_ver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *output;
    int i, k;
    int byte_max_len, short_max_len, double_max_len;
    char output_pathname[NVRAM_AUTO_GEN_MAX_PATH_LEN];
    int mode_result;
    nvram_lid_enum last_custpack_lid;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(output_pathname, "%s\\nvram_mmi_cache_cust_pack.h", nvram_auto_gen_output_path);

    printf("nvram_gen_mmi_cache milestone1\n");

    /* check if the file exists. */
    mode_result = access(output_pathname, 0);
    if (mode_result == 0)
    {
        /* exists,but check if it can be written. */
        mode_result = access(output_pathname, 2);
        if (mode_result != 0)
        {
            fprintf(stderr, "error: nvram_mmi_cache_cust_pack.h exists,but it cannot be written.\n");
            exit(NVRAM_EXIT_CODE_ERROR);
        }
    }
    else
    {
        /* file not exist*/
        mode_result = access(nvram_auto_gen_output_path, 2);
        if (mode_result != 0)
        {
            fprintf(stderr, "error: cannot create file in The project_BB folder\n");
            exit(NVRAM_EXIT_CODE_ERROR);
        }
    }
    output = fopen(output_pathname, "w+");
    if (output == NULL)
    {
        fprintf(stderr, "error: cannot write to nvram_mmi_cache_cust_pack.h in The project_BB folder\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    fprintf(output, "/* This file is generated automatically by nvram_auto_gen.exe, please do not modify it here manually */\n");

    printf("nvram_gen_mmi_cache milestone2\n");

    nvram_common_byte_count = nvram_get_byte_entry_count(common_mmi_cache_byte);
    if (nvram_common_byte_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds common_byte_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_common_short_count = nvram_get_short_entry_count(common_mmi_cache_short);
    if (nvram_common_short_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds common_short_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_common_double_count = nvram_get_double_entry_count(common_mmi_cache_double);
    if (nvram_common_double_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds common_double_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_custom_byte_count = nvram_get_byte_entry_count(custom_mmi_cache_byte);
    if (nvram_custom_byte_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds custom_byte_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }

    nvram_custom_short_count = nvram_get_short_entry_count(custom_mmi_cache_short);
    if (nvram_custom_short_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds custom_short_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }

    nvram_custom_double_count = nvram_get_double_entry_count(custom_mmi_cache_double);
    if (nvram_custom_double_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds custom_double_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
#ifndef __OPTR_NONE__
    nvram_operator_byte_count = nvram_get_byte_entry_count(operator_mmi_cache_byte);
    if (nvram_operator_byte_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds operator_byte_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_operator_short_count = nvram_get_short_entry_count(operator_mmi_cache_short);
    if (nvram_operator_short_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds operator_short_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_operator_double_count = nvram_get_double_entry_count(operator_mmi_cache_double);
    if (nvram_operator_double_count < 0)
    {
        fprintf(stderr, "error: configuration exceeds operator_double_cache max count.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
#endif

    printf("nvram_gen_mmi_cache milestone3\n");

    nvram_sort_byte();
    nvram_sort_short();
    nvram_sort_double();
    /*
    fprintf(output, "nvram_common_byte_count : %d--------------------------------------------\n", nvram_common_byte_count);
    for (i = 0; i < nvram_common_byte_count; i++)
    {
        fprintf(output, "%s, %s\n", common_mmi_cache_byte[i].id_str, common_mmi_cache_byte[i].value_str);
    }
    fprintf(output, "nvram_common_short_count : %d--------------------------------------------\n", nvram_common_short_count);
    fprintf(output, "nvram_common_double_count : %d--------------------------------------------\n", nvram_common_double_count);
    fprintf(output, "nvram_custom_byte_count : %d--------------------------------------------\n", nvram_custom_byte_count);
    for (i = 0; i < nvram_custom_byte_count; i++)
    {
        fprintf(output, "%s, %s\n", custom_mmi_cache_byte[i].id_str, custom_mmi_cache_byte[i].value_str);
    }
    */

    printf("nvram_gen_mmi_cache milestone4\n");

#ifndef __OPTR_NONE__
    nvram_op_byte_count = nvram_merge_byte(
                        common_mmi_cache_byte,
                        nvram_common_byte_count,
                        custom_mmi_cache_byte,
                        nvram_custom_byte_count,
                        nvram_op_byte);
    if (nvram_op_byte_count < 0)
    {
        fprintf(stderr, "error: duplicate byte entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_op_short_count = nvram_merge_short(
                        common_mmi_cache_short,
                        nvram_common_short_count,
                        custom_mmi_cache_short,
                        nvram_custom_short_count,
                        nvram_op_short);
    if (nvram_op_short_count < 0)
    {
        fprintf(stderr, "error: duplicate short entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_op_double_count = nvram_merge_double(
                        common_mmi_cache_double,
                        nvram_common_double_count,
                        custom_mmi_cache_double,
                        nvram_custom_double_count,
                        nvram_op_double);
    if (nvram_op_double_count < 0)
    {
        fprintf(stderr, "error: duplicate double entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_byte_count = nvram_merge_byte(
                    nvram_op_byte,
                    nvram_op_byte_count,
                    operator_mmi_cache_byte,
                    nvram_operator_byte_count,
                    nvram_mmi_cache_byte);
    if (nvram_byte_count < 0)
    {
        fprintf(stderr, "error: duplicate nvram_op_byte entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_short_count = nvram_merge_short(
                    nvram_op_short,
                    nvram_op_short_count,
                    operator_mmi_cache_short,
                    nvram_operator_short_count,
                    nvram_mmi_cache_short);
    if (nvram_short_count < 0)
    {
        fprintf(stderr, "error: duplicate nvram_op_short entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }

    nvram_double_count = nvram_merge_double(
                    nvram_op_double,
                    nvram_op_double_count,
                    operator_mmi_cache_double,
                    nvram_operator_double_count,
                    nvram_mmi_cache_double);
    if (nvram_double_count < 0)
    {
        fprintf(stderr, "error: duplicate nvram_op_double entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
#else /* __OPTR_NONE__ */
    nvram_byte_count = nvram_merge_byte(
                    common_mmi_cache_byte,
                    nvram_common_byte_count,
                    custom_mmi_cache_byte,
                    nvram_custom_byte_count,
                    nvram_mmi_cache_byte);
    if (nvram_byte_count < 0)
    {
        fprintf(stderr, "error: duplicate byte entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_short_count = nvram_merge_short(
                    common_mmi_cache_short,
                    nvram_common_short_count,
                    custom_mmi_cache_short,
                    nvram_custom_short_count,
                    nvram_mmi_cache_short);
    if (nvram_short_count < 0)
    {
        fprintf(stderr, "error: duplicate short entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }
    nvram_double_count = nvram_merge_double(
                    common_mmi_cache_double,
                    nvram_common_double_count,
                    custom_mmi_cache_double,
                    nvram_custom_double_count,
                    nvram_mmi_cache_double);
    if (nvram_double_count < 0)
    {
        fprintf(stderr, "error: duplicate double entries exist.\n");
        exit(NVRAM_EXIT_CODE_ERROR);
    }

#endif /* __OPTR_NONE__ */

    /*
    if (nvram_mmi_cache_byte[nvram_byte_count - 1].id != NVRAM_LAST_BYTE_ELEMENT - 1)
    {
        fprintf(stderr, "warning: there is byte enum id that does not config default value\n");
    }
    if (nvram_mmi_cache_short[nvram_short_count - 1].id != NVRAM_LAST_SHORT_ELEMENT - 1)
    {
        fprintf(stderr, "warning: there is short enum id that does not config default value\n");
    }
    if (nvram_mmi_cache_double[nvram_double_count - 1].id != NVRAM_LAST_DOUBLE_ELEMENT - 1)
    {
        fprintf(stderr, "warning: there is double enum id that does not config default value\n");
    }
    */

    printf("nvram_gen_mmi_cache milestone5\n");

    byte_max_len = 0;
    short_max_len = 0;
    double_max_len = 0;
    for (i = 0; i < nvram_byte_count; i++)
    {
        if (strlen(nvram_mmi_cache_byte[i].value_str) > byte_max_len)
        {
            byte_max_len = strlen(nvram_mmi_cache_byte[i].value_str);
        }
    }
    for (i = 0; i < nvram_short_count; i++)
    {
        if (strlen(nvram_mmi_cache_short[i].value1_str) > short_max_len)
        {
            short_max_len = strlen(nvram_mmi_cache_short[i].value1_str);
        }
        if (strlen(nvram_mmi_cache_short[i].value2_str) > short_max_len)
        {
            short_max_len = strlen(nvram_mmi_cache_short[i].value2_str);
        }
    }
    for (i = 0; i < nvram_double_count; i++)
    {
        if (strlen(nvram_mmi_cache_double[i].value1_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value1_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value2_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value2_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value3_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value3_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value4_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value4_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value5_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value5_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value6_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value6_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value7_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value7_str);
        }
        if (strlen(nvram_mmi_cache_double[i].value8_str) > double_max_len)
        {
            double_max_len = strlen(nvram_mmi_cache_double[i].value8_str);
        }
    }


    printf("nvram_gen_mmi_cache milestone6\n");

    /* Begin output NVRAM_CACHE_BYTE_DEFAULT */
    i = 0;
    fprintf(output, "/* The count of byte configuaration: %d */\n", nvram_byte_count);
    fprintf(output, "/* BYTEDATA enum Max index: %d */\n", NVRAM_LAST_BYTE_ELEMENT - 1);
    fprintf(output, "const kal_uint8 NVRAM_CACHE_BYTE_DEFAULT[NVRAM_CACHE_SIZE] =\n");
    fprintf(output, "{\n");
    for (k = 0; k < BYTE_ENTRY_COUNT; k++)
    {
        int j;
        if (i < nvram_byte_count)
        {
            if (nvram_mmi_cache_byte[i].id == k)    /* enum <--->entry */
            {
            /* Begin to restore factory */
                if (nvram_mmi_cache_byte[i].restore)
                {
                    /* Get max length begin */
                    if(strlen(nvram_mmi_cache_byte[i].id_str) > nvram_max_length_byte_id_str)
                    {
                        nvram_max_length_byte_id_str = strlen(nvram_mmi_cache_byte[i].id_str);
                    }
                    /* Get max length end */

                    nvram_restore_cache_byte[nvram_mmi_cache_byte[i].app_id][nvram_restore_byte_idx[nvram_mmi_cache_byte[i].app_id]]
                        = i;
                    nvram_restore_byte_idx[nvram_mmi_cache_byte[i].app_id]++;
                    //cache_struct_idx++;
                }
            /* End to restore factory */
                fprintf(output, "    %s", nvram_mmi_cache_byte[i].value_str);
                if (k != BYTE_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",");
                }
                for (j = 0; j < byte_max_len - strlen(nvram_mmi_cache_byte[i].value_str) + 4; j++)
                {
                    fprintf(output, " ");
                }
                fprintf(output, "/* %3d  : %s */\n", nvram_mmi_cache_byte[i].id, nvram_mmi_cache_byte[i].id_str);
                i++;
            }
            else
            {
                fprintf(output, "    0xFF");
                if (k != BYTE_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",/* unset */");
                }
                fprintf(output, "\n");
            }
        }
        else
        {
            fprintf(output, "    0xFF");
            if (k != BYTE_ENTRY_COUNT - 1)
            {
                fprintf(output, ",");
            }
            fprintf(output, "\n");
        }
    }
    fprintf(output, "};\n\n\n");
    /* End output NVRAM_CACHE_BYTE_DEFAULT */


    /* Begin output NVRAM_CACHE_SHORT_DEFAULT */
    i = 0;
    fprintf(output, "/* The count of short configuaration: %d */\n", nvram_short_count);
    fprintf(output, "/* SHORTDATA enum Max index: %d */\n", NVRAM_LAST_SHORT_ELEMENT - 1);

    fprintf(output, "const kal_uint8 NVRAM_CACHE_SHORT_DEFAULT[NVRAM_CACHE_SIZE] =\n");
    fprintf(output, "{\n");
    for (k = 0; k < SHORT_ENTRY_COUNT; k++)
    {
        int j;
        if (i < nvram_short_count)
        {
            if (nvram_mmi_cache_short[i].id == k)
            {
                /* Get max length begin */
                if(strlen(nvram_mmi_cache_short[i].id_str) > nvram_max_length_short_id_str)
                {
                    nvram_max_length_short_id_str = strlen(nvram_mmi_cache_short[i].id_str);
                }
                /* Get max length end */

            /* Begin to restore factory */
                if (nvram_mmi_cache_short[i].restore)
                {
                    nvram_restore_cache_short[nvram_mmi_cache_short[i].app_id][nvram_restore_short_idx[nvram_mmi_cache_short[i].app_id]]
                        //= nvram_mmi_cache_short[i].id;
                        = i;
                    nvram_restore_short_idx[nvram_mmi_cache_short[i].app_id]++;
                }
            /* End to restore factory */
                fprintf(output, "    %s,", nvram_mmi_cache_short[i].value1_str);
                for (j = 0; j < short_max_len - strlen(nvram_mmi_cache_short[i].value1_str) + 4; j++)
                {
                    fprintf(output, " ");
                }
                fprintf(output, "/* %3d  : %s */\n", nvram_mmi_cache_short[i].id, nvram_mmi_cache_short[i].id_str);
                fprintf(output, "    %s", nvram_mmi_cache_short[i].value2_str);
                if (k != SHORT_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",");
                }
                fprintf(output, "\n");
                i++;
            }
            else
            {
                fprintf(output, "    0xFF,/* unset */\n");
                fprintf(output, "    0xFF");
                if (k != SHORT_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",");
                }
                fprintf(output, "\n");
            }
        }
        else
        {
            fprintf(output, "    0xFF,\n");
            fprintf(output, "    0xFF");
            if (k != SHORT_ENTRY_COUNT - 1)
            {
                fprintf(output, ",");
            }
            fprintf(output, "\n");
        }

    }

    fprintf(output, "};\n\n\n");
    /* End output NVRAM_CACHE_SHORT_DEFAULT */


    /* Begin output NVRAM_CACHE_DOUBLE_DEFAULT */
    i = 0;
    fprintf(output, "/* The count of double configuaration: %d */\n", nvram_double_count);
    fprintf(output, "/* DOUBLEDATA enum Max index: %d */\n", NVRAM_LAST_DOUBLE_ELEMENT - 1);

    fprintf(output, "const kal_uint8 NVRAM_CACHE_DOUBLE_DEFAULT[NVRAM_CACHE_SIZE] =\n");
    fprintf(output, "{\n");
    for (k = 0; k < DOUBLE_ENTRY_COUNT; k++)
    {
        int j;
        if (i < nvram_double_count)
        {
            if (nvram_mmi_cache_double[i].id == k)
            {
            /* Begin to restore factory */
                if (nvram_mmi_cache_double[i].restore)
                {
                    /* Get max length begin */
                    if(strlen(nvram_mmi_cache_double[i].id_str) > nvram_max_length_double_id_str)
                    {
                        nvram_max_length_double_id_str = strlen(nvram_mmi_cache_double[i].id_str);
                    }
                    /* Get max length end */

                    nvram_restore_cache_double[nvram_mmi_cache_double[i].app_id][nvram_restore_double_idx[nvram_mmi_cache_double[i].app_id]]
                        = i;
                    nvram_restore_double_idx[nvram_mmi_cache_double[i].app_id]++;
                }
            /* End to restore factory */
                fprintf(output, "    %s,", nvram_mmi_cache_double[i].value1_str);
                for (j = 0; j < short_max_len - strlen(nvram_mmi_cache_double[i].value1_str) + 4; j++)
                {
                    fprintf(output, " ");
                }
                fprintf(output, "/* %3d  : %s */\n", nvram_mmi_cache_double[i].id, nvram_mmi_cache_double[i].id_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value2_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value3_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value4_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value5_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value6_str);
                fprintf(output, "    %s,\n", nvram_mmi_cache_double[i].value7_str);
                fprintf(output, "    %s", nvram_mmi_cache_double[i].value8_str);
                if (k != DOUBLE_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",");
                }
                fprintf(output, "\n");
                i++;
            }
            else
            {
                fprintf(output,
                    "    0xFF,/* unset */\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF");
                if (k != DOUBLE_ENTRY_COUNT - 1)
                {
                    fprintf(output, ",");
                }
                fprintf(output, "\n");
            }
        }
        else
        {
            fprintf(output, "    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF,\n    0xFF");
            if (k != DOUBLE_ENTRY_COUNT - 1)
            {
                fprintf(output, ",");
            }
            fprintf(output, "\n");
        }
    }
    fprintf(output, "};\n\n\n");
    fclose(output);
}

void nvram_gen_mmi_cache_res_func(FILE *fh_restore_factory_c, FILE *fh_restore_dom_h)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int  loop_app_idx;
    int  loop_app_cache_idx;
    int  loop_value_idx;
    int  loop_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* step 1: generate function name */
    fprintf(fh_restore_factory_c,NVRAM_FUNCTION_HEAD, "nvram_restore_byte_cache()", "byte");
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_NAME, "byte", "kal_uint8", "b", "kal_uint8");

    /* Dom: byte (begin) */
    fprintf(fh_restore_dom_h, R_F_DOM_COMMENT, "BYTE -8bit");
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_BEGIN);
    /* Dom: byte (end) */

    /* step 2: generate function context */
    for (loop_app_idx = 0; loop_app_idx < NVRAM_APP_TOTAL; loop_app_idx++)
    {
        if (nvram_restore_byte_idx[loop_app_idx])
        {
            fprintf(fh_restore_factory_c,"        case %s :\n", nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][0]].app_id_str);
        }
        else
        {
            continue;
        }

        for (loop_app_cache_idx = 0; loop_app_cache_idx < nvram_restore_byte_idx[loop_app_idx]; loop_app_cache_idx++)
        {
            /* Dom: byte (begin) */
            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_ID,
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].id_str);

            for (loop_space = 0; loop_space < nvram_max_length_byte_id_str - strlen(nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].id_str); loop_space++)
            {
                fprintf(fh_restore_dom_h, " ");
            }

            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_DESCRIPTION,
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].description);
            /* Dom: byte (end) */

            if (nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].restore_id == NVRAM_CACHE_ID_RESERVED)
            {
                fprintf(fh_restore_factory_c,"            buffer[%s] = %s;\n",
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].id_str,
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].value_str);
            }
            else
            {
                fprintf(fh_restore_factory_c,"            b_buffer[%s] = b_buffer[%s];\n",
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].id_str,
                        nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][loop_app_cache_idx]].restore_id_str);
            }
        }

        fprintf(fh_restore_factory_c,NVRAM_RESTORE_FUNCTION_BREAK);
    }
    /* step 3: generate function end */
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_TAIL, 1);
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_END, "BYTE", "BYTE");

    /*
     * generate restore function: cache short
     *
     */

    /* step 1: generate function name */
    fprintf(fh_restore_factory_c,NVRAM_FUNCTION_HEAD, "nvram_restore_short_cache()", "short");
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_NAME, "short", "kal_uint16", "s", "kal_uint16");

    /* Dom: short (begin) */
    fprintf(fh_restore_dom_h, R_F_DOM_COMMENT, "SHORT -16bit");
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_BEGIN);
    /* Dom: short (end) */

    /* step 2: generate function context */
    for (loop_app_idx = 0; loop_app_idx < NVRAM_APP_TOTAL; loop_app_idx++)
    {
        if (nvram_restore_short_idx[loop_app_idx])
        {
            fprintf(fh_restore_factory_c,"        case %s :\n", nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][0]].app_id_str);
        }
        else
        {
            continue;
        }

        for (loop_app_cache_idx = 0; loop_app_cache_idx < nvram_restore_short_idx[loop_app_idx]; loop_app_cache_idx++)
        {
            /* Dom: short context (begin) */
            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_ID,
                        nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].id_str);

            for (loop_space = 0; loop_space < nvram_max_length_short_id_str - strlen(nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].id_str); loop_space++)
            {
                fprintf(fh_restore_dom_h, " ");
            }

            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_DESCRIPTION,
                        nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].description);
            /* Dom: short context (end) */

            if (nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].restore_id == NVRAM_CACHE_ID_RESERVED)
            {
                fprintf(fh_restore_factory_c, NVRAM_AUTO_GEN_COMMENT, nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].description);

                for (loop_value_idx = 0; loop_value_idx < sizeof(short); loop_value_idx++)
                {
                    fprintf(fh_restore_factory_c,"            buffer[%d * %s + %d] = 0x%02X;\n",
                            sizeof(short),
                            nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].id_str,
                            loop_value_idx,
                            *(&(nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].value1) + loop_value_idx));
                }

            }
            else
            {
                fprintf(fh_restore_factory_c,"            s_buffer[%s] = s_buffer[%s];\n",
                        nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].id_str,
                        nvram_mmi_cache_short[nvram_restore_cache_short[loop_app_idx][loop_app_cache_idx]].restore_id_str);
            }
        }

        fprintf(fh_restore_factory_c,NVRAM_RESTORE_FUNCTION_BREAK);
    }
    /* step 3: generate function end */
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_TAIL, 2);
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_END, "SHORT", "SHORT");

    /*
     * generate restore function: cache double
     *
     */

    /* step 1: generate function name */
    fprintf(fh_restore_factory_c,NVRAM_FUNCTION_HEAD, "nvram_restore_double_cache()", "double");
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_NAME, "double", "double", "d", "double");
    /* Dom: double (begin) */
    fprintf(fh_restore_dom_h, R_F_DOM_COMMENT, "DOUBLE -64bit");
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_BEGIN);
    /* Dom: double (end) */

    /* step 2: generate function context */
    for (loop_app_idx = 0; loop_app_idx < NVRAM_APP_TOTAL; loop_app_idx++)
    {
        if (nvram_restore_double_idx[loop_app_idx])
        {
            fprintf(fh_restore_factory_c,"        case %s :\n", nvram_mmi_cache_byte[nvram_restore_cache_byte[loop_app_idx][0]].app_id_str);
        }
        else
        {
            continue;
        }

        for (loop_app_cache_idx = 0; loop_app_cache_idx < nvram_restore_double_idx[loop_app_idx]; loop_app_cache_idx++)
        {
            /* Dom: double context (begin) */
            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_ID,
                        nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].id_str);

            for (loop_space = 0; loop_space < nvram_max_length_double_id_str - strlen(nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].id_str); loop_space++)
            {
                fprintf(fh_restore_dom_h, " ");
            }

            fprintf(fh_restore_dom_h, R_F_DOM_CONTENT_DESCRIPTION,
                        nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].description);
            /* Dom: double context (end) */

            fprintf(fh_restore_factory_c, NVRAM_AUTO_GEN_COMMENT, nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].description);

            if (nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].restore_id == NVRAM_CACHE_ID_RESERVED)
            {
                for (loop_value_idx = 0; loop_value_idx < sizeof(double); loop_value_idx++)
                {
                    fprintf(fh_restore_factory_c,"            buffer[%d * %s + %d] = 0x%02X;\n",
                            sizeof(double),
                            nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].id_str,
                            loop_value_idx,
                            *(&(nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].value1) + loop_value_idx));
                }
            }
            else
            {
                fprintf(fh_restore_factory_c,"            d_buffer[%s] = d_buffer[%s];\n",
                        nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].id_str,
                        nvram_mmi_cache_double[nvram_restore_cache_double[loop_app_idx][loop_app_cache_idx]].restore_id_str);
            }
        }

        fprintf(fh_restore_factory_c,NVRAM_RESTORE_FUNCTION_BREAK);
    }
    /* step 3: generate function end */
    fprintf(fh_restore_factory_c, NVRAM_RESTORE_FUNCTION_TAIL, 3);
    fprintf(fh_restore_dom_h, R_F_DOM_ENUM_END, "DOUBLE", "DOUBLE");
}

/*****************************************************************************
* FUNCTION
*   nvram_gen_mmi_cache
* DESCRIPTION
*   output restore head file to nvram_restore_headfile.h
* PARAMETERS
*   project_name    [IN]
*   broad_ver       [IN]
* RETURNS
*   none
*****************************************************************************/
void nvram_gen_create_file(FILE **file_handle, char *file_path, char *file_name)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    int  mode_result;
    char file_pathname[NVRAM_AUTO_GEN_MAX_PATH_LEN];

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(file_pathname, "%s\\%s", file_path, file_name);

    mode_result = access(file_pathname, 0);

    if (mode_result == 0)
    {
        /* exists,but check if it can be written. */
        mode_result = access(file_pathname, 2);
        if (mode_result != 0)
        {
            fprintf(stderr, "error: %s exists,but it cannot be written.\n", file_name);
            exit(NVRAM_EXIT_CODE_ERROR);
        }
    }
    else
    {
        /* file not exist*/
        mode_result = access(file_path, 2);
        if (mode_result != 0)
        {
            fprintf(stderr, "error: cannot create file in folder: %s\n", file_path);
            exit(NVRAM_EXIT_CODE_ERROR);
        }
    }

    *file_handle = fopen(file_pathname, "w+");
    if (file_handle == NULL)
    {
        fprintf(stderr, "error: cannot write to %s in folder: %s\n", file_name, file_path);
        exit(NVRAM_EXIT_CODE_ERROR);
    }

    return;
}

void nvram_gen_close_file(FILE **file_handle)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    fclose(*file_handle);
}

/*****************************************************************************
* FUNCTION
*   nvram_gen_restore_function
* DESCRIPTION
*   output restore function to nvram_user_restore_factory.c
* PARAMETERS
*   project_name    [IN]
*   broad_ver       [IN]
* RETURNS
*   none
*****************************************************************************/
void nvram_gen_restore_function(char *project_name, char *broad_ver)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    FILE *fh_restore_factory_c;
    FILE *fh_restore_dom_h;
    char output_pathname[NVRAM_AUTO_GEN_MAX_PATH_LEN];
    int  loop_app_idx;
    int  loop_space;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    sprintf(output_pathname, "mmi_cache_restore.c");
    nvram_gen_create_file(&fh_restore_factory_c,nvram_auto_gen_output_path,output_pathname);

    sprintf(output_pathname,"mmi_cache_restore_dom.h");
    nvram_gen_create_file(&fh_restore_dom_h,nvram_auto_gen_output_path,output_pathname);

    /* generate head file */
    fprintf(fh_restore_factory_c, COPYRIGHTS_HEADER, "custom_mmi_cache_restore.c");
    fprintf(fh_restore_factory_c, "#ifndef NVRAM_NOT_PRESENT\n");
    fprintf(fh_restore_factory_c, "#include \"kal_general_types.h\"\n");
    fprintf(fh_restore_factory_c, "#include \"nvram_enums.h\"\n");
    fprintf(fh_restore_factory_c, "#include \"custom_nvram_config.h\"\n");
    fprintf(fh_restore_factory_c, "#include \"custom_mmi_default_value.h\"\n");

    nvram_gen_mmi_cache_res_func(fh_restore_factory_c, fh_restore_dom_h);

    fprintf(fh_restore_factory_c, "#endif /* NVRAM_NOT_PRESENT */");

    nvram_gen_close_file(&fh_restore_factory_c);
    nvram_gen_close_file(&fh_restore_dom_h);
}

#endif /* #if defined(NEPTUNE_MMI) */
#endif /* NVRAM_NOT_PRESENT */

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
int main(int argc, char *argv[])
{
#if defined(NEPTUNE_MMI) && !defined(NVRAM_NOT_PRESENT)
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    if (argc > 1)
    {
        sprintf(nvram_auto_gen_output_path, "%s", argv[3]);
	
        printf("nvram_gen_mmi_cache\n");
        nvram_gen_mmi_cache(argv[1], argv[2]);

        printf("nvram_gen_mmi_cache_res_func\n");
        nvram_gen_restore_function(argv[1], argv[2]);

    }
    return 0;
#else
    printf("Old mmi cache mechanism is already phased out\n");
    return 0;
#endif
}

