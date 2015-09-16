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
 *	NAND_MTD_FDM50.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This is a NAND Flash MTD driver header file.
 *
 * Author:
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef NAND_MTD_FDM50_INTERNAL_H
#define NAND_MTD_FDM50_INTERNAL_H

/*******************************************************************************
 * Include Header Files
 *******************************************************************************/
#if defined __MTK_TARGET__
  #if defined __DOWNLOAD_AGENT__
    #include "NAND_DA_internal.h"
  #else
    #include "reg_base.h"
	#include "sleepdrv_interface.h"
  #endif
  #include "kal_general_types.h"
  #include "kal_public_defs.h" 
#endif

 #include "NAND_DevConfig.h"

/*******************************************************************************
 * Compiler definition
 *******************************************************************************/ 
#ifndef __NAND_INLINE
#ifdef __MTK_TARGET__
	#if defined (__ARMCC_VERSION)
		#define __NAND_INLINE __inline
	#elif defined (__GNUC__)
		#define __NAND_INLINE inline
	#endif /* ARMCC , GNUC */
#else  /* __MTK_TARGET__ */
	#define __NAND_INLINE __inline
#endif /* __MTK_TARGET__ */
#endif /*__NAND_INLINE*/
	 
/*******************************************************************************
 * Message Log definition
 *******************************************************************************/
#ifndef nandlog_print 
#if defined(__UBL__) || defined(__FUE__)
	#define nandlog_print
#elif defined(__MAUI_BASIC__)
	#define nandlog_print dbg_print
#else
  #define nandlog_print tst_sys_trace
#endif  
#endif /*nandlog_print*/

/*******************************************************************************
 * define
 *******************************************************************************/
//#define NFI_HW_SCRAMBLE_EN
#define NEW_FDM_BAD_BLOCK_MARK
#define SECTOR_READ_SUPPORT
#define NAND_ONFI_SUPPORT
#ifdef PHONE_TYPE_FOR_HQA
#define NFI_SLEEP_SUPPORT
#endif

#if (defined(ATEST_DRV_NFI) && !defined(__UBL__) && !defined(__FUE__))
#define __NAND_FLASH_HARDWARE_TEST__ 
#define __MAUI_BASIC__ 
#define ECC_BIT_ERROR_TEST
#define DAL_VERIFICATION
#endif

#ifndef NODEBUG
   #define DEBUG
#endif

#ifdef _MSC_VER
   #define INTERN _fastcall
   #define WATCOM_VOLATILE
#elif defined __BORLANDC__
   #define INTERN __fastcall
   #define WATCOM_VOLATILE
#else
   #define INTERN
   #define WATCOM_VOLATILE volatile   // Watcom compiler bug workaround
#endif

/*MTD status value must keep the low 16 bit to zero*/
#define MTD_STATUS_NO_ERROR           (0x00000000)
#define MTD_STATUS_ERROR              (0x00010000)
#define MTD_STATUS_CORRECTED          (0x00020000)
#define MTD_STATUS_EARLY_BAD          (0x00040000)
#define MTD_STATUS_FDM_BAD            (0x00080000)
#define MTD_STATUS_ID_NOT_SUPPORT     (0x00100000)
#define MTD_STATUS_PARA_ERROR         (0x00200000)
#define MTD_STATUS_TIMEOUT            (0x00400000)

/* NAND flash plane setting */
#define NAND_PLANE_BLOCK_BIT0 (1 << 0)
#define NAND_PLANE_BLOCK_BIT1 (1 << 1)
#define NAND_PLANE_BLOCK_BIT2 (1 << 2)
#define NAND_PLANE_BLOCK_BIT3 (1 << 3)
#define NAND_PLANE_BLOCK_BIT4 (1 << 4)
#define NAND_PLANE_BLOCK_BIT5 (1 << 5)
#define NAND_PLANE_BLOCK_BIT6 (1 << 6)
#define NAND_PLANE_BLOCK_BIT7 (1 << 7)
#define NAND_PLANE_BLOCK_BIT8 (1 << 8)
#define NAND_PLANE_BLOCK_BIT9 (1 << 9)
#define NAND_PLANE_BLOCK_BIT10 (1 << 10)
#define NAND_PLANE_BLOCK_BIT11 (1 << 11)
#define NAND_PLANE_BLOCK_BIT12 (1 << 12)
#define NAND_PLANE_BLOCK_BIT13 (1 << 13)
#define NAND_PLANE_BLOCK_BIT14 (1 << 14)
#define NAND_PLANE_BLOCK_BIT15 (1 << 15)
#define NAND_PLANE_BLOCK_BIT16 (1 << 16)

#define	PRE_SCAN_BLOCK_NUM	20

/* flag for NAND_Reset */
#define NFI_NAND_RST_CON				(0x00000001)
#define NFI_NAND_RST_DEV				(0x00000002)
#define NFI_NAND_RST_WAIT_READY			(0x00000004)

/* NAND flash attributes (0~24bits)*/
#define NAND_ARRT_OFFSET			(8)
#define NAND_ARRT_READ_CACHE		(1 << 0)
#define NAND_ARRT_PROGRAM_CACHE		(1 << 1)
#define NAND_ARRT_COPYBACK			(1 << 2)
#define NAND_ARRT_OTP_SUPPORT		(1 << 3)

/*******************************************************************************
 * NFI address definition
 *******************************************************************************/

/*******************************************************************************
 * NFI register definition
 *******************************************************************************/
#define NAND_SECTOR_SIZE        (512)
#define BAD_BLK_MARK_NUM_MAX	(4)

#define PAGEFMT_FDM_ECC_DEFAULT	8
#define PAGEFMT_FDM_DEFAULT		8

/*******************************************************************************
 * Macro definition
 *******************************************************************************/
#define ECC_MAGIC_NUM			(13)
#define ECC_BASE_BIT_NUM		4
#define ECC_BIT_NUM(ecc_cap)	(ECC_BASE_BIT_NUM + ecc_cap * 2)

/*******************************************************************************
 * NAND MTD declaration
 *******************************************************************************/
 // NAND flash maker ID
#define TOSHIBA		0x98
#define SAMSUNG		0xEC
#define HYNIX		0xAD
#define ST			0x20
#define MICRON		0x2C
#define	INTEL		0x89
#define SPANSION	0x01
#define POWERFLASH	0x92

typedef struct NAND_ID_tag
{
	kal_uint32 mID:8;			 /*[Byte1]*/
	kal_uint32 dID:8;			 /*[Byte2]*/
	kal_uint32 dieNum:2;		 /*[Byte3] number of Die (per CE) = (1<<value)*/
	kal_uint32 cellType:2;		 /*[Byte3] Cell Type = (2<<value) Level cell, value >= 1 is MLC*/
	kal_uint32 simultNum:2; 	 /*[Byte3] Number of Simutaneously Programmed Page = (1<<value), for each die*/
	kal_uint32 dieInterleave:1;  /*[Byte3] die Interleave support Flag: 1 support; 0 Not Support*/
	kal_uint32 cacheProgram:1;	 /*[Byte3] cache Program support Flag: 1 support; 0 Not Support*/
	kal_uint32 pageSize:2;		 /*[Byte4] page Size = (1024<<value)*/
	kal_uint32 spareSize:1; 	 /*[Byte4] spare Size per 512 = (8<<value) */
	kal_uint32 accessTime0:1;	 /*[Byte4]*/
	kal_uint32 blockSize:2; 	 /*[Byte4] block Size = (64k<<value)*/
	kal_uint32 IOWidth:1;		 /*[Byte4] IOWidth = (8<<value)*/
	kal_uint32 accessTime1:1;	 /*[Byte4]*/
	kal_uint32 byte5Rev0:1; 	 /*[Byte5]*/
	kal_uint32 ToshibaExt:1;	 /*[Byte5] [Toshiba] Extended block flag*/
	kal_uint32 planeNum:2;		 /*[Byte5] number of plane (per CE) = (1<<value) (Toshiba does not suuport)*/
	kal_uint32 planeSize:3; 	 /*[Byte5] plane Size= (64Mb<<value) (Toshiba does not suuport)*/
	kal_uint32 byte5Rev1:1; 	 /*[Byte5]*/
	kal_uint32 Reserve:24;		 /*[Byte6~8]*/
}nAND_ID;


typedef struct
{
	kal_uint8  cmd[2];
	kal_uint8  cmd_len;
	kal_uint32 add[2]; /*Max 8 x uint8 address cycle*/
	kal_uint8  add_cycle;
	kal_uint8  *buff;
	kal_uint32 buff_len;
	kal_uint8  *spare;
	kal_uint32 spare_len;
	kal_uint32 intFlag;
	kal_uint8  ECCFlag;
}nAND_Cmd_info;


typedef struct mtd_lock_tag {
   kal_uint32  lock_count;
   kal_taskid  owner_id;
   kal_enhmutexid mtd_enhmutex;
} NAND_MTD_LOCK;

#if defined(__AUDIO_DSP_LOWPOWER__)
typedef struct {
   kal_uint32	 nfi_ACCCON_reg;		// NFI R/W access timing  (MAX: 0xFFFFFFFF)
   kal_uint32	 nfi_page_size; 		// PAGE_512. PAGE_2K   (MAX: 4096)
   kal_uint32	 nfi_spare_size;		//	SPARE_SIZE ==> 16 bytes (MAX:16)
   kal_uint32	 nfi_pages_per_block;	// PAGE_512 ==> 32, PAGE2K ==> 64  (MAX : 128)
   kal_uint32	 nfi_fdm_size;			// ECC protection area	of fdm data in NAND is defined by nfi_fdm_size	//(MAX:8)
   kal_uint32	 nfi_sector_num;		// PAGE2K=4, PAGE512=1 (MAX:8)
   kal_uint32	 nfi_data_sectors;		// Define sectors number for read at each transaction. (MAX:8)
   kal_uint32	 nfi_col_num;			// parameter for nand  (MAX:2)
   kal_uint32	 nfi_row_num;			// parameter for nand (MAX:4)
   kal_uint32	 nfi_io_width;			// BUS width: 8bits / 16 bits nand device (MAX:1)
} NFI_Config_for_MP3_st;
#endif // #if defined(__AUDIO_DSP_LOWPOWER__)



/*******************************************************************************
 * structure definition for flash supply list and MTD
 *******************************************************************************/

typedef struct
{
    kal_uint32 *page_p;
    kal_uint8  *buff;
    kal_uint8  *spare;
    kal_uint16 pageOffset; /*Pnysical PageIndex = (*page_p)+pageOffset*/
    kal_uint8  addCycle;
    kal_uint8  opFlag;
} mtd_drv_para;

#if defined(__DOWNLOAD_AGENT__)
typedef struct  //for (opFlag == PARTIAL_OPERATION)
{
    kal_uint32 *page_p;
    kal_uint8  *buff;
    kal_uint16  length;		/*spare is partial read length with  */
    kal_uint16 column;
    kal_uint8  addCycle;
    kal_uint8  opFlag;
} mtd_drv_para2;
#endif

/*For mtd_drv_para.opFlag*/
#define FIRST_PROCESS           0x01
#define SECOND_BUSY             0x02
#define FULL_OPERATION          (FIRST_PROCESS|SECOND_BUSY)
#define ONE_SPARE				0x04
#define PARTIAL_OPERATION		0x08
#define PROGRAM_CACHED           0x10
#define PROGRAM_FINAL            0x20
#define SAMSUNG_D0_ILEAVE_OP     0x40 /*samsung die 0 interleave operation*/
#define SAMSUNG_D1_ILEAVE_OP     0x80 /*samsung die 1 interleave operation*/
typedef struct multiPage_operation_tag
{
    kal_uint32 (*func_p) (mtd_drv_para* Para);          /**/
    kal_uint8 startAlign;       /*start page alignment limitation*/
    kal_uint8 multiPageNum;    /*the max page numner func_p can access. 0xFF means continue to end of block*/
}mPage_operation;

#define MAX_MULTIPAGE_FUNCTION_NUM 6
#define MAX_MULTIPAGE_NUM 8 /*max MULTI-PAGE num (CE0+CE1)*//*It should <= 16 due to MTD return value */

typedef struct
{
    kal_uint8  *buff;
    kal_uint8  *spare;
    kal_uint32 pageIdx[MAX_MULTIPAGE_NUM];
    kal_uint16 length;
    kal_uint8  ce;
    kal_uint8  m_idx;  /*index of Flash_Info.multiProgram*/
    kal_uint8  opFlag;
}mtd_if_para;

typedef struct
{
    kal_uint8  *buff;
	kal_uint16 offset;
    kal_uint32 pageIdx[MAX_MULTIPAGE_NUM];
    kal_uint16 length;
    kal_uint8  ce;
    kal_uint8  m_idx;  /*index of Flash_Info.multiProgram*/
    kal_uint8  opFlag;
}mtd_if_para2;

typedef struct _bad_blk_mark_s_ {
	unsigned markedPage;
	unsigned markedOffset;
} bad_blk_mark_t;

typedef struct
{
	kal_uint32     (* ProgramPage)                   (mtd_drv_para* Para);
	kal_uint32     (* ReadPage)                      (mtd_drv_para* Para);
	kal_uint32     (* CopyPage)                      (mtd_drv_para* Para);
	kal_uint32     (* EraseBlock)                    (mtd_drv_para* Para);
/*Multi Page Program functions*/
	kal_uint32     (* TwoPlaneProgram)               (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* TwoDieProgram)                 (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* FourPlaneProgram)              (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* TwoDieTwoPlaneProgram)         (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* CacheProgram)                  (mtd_drv_para* Para);
	kal_uint32     (* TwoPlaneCacheProgram)          (mtd_drv_para* Para);
	kal_uint32     (* TwoDieCacheProgram)            (mtd_drv_para* Para);
	kal_uint32     (* FourPlaneCacheProgram)         (mtd_drv_para* Para);
	kal_uint32     (* TwoDieTwoPlaneCacheProgram)    (mtd_drv_para* Para);
/*Multi Block Erase functions*/
	kal_uint32     (* TwoPlaneErase)               (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* TwoDieErase)                 (mtd_drv_para* Para);/*multiple 2*/
	kal_uint32     (* FourPlaneErase)              (mtd_drv_para* Para);/*multiple 4*/
	kal_uint32     (* TwoDieTwoPlaneErase)         (mtd_drv_para* Para);/*multiple 4*/
/* OTP related function */
	kal_int32  	   (* OTPAccess)                   (kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
	kal_int32      (* OTPQueryLength)              (kal_uint32 *Length);
} NAND_MTD_SUB_DRIVER;

typedef enum {
	ECC_4_BITS	= 0,
	ECC_6_BITS	= 1,
	ECC_8_BITS	= 2,
	ECC_10_BITS	= 3,
	ECC_12_BITS	= 4,
	ECC_AUTO_SEL = 0xFF
} ecc_cap_t;

typedef struct
{
    nand_Name               DevName_enum;        /*Device name enum*/
	kal_char                DevName_str[64];     /*Device name string*/
    kal_uint8               ID_info[8];    /*equal sizeof(nAND_ID)*/
    kal_uint8               ID_valid_mask[8];  /*valid-bit mask of ID_info*/
    kal_uint8               IOWidth;
    kal_uint8               address_cycle; /*row add cycle + column add cycle*/
    kal_uint8               planeNum;      /*number of plane per die, min 1*/
    kal_uint8               dieNum;        /*number of die per device(CE), min 1*/
    kal_uint16              pageSize;
    kal_uint16              spareSize;
    kal_uint16              blockPage;
    kal_uint16              deviceSize;    /*unit by MByte (so max < 64GB), exclude the extended block size*/
    kal_uint16              supportMPType; /*Supported Multi-page program type*//*supportOpType*/
    kal_uint16              supportMEType; /*Supported Multi-Block Erase type*//*supportOpType*/
    kal_uint16              CopyBackType;  /*Type of Copyback*/
    NAND_MTD_SUB_DRIVER*        driverSet;     /*driverSet + supportOpType = supported driver*/
	kal_uint8				badBlkMarkNum;
	bad_blk_mark_t			badBlkMark[BAD_BLK_MARK_NUM_MAX];
	ecc_cap_t				eccMinNum; /*Minimum required ECC n-bits per sector*/
	kal_uint32				acccon;	/*NAND flash access timing*/
	kal_uint32				attribute; /*NAND flash attribute (cache/OTP...)*/
}flash_list /*device_info*/;

/*device feature/operation support (for flash_list.supportOpType)*/
#define SIMPLE_OP               (0x0000)
/*Do not use (0x0001), it use by AUTO_NAND_DETECT (0x0011)*/
#define TWO_PLANE_OP            (0x0002)
#define FOUR_PLANE_OP           (0x0004)
#define TWO_DIE_INTERLEAVE_OP   (0x0008)
/*Do not use (0x0010), it use by AUTO_NAND_DETECT (0x0011)*/
#define CACHE_PROGRAM           (0x0020)
#define EXTENDED_BLOCK          (0x0040)
#define PLANE_INTERLACED        (0x0080) /*block number is interlaced between plane*/
#define PLANE_CONTINUOUS        (0x0100) /*block number is continuous in plane*/

#define AUTO_NAND_DETECT        (0x00AD) /*auto-detection definition of all excepte (supportMPType and supportMEType)*/


/* indicate if write ECC fields while program page */
enum
{
    ECC_SKIP = 0,            // don't program spare area
    ECC_FIRST_HALF,      // only program first and second ECC fields
    ECC_SECOND_HALF,     // only program third and fourth ECC fields
    ECC_WHOLE            // program whole ECC fields
};

/*******************************************************************************
 *  Macro definition
 *******************************************************************************/
#if (defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__) && defined(MT6290))
#define INITIALIZE_NFI_DIR_DOUT
#define SET_NFI_CS0
#define SET_NFI_CS1
#define SET_NFI_CS1_END
#endif

#if !defined(__NFI_VERSION3_1__)
	
#if defined(MCU_13M)
	/* 1T ~= 77 ns */
#define COUNTER_200nS	(3)
	
#elif defined(MCU_26M)
	/* 1T ~= 38 ns */
#define COUNTER_200nS 	(6)
	
#elif defined(MCU_52M)
	/* 1T ~= 19 ns */
#define COUNTER_200nS 	(11)
	
#elif defined(MCU_78M)
	/* 1T ~= 12.8 ns */
#define COUNTER_200nS 	(16)
	
#elif defined(MCU_104M)
	/* 1T ~= 9.6 ns */
#define COUNTER_200nS 	(21)
	
#elif defined(MCU_122_88M)
	/* 1T ~= 8.13 ns */
#define COUNTER_200nS 	(25)
	
#elif defined(MCU_208M)
	/* 1T ~= 4.8 ns */
#define COUNTER_200nS   (42)
	
#elif defined(MCU_245_76M)
	/* 1T ~= 4 ns */
#define COUNTER_200nS   (50)
	
#elif defined(MCU_260M)
	/* 1T ~= 3.8 ns */
#define COUNTER_200nS   (52)
	
#elif defined(MCU_312M)
	/* 1T ~= 3.2 ns */
	
#define COUNTER_200nS   (63)
	
#elif defined(MCU_368_64M)
	/* 1T ~= 2.7 ns */
#define COUNTER_200nS   (75)
	
#elif (defined(MCU_491_52M) || defined(MCU_492M) || defined(MCU_480M))
	/* 1T ~= 2.0 ns */
#define COUNTER_200nS   (100)
	
#else
	#if defined(NAND_SUPPORT)
		#error "Unsupported MCU clock rate for busy wait loop!"
	#endif
	
#endif
	
#endif // !defined(__NFI_VERSION3_1__)

#if !defined(CORTEXA7)
#define vp_v2p(ptr) (ptr)
#endif

/*******************************************************************************
 *  MTD function declaration
 *******************************************************************************/
//kal_int32 MTD_MountDevice	(void * DriveData);
kal_int32 MTD_MountDevice( void);
kal_uint32 MTD_CE_Interleave_Program (mtd_if_para* Para);
kal_uint32 MTD_CE_Interleave_CacheProgram (mtd_if_para* Para);
kal_uint32 MTD_Program (mtd_if_para* Para);
kal_uint32 MTD_CacheProgram (mtd_if_para* Para);
kal_uint32 MTD_Read(mtd_if_para* Para);
kal_uint32 MTD_Erase(mtd_if_para* Para);
kal_uint32 MTD_MarkBlockBad (mtd_if_para* Para);
kal_uint32 MTD_CheckBlockBad (mtd_if_para* Para);
kal_uint32 MTD_NAND_Reset(mtd_if_para* Para);
kal_int32 MTD_ShutDown(void);
kal_uint32 MTD_CheckEmptyBlock(mtd_if_para* Para);

#if defined(__DOWNLOAD_AGENT__)|| defined(ECC_BIT_ERROR_TEST)
kal_uint32 MTD_ReadWithoutECC(mtd_if_para* Para);
#endif
#if defined(__DOWNLOAD_AGENT__)
kal_uint32 MTD_ReadPartial(mtd_if_para2* Para);
kal_uint32 MTD_BadBlock_ReMark(mtd_if_para* Para);
kal_uint32 MTD_Initial_HeaderBlock(mtd_if_para* Para);
kal_uint32 MTD_Query_BPTTBL(kal_uint32 Block, kal_uint32 QueryType);
kal_uint32 MTD_Update_BPTTBL(kal_uint32 phyBadBlock);
kal_uint32 MTD_WriteBack_HeaderBlock(mtd_if_para* Para);
#endif 

#if defined(FLASH_DISKDRV_DEBUG) && !defined(__MTK_TARGET__)
void MTD_Simu_Create_Device_File (void);
void MTD_Simu_SetUserDefID(kal_uint32 cs0_ID_0_3,kal_uint32 cs0_ID_4_7,kal_uint32 cs1_ID_0_3,kal_uint32 cs1_ID_4_7);
void MTD_Simu_SetIDData(kal_uint32* id_data,kal_uint8 cs);
#if defined DAL_DLL_VERSION
void MTD_WriteErrMsg(char* title, char* exp, char* f, kal_uint32 line, kal_uint32 e1, kal_uint32 e2, kal_uint32 e3);
#endif
#endif

//kal_int32 MTD_EraseBlock	(void * DriveData, kal_uint32 BlockIndex);

/*******************************************************************************
 *  NFIC driver function declaration
 *******************************************************************************/
kal_uint32 NFI_NAND_PowerInit(kal_bool first);
kal_uint32 NFI_NAND_PowerCtl(kal_bool ON);
kal_uint32 NFI_NAND_IRQ_Register();
kal_uint32 NFI_NAND_Reset(kal_uint32 rst_flag);
kal_uint32 NFI_NAND_PageFmt_Config(kal_uint8 IOWidth, kal_uint16 pageSize, kal_uint16 spare_size);
kal_uint32 NFI_NAND_ECC_Config(kal_bool ecc_enable);
kal_uint32 NFI_NAND_ECC_Encode(kal_uint8 *buff_ptr, kal_uint32 buff_size, kal_uint32 encode_size);

kal_uint32 NFI_NAND_COMMON_UnlockFlash();
kal_uint32 NFI_NAND_COMMON_ReadID(kal_uint32 addr, kal_uint32 idAry[]);
kal_uint32 NFI_NAND_IsEmptyPage (mtd_drv_para *para);
kal_uint32 NFI_NAND_Remake_ID_Table(kal_uint32 id_data[], flash_list *pNAND_ID_Table);
kal_uint32 NFI_NAND_Set_ID_Table(flash_list *pNAND_ID_Table, void *pCombo_NAND_Table);
kal_uint32 NFI_NAND_Check_ONFI(void *pCombo_NAND_Info, kal_uint32 *Attribute);

void NFI_Reset(void);

/*******************************************************************************
 *  MTD Sub-function declaration
 *******************************************************************************/
kal_uint32 single_Page_Program (mtd_drv_para *para);
kal_uint32 single_Page_CacheProgram (mtd_drv_para *para);
kal_uint32 single_Page_Read (mtd_drv_para *para);
kal_uint32 single_Block_Erase (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_Program (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_Program (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_Erase (mtd_drv_para *para);
kal_uint32 toshiba_twoPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 toshiba_fourPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 samsung_twoPlane_Program (mtd_drv_para *para);
kal_uint32 samsung_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 samsung_twoDie_Program (mtd_drv_para *para);
kal_uint32 samsung_twoDie_Erase (mtd_drv_para *para);
kal_uint32 samsung_twoDie_twoPlane_Program (mtd_drv_para *para);
kal_uint32 samsung_twoDie_twoPlane_Erase (mtd_drv_para *para);
kal_int32  samsung_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  samsung_OTPQueryLength(kal_uint32 *Length);
kal_int32  hynix_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  hynix_OTPQueryLength(kal_uint32 *Length);
kal_int32  micron_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  micron_OTPQueryLength(kal_uint32 *Length);
kal_int32  NAND_OTPAccess(kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32  NAND_OTPQueryLength(kal_uint32 *Length);
kal_uint32 micron_twoPlane_Program (mtd_drv_para *para);
kal_uint32 micron_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 micron_twoPlane_CacheProgram (mtd_drv_para *para);
kal_uint32 micron_twoDie_Program (mtd_drv_para *para);
kal_uint32 micron_twoDie_Erase (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_Program (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_Erase (mtd_drv_para *para);
kal_uint32 micron_twoDie_CacheProgram (mtd_drv_para *para);
kal_uint32 micron_twoDie_twoPlane_CacheProgram (mtd_drv_para *para);
#if defined(__DOWNLOAD_AGENT__)
kal_uint32 single_Page_Read_WithoutECC(mtd_drv_para *para);
kal_uint32 partial_Page_Read(mtd_drv_para2 *para);
#endif
#if defined(SECTOR_READ_SUPPORT)
kal_uint32 partial_Sector_Read(mtd_drv_para *para);
#endif
#if defined(NAND_ONFI_SUPPORT)
kal_uint32 Parameter_Page_Read(mtd_drv_para *para);
#endif

kal_uint32 FlashCheckID(const flash_list *ID_table);

kal_uint8 read_status(kal_uint8 cmd1, nAND_Cmd_info* info );
kal_int32 InitializeMTD(void * DriveData);
void nfi_lisr(void);
void nfi_hisr(void);
void NFI_DMA_Callback(void);
void pdn_nfi(kal_bool ON);
void NAND_GPIO_InitIO(char direction, char port);
char NAND_GPIO_ReturnMode(char port);
char NAND_GPIO_ReadIO(char port);
void NAND_GPIO_WriteIO(char data, char port);
kal_bool NAND_INT_USBBoot(void);

/******************************************************************************
 * SuperAND flash device definition                                           *
 ******************************************************************************/
#define SUPERAND_PAGE_READ_CMD  0x00    /* Can be recognized by NFI */
#define SUPERAND_SEQ_READ_CMD   0x0F    /* Can't be recognized by NFI */
#define SUPERAND_READ_END_CMD   0xF0    /* Can't be recognized by NFI */
#define SUPERAND_REWRITE_CMD    0x1F    /* Can't be recognized by NFI */
#define SUPERAND_PROG_CMD       0x10    /* Can be recognized by NFI */

#define SUPERAND_ADDR_CYCLE     0x04
#define SUPERAND_BYTES_PER_SECTOR   (SUPERAND_PAGES_PER_SECTOR << 9)
#define SUPERAND_PAGES_PER_SECTOR   0x04
#define SUPERAND_SECTOR_MASK    (SUPERAND_PAGES_PER_SECTOR - 1)
#define SUPERAND_PAGES_PER_EXT_SECTOR   0x08
#define SUPERAND_EXT_SSECTOR_MASK    (SUPERAND_PAGES_PER_EXT_SECTOR - 1)


#define SUPERAND_PAGEFMT_8BIT   0x0005
#define SUPERAND_PAGEFMT_16BIT  0x0105

#define SUPERAND_ACCCON         0x07FF

#define PAGES2BYTES(pages)      ((pages) << 9)
#define PAGES2DWORDS(pages)     ((pages) << 7)

#define MAX_DEVICE_NUM          2

typedef struct
{
   kal_uint16     id;
   kal_uint16     plane_size;      // in MBytes
   kal_uint16     block_size;      // in KBytes
   kal_uint8      io_width;        // 8 or 16 bits
}  superand_flash_list;
#define SUPERAND_FLASH_LIST_END {0xFFFF, 0, 0, 0}

typedef struct
{
	kal_int32     (* MountDevice)    (void * DriveData);
	kal_int32     (* ShutDown)       (void * DriveData);
	kal_int32     (* ReadPages)      (void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
	kal_int32     (* RewritePages)   (void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
	kal_int32     (* ProgramData)    (void * DriveData, kal_uint32 PageIndex, kal_uint32 Bytes, kal_uint8 * Data);
	kal_int32     (* EraseBlock)     (void * DriveData, kal_uint32 PageIndex);
	kal_int32     (* ReadGoodBlkCnt) (void * DriveData);
} SuperAND_MTD_DRIVER;

#if (defined(MT6218B) || defined(MT6219))
#define COMPUTE_ADDRESS_AND_SET_CSEL \
{\
    kal_uint32 page_idx = PageIndex;\
    kal_uint16 *paddr = (kal_uint16*)&addr;\
    paddr[0] = (D->io_width == 8) ? (kal_uint16)((page_idx&0x3) << 9) : (kal_uint16)((page_idx&0x3) << 8);\
    paddr[1] = page_idx >> 2;\
}
#else
#define COMPUTE_ADDRESS_AND_SET_CSEL \
{\
    kal_uint32 page_idx = PageIndex;\
    kal_uint16 *paddr = (kal_uint16*)&addr;\
    if(page_idx >= D->pages_of_first_device)\
    {\
        *NFI_CSEL = 0x1;\
        page_idx -= D->pages_of_first_device;\
    }else{\
        *NFI_CSEL = 0x0;\
    }\
    paddr[0] = (D->io_width == 8) ? (kal_uint16)((page_idx&0x3) << 9) : (kal_uint16)((page_idx&0x3) << 8);\
    paddr[1] = page_idx >> 2;\
}
#endif

void SuperAND_MTD_Init(void);
kal_int32 SuperAND_MTD_MountDevice(void * DriveData);
kal_int32 SuperAND_MTD_ShutDown(void * DriveData);
kal_int32 SuperAND_MTD_ReadPages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
kal_int32 SuperAND_MTD_RewritePages(void * DriveData, kal_uint32 PageIndex, kal_uint32 Pages, kal_uint8 * Data);
kal_int32 SuperAND_MTD_ProgramData(void * DriveData, kal_uint32 PageIndex, kal_uint32 Bytes, kal_uint8 * Data);
kal_int32 SuperAND_MTD_EraseBlock(void * DriveData, kal_uint32 PageIndex);
kal_int32 SuperAND_MTD_ReadGoodBlkCnt(void * DriveData);

kal_uint16 superand_read_device_id(kal_uint16 csel);
kal_bool superand_checkdevice(void * DriveData);
kal_int32 superand_writefifo(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint32 Bytes, kal_bool rewrite);
void superand_readfifo(kal_uint8 * Data, kal_uint32 Pages);
kal_uint8 superand_read_status(void);


extern kal_uint32 custom_part_secs;

extern NAND_MTD_SUB_DRIVER SAMSUNG_SINGLE_CACHE_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER SAMSUNG_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER HYNIX_ST_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER TOSHIBA_SUB_DRIVER;
extern NAND_MTD_SUB_DRIVER MICRON_SUB_DRIVER;

/******************************************************************************
 * EMIGEN NAND flash parameter definition                                                                          *
 ******************************************************************************/
typedef struct {
	kal_uint32		version;			/*equal to 0x00000301 */
	kal_char		DevName_str[64];	/*Device name string*/
    kal_uint8		ID_info[8];			/*equal sizeof(nAND_ID)*/
    kal_uint8		ID_valid_mask[8];	/*valid-bit mask of ID_info*/
	kal_uint16		deviceSize;			/*unit by MByte (so max < 64GB), exclude the extended block size*/
	kal_uint32		blockSize;			/*unit by Byte*/
	kal_uint32		nfi_acccon_val;		/*NFI_ACCCON_VAL : NFIC access timing*/
	kal_uint32		nfi_rdyto_val;		/*NFI_RDYTO_VAL : FCD busy to ready timeout*/
	kal_uint32		nfi_adnob_val;		/*NFI_ADNOB_VAL : Address cycle*/
	kal_uint32		nfi_bb_mark[4];		/*NFI_BB_MARK : Bad block mark offset*/
	kal_uint32		nfi_dc_val;			/*NFI_DC_VAL : NFIC driving*/
	kal_uint32		nfi_drv_set;		/*NFI_DRV_SET : driver type set*/
	kal_uint32		nfi_pgfmt_val;		/*NFI_PGFMT_VAL : page format*/
	kal_uint32		nfi_tnum_val;		/*NFI_TNUM_VAL: ECC tnum*/
} combo_nand_flash_list_v01;

typedef union {
	kal_uint32 version;
	combo_nand_flash_list_v01 v01;		//CFG v3.1
} combo_nand_flash_list;

#ifdef __DOWNLOAD_AGENT__ //Bootloader include nfb_header.h
//==============================================================================
// NFB header structure for  HB
//==============================================================================
#define ECC_PARITY_BYTES    (20)
#define NFB_LOOP_STOP       (100)

typedef struct _NFIType
{
    kal_uint16	IOInterface;     /* IO_8BITS or IO_16BITS */
    kal_uint16	pageSize;        /* 512, 2048, 4096 bytes */
    kal_uint16	addressCycle;
} NFI_MENU;

typedef struct __NFB_HEADER
{
    kal_char	ID1[12];
    kal_char	version[4];
    kal_char	ID2[8];
    NFI_MENU	NFIinfo;
    kal_uint16	spareSize;
    kal_uint16	pagesPerBlock;
    kal_uint16	totalBlocks;
    kal_uint16	pageShift;
    kal_uint16	blockShift;
    kal_uint8	scramble;
    kal_uint32	padding[6];
} NFB_HEADER;

typedef struct {
    NFB_HEADER	nfb_header_body;
    kal_uint32	dummy_u32; // It forces the buffer pointer of NFB_HDR_SECTOR to be 4-bytes alignment address.
    kal_char	nfb_dummy[128-sizeof(NFB_HEADER)-4-ECC_PARITY_BYTES];
    kal_uint8	nfb_ecc_parities[ECC_PARITY_BYTES];
} NFB_HDR_SECTOR;

#define REPLICATION_NUMBER         (512/sizeof(NFB_HDR_SECTOR))

typedef struct {
    NFB_HDR_SECTOR  nfb_hdr_sec[REPLICATION_NUMBER];
} NFB_HDR_REPLICATION;

//==============================================================================
// Header Block Information
//==============================================================================

#define MAX_RECORD_SIZE     512

#define BOOTLOADER_ID1		"BOOTLOADER!\0"
#define BOOTLOADER_ID2		"NFIINFO\0"
#define BOOTLOADER_VER		"V006\0"

#define BPTTBL_ID           "BPTTBL\0\0"
#define BPTTBL_VER          1
#define BPTTBL_MAX_ENTRY    124

typedef enum {
     REGION_IDX_DEV_HEADER      = 0
    ,REGION_IDX_BRLYT           = 1
    ,REGION_IDX_BRTTBL          = 2
    ,REGION_IDX_HB_EPP_PARAM    = 3
    ,REGION_IDX_BPTTBL    		= 4
    ,REGION_TOTAL_NUM
    ,REGION_IDX_END             = (kal_uint8)255
} REGION_IDX;

typedef struct {
    kal_uint32		m_num;
    kal_uint32		m_entry[BPTTBL_MAX_ENTRY];
} Log2Phy_Table;

typedef struct {
    // WARNING! Ensure structure size is exactly 512B 
    kal_char			m_identifier[8];        // including '\0'
    kal_uint32			m_ver;               // this structure will directly export to others, version field is necessary
    Log2Phy_Table		m_log2phy_map;
} BP_TransTable_v1;

typedef union {

	/*#if defined(__NOR_BOOT__)
	NOR_HEADER_v1       m_nor_hdr;
	#endif*/

	//#if defined(__NAND_BOOT__)
	NFB_HEADER          m_nand_hdr;
	//#endif

	/*#if defined(__EMMC_BOOT__)
	EMMC_HEADER_v1      m_emmc_hdr;
	#endif

	#if defined(__SF_BOOT__)
	SF_HEADER_v1        m_sf_hdr;
	#endif*/

    // raw data 
    kal_uint32			m_raw_data[MAX_RECORD_SIZE>>2];

} DEV_HDR_U;

typedef union {
    //BR_Layout_v1        m_br_layout;
    // raw data 
    kal_uint32			m_raw_data[MAX_RECORD_SIZE>>2];
} BRLYT_U;

typedef union {
    //BR_TransTable_v1    m_br_ttbl;
    // raw data 
    kal_uint32			m_raw_data[MAX_RECORD_SIZE>>2];
} BRTTBL_U;

typedef union {
    //EPP_Param_v1        m_hb_epp_param;
    // raw data 
    kal_uint32			m_raw_data[MAX_RECORD_SIZE>>2];
} HB_EPP_PARAM_U;

typedef union {
    BP_TransTable_v1	m_bp_ttbl;
    // raw data 
    kal_uint32			m_raw_data[MAX_RECORD_SIZE>>2];
} BPTTBL_U;

typedef struct {

    kal_uint32			m_hdr_blk_dev_addr;     // header block device addr 
    // ----- region record begin ----- //
    DEV_HDR_U           m_region0_u;            // region 0: device header 
    BRLYT_U             m_region1_u;            // region 1: boot region layout 
    BRTTBL_U            m_region2_u;            // region 2: boot region translation table 
    HB_EPP_PARAM_U      m_region3_u;            // region 3: epp param 
    BPTTBL_U      		m_region4_u;            // region 4: bad-block and plane translation table
} HeaderBlock_Info;
#endif /*__DOWNLOAD_AGENT__*/

#endif /* NAND_MTD_FDM50_INTERNAL_H */
