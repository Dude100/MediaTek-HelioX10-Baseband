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
 * nvram_data_items.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *    This file contains `vendor' defined logical data items stored in NVRAM.
 *    These logical data items are used in object code of Protocol Stack software.
 *
 *    As for customizable logical data items, they are defined in nvram_user_config.c
 *
 * Author:
 * -------
 * -------
 * -------
 *
 *============================================================================
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef NVRAM_NOT_PRESENT

#ifdef __AST_TL1_TDD__
#define __AST_TL1_TDD_RF_PARAMETER_DEFINE__
#ifdef __AST_TL1_TDD_RF_TIMESEQ_SUPPORT__
#define __AST_TL1_TDD_RF_TIMESEQ_DEFINE__
#endif
#define __3G_TDD_MIPI_DEFINE__
#define __3G_TDD_DRDI_DEFINE__
#endif // __AST_TL1_TDD__
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_general_types.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"
#include "ex_item.h"

#include "nvram_defs.h"
#include "nvram_enums.h"
#include "nvram_data_items.h"
#include "nvram_editor_data_item.h"
#include "custom_nvram_config.h"
#include "custom_nvram_sec.h"
#include "custom_nvram_restore.h"
#include "custom_nvram_config.h"
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
#include "nvram_default_value.h"
#endif

#if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
#include "custom_port_setting.h"
#endif

#include "tst.h"

#if defined(__UMTS_RAT__) && defined(__MTK_UL1_FDD__)
#include "ul1cal.h"
#endif /* __UMTS_RAT__ && __MTK_UL1_FDD__ */

#ifdef __AST_TL1_TDD__
#include "tl1cal_ast.h"
#include "t12193.h"
#include "tl1d_custom_rf.h"
#include "tl1d_custom_drdi.h"
#endif // __AST_TL1_TDD__

#include "l1cal.h"
#if defined(__WIFI_SUPPORT__)
#include "wndrv_cal.h"
#endif



#include "dcl.h"

#include "custom_gprs_pdp_default_qos_config.h"

#if(defined(ISP_SUPPORT))
#include "drv_sw_features_isp.h"
#include "camera_tuning_para.h"
#endif

#include "nvram_default_audio.h"            /* NVRAM_EF_CUST_ACOUSTIC_DATA_SIZE */
#ifdef __GAIN_TABLE_SUPPORT__
#include "gain_table.h"
#endif /* __GAIN_TABLE_SUPPORT__ */

#include "adc_channel.h"

#if !defined(__NVRAM_SUPPORT_CUSTPACK__)// && !defined(__L1_STANDALONE__)
//    #include "nvram_cust_pack.c"
#if !defined(EXTERNAL_MMI)
    extern kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[];
#endif

extern kal_uint8 COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[];    

#ifdef __CPHS__
    extern kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[];
#endif
    
extern kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[];
extern kal_uint8 COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[];

#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    extern nvram_ef_mobile_broadband_provision_context_struct COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[];
#endif

#ifdef __MEDIATEK_SMART_QOS__
    extern nvram_ef_msq_list_struct NVRAM_EF_MSQ_LIST_DEFAULT[] ;
#endif

#if defined (__UL1_HS_PLATFORM__) || defined (__UL1_HS_PLUS_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)

            #include "ul1_nvram_def.h"
            extern U_sUl1dRfCustomInputData COMMON_NVRAM_EF_UL1_3G_RF_PARAMETER_DEFAULT[];

    #endif
#endif

#if defined (__UL1_PLATFORM__)
    #if defined (__MTK_UL1_FDD__)
        #include "ul1_nvram_def.h"
        extern nvram_ef_ul1_rf_custpack_data_select_struct COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT[];
        extern nvram_ef_ul1_rf_custom_data_struct COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT[];
    #endif
#endif


#endif  /* __MMI_FMI__*/
/*The chip doesn't support A5/3*/
#if defined( MT6208) || defined( MT6205) || defined( MT6218) || defined( MT6219) || \
    defined( MT6217) || defined( MT6227) || defined( MT6226) || defined( MT6228) || \
    defined(MT6205B) || defined(MT6226M) || defined(MT6218B)
#define __NO_SUPPORT_A5_3__
#endif

extern void nvram_get_L1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);

extern void nvram_get_eL1_default_value_to_write(nvram_lid_enum lid, kal_uint8 *buffer, kal_uint16 buffer_size);

#ifdef __UMTS_FDD_MODE__
/*
        3G multiband support
bit     |	8     7    6    5    4    3    2    1
  |-------------------------------------------
byte 0  | VIII  VII  VI   V    IV	  III  II   I
  |-------------------------------------------
byte 1  |                                X    IX

*/
typedef enum
{
    Support_UMTS_BAND_I       = 0x01,
    Support_UMTS_BAND_II      = 0x02,
    Support_UMTS_BAND_III     = 0x04,
    Support_UMTS_BAND_IV      = 0x08,
    Support_UMTS_BAND_V       = 0x10,
    Support_UMTS_BAND_VI      = 0x20,
    Support_UMTS_BAND_VII     = 0x40,
    Support_UMTS_BAND_VIII    = 0x80,
    Support_UMTS_BAND_IX      = 0x01,
    Support_UMTS_BAND_X       = 0x02,
    Support_UMTS_BAND_XI      = 0x04,
    Support_UMTS_BAND_XII     = 0x08,
    Support_UMTS_BAND_XIII    = 0x10,
    Support_UMTS_BAND_XIV     = 0x20,
    Support_UMTS_BAND_XV      = 0x40,
    Support_UMTS_BAND_XVI     = 0x80,
    Support_UMTS_BAND_XVII    = 0x01,
    Support_UMTS_BAND_XVIII   = 0x02,
    Support_UMTS_BAND_XIX     = 0x04,
    Support_UMTS_BAND_XX      = 0x08,
    Support_UMTS_BAND_XXI     = 0x10,
    Support_UMTS_BAND_XXII    = 0x20,
    Support_UMTS_BAND_XXIII   = 0x40,
    Support_UMTS_BAND_XXIV    = 0x80,
    Support_UMTS_BAND_XXV     = 0x01,
    Support_UMTS_BAND_XXVI    = 0x02,
    Support_UMTS_BAND_XXVII   = 0x04,
    Support_UMTS_BAND_XXVIII  = 0x08,
    Support_UMTS_BAND_XXIX    = 0x10,
    Support_UMTS_BAND_XXX     = 0x20,
    Support_UMTS_BAND_XXXI    = 0x40,
    Support_UMTS_BAND_XXXII   = 0x80
}umts_band_nvram_bitmask_enum;
#endif

#ifdef __UMTS_TDD128_MODE__
typedef enum
{
    Support_UMTS_BAND_A       = 0x01,
    Support_UMTS_BAND_B      = 0x02,
    Support_UMTS_BAND_C     = 0x04,
    Support_UMTS_BAND_D      = 0x08,
    Support_UMTS_BAND_E       = 0x10,
    Support_UMTS_BAND_F      = 0x20
}umts_band_nvram_bitmask_enum;
#endif
/**
 * Steps of defining logical data item:
 * 1> Define LID of new logical data item into `nvram_lid_core_enum' in
 *    nvram_data_items.h
 * 2> Define two constants: SIZE and TOTAL, in nvram_data_items.h
 * 3> Define default value of that new logical data item.
 * 4> Define attributes of that new logical data item into
 *    `logical_data_item_table_core'
 * 5> Change NVRAM_TOTAL_LID_VENDOR in nvram_user_defs.h
 * 6> Add structure defination in nvram_editor_data_item.h
 * 7> Add bit-level description in nvram_editor_data_item.h
 * 8> Change version number CODED_DATA_VERSION in nvram_user_config.c
 *
 * Note that multiple copied attribute DOES NOT support for
 * near fixed logical data items.
 */

/**
 * Step 3:
 * Define necessary default values for each logical data item.
 */

kal_uint8 const NVRAM_EF_ZERO_DEFAULT[] = { 0x00 };
kal_uint8 const NVRAM_EF_FF_DEFAULT[] = { 0xFF };

static kal_uint8 const NVRAM_EF_CFU_FLAG_DEFAULT[] = {
                  0x55, 0x55
};

static kal_uint8 const NVRAM_EF_MM_LOCIGPRS_DEFAULT[] = {
    0x00, //rplmn_rat
    0x00, //num_of_eq_plmn
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[0]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[1]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[2]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[3]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[4]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[5]
#ifdef __REL6__
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[6]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[7]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[8]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[9]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[10]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[11]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[12]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[13]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[14]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[15]
#endif
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //nvram_locigprs
};


nvram_ef_nwsel_data_struct const COMMON_NVRAM_EF_NWSEL_DATA_DEFAULT[] =
{
    0x00, //rplmn_rat
    0x00, //num_of_eq_plmn
    {
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[0]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[1]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[2]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[3]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[4]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[5]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[6]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[7]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[8]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[9]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[10]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[11]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[12]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[13]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //eq_plmn[14]
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f  //eq_plmn[15]
    }
#if defined(__CSG_SUPPORT__) || defined (UNIT_TEST)/* CSG R9 */
    ,
    {
    0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f, //csg_previous_rplmn
    0x00                               //csg_previous_rplmn_rat
    }
    ,
    0x00                               //csg_id   
#endif
    ,
    {
    /*recovery timer, little endian*/
    /*SGLTE project: if the default recovery timer changed, both modem1 & modem2 shall be affected*/
#ifdef __SGLTE__
    0xb4,  /*1, 180s, give the enough timer to sniffer @CMCC case 4.3.3/4.1.3*/
#else
    0x14,  /*1, 20s*/
#endif
    0x14,  /*2, 20s*/
    0x14,  /*3, 20s*/
    0x14,  /*4, 20s*/
    0x14,  /*5, 20s*/
    0x14,  /*6, 20s*/
    0x1E,  /*7, 30s*/
    0x1E,  /*8, 30s*/
    0x1E,  /*9, 30s*/
    0x1E,  /*10, 30s*/
    0x1E,  /*11, 30s*/
    0x1E,  /*12, 30s*/
    0x3C,  /*13, 60s*/
    0x3C,  /*14, 60s*/
    0x3C,  /*15, 60s*/
    0x3C,  /*16, 60s*/
    0x3C,  /*17, 60s*/
    0x3C,  /*18, 60s*/
    0x78   /*19, 120s*/
    }
    #ifdef __UE_EFOPLMN__
    ,    
    {0x00,0x00}, // version
    272,   // OPLMN_entry	
    {
    0x2, 0xF2, 0x50, 0x80, 0x80, 
    0x2, 0xF4, 0x40, 0x80, 0x80, 
    0x2, 0xF6, 0x10, 0x80, 0x80, 
    0x2, 0xF8, 0x1, 0x80, 0x80, 
    0x12, 0xF2, 0x10, 0x0, 0x80, 
    0x12, 0xF3, 0x30, 0x0, 0x80, 
    0x12, 0xF4, 0x10, 0x80, 0x80, 
    0x12, 0xF6, 0x7, 0x80, 0x80, 
    0x12, 0xF8, 0x9, 0x0, 0x80, 
    0x12, 0xF9, 0x1, 0x80, 0x80, 
    0x12, 0xF9, 0x20, 0x80, 0x80, 
    0x12, 0xF9, 0x10, 0x80, 0x80, 
    0x22, 0xF0, 0x20, 0x0, 0x80, 
    0x22, 0xF0, 0x50, 0x80, 0x80, 
    0x22, 0xF0, 0x30, 0x0, 0x80, 
    0x22, 0xF2, 0x5, 0x0, 0x80, 
    0x22, 0xF2, 0x1, 0x80, 0x80, 
    0x22, 0xF2, 0x88, 0x80, 0x80, 
    0x22, 0xF6, 0x10, 0x80, 0x80, 
    0x22, 0xF8, 0x10, 0x80, 0x80, 
    0x32, 0xF0, 0x30, 0x80, 0x80, 
    0x32, 0xF1, 0x10, 0x80, 0x80, 
    0x32, 0xF2, 0x10, 0x80, 0x80, 
    0x32, 0xF4, 0x51, 0x80, 0x80, 
    0x32, 0xF4, 0x30, 0x80, 0x80, 
    0x32, 0xF4, 0x85, 0x0, 0x80, 
    0x32, 0xF8, 0x10, 0x80, 0x80, 
    0x42, 0xF0, 0x80, 0x80, 0x80, 
    0x42, 0xF0, 0x70, 0x80, 0x80, 
    0x42, 0xF2, 0x10, 0x80, 0x80, 
    0x42, 0xF4, 0x50, 0x80, 0x80, 
    0x42, 0xF6, 0x20, 0x80, 0x80, 
    0x42, 0xF7, 0x50, 0x80, 0x80, 
    0x42, 0xF8, 0x20, 0x80, 0x80, 
    0x52, 0xF0, 0x10, 0x80, 0x80, 
    0x52, 0xF5, 0x10, 0x0, 0x80, 
    0x52, 0xF5, 0x60, 0x0, 0x80, 
    0x52, 0xF5, 0x70, 0x80, 0x0, 
    0x52, 0xF7, 0x20, 0x0, 0x80, 
    0x52, 0xF7, 0x40, 0x80, 0x80, 
    0x52, 0xF9, 0x10, 0x0, 0x80, 
    0x62, 0xF0, 0x10, 0x80, 0x80, 
    0x62, 0xF2, 0x20, 0x80, 0x80, 
    0x62, 0xF6, 0x10, 0x80, 0x80, 
    0x62, 0xF8, 0x10, 0x80, 0x80, 
    0x72, 0xF0, 0x77, 0x80, 0x80, 
    0x72, 0xF2, 0x10, 0x80, 0x80, 
    0x72, 0xF4, 0x20, 0x0, 0x80, 
    0x72, 0xF6, 0x20, 0x0, 0x80, 
    0x72, 0xF8, 0x10, 0x80, 0x80, 
    0x82, 0xF0, 0x10, 0x80, 0x80, 
    0x82, 0xF0, 0x1, 0x80, 0x80, 
    0x82, 0xF2, 0x20, 0x0, 0x80, 
    0x82, 0xF3, 0x50, 0x80, 0x80, 
    0x82, 0xF3, 0x1, 0x80, 0x80, 
    0x82, 0xF4, 0x10, 0x80, 0x80, 
    0x82, 0xF6, 0x20, 0x0, 0x80, 
    0x82, 0xF6, 0x30, 0x0, 0x80, 
    0x82, 0xF8, 0x10, 0x0, 0x80, 
    0x92, 0xF0, 0x10, 0x0, 0x80, 
    0x92, 0xF2, 0x10, 0x0, 0x80, 
    0x92, 0xF3, 0x4, 0x0, 0x80, 
    0x92, 0xF4, 0x30, 0x0, 0x80, 
    0x92, 0xF5, 0x50, 0x0, 0x80, 
    0x92, 0xF7, 0x10, 0x0, 0x80, 
    0x92, 0xF7, 0x30, 0x80, 0x80, 
    0x3, 0x2, 0x16, 0x80, 0x0, 
    0x3, 0x2, 0x22, 0x80, 0x0, 
    0x13, 0x0, 0x62, 0x0, 0x80, 
    0x13, 0x0, 0x14, 0x80, 0x80, 
    0x13, 0x0, 0x83, 0x80, 0x80, 
    0x13, 0x0, 0x74, 0x80, 0x80, 
    0x33, 0x4, 0x30, 0x0, 0x80, 
    0x33, 0x4, 0x20, 0x80, 0x80, 
    0x33, 0x8, 0x50, 0x0, 0x80, 
    0x43, 0xF0, 0x2, 0x0, 0x80, 
    0x43, 0x2, 0x6, 0x0, 0x80, 
    0x43, 0x4, 0x29, 0x0, 0x80, 
    0x43, 0x6, 0x41, 0x0, 0x80, 
    0x43, 0x8, 0x71, 0x80, 0x80, 
    0x53, 0xF0, 0x10, 0x0, 0x80, 
    0x53, 0x2, 0x11, 0x0, 0x80, 
    0x53, 0x4, 0x68, 0x0, 0x80, 
    0x53, 0x6, 0x11, 0x0, 0x80, 
    0x53, 0x8, 0x11, 0x0, 0x80, 
    0x63, 0x0, 0x11, 0x0, 0x80, 
    0x63, 0xF2, 0x96, 0x0, 0x80, 
    0x63, 0xF3, 0x10, 0x80, 0x80, 
    0x63, 0xF3, 0x20, 0x0, 0x80, 
    0x63, 0xF4, 0x93, 0x0, 0x80, 
    0x63, 0x5, 0x48, 0x0, 0x80, 
    0x63, 0x6, 0x11, 0x0, 0x80, 
    0x63, 0xF8, 0x10, 0x0, 0x80, 
    0x73, 0xF0, 0x20, 0x80, 0x80, 
    0x73, 0xF0, 0x40, 0x0, 0x80, 
    0x73, 0x4, 0x31, 0x0, 0x80, 
    0x73, 0x6, 0x53, 0x0, 0x80, 
    0x4, 0xF0, 0x40, 0x80, 0x80, 
    0x4, 0xF1, 0x10, 0x0, 0x80, 
    0x4, 0xF2, 0x77, 0x0, 0x80, 
    0x4, 0xF4, 0x24, 0x80, 0x80, 
    0x4, 0xF4, 0x96, 0x0, 0x80, 
    0x4, 0xF4, 0x11, 0x0, 0x80, 
    0x4, 0xF4, 0x86, 0x0, 0x80, 
    0x4, 0xF4, 0x2, 0x0, 0x80, 
    0x4, 0xF4, 0x3, 0x0, 0x80, 
    0x4, 0xF4, 0x72, 0x0, 0x80, 
    0x4, 0xF4, 0x50, 0x0, 0x80, 
    0x4, 0xF4, 0x34, 0x0, 0x80, 
    0x4, 0xF4, 0x64, 0x0, 0x80, 
    0x14, 0xF0, 0x30, 0x0, 0x80, 
    0x14, 0xF2, 0x2, 0x0, 0x80, 
    0x14, 0xF2, 0x5, 0x80, 0x80, 
    0x14, 0xF3, 0x20, 0x80, 0x80, 
    0x14, 0xF5, 0x30, 0x0, 0x80, 
    0x14, 0xF6, 0x10, 0x0, 0x80, 
    0x14, 0xF6, 0x30, 0x0, 0x80, 
    0x14, 0xF7, 0x20, 0x0, 0x80, 
    0x14, 0xF8, 0x2, 0x0, 0x80, 
    0x14, 0xF9, 0x20, 0x80, 0x80, 
    0x14, 0xF9, 0x30, 0x0, 0x80, 
    0x24, 0xF0, 0x10, 0x80, 0x80, 
    0x24, 0xF1, 0x20, 0x0, 0x80, 
    0x24, 0xF2, 0x20, 0x0, 0x80, 
    0x24, 0xF4, 0x20, 0x80, 0x80, 
    0x24, 0xF5, 0x10, 0x80, 0x80, 
    0x24, 0xF5, 0x20, 0x80, 0x80, 
    0x24, 0xF5, 0x50, 0x0, 0x80, 
    0x24, 0xF6, 0x20, 0x80, 0x80, 
    0x24, 0xF6, 0x40, 0x80, 0x80, 
    0x24, 0xF7, 0x20, 0x80, 0x80, 
    0x24, 0xF8, 0x99, 0x0, 0x80, 
    0x24, 0xF9, 0x10, 0x0, 0x80, 
    0x34, 0xF2, 0x11, 0x0, 0x80, 
    0x34, 0xF4, 0x50, 0x0, 0x80, 
    0x34, 0xF6, 0x20, 0x0, 0x80, 
    0x34, 0xF7, 0x10, 0x0, 0x80, 
    0x34, 0xF8, 0x10, 0x0, 0x80, 
    0x44, 0xF0, 0x1, 0x80, 0x0, 
    0x54, 0xF0, 0x50, 0x80, 0x0, 
    0x54, 0xF0, 0x80, 0x80, 0x0, 
    0x54, 0xF2, 0x20, 0x0, 0x80, 
    0x54, 0xF4, 0x30, 0x80, 0x80, 
    0x54, 0xF4, 0x40, 0x0, 0x80, 
    0x54, 0xF5, 0x10, 0x80, 0x80, 
    0x54, 0xF6, 0x20, 0x80, 0x80, 
    0x54, 0xF6, 0x90, 0x0, 0x80, 
    0x54, 0xF7, 0x80, 0x0, 0x80, 
    0x64, 0xF0, 0x10, 0x80, 0x80, 
    0x64, 0xF6, 0x79, 0x0, 0x80, 
    0x64, 0xF6, 0x99, 0x0, 0x80, 
    0x64, 0xF6, 0x39, 0x0, 0x80, 
    0x74, 0xF0, 0x10, 0x0, 0x80, 
    0x74, 0xF2, 0x20, 0x80, 0x80, 
    0x5, 0xF2, 0x21, 0x80, 0x80, 
    0x5, 0xF5, 0x30, 0x80, 0x80, 
    0x5, 0xF5, 0x1, 0x0, 0x80, 
    0x15, 0xF0, 0x10, 0x0, 0x80, 
    0x15, 0xF0, 0x1, 0x80, 0x80, 
    0x15, 0xF4, 0x20, 0x0, 0x80, 
    0x15, 0xF5, 0x30, 0x0, 0x80, 
    0x15, 0xF5, 0x50, 0x0, 0x80, 
    0x25, 0xF0, 0x99, 0x0, 0x80, 
    0x25, 0xF5, 0x50, 0x0, 0x80, 
    0x25, 0xF5, 0x10, 0x0, 0x80, 
    0x25, 0xF5, 0x20, 0x0, 0x80, 
    0x25, 0xF8, 0x20, 0x80, 0x0, 
    0x35, 0xF0, 0x10, 0x80, 0x80, 
    0x35, 0xF7, 0x30, 0x0, 0x80, 
    0x35, 0xF9, 0x88, 0x0, 0x80, 
    0x45, 0xF0, 0x10, 0x0, 0x80, 
    0x45, 0xF1, 0x50, 0x0, 0x80, 
    0x45, 0xF2, 0x10, 0x0, 0x80, 
    0x45, 0x4, 0x11, 0x0, 0x80, 
    0x45, 0xF6, 0x10, 0x0, 0x80, 
    0x45, 0xF7, 0x2, 0x0, 0x80, 
    0x45, 0xF8, 0x10, 0x0, 0x80, 
    0x45, 0xF9, 0x0, 0x0, 0x80, 
    0x55, 0xF0, 0x10, 0x0, 0x80, 
    0x55, 0xF2, 0x8, 0x0, 0x80, 
    0x6, 0xF2, 0x20, 0x80, 0x80, 
    0x6, 0xF2, 0x30, 0x80, 0x80, 
    0x6, 0xF3, 0x30, 0x0, 0x80, 
    0x6, 0xF3, 0x20, 0x0, 0x80, 
    0x6, 0xF4, 0x10, 0x0, 0x80, 
    0x6, 0xF4, 0x0, 0x0, 0x80, 
    0x6, 0xF5, 0x20, 0x0, 0x80, 
    0x6, 0xF6, 0x10, 0x0, 0x80, 
    0x6, 0xF7, 0x40, 0x80, 0x80, 
    0x6, 0xF8, 0x10, 0x0, 0x80, 
    0x6, 0xF9, 0x1, 0x0, 0x80, 
    0x16, 0xF0, 0x20, 0x0, 0x80, 
    0x16, 0xF1, 0x40, 0x0, 0x80, 
    0x16, 0xF2, 0x20, 0x0, 0x80, 
    0x16, 0xF3, 0x20, 0x0, 0x80, 
    0x16, 0xF4, 0x30, 0x0, 0x80, 
    0x16, 0xF4, 0x20, 0x0, 0x80, 
    0x16, 0xF5, 0x30, 0x0, 0x80, 
    0x16, 0xF6, 0x30, 0x0, 0x80, 
    0x16, 0xF6, 0x20, 0x0, 0x80, 
    0x16, 0xF7, 0x30, 0x0, 0x80, 
    0x16, 0xF8, 0x10, 0x0, 0x80, 
    0x16, 0xF8, 0x70, 0x0, 0x80, 
    0x16, 0xF9, 0x10, 0x0, 0x80, 
    0x26, 0xF0, 0x10, 0x0, 0x80, 
    0x26, 0xF1, 0x6, 0x0, 0x80, 
    0x26, 0xF2, 0x10, 0x0, 0x80, 
    0x26, 0xF3, 0x20, 0x0, 0x80, 
    0x26, 0xF4, 0x10, 0x0, 0x80, 
    0x26, 0xF5, 0x10, 0x0, 0x80, 
    0x26, 0xF6, 0x10, 0x0, 0x80, 
    0x26, 0xF7, 0x30, 0x0, 0x80, 
    0x26, 0xF8, 0x30, 0x0, 0x80, 
    0x26, 0xF9, 0x10, 0x0, 0x80, 
    0x36, 0xF0, 0x20, 0x0, 0x80, 
    0x36, 0xF1, 0x40, 0x80, 0x80, 
    0x36, 0xF2, 0x20, 0x0, 0x80, 
    0x36, 0xF3, 0x10, 0x0, 0x80, 
    0x36, 0xF4, 0x10, 0x0, 0x80, 
    0x36, 0xF5, 0x31, 0x0, 0x80, 
    0x36, 0xF6, 0x10, 0x0, 0x80, 
    0x36, 0xF8, 0x10, 0x0, 0x80, 
    0x36, 0xF9, 0x20, 0x0, 0x80, 
    0x46, 0xF0, 0x40, 0x0, 0x80, 
    0x46, 0xF0, 0x30, 0x80, 0x80, 
    0x46, 0xF0, 0x50, 0x0, 0x80, 
    0x46, 0xF1, 0x10, 0x0, 0x80, 
    0x46, 0xF1, 0x1, 0x0, 0x80, 
    0x46, 0xF2, 0x28, 0x0, 0x80, 
    0x46, 0xF3, 0x10, 0x0, 0x80, 
    0x46, 0xF5, 0x10, 0x0, 0x80, 
    0x46, 0xF6, 0x10, 0x0, 0x80, 
    0x46, 0xF7, 0x1, 0x0, 0x80, 
    0x46, 0xF8, 0x40, 0x0, 0x80, 
    0x46, 0xF9, 0x10, 0x0, 0x80, 
    0x56, 0xF0, 0x1, 0x0, 0x80, 
    0x56, 0xF1, 0x10, 0x0, 0x80, 
    0x56, 0xF2, 0x20, 0x0, 0x80, 
    0x56, 0xF3, 0x1, 0x0, 0x80, 
    0x56, 0xF4, 0x10, 0x0, 0x80, 
    0x56, 0xF5, 0x10, 0x80, 0x80, 
    0x7, 0xF2, 0x76, 0x0, 0x80, 
    0x7, 0xF4, 0x10, 0x80, 0x80, 
    0x7, 0xF6, 0x10, 0x0, 0x80, 
    0x7, 0x8, 0x40, 0x0, 0x80, 
    0x17, 0xF0, 0x12, 0x80, 0x80, 
    0x17, 0xF0, 0x37, 0x0, 0x80, 
    0x17, 0xF2, 0x30, 0x80, 0x80, 
    0x17, 0xF2, 0x40, 0x80, 0x80, 
    0x17, 0xF4, 0x40, 0x0, 0x80, 
    0x17, 0xF6, 0x1, 0x80, 0x80, 
    0x27, 0xF2, 0x43, 0x0, 0x80, 
    0x27, 0xF4, 0x40, 0x80, 0x80, 
    0x27, 0xF4, 0x20, 0x80, 0x80, 
    0x27, 0xF4, 0x30, 0x80, 0x80, 
    0x37, 0xF0, 0x10, 0x80, 0x80, 
    0x37, 0x32, 0x21, 0x0, 0x80, 
    0x37, 0xF4, 0x60, 0x80, 0x80, 
    0x37, 0xF6, 0x10, 0x0, 0x80, 
    0x37, 0xF8, 0x10, 0x0, 0x80, 
    0x47, 0xF0, 0x10, 0x80, 0x80, 
    0x47, 0xF4, 0x40, 0x0, 0x80, 
    0x47, 0xF4, 0x10, 0x0, 0x80, 
    0x47, 0xF6, 0x30, 0x0, 0x80, 
    0x47, 0xF8, 0x70, 0x80, 0x80, 
    0x47, 0xF8, 0x1, 0x0, 0x80, 
    0x57, 0xF0, 0x0, 0x0, 0x80, 
    0x9, 0xF1, 0x72, 0x0, 0x80, 
    0x9, 0xF1, 0x21, 0x0, 0x80, 
    0x9, 0xF1, 0x91, 0x0, 0x80, 
    0x9, 0xF1, 0x41, 0x0, 0x80, 
    0x9, 0xF1, 0x51, 0x0, 0x80
    }
#endif   
};



#ifdef __TC02_SECURITY_REQUIREMENT__
static kal_uint8 const NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, //EF_IMSI
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, //EF_LOCI
    0xff, 0xff, 0xff, 0xff,	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff //EF_GLOCI
};
#endif /* __TC02_SECURITY_REQUIREMENT__ */

#if defined(__ATCMD_ONOFF_CHECK__)
const nvram_atcmd_check_context_struct NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT =
{
        {ATCMD_CHECK_ENABLE, 0x26598088, ATCMD_CHECK_ENABLE, 0X26598088},
        ATCMD_CHECK_ENABLE,  /* enable */
        {0x26598088, ATCMD_CHECK_ENABLE, 0x26598088}
};
#endif

#if defined(__ETWS_SUPPORT__)
const nvram_ef_etws_setting_struct NVRAM_EF_ETWS_SETTING_DEFAULT =
{
#ifdef __UE_SIMULATOR__
        0x01  /* always ON */
#else
        0x00
#endif        
};
#endif

static kal_uint8 const NVRAM_EF_BAND_INFO_DEFAULT[] = {
        0x00, /* mcc1 */
        0x00, /* mcc2 */
        0x00, /* mcc3 */
        0x00, /* learned_band */
        0x00, /* working_band */
        0x00  /* when __BAND_PRIORITY_SEARCH__ is defined, this
               * byte is used to set the priority for each band:
               *
               *      850     1900    1800    900
               *     +-------------------------------+
               * bit | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 | 
               *     +-------------------------------+
               * The priority of each band is representive by two bits:
               *
               * <ex> bit 5 and 4 is the priority for 1900 band:
               *         '0'   '0' -> priority value 0
               *         '0'   '1' -> priority value 1
               *         '1'   '0' -> priority value 2
               *         '1'   '1' -> priority value 3
               *  
               *      The smaller the value is, the higher the priroity is:
               *      (1) if no band is preferred, the value can be assigned:
               *          0x00, 0x55, 0xaa, or 0xff
               *      (2) if 900/1800 is prefered, the value can be assigned:
               *          0x50, 0xF0, 0xF5 and so on.
               *      (3) if 850/1900 is prefered, the value can be assigned:
               *          0x05, 0x0F, 0x5F and so on.
               *      (4) if the band prefered order is 1900 -> 8500 -> 900 -> 1800,
               *          the value 0x4e (0100 1110) should be used.
               */
};

static kal_uint8 const NVRAM_EF_CLASSMARK_RACAP_DEFAULT[] = {
       /*---BYTE 1 to BYTE 6 : From MS CLASSMARK3 -------------------------*/

    /*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined ( __EDGE_CARD_CLASS_12__ )

#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x25,  /* E-GSM power class 5, DCS power class 2 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x25,  /* P-GSM power class 5, DCS power class 2 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x05,  /* E-GSM power class 5 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x05,  /* P-GSM power class 5 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x02,  /* DCS power class 2 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#else /*__EDGE_CARD_CALSS_12__  */
       /* Claire 030922 change : Support multiband compile option */
#if defined( __EGSM900__) && defined( __DCS1800__)
#if defined ( __DISABLE_EGSM__ )
                  0x50,  /* MS supports P-GSM and DCS band */
#else
                  0x60,  /* MS supports E-GSM and DCS band */
#endif                  
                  0x14,  /* E-GSM power class 4, DCS power class 1 */
#elif defined( __PGSM900__) && defined( __DCS1800__)
                  0x50,  /* MS supports P-GSM and DCS band */
                  0x14,  /* P-GSM power class 4, DCS power class 1 */
#elif defined( __EGSM900__)
                  0x60,  /* MS supports E-GSM band only */
                  0x04,  /* E-GSM power class 4 */
#elif defined (__PGSM900__)
                  0x60,  /* MS supports P-GSM band only */
                  0x04,  /* P-GSM power class 4 */
#elif defined ( __DCS1800__ )
                  0x40,  /* MS supports DCS band only */
                  0x01,  /* DCS power class 1 */
#else
                  0x00,  /* None of GSM900 and DCS1800 are supported */
                  0x00,
#endif

#endif /* __EDGE_CARD_CALSS_12__  */
                  0x01,  /* HSCSD multislot cap not present, UCS2 =1 */
                  /* Claire 030922 change : Support multiband compile option */

                  0x80 + /* Extended Measurement cap=1(1 bit), AGPS support(6 bit), GSM400/480(1 bit) */
#ifdef __AGPS_CONTROL_PLANE__
                  0x4e +
#endif /* __AGPS_CONTROL_PLANE__ */
#if defined( __GSM450__) || defined( __GSM480__)
                  0x01 +
#endif /* defined( __GSM450__) || defined( __GSM480__) */
                  0x00,
#if 0
#if defined( __GSM450__) || defined( __GSM480__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif /* __AGPS_CONTROL_PLANE__ */
#else
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif /* __AGPS_CONTROL_PLANE__ */
#endif
#endif

#if !defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                  0x00,  /* GSM 400 and GSM 850 are not suported */
#elif defined( __GSM450__) && !defined( __GSM480__) && !defined( __GSM850__)
                 0x90,  /* GSM 450 is supported with power class 4*/
#elif !defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0x50,  /* GSM 480 is supported with power class 4*/
#elif !defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x02,  /* GSM 850 is supported*/
#elif defined( __GSM450__) && defined( __GSM480__) && !defined( __GSM850__)
                 0xd0,  /* GSM 450 and 480 are supported with power class 4*/
#elif defined( __GSM450__) && !defined( __GSM480__) && defined( __GSM850__)
                 0x92,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#elif !defined( __GSM450__) && defined( __GSM480__) && defined( __GSM850__)
                 0x52,  /* GSM 450 with power class 4 and GSM 850 are supported*/
#else
                 0xd2,   /* GSM 450, 480 with power class 4 and 850 are supported*/
#endif

/*Evelyn 071127 add compile option for EDGE CARD: different power class*/
#if defined( __EDGE_CARD_CLASS_12__ )

#if defined( __GSM850__) && defined( __PCS1900__)
                  0xb2,  /* GSM 850 is power class 5 ,PCS 1900 is suportedwith power class 2*/
#elif  defined( __PCS1900__)
                  0x12,  /* PCS 1900 is suported , power class 2 */
#elif  defined( __GSM850__)
                  0xa0,  /* GSM 850 is power class 5 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#else /* __EDGE_CARD_CALSS_12__  */

#if defined( __GSM850__) && defined( __PCS1900__)
                  0x91,  /* GSM 850 is power class 4 ,PCS 1900 is suportedwith power class 1*/
#elif  defined( __PCS1900__)
                  0x11,  /* PCS 1900 is suported , power class 1 */
#elif  defined( __GSM850__)
                  0x80,  /* GSM 850 is power class 4 */
#else
                  0x00,  /* Both GSM 850 and DCS 1900 are not supported */
#endif

#endif /* __EDGE_CARD_CALSS_12__  */


       /*---BYTE 7 to BYTE 9 : From MS CLASSMARK2 -----------  */
                  0x30,  /* CM2 Byte1: ES_IND =1, Revision level =01, A51 algo supported---*/
                  0x58,  /* CM2 Byte2: PS cap =1, SS sreen indicator =01, SM cap =1 */

                  0x80 + /* CM2 Byte3: CM3 is supported */
#ifdef __AGPS_CONTROL_PLANE__
                  0x20 +
#endif /* __AGPS_CONTROL_PLANE__ */
/* bit 2 RESERVED for further usage */
                  0x02 +
#ifndef __DISABLE_A5_2__
                  0x01 +
#endif /* __DISABLE_A5_2__ */
#ifdef __CCBS_SUPPORT__
                  0x04 +
#endif /* __CCBS_SUPPORT__ */
                  0x00,

#if 0
/* under construction !*/
#if defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
/* under construction !*/
#elif defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif !defined(__NO_SUPPORT_A5_3__) && defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#elif defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#else //!defined(__NO_SUPPORT_A5_3__) && !defined(__DISABLE_A5_2__) && !defined(__CCBS_SUPPORT__)
#ifdef __AGPS_CONTROL_PLANE__
/* under construction !*/
#else
/* under construction !*/
#endif
#endif
#endif
       /*---BYTE 10 to BYTE 12 : From MS RA capability and MS network capability --*/

                           /* BYTE 10:
                            * bit 8: multislot capability present,
                            * bit 7 ~ 3: mutlislot capability,
                            * bit 2: GPRS extended Dynamic Allocation cap =1
                            * bit 1 : RL indicator = 0 => R98 MS, 1 => R99 MS */
#ifdef __R99__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xab,   /* Default GPRS multislot class 10, ext DA support, R99 */
   #else
                  0xb3,  /* Default GPRS multislot class 12, ext DA support, R99 */
   #endif
#else /* __R99__*/
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__GPRS_MULTISLOT_CLASS_10__)
                  0xaa,   /* Default GPRS multislot class 10, ext DA support, R98 */
   #else
                  0xb2,  /* Default GPRS multislot class 12, ext DA support, R98 */
   #endif
#endif /* __R99__ */

                           /* BYTE 11:
                            * bit 8 : GEA1
                            * bit 7 : GEA2
                            * bit 6 : GEA3
                            * bit 5 : GEA4
                            * bit 4 : GEA5
                            * bit 3 : GEA6
                            * bit 2 : GEA7
                            * bit 1 : SM cap in GPRS =1 */
/* Peter 080520: change complie option */
#ifdef __NO_SUPPORT_A5_3__
                  0xc1, /* GEA1, 2 and SM cap support */
#else // The chip support A5/3(GEA/3)
    0xe1, /* GEA1, 2, 3 and SM cap support */
#endif

                           /* BYTE 12: Lanslo 20060215: for selecting GPRS or EGPRS capability
                             * bit 8: PFC mode = 0b
                             * bit 7: EDGE multislot class present / EDGE support = 1b
                             * bit 6 ~ 2: EDGE multislot capability = 01100b
                             * bit 1: EDGE extended dynamic allocation capability = 1b
                             * Old value 0x80, new 0xd9(PFC on), 0x59 (PFC off) */

/* Evelyn 20090511: open the PFC support bit */
#ifdef __EGPRS_MODE__
   #if defined(__EDGE_CARD_CLASS_10__) || defined(__EDGE_MULTISLOT_CLASS_10__)
                  0xD5,   /* PFC on, EGPRS multislot class 10, Ext DA support */
   #else
                  0xD9,   /* PFC on, EGPRS multislot class 12, Ext DA support */
   #endif
#else /* __EGPRS_MODE__ */
   #ifdef __R99__
                  0x80,   /* PFC on */
   #else
                  0x00,   /* PFC off */
   #endif
#endif /* __EGPRS_MODE__ */

// Jelly 20090602 Use __EPSK_TX__
#if (defined(__EGPRS_MODE__) && defined(__EPSK_TX__))
                  0xAA,   /* BYTE 13: Evelyn 20090422: set 8PSK power class in NVRAM
                            * bit8~7 : 8psk radio cap 2 = E2 *
                            * bit6~5 : 8psk radio cap 1 = E2 *
                            * bit4~3 : 8psk 850 Band    = E2 *
                            * bit2~1 : 8psk 1900 Band   = E2 */
#else /* __EGPRS_MODE__ */
                  0x00,   /* No 8PSK power class */
#endif /* __EGPRS_MODE__ */

/* Modify for High multislot class */
#if defined (__MULTISLOT_CLASS_34__) || defined (__MULTISLOT_CLASS_45__)
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0xEc    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#else
                  0x6c    /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           *  bit 7   : high multislot class present or not
                           *  bit 6~1 : binany coding for high multislot value
                           *  For example, high multislot class 44 = 0x6c
                           */
#endif
#else
#if defined(__EPSK_TX__) && !defined(__EPSK_TX_SW_SWITCH_OFF__)
                  0x80   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#else
                  0x00   /* BYTE 14: Evelyn 20090905: set high multislot class
                           *  bit 8   : EPSK_TX
                           */
#endif
#endif

/* Byte 15: Rel4 Capabiility: GSM 750 cap(1 bit), TDD cap(1 bit), GERAN FP1(1 bit), Extended DTM(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __UMTS_TDD128_MODE__
                  0x40 +
#endif /* __UMTS_TDD128_MODE__ */
#ifdef __GERAN_R4__
                  0x20 +
#endif /* __GERAN_R4__ */
                  0x00

/* Byte 16: Rel5 Capabiility: High Multislot(1 bit), GERAN lu Mode(1 bit), GERAN FP2(1 bit), GMSK Multislot(2 bit), 8PSK Multislot(2 bit), 1 bit is spared */
                 ,0x00

/* Byte 17: Rel6 Capabiility: T-GSM 400 cap(1 bit), T-GSM 900 cap(1 bit), SAIC(2 bit), DTM enhancements(1 bit), DTM GPRS High Multislot(1 bit), Repeated ACCH(1 bit), 1 bit is spared */
                 ,0x00 +
#ifdef __SAIC__
                  0x10 +
#endif /* __SAIC__ */
#ifdef __REPEATED_ACCH__
                  0x02 +
#endif /* __REPEATED_ACCH__ */
                  0x00

/* Byte 18: Rel7 Capabiility: GSM 710 cap(1 bit), T-GSM 810 cap(1 bit), Ciphering Mode Setting(1 bit), Additional Positioning cap(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__
                  0x10 +
#endif /* __POS_CAP_TRANSFER_PROCEDURE_SUPPORT__ */
                  0x00

/* Byte 19: Rel8 Capabiility: E-UTRA FDD(1 bit), E-UTRA TDD(1 bit), E-UTRA Measurement(1 bit), APBCR(1 bit), 4 bits are spared */
                 ,0x00 +
#ifdef __LTE_RAT__
                  0xe0 +
#endif /* __LTE_RAT__ */
#if defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__)
                  0x10 +
#endif /* defined(__23G_PRI_RESEL_SUPPORT__) || defined(__LTE_RAT__) */
                  0x00

/* Byte 20: Rel9 Capabiility: CSG reporting cap(1 bit), 7 bits are spared */
                 ,0x00

};

static kal_uint8 const NVRAM_EF_AS_BAND_SETTING_DEFAULT[] =
{
/* Byte 0 is GSM band */
    0
#if defined(__EGSM900__) && defined(__DISABLE_EGSM__) //mtk02475: AS and L1 need keep EGSM compile option turn on, request RAC turn on PGSM only
    + 0x01
#else /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __PGSM900__
    + 0x01
#endif /* __PGSM900__ */
#ifdef __EGSM900__
    + 0x02
#endif /* __EGSM900__ */
#endif /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __RGSM900__
    + 0x04
#endif /* __RGSM900__ */
#ifdef __DCS1800__
    + 0x08
#endif /* __DCS1800__ */
#ifdef __PCS1900__
    + 0x10
#endif /* __PCS1900__ */
#ifdef __GSM450__
    + 0x20
#endif /* __GSM450__ */
#ifdef __GSM850__
    + 0x80
#endif /* __GSM850__ */
    ,

#if defined(__UMTS_FDD_MODE__)
/* Byte 1~4 is UMTS band */
	// for MT6276/MT6573 UMTS band customization, need to default turn on all UMTS band instead of check UMTS band feature option
	/* 1th	byte is first byte of UMTS supported band */
    0 // initial value
    + Support_UMTS_BAND_I
    + Support_UMTS_BAND_II
    + Support_UMTS_BAND_III
    + Support_UMTS_BAND_IV
    + Support_UMTS_BAND_V
    + Support_UMTS_BAND_VI
    + Support_UMTS_BAND_VII
    + Support_UMTS_BAND_VIII
    ,  // end of character

    /* 2th  byte is second byte of UMTS supported band */
    0 // initial value
    + Support_UMTS_BAND_IX
    + Support_UMTS_BAND_X
    + Support_UMTS_BAND_XI
    + Support_UMTS_BAND_XII
    + Support_UMTS_BAND_XIII
    + Support_UMTS_BAND_XIV
    + Support_UMTS_BAND_XV
    + Support_UMTS_BAND_XVI
    ,  // end of character

    /* 3th  byte is third byte of UMTS supported band */
    0 // initial value
    + Support_UMTS_BAND_XVII
    + Support_UMTS_BAND_XVIII
    + Support_UMTS_BAND_XIX
    + Support_UMTS_BAND_XX
    + Support_UMTS_BAND_XXI
    + Support_UMTS_BAND_XXII
    + Support_UMTS_BAND_XXIII
    + Support_UMTS_BAND_XXIV
    ,  // end of character

    /* 4th  byte is fourth byte of UMTS supported band */
    0 // initial value
    + Support_UMTS_BAND_XXV
    + Support_UMTS_BAND_XXVI
    + Support_UMTS_BAND_XXVII
    + Support_UMTS_BAND_XXVIII
    + Support_UMTS_BAND_XXIX
    + Support_UMTS_BAND_XXX
    + Support_UMTS_BAND_XXXI
    + Support_UMTS_BAND_XXXII
    ,  // end of character
   #else
	/* 1th	byte is first byte of UMTS supported band */
    0 // initial value
#ifdef __UMTS_TDD128_BAND_A__    
    + Support_UMTS_BAND_A
#endif
#ifdef __UMTS_TDD128_BAND_B__ 
    + Support_UMTS_BAND_B
#endif
#ifdef __UMTS_TDD128_BAND_C__ 
    + Support_UMTS_BAND_C
#endif
#ifdef __UMTS_TDD128_BAND_D__ 
    + Support_UMTS_BAND_D
#endif
#ifdef __UMTS_TDD128_BAND_E__ 
    + Support_UMTS_BAND_E
#endif
#ifdef __UMTS_TDD128_BAND_F__ 
    + Support_UMTS_BAND_F
#endif
    ,  // end of character
    0,
    0,
    0,
#endif


/* Byte 5~12 is LTE band */
	/* 5th byte is first byte of LTE supported band */
#if defined(__UE_SIMULATOR__)
    0x03 // For UESIM, default is band 1
    ,  // end of character

    /* 6th byte is second byte of LTE supported band */
    0x00 // initial value
    ,  // end of character

    /* 7th byte is third byte of LTE supported band */
    0x00 // initial value
    ,  // end of character

    /* 8th byte is fourth byte of LTE supported band */
    0x00 // initial value
    ,  // end of character

    /* 9th byte is fifth byte of LTE supported band */
    0x80 // initial value
    ,  // end of character

    /* 10th byte is sixth byte of LTE supported band */
    0x00 // initial value
    ,  // end of character

    /* 11th byte is seventh byte of LTE supported band */
    0x00 // initial value
    ,  // end of character

    /* 12th byte is eightth byte of LTE supported band */
    0x00 // initial value    
#else
    0xff // initial value
    ,  // end of character

    /* 6th byte is second byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 7th byte is third byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 8th byte is fourth byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 9th byte is fifth byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 10th byte is sixth byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 11th byte is seventh byte of LTE supported band */
    0xff // initial value
    ,  // end of character

    /* 12th byte is eightth byte of LTE supported band */
    0x7f // initial value
#endif
};

#ifdef __UMTS_RAT__

#ifdef __UMTS_FDD_MODE__
static kal_uint8 const NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT[] =
{
    // R99 CAP #29
    /* PDCP part */
#if defined(__RFC2507_SUPPORT__) && defined(__CUSTOMIZE_RFC2507_SUPPORT__)
    0x02, /* PDCP_supportForRfc2507: supported */
#else
    0x01, /* PDCP_supportForRfc2507: not supported */
#endif

#ifndef __UMTS_R5__
    0x00, /* MAX_HeaderCompressionLengthContext: 512 */
#else
    0x01, /* MAX_HeaderCompressionLengthContext: 1024 */
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    /* RLC part */
#ifdef __UMTS_R8__
    0x06, /* RRC_TotalRLC_AM_BufferSize: RRC_kb1000 */
#elif defined(__UMTS_R5__)
    0x05, /* RRC_TotalRLC_AM_BufferSize: RRC_kb500 */
#else
    0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150. */
#endif

    0x00, /* RRC_MaximumRLC_WindowSize: RRC_mws2047 */
    0x04, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am8 */

    /* UL TRCH part */
    0x01, /* ul_TransChCapability.modeSpecificInfo.selection: RRC_UL_TransChCapability_modeSpecificInfo_fdd_selected */
    0x08, /* ul_TransChCapability.maxNoBitsTransmitted: RRC_b10240 */
    0x00, /* ul_TransChCapability.maxConvCodeBitsTransmitted: RRC_b640 */
    0x02, /* ul_TransChCapability.turboEncodingSupport.selection: RRC_TurboSupport_supported_selected */
    0x08, /* ul_TransChCapability.turboEncodingSupport.choice.supported: RRC_b10240 */
    0x02, /* ul_TransChCapability.maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsUL_e8 */
    0x03, /* ul_TransChCapability.maxTransmittedBlocks: RRC_MaxTransportBlocksUL_tb16 */
    0x05, /* ul_TransChCapability.maxNumberOfTFC: RRC_MaxNumberOfTFC_UL_tfc64 */
    0x00, /* ul_TransChCapability.maxNumberOfTF: RRC_tf32 */
    0x01, /* tdd.maxSimultaneousCCTrCH_Count: 1(TDD_R4 only), not used in FDD */
    /* DL TRCH part */
    0x08, /* maxNoBitsReceived: RRC_b10240 */
// Temporary modify from 1280bits to 640bits for 6290E1 HW.
//    0x01, /* maxConvCodeBitsReceived: RRC_b1280 */
#ifdef __UE_SIMULATOR__
    0x01, /* maxConvCodeBitsReceived: RRC_b1280 */
#else
/* Use Chip-ID to determine maxConvCodeBitsReceived. If 6290 E1 is no-longer used, we shall remove this checking */
#if defined( MT6290_S00 )
    0x00, /* maxConvCodeBitsReceived: RRC_b640 */
#else
    0x01, /* maxConvCodeBitsReceived: RRC_b1280 */
#endif
#endif
    
    0x02, /* turboDecodingSupport: RRC_TurboSupport_supported_selected */
    0x08, /* turboDecodingSupport.choice.supported: RRC_b10240 */
    0x01, /* maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsDL_e8 */
    0x01, /* maxSimultaneousCCTrCH_Count: DL_TCH_MAXSIMCCTRCH_COUNT */
    0x03, /* maxReceivedTransportBlocks: RRC_MaxTransportBlocksDL_tb32 */
    0x05, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc128 */
    0x01, /* maxNumberOfTF: RRC_tf64 */

    /* Capability for CSCE use (WCDMA prefered, not part of UE capability which report to Network) */
#ifdef __WCDMA_PREFERRED__
    0x28+ /* 2G RSSI penalty: default value is 40 */
#endif /* __WCDMA_PREFERRED__ */
    0x00,

    /* RF Frequency Capability Info */
    0x00, /* reserved, original is for RF band */
    0x02, /* power class for all frequency bands: 00: Power Class 1, 01: Power Class 2, 02: Power Class 3, 03: Power Class 4 */
    0xAA, /* reserved, original is for Power Class bitmask */
    0xAA, /* reserved, original is for Power Class bitmask */

    /* R99 CAP Additional part #5 */
    /* 20101020 Chi-Chung: According to PDCP request, turn off LSR on FDD R5R6 and MAUI branches */
    0x00, /* losslessSRNS_RelocationSupport: 0 not supported, 1 supported */

    0x00, /* cipheringAlgorithmCap.stringData[0] */
#if defined(__UMTS_R7__) && !defined(__UE_SIMULATOR__) && defined(__CUSTOMIZE_UEA2_UIA2_SUPPORT__)
    0x07, /* cipheringAlgorithmCap.stringData[1]: UEA2|UEA1|UEA0 */
#else
    0x03, /* cipheringAlgorithmCap.stringData[1]: UEA1|UEA0*/
#endif

    0x00, /* integrityProtectionAlgorithmCap.stringData[0] */
#if defined(__UMTS_R7__) && !defined(__UE_SIMULATOR__) && defined(__CUSTOMIZE_UEA2_UIA2_SUPPORT__)
    0x06  /* integrityProtectionAlgorithmCap.stringData[1]: UIA2|UIA1 */
#else
    0x02  /* integrityProtectionAlgorithmCap.stringData[1]: UIA1 */
#endif

    , /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~3: not used */
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    0x02+
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#if 0  /* 6589: default setting changes to not send SCRI in PCH state for power saving optimization, also to meet some operators requirement. */
#ifdef __FAST_DORMANCY__
/* under construction !*/
#endif /* __FAST_DORMANCY__ */
#endif
    0x00

    , /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~3: not used 
       * bit 2: Turn on 3G Smart Paging Level 2 (RRCE listen paging each 2 DRX without learning)
       * bit 1: Turn on 3G Smart Paging */
#ifdef __SMART_PAGING_3G_FDD__
#ifdef __SMART_PAGING_3G_FDD_OFF__ /* This compile option only defined in MT6280 chip, used to keep the code sync with MT6583 and further product (Smart paging not turn on in MT6280) */
    0x00+
#else
    0x01+
#endif /* __SMART_PAGING_3G_FDD_OFF__ */
#endif /* __SMART_PAGING_3G_FDD__ */
    0x00

   ,  /* Capability for RRCE use (not part of UE capability which report to Network) */
      /* bit 8~7: not used 
       * bit 1: bypass integrity checking(ip checking always pass). 
       * e.g. 0x01: UE will bypass integrity checking for every DL RRC msg.
       *      0x00: UE will handle integrity checking as usual. */
   0x0

    /* Access Stratum Release Indicator */
   ,
#if defined(__UMTS_R9__)
   0x05 /* RRC_AccessStratumReleaseIndicator_rel_9 */
#elif defined(__UMTS_R8__)
   0x04 /* RRC_AccessStratumReleaseIndicator_rel_8 */
#elif defined(__UMTS_R7__)
   0x03 /* RRC_AccessStratumReleaseIndicator_rel_7 */
#elif defined(__UMTS_R6__)
   0x02 /* RRC_AccessStratumReleaseIndicator_rel_6 */
#elif defined(__UMTS_R5__)
   0x01 /* RRC_AccessStratumReleaseIndicator_rel_5 */
#elif defined(__UMTS_R4__)
   0x00 /* RRC_AccessStratumReleaseIndicator_rel_4 */
#else
   0x00
#endif

    /* PHYCH part */
   ,0x03, /* DL PhyChCap -  dlPhyCh_maxNoDPCH_PDSCH_Codes: 3 */


                          /* r3_cap1: USIME_R3_Cap1
                            * bit 8~5: maxNoDPDCH_BitsTransmitted
                            * bit 4~0: maxNoPhysChBitsReceived */

   0x40+ /* UL PhyChCap - maxNoDPDCH_BitsTransmitted: RRC_MaxNoDPDCH_BitsTransmitted_b9600 */
   0x08, /* DL PhyChCap - maxNoPhysChBitsReceived: RRC_MaxNoPhysChBitsReceived_b19200 */


                          /* r3_cap2: USIME_R3_Cap2
                            * bit 8~7: not used
                            * bit 6: sfn_sfnType2Capability
                            * bit 5~4: multiModeCapability
                            * bit 3: supportOfMulticarrier
                            * bit 2: supportOfGSM
                            * bit 1: supportForSF_512 */
   0x00+ /* sfn_sfnType2Capability: 0x20 supported, 0x00 not supported */

#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_TDD128_MODE__)
   0x10+ /* RRC_MultiModeCapability_fdd_tdd */
#elif defined(__UMTS_FDD_MODE__)
   0x08+ /* RRC_MultiModeCapability_fdd */
#elif defined(__UMTS_TDD128_MODE__)
   0x00+ /* RRC_MultiModeCapability_tdd */
#endif

   0x00+ /* supportOfMulticarrier: 0x04 supported, 0x00 not supported */
#if defined (__GSM_RAT__)
   0x02+ /* supportOfGSM: 0x02 supported, 0x00 not supported */
#endif
   0x00, /* USIME_supportForSF_512: 0x01 supported, 0x00 not supported */

                          /* r3_cap3: USIME_R3_Cap3
                            * bit 8: validity_CellPCH_UraPCH
                            * bit 7: rx_tx_TimeDifferenceType2Capable
                            * bit 6: supportForIPDL
                            * bit 5: supportForUE_GPS_TimingOfCellFrames
                            * bit 4~3: networkAssistedGPS_Supported
                            * bit 2: ue_BasedOTDOA_Supported
                            * bit 1: standaloneLocMethodsSupported */
#ifdef __UAGPS_CP_SUPPORT__
   0x80+ /* validity_CellPCH_UraPCH: 0x80: supported, 0x00 not supported */
#endif

   0x00+ /* rx_tx_TimeDifferenceType2Capable: 0x40: supported, 0x00 not supported */
   0x00+ /* supportForIPDL: 0x20: supported, 0x00 not supported */

#if defined(__UAGPS_CP_SUPPORT__) && defined(__L1_GPS_REF_TIME_SUPPORT__)
   0x00+ /* supportForUE_GPS_TimingOfCellFrames: 0x10: supported, 0x00 not supported */
#endif

#ifdef __UAGPS_CP_SUPPORT__
   0x08+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_bothNetworkAndUE_Based */
#else
   0x0C+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_noNetworkAssistedGPS */
#endif

   0x00+ /* ue_BasedOTDOA_Supported: 0x02: supported, 0x00 not supported */

#ifdef __UAGPS_CP_SUPPORT__
   0x01+ /* standaloneLocMethodsSupported: 0x01: supported, 0x00 not supported */
#endif
   0x00

    /* R4 CAP */
#if defined(__UMTS_R4__) || defined(__UMTS_R5__)
    ,   // >#I
                           /* r4_cap1: USIME_R4_Cap1
                            * bit 8~6: not used
                            * bit 4: USIME_supportForRfc3095
                            * bit 3~0: maxROHC_ContextSessions */
    0x00+ /* USIME_supportForRfc3095: 0x10 support, 0x00 not support */
    0x00, /* maxROHC_ContextSessions: RRC_MaxROHC_ContextSessions_r4_s2 */

    0x00, /* reverseCompressionDepth_high_byte */
    0x00 /* reverseCompressionDepth_low_byte */
#endif /* defined(__UMTS_R4__) || defined(__UMTS_R5__) */

    /* R5 CAP */
#ifdef __UMTS_R5__
    ,   // >#I
                           /* r5_cap1: USIME_R5_Cap1
                            * bit 8~7: not used
                            * bit 6: supportForRfc3095ContextRelocation
                            * bit 5: supportOfUTRAN_ToGERAN_NACC
                            * bit 4: losslessDLRLCPDUSizeChange
                            * bit 2~3: dl_CapabilityWithSimultaneousHS_DSCHConfig 
                            * bit 1: dl_CapabilityWithSimultaneousHS_DSCHConfigValid */
    0x00+ /* supportForRfc3095ContextRelocation: 0x20 supported, 0x00 not supported */
    0x10+ /* supportOfUTRAN_ToGERAN_NACC: 0x10 supported, 0x00 not supported */
    0x00+ /* losslessDLRLCPDUSizeChange: 0x08 supported, 0x00 not supported */
    0x02+ /* dl_CapabilityWithSimultaneousHS_DSCHConfig: 0x00 kbps32, 0x02 kbps64, 0x04 kbps128, 0x06 kbps384*/
    0x01  /* fddPhysicalChannelCapab_hspdsch_edch: 0x01 valid, 0x00 not valid */
#endif /* __UMTS_R5__ */

    /* R6 CAP */
#ifdef __UMTS_R6__
    ,   // >#I
                          /* r6_cap1: USIME_R6_Cap1
                            * bit 8~5: not used
                            * bit 4: supportOfCSHandoverToGAN
                            * bit 3: doesNotBenifitFromBatteryConsumptionOptimization
                            * bit 2: supportForFDPCH 
                            * bit 1: supportForSIB11bis */
    0x00+ /* supportOfCSHandoverToGAN: 0x08 support, 0x00 not support */
#ifdef __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
    0x04+ /* doesNotBenifitFromBatteryConsumptionOptimization: 0x04 does not benefit, 0x00 benefit */
#endif    
    0x02+ /* supportForFDPCH: 0x02 supported, 0x00 not supported */
    0x01  /* supportForSIB11bis: 0x01 supported, 0x00 not supported */
#endif /* __UMTS_R6__ */

    /* R7 CAP */
#ifdef __UMTS_R7__
    ,   // >#I
                          /* r7_cap1: USIME_R7_Cap1
                            * bit 8: discontinuousDpcchTransmission
                            * bit 7: hsdschReceptionCellUraPch
                            * bit 6: hsdschReceptionCellFach
                            * bit 5: enhancedFdpch
                            * bit 4: hsscchlessHsdschOperation
                            * bit 3: mac_ehsSupport
                            * bit 2: supportOfTwoLogicalChannel
                            * bit 1: supportForCSVoiceoverHSPA */
#if defined(__ENHANCED_COMMON_STATE_SUPPORT__) && defined(__CUSTOMIZE_ENHANCED_COMMON_STATE_SUPPORT__)
    0x40+ /* hsdschReceptionCellUraPch: 0x40 supported, 0x00 not supported */
    0x20+ /* hsdschReceptionCellFach: 0x20 supported, 0x00 not supported*/
#endif

    0x10+ /* enhancedFdpch: 0x10 supported, 0x00 not supported */

#ifdef __CPC_SUPPORT__
    0x80+ /* discontinuousDpcchTransmission: 0x80 supported, 0x00 not supported */
#endif

#if defined(__CPC_SUPPORT__) && defined(__CUSTOMIZE_HSSCCH_LESS_SUPPORT__)
    0x08+ /* hsscchlessHsdschOperation: 0x08 supported, 0x00 not supported */
#endif

#ifdef __MAC_EHS_SUPPORT__
    0x04+ /* mac_ehsSupport: 0x04 supported, 0x00 not supported */
#endif

    0x00+ /* supportOfTwoLogicalChannel: 0x02 supported, 0x00 not supported */

#if defined(__CSHSPA_SUPPORT__) && defined(__CUSTOMIZE_CSHSPA_SUPPORT__)
    0x01+  /* pdcp_supportForCSVoiceoverHSPA: 0x01 supported, 0x00 not supported */
#endif

    0x00,

                          /* r7_cap2: USIME_R7_Cap2
                            * bit 8~7: not used
                            * bit 6: supportofPSHandoverToGAN
                            * bit 5: supportofTxDivOnNonMIMOChannel
                            * bit 4: supportEDPDCHPowerInterpolation
                            * bit 3: supportForTwoDRXSchemesInPCH
                            * bit 2: supportForEDPCCHPowerBoosting
                            * bit 1: slotFormat4 */
    0x00+ /* supportofPSHandoverToGAN: 0x20 supported, 0x00 not supported */
    0x00+ /* supportofTxDivOnNonMIMOChannel: 0x10 supported, 0x00 not supported */
    0x00+ /* supportEDPDCHPowerInterpolation: 0x08 supported, 0x00 not supported */
    0x04+ /* supportForTwoDRXSchemesInPCH: 0x04 supported, 0x00 not supported */
    0x02+ /* supportForEDPCCHPowerBoosting: 0x02 supported, 0x00 not supported */
    0x01   /* slotFormat4: 0x01 supported, 0x00 not supported */
#endif /* __UMTS_R7__ */

    /* R8 CAP */
#ifdef __UMTS_R8__
    ,   // >#I
                          /* r8_cap1: USIME_R8_Cap1
                            * bit 5~8: eutraFeatureGroupIndicators
                            * bit 4: supportOfInterRATHOToEUTRAFDD
                            * bit 3: supportOfEUTRAFDD
                            * bit 2: supportOfHsdschDrxOperation
                            * bit 1: supportOfTargetCellPreConfig */

#ifdef __LTE_RAT__
    0xC0+ /* eutraFeatureGroupIndicators: 0xC0 fully supported, 0x00 not supported */
    0x08+ /* supportOfInterRATHOToEUTRAFDD: 0x08 supported, 0x00 not supported */
    0x04+ /* supportOfEUTRAFDD: 0x04 supported, 0x00 not supported */
#endif

#if defined(__HSDSCH_DRX_CELL_FACH_SUPPORT__) && defined(__CUSTOMIZE_HSDSCH_DRX_CELL_FACH_SUPPORT__)
    0x02+ /* supportOfHsdschDrxOperation: 0x02 supported, 0x00 not supported */
#endif

#if defined(__HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__) && defined(__CUSTOMIZE_HSDSCH_CELL_CHANGE_ENHANCE_SUPPORT__)
    0x01+ /* supportOfTargetCellPreConfig: 0x01 supported, 0x00 not supported */
#endif

    0x00,

                          /* r8_cap2: USIME_R8_Cap2
                            * bit 8: supportOfInterRATHOToEUTRATDD
                            * bit 7: supportOfEUTRATDD
                            * bit 6: supportCellSpecificTxDiversityinDC_Operation
                            * bit 5: supportForPriorityReselectionInUTRAN
                            * bit 4: supportOfCSG
                            * bit 3: supportOfMACiis
                            * bit 2: supportOfCommonEDCH
                            * bit 1: adjacentFrequencyMeasurements */
#ifdef __LTE_RAT__
    0x80+ /* supportOfInterRATHOToEUTRATDD: 0x80 supported, 0x00 not supported */
    0x40+ /* supportOfEUTRATDD: 0x40 supported, 0x00 not supported */
#endif

#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x20+ /* supportCellSpecificTxDiversityinDC_Operation: 0x20 supported, 0x00 not supported */
#endif

#ifdef __23G_PRI_RESEL_SUPPORT__
    0x10+ /* supportForPriorityReselectionInUTRAN: 0x10 supported, 0x00 not supported */
#endif

#ifdef __3G_CSG_SUPPORT__
    0x08+ /* supportOfCSG: 0x08 supported, 0x00 not supported */
#endif

#if defined(__MAC_IIS_SUPPORT__) && defined(__CUSTOMIZE_MAC_IIS_SUPPORT__)
    0x04+ /* supportOfMACiis: 0x04 supported, 0x00 not supported */
#endif

#if defined(__COMMON_EDCH_SUPPORT__) && defined(__CUSTOMIZE_COMMON_EDCH_SUPPORT__)
    0x02+ /* supportOfCommonEDCH: 0x02 supported, 0x00 not supported */
#endif

#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x01+  /* adjacentFrequencyMeasurements: 0x01 supported, 0x00 not supported */
#endif

    0x00
#endif /* __UMTS_R8__ */
};

/* The default data was encoded result of SCSI's ScsiFrequencyInfoRepository which saves the 110 plmns' 3 uarfcn. */
static kal_uint8 const NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT[] =
{0XA1, 0X02
, 0X06, 0X00, 0X00, 0X03, 0X0F, 0XA9, 0X44, 0XA5, 0X76, 0X04
, 0X0C, 0X00, 0X00, 0X0C, 0X1F, 0X54, 0X47, 0X52, 0XA4, 0X08
, 0X18, 0X00, 0X00, 0X04, 0X3E, 0XA7, 0XC6, 0XA0, 0XA8, 0X10
, 0X30, 0X00, 0X00, 0X10, 0X7D, 0X4D, 0XC5, 0X32, 0XF0, 0X20
, 0X00, 0X80, 0X00, 0X10, 0XFA, 0XA2, 0X2A, 0X8E, 0XE0, 0X40
, 0X01, 0X00, 0X20, 0X01, 0XF5, 0X28, 0X94, 0XAE, 0XC0, 0X80
, 0X02, 0X00, 0X80, 0X03, 0XDA, 0X63, 0XE0, 0X40, 0X60, 0X80
, 0X60, 0X01, 0XED, 0X41, 0X30, 0X20, 0X30, 0X40, 0X30, 0X30
, 0XFA, 0XA5, 0X4A, 0X8E, 0XE0, 0X40, 0X60, 0X80, 0X20, 0XA1
, 0XFD, 0X3B, 0X14, 0XF8, 0X53, 0X7F, 0X02, 0X03, 0X04, 0X01
, 0X00, 0X0F, 0XA9, 0X8D, 0XA6, 0X96, 0X04, 0X06, 0X08, 0X04
, 0X00, 0X1F, 0XD2, 0X89, 0X4B, 0XA5, 0X2B, 0X90, 0X40, 0X50
, 0X40, 0X10, 0X90, 0XFE, 0X95, 0XDA, 0X51, 0X29, 0X76, 0X82
, 0X02, 0X82, 0X00, 0X03, 0X07, 0XD4, 0XF8, 0XD3, 0XB3, 0X04
, 0X05, 0X04, 0X00, 0X03, 0X0F, 0XEA, 0X24, 0XA8, 0XF2, 0XA5
, 0X48, 0X20, 0X28, 0X20, 0X00, 0X00, 0X7F, 0X4D, 0X3D, 0X31
, 0XD4, 0XDF, 0XC1, 0X01, 0X81, 0X80, 0X00, 0X43, 0XDA, 0X50
, 0XE0, 0X80, 0XC0, 0XC1, 0X01, 0X21, 0XF5, 0X31, 0XD4, 0XD3
, 0X41, 0X01, 0X81, 0X82, 0X40, 0X83, 0XEA, 0X82, 0XAA, 0X23
, 0X82, 0X03, 0X03, 0X04, 0X83, 0X87, 0XD4, 0XEC, 0XD3, 0XE5
, 0X02, 0X06, 0X02, 0X00, 0X01, 0X0F, 0X6A, 0X54, 0X81, 0X03
, 0X01, 0X00, 0X01, 0X07, 0XD4, 0XA2, 0X52, 0XB9, 0X02, 0X06
, 0X02, 0X00, 0X03, 0X0F, 0X69, 0XA7, 0X81, 0X03, 0X01, 0X00
, 0X03, 0X87, 0XB5, 0X11, 0X40, 0X80, 0X80, 0X80, 0X40, 0X03
, 0XDA, 0X95, 0XA0, 0X40, 0X40, 0X41, 0X21, 0X21, 0XF5, 0X41
, 0X75, 0X12, 0X40, 0X80, 0X80, 0X80, 0X00, 0X43, 0XDA, 0X63
, 0XA0, 0X40, 0X40, 0X41, 0X01, 0X01, 0XED, 0X38, 0X10, 0X50
, 0X10, 0X00, 0X00, 0X80, 0XF6, 0X97, 0X58, 0X28, 0X08, 0X00
, 0X08, 0X08, 0X7B, 0X4E, 0X04, 0X14, 0X04, 0X00, 0X00, 0X04
, 0X3D, 0XA7, 0X66, 0X0A, 0X02, 0X00, 0X10, 0X12, 0X1E, 0XD2
, 0X87, 0X05, 0X01, 0X00, 0X01, 0X00, 0X0F, 0X69, 0XA7, 0X82
, 0X80, 0X82, 0X80, 0X01, 0X07, 0XD4, 0XEC, 0XD3, 0X81, 0X05
, 0X01, 0X05, 0X00, 0X05, 0X0F, 0X69, 0X8E, 0X82, 0X80, 0X82
, 0X80, 0X01, 0X87, 0XF4, 0XA1, 0X22, 0X46, 0X88, 0X54, 0X08
, 0X14, 0X14, 0X00, 0X1C, 0X3E, 0XA6, 0X36, 0X94, 0X38, 0X10
, 0X28, 0X28, 0X00, 0X18, 0X7B, 0X4E, 0XCC, 0X18, 0X00, 0X08
, 0X00, 0X0C, 0X3E, 0XA5, 0X0A, 0X95, 0XB8, 0X30, 0X00, 0X10
, 0X00, 0X10, 0X7B, 0X4D, 0X34, 0X10, 0X14, 0X00, 0X00, 0X20
, 0X3D, 0XA9, 0X52, 0X08, 0X08, 0X00, 0X02, 0X00, 0X1F, 0X88
, 0X1B, 0X4E, 0X05, 0X3B, 0X10, 0X40, 0X40, 0X00, 0X20, 0X00
, 0XFE, 0XA0, 0XBA, 0X8F, 0X2A, 0X24, 0X83, 0X02, 0X82, 0X80
, 0X80, 0X07, 0XB4, 0XEC, 0X41, 0X81, 0X41, 0X40, 0X00, 0X43
, 0XEA, 0X57, 0X29, 0X42, 0X83, 0X81, 0X02, 0X00, 0X02, 0X87
, 0XA8, 0X9F, 0X41, 0XC0, 0X81, 0X00, 0X00, 0XC3, 0XDA, 0X50
, 0XE0, 0X60, 0X60, 0X80, 0X00, 0X41, 0XE8, 0X87, 0XF0, 0X40
, 0X00, 0X40, 0X30, 0X40, 0XF6, 0XA0, 0XA8, 0X20, 0X00, 0X20
, 0X28, 0X08, 0X7B, 0X4C, 0X6C, 0X0C, 0X04, 0X00, 0X10, 0X04
, 0X01, 0X45, 0X4E, 0X04, 0X00, 0X08, 0X00, 0X08, 0X1E, 0XD2
, 0XB9, 0X02, 0X00, 0X04, 0X00, 0X08, 0X0F, 0X69, 0XA5, 0X81
, 0X00, 0X02, 0X00, 0X83, 0X07, 0XB5, 0X2A, 0X40, 0X80, 0X42
, 0X40, 0X00, 0X43, 0XDA, 0X50, 0XA0, 0X40, 0X21, 0X20, 0X20
, 0X01, 0XED, 0X3E, 0X30, 0X20, 0X30, 0X80, 0X00, 0X10, 0XF6
, 0X9A, 0X68, 0X10, 0X18, 0X40, 0X00, 0X10, 0X7B, 0X51, 0XEC
, 0X08, 0X0C, 0X20, 0X00, 0X18, 0X3D, 0XA5, 0X6E, 0X04, 0X06
, 0X10, 0X04, 0X00, 0X1E, 0XD3, 0XE3, 0X02, 0X04, 0X04, 0X00
, 0X05, 0X0F, 0X69, 0X75, 0X81, 0X02, 0X02, 0X00, 0X81, 0X07
, 0XB4, 0XF9, 0X40, 0X81, 0X01, 0X02, 0X40, 0X43, 0XDA, 0X95
, 0X60, 0X40, 0X80, 0XC0, 0X00, 0X21, 0XED, 0X38, 0X10, 0X20
, 0X40, 0X60, 0X00, 0X20, 0XF6, 0X98, 0XD8, 0X10, 0X20, 0X30
, 0X00, 0X18, 0X7B, 0X50, 0X54, 0X08, 0X14, 0X00, 0X00, 0X04
, 0X3D, 0XA8, 0X2A, 0X04, 0X0A, 0X00, 0X00, 0X04, 0X1E, 0XD3
, 0X7F, 0X02, 0X05, 0X00, 0X09, 0X09, 0X0F, 0X6A, 0X54, 0X81
, 0X03, 0X04, 0X00, 0X00, 0X87, 0XD4, 0XAE, 0XD2, 0XED, 0X02
, 0X06, 0X08, 0X00, 0X03, 0X0F, 0X69, 0XC0, 0X81, 0X03, 0X04
, 0X00, 0X03, 0X07, 0XD5, 0X05, 0X54, 0X79, 0X02, 0X07, 0X02
, 0X00, 0X01, 0X0F, 0X69, 0XF1, 0X81, 0X03, 0X81, 0X00, 0X01
, 0X07, 0XB5, 0X2A, 0XC0, 0X81, 0XC0, 0X80, 0X01, 0X43, 0XEA
, 0X51, 0X29, 0X5D, 0X82, 0X01, 0X02, 0X80, 0X00, 0X87, 0XB4
, 0XDF, 0XC1, 0X00, 0X81, 0X40, 0X00, 0X83, 0XDA, 0X89, 0X20
, 0XA0, 0X00, 0XA0, 0X00, 0X41, 0XED, 0X3E, 0X30, 0X50, 0X00
, 0X50, 0X00, 0X60, 0XF6, 0X94, 0X38, 0X30, 0X18, 0X48, 0X00
, 0X10, 0X7D, 0X4A, 0X15, 0X2B, 0X60
};

//#ifdef __BAND_PRIORITY_SEARCH__
static kal_uint8 const NVRAM_EF_UMTS_BAND_PRIORITY_DEFAULT[] =
{
        /**
         * these bytes are used to set the priority of each band.
         * Total size: 22bytes (one byte for each band)
         * Value(Priority) range: 0x00(the highest) ~ 0xFF(the lowest)
         * Default value for each band: 0xFF
         *
         * Band    I    II    III   IV     V    VI    VII   VIII
         *      +-----------------------------------------------+
         * byte |  0  |  1  |  2  |  3  |  4  |  5  |  6  |  7  | 
         *      +-----------------------------------------------+
         *
         * Band   IX     X    XI    XII  XIII   XIV   XV    XVI
         *      +-----------------------------------------------+
         * byte |  8  |  9  | 10  | 11  | 12  | 13  | 14  | 15  | 
         *      +-----------------------------------------------+
         *
         * Band  XVII  XVIII  XIX   XX    XXI  XXII
         *      +-----------------------------------+
         * byte | 16  | 17  | 18  | 19  | 20  | 21  |
         *      +-----------------------------------+
         */
  0xFF, /* Band I */
  0xFF, /* Band II */
  0xFF, /* Band III */
  0xFF, /* Band IV */
  0xFF, /* Band V */
  0xFF, /* Band VI */
  0xFF, /* Band VII */
  0xFF, /* Band VIII */
  0xFF, /* Band IX */
  0xFF, /* Band X */
  0xFF, /* Band XI */
  0xFF, /* Band XII */
  0xFF, /* Band XIII */
  0xFF, /* Band XIV */
  0xFF, /* Band XV */
  0xFF, /* Band XVI */
  0xFF, /* Band XVII */
  0xFF, /* Band XVIII */
  0xFF, /* Band XIX */
  0xFF, /* Band XX */
  0xFF, /* Band XXI */
  0xFF  /* Band XXII */
};
//#endif /* __BAND_PRIORITY_SEARCH__ */

#endif /* __UMTS_FDD_MODE__ */

#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_R7__)
static nvram_ef_umts_dmcr_setting_struct const NVRAM_EF_UMTS_DMCR_SETTING_DEFAULT[] =
{
    /**
     * User can use this setting to control which operator (PLMN) need to disable DMCR feature.
     * If UE try to camp on cells of these PLMNs, DMCR feature is disable.
     *
     * The format of each PLMN is defined as below:
     * MCC1, MCC2, MCC3, MNC1, MNC2, MNC3,   //disable_PLMN[x]
     *
     * For example, if user want to disable DMCR on CHT(46692f)
     * add it into this list as below:
     * 0x04, 0x06, 0x06, 0x09, 0x02, 0x0f,   //disable_PLMN[0]
     */
    {
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[0]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[1]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[2]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[3]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[4]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[5]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[6]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[7]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[8]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[9]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[10]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[11]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[12]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[13]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //disable_PLMN[14]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f    //disable_PLMN[15]
    }
};

static nvram_ef_umts_sib_skip_setting_struct const NVRAM_EF_UMTS_SIB_SKIP_SETTING_DEFAULT[] =
{
    /**
     * ********** HIGH RISK!! Need to set it carafully. **********
     * If DMCR is not supported by some operators, may use this setting to speed up the CSFB time.
     * 'BUT' there are highly potential risks that side effects (ex: call drop) may happen if implicitly skipping SIB11/12.
     * Highly recommend 'NOT' to use this setting.
     *
     * User can use this setting to control which operator (PLMN) need to enable SIB11/12 skipping for CSFB.
     * If UE try to camp on cells of these PLMNs while CSFB is ongoing, SIB11/12 skipping is enable if DMCR not supported.
     *
     * The format of each PLMN is defined as below:
     * MCC1, MCC2, MCC3, MNC1, MNC2, MNC3,   //enable_PLMN[x]
     *
     * For example, if user want to enable SIB11/12 skipping on CHT(46692f)
     * add it into this list as below:
     * 0x04, 0x06, 0x06, 0x09, 0x02, 0x0f,   //enable_PLMN[0]
     */
    {
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[0]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[1]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[2]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[3]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[4]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[5]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[6]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[7]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[8]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[9]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[10]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[11]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[12]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[13]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f,   //enable_PLMN[14]
        0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f    //enable_PLMN[15]
    }
};
#endif /* __UMTS_FDD_MODE__ && __UMTS_R7__ */

#ifdef __UMTS_TDD128_MODE__
#ifdef __AST_TL1_TDD__
static kal_uint8 const NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT[] =
{
    /* PDCP part */
#if defined(__RFC2507_SUPPORT__) && defined(__CUSTOMIZE_RFC2507_SUPPORT__)
    0x02, /* PDCP_supportForRfc2507: supported */
#else
    0x01, /* PDCP_supportForRfc2507: not supported */
#endif /* __RFC2507_SUPPORT__ */

    0x01, /* MAX_HeaderCompressionLengthContext:  1024 */ 

    /* RLC part */
#ifdef __UMTS_R7__
        0x05, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150. */
#else
        0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb500 */
#endif

    //0x04, /* RRC_TotalRLC_AM_BufferSize: RRC_kb150(TDD_R4). For R5, remember to revise the later-release raw data in USIME
             //and keep buffer_size_R99 <= buffer_size_R5 */
    0x00, /* RRC_MaximumRLC_WindowSize: RRC_mws2047(TDD_R4) */
    //0x06, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am30(TDD_R4) */
#ifdef __UMTS_R7__
        0x04, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am30(TDD_R4) */
#else
        0x06, /* RRC_MaximumAM_EntityNumberRLC_Cap: RRC_am8(TDD_R4) */
#endif
    /* UL TRCH part */
    0x02, /* ul_TransChCapability.modeSpecificInfo.selection: RRC_UL_TransChCapability_modeSpecificInfo_tdd_selected */
    0x07, /* ul_TransChCapability.maxNoBitsTransmitted: RRC_b8960(TDD_R4) */
    0x00, /* ul_TransChCapability.maxConvCodeBitsTransmitted: RRC_b640(TDD_R4) */
    0x02, /* ul_TransChCapability.turboEncodingSupport.selection: RRC_TurboSupport_supported_selected */
    0x07, /* ul_TransChCapability.turboEncodingSupport.choice.supported: RRC_b8960 */
    0x02, /* ul_TransChCapability.maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsUL_e8 */
    0x04, /* ul_TransChCapability.maxTransmittedBlocks: RRC_MaxTransportBlocksUL_tb32 */
    0x05, /* ul_TransChCapability.maxNumberOfTFC: RRC_MaxNumberOfTFC_UL_tfc64 */
    0x00, /* ul_TransChCapability.maxNumberOfTF: RRC_tf32 */
    0x01, /* transportChannelCapability.ul_TransChCapability.modeSpecificInfo.choice.tdd.maxSimultaneousCCTrCH_Count: 1(TDD_R4 only) */
    /* DL TRCH part */
    0x07, /* maxNoBitsReceived: RRC_b8960(TDD_R4) */
    0x00, /* maxConvCodeBitsReceived: RRC_b640(TDD_R4) */
    0x02, /* turboDecodingSupport: RRC_TurboSupport_supported_selected */
    0x07, /* turboDecodingSupport.choice.supported: RRC_b8960 */
    0x01, /* maxSimultaneousTransChs: RRC_MaxSimultaneousTransChsDL_e8 */
    0x01, /* maxSimultaneousCCTrCH_Count: DL_TCH_MAXSIMCCTRCH_COUNT */
    0x03, /* maxReceivedTransportBlocks: RRC_MaxTransportBlocksDL_tb32 */
#ifdef __AST1001__
    0x05, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc128 */
#else /* __AST2001__ */
    0x04, /* maxNumberOfTFC: RRC_MaxNumberOfTFC_DL_tfc96 */
#endif
    0x01, /* maxNumberOfTF: RRC_tf64 */

    /* RF Frequency Capability Info */
    0x00, /* reserved, original is for RF band */
    0x00, /* reserve for future band use, currently this shall be set to 0 */
    0x01, /* 0: Power Class 1, 1: Power Class 2, 2: Power Class 3, 3: Power Class 4  */
    0x00, /* TDD_R4 sync with FDD, dummy byte */
    0x00, /* TDD_R4 sync with FDD, dummy byte */

    /* R99 CAP Additional part #5 */
    0x00, /* losslessSRNS_RelocationSupport: 1 supported */
    0x00, /* cipheringAlgorithmCap.stringData[0] */
#ifdef __UMTS_R7__
    //0x07, /* cipheringAlgorithmCap.stringData[1]: UEA2|UEA1|UEA0 */
    0x01,
#else
    0x01, /* cipheringAlgorithmCap.stringData[1]: UEA0*/
#endif

    0x00, /* integrityProtectionAlgorithmCap.stringData[0] */
#ifdef __UMTS_R7__
    //0x06  /* integrityProtectionAlgorithmCap.stringData[1]: UIA2|UIA1 */
    0x02
#else
    0x02  /* integrityProtectionAlgorithmCap.stringData[1]: UIA1 */
#endif

,   /* Capability for RRCE use (not part of UE capability which report to Network) */
       /* bit 8~3: not used */
#if defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__)
    0x02+
#endif /* defined(__NO_PSDATA_SEND_SCRI__) || defined(__FAST_DORMANCY__) */
#ifdef __FAST_DORMANCY__
    0x01+
#endif /* __FAST_DORMANCY__ */
    0x00

    , /* Capability for RRCE use (not part of UE capability which report to Network) */
                           /* bit 8~3: not used 
                                                 * bit 2: Turn on 3G Smart Paging Level 2 (RRCE listen paging each 2 DRX without learning)
                                                 * bit 1: Turn on 3G Smart Paging */
#ifdef __SMART_PAGING_3G_FDD__
#ifdef __SMART_PAGING_3G_FDD_OFF__ /* This compile option only defined in MT6280 chip, used to keep the code sync with MT6583 and further product (Smart paging not turn on in MT6280) */
    0x00+
#else
    0x01+
#endif /* __SMART_PAGING_3G_FDD_OFF__ */
#endif /* __SMART_PAGING_3G_FDD__ */
    0x00

    /* Access Stratum Release Indicator */
   ,
#if defined(__UMTS_R9__)
    0x05 /* RRC_AccessStratumReleaseIndicator_rel_9 */
#elif defined(__UMTS_R8__)
   0x04 /* RRC_AccessStratumReleaseIndicator_rel_8 */
#elif defined(__UMTS_R7__)
   0x03 /* RRC_AccessStratumReleaseIndicator_rel_7 */
#elif defined(__UMTS_R6__)
   0x02 /* RRC_AccessStratumReleaseIndicator_rel_6 */
#elif defined(__UMTS_R5__)
   0x01 /* RRC_AccessStratumReleaseIndicator_rel_5 */
#elif defined(__UMTS_R4__)
   0x00 /* RRC_AccessStratumReleaseIndicator_rel_4 */
#else
   0x00
#endif

    /* PHYCH part */
   ,0x03, /* DL PhyChCap -  dlPhyCh_maxNoDPCH_PDSCH_Codes: 3 */


                          /* r3_cap1: USIME_R3_Cap1
                            * bit 8~5: maxNoDPDCH_BitsTransmitted
                            * bit 4~0: maxNoPhysChBitsReceived */

   0x40+ /* UL PhyChCap - maxNoDPDCH_BitsTransmitted: RRC_MaxNoDPDCH_BitsTransmitted_b9600 */
   0x08, /* DL PhyChCap - maxNoPhysChBitsReceived: RRC_MaxNoPhysChBitsReceived_b19200 */


                          /* r3_cap2: USIME_R3_Cap2
                            * bit 8~7: not used
                            * bit 6: sfn_sfnType2Capability
                            * bit 5~4: multiModeCapability
                            * bit 3: supportOfMulticarrier
                            * bit 2: supportOfGSM
                            * bit 1: supportForSF_512 */
   0x00+ /* sfn_sfnType2Capability: 0x20 supported, 0x00 not supported */

#if defined(__UMTS_FDD_MODE__) && defined(__UMTS_TDD128_MODE__)
   0x10+ /* RRC_MultiModeCapability_fdd_tdd */
#elif defined(__UMTS_FDD_MODE__)
   0x08+ /* RRC_MultiModeCapability_fdd */
#elif defined(__UMTS_TDD128_MODE__)
   0x00+ /* RRC_MultiModeCapability_tdd */
#endif

   0x00+ /* supportOfMulticarrier: 0x04 supported, 0x00 not supported */
#if defined (__GSM_RAT__)
   0x02+ /* supportOfGSM: 0x02 supported, 0x00 not supported */
#endif
   0x00, /* USIME_supportForSF_512: 0x01 supported, 0x00 not supported */

                          /* r3_cap3: USIME_R3_Cap3
                            * bit 8: validity_CellPCH_UraPCH
                            * bit 7: rx_tx_TimeDifferenceType2Capable
                            * bit 6: supportForIPDL
                            * bit 5: supportForUE_GPS_TimingOfCellFrames
                            * bit 4~3: networkAssistedGPS_Supported
                            * bit 2: ue_BasedOTDOA_Supported
                            * bit 1: standaloneLocMethodsSupported */
#ifdef __UAGPS_CP_SUPPORT__
   0x80+ /* validity_CellPCH_UraPCH: 0x80: supported, 0x00 not supported */
#endif

   0x00+ /* rx_tx_TimeDifferenceType2Capable: 0x40: supported, 0x00 not supported */
   0x00+ /* supportForIPDL: 0x20: supported, 0x00 not supported */

#if defined(__UAGPS_CP_SUPPORT__) && defined(__L1_GPS_REF_TIME_SUPPORT__)
   0x00+ /* supportForUE_GPS_TimingOfCellFrames: 0x10: supported, 0x00 not supported */
#endif

#ifdef __UAGPS_CP_SUPPORT__
   0x08+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_bothNetworkAndUE_Based */
#else
   0x0C+ /* networkAssistedGPS_Supported: RRC_NetworkAssistedGPS_Supported_noNetworkAssistedGPS */
#endif

   0x00+ /* ue_BasedOTDOA_Supported: 0x02: supported, 0x00 not supported */

#ifdef __UAGPS_CP_SUPPORT__
   0x01+ /* standaloneLocMethodsSupported: 0x01: supported, 0x00 not supported */
#endif
   0x00

    /* R4 CAP */
#if defined(__UMTS_R4__) || defined(__UMTS_R5__)
    ,   // >#I
                           /* r4_cap1: USIME_R4_Cap1
                            * bit 8~6: not used
                            * bit 4: USIME_supportForRfc3095
                            * bit 3~0: maxROHC_ContextSessions */
    0x00+ /* USIME_supportForRfc3095: 0x10 support, 0x00 not support */
    0x00, /* maxROHC_ContextSessions: RRC_MaxROHC_ContextSessions_r4_s2 */

    0x00, /* reverseCompressionDepth_high_byte */
    0x00 /* reverseCompressionDepth_low_byte */
#endif /* defined(__UMTS_R4__) || defined(__UMTS_R5__) */

    /* R5 CAP */
#ifdef __UMTS_R5__
    ,   // >#I
                           /* r5_cap1: USIME_R5_Cap1
                            * bit 8~7: not used
                            * bit 6: supportForRfc3095ContextRelocation
                            * bit 5: supportOfUTRAN_ToGERAN_NACC
                            * bit 4: losslessDLRLCPDUSizeChange
                            * bit 2~3: dl_CapabilityWithSimultaneousHS_DSCHConfig 
                            * bit 1: dl_CapabilityWithSimultaneousHS_DSCHConfigValid */
    0x00+ /* supportForRfc3095ContextRelocation: 0x20 supported, 0x00 not supported */
    0x10+ /* supportOfUTRAN_ToGERAN_NACC: 0x10 supported, 0x00 not supported */
    0x00+ /* losslessDLRLCPDUSizeChange: 0x08 supported, 0x00 not supported */
    0x02+ /* dl_CapabilityWithSimultaneousHS_DSCHConfig: 0x00 kbps32, 0x02 kbps64, 0x04 kbps128, 0x06 kbps384*/
    0x01  /* fddPhysicalChannelCapab_hspdsch_edch: 0x01 valid, 0x00 not valid */
#endif /* __UMTS_R5__ */

    /* R6 CAP */
#ifdef __UMTS_R6__
    ,   // >#I
                          /* r6_cap1: USIME_R6_Cap1
                            * bit 8~5: not used
                            * bit 4: supportOfCSHandoverToGAN
                            * bit 3: doesNotBenifitFromBatteryConsumptionOptimization
                            * bit 2: supportForFDPCH 
                            * bit 1: supportForSIB11bis */
    0x00+ /* supportOfCSHandoverToGAN: 0x08 support, 0x00 not support */
#ifdef __NOT_BENEFIT_FROM_BATTERY_CONSUMPTION_OPTIMISATION__
    0x04+ /* doesNotBenifitFromBatteryConsumptionOptimization: 0x04 does not benefit, 0x00 benefit */
#endif 
    0x00+ /* supportForFDPCH: 0x02 supported, 0x00 not supported */
    //0x01,  /* supportForSIB11bis: 0x01 supported, 0x00 not supported */
    0x00   /*TDD not support but FDD support*/
#endif /* __UMTS_R6__ */

    /* R7 CAP */
#ifdef __UMTS_R7__
    ,   // >#I
                          /* r7_cap1: USIME_R7_Cap1
                            * bit 8: discontinuousDpcchTransmission
                            * bit 7: hsdschReceptionCellUraPch
                            * bit 6: hsdschReceptionCellFach
                            * bit 5: enhancedFdpch
                            * bit 4: hsscchlessHsdschOperation
                            * bit 3: mac_ehsSupport
                            * bit 2: supportOfTwoLogicalChannel
                            * bit 1: supportForCSVoiceoverHSPA */
#ifdef __ENHANCED_COMMON_STATE_SUPPORT__
    0x40+ /* hsdschReceptionCellUraPch: 0x40 supported, 0x00 not supported */
    0x20+ /* hsdschReceptionCellFach: 0x20 supported, 0x00 not supported*/
#endif

    0x00+ /* enhancedFdpch: 0x10 supported, 0x00 not supported */

#ifdef __CPC_SUPPORT__
    0x80+ /* discontinuousDpcchTransmission: 0x80 supported, 0x00 not supported */
    0x08+ /* hsscchlessHsdschOperation: 0x08 supported, 0x00 not supported */
#endif

#ifdef __MAC_EHS_SUPPORT__
    //0x04+ /* mac_ehsSupport: 0x04 supported, 0x00 not supported */
    0x00+   /*open this compile option but not surpport this capability*/
#endif
    0x00+ /* supportOfTwoLogicalChannel: 0x02 supported, 0x00 not supported */
#ifdef __CSHSPA_SUPPORT__
    0x00+  /* pdcp_supportForCSVoiceoverHSPA: 0x01 supported, 0x00 not supported */
#endif
    0x00,

                          /* r7_cap2: USIME_R7_Cap2
                            * bit 8~7: not used
                            * bit 6: supportofPSHandoverToGAN
                            * bit 5: supportofTxDivOnNonMIMOChannel
                            * bit 4: supportEDPDCHPowerInterpolation
                            * bit 3: supportForTwoDRXSchemesInPCH
                            * bit 2: supportForEDPCCHPowerBoosting
                            * bit 1: slotFormat4 */
    0x00+ /* supportofPSHandoverToGAN: 0x20 supported, 0x00 not supported */
#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x00+ /* supportofTxDivOnNonMIMOChannel: 0x10 supported, 0x00 not supported */
#endif
    0x00+ /* supportEDPDCHPowerInterpolation: 0x08 supported, 0x00 not supported */
    0x00+ /* supportForTwoDRXSchemesInPCH: 0x04 supported, 0x00 not supported */
    0x00+ /* supportForEDPCCHPowerBoosting: 0x02 supported, 0x00 not supported */
    0x00   /* slotFormat4: 0x01 supported, 0x00 not supported */
#endif /* __UMTS_R7__ */

    /* R8 CAP */
#ifdef __UMTS_R9__
    ,   // >#I
                          /* r9_cap1: USIME_R8_Cap1
                            * bit 5~8: eutraFeatureGroupIndicators
                            * bit 4: supportOfInterRATHOToEUTRATDD
                            * bit 3: supportOfEUTRATDD
                            * //bit 2: supportOfHsdschDrxOperation
                            * //bit 1: supportOfTargetCellPreConfig
                            * bit 2: supportOfSPSOperation
                            * bit 1: supportOfControlChannelDRXOperation */

#ifdef __LTE_RAT__
    0xC0+ /* eutraFeatureGroupIndicators: 0xC0 fully supported, 0x00 not supported */
    0x08+ /* supportOfInterRATHOToEUTRATDD: 0x08 supported, 0x00 not supported */
    0x04+ /* supportOfEUTRATDD: 0x04 supported, 0x00 not supported */
#endif


    0x02+ /* supportOfSPSOperation: 0x02 supported, 0x00 not supported */
    0x01+ /* supportOfControlChannelDRXOperation: 0x01 supported, 0x00 not supported */
    0x00,

                          /* r8_cap2: USIME_R8_Cap2
                            * bit 8: supportOfTS0
                            * bit 7: supportOfSFModeForHSPDSCHDualStream
                            * bit 6: supportCellSpecificTxDiversityinDC_Operation
                            * bit 5: supportForPriorityReselectionInUTRAN
                            * bit 4: supportOfCSG
                            * bit 3: supportOfMACiis
                            * bit 2: supportOfCommonEDCH
                            * bit 1: supportForRfc3095*/

    0x80+ /* supportOfTS0: 0x80 supported, 0x00 not supported */
    0x00+ /* supportOfSFModeForHSPDSCHDualStream: 0x40 supported, 0x00 not supported */

#ifdef __DCHSDPA_ADJ_FREQ_SUPPORT__
    0x00+ /* supportCellSpecificTxDiversityinDC_Operation: 0x20 supported, 0x00 not supported */
#endif

#ifdef __23G_PRI_RESEL_SUPPORT__
    0x10+ /* supportForPriorityReselectionInUTRAN: 0x10 supported, 0x00 not supported */
#endif

#ifdef __3G_CSG_SUPPORT__
    0x00+ /* supportOfCSG: 0x08 supported, 0x00 not supported */
#endif

#if defined(__MAC_IIS_SUPPORT__)
    0x04+ /* supportOfMACiis: 0x04 supported, 0x00 not supported */
#endif

#if defined(__COMMON_EDCH_SUPPORT__)
    0x02+ /* supportOfCommonEDCH: 0x02 supported, 0x00 not supported */
#endif


    0x00+  /* supportForRfc3095: 0x01 supported, 0x00 not supported */
    0x00,
							  /* r9_cap3: USIME_R8_Cap3
							   * bit 8: supportOfEUTRAFDD
							   * bit 7: supportOfInterRATHOToEUTRAFDD
							   * else: reserved
							   */
#ifdef __LTE_RAT__
#ifdef __4G_TDD_ONLY__
    0x00+ /*  not supportOfEUTRAFDD */
	0x00+ /* not supportOfInterRATHOToEUTRAFDD: 0x08 supported, 0x00 not supported */
#else 
	0x80+ /*  supportOfEUTRAFDD */
	0x40+ /* supportOfInterRATHOToEUTRAFDD: 0x08 supported, 0x00 not supported */
#endif
	0x00+ /* reserved */
    0x00
#endif
#endif /* __UMTS_R8__ */

};
#endif /* __AST_TL1_TDD__ */

/* The default data was encoded result of SCSI's ScsiFrequencyInfoRepository which saves the 15 plmns' 22 uarfcn. */
static kal_uint8 const NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT[] =
{0X00, 0X00
, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00
, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00, 0X00
};

#endif /* __UMTS_TDD128_MODE__ */

#endif /* __UMTS_RAT__ */


#ifdef  __BTMODULE_RFMD3500__
static kal_uint8 const NVRAM_EF_BTRADIO_RFMD3500_DEFAULT[] = {
/* BluetoothAddress                  ,  6 */ 0xAD,0x5A,0x00,0x00,0x00,0x00,
/* MinEncryptionSize                 ,  1 */ 0x01,
/* MaxEncryptionSize                 ,  1 */ 0x10,
/* HCITransportLayerParameters       ,  3 */ 0x02,0x00,0x00,
/* FixedPIN                          , 16 */ 0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
                                             0x00,0x00,0x00,0x00,0x00,0x00,
/* FixedPINLength                    ,  1 */ 0x00,
/* SleepEnableMask					 ,	1 */ 0x01,
/* LowPowerClockParameter	   	  	 ,  8 */ 0x03,0x02,0x00,0x00,0x00,0x10,0x00,0x00,
/* PowerControlConfiguration         , 13 */ 0x07,0x07,0x07,0x02,0x00,0x01,0x02,0x03,0x04,0x05,
                                             0x06,0x07,0x07,
/* SleepControlParameters            , 12 */ 0x00,0x00,0x14,0x10,0x20,0x30,0x30,0x30,0x30,0x00,
                                             0x03,0x02,
/* DebugControl                      ,  4 */ 0x00,0x00,0x2C,0x01,
/* LCandRMOverrideEnable             ,  4 */ 0x10,0x00,0x00,0x00,
/* RadioRegisterOverride             ,  6 */ 0x01,0x00,0x00,0x00,0x0D,0x7F,
/* CodecConfiguration                ,  8 */ 0x20,0x00,0x10,0x1F,0x00,0x0F,0x0F,0x02,
/* CVSDGainVolumeSettings            ,  6 */ 0x02,0x00,0x00,0x00,0x0E,0x0E,
/* VoiceSettings                     ,  2 */ 0x60,0x00,
/* UserBaudRate                      ,  3 */ 0x11,0x00,0x17,
/* CoexistenceParameters             ,  4 */// 0x02,0xA4,0x0E,0x00,
/* LowPowerDriftRate                 ,  1 */ 0x2D,
/* MaxTxPowerLevel                   ,  1 */ 0x04,
/* AdaptiveFrequencyHoppingParameters, 29 */ 0x02,0x00,0x3C,0x00,0x3C,0x00,0x00,0x01,0x0A,0x05,
                                             0x13,0x4F,0x02,0x08,0x01,0x0C,0x01,0x00,0x00,0x00,
                                             0x40,0x00,0x00,0x00,0x40,0x00,0x00,0x0A,0x05,
/* BufferSize                        ,  4 */ 0x7C,0x00,0x7C,0x00,
/* GPIO Mapping                      , 16 */ 0xFF,0x01,0xFF,0x02,0x04,0x06,0xFF,0x00,0xFF,0x00,
                                             0xFF,0x00,0xFF,0x00,0xFF,0x00,
/* GPIO Polarity                     ,  4 */ 0x00,0x00,0x04,0x00
};
#endif /* __BTMODULE_RFMD3500__*/



#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
static kal_uint8 const NVRAM_EF_MNL_SETTING_DATA_DEFAULT[] = {
/* Internal LNA Enable          ,  1  */ 0x00,
/* TCXO Frequency Drift         ,  1  */ 0x01,
/* SBAS Mode                    ,  1  */ 0x00,
/* Clock Type                   ,  1  */ 0x00,
/* Frequency Error for XTAL     ,  1  */ 0x00,
/* Frame Sync Enable            ,  1  */ 0x00,
/* Reserved                     ,  10 */ 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
};
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined (__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
//#if defined(__BTMODULE_MT6276__)|| defined(__BTMODULE_MT6622__) || defined(__BTMODULE_MT6626__)
static kal_uint32 const NVRAM_EF_BWCS_SETTING_DATA_DEFAULT[] =
{
    /* Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Non Real Time RSSI Threshold : BT / WIFI1 / WIFI2 */
    73, 73, 73,
    /* Antenna path compensation */
    10,
    /* antenna path switch protection period, Unit is frames (4.615us) */
    2000,
    /* TX Flow control : medium time / period time */
    0x0E00, 0x01,
    /* BT RX Range : Low / High */
    0xC4, 0xE2,
    /* BT TX power : WIFI OFF / WIFI SCO / WIFI ACL */
    0x07, 0x07, 0x06,
    /* Reserved                     ,  5 */
    0x00, 0x00, 0x00, 0x00, 0x00
};
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	/* #if 0 */
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */

#if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
#define TCM_CONTEXT_ID_DEFAULT_VALUE (0xFF)

static nvram_ef_tcm_PDP_profile_record_struct const NVRAM_EF_TCM_CID_0_PROFILE_DEFAULT[] = {
                  /* context_id, pdp_addr_type, pdp_addr_len. */
                  TCM_CONTEXT_ID_DEFAULT_VALUE, 0x21, 0x01,

                  /* addr_val[16]. */                  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* apn_len. */
                  0x00,

                  /* apn[100]. */
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* pcomp_algo, dcomp_algo, context_type(0:PRIMARY_CONTEXT), primary_context_id . */
                  0x02, 0x02, 0x00, TCM_CONTEXT_ID_DEFAULT_VALUE,

                  /* reserved (AT_definition). */
                  0x01, /* 0000 0001. Only TCM_CGDCONT_DEFINED is set. Others are not. */
                  
                  /* req_n201u. */
                  0x0000,

                  /* p_cscf_discovery, im_cn_signalling_flag, request_type. */
                  0x00, 0x00, 0x01, 

                  /* reserved2. */
                  0x00
};

static nvram_ef_tcm_PDP_profile_record_struct const NVRAM_EF_TCM_PDP_PROFILE_DEFAULT[] = {
                  /* context_id, pdp_addr_type, pdp_addr_len. */
                  TCM_CONTEXT_ID_DEFAULT_VALUE, 0x21, 0x01,

                  /* addr_val[16]. */                  
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* apn_len. */
                  0x08,

                  /* apn[100]. */
                  0x69, 0x6E, 0x74, 0x65, 0x72, 0x6E, 0x65, 0x74, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  /* pcomp_algo, dcomp_algo, context_type(0:PRIMARY_CONTEXT), primary_context_id . */
                  0x02, 0x02, 0x00, TCM_CONTEXT_ID_DEFAULT_VALUE,

                  /* reserved (AT_definition). */
                  0x01, /* 0000 0001. Only TCM_CGDCONT_DEFINED is set. Others are not. */
                  
                  /* req_n201u. */
                  0x0000,

                  /* p_cscf_discovery, im_cn_signalling_flag, request_type. */
                  0x00, 0x00, 0x01, 

                  /* reserved2. */
                  0x00
};
#endif /* #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__) */

#ifdef __VOLTE_SUPPORT__
static nvram_ef_vdm_ads_profile_struct const NVRAM_EF_VDM_ADS_PROFILE_DEFAULT[] =
{
    // nvram_ef_vdm_ads_profile_struct
    {
        // nvram_vdm_ads_profile_normal_struct (profile_normal)
        {
            // nvram_vdm_ads_general_profile_struct (general_setting_normal)
            {
                0x1,    // allow_cs = 1
                0x1,    // allow_ims = 1
                0x3,    // max_attempt_total_num = 3
                0x1,    // max_attempt_consecutive_cs_num = 1
                0x2,    // max_attempt_consecutive_ims_num = 2
                0x0,    // allow_recursive_cs = 0
                0x0,    // allow_recursive_ims = 0
                0x1,    // max_nw_selection_count = 1
                0x20,   // ads_guard_timer_length = 32 (*1s)
                0x0,    // wait_for_oos = 0
                0x1,    // wait_for_irat = 1
                0x1,    // wait_for_nas_nwsel = 1
                0x0,    // allow_csfb_when_nas_detached = 0
                0x0,    // allow_ims_when_nas_detached = 0
                0x0,    // allow_ims_when_ims_unreged = 0
                0x0,    // allow_ims_with_negative_imsvops_eutran = 0
                0x0,    // allow_ims_with_negative_imsvops_utran = 0
                0x0,    // reserved1
                0x0,    // reserved2
                0x0     // reserved3                        
            },
            
            /* normal call specific settings */        
            0x1,    // allow_cs_during_ssac_barring = 1
            0x1,    // reset_ssac_barring_lte_mobility = 1
            0x1,    // reset_ssac_barring_4g32_mobility = 1
            0x0     // reserved3

        },

        // nvram_vdm_ads_profile_emerg_struct (profile_emerg)
        { 
            // nvram_vdm_ads_general_profile_struct (general_setting_emerg)
            {
                0x1,    // allow_cs = 1
                0x1,    // allow_ims = 1
                0x3,    // max_attempt_total_num = 3
                0x1,    // max_attempt_consecutive_cs_num = 1
                0x2,    // max_attempt_consecutive_ims_num = 2
                0x0,    // allow_recursive_cs = 0
                0x0,    // allow_recursive_ims = 0
                0x1,    // max_nw_selection_count = 1
                0x96,   // ads_guard_timer_length = 150 (*1s)
                0x1,    // wait_for_oos = 1
                0x1,    // wait_for_irat = 1
                0x1,    // wait_for_nas_nwsel = 1
                0x1,    // allow_csfb_when_nas_detached = 1
                0x1,    // allow_ims_when_nas_detached = 1
                0x1,    // allow_ims_when_ims_unreged = 1
                0x1,    // allow_ims_with_negative_imsvops_eutran = 1
                0x1,    // allow_ims_with_negative_imsvops_utran = 1
                0x0,    // reserved1
                0x0,    // reserved2
                0x0     // reserved3                        
            }, 
            /* emergency call specific settings */        
            0x0,    // allow_ims_with_negative_emb_eutran = 0
            0x0,    // allow_ims_with_negative_emb_utran = 0
            0x0,    // allow_ims_with_negative_sib_emc_eutran = 0
            0x0,    // allow_ims_with_negative_sib_emc_utran
            0x1,    // prefer_ims_in_lte_limited_srv = 1
            0x0,    // reserved1
            0x0,    // reserved2
            0x0     // reserved3
        }
    }
};
#endif /* __VOLTE_SUPPORT__ */


#if defined (__MOD_IMC__)
static nvram_ef_ims_profile_record_struct const NVRAM_EF_IMS_PROFILE_DEFAULT[] = 
{
    {
        /* nvram_ua_struct */
        {
            0x000013C4, // local_port = 5060
            0x0000C350, // ipsec_local_port_start = 50000
            0x00000032, // ipsec_local_port_range = 50
            0x00009C40, // rtp_rtcp_local_port_start = 40000
            0x00001388, // rtp_rtcp_local_port_range = 5000
            0x00001388, // rtcp_interval = 5000
            0x00000000, // dscp = 0
            0x000927C0, // register_expiry = 600000
            0x000001F4, // UA_reg_t1_timer = 500
            0x00000FA0, // UA_reg_t2_timer = 4*1000 = 4000
            0x00001388, // UA_reg_t4_timer = 5*1000 = 5000
            0x00000000, // UA_reg_retry_base_time
            0x00000000, // UA_reg_retry_max_time
            0x00000E10, // UA_call_conf_subtimer = 3600
            0x0000EA60, // UA_call_session_timer = 60000
            0x00001010, // UA_call_amr_fmt_variant = 0x1010

            /* VoLTE_Setting_SIP_Force_Use_UDP */
            /* VoLTE_Setting_SIP_TCP_On_Demand */
            /* VoLTE_Setting_SIP_TCP_MTU_Size  */
            0x01, 0x01, 0x0514,  /* 1300 */

            0x0708,             // UA_call_session_min_se = 1800
            0x01E6,             // UA_call_rej_code = 486
            0x01E0,             // UA_call_no_resource_code = 480
            0x01E8,             // UA_call_rej_media_code = 488
            0x01E6,             // UA_call_rej_by_user_code = 486
            0x0000,             //operator_code = 0
            0x00C8,             //sms_rspcode = 200
            0x0000,
            0x00,                   // local_sip_protocol_type = 0(UDP), 1(TCP)
            0x14,                   // UA_g711_ptime = 20
            0x14,                   // UA_g726_ptime = 20
            0x02,                   // UA_call_codec_order1 = 2 (AMR WB)
            0x01,                   // UA_call_codec_order2 = 1 (AMR NB)
            0x00,                   // UA_call_codec_order3 = 0 
            0x50,                   // UA_call_def_max_ptime = 80
            0x14,                   // UA_call_def_ptime = 20
            0x61,                   // UA_call_amr_pt = 97
            0x62,                   // UA_call_amr_wb_pt = 98
            0x63,                   // UA_call_h264_pt = 99
            0x01,                   // UA_call_g729_annexb = 1
            0x14,                   // UA_call_g729_ptime = 20
            0x00,                   // UA_call_priority = 0
            0x00,                   // UA_call_privacy = 0
            0x01,                   // UA_call_session_flag = 1
            0x01,                   // UA_call_tel_evt = 1
            0x65,                   // UA_call_tel_evt_pt = 101
            0x01,                   // UA_call_precondition 0:disable, 1:enable
            0x00,                   // early media = 0
            0x00,                   // mwi_license = 0
            0x00,                   // UA_reg_keep_alive = 0, 0: no keep alive, >0: seconds for keep alive timer 
            0x03,                   // bitmap: 0x03 (sip+tel, no urn)
            0x01,                   // UA_net_ipsec = 1
            0x00,                   // UA_reg_uri_with_port = 0
            0x03,                   // UA_reg_ipsec_algo = 3
            0x00,                   // UA_reg_http_digest = 0(disable)
            0x00,                   // UA_reg_specific_ipsec_algo, bitmap, same to UA_reg_ipsec_algo
            0x00,                   // UA_call_mo_invite_to_bw_cnf_time = 0
            0x00,                   // pad2
            0x00,                   // pas3
            0x00,                   // pad4
            {
                0x56, 0x6F, 0x4C, 0x54, // user_agent = "VoLTE UA"
                0x45, 0x20, 0x55, 0x41,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },                              
            {
                //UA_call_amr_mode_set = 0,1,2,3,4,5,6,7
                0x30, 0x2C, 0x31, 0x2C, // 0,1,
                0x32, 0x2C, 0x33, 0x2C, // 2,3,
                0x34, 0x2C, 0x35, 0x2C, // 4,5,
                0x36, 0x2C, 0x37, 0x00  // 6,7
            },
            {
                //UA_call_amr_wb_mode_set = 0,1,2,3,4,5,6,7,8
                0x30, 0x2C, 0x31, 0x2C, // 0,1,
                0x32, 0x2C, 0x33, 0x2C, // 2,3,
                0x34, 0x2C, 0x35, 0x2C, // 4,5,
                0x36, 0x2C, 0x37, 0x2C, // 6,7,
                0x38, 0x00, 0x00, 0x00  // 8
            },
            {
                // icsi_1 = "urn:urn-7:3gpp-service.ims.icsi.mmtel"
                0x75, 0x72, 0x6E, 0x3A, // urn:
                0x75, 0x72, 0x6E, 0x2D, // urn-
                0x37, 0x3A, 0x33, 0x67, // 7:3g
                0x70, 0x70, 0x2D, 0x73, // pp-s
                0x65, 0x72, 0x76, 0x69, // ervi
                0x63, 0x65, 0x2E, 0x69, // ce.i
                0x6D, 0x73, 0x2E, 0x69, // ms.i
                0x63, 0x73, 0x69, 0x2E, // csi.
                0x6D, 0x6D, 0x74, 0x65, // mmte
                0x6C, 0x00, 0x00, 0x00, // l
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // icsi_2 = "urn:urn-7:3gpp-service.ims.icsi.mmtel"
                0x75, 0x72, 0x6E, 0x3A, // urn:
                0x75, 0x72, 0x6E, 0x2D, // urn-
                0x37, 0x3A, 0x33, 0x67, // 7:3g
                0x70, 0x70, 0x2D, 0x73, // pp-s
                0x65, 0x72, 0x76, 0x69, // ervi
                0x63, 0x65, 0x2E, 0x69, // ce.i
                0x6D, 0x73, 0x2E, 0x69, // ms.i
                0x63, 0x73, 0x69, 0x2E, // csi.
                0x6D, 0x6D, 0x74, 0x65, // mmte
                0x6C, 0x00, 0x00, 0x00, // l
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // icsi_3 = "urn:urn-7:3gpp-service.ims.icsi.mmtel"
                0x75, 0x72, 0x6E, 0x3A, // urn:
                0x75, 0x72, 0x6E, 0x2D, // urn-
                0x37, 0x3A, 0x33, 0x67, // 7:3g
                0x70, 0x70, 0x2D, 0x73, // pp-s
                0x65, 0x72, 0x76, 0x69, // ervi
                0x63, 0x65, 0x2E, 0x69, // ce.i
                0x6D, 0x73, 0x2E, 0x69, // ms.i
                0x63, 0x73, 0x69, 0x2E, // csi.
                0x6D, 0x6D, 0x74, 0x65, // mmte
                0x6C, 0x00, 0x00, 0x00, // l
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // icsi_4 = "urn:urn-7:3gpp-service.ims.icsi.mmtel"
                0x75, 0x72, 0x6E, 0x3A, // urn:
                0x75, 0x72, 0x6E, 0x2D, // urn-
                0x37, 0x3A, 0x33, 0x67, // 7:3g
                0x70, 0x70, 0x2D, 0x73, // pp-s
                0x65, 0x72, 0x76, 0x69, // ervi
                0x63, 0x65, 0x2E, 0x69, // ce.i
                0x6D, 0x73, 0x2E, 0x69, // ms.i
                0x63, 0x73, 0x69, 0x2E, // csi.
                0x6D, 0x6D, 0x74, 0x65, // mmte
                0x6C, 0x00, 0x00, 0x00, // l
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                0x00, 0x00, 0x00, 0x00, // UA_phone_context
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                0x2B, 0x31, 0x38, 0x38, // UA_reg_auth_name = +18860000042@srnims3.srnnam.nsn-rdnet.net
                0x36, 0x30, 0x30, 0x30,
                0x30, 0x30, 0x34, 0x32,
                0x40, 0x73, 0x72, 0x6E,
                0x69, 0x6D, 0x73, 0x33,
                0x2E, 0x73, 0x72, 0x6E,
                0x6E, 0x61, 0x6D, 0x2E,
                0x6E, 0x73, 0x6E, 0x2D,
                0x72, 0x64, 0x6E, 0x65,
                0x74, 0x2E, 0x6E, 0x65,
                0x74, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                0x69, 0x6D, 0x73, 0x31, // UA_reg_auth_password = ims123456
                0x32, 0x33, 0x34, 0x35,
                0x36, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                0x00, 0x00, 0x00, 0x00, // UA_phone_context_associated_impu
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                0x00, 0x00, 0x00, 0x00, // UA_conf_factory_uri 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
           }
        },

        /* nvram_imc_struct */
        {
            0x00000BB8, // resource_retain_timer = 3000ms (3 seconds)
            0x00002710, // emergency_pdn_retain_timer = 10000ms (10 seconds)
            0x00001388, // auto_re_reg_timer = 5000ms (5 sec)
            0x00000000, // poweroff_detach_timer = ??
            0x00000005, // poweroff_ims_dereg_timer = 5 seconds
            0x00000000, // emergency_reg_retain_timer = 0 seconds, in ms
            0x02,       // PCO, reference enum in imcb_imc_struct.h
            0x01,       // DHCP
            0x04,       // MO
            0x05,       // MANUAL
            0x03,       // SIM
            0x00,
            0x00,
            0x00,
            0x01,                   // set_pcscf_discovery_via_nas = 1
            0x00,                   // voice_bearer_ctrl
            0x01,                   // default_pcscf_address_is_v4 (v4:1, v6:0)
            0x00,                   // force_user_account_by_manual (default: 0)
            0x01,                   // set_ue_im_cn_signaling_flag = 1
            0x01,                   // check_nw_im_cn_signaling_flag = 1
            0x05,                   // ims_signaling_qci = 5
            0x01,                   // ims_voice_qci = 1
            0x02,                   // ims_video_qci = 2
            0x03,                   // ims_v4v6_preference = 3
        /* pcscf_manual_list? */
            0x00,                   // pcscf_manual_support = 0
            0x00,                   // pcscf_mo_support = 0
            0x01,                   // pcscf_sim_support = 1
            0x01,                   // pcscf_pco_renew_support = 1
            0x01,                   // emergency_call_learning_support = 1
            0x01,                   // home_detected_emergency_call_support = 1
            0x01,                   // sms_support = 1
            0x01,                   // voice_support = 1
            0x00,                    // video_over_ps_support = 0 (0:disable, 1:enable)
            0x01,                    // resource_allocation_mode = 1 (0:UE initial, 1: NW only)(reference to TS24.167, ICSI_Resource_Allocation_Mode)
            0x01,                    // icsi_resource_allocation_mode_1 = 1
            0x01,                    // icsi_resource_allocation_mode_2 = 1
            0x01,                    // icsi_resource_allocation_mode_3 = 1
            0x01,                    // icsi_resource_allocation_mode_4 = 1
            {
                //default pcscf address
                0xC0, 0xA8, 0x00, 0x01, // 192.168.0.1
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // default_psismsc = "sip:smsc@ims.mnc001.mcc001.3gppnetwork.org"
                0x73, 0x69, 0x70, 0x3A, // sip:
                0x73, 0x6D, 0x73, 0x63, // smsc
                0x40, 0x69, 0x6D, 0x73, // @ims
                0x2E, 0x6D, 0x6E, 0x63, // .mnc
                0x30, 0x30, 0x31, 0x2E, // 001.
                0x6D, 0x63, 0x63, 0x30, // mcc0
                0x30, 0x31, 0x2E, 0x33, // 01.3
                0x67, 0x70, 0x70, 0x6E, // gppn
                0x65, 0x74, 0x77, 0x6F, // etwo
                0x72, 0x6B, 0x2E, 0x6F, // rk.o
                0x72, 0x67, 0x00, 0x00, // rg
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // manual_impi = "310886000000042@ims.mnc688.mcc310.3gppnetwork.org"
                0x33, 0x31, 0x30, 0x38, // 3108
                0x38, 0x36, 0x30, 0x30, // 8600
                0x30, 0x30, 0x30, 0x30, // 0000
                0x30, 0x34, 0x32, 0x40, // 042@
                0x69, 0x6D, 0x73, 0x2E, // ims.
                0x6D, 0x6E, 0x63, 0x36, // mnc6
                0x38, 0x38, 0x2E, 0x6D, // 88.m
                0x63, 0x63, 0x33, 0x31, // cc31
                0x30, 0x2E, 0x33, 0x67, // 0.3g
                0x70, 0x70, 0x6E, 0x65, // ppne
                0x74, 0x77, 0x6F, 0x72, // twor
                0x6B, 0x2E, 0x6F, 0x72, // k.or
                0x67, 0x00, 0x00, 0x00, // g
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // manual_impu = "sip:+18860000042@srnims3.srnnam.nsn-rdnet.net"
                0x73, 0x69, 0x70, 0x3A, // sip:
                0x2B, 0x31, 0x38, 0x38, // +188
                0x36, 0x30, 0x30, 0x30, // 6000
                0x30, 0x30, 0x34, 0x32, // 0042
                0x40, 0x73, 0x72, 0x6E, // @srn
                0x69, 0x6D, 0x73, 0x33, // ims3
                0x2E, 0x73, 0x72, 0x6E, // .srn
                0x6E, 0x61, 0x6D, 0x2E, // nam.
                0x6E, 0x73, 0x6E, 0x2D, // nsn-
                0x72, 0x64, 0x6E, 0x65, // rdne
                0x74, 0x2E, 0x6E, 0x65, // t.ne
                0x74, 0x00, 0x00, 0x00, // t
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            },
            {
                // manual_domain_name = "srnims3.srnnam.nsn-rdnet.net"
                0x73, 0x72, 0x6E, 0x69, // srni
                0x6D, 0x73, 0x33, 0x2E, // ms3.
                0x73, 0x72, 0x6E, 0x6E, // srnn
                0x61, 0x6D, 0x2E, 0x6E, // am.n
                0x73, 0x6E, 0x2D, 0x72, // sn-r
                0x64, 0x6E, 0x65, 0x74, // dnet
                0x2E, 0x6E, 0x65, 0x74, // .net
                0x00, 0x00, 0x00, 0x00, 
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00,
                0x00, 0x00, 0x00, 0x00
            }
        }
    }
};
static nvram_ef_ltecsr_profile_record_struct const NVRAM_EF_LTECSR_PROFILE_DEFAULT[] = 
{
	KAL_TRUE, //dtx_enable
    30000, //silence_dropcall_threshold
	0, //jbm_load_params_enable
	3, //jbm_prebuf_len
	10, //jbm_jitter_max_depth
	4 //jbm_jitter_full_offset
};
#endif /*__MOD_IMC__ */

#if !defined(__CUSTOMIZED_PORT_SETTING__)
static port_setting_struct const NVRAM_EF_PORT_SETTING_DEFAULT[]=
{
// ################################################
// Record 1
// ################################################
    {
    /********************************************/
    //      TST_PORT
    /********************************************/
    #if defined(__ANDROID_MODEM__)
        uart_port_dhl_sp,
    #else
        uart_port_usb2,
    #endif

    /********************************************/
    //      PS_UART_PORT 
    /********************************************/
    #if defined(__SMART_PHONE_MODEM__)
        uart_port_at_ccci,
    #else
        uart_port_usb,
    #endif

    /********************************************/
    //      TST_BAUDRATE
    /********************************************/
        921600,

    /********************************************/
    //      PS_BAUDRATE
    /********************************************/
        115200,


        KAL_FALSE,                   /* High SpeedSIM */
        0,                           /* SWDBG */
    #if defined(__ONLY_ONE_UART__)
        1,                           /* uart power setting (0x03) */
    #else
        3,
    #endif

        uart_port_null,              /* CTI uart port: uart_null (value is 0x63 (99) */
        0,                           /* CTI baud rate: auto*/

    /********************************************/
    //      TST_PORT_L1
    /********************************************/
    #if defined(__ANDROID_MODEM__)
        uart_port_dhl_sp,
    #else
        uart_port_usb2,
    #endif

    /********************************************/
    //      TST_BAUDRATE_L1
    /********************************************/
        921600,


        0,                           /* tst output mode*/
    #if !defined( __UL1_STANDALONE__ )
        0,                            /* USB logging mode */
    #else
        #if defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__)
            2,
        #else
            1,
        #endif /* defined(__MODEM_3G_LOGGING__) && defined(_DSPIRDBG__) */
    #endif /*  __UL1_STANDALONE__  */

        uart_port_null,     //TST-DSP
        921600,             //TST-DSP baudrate

    /********************************************/
    //      usb_cdrom_config
    /********************************************/
        0,       // USB CD-ROM config,  0:CD-ROM , 1: COM

    /********************************************/
    //      SPEECH_PORT
    /********************************************/
        uart_port_usb4,

    /********************************************/
    //      PS_UART_PORT_2
    /********************************************/
	#if defined(__MODEM_CARD__)
        uart_port_usb3
    #else
		uart_port_null
	#endif
    },
};
#endif /* !defined(__CUSTOMIZED_PORT_SETTING__) */

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
static kal_uint8 const NVRAM_EF_SMSAL_SMS_DEFAULT[] = {
    0xfe,                            /* status */
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0xFF,
    0xFF, 0xFF, 0xFF, 0xFF
};
#endif

#ifndef __CB_CHANNEL_ONLY_STORED_IN_NVRAM__
/* Cell Broadcast Setting. */
/* The channels set will shown in MMI */
/* This setting may be changed by customer. DON'T remove it. */
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_me_mask, default all cbmir turn on */
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, /* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 1*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 2*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 3*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 4*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 5*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 6*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 7*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 8*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 9*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 10*/
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 11*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 12*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 13*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 14*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 15*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 16*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 17*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 18*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 19*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 20*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 21*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 22*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 23*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 24*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 25*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 26*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 27*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 28*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 29*/ 
    0xFF, 0xFF, 0xFF, 0xFF  /*Range 30*/ 
};
#else
static kal_uint8 const COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT[] =
{
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_mask, default all cbmir turn on */ 
    0xFF, 0xFF, 0xFF, 0xFF, /* cbmir_me_mask, default all cbmir turn on */
    0xFF, 0xFF, 0xFF, 0xFF, /* dcs_mask, default all dcs turn on */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[0] ~ dcs[4] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[5] ~ dcs[9] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[10] ~ dcs[14] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[15] ~ dcs[19] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[20] ~ dcs[24] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, /* dcs[25] ~ dcs[29] */
    0xFF, 0xFF, 0xFF, 0xFF, 0xFF,/* cbmi_me_mask, default all ME cbmi turn on */ 
    0xFF, 0xFF, 0xFF, /* cbmi_sim_mask, default all SIM cbmi turn on */
#ifndef __CMAS__
    0xFF, 0xFF, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* CH 2  */
    0xFF, 0xFF, /* CH 3  */
    0xFF, 0xFF, /* CH 4  */
    0xFF, 0xFF, /* CH 5  */
    0xFF, 0xFF, /* CH 6  */
    0xFF, 0xFF, /* CH 7  */
    0xFF, 0xFF, /* CH 8  */
    0xFF, 0xFF, /* CH 9  */
    0xFF, 0xFF, /* CH 10 */
    0xFF, 0xFF, /* CH 11 */
    0xFF, 0xFF, /* CH 12 */
    0xFF, 0xFF, /* CH 13 */
#else
    0x11, 0x12, /* CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0x11, 0x13, /* CH 2  */
    0x11, 0x14, /* CH 3  */
    0x11, 0x15, /* CH 4  */
    0x11, 0x16, /* CH 5  */
    0x11, 0x17, /* CH 6  */
    0x11, 0x18, /* CH 7  */
    0x11, 0x19, /* CH 8  */
    0x11, 0x1A, /* CH 9  */
    0x11, 0x1B, /* CH 10 */
    0x11, 0x1C, /* CH 11 */
    0x11, 0x1D, /* CH 12 */
    0x11, 0x1E, /* CH 13 */
#endif
    0xFF, 0xFF, /* CH 14 */
    0xFF, 0xFF, /* CH 15 */
    0xFF, 0xFF, /* CH 16 */
    0xFF, 0xFF, /* CH 17 */
    0xFF, 0xFF, /* CH 18 */
    0xFF, 0xFF, /* CH 19 */
    0xFF, 0xFF, /* CH 20 */
    0xFF, 0xFF, /* CH 21 */
    0xFF, 0xFF, /* CH 22 */
    0xFF, 0xFF, /* CH 23 */
    0xFF, 0xFF, /* CH 24 */
    0xFF, 0xFF, /* CH 25 */
    0xFF, 0xFF, /* CH 26 */
    0xFF, 0xFF, /* CH 27 */
    0xFF, 0xFF, /* CH 28 */
    0xFF, 0xFF, /* CH 29 */
    0xFF, 0xFF, /* CH 30 */
    0xFF, 0xFF, /* CH 31 */
    0xFF, 0xFF, /* CH 32 */
    0xFF, 0xFF, /* CH 33 */
    0xFF, 0xFF, /* CH 34 */
    0xFF, 0xFF, /* CH 35 */
    0xFF, 0xFF, /* CH 36 */
    0xFF, 0xFF, /* CH 37 */
    0xFF, 0xFF, /* CH 38 */
    0xFF, 0xFF, /* CH 39 */
    0xFF, 0xFF, /* CH 40 */
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 1*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 2*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 3*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 4*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 5*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 6*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 7*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 8*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 9*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 10*/
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 11*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 12*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 13*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 14*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 15*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 16*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 17*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 18*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 19*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 20*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 21*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 22*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 23*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 24*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 25*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 26*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 27*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 28*/ 
    0xFF, 0xFF, 0xFF, 0xFF, /*Range 29*/ 
    0xFF, 0xFF, 0xFF, 0xFF  /*Range 30*/ 
};
#endif

/* UEM*/
static kal_uint8 const NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT[] = {
                   'M',  'T',  'K',  '1', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#ifdef __DM_MO_SUPPORT__
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#else
                   'M',  'T',  'K',  '2', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#endif
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '3', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '4', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '5', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                   'M',  'T',  'K',  '6', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                   'M',  'T',  'K',  '7', 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,

                  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
                  };





static kal_uint8 const NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT[] ={
    /* High 8 bit stores Test mode. Eg. CTA/FTA/IOT...   
         * And the value follow the rule like this:
         * 0x00  ==> Real NW
         * 0x01  ==> CTA
         * 0x02  ==> FTA
         * 0x03  ==> IOT
         * 0x04  ==> OPERATOR
         * ...
         */
    0x00,   
    /* Low 24 bit store the Special setting according to each MODE
         */
    0x00,0x00,
#ifdef __UE_SIMULATOR__
    0x02
#else
    0x00
#endif
};
#ifdef __LTE_RAT__
static nvram_ef_epsloci_epsnsc_tin_struct const NVRAM_EF_EPSLOCI_EPSNSC_TIN_DEFAULT[] =
{
    {
        {/* EPSLOCI, 18 bytes */
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
        },
        {/* EPSNSC, 54 bytes */
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
        0xFF, 0xFF, 0xFF, 0xFF
        },
        /* TIN */
        0x00
    },
};

static nvram_ef_lte_preference_struct const NVRAM_EF_LTE_PREFERENCE_DEFAULT[] =
{
    {
#if defined(__SGLTE__) || defined(__DISABLE_CSCALL__) || defined(__DISABLE_SMS__)
        0x01,       /* restrict to Data Centric for MMDC */
#else
#if (defined(__GSM_RAT__) || defined(__UMTS_RAT__))
        0x00,       /* with 2/3G, vioce centric */
#else
        0x01,       /* with 4G only, data centric */
#endif
#endif /* __SGLTE__ */

        /* voice domain preference */
#ifdef __VOLTE_SUPPORT__
#if (defined(__GSM_RAT__) || defined(__UMTS_RAT__))
        0x03,       /* IMS PS voice preferred */
#else
        0x04,       /* IMS PS voice only */
#endif /* __GSM_RAT__ || __UMTS_RAT__ */
#else /* __VOLTE_SUPPORT__ */
        0x01,       /* CS voice only */
#endif /* __VOLTE_SUPPORT__ */

        /* SMS over IP */
#ifdef __IMS_SUPPORT__        
        0x01,
#else /* __IMS_SUPPORT__ */
        0x00,
#endif /* __IMS_SUPPORT__ */

        /* SMS over SGs */
        0x01,

        /* UE mode profile */
        0x01,

        /* UE mode */
        0x04,
        0x00,
        0x00,

        /* general feature */
        0x00, 0x00, 0x00, 0x00,
        
        /* R10 CR */
#ifdef __DOCOMO_IOT_EMM_R10_DISABLE__
        0x00, 0x00, 0x00, 0x00,
#else // __DOCOMO_IOT_EMM_R10_DISABLE__
        0x01, 0x00, 0x00, 0x00,
#endif /* __DOCOMO_IOT_EMM_R10_DISABLE__ */

        /* R11 CR */
#ifdef __DOCOMO_IOT_EMM_R11_DISABLE__
        0x00, 0x00, 0x00, 0x00,
#else // __DOCOMO_IOT_EMM_R11_DISABLE__
        0x01, 0x00, 0x00, 0x00,
#endif /* __DOCOMO_IOT_EMM_R11_DISABLE__ */

        /* R12 CR */
        0x00, 0x00, 0x00, 0x00 
    },
};

static nvram_ef_errc_performance_para_struct const NVRAM_EF_ERRC_PERFORMANCE_PARA_DEFAULT[] =
{
	{

		0x14,       //tband_ind
		0x1E,       //tbarred_cell
		0x1E,       //tbarred_freq
		0x14,       //tcsg_cell
		0x02,       //carrs_interval
		0x20,       //list1_used_carr_max
		0xFE48,     //skip_bw_rsrp_th
		0xFFC4,     //skip_bw_rsrq_th
		0x3C,       //tsib_ng_rej
		0x04,       //nsib_ng_max
		0x3C,       //tnsib_clear
		0x05,       //est_s_rxlev_th
		0x03,       //est_s_qual_th
		0x003C,     //trach

		{
			{
	    	//filter_coef_inrterval[0].interva_k0~19
			0x01, 0x02, 0x03, 0x04, 0x06,
        	0x07, 0x09, 0x0A, 0x0c, 0x0D,
        	0x0E, 0x0F, 0x11, 0x12, 0x13,
        	0x14, 0x14, 0x14, 0x14, 0x14
	        },

			{
			//filter_coef_inrterval[1].interva_k0~19
			0x01, 0x02, 0x03, 0x04, 0x05,
        	0x06, 0x07, 0x08, 0x09, 0x0A,
        	0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        	0x10, 0x11, 0x12, 0x13, 0x14
	        },

			{
			//filter_coef_inrterval[2].interva_k0~19
			0x01, 0x02, 0x02, 0x03, 0x04,
        	0x05, 0x06, 0x06, 0x07, 0x07,
        	0x08, 0x08, 0x08, 0x09, 0x09,
        	0x0A, 0x0A, 0x0B, 0x0B, 0x0C
		    },

			{
		 	//filter_coef_inrterval[3].interva_k0~19
			0x01, 0x02, 0x02, 0x03, 0x03,
        	0x04, 0x04, 0x05, 0x05, 0x06,
        	0x06, 0x06, 0x06, 0x07, 0x07,
        	0x07, 0x08, 0x08, 0x09, 0x09
			}
		},

		0x00,   //eutran_neighbour_cellreport_flg
		0x01,   //iir_filter_coef_rsrp
		0x01,   //iir_filter_coef_rsrp
		0x0001, //th0_interval
		0x00B5, //th1_interval
		0x00F1, //th2_interval
		0x0501, //th3_interval
		0x0A01, //th4_interval

		0x0A,   //max_kraerr
		0x02,   //traerr
        0x05,   //tvalid_raerr

		0x10,  //mib_crc_ng_max
		0x10,  //sib1_crc_ng_max
		0x10,  //si1_crc_ng_max
		0x10,  //si_crc_ng_max
		0x20,  //sib10_crc_ng_max
		0x20,  //sib11_crc_ng_max
		0x20,  //sib12_crc_ng_max
		0x28,  //mib_sib1_protect_tim_val
        0x0A,  //sib2_9_protect_tim_val
        0x05,  //crc_ng_tim_shift
        0x0A,  //standby_mib_sib1_protect_tim_val
        0x0A,  //standby_sib2_9_protect_tim_val
#ifndef __DISABLE_3G_AFR__
        0x10+
#endif        
        0x0F,  //csfb_enhancement_item_status [b1: not used] [b2: reduce lau, enable] [b3: defer si13, enable] [b4: 2g afr, enable] [b5: 3g afr, enable]
        0x04,  //csfb_enhancement_item_status_in_test_mode [b1: not used] [b2: reduce lau, disable] [b3: defer si13, enable] [b4: 2g afr, disable] [b5: 3g afr, disable]
        0x00,  //is_eia0_by_sp1;
        0x00,  //background_search_status_in_test_mode [b1: BG_SEARCH_2G4_FDD, off] [b2: BG_SEARCH_3G4_FDD, off] [b3: BG_SEARCH_2G4_TDD, off] [b4: BG_SEARCH_3G4_TDD, off]

        {   //designated_carrier_inf
            0x05,   //freq_num
            {       //freq_list[20]
                {   //freq_list[0]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9952  //39250
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x95CE  //38350
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x940C  //37900
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x94D4  //38100
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9826  //38950
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[16]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[17]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[18]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                },
                {   //freq_list[19]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000
                }
            },

            0x04,   //black_freq_num
            {       //black_freq_list[16]
                {   //freq_list[0]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x975E, //38750
                    0x05    //bandwidth
                },
                {   //freq_list[1]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9A1A, //39450
                    0x05    //bandwidth
                },
                {   //freq_list[2]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0x9D94, //40340
                    0x05    //bandwidth
                },
                {   //freq_list[3]
                    {   //plmn_id
                        0x04,
                        0x06,
                        0x00,
                        0x00,
                        0x00,
                        0x0F
                    },
                    0xA0B4, //41140
                    0x05    //bandwidth
                },
                {   //freq_list[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                },
                {   //freq_list[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x0000, //earfcn
                    0x00    //bandwidth
                }
            },

            0x00,   //priority_band_inf_num
            {       //priority_band_inf[16]
                {       //priority_band_inf[0]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[1]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[2]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[3]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[4]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[5]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[6]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[7]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[8]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[9]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[10]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[11]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[12]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[13]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[14]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                },
                {       //priority_band_inf[15]
                    {   //plmn_id
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00,
                        0x00
                    },
                    0x00,   //band_num
                    {       //band_list[64]
                        0x00,   //band_list[00]
                        0x00,   //band_list[01]
                        0x00,   //band_list[02]
                        0x00,   //band_list[03]
                        0x00,   //band_list[04]
                        0x00,   //band_list[05]
                        0x00,   //band_list[06]
                        0x00,   //band_list[07]
                        0x00,   //band_list[08]
                        0x00,   //band_list[09]
                        0x00,   //band_list[10]
                        0x00,   //band_list[11]
                        0x00,   //band_list[12]
                        0x00,   //band_list[13]
                        0x00,   //band_list[14]
                        0x00,   //band_list[15]
                        0x00,   //band_list[16]
                        0x00,   //band_list[17]
                        0x00,   //band_list[18]
                        0x00,   //band_list[19]
                        0x00,   //band_list[20]
                        0x00,   //band_list[21]
                        0x00,   //band_list[22]
                        0x00,   //band_list[23]
                        0x00,   //band_list[24]
                        0x00,   //band_list[25]
                        0x00,   //band_list[26]
                        0x00,   //band_list[27]
                        0x00,   //band_list[28]
                        0x00,   //band_list[29]
                        0x00,   //band_list[30]
                        0x00,   //band_list[31]
                        0x00,   //band_list[32]
                        0x00,   //band_list[33]
                        0x00,   //band_list[34]
                        0x00,   //band_list[35]
                        0x00,   //band_list[36]
                        0x00,   //band_list[37]
                        0x00,   //band_list[38]
                        0x00,   //band_list[39]
                        0x00,   //band_list[40]
                        0x00,   //band_list[41]
                        0x00,   //band_list[42]
                        0x00,   //band_list[43]
                        0x00,   //band_list[44]
                        0x00,   //band_list[45]
                        0x00,   //band_list[46]
                        0x00,   //band_list[47]
                        0x00,   //band_list[48]
                        0x00,   //band_list[49]
                        0x00,   //band_list[50]
                        0x00,   //band_list[51]
                        0x00,   //band_list[52]
                        0x00,   //band_list[53]
                        0x00,   //band_list[54]
                        0x00,   //band_list[55]
                        0x00,   //band_list[56]
                        0x00,   //band_list[57]
                        0x00,   //band_list[58]
                        0x00,   //band_list[59]
                        0x00,   //band_list[60]
                        0x00,   //band_list[61]
                        0x00,   //band_list[62]
                        0x00    //band_list[63]
                    }
                }
            }
        },
        0x02,  //afr_timer(seconds)
        0x04,  //csfb_enhancement_item_status_2 [b1: 2G_FDD_eCSFB, disable] [b2: 3G_FDD_eCSFB, disable] [b3: 2G_TDD_eCSFB, enable] [b4: 3G_TDD_eCSFB, disable]
        0x00,  //csfb_enhancement_item_status_2_in_test_mode [b1: 2G_FDD_eCSFB, disable] [b2: 3G_FDD_eCSFB, disable] [b3: 2G_TDD_eCSFB, disable] [b4: 3G_TDD_eCSFB, disable]
	},
};

static nvram_ef_errc_afr_setting_struct const NVRAM_EF_ERRC_AFR_SETTING_DEFAULT[] =
{
    {
        {
            {
                //hplmn_afr_mapping[0]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[1]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[2]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[3]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[4]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[5]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[6]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            },
            
            {
                //hplmn_afr_mapping[7]
                {0x0f, 0x0f, 0x0f, 0x0f, 0x0f, 0x0f}, //plmnid
                KAL_FALSE, //csfb_2g_afr
                KAL_FALSE  //csfg_3g_afr
            }
        }
    }
};

static kal_uint8 const NVRAM_EF_LTE_CAP_DEFAULT[] =
{
    0xf0, //eea_support
#ifdef __VOLTE_SUPPORT__    
    0xf0, //eia_support
#else
    0x70, //eia_support
#endif

#ifdef __VOLTE_SUPPORT__
    0x09,  //bit 1: srvcc_to_geran_utran_support  //bit2: nf_support //bit3+4: LTE power class =>2 denotes class 3
#else
    0x08,  //bit 1: srvcc_to_geran_utran_support  //bit2: nf_support //bit3+4: LTE power class =>2 denotes class 3
#endif    
};

static nvram_ef_ue_eutra_cap_struct const NVRAM_EF_UE_EUTRA_CAP_CSFB_DEFAULT[] =
{
    //MTK related
	0x00,       //ue_eutra_cap_ver

    //spec related
	0x01,       //access_stratum_release, Rel-9
	0x04,       //ue_category
	
	{//pdcp_param
		{
    	//rohc_profiles[0~8]
		0x01, 0x01, 0x00, 0x01, 0x00,
    	0x01, 0x01, 0x00, 0x01
        },

		0x04    //max_num_rohc_sessions, cs16
	},

    {//phylayer_param
		0x00,   //ue_tx_ante_sel_fdd
		0x00,   //ue_tx_ante_sel_tdd
		0x01    //ue_specific_ref_sigs
	},    

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFE80, //feature_group_ind_fdd

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
	0x5D0FFE80, //feature_group_ind_tdd

    {//phylayer_param_v920
		0x01,   //enhancedDualLayerFDD_r9
		0x01    //enhancedDualLayerTDD_r9
	}, 

    {//interrat_param_geram_v920
		0x00,   //dtm_r9
		0x01    //e_RedirectionGERAN_r9
	},

    {//interrat_param_utra_v920
		0x01,   //e_RedirectionUTRA_r9_fdd
		0x01    //e_RedirectionUTRA_r9_tdd
	},
	
	0x00,   //deviceType_r9

    {//csg_prox_ind_param_r9
		0x01,   //intraFreqProximityIndication_r9
		0x01,   //interFreqProximityIndication_r9
		0x00    //utran_ProximityIndication_r9
	},

    {//nei_cell_si_acq_r9
		0x01,   //intraFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //intraFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //utran_SI_AcquisitionForHO_r9_fdd
		0x01    //utran_SI_AcquisitionForHO_r9_tdd
	},

    {//son_param_r9
		0x01    //rach_Report_r9
	},
        
	0xCE800000,   //feature_group_ind_add_r9_fdd
	0xCE800000,   //feature_group_ind_add_r9_tdd

    {//fdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},

    {//tdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},
        
    {//interrat_param_utra_v9c0
		0x00,   //voiceOverPS_HS_UTRA_FDD_r9
		0x00,   //voiceOverPS_HS_UTRA_TDD128_r9
		0x00,   //srvcc_FromUTRA_FDD_ToUTRA_FDD_r9
		0x00,   //srvcc_FromUTRA_FDD_ToGERAN_r9
		0x00,   //srvcc_FromUTRA_TDD128_ToUTRA_TDD128_r9
		0x00    //srvcc_FromUTRA_TDD128_ToGERAN_r9
	},

    {//phylayer_param_v9d0
		0x01,   //tm5_FDD_r9
		0x01    //tm5_TDD_r9
	},   

    {//irat_param_utra_tdd_v1020
		0x01,   //e_RedirectionUTRA_TDD_r10_fdd
		0x01    //e_RedirectionUTRA_TDD_r10_tdd
	},

    {//phylayer_param_v1130
		0x01    //tdd_SpecialSubframe_r11
	}
};

static nvram_ef_ue_eutra_cap_struct const NVRAM_EF_UE_EUTRA_CAP_MMDC_DEFAULT[] =
{
	//MTK related
	0x00,       //ue_eutra_cap_ver

    //spec related
	0x01,       //access_stratum_release, Rel-9
	0x04,       //ue_category
	
	{//pdcp_param
		{
    	//rohc_profiles[0~8]
		0x01, 0x01, 0x00, 0x01, 0x00,
    	0x01, 0x01, 0x00, 0x01
        },

		0x04    //max_num_rohc_sessions, cs16
	},

    {//phylayer_param
		0x00,   //ue_tx_ante_sel_fdd
		0x00,   //ue_tx_ante_sel_tdd
		0x01    //ue_specific_ref_sigs
	},    

#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFE80, //feature_group_ind_fdd
        
#ifndef __DISABLE_SRVCC_FGI_ORANGE__
    0xA240001E |
#ifdef __VOLTE_SUPPORT__
    0x00800020 |
#endif
#endif
    0x5D0FFE80, //feature_group_ind_tdd


    {//phylayer_param_v920
		0x01,   //enhancedDualLayerFDD_r9
		0x01    //enhancedDualLayerTDD_r9
	}, 

    {//interrat_param_geram_v920
		0x00,   //dtm_r9
		0x01    //e_RedirectionGERAN_r9
	},

    {//interrat_param_utra_v920
		0x01,   //e_RedirectionUTRA_r9_fdd
		0x01    //e_RedirectionUTRA_r9_tdd
	},
	
	0x00,   //deviceType_r9

    {//csg_prox_ind_param_r9
		0x01,   //intraFreqProximityIndication_r9
		0x01,   //interFreqProximityIndication_r9
		0x00    //utran_ProximityIndication_r9
	},

    {//nei_cell_si_acq_r9
		0x01,   //intraFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //intraFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_fdd
		0x01,   //interFreqSI_AcquisitionForHO_r9_tdd
		0x01,   //utran_SI_AcquisitionForHO_r9_fdd
		0x01    //utran_SI_AcquisitionForHO_r9_tdd
	},

    {//son_param_r9
		0x01    //rach_Report_r9
	},
        
	0xCE800000,   //feature_group_ind_add_r9_fdd
	0xCE800000,   //feature_group_ind_add_r9_tdd

    {//fdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},

    {//tdd_add_ue_eutra_cap_r9
		{//phylayer_param_r9
    		0x00,   //ue_tx_ante_sel
    		0x00    //ue_specific_ref_sigs
    	},

        0x00000000, //feature_group_ind_r9
    	0x00000000, //feature_group_ind_add_r9

        {//interrat_param_utra_r9
    		0x00    //e_RedirectionUTRA_r9
    	},

        {//nei_cell_si_acq_r9
    		0x00,   //intraFreqSI_AcquisitionForHO_r9
    		0x00,   //interFreqSI_AcquisitionForHO_r9
    		0x00    //utran_SI_AcquisitionForHO_r9
    	}
	},
        
    {//interrat_param_utra_v9c0
		0x00,   //voiceOverPS_HS_UTRA_FDD_r9
		0x00,   //voiceOverPS_HS_UTRA_TDD128_r9
		0x00,   //srvcc_FromUTRA_FDD_ToUTRA_FDD_r9
		0x00,   //srvcc_FromUTRA_FDD_ToGERAN_r9
		0x00,   //srvcc_FromUTRA_TDD128_ToUTRA_TDD128_r9
		0x00    //srvcc_FromUTRA_TDD128_ToGERAN_r9
	},

    {//phylayer_param_v9d0
		0x01,   //tm5_FDD_r9
		0x01    //tm5_TDD_r9
	},   

    {//irat_param_utra_tdd_v1020
		0x01,   //e_RedirectionUTRA_TDD_r10_fdd
		0x01    //e_RedirectionUTRA_TDD_r10_tdd
	},

    {//phylayer_param_v1130
		0x01    //tdd_SpecialSubframe_r11
	}     
};


#endif /* __LTE_RAT__ */


#if defined (__HMU_ENABLE__)
static hmu_conf_struct const NVRAM_EF_HMU_CONFIG_DEFAULT[] =
{
    {
        3,                      //kal_uint32    dev_num;
        8,                     //kal_uint32    ext_hifinfo_len;
		{0x20, 0x4E, 0x00, 0x00, // kal_uint32                          enum_timeout;
		0x88, 0x13, 0x00, 0x00}, // kal_uint32                          tx_timeout;
        {
            {
                HMU_USB_DEV_RNDIS,  //hmuEmuDeviceTyep_enum     dev_type;
                0,                  //kal_uint32                dev_mapping;
                {NULL},             //void                      *reserve ;
                11,                 //kal_uint32                ext_devinfo_len;
                "Test RNDIS"        //kal_char                  ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
            },
            {
                HMU_USB_DEV_ACM,    //hmuEmuDeviceTyep_enum     dev_type;
                uart_port_usb,      //kal_uint32                dev_mapping;
                {NULL},             //void                      *reserve ;
                10,                 //kal_uint32                ext_devinfo_len;
                "Test ACM1"         //kal_char                  ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
            },
            {
                HMU_USB_DEV_ACM,    //hmuEmuDeviceTyep_enum     dev_type;
                uart_port_usb2,     //kal_uint32                dev_mapping;
                {NULL},             //void                      *reserve ;
                10,                 //kal_uint32                ext_devinfo_len;
                "Test ACM2"         //kal_char                  ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
            }
        }
    },
};

#ifdef __USB_MBIM_SUPPORT__
static hmu_conf_struct const NVRAM_EF_HMU_CONFIG_MBIM[] =
{
    {
        1,                      //kal_uint32    dev_num;
        8,                     //kal_uint32    ext_hifinfo_len;
		{0x20, 0x4E, 0x00, 0x00, // kal_uint32                          enum_timeout;
		0x88, 0x13, 0x00, 0x00}, // kal_uint32                          tx_timeout;
        {
            {
                HMU_USB_DEV_MBIM,   //hmuEmuDeviceTyep_enum     dev_type;
                0,                  //kal_uint32                dev_mapping;
                {NULL},             //void                      *reserve ;
                10,                 //kal_uint32                ext_devinfo_len;
                "Test MBIM"         //kal_char                  ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
            },
        }
    },
};
#endif /* __USB_MBIM_SUPPORT__ */


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

static hmu_hd_conf_struct const NVRAM_EF_HMU_HD_CONFIG_DEFAULT[] =
{
    {
        //kal_uint32            dev_num;
        1,
        //kal_uint32            ext_hifinfo_len;
        14,
        //kal_char          ext_hifinfo[HMU_MAX_HIF_EXTINFO_SIZE];
        "i am hd device",
        //hmu_emudev_info   dev_info[HMU_MAX_EMUDEVNUM];
        {
            {
                HMU_USB_DEV_ACM,//hmuEmuDeviceTyep_enum  dev_type;
                8,//kal_uint32          dev_mapping;
                {NULL},//void               *reserve ;
                9,//kal_uint32          ext_devinfo_len;
                "I am ACM"//kal_char            ext_devinfo[HMU_MAX_EMUDEV_EXTINFO_SIZE];
            },
        },
    },
};
#endif

#ifdef __NMU_ENABLE__
static nmu_nvram_table_t const NVRAM_EF_NMU_CONFIG_DEFAULT[] =
{
    {0, {0x00, 0x00, 0x00, 0x00, 0x72, 0x08}}
    ,
};
#endif

static kal_uint8 const NVRAM_EF_DHL_FILTER_DEFAULT[] = 
{
	7,   0,   0,   0,   0,   0,   0,   0,
    0,   0,   0,   0,   0,   0,   0,   0,
  255, 255, 255, 255, 255, 255, 255, 255,
  255, 255, 255, 255, 255, 255, 255, 255,
};

/* default value for SBP feature
   refer to sbp_md_feature_enum for modem configurable features
*/
static nvram_ef_sbp_modem_config_struct NVRAM_EF_SBP_MODEM_CONFIG_DEFAULT[] = {
{
    0x00000000, //0: disable SBP, 1: enable SBP
    /* below are bitmap for modem feature */
    {
    /* 1st byte */
#if defined(__PERMANENT_AUTO_SEL_MODE__)
    0x01 |
#endif
#if defined(__3G_CB_OFF__)
    0x02 |
#endif
//#if defined(__MM_TRY_ABNORMAL_LAI_ONCE_MORE__)
    0x04 |
//#endif
#if defined(__MM_DISABLE_RETRY_ABNORMAL_LAI__)
    0x08 |
#endif
#if defined(__DISABLE_AUTO_RETURN_PRE_RPLMN__)
    0x10 |
#endif
#if defined(__MM_HPPLMN_1ST_ATTEMPT_ENHANCE__)
    0x20 |
#endif
#if defined(__OOS_EARLY_IND__)
    0x40 |
#endif
/* Default open __L2_RANDOM_FILL_BIT__ */
// #if defined(__L2_RANDOM_FILL_BIT__)
    0x80 |
// #endif
    0x00 ,

    /* 2nd byte */
#if defined(__3G_CB_SERVICE_BY_PLMN__)
    0x01 |
#endif
#if defined(__MM_IGNORE_YOIGO_EQPLMN__)
    0x04 |
#endif
#if defined(__MM_IGNORE_PLAY_EQPLMN__)
    0x08 |
#endif
#if defined(__MM_IGNORE_EQPLMN_IN_AUTO_MODE__)
    0x10 |
#endif
#if defined(__MM_DISABLE_PREVIOUS_RPLMN_FROM_NVRAM__)
    0x20 |
#endif
#if defined(__MM_INTERNATIONAL_HPPLMN_SEARCH__)
    0x40 |
#endif
#if defined(__ATNT_HPPLMN_SEARCH__)
    0x80 |
#endif
    0x00 ,

    /* 3rd byte */
#if defined(__HPPLMN_REGARDLESS_ANY_MCC__)
    0x01 |
#endif
#if defined(__DISABLE_RPLMN_FROM_GLOCI__)
    0x02 |
#endif
#if defined(__DISABLE_PLMNSEL_OPLMN_COEXIST__)
    0x04 |
#endif
#if defined(__DISABLE_DISPLAY_ROAMING_HPLMN_IN_EPLMN__)
    0x08 |
#endif
#if defined(__RPLMN_HPLMN_COMBINED_SEARCH__)
    0x10 |
#endif
#if defined(__MM_SEARCH_HPLMN_BEFORE_RPLMN__)
    0x20 |
#endif
#if defined(__DISABLE_PLMN_SEL_WHEN_ACCESS_BARRED__)
    0x40 |
#endif
#if defined(__TMO_PLMN_MATCHING__)
    0x80 |
#endif
    0x00,

    /* 4th byte */
#if defined(__MM_NOT_TRY_ANOTHER_RAT_FOR_LU_ABNORMAL__)
    0x01 |
#endif  
#if defined(__ENS__)
    0x02 |
#endif  
#if defined(__MM_PERFORM_PLMN_SEARCH_AFTER_LU_ABNORMAL__)
    0x04 |
#endif  
//#if defined(__RESUME_GPRS_AFTER_LU_ABNORMAL__)
    0x08 |
//#endif
#if defined(__TMO_ECC_NOTIFICATION_ENABLE__)
    0x10 |
#endif
#if defined(__ENS_RAT_BALANCING__)
    0x20 |
#endif
#if defined(__ORANGE_H_PLUS__)
    0x40 |
#endif
#if defined(__U_CSP_SUPPORT__)
    0x80 |
#endif
    0x00,

    /* 5th byte */
#if defined(__SAT_NO_EVDL_IN_SESSION__)
    0x01 |
#endif
#if defined(__IMEI_LOCK_SUPPORT__)
    0x02 |
#endif
#if defined(__DOCOMO_IOT_SMS__)
    0x04 |
#endif
#if defined(__USE_SM_QOS_SUBSCRIBED__)
    0x08 |
#endif
#if defined(__NO_SUPPORT_A5_3__)
    0x10 |
#endif
#if defined(__DOCOMO_IOT_CC__)
    0x20 |
#endif
#if defined(__AT_ME_IDENTIFICATION_WITHOUT_HEADER__)
    0x40 |
#endif
#if defined(__STAR_SHORT_STRING_AS_CALL__)
    0x80 |
#endif
    0x00,

    /* 6th byte */
#if defined(__CUSTOMIZED_IDLE_STRING_AS_CALL__)
    0x01 |
#endif
#if defined(__DISABLE_SKIP_NEW_FPLMN_MANUAL_RESEL__)
    0x02 |
#endif
#if defined(__ADAPTIVE_PAGING_PERIOD_IN_UNACK_MODE__)
    0x04 |
#endif
//#if defined(__OP01_ROAMING_RAT_ORDER__)
 //   0x08 |
//#endif
#if defined(__GEMINI__) && !defined(__SGLTE_DSDS__)
    0x10 |
    0x20 |
    0x40 |
    0x80 |
#else
    0x40 |
    0x80 |
#endif
    0x00,

    /* 7th byte */
//#if defined(__PREFER_SEARCH_3G__)
    0x01 |
//#endif

//#if defined(__PREFER_SEARCH_4G__)
    0x02 |  
//#endif

#if defined(__TMO_GBA__)
    0x04 |
#endif

#if defined(__UMTS_TDD128_MODE__)
    0x08 |
#endif

//#if defined(__DISABLE_EUTRAN_AFTER_ABNORMAL__)
    0x10 |
//#endif

#if defined(__DISABLE_RPLMN_FROM_EPSLOCI__)
    0x20 |
#endif    

//#if defined(__DISABLE_EUTRAN_AFTER_NO_SUITABLE__)
    0x40 |
//#endif   

#if defined(__MM_NOT_STAY_ON_FBLA_FOR_REG_PROV__)
    0x80 |
#endif

    0x00,

    /* 8th byte */
#if defined(__TMO_NO_OPTIONAL_RAU_AFTER_CCO_FAILURE__)
    0x01 |
#endif
#ifdef __SGLTE__ //SAT PROVIDE_LOCAL_INFO from ps Protocol
    0x02 |
#endif // end of SAT
#if defined(__EMR_REPORTING_WITH_SI2Q_BSIC_PARA__)
    0x04 |
#endif
    0x10 |
#if defined(__TMO_SIM_LOCK__)
    0x20 |
#endif
//#if defined(__MODE_1_PS_ONLY_LTE_NETWORK_SUPPORT__)    
    0x40 | // SBP_MODE_1_PS_ONLY_LTE_NETWORK_SUPPORT default off
//#endif
#if defined(__IGNORE_PLMN_CHANGE_FOR_MANUAL_MODE__)
    0x80 |
#endif
     0x00,

    /* 9th byte */
#if defined(__CLEAR_CODE_33__)
    0x01 |
#endif   
#if defined(__RELEASE_DEACTIVATING_BEARER_DURING_IRAT__)
    0X02 |
#endif
#if defined(__EMM_RETRY_EMC_WHEN_ABNORMAL__)
    0x04 |
#endif
#if defined(__EMM_RETRY_EMC_IN_SHARED_NW__)
    0x08 |
#endif
#if defined(__EMM_RETRY_EMC_IN_SAME_PLMN__)
    0x10 |
#endif
#if defined(__EMM_RETRY_EMC_IN_DIFF_PLMN__)
    0x20 |
#endif
#if defined(__SAT_REISSUE_REFRESH_AFTER_CALL_END__)
    0x40 |
#endif
#if defined(__ALLOW_SIM_REFRESH_RESET_WHEN_IN_CALL__)
    0x80 |
#endif
    0x00,

    /* 10th byte */
#if defined(__TMO_IRAT_SET_ACTIVE_FLAG__)
    0x01 |
#endif    
#if defined(__RELEASE_PS_CONN_FOR_EUTRAN_UPDATE__)
    0x02 |
#endif
    0x00 | //Default turn off disable EUTRAN measurement and reporting capability
#if (defined(__OP01__) && !defined(__SGLTE__)) || defined(__PLMN_SEARCH_ABORT_SUPPORT__)
    0x08 |
#endif
#if defined(__DISABLE_EUTRAN_AFTER_ROAMING_NOT_ALLOWED__)
    0x10 |
#endif
#if defined(__TELSTRA_BAND_PRIORITY_SEARCH__)
    0x20 |
#endif
    0x00
        }
}
};

/* default value for SBP feature data
   refer to sbp_md_feature_data_enum for modem configurable features
*/
static nvram_ef_sbp_modem_data_config_struct NVRAM_EF_SBP_MODEM_DATA_CONFIG_DEFAULT[] = {
{
    0x00000000, {
    /*1st Byte VAMOS*/
#if defined(__VAMOS_2__)
    0x02,
#elif defined(__VAMOS_1__)
    0x01,
#else
    0x00,
#endif
   /*2nd Byte  IDC_EN*/
    0x01, 
   /*3th Byte  IDC_BAND7_IM3_TX_PWR*/
    0x12,
   /*4th Byte  IDC_BAND13_GPS_TX_PWR*/
    0x14,
   /*5th Byte  IDC_802_ANT_ISOLATION*/ 
    0x0c,
   /*6th Byte  IDC_GPS_ANT_ISOLATION*/
    0x0e,
   /*7th Byte  GERAN_TO_EUTRAN_SUPPORT_IN_GERAN_PTM*/
    0x02,
   /*8th Byte  PLMN_SEARCH_ABORT_3G_TIMER_PERIOD*/
#if (defined(__OP01__)) && (!defined(__SGLTE__))
    0x14,
#else
    0x0b,
#endif
   /*9th Byte  PLMN_SEARCH_ABORT_4G_TIMER_PERIOD*/
#if (defined(__OP01__)) && (!defined(__SGLTE__))
    0x12
#else
    0x0e
#endif
    }
}
};

/**
 * Step 4:
 * The logical data item table.
 * Note:
 * Each logical data item must be:
 * 1> Size must be EVEN
 * 2> Size of default value must be equal to the logical data item's size.
 *
 * The last LID in the MT reign now is MT1k
 */
ltable_entry_struct logical_data_item_table_core[] =
{
    {
        NVRAM_EF_SYS_STATISTICS_LID,
        NVRAM_EF_SYS_STATISTICS_TOTAL,
        NVRAM_EF_SYS_STATISTICS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT04",
        VER(NVRAM_EF_SYS_STATISTICS_LID)
    },
    
    {
        NVRAM_EF_AS_BAND_SETTING_LID,
        NVRAM_EF_AS_BAND_SETTING_TOTAL,
        NVRAM_EF_AS_BAND_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_AS_BAND_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#if defined(__UMTS_FDD_MODE__)        
        "MT10",
#else        
        "MT13",
#endif
        VER(NVRAM_EF_AS_BAND_SETTING_LID)
    },

#if defined(__2G_RF_CUSTOM_TOOL_SUPPORT__)
    {
        NVRAM_EF_L1_2G_RF_PARAMETER_LID,
        NVRAM_EF_L1_2G_RF_PARAMETER_TOTAL,
        NVRAM_EF_L1_2G_RF_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP((void*)&RF_custom_input_data),//NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),//NVRAM_NORMAL_NOT_ZIP(RF_custom_input_data),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
   #if defined(__DUAL_TALK_SUPPORT__)
        "MT8W",
   #else
      #if defined(__UMTS_FDD_MODE__)
        "MT9W",
      #elif defined(__UMTS_TDD128_MODE__)
        "MT0W",
      #else
        "MT0W", 
      #endif
   #endif
        VER(NVRAM_EF_L1_2G_RF_PARAMETER_LID)
    },
#endif


    {
        NVRAM_EF_BAND_INFO_LID,
        NVRAM_EF_BAND_INFO_TOTAL,
        NVRAM_EF_BAND_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BAND_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT0X",
        VER(NVRAM_EF_BAND_INFO_LID)
    },
    
    {
        NVRAM_EF_TST_FILTER_LID,
        NVRAM_EF_TST_FILTER_TOTAL,
        NVRAM_EF_TST_FILTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT0Y",
        VER(NVRAM_EF_TST_FILTER_LID)
    },
    {
        NVRAM_EF_DHL_FILTER_LID,
        NVRAM_EF_DHL_FILTER_TOTAL,
        NVRAM_EF_DHL_FILTER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_DHL_FILTER_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1K",
        VER(NVRAM_EF_DHL_FILTER_LID)
    },

    {
        NVRAM_EF_PORT_SETTING_LID,
        NVRAM_EF_PORT_SETTING_TOTAL,
        NVRAM_EF_PORT_SETTING_SIZE,
    #if defined(__CUSTOMIZED_PORT_SETTING__) && !defined(NVRAM_AUTO_GEN)
        NVRAM_NORMAL(NVRAM_EF_CUSTOM_PORT_SETTING_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_PORT_SETTING_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT0Z",
        VER(NVRAM_EF_PORT_SETTING_LID)
    },

#if !defined(__SMS_STORAGE_BY_MMI__) && (SMS_PHONE_ENTRY > 0)
    {
        NVRAM_EF_SMSAL_SMS_LID,
        NVRAM_EF_SMSAL_SMS_TOTAL,
        NVRAM_EF_SMSAL_SMS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SMSAL_SMS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT40",
        VER(NVRAM_EF_SMSAL_SMS_LID)
    },
#endif

#if !defined(EXTERNAL_MMI)
    {
        NVRAM_EF_SMSAL_MAILBOX_ADDR_LID,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_TOTAL,
        NVRAM_EF_SMSAL_MAILBOX_ADDR_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT41",
        VER(NVRAM_EF_SMSAL_MAILBOX_ADDR_LID)
    },
#endif

    {
        NVRAM_EF_SMSAL_COMMON_PARAM_LID,
        NVRAM_EF_SMSAL_COMMON_PARAM_TOTAL,
        NVRAM_EF_SMSAL_COMMON_PARAM_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT42",
        VER(NVRAM_EF_SMSAL_COMMON_PARAM_LID)
    },

    {
        NVRAM_EF_SMSAL_SMSP_LID,
        NVRAM_EF_SMSAL_SMSP_TOTAL,
        NVRAM_EF_SMSAL_SMSP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTIREC_READ,
        "MT43",
        VER(NVRAM_EF_SMSAL_SMSP_LID)
    },

    {
        NVRAM_EF_SMSAL_MWIS_LID,
        NVRAM_EF_SMSAL_MWIS_TOTAL,
        NVRAM_EF_SMSAL_MWIS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT44",
        VER(NVRAM_EF_SMSAL_MWIS_LID)
    },

    {
        NVRAM_EF_CB_DEFAULT_CH_LID,
        NVRAM_EF_CB_DEFAULT_CH_TOTAL,
        NVRAM_EF_CB_DEFAULT_CH_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_FACTORY_RESET,
        "MT45",
        VER(NVRAM_EF_CB_DEFAULT_CH_LID)
    },

    {
        NVRAM_EF_CB_CH_INFO_LID,
        NVRAM_EF_CB_CH_INFO_TOTAL,
        NVRAM_EF_CB_CH_INFO_SIZE,
        NVRAM_NORMAL(COMMON_NVRAM_EF_CB_CH_INFO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MT46",
        VER(NVRAM_EF_CB_CH_INFO_LID)
    },

    #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)
    {
        NVRAM_EF_TCM_CID_0_PROFILE_LID,
        NVRAM_EF_TCM_CID_0_PROFILE_TOTAL,
        NVRAM_EF_TCM_CID_0_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_TCM_CID_0_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT47",
        VER(NVRAM_EF_TCM_CID_0_PROFILE_LID)
    },

    {
        NVRAM_EF_TCM_PDP_PROFILE_LID,
        NVRAM_EF_TCM_PDP_PROFILE_TOTAL,
        NVRAM_EF_TCM_PDP_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_TCM_PDP_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT48",
        VER(NVRAM_EF_TCM_PDP_PROFILE_LID)
    },
    #endif // ~ #if defined (__PS_SERVICE__) && defined (__MOD_TCM__) && defined (__EXT_PDP_CONTEXT_ON__)

    {
        NVRAM_EF_CFU_FLAG_LID,
        NVRAM_EF_CFU_FLAG_TOTAL,
        NVRAM_EF_CFU_FLAG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CFU_FLAG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT49",
        VER(NVRAM_EF_CFU_FLAG_LID)
    },

    {
        NVRAM_EF_MM_LOCIGPRS_LID,
        NVRAM_EF_MM_LOCIGPRS_TOTAL,
        NVRAM_EF_MM_LOCIGPRS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MM_LOCIGPRS_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__          
        "MT4A",
#else
        "MT4E",
#endif
        VER(NVRAM_EF_MM_LOCIGPRS_LID)
    },
    
#if defined (__CPHS__) || defined (__CCM_NO_RESET__)
    {
        NVRAM_EF_ALS_LINE_ID_LID,
        NVRAM_EF_ALS_LINE_ID_TOTAL,
        NVRAM_EF_ALS_LINE_ID_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE,
        "MT4C",
        VER(NVRAM_EF_ALS_LINE_ID_LID)
    },
#endif/* (__CPHS__) || (__CCM_NO_RESET__)*/

    {
        NVRAM_EF_MSCAP_LID,
        NVRAM_EF_MSCAP_TOTAL,
        NVRAM_EF_MSCAP_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MSCAP_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
#ifdef __UMTS_FDD_MODE__  
        "MT4D",
#else
		"MT4F",
#endif
        VER(NVRAM_EF_MSCAP_LID)
    },
    
    {
        NVRAM_EF_CLASSMARK_RACAP_LID,
        NVRAM_EF_CLASSMARK_RACAP_TOTAL,
        NVRAM_EF_CLASSMARK_RACAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_CLASSMARK_RACAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_WRITEPROTECT | NVRAM_ATTR_MULTIPLE,
#ifdef __UMTS_TDD128_MODE__
        "MT16",
#else
        "MT17",
#endif
        VER(NVRAM_EF_CLASSMARK_RACAP_LID)
    },
    
    {
        NVRAM_EF_SIM_ASSERT_LID,
        NVRAM_EF_SIM_ASSERT_TOTAL,
        NVRAM_EF_SIM_ASSERT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_RING,
        "MT18",
        VER(NVRAM_EF_SIM_ASSERT_LID)
    },
        
    {
        NVRAM_EF_RTC_DATA_LID,
        NVRAM_EF_RTC_DATA_TOTAL,
        NVRAM_EF_RTC_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT19",
        VER(NVRAM_EF_RTC_DATA_LID)
    },
    
#if defined(__UMTS_RAT__) || defined(__STORED_CELL_SELECTION_INFO__)
    {
        NVRAM_EF_NET_PAR_LID,
        NVRAM_EF_NET_PAR_TOTAL,
        NVRAM_EF_NET_PAR_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#if (!defined(__UMTS_RAT__) && defined(__STORED_CELL_SELECTION_INFO__)) || defined(__UMTS_FDD_MODE__)
        "MT1A",
#endif
#ifdef __UMTS_TDD128_MODE__
        "MT3A",
#endif
        VER(NVRAM_EF_NET_PAR_LID)
    },
#endif

//#ifdef __BAND_PRIORITY_SEARCH__
#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__)
    {
        NVRAM_EF_UMTS_BAND_PRIORITY_LID,
        NVRAM_EF_UMTS_BAND_PRIORITY_TOTAL,
        NVRAM_EF_UMTS_BAND_PRIORITY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_BAND_PRIORITY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT12",
        VER(NVRAM_EF_UMTS_BAND_PRIORITY_LID)
    },
#endif /* __UMTS_RAT__ && __UMTS_FDD_MODE_ */
//#endif /* __BAND_PRIORITY_SEARCH__ */

#if defined(__UMTS_RAT__) && defined(__UMTS_FDD_MODE__) && defined(__UMTS_R7__)
    {

        NVRAM_EF_UMTS_DMCR_SETTING_LID,
        NVRAM_EF_UMTS_DMCR_SETTING_TOTAL,
        NVRAM_EF_UMTS_DMCR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_DMCR_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT13",
        VER(NVRAM_EF_UMTS_DMCR_SETTING_LID)
    },

    {

        NVRAM_EF_UMTS_SIB_SKIP_SETTING_LID,
        NVRAM_EF_UMTS_SIB_SKIP_SETTING_TOTAL,
        NVRAM_EF_UMTS_SIB_SKIP_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_SIB_SKIP_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT14",
        VER(NVRAM_EF_UMTS_SIB_SKIP_SETTING_LID)
    },
#endif /* __UMTS_RAT__ && __UMTS_FDD_MODE__ && __UMTS_R7__ */

#ifdef __UMTS_RAT__
/* currently useless
    {
        NVRAM_EF_UMTS_PLMN_LID,
        NVRAM_EF_UMTS_PLMN_TOTAL,
        NVRAM_EF_UMTS_PLMN_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM01",
        VER(NVRAM_EF_UMTS_PLMN_LID)
    },
*/
    {
        NVRAM_EF_UMTS_IMSI_LID,
        NVRAM_EF_UMTS_IMSI_TOTAL,
        NVRAM_EF_UMTS_IMSI_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_CONFIDENTIAL,
        "UM02",
        VER(NVRAM_EF_UMTS_IMSI_LID)
    },
    
    {
        NVRAM_EF_UMTS_START_HFN_LID,
        NVRAM_EF_UMTS_START_HFN_TOTAL,
        NVRAM_EF_UMTS_START_HFN_SIZE,
#ifdef __UMTS_FDD_MODE__
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
#endif
#ifdef __UMTS_TDD128_MODE__
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM03",
        VER(NVRAM_EF_UMTS_START_HFN_LID)
    },
    
    {
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID,
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_TOTAL,
        NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__
        "UM04",
#endif
#ifdef __UMTS_TDD128_MODE__
         "UM05",
#endif
        VER(NVRAM_EF_UMTS_USIME_RRC_DYNAMIC_CAP_LID)
    },
    
    {
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_LID,
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_TOTAL,
        NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__
        "UM06",
#endif
#ifdef __UMTS_TDD128_MODE__
         "UM07",
#endif
        VER(NVRAM_EF_UMTS_FREQUENCY_REPOSITORY_LID)
    },
#if (defined(__UMTS_TDD128_MODE__) && defined(__UMTS_R7__)) || (defined(__SEARCH_ALL_EHPLMN_TOGETHER__))
   {
        NVRAM_EF_UMTS_URR_CONFIGURATION_LID,
        NVRAM_EF_UMTS_URR_CONFIGURATION_TOTAL,
        NVRAM_EF_UMTS_URR_CONFIGURATION_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "UM08",
        VER(NVRAM_EF_UMTS_URR_CONFIGURATION_LID)
    },
#endif

#endif /* __UMTS_RAT__ */

#if (defined(__3G_CSG_SUPPORT__) || defined(__LTE_RAT__))
    {
        NVRAM_EF_PREV_VISITED_CELL_INFO_LID,
        NVRAM_EF_PREV_VISITED_CELL_INFO_TOTAL,
        NVRAM_EF_PREV_VISITED_CELL_INFO_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT11",
        VER(NVRAM_EF_PREV_VISITED_CELL_INFO_LID)
    },
#endif

#if defined(__MA_L1__) || defined(__UMTS_RAT__)
    {
        NVRAM_EF_L1_3G_CAL_DATA_LID,
        NVRAM_EF_L1_3G_CAL_DATA_TOTAL,
        NVRAM_EF_L1_3G_CAL_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1B",
        VER(NVRAM_EF_L1_3G_CAL_DATA_LID)
    },
#endif

#if 0
#if !defined(__LOW_COST_SUPPORT_COMMON__) && defined(__FLC_SUPPORT__ )&& defined(__MTK_INTERNAL__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif /* !__LOW_COST_SUPPORT_COMMON__&&__MTK_INTERNAL__ && __FLC_SUPPORT__ */
#endif

#if defined (__E_COMPASS_SENSOR_SUPPORT__)
    {
        NVRAM_EF_ECOMPASS_DATA_LID,
        NVRAM_EF_ECOMPASS_DATA_TOTAL,
        NVRAM_EF_ECOMPASS_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1D",
        VER(NVRAM_EF_ECOMPASS_DATA_LID)
    },
#endif  /* __E_COMPASS_SENSOR_SUPPORT__ */

#ifdef __BAND_BLOCK__
    {
        NVRAM_EF_BAND_BLOCK_LID,
        NVRAM_EF_BAND_BLOCK_TOTAL,
        NVRAM_EF_BAND_BLOCK_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "MT1E",
        VER(NVRAM_EF_BAND_BLOCK_LID),
    },
#endif /* __BAND_BLOCK__ */


#ifdef  __BTMODULE_RFMD3500__
    {
        NVRAM_EF_BTRADIO_RFMD3500_LID,
        NVRAM_EF_BTRADIO_RFMD3500_TOTAL,
        NVRAM_EF_BTRADIO_RFMD3500_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BTRADIO_RFMD3500_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT1G",
        VER(NVRAM_EF_BTRADIO_RFMD3500_LID)
    },
#endif





#if defined(__ATCMD_ONOFF_CHECK__)
    {
        NVRAM_EF_ATCMD_ON_OFF_CHECK_LID,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_TOTAL,
        NVRAM_EF_ATCMD_ON_OFF_CHECK_SIZE,
        NVRAM_NORMAL(&NVRAM_EF_ATCMD_ONOFF_CHECK_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT30",
        VER(NVRAM_EF_ATCMD_ON_OFF_CHECK_LID)
    },
#endif

#if defined(__TST_DNT_LOGGING__)
    {
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_TOTAL,
        NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT31",
        VER(NVRAM_EF_PS_L2COPRO_FILTER_SETTINGS_LID)
    },
#endif  //#if defined(__TST_DNT_LOGGING__)

#if defined(__ETWS_SUPPORT__)
    {
            NVRAM_EF_ETWS_SETTING_LID,
            NVRAM_EF_ETWS_SETTING_TOTAL,
            NVRAM_EF_ETWS_SETTING_SIZE,
            NVRAM_NORMAL(&NVRAM_EF_ETWS_SETTING_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT32",
            VER(NVRAM_EF_ETWS_SETTING_LID)
    },
#endif

    {
            NVRAM_EF_CSM_ESSP_LID,
            NVRAM_EF_CSM_ESSP_TOTAL,
            NVRAM_EF_CSM_ESSP_SIZE,
            NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
            NVRAM_CATEGORY_USER,
            NVRAM_ATTR_AVERAGE,
            "MT35",
            VER(NVRAM_EF_CSM_ESSP_LID)
    },

/* UEM*/
    {
        NVRAM_EF_CUST_HW_LEVEL_TBL_LID,
        NVRAM_EF_CUST_HW_LEVEL_TBL_TOTAL,
        NVRAM_EF_CUST_HW_LEVEL_TBL_SIZE,
    #if defined(__MMI_FMI__)        
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_CUST_HW_LEVEL_TBL_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_SW_VERNO_RESET | NVRAM_ATTR_ZIP_DEFAULT,
        "MT67",
        VER(NVRAM_EF_CUST_HW_LEVEL_TBL_LID)
    },
    
    {
        NVRAM_EF_UEM_MANUFACTURE_DATA_LID,
        NVRAM_EF_UEM_MANUFACTURE_DATA_TOTAL,
        NVRAM_EF_UEM_MANUFACTURE_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UEM_MANUFACTURE_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT68",
        VER(NVRAM_EF_UEM_MANUFACTURE_DATA_LID)
    },
    
    {
        NVRAM_EF_UEM_RMI_DATA_LID,
        NVRAM_EF_UEM_RMI_DATA_TOTAL,
        NVRAM_EF_UEM_RMI_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_ZIP_DEFAULT,
        "MT69",
        VER(NVRAM_EF_UEM_RMI_DATA_LID)
    },

#ifdef __GPS_SUPPORT__
    {
        NVRAM_EF_GPS_SETTING_DATA_LID,
        NVRAM_EF_GPS_SETTING_DATA_TOTAL,
        NVRAM_EF_GPS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6D",
        VER(NVRAM_EF_GPS_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ */

#if defined(__GPS_SUPPORT__) && defined(__MNL_SUPPORT__)
    {
        NVRAM_EF_MNL_SETTING_DATA_LID,
        NVRAM_EF_MNL_SETTING_DATA_TOTAL,
        NVRAM_EF_MNL_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MNL_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6E",
        VER(NVRAM_EF_MNL_SETTING_DATA_LID)
    },
#endif /* __GPS_SUPPORT__ & __MNL_SUPPORT__ */

#if defined(__WIFI_BT_SINGLE_ANTENNA_SUPPORT__)
    {
        NVRAM_EF_BWCS_SETTING_DATA_LID,
        NVRAM_EF_BWCS_SETTING_DATA_TOTAL,
        NVRAM_EF_BWCS_SETTING_DATA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_BWCS_SETTING_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6F",
        VER(NVRAM_EF_BWCS_SETTING_DATA_LID)
    },
#endif /* __WIFI_BT_SINGLE_ANTENNA_SUPPORT__ */


    {
        NVRAM_EF_MS_SECURITY_LID,
        NVRAM_EF_MS_SECURITY_TOTAL,
        NVRAM_EF_MS_SECURITY_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MS_SECURITY_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
    #ifdef __TC01__
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_FACTORY_RESET,
    #else
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL,
    #endif
        "MT6G",
        VER(NVRAM_EF_MS_SECURITY_LID)
    },

#if !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__)
    {
          NVRAM_EF_PHB_LN_ENTRY_LID,
          NVRAM_EF_PHB_LN_ENTRY_TOTAL,
          NVRAM_EF_PHB_LN_ENTRY_SIZE,
          NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6H",
          VER(NVRAM_EF_PHB_LN_ENTRY_LID)
    },

    {
          NVRAM_EF_PHB_LN_TYPE_SEQ_LID,
          NVRAM_EF_PHB_LN_TYPE_SEQ_TOTAL,
          NVRAM_EF_PHB_LN_TYPE_SEQ_SIZE,
          NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
          NVRAM_CATEGORY_USER,
          NVRAM_ATTR_AVERAGE,
          "MT6I",
          VER(NVRAM_EF_PHB_LN_TYPE_SEQ_LID)
    },

#endif /* !defined(__PHB_NO_CALL_LOG__) & !defined(__L1_STANDALONE__) */





    {
        NVRAM_EF_SYS_CACHE_OCTET_LID,
        NVRAM_EF_SYS_CACHE_OCTET_TOTAL,
        NVRAM_EF_SYS_CACHE_OCTET_SIZE,
        NVRAM_NORMAL_NOT_GEN(NVRAM_EF_SYS_CACHE_OCTET_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTI_DEFAULT | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT6K",
        VER(NVRAM_EF_SYS_CACHE_OCTET_LID)
    },

#ifdef __DRM_V02__
    {
        NVRAM_EF_DRM_SETTING_LID,
        NVRAM_EF_DRM_SETTING_TOTAL,
        NVRAM_EF_DRM_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ | NVRAM_ATTR_CONFIDENTIAL,
        "MT6L",
        VER(NVRAM_EF_DRM_SETTING_LID)
    },
    
    {
        NVRAM_EF_DRM_STIME_LID,
        NVRAM_EF_DRM_STIME_TOTAL,
        NVRAM_EF_DRM_STIME_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_CONFIDENTIAL,
        "MT6M",
        VER(NVRAM_EF_DRM_STIME_LID)
    },
    
    {
        NVRAM_EF_DRM_CERPATH_LID,
        NVRAM_EF_DRM_CERPATH_TOTAL,
        NVRAM_EF_DRM_CERPATH_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6N",
        VER(NVRAM_EF_DRM_CERPATH_LID)
    },
#endif /* __DRM_V02__ */


    {
        NVRAM_EF_RAC_PREFERENCE_LID,
        NVRAM_EF_RAC_PREFERENCE_TOTAL,
        NVRAM_EF_RAC_PREFERENCE_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
#ifdef __UMTS_FDD_MODE__        
        "MT6S",
#else
        "MT6Z",
#endif
        VER(NVRAM_EF_RAC_PREFERENCE_LID)
    },

#ifdef __TC02_SECURITY_REQUIREMENT__
    {                                                                   
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_TOTAL,
        NVRAM_EF_MM_IMSI_LOCI_GLOCI_SIZE,
        NVRAM_SECUPACK(NVRAM_EF_MM_IMSI_LOCI_GLOCI_DEFAULT),
        NVRAM_CATEGORY_SECUPACK,
        NVRAM_ATTR_MSP | NVRAM_ATTR_CONFIDENTIAL,
        "MT6T", 
        VER(NVRAM_EF_MM_IMSI_LOCI_GLOCI_LID)
    },
#endif  /* __TC02_SECURITY_REQUIREMENT__ */    

    {
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_TOTAL,
        NVRAM_EF_PS_CONFORMANCE_TESTMODE_SIZE,
#ifdef __UE_SIMULATOR__
        NVRAM_NORMAL(NVRAM_EF_PS_CONFORMANCE_TESTMODE_DEFAULT),
#else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT6U",
        VER(NVRAM_EF_PS_CONFORMANCE_TESTMODE_LID)
    },

#if !defined(L4_NOT_PRESENT)
#ifndef __PHB_STORAGE_BY_MMI__
    {
        NVRAM_EF_PHB_LID,
        NVRAM_EF_PHB_TOTAL,
        NVRAM_EF_PHB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIREC_READ,
        "MT6V",
        VER(NVRAM_EF_PHB_LID)
    },
#endif
#endif

//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
    {
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_TOTAL,
        NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_MULTI_DEFAULT,
        "MT70",
        VER(NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_LID)
        //"MB PROVISION CONTEXT",
        //NVRAM_APP_RESERVED
    },        
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

#ifdef __MINI_LOG_SUPPORT__
	{
		NVRAM_EF_MINI_LOG_01_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR01",
		VER(NVRAM_EF_MINI_LOG_01_LID)
	},
	{
		NVRAM_EF_MINI_LOG_02_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR02",
		VER(NVRAM_EF_MINI_LOG_02_LID)
	},
	{
		NVRAM_EF_MINI_LOG_03_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR03",
		VER(NVRAM_EF_MINI_LOG_03_LID)
	},
	{
		NVRAM_EF_MINI_LOG_04_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR04",
		VER(NVRAM_EF_MINI_LOG_04_LID)
	},
	{
		NVRAM_EF_MINI_LOG_05_LID,
		NVRAM_EF_MINI_LOG_TOTAL,
		NVRAM_EF_MINI_LOG_SIZE,		
		NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),		
		NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
		"TR05",
		VER(NVRAM_EF_MINI_LOG_05_LID)
	},
#endif

  {
        NVRAM_EF_TST_CONFIG_LID,
        NVRAM_EF_TST_CONFIG_TOTAL,
        NVRAM_EF_TST_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_NOT_ZIP_DEFAULT,
        "MT72",
        VER(NVRAM_EF_TST_CONFIG_LID)
    },

#ifdef __SYSSEL_SUPPORT__
    {
        NVRAM_EF_SYSSEL_SETTING_LID,
        NVRAM_EF_SYSSEL_SETTING_TOTAL,
        NVRAM_EF_SYSSEL_SETTING_SIZE,
        NVRAM_NORMAL((const kal_uint8 *)NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT73",
        VER(NVRAM_EF_SYSSEL_SETTING_LID),
    },
#endif /* __SYSSEL_SUPPORT__ */

//__MEDIATEK_SMART_QOS__
#ifdef __MEDIATEK_SMART_QOS__
    {
        NVRAM_EF_MSQ_LIST_LID,
        NVRAM_EF_MSQ_LIST_TOTAL,
        NVRAM_EF_MSQ_LIST_SIZE,
        NVRAM_NORMAL(NVRAM_EF_MSQ_LIST_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT74",
        VER(NVRAM_EF_MSQ_LIST_LID)
    },
#endif /* __MEDIATEK_SMART_QOS__ */

#ifdef __LTE_RAT__
    {

        NVRAM_EF_EPSLOCI_EPSNSC_TIN_LID,
        NVRAM_EF_EPSLOCI_EPSNSC_TIN_TOTAL,
        NVRAM_EF_EPSLOCI_EPSNSC_TIN_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_EPSLOCI_EPSNSC_TIN_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
#ifdef __UMTS_FDD_MODE__         
        "MT75",
#else
        "MT7F",
#endif
        VER(NVRAM_EF_EPSLOCI_EPSNSC_TIN_LID)
    },

    {

        NVRAM_EF_LTE_PREFERENCE_LID,
        NVRAM_EF_LTE_PREFERENCE_TOTAL,
        NVRAM_EF_LTE_PREFERENCE_SIZE,
        NVRAM_CUSTPACK(NVRAM_EF_LTE_PREFERENCE_DEFAULT),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_CUSTPACK,
        NVRAM_ATTR_AVERAGE | NVRAM_ATTR_FACTORY_RESET,
#if (defined(__SGLTE__) || defined(__SGLTE_DSDS__))
        "MT7E",
#else
        "MT76",
#endif /* __SGLTE__ || __SGLTE_DSDS__ */
        VER(NVRAM_EF_LTE_PREFERENCE_LID)
    },

    {

        NVRAM_EF_ERRC_STORED_CARRIER_LID,
        NVRAM_EF_ERRC_STORED_CARRIER_TOTAL,
        NVRAM_EF_ERRC_STORED_CARRIER_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1A",
        VER(NVRAM_EF_ERRC_STORED_CARRIER_LID)
    },

    {

        NVRAM_EF_ERRC_PERFORMANCE_PARA_LID,
        NVRAM_EF_ERRC_PERFORMANCE_PARA_TOTAL,
        NVRAM_EF_ERRC_PERFORMANCE_PARA_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ERRC_PERFORMANCE_PARA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1B",
        VER(NVRAM_EF_ERRC_PERFORMANCE_PARA_LID)
    },

    {

        NVRAM_EF_ERRC_FINGER_PRINT_LID,
        NVRAM_EF_ERRC_FINGER_PRINT_TOTAL,
        NVRAM_EF_ERRC_FINGER_PRINT_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1C",
        VER(NVRAM_EF_ERRC_FINGER_PRINT_LID)
    },

    {

        NVRAM_EF_ERRC_LEARNED_MCC_LID,
        NVRAM_EF_ERRC_LEARNED_MCC_TOTAL,
        NVRAM_EF_ERRC_LEARNED_MCC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1D",
        VER(NVRAM_EF_ERRC_LEARNED_MCC_LID)
    },    

    {

        NVRAM_EF_ERRC_STORED_CELL_LID,
        NVRAM_EF_ERRC_STORED_CELL_TOTAL,
        NVRAM_EF_ERRC_STORED_CELL_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1E",
        VER(NVRAM_EF_ERRC_STORED_CELL_LID)
    },
		
    {

        NVRAM_EF_ERRC_AFR_SETTING_LID,
        NVRAM_EF_ERRC_AFR_SETTING_TOTAL,
        NVRAM_EF_ERRC_AFR_SETTING_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ERRC_AFR_SETTING_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "ER1F",
        VER(NVRAM_EF_ERRC_AFR_SETTING_LID)
    },

    {

        NVRAM_EF_LTE_CAP_LID,
        NVRAM_EF_LTE_CAP_TOTAL,
        NVRAM_EF_LTE_CAP_SIZE,
        NVRAM_NORMAL(NVRAM_EF_LTE_CAP_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "LTEA",
        VER(NVRAM_EF_LTE_CAP_LID)
    },

    {

        NVRAM_EF_UE_EUTRA_CAP_CSFB_LID,
        NVRAM_EF_UE_EUTRA_CAP_CSFB_TOTAL,
        NVRAM_EF_UE_EUTRA_CAP_CSFB_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UE_EUTRA_CAP_CSFB_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "LTEB",
        VER(NVRAM_EF_UE_EUTRA_CAP_CSFB_LID)
    },    

    {

        NVRAM_EF_UE_EUTRA_CAP_MMDC_LID,
        NVRAM_EF_UE_EUTRA_CAP_MMDC_TOTAL,
        NVRAM_EF_UE_EUTRA_CAP_MMDC_SIZE,
        NVRAM_NORMAL(NVRAM_EF_UE_EUTRA_CAP_MMDC_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "LTEC",
        VER(NVRAM_EF_UE_EUTRA_CAP_MMDC_LID)
    },       
#endif /* __LTE_RAT__ */

    {
        NVRAM_EF_NWSEL_DATA_LID,
        NVRAM_EF_NWSEL_DATA_TOTAL,
        NVRAM_EF_NWSEL_DATA_SIZE,
        NVRAM_CUSTPACK(COMMON_NVRAM_EF_NWSEL_DATA_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
#ifdef __UMTS_FDD_MODE__       
        "MT77",
#else
        "MT7D",
#endif
        VER(NVRAM_EF_NWSEL_DATA_LID)
    },

#ifdef __LTE_RAT__
	{
	    NVRAM_EF_EL1_PWRONCAL_LID,
	    NVRAM_EF_EL1_PWRONCAL_TOTAL,
	    NVRAM_EF_EL1_PWRONCAL_SIZE,
	    NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
	    NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CALIBRAT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL08",
	    VER(NVRAM_EF_EL1_PWRONCAL_LID)
	},
	
	{
	    NVRAM_EF_EL1_DSPLOGFILTER_LID,
	    NVRAM_EF_EL1_DSPLOGFILTER_TOTAL,
	    NVRAM_EF_EL1_DSPLOGFILTER_SIZE,
	    NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
	    NVRAM_CATEGORY_USER| NVRAM_CATEGORY_CALIBRAT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL09",
	    VER(NVRAM_EF_EL1_DSPLOGFILTER_LID)
	},

	{
	    NVRAM_EF_EL1_FREQADJTBL_LID,
	    NVRAM_EF_EL1_FREQADJTBL_TOTAL,
	    NVRAM_EF_EL1_FREQADJTBL_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0A",
	    VER(NVRAM_EF_EL1_FREQADJTBL_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_1STBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0B",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_1STBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_2NDBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0C",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_2NDBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_3RDBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0D",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_3RDBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_4THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0E",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_4THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_5THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0F",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_5THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_6THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0G",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_6THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_7THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0H",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_7THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_8THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0I",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_8THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_9THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0J",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_9THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_10THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0K",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_10THBAND_LID)
	},

	{
	    NVRAM_EF_EL1_RSSIGAINTBL_11THBAND_LID,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
	    NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL0L",
	    VER(NVRAM_EF_EL1_RSSIGAINTBL_11THBAND_LID)
	},

   {
       NVRAM_EF_EL1_RSSIGAINTBL_12THBAND_LID,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL0M",
       VER(NVRAM_EF_EL1_RSSIGAINTBL_12THBAND_LID)
   },

   {
       NVRAM_EF_EL1_RSSIGAINTBL_13THBAND_LID,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL0N",
       VER(NVRAM_EF_EL1_RSSIGAINTBL_13THBAND_LID)
   },

   {
       NVRAM_EF_EL1_RSSIGAINTBL_14THBAND_LID,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_TOTAL,
       NVRAM_EF_EL1_RSSIGAINTBL_BAND_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL0O",
       VER(NVRAM_EF_EL1_RSSIGAINTBL_14THBAND_LID)
   },

   {
        NVRAM_EF_EL1_CTRL_REG_RW_LID,
        NVRAM_EF_EL1_CTRL_REG_RW_TOTAL,
        NVRAM_EF_EL1_CTRL_REG_RW_SIZE,
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE,
        "EL1A",
        VER(NVRAM_EF_EL1_CTRL_REG_RW_LID)
    },

   {
        NVRAM_EF_EL1_TXDAC_1STBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1B",
        VER(NVRAM_EF_EL1_TXDAC_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_2NDBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1C",
        VER(NVRAM_EF_EL1_TXDAC_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_3RDBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1D",
        VER(NVRAM_EF_EL1_TXDAC_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_4THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1E",
        VER(NVRAM_EF_EL1_TXDAC_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_5THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1F",
        VER(NVRAM_EF_EL1_TXDAC_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_6THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1G",
        VER(NVRAM_EF_EL1_TXDAC_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_7THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1H",
        VER(NVRAM_EF_EL1_TXDAC_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_8THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1I",
        VER(NVRAM_EF_EL1_TXDAC_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_9THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1J",
        VER(NVRAM_EF_EL1_TXDAC_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_10THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1K",
        VER(NVRAM_EF_EL1_TXDAC_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_11THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1L",
        VER(NVRAM_EF_EL1_TXDAC_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_12THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1M",
        VER(NVRAM_EF_EL1_TXDAC_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_13THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1N",
        VER(NVRAM_EF_EL1_TXDAC_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXDAC_14THBAND_LID,
        NVRAM_EF_EL1_TXDAC_BAND_TOTAL,
        NVRAM_EF_EL1_TXDAC_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1O",
        VER(NVRAM_EF_EL1_TXDAC_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_1STBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1P",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_2NDBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1Q",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_3RDBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1R",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_4THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1S",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_5THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1T",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_6THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1U",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_7THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1V",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_8THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1W",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_9THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1X",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_10THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1Y",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_11THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL1Z",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_12THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2A",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_13THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2B",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TXPAOCTLEV_14THBAND_LID,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_TOTAL,
        NVRAM_EF_EL1_TXPAOCTLEV_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2C",
        VER(NVRAM_EF_EL1_TXPAOCTLEV_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_ETVINLUTDATA_1STBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2D",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_ETVINLUTDATA_2NDBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2E",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_2NDBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_3RDBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2F",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_3RDBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_4THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2G",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_4THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_5THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2H",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_5THBAND_LID)
    },	

    {
        NVRAM_EF_EL1_ETVINLUTDATA_6THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2I",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_6THBAND_LID)
    },	

    {
        NVRAM_EF_EL1_ETVINLUTDATA_7THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2J",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_7THBAND_LID)
    },	

    {
        NVRAM_EF_EL1_ETVINLUTDATA_8THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2K",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_8THBAND_LID)
    },	

    {
        NVRAM_EF_EL1_ETVINLUTDATA_9THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2L",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_9THBAND_LID)
    },	

    {
        NVRAM_EF_EL1_ETVINLUTDATA_10THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2M",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_10THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_11THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2N",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_11THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_12THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2O",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_12THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_13THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2P",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_13THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETVINLUTDATA_14THBAND_LID,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_TOTAL,
        NVRAM_EF_EL1_ETVINLUTDATA_BAND_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2Q",
        VER(NVRAM_EF_EL1_ETVINLUTDATA_14THBAND_LID)
    },		

    {
        NVRAM_EF_EL1_ETCOMPPARAM_LID,
        NVRAM_EF_EL1_ETCOMPPARAM_TOTAL,
        NVRAM_EF_EL1_ETCOMPPARAM_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2R",
        VER(NVRAM_EF_EL1_ETCOMPPARAM_LID)
    },

    {
        NVRAM_EF_EL1_TEMPERATUREDAC_LID,
        NVRAM_EF_EL1_TEMPERATUREDAC_TOTAL,
        NVRAM_EF_EL1_TEMPERATUREDAC_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2S",
        VER(NVRAM_EF_EL1_TEMPERATUREDAC_LID)
    },			

    {
        NVRAM_EF_EL1_BAND_INDICATOR_LID,
        NVRAM_EF_EL1_BAND_INDICATOR_TOTAL,
        NVRAM_EF_EL1_BAND_INDICATOR_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2T",
        VER(NVRAM_EF_EL1_BAND_INDICATOR_LID)
    },

    {
        NVRAM_EF_EL1_RX_PDATABASE_LID,
        NVRAM_EF_EL1_RX_PDATABASE_TOTAL,
        NVRAM_EF_EL1_RX_PDATABASE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2U",
        VER(NVRAM_EF_EL1_RX_PDATABASE_LID)
    },

    {
        NVRAM_EF_EL1_TX_PDATABASE_LID,
        NVRAM_EF_EL1_TX_PDATABASE_TOTAL,
        NVRAM_EF_EL1_TX_PDATABASE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2V",
        VER(NVRAM_EF_EL1_TX_PDATABASE_LID)
    },

    {
        NVRAM_EF_EL1_RF_IO_LID,
        NVRAM_EF_EL1_RF_IO_TOTAL,
        NVRAM_EF_EL1_RF_IO_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2W",
        VER(NVRAM_EF_EL1_RF_IO_LID)
    },

    {
        /* Dynamic Radio-setting Dedicated Image (DRDI) */
        // DRDI Enable
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_LID,
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_TOTAL,
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2X",
        VER(NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_LID)
    },

    {
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID,
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL,
        NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT), // NVRAM_NORMAL for data not in secupack and custpack
        NVRAM_CATEGORY_CALIBRAT,
        /* Attribute NVRAM_ATTR_MULTIPLE for double copy on flash */
        NVRAM_ATTR_MULTIPLE,
        /* Category NVRAM_CATEGORY_CUSTPACK for using default value from custpack */
        "EL2Y",
        VER(NVRAM_EF_EL1_CUSTOM_DYNAMIC_INIT_DEBUG_LID)
        //"EL1 Custom Dynamic Init Debug",
        //NVRAM_APP_RESERVED
    },
    
    {
        /* Single ANT Feature */
        NVRAM_EF_EL1_RF_RX_PATH_CONFIG_LID,
        NVRAM_EF_EL1_RF_RX_PATH_CONFIG_TOTAL,
        NVRAM_EF_EL1_RF_RX_PATH_CONFIG_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL2Z",
        VER(NVRAM_EF_EL1_RF_RX_PATH_CONFIG_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_FEATURE_LID,
        NVRAM_EF_EL1_MIPI_FEATURE_TOTAL,
        NVRAM_EF_EL1_MIPI_FEATURE_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL30",
        VER(NVRAM_EF_EL1_MIPI_FEATURE_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL31",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL32",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL33",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL34",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL35",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_6THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL36",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_7THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL37",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_8THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL38",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_9THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL39",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_10THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3A",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_11THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3B",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_12THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3C",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_13THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3D",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_EVENT_14THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3E",
        VER(NVRAM_EF_EL1_MIPI_RX_EVENT_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3F",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3G",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3H",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3I",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3J",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_6THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3K",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_7THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3L",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_8THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3M",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_9THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3N",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_10THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3O",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_11THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3P",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_12THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3Q",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_13THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3R",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_EVENT_14THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3S",
        VER(NVRAM_EF_EL1_MIPI_TX_EVENT_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3T",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3U",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3V",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3W",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3X",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_6THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3Y",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_7THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL3Z",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_8THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL40",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_9THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL41",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_10THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL42",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_11THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL43",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_12THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL44",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_13THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL45",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_14THBAND_LID,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT| NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL46",
        VER(NVRAM_EF_EL1_MIPI_PA_TPC_SECTION_DATA_14THBAND_LID)
    },

	{
	    NVRAM_EF_EL1_MPRADJTBL_LID,
	    NVRAM_EF_EL1_MPRADJTBL_TOTAL,
	    NVRAM_EF_EL1_MPRADJTBL_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL47",
	    VER(NVRAM_EF_EL1_MPRADJTBL_LID)
	},

	{
	    NVRAM_EF_EL1_AMPRADJTBL_LID,
	    NVRAM_EF_EL1_AMPRADJTBL_TOTAL,
	    NVRAM_EF_EL1_AMPRADJTBL_SIZE,
	    NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
	    NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
	    NVRAM_ATTR_MULTIPLE,
	    "EL48",
	    VER(NVRAM_EF_EL1_AMPRADJTBL_LID)
	},

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL49",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_1STBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_2NDBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4A",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_2NDBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_3RDBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4B",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_3RDBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_4THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4C",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_4THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_5THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4D",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_5THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_6THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4E",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_6THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_7THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4F",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_7THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_8THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4G",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_8THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_9THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4H",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_9THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_10THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4I",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_10THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_11THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4J",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_11THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_12THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4K",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_12THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_13THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4L",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_13THBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_TPC_EVENT_14THBAND_LID,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4M",
       VER(NVRAM_EF_EL1_MIPI_TPC_EVENT_14THBAND_LID)
   },

   {
       NVRAM_EF_EL1_RXON_BPIOFFSET_LID,
       NVRAM_EF_EL1_RXON_BPIOFFSET_TOTAL,
       NVRAM_EF_EL1_RXON_BPIOFFSET_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_USER| NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4N",
       VER(NVRAM_EF_EL1_RXON_BPIOFFSET_LID)
   },

   {
       NVRAM_EF_EL1_TXON_BPIOFFSET_LID,
       NVRAM_EF_EL1_TXON_BPIOFFSET_TOTAL,
       NVRAM_EF_EL1_TXON_BPIOFFSET_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4O",
       VER(NVRAM_EF_EL1_TXON_BPIOFFSET_LID)
   },

   {
       NVRAM_EF_EL1_RXOFF_BPIOFFSET_LID,
       NVRAM_EF_EL1_RXOFF_BPIOFFSET_TOTAL,
       NVRAM_EF_EL1_RXOFF_BPIOFFSET_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4P",
       VER(NVRAM_EF_EL1_RXOFF_BPIOFFSET_LID)
   },

   {
       NVRAM_EF_EL1_TXOFF_BPIOFFSET_LID,
       NVRAM_EF_EL1_TXOFF_BPIOFFSET_TOTAL,
       NVRAM_EF_EL1_TXOFF_BPIOFFSET_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4Q",
       VER(NVRAM_EF_EL1_TXOFF_BPIOFFSET_LID)
   },

   /*** MIPI BYPASS Feature ***/
   {
       NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4R",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_FEATURE_LID)
   },
    
   {
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4S",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_1STBAND_LID)
    },

    {
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_2NDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4T",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_2NDBAND_LID)
    },

    {
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_3RDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4U",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_3RDBAND_LID)
    },
    {
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4V",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_1STBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_2NDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4X",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_2NDBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_3RDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4Y",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_3RDBAND_LID)
   },

   {
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL4Z",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_1STBAND_LID)
    },

    {
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_2NDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL50",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_2NDBAND_LID)
    },

    {
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_3RDBAND_LID,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_TOTAL,
       NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
       NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
       NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
       NVRAM_ATTR_MULTIPLE,
       "EL51",
       VER(NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL52",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL53",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL54",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL55",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL56",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_6THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL57",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_7THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL58",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_8THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL59",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_9THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5A",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_10THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5B",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_11THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5C",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_12THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5D",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_13THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5E",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_RX_DATA_14THBAND_LID,
        NVRAM_EF_EL1_MIPI_RX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_RX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5F",
        VER(NVRAM_EF_EL1_MIPI_RX_DATA_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5G",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5H",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5I",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5J",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5K",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_6THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5L",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_7THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5M",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_8THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5N",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_9THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5O",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_10THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5P",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_11THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5Q",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_12THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5R",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_13THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5S",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_TX_DATA_14THBAND_LID,
        NVRAM_EF_EL1_MIPI_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5T",
        VER(NVRAM_EF_EL1_MIPI_TX_DATA_14THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5U",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_2NDBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5V",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_3RDBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5W",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_3RDBAND_LID)
    },

#if IS_4G_TX_POWER_OFFSET_SUPPORT
    {
        NVRAM_EF_EL1_4G_TPO_PARAMETER_LID,
        NVRAM_EF_EL1_4G_TPO_PARAMETER_TOTAL,
        NVRAM_EF_EL1_4G_TPO_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5X",
        VER(NVRAM_EF_EL1_4G_TPO_PARAMETER_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_1STBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5Y",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_1STBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_2NDBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL5Z",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_2NDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_3RDBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL60",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_3RDBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_4THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL61",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_5THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL62",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_6THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL63",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_6THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_7THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL64",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_7THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_8THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL65",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_8THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_9THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL66",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_9THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_10THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL67",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_10THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_11THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL68",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_11THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_12THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL69",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_12THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_13THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6A",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_13THBAND_LID)
    },

    {
        NVRAM_EF_EL1_TX_POWER_OFFSET_14THBAND_LID,
        NVRAM_EF_EL1_TX_POWER_OFFSET_TOTAL,
        NVRAM_EF_EL1_TX_POWER_OFFSET_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6B",
        VER(NVRAM_EF_EL1_TX_POWER_OFFSET_14THBAND_LID)
    },    
#endif /* IS_4G_TX_POWER_OFFSET_SUPPORT */

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6C",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6D",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_EVENT_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6E",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6F",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TPC_EVENT_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6G",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6H",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_PA_TPC_SECTION_DATA_5THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_4THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6I",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_4THBAND_LID)
    },

    {
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_5THBAND_LID,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_TOTAL,
        NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6J",
        VER(NVRAM_EF_EL1_MIPI_BYPASS_TX_DATA_5THBAND_LID)
    },

#if defined(__TAS_SUPPORT__)
    /* For the Transmit Antenna Selection feature */
    {
        NVRAM_EF_EL1_TAS_PARAMETER_LID,
        NVRAM_EF_EL1_TAS_PARAMETER_TOTAL,
        NVRAM_EF_EL1_TAS_PARAMETER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6K",
        VER(NVRAM_EF_EL1_TAS_PARAMETER_LID)
    },    

    #if defined(__TAS_INTERNAL_NVRAM_VISIBLE__)
    {
        NVRAM_EF_EL1_TAS_OTHER_LID,
        NVRAM_EF_EL1_TAS_OTHER_TOTAL,
        NVRAM_EF_EL1_TAS_OTHER_SIZE,
        NVRAM_DEFAULT_FUNC(nvram_get_eL1_default_value_to_write),
        NVRAM_CATEGORY_CALIBRAT | NVRAM_CATEGORY_FUNC_DEFAULT,
        NVRAM_ATTR_MULTIPLE,
        "EL6L",
        VER(NVRAM_EF_EL1_TAS_OTHER_LID)
    },    
    #endif /* __TAS_INTERNAL_NVRAM_VISIBLE__ */
#endif /* __TAS_SUPPORT__ */
#endif
#ifdef __HMU_ENABLE__
    {
        NVRAM_EF_HMU_CONFIG_LID,
        NVRAM_EF_HMU_CONFIG_TOTAL,
        NVRAM_EF_HMU_CONFIG_SIZE,
        //NVRAM_CUSTPACK(NVRAM_EF_HMU_CONFIG_DEFAULT),
#ifdef __USB_MBIM_SUPPORT__
        NVRAM_NORMAL(NVRAM_EF_HMU_CONFIG_MBIM),
#else
        NVRAM_NORMAL(NVRAM_EF_HMU_CONFIG_DEFAULT),
#endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT7A",
        VER(NVRAM_EF_HMU_CONFIG_LID),
    },
	{
        NVRAM_EF_HMU_HD_CONFIG_LID,
        NVRAM_EF_HMU_HD_CONFIG_TOTAL,
        NVRAM_EF_HMU_HD_CONFIG_SIZE,
        //NVRAM_CUSTPACK(NVRAM_EF_HMU_CONFIG_DEFAULT),
        NVRAM_NORMAL(NVRAM_EF_HMU_HD_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT7B",
        VER(NVRAM_EF_HMU_HD_CONFIG_LID),
    },
#endif
#ifdef __NMU_ENABLE__
	{
        NVRAM_EF_NMU_CONFIG_LID,
        NVRAM_EF_NMU_CONFIG_TOTAL,
        NVRAM_EF_NMU_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_NMU_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
		NVRAM_ATTR_AVERAGE,
        "MT7C",
        VER(NVRAM_EF_NMU_CONFIG_LID),
	},				
#endif	
    {
        NVRAM_EF_REGIONAL_PHONE_MODE_LID,
        NVRAM_EF_REGIONAL_PHONE_MODE_TOTAL,
        NVRAM_EF_REGIONAL_PHONE_MODE_SIZE,
    #ifdef __REGIONAL_PHONE__
        NVRAM_NORMAL(NVRAM_EF_FF_DEFAULT),
    #else
        NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
    #endif
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_FACTORY_RESET,
        "MT78",
        VER(NVRAM_EF_REGIONAL_PHONE_MODE_LID),
    },

#ifdef __MOD_IMC__
    {
        NVRAM_EF_IMS_PROFILE_LID,
        NVRAM_EF_IMS_PROFILE_TOTAL,
        NVRAM_EF_IMS_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_IMS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT79",
        VER(NVRAM_EF_IMS_PROFILE_LID),
    },
    {
        NVRAM_EF_LTECSR_PROFILE_LID,
        NVRAM_EF_LTECSR_PROFILE_TOTAL,
        NVRAM_EF_LTECSR_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_LTECSR_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT82",
        VER(NVRAM_EF_LTECSR_PROFILE_LID),
    },
#endif /* __MOD_IMC__ */

#ifdef __VOLTE_SUPPORT__
    {
        NVRAM_EF_VDM_ADS_PROFILE_LID,
        NVRAM_EF_VDM_ADS_PROFILE_TOTAL,
        NVRAM_EF_VDM_ADS_PROFILE_SIZE,
        NVRAM_NORMAL(NVRAM_EF_VDM_ADS_PROFILE_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_AVERAGE,
        "MT83",
        VER(NVRAM_EF_VDM_ADS_PROFILE_LID),
    },
#endif /* __VOLTE_SUPPORT__ */

#if defined(__2G_MIPI_SUPPORT__)
   #ifdef __GSM850__
        {
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_LID,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_TOTAL,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
         /* 20140503,Update PA DATA Check Condition */
         #if defined(__DUAL_TALK_SUPPORT__)
         "MT3J",
         #else
         "MT3K",
         #endif
         /*NVRAM filename at below had been used */
         /*
         #if 1
            #if defined(__DUAL_TALK_SUPPORT__)
         "MT3F",
            #else
         "MT3B",
            #endif
         #else
         "MT36",
         #endif
         */
         VER(NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM850_LID),
     },
   #endif
   #ifdef __EGSM900__
     {
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_LID,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_TOTAL,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
         /* 20140503,Update PA DATA Check Condition */
         #if defined(__DUAL_TALK_SUPPORT__)
         "MT3L",
         #else
         "MT3M",
         #endif
         /*NVRAM filename at below had been used */
         /*
         #if 1
            #if defined(__DUAL_TALK_SUPPORT__)
         "MT3G",
            #else 
         "MT3C",
            #endif
         #else
         "MT37",
         #endif
         */
         VER(NVRAM_EF_L1_MIPI_CTRL_TABLE_GSM900_LID),
     },
   #endif
   #ifdef __DCS1800__
     {
         NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_LID,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_TOTAL,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
         /* 20140503,Update PA DATA Check Condition */
         #if defined(__DUAL_TALK_SUPPORT__)
         "MT3N",
         #else
         "MT3O",
         #endif
         /*NVRAM filename at below had been used */
         /*
         #if 1 
            #if defined(__DUAL_TALK_SUPPORT__)
         "MT3H",
            #else 
         "MT3D",
            #endif
         #else
         "MT38",
         #endif
         */
         VER(NVRAM_EF_L1_MIPI_CTRL_TABLE_DCS1800_LID),
     },
   #endif
   #ifdef __PCS1900__
     {
         NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_LID,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_TOTAL,
         NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
         /* 20140503,Update PA DATA Check Condition */
         #if defined(__DUAL_TALK_SUPPORT__)
         "MT3P",
         #else
         "MT3Q",
         #endif
         /*NVRAM filename at below had been used */
         /*
         #if 1
            #if defined(__DUAL_TALK_SUPPORT__)
         "MT3I",
            #else 
         "MT3E",
            #endif
         #else
         "MT39",
         #endif
         */
         VER(NVRAM_EF_L1_MIPI_CTRL_TABLE_PCS1900_LID),
     },
   #endif
#endif
     {
         NVRAM_EF_L1_CUSTOM_DRDI_STATUS_DEBUGINFO_LID,
         NVRAM_EF_L1_CUSTOM_DRDI_STATUS_DEBUGINFO_TOTAL,
         NVRAM_EF_L1_CUSTOM_DRDI_STATUS_DEBUGINFO_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
         #if defined(__DUAL_TALK_SUPPORT__)
         "MT3R",
         #else
         "MT3S",
         #endif
         VER(NVRAM_EF_L1_CUSTOM_DRDI_STATUS_DEBUGINFO_LID),
     },
#if defined(__TAS_SUPPORT__)
      {
         NVRAM_EF_L1_TAS_CUSTOM_PARAMES_LID,
         NVRAM_EF_L1_TAS_CUSTOM_PARAMES_TOTAL,
         NVRAM_EF_L1_TAS_CUSTOM_PARAMES_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
        "MT9X",
        VER(NVRAM_EF_L1_TAS_CUSTOM_PARAMES_LID),
      },
   #if defined(__TAS_INTERNAL_NVRAM_VISIBLE__)
      {
         NVRAM_EF_L1_TAS_LIB_PARAMES_LID,
         NVRAM_EF_L1_TAS_LIB_PARAMES_TOTAL,
         NVRAM_EF_L1_TAS_LIB_PARAMES_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
        "MT9Y",
        VER(NVRAM_EF_L1_TAS_LIB_PARAMES_LID),
     },
   #endif
     {
         NVRAM_EF_L1_TAS_CUSTOM_PDATA_LID,
         NVRAM_EF_L1_TAS_CUSTOM_PDATA_TOTAL,
         NVRAM_EF_L1_TAS_CUSTOM_PDATA_SIZE,
         NVRAM_DEFAULT_FUNC(nvram_get_L1_default_value_to_write),
         NVRAM_CATEGORY_USER | NVRAM_CATEGORY_FUNC_DEFAULT,
         NVRAM_ATTR_MULTIPLE,
        "MT9Z",
        VER(NVRAM_EF_L1_TAS_CUSTOM_PDATA_LID),
     },
#endif
   #ifdef __AST_TL1_TDD_RF_PARAMETER_SUPPORT__
	  {
		    NVRAM_EF_AST_TL1_RF_PARAM_LID,
		    NVRAM_EF_AST_TL1_RF_PARAM_TOTAL,
		    NVRAM_EF_AST_TL1_RF_PARAM_SIZE,
		    NVRAM_NORMAL(AST_TL1_RF_PARAMETER_DEFAULT),
		    NVRAM_CATEGORY_USER, /// this is auto calibrated in first time mcu power on (or the data loss case), don't need backup & restore
		    NVRAM_ATTR_AVERAGE,
		    "TL10", 
		    VER(NVRAM_EF_AST_TL1_RF_PARAM_LID),
	   },				
#endif
#ifdef __3G_TDD_MIPI_SUPPORT__

	{
		NVRAM_EF_AST_TL1_RFFE_PARAM_LID,
		NVRAM_EF_AST_TL1_RFFE_PARAM_TOTAL,
		NVRAM_EF_AST_TL1_RFFE_PARAM_SIZE,
		NVRAM_NORMAL(AST_TL1_RFFE_PARAMETER_DEFAULT),
		NVRAM_CATEGORY_USER, /// this is auto calibrated in first time mcu power on (or the data loss case), don't need backup & restore
		NVRAM_ATTR_AVERAGE,
		"TL11", 
		VER(NVRAM_EF_AST_TL1_RFFE_PARAM_LID)
	},				
#endif	
#ifdef __AST_TL1_TDD__
// DRDI INIT STATUS FOR NVRAM
	{
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_LID,
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_TOTAL,
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_SIZE,
				NVRAM_NORMAL(TDS_DRDI_STATUS_DEFAULT),
				NVRAM_CATEGORY_USER, 
				NVRAM_ATTR_AVERAGE,
				"TL12", 
				VER(NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_LID),
    },
// DRDI DEBUG INFO. FOR NVRAM
    {
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_LID,
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_TOTAL,
				NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_SIZE,
				NVRAM_NORMAL(NVRAM_EF_ZERO_DEFAULT),
				NVRAM_CATEGORY_USER, 
				NVRAM_ATTR_AVERAGE,
				"TL13", 
				VER(NVRAM_EF_AST_CUSTOM_DYNAMIC_INIT_DEBUG_LID),
    },
    
#ifdef __AST_TL1_TDD_RF_TIMESEQ_SUPPORT__
// RF TIME SEQUENCE INFO. FOR NVRAM
    {
		             NVRAM_EF_AST_TL1_RF_TIMESEQ_LID,
		             NVRAM_EF_AST_TL1_RF_TIMESEQ_TOTAL,
		             NVRAM_EF_AST_TL1_RF_TIMESEQ_SIZE,
		             NVRAM_NORMAL(AST_TL1_SEQ_DEFAULT),
		             NVRAM_CATEGORY_USER, 
		             NVRAM_ATTR_AVERAGE,
		             "TL14", 
		             VER(NVRAM_EF_AST_TL1_RF_TIMESEQ_LID),
    },	
#endif
    
#endif
    {
        NVRAM_EF_SBP_MODEM_CONFIG_LID,
        NVRAM_EF_SBP_MODEM_CONFIG_TOTAL,
        NVRAM_EF_SBP_MODEM_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SBP_MODEM_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "MT80",
        VER(NVRAM_EF_SBP_MODEM_CONFIG_LID)
    },
    {
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID,
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_TOTAL,
        NVRAM_EF_SBP_MODEM_DATA_CONFIG_SIZE,
        NVRAM_NORMAL(NVRAM_EF_SBP_MODEM_DATA_CONFIG_DEFAULT),
        NVRAM_CATEGORY_USER,
        NVRAM_ATTR_MULTIPLE | NVRAM_ATTR_CONFIDENTIAL | NVRAM_ATTR_MSP,
        "MT81",
        VER(NVRAM_EF_SBP_MODEM_DATA_CONFIG_LID)
    },
};

/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID begin */
#ifdef NVRAM_AUTO_GEN
nvram_sys_cache_entry nvram_sys_cache[] =
{
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_BEGIN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "Record system cache will be restore or not",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),

    SYS_CACHE_ENTRY(NVRAM_SYS_FLIGHTMODE_STATE,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FLIGHTMODE_STATE",
                #if (GEMINI_PLUS == 4)
                    0x00, 0x00, 0x0F, 0x00, 0x01, 0x0A, 0x00, 0x00),
                #elif (GEMINI_PLUS == 3)
                    0x00, 0x00, 0x07, 0x00, 0x01, 0x0A, 0x00, 0x00),
                #elif (GEMINI_PLUS == 2)
                    0x00, 0x00, 0x03, 0x00, 0x01, 0x0A, 0x00, 0x00),
                #else
                    0x00, 0x00, 0x00, 0x00, 0x01, 0x0A, 0x00, 0x00),
                #endif
    SYS_CACHE_ENTRY(NVRAM_SYS_DSP_PATCH,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_DSP_PATCH",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_SIM_PLUS_SETTING,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_SIM_PLUS_SETTING",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_FIXED_GAIN_MECH_FOR_HELIOS2",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_FACTORY_FLAG,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_FACTORY_FLAG",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_LAST_FAT_STATUS,
                    NVRAM_APP_RESERVED,
                    KAL_TRUE,
                    "NVRAM_SYS_LAST_FAT_STATUS",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_INFO,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_INFO",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#if defined(NEPTUNE_MMI)
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#else
    SYS_CACHE_ENTRY(NVRAM_SYS_PHB_COMPARE_DIGIT,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_PHB_COMPARE_DIGIT",
                    0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
#endif
    SYS_CACHE_ENTRY(NVRAM_SYS_SVN,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SVN",
                    0x87, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_BOOT_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_BOOT_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_USB_TETHERING_MODE,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_USB_TETHERING_MODE\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),                    
    SYS_CACHE_ENTRY(NVRAM_SYS_AUTO_TEST,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_AUTO_TEST\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
    SYS_CACHE_ENTRY(NVRAM_SYS_MINI_LOG_IDX,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_MINI_LOG_IDX\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),       
     SYS_CACHE_ENTRY(NVRAM_SYS_SWLA,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "NVRAM_SYS_SWLA\0",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),             

    /* !!Add a entry above this line by using SYS_CACHE_ENTRY macro */
    SYS_CACHE_ENTRY(NVRAM_SYS_CACHE_MAX,
                    NVRAM_APP_RESERVED,
                    KAL_FALSE,
                    "The last record of system cache",
                    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00),
};
#endif
/* Configure NVRAM_EF_SYS_CACHE_OCTET_LID end */

#endif /* NVRAM_NOT_PRESENT */
