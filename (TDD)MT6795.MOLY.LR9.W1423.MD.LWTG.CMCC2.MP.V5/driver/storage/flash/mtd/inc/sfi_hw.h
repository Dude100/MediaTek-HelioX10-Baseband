/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 *
 * Filename:
 * ---------
 *	flash_mtd.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Serial flash interface definitions
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _SFI_HW_H
#define _SFI_HW_H

#include "reg_base.h"

//-------------------------------------------------------
// Serial Flash Interface Access Macros
//-------------------------------------------------------

#define SFI_ReadReg8(addr)          *((volatile unsigned char *)(addr))
#define SFI_ReadReg32(addr)         *((volatile unsigned int *)(addr))
#define SFI_WriteReg32(addr, data)  *((volatile unsigned int *)(addr)) = (unsigned int)(data)

//-------------------------------------------------------
// Serial Flash Interface
//-------------------------------------------------------
// MT6251 and MT6252
//-------------------------------------------------------
#if defined(MT6252) || defined(MT6251)
// SFI registers
#define RW_SFI_MAC_CTL              (SFI_base + 0x0000)
#define RW_SFI_MAC_OUTL             (SFI_base + 0x0004)
#define RW_SFI_MAC_INL              (SFI_base + 0x0008)
#define RW_SFI_DIRECT_CTL           (SFI_base + 0x000C)
#define RW_SFI_DLY_CTL              (SFI_base + 0x0014)
#define RW_SFI_MISC_CTL             (SFI_base + 0x0018)
#define RW_SFI_GPRAM_DATA           (SFI_base + 0x0800)
#define RW_SFI_RESET_CTL            (0x83010A28) // PMIC_CHR_CON10

// RW_SF_MAC_CTL
#define SFI_WIP                     (0x00000001)
#define SFI_WIP_READY               (0x00000002)
#define SFI_TRIG                    (0x00000004)
#define SFI_MAC_EN                  (0x00000008)
#define SFI_SYNC_EN                 (0x00000200)
#define SFI_QPI_EN                  (0x00000400)
#define SFI_MAC_SIO_SEL             (0x00000800)
#define SFI_RELEASE_MAC             (0x00080000)   // should enabled by default
#define SFI_DIRECT_WRAP_EN          (0x00020000)
#define SFI_WRAP_ACC_EN             (0x00010000)

// RW_SF_DIRECT_CTL
#define SFI_DR_MODE_MASK            (0x70)
#define SFI_NO_RELOAD               (0x80)
#define SFI_REQ_D1T_EN              (0x00000100)
#define SFI_DEV_MASK                (0xFF000000)
#define SFI_DEV_MOD                 (0x80000000)

// RW_SF_MISC_CTL
#define SFI_DEL_LATCH_MASK          (0x00000080)  // b7
#define SFI_DEL_LATCH_OFFSET        (7)
#define SFI_READ_CMD_MASK           (0x00FF0000)
#define SFI_READ_CMD_OFFSET         (16)
#define SFI_DUMMY_CYC_MASK          (0x0000F000)
#define SFI_DUMMY_CYC_OFFSET        (12)
#define SFI_BOOT_REMAP              (0x200)
#define SFI_REQ_IDLE                (0x00000010)
#define SFI_CS_EXT_MASK             (0xF0000000)

// SFI direct read mode CS_EXT configurations
#define SFI_CS_EXT_4T               (0xA)
#define SFI_CS_EXT_7T               (0x7)
#define SFI_CS_EXT_10T              (0x4)
#define SFI_CS_EXT_12T              (0x2)
#define SFI_CS_EXT_OFFSET           (28)

// Serial flash dummy cycle for fast read in QPI
#define SFI_DUMMY_CYC_QPI_1T        (0x0)
#define SFI_DUMMY_CYC_QPI_2T        (0x3)
#define SFI_DUMMY_CYC_QPI_3T        (0x6)
#define SFI_DUMMY_CYC_QPI_4T        (0x9)
#define SFI_DUMMY_CYC_QPI_5T        (0xC)
#define SFI_DUMMY_CYC_QPI_6T        (0xF)

// Serial flash dummy cycle for fast read in SPI
#define SFI_DUMMY_CYC_SPI_1T        (0x0)
#define SFI_DUMMY_CYC_SPI_2T        (0x1)
#define SFI_DUMMY_CYC_SPI_3T        (0x2)
#define SFI_DUMMY_CYC_SPI_4T        (0x3)
#define SFI_DUMMY_CYC_SPI_5T        (0x4)
#define SFI_DUMMY_CYC_SPI_6T        (0x5)
#define SFI_DUMMY_CYC_SPI_7T        (0x6)
#define SFI_DUMMY_CYC_SPI_8T        (0x7)

// Serial flash direct read mode
#define SFI_DR_SPI_NORMAL_READ_MODE (0x00)  // SPI, < 25MHz
#define SFI_DR_SPI_FAST_READ_MODE   (0x10)  // SPI, 80MHz
#define SFI_DR_QPI_FAST_READ_MODE   (0x70)  // QPI, Quad I/O mode + SF_QPI_EN=1. (quad command + quad address + quad data)

#define SFI_DevMode (SFI_ReadReg32(RW_SFI_MAC_CTL)&SFI_QPI_EN)
#define SFI_SetDevMode(x)  do {	\
	if(x != 0) \
		SFI_WriteReg32(RW_SFI_MAC_CTL, SFI_ReadReg32(RW_SFI_MAC_CTL) | (SFI_QPI_EN) ); \
    else \
		SFI_WriteReg32(RW_SFI_MAC_CTL, SFI_ReadReg32(RW_SFI_MAC_CTL) & (~(SFI_QPI_EN)) ); \
	} while(0)
#define SFI_GetWrapMode (SFI_ReadReg32(RW_SFI_MAC_CTL)& (SFI_DIRECT_WRAP_EN|SFI_WRAP_ACC_EN) )
#define SFI_MaskAhbChannel(...)
// MT6255
//-------------------------------------------------------
#elif defined(MT6255)

// 4 bytes address support
#define __SFI_4BYTES_ADDRESS__

// SFI registers
#define RW_SFI_MAC_CTL              (SFI_base + 0x0000)
#define RW_SFI_DIRECT_CTL           (SFI_base + 0x0004)
#define RW_SFI_MISC_CTL             (SFI_base + 0x0008)
#define RW_SFI_MAC_OUTL             (SFI_base + 0x0010)
#define RW_SFI_MAC_INL              (SFI_base + 0x0014)
#define RW_SFI_RESET_CTL            (SFI_base + 0x0018)
#define RW_SFI_DLY_CTL1             (SFI_base + 0x0020)
#define RW_SFI_DLY_CTL2             (SFI_base + 0x0024)
#define RW_SFI_DLY_CTL3             (SFI_base + 0x0028)
#define RW_SFI_GPRAM_DATA           (SFI_base + 0x0800)

// RW_SF_MAC_CTL
#define SFI_WIP                     (0x00000001)   // b0
#define SFI_WIP_READY               (0x00000002)   // b1
#define SFI_TRIG                    (0x00000004)   // b2
#define SFI_MAC_EN                  (0x00000008)   // b3
#define SFI_MAC_SIO_SEL             (0x00000010)   // b4
#define SFI_RELEASE_MAC             (0x00010000)   // b16

// RW_SF_DIRECT_CTL
#define SFI_QPI_EN                  (0x00000001)  // b0
#define SFI_CMD1_EXTADDR_EN         (0x00000002)  // b1
#define SFI_CMD2_EN                 (0x00000004)  // b2
#define SFI_CMD2_EXTADDR_EN         (0x00000008)  // b3
#define SFI_DR_MODE_MASK            (0x00000070)  // b4~b6
#define SFI_NO_RELOAD               (0x00000080)  // b7
#define SFI_DR_CMD2_DUMMY_CYC_MASK  (0x00000F00)  // b8~b11
#define SFI_DR_CMD1_DUMMY_CYC_MASK  (0x0000F000)  // b12~b15
#define SFI_DR_CMD2_DUMMY_CYC_OFFSET         (8)
#define SFI_DR_CMD1_DUMMY_CYC_OFFSET        (12)

#define SFI_DR_CMD2_MASK            (0x00FF0000)  // b16~b23
#define SFI_DR_CMD1_MASK            (0xFF000000)  // b24~b31
#define SFI_DR_CMD2_OFFSET                  (16)
#define SFI_DR_CMD1_OFFSET                  (24)

// RW_SF_DIRECT_CTL: Serial flash direct read mode
#define SFI_DR_SPI_NORMAL_READ_MODE (0x00000000)
#define SFI_DR_SPI_FAST_READ_MODE   (0x00000010)
#define SFI_DR_QPI_FAST_READ_MODE   (0x00000070)

// RW_SF_MISC_CTL
#define SFI_DEL_LATCH_MASK          (0x00000003)  // b0~02
#define SFI_DEL_LATCH_OFFSET        (0)
#define SFI_REQ_IDLE                (0x00000100)  // b8
#define SFI_BOOT_REMAP              (0x00000200)  // b9
#define SFI_WRAP_ACC_EN             (0x00010000)  // b16
#define SFI_SYNC_EN                 (0x00020000)  // b17
#define SFI_CS_EXT_MASK             (0xF0000000)  // b28~b31


#define SFI_DevMode (SFI_ReadReg32(RW_SFI_DIRECT_CTL)&SFI_QPI_EN)
#define SFI_SetDevMode(x)  do {	\
	if(x != 0) \
		SFI_WriteReg32(RW_SFI_DIRECT_CTL, SFI_ReadReg32(RW_SFI_DIRECT_CTL) | (SFI_QPI_EN) ); \
	else \
		SFI_WriteReg32(RW_SFI_DIRECT_CTL, SFI_ReadReg32(RW_SFI_DIRECT_CTL) & (~(SFI_QPI_EN)) ); \
	} while(0)
#define SFI_GetWrapMode (SFI_ReadReg32(RW_SFI_MISC_CTL)&SFI_WRAP_ACC_EN)
#define SFI_MaskAhbChannel(...)

#elif defined(MT6250) || defined(MT6280)

// 4 bytes address support
#define __SFI_4BYTES_ADDRESS__    

// SFI registers
#define RW_SFI_MAC_CTL              (SFI_base + 0x0000)
#define RW_SFI_DIRECT_CTL           (SFI_base + 0x0004)
#define RW_SFI_MISC_CTL             (SFI_base + 0x0008)
#define RW_SFI_MISC_CTL2            (SFI_base + 0x000C)
#define RW_SFI_MAC_OUTL             (SFI_base + 0x0010)
#define RW_SFI_MAC_INL              (SFI_base + 0x0014)
#define RW_SFI_RESET_CTL            (SFI_base + 0x0018)
#define RW_SFI_STA2_CTL             (SFI_base + 0x001C)
#define RW_SFI_DLY_CTL1             (SFI_base + 0x0020)
#define RW_SFI_DLY_CTL2             (SFI_base + 0x0024)
#define RW_SFI_DLY_CTL3             (SFI_base + 0x0028)
#define RW_SFI_DLY_CTL4             (SFI_base + 0x0030)
#define RW_SFI_DLY_CTL5             (SFI_base + 0x0034)
#define RW_SFI_DLY_CTL6             (SFI_base + 0x0038)
#define RW_SFI_DIRECT_CTL2          (SFI_base + 0x0040)
#define RW_SFI_MISC_CTL3            (SFI_base + 0x0044)
#define RW_SFI_GPRAM_DATA           (SFI_base + 0x0800)


// Performance Monitor
#define SF_PERF_MON1                (SFI_base + 0x0080)
#define SF_PERF_MON2                (SFI_base + 0x0084)
#define SF_PERF_MON3                (SFI_base + 0x0088)
#define SF_PERF_MON4                (SFI_base + 0x008C)
#define SF_PERF_MON5                (SFI_base + 0x0090)
#define SF_PERF_MON6                (SFI_base + 0x0094)
#define SF_PERF_MON7                (SFI_base + 0x0098)
#define SF_PERF_MON8                (SFI_base + 0x009C)
#define SF_PERF_MON9                (SFI_base + 0x00A0)
#define SF_PERF_MON10               (SFI_base + 0x00A4)
#define SF_PERF_MON11               (SFI_base + 0x00A8)
#define SF_PERF_MON12               (SFI_base + 0x00AC)
#define SF_PERF_MON13               (SFI_base + 0x00B0)

// RW_SF_MAC_CTL
#define SFI_WIP                     (0x00000001)   // b0
#define SFI_WIP_READY               (0x00000002)   // b1
#define SFI_TRIG                    (0x00000004)   // b2
#define SFI_MAC_EN                  (0x00000008)   // b3
#define SFI_MAC_SIO_SEL             (0x00000010)   // b4
#define SFI_RELEASE_MAC             (0x00010000)   // b16
#define SFI_MAC_SEL                 (0x10000000)   // b28

// RW_SF_DIRECT_CTL
#define SFI_QPI_EN                  (0x00000001)  // b0
#define SFI_CMD1_EXTADDR_EN         (0x00000002)  // b1
#define SFI_CMD2_EN                 (0x00000004)  // b2
#define SFI_CMD2_EXTADDR_EN         (0x00000008)  // b3
#define SFI_DR_MODE_MASK            (0x00000070)  // b4~b6
#define SFI_DR_CMD2_DUMMY_CYC_MASK  (0x00000F00)  // b8~b11
#define SFI_DR_CMD1_DUMMY_CYC_MASK  (0x0000F000)  // b12~b15
#define SFI_DR_CMD2_DUMMY_CYC_OFFSET         (8)
#define SFI_DR_CMD1_DUMMY_CYC_OFFSET        (12)

#define SFI_DR_CMD2_MASK            (0x00FF0000)  // b16~b23
#define SFI_DR_CMD1_MASK            (0xFF000000)  // b24~b31
#define SFI_DR_CMD2_OFFSET                  (16)
#define SFI_DR_CMD1_OFFSET                  (24)

// RW_SF_DIRECT_CTL: Serial flash direct read mode
#define SFI_DR_SPI_NORMAL_READ_MODE (0x00000000)
#define SFI_DR_SPI_FAST_READ_MODE   (0x00000010)
#define SFI_DR_QPI_FAST_READ_MODE   (0x00000070)

// RW_SF_MISC_CTL
#define SFI_DEL_LATCH_MASK          (0x00000003)  // b0~01
#define SFI_DEL_LATCH_OFFSET        (0)
#define SFI_REQ_IDLE                (0x00000100)  // b8
#define SFI_BOOT_REMAP              (0x00000200)  // b9
#define SFI_SYNC_EN                 (0x00020000)  // b17
#define SFI_NO_RELOAD               (0x00800000)  // b23
#define SFI_CS_EXT_MASK             (0xF0000000)  // b28~b31

// RW_SF_MISC_CTL2
#define SFI_WRAP_ACC_EN             (0x00000001)  // b0
#define SFI_DDR                     (0x00000002)  // b1

// RW_SF_MISC_CTL3
#define SFI_DEL_LATCH_MASK2         (0x00030000)  // b16~017
#define SFI_DEL_LATCH_OFFSET2       (16)
#define SFI_SF2_EN                  (0x00000001)    // b0
#define SFI_SF1_SIZE_MASK           (0x00000070)    // b4~6
#define SFI_SF1_SIZE_OFFSET         (4)             // b4~6
#define SFI_CH1_TRANS_MASK          (0x00000100)    // b8
#define SFI_CH2_TRANS_MASK          (0x00000200)    // b9
#define SFI_CH3_TRANS_MASK          (0x00000400)    // b10
#define SFI_CH1_TRANS_IDLE          (0x00001000)    // b12
#define SFI_CH2_TRANS_IDLE          (0x00002000)    // b13
#define SFI_CH3_TRANS_IDLE          (0x00004000)    // b14

// RW_SF_STA2_CTL
#define SFI_KEEP_READ_SETTING       (0x80000000)  // b31


#define SFI_DevMode (SFI_ReadReg32(RW_SFI_DIRECT_CTL)&SFI_QPI_EN)
#define SFI_SetDevMode(x)  do {	\
	if(x != 0) \
		SFI_WriteReg32(RW_SFI_DIRECT_CTL, SFI_ReadReg32(RW_SFI_DIRECT_CTL) | (SFI_QPI_EN) ); \
	else \
		SFI_WriteReg32(RW_SFI_DIRECT_CTL, SFI_ReadReg32(RW_SFI_DIRECT_CTL) & (~(SFI_QPI_EN)) ); \
	} while(0)
#define SFI_GetWrapMode (SFI_ReadReg32(RW_SFI_MISC_CTL2)&SFI_WRAP_ACC_EN)
//Only for MT6250
#if defined(MT6250) && !defined(__UBL__) // Bootloader should not toggle Code compressor
#define SFI_MaskAhbChannel(x)  do {	\
	if(x != 0) \
		SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3) | (SFI_CH2_TRANS_MASK|SFI_CH3_TRANS_MASK) ); \
	else \
		SFI_WriteReg32(RW_SFI_MISC_CTL3, SFI_ReadReg32(RW_SFI_MISC_CTL3) & (~(SFI_CH2_TRANS_MASK|SFI_CH3_TRANS_MASK)) ); \
	} while(0)
#else
#define SFI_MaskAhbChannel(...)
#endif


#endif /*  defined(MT6252) || defined(MT6251) */


#endif /* _SFI_HW_H */
