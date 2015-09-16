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
 *    drv_features_msdc.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for the msdc driver features
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
 * removed!
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __DRV_FEATURES_MSDC_H__
#define __DRV_FEATURES_MSDC_H__

/**************** MSDC ******************/
#include "drv_features_chip_select.h"

/***** Chip Options *****/
#if defined(DRV_MSDC_MT6235_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_6235_SERIES
    #define MSDC_3538_DMA_STOP_ISSUE
    #define MSDC_CACHED_SUPPORT
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON

#elif defined(DRV_MSDC_MT6236_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_MT6238_SERIES
    #define MSDC_3538_DMA_STOP_ISSUE
    #define DRV_MSDC_CLK_MT6236_SERIES
    #define DRV_MSDC_DATSTA_V2
    #define DRV_MSDC_IOCON_V2
    #define DRV_MSDC_VMC_CTRL
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_2_DLT_FOR_RD_WR
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_DRIVING_36_SERIES
    #define MSDC_CACHED_SUPPORT
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
	#define DRV_MSDC_RETRY_DLT_IN_READ_ERR		/*Try next DLT while read error happened*/
    #define __MSDC_R1B_SUPPORT__
#elif defined(DRV_MSDC_MT6253_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_6235_SERIES
    #define MSDC_3538_DMA_STOP_ISSUE
    #define DRV_MSDC_IOCON_MT6268_SERIES	    /*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_CLK_MT6253_SERIES	        /*104M & 48M*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_ENHANCED_PULL_CTRL			/*BB after MT6253 has enhanced embeded pull high/down resistors*/
    #define DRV_MSDC_2_DLT_FOR_RD_WR
    #define __DRV_MSDC_DRIVING_53_SERIES__      /*53 series's driving for 8mA and 12mA are inversed*/
    //#define MSDC_CACHED_SUPPORT	            /*only support in ARM9*/
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
	#define DRV_MSDC_RETRY_DLT_IN_READ_ERR		/*Try next DLT while read error happened*/

#elif defined(DRV_MSDC_MT6253EL_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_6235_SERIES
    #define MSDC_3538_DMA_STOP_ISSUE
    #define DRV_MSDC_IOCON_MT6268_SERIES	    /*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_CLK_MT6253EL_SERIES		/*104M & 91M*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_ENHANCED_PULL_CTRL			/*BB after MT6253 has enhanced embeded pull high/down resistors*/
    #define DRV_MSDC_2_DLT_FOR_RD_WR
    #define __DRV_MSDC_DRIVING_53_SERIES__      /*53 series's driving for 8mA and 12mA are inversed*/
    #define DRV_MSDC_SDC_V3
    #define MSDC_CACHED_SUPPORT
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
	#define DRV_MSDC_RETRY_DLT_IN_READ_ERR		/*Try next DLT while read error happened*/

#elif defined(DRV_MSDC_MT6251_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    //#define DRV_MSDC_6235_SERIES
    #define MSDC_3538_DMA_STOP_ISSUE
    #define DRV_MSDC_IOCON_MT6268_SERIES	    /*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_CLK_MT6251_SERIES			/*104M & 78M*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    //#define DRV_MSDC_ENHANCED_PULL_CTRL		/*BB after MT6253 has enhanced embeded pull high/down resistors*/
    #define DRV_MSDC_2_DLT_FOR_RD_WR
    //#define __DRV_MSDC_DRIVING_53_SERIES__	/*53 series's driving for 8mA and 12mA are inversed*/
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
	//#define DRV_MSDC_SDC_V3					/*CTOC first introduced in MT6253EL*/
	#define DRV_MSDC_DATSTA_V2					/*MT6255 add 4-bit DATCRCERR*/
	#define DRV_MSDC_SDC_V2						/*MT6255 add MDLEN8, SDIO, CMDFAIL*/
	//#define DRV_MSDC_DMA_V2					/*BB after MT6255/MT6276 will use the updated DMA function*/
	#define DRV_MSDC_RETRY_DLT_IN_READ_ERR		/*Try next DLT while read error happened*/
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON

#elif defined(DRV_MSDC_MT6250_SERIES)

    //#define DRV_MSDC_INSWP_MT6219_SERIES      /*INS and WP*/
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    //#define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_REG_V3
    #define DRV_MSDC_REG_V4
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_IOCON_MT6255_SERIES		/*MT6255 add DMABURST, SAMPON*/
    #define DRV_MSDC_IOCON_MT6276_SERIES		/*MT6276 add FIXDLY, SAMPLEDLY*/
    #define DRV_MSDC_DATSTA_V3					/*MT6276 add 8-bit DATCRCERR*/
    #define DRV_MSDC_SDC_V2
    #define DRV_MSDC_LATCH_MT6276_SERIES		/*BB after MT6276 will use the new latch */
    //#define DRV_MSDC_MMC_BOOTUP_MT6276_SERIES
    //#define DRV_MSDC_DMA_V2						/*BB after MT6255/MT6276 will use the updated DMA function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_VMC_CTRL
    #define __MSDC_R1B_SUPPORT__
    #define MSDC_MMC441_SUPPORT
    #define DRV_MSDC_DRIVING_6255_SERIES
    #define DRV_MSDC_SLIM
    
#elif defined(DRV_MSDC_MT6255_SERIES)

  
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_CLK_MT6256_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_REG_V3
    #define DRV_MSDC_REG_V4
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_IOCON_MT6255_SERIES		/*MT6255 add DMABURST, SAMPON*/
    #define DRV_MSDC_IOCON_MT6276_SERIES		/*MT6276 add FIXDLY, SAMPLEDLY*/
    #define DRV_MSDC_DATSTA_V3					/*MT6276 add 8-bit DATCRCERR*/
    #define DRV_MSDC_SDC_V2
    #define DRV_MSDC_LATCH_MT6276_SERIES		/*BB after MT6276 will use the new latch */
    #define DRV_MSDC_MMC_BOOTUP_MT6276_SERIES
    #define DRV_MSDC_DMA_V2						/*BB after MT6255/MT6276 will use the updated DMA function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_VMC_CTRL
    #define __MSDC_R1B_SUPPORT__
    #define MSDC_MMC441_SUPPORT
    #define DRV_MSDC_DRIVING_6255_SERIES

#elif defined(DRV_MSDC_MT6268_SERIES)

    #define DRV_MSDC_INSWP_MT6219_SERIES
    #define DRV_MSDC_MT6225_SERIES
    #define MSDC_MULTI_BLOCK_WRITE
    //#define DRV_MSDC_MT6238_SERIES			/*second MSDC controller*/
    #define	DRV_MSDC_CORRECT_CMD6
    #define	DRV_MSDC_CLK_MT6268_SERIES		    /*MT6268 has new CLK timing and some modification on IOCON*/
    #define	DRV_MSDC_IOCON_MT6268_SERIES	    /*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define	DRV_MSDC_CLK_SEARCH				    /*we will tune a suitable clk in MT6268*/
    #define DRV_MSDC_2_DLT_FOR_RD_WR
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define MSDC_CACHED_SUPPORT
	#define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
	#define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
	#define DRV_MSDC_RETRY_DLT_IN_READ_ERR		/*Try next DLT while read error happened*/

#elif defined(DRV_MSDC_MT6276_SERIES)

    //#define DRV_MSDC_INSWP_MT6219_SERIES      /*INS and WP*/
    //#define DRV_MSDC_MT6225_SERIES            /*DLT related*/
    #define MSDC_MULTI_BLOCK_WRITE
    //#define DRV_MSDC_MT6238_SERIES            /*MSDC 2*/
    //#define MSDC_3538_DMA_STOP_ISSUE
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_REG_V3
    #define DRV_MSDC_REG_V4
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_IOCON_MT6255_SERIES		/*MT6255 add DMABURST, SAMPON*/
    #define DRV_MSDC_IOCON_MT6276_SERIES		/*MT6276 add FIXDLY, SAMPLEDLY*/
    #define DRV_MSDC_DATSTA_V3					/*MT6276 add 8-bit DATCRCERR*/
    #define DRV_MSDC_SDC_V2
    #define DRV_MSDC_LATCH_MT6276_SERIES		/*BB after MT6276 will use the new latch */
    #define DRV_MSDC_MMC_BOOTUP_MT6276_SERIES
    #define DRV_MSDC_DMA_V2						/*BB after MT6255/MT6276 will use the updated DMA function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define __MSDC_R1B_SUPPORT__
    #define MSDC_MMC441_SUPPORT
#elif defined(DRV_MSDC_MT6256_SERIES)

    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_CLK_MT6256_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_REG_V3
    #define DRV_MSDC_REG_V4
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_IOCON_MT6255_SERIES		/*MT6255 add DMABURST, SAMPON*/
    #define DRV_MSDC_IOCON_MT6276_SERIES		/*MT6276 add FIXDLY, SAMPLEDLY*/
    #define DRV_MSDC_DATSTA_V3					/*MT6276 add 8-bit DATCRCERR*/
    #define DRV_MSDC_SDC_V2
    #define DRV_MSDC_LATCH_MT6276_SERIES		/*BB after MT6276 will use the new latch */
    #define DRV_MSDC_MMC_BOOTUP_MT6276_SERIES
    #define DRV_MSDC_DMA_V2						/*BB after MT6255/MT6276 will use the updated DMA function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_VMC_CTRL
    #define __MSDC_R1B_SUPPORT__
    #define MSDC_MMC441_SUPPORT

#elif defined(DRV_MSDC_MT6280_SERIES)
  
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_CLK_MT6276_SERIES
    #define DRV_MSDC_CLK_SEARCH
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define DRV_MSDC_IOCON_CORRECT_SLEW_RATE	/*we use correct MSDC_IOCON Slew rate setting from MT6516*/
    #define DRV_MSDC_MT6238_SERIES				/*second MSDC controller*/
    #define DRV_MSDC_REG_V3
    #define DRV_MSDC_REG_V4
    #define DRV_MSDC_IOCON_V2					/*MT6236 add MSDC_IOCON1*/
    #define DRV_MSDC_IOCON_MT6268_SERIES		/*MT6268 add DSW, CRCDIS, INTLH, CMDSEL*/
    #define DRV_MSDC_IOCON_MT6255_SERIES		/*MT6255 add DMABURST, SAMPON*/
    #define DRV_MSDC_IOCON_MT6276_SERIES		/*MT6276 add FIXDLY, SAMPLEDLY*/
    #define DRV_MSDC_DATSTA_V3					/*MT6276 add 8-bit DATCRCERR*/
    #define DRV_MSDC_SDC_V2
    #define DRV_MSDC_LATCH_MT6276_SERIES		/*BB after MT6276 will use the new latch */
    #define DRV_MSDC_MMC_BOOTUP_MT6276_SERIES
    #define DRV_MSDC_DMA_V2						/*BB after MT6255/MT6276 will use the updated DMA function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_STOP_TRANS_WITH_TIMEOUT
    #define DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION // fix issue happened in PEGATRON
    #define DRV_MSDC_VMC_CTRL
    #define __MSDC_R1B_SUPPORT__
    #define MSDC_MMC441_SUPPORT
    #define DRV_MSDC_DRIVING_6255_SERIES
    #define DRV_MSDC_DEBUG_REGISTER
    #define CLKSW_CKSEL1             (MIX_ABB_base+0x0064)
    #define CLKSW_FDIV1              (MIX_ABB_base+0x0074)
    #define CLKSW_FDIV6              (MIX_ABB_base+0x0088)

#elif defined(DRV_MSDC_MT6290_SERIES)
    
    #define MSDC_MULTI_BLOCK_WRITE
    #define DRV_MSDC_CORRECT_CMD6				/*BB after MT6253 will use the updated CMD6 function*/
    #define MSDC_CACHED_SUPPORT
    #define DRV_MSDC_CLK_SEARCH
    #define MSDC_MMC441_SUPPORT
    //#define _MSDC_INTERNAL_CD_INT_PIN_      //use the card detect inside MSDC IP
    //#define MSDC_HOTPLUG_EN
    //#define MSDC_WR_PROT_EN
    #define MSDC_CONFIG_SD30_SUPPORT        //support sd 3.0
    //#define MSDC_DMA_CHKSUM_EN
    //#define MSDC_SCAT_BUF_FLUSH
    #define MSDC_GPD_BD_BUF_CACHED
    #define MSDC_QMU_ENABLE
        
#endif

/***** Coding Options *****/
#if defined(__MSDC_DUAL_CARD_SWITCH__)
#define DRV_MSDC_DUAL_TCARD_BY_SWITCH
#endif

#if defined(DRV_MSDC_LSD)
   #define DRV_LSD
#endif

#ifdef DRV_MSDC_INSWP_MT6219_SERIES
   #ifdef MT6225
   #define DRV_MSDC_INSWP_GPIO_MT6225_SERIES
   #endif
#endif


/*MSDC first CLK*/
#if defined(DRV_MSDC_CLK_MT6276_SERIES)
#define MSDC_CLOCK		98300	// (kHz)
#define MSDC_OP_CLOCK	15300
#define MSDC_30M		30700
#elif defined(DRV_MSDC_CLK_MT6256_SERIES)
#define MSDC_CLOCK		94500	// (kHz)
#define MSDC_OP_CLOCK	15300
#define MSDC_30M		32500
#elif defined(DRV_MSDC_CLK_MT6268_SERIES)
#define MSDC_CLOCK		122000	// (kHz)
#define MSDC_OP_CLOCK	15250
#define MSDC_30M		30500
#elif defined(DRV_MSDC_CLK_MT6236_SERIES) || defined(DRV_MSDC_CLK_MT6253EL_SERIES) || defined(DRV_MSDC_CLK_MT6255_SERIES)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000
#define MSDC_30M		26000
#elif defined(DRV_MSDC_CLK_MT6516_SERIES)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000
#define MSDC_30M		26000
#elif defined(DRV_MSDC_CLK_MT6253_SERIES)
#define MSDC_CLOCK		52000	// (kHz)
#define MSDC_OP_CLOCK	13000
#define MSDC_30M		26000
#elif defined(DRV_MSDC_CLK_MT6251_SERIES)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000
#define MSDC_30M		26000
/*definitions hereafter are for old chips, like 27, 28, 29, 25, 35, 38*/
#elif defined(MCU_26M)
#define MSDC_CLOCK		26000	// (kHz)
#define MSDC_OP_CLOCK	13000
#elif defined(MCU_52M)
#define MSDC_CLOCK		52000	// (kHz)
#define MSDC_OP_CLOCK	13000
#elif defined(MCU_104M)
#define MSDC_CLOCK		104000	// (kHz)
#define MSDC_OP_CLOCK	13000
#elif defined(MCU_208M)
#define MSDC_CLOCK		208000	// (kHz)
#define MSDC_OP_CLOCK	13000
#elif defined(DRV_MSDC_CLK_MT6268_SERIES)
#define MSDC_CLOCK		122000	// (kHz)
#define MSDC_OP_CLOCK	15250
#define MSDC_30M		30500
#endif


/*MSDC 2nd CLK source*/
#ifdef DRV_MSDC_CLK_MT6516_SERIES
#define MSDC_2ND_CLK_MCPLL
#endif

#if defined(DRV_MSDC_CLK_MT6268_SERIES) ||defined(DRV_MSDC_CLK_MT6516_SERIES) || defined(DRV_MSDC_CLK_MT6253_SERIES) || defined(DRV_MSDC_CLK_MT6253EL_SERIES)
#define	DRV_MSDC_CLK_ALTER_91M
#elif defined(DRV_MSDC_CLK_MT6236_SERIES) || defined(DRV_MSDC_CLK_MT6255_SERIES)
#define DRV_MSDC_CLK_ALTER_96M
#else
/*MSDC before MT6268 use USB CLK as second CLK source*/
#define	DRV_MSDC_CLK_USE_USB_48M
#endif

#if defined(DRV_MSDC_CLK_ALTER_91M)
#define MSDC_CLOCK_USB		91000		// (kHz)
#define MSDC_SD_OP_CLOCK	22750
#define MSDC_45M			45500
/*following is for MT6236*/
#elif defined(DRV_MSDC_CLK_ALTER_96M)
#define MSDC_CLOCK_USB		96000		// (kHz)
#define MSDC_SD_OP_CLOCK	24000
#elif defined(DRV_MSDC_CLK_MT6251_SERIES)
#define MSDC_CLOCK_USB		78000		// (kHz)
#define MSDC_SD_OP_CLOCK	19500
/*definitions hereafter are for old chips, like 27, 28, 29, 25, 35, 38*/
#elif defined(DRV_MSDC_CLK_USE_USB_48M)
#define MSDC_CLOCK_USB		48000		// (kHz)
#define MSDC_SD_OP_CLOCK	24000
#endif

#ifdef __MSDC2_MSP_DVT__
#define MSDC_TEST_MSDC2_FROM_MSDC1_CODE	//this option is used on msdc.c to tell that we want to test msdc2 on msdc code
#endif

#ifdef MSDC2_SDIO_TEST 
    #define MSDC_TEST_MSDC2_FROM_MSDC1_CODE
    #define __MSDC_NOT_SUPPORT_HOT_PLUG__
    #define __MSDC_NO_WRITE_PROTECT__
#endif
/*we may enable __DRV_MSDC_CLK_SEARCH__ in makefile of some projects*/
#ifdef __DRV_MSDC_CLK_SEARCH__
#ifndef DRV_MSDC_CLK_SEARCH
#define DRV_MSDC_CLK_SEARCH
#endif
#endif

#ifdef	__CMMB_CAS_FULL_CARD_SUPPORT__
//when CAS full card support, there is critical throughput requirement, we hae to enable MMC40
#ifndef	MSDC_MMC40_SUPPORT
#define	MSDC_MMC40_SUPPORT
#endif
//the CAS full card is a MMC4.1 card, but it won't reply SEND_EXT_CSD command, we have to send it to 4-bit mode without this command
#define	MSDC_SPECIAL_MMC_41_CARD
#endif

#if defined(DRV_MSDC_CLK_MT6253_SERIES) || defined(DRV_MSDC_CLK_MT6236_SERIES) || defined(DRV_MSDC_CLK_MT6253EL_SERIES) || defined(DRV_MSDC_CLK_MT6276_SERIES) || defined(DRV_MSDC_CLK_MT6255_SERIES)|| defined(DRV_MSDC_CLK_MT6256_SERIES)
#define DRV_MSDC_NOT_USE_2ND_CLK
#endif

#if (defined( __CMMB_CAS_FULL_CARD_SUPPORT__) ||defined(DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH))
#define DRV_MSDC_HW_CONTENTION
#endif

#if defined( DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH) || defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
#define DRV_MSDC_SHARE_BY_SWITCH
#endif

#ifndef DRV_LSD
//#if !defined(MT6255) && !defined(MT6256) && !defined(MT6276) && !defined(MT6573)
#define __DRV_MSDC_FAST_FORMAT__
//#endif
#endif

#ifdef __INNOFIDEI_IF202__
/*
	This is wrong, since INNOFIDEI may uses SPI, we have to discuss a option to indicate driver that uses SDIO for INNOFIDEI.
	Currently, we just disable this.
*/
//#define __MSDC_SD_SDIO__
#endif

#if defined(MT6268) || defined(MT6250) || defined(MT6280)
#define DRV_MSDC_4_BYTE_BURST
#endif

#ifdef __DYNAMIC_SWITCH_CACHEABILITY__
#define MSDC_CACHED_SUPPORT
#else
	#ifdef MSDC_CACHED_SUPPORT
	#undef MSDC_CACHED_SUPPORT
	#endif
#endif

#if defined(__WRITE_THROUGH_CACHEABLE__)
/*storage cached transfer support*/
#define MSDC_CACHED_SUPPORT_WRITE_THROUGH_SERIES
//#define SIM_CACHED_SUPPORT_WRITE_THROUGH_SERIES
#endif

#if defined(MT6236) || defined(MT6236B)
#define MSDC_DEFECT_WRITE_CRCERR
#endif

//
// Add a reset MSDC compile option to prevent FIFO is not clear entirely.
// This is a hardware bug on MT6276 series/MT6573 and will cause a random data error.
//	
#if defined(MT6276) || defined(MT6276M) || defined(MT6573)
#define MSDC_SYNC_CLEAR
#endif

#if !defined(MT6253L) && !defined(MT6253E) && !defined(MT6252) && !defined(MT6252H) && !defined(MT6251) && !defined(MT6250)
#define MSDC_SD_BITS4_BUS		// using 4bits bus width for SD card which has this feature
#define MMC40_USE_4BIT_BUS
#elif defined(__MSDC_4BIT_BUSWIDTH__)
#define MSDC_SD_BITS4_BUS		// using 4bits bus width for SD card which has this feature
#define MMC40_USE_4BIT_BUS
#endif

//#ifdef __MEUT__
#define DCL_MSDC_INTERFACE
#if defined(MT6251_S00)||defined(MT6516)||!defined(__MSDC_SD_MMC__)
#define DRV_MSDC_OFF
#endif
//#endif

#ifdef IC_BURNIN_TEST
/*remove following line so that the OLT load of all new chips will include the option*/
//#if defined(MT6268_EVB) || defined(MT6253_EVB) || defined(MT6236) || defined(MT6236B) || defined(MT6253D_EVB)
#ifndef MT6573
#define DRV_MSDC_BT
#endif//MT6573
//#endif//defined(MT6268_EVB) || defined(MT6253_EVB) || defined(MT6236) || defined(MT6236B) || defined(MT6253D_EVB)
#endif

#endif /*End __DRV_FEATURES_MSDC_H__*/
