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
 *   msdc.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for MSDC controller
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
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
 * removed!
 *
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
#include "drv_features.h"
#ifndef DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "md_drv_sap.h"
#include "drv_msgid.h"
//RHR ADD
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "kal_public_api.h"
#include "kal_debug.h"
#include "hisr_config.h"
#include "config_hw.h"
#include "init.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "kal_active_module.h"
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
//#include "gpio_hw.h"
#ifdef __MULTI_BOOT__
#include "syscomp_config.h"
#include "multiboot_config.h"
#endif//__MULTI_BOOT__
#include "pmu_sw.h"
#if defined(KAL_ON_NUCLEUS)
#include "nucleus.h"
#include "ev_defs.h"
#endif
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "kal_public_api.h"
#include "kal_public_api.h" //MSBB change #include "app_ltlcom.h"       /* Task message communiction */
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
#include "drv_features.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "drv_hisr.h"
#include "sleepdrv_interface.h"
#include "eint.h"

#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)
#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "../../../devdrv/iomux/inc/drv_iomux.h"

//! EMB
#include "FTL.h"

#if defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)
#include "sdio_sw.h"
#endif
#if defined(__MSDC_MS__)
#include "ms_def.h"
#elif defined(__MSDC_MSPRO__)
#include "mspro_def.h"
#endif
#include "upll_ctrl.h"
//#include "gpio_sw.h"
#include "drv_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

#ifdef DRV_LSD
#include "msdc_lsd.h"
#endif

#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON1
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else
#define DRVPDN_CON1		CG_CON1
#endif

#ifdef DRVPDN_CON1_SIM
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SIM are all defined"
#else
#define DRVPDN_CON1_SIM	CG_CON1_SIM
#endif

#ifndef MSDC_TEST_MSDC2_FROM_MSDC1_CODE

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON1_MSDC
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR1
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET1
#endif

#else /*when MSDC_TEST_MSDC2_FROM_MSDC1_CODE is defined, we direct CON1 related macro to CON0 related*/

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR0
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET0
#endif
#endif//MSDC_TEST_MSDC2_FROM_MSDC1_CODE

#endif




/*
#if !(defined __MSDC_NOT_SUPPORT_HOT_PLUG__)
#if defined(MT6218B_FN) || defined(MT6219_EV) ||defined(MT6217)||defined(MT6227)||defined(MT6226)||defined(MT6226M)\
		|| defined(MT6225)
#define USE_INT26_CARD_DETECTION
#endif
#endif
*/


#if defined (WISDOM35B_DEMO_BB)
extern const char gpio_SD_det_pin;
#endif

// global variable
MSDC_HANDLE MSDC_Blk[SD_NUM];

/*    no need now  ,compile pass first
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
#if defined(MT6256)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {94500, 86600, 74200, 65000};
#elif defined(MT6255)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF};
#elif defined(MT6250)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {97500, 86600, 78000, 65000};
#elif defined(MT6280)
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {96000, 80000, 68600, 60000};
#else
kal_uint32 gMsdcClksrcRate[MSDC_CLKSRC_NUM] = {122200, 101800, 87200, 76300}; // KHz
#endif
#endif
*/

#if (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__)|| defined(__MSDC_MSPRO__)) || defined(__MSDC_SD_SDIO__)
MSDC_HANDLE	*gMSDC_Handle = &(MSDC_Blk[0]);

#if defined(__UBL__) && defined(__EMMC_BOOTING__)
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32 MSDC_Sector[128];
#if defined(MSDC_MMC40_SUPPORT)
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32 MSDC_eCSD[128];
#endif
#ifdef MSDC_CACHED_SUPPORT
__attribute__ ((zero_init, section ("EXT_UN_INIT_ZI")))kal_uint32	msdc_uncachedBuf[MSDC_UNCACHED_BUF_SIZE / 4];
#endif
#else
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32 MSDC_Sector[128];
#if defined(MSDC_MMC40_SUPPORT)
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32 MSDC_eCSD[128];
#endif
#ifdef MSDC_CACHED_SUPPORT
__attribute__ ((zero_init, section ("NONCACHEDZI")))kal_uint32	msdc_uncachedBuf[MSDC_UNCACHED_BUF_SIZE / 4];
#endif
#endif
//Light 120907
#define MSDC_DMA_BURSTLEN_LIMIT 0xFFFFFFFF//4294966784  //32bit 
//#define MSDC_DMA_BURSTLEN_LIMIT 65024
kal_bool MSDC_useDMA4ByteBurst = KAL_FALSE;

/* Debug log */
kal_uint32 MSDC_DebugLevel;

/* IO configurations */
static struct msdc_cust msdc_cap = {
    0,                   /* host clock source             */
    1,                   /* command latch edge            */
    1,                   /* read data latch edge          */
    1,                   /* write data latch edge         */
    
    {6, 6, 0, 0, 1, 0, 1},
    {4, 4, 0, 0, 1, 0, 1},
    {4, 4, 0, 0, 1, 0, 1},
    
    8,                   /* data pins                     */
    0,                   /* data address offset           */

    /* hardware capability flags     */
    0, 
};

#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this additional global variable to use when in error recording*/
MSDC_HANDLE MSDC_ErrorRecordingBlk;
#endif

#if defined(DRV_MSDC_SHARE_BY_SWITCH)
sd_select_enum current_card; // active card
#if !defined(__CUST_NEW__)
extern kal_char MSDC_GetLDO_GPIO(void);
extern kal_char MSDC_GetSwitch_GPIO(void);
extern kal_char MSDC_GetEXTLDO_GPIO(void);
extern kal_char MSDC_GetSwitchDirection(void);
kal_char gpio_simplug_ldo_switch;
kal_char gpio_ext_sd_ldo_switch;
kal_char gpio_sim_msdc_switch;
#endif
#endif

#if !defined(LOW_COST_SUPPORT) && !defined(DRV_LSD) && defined(__DRV_DBG_MEMORY_TRACE_SUPPORT__) && !defined(__UBL__)
msdc_debugMessage msdc_msgArray[MSDC_DBG_ARRAY_SIZE];
kal_uint32 msdc_msdIndex;
#endif

#define MSDC_EINT_NUM       MSDC_EINT_NO


// system control blocks

// function predeclaration
void MSDC_DMAInit(void);
void MSDC_INT_Init(void);
void MSDC_DMA_Callback(void);
void MSDC_EINT_Handler(void);
void MSDC_turnOnVMC(kal_bool turnOnLdo);
#ifdef R1B_INTERRUPT_MODE
static void MSDC_R1B_Init();
#endif


extern void GPIO_ModeSetup(kal_uint16 pin, kal_uint16 conf_dada);
extern boot_mode_type kal_query_boot_mode(void);
extern kal_bool INT_USBBoot(void);
extern kal_int8 MSDC_GetDLTFromOPCLK(kal_uint32 opClk, kal_uint8 *setRED);
extern void SD_Sleep4Wait(kal_int32 sleep_tick);
extern void msdc_tune_init(void);

#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC_QueryIsPowerControllable(void);
extern void MSDC_SetPower(kal_bool enable);
#endif

#if !defined(_MSDC_INTERNAL_CD_INT_PIN_)

#if defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
#error "__MSDC_NOT_SUPPORT_HOT_PLUG__ shouldn't be defined."
#endif
extern const unsigned char MSDC_EINT_NO;
static kal_uint32 MSDC_debounceTime;
static kal_bool cardDetectionEINTPolarity;
#endif

#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_START_TIMER(kal_uint16 x)
{
    gMSDC_Handle->is_timeout = KAL_FALSE;
}
#else// defined(__UBL__) || defined(__FUE__)

kal_bool MSDC_START_TIMER(kal_uint16 x)
{
    //DCL_HANDLE gpt_handle;
    DCL_STATUS status;
    SGPT_CTRL_START_T start;

#if defined(MSDC_DEBUG_INFO)
    strcpy(gMSDC_Handle->msdc_fname, __FILE__);
    gMSDC_Handle->msdc_lines = __LINE__;
#endif

    gMSDC_Handle->is_timeout = KAL_FALSE;
    start.u2Tick = x;
    start.pfCallback = MSDC_TimeOutHandler;
    start.vPara = NULL;
    //gpt_handle= module |MSDC_GPT_CB_MAGIC_NUM;
    status = DclSGPT_Control(MSDC_Blk[0].gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start);
    //dbg_print("start timer++++++++%d+++++\r\n",drv_get_current_time());
    if (STATUS_OK == status)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}
#endif// defined(__UBL__) || defined(__FUE__)

#if defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_STOP_TIMER()
{
    return KAL_TRUE;
}
#else// defined(__UBL__) || defined(__FUE__)
kal_bool MSDC_STOP_TIMER()
{
    

    //MSDC_GPTI_StopItem(gMSDC_Handle->gpt_handle);
    DclSGPT_Control(MSDC_Blk[0].gpt_handle, SGPT_CMD_STOP, 0);
    if (gMSDC_Handle->is_timeout ||!gMSDC_Handle->mIsPresent)
    {
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
    }
    //dbg_print("stop timer +++++++%d++++++++\r\n",drv_get_current_time());
    return KAL_TRUE;
}
#endif// defined(__UBL__) || defined(__FUE__)

#if !defined(__FUE__) && !defined(__UBL__)
void MSDC_GPTI_BusyWait(kal_uint16 len)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

kal_uint8 MSDC_GPTI_GetHandle(DCL_HANDLE *handle)
{
    //DCL_HANDLE gpt_handle;
    *handle = DclSGPT_Open(DCL_GPT_CB, 0);

    //*handle = 0xFF & gpt_handle;

    return KAL_TRUE;
}

#endif//!defined(__FUE__) && !defined(__UBL__)

/*************************************************************************
* FUNCTION
*  MSDC_SetClock
*
* DESCRIPTION
*
* PARAMETERS
*	clock: the desired operating clock rate in the unit of kHz
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_uint32  MSDC_SetClock(kal_uint32 bus_clock,kal_bool ddr_mode)
{
	kal_uint32 msdc_clock,op_clock=0;
	kal_uint32 div,mode;
	if (!gMSDC_Handle->msdc_clock)
	{
		/*didn't set source clock*/
		MSDC_ERR("[MSDC][%s %d]set clock before set source clock\r\n",__FUNCTION__,__LINE__);
		return MSDC_ERROR;
	}
	
	msdc_clock=gMSDC_Handle->msdc_clock;

	if (!(bus_clock))
	{
		MSDC_RESET();
		MSDC_ENABLE_CARD_CLOCK(KAL_TRUE);
		MSDC_ERR("[MSDC][%s %d]can't set bus clock to %d\r\n",__FUNCTION__,__LINE__,bus_clock);
		return MSDC_ERROR;
	}

	/* Check the MAX bus clock which could be supportted by driver */
	if (bus_clock > gMSDC_Handle->op_clock_max)
	    bus_clock = gMSDC_Handle->op_clock_max;
   
	/*need disable irq*/
	
	MSDC_ENABLE_CARD_CLOCK(KAL_FALSE);
	
	if (ddr_mode){
		mode=USE_DDR_MODE;
		if (bus_clock>=(msdc_clock >> 2)){
			div=0;
			op_clock=msdc_clock >> 2;
		}
		else
		{
			bus_clock=bus_clock << 1;
			div=(msdc_clock+((bus_clock << 2)-1))/(bus_clock << 2);
			op_clock=(msdc_clock>>2)/div;
			op_clock=op_clock>>1;
		} 
	}
	else 
	{
	    if (bus_clock >=msdc_clock)
        {  
            //dbg_print("entry bus_clock==msdc_clock\r\n");
	    	mode =USE_MSDC_SRC_CK;
		    div=0;
		    op_clock=msdc_clock;
        }
        else
        {
            mode =USE_CLOCK_DIV;
    		if (bus_clock >= (msdc_clock >> 1))
    		{
    		    
    			div=0;
    			op_clock=msdc_clock>>1;
                //dbg_print("entry bus_clock >= (msdc_clock>>1),op_clock=%d\r\n",op_clock);
    		} else {
    		    
        		div=(msdc_clock+((bus_clock << 2)-1))/(bus_clock << 2);
        		op_clock=(msdc_clock >> 2)/div;
                //dbg_print("entry bus_clock <(msdc_clock>>1),bus_clock=%d ,op_clock=%d,msdc_clock=%d\r\n",bus_clock,op_clock,msdc_clock);
    		}
        }
	}
	
	gMSDC_Handle->op_clock=op_clock;
	gMSDC_Handle->msdc_clock=msdc_clock;
    //dbg_print("op_clock=%d ,msdc_clock=%d,div=%x\r\n",op_clock,msdc_clock,div);
	BitFieldWrite32((kal_uint32 *)MSDC_CFG, mode, MSDC_CFG_CKMOD);
	BitFieldWrite32((kal_uint32 *)MSDC_CFG,div,MSDC_CFG_CKDIV);
	if (MSDC_TIMEOUT_WAIT((MSDC_Reg32(MSDC_CFG)&MSDC_CFG_CKSTB),500))
	{
		MSDC_ERR("[MSDC][%s %d]wait clock stable 500ms,then timeout \r\n",__FUNCTION__,__LINE__);
		return MSDC_ERROR;
	}
    //dbg_print("MSDC_CFG=%x\r\n",MSDC_Reg32(MSDC_CFG));
	
	/*open irq*/
    MSDC_CRIT("[MSDC][%s %d] SET_CLK(%dkHz): SCLK(%dkHz) MODE(%d) DDR(%d) DIV(%d)\r\n",
           __FUNCTION__,__LINE__, bus_clock / 1000, op_clock / 1000, mode, ddr_mode, div);
           
	MSDC_ENABLE_CARD_CLOCK(KAL_TRUE);
    return MSDC_OK;

}

kal_uint32  uffs(kal_uint32 x)
{
	kal_uint32 r=1;
	if (!x)
	{
		return 0	;
	}
	if (!(x&0xffff))
	{
		x>>=16;
		r+=16;
	}
	if (!(x&0xff))
	{
		x>>=8;
		r+=8;
	}
	if (!(x&0xf))
	{
		x>>=4;
		r+=4;
	}
	if (!(x&0x3))
	{
		x>>=2;
		r+=2;
	}
	if (!(x&0x1))
	{
		x>>=1;
		r+=1;
	}
	return r;
}


void msdc_sleep(kal_uint32 ticks)
{
   if ((kal_query_systemInit() == KAL_TRUE)
    #ifdef  __TST_WRITE_TO_FILE__ 			/*error recording: considering error recording additionally*/
                || (KAL_TRUE == INT_QueryExceptionStatus())
    #endif
    #ifndef __MTK_TARGET__
                || KAL_TRUE == FTL_isPollingMode()
    #endif                
      )
    {
        MSDC_GPTI_BusyWait(ticks*5);
    }
    else
    {
        kal_sleep_task(ticks);
    } 
}
/*************************************************************************
* FUNCTION
*  MSDC_SetClockSource
*
* DESCRIPTION
*
* PARAMETERS
*	type: the desired operating clock source
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
#if (CHIP_VER == 0)
void MSDC_SetClockSource(T_MSDC_CLK_TYPE type)
{
    kal_uint32 orig_val;
       // 3'b000: 26MHz
	// 3'b001: 40MHz
	// 3'b010: 50MHz
	// 3'b011: 60MHz
	// 3'b100: 69MHz
	// 3'b101: 80MHz
	// 3'b110: 96MHz
	// 3'b111: 100MHz
	#define MSDC_SOURCE_SEL_ADDR (0xBF814004)
    orig_val=MSDC_Reg32(MSDC_SOURCE_SEL_ADDR);
    orig_val=orig_val&(~0x7);
	switch (type)
	{
		case SRC_26M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_26M);
			gMSDC_Handle->msdc_clock=26000000;
			gMSDC_Handle->op_clock_max = 13000000;
			break;
			
		case SRC_40M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_40M);
			gMSDC_Handle->msdc_clock=40000000;
			gMSDC_Handle->op_clock_max = 20000000;
			break;
		case SRC_50M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_50M);
			gMSDC_Handle->msdc_clock=50000000;
            gMSDC_Handle->msdc_clock=35000000;
			gMSDC_Handle->op_clock_max = 17000000;
			break;
		case SRC_60M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_60M);
			gMSDC_Handle->msdc_clock=60000000;
			gMSDC_Handle->op_clock_max = 30000000;
			break;
		case SRC_69M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_69M);
			gMSDC_Handle->msdc_clock=69000000;
			gMSDC_Handle->op_clock_max = 35000000;
			break;
		case SRC_80M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_80M);
			gMSDC_Handle->msdc_clock=80000000;
			gMSDC_Handle->op_clock_max = 40000000;
			break;
		case SRC_96M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_96M);
			gMSDC_Handle->msdc_clock=96000000;
			gMSDC_Handle->op_clock_max = 48000000;
			break;
		case SRC_100M:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_100M);
			gMSDC_Handle->msdc_clock=100000000;
			gMSDC_Handle->op_clock_max = 50000000;
			break;
		default:
			MSDC_WriteReg32(MSDC_SOURCE_SEL_ADDR,orig_val|SRC_26M);
			gMSDC_Handle->msdc_clock=26000000;
			MSDC_ERR("[MSDC][%s %d]unknow source CLK %d\r\n",__FUNCTION__,__LINE__,type);
			break;
	}
}
#elif (CHIP_VER == 1)

#define MSDC_OP_SCLK            (200000000)
#define MSDC_MAX_SCLK           (200000000)
void MSDC_SetClockSource(T_MSDC_CLK_TYPE type)
{
    gMSDC_Handle->msdc_clock = MSDC_OP_SCLK;
    gMSDC_Handle->op_clock_max = MSDC_MAX_SCLK;
}

#endif
/*************************************************************************
* FUNCTION
*  MSDC_Check_Card_Present
*
* DESCRIPTION
*	c
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_Check_Card_Present(void)
{
#if !defined(__MSDC_NOT_SUPPORT_HOT_PLUG__)
    return gMSDC_Handle->mIsPresent;
#else
    return KAL_TRUE;
#endif
}
/*************************************************************************
* FUNCTION
*  MSDC_PDNControl
*
* DESCRIPTION
*	Enable power saving or not.
*
* PARAMETERS
*	ON: turn on power saving or not
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
#define MSDC_PDN_EN
void MSDC_PDNControl(kal_bool ON)
{
    if (ON) {
    #if !defined(ATEST_DRV_ENABLE)
    
        #if defined(MSDC_PDN_EN)
        PDN_SET(PDN_MSDC0);
        #endif
    
        SleepDrv_SleepEnable(gMSDC_Handle->msdc_sm_hdl);
    #endif
    }
    else {
    #if !defined(ATEST_DRV_ENABLE)

        #if defined(MSDC_PDN_EN)
        PDN_CLR(PDN_MSDC0);
        #endif
    
        SleepDrv_SleepDisable(gMSDC_Handle->msdc_sm_hdl);
    #endif
    }
}
/*************************************************************************
* FUNCTION
*  MSDC_TimeOutHandler
*
* DESCRIPTION
*	Callback function of gpt timer, and launched while MSDC busy for a while

*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_TimeOutHandler(void *parameter)
{
	gMSDC_Handle->is_timeout=KAL_TRUE;
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,
		EVENT_DMA_DONE|EVENT_XFER_DONE|EVENT_CMD_DONE,KAL_OR);
	MSDC_ERR("[MSDC][%s %d] Enter timeout handler \r\n",__FUNCTION__,__LINE__);
}

/*************************************************************************
* FUNCTION
*  MSDC_GetCardStatus
*
* DESCRIPTION
*	Check currently card is present or not.
*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*	msdc_eint_state
*
*
*************************************************************************/
int MSDC_GetCardStatus(void * DriveData, int AckType)
{
   return 0;
}
/*************************************************************************
* FUNCTION
*  MSDC_SendCardInd
*
* DESCRIPTION
*	Send card indication to the specified module.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_SendCardInd(module_type dest_id, sd_select_enum sel, kal_uint32 msg_id)
{
   
}
/*************************************************************************
* FUNCTION
*  MSDC_GetMediaChanged
*
* DESCRIPTION
*	Check if the media is changed, and clear the status after function call
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
kal_bool MSDC_GetMediaChanged(sd_select_enum sel)
{
    kal_bool ret;

    ENTER_CRITICAL();
    ret = (MSDC_Blk[sel].mIsChanged ) ? (KAL_TRUE) : (KAL_FALSE);
    MSDC_Blk[sel].mIsChanged = KAL_FALSE;
    EXIT_CRITICAL();

    return ret;
}
/*************************************************************************
* FUNCTION
*  MSDC_InvertN
*
* DESCRIPTION
* 	Invert the order of bytes eg,
* 	src: 0x01 0x02, len: 2 => dest: 0x02 0x01
*
* PARAMETERS
*	1. dest: used for store inverted result
*	2. src: source for inverting
*	3. len: bytes for inverting
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. make sure dest has the same size with src.
*************************************************************************/
void MSDC_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
    int i;

    for (i = 0; i < len; i++)
        *(dest + len - 1 - i) = *(src + i);

}
/*************************************************************************
* FUNCTION
*  MSDC_Config_INS_WP
*
* DESCRIPTION
* 	Configure the pull up or pull down status for INS and WP pin
*
* PARAMETERS
*	1. ins: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*	2. wp: MSDC_IOCTRL_PULL_DOWN, MSDC_IOCTRL_PULL_UP
*
* RETURNS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. MT6219 can not be configured to PULL up or down. They are all pulled up by IO.
*	2. MT6218B and MT6217, WP is configured with data lines.
*************************************************************************/
void MSDC_Config_INS_WP(msdc_ioctrl_enum ins, msdc_ioctrl_enum wp)
{

}

void MSDC_InitializeSwitchGpio()
{

	#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
	DCL_HANDLE handle;
#if !defined(__CUST_NEW__)
    GPIO_LDO_SWITCH = MSDC_GetLDO_GPIO();
    GPIO_EXT_SD_LDO_SWITCH = MSDC_GetEXTLDO_GPIO();
    GPIO_SIM_MSDC_SWITCH = MSDC_GetSwitch_GPIO();
#endif
    //GPIO_ModeSetup(GPIO_SIM_MSDC_SWITCH, 0); // gpio mode (replaced by DCL)
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Close(handle);
    //GPIO_InitIO(OUTPUT, GPIO_SIM_MSDC_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Close(handle);
    /*bewlow comes after JRD SIM+ issue on 2007_03_08, use custom setting instead of fix value*/
    //GPIO_WriteIO(MSDC_GetSwitchDirection(), GPIO_SIM_MSDC_SWITCH); // replaced by DCL
    handle = DclGPIO_Open(DCL_GPIO, GPIO_SIM_MSDC_SWITCH);

    if (0 == MSDC_GetSwitchDirection())
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    else if (1 == MSDC_GetSwitchDirection())
        DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
    else
    {
        DclGPIO_Close(handle);
        ASSERT(0);
    }

    DclGPIO_Close(handle);
    /*end of changes of JRD SIM+ issue on 2007_03_08*/
#endif

}

#if !defined(_MSDC_INTERNAL_CD_INT_PIN_)
#if defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
kal_bool EINT_DefaultPolarity = KAL_FALSE;
#else
kal_bool EINT_DefaultPolarity = KAL_FALSE;
#endif
#endif

void MSDC_ConfigPin(kal_uint32 pullmode)
{
	/* 
	 * Note that the CLK signal is a output signal,
	 * and it should be kept to the default value.
	 * that is, PULL DOWN
	 */
    switch (pullmode)
    {
        case MSDC_PIN_PULL_UP:

    	    /* For CMD pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPU_DUAL_IO, 1);
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPD_DUAL_IO, 0);
            /* For DATA pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPU_DUAL_IO, 1);
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPD_DUAL_IO, 0);
            break;
            
        case MSDC_PIN_PULL_DOWN:

    	    /* For CMD pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPU_DUAL_IO, 0);
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPD_DUAL_IO, 1);
            /* For DATA pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPU_DUAL_IO, 0);
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPD_DUAL_IO, 1);
            
            break;
        case MSDC_PIN_PULL_NONE:
        default:
        
    	    /* For CMD pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPU_DUAL_IO, 0);
            MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDPD_DUAL_IO, 0);
            /* For DATA pin */
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPU_DUAL_IO, 0);
            MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATPD_DUAL_IO, 0);
                
            break;
    }
}

/*************************************************************************
* FUNCTION
*  MSDC_SetHostPower
*
* DESCRIPTION
*	enable or disable the power of host
*
* PARAMETERS*
*	on:  KAL_TURE enable the power, KAL_FALSE disable the power
*
* RETURNS
*   
* 	KAL_FALSE: fail to set the power
* 	KAL_TURE:   success to set the power     
* 
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
kal_bool MSDC_SetHostPower(kal_bool on)
{
	kal_bool ret = KAL_TRUE;
	
	return ret;
}

#if (CHIP_VER == 0)
/*************************************************************************
* FUNCTION
*  MSDC_SetVddPower
*
* DESCRIPTION
*	enable or disable the power of host
*
* PARAMETERS*
*	on:   KAL_TURE enable the power, KAL_FALSE disable the power
*	volt:  the voltage of vdd  3300 mean 3.3v
* RETURNS
*   
* 	KAL_FALSE: fail to set the power
* 	KAL_TURE:   success to set the power     
* 
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
kal_bool MSDC_SetVddPower(kal_bool on,kal_uint32 volt)
{
	kal_bool ret =KAL_TRUE;
	if (on)
	{
		if (volt == 3300)
		{
			MSDC_ConfigPin(MSDC_PIN_PULL_UP);
		}
		else
		{
			ret = KAL_FALSE;
		}
	}
	else
	{
		MSDC_ConfigPin(MSDC_PIN_PULL_DOWN);
	}
	return ret;
}

/*************************************************************************
* FUNCTION
*  MSDC_SetSignalPower
*
* DESCRIPTION
*	enable or disable the power of host
*
* PARAMETERS*
*	on:  KAL_TURE enable the power, KAL_FALSE disable the power
*	volt: the voltage of signal , 3300 mean 3.3v  ,1800 mean 1.8v
* RETURNS
*   
* 	KAL_FALSE: fail to set the power
* 	KAL_TURE:   success to set the power     
* 
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
/*
	CARD_PWR 1   LEVEL_PWR33 0             1.8v
	CARD_PWR 1   LEVEL_PWR33 1		3.3v
	CARD_PWR0						0v
*/
#define MSDC_CARD_PWR		26
#define MSDC_LEVEL_PWR33		27
kal_bool MSDC_SetSignalPower(kal_bool on,kal_uint32 volt)
{
	DCL_HANDLE handle;
	kal_bool ret =KAL_TRUE;
	if (on)
	{
		handle = DclGPIO_Open(DCL_GPIO, MSDC_CARD_PWR);
        DclGPIO_Control(handle, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    	DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
		//DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
		
    		DclGPIO_Close(handle);
		if (volt == 3300)
		{
			handle = DclGPIO_Open(DCL_GPIO, MSDC_LEVEL_PWR33);
            DclGPIO_Control(handle, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
	    	DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
			//DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
			
	    	DclGPIO_Close(handle);
			MSDC_CRIT("[MSDC][%s %d]set signal power to 3.3v\r\n",__FUNCTION__,__LINE__);
            gMSDC_Handle->signal_volt=3300;
		}
		else if (volt ==1800)
		{
			handle = DclGPIO_Open(DCL_GPIO,MSDC_LEVEL_PWR33);
            DclGPIO_Control(handle, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
	   		DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
			//DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
			
	   		DclGPIO_Close(handle);
			MSDC_CRIT("[MSDC][%s %d]set signal power to 1.8v\r\n",__FUNCTION__,__LINE__);
            gMSDC_Handle->signal_volt=1800;
		} 
		else
		{
			MSDC_ERR("[MSDC][%s %d]unknow signal power %d v\r\n",__FUNCTION__,__LINE__,volt);
			ret = KAL_FALSE;
		}
	}
	else
	{
		/*set signal volt to 0v*/
		handle = DclGPIO_Open(DCL_GPIO, MSDC_CARD_PWR);
        DclGPIO_Control(handle, GPIO_CMD_SET_OWNERSHIP_TO_MD, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    	DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
		//DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
		
   		DclGPIO_Close(handle);
		MSDC_CRIT("[MSDC][%s %d]set signal power to 0v\r\n",__FUNCTION__,__LINE__);
        gMSDC_Handle->signal_volt=0;
	}
		
	return ret;
}

#elif (CHIP_VER == 1)

#define LDO_VMC             0
#define LDO_VMCH            1
#define LDO_VIO18_PMU       2

static kal_uint32 g_msdc0_io = PMU_VOLT_03_300000_V;
static kal_uint32 g_msdc0_card = PMU_VOLT_03_300000_V;

static kal_uint32 hwPowerOn(kal_uint32 powerID, PMU_VOLTAGE_ENUM powerVolt) 
{
    PMU_CTRL_LDO_BUCK_SET_EN pmu_en;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE pmu_volsel;
    DCL_HANDLE handle;

    /* Open PMU handle */
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    
    switch(powerID) {
        case LDO_VMC:
            /* Set enable control */
            pmu_en.mod = VMC;
            pmu_en.enable = 1;

            /* Set voltage */
            pmu_volsel.mod = VMC;
            pmu_volsel.voltage = powerVolt;

            DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmu_volsel);
            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        case LDO_VMCH:
            /* Set enable control */
            pmu_en.mod = VMCH;
            pmu_en.enable = 1;

            /* Set voltage */
            pmu_volsel.mod = VMCH;
            pmu_volsel.voltage = powerVolt;

            DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmu_volsel);
            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        default:
        break;
    }

    /* Close PMU handle */
    DclPMU_Close(handle);
    
    return 1;
}

static kal_uint32 hwPowerDown(kal_uint32 powerID) 
{
    PMU_CTRL_LDO_BUCK_SET_EN pmu_en;
    DCL_HANDLE handle;

    /* Open PMU handle */
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

    switch(powerID) {
        case LDO_VMC:
            /* Set enable control */
            pmu_en.mod = VMC;
            pmu_en.enable = 0;

            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
        break;

        case LDO_VMCH:
            /* Set enable control */
            pmu_en.mod = VMCH;
            pmu_en.enable = 0;

            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        default:
        break;
    }

    /* Close PMU handle */
    DclPMU_Close(handle);

    return 1;
}

static kal_uint32 msdc_ldo_power(kal_uint32 on, kal_uint8 powerId, 
    PMU_VOLTAGE_ENUM powerVolt, kal_uint32 *status)
{
    if (on) { // want to power on
        if (*status == 0) {  // can power on 
            MSDC_CRIT("msdc LDO<%s> power on<%d>\r\n", 
                powerId ? "VMCH" : "VMC", powerVolt);     

            hwPowerOn(powerId, powerVolt);
            
            *status = powerVolt;             
        } else if (*status == powerVolt) {
            MSDC_CRIT("msdc LDO<%s><%d> power on again!\r\n", 
                powerId ? "VMCH" : "VMC", powerVolt);    
        } else { // for sd3.0 later
            MSDC_CRIT("msdc LDO<%s> change<%d> to <%d>\r\n", 
                powerId ? "VMCH" : "VMC", *status, powerVolt);

            hwPowerDown(powerId);
            hwPowerOn(powerId, powerVolt);
            
            *status = powerVolt;
        }
    } else {  // want to power off
        if (*status != 0) {  // has been powerred on
            MSDC_CRIT("msdc LDO<%s> power off\r\n", powerId ? "VMCH" : "VMC");   

            hwPowerDown(powerId);
            
            *status = 0;
        } else {
            MSDC_CRIT("LDO<%s> not power on\r\n", powerId ? "VMCH" : "VMC");    
        }                
    }  
    
    return 0;          
}

void msdc_set_smt(kal_bool clk, kal_bool cmd, kal_bool dat)
{
    clk &= 0xF;
    cmd &= 0xF;
    dat &= 0xF;
    
    /* For CLK pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKSMT, clk);
    /* For CMD pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDSMT, cmd);
    /* For DATA pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATSMT, dat);
}

void msdc_set_slew_rate(int clk,int cmd, int dat)
{
    clk &= 0x1;
    cmd &= 0x1;
    dat &= 0x1;
    
    /* For CLK pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKSR, clk);
    /* For CMD pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDSR, cmd);
    /* For DATA pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATSR, dat);
}

void msdc_set_rdsel(kal_bool clk, kal_bool cmd, kal_bool dat)
{
    clk &= 0xF;
    cmd &= 0xF;
    dat &= 0xF;
    
    /* For CLK pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKRDSEL, clk);
    /* For CMD pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDRDSEL, cmd);
    /* For DATA pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATRDSEL, dat);
}

void msdc_set_tdsel(kal_bool clk, kal_bool cmd, kal_bool dat)
{
    clk &= 0xF;
    cmd &= 0xF;
    dat &= 0xF;
    
    /* For CLK pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKTDSEL, clk);
    /* For CMD pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDTDSEL, cmd);
    /* For DATA pin */
    MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATTDSEL, dat);
}

void msdc_set_driving(struct msdc_cust *hw, kal_bool sd_18)
{
    if (sd_18) {
        /* For CLK pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKDRV, hw->io_clk.io_drv_18);
        /* For CMD pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDDRV, hw->io_cmd.io_drv_18);
        /* For DATA pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATDRV, hw->io_dat.io_drv_18);
    } else {
        /* For CLK pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL0, MSDC_PAD_CTL0_CLKDRV, hw->io_clk.io_drv_33);
        /* For CMD pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL1, MSDC_PAD_CTL1_CMDDRV, hw->io_cmd.io_drv_33);
        /* For DATA pin */
        MSDC_SET_FIELD(MSDC_PAD_CTL2, MSDC_PAD_CTL2_DATDRV, hw->io_dat.io_drv_33);
    }

}

int msdc_io_init()
{
    struct msdc_cust *pmsdc_cust = NULL;

    pmsdc_cust = &msdc_cap;

    if (!pmsdc_cust) {
        MSDC_ERR("<%s> : Invalid host ID!\r\n", __FUNCTION__);
        goto exit;
    }

    /* RDSEL Init */
    msdc_set_rdsel(pmsdc_cust->io_clk.rdsel, pmsdc_cust->io_cmd.rdsel,
                    pmsdc_cust->io_dat.rdsel);
    
    /* TDSEL Init */
    msdc_set_tdsel(pmsdc_cust->io_clk.tdsel, pmsdc_cust->io_cmd.tdsel,
                    pmsdc_cust->io_dat.tdsel);
                    
    /* SMTen Init */
    msdc_set_smt(pmsdc_cust->io_clk.smten, pmsdc_cust->io_cmd.smten,
                    pmsdc_cust->io_dat.smten);

    /* Slew Rate Init */
    msdc_set_slew_rate(pmsdc_cust->io_clk.slew, pmsdc_cust->io_cmd.slew,
                        pmsdc_cust->io_dat.slew);
                    
    /* IO driving Init */
    msdc_set_driving(pmsdc_cust, 0);

exit:

    return 1;
}

void msdc_pin_init()
{
    /* Pin config for MSDC0 */
#if defined(_MSDC_INTERNAL_CD_INT_PIN_)
    /* Set to MSDC function(INS and WP) */
    IOMUX_set_module_func(0, sel_msdc0p_0);
#else
    /* Set GPIO/EINT function, both for INS and WP */
    IOMUX_set_module_func(4, sel_msdc0p_0);

    #ifdef ATEST_DRV_MSDC
    GPIO_init();
    EINT_Setting_Init();
    #endif
    
#endif

    IOMUX_set_module_func(0, sel_msdc0p_1);
    IOMUX_set_module_func(0, sel_msdc0p_2);
    
    return;
}

kal_bool MSDC_SetVddPower(kal_bool on, kal_uint32 volt)
{
	kal_bool ret =KAL_TRUE;

	if (on)
	    MSDC_ConfigPin(MSDC_PIN_PULL_UP);
	    
	if (volt == 3300)
	{
		msdc_ldo_power(on, LDO_VMCH, PMU_VOLT_03_300000_V, &g_msdc0_card);
	}
	else
	{
	    MSDC_ERR("[MSDC][%s %d]unknow signal power %d v\r\n", 
	        __FUNCTION__, __LINE__, volt);

		ret = KAL_FALSE;
	}

	if (!on)
	    MSDC_ConfigPin(MSDC_PIN_PULL_UP);
		
	return ret;
}

kal_bool MSDC_SetSignalPower(kal_bool on,kal_uint32 volt)
{
	kal_bool ret =KAL_TRUE;
	if (volt == 3300)
	{
		msdc_ldo_power(on, LDO_VMC, PMU_VOLT_03_300000_V, &g_msdc0_io);
		msdc_set_driving(&msdc_cap, 0);
	}
	else if (volt ==1800)
	{
        msdc_ldo_power(on, LDO_VMC, PMU_VOLT_01_800000_V, &g_msdc0_io);
        msdc_set_driving(&msdc_cap, 1);
	} 
	else
	{
	    MSDC_ERR("[MSDC][%s %d]unknow signal power %d v\r\n", 
	        __FUNCTION__, __LINE__, volt);
	        
		ret = KAL_FALSE;
	}
		
	return ret;
}
#endif

/*************************************************************************
* FUNCTION
*  MSDC_SetAllPower
*
* DESCRIPTION
*	enable or disable the power of host\Vdd\signal
*
* PARAMETERS*
*
* RETURNS
*   
* KAL_FALSE: fail to set the power
* KAL_TURE:   success to set the power     
* 
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
kal_bool MSDC_SetAllPower(kal_bool on)
{
	kal_bool ret=KAL_TRUE;
	
	if (on)
	{
		MSDC_SetHostPower(on);
		MSDC_SetVddPower(on,gMSDC_Handle->vdd_volt);
		MSDC_SetSignalPower(on,gMSDC_Handle->signal_volt);
	}
	else
	{
		MSDC_SetSignalPower(on,gMSDC_Handle->signal_volt);
		MSDC_SetVddPower(on,gMSDC_Handle->vdd_volt);
		MSDC_SetHostPower(on);
		
	}
	return ret;
	
}

void power_cycle(kal_uint32 interval_ticks)
{
    MSDC_SetVddPower(0,gMSDC_Handle->vdd_volt);
    msdc_sleep(interval_ticks);
    MSDC_SetVddPower(1,gMSDC_Handle->vdd_volt);
}

/*************************************************************************
* FUNCTION
*  MSDC_SetBusWidth
*
* DESCRIPTION
*	set the bus width to 1 ,4 8
*
* PARAMETERS*
*	bus_width :   set to 1 ,4 ,8
* RETURNS     
* 
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
void MSDC_SetBusWidth(SD_BITWIDTH bus_width)
{
	kal_uint32 val;
	val=MSDC_Reg32(SDC_CFG)&(~SDC_CFG_BUSWIDTH);
	switch(bus_width)
	{
	default:
	case BIT_1W:
		val |=(MSDC_BUS_1BITS << 16);
        gMSDC_Handle->bus_width=1;
		break;
	case BIT_4W:
		val |=(MSDC_BUS_4BITS <<16);
        gMSDC_Handle->bus_width=4;
		break;
    case BIT_8W:
        val |=(MSDC_BUS_8BITS<<16);
        gMSDC_Handle->bus_width=8;
        break;
	}
	MSDC_WriteReg32(SDC_CFG,val);

	MSDC_CRIT("[MSDC][%s %d]Set to %d-bit bus width\r\n", __FUNCTION__, 
	    __LINE__, gMSDC_Handle->bus_width);
}

void MSDC_FatalErrorHandle()
{
	/*reset msdc*/
	MSDC_RESET();
	/*stop dma*/
	MSDC_STOP_DMA();
	/*clear fifo*/
	MSDC_CLR_FIFO_EX();
	/*clear ints*/
	MSDC_CLR_INT();
	/**/
}

 kal_uint32 MSDC_PollInts(kal_uint32 int_mask,kal_uint32 timeout_ms)
{
	kal_uint32 intsts;
	if (!MSDC_TIMEOUT_WAIT((MSDC_Reg32(MSDC_INT)&int_mask),timeout_ms))
	{
			intsts=MSDC_Reg32(MSDC_INT);
			MSDC_WriteReg32(MSDC_INT,intsts&int_mask);
			return intsts&int_mask;
	}

	MSDC_ERR("[MSDC][%s %d]poll INT %d, SW timeout\r\n",__FUNCTION__,__LINE__,timeout_ms);
	return 0;
}
/*************************************************************************
* FUNCTION

*  MSDC_Initialize
*
* DESCRIPTION
*	Initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*
*
* RETURNS
*  1: initailized failed
*  0: successful
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
extern kal_semid dualMsdcArb;

void MSDC_Probe (void)
{
    if (gMSDC_Handle->mIsProbeMSDC)
        return;

    /* PDN disable first */
    MSDC_PDNControl(KAL_FALSE);
    
    #if (CHIP_VER == 1)
    msdc_io_init();
    #endif
    
    /*check card present or not*/
#if defined(MSDC_HOTPLUG_EN)
#if defined(_MSDC_INTERNAL_CD_INT_PIN_)
    if (MSDC_Reg32(MSDC_PS)&MSDC_PS_CDSTS)
        gMSDC_Handle->mIsPresent=KAL_FALSE;
    else
        gMSDC_Handle->mIsPresent=KAL_TRUE;
#else       /* _MSDC_INTERNAL_CD_INT_PIN_ */
    {
    DCL_HANDLE handle;

    GPIO_CTRL_READ_T data;
    
    /* when use EINT for card detect,get the status */
    handle = DclGPIO_Open(DCL_GPIO, MSDC_INS_GPIO);
    DclGPIO_Control(handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&data);

    if (data.u1IOData)
        gMSDC_Handle->mIsPresent = KAL_FALSE;
    else
        gMSDC_Handle->mIsPresent = KAL_TRUE;

    DclGPIO_Close(handle);
    }
#endif
#else       /* MSDC_HOTPLUG_EN */
    gMSDC_Handle->mIsPresent = KAL_TRUE;
#endif
    MSDC_CRIT("[MSDC][%s %d]Card is %s\r\n",__FUNCTION__,__LINE__,
        gMSDC_Handle->mIsPresent ? "Present" : "Not Present");

    /* If card is not exist, step over the INIT flow */
    if (gMSDC_Handle->mIsPresent)
        gMSDC_Handle->mIsProbeMSDC = KAL_TRUE;
    else {
        gMSDC_Handle->mIsProbeMSDC = KAL_FALSE;
        goto exit;
    }

	/*set MSDC as the controller of SD*/
	MSDC_SET_FIELD(MSDC_CFG, MSDC_CFG_MODE, 1);
	
	/*reset MSDC ,clear FIFO*/
	MSDC_RESET();
	MSDC_CLR_FIFO_EX();
	MSDC_DEBUG("[MSDC][%s %d]reset MSDC,clear FIFO\r\n",__FUNCTION__,__LINE__);
	
    /*write crc timeout detection*/
    MSDC_SetData32(MSDC_PATCH_BIT0,1<<30,(1<<30));	
    /*Configure To Default Data Timeout */
    MSDC_SetData32(SDC_CFG,SDC_CFG_DTOC,(DEFAULT_DTOC<<24));
    /*set bus width to 1 */
    MSDC_SetBusWidth(BIT_1W);

    /* Tuning parameters INIT */
    msdc_tune_init();

exit:
    MSDC_PDNControl(KAL_TRUE);

    /* Shut card power */
	MSDC_SetVddPower(KAL_FALSE, gMSDC_Handle->vdd_volt);

	/* Defaultly turn VMC to 1.8V to save power */
	MSDC_SetSignalPower(KAL_TRUE, gMSDC_Handle->signal_volt);
}

void MSDC_Initialize(void)
{    
    /* INIT MSDC debug flag */
    MSDC_SetDebugLevel(K_NOTICE);

	MSDC_CRIT("[MSDC][%s %d]Start init MSDC...\r\n",__FUNCTION__,__LINE__);

 	/*check MSDC is initalized or not */
	if (gMSDC_Handle->mIsInitMSDC)
		return;

    gMSDC_Handle->mIsProbeMSDC = 0;
    
    /*init gSD*/
	kal_mem_set(gSD,0,sizeof(T_SDC_HANDLE));
	
	/* Set voltage of single and card power */
	gMSDC_Handle->signal_volt = 1800;
	gMSDC_Handle->vdd_volt = 3300;

    #if !defined(ATEST_DRV_ENABLE)
    /* Get Sleep handler */
	gMSDC_Handle->msdc_sm_hdl = SleepDrv_GetHandle();
	MSDC_CRIT("[MSDC][%s %d]MSDC Slp Handler: %d\r\n",
	    __FUNCTION__, __LINE__, gMSDC_Handle->msdc_sm_hdl);
	#endif
	
	/*set clock source */
	MSDC_SetClockSource(SRC_80M);

    #if (CHIP_VER == 1)
    /* Pin MUX setting and IO settings */
    msdc_pin_init();
    #endif
	
    /*get gpt handle*/
    if (gMSDC_Handle->gpt_handle==0)
        MSDC_GPTI_GetHandle(&gMSDC_Handle->gpt_handle);

    /*clear and disable all interrupt*/
    MSDC_ClearBits32(MSDC_INTEN,MSDC_Reg32(MSDC_INTEN));
    MSDC_WriteReg32(MSDC_INT,MSDC_Reg32(MSDC_INT));
    
    /* INIT the MSDC related registers */
    MSDC_Probe();
    
    /*init  INT handle*/
    MSDC_INT_Init();

    /*set the function support by host*/
    gMSDC_Handle->host_support.function1=FUN1_SDR12_DS|FUN1_SDR25_HS|FUN1_SDR50|FUN1_SDR104|FUN1_DDR50;
    gMSDC_Handle->host_support.function2=FUN2_DEFAULT;
    gMSDC_Handle->host_support.function3=FUN3_TYPE_B;
    gMSDC_Handle->host_support.function4=FUN4_200MA|FUN4_400MA|FUN4_600MA|FUN4_800MA;

    gMSDC_Handle->mIsInitMSDC = KAL_TRUE;
    
    MSDC_DEBUG("[MSDC][%s %d]finish init MSDC\r\n",__FUNCTION__,__LINE__);
}

/*************************************************************************
* FUNCTION
*  MSDC_DeInit
*
* DESCRIPTION
*	De-initialize the MS/SD host controller, called only once at drv_init
*
* PARAMETERS*
*
* RETURNS
*
* GLOBALS AFFECTED
*
*************************************************************************/
void MSDC_DeInit(void)
{
    /* Shutdown Card power Only */
	MSDC_SetVddPower(KAL_FALSE, gMSDC_Handle->vdd_volt);
    
    gMSDC_Handle->mIsProbeMSDC = KAL_FALSE;
    gMSDC_Handle->mIsInitialized = KAL_FALSE;

    return;
}


#ifdef  __TST_WRITE_TO_FILE__
/*error recording: add this function to do MSDC reset when error recording*/
void MSDC_ErrorRecordingReset()
{

   	
}
#endif

#ifndef DRV_LSD
/*************************************************************************
* FUNCTION
*  BitFieldWrite32
*
* DESCRIPTION
*	Write src to dest at mask position
*
* PARAMETERS
*	dest: destination to be update
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
// Note: mask must be a continuous area during 32bits. eg,
// dest : 00A30000 , src : BF, mask : 0000BF00.
// after BitFieldCpy, dest : 00A3BF00, copy src to dest at mask position.
void BitFieldWrite32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
    kal_uint8 bit_pos;
    kal_uint32 tmp;

    bit_pos = 0;
    tmp = MSDC_Reg32(dest);

    // get bit positoin
    while (!((mask >> bit_pos++) & 1));

    //use mask clear the corresponding area
    tmp &= ~mask;
    //shift src to the corresponding positiion
    src <<= (bit_pos - 1);
    //copy src into destination
    tmp |= src;
    MSDC_WriteReg32(dest, tmp);
}
#endif

#ifdef MSDC_USED_STUFF
/*************************************************************************
* FUNCTION
*  BitFieldRead32
*
* DESCRIPTION
*	read src to dest at mask position
*
* PARAMETERS
*	dest: destination to store
*	src: value to be written
*	mask: bit mask
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/

// Note: mask must ve continuous area during 32 bits.eg,
// src : 00A3BF00, mask : 00FF0000
// after BitFieldRead, dest : A3
void BitFieldRead32(kal_uint32 * dest, kal_uint32 src, kal_uint32 mask)
{
    kal_uint8 bit_pos = 0;

    while (!((mask >> bit_pos++) & 1));

    src &= mask;
    *(kal_uint32 *)dest = src >> (bit_pos - 1);
}
#endif//MSDC_USED_STUFF

// get the bit field value of start_bit with width bits
// note 1) start_bit start from bit 0
//		2) prepare dest with initialized with zeros
//		3) width must less than 32 if using the retrun value as a result
// eg,
// src:00110110, start_bit:2,width:3 => dest:101
void GetBitFieldN(kal_uint8* dest, kal_uint8* src, kal_uint16 start_bit, kal_uint16 width)
{
    int i;
    kal_uint16 bytes, bits;

    //kal_mem_set(dest,0,width/8+1);
    kal_mem_set(dest, 0, (width / 8) + (0 == (width % 8) ? 0 : 1));

    for ( i = 0; i < width; i++)
    {
        bytes = (start_bit + i) / 8;
        bits  = (start_bit + i) % 8;
        *(dest + i / 8) |= (kal_uint8)(((*(src + bytes) >> bits) & 1) << (i % 8));
    }

    /*in MT6238, address of kal_uint32 is checked strictly, and we don't need the return value of this function*/
    /*change it's return type to void*/
    return ;
}

#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
void MSDC_SetLatchTuning(void)
{
    
}
#else
void MSDC_SetIOCONRegDLT(void)
{

}
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)

void msdc_dump_reg(void)
{
    int idx;

    MSDC_CRIT("****** [00]MSDC_CFG       : %x\r\n", MSDC_Reg32(MSDC_CFG));
    MSDC_CRIT("****** [04]MSDC_IOCON     : %x\r\n", MSDC_Reg32(MSDC_IOCON));
    MSDC_CRIT("****** [08]MSDC_PS        : %x\r\n", MSDC_Reg32(MSDC_PS));
    MSDC_CRIT("****** [0C]MSDC_INT       : %x\r\n", MSDC_Reg32(MSDC_INT));
    MSDC_CRIT("****** [10]MSDC_INTEN     : %x\r\n", MSDC_Reg32(MSDC_INTEN));
    MSDC_CRIT("****** [14]MSDC_FIFOCS    : %x\r\n", MSDC_Reg32(MSDC_FIFOCS));
    MSDC_CRIT("****** [18]MSDC_TXDATA    : %x\r\n", MSDC_Reg32(MSDC_TXDATA));
    MSDC_CRIT("****** [1C]MSDC_RXDATA    : --------\r\n");
    MSDC_CRIT("****** [30]SDC_CFG        : %x\r\n", MSDC_Reg32(SDC_CFG));
    MSDC_CRIT("****** [34]SDC_CMD        : %x\r\n", MSDC_Reg32(SDC_CMD));
    MSDC_CRIT("****** [38]SDC_ARG        : %x\r\n", MSDC_Reg32(SDC_ARG));
    MSDC_CRIT("****** [3C]SDC_STS        : %x\r\n", MSDC_Reg32(SDC_STS));
    MSDC_CRIT("****** [40]SDC_RESP0      : %x\r\n", MSDC_Reg32(SDC_RESP0));
    MSDC_CRIT("****** [44]SDC_RESP1      : %x\r\n", MSDC_Reg32(SDC_RESP1));
    MSDC_CRIT("****** [48]SDC_RESP2      : %x\r\n", MSDC_Reg32(SDC_RESP2));
    MSDC_CRIT("****** [4C]SDC_RESP3      : %x\r\n", MSDC_Reg32(SDC_RESP3));
    MSDC_CRIT("****** [50]SDC_BLK_NUM    : %x\r\n", MSDC_Reg32(SDC_BLK_NUM));
    MSDC_CRIT("****** [58]SDC_CSTS       : %x\r\n", MSDC_Reg32(SDC_CSTS));
    MSDC_CRIT("****** [5C]SDC_CSTS_EN    : %x\r\n", MSDC_Reg32(SDC_CSTS_EN));
    MSDC_CRIT("****** [60]SDC_DATCRC_STS : %x\r\n", MSDC_Reg32(SDC_DCRC_STS));
    MSDC_CRIT("****** [70]EMMC_CFG0      : %x\r\n", MSDC_Reg32(EMMC_CFG0));
    MSDC_CRIT("****** [74]EMMC_CFG1      : %x\r\n", MSDC_Reg32(EMMC_CFG1));
    MSDC_CRIT("****** [78]EMMC_STS       : %x\r\n", MSDC_Reg32(EMMC_STS));
    MSDC_CRIT("****** [7C]EMMC_IOCON     : %x\r\n", MSDC_Reg32(EMMC_IOCON));
    MSDC_CRIT("****** [80]SD_ACMD_RESP   : %x\r\n", MSDC_Reg32(SDC_ACMD_RESP));
    MSDC_CRIT("****** [84]SD_ACMD19_TRG  : %x\r\n", MSDC_Reg32(SDC_ACMD19_TRG));
    MSDC_CRIT("****** [88]SD_ACMD19_STS  : %x\r\n", MSDC_Reg32(SDC_ACMD19_STS));
    MSDC_CRIT("****** [90]DMA_SA         : %x\r\n", MSDC_Reg32(MSDC_DMA_SA));
    MSDC_CRIT("****** [94]DMA_CA         : %x\r\n", MSDC_Reg32(MSDC_DMA_CA));
    MSDC_CRIT("****** [98]DMA_CTRL       : %x\r\n", MSDC_Reg32(MSDC_DMA_CTL));
    MSDC_CRIT("****** [9C]DMA_CFG        : %x\r\n", MSDC_Reg32(MSDC_DMA_CFG));
    MSDC_CRIT("****** [A8]DMA_LENGTH     : %x\r\n", MSDC_Reg32(MSDC_DMA_LENGTH));
    MSDC_CRIT("****** [B0]PATCH_BIT0     : %x\r\n", MSDC_Reg32(MSDC_PATCH_BIT0));
    MSDC_CRIT("****** [B4]PATCH_BIT1     : %x\r\n", MSDC_Reg32(MSDC_PATCH_BIT1));
    MSDC_CRIT("****** [E0]SD30_PAD_CTL0  : %x\r\n", MSDC_Reg32(MSDC_PAD_CTL0));
    MSDC_CRIT("****** [E4]SD30_PAD_CTL1  : %x\r\n", MSDC_Reg32(MSDC_PAD_CTL1));
    MSDC_CRIT("****** [E8]SD30_PAD_CTL2  : %x\r\n", MSDC_Reg32(MSDC_PAD_CTL2));
    MSDC_CRIT("****** [EC]PAD_TUNE       : %x\r\n", MSDC_Reg32(MSDC_PAD_TUNE));
    MSDC_CRIT("****** [F0]DAT_RD_DLY0    : %x\r\n", MSDC_Reg32(MSDC_DAT_RDDLY0));
    MSDC_CRIT("****** [F4]DAT_RD_DLY1    : %x\r\n", MSDC_Reg32(MSDC_DAT_RDDLY1));
    MSDC_CRIT("****** [100]MAIN_VERSION  : %x\r\n", MSDC_Reg32(MSDC_VERSION));
    MSDC_CRIT("****** [104]ECO_VERSION   : %x\r\n", MSDC_Reg32(MSDC_ECO_VER));

    for (idx = 0; idx < 26; idx++) {
        MSDC_WriteReg32(MSDC_DBG_SEL, idx);
        MSDC_CRIT("=*=*=* MSDC_DBG_SEL:%d => MSDC_DBG_OUT:%x\r\n",
                                          idx, MSDC_Reg32(MSDC_DBG_OUT));
    }

    MSDC_CRIT("====== MSDC Register and Debug Register Dump End   ======\r\n");
}

#ifdef _MSDC_DMA_
/*************************************************************************
* FUNCTION
*  MSDC_DMAInit
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_DMAInit(void)
{

}
void MSDC_StartDMA(void)
{
	kal_uint32 ints=MSDC_INTEN_XFER_COMPL | MSDC_INTEN_DATTMO | 
	                MSDC_INTEN_DATCRCERR |MSDC_INTEN_DXFER_DONE |
	                MSDC_INTEN_BD_CS_ERR | MSDC_INTEN_GPD_CS_ERR;
	//kal_uint32 ints=MSDC_DAT_INTS;
	kal_uint32 abnormal_ints;
    abnormal_ints=MSDC_Reg32(MSDC_INT)&ints;
	if(0 != abnormal_ints)
	{
		/*error, have irq before we enable it*/
	    MSDC_ERR("[MSDC][%s %d]abnormal irq %x\r\n",__FUNCTION__,__LINE__,abnormal_ints);
		MSDC_WriteReg32(MSDC_INT,abnormal_ints);
	}
	MSDC_SetBits32(MSDC_INTEN, ints);
	MSDC_SET_FIELD(MSDC_DMA_CTL, MSDC_DMA_CTL_START, 1);
    gMSDC_Handle->is_timeout=KAL_FALSE;
	MSDC_START_TIMER(MSDC_DMA_DAT_TMO);
}
SDC_CMD_STATUS MSDC_ConfigDMA(kal_uint32 * buffer,kal_uint32 num,msdc_gpd_t * gpd_ptr,kal_bool isLastBuf)
{
    kal_uint32 dma_ctl_arg;
    #define BURST_8Byte		3
	#define BURST_16Byte	4
	#define BURST_32Byte	5
	#define BURST_64Byte	6
	/*if (gpd_ptr==NULL)
	{
		gMSDC_Handle->error=ERR_ARGUMENT;
		#ifdef MSDC_DEBUG_PRINT
		dbg_print("[MSDC][ERROR][%s %d]gpd_ptr point to zero\r\n",__FUNCTION__,__LINE__);
		#endif
		return ERR_ARGUMENT;
	}*/
	//set to DMA mode
	//BitFieldWrite32((kal_uint32 *)MSDC_CFG, 0, MSDC_CFG_PIO);
	MSDC_ClearBits32(MSDC_CFG,MSDC_CFG_PIO);
	gMSDC_Handle->dma_xfer=1;
	if ((buffer==NULL) && (gpd_ptr != NULL))
	{
        /*use link list based DMA */

        #ifdef MSDC_DMA_CHKSUM_EN
        /*Enable descriptor 's checksum*/
        MSDC_SET_FIELD(MSDC_DMA_CFG, MSDC_DMA_CFG_DECSEN, 1);
        #else
        /*Disable descriptor 's checksum*/
        MSDC_SET_FIELD(MSDC_DMA_CFG, MSDC_DMA_CFG_DECSEN, 0);
        #endif

        /*descriptor mode and burst size=64Bytes*/
        dma_ctl_arg=(BURST_64Byte<<12)|MSDC_DMA_CTL_MODE;
        MSDC_WriteReg32(MSDC_DMA_CTL,dma_ctl_arg);
        /*write DMA start address to GPD's physical address*/
        MSDC_WriteReg32(MSDC_DMA_SA,gpd_ptr);
	}
	else if((buffer != NULL)&& (gpd_ptr == NULL))
	{	
		
		/*use basic DMA*/
		/*burst size\last buffer*/
        dma_ctl_arg = (isLastBuf==KAL_TRUE)? ((BURST_64Byte<<12)|MSDC_DMA_CTL_LASTBUF) : (BURST_64Byte<<12);
		MSDC_WriteReg32(MSDC_DMA_CTL,dma_ctl_arg);
		/*set xfer size*/
		MSDC_WriteReg32(MSDC_DMA_LENGTH,num);
		/*set address*/
		MSDC_WriteReg32(MSDC_DMA_SA,buffer);
	}
    else
    {
        //wrong argument
    }
	return  NO_ERROR;
}
SDC_CMD_STATUS MSDC_WaitDMADone()
{
	kal_uint32 status;
	kal_uint32 ints= MSDC_INTEN_XFER_COMPL | MSDC_INTEN_DATTMO | 
	                MSDC_INTEN_DATCRCERR |MSDC_INTEN_DXFER_DONE |
	                MSDC_INTEN_BD_CS_ERR | MSDC_INTEN_GPD_CS_ERR;

	/*wait DMA done*/
	kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,EVENT_XFER_DONE|EVENT_DMA_DONE,KAL_OR_CONSUME,&status,KAL_SUSPEND);
	MSDC_STOP_TIMER();
    MSDC_DEBUG("[MSDC][%s]msdc_int=%x\r\n",__FUNCTION__,gMSDC_Handle->msdc_int);
	if (gMSDC_Handle->is_timeout)
	{
		MSDC_ERR("[MSDC][%s %d]wait DMA done GPT timeout\r\n",__FUNCTION__,__LINE__);
		msdc_dump_reg();
		gMSDC_Handle->error=MSDC_GPT_TIMEOUT_ERR;
	}
    /*Disable interrupt*/
    MSDC_ClearBits32(MSDC_INTEN,ints);
	/*stop dma*/
	MSDC_STOP_DMA();
	return gMSDC_Handle->error;
}
kal_uint32 MSDC_CheckCardBusy(kal_bool send_stop,kal_uint32 timeout_ms)
{
	kal_uint32 start_time,status;
	kal_uint32 err,count=0;
	start_time = drv_get_current_time(); 
		
	do{
		err=SD_GetStatus(gSD->mRCA, &status);
		if(err)
		{
			break;
		}
		count++;
		if(count%5000==0)
		{
			if(send_stop)
			{
				SD_StopTrans();
			}
		}
	}while((!(status&R1_READY_FOR_DATA_8)||(R1_CURRENT_STATE(status)==7))&&(drv_get_duration_ms(start_time) <=timeout_ms));
	if (!(drv_get_duration_ms(start_time) <=timeout_ms))
	{
		MSDC_ERR("[MSDC][%s %d]card busy timeout\r\n",__FUNCTION__,__LINE__);
		gMSDC_Handle->error=err=ERR_CARD_BUSY_TIMEOUT;
	}
	return err;
}
/************************************************************************
* FUNCTION
*  MSDC_DMATransferFinal_In_Callback
*
* DESCRIPTION
*	Initialize MSDC's DMA
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
#if defined(MSDC_START_DMA_IN_CALLBACK)

void MSDC_DMATransferFinal_In_Callback(void)
{

}

kal_uint32 MSDC_DMATransferFinal(void)
{

}
#endif
/*************************************************************************
* FUNCTION
*  MSDC_DMATransfer
*
* DESCRIPTION
*	MSDC using DAM for data transfer
*
* PARAMETERS
*	adrs: data buffer
*	count: bytes to be transfered
*	isTx: ture for move data from MSDC to data buffer and vise versa
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
extern kal_bool FTL_isPollingMode();
void MSDC_DMATransferFirst( kal_bool isWrite,kal_bool isLinkListBuf)
{
	kal_uint32 * adrs;
	
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,0,KAL_AND);
    if (isLinkListBuf)
    {
        /*configure DMA*/
        MSDC_ConfigDMA(NULL,gMSDC_Handle->total_count,(msdc_gpd_t *)gMSDC_Handle->buf_addr,1);
    }
    else
    {
        adrs=gMSDC_Handle->buf_addr;
    	#ifdef MSDC_CACHED_SUPPORT
    	if (gMSDC_Handle->isRomSpace)
    	{
    		gMSDC_Handle->trans_count=(gMSDC_Handle->total_count > MSDC_UNCACHED_TRANSFER_SIZE) ? (MSDC_UNCACHED_TRANSFER_SIZE) : gMSDC_Handle->total_count;
    		/*copy from upper application buffer*/
    		if (isWrite)
    		{   
    			kal_mem_cpy((void *)msdc_uncachedBuf,(void*)gMSDC_Handle->buf_addr,gMSDC_Handle->trans_count);
    		}
    		adrs=(kal_uint32 *)msdc_uncachedBuf;       
    	}
    	else if (gMSDC_Handle->isCachedBuf)
        {
            //clear cache  
            gMSDC_Handle->trans_count=(gMSDC_Handle->total_count > MSDC_DMA_BURSTLEN_LIMIT) ? (MSDC_DMA_BURSTLEN_LIMIT) : gMSDC_Handle->total_count;
            clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)gMSDC_Handle->buf_addr),CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)gMSDC_Handle->buf_addr,gMSDC_Handle->trans_count));
            Data_Mem_Barrier();
        }  
        else
    	#endif 
    	{
    		gMSDC_Handle->trans_count=(gMSDC_Handle->total_count > MSDC_DMA_BURSTLEN_LIMIT) ? (MSDC_DMA_BURSTLEN_LIMIT) : gMSDC_Handle->total_count;
    	} 
        /*configure DMA*/
        MSDC_ConfigDMA(adrs,gMSDC_Handle->trans_count,NULL,(gMSDC_Handle->total_count==gMSDC_Handle->trans_count));
    }
		
}
#if !defined(MSDC_START_DMA_IN_CALLBACK)
kal_uint32 MSDC_DMATransferFinal(kal_bool isWrite,kal_bool isLinkListBuf)
{
	kal_uint32 status;
	while(1)
	{
		/*start DMA*/
		MSDC_StartDMA();
		/*wait DMA finish*/
		status=MSDC_WaitDMADone();
		if (status!=NO_ERROR)
		{
		    MSDC_ERR("[MSDC][%s %d]INTS<%x>\r\n",__FUNCTION__,__LINE__,gMSDC_Handle->msdc_int);
			goto done;
		}
        if (isLinkListBuf)
        {
            MSDC_DEBUG("[MSDC]link list DMA finish\r\n");
            break;
        }
        else
        {
    		/*copy RX data when use cached buffer*/
    		#ifdef MSDC_CACHED_SUPPORT
    		if (gMSDC_Handle->isCachedBuf)
    		{
    		    /*if (!isWrite)
                        {         
        			    kal_mem_cpy((void *)gMSDC_Handle->buf_addr,(void *)msdc_uncachedBuf,gMSDC_Handle->trans_count);
                        }*/
                 //invalidate_dcache((gMSDC_Handle->buf_addr&~CPU_CACHE_LINE_SIZE_MASK),(gMSDC_Handle->trans_count+CPU_CACHE_LINE_SIZE_MASK)&~CPU_CACHE_LINE_SIZE_MASK);
    		}
    		#endif
    		/*check need do further transfer or not */
    		gMSDC_Handle->total_count-=gMSDC_Handle->trans_count;
    		if (gMSDC_Handle->total_count==0)
    		{
    			gMSDC_Handle->error=NO_ERROR;
    			goto done;
    		}
    		gMSDC_Handle->buf_addr+=gMSDC_Handle->trans_count;
    		MSDC_DMATransferFirst( isWrite,isLinkListBuf);
        }
	}
done:
	
	return status;
}
#endif //!defined(MSDC_START_DMA_IN_CALLBACK)

#endif // DMA

void* GetMsdcHandle(kal_uint8 id)
{
    return (void*)&MSDC_Blk[id];
}

#ifdef R1B_INTERRUPT_MODE
static void MSDC_R1B_Init()
{
    
}
#endif

// ===========================================================
//     MSDC common lock
// ===========================================================

#if !defined(__FUE__) && !defined(__UBL__)

void init_MSDC_lock(PMSDC_LOCK_TAG lock, const kal_char *str)
{
    if (lock->mtd_mutex == NULL)
    {
        strcpy((char *)lock->name, str);
        lock->mtd_mutex = kal_create_mutex((kal_char *)lock->name);
        lock->lock_count = 0;
        lock->owner_id = NULL;
    }
}

static kal_uint8 msdc_lock_user = 0;

void get_MSDC_lock(PMSDC_LOCK_TAG lock)
{
    if (msdc_lock_user > 0)
        ;//ASSERT(0); // init debugging purpose
    else
        msdc_lock_user ++;

    if ( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;

    if (kal_if_hisr() == KAL_TRUE || kal_if_lisr() == KAL_TRUE)
    {
        kal_uint32 retaddr0 = 0;
        GET_RETURN_ADDRESS(retaddr0);
        EXT_ASSERT(0, retaddr0, 0, 0);
    }

    if ( kal_get_current_task() == lock->owner_id )
    {
        force_ASSERT(0 != lock->lock_count, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count++;
    }
    else
    {
        if (lock->mtd_mutex == NULL)
        {
            init_MSDC_lock(lock, (const kal_char *)lock->name);
        }

        kal_take_mutex(lock->mtd_mutex);
     //   lock->owner_id = kal_get_task_self_id();
     		lock->owner_id = kal_get_current_task();
        lock->lock_count++;
    }
}

void free_MSDC_lock(PMSDC_LOCK_TAG lock)
{
    if (msdc_lock_user != 1)
        ;//ASSERT(0); // init debugging purpose
    else
        msdc_lock_user --;

    if ( kal_query_systemInit() || INT_QueryExceptionStatus() )
        return;

    if ( kal_get_current_task() == lock->owner_id )
    {
        force_ASSERT(lock->lock_count > 0, lock->lock_count, (kal_uint32)lock->owner_id, (kal_uint32)lock->mtd_mutex);
        lock->lock_count--;

        if (0 == lock->lock_count)
        {
            lock->owner_id = NULL;

            if (lock->mtd_mutex != NULL)
                kal_give_mutex(lock->mtd_mutex);
        }
    }
    else
    {
        force_ASSERT(0, (kal_uint32)lock->owner_id, (kal_uint32)kal_get_current_task(), (kal_uint32)lock->mtd_mutex);
    }
}

#else /* __FUE__, __UBL__ */

//#define init_MSDC_lock(x)

//#define get_MSDC_lock(x)

//#define free_MSDC_lock(x)

#endif /* !defined(__FUE__) && !defined(__UBL__) */

#ifdef _MSDC_INT_

#ifdef USE_INT26_CARD_DETECTION
void MSDC_CardDetect_LISR(void)
{
    
}
#endif //USE_INT26_CARD_DETECTION


#ifdef DRV_LSD
kal_uint32 MSDC_CARD_INSERT_COUNTER, MSDC_CARD_REMOVE_COUNTER;
kal_uint32 notifiedFMT;//this variable is to sync the state, since we only allow FMT get disk infor to be the first operation that access SD


void MSDC_LSD_HISR(void)
{
    

}

void MSDC_unsealMountOperation(void)
{
    /*notifiedFMT may be modified by FMT and MMI tasks, but it is no need to protect this, any task that preempt FMT just get mount fail*/
    if (1 == notifiedFMT) /*FMT may call this function no matter card exits or not*/
    {
        notifiedFMT = 2;
    }

}
#endif

#if !defined(_MSDC_INTERNAL_CD_INT_PIN_)
void MSDC_CD_Entry()
{
    /* Reverse the polarity */
    cardDetectionEINTPolarity = !cardDetectionEINTPolarity;
    EINT_Set_Polarity(MSDC_EINT_NUM, cardDetectionEINTPolarity); 

    gMSDC_Handle->mIsChanged=KAL_TRUE;
    
    /*memory card insertion\removal */
    if (!cardDetectionEINTPolarity)
    {
        gMSDC_Handle->mIsPresent=KAL_FALSE;
        gMSDC_Handle->mIsInitialized=KAL_FALSE;
    #ifdef MSDC_MUST_RECORD_PLUGOUT
        if (KAL_FALSE == gMSDC_Handle->mIsPresent)
            gMSDC_Handle->MSDC_everPlugOut = KAL_TRUE;
    #endif//MSDC_MUST_RECORD_PLUGOUT

        MSDC_CRIT("[MSDC]Card Remove(EINT)\r\n");
        MSDC_DeInit();
    }
    else
    {
        gMSDC_Handle->mIsPresent=KAL_TRUE;
        gMSDC_Handle->mIsInitialized=KAL_FALSE;

        MSDC_CRIT("[MSDC]Card Insert(EINT)\r\n");
        MSDC_Probe();
    }
}
#endif

/*************************************************************************
* FUNCTION
*  MSDC_INT_Init
*
* DESCRIPTION
*	Initialize MSDC's interrupt
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_INT_Init(void)
{
	/*create events group*/
	gMSDC_Handle->MSDC_Events=kal_create_event_group("MSDC Event");
	/*register HISR*/
	DRV_Register_HISR(DRV_MSDC_HISR_ID,MSDC_HISR_Entry);
	/*register LISR*/
	IRQ_Register_LISR(MD_IRQID_MSDC0,MSDC_LISR,"MSDC ISR");
	IRQSensitivity(MD_IRQID_MSDC0,LEVEL_SENSITIVE);
	IRQUnmask(MD_IRQID_MSDC0);
	/*clear IRQ */
	MSDC_WriteReg32(MSDC_INT,MSDC_Reg32(MSDC_INT));

	/*register IRQ for card detect*/
	/*enable card detect interrupt*/
#if defined(_MSDC_INTERNAL_CD_INT_PIN_)
    /*enable card detect*/
    MSDC_SET_FIELD(MSDC_PS, MSDC_PS_CDEN, 1);
    MSDC_SET_FIELD(MSDC_INTEN, MSDC_INTEN_CDSC, 1);
#else

    /* Polarity setting, default triggered by low level */
    cardDetectionEINTPolarity = EINT_DefaultPolarity;

    /* SW debounce time is 300ms */
    MSDC_debounceTime=30;
    
    EINT_Mask(MSDC_EINT_NUM);    //need check the MSDC_EINT_NO ,unused current time

    /* Level trigger */
    EINT_Set_Sensitivity(MSDC_EINT_NUM, KAL_FALSE);
    
    EINT_Registration(MSDC_EINT_NUM,KAL_TRUE,cardDetectionEINTPolarity,MSDC_CD_Entry,KAL_TRUE);
    EINT_SW_Debounce_Modify(MSDC_EINT_NUM,MSDC_debounceTime);
    EINT_UnMask(MSDC_EINT_NUM);
    
#endif
}
void MSDC_LISR(void)
{
	/*Mask IRQ*/
	IRQMask(MD_IRQID_MSDC0);
	/*save IRQ information*/
	gMSDC_Handle->msdc_int=MSDC_Reg32(MSDC_INT);
	/*call hisr*/
	drv_active_hisr(DRV_MSDC_HISR_ID);
	
}

void MSDC_DatIrqHandle(kal_uint32 intsts)
{
	if (intsts & MSDC_INT_XFER_COMPL){
		gMSDC_Handle->error=NO_ERROR;
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_XFER_DONE,KAL_OR);
	}
	else if (intsts & MSDC_INT_DXFER_DONE)
	{
		
		gMSDC_Handle->error=NO_ERROR;
		kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_DMA_DONE,KAL_OR);
	}
	else
	{
		
		/*mean some error */
		if (intsts & MSDC_INT_DATCRCERR)
		{
			gMSDC_Handle->error=ERR_DAT_CRCERR;
			MSDC_ERR("[MSDC][%s %d]CMD%d DMA DAT CRCERR!\r\n",__FUNCTION__, 
			    __LINE__, gMSDC_Handle->cmd & 0x3F);
		}
		else if (intsts & MSDC_INT_DATTMO)
		{
			gMSDC_Handle->error=ERR_DAT_TIMEOUT;
			MSDC_ERR("[MSDC][%s %d]CMD%d DMA DAT TMO!\r\n",__FUNCTION__, 
			    __LINE__, gMSDC_Handle->cmd & 0x3F);
		} else if (intsts & MSDC_INT_BD_CS_ERR) {
		
			gMSDC_Handle->error = ERR_DAT_TIMEOUT;
			MSDC_ERR("[MSDC][%s %d]CMD%d DMA BD checksum ERR!\r\n",__FUNCTION__, 
			    __LINE__, gMSDC_Handle->cmd & 0x3F);
		} else if (intsts & MSDC_INT_GPD_CS_ERR) {
		
			gMSDC_Handle->error = ERR_DAT_TIMEOUT;
			MSDC_ERR("[MSDC][%s %d]CMD%d DMA GPD checksum ERR!\r\n",__FUNCTION__, 
			    __LINE__, gMSDC_Handle->cmd & 0x3F);
		}
		
		/*for poll mode exit*/
		gMSDC_Handle->abort=1;

		if (gMSDC_Handle->dma_xfer)
		{
			kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_XFER_DONE,KAL_OR);
		}
	}
}
void MSDC_CmdIrqHandle(kal_uint32 intsts)
{
	if ((intsts&MSDC_INT_CMDRDY)||(intsts&MSDC_INT_ACMDRDY)||(intsts&MSDC_INT_ACMD19_DONE))
	{
		gMSDC_Handle->error=NO_ERROR;
	}
	else if ((intsts&MSDC_INT_RSPCRCERR)||(intsts&MSDC_INT_ACMDCRCERR))
	{
		gMSDC_Handle->error=ERR_CMD_RSPCRCERR;
	}
	else if ((intsts&MSDC_INT_ACMDTMO)||(intsts&MSDC_INT_CMDTMO))
	{
		gMSDC_Handle->error=ERR_CMD_TIMEOUT;
	}
	kal_set_eg_events(gMSDC_Handle->MSDC_Events,EVENT_CMD_DONE,KAL_OR);
}

void MSDC_CardDetectHandle(kal_uint32 intsts)
{
#if defined(_MSDC_INTERNAL_CD_INT_PIN_)


    gMSDC_Handle->mIsChanged=KAL_TRUE;
    
    /*memory card insertion\removal */
    if (MSDC_Reg32(MSDC_PS)&MSDC_PS_CDSTS)
    {
        /*Card detection pin is logic high*/
        gMSDC_Handle->mIsPresent=KAL_FALSE;
        gMSDC_Handle->mIsInitialized=KAL_FALSE;
    #ifdef MSDC_MUST_RECORD_PLUGOUT
        if (KAL_FALSE == gMSDC_Handle->mIsPresent)
        gMSDC_Handle->MSDC_everPlugOut = KAL_TRUE;
    #endif//MSDC_MUST_RECORD_PLUGOUT

        MSDC_CRIT("[MSDC]Card Remove\r\n");
        MSDC_DeInit();

        }
    else
    {
        /*Card detection pin is logic low*/
        gMSDC_Handle->mIsPresent=KAL_TRUE;
        gMSDC_Handle->mIsInitialized=KAL_FALSE;

        MSDC_CRIT("[MSDC]Card Insert\r\n");
        MSDC_Probe();
    }

#endif
}

/*************************************************************************
* FUNCTION
*  MSDC_HISR_Entry
*
* DESCRIPTION
*	Set corresponding enevt and wake up waiting task.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_HISR_Entry(void)
{
	kal_uint32 cmdsts =MSDC_INT_CMDRDY|MSDC_INT_CMDTMO|MSDC_INT_RSPCRCERR;
	kal_uint32 acmdsts =MSDC_INT_ACMDRDY|MSDC_INT_ACMDTMO|MSDC_INT_ACMDCRCERR|MSDC_INT_ACMD19_DONE;
	kal_uint32 datsts =MSDC_INT_XFER_COMPL | MSDC_INT_DXFER_DONE |
	                    MSDC_INT_DATCRCERR | MSDC_INT_DATTMO |
	                    MSDC_INT_BD_CS_ERR | MSDC_INT_GPD_CS_ERR;

    kal_uint32 intsts_pure;
    kal_uint32 inten, intsts;

	/*Mask IRQ*/
	IRQMask(MD_IRQID_MSDC0);
	/*save IRQ information*/
	gMSDC_Handle->msdc_int=MSDC_Reg32(MSDC_INT);

	intsts_pure=gMSDC_Handle->msdc_int;
	inten=MSDC_Reg32(MSDC_INTEN);

	intsts=intsts_pure&inten;
	/*clear all interrupt*/
	MSDC_WriteReg32(MSDC_INT,intsts);
	/*data transfer interrupt*/
	if (intsts&datsts)
	{
		MSDC_DatIrqHandle(intsts);	
	}
	/*command interrupt*/
	if (intsts&(cmdsts|acmdsts))
	{
		MSDC_CmdIrqHandle(intsts);
	}
	/*card detect interrupt*/
	if(intsts & MSDC_INT_CDSC) 
	{
		MSDC_CardDetectHandle(intsts);
	}
	/*mmc interrupt*/

	/*unmask irq*/
	IRQUnmask(MD_IRQID_MSDC0);
}

/*************************************************************************
* FUNCTION
*  MSDC_DMA_Callback
*
* DESCRIPTION
*	Call back while DMA has done the data transfer.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*
*
*************************************************************************/
void MSDC_DMA_Callback(void)
{

}

#ifdef DRV_MSDC_SHARE_BY_SWITCH
void MSDC_changeSwContext(sd_select_enum sel)
{
    gMSDC_Handle = &MSDC_Blk[sel];
    gSD = &gSD_blk[sel];
}

/*
	this function do not consider race condition issue, caller should make sure this function is called without risk
	currently, this function is called in sdio_drv.c and sd_drv.c
*/
void MSDC_backupHwSetting()
{
    /*backup MSDC_CFG, MSDC_IOCON, SDC_CFG*/
    gMSDC_Handle->setting_MSDC_CFG = MSDC_Reg32(MSDC_CFG);
    gMSDC_Handle->setting_MSDC_IOCON = MSDC_Reg32(MSDC_IOCON);
    gMSDC_Handle->setting_SDC_CFG = MSDC_Reg32(SDC_CFG);
}

void MSDC_retreiveHwSetting()
{
    MSDC_WriteReg32(MSDC_CFG, gMSDC_Handle->setting_MSDC_CFG);
    MSDC_WriteReg32(MSDC_IOCON, gMSDC_Handle->setting_MSDC_IOCON);
    MSDC_WriteReg32(SDC_CFG, gMSDC_Handle->setting_SDC_CFG);
}
#endif

#if defined(__SIM_PLUS__) || defined(DRV_MSDC_DUAL_TCARD_BY_SWITCH)
void MSDC_Switch_Card(sd_select_enum sel)
{
    
}
#endif

#endif //end of MSDC_INT


void MSDC_turnOnVMC(kal_bool turnOnLdo)
{
    
}

#if defined(MSDC_TRACE_LEVEL3)
void MSDC_add_dbg_msg( msdc_dbg_Event event, kal_uint32 data1, kal_uint32 data2)
{

}
#endif

#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH
void MSDC_Switch_SDIO(sd_select_enum sel)
{
    

}
#endif

#ifdef DRV_MSDC_SD_SDIO_SHARE_BY_SWITCH

/*following should be the value defined in custom files*/
#define MSDC_SWITCH_2_SD		1
#define MSDC_SWITCH_2_SDIO	0
#define MSDC_SWITCH_GPIO		20
typedef enum
{
    MSDC_SWITCH_DIRECTION_SD,
    MSDC_SWITCH_DIRECTION_SDIO
} MSDC_SWITCH_DIRECTION;


void MSDC_Switch_init()
{
   
}

/*
	direction:
		0 :	cmmb
		1 :	sd card
*/

void MSDC_Switch(sd_select_enum direction)
{
    
}
#endif


#else
#ifdef DRV_LSD
void MSDC_LSD_HISR(void)
{
}
#endif
#endif // end of  (defined(__MSDC_MS__) || defined(__MSDC_SD_MMC__))
#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)

#else //DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "msdc_def.h"

/*
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR REMOVE
#include "syscomp_config.h"
#include "task_config.h"
#include "stacklib.h"
#include "eint.h"
#include "fat_fs.h"
*/
//RHR
#include "kal_public_defs.h" //MSBB change #include "stack_common.h"  
#include "kal_public_defs.h" //MSBB change #include "stack_msgs.h"
#include "kal_public_api.h" //MSBB change #include "app_ltlcom.h"     
#include "intrCtrl.h"
#include "reg_base.h"
#include "drvpdn.h"
//#include "gpt_sw.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "msdc_def.h"
#include "dcl.h"

/* Debug log */
kal_uint32 MSDC_DebugLevel;

#define LDO_VMC             0
#define LDO_VMCH            1
#define LDO_VIO18_PMU       2

static kal_uint32 g_msdc0_io = PMU_VOLT_03_300000_V;
static kal_uint32 g_msdc0_card = PMU_VOLT_03_300000_V;

static kal_uint32 hwPowerOn(kal_uint32 powerID, PMU_VOLTAGE_ENUM powerVolt) 
{
    PMU_CTRL_LDO_BUCK_SET_EN pmu_en;
    PMU_CTRL_LDO_BUCK_SET_VOLTAGE pmu_volsel;
    DCL_HANDLE handle;

    /* Open PMU handle */
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);
    
    switch(powerID) {
        case LDO_VMC:
            /* Set enable control */
            pmu_en.mod = VMC;
            pmu_en.enable = 1;

            /* Set voltage */
            pmu_volsel.mod = VMC;
            pmu_volsel.voltage = powerVolt;

            DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmu_volsel);
            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        case LDO_VMCH:
            /* Set enable control */
            pmu_en.mod = VMCH;
            pmu_en.enable = 1;

            /* Set voltage */
            pmu_volsel.mod = VMCH;
            pmu_volsel.voltage = powerVolt;

            DclPMU_Control(handle, LDO_BUCK_SET_VOLTAGE, (DCL_CTRL_DATA_T *)&pmu_volsel);
            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        default:
        break;
    }

    /* Close PMU handle */
    DclPMU_Close(handle);
    
    return 1;
}

static kal_uint32 hwPowerDown(kal_uint32 powerID) 
{
    PMU_CTRL_LDO_BUCK_SET_EN pmu_en;
    DCL_HANDLE handle;

    /* Open PMU handle */
    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

    switch(powerID) {
        case LDO_VMC:
            /* Set enable control */
            pmu_en.mod = VMC;
            pmu_en.enable = 0;

            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
        break;

        case LDO_VMCH:
            /* Set enable control */
            pmu_en.mod = VMCH;
            pmu_en.enable = 0;

            DclPMU_Control(handle, LDO_BUCK_SET_EN, (DCL_CTRL_DATA_T *)&pmu_en);
            
        break;

        default:
        break;
    }

    /* Close PMU handle */
    DclPMU_Close(handle);

    return 1;
}

static kal_uint32 msdc_ldo_power(kal_uint32 on, kal_uint8 powerId, 
    PMU_VOLTAGE_ENUM powerVolt, kal_uint32 *status)
{
    if (on) { // want to power on
        if (*status == 0) {  // can power on 
            hwPowerOn(powerId, powerVolt);
            
            *status = powerVolt;             
        } else if (*status == powerVolt) {
        } else { // for sd3.0 later

            hwPowerDown(powerId);
            hwPowerOn(powerId, powerVolt);
            
            *status = powerVolt;
        }
    } else {  // want to power off
        if (*status != 0) {  // has been powerred on

            hwPowerDown(powerId);
            
            *status = 0;
        } else {
        }                
    }  
    
    return 0;          
}

kal_bool MSDC_SetVddPower(kal_bool on, kal_uint32 volt)
{
	kal_bool ret =KAL_TRUE;
	    
	if (volt == 3300)
	{
		msdc_ldo_power(on, LDO_VMCH, PMU_VOLT_03_300000_V, &g_msdc0_card);
	}
	else
	{
		ret = KAL_FALSE;
	}
		
	return ret;
}

kal_bool MSDC_SetSignalPower(kal_bool on,kal_uint32 volt)
{
	kal_bool ret =KAL_TRUE;
	if (volt == 3300)
	{
		msdc_ldo_power(on, LDO_VMC, PMU_VOLT_03_300000_V, &g_msdc0_io);
	}
	else if (volt ==1800)
	{
        msdc_ldo_power(on, LDO_VMC, PMU_VOLT_01_800000_V, &g_msdc0_io);
	} 
	else
	{
		ret = KAL_FALSE;
	}
		
	return ret;
}

/*here are dummy API*/
void MSDC_Initialize(void) 
{
    /* INIT MSDC debug flag */
    MSDC_SetDebugLevel(K_WARNIN);
    
    /* Shut card power and signal power */
	MSDC_SetVddPower(KAL_FALSE, 3300);
	MSDC_SetSignalPower(KAL_FALSE, 3300);
}

void MSDC_PDNControl(kal_bool ON) {}
int MSDC_GetCardStatus(void * DriveData, int AckType) {return 0;}
//kal_bool MSDC_GetMediaChanged(void * id) {}
kal_bool MSDC_GetMediaChanged(sd_select_enum id) {return 0;}
MSDC_HANDLE MSDC_Blk[SD_NUM];
MSDC_HANDLE	*gMSDC_Handle = &(MSDC_Blk[0]);
//kal_bool MSDC_everPlugOut;

#endif //DRV_MSDC_OFF
