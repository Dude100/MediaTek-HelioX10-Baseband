/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *  custom_ups_config.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  This file is used to define the UPS configuration.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef CUSTOM_UPS_CONFIG_H
#define CUSTOM_UPS_CONFIG_H
/******************************************************************************/

/******************************************************************************/
//  Descirption:   Defines the prefix of MAC address used by host                                   
//  Restriction:    Three eight bits digits separated by commas
/******************************************************************************/

#define VENDOR_MAC_ADDRESS_PREFIX   0x02,0x00,0xFF

/******************************************************************************/
//  Descirption:    Defines the id of vendors (the same as usb id's)
//  Restriction:     A 16 bits integer
/******************************************************************************/

#define VENDOR_ID                   0x0000

/******************************************************************************/
//  Descirption:   Defines the string of vendor descrption 
//  Restriction:    String length must be under 64
/******************************************************************************/

#define VENDOR_DESCRIPTION          "N/A"

/******************************************************************************/
//  Descirption:    Defines the value of speed which shows in Windows Connection Status
//  Unit:             1/10 kbps
//  Range:          0~4294967295 ( 0x00000000 ~ 0xFFFFFFFF )
/******************************************************************************/

#if defined(__UMTS_FDD_MODE__)

#if defined(__HSDPA_SUPPORT__)
#define VENDOR_DEVICE_LINKSPEED     72000 // 7.2Mbps
#else
#define VENDOR_DEVICE_LINKSPEED      3840 // 384kbps
#endif

#elif defined(__UMTS_TDD128_MODE__)

#define VENDOR_DEVICE_LINKSPEED     26240 // 2.6Mbps

#elif defined(__EGPRS_MODE__)
#define VENDOR_DEVICE_LINKSPEED      4736 // 473.6kbps
#else
#define VENDOR_DEVICE_LINKSPEED       800 // 80kbps
#endif

/******************************************************************************/
#endif /* CUSTOM_UPS_CONFIG_H */

