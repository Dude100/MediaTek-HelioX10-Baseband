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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef FLASH_MTD_INTERNAL_H
#define FLASH_MTD_INTERNAL_H

#ifdef __NORFLASH_DEBUGMODE__
   #define DEBUG
#endif


/********************************************************/
/*                  Include Header Files                */
/********************************************************/

#include "kal_general_types.h"
#include "flash_opt.h"
#include "flash_mtd_ut.h"

/********************************************************/
/* AM29PDL128G (chip name) command address is different */
/* from others. It is MT6218B, MT6219_EVB, MT6217_EVB   */
/* default on board flash. if you want to use other     */
/* flash on MT6218B, MT6219_EVB, or MT6217_EVB, make    */
/* sure to invalidate the AM29PDL128G definition        */
/********************************************************/

#if ( defined(MT6218B_EVB) || defined(MT6219_EVB) || defined(MT6217_EVB) )
   #define AM29PDL128G
#endif

#ifndef AM29PDL128G
#define ADDR_UNLOCK_1        0x555
#define ADDR_UNLOCK_2        0x2AA
#else
#define ADDR_UNLOCK_1        0xAAA
#define ADDR_UNLOCK_2        0x555
#endif

#define ADDR_UNLOCK_MASK    0xFFFFF000

/********************************************************/
/*         Parameter and Function Decleration           */
/********************************************************/
typedef kal_uint16 FLASH_CELL;

/********************************************************/
/*                  Flash Command Definition            */
/********************************************************/


/*********************** AMD SERIES *********************/

#define TOGGLE_ERASE_SUSPEND 0x0004 // DQ2: toggles while the read address is erasing or erase suspending
#define TOGGLE_BUSY          0x0040 // DQ6: toggles while programming or erasing
#define POLL_BUSY            0x0080
#define POLL_TIMEOUT         0x0020
#define TOGGLE_TIMEOUT       0x0020 // DQ5: timeout, not a toggle (only valid while D6 is toggeling)
#define TOGGLE_BUFFER_ABORT  0x0002 // DQ1: buffer write abort, not a toggle (only valid while D6 is toggeling)
#define POLL_ERASE_START     0x0008 // DQ3: sector erase timer (only valid while D6 is toggeling)
#define CMD_RESET            0xF0
#define CMD_UNLOCK_1         0xAA
#define CMD_UNLOCK_2         0x55
#define CMD_UB               0x20
#define CMD_PROG             0xA0
#define CMD_WRITETOBUFFER    0x25
#define CMD_BUFFERTOFLASH    0x29
#define CMD_UB_RESET         0x90

// Sector Erase Command
#define CMD_SERASE           0x80
#define CMD_SERASE_END       0x30

// Sector Erase Suspend/Resume command
#define CMD_SUSP_SEC_ERASE   0xB0
#define CMD_RESU_SEC_ERASE   0x30

//DYB command (Dynamic Protection Bit Command)
#define CMD_DYB_ENTER 0xE0
#define CMD_DYB_ACT 0xA0
#define CMD_DYB_SET 0x0
#define CMD_DYB_CLR 0x1
#define CMD_DYB_EXIT1 0x90
#define CMD_DYB_EXIT2 0x0

#define DYB_LOCK 0
#define DYB_UNLOCK 1
/********************** SPANSION W/V-SR SERIES *********************/
#define WVSR_CMD_RD_SR 0x70  //Read Status Register
#define WVSR_CMD_CLR_SR 0x71  //Clear Status Register

//Status Register Definition
#define WVSR_PROGRAM_SUSPEND 0x04
#define WVSR_PROGRAM_ERROR_FLAG 0x10
#define WVSR_ERASE_ERROR_FLAG 0x20
#define WVSR_ERASE_SUSPEND 0x40
#define WVSR_READY_FLAG 0x80

#define WVSR_CMD_PROGRAM_SUSPEND 0x51
#define WVSR_CMD_PROGRAM_RESUME  0x50

#define WVSR_CMD_ERASE_SUSPEND CMD_SUSP_SEC_ERASE //0xB0
#define WVSR_CMD_ERASE_RESUME  CMD_RESU_SEC_ERASE //0x30

/********************** INTEL SERIES *********************/

//Read Command
#define INTEL_CMD_RD_ID 0x90     //Read Device ID or Configuration Register
#define INTEL_CMD_RD_ARRAY 0xff  //Read Array
#define INTEL_CMD_RD_SR 0x70     //Read Status Register
#define INTEL_CMD_CLR_SR 0x50;

//Erase Command
#define INTEL_CMD_ERASE_SETUP 0x20
#define INTEL_CMD_ERASE_CONFIRM 0xD0

//Program Command
#define INTEL_CMD_PGM_WORD 0x40
#define INTEL_CMD_BUF_PGM 0xE8;
#define INTEL_CMD_BUF_PGM_CNF 0xD0;

//Block Locking/Unlocking Command
#define INTEL_CMD_LOCK_SETUP 0x60
#define INTEL_CMD_LOCK 0x01
#define INTEL_CMD_UNLOCK 0xD0

//Suspend Command
#define INTEL_CMD_SUSPEND 0xB0
#define INTEL_CMD_RESUME 0xD0

//Status Register Definition
#define INTEL_READY_FLAG (0x80)
#define INTEL_ERASE_SUSPEND (0x40)
#define INTEL_PROGRAM_SUSPEND (0x04)
#define INTEL_ERASE_ERROR_FLAG (0x3A)
#define INTEL_PROGRAM_ERROR_FLAG (0x1A)

//Block Status
#define INTEL_BLOCK_LOCK_FLAG (0x03)

//Wait Function Definition
#define INTEL_WAIT_PROGRAM 0
#define INTEL_WAIT_ERASE 1
#define SIB_WAIT_BLANK_CHECK 2

/*********************** SIBLEY ***********************/


//Program Command
#define SIB_CMD_PGM_WORD 0x41
#define SIB_CMD_PGM_BUF_C1 0xE9
#define SIB_CMD_PGM_BUF_C2 0xD0

//Blank Check Command
#define SIB_CMD_BLANK_CK_C1 0xBC
#define SIB_CMD_BLANK_CK_C2 0xD0

//EFA Command
#define SIB_CMD_RD_EFA 0x94
#define SIB_CMD_PGM_EFA 0x44
#define SIB_CMD_ERASE_EFA 0x24
#define SIB_CMD_LOCKEFA_C1 0x64

//Configuration
#define SIB_CMD_PGM_CR_C1 0x60
#define SIB_CMD_PGM_RCR_C2 0x03
#define SIB_CMD_PGM_ECR_C2 0x04

//Status Register Definition
#define SIB_NOT_ALL_ERASED_FLAG (0x20)

/********************************************************/
#define INVALID_BLOCK_ADDR 0xFFFFFFFF


/********************************************************/
/*        Loop count for time measurement               */
/********************************************************/
//ToDo: avoid smart phone load to reference NOR MTD
#if (defined(__AMD_SERIES_NOR__) || defined(__SERIAL_FLASH__) )
#if defined(MCU_13M)
/* 1T ~= 77 ns */
#define COUNTER_50US (325)
#define COUNTER_20US (130)
#define COUNTER_15US (97)
#define COUNTER_10US (65)
#define COUNTER_05US (32)
#define COUNTER_350NS (3)

#elif defined(MCU_15_36M)
/* 1T ~= 65 ns */
#define COUNTER_50US (384)
#define COUNTER_20US (153)
#define COUNTER_15US (174)
#define COUNTER_10US (76)
#define COUNTER_05US (38)
#define COUNTER_350NS (4)

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
#define COUNTER_50US (658)
#define COUNTER_20US (263)
#define COUNTER_15US (197)
#define COUNTER_10US (132)
#define COUNTER_05US (66)
#define COUNTER_350NS (5)

#elif defined(MCU_30_72M)
/* 1T ~= 33 ns */
#define COUNTER_50US (757)
#define COUNTER_20US (303)
#define COUNTER_15US (227)
#define COUNTER_10US (151)
#define COUNTER_05US (75)
#define COUNTER_350NS (6)

#elif defined(MCU_39M)
/* 1T ~= 25 ns */
#define COUNTER_50US (1000)
#define COUNTER_20US (400)
#define COUNTER_15US (300)
#define COUNTER_10US (200)
#define COUNTER_05US (100)
#define COUNTER_350NS (7)

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
#define COUNTER_50US (1316)
#define COUNTER_20US (526)
#define COUNTER_15US (395)
#define COUNTER_10US (263)
#define COUNTER_05US (132)
#define COUNTER_350NS (10)

#elif defined(MCU_61_44M)
/* 1T ~= 16 ns */
#define COUNTER_50US (1563)
#define COUNTER_20US (625)
#define COUNTER_15US (468)
#define COUNTER_10US (312)
#define COUNTER_05US (156)
#define COUNTER_350NS (11)

#elif defined(MCU_68_714M)

#define COUNTER_50US (1761)
#define COUNTER_20US (704)
#define COUNTER_15US (528)
#define COUNTER_10US (1408)
#define COUNTER_05US (176)
#define COUNTER_350NS (13)

#elif defined(MCU_65M)
/* 1T ~= 15 ns */
#define COUNTER_50US (1666)
#define COUNTER_20US (666)
#define COUNTER_15US (500)
#define COUNTER_10US (333)
#define COUNTER_05US (166)
#define COUNTER_350NS (12)

#elif defined(MCU_78M)
/* 1T ~= 13 ns */
#define COUNTER_50US (1923)
#define COUNTER_20US (769)
#define COUNTER_15US (576)
#define COUNTER_10US (384)
#define COUNTER_05US (192)
#define COUNTER_350NS (13)

#elif defined(MCU_91M)
/* 1T ~= 11 ns */
#define COUNTER_50US (2272)
#define COUNTER_20US (909)
#define COUNTER_15US (681)
#define COUNTER_10US (454)
#define COUNTER_05US (227)
#define COUNTER_350NS (15)

#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
#define COUNTER_50US (2604)
#define COUNTER_20US (1042)
#define COUNTER_15US (781)
#define COUNTER_10US (521)
#define COUNTER_05US (260)
#define COUNTER_350NS (19)

#elif defined(MCU_122_88M)
/* 1T ~= 8.1 ns */
#define COUNTER_50US (3086)
#define COUNTER_20US (1235)
#define COUNTER_15US (925)
#define COUNTER_10US (617)
#define COUNTER_05US (308)
#define COUNTER_350NS (22)

#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
#define COUNTER_50US (5208)
#define COUNTER_20US (2084)
#define COUNTER_15US (1562)
#define COUNTER_10US (1042)
#define COUNTER_05US (520)
#define COUNTER_350NS (37)

#elif defined(MCU_245_76M)
/* 1T ~= 4.0 ns */
#define COUNTER_50US (6172)
#define COUNTER_20US (2470)
#define COUNTER_15US (1850)
#define COUNTER_10US (1234)
#define COUNTER_05US (616)
#define COUNTER_350NS (44)

#elif defined(MCU_260M)
/* 1T ~= 3.9 ns */
#define COUNTER_50US (6411)
#define COUNTER_20US (2564)
#define COUNTER_15US (1923)
#define COUNTER_10US (1282)
#define COUNTER_05US (641)
#define COUNTER_350NS (45)


#elif defined(MCU_312M)
/* 1T ~= 3.2 ns */
#define COUNTER_50US (7800)
#define COUNTER_20US (3120)
#define COUNTER_15US (2340)
#define COUNTER_10US (1560)
#define COUNTER_05US (780)
#define COUNTER_350NS (55)

#elif defined(MCU_416M)
/* 1T ~= 2.4 ns */
#define COUNTER_50US (10416)
#define COUNTER_20US (4168)
#define COUNTER_15US (1562)
#define COUNTER_10US (3124)
#define COUNTER_05US (1040)
#define COUNTER_350NS (74)

// Counter = CLK_RATE(M) * PERIOD(US) / 2 (a loop cost more than 2T)
// COUNTER_50US = 480*50/2 = 12000
#elif defined(MCU_480M)
#define COUNTER_50US (12000)
#define COUNTER_20US (4800)
#define COUNTER_15US (3600)
#define COUNTER_10US (2400)
#define COUNTER_05US (1200)
#define COUNTER_350NS (84)

#elif defined(MCU_570M)
#define COUNTER_50US (14250)
#define COUNTER_20US (5700)
#define COUNTER_15US (4275)
#define COUNTER_10US (2850)
#define COUNTER_05US (1425)
#define COUNTER_350NS (100)

#else

#error "Unsupported MCU clock rate for single bank support V2!"

#endif

#endif /* __AMD_SERIES_NOR__ || __SERIAL_FLASH__ */

/*-------------------------------------------------------
 * Time unit conversion
 *-------------------------------------------------------*/

/* TDMA qbit to us: qbit * 12 / 13 ~= (qbit * 237) / 2^8 */
#define ust_qbit_to_us(qbit)       (((qbit) * 237) >> 8)

/*-------------------------------------------------------
 * AMD-series flash specific definition
 *-------------------------------------------------------*/
#define MAX_AMD_ERASE_POLL_TIMES   (0x00FFFFFF)
#define MAX_AMD_PGM_POLL_TIMES     (0x000FFFFF)
#define NOR_DEFAULT_RESUME_TIME    (0xFFFFFFFF)

/*-------------------------------------------------------
 * Sleep mode support
 *-------------------------------------------------------*/
#define NOR_DEFAULT_RETURN_READY_LATENCY  (0xFFFFFFFF)

/*-------------------------------------------------------
 * NOR MTD error code
 *-------------------------------------------------------*/
typedef enum {
    NOR_MTD_NO_ERROR    = 0
   ,NOR_MTD_UNSUPPORTED_FUNCTION
   ,NOR_MTD_ERASE_FAIL
   ,NOR_MTD_ERASE_POLL_BUSY_FAIL
   ,NOR_MTD_ERASE_TIMEOUT
   ,NOR_MTD_ERASE_COMP_DATA_FAIL
   ,NOR_MTD_ERASE_COMP_BLOCK_DATA_FAIL
   ,NOR_MTD_PROGRAM_FAIL
   ,NOR_MTD_PROGRAM_TIMEOUT
   ,NOR_MTD_PROGRAM_COMP_DATA_FAIL
   ,NOR_MTD_PROGRAM_WRITE_BUFFER_FAIL
   ,NOR_MTD_SIGNATURE_UNMATCH
   ,NOR_MTD_DATA_CORRUPTED
   ,NOR_MTD_RAM_ROM_CONTENTS_UNMATCH
   ,NOR_MTD_BANK_REGION_INFO_UNMATCH
   ,NOR_MTD_ESB_BUSY_FLAG_MISMATCH   
   ,NOR_MTD_SF_NOT_QPI_MODE
   ,NOR_MTD_SF_WRITE_PROTECT_ERROR   
} NOR_Flash_Error_Code;

/*-------------------------------------------------------
 * Function Prototype
 *-------------------------------------------------------*/
void                   *BlockAddress(void* DriverData, kal_uint32 BlockIndex);
kal_uint32              BlockSize(void* DriverData, kal_uint32 BlockIndex);
kal_uint32              BlockIndex(void* DriverData, kal_uint32 blk_addr);
#ifdef __SPANSION_NS_N__
kal_uint32              CalBlkAddr(void* DriverData, kal_uint32 Addr);
#endif
void                   *MapWindow(void * DriveData, kal_uint32 BlockIndex, kal_uint32 WindowIndex);
extern kal_uint32       SaveAndSetIRQMask( void );
extern void             RestoreIRQMask( kal_uint32 );
extern kal_uint32       INT_DisableDataCache(void);
extern void             INT_RestoreDataCache(kal_uint32);
#if (defined(__AMD_SERIES_NOR__) || defined(__SECURITY_OTP__))
void                    DelayAWhile_UST(kal_uint32 delay);
#endif   /* __SPANSION_PL_N__ || __SECURITY_OTP__ */

/*-------------------------------------------------------
 * Assert information
 *-------------------------------------------------------*/

#if defined(__BASIC_LOAD_FLASH_TEST__) 
void                    MTD_GenerateAssertInfo(kal_uint32 err_code);
void                    MTD_PrintAssertInfo(void);
#else  // !__BASIC_LOAD_FLASH_TEST__
#define                 MTD_GenerateAssertInfo(e)
#define                 MTD_PrintAssertInfo()
#endif //__BASIC_LOAD_FLASH_TEST__

/*-------------------------------------------------------
 * Enhanced single bank specific
 *-------------------------------------------------------*/

#if defined(__SINGLE_BANK_NOR_FLASH_SUPPORT__)
/* Following functions are assumed to be atomic */
void                    Flash_ProgramData(void *target, void *src, kal_uint32 size);
void                    Flash_ResumeOperation(void);
void                    Flash_SuspendOperation(void);
kal_bool                Flash_CheckReady(void);

/*-------------------------------------------------------
 * MTD assert definition (ESB)
 *-------------------------------------------------------*/



// SNOR_MTD_ASSERT: general version
// MTD_SNOR_ASSERT: readable message version
#if defined(__UBL__)
#define SNOR_MTD_ASSERT(expr, e1, e2, e3)
#define MTD_SNOR_ASSERT(expr, e1, e2, e3, code)
#else
/* general version */
#define SNOR_MTD_ASSERT(expr, e1, e2, e3)\
   do{\
         if(!(expr))\
         {\
            Flash_ReturnReady();\
            ASSERT(0);\
         }\
     }while(0);
#define MTD_SNOR_ASSERT(expr, e1, e2, e3, code)\
   do{\
         if(!(expr))\
         {\
            MTD_GenerateAssertInfo(code);\
            Flash_ReturnReady();\
            MTD_PrintAssertInfo();\
            ASSERT(0);\
         }\
     }while(0);

#endif   /* __UBL__ */
#endif   /* __SINGLE_BANK_NOR_FLASH_SUPPORT__ */

/*-------------------------------------------------------
 * MTD assert definition (not ESB)
 *-------------------------------------------------------*/

/* readable message version */
#define MTD_ASSERT(expr, e1, e2, e3, code)\
   do{\
      if(!(expr))\
      {\
         MTD_GenerateAssertInfo(code);\
         MTD_PrintAssertInfo();\
         ASSERT(0);\
      }\
   }while(0);


/*******************************************************************************
 *  Marcro declaration
 *******************************************************************************/
#ifdef __MTK_TARGET__
   #ifndef __UBL__
      #ifdef __SINGLE_BANK_NOR_FLASH_SUPPORT__
         #define __SINGLE_BANK_NOR_FLASH_SUPPORT_PRAGMA__
      #endif
   #else // __UBL__
      #ifdef __NOR_FULL_DRIVER__
        #define __NOR_FULL_DRIVER_PRAGMA__
      #endif
   #endif
#endif

extern kal_uint32 gNonBlockingEraseBlockAddr;
#if defined(__UBL__) || defined(__FUE__) || (defined(__SMART_PHONE_PLATFORM__)&&defined(__SMART_PHONE_MODEM__))
#define waitNonBlockEraseDone()
#else
extern void waitNonBlockEraseDone(void);
#endif //__UBL__ || __FUE__


/*******************************************************************************
 *  Get IRQ Count
 *******************************************************************************/
#if defined(__UBL__) || defined(__FUE__)
// in bootloader or fota update engine, the system is single task, not need to monitor irq,
// so always return the same value
#define PROCESSING_IRQ_CNT 0
#else  // MAUI
extern volatile kal_uint32 processing_irqCnt;
#define PROCESSING_IRQ_CNT processing_irqCnt
#endif


/*******************************************************************************
 *  MTD internal functions
 *******************************************************************************/
kal_bool CompareData(void * Address, void * Data, kal_uint32 Length);


#if defined(NOR_FLASH_TYPE_SST) \
    || defined(NOR_FLASH_TYPE_ST_AMD_LIKE) \
    || defined(NOR_FLASH_TYPE_AMD_SERIES) \
    || defined(NOR_FLASH_TYPE_SPANSION_PL_J) \
    || defined(NOR_FLASH_TYPE_SPANSION_PL_N) \
    || defined(NOR_FLASH_TYPE_SPANSION_WS_N) \
    || defined(NOR_FLASH_TYPE_SPANSION_WS_P) \
    || defined(NOR_FLASH_TYPE_SPANSION_GL_A) \
    || defined(NOR_FLASH_TYPE_SPANSION_GL_N) \
    || defined(NOR_FLASH_TYPE_SPANSION_NS_N) \
    || defined(NOR_FLASH_TYPE_SPANSION_NS_P) \
    || defined(NOR_FLASH_TYPE_SPANSION_NS_J) \
    || defined(NOR_FLASH_TYPE_TOSHIBA) \
    || defined(NOR_FLASH_TYPE_SAMSUNG_SPANSION_NS_J_LIKE) \
    || defined(NOR_FLASH_TYPE_SPANSION_VS_R64)

#define __AMD_SERIES_NOR_PROGRAM__

#endif


#endif /* FLASH_MTD_INTERNAL_H */
