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
*   bootarm.inc
*
* Project:
* --------
*   Maui_Software
*
* Description:
* ------------
*   This Module defines the platform dependent setting for boot sequence of asm level.
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
*
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *****************************************************************************/

#ifndef __BOOTARM_H__
#define __BOOTARM_H__

#define PC_INITIALIZE_VAL  0xE59FF018
#define DUMMY_END_VAL      0x454E4400


/* Define init label */
#ifdef __X_BOOTING__
#define INIT_MAGIC              0x4D4F0000  //MO				
#else /*__X_BOOTING__*/
#define INIT_MAGIC              0x30305F49  //I_00
#endif /*__X_BOOTING__*/
#define LABEL_START_INIT        0x0000
#define LABEL_TCM_INIT          0x0001
#define LABEL_SAVE_LRSP         0x0002
#define LABEL_ABN_RST_CHECK     0x0003
#define LABEL_VER_CHECK         0x0004 
#define LABEL_GET_RAND_SEED     0x0005
#define LABEL_REG_INIT_EMI      0x0006
#define LABEL_INT_CONFIG        0x0007
#define LABEL_CACHE_PRE_INIT    0x0008
#define LABEL_REG_INIT_MAIN     0x0009
#define LABEL_DCM_PREINIT       0x000A
#define LABEL_SERIPORT_PREINIT  0x000B
#define LABEL_BOOTTRC_INIT      0x000C
#define LABEL_GDB_INIT          0x000D
#define LABEL_CACHE_INIT        0x000E
#define LABEL_STACK_INIT        0x000F
#define LABEL_ASM_DONE          0x0010
#define LABEL_APPINIT           0x0011
#define LABEL_CLIB              0x0012
#define LABEL_CCCI_HS1          0x0013

#endif /* __BOOTARM_H__ */
