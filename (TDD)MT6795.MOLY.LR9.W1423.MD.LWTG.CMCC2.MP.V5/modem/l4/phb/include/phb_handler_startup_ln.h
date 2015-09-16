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
 * phb_handler_startup_ln.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is declarations of startup ln handler.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _PHB_HANDLER_STARTUP_LN_H
#define _PHB_HANDLER_STARTUP_LN_H

//#include "stack_ltlcom.h"
#include "kal_public_api.h"
#include "phb_control_block.h"


#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */ 

    /* Header files should be include before this one */

#if !defined(__PHB_NO_CALL_LOG__)
    typedef enum
    {
        ERASE_LN_NONE,
        ERASE_LN_CONTINUE = 0x10,   /* To avoid conflict with READ_CONTINUE */
        COPY_LN_NONE,
        COPY_LN_READ,
        COPY_LN_READ_FILE,
        COPY_LN_WRITE,
        WRITE_LN_TYPE_SEQ
    } erase_stage_enum;

#ifdef __PHB_RECORD_LN_TYPE_SEQ__
    typedef enum
    {
        SYNC_LN_TYPE_SEQ_NONE,
        SYNC_LN_TYPE_SEQ_CONTINUE = 0x10    /* To avoid conflict with READ_CONTINUE */
    } sync_ln_type_seq_stage_enum;

    extern void phb_startup_sync_ln_type_seq(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif /* __PHB_RECORD_LN_TYPE_SEQ__ */ 

    extern void phb_startup_erase_ln(ilm_struct *ilm_ptr, control_block_type *control_block);
#endif /* !defined(__PHB_NO_CALL_LOG__) */

#if defined(__PHB_NO_CALL_LOG__)
    typedef enum
    {
        startup_ln_none,
        startup_ln_info_lnd_record_info,
        startup_ln_get_info_finish,
        startup_ln_stage_enum_total
    } startup_ln_stage_enum;

    extern void phb_no_call_log_init_ln_handler(ilm_struct *ilm_ptr, control_block_type *control_block);

#endif /* defined(__PHB_NO_CALL_LOG__) */

#if defined(__CANCEL_LOCK_POWERON__)
    extern void phb_init_me_ln_handler(void);
    extern void phb_init_me_ln_confirm(void);
#endif /* defined(__CANCEL_LOCK_POWERON__) */
#ifdef __cplusplus
}
#endif 

#endif /* _PHB_HANDLER_STARTUP_LN_H */ 


