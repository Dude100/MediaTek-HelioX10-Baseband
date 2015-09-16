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
 *   custom_config.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contain definition of custom component module configuration variables, and routines
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "page.h"
#include "kal_public_defs.h"
#include "custom_FeatureConfig.h"

/*************************************************************************
* FUNCTION
*  custom_config_demp_page
*
* DESCRIPTION
*  This routine configures pages for demand paging.
*
* PARAMETERS
*  page        -   returned pointer to control blocks
*  pool        -   returned pointer to page pool
*  pool_size   -   returned pointer to page pool size
*
* RETURNS
*  0 fo success; -1 for failure.
*
************************************************************************/
#if defined(__DEMAND_PAGING__)

#if defined(CONFIG_DEMAND_PAGE_SHARE_POOL_SIZE)
   #define DEMP_PAGE_SHARE_POOL_SIZE CONFIG_DEMAND_PAGE_SHARE_POOL_SIZE
#else  /* CONFIG_DEMAND_PAGE_SHARE_POOL_SIZE */

#if defined(__DEMAND_PAGING_V2__)
#if defined(MT6276) 
   #define DEMP_PAGE_SHARE_POOL_SIZE (3584 * 1024)
   #define DEMP_MIN_SHARE_POOL_SIZE (3072 * 1024)
#elif defined(MT6256)
   #define DEMP_PAGE_SHARE_POOL_SIZE (4608 * 1024)
   #define DEMP_MIN_SHARE_POOL_SIZE (3072 * 1024)
#elif defined(MT6236) || defined(MT6236B)
   #define DEMP_PAGE_SHARE_POOL_SIZE (2560 * 1024)
   #define DEMP_MIN_SHARE_POOL_SIZE (2048 * 1024)
#elif defined(MT6268) || defined(MT6268A) || defined(MT6268H) || defined(MT6268T)
   #define DEMP_PAGE_SHARE_POOL_SIZE (2560 * 1024)
   #define DEMP_MIN_SHARE_POOL_SIZE (2048 * 1024)
#elif defined(MT6255)
   #define DEMP_PAGE_SHARE_POOL_SIZE (2048 * 1024)
   #define DEMP_MIN_SHARE_POOL_SIZE (2048 * 1024)   
#else
   #define DEMP_PAGE_SHARE_POOL_SIZE (2560 * 1024)   
   #define DEMP_MIN_SHARE_POOL_SIZE (2048 * 1024)
#endif 
#else /*__DEMAND_PAGING_V2__*/
    #define DEMP_PAGE_SHARE_POOL_SIZE (2048 * 1024)
    #define DEMP_MIN_SHARE_POOL_SIZE (2048 * 1024)
#endif /*__DEMAND_PAGING_V2__*/
#endif  /* CONFIG_DEMAND_PAGE_SHARE_POOL_SIZE */

#define DEMP_PAGE_POOL_SIZE (TOTAL_MAX_LOCK_SIZE + DEMP_PAGE_SHARE_POOL_SIZE)

#if DEMP_MIN_SHARE_POOL_SIZE > DEMP_PAGE_SHARE_POOL_SIZE
    #error "Pool size is smaller than minimum size!"
#endif

#if defined (__DEMAND_PAGING_PERFORMANCE_PROFILING__)

/* define page pool */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI"
// KeTing: To support change demand page pool on the fly, set to max allowable page by default
//static __align((2 << PAGE_CLUSTER) * 1024) kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
static __align((2 << PAGE_CLUSTER) * 1024) kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_MAX_SIZE / 4];
#pragma arm section zidata
#else
//static kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
static kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_MAX_SIZE / 4];
#endif /* MTK_TARGET */

/* define the control block for pages */
//static demp_page_t DEMP_PAGE_LIST[DEMP_PAGE_POOL_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))];
static demp_page_t DEMP_PAGE_LIST[DEMP_PAGE_POOL_MAX_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))];

#else   /* __DEMAND_PAGING_PERFORMANCE_PROFILING__ */

/* define page pool */
#if defined(__MTK_TARGET__)
#pragma arm section zidata = "NONCACHEDZI"
static __align((2 << PAGE_CLUSTER) * 1024) kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#pragma arm section zidata
#else
static kal_uint32 DEMP_PAGE_POOL[DEMP_PAGE_POOL_SIZE / 4];
#endif /* MTK_TARGET */

/* define the control block for pages */
static demp_page_t DEMP_PAGE_LIST[DEMP_PAGE_POOL_SIZE >> (PAGE_SHIFT_2K + (PAGE_CLUSTER - 1))];

#endif  /* __DEMAND_PAGING_PERFORMANCE_PROFILING__ */

#endif  /* __DEMAND_PAGING__ */

kal_int32
custom_config_demp_page(kal_uint32 **list, kal_uint32 **pool, kal_uint32 *pool_size)
{
#if defined(__DEMAND_PAGING__)

   if (list != NULL) {
      *list = (kal_uint32 *)DEMP_PAGE_LIST;
   } else {
      return -1;
   }

   if (pool != NULL) {
      *pool = (kal_uint32 *)DEMP_PAGE_POOL;
   } else {
      return -1;
   }

   if (pool_size != NULL) {
      *pool_size = DEMP_PAGE_POOL_SIZE;
   } else {
      return -1;
   }

   return 0;

#else   /* __DEMAND_PAGING__ */

   return -1;

#endif  /* __DEMAND_PAGING__ */
}

