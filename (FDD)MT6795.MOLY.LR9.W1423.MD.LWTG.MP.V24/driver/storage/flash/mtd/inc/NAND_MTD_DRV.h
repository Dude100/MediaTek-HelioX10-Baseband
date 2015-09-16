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
 *  NAND_MTD_DRV.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This is a NFIC driver  for MTD layer
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
 *
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
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NAND_MTD_DRV_H
#define NAND_MTD_DRV_H

#if !defined(CORTEXA7)
#include "kal_general_types.h"
#include "NAND_DevConfig.h"
#include "NAND_MTD_FDM50_internal.h" 

#include "reg_base.h"
#include "cache_sw.h"
#include "cp15.h"
#else
// reg_base.h
#define	BASE_ADDR_NFI_AP				(0xBE230000)
#define	BASE_ADDR_NFIECC_AP				(0xBE230000)
#endif

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
 * Local Definitions
 *******************************************************************************/
#if defined(__DOWNLOAD_AGENT__) /*downloadAgent case*/
extern void da_printf(const char *form, ...);
extern void da_sprintf(char *buf, const char *form, ...);
#define dbg_print da_printf
#define kal_sprintf da_sprintf
#elif defined(CORTEXA7) /*AP case*/
#define dbg_print(var ...) MSG(MSG_INFO, ##var)
#elif defined(__UBL__) /*bootloader  case*/
extern void dbg_print(kal_char *fmt, ...);
#else
extern void dbg_print(kal_char *fmt, ...);
#endif

/*
 ****** Definition of dbg_ASSERT and force_ASSERT ******
 dbg_ASSERT:
		  - For basic load prevalidation use. The code is used for RD debug.
 force_ASSERT:
		  - For normal check, if those parameters are incorrect, system will fail.
		  - We expect it should be found in the earlier stage.
*/

#if ( defined(__NAND_FLASH_HARDWARE_TEST__) && defined(__MAUI_BASIC__))
    #if defined(__UBL__) || defined(__DOWNLOAD_AGENT__) /*bootloader & downloadAgent case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
		#elif defined(__DOWNLOAD_AGENT__) /*downloadAgent case*/
			#define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);FinishCmd();}}
        #else	
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
    #else
        #define dbg_ASSERT(expr) ASSERT(expr)
    #endif
#else
    #if defined(__UBL__) /*bootloader  case*/
        #if defined BL_DEBUG
            #define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);while(1); }}
        #else
            #define dbg_ASSERT(expr) {do { } while (0);}
        #endif
	#elif defined(__DOWNLOAD_AGENT__) /*downloadAgent case*/
		#define dbg_ASSERT(expr) {if(!(expr)) {dbg_print("dbg_ASSERT:%s line:%d\n",__FILE__,__LINE__);FinishCmd();}}
    #else
        #define dbg_ASSERT(expr) {do { } while (0);}
    #endif
#endif

#if defined(__UBL__) /*bootloader  case*/
	#define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);while(1);}}
#elif defined(__DOWNLOAD_AGENT__) /*downloadAgent case*/	
	#define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);FinishCmd();}}
#else
	#define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif

/*******************************************************************************
 * define
 *******************************************************************************/
#define NFI_CACHE_ALIGNED		__attribute__((aligned(CPU_CACHE_LINE_SIZE)))

// For solving set-but-not-used compiler warning
#define NFI_NAND_RM_WARNING(x) 	if (x) {}

#if defined(__SECURITY_OTP__)
#define NFI_FCD_MAX_NUM         (30)
#else
#define NFI_FCD_MAX_NUM         (20)
#endif
#define NFI_FCD_MAX_SIZE		(NFI_FCD_MAX_NUM * sizeof(nfi_fcd_type_t))
#define NFI_FEATURE_CODE_SIZE	(CPU_CACHE_LINE_SIZE * 2)

#define SECTOR_SIZE				NAND_SECTOR_SIZE

/*******************************************************************************
 * Nfi_md.h & Nfiecc_md.h
 *******************************************************************************/
#define REG_NFI_MD_R_NFI_MD_CODA_VERSION	(BASE_ADDR_NFI_MD+0x0)
#define REG_NFI_MD_R_NFI_CNFG_MD	(BASE_ADDR_NFI_MD+0x4)
#define REG_NFI_MD_R_NFI_PAGEFMT_MD	(BASE_ADDR_NFI_MD+0x8)
#define REG_NFI_MD_R_NFI_CON_MD	(BASE_ADDR_NFI_MD+0xC)
#define REG_NFI_MD_R_NFI_ACCCON_MD	(BASE_ADDR_NFI_MD+0x10)
#define REG_NFI_MD_R_NFI_INTR_EN_MD	(BASE_ADDR_NFI_MD+0x14)
#define REG_NFI_MD_R_NFI_INTR_MD	(BASE_ADDR_NFI_MD+0x18)
#define REG_NFI_MD_R_NFI_INTR_CLR_MD	(BASE_ADDR_NFI_MD+0x1C)
#define REG_NFI_MD_R_NFI_BATCH_MD	(BASE_ADDR_NFI_MD+0x20)
#define REG_NFI_MD_R_NFI_LOC_MD	(BASE_ADDR_NFI_MD+0x24)
#define REG_NFI_MD_R_NFI_CMD	(BASE_ADDR_NFI_MD+0x28)
#define REG_NFI_MD_R_NFI_ADDRNOB	(BASE_ADDR_NFI_MD+0x2C)
#define REG_NFI_MD_R_NFI_COLADDR	(BASE_ADDR_NFI_MD+0x30)
#define REG_NFI_MD_R_NFI_ROWADDR	(BASE_ADDR_NFI_MD+0x34)
#define REG_NFI_MD_R_NFI_STRDATA	(BASE_ADDR_NFI_MD+0x38)
#define REG_NFI_MD_R_NFI_DATAW	(BASE_ADDR_NFI_MD+0x3C)
#define REG_NFI_MD_R_NFI_DATAR	(BASE_ADDR_NFI_MD+0x40)
#define REG_NFI_MD_R_NFI_STA	(BASE_ADDR_NFI_MD+0x44)
#define REG_NFI_MD_R_NFI_FIFOSTA	(BASE_ADDR_NFI_MD+0x48)
#define REG_NFI_MD_R_NFI_LOCKSTA	(BASE_ADDR_NFI_MD+0x4C)
#define REG_NFI_MD_R_NFI_ADDRCNTR	(BASE_ADDR_NFI_MD+0x50)
#define REG_NFI_MD_R_NFI_STRADDR	(BASE_ADDR_NFI_MD+0x54)
#define REG_NFI_MD_R_NFI_BYTELEN	(BASE_ADDR_NFI_MD+0x58)
#define REG_NFI_MD_R_NFI_CSEL	(BASE_ADDR_NFI_MD+0x5C)
#define REG_NFI_MD_R_NFI_FDM0L	(BASE_ADDR_NFI_MD+0x60)
#define REG_NFI_MD_R_NFI_FDM0M	(BASE_ADDR_NFI_MD+0x64)
#define REG_NFI_MD_R_NFI_FDM1L	(BASE_ADDR_NFI_MD+0x68)
#define REG_NFI_MD_R_NFI_FDM1M	(BASE_ADDR_NFI_MD+0x6C)
#define REG_NFI_MD_R_NFI_FDM2L	(BASE_ADDR_NFI_MD+0x70)
#define REG_NFI_MD_R_NFI_FDM2M	(BASE_ADDR_NFI_MD+0x74)
#define REG_NFI_MD_R_NFI_FDM3L	(BASE_ADDR_NFI_MD+0x78)
#define REG_NFI_MD_R_NFI_FDM3M	(BASE_ADDR_NFI_MD+0x7C)
#define REG_NFI_MD_R_NFI_FDM4L	(BASE_ADDR_NFI_MD+0x80)
#define REG_NFI_MD_R_NFI_FDM4M	(BASE_ADDR_NFI_MD+0x84)
#define REG_NFI_MD_R_NFI_FDM5L	(BASE_ADDR_NFI_MD+0x88)
#define REG_NFI_MD_R_NFI_FDM5M	(BASE_ADDR_NFI_MD+0x8C)
#define REG_NFI_MD_R_NFI_FDM6L	(BASE_ADDR_NFI_MD+0x90)
#define REG_NFI_MD_R_NFI_FDM6M	(BASE_ADDR_NFI_MD+0x94)
#define REG_NFI_MD_R_NFI_FDM7L	(BASE_ADDR_NFI_MD+0x98)
#define REG_NFI_MD_R_NFI_FDM7M	(BASE_ADDR_NFI_MD+0x9C)
#define REG_NFI_MD_R_NFI_LOCK_EN	(BASE_ADDR_NFI_MD+0xA0)
#define REG_NFI_MD_R_NFI_LOCK	(BASE_ADDR_NFI_MD+0xA4)
#define REG_NFI_MD_R_NFI_LOCKANOB	(BASE_ADDR_NFI_MD+0xA8)
#define REG_NFI_MD_R_NFI_LOCK00ADD	(BASE_ADDR_NFI_MD+0xAC)
#define REG_NFI_MD_R_NFI_LOCK00FMT	(BASE_ADDR_NFI_MD+0xB0)
#define REG_NFI_MD_R_NFI_LOCK01ADD	(BASE_ADDR_NFI_MD+0xB4)
#define REG_NFI_MD_R_NFI_LOCK01FMT	(BASE_ADDR_NFI_MD+0xB8)
#define REG_NFI_MD_R_NFI_LOCK02ADD	(BASE_ADDR_NFI_MD+0xBC)
#define REG_NFI_MD_R_NFI_LOCK02FMT	(BASE_ADDR_NFI_MD+0xC0)
#define REG_NFI_MD_R_NFI_LOCK03ADD	(BASE_ADDR_NFI_MD+0xC4)
#define REG_NFI_MD_R_NFI_LOCK03FMT	(BASE_ADDR_NFI_MD+0xC8)
#define REG_NFI_MD_R_NFI_LOCK04ADD	(BASE_ADDR_NFI_MD+0xCC)
#define REG_NFI_MD_R_NFI_LOCK04FMT	(BASE_ADDR_NFI_MD+0xD0)
#define REG_NFI_MD_R_NFI_LOCK05ADD	(BASE_ADDR_NFI_MD+0xD4)
#define REG_NFI_MD_R_NFI_LOCK05FMT	(BASE_ADDR_NFI_MD+0xD8)
#define REG_NFI_MD_R_NFI_LOCK06ADD	(BASE_ADDR_NFI_MD+0xDC)
#define REG_NFI_MD_R_NFI_LOCK06FMT	(BASE_ADDR_NFI_MD+0xE0)
#define REG_NFI_MD_R_NFI_LOCK07ADD	(BASE_ADDR_NFI_MD+0xE4)
#define REG_NFI_MD_R_NFI_LOCK07FMT	(BASE_ADDR_NFI_MD+0xE8)
#define REG_NFI_MD_R_NFI_LOCK08ADD	(BASE_ADDR_NFI_MD+0xEC)
#define REG_NFI_MD_R_NFI_LOCK08FMT	(BASE_ADDR_NFI_MD+0xF0)
#define REG_NFI_MD_R_NFI_LOCK09ADD	(BASE_ADDR_NFI_MD+0xF4)
#define REG_NFI_MD_R_NFI_LOCK09FMT	(BASE_ADDR_NFI_MD+0xF8)
#define REG_NFI_MD_R_NFI_LOCK10ADD	(BASE_ADDR_NFI_MD+0xFC)
#define REG_NFI_MD_R_NFI_LOCK10FMT	(BASE_ADDR_NFI_MD+0x100)
#define REG_NFI_MD_R_NFI_LOCK11ADD	(BASE_ADDR_NFI_MD+0x104)
#define REG_NFI_MD_R_NFI_LOCK11FMT	(BASE_ADDR_NFI_MD+0x108)
#define REG_NFI_MD_R_NFI_LOCK12ADD	(BASE_ADDR_NFI_MD+0x10C)
#define REG_NFI_MD_R_NFI_LOCK12FMT	(BASE_ADDR_NFI_MD+0x110)
#define REG_NFI_MD_R_NFI_LOCK13ADD	(BASE_ADDR_NFI_MD+0x114)
#define REG_NFI_MD_R_NFI_LOCK13FMT	(BASE_ADDR_NFI_MD+0x118)
#define REG_NFI_MD_R_NFI_LOCK14ADD	(BASE_ADDR_NFI_MD+0x11C)
#define REG_NFI_MD_R_NFI_LOCK14FMT	(BASE_ADDR_NFI_MD+0x120)
#define REG_NFI_MD_R_NFI_LOCK15ADD	(BASE_ADDR_NFI_MD+0x124)
#define REG_NFI_MD_R_NFI_LOCK15FMT	(BASE_ADDR_NFI_MD+0x128)
#define REG_NFI_MD_R_NFI_FIFO_DATA0	(BASE_ADDR_NFI_MD+0x12C)
#define REG_NFI_MD_R_NFI_FIFO_DATA1	(BASE_ADDR_NFI_MD+0x130)
#define REG_NFI_MD_R_NFI_FIFO_DATA2	(BASE_ADDR_NFI_MD+0x134)
#define REG_NFI_MD_R_NFI_FIFO_DATA3	(BASE_ADDR_NFI_MD+0x138)
#define REG_NFI_MD_R_NFI_BATCH_MODE	(BASE_ADDR_NFI_MD+0x13C)
#define REG_NFI_MD_R_NFI_TIMEOUT	(BASE_ADDR_NFI_MD+0x140)
#define REG_NFI_MD_R_NFI_FCD_STAT_MD	(BASE_ADDR_NFI_MD+0x144)
#define REG_NFI_MD_R_NFI_BATCH_CMD_STATUS_MD	(BASE_ADDR_NFI_MD+0x148)
#define REG_NFI_MD_R_NFI_NLI_CTRL	(BASE_ADDR_NFI_MD+0x14C)
#define REG_NFI_MD_R_NFI_MD_DUMMY_REG0	(BASE_ADDR_NFI_MD+0x150)

#define REG_NFIECC_MD_R_NFIECC_MD_CODA_VERSION	(BASE_ADDR_NFIECC_MD+0x2000)
#define REG_NFIECC_MD_R_NFIECC_ENCCON_MD	(BASE_ADDR_NFIECC_MD+0x2004)
#define REG_NFIECC_MD_R_NFIECC_ENCCNFG_MD	(BASE_ADDR_NFIECC_MD+0x2008)
#define REG_NFIECC_MD_R_NFIECC_ENCPAR0_MD	(BASE_ADDR_NFIECC_MD+0x200C)
#define REG_NFIECC_MD_R_NFIECC_ENCPAR1_MD	(BASE_ADDR_NFIECC_MD+0x2010)
#define REG_NFIECC_MD_R_NFIECC_ENCPAR2_MD	(BASE_ADDR_NFIECC_MD+0x2014)
#define REG_NFIECC_MD_R_NFIECC_ENCPAR3_MD	(BASE_ADDR_NFIECC_MD+0x2018)
#define REG_NFIECC_MD_R_NFIECC_ENCPAR4_MD	(BASE_ADDR_NFIECC_MD+0x201C)
#define REG_NFIECC_MD_R_NFIECC_ENCIRQEN_MD	(BASE_ADDR_NFIECC_MD+0x2020)
#define REG_NFIECC_MD_R_NFIECC_ENCIRQSTA_MD	(BASE_ADDR_NFIECC_MD+0x2024)
#define REG_NFIECC_MD_R_NFIECC_ENCIRQCLR_MD	(BASE_ADDR_NFIECC_MD+0x2028)
#define REG_NFIECC_MD_R_NFIECC_DECCON_MD	(BASE_ADDR_NFIECC_MD+0x202C)
#define REG_NFIECC_MD_R_NFIECC_DECCNFG_MD	(BASE_ADDR_NFIECC_MD+0x2030)
#define REG_NFIECC_MD_R_NFIECC_DECFER_MD	(BASE_ADDR_NFIECC_MD+0x2034)
#define REG_NFIECC_MD_R_NFIECC_DECENUM_MD	(BASE_ADDR_NFIECC_MD+0x2038)
#define REG_NFIECC_MD_R_NFIECC_DECDONE_MD	(BASE_ADDR_NFIECC_MD+0x203C)
#define REG_NFIECC_MD_R_NFIECC_DECEL0_MD	(BASE_ADDR_NFIECC_MD+0x2040)
#define REG_NFIECC_MD_R_NFIECC_DECEL1_MD	(BASE_ADDR_NFIECC_MD+0x2044)
#define REG_NFIECC_MD_R_NFIECC_DECEL2_MD	(BASE_ADDR_NFIECC_MD+0x2048)
#define REG_NFIECC_MD_R_NFIECC_DECEL3_MD	(BASE_ADDR_NFIECC_MD+0x204C)
#define REG_NFIECC_MD_R_NFIECC_DECEL4_MD	(BASE_ADDR_NFIECC_MD+0x2050)
#define REG_NFIECC_MD_R_NFIECC_DECEL5_MD	(BASE_ADDR_NFIECC_MD+0x2054)
#define REG_NFIECC_MD_R_NFIECC_DECIRQEN_MD	(BASE_ADDR_NFIECC_MD+0x2058)
#define REG_NFIECC_MD_R_NFIECC_DECIRQSTA_MD	(BASE_ADDR_NFIECC_MD+0x205C)
#define REG_NFIECC_MD_R_NFIECC_DECIRQCLR_MD	(BASE_ADDR_NFIECC_MD+0x2060)
#define REG_NFIECC_MD_R_NFIECC_FDMADDR_MD	(BASE_ADDR_NFIECC_MD+0x2064)
#define REG_NFIECC_MD_R_NFIECC_ENCDIADDR	(BASE_ADDR_NFIECC_MD+0x2068)
#define REG_NFIECC_MD_R_NFIECC_DECDIADDR	(BASE_ADDR_NFIECC_MD+0x206C)
#define REG_NFIECC_MD_R_NFIECC_ENCIDLE	(BASE_ADDR_NFIECC_MD+0x2070)
#define REG_NFIECC_MD_R_NFIECC_ENCSTA	(BASE_ADDR_NFIECC_MD+0x2074)
#define REG_NFIECC_MD_R_NFIECC_DECIDLE	(BASE_ADDR_NFIECC_MD+0x2078)
#define REG_NFIECC_MD_R_NFIECC_DECFSM	(BASE_ADDR_NFIECC_MD+0x207C)
#define REG_NFIECC_MD_R_NFIECC_SYNSTA	(BASE_ADDR_NFIECC_MD+0x2080)
#define REG_NFIECC_MD_R_NFIECC_DECNFIDI	(BASE_ADDR_NFIECC_MD+0x2084)
#define REG_NFIECC_MD_R_NFIECC_SYN0	(BASE_ADDR_NFIECC_MD+0x2088)
#define REG_NFIECC_MD_R_NFIECC_MD_DUMMY_REG0	(BASE_ADDR_NFIECC_MD+0x208C)

/*******************************************************************************
 * Nfi_ap.h & Nfiecc_ap.h
 *******************************************************************************/
#define REG_NFI_AP_R_NFI_AP_CODA_VERSION	(BASE_ADDR_NFI_AP+0x4000)
#define REG_NFI_AP_R_NFI_CNFG_AP	(BASE_ADDR_NFI_AP+0x4004)
#define REG_NFI_AP_R_NFI_PAGEFMT_AP	(BASE_ADDR_NFI_AP+0x4008)
#define REG_NFI_AP_R_NFI_CON_AP	(BASE_ADDR_NFI_AP+0x400C)
#define REG_NFI_AP_R_NFI_INTR_EN_AP	(BASE_ADDR_NFI_AP+0x4010)
#define REG_NFI_AP_R_NFI_INTR_AP	(BASE_ADDR_NFI_AP+0x4014)
#define REG_NFI_AP_R_NFI_INTR_CLR_AP	(BASE_ADDR_NFI_AP+0x4018)
#define REG_NFI_AP_R_NFI_BATCH_AP	(BASE_ADDR_NFI_AP+0x401C)
#define REG_NFI_AP_R_NFI_LOC_AP	(BASE_ADDR_NFI_AP+0x4020)
#define REG_NFI_AP_R_NFI_STA_AP	(BASE_ADDR_NFI_AP+0x4024)
#define REG_NFI_AP_R_NFI_FIFOSTA_AP	(BASE_ADDR_NFI_AP+0x4028)
#define REG_NFI_AP_R_NFI_LOCKSTA_AP	(BASE_ADDR_NFI_AP+0x402C)
#define REG_NFI_AP_R_NFI_ADDRCNTR_AP	(BASE_ADDR_NFI_AP+0x4030)
#define REG_NFI_AP_R_NFI_AP_STRADDR_AP	(BASE_ADDR_NFI_AP+0x4034)
#define REG_NFI_AP_R_NFI_BYTELEN_AP	(BASE_ADDR_NFI_AP+0x4038)
#define REG_NFI_AP_R_NFI_AP_FDM0L	(BASE_ADDR_NFI_AP+0x403C)
#define REG_NFI_AP_R_NFI_AP_FDM0M	(BASE_ADDR_NFI_AP+0x4040)
#define REG_NFI_AP_R_NFI_AP_FDM1L	(BASE_ADDR_NFI_AP+0x4044)
#define REG_NFI_AP_R_NFI_AP_FDM1M	(BASE_ADDR_NFI_AP+0x4048)
#define REG_NFI_AP_R_NFI_AP_FDM2L	(BASE_ADDR_NFI_AP+0x404C)
#define REG_NFI_AP_R_NFI_AP_FDM2M	(BASE_ADDR_NFI_AP+0x4050)
#define REG_NFI_AP_R_NFI_AP_FDM3L	(BASE_ADDR_NFI_AP+0x4054)
#define REG_NFI_AP_R_NFI_AP_FDM3M	(BASE_ADDR_NFI_AP+0x4058)
#define REG_NFI_AP_R_NFI_AP_FDM4L	(BASE_ADDR_NFI_AP+0x405C)
#define REG_NFI_AP_R_NFI_AP_FDM4M	(BASE_ADDR_NFI_AP+0x4060)
#define REG_NFI_AP_R_NFI_AP_FDM5L	(BASE_ADDR_NFI_AP+0x4064)
#define REG_NFI_AP_R_NFI_AP_FDM5M	(BASE_ADDR_NFI_AP+0x4068)
#define REG_NFI_AP_R_NFI_AP_FDM6L	(BASE_ADDR_NFI_AP+0x406C)
#define REG_NFI_AP_R_NFI_AP_FDM6M	(BASE_ADDR_NFI_AP+0x4070)
#define REG_NFI_AP_R_NFI_AP_FDM7L	(BASE_ADDR_NFI_AP+0x4074)
#define REG_NFI_AP_R_NFI_AP_FDM7M	(BASE_ADDR_NFI_AP+0x4078)
#define REG_NFI_AP_R_NFI_FIFO_DATA0_AP	(BASE_ADDR_NFI_AP+0x407C)
#define REG_NFI_AP_R_NFI_FIFO_DATA1_AP	(BASE_ADDR_NFI_AP+0x4080)
#define REG_NFI_AP_R_NFI_FIFO_DATA2_AP	(BASE_ADDR_NFI_AP+0x4084)
#define REG_NFI_AP_R_NFI_FIFO_DATA3_AP	(BASE_ADDR_NFI_AP+0x4088)
#define REG_NFI_AP_R_NFI_FCD_STAT_AP	(BASE_ADDR_NFI_AP+0x408C)
#define REG_NFI_AP_R_NFI_BATCH_CMD_STATUS_AP	(BASE_ADDR_NFI_AP+0x4090)
#define REG_NFI_AP_R_NFI_AP_DUMMY0	(BASE_ADDR_NFI_AP+0x4094)
#define REG_NFI_AP_R_NFI_NLI_CTRL_AP	(BASE_ADDR_NFI_AP+0x4098)

#define REG_NFIECC_AP_R_NFIECC_AP_CODA_VERSION	(BASE_ADDR_NFIECC_AP+0x6000)
#define REG_NFIECC_AP_R_NFIECC_ENCCON_AP	(BASE_ADDR_NFIECC_AP+0x6004)
#define REG_NFIECC_AP_R_NFIECC_ENCCNFG_AP	(BASE_ADDR_NFIECC_AP+0x6008)
#define REG_NFIECC_AP_R_NFIECC_ENCPAR0_AP	(BASE_ADDR_NFIECC_AP+0x600C)
#define REG_NFIECC_AP_R_NFIECC_ENCPAR1_AP	(BASE_ADDR_NFIECC_AP+0x6010)
#define REG_NFIECC_AP_R_NFIECC_ENCPAR2_AP	(BASE_ADDR_NFIECC_AP+0x6014)
#define REG_NFIECC_AP_R_NFIECC_ENCPAR3_AP	(BASE_ADDR_NFIECC_AP+0x6018)
#define REG_NFIECC_AP_R_NFIECC_ENCPAR4_AP	(BASE_ADDR_NFIECC_AP+0x601C)
#define REG_NFIECC_AP_R_NFIECC_ENCIRQEN_AP	(BASE_ADDR_NFIECC_AP+0x6020)
#define REG_NFIECC_AP_R_NFIECC_ENCIRQSTA_AP	(BASE_ADDR_NFIECC_AP+0x6024)
#define REG_NFIECC_AP_R_NFIECC_ENCIRQCLR_AP	(BASE_ADDR_NFIECC_AP+0x6028)
#define REG_NFIECC_AP_R_NFIECC_DECCON_AP	(BASE_ADDR_NFIECC_AP+0x602C)
#define REG_NFIECC_AP_R_NFIECC_DECCNFG_AP	(BASE_ADDR_NFIECC_AP+0x6030)
#define REG_NFIECC_AP_R_NFIECC_DECFER_AP	(BASE_ADDR_NFIECC_AP+0x6034)
#define REG_NFIECC_AP_R_NFIECC_DECENUM_AP	(BASE_ADDR_NFIECC_AP+0x6038)
#define REG_NFIECC_AP_R_NFIECC_DECDONE_AP	(BASE_ADDR_NFIECC_AP+0x603C)
#define REG_NFIECC_AP_R_NFIECC_DECEL0_AP	(BASE_ADDR_NFIECC_AP+0x6040)
#define REG_NFIECC_AP_R_NFIECC_DECEL1_AP	(BASE_ADDR_NFIECC_AP+0x6044)
#define REG_NFIECC_AP_R_NFIECC_DECEL2_AP	(BASE_ADDR_NFIECC_AP+0x6048)
#define REG_NFIECC_AP_R_NFIECC_DECEL3_AP	(BASE_ADDR_NFIECC_AP+0x604C)
#define REG_NFIECC_AP_R_NFIECC_DECEL4_AP	(BASE_ADDR_NFIECC_AP+0x6050)
#define REG_NFIECC_AP_R_NFIECC_DECEL5_AP	(BASE_ADDR_NFIECC_AP+0x6054)
#define REG_NFIECC_AP_R_NFIECC_DECIRQEN_AP	(BASE_ADDR_NFIECC_AP+0x6058)
#define REG_NFIECC_AP_R_NFIECC_DECIRQSTA_AP	(BASE_ADDR_NFIECC_AP+0x605C)
#define REG_NFIECC_AP_R_NFIECC_DECIRQCLR_AP	(BASE_ADDR_NFIECC_AP+0x6060)
#define REG_NFIECC_AP_R_NFIECC_FDMADDR_AP	(BASE_ADDR_NFIECC_AP+0x6064)
#define REG_NFIECC_AP_R_NFIECC_ENCIDLE	(BASE_ADDR_NFIECC_AP+0x6068)
#define REG_NFIECC_AP_R_NFIECC_ENCSTA	(BASE_ADDR_NFIECC_AP+0x606C)
#define REG_NFIECC_AP_R_NFIECC_DECIDLE	(BASE_ADDR_NFIECC_AP+0x6070)
#define REG_NFIECC_AP_R_NFIECC_DECFSM	(BASE_ADDR_NFIECC_AP+0x6074)
#define REG_NFIECC_AP_R_NFIECC_SYNSTA	(BASE_ADDR_NFIECC_AP+0x6078)
#define REG_NFIECC_AP_R_NFIECC_DECNFIDI	(BASE_ADDR_NFIECC_AP+0x607C)
#define REG_NFIECC_AP_R_NFIECC_SYN0	(BASE_ADDR_NFIECC_AP+0x6080)
#define REG_NFIECC_AP_R_NFIECC_AP_DUMMY0	(BASE_ADDR_NFIECC_AP+0x6084)

/*******************************************************************************
 * Nfi_drv_hw.h
 *******************************************************************************/
#if defined(__CR4__)
// MD-NFI
#define REG_NFI_CODA_VERSION         (REG_NFI_MD_R_NFI_MD_CODA_VERSION)
#define REG_NFI_CNFG             (REG_NFI_MD_R_NFI_CNFG_MD)
#define REG_NFI_PAGEFMT          (REG_NFI_MD_R_NFI_PAGEFMT_MD)
#define REG_NFI_CON              (REG_NFI_MD_R_NFI_CON_MD)
#define REG_NFI_ACCCON           (REG_NFI_MD_R_NFI_ACCCON_MD)
#define REG_NFI_INTR_EN          (REG_NFI_MD_R_NFI_INTR_EN_MD)
#define REG_NFI_INTR             (REG_NFI_MD_R_NFI_INTR_MD)
#define REG_NFI_INTR_CLR         (REG_NFI_MD_R_NFI_INTR_CLR_MD)
#define REG_NFI_BATCH            (REG_NFI_MD_R_NFI_BATCH_MD)
#define REG_NFI_LOC              (REG_NFI_MD_R_NFI_LOC_MD)
#define REG_NFI_CMD              (REG_NFI_MD_R_NFI_CMD)
#define REG_NFI_ADDRNOB          (REG_NFI_MD_R_NFI_ADDRNOB)
#define REG_NFI_COLADDR          (REG_NFI_MD_R_NFI_COLADDR)
#define REG_NFI_ROWADDR          (REG_NFI_MD_R_NFI_ROWADDR)
#define REG_NFI_STRDATA          (REG_NFI_MD_R_NFI_STRDATA)
#define REG_NFI_DATAW            (REG_NFI_MD_R_NFI_DATAW)
#define REG_NFI_DATAR            (REG_NFI_MD_R_NFI_DATAR)
#define REG_NFI_STA              (REG_NFI_MD_R_NFI_STA)
#define REG_NFI_FIFOSTA          (REG_NFI_MD_R_NFI_FIFOSTA)
#define REG_NFI_LOCKSTA          (REG_NFI_MD_R_NFI_LOCKSTA)
#define REG_NFI_ADDRCNTR         (REG_NFI_MD_R_NFI_ADDRCNTR)
#define REG_NFI_STRADDR          (REG_NFI_MD_R_NFI_STRADDR)
#define REG_NFI_BYTELEN          (REG_NFI_MD_R_NFI_BYTELEN)
#define REG_NFI_CSEL             (REG_NFI_MD_R_NFI_CSEL)
#define REG_NFI_FDML(n)            (REG_NFI_MD_R_NFI_FDM0L+(n<<3))
#define REG_NFI_FDMM(n)            (REG_NFI_MD_R_NFI_FDM0M+(n<<3))
#define REG_NFI_LOCK_EN          (REG_NFI_MD_R_NFI_LOCK_EN)
#define REG_NFI_LOCK             (REG_NFI_MD_R_NFI_LOCK)
#define REG_NFI_LOCKANOB         (REG_NFI_MD_R_NFI_LOCKANOB)
#define REG_NFI_LOCKADD(n)        (REG_NFI_MD_R_NFI_LOCK00ADD+(n<<3))
#define REG_NFI_LOCKFMT(n)        (REG_NFI_MD_R_NFI_LOCK00FMT+(n<<3))
#define REG_NFI_FIFO_DATA(n)       (REG_NFI_MD_R_NFI_FIFO_DATA0+(n<<2))
#define REG_NFI_BATCH_MODE       (REG_NFI_MD_R_NFI_BATCH_MODE)
#define REG_NFI_TIMEOUT          (REG_NFI_MD_R_NFI_TIMEOUT)
#define REG_NFI_FCD_STAT         (REG_NFI_MD_R_NFI_FCD_STAT_MD)
#define REG_NFI_BATCH_CMD_STATUS (REG_NFI_MD_R_NFI_BATCH_CMD_STATUS_MD)
#define REG_NFI_NLI_CTRL         (REG_NFI_MD_R_NFI_NLI_CTRL)
#define REG_NFI_DUMMY_REG         (REG_NFI_MD_R_NFI_MD_DUMMY_REG0)
// MD-NFIECC
#define REG_NFIECC_CODA_VERSION  (REG_NFIECC_MD_R_NFIECC_MD_CODA_VERSION)
#define REG_NFIECC_ENCCON        (REG_NFIECC_MD_R_NFIECC_ENCCON_MD)	
#define REG_NFIECC_ENCCNFG       (REG_NFIECC_MD_R_NFIECC_ENCCNFG_MD)	
#define REG_NFIECC_ENCPAR(n)       (REG_NFIECC_MD_R_NFIECC_ENCPAR0_MD+(n<<2))	
#define REG_NFIECC_ENCIRQEN      (REG_NFIECC_MD_R_NFIECC_ENCIRQEN_MD)	
#define REG_NFIECC_ENCIRQSTA     (REG_NFIECC_MD_R_NFIECC_ENCIRQSTA_MD)
#define REG_NFIECC_ENCIRQCLR     (REG_NFIECC_MD_R_NFIECC_ENCIRQCLR_MD)
#define REG_NFIECC_DECCON        (REG_NFIECC_MD_R_NFIECC_DECCON_MD)	
#define REG_NFIECC_DECCNFG       (REG_NFIECC_MD_R_NFIECC_DECCNFG_MD)	
#define REG_NFIECC_DECFER        (REG_NFIECC_MD_R_NFIECC_DECFER_MD)	
#define REG_NFIECC_DECENUM       (REG_NFIECC_MD_R_NFIECC_DECENUM_MD)	
#define REG_NFIECC_DECDONE       (REG_NFIECC_MD_R_NFIECC_DECDONE_MD)	
#define REG_NFIECC_DECEL(n)        (REG_NFIECC_MD_R_NFIECC_DECEL0_MD+(n<<2))
#define REG_NFIECC_DECIRQEN      (REG_NFIECC_MD_R_NFIECC_DECIRQEN_MD)	
#define REG_NFIECC_DECIRQSTA     (REG_NFIECC_MD_R_NFIECC_DECIRQSTA_MD)
#define REG_NFIECC_DECIRQCLR     (REG_NFIECC_MD_R_NFIECC_DECIRQCLR_MD)
#define REG_NFIECC_FDMADDR       (REG_NFIECC_MD_R_NFIECC_FDMADDR_MD)	
#define REG_NFIECC_ENCDIADDR     (REG_NFIECC_MD_R_NFIECC_ENCDIADDR)	
#define REG_NFIECC_DECDIADDR     (REG_NFIECC_MD_R_NFIECC_DECDIADDR)	
#define REG_NFIECC_ENCIDLE       (REG_NFIECC_MD_R_NFIECC_ENCIDLE)     
#define REG_NFIECC_ENCSTA        (REG_NFIECC_MD_R_NFIECC_ENCSTA)	   
#define REG_NFIECC_DECIDLE       (REG_NFIECC_MD_R_NFIECC_DECIDLE)     
#define REG_NFIECC_DECFSM        (REG_NFIECC_MD_R_NFIECC_DECFSM)	   
#define REG_NFIECC_SYNSTA        (REG_NFIECC_MD_R_NFIECC_SYNSTA)	   
#define REG_NFIECC_DECNFIDI      (REG_NFIECC_MD_R_NFIECC_DECNFIDI)	   
#define REG_NFIECC_SYN0          (REG_NFIECC_MD_R_NFIECC_SYN0)	       
#define REG_NFIECC_DUMMY_REG          (REG_NFIECC_MD_R_NFIECC_MD_DUMMY_REG0)
#elif defined(__CA7__) || defined(CORTEXA7)
// AP-NFI
#define REG_NFI_CODA_VERSION      (REG_NFI_AP_R_NFI_AP_CODA_VERSION)
#define REG_NFI_CNFG             (REG_NFI_AP_R_NFI_CNFG_AP)
#define REG_NFI_PAGEFMT          (REG_NFI_AP_R_NFI_PAGEFMT_AP)
#define REG_NFI_CON              (REG_NFI_AP_R_NFI_CON_AP)
#define REG_NFI_INTR_EN          (REG_NFI_AP_R_NFI_INTR_EN_AP)
#define REG_NFI_INTR             (REG_NFI_AP_R_NFI_INTR_AP)
#define REG_NFI_INTR_CLR         (REG_NFI_AP_R_NFI_INTR_CLR_AP)
#define REG_NFI_BATCH            (REG_NFI_AP_R_NFI_BATCH_AP)
#define REG_NFI_LOC              (REG_NFI_AP_R_NFI_LOC_AP)
#define REG_NFI_STA              (REG_NFI_AP_R_NFI_STA_AP)
#define REG_NFI_FIFOSTA          (REG_NFI_AP_R_NFI_FIFOSTA_AP)
#define REG_NFI_LOCKSTA          (REG_NFI_AP_R_NFI_LOCKSTA_AP)
#define REG_NFI_ADDRCNTR         (REG_NFI_AP_R_NFI_ADDRCNTR_AP)
#define REG_NFI_STRADDR       (REG_NFI_AP_R_NFI_AP_STRADDR_AP)
#define REG_NFI_BYTELEN          (REG_NFI_AP_R_NFI_BYTELEN_AP)
#define REG_NFI_FDML(n)            (REG_NFI_AP_R_NFI_AP_FDM0L+(n<<3))
#define REG_NFI_FDMM(n)            (REG_NFI_AP_R_NFI_AP_FDM0M+(n<<3))
#define REG_NFI_FIFO_DATA(n)       (REG_NFI_AP_R_NFI_FIFO_DATA0_AP+(n<<2))
#define REG_NFI_FCD_STAT         (REG_NFI_AP_R_NFI_FCD_STAT_AP)
#define REG_NFI_BATCH_CMD_STATUS (REG_NFI_AP_R_NFI_BATCH_CMD_STATUS_AP)
#define REG_NFI_DUMMY_REG         (REG_NFI_AP_R_NFI_AP_DUMMY0)
#define REG_NFI_NLI_CTRL         (REG_NFI_AP_R_NFI_NLI_CTRL_AP)
// AP-NFIECC
#define REG_NFIECC_CODA_VERSION  (REG_NFIECC_AP_R_NFIECC_AP_CODA_VERSION)
#define REG_NFIECC_ENCCON        (REG_NFIECC_AP_R_NFIECC_ENCCON_AP)
#define REG_NFIECC_ENCCNFG       (REG_NFIECC_AP_R_NFIECC_ENCCNFG_AP)
#define REG_NFIECC_ENCPAR(n)       (REG_NFIECC_AP_R_NFIECC_ENCPAR0_AP+(n<<2))
#define REG_NFIECC_ENCIRQEN      (REG_NFIECC_AP_R_NFIECC_ENCIRQEN_AP)
#define REG_NFIECC_ENCIRQSTA     (REG_NFIECC_AP_R_NFIECC_ENCIRQSTA_AP)
#define REG_NFIECC_ENCIRQCLR     (REG_NFIECC_AP_R_NFIECC_ENCIRQCLR_AP)
#define REG_NFIECC_DECCON        (REG_NFIECC_AP_R_NFIECC_DECCON_AP)
#define REG_NFIECC_DECCNFG       (REG_NFIECC_AP_R_NFIECC_DECCNFG_AP)
#define REG_NFIECC_DECFER        (REG_NFIECC_AP_R_NFIECC_DECFER_AP)
#define REG_NFIECC_DECENUM       (REG_NFIECC_AP_R_NFIECC_DECENUM_AP)
#define REG_NFIECC_DECDONE       (REG_NFIECC_AP_R_NFIECC_DECDONE_AP)
#define REG_NFIECC_DECEL(n)        (REG_NFIECC_AP_R_NFIECC_DECEL0_AP+(n<<2))
#define REG_NFIECC_DECIRQEN      (REG_NFIECC_AP_R_NFIECC_DECIRQEN_AP)
#define REG_NFIECC_DECIRQSTA     (REG_NFIECC_AP_R_NFIECC_DECIRQSTA_AP)
#define REG_NFIECC_DECIRQCLR     (REG_NFIECC_AP_R_NFIECC_DECIRQCLR_AP)
#define REG_NFIECC_FDMADDR       (REG_NFIECC_AP_R_NFIECC_FDMADDR_AP)
#define REG_NFIECC_ENCIDLE         (REG_NFIECC_AP_R_NFIECC_ENCIDLE)
#define REG_NFIECC_ENCSTA          (REG_NFIECC_AP_R_NFIECC_ENCSTA)
#define REG_NFIECC_DECIDLE         (REG_NFIECC_AP_R_NFIECC_DECIDLE)
#define REG_NFIECC_DECFSM          (REG_NFIECC_AP_R_NFIECC_DECFSM)
#define REG_NFIECC_SYNSTA           (REG_NFIECC_AP_R_NFIECC_SYNSTA)
#define REG_NFIECC_DECNFIDI        (REG_NFIECC_AP_R_NFIECC_DECNFIDI)
#define REG_NFIECC_SYN0              (REG_NFIECC_AP_R_NFIECC_SYN0)
#define REG_NFIECC_DUMMY_REG          (REG_NFIECC_AP_R_NFIECC_AP_DUMMY0)
#endif

#define REG_NFI_OFFSET_MASK		(0xFFFF)

// NFI_CNFG
#define NFI_CNFG_AHB_MODE        (1U<<0)
#define NFI_CNFG_READ_MODE       (1U<<1)
#define NFI_CNFG_SCMB_FUN_EN     (1U<<2)
#define NFI_CNFG_SCMB_RST        (1U<<3)
#define NFI_CNFG_BYTE_RW         (1U<<6)
#define NFI_CNFG_HW_ECC_EN       (1U<<8)
#define NFI_CNFG_AUTO_FMT_EN     (1U<<9)
#define NFI_CNFG_OPMODE(n)       ((n<<12)&NFI_CNFG_OPMODE_MASK)
#define NFI_CNFG_OPMODE_MASK     (0x7<<12)
typedef enum {
    NFI_OPMODE_IDLE = 0, NFI_OPMODE_RD, NFI_OPMODE_SINGLE_RD, NFI_OPMODE_PRO,
    NFI_OPMODE_ERASE, NFI_OPMODE_RST, NFI_OPMODE_CUSTOM
} nfi_cnfg_opmode;

// NF_PAGEFMT
typedef enum {
	NFI_PAGEFMT_PAGE_SIZE_512 = 0, NFI_PAGEFMT_PAGE_SIZE_2K, NFI_PAGEFMT_PAGE_SIZE_4K, 
	NFI_PAGEFMT_PAGE_SIZE_RESERVED
} nfi_pagefmt_page_size;

typedef enum {
	NFI_PAGEFMT_SPARE_SIZE_16 = 0, NFI_PAGEFMT_SPARE_SIZE_26, NFI_PAGEFMT_SPARE_SIZE_27, 
	NFI_PAGEFMT_SPARE_SIZE_28
} nfi_pagefmt_spare_size;

typedef union nfi_page_fmt_u {
	struct nfi_page_fmt_s {
		kal_uint32 page_size:2,
					reserved0:1,
					data_width_16:1,
					spare_size:2,
					reserved1:2,
					fdm_num:4,
					fdm_ecc_num:4,
					reserved2:16;
	} s;
	kal_uint32 data;
} nfi_page_fmt_t;

#define NFI_PAGEFMT_DBYTE_EN			(1<<3)
#define NFI_PAGEFMT_FDM_NUM_MASK		((0xf)<<8)
#define NFI_PAGEFMT_FDM_NUM(n)			((n<<8)&NFI_PAGEFMT_FDM_NUM_MASK)
#define NFI_PAGEFMT_FDM_ECC_NUM_MASK	((0xf)<<12)
#define NFI_PAGEFMT_FDM_ECC_NUM(n)		((n<<12)&NFI_PAGEFMT_FDM_ECC_NUM_MASK)


// NFI_CON
#define NFI_CON_FLUSH_FIFO       (1U<<0)
#define NFI_CON_NFI_RESET        (1U<<1)
#define NFI_CON_SINGLE_RD_STR    (1U<<4)
#define NFI_CON_SR_NOB(n)        (n<<5)
#define NFI_CON_BURST_RD         (1U<<8)
#define NFI_CON_BUSRT_WR         (1U<<9)
#define NFI_CON_SEC_NUM(n)       (n<<12)

// --------------------------------------------------------------------
#ifdef __CR4__ // This is only for MD-side
// NFI_ACCCON
#define NFI_ACCCON_OUT_EN_EXT_EN_SHIFT  (28)
#define NFI_ACCCON_OUT_EN_EXT_EN_MASK  ((0x3)<<NFI_ACCCON_OUT_EN_EXT_EN_SHIFT)
#define NFI_ACCCON_OUT_EN_EXT_EN(n)       (((n)<<NFI_ACCCON_OUT_EN_EXT_EN_SHIFT)&NFI_ACCCON_OUT_EN_EXT_EN_MASK)
#define NFI_ACCCON_PRECS_SHIFT                (22)
#define NFI_ACCCON_PRECS_MASK	                ((0x3f)<<NFI_ACCCON_PRECS_SHIFT)
#define NFI_ACCCON_PRECS(n)                      (((n)<<NFI_ACCCON_PRECS_SHIFT)&NFI_ACCCON_PRECS_MASK)
#define NFI_ACCCON_C2R_LATENCY_SHIFT     (16)
#define NFI_ACCCON_C2R_LATENCY_MASK     ((0x3f)<<NFI_ACCCON_C2R_LATENCY_SHIFT)
#define NFI_ACCCON_C2R_LATENCY(n)           (((n)<<NFI_ACCCON_C2R_LATENCY_SHIFT)&NFI_ACCCON_C2R_LATENCY_MASK)
#define NFI_ACCCON_W2R_LATENCY_SHIFT    (12)
#define NFI_ACCCON_W2R_LATENCY_MASK    ((0xf)<<NFI_ACCCON_W2R_LATENCY_SHIFT)
#define NFI_ACCCON_W2R_LATENCY(n)          (((n)<<NFI_ACCCON_W2R_LATENCY_SHIFT)&NFI_ACCCON_W2R_LATENCY_MASK)
#define NFI_ACCCON_CAD_HOLD_SHIFT         (8)
#define NFI_ACCCON_CAD_HOLD_MASK          ((0xf)<<NFI_ACCCON_CAD_HOLD_SHIFT)
#define NFI_ACCCON_CAD_HOLD(n)                (((n)<<NFI_ACCCON_CAD_HOLD_SHIFT)&NFI_ACCCON_CAD_HOLD_MASK)
#define NFI_ACCCON_WR_LATENCY_SHIFT      (8)
#define NFI_ACCCON_WR_LATENCY_MASK      ((0xf)<<NFI_ACCCON_WR_LATENCY_SHIFT)
#define NFI_ACCCON_WR_LATENCY(n)            (((n)<<NFI_ACCCON_WR_LATENCY_SHIFT)&NFI_ACCCON_WR_LATENCY_MASK)
#define NFI_ACCCON_RD_LATENCY_SHIFT      (8)
#define NFI_ACCCON_RD_LATENCY_MASK      ((0xf)<<NFI_ACCCON_RD_LATENCY_SHIFT)
#define NFI_ACCCON_RD_LATENCYS(n)          (((n)<<NFI_ACCCON_RD_LATENCY_SHIFT)&NFI_ACCCON_RD_LATENCY_MASK)

typedef struct nfi_acccon_struct {
	kal_uint32 rd_latency:4;
	kal_uint32 wr_latency:4;
	kal_uint32 cad_hold:4;
	kal_uint32 w2r_latency:4;
	kal_uint32 c2r_latency:6;
	kal_uint32 precs:6;
	kal_uint32 out_en_ext_end:2;
	kal_uint32 reserved:2;
} nfi_acccon_struct;

typedef union {
    nfi_acccon_struct s;
    kal_uint32 raw_data;
} nfi_acccon;
#endif
// --------------------------------------------------------------------

typedef enum {
	NFI_INTR_RD_DONE_IDX = 0,
	NFI_INTR_WR_DONE_IDX = 1,
	NFI_INTR_RST_DONE_IDX = 2,
	NFI_INTR_ERASE_DONE_IDX = 3,
	NFI_INTR_BUSY2READY_IDX = 4,
	NFI_INTR_ACCESS_LOCK_IDX = 5,
	NFI_INTR_AHB_DONE_IDX = 6,
	NFI_INTR_NEW_RD_DONE_IDX = 7,
	NFI_INTR_NEW_WR_DONE_IDX = 8,
	NFI_INTR_NEW_AHB_DONE_IDX = 9,
	NFI_INTR_BUSY_TIMEOUT_IDX = 10,
	NFI_INTR_FCD_DONE_IDX = 11,
	NFI_INTR_NLI_GRANT_IDX = 12,
	NFI_INTR_NUM
} nfi_intr_index;

// NFI_INTR_EN, NFI_INTR
#define NFI_INTR_RD_DONE         (1U<<NFI_INTR_RD_DONE_IDX)
#define NFI_INTR_WR_DONE         (1U<<NFI_INTR_WR_DONE_IDX)
#define NFI_INTR_RST_DONE        (1U<<NFI_INTR_RST_DONE_IDX)
#define NFI_INTR_ERASE_DONE      (1U<<NFI_INTR_ERASE_DONE_IDX)
#define NFI_INTR_BUSY2READY      (1U<<NFI_INTR_BUSY2READY_IDX)
#define NFI_INTR_ACCESS_LOCK     (1U<<NFI_INTR_ACCESS_LOCK_IDX)
#define NFI_INTR_AHB_DONE        (1U<<NFI_INTR_AHB_DONE_IDX)
#define NFI_INTR_NEW_RD_DONE     (1U<<NFI_INTR_NEW_RD_DONE_IDX)
#define NFI_INTR_NEW_WR_DONE     (1U<<NFI_INTR_NEW_WR_DONE_IDX)
#define NFI_INTR_NEW_AHB_DONE    (1U<<NFI_INTR_NEW_AHB_DONE_IDX)
#define NFI_INTR_BUSY_TIMEOUT    (1U<<NFI_INTR_BUSY_TIMEOUT_IDX)
#define NFI_INTR_FCD_DONE        (1U<<NFI_INTR_FCD_DONE_IDX)
#define NFI_INTR_NLI_GRANT        (1U<<NFI_INTR_NLI_GRANT_IDX)
#define NFI_INTR_MASK			(NFI_INTR_RD_DONE | NFI_INTR_WR_DONE | NFI_INTR_RST_DONE | NFI_INTR_ERASE_DONE |	\
								NFI_INTR_BUSY2READY | NFI_INTR_ACCESS_LOCK | NFI_INTR_AHB_DONE | NFI_INTR_NEW_RD_DONE |	\
								NFI_INTR_NEW_WR_DONE | NFI_INTR_NEW_AHB_DONE | NFI_INTR_BUSY_TIMEOUT | NFI_INTR_FCD_DONE |	\
								NFI_INTR_NLI_GRANT)

// NFI_ADDRNOB
#define NFI_ADDRNOB_ROWADDR_MASK	((0x7)<<4)
#define NFI_ADDRNOB_COLADDR_MASK		((0x7)<<0)
#define NFI_ADDRNOB_ROWADDR_NOB(n)	((n<<4)&NFI_ADDRNOB_ROWADDR_MASK)
#define NFI_ADDRNOB_COLADDR_NOB(n)	((n<<0)&NFI_ADDRNOB_ROWADDR_MASK)

// NFI_STA
#define NFI_STA_NAND_FSM         (0x1F<<24)
#define NFI_STA_NFI_FSM          (0xF<<16)
#define NFI_STA_READ_EMPTY       (1U<<12)
#define NFI_STA_BUSY2READY       (1U<<9)
#define NFI_STA_BUSY             (1U<<8)
#define NFI_STA_ACCESS_LOCKED    (1U<<4)
#define NFI_STA_DATAW            (1U<<3)
#define NFI_STA_DATAR            (1U<<2)
#define NFI_STA_ADDR             (1U<<1)
#define NFI_STA_CMD_MODE         (1U<<0)

// NFI_FIFOSTA
#define NFI_FIFOSTA_WR_FULL      (1U<<15)
#define NFI_FIFOSTA_WR_EMPTY     (1U<<14)
#define NFI_FIFOSTA_WR_REMAIN    (0x1F<<8)
#define NFI_FIFOSTA_RD_FULL      (1U<<7)
#define NFI_FIFOSTA_RD_EMPTY     (1U<<6)
#define NFI_FIFOSTA_RD_REMAIN    (0x1F<<0)

// NFI_LOCK related
#define NFI_LOCK_SET_NUM	16

// NFI_BATCH_MODE
#define NFI_BATCH_MODE_EN					(1U<<0)

// NFI_FCD_STAT
#define NFI_FCD_STAT_BATCH_ACTIVE			(1U<<16)
#define NFI_FCD_STAT_FCD_CURR_IDX_MASK	(0xFFFF)

// NFI_BATCH_CMD_STATUS
#define NFI_BATCH_CMD_STATUS_SRD_CMP		(1U<<0)

// --------------------------------------------------------------------
#ifdef __CR4__ // This is only for MD-side
// NFI_NLI_CTRL
#define NFI_NLI_CTRL_NLI_REQ			(1U<<0)
#define NFI_NLI_CTRL_NLI_GRANT			(1U<<1)
#define NFI_NLI_CTRL_NFI_ULTRA_REQ_EN	(1U<<2)
#endif
// --------------------------------------------------------------------

//NFIECC_ENCIDLE
#define NFIECC_ENCIDLE_ENC_IDLE	(1U<<0)

//NFIECC_DECIDLE
#define NFIECC_DECIDLE_DEC_IDLE	(1U<<0)

//NFIECC_ENCCON
#define NFIECC_ENCCON_ENC_EN		(1U<<0)

//NFIECC_DECCON
#define NFIECC_DECCON_DEC_EN		(1U<<0)
#define NFIECC_DECCON_DEC_TRIG	(1U<<1)

//NFIECC_ENCCNFG & NFIECC_DECCNFG
typedef enum {
   NFIECC_CORRECT_4_BITS = 0,
   NFIECC_CORRECT_6_BITS = 1,
   NFIECC_CORRECT_8_BITS = 2,
   NFIECC_CORRECT_10_BITS = 3,
   NFIECC_CORRECT_12_BITS = 4
} nfiecc_tnum;
#define NFIECC_PARITY_BIT_BASE_NUM		(13)
#define NFIECC_MAX_CORRECTION_BITS		(12)

typedef enum {
	NFIECC_AHB_MODE = 0,
	NFIECC_NFI_MODE = 1
} nfiecc_cnfg_nfi_mode;

#define NFIECC_CNFG_TNUM_MASK				(0x7)
#define NFIECC_CNFG_TNUM(ecc_bit)			(((ecc_bit - 4) >> 1)&NFIECC_CNFG_TNUM_MASK)	// 4 -> 0, 6 -> 1, 8 -> 2, 10 -> 3, 12 -> 4
#define NFIECC_CNFG_NFI_MODE_EN			(1U<<4)
#define NFIECC_CNFG_MESSAGE_MASK			(0x1FFF0000)
#define NFIECC_CNFG_MESSAGE(n)				((n<<16)&NFIECC_CNFG_MESSAGE_MASK)

//NFIECC_DECCNFG
typedef enum {
	NFIECC_DEC_RESERVED_MODE = 0,
	NFIECC_DEC_DETECT_MODE,
	NFIECC_DEC_LOCATE_MODE,
	NFIECC_DEC_CORRECT_MODE
} nfiecc_deccnfg_con;

#define NFIECC_DECCNFG_DIS_CL_EX_FUN		(1U<<8)
#define NFIECC_DECCNFG_DEC_CON_MASK		(0x00003000)
#define NFIECC_DECCNFG_DEC_CON(mode)		((mode<<12)&NFIECC_DECCNFG_DEC_CON_MASK)
#define NFIECC_DECCNFG_DEC_EMPTY_EN		(1<<31)

//NFIECC_DECENUM
#define NFIECC_DECENUM_ERRNUM_MASK						(0xf)
#define NFIECC_DECENUM_ERRNUM(nfiecc_decnum_val, n)		((nfiecc_decnum_val>>(n<<2))&NFIECC_DECENUM_ERRNUM_MASK)

//NFIECC_ENCIRQ & NFIECC_DECIRQ
#define NFIECC_IRQ	(1U<<0)

/* NFIECC_ENCSTA */
#define NFIECC_ENCSTA_ENC_FSM			(0x001F)
#define NFIECC_ENCSTA_COUNT_PS		(0xFF10)
#define NFIECC_ENCSTA_COUNT_MS		(0x3FFF0000)

typedef struct {
	kal_uint32 nfi_sta;
	kal_uint32 nfi_addrcntr;
	kal_uint32 nfi_bytelen;
	kal_uint32 nfi_datafifo[4];
	// need to make sure size
	kal_uint8 dummy[CPU_CACHE_LINE_SIZE - sizeof(kal_uint32) * 7];
} nfi_status_struct;

typedef struct {
	// every error location need 16 bits
	kal_uint32 nfiecc_decel[NFIECC_MAX_CORRECTION_BITS >> 1]; 
	kal_uint32 nfiecc_decfer;
	kal_uint32 nfiecc_decenum;
	kal_uint32 nfiecc_decdone;
	// need to make sure size
	kal_uint8 dummy[CPU_CACHE_LINE_SIZE * 2 - sizeof(kal_uint32) * ((NFIECC_MAX_CORRECTION_BITS >> 1)  + 3 )];
} nfiecc_dec_status_struct;

#define ECC_ERR_LOC(base, x) ((base[x>>1] >> ((x % 2) ? 16: 0)) & 0x1FFF)
#define REG_ECC_ERR_LOC_REG(x) ((DRV_Reg32(REG_NFIECC_DECEL(x >> 1)) >> ((x % 2) ? 16: 0)) & 0x1FFF)

/*******************************************************************************
 * Nfi_bm_drv.h
 *******************************************************************************/
#if !defined(CORTEXA7)
typedef enum {
 NFI_REPORT_FAIL = -1,
 NFI_REPORT_PASS = 0,
 NFI_REPORT_TIMEOUT,
 NFI_REPORT_ONFI_NOT_SUPPORT,
 NFI_REPORT_PARA_ERR,
 NFI_REPORT_BATCH_ERR,
 NFI_REPORT_STATE_CMP_ERR,
 NFI_REPORT_ECC_ENC_ERR,
 NFI_REPORT_ECC_DEC_ERR
} NFI_REPORT_STATUS;
#endif // !CORTEXA7

#define NFI_FDM_NUM	8
#define NFI_MAX_DEV_ID_LEN 8
#define NFI_MAX_BAD_BLK 20
#define NFI_INIT_BAD_MARK_NUM	4
#define NFI_COPY_BACK_OP_NUM 4
#define ECC_MAX_BITS ECC_12_BITS

// FCD Format
typedef enum {
  NFI_FCD_CMD = 0, NFI_FCD_ADDR, NFI_FCD_SINGLE_RD, 
  NFI_FCD_DATA, NFI_FCD_REG_WR, NFI_FCD_REG_RD, 
  NFI_FCD_FDM
} nfi_fcd_type;

typedef struct nfi_fcd_cmd_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   Reserved02:1,
			   rb_flag:1,
			   fcd_type:3,
			   Reserved05:1,
			   cmd:8,
			   Reserved016:16;
	kal_uint32 Reserved10;
	kal_uint32 Reserved20;
	void * nx_fcd_ptr;
} nfi_fcd_cmd_type_t;

typedef struct nfi_fcd_addr_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   Reserved02:1,
			   rb_flag:1,
			   fcd_type:3,
			   Reserved07:1,
			   num_of_row:3,
			   num_of_col:3,
			   Reserved014:2,
			   Reserved016:16;
	kal_uint32 row_addr;
	kal_uint32 col_addr;
	void * nx_fcd_ptr;
} nfi_fcd_addr_type_t;

typedef struct nfi_fcd_single_rd_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   Reserved02:1,
			   Reserved03:1,
			   fcd_type:3,
			   cmp_en:1,
			   Reserved08:8,
			   num_of_byte:3,
			   Reserved019:13;
	kal_uint32 cmp_val;
	kal_uint32 cmp_mask;
	void * nx_fcd_ptr;
} nfi_fcd_single_rd_type_t;

typedef struct nfi_fcd_data_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   wr_rd_n:1,
			   rb_flag:1,
			   fcd_type:3,
			   Reserved07:1,
			   Reserved08:8,
			   len:16;
	kal_uint32 Reserved10;
	void * data_ptr;
	void * nx_fcd_ptr;
} nfi_fcd_data_type_t;

typedef struct nfi_fcd_reg_wr_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   Reserved02:1,
			   Reserved03:1,
			   fcd_type:3,
			   Reserved07:1,
			   Reserved08:8,
			   reg_addr:16;
	kal_uint32 reg_wr_mask;
	kal_uint32 reg_wr_val;
	void * nx_fcd_ptr;
} nfi_fcd_reg_wr_type_t;

typedef struct nfi_fcd_reg_rd_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   Reserved02:1,
			   Reserved03:1,
			   fcd_type:3,
			   Reserved07:1,
			   Reserved08:8,
			   reg_addr:16;
	kal_uint32 Reserved10;
	void * data_ptr;
	void * nx_fcd_ptr;
} nfi_fcd_reg_rd_type_t;

typedef struct nfi_fcd_fdm_type_s {
	kal_uint32 hw_own:1,
			   ioc:1,
			   wr_rd_n:1,
			   Reserved03:1,
			   fcd_type:3,
			   Reserved07:1,
			   fdm_reg_num:4,
			   Reserved012:4,
			   len:4,
			   Reserved020:12;
	kal_uint32 Reserved10;
	void * data_ptr;
	void * nx_fcd_ptr;
} nfi_fcd_fdm_type_t;

typedef struct nfi_fcd_s {
	kal_uint32 hw_own:1,
                     ioc:1,
			Reserved02:30;
	kal_uint32 Reserved10;
	kal_uint32 Reserved20;
	void * nx_fcd_ptr;
} nfi_fcd_type_t;

#ifdef __DOWNLOAD_AGENT__
/*******************************************************************************
 * Drv_rstctl.h & Drv_rstctl.c
 *******************************************************************************/ 
#define BASE_ADDR_RSTCTL				BASE_ADDR_MDRSTCTL 
#define REG_MDRSTCTL_SRSTR_APPERI       (BASE_ADDR_RSTCTL+0x0158)
#define REG_MDRSTCTL_SRCMR              (BASE_ADDR_RSTCTL+0x0300)
#define REG_MDRSTCTL_SRBER_APPERI       (BASE_ADDR_RSTCTL+0x0324)

#define RSTCTL_SRBER_NFI_RST			(1 << 3)
#define RSTCTL_SRCMR_KEY_SWDT_OFFSET	(16)
#define RSTCTL_SRCMR_KEY_SWRST			((0x2593 << RSTCTL_SRCMR_KEY_SWDT_OFFSET) | 0x1)	/* Key to enable software reset */
#endif /* __DOWNLOAD_AGENT__ */

#endif /* NAND_MTD_DRV_H */
