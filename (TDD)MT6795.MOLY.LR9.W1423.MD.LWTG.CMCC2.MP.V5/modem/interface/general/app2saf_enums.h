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
 * app2saf_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file contains the Enum for interface of APP and SAF.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 * 				HISTORY
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
 *==============================================================================
 *******************************************************************************/

#ifndef _APP2SAF_ENUMS_H
#define _APP2SAF_ENUMS_H

/* Used to specify the NAT type */
typedef enum
{
   SAF_OPEN_IP = 0,              /* Open Internet */
   SAF_UDP_BLOCKED,	             /* UDP Blocked */
   SAF_FULL_CONE_NAT,		     /* Full cone */
   SAF_RESTRICTED_CONE_NAT,		 /* Restricted cone */
   SAF_PORT_RESTRICTED_CONE_NAT, /* Port restricted cone */
   SAF_SYM_NAT,                  /* Symmetric NAT */
   SAF_SYM_FIREWALL        	     /* Symmetric Firewall*/
} saf_nat_type_enum;

/* Used to specify the result code of SAF operation */
typedef enum
{
   SAF_OK=0,                        /* Operation Success */		
   SAF_NO_SERVER_ADDR,              /* Server Address Error */
   SAF_REQUEST_TIMEOUT,             /* Request Timeout */
   SAF_NO_PENDING_OP,               /* No Pending Operation */
   SAF_HAS_PENDING_OP,              /* Has Pending Operation */
   SAF_SOCKET_ERROR,                /* Socket Error */
   SAF_DNS_ERROR,                   /* DNS Error */
   SAF_CHANNEL_NOT_EXIST,           /* Channel Not Exist */
   SAF_CHANNEL_EXIST,               /* Channel Already Exist */
   SAF_TOO_MANY_CHANNELS,           /* Reach Max Number of Channels */
   SAF_TOO_MANY_PENDING_OP,         /* Reach Max Number of Operations */
   SAF_RECV_BINDING_ERR_RSP,        /* Recieve Error Binding Resp */
   SAF_SOCKET_CANCEL_ACT_BEARER,    /* Socket Cancel Activating Bearer */
   SAF_UNSPECIFIED_ERROR		    /* General Error */
} saf_result_enum;

#endif /* _APP2SAF_ENUMS_H */ 

