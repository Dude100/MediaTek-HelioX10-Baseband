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
 *	NandMTD.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This is a NAND Flash MTD driver header file for Samsung and Toshiba flash devices.
 *
 * Author:
 * -------
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
 *
 * removed!
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
 * removed!
 * removed!
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
 * removed!
 *
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
#ifndef NAND_MTD_INTERNAL_H
#define NAND_MTD_INTERNAL_H
/****************************
 * Include Header Files     *
 ****************************/
#include "reg_base.h"
#include "config_hw.h"
#include "drvpdn.h"
#include "fota_error.h"
  // Add for RHR
//    #include "dma_hw.h"
//RHR remove     #include "kal_non_specific_general_types.h"
//RHR remove     #include "kal_release.h"
    #include "kal_general_types.h"
    #include "kal_public_defs.h"    
  // Add for RHR
/*******************************************************************************
 * define
 *******************************************************************************/

#define QUICK_DMA_SUPPORT_V1

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


#define MTD_STATUS_ERROR              (0)
#define MTD_STATUS_NO_ERROR           (1)
#define MTD_STATUS_CORRECTED          (2)
#define MTD_STATUS_ID_NOT_SUPPORT     (10)

/* NAND flash copy back support */
#define PAGE_COPY_SUPPORT 1
#define MAX_PAGE_BUFFER_SIZE  (2048)
#define MAX_SPARE_BUFFER_SIZE (64)
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
/*******************************************************************************
 * NFI address definition
 *******************************************************************************/
#define DMA_NFI  0xf

#if ((defined(MT6228)) || (defined(MT6229)) || (defined(MT6230)))
#define NFI_GPIO_CON    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x01D0))		// gpio control pin
#define NFI_GPIO_DATA1  ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0200))		// data bit 8-9
#define NFI_GPIO_DATA2  ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0210))		// data bit 10-15
#elif ((defined(MT6219))|| (defined(MT6226))|| (defined(MT6226M)) || (defined(MT6227)))
#define NFI_GPIO_CON    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0180))
#elif (defined(MT6225))
#define NFI_GPIO_CON1    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0190))
#define NFI_GPIO_CON2    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x01A0))
#elif (defined(MT6238)) || (defined(MT6239)) /*MAUI_00728731*/
#define NFI_GPIO_CON1    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x1200))
#define NFI_GPIO_CON2    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x1300))
#elif (defined (MT6235)) || (defined(MT6235B))/*MAUI_00728731*/
#define NFI_GPIO_CON1    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x1300))
#define NFI_GPIO_CON2    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x1400))
#elif (defined (MT6268A) || defined (MT6268) || defined(MT6516) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)|| defined(TK6280)) /*MAUI_00757139*/
/*NAND control pin is dedicate */
#elif (defined (MT6253T) || defined (MT6253))
#define NFI_GPIO_CON1    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x01C0))
#else   //MT6217, MT6218B
#define NFI_GPIO_CON    ((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0130))
#endif
#if defined(__NFI_VERSION3_1__)

#define NFI_CNFG        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0004))
#define NFI_CON         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0008))
#define NFI_ACCCON      ((volatile UINT32P)(BASE_ADDR_MDNFI+0x000C))
#define NFI_INTR_EN     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0010))
#define NFI_INTR        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0014))

#define NFI_CMD         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0020))

#define NFI_ADDRNOB     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0030))
#define NFI_COLADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0034))
#define NFI_ROWADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0038))

#define NFI_STRDATA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0040))
#define NFI_CNRNB	    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0044))

#define NFI_DATAW       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0050))
#define NFI_DATAR       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0054))
#define NFI_PIO_DIRDY   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0058))

#define NFI_STA         ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0060))
#define NFI_FIFOSTA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0064))

#define NFI_ADDRCNTR    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0070))

#define NFI_STRADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0080))
#define NFI_BYTELEN     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0084))

#define NFI_CSEL        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0090))
#define NFI_IOCON       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0094))

#define NFI_FDM0L       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00A0))
#define NFI_FDM0M       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00A4))

#define NFI_FIFODATA0   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0190))
#define NFI_FIFODATA1   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0194))
#define NFI_FIFODATA2   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0198))
#define NFI_FIFODATA3   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x019C))

#define NFI_MCON		((volatile UINT32P)(BASE_ADDR_MDNFI+0x0200))
#define NFI_TOTALCNT	((volatile UINT32P)(BASE_ADDR_MDNFI+0x0204))
#define NFI_RQCNT		((volatile UINT32P)(BASE_ADDR_MDNFI+0x0208))
#define NFI_ACCNT		((volatile UINT32P)(BASE_ADDR_MDNFI+0x020c))
#define NFI_MASTERSTA   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0210))

/* NFI_CNFG */
#define CNFG_DMA             (0x0001)
#define CNFG_READ_EN         (0x0002)
#define CNFG_DMA_BURST_EN    (0x0004)
#define CNFG_BYTE_RW         (0x0040)
#define CNFG_HW_ECC_EN       (0x0100)
#define CNFG_AUTO_FMT_EN     (0x0200)
#define CNFG_OP_IDLE         (0x0000)
#define CNFG_OP_READ         (0x1000)
#define CNFG_OP_SRD          (0x2000)
#define CNFG_OP_PRGM         (0x3000)
#define CNFG_OP_ERASE        (0x4000)
#define CNFG_OP_RESET        (0x5000)
#define CNFG_OP_CUST         (0x6000)

#define CNFG_OP_MODE_MASK    (0x7000)
#define CNFG_OP_MODE_SHIFT   (12)

/* NFI_PAGEFMT */
#define PAGEFMT_512          (0x0000)
#define PAGEFMT_2K           (0x0001)
#define PAGEFMT_4K           (0x0002)

#define PAGEFMT_PAGE_MASK    (0x0003)

#define PAGEFMT_DBYTE_EN     (0x0008)

#define PAGEFMT_SPARE_16     (0x0000)
#define PAGEFMT_SPARE_26     (0x0001)
#define PAGEFMT_SPARE_27     (0x0002)
#define PAGEFMT_SPARE_28     (0x0003)
#define PAGEFMT_SPARE_MASK   (0x0030)
#define PAGEFMT_SPARE_SHIFT  (4)

#define PAGEFMT_FDM_MASK     (0x0F00)
#define PAGEFMT_FDM_SHIFT    (8)

#define PAGEFMT_FDM_ECC_MASK  (0xF000)
#define PAGEFMT_FDM_ECC_SHIFT (12)

#define PAGEFMT_FDM_ECC_DEFAULT		8
#define PAGEFMT_FDM_DEFAULT			8
#define PAGEFMT_FDM_ECC_SETTING 	((PAGEFMT_FDM_ECC_DEFAULT << PAGEFMT_FDM_ECC_SHIFT) | (PAGEFMT_FDM_DEFAULT << PAGEFMT_FDM_SHIFT))

/* NFI_CON */
#define CON_FIFO_FLUSH       (0x0001)
#define CON_NFI_RST          (0x0002)
#define CON_NFI_SRD          (0x0010)

#define CON_NFI_NOB_MASK     (0x0070)
#define CON_NFI_NOB_SHIFT    (5)

#define CON_NFI_BRD          (0x0100)
#define CON_NFI_BWR          (0x0200)

#define CON_NFI_SEC_MASK     (0xF000)
#define CON_NFI_SEC_SHIFT    (12)

/* NFI_ADDRNOB */
#define ADDR_COL_NOB_MASK    (0x0007)
#define ADDR_COL_NOB_SHIFT   (0)
#define ADDR_ROW_NOB_MASK    (0x0070)
#define ADDR_ROW_NOB_SHIFT   (4)

/* NFI_PIO_DIRDY */
#define PIO_DI_DRY			 (0x0001)

/* NFI_STA */
#define STA_READ_EMPTY       (0x00001000)
#define STA_ACC_LOCK         (0x00000010)
#define STA_CMD_STATE        (0x00000001)
#define STA_ADDR_STATE       (0x00000002)
#define STA_DATAR_STATE      (0x00000004)
#define STA_DATAW_STATE      (0x00000008)

#define STA_NAND_FSM_MASK    (0x1F000000)
#define STA_NAND_BUSY        (0x00000100)
#define STA_NAND_BUSY_RETURN (0x00000200)
#define STA_NFI_FSM_MASK     (0x000F0000)
#define STA_NFI_OP_MASK      (0x0000000F)

/* NFI_FIFOSTA */
#define FIFO_RD_EMPTY        	(0x0040)
#define FIFO_RD_FULL         	(0x0080)
#define FIFO_WR_FULL         	(0x8000)
#define FIFO_WR_EMPTY        	(0x4000)
#define FIFO_RD_REMAIN(x)    	(0x1F&(x))
#define FIFO_WR_REMAIN(x)    	((0x1F00&(x))>>8)
#define FIFO_PIO_READY(x)		(0x1 & x)

/* NFI_ADDRCNTR */
#define ADDRCNTR_CNTR(x)     ((0xF000&(x))>>12)
#define ADDRCNTR_OFFSET(x)   (0x03FF&(x))

/* NFI_CNRNB */
#define STROBE_TIMEOUT          (0xF1)

/* NFI_IOCON */
#define BRSTN_MASK				(0x00F0)
#define BRSTN_DEFAULT			(0x00F0)

#define NAND_SECTOR_SIZE        (512)
#define NAND_SECTOR_SHIFT		(9)

/*******************************************************************************
 * Macro definition
 *******************************************************************************/
#define NFI_Wait_Ready(timeout)   while ( (*NFI_STA & STA_NAND_BUSY) && (timeout) ){timeout--;}
#define NFI_Empty_Page()          ((*NFI_STA & STA_READ_EMPTY)>0)
#define NFI_FIFO_Empty(timeout)   while ( !(*NFI_FIFOSTA & FIFO_WR_EMPTY) && (timeout) ){timeout--;}

#define NFI_WAIT_TRANSFER_DONE(sec_num, timeout) \
   do {\
         if(ADDRCNTR_CNTR(DRV_Reg(NFI_ADDRCNTR)) < sec_num)\
            timeout--;\
         else\
            break;\
   } while( timeout>0 );

#define NFI_FIFO_DEPTH (16) /* in bytes */

#elif defined(__NFI_VERSION3__)

#define NFI_CNFG        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0004))
#define NFI_CON         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0008))
#define NFI_ACCCON      ((volatile UINT32P)(BASE_ADDR_MDNFI+0x000C))
#define NFI_INTR_EN     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0010))
#define NFI_INTR        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0014))

#define NFI_CMD         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0020))

#define NFI_ADDRNOB     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0030))
#define NFI_COLADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0034))
#define NFI_ROWADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0038))

#define NFI_STRDATA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0040))

#define NFI_DATAW       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0050))
#define NFI_DATAR       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0054))

#define NFI_STA         ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0060))
#define NFI_FIFOSTA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0064))
#define NFI_LOCKSTA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0068))

#define NFI_ADDRCNTR    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0070))

#define NFI_STRADDR     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0080))
#define NFI_BYTELEN     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0084))

#define NFI_CSEL        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0090))
#define NFI_IOCON       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0094))

#define NFI_FDM0L       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00A0))
#define NFI_FDM0M       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00A4))

#define NFI_LOCK        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0100))
#define NFI_LOCKCON     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0104))
#define NFI_LOCKANOB    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0108))
#define NFI_LOCK00ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0110))
#define NFI_LOCK00FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0114))
#define NFI_LOCK01ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0118))
#define NFI_LOCK01FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x011C))
#define NFI_LOCK02ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0120))
#define NFI_LOCK02FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0124))
#define NFI_LOCK03ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0128))
#define NFI_LOCK03FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x012C))
#define NFI_LOCK04ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0130))
#define NFI_LOCK04FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0134))
#define NFI_LOCK05ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0138))
#define NFI_LOCK05FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x013C))
#define NFI_LOCK06ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0140))
#define NFI_LOCK06FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0144))
#define NFI_LOCK07ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0148))
#define NFI_LOCK07FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x014C))
#define NFI_LOCK08ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0150))
#define NFI_LOCK08FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0154))
#define NFI_LOCK09ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0158))
#define NFI_LOCK09FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x015C))
#define NFI_LOCK10ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0160))
#define NFI_LOCK10FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0164))
#define NFI_LOCK11ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0168))
#define NFI_LOCK11FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x016C))
#define NFI_LOCK12ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0170))
#define NFI_LOCK12FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0174))
#define NFI_LOCK13ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0178))
#define NFI_LOCK13FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x017C))
#define NFI_LOCK14ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0180))
#define NFI_LOCK14FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0184))
#define NFI_LOCK15ADD   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0188))
#define NFI_LOCK15FMT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x018C))

#define NFI_FIFODATA0   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0190))
#define NFI_FIFODATA1   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0194))
#define NFI_FIFODATA2   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0198))
#define NFI_FIFODATA3   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x019C))

#elif defined(__NFI_VERSION2__)

#define NFI_ACCCON      ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0004))
#define NFI_OPCON       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0008))
#define NFI_CMD         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0010))
#define NFI_ADDNOB      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0020))
#define NFI_ADDRL       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0024))
#define NFI_ADDRM       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0028))
#define NFI_DATAW       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0030))
#define NFI_DATAWB      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0034))
#define NFI_DATAR       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0038))
#define NFI_DATARB		  ((volatile UINT16P)(BASE_ADDR_MDNFI+0x003C))
#define NFI_PSTA        ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0040))
#define NFI_FIFOSTA     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0044))
#define NFI_FIFODATA0   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0050))
#define NFI_FIFODATA1   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0054))
#define NFI_FIFODATA2   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0058))
#define NFI_FIFODATA3   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x005C))
#define NFI_CON         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0060))
#define NFI_INTR        ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0064))
#define NFI_INTR_EN     ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0068))
#define NFI_PAGECNTR    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0070))
#define NFI_ADDRCNTR    ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0074))
#define NFI_SYM0_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0080))
#define NFI_SYM1_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0084))
#define NFI_SYM2_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0088))
#define NFI_SYM3_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x008C))
#define NFI_SYM4_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0090))
#define NFI_SYM5_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0094))
#define NFI_SYM6_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0098))
#define NFI_SYM7_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x009C))
#define NFI_SYMS0_ADDR  ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00A0))
#define NFI_SYMS1_ADDR  ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00A4))
#define NFI_SYMS2_ADDR  ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00A8))
#define NFI_SYMS3_ADDR  ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00AC))
#define NFI_SYM0_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00B0))
#define NFI_SYM1_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00B4))
#define NFI_SYM2_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00B8))
#define NFI_SYM3_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00BC))
#define NFI_SYM4_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00C0))
#define NFI_SYM5_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00C4))
#define NFI_SYM6_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00C8))
#define NFI_SYM7_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00CC))
#define NFI_SYMS0_DAT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00D0))
#define NFI_SYMS1_DAT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00D4))
#define NFI_SYMS2_DAT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00D8))
#define NFI_SYMS3_DAT   ((volatile UINT32P)(BASE_ADDR_MDNFI+0x00DC))
#define NFI_PAR_0P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00E0))
#define NFI_PAR_0C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00E4))
#define NFI_PAR_1P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00E8))
#define NFI_PAR_1C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00EC))
#define NFI_PAR_2P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00F0))
#define NFI_PAR_2C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00F4))
#define NFI_PAR_3P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00F8))
#define NFI_PAR_3C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x00FC))
#define NFI_PAR_4P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0100))
#define NFI_PAR_4C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0104))
#define NFI_PAR_5P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0108))
#define NFI_PAR_5C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x010C))
#define NFI_PAR_6P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0110))
#define NFI_PAR_6C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0114))
#define NFI_PAR_7P      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0118))
#define NFI_PAR_7C      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x011C))
#define NFI_PARS_0P     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0120))
#define NFI_PARS_0C     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0124))
#define NFI_PARS_1P     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0128))
#define NFI_PARS_1C     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x012C))
#define NFI_PARS_2P     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0130))
#define NFI_PARS_2C     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0134))
#define NFI_PARS_3P     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0138))
#define NFI_PARS_3C     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x013C))
#define NFI_ERRDET      ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0140))
#define NFI_PARECC      ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0144))
#define NFI_SCON        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0148))
#define NFI_CSEL        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0200))
#define NFI_IOCON       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0204))

#else	// #if defined(__NFI_VERSION2__)

#define NFI_ACCCON      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0000))
#define NFI_PAGEFMT     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0004))
#define NFI_OPCON       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0008))
#define NFI_CMD         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x000C))
#define NFI_ADDNOB      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0010))
#define NFI_ADDRL       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0014))
#define NFI_ADDRM       ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0018))
#define NFI_DATAW       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x001C))
#define NFI_DATAWB      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0020))
#define NFI_DATAR       ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0024))
#define NFI_DATARB		((volatile UINT16P)(BASE_ADDR_MDNFI+0x0028))
#define NFI_PSTA        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x002C))
#define NFI_FIFOCON     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0030))
#define NFI_CON         ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0034))
#define NFI_INTR        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0038))
#define NFI_INTR_EN     ((volatile UINT16P)(BASE_ADDR_MDNFI+0x003C))
#define NFI_PAGECNTR		((volatile UINT16P)(BASE_ADDR_MDNFI+0x0040))
#define NFI_ADDRCNTR		((volatile UINT16P)(BASE_ADDR_MDNFI+0x0044))
#define NFI_SYM0_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0050))
#define NFI_SYM1_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0054))
#define NFI_SYM2_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0058))
#define NFI_SYM3_ADDR   ((volatile UINT16P)(BASE_ADDR_MDNFI+0x005C))
#define NFI_SYM0_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0060))
#define NFI_SYM1_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0064))
#define NFI_SYM2_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x0068))
#define NFI_SYM3_DAT    ((volatile UINT32P)(BASE_ADDR_MDNFI+0x006C))
#define NFI_ERRDET      ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0070))
#define NFI_PAR0        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0080))
#define NFI_PAR1        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0084))
#define NFI_PAR2        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0088))
#define NFI_PAR3        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x008C))
#define NFI_PAR4        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0090))
#define NFI_PAR5        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0094))
#define NFI_PAR6        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x0098))
#define NFI_PAR7        ((volatile UINT16P)(BASE_ADDR_MDNFI+0x009C))
#define NFI_CSEL			((volatile UINT16P)(BASE_ADDR_MDNFI+0x0100))

#endif /*__NFI_VERSION3__*/



/*******************************************************************************
 * NFI register definition
 *******************************************************************************/
/* NFI_ACCCON - example
  *NFI_ACCCON = ACCCON | (((NFI_W2R<<6)|(NFI_WH<<4)) | ((NFI_WST<<2)|NFI_RLC));

  *NFI_ACCCON = 0x07C6  // C2R=111, W2R=11, WH=00, WST=00, RLT=10

*/
#define ACCCON						0x0700	// C2R=111
#define NFI_W2R					3			// 0:2T, 1:4T, 2:6T, 3:8T ; recommanded value=3
#define NFI_WH						3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=1
#define NFI_WST					3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=1
#define NFI_RLC					3			// 0:0T, 1:1T, 2:2T, 3:3T ; recommanded value=2

/* NFI_PAGEFMT; support for PAGEFMT_PageSize_BusWidth */
#if defined(__NFI_VERSION3_1__)
// Set FDM_ECC_NUM to 8 and FDM_NUM to 8 by default.
#define PAGEFMT_512_8BIT   	0x0000
#define PAGEFMT_512_16BIT  	0x0008
#define PAGEFMT_2K_8BIT		0x0001
#define PAGEFMT_2K_16BIT	0x0009
#define PAGEFMT_4K_8BIT		0x0002
#define PAGEFMT_4K_16BIT	0x000A
#elif defined(__NFI_VERSION3__)
#define PAGEFMT_512_8BIT     (0x0000)
#define PAGEFMT_512_16BIT    (0x0008)
#define PAGEFMT_2K_8BIT      (0x0001)
#define PAGEFMT_2K_16BIT     (0x0009)
#define PAGEFMT_4K_8BIT      (0x0002)
#define PAGEFMT_4K_16BIT     (0x000A)

#define PAGEFMT_PAGE_MASK    (0x0003)

#define PAGEFMT_DBYTE_EN     (0x0008)

#define PAGEFMT_SPARE_16     (0x0000)
#define PAGEFMT_SPARE_26     (0x0001)
#define PAGEFMT_SPARE_27     (0x0002)
#define PAGEFMT_SPARE_28     (0x0003)
#define PAGEFMT_SPARE_MASK   (0x0030)
#define PAGEFMT_SPARE_SHIFT  (4)

#define PAGEFMT_FDM_MASK     (0x0F00)
#define PAGEFMT_FDM_SHIFT    (8)

#define PAGEFMT_FDM_ECC_MASK  (0xF000)
#define PAGEFMT_FDM_ECC_SHIFT (12)

#elif defined(__NFI_VERSION2__)

#define PAGEFMT_512_8BIT   	0x0010  /*Enable ECC block size = 256*/
#define PAGEFMT_512_16BIT  	0x0110  /*Enable ECC block size = 256*/
#define PAGEFMT_2K_8BIT		0x0015  /*Enable ECC block size = 256*/
#define PAGEFMT_2K_16BIT	0x0119  /*Enable ECC block size = 256*/

#else

#define PAGEFMT_512_8BIT   	0x0020
#define PAGEFMT_512_16BIT  	0x0120
#define PAGEFMT_2K_8BIT			0x0025
#define PAGEFMT_2K_16BIT		0x0125

#endif /* __NFI_VERSION3__ */

#define	IO_ACCESS_8BIT			8
#define	IO_ACCESS_16BIT		16

/* NFI_CNFG */
#if defined(__NFI_VERSION3__)
#define AHB_MODE             (0x0001)
#define READ_MODE            (0x0002)
#define BYTE_RW              (0x0040)
#define HW_ECC_EN            (0x0100)
#define AUTO_FMT_EN          (0x0200)
#define OP_IDLE              (0x0000)
#define OP_READ              (0x1000)
#define OP_SRD               (0x2000)
#define OP_PROGRAM           (0x3000)
#define OP_ERASE             (0x4000)
#define OP_RESET             (0x5000)
#define OP_CUSTOM            (0x6000)

#define OP_MODE_MASK    (0x7000)
#define OP_MODE_SHIFT   (12)
#endif /* __NFI_VERSION3__ */

/* NFI_OPCON */
#if defined(__NFI_VERSION3__)
#define FIFO_FLUSH         (0x0001)
#define NFI_RESET          (0x0002)
#define SINGLE_RD          (0x0010)
#define BURST_RD           (0x0100)
#define BURST_WR           (0x0200)
#define NOB_MASK           (0x0060)
#define NOB_BYTE           (0x1000)
#define NOB_WORD           (0x2000)
#define NOB_DWORD          (0x4000)
#define NOB_DDWORD         (0x0000)
#define NOB_SHIFT          (5)
#define SEC_MASK           (0xF000)
#define SEC_SHIFT          (12)
#else
#define BURST_RD           	(0x0001)
#define BURST_WR           	(0x0002)
#define ECC_RD_INIT        	(0x0010)
#define ECC_WR_INIT        	(0x0020)
#define SINGLE_RD          	(0x0100)
#define NOB_BYTE           	(0x1000)
#define NOB_WORD           	(0x2000)
#define NOB_DWORD          	(0x0000)
#endif /* __NFI_VERSION3__ */
#if defined(__NFI_VERSION2__)
#define OPCON_RESET 0x0C00
#endif


/* Nand flash command */
#define RD_1ST_CMD         	0x00
#define RD_2ND_HALF_CMD     	0x01	// only for 512B page-size
#define RD_SPARE_CMD       	0x50	// only for 512B page-size
#define RD_2ND_CYCLE_CMD		0x30	// only for 2KB  page-size
#define INPUT_DATA_CMD     	0x80
#define PROG_DATA_CMD      	0x10
#define BLOCK_ERASE1_CMD   	0x60
#define BLOCK_ERASE2_CMD   	0xD0
#define RD_ID_CMD          	0x90
#define RD_STATUS_CMD      	0x70
#define RESET_CMD          	0xFF
#define CP_READ_CMD        	0x35
#define CP_INPUT_CMD_2K    	0x85
#define CP_INPUT_CMD_512   	0x8A
#define CP_PROG_CMD_TOSHIBA	0x15

/* NFI_PSTA */
#if defined(__NFI_VERSION3__)
#define STATUS_CMD              (0x00000001)
#define STATUS_ADDR             (0x00000002)
#define STATUS_DATAR            (0x00000004)
#define STATUS_DATAW            (0x00000008)
#define STATUS_ACCESS_LOCK      (0x00000010)
#define STATUS_BUSY             (0x00000100)
#define STATUS_BUSY_RETURN      (0x00000200)
#define STATUS_READ_EMPTY       (0x00001000)

#define STATUS_NAND_FSM_MASK    (0x1F000000)
#define STATUS_NFI_FSM_MASK     (0x000F0000)
#define STATUS_OPERATION_MASK   (0x0000000F)

#else /* !__NFI_VERSION3__ */
#define STATUS_CMD         	0x1
#define STATUS_ADDR        	0x2
#define STATUS_DATAR       	0x4
#define STATUS_DATAW       	0x8
#define STATUS_BUSY        	0x100
#endif /* __NFI_VERSION3__ */

#if defined(__NFI_VERSION3__)
/* NFI_FIFOSTA */
#define RD_EMPTY_MASK        (0x0040)
#define RD_FULL_MASK         (0x0080)
#define WR_EMPTY_MASK        (0x4000)
#define WR_FULL_MASK         (0x8000)
#define FIFO_RD_REMAIN(x)    (0x1F&(x))
#define FIFO_WR_REMAIN(x)    ((0x1F00&(x))>>8)

#elif defined(__NFI_VERSION2__)
/* NFI_FIFOCON */

#define RD_EMPTY_MASK  0x40
#define RD_FULL_MASK     0x80
#define WR_EMPTY_MASK 	0x4000
#define WR_FULL_MASK    0x8000
#define FIFO_RD_REMAIN(x) (0x1F&(x))
#define FIFO_WR_REMAIN(x) ((0x1F00&(x))>>8)

#else

#define RD_EMPTY_MASK      	0x001
#define RD_FULL_MASK       	0x002
#define WR_EMPTY_MASK      	0x004
#define WR_FULL_MASK      		0x008
#define FIFO_FLUSH         	0x010
#define RESET              	0x020

#endif

#if defined(__NFI_VERSION3__)
/* NFI_FIFOSTA */
#define RD_EMPTY_MASK        (0x0040)
#define RD_FULL_MASK         (0x0080)
#define WR_EMPTY_MASK        (0x4000)
#define WR_FULL_MASK         (0x8000)
#define FIFO_RD_REMAIN(x)    (0x1F&(x))
#define FIFO_WR_REMAIN(x)    ((0x1F00&(x))>>8)
#endif /* __NFI_VERSION3__ */

/* NFI_CON */
#if defined(__NFI_VERSION3_1__)
#define BYTE_RW_EN				0x0040
#else
#define BYTE_RW_EN				0x8000
#endif
#define READ_CON_EN				0x0400
#define PROGRAM_CON_EN			0X0200
#define ERASE_CON_EN				0X0100
#define SW_PROGSPARE_EN    	0x0020
#define MULTI_PAGE_RD_EN   	0x0010
#define AUTOECC_ENC_EN     	0x0008
#define AUTOECC_DEC_EN     	0x0004
#define DMA_WR_EN          	0x0002
#define DMA_RD_EN          	0x0001

#if defined(__NFI_VERSION2__)
#define MAIN_ECC_EN      0x200
#define SPARE_ECC_EN     0x100
#define AUTO_ECC_ENC    0x8
#define AUTO_ECC_DEC    0x4
#define ECC_FALSE      0x0
#endif

/* NFI_ERRDET */
#if defined(__NFI_VERSION2__)
/*uncorrectable error*/
#define ERRDET_EBLK0    0x00000001
#define ERRDET_EBLK1    0x00000002
#define ERRDET_EBLK2    0x00000004
#define ERRDET_EBLK3    0x00000008
#define ERRDET_EBLK4    0x00000010
#define ERRDET_EBLK5    0x00000020
#define ERRDET_EBLK6    0x00000040
#define ERRDET_EBLK7    0x00000080
#define ERRDET_ESBLK0   0x00000100
#define ERRDET_ESBLK1   0x00000200
#define ERRDET_ESBLK2   0x00000400
#define ERRDET_ESBLK3   0x00000800
#define ERRDET_E_ALL    0x00000FFF
/*correctable error*/
#define ERRDET_PEBLK0   0x00010000
#define ERRDET_PEBLK1   0x00020000
#define ERRDET_PEBLK2   0x00040000
#define ERRDET_PEBLK3   0x00080000
#define ERRDET_PEBLK4   0x00100000
#define ERRDET_PEBLK5   0x00200000
#define ERRDET_PEBLK6   0x00400000
#define ERRDET_PEBLK7   0x00800000
#define ERRDET_PESBLK0  0x01000000
#define ERRDET_PESBLK1  0x02000000
#define ERRDET_PESBLK2  0x04000000
#define ERRDET_PESBLK3  0x08000000
#define ERRDET_PE_ALL   0x0FFF0000
#endif

#if defined(__NFI_VERSION3__)
/* NFI_ADDRCNTR */
#define ADDRCNTR_CNTR(x)     ((0xF000&(x))>>12)
#define ADDRCNTR_OFFSET(x)   (0x03FF&(x))

/* NFI_LOCK */
#define LOCK_ON                (0x0001)

/* NFI_LOCKANOB */
#define PROGRAM_ROW_NOB_MASK   (0x7000)
#define PROGRAM_ROW_NOB_SHIFT  (12)
#define PROGRAM_COL_NOB_MASK   (0x0300)
#define PROGRAM_COL_NOB_SHIFT  (8)
#define ERASE_ROW_NOB_MASK     (0x0070)
#define ERASE_ROW_NOB_SHIFT    (4)
#define ERASE_COL_NOB_MASK     (0x0007)
#define ERASE_COL_NOB_SHIFT    (0)
#endif /* __NFI_VERSION3__ */


/* Status register */
#define RDY_BUSY           	0x40
#define PASS_FAIL          	0x01


#define IS_NFI_DMA_RUN 	 *(volatile kal_uint32 *)DMA_GLBSTA & (kal_uint32)DMA_GLBSTA_RUN(nfi_dmaport)

/* NFI_INTR_EN */

/* NFI_INTR */
#if defined(__NFI_VERSION3_1__)
#define RD_COMPLETE_EN		(0x0001)
#define WR_COMPLETE_EN		(0x0002)
#define RESET_COMPLETE_EN	(0x0004)
#define ERASE_COMPLETE_EN	(0x0008)
#define BUSY_RETURN_EN		(0x0010)
#define ACC_LOCK_EN			(0x0020)
#define AHB_DONE_EN			(0x0040)
#define ALL_EN             	(0x007F)
#elif defined(__NFI_VERSION3__)
#define RD_COMPLETE_EN     (0x0001)
#define WR_COMPLETE_EN     (0x0002)
#define RESET_COMPLETE_EN  (0x0004)
#define ERASE_COMPLETE_EN  (0x0008)
#define BUSY_RETURN_EN     (0x0010)
#define ACCESS_LOCK_EN     (0x0020)
#define AHB_COMPLETE__EN   (0x0040)
#define ALL_EN             (0x007F)
#elif defined(__NFI_VERSION2__)
#define RD_COMPLETE_EN     0x1000
#define WR_COMPLETE_EN     0x2000
#define RESET_COMPLETE_EN  0x4000
#define ERASE_COMPLETE_EN  0x8000
#define BUSY_RETURN_EN     0x10000000
#define ALL_EN         0x1000f000
#else
#define RD_COMPLETE_EN     	0x01
#define WR_COMPLETE_EN     	0x02
#define RESET_COMPLETE_EN  	0x04
#define ERASE_COMPLETE_EN  	0x08
#define ERR_DET_EN         	0x10
#define ERR_COR_EN         	0x20
#define BUSY_RETURN_EN     	0x40
#define ALL_EN             	0x7F
#endif

/* NFI_INTR */
#if defined(__NFI_VERSION3_1__)
#define RD_COMPLETE			(0x0001)
#define WR_COMPLETE			(0x0002)
#define RESET_COMPLETE		(0x0004)
#define ERASE_COMPLETE		(0x0008)
#define BUSY_RETURN			(0x0010)
#define ACC_LOCK		    (0x0020)
#define AHB_DONE			(0x0040)
#elif defined(__NFI_VERSION3__)
#define RD_COMPLETE         (0x0001)
#define WR_COMPLETE         (0x0002)
#define RESET_COMPLETE      (0x0004)
#define ERASE_COMPLETE      (0x0008)
#define BUSY_RETURN         (0x0010)
#define ACCESS_LOCK         (0x0020)
#define AHB_COMPLETE        (0x0040)
#elif defined(__NFI_VERSION2__)
#define RD_COMPLETE        0x1000
#define WR_COMPLETE       0x2000
#define RESET_COMPLETE   0x4000
#define ERASE_COMPLETE  0x8000
#define BUSY_RETURN        0x10000000
#else
#define RD_COMPLETE        0x0001
#define WR_COMPLETE        0x0002
#define RESET_COMPLETE     0x0004
#define ERASE_COMPLETE     0x0008
#define ERR_DET0           0x0010
#define ERR_DET1           0x0020
#define ERR_DET2           0x0040
#define ERR_DET3           0x0080
#define ERR_COR0           0x0100
#define ERR_COR1           0x0200
#define ERR_COR2           0x0400
#define ERR_COR3           0x0800
#define BUSY_RETURN        0x1000
#endif /*__NFI_VERSION2__*/

#if defined(__NFI_VERSION3__)
/* NFI_ADDRNOB */
#define ADDRNOB_COL_MASK    (0x0007)
#define ADDRNOB_COL_SHIFT   (0)
#define ADDRNOB_ROW_MASK    (0x0070)
#define ADDRNOB_ROW_SHIFT   (4)
#endif /* __NFI_VERSION3__ */

/*******************************************************************************
 * Dual NAND declaration
 *******************************************************************************/
typedef struct
{
  kal_int32     (* ProgramPage)    (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
  kal_int32     (* ReadPage)       (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
  kal_int32     (* ProgramSpare)   (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data);
  kal_int32     (* ReadSpare)      (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data);
  kal_int32     (* CopyPage)       (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex);
  kal_int32     (* CopyPermitted)  (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex);
  kal_int32     (* OTPAccess)      (void * DriveData, kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
  kal_int32     (* OTPQueryLength) (void * DriveData, kal_uint32 *Length);
} NAND_MTD_SUB_DRIVER;

typedef struct drive_data_tag
{
   kal_uint32            base_page;
   kal_uint8             address_cycle;  // 3, 4, or 5
   kal_uint8             io_width;       // 8 or 16 bits
   kal_uint32            page_size;      // in bytes
   kal_uint32            pages_per_block;//
   kal_uint32            plane_mask;     // identify whether two blocks are in the same plane/district
   NAND_MTD_SUB_DRIVER * sub_driver;
}  NAND_MTD_SUB_DRIVER_DATA;


typedef struct mtd_lock_tag {
   kal_uint32  lock_count;
   kal_taskid  owner_id;
   kal_mutexid mtd_mutex;
} NAND_MTD_LOCK;

// define NFI CS0/1 DIR, DOUT, CON
#if ( (defined(MT6218B)) )
#define NFI_CS_DIR		((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0010))		// GPIO 30 as NFI CS0
#define NFI_CS_DOUT		((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x00A0))
#elif ( (defined(MT6219)) )
#define NFI_CS_DIR		((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x0010))		// GPIO 30 as NFI CS0
#define NFI_CS_DOUT		((volatile UINT16P)(BASE_ADDR_MDGPIOMUX+0x00D0))
#endif



#if defined(MT6516)

#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0

#define SET_NFI_CS1

#define SET_NFI_CS1_END

#elif ( (defined(MT6218B)) || (defined(MT6219)))
#define INITIALIZE_NFI_DIR_DOUT \
{\
  *NFI_CS_DIR |= 0x4100;\
  *NFI_CS_DOUT |= 0x4100;\
}

// set GPIO 30 as NFI CS0
#define SET_NFI_CS0 \


// set GPIO 30 as GPIO and GPIO 24 DOUT=0
#define SET_NFI_CS1 \
{\
  *NFI_GPIO_CON &= 0xCFFF;\
  *NFI_CS_DOUT &= 0xFEFF;\
}

// set GPIO 24 DOUT=1
#define SET_NFI_CS1_END \
{\
   *NFI_GPIO_CON |= 0x1000;\
  *NFI_CS_DOUT |= 0x0100;\
}
#elif (defined(MT6225))
#define INITIALIZE_NFI_DIR_DOUT

/* GPIO42 as CS0 */
#define SET_NFI_CS0 \
{\
  *NFI_GPIO_CON2 |= 0x10;\
  *NFI_CSEL = 0;\
}

/* GPIO34 as CS1 */
#define SET_NFI_CS1 \
{\
  *NFI_GPIO_CON1 |= 0x20;\
  *NFI_CSEL = 1;\
}

#define SET_NFI_CS0_END \
{\
  *NFI_GPIO_CON2 &= 0xFFEF;\
}

#define SET_NFI_CS1_END \
{\
  *NFI_GPIO_CON1 &= 0xFFDF;\
}

#elif defined(__NFI_VERSION2__)

#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0 \
  *NFI_CSEL = 0;

#define SET_NFI_CS1 \
  *NFI_CSEL = 1;

#define SET_NFI_CS1_END

#else		// MT6217 , MT6226, MT6226M, MT6227, MT6228, MT6229
#define INITIALIZE_NFI_DIR_DOUT

#define SET_NFI_CS0 \
  *NFI_CSEL = 0;

#define SET_NFI_CS1 \
  *NFI_CSEL = 1;

#define SET_NFI_CS1_END

#endif



/*******************************************************************************
 * structure definition for flash supply list and MTD
 *******************************************************************************/
typedef struct flash_list_tag
{
   kal_uint16     id;
   kal_uint16     plane_size;       // in MB
   kal_uint16     block_size;       // in KB
   kal_uint16     page_size;        // in B
   kal_uint8      address_cycle;    // 3, 4, or 5
   kal_uint8      io_width;      // 8 or 16 bits
   kal_uint32     plane_mask;       // identify whether two blocks are in the same plane/district
   NAND_MTD_SUB_DRIVER * sub_driver;
}  flash_list;


/*******************************************************************************/
typedef struct
{
  kal_int32     (* MountDevice)    (void * DriveData);
  kal_int32     (* ShutDown)       (void * DriveData);
  kal_int32     (* EraseBlock)     (void * DriveData, kal_uint32 BlockIndex);
  kal_int32     (* ProgramPage)    (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag);
  kal_int32     (* ReadPage)       (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
  kal_int32     (* ProgramSpare)   (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data);
  kal_int32     (* ReadSpare)      (void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data);
  kal_int32     (* CopyPage)       (void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex);
    kal_int32     (* OTPAccess)      (void * DriveData, kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
  kal_int32     (* OTPQueryLength) (void * DriveData, kal_uint32 *LengthPtr);
} NAND_MTD_DRIVER;



/*******************************************************************************
 *  Macro definition
 *******************************************************************************/
#if defined(MCU_13M)
/* 1T ~= 77 ns */
//#define COUNTER_2MS (25974)
#define COUNTER_200nS	(3)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 25974) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 25974) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 64935) break;\
}

#elif defined(MCU_26M)
/* 1T ~= 38 ns */
//#define COUNTER_2MS (60606)
#define COUNTER_200nS 	(6)
#define NOT_WAIT_NFI_DONE_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 60606) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 60606) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 131579) break;\
}

#elif defined(MCU_52M)
/* 1T ~= 19 ns */
//#define COUNTER_2MS (105263)
#define COUNTER_200nS 	(11)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 105263) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 105263) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 263157) break;\
}
#elif defined(MCU_68_714M)
/* 1T ~= 19 ns */
#define COUNTER_200nS   (15)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
	   kal_uint32 dida = 0;\
	   while(a)\
	      if(dida++ > 139097) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
	   kal_uint32 dida = 0;\
	   while(a)\
	      if(dida++ > 139097) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
	kal_uint32 dida = 0;\
	while(a)\
	if(dida++ > 347742) break;\
}

#elif defined(MCU_78M)
/* 1T ~= 12.8 ns */
#define COUNTER_200nS 	(15)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 156250) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 156250) break;\
}

#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 312500) break;\
}
#elif defined(MCU_104M)
/* 1T ~= 9.6 ns */
//#define COUNTER_2MS (208333)
#define COUNTER_200nS 	(21)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 208333) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 208333) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 520833) break;\
}

#elif defined(MCU_122_88M)
/* 1T ~= 8.13 ns */
//#define COUNTER_2MS (246002)
#define COUNTER_200nS 	(25)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 246002) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 246002) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 615006) break;\
}

/* SHK: I add this for supporting */
#elif defined(MCU_208M)
/* 1T ~= 4.8 ns */
//#define COUNTER_2MS (416666)
#define COUNTER_200nS   (42)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 416666) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 416666) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1041666) break;\
}

#elif (defined(MCU_245_76M)||defined(MCU_260M)) /*[MAUI_00754374]*/
/* 1T ~= 4 ns */
//#define COUNTER_2MS (491520)
#define COUNTER_200nS   (50)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 491520) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 491520) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1250000) break;\
}

#elif defined(MCU_312M)
/* 1T ~= 3.2 ns */
//#define COUNTER_2MS (625000)
#define COUNTER_200nS   (63)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 625000) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 625000) break;\
}

//#define COUNTER_5MS (156250)
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1562500) break;\
}
#elif defined(MCU_368_64M)
/* 1T ~= 2.7 ns */
#define COUNTER_200nS   (75)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 740741) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 740741) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1851852) break;\
}
#elif defined(MCU_416M)
/* 1T ~= 2.4 ns */
#define COUNTER_200nS   (83)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 833333) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 833333) break;\
}

#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1666666) break;\
}
#elif (defined(MCU_512M)|| defined(MCU_491_52M) || defined(MCU_492M)|| defined(MCU_480M))
/* 1T ~= 2.0 ns */
//#define COUNTER_2MS (1000000)
#define COUNTER_200nS   (100)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1000000) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1000000) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 2500000) break;\
}
#elif defined(MCU_520M)
/* 1T ~= 1.92 ns */
//#define COUNTER_2MS (1041666)
#define COUNTER_200nS   (104)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1041666) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1041666) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 2604166) break;\
}
#elif defined(MCU_611M)
/* 1T ~= 1.6 ns */
#define COUNTER_200nS   (125)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1253333) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1253333) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 3133333) break;\
}
#elif defined(MCU_650M)
/* 1T ~= 1.5 ns */
#define COUNTER_200nS   (133)
#define NOT_WAIT_NFI_RETURN(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1333333) return KAL_FALSE;\
}

#define NOT_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 1333333) break;\
}

//#define COUNTER_5MS
#define LONG_WAIT_NFI_DONE(a)  \
{\
   kal_uint32 dida = 0;\
   while(a)\
      if(dida++ > 3333333) break;\
}
#else
	#if defined(NAND_SUPPORT)
		#error "Unsupported MCU clock rate for busy wait loop!"
	#endif
#endif
/*if(dida++ > 0xFFF0) return 0;*/

/*******************************************************************************
 *  MTD function declaration
 *******************************************************************************/
kal_int32 MTD_MountDevice (void * DriveData);
kal_int32 MTD_ShutDown  (void * DriveData);
kal_int32 MTD_EraseBlock  (void * DriveData, kal_uint32 BlockIndex);
kal_int32 MTD_OTPAccess      (void * DriveData, kal_int32 accesstype, kal_uint32 Offset, void * BufferPtr, kal_uint32 Length);
kal_int32 MTD_OTPQueryLength (void * DriveData, kal_uint32 *LengthPtr);


/*******************************************************************************
 *  Sub-function declaration
 *******************************************************************************/
kal_int32 ProgramPage_512(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
kal_int32 ReadPage_512(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_512(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_512(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ProgramPage_2K(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 ECCFlag);
kal_int32 ReadPage_2K(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_2K(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_2K(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);

kal_int32 ProgramPage_512_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
kal_int32 ReadPage_512_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_512_default(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_512_default(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ProgramPage_2K_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
kal_int32 ReadPage_2K_default(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_2K_default(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_2K_default(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);

kal_int32 CopyPage_2K(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPage_2K_default(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPermitted_default(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPage_2K_Toshiba(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPage_512_Samsung(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPermitted_Samsung(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPage_via_MCU(void * DriveData, kal_uint32 SrcPageIndex, kal_uint32 DestPageIndex);
kal_int32 CopyPage_2K_test(void * DriveData, kal_uint32 SrcPagesIndex, kal_uint32 DestPageIndex);

kal_int32 ProgramPage_512_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
kal_int32 ReadPage_512_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_512_specific(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_512_specific(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ProgramPage_2K_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag);
kal_int32 ReadPage_2K_specific(void * DriveData, kal_uint32 PageIndex, kal_uint8 * Data, kal_uint8 * Spare, kal_uint8 SpareFlag, kal_uint8 ECCFlag);
kal_int32 ProgramSpare_2K_specific(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);
kal_int32 ReadSpare_2K_specific(void * DriveData, kal_uint32 PagesIndex, kal_uint8 * Data);

kal_int32  OTPAccessDefault(void * DriveData, kal_int32 accesstype, kal_uint32 PageAddr, void *BufferPtr, void *SparePtr);
kal_int32 OTPQueryLengthDefault(void * DriveData, kal_uint32 *Length);


void writefifo_512(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length);
void writefifo_2K(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length);
#ifdef __NFI_VERSION2__
kal_int32 readfifo_512(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint8 Spare_Flag, kal_uint32 length);
kal_int32 readfifo_2K(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint8 Spare_Flag, kal_uint32 length);
#else
void readfifo_512(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length);
void readfifo_2K(kal_uint8* data, kal_uint8* spare, kal_uint8 ECC_flag, kal_uint32 length);
#endif

void cmd_resetpointer(void);
void cmd_sparepointer(void);
kal_uint8 read_status(void);
kal_uint8 read_cp_status(void);
kal_int32 InitializeMTD(void * DriveData);
kal_int32 InitializeMTDData(void * DriveData);
void nfi_lisr(void);
void nfi_hisr(void);
void NFI_DMA_Callback(void);
void pdn_nfi(kal_bool ON);
char NAND4X_GPIO_ReturnMode(char port);
kal_bool NAND4X_INT_USBBoot(void);



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

#endif //NAND_MTD_INTERNAL_H

