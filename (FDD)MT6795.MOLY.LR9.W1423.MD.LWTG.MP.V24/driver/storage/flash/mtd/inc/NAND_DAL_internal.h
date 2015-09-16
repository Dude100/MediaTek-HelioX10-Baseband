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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *  NAND_DAL.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This is a NAND Flash Device Abstraction Layer file.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NAND_DAL_INTERNAL_H
#define NAND_DAL_INTERNAL_H

/****************************
 * Include Header Files     *
 ****************************/
#include "fota_error.h"
  // Add for RHR
    #include "NAND_MTD_FDM50_internal.h"
//RHR remove    #include "kal_non_specific_general_types.h"
    #include "kal_general_types.h"
  // Add for RHR
typedef struct flash_info_tag_2
{
    flash_list          deviceInfo_CE[2];
    kal_uint8           valid_CE[2];    /*flag to identify CE# is valid or not*/
    kal_uint8           bank_CE[2];    /*bank number of each device(CE)*/
    kal_uint8           zone_CE[2];    /*zone number of each device(CE), [Note] Need to concern CE_interleave_Flag to get total zone number*/
    kal_uint32          devicePage[2];
    kal_uint32          diePage[2];
    kal_uint32          planePage[2];
    kal_uint16          supportMPType[2]; /*judged supportMPType */
    kal_uint16          supportMEType[2]; /*judged supportMEType */
    kal_uint16          pageSize;
    kal_uint16          spareSize;
    kal_uint16          blockPage;
    kal_uint8           bankNum;    /*Total bank number of FDM section or Zone*/
    kal_uint8           zoneNum;    /*Total zone number*/
    kal_uint8           CE_interleave_Flag;
    kal_uint8           CE_cache_interleave_Flag;
    kal_uint8           CE_interleave_mOP_Idx[2];
    kal_uint8           CE_cache_interleave_mOP_Idx[2];
    mPage_operation     multiProgram[2][MAX_MULTIPAGE_FUNCTION_NUM];
    mPage_operation     multiErase[2][MAX_MULTIPAGE_FUNCTION_NUM];
}flash_info_2;
/*FDM Layer flash information*/
#define NUM_OF_ZONES 8 /*yehudi temp assign*/
#define BBM_GLOBAL_ADDR  0x8000         // The bank address is global not local in region.
typedef struct
{
  kal_uint8 TotalZoneNum;         // This number should exclude the NFB space. That is, only FAT size.
  kal_uint16  PSectionNumInZone[NUM_OF_ZONES];  // Section number for each zone. Also, need exclude the NFB space.
  kal_uint8 BankNumber;
  kal_bool  Plane_PagePair;     /*Flag to identify whether only page pair can process multiplane operation (i.e. samsung\Hynix device)*/
  kal_bool  ExtendBlock;
  kal_uint8   SectorNumPerPage;
  kal_uint16  PageNumPerSection;
  kal_uint8 SectionShiftNum;        // For example, 64 pages/section=> shift number 6, 256 pages/section=> shift number 8
#if defined(__NANDFDM_MULTI_INSTANCE__)
  kal_uint32  TotalPSectionNumInZone;         // This number is the physical number. No need to care the NFB, FS, etc.
#endif // defined(__NANDFDM_MULTI_INSTANCE__)
} FLASH_INFO;

//#define PROGRAM_WO_WAIT_LAST_BUSY   0x01
//WAIT_LAST_BUSY
//FULL_OPERATION

typedef struct
{
    kal_uint8  zoneNum;  /*input*/
    kal_uint16 *bankArry;/*input*/
    kal_uint32 pageIdx; /*input*/
    kal_uint32 phyPage; /*output*/
    kal_uint8  ce;      /*output*/
}add_convert;

typedef struct
{
    kal_uint8  zoneNum;  /*input*/
    kal_uint8  ce;      /*output*/
    kal_uint16 blockNum; /*input*/
    kal_uint32 zoneOffset; /*output*/
    kal_uint32 bankOffset; /*output*/
}struct_map_cache ;

typedef struct
{
  kal_uint16    LBA;
  kal_uint16    BM_PA;
  kal_uint8   R; /*reserve*/
  kal_uint8   BI;
  kal_uint16    PBA;
} FDMData_512;

typedef struct
{
#ifdef NEW_FDM_BAD_BLOCK_MARK
  kal_uint8   	BI;
  kal_uint8		R; /*reserve*/
#else
  kal_uint16    BI;
#endif
  kal_uint16    BM_PA;
  kal_uint16    LBA;
  kal_uint16    PBA;
} FDMData_2k;

typedef enum
{
    CODE_ACC,
    FAT_ACC,
    RAW_ACC
} DAL_ACC_Type;

#if defined(__UBL__)
typedef struct
{
  kal_uint8		flashLsz;		// in Byte (log2), possible value: <= 33
  kal_uint8		blkLsz;			// in Byte (log2), possible value: 15,16,17,18
  kal_uint8		pageLsz;		// in Byte (log2) , possible value: 9,11,12
  kal_uint8		spareSize;		// in Byte per sector, possible value: 16,26,27,28
  kal_uint32	rfu[3];			// reserved
} flash_info_sync_s;
#endif

#ifdef NEW_FDM_BAD_BLOCK_MARK
#define FDM_BAD_BLOCK_MARK_2K   (0xF0)
#else
#define FDM_BAD_BLOCK_MARK_2K   (0xF0F0)
#endif
#define FDM_BAD_BLOCK_MARK_512  (0xF0)
#define ZERO_OF_FDM_BAD_BLOCK_MARK_2K   (8)
#define ZERO_OF_FDM_BAD_BLOCK_MARK_512  (4)

#define FDMDATA_BM		0x01
#define FDMDATA_PA		0x02
#define FDMDATA_LBA		0x04
#define FDMDATA_BI		0x08
#define FDMDATA_BBPBA	0x10
#define FDMDATA_4XCTL	0x20
#define FDMDATA_EMPTY	0x80

//#define __EMULATE_NFB_BIT_ERROE__
#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
//#define ECC_BIT_ERROR_TEST
#endif // ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__) )
//#define ENABLE_ADVANCE_OPERATION

#if !defined DWORD_INVALID
    #define DWORD_INVALID       0xFFFFFFFF
#endif
#if !defined WORD_INVALID
    #define WORD_INVALID            0xFFFF
#endif
#if !defined BYTE_INVALID
    #define BYTE_INVALID            0xFF
#endif

kal_int32 DAL_FDM_Flash_Info_Init ( FLASH_INFO* fdm_flash_info, kal_uint32 DiskIndex);

/**************************************
 * Returns:     Low 2 byte: error Page
 *              High 2 byte: error code
 *************************************/
kal_int32 DAL_ProgramPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr,
                          kal_uint16 PageLength, kal_uint8 *Data, kal_uint8 *Spare);

kal_int32 DAL_ReadPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr, kal_uint16 PageLength,
                       kal_uint8 *Data, kal_uint8 *Spare);

kal_int32 DAL_CopyPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *srcBank, kal_uint16 *dstBank, kal_uint16 srcPageAddr,
                       kal_uint16 dstPageAddr, kal_uint16 PageLength, kal_uint8 *Data_buff, kal_uint8 *Spare_buff, kal_uint32 buff_len,
                       kal_uint8 SDataNumber);

kal_int32 DAL_EraseBlock(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 start, kal_uint8 length);

kal_int32 DAL_MarkBlockBad(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset, kal_bool EraseBlock,
                            kal_uint32 *Data_buff, kal_uint32 *Spare_buff);
/**************************************
 * Returns:      MTD_STATUS_NO_ERROR - The block is a Good block
 *               MTD_STATUS_EARLY_BAD - The block is a bad block of early bad
 *               MTD_STATUS_FDM_BAD - The block is a bad block of FDM bad
 *               (MTD_STATUS_EARLY_BAD|MTD_STATUS_FDM_BAD)
 *************************************/
kal_int32 DAL_CheckBadBlock (DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank,kal_uint8 Block_offset,
                             kal_bool newFlash, kal_uint32 *Data_buff, kal_uint32 *Spare_buff);

kal_int32 DAL_NAND_Reset(void);
#if defined(FLASH_DISKDRV_DEBUG) || (defined _NAND_FLASH_BOOTING_)
kal_int32 DAL_NFB_AddressConvert(kal_uint32 Block, kal_uint32 Page, kal_uint8* cs_p, kal_uint32* page_idx_p);
#endif
/*=====*/
kal_uint16 DAL_GetFDMData(kal_uint8 FDMType, kal_uint32 *Spare_buff) ;

void DAL_SetFDMData(kal_uint16 BMPA, kal_uint16 LBA, kal_uint8 Option, kal_uint32 *Spare_buff);

kal_uint8 DAL_GetDALVersion(void);

kal_bool DAL_FormatQuery(kal_uint8 dal_ver);

void DAL_GetDeviceInfo (kal_uint8 cs, flash_list* p);


kal_uint32 addressMap(add_convert* AddInfo);
kal_int32 DAL_ShutDown (void);

kal_int32 DAL_OTPAccess(kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 DAL_OTPQueryLength(kal_uint32 *LengthPtr);
kal_int32 DAL_GetDeviceIDInfo(void* DeviceInfo);
kal_int32 DAL_LPage2PPage(DAL_ACC_Type Acc_Type, kal_uint8 ZoneNo, kal_uint16 *Bank, kal_uint16 PageAddr);

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) )

typedef struct
{
	kal_uint8				Zone;
	kal_uint16				Block;
	kal_uint16				Bank;
	kal_uint16				Page;
} BAD_ADDR;

#define PF_DAL_TRIGGER	0x00000001
#define PF_MTD_TRIGGER  0x00000002
#define PF_BRMT_UPDATE	0x80000000
#define PF_LOW_FORMAT	0x40000000
#define PF_MERGE_ALL	0x20000000
#define PF_ACT_MERGEBMR 0x10000000
#define PF_NONBMR_INIT	0x08000000
#define PF_BMR_INIT		0x04000000
#define PF_WRITE_LSA	0x02000000
#define PF_PMT_SAVE		0x01000000
#define PF_REG_SAVE		0x00800000
#define PF_ACT_WRITE_1	0x00400000
#define PF_ACT_WRITE_2	0x00200000
#define PF_ACT_WRITE_3	0x00100000
#define PF_ACT_MOVENEW	0x00080000
#define PF_WL_MOVENEW	0x00040000
#define PF_PMT_SAVE_1	0x00020000
#define PF_MERGEBMR_ALL 0x00010000
#define PF_RAW_WRITE    0x00008000
#define PF_RAW_COPY     0x00004000


#define EF_DAL_TRIGGER	0x00000001
#define EF_MTD_TRIGGER  0x00000002
#define EF_BRMT_UPDATE1	0x80000000
#define EF_BRMT_UPDATE2	0x40000000
#define EF_LOW_FORMAT	0x20000000
#define EF_ERASE_RETURN 0x10000000
#define EF_WRITE_LSA	0x08000000
#define EF_RAW_ERASE    0x04000000
#define EF_RAW_WR_ERASE 0x02000000

extern kal_bool PFTrigger;
extern kal_bool EFTrigger;
extern kal_uint32 PFTestCase;
extern kal_uint32 EFTestCase;
// Program fail and Erase fail auto test . kuohong 2010.1.16
extern kal_bool PF_EF_AutoTest;
extern kal_uint32 PFTrigerByTestCase;
extern kal_uint32 EFTrigerByTestCase;

extern BAD_ADDR EraseBadAddr[];
extern BAD_ADDR ProgBadAddr[];

#endif // #if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && !defined(__UBL__))

#endif //NAND_DAL_INTERNAL_H
