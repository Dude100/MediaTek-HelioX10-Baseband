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
/*******************************************************************************
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   fta_gemini.h
 *
 * Project:
 * --------
 *   MAUI dual sim
 *
 * Description:
 * ------------
 *   FTA gemini stuff
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 

#ifndef FTA_GEMINI_H
#define FTA_GEMINI_H


#ifdef TL1_TESTCASE
#include "rtb_tl1.h"
/*
typedef struct _cphy_gemini_set_TL1_SUSPEND_REQ
{
    LOCAL_PARA_HDR
}rsvas_tl1_suspend_req_struct;

typedef struct _cphy_gemini_TL1_SUSPEND_CNF
{
    LOCAL_PARA_HDR
}rsvas_tl1_suspend_cnf_struct;

typedef struct _cphy_gemini_set_TL1_RESUME_REQ
{
    LOCAL_PARA_HDR
}rsvas_tl1_resume_req_struct;
*/

#define FTA_GEMINI_1_0_CHANNEL_NUMBER       10

typedef enum _Fta_gemini_tl1_sim1_set
{
    DUALSIM1_MODE_NULL =0,    
	DUALSIM1_TACTIVE_GSTANDBY_WITH_SYNC ,
	DUALSIM1_TACTIVE_GSTANDBY_WITHOUT_SYNC ,
	DUALSIM1_TSTANDBY_GACTIVE_WITH_SYNC,
	DUALSIM1_TSTANDBY_GACTIVE_WITHOUT_SYNC,
	DUALSIM1_TSINGLE_MODE,
    DUALSIM1_TFLIGHT_MODE,	
    DUALSIM1_SET_SUSPEND,
    DUALSIM1_SET_RESUME,
	DUALSIM1_PRIORITY_LOW ,
	DUALSIM1_PRIORITY_HIGH,
	DUALSIM1_PRIORITY_SAME,    //no use
	FTA_RTB_RESOURCE_SET
}__Fta_gemini_tl1_sim1_set;
typedef kal_uint8 Fta_gemini_tl1_sim1_set;

 typedef enum _gemini2_fta_rtb_resource_type_E
{
	GEMINI2_FTA_RTB_R_UNSET = 0x54,  
	GEMINI2_FTA_RTB_R_BAN ,  //DO NOT GIVE SOURCE
	GEMINI2_FTA_RTB_R_GIVE,      //GIVE
	GEMINI2_FTA_RTB_R_CIRCULE           //GIVE->NO->G
	
}__gemini2_fta_rtb_resource_type_E;
 typedef kal_uint8 gemini2_fta_rtb_resource_type_E;

typedef enum _Fta_gemini_tl1_sim1_status
{
    DUALSIM1_STATUS_NULL =0, 
	DUALSIM1_SUSPEND_STANDBY_FLLIGHT,       //3G no active,enters suspend/standby/flight state
	DUALSIM1_IDLE_MODE,     //3G active, enters other state except FACH and DCH
	DUALSIM1_CONNECT_MODE,  //3G active,enters FACH/DCH state
}__Fta_gemini_tl1_sim1_status;
typedef kal_uint8 Fta_gemini_sim1_status;

typedef enum _Fta_gemini_message_index
{
    DUALSIM1_TD_NULL =0,     
	DUALSIM1_TD_TIME_SYNC_MESSAGE_NORMAL,
	DUALSIM1_TD_TIME_SYNC_ADJUST_MESSAGE,
	DUALSIM1_TD_RTB_CONFLICT_MESSAGE_PRIORITY_LOW,	
	DUALSIM1_TD_RTB_CONFLICT_MESSAGE_PRIORITY_HIGH,	
    DUALSIM1_TD_RTB_STATUS_CHANGE_SIM1_IDLE_MODE,
    DUALSIM1_TD_RTB_STATUS_CHANGE_SIM1_CONNECT_MODE,
	DUALSIM1_TD_RTB_STATUS_CHANGE_SIM1_SUSPEND_STANDBY_FLIGHT,
}__Fta_gemini_message_index;
typedef kal_uint8 Fta_gemini_message_index ;

typedef struct _cphy_gemini_set_req_struct
{
    LOCAL_PARA_HDR
    Fta_gemini_tl1_sim1_set   gemini_set;
    kal_uint8            gemini_reserve;            //for 4 byte aline   
    kal_uint8            gemini_reserve1;            //for 4 byte aline   
    kal_uint8            gemini_reserve2;            //for 4 byte aline   
}cphy_gemini_set_req_struct;


typedef struct _cphy_gemini_report_message_struct
{
    LOCAL_PARA_HDR        
    Fta_gemini_message_index   gemini_index;            //for 4 byte aline   
    Fta_gemini_sim1_status     gemini_status;            //for 4 byte aline   
    TL1_Task_E                gemini_channel;            //for 4 byte aline   
    kal_uint8                  gemini_reserve4;            //for 4 byte aline   
}cphy_gemini_report_message_struct;//cphy_gemini_wait_message_type;                    


typedef struct _FTA_Gemini_sim1_info_struct
{
    Fta_gemini_sim1_status    fta_gemini_sim1_status;
    Fta_gemini_sim1_status    fta_gemini_sim1_status_pre;
    Fta_gemini_tl1_sim1_set   fta_gemini_set_current;
    Fta_gemini_message_index  fta_gemini_sim1_index;            //for 4 byte aline   
    kal_uint8            fta_gemini_reserve4;            //for 4 byte aline   
}FTA_Gemini_sim1_info_struct;


typedef struct _FTA_Gemini_channel_source_struct
{
    TL1_Task_E	    channel_type;
    kal_bool        channel_register_status;    //TRUE :  START  False stop
    kal_uint16	    current_fn;
    kal_uint16      fn_delay;
    kal_uint16	    echip_delay;
    kal_int16	        priority_index;    
}FTA_Gemini_channel_source_struct;

typedef struct _FTA_Gemini_channel_status_struct
{
    kal_bool    sim1_to_sim2_priority;          //TRUE high  FALSE low
    FTA_Gemini_channel_source_struct FTA_Gemini_channel_source_info[FTA_GEMINI_1_0_CHANNEL_NUMBER+1];
                                                                 //note: add 1 for measurement only  last channel      
}FTA_Gemini_channel_status_struct;
#endif

#ifdef __cplusplus
extern "C" {
#endif
void FTA_GEMINI_L1R_Active3G(kal_bool	active3G, kal_bool	ConnectMode);
void FTA_GEMINI_L1R_Start3GChannel(TL1_Task_E 	channel_type,kal_uint16	current_fn,kal_uint16 fn_delay,\
kal_uint16	echip_delay,kal_uint16 priority_index);
void FTA_GEMINI_L1R_Stop3GChannel(TL1_Task_E 	channel_type);
kal_bool FTA_GEMINI_L1R_Check3GResource(TL1_Task_E channel_type,kal_uint32 length_echip,TL1_Conflict_E *conflictReport,kal_uint16 *priority_index);
kal_int16 FTA_GEMINI_L1R_Start3GMeasurement(kal_uint16 start_sub_sfn,kal_uint16 start_echip,kal_uint32 length_echip);
void FTA_GEMINI_L1R_3GMeasurementDone( void);
void FTA_GEMINI_L1R_SyncTime_3G(kal_uint16	sync_sub_sfn,kal_uint32	sync_echip);
void FTA_GEMINI_L1R_AdjustTime_3G(kal_int16	fn_offset,kal_int32	echip_offset);
kal_bool FTA_GEMINI_set_deal(msg_type msg_id,local_para_struct* local_para_ptr);

void FTA_GEMINI_L1R_3GProtectChannel(void);
void FTA_GEMINI_L1R_3GCancelProtection(void);
void FTA_GEMINI_L1R_3GCancelReservation(void);
void FTA_GEMINI_L1R_3GEnterVirtualMode(kal_bool isVirtual);
kal_bool FTA_GEMINI_L1R_3GStartVirtualMeas(kal_uint16 start_sub_sfn, kal_uint16 start_echip, kal_uint32 length_echip);


    
#ifdef __cplusplus
}
#endif



#endif

