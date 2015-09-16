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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   hmu.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This file implement the function of Host Interface Management Unit.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * 07 04 2014 ap.wang
 * removed!
 * .
 *
 * 07 04 2014 ap.wang
 * removed!
 * .
 *
 * 07 01 2014 ap.wang
 * removed!
 * .
 *
 * 06 10 2014 ap.wang
 * removed!
 * .
 *
 * 04 28 2014 ap.wang
 * removed!
 * HMU temp solution for K2 MD2
 *
 * 04 17 2014 box.wu
 * removed!
 * cldma timeout check
 *
 * 03 21 2014 ap.wang
 * removed!
 * Add ethercore DL retry
 *
 * 02 26 2014 ap.wang
 * removed!
 * 	Add L2trc_fill_4G_time to HMU GPT for L2 trace
 *
 * 11 07 2013 ap.wang
 * removed!
 * 	Fix Klocwork warning: succeeded might be used uninitialized in this function.
 *
 * 08 28 2013 ap.wang
 * removed!
 * 	[HMU] Add L2 trace for event trigger
 *
 * 08 27 2013 ap.wang
 * removed!
 * 	[HMU] Modify for multi dev type exception init
 *
 * 07 31 2013 ap.wang
 * removed!
 * .
 *
 * 07 31 2013 ap.wang
 * removed!
 * [HMU] Add trace log
 *
 * 03 11 2013 ap.wang
 * removed!
 * [HMU] Add copyright header and change ipc_reload condition
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "kal_public_defs.h"

#include "nvram_interface.h"
#include "nvram_data_items.h"
#include "hmu_conf_data.h"
#include "hmu.h"
#include "hmu_debug.h"

#if defined(__IPCORE_SUPPORT__) && !defined(IPCORE_NOT_PRESENT)
#include "ipc_api.h"
#endif

#include "dcl_gpt.h"

#if !defined(_MTK_TARGET_) && defined(_MSC_VER) && (_MSC_VER >= 1500)
#pragma warning( disable : 4100 )
#endif

static DCL_HANDLE hmu_gpt_handle = 0 ;

static kal_enhmutexid hmu_gpt_mutex = NULL ; 

static kal_bool hmu_gpt_enable = KAL_TRUE ; 

static kal_bool hmu_dsp_timer_exist = KAL_FALSE ; 


static hmu_internal_state_struct hmu_internal_state = {KAL_FALSE, KAL_FALSE, NULL}; 
extern hmu_tick_interval hmu_tick_interval_table[];

extern hmu_uldrv_except_initfunc uldrv_except_init_func_table[];
extern unsigned int uldrv_except_init_func_table_num;

#if defined(__CLDMACORE_SUPPORT__) || defined(__CCIFCORE_SUPPORT__)
kal_uint32 hmu_trigger_hif_pending_count = 0;
#endif

kal_uint32 hmu_tick = 0;

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_init
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_int32 hmu_hifeg_init(){
	if (hmu_internal_state.hmuHifEgId == NULL){
		hmu_internal_state.hmuHifEgId = kal_create_event_group(HIF_DRV_EG_NAME) ;
	}
	return HMU_OK ;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_set
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
#ifdef __CCMNI_IT__
void ccmni_it_reload_rgpds();
#endif 

#if defined(__ETHERCORE_SUPPORT__) && !defined(ETHERCORE_NOT_PRESENT)
void ethc_check_dl_handle_packet_retry(void);
#endif

kal_status hmu_hifeg_set(kal_uint32 events) {
    kal_int32 index = 0;
    hmu_tick_interval *hif;
    /*
     * Check if each uplink IP stream GPD is required to be relaoded or not. 
     * Note that, the uplink GPD realoding will be done in IPCORE context not here.
     */
    if ((HIF_DRV_EG_HIF_TICK_EVENT_GROUP & events)) {
#if defined(__IPCORE_SUPPORT__) && !defined(IPCORE_NOT_PRESENT)
        ipc_check_ul_reload_retry();
#endif
#if defined(__ETHERCORE_SUPPORT__) && !defined(ETHERCORE_NOT_PRESENT)
        ethc_check_dl_handle_packet_retry();
#endif
    }
#ifdef __CCMNI_IT__
    /* Use for CCMNI_IT rgpds reload, move from sdiocore to here*/
    ccmni_it_reload_rgpds();
#endif 
    /* Clear events if interval is not reached */
    for(index = 0; hmu_tick_interval_table[index].hif_event != 0; index++){
        hif = &(hmu_tick_interval_table[index]);
        if (hif->hif_current_tick > 0){
            events &= ~(hif->hif_event);
            hif->hif_current_tick--;
        }
        else{
            hif->hif_current_tick = hif->hif_event_tick_count;
        }   
    }

#if defined(__CLDMACORE_SUPPORT__) || defined(__CCIFCORE_SUPPORT__)
#define HIF_PENDING_LIMIT (5000)
	/* add hif pending count and this count should be reset  when hif polling task wakes up */ 
	if (hmu_trigger_hif_pending_count++ > HIF_PENDING_LIMIT) {
		/* assert if over pending limit */
		ASSERT(0);
	}
#endif

    hmu_data_trace(HMU_DATA_EVENT_TRIGGER, hmu_gpt_enable, events, hmu_tick++);
	return kal_set_eg_events(hmu_internal_state.hmuHifEgId, events, KAL_OR) ;
}

/*****************************************************************************
 * FUNCTION
 *  hmu_hifeg_wait
 * DESCRIPTION
 *  
 * PARAMETERS
 *  
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 hmu_hifeg_wait(kal_uint32 events) {
    kal_uint32  rt_event = 0;
	kal_retrieve_eg_events(hmu_internal_state.hmuHifEgId, events, KAL_OR_CONSUME, &rt_event, KAL_SUSPEND);
    return rt_event;
}

static void hmu_gpt_callback(void *data) // HISR level !!  
{
	SGPT_CTRL_START_T re_schedule;

	if (hmu_gpt_enable == KAL_TRUE && hmu_dsp_timer_exist == KAL_FALSE){
		re_schedule.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL ;
		re_schedule.pfCallback=hmu_gpt_callback;
		re_schedule.vPara=NULL;
        l2trc_fill_4G_time();
	    hmu_hifeg_set(HIF_DRV_EG_HIF_TICK_EVENT_GROUP); 

	    DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&re_schedule) ;
   	}
}

void hmu_stop_hif_sys_timer(){
	kal_take_enh_mutex(hmu_gpt_mutex);

	hmu_gpt_enable = KAL_FALSE ; 

	DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_STOP, (DCL_CTRL_DATA_T*)NULL) ;

	kal_give_enh_mutex(hmu_gpt_mutex);	
}

void hmu_start_hif_sys_timer(){
 	SGPT_CTRL_START_T start;

	kal_take_enh_mutex(hmu_gpt_mutex);

	hmu_gpt_enable = KAL_TRUE ; 
	
	start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=hmu_gpt_callback;
	start.vPara=NULL;

	DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;
	
	kal_give_enh_mutex(hmu_gpt_mutex);	
}

void hmu_dsp_timer_kick(){
	hmu_hifeg_set(HIF_DRV_EG_HIF_TICK_EVENT_GROUP);
}

static void hmu_init_hif_timer()
{
	SGPT_CTRL_START_T start;

	start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=hmu_gpt_callback;
	start.vPara=NULL;

    hmu_dsp_timer_exist = KAL_FALSE ;		
	hmu_gpt_enable = KAL_TRUE ; 	
    DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;

}

void hmu_switch_hif_timer(hmuTimerSource_enum source)
{
	SGPT_CTRL_START_T start;

     
	start.u2Tick=HMU_GPTIMER_PRIODIC_INTERVAL;
	start.pfCallback=hmu_gpt_callback;
	start.vPara=NULL;
	     
	kal_take_enh_mutex(hmu_gpt_mutex);
	if (source == HMU_TIMER_SOURCE_DSP){
		hmu_dsp_timer_exist = KAL_TRUE ;		
		//if (hmu_gpt_enable == KAL_TRUE){
			hmu_gpt_enable = KAL_FALSE ; 
			DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_STOP, (DCL_CTRL_DATA_T*)NULL) ;
		//}
		hmu_trace(HMU_TRACE, HMU_MOD, HMU_CHANGE_TIMER_DSP); 
	}else if(source == HMU_TIMER_SOURCE_SYS){		
		hmu_dsp_timer_exist = KAL_FALSE ;		
		//if (hmu_gpt_enable == KAL_FALSE){
			hmu_gpt_enable = KAL_TRUE ; 	
			DclSGPT_Control(hmu_gpt_handle, SGPT_CMD_START, (DCL_CTRL_DATA_T*)&start) ;
		//}
		hmu_trace(HMU_TRACE, HMU_MOD, HMU_CHANGE_TIMER_GPT); 
	}
	kal_give_enh_mutex(hmu_gpt_mutex);	

}

kal_int32 hmu_boot_init()
{
	if (hmu_internal_state.hmuBootInit == KAL_TRUE) {
		return HMU_ALREADY_INIT; 
	}

	hmu_hifeg_init() ;

	if (hmu_gpt_handle == 0) {
        hmu_gpt_handle = DclSGPT_Open(DCL_GPT_CB_MS, FLAGS_NONE);		
		if (hmu_gpt_handle == DCL_HANDLE_INVALID || hmu_gpt_handle == DCL_HANDLE_OCCUPIED){
			ASSERT(0);
		}
	}

	if (hmu_gpt_mutex == NULL) {
		hmu_gpt_mutex = kal_create_enh_mutex("hmu_timer_mutex");
		if (hmu_gpt_mutex == NULL) {
			ASSERT(0);
		}
	}	

    hmu_init_hif_timer() ;

 	hmu_internal_state.hmuBootInit = KAL_TRUE ;
	return 0 ;
}



/*****************************************************************************
 * FUNCTION
 *  hmu_except_init
 *
 * DESCRIPTION
 *  Trigger an upper layer device module to hook with TTYCORE and then proceed 
 *  exception flow if an exception happens before hmu_init() completes.
 *
 * PARAMETERS
 *  N/A
 *
 * RETURNS
 *  KAL_TRUE if caller is allowed to proceed the exception flow; 
 *  KAL_FALSE if there's no proper callback function registered by 
 *            upper layer device modules or something wrong while executing 
 *            the callback function.
 *****************************************************************************/
kal_bool hmu_except_init(void)
{
    kal_bool        succeeded = KAL_TRUE;
    kal_bool        ret;
    kal_uint32      idx;
	
    for (idx = 0; idx < uldrv_except_init_func_table_num; idx++) {
        ret = uldrv_except_init_func_table[idx].except_init_func(uldrv_except_init_func_table[idx].port_id, 0, NULL);
        if (ret != 0){
            succeeded = KAL_FALSE;
        }
    }	
    
    return succeeded;
}

/*****************************************************************************
 * FUNCTION
 *  hif_boot_init
 * DESCRIPTION
 *  HIF boot init function to initial HIF module without task.
 * PARAMETERS
 *  
 * RETURNS
 *  success or fail
 *****************************************************************************/
kal_int32 hif_boot_init()
{
    hmu_boot_init();
	return 0 ;
}
