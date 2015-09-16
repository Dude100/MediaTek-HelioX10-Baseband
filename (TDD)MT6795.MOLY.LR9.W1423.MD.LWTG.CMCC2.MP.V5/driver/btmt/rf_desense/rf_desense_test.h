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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   rf_desense_test.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is for Engineer Mode RF desense test
 *
 * Author:
 * -------
 *   
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __rf_desense_test_h__
#define __rf_desense_test_h__

#if defined(__MTK_INTERNAL__)

#ifdef __RF_DESENSE_TEST__

enum RF_DESENSE_MODE {
    RF_DESENSE_MODE_BASE,
    RF_DESENSE_MODE_CAMERA_FH,
    RF_DESENSE_MODE_VBOOST_OFF,
    RF_DESENSE_MODE_FM_NO_ANIMATION,
    RF_DESENSE_MODE_MSDC_4MA,
    RF_DESENSE_MODE_MSDC_8MA,
    RF_DESENSE_MODE_NO_LCD_UPDATE,
    RF_DESENSE_MODE_NO_LCM_UPDATE,
    RF_DESENSE_MODE_FM_GSM_ON,
    RF_DESENSE_MODE_SERDES,
    RF_DESENSE_MODE_SSC1,
    RF_DESENSE_MODE_SSC2,
    RF_DESENSE_MODE_SSC3,
    RF_DESENSE_MODE_SSC4,
    RF_DESENSE_MODE_SSC5,
    RF_DESENSE_MODE_SSC6,
    RF_DESENSE_MODE_SSC7,
    RF_DESENSE_MODE_SSC8,
    RF_DESENSE_MODE_MIN_EMI_CURRENT,
    RF_DESENSE_MODE_MIN_EMI_CTRL_CURRENT,
    RF_DESENSE_MODE_26MHZ_BUFFER_OUTPUT_ALWAYS_ON,
    RF_DESENSE_MODE_CTP_NO_SWEEP,
    RF_DESENSE_MODE_MSDC_AUTO_RD_WR,
    RF_DESENSE_MODE_3D_ON
};
typedef enum RF_DESENSE_MODE RF_DESENSE_MODE;

extern void rf_desense_set_curr_mode(RF_DESENSE_MODE const mode);
extern RF_DESENSE_MODE rf_desense_get_curr_mode(void);

extern void rfdtPrintCheckLog(void);
extern void rfdFsAccessHandler(void);

#endif  // End of #ifdef __RF_DESENSE_TEST__

#endif  // End of #if defined(__MTK_INTERNAL__)

#endif  // End of #ifndef __rf_desense_test_h__
