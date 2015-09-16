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
 *    idc_reg.h
 *
 * Project:
 * --------
 *   MOLY_Software
 *
 * Description:
 * ------------
 *   This file is intends for UART driver.
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
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __IDC_REG_H__
#define __IDC_REG_H__

#include "pf_bsictrl_apb2.h"
#include "idc_suart.h"

#if defined(MT6752)
#define IOCFG_L_BASE					0xA0002000
#endif

// Free Run Counter
#define FRC_VAL_R					(BASE_ADDR_MDTOPSM+0x88)  /* Free Running Counter Current Value */

// IDC BSI
#define IDC_BSI_TX_GLO_OS0				(REG_PERISYS_PFBSI_APB2_TX_GLO_OS0)
#define IDC_BSI_TX_GLO_OS1				(REG_PERISYS_PFBSI_APB2_TX_GLO_OS1)
#define IDC_BSI_TX_GLO_OS(_n)				(REG_PERISYS_PFBSI_APB2_TX_GLO_OS0+((_n)<<3))
#define IDC_BSI_SCH_START_3100				(REG_PERISYS_PFBSI_APB2_SCH_START_3100)
#define IDC_BSI_SCH_START_6332				(REG_PERISYS_PFBSI_APB2_SCH_START_6332)
#define IDC_BSI_SCH_START(_n)				(REG_PERISYS_PFBSI_APB2_SCH_START_3100+((_n)<<2))
#define	IDC_BSI_SCH_STOP_3100				(REG_PERISYS_PFBSI_APB2_SCH_STOP_3100)
#define IDC_BSI_SCH_STOP_6332				(REG_PERISYS_PFBSI_APB2_SCH_STOP_6332)
#define IDC_BSI_SCH_STATUS(_n)				(REG_PERISYS_PFBSI_APB2_SCH_STATUS_3100+((_n)<<2))
#define IDC_BSI_SCH_STATUS_3100				(REG_PERISYS_PFBSI_APB2_SCH_STATUS_3100)
#define IDC_BSI_SCH_STATUS_6332				(REG_PERISYS_PFBSI_APB2_SCH_STATUS_6332)
#define IDC_BSI_IND_ADDR				(REG_PERISYS_PFBSI_APB2_IND_ADDR)
#define IDC_BSI_IND_DATA				(REG_PERISYS_PFBSI_APB2_IND_DATA)

#define IDC_BSI_SCH_EVT_CON(_n)				(BASE_ADDR_BSI_DSPIO_IND + 0x000 + (_n) + ((_n) << 1))
#define IDC_BSI_SCH_EVT_CON2(_n)			(BASE_ADDR_BSI_DSPIO_IND + 0x001 + (_n) + ((_n) << 1))
#define IDC_BSI_SCH_EVT_OFFSET(_n)			(BASE_ADDR_BSI_DSPIO_IND + 0x002 + (_n) + ((_n) << 1))
#define IDC_BSI_SCH_DATA_L(_n)				(BASE_ADDR_BSI_DSPIO_IND + 0x200 + ((_n) << 2))
#define IDC_BSI_SCH_DATA_H(_n)				(BASE_ADDR_BSI_DSPIO_IND + 0x201 + ((_n) << 2))
#define IDC_BSI_SCH_DATA_MIPI_RWLEN(_n)			(BASE_ADDR_BSI_DSPIO_IND + 0x202 + ((_n) << 2))
#define IDC_BSI_SCH_DATA_MIPI_LOCK(_n)			(BASE_ADDR_BSI_DSPIO_IND + 0x203 + ((_n) << 2))



#define IDC_BSI_SCH_EVT_CON_STP_STA_ADDR(_STP, _STA)	(((_STP) << 8) | (_STA))

#define IDC_BSI_SCH_EVT_CON2_SCHE(_n)			(0x1000 | (_n))

// IDC UART
/*used in Task or normal function*/
#define IDC_UART_RBR					(REG_PERISYS_IDC_SUART_RBR_THR_DLL_ADDR)	// read only
#define IDC_UART_IER					(REG_PERISYS_IDC_SUART_IER_DLM_ADDR)
#define IDC_UART_IIR					(REG_PERISYS_IDC_SUART_IIR_FCR_EFR_ADDR)	// read only
#define IDC_UART_FCR					(REG_PERISYS_IDC_SUART_IIR_FCR_EFR_ADDR)	// write only
#define IDC_UART_LCR					(REG_PERISYS_IDC_SUART_LCR_ADDR)
#define IDC_UART_LSR					(REG_PERISYS_IDC_SUART_LSR_XON2_ADDR)
#define IDC_UART_RATE_STEP				(REG_PERISYS_IDC_SUART_RATE_STEP_ADDR)
#define IDC_UART_STEP_COUNT				(REG_PERISYS_IDC_SUART_STEP_COUNT_ADDR)
#define	IDC_UART_SAMPLE_COUNT				(REG_PERISYS_IDC_SUART_SAMPLE_COUNT_ADDR)
#define IDC_UART_RXTIMEOUT_ADDR				(REG_PERISYS_IDC_SUART_RXTIMEOUT_ADDR)
#define IDC_UART_DLL					(REG_PERISYS_IDC_SUART_RBR_THR_DLL_ADDR)
#define IDC_UART_DLM					(REG_PERISYS_IDC_SUART_IER_DLM_ADDR)
#define IDC_UART_RXTRIG					(REG_PERISYS_IDC_SUART_RXTRIG_ADDR)

#define IDC_UART_START_PRI				(REG_PERISYS_IDC_SUART_START_PRI)
#define IDC_UART_START_PRI_BITEN			(REG_PERISYS_IDC_SUART_START_PRI_BITEN)
#define IDC_UART_START_PAT				(REG_PERISYS_IDC_SUART_START_PAT)
#define IDC_UART_START_PAT_BITEN			(REG_PERISYS_IDC_SUART_START_PAT_BITEN)
#define IDC_UART_FINISH_PRI				(REG_PERISYS_IDC_SUART_FINISH_PRI)
#define IDC_UART_FINISH_PRI_BITEN			(REG_PERISYS_IDC_SUART_FINISH_PRI_BITEN)
#define IDC_UART_FINISH_PAT				(REG_PERISYS_IDC_SUART_FINISH_PAT)
#define IDC_UART_FINISH_PAT_BITEN			(REG_PERISYS_IDC_SUART_FINISH_PAT_BITEN)

//IER
#define IDC_UART_IER_ALLOFF				0x0000
#define IDC_UART_IER_ERBFI				0x0001

#define	ID_UART_RATE_STEP_COUNT				0x0003	// baud = clock/UART_RATE_STEP_COUNT

//FCR
#define IDC_UART_FCR_FIFOEN				0x0001
#define IDC_UART_FCR_CLRR				0x0002
#define IDC_UART_FCR_CLRT				0x0004
#define IDC_UART_FCR_FIFOINI				0x0007
#define IDC_UART_FCR_RXTRIG				0x00c0

#define IDC_UART_TxFIFO_DEPTH				16
#define IDC_UART_RxFIFO_DEPTH				24

//IIR (RO)
#define IDC_UART_IIR_INT_INVALID			0x0001
#define IDC_UART_IIR_RDA				0x0004  // Receive Data Available
#define IDC_UART_IIR_INT_MASK				0x001f

//===============================LCR================================
//WLS
#define IDC_UART_WLS_8					0x0003
#define IDC_UART_WLS_7					0x0002
#define IDC_UART_WLS_6					0x0001
#define IDC_UART_WLS_5					0x0000
#define IDC_UART_DATA_MASK				0x0003

//Parity
#define IDC_UART_NONE_PARITY				0x0000
#define IDC_UART_ODD_PARITY				0x0008
#define IDC_UART_EVEN_PARITY				0x0018
#define IDC_UART_ONE_PARITY				0x0028
#define IDC_UART_ZERO_PARITY				0x0038
#define IDC_UART_PARITY_MASK				0x0038

//Stop bits
#define IDC_UART_1_STOP					0x0000
#define IDC_UART_1_5_STOP				0x0004	// Only valid for 5 data bits
#define IDC_UART_2_STOP					0x0004
#define IDC_UART_STOP_MASK				0x0004

#define IDC_UART_LCR_DLAB				0x0080
//===============================LCR================================

//LSR
#define IDC_UART_LSR_DR					0x0001
#define IDC_UART_LSR_TEMT				0x0040

#endif // __IDC_REG_H__
