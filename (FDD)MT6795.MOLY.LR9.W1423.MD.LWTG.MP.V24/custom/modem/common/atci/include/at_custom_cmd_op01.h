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
 * at_custom_cmd_op01.def
 *
 * Project:
 * --------
 *   MT6208
 *
 * Description:
 * ------------
 *   This file is intends for ....
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/

/* Please add EXTEND_CMD() in the following*/
#if defined(__OP01__) || defined(__SCPBR_SCPBW__SUPPORT__)
EXTEND_CMD("scpbr", 119040566, 0, "", RMMI_CMD_ATSCPBR, rmmi_cpbr_hdlr)
EXTEND_CMD("scpbw", 119040571, 0, "", RMMI_CMD_ATSCPBW, rmmi_cpbw_hdlr)
#endif
#ifdef __OP01__
EXTEND_CMD("dsci", 79482215, 0, "^DSCI: (0,1)", RMMI_CMD_ATDSCI, rmmi_dsci_hdlr)
EXTEND_CMD("mtv", 79254722, 0, "", RMMI_CMD_ATMTV, rmmi_mtv_hdlr)
EXTEND_CMD("sysinfo", 120252344, 243, "", RMMI_CMD_ATSYSINFO, rmmi_sysinfo_hdlr)
EXTEND_CMD("sysconfig", 120252117, 777221, "", RMMI_CMD_ATSYSCONFIG, rmmi_sysconfig_hdlr)
EXTEND_CMD("cardmode", 85571605, 21817, "^CARDMODE: (0,1)", RMMI_CMD_ATCARDMODE, rmmi_cardmode_hdlr)
EXTEND_CMD("rfsw", 80232273, 0, "", RMMI_CMD_ATRFSW, rmmi_rfsw_hdlr)
EXTEND_CMD("spn", 79263226, 0, "^SPN: (0,1)", RMMI_CMD_ATSPN, rmmi_spn_hdlr)
EXTEND_CMD("hver", 79706120, 0, "", RMMI_CMD_ATHVER, rmmi_hver_hdlr)
EXTEND_CMD("cmdver", 86210529, 18, "", RMMI_CMD_ATCMDVER, rmmi_cmdver_hdlr)
EXTEND_CMD("off", 21894, 0, "", RMMI_CMD_ATOFF, rmmi_off_hdlr)
#endif

/* Please add CMD_ENUM() in the following and do not wrap with compile option*/
CMD_ENUM(RMMI_CMD_ATSCPBR)
CMD_ENUM(RMMI_CMD_ATSCPBW)
CMD_ENUM(RMMI_CMD_ATDSCI)
CMD_ENUM(RMMI_CMD_ATMTV)
CMD_ENUM(RMMI_CMD_ATSYSINFO)
CMD_ENUM(RMMI_CMD_ATSYSCONFIG)
CMD_ENUM(RMMI_CMD_ATCARDMODE)
CMD_ENUM(RMMI_CMD_ATRFSW)
CMD_ENUM(RMMI_CMD_ATSPN)
CMD_ENUM(RMMI_CMD_ATHVER)
CMD_ENUM(RMMI_CMD_ATCMDVER)
CMD_ENUM(RMMI_CMD_ATOFF)

