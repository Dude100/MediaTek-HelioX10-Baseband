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
 *   kal_nucleus_common_defs.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   It includes the definations that are common to target and
 *   debug version of KAL on Nucleus
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

#ifndef _KAL_NUCLEUS_COMMON_DEFS_H
#define _KAL_NUCLEUS_COMMON_DEFS_H

#ifdef KAL_ON_NUCLEUS

/*************************************************************************
 * Constant definition
 *************************************************************************/
/* Following defines are internal to the KAL */
/* !!! Following macros moved to kal_public_defs.h */
//#define KAL_MAX_TICKS (2715648)   /* 2048 * 26 * 51 */
//
//#define KAL_TICKS_10_MSEC           (2)         /* 10 msec */
//#define KAL_TICKS_50_MSEC           (10)        /* 50 msec */
//#define KAL_TICKS_100_MSEC          (21)        /* 100 msec */
//#define KAL_TICKS_500_MSEC          (108)       /* 500 msec */
//#define KAL_TICKS_1024_MSEC         (221)       /* 1024 msec */
//#define KAL_TICKS_1_SEC             (216)       /* 1 sec */
//#define KAL_TICKS_2_SEC            (433)       /* 2 sec */
//#define KAL_TICKS_3_SEC             (650)       /* 3 sec */
//#define KAL_TICKS_5_SEC             (1083)      /* 5 sec */
//#define KAL_TICKS_30_SEC            (6500)      /* 30 sec */
//#define KAL_TICKS_1_MIN             (13000)     /* 1 min */
//#define KAL_MSEC_64_TICKS           (295)       /* 64 ticks */
//#define KAL_MSEC_256_TICKS          (1181)      /* 256 ticks */
//
//#define ALIGNED_TIMER_MAX_DELAY 255
#define ALIGNED_TIMER_ID 0xcbcbcbcb
#define UNALIGNED_TIMER_ID 0xbcbcbcbc

/*************************************************************************
 * Type Definitions
 *************************************************************************/
/* Genenral types that are used by KAL */
typedef NU_TASK               kal_os_task_type;
typedef NU_HISR               kal_os_hisr_type;
typedef NU_QUEUE              kal_os_queue_type;
typedef NU_SEMAPHORE          kal_os_mutex_type;
typedef NU_SEMAPHORE          kal_os_sem_type;
typedef NU_EVENT_GROUP        kal_os_eventgrp_type;
typedef NU_TIMER              kal_os_timer_type;
typedef NU_PARTITION_POOL     kal_os_pool_type;

/* Function pointer types used */
/* VOID is NUCLEUS defined data-type */
typedef VOID (*kal_nu_task_func_ptr) (UNSIGNED, VOID *);
typedef VOID (*kal_nu_hisr_func_ptr) (VOID);
typedef VOID (*kal_nu_timer_func_ptr) (UNSIGNED);

typedef struct {
   struct kal_int_pool_struct*  pool_id;
   void *                       start_address;
   void *                      end_address;
} kal_buff_pool_info;

/*************************************************************************
 * Constants
 *************************************************************************/

/*************************************************************************
 * Macros With Parameters
 *************************************************************************/


#endif  /* KAL_ON_NUCLEUS */

#endif /* _KAL_NUCLEUS_COMMON_DEFS_H */


