/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2007
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
 * Filename:
 * ---------
 *  gps_auth.c
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  GPS task
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
 *==============================================================================
 *******************************************************************************/
/***************************************************************************** 
 * Include
 *****************************************************************************/ 
#ifdef __GPS_SUPPORT__
#include "kal_general_types.h"
    
extern kal_uint8 gps_uart_port;
extern void gps_uart_enable_authentication(void);
extern kal_char* release_bb_chip(void);

/*****************************************************************************
 * FUNCTION
 *  gps_authentication_timeout_handler
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_authentication_timeout_handler(void)
{   
}
/*****************************************************************************
 * FUNCTION
 *  gps_send_check_id
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_send_check_id(void)
{  
}


/*****************************************************************************
 * FUNCTION
 *  gps_receive_check_id
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool gps_receive_check_id(kal_uint8 *buffer, kal_int32 length)
{    
    return KAL_TRUE;
}

/*****************************************************************************
 * FUNCTION
 *  gps_send_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_send_authentication(kal_uint8 year, kal_uint8 mon, kal_uint8 day, kal_uint8 hour, kal_uint8 min, kal_uint8 sec)
{    
}


/*****************************************************************************
 * FUNCTION
 *  gps_receive_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
kal_bool gps_receive_authentication(kal_uint8 *buffer, kal_int32 length)
{    
    return KAL_TRUE;
}


/*****************************************************************************
 * FUNCTION
 *  gps_gis_authentication
 * DESCRIPTION
 *  Message handler
 * PARAMETERS
 *  void
 * RETURNS
 *  void
 *****************************************************************************/
void gps_gis_authentication(kal_uint8 *plainText, kal_uint16 plainTextLen, kal_uint8 *encryptText, kal_uint16 encryptTextLen)
{        
}

#endif /* __GPS_SUPPORT__ */

