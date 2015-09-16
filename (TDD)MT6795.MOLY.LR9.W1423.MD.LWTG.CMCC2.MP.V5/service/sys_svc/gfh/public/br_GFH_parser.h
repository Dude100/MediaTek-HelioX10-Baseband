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
 *   br_GFH_parser.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   GFH(General File Header) parser interface
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_PARSER_H__
#define __BR_GFH_PARSER_H__

#include "br_sw_types.h"
#include "br_GFH.h"

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// GFH callback function definition
//==============================================================================

typedef U32    (*CB_GFH_INTERPRETER)(void * p_gfh, void * p_arg);

//==============================================================================
// GFH parser handle 
//==============================================================================

typedef struct GFH_Callback {
    bool                m_enable;
    #if defined(WIN32)
    U16                 m_type;
    #else    
    GFH_TYPE            m_type;
    #endif
    CB_GFH_INTERPRETER  m_cb_interpreter;
    void *              m_cb_interpreter_arg;
} GFH_Callback;

#define GFH_PARSER_HANDLE_MAGIC     0x50484647  // represent for "GFHP"

typedef struct GFH_Parser_Handle {
    U32                 m_magic;
    U32                 m_cb_map_size;
    GFH_Callback       *m_p_cb_map;
    CB_GFH_INTERPRETER  m_p_cb_default_handler;
    void               *m_p_cb_default_handler_arg;
} GFH_Parser_Handle;

//==============================================================================
// Exported APIs
//==============================================================================

#if defined(__GFH_PARSER__)
// default global GFH parser handle
extern GFH_Parser_Handle     g_GFH_PARSER_HANDLE;

extern U32  GFH_Parser_Init(GFH_Parser_Handle * p_handle, U32 cb_map_size, GFH_Callback * cb_map);
extern U32  GFH_Parser_Install(GFH_Parser_Handle * p_handle, GFH_TYPE type, CB_GFH_INTERPRETER cb, void * p_arg);
extern U32  GFH_Parser_Uninstall(GFH_Parser_Handle * p_handle, GFH_TYPE type);
extern U32  GFH_Parser_Install_Default_Handler(GFH_Parser_Handle * p_handle, CB_GFH_INTERPRETER cb, void * p_arg);
extern U32  GFH_Parser_ClearAll(GFH_Parser_Handle * p_handle);
extern U32  GFH_Parser_Start(const GFH_Parser_Handle * p_handle, U32 buf_addr);
#endif

extern U32  GFH_Find(U32 buf_addr, GFH_TYPE type, void ** pp_gfh);
extern U32  GFH_FindEx(U32 buf_addr, GFH_TYPE type, void ** pp_gfh, U32 index);

#ifdef __cplusplus
}
#endif

#endif
