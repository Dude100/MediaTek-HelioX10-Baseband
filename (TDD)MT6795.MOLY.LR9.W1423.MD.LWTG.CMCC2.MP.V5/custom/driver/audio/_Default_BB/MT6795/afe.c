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
 * afe.c
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   Audio Front End
 *
 * Author:
 * -------
 * -------
 *
 *------------------------------------------------------------------------------
 * $Revision:   1.1  $
 * $Modtime:   May 16 2005 23:11:26  $
 * $Log:   //mtkvs01/vmdata/Maui_sw/archives/mcu/custom/audio/MT6229_EVB/afe.c-arc  $
 *
 * removed!
 * removed!
 * .
 * 
 * removed!
 * removed!
 * Prepare MT6583 customer folder
 * 
 * removed!
 * removed!
 * 6583 Customer folder preparation
 *
 * removed!
 * removed!
 * Add MT6577 settings.
 *
 * removed!
 * removed!
 * Back out changelist 519486
 *
 * removed!
 * removed!
 * .
 * 
 *******************************************************************************/

// #define  AFE_VAC_DCON1  (volatile unsigned short*)(0xA40F000CL)  /* AFE Voice Analog Circuit Control Register 1   */
// #define  AFE_VAC_CON0   (volatile unsigned short*)(0x840C0104L)  /* AFE Voice Analog-Circuit Control Register 0   */

/*****************************************************************************
* FUNCTION
*  AFE_Initialize
* DESCRIPTION
*   This function is to set the initial value of AFE HW.
*****************************************************************************/
void AFE_Initialize( void )
{
   /// AFE_VAC_CON0::VCALI is chip dependent, will be set in l1audio\afe2.c
   /// immediately after this function is called.
   /// set audio output == differential mode.
   //*AFE_VAC_CON0  = 0x00;
   //*AFE_VAC_DCON1 = 0x80;
}

/*****************************************************************************
* FUNCTION
*  AFE_SwitchExtAmplifier
* DESCRIPTION
*   This function is to turn on/off external amplifier.
*****************************************************************************/
void AFE_SwitchExtAmplifier( char sw_on )
{
   return;
}
