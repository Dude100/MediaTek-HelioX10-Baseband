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
 *   bl_drv_common.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Driver common header file
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
 * .
 ****************************************************************************/

#ifndef _BL_DRV_COMMON_H
#define _BL_DRV_COMMON_H

#include "kal_general_types.h"

#ifndef DRV_WriteReg
#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#endif

#ifndef DRV_Reg
#define DRV_Reg(addr)                (*(volatile kal_uint16 *)(addr))
#endif

#ifndef DRV_SetReg
#define DRV_SetReg(addr, data)      (DRV_WriteReg(addr, DRV_Reg(addr)|(data)))
#endif

#ifndef DRV_ClrReg
#define DRV_ClrReg(addr, data)      (DRV_WriteReg(addr, DRV_Reg(addr)&~(data)))
#endif

#ifndef DRV_WriteReg32
#define DRV_WriteReg32(addr,data)   ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#endif

#ifndef DRV_Reg32
#define DRV_Reg32(addr)              (*(volatile kal_uint32 *)(addr))
#endif

#ifndef DRV_SetReg32
#define DRV_SetReg32(addr, data)    (DRV_WriteReg32(addr, DRV_Reg32(addr)|(data)))
#endif

#ifndef DRV_ClrReg32
#define DRV_ClrReg32(addr, data)    (DRV_WriteReg32(addr, DRV_Reg32(addr)&~(data)))
#endif

#ifndef DRV_WriteReg8
#define DRV_WriteReg8(addr,data)    ((*(volatile kal_uint8 *) (addr)) = (kal_uint8)(data))
#endif

#ifndef DRV_Reg8
#define DRV_Reg8(addr)               (*(volatile kal_uint8 *) (addr))
#endif

#ifndef DRV_SetReg8
#define DRV_SetReg8(addr, data)     (DRV_WriteReg8(addr, DRV_Reg8(addr)|(data)))
#endif

#ifndef DRV_ClrReg8
#define DRV_ClrReg8(addr, data)     (DRV_WriteReg8(addr, DRV_Reg8(addr)&~(data)))
#endif

// TODO: check DRV_WriteReg32_NPW and DRV_WriteReg32_NPW have been defined
/* DRV_WriteReg32_NPW, DRV_WriteReg32_NPW_RB provide non-post-write operation
   Abbreviation:
       NPW: Non Post Write
       RB : Read Back
   Description:
       1. DRV_WriteReg32_NPW: In System with strongly order memory attribute
          (write response from target hardware IP), we just write the data
          into the strongly order region (write_addr | 0xF000_0000)
       2. DRV_WriteReg32_NPW: In System without strongly order memory atribute,
          we write the data into the write_addr and read the write_addr
          back to avoid the write data is buffered in bus fabric
       3. DRV_WriteReg32_NPW_RB: In some hardware IP design, reading the 
          write_addr has some side-effects, in order to avoid this situation, 
          DRV_WriteReg32_NPW_RB is provided and the read_addr of 
          DRV_WriteReg32_NPW_RB is assigned by the user.
          User must confirm that all previous write operations are finished 
          before the data of read_addr ready.
          For example, write_addr in IP-A, read_addr in IP-B can't make sure the
          IP-A write operation is finished. write_addr/read_addr must be in the 
          same IP.
       4. DRV_WriteReg32_NPW_RB: For system with strongly order memory
          attribute, DRV_WriteReg32_NPW_RB does NOT read the read_addr
          (the same behavior with DRV_WriteReg32_NPW).
       5. Memory barrier operations (DMB/DSB in ARM Arch.) are not included in 
          DRV_WriteReg32_NPW_RB and DRV_WriteReg32_NPW.
 */

#ifndef  DRV_WriteReg32_NPW_RB
#define DRV_WriteReg32_NPW_RB(write_addr, data, read_addr)         \
    DRV_WriteReg32(((kal_uint32)(write_addr))|0xF0000000, data);
#endif

#ifndef DRV_WriteReg32_NPW
#define DRV_WriteReg32_NPW(write_addr, data)                       \
    DRV_WriteReg32(((kal_uint32)(write_addr))|0xF0000000, data)
#endif

#ifndef DRV_SetReg32_NPW
#define DRV_SetReg32_NPW(write_addr, data)  \
    DRV_WriteReg32(((kal_uint32)(write_addr))|0xF0000000, DRV_Reg32(write_addr) | (data))
#endif

#ifndef DRV_ClrReg32_NPW
#define DRV_ClrReg32_NPW(write_addr, data)  \
    DRV_WriteReg32(((kal_uint32)(write_addr))|0xF0000000, DRV_Reg32(write_addr) & (~(data)))
#endif

#endif /* _BL_DRV_COMMON_H */
