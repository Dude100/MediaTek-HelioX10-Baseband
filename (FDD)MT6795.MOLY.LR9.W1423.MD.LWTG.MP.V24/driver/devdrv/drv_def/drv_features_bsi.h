/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * Filename:
 * ---------
 *    drv_features_bsi.h
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   This file is merged for BSI driver feature options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_BSI_H__
#define __DRV_FEATURES_BSI_H__

#include "drv_features_chip_select.h"

/**************** BSI ******************/
#if defined(DRV_BSI_6290_SERIES)

  #define A60386_TARGET                 (0)
  #if A60386_TARGET

  // BSI Setting
  #define DRV_BSI_PORT_SEL              (0)  // Immediate mode port select to 0
  #define DRV_BSI_CS_SEL                (0)  // Immediate mode chip select to 0

  // BSISPI Setting
  #define DRV_BSI_MIPI_EN               (0)  // Port for SPI, not MIPI
  #define DRV_BSI_MODE                  (0)  // For 3-wire interface
  #define DRV_BSI_SINGLE_DIR            (0)  // default value
  #define DRV_BSI_CLSNINT_EN            (0)  // Disable RAT collision interrupt
  #define DRV_BSI_DBG_EN                (0)  // default value
  #define DRV_BSI_READ_PHASE            (1)  // Read phase selection
  #define DRV_BSI_RESET_MODE            (0)  // Defines BSI port DATA mode to 0 before first BSI event
  #define DRV_BSI_IO_MODE               (0)  // default value
  #define DRV_BSI_SW_CS_SEL             (0)  // default value

  #define DRV_BSI_CS0_SUPPORT           (1)  // CS0 is connected to a target
  #if DRV_BSI_CS0_SUPPORT
  #define DRV_BSI_CLK_POL0              (1)  // default value
  #define DRV_BSI_CLK_SPD0              (0)  // default value
  #define DRV_BSI_CS0_LEN               (0)  // default value
  #define DRV_BSI_CS0_POL               (1)  // default value
  #define DRV_BSI_RD_CLK_SPD0           (2)  // default value
  #define DRV_BSI_RD_TRANS_CLKON0       (1)  // default value
  #define DRV_BSI_RD_TRANS_LEN0         (12) // default value
  #define DRV_BSI_IDLE_CNT0             (0)  // default value
  #define DRV_BSI_WLEN0                 (28) // Write data length for IC0: (28) + 1 = 29
  #define DRV_BSI_RD_TRANS_CS0_WAVEFORM (0)  // default value
  #define DRV_BSI_RD_RDATA_CS0_POL      (0)  // default value
  #define DRV_BSI_RD_WLEN0              (12) // Write length of a read event for IC0: (12) + 1 = 13
  #define DRV_BSI_RD_RLEN0              (15) // Read back data length for IC0: (15) + 1 = 16
  #endif /* DRV_BSI_CS0_SUPPORT */

  #else /* A60386_TARGET */

  // BSI Setting
  #define DRV_BSI_PORT_SEL              (0)  // Immediate mode port select to 0
  #define DRV_BSI_CS_SEL                (0)  // Immediate mode chip select to 0

  // BSISPI Setting
  #define DRV_BSI_MIPI_EN               (0)  // Port for SPI, not MIPI
  #define DRV_BSI_MODE                  (0)  // For 3-wire interface
  #define DRV_BSI_SINGLE_DIR            (0)  // default value
  #define DRV_BSI_CLSNINT_EN            (0)  // Disable RAT collision interrupt
  #define DRV_BSI_DBG_EN                (0)  // default value
  #define DRV_BSI_READ_PHASE            (1)  // Read phase selection
  #define DRV_BSI_RESET_MODE            (0)  // Defines BSI port DATA mode to 0 before first BSI event
  #define DRV_BSI_IO_MODE               (0)  // default value
  #define DRV_BSI_SW_CS_SEL             (0)  // default value

  #define DRV_BSI_CS0_SUPPORT           (1)  // CS0 is connected to a target
  #if DRV_BSI_CS0_SUPPORT
  #define DRV_BSI_CLK_POL0              (1)  // default value
  #define DRV_BSI_CLK_SPD0              (2)  // default value
  #define DRV_BSI_CS0_LEN               (2)  // default value
  #define DRV_BSI_CS0_POL               (0)  // default value
  #define DRV_BSI_RD_CLK_SPD0           (5)  // default value
  #define DRV_BSI_RD_TRANS_CLKON0       (1)  // default value
  #define DRV_BSI_RD_TRANS_LEN0         (1)  // default value
  #define DRV_BSI_IDLE_CNT0             (0)  // default value
  #define DRV_BSI_WLEN0                 (24) // Write data length for IC0: (24) + 1 = 25
  #define DRV_BSI_RD_TRANS_CS0_WAVEFORM (0)  // default value
  #define DRV_BSI_RD_RDATA_CS0_POL      (0)  // default value
  #define DRV_BSI_RD_WLEN0              (8)  // Write length of a read event for IC0: (8) + 1 = 9
  #define DRV_BSI_RD_RLEN0              (15) // Read back data length for IC0: (15) + 1 = 16
  #endif /* DRV_BSI_CS0_SUPPORT */

  #endif /* else of A60386_TARGET */

  #define DRV_BSI_CS1_SUPPORT           (0)  // CS1 is not connected to a target
  #if DRV_BSI_CS1_SUPPORT
  #define DRV_BSI_CLK_POL1              (1)  // default value
  #define DRV_BSI_CLK_SPD1              (0)  // default value
  #define DRV_BSI_CS1_LEN               (2)  // default value
  #define DRV_BSI_CS1_POL               (0)  // default value
  #define DRV_BSI_RD_CLK_SPD1           (0)  // default value
  #define DRV_BSI_RD_TRANS_CLKON1       (1)  // default value
  #define DRV_BSI_RD_TRANS_LEN1         (1)  // default value
  #define DRV_BSI_IDLE_CNT1             (0)  // default value
  #define DRV_BSI_WLEN1                 (30) // Write data length for IC1: default value
  #define DRV_BSI_RD_TRANS_CS1_WAVEFORM (0)  // default value
  #define DRV_BSI_RD_RDATA_CS1_POL      (0)  // default value
  #define DRV_BSI_RD_WLEN1              (8)  // Write length of a read event for IC1: default value
  #define DRV_BSI_RD_RLEN1              (21) // Read back data length for IC1: default value
  #endif /* DRV_BSI_CS1_SUPPORT */

#endif /* DRV_BSI_6290_SERIES */

#endif /* __DRV_FEATURES_BSI_H__ */
