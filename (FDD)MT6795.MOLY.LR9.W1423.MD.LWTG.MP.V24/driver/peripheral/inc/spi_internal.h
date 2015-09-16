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
 *    spi_internal.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the SPI driver.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __spi_internal_h__
#define __spi_internal_h__

//////////////////RHR-ADD//////////////////////
#include "reg_base.h"
//////////////////RHR-ADD//////////////////////

//////////////////RHR-REMOVE//////////////////////
//#include <spi_define.h>
//////////////////////////////////////////////////


/**
 * \def SPI_CONF0_REG
 * \ingroup spi
 * Defines the SPI configuration 0 register.
 */
#define SPI_CONF0_REG    (*((kal_uint32 volatile *)((SPI_base) + 0x0)))

/**
 * \def SPI_CONF1_REG
 * \ingroup spi
 * Defines the SPI configuration 1 register.
 */
#define SPI_CONF1_REG    (*((kal_uint32 volatile *)((SPI_base) + 0x4)))

/**
 * \def SPI_TX_ADDR_REG
 * \ingroup spi
 * Defines the SPI TX source address register.
 */
#define SPI_TX_ADDR_REG  (*((kal_uint32 volatile *)((SPI_base) + 0x8)))

/**
 * \def SPI_RX_ADDR_REG
 * \ingroup spi
 * Defines the SPI RX destination address register.
 */
#define SPI_RX_ADDR_REG  (*((kal_uint32 volatile *)((SPI_base) + 0xC)))

#define SPI_TX_FIFO_REG_ADDR  ((kal_uint32 volatile *)((SPI_base) + 0x10))
/**
 * \def SPI_TX_FIFO_REG
 * \ingroup spi
 * Defines the SPI TX data FIFO register.
 */
#define SPI_TX_FIFO_REG  (*SPI_TX_FIFO_REG_ADDR)

#define SPI_RX_FIFO_REG_ADDR  ((kal_uint32 volatile *)((SPI_base) + 0x14))
/**
 * \def SPI_RX_FIFO_REG
 * \ingroup spi
 * Defines the SPI RX data FIFO register.
 */
#define SPI_RX_FIFO_REG  (*SPI_RX_FIFO_REG_ADDR)

/**
 * \def SPI_COMM_REG
 * \ingroup spi
 * Defines the SPI command register.
 */
#define SPI_COMM_REG     (*((kal_uint32 volatile *)((SPI_base) + 0x18)))

/**
 * \def SPI_STATUS1_REG
 * \ingroup spi
 * Defines the SPI status register 1.
 */
#define SPI_STATUS1_REG   (*((kal_uint32 volatile *)((SPI_base) + 0x1C)))

/**
 * \def SPI_STATUS2_REG
 * \ingroup spi
 * Defines the SPI status register 2.
 */
#define SPI_STATUS2_REG   (*((kal_uint32 volatile *)((SPI_base) + 0x20)))

#if defined  (DRV_SPI_GMC_ARBITRATE ) 
#define SPI_GMC_SLOW_DOWN_REG (*((kal_uint32 volatile *)((SPI_base) + 0x24)))
#define SPI_ULTRA_HIGH_PRIORITY_REG (*((kal_uint32 volatile *)((SPI_base) + 0x28)))
#endif
#if defined  (DRV_SPI_PAD_MACRO_SELECT ) 
#define SPI_PAD_MACRO_SELECT_REG (*((kal_uint32 volatile *)((SPI_base) + 0x2C)))
#endif
#if defined(MT6280)
#define SPI_PAD_MACRO_PDN_REG (*((kal_uint32 volatile *)((AP_CONFIG_base)+0x08)))
#endif

/** \enum SPI_COMM_REG_BIT_POS
 * \ingroup spi
 *
 * @brief
 * Specify the bit position in the SPI command register.
 */
enum SPI_COMM_REG_BIT_POS
{
  SPI_COMM_BIT_ACT            =  0,
  /**<
   * \ingroup spi
   * The activate bit.
   */
  SPI_COMM_BIT_RESUME         =  1,
  /**<
   * \ingroup spi
   * The resume bit.
   */
  SPI_COMM_BIT_RESET          =  2,
  /**<
   * \ingroup spi
   * The reset bit.
   */
  SPI_COMM_BIT_PAUSE_EN       =  4,
  /**<
   * \ingroup spi
   * The pause enable bit.
   */
  SPI_COMM_BIT_CS_DEASSERT_EN =  5,
  /**<
   * \ingroup spi
   * The deassert enable bit.
   */
  SPI_COMM_BIT_CPHA           =  8,
  /**<
   * \ingroup spi
   * The clock format bit.
   */
  SPI_COMM_BIT_CPOL           =  9,
  /**<
   * \ingroup spi
   * The clock polarity bit.
   */
  SPI_COMM_BIT_RX_DMA_EN      = 10,
  /**<
   * \ingroup spi
   * The RX DMA enable/disable bit.
   */
  SPI_COMM_BIT_TX_DMA_EN      = 11,
  /**<
   * \ingroup spi
   * The TX DMA enable/disable bit.
   */
  SPI_COMM_BIT_TX_MSBF        = 12,
  /**<
   * \ingroup spi
   * The TX MSB/LSB select bit.
   */
  SPI_COMM_BIT_RX_MSBF        = 13,
  /**<
   * \ingroup spi
   * The RX MSB/LSB select bit.
   */
  SPI_COMM_BIT_RX_ENDIAN      = 14,
  /**<
   * \ingroup spi
   * The RX big/little endian select bit.
   */
  SPI_COMM_BIT_TX_ENDIAN      = 15,
  /**<
   * \ingroup spi
   * The TX big/little endian select bit.
   */
  SPI_COMM_BIT_FINISH_IE      = 16,
  /**<
   * \ingroup spi
   * The finish mode enable/disable bit.
   */
  SPI_COMM_BIT_PAUSE_IE       = 17
  /**<
   * \ingroup spi
   * The pause mode enable/disable bit.
   */
};
typedef enum SPI_COMM_REG_BIT_POS SPI_COMM_REG_BIT_POS;

/** \enum SPI_STATUS1_BIT
 * \ingroup spi
 *
 * @brief
 * Specify the bit position in the SPI status register 1.
 */
enum SPI_STATUS1_BIT
{
  SPI_STATUS1_BIT_FINISH = (1 << 0),
  /**<
   * \ingroup spi
   * The finish bit in the SPI status register 1.
   */
  SPI_STATUS1_BIT_PAUSE = (1 << 1)
  /**<
   * \ingroup spi
   * The pause bit in the SPI status register 1.
   */
};
typedef enum SPI_STATUS1_BIT SPI_STATUS1_BIT;

/** \enum SPI_STATUS2_BIT
 * \ingroup spi
 *
 * @brief
 * Specify the bit position in the SPI status register 2.
 */
enum SPI_STATUS2_BIT
{
  SPI_STATUS2_BIT_BUSY = (1 << 0)
  /**<
   * \ingroup spi
   * The busy bit in the SPI status register 2.
   */
};
typedef enum SPI_STATUS2_BIT SPI_STATUS2_BIT;

/** \enum SPI_STATUS_REG
 * \ingroup spi
 *
 * @brief Choose the supported status registers.
 */
enum SPI_STATUS_REG
{
  SPI_STATUS_REG_1,
  /**<
   * \ingroup spi
   * status register 1
   */
  SPI_STATUS_REG_2
  /**<
   * \ingroup spi
   * status register 2
   */
};
typedef enum SPI_STATUS_REG SPI_STATUS_REG;

typedef enum
{
  SPI_GMC_SLOW_DOWN_ENABLE = 0,
  SPI_GMC_SPLIT_BURST_ENABLE = 4
} SPI_GMC_SLOW_DOWN_REG_BIT_POS;

typedef enum
{
  SPI_ULTRA_HIGH_ENABLE = 0
} SPI_ULTRA_HIGH_PRIORITY_REG_BIT_POS;

#endif
