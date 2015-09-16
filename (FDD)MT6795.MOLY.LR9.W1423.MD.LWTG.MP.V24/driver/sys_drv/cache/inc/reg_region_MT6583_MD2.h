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
 *   reg_region_MT6583_MD2.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is used to define MT6255 register region
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

                             /*name,                virtual address,           physical address,          length                    RW/RO*/
X_REGISTER_REGION_NCNB_CONST(MCUSYS_APB,            0x80000000,                0x80000000,                0x001A0000,                0x0)
X_REGISTER_REGION_NCNB_CONST(MD2GSYS,               0x82000000,                0x82000000,                0x00CF0000,                0x0)
X_REGISTER_REGION_NCNB_CONST(MODEMSYS_TOP,          0x83000000,                0x83000000,                0x000C0000,                0x0)
X_REGISTER_REGION_NCNB_CONST(HSPASYS1,              0x83200000,                0x83200000,                0x00040000,                0x0)
X_REGISTER_REGION_NCNB_CONST(HSPASYS2,              0x83400000,                0x83400000,                0x00050000,                0x0)
X_REGISTER_REGION_NCNB_CONST(HSPASYS3,              0x83600000,                0x83600000,                0x000F0000,                0x0)
X_REGISTER_REGION_NCNB_CONST(HSPASYS4,              0x83800000,                0x83800000,                0x000E0000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_INFRA1,             0xA0000000,                0xA0000000,                0x0005F000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_DEBUG,              0xA0100000,                0xA0100000,                0x00040000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_INFRA2,             0xA0200000,                0xA0200000,                0x00020000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_INFRA3,             0xA1000000,                0xA1000000,                0x00019000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_INFRA4,             0xA1200000,                0xA1200000,                0x00080000,                0x0)
X_REGISTER_REGION_NCNB_CONST(AP_AUDSYS,             0xA2070000,                0xA2070000,                0x00010000,                0x0)
X_REGISTER_REGION_NCNB_CONST(CONNSYS_BT,            0xA8000000,                0xA8000000,                0x01000000,                0x0)
