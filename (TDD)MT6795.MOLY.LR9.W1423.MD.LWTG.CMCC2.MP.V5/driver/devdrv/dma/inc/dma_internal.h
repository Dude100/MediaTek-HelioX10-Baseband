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
 *    dma_internal.h
 *
 * Project:
 * --------
 *   WR8_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
#ifndef _DMA_INTERNAL_H
#define _DMA_INTERNAL_H

/*******************************include related header files*********************************************/ 
#include "drvpdn.h"
#include "drv_comm.h"
#include "intrCtrl.h"
#include "reg_base.h"
#include "kal_general_types.h"
/*======================================================================================================*/

/************************** define related environment macros *******************************************/ 
#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#define __SECTION__(name)
#define __ZI__ 
#else //#if defined(_MSC_VER) && (_MSC_VER >= 1500)
#define __SECTION__(name) __attribute__ ((section (#name)))
#define __ZI__            __attribute__ ((zero_init))
#endif //#if defined(_MSC_VER) && (_MSC_VER >= 1500)

#if defined (__RVCT__)
#define RETURN_ADDRESS() __return_address()
#elif defined (__GNUC__)
#define RETURN_ADDRESS() __builtin_return_address(0)
#elif defined(_MSC_VER)
#define RETURN_ADDRESS() (0)
#else
#error "no intrinsic API for return_address()"
#endif

#if defined(__GNUC__)

#if defined(__SSDVT_TEST__) //for DCM DVT test, all test code should be put into TCM
#define SSDVT_DMA_INT_ZI_ATTR __attribute__ ((zero_init, section ("INTSRAM_ZI")))
#define SSDVT_DMA_INT_RW_ATTR __attribute__ ((section ("INTSRAM_RW")))
#define SSDVT_DMA_INT_CODE_ATTR __attribute__ ((section ("INTSRAM_ROCODE")))
#else
#define SSDVT_DMA_INT_ZI_ATTR
#define SSDVT_DMA_INT_RW_ATTR
#define SSDVT_DMA_INT_CODE_ATTR
#endif //__SSDVT_TEST__

#else //__GNUC__

#define SSDVT_DMA_INT_ZI_ATTR
#define SSDVT_DMA_INT_RW_ATTR
#define SSDVT_DMA_INT_CODE_ATTR

#endif //__GNUC__
/*======================================================================================================*/

#if defined(__DMA_V3__)
/****************************** MD register definition***************************************************/ 
#define DMA_OFFSET               	(0x0080)

/* DMA Global Registers */
#define DMA_GLBST_INT               (DMA_base+0x0000)
#define DMA_GLOBAL_RESET            (DMA_base+0x0004)
#define DMA_GLBST_RUNNING           (DMA_base+0x0008)
#define DMA_GLOBAL_SLOW_DOWN        (DMA_base+0x000c)

/* DMA Control Registers (n: start from 1) default apply to GDMA */
#define DMA_INT_FLAG(_n)            (DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA_INT_EN(_n)              (DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA_START(_n)               (DMA_base+0x0008+(DMA_OFFSET*(_n)))                                                                                       
#define DMA_RESET(_n)               (DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA_STOP(_n)                (DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA_FLUSH(_n)               (DMA_base+0x0014+(DMA_OFFSET*(_n)))                                                                                       
#define DMA_CON(_n)                 (DMA_base+0x0018+(DMA_OFFSET*(_n))) // VFF DMA [doesn't] use this                                                                   
#define DMA_SRC(_n)                 (DMA_base+0x001c+(DMA_OFFSET*(_n)))                                                                                       
#define DMA_MEM_ADDR(_n)            (DMA_base+0x001c+(DMA_OFFSET*(_n))) // alse for [peripheral DMA TX] memory address & [VFF TX/RX] base address
#define DMA_DST(_n)                 (DMA_base+0x0020+(DMA_OFFSET*(_n))) // alse for [peripheral DMA RX] memory address
#define DMA_LEN1(_n)                (DMA_base+0x0024+(DMA_OFFSET*(_n))) // alse for [peripheral DMA TX] len
#define DMA_VFF_SIZE(_n)            (DMA_base+0x0024+(DMA_OFFSET*(_n))) // alse for [VFF DMA TX/RX] FIFO size                                                  
#define DMA_LEN2(_n)                (DMA_base+0x0028+(DMA_OFFSET*(_n))) // alse for [peripheral DMA RX] len
#define DMA_VFF_THRE(_n)            (DMA_base+0x0028+(DMA_OFFSET*(_n))) // alse for [VFF DMA TX/RX] FIFO threshold
#define DMA_JMP_ADDR(_n)            (DMA_base+0x002c+(DMA_OFFSET*(_n))) // peripheral DMA [doesn't] use this
#define DMA_VFF_WPT(_n)             (DMA_base+0x002c+(DMA_OFFSET*(_n))) // alse for [VFF DMA TX/RX] FIFO write pointer index                                        
#define DMA_BUF_SIZE(_n)            (DMA_base+0x0030+(DMA_OFFSET*(_n))) // peripheral DMA [doesn't] use this
#define DMA_VFF_RPT(_n)             (DMA_base+0x0030+(DMA_OFFSET*(_n))) // alse for [VFF DMA TX/RX] FIFO read pointer index                                         
#define DMA_CONNECT(_n)             (DMA_base+0x0034+(DMA_OFFSET*(_n))) // peripheral [doesn't] use this
#define DMA_W_INT_BUF_SIZE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n))) // alse for [VFF DMA TX] write internal buffer size 								 
#define DMA_FLOW_CTRL_THRE(_n)      (DMA_base+0x0034+(DMA_OFFSET*(_n))) // alse for [VFF DMA RX] flow control threshold 
#define DMA_INT_BUF_SIZE(_n)        (DMA_base+0x0038+(DMA_OFFSET*(_n))) // generic DMA [doesn't] use this
#define DMA_VFF_VALID_SIZE(_n)      (DMA_base+0x003c+(DMA_OFFSET*(_n))) // only for [VFF DMA TX/RX] (VFF valid size)                                       
#define DMA_VFF_LEFT_SIZE(_n)       (DMA_base+0x0040+(DMA_OFFSET*(_n))) // only for [VFF DMA TX/RX] (VFF left size)
#ifdef DMA_SUPPORT_TX_FLUSH_HW_GUARANTEE
#define DMA_VFF_FLUSH_CTRL(_n)      (DMA_base+0x0044+(DMA_OFFSET*(_n))) // only for [VFF DMA TX] (flush control)
#endif
#define DMA_DEBUG(_n)               (DMA_base+0x0050+(DMA_OFFSET*(_n))) 

/* for backward compatible (rename register) */ 
// MD side             
#define DMA_COUNT(_n)               DMA_LEN1(_n)             
#define DMA_WPPT(_n)                DMA_LEN2(_n)
#define DMA_WPTO(_n)                DMA_JMP_ADDR(_n)
#define DMA_PGMADDR(_n)             DMA_MEM_ADDR(_n)
#define DMA_ACKINT(_n)              DMA_INT_FLAG(_n)
#define DMA_RLCT(_n)                DMA_LEN1(_n)             
#define DMA_LIMITER(_n)             DMA_CON(_n)				 	
#define DMA_INTSTA(_n)              DMA_INT_FLAG(_n)
#define DMA_ALTLEN(_n)              DMA_FLOW_CTRL_THRE(_n)
#define DMA_FFSIZE(_n)              DMA_VFF_SIZE(_n)
#define DMA_WRPTR(_n)               DMA_VFF_WPT(_n)
#define DMA_RDPTR(_n)               DMA_VFF_RPT(_n)
#define DMA_FFCNT(_n)               DMA_VFF_VALID_SIZE(_n)

/*=====================================================================================================*/

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
/******************************AP register definition***************************************************/ 
/* DMA Global Registers */
#define DMA2_GLBST_INT              (AP_DMA_base+0x0000)
#define DMA2_GLOBAL_RESET           (AP_DMA_base+0x0004)
#define DMA2_GLBST_RUNNING          (AP_DMA_base+0x0008)
#define DMA2_GLOBAL_SLOW_DOWN       (AP_DMA_base+0x000c)

/* DMA Security Registers */
#define DMA2_GLOBAL_SEC_EN          (AP_DMA_base+0x0010)
#define DMA2_GLOBAL_GSEC_EN         (AP_DMA_base+0x0014)
#define DMA2_GLOBAL_LAT_ADDR        (AP_DMA_base+0x0018)
#define DMA2_GLOBAL_ABORT           (AP_DMA_base+0x001c)

/* DMA Control Registers */ 
#define DMA2_INT_FLAG(_n)           (AP_DMA_base+0x0000+(DMA_OFFSET*(_n)))
#define DMA2_INT_EN(_n)             (AP_DMA_base+0x0004+(DMA_OFFSET*(_n)))
#define DMA2_START(_n)              (AP_DMA_base+0x0008+(DMA_OFFSET*(_n)))
#define DMA2_RESET(_n)              (AP_DMA_base+0x000c+(DMA_OFFSET*(_n)))
#define DMA2_STOP(_n)               (AP_DMA_base+0x0010+(DMA_OFFSET*(_n)))
#define DMA2_FLUSH(_n)              (AP_DMA_base+0x0014+(DMA_OFFSET*(_n)))
#define DMA2_CON(_n)                (AP_DMA_base+0x0018+(DMA_OFFSET*(_n)))
#define DMA2_MEM_ADDR(_n)           (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_SRC(_n)                (AP_DMA_base+0x001c+(DMA_OFFSET*(_n)))
#define DMA2_DST(_n)                (AP_DMA_base+0x0020+(DMA_OFFSET*(_n)))
#define DMA2_LEN1(_n)               (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_VFF_SIZE(_n)           (AP_DMA_base+0x0024+(DMA_OFFSET*(_n)))
#define DMA2_LEN2(_n)               (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_VFF_THRE(_n)           (AP_DMA_base+0x0028+(DMA_OFFSET*(_n)))
#define DMA2_JMP_ADDR(_n)           (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_WPT(_n)            (AP_DMA_base+0x002c+(DMA_OFFSET*(_n)))
#define DMA2_BUF_SIZE(_n)           (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_VFF_RPT(_n)            (AP_DMA_base+0x0030+(DMA_OFFSET*(_n)))
#define DMA2_CONNECT(_n)            (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_W_INT_BUF_SIZE(_n)     (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_FLOW_CTRL_THRE(_n)     (AP_DMA_base+0x0034+(DMA_OFFSET*(_n)))
#define DMA2_INT_BUF_SIZE(_n)       (AP_DMA_base+0x0038+(DMA_OFFSET*(_n)))
#define DMA2_VFF_VALID_SIZE(_n)     (AP_DMA_base+0x003c+(DMA_OFFSET*(_n)))
#define DMA2_VFF_LEFT_SIZE(_n)      (AP_DMA_base+0x0040+(DMA_OFFSET*(_n)))
#define DMA2_DEBUG(_n)              (AP_DMA_base+0x0050+(DMA_OFFSET*(_n)))

/* for backward compatible (rename register) */
// AP side              
#define DMA2_COUNT(_n)              DMA2_LEN1(_n)
#define DMA2_WPPT(_n)               DMA2_LEN2(_n)
#define DMA2_WPTO(_n)               DMA2_JMP_ADDR(_n)
#define DMA2_PGMADDR(_n)            DMA2_MEM_ADDR(_n)
#define DMA2_ACKINT(_n)             DMA2_INT_FLAG(_n)
#define DMA2_RLCT(_n)               DMA2_LEN1(_n)
#define DMA2_LIMITER(_n)            DMA2_CON(_n)
#define DMA2_INTSTA(_n)             DMA2_INT_FLAG(_n)
#define DMA2_ALTLEN(_n)             DMA2_FLOW_CTRL_THRE(_n)
#define DMA2_FFSIZE(_n)             DMA2_VFF_SIZE(_n)
/*=====================================================================================================*/
#endif //__MULTI_CORE_SHARED_DMA__ && __DMA2_SUPPORT__

/**************************DMA control register for GDMA & Periperial DMA*******************************/                       
#define DMA_CON_SIZE_MASK           0x00000003
 
#define DMA_CON_WSIZE_1BYTE         0x00000000
#define DMA_CON_WSIZE_2BYTE         0x00000001
#define DMA_CON_WSIZE_4BYTE         0x00000002
#define DMA_CON_WSIZE_OFFSET        24

#define DMA_CON_RSIZE_1BYTE         0x00000000
#define DMA_CON_RSIZE_2BYTE         0x00000001
#define DMA_CON_RSIZE_4BYTE         0x00000002
#define DMA_CON_RSIZE_OFFSET        28

#define DMA_CON_WPSD                0x00100000  /*0:at source, 1: at destination*/
#define DMA_CON_WPEN                0x00008000  

#define DMA_CON_BURST_SINGLE        0x00000000  /*without burst mode*/
#define DMA_CON_BURST_2BEAT         0x00000001  /*2-beat incrementing burst*/
#define DMA_CON_BURST_3BEAT         0x00000002  /*3-beat incrementing burst*/
#define DMA_CON_BURST_4BEAT         0x00000003  /*4-beat incrementing burst*/
#define DMA_CON_BURST_5BEAT         0x00000004  /*5-beat incrementing burst*/
#define DMA_CON_BURST_6BEAT         0x00000005  /*6-beat incrementing burst*/
#define DMA_CON_BURST_7BEAT         0x00000006  /*7-beat incrementing burst*/
#define DMA_CON_BURST_8BEAT         0x00000007  /*7-beat incrementing burst*/
#define DMA_CON_BURST_OFFSET        16

#define DMA_CON_SLOW_EN             0x00000004
#define DMA_CON_SLOW_OFFSET         5
#define DMA_CON_SLOW_MASK           0x00007FE0
                                  
#define DMA_CON_SFIX                0x00000010
#define DMA_CON_DFIX                0x00000008

/* peripheral DMA only can configure fix pattern & direction in control register */                                       
#define DMA_CON_FIXED_PATTERN       2

/* GDMA can't not configure this bit */
#define DMA_CON_RXCONTRL            1 /*half duplex peripheral DMA direction: RX*/
#define DMA_CON_TXCONTRL            0 /*half duplex peripheral DMA direction: TX*/
/*=====================================================================================================*/

/**********************************bit field of each DMA register***************************************/ 
/* start DMA */
#define DMA_START_BIT               0x00000001
/* warm reset DMA */
#define DMA_W_RST_BIT               0x00000001
/* hard reset DMA */
#define DMA_H_RST_BIT               0x00000002
/* stop DMA */
#define DMA_STOP_BIT                0x00000001
/* pause DMA */
#define DMA_PAUSE_BIT               0x00000002
/* clear interrupt flag */
#define DMA_ACKINT_BIT              0x00000000
/* interrupt flag mask used to know whether finish DMA transaction or not in interrupt mode*/
#define DMA_INTSTA_BIT              0x00000001
#define DMA_INTSTA_BIT1             0x00000002
/* Generic DMA connect register*/                                        
#define DMA_CONNECT_HIF             0x00000001
#define DMA_CONNECT_WRITE           0x00000000
#define DMA_CONNECT_READ            0x00000004
#define DMA_REQ_ACK_RATIO_1_2       0x00000000
#define DMA_REQ_ACK_RATIO_1_1       0x00000008
/* configure VFF DMA TX/RX threshold value by multiplied a ratio */
#define DMA_TX_TRIGGER_LEVEL(n)     ((n)/8)     // trigger level of tx vfifo ==> DMA issues interrupt when left size in VFF is greater than threshold
#define DMA_RX_TRIGGER_LEVEL(n)     ((n)*3/4)   // trigger level of rx vfifo ==> DMA issues interrupt when data in VFF is greater than threshold
/* VFF DMA RX flow control threshold */
#define DMA_VIFOF_ALERT_LENGTH      0x3f        // flow control trigger level ==> DMA issues flow control when left size in VFF is smaller than threshold
/*=====================================================================================================*/

/**********************************************define macro*********************************************/ 
/* valid transfer count mask for GDMA*/ 
#define DMA_COUNT_MAX       		0xFFFFF

#define DMA_GLBSTA_RUN(_n)          (0x00000001 << (_n-1))  /*_n: start from 1*/
#define DMA_GLBSTA_IT(_n)           (0x00000001 << (_n-1))  /*_n: start from 1*/

/* For Multi-Core DMA, DMA VIVFO channel always start from 0 logitically */
#define DMA_VFIFO_CH_S				0            		    // start  of DMA Virtual fifo
#define DMA_VFIFO_CH_E				(DMA_VFF_CH_NUM-1)		// end of DMA Virtual fifo
/*=====================================================================================================*/

/**********************************************Debug structure******************************************/ 
typedef struct
{
    kal_uint32	ret_addr;
	kal_uint32 	access_addr;
	kal_uint32 	count;
	kal_uint8   dma_no;
	kal_uint8	type;
	kal_bool    fixed_pattern;
	kal_bool	fullsize;
	kal_bool	b2w;
	kal_bool 	IsTx;
} DMA_EXTRA_LOG;   
/*=====================================================================================================*/
#endif // __DMA_V3__
#endif /* !_DMA_INTERNAL_H */