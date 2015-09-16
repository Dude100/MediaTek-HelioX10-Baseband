/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2010
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
 * Filename:
 * ---------
 * ps_em_enum.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is for engineer mode.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Add OPERATOR_TEST_CU mode and OPERATOR_TEST_VODAFONE mode for MT Secondary Test
 *
 * removed!
 * removed!
 * MT Secondary (Implement Ericsson IOT Mode)
 *
 * removed!
 * removed!
 * .
 *
 * 05 24 2013 hong.yu
 * removed!
 * GENERAL_BIT_FOR_DISABLE_SCRI_ONLY
 *
 * removed!
 * removed!
 * Code sync (MOLY TRUNK)
 *
 * removed!
 * removed!
 * Extract_AMR_Codec_from_L1
 *
 * removed!
 * removed!
 * replace CTA mode with Integrity Protection OFF mode.
 *
 * removed!
 * removed!
 * Part 2 - Other common files for Multimode
 *
 * 10 30 2012 hong.yu
 * removed!
 * fix typo
 * 
 * 10 26 2012 hong.yu
 * removed!
 * check in test profile definition
 * 
 * removed!
 * removed!
 * .
 * 
 * 10 10 2012 xi.li
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change. 
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change. 
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Integration change.
 *
 * removed!
 * removed!
 * Integration change. 
 *
 * removed!
 * removed!
 * Integration change. 
 *
 * 05 11 2011 xi.li
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * 03 04 2011 xi.li
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * FDD2TDD code sync stage 3, CTA menu, steady_inactive_ind.
 *
 * 12 08 2010 yc.chen
 * removed!
 * .
 *
 * removed!
 * removed!
 * Patch NVRAM parts for EM menu.
 *
 * removed!
 * removed!
 * L4 Add PS conformance test EM menu support & AT command Support
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __PS_EM_ENUM_H__
#define __PS_EM_ENUM_H__

/* Constants defined for PS conformance test mode special profile*/


typedef enum
{
    PS_CONF_TEST_NONE,
    PS_CONF_TEST_CTA,
    PS_CONF_TEST_IP_OFF = PS_CONF_TEST_CTA, /* mtk80420: remove CTA mode, replace with Integrity Protection OFF mode */
    PS_CONF_TEST_FTA,
    PS_CONF_TEST_IOT,
    PS_CONF_TEST_OPERATOR,
    PS_CONF_TEST_FACTORY,
    /* Add new test mode here! */
    PS_CONF_TEST_END
} ps_conf_test_mode_enum;

/***************
 * Define bit mask for MMI and PS, each special setting occupy 1 bit.  $$$ 1 bit, please
 * Please try to use the format like this:
 * (MODE)_(MENUNAME)_BIT_FOR_(MODULE)
 * eg. CTA_INTEGRITY_CHECK_BIT_FOR_MM
 *     FTA_ABC_FOR_XYZ or FTA_AB_C_FOR_XYZ_MNQ
 *************** */

/* General bits, and these bits CAN NOT taken by others whatever mode it's (CTA/FTA/IOT) 
   Please avoid to add any more bits here! */
#define GENERAL_BIT_FOR_DISABLE_SCRI_AND_FD 0x00800000
#define GENERAL_BIT_FOR_DISABLE_SCRI_ONLY   0x00400000

/* CTA Items */
#define CTA_INTEGRITY_CHECK_BIT_FOR_MM          0x00000001
#define CTA_TL1_BIT_FOR_TL1                     0x00000002
#define CTA_K1297_BIT_FOR_RRCE                  0x00000004
#define CTA_SNCONFLICT_BIT_FOR_RLC_RRCE         0x00000008
#define CTA_CFQUERY_BIT_FOR_SS                  0x00000010
#define CTA_PLMN_LOCK_BIT_FOR_CSCE              0x00000020
#define CTA_OPEN_MEAS_BIT_FOR_CSCE              0x00000040
#define CTA_SET_CAP_R4ONLY_BIT_FOR_RRCE         0x00000080
#define CTA_OPEN_INVALID_INTRA_CELL_REPORT__BIT_FOR_MEME     0x00000100
#define CTA_AUTO_ADJUST_BIT_FOR_RRCE            0x00000200
#define CTA_SET_CAP_R5DPA_BIT_FOR_RRCE          0x00000400
#define CTA_RELEASE_ADAPTION_BIT_FOR_RRCE       0x00000800
#define CTA_SET_CAP_R7UPA_BIT_FOR_RRCE          0x00001000
#define CTA_SET_CAP_R9UPA_BIT_FOR_RRCE          0x00002000
/* Add new definition here! */

/* FTA Items */
#define FTA_TEST_ANITE      0x00000001
#define FTA_TEST_CRTUG      0x00000002
#define FTA_TEST_CRTUW      0x00000004
#define FTA_TEST_ANRITSU    0x00000008
#define FTA_TEST_CMW500     0x00000010
/* Add new definition here! */

/* IOT items */
#define IOT_TEST_NSN    0x00000001
#define IOT_TEST_DCM_CB    0x00000002 /*It will enable CBMI 0xA000~0xA7FF for DoCoMo IOT*/
#define IOT_TEST_ERICSSON    0x00000004 /*It will enable NRSPCA(NISPCA) Network Requested(Initiated) Secondary PDP Context Activation for Ericsson IOT*/

/* Add new definition here! */

/* Operator Test Items */
#define OPERATOR_TEST_MS_USIM_COMPATIBLE    0x00000001
#define OPERATOR_TEST_ATNT                  0x00000002
#define OPERATOR_TEST_TMOBILE               0x00000004
#define OPERATOR_TEST_ORANGE                0x00000008
#define OPERATOR_TEST_VODAFONE              0x00000010
#define OPERATOR_TEST_O2                    0x00000020
#define OPERATOR_TEST_TELEFONICA            0x00000040
#define OPERATOR_TEST_DOCOMO                0x00000080
#define OPERATOR_TEST_SOFTBANK              0x00000100
#define OPERATOR_TEST_VIVO                  0x00000200
#define OPERATOR_TEST_CLARO                 0x00000400
#define OPERATOR_TEST_TIM                   0x00000800
#define OPERATOR_TEST_CU                    0x00001000 /*It will enable NRSPCA(NISPCA) Network Requested(Initiated) Secondary PDP Context Activation for Ericsson IOT*/
/* Add new definition here! */

/* Factory Items */
#define FACTORY_MODEM_VIRTUAL_SIM_ON_BIT_FOR_L4C                0x00000001
#define FACTORY_MODEM_AUTO_BOOT_AND_AUTO_ANSWER_BIT_FOR_L4C     0x00000002
/* Add new definition here! */

/* -----------For NW EVENT start--------------------- */
#define MAX_LEN_OF_NW_EVENT_NAME 20  
#define MAX_LEN_OF_NW_GROUP_NAME 5
#define EM_NW_NUM_OF_QUEUE_EVENT 32  

typedef enum
{
/* John Tang 2006/11/13 */
#ifdef __UMTS_RAT__
    
    /* MOD_UMAC */
    EM_NW_EVENT_ID_UMAC_EVENT_START,

    EM_NW_EVENT_ID_UMAC_EVENT_END,

    /* MOD_CSCE */
    EM_NW_EVENT_ID_CSCE_CELL_RESELECTION_EVENT,
    EM_NW_EVENT_ID_CSCE_NEW_CELL_SELECTED_EVENT,
    EM_NW_EVENT_ID_CSCE_OUT_OF_SERVICE_EVENT,
    EM_NW_EVENT_ID_CSCE_IN_SERVICE_EVENT,
    
    /* MOD_MEME */
    EM_NW_EVENT_ID_MEME_EVENT_SPECIFIC_CELL_IND,

    /* MOD_RRCE */
    EM_NW_EVENT_ID_RRCE_IRHO_3G2_EVENT,
    EM_NW_EVENT_ID_RRCE_IRCCO_3G2_EVENT,
    EM_NW_EVENT_ID_RRCE_IRCR_3G2_EVENT,

    EM_NW_EVENT_ID_RRCE_IRHO_3G4_EVENT,
    EM_NW_EVENT_ID_RRCE_IRCR_3G4_EVENT,

    /* MOD_SLCE */
    EM_NW_EVENT_ID_SLCE_EVENT_START,

    EM_NW_EVENT_ID_SLCE_EVENT_END,

#endif /* __UMTS_RAT__ */

    EM_NW_EVENT_ID_TEST0,     /* 0 */
    EM_NW_EVENT_ID_TEST1,
    EM_NW_EVENT_ID_TEST2,
    EM_NW_EVENT_ID_TEST3,
    EM_NW_EVENT_ID_TEST4,
    EM_NW_EVENT_ID_TEST5,
    EM_NW_EVENT_ID_TEST6,     /* 5 */
    EM_NW_EVENT_ID_TEST7,
    EM_NW_EVENT_ID_TEST8,
    EM_NW_EVENT_ID_TEST9,
    EM_NW_EVENT_ID_TEST10,
    EM_NW_EVENT_ID_TEST11,    /* 10 */
    EM_NW_EVENT_ID_TEST12,
    EM_NW_EVENT_ID_TEST13,
    EM_NW_EVENT_ID_TEST14,
    EM_NW_EVENT_ID_TEST15,
    EM_NW_EVENT_ID_TEST16,    /* 15 */
    EM_NW_EVENT_ID_TEST17,
    EM_NW_EVENT_ID_TEST18,
    EM_NW_EVENT_ID_TEST19,
    EM_NW_EVENT_ID_TEST20,
    EM_NW_EVENT_ID_TEST21,    /* 20 */
    EM_NW_EVENT_ID_TEST22,
    EM_NW_EVENT_ID_TEST23,
    EM_NW_EVENT_ID_TEST24,
    EM_NW_EVENT_ID_TEST25,
    EM_NW_EVENT_ID_TEST26,    /* 25 */
    EM_NW_EVENT_ID_TEST27,
    EM_NW_EVENT_ID_TEST28,
    EM_NW_EVENT_ID_TEST29,
    EM_NW_EVENT_ID_TEST30,
    EM_NW_EVENT_ID_TEST31,    /* 30 */
    EM_NW_EVENT_ID_TEST32,
    EM_NW_EVENT_ID_TEST33,
    EM_NW_EVENT_ID_TEST34,
    EM_NW_EVENT_ID_TEST35,
    EM_NW_EVENT_ID_TEST36,    /* 35 */
    EM_NW_EVENT_ID_TEST37,
    
    /* RAC Event start */
    EM_NW_EVENT_ID_CELL_POWER_LEVEL_IND,
    EM_NW_EVENT_ID_GMMREG_ATTACH_CNF,

    /* RAC Event End */
    
    EM_NW_EVENT_ID_MAX
    
} EM_NW_EVENT_ID_ENUM;

typedef enum
{
#ifdef __UMTS_RAT__
    //EM_NW_EVENT_GROUP_UMAC,
    EM_NW_EVENT_GROUP_CSCE,
    EM_NW_EVENT_GROUP_MEME,
    EM_NW_EVENT_GROUP_RRCE,
    //EM_NW_EVENT_GROUP_SLCE,
#endif /* __UMTS_RAT__ */
    EM_NW_EVENT_GROUP_RAC,
    /* don't remove this item and add new item before it */
    EM_NW_MAX_NO_OF_GROUP
} EM_NW_EVENT_GROUP_ENUM;
/* -----------For NW EVENT end------------------------- */

#ifdef __AMR_SUPPORT__
typedef enum
{
    EM_AMR_MODE_475,
    EM_AMR_MODE_515,
    EM_AMR_MODE_590,
    EM_AMR_MODE_670,
    EM_AMR_MODE_740,
    EM_AMR_MODE_795,
    EM_AMR_MODE_1020, /* This is the number of half rate codec modes. */
    EM_AMR_MODE_1220,
    EM_AMR_MODE_NONE, /* This is the number of full rate codec modes. */
} em_amr_mode_enum;
#endif /* __AMR_SUPPORT__ */
#endif  /* __PS_EM_ENUM_H__ */


