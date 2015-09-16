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
 *   spi.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for SPI driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __spi_h__
#define __spi_h__

//////////////////RHR-ADD//////////////////////
#include "kal_general_types.h"
#include "kal_public_defs.h"
//////////////////RHR-ADD//////////////////////

//////////////////RHR-REMOVE//////////////////////
//#include <spi_define.h>
//////////////////////////////////////////////////

#include "drv_features.h"

#if defined(DRV_SPI_SUPPORT)

/** \brief Open the SPI interface
 * 
 * Before using the SPI interface, users have to call this
 * function to get one unique number to be used in later SPI
 * API functions.
 *
 * \param id Points to a kal_int32. When this function is
 * finished, and if it succeed, this variable is represented
 * as an unique identification number which is used as a
 * parameter in the other SPI API functions if needed.
 * \return 
 * - KAL_TRUE if the SPI interface is available.
 * - KAL_FALSE if the SPI interface is unavailable.
 */
#ifdef DRV_SPI_HAL
#define SPI_OPEN(id) spi_open_old((id), __FILE__, __LINE__);
#else
#define SPI_OPEN(id) spi_open((id), __FILE__, __LINE__);
#endif

/** \brief Release the ownership of the SPI interface, so
 * that others can use it.
 *
 * spi_open() will get the ownership of the SPI interface,
 * you have to call this function to release the ownership.
 * 
 * \param id The return value of spi_open().
 * \return
 * - KAL_TRUE if success.
 * - KAL_FALSE if failure, caller can use spi_get_error_code()
 * to examine what was wrong.
 */
#ifdef DRV_SPI_HAL
#define SPI_CLOSE(id) spi_close_old((id))
#else
#define SPI_CLOSE(id) spi_close((id))
#endif


#define SPI_INTERFACE_MAX_PKT_LENGTH_PER_TIMES (0x400)
#define SPI_INTERFACE_MAX_PKT_COUNT_PER_TIMES  (0x100)

/**
 * \def SPI_FIFO_SIZE
 * \ingroup spi
 * Defines the internal TX/RX FIFO size of the SPI controller.
 */
#define SPI_FIFO_SIZE (32)

/** \enum SPI_TIME_TYPE
 * \ingroup spi
 *
 * @brief
 * Specify the time intervals used by the SPI interface.
 */
enum SPI_TIME_TYPE {
  SPI_TIME_SETUP,
  /**<
   * \ingroup spi
   * Setup time.
   */
  SPI_TIME_HOLD,
  /**<
   * \ingroup spi
   * Hold time.
   */
  SPI_TIME_LOW,
  /**<
   * \ingroup spi
   * Low voltage time of the SPI clock.
   */
  SPI_TIME_HIGH,
  /**<
   * \ingroup spi
   * High voltage time of the SPI clock.
   */
  SPI_TIME_IDLE
  /**<
   * \ingroup spi
   * Idle time.
   */
};
typedef enum SPI_TIME_TYPE SPI_TIME_TYPE;

/** \enum SPI_INT_TYPE
 * \ingroup spi
 *
 * @brief
 * SPI interrupt category enum.
 *
 * This enumeration defines the two interrupts which SPI devices can generate.
 */
enum SPI_INT_TYPE {
  SPI_INT_PAUSE,
  /**<
   * \ingroup spi
   * Pause interrupt.
   */
  SPI_INT_FINISH
  /**<
   * \ingroup spi
   * Finish interrupt.
   */
};
typedef enum SPI_INT_TYPE SPI_INT_TYPE;

/** \enum SPI_DIRECTION_TYPE
 * \ingroup spi
 *
 * @brief
 * SPI direction enum.
 *
 * This enumeration defines whether this SPI operation is
 * transmission of reception.
 */
enum SPI_DIRECTION_TYPE {
  SPI_TX,
  /**<
   * \ingroup spi
   * Means transmission
   */
  SPI_RX
  /**<
   * \ingroup spi
   * Means reception
   */
};
typedef enum SPI_DIRECTION_TYPE SPI_DIRECTION_TYPE;

/** \enum SPI_MLSB
 * \ingroup spi
 *
 * @brief
 * Specify the MSB or LSB used by the SPI TX/RX operation.
 */
enum SPI_MLSB {
  SPI_LSB = 0,
  /**<
   * \ingroup spi
   * LSB.
   */
  SPI_MSB
  /**<
   * \ingroup spi
   * MSB.
   */
};
typedef enum SPI_MLSB SPI_MLSB;

/** \enum SPI_CPOL
 * \ingroup spi
 *
 * @brief
 * Choose the desired clock polarities supported by the SPI interface.
 */
enum SPI_CPOL {
  SPI_CPOL_0 = 0,
  /**<
   * \ingroup spi
   * SPI clock polarity 0.
   */
  SPI_CPOL_1
  /**<
   * \ingroup spi
   * SPI clock polarity 1.
   */
};
typedef enum SPI_CPOL SPI_CPOL;

/** \enum SPI_CPHA
 * \ingroup spi
 *
 * @brief
 * Choose the desired clock formats supported by the SPI interface.
 */
enum SPI_CPHA {
  SPI_CPHA_0 = 0,
  /**<
   * \ingroup spi
   * SPI clock format 0.
   */
  SPI_CPHA_1
  /**<
   * \ingroup spi
   * SPI clock format 1.
   */
};
typedef enum SPI_CPHA SPI_CPHA;

/** \enum SPI_MODE
 * \ingroup spi
 *
 * @brief
 * Choose the SPI FIFO mode or the SPI DMA mode.
 */
enum SPI_MODE {
  SPI_MODE_FIFO = 0,
  /**<
   * \ingroup spi
   * SPI FIFO mode.
   */
  SPI_MODE_DMA
  /**<
   * \ingroup spi
   * SPI DMA mode.
   */
};
typedef enum SPI_MODE SPI_MODE;

/** \enum SPI_ERROR_CODE
 * \ingroup spi
 *
 * @brief
 * The possible result values of each SPI operations.
 */
enum SPI_ERROR_CODE {
  SPI_NO_ERROR = 0,
  /**<
   * \ingroup spi
   * No errors.
   */
  
  SPI_ERROR_CODE_UNAVAILABLE,
  /**<
   * \ingroup spi
   * If ownership of the SPI interface is owned by another
   * task.
   */
  
  SPI_ERROR_CODE_UNKNOWN_TIME_TYPE,
  /**<
   * \ingroup spi
   * Unknown spi time type.
   */
  
  SPI_ERROR_CODE_UNKNOWN_BIT_STATUS,
  /**<
   * \ingroup spi
   * Unknown spi bit status.
   */
  
  SPI_ERROR_CODE_UNKNOWN_INT_TYPE,
  /**<
   * \ingroup spi
   * Unknown spi interrupt type.
   */
  
  SPI_ERROR_CODE_UNKNOWN_MSB_LSB_TYPE,
  /**<
   * \ingroup spi
   * Unknown spi MSB/LSB.
   */
  
  SPI_ERROR_CODE_UNKNOWN_TRANSFER_DIRECTION,
  /**<
   * \ingroup spi
   * Unknown spi TX/RX.
   */
  
  SPI_ERROR_CODE_UNKNOWN_TRANSFER_TYPE,
  /**<
   * \ingroup spi
   * Unknown spi DMA/FIFO.
   */
  
  SPI_ERROR_CODE_UNKNOWN_CLK_POLARITY,
  /**<
   * \ingroup spi
   * Unknown spi clock polarity.
   */
  
  SPI_ERROR_CODE_UNKNOWN_CLK_FORMAT,
  /**<
   * \ingroup spi
   * Unknown spi clock format.
   */
  
  SPI_ERROR_CODE_ID_PTR_CAN_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In spi_open(), the specified ID address can not
   * be 0.
   */
  
  SPI_ERROR_CODE_FILENAME_PTR_CAN_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In spi_open(), the specified filename address can not
   * be 0.
   */
  
  SPI_ERROR_CODE_DMA_BUF_ADDR_CAT_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In SPI DMA mode, the specified buffer address can not
   * be 0.
   */
  
  SPI_ERROR_CODE_CONFIG_ATTR_CAN_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In spi_config(), the specified spi_attr_t can not
   * be 0.
   */
  
  SPI_ERROR_CODE_PKT_LENGTH_CAN_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In SPI DMA mode, the specified packet length can not be
   * 0.
   */
  
  SPI_ERROR_CODE_PKT_COUNT_CAN_NOT_BE_ZERO,
  /**<
   * \ingroup spi
   * In SPI DMA mode, the specified packet count can not be
   * 0.
   */
  
  SPI_ERROR_CODE_PKT_LENGTH_TOO_LARGE,
  /**<
   * \ingroup spi
   * In SPI DMA mode, the specified packet length is too
   * large to operate. 
   */
  
  SPI_ERROR_CODE_PKT_COUNT_TOO_LARGE,
  /**<
   * \ingroup spi
   * In SPI DMA mode, the specified packet count is too
   * large to operate. 
   */
  
  SPI_ERROR_CODE_ADDR_NOT_4_ALIGN
  /**<
   * \ingroup spi
   * The buffer addresses for TX and RX should be 4-byte
   * alignment. 
   */
};
typedef enum SPI_ERROR_CODE SPI_ERROR_CODE;

enum SPI_BIT_STATUS
{
  SPI_DISABLE,
  SPI_ENABLE
};
typedef enum SPI_BIT_STATUS SPI_BIT_STATUS;

/**
 * \typedef spi_cb_func
 * \ingroup spi
 * The callback function type.
 */
typedef void (*spi_cb_func)(void);

enum SPI_GET_TICK_MODE {
  SPI_NO_GET_TICK_MODE,
  SPI_GET_TICK_MODE_DELAY_1,
  SPI_GET_TICK_MODE_DELAY_2
};
typedef enum SPI_GET_TICK_MODE SPI_GET_TICK_MODE;

struct spi_attr_t {
  kal_uint8 setup_time;
  kal_uint8 hold_time;
  kal_uint8 clk_low;
  kal_uint8 clk_high;
  kal_uint8 idle_time;
  kal_bool enable_pause_int;
  kal_bool enable_finish_int;
  kal_bool enable_pause_mode;
  kal_bool enable_deassert_mode;
  SPI_MLSB tx_mlsb;
  SPI_MLSB rx_mlsb;
  SPI_MODE tx_mode;
  SPI_MODE rx_mode;
  SPI_CPOL clk_polarity;
  SPI_CPHA clk_fmt;
  SPI_GET_TICK_MODE get_tick;
  kal_bool enable_ultra_high;
  kal_uint16 ultra_high_thresh;
  kal_bool enable_gmc_slow_down;
  kal_bool enable_gmc_split_burst;
  kal_uint16 gmc_slow_down_thresh;
};
typedef struct spi_attr_t spi_attr_t;

typedef enum
{ SPI_EVENT_INVALID                         = 0x0,
  SPI_EVENT_TRANSFER_COMPLETE               = 0x1
} SPIEventType;

extern volatile kal_eventgrpid spi_event_id;

/* Export function prototype. */
extern void SPI_LISR(void);

#ifdef DRV_SPI_HAL
extern kal_bool spi_open_old(
#else
extern kal_bool spi_open(
#endif
  kal_int32 * const id,
  char const * const filename,
  kal_uint32 const lineno);

#ifdef DRV_SPI_HAL
extern kal_bool spi_close_old(
#else
extern kal_bool spi_close(
#endif
  kal_int32 const id);

extern kal_bool spi_set_time_interval(
  kal_int32 const id,
  SPI_TIME_TYPE const type,
  kal_uint8 const value);

extern kal_bool spi_set_interrupt(
  kal_int32 const id,
  SPI_INT_TYPE const type,
  SPI_BIT_STATUS const status);

extern kal_bool spi_set_msb(
  kal_int32 const id,
  SPI_DIRECTION_TYPE const type,
  SPI_MLSB const msb);

extern kal_bool spi_select_mode(
  kal_int32 const id,
  SPI_DIRECTION_TYPE const type,
  SPI_MODE const mode);

extern kal_bool spi_set_clock_polarity(
  kal_int32 const id,
  SPI_CPOL const cpol);

extern kal_bool spi_set_clock_format(
  kal_int32 const id,
  SPI_CPHA const cpha);

extern kal_bool spi_set_pause_mode(
  kal_int32 const id,
  kal_bool const status);

extern kal_bool spi_set_deassert_mode(
  kal_int32 const id,
  kal_bool const status);

extern kal_bool spi_set_desired_size(
  kal_int32 const id,
  kal_uint32 const length,
  kal_uint16 const loop);

extern kal_bool spi_set_get_tick_mode(
  kal_int32 const id,
  SPI_GET_TICK_MODE const get_tick);

extern kal_bool spi_slow_down_gmc(
    kal_int32 const id,
    kal_bool const slow_down_enable,
    kal_bool const split_burst_enable,
    kal_uint16 const slow_down_thresh);

extern kal_bool spi_set_ultra_high(
    kal_int32 const id,
    kal_bool const ultra_high_enable,
    kal_uint16 const ultra_high_thresh);

extern kal_bool spi_set_rwaddr(
  kal_int32 const id,
  SPI_DIRECTION_TYPE const type,
  void * const addr);

extern kal_bool spi_set_cb(
  kal_int32 const id,
  SPI_INT_TYPE const type,
  spi_cb_func func,
  spi_cb_func * const old);

extern kal_bool spi_set_endian_reverse(
  kal_int32 const id,
  SPI_DIRECTION_TYPE const type,
  kal_bool const reverse);

extern kal_bool spi_config(
  kal_int32 const id,
  spi_attr_t * const attr);

extern kal_bool spi_clear_fifo(
  kal_int32 const id,
  SPI_DIRECTION_TYPE const direction);

extern kal_bool spi_reset(
  kal_int32 const id);

extern kal_bool spi_resume(
  kal_int32 const id);

extern kal_bool spi_activate(
  kal_int32 const id);

extern kal_bool spi_is_in_pause_mode(void);
extern kal_bool spi_is_busy(void);

extern kal_bool spi_wait_not_busy(
  kal_int32 const id);

extern kal_bool spi_fifo_push(
  kal_int32 const id,
  kal_uint32 const data);

extern kal_bool spi_fifo_pop(
  kal_int32 const id,
  kal_uint32 * const data);

extern void spi_init(void);

extern int rand(void);

#ifdef DRV_SPI_HAL
extern kal_bool spi_get_driving_current(kal_bool* bEnableSlewRate, kal_uint32* current);
extern kal_bool spi_set_driving_current(kal_bool bEnableSlewRate, kal_uint32 current);
extern void spi_select_port(kal_uint32 port);
#endif

#endif

#endif
