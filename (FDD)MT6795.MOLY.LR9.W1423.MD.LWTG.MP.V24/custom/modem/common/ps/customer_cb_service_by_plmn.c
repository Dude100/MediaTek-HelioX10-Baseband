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
/*
**   Includes
*/
#include "kal_general_types.h"

/* 
** For customer to define which PLMN has 3G CB service 
** 
*/
#define SMSAL_CB_SERVICE_PLMN_NUMBER  10

char* cb_service_plmn_table[SMSAL_CB_SERVICE_PLMN_NUMBER] = {

						{"fffff"},	
						{"fffff"},
						{"fffff"},
						{"fffff"},		
						{"fffff"},	
						{"fffff"},
						{"fffff"},
						{"fffff"},
						{"fffff"},	
						{"fffff"}
						
};


kal_uint8 smsal_cb_get_service_plmn_num (void);
void smsal_cb_get_service_plmn(kal_uint8 i, kal_uint8 * plmn);


/*****************************************************************************
* FUNCTION
*  smsal_cb_get_service_plmn_num
* DESCRIPTION
*   This function is used to get the number of PLMN table entries.
*
* PARAMETERS
*
* RETURNS
*  kal_uint8
* GLOBALS AFFECTED
*   None
*****************************************************************************/

kal_uint8 smsal_cb_get_service_plmn_num (void)
{
   return (SMSAL_CB_SERVICE_PLMN_NUMBER);
}


/*****************************************************************************
* FUNCTION
*  smsal_cb_get_service_plmn
* DESCRIPTION
*  This function gives the PLMN for the specified entry.
*
* PARAMETERS
*  IN	i : specified the i-th entry
*  OUT	plmn
*  
* RETURNS
*  void
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void smsal_cb_get_service_plmn(kal_uint8 i, kal_uint8 * plmn)
{
    plmn[0]='f';
	
	
	if( i >= SMSAL_CB_SERVICE_PLMN_NUMBER)
		return;
	
	if(strlen((char *)cb_service_plmn_table[i])>0)
	{
		strcpy((char *)plmn,(char *)cb_service_plmn_table[i]);
		
	}
	return;
}


