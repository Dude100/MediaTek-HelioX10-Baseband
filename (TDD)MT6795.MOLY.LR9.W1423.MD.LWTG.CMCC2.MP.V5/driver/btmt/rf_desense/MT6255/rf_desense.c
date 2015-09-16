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
 *   rf_desense.c
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "drv_features.h"
#include "drv_comm.h"
#include "rf_desense_test.h"
#include "rf_desense.h"
#include "pll.h"
#include "kal_general_types.h"


#include "reg_base.h"
#include "emi_hw.h"
#include "msdc_def.h"

#include "dcl.h"
#if defined(__MTK_INTERNAL__)

#ifdef __RF_DESENSE_TEST__
#pragma arm section code= "PRIMARY_ROCODE" rodata = "PRIMARY_RODATA"

static DCL_HANDLE rf_desense_em_gpt_handle;
static SGPT_CTRL_START_T rf_desense_em_gpt_start;

#if defined(__TOUCH_PANEL_CAPACITY__)
extern void touch_panel_capacitive_power_on(kal_bool on);
#endif // #if defined(__TOUCH_PANEL_CAPACITY__)
extern void EMI_SetMinDrivingCurrent(void);
extern void RfDesenseFsAccessHandler(void);


//static void mmi_em_misc_rf_desense_mode_sample_func(void); //sample
static void mmi_em_misc_rf_desense_mode_base(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_BASE);
}
static void mmi_em_misc_rf_desense_mode_camera_fh(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_CAMERA_FH);
}
static void mmi_em_misc_rf_desense_mode_fm_no_animation(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_FM_NO_ANIMATION);
}
static void mmi_em_misc_rf_desense_mode_msdc_4ma(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_MSDC_4MA);
    kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC driving current 4MA] Pass!\n");
}
static void mmi_em_misc_rf_desense_mode_msdc_8ma(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_MSDC_8MA);
    kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC driving current 8MA] Pass!\n");
}
static void mmi_em_misc_rf_desense_mode_no_lcd_update_cb(void)
{
    rf_desense_set_curr_mode(RF_DESENSE_MODE_NO_LCD_UPDATE);
}
static void mmi_em_misc_rf_desense_mode_no_lcd_update(void) {
    #if 1 // delay 30s stop lcd   
    rf_desense_em_gpt_handle = DclSGPT_Open(DCL_GPT_CB, 0);    
    
    rf_desense_em_gpt_start.u2Tick = 3000; //30s
    rf_desense_em_gpt_start.pfCallback = mmi_em_misc_rf_desense_mode_no_lcd_update_cb;
    rf_desense_em_gpt_start.vPara = NULL;
    DclSGPT_Control(rf_desense_em_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rf_desense_em_gpt_start);     
    #else    
/* under construction !*/
    #endif
}
static void mmi_em_misc_rf_desense_mode_no_lcm_update_cb(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_NO_LCM_UPDATE);
}
static void mmi_em_misc_rf_desense_mode_no_lcm_update(void) {
    #if 1 // delay 30s stop lcm
    rf_desense_em_gpt_handle = DclSGPT_Open(DCL_GPT_CB, 0);    
    
    rf_desense_em_gpt_start.u2Tick = 3000; //30s
    rf_desense_em_gpt_start.pfCallback = mmi_em_misc_rf_desense_mode_no_lcm_update_cb;
    rf_desense_em_gpt_start.vPara = NULL;
    DclSGPT_Control(rf_desense_em_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&rf_desense_em_gpt_start);     
    #else      
/* under construction !*/
    #endif
}
static void mmi_em_misc_rf_desense_mode_min_emi_current(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_MIN_EMI_CURRENT);
    EMI_SetMinDrivingCurrent();
    kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum EMI driving current] Pass!\n");
}
static void mmi_em_misc_rf_desense_mode_fm_gsm_on(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_FM_GSM_ON);
}
static void mmi_em_misc_rf_desense_mode_ctp_no_sweep(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_CTP_NO_SWEEP);
    #if defined(__TOUCH_PANEL_CAPACITY__)
    touch_panel_capacitive_power_on(KAL_FALSE);
    #endif // #if defined(__TOUCH_PANEL_CAPACITY__)
}
static void mmi_em_misc_rf_desense_mode_msdc_auto_rd_wr(void) {
    rf_desense_set_curr_mode(RF_DESENSE_MODE_MSDC_AUTO_RD_WR);
    rfdFsAccessHandler();
}


static const rf_desense_info_struct g_em_misc_rf_desense_mode_list[] =
{
  /* mode,    mode name,                  mode function*/
  //{L"RF_DESENSE_MODE_BASE",   mmi_em_misc_rf_desense_mode_sample_func, (void*)0}, //sample
    {
        L"Base", 
        mmi_em_misc_rf_desense_mode_base,
        (void*)RF_DESENSE_MODE_BASE
    },
    {
        L"Camera FH", 
        mmi_em_misc_rf_desense_mode_camera_fh,
        (void*)RF_DESENSE_MODE_CAMERA_FH
    },
    {
        L"FM No Animation", 
        mmi_em_misc_rf_desense_mode_fm_no_animation, 
        (void*)RF_DESENSE_MODE_FM_NO_ANIMATION
    },
    {
        L"MSDC 4MA", 
        mmi_em_misc_rf_desense_mode_msdc_4ma,
        (void*)RF_DESENSE_MODE_MSDC_4MA
    },
    {
        L"MSDC 8MA", 
        mmi_em_misc_rf_desense_mode_msdc_8ma,
        (void*)RF_DESENSE_MODE_MSDC_8MA
    },
    {
        L"No LCD Update", 
        mmi_em_misc_rf_desense_mode_no_lcd_update,
        (void*)RF_DESENSE_MODE_NO_LCD_UPDATE
    },
    {
        L"No LCM Update", 
        mmi_em_misc_rf_desense_mode_no_lcm_update,
        (void*)RF_DESENSE_MODE_NO_LCM_UPDATE
    },
    {
        L"MIN EMI Current", 
        mmi_em_misc_rf_desense_mode_min_emi_current,
        (void*)RF_DESENSE_MODE_MIN_EMI_CURRENT
    },
    {
        L"FM GSM On", 
        mmi_em_misc_rf_desense_mode_fm_gsm_on,
        (void*)RF_DESENSE_MODE_FM_GSM_ON
    },  
    {
        L"CTP NO SWEEP", 
        mmi_em_misc_rf_desense_mode_ctp_no_sweep, 
        (void*)RF_DESENSE_MODE_CTP_NO_SWEEP
    },
    {
        L"MSDC AUTO RD and WR", 
        mmi_em_misc_rf_desense_mode_msdc_auto_rd_wr, 
        (void*)RF_DESENSE_MODE_MSDC_AUTO_RD_WR
    },       
    {
        L"RF_DESENSE_MODE_BASE",    
        NULL,
        0
    }
};

kal_uint16 rf_desense_get_total(void)
{
    return sizeof(g_em_misc_rf_desense_mode_list) / sizeof(rf_desense_info_struct);
}

rf_desense_info_struct *rf_desense_get_item(kal_uint32 index)
{
    return (rf_desense_info_struct*)(g_em_misc_rf_desense_mode_list + index);
}

#endif  // End of #ifdef __RF_DESENSE_TEST__
#endif  // End of #if defined(__MTK_INTERNAL__)
