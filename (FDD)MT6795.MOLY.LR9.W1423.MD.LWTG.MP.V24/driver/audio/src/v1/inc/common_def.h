/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *
 * Filename:
 * ---------
 * audio_def.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 *  The common definition used in audio module.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __COMMON_DEF_H
#define __COMMON_DEF_H

#include "kal_public_api.h"
#include "reg_base.h"

typedef volatile unsigned short* DPRAMADDR;
typedef volatile unsigned long*  APBADDR32;                             /* APB addr is 32 bits                           */
typedef volatile unsigned short* APBADDR;                               /* APB addr is 32 bits                           */

#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752)
#define IDMA_LONG                (IDMA_base +0x310000)
#define IDMA_SHORT               (IDMA_base +0x310000)
#define IDMA_CM0                 (IDMA_base +0x000000)
#define IDMA_PM0                 (IDMA_base +0x100000)
#define IDMA_DM0                 (IDMA_base +0x200000)
#define IDMA2_LONG                IDMA_LONG
#define IDMA2_SHORT               IDMA_SHORT
#define IDMA2_CM0                 IDMA_CM0
#define IDMA2_PM0                 IDMA_PM0
#define IDMA2_DM0                 IDMA_DM0
#define DSP2_CM_ADDR(page,addr)   DSP_CM_ADDR(page,addr)
#define DSP2_PM_ADDR(page,addr)   DSP_PM_ADDR(page,addr)
#define DSP2_DM_ADDR(page,addr)   DSP_DM_ADDR(page,addr)
#endif

#define IDMA_LONG_ADDR           ((APBADDR32)IDMA_LONG)
#define IDMA_SHORT_ADDR          ((DPRAMADDR)IDMA_SHORT)
#define DSP_CM_ADDR(page,addr)   ((APBADDR32)(IDMA_CM0+((page)<<16)+((addr)<<2)))
#define DSP_PM_ADDR(page,addr)   ((DPRAMADDR)(IDMA_PM0+((page)<<16)+((addr)<<1)))
#define DSP_DM_ADDR(page,addr)   ((DPRAMADDR)(IDMA_DM0+((page)<<16)+((addr)<<1)))

/* -------------------------------------------------------------------------- */
/* Data Type Definition                                                       */
/* -------------------------------------------------------------------------- */
#ifndef uint16
typedef kal_uint16   uint16;
typedef kal_int16    int16;
typedef kal_uint32   uint32;
typedef kal_int32    int32;
typedef kal_uint8    uint8;
typedef kal_int8     int8;
typedef kal_bool     bool;
#define true         (kal_bool)(1==1)
#define false        (kal_bool)(1==0)
#endif

/* -------------------------------------------------------------------------- */
/* DSP Share Registers                                                        */
/* -------------------------------------------------------------------------- */
// #if defined(MT6280) || defined(MT6589)
#define SHARE_DSPCON    ((APBADDR)(SHAREG2_base+0x0000))      /* DSP Control Register                      */
#define SHARE2_M2DI1     ((APBADDR)(SHAREG2_base+0x0004))      /* MCU-to-DSP Interrupt1 Register            */
#define SHARE2_M2DI2     ((APBADDR)(SHAREG2_base+0x0008))      /* MCU-to-DSP Interrupt2 Register            */
// #endif

#define SHARE2_D2MCON    ((APBADDR)(SHARE_base+0x000C))       /* DSP-to-MCU Interrupt Control Register     */
#define SHARE_D2MSTA    ((APBADDR)(SHARE_base+0x0010))       /* DSP-to-MCU Interrupt Status Register      */
#define SHARE_D2MTID    ((APBADDR)(SHARE_base+0x0014))       /* DSP Task Identification Register          */

/* -------------------------------------------------------------------------- */
/* Internal definition of audio module                                        */
/* -------------------------------------------------------------------------- */

// no audio close delay, phase it out 
// #define AUDIO_CLOSE_DELAY 500 //500 ms, unit is 10ms


#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif 


//change mcu and dsp share memory to internal memory, always define after MT6256
// #if defined(MT6280) || defined(MT6589) || defined(MT6572)
// #define _DSP_INTERSHAREMEM_EN_ // only using in audio, so phase it out
#define L1AUDIO_IDMA_ALL_ADDRESS_MODE
// #endif

//#define TDDNC_SUPPORT 1

#define SPE_LOUDSPK_DMNR (defined(MT6582)|| defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752))

// Execute AM_DSP in MED task
#define __AM_DSP_IN_TASK__ ( defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752))

// For 3G
//#define __SP3G_PLATFORM__ 

// For <65nm, dsp coefficients need to reload after sleep. This are always happen after 80, so remove the redundant 
// #define __RELOAD_DSP_COEFF__  ( defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571))
#define __RELOAD_HW_COEFF__  ( defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752))
// #define WB_SPE_SUPPORT        ( defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571)) // default have 

// MODEM Resync enhancement (the sync is implement inside DSP)
// For 2g, resync is default enable after chip MT6582. (like MT6290, MT6592, MT6571.....)
// For MT6572, resync mechamnism can be open by feature option "__L1_GPS_CO_CLOCK_SUPPORT__"
// For MT6280 & MT6589, resync is not support. 
#if (defined(__L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT__)&&defined(__L1_GPS_CO_CLOCK_SUPPORT__)) || defined(MT6582)
#define _MODEM_RESYNC_2G_
#endif

#if defined(MT6290)
#define _2G_DSP_SMR_SUPPORT_
#endif

#if defined(_2G_DSP_SMR_SUPPORT_)// Notice these , _MODEM_RESYNC_2G_ and _2G_DSP_SMR_SUPPORT_, are exclusive.
#undef _MODEM_RESYNC_2G_
#endif

#if defined(__L1_LOCK_AFCDAC_AT_STARTUP_SUPPORT__)
#define _MODEM_RESYNC_3G_
#endif
/* -------------------------------------------------------------------------- */
/* Assertion check                                                            */
/* -------------------------------------------------------------------------- */
#define ASSERT_REBOOT(st)  EXT_ASSERT(st,0,0,0)
#define DSP_DATA_CARD_INTERFACE_SUPPORT  (defined(MT6280))

#if 0 // defined(MT6280) && defined(__SMART_PHONE_MODEM__)
/* under construction !*/
#endif  // 

#ifdef CONNECT_WM8904

#include "dcl.h"
#include "dcl_i2c.h"
#include "dcl_gpio.h"

#define NUM_I2C_WRITE_TAB 24
#define NUM_WRITE_I2C_SINGLE_REG 42
#define LEN_WRITE_I2C_SINGLE_REG 3
#define NUM_READ_I2C_SINGLE_REG NUM_WRITE_I2C_SINGLE_REG
#define LEN_READ_I2C_SINGLE_REG 1
#define LEN_READ_I2C_SINGLE_OUT 2

#define MIC_8K_LONGSYNC_ANALOG_BYPASS           0
#define MIC_8K_LONGSYNC_DIGITAL_LOOPBACK        1
#define MIC_8K_LONGSYNC_PHONE_CALL              2
#define LINEIN_8K_LONGSYNC_ANALOG_BYPASS        3
#define LINEIN_8K_LONGSYNC_DIGITAL_LOOPBACK     4
#define LINEIN_8K_LONGSYNC_PHONE_CALL           5
#define MIC_8K_SHORTSYNC_ANALOG_BYPASS          6 
#define MIC_8K_SHORTSYNC_DIGITAL_LOOPBACK       7 
#define MIC_8K_SHORTSYNC_PHONE_CALL             8 
#define LINEIN_8K_SHORTSYNC_ANALOG_BYPASS       9 
#define LINEIN_8K_SHORTSYNC_DIGITAL_LOOPBACK    10
#define LINEIN_8K_SHORTSYNC_PHONE_CALL          11
#define MIC_16K_LONGSYNC_ANALOG_BYPASS          12
#define MIC_16K_LONGSYNC_DIGITAL_LOOPBACK       13
#define MIC_16K_LONGSYNC_PHONE_CALL             14
#define LINEIN_16K_LONGSYNC_ANALOG_BYPASS       15
#define LINEIN_16K_LONGSYNC_DIGITAL_LOOPBACK    16
#define LINEIN_16K_LONGSYNC_PHONE_CALL          17
#define MIC_16K_SHORTSYNC_ANALOG_BYPASS         18
#define MIC_16K_SHORTSYNC_DIGITAL_LOOPBACK      19
#define MIC_16K_SHORTSYNC_PHONE_CALL            20
#define LINEIN_16K_SHORTSYNC_ANALOG_BYPASS      21
#define LINEIN_16K_SHORTSYNC_DIGITAL_LOOPBACK   22
#define LINEIN_16K_SHORTSYNC_PHONE_CALL         23

void Config_WM8904(kal_int32 tab);

#endif // CONNECT_WM8904

/* -------------------------------------------------------------------------- */
/* Internal Audio Definition                                                  */
/* -------------------------------------------------------------------------- */
#if (defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6290) || defined(MT6592) || defined(MT6571) || defined(MT6595) || defined(MT6752))
// MT6250 is centralize-sleepmode, but MP already, not change
// This compile option should be enabled from MT6280,MT6583,MT6572,etc.
#define __AUDIO_POWERON_RESET_DSP__
#endif


#if defined(__HIF_CCCI_SUPPORT__)
#define __CCCI_OVER_SDIO_SUPPORT__ //currently only MT6290
#endif


#if defined(MT6290)
#define DATA_CARD_DISABLE_INTERNAL 0
#endif

#if defined(MT6290) || defined(MT6595)
#define _SWITCH_AFE_CLK_
#endif

#endif //__COMMON_DEF_H
