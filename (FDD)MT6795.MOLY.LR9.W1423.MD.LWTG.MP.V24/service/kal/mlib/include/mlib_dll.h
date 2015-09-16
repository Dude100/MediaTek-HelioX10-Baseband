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
 *   mlib_dll.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Light weight C Data structures library:  Doubly Linked List.
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
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*********************************************************************
   (C) _____ (year of first publication) Sasken communication
   Technologies Limited, All rights reserved.
*   This file provides a template for .c files. This space
*   should be used to describe the file contents
*   Component-specific prefix : xxxx
*********************************************************************/
 
#ifndef _MLIB_DLL_H
#define _MLIB_DLL_H
/*RHR*/
#include "kal_general_types.h"
#ifndef GEN_FOR_PC
#include "stddef.h"
#endif
/*RHR*/
/*******************************************************************************
 * Data Structure definition
 *******************************************************************************/
typedef struct list_node list_node;
typedef kal_int32  (*mlib_dll_cmp_func)(const list_node *, const list_node *, void *user_para);
typedef void (*mlib_dll_cb_func)(list_node *,void *para);

#define List2Container(list_ptr,type,list_name)   \
		(type *)((char *)list_ptr - offsetof(type,list_name))

/*************************************************************************
* STRUCT
*  lcd_dll_node
*
* DESCRIPTION
*  double-linked list node
*
*************************************************************************/
struct list_node {
   list_node    *prev;
   list_node    *next;
};

/*******************************************************************************
 * Exported Function Prototypes
 *******************************************************************************/

extern kal_int32 	mlib_dll_insert_node(list_node **header, list_node *node,
																	 mlib_dll_cmp_func cmp_f,void *para);
extern kal_bool	  mlib_dll_delete_node(list_node **header, list_node *node);
extern kal_uint32	mlib_dll_delete_all_nodes(list_node **header,
																			  mlib_dll_cb_func callback_f, void *para);
extern list_node* mlib_dll_split_list(list_node **header, const list_node *cmp_node, 
																  mlib_dll_cmp_func cmp_f, void *para);
extern void		    mlib_dll_append_list(list_node **header, list_node *app_header);
extern kal_uint32 mlib_dll_traverse_all_nodes(list_node *header,
																          mlib_dll_cb_func callback_f, void *para);
extern list_node* mlib_dll_locate_node(list_node *header,list_node *cmp_node, mlib_dll_cmp_func cmp_f, void *para);
extern kal_bool   mlib_dll_is_single_node(list_node *header);
#endif /* _MLIB_DLL_H */


