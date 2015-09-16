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
 *   fota_gprot.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This is the header file of exproted functions for MMI
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

#ifndef __FOTA_H__
#define __FOTA_H__

/*******************************************
*   Include File      
********************************************/

#include "kal_general_types.h"
#include "fota_error.h"
#include "custom_img_config.h"
#include "ssf_interface.h"


/*******************************************
*   Structure and Macro Definition      
********************************************/
typedef enum {
  FOTA_UPDATE_SUCCEEDED,
  FOTA_UPDATE_FAILED,
  FOTA_UPDATE_NONE,
  FOTA_UPDATE_END
} FOTA_update_result; 

/*******************************************
*   Function and Variable Definition      
********************************************/

/* ---------------------------------------------------------------------------------
 * MAUI FOTA driver API
 --------------------------------------------------------------------------------- */

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Initialize
DESCRIPTION
   FOTA Initialization API
   1. Initialize data structure and progress initial step
   2. Register customized authentication function or encryption function
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_Initialize(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_WriteData
DESCRIPTION
   FOTA write data API
   1. This function is used to write data to spare image pool
   2. This API only allow sequentially writing mechanism
   3. Authentication mechanism is executed during writing
PARAMETER
   Length: the length of writing (Unit: Bytes)
   Buffer: the start address of buffer
RETURN
   0: means pass write success (ERROR_FOTA_SUCCESS)
   < 0: writing action is fail
      ERROR_FOTA_AUTH_ROMINFO: authentication fail, can't find rom info
      ERROR_FOTA_AUTH_FATBEGIN: authentication fail, fat begin address is different
      ERROR_FOTA_AUTH_FATLEN: authentication fail, fat length is different
      ERROR_FOTA_AUTH_HCHECKSUM: authentication fail, header checksum fail
      ERROR_FOTA_AUTH_ID: authentication fail, platform id is different
      ERROR_FOTA_AUTH_VERSION: authentication fail, downgrade is not allowed
      ERROR_FOTA_AUTH_IMAGELEN: authentication fail, image length too large
	 ERROR_FOTA_AUTH_FAIL: authentication fail before
	 ERROR_FOTA_OVERRANGE: write over the spare image pool range
	 ERROR_FOTA_NOT_INITIALIZED: not call FOTA_Initialize before
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_WriteData(kal_uint32 Length, void* Buffer);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ReadData
DESCRIPTION
   FOTA read data API
   1. This function is used to read data from spare image pool
   2. This API only support sequentially read operation, i.e. from low address to high address
PARAMETER
   Length: the length of writing (Unit: Bytes)
   Buffer: the start address of buffer
RETURN
   0: means pass write success (ERROR_FOTA_SUCCESS)
   < 0: writing action is fail
      ERROR_FOTA_AUTH_ROMINFO: authentication fail, can't find rom info
      ERROR_FOTA_AUTH_FATBEGIN: authentication fail, fat begin address is different
      ERROR_FOTA_AUTH_FATLEN: authentication fail, fat length is different
      ERROR_FOTA_AUTH_HCHECKSUM: authentication fail, header checksum fail
      ERROR_FOTA_AUTH_ID: authentication fail, platform id is different
      ERROR_FOTA_AUTH_VERSION: authentication fail, downgrade is not allowed
      ERROR_FOTA_AUTH_IMAGELEN: authentication fail, image length too large
	 ERROR_FOTA_AUTH_FAIL: authentication fail before
	 ERROR_FOTA_OVERRANGE: write over the spare image pool range
	 ERROR_FOTA_NOT_INITIALIZED: not call FOTA_Initialize before
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_ReadData(kal_uint32 Length, void* Buffer);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_DownloadedPackageSize
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_DownloadedPackageSize(kal_uint32 *curr_size);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ClearPackageReservoir
DESCRIPTION
   clear downloaded update package
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
        ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_ClearPackageReservoir(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_AvailablePackageSpace
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_AvailablePackageSpace(kal_uint32 *avail_size);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Get_TotalPackageSpace
DESCRIPTION
   return currently downloaded package size
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Get_TotalPackageSpace(kal_uint32 *avail_size);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_WriteUpdateRecord
DESCRIPTION
   FOTA update state information write API
   download client and update agent use this information to communicate with each other
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_WriteUpdateRecord(FOTA_Custom_Update_Info* record);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_ReadUpdateRecord
DESCRIPTION
   FOTA update state information read API
   download client and update agent use this information to communicate with each other
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_ReadUpdateRecord(FOTA_Custom_Update_Info* record);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Finalize
DESCRIPTION
   FOTA finalization API
   1. compare calculated checksum with image checksum in the header after 
       whole image is written 
   2. mark the status to UPDATE_NEEDED 
PARAMETER
   void
RETURN
   0: means pass error check step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_AUTH_FAIL: authentication fail, final step is not allowed
      ERROR_FOTA_IMAGE_CHECKSUM: image checksum error
--------------------------------------------------------------------------------- */
extern kal_int32 FOTA_Finalize(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_InitializeUpdateRecord
DESCRIPTION
   create an update record block or find out the existing update record block 
PARAMETER
   NULL
RETURN
   0: means pass initialization step (ERROR_FOTA_SUCCESS)
   < 0: means fail
      ERROR_FOTA_CUSTOMIZATION: wrong customization
--------------------------------------------------------------------------------- */
kal_int32 FOTA_InitializeUpdateRecord(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Inform_Update_State
DESCRIPTION
   Query the status of triggered update process
PARAMETER
   NONE
RETURN
   NULL
--------------------------------------------------------------------------------- */
FOTA_update_result FOTA_Inform_Update_State(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Start_Download_State
DESCRIPTION
   Download client use this function to query the result of update process
PARAMETER
   NULL
RETURN
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Start_Download_State(void);

/* ---------------------------------------------------------------------------------
FUNCTION
   FOTA_Start_Update_State
DESCRIPTION
   Download client use this function to query the result of update process
PARAMETER
   NULL
RETURN
--------------------------------------------------------------------------------- */
kal_int32 FOTA_Start_Update_State(void);

#endif //__FOTA_H__

