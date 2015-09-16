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
 *    dcl_msdc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file defines common part of msdc related modules.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef DCL_DEFINITION_STRUCT
#ifndef __DCL_MSDC_H_FRONT__
#define __DCL_MSDC_H_FRONT__

//RHR ADD
#include "dcl.h"
#include "kal_general_types.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
*/
//RHR

#define	DCL_MSDC_HW_MSDC1	1
#define	DCL_MSDC_HW_MSDC2	2

/*********************************************************************************************************
*followings we defines the structure used by DCL user, this is prevent DCL user from include invividual moudles' header file.
**********************************************************************************************************/
typedef DCL_UINT32				DCL_SDC_CMD_STATUS;//this is to replace SDC_CMD_STATUS 


/*this is to replace cmd53_op_enum*/
typedef enum{
	DCL_SDIO_FIX,	//multi byte r/w at fixed address
	DCL_SDIO_INC	//multi byte r/w at incrementing address 
}DCL_SDIO_cmd53_op_enum;

/*this is to replace SDIO_function_id_enum*/
typedef enum{
	DCL_SDIO_FUCN_0=0,
	DCL_SDIO_FUCN_1,
	DCL_SDIO_MAX_FUCN_ID, 
	DCL_SDIO_FUCN_MEM=0x1000
}DCL_SDIO_function_id_enum;

/*this is to replace SD_BITWIDTH*/
typedef enum{
	DCL_BIT_1W = 0x0000,
	DCL_BIT_4W = 0x0002
}DCL_SD_BITWIDTH;

typedef void ( *MSDC_CALLBACK) (void);
#define DCL_SECTOR_SIZE		512

/*******************************************************************************
 * driver function tables exposed to DCL, in SD layer, SDIO layer, and MSDC layer
 *******************************************************************************/
/*here are type definition for functions*/
typedef DCL_SDC_CMD_STATUS (*DCL_SINGLE_BLK_RD) (DCL_UINT32 data_adrs, DCL_UINT32 *rxbuffer);
typedef DCL_SDC_CMD_STATUS (*DCL_MUL_BLK_RD) (DCL_UINT32 data_adrs, DCL_UINT32 *rxbuffer, DCL_UINT32 num);
typedef DCL_SDC_CMD_STATUS (*DCL_SINGLE_BLK_WR) (DCL_UINT32 address, DCL_UINT32 *txbuffer);
typedef DCL_SDC_CMD_STATUS (*DCL_MUL_BLK_WR) (DCL_UINT32 address, DCL_UINT32 *txbuffer, DCL_UINT32 num);
typedef DCL_SDC_CMD_STATUS (*DCL_SD_INITITALIZE) (void);
typedef DCL_SDC_CMD_STATUS (*DCL_SET_PRE_ERASE_CNT) (DCL_UINT32 num);
typedef DCL_SDC_CMD_STATUS (*DCL_SD_SET_CALLBACK)(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3,MSDC_CALLBACK callback4,MSDC_CALLBACK callback5,MSDC_CALLBACK callback6);
typedef DCL_SDC_CMD_STATUS (*DCL_SET_READ_TEST_FLAG)(kal_uint32 readTestFlag);
typedef	DCL_SDC_CMD_STATUS(*DCL_SD_READ_TEST)(void);
typedef	DCL_SDC_CMD_STATUS(*DCL_SD_SET_UPLL_CLOCK_TEST)(void);
typedef	DCL_SDC_CMD_STATUS(*DCL_SD_ERASE_BLK)(DCL_UINT32 startSector, DCL_UINT32 sectorNum);
typedef DCL_SDC_CMD_STATUS (*DCL_GPD_MUL_BLK_RD) (DCL_UINT32 data_addrs,DCL_UINT32 num, void *data_buf);
typedef DCL_SDC_CMD_STATUS (*DCL_GPD_MUL_BLK_WR) (DCL_UINT32 data_addrs,DCL_UINT32 num, void *data_buf);


typedef struct
{
	DCL_SINGLE_BLK_RD singleBlkRd;
	DCL_MUL_BLK_RD mulBlkRd;
	DCL_SINGLE_BLK_WR singleBlkWr;
	DCL_MUL_BLK_WR mulBlkWr;
	DCL_SD_INITITALIZE sdInititalize;
	DCL_SET_PRE_ERASE_CNT setPreEraseCnt;
	DCL_SD_SET_CALLBACK sdSetCallBack;
	DCL_SET_READ_TEST_FLAG sdSetReadTestFlag;
	DCL_SD_READ_TEST sdSetReadTest;	
	DCL_SD_SET_UPLL_CLOCK_TEST sdSetUpllClock;
	DCL_SD_ERASE_BLK eraseBlk;
    DCL_GPD_MUL_BLK_RD GpdMulBlkRd;
    DCL_GPD_MUL_BLK_WR GpdMulBlkWr;
}SDDriver_t;


typedef DCL_BOOL (*DCL_SDIO_REG_WR) (DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op);
typedef DCL_BOOL (*DCL_SDIO_REG_WR_ISR) (DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op);
typedef DCL_BOOL (*DCL_SDIO_DATA_WR) (DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8  *data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block);
typedef DCL_BOOL (*DCL_SDIO_REG_RD) (DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 *data, DCL_SDIO_cmd53_op_enum op);
typedef DCL_BOOL (*DCL_SDIO_DATA_RD) (DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8  *data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CHECK_INTR) (DCL_SDIO_function_id_enum function, DCL_BOOL *pending);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_ENABLE_INTR) (DCL_SDIO_function_id_enum function, DCL_BOOL enable);
typedef DCL_UINT32 (*DCL_SDIO_INIT) (void);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_ABORT) (DCL_SDIO_function_id_enum function);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_SW_RST) (void);
typedef DCL_UINT32 (*DCL_SDIO_QRY_BLOCK_SIZE) (DCL_SDIO_function_id_enum function);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_SET_BLOCK_SIZE) (DCL_SDIO_function_id_enum function, DCL_UINT32 size);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_GET_BLOCK_SIZE) (DCL_SDIO_function_id_enum function, DCL_UINT32 *size);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_ENABLE_IO) (DCL_SDIO_function_id_enum function, DCL_BOOL enable);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_SET_BUS_WIDTH) (DCL_SD_BITWIDTH bus);
typedef void (*DCL_SDIO_GET_CCCR) (DCL_UINT8 *buf, DCL_UINT32 bufLen);
typedef void (*DCL_SDIO_GET_FBR) (DCL_UINT8 *buf, DCL_UINT32 bufLen);

typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CMD52_READ)(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 *rdata, DCL_UINT8 *r5resp);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CMD52_WRITE)(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 wdata, DCL_UINT8 *r5resp);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CMD52_WRITE_READ)(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT8 wdata, DCL_UINT8 *rdata, DCL_UINT8 *r5resp);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CMD53_READ)(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block, DCL_UINT8 *r5resp);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CMD53_WRITE)(DCL_SDIO_function_id_enum function, DCL_UINT32 addr, DCL_UINT32 data, DCL_SDIO_cmd53_op_enum op, DCL_UINT32 count, DCL_BOOL block, DCL_UINT8 *r5resp);
typedef void (*DCL_SDIO_int_registration)(DCL_SDIO_function_id_enum function, void (func)(void));
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_MCUDMA_READ)(DCL_UINT32 *rdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_MCUDMA_WRITE)(DCL_UINT32 wdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CLKPADRED_READ)(DCL_UINT32 *rdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_CLKPADRED_WRITE)(DCL_UINT32 wdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_FORCEMCU_READ)(DCL_UINT32 *rdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_FORCEMCU_WRITE)(DCL_UINT32 wdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_GETCLK)(DCL_UINT32 *rdata);
typedef DCL_SDC_CMD_STATUS (*DCL_SDIO_SETCLK)(DCL_UINT32 wdata);

//guilin

typedef struct
{
	DCL_SDIO_REG_WR regWr;
	DCL_SDIO_REG_WR_ISR regWrInIsr;
	DCL_SDIO_DATA_WR dataWr;
	DCL_SDIO_REG_RD regRd;
	DCL_SDIO_DATA_RD dataRd;
	DCL_SDIO_CHECK_INTR checkIntr;
	DCL_SDIO_ENABLE_INTR enableIntr;
	DCL_SDIO_INIT sdioInititalize;
	DCL_SDIO_ABORT abort;
	DCL_SDIO_SW_RST swRst;
	DCL_SDIO_QRY_BLOCK_SIZE qryBlkSize;
	DCL_SDIO_SET_BLOCK_SIZE setBlkSize;
	DCL_SDIO_GET_BLOCK_SIZE getBlkSize;
	DCL_SDIO_ENABLE_IO enableIO;
	DCL_SDIO_SET_BUS_WIDTH setBusWidth;
	DCL_SDIO_GET_CCCR getCCCR;
	DCL_SDIO_GET_FBR getFBR;

    DCL_SDIO_CMD52_READ cmd52_read;
    DCL_SDIO_CMD52_WRITE cmd52_write;
    DCL_SDIO_CMD52_WRITE_READ cmd52_write_read;
    DCL_SDIO_CMD53_READ cmd53_read;
    DCL_SDIO_CMD53_WRITE cmd53_write;
    DCL_SDIO_int_registration hisr_callback;
    DCL_SDIO_MCUDMA_READ mcudma_read;
    DCL_SDIO_MCUDMA_WRITE mcudma_write;
    DCL_SDIO_CLKPADRED_READ clkpadred_read;
    DCL_SDIO_CLKPADRED_WRITE clkpadred_write;
    DCL_SDIO_FORCEMCU_READ forcemcu_read;
    DCL_SDIO_FORCEMCU_WRITE forcemcu_write;
    DCL_SDIO_GETCLK getclk;
    DCL_SDIO_SETCLK setclk;
    
}SDIODriver_t;
//guilin
typedef void (* DCL_MSDC_PDN)(DCL_BOOLEAN pwDown);

typedef struct
{
	//void (*modulePDN) (DCL_BOOLEAN pwDown);
	DCL_MSDC_PDN modulePDN;
}MSDCDriver_t;


/*******************************************************************************
 * DCL_FLAGS_T for SD
 *******************************************************************************/
#define DCL_SD_FLAGS_DEVICE_CARD1			0x1
#define DCL_SD_FLAGS_DEVICE_CARD2			0x2
#define DCL_SD_FLAGS_DEVICE_SIMPLUS			0x4
#define DCL_SDIO_FLAGS_SDIO1				0x100
#define DCL_SDIO_FLAGS_SDIO2				0x200
#define DCL_SDIO_FLAGS_ALL					0x300
#define DCL_SD_FLAGS_USAGE_GET_INFORMATION	0x10000
#define DCL_SD_FLAGS_USAGE_CMD				0x20000

#define DCL_SD_FLAGS_DEVICE_ALL (DCL_SD_FLAGS_DEVICE_CARD1|DCL_SD_FLAGS_DEVICE_CARD2|DCL_SD_FLAGS_DEVICE_SIMPLUS)
#define DCL_SD_FLAGS_USAGE_ALL (DCL_SD_FLAGS_USAGE_GET_INFORMATION|DCL_SD_FLAGS_USAGE_CMD)
/*******************************************************************************
 * DCL_CTRL_CMD for SD
 *******************************************************************************/
#define SD_CMDS    \
   SD_CTRL_CMD_BASE, \
   SD_CTRL_CMD_READ = SD_CTRL_CMD_BASE, \
   SD_CTRL_CMD_WRITE, \
   SD_CTRL_CMD_READ_ODD_SIZE, \
   SD_CTRL_CMD_WRITE_ODD_SIZE, \
   SD_CTRL_CMD_INIT, \
   SD_CTRL_CMD_IS_INITED, \
   SD_CTRL_CMD_ANALOG_SWITCH, \
   SD_CTRL_CMD_FAST_FORMAT_START, \
   SD_CTRL_CMD_FAST_FORMAT_STOP, \
   SD_CTRL_CMD_IS_FAST_FORMAT_RUNNING, \
   SD_CTRL_CMD_GET_CAPACITY, \
   SD_CTRL_CMD_IS_EXISTENCE, \
   SD_CTRL_CMD_POLL_EXISTENCE, \
   SD_CTRL_CMD_SET_CLEAR_EXISTENCE, \
   SD_CTRL_CMD_WRITE_PROTECTION, \
   SD_CTRL_CMD_QUERY_EVER_PLUGOUT, \
   SD_CTRL_CMD_RESET_EVER_PLUGOUT, \
   SD_CTRL_CMD_FORCE_SINGLE_LINE, \
   SD_CTRL_CMD_GO_IDLE, \
   SD_CTRL_CMD_CACHEABLE_BUFFER, \
   SD_CTRL_CMD_ADD_CALLBACK, \
   SD_CTRL_CMD_SET_FLAG, \
   SD_CTRL_CMD_READ_TEST, \
   SD_CTRL_CMD_SET_CLOCK_TEST, \
   SD_CTRL_CMD_FLUSH, \
   SD_CTRL_CMD_GET_AND_CLEAR_MEDIA_CHANGED, \
   SD_CTRL_CMD_GPD_READ,\
   SD_CTRL_CMD_GPD_WRITE,\
   SD_CTRL_CMD_GET_BD_STRUCT_NUM,\
   SD_CTRL_CMD_DUMMY_END,


/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/
/* FOR SD_CTRL_CMD_READ control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to read
	DCL_UINT32	u4Sectors; //this specify the number of sectors to read
	void		*bufferAddr; //we will move read data from card to this address
} SD_CTRL_READ_T;

/* FOR SD_CTRL_CMD_WRITE control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to write
	DCL_UINT32	u4Sectors; //this specify the number of sectors to write
	void		*bufferAddr; //we will move move data from this address to card
} SD_CTRL_WRITE_T;

/* FOR SD_CTRL_CMD_GPD_READ control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to read
	DCL_UINT32	u4Sectors; //this specify the number of sectors to read
	void		*bufferHead; //we will move read data from card to this address
	void        *bufferTail;
} SD_CTRL_GPD_READ_T;

/* FOR SD_CTRL_CMD_GPD_WRITE control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to write
	DCL_UINT32	u4Sectors; //this specify the number of sectors to write
	void		*bufferHead; //we will move move data from this address to card
	void        *bufferTail;
} SD_CTRL_GPD_WRITE_T;
typedef struct
{
    DCL_UINT32 max_bd_num;//specify the max bd struct num for link list dma transfer
} SD_CTRL_MAX_BD_STRUCT_NUM_T;

/* FOR SD_CTRL_CMD_READ_ODD_SIZE control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to read
	DCL_UINT32	u4Size; //this specify the number of bytes to read
	void		*bufferAddr; //we will move read data from card to this address
} SD_CTRL_READ_ODD_T;

/* FOR SD_CTRL_CMD_WRITE_ODD_SIZE control command. */
typedef struct
{
	DCL_UINT32	u4Sector; //this specify the starting sector to write
	DCL_UINT32	u4Size; //this specify the number of bytes to write
	void		*bufferAddr; //we will move move data from this address to card
} SD_CTRL_WRITE_ODD_T;

/* FOR SD_CTRL_CMD_ANALOG_SWITCH control command. */
typedef struct
{
	DCL_UINT32	u4TargetInterface;
} SD_CTRL_ANALOG_SWITCH_T;

/* FOR SD_CTRL_CMD_GET_CAPACITY control command. */
typedef struct
{
	DCL_BOOL	gHighCapacityCard;
	DCL_UINT64	pu8Capacity;
} SD_CTRL_GET_CAPACITY_T;

/* FOR SD_CTRL_CMD_READY control command. */
typedef struct
{
	DCL_BOOL fgInited;
} SD_CTRL_INITED_T;

/* FOR SD_CTRL_CMD_IS_EXISTENCE and SD_CTRL_CMD_POLL_EXISTENCE control command. */
typedef struct
{
	DCL_BOOL fgPresent;
} SD_CTRL_EXISTENCE_T;

/* FOR SD_CTRL_CMD_WRITE_PROTECTION control command. */
typedef struct
{
	DCL_BOOL fgReadOnly;
} SD_CTRL_WRITE_PROTECTION_T;

/* FOR SD_CTRL_CMD_QUERY_EVER_PLUGOUT control command. */
typedef struct
{
	DCL_BOOL fgEverPLugOut;
} SD_CTRL_QUERY_EVER_PLUGOUT_T;

/* FOR SD_CTRL_CMD_FORCE_SINGLE_LINE control command. */
typedef struct
{
	DCL_BOOL fgIsItTrue;
} SD_CTRL_FORCE_SINGLE_LINE_T;

/* FOR SD_CTRL_CMD_CACHEABLE_BUFFER control command. */
typedef struct
{
	DCL_BOOL fgIsCACHEABLE;
} SD_CTRL_CACHEABLE_BUFFER_T;

typedef struct 
{
	MSDC_CALLBACK callback1;
	MSDC_CALLBACK callback2;
	MSDC_CALLBACK callback3;
	MSDC_CALLBACK callback4;
	MSDC_CALLBACK callback5;
	MSDC_CALLBACK callback6;
}SD_CTRL_CALLBACK_T;

typedef struct 
{
	DCL_UINT32 readTestFlag;
}SD_CTRL_SET_READ_TEST_FLAG_T;

typedef struct 
{
	DCL_UINT32 startSector;
	DCL_UINT32 sectorNum;
}SD_CTRL_FLUSH_T;

typedef struct 
{
	DCL_BOOL enable;
}SD_CTRL_FAST_FORMAT_T;

typedef struct 
{
	DCL_BOOL changed;
}SD_CTRL_MEDIA_CHANGED_T;

#define SD_CTRLS \
   SD_CTRL_READ_T		rSDRead; \
   SD_CTRL_WRITE_T		rSDWrite; \
   SD_CTRL_READ_ODD_T	rSDReadOdd;\
   SD_CTRL_WRITE_ODD_T	rSDWriteOdd; \
   SD_CTRL_ANALOG_SWITCH_T rSDSwitch; \
   SD_CTRL_GET_CAPACITY_T	rSDGetCapacity; \
   SD_CTRL_INITED_T rSDInited; \
   SD_CTRL_EXISTENCE_T rSDExistence; \
   SD_CTRL_EXISTENCE_T rSDPollExistence; \
   SD_CTRL_WRITE_PROTECTION_T rSDWriteProrect; \
   SD_CTRL_QUERY_EVER_PLUGOUT_T rSDQueryEverPugOut; \
   SD_CTRL_FORCE_SINGLE_LINE_T rSDForceSingleLine; \
   SD_CTRL_CACHEABLE_BUFFER_T rSDCacheableBuf; \
   SD_CTRL_CALLBACK_T rSDCallBackFunc; \
   SD_CTRL_SET_READ_TEST_FLAG_T rSDSetReadTestFlag; \
   SD_CTRL_FLUSH_T rSDFlush; \
   SD_CTRL_FAST_FORMAT_T rSDFastFormat; \
   SD_CTRL_MEDIA_CHANGED_T rSDMediaChanged; \
   SD_CTRL_GPD_READ_T   rSDReadGPD;\
   SD_CTRL_GPD_WRITE_T   rSDWriteGPD;\
   SD_CTRL_MAX_BD_STRUCT_NUM_T rSDMaxBD;


/***********************************************************************************
* following is the part of SDIO
************************************************************************************/

/*******************************************************************************
 * DCL_FLAGS_T for SDIO
 *******************************************************************************/
#define DCL_SDIO_FLAGS_DEVICE_CARD1 0x1
#define DCL_SDIO_FLAGS_DEVICE_CARD2 0x2
#define DCL_SDIO_FLAGS_USAGE_GET_INFORMATION	0x10
#define DCL_SDIO_FLAGS_USAGE_CMD	0x20

#define DCL_SDIO_FLAGS_DEVICE_ALL (DCL_SDIO_FLAGS_DEVICE_CARD1|DCL_SDIO_FLAGS_DEVICE_CARD2)
#define DCL_SDIO_FLAGS_USAGE_ALL (DCL_SDIO_FLAGS_USAGE_GET_INFORMATION|DCL_SDIO_FLAGS_USAGE_CMD)


/*******************************************************************************
 * DCL_CTRL_CMD for SDIO
 *******************************************************************************/
#define SDIO_CMDS    \
   SDIO_CTRL_CMD_REG_WR, \
   SDIO_CTRL_CMD_REG_WR_ISR, \
   SDIO_CTRL_CMD_DATA_WR, \
   SDIO_CTRL_CMD_REG_RD,  \
   SDIO_CTRL_CMD_DATA_RD, \
   SDIO_CTRL_CMD_CHECK_INTR, \
   SDIO_CTRL_CMD_ENABLE_INTR, \
   SDIO_CTRL_CMD_INIT, \
   SDIO_CTRL_CMD_ABORT, \
   SDIO_CTRL_CMD_SW_RST, \
   SDIO_CTRL_CMD_QUERY_BLK_SIZE, \
   SDIO_CTRL_CMD_SET_BLK_SIZE, \
    SDIO_CTRL_CMD_GET_BLK_SIZE, \
   SDIO_CTRL_CMD_ENABLE_IO, \
   SDIO_CTRL_CMD_SET_BUS_WIDTH, \
   SDIO_CTRL_CMD_GET_CCCR, \
   SDIO_CTRL_CMD_GET_FBR, \
   SDIO_CTRL_CMD_CMD52_READ, \
   SDIO_CTRL_CMD_CMD52_WRITE, \
   SDIO_CTRL_CMD_CMD52_WRITE_READ, \
   SDIO_CTRL_CMD_CMD53_READ, \
   SDIO_CTRL_CMD_CMD53_WRITE, \
   SDIO_CTRL_CMD_MCUDMA_READ, \
   SDIO_CTRL_CMD_MCUDMA_WRITE, \
    SDIO_CTRL_CMD_CLKPADRED_READ, \
    SDIO_CTRL_CMD_CLKPADRED_WRITE, \
    SDIO_CTRL_CMD_FORCEMCU_READ, \
    SDIO_CTRL_CMD_FORCEMCU_WRITE, \
    SDIO_CTRL_CMD_GETCLK, \
    SDIO_CTRL_CMD_SETCLK,
//guilin
/*******************************************************************************
 * DCL_CTRL_DATA_T: Define the Control data structure for each module's command
 *******************************************************************************/

/* For SDIO_CTRL_CMD_REG_WR, SDIO_CTRL_CMD_REG_WR_ISR, SDIO_CTRL_CMD_REG_RD control command.*/
typedef struct
{
	DCL_SDIO_function_id_enum function;
	DCL_UINT32 addr;	// card's address to access
	DCL_UINT32 data;		// the data want to read from/write from card
	DCL_SDIO_cmd53_op_enum op;	// operation mode
} SDIO_CTRL_REG_RW_T;

/* For SDIO_CTRL_CMD_DATA_WR, SDIO_CTRL_CMD_DATA_RD,  control command.*/
typedef struct{
	DCL_SDIO_function_id_enum function;		// function
	DCL_BOOL block;		// block mode or not
	DCL_SDIO_cmd53_op_enum op;	// operation mode
	DCL_UINT16 count;		// byte or block count
	DCL_UINT32 addr;		// address
	DCL_UINT32 buffer;		// address of buffer for data transfer
}SDIO_CTRL_DAT_RW_T;

/* For SDIO_CTRL_CMD_SET_BLK_SIZE, SDIO_CTRL_CMD_GET_BLK_SIZE , control command.*/
typedef struct{
	DCL_SDIO_function_id_enum function;
	DCL_UINT32 size;
}SDIO_CTRL_SET_BLK_SIZE_T;

/* For SDIO_CTRL_CMD_CHECK_INTR,  control command.*/
typedef struct{
	DCL_SDIO_function_id_enum function;
	DCL_BOOL *pending;
}SDIO_CTRL_CHECK_INTR_T;

/* For SDIO_CTRL_CMD_ENABLE_INTR,  control command.*/
typedef struct{
	DCL_SDIO_function_id_enum function;
	DCL_BOOL enable;
}SDIO_CTRL_ENABLE_T;

/* For SDIO_CTRL_CMD_GET_CCCR and SDIO_CTRL_CMD_GET_FBR,  control command.*/
typedef struct{
	DCL_UINT8 *buffer;
	DCL_UINT32 bufferLength;
}SDIO_CTRL_GET_INFO_T;

typedef struct{
//	rw_dir_enum rw;	// directon (input)0=read,1=write
	kal_uint8 rw;	// directon (input)0=read,1=write
	kal_uint8 func;	// function (input)
	kal_uint8 rdata;	// write data or read back data (Input , output)
	kal_uint8 wdata;	// write data or read back data (Input , output)
	kal_bool raw;		// read after write
	kal_bool stop;		// stop data transfer 
	kal_uint32 addr;	// address (input)
    kal_uint8 r5_resp;  // R5
}SDIO_CTRL_CMD52_T;

typedef struct{
//	rw_dir_enum rw;	// directon (input)0=read,1=write
	kal_uint8 rw;	// directon (input)0=read,1=write
	kal_uint8 func;	// function (input)
    kal_uint8 r5_resp;  // R5
//  cmd53_op_enum op;       // operation mode,0=FIX,1=INC
    kal_uint8 op;       // operation mode,0=FIX,1=INC
    kal_bool block;     // block mode or not
    kal_uint16 count;       // byte or block count
    kal_uint32 addr;        // address
    kal_uint32 buffer;  // address of buffer for data transfer
}SDIO_CTRL_CMD53_T;

typedef struct{
    kal_uint32 data;
}SDIO_CTRL_CMD_REG_T;

#define SDIO_CTRLS \
   SDIO_CTRL_REG_RW_T		rSDIORegRw; \
   SDIO_CTRL_DAT_RW_T		rSDIODatRw; \
   DCL_SDIO_function_id_enum	rSDIOFunction; \
   SDIO_CTRL_SET_BLK_SIZE_T	rSDIOSetBlkSize; \
   SDIO_CTRL_CHECK_INTR_T	rSDIOCheckIntr; \
   SDIO_CTRL_ENABLE_T		rSDIOEnable; \
   DCL_SD_BITWIDTH			rSDIOBusWidth; \
   SDIO_CTRL_GET_INFO_T		rSDIOGetInfo; \
    SDIO_CTRL_CMD52_T       rSDIOCMD52; \
    SDIO_CTRL_CMD53_T       rSDIOCMD53; \
    SDIO_CTRL_CMD_REG_T     rSDIOCMDREG;
//guilin
#endif /*__DCL_MSDC_H_FRONT__*/
#endif /*DCL_DEFINITION_STRUCT*/

#ifdef DCL_DEFINITION_PROTOTYPE
//#ifndef __DCL_MSDC_H_FRONT__
//#define __DCL_MSDC_H_FRONT__

/*******************************************************************************
 * Declare function prototype.
 *******************************************************************************/
/* DCL for SD/MMC*/
/* DCL for SDIO */
extern DCL_STATUS DclSD_Initialize(void);
extern DCL_HANDLE DclSD_Open(DCL_DEV dev, DCL_FLAGS flags);
extern DCL_STATUS DclSD_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
extern DCL_STATUS DclSD_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options);
extern DCL_STATUS DclSD_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure);
extern DCL_STATUS DclSD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback);
extern DCL_STATUS DclSD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data);
extern DCL_STATUS DclSD_Close(DCL_HANDLE handle);
//#endif /*__DCL_MSDC_H_FRONT__*/
#endif /*DCL_DEFINITION_PROTOTYPE*/


