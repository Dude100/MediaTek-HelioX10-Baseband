/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 *   fota_error.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is the header of FOTA firmware update download module
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __FOTA_ERROR_H__
#define __FOTA_ERROR_H__




/*******************************************
*   Error Definition      
********************************************/
#define ERROR_FOTA_ECC_CORRECTED           ( 1)
#define ERROR_FOTA_SUCCESS                 ( 0)
#define ERROR_FOTA_OVERRANGE               (-1)
#define ERROR_FOTA_CUSTOMIZATION           (-2)
#define ERROR_FOTA_AUTH_ROMINFO            (-3)
#define ERROR_FOTA_AUTH_FATBEGIN           (-4)
#define ERROR_FOTA_AUTH_FATLEN             (-5)
#define ERROR_FOTA_AUTH_HCHECKSUM          (-6)
#define ERROR_FOTA_AUTH_ID                 (-7)
#define ERROR_FOTA_AUTH_VERSION            (-8)
#define ERROR_FOTA_AUTH_IMAGELEN           (-9)
#define ERROR_FOTA_AUTH_FAIL               (-10)
#define ERROR_FOTA_NOT_INITIALIZED         (-11)
#define ERROR_FOTA_IMAGE_CHECKSUM          (-12)
#define ERROR_FOTA_READ                    (-13)
#define ERROR_FOTA_PROGRAM                 (-14)
#define ERROR_FOTA_ERASE                   (-15)
#define ERROR_FOTA_BAD_BLOCK               (-16)
#define ERROR_FOTA_NFB_CHECKSUM            (-17)
#define ERROR_FOTA_NO_UPDATE_RECORD        (-18)
#define ERROR_FOTA_NO_UPDATE_BLOCK         (-19)
#define ERROR_FOTA_UPDATE_BLOCK_CORRUPT    (-20)
#define ERROR_FOTA_UPDATE_RECORD_CORRUPT   (-21)
#define ERROR_FOTA_NO_AVAILABLE_BLOCK      (-22)
#define ERROR_FOTA_TOO_MANY_UPDATE_BLOCK   (-23)
#define ERROR_FOTA_NOT_FINALIZED           (-24)
#define ERROR_FOTA_NO_UPDATE_PACKAGE       (-25)
#define ERROR_FOTA_UPDATE_PACKAGE_CORRUPT  (-26)
#define ERROR_FOTA_TOO_MANY_RECOVER_BLOCK  (-27)
#define ERROR_FOTA_TOO_MANY_PARTIAL_BLOCK  (-28)
#define ERROR_FOTA_FLASH_DEVICE            (-29)
#define ERROR_FOTA_UNSUPPORTED_CASES       (-30)
#define ERROR_FOTA_INVALID_PARAMETER       (-31)

/*******************************************
*   Status Definition      
********************************************/


#define STATUS_FOTA_INITIALIZED 0
#define STATUS_FOTA_AUTH_PASS 1
#define STATUS_FOTA_FINAL 2
#define STATUS_FOTA_AUTH_FAIL -1
#define STATUS_FOTA_NOT_INITIAL -2
#define STATUS_FOTA_OVERRANGE -3
#define UPDATE_SKIP 0xFFFFFFFF
#define UPDATE_NEED 0xFF00FF00
#define UPDATE_DONE 0x00000000

#endif //__FOTA_ERROR_H__
