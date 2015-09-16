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
 *   ltecsr_msgid.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   IMX and LTECSR SAP message definition
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/* LTECSR INTERFACE */

#include "module_msg_range.h"

#ifndef _LTECSR_MSG_H
#define _LTECSR_MSG_H

MODULE_MSG_BEGIN( MSG_ID_LTECSR_CODE_BEGIN )

/* FROM: IMC External */

	MSG_ID_LTECSR_MEDIA_NEW=MSG_ID_LTECSR_CODE_BEGIN,
	MSG_ID_LTECSR_MEDIA_DEL,
	MSG_ID_LTECSR_MEDIA_UPDATE,
	MSG_ID_LTECSR_MEDIA_ACTIVE,

	MSG_ID_LTECSR_DTMF_REQ, /* IN: cid, (sid), digit, in/out band, time:0-stop, non-zero: play, -1: periodically */

/* FROM: MOD_L1SP */

	MSG_ID_LTECSR_VOICE_UL_DATA_NOTIFY,
	MSG_ID_LTECSR_VOICE_UL_MUTE_NOTIFY,

/* LTECSR Internal */

	/* media */
	MSG_ID_LTECSR_MEDIA_START, /* IN: cid, sid OUT: result */
	MSG_ID_LTECSR_MEDIA_STOP, /* IN: cid, sid OUT: result */

	/* transmit mode */
	MSG_ID_LTECSR_MEDIA_XMIT_MODE_SET, /* IN: cid, sid, xmit_mode */
	MSG_ID_LTECSR_MEDIA_XMIT_MODE_GET, /* IN: cid, sid OUT: xmit_mode */

	/* dtmf */
	MSG_ID_LTECSR_DTMF_PLAY, /* IN: cid, (sid), digit, direction:0-local, 1-remote, duration:-1(infinite), 0(stop), others(ms) */
	MSG_ID_LTECSR_DTMF_STOP, /* IN: cid*/

	/* codec payload type */
	MSG_ID_LTECSR_MEDIA_PT_SET, /* IN: cid, sid, codec, pt */
	//MSG_ID_LTECSR_MEDIA_PT_GET, /* IN: cid, sid */

	/* rtcp */
	MSG_ID_LTECSR_RTCP_SEND_INTERVAL_SET, /* IN: cid, sid, rtcp send interval */
	//MSG_ID_LTECSR_RTCP_SEND_INTERVAL_GET, /* IN: cid, sid OUT: cid, sid */

MODULE_MSG_END( MSG_ID_LTECSR_CODE_TAIL )

#endif  /* _LTECSR_MSG_H */

