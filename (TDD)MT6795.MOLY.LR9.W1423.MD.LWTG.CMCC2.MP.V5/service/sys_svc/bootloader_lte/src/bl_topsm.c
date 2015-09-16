/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   bl_topsm.c
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   TOPSM driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
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
 * .
 ****************************************************************************/

#include "kal_general_types.h"
#include "bl_GPT.h"
#include "bl_drv_common.h"
#include "reg_base.h"

#define REG_APTOPSM_DUMMY(n)                    (BASE_ADDR_APTOPSM+0xC00+(n)*4)
#define REG_APTOPSM_RM_PWR0_CON            (BASE_ADDR_APTOPSM+0x800)
#define REG_APTOPSM_DBG                             (BASE_ADDR_APTOPSM+0x50)
#define REG_MDTOPSM_DBG                             (BASE_ADDR_MDTOPSM+0x50)


void bl_topsm_init()
{
    //Clear request to avoid ICE attaching issue
    DRV_WriteReg32(REG_MDTOPSM_DBG, 0);
    DRV_WriteReg32(REG_APTOPSM_DBG, 0);
}

void bl_topsm_power_on_ap()
{
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000600FE);
    BL_GPT_UDELAY(2);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000600F6);
    BL_GPT_UDELAY(2);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00F6);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00E6);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00E4);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00D4);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00D5);
    DRV_WriteReg32(REG_APTOPSM_RM_PWR0_CON, 0x000E00C5);    
}

void bl_topsm_set_retention(kal_uint32 data, kal_uint32 reg_num)
{
    DRV_WriteReg32(REG_APTOPSM_DUMMY(reg_num), data);
}

void bl_topsm_get_retention(kal_uint32 *data, kal_uint32 reg_num)
{
    *data = DRV_Reg32(REG_APTOPSM_DUMMY(reg_num));
}
