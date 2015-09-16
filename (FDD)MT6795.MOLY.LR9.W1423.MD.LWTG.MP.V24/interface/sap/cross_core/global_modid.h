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
 *   global_modid.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   This file provides the task index and module index configuration.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef GLOBAL_MODULE_ID_H
#define GLOBAL_MODULE_ID_H

#include "global_modid_range.h"


MODULE_MOD_BEGIN(MOD_ID_GLOBAL_BEGIN)
MOD_NIL = MOD_ID_GLOBAL_BEGIN,
MODULE_MOD_END( MOD_ID_GLOBAL_TAIL )


MODULE_MOD_BEGIN(MOD_ID_GLOBAL_MD1_BEGIN)
#undef MODULE_ID_GLOBAL_MD1
#define MODULE_ID_GLOBAL_MD1(module) module##_MD1,
	#include "md1_module_config.h"
#undef MODULE_ID_GLOBAL_MD1
MODULE_TAG_MOD_ID_GLOBAL_MD1_TAIL,
MODULE_MOD_END( MOD_ID_GLOBAL_MD1_TAIL )


MODULE_MOD_BEGIN(MOD_ID_GLOBAL_MD2_BEGIN)
#undef MODULE_ID_GLOBAL_MD2
#define MODULE_ID_GLOBAL_MD2(module) module##_MD2,
	#include "md2_module_config.h"
#undef MODULE_ID_GLOBAL_MD2
MODULE_TAG_MOD_ID_GLOBAL_MD2_TAIL,
MODULE_MOD_END( MOD_ID_GLOBAL_MD2_TAIL )


MODULE_MOD_BEGIN(MOD_ID_GLOBAL_MD3_BEGIN)
#undef MODULE_ID_GLOBAL_MD3
#define MODULE_ID_GLOBAL_MD3(module) module##_MD3,
	#include "md3_module_config.h"
#undef MODULE_ID_GLOBAL_MD3
MODULE_TAG_MOD_ID_GLOBAL_MD3_TAIL,
MODULE_MOD_END( MOD_ID_GLOBAL_MD3_TAIL )

#endif /* GLOBAL_MODULE_ID_H */


