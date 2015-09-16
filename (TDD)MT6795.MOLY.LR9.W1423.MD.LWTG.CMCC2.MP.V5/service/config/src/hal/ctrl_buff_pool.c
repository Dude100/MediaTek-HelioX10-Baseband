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
 *   ctrl_buff_pool.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains all the buffer pool related routines.
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

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_internal_api.h"
#include "stack_buff_pool.h"
#include "stack_internal_macros.h"
#include "ctrl_buff_pool.h"

/*******************************************************************************
 * Global variable
 * this variable is used in kal files
 * it should be defined in config file since it will be modified by customer in config file
 *******************************************************************************/
const unsigned int kal_min_evshed_buffer_number = KAL_MIN_EVSHED_BUFF_NUM; 
/*************************************************************************
 * Internal Globals
 *************************************************************************/
buff_pool_info_struct ctrl_buff_pool_info_g[ RPS_CREATED_CTRL_BUFF_POOLS];

/*************************************************************************
* FUNCTION
*  config_ctrl_buff_info()
*
* DESCRIPTION
*   This routine configure control buffer pool information (run time 
*   memory allocation usage)
*
* PARAMETERS
*
* RETURNS
*  None
*
* GLOBALS AFFECTED
*
*************************************************************************/
void
config_ctrl_buff_info(void)
{
   /* These constants defined in ctrl_buff_pool.h */

   ctrl_buff_pool_info_g[0].size        = CTRL_BUFF_POOL_SIZE32;
   ctrl_buff_pool_info_g[0].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE32 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32;

   ctrl_buff_pool_info_g[1].size        = CTRL_BUFF_POOL_SIZE64;
   ctrl_buff_pool_info_g[1].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE64 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE64;

   ctrl_buff_pool_info_g[2].size        = CTRL_BUFF_POOL_SIZE128;
   ctrl_buff_pool_info_g[2].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE128 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE128;

   ctrl_buff_pool_info_g[3].size        = CTRL_BUFF_POOL_SIZE256;
   ctrl_buff_pool_info_g[3].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE256 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE256;

   ctrl_buff_pool_info_g[4].size        = CTRL_BUFF_POOL_SIZE512;
   ctrl_buff_pool_info_g[4].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE512 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE512;

   ctrl_buff_pool_info_g[5].size        = CTRL_BUFF_POOL_SIZE1024;
   ctrl_buff_pool_info_g[5].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE1024 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE1024;

   ctrl_buff_pool_info_g[6].size        = CTRL_BUFF_POOL_SIZE2048;
   ctrl_buff_pool_info_g[6].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE2048 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE2048;

   ctrl_buff_pool_info_g[7].size        = CTRL_BUFF_POOL_SIZE4096;
   ctrl_buff_pool_info_g[7].no_of_buff  = NUM_CTRL_BUFF_POOL_SIZE4096 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE4096;

#if defined(__UMTS_RAT__) || defined(__LTE_RAT__)
   ctrl_buff_pool_info_g[8].size       = CTRL_BUFF_POOL_SIZE8192;
   ctrl_buff_pool_info_g[8].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE8192 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE8192;

   ctrl_buff_pool_info_g[9].size       = CTRL_BUFF_POOL_SIZE16384;
   ctrl_buff_pool_info_g[9].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE16384 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE16384;

   ctrl_buff_pool_info_g[10].size       = CTRL_BUFF_POOL_SIZE32768;
   ctrl_buff_pool_info_g[10].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE32768 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE32768;

   ctrl_buff_pool_info_g[11].size       = CTRL_BUFF_POOL_SIZE65536;
   ctrl_buff_pool_info_g[11].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE65536 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE65536;


   ctrl_buff_pool_info_g[12].size       = CTRL_BUFF_POOL_SIZE100000;
   ctrl_buff_pool_info_g[12].no_of_buff = NUM_CTRL_BUFF_POOL_SIZE100000 + NUM_CUSTOM_CTRL_BUFF_POOL_SIZE100000;

#endif /* end of defined(__UMTS_RAT__) || defined(__LTE_RAT__) */
        
} 
