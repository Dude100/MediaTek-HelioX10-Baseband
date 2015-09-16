/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *   ccci_ipc_module_conf.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Header file of CCCI_IPC_MODULE.
 *
 * Author:
 * -------
 * -------
 *
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [CCCI IPC] Add CCCI IPC msgid for garbage filter
 *
 * removed!
 * removed!
 * [CCCI IPC] Support Clibtime feature
 *
 * removed!
 * removed!
 * .
 *
 * 10 08 2013 ap.wang
 * removed!
 * 	Fix EL1 module error
 *
 * 10 08 2013 ap.wang
 * removed!
 * 	Add MOD_EL1 and AP_MOD_WMT
 *
 * 07 15 2013 ap.wang
 * removed!
 *
 * 07 12 2013 aj.tsai
 * removed!
 * check-in aomgr code 
 * DHCPV4 ok
 *
 * 06 04 2013 ap.wang
 * removed!
 * .
 ****************************************************************************/

#ifndef __CCCI_IPC_MODULE_CONF_H__
#define __CCCI_IPC_MODULE_CONF_H__

#if defined(__HIF_CCCI_SUPPORT__)

// Cross Core IPC Direction :  AP 2 MD
// Priority   -->   Local module ID -->     External ID     --> Max sent message
X_IPC_MODULE_CONF(1,MOD_L4C,0,1),     //TASK_ID_1
#if defined(__SGLTE__) || defined(__GEMINI__)
    X_IPC_MODULE_CONF(1,MOD_L4C_2,1,1), //TASK_ID_2
#if (GEMINI_PLUS >= 3)
    X_IPC_MODULE_CONF(1,MOD_L4C_3,2,1), //TASK_ID_3
#endif    /* GEMINI_PLUS >= 3 */
#if (GEMINI_PLUS >= 4)
    X_IPC_MODULE_CONF(1,MOD_L4C_4,3,1), //TASK_ID_4
#endif    /* GEMINI_PLUS >= 4 */
#endif /* __GEMINI__ */

X_IPC_MODULE_CONF(1,MOD_AOMGR,4,1), //TASK_ID_4


#if defined(__LTE_RAT__)
X_IPC_MODULE_CONF(1,MOD_EL1,  5,1), //TASK_ID_4
#endif

// TASK_ID_6 is reserved to MISCTA

X_IPC_MODULE_CONF(1,MOD_CCCIIPC, 7,1), //TASK_ID_7

#if defined(__IPCORE_SUPPORT__) && !defined(IPCORE_NOT_PRESENT) && !defined(__IPCORE_TASK_DISABLE__)
X_IPC_MODULE_CONF(1,MOD_IPCORE, 8,1), //TASK_ID_8
#endif 

// Cross Core IPC Direction :  MD 2 AP
// Priority   -->   Local module ID -->     External ID     --> Max sent message
#define AP_UINFY_ID_FLAG ((kal_uint32)1<<31)
X_IPC_MODULE_CONF(1,APMOD_AGPS,(0|AP_UINFY_ID_FLAG),1),    
X_IPC_MODULE_CONF(1,APMOD_DHCP,(1|AP_UINFY_ID_FLAG),1),    
X_IPC_MODULE_CONF(1,APMOD_GPS ,(2|AP_UINFY_ID_FLAG),1),    
X_IPC_MODULE_CONF(1,APMOD_WMT ,(3|AP_UINFY_ID_FLAG),1),  
X_IPC_MODULE_CONF(1,APMOD_MISCTA ,(4|AP_UINFY_ID_FLAG),1),
X_IPC_MODULE_CONF(1,APMOD_CCCI ,(5|AP_UINFY_ID_FLAG),1),  

#endif /* __HIF_CCCI_SUPPORT__ */
#endif  /* !__CCCI_IPC_MODULE_CONF_H__ */


