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

/*******************************************************************************
 * Filename:
 * ---------
 *   ipc_object.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Helper for object management and synchronization.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *                 HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

#ifndef __INC_IPC_OBJECT_H
#define __INC_IPC_OBJECT_H

#include "kal_public_api.h"

#include "ipc_api.h"

/*------------------------------------------------------------------------------
 * Data structure defintion.
 *----------------------------------------------------------------------------*/
#define IPC_DECLARE_OBJECT \
            kal_int32       ref_count;

#define IPC_IS_VALID_OBJECT(_object) \
            ((_object) != NULL && (_object)->ref_count > 1)

#define IPC_R_LOCK_OBJECT(_object) \
            if (IPC_IS_VALID_OBJECT(_object)) { \
                ++((_object)->ref_count); \
            } else { \
                (_object) = NULL; \
            }

#define IPC_R_UNLOCK_OBJECT(_object) \
            ASSERT((_object)); \
            ASSERT((_object)->ref_count > 1); \
            --((_object)->ref_count)

#define IPC_INIT_OBJECT_BEGIN(_object, _mask) \
            IPC_ASSERT(_object); \
            _mask = SaveAndSetIRQMask(); \
            IPC_ASSERT(_object->ref_count == 0); \
            (_object)->ref_count = 1; \
            RestoreIRQMask(_mask)

#define IPC_INIT_OBJECT_END(_object, _mask) \
            IPC_ASSERT(_object); \
            _mask = SaveAndSetIRQMask(); \
            IPC_ASSERT(_object->ref_count == 1); \
            (_object)->ref_count = 2; \
            RestoreIRQMask(_mask)

#define IPC_DEINIT_OBJECT_BEGIN(_object, _mask) \
            IPC_ASSERT(kal_if_hisr() == KAL_FALSE); \
            IPC_ASSERT(_object); \
            _mask = SaveAndSetIRQMask(); \
            IPC_ASSERT((_object)->ref_count > 1); \
            --((_object)->ref_count); \
            while ((_object)->ref_count > 1) { \
                RestoreIRQMask(_mask); \
                kal_sleep_task(IPC_DEL_OBJECT_SLEEP_TICKS); \
                _mask = SaveAndSetIRQMask(); \
            } \
            IPC_ASSERT((_object)->ref_count == 1); \
            RestoreIRQMask(_mask)

#define IPC_DEINIT_OBJECT_END(_object, _mask) \
            _mask = SaveAndSetIRQMask(); \
            IPC_ASSERT((_object)->ref_count == 1); \
            (_object)->ref_count = 0; \
            RestoreIRQMask(_mask)

#define IPC_W_LOCK_OBJECT(_object, _mask) \
            IPC_ASSERT(kal_if_hisr() == KAL_FALSE); \
            _mask = SaveAndSetIRQMask(); \
            if (IPC_IS_VALID_OBJECT(_object)) { \
                --((_object)->ref_count); \
                while ((_object)->ref_count > 1) { \
                    RestoreIRQMask(_mask); \
                    kal_sleep_task(IPC_W_LOCK_OBJECT_SLEEP_TICKS); \
                    _mask = SaveAndSetIRQMask(); \
                } \
                IPC_ASSERT((_object)->ref_count == 1); \
            } else { \
                (_object) = NULL; \
                RestoreIRQMask(_mask); \
            }

#define IPC_W_UNLOCK_OBJECT(_object, _mask) \
            IPC_ASSERT((_object)); \
            IPC_ASSERT((_object)->ref_count == 1); \
            ((_object)->ref_count) = 2; \
            RestoreIRQMask(_mask)

/* Safely convert between Read & Write lock at the same time. */
#define IPC_R_TO_W_LOCK_OBJECT(_object, _mask) \
            IPC_ASSERT(kal_if_hisr() == KAL_FALSE); \
            _mask = SaveAndSetIRQMask(); \
            if (IPC_IS_VALID_OBJECT(_object)) { \
                (_object)->ref_count -= 2; \
                while ((_object)->ref_count > 1) { \
                    RestoreIRQMask(_mask); \
                    kal_sleep_task(IPC_W_LOCK_OBJECT_SLEEP_TICKS); \
                    _mask = SaveAndSetIRQMask(); \
                } \
                IPC_ASSERT((_object)->ref_count == 1); \
            } else { \
                (_object) = NULL; \
                RestoreIRQMask(_mask); \
            }

#define IPC_W_TO_R_LOCK_OBJECT(_object, _mask) \
            IPC_ASSERT((_object)); \
            IPC_ASSERT((_object)->ref_count == 1); \
            ((_object)->ref_count) = 3; \
            RestoreIRQMask(_mask)

#endif /* __INC_IPC_OBJECT_H */
