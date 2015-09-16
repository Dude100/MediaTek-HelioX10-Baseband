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
 *   bl_BootInfo.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   Essential definition for analyzing boot information
 *
 * Author:
 * -------
 *   
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
 *
 * removed!
 * removed!
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

#ifndef __BL_BOOT_INFO_H__
#define __BL_BOOT_INFO_H__

#if defined(_NAND_FLASH_BOOTING_)

#ifndef __NAND_BOOT__
#define __NAND_BOOT__
#endif

#elif defined(__EMMC_BOOTING__)

#ifndef __EMMC_BOOT__
#define __EMMC_BOOT__
#endif

#elif defined(MT6251) || defined(__SERIAL_FLASH_EN__)

#ifndef __SF_BOOT__
#define __SF_BOOT__
#endif

#elif defined(__X_BOOTING__)

//Empty

#else

#ifndef __NOR_BOOT__
#define __NOR_BOOT__
#endif

#endif

#include "sw_types.h"
#include "br_header_block.h"
#include "bl_setting.h"

#define SYS_RESERVED_PATTERN 0x56534552   //RESV

typedef struct 
{
   U32 pattern;
   U8 reserved[44];     //struct size must be 48 bytes   
} SYS_ReservedStruct;

typedef struct
{
   U8 reserved[16];     //struct size must be 16 bytes
} SYS_ResetStruct;

typedef struct
{
   SYS_ReservedStruct sysReservedBuf;
   SYS_ResetStruct    sysResetBuf;
} SYS_ParamBuffer;

typedef struct
{
   U32 startPage;
   U32 boundPage;
   U32 reserved[1];      
} FlashLayoutNandEmmcElement;

typedef struct
{
   U32 binaryType;
   union {
      FlashLayoutNandEmmcElement nandEmmc;
   } u;
} FlashLayoutElement;

#define MAX_FLASH_LAYOUT_REGION     (24)

typedef struct
{
   U8 header[16];

   U32 ver;
   U32 bootloaderRegionEnd;
   U32 cbrStartBlock;
   U32 cbrBoundBlock;

   U32 reserved[3];
   U32 regionCount;
   FlashLayoutElement region[MAX_FLASH_LAYOUT_REGION];

} FlashLayout; 


#endif /* __BL_BOOT_INFO_H__ */

