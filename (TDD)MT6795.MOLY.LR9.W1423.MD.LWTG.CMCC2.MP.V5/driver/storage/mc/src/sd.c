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
 *   sd.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   driver functons for SD/MMC
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
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
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


//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
//#include "kal_public_api.h"
#include "kal_public_defs.h"
#include "kal_debug.h"
#include "init.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "app_buff_alloc.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"
#include "init.h"
#include "pmic_features.h"
#include "pmu_sw.h"
#include "nucleus.h"
#include "ev_defs.h"
*/
//RHR
#include "kal_trace.h"
#include "dcl.h"
#include "drv_comm.h"
#include "drv_features.h"
#include "kal_public_defs.h" //MSBB change #include "stack_config.h"
#include "qmu_bm.h"
#include "qmu_bm_util.h"

#if !defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)
#include "us_timer.h"
#include "msdc_reg_adap.h"
#include "reg_base.h"
#include "msdc_api.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
#include "drv_trc.h"
#if defined(__AUDIO_DSP_LOWPOWER__)
#include "audlp_exp.h"
#endif

#if defined(__EMMC_BOOTING__)
#include "FTL.h"
#endif

#ifdef DRV_LSD
#include "msdc_lsd.h"



extern void LSD_Host74TCMDHigh(void);
extern kal_bool LSD_HostDetectBusy(void);
#endif

#if defined(__MSDC_SD_MMC__)
//global variables
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;

/*global veriable ,operation by DMA ,alloc in uncached memory*/
#ifdef MSDC_GPD_BD_BUF_CACHED
msdc_gpd_t MSDC_gpd[SD_NUM];
msdc_gpd_t MSDC_gpd_end[SD_NUM];

msdc_bd_t  MSDC_bd[SD_NUM][MSDC_BD_MAX];
#else
__attribute__ ( (section ("NONCACHEDRW")))msdc_gpd_t MSDC_gpd[SD_NUM];
__attribute__ ( (section ("NONCACHEDRW")))msdc_gpd_t MSDC_gpd_end[SD_NUM];

__attribute__ ( (section ("NONCACHEDRW")))msdc_bd_t  MSDC_bd[SD_NUM][MSDC_BD_MAX];
#endif

//static SDC_CMD_STATUS gblSDsta;

extern MSDC_Custom_Handle msdc_custom_handle;
void SD_Sleep4Wait(kal_int32 sleep_tick);
void SD_Use13M_Clock(void);
extern kal_uint8 MSDC_GetIOCtrlParam(void);
extern kal_bool INT_USBBoot(void);
#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
extern void MSDC_SetLatchTuning(void);
#else
extern void MSDC_SetIOCONRegDLT(void);
#endif//#if defined(DRV_MSDC_LATCH_MT6276_SERIES)
//kal_uint32 sd_writeFailReason; // fix Lint warning
#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
void SD_SetRedDlt(kal_uint32 redDlt);
#endif//#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction); 

/*#ifdef DRV_MSDC_SDC_V3
static kal_uint32 sd_cmd_extra = ((64) << 24);	// CTOC = 64
#else
static kal_uint32 sd_cmd_extra = 0;
#endif*/

#if defined(__SIM_PLUS__)
#if !defined(__CUST_NEW__)
kal_char MSDC_GetClockWithoutSIMPlus(void);
#endif
#endif



#ifdef DCL_MSDC_INTERFACE
#include "dcl.h"

SDC_CMD_STATUS SD_SetCallBack(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3, MSDC_CALLBACK callback4, MSDC_CALLBACK callback5, MSDC_CALLBACK callback6);
SDC_CMD_STATUS SD_SetReadTestFlag(kal_uint32 readTestFlag);
SDC_CMD_STATUS SD_readTest(void);
SDC_CMD_STATUS SD_SetUpllClock(void);

#ifdef __MEUT__
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_ReadSingleBlock,
    (DCL_MUL_BLK_RD)SD_ReadMultiBlock,
    (DCL_SINGLE_BLK_WR)SD_WriteSingleBlock,
    (DCL_MUL_BLK_WR)SD_WriteMultiBlock,
    (DCL_SD_INITITALIZE)SD_Initialize,
    (DCL_SET_PRE_ERASE_CNT)SD_SetPreEraseBlk,
    (DCL_SD_SET_CALLBACK)SD_SetCallBack,
    (DCL_SET_READ_TEST_FLAG)SD_SetReadTestFlag,
    (DCL_SD_READ_TEST)SD_readTest,
    (DCL_SD_SET_UPLL_CLOCK_TEST)SD_SetUpllClock,
    (DCL_SD_ERASE_BLK)SD_FlushSectors,
};
#else
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_ReadSingleBlock,
    (DCL_MUL_BLK_RD)SD_ReadMultiBlock,
    (DCL_SINGLE_BLK_WR)SD_WriteSingleBlock,
    (DCL_MUL_BLK_WR)SD_WriteMultiBlock,
    (DCL_SD_INITITALIZE)SD_Initialize,
    (DCL_SET_PRE_ERASE_CNT)SD_SetPreEraseBlk,
    (DCL_SD_SET_CALLBACK)NULL,
    (DCL_SET_READ_TEST_FLAG)NULL,
    (DCL_SD_READ_TEST)NULL,
    (DCL_SD_SET_UPLL_CLOCK_TEST)NULL,
    (DCL_SD_ERASE_BLK)SD_FlushSectors,
    (DCL_GPD_MUL_BLK_RD)SD_GpdReadMultiBlock,
    (DCL_GPD_MUL_BLK_WR)SD_GpdWriteMultiBlock,
};
#endif

#endif

#if defined( __MSDC_BASIC_LOAD__) || defined( __MEUT__)
#define MSDC_TESTBUFFER_SIZE	512
kal_uint32	msdc_testBuffer[(MSDC_TESTBUFFER_SIZE / 4)];
kal_uint32	msdc_writeBuffer[(MSDC_TESTBUFFER_SIZE / 4)];

#define CMD_DVT_TEST_STATUS 7
kal_uint32 msdc_ReadTestFlag;
MSDC_CALLBACK msdc_TestCallBack1;
MSDC_CALLBACK msdc_TestCallBack2;
MSDC_CALLBACK msdc_TestCallBack3;
MSDC_CALLBACK msdc_TestCallBack4;
MSDC_CALLBACK msdc_TestCallBack5;
MSDC_CALLBACK msdc_TestCallBack6;
static kal_uint32 sendCmdTimes = 0;
#endif

#ifdef __CARD_DOWNLOAD__
extern kal_bool MSDC_QueryIsPowerControllable(void);
extern void MSDC_SetPower(kal_bool enable);
#endif




/*************************************************************************
* FUNCTION
*  SD_Acmd42
*
* DESCRIPTION
*	connect/disconnect the 50K Ohm pull-up resistor on CD/DAT3
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_Acmd42(kal_bool connect)
{
    SDC_CMD_STATUS status;
    MSDC_DEBUG("[SD][%s %d]send cmd55\r\n",__FUNCTION__,__LINE__);

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;
    
    MSDC_DEBUG("[SD][%s %d]send acmd42\r\n",__FUNCTION__,__LINE__);

    // send cmd6
    if ((status = SD_SendCmd(SDC_CMD_ACMD42, connect,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    gSD->mCD_DAT3 = KAL_FALSE;	// pull-up resistor is disconnected for data trnasfer
    return NO_ERROR;
}


#if defined(MSDC_MMC441_SUPPORT)

kal_bool SD_eMMC_ECSD_setValue(kal_uint8 addr, kal_uint8 value)
{
    //kal_uint32 r0; // [TODO]: eMMC
    //kal_bool status = KAL_FALSE;
    kal_uint8 *pData;

    if (192 <= addr) //addr above 192 is information registers, we can't write these registers
        ASSERT(0);

    MSDC_PDNControl(KAL_FALSE);

    if (NO_ERROR != SD_Switch_MMC40(SET_BYTE, addr, value, 0))
        ASSERT(0);

    //if(NO_ERROR != SD_GetStatus(gSD->mRCA,(kal_uint32*)&r0))
    //	ASSERT(0);
    if (NO_ERROR != SD_SendEXTCSD_MMC40(MSDC_Sector))
        ASSERT(0);

    pData = (kal_uint8 *)MSDC_Sector;

    if (value !=  *(pData + addr))
        ASSERT(0);

    //status = KAL_TRUE;
    MSDC_PDNControl(KAL_TRUE);
    return KAL_TRUE;
}

/*
	This API is to ask eMMC to start the partition.
	That is, this API should be called after configuring partition settings.
*/
kal_bool SD_eMMC_ECSD_StartPartition()
{
    kal_bool status;

    /*if this is not eMMC 4.4, assert it */
    //EMMC44_CHECK_AND_ASSERT;

    /*the device has been partitioned*/
    if (EMMC_MASK_PARTITION_SETTING & gSD->mCSD.ext_csd->partition_settig)
    {
        ASSERT(0);
    }

    status = SD_eMMC_ECSD_setValue(EXT_CSD_PARTITION_CONFIG_INDEX, 1);

    return status;
}

// unit: 512-byte
kal_uint32 SD_eMMC_getWpgSize()
{
     if ((1 & gSD->mCSD.ext_csd->erase_grp_def) && (gSD->mCSD.ext_csd->hc_wp_grp_size > 0))
        return 1024 * gSD->mCSD.ext_csd->hc_erase_grp_size * gSD->mCSD.ext_csd->hc_wp_grp_size;
    else
        return (gSD->mCSD.wp_grp_size_mmc >> 9);
}

/*
	This API is called to configure partition settings. Size unit is 512-byte.
*/
kal_bool SD_eMMC_ECSD_configPartition(eMMC_partitions partition, kal_uint32 startAddr, kal_uint32 size, kal_bool isEnhanced)
{
    
	kal_bool status;
	kal_uint32 maxEnhSizeMult;
	kal_uint32 wpgSize;
	kal_uint32 wpgNum;
	kal_uint32 partitionSize[5];
	kal_uint8	regIndex;
	kal_uint8 value[3];

	if (eMMC_GP_partition1 > partition || eMMC_user_Area < partition)
		ASSERT(0);

	/*if this is not eMMC 4.4, assert it */
	//EMMC44_CHECK_AND_ASSERT;

	/*1st, if this card does not support enhanced feature or does not support partition feature, we can not do this function*/

	/*	2nd, there is a limitation for the total size of enhanced memory area.
		we have to know the total size of other existed enhanced area and check whether the setting violet the limitation.
	*/
	maxEnhSizeMult = gSD->mCSD.ext_csd->max_enh_size_mult[0] | ( gSD->mCSD.ext_csd->max_enh_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->max_enh_size_mult[2] << 16);

	/*get current all partition size*/
	partitionSize[eMMC_GP_partition1 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[0] | ( gSD->mCSD.ext_csd->gp_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[2] << 16);
	partitionSize[eMMC_GP_partition2 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[3] | ( gSD->mCSD.ext_csd->gp_size_mult[4] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[5] << 16);
	partitionSize[eMMC_GP_partition3 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[6] | ( gSD->mCSD.ext_csd->gp_size_mult[7] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[8] << 16);
	partitionSize[eMMC_GP_partition4 - eMMC_GP_partition1] = gSD->mCSD.ext_csd->gp_size_mult[9] | ( gSD->mCSD.ext_csd->gp_size_mult[10] << 8) | ( gSD->mCSD.ext_csd->gp_size_mult[11] << 16);
	partitionSize[eMMC_user_Area - eMMC_GP_partition1] = gSD->mCSD.ext_csd->enh_size_mult[0] | ( gSD->mCSD.ext_csd->enh_size_mult[1] << 8) | ( gSD->mCSD.ext_csd->enh_size_mult[2] << 16);

	/*calculate how many wpg we need to set*/
	wpgSize = SD_eMMC_getWpgSize();
	wpgNum = (size / wpgSize) + ((size % wpgSize) > 0 ? 1 : 0);

	/*replace old size with the new size we want to set*/
	partitionSize [partition - eMMC_GP_partition1] = wpgNum;

	if ((partitionSize[0] + partitionSize[1] + partitionSize[2] + partitionSize[3] + partitionSize[4]) > maxEnhSizeMult)
		return KAL_FALSE;

	/*everything check passed, now we can set the value*/
	if (eMMC_user_Area > partition)
		regIndex = EXT_CSD_GP_SIZE_MULT_GP0_INDEX + 3 * (partition - eMMC_GP_partition1);
	else
		regIndex = EXT_CSD_ENH_SIZE_MULT_INDEX;

	value[2] = wpgNum / 64;
	value[1] = (wpgNum - (value[2] * 64)) / 8;
	value[0] = wpgNum - (value[2] * 64) - (value[1] * 8);
	status = SD_eMMC_ECSD_setValue(regIndex, value[0]);

	if (KAL_TRUE != status)
		goto err_exit;

	status = SD_eMMC_ECSD_setValue(regIndex + 1, value[1]);

	if (KAL_TRUE != status)
		goto err_exit;

	status = SD_eMMC_ECSD_setValue(regIndex + 2, value[2]);

	if (KAL_TRUE != status)
		goto err_exit;

err_exit:
	return status;
    
}

/*
	This API is to configure to boot from specified partition.
	By this API, DA can decide from wich partition, will card output the boot code in boot mode.
*/
kal_bool SD_eMMC_ECSD_setCurrentPart(eMMC_partitions partition)
{
    kal_uint8 regValue;
    kal_bool status;
    eMMC_partitions pt;

  	if (0 == partition || eMMC_user_Area < partition)
        ASSERT(0);

    /*if this is not eMMC 4.4, assert it */
    //EMMC44_CHECK_AND_ASSERT;

    pt = (partition == eMMC_user_Area) ? 0 : partition;

    regValue = gSD->mCSD.ext_csd->partition_config;

    /*currently it uses the setting DA want, no need to change*/
    if (pt == (EMMC_MASK_PARTITION_CONFIG & regValue))
        return KAL_TRUE;

    regValue &= ~EMMC_MASK_PARTITION_CONFIG;
    regValue |= pt;
    status = SD_eMMC_ECSD_setValue(EXT_CSD_PARTITION_CONFIG_INDEX, regValue);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__EMMC_BOOTING__)
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    return status;
}

/*************************************************************************
* FUNCTION
*  SD_IsEMMC
*
* DESCRIPTION
*	Check inserted card is e-MMC 4.4
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_IsEmmcV44()
{
    /*	from eMMC 4.3, EXT_CSD_REV has maximum value 3, and from eMMC 4.4, EXT_CSD_REV new value 4, 5
    */
    if (3 < gSD->mCSD.ext_csd->ext_csd_rev)
    {
        if (0 != gSD->mCSD.ext_csd->boot_size_mul) //has boot partition, this is eMMC
        {
            gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_TRUE;
            gSD->emmc_info.bootPartitionSize = 2 * 128 * gSD->mCSD.ext_csd->boot_size_mul;
            gSD->emmc_info.gp1PartitionSize = SD_eMMC_getWpgSize() *
                                              (gSD->mCSD.ext_csd->gp_size_mult[0]
                                               + ( gSD->mCSD.ext_csd->gp_size_mult[1] * 256)
                                               + ( gSD->mCSD.ext_csd->gp_size_mult[2] * 65536));

            /*from spec, alternated boot method is mandatory for eMMC4.4*/
            if ( 0 == (0x1 & gSD->mCSD.ext_csd->boot_info))
                ASSERT(0);

            /*we can't use the card that don't have RST signal support*/
            if ( 0x2 == (0x3 & gSD->mCSD.ext_csd->rst_function))
                ASSERT(0);

            if ( 0x1 == (0x1 & gSD->mCSD.ext_csd->partition_support))
                gSD->emmc_info.supportPartition = (kal_bool)KAL_TRUE;
            else
                gSD->emmc_info.supportPartition = (kal_bool)KAL_FALSE;

            if ( 0x2 == (0x2 & gSD->mCSD.ext_csd->partition_support))
                gSD->emmc_info.supportEnhancedPart = (kal_bool)KAL_TRUE;
            else
                gSD->emmc_info.supportEnhancedPart = (kal_bool)KAL_FALSE;
        }
        else   //normal mmc card without boot support
        {
            gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_FALSE;
        }
    }
    else   //spec version below or equals to eMMC 4.3
    {
        gSD->emmc_info.isEmmcV44 = (kal_bool)KAL_FALSE;
    }
}

#endif//defined(MSDC_MMC441_SUPPORT)


/*************************************************************************
* FUNCTION
*  SD_SetMMC40_4bit_high_speed
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
SDC_CMD_STATUS SD_SetMMC40_bus_high_speed(void)
{
	kal_uint32 clock, hs;
    //    kal_uint8 *pData;

    #if !defined(__EMMC_BOOTING__)

    if (SD_SetBlength(512) != NO_ERROR)
        goto err;

    #endif

    #ifndef MSDC_SPECIAL_MMC_41_CARD

    // read the EXT_CSD
    if (SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
        goto err;

    #endif

    /*calculate size*/
    if (MMC42_CARD == gMSDC_Handle->mMSDC_type)
    {
        gSD->mCSD.capacity = (kal_uint64)gSD->mCSD.ext_csd->sec_count * 512;
    }

    #if defined(MSDC_MMC441_SUPPORT)
        SD_IsEmmcV44();
    #endif

    // set high speed
    #ifndef MSDC_SPECIAL_MMC_41_CARD

    if (gSD->mCSD.ext_csd->card_type & HS_52M)
    #endif
    {
        // should be 52000
        clock = 52000000;
        //clock = gMSDC_Handle->msdc_clock / 2;

        //if (52000000 < clock)
        //    clock = clock / 2;

        hs = 1;
        //MSDC_LSD_WriteReg32(MSDC_IOCON,0x010002FF)
        
	    MSDC_DEBUG("[MSDC][%s %d]1.Set clock to %d \r\n",__FUNCTION__,__LINE__,clock);
    }

    #ifndef MSDC_SPECIAL_MMC_41_CARD
    else if (gSD->mCSD.ext_csd->card_type & HS_26M)
    {
        // should be 26000
        clock = 26000000;
        hs = 1;
    }
    else
    {
        clock = 13000000;
        hs = 0;
    }

    #endif
    
    if (hs)
    {
        //! [TODO]: eMMC
        /* select proper power class
        if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_POW_CLASS_INDEX,
        	(gSD->mCSD.ext_csd->pwr_52_360&0xf) ,0) != NO_ERROR)
        	goto err;
        */


       
        /* enable high speed (26M or 52M)*/
        if(SD_Switch_MMC40(SET_BYTE,EXT_CSD_HIGH_SPPED_INDEX,EXT_CSD_ENABLE_HIGH_SPEED,0) != NO_ERROR)
        	goto err;
        

        // latch data at falling edge to cover the card driving capability
        // MSDC_LSD_SetBits32(MSDC_CFG,MSDC_CFG_RED);
    }

    #ifndef DRV_LSD

    //#ifndef DRV_MSDC_CLK_SEARCH
    //gMSDC_Handle->msdc_clock = MSDC_CLOCK;
    MSDC_SetClock(clock,KAL_FALSE);
    //#endif
    #else
    LSD_HostSetClock(LSD_SPEED_52M);
    #endif



    if (NO_SINGLE_LINE == gMSDC_Handle->trySingleLine)
    {
        // select bus width
        #if defined(MMC40_USE_4BIT_BUS)
        // enable 4-bit bus width
        if (SD_Switch_MMC40(SET_BYTE, EXT_CSD_BUS_WIDTH_INDEX, BIT_4_MMC40, 0) != NO_ERROR)
            goto err;

        #ifdef MSDC_SPECIAL_MMC_41_CARD

        if (KAL_TRUE == kal_query_systemInit()
            || KAL_TRUE == FTL_isPollingMode()
           )
        {
            MSDC_GPTI_BusyWait(2);
        }
        else
        {
            kal_sleep_task(4);
        }

        #endif

        MSDC_SetBusWidth(BIT_4W);
        gSD->bus_width = 4;
        #elif defined(MMC40_USE_8BIT_BUS)

        // enable 8-bit bus width
        if (SD_Switch_MMC40(SET_BYTE, EXT_CSD_BUS_WIDTH_INDEX, BIT_8_MMC40, 0) != NO_ERROR)
            goto err;
        MSDC_SetBusWidth(BIT_8W);
        gSD->bus_width = 8;
        #endif
    }
    else
    {
        gMSDC_Handle->trySingleLine&=(~TEMP_SINGLE_LINE);
    }

    #ifndef MSDC_SPECIAL_MMC_41_CARD

    if (SD_SendEXTCSD_MMC40(MSDC_Sector) != NO_ERROR)
        goto err;;

    #endif
    
    return NO_ERROR;
err:

    return ERR_MMC_BUS_HS_ERROR;
}
/*************************************************************************
* FUNCTION
*  SD_CheckSDorMMC
*
* DESCRIPTION
*	Check inserted card is SD or MMC
*
* PARAMETERS
*
*
* RETURNS
*  SD_CARD or MMC_CARD
*
* GLOBALS AFFECTED
*	gMSDC_Handle
*
*************************************************************************/
T_MSDC_CARD SD_CheckSDorMMC()
{
    SDC_CMD_STATUS status;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
    SD_Cmd8();
#endif
    status = SD_Acmd41_SD();

    if (status == NO_ERROR)
        return gMSDC_Handle->mMSDC_type;	// SD_CARD
    else
        MSDC_ERR("[SD]SD_Acmd41_SD returns error code: %d\r\n", status);

    status = SD_Cmd1_MMC();

    if (status == NO_ERROR)
        return gMSDC_Handle->mMSDC_type;	// MMC_CARD
    else
        MSDC_ERR("[SD]SD_Cmd1_MMC returns error code: %d\r\n", status);

    return UNKNOWN_CARD;
}

/*************************************************************************
* FUNCTION
*  SD_SetDefault
*
* DESCRIPTION
*	set default values to gSD
*
* PARAMETERS
*
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_SetDefault(void)
{
     MSDC_LOCK_TAG tempLock;
    kal_mem_cpy(&tempLock, &gSD->mSDdrv_lock, sizeof(MSDC_LOCK_TAG));
    kal_mem_set(gSD, 0, sizeof(T_SDC_HANDLE));

    gSD->mBKLength = 0;
    gSD->mRCA = 0;
    gSD->mInactive = KAL_FALSE;
    gSD->mState = IDLE_STA;
    gSD->bus_width = 1;
    //gSD->mCD_DAT3 = KAL_TRUE;

    kal_mem_cpy(&gSD->mSDdrv_lock, &tempLock, sizeof(MSDC_LOCK_TAG));
}

void SD_Use24M_Clock(void)
{

}

void SD_Use13M_Clock(void)
{

}

#ifdef	DRV_MSDC_CLK_MT6268_SERIES
void SD_Use30M_Clock(void)
{
    
}

void SD_Use45M_Clock(void)
{
   
}
#endif

#ifdef DRV_MSDC_CLK_SEARCH

kal_uint32 whenToStop;
kal_uint32 stopTimeout = 300;

#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

void SD_SetRedDlt(kal_uint32 redDlt)
{
    
}
#endif//#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool sd_DltTestWithClkStopped(kal_uint32 data_adrs)
{
	return 0;
    
}

#if !defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool SD_setCLKAndTest(kal_uint32 targetCLK)
{
   return 0;
}


kal_uint32 SD_tuneCLK2()
{
    return 0;
}

#else//!defined(DRV_MSDC_LATCH_MT6276_SERIES)

kal_bool SD_IsClkInRange(kal_uint32 clk)
{
     return 0;
}

kal_bool SD_CanCmdBeLatched(void)
{
     return 0;
}

/*kal_bool SD_CanDataBeLatched(msdc_clk_setting cs)
{
   
}*/

/*SDC_CMD_STATUS MSDC_AutoCalibrate(
    msdc_acb_mode		mode,
    msdc_acb_scan_mode	scanMode,
    msdc_acb_tun_scheme	tunScheme,
    kal_uint8			tunBlockNum
)
{
   
}*/

/*kal_uint32 MSDC_ManuCalibrate(
    msdc_clk_setting	cs,
    msdc_acb_mode 		mode
)
{
    
}*/

#define MAX_NUM_MULTI_PHASE	32
SDC_CMD_STATUS FindMostConsecutiveBits(
    kal_uint32 word,
    kal_uint8 wordLen,
    kal_uint8 threshold,
    kal_uint8 *pos
)
{
    return 0;
}

/*SDC_CMD_STATUS MSDC_AutoCalibrate_FindBestLatchWindow(
    msdc_acb_scan_mode scanMode,
    kal_uint8 *pos
)
{
    
}*/

/*SDC_CMD_STATUS MSDC_ManuCali_FindBestLatchWindow(
    msdc_clk_setting cs,
    kal_uint32 phaseArraySeamless,
    kal_uint8 *pos
)
{
    
}*/

/*kal_uint32 SD_ClkTuning_AutoCalibrate(msdc_clk_setting cs)
{

}*/

/*kal_uint32 SD_ClkTuning_ManualCalibrate(msdc_clk_setting cs)
{
   
}*/

/*kal_uint32 SD_ClkTuning_FeedbackClk(msdc_clk_setting cs)
{
    
}*/

kal_uint32 SD_tuneCLK2()
{
    return 0;
}

#endif//!defined(DRV_MSDC_LATCH_MT6276_SERIES)

#endif//#ifdef DRV_MSDC_CLK_SEARCH

#ifdef __MEUT__
kal_bool	msdcOddNumberSizeTestByDMA;
kal_bool	msdcDoNotRST;
SDC_CMD_STATUS msdcReadTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs)
{
	
    return 0;
}

#endif


#ifdef __MSDC_BASIC_LOAD__

kal_bool	msdcOddNumberSizeTestByDMA;
kal_bool	msdcDoNotRST;
SDC_CMD_STATUS msdcTransferLengthTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs)
{
	 return 0;
   }

SDC_CMD_STATUS msdcWriteLengthTest(kal_uint32 size, kal_uint8 *compareBuffer, kal_uint32 data_adrs, kal_bool notChange)
{
	 return 0;
    
}
#endif

#if defined(MSDC_QMU_ENABLE)
#define MSDC_QBM_BPS_NUM        1
#define MSDC_QBM_BPS_BUF_SZ		QBM_QUEUE_GET_MEM_SIZE(QBM_SIZE_TGPD_BPS, MSDC_QBM_BPS_NUM)
kal_uint8 msdc_bps_buf[MSDC_QBM_BPS_BUF_SZ];
void *g_p_msdc_bps[MSDC_QBM_BPS_NUM];

/* Initialize the QUM buffer for MSDC queue transfer */
kal_bool SD_QMU_Init(void)
{
    kal_bool ret = KAL_TRUE;
    unsigned char idx = 0;
    bm_queue_config conf;
    qbm_gpd *p_cur_gpd = NULL ,*p_head_gpd = NULL , *p_tail_gpd = NULL;

    /* Init the BPS pointer */
    for (idx = 0; idx < MSDC_QBM_BPS_NUM; idx++)
        g_p_msdc_bps[idx] = NULL;

    /*initial non-free bypass GPD buffer pool*/
    qbm_init_q_config(&conf);
    conf.buff_num = MSDC_QBM_BPS_NUM;
    conf.p_mem_pool_str = msdc_bps_buf;
    conf.p_mem_pool_end = msdc_bps_buf + MSDC_QBM_BPS_BUF_SZ;

    /*user must flush the GPD after this non-free init queue*/
    if (QBM_ERROR_OK != qbm_init_queue_non_free(QBM_TYPE_TGPD_BPS, &conf , (void **)&p_head_gpd, (void **)&p_tail_gpd)) {
        return KAL_FALSE;
    }

    idx = 0;
    p_cur_gpd = p_head_gpd;

    do {
        qbm_set_non_free(p_cur_gpd);
		qbm_set_used(p_cur_gpd);
		QBM_DES_CLR_HWO(p_cur_gpd);
		QBM_DES_SET_NEXT(p_cur_gpd, NULL);

		g_p_msdc_bps[idx] = p_cur_gpd;
		
        /*flush GPD here because qbm_init_queue_non_free don't flush GPD*/
        QBM_CACHE_FLUSH(p_cur_gpd, sizeof(qbm_gpd));
        idx ++;

        /*should consider the bps_ptr array count*/
        if ((p_cur_gpd == p_tail_gpd) || (idx >= MSDC_QBM_BPS_NUM)) {
            break;
        }

        p_cur_gpd = p_cur_gpd->p_next;
    } while(1);

    return ret;
}
#endif

/*************************************************************************
* FUNCTION
*  SD_Initialize
*
* DESCRIPTION
*	Initial SD controller and card
*
* PARAMETERS
*
*
* RETURNS
*  SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
SDC_CMD_STATUS SD_Initialize(void)
{
    SDC_CMD_STATUS status;
    kal_uint32 cid[4], csd[4], scr[4];
    kal_uint32 sd_status[16];
    kal_uint16 rca;
    
    /*check if init or not*/
    if (gMSDC_Handle->mIsInitialized==KAL_TRUE)
    {
    	return NO_ERROR;
    }

#if defined(MSDC_MMC441_SUPPORT)
    gSD->emmc_info.isEmmcV44 = KAL_FALSE;
#endif

    /* Re-Init gSD */
	kal_mem_set(&gSD->mSCR, 0, sizeof(T_SCR));

    /*reset event*/
    kal_set_eg_events(gMSDC_Handle->MSDC_Events,0,KAL_AND);

    /*reset MSDC*/
    MSDC_RESET();

    /*may switch to 1.8 last time,we should set signal volt to 3.3v and power cycle*/
    gMSDC_Handle->signal_volt=3300;
    MSDC_SetSignalPower(KAL_TRUE, gMSDC_Handle->signal_volt);
    power_cycle(20);

    /* Set INIT clock */
    MSDC_SetClock(MSDC_INIT_CLOCK,KAL_FALSE);
    /*set to 1 bit data line*/
    MSDC_SetBusWidth(BIT_1W);
    /*SD_SetDefault*/
    SD_SetDefault();					//need check the function !!!!!!
    /*set latch tuning*/

    /*set IOCON1  */
    /*set CARD_CK_PWDN=0 */
    MSDC_ClearBits32(MSDC_CFG,MSDC_CFG_CKPDN);
    /*enable bus clk*/
    MSDC_SetBits32(MSDC_CFG,MSDC_CFG_CKDRV_EN);

    /*reset cmd0*/
    status=SD_Reset();
    SD_INITIALIZE_STATUS_CHECK();                   /*need check this function !!!!!!!!!!!!*/
    /*checkSDorMMC cmd8 acmd41 cmd1*/
    if (SD_CheckSDorMMC() == UNKNOWN_CARD)
    {
        MSDC_ERR("[SD][%s %d]unknow card\r\n",__FUNCTION__,__LINE__);
        SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
        status = ERR_STATUS;
        goto err;
    }
    /*getCID cmd2*/
    status = SD_GetCID(cid);
    SD_INITIALIZE_STATUS_CHECK();
    /*validateRCA cmd3*/
    status = SD_ValidateRCA(&rca);
    SD_INITIALIZE_STATUS_CHECK();
    /*GetCSD cmd9*/
    status = SD_GetCSD(gSD->mRCA, csd);
    SD_INITIALIZE_STATUS_CHECK();
    MSDC_DEBUG("[SD][%s %d]send cmd4\r\n",__FUNCTION__,__LINE__);
    /*setSDR cmd4*/
    if (gSD->mCSD.dsr_imp){
        if ((status = SD_SetDSR()) != NO_ERROR)
        {
            //dbg_print("6\r\n");
            SD_TRACE2(TRACE_GROUP_5, MSDC_GENERAL_FAIL, MSDC_DRV_TRC_FILE_SD, __LINE__);
            goto err;
        }
    }
    /*check Write Protected*/
#if defined(MSDC_WR_PROT_EN)
#if defined(_MSDC_INTERNAL_CD_INT_PIN_)
    if(!(MSDC_Reg32(MSDC_PS)&MSDC_PS_WP))
    {
        //gSD->mWPEnabled=KAL_TRUE;
        if (gSD->mWPEnabled!=KAL_TRUE)
            gSD->mWPEnabled=KAL_FALSE;
    }
    else
    {
        //gSD->mWPEnabled=KAL_FALSE;
        gSD->mWPEnabled=KAL_TRUE;
    }
#else
    {
    DCL_HANDLE handle;

    GPIO_CTRL_READ_T data;

    /* when use EINT for card detect,get the status */
    handle = DclGPIO_Open(DCL_GPIO, MSDC_WP_GPIO);
    DclGPIO_Control(handle, GPIO_CMD_READ, (DCL_CTRL_DATA_T *)&data);

    if (data.u1IOData)
        gSD->mWPEnabled = KAL_TRUE;
    else
        gSD->mWPEnabled = KAL_FALSE;
        
    DclGPIO_Close(handle);
    }
#endif
#else       /* MSDC_WR_PROT_EN */
    gSD->mWPEnabled = KAL_FALSE;
#endif

    MSDC_CRIT("[SD][%s %d]Card is %s\r\n",__FUNCTION__,__LINE__,
        gSD->mWPEnabled ? "WP-ed" : "Not WP-ed");
        
    /*select Card cmd7*/
    status = SD_SelectCard(gSD->mRCA);
    if (status == CARD_IS_LOCKED)
        gSD->mIsLocked = KAL_TRUE;
    SD_INITIALIZE_STATUS_CHECK();


    /*read SCR cmd16 acmd51*/
    if (gMSDC_Handle->mMSDC_type==SD_CARD\
        ||gMSDC_Handle->mMSDC_type==SD20_HCS_CARD ||gMSDC_Handle->mMSDC_type==SD20_LCS_CARD\
        ||gMSDC_Handle->mMSDC_type==SD30_CARD)
    {
        status = SD_ReadSCR(scr);
        SD_INITIALIZE_STATUS_CHECK();

        status = SD_ReadSDStatus(sd_status);
        SD_INITIALIZE_STATUS_CHECK();
        
    	/*set bus width acmd6*/
        if (NO_SINGLE_LINE == gMSDC_Handle->trySingleLine)
        {
            status = SD_SetBusWidth(BIT_4W);
            SD_INITIALIZE_STATUS_CHECK();
        }
        else
        {
            gMSDC_Handle->trySingleLine&=~(TEMP_SINGLE_LINE);
        }
     
    	/*acmd42*/
    	#if !defined(__MSDC_TFLASH_DAT3_1BIT_HOT_PLUG__)
        status = SD_Acmd42(KAL_FALSE);
        SD_INITIALIZE_STATUS_CHECK();
    	#endif

        status=SD_SwitchSpeedMode();
        SD_INITIALIZE_STATUS_CHECK();
        
#if defined(MSDC_CONFIG_SD30_SUPPORT)
        if (gMSDC_Handle->mMSDC_type==SD30_CARD)
        {
         
            switch (gSD->function_set.function1)
            {
                case FUN1_SET_SDR104:
                    MSDC_SetClock(208000000,KAL_FALSE);
                    gMSDC_Handle->msdc_clkTuneUpperBund = 100000000;
                    break;
                case FUN1_SET_SDR50:
                    MSDC_SetClock(100000000,KAL_FALSE);
                    gMSDC_Handle->msdc_clkTuneUpperBund = 50000000;
                    break;
                case FUN1_SET_SDR25_HS:
                    MSDC_SetClock(50000000,KAL_FALSE);
                    gMSDC_Handle->msdc_clkTuneUpperBund = 25000000;
                    break;
                case FUN1_SET_SDR12_DS:
                    MSDC_SetClock(25000000,KAL_FALSE);
                    gMSDC_Handle->msdc_clkTuneUpperBund = 12500000;
                    break;
                case FUN1_SET_DDR50:
                    MSDC_SetClock(50000000,KAL_TRUE);
                    gMSDC_Handle->msdc_clkTuneUpperBund = 25000000;
                    break;
            }
        }
        else
#endif
        {
            if (gSD->function_set.function1==1)
            {
                MSDC_CRIT("[SD][%s %d]set Bus Clock to 50M(HS)\r\n",__FUNCTION__,__LINE__);
                MSDC_SetClock(50000000,KAL_FALSE);
                gMSDC_Handle->msdc_clkTuneUpperBund = 25000000;
            }
            else
            {
                MSDC_CRIT("[SD][%s %d]set Bus Clock to 25M(DS)\r\n",__FUNCTION__,__LINE__);
                MSDC_SetClock(25000000,KAL_FALSE);
                gMSDC_Handle->msdc_clkTuneUpperBund = 12500000;
            }
        }

        /* For SDA compliance test */
        if (((gSD->mSCR.spec_ver==SD_SPEC_101)||(gSD->mSCR.spec_ver==SD_SPEC_110)||(gSD->mCSD.csd_ver==CSD_VER_1_0))&&
             ((kal_uint32)(gSD->mCSD.capacity / (1024 * 1024)) > 2048)&&(status==NO_ERROR)) {
            status = ERR_STATUS;
            MSDC_ERR("[SD] We would not mount >2G Card which is compliant to SD1.x\r\n");
            goto err;
        }
        if (((gSD->mSCR.spec_ver<=SD_SPEC_200))&&
             ((kal_uint32)(gSD->mCSD.capacity / (1024 * 1024)) > 32768)&&(status==NO_ERROR)) {
            status = ERR_STATUS;
            MSDC_ERR("[SD] We would not mount >32GB Card which is compliant to SD2.0\r\n");
            goto err;
        }
    }
    else
    {
    	MSDC_CRIT("[SD][%s %d]init mmc \r\n",__FUNCTION__,__LINE__);
        //mmc card
#if defined(MSDC_MMC40_SUPPORT)
        if ((gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD) && gSD->mCSD.spec_ver >= 4)
        {
            if (gMSDC_Handle->mMSDC_type == MMC_CARD) /*we don't need to change MMC42_CARD to MMC40_CARD*/
                gMSDC_Handle->mMSDC_type = MMC40_CARD;
            status = SD_SetMMC40_bus_high_speed();
            SD_INITIALIZE_STATUS_CHECK();
            #if defined(MSDC_MMC441_SUPPORT)
            if ( gSD->mCSD.ext_csd->ext_csd_rev >= 5 )
            {
                // set ERASE_GROUP_DEF[175] before issuing read, write, erase, write protect
                status = SD_Switch_MMC40(SET_BYTE, EXT_CSD_ERASE_GRP_DEF, 1 , 0);
                SD_INITIALIZE_STATUS_CHECK();
            }
            #endif
        }
        else
#endif
        {
            MSDC_SetClock(13000000,KAL_FALSE);
        }
       
    }
    
    /* Set block length cmd16 */
    status = SD_SetBlength(512);
    SD_INITIALIZE_STATUS_CHECK();
    
err:

    if (status != NO_ERROR)
    {
    	MSDC_ERR("[SD][%s %d]mount fail %x\r\n",__FUNCTION__,__LINE__,status);
        SD_SetDefault();
        gMSDC_Handle->mIsInitialized = KAL_FALSE;
        gMSDC_Handle->mIsPresent = KAL_FALSE;
        MSDC_turnOnVMC(gMSDC_Handle->mIsPresent);
        MSDC_SetVddPower(KAL_FALSE, gMSDC_Handle->vdd_volt);
    	MSDC_PDNControl(KAL_TRUE);
     }
     else
     {
    	MSDC_CRIT("[SD][%s %d]mount ok %x\r\n",__FUNCTION__,__LINE__,status);
        gMSDC_Handle->mIsInitialized = KAL_TRUE;
     }
     
    /*reset event*/
     kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
    return status;

}

#ifdef __MEUT__
SDC_CMD_STATUS SD_SetCallBack(MSDC_CALLBACK callback1, MSDC_CALLBACK callback2, MSDC_CALLBACK callback3, MSDC_CALLBACK callback4, MSDC_CALLBACK callback5, MSDC_CALLBACK callback6)
{
     return 0;
}
SDC_CMD_STATUS SD_SetReadTestFlag(kal_uint32 readTestFlag)
{
     return 0;
}
SDC_CMD_STATUS SD_readTest(void)
{

     return 0;
}

SDC_CMD_STATUS SD_SetUpllClock(void)
{

    return 0;
}
#endif


void SD_InvertN(kal_uint8 *dest, kal_uint8 *src, kal_uint8 len)
{
    int i;

    for (i = 0; i < len; i++)
        *(dest + len - 1 - i) = *(src + i);

}
/*************************************************************************
* FUNCTION
*  power2
*
* DESCRIPTION
*	Calculate the power of 2
*
* PARAMETERS
*	num:
*
* RETURNS
*  2^num
*
* GLOBALS AFFECTED
*
*************************************************************************/
static kal_uint32 power2(kal_uint32 num)
{
    return 1 << num;
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCSD
*
* DESCRIPTION
*	Analysis Card Specific Data and store in the member of gSD
*
* PARAMETERS
*	csd: input csd for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCSD(kal_uint32* csd)
{
    kal_uint8 *ptr;
    kal_uint32 c_mult, c_size;

    ptr = (kal_uint8*)csd;
    c_mult = c_size = 0;
    // these offsets refer to the spec. of SD and MMC
    GetBitFieldN((kal_uint8*)&gSD->mCSD.csd_ver, ptr, 126, 2);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.tacc, ptr, 112, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.nsac, ptr, 104, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.tran_speed, ptr, 96, 8);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.ccc, ptr, 84, 12);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_len, ptr, 80, 4);
    gSD->mCSD.r_blk_len = power2(gSD->mCSD.r_blk_len);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_part, ptr, 79, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_misali, ptr, 78, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.r_blk_misali, ptr, 77, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.dsr_imp, ptr, 76, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_part, ptr, 21, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.w_blk_len, ptr, 22, 4);
    gSD->mCSD.w_blk_len = power2(gSD->mCSD.w_blk_len);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_enable, ptr, 31, 1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.temp_wp,ptr,12,1);
    GetBitFieldN((kal_uint8*)&gSD->mCSD.perm_wp,ptr,13,1);
    if (gSD->mCSD.temp_wp || gSD->mCSD.perm_wp)
        gSD->mWPEnabled = KAL_TRUE;

    // there are some difference of CSD between SD and MMC
    if (gMSDC_Handle->mMSDC_type == MMC_CARD || gMSDC_Handle->mMSDC_type == MMC42_CARD)
    {
        GetBitFieldN((kal_uint8*)&gSD->mCSD.spec_ver, ptr, 122, 4);
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_mmc, ptr, 42, 5);
        gSD->mCSD.erase_sec_size_mmc = (gSD->mCSD.erase_sec_size_mmc + 1) * gSD->mCSD.w_blk_len;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_grp_size_mmc, ptr, 37, 5);
        gSD->mCSD.erase_grp_size_mmc = (gSD->mCSD.erase_grp_size_mmc + 1) * gSD->mCSD.erase_sec_size_mmc;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_grp_size_mmc, ptr, 32, 5);
        gSD->mCSD.wp_grp_size_mmc = (gSD->mCSD.wp_grp_size_mmc + 1) * gSD->mCSD.erase_grp_size_mmc;
    }
    else // SD_CARD
    {
        if (gSD->mCSD.csd_ver == CSD_VER_2_0)
            gSD->mIsBlkAddr = 1;
        else
            gSD->mIsBlkAddr = 0;
            
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_sec_size_sd, ptr, 39, 7);
        gSD->mCSD.erase_sec_size_sd += 1;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.wp_prg_size_sd, ptr, 32, 7);
        gSD->mCSD.wp_prg_size_sd = (gSD->mCSD.wp_prg_size_sd + 1) * gSD->mCSD.erase_sec_size_sd;
        GetBitFieldN((kal_uint8*)&gSD->mCSD.erase_blk_en_sd, ptr, 46, 1);
    }

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if ((gMSDC_Handle->mMSDC_type == SD20_HCS_CARD||\
        gMSDC_Handle->mMSDC_type == SD30_CARD) && gSD->mCSD.csd_ver >= SD_CSD_VER_20)
    {
        GetBitFieldN((kal_uint8*)&c_size, ptr, 48, 22);
        gSD->mBKNum = (c_size + 1);
        gSD->mCSD.capacity = (kal_uint64)gSD->mBKNum * 512 * 1024;
    }
    else
#endif
    {
        GetBitFieldN((kal_uint8*)&c_mult, ptr, 47, 3);
        c_mult = power2(c_mult + 2);
        GetBitFieldN((kal_uint8*)&c_size, ptr, 62, 12);
        gSD->mBKNum = (c_size + 1) * c_mult;
        gSD->mCSD.capacity = (kal_uint64)(c_size + 1) * (kal_uint64)c_mult * (kal_uint64)gSD->mCSD.r_blk_len;
    }
    if (!(gSD->mCSD.ccc &CCC_BLOCK_WRITE))
        gSD->mWPEnabled = KAL_TRUE;  //unsupport write command

    MSDC_CRIT("[SD][%s %d]The capacity is %d MB, BLK_ADDR(%d)\r\n", __FUNCTION__, __LINE__,
        (kal_uint32)(gSD->mCSD.capacity / (1024 * 1024)), gSD->mIsBlkAddr);
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisCID
*
* DESCRIPTION
*	Analysis Card Identificaton and store in the member of gSD
*
* PARAMETERS
*	cid: input of card ID for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
*************************************************************************/
void SD_AnalysisCID(kal_uint32* cid)
{
    kal_uint8	i;
    kal_uint8* pcid;
    pcid = (kal_uint8*)cid;

    if (gMSDC_Handle->mMSDC_type == MMC_CARD || MMC42_CARD == gMSDC_Handle->mMSDC_type)
    {
        GetBitFieldN((kal_uint8*)&gSD->mCID.year, pcid, 8, 4);
        gSD->mCID.year += 1997;
        GetBitFieldN((kal_uint8*)&gSD->mCID.month, pcid, 12, 4);
        GetBitFieldN((kal_uint8*)&gSD->mCID.psn, pcid, 16, 32);
        GetBitFieldN((kal_uint8*)&gSD->mCID.prv, pcid, 48, 8);

        for (i = 0; i < 6; i++)
            gSD->mCID.pnm[i] = *(pcid + 7 + i);

        GetBitFieldN((kal_uint8*)&gSD->mCID.oid, pcid, 104, 16);
        GetBitFieldN((kal_uint8*)&gSD->mCID.mid, pcid, 120, 8);

        // special case handling
        {
            kal_uint8 pnm[] = {0xFF, 0xFF, 0xFF, 0xFF, 0x36, 0x31};

            if (gSD->mCID.mid == 6 && gSD->mCID.oid == 0 &&
                !kal_mem_cmp(gSD->mCID.pnm, pnm, 6))
            {
                gSD->flags |= SD_FLAG_MMC_MRSW_FAIL;
            }
        }
#ifdef __CMMB_CAS_FULL_CARD_SUPPORT__
        {
            kal_uint8 fullCardPnm[] = {0x55, 0x59, 0x4E, 0x41, 0x49, 0x54};

            if (!kal_mem_cmp(gSD->mCID.pnm, fullCardPnm, 6)) /*Tianyu does not provide MID and OID*/
            {
                SD_setFullCard(KAL_TRUE);
                gMSDC_Handle->msdc_clkTuneUpperBund = 15000;
            }
            else
                SD_setFullCard(KAL_FALSE);
        }
#endif

    }
    else // SD_CARD
    {
        gSD->mCID.mid = *(pcid + 15);
        gSD->mCID.oid = *(pcid + 13) + 256 * (*(pcid + 14));

        for (i = 0; i < 5; i++)
            gSD->mCID.pnm[i] = *(pcid + 8 + i);

        gSD->mCID.prv = *(pcid + 7);
        //gSD->mCID.psn = *(kal_uint32*)(pcid+3);
        gSD->mCID.psn = (*(kal_uint32*)(pcid + 4) << 8) | *(pcid + 3);
        gSD->mCID.month = (kal_uint8)GET_BIT(*(pcid + 1), 0, BIT_MASK_4);
        gSD->mCID.year = GET_BIT(*(pcid + 1), 4, BIT_MASK_4) + 16 * GET_BIT(*(pcid + 2), 0, BIT_MASK_4) + 2000;
    }

#ifdef MSDC_TRACE_LEVEL1
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_CID, gSD->mCID.mid, gSD->mCID.oid);
#endif
}

/*************************************************************************
* FUNCTION
*  SD_AnalysisSCR
*
* DESCRIPTION
*	Analysis SD Card Configuration Register and store in the member of gSD
*
* PARAMETERS
*	scr: input of scr for analysis
* RETURNS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	Only for SD card.
*
*************************************************************************/
void SD_AnalysisSCR(kal_uint32* scr)
{
    kal_uint8 *pscr;

    pscr = (kal_uint8*)scr;
    gSD->mSCR.spec_ver = (SD_SPEC)((kal_uint8)GET_BIT(*(pscr), 0, BIT_MASK_4));

    if (gSD->mSCR.spec_ver > SD_SPEC_101)
        gSD->flags |= SD_FLAG_CMD6_SUPPORT;

    gSD->mSCR.dat_after_erase = (kal_uint8)GET_BIT(*(pscr + 1), 7, BIT_MASK_1);
    gSD->mSCR.security = (kal_uint8)GET_BIT(*(pscr + 1), 4, BIT_MASK_3);
    gSD->mSCR.bus_width = (kal_uint8)GET_BIT(*(pscr + 1), 0, BIT_MASK_4);
    gSD->mSCR.cmd_support = (kal_uint8)GET_BIT(*(pscr + 3), 0, BIT_MASK_2);
    
    gSD->mSCR.sd_spec3 = (kal_uint8)GET_BIT(*(pscr + 2), 7, BIT_MASK_1);
    if ((gSD->mSCR.spec_ver == SD_SPEC_200) && (gSD->mSCR.sd_spec3))
        gSD->mSCR.spec_ver = SD_SPEC_30X;
    else
        gSD->mSCR.spec_ver = SD_SPEC_200;

    MSDC_CRIT("[SD] SD_SPEC(%d) SD_SPEC3(%d) SD_BUS_WIDTH=%d\r\n", 
            gSD->mSCR.spec_ver, gSD->mSCR.sd_spec3, gSD->mSCR.bus_width);
    MSDC_CRIT("[SD] SD_SECU(%d) CMD_SUPP(%d): CMD23(%d), CMD20(%d)\r\n", 
            gSD->mSCR.security, gSD->mSCR.cmd_support,
            (gSD->mSCR.cmd_support >> 1) & 0x1, gSD->mSCR.cmd_support & 0x1);
}

kal_uint32  SD_CmdPollResp(kal_uint32 * error,kal_uint32 pollTime_ms)
{
	kal_uint32 status;
	
	if (!MSDC_TIMEOUT_WAIT(MSDC_Reg32(MSDC_INT)&MSDC_CMD_INTS,pollTime_ms))
	{
		status=MSDC_Reg32(MSDC_INT);
		MSDC_WriteReg32(MSDC_INT,(status&MSDC_CMD_INTS));
		if (status & MSDC_INT_CMDTMO)
		{
			MSDC_ERR("[SD][%s %d]CMDTMO(%d)\r\n",__FUNCTION__,
			    __LINE__, gMSDC_Handle->cmd);
			*error=ERR_CMD_TIMEOUT;
		}
		else if (status & MSDC_INT_RSPCRCERR)
		{
			MSDC_ERR("[SD][%s %d]CMDCRC(%d)\r\n",__FUNCTION__,
			    __LINE__, gMSDC_Handle->cmd);
			*error=ERR_CMD_RSPCRCERR;
		}
		else if (status & MSDC_INT_CMDRDY)
		{
			*error=NO_ERROR;
		}
		/*we get the interrupt information*/
		return 0;
	}
	/*polling  timeout ,so we need sleep and  try wait interrupt*/
	return 1;	//tiemeout
}

/*************************************************************************
* FUNCTION
*  SD_WaitCmdRdyOrTo
*
* DESCRIPTION
*	Wait until command ready or timeout
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
SDC_CMD_STATUS SD_WaitCmdRdyOrTo(void)
{
	kal_uint32 ret;
	kal_uint32 status;
	kal_uint32 flag;
	/*poll 5 ms first to check response*/
	ret=SD_CmdPollResp(&(gMSDC_Handle->error),5);
	if (ret)
	{
		MSDC_START_TIMER(MSDC_CMD_TIMEOUT/10);
		/*enable interrupt*/
		MSDC_SetBits32(MSDC_INTEN,MSDC_CMD_INTS|MSDC_INT_CDSC);
		/*use interrupt handler*/
		kal_retrieve_eg_events(gMSDC_Handle->MSDC_Events,EVENT_CMD_DONE,KAL_OR_CONSUME,&flag,KAL_SUSPEND);	
		/*disable interrupt*/
		MSDC_ClearBits32(MSDC_INTEN, MSDC_CMD_INTS);
		MSDC_STOP_TIMER();
        if (gMSDC_Handle->is_timeout)
        {
            gMSDC_Handle->error=MSDC_GPT_TIMEOUT_ERR;
        }
        else
        {
    		status=gMSDC_Handle->msdc_int&MSDC_CMD_INTS;
    		
    		if (status &MSDC_INT_CMDRDY)
    		{
    			gMSDC_Handle->error=NO_ERROR;
    		}
    		else if (status& MSDC_INT_CMDTMO)
    		{
    			MSDC_ERR("[SD][%s %d]CMDTMO(%d), MSDC_CMD_INTS:%x\r\n",__FUNCTION__,
    			    __LINE__, gMSDC_Handle->cmd, status);
    			gMSDC_Handle->error=ERR_CMD_TIMEOUT;
    		}
    		else if (status & MSDC_INT_RSPCRCERR)
    		{
    			MSDC_ERR("[SD][%s %d]CMDCRC(%d), MSDC_CMD_INTS:%x\r\n",__FUNCTION__,
    			    __LINE__, gMSDC_Handle->cmd, status);
    			gMSDC_Handle->error=ERR_CMD_RSPCRCERR;
    		}
    		else
    		{
    			MSDC_ERR("[SD][%s %d]ERR(%d), MSDC_CMD_INTS:%x\r\n",__FUNCTION__,
    			    __LINE__, gMSDC_Handle->cmd, status);
    			gMSDC_Handle->error=ERR_CMD_TIMEOUT;
    		}
    		ret=status;
        }
	}
	return gMSDC_Handle->error;
}

/*************************************************************************
* FUNCTION
*  SD_WaitDatRdyOrTo
*
* DESCRIPTION
*	Wait until data ready or timeout ,just for pio read and write
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	just polling 
*
*************************************************************************/
	SDC_CMD_STATUS SD_WaitDatRdyOrTo(kal_uint32 *buffer,kal_uint32 byte_len,kal_bool isWrite)
	{
		kal_uint32 intsts;
		kal_uint8 * u8ptr;
		kal_uint32 * ptr;
        ptr=buffer;
        
		gMSDC_Handle->abort=0;
		MSDC_SetBits32(MSDC_INTEN,MSDC_INTEN_DATTMO|MSDC_INTEN_DATCRCERR);
		if(!isWrite)
		{
			/*poll to read data from FIFO*/
			while(byte_len)
			{
			   
				if ((byte_len>=MSDC_FIFO_THD)&&(MSDC_RXFIFOCNT()>=MSDC_FIFO_THD)){
					int count =MSDC_FIFO_THD>>2;	
					do{
						*ptr++=MSDC_FIFO_READ32();
					}while(--count);
					byte_len-=MSDC_FIFO_THD;
					
				}
				else if  ((byte_len<MSDC_FIFO_THD)&&(MSDC_RXFIFOCNT()>=byte_len))
				{
					while(byte_len>3){
						*ptr++=MSDC_FIFO_READ32();
						byte_len-=4;
					}
					u8ptr=(kal_uint8 *)ptr;
					while(byte_len){
						*u8ptr++=MSDC_FIFO_READ8();
						byte_len--;
					}
				}
				if (gMSDC_Handle->abort){
				   	gMSDC_Handle->abort=0;
					MSDC_ERR("[SD][%s %d]pio read abort ,byte_len=%d \r\n",__FUNCTION__,__LINE__,byte_len);
					break;
				}
			}
		}
		else
		{
			/*poll to write data into FIFO*/
			while(byte_len){
				if (byte_len >= MSDC_FIFO_SZ){
					if (MSDC_TXFIFOCNT()==0){
						int count =MSDC_FIFO_SZ>>2;
						do {
							MSDC_FIFO_WRITE32(*ptr);
							ptr++;
						}while(--count);
						byte_len-=MSDC_FIFO_SZ;
					}
				}
				else if ((byte_len<MSDC_FIFO_SZ)&&(MSDC_TXFIFOCNT()==0)){
					while(byte_len){
						while(byte_len>3){
							MSDC_FIFO_WRITE32(*ptr);
							ptr++;
							byte_len-=4;
						}
						u8ptr=(kal_uint8 *)ptr;
						while(byte_len){
							MSDC_FIFO_WRITE8(*u8ptr);
							u8ptr++;
							byte_len--;
						}
					}
				}
				if (gMSDC_Handle->abort)
				{
					gMSDC_Handle->abort=0;
					MSDC_ERR("[SD][%s %d]pio write abort ,byte_len=%d \r\n",__FUNCTION__,__LINE__,byte_len);
					break;
				}
			}
			
		}
		
		MSDC_ClearBits32(MSDC_INTEN, MSDC_INTEN_DATTMO|MSDC_INTEN_DATCRCERR);
		if (byte_len)
			goto end;
		intsts =MSDC_PollInts(MSDC_INT_XFER_COMPL|MSDC_INT_DATTMO|MSDC_INT_DATCRCERR,100);
		MSDC_DEBUG("[SD][%s %d]intsts =%x \r\n",__FUNCTION__,__LINE__,intsts);
		MSDC_CLR_FIFO();
		if (intsts&MSDC_INT_XFER_COMPL)
		{
			gMSDC_Handle->error=NO_ERROR;
		}
		else if (intsts&MSDC_INT_DATCRCERR){
			gMSDC_Handle->error=ERR_DAT_CRCERR;
		}
		else if (intsts&MSDC_INT_DATTMO)
		{
			gMSDC_Handle->error=ERR_DAT_TIMEOUT;
		}
end:
		if (gMSDC_Handle->error)
		{
			MSDC_FatalErrorHandle();
		}
		
		/*wait busy for write operation*/
		if (isWrite)
		{
		    dbg_print("isWrite=%x ,go to MSDC_CheckCardBusy",isWrite);
			MSDC_CheckCardBusy(KAL_FALSE,30*1000);
		}
		return gMSDC_Handle->error;
	}

/*************************************************************************
* FUNCTION
*  SD_WaitCardNotBusy
*
* DESCRIPTION
*	Wait until card is not busy (R1b)
*
* PARAMETERS
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*
* NOTE
*	Interrupt driven and polling are both implemented
*
*************************************************************************/
extern kal_bool FTL_isPollingMode();
kal_uint32 direct_msdc_entry = 0;

SDC_CMD_STATUS SD_WaitCardNotBusy(kal_uint32 timeout_ms)
{
    	if(MSDC_TIMEOUT_WAIT((!SD_IS_R1B_BUSY())&&MSDC_Check_Card_Present(),timeout_ms))
    	{
    		gMSDC_Handle->error=ERR_CMD_TIMEOUT;
    		MSDC_ERR("[SD][%s %d]R1B busy timeout ,wait %d ms\r\n",__FUNCTION__,__LINE__,timeout_ms);
    		return ERR_CMD_TIMEOUT;
    	}
	return  NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_CheckStatus
*
* DESCRIPTION
*	Check command status
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_CheckStatus(void)
{
	     kal_uint32 status;

	    status= MSDC_Reg32(SDC_RESP0);
	    if ((status & SDC_CSTA_MASK) == 0 )
	        return NO_ERROR;

	    MSDC_ERR("[SD][%s %d]check status<%x>\r\n",__FUNCTION__,__LINE__,status);
	    if (status & SDC_CARD_IS_LOCKED)
	    {
	    	
	        return CARD_IS_LOCKED;
	    }
	    return ERR_STATUS;
    
}



/*************************************************************************
* FUNCTION
*  SD_Send_Cmd
*
* DESCRIPTION
*	to launch the command packet to the card
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	1. Check if controller is available  before launch any commands
*	2. Maybe add check if card is busy (R1b)
*************************************************************************/
SDC_CMD_STATUS SD_SendCmdOnly( kal_uint32 cmd, kal_uint32 arg,kal_uint32 timeout_ms)
{
	kal_uint32 retry_count=0;
check_busy:
	/*wait CMD busy and SDC busy*/
   	if (cmd == SDC_CMD_CMD12||cmd==SDC_CMD_CMD13)
   	{
		if (MSDC_TIMEOUT_WAIT((!SD_IS_CMD_BUSY()),timeout_ms))
   		{
			gMSDC_Handle->error=ERR_CMD_TIMEOUT;
			MSDC_FatalErrorHandle();
			MSDC_ERR("[SD][%s %d]wait cmd busy timeout !!,retry %d times\r\n",__FUNCTION__,__LINE__,retry_count);
		}
   	}
   	else
   	{
		if (MSDC_TIMEOUT_WAIT((!SD_IS_SDC_BUSY()), timeout_ms))
		{
			gMSDC_Handle->error=ERR_CMD_TIMEOUT;
			MSDC_FatalErrorHandle();
			MSDC_ERR("[SD][%s %d]wait SDC busy %d ms timeout!!,retry %d times\r\n",__FUNCTION__,__LINE__,timeout_ms,retry_count);
			goto retry;
		}
   	}
	if (gSD->mBKLength&&(gSD->mBKLength <= 0xfff))
	{
		cmd|=(gSD->mBKLength<<16);
	}

    /* If the card supports CMD23, enable AUTOCMD23 function of MSDC */
    if (((cmd & 0x3F) == 18) || ((cmd & 0x3F) == 25)) {
        if ((gSD->mSCR.cmd_support >> 1) & 0x1)
            cmd |= (2 << 28);
    }

    MSDC_DEBUG("[SD]CMD=%d, arg=%X\r\n", cmd & 0x3F, arg);
	
	/*set argument*/
	MSDC_WriteReg32(SDC_ARG,arg);
	/*set command*/
	MSDC_WriteReg32(SDC_CMD,cmd);
	gMSDC_Handle->cmd = (kal_uint8)(cmd & 0x3F);
    gMSDC_Handle->error=NO_ERROR;
	return gMSDC_Handle->error;
	
retry:
	if ((!SD_IS_SDC_BUSY())&&(retry_count<3)){
		retry_count++;
		goto check_busy;
	}
	return gMSDC_Handle->error;
	
}

#define MSDC_TUNE_CMD_RESP_TA_MAX           (8)
#define MSDC_TUNE_INT_DAT_LATCH_CK_MAX      (8)
#define MSDC_TUNE_WCRC_TA_MAX               (8)

static kal_uint8 fgCMDTuneLargeScale = 1;
static kal_uint32 times_large = 0;
static kal_uint32 times_small = 0;

static kal_uint8 fgWrTuneLargeScale = 1;
static kal_uint32 times_large_w = 0;
static kal_uint32 times_small_w = 0;

static kal_uint8 fgReadTuneLargeScale = 1;
static kal_uint32 times_large_r = 0;
static kal_uint32 times_small_r = 0;
    
static kal_uint32 msdc_tune_cmd_retry(kal_uint32 cmd, kal_uint32 arg, kal_uint32 timeout_ms)
{
    kal_uint32 result = ERR_CMD_RSPCRCERR;

    /* CMD12 CRCERR should not tune */
    if ((cmd & 0x3F) == 12) {
        result = NO_ERROR;
        goto done;
    }
    
    /* Send 'STOP' command to complete 'TRANS' state */
    if (MSDC_Reg32(SDC_CMD)&0x1800)
    {
        /*check if has data phase*/
        result=SD_SendCmdOnly(SDC_CMD_CMD12,SDC_NO_ARG,1000);
        result=SD_WaitCmdRdyOrTo();
        if (result!=NO_ERROR)
            goto err;
    }
    
    if (gMSDC_Handle->app_cmd)
    {
        /*for acmd ,we should send cmd55 again*/
        result=SD_SendCmdOnly(SDC_CMD_CMD55,gSD->mRCA,1000);
        if (result!=NO_ERROR)
            goto err;
        result=SD_WaitCmdRdyOrTo();
        if (result!=NO_ERROR)
            goto err;
    }
    
    result=SD_SendCmdOnly(cmd,arg,timeout_ms);

    if (result!=NO_ERROR)
        goto err;
        
    result=SD_WaitCmdRdyOrTo();
    if (result==NO_ERROR)
        goto done;
    if (result != ERR_CMD_RSPCRCERR)
        goto err;

err:
    MSDC_FatalErrorHandle();
done:    
    return result;
}

kal_uint32 msdc_tune_cmd_large_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 clk_mode, cmd_resp_ta_cntr, r_smpl;

    times_large++;
    
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, cmd_resp_ta_cntr);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl);

    /* 
     * If MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz 
     * that is ultra high speed mode, tune CMD_RESP_TA first
     */
    if ((clk_mode == 1) || (clk_mode == 2) || 
        (gMSDC_Handle->op_clock >= MSDC_TUNE_UHS_SCLK)) {
        cmd_resp_ta_cntr++;
        MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, 
            cmd_resp_ta_cntr & (MSDC_TUNE_CMD_RESP_TA_MAX - 1));

        if (cmd_resp_ta_cntr >= MSDC_TUNE_CMD_RESP_TA_MAX) {
            r_smpl++;
            MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl % 2);
        }
    }
    else {
        /* 
         * In low speed mode, just tune R_SMPL 
         * and set MSDC_CMD_RSP_TA_CNTR back to 0
         */
        r_smpl++;
        cmd_resp_ta_cntr = 0;
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl % 2);
        MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, cmd_resp_ta_cntr & 
            (MSDC_TUNE_CMD_RESP_TA_MAX - 1));
    }

    /* Now all the parameters are set to 0 */
    if (r_smpl >= 2)
        ret = 1;

    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, cmd_resp_ta_cntr);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl);
    
    MSDC_NOTICE("[SD] <TUNE_CMD_LS><%d> CKMOD=%d, CMD_RSP_TA=%d, R_SMPL=%d\r\n",
            times_large, clk_mode, cmd_resp_ta_cntr, r_smpl);
   
    if (ret)
        times_large = 0;

    return ret;
}

kal_uint32 msdc_tune_cmd_small_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 cmd_rxdly, clk_mode, cmd_resp_ta_cntr, r_smpl;

    times_small++;
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, cmd_resp_ta_cntr);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl);
    MSDC_GET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY, cmd_rxdly);

    /* Adjust CMD_RXDLY in PAD macro */
    cmd_rxdly++;
    MSDC_SET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY, cmd_rxdly & 0x1F);

    /* Adjust R_SMPL */
    if (cmd_rxdly >= 32) {
        r_smpl++;
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl % 2);
    }

    /* 
     * Adjust CMD_RSP_TA_CNTR
     * if MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz
     */
    if (r_smpl >= 2) {
        if ((clk_mode == 1) || (clk_mode == 2) || (gMSDC_Handle->op_clock >= MSDC_TUNE_UHS_SCLK)) {
            cmd_resp_ta_cntr++;
            MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, 
                cmd_resp_ta_cntr & (MSDC_TUNE_CMD_RESP_TA_MAX - 1));

            if (cmd_resp_ta_cntr >= MSDC_TUNE_CMD_RESP_TA_MAX) 
                ret = 1;
        }
        else
            ret= 1;
    }

    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, cmd_resp_ta_cntr);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RSPL, r_smpl);
    MSDC_GET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY, cmd_rxdly);

    MSDC_NOTICE("[SD] <TUNE_CMD_SS><%d> CMD_RXDLY=%d, R_SMPL=%d, CMD_RSP_TA=%d\r\n",
            times_small, cmd_rxdly, r_smpl, cmd_resp_ta_cntr);

    /* Now all the parameters are set to 0 */
    if (ret)
        times_small = 0;
        
    return ret;    
}

SDC_CMD_STATUS SD_CmdTuneResp(kal_uint32 cmd,kal_uint32 arg,kal_uint32 timeout_ms)
{
    kal_uint32 result = ERR_CMD_RSPCRCERR;
    
    do {
        /* Retry the CMD with error handling */
        result = msdc_tune_cmd_retry(cmd, arg, timeout_ms);

        if ((result == ERR_CMD_TIMEOUT) ||
            (result == NO_ERROR)) {
            if (result == NO_ERROR) {
                if (times_large)
                    fgCMDTuneLargeScale = 0;

                times_small = 0;
            }
            goto done;
        }

        /* Large scale timing tuning */
        if (fgCMDTuneLargeScale) {
            if (msdc_tune_cmd_large_scale())
                fgCMDTuneLargeScale = 0;
        } 
        /* Small scale timing tuning */
        else {
            if (msdc_tune_cmd_small_scale())
                goto done;
        }

    } while (1);

done:
    MSDC_CRIT("[SD] <TUNE_CMD%d_DONE>", cmd & 0x3F);
    if (result == NO_ERROR) 
        MSDC_CRIT(" %s\r\n", "PASS");
    else if (result == ERR_CMD_RSPCRCERR)
        MSDC_CRIT(" %s\r\n", "CRCERR");
    else if (result == ERR_CMD_TIMEOUT)
        MSDC_CRIT(" %s\r\n", "TIMEOUT");

    return result;
}

SDC_CMD_STATUS SD_SendCmd(kal_uint32 cmd,kal_uint32 arg,kal_uint32 timeout_ms)
{
	kal_uint32 status;
	/*send command */
	status = SD_SendCmdOnly(cmd,arg,timeout_ms);
	if (status!=NO_ERROR)
	{
		MSDC_ERR("[SD][%s %d]send cmd %d error \r\n",__FUNCTION__,__LINE__,cmd);
		return status;
	}
	/*wait command complete*/
	status=SD_WaitCmdRdyOrTo();
	if (status != NO_ERROR)
	{
		MSDC_FatalErrorHandle();
		if (status == ERR_CMD_RSPCRCERR)
		{
			SD_CmdTuneResp(cmd, arg,timeout_ms);
		}
		status = gMSDC_Handle->error;
		
		return status;
	}
	if (cmd== SDC_CMD_CMD55 )
	{
		gMSDC_Handle->app_cmd=1;
	}
	else
    {
		gMSDC_Handle->app_cmd=0;
		
	}
	return status;
}
kal_uint32 SD_PioRead(kal_uint32 * buffer,kal_uint32 num)
{
	kal_uint32 *ptr=buffer;
	kal_uint8 *u8ptr;
	kal_uint32 left;
	ptr =buffer;
	left=num;
	while(left)
	{
		if ((left>=MSDC_FIFO_THD)&&(MSDC_RXFIFOCNT()>=MSDC_FIFO_THD)){
			int count =MSDC_FIFO_THD>>2;	
			do{
				*ptr++=MSDC_FIFO_READ32();
			}while(--count);
			left-=MSDC_FIFO_THD;
			
		}
		else if  ((left<MSDC_FIFO_THD)&&(MSDC_RXFIFOCNT()>=left))
		{
			while(left>3){
				*ptr++=MSDC_FIFO_READ32();
				left-=4;
			}
			u8ptr=(kal_uint8 *)ptr;
			while(left){
				*u8ptr++=MSDC_FIFO_READ8();
				left--;
			}
			
			if (gMSDC_Handle->abort){
				gMSDC_Handle->abort=0;
				MSDC_ERR("[SD][%s %d]pio read abort!!, num= %d \r\n",__FUNCTION__,__LINE__,num);
				goto end;
			}
		}
	}
end:
	return left;
}

kal_uint32 SD_PioWrite(kal_uint32 * buffer,kal_uint32 num)
{
	kal_uint32 * ptr=buffer;
	kal_uint8 *u8ptr;
	kal_uint32 left;
	ptr=buffer;
	left=num;
	while(left){
		if (left >= MSDC_FIFO_SZ){
			if (MSDC_TXFIFOCNT()==0){
				int count =MSDC_FIFO_SZ>>2;
				do {
					MSDC_FIFO_WRITE32(*ptr);
					ptr++;
				}while(--count);
				left-=MSDC_FIFO_SZ;
			}
		}
		else if ((left<MSDC_FIFO_SZ)&&(MSDC_TXFIFOCNT()==0)){
			while(left){
				while(left>3){
					MSDC_FIFO_WRITE32(*ptr);
					ptr++;
					left-=4;
				}
				u8ptr=(kal_uint8 *)ptr;
				while(left){
					MSDC_FIFO_WRITE8(*u8ptr);
					u8ptr++;
					left--;
				}
			}
		}
		if (gMSDC_Handle->abort)
		{
			gMSDC_Handle->abort=0;
			MSDC_ERR("[SD][%s %d]pio write abort %d \r\n",__FUNCTION__,__LINE__,num);
			goto done;
		}
	}

done:
	return left;
}

#if !defined(MSDC_QMU_ENABLE)
static kal_uint8 msdc_cal_checksum(const void *buf,kal_uint32 len)
{
    kal_uint32 i,sum=0;
    kal_char *data=(char*)buf;
    for(i=0;i<len;i++)
    {
        sum+=*data++;
    }
    return 0xFF-(kal_uint8)sum;
}
#endif

static DCL_STATUS SD_ConfigGpdList(kal_uint32 size)
{
#if !defined(MSDC_QMU_ENABLE)
    kal_uint32 i,buflen,data_count;
    kal_uint32 * data_ptr;
    kal_uint32 t1;
    qbm_gpd* cur_gpd=NULL,*cur_bd=NULL;
    msdc_gpd_t *gpd;
    msdc_gpd_t *gpd_end;
    qbm_gpd *head;
    qbm_gpd *tail;
    kal_uint8 sel = 0;
    
    #define CONFIG_GPDLIST_TIMEOUT 10000
    
    head = MSDC_Blk[sel].head;
    tail = MSDC_Blk[sel].tail;
    gpd = MSDC_Blk[sel].gpd;
    gpd_end = MSDC_Blk[sel].gpd_end;
    
    gpd->intr   =1;     /*don't generate DMA_done interrupt*/
    gpd->extlen =0;     /*ignore cmd,arg etc*/
    gpd->hwo    =1;     /*config hardware owner*/
    gpd->bdp    =1;     /*use buffer descriptor list*/
    gpd->ptr    =(void*)(&MSDC_bd[sel][0]);
    gpd->next   =(void*)gpd_end;
    
    #ifdef MSDC_DMA_CHKSUM_EN
    gpd->chksum =0;
    gpd->chksum =msdc_cal_checksum(gpd,16);
    #endif
   
    gpd_end->intr   =0;     /*don't generate DMA_done interrupt*/
    gpd_end->extlen =0;     /*ignore cmd,arg etc*/
    gpd_end->hwo    =0;     /*config hardware owner*/
    gpd_end->bdp    =0;     /*use buffer descriptor list*/
    gpd_end->ptr    =0;
    gpd_end->next   =NULL;

    #ifdef MSDC_DMA_CHKSUM_EN
    gpd_end->chksum =0;
    gpd_end->chksum =msdc_cal_checksum(gpd_end,16);
    #endif
    
    data_count = 0;
    t1 = drv_get_current_time();
    
    for (i=0,cur_gpd=head;;cur_gpd=QBM_DES_GET_NEXT(cur_gpd)) {
        if (i > MSDC_BD_MAX)
        {
            MSDC_ERR("[%s %d]qbm_gpd list is to long,only supprot %d object \r\n",__FUNCTION__,__LINE__,MSDC_BD_MAX);
            return STATUS_INVALID_ARGUMENT;
        }

        /* NULL pointer check */
        if (cur_gpd == NULL) {
            MSDC_ERR("[%s %d]cur_gpd is NULL pointer!\r\n",__FUNCTION__,__LINE__);
            return STATUS_INVALID_ARGUMENT;
        }
        
        if (QBM_DES_GET_BDP(cur_gpd))
        {
            // if GPD with BD with data buffer
            cur_bd=QBM_DES_GET_DATAPTR(cur_gpd);
            while(1)
            {
                buflen=QBM_DES_GET_DATALEN(cur_bd);
                data_ptr=(kal_uint32 *)QBM_DES_GET_DATAPTR(cur_bd);
                if ((data_count+buflen)>size)
                { //if buffer length is large the secotors we want to transfer            
                   buflen=size-data_count;
                   data_count=size;
                }
                else
                {
                    data_count+=buflen;
                }
                if (buflen)
                { // if point to a buffer adress on this BD
                    
                    if (((cur_gpd==tail)&&(QBM_DES_GET_EOL(cur_bd)))||(data_count==size))
                        MSDC_bd[sel][i].eol     =1;
                    else
                        MSDC_bd[sel][i].eol     =0;
                    MSDC_bd[sel][i].next    =&MSDC_bd[sel][i+1];
                    MSDC_bd[sel][i].ptr     =data_ptr;               
                    MSDC_bd[sel][i].buflen  =buflen;
                    clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)data_ptr),CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)data_ptr,buflen));                 
                    MSDC_bd[sel][i].blkpad   =0;
                    MSDC_bd[sel][i].dwpad   =0;
                    MSDC_bd[sel][i].chksum=0;
                    MSDC_bd[sel][i].chksum=msdc_cal_checksum(&MSDC_bd[sel][i],16);
                    i++;
                }          
                if(QBM_DES_GET_EOL(cur_bd))
                {
                    break;
                }
                cur_bd=QBM_DES_GET_NEXT(cur_bd);
            }
        }
        else
        {   
            // if GPD with data buffer
            buflen=QBM_DES_GET_DATALEN(cur_gpd);
            //dbg_print("%d  buflen=%d\r\n",i,buflen);
            data_ptr=(kal_uint32 *)QBM_DES_GET_DATAPTR(cur_gpd);
            if ((data_count+buflen)>size)
            {             
               buflen=size-data_count;
               data_count=size;
               //dbg_print("entry last data_count %d,buflen %d size %d\r\n",data_count,buflen,size);
            }
            else
            {
                data_count+=buflen;
            }
            if (buflen)
            {
                if (cur_gpd==tail||data_count==size)
                    MSDC_bd[sel][i].eol     =1;
                else
                    MSDC_bd[sel][i].eol     =0;
                MSDC_bd[sel][i].next    =&MSDC_bd[sel][i+1];
                MSDC_bd[sel][i].ptr     =data_ptr;               
                MSDC_bd[sel][i].buflen  =buflen;

                /* 
                 * There is NO need to clean the data cache, which is transfered
                 * from MSD and USB, because the buffer is directly read or write 
                 * by DMA, CPU are not involved in.
                 */
                #if defined(MSDC_SCAT_BUF_FLUSH) || defined(ATEST_DRV_MSDC)
                clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)data_ptr),CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)data_ptr,buflen));
                #endif
                
                MSDC_bd[sel][i].blkpad   =0;
                MSDC_bd[sel][i].dwpad   =0;

                #ifdef MSDC_DMA_CHKSUM_EN
                MSDC_bd[sel][i].chksum=0;
                MSDC_bd[sel][i].chksum=msdc_cal_checksum(&MSDC_bd[sel][i], 16);
                #endif
                
                i++;
            }          
        }
        if (cur_gpd==tail)
            break;
            
    }

    if (drv_get_duration_ms(t1)>CONFIG_GPDLIST_TIMEOUT)
    {
        MSDC_INFO("[%s %d]config gpd list timeout\r\n",__FUNCTION__,__LINE__,MSDC_BD_MAX);
        return STATUS_INVALID_ARGUMENT;
    }
    
    //if data buffer is not enough 
    if (data_count!=size)
    {
        MSDC_INFO("[%s %d]data_count %d,size %d\r\n",__FUNCTION__,__LINE__,data_count,size);
        return STATUS_INVALID_ARGUMENT;
    }

    /* Flush the GPD and BD from cache to memory */
    #ifdef MSDC_GPD_BD_BUF_CACHED
    clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)gpd),
        CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)gpd, sizeof(msdc_gpd_t)));
    clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)gpd_end),
        CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)gpd_end, sizeof(msdc_gpd_t)));
    clean_and_invalidate_dcache(CPU_CACHE_LINE_ALIGN_ADDR((kal_uint32)&MSDC_bd[sel][0]),
        CPU_CACHE_LINE_ALIGN_LEN((kal_uint32)&MSDC_bd[sel][0], i * sizeof(msdc_bd_t)));
    #endif

    return STATUS_OK;

#else
    
    qbm_gpd *head, *tail, *p_bps_gpd, *p_cur_gpd;
    kal_uint8 sel = 0;
        
    head = MSDC_Blk[sel].head;
    tail = MSDC_Blk[sel].tail;

    /* In case of normal transfer */
    if (!gMSDC_Handle->f_tuning) {
        p_bps_gpd = g_p_msdc_bps[sel];
        if (!p_bps_gpd) {
            MSDC_ERR("[%s %d]Invalid loacal bypass GPD buffer!\r\n",__FUNCTION__,__LINE__);
            return STATUS_FAIL;
        }

        /* Link the bypass GPD to tail */
        qbmt_common_en_q_rx(p_bps_gpd, p_bps_gpd, (void **)&head, (void **)&tail);

        /* Set HWO = 1, cause it is cleared by USB QMU */
        p_cur_gpd = head;
        do {
            if (p_cur_gpd == tail)
                break;

            QBM_DES_SET_HWO(p_cur_gpd);
            QBM_CACHE_FLUSH(p_cur_gpd, 2);

            p_cur_gpd = p_cur_gpd->p_next;
        } while(1);
    }
    /* In case of re-try on tuning */
    else {
        p_cur_gpd = head;

        /* Re-Set HWO = 1, and flush cache */
        do {
            QBM_DES_SET_HWO(p_cur_gpd);
            QBM_CACHE_FLUSH(p_cur_gpd, sizeof(qbm_gpd));

            if ((p_cur_gpd == tail))
                break;

            p_cur_gpd = p_cur_gpd->p_next;

        } while(1);
    }

    /* Set the QMU start address */
    gMSDC_Handle->buf_addr = (void *)MSDC_Blk[sel].head;
		    
    return STATUS_OK;
    
#endif
}

SDC_CMD_STATUS SD_ReqHandleData(kal_uint32 data_adrs, void* buffer, kal_uint32 num,kal_bool isWrite,kal_bool isLinkListBuf)
{
	kal_uint32 status ;
	kal_bool dma;
	kal_uint32 intsts;
	kal_uint8 cmd23_sup = 0;

    MSDC_INFO("[SD]SD_Req: CMD%s Addr=%x BlkNum=%d Buf=%x\r\n", 
        isWrite ? "25(24)" : "18(17)", data_adrs, num, buffer);

	/*Set block size and block num*/
	if (gSD->mBKLength!=512)
	{
		status =SD_SetBlength(512);
		if (status != NO_ERROR)
		{
			return status;
		}
			
	}
	MSDC_WriteReg32(SDC_BLK_NUM,num);
	/*set read timeout*/
	/*check we use dma or pio*/
	if(gSD->mBKLength*num <512)
	{
		/*use pio*/
		dma=0;
		//set to PIO mode
  		 BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
		gMSDC_Handle->dma_xfer=0;
	}
	else
	{
		/*use dma*/
		dma=1;
		//set to DMA mode
   		BitFieldWrite32((kal_uint32 *)MSDC_CFG, 0, MSDC_CFG_PIO);
		gMSDC_Handle->dma_xfer=1;
	}
	
	dma=1;						/*driver unsupport PIO now*/
	gMSDC_Handle->dma_xfer=1;
	if (dma)
	{
		kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0,KAL_AND);
		/*enable DMA*/
		MSDC_ClearBits32(MSDC_CFG,MSDC_CFG_PIO);
		/*start command*/
        if (!isWrite)
        {
            if (num==1)
            {
                status=SD_SendCmdOnly(SDC_CMD_CMD17,data_adrs,MSDC_CMD_TIMEOUT);
            }
            else
            {
		        status=SD_SendCmdOnly(SDC_CMD_CMD18,data_adrs,MSDC_CMD_TIMEOUT);
            }
        }
        else
        {
            if (num==1)
            {
                status=SD_SendCmdOnly(SDC_CMD_CMD24,data_adrs,MSDC_CMD_TIMEOUT);
            }
            else
            {
                status=SD_SendCmdOnly(SDC_CMD_CMD25,data_adrs,MSDC_CMD_TIMEOUT);
            }
        }
		if (status !=NO_ERROR)
		{
			goto done;
		}
		/*map dma data*/
		
		/*config dma*/
		gMSDC_Handle->total_count=num*gSD->mBKLength;
		gMSDC_Handle->buf_addr=buffer;

		if (isLinkListBuf) {
		    status = SD_ConfigGpdList(gMSDC_Handle->total_count);
		    if (status != STATUS_OK) {
		        MSDC_ERR("[%s %d]Config GPD list fail!\r\n",__FUNCTION__,__LINE__);
		        return status;
		    }
		}
		    
		MSDC_DMATransferFirst(isWrite,isLinkListBuf);
		
		/*wait cmd rsp*/
		status=SD_WaitCmdRdyOrTo();
		if (status != NO_ERROR)
		{
			MSDC_FatalErrorHandle();
			if (status == ERR_CMD_RSPCRCERR)
			{
			    if (!isWrite)
                {   if (num==1)      
				        status=SD_CmdTuneResp(SDC_CMD_CMD17, data_adrs,MSDC_CMD_TIMEOUT);
                    else
                        status=SD_CmdTuneResp(SDC_CMD_CMD18, data_adrs,MSDC_CMD_TIMEOUT);   
                }
                else
                {
                    if(num==1)
                        status=SD_CmdTuneResp(SDC_CMD_CMD24, data_adrs,MSDC_CMD_TIMEOUT);
                    else
                        status=SD_CmdTuneResp(SDC_CMD_CMD25, data_adrs,MSDC_CMD_TIMEOUT);     
                }
			}
			if(status != NO_ERROR)
			    goto done;
		}
		/*start dma and wait data complete*/
		status = MSDC_DMATransferFinal(isWrite,isLinkListBuf);
	}
	else
	{
		/*pio mode*/
		if (SD_SendCmd(((isWrite==KAL_TRUE) ?SDC_CMD_CMD25:SDC_CMD_CMD18),data_adrs,MSDC_CMD_TIMEOUT))
		{
			goto done;
		}
		MSDC_SetBits32(MSDC_INTEN,MSDC_INTEN_DATTMO|MSDC_INTEN_DATCRCERR);
		if(!isWrite)
		{
			/*poll to read data from FIFO*/
			status =SD_PioRead(buffer,num*gSD->mBKLength);
		}
		else
		{
			/*poll to write data to FIFO*/
			status =SD_PioWrite(buffer,num*gSD->mBKLength);
		}
		
		MSDC_ClearBits32(MSDC_INTEN, MSDC_INTEN_DATTMO|MSDC_INTEN_DATCRCERR);
		if (status)
		{
			goto done;
		}
		intsts =MSDC_PollInts(MSDC_INT_XFER_COMPL|MSDC_INT_DATTMO|MSDC_INT_DATCRCERR,100);
		if (intsts&MSDC_INT_XFER_COMPL)
		{
			status=gMSDC_Handle->error=NO_ERROR;
		}
		else if (intsts&MSDC_INT_DATCRCERR){
			status=gMSDC_Handle->error=ERR_DAT_CRCERR;
		}
		else if (intsts&MSDC_INT_DATTMO)
		{
			status=gMSDC_Handle->error=ERR_DAT_TIMEOUT;
		}
		else
        	MSDC_ERR("[SD][%s %d]SW timeout in wait PIO data done\r\n",__FUNCTION__,__LINE__);
	}
done:
	if (status)
	{
		MSDC_FatalErrorHandle();
	}
	
	/*cmd12 to stop data*/
	cmd23_sup = (gSD->mSCR.cmd_support >> 1) & 0x1;
    if (((num>1) && !cmd23_sup) || ((num>1) && cmd23_sup && status))
	    SD_SendCmd(SDC_CMD_CMD12, SDC_NO_ARG, MSDC_CMD_TIMEOUT);
	
	/* Check card status after each operation */
	MSDC_CheckCardBusy(KAL_FALSE, 10*1000);
	
	return status;
}

kal_uint32 msdc_tune_write_large_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 ultra_hs = 0;
    kal_uint32 clk_mode, wr_datcrc_ta, w_d_smpl;
    
    times_large_w++;
    
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, wr_datcrc_ta);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl);

    /* 
     * If MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz 
     * that is ultra high speed mode, tune WRDAT_CRCS_TA_CNTR first
     */
    if ((clk_mode == 1) || (clk_mode == 2) ||  (gMSDC_Handle->op_clock > MSDC_TUNE_UHS_SCLK))
        ultra_hs = 1;

    if (ultra_hs) {
        wr_datcrc_ta++;
        MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, 
            wr_datcrc_ta & (MSDC_TUNE_WCRC_TA_MAX - 1));

        if (wr_datcrc_ta >= MSDC_TUNE_WCRC_TA_MAX) {
            w_d_smpl++;
            MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl % 2);
        }
    }
    else {
        w_d_smpl++;
        wr_datcrc_ta = 0;
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl % 2);
        MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, 
            wr_datcrc_ta & (MSDC_TUNE_WCRC_TA_MAX - 1));
    }

    if (w_d_smpl >= 2) {
        ret = 1;    
    }

    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, wr_datcrc_ta);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl);
    
    MSDC_NOTICE("[SD] <TUNE_WR_LS><%d> %s=%d, %s=%d, %s=%d\r\n",
            times_large_w, "CKMOD", clk_mode, 
            "WR_DATCRC_TA", wr_datcrc_ta, "W_D_SMPL", w_d_smpl);
   
    if (ret)
        times_large_w = 0;

    return ret;
}

kal_uint32 msdc_tune_write_small_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 ultra_hs = 0;
    kal_uint32 clk_mode, wr_datcrc_ta, w_d_smpl, dat0_rd_dly, dat_wr_rxdly;
    
    times_small_w++;

    /* 
     * When re-enter the tuning flow, 
     * Clear the pad macro then tune from the beginning
     */
    if (times_small_w == 1) {
        MSDC_SET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_DATWRDLY, 0);
    }
    
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, wr_datcrc_ta);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl);
    MSDC_GET_FIELD(MSDC_DAT_RDDLY0, MSDC_DAT_RDDLY0_D0, dat0_rd_dly);
    MSDC_GET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_DATWRDLY, dat_wr_rxdly);

    /* 
     * If MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz 
     * that is ultra high speed mode, tune WRDAT_CRCS_TA_CNTR 
     * and PAT_DAT_WR_RXDLY at last
     */
    if ((clk_mode == 1) || (clk_mode == 2) || (gMSDC_Handle->op_clock > MSDC_TUNE_UHS_SCLK))
        ultra_hs = 1;

    dat_wr_rxdly++;
    MSDC_SET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_DATWRDLY, dat_wr_rxdly & 0x1F);

    if (dat_wr_rxdly >= 32) {
        w_d_smpl++;
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl % 2);
    }

    if (ultra_hs) {
        if (w_d_smpl >= 2) {
            wr_datcrc_ta++;
            MSDC_SET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, 
                wr_datcrc_ta & (MSDC_TUNE_WCRC_TA_MAX - 1));
        }

        if (wr_datcrc_ta >= MSDC_TUNE_WCRC_TA_MAX)
            ret = 1;
    }

    if (w_d_smpl >= 2) 
        ret = 1;

    MSDC_GET_FIELD(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, wr_datcrc_ta);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_WDSPL, w_d_smpl);
    MSDC_GET_FIELD(MSDC_DAT_RDDLY0, MSDC_DAT_RDDLY0_D0, dat0_rd_dly);
    MSDC_GET_FIELD(MSDC_PAD_TUNE, MSDC_PAD_TUNE_DATWRDLY, dat_wr_rxdly);
    
    MSDC_NOTICE("[SD] <TUNE_WR_SS><%d> %s=%d, %s=%d, %s=%d\r\n",
            times_small_w, "CKMOD", clk_mode, 
            "WR_DATCRC_TA", wr_datcrc_ta, "W_D_SMPL", w_d_smpl);
    MSDC_NOTICE("                        %s=%d, %s=%d\r\n",
            "DAT0_RD_DLY", dat0_rd_dly, "DAT_WR_RXDLY", dat_wr_rxdly);
            
    if (ret)
        times_small_w = 0;

    return ret;
}

kal_uint32 SD_TuneWrite(kal_uint32 address,void * txbuffer,kal_uint32 num,kal_bool isLinkListBuf)
{
    kal_uint32 result = ERR_DAT_CRCERR;
    
    do {
        /* Retry the Write with error handling */
        result = SD_ReqHandleData(address,txbuffer,num,KAL_TRUE,isLinkListBuf);

        if (/*(result == ERR_DAT_TIMEOUT) ||*/
            (result == NO_ERROR)) {
            if (times_large_w)
                fgWrTuneLargeScale = 0;

            times_small_w = 0;
            
            goto done;
        }

        /* Large scale timing tuning */
        if (fgWrTuneLargeScale) {
            if (msdc_tune_write_large_scale())
                fgWrTuneLargeScale = 0;
        } 
        /* Small scale timing tuning */
        else {
            if (msdc_tune_write_small_scale())
                goto done;
        }

    } while (1);

done:
    MSDC_CRIT("[SD] <TUNE_WRITE_DONE>");
    if (result == NO_ERROR) 
        MSDC_CRIT(" %s\r\n", "PASS");
    else if (result == ERR_DAT_CRCERR)
        MSDC_CRIT(" %s\r\n", "CRCERR");
    else if (result == ERR_DAT_TIMEOUT)
        MSDC_CRIT(" %s\r\n", "TIMEOUT");

    return result;
}


kal_uint32 msdc_tune_read_large_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 ultra_hs = 0;
    kal_uint32 clk_mode, int_dat_latch, ckgen_dly, r_d_smpl;
    
    times_large_r++;
    
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, int_dat_latch);
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl);

    /* 
     * If MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz 
     * that is ultra high speed mode, tune INT_DAT_LATCH_CK_SEL
     * and CKGEN_MSDC_DLY_SEL first
     */
    if ((clk_mode == 1) || (clk_mode == 2) || (gMSDC_Handle->op_clock > MSDC_TUNE_UHS_SCLK))
        ultra_hs = 1;

    if (ultra_hs) {
        /* Sampling edge is fixed by default setting - rising edge */
        int_dat_latch++;
        MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, 
            int_dat_latch & (MSDC_TUNE_INT_DAT_LATCH_CK_MAX - 1));

        if (int_dat_latch >= MSDC_TUNE_INT_DAT_LATCH_CK_MAX) {
            ckgen_dly++;
            MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly & 0x1F);

            if (ckgen_dly >= 32)
                ret = 1;
        }
    }
    else {
        /* 
         * In low speed mode, just tune R_D_SMPL 
         * and set other parameters back to 0
         */
        r_d_smpl++;
        int_dat_latch = 0;
        ckgen_dly = 0;
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl % 2);
        MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, 
            int_dat_latch & (MSDC_TUNE_INT_DAT_LATCH_CK_MAX - 1));
        MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly & 0x1F);
        
    }

    if (r_d_smpl >= 2)
        ret = 1;

    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, int_dat_latch);
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl);
    
    MSDC_NOTICE("[SD] <TUNE_RD_LS><%d> %s=%d, %s=%d, %s=%d, %s=%d\r\n",
            times_large_r, "CKMOD", clk_mode, 
            "INT_DAT_L", int_dat_latch, "CKGEN_DLY", ckgen_dly,
            "R_D_SMPL", r_d_smpl);
   
    if (ret)
        times_large_r = 0;

    return ret;
    
}

kal_uint32 msdc_tune_read_small_scale()
{
    kal_uint32 ret = 0;
    kal_uint32 ultra_hs = 0;
    kal_uint32 clk_mode, int_dat_latch, ckgen_dly, r_d_smpl, dat_rddly0, dat_rddly1;
    kal_uint32 dat0_rd_dly, dat1_rd_dly, dat2_rd_dly, dat3_rd_dly;
    kal_uint32 dat4_rd_dly, dat5_rd_dly, dat6_rd_dly, dat7_rd_dly;

    kal_uint32 ddr = 0, dcrc_sts;
    
    times_small_r++;
    
    MSDC_GET_FIELD(MSDC_CFG, MSDC_CFG_CKMOD, clk_mode);
    
    /* 
     * If MSDC_CFG.CLK_MODE = 1 && Bus_Speed > 100MHz 
     * that is ultra high speed mode, tune INT_DAT_LATCH_CK_SEL
     * and CKGEN_MSDC_DLY_SEL at last
     */
    if ((clk_mode == 1) || (clk_mode == 2) || (gMSDC_Handle->op_clock > MSDC_TUNE_UHS_SCLK))
        ultra_hs = 1;

    /* 
     * When re-enter the tune in Non-UHS mode, 
     * Clear the pad macro then tune from the beginning
     */
    if ((times_small_r == 1) && (ultra_hs == 0)) {
        MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, 0);
        MSDC_WriteReg32(MSDC_DAT_RDDLY0, 0);
        MSDC_WriteReg32(MSDC_DAT_RDDLY1, 0);
    }
    
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, int_dat_latch);
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl);
    dat_rddly0 = MSDC_Reg32(MSDC_DAT_RDDLY0);
    dat_rddly1 = MSDC_Reg32(MSDC_DAT_RDDLY1);
    
    /* Get data CRC status */
    MSDC_GET_FIELD(SDC_DCRC_STS, SDC_DCRC_STS_NEG | SDC_DCRC_STS_POS, dcrc_sts);

    /* Check output clock is SDR mode or DDR mode */
    ddr =  (clk_mode == 2) ? 1 : 0;
    if (!ddr) 
        dcrc_sts &= ~SDC_DCRC_STS_NEG;
    
    /* Tune PAD macro first */
    MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_DDLSEL, 1);
    
    dat0_rd_dly = (dat_rddly0 >> 24) & 0x1F;
    dat1_rd_dly = (dat_rddly0 >> 16) & 0x1F;
    dat2_rd_dly = (dat_rddly0 >>  8) & 0x1F;
    dat3_rd_dly = (dat_rddly0 >>  0) & 0x1F;
    dat4_rd_dly = (dat_rddly1 >> 24) & 0x1F;
    dat5_rd_dly = (dat_rddly1 >> 16) & 0x1F;
    dat6_rd_dly = (dat_rddly1 >>  8) & 0x1F;
    dat7_rd_dly = (dat_rddly1 >>  0) & 0x1F;

    if (ddr) {
        dat0_rd_dly = (dcrc_sts & (1 << 0) || dcrc_sts & (1 <<  8)) ? (dat0_rd_dly + 1) : dat0_rd_dly;
        dat1_rd_dly = (dcrc_sts & (1 << 1) || dcrc_sts & (1 <<  9)) ? (dat1_rd_dly + 1) : dat1_rd_dly;
        dat2_rd_dly = (dcrc_sts & (1 << 2) || dcrc_sts & (1 << 10)) ? (dat2_rd_dly + 1) : dat2_rd_dly;
        dat3_rd_dly = (dcrc_sts & (1 << 3) || dcrc_sts & (1 << 11)) ? (dat3_rd_dly + 1) : dat3_rd_dly;
        dat4_rd_dly = (dcrc_sts & (1 << 4) || dcrc_sts & (1 << 12)) ? (dat4_rd_dly + 1) : dat4_rd_dly;
        dat5_rd_dly = (dcrc_sts & (1 << 5) || dcrc_sts & (1 << 13)) ? (dat5_rd_dly + 1) : dat5_rd_dly;
        dat6_rd_dly = (dcrc_sts & (1 << 6) || dcrc_sts & (1 << 14)) ? (dat6_rd_dly + 1) : dat6_rd_dly;
        dat7_rd_dly = (dcrc_sts & (1 << 7) || dcrc_sts & (1 << 15)) ? (dat7_rd_dly + 1) : dat7_rd_dly;
    } else {
        dat0_rd_dly = (dcrc_sts & (1 << 0)) ? (dat0_rd_dly + 1) : dat0_rd_dly;
        dat1_rd_dly = (dcrc_sts & (1 << 1)) ? (dat1_rd_dly + 1) : dat1_rd_dly;
        dat2_rd_dly = (dcrc_sts & (1 << 2)) ? (dat2_rd_dly + 1) : dat2_rd_dly;
        dat3_rd_dly = (dcrc_sts & (1 << 3)) ? (dat3_rd_dly + 1) : dat3_rd_dly;
        dat4_rd_dly = (dcrc_sts & (1 << 4)) ? (dat4_rd_dly + 1) : dat4_rd_dly;
        dat5_rd_dly = (dcrc_sts & (1 << 5)) ? (dat5_rd_dly + 1) : dat5_rd_dly;
        dat6_rd_dly = (dcrc_sts & (1 << 6)) ? (dat6_rd_dly + 1) : dat6_rd_dly;
        dat7_rd_dly = (dcrc_sts & (1 << 7)) ? (dat7_rd_dly + 1) : dat7_rd_dly;
    }

    dat_rddly0 = ((dat0_rd_dly & 0x1F) << 24) | ((dat1_rd_dly & 0x1F) << 16) |
                 ((dat2_rd_dly & 0x1F) << 8)  | ((dat3_rd_dly & 0x1F) << 0);    
    dat_rddly1 = ((dat4_rd_dly & 0x1F) << 24) | ((dat5_rd_dly & 0x1F) << 16) |
                 ((dat6_rd_dly & 0x1F) << 8)  | ((dat7_rd_dly & 0x1F) << 0);

    MSDC_WriteReg32(MSDC_DAT_RDDLY0, dat_rddly0);
    MSDC_WriteReg32(MSDC_DAT_RDDLY1, dat_rddly1);   
    
    /* Then R_D_SMPL */
    if( (dat0_rd_dly >= 32) || (dat1_rd_dly >= 32) || (dat2_rd_dly >= 32) || (dat3_rd_dly >= 32)||
        (dat4_rd_dly >= 32) || (dat5_rd_dly >= 32) || (dat6_rd_dly >= 32) || (dat7_rd_dly >= 32)){

        /* 
         * On ultra-hs mode, do NOT tune sampling edge,
         * because of the 'internal boundary' issue of the current IP
         */
        if (!ultra_hs) {
            r_d_smpl++;
            MSDC_SET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl % 2);
        }

        /* Re-tune the data pad macro */
        MSDC_WriteReg32(MSDC_DAT_RDDLY0, 0);
        MSDC_WriteReg32(MSDC_DAT_RDDLY1, 0);

        /* Then CKGEN_MSDC_DLY_SEL if it is SDR104 mode */
        if (ultra_hs) {
            ckgen_dly++;
            MSDC_SET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly & 0x1F);

            if (ckgen_dly >= 32)
                ret = 1;
        }
        else {
            if (r_d_smpl >= 2)
                ret = 1;
        }
        
    }

    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, int_dat_latch);
    MSDC_GET_FIELD(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, ckgen_dly);
    MSDC_GET_FIELD(MSDC_IOCON, MSDC_IOCON_RDSPL, r_d_smpl);
    dat_rddly0 = MSDC_Reg32(MSDC_DAT_RDDLY0);
    dat_rddly1 = MSDC_Reg32(MSDC_DAT_RDDLY1);
    
    MSDC_NOTICE("[SD] <TUNE_RD_SS><%d> %s=%d, %s=%d, %s=%d, %s=%d\r\n",
            times_small_r, "CKMOD", clk_mode, 
            "INT_DAT_L", int_dat_latch, "CKGEN_DLY", ckgen_dly,
            "R_D_SMPL", r_d_smpl);
    MSDC_NOTICE("                        %s=0x%x, %s=0x%x\r\n",
            "DAT_RDDLY0", dat_rddly0, "DAT_RDDLY1", dat_rddly1);
            
    if (ret)
        times_small_r = 0;

    return ret;
    
}

SDC_CMD_STATUS SD_TuneRead(kal_uint32 data_adrs,void *rxbuffer,kal_uint32 num,kal_bool isLinkListBuf)
{
    kal_uint32 result = ERR_DAT_CRCERR;
    
    do {
        /* Retry the Read with error handling */
        result = SD_ReqHandleData(data_adrs,rxbuffer,num,KAL_FALSE,isLinkListBuf);

        if ((result == ERR_DAT_TIMEOUT) ||
            (result == NO_ERROR)) {
            if (result == NO_ERROR) {
                if (times_large_r)
                    fgReadTuneLargeScale = 0;

                times_small_r = 0;
            }
            
            goto done;
        }

        /* Large scale timing tuning */
        if (fgReadTuneLargeScale) {
            if (msdc_tune_read_large_scale())
                fgReadTuneLargeScale = 0;
        } 
        /* Small scale timing tuning */
        else {
            if (msdc_tune_read_small_scale())
                goto done;
        }

    } while (1);

done:
    MSDC_CRIT("[SD] <TUNE_READ_DONE>");
    if (result == NO_ERROR) 
        MSDC_CRIT(" %s\r\n", "PASS");
    else if (result == ERR_DAT_CRCERR)
        MSDC_CRIT(" %s\r\n", "CRCERR");
    else if (result == ERR_DAT_TIMEOUT)
        MSDC_CRIT(" %s\r\n", "TIMEOUT");

    return result;
}

void msdc_tune_init(void) 
{
    /* Initialize the tuning releated parameters and registers */
    fgCMDTuneLargeScale = 1;
    times_large = 0;
    times_small = 0;
    MSDC_SET_FIELD_NPW(MSDC_PATCH_BIT1, MSDC_CMD_RSP_TA_CNTR, 0);
    MSDC_SET_FIELD_NPW(MSDC_IOCON, MSDC_IOCON_RSPL, 0);
    MSDC_SET_FIELD_NPW(MSDC_PAD_TUNE, MSDC_PAD_TUNE_CMDRDLY, 0);
    
    fgWrTuneLargeScale = 1;
    times_large_w = 0;
    times_small_w = 0;
    MSDC_SET_FIELD_NPW(MSDC_PATCH_BIT1, MSDC_WRDAT_CRCS_TA_CNTR, 0);
    MSDC_SET_FIELD_NPW(MSDC_IOCON, MSDC_IOCON_WDSPL, 0);
    MSDC_SET_FIELD_NPW(MSDC_PAD_TUNE, MSDC_PAD_TUNE_DATWRDLY, 0);
    
    fgReadTuneLargeScale = 1;
    times_large_r = 0;
    times_small_r = 0;
    MSDC_WriteReg32_NPW(MSDC_DAT_RDDLY0, 0);
    MSDC_WriteReg32_NPW(MSDC_DAT_RDDLY1, 0);
    MSDC_SET_FIELD_NPW(MSDC_PATCH_BIT0, MSDC_INT_DAT_LATCH_CK_SEL, 0);
    MSDC_SET_FIELD_NPW(MSDC_PATCH_BIT0, MSDC_CKGEN_MSDC_DLY_SEL, 0);
    MSDC_SET_FIELD_NPW(MSDC_IOCON, MSDC_IOCON_RDSPL, 0);    
}

SDC_CMD_STATUS SD_HandleWriteTMO(kal_uint32 address,void *txbuffer,kal_uint32 num,kal_bool isLinkListBuf)
{
	kal_uint32 cur_wrta,orig_wr_crcta;
	kal_uint32 status,i,ret;
	
	ret=SD_GetStatus(gSD->mRCA,&status);
	if (ret){
		return ERR_DAT_TIMEOUT;
	}
	if (status&(R1_OUT_OF_RANGE_31|R1_ADDRESS_ERROR_30)){
		return ERR_DAT_TIMEOUT;
	}
	orig_wr_crcta=(MSDC_Reg32(MSDC_PATCH_BIT1)&MSDC_PATCH_BIT1_WRDAT_CRCS)>>(uffs(MSDC_PATCH_BIT1_WRDAT_CRCS)-1);
	/*Ncrc may cause Write data timeout*/
	for (i=0;i<8;i++){
		cur_wrta=(orig_wr_crcta+i)%8;
		MSDC_SetData32(MSDC_PATCH_BIT1,MSDC_PATCH_BIT1_WRDAT_CRCS,cur_wrta<<(uffs(MSDC_PATCH_BIT1_WRDAT_CRCS)-1));
		ret=SD_ReqHandleData(address,txbuffer,num,KAL_TRUE,isLinkListBuf);
		if (ret==0)
			return 0;
		if (ret==ERR_DAT_CRCERR||ret==ERR_CMD_RSPCRCERR)
		{
			return ret;
		}
	}
	if (ret)
	{
		return ret;
	}
	ret=SD_TuneWrite( address,txbuffer,num,isLinkListBuf);
	return ret;
}
/*************************************************************************
* FUNCTION
*  SD_Reset
*
* DESCRIPTION
*	reset all cards to idle state
*
* PARAMETERS
*	1. cmd: the content of SDC_CMD register
*	2. arg: the argument(if the command need no argument, fill it with 0)
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Reset(void)
{
	SDC_CMD_STATUS status;
	status=SD_SendCmd(SDC_CMD_CMD0,SDC_NO_ARG,MSDC_CMD_TIMEOUT);
	gSD->mState=IDLE_STA;
	return status;
    
}

/*************************************************************************
* FUNCTION
*  SD_Cmd55
*
* DESCRIPTION
*	APP_CMD: inidicate to the card that the next command is an application specified command
*			rather than a standard command
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Cmd55(kal_uint16 rca)
{
	SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD55, ((kal_uint32)rca << 16),MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;
        
    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //check APP_CMD bit in status register
    status=MSDC_Reg32(SDC_RESP0);

    if (!(status & R1_APP_CMD_5))
        return ERR_APPCMD_FAILED;

    return NO_ERROR;
   
}
/*************************************************************************
* FUNCTION
*  SD_Cmd8
*
* DESCRIPTION
*	1. Sends SD Memory Card interface conditions for support larger than 2G cards
*	2. check if the card is compliant to SD2.0 or higher
*	3. only performed while at IDLE state.
*
* PARAMETERS
*
* RETURNS
*
* GLOBALS AFFECTED
*	gSD->mIsCMD8
*
*************************************************************************/
void SD_Cmd8(void)
{
    kal_uint32 resp;
    kal_uint32 retry = 4;
    MSDC_DEBUG("[SD][%s %d]Cmd8 arg=%x\r\n",__FUNCTION__,__LINE__,SDC_CMD8_ARG);

cmd8_retry:	
    if (SD_SendCmd(SDC_CMD_CMD8, SDC_CMD8_ARG,MSDC_CMD_TIMEOUT) != NO_ERROR)
    {
        MSDC_ERR("[SD][%s %d]SDC_Cmd8 fail\r\n",__FUNCTION__,__LINE__);
        SD_Reset();
        gSD->mCMD8Resp = SD_CMD8_RESP_NORESP;
        return;
    }

    resp= MSDC_Reg32(SDC_RESP0);
    MSDC_DEBUG("[SD][%s %d]Cmd8 resp=%x\r\n",__FUNCTION__,__LINE__,resp);

    if (resp == SDC_CMD8_ARG)
        gSD->mCMD8Resp = SD_CMD8_RESP_VALID;
    else {
        MSDC_ERR("[SD]CMD8 check pattern error, %X(%X)\r\n",SDC_CMD8_ARG,resp);
        
        if (retry--)
            goto cmd8_retry;

        gSD->mCMD8Resp = SD_CMD8_RESP_INVALID;
    }

    return;
}

/*************************************************************************
* FUNCTION
*  SD_Cmd1_MMC
*
* DESCRIPTION
*	 asks all cards in idle state to send their OCR in the response on the CMD line
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for MMC
*
*************************************************************************/
extern kal_bool FTL_isPollingMode();

SDC_CMD_STATUS SD_Cmd1_MMC(void)
{
    SDC_CMD_STATUS status;
    kal_uint32 _ocr, ocr_i,  t2;

    #if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
        return ERR_CMD8_INVALID;

    ocr_i = (SDC_OCR_DEFAULT | MMC_HIGH_DESITY_CHECK_BIT);
    #else
    ocr_i = SDC_OCR_DEFAULT;
    #endif

    if (gMSDC_Handle->is_init_timeout == KAL_TRUE)
        return ERR_R3_OCR_BUSY;

    t2 = drv_get_current_time();

    do
    {
        /*send cmd1*/
        if ((status=SD_SendCmd(SDC_CMD_CMD1,ocr_i,MSDC_CMD_TIMEOUT))  != NO_ERROR)
            return status;

        _ocr=MSDC_Reg32(SDC_RESP0);
        MSDC_NOTICE("[SD]OCR = %x\r\n", _ocr);

        if ((_ocr & SDC_OCR_DEFAULT) == 0)
            return ERR_OCR_NOT_SUPPORT;

        if (!gMSDC_Handle->mIsPresent)
            return MSDC_CARD_NOT_PRESENT;

        if (!(_ocr & SDC_OCR_BUSY))
        {
            if (drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
            {
                gMSDC_Handle->is_init_timeout = KAL_TRUE;
                break;
            }

            msdc_sleep(2);
        }
        else {
            MSDC_CRIT("[SD]OCR = %x\r\n", _ocr);
            break;
        }
    }
    while (1);

    if (gMSDC_Handle->is_init_timeout)
        return ERR_CMD_TIMEOUT;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if ((_ocr & MMC_HIGH_DESITY_CHECK_MSK) == MMC_HIGH_DESITY_CHECK_BIT)
    {
        gSD->flags |= SD_FLAG_HCS_SUPPORT;
        gMSDC_Handle->mMSDC_type = MMC42_CARD;
        gSD->mIsBlkAddr = 1;
    }
    else
#endif
        gMSDC_Handle->mMSDC_type = MMC_CARD;

    gSD->mInactive = KAL_FALSE;
    gSD->mSDC_ocr = _ocr;
    gSD->mState = READY_STA;

    return NO_ERROR;
}
SDC_CMD_STATUS SD_Cmd11(void)
{
    SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD11, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
    {
        return status;
    }
    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
   
}
kal_int32 SD_SwitchVolt18()
{
    kal_uint32 status,t2;
    status=SD_Cmd11();
    if (status !=NO_ERROR)
        return status;
    /*make sure SDC is not BUSY*/
    if (MSDC_TIMEOUT_WAIT((!SD_IS_SDC_BUSY())&&MSDC_Check_Card_Present(),MSDC_CMD_TIMEOUT))
    {
	    MSDC_ERR("[SD][%s %d]wait SDC busy timeout\r\n",__FUNCTION__,__LINE__);
        return ERR_STATUS;
    }
    /*check data[3:0] and cmd is lower by card*/
    if(MSDC_Reg32(MSDC_PS)&((1<<24)|(0xf<<16)))
        return CHECK_DATA_CMD_LOW_FAIL;
    /*pull up disabled in CMD and DAT[3:0]*/
    MSDC_ConfigPin(MSDC_PIN_PULL_NONE);
    /*switch signal voltage to 1.8v*/
    gMSDC_Handle->signal_volt=1800;
    MSDC_SetSignalPower(1,gMSDC_Handle->signal_volt);
    /*wait 5ms*/
    msdc_sleep(2);
    /*PULL UP enable in CMD and DAT[3:0]*/
    MSDC_ConfigPin(MSDC_PIN_PULL_UP);
    msdc_sleep(1);
    /*start to detect volt change */
    MSDC_SetBits32(MSDC_CFG,MSDC_CFG_BV18SDT);
    msdc_sleep(20);
    t2=drv_get_current_time();
    do{
        if(((status=MSDC_Reg32(MSDC_CFG))& MSDC_CFG_BV18SDT)==0);
        {
            if (status&MSDC_CFG_BV18PSS)
            {
                //pass to switch volt to 1.8v
                return NO_ERROR;
            }
            else
            {
                //fail to switch volt to 1.8v
	            MSDC_ERR("[SD][%s %d]1.8v fail ,MSDC_CFG %x\r\n",__FUNCTION__,__LINE__,status);
                break;
            }
        }
        if (drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
        {
            //detect volt change timeout
	        MSDC_ERR("[SD][%s %d]detect volt change timeout\r\n",__FUNCTION__,__LINE__);
            break;
        }
    }while(1);

    //come to here ,mean timeout or switch 1.8v fail
    
    return ERR_STATUS;
}
/*************************************************************************
* FUNCTION
*  SD_Acmd41_SD
*
* DESCRIPTION
*	asks all cards in idle state to send their OCR in the response on the CMD line
*	OCR: Operation Condition Register
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	only works for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_Acmd41_SD(void)
{
	SDC_CMD_STATUS		status;
    kal_uint32			_ocr = 0, ocr_i = 0,  t2;
    
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->mCMD8Resp == SD_CMD8_RESP_NORESP)
        ocr_i = SDC_OCR_DEFAULT;
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_VALID) {
        #if defined(MSDC_CONFIG_SD30_SUPPORT)
        if (TEMP_SINGLE_LINE == gMSDC_Handle->trySingleLine)
            ocr_i = (SDC_OCR_DEFAULT | SD_ACMD41_HCS);
        else
            ocr_i = (SDC_OCR_DEFAULT | SD_ACMD41_HCS |SD_ACMD41_S18R | SD_ACMD41_XPC);
           
        #else
        ocr_i = (SDC_OCR_DEFAULT | SD_ACMD41_HCS);
        #endif
    }
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_INVALID)
        return ERR_CMD8_INVALID;

#else
    ocr_i = SDC_OCR_DEFAULT;
#endif
    MSDC_CRIT("[SD][%s %d]Host OCR = %x\r\n",__FUNCTION__,__LINE__,ocr_i);
 retry:
    gMSDC_Handle->is_init_timeout = KAL_FALSE;
    t2 = drv_get_current_time();

    do
    {
        /*send ACMD41*/
        status = SD_Cmd55(SDC_RCA_DEFAULT);

        if (status != NO_ERROR)
        {
            return status;
        }   

        status=SD_SendCmd(SDC_CMD_ACMD41, ocr_i, MSDC_CMD_TIMEOUT);
        if (status != NO_ERROR)
        {
            return status;
        }
        
        /*check response*/
        _ocr = MSDC_Reg32(SDC_RESP0);
        MSDC_NOTICE("[SD]ACMD41 resp = %x\r\n", _ocr);

        if ((_ocr & SDC_OCR_DEFAULT) == 0)
            return ERR_OCR_NOT_SUPPORT;

        if (!gMSDC_Handle->mIsPresent)
            return ERR_CARD_NOT_PRESENT;

        if (!(_ocr & SDC_OCR_BUSY))
        {
            /*if return busy ,we check timeout or not*/
            if (drv_get_duration_ms(t2) > MSDC_TIMEOUT_PERIOD_INI)
            {
                gMSDC_Handle->is_init_timeout = KAL_TRUE;
                MSDC_ERR("[SD]ACMD41 Polling BUSY timeout!\r\n");
                break;
            }

            msdc_sleep(5);
        }
        else
        {
            /*not busy */
            MSDC_CRIT("[SD]OCR = %x\r\n", _ocr);
            break;
        }
    }
    while (1);

    if (gMSDC_Handle->is_init_timeout)
        return ERR_R3_OCR_BUSY;

    gSD->mInactive = KAL_FALSE;
    gSD->mSDC_ocr = _ocr;
#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)
    gSD->flags |= SD_FLAG_SD_TYPE_CARD;

    if (_ocr & SD_ACMD41_HCS)
    {
        #if defined(MSDC_CONFIG_SD30_SUPPORT)
        if (_ocr & SD_ACMD41_S18R )
        {
            status=SD_SwitchVolt18();
            if (status != NO_ERROR)
            {
                return status;  //need delete
                //fail to switch to 1.8v ,so set signal voltage back to 3.3.v
                gMSDC_Handle->signal_volt=3300;
                MSDC_SetSignalPower(1,gMSDC_Handle->signal_volt);
                power_cycle(1);
                SD_Reset();
                SD_Cmd8();
                ocr_i = (SDC_OCR_DEFAULT | SD_ACMD41_HCS);
                goto retry;
            }

            gSD->flags|=SD_FLAG_UHS_SUPPORT;
            gMSDC_Handle->mMSDC_type=SD30_CARD;
 	        MSDC_CRIT("[SD][%s %d]SD3.0 UHS Card\r\n",__FUNCTION__,__LINE__);
        }
        else
        #endif
        {
            gSD->flags |= SD_FLAG_HCS_SUPPORT;
            gMSDC_Handle->mMSDC_type = SD20_HCS_CARD;
 	        MSDC_CRIT("[SD][%s %d]SD2.0 High Capacity Card\r\n",__FUNCTION__,__LINE__);
            
        }
      
        
    }
    else if (gSD->mCMD8Resp == SD_CMD8_RESP_VALID)
        gMSDC_Handle->mMSDC_type = SD20_LCS_CARD;
    else
#endif
        gMSDC_Handle->mMSDC_type = SD_CARD;

    gSD->mState = READY_STA;

    return NO_ERROR;
    
}

/*************************************************************************
* FUNCTION
*  SD_GetCID
*
* DESCRIPTION
*	Read Card Identification.
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*
*
*************************************************************************/

// Get CID(CMD2)
SDC_CMD_STATUS SD_GetCID(kal_uint32 *Cid)
{
     int i;
    SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD2, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
    {
        	return status;
    }
     
    //read R2
    for (i = 0; i < 4; i++)
    {
        Cid[i]=MSDC_Reg32((SDC_RESP0 + i * sizeof(kal_uint32)));
    }
    
    SD_AnalysisCID(Cid);
    gSD->mState = IDENT_STA;

    return NO_ERROR;
    
}

/*************************************************************************
* FUNCTION
*  SD_ValidateRCA
*
* DESCRIPTION
*	assing or read RCA
*
* PARAMETERS
*	pRca: used for input or output RCA
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD
*
* NOTE
*	RCA is assinged to MMC card fixed to SDC_RCA_MMC(1)
*
*************************************************************************/

// assign or read RCA
SDC_CMD_STATUS SD_ValidateRCA(kal_uint16* pRca)
{
    SDC_CMD_STATUS status;
    kal_uint32 resp;
    kal_uint8  state;
    kal_uint32 retry;

#if defined(SD_MMC_HIGH_DENSITY_SUPPORT)

    if (gSD->flags & SD_FLAG_SD_TYPE_CARD )
#else
    if (gMSDC_Handle->mMSDC_type == SD_CARD)
#endif
    {
        //read RCA form card
        retry=10;
	/*if card return RCA=0  we will retry,*/
        while(retry--)
        {
     		MSDC_DEBUG("[SD][%s %d]send cmd3\r\n",__FUNCTION__,__LINE__);
	        if ((status = SD_SendCmd(SDC_CMD_CMD3, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
	            return status;

	        //read R6
	        resp=MSDC_Reg32(SDC_RESP0);
    		MSDC_DEBUG("[SD][%s %d]cmd3 reps=%x\r\n",__FUNCTION__,__LINE__,resp);	
#ifdef MSDC_TRACE_LEVEL1
	        drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
    		if ((resp>>16)!=0)
    		{
    	       	 *pRca = resp >>  16;
    	       	 gSD->mRCA = *pRca;
    			 break;
    		}
    		MSDC_DEBUG("[SD][%s %d]gSD->mRCA=%x\r\n",__FUNCTION__,__LINE__,gSD->mRCA);	
        }
	 if (retry==0)
	 {
	 	/*always return RCA=0*/
	 	return ERR_RCA_FAIL;
	 }

    }
    else
    {
        //assign RCA to card
        if ((status = SD_SendCmd(SDC_CMD_CMD3_MMC, ((kal_uint32)SDC_RCA_MMC << 16),MSDC_CMD_TIMEOUT)) != NO_ERROR)
            return status;

        //read R1
        resp=MSDC_Reg32(SDC_RESP0);
#ifdef MSDC_TRACE_LEVEL1
        drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
        SD_GetStatus(SDC_RCA_MMC, &resp);
        state = 0;
        GetBitFieldN((kal_uint8*)&state, (kal_uint8*)&resp, 9, 4);

        if (STBY_STA != state)
            return ERR_RCA_FAIL;

        *pRca = gSD->mRCA = SDC_RCA_MMC;
    }

    gSD->mState = STBY_STA;
    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetDSR
*
* DESCRIPTION
*	set default value to the DSR
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	SDC_DSR_DEFAULT(0x404)
*
*************************************************************************/
SDC_CMD_STATUS SD_SetDSR(void)
{
    return SD_SendCmd(SDC_CMD_CMD4, (kal_uint32)SDC_DSR_DEFAULT << 16,MSDC_CMD_TIMEOUT);
}

/*************************************************************************
* FUNCTION
*  SD_SelectCard
*
* DESCRIPTION
*	select/deselect card
*
* PARAMETERS
*	rca: relative card address
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SelectCard(kal_uint16 rca)
{
    SDC_CMD_STATUS status;
    MSDC_DEBUG("[SD][%s %d]send cmd7\r\n",__FUNCTION__,__LINE__);

    if ((status = SD_SendCmd(SDC_CMD_CMD7, ((kal_uint32)rca << 16),MSDC_CMD_TIMEOUT)) != NO_ERROR)
    {
        return status;
    }
	
    //read R1b
    if ((status = SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_GetCSD
*
* DESCRIPTION
*	Get CSD from addressed card
*
* PARAMETERS
*	rca: relative card address
*	Csd: used for containing read CSD
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetCSD(kal_uint16 rca, kal_uint32 Csd[4])
{
    SDC_CMD_STATUS status;
    kal_uint32 i;
    MSDC_DEBUG("[SD][%s %d]send cmd9\r\n",__FUNCTION__,__LINE__);

    if ((status = SD_SendCmd(SDC_CMD_CMD9, ((kal_uint32)rca << 16),MSDC_CMD_TIMEOUT)) != NO_ERROR)
    {
        return status;
    }
	

    // read R2
    for (i = 0; i < 4; i++)
    {
        Csd[i]=MSDC_Reg32((volatile kal_uint32 *)(SDC_RESP0 + i * 4));
	    #ifdef MSDC_DEBUG_PRINT
	    MSDC_DEBUG("%x ",Csd[i]);
	    #endif
    }
	#ifdef MSDC_DEBUG_PRINT
	MSDC_DEBUG("\r\n ");
	#endif
    // analysis CSD...
    SD_AnalysisCSD(Csd);

    return NO_ERROR;
}

// addressed send CID
SDC_CMD_STATUS SD_GetAddressedCID(kal_uint16 rca, kal_uint32 Cid[4])
{
     SDC_CMD_STATUS status;
    kal_uint32 i;

    if ((status = SD_SendCmd(SDC_CMD_CMD10, (kal_uint32)rca << 16,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    // read R2
    for (i = 0; i < 4; i++)
    {
#ifndef DRV_LSD
       Cid[i]=MSDC_Reg32((volatile kal_uint32 *)(SDC_RESP0 + i * 4));
#else
       Cid[i]=MSDC_Reg32(SDC_RESP0 + i);
#endif
    }

    return NO_ERROR;
}


/*************************************************************************
* FUNCTION
*  SD_StopTrans
*
* DESCRIPTION
*	Stop Muli-Block operation
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	definition of SD_STOP_SLOW is used for some erroneous card
*************************************************************************/
SDC_CMD_STATUS SD_StopTrans(void)
{
	SDC_CMD_STATUS status;
	#define CMD12_TIMEOUT_MS	1000		
	status = SD_SendCmd(SDC_CMD_CMD12,SDC_NO_ARG,MSDC_CMD_TIMEOUT);
	MSDC_CLR_FIFO();
	return status;
    
}

/*************************************************************************
* FUNCTION
*  SD_GetStatus
*
* DESCRIPTION
*	addressed send status
*
* PARAMETERS
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_GetStatus(kal_uint16 rca, kal_uint32* resp)
{
    SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD13, ((kal_uint32)rca << 16),MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    *resp=MSDC_Reg32(SDC_RESP0);
    
    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*  SD_SetBlength
*
* DESCRIPTION
*	set block length
*
* PARAMETERS
*	BKLength: block length u want to set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD->mBKLength
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength)
{
    SDC_CMD_STATUS status;
    
    // maximal value of block length is 2048
    if (BKLength > SDC_MAX_BKLENGTH)
        return ERR_INVALID_BKLENGTH;

    if (!gSD->mCSD.r_blk_part && BKLength < gSD->mCSD.max_r_blk_len )
        return ERR_INVALID_BKLENGTH;
    if ((status = SD_SendCmd(SDC_CMD_CMD16, BKLength,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    status = SD_CheckStatus();
    // 2. configure the controller
    gSD->mBKLength = BKLength;
   // BitFieldWrite32((kal_uint32*)SDC_CMD, BKLength, SDC_CMD_BLKLEN);
    return status;
}


/*************************************************************************
* FUNCTION
*  SD_ReadSingleBlock
*
* DESCRIPTION
*	1. read a single block form data_adrs of card to the rxbuffer
*	2. the block length is set by set block length
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	the size of rxbuffer should be 4*n (n : integer)
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer) // slim
{
    return SD_ReadMultiBlock(data_adrs, rxbuffer, 1); // slim
}
#else
SDC_CMD_STATUS SD_ReadSingleBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    return SD_ReadMultiBlock(data_adrs, rxbuffer, 1);
}
#endif
/*************************************************************************
* FUNCTION
*  SD_ReadMultiBlock
*
* DESCRIPTION
*	read num of blocks into rxbuffer
*
* PARAMETERS
*	data_adrs: starting address to read
*	rxbuffer: as name
*	num: number of blocks to read
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
SDC_CMD_STATUS 
SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num_blk) // slim
{
    

}
#else
SDC_CMD_STATUS SD_ReadMultiBlock(kal_uint32 data_adrs, kal_uint32* rxbuffer, kal_uint32 num_blk)
{
   kal_uint32 status;

   status = SD_ReqHandleData(data_adrs, rxbuffer,num_blk, KAL_FALSE,KAL_FALSE);
   if (status==ERR_DAT_CRCERR)
   {
 	    status=SD_TuneRead(data_adrs,rxbuffer,num_blk,KAL_FALSE);
   }
   return status;
}
#endif


#if defined(MT6255)
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_DummySingleWrite(kal_uint32 address, kal_uint32 *buf)
SDC_CMD_STATUS SD_DummySingleWrite(kal_uint32 address, kal_uint32 *buf)
{
    
}
#endif

/*************************************************************************
* FUNCTION
*  SD_WriteSingleBlock
*
* DESCRIPTION
*	write a single block
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
#ifdef DRV_MSDC_SLIM
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer) // slim
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
    return SD_WriteMultiBlock(address, txbuffer, 1); // slim
}
#else
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
SDC_CMD_STATUS SD_WriteSingleBlock(kal_uint32 address, kal_uint32* txbuffer)
{
    return SD_WriteMultiBlock(address, txbuffer, 1);
}
#endif

void SD_Sleep4Wait(kal_int32 sleep_tick)
{
   
}
/*************************************************************************
* FUNCTION
*	SD_WriteMultiBlock
*
* DESCRIPTION
*	write num blocks starting at address
*
* PARAMETERS
*	address: starting address to write
*	txbuffer: as name
*	num: number of blocks to write
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	block length is set by Set_Block_Length
*
*************************************************************************/
//#ifndef DRV_MSDC_SLIM
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num)
SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num_blk)
{
    SDC_CMD_STATUS status;
    
    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;
    if ((status=SD_ReqHandleData(address, txbuffer, num_blk, KAL_TRUE,KAL_FALSE))!=NO_ERROR)
    {        
		if (status ==ERR_DAT_CRCERR)
		{
			status=SD_TuneWrite(address,txbuffer,num_blk,KAL_FALSE);
		}
		else if (status == ERR_DAT_TIMEOUT)
		{
			status=SD_HandleWriteTMO(address,txbuffer,num_blk,KAL_FALSE);
		}
    }
    
        return status;
}

SDC_CMD_STATUS SD_GpdWriteMultiBlock(kal_uint32 address ,kal_uint32 num_blk,void *gpd_data)
{
    SDC_CMD_STATUS status;

    gMSDC_Handle->f_tuning = 0;
    
    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;
    if ((status=SD_ReqHandleData(address, gpd_data, num_blk, KAL_TRUE,KAL_TRUE))!=NO_ERROR)
    {
        gMSDC_Handle->f_tuning = 1;
        
		if (status ==ERR_DAT_CRCERR)
		{
			status=SD_TuneWrite(address,gpd_data,num_blk,KAL_TRUE);
		}
		else if (status == ERR_DAT_TIMEOUT)
		{
			status=SD_HandleWriteTMO(address,gpd_data,num_blk,KAL_TRUE);
		}
    }    
    return status;
}

SDC_CMD_STATUS SD_GpdReadMultiBlock(kal_uint32 address ,kal_uint32 num_blk,void *gpd_data )
{
    kal_uint32 status;
    
    gMSDC_Handle->f_tuning = 0;
    status = SD_ReqHandleData(address, gpd_data,num_blk, KAL_FALSE,KAL_TRUE);
    
    if (status==ERR_DAT_CRCERR)
    {
        gMSDC_Handle->f_tuning = 1;
        status=SD_TuneRead(address,gpd_data,num_blk,KAL_TRUE);
    }
    return status;
}


//#else
//__attribute__ ((section ("EXT_BOOTLOADER_CODE"))) SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num) // slim
//SDC_CMD_STATUS SD_WriteMultiBlock(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 num) // slim
//{
    

//}
//#endif


/*************************************************************************
* FUNCTION
*	SD_SetBusWidth
*
* DESCRIPTION
*	ACMD6: set the data width 00 for 1 bit, 10 for 4 bits
*
* PARAMETERS
*	width: indicate the bus width
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Not every card support 4-bits bus
*	only for SD
*
*************************************************************************/
SDC_CMD_STATUS SD_SetBusWidth(SD_BITWIDTH width)
{
    SDC_CMD_STATUS status;
    MSDC_DEBUG("[SD][%s %d]send ACMD6 ,change bus width to %d\r\n",__FUNCTION__,__LINE__,width);

    // check if card support 4 bits bus
    if ((width == BIT_4W) && !(gSD->mSCR.bus_width & 0x04))
        return ERR_NOT_SUPPORT_4BITS;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send cmd6
    if ((status = SD_SendCmd(SDC_CMD_ACMD6, width,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

   
        // set the controler  bus width
	MSDC_SetBusWidth(width);
    gSD->bus_width = width;
    return NO_ERROR;
}

/*************************************************************************
* FUNCTION
*	SD_ReadSCR
*
* DESCRIPTION
*	ACMD51: read the SD Configuration Register(8bytes block read)
*
* PARAMETERS
*	scr: used for store SCR
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Make sure the size of SCR is 8 bytes
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSCR(kal_uint32* scr)
{
    SDC_CMD_STATUS status;
    kal_uint32 blklen;

    ASSERT((kal_uint32)scr % 4  == 0);

    MSDC_DEBUG("[SD][%s %d]send cmd55\r\n",__FUNCTION__,__LINE__);

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;
        
    // set block number 
    blklen=gSD->mBKLength;
    gSD->mBKLength = 8;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    MSDC_DEBUG("[SD][%s %d]send acmd51\r\n",__FUNCTION__,__LINE__);

    // set to pio mode and clear fifo
    BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
    gMSDC_Handle->dma_xfer=0;
    MSDC_CLR_FIFO();
    
    // send command
    if ((status = SD_SendCmd(SDC_CMD_ACMD51, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    // read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read data(8bytes)
    status=SD_WaitDatRdyOrTo(scr,8,KAL_FALSE);
    if (status !=NO_ERROR) 
        return status;
    MSDC_DEBUG("[SD][%s %d]scr=%x %x\r\n",__FUNCTION__,__LINE__,*scr,*(scr+1));	
	
    SD_AnalysisSCR(scr);
    MSDC_CLR_FIFO();
    	
    gSD->mBKLength = blklen;

    return NO_ERROR;

}

static kal_uint32 unstuff_sd_status(kal_uint32 *raw_sd_status, kal_uint32 start, kal_uint32 size)
{
    kal_uint32 __mask = (1 << (size)) - 1;
    int __off = 63 - ((start) / 8);
    int __shft;
    kal_uint8 *raw = (kal_uint8 *)raw_sd_status;
    kal_uint32 __res = 0;

    if ((start & 7) + 1 >= size)
    {
        __shft = ((start & 7) + 1) - size;
        __res = raw[__off] >> __shft;
    }
    else if (size <= 32)
    {
        size -= ((start & 7) + 1);
        __shft = size;
        __res = raw[__off] << __shft;
        while (size)
        {
            __off++;
            if (size >= 8)
            {
                size -= 8;
                __res |= raw[__off] << size;
            }
            else
            {
                __mask = (1 << (size)) - 1;
                __res |= (raw[__off] >> (8 - size)) & __mask;
                size = 0;
            }
        }
    }
    return __res & __mask;
}
#define UNSTUFF_SD_STATUS(r,s,sz)    unstuff_sd_status(r,s,sz)

/*************************************************************************
* FUNCTION
*	SD_ReadSDStatus
*
* DESCRIPTION
*	ACMD13: read the SD Status Register(64bytes block read)
*
* PARAMETERS
*	sd_status: used for store SD Status
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	Make sure the size of SD Status is 64 bytes
*
*************************************************************************/
SDC_CMD_STATUS SD_ReadSDStatus(kal_uint32* sd_status)
{
    SDC_CMD_STATUS status;
    kal_uint32 blklen;

    ASSERT((kal_uint32)sd_status % 4  == 0);

    MSDC_DEBUG("[SD][%s %d]send cmd55\r\n",__FUNCTION__,__LINE__);

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;
        
    // set block number 
    blklen=gSD->mBKLength;
    gSD->mBKLength = 64;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    MSDC_DEBUG("[SD][%s %d]send acmd13\r\n",__FUNCTION__,__LINE__);

    // set to pio mode and clear fifo
    BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
    gMSDC_Handle->dma_xfer=0;
    
    // send command
    if ((status = SD_SendCmd(SDC_CMD_ACMD13, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    // read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read data(8bytes)
    status=SD_WaitDatRdyOrTo(sd_status,64,KAL_FALSE);
    gSD->mBKLength = blklen;

    if (status !=NO_ERROR) 
        return status;
    MSDC_DEBUG("[SD][%s %d]sd_status=%x %x\r\n",__FUNCTION__,__LINE__,*sd_status,*(sd_status+1));	
	
    gSD->mSDSts.dat_bus_width = UNSTUFF_SD_STATUS(sd_status, 511, 2);
    gSD->mSDSts.secured_mode = UNSTUFF_SD_STATUS(sd_status, 509, 1);
    gSD->mSDSts.sd_card_type = UNSTUFF_SD_STATUS(sd_status, 495, 16);
    gSD->mSDSts.size_of_prot_area = UNSTUFF_SD_STATUS(sd_status, 479, 32);
    gSD->mSDSts.speed_class = UNSTUFF_SD_STATUS(sd_status, 447, 8);
    gSD->mSDSts.perf_move = UNSTUFF_SD_STATUS(sd_status, 439, 8);
    gSD->mSDSts.au_size = UNSTUFF_SD_STATUS(sd_status, 431, 4);
    gSD->mSDSts.erase_size = UNSTUFF_SD_STATUS(sd_status, 423, 16);
    gSD->mSDSts.erase_timeout = UNSTUFF_SD_STATUS(sd_status, 407, 6);
    gSD->mSDSts.erase_offset = UNSTUFF_SD_STATUS(sd_status, 401, 2);
    gSD->mSDSts.uhs_speed_grade = UNSTUFF_SD_STATUS(sd_status, 399, 4);
    gSD->mSDSts.uhs_au_size = UNSTUFF_SD_STATUS(sd_status, 395, 4);

    /* If it is a SD ROM Card, set the WP flag */
    if (gSD->mSDSts.sd_card_type == 0x0001) {
        gSD->mWPEnabled = KAL_TRUE;
        MSDC_CRIT("[SD]It is a ROM Card!\r\n");
    }

    return NO_ERROR;

}


/*************************************************************************
* FUNCTION
*	SD_SetPreEraseBlk
*
* DESCRIPTION
*	ACMD23: set the number of write blocksto be pre-erased before writing
*	used for faster multiple Block Write
*
* PARAMETERS
*	num: used for storing number of blocks during multi-block operation
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_SetPreEraseBlk(kal_uint32 num)
{
    SDC_CMD_STATUS status;

    //[22:0] number of blocks
    num &= 0x003FFF;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;

    // send CMD23
    if ((status = SD_SendCmd(SDC_CMD_ACMD23, num,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;

}

/*************************************************************************
* FUNCTION
*	SD_EraseCmdClass
*
* DESCRIPTION
*	groups of erase commands including CMD32 ~CMD38
*
* PARAMETERS
*	cmd: indicate which command to execute
*	address: starting address wiht write protection
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*	CMD34~CMD37 are only for MMC
*
*************************************************************************/
SDC_CMD_STATUS SD_EraseCmdClass(kal_uint32 cmd , kal_uint32 address)
{
   SDC_CMD_STATUS status;
    kal_uint32 sdcard_status;
    kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);

    if (cmd != SDC_CMD_CMD38)
    {
        if ((status = SD_SendCmd(cmd, address,MSDC_CMD_TIMEOUT)) != NO_ERROR)
            return status;
    }
    else if ((status = SD_SendCmd(cmd, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;


    if (cmd == SDC_CMD_CMD38)
    {

        if ((status = SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT)) != NO_ERROR)
            return status;

        do
        {
            if ((status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&sdcard_status)) != NO_ERROR)
                return status;

            if (gMSDC_Handle->mIsPresent == KAL_FALSE)
                return ERR_INVALID_CARD;
        }
        while (R1_CURRENT_STATE(sdcard_status) != TRAN_STA);
    }

    return NO_ERROR;
}
/*************************************************************************
* FUNCTION
*	SD_Switch_MMC40
*
* DESCRIPTION
*	CMD6: set the command set or write to the EXT_CSD (for MMC4.0)
*
* PARAMETERS
*	access: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_MMC40(kal_uint8 access, kal_uint8 index, kal_uint8 value, kal_uint8 set)
{
    SDC_CMD_STATUS status = NO_ERROR;
    kal_uint32 arg = 0;
    kal_uint32 resp = 0;
    kal_bool retry = KAL_FALSE;
//    kal_uint8 *pData = NULL;

switch_start:

    arg = (access << 24) | (index << 16) | (value << 8) | set;

    // send command
    if ((status = SD_SendCmd(SDC_CMD_CMD6_MMC, arg,MSDC_CMD_TIMEOUT)) != NO_ERROR)
    {
        goto ERR_Exit;
    }

#ifndef DRV_LSD

    //read R1b
    if ((status = SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT)) != NO_ERROR)
        goto ERR_Exit;

#endif

    SD_GetStatus(gSD->mRCA, (kal_uint32*)&status);

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    resp=MSDC_Reg32(SDC_RESP0);

    if ((resp & MMC_SWITCH_ERROR) != 0)
    {
        if (retry == KAL_FALSE)
        {
#ifdef MSDC_TRACE_LEVEL2
            drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, resp, __LINE__);
#endif
            retry = KAL_TRUE;
            goto switch_start;
        }
        else
            return ERR_MMC_SWITCH_ERROR;
    }

    return NO_ERROR;

ERR_Exit:
    return status;
}

/*************************************************************************
* FUNCTION
*	SD_SendEXTCSD_MMC40
*
* DESCRIPTION
*	CMD8: read the content of EXT_CSD register
*
* PARAMETERS
*	kal: access mode
*	index: index to EXT_CSD
*  value: value to write to EXT_CSD
*	set:	selected command set
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef DRV_LSD
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else
SDC_CMD_STATUS SD_SendEXTCSD_MMC40(kal_uint32* rxbuffer)
{
	SDC_CMD_STATUS status;
	kal_uint32 blklen;
	//    SDC_CMD_STATUS status1;
	//    kal_bool retry = KAL_FALSE;
	//kal_uint32 idx = 0;

	//start:
	blklen=gSD->mBKLength;
    gSD->mBKLength = 512;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
	 //set to pio mode and clear fifo
	BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
	gMSDC_Handle->dma_xfer=0;
	MSDC_CLR_FIFO();

	// read the block of 512 bytes (make sure the rxbuffer is 4 byte aligned)
	if ((status = SD_SendCmd(SDC_CMD_CMD8_MMC40, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
	    goto ERR_Exit;

	//read R1
	if ((status = SD_CheckStatus()) != NO_ERROR)
	    goto ERR_Exit;

	//idx = 0;
	/*move data from FIFO to buffer*/
	if ((status = SD_WaitDatRdyOrTo(rxbuffer,512,KAL_FALSE))!=NO_ERROR)
	{
		goto ERR_Exit; 
	}

    kal_mem_cpy(MSDC_eCSD, rxbuffer, 512);
    gSD->mCSD.ext_csd = (T_EXT_CSD_MMC40 *)MSDC_eCSD;//rxbuffer;
    gSD->mBKLength=blklen;
    return NO_ERROR;

ERR_Exit:
    
    MSDC_FatalErrorHandle();
    return status;
}
#endif
/*************************************************************************
* FUNCTION
*  SD_CheckTimeoutWithSleep
*
* DESCRIPTION
*	check timeout or not and sleep 1 tick if has been waited more than 10 ms
*
* PARAMETERS
*	start_time: the time start to wait, get with drv_get_current_time
*     duration_ms: the timeout limitation
*
* RETURNS
*	kal_bool, timeout:KAL_TRUE; not timeout:KAL_FALSE;
*
* GLOBALS AFFECTED
*	gMSDC_Handle->is_timeout
*
* NOTE:
*     This function should be called in the wait loop to prevent block other tasks.
*
*************************************************************************/
kal_bool SD_CheckTimeoutWithSleep(kal_int32 start_time,
                         kal_int32 duration_ms)
{
    kal_int32 elapsed_time = drv_get_duration_ms(start_time);    
    //check timeout or not
    if(elapsed_time > duration_ms)
    {
        gMSDC_Handle->is_timeout = KAL_TRUE;        
        return KAL_TRUE;
    }
    gMSDC_Handle->is_timeout = KAL_FALSE;

    if(elapsed_time < 10)
    {
        return KAL_FALSE;
    }
    else if ((KAL_FALSE == kal_query_systemInit())
#ifdef  __TST_WRITE_TO_FILE__/*error recording: considering error recording additionally*/
                && (KAL_FALSE == INT_QueryExceptionStatus())
#endif
                && (KAL_FALSE == kal_if_hisr())
                && (KAL_FALSE == kal_if_lisr()))
        {
            kal_sleep_task(1);
        }
    return KAL_FALSE;

}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	CMD6: switch command to query and select the specific functions. (SD1.1 or later)
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_Switch_SD11(kal_uint32 arg, T_SWITCH_STATUS* info)
{
	SDC_CMD_STATUS status = NO_ERROR;
	kal_uint32 blklen;
    gSD->mBKNum=1;
    blklen=gSD->mBKLength;
	gSD->mBKLength = SD_CMD6_RESP_LEN;
	MSDC_WriteReg32(SDC_BLK_NUM,1);
	//set to pio mode and clear fifo
	BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
	gMSDC_Handle->dma_xfer=0;
	MSDC_CLR_FIFO();

    if ((status = SD_SendCmd(SDC_CMD_CMD6_SD11, arg,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;
	
    status=SD_WaitDatRdyOrTo((kal_uint32 *)info,SD_CMD6_RESP_LEN,KAL_FALSE);
    gSD->mBKLength=blklen;
    return status;
}

/*************************************************************************
* FUNCTION
*	SD_Switch_SD11
*
* DESCRIPTION
*	Enable the high speed interface to support up to 50M Hz clock
*
* PARAMETERS
*	arg: argument
*	resp: buffer to contain the ther 64 bytes status information
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*
* NOTE
*
*************************************************************************/

#ifndef DRV_MSDC_CORRECT_CMD6
SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void)
{
	SDC_CMD_STATUS status;
    T_SWITCH_STATUS *p = (T_SWITCH_STATUS*)MSDC_Sector;
	MSDC_DEBUG("[SD][%s %d]send cmd6 \r\n",__FUNCTION__,__LINE__);

    if ((status = SD_Switch_SD11(SD_CMD6_QUERY_HIGH_SPEED, p)) != NO_ERROR)
        return status;

    if (p->max_current == 0)
        return ERR_SD_HS_FAIL;

    if ((p->group1_info & (1 << SD_FUNC_HIGH_SPEED)) &&
        (p->group1_result == SD_FUNC_HIGH_SPEED))
    {
        if ((status = SD_Switch_SD11(SD_CMD6_SELECT_HIGH_SPEED, p)) != NO_ERROR)
            return status;

        if (p->max_current == 0)
            return ERR_SD_HS_FAIL;

        if (p->group1_result == SD_FUNC_HIGH_SPEED)
            gSD->flags |= SD_FLAG_HS_SUPPORT;
    }
    else
        return ERR_SD_HS_FAIL;


    return NO_ERROR;
}
#else
typedef struct
{
    kal_uint16 max_current;
    kal_uint16 group1_info;
    kal_uint16 group1_status;
    kal_uint8  group1_result;
    kal_uint8  structure_version;
}T_Group1SwitchStatus;
/*************************************************************************
* FUNCTION
*	SD_ParseGroup1FunctionStatus
*
* DESCRIPTION
*	Parse the Group1 functons' information form the data returned by CMD6
*
* PARAMETERS
*	arg: 
*		T_Group1SwitchStatus* sf_status :  information of group1 function
*		kal_uint8* crude_info			: crude data returned by CMD6
*	resp:
*
* RETURNS
*	void
*
* GLOBALS AFFECTED
*	 None
* NOTE
*
*************************************************************************/
void SD_ParseGroup1FunctionStatus(T_Group1SwitchStatus* sf_status, kal_uint8* crude_info)
{
    sf_status->max_current = (((*(kal_uint8 *)crude_info) << 8)
        | (*(kal_uint8 *)(crude_info + 1)));
    sf_status->group1_info = (((*(kal_uint8 *)(crude_info + 12)) << 8)
        | (*(kal_uint8 *)(crude_info + 13)));
    sf_status->group1_result = ((*(kal_uint8 *)(crude_info + 16)) & 0xf);
    sf_status->structure_version = (*(kal_uint8 *)(crude_info + 17));
    sf_status->group1_status = (((*(kal_uint8 *)(crude_info + 28)) << 8)
        | (*(kal_uint8 *)(crude_info + 29)));    
}
/*************************************************************************
* FUNCTION
*	SD_QuerySwithHighSpeed
*
* DESCRIPTION
*	Send CMD6 with query or swith and check the response data.
*
* PARAMETERS
*	arg: kal_uint32 arg
*	resp:
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	MSDC_Sector
* NOTE
*
*************************************************************************/
SDC_CMD_STATUS SD_QuerySwithHighSpeed(kal_uint32 arg)
{
	T_Group1SwitchStatus sf_status;
	SDC_CMD_STATUS  	 cmd_status;
	if ((cmd_status = SD_Switch_SD11(arg, (T_SWITCH_STATUS*)MSDC_Sector)) != NO_ERROR)
       return cmd_status;
    SD_ParseGroup1FunctionStatus(&sf_status,(kal_uint8*)MSDC_Sector);
	if (0 == sf_status.max_current)
    	return ERR_HIGH_SPEED_CONSUMPTION;
	if ((SD_FUNC_HIGH_SPEED == sf_status.group1_result)\
		&& (0==(sf_status.group1_status & (1 << SD_FUNC_HIGH_SPEED))))
    	return NO_ERROR;//the high speed function can be switched
	if ((0xF == sf_status.group1_result) || (!(sf_status.group1_info & (1 << SD_FUNC_HIGH_SPEED))))
		return ERR_HIGH_SPEED_NOT_SUPPORT;//not support	
	if (sf_status.group1_status & (1 << SD_FUNC_HIGH_SPEED))//busy      
        return ERR_HIGH_SPEED_BUSY;
    return ERR_HIGH_SPEED_COMMON_ERROR;
}
/*************************************************************************
* FUNCTION
*	SD_SelectHighSpeed_SD11
*
* DESCRIPTION
*	Select high speed mode for the SD card that supports CMD6
*
* PARAMETERS
*	arg: void
*	resp:
*
* RETURNS
*	SDC_CMD_STATUS
*
* GLOBALS AFFECTED
*	gSD->flags
* NOTE
*
*************************************************************************/

SDC_CMD_STATUS SD_SelectHighSpeed_SD11(void)
{
    SDC_CMD_STATUS high_speed_status;
	kal_int32      t1;
	t1 = drv_get_current_time();
	do 
	{
    	high_speed_status = SD_QuerySwithHighSpeed(SD_CMD6_QUERY_HIGH_SPEED);//query
    	dbg_print("query high_speed_status: %x\r\n",high_speed_status);
		if (NO_ERROR == high_speed_status)
		{
			high_speed_status = SD_QuerySwithHighSpeed(SD_CMD6_SELECT_HIGH_SPEED);//switch
			dbg_print("switch high_speed_status: %x\r\n",high_speed_status);
			if (NO_ERROR == high_speed_status)
			{
				gSD->flags |= SD_FLAG_HS_SUPPORT;
				return NO_ERROR;
			}
			if (ERR_HIGH_SPEED_BUSY != high_speed_status)
				break;			
		}
		if (ERR_HIGH_SPEED_BUSY != high_speed_status)
            break;
        if (drv_get_duration_ms(t1)>500)
            return ERR_HIGH_SPEED_TIMEOUT;
		//if(SD_CheckTimeoutWithSleep(t1,500))
        //    return ERR_HIGH_SPEED_TIMEOUT;//timeout
	}while(1);	
	return high_speed_status;
}

#endif

void parse_Cmd6FunctionStatus(T_SWITCH_STATUS *new_status,kal_uint8 * cur_Status)
{
    new_status->max_current=((*(kal_uint8*)cur_Status)<<8)\
        | (*(kal_uint8 *)(cur_Status+1));
    new_status->ver=(*(kal_uint8 *)(cur_Status+17));
    new_status->group1_info=((*(kal_uint8 *)(cur_Status+12))<<8)\
        | (*(kal_uint8 *)(cur_Status+13));
    new_status->group1_result=(*(kal_uint8*)(cur_Status+16))&0xf;
    new_status->group1_busy=((*(kal_uint8*)(cur_Status+28))<<8)\
        | (*(kal_uint8 *)(cur_Status+29));
    
    new_status->group2_info=((*(kal_uint8 *)(cur_Status+10))<<8)\
        | (*(kal_uint8 *)(cur_Status+11));
    new_status->group2_result=((*(kal_uint8*)(cur_Status+16))>>4)&0xf;
    new_status->group2_busy=((*(kal_uint8*)(cur_Status+26))<<8)\
        | (*(kal_uint8 *)(cur_Status+27));

    new_status->group3_info=((*(kal_uint8 *)(cur_Status+8))<<8)\
        | (*(kal_uint8 *)(cur_Status+9));
    new_status->group3_result=(*(kal_uint8*)(cur_Status+15))&0xf;
    new_status->group3_busy=((*(kal_uint8*)(cur_Status+24))<<8)\
        | (*(kal_uint8 *)(cur_Status+25));

    new_status->group4_info=((*(kal_uint8 *)(cur_Status+6))<<8)\
        | (*(kal_uint8 *)(cur_Status+7));
    new_status->group4_result=((*(kal_uint8*)(cur_Status+15))>>4)&0xf;
    new_status->group4_busy=((*(kal_uint8*)(cur_Status+22))<<8)\
        | (*(kal_uint8 *)(cur_Status+23));

     new_status->group5_info=((*(kal_uint8 *)(cur_Status+4))<<8)\
        | (*(kal_uint8 *)(cur_Status+5));
    new_status->group5_result=(*(kal_uint8*)(cur_Status+14))&0xf;
    new_status->group5_busy=((*(kal_uint8*)(cur_Status+20))<<8)\
        | (*(kal_uint8 *)(cur_Status+21));

    new_status->group6_info=((*(kal_uint8 *)(cur_Status+2))<<8)\
        | (*(kal_uint8 *)(cur_Status+3));
    new_status->group6_result=((*(kal_uint8*)(cur_Status+14))>>4)&0xf;
    new_status->group6_busy=((*(kal_uint8*)(cur_Status+18))<<8)\
        | (*(kal_uint8 *)(cur_Status+19));
    /*
    dbg_print("new_status->group1_info :%x\r\n",new_status->group1_info);
    dbg_print("new_status->group1_result:%x\r\n",new_status->group1_result);
    dbg_print("new_status->group1_busy:%x\r\n",new_status->group1_busy);

    dbg_print("new_status->group2_info :%x\r\n",new_status->group2_info);
    dbg_print("new_status->group2_result:%x\r\n",new_status->group2_result);
    dbg_print("new_status->group2_busy:%x\r\n",new_status->group2_busy);

    dbg_print("new_status->group3_info :%x\r\n",new_status->group3_info);
    dbg_print("new_status->group3_result:%x\r\n",new_status->group3_result);
    dbg_print("new_status->group3_busy:%x\r\n",new_status->group3_busy);

    dbg_print("new_status->group4_info :%x\r\n",new_status->group4_info);
    dbg_print("new_status->group4_result:%x\r\n",new_status->group4_result);
    dbg_print("new_status->group4_busy:%x\r\n",new_status->group4_busy);

    dbg_print("new_status->group5_info :%x\r\n",new_status->group5_info);
    dbg_print("new_status->group5_result:%x\r\n",new_status->group5_result);
    dbg_print("new_status->group5_busy:%x\r\n",new_status->group5_busy);

    dbg_print("new_status->group6_info :%x\r\n",new_status->group6_info);
    dbg_print("new_status->group6_result:%x\r\n",new_status->group6_result);
    dbg_print("new_status->group6_busy:%x\r\n",new_status->group6_busy);
    dbg_print("new_status->max_current:%x\r\n",new_status->max_current);
    dbg_print("new_status->ver:%x\r\n",new_status->ver);
    */
    
}

SDC_CMD_STATUS SD_CheckSwitch(void)
{
    //read the function support by current card
    kal_uint32 status;
    T_SWITCH_STATUS funcStatus;

    char *uhs_mode[] = {"SDR12", "SDR25", "SDR50", "SDR104", "DDR50"};
    char *speed_mode[] = {"DS", "HS"};
    char *drv_strength[] = {"TYPE_A", "TYPE_B", "TYPE_C", "TYPE_D"};
    char *cur_limit[] = {"200mA", "400mA", "600mA", "800mA"};
    
    if ((status = SD_Switch_SD11(SD_CMD6_QUERY_SUPPORT_FUNCTION, (T_SWITCH_STATUS*)MSDC_Sector)) != NO_ERROR)
       return status;
    parse_Cmd6FunctionStatus(&funcStatus,(kal_uint8*)MSDC_Sector);
    gSD->card_support.function1=funcStatus.group1_info;
    gSD->card_support.function2=funcStatus.group2_info;
    gSD->card_support.function3=funcStatus.group3_info;
    gSD->card_support.function4=funcStatus.group4_info;
    #if defined(MSDC_CONFIG_SD30_SUPPORT)
    if (gMSDC_Handle->mMSDC_type==SD30_CARD)
    {
        //for SD3.0
        /*set bus speed mode*/
        if(gSD->card_support.function1&gMSDC_Handle->host_support.function1&FUN1_SDR104)
            gSD->function_set.function1=FUN1_SET_SDR104;
        else if(gSD->card_support.function1&gMSDC_Handle->host_support.function1&FUN1_DDR50)
            gSD->function_set.function1=FUN1_SET_DDR50;
        else if(gSD->card_support.function1&gMSDC_Handle->host_support.function1&FUN1_SDR50)
            gSD->function_set.function1=FUN1_SET_SDR50;
        else if(gSD->card_support.function1&gMSDC_Handle->host_support.function1&FUN1_SDR25_HS)
            gSD->function_set.function1=FUN1_SET_SDR25_HS;
        else 
            gSD->function_set.function1=FUN1_SET_SDR12_DS;
        /*set command system*/
        gSD->function_set.function2=FUN2_SET_DEFAULT;
        /*set driver strength */
        if (gSD->card_support.function3&gMSDC_Handle->host_support.function3&FUN3_TYPE_A)
            gSD->function_set.function3=FUN3_SET_TYPE_A;
        else if(gSD->card_support.function3&gMSDC_Handle->host_support.function3&FUN3_TYPE_B)
            gSD->function_set.function3=FUN3_SET_TYPE_B;
        else if(gSD->card_support.function3&gMSDC_Handle->host_support.function3&FUN3_TYPE_C)
            gSD->function_set.function3=FUN3_SET_TYPE_C;
        else if(gSD->card_support.function3&gMSDC_Handle->host_support.function3&FUN3_TYPE_D)
            gSD->function_set.function3=FUN3_SET_TYPE_D;
        else
            gSD->function_set.function3=FUN3_SET_TYPE_A;
        /*set current limit*/
        if (gSD->function_set.function1==FUN1_SET_SDR104||gSD->function_set.function1==FUN1_SET_DDR50
            ||gSD->function_set.function1==FUN1_SET_SDR50)
        {
            if(gSD->card_support.function4&gMSDC_Handle->host_support.function4&FUN4_800MA)
                gSD->function_set.function4=FUN4_SET_800MA;
            else if (gSD->card_support.function4&gMSDC_Handle->host_support.function4&FUN4_600MA)
                gSD->function_set.function4=FUN4_SET_600MA;
            else if (gSD->card_support.function4&gMSDC_Handle->host_support.function4&FUN4_400MA)
                gSD->function_set.function4=FUN4_SET_400MA;
            else
                gSD->function_set.function4=FUN4_SET_200MA;
        }
        else
        {
            gSD->function_set.function4=FUN4_SET_200MA;
        }

        MSDC_CRIT("[SD][%s]Switch to %s speed mode! \r\n", __FUNCTION__,
            uhs_mode[gSD->function_set.function1]);
        MSDC_CRIT("[SD][%s]Switch to %s drive strength! \r\n", __FUNCTION__,
            drv_strength[gSD->function_set.function3]);
        MSDC_CRIT("[SD][%s]Switch to %s current limit! \r\n", __FUNCTION__,
            cur_limit[gSD->function_set.function4]);
    }
    else
   #endif
    {
        //for 2.0 HS DS card
        if(gSD->card_support.function1&gMSDC_Handle->host_support.function1&FUN1_SDR25_HS)
            gSD->function_set.function1=FUN1_SET_SDR25_HS;
        else 
            gSD->function_set.function1=FUN1_SET_SDR12_DS;

        MSDC_CRIT("[SD][%s]Switch to %s speed mode! \r\n", __FUNCTION__,
            speed_mode[gSD->function_set.function1]);
    }
    return NO_ERROR;
    
}

SDC_CMD_STATUS SD_QuerySwith(kal_uint32 cmd6_arg)
{
    
	SDC_CMD_STATUS  	 cmd_status;
    T_SWITCH_STATUS  card_support;
	if ((cmd_status = SD_Switch_SD11(cmd6_arg, (T_SWITCH_STATUS*)MSDC_Sector)) != NO_ERROR)
       return cmd_status;
    parse_Cmd6FunctionStatus(&card_support,(kal_uint8*)MSDC_Sector);
    /*
    dbg_print("card_support.group1_info :%x\r\n",card_support.group1_info);
    dbg_print("card_support.group1_result:%x\r\n",card_support.group1_result);
    dbg_print("card_support.group1_busy:%x\r\n",card_support.group1_busy);

    dbg_print("card_support.group2_info :%x\r\n",card_support.group2_info);
    dbg_print("card_support.group2_result:%x\r\n",card_support.group2_result);
    dbg_print("card_support.group2_busy:%x\r\n",card_support.group2_busy);

    dbg_print("card_support.group3_info :%x\r\n",card_support.group3_info);
    dbg_print("card_support.group3_result:%x\r\n",card_support.group3_result);
    dbg_print("card_support.group3_busy:%x\r\n",card_support.group3_busy);

    dbg_print("card_support.group4_info :%x\r\n",card_support.group4_info);
    dbg_print("card_support.group4_result:%x\r\n",card_support.group4_result);
    dbg_print("card_support.group4_busy:%x\r\n",card_support.group4_busy);

    dbg_print("card_support.group5_info :%x\r\n",card_support.group5_info);
    dbg_print("card_support.group5_result:%x\r\n",card_support.group5_result);
    dbg_print("card_support.group5_busy:%x\r\n",card_support.group5_busy);

    dbg_print("card_support.group6_info :%x\r\n",card_support.group6_info);
    dbg_print("card_support.group6_result:%x\r\n",card_support.group6_result);
    dbg_print("card_support.group6_busy:%x\r\n",card_support.group6_busy);
    dbg_print("card_support.max_current:%x\r\n",card_support.max_current);
    dbg_print("card_support.ver:%x\r\n",card_support.ver);
    */
    if (0 == card_support.max_current)
    	return ERR_HIGH_SPEED_CONSUMPTION;
    #if defined(MSDC_CONFIG_SD30_SUPPORT)
    if (gMSDC_Handle->mMSDC_type==SD30_CARD)
    {
        if ((gSD->function_set.function1==card_support.group1_result)\
            &&(0==(card_support.group1_busy &(1<<(gSD->function_set.function1)))))
        {

            if ((gSD->function_set.function3==card_support.group3_result)\
            &&(0==(card_support.group3_busy &(1<<(gSD->function_set.function3)))))
            {

                if ((gSD->function_set.function4==card_support.group4_result)\
                &&(0==(card_support.group4_busy &(1<<(gSD->function_set.function4)))))
                {

                    return NO_ERROR;
                }
            }
        }
        dbg_print("gSD->function_set.function1=%x card_support.group1_result=%x\r\n",gSD->function_set.function1,card_support.group1_result);
        dbg_print("gSD->function_set.function3=%x card_support.group3_result=%x\r\n",gSD->function_set.function3,card_support.group3_result);
        dbg_print("gSD->function_set.function4=%x card_support.group4_result=%x\r\n",gSD->function_set.function4,card_support.group4_result);
        dbg_print("busy1 %x busy3 %x busy4 %x\r\n",(card_support.group1_busy &(1<<(gSD->function_set.function1)))\
            ,(card_support.group3_busy &(1<<(gSD->function_set.function3)))\
            ,(card_support.group4_busy &(1<<(gSD->function_set.function4))));
        if ((0xF == card_support.group1_result)\
            || (!(card_support.group1_info & (1<<(gSD->function_set.function1)))))
		    return ERR_SPEED_MODE_UNSUPPORT;//not support	
		if ((0xF == card_support.group3_result)\
            || (!(card_support.group3_info & (1<<(gSD->function_set.function3)))))
		    return ERR_DRIVER_TYPE_UNSUPPORT;//not support	
		if ((0xF == card_support.group4_result)\
            || (!(card_support.group4_info & (1<<(gSD->function_set.function4)))))
		    return ERR_CURRENT_LIMIT_UNSUPPORT;//not support	

            
	    if (card_support.group1_busy & (1 << (gSD->function_set.function1)))//busy      
            return ERR_SWITCH_BUSY;
        if (card_support.group3_busy & (1 << (gSD->function_set.function3)))//busy      
            return ERR_SWITCH_BUSY;
        if (card_support.group4_busy & (1 << (gSD->function_set.function4)))//busy      
            return ERR_SWITCH_BUSY;
    }
    else
    #endif
    {
        if ((gSD->function_set.function1==card_support.group1_result)\
            &&(0==(card_support.group1_busy &(1<<(gSD->function_set.function1)))))
            return NO_ERROR;
        if ((0xF == card_support.group1_result)\
            || (!(card_support.group1_info & (1<<(gSD->function_set.function1)))))
		    return ERR_HIGH_SPEED_NOT_SUPPORT;//not support	
	    if (card_support.group1_busy & (1 << (gSD->function_set.function1)))//busy      
            return ERR_HIGH_SPEED_BUSY;
    }
    
    return ERR_HIGH_SPEED_COMMON_ERROR;
}

SDC_CMD_STATUS SD_SwitchSpeedMode(void)
{
    kal_uint32 status,set_function;
    kal_int32      t1;

    if (gSD->mSCR.spec_ver<SCR_SEC_VER_1)
    {
        gSD->function_set.function1=0;
        return NO_ERROR;
    }
    if (!(gSD->mCSD.ccc&CCC_SWITCH))
    {
        gSD->function_set.function1=0;
        return NO_ERROR;
    }
        
	t1 = drv_get_current_time();
    if ((status =SD_CheckSwitch()) != NO_ERROR)
        return status;
    #if defined(MSDC_CONFIG_SD30_SUPPORT)
    if (gMSDC_Handle->mMSDC_type==SD30_CARD)
    {
        set_function=0x00ff0000|gSD->function_set.function1|(gSD->function_set.function3<<8)|(gSD->function_set.function4<<12);
    }
    else
    #endif
    {
        set_function=0x00fffff0|gSD->function_set.function1;
    }
	do 
	{   
    	status = SD_QuerySwith(SD_CMD6_QUERY_SWITCH|set_function);//query
		if (NO_ERROR == status)
		{
			status = SD_QuerySwith(SD_CMD6_SELECT_SWITCH|set_function);//switch
			if (NO_ERROR == status)
			{
			    if (gMSDC_Handle->mMSDC_type==SD30_CARD)
                {         
                    gSD->flags |= SD_FLAG_UHS_ENABLED;        
                }
                else if (gSD->function_set.function1==1)
                {
                    gSD->flags |= SD_FLAG_HS_ENABLED;
                }
				
				return NO_ERROR;
			}
			if (ERR_SWITCH_BUSY != status)
				break;			
		}
		if (ERR_SWITCH_BUSY != status)
            break;
        if (drv_get_duration_ms(t1)>500)
            return ERR_SWITCH_TIMEOUT;
	}while(1);	
    return status;
}
SDC_CMD_STATUS SD_GoInactive(kal_uint16 rca)
{
     SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD15, (kal_uint32)rca << 16,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    return NO_ERROR;
}

SDC_CMD_STATUS SD_ReadStream_MMC(kal_uint32 address, kal_uint32* rxbuffer, kal_uint32 bytes)
{
    
    return 0;	
} 


// write data stream from card only for MMC
SDC_CMD_STATUS SD_WriteStream_MMC(kal_uint32 address, kal_uint32* txbuffer, kal_uint32 bytes)
{
     return 0;
}

//program CSD, transfer CSD through data line
SDC_CMD_STATUS SD_ProgramCSD(kal_uint32 Csd[4])
{
    SDC_CMD_STATUS status;
    kal_uint32 blklen;
    //set block length to 16 , num to 1
    
    gSD->mBKNum=1;
    blklen=gSD->mBKLength;
	gSD->mBKLength = 16;
	MSDC_WriteReg32(SDC_BLK_NUM,1);
	//set to pio mode and clear fifo
	BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
	gMSDC_Handle->dma_xfer=0;
	MSDC_CLR_FIFO();


    if ((status = SD_SendCmd(SDC_CMD_CMD27, 0,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
    {
        //SD_WaitDatRdyOrTo();
        return status;
    }
    //send CSD 128 bits
    status=SD_WaitDatRdyOrTo(Csd,16,KAL_TRUE);
    //set block length back to 512
    BitFieldWrite32((kal_uint32*)SDC_CMD, 512, SDC_CMD_BLKLEN);
    gSD->mBKLength=blklen;
    return status;
}


//set write protect
SDC_CMD_STATUS SD_SetWriteProtect(kal_uint32 address)
{
    SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD28, address,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //wait until data line is ready
    status =SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT);
    return status;
}

//clear write protect
SDC_CMD_STATUS SD_ClrWriteProtect(kal_uint32 address)
{
     SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD29, address,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    status=SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT);
    return status;
}

// send write protect(single block read)
SDC_CMD_STATUS SD_SendWriteProtect(kal_uint32 address, kal_uint32* WPBits32)
{
    SDC_CMD_STATUS status;
    kal_uint32	tmp,blklen;

    
    BitFieldWrite32((kal_uint32*)SDC_CMD, 4, SDC_CMD_BLKLEN);
    blklen=gSD->mBKLength;
    gSD->mBKLength=4;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    MSDC_CLR_FIFO();

    if ((status = SD_SendCmd(SDC_CMD_CMD30, address,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    //read 32 write protection bits
    tmp=MSDC_FIFO_READ32();
    MSDC_InvertN((kal_uint8*)WPBits32, (kal_uint8*)&tmp, 4);
    // configure the controller to the original block length
    BitFieldWrite32((kal_uint32*)SDC_CMD, 512, SDC_CMD_BLKLEN);
    gSD->mBKLength=blklen;

    return NO_ERROR;
}

// CMD39: Fast IO-used to write and read 8 bit register
SDC_CMD_STATUS SD_FastIO_MMC(kal_uint16 rca, kal_bool isWrite, kal_uint8 reg_adrs, kal_uint8 data)
{
     SDC_CMD_STATUS status;
    kal_uint32 arg = 0;

    arg = rca << 16;
    arg |= isWrite << 15;
    arg |= reg_adrs << 8;
    arg |= data;

    if ((status = SD_SendCmd(SDC_CMD_CMD39_MMC, arg,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    return NO_ERROR;
}


// Sets the system into interrupt mode (MMC)
SDC_CMD_STATUS SD_GoIRQ_MMC(void)
{
     SDC_CMD_STATUS status;

    if ((status = SD_SendCmd(SDC_CMD_CMD40_MMC, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    status = *(kal_uint32*)SDC_RESP0;
#ifdef MSDC_TRACE_LEVEL2
    drv_trace2(TRACE_GROUP_6, MSDC_INFORM_R0, status, __LINE__);
#endif

    return NO_ERROR;
}

// Used to set/reset password ,lock/unlock the card and force erase total card.
// similiar to a signle block write structure.(CMD42)
// max password length = 16
SDC_CMD_STATUS SD_LockUnlock(SD_LOCK_OP op, kal_char* Oldpwd, kal_char* Newpwd, kal_uint8 Oldlen, kal_uint8 Newlen)
{
     SDC_CMD_STATUS status;
    kal_uint8 lockbk[SDC_MAX_LOCKBK];
    kal_uint32 blklen, *ptr = (kal_uint32*)lockbk, count;

    if (Oldlen > 16 || Newlen > 16)
        return ERR_ERRORS;

    /* save the original block length*/
    blklen = gSD->mBKLength;

    kal_mem_set(lockbk, 0, SDC_MAX_LOCKBK);

    switch (op)
    {
        case SET_PWD:
            lockbk[0] = 0x01;
            break;

        case CLR_PWD:
            lockbk[0] = 0x02;
            break;

        case LOCK_CARD:
            lockbk[0] = 0x04;
            break;

        case UNLOCK_CARD:
            lockbk[0] = 0x00;
            break;

        case ERASE:
            lockbk[0] = 0x08;
            break;
    }

    lockbk[1] = Oldlen + Newlen;
    kal_mem_cpy(&lockbk[2], Oldpwd, Oldlen);
    kal_mem_cpy(&lockbk[2 + Oldlen], Newpwd, Newlen);

    /* set block length */
    if (op != ERASE)
    {
        SD_SetBlength(2 + lockbk[1]);
        count = ((lockbk[1] + 2) % sizeof(kal_uint32)) ? ((lockbk[1] + 2) / sizeof(kal_uint32) + 1) :
                ((lockbk[1] + 2) / sizeof(kal_uint32));
        gSD->mBKNum=1;
        blklen=gSD->mBKLength;
    	gSD->mBKLength = 2 + lockbk[1];
    	MSDC_WriteReg32(SDC_BLK_NUM,1);
    	//set to pio mode and clear fifo
    	BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
    	gMSDC_Handle->dma_xfer=0;
    	MSDC_CLR_FIFO();
    }
    else
    {
        SD_SetBlength(1);
        gSD->mBKNum=1;
        blklen=gSD->mBKLength;
	    gSD->mBKLength = 1;
	    MSDC_WriteReg32(SDC_BLK_NUM,1);
	    //set to pio mode and clear fifo
	    BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
	    gMSDC_Handle->dma_xfer=0;
	    MSDC_CLR_FIFO();
        count = 1;
    }
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    /* send command */
    if ((status = SD_SendCmd(SDC_CMD_CMD42, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    /* read R1b */
    SD_CheckStatus();
    /* clear FIFO */
    MSDC_CLR_FIFO();
   
	
#ifndef DRV_LSD
	status=SD_WaitDatRdyOrTo(ptr,count,KAL_TRUE);
    
#endif
		
    /* wait util card has finished programming */
    SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT);
    // restore the block length back
     if (status != NO_ERROR)
     {
     	 return gMSDC_Handle->error;
     }
	 
    // restore the block length back
	 SD_SetBlength(blklen);
    gSD->mBKLength=blklen;
    /* check status*/
    SD_GetStatus(gSD->mRCA, &status);
	
    if (status & R1_LOCK_UNLOCK_FAILED_24)
        return ERR_LOCK_UNLOCK_FAILED;

    if ((op == LOCK_CARD) && !(status & R1_CARD_IS_LOCKED_25))
        return ERR_LOCK_UNLOCK_FAILED;

    if ((op == UNLOCK_CARD) && (status & R1_CARD_IS_LOCKED_25))
        return ERR_LOCK_UNLOCK_FAILED;

    return NO_ERROR;
}

// ACMD13: read SD status(512bits = 64bytes single block read)
SDC_CMD_STATUS SD_GetSDStatus(kal_uint32* sd_status)
{
     SDC_CMD_STATUS status;
    kal_uint32 blklen;

    
    //if ((status = SD_SetBlength(64)) != NO_ERROR)
    //    return status;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;
    // save the orignial block length
    blklen=gSD->mBKLength;
    gSD->mBKLength = 64;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    MSDC_DEBUG("[SD][%s %d]send acmd13\r\n",__FUNCTION__,__LINE__);
    
    //set to pio mode and clear fifo
    BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
    gMSDC_Handle->dma_xfer=0;
    MSDC_CLR_FIFO();
    // send ACMD13
    if ((status = SD_SendCmd(SDC_CMD_ACMD13, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;
    
    // read sd status(64bytes = 4x16)
    status=SD_WaitDatRdyOrTo(sd_status,64,KAL_FALSE);
	if (status !=NO_ERROR) 
	{
		return status;
    }
    gSD->mBKLength=blklen;
    return NO_ERROR;
}
//ACMD22: get the number of written write blocks(4bytes single block read)
SDC_CMD_STATUS SD_GetNumWrittenBlk(kal_uint32* num)
{
     SDC_CMD_STATUS status;
    kal_uint32 blklen, tmp;

    // send APP_CMD
    if ((status = SD_Cmd55(gSD->mRCA)) != NO_ERROR)
        return status;
    
    blklen=gSD->mBKLength;
    gSD->mBKLength = 4;
    MSDC_WriteReg32(SDC_BLK_NUM,1);
    MSDC_DEBUG("[SD][%s %d]send acmd13\r\n",__FUNCTION__,__LINE__);
    
    //set to pio mode and clear fifo
    BitFieldWrite32((kal_uint32 *)MSDC_CFG, 1, MSDC_CFG_PIO);
    gMSDC_Handle->dma_xfer=0;
    MSDC_CLR_FIFO();
    
    // send CMD22
    if ((status = SD_SendCmd(SDC_CMD_ACMD22, SDC_NO_ARG,MSDC_CMD_TIMEOUT)) != NO_ERROR)
        return status;

    //read R1
    if ((status = SD_CheckStatus()) != NO_ERROR)
        return status;

    // read the number of written write blocks(4bytes)

    if ((status=SD_WaitDatRdyOrTo(&tmp,4,KAL_FALSE))!=NO_ERROR)
		return status;
   
    MSDC_InvertN((kal_uint8*)num, (kal_uint8*)&tmp, 4);

    // resotre block length
    gSD->mBKLength=blklen;
    return NO_ERROR;
}

#ifdef DRV_MSDC_HW_CONTENTION
extern kal_semid dclMsdcArb;
#endif

void SD_startFastFormat(void)
{
	#if defined(__AUDIO_DSP_LOWPOWER__)
    AUDMA_LOCK(AUDMA_ID_MSDC);
	#endif

#ifdef DRV_MSDC_HW_CONTENTION
    kal_uint32 retAddr;

#if defined(__RVCT__)
    /* RVCT doesn't support inline assemlber; bypass temporarily */
    retAddr = 0;
#else   /* __RVCT__ */
    /* get the return address */
    __asm
    {
        MOV retAddr, lr
    }
#endif  /* __RVCT__ */


    if (NULL == dclMsdcArb)
        ASSERT(0);

    if (kal_query_systemInit() == KAL_FALSE)
    {
        /*must gain resource here before calling writeSectors*/
        kal_take_sem(dclMsdcArb, 1);
        SD_setArbRetAddr(retAddr);
        SD_setArbThdId((kal_uint32)kal_get_current_thread_ID());
    }

#endif


#ifdef DRV_LSD
    LSD_startFastFormat();
#elif defined(__DRV_MSDC_FAST_FORMAT__)
    gMSDC_Handle->MSDC_fastFormat = KAL_TRUE;
#endif
}

void SD_closeFastFormat(void)
{
	#ifdef DRV_LSD
	LSD_closeFastFormat();
	#elif defined(__DRV_MSDC_FAST_FORMAT__)
	gMSDC_Handle->MSDC_fastFormat = KAL_FALSE;
	#endif

	#ifdef DRV_MSDC_HW_CONTENTION

	if (kal_query_systemInit() == KAL_FALSE)
	{
	    /*when the semaphore is returned, we set thdId to zero, but not retAddr, we can know that it is released from here*/
	    SD_setArbThdId(NULL);
	    kal_give_sem(dclMsdcArb);
	}

	#endif

	#if defined(__AUDIO_DSP_LOWPOWER__)
	AUDMA_UNLOCK(AUDMA_ID_MSDC);
	#endif

}


//__attribute__ ((section ("EXT_BOOTLOADER_CODE")))SDC_CMD_STATUS SD_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum)
SDC_CMD_STATUS SD_FlushSectors(kal_uint32 startSector, kal_uint32 sectorNum)
{
     SDC_CMD_STATUS status;
    kal_uint32 sectorMult,maxBlk;

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        sectorMult = 1;
    else
        sectorMult = SECTOR_SIZE;
    maxBlk=gSD->mCSD.capacity /512;
    if(0 == sectorNum || sectorNum > maxBlk || startSector > maxBlk){
		//ASSERT(0);
		status = STATUS_INVALID_CTRL_DATA;
		return status;
	}

	/*check that ending block should be smaller than maximum block number*/
	if((startSector + sectorNum - 1) > maxBlk){
		//ASSERT(0);
		status = STATUS_INVALID_CTRL_DATA;
		return status;
	}
    MSDC_PDNControl(KAL_FALSE);

    // there are differences between SD and MMC
    // tag erase start(CMD32)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD32, sectorMult * startSector)) != NO_ERROR)
    {
        goto ErrorExit;
    }

    // tag erase end(CMD33)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD33, sectorMult * (startSector + sectorNum - 1))) != NO_ERROR)
    {
        goto ErrorExit;
    }

    // erase...(CMD38)
    if ((status = SD_EraseCmdClass(SDC_CMD_CMD38, 0)) != NO_ERROR)
    {
        goto ErrorExit;
    }

ErrorExit:
    MSDC_PDNControl(KAL_TRUE);
    return status;
}

#ifdef IC_MODULE_TEST

kal_bool MSDC_ModuleTest_Report(void)
{
     
	 SDC_CMD_STATUS status;
	 
	 if (gMSDC_Handle->mIsInitialized == KAL_FALSE)
		 return KAL_FALSE;
 
	 MSDC_PDNControl(KAL_FALSE);
 
	 gMSDC_Handle->mIsInitialized = KAL_TRUE;
	 gMSDC_Handle->trySingleLine = KAL_TRUE;
 
	 status = SD_Initialize();
 
	 if (status == NO_ERROR)
		 return KAL_TRUE;
	 else
		 return KAL_FALSE;
 
}
#endif

#else
#ifdef DRV_LSD
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;
#endif
#endif //  defined(__MSDC_SD_MMC__)

#ifdef MSDC_DEBUG

#define TST_ADRS	512*12
kal_uint32 SD_MMC_Test(void)
{

	 return 0;

}
#endif	// FPGA_DEBUG

#endif//!defined(__UBL__) || defined(__CARD_DOWNLOAD__) || defined(__EMMC_BOOTING__)

#else //DRV_MSDC_OFF
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
//RHR ADD
#include "kal_general_types.h"
//#include "btif_sw.h"
#include "kal_public_api.h"
#include "kal_internal_api.h"
#include "kal_public_defs.h"
//RHR REMOVE
/*
//MSBB remove #include "kal_non_specific_general_types.h"
//MSBB remove #include "app_buff_alloc.h"
#include "intrCtrl.h"
//#include "gpio_sw.h"
#include "init.h"
#include "pmic_features.h"
#include "pmu_sw.h"
#include "nucleus.h"
#include "ev_defs.h"
*/
//RHR
//#include "gpt_sw.h"
#include "drv_comm.h"
#include "reg_base.h"
#include "msdc_def.h"
#include "sd_def.h"
#include "upll_ctrl.h"
//#include	"Drv_trc.h"
#ifdef DCL_MSDC_INTERFACE
#include "dcl.h"
void SD_dummyAPI(void) {}
SDC_CMD_STATUS SD_SetBlength(kal_uint32 BKLength) {}
SDDriver_t sd_driver_MTK1 =
{
    (DCL_SINGLE_BLK_RD)SD_dummyAPI,
    (DCL_MUL_BLK_RD)SD_dummyAPI,
    (DCL_SINGLE_BLK_WR)SD_dummyAPI,
    (DCL_MUL_BLK_WR)SD_dummyAPI,
    (DCL_SD_INITITALIZE)SD_dummyAPI,
    (DCL_SET_PRE_ERASE_CNT)SD_dummyAPI,
    (DCL_SD_SET_CALLBACK)SD_dummyAPI,
    (DCL_SET_READ_TEST_FLAG)SD_dummyAPI,
    (DCL_SD_READ_TEST)SD_dummyAPI,
    (DCL_SD_SET_UPLL_CLOCK_TEST)SD_dummyAPI,
    (DCL_SD_ERASE_BLK)SD_dummyAPI,
    (DCL_GPD_MUL_BLK_RD)SD_dummyAPI,
    (DCL_GPD_MUL_BLK_WR)SD_dummyAPI,
};
#endif //DCL_MSDC_INTERFACE

void SD_startFastFormat(void) {}
void SD_closeFastFormat(void) {}
T_SDC_HANDLE	gSD_blk[SD_NUM];
T_SDC_HANDLE	*gSD = gSD_blk;

#if defined( __MSDC_BASIC_LOAD__) || defined( __MEUT__)
kal_uint32 msdc_ReadTestFlag;
#endif

#endif //DRV_MSDC_OFF


