/*************************************************************************/
/*                                                                       */
/*          Copyright (c) 2001 Accelerated Technology, Inc.              */
/*                                                                       */
/* PROPRIETARY RIGHTS of Accelerated Technology are involved in the      */
/* subject matter of this material.  All manufacturing, reproduction,    */
/* use, and sales rights pertaining to this subject matter are governed  */
/* by the license agreement.  The recipient of this software implicitly  */
/* accepts the terms of the license.                                     */
/*                                                                       */
/*************************************************************************/

/*************************************************************************/
/*                                                                       */
/* FILE NAME                                          VERSION            */
/*                                               PLUS/ARM679/v1.13.21    */
/*      sd_defs.h                                                        */
/*                                                                       */
/* COMPONENT                                                             */
/*                                                                       */
/*      SD - Serial Driver                                               */
/*                                                                       */
/* DESCRIPTION                                                           */
/*                                                                       */
/*      This file contains constant definitions and function macros      */
/*      for the Serial Driver module.                                    */
/*                                                                       */
/* DATA STRUCTURES                                                       */
/*                                                                       */
/*      SD_PORT     :   Structure to keep all needed info. about a port. */
/*                                                                       */
/* DEPENDENCIES                                                          */
/*                                                                       */
/*      none                                                             */
/*                                                                       */
/*************************************************************************/
/*=========================================================================
*             HISTORY
* Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*--------------------------------------------------------------------------
* $Revision$
* $Modtime$
* $Log$
*
* 03 19 2014 hc.yang
 * removed!
* .
*
*--------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*========================================================================*/
#ifndef SD_DEFS_H
#define SD_DEFS_H

/**************** User configurable section *************************/


/* The base addresses for the seperate UART registers. */
#define SD_UART_A_BASE      0x0D800000
#define SD_UART_B_BASE      0x0D800020

#define SD_UART_A_VECTOR    8
#define SD_UART_B_VECTOR    9

/* Defines for use by applications */
#define UART_A_RXINT            0x0100
#define UART_B_RXINT            0x0200


/* Macros for specifying which UART to use. */
#define SD_UART_A           0
#define SD_UART_B           1
#define SD_UART1            SD_UART_A
#define SD_UART2            SD_UART_B

#define SD_MAX_UARTS        2

#define ICBASE          (0x0A000000)    /* Interrupt Controller Base */
#define IRQEnable       ((volatile int *)(ICBASE + 0x08))



/* These use specific type names, putting the register name
   in the macro, because these macros are used by port specific
   sections of code and will most likely have different names
   on other UARTS. */



/*******************************************************************************/
/* Receive Holding Register - RHR                                             */
/*******************************************************************************/
#define RHR_OFFSET          0x00        

/*******************************************************************************/
/* Transmit Holding Register - THR                                             */
/*******************************************************************************/
#define THR_OFFSET          0x00        


/*******************************************************************************/
/* Interrupt Enable Register - IER                                             */
/*******************************************************************************/
#define IER_OFFSET          0x04        
#define IER_Rx_Holding_Reg  0x01   /* b0 - Recieve Holding Register Interrupt
                                         - Enabled When Set   */
#define IER_Tx_Holding_Reg  0x02   /* b1 - Transmit Holding Register Interrupt 
                                         - Enabled When Set   */
#define IER_RX_Line_Status  0x04   /* b2 - recieve Line Status Interrupt 
                                         - Enabled When Set   */



/*******************************************************************************/
/*  FIFO Control Register - FCR                                               */
/*******************************************************************************/
#define FCR_OFFSET          0x08
#define FCR_FIFO_Enabled    0x01   /* b0 - Enabled When Set */
#define FCR_RCVR_Trig_level 0x40   /* b6-7 -  1 Byte Trigger Level */
#define FCR_FIFO_Reset      0x06   /* b1-2 - TX/RX FIFO Reset When Set */


/*******************************************************************************/
/* Interrupt Status Register - ISR                                             */
/*******************************************************************************/
#define ISR_OFFSET          0x08
#define ISR_Rx_Rdy          0x04   /* 0 1 0 - Received Data Ready           Priority 2 */
#define ISR_Tx_Rdy          0x02   /* 0 0 1 - Transmitter Holding Reg Empty Priority 3 */

/*******************************************************************************/
/*  Latch Control Register - LCR                                               */
/*******************************************************************************/
#define LCR_OFFSET          0x0C
#define LCR_5_Bit_Word      0x00   /* 0 0  - 5 Bit Word   */
#define LCR_6_Bit_Word      0x01   /* 0 1  - 6 Bit Word   */ 
#define LCR_7_Bit_Word      0x02   /* 1 0  - 7 Bit Word   */
#define LCR_8_Bit_Word      0x03   /* 1 1  - 8 Bit Word   */

#define LCR_Stop_Bit_1	    0x00  /* 1 stop bit */
#define LCR_Stop_Bit_2	    0x04  /* 2 stop bit */

#define LCR_Parity_Enable   0x01   /* b3 - Enable Parity Bit Generation and Check
                                         - Enabled When Set */
#define LCR_Parity_Disable  0x00   /* b3 - Enable Parity Bit Generation and Check 
                                         - Enabled When Set */
#define LCR_Parity_Even     0x10   /* b4 - Odd/Even Parity Generation and Check   
                                         - Even When Set    */
#define LCR_Parity_Odd      0x00   /* b4 - Odd/Even Parity Generation and Check   
                                         - Odd When Set    */
#define LCR_Divisor_Latch   0x80   /* b7 - Enable Internal Baud Rate Latch        
                                         - Enabled When Set */
#define LCR_Break_Set       0x40   /* b6 - Force Break Control ( Tx o/p low)      
                                         - Forced When Set  */
#define LCR_NO_Break        0x00   /* b6 - Normal operating conditions */

/*******************************************************************************/
/* Modem Control Register - MCR                                                */
/*******************************************************************************/
#define MCR_OFFSET          0x10
#define MCR_DTR_Low         0x01   /* b0 - Set DTR Signal Low/High - DTR Low when Set */
#define MCR_RTS_Low         0x02   /* b1 - Set RTS Signal Low/High - RTS Low when Set */
                                   /* MCR b2 is not used                              */
#define MCR_Interrupt_En    0x08   /* b3 - Interrupt output pin Operate/3-State  
                                         - Operate when Set */

#define MCR_Normal_Mode     0x00   /* b4 - normal operating mode */
#define MCR_Loop_Back       0x10   /* b4 - enable loopback mode */
#define MCR_Not_Used        0x04   /* b2 - not used */ 

/* The Following Registers are Status Registers which Report conditions within the    */
/* UART/PPP during operation. The defined values are masks to ensure that the register*/
/* flags are correctly accessed */

/*******************************************************************************/
/* Line Status Register - LSR                                                                              */
/*******************************************************************************/
#define LSR_OFFSET          0x14
#define LSR_Rx_Data_Ready   0x01   /* b0 - Data Recieved and Saved in Holding Reg 
                                         - Set when Valid */
#define LSR_Overrun_Error   0x02   /* b1 - Overrun Error Occured                  
                                         - Set When Valid */
#define LSR_Parity_Error    0x04   /* b2 - Received Data has Incorrect Parity     
                                         - Set When Valid */
#define LSR_Framing_Error   0x08   /* b3 - Framing Error (No Stop Bit)            
                                         - Set When Valid */
#define LSR_Tx_Hold_Empty   0x20   /* b5 - Tx Holding Register is empty and ready 
                                         - Set When Valid */
#define LSR_Tx_Hold_Full    0x00   /* b5 - Tx Holding Register is Full */
                                         
#define LSR_Tx_Empty        0x40   /* b6 - 1= Tx Holding and shift registers are empty */
#define LSR_Tx_Full         0x00   /* b6 - 0= Tx Holding and shift registers are full */

#define LSR_Fifo_Error      0x80   /* b7 - At Least one of b4 - b2 has occurred   
                                         - Set When Valid */

/*******************************************************************************/
/* Modem Status Register - MSR                                                                              */
/*******************************************************************************/
#define MSR_OFFSET          0x18


/*******************************************************************************/
/* Divisor Latch LSB                                                           */
/*******************************************************************************/
#define DLL_OFFSET          0x00

/*******************************************************************************/
/* Divisor Latch MSB                                                           */
/*******************************************************************************/
#define DLM_OFFSET          0x04


/* These use generic type names, leaving off the register name
   in the macro, because they are used by generic sections of
   code which will not require changes for other UARTS. Only the
   bits these correspond to should change. */

/* UART Line Control Register Bits */
#define SD_PARITY_NONE              LCR_Parity_Disable
#define SD_PARITY_EVEN              LCR_Parity_Even
#define SD_PARITY_ODD               LCR_Parity_Odd

#define SD_DATA_BITS_5              LCR_5_Bit_Word
#define SD_DATA_BITS_6              LCR_6_Bit_Word
#define SD_DATA_BITS_7              LCR_7_Bit_Word
#define SD_DATA_BITS_8              LCR_8_Bit_Word

#define SD_STOP_BITS_1              LCR_Stop_Bit_1
#define SD_STOP_BITS_2              LCR_Stop_Bit_2

#define SD_MODE_NORMAL              MCR_Normal_Mode
#define SD_MODE_AUTO_ECHO           MCR_Not_Used
#define SD_MODE_LOCAL_LOOP          MCR_Loop_Back
#define SD_MODE_REMOTE_LOOP         MCR_Not_Used

/* Define data structures for management of a serial port. */

typedef struct SD_INIT_STRUCT
{
    UNSIGNED        data_mode;
    UNSIGNED        base_address;

    /* The following elements should generic accross other
       platforms. */
    NU_SEMAPHORE    *sd_semaphore;
    UNSIGNED        com_port;
    UNSIGNED        data_bits;
    UNSIGNED        stop_bits;
    UNSIGNED        parity;
    UNSIGNED        baud_rate;
    UNSIGNED        vector;
	UNSIGNED		driver_options;
	UNSIGNED		sd_buffer_size;

    UNSIGNED        parity_errors;
    UNSIGNED        frame_errors;
    UNSIGNED        overrun_errors;
	UNSIGNED		busy_errors;
	UNSIGNED        general_errors;

    CHAR            *rx_buffer;
 	INT             rx_buffer_read;
	INT             rx_buffer_write;
	INT             rx_buffer_status; 

    /* All of the following elements are required by PPP, do not modify. */
	UNSIGNED        communication_mode;
	CHAR            *tx_buffer;
 	INT             tx_buffer_read;
	INT             tx_buffer_write;
	INT             tx_buffer_status; 

} SD_PORT;

/* Defines to be used by application */
#define MODE_NORMAL       SD_MODE_NORMAL
#define MODE_AUTO_ECHO    SD_MODE_AUTO_ECHO
#define MODE_LOCAL_LOOP   SD_MODE_LOCAL_LOOP
#define MODE_REMOTE_LOOP  SD_MODE_REMOTE_LOOP

#define STOP_BITS_1       SD_STOP_BITS_1
#define STOP_BITS_2       SD_STOP_BITS_2

#define UART1             SD_UART_A
#define UART2             SD_UART_B

/* Defines to determine communication mode */
#define SERIAL_MODE					0
#define MDM_NETWORK_COMMUNICATION   1
#define MDM_TERMINAL_COMMUNICATION  2

/**************** End configurable section *************************/

/***********************************************************************
 Note: everything below should be genric.
*/

#define NU_SERIAL_PORT          SD_PORT
#define PARITY_NONE             SD_PARITY_NONE
#define PARITY_EVEN             SD_PARITY_EVEN
#define PARITY_ODD              SD_PARITY_ODD

#define DATA_BITS_6             SD_DATA_BITS_6
#define DATA_BITS_7             SD_DATA_BITS_7
#define DATA_BITS_8             SD_DATA_BITS_8

#define NU_SD_Put_Char          SDC_Put_Char
#define NU_SD_Get_Char          SDC_Get_Char
#define NU_SD_Put_String        SDC_Put_String
#define NU_SD_Init_Port         SDC_Init_Port
#define NU_SD_Data_Ready        SDC_Data_Ready

#define NU_UART_SUCCESS         0
#define NU_INVALID_PARITY       -1
#define NU_INVALID_DATA_BITS    -2
#define NU_INVALID_STOP_BITS    -3
#define NU_INVALID_BAUD         -4
#define NU_INVALID_COM_PORT     -5
#define NU_INVALID_DATA_MODE    -6
#define NU_UART_LIST_FULL       -7

#define NU_BUFFER_FULL          1
#define NU_BUFFER_DATA          2
#define NU_BUFFER_EMPTY         3

/* Deifine IO macros. */

/* 8 bit access */
#define SD_OUTBYTE(reg, data)   ( (*( (UINT8 *) (reg) ) ) = (data) )

#define SD_INBYTE(reg)          (  *( (UINT8 *) (reg) ) )

/* 16 bit access */
#define SD_OUTWORD(reg, data)   ( (*( (unsigned short *) (reg) ) ) = (data) )

#define SD_INWORD(reg)          (  *( (unsigned short *) (reg) ) )

/* 32 bit access */
#define SD_OUTDWORD(reg, data)  ( (*( (UNSIGNED *) (reg) ) ) = (data) )

#define SD_INDWORD(reg)         (  *( (UNSIGNED *) (reg) ) )

/*Macro used for converting URT to SD_PORT. This is for PPP serial driver
  backwards compatability. */
#define URT_LAYER						SD_PORT

#define URT_TX_BUFFER_SIZE				uart->sd_buffer_size
#define URT_Get_Char					SDC_Get_Char
#define URT_Put_Char					SDC_Put_Char
#define URT_Reset						SDC_Reset
#define URT_Change_Communication_Mode	SDC_Change_Communication_Mode
#define URT_Carrier						SDC_Carrier


#endif /* ifndef SD_DEFS_H */


