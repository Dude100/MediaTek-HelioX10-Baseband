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
 *
 * Filename:
 * ---------
 * spc_io.h
 *
 * Project:
 * --------
 * MAUI
 *
 * Description:
 * ------------
 * IO interface between AP and MD speech driver, and AUDL basic function structure
 *
 * Author:
 * -------
 * 
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
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
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
 *==============================================================================
 *******************************************************************************/
#ifndef _SPC_IO_H_
#define _SPC_IO_H_

#include "audio_enum.h"

#if 0 // defined(MT6280) // for 75+80 integration
/* under construction !*/
#endif

typedef enum {
	
	SPCIO_MSG_FROM_SPC_SPH_ON_ACK = 0x20, 
	SPCIO_MSG_FROM_SPC_SPH_OFF_ACK, 
	SPCIO_MSG_FROM_SPC_SET_SPH_MODE_ACK,
	SPCIO_MSG_FROM_SPC_CTRL_SPH_ENH_ACK,
	SPCIO_MSG_FROM_SPC_CONFIG_SPH_ENH_ACK,
	SPCIO_MSG_FROM_SPC_SET_ACOUSTIC_LOOPBACK_ACK,
	SPCIO_MSG_FROM_SPC_QUERY_MD_CAPABILITY_ACK, 
	SPCIO_MSG_FROM_SPC_SET_MD_CAPABILITY_ACK, 
	SPCIO_MSG_FROM_SPC_PRINT_SPH_COEFF_ACK,
	SPCIO_MSG_FROM_SPC_SPH_ON_FOR_HOLD_CALL_ACK,
	SPCIO_MSG_FROM_SPC_SPH_ON_FOR_DACA_ACK,
	SPCIO_MSG_FROM_SPC_SPH_ROUTER_ON_ACK,

	SPCIO_MSG_FROM_SPC_PNW_ON_ACK = 0x30,
	SPCIO_MSG_FROM_SPC_PNW_OFF_ACK,
	SPCIO_MSG_FROM_SPC_RECORD_ON_ACK,
	SPCIO_MSG_FROM_SPC_RECORD_OFF_ACK,
	SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_ON_ACK,
	SPCIO_MSG_FROM_SPC_DMNR_RECPLAY_OFF_ACK,
	SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_ON_ACK,
	SPCIO_MSG_FROM_SPC_DMNR_REC_ONLY_OFF_ACK,
	SPCIO_MSG_FROM_SPC_PCM_REC_ON_ACK,
	SPCIO_MSG_FROM_SPC_PCM_REC_OFF_ACK,
	SPCIO_MSG_FROM_SPC_VM_REC_ON_ACK,
	SPCIO_MSG_FROM_SPC_VM_REC_OFF_ACK,
	SPCIO_MSG_FROM_SPC_RECORD_RAW_PCM_ON_ACK,
	SPCIO_MSG_FROM_SPC_RECORD_RAW_PCM_OFF_ACK,

	SPCIO_MSG_FROM_SPC_CTM_ON_ACK = 0x40,
	SPCIO_MSG_FROM_SPC_CTM_OFF_ACK,
	SPCIO_MSG_FROM_SPC_CTM_DUMP_DEBUG_FILE_ACK,
	SPCIO_MSG_FROM_SPC_BGSND_ON_ACK,
	SPCIO_MSG_FROM_SPC_BGSND_OFF_ACK,
	SPCIO_MSG_FROM_SPC_BGSND_CONFIG_ACK,

	SPCIO_MSG_FROM_SPC_PNW_DLDATA_REQUEST = 0x50,
	SPCIO_MSG_FROM_SPC_BGS_DATA_REQUEST,
	SPCIO_MSG_FROM_SPC_CTM_DATA_REQUEST,
	SPCIO_MSG_FROM_SPC_DACA_ULDATA_REQUEST,
	
	SPCIO_MSG_FROM_SPC_PNW_ULDATA_NOTIFY = 0x60,
	SPCIO_MSG_FROM_SPC_REC_DATA_NOTIFY,
	SPCIO_MSG_FROM_SPC_CTM_DEBUG_DATA_NOTIFY,
	SPCIO_MSG_FROM_SPC_PCM_REC_DATA_NOTIFY,
	SPCIO_MSG_FROM_SPC_VM_REC_DATA_NOTIFY,
	SPCIO_MSG_FROM_SPC_DACA_DLDATA_NOTIFY,
	SPCIO_MSG_FROM_SPC_RAW_PCM_REC_DATA_NOTIFY, //0x60 + 0x6

	SPCIO_MSG_FROM_SPC_EM_DATA_REQUEST = 0x70,
	SPCIO_MSG_FROM_SPC_EM_INCALL_ACK,
	SPCIO_MSG_FROM_SPC_EM_DMNR_ACK,
	SPCIO_MSG_FROM_SPC_EM_WB_ACK,  
	SPCIO_MSG_FROM_SPC_EM_MAGICON_ACK,  
	SPCIO_MSG_FROM_SPC_NETWORK_STATUS_NOTIFY,
	SPCIO_MSG_FROM_SPC_RF_INFO_NOTIFY,
	SPCIO_MSG_FROM_SPC_EM_HAC_ACK,  
	
	SPCIO_MSG_FROM_SPC_VIBSPK_PARAMETER_ACK = 0x80,
	SPCIO_MSG_FROM_SPC_NXP_SMARTPA_PARAMETER_ACK,
}SPCIO_MSG_FROM_SPC;

// ----------------------------------------------------------------------------
// Macro function
// ----------------------------------------------------------------------------

// extend version
#define SPCIO_CCCI_MSG_CMD(msg) ((msg) >> 16)
#define SPCIO_CCCI_MSG_DATA16(msg) ((msg) & 0xffffU)
#define SPCIO_CCCI_MSG_CONSTRCUT_CMD(msg, data16) ( ((msg)<<16) | (0xffffU&(data16)) )
#define SPCIO_CCCI_MSG_CONSTRCUT_DATA_CMD(msg, leng) SPCIO_CCCI_MSG_CONSTRCUT_CMD(msg, leng)
#define SPCIO_CCCI_MSG_CONSTRUCT_DATA_CMD_WO_SHIFT(typefuncData, length) ( ( (typefuncData)&0xFFFF0000U) | ((length)&0xffffU) )

// for mixing 
#ifdef SPC_MSG_ORG_VER
#define SPCIO_CCCI_MSG_IS_EXTEND(msg) (SPCIO_CCCI_MSG_IS_EXTEND_A2M(msg) || SPCIO_CCCI_MSG_IS_EXTEND_M2A(msg))
#define SPCIO_CCCI_MSG_IS_EXTEND_A2M(msg)	(((msg) >> 24) == MSG_A2M_EXTEND_BASE)
#define SPCIO_CCCI_MSG_IS_EXTEND_M2A(msg)	(((msg) >> 24) == MSG_M2A_EXTEND_BASE)

#define SPCIO_CCCI_MSG_CMD_IS_EXTEND_A2M(msg) (((msg)>>2) == MSG_A2M_EXTEND_BASE)
#define SPCIO_CCCI_MSG_CMD_IS_EXTEND_M2A(msg) (((msg)>>2) == MSG_M2A_EXTEND_BASE)

// origianl 
#define SPCIO_CCCI_MSG_ORG_TYPE(msg)  ((msg)>>28)

#define SPCIO_CCCI_MSG_ORG_FUNC1(msg)  (((msg) >> 24)& 0xfU) // for command 
#define SPCIO_CCCI_MSG_ORG_FUNC2(msg)  (((msg) >> 26)& 0x3U) // for data

#define SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC1(msg)  ((msg) >> 24) // for command 
#define SPCIO_CCCI_MSG_ORG_TYPE_AND_FUNC2(msg)  (((msg) >> 24)& 0xfcU) // for data

#define SPCIO_CCCI_MSG_ORG_PARAM1(msg) ((msg) & 0xffffffU)
#define SPCIO_CCCI_MSG_ORG_PARAM2_OFFSET(msg) (((msg) & 0x3ffffffU)>>13) // for data offset & length 
#define SPCIO_CCCI_MSG_ORG_PARAM2_LENGTH(msg) ((msg) & 0x1fffU)
#define SPCIO_CCCI_MSG_ORG_CONSTRCUT_CMD(typefuncCmd, param) ( (0xFF000000U&((typefuncCmd)<<24)) | (0xffffffU&(param)) )
#define SPCIO_CCCI_MSG_ORG_CONSTRUCT_DATA(typefunc2, offset, length) ( (( (typefunc2 << 24))&0xFC000000U) | ((offset)<<13) | ((length)&0x1fffU) )
#define SPCIO_CCCI_MSG_ORG_CONSTRUCT_DATA_WO_SHIFT(typefunc2, offset, length) ( ( (typefunc2)&0xFC000000U) | ((offset)<<13) | ((length)&0x1fffU) )
#endif //SPC_MSG_ORG_VER


// ----------------------------------------------------------------------------
// function for AUDL thread putting
// ----------------------------------------------------------------------------
/**
	@prSmpMsg:
	@comeFrom: 0 for trigger from CCCI_HISR, 1 for trigger from AUDL. (you can add more in the future
*/
void SpcIO_MsgQueuePut(SPC_MSG_ID_T msgId, uint32 msgData, uint32 msgDataRev, kal_uint8 callerFrom);
// ----------------------------------------------------------------------------
// function for msg send/receive
// ----------------------------------------------------------------------------
kal_uint16 SpcIo_GetDataFromAp(const kal_uint16 offset, const kal_uint16 length, void *buf);
void SpcIO_GetDataFromAp_inOneTime(kal_uint16 offset, kal_uint16 length, kal_int16 headerLen,
	void *header, void *buf);
bool SpcIO_WriteDataToAp(void *headerBuf, kal_int16 headerLen, 
	void *srcBuf1, kal_int16 srcLen1, void *srcBuf2, kal_int16 srcLen2, SPCIO_MSG_FROM_SPC spcIoMsg);
kal_bool SpcIO_SendMsgToAp(SPCIO_MSG_FROM_SPC spcIoMsg, uint32 data1, uint32 reserve);


#endif // _SPC_IO_H_

