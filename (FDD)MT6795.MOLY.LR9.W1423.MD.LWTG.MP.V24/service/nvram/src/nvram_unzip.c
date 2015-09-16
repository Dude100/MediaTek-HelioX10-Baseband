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
/*****************************************************************************
 *
 * Filename:
 * ---------
 *  nvram_unzip.c
 *
 * Project:
 * -------- 
 *  MAUI
 *
 * Description:
 * ------------
 *  	nvram default value  unzip interface, the zilb working buffer is form PLUTOMMI, 
 *		so this feature only can be supported on PLUTOMMI right now.
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __NVRAM_COMPRESS_SUPPORT__

/*****************************************************************************
 * Header file  
 *****************************************************************************/
#include "kal_general_types.h"
#include "kal_trace.h"

#include "nvram_defs.h"
#include "nvram_trc.h"
#include "nvram_util.h"

#include "app_zlib.h"
#include "simple_memory_manager.h"
#include "nvram_default_value.h"
#include "nvram_enums.h"

/*****************************************************************************
 * Typedef  
 *****************************************************************************/
typedef enum{
	RET_OK, 
	RET_STOP, 
	RET_OOM, 
	RET_TOTAL
	}Ret;
	
typedef Ret (*visit_funcptr)(void *data, void* usr_data);

/*****************************************************************************
 * Define
 *****************************************************************************/
#ifndef NVRAM_DEBUG
#define NVRAM_UNZIP_LOG0(grp) 			  NVRAM_LOG0(TRACE_FUNC, grp);
#define NVRAM_UNZIP_LOG1(grp, x) 		  NVRAM_LOG1(TRACE_FUNC, grp, x);
#define NVRAM_UNZIP_LOG3(grp, x1, x2, x3) NVRAM_LOG3(TRACE_FUNC, grp, x1, x2, x3);
#else
#define NVRAM_UNZIP_LOG0(grp) 			  nvram_trace_to_file(__LINE__, 0, 0, 308);
#define NVRAM_UNZIP_LOG1(grp, x) 		  nvram_trace_to_file(__LINE__, x, 0, 308);
#define NVRAM_UNZIP_LOG3(grp, x1, x2, x3) nvram_trace_to_file(__LINE__, x1, x2, x3);
#endif

#define NVRAM_ZLIB_BUFF_SIZE (80*1024)
#define RETURN_IF_FAIL(p) if(!(p)){NVRAM_UNZIP_LOG1(ABNORMAL_RETURN, __LINE__); return;}
#define RETURN_VAL_IF_FAIL(p, val) if(!(p)){NVRAM_UNZIP_LOG1(ABNORMAL_RETURN, __LINE__); return val;}

#define CONV_4BYTES_TO_INT(b, i) (i = ((b[0] << 24) + (b[1] << 16) + (b[2] << 8) + b[3]))
#define CONV_INT_TO_4BYTES(b, i) \
			b[0] = (kal_uint8)(i >> 24); \
			b[1] = (kal_uint8)(i >> 16); \
			b[2] = (kal_uint8)(i >> 8); \
			b[3] = (kal_uint8)i;


#define NVRAM_UNZIP_BUFFER_SIZE (NVRAM_MAX_DEFAULE_VALUE_SIZE + 32)

/*****************************************************************************
 * Global Variables 
 *****************************************************************************/


/*****************************************************************************
 * Global Function 
 *****************************************************************************/
/* Before MMI task init, we can use this pool */
extern kal_uint8* mmi_frm_scrmem_get_pool(kal_uint32 *size);

/*****************************************************************************
 * Local Variables 
 *****************************************************************************/

static STSMM nvram_unzip_smm;
static kal_uint32 g_nvram_curr_lid;

/*****************************************************************************
 * Local Function 
 *****************************************************************************/
static void *nvram_unzip_mem_malloc(void *opaque, kal_uint32 items, kal_uint32 size);
static void nvram_unzip_mem_free(void *opaque, void *address);

/*****************************************************************************
 * FUNCTION
*   nvram_unzip_org_size
 * DESCRIPTION
*   To check whether the entry can be compressed
 * PARAMETERS
*   entry		[IN]		the logical table
 * RETURNS
 *  kal_bool
 *****************************************************************************/
kal_uint32 nvram_unzip_org_size(const ltable_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
    RETURN_VAL_IF_FAIL(entry != NULL, KAL_FALSE);

	g_nvram_curr_lid = entry->LID;
    if (NVRAM_IS_ATTR_MULTI_DEFAULT(entry->attr))
    {
		return (entry->size * entry->total_records);
    }
	
    return entry->size;
}

/*****************************************************************************
 * FUNCTION
 *  nvram_unzip_default_value
 * DESCRIPTION
 *  
 * PARAMETERS
 *	unzip_buffer	[OUT]	just a pointer, the memory will be keep at working buffer.
 *	unzip_size	[OUT]
 *	buffer		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
void nvram_unzip_default_value(kal_uint8 **unzip_buffer, kal_uint32 *unzip_size, kal_uint8 const *buffer)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	kal_uint32 out_size;
	kal_int32 ret, i;
	kal_uint32 compress_len;
	kal_uint32 buffer_len;
	kal_uint8 *out_ptr;
	
    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_IF_FAIL(unzip_buffer != NULL);
	RETURN_IF_FAIL(buffer != NULL);

	out_ptr = mmi_frm_scrmem_get_pool(&buffer_len);
	smmInit(&nvram_unzip_smm, out_ptr + NVRAM_UNZIP_BUFFER_SIZE, buffer_len);

	CONV_4BYTES_TO_INT(buffer, compress_len);
//    EXT_ASSERT(buffer_len > compress_len, 0, buffer_len, buffer_len);
    ASSERT(buffer_len > compress_len);

	out_size = NVRAM_UNZIP_BUFFER_SIZE;
	
	ret = uncompress_mtk(out_ptr,	 
					    (uLongf *)&out_size,
					    buffer + 4, /* sizeof(kal_uint32) = 4*/
					    compress_len,
					    nvram_unzip_mem_malloc, 
					    nvram_unzip_mem_free);	

	NVRAM_UNZIP_LOG3(UNZIP_RESULT, compress_len, out_size, ret);
	
    EXT_ASSERT (ret == Z_OK, ret, g_nvram_curr_lid, 0);

    /* user prepare the output buffer by themselves */
    if (*unzip_size && *unzip_buffer)
    {
        EXT_ASSERT(*unzip_size == out_size, *unzip_size, out_size, 0);
        kal_mem_cpy(*unzip_buffer, out_ptr, out_size);
    }
    else
    {
    	*unzip_size = out_size;
    	*unzip_buffer = out_ptr;
    }
}


/*****************************************************************************
* FUNCTION
*   nvram_unzip_check
* DESCRIPTION
*   To check whether the entry can be compressed
* PARAMETERS
*   entry		[IN]		the logical table
* RETURNS
*   kal_bool
*****************************************************************************/
kal_bool nvram_unzip_check(const ltable_entry_struct *entry)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
	RETURN_VAL_IF_FAIL(entry != NULL, KAL_FALSE);

	/* No data */
	if (entry->LID == 0 || 
		entry->size == 0 || 
		entry->total_records == 0)
	{
		return KAL_FALSE;
	}
	
	/* always compress custpack entry */
	if (NVRAM_IS_CATEGORY_CUSTPACK(entry->category) ||
		NVRAM_IS_ATTR_ZIP_DEFAULT(entry->attr))
	{
		return KAL_TRUE;
	}

	return KAL_FALSE;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_unzip_mem_malloc
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opaque	[IN]
 *  items		[IN]
 *  size		[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void *nvram_unzip_mem_malloc(void *opaque, kal_uint32 items, kal_uint32 size)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/
	unsigned int total_bytes;
	void *buffer_ptr;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
   if (opaque)
   {
	  items += size - size;   /// make compiler happy
   }
   total_bytes = items * size;

#if 1
   buffer_ptr = smmMallocAligned(&nvram_unzip_smm, total_bytes, 4);
#else
/* under construction !*/
#endif

   return buffer_ptr;
}


/*****************************************************************************
 * FUNCTION
 *  nvram_unzip_mem_free
 * DESCRIPTION
 *  
 * PARAMETERS
 *  opaque	[IN]
 *  address	[IN]
 * RETURNS
 *  void
 *****************************************************************************/
static void nvram_unzip_mem_free(void *opaque, void *address)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                					   */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      					   */
    /*----------------------------------------------------------------*/
   return;
}

#endif /* __NVRAM_COMPRESS_SUPPORT__ */

