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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   md_pccif_hw.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This Module defines PCCIF HW defintion.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __MD_PCCIF_HW_H__
#define __MD_PCCIF_HW_H__

/**************** Base address definition ****************/
#define CCIF0_OFF    0x0
#define CCIF1_OFF    0x400
#define PCCIF_OFF    0x800

#define PCCIF_SRAM_OFF    0x100

#if defined(__MD1__)

#define PCCIF_CTRL_REG_base           (PCCIF_MD1_base + PCCIF_OFF)
#define PCCIF_REMOTE_CTRL_REG_base    (PCCIF_MD2_base + PCCIF_OFF)
#define PCCIF_CTRL_SRAM_base          (PCCIF_MD1_base + PCCIF_OFF + PCCIF_SRAM_OFF)
#define PCCIF_TX_SRAM_base            (PCCIF_MD1_base + CCIF0_OFF + PCCIF_SRAM_OFF)    //- Use CCIF0 for MD1 -> MD2
#define PCCIF_RX_SRAM_base            (PCCIF_MD1_base + CCIF1_OFF + PCCIF_SRAM_OFF)    //- Use CCIF1 for MD2 -> MD1

#elif defined(__MD2__)
#define PCCIF_CTRL_REG_base           (PCCIF_MD2_base + PCCIF_OFF)
#define PCCIF_REMOTE_CTRL_REG_base    (PCCIF_MD1_base + PCCIF_OFF)
#define PCCIF_CTRL_SRAM_base          (PCCIF_MD2_base + PCCIF_OFF + PCCIF_SRAM_OFF)
#define PCCIF_TX_SRAM_base            (PCCIF_MD2_base + CCIF1_OFF + PCCIF_SRAM_OFF)    //- Use CCIF1 for MD2 -> MD1
#define PCCIF_RX_SRAM_base            (PCCIF_MD2_base + CCIF0_OFF + PCCIF_SRAM_OFF)    //- Use CCIF0 for MD1 -> MD2

#else
#error "Option error: Core type is not defined"
#endif



/**************** Register address definition ****************/
#define PCCIF_CON          ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0000))
#define PCCIF_BUSY         ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0004))
#define PCCIF_START        ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0008))
#define PCCIF_TCHNUM       ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x000C))
#define PCCIF_RCHNUM       ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0010))
#define PCCIF_ACK          ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0014))
#define PCCIF_MASK(irq)    ((volatile unsigned int *)(PCCIF_CTRL_REG_base + 0x0020 + (irq) * 4))

#define PCCIF_REMOTE_RCHNUM    ((volatile unsigned int *)(PCCIF_REMOTE_CTRL_REG_base + 0x0010))
#define PCCIF_REMOTE_ACK       ((volatile unsigned int *)(PCCIF_REMOTE_CTRL_REG_base + 0x0014))

#define PCCIF_SRAM_SIZE    512
#define PCCIF_CHANNEL_NUMBER    16
#define PCCIF_IRQ_NUMBER    4

#endif
