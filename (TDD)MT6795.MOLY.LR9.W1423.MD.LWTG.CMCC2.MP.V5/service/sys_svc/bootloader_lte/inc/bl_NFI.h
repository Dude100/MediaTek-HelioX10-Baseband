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
 *   bl_NFI.h
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   Item test - NANDFlash test.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _BOOTLOADER_NFI_H
#define _BOOTLOADER_NFI_H

#if defined(MT6238) || defined(MT6235)  || defined(MT6239) || defined(MT6235B)  || defined(MT6268A) || defined(MT6268) || defined(MT6236) || defined(MT6236B) || defined(MT6270A)
    #if !defined __NFI_VERSION2__   /*__NFI_VERSION2__ should be defined at mak file*/
        #define __NFI_VERSION2__
    #endif    
#endif

#include "reg_base.h"
//RHR remove#include "bl_types.h"
// Add for RHR 
#include "bl_nfi_wrapper.h"
//RHR remove#include "kal_non_specific_general_types.h" 
#include "kal_general_types.h"
// Add for RHR 
/* Register definition : NFI VERSION 3 */
#if defined(__NFI_VERSION3_1__)
#elif defined(__NFI_VERSION3__)
#if defined(MT6516) && defined (__APPLICATION_PROCESSOR__)
	#define APCG_CLR0 		((volatile P_U32)(APMCUSYS_CONFIG+0x0340))
	#define CG_CON0_NFI     (0x00020000)
#endif

#define NFI_CNFG        ((volatile P_U16)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile P_U16)(NFI_base+0x0004))
#define NFI_CON         ((volatile P_U16)(NFI_base+0x0008))
#define NFI_ACCCON      ((volatile P_U32)(NFI_base+0x000C))
#define NFI_INTR_EN     ((volatile P_U16)(NFI_base+0x0010))
#define NFI_INTR        ((volatile P_U16)(NFI_base+0x0014))

#define NFI_CMD         ((volatile P_U16)(NFI_base+0x0020))

#define NFI_ADDRNOB     ((volatile P_U16)(NFI_base+0x0030))
#define NFI_COLADDR     ((volatile P_U32)(NFI_base+0x0034))
#define NFI_ROWADDR     ((volatile P_U32)(NFI_base+0x0038))

#define NFI_STRDATA     ((volatile P_U16)(NFI_base+0x0040))

#define NFI_DATAW       ((volatile P_U32)(NFI_base+0x0050))
#define NFI_DATAR       ((volatile P_U32)(NFI_base+0x0054))

#define NFI_STA         ((volatile P_U32)(NFI_base+0x0060))
#define NFI_FIFOSTA     ((volatile P_U16)(NFI_base+0x0064))
#define NFI_LOCKSTA     ((volatile P_U16)(NFI_base+0x0068))

#define NFI_ADDRCNTR    ((volatile P_U16)(NFI_base+0x0070))

#define NFI_STRADDR     ((volatile P_U32)(NFI_base+0x0080))
#define NFI_BYTELEN     ((volatile P_U16)(NFI_base+0x0084))

#define NFI_CSEL        ((volatile P_U16)(NFI_base+0x0090))
#define NFI_IOCON       ((volatile P_U16)(NFI_base+0x0094))

#define NFI_FDM0L       ((volatile P_U32)(NFI_base+0x00A0))
#define NFI_FDM0M       ((volatile P_U32)(NFI_base+0x00A4))

#define NFI_LOCK        ((volatile P_U16)(NFI_base+0x0100))
#define NFI_LOCKCON     ((volatile P_U32)(NFI_base+0x0104))
#define NFI_LOCKANOB    ((volatile P_U16)(NFI_base+0x0108))
#define NFI_LOCK00ADD   ((volatile P_U32)(NFI_base+0x0110))
#define NFI_LOCK00FMT   ((volatile P_U32)(NFI_base+0x0114))
#define NFI_LOCK01ADD   ((volatile P_U32)(NFI_base+0x0118))
#define NFI_LOCK01FMT   ((volatile P_U32)(NFI_base+0x011C))
#define NFI_LOCK02ADD   ((volatile P_U32)(NFI_base+0x0120))
#define NFI_LOCK02FMT   ((volatile P_U32)(NFI_base+0x0124))
#define NFI_LOCK03ADD   ((volatile P_U32)(NFI_base+0x0128))
#define NFI_LOCK03FMT   ((volatile P_U32)(NFI_base+0x012C))
#define NFI_LOCK04ADD   ((volatile P_U32)(NFI_base+0x0130))
#define NFI_LOCK04FMT   ((volatile P_U32)(NFI_base+0x0134))
#define NFI_LOCK05ADD   ((volatile P_U32)(NFI_base+0x0138))
#define NFI_LOCK05FMT   ((volatile P_U32)(NFI_base+0x013C))
#define NFI_LOCK06ADD   ((volatile P_U32)(NFI_base+0x0140))
#define NFI_LOCK06FMT   ((volatile P_U32)(NFI_base+0x0144))
#define NFI_LOCK07ADD   ((volatile P_U32)(NFI_base+0x0148))
#define NFI_LOCK07FMT   ((volatile P_U32)(NFI_base+0x014C))
#define NFI_LOCK08ADD   ((volatile P_U32)(NFI_base+0x0150))
#define NFI_LOCK08FMT   ((volatile P_U32)(NFI_base+0x0154))
#define NFI_LOCK09ADD   ((volatile P_U32)(NFI_base+0x0158))
#define NFI_LOCK09FMT   ((volatile P_U32)(NFI_base+0x015C))
#define NFI_LOCK10ADD   ((volatile P_U32)(NFI_base+0x0160))
#define NFI_LOCK10FMT   ((volatile P_U32)(NFI_base+0x0164))
#define NFI_LOCK11ADD   ((volatile P_U32)(NFI_base+0x0168))
#define NFI_LOCK11FMT   ((volatile P_U32)(NFI_base+0x016C))
#define NFI_LOCK12ADD   ((volatile P_U32)(NFI_base+0x0170))
#define NFI_LOCK12FMT   ((volatile P_U32)(NFI_base+0x0174))
#define NFI_LOCK13ADD   ((volatile P_U32)(NFI_base+0x0178))
#define NFI_LOCK13FMT   ((volatile P_U32)(NFI_base+0x017C))
#define NFI_LOCK14ADD   ((volatile P_U32)(NFI_base+0x0180))
#define NFI_LOCK14FMT   ((volatile P_U32)(NFI_base+0x0184))
#define NFI_LOCK15ADD   ((volatile P_U32)(NFI_base+0x0188))
#define NFI_LOCK15FMT   ((volatile P_U32)(NFI_base+0x018C))

#define NFI_FIFODATA0   ((volatile P_U32)(NFI_base+0x0190))
#define NFI_FIFODATA1   ((volatile P_U32)(NFI_base+0x0194))
#define NFI_FIFODATA2   ((volatile P_U32)(NFI_base+0x0198))
#define NFI_FIFODATA3   ((volatile P_U32)(NFI_base+0x019C))

/* NFI_CNFG */
#define CNFG_AHB             (0x0001)
#define CNFG_READ_EN         (0x0002)
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

/* NFI_CON */
#define CON_FIFO_FLUSH       (0x0001)
#define CON_NFI_RST          (0x0002)
#define CON_NFI_SRD          (0x0010)

#define CON_NFI_NOB_MASK     (0x0060)
#define CON_NFI_NOB_SHIFT    (5)

#define CON_NFI_BRD          (0x0100)
#define CON_NFI_BWR          (0x0200)

#define CON_NFI_SEC_MASK     (0xF000)
#define CON_NFI_SEC_SHIFT    (12)

/* NFI_ACCCON */
#define ACCCON_SETTING       ()

/* NFI_INTR_EN */
#define INTR_RD_DONE_EN      (0x0001)
#define INTR_WR_DONE_EN      (0x0002)
#define INTR_RST_DONE_EN     (0x0004)
#define INTR_ERASE_DONE_EN   (0x0008)
#define INTR_BSY_RTN_EN      (0x0010)
#define INTR_ACC_LOCK_EN     (0x0020)
#define INTR_AHB_DONE_EN     (0x0040)

/* NFI_INTR */
#define INTR_RD_DONE         (0x0001)
#define INTR_WR_DONE         (0x0002)
#define INTR_RST_DONE        (0x0004)
#define INTR_ERASE_DONE      (0x0008)
#define INTR_BSY_RTN         (0x0010)
#define INTR_ACC_LOCK        (0x0020)
#define INTR_AHB_DONE        (0x0040)

/* NFI_ADDRNOB */
#define ADDR_COL_NOB_MASK    (0x0003)
#define ADDR_COL_NOB_SHIFT   (0)
#define ADDR_ROW_NOB_MASK    (0x0030)
#define ADDR_ROW_NOB_SHIFT   (4)

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
#define FIFO_RD_EMPTY        (0x0040)
#define FIFO_RD_FULL         (0x0080)
#define FIFO_WR_FULL         (0x8000)
#define FIFO_WR_EMPTY        (0x4000)
#define FIFO_RD_REMAIN(x)    (0x1F&(x))
#define FIFO_WR_REMAIN(x)    ((0x1F00&(x))>>8)

/* NFI_ADDRCNTR */
#define ADDRCNTR_CNTR(x)     ((0xF000&(x))>>12)
#define ADDRCNTR_OFFSET(x)   (0x03FF&(x))

/* NFI_LOCK */
#define NFI_LOCK_ON          (0x0001)

/* NFI_LOCKANOB */
#define PROG_RADD_NOB_MASK   (0x7000)
#define PROG_RADD_NOB_SHIFT  (12)
#define PROG_CADD_NOB_MASK   (0x0300)
#define PROG_CADD_NOB_SHIFT  (8)
#define ERASE_RADD_NOB_MASK  (0x0070)
#define ERASE_RADD_NOB_SHIFT (4)
#define ERASE_CADD_NOB_MASK  (0x0007)
#define ERASE_CADD_NOB_SHIFT (0)

/* Nand flash command */
#define RD_1ST_CMD              (0x00)
#define RANDOM_RD_1ST_CMD       (0x05)
#define RD_2ND_HALF_CMD         (0x01)    // only for 512 bytes page-size
#define RD_SPARE_CMD            (0x50)    // only for 512 bytes page-size
#define RD_2ND_CYCLE_CMD        (0x30)    // only for 2K  bytes page-size
#define RANDOM_RD_2ND_CMD       (0xE0)
#define RD_FOR_COPYBACK         (0x35)
#define RD_FOR_CACHECOPY        (0x3A)
#define COPY_1ST_CMD            (0x85)
#define COPY_PAGE_CMD           (0x8C)
#define COPY_2ND_CMD            (0x10)
#define COPY_PROGRAM            (0x8A)
#define INPUT_DATA_CMD          (0x80)
#define PLANE_INPUT_DATA_CMD    (0x81)
#define RANDOM_INPUT_DATA_CMD   (0x85)
#define PROG_DATA_CMD           (0x10)
#define PLANE_PROG_DATA_CMD     (0x11)
#define CACHE_PROG_CMD          (0x15)
#define BLOCK_ERASE1_CMD        (0x60)
#define BLOCK_ERASE2_CMD        (0xD0)
#define RD_ID_CMD               (0x90)
#define RD_STATUS_CMD           (0x70)
#define RD_CACHE_STATUS_CMD     (0x71)
#define RESET_CMD               (0xFF)
#define CACHE_START_CMD         (0x11)
#define CACHE_RD_START_CMD      (0x31)
#define CACHE_RD_END_CMD        (0x3F)
#define CACHE_RD_COL_CMD        (0x05)
#define CACHE_RD_CONFIRM_CMD    (0xE0)

#define RD_CHIP1_STATUS_CMD     (0xF1)
#define RD_CHIP2_STATUS_CMD     (0xF2)

/* device status */
#define DEVICE_READY            (0x40)
#define OPERATION_FAIL          (0x01)

#define CHIP1_DISTRICT0_FAIL    (0x02)
#define CHIP1_DISTRICT1_FAIL    (0x04)
#define CHIP2_DISTRICT0_FAIL    (0x08)
#define CHIP2_DISTRICT1_FAIL    (0x10)
#define MULTI_DEVICE_READY      (0x20)
#define DATA_CACHE_READY        (0x40)
#define CHIP1_FAIL              (0x01)
#define CHIP2_FAIL              (0x02)

#define NAND_PLANE_OPERATIONS   (2)

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

//#define BL_ACCON      (0x00077fff)
#define BL_ACCON      (0x00033333)

#define BL_WRITE_CNFG (CNFG_OP_PRGM)
#define BL_READ_CNFG  (CNFG_READ_EN|CNFG_OP_READ)
#define BL_SRD_CNFG   (CNFG_READ_EN|CNFG_BYTE_RW|CNFG_OP_SRD)
#define BL_ERASE_CNFG (CNFG_OP_ERASE)

#define ECC_ENCCON      ((volatile P_U16)(ECC_base+0x0000))
#define ECC_ENCCNFG     ((volatile P_U32)(ECC_base+0x0004))
#define ECC_ENCDIADDR   ((volatile P_U32)(ECC_base+0x0008))
#define ECC_ENCIDLE     ((volatile P_U32)(ECC_base+0x000C))
#define ECC_ENCPAR0     ((volatile P_U32)(ECC_base+0x0010))
#define ECC_ENCPAR1     ((volatile P_U32)(ECC_base+0x0014))
#define ECC_ENCPAR2     ((volatile P_U32)(ECC_base+0x0018))
#define ECC_ENCPAR3     ((volatile P_U32)(ECC_base+0x001C))
#define ECC_ENCPAR4     ((volatile P_U32)(ECC_base+0x0020))
#define ECC_ENCSTA      ((volatile P_U32)(ECC_base+0x0024))
#define ECC_ENCIRQEN    ((volatile P_U16)(ECC_base+0x0028))
#define ECC_ENCIRQSTA   ((volatile P_U16)(ECC_base+0x002C))

#define ECC_DECCON      ((volatile P_U16)(ECC_base+0x0100))
#define ECC_DECCNFG     ((volatile P_U32)(ECC_base+0x0104))
#define ECC_DECDIADDR   ((volatile P_U32)(ECC_base+0x0108))
#define ECC_DECIDLE     ((volatile P_U16)(ECC_base+0x010C))
#define ECC_DECFER      ((volatile P_U16)(ECC_base+0x0110))
#define ECC_DECENUM     ((volatile P_U32)(ECC_base+0x0114))
#define ECC_DECDONE     ((volatile P_U16)(ECC_base+0x0118))
#define ECC_DECEL0      ((volatile P_U32)(ECC_base+0x011C))
#define ECC_DECEL1      ((volatile P_U32)(ECC_base+0x0120))
#define ECC_DECEL2      ((volatile P_U32)(ECC_base+0x0124))
#define ECC_DECEL3      ((volatile P_U32)(ECC_base+0x0128))
#define ECC_DECEL4      ((volatile P_U32)(ECC_base+0x012C))
#define ECC_DECEL5      ((volatile P_U32)(ECC_base+0x0130))
#define ECC_DECIRQEN    ((volatile P_U16)(ECC_base+0x0134))
#define ECC_DECIRQSTA   ((volatile P_U16)(ECC_base+0x0138))
#define ECC_FDMADDR     ((volatile P_U32)(ECC_base+0x013C))

/*******************************************************************************
 * ECC register bit definition
 *******************************************************************************/
/* ECC_ENCON */
#define ENC_EN                 (0x0001)

/* ECC_ENCCNFG */
#define ECC_CNFG_ECC4          (0x0000)
#define ECC_CNFG_ECC6          (0x0001)
#define ECC_CNFG_ECC8          (0x0002)
#define ECC_CNFG_ECC10         (0x0003)
#define ECC_CNFG_ECC12         (0x0004)
#define ECC_CNFG_ECC_MASK      (0x00000007)

#define ECC_CNFG_NFI           (0x0010)
#define ECC_CNFG_MODE_MASK     (0x0010)

#define ECC_CNFG_META6         (0x10300000)
#define ECC_CNFG_META8         (0x10400000)

#define ENC_CNFG_MSG_MASK      (0x1FFF0000)
#define ENC_CNFG_MSG_SHIFT     (0x10)

/* ECC_ENCIDLE */
#define ENC_IDLE               (0x0001)

/* ECC_ENCSTA */
#define STA_FSM                (0x001F)
#define STA_COUNT_PS           (0xFF10)
#define STA_COUNT_MS           (0x3FFF0000)

/* ECC_ENCIRQEN */
#define ENC_IRQEN              (0x0001)

/* ECC_ENCIRQSTA */
#define ENC_IRQSTA             (0x0001)

/* ECC_DECCON */
#define DEC_EN                 (0x0001)

/* ECC_ENCCNFG */
//#define DEC_CNFG_ECC4          (0x0000)
//#define DEC_CNFG_ECC6          (0x0001)
//#define DEC_CNFG_ECC12         (0x0002)
//#define DEC_CNFG_NFI           (0x0010)
//#define DEC_CNFG_META6         (0x10300000)
//#define DEC_CNFG_META8         (0x10400000)

#define DEC_CNFG_FER           (0x01000)
#define DEC_CNFG_EL            (0x02000)
#define DEC_CNFG_CORRECT       (0x03000)
#define DEC_CNFG_TYPE_MASK     (0x03000)

#define DEC_CNFG_EMPTY_EN      (0x80000000)

#define DEC_CNFG_CODE_MASK     (0x1FFF0000)
#define DEC_CNFG_CODE_SHIFT    (0x10)

/* ECC_DECIDLE */
#define DEC_IDLE           (0x0001)

/* ECC_DECFER */
#define DEC_FER0               (0x0001)
#define DEC_FER1               (0x0002)
#define DEC_FER2               (0x0004)
#define DEC_FER3               (0x0008)
#define DEC_FER4               (0x0010)
#define DEC_FER5               (0x0020)
#define DEC_FER6               (0x0040)
#define DEC_FER7               (0x0080)

/* ECC_DECENUM */
#define ERR_NUM0               (0x0000000F)
#define ERR_NUM1               (0x000000F0)
#define ERR_NUM2               (0x00000F00)
#define ERR_NUM3               (0x0000F000)
#define ERR_NUM4               (0x000F0000)
#define ERR_NUM5               (0x00F00000)
#define ERR_NUM6               (0x0F000000)
#define ERR_NUM7               (0xF0000000)

/* ECC_DECDONE */
#define DEC_DONE0               (0x0001)
#define DEC_DONE1               (0x0002)
#define DEC_DONE2               (0x0004)
#define DEC_DONE3               (0x0008)
#define DEC_DONE4               (0x0010)
#define DEC_DONE5               (0x0020)
#define DEC_DONE6               (0x0040)
#define DEC_DONE7               (0x0080)

/* ECC_DECIRQEN */
#define DEC_IRQEN               (0x0001)

/* ECC_DECIRQSTA */
#define DEC_IRQSTA              (0x0001)

#define NAND_SECTOR_SIZE        (512)
#define NAND_SECTOR_SHIFT		(9)
#define FDMDATA_SIZE			(3)

#if defined(MT6516)
#define MCU_CYCLE_TIME_NS 	(3)
#endif

#define NORMAL_BUSY_PERIOD   (500000/MCU_CYCLE_TIME_NS)
#define DATA_TRANSFER_PERIOD (6000000/MCU_CYCLE_TIME_NS)
#define PROG_BUSY_PERIOD     (700000/MCU_CYCLE_TIME_NS)
#define ERASE_BUSY_PERIOD    (3000000/MCU_CYCLE_TIME_NS)
    
typedef enum
{
   NFI_ECC_CORRECTED      = 0xD0,
   NFI_OPERATION_SUCCESS  = 0xE0,
   NFI_BAD_BLOCK          = 0xF0,
   NFI_ECC_UNCORRECT      = 0xF1,
   NFI_ECC_TIMEOUT        = 0xF2,
   NFI_CMD_TIMEOUT        = 0xF3,
   NFI_ADDR_TIMEOUT       = 0xF4,
   NFI_DATA_TIMEOUT       = 0xF5,
   NFI_PROG_TIMEOUT       = 0xF6,
   NFI_BLOCKERASE_TIMEOUT = 0xF7,
   NFI_READ_TIMEOUT       = 0xF8,
   NFI_RESET_TIMEOUT      = 0xF9,
   NFI_PROG_FAILED        = 0xFA,
   NFI_BLOCKERASE_FAILED  = 0xFB
} NFI_Error_Code;

/************************************************************************
 * Macro definition
 ************************************************************************/
#define WAIT_ENC_READY_WITH_TIMEOUT(timeout) \
do {\
   while( (!(*ECC_ENCIDLE & ENC_IDLE)) && (--timeout) );\
} while(0);

#define WAIT_ENC_READY \
do {\
   while(!(*ECC_ENCIDLE & ENC_IDLE));\
} while(0);

#define WAIT_ENC_PARITY_READY \
do {\
   while(*ECC_ENCSTA & STA_COUNT_MS);\
} while(0);

#define WAIT_DEC_READY_WITH_TIMEOUT(timeout) \
do {\
   while( (!(*ECC_DECIDLE & DEC_IDLE)) && (--timeout) );\
} while(0);

#define WAIT_DEC_DONE_WITH_TIMEOUT(blk_idx, timeout) \
do {\
   while( (!(*ECC_DECDONE & (1<<blk_idx))) && (--timeout) );\
} while(0);

#define WAIT_DEC_READY \
do {\
   while(!(*ECC_DECIDLE & DEC_IDLE));\
} while(0);

#define START_ECC_DEC \
do{\
   *ECC_DECCON = 0;\
   *ECC_DECCON = DEC_EN;\
}while(0);

#define STOP_ECC_DEC \
do{\
   *ECC_DECCON = 0;\
}while(0);

#define START_ECC_ENC \
do{\
   *ECC_ENCCON = 0;\
   *ECC_ENCCON = ENC_EN;\
}while(0);

#define STOP_ECC_ENC \
do{\
   *ECC_ENCCON = 0;\
}while(0);

#define GET_ECC_ERRNUM(val)\
do{\
   val = *ECC_DECENUM;\
}while(0);

#define GET_ECC_ERRDONE(val) \
do{\
   val = *ECC_DECDONE;\
}while(0);

#define ECC_PARITY_NUM        (156)

#define ECC_PARITY_BITS       (13)

typedef enum {
   ECC_DEC_DETECT,
   ECC_DEC_LOCATE,
   ECC_DEC_CORRECT,
   ECC_DEC_NONE
} ECC_Decode_Type_t;

typedef enum {
   ECC_4_BITS,
   ECC_6_BITS,
   ECC_8_BITS,
   ECC_10_BITS,
   ECC_12_BITS,
   NUM_OF_ECC
} ECC_Level_t;


#elif defined(__NFI_VERSION2__)
	#if !defined(__NAND_FDM_50__)
	/* Register definition : NFI VERSION 2  */
	//#if defined(MT6270A)
	//#define NFI_base        (0x710E0000)
	//#elif defined(MT6236) || defined(MT6236B)
	//#define NFI_base        (0x80110000)
	//#elif defined(MT6268A) || defined(MT6268)
	//#define NFI_base        (0x85120000)
	//#else
	//#define NFI_base        (0x81120000)
	//#endif
	
	
	#define NFI_ACCCON      ((volatile kal_uint32 *)(NFI_base+0x0000))
	#define NFI_PAGEFMT     ((volatile kal_uint16 *)(NFI_base+0x0004))
	#define NFI_OPCON       ((volatile kal_uint16 *)(NFI_base+0x0008))
	#define NFI_CMD         ((volatile kal_uint16 *)(NFI_base+0x0010))
	#define NFI_ADDNOB      ((volatile kal_uint16 *)(NFI_base+0x0020))
	#define NFI_ADDRL       ((volatile kal_uint32 *)(NFI_base+0x0024))
	#define NFI_ADDRM       ((volatile kal_uint32 *)(NFI_base+0x0028))
	#define NFI_DATAW       ((volatile kal_uint32 *)(NFI_base+0x0030))
	#define NFI_DATAWB      ((volatile kal_uint16 *)(NFI_base+0x0034))
	#define NFI_DATAR       ((volatile kal_uint32 *)(NFI_base+0x0038))
	#define NFI_DATARB		  ((volatile kal_uint16 *)(NFI_base+0x003C))
	#define NFI_PSTA        ((volatile kal_uint32 *)(NFI_base+0x0040))
	#define NFI_FIFOSTA     ((volatile kal_uint16 *)(NFI_base+0x0044))
	#define NFI_FIFODATA0   ((volatile kal_uint32 *)(NFI_base+0x0050))
	#define NFI_FIFODATA1   ((volatile kal_uint32 *)(NFI_base+0x0054))
	#define NFI_FIFODATA2   ((volatile kal_uint32 *)(NFI_base+0x0058))
	#define NFI_FIFODATA3   ((volatile kal_uint32 *)(NFI_base+0x005C))
	#define NFI_CON         ((volatile kal_uint16 *)(NFI_base+0x0060))
	#define NFI_INTR        ((volatile kal_uint32 *)(NFI_base+0x0064))
	#define NFI_INTR_EN     ((volatile kal_uint32 *)(NFI_base+0x0068))
	#define NFI_PAGECNTR    ((volatile kal_uint16 *)(NFI_base+0x0070))
	#define NFI_ADDRCNTR    ((volatile kal_uint16 *)(NFI_base+0x0074))
	#define NFI_SYM0_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0080))
	#define NFI_SYM1_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0084))
	#define NFI_SYM2_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0088))
	#define NFI_SYM3_ADDR   ((volatile kal_uint16 *)(NFI_base+0x008C))
	#define NFI_SYM4_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0090))
	#define NFI_SYM5_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0094))
	#define NFI_SYM6_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0098))
	#define NFI_SYM7_ADDR   ((volatile kal_uint16 *)(NFI_base+0x009C))
	#define NFI_SYMS0_ADDR  ((volatile kal_uint16 *)(NFI_base+0x00A0))
	#define NFI_SYMS1_ADDR  ((volatile kal_uint16 *)(NFI_base+0x00A4))
	#define NFI_SYMS2_ADDR  ((volatile kal_uint16 *)(NFI_base+0x00A8))
	#define NFI_SYMS3_ADDR  ((volatile kal_uint16 *)(NFI_base+0x00AC))
	#define NFI_SYM0_DAT    ((volatile kal_uint32 *)(NFI_base+0x00B0))
	#define NFI_SYM1_DAT    ((volatile kal_uint32 *)(NFI_base+0x00B4))
	#define NFI_SYM2_DAT    ((volatile kal_uint32 *)(NFI_base+0x00B8))
	#define NFI_SYM3_DAT    ((volatile kal_uint32 *)(NFI_base+0x00BC))
	#define NFI_SYM4_DAT    ((volatile kal_uint32 *)(NFI_base+0x00C0))
	#define NFI_SYM5_DAT    ((volatile kal_uint32 *)(NFI_base+0x00C4))
	#define NFI_SYM6_DAT    ((volatile kal_uint32 *)(NFI_base+0x00C8))
	#define NFI_SYM7_DAT    ((volatile kal_uint32 *)(NFI_base+0x00CC))
	#define NFI_SYMS0_DAT   ((volatile kal_uint32 *)(NFI_base+0x00D0))
	#define NFI_SYMS1_DAT   ((volatile kal_uint32 *)(NFI_base+0x00D4))
	#define NFI_SYMS2_DAT   ((volatile kal_uint32 *)(NFI_base+0x00D8))
	#define NFI_SYMS3_DAT   ((volatile kal_uint32 *)(NFI_base+0x00DC))
	#define NFI_PAR_0P      ((volatile kal_uint16 *)(NFI_base+0x00E0))
	#define NFI_PAR_0C      ((volatile kal_uint16 *)(NFI_base+0x00E4))
	#define NFI_PAR_1P      ((volatile kal_uint16 *)(NFI_base+0x00E8))
	#define NFI_PAR_1C      ((volatile kal_uint16 *)(NFI_base+0x00EC))
	#define NFI_PAR_2P      ((volatile kal_uint16 *)(NFI_base+0x00F0))
	#define NFI_PAR_2C      ((volatile kal_uint16 *)(NFI_base+0x00F4))
	#define NFI_PAR_3P      ((volatile kal_uint16 *)(NFI_base+0x00F8))
	#define NFI_PAR_3C      ((volatile kal_uint16 *)(NFI_base+0x00FC))
	#define NFI_PAR_4P      ((volatile kal_uint16 *)(NFI_base+0x0100))
	#define NFI_PAR_4C      ((volatile kal_uint16 *)(NFI_base+0x0104))
	#define NFI_PAR_5P      ((volatile kal_uint16 *)(NFI_base+0x0108))
	#define NFI_PAR_5C      ((volatile kal_uint16 *)(NFI_base+0x010C))
	#define NFI_PAR_6P      ((volatile kal_uint16 *)(NFI_base+0x0110))
	#define NFI_PAR_6C      ((volatile kal_uint16 *)(NFI_base+0x0114))
	#define NFI_PAR_7P      ((volatile kal_uint16 *)(NFI_base+0x0118))
	#define NFI_PAR_7C      ((volatile kal_uint16 *)(NFI_base+0x011C))
	#define NFI_PARS_0P     ((volatile kal_uint16 *)(NFI_base+0x0120))
	#define NFI_PARS_0C     ((volatile kal_uint16 *)(NFI_base+0x0124))
	#define NFI_PARS_1P     ((volatile kal_uint16 *)(NFI_base+0x0128))
	#define NFI_PARS_1C     ((volatile kal_uint16 *)(NFI_base+0x012C))
	#define NFI_PARS_2P     ((volatile kal_uint16 *)(NFI_base+0x0130))
	#define NFI_PARS_2C     ((volatile kal_uint16 *)(NFI_base+0x0134))
	#define NFI_PARS_3P     ((volatile kal_uint16 *)(NFI_base+0x0138))
	#define NFI_PARS_3C     ((volatile kal_uint16 *)(NFI_base+0x013C))
	#define NFI_ERRDET      ((volatile kal_uint32 *)(NFI_base+0x0140))
	#define NFI_PARECC      ((volatile kal_uint32 *)(NFI_base+0x0144))
	#define NFI_SCON        ((volatile kal_uint16 *)(NFI_base+0x0148))
	#define NFI_CSEL        ((volatile kal_uint16 *)(NFI_base+0x0200))
	#define NFI_IOCON       ((volatile kal_uint16 *)(NFI_base+0x0204))
#endif // !defined(__NAND_FDM_50__)
#else	// #if defined(__NFI_VERSION2__)
//#define NFI_base        (0x80090000)
#define NFI_ACCCON      ((volatile kal_uint16 *)(NFI_base+0x0000))
#define NFI_PAGEFMT     ((volatile kal_uint16 *)(NFI_base+0x0004))
#define NFI_OPCON       ((volatile kal_uint16 *)(NFI_base+0x0008))
#define NFI_CMD         ((volatile kal_uint16 *)(NFI_base+0x000C))
#define NFI_ADDNOB      ((volatile kal_uint16 *)(NFI_base+0x0010))
#define NFI_ADDRL       ((volatile kal_uint32 *)(NFI_base+0x0014))
#define NFI_ADDRM       ((volatile kal_uint16 *)(NFI_base+0x0018))
#define NFI_DATAW       ((volatile kal_uint32 *)(NFI_base+0x001C))
#define NFI_DATAWB      ((volatile kal_uint16 *)(NFI_base+0x0020))
#define NFI_DATAR       ((volatile kal_uint32 *)(NFI_base+0x0024))
#define NFI_DATARB	   ((volatile kal_uint16 *)(NFI_base+0x0028))
#define NFI_PSTA        ((volatile kal_uint16 *)(NFI_base+0x002C))
#define NFI_FIFOCON     ((volatile kal_uint16 *)(NFI_base+0x0030))
#define NFI_CON         ((volatile kal_uint16 *)(NFI_base+0x0034))
#define NFI_INTR        ((volatile kal_uint16 *)(NFI_base+0x0038))
#define NFI_INTR_EN     ((volatile kal_uint16 *)(NFI_base+0x003C))
#define NFI_PAGECNTR	   ((volatile kal_uint16 *)(NFI_base+0x0040))
#define NFI_ADDRCNTR	   ((volatile kal_uint16 *)(NFI_base+0x0044))
#define NFI_SYM0_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0050))
#define NFI_SYM1_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0054))
#define NFI_SYM2_ADDR   ((volatile kal_uint16 *)(NFI_base+0x0058))
#define NFI_SYM3_ADDR   ((volatile kal_uint16 *)(NFI_base+0x005C))
#define NFI_SYM0_DAT    ((volatile kal_uint32 *)(NFI_base+0x0060))
#define NFI_SYM1_DAT    ((volatile kal_uint32 *)(NFI_base+0x0064))
#define NFI_SYM2_DAT    ((volatile kal_uint32 *)(NFI_base+0x0068))
#define NFI_SYM3_DAT    ((volatile kal_uint32 *)(NFI_base+0x006C))
#define NFI_ERRDET      ((volatile kal_uint16 *)(NFI_base+0x0070))
#define NFI_PAR0        ((volatile kal_uint16 *)(NFI_base+0x0080))
#define NFI_PAR1        ((volatile kal_uint16 *)(NFI_base+0x0084))
#define NFI_PAR2        ((volatile kal_uint16 *)(NFI_base+0x0088))
#define NFI_PAR3        ((volatile kal_uint16 *)(NFI_base+0x008C))
#define NFI_PAR4        ((volatile kal_uint16 *)(NFI_base+0x0090))
#define NFI_PAR5        ((volatile kal_uint16 *)(NFI_base+0x0094))
#define NFI_PAR6        ((volatile kal_uint16 *)(NFI_base+0x0098))
#define NFI_PAR7        ((volatile kal_uint16 *)(NFI_base+0x009C))
#define NFI_CSEL	      ((volatile kal_uint16 *)(NFI_base+0x0100))
#endif /*__NFI_VERSION2__*/

#if !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)

/*******************************************************************************
 * NFI register definition
 *******************************************************************************/
#if !defined(__NFI_VERSION2__)
/* NFI_ACCCON */
#define ACCCON			      0x07C6	// C2R=111, W2R=11, WH=00, WST=00, RLT=10

/* NFI_PAGEFMT */
//#define PAGEFMT_512      0x0020
//#define PAGEFMT_2K		   0x0125
#define PAGEFMT_512        0x0000
#define PAGEFMT_2K		   0x0005
#define PAGEFMT_8BITS      0x0000
#define PAGEFMT_16BITS     0x0100

    /* NFI_CSEL */
    #define DEVICE_512		   0x00
    #define DEVICE_2K		      0x01

#endif

/* NFI_OPCON */
#define BURST_RD           0x0001
#define BURST_WR           0x0002
#define ECC_RD_INIT        0x0010
#define ECC_WR_INIT        0x0020
#define SINGLE_RD          0x0100
#define NOB_BYTE           0x1000
#define NOB_WORD           0x2000
#define NOB_DWORD          0x0000
#if defined(__NFI_VERSION2__)
#define OPCON_RESET 0x0C00
#endif

/* Nand flash command */
#define RD_1ST_CMD         0x00
#define RD_2ND_HALF_CMD    0x01	// only for 512 bytes page-size
#define RD_SPARE_CMD      	0x50	// only for 512 bytes page-size
#define RD_2ND_CYCLE_CMD	0x30	// only for 2K  bytes page-size
#define INPUT_DATA_CMD     0x80
#define PROG_DATA_CMD      0x10
#define BLOCK_ERASE1_CMD   0x60
#define BLOCK_ERASE2_CMD   0xD0
#define RD_ID_CMD          0x90
#define RD_STATUS_CMD      0x70
#define RESET_CMD          0xFF



/* NFI_PSTA */
#define STATUS_CMD         0x1
#define STATUS_ADDR        0x2
#define STATUS_DATAR       0x4
#define STATUS_DATAW       0x8
#define STATUS_BUSY        0x100


/* NFI_FIFOCON */
#if defined(__NFI_VERSION2__)

#define RD_EMPTY_MASK  0x40
#define RD_FULL_MASK     0x80
#define WR_EMPTY_MASK 	0x4000
#define WR_FULL_MASK    0x8000
#define FIFO_RD_REMAIN(x) (0x1F&(x))
#define FIFO_WR_REMAIN(x) ((0x1F00&(x))>>8)

#else

#define RD_EMPTY_MASK      0x001
#define RD_FULL_MASK       0x002
#define WR_EMPTY_MASK      0x004
#define WR_FULL_MASK      	0x008
#define FIFO_FLUSH         0x010
#define RESET              0x020

#endif

#define BYTE_RW_EN				0x8000

/* NFI_CON */
#define MULTIPAGE_CON	   0x0800
#define READ_CON_EN		   0x0400
#if ( defined(__NAND_FDM_50__) && defined(__NFI_VERSION2__) )
// Define in NAND_MTD_FDM50_internal.h
#else
#define PROGRAM_CON_EN		0x0200
#define ERASE_CON_EN		   0x0100
#endif
#define SW_PROGSPARE_EN    0x0020
#define MULTI_PAGE_RD_EN   0x0010
#define AUTOECC_ENC_EN     0x0008
#define AUTOECC_DEC_EN     0x0004
#define DMA_WR_EN          0x0002
#define DMA_RD_EN          0x0001

#if defined(__NFI_VERSION2__)
#define MAIN_ECC_EN      0x200
#define SPARE_ECC_EN     0x100
#define AUTO_ECC_ENC    0x8
#define AUTO_ECC_DEC    0x4
#define ECC_BLKSIZE_128 0
#define ECC_BLKSIZE_256 0x10
#define ECC_BLKSIZE_512 0x20
#define ECC_BLKSIZE_1024 0x30
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


/* Status register */
#define RDY_BUSY           0x40
#define PASS_FAIL          0x01

 
/* NFI_INTR_EN */
#if defined(__NFI_VERSION2__)
#define RD_COMPLETE_EN     0x1000
#define WR_COMPLETE_EN     0x2000
#define RESET_COMPLETE_EN  0x4000
#define ERASE_COMPLETE_EN  0x8000
#define BUSY_RETURN_EN     0x10000000
#define ALL_EN         0x1000f000
#else
#define RD_COMPLETE_EN     0x01
#define WR_COMPLETE_EN     0x02
#define RESET_COMPLETE_EN  0x04
#define ERASE_COMPLETE_EN  0x08
#define ERR_DET_EN         0x10
#define ERR_COR_EN         0x20
#define BUSY_RETURN_EN     0x40
#define ALL_EN             0x7F
#endif

/* NFI_INTR */
#if defined(__NFI_VERSION2__)
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

#endif //!defined(__NFI_VERSION3__)

/*========================================================================
 Type definition 
=========================================================================*/

#define  IO_8BITS   0x0000
#define  IO_16BITS  0x0001

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
#elif defined(MCU_68_714M)
/* 1T ~= 14.5 ns */
#define COUNTER_200nS   (14)

#elif defined(MCU_78M)
/* 1T ~= 12.8 ns */
#define COUNTER_200nS 	(15)

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

/*========================================================================
 Prototypes 
=========================================================================*/

void NFI_Init(void);
void NFI_DeInit(void);
#if defined(__NFI_VERSION3__) || defined(__NFI_VERSION3_1__)
void NFI_Config(const NFI_MENU *input, const NFI_SUBMENU* sub_para);
#endif //defined(__NFI_VERSION3__)
void NFIReconfigure(void);
kal_bool GoodBlockChecking(NFI_MENU *input, kal_uint32 addr1, kal_uint16 addr2);
_RET_CODE NFI_PageRead(kal_uint32 *destination, kal_uint32 *parity, kal_uint32 length, \
                       kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, \
                       kal_uint16 pageSize, kal_bool ECC, kal_bool continous);
_RET_CODE NFI_ParityCheck(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, \
                          kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize, \
                          kal_uint16 IO, kal_uint32 blockSize);                       
kal_int32 NFB_ReadPhysicalPageWithSpare_NoTT(kal_uint32 PhyBlock, kal_uint32 PhyPage, kal_uint32 *Data, kal_uint32 *Spare);
#if !defined(__NFI_VERSION3__) && !defined(__NFI_VERSION3_1__)
kal_int32 NFB_CheckGoodBlock_NoTT(NFI_MENU *input, kal_uint32 Block);
#endif

#if defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)
void EmulateBitError(kal_uint32 *destination, kal_uint32 *parity, kal_uint16 addr_no, kal_uint32 addr1, kal_uint16 addr2, kal_uint16 pageSize);
void BL_NFI_Test(kal_uint32 *Buffer);
#endif  // defined(BIT_ERROR_TEST) || defined(BL_NFI_TEST)
                  
#endif
