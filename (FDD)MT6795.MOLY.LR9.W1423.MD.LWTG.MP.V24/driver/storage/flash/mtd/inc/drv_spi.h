/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   drv_spi.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 * driver header of spi controller
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Add SPI Driver to storage/flash/mtd folder.
 * 
 ****************************************************************************/

#ifndef	SPI_FLASH_DRV_07_06_11
#define SPI_FLASH_DRV_07_06_11

#include "def_spi.h"
#include "link_spi.h"
#include "kal_general_types.h"
//#include <stdio.h>
//#include <base/kal/kal_public_api.h>
//#include <base/kal/kal_debug.h>

#ifndef _PTST_
#define SPI_FLASH_DEBUG
#endif
//#ifdef SPI_FLASH_DEBUG
//#define	DBG_PRINT(fmt, args...)		kal_printf(fmt,##args)
//#else
#define DBG_PRINT(fmt, args...)
//#endif
/**
 *	@brief the _spi_flash_hwinfo object
 */
typedef struct _spi_flash_hwinfo{
	kal_char  vendorID;			//Manufacturer ID from RDID command
	kal_uint16 deviceID;			//Device ID from RDID command
	kal_int32 bulkCount; 		//Total 64KB bulk numbers
	kal_int32 sectorSize;

	kal_char fourByteAccess;
	kal_char SE4Ksupported;
	kal_char twoReadSupported;
	kal_char fastReadDualSupported;
	kal_char powerDownSupported;
	kal_char byteProgram;
	
	kal_int32 WorkingClock;

}spi_flash_hwinfo_t;

/**
 *	@brief the spi_flash_drv object
 */
typedef struct _spi_flash_drv{
	spi_flash_hwinfo_t* hw_info;
	kal_int32 working_clock;
}spi_flash_drv_t;

/**
 *	@brief Read Status Register (RDSR)
 *	@param
 *	@return
 */
kal_int32 spi_flash_readStatus(kal_char* status);

/**
 *	@brief Write Status Regiser (WRSR)
 *	@param
 *	@return
 */
kal_int32 spi_flash_writeStatus(kal_char status);

/**
 *	@brief
 *	@param
 *	@return
 */

kal_int32 spi_flash_getFlashInfo(spi_flash_drv_t* flash_info);

kal_int32 spi_flash_write(spi_flash_drv_t* flash_info, kal_int32 offset, kal_char * data, kal_int32 len);

kal_int32 spi_flash_erase(spi_flash_drv_t* flash_info, kal_int32 offset, kal_int32 len);

kal_int32 spi_flash_switchRead(spi_flash_drv_t* flash_info, kal_int32 read_type);

kal_int32 spi_flash_waitWIP(kal_int32 total_loop);

kal_int32 spi_common_transfer(kal_int32 tx_len, kal_int32 rx_len, kal_int32 timeout, kal_uint32 start);

/* Following function are exported only for testint its functionality */
kal_int32 spi_flash_WREN(void);
kal_int32 spi_flash_WRDI(void);
kal_int32 spi_flash_E4K(spi_flash_drv_t* flash_info, kal_int32 addr);
kal_int32 spi_flash_SE(spi_flash_drv_t* flash_info, kal_int32 addr);
kal_int32 spi_flash_pageProgram(spi_flash_drv_t* flash_info, kal_int32 offset, kal_char * data, kal_int32 len);
kal_int32 spi_flash_chipErase(void);
kal_int32 spi_flash_indirectRead(spi_flash_drv_t* flash_info, kal_int32 addr, kal_char * data, kal_int32 len);
kal_int32 spi_flash_wakeUp(void);
kal_int32 spi_flash_powerDown(void);
kal_int32 spi_flash_readID(kal_char* RDID);

kal_int32 spi_flash_REMS_Test(kal_char rems_cmd, kal_char rems_manufacturer_ID, kal_char rems_device_ID);
kal_int32 spi_flash_is_MX25L12845E(void);

#endif
