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
 *	el1_rf_cid.h
 *
 * Project:
 * --------
 * MT6290
 *
 * Description:
 * ------------
 * LTE RF Chip ID
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef  _EL1_RF_CID_H_
#define  _EL1_RF_CID_H_

/*******************************************************************************
** Define RF chip in use
*******************************************************************************/

/*------------------------------------------*/
/* Use in EL1 :                             */
/*   ( 1) EL1_RF_ID_MT6169                  */
/*------------------------------------------*/

#define EL1_RF_ID_MT6169                         0x00000001

/*.......................................................*/

#define IS_EL1_RF_MT6169                         ( EL1_RF_ID==EL1_RF_ID_MT6169 )

/*.......................................................*/

#ifndef EL1_RF_ID
   #if defined(MT6169_RF)
#define EL1_RF_ID                                EL1_RF_ID_MT6169
   #else
#error "No Valid RF Chip was defined"
   #endif
#else
   #error "Unexpected RF Chip was defined"
#endif //EL1_RF_ID

/*.......................................................*/

/*****************************************************
** TX Power offset define           
*****************************************************/
#if defined (__TX_POWER_OFFSET_SUPPORT__)
#define IS_4G_TX_POWER_OFFSET_SUPPORT                 1  /* Enable Tx power offset for 4G part */
#else
#define IS_4G_TX_POWER_OFFSET_SUPPORT                 0  /* Disable Tx power offset for 4G part */
#endif /*__TX_POWER_OFFSET_SUPPORT__*/   

#if defined(__TAS_SUPPORT__)
#define IS_4G_TAS_SUPPORT                             1  /* The 4G TAS is supported                                       */
   #if defined (__TAS_INTERNAL_NVRAM_VISIBLE__)
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              1  /* The 4G TAS internal parameters can be controlled by NVRAM     */
   #else
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              0  /* The 4G TAS internal parameters can NOT be controlled by NVRAM */
   #endif
#else
#define IS_4G_TAS_SUPPORT                             0  /* The 4G TAS is NOT supported                                   */
#define IS_4G_TAS_INTERNAL_NVRAM_VISIBLE              0  /* The 4G TAS internal parameters can NOT be controlled by NVRAM */
#endif

#endif /* End of #ifndef _EL1_RF_CID_H_ */
