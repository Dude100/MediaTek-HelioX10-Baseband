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
 *   flash_cfi.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This module implements Common Flash Interface Query for NOR Flash Memory.
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *============================================================================
 ****************************************************************************/

#ifndef __FLASH_CFI_INTERNAL_H
#define __FLASH_CFI_INTERNAL_H

#include "kal_general_types.h"
//-----------------------------------------------------------------------------
// Internal Functions / Predefines
//-----------------------------------------------------------------------------
#define CFI_QRYSTR     0x00595251 // ASCII 'Q', 'R', 'Y'
#define CFI_PRISTR     0x00495250 // ASCII 'P', 'R', 'I'
#define CFI_ALTSTR     0x00544C41 // ASCII 'A', 'L', 'T'

#define CFI_MILVOLT(x)   ((x) & 0x0F)
#define CFI_VOLT(x)      (((x) & 0xF0) >> 4)
#define CFI_BYTE(x)      ((x) & 0xFF)
#define CFI_WORD(a)      (a[1] << 8 | a[0])
#define CFI_DWORD(a)     (a[3] << 24 | a[2] << 16 | a[1] << 8 | a[0])
#define CFI_EXP2(x)      (1 << (x))

#define CFI_TEXT_BUFF_SIZE 100  // Size of text buffer for error messges (bytes)

//-----------------------------------------------------------------------------
// CFI ID Codes: Command Set (JEDEC JEP137B)
//-----------------------------------------------------------------------------
typedef enum {
    CFI_ALG_NONE          = 0x0000,  // None
    CFI_ALG_IntelSharpExt = 0x0001,  // Intel/Sharp Extemded Command Set
    CFI_ALG_AMDFujitsu    = 0x0002,  // AMD/Fujitsu Standard Command Set
    CFI_ALG_Intel         = 0x0003,  // Intel Standard Command Set
    CFI_ALG_AMDFujitsuExt = 0x0004,  // AMD/Fujitsu Extended Command Set
    CFI_ALG_Winbond       = 0x0006,  // Winbond Standard Command Set
    CFI_ALG_Mitsubishi    = 0x0100,  // Mistubishi Standard Command Set
    CFI_ALG_MitsubishiExt = 0x0101,  // Mistubishi Extended Command Set
    CFI_ALG_SST           = 0x0102,  // SST Page Write Command Set
    CFI_ALG_Intel_Perform = 0x0200,  // Intel Performance Code Command
    CFI_ALG_Intel_Data    = 0x0210,  // Intel Data Command Set
    CFI_ALG_NA            = 0xFFFF   // Not Allowed
} Enum_CFI_ALG;

//-----------------------------------------------------------------------------
// CFI ID Codes: Device Assignments (JEDEC JEP137B)
//-----------------------------------------------------------------------------
typedef enum {
    CFI_INT_X8     = 0x0000, // x8-only asynchronous interface
    CFI_INT_X16    = 0x0001, // x16-only asynchronous interface
    CFI_INT_X8X16  = 0x0002, // Supports x8/x16 via BYTE# with asynchronous interface
    CFI_INT_X32    = 0x0003, // x32-only asynchronous interface
    CFI_INT_X16X32 = 0x0004, // Supports x16/x32 via WORD# with asynchronous interface
    CFI_INT_NA     = 0xFFFF  // Not Allowed
} Enum_CFI_INT;

//-----------------------------------------------------------------------------
// Standard CFI Command Codes / Base Addr
//-----------------------------------------------------------------------------
#define CFI_BASE_ADDR  0x0010     // CFI mode data address
#define CFI_CMD_ADDR   0x0055     // CFI command address
#define CFI_CMD_ENTR   0x0098     // Enter CFI mode
#define CFI_CMD_EXIT1  0x00FF     // Leave CFI mode (Intel/Sibley)
#define CFI_CMD_EXIT2  0x00F0     // Leave CFI mode (AMD/Toshiba)

//-----------------------------------------------------------------------------
// Read ID Command Codes
//-----------------------------------------------------------------------------
#define CFI_RDID_UNLOCK_ADR1 0x555
#define CFI_RDID_UNLOCK_DAT1 0xAA
#define CFI_RDID_UNLOCK_ADR2 0x2AA
#define CFI_RDID_UNLOCK_DAT2 0x55
#define CFI_RDID_ADR         0x555
#define CFI_RDID_CMD         0x90

//-----------------------------------------------------------------------------
// Standard CFI Query
//-----------------------------------------------------------------------------
typedef enum {
    CFI_QRY    = 0x010, // 10h: Query unique ASCII string "QRY"
    CFI_PRIALG = 0x013, // 13h: Primary algorithm
    CFI_PRIEXT = 0x015, // 15h: Offset to the Primary algorithm extended query
    CFI_ALTALG = 0x017, // 17h: Alternative algorithm
    CFI_ALTEXT = 0x019, // 19h: Offset to the Alternative algorithm extended query
    // CFI Device System Interface  (1Bh)
    CFI_VCCMIN = 0x01B, // 1Bh: Vcc Logic Supply Minimum Voltage, bits 7~4: BCD in vlots, bits 3~0: BCD in 100 millivolts
    CFI_VCCMAX = 0x01C, // 1Ch: Vcc Logic Supply Maximum Voltage, bits 7~4: BCD in vlots, bits 3~0: BCD in 100 millivolts
    CFI_VPPMIN = 0x01D, // 1Dh: Vpp Supply Minimum Voltage (Factory Mode), bits 7~4: HEX in vlots, bits 3~0: BCD in 100 millivolts
    CFI_VPPMAX = 0x01E, // 1Eh: Vpp Supply Maximum Voltage (Factory Mode), bits 7~4: HEX in vlots, bits 3~0: BCD in 100 millivolts
    CFI_WPRGTT = 0x01F, // 1Fh: Typical timeout per single byte/word/D-word program, 2^N us
    CFI_BPRGTT = 0x020, // 20h: Typical timeout for maximum-size multi-byte program 2^N us, 0=not supported
    CFI_BLKETT = 0x021, // 21h: Typical timeout per individual block erase, 2^N ms
    CFI_CHPETT = 0x022, // 22h: Typical timeout for full chip erase
    CFI_WPRGMT = 0x023, // 23h: Maximum timeout per single byte/word/D-word program, 2^N us
    CFI_BPRGMT = 0x024, // 24h: Maximum timeout for maximum-size multi-byte program 2^N us, 0=not supported
    CFI_BLKEMT = 0x025, // 25h: Maximum timeout per individual block erase, 2^N ms
    CFI_CHPEMT = 0x026, // 26h: Maximum timeout for full chip erase
    CFI_SIZE   = 0x027, // 27h: Device Size: 2^N bytes
    CFI_DEVINT = 0x028, // 28h: Device interface
    CFI_WBSIZE = 0x02A, // 2Ah: Maximum number of bytes in multi-byte program
    CFI_REGCNT = 0x02C, // 2Ch: Number of Erase Block Regions within the device
    CFI_REGINF = 0x02D  // 2Dh: Erase Block Region Information
} Enum_CFI;

//-----------------------------------------------------------------------------
// Extended CFI Query
//-----------------------------------------------------------------------------
typedef enum {
    CFI_EXTQRY  = 0x000, // P+00h: Query unique ASCII string "PRI"
    CFI_EXTVER1 = 0x003, // P+03h: Major version number, ASCII
    CFI_EXTVER2 = 0x004  // P+04h: Minor version number, ASCII
} Enum_CFI_EXT;


// AMD
typedef enum {
    CFI_AMD_BOOTFLAG = 0x000F, // P+0Fh: boot flag, 02=bottom, 03=top boot
    CFI_AMD_BNKCNT = 0x017,    // P+17h: Bank organization, number of banks
    CFI_AMD_BNKINF = 0x018     // P+18h ~ : Bank Region Information (number of sectors in each bank)
} Enum_CFI_AMD;

// Numonyx
typedef enum {
    CFI_NUMONYX_BNKCNT = 0x022, // P+22h: Number of device hardware prtition regions
    CFI_NUMONYX_REGINF = 0x023  // P+23h: Region Info Start
} Enum_CFI_NUMONYX;

#ifndef FLASH_CELL
    typedef kal_uint16 FLASH_CELL;
#endif // FLASH_CELL

//-----------------------------------------------------------------------------
// Exported CFI Geometry Infomation
//-----------------------------------------------------------------------------
#define CFI_FLASH_ID_LENGTH   4
#define CFI_REGIONINFO_SIZE  16   // Maximum entries in Region Info
#define CFI_BANKINFO_SIZE     8   // Maximum entries in Bank Info
#define CFI_BLOCKINFO_SIZE   16   // Maximum entries in Block Info

// Basetype of RegionInfo and BankInfo
typedef struct MEM_DEV_GEOMETRY
{
    kal_uint32  Size;
    kal_uint16  Count;
} MEM_DEV_GEOMETRY_T;

typedef struct MEM_DEV_BLOCK
{
    kal_uint32  Offset;
    kal_uint32  Size;
} MEM_DEV_BLOCK_T;

// CFI Geometry info structure
// The structure is used by CFI_QueryGeometry(), used by .\mcu\init\info.c in Engineer Mode
typedef struct MEM_DEV_CFI_STRUCT
{
    kal_uint16          FlashID[CFI_FLASH_ID_LENGTH];     // Flash ID (0x90)
    kal_uint32          Size;           // Size of NOR flash in bytes
    kal_uint16          CommandSet;     // Primary Algorithm Code (refer to CFI spec.)
    kal_uint8           RegionCount;    // Number of Regions
    kal_uint8           BankCount;      // Number of Banks
    kal_uint16          TotalBlocks;        // Number of Blocks (of all sizes)
    kal_uint16          ProgramBufferSize;  // Size of Page Program Buffer (i.e maximum program length of bytes at a time)
    MEM_DEV_GEOMETRY_T  RegionInfo[CFI_REGIONINFO_SIZE];  // Region Info, in format of {region size, region count}
    MEM_DEV_GEOMETRY_T  BankInfo[CFI_BANKINFO_SIZE];      // Bank Info, in format of {bank size, bank count}
    MEM_DEV_BLOCK_T     BlockInfo[CFI_BLOCKINFO_SIZE];    // Block Info, in format of {offset, block size}
    MEM_DEV_GEOMETRY_T  FAT_RegionInfo[CFI_REGIONINFO_SIZE];  // Region Info, in format of {region size, region count}
    MEM_DEV_GEOMETRY_T  FAT_BankInfo[CFI_BANKINFO_SIZE];      // Bank Info, in format of {bank size, bank count}

    kal_int8            CheckResults;   // Check Results
    kal_uint32          CheckData1;
    kal_uint32          CheckData2;
} MEM_DEV_CFI_T;

// CFI Query Error Codes
typedef enum {
    CFIErr_NoError=0,
    CFIErr_FATBeginUnalign,
    CFIErr_FATEndUnalign,
    CFIErr_FATSizeExceed,
    CFIErr_ProgBufExceed,
    CFIErr_NotAvailable,
    CFIErr_RegionInfoError,
    CFIErr_RegionInfoBlkCnt,
    CFIErr_RegionInfoBlkSize,
    CFIErr_BankInfoBnkCnt,
    CFIErr_BankInfoBnkSize,
    CFIErr_Count
} Enum_CFIErrCode;

//-----------------------------------------------------------------------------
// Function Prototypes
//-----------------------------------------------------------------------------
// Main Funtion
void CFI_NOR_Main(void);

// General functions
kal_int32 CFI_Query(volatile FLASH_CELL *BaseAddr, kal_uint16 offset, kal_uint8 length);
kal_int32 CFI_QueryAll(volatile FLASH_CELL *BaseAddr);
void CFI_DumpInfo(MEM_DEV_CFI_T *CFIInfo);

// Reserved For EM
kal_int32 CFI_QueryGeometry(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo);
kal_int32 CFI_CheckSettings(MEM_DEV_CFI_T *CFIInfo);
char *CFI_GetErrorMessage(MEM_DEV_CFI_T *CFIInfo, char *str, int len);
const char *CFI_GetCommandSetName(kal_uint16 id);
void NOR_ReadID(volatile FLASH_CELL *BaseAddr, kal_uint16 *flashid);
kal_int32 CFI_ReadID(volatile FLASH_CELL *BaseAddr, MEM_DEV_CFI_T *CFIInfo);

//-----------------------------------------------------------------------------
// Exported Macros
//-----------------------------------------------------------------------------
#define CFI_NOR_BASE$ ((volatile FLASH_CELL *)(custom_get_NORFLASH_Base()+custom_get_fat_addr()))

#define CFI_QRY$     CFI_Query(CFI_NOR_BASE$, CFI_QRY,    3)
#define CFI_PRIALG$  CFI_Query(CFI_NOR_BASE$, CFI_PRIALG, 2)
#define CFI_PRIEXT$  CFI_Query(CFI_NOR_BASE$, CFI_PRIEXT, 2)
#define CFI_ALTALG$  CFI_Query(CFI_NOR_BASE$, CFI_ALTALG, 2)
#define CFI_ALTEXT$  CFI_Query(CFI_NOR_BASE$, CFI_ALTEXT, 2)
#define CFI_DEVINT$  CFI_Query(CFI_NOR_BASE$, CFI_DEVINT, 2)
#define CFI_SIZE$    CFI_Query(CFI_NOR_BASE$, CFI_SIZE,   1)
#define CFI_WBSIZE$  CFI_Query(CFI_NOR_BASE$, CFI_WBSIZE, 2)
#define CFI_VCCMIN$  CFI_Query(CFI_NOR_BASE$, CFI_VCCMIN, 1)
#define CFI_VCCMAX$  CFI_Query(CFI_NOR_BASE$, CFI_VCCMAX, 1)
#define CFI_VPPMIN$  CFI_Query(CFI_NOR_BASE$, CFI_VPPMIN, 1)
#define CFI_VPPMAX$  CFI_Query(CFI_NOR_BASE$, CFI_VPPMAX, 1)
#define CFI_WPRGTT$  CFI_Query(CFI_NOR_BASE$, CFI_WPRGTT, 1)
#define CFI_BPRGTT$  CFI_Query(CFI_NOR_BASE$, CFI_BPRGTT, 1)
#define CFI_BLKETT$  CFI_Query(CFI_NOR_BASE$, CFI_BLKETT, 1)
#define CFI_CHPETT$  CFI_Query(CFI_NOR_BASE$, CFI_CHPETT, 1)
#define CFI_WPRGMT$  CFI_Query(CFI_NOR_BASE$, CFI_WPRGMT, 1)
#define CFI_BPRGMT$  CFI_Query(CFI_NOR_BASE$, CFI_BPRGMT, 1)
#define CFI_BLKEMT$  CFI_Query(CFI_NOR_BASE$, CFI_BLKEMT, 1)
#define CFI_CHPEMT$  CFI_Query(CFI_NOR_BASE$, CFI_CHPEMT, 1)
#define CFI_REGCNT$  CFI_Query(CFI_NOR_BASE$, CFI_REGCNT, 1)

#endif /* end of __FLASH_CFI_H  */

