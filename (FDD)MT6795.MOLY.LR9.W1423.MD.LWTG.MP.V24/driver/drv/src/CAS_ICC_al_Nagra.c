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
 *    CAS_ICC_al_Nagra.c 
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is to implement API for smart card CA solution of Nagra's SMD card.
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
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*****************************************************************************/
/* FICHIERS A INCLURE                                                        */
/*****************************************************************************/
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include  	"drv_comm.h"
#include 	"reg_base.h"
#include "dma_sw.h"
#include 	"intrCtrl.h"
#include    "sim_hw.h"
#include "sim_al.h"
#include "sim_sw_comm.h"
#include "cache_sw.h"
#include "init.h"

#include "..\..\vendor\cmmb\nagra\inc\ca_icc.h"
#include "..\..\media\common\include\med_trc.h"

/*****************************************************************************/
/* DECLARATION DES CONSTANTES LOCALES                                        */
/*****************************************************************************/

#define ICC_MAX_READER_NUMBER 2

#define ICC_MAX_SEND_TRY 3 // max number of send try in case of failure

#define MAX_READERNAME 52

#define READER_NAME "TFlash USB GSI (823533310050) 00 00"

/*****************************************************************************/
/* DECLARATION DES TYPES LOCAUX                                              */
/*****************************************************************************/
/*
typedef struct {
	char ident[MAX_READERNAME];
	bool lock;
	bool exclusivity;
	e_ReaderProtocol protocol;
	unsigned int rate;
} tReaderInfo;

typedef struct {
	int ReaderId;
	TIccEventNotification callback;
} tCardEventCallback;

*/

#define IMPLEMENTING_ASSERT	ASSERT(0)

typedef struct
{
	sim_HW_cb	*iccHwCb;
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
#endif
} TIccGlobals;


/*****************************************************************************/
/* DECLARATION DES FONCTIONS STATIQUES                                       */
/*****************************************************************************/
/*
TIccStatus IccSetReaders(int Nb, char* Ident, int Protocol, unsigned int Rate);
tCardEventCallback *CardEventCallbackCreate(int ReaderId, TIccEventNotification Callback);
void CardEventCallbackDestroy(tCardEventCallback *CardEventCallback);
void CardEvent(void *Event, void *Extra);
static TIccStatus GetReaderFromSessionId(TIccSessionId xSessionId,
										 TIccGlobals ** pIccReader);
static void SendNoAvailableSCNotif(void * CB);
*/
/*****************************************************************************/
/* DECLARATION DES VARIABLES STATIQUES                                       */
/*****************************************************************************/
//static tReaderInfo readers[ICC_MAX_READER_NUMBER];
static kal_bool readersInit = KAL_FALSE; //to make record whether DALICCInit is called or not, to make usre it is called onece
static int gReaderNb=0;
static TIccGlobals gIcc[ICC_MAX_READER_NUMBER];
static kal_bool gIccRegistered = KAL_FALSE;
kal_semid casIccArb;

TIccEventNotification   gIccEventNotificationCB;

extern sim_HW_cb	simHWCbArray[];

/*****************************************************************************/
/* CORPS DES FONCTIONS                                                       */
/*****************************************************************************/


TIccStatus DalIccInit()
{
	if (KAL_TRUE == readersInit){
		dbg_print("ERROR: already initialized!!");
		return ICC_ERROR;	
	}



	casIccArb = kal_create_sem("cas icc", 1);
	
	/*need to get HW information about which card slot is for SMD*/
	
	readersInit = KAL_TRUE;
}


// this function is meant to be called only once !!!!!!!
TIccStatus iccRegister(TIccEventNotification   xIccEventNotification,
					   TIccRegistrationId*     pxRegistrationId){
	TIccStatus Status=ICC_ERROR;
	//linrdStatus LrdStatus ;
	//tEventListener *Listener = NULL;
	//int loop;
	kal_bool IccFound = KAL_FALSE;
	sim_power_enum resultVoltage;
	sim_HW_cb	*hw_cb;
	usim_status_enum resetStatus = USIM_NO_INSERT;


	if (pxRegistrationId==NULL || xIccEventNotification==NULL)
		goto End;

	kal_take_sem(casIccArb, 1);
	if (KAL_TRUE == gIccRegistered) {
		dbg_print("ERROR:  an application is already registered");
		Status=ICC_ERROR;
		kal_give_sem(casIccArb);
		goto End;
	}
	if (KAL_FALSE == readersInit){
		dbg_print("ERROR: ICC initialized");
		Status=ICC_ERROR;
		kal_give_sem(casIccArb);
		goto End;
	}

	// limitation: only one appli registered at once !!!
	*pxRegistrationId=1;
	if(NULL != gIccEventNotificationCB)
		ASSERT(0);
	gIccEventNotificationCB=xIccEventNotification;
	gIccRegistered = KAL_TRUE;
	kal_give_sem(casIccArb);
	hw_cb = &simHWCbArray[get_CAS_icc_logicalNum()];
	gIcc[0].iccHwCb = hw_cb;
	/*get car's existence, if it exists, calls callback*/
	resetStatus = L1sim_Reset_All(UNKNOWN_POWER_CLASS, &resultVoltage, KAL_FALSE, SIM_ICC_APPLICATION_CMMB_SMD);
	if(USIM_NO_ERROR == resetStatus)
		xIccEventNotification(ICC_EVENT_CARD_INSERTED_SINGLE_CLIENT_SUPPORT, (kal_uint32)hw_cb, NULL, 0);
	else
		xIccEventNotification(ICC_EVENT_NO_AVAILABLE_CARD, ICC_SESSION_ID_NONE, NULL, 0);

	Status=ICC_NO_ERROR;


 End:
    kal_trace(TRACE_FUNC, CMMB_CA_NAGRA_ICC_REGISTER, Status, *pxRegistrationId, (resetStatus == USIM_NO_ERROR)? ICC_EVENT_CARD_INSERTED_SINGLE_CLIENT_SUPPORT : ICC_EVENT_NO_AVAILABLE_CARD);
	return Status;

}


TIccStatus iccCancelRegistration(TIccRegistrationId    xRegistrationId)
{
	
	TIccStatus Status=ICC_ERROR;
	int loop;
	//linrdStatus LrdStatus ;

	if(KAL_TRUE != gIccRegistered)
		ASSERT(0);

	kal_take_sem(casIccArb, 1);
	
	// limitation: only one appli registered at once !!!
	if (xRegistrationId==1) {
		gIccRegistered = KAL_FALSE;
		Status = ICC_NO_ERROR;
		gIccEventNotificationCB = NULL;
	}
	
	
	kal_give_sem(casIccArb);
	
    kal_trace(TRACE_FUNC, CMMB_CA_NAGRA_ICC_CANCEL_REGISTER, Status, xRegistrationId);

	return Status;
}


TIccStatus iccT0Exchange(
        TIccSessionId      xSessionId,
        kal_uint32              xCommandLen,
  const kal_uint8*    pxCommand,
        kal_uint32                xReceiveMaxLen,
        kal_uint32*              pxReceiveLen,
        kal_uint8*      pxReceiveBytes
)
{
	//linrdStatus LrdStatus;
	TIccStatus Status=ICC_ERROR;
	TIccGlobals * pIccReader;
	sim_HW_cb *hw_cb;
	sim_status SW;
	kal_uint8 cmd_case1[5];
	kal_uint8 *tx;


	if((TIccSessionId)gIcc[0].iccHwCb != xSessionId || SIM_HW_CB_HEAD != ((sim_HW_cb *)xSessionId)->head || SIM_HW_CB_TAIL != ((sim_HW_cb *)xSessionId)->tail)
		return ICC_ERROR_SESSION_ID;

  	hw_cb = (sim_HW_cb *)xSessionId;

	

	if (pxCommand==NULL || pxReceiveBytes==NULL || pxReceiveLen==NULL || 2 > xReceiveMaxLen || 4 > xCommandLen){
		Status=ICC_ERROR;
		goto End;
	}

	tx = (kal_uint8 *)pxCommand;

	*pxReceiveLen = xReceiveMaxLen-2; //thie value includes status word from upper layer, we have to decrease this.

	if(5 != xCommandLen && 0 != *pxReceiveLen)/*usim_case_4*/
	{
		/*in our driver, we will ignore tx last byte in usim_case4 processing, so we have to add 1 here*/
		xCommandLen ++;
	}
	else if(5 > xCommandLen && 0 == *pxReceiveLen)/*sim_case_1*/
	{
		/*
			tx length 4 and no rx, this is cmd case 1 in sim spec, but our driver expect the tx length should be 5
			so we have to workaround this part.
		*/
		if(4 != xCommandLen)
			ASSERT(0);

		kal_mem_cpy(cmd_case1, pxCommand, xCommandLen);
		cmd_case1[4] = 0;
		tx = cmd_case1;
		xCommandLen = 5;
	}
	if(0 == *pxReceiveLen){ /*in MTK's driver, we use rxPtr to tell whether it is case 3 or case 4, we should modify this argument*/
		SW = L1sim_Cmd_All(tx, &xCommandLen, NULL, pxReceiveLen, SIM_ICC_APPLICATION_CMMB_SMD);
	}
	else{
		SW = L1sim_Cmd_All(tx, &xCommandLen, pxReceiveBytes, pxReceiveLen, SIM_ICC_APPLICATION_CMMB_SMD);
	}

	*pxReceiveLen = (*pxReceiveLen) +2;
	if(0x0000 == SW)
		Status=ICC_ERROR_TIMEOUT;
	else{
		Status=ICC_NO_ERROR;
		pxReceiveBytes[(*pxReceiveLen)-2] = (SW >>8);
		pxReceiveBytes[(*pxReceiveLen)-1] = (SW & 0xff);
	}

 End:
    kal_trace(TRACE_FUNC, CMMB_CA_NAGRA_ICC_T0_EXCHANGE, Status, xSessionId, xCommandLen, tx, *pxReceiveLen);
	return Status;	
}




TIccStatus iccSmartcardReset( TIccSessionId xSessionId, TBoolean xColdReset)
{

	kal_bool coldReset;
	TIccStatus Status=ICC_ERROR;
	//linrdStatus LrdStatus ;
	TIccGlobals * pIccReader;
	sim_power_enum resultVoltage;
	sim_HW_cb *hw_cb;

	if((TIccSessionId)gIcc[0].iccHwCb != xSessionId)
		ASSERT(0);

  	hw_cb = (sim_HW_cb *)xSessionId;
	

	if(TRUE == xColdReset)
		coldReset = KAL_TRUE;
	else if(FALSE == xColdReset)
		coldReset = KAL_FALSE;
	else
		ASSERT(0);
	
	L1sim_Reset_All(UNKNOWN_POWER_CLASS, &resultVoltage, coldReset, SIM_ICC_APPLICATION_CMMB_SMD);

		Status=ICC_NO_ERROR;

 End:
    kal_trace(TRACE_FUNC, CMMB_CA_NAGRA_ICC_SMARTCARD_RESET, Status, xColdReset);
	return Status;
}


TIccStatus iccModeChange( TIccSessionId       xSessionId,
						  TIccAccessMode      xMode)
{
    kal_trace(TRACE_FUNC, CMMB_CA_NAGRA_ICC_MODE_CHANGE, xSessionId, xMode);
	if((TIccSessionId)gIcc[0].iccHwCb != xSessionId)
		return ICC_ERROR_SESSION_ID;
	IMPLEMENTING_ASSERT;
/*
	TIccStatus Status=ICC_ERROR;
	TIccGlobals * pIccReader;


	if ((Status=GetReaderFromSessionId(xSessionId,
									   &pIccReader)) 
		!= ICC_NO_ERROR){
		esyslog("ERROR iccSmartcardReset:  invalid sessionId !!!");
		goto End;
	}
	
	switch (xMode){
	case ICC_ACCESS_NONE:
		pIccReader->accessMode=xMode;
		Status= ICC_NO_ERROR;
		break;
	case ICC_ACCESS_EXCLUSIVE:
		pIccReader->accessMode=xMode;
		Status= ICC_NO_ERROR;
		break;
	default:
		Status= ICC_ERROR_MODE;
		break;
	}

 End:
	return Status;
*/
}

