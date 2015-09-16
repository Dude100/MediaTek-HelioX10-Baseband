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
 *   Msdc_def.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file of MSDC driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
#ifndef MSDC_DEF_H
#define MSDC_DEF_H

//RHR ADD
#include "kal_general_types.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//MSBB remove #include "kal_non_specific_general_types.h"
*/
//RHR
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "drv_features.h"
#include "drvpdn.h"
#include "msdc_api.h"
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "dcl.h"
#include "cache_sw.h"
#include "cache_sw_int.h"
#include "sync_data.h"
#include "qmu_bm.h"
#include "kal_trace.h"

#ifdef CHIP_VER
#undef CHIP_VER
#endif

/* Chip version for FPGA */
#define CHIP_VER        1
/* Chip version for E1 */
//#define CHIP_VER        1
/* Chip version for E2 */
//#define CHIP_VER        2

//#define MSDC_DEBUG_PRINT
#define  MSDC_ADRS BASE_ADDR_MSDC_0
#define MSDC_MUST_RECORD_PLUGOUT
#if defined(__MSDC_SD_MMC__)
#define SD_MMC_HIGH_DENSITY_SUPPORT
//#define SD30_SUPPORT
#endif

#ifdef	MSDC_CACHED_SUPPORT
#define	MSDC_UNCACHED_BUF_SIZE	4096
#define	MSDC_UNCACHED_TRASNFER_SIZE	(MSDC_UNCACHED_BUF_SIZE/4)
extern	kal_uint32	msdc_uncachedBuf[];
#endif

/* 
 * On normal load, use DHL as log output
 * On ATEST load, use dbgprint as log output
 */
#if !defined (ATEST_DRV_MSDC) && !defined (ATEST_ENABLE)
#define MSDC_DHL_LOG
#endif

#define DRV_MSDC_DEBUGGING_SLA


extern void dbg_print(char *fmt,...);
#if defined (__MTK_TARGET__)
#if defined (MSDC_DHL_LOG)
#define MSDC_PRINTF(_fmt, _args ...)				dhl_print(TRACE_INFO, DHL_USER_FLAG_NONE, MOD_SYSTEM, _fmt, ## _args);
#else
#define MSDC_PRINTF(_fmt, _args ...)				dbg_print(_fmt, ## _args)
#endif
#endif

/* Refer to RFC5424 */
#define K_EMERG		(0)	// Emergency: system is unusable
#define K_ALET		(1)	// Alert: action must be taken immediately
#define K_CRIT		(2)	// Critical: critical conditions
#define K_ERR		(3)	// Error: error conditions
#define K_WARNIN	(4)	// Warning: warning conditions
#define K_NOTICE	(5)	// Notice: normal but significant conditions
#define K_INFO		(6)	// Informational: informational messages
#define K_DEBUG		(7)	// Debug: debug-level messages

#define MSDC_DebugLevel				K_WARNIN // K_ERR / K_WARNIN / K_NOTICE
#define MSDC_DebugDisable			(0)

#define MSDC_GetDebugLevel()        MSDC_DebugLevel
#define MSDC_SetDebugLevel(_level)	(MSDC_DebugLevel = (_level))
#define MSDC_EnableDebug()			(MSDC_DebugDisable = 0)
#define MSDC_DisableDebug()			(MSDC_DebugDisable = 1)
#define _dbg_level(_level)			((!MSDC_DebugDisable) && (((_level) >= 0) && (MSDC_GetDebugLevel() >= (_level))))

#if defined(__MTK_TARGET__)
#define MSDC_PRINT(_level, _fmt, _args ...)		\
	do											\
	{											\
		if (_dbg_level(_level))					\
		{										\
			MSDC_PRINTF(_fmt, ## _args);		\
		}										\
	} while (0)

#define MSDC_EMERG(_fmt, _args ...)     MSDC_PRINT(K_EMERG, "[EMERGENCY]" _fmt, ## _args)
#define MSDC_ALET(_fmt, _args ...)      MSDC_PRINT(K_ALET, "[ALTER]" _fmt, ## _args)
#define MSDC_CRIT(_fmt, _args ...)      MSDC_PRINT(K_CRIT, _fmt, ## _args)
#define MSDC_ERR(_fmt, _args ...)       MSDC_PRINT(K_ERR, "[ERROR]" _fmt, ## _args)
#define MSDC_WARNIN(_fmt, _args ...)    MSDC_PRINT(K_WARNIN, "[WARNING]" _fmt, ## _args)
#define MSDC_NOTICE(_fmt, _args ...)    MSDC_PRINT(K_NOTICE, "[NOTICE]" _fmt, ## _args)
#define MSDC_INFO(_fmt, _args ...)      MSDC_PRINT(K_INFO, "[INFO]" _fmt, ## _args)
#define MSDC_DEBUG(_fmt, _args ...)     MSDC_PRINT(K_DEBUG, "[DEBUG]" _fmt, ## _args)
#else
#define MSDC_EMERG dbg_print
#define MSDC_ALET  dbg_print	
#define MSDC_CRIT  dbg_print		
#define MSDC_ERR   dbg_print		
#define MSDC_WARNIN dbg_print	
#define MSDC_NOTICE dbg_print	
#define MSDC_INFO dbg_print		
#define MSDC_DEBUG dbg_print	
#endif

#ifdef MSDC_DebugLevel
#undef MSDC_DebugLevel
#endif

extern kal_uint32 MSDC_DebugLevel;

#if !defined(_MSDC_INTERNAL_CD_INT_PIN_)
#define MSDC_INS_GPIO           25//GPIO_PIN25
#define MSDC_WP_GPIO            26//GPIO_PIN26
#endif

struct msdc_io_setting {
    unsigned char  io_drv_33;
    unsigned char  io_drv_18;

    unsigned char  rdsel;
    unsigned char  tdsel;
    unsigned char  smten;
    unsigned char  slew;

    unsigned char  is_res_10k;
};

struct msdc_cust {
    unsigned char  clk_src;           /* host clock source             */
    unsigned char  cmd_edge;          /* command latch edge            */
    unsigned char  rdata_edge;        /* read data latch edge         */
    unsigned char  wdata_edge;        /* write data latch edge        */
    
    struct msdc_io_setting io_clk;
    struct msdc_io_setting io_cmd;
    struct msdc_io_setting io_dat;
    
    unsigned char  data_pins;         /* data pins on 1.8V             */
    unsigned int   data_offset;       /* data address offset           */    
    unsigned int   flags;             /* hardware capability flags     */
};


/*MSDC DBG print definitions*/
#define MSDC_DBG_ARRAY_SIZE	(1024)
#define MSDC_DBG_ARRAY_MASK	(MSDC_DBG_ARRAY_SIZE-1)
#define MMC_HIGH_DESITY_CHECK_BIT	(0x40000000)
#define MMC_HIGH_DESITY_CHECK_MSK	(0x60000000)


/*----------------------------------------*/
/* register address*/
/*----------------------------------------*/
/*common register*/
#define MSDC_CFG 		(MSDC_ADRS + 0)
#define MSDC_IOCON 		(MSDC_ADRS + 0x4)
#define MSDC_PS			(MSDC_ADRS + 0x8)
#define MSDC_INT 		(MSDC_ADRS + 0xc)
#define MSDC_INTEN 		(MSDC_ADRS + 0x10)
#define MSDC_FIFOCS		(MSDC_ADRS + 0x14)
#define MSDC_TXDATA 	(MSDC_ADRS + 0x18)
#define MSDC_RXDATA 	(MSDC_ADRS + 0x1c)

/*dma register*/
#define MSDC_DMA_SA	(MSDC_ADRS + 0x90)
#define MSDC_DMA_CA	(MSDC_ADRS + 0x94)
#define MSDC_DMA_CTL	(MSDC_ADRS + 0x98)
#define MSDC_DMA_CFG	(MSDC_ADRS + 0x9c)
#define MSDC_DMA_LENGTH	(MSDC_ADRS + 0xa8)
/*pad control register*/
#define MSDC_PAD_CTL0	(MSDC_ADRS + 0xe0)
#define MSDC_PAD_CTL1	(MSDC_ADRS + 0xe4)
#define MSDC_PAD_CTL2	(MSDC_ADRS + 0xe8)
/*data read delay*/
#define MSDC_DAT_RDDLY0	(MSDC_ADRS + 0xf0)
#define MSDC_DAT_RDDLY1	(MSDC_ADRS + 0xf4)
/*debug register*/
#define MSDC_DBG_SEL		(MSDC_ADRS + 0xa0)
#define MSDC_DBG_OUT		(MSDC_ADRS + 0xa4)
/*patch bit register*/
#define MSDC_PATCH_BIT0	(MSDC_ADRS + 0xb0)
#define MSDC_PATCH_BIT1	(MSDC_ADRS + 0xb4)
/*misc register*/
#define MSDC_PATCH_BIT 		(MSDC_ADRS + 0xb0)
#define MSDC_PAD_TUNE		(MSDC_ADRS + 0xec)
#define MSDC_HW_DBG		(MSDC_ADRS + 0xf8)
#define MSDC_VERSION		(MSDC_ADRS + 0x100)
#define MSDC_ECO_VER		(MSDC_ADRS + 0x104)

/*--------------------------------------*/
/*register mask */
/*--------------------------------------*/
/*MSDC CFG Mask*/
#define MSDC_CFG_MODE				(0x1 << 0 )		/*RW*/
#define MSDC_CFG_CKPDN				(0x1 << 1 )		/*RW*/
#define MSDC_CFG_RST				(0x1 << 2 )		/*RW*/
#define MSDC_CFG_PIO				(0x1 << 3 )		/*RW*/
#define MSDC_CFG_CKDRV_EN			(0x1 << 4 )		/*RW*/
#define MSDC_CFG_BV18SDT			(0x1 << 5 )		/*RW*/
#define MSDC_CFG_BV18PSS			(0x1 << 6 )		/*RW*/
#define MSDC_CFG_CKSTB				(0x1 << 7 )		/*RW*/
#define MSDC_CFG_CKDIV				(0xff <<8 )		/*RW*/
#define MSDC_CFG_CKMOD				(0x3 << 16)		/*RW*/
/*MSDC IOCON Mask*/
#define MSDC_IOCON_SDR104CKS    (0x1  << 0)     /* RW */
#define MSDC_IOCON_RSPL         (0x1  << 1)     /* RW */
#define MSDC_IOCON_RDSPL        (0x1  << 2)     /* RW */
#define MSDC_IOCON_DDLSEL       (0x1  << 3)     /* RW */
#define MSDC_IOCON_DDR50CKD     (0x1  << 4)     /* RW */
#define MSDC_IOCON_RDSPLSEL     (0x1  << 5)     /* RW */
#define MSDC_IOCON_WDSPL        (0x1  << 8)     /* RW */
#define MSDC_IOCON_WDSPLSEL     (0x1  << 9)     /* RW */
#define MSDC_IOCON_WD0SPL       (0x1  << 10)    /* RW */
#define MSDC_IOCON_WD1SPL       (0x1  << 11)    /* RW */
#define MSDC_IOCON_WD2SPL       (0x1  << 12)    /* RW */
#define MSDC_IOCON_WD3SPL       (0x1  << 13)    /* RW */
#define MSDC_IOCON_RD0SPL       (0x1  << 16)    /* RW */
#define MSDC_IOCON_RD1SPL       (0x1  << 17)    /* RW */
#define MSDC_IOCON_RD2SPL       (0x1  << 18)    /* RW */
#define MSDC_IOCON_RD3SPL       (0x1  << 19)    /* RW */
#define MSDC_IOCON_RD4SPL       (0x1  << 20)    /* RW */
#define MSDC_IOCON_RD5SPL       (0x1  << 21)    /* RW */
#define MSDC_IOCON_RD6SPL       (0x1  << 22)    /* RW */
#define MSDC_IOCON_RD7SPL       (0x1  << 23)    /* RW */

/*MSDC PS Mask*/
#define MSDC_PS_CDEN				(0x1 <<0)		/*RW*/
#define MSDC_PS_CDSTS				(0x1 << 1) 		/*R*/
#define MSDC_PS_CDDEBOUNCE		(0xf << 12) 		/*RW*/
#define MSDC_PS_DATA				(0xff << 16)		 /*R*/
#define MSDC_PS_CMD				(0x1 << 24)		/*R*/
#define MSDC_PS_WP					(0x1UL << 31)	/*R*/

/*MSDC INT Mask*/
#define MSDC_INT_MMCIRQ 			(0x1 << 0)      /*W1C*/
#define MSDC_INT_CDSC 				(0x1 << 1)      /*W1C*/
#define MSDC_INT_ACMDRDY 			(0x1 << 3)      /*W1C*/
#define MSDC_INT_ACMDTMO			(0x1 << 4)      /*W1C*/
#define MSDC_INT_ACMDCRCERR		    (0x1 << 5)      /*W1C*/
#define MSDC_INT_DMAQ_EMPTY		    (0x1 << 6)      /*W1C*/
#define MSDC_INT_SDIOIRQ 			(0x1 << 7)      /*W1C*/
#define MSDC_INT_CMDRDY			    (0x1 << 8)      /*W1C*/
#define MSDC_INT_CMDTMO 			(0x1 << 9)      /*W1C*/
#define MSDC_INT_RSPCRCERR 		    (0x1 << 10)     /*W1C*/
#define MSDC_INT_CSTA				(0x1 << 11)     /*R*/
#define MSDC_INT_XFER_COMPL 		(0x1 << 12)     /*W1C*/
#define MSDC_INT_DXFER_DONE		    (0x1 << 13)     /*W1C*/
#define MSDC_INT_DATTMO 			(0x1 << 14)     /*W1C*/
#define MSDC_INT_DATCRCERR 		    (0x1 << 15)     /*W1C*/
#define MSDC_INT_ACMD19_DONE 		(0x1 << 16)     /*W1C*/
#define MSDC_INT_BD_CS_ERR          (0x1 << 17)     /*W1C*/
#define MSDC_INT_GPD_CS_ERR         (0x1 << 18)     /*W1C*/
#define MSDC_CMD_INTS				(MSDC_INT_CMDRDY|MSDC_INT_CMDTMO|MSDC_INT_RSPCRCERR)
#define MSDC_ACMD_INTS				(MSDC_INT_ACMDRDY|MSDC_INT_ACMDCRCERR|MSDC_INT_ACMDTMO)
#define MSDC_DAT_INTS				(MSDC_INT_DATTMO|MSDC_INT_DATCRCERR|MSDC_INT_XFER_COMPL)


/*MSDC INTEN Mask*/
#define MSDC_INTEN_MMCIRQ 			(0x1 << 0)		 /*W1C*/
#define MSDC_INTEN_CDSC 			(0x1 << 1)		 /*W1C*/
#define MSDC_INTEN_ACMDRDY 		    (0x1 << 3)		 /*W1C*/
#define MSDC_INTEN_ACMDTMO		    (0x1 << 4)		 /*W1C*/
#define MSDC_INTEN_ACMDCRCERR 	    (0x1 << 5)		 /*W1C*/
#define MSDC_INTEN_DMAQ_EMPTY 	    (0x1 << 6)		 /*W1C*/
#define MSDC_INTEN_SDIOIRQ 		    (0x1 << 7)		 /*W1C*/
#define MSDC_INTEN_CMDRDY 			(0x1 << 8)		 /*W1C*/	
#define MSDC_INTEN_CMDTMO 		    (0x1 << 9)		 /*W1C*/
#define MSDC_INTEN_RSPCRCERR 		(0x1 << 10)		 /*W1C*/
#define MSDC_INTEN_CSTA 			(0x1 << 11)		 /*W1C*/
#define MSDC_INTEN_XFER_COMPL 	    (0x1 << 12 )     /*W1C*/
#define MSDC_INTEN_DXFER_DONE		(0x1 << 13)		 /*W1C*/
#define MSDC_INTEN_DATTMO 		    (0x1 << 14)		 /*W1C*/
#define MSDC_INTEN_DATCRCERR	    (0x1 << 15)		 /*W1C*/
#define MSDC_INTEN_ACMD19_DONE 	    (0x1 << 16)		 /*W1C*/
#define MSDC_INTEN_BD_CS_ERR        (0x1 << 17)      /*W1C*/
#define MSDC_INTEN_GPD_CS_ERR       (0x1 << 18)      /*W1C*/

/*MSDC FIFOOCS Mask*/
#define MSDC_FIFOCS_RXCNT 			(0xff << 0)		 /*R*/
#define MSDC_FIFOCS_TXCNT		 	(0xff << 16)		 /*R*/
#define MSDC_FIFOCS_CLR			 (0x1UL << 31 )	 /*RW*/



/*MSDC_DMA_CTL mask*/
#define MSDC_DMA_CTL_START 		(0x1 <<0) 		/*W*/
#define MSDC_DMA_CTL_STOP 		(0x1 << 1)		 /*W*/
#define MSDC_DMA_CTL_RESUME 		(0x1 << 2)		 /*W*/
#define MSDC_DMA_CTL_MODE		(0x1 << 8) 		/*RW*/
#define MSDC_DMA_CTL_LASTBUF  		(0x1 << 10 )		/*RW*/
#define MSDC_DMA_CTL_BURSTSZ 		(0x7 << 12)		 /*RW*/
//#define MSDC_DMA_CTL_XFERSZ 		(0xffffUL << 16) 	/*RW*/ change to 0xa8 in CODA2.14


/*MSDC_DMA_CFG mask*/
#define MSDC_DMA_CFG_STS 			(0x1 << 0)		 /*R*/
#define MSDC_DMA_CFG_DECSEN		(0x1 << 1) 		/*RW*/
#define MSDC_DMA_CFG_BDCSERR 		(0x1 << 4) 		/*R*/
#define MSDC_DMA_CFG_GPDCSERR 	(0x1 << 5) 		/*R*/

/*MSDC_DMA_LENGTH mask*/
#define MSDC_MDA_LEN_XFER_SIZE	(0xffffffff)		/*RW*/					

/*MSDC_PATCH_BIT mask*/
#define MSDC_PATCH_BIT_WFLSMODE 		(0x1 << 0)	 /*RW*/
#define MSDC_PATCH_BIT_ODDSUPP 		(0x1 << 1) 	/*RW*/
#define MSDC_PATCH_BIT_CKGEN_CK 		(0x1 << 6) 	/*E2 : Fixed to 1*/
#define MSDC_PATCH_BIT_IODSSEL 		(0x1 << 16) 	/* RW*/
#define MSDC_PATCH_BIT_IOINTSEL		(0x1 << 17) 	/*RW*/
#define MSDC_PATCH_BIT_BUSYDLY 		(0xf << 18) 	/*RW*/
#define MSDC_PATCH_BIT_WDOD 			(0xf << 22)	/*RW*/
#define MSDC_PATCH_BIT_IDRTSEL 		(0x1 << 26) 	/*RW*/
#define MSDC_PATCH_BIT_CMDFSEL 		(0x1 << 27)	 /*RW*/
#define MSDC_PATCH_BIT_SPCPUSH		 (0x1 << 29)	 /*RW*/
#define MSDC_PATCH_BIT_DECRCTMO 		(0x1 << 30) 	/*RW*/

/*MSDC_PATCH_BIT1 mask*/
#define MSDC_PATCH_BIT1_WRDAT_CRCS 	(0x7 << 0)
#define MSDC_PATCH_BIT1_CMD_RSP 		(0x7 << 3)

/*MSDC_PAD_CTL0 mask*/
#define MSDC_PAD_CTL0_CLKDRV        (0x7  << 0)     /* RW */
#define MSDC_PAD_CTL0_CLKSR         (0x1  << 8)     /* RW */
#define MSDC_PAD_CTL0_CLKPUPD_18IO  (0x1  << 15)    /* RW */
#define MSDC_PAD_CTL0_CLKR50K_18IO  (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL0_CLKR10K_18IO  (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL0_CLKPD_DUAL_IO (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL0_CLKPU_DUAL_IO (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL0_CLKSMT        (0x1  << 18)    /* RW */
#define MSDC_PAD_CTL0_CLKIES        (0x1  << 19)    /* RW */
#define MSDC_PAD_CTL0_CLKTDSEL      (0xf  << 20)    /* RW */
#define MSDC_PAD_CTL0_CLKRDSEL      (0xffUL<< 24)   /* RW */


/* MSDC_PAD_CTL1 mask */
#define MSDC_PAD_CTL1_CMDDRV        (0x7  << 0)     /* RW */
#define MSDC_PAD_CTL1_CMDSR         (0x1  << 8)     /* RW */
#define MSDC_PAD_CTL1_CMDPUPD_18IO  (0x1  << 15)    /* RW */
#define MSDC_PAD_CTL1_CMDR50K_18IO  (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL1_CMDR10K_18IO  (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL1_CMDPD_DUAL_IO (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL1_CMDPU_DUAL_IO (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL1_CMDSMT        (0x1  << 18)    /* RW */
#define MSDC_PAD_CTL1_CMDIES        (0x1  << 19)    /* RW */
#define MSDC_PAD_CTL1_CMDTDSEL      (0xf  << 20)    /* RW */
#define MSDC_PAD_CTL1_CMDRDSEL      (0xffUL<< 24)   /* RW */


/*MSDC_PAD_CTL2 mask*/
#define MSDC_PAD_CTL2_DATDRV        (0x7  << 0)     /* RW */
#define MSDC_PAD_CTL2_DATSR         (0x1  << 8)     /* RW */
#define MSDC_PAD_CTL2_DATPUPD_18IO  (0x1  << 15)    /* RW */
#define MSDC_PAD_CTL2_DATR50K_18IO  (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL2_DATR10K_18IO  (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL2_DATPD_DUAL_IO (0x1  << 16)    /* RW */
#define MSDC_PAD_CTL2_DATPU_DUAL_IO (0x1  << 17)    /* RW */
#define MSDC_PAD_CTL2_DATSMT        (0x1  << 18)    /* RW */
#define MSDC_PAD_CTL2_DATIES        (0x1  << 19)    /* RW */
#define MSDC_PAD_CTL2_DATTDSEL      (0xf  << 20)    /* RW */
#define MSDC_PAD_CTL2_DATRDSEL      (0xffUL<< 24)   /* RW */



/*MSDC_PAD_TUNE mask*/
#define MSDC_PAD_TUNE_DATWRDLY 		(0x1f <<0) 		/*RW*/
#define MSDC_PAD_TUNE_DATRRDLY 		(0x1f << 8) 		/*RW*/
#define MSDC_PAD_TUNE_CMDRDLY		 (0x1f << 16) 		/*RW*/
#define MSDC_PAD_TUNE_CMDRRDLY		 (0x1fUL << 22) 		/*RW*/
#define MSDC_PAD_TUNE_CLKTXDLY		 (0x1fUL << 27) 		/*RW*/



/*MSDC_DAT_RDDLY0/1 mask*/
#define MSDC_DAT_RDDLY0_D0		(0x1f <<0)			/*RW*/
#define MSDC_DAT_RDDLY0_D1 		(0x1f << 8) 			/*RW*/
#define MSDC_DAT_RDDLY0_D2		 (0x1f << 16) 		/*RW*/
#define MSDC_DAT_RDDLY0_D3		(0x1f << 24) 			/*RW*/

#define MSDC_DAT_RDDLY1_D4		(0x1f <<0)			/*RW*/
#define MSDC_DAT_RDDLY1_D5 		(0x1f << 8) 			/*RW*/
#define MSDC_DAT_RDDLY1_D6		 (0x1f << 16) 		/*RW*/
#define MSDC_DAT_RDDLY1_D7		(0x1f << 24) 			/*RW*/

/*MSDC_PATCH_BIT0 mask*/
#define MSDC_CKGEN_MSDC_DLY_SEL     (0x1F<<10)
#define MSDC_INT_DAT_LATCH_CK_SEL   (0x7<<7)
#define MSDC_CKGEN_MSDC_CK_SEL      (0x1<<6)
#define MSDC_CKGEN_RX_SDCLKO_SEL    (0x1<<0)

/* MSDC_PATCH_BIT1 mask */
#define MSDC_CMD_RSP_TA_CNTR        (0x7<<3)
#define MSDC_WRDAT_CRCS_TA_CNTR     (0x7<<0)

/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*define for custom ,need check  ----begin*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/

typedef struct
{
	kal_uint32 (*Init)(void);
	kal_bool (*IsCardInd)(void);
	void (*PowerCtrl)(kal_bool on);
} MSDC_Custom_Handle;

typedef struct
{
	kal_uint8 cmd_clk_odc;
	kal_uint8 dat_odc;
	kal_uint8 cmd_clk_slew;
	kal_uint8 dat_slew;
}msdc_io_ctrl_struct;
typedef enum
{
	MSDC_HOT_PLUG = 		0x1,	// MSDC support hot plugging
	MSDC2_HOT_PLUG = 		0x2,	// MSDC2 support hot plugging
	MSDC_WP = 				0x4,	//  MSDC support write protecton detection
	MSDC2_WP = 				0x8,	// MSDC2 support write protection detection
	MSDC_SD4_SDIO1 =		0x10,	// SD/MMC use MSDC1(4-bits) and SDIO use MSDC2(1-bits)
	MSDC_SDIO4_SD1	= 		0x20	// vice versa
	//MSDC_SDIO4_SDIO1,  // not support now
}msdc_custom_enum;
#if !defined(DRV_MSDC_MT6225_SERIES) && !defined(MT6276) && !defined(MT6573) && !defined(MT6251) && !defined(MT6256) && !defined(MT6255) && !defined(MT6280)
// configure the output driving capacity and slew rate
#define MSDC_ODC_2MA		0x0
#define MSDC_ODC_4MA		0x1
#define MSDC_ODC_6MA		0x2
#define MSDC_ODC_8MA		0x3
// only MT6227, MT6217 and MT6218B can support following driving capacity
//#if defined(MT6228)||defined(MT6229) || defined(MT6227)|| defined(MT6226)|| defined(MT6226M)
#define MSDC_ODC_10MA		0x4
#define MSDC_ODC_12MA		0x5
#define MSDC_ODC_14MA		0x6
#define MSDC_ODC_16MA		0x7
//#endif
#elif defined(__DRV_MSDC_DRIVING_53_SERIES__)
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_8MA		0x4
#define MSDC_ODC_12MA		0x2
#define MSDC_ODC_16MA		0x6
#elif defined(DRV_MSDC_DRIVING_36_SERIES)
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_12MA		0x1
#define MSDC_ODC_8MA		0x2
#define MSDC_ODC_16MA		0x3
#elif defined(DRV_MSDC_DRIVING_6255_SERIES)
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_8MA		0x1
#define MSDC_ODC_12MA		0x2
#define MSDC_ODC_16MA		0x3
#else
#define MSDC_ODC_4MA		0x0
#define MSDC_ODC_8MA		0x2
#define MSDC_ODC_12MA		0x4
#define MSDC_ODC_16MA		0x6
#endif

#ifndef DRV_MSDC_IOCON_CORRECT_SLEW_RATE
#define MSDC_ODC_SLEW_FAST		1
#define MSDC_ODC_SLEW_SLOW		0
#else
#define MSDC_ODC_SLEW_FAST		0
#define MSDC_ODC_SLEW_SLOW		1
#endif
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/
/*define for custom ,need check   -----finish*/
/*+++++++++++++++++++++++++++++++++++++++++++++++++++*/


/*------------------------------------------------*/

typedef enum{
 MSDC_IOCTRL_DISABLE		= 0,
 MSDC_IOCTRL_PULL_DOWN	= 1,
 MSDC_IOCTRL_PULL_UP		= 2,
 MSDC_IOCTRL_KEEPER		= 3
}msdc_ioctrl_enum;
typedef struct {
    kal_uint32 function1;
    kal_uint32 function2;
    kal_uint32 function3;
    kal_uint32 function4;
} T_SWITCH_SUPPROT_FUNCTIONS;

typedef struct 
{
	kal_uint32 hwo:1;
	kal_uint32 bdp:1;
	kal_uint32 rsv0:6;
	kal_uint32 chksum:8;
	kal_uint32 intr:1;
	kal_uint32 rsv1:15;
	void *next;
	void *ptr;
	kal_uint32 buflen:16;
	kal_uint32 extlen:8;
	kal_uint32 rsv2:8;
	kal_uint32 arg;
	kal_uint32 blknum;
	kal_uint32 cmd;
}msdc_gpd_t;

typedef struct 
{
	kal_uint32 eol:1;
	kal_uint32 rsv0:7;
	kal_uint32 chksum:8;
	kal_uint32 rsvl:1;
	kal_uint32 blkpad:1;
	kal_uint32 dwpad:1;
	kal_uint32 rsv2:13;
	void *next;
	void *ptr;
	kal_uint32 buflen:16;
	kal_uint32 rsv3:16;
}msdc_bd_t;

typedef struct 
{
	kal_uint32				msdc_clock;     // clock rate of MSDC	
	kal_uint32				op_clock_max;     // clock rate of the serial clock output to card
	kal_uint32				op_clock;       // clock rate of the serial clock output to card
	kal_uint32 				timeout_period; // x 10ms
	kal_uint32				error;		//store the EIO or TIMEOUT error information when send command or data 
	kal_bool					abort;		//write to 1 to abort the transfer
	kal_bool					dma_xfer;	//write 1 mean use dma to transfer ,write 0 mean to use poll to transfer    
	kal_uint32 				vdd_volt;	// voltage of Vdd
	kal_uint32				signal_volt;	//voltage of signal pin
	kal_uint32			bus_width;		//the bus width 1 ,4, 8 
	void 			   *buf_addr;			//store the address of the data buffer
	kal_uint32 			total_count;    //
	kal_uint32			trans_count;			//store the data size per  transation
	T_SWITCH_SUPPROT_FUNCTIONS host_support; //indicate the functionsins(driver type/current limit /speed mode)  support by host ,
	msdc_ioctrl_enum		ins_level;      // indicate the INS pin pull status;
	kal_uint32 			app_cmd;		// 1 mean the command we send is app command , we will send cmd55 first ,
	kal_uint8           cmd;
	volatile T_MSDC_CARD	mMSDC_type;     // indicate the type of card(SD, MMC, MS)
	volatile kal_bool		mIsPresent;     // card is present or not
	volatile kal_bool		mIsInitialized; // card is initialized or not
	volatile kal_bool		mIsChanged;     // card is changed or not
	volatile kal_bool 		is_timeout;     // flag to indicate whther the gpt is expired		
	kal_bool				mIsPWDown;      // is MSDC is power down
	DCL_HANDLE 				gpt_handle;     // handler of gpt timer 		
	kal_uint8	 			cmd_sta;        // store the status of the latest CMD transaction
	kal_uint8				dat_sta;        // store the status of the latest DAT transaction
	//msdc_ioctrl_enum		ins_level;      // indicate the INS pin pull status;
	kal_uint8 				timeout_count;  // retry of card mounting during read or write
	kal_bool				is_poll;        // is busy-waiting or event-triggered for data trasaction
	kal_bool				is_aligned;     // is transfer by 4-byte alignment
	kal_bool				is_init_timeout;    // the initialization process larger than 1 sec
	kal_bool				send_ilm;       // 1: means to send ilm to fmt task
	kal_uint8 				msdc_dmaport;   // DMA setting
	kal_eventgrpid          MSDC_Events;    // events used for memory car
	kal_uint8 				dataCrcError_count; // we count the times to happen data CRC error
	kal_uint32				trySingleLine;  //we use this flag to mrak that we want to rey single line on this card
	                                        // 0 don't try single line , 1 host force to try single line on all card ,2 use to
	                                        // try single line when CRC on current data ,will not effect the next card
    kal_uint8               msdc_sm_hdl;

    qbm_gpd *head;
    qbm_gpd *tail;
    msdc_gpd_t * gpd;
    msdc_gpd_t * gpd_end;
    kal_bool f_tuning;
    
#ifdef MSDC_CACHED_SUPPORT
	kal_bool				isCachedBuf;
    kal_bool                isRomSpace;       //R\W buffer address is in ROM space or not 
	kal_uint32				cachedBufCopyPtr;
#endif
#if defined(MSDC_DEBUG_INFO)
    kal_char                msdc_fname[20];
    kal_uint32              msdc_lines;
#endif
	
#ifdef DRV_MSDC_SHARE_BY_SWITCH
	kal_uint32				setting_MSDC_CFG;
	kal_uint32				setting_MSDC_IOCON;
	kal_uint32				setting_SDC_CFG;
#endif

#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
	//tuning_topology			tuningTopology;
#endif

#ifdef MSDC_MUST_RECORD_PLUGOUT
	kal_bool MSDC_everPlugOut;//this is only be set true in plug out hisr, set false in MSDC_getStatus
#endif

	MSDC_Custom_Handle msdc_custom_handle;

#ifdef __DRV_MSDC_FAST_FORMAT__
	kal_bool	MSDC_fastFormat ;
#endif
#ifndef DRV_LSD
	kal_uint32 msdcTimeoutDuration;
#endif

#ifdef	DRV_MSDC_CLK_SEARCH
	kal_uint32	msdc_clkTuneUpperBund;
#endif

#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
	kal_uint32 msdc_clkTuneTriedWr ;
	kal_uint32 msdc_clkTuneTriedRd ;
	kal_uint32 msdc_RedDlt_forRd ;
	kal_uint32 msdc_RedDlt_forWr ;
#endif

    volatile kal_bool			mIsInitMSDC; // MSDC is initialized or not
    volatile kal_bool			mIsProbeMSDC; // MSDC is initialized or not
    kal_uint32 msdc_int;
#ifdef R1B_DEBUG
    kal_uint32 LISR_Entry_Count;
    kal_uint32 SDCMDIRQ_Entry_Count;
    kal_uint32 SDMCIRQ_Entry_Count;
    kal_uint32 SDDATIRQ_Entry_Count;
    kal_uint32 SDR1bIRQ_Entry_count;
    kal_uint32 SDIOIRQ_Entry_Count;
    kal_uint32 SDPINIRQ_Entry_Count;
#endif     

}MSDC_HANDLE, *pMSDC_HANDLE; 




/*define the option of MSDC_HANDLE->error*/
//#define NONE_ERROR	0			//mean right to send command or data
//#define EIO_ERROR	-1			//mean CRC error on command response or data
//#define TIMEOUT_ERROR	-2		//mean timeout error when send command or data
/**/
#define MSDC_TIMEOUT_WAIT(cond,duration_ms)	\
	({ \
		volatile kal_uint32 start_time;\
		start_time = drv_get_current_time();\
		while (drv_get_duration_ms(start_time) <=duration_ms) \
		{ \
			if (cond) \
			{\
				break;\
			}\
		}\
		(!(cond));\
	})
	
#define MSDC_RESET()  \
		do { \
				MSDC_SET_FIELD(MSDC_CFG, MSDC_CFG_RST, 1); \
				MSDC_TIMEOUT_WAIT(!(MSDC_Reg32(MSDC_CFG)&MSDC_CFG_RST),500); \
		} while (0)

#define MSDC_CLR_FIFO()

#define MSDC_CLR_FIFO_EX() \
		do{\
				MSDC_SET_FIELD(MSDC_FIFOCS, MSDC_FIFOCS_CLR, 1);\
				MSDC_TIMEOUT_WAIT(!(MSDC_Reg32(MSDC_FIFOCS)&MSDC_FIFOCS_CLR),500);\
		}while(0)
		
#define MSDC_STOP_DMA()\
		do{\
				MSDC_SET_FIELD(MSDC_DMA_CTL, MSDC_DMA_CTL_STOP, 1);\
				MSDC_TIMEOUT_WAIT((!(MSDC_Reg32(MSDC_DMA_CTL)&MSDC_DMA_CTL_STOP))||(!(MSDC_Reg32(MSDC_DMA_CFG)&MSDC_DMA_CFG_STS)),500);\
		}while(0)
#define MSDC_CLR_INT()\
		do{\
				 volatile kal_uint32 temp;\
				 temp=MSDC_Reg32(MSDC_INT);\
				MSDC_WriteReg32(MSDC_INT,temp);\
		}while(0)


/*tune pattern*/
#define DEFAULT_DTOC (128)  //  need change the value  again !!!!!!!!!!!
/*common define*/
#define MSDC_BUS_1BITS 	(0)
#define MSDC_BUS_4BITS	(1)
#define MSDC_BUS_8BITS 	(2)

#define MSDC_FIFO_THD	(128)
#define MSDC_FIFO_SZ	(128)
#define MSDC_RXFIFOCNT()	((MSDC_Reg32(MSDC_FIFOCS)&MSDC_FIFOCS_RXCNT)>>0)
#define MSDC_TXFIFOCNT()	((MSDC_Reg32(MSDC_FIFOCS)&MSDC_FIFOCS_TXCNT)>>16)
#define MSDC_FIFO_WRITE32(val)	(MSDC_WriteReg32(MSDC_TXDATA, (val)))
#define MSDC_FIFO_WRITE8(val)	(MSDC_WriteReg8(MSDC_TXDATA,(val)))
#define MSDC_FIFO_READ32()	(MSDC_Reg32(MSDC_RXDATA))
#define MSDC_FIFO_READ8()	(MSDC_Reg8(MSDC_RXDATA))
/*Event*/
#define EVENT_XFER_DONE 0x00000001
#define EVENT_DMA_DONE 0x00000002
#define EVENT_CMD_DONE 0x00000004

#define MSDC_NOERROR					0
#define MSDC_ERR_CARD_DETECT			101
#define MSDC_CARD_NOT_PRESENT			102
#define MSDC_DMA_FAIL					104
#define MSDC_GPT_TIMEOUT_ERR			199


#define MSDC_CARD_NOT_PRESENT			102

/**/
#define MSDC_INIT_CLOCK	(270000)			//270kHz
#define MSDC_ENABLE_CARD_CLOCK(a) \
	do { \
		if (a==KAL_FALSE)\
		{\
			MSDC_ClearBits32(MSDC_CFG,MSDC_CFG_CKDRV_EN);\
		}\
		else if (a== KAL_TRUE)\
		{\
			MSDC_SetBits32(MSDC_CFG,MSDC_CFG_CKDRV_EN);\
		}\
	}while(0)

#define MSDC_CMD_TIMEOUT        1500	// 1500ms
#define MSDC_DATA_TIMEOUT       5000	// 5000ms
#define MSDC_DMA_DAT_TMO        500	    // 500*10ms
#define MSDC_TIMEOUT_PERIOD_INI 5000    // 5000ms

#define MSDC_UNCACHED_TRANSFER_SIZE     4096    //4K byte buffer

/*trace*/
#define MSDC_DRV_TRC_FILE_MSDC			0
#define MSDC_DRV_TRC_FILE_SD			1
#define MSDC_DRV_TRC_FILE_SD_DRV		2
#define MSDC_DRV_TRC_FILE_MS			3
#define MSDC_DRV_TRC_FILE_MS_DRV		4
#define MSDC_DRV_TRC_FILE_MSP			5
#define MSDC_DRV_TRC_FILE_MSP_DRV		6

#define MSDC_PIN_PULL_NONE		(0)
#define MSDC_PIN_PULL_DOWN	(1)
#define MSDC_PIN_PULL_UP		(2)
#define MSDC_PIN_KEEP			(3)

// define the MSDC_HANDLE->trySingleLine
#define NO_SINGLE_LINE  (0)         //will not try single line
#define FORCE_SINGLE_LINE  (1<<0)      //host force try single line on all card when init the card
#define TEMP_SINGLE_LINE    (1<<1)     //just try single line when crc error , will be reset to 0 after current init


#if defined(__SIM_PLUS__)
typedef enum{
	SD_EXT = 0,
	SD_SIM = 1,
	SD_NUM = 2
}sd_select_enum;
/*bewlow comes after JRD SIM+ issue on 2007_03_08, add custom setting on "clock without sim+" and "ext_sd ldo" */
typedef enum{
 MSDC_13M	= 0,
 MSDC_24M	= 1
}msdc_ClockWithoutSIMPlus;

#define MSDC_NO_EXT_LDO					0xFF
/*end of JRD SIM+ issue on 2007_03_08*/
#elif defined(DRV_MSDC_MT6238_SERIES)
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_MSDC2 = 1,		
	SD_NUM = 2
}sd_select_enum;
#elif defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
	SD_T_CARD_2 =1,
	SD_NUM = 2
}sd_select_enum;
#else
typedef enum{
	SD_EXT = 0,
	SD_MSDC1 = 0,
#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
	SD_SDIO = 1,
#endif
	SD_NUM
}sd_select_enum;


#endif

typedef struct _msdc_lock_tag {
   kal_uint8 name[20];
   kal_uint32  lock_count;
   kal_taskid  owner_id;
   kal_mutexid mtd_mutex;
} MSDC_LOCK_TAG, *PMSDC_LOCK_TAG;


// 3'b000: 26MHz
// 3'b001: 40MHz
// 3'b010: 50MHz
// 3'b011: 60MHz
// 3'b100: 69MHz
// 3'b101: 80MHz
// 3'b110: 96MHz
// 3'b111: 100MHz
typedef enum {
	SRC_26M=0,
	SRC_40M=1,
	SRC_50M=2,
	SRC_60M,
	SRC_69M,
	SRC_80M,
	SRC_96M,
	SRC_100M
}T_MSDC_CLK_TYPE;


/*use to define the card clock mode */
/* 0 use clock devider by msdc_src_ck as msdc_ck    1 use msdc_src_ck as msdc_ck   2 ddr mode */
typedef enum {
	USE_CLOCK_DIV=0,	
	USE_MSDC_SRC_CK=1,
	USE_DDR_MODE=2
} CARD_CLOCK_MODE;

typedef enum
{
	msdc_dbg_event_DMA_done,
	msdc_dbg_event_DMA_RLCT_Monitor,
	msdc_dbg_event_DMA_timeout,
	msdc_dbg_event_SD_CMD_issue,
	msdc_dbg_event_SD_CMD_issue2,
	msdc_dbg_event_SD_transfer_event_retreived1,
	msdc_dbg_event_SD_transfer_event_retreived2,
	msdc_dbg_event_SD_transfer_event_retreiving1,
	msdc_dbg_event_SD_transfer_event_retreiving2,
	msdc_dbg_event_SD_transfer_DMA_timeout_monitor,
	msdc_dbg_event_SD_transfer_timeout_assert,
	msdc_dbg_event_SD_transfer_poll_end1,
	msdc_dbg_event_SD_transfer_poll_end2,
	msdc_dbg_event_SD_cached_copy_start,
	msdc_dbg_event_SD_cached_copy_end,
	msdc_dbg_event_SD_datTimeOut_sta,
	msdc_dbg_event_GPT_timeout,
	msdc_dbg_event_SD_read_fail_systemInit,
	msdc_dbg_event_SD_clk_tuning,
	msdc_dbg_event_SD_datsta_systemInit,
	msdc_dbg_event_SD_multi_blk_write_issue1,
	msdc_dbg_event_SD_multi_blk_write_issue2
} msdc_dbg_Event;

typedef struct
{
	msdc_dbg_Event event;
	kal_uint32 time;
	kal_uint32 data32_0;
	kal_uint32 data32_1;
} msdc_debugMessage;


typedef enum{
	BIT_1W ,
	BIT_4W=2,
	BIT_8W
}SD_BITWIDTH;

typedef enum{
	CMD_SET,
	SET_BIT,
	CLR_BIT,
	SET_BYTE
}CMD6_ACCESS_MODE;

#define EXT_MEM_ID			(void *)(&MSDC_Blk[SD_EXT])

#if defined(__SIM_PLUS__)
#define SIMPLUS_MEM_ID		(void *)(&MSDC_Blk[SD_SIM])
#endif

#if defined(__MSDC_DUAL_CARD_SWITCH__)
#define TCARD_2_MEM_ID		(void *)(&MSDC_Blk[SD_T_CARD_2])
#endif

#ifdef __CUST_NEW__
//if __CUST_NEW__ is defined, following variables will be decalred and initialized by custom tool
extern const char gpio_simplug_ldo_switch;
extern const char gpio_sim_msdc_switch;
extern const char gpio_ext_sd_ldo_switch;
#else
//if __CUST_NEW__ is undefined, following variables will be declared in msdc.c and will be assigned value in msdc initialization
extern  kal_char gpio_simplug_ldo_switch;
extern  kal_char gpio_sim_msdc_switch;
extern  kal_char gpio_ext_sd_ldo_switch;
#endif
#define GPIO_LDO_SWITCH 				gpio_simplug_ldo_switch
#define GPIO_EXT_SD_LDO_SWITCH		gpio_ext_sd_ldo_switch
#define GPIO_SIM_MSDC_SWITCH 			gpio_sim_msdc_switch
#define ENTER_CRITICAL()		{\
													kal_uint32 _savedMask;\
													_savedMask = SaveAndSetIRQMask();

#define EXIT_CRITICAL()			RestoreIRQMask(_savedMask);}


/**/
/**/
/**/
/**/
/**/
/**/
/**/
/**/
#if defined(__UBL__) || defined(__FUE__)
#include "msdc_fake_kal.h"
#define kal_set_eg_events(...) do { } while (0);
#define kal_retrieve_eg_events(...) do { } while (0);
#define kal_debug_print dbg_print
#define kal_query_systemInit() (KAL_FALSE)
#define INT_QueryExceptionStatus(...) (KAL_FALSE)
#define kal_sleep_task(x)	{\
							kal_uint32 i = x;\
							while(i--);\
						}
#define kal_prompt_trace(...) do { } while (0);
#define drv_trace1(...) do { } while (0);
#define drv_trace2(...) do { } while (0);
#define drv_trace4(...) do { } while (0);
#define drv_trace8(...) do { } while (0);

#ifdef MSDC_INT
#undef MSDC_INT
#endif

#ifdef __DRV_MSDC_FAST_FORMAT__
#undef __DRV_MSDC_FAST_FORMAT__
#endif

#ifdef __MULTI_BOOT__
#undef __MULTI_BOOT__
#endif
#else//defined(__UBL__) || defined(__FUE__)
#ifdef __MTK_TARGET__
extern kal_bool INT_QueryExceptionStatus(void);
#endif
#endif//defined(__UBL__) || defined(__FUE__)

#if !defined(__FUE__) && !defined(__UBL__)
void init_MSDC_lock(PMSDC_LOCK_TAG lock, const kal_char *str);
void get_MSDC_lock(PMSDC_LOCK_TAG lock);
void free_MSDC_lock(PMSDC_LOCK_TAG lock);
#else /* __FUE__, __UBL__ */
#define init_MSDC_lock(x, y)
#define get_MSDC_lock(x)
#define free_MSDC_lock(x)
#endif /* !defined(__FUE__) && !defined(__UBL__) */

#if defined(__UBL__) || defined(__FUE__)
//#define MSDC_GPTI_BusyWait(...) do { } while (0);
#define MSDC_GPTI_BusyWait(...)	0
#define kal_sleep_task(x)	{\
							kal_uint32 i = x;\
							while(i--);\
						}
#define MSDC_GPTI_GetHandle(...) 
#else
#define MSDC_GPT_CB_MAGIC_NUM 0x02000000
void MSDC_GPTI_BusyWait(kal_uint16 len);
kal_uint8 MSDC_GPTI_GetHandle(DCL_HANDLE *handle);
kal_bool MSDC_GPTI_StartItem(kal_uint8 module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
void MSDC_GPTI_StopItem(kal_uint8 module);
#endif//defined(__UBL__) || defined(__FUE__)

#if defined(DRV_MSDC_DEBUGGING_SLA)
#define MSDC_SLA_Start_Logging(x) SLA_CustomLogging(x, 1)
#define MSDC_SLA_Stop_Logging(x) SLA_CustomLogging(x, 0)
#else
#define MSDC_SLA_Start_Logging(x)
#define MSDC_SLA_Stop_Logging(x)
#endif

#if defined(__UBL__) || defined(__FUE__) /*bootloader case*/
    #define force_ASSERT(expr, e1, e2, e3) {if(!(expr)) {dbg_print("force_ASSERT:%s line:%d e1:%d,e2:%d,e3:%d\n",__FILE__,__LINE__, e1, e2, e3);while(1);}}
#else
    #define force_ASSERT(expr, e1, e2, e3) {EXT_ASSERT(expr, e1, e2, e3);}
#endif


#define _MSDC_DMA_		// using DMA transfer instead of polling
#define _MSDC_INT_		// using hardware interrupt instead of polling



extern MSDC_HANDLE MSDC_Blk[SD_NUM];
extern MSDC_HANDLE *gMSDC_Handle;
extern kal_uint32 MSDC_Sector[128];
#if defined(MSDC_MMC40_SUPPORT)
extern kal_uint32 MSDC_eCSD[128];
#endif
extern sd_select_enum current_card;

kal_bool MSDC_STOP_TIMER(void);
kal_bool MSDC_START_TIMER(kal_uint16 x);

void MSDC_Initialize(void);
void MSDC_DeInit(void);
kal_bool MSDC_CardDetect(void);
void MSDC_HostSelect(T_MSDC_CARD type);
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask);
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width);
void MSDC_LISR(void);
void MSDC_HISR_Entry(void);
extern int MSDC_GetCardStatus(void *slot_id, int AckType);
extern void MSDC_PDNControl(kal_bool ON);


extern void MSDC_TimeOutHandler(void *parameter);
kal_bool MSDC_GetMediaChanged(sd_select_enum sel);
kal_uint32 MSDC_SetClock(kal_uint32 clock,kal_bool ddr_mode);
void MSDC_SetBusWidth(SD_BITWIDTH bus_width);
void MSDC_turnOnVMC(kal_bool turnOnLdo);

extern kal_bool MSDC_Check_Card_Present(void);
extern void MSDC_FatalErrorHandle();
extern void MSDC_DMATransferFirst( kal_bool isWrite,kal_bool isLinkListBuf);
extern kal_uint32 MSDC_DMATransferFinal(kal_bool isWrite,kal_bool isLinkListBuf);
extern kal_uint32 MSDC_PollInts(kal_uint32 int_mask,kal_uint32 timeout_ms);
extern kal_uint32 MSDC_CheckCardBusy(kal_bool send_stop,kal_uint32 timeout_ms);
void MSDC_DMAInit(void);
void MSDC_ConfigPin(kal_uint32 pullmode);
void msdc_sleep(kal_uint32 ticks);
kal_bool MSDC_SetSignalPower(kal_bool on,kal_uint32 volt);
void power_cycle(kal_uint32 interval_ticks);
void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len);

kal_bool MSDC_SetVddPower(kal_bool on,kal_uint32 volt);
 kal_uint32  uffs(kal_uint32 x);









#endif






