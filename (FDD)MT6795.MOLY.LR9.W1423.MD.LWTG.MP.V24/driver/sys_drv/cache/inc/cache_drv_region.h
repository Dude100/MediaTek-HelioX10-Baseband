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
 *   cache_drv_region.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the memory region of each APIs in Cache.c
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
 *****************************************************************************/

#ifndef _CACHE_API_REGION_H
#define _CACHE_API_REGION_H
/* Common region pragma setting */
#define INSTRUCTION_TCM   __attribute__((section("INTSRAM_ROCODE")))
#define DATA_TCM_ZI       __attribute__((section("INTSRAM_ZI"), zero_init))
#define DATA_TCM_RW       __attribute__((section("INTSRAM_RW")))
#define DEFAULT_REGION           

/* Defines each API region by project */
#if defined(MT6280)
/* Functions */
#define CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT    DEFAULT_REGION
#define CLEAN_DCACHE_PLACEMENT                          INSTRUCTION_TCM
#define DYNAMIC_SWITCH_CACHEABLE_REGION_PLACEMENT       INSTRUCTION_TCM
#define INVALIDATE_DCACHE_PLACEMENT                     INSTRUCTION_TCM
#define IS_PREDEF_DYNA_C_REGION_PLACEMENT               INSTRUCTION_TCM


#else
/* Functions */
#define CLEAN_AND_INVALIDATE_DCACHE_REGION_PLACEMENT    DEFAULT_REGION
#define CLEAN_DCACHE_PLACEMENT                          DEFAULT_REGION
#define DYNAMIC_SWITCH_CACHEABLE_REGION_PLACEMENT       DEFAULT_REGION
#define INVALIDATE_DCACHE_PLACEMENT                     DEFAULT_REGION
#define IS_PREDEF_DYNA_C_REGION_PLACEMENT               DEFAULT_REGION


#endif

#endif
