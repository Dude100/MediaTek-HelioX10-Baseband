/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 * speech_dvt.c
 *
 * Project:
 * --------
 * MOLY
 *
 * Description:
 * ------------
 * Speech DVT codes
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#if defined(__ENABLE_SPEECH_DVT__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "string.h"
#include "l1audio_def.h"
#include "am.h"
#include "media.h"
#include "l1sp_trc.h"
#include "spc_io.h"
#include "spc_drv.h" // including "sp_drv.h" 
#include "pcm4way.h"

extern void Spc_AcousticLoopback(kal_uint8 uParam);
extern void spc_RecordStart(uint8 format, uint8 sampleRateIdx, uint8 channelNumIdx);
extern void spc_RecordStop(void);

// Bit 0 => 0: NB              1: WB
// Bit 1 => 0: Idle            1: Call
// Bit 2 => 0: P2W             1: P4W
// Bit 3 => 0: Enable PNW test 1: Disable PNW test
typedef enum {
    PNW_TEST_P2W_IDLE_NB = 0x0,
    PNW_TEST_P2W_IDLE_WB = 0x1,
    PNW_TEST_P2W_CALL_NB = 0x2,
    PNW_TEST_P2W_CALL_WB = 0x3,
    PNW_TEST_P4W_IDLE_NB = 0x4,
    PNW_TEST_P4W_IDLE_WB = 0x5,
    PNW_TEST_P4W_CALL_NB = 0x6,
    PNW_TEST_P4W_CALL_WB = 0x7,
    PNW_TEST_NONE        = 0x8
} PNW_TEST_TYPE;

#define IS_NB(a)        ((a & 0x1) == 0)
#define IS_WB(a)        ((a & 0x1) != 0)
#define IS_IDLE(a)      ((a & 0x2) == 0)
#define IS_CALL(a)      ((a & 0x2) != 0)
#define IS_P2W(a)       ((a & 0x4) == 0)
#define IS_P4W(a)       ((a & 0x4) != 0)
#define IS_ENABLE(a)    ((a & 0x8) == 0)
#define IS_DISABLE(a)   ((a & 0x8) != 0)

static kal_uint32 pnw_test_type = (kal_uint32)PNW_TEST_P2W_IDLE_NB;

// ----------------------------------------------------------------------------
// Loopback
// ----------------------------------------------------------------------------

#define PNW_TEST_FRM_BUF_CNT    32  // REMIND : must be pow of 2 
#define PNW_TEST_FRM_SIZE       320 // Unit : sample
#define PNW_TEST_DELAY          12  // Unit : 20ms 
#define MOD_BUF_CNT(a) (a & (PNW_TEST_FRM_BUF_CNT - 1))

#define P2W_UL_CONFIG (PNW_ENBLE + USE_D2M_PATH                + DATA_SELECT_AFTER_ENH + MCU_SET_P2W_ON)
#define P2W_DL_CONFIG (PNW_ENBLE + USE_M2D_PATH                                        + MCU_SET_P2W_ON)
#define P4W_UL_CONFIG (PNW_ENBLE + USE_D2M_PATH + USE_M2D_PATH + DATA_SELECT_AFTER_ENH + MCU_SET_P4W_ON)
#define P4W_DL_CONFIG (PNW_ENBLE + USE_D2M_PATH + USE_M2D_PATH                         + MCU_SET_P4W_ON)

static kal_uint16 PNW_Test_UL_Buf[PNW_TEST_FRM_BUF_CNT][PNW_TEST_FRM_SIZE];
static kal_uint16 PNW_Test_DL_Buf[PNW_TEST_FRM_BUF_CNT][PNW_TEST_FRM_SIZE];

typedef struct {
    kal_uint32 delay;
    kal_uint32 w_idx;
    kal_uint32 r_idx;
    kal_uint32 UL_w_idx;
    kal_uint32 UL_r_idx;
    kal_uint32 DL_w_idx;
    kal_uint32 DL_r_idx;
} PNW_TEST_STRUCT;

static PNW_TEST_STRUCT pnw_test_handle;

static void PNW_Test_UL_Hisr(void)
{
    kal_uint32 w_idx;
    kal_uint32 r_idx;
    
    // Get read / write index
    if (IS_P2W(pnw_test_type))
    {
        w_idx = pnw_test_handle.w_idx;
        r_idx = pnw_test_handle.r_idx;
    }
    else
    {
        w_idx = pnw_test_handle.UL_w_idx;
        r_idx = pnw_test_handle.UL_r_idx;
    }
    
    // Get from microphone
    if (w_idx - r_idx < PNW_TEST_FRM_BUF_CNT)
    {
        kal_uint16 *p_buf = (kal_uint16 *)PNW_Test_UL_Buf[MOD_BUF_CNT(w_idx)];
        
        if (IS_P2W(pnw_test_type))
        {
            PCM2WAY_GetFromMic(p_buf);
        }
        else
        {
            PCM4WAY_GetFromMic(p_buf);
        }
        
        kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_FROM_MIC, p_buf[0], p_buf[1], p_buf[2], p_buf[3]);
        
        w_idx++;
    }
    else
    {
        kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_SKIP_MIC);
    }
    
    // Put to speech encode, only for P4W
    if (IS_P4W(pnw_test_type))
    {
        if (w_idx - r_idx >= pnw_test_handle.delay)
        {
            kal_uint16 *p_buf = (kal_uint16 *)PNW_Test_UL_Buf[MOD_BUF_CNT(r_idx)];
            
            PCM4WAY_PutToSE(p_buf);
            
            kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_TO_SE, p_buf[0], p_buf[1], p_buf[2], p_buf[3]);
            
            r_idx++;
        }
        else
        {
            PCM4WAY_FillSE(0);
            kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_FILL_SE);
        }
    }
    
    // Update read / write index
    if (IS_P2W(pnw_test_type))
    {
        pnw_test_handle.w_idx = w_idx;
        pnw_test_handle.r_idx = r_idx;
    }
    else
    {
        pnw_test_handle.UL_w_idx = w_idx;
        pnw_test_handle.UL_r_idx = r_idx;
    }
    
    return;
}

static void PNW_Test_DL_Hisr(void)
{
	kal_uint32 w_idx;
    kal_uint32 r_idx;
    
    // Get read / write index
    if (IS_P2W(pnw_test_type))
    {
        w_idx = pnw_test_handle.w_idx;
        r_idx = pnw_test_handle.r_idx;
    }
    else
    {
        w_idx = pnw_test_handle.DL_w_idx;
        r_idx = pnw_test_handle.DL_r_idx;
    }
	
	// Get from speech decode, only for P4W
	if (IS_P4W(pnw_test_type))
    {
        if (w_idx - r_idx < PNW_TEST_FRM_BUF_CNT)
        {
            kal_uint16 *p_buf = (kal_uint16 *)PNW_Test_DL_Buf[MOD_BUF_CNT(w_idx)];
            
            PCM4WAY_GetFromSD(p_buf);
            
            kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_FROM_SD, p_buf[0], p_buf[1], p_buf[2], p_buf[3]);
            
            w_idx++;
        }
        else
        {
            kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_SKIP_SD); 
        }
    }
	
	// Put to speaker
	if (w_idx - r_idx >= pnw_test_handle.delay)
    {
        kal_uint16 *p_buf;
        
        if (IS_P2W(pnw_test_type))
        {
            p_buf = (kal_uint16 *)PNW_Test_UL_Buf[MOD_BUF_CNT(r_idx)];
            
            PCM2WAY_PutToSpk(p_buf);
        }
        else
        {
            p_buf = (kal_uint16 *)PNW_Test_DL_Buf[MOD_BUF_CNT(r_idx)];
            
            PCM4WAY_PutToSpk(p_buf);
        }
        
        kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_TO_SPK, p_buf[0], p_buf[1], p_buf[2], p_buf[3]);
        
        r_idx++;
    }
    else
    {
        kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_FILL_SPK);
        
        if (IS_P2W(pnw_test_type))
        {
            PCM2WAY_FillSpk(0);
        }
        else
        {
            PCM4WAY_FillSpk(0);
        }
    }
	
	// Update read / write index
    if (IS_P2W(pnw_test_type))
    {
        pnw_test_handle.w_idx = w_idx;
        pnw_test_handle.r_idx = r_idx;
    }
    else
    {
        pnw_test_handle.DL_w_idx = w_idx;
        pnw_test_handle.DL_r_idx = r_idx;
    }
	
    kal_dev_trace(TRACE_INFO, SPC_AC_LOOPBACK_UL_DL_INDEX, w_idx, r_idx, 0, 0);
    
    return;
}

// uParam bit 0 => 1: on, 0: off
void Spc_PCMNWay_DVT_Test(kal_uint8 uParam)
{
    if (IS_DISABLE(pnw_test_type))
    {
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]PNW test is disabled (test type = %x)", pnw_test_type);
        Spc_AcousticLoopback(uParam);
    }
    else if (uParam & 0x1)
    {
        // Setup
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]PNW start (test type = %x)", pnw_test_type);
        memset(&pnw_test_handle, 0, sizeof(PNW_TEST_STRUCT));
        memset(PNW_Test_UL_Buf,  0, sizeof(kal_uint16) * PNW_TEST_FRM_BUF_CNT * PNW_TEST_FRM_SIZE);
        memset(PNW_Test_DL_Buf,  0, sizeof(kal_uint16) * PNW_TEST_FRM_BUF_CNT * PNW_TEST_FRM_SIZE);
        pnw_test_handle.delay = PNW_TEST_DELAY;
        
        // Enable
        if (IS_CALL(pnw_test_type) && !AM_IsSpeechOn())
        {
            L1SP_Speech_On(RAT_2G_MODE);
            L1SP_SpeechLoopBackEnable(KAL_TRUE);
        }
        
        if (IS_P2W(pnw_test_type))
        {
            if (IS_NB(pnw_test_type))
            {
                PCM2Way_SetFormat(P2W_FORMAT_NORMAL);
            }
            else
            {
                PCM2Way_SetFormat(P2W_FORMAT_WB_NORMAL);
            }
        }
        
        switch(pnw_test_type)
        {
            case PNW_TEST_P2W_IDLE_NB:
            case PNW_TEST_P2W_IDLE_WB:
                Extended_PCM2WAY_Start(PNW_Test_DL_Hisr, PNW_Test_UL_Hisr, P2W_APP_TYPE_VOIP, P2W_UL_CONFIG, P2W_DL_CONFIG);
                break;
            case PNW_TEST_P2W_CALL_NB:
            case PNW_TEST_P2W_CALL_WB:
                Extended_PCM2WAY_Start(PNW_Test_DL_Hisr, PNW_Test_UL_Hisr, P2W_APP_TYPE_UNDER_CALL, P2W_UL_CONFIG, P2W_DL_CONFIG);
                break;
            case PNW_TEST_P4W_IDLE_NB:
                Extended_PCM4WAY_Start(PNW_Test_DL_Hisr, PNW_Test_UL_Hisr, P4W_APP_TYPE_WITHOUT_CALL, P4W_UL_CONFIG, P4W_DL_CONFIG);
                break;
            case PNW_TEST_P4W_IDLE_WB:
                Extended_PCM4WAY_Start(PNW_Test_DL_Hisr, PNW_Test_UL_Hisr, P4W_APP_TYPE_WITHOUT_CALL_WB, P4W_UL_CONFIG, P4W_DL_CONFIG);
                break;
            case PNW_TEST_P4W_CALL_NB:
            case PNW_TEST_P4W_CALL_WB:
                Extended_PCM4WAY_Start(PNW_Test_DL_Hisr, PNW_Test_UL_Hisr, P4W_APP_TYPE_UNDER_CALL, P4W_UL_CONFIG, P4W_DL_CONFIG);
                break;
            default:
                break;
        }
    }
    else
    {
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]PNW stop (test type = %x)", pnw_test_type);
        switch(pnw_test_type)
        {
            case PNW_TEST_P2W_IDLE_NB:
            case PNW_TEST_P2W_IDLE_WB:
                Extended_PCM2WAY_Stop(P2W_APP_TYPE_VOIP);
                break;
            case PNW_TEST_P2W_CALL_NB:
            case PNW_TEST_P2W_CALL_WB:
                Extended_PCM2WAY_Stop(P2W_APP_TYPE_UNDER_CALL);
                break;
            case PNW_TEST_P4W_IDLE_NB:
                Extended_PCM4WAY_Stop(P4W_APP_TYPE_WITHOUT_CALL);
                break;
            case PNW_TEST_P4W_IDLE_WB:
                Extended_PCM4WAY_Stop(P4W_APP_TYPE_WITHOUT_CALL_WB);
                break;
            case PNW_TEST_P4W_CALL_NB:
            case PNW_TEST_P4W_CALL_WB:
                Extended_PCM4WAY_Stop(P4W_APP_TYPE_UNDER_CALL);
                break;
            default:
                break;
        }
    }
	
	return; 
}

static kal_bool f_sph_DVT_pnw_via_rec_on = KAL_FALSE;

void Spc_PCMNWay_DVT_Test_by_Rec_Button(kal_uint8 uParam, uint8 format, uint8 sampling_rate_idx, uint8 ch_num_idx)
{
    if (f_sph_DVT_pnw_via_rec_on && IS_ENABLE(pnw_test_type) && IS_CALL(pnw_test_type))
    {
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]PNW Call via Rec %s", uParam & 0x1 ? "on" : "off");
        Spc_PCMNWay_DVT_Test(uParam);
    }
    else
    {
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]Back to Rec, is start %d, flag %d, is enable %d, is call", uParam & 0x1, f_sph_DVT_pnw_via_rec_on, IS_ENABLE(pnw_test_type), IS_CALL(pnw_test_type));
        if (uParam & 0x1)
        {
            spc_RecordStart(format, sampling_rate_idx, ch_num_idx);
        }
        else
        {
            spc_RecordStop();
        }
    }
    
    return;
}

static kal_bool f_sph_DVT_fwe_on = KAL_TRUE;

kal_bool Is_Sph_DVT_Enable_FWE(void)
{
    return f_sph_DVT_fwe_on;
}

typedef enum {
    BT_MODE_TEST_NONE = 0x0,
    BT_MODE_TEST_NB   = 0x1,
    BT_MODE_TEST_WB   = 0x2
} BT_MODE_TEST_TYPE;

static kal_uint32 sph_DVT_BT_mode = (kal_uint32)BT_MODE_TEST_NONE;

kal_bool Is_Sph_DVT_BT_Mode_NB(void)
{
    return (kal_bool)(sph_DVT_BT_mode == BT_MODE_TEST_NB);
}

kal_bool Is_Sph_DVT_BT_Mode_WB(void)
{
    return (kal_bool)(sph_DVT_BT_mode == BT_MODE_TEST_WB);
}

void Speech_DVT_Test_Main(kal_char *string)
{
    if (strcmp(string, "P2W_Idle_NB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P2W_IDLE_NB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P2W idle NB");
	}
	else if(strcmp(string, "P2W_Idle_WB")==0)
    {
        pnw_test_type = (kal_uint32)PNW_TEST_P2W_IDLE_WB;
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]P2W idle WB");
	}
	else if(strcmp(string, "P2W_Call_NB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P2W_CALL_NB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P2W call NB");
	}
	else if(strcmp(string, "P2W_Call_WB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P2W_CALL_WB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P2W call WB");
	}
	else if (strcmp(string, "P4W_Idle_NB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P4W_IDLE_NB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P4W idle NB");
	}
	else if(strcmp(string, "P4W_Idle_WB")==0)
    {
        pnw_test_type = (kal_uint32)PNW_TEST_P4W_IDLE_WB;
        kal_prompt_trace(MOD_L1SP, "[Speech DVT]P4W idle WB");
	}
	else if(strcmp(string, "P4W_Call_NB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P4W_CALL_NB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P4W call NB");
	}
	else if(strcmp(string, "P4W_Call_WB")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_P4W_CALL_WB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]P4W call WB");
	}
	else if(strcmp(string, "PNW_None")==0)
    {
		pnw_test_type = (kal_uint32)PNW_TEST_NONE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]PNW none");
	}
	else if(strcmp(string, "Enable_FWE")==0)
    {
		f_sph_DVT_fwe_on = KAL_TRUE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Enable FWE");
	}
	else if(strcmp(string, "Disable_FWE")==0)
    {
		f_sph_DVT_fwe_on = KAL_FALSE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Disable FWE");
	}
	else if(strcmp(string, "Enable_PNW_Call_Via_Rec")==0)
    {
		f_sph_DVT_pnw_via_rec_on = KAL_TRUE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Enable PNW via Rec");
	}
	else if(strcmp(string, "Disable_PNW_Call_Via_Rec")==0)
    {
		f_sph_DVT_pnw_via_rec_on = KAL_FALSE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Disable PNW via Rec");
	}
	else if(strcmp(string, "Enable_BT_Mode_NB")==0)
    {
		sph_DVT_BT_mode = (kal_uint32)BT_MODE_TEST_NB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Enable BT Mode NB");
	}
	else if(strcmp(string, "Enable_BT_Mode_WB")==0)
    {
		sph_DVT_BT_mode = (kal_uint32)BT_MODE_TEST_WB;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Enable BT Mode WB");
	}
	else if(strcmp(string, "Disable_BT_Mode")==0)
    {
		sph_DVT_BT_mode = (kal_uint32)BT_MODE_TEST_NONE;
		kal_prompt_trace(MOD_L1SP, "[Speech DVT]Disable BT Mode");
	}
    
	return;
}

#endif // defined(__ENABLE_SPEECH_DVT__)

