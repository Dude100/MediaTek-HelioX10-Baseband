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
 *    icusb_iccd_adap.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file intends for host mass storage adaptaion layer definitaions (file system API)
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
 *============================================================================
 ****************************************************************************/
 
#ifndef USB_HOST_ICCD_ADAP_H
#define USB_HOST_ICCD_ADAP_H

typedef enum
{
	ICUSB_ICCD_P_ATR,
	ICUSB_ICCD_P_ATR_LENGTH,
	ICUSB_ICCD_P_DESCRIPTOR,
	ICUSB_ICCD_P_DELAY
}USB_HOST_ICCD_PARAMETER;

typedef struct{
	kal_uint8 *pATR;
	kal_uint32 atrLen;
}ICUSB_ICCD_INFO;


//SIM Drive : return Status
typedef enum
{
	DEVICE_Is_Always_Busy,
	DEVICE_Is_Ready,
	DEVICE_HW_FAIL,
	ATR_RESPONSE_FAIL,
	APDU_FAIL,
	APDU_SUCCESS
}USB_ICCD_STATE;


// SIM Drive => iccd_index is mapping to ICUSB HW
// only SIM Driver will user use these API  

extern USB_ICCD_STATE ICUSB_ICCD_POWER_ON(kal_uint8 iccd_index);
extern USB_ICCD_STATE ICUSB_ICCD_POWER_RESET(kal_uint8 iccd_index);
extern USB_ICCD_STATE ICUSB_ICCD_DATA_Transfer(kal_uint8 iccd_index,kal_uint16 tx_length,kal_uint8 *tx_buffer, kal_uint8 *rx_buffer, kal_uint16 *rx_size);

extern void ICUSB_ICCD_Parameter_Setting(kal_uint8 iccd_index,USB_HOST_ICCD_PARAMETER parameter, kal_uint16 data);
extern void ICUSB_ICCD_Parameter_Querry(kal_uint8 iccd_index, ICUSB_ICCD_INFO *pInfo);

extern void ICUSB_ICCD_Init(kal_uint8 iccd_index);
extern kal_bool IC_USB_POWER_ON(kal_uint8 iccd_index,kal_bool blocking);
extern kal_bool IC_USB_Reset_Card(kal_uint8 iccd_index);


#endif	/* USB_HOST_ICCD_ADAP_H */ 
 
