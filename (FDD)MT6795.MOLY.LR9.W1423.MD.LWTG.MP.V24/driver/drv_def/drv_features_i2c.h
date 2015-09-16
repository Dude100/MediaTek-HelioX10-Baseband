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
 *    drv_features_i2c.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for I2C driver feature options.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_I2C_H__
#define __DRV_FEATURES_I2C_H__

#include "drv_features_chip_select.h"

/**************** I2C ******************/
#if defined(DRV_I2C_6268A_SERIES)
  #define DRV_I2C_25_SERIES	    // MT6268A I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED   //Enable I2C DMA Mode
  #define DRV_I2C_USE_DMA_V1_API
  #define DRV_I2C_DUAL          // MT6268A support 2 I2C modules
                                // The I2C DUAL module is used communicate PMIC
  #define DRV_I2C_DUAL_NO_DMA   // Indicate the I2C DUAL module does NOT support DMA property
  // I2C module clock is 15.36 MHz
  #define DRV_I2C_CLOCK_RATE_15_360_MHZ
  #define DRV_I2C_FIFO_DEPTH      8
  #define DRV_I2C_DMA_DEPTH  	    255	   ///The limitation is from I2C spec (transfer len is 8 bits)
  #define DRV_I2C_DMA_DEPTH_AUX  	31	   ///TRANSFER_LEN_AUX[4:0] indicate the number of DATA transferred following the direction change
#elif defined(DRV_I2C_6236_SERIES)
  #define DRV_I2C_25_SERIES     // MT6236 I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED  //Enable I2C DMA Mode
  #define DRV_I2C_USE_DMA_V1_API

  #define DRV_I2C_PDN_NAME_I2C

  #define DRV_I2C_FIFO_DEPTH        8
  #define DRV_I2C_DMA_DEPTH         255    ///The limitation is from I2C spec (transfer len is 8 bits)
  #define DRV_I2C_DMA_DEPTH_AUX     31     ///TRANSFER_LEN_AUX[4:0] indicate the number of DATA transferred following the direction change
#elif defined(DRV_I2C_6225_BASIC_SERIES)
  #define DRV_I2C_25_SERIES	    // I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED  //Enable I2C DMA Mode
  #define DRV_I2C_USE_DMA_V1_API
	#if defined(MT6253E) || defined(MT6253L) || defined(MT6252H) || defined(MT6252)
	#define DRV_I2C_DMA_NOT_SUPPORT_READ_AFTER_WRITE
	#endif
	
  #define DRV_I2C_FIFO_DEPTH        8
  #define DRV_I2C_DMA_DEPTH         255    ///The limitation is from I2C spec (transfer len is 8 bits)
  #define DRV_I2C_DMA_DEPTH_AUX     31     ///TRANSFER_LEN_AUX[4:0] indicate the number of DATA transferred following the direction change
#elif defined(DRV_I2C_6276_SERIES)
  #define DRV_I2C_25_SERIES	    // I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED  //Enable I2C DMA Mode
  #define DRV_I2C_USE_DMA_V2_API    // From 6276, I2C driver use DMA V2 API, not directly configure DMA register
  // DMA module does NOT have 2 channels for I2C, can NOT perform "write and read" with DMA enabled
  #if defined(MT6276_S00)
  #define DRV_I2C_DMA_NOT_SUPPORT_READ_AFTER_WRITE
  #endif
  // I2C module clock is 15.36 MHz
  #define DRV_I2C_CLOCK_RATE_15_360_MHZ

  #define DRV_I2C_PDN_NAME_I2C

  #define DRV_I2C_FIFO_DEPTH        8
  #define DRV_I2C_DMA_DEPTH         255    ///The limitation is from I2C spec (transfer len is 8 bits)
  #define DRV_I2C_DMA_DEPTH_AUX     31     ///TRANSFER_LEN_AUX[4:0] indicate the number of DATA transferred following the direction change
  #define DRV_I2C_BATCH_TRANSACTION_SUPPORT
#elif defined(DRV_I2C_6256_SERIES)
  #define DRV_I2C_25_SERIES	    // I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED
  #define DRV_I2C_USE_DMA_V2_API
  #define DRV_I2C_MAX_65535_TRANSFER_LENGTH		///since MT6256E2, the max I2C transfer length is extened to 65535 bytes
  #define DRV_I2C_PDN_NAME_I2C
  #define DRV_I2C_FIFO_DEPTH        8
  #define DRV_I2C_DMA_DEPTH         65535    
  #define DRV_I2C_DMA_DEPTH_AUX     65535   
 #elif defined(DRV_I2C_6280_SERIES)
  #define DRV_I2C_25_SERIES	    // I2C module is based on DRV_I2C_25_SERIES
  #define DRV_I2C_DMA_ENABLED
  #define DRV_I2C_USE_DMA_V2_API
  #define DRV_I2C_MAX_65535_TRANSFER_LENGTH		///since MT6256E2, the max I2C transfer length is extened to 65535 bytes
  #define DRV_I2C_PDN_NAME_I2C
  #define DRV_I2C_FIFO_DEPTH        8
  #define DRV_I2C_DMA_DEPTH         65535    
  #define DRV_I2C_DMA_DEPTH_AUX     65535 
  #define DRV_I2C_NO_CAMERA     

#elif defined(DRV_I2C_6575_SERIES)
    #define DRV_I2C_OFF		  // MT6575 I2C driver is disabled on MD side
    #define DRV_I2C_DUAL    // MT6575 support 2 I2C modules
#else
#define DRV_I2C_OFF 	  // 

#endif // #if defined(DRV_I2C_6268A_SERIES)

#ifdef LOW_COST_SUPPORT
  ///Bin: for SLIM projects, DMA can be disabled
  #undef DRV_I2C_DMA_ENABLED  //Enable I2C DMA Mode
#endif

//#ifdef __MEUT__
#if (!defined(DRV_I2C_OFF) && defined(DRV_I2C_25_SERIES))
#define DCL_I2C_INTERFACE
#endif
//#endif
#define HAL_I2C_ENABLE_EMPTY_NON_HAL_INTERFACE

#endif   /*End __DRV_FEATURES_I2C_H__*/
