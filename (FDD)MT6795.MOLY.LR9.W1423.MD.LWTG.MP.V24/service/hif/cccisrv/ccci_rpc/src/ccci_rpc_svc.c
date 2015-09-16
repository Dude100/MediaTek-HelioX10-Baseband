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
 *   ccci_rpc.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   This function implements file system adaptation layer with CCCI interfaces.
 *  
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI RPC] Add CCCI RPC general query function.
 *
 * 06 27 2013 ap.wang
 * removed!
 * [CCCI_RPC] Modify for sceurity RPC service
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "ccci_rpc_if.h"
#include "ccci_rpc_data.h"

/*******************************************************************************
 * Global parameters
 *******************************************************************************/

/*******************************************************************************
 * Define functions.
 *******************************************************************************/

/*************************************************************************
* FUNCTION
*  IPC_RPC_Secure_Algo
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : MDSC insert or remove message and change EINT poliaty
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_Secure_Algo (kal_uint8 Direction, kal_uint32 ContentAddr,
                               kal_uint32 ContentLen, kal_uint8 *CustomSeed,
                               kal_uint8 *ResText)
{
    kal_int32 ret;

    ret = 	IPC_RPC_Wrapper(IPC_RPC_CPSVC_SECURE_ALGO_OP,	sizeof(kal_uint8),	(void *)&Direction,
                            ContentLen,			(void *)ContentAddr,
                            sizeof(kal_uint32), (void *)&ContentLen,
                            sizeof(kal_uint32), (void *)CustomSeed, 	IPC_RPC_INPUT_TERM_PATTERN,
                            ContentLen, 		(void *)ResText, 		IPC_RPC_EOF_TERM_PATTERN);

    return ret;

}

/*************************************************************************
* FUNCTION
*  IPC_RPC_Get_Secure_RO
*
* DESCRIPTION
*  This function is to get Secure RO image from AP side
*
* PARAMETERS
*  ResText: buffer for decrypted SecureRO
*  ResLen: buffer length
* RETURNS
*  <0: AP doesn't support the feature
*  otherwise: the transferred bytes
*
*************************************************************************/
kal_int32 IPC_RPC_Get_Secure_RO(kal_uint8* ResText, kal_uint32 ResLen)
{
    kal_int32 ret;

    ret =  IPC_RPC_Wrapper(IPC_RPC_GET_SECURE_RO_OP,	sizeof(kal_int32),	(void *)&ResLen,	IPC_RPC_INPUT_TERM_PATTERN,
                           ResLen,				(void *)ResText,	IPC_RPC_EOF_TERM_PATTERN);


    return ret;
}

/*************************************************************************
* FUNCTION
*  IPC_RPC_EINT_GetNumber
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : MDSC insert or remove message and change EINT poliaty
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_EINT_GetNumber(kal_uint8 *EintName, kal_uint32 EintNameLength,
                                 kal_uint32 *EintNo)
{
    kal_int32 ret;

    ret = IPC_RPC_Wrapper(IPC_RPC_EINT_GETNUM_OP,		EintNameLength,		(void *)EintName,
                          sizeof(kal_uint32), (void *)&EintNameLength,	IPC_RPC_INPUT_TERM_PATTERN,
                          sizeof(kal_uint32), (void *)EintNo,				IPC_RPC_EOF_TERM_PATTERN);

    return ret;
}

/*************************************************************************
* FUNCTION
*  void IPC_RPC_GPIO_GetPin
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : query the GPIO pin
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_GPIO_GetPin(kal_uint8 *GPIOName, kal_uint32 GPIONameLength, kal_uint32 *GPIOPin)
{
    kal_int32 ret;

    ret =  IPC_RPC_Wrapper(IPC_RPC_GPIO_GETPIN_OP,		GPIONameLength,		(void *)GPIOName,
                           sizeof(kal_uint32), (void *)&GPIONameLength,	IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32), (void *)GPIOPin,			IPC_RPC_EOF_TERM_PATTERN);


    return ret;
}

/*************************************************************************
* FUNCTION
*  IPC_RPC_ADC_GetChannelNumber
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : query the ChannelNumber pin
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_ADC_GetChannelNumber(kal_uint8 *ChannelName, kal_uint32 ChannelNameLength, kal_uint32 *ChannelNumber)
{
    kal_int32 ret;

    ret =  IPC_RPC_Wrapper(IPC_RPC_ADC_GETNUM_OP,		ChannelNameLength,	(void *)ChannelName,
                           sizeof(kal_uint32), (void *)&ChannelNameLength, IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32), (void *)ChannelNumber,		IPC_RPC_EOF_TERM_PATTERN);


    return ret;
}


/*************************************************************************
* FUNCTION
*  IPC_RPC_Query_EMI
*
* DESCRIPTION
*  This function use to handle control channel messages from AP side
*  major information : query the EMI Type in AP side
*
* PARAMETERS
*  *
* RETURNS
*  NA
*
*************************************************************************/
kal_int32 IPC_RPC_Query_EMI(kal_uint32 *EMIType, kal_uint32 *ClockRate)
{
    kal_int32 ret;

    ret =  IPC_RPC_Wrapper(IPC_RPC_QUERY_EMI_OP,                            IPC_RPC_INPUT_TERM_PATTERN,
                           sizeof(kal_uint32), (void *)EMIType,
                           sizeof(kal_uint32), (void *)ClockRate,			IPC_RPC_EOF_TERM_PATTERN);

    return ret;
}


/*************************************************************************
* FUNCTION
*  IPC_RPC_EINT_GetAttribute
*
* DESCRIPTION
*  This function use to get eint attribute from AP side
*  major information : get attribute of EINT
*
* PARAMETERS
*  *
* RETURNS
*   >= 0 : Success
*	<  0 : error code
*
*************************************************************************/
#if defined(__SIM_HOT_SWAP_SUPPORT__)
kal_int32 IPC_RPC_EINT_GetAttribute (kal_uint8 *EintName, kal_uint32 EintNameLength, kal_uint32 queryType, void *result, kal_uint32 resultLength)
{
    kal_int32 ret;

    ret =  IPC_RPC_Wrapper(IPC_RPC_EINT_GETATTRIBUTE_OP,		EintNameLength		, (void *)EintName,
                           sizeof(kal_uint32)	, (void *)&EintNameLength,
                           sizeof(kal_uint32)	, (void *)&queryType,		IPC_RPC_INPUT_TERM_PATTERN,
                           resultLength		, (void *)result,			IPC_RPC_EOF_TERM_PATTERN);


    return ret;
}
#endif

/*************************************************************************
* FUNCTION
*  IPC_RPC_General_Query
*
* DESCRIPTION
*  This function use to get informations from AP side
*  major information : query infomations from AP sode
*
* PARAMETERS
*  OPID: operation ID (defined in ccci_rpc_if.h)
*  queryType: query specified type (bitmap or integer)
*  input: input parameter (any type)
*  inputLength: input parameter length
*  result: result return from AP
*  resultLength: result length
* RETURNS
*   >= 0 : Success
*	<  0 : error code
*
*************************************************************************/
kal_int32 IPC_RPC_General_Query (kal_uint32 OPID, void *input, kal_uint32 inputLength,void *result, kal_uint32 resultLength)
{
	kal_int32 ret;

	ret =  IPC_RPC_Wrapper(OPID,  inputLength			, (void *)input,		IPC_RPC_INPUT_TERM_PATTERN,
						          resultLength			, (void *)result,		IPC_RPC_EOF_TERM_PATTERN);

	return ret;
}


