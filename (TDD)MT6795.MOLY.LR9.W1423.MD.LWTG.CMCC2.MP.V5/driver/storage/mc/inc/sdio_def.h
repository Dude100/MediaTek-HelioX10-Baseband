/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
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
 *   Header file of SDIO driver
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef SDIO_DEF_H
#define SDIO_DEF_H
/*HW part*/
#define SDIO_CFG				(MSDC_ADRS+0x54)
#define SDIO_STA				(MSDC_ADRS+0x58)
//#define SDC_CFG_SDIO		0x00080000
#define SDiO_CFG_INTEN		0x1	// enable interrupt
#define SDiO_CFG_INTSEL		0x2	// interrupt signal selection 0: use DAT[1], 1: use DAT[5]
#define SDiO_CFG_DSBSEL		0x4	// data block start bit selection

#if defined(DRV_MSDC_MT6238_SERIES)
#define SDIO_CFG2	(MSDC_ADRS2+0x54)
#define SDIO_STA2	(MSDC_ADRS2+0x58)
#endif

#define SDIO_R4_CARD_READY		0x80
#define IO_ARG_RW_FLAG			0x80000000
#define IO_ARG_RAW_FLAG			0x08000000		
#define MSDC_WORK_OCR			0x8000

#define R5_COM_CRC_ERROR       (1<<7)
#define R5_ILLEGAL_COMMAND     (1<<6)
#define R5_IO_CURRENT_STATE    (3<<4)
#define R5_ERROR                 (1<<3)
#define R5_RFU                   (1<<2)
#define R5_FUNCTION_NUMBER      (1<<1)
#define R5_OUT_OF_RANGE         (1<<0)
#define R5_ERROR_CHECK          (R5_COM_CRC_ERROR|R5_ILLEGAL_COMMAND|R5_ERROR|R5_FUNCTION_NUMBER|R5_OUT_OF_RANGE)

#define SDIO_STATUS_CHECK 	\
{\
	if(NO_ERROR != status)\
	{\
		SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);\
		goto err;\
	}\
}

#endif // end of SD_DEF_H
