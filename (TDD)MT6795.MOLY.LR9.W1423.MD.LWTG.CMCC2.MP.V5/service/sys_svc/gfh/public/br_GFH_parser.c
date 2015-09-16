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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   br_GFH_parser.c
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   GFH(General File Header) parser functions 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#include "br_GFH_parser.h"
#include "br_GFH_error.h"

static U32  GFH_Internal_Parser(U32 buf_addr, const GFH_Parser_Handle * p_handle, GFH_TYPE type, void ** pp_gfh, U32 index);

#if defined(__GFH_PARSER__)

GFH_Parser_Handle     g_GFH_PARSER_HANDLE;

//==============================================================================
// local functions
//==============================================================================

__BR_STATIC U32  GFH_Parser_IsHandleInitialized(const GFH_Parser_Handle * p_handle);

#define GFH_PARSER_INSTALL_CB(p_cb, type, cb, p_arg)\
        do {\
            p_cb->m_enable             = TRUE;\
            p_cb->m_type               = type;\
            p_cb->m_cb_interpreter     = cb;\
            p_cb->m_cb_interpreter_arg = p_arg;\
        } while(0)

//==============================================================================
// GFH handle is initialized?
//==============================================================================
U32 GFH_Parser_IsHandleInitialized(const GFH_Parser_Handle * p_handle)
{
    if( NULL==p_handle || GFH_PARSER_HANDLE_MAGIC!=p_handle->m_magic )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    return B_OK;
}

//==============================================================================
// GFH init internal status
//==============================================================================
U32  GFH_Parser_Init(GFH_Parser_Handle * p_handle, U32 cb_map_size, GFH_Callback * cb_map)
{
    // check if handle is NULL
    if( NULL == p_handle )
    {
        return E_GFH_INVALID_PARAM;
    }

    if( (0==cb_map_size && NULL!=cb_map) ||
        (0!=cb_map_size && NULL==cb_map) )
    {
        return E_GFH_INVALID_PARAM;
    }

    // initialized the handle
    p_handle->m_magic = GFH_PARSER_HANDLE_MAGIC;
    p_handle->m_cb_map_size = cb_map_size;
    p_handle->m_p_cb_map = cb_map;
    p_handle->m_p_cb_default_handler = NULL;
    p_handle->m_p_cb_default_handler_arg = NULL;
    
    // clear all callbacks 
    GFH_Parser_ClearAll(p_handle);

    return B_OK;
}

//==============================================================================
// GFH install callback by type 
//==============================================================================
U32  GFH_Parser_Install(GFH_Parser_Handle * p_handle, GFH_TYPE type, CB_GFH_INTERPRETER cb, void * p_arg)
{
    U32 i;
    GFH_Callback   *p_cb;

    if( B_OK != GFH_Parser_IsHandleInitialized(p_handle) )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    // check input arguments 
    if( NULL == cb )
    {
        return E_GFH_INVALID_PARAM;
    }

    // to guarantee that we won't have multiple callback entries for
    // the same GFH type, we have to check whether we could overwrite
    // an existing entry first
    for(i=0; i<p_handle->m_cb_map_size; i++)
    {
        p_cb = (p_handle->m_p_cb_map + i);
        if( p_cb->m_type == type )
        {
            GFH_PARSER_INSTALL_CB(p_cb, type, cb, p_arg);
            return B_OK;
        }
    }

    // then we can insert an new entry if there's room for us to do so
    for(i=0; i<p_handle->m_cb_map_size; i++)
    {
        p_cb = (p_handle->m_p_cb_map + i);
        if( FALSE == p_cb->m_enable )
        {
            GFH_PARSER_INSTALL_CB(p_cb, type, cb, p_arg);
            return B_OK;
        }
    }

    return E_GFH_CALLBACK_MAP_IS_FULL;
}

//==============================================================================
// GFH install default callback which will be used if no proper one is matched
//==============================================================================
U32  GFH_Parser_Install_Default_Handler(GFH_Parser_Handle * p_handle, CB_GFH_INTERPRETER cb, void * p_arg)
{
    if( B_OK != GFH_Parser_IsHandleInitialized(p_handle) )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    // check input arguments 
    if( NULL == cb )
    {
        return E_GFH_INVALID_PARAM;
    }

    p_handle->m_p_cb_default_handler = cb;
    p_handle->m_p_cb_default_handler_arg = p_arg;

    return B_OK;
}

//==============================================================================
// GFH un-install callback by type
//==============================================================================
U32  GFH_Parser_Uninstall(GFH_Parser_Handle * p_handle, GFH_TYPE type)
{
    U32 i;
    GFH_Callback   *p_cb;

    if( B_OK != GFH_Parser_IsHandleInitialized(p_handle) )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    for(i=0; i<p_handle->m_cb_map_size; i++)
    {
        p_cb = (p_handle->m_p_cb_map + i);
        if( p_cb->m_type == type )
        {
            p_cb->m_enable = FALSE;
            return B_OK;
        }
    }

    return E_GFH_CALLBACK_NOT_EXIST;
}

//==============================================================================
// GFH clear all callbacks 
//==============================================================================
U32  GFH_Parser_ClearAll(GFH_Parser_Handle * p_handle)
{
    U32 i;

    if( B_OK != GFH_Parser_IsHandleInitialized(p_handle) )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    // remove all callbacks
    for(i=0; i<p_handle->m_cb_map_size; i++)
    {
        // un-install callback 
        p_handle->m_p_cb_map[i].m_enable = FALSE;
    }

    return B_OK;
}

//==============================================================================
// GFH parse
//==============================================================================
U32  GFH_Parser_Start(const GFH_Parser_Handle * p_handle, U32 buf_addr)
{
    if( B_OK != GFH_Parser_IsHandleInitialized(p_handle) )
    {
        return E_GFH_HANDLE_NOT_INIT;
    }

    // callback mode, index is ignored 
    return GFH_Internal_Parser(buf_addr, p_handle, (GFH_TYPE)0, NULL, 0);
}

#endif

//==============================================================================
// GFH search by type
//==============================================================================
U32  GFH_Find(U32 buf_addr, GFH_TYPE type, void ** pp_gfh)
{
    // only search for the 1st matched GFH 
    return GFH_Internal_Parser(buf_addr, NULL, type, pp_gfh, 0);
}

//==============================================================================
// GFH search by type with multiple instances search 
//==============================================================================
U32  GFH_FindEx(U32 buf_addr, GFH_TYPE type, void ** pp_gfh, U32 index)
{
    U32 status;

    if( NULL == pp_gfh )
    {
        return E_GFH_INVALID_PARAM;
    }

    *pp_gfh = NULL;

    status = GFH_Internal_Parser(buf_addr, NULL, type, pp_gfh, index);

    return status;
}

//==============================================================================
// GFH search by type
//==============================================================================
static U32  GFH_Internal_Parser(U32 buf_addr, const GFH_Parser_Handle * p_handle, GFH_TYPE type, void ** pp_gfh, U32 index)
{
#if defined(__GFH_PARSER__)
    const GFH_Callback  *p_cb;
    U32             i;    
#endif
    GFH_FILE_INFO_v1    *p_gfh_file_info;
    GFH_Header     *p_gfh_hdr;
    GFH_End        *p_gfh_end;
    U32             status;
    U32             offset;
    U32             occur_index = 0;
    U32             next_gfh_offset;
    U32             file_content_offset;
    bool            bEnableCallbackMap = FALSE;
    bool            bAnyCallbackInvoked = FALSE;

    // check if use callback map or just a single search?
    if( NULL != p_handle )
    {
        bEnableCallbackMap = TRUE;
    }

    // check data addr 
    if( 0 != (buf_addr&(4-1)))
    {
        status = E_GFH_BUF_ADDR_NOT_32BITS_ALIGNED;
        return status;
    }

    // perform FILE_INFO basic check 
    p_gfh_file_info = (GFH_FILE_INFO_v1 *)buf_addr;
    status = GFH_FILE_INFO_BasicCheck(p_gfh_file_info);
    if( E_ERROR <= status )
    {
        return status;
    }
    file_content_offset = p_gfh_file_info->m_content_offset;

    // search target GFH 
    offset = 0;
    while( offset < file_content_offset )
    {
        p_gfh_hdr = (GFH_Header *)(buf_addr+offset);
        p_gfh_end = (GFH_End *)p_gfh_hdr;

        // stop when end mark is found
        if( GFH_HDR_MAGIC_END_MARK == p_gfh_end->m_magic_end )
        {
            break;
        }

        // check if GFH Header exist 
        if( GFH_HDR_MAGIC != GFH_GET_MAGIC(p_gfh_hdr->m_magic_ver) )
        {
            return E_GFH_NOT_FOUND;
        }

        // check if size is valid 
        next_gfh_offset = (offset+p_gfh_hdr->m_size);
        if( (sizeof(GFH_Header) > p_gfh_hdr->m_size)
         || (file_content_offset < next_gfh_offset)
        ) {
            return E_GFH_INVALID_SIZE;
        }

        // callback or search target type? 
#if defined(__GFH_PARSER__)
        if(bEnableCallbackMap)
        {
            for(i=0; i<p_handle->m_cb_map_size; i++)
            {
                p_cb = (p_handle->m_p_cb_map + i);

                if( p_cb->m_enable && (p_cb->m_type == p_gfh_hdr->m_type) )
                {
                    status = p_cb->m_cb_interpreter(p_gfh_hdr, p_cb->m_cb_interpreter_arg);
                    // if callback return error, stop parsing 
                    if( E_ERROR <= status )
                    {
                        return status;
                    }

                    bAnyCallbackInvoked = TRUE;
                    break;
                }
            }

            //No callback found but the default handler exists
            if(i==p_handle->m_cb_map_size && p_handle->m_p_cb_default_handler)
            {
                status = p_handle->m_p_cb_default_handler(p_gfh_hdr, p_handle->m_p_cb_default_handler_arg);
                // if callback return error, stop parsing 
                if( E_ERROR <= status )
                {
                    return status;
                }
                bAnyCallbackInvoked = TRUE;
            }
        }
        else
#endif 
        {
            // check if type is matched 
            if( type == p_gfh_hdr->m_type )
            {
                // check occurrence index for multiple instances searching 
                if( occur_index == index )
                {
                    // matched 
                    *pp_gfh = p_gfh_hdr;
                    return B_OK;
                }
                else
                {
                    // not matched, increase occurrence count and continue to search 
                    occur_index++;
                }
            }
        }

        // update offset 
        offset = next_gfh_offset;
    }

    if( bEnableCallbackMap && bAnyCallbackInvoked )
    {
        return B_OK;
    }

    return E_GFH_NOT_FOUND;
}
