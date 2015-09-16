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
 * AT_CUSTOM_CMD.DEF
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for implementing custom commands for some customers
 *   which should not be released to other customers
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifdef __TC01__
CUSTOM_CMD("custom", 7435931, 13, "+CUSTOM: This is a sample", RMMI_CMD_ATCUSTOM, rmmi_custom_hdlr)

#if defined(__EXT_AMP_CONTROL__) && defined(__MTK_TARGET__)
CUSTOM_CMD("writewm", 48959585, 887, "", RMMI_CMD_WRITEWM, rmmi_writewm_hdlr)
CUSTOM_CMD("readwm", 37808427,13, "", RMMI_CMD_READWM, rmmi_readwm_hdlr)
#endif

CUSTOM_CMD("imei", 512819, 0, "%IMEI TEST MODE", RMMI_CMD_ATIMEI, rmmi_imei_hdlr)
CUSTOM_CMD("lgapp", 25407804, 0, "$LGAPP TEST MODE", RMMI_CMD_LGAPP, rmmi_lgapp_hdlr)
CUSTOM_CMD("acs", 1577, 0, "", RMMI_CMD_ACS, rmmi_acs_hdlr)
CUSTOM_CMD("issim", 19836583, 0, "ISSIM TEST MODE", RMMI_CMD_ISSIM, rmmi_issim_hdlr)
CUSTOM_CMD("simid", 40130550, 0, "SIMID TEST MODE", RMMI_CMD_SIMID, rmmi_simid_hdlr)
CUSTOM_CMD("inisim", 19548159, 13, "INISIM TEST MODE", RMMI_CMD_INISIM, rmmi_inisim_hdlr)
#ifdef __VSIM__
CUSTOM_CMD("simoff", 40130780, 6, "SIMOFF TEST MODE", RMMI_CMD_SIMOFF, rmmi_simoff_hdlr)
#endif
CUSTOM_CMD("campreq", 6329678, 207, "CAMPREQ TEST MODE", RMMI_CMD_CAMPREQ, rmmi_campreq_hdlr)
CUSTOM_CMD("camp", 166570, 0, "", RMMI_CMD_CAMP, rmmi_camp_hdlr)
CUSTOM_CMD("caldt", 6327780, 0, "CALDT TEST MODE", RMMI_CMD_CALDT, rmmi_caldt_hdlr)
CUSTOM_CMD("restart", 37835005, 704, "", RMMI_CMD_RESTART, rmmi_restart_hdlr)
CUSTOM_CMD("nosleep", 30042881, 206, "", RMMI_CMD_NOSLEEP, rmmi_nosleep_hdlr)
CUSTOM_CMD("batl", 111960, 0, "BATL TEST MODE", RMMI_CMD_BATL, rmmi_batl_hdlr) 
CUSTOM_CMD("calck", 6327733, 0, "CALCK TEST MODE", RMMI_CMD_CALCK, rmmi_calck_hdlr)
CUSTOM_CMD("fkpd", 345728, 0, "FKPD TEST MODE", RMMI_CMD_FKPD, rmmi_fkpd_hdlr)
CUSTOM_CMD("gkpd", 400600, 0, "GKPD TEST MODE", RMMI_CMD_GKPD, rmmi_gkpd_hdlr)
CUSTOM_CMD("boff", 131638, 0, "BOFF TEST MODE", RMMI_CMD_BOFF, rmmi_boff_hdlr)
CUSTOM_CMD("calm", 166529, 0, "CALM TEST MODE", RMMI_CMD_CALM, rmmi_calm_hdlr)
CUSTOM_CMD("vlc", 32227, 0, "VLCTEST MODE", RMMI_CMD_VLC, rmmi_vlc_hdlr)
CUSTOM_CMD("fo", 243, 0, "FO TEST MODE", RMMI_CMD_FO, rmmi_fo_hdlr)
CUSTOM_CMD("fc", 231, 0, "FC TEST MODE", RMMI_CMD_FC, rmmi_fc_hdlr)
CUSTOM_CMD("sync", 1079203, 0, "", RMMI_CMD_SYNC, rmmi_sync_hdlr)
CUSTOM_CMD("cgatt", 6641736, 0, "", RMMI_CMD_LGCGATT, rmmi_lgcgatt_hdlr)
CUSTOM_CMD("emt", 7734, 0, "", RMMI_CMD_EMT, rmmi_emt_hdlr)
CUSTOM_CMD("lcd", 17446, 0, "", RMMI_CMD_LCD, rmmi_lcd_hdlr)
CUSTOM_CMD("flight", 13182550, 20, "", RMMI_CMD_FLIGHT, rmmi_flight_hdlr)
#if defined(__MTK_TARGET__)  /* Only support ATS test on target , not support in simulator */
CUSTOM_CMD("mtc", 19535, 0, "", RMMI_CMD_MTC, rmmi_mtc_hdlr)
#endif
#if defined(__ACOUSTIC_LOOPBACK_SUPPORT__)
CUSTOM_CMD("acslb", 2277646, 0, "", RMMI_CMD_ACSLB, rmmi_acslb_hdlr)
#endif
CUSTOM_CMD("frst", 355966, 0, "", RMMI_CMD_FRST, rmmi_frst_hdlr)
CUSTOM_CMD("mot", 19362, 0, "", RMMI_CMD_MOT, rmmi_mot_hdlr)
CUSTOM_CMD("charge", 6696519, 5, "", RMMI_CMD_CHARGE, rmmi_charge_hdlr)
CUSTOM_CMD("chcomp", 6699299, 16, "", RMMI_CMD_CHCOMP, rmmi_chcomp_hdlr)
CUSTOM_CMD("utoa", 1181763, 0, "", RMMI_CMD_UTOA, rmmi_utoa_hdlr)
CUSTOM_CMD("bndi", 130121, 0, "", RMMI_CMD_BNDI, rmmi_bndi_hdlr)
#if !defined(EXTERNAL_MMI)/* for LG MTK MMI project ex:V32/V33 */
CUSTOM_CMD("fmr", 9176, 0, "", RMMI_CMD_LGFMR, rmmi_lgfmr_hdlr) /* function name conflict with AT+FMR */
CUSTOM_CMD("ecall", 10592208, 0, "", RMMI_CMD_ECALL, rmmi_ecall_hdlr)
CUSTOM_CMD("bttm", 139397, 0, "", RMMI_CMD_BTTM, rmmi_bttm_hdlr)
CUSTOM_CMD("spm", 28057, 0, "SPM TEST MODE", RMMI_CMD_SPM, rmmi_spm_hdlr) 
CUSTOM_CMD("mpt", 19400, 0, "MPT TEST MODE", RMMI_CMD_MPT, rmmi_mpt_hdlr)
CUSTOM_CMD("avr", 2298, 0, "AVR TEST MODE", RMMI_CMD_AVR, rmmi_avr_hdlr)
CUSTOM_CMD("cam", 4383, 0, "CAM TEST MODE", RMMI_CMD_CAM, rmmi_cam_hdlr)
#endif
#endif
