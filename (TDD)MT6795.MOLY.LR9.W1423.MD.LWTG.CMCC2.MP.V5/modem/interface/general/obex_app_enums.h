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
 * Filename:
 * ---------
 *   obex_app_enums.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Enum value between OBEX and APP.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#ifndef _OBEX_APP_ENUMS_H
#define _OBEX_APP_ENUMS_H

#define IRDA_MAX_USER_DATA 512 /* OBEX + TTP + LMP */
#define IRDA_MAX_DECLARED_OBEX_PKT_SIZE 32672 /* Follow PC device */
//#define IRDA_MAX_USER_DATA 128 /* OBEX + TTP + LMP */ /* 04.02.23 Change from 256 to 128 */

#define TTP_HEADER_SIZE 1
#define LMP_HEADER_SIZE 2
#define OBEX_MAX_PKT_SIZE IRDA_MAX_USER_DATA - TTP_HEADER_SIZE - LMP_HEADER_SIZE
#define OBEX_MAX_APP_DATA OBEX_MAX_PKT_SIZE - 6 /* 6 = OBEX PUT header(3) and BODY header(3) */

#define IRCOMM_MAX_PKT_SIZE IRDA_MAX_USER_DATA - TTP_HEADER_SIZE - LMP_HEADER_SIZE
#define IRCOMM_MAX_APP_DATA OBEX_MAX_PKT_SIZE - 1 /* 1 = IrCOMM control len field */

typedef enum
{
   OBEX_CLOSE,
   OBEX_CONNECTED,
   OBEX_OPEN
} obex_state_enum;

typedef enum
{
   OBEX_IAS_CLOSE,
   OBEX_IAS_WAITI,
   OBEX_IAS_OPEN
} obex_ias_state_enum;

typedef enum
{
   OBEX_ERR_LMP_FAILED,
   OBEX_ERR_IAS_FAILED,
   OBEX_ERR_TTP_FAILED,
   OBEX_ERR_OBEX_FAILED
} obex_err_cause_enum;

typedef enum
{    
    OBEX_APP_RES_CONTINUE_F=0x90, 
    OBEX_APP_RES_SUCCESS_F=0xA0,
    OBEX_APP_RES_FAILED_F=0xC4
} obex_app_rsp_code_enum;

typedef enum
{
   OBEX_FIRST_PKT,
	OBEX_NORMAL_PKT,
	OBEX_FINAL_PKT
} obex_pkt_type_enum;

typedef enum
{
   OBEX_TRANSMISSION_FINISHED,
   OBEX_USER_CANCELLED
} obex_disconnect_reason_enum;

#endif /* ~_OBEX_APP_ENUMS_H */


