/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 * Filename:
 * ---------
 *   devdrv_fakeapi.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   For missing functions in new chip, fast porting
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * 09 24 2013 da.li
 * removed!
 * Add AUXADC driver for immediate temperature sampling in SP project.
 *
 * removed!
 * removed!
 * add pw and chr_det module in devdrv, remove them from devdrv_fakeapi.c
 *
 * removed!
 * removed!
 * move dma_recover_all() to drv_gdma.c
 *
 * removed!
 * removed!
 * remove unused fake_api
 *
 * removed!
 * removed!
 * remove unnecessary HISR functions
 *
 * removed!
 * removed!
 * MT6290E1_FristCall Branch sync back to MOLY Trunk
 *
 * removed!
 * removed!
 * LISR 2 HISR support, driver part
 *
 * removed!
 * removed!
 * MOLY LISR2HISR, Driver part
 *
 * removed!
 * removed!
 * .add AUXADC dummy function
 *
 * removed!
 * removed!
 * provide PWM fake API to solve link error of multimode
 *
 * removed!
 * removed!
 * .add fake API DclSADC_Open/DclSADC_Control/DclSADC_Close
 *
 * removed!
 * removed!
 * .Sync DCM function to MOLY 6290 for sleep flow
 *
 * removed!
 * removed!
 * Merging //MOLY_CBr/yaohua.liu/MOLY_NAND/... to TRUNK
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .add DCM fakeapi temporarily before porting finish
 *
 * removed!
 * removed!
 * Remove PWM and Keyboard fake api
 *
 * removed!
 * removed!
 * remove NFI_Reset() from fakeapi, and add NAND_SUPPORT macro in init.c
 *
 * removed!
 * removed!
 * *: Remove EMI fake API
 *
 * removed!
 * removed!
 * *: Remove EMI fake API
 *
 * removed!
 * removed!
 * *: Remove EMI fake API
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .reverse WDT_SET_RETN_FLAG/WDT_CLR_RETN_FLAG wait for cindy modify
 *
 * removed!
 * removed!
 * .remove fakeAPI
 *
 * removed!
 * removed!
 * update custom_EMI function into custom_EMI_MT6290.c and remove it in devdrv_fakeapi.c
 * update cfgGen_EMI.pl for MT6290
 *
 * removed!
 * removed!
 * removed!
 * mask the "DclSI2C_Initialize" in  devdrv_common.c
 * mask the "DclSI2C_Initialize" in devdrv_fakeapi.c
 * DRV_I2C_6276_SERIES -> DRV_I2C_6290_SERIES in drv_features_6290.h
 *
 * removed!
 * removed!
 * Remove fake APIs at fakeapi.c & implement it at SF MTD driver
 *
 * removed!
 * removed!
 * Remove PreInit_Seriport function call in MT6290
 *
 * removed!
 * removed!
 * Remove Fake API
 *
 * removed!
 * removed!
 * Remove unused fake_api
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * add PMIC 6339 driver API
 *
 * 02 22 2013 da.wang
 * removed!
 * .Remove GPIO fakeapi
 *
 * removed!
 * removed!
 * [RTC] Remove RTC fake API.
 *
 * removed!
 * removed!
 * Enable Prefetch Buffer and remove it from fake api.
 *
 * removed!
 * removed!
 * chip rename:MT7208 to MT6290
 *
 * removed!
 * removed!
 * add EMI_reg_dump_init dummy function
 ****************************************************************************/

#include <kal_public_api.h>
#include <dcl.h>
#include <init.h>
#include <drv_comm.h>
#include <reg_base.h>
#include <fs_gprot.h>
#include <pll.h>
//#include "mtd_dal_spi.h"

#define FAKEAPI_ENABLE_DRIVER 1

#if FAKEAPI_ENABLE_DRIVER
/************** Driver Related Fake APIs/Variables - Start  *******************/



/************** Driver Related Fake APIs/Variables - End    *******************/
#endif /* end of FAKEAPI_ENABLE_DRIVER */


