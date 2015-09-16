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
 *   Sd_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of SD/MMC driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef SD_DEF_H
#define SD_DEF_H

//RHR ADD
#include "kal_general_types.h"
#include "drv_trc.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
*/
//RHR
#include "drv_features.h"
#include "dcl.h"
#include "dcl_msdc.h"
#include "msdc_api.h"
/*--------------------------------*/
/*SDC register address */
/*--------------------------------*/

/*sdmmc register*/
#define SDC_CFG			(MSDC_ADRS + 0x30)
#define SDC_CMD			(MSDC_ADRS + 0x34)
#define SDC_ARG			(MSDC_ADRS + 0x38)
#define SDC_STS			(MSDC_ADRS + 0x3c)
#define SDC_RESP0		(MSDC_ADRS + 0x40)
#define SDC_RESP1		(MSDC_ADRS + 0x44)
#define SDC_RESP2		(MSDC_ADRS + 0x48)
#define SDC_RESP3		(MSDC_ADRS + 0x4c)
#define SDC_BLK_NUM	(MSDC_ADRS + 0x50)
#define SDC_CSTS		(MSDC_ADRS + 0x58)
#define SDC_CSTS_EN		(MSDC_ADRS + 0x5c)
#define SDC_DCRC_STS	(MSDC_ADRS + 0x60)
/*emmc register*/
#define EMMC_CFG0		(MSDC_ADRS + 0x70)
#define EMMC_CFG1		(MSDC_ADRS + 0x74)
#define EMMC_STS		(MSDC_ADRS + 0x78)
#define EMMC_IOCON		(MSDC_ADRS + 0x7c)
/*auto command register*/
#define SDC_ACMD_RESP	(MSDC_ADRS + 0x80)
#define SDC_ACMD19_TRG	(MSDC_ADRS + 0x84)
#define SDC_ACMD19_STS (MSDC_ADRS + 0x88)



/*SDC_CFG mask*/
#define SDC_CFG_SDIOINTWKUP 		(0x1 << 0)		 /*RW*/
#define SDC_CFG_INSWKUP 			(0x1 << 1)		 /*RW*/
#define SDC_CFG_BUSWIDTH 			(0x3 << 16)		 /*RW*/
#define SDC_CFG_SDIO 				(0x1 << 19)		 /*RW*/
#define SDC_CFG_SDIOIDE 			(0x1 << 20)		 /*RW*/
#define SDC_CFG_INTATGAP 			(0x1 << 21)		 /*RW*/
#define SDC_CFG_DTOC 				(0xffUL << 24)	 /*RW*/


/*SDC_CMD mask*/
#define SDC_CMD_OPC 				(0x3f <<0)		 /*RW*/
#define SDC_CMD_BRK 				(0x1 << 6)		 /*RW*/
#define SDC_CMD_RSPTYP 			(0x7 << 7)		 /*RW*/
#define SDC_CMD_DTYP 				(0x3 <<11)		 /*RW*/
#define SDC_CMD_RW 				(0x1 << 13)		 /*RW*/
#define SDC_CMD_STOP				 (0x1 << 14)		 /*RW*/
#define SDC_CMD_GOIRQ 				(0x1 << 15)			 /*RW*/
#define SDC_CMD_BLKLEN 				(0xfff << 16)		 /*RW*/
#define SDC_CMD_AUTOCMD 			(0x3 << 28)			 /*RW*/
#define SDC_CMD_VOLSWTH 			(0x1 << 30)		 /*RW*/

/*SDC_STS mask */
#define SDC_STS_SDCBUSY 			(0x1 << 0)			 /*RW*/
#define SDC_STS_CMDBUSY 			(0x1 << 1)			 /*RW*/
#define SDC_STS_SWR_COMPL 			(0x1 << 31)			 /*RW*/


/*SDC_DCRC_STS mask*/
#define SDC_DCRC_STS_NEG 			(0xf << 8)			/*RO*/
#define SDC_DCRC_STS_POS 			(0xff << 0)			/*RO*/

/*EMMC_CFG0 mask*/
#define EMMC_CFG0_BOOTSTART 		(0x1 << 0) 		/*W*/
#define EMMC_CFG0_BOOTSTOP		(0x1 << 1) 		/*W*/
#define EMMC_CFG0_BOOTMODE 		(0x1 << 2) 		/*RW*/
#define EMMC_CFG0_BOOTWDLY 		(0x7 << 12) 		/*RW*/
#define EMMC_CFG0_BOOTACKDIS 		(0x1 << 3) 		/*RW*/
#define EMMC_CFG0_BOOTSUPP		(0x1 << 15) 		/*RW*/

/*EMMC_CFG1 mask*/
#define EMMC_CFG1_BOOTDATTMC 		(0xfffff << 0) 		/*RW*/
#define EMMC_CFG1_BOOTACKTMC 		(0xfffUL << 20) 		/*RW*/

/*EMMC_STS mask*/
#define EMMC_STS_BOOTCRCERR 		(0x1 << 0) 		/*W1C*/
#define EMMC_STS_BOOTACKERR 		(0x1 << 1) 		/*W1C*/
#define EMMC_STS_BOOTDATTMO 		(0x1 << 2)		 /*W1C*/
#define EMMC_STS_BOOTACKTMO 		(0x1 << 3) 		/*W1C*/
#define EMMC_STS_BOOTUPSTATE		 (0x1 << 4)		 /*R*/
#define EMMC_STS_BOOTACKRCV 		(0x1 << 5)		 /*W1C*/
#define EMMC_STS_BOOTDATRCV 		(0x1 << 6) 		/*R*/


/*EMMC_IOCON mask*/
#define EMMC_IOCON_BOOTRST 		(0x1 << 0)		/*RW*/


/*SDC_ACMD19_TRG mask*/
#define MSDC_ACMD19_TRG_TUNESEL 	(0xf << 0)		 /*RW*/

#define SDC_NO_ARG 0


#define SDC_OCR_DEFAULT		0x00FF8000
#define SDC_OCR_QUERY		0x0
#define TRY_OCR				20 
#define SDC_OCR_BUSY			0x80000000
#define SDC_RCA_DEFAULT		0x0000
#define	ARG_RCA_MASK		0xffff0000
#define SDC_RCA_MMC			1
#define SDC_DSR_DEFAULT		0x0404
#define SDC_NO_ARG			0
#define SDC_MAX_BKLENGTH	2048
#define SDC_MAX_LOCKBK		34
#define SDC_CMD8_ARG			0x000001AA			// the argument of the CMD8
#define SD_ACMD41_HCS		0x40000000			// indicate host support high capacity card.
#define SD_ACMD41_XPC		0x10000000
#define SD_ACMD41_S18R      0x01000000          // indicate host support 1.8v
#define SD_CMD6_RESP_LEN	64						// lenght of the CMD6 response
#define SD_CMD6_QUERY_SWITCH    0x00FF0000          //cmd6 query the function
#define SD_CMD6_SELECT_SWITCH   0x80FF0000          //cmd6 select the function
#define SD_CMD6_QUERY_SUPPORT_FUNCTION 0x00FFFFFF  //use to get the functions supported by the card
#define SD_CMD6_QUERY_HIGH_SPEED		0x00FFFFF1	// argument of CMD6 to query the high speed interface
#define SD_CMD6_SELECT_HIGH_SPEED	0x80FFFFF1	// argument of CMD6 to query the high speed interface
#define SD_FUNC_HIGH_SPEED				0x1
#define SD_CSD_VER_20					0x01

#define SD_FLAG_MMC_MRSW_FAIL  (0x01)		// some special MMC card will fail at multi-read follow a single wirte
#define SD_FLAG_HCS_SUPPORT	 (0x02)		// support block access mode
#define SD_FLAG_CMD6_SUPPORT	 (0x04)		// support CMD6 (SD1.1 higher)
#define SD_FLAG_HS_SUPPORT		 (0x08)		// support high speed interface (SD1.1 higher)
#define SD_FLAG_HS_ENABLED		 (0x10)		// enable high speed interface (SD1.1 higher)	
#define SD_FLAG_SD_TYPE_CARD	 (0x20)		// to indicate SD or MMC type card
#define SD_FLAG_USE_USB_CLK	 (0x40)		// to indicate use USB clock
#define SD_FLAG_UHS_ENABLED      (0x80)   //enable UHS interface
#define SD_FLAG_UHS_SUPPORT      (0x100)   //support  UHS interface


#define SD_FLAG_LIMITED_HIGH_SPEED_CARD	(0x8000) // to indicate special high speed card that we can only run with 26M

	
								
#define MSDC_SD_BLOCK_SIZE		128		// * 4byte
#define SECTOR_SIZE 512

#define MSDC_TUNE_UHS_SCLK      (100000000)

typedef kal_uint32 SDC_CMD_STATUS;
// ERROR definition of SDC_CMD_STATUS
#define NO_ERROR				0
#define ERR_CMD_TIMEOUT			1
#define ERR_APP_CMD_NOT_ACCEPT	2
#define ERR_R3_OCR_BUSY			3
#define ERR_RCA_FAIL			4
#define ERR_INVALID_CARD		5
#define ERR_INVALID_BKLENGTH	6  // over 2048 or not multiple of 4
#define ERR_DAT_CRCERR			7
#define ERR_RW_CMDERR			8
#define ERR_CMD_RSPCRCERR		9
#define ERR_DAT_TIMEOUT			10
#define ERR_STATUS				11
#define ERR_LOCK_UNLOCK_FAILED  12
#define ERR_APPCMD_FAILED		13
#define ERR_NOT_SUPPORT_4BITS   14
#define ERR_NORESP				15
#define ERR_WRITE_PROTECT		16
#define ERR_DATA_NOT_READY		17
#define ERR_CARD_NOT_PRESENT	18
#define ERR_OCR_NOT_SUPPORT	19
#define ERR_DAT_ERROR			20
#define SDIO_4MI_NOT_SUPPORT  21
#define ERR_MMC_BUS_HS_ERROR	22
#define ERR_SendEXTCSD			23
#define ERR_CMD8_INVALID		24
#define ERR_SD_HS_FAIL			25		// SD change high speed interface fail
#define ERR_NOT_FOUND			26
#define ERR_ACB_FAIL			27
#define ERR_ACB_TIMEOUT			28
#define ERR_ACB_STA_ENABLE_FAIL	29
#define ERR_ERRORS				30	// general errors
#define ERR_INVALID_BLOCK		31
#define ERR_MMC_SWITCH_ERROR    32
#define ERR_CARD_BUSY_TIMEOUT   33
#define ERR_HIGH_SPEED_BUSY     34
#define ERR_HIGH_SPEED_TIMEOUT  35
#define ERR_HIGH_SPEED_COMMON_ERROR 36
#define ERR_HIGH_SPEED_NOT_SUPPORT 37
#define ERR_HIGH_SPEED_CONSUMPTION 38
#define ERR_ARGUMENT			39

#define CARD_IS_LOCKED			60
#define CHECK_DATA_CMD_LOW_FAIL 61
#define ERR_SWITCH_BUSY 62
#define ERR_SWITCH_TIMEOUT 63
#define ERR_SPEED_MODE_UNSUPPORT 64
#define ERR_DRIVER_TYPE_UNSUPPORT 65
#define ERR_CURRENT_LIMIT_UNSUPPORT 66


/* MMC bus commands */
#define CMD0_GO_IDLE_STATE          0x00    /* Resets the MMC */
#define CMD1_SEND_OP_COND           0x01    /* Activates the card's initialization process */
#define CMD2_ALL_SEND_CID           0x02    /* Asks all cards in ready state to send their CID */
#define CMD3_SET_RELATIVE_ADDR      0x03    /* Assigns relative address to the card in identification state */
#define CMD4_SET_DSR                0x04    /* Sets drive stage register DSR */
#define CMD7_SELECT_CARD            0x07
#define CMD9_SEND_CSD               0x09    /* Asks the selected card to send its CSD */
#define CMD10_SEND_CID              0x0A    /* Asks the selected card to send its CID */
#define CMD11_READ_DAT_UNTIL_STOP_MMC   0x0B
#define CMD12_STOP_TRANSMISSION     0x0C    /* Stop data transmission */
#define CMD13_SEND_STATUS           0x0D    /* Asks the selected card to send its status register */
#define CMD15_GO_INACTIVE_STATE     0x0F
#define CMD16_SET_BLOCKLEN          0x10    /* Selects a block length for all following block commands */
#define CMD17_READ_SINGLE_BLOCK     0x11    /* Reads a block of the size selected by the SET_BLOCKLEN command */
#define CMD18_READ_MULTIPLE_BLOCK   0x12
#define CMD20_WRITE_DAT_UNTIL_STOP_MMC  0x14
#define CMD24_WRITE_SINGLE_BLOCK    0x18    /* Writes a block of the size selected by SET_BLOCKLEN command */
#define CMD25_WRITE_MULTIPLE_BLOCK  0x19     /* Writes multiple block until CMD 12 */
#define CMD26_PROGRAM_CID           0x1A
#define CMD27_PROGRAM_CSD           0x1B    /* Programming of the programmable bits of the CSD */
#define CMD28_SET_WRITE_PROT        0x1C    /* If the card has write protection features, sets the write protection bit */
#define CMD29_CLR_WRITE_PROT        0x1D    /* If with write protection features, clears the write protection bit */
#define CMD30_SEND_WRITE_PROT       0x1E    /* If with write protection features, asks the card to send status of write protection bit */
#define CMD32_TAG_SECTOR_START      0x20    /* Sets the address of the first sector */
#define CMD33_TAG_SECTOR_END        0x21    /* Sets the address of the last sectore */
#define CMD34_UNTAG_SECTOR          0x22    /* Removes one previously selected sector */
#define CMD35_TAG_ERASE_GROUP_START 0x23    /* Sets the address of the first erase group */
#define CMD36_TAG_ERASE_GROUP_END   0x24    /* Sets the address of the last erase group */
#define CMD37_UNTAG_ERASE_GROUP     0x25    /* Removes on previously selected erase group */
#define CMD38_ERASE                 0x26    /* Erases all previously selected sectors */
#define CMD39_FAST_IO_MMC           0x27
#define CMD40_GO_IRQ_STATE          0x28    
#define CMD42_LOCK_UNLOCK           0x2A    /* Used to set/reset the password or lock/unlock the card */
#define CMD55_APP					0x37	/* Indicates to the card the next cmd is an application specific command */
#define CMD56_GEN					0x38	/* Used either to transfer a data block or to get a data block form the card for general purpse */

// commnad value for MSDC controller SDC_CMD
// not include the SDC_CMD  LEN[27:16] !!
#define SDC_CMD_CMD0			0x0000		/*	response_none*/
#define SDC_CMD_CMD1			0x0181		/*	response_r3   */
#define SDC_CMD_CMD2			0x0102		/*	response_r2    */
#define SDC_CMD_CMD3			0x0083		/*	response_r6   */
#define SDC_CMD_CMD3_MMC		0x0083		/*	response_r1*/
#define SDC_CMD_CMD4			0x0004		/*	response_none*/
#define SDC_CMD_CMD5			0x0185		/*	response_r3*/
#define SDC_CMD_CMD5_MMC		0x0385		/*	response_r1b*/
#define SDC_CMD_CMD6			0x0886		/*	response_r1 +single_block + read*/
#define SDC_CMD_CMD6_MMC		0x0386		/*	response_r1b*/
#define SDC_CMD_CMD7			0x0387		/*	response_r1b*/
#define SDC_CMD_CMD8			0x0088		/*	response_r7*/
#define SDC_CMD_CMD8_MMC40	0x0888		/*	response_r1+single_blokc+read*/
#define SDC_CMD_CMD9			0x0109		/*	response_r2*/
#define SDC_CMD_CMD10			0x010a		/* 	response_r2                                                  the response time delay is not NID(5 cycles)*/
#define SDC_CMD_CMD11			0x4000008b	/*	response_r1+ switch vlot*/
#define SDC_CMD_CMD11_MMC		0x188b 		/*	response_r1*/
#define SDC_CMD_CMD12			0x438c		/*	response_r1b+stop command*/
#define SDC_CMD_CMD13			0x008d		/*	response_r1*/
#define SDC_CMD_CMD15			0x000f		/*	response_none*/
#define SDC_CMD_CMD16			0x0090		/*	response_r1*/
#define SDC_CMD_CMD17			0x0891		/*	response_r1+single_block+read*/
#define SDC_CMD_CMD18			0x1092		/*	response_r1+mutli_block+read*/
#define SDC_CMD_CMD19			0x0893		/*	response_r1+single_block_read*/
#define SDC_CMD_CMD19_MMC		0x0093		/*	response_r1*/
#define SDC_CMD_CMD20_MMC		0x3894		/*	response_r1+stream_write*/
#define SDC_CMD_CMD20			0x0394		/*	response_r1b*/
#define SDC_CMD_CMD23			0x0097		/*	response_r1*/
#define SDC_CMD_CMD24			0x2898		/*	response_r1+single_block+write*/
#define SDC_CMD_CMD25			0x3099		/*	response_r1+mutli_block+write*/
#define SDC_CMD_CMD26			0x009a		/*	response_r1*/
#define SDC_CMD_CMD26_MMC		0x289a		/*	response_r1+single_block+write*/
#define SDC_CMD_CMD27			0x289b		/*	response_r1+single_block_write*/
#define SDC_CMD_CMD28			0x039c		/*	response_r1b*/
#define SDC_CMD_CMD29			0x039d		/*	response_r1b*/
#define SDC_CMD_CMD30			0x089e		/*	response_r1+single_block_read*/
#define SDC_CMD_CMD31_MMC		0x039f		/*	response_r1b*/
#define SDC_CMD_CMD32			0x00a0		/*	response_r1*/
#define SDC_CMD_CMD33			0x00a1		/*	response_r1*/
#define SDC_CMD_CMD35_MMC		0x00a3		/*	response_r1*/
#define SDC_CMD_CMD36_MMC		0x00a4		/*	response_r1*/
#define SDC_CMD_CMD38			0x03a6		/*	response_r1b*/
#define SDC_CMD_CMD39_MMC		0x0227		/*	response_r4*/
#define SDC_CMD_CMD40_MMC		0x80a8		/*	response_r5*/   
#define SDC_CMD_CMD42			0x28aa 		/*	response_r1+single_block+write*/    
#define SDC_CMD_CMD55			0x00b7     	/*	response_r1*/
#define SDC_CMD_CMD56			0x08b8		/*	response_r1+single_block*/
#define SDC_CMD_ACMD6			0x0086		/*	response_r1*/
#define SDC_CMD_ACMD13			0x088d	/*	response_r1+single_block+read*/
#define SDC_CMD_ACMD22			0x0896	/*	response_r1+single_block+read*/	
#define SDC_CMD_ACMD23			0x0097	/*	response_r1*/
#define SDC_CMD_ACMD41			0x01a9	/*	response_r3*/
#define SDC_CMD_ACMD42			0x00aa	/*	response_r1*/
#define SDC_CMD_ACMD51			0x08b3	/*	response_r1+single_block+read*/	

#define SDC_CMD_CMD6_SD11		0x0886	// SWITCH

/* SDIO command*/
#define SDC_CMD_CMD52			0x00b4	/*	response_r5                  STOp field will be set while used to Stop data transfer*/
#define SDC_CMD_CMD53			0x00b5	/*	response_r5                  the RWand DTYPE will be changed according request*/



//masks for command error response(32) of SDC_CSTA
#define SDC_OUT_OF_RANGE		0x80000000
#define SDC_ADDRESS_ERROR		0x40000000
#define SDC_BLOCK_LEN_ERROR		0X20000000
#define SDC_ERASE_SEQ_ERROR		0X10000000
#define SDC_ERASE_PARAM			0X08000000
#define SDC_WP_VIOLATION		0X04000000
#define SDC_CARD_IS_LOCKED		0x02000000
#define SDC_LOCK_UNLOCK_FAILED	0X01000000
#define SDC_COM_CRC_ERROR		0X00800000
#define SDC_ILLEGAL_COMMAND		0X00400000
#define SDC_CARD_ECC_FAILED		0X00200000
#define SDC_CC_ERROR			0X00100000
#define SDC_ERROR				0X00080000
#define SDC_UNDERRUN			0X00040000
#define SDC_OVERRUN				0X00020000
#define SDC_CIDCSD_OVERWRITE	0X00010000
#define MMC_SWITCH_ERROR		0x00000080
#define SDC_AKE_SEQ_ERROR		0X00000008

#define SDC_CSTA_MASK 				0xffff0000

//masks for card status contained in R1
#define R1_AKE_SEQ_ERROR_3			0x00000004
#define R1_APP_CMD_5				0x00000020
#define R1_READY_FOR_DATA_8			0x00000100
#define R1_CURRENT_STATE_9_12		0x00001e00
#define R1_ERASE_RESET_13			0x00002000
#define R1_CARD_ECC_DISABLE_14		0x00004000
#define R1_WP_ERASE_SKIP_15			0x00008000
#define R1_CID_CSD_OVERWRITE_16		0x00010000
#define R1_OVERRUN_17				0x00020000
#define R1_UNDERRUN_18				0x00040000
#define R1_ERROR_19					0x00080000
#define R1_CC_ERROR_20				0x00100000
#define R1_CARD_ECC_FAILED_21		0x00200000
#define R1_ILLEGAL_COMMAND_22		0x00400000
#define R1_COM_CRC_ERROR_23			0x00800000
#define R1_LOCK_UNLOCK_FAILED_24	0x01000000
#define R1_CARD_IS_LOCKED_25		0x02000000
#define R1_WP_VIOLATION_26			0x04000000
#define R1_ERASE_PARAM_27			0x08000000
#define R1_ERASE_SEQ_ERROR_28		0x10000000
#define R1_BLOCK_LEN_ERROR_29		0x20000000
#define R1_ADDRESS_ERROR_30			0x40000000
#define R1_OUT_OF_RANGE_31			0x80000000
#define R1_CUR_STATE				0x00001E00

#define R1_CURRENT_STATE(a)	(kal_uint32)(((a) & R1_CUR_STATE) >> 9)


#define FUN1_SDR12_DS 0x1
#define FUN1_SDR25_HS 0x2
#define FUN1_SDR50 0x4
#define FUN1_SDR104 0x8
#define FUN1_DDR50  0x10
#define FUN2_DEFAULT 0x1
#define FUN2_FOR_EC  0x2
#define FUN2_OTP     0x8
#define FUN2_ASSD    0x10
#define FUN3_TYPE_A  0x1
#define FUN3_TYPE_B  0x2
#define FUN3_TYPE_C  0x4
#define FUN3_TYPE_D  0x8
#define FUN4_200MA  0x1
#define FUN4_400MA  0x2
#define FUN4_600MA  0x4
#define FUN4_800MA  0x8

#define FUN1_SET_SDR12_DS (0x0)
#define FUN1_SET_SDR25_HS (0x1)
#define FUN1_SET_SDR50 (0x2)
#define FUN1_SET_SDR104 (0x3)
#define FUN1_SET_DDR50  (0x4)
#define FUN2_SET_DEFAULT (0x0)
#define FUN2_SET_FOR_EC  (0x1)
#define FUN2_SET_OTP     (0x3)
#define FUN2_SET_ASSD    (0x4)
#define FUN3_SET_TYPE_A  (0x0)
#define FUN3_SET_TYPE_B  (0x1)
#define FUN3_SET_TYPE_C  (0x2)
#define FUN3_SET_TYPE_D  (0x3)
#define FUN4_SET_200MA  (0x0)
#define FUN4_SET_400MA  (0x1)
#define FUN4_SET_600MA  (0x2)
#define FUN4_SET_800MA  (0x3)

/*Card Command Classes(CCC)*/
#define CCC_BASIC   (1<<0)  //cmd0,1,2,3,4,7,9,10,12,13,15 and for SPI cdm58,59
#define CCC_STREAM_READ  (1<<1)  //cmd11
#define CCC_BLOCK_READ (1<<2)   //cmd16,17,18
#define CCC_STREAM_WRITE (1<<3) //CMD20
#define CCC_BLOCK_WRITE (1<<4)  //cmd16,24,25,26,27
#define CCC_ERASE       (1<<5)  //cmd32,33,34,35,36,37,38,39
#define CCC_WRITE_PROT  (1<<6)  //cmd28,29,30
#define CCC_LOCK_CARD   (1<<7)  //cmd16,cmd42
#define CCC_APP_SPEC    (1<<8)  //cmd55,56,57,ACMD
#define CCC_IO_MODE (1<<9)  //cmd5,39,40,52,53
#define CCC_SWITCH     (1<<10)  //cmd6,34,35,36,37,50

#define SCR_SPEC_VER_0      0   //system specification 1.0-1.01
#define SCR_SEC_VER_1      1    //system specification 1.10
#define SCR_SEC_VER_2      2    //system specification 2.00-3.0x

typedef enum {
	IDLE_STA,
	READY_STA,
	IDENT_STA,
	STBY_STA,
	TRAN_STA,
	DATA_STA,
	RCV_STA,
	PRG_STA,
	DIS_STA,
	INV_STA
}T_SDC_STATE;

typedef enum{
	SD_CMD8_RESP_NORESP,		// before SD2.0 version or MMC
	SD_CMD8_RESP_INVALID,	// SD 2.0 or higher compliant but voltage condition is not allow
	SD_CMD8_RESP_VALID		// SD 2.0 or higher compliant
}SD_CMD8_RESP;

typedef enum{
	eMMC_boot_partition1 = 1,
	eMMC_boot_partition2,
	eMMC_RPMB,
	eMMC_GP_partition1,
	eMMC_GP_partition2,
	eMMC_GP_partition3,
	eMMC_GP_partition4,
	eMMC_user_Area
} eMMC_partitions;





typedef struct{
	kal_bool isEmmcV44;
	kal_bool supportPartition;
	kal_bool supportEnhancedPart;
	kal_uint32 bootPartitionSize; //size of boot partition, the uint is 512-byte
	kal_uint32 gp1PartitionSize; //size of GP1 partition, the uint is 512-byte
}t_emmc_info;

#define MSDC_SD_BLOCK_SIZE				128	// x4 bytes
#define EXT_CSD_BUS_WIDTH_INDEX		183
#define EXT_CSD_HIGH_SPPED_INDEX		185
#define EXT_CSD_POW_CLASS_INDEX			187
#define EXT_CSD_PARTITION_CONFIG_INDEX	179
#define EXT_CSD_BOOT_BUS_WIDTH_INDEX	177
#define EXT_CSD_ERASE_GRP_DEF			175
#define EXT_CSD_RT_FUNCTION_INDEX		162
#define EXT_CSD_GP_SIZE_MULT_GP0_INDEX	143
#define EXT_CSD_ENH_SIZE_MULT_INDEX		140
#define EXT_CSD_ENABLE_HIGH_SPEED	1
#define MMC_HIGH_DESITY_CHECK_BIT	(0x40000000)
#define MMC_HIGH_DESITY_CHECK_MSK	(0x60000000)



#define EMMC_MASK_PARTITION_SETTING	0x1
#define EMMC_MASK_PARTITION_CONFIG	0x7


typedef struct {
#ifndef MSDC_MMC441_SUPPORT
	kal_uint8 rev1[183];
#else
	kal_uint8 mmc44_rev0[136];	/*[135:0]*/
	kal_uint32 enh_start_addr; 	/*[139:136]*/
	kal_uint8 enh_size_mult[3];	/*[142:140]*/
	kal_uint8 gp_size_mult[12];	/*[154:143]*/
	kal_uint8 partition_settig;		/*[155]*/
	kal_uint8 partition_attr;		/*[156]*/
	kal_uint8 max_enh_size_mult[3];		/*[159:157]*/
	kal_uint8 partition_support;	/*[160]*/
	kal_uint8 mmc44_rev1;		/*[161]*/
	kal_uint8 rst_function;		/*[162]*/
	kal_uint8 mmc44_rev2[5];		/*[167:163]*/
	kal_uint8 rpmb_size_mul;		/*[168]*/
	kal_uint8 fw_config;			/*[169]*/
	kal_uint8 mmc44_rev3;		/*[170]*/
	kal_uint8 user_wp;			/*[171]*/
	kal_uint8 mmc44_rev4;		/*[172]*/
	kal_uint8 boot_wp;			/*[173]*/
	kal_uint8 mmc44_rev5;		/*[174]*/
	kal_uint8 erase_grp_def;		/*[175]*/
	kal_uint8 mmc44_rev6;		/*[176]*/
	kal_uint8 boot_bus_width;		/*[177]*/
	kal_uint8 boot_config_prot;	/*[178]*/
	kal_uint8 partition_config;		/*[179]*/
	kal_uint8 mmc44_rev7;		/*[180]*/
	kal_uint8 erased_mem_cont;	/*[181]*/
	kal_uint8 mmc44_rev8;		/*[182]*/
#endif
	kal_uint8 bus_width;
	kal_uint8 rev2;
	kal_uint8 high_speed;
	kal_uint8 rev3;
	kal_uint8 power_class;
	kal_uint8 rev4;
	kal_uint8 cmd_set_rev;
	kal_uint8 rev5;
	kal_uint8 cmd_set;
	kal_uint8 ext_csd_rev;
	kal_uint8 rev7;
	kal_uint8 ext_csd_ver;
	kal_uint8 rev8;
	kal_uint8 card_type;
	kal_uint8 rev9;
	kal_uint8 out_of_interrupt_time;
	kal_uint8 partition_switch_time;
	kal_uint8 pwr_52_195;
	kal_uint8 pwr_26_195;
	kal_uint8 pwr_52_360;
	kal_uint8 pwr_26_360;
	kal_uint8 rev10;
	kal_uint8 min_perf_r_4_26;
	kal_uint8 min_perf_w_4_26;
	kal_uint8 min_perf_r_8_26_4_52;
	kal_uint8 min_perf_w_8_26_4_52;
	kal_uint8 min_perf_r_8_52;
	kal_uint8 min_perf_w_8_52;
	kal_uint8 resv11;
	kal_uint32 sec_count;	/*newly defined in MMC42*/
#ifndef MSDC_MMC441_SUPPORT
	kal_uint8 rev12[288];
#else
	kal_uint8 mmc44_rev9[5];	/*[220:216]*/
	kal_uint8 hc_wp_grp_size;		/*221*/
	kal_uint8 rel_wr_sec_c;		/*222*/
	kal_uint8 erase_timeout_mult;	/*223*/
	kal_uint8 hc_erase_grp_size;	/*224*/
	kal_uint8 acc_size;			/*225*/
	kal_uint8 boot_size_mul;		/*[226]*/
	kal_uint8 mmc44_rev10;		/*[227]*/
	kal_uint8 boot_info;			/*[228]*/
	kal_uint8 mmc44_rev11[275];		/*[503:229]*/
#endif
	kal_uint8 s_cmd_set;
	kal_uint8 rev13[7];
}T_EXT_CSD_MMC40;

typedef enum{
	SD_SPEC_101,
	SD_SPEC_110,
	SD_SPEC_200,
	SD_SPEC_30X
}SD_SPEC;
typedef enum{
	CSD_VER_1_0 = 0,
	CSD_VER_1_1 = 0,
	CSD_VER_2_0 = 1,
	CSD_VER_EXT
 }CSD_VER_ENUM;

/* Card Specific Data(CSD) register structure */
typedef struct {
   kal_uint8   tacc;				   /* read access time-1 */
   kal_uint8   nsac;				   /* read access time-2 */
   kal_uint8   tran_speed;			   /* max. data transfer rate */
   kal_uint16  ccc;					   /* card command classes */
   kal_uint32  w_blk_len;              /* actual write block length in bytes */
   kal_uint32  r_blk_len;              /* actual read block length in bytes */
   kal_uint32  max_w_blk_len;          /* max write data block length */
   kal_uint32  max_r_blk_len;          /* max read data block length */
   kal_uint8   w_blk_misali;           /* write block misalighment */
   kal_uint8   r_blk_misali;           /* read block misalighment */
   kal_uint8   w_blk_part;             /* partial blocks for write allowed */
   kal_uint8   r_blk_part;             /* partial blocks for write allowed */
   kal_uint32  erase_sec_size_mmc;     /* erase sector size */
   kal_uint32  erase_grp_size_mmc;     /* erase group size */
   kal_uint32  wp_grp_size_mmc;        /* write protect group size */
   kal_uint8   erase_blk_en_sd;
   kal_uint32  erase_sec_size_sd;
   kal_uint32  wp_prg_size_sd;
   kal_uint8   wp_grp_enable;          /* write protect group enable */
   kal_uint64  capacity;               /* capacity in bytes */
   kal_uint16  cmd_class;              /* card command classes */
   kal_uint8   temp_wp;                /* temporary write protection  */
   kal_uint8   perm_wp;                /* permanent write protection  */
   kal_uint8   dsr_imp;
   CSD_VER_ENUM 	csd_ver;					/* the version of CSD structure */
   kal_uint8	spec_ver;					/* defne the MMC system spec. */
   T_EXT_CSD_MMC40 *ext_csd;				/* pointer to EXT_CSD */
} T_CSD;

typedef struct {
	kal_uint8	mid;
	kal_uint16	oid;
	kal_uint8	pnm[6];
	kal_uint8	prv;
	kal_uint32	psn;
	kal_uint16	year;
	kal_uint8	month;
}T_CID;

typedef struct {
	kal_uint8 dat_after_erase;
	kal_uint8 security;
	kal_uint8 bus_width;
	kal_uint8 sd_spec3;
	kal_uint8 cmd_support;
	SD_SPEC spec_ver;
}T_SCR;

typedef struct {
    unsigned char   dat_bus_width:2,
                    secured_mode:1,
                    rsv1:5;
    unsigned char   rsv2:2,
                    rsv3:6;
    unsigned short  sd_card_type;
    unsigned int    size_of_prot_area;
    unsigned char   speed_class;
    unsigned char   perf_move;
    unsigned char   au_size:4,
                    rsv4:4;
    unsigned short  erase_size;
    unsigned char   erase_timeout:6,
                    erase_offset:2;
    unsigned char   uhs_speed_grade:4,
                    uhs_au_size:4;
    unsigned char   rsv5[49];
}T_SD_STATUS;

typedef struct {
	kal_uint32		mSDC_ocr;	// store the OCR
	kal_uint32		mBKLength;	// store the block length
	kal_uint32 		mBKNum;		// store the block numbers
	kal_uint32		flags;		// for some special case handling
	T_CSD				mCSD;		// card specific data
	T_CID				mCID;		// card idendtification
	T_SCR				mSCR;		// only for SD
	T_SD_STATUS         mSDSts;
	kal_uint16		mRCA;		// store relative card address
	T_SDC_STATE		mState;		// indicate the current state
	kal_bool			mInactive;	// indicate whether card in inactive state
	kal_uint8		bus_width;	// indicate 4-bits data line enable
	kal_bool			mWPEnabled;	// indicate write protection is enabled(SD)
	kal_bool			mIsLocked;	// indicate whether the card is locked by switch
	kal_bool			mCD_DAT3;	// indicate the pull-up resistor of CD_DAT3 pin
	kal_bool            mIsBlkAddr;
	SD_CMD8_RESP	mCMD8Resp;		// receive response after CMD8 (SD2.0 or higher)
	MSDC_LOCK_TAG	mSDdrv_lock;	// lock for sd_drv adaption layer
#if defined(MSDC_MMC441_SUPPORT)
	t_emmc_info		emmc_info;
#endif
	kal_uint32 sd_r;
	kal_uint32 sd_w;
    T_SWITCH_SUPPROT_FUNCTIONS card_support;
    T_SWITCH_SUPPROT_FUNCTIONS function_set;
}T_SDC_HANDLE;

typedef struct{
	kal_uint32 max_current	: 16;
	kal_uint32 group6_info	: 16;
	kal_uint32 group5_info	: 16;
	kal_uint32 group4_info	: 16;
	kal_uint32 group3_info	: 16;
	kal_uint32 group2_info	: 16;
	kal_uint32 group1_info	: 16;
	kal_uint32 group6_result: 4;
	kal_uint32 group5_result: 4;
	kal_uint32 group4_result: 4;
	kal_uint32 group3_result: 4;
	kal_uint32 group2_result: 4;
	kal_uint32 group1_result: 4;
	kal_uint32 ver				: 8;
	kal_uint32 group6_busy	: 16;
	kal_uint32 group5_busy	: 16;
	kal_uint32 group4_busy	: 16;
	kal_uint32 group3_busy	: 16;
	kal_uint32 group2_busy	: 16;
	kal_uint32 group1_busy	: 16;
	kal_uint8  rev[34];
}T_SWITCH_STATUS;



typedef enum{
	SET_PWD,
	CLR_PWD,
	LOCK_CARD,
	UNLOCK_CARD,
	ERASE
}SD_LOCK_OP;

typedef enum{
	BIT_1_MMC40,
	BIT_4_MMC40,
	BIT_8_MMC40
}BUS_WIDHT_MMC40;
typedef enum{
	HS_26M = 1,
	HS_52M = 2
}EXT_CSD_CARD_TYPE_MMC40;





// bit masks     
#define BIT_MASK_1 0x01
#define BIT_MASK_2 0x03
#define BIT_MASK_3 0x07
#define BIT_MASK_4 0x0F
#define BIT_MASK_5 0x1F
#define BIT_MASK_6 0x3F
#define BIT_MASK_7 0x7F
#define BIT_MASK_8 0xFF
#define GET_BIT(byte, bit_pos, bit_mask)    (((byte) & ((bit_mask)<<(bit_pos)))>> (bit_pos))

#ifndef __MSDC_BASIC_LOAD__
#define SD_TRACE2(a,b,c,d)	drv_trace2(a, b, c, d)
#else
#define SD_TRACE2(a,b,c,d)	dbg_print("SD error in file %d, line %d\n\r", c,d)
#endif
#define SD_INITIALIZE_STATUS_CHECK()	\
{\
	if(NO_ERROR != status)\
	{\
	    MSDC_ERR("[MSDC][%s %d]%x\r\n",__FUNCTION__,__LINE__,status);\
		SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);\
		goto err;\
	}\
}
#define MSDC_ERROR		1
#define MSDC_OK			0

#define SD_IS_SDC_BUSY()  	(!!(MSDC_Reg32(SDC_STS)&SDC_STS_SDCBUSY))
#define SD_IS_CMD_BUSY() 	(!!(MSDC_Reg32(SDC_STS)&SDC_STS_CMDBUSY))
#define SD_IS_R1B_BUSY()	(!(MSDC_Reg32(MSDC_PS)&(1<<16)))

#define MSDC_BD_MAX 128 
extern msdc_gpd_t MSDC_gpd[SD_NUM];
extern msdc_gpd_t MSDC_gpd_end[SD_NUM];

extern msdc_bd_t MSDC_bd[SD_NUM][MSDC_BD_MAX];
extern T_SDC_HANDLE * gSD;
extern T_SDC_HANDLE	gSD_blk[SD_NUM];
SDC_CMD_STATUS SD_SendCmd(kal_uint32 cmd,kal_uint32 arg,kal_uint32 timeout_ms);
void SD_Cmd8(void);

SDC_CMD_STATUS SD_Reset(void);
SDC_CMD_STATUS SD_Cmd55(kal_uint16 rca);
SDC_CMD_STATUS SD_Cmd1_MMC(void);
SDC_CMD_STATUS SD_Acmd41_SD(void);
SDC_CMD_STATUS SD_GetCID(kal_uint32 Cid[4]);
SDC_CMD_STATUS SD_ValidateRCA(kal_uint16* pRca);
SDC_CMD_STATUS SD_SetDSR(void);
SDC_CMD_STATUS SD_SelectCard(kal_uint16 rca);
SDC_CMD_STATUS SD_GetCSD(kal_uint16 rca, kal_uint32 Csd[4]);
SDC_CMD_STATUS SD_GetStatus(kal_uint16 rca, kal_uint32* resp);
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength);
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer);
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num);
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer);
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num);
SDC_CMD_STATUS SD_SetBusWidth(SD_BITWIDTH width);
SDC_CMD_STATUS SD_ReadSCR(kal_uint32* scr);
SDC_CMD_STATUS SD_ReadSDStatus(kal_uint32* sd_status);
SDC_CMD_STATUS SD_SendEXTCSD_MMC40(kal_uint32* rxbuffer);
SDC_CMD_STATUS SD_Initialize(void);
SDC_CMD_STATUS SD_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum);
SDC_CMD_STATUS SD_SetPreEraseBlk(kal_uint32 num);
SDC_CMD_STATUS SD_CheckStatus(void);
SDC_CMD_STATUS SD_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set);
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void);
SDC_CMD_STATUS SD_SwitchSpeedMode(void);

SDC_CMD_STATUS SD_GpdWriteMultiBlock(kal_uint32 address ,kal_uint32 num_blk,void *gpd_data);
SDC_CMD_STATUS SD_GpdReadMultiBlock(kal_uint32 address ,kal_uint32 num_blk,void *gpd_data );

kal_bool SD_QMU_Init(void);

void SD_closeFastFormat(void);
void SD_startFastFormat(void);

extern SDC_CMD_STATUS SD_StopTrans(void);













/*following 2 API is used to declare the beginning and ending of high level format*/
void SD_startFastFormat(void);
void SD_closeFastFormat(void);

int  MountDevice(void * DriveData, int DeviceNumber, int DeviceType, kal_uint32 Flags);
int  ReadSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);
int  WriteSectors(void * DriveData, kal_uint32 Sector, kal_uint32 Sectors, void * Buffer);





#endif // end of SD_DEF_H


