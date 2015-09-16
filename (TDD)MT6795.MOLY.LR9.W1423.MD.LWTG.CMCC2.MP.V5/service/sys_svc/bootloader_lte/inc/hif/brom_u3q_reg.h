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
 *   brom_hif_u3q_reg.h
 *
 * Project:
 * --------
 *   BOOTROM
 *
 * Description:
 * ------------
 *	This is the USB2.0 QMU hardware register definition head file.
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/


#ifndef __BROM_U3Q_REG_H__
#define __BROM_U3Q_REG_H__

#include "brom_u3mac_reg.h"

#define USB_BASE	SSUSB_DEV_BASE

/*!
 *	@brief	the U3 QMU que number start from 1 and is U2 QMU que start from 0
 *			In U3 QMU, we sync the queue number operation to U2 QMU
*/

#ifdef U3_DUAL_MODE_IP
/* USB QMU  Register */
#define USB3_QMU_QCR0				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0400)
#define USB3_QMU_QCR1				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0404)
#define USB3_QMU_QCR2				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0408)
#define USB3_QMU_QCR3				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x040C)
#define USB3_QMU_QGCSR				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0410)
#define USB3_QMU_QCAPR				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0420)
#define USB3_QMU_TXQCSR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0510)
#define USB3_QMU_TXQSAR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0514)
#define USB3_QMU_TXQCPR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0518)
#define USB3_QMU_RXQCSR1	    	(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0610)
#define USB3_QMU_RXQSAR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0614)
#define USB3_QMU_RXQCPR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0618)
#define USB3_QMU_RXQLDPR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x061C) //Last Done Pointer Register
#define USB3_QMU_QISAR0				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0700) //TX/RX done interrupt status
#define USB3_QMU_QIER0				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0704) //TX/RX done interrupt enable 
#define USB3_QMU_QIESR0				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0708) //TX/RX done interrupt enable set
#define USB3_QMU_QIECR0				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x070C) //TX/RX done interrupt enable clear
#define USB3_QMU_QISAR1				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0710) //empty and error interrupt status
#define USB3_QMU_QIER1				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0714) //empty and error interrupt enable
#define USB3_QMU_QIESR1				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0718) //empty and error interrupt enable set
#define USB3_QMU_QIECR1				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x071C) //empty and error interrupt enable clear
#define USB3_QMU_QEMIR				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0740) //empty interrupt status 
#define USB3_QMU_QEMIER				(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0744)
#define USB3_QMU_QEMIESR			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0748)
#define USB3_QMU_QEMIECR			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x074C)
#define USB3_QMU_TQERRIR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0780)//TX queue error interrupt
#define USB3_QMU_TQERRIER0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0784)
#define USB3_QMU_TQERRIESR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x0788)
#define USB3_QMU_TQERRIECR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x078C)
#define USB3_QMU_RQERRIR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07C0)//RX queue error interrupt
#define USB3_QMU_RQERRIER0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07C4)
#define USB3_QMU_RQERRIESR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07C8)
#define USB3_QMU_RQERRIECR0			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07CC)
#define USB3_QMU_RQERRIR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07D0)//RX queue error interrupt
#define USB3_QMU_RQERRIER1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07D4)
#define USB3_QMU_RQERRIESR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07D8)
#define USB3_QMU_RQERRIECR1			(volatile unsigned int *)(SSUSB_DEV_BMU_BASE+0x07DC)
#else /*U3_DUAL_MODE_IP*/
/* USB QMU  Register */
#define USB3_QMU_QCR0				(volatile unsigned int *)(USB_BASE+0x1400)
#define USB3_QMU_QCR1				(volatile unsigned int *)(USB_BASE+0x1404)
#define USB3_QMU_QCR2				(volatile unsigned int *)(USB_BASE+0x1408)
#define USB3_QMU_QCR3				(volatile unsigned int *)(USB_BASE+0x140C)
#define USB3_QMU_QGCSR				(volatile unsigned int *)(USB_BASE+0x1410)
#define USB3_QMU_QCAPR				(volatile unsigned int *)(USB_BASE+0x1420)
#define USB3_QMU_TXQCSR1			(volatile unsigned int *)(USB_BASE+0x1510)
#define USB3_QMU_TXQSAR1			(volatile unsigned int *)(USB_BASE+0x1514)
#define USB3_QMU_TXQCPR1			(volatile unsigned int *)(USB_BASE+0x1518)
#define USB3_QMU_RXQCSR1	    	(volatile unsigned int *)(USB_BASE+0x1610)
#define USB3_QMU_RXQSAR1			(volatile unsigned int *)(USB_BASE+0x1614)
#define USB3_QMU_RXQCPR1			(volatile unsigned int *)(USB_BASE+0x1618)
#define USB3_QMU_RXQLDPR1			(volatile unsigned int *)(USB_BASE+0x161C) //Last Done Pointer Register
#define USB3_QMU_QISAR0				(volatile unsigned int *)(USB_BASE+0x1700) //TX/RX done interrupt status
#define USB3_QMU_QIER0				(volatile unsigned int *)(USB_BASE+0x1704) //TX/RX done interrupt enable 
#define USB3_QMU_QIESR0				(volatile unsigned int *)(USB_BASE+0x1708) //TX/RX done interrupt enable set
#define USB3_QMU_QIECR0				(volatile unsigned int *)(USB_BASE+0x170C) //TX/RX done interrupt enable clear
#define USB3_QMU_QISAR1				(volatile unsigned int *)(USB_BASE+0x1710) //empty and error interrupt status
#define USB3_QMU_QIER1				(volatile unsigned int *)(USB_BASE+0x1714) //empty and error interrupt enable
#define USB3_QMU_QIESR1				(volatile unsigned int *)(USB_BASE+0x1718) //empty and error interrupt enable set
#define USB3_QMU_QIECR1				(volatile unsigned int *)(USB_BASE+0x171C) //empty and error interrupt enable clear
#define USB3_QMU_QEMIR				(volatile unsigned int *)(USB_BASE+0x1740) //empty interrupt status 
#define USB3_QMU_QEMIER				(volatile unsigned int *)(USB_BASE+0x1744)
#define USB3_QMU_QEMIESR			(volatile unsigned int *)(USB_BASE+0x1748)
#define USB3_QMU_QEMIECR			(volatile unsigned int *)(USB_BASE+0x174C)
#define USB3_QMU_TQERRIR0			(volatile unsigned int *)(USB_BASE+0x1780)//TX queue error interrupt
#define USB3_QMU_TQERRIER0			(volatile unsigned int *)(USB_BASE+0x1784)
#define USB3_QMU_TQERRIESR0			(volatile unsigned int *)(USB_BASE+0x1788)
#define USB3_QMU_TQERRIECR0			(volatile unsigned int *)(USB_BASE+0x178C)
#define USB3_QMU_RQERRIR0			(volatile unsigned int *)(USB_BASE+0x17C0)//RX queue error interrupt
#define USB3_QMU_RQERRIER0			(volatile unsigned int *)(USB_BASE+0x17C4)
#define USB3_QMU_RQERRIESR0			(volatile unsigned int *)(USB_BASE+0x17C8)
#define USB3_QMU_RQERRIECR0			(volatile unsigned int *)(USB_BASE+0x17CC)
#define USB3_QMU_RQERRIR1			(volatile unsigned int *)(USB_BASE+0x17D0)//RX queue error interrupt
#define USB3_QMU_RQERRIER1			(volatile unsigned int *)(USB_BASE+0x17D4)
#define USB3_QMU_RQERRIESR1			(volatile unsigned int *)(USB_BASE+0x17D8)
#define USB3_QMU_RQERRIECR1			(volatile unsigned int *)(USB_BASE+0x17DC)
#endif /*U3_DUAL_MODE_IP*/



/**
 *  @brief  USB3_QMU_QISAR0 QMU Done layer 2 interrupt
 */                            
#define U3_TXQ0_DONE_INTR			0x00000002
#define U3_TXQ_DONE_INTR(n)			(U3_TXQ0_DONE_INTR << n)
#define U3_RXQ0_DONE_INTR		0x00020000
#define U3_RXQ_DONE_INTR(n)			(U3_RXQ0_DONE_INTR << n)

/**
 *  @brief  USB3_QMU_QISAR1 QMU empty and error layer 2 interrupt
 */                            
#define U3_TXQ_EMPTY_INTR_FLAG			(0x1 << 0)
#define U3_TXQ_CSERR_INTR_FLAG			(0x1 << 1)
#define U3_TXQ_LENERR_INTR_FLAG			(0x1 << 2)
#define U3_RXQ_EMPTY_INTR_FLAG			(0x1 << 16)
#define U3_RXQ_CSERR_INTR_FLAG			(0x1 << 17)
#define U3_RXQ_LENERR_INTR_FLAG			(0x1 << 18)
#define U3_RXQ_ZLPERR_INTR_FLAG			(0x1 << 20)

/**
 *  @brief  USB3_QMU_QEMIR QMU empty layer 3 interrupt
 */                            
#define U3_TXQ_EMPTY_INTR_MASK			0x0000FFFE
#define U3_TXQ0_EMPTY_INTR				0x00000002
#define U3_TXQ_EMPTY_INTR(n)			(U3_TXQ0_EMPTY_INTR << n)
#define U3_RXQ_EMPTY_INTR_MASK			0xFFFE0000
#define U3_RXQ0_EMPTY_INTR				0x00020000
#define U3_RXQ_EMPTY_INTR(n)			(U3_RXQ0_EMPTY_INTR << n)


/**
 *  @brief  USB3_QMU_TQERRIR0 QMU TXQ error layer 3 interrupt
 */                            
#define U3_TXQ_CSERR_INTR_MASK			0x0000FFFE
#define U3_TXQ0_CSERR_INTR				0x00000002
#define U3_TXQ_CSERR_INTR(n)			(U3_TXQ0_CSERR_INTR << n)
#define U3_TXQ_LENERR_INTR_MASK			0xFFFE0000
#define U3_TXQ0_LENERR_INTR				0x00020000
#define U3_TXQ_LENERR_INTR(n)			(U3_TXQ0_LENERR_INTR << n)

/**
 *  @brief  USB3_QMU_RQERRIR0 QMU RXQ error layer 3 interrupt
 */                            
#define U3_RXQ_CSERR_INTR_MASK			0x0000FFFE
#define U3_RXQ0_CSERR_INTR				0x00000002
#define U3_RXQ_CSERR_INTR(n)			(U3_RXQ0_CSERR_INTR << n)
#define U3_RXQ_LENERR_INTR_MASK			0xFFFE0000
#define U3_RXQ0_LENERR_INTR				0x00020000
#define U3_RXQ_LENERR_INTR(n)			(U3_RXQ0_LENERR_INTR << n)

/**
 *  @brief  USB3_QMU_RQERRIR1 QMU RXQ error layer 3 interrupt
 */                            
#define U3_RXQ_ZLPERR_INTR_MASK			0xFFFE0000
#define U3_RXQ0_ZLPERR_INTR				0x00020000
#define U3_RXQ_ZLPERR_INTR(n)			(U3_RXQ0_ZLPERR_INTR << n)


/**
 *  @brief  Per-Queue Control related CSR
 */                            
#define USB3_QMU_RQCSR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_RXQCSR1) + (0x10 * q_num))
#define USB3_QMU_RQSAR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_RXQSAR1) + (0x10 * q_num))
#define USB3_QMU_RQCPR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_RXQCPR1) + (0x10 * q_num))
#define USB3_QMU_TQCSR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_TXQCSR1) + (0x10 * q_num))
#define USB3_QMU_TQSAR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_TXQSAR1) + (0x10 * q_num))
#define USB3_QMU_TQCPR_n(q_num)				(volatile unsigned int *)(((unsigned int)USB3_QMU_TXQCPR1) + (0x10 * q_num))
#define USB3_QMU_RQLDPR_n(q_num)			(volatile unsigned int *)(((unsigned int)USB3_QMU_RXQLDPR1) + (0x10 * q_num))

/**
 *  @brief  Queue Control value Definition
 */                            
#define U3_DQMU_QUE_START	0x00000001
#define U3_DQMU_QUE_RESUME	0x00000002
#define U3_DQMU_QUE_STOP	0x00000004
#define U3_DQMU_QUE_ACTIVE	0x00008000

/**
 *  @brief  USB QMU Special Control USB3_QMU_QGCSR value Definition
 */   
#define USB3_QMU_TX1_EN 			0x00000002 //sync with U2Q
#define USB3_QMU_TX_EN(n) 			(USB3_QMU_TX1_EN << n)
#define USB3_QMU_RX1_EN 			0x00020000 //sync with U2Q
#define USB3_QMU_RX_EN(n) 			(USB3_QMU_RX1_EN << n)

/**
 *  @brief  USB3_QMU_QCR0 field Definition
 */   
#define U3_DQMU_CS16_EN					0x1 //0 : cs12 , 1: cs16
#define U3_DQMU_TQ1CS_EN				0x00000002 //sync with U2Q
#define U3_DQMU_TQCS_EN(n)				(U3_DQMU_TQ1CS_EN << n)
#define U3_DQMU_RQ1CS_EN				0x00020000 //sync with U2Q
#define U3_DQMU_RQCS_EN(n)				(U3_DQMU_RQ1CS_EN << n)

/**
 *  @brief  USB3_QMU_QCR1 field Definition
 */   
#define U3_DQMU_TXQ1_ZLP_GPD_EN				0x00000002 //sync with U2Q
#define U3_DQMU_TXQ_ZLP_GPD_EN(n)			(U3_DQMU_TXQ1_ZLP_GPD_EN << n)

/**
 *  @brief  USB3_QMU_QCR2 field Definition
 */   
#define U3_DQMU_TX1_ZLP 				0x00000002
#define U3_DQMU_TX_ZLP(n)				(U3_DQMU_TX1_ZLP << n)

/**
 *  @brief  USB3_QMU_QCR3 field Definition
 */
#define U3_DQMU_RX_ZLP_MASK				0x0000FFFE
#define U3_DQMU_RX1_ZLP 				0x00000002
#define U3_DQMU_RX_ZLP(n)				(U3_DQMU_RX1_ZLP << n)
#define U3_DQMU_RX_COZ_MASK				0xFFFE0000
#define U3_DQMU_RX1_COZ					0x00020000 //sync with U2Q
#define U3_DQMU_RX_COZ(n)				(U3_DQMU_RX1_COZ << n)

#endif
