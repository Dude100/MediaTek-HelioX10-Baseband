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
 *   This is a flash MTD driver header file
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef _FLASH_SF_H
#define _FLASH_SF_H

#ifdef __SF_DVT__
#include "flash_mtd_sf_dvt.h"
#else
#include "kal_general_types.h"
#endif
#include "sfi_hw.h"

/*-------------------------------------------------------
 *          Serial Flash Device Parameters
 *-------------------------------------------------------*/

// Parameters
#define SF_MAX_PAGE_PROG_SIZE   (256)
#define SF_ADDRESS_MASK         (0x07FFFFFF)

typedef enum {
    SF_SR_BUSY  = 0
   ,SF_SR_WEL
   ,SF_SR_WSE
   ,SF_SR_WSP
   ,SF_SR_BP
   ,SF_SR_SRWD
   ,SF_SR_OTPLOCK
   ,SF_SR_FAIL
   ,SF_SR_COUNT     // Number of SR map entries
} SF_Status_Enum;

typedef enum {
    SF_SST_SR_WEL          = 0x02      // Write Enable Latch
   ,SF_SST_SR_WSE          = 0x04      // Write Suspend Erase Status
   ,SF_SST_SR_WSP          = 0x08      // Write Suspend Program Status
   ,SF_SST_SR_WPLD         = 0x10      // Write Protection Lockdown Status (Resets to 0 after a power cycle)
   ,SF_SST_SR_SEC          = 0x20      // Security ID status (Once set by Lock Security ID (0x85h) it can not be reset)
   ,SF_SST_SR_BUSY         = 0x80      // Write operation status (Write In Progress Bit)
   ,SF_SST_SR_ALL          = 0xFF
} SF_SST_Status_Indication_Enum;

typedef enum {
    SF_MXIC_SR_BUSY        = 0x01      // Write operation status (Write In Progress Bit)
   ,SF_MXIC_SR_WEL         = 0x02      // Write Enable Latch
   ,SF_MXIC_SR_WSE         = 0x08      // Write Suspend Erase Status (in security register)
   ,SF_MXIC_SR_WSP         = 0x04      // Write Suspend Program Status (in security register)
   ,SF_MXIC_SR_BP          = 0x3C      // Block protection (MXIC only)
   ,SF_MXIC_SR_SRWD        = 0x80      // Status register write disable (MXIC only)
   ,SF_MXIC_SR_ALL         = 0xFF
} SF_MXIC_Status_Indication_Enum;

typedef enum {
    SF_MXIC_SSR_OTP        = 0x01
   ,SF_MXIC_SSR_LDSO       = 0x02
   ,SF_MXIC_SSR_WSP        = 0x04
   ,SF_MXIC_SSR_WSE        = 0x08
   ,SF_MXIC_SSR_PFAIL      = 0x20
   ,SF_MXIC_SSR_EFAIL      = 0x40
   ,SF_MXIC_SSR_WPSEL      = 0x80
} SF_MXIC_Security_Indication_Enum;

typedef enum {
    SF_EON_SSR_WSE         = 0x04
   ,SF_EON_SSR_WSP         = 0x08
} SF_EON_Suspend_Indication_Enum;

typedef enum {
    SF_WINBOND_SSR_SUS     = 0x80
   ,SF_WINBOND_SSR_OTP     = 0x3C       //Security register lock bits (LB0, LB1, LB2, LB3)
} SF_WINBOND_Suspend_Indication_Enum;

typedef enum {
    SF_NUMONYX_SSR_WSP     = 0x04
   ,SF_NUMONYX_SSR_WSE     = 0x40
} SF_NUMONYX_Suspend_Indication_Enum;

typedef enum {
    SF_UNDEF = 0
   ,SPI      = 1
   ,SPIQ     = 2
   ,QPI      = 3
} SF_MODE_Enum;

typedef kal_uint8 SF_Status;

/*-------------------------------------------------------
 *             Serial Flash Device Commands
 *-------------------------------------------------------*/

// Serial Flash commands (General for SPI)
#define SF_CMD_WRITE_SR     (0x01)
#define SF_CMD_PAGE_PROG    (0x02)
#define SF_CMD_READ         (0x03)
#define SF_CMD_NORMAL_READ  (0x00030000)  // for direct mode usage
#define SF_CMD_READ_SR      (0x05)
#define SF_CMD_WREN         (0x06)
#define SF_CMD_FAST_READ    (0x000B0000)  // for direct mode usage
#define SF_CMD_RESUME       (0x30)
#define SF_CMD_WBPR         (0x42)
#define SF_CMD_RSTEN        (0x66)
#define SF_CMD_RBPR         (0x72)
#define SF_CMD_RST          (0x99)
#define SF_CMD_SUSPEND      (0xB0)
#define SF_CMD_ERASE_CHIP   (0xC7)
#define SF_CMD_ERASE_BLOCK  (0xD8)
#define SF_CMD_ERASE_SMALL_BLOCK (0x52)
#define SF_CMD_ERASE_SECTOR (0x20)
#define SF_CMD_READ_ID      (0x9F)

// Serial Flash commands (General for QPI)
#define SF_CMD_READ_ID_QPI  (0xAF)

// Serial Flash commands (SST specific)
#define SF_CMD_SST_QPIEN                    (0x38)        // for SST only
#define SF_CMD_SST_QPIRST                   (0xFF)
#define SF_CMD_SST_SET_BURST_LENGTH         (0xC0)
#define SF_CMD_SST_BURST_LENGTH_32_BYTE     (0x02)
#define SF_CMD_SST_FAST_READ                (0x0B)
#define SF_CMD_SST_FAST_READ_WRAP           (0x0C)
#define SF_CMD_SST_READ_SECURITY_ID         (0x88)    // SST: Read OTP registers
#define SF_CMD_SST_PROG_SECURITY_ID         (0xA5)    // SST: Program OTP registers
#define SF_CMD_SST_LOCK_SECURITY_ID         (0x85)    // SST: Lock OTP registers


// Serial Flash commands (MXIC specific)
#define SF_CMD_MXIC_QPIEN                   (0x35)
#define SF_CMD_MXIC_RSTQPI                  (0xF5)
#define SF_CMD_MXIC_READ_SEC_SR             (0x2B)  // OTP Read status
#define SF_CMD_MXIC_WRITE_SEC_SR            (0x2F)  // OTP write status
#define SF_CMD_MXIC_SET_BURST_LENGTH        (0xC0)
#define SF_CMD_MXIC_BURST_LENGTH_32_BYTE    (0x02)
#define SF_CMD_MXIC_BURST_LENGTH_DISABLE    (0x10)
#define SF_CMD_MXIC_FAST_READ_WRAP          (0x0B)  // for direct mode usage
#define SF_CMD_MXIC_FAST_READ_ENH           (0xEB)  // for direct mode usage
#define SF_CMD_MXIC_ENTER_SECURED_OTP       (0xB1)  // Enter OTP Access
#define SF_CMD_MXIC_EXIT_SECURED_OTP        (0xC1)  // Exit OTP Access

// Serial Flash commands (EON specific)
#define SF_CMD_EON_READ_SUSPEND_SR          (0x09)  // Suspend status register

// Serial Flash commands (WINBOND specific)
#define SF_CMD_WINBOND_READ_SUSPEND_SR      (0x35)  // Suspend status register
#define SF_CMD_WINBOND_SUSPEND              (0x75)  // Suspend
#define SF_CMD_WINBOND_RESUME               (0x7A)  // Resume
#define SF_CMD_WINBOND_READ_SECURITY_REG    (0x48)  // Winbond: Read OTP registers
#define SF_CMD_WINBOND_PROG_SECURITY_REG    (0x42)  // Winbond: Program OTP registers
#define SF_CMD_WINBOND_READ_UNIQUE_ID       (0x4B)  // Read unique ID number (4 dummy bytes)

// Serial Flash commands (NUMONYX specific)
#define SF_CMD_NUMONYX_READ_FLAG_SR         (0x70)  // Numonyx: Read flag status register
#define SF_CMD_NUMONYX_WRITE_FLAG_SR        (0x50)  // Numonyx: Write flag status register
#define SF_CMD_NUMONYX_READ_LOCK_SR         (0xE8)  // Numonyx: Read lock status register
#define SF_CMD_NUMONYX_WRITE_LOCK_SR        (0xE5)  // Numonyx: Write lock status register
#define SF_CMD_NUMONYX_READ_CONFIG_SR       (0x85)  // Numonyx: Read volatile config status register
#define SF_CMD_NUMONYX_WRITE_CONFIG_SR      (0x81)  // Numonyx: Write volatile config status register

// Serial Flash commands (GIGADEVICE specific)
#define SF_CMD_GIGADEVICE_HPM_ENTER         (0xA3000000)  // GIGA Device: Enter high performance mode + 3 dummy
#define SF_CMD_GIGADEVICE_HPM_ENTER_CMD     (0xA3)        // GIGA Device: Enter high performance mode cmd
#define SF_CMD_GIGADEVICE_HPM_EXIT          (0xAB)        // GIGA Device: Exit high performance mode

// Serial flash device characteriscs
#define SF_WRAP_ENABLE                       (1)      // wrap burst read should be enabled by default
#define SF_FLASH_ID_LENGTH                   (3)      // The number of bytes for flash ID



/*-------------------------------------------------------
 *              Serial Flash Common APIs
 *        API Body is in "flash_mtd_sf_common.c"
 *-------------------------------------------------------*/
extern void         SFI_BlankCheck(void *MTDData, kal_uint32 BlockIndex);
extern void         SFI_MacEnable(void);
extern void         SFI_MacWaitReady(void);
extern kal_uint32   SFI_ReverseByteOrder(kal_uint32 num);
extern void         SFI_ReadDeviceID(kal_uint8 *id, kal_uint8 cmd);
extern void         SFI_ReadDeviceID_SPI(kal_uint8 *id);
// Device Command functions
extern void         SFI_Dev_Command(const kal_uint32 cmd);
extern void         SFI_Dev_CommandAddress(const kal_uint8 cmd, const kal_uint32 address, const kal_uint32 address_bytes);
extern void         SFI_Dev_Command_List(const kal_uint8 *cmdlist);
extern void         SFI_Dev_Command_Ext(const kal_uint8 *cmd, kal_uint8 *data, const kal_uint16 outl, const kal_uint16 inl);
extern kal_bool     SFI_Dev_SupportUpHopping(void);
extern kal_bool     SFI_Dev_IsModemTimingRecoveryRequired(void);
extern void         SFI_Dev_SupportDelayResume(kal_bool flag);
// GPRAM access functions
extern void         SFI_GPRAM_Write(kal_uint32 gpram_offset, void* buff, kal_int32 length);
extern kal_uint32   SFI_GPRAM_Write_C1A3(const kal_uint32 cmd, const kal_uint32 address);
extern kal_uint32   SFI_GPRAM_Write_C1A4(const kal_uint32 cmd, const kal_uint32 address, kal_uint8 **p_data, kal_uint32 *length);

#endif /* _FLASH_SF_H */

