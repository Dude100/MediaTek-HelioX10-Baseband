/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   bl_efuse.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Efuse driver
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 *
 ****************************************************************************/
#include <reg_base.h>
#include "kal_general_types.h"
#include "bl_drv_common.h"

#define REG_EFUSE_READ_DATA(n)      (BASE_ADDR_EFUSE+0x20+(n)*4)
#define EFUSE_MACRO_HW              (5)
#define EFUSE_MACRO_USB_PIDVID      (18)

#define EFUSE_LEAKAGE_BITS_1          (27)
#define EFUSE_LEAKAGE_BITS_2          (28)
#define EFUSE_EXT_PWR_FLOW_BIT        (29)

void bl_efuse_get_usb_pidvid(kal_uint16 *pid, kal_uint16* vid)
{
    kal_uint32 data;

    data = DRV_Reg32(REG_EFUSE_READ_DATA(EFUSE_MACRO_USB_PIDVID));

    *vid = data & 0xFFFF; //efuse LSB 16bit is VID
    *pid = ((data >> 16) & 0xFFFF); //efuse MSB 16bit is PID
}

kal_uint8 bl_efuse_get_leakage()
{
    kal_uint32 data;

    data = DRV_Reg32(REG_EFUSE_READ_DATA(EFUSE_MACRO_HW));
	
	return (data & ((1 << EFUSE_LEAKAGE_BITS_1)|(1 << EFUSE_LEAKAGE_BITS_2)) ) >>  EFUSE_LEAKAGE_BITS_1;
}

kal_uint8 bl_efuse_get_ext_pwr_flow()
{
    kal_uint32 data;

    data = DRV_Reg32(REG_EFUSE_READ_DATA(EFUSE_MACRO_HW));
	
	return (data & (1 << EFUSE_EXT_PWR_FLOW_BIT)) >> EFUSE_EXT_PWR_FLOW_BIT;
}

