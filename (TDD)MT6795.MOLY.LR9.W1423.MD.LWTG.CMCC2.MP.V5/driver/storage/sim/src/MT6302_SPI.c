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
 * MT6302_interface.C
 *
 * Project:
 * --------
 *   Gemini
 *
 * Description:
 * ------------
 *   this file is to be adaption layer for different SPI implementation
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef DRV_SIM_OFF
#include 	"kal_public_api.h"
#include	"drv_comm.h"
#include	"reg_base.h"
//#include	"gpio_sw.h"
#include    "sim_reg_adp.h"
#include    "drv_sw_features_display.h"
#include	"MT6302_spi.h"
//#include	"lcd_if_hw.h"
//#include	"lcd_if.h"
//#include  "..\..\ps\sim\include\sim_trc.h"
#include "sim_drv_trc.h"
#if defined(__DRV_SIM_TP_SHARE_PIN__)
#include	"touch_panel_spi.h"
#endif  // #if defined(__DRV_SIM_TP_SHARE_PIN__)
//#include "lcd_if_manager.h"
#include "dcl.h"
//#include "lcd_power_mgr.h"
/*following decalration were moved from gpio_sw.h*, we should change them to dcl form eventually*/
extern char GPIO_ReturnMode(char port);
extern char GPIO_ReturnDir(char port);
extern char GPIO_ReturnDout(char port);


#if  (defined(DRV_MULTIPLE_SIM) && !defined(DRV_2_SIM_CONTROLLER)) || (defined(__SIM_DRV_MULTI_DRV_ARCH__))
//extern sim_MT6302_SPIWriter	sim_MT6320_writer;
extern kal_uint32 MT6302_getLCDSerialInterface(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getSPIInterface(kal_uint32 MT6302Interface);
extern kal_bool MT6302_checkSPIMode(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIOCLK(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIOCS(kal_uint32 MT6302Interface);
extern kal_uint32 MT6302_getGPIODAT(kal_uint32 MT6302Interface);
extern void lcd_clk_disable( kal_uint8 handle );
extern void lcd_clk_enable( kal_uint8 handle );
//extern kal_uint8 lcd_get_power_handle(void);

#define IMPLEMENTING_ASSERT	ASSERT(0)
#define SIM_REMOVE_LCD_PDN_DBG_CODE

kal_uint8		MT6302_LCD_dummyReadValue;

sim_MT6302_SPIInfo SIM_MT6302_spi_cb[SIM_MT6302_MAX_MT6302];

#ifdef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
kal_uint8	MT6302_GPIO_dmaHandle;
#endif

#if defined(__DRV_SIM_TP_SHARE_PIN__)
extern kal_bool FlagDisablePENIRQ;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

void MT6302_Writer_LCD(kal_uint32 chipNo, kal_uint8 data)
{
	//no LCD in Moly
}

#ifndef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
void MT6302_Writer_GPIO(kal_uint32 chipNo, kal_uint8 data)
{
	kal_uint32 i, j;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

	i = SaveAndSetIRQMask();

	if(KAL_FALSE == MT6302_checkSPIMode(chipNo)){
		RestoreIRQMask(i);
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}

	MT6302_CS_PIN=MT6302_getGPIOCS(chipNo);
	MT6302_CLK_PIN=MT6302_getGPIOCLK(chipNo);
	MT6302_DAT_PIN=MT6302_getGPIODAT(chipNo);

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);
	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);
	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	/*since we will call GPIO_WriteIO_fast. we should remove the magic number here*/
	MT6302_CS_PIN &= 0x7f;
	MT6302_CLK_PIN &= 0x7f;
	MT6302_DAT_PIN &= 0x7f;

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
	//GPIO_WriteIO(0, MT6302_CLK_PIN);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_LOW,&spiCs);
	//GPIO_WriteIO(0, MT6302_CS_PIN);
	for(j=8;j>0;j--)
	{
		if(data&(0x1<<(j-1)))
		{
			spiDat.rWriteSpi.data = 1;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_HIGH,&spiDat);
			//GPIO_WriteIO(1, MT6302_DAT_PIN);
		}
		else
		{
			spiDat.rWriteSpi.data = 0;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
			//GPIO_WriteIO(0, MT6302_DAT_PIN);
		}

		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_HIGH,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
		//GPIO_WriteIO(1, MT6302_CLK_PIN);
		//GPIO_WriteIO(0, MT6302_CLK_PIN);
	}
	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
	//GPIO_WriteIO(0, MT6302_DAT_PIN);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_HIGH,&spiCs);
	//GPIO_WriteIO(1, MT6302_CS_PIN);

	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);

	RestoreIRQMask(i);
}
#else
void MT6302_Writer_GPIO(kal_uint8 data)
{
	kal_uint32 i;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	kal_uint16	no_cs, no_clk, no_dat;
	kal_uint16	remainder_cs, remainder_clk, remainder_dat;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    kal_uint8 TP_SPI_CS_PIN;
    kal_uint16 no_tp_cs, remainder_tp_cs;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	//i = SaveAndSetIRQMask();

	if(KAL_FALSE == MT6302_checkSPIMode()){
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}


	MT6302_CS_PIN=MT6302_getGPIOCS();
	MT6302_CLK_PIN=MT6302_getGPIOCLK();
	MT6302_DAT_PIN=MT6302_getGPIODAT();

	/*since we will call GPIO_WriteIO_fast. we should remove the magic number here*/
	MT6302_CS_PIN &= 0x7f;
	MT6302_CLK_PIN &= 0x7f;
	MT6302_DAT_PIN &= 0x7f;

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);

	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);

	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    TP_SPI_CS_PIN = (SPI_CS_PIN);
    TP_SPI_CS_PIN &= 0x7f;

    remainder_tp_cs = 1<<(TP_SPI_CS_PIN%16);
	no_tp_cs = TP_SPI_CS_PIN/16;
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	dma_slowdown(MT6302_GPIO_dmaHandle);
	i = SaveAndSetIRQMask();

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    if(!FlagDisablePENIRQ)
    {
		 spiCs.rWriteSpi.data = 1;
		 DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//        GPIO_WriteIO_FAST2(1, no_tp_cs, remainder_tp_cs);
    }
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

    	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
//	GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//	GPIO_WriteIO_FAST2(0, no_cs, remainder_cs);

	{
		/*bit 8*/
		spiDat.rWriteSpi.data = (data>>7) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>7) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 7*/
		spiDat.rWriteSpi.data = (data>>6) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>6) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 6*/
		spiDat.rWriteSpi.data = (data>>5) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>5) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 5*/
		spiDat.rWriteSpi.data = (data>>4) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>4) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 4*/
		spiDat.rWriteSpi.data = (data>>3) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>3) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 3*/
		spiDat.rWriteSpi.data = (data>>2) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>2) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 2*/
		spiDat.rWriteSpi.data = (data>>1) & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2((data>>1) & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);

		/*bit 1*/
		spiDat.rWriteSpi.data = data & 0x01;
		DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_FOR_SPI,&spiClk);

//		GPIO_WriteIO_FAST2(data & 0x01, no_dat, remainder_dat);
//		GPIO_WriteIO_FAST2(1, no_clk, remainder_clk);
//		GPIO_WriteIO_FAST2(0, no_clk, remainder_clk);
	}

	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_FOR_SPI,&spiDat);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);

//	GPIO_WriteIO_FAST2(0, no_dat, remainder_dat);
//	GPIO_WriteIO_FAST2(1, no_cs, remainder_cs);

#if defined(__DRV_SIM_TP_SHARE_PIN__)
    if(!FlagDisablePENIRQ)
    {
		 spiCs.rWriteSpi.data = 0;
		 DclGPIO_Control(csHandle,GPIO_CMD_WRITE_FOR_SPI,&spiCs);
//        GPIO_WriteIO_FAST2(0, no_tp_cs, remainder_tp_cs);
    }
#endif // #if defined(__DRV_SIM_TP_SHARE_PIN__)

	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);

	RestoreIRQMask(i);
	dma_recover(MT6302_GPIO_dmaHandle);
}
#endif

/*
	This is the new MT6302 SPI implementation.
	This API will be used when the SPI is implemented by 3 dedicated GPIO.
	In this function, we will not disable i-bit
*/
void MT6302_Writer_dedicated_GPIO(kal_uint32 chipNo, kal_uint8 data)
{
	kal_uint32 j;
	kal_uint8 	MT6302_CS_PIN, MT6302_CLK_PIN, MT6302_DAT_PIN;
	DCL_HANDLE clkHandle, datHandle, csHandle;
	DCL_CTRL_DATA_T spiClk, spiDat, spiCs;

	if(KAL_FALSE == MT6302_checkSPIMode(chipNo)){
		// some states of 3 SPI pins don't match our expectation.
		ASSERT(0);
	}

	MT6302_CS_PIN=MT6302_getGPIOCS(chipNo);
	MT6302_CLK_PIN=MT6302_getGPIOCLK(chipNo);
	MT6302_DAT_PIN=MT6302_getGPIODAT(chipNo);

	datHandle = DclGPIO_Open(DCL_GPIO, MT6302_DAT_PIN);
	DclGPIO_Control(datHandle,GPIO_CMD_SET_DIR_OUT,0);

	clkHandle = DclGPIO_Open(DCL_GPIO, MT6302_CLK_PIN);

	csHandle = DclGPIO_Open(DCL_GPIO, MT6302_CS_PIN);

	spiClk.rWriteSpi.remainder_shift = 1<<(MT6302_CLK_PIN%16);
	spiClk.rWriteSpi.no = MT6302_CLK_PIN/16;
	spiDat.rWriteSpi.remainder_shift = 1<<(MT6302_DAT_PIN%16);
	spiDat.rWriteSpi.no = MT6302_DAT_PIN/16;
	spiCs.rWriteSpi.remainder_shift = 1<<(MT6302_CS_PIN%16);
	spiCs.rWriteSpi.no = MT6302_CS_PIN/16;

	/*MT6302 latch SPI command on CLK rising edge, we have park clk to low or there will be race conditions*/
	spiClk.rWriteSpi.data = 0;
	DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);
	//GPIO_WriteIO(0, MT6302_CLK_PIN);
	spiCs.rWriteSpi.data = 0;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_LOW,&spiCs);
	//GPIO_WriteIO(0, MT6302_CS_PIN);
	for(j=8;j>0;j--)
	{
		if(data&(0x1<<(j-1)))
		{
			spiDat.rWriteSpi.data = 1;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_HIGH,&spiDat);
			//GPIO_WriteIO(1, MT6302_DAT_PIN);
		}
		else
		{
			spiDat.rWriteSpi.data = 0;
			DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
			//GPIO_WriteIO(0, MT6302_DAT_PIN);
		}
		spiClk.rWriteSpi.data = 1;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_HIGH,&spiClk);
		spiClk.rWriteSpi.data = 0;
		DclGPIO_Control(clkHandle,GPIO_CMD_WRITE_LOW,&spiClk);

		//GPIO_WriteIO(1, MT6302_CLK_PIN);
		//GPIO_WriteIO(0, MT6302_CLK_PIN);
	}
	spiDat.rWriteSpi.data = 0;
	DclGPIO_Control(datHandle,GPIO_CMD_WRITE_LOW,&spiDat);
	spiCs.rWriteSpi.data = 1;
	DclGPIO_Control(csHandle,GPIO_CMD_WRITE_HIGH,&spiCs);

	//GPIO_WriteIO(0, MT6302_DAT_PIN);
	//GPIO_WriteIO(1, MT6302_CS_PIN);
	DclGPIO_Close(datHandle);
	DclGPIO_Close(clkHandle);
	DclGPIO_Close(csHandle);
}

void MT6302_spiPowerCtrl(kal_uint32 chipNo, kal_bool on)
{
	//no LCD in Moly
}


void MT6302_SPI_LCDHandlerInit(kal_uint32 serialLCDNo, kal_uint32 *LCDSerialDataAddr)
{
	//no LCD in Moly
}

kal_uint32 MT6302_initDelayTime;

//#define OLD_LCD_INTERFACE

void MT6302_spiInit(sim_MT6302_SPIWriter *spiWritePtr, kal_uint32 chipNo)
{

	if(0 == MT6302_getSPIInterface(chipNo)){ //MT6302_SPI_USE_LCD
		//no LCD in Moly
	}
	else if(1 == MT6302_getSPIInterface(chipNo)){//MT6302_SPI_USE_GPIO
		*spiWritePtr = (sim_MT6302_SPIWriter)MT6302_Writer_GPIO;
		if((0xff == MT6302_getGPIOCS(chipNo)) || (0xff == MT6302_getGPIOCLK(chipNo)) || (0xff == MT6302_getGPIODAT(chipNo)))
			ASSERT(0);

#ifdef DRV_SIM_GEMINI_ON_LOW_SPEED_PLATFORM
		MT6302_GPIO_dmaHandle = dma_slowdown_get_handle();
#endif
	}
	else if(2 == MT6302_getSPIInterface(chipNo)){//MT6302_SPI_USE_DEDICATED_GPIO
		*spiWritePtr = (sim_MT6302_SPIWriter)MT6302_Writer_dedicated_GPIO;
		if((0xff == MT6302_getGPIOCS(chipNo)) || (0xff == MT6302_getGPIOCLK(chipNo)) || (0xff == MT6302_getGPIODAT(chipNo)))
			ASSERT(0);

	}
	else{
		IMPLEMENTING_ASSERT;
	}
}


/*
void MT6302_spiInit(void)
{
	extern sim_MT6302_switchInfo switchCB[];
	kal_uint32 i;

	for(i = 0; i < SIM_MT6302_MAX_MT6302; i++){
		MT6302_spiInterfaceInit(&switchCB[i], i);
	}
}
*/
#endif
#endif //DRV_SIM_OFF
