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
 *   bl_uart.c
 *
 * Project:
 * --------
 *   NFB - Bootloader
 *
 * Description:
 * ------------
 *   UART driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_general_types.h" 
#include "bl_UART_HW.H"
#include "bl_UART_SW.H"
#include "bl_drv_common.h"
#include "pll.h"

/*
 * Baud rates.
 */
typedef enum {
    UART_BAUD_921600 = 0x1, 
    UART_BAUD_460800 = 0x2, 
    UART_BAUD_230400 = 0x3,
    UART_BAUD_115200 = 0x4, 	
    UART_BAUD_57600 = 0x5, 
    UART_BAUD_38400 = 0x6,
    UART_BAUD_19200 = 0x7, 	
    UART_BAUD_9600 = 0x8,
    UART_BAUD_4800 = 0x9,
    UART_BAUD_2400 = 0xA, 	
    UART_BAUD_1200 = 0xB,
    UART_BAUD_300 = 0xC, 	
    UART_BAUD_110 = 0xD, 
}UART_BAUDRATE;

kal_uint32 baud_table[] = {921600, 460800, 230400, 115200, 57600, 38400, 19200, 9600, 4800, 2400, 1200, 300, 110};

/**********************************************************
Description : UART get single byte (non-blocking)
Input       : Non
Output      : 8-bits data
***********************************************************/
kal_bool GetUARTByte_NB(kal_uint8 *data)
{
    kal_uint8 LSR;

    LSR = DRV_Reg8(UART_LSR);
    if ( LSR & LSR_DR )
    {
        *data = DRV_Reg8(UART_RBR);
        return KAL_TRUE;
    }

    *data = 0;
    return KAL_FALSE;
}

/**********************************************************
Description : UART get single byte
Input       : Non
Output      : 8-bits data
***********************************************************/
kal_uint8 GetUARTByte()
{
    kal_uint8 LSR;

    while(1){
        LSR = DRV_Reg8(UART_LSR);
        if ( LSR & LSR_DR )
        {
            return DRV_Reg8(UART_RBR);
        }
    }
}

/**********************************************************
Description : UART put single byte
Input       : 8-bits data to be sent
Output      : Non
***********************************************************/

void PutUARTByte(kal_uint8 data)
{
    kal_uint8 LSR;

    while(1)
    {
        LSR = DRV_Reg8(UART_LSR);
        if ( LSR & LSR_THRE )
        {
            DRV_WriteReg8(UART_THR, data);
            break;
        }
    }
}

/**********************************************************
Description : UART put complete
Input       : Non
Output      : Non
***********************************************************/

void PutUARTByte_Complete()
{
    CheckUARTSendEnd();
}

/**********************************************************
Description : Checking end of transferring
Input       : Non
Output      : Non
***********************************************************/

void CheckUARTSendEnd(void)
{
    kal_uint8 LSR;
    kal_uint16 timeout=0xffff;

    while(timeout--)
    {
        LSR = DRV_Reg8(UART_LSR);
        if ( LSR & LSR_TEMT )
            break;
    }
}

void ClearUARTFifo()
{
    // Enable & clear FIFO
    DRV_WriteReg8(UART_FCR, 0x07);
}

/**********************************************************
Description : UART initialization
Input       : Non
Output      : Non
***********************************************************/

void uart_init(void)
{
    kal_uint8 lcr;
    kal_uint32 sample_count = 16;
    kal_uint32 clock = BUS_CLOCK_MHZ*1000000;
    kal_uint32 freq_div = 1;
    kal_uint32 baudrate = baud_table[UART_BAUD_115200-1];

    //Init UART in 115200

    // 8-1-no parity.
    DRV_WriteReg8(UART_LCR, LCR_WLS1 | LCR_WLS0);

    do {
        sample_count = (clock + (freq_div * baudrate / 2)) / (freq_div * baudrate);
        if (sample_count > 0xff) freq_div++;
    } while (sample_count > 0xff );

    lcr = DRV_Reg8(UART_LCR);
    lcr |= LCR_DLAB;
    DRV_WriteReg8(UART_LCR, lcr);

    DRV_WriteReg8(UART_DLL, (freq_div & 0xFF));
    DRV_WriteReg8(UART_DLM, (freq_div >> 8));

    lcr &= ~LCR_DLAB;
    DRV_WriteReg8(UART_LCR, lcr);

    DRV_WriteReg8(UART_SAMPLE_CNT, sample_count - 1);
    DRV_WriteReg8(UART_SAMPLE_PNT, sample_count / 2);

    DRV_WriteReg8(UART_HSD, HSD_X);

    // Enable & clear FIFO
    DRV_WriteReg8(UART_FCR, 0x07);
    
}
