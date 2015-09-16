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
 *   bl_GPT.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   GPT public header
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
 
#ifndef _BOOTLOADER_GPT_H
#define _BOOTLOADER_GPT_H

#include "kal_general_types.h"

#define BL_GPT_UDELAY_INSTANCE   (1)
#define BL_GPT_USBDL_INSTANCE     (2)
#define BL_GPT_USBDL_INSTANCE2   (3)

extern void bl_drvgpt_init(void);
extern void bl_drvgpt_stop_timer(kal_uint32 num);
extern void bl_drvgpt_start_timer(kal_uint32 num);
extern void bl_drvgpt_set_timer(kal_uint32 num, kal_uint32 time, kal_uint32 mode, kal_uint32 prescaler);
extern void bl_drvgpt_udelay(kal_uint32 num, kal_uint32 udelay);
extern void bl_drvgpt_start_timeout_ms(kal_uint32 num, kal_uint32 mdelay);
extern void bl_drvgpt_start_timeout_s(kal_uint32 num, kal_uint32 sdelay);
extern kal_bool bl_drvgpt_get_timeout_status(kal_uint32 num);

#define BL_GPT_UDELAY(us)  bl_drvgpt_udelay(BL_GPT_UDELAY_INSTANCE, us)

#define BL_GPT_START_TIMEOUT_MS(ms)  bl_drvgpt_start_timeout_ms(BL_GPT_USBDL_INSTANCE, (ms))
#define BL_GPT_START_TIMEOUT_S(s)  bl_drvgpt_start_timeout_s(BL_GPT_USBDL_INSTANCE, (s))
#define BL_GPT_GET_TIMEOUT_STATUS()  bl_drvgpt_get_timeout_status(BL_GPT_USBDL_INSTANCE)

#define BL_GPT_START_TIMEOUT_S2(s)  bl_drvgpt_start_timeout_s(BL_GPT_USBDL_INSTANCE2, (s))
#define BL_GPT_GET_TIMEOUT_STATUS2()  bl_drvgpt_get_timeout_status(BL_GPT_USBDL_INSTANCE2)
#endif /* _BOOTLOADER_GPT_H */

