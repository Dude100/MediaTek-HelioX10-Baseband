/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER  S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER  S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK  S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK  S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
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
 *   init_trc_id.h
 *
 * Project:
 * --------
 *   WR8
 *
 * Description:
 * ------------
 *   Time stamp measurement id (MOLY Only)
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __INIT_TRC_ID_H
#define __INIT_TRC_ID_H

#ifdef __cplusplus
extern "C" {
#endif

//==============================================================================
// TimeStamp Measurement ID
//==============================================================================

typedef enum {
 
    /* init main flow */
     BOOT_INIT_TOTAL
    ,BOOT_INIT_READY_TO_DISPLAY
    ,BOOT_INIT_ASM
    ,BOOT_INIT_APPINIT
    ,BOOT_INIT_CLIB1
    ,BOOT_INIT_CCCI
    ,BOOT_INIT_CCCIHS1
    ,BOOT_INIT_MDCIHS1
    ,BOOT_INIT_BOOTMODE
    ,BOOT_INIT_SYSTEMINIT
    ,BOOT_INIT_NVRAM
    ,BOOT_INIT_HWDINIT
        /* HWDInitialization */
        ,BOOT_INIT_CHIPREG
        ,BOOT_INIT_BUS
        ,BOOT_INIT_USC
        ,BOOT_INIT_RM
        ,BOOT_INIT_OSTD    
        ,BOOT_INIT_L1SM
        ,BOOT_INIT_UL1SM
        ,BOOT_INIT_EL1SM
        ,BOOT_INIT_HWDIVIDER
        ,BOOT_INIT_IDMALOAD
        ,BOOT_INIT_NFIRESET
        ,BOOT_INIT_DRV1 
    
        /*  Drv_Init_Phase1 */
        ,BOOT_INIT_DRV1_PW
        ,BOOT_INIT_DRV1_TTY
        ,BOOT_INIT_DRV1_DRVHISR
        ,BOOT_INIT_DRV1_CCCI
        ,BOOT_INIT_DRV1_EMIMPU
        ,BOOT_INIT_DRV1_PWM
        ,BOOT_INIT_DRV1_CUSTOM
        ,BOOT_INIT_DRV1_GPT3
        ,BOOT_INIT_DRV1_GPTI
        ,BOOT_INIT_DRV1_WDT
        ,BOOT_INIT_DRV1_UART1
        ,BOOT_INIT_DRV1_UART2
        ,BOOT_INIT_DRV1_UART3
        
    ,BOOT_INIT_PREFOTA
    ,BOOT_INIT_THIRDROM
    ,BOOT_INIT_LOADSECMAUI
    ,BOOT_INIT_DEMP
    ,BOOT_INIT_DRV2
    
        /*  Drv_Init_Phase2 */
        ,BOOT_INIT_DRV2_SIM
        ,BOOT_INIT_DRV2_MSDC
        ,BOOT_INIT_DRV2_EINTSWDBNC
        ,BOOT_INIT_DRV2_CHE
        ,BOOT_INIT_DRV2_ADC
    ,BOOT_INIT_RESINIT
    ,BOOT_INIT_CHECKMSGID
    ,BOOT_INIT_CLIB2
    ,BOOT_INIT_MAINP
    ,BOOT_INIT_CCCIHS2
    ,BOOT_INIT_MDCIHS2
    ,BOOT_INIT_DMDSP2

    ,BOOT_NUM

    ,BOOT_END = (kal_uint8)255    // max 255 records     
    ,BOOT_NONE = BOOT_END


} BOOT;

#ifdef __cplusplus
}
#endif

#endif

