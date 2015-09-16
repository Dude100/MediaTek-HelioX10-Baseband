/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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
 * nvram_cust_pack.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef NVRAM_AUTO_GEN
#include "nvram_auto_gen.h"
#endif

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "nvram_data_items.h"
#include "nvram_defs.h"
#include "nvram_editor_data_item.h"
#include "ul1_nvram_def.h"

#if defined(__MMI_FMI__)
#include "nvram_user_defs.h"
#include "custom_nvram_editor_data_item.h"
#include "custom_mmi_default_value.h"

#endif

#ifdef __PS_SERVICE__
#include "custom_gprs_pdp_default_qos_config.h" // Carlson, for PS_QOS_PROFILE_DEFAULT_REQ_XXX and PS_QOS_PROFILE_DEFAULT_MIN_XXX
#endif

/* Add include statement above this line */
#ifndef __OPTR_NONE__
#include "op_nvram_common_config.h"
#endif

#ifdef __MEDIATEK_SMART_QOS__
nvram_ef_msq_list_struct const NVRAM_EF_MSQ_LIST_DEFAULT[] = 
{
    {
        /* is_msq_on */
        /* - Format: 0 (OFF), 1 (ON) */
        1,
        0, /* padding */
        
        /* nvram_ef_msq_entry_struct msq_entry[MSQ_MAX_ENTRY_COUNT] 
         * - Format: {<entry_id>,"<PLMN_ID>",<check_nw>,<check_sim>}
         */
        {
            /* 01 ~ 10. */
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
                                                                  
            /* 11 ~ 20. */                                        
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
                                                                  
            /* 21 ~ 30. */                                        
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},  
                                                                  
            /* 31 ~ 40. */                                        
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0}, 
                                                                  
            /* 41 ~ 50. */                                        
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},

            /* 51 ~ 60. */
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},

            /* 61 ~ 70. */
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},

            /* 71 ~ 80. */
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},

            /* 81 ~ 90. */

            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},

            /* 91 ~ 100. */
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0},
            {0,"",0,0}
        }
    }
} ;
#endif /* __MEDIATEK_SMART_QOS__ */

#if !defined(NVRAM_NOT_PRESENT) && !defined(__L1_STANDALONE__)
/*
        3G multiband support
bit     |	8     7    6    5    4    3    2    1
  |-------------------------------------------
byte 0  | VIII  VII  VI   V    IV	  III  II   I
  |-------------------------------------------
byte 1  |                                X    IX

*/
typedef enum
{
    Support_UMTS_BAND_I       = 0x01,
    Support_UMTS_BAND_II      = 0x02,
    Support_UMTS_BAND_III     = 0x04,
    Support_UMTS_BAND_IV      = 0x08,
    Support_UMTS_BAND_V       = 0x10,
    Support_UMTS_BAND_VI      = 0x20,
    Support_UMTS_BAND_VII     = 0x40,
    Support_UMTS_BAND_VIII    = 0x80,
    Support_UMTS_BAND_IX      = 0x01,
    Support_UMTS_BAND_X       = 0x02,
    Support_UMTS_BAND_XI      = 0x04,
    Support_UMTS_BAND_XII     = 0x08,
    Support_UMTS_BAND_XIII    = 0x10,
    Support_UMTS_BAND_XIV     = 0x20,
    Support_UMTS_BAND_XV      = 0x40,
    Support_UMTS_BAND_XVI     = 0x80,
    Support_UMTS_BAND_XVII    = 0x01,
    Support_UMTS_BAND_XVIII   = 0x02,
    Support_UMTS_BAND_XIX     = 0x04,
    Support_UMTS_BAND_XX      = 0x08,
    Support_UMTS_BAND_XXI     = 0x10,
    Support_UMTS_BAND_XXII    = 0x20,
    Support_UMTS_BAND_XXIII   = 0x40,
    Support_UMTS_BAND_XXIV    = 0x80,
    Support_UMTS_BAND_XXV     = 0x01,
    Support_UMTS_BAND_XXVI    = 0x02,
    Support_UMTS_BAND_XXVII   = 0x04,
    Support_UMTS_BAND_XXVIII  = 0x08,
    Support_UMTS_BAND_XXIX    = 0x10,
    Support_UMTS_BAND_XXX     = 0x20,
    Support_UMTS_BAND_XXXI    = 0x40,
    Support_UMTS_BAND_XXXII   = 0x80
}rac_multi_band_option_enum;

#if !defined(EXTERNAL_MMI)
#ifdef __MAX_MAILBOX_NAME_UPDATA_TO_30__
const kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Alpha ID */
    0x00,   /* Length of BCD number */
    0xff,   /* TON and NPI */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Dailling number */
    0xff,   /* capability/configuration identifier */
    0xff    /* extension 1 record identifier */
};
#else
const kal_uint8 COMMON_NVRAM_EF_SMSAL_MAILBOX_ADDR_DEFAULT[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Alpha ID */
    0x00,   /* Length of BCD number */
    0xff,   /* TON and NPI */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* Dailling number */
    0xff,   /* capability/configuration identifier */
    0xff    /* extension 1 record identifier */
};
#endif
#endif

kal_uint8 const COMMON_NVRAM_EF_MS_SECURITY_DEFAULT[] =
{
/*
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // reg_ps_key
*/
    0x00,                                                   /* security_indication */
/*
    0x00,                                                   // auto_lock_item
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // np_code
    0x21, 0x43, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // np_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // nsp_code
    0x65, 0x87, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // nsp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00,                                       // np_of_sp
    0x00, 0x00, 0x00,                                       // np_of_cp
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // gid1
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, // gid2
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // sp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // cp_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // imsi_code
    0x33, 0x44, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // imsi_key
*/
    0x11, 0x22, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,         // phone_key
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   // last_imsi
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,         // pin1
    0x00,                                                   // pin1_valid
    0x00,                                                    // phone_lock_verified
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00 // iccid
};

#ifdef __CPHS__
const kal_uint8 COMMON_NVRAM_EF_ALS_LINE_ID_DEFAULT[NVRAM_EF_ALS_LINE_ID_SIZE] =
{
    0x0, 0x0
};
#endif /* __CPHS__ */

const kal_uint8 COMMON_NVRAM_EF_MSCAP_DEFAULT[NVRAM_EF_MSCAP_SIZE] =
{
/* Byte 1~4 describes MS supported codec
 * 1. Codec types is coded as the definition in TS26.103, Sec. 6.2, Codec Bitmap
 * 2. Spec Codec Bitmap combines GSM and UMTS together, whereas we separate codec
 *    types according to different radio access technologies. So GAS can directly
 *    read first 2 bytes for speech capability.
 */
#if defined(__AMR_SUPPORT__)
    0x1f,   /* Supported speech version (FR,HR,EFR,AMR FR,AMR HR) */
#else
    0x07,   /* Supported speech version (FR,HR,EFR) */
#endif 
//0528_AMRWB: Restructure EF_MSCAP, put speech codec bytes together
#if defined(__AMRWB_LINK_SUPPORT__)
#if defined(__AMR_WB_WHITE_LIST__)
    0x02,  /* byte 2 for GSM supported codec, (FR AMRWB) */
#else
    0x00,  /* byte 2 for GSM supported codec */
#endif
#else
    0x00,  /* byte 2 for GSM supported codec */
#endif
#ifdef __UMTS_TDD128_MODE__ /*MOLY00003437*/
    0x20,
#else
    0x60,  /* byte 1 for UMTS supported codec,(UMTS_AMR, UMTS_AMR2) */ 
#endif
#if defined(__AMRWB_LINK_SUPPORT__)
    0x04,  /* byte 2 for GSM supported codec, (UMTS_AMRWB) */
#else
    0x00,  /* byte 2 for UMTS supported codec */
#endif
#if defined(__CSD_T__) && defined(__CSD_NT__) && defined(__CSD_FAX__)
#ifdef __SYNC_HDLC_CSD__
    0x6b,   /* Supported data capability 1 (T & NT & FAX_T) */
#else
    0x63,   /* Supported data capability 1 (T & NT & FAX_T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_T__) && defined(__CSD_NT__)
#ifdef __SYNC_HDLC_CSD__
    0x69,   /* Supported data capability 1 (T & NT) */
#else
    0x61,   /* Supported data capability 1 (T & NT) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_T__) && defined(__CSD_FAX__)
#ifdef __SYNC_HDLC_CSD__
    0x2b,   /* Supported data capability 1 (T & FAX_T) */
#else
    0x23,   /* Supported data capability 1 (T & FAX_T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_NT__) && defined(__CSD_FAX__)
    0x43,   /* Supported data capability 1 (NT & FAX_T) */
#elif defined(__CSD_T__)
#ifdef __SYNC_HDLC_CSD__
    0x29,   /* Supported data capability 1 (ONLY T) */
#else
    0x21,   /* Supported data capability 1 (ONLY T) */
#endif /* __SYNC_HDLC_CSD__ */
#elif defined(__CSD_NT__)
    0x41,   /* Supported data capability 1 (ONLY NT) */
#elif defined(__CSD_FAX__)
    0x02,   /* Supported data capability 1 (ONLY FAX_T) */
#else
    0x00,   /* Supported data capability 1 (NO SUPPORT CSD) */
#endif
    0x00,   /* Supported data capability 2 */
#if defined(CSD_SUPPORT) || defined(__CSD_FAX__)
    0x1f,    /* Supported channel coding (2.4k,4.8k,9.6k,14.4k,HR) */
#else /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */
    0x00,
#endif /* defined(CSD_SUPPORT) || defined(__CSD_FAX__) */
#if defined(__DISABLE_CSCALL__)
    0x01, /*0x01 mean disable call , 0x00 mean not disable call*/
#else
    0x00,
#endif
    /* The 1st bit of the byte: Support of random L2 fill bits. 1: support, 0: not support.
       The 2nd and 3rd bit of the byte: VAMOS support level, 10: VAMOS II, 01: VAMOS I, 00: not support. */
#if defined(__VAMOS_2__) && defined(__CUSTOMIZE_VAMOS__)
    0xc0,
#elif defined(__VAMOS_1__) && defined(__CUSTOMIZE_VAMOS__)
    0xa0,
#else
    0x80,
#endif
    0x05 /*mm_non_drx_timer_value(sec), default value is 5 sec*/

/************************************ !!! GAS OWNERS MUST READ !!! ************************************
    If 
       (1) you want to add a setting value in this NVRAM file (NVRAM_EF_MSCAP_LID), and
       (2) The setting can be also read in NVRAM_EF_CLASSMARK_RACAP_LID

    You have to notice that the setting value may be overlapped by some procedures (for example, 
    dynamic band setting), which will re-read NVRAM_EF_CLASSMARK_RACAP_LID. As a result, the
    setting you want will be again changed to the original value. To avoid this, you must additionally
    do extra handling in mrs_gas_decode_ms_capability(..., ..., kal_bool is_dynmc_cfg).
    If the input "is_dynmc_cfg == TRUE", do not re-write the setting. VAMOS setting capability is an 
    examlpe you can refer to.

    To ensure everyone knows this, please do NOT add code after this comment. 

************************************ !!! GAS OWNERS MUST READ !!! ************************************/
};

#if defined(__UMTS_TDD128_MODE__) || defined(__TDD_2G_OP01__)
kal_uint8 const COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[] = 
{
    /* Ripple: 20050513, Auto band, then turn on all supported bands. */
    //mtk02475: change to bitmap coding style, avoid enumarate all band setting combination
    0
#if defined(__EGSM900__) && defined(__DISABLE_EGSM__) //mtk02475: AS and L1 need keep EGSM compile option turn on, request RAC turn on PGSM only
    + 0x01
#else /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __PGSM900__
    + 0x01
#endif /* __PGSM900__ */
#ifdef __EGSM900__
    + 0x02
#endif /* __EGSM900__ */
#endif /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __RGSM900__
    + 0x04
#endif /* __RGSM900__ */
#ifdef __DCS1800__
    + 0x08
#endif /* __DCS1800__ */
#ifdef __PCS1900__
    + 0x10
#endif /* __PCS1900__ */
#ifdef __GSM450__
    + 0x20
#endif /* __GSM450__ */
#ifdef __GSM850__
    + 0x80
#endif /* __GSM850__ */
    ,
    // 0x80 /* PLMN selection mode and Preferred Service in NMO III */
    //mtk02475: merge MODEM project specific default value via compile option, set GPRS always on for single SIM modem project.
    //mtk02475: for NWSIM environment, set to GPRS always on for executing GCF TTCN
#ifdef __UE_SIMULATOR__
    0xD0    /* GPRS auto attach - always on */
#else /* __UE_SIMULATOR__ */
#if defined(__MMI_FMI__) || defined(__GEMINI__)
    0xC0    /* GPRS when needed */
#else /* __MMI_FMI__ || __GEMINI__ */
    0xD0    /* GPRS always on */
#endif /* __MMI_FMI__ || GEMINI__ */
#ifdef __DYNAMIC_ROAMING_SUPPORT__
        +0x02
#else
        +0x00
#endif
#endif /* __UE_SIMULATOR__ */
#ifdef __PLMN_LIST_PREF_SUPPORT__
+ 0x00 /*PLMN_LIST_PREFERENCE: 0: ACCURACY FIRST, 1: SPEED_FIRST*/
#endif
#ifdef __MM_INTEGRITY_PREF__
+ 0x00 /* MM INTEGRITY CHECK PREFERENCE: 0x00: integrity check enabled, 0x08: integrity check disabled when test SIM */
#endif
,
/* 3rd  byte is RAT mode*/
0
/* always disable LTE RAT whenver __MM_DISABLE_L__ flag is set */
#ifndef __MM_DISABLE_L__
#if defined(__LTE_RAT__)
	| 0x04
#endif
#endif /* __MM_DISABLE_L__ */

#if defined(__UMTS_RAT__)
| 0x02
#endif
#if defined(__GSM_RAT__) && !defined(__SGLTE__)
| 0x01
#endif
,


/* 4th  byte is IR preferred RAT and MM preferred RAT */
// MM preferred RAT 0x00 : RAT_NONE  0x01 : RAT_GSM 0x02 : RAT_UMTS 0x04 : RAT_LTE 
    0x00
    +
// IR preferred RAT 0x00 : RAT_NONE  0x10 : RAT_GSM 0x20 : RAT_UMTS  
    0x20
    , 

/* 5th  byte is first byte of UMTS preferred band */
    0 // initial value

#if defined(__UMTS_BAND_I__) || defined(__UMTS_TDD128_BAND_A__)
    + Support_UMTS_BAND_I
#endif

#if defined(__UMTS_BAND_II__) || defined(__UMTS_TDD128_BAND_B__) 
    + Support_UMTS_BAND_II
#endif

#if defined(__UMTS_BAND_III__) || defined(__UMTS_TDD128_BAND_C__)
    + Support_UMTS_BAND_III
#endif

#if defined(__UMTS_BAND_IV__) || defined(__UMTS_TDD128_BAND_D__) 
    + Support_UMTS_BAND_IV
#endif

#if defined(__UMTS_BAND_V__) || defined(__UMTS_TDD128_BAND_E__) 
    + Support_UMTS_BAND_V
#endif

#if defined(__UMTS_BAND_VI__) || defined(__UMTS_TDD128_BAND_F__) 
    + Support_UMTS_BAND_VI
#endif

#if defined(__UMTS_BAND_VII__) 
    + Support_UMTS_BAND_VII
#endif

#if defined(__UMTS_BAND_VIII__) 
    + Support_UMTS_BAND_VIII
#endif

#if 1 
    ,  // end of character
#endif
    /* 6th  byte is second byte of UMTS preferred band */                   
    0 // initial value

#if defined(__UMTS_BAND_IX__)
    + Support_UMTS_BAND_IX
#endif

#if defined(__UMTS_BAND_X__)
    + Support_UMTS_BAND_X
#endif

#if defined(__UMTS_BAND_XI__)
    + Support_UMTS_BAND_XI
#endif

#if defined(__UMTS_BAND_XII__)
    + Support_UMTS_BAND_XII
#endif

#if defined(__UMTS_BAND_XIII__)
    + Support_UMTS_BAND_XIII
#endif

#if defined(__UMTS_BAND_XIV__)
    + Support_UMTS_BAND_XIV
#endif

#if defined(__UMTS_BAND_XV__)
    + Support_UMTS_BAND_XV
#endif

#if defined(__UMTS_BAND_XVI__)
    + Support_UMTS_BAND_XVI
#endif

#if 1 
    ,  // end of character
#endif
    /* 7th  byte is third byte of UMTS preferred band */                   
    0 // initial value

#if defined(__UMTS_BAND_XVII__)
    + Support_UMTS_BAND_XVII
#endif

#if defined(__UMTS_BAND_XVIII__)
    + Support_UMTS_BAND_XVIII
#endif

#if defined(__UMTS_BAND_XIX__)
    + Support_UMTS_BAND_XIX
#endif

#if defined(__UMTS_BAND_XX__)
    + Support_UMTS_BAND_XX
#endif

#if defined(__UMTS_BAND_XXI__)
    + Support_UMTS_BAND_XXI
#endif

#if defined(__UMTS_BAND_XXII__)
    + Support_UMTS_BAND_XXII
#endif

#if defined(__UMTS_BAND_XXIII__)
    + Support_UMTS_BAND_XXIII
#endif

#if defined(__UMTS_BAND_XXIV__)
    + Support_UMTS_BAND_XXIV
#endif

#if 1 
    ,  // end of character
#endif
    /* 8th  byte is fourth byte of UMTS preferred band */                   
    0 // initial value

#if defined(__UMTS_BAND_XXV__)
    + Support_UMTS_BAND_XXV
#endif

#if defined(__UMTS_BAND_XXVI__)
    + Support_UMTS_BAND_XXVI
#endif

#if defined(__UMTS_BAND_XXVII__)
    + Support_UMTS_BAND_XXVII
#endif

#if defined(__UMTS_BAND_XXVIII__)
    + Support_UMTS_BAND_XXVIII
#endif

#if defined(__UMTS_BAND_XXIX__)
    + Support_UMTS_BAND_XXIX
#endif

#if defined(__UMTS_BAND_XXX__)
    + Support_UMTS_BAND_XXX
#endif

#if defined(__UMTS_BAND_XXXI__)
    + Support_UMTS_BAND_XXXI
#endif

#if defined(__UMTS_BAND_XXXII__)
    + Support_UMTS_BAND_XXXII
#endif

#if 1 
    ,  // end of character
#endif
    /* 9th byte is HSPA preference + GPRS transfer preference*/
    0
#ifdef __HSPA_PREFERENCE_SETTING__
        //mtk02475: default turn on maximum HSPA capability
#if defined(__HSUPA_SUPPORT__)
        + 0x20
#elif defined(__HSDPA_SUPPORT__)
        + 0x10
#else
        + 0x00  // 0x00 for HSPA_OFF, 0x10 for HSDPA_ON, 0x20 for HSDPA_HSUPA_ON, 0x30 for HSDPA & HSUPA & HSPAPLUS ON
#endif
#endif
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
        + 0x00  // 0 for GPRS_PREFER, 1 for CALL prefer, // 2 for AS_OPTIMAL(reserved)
#endif

    ,  // end of character

    /* 10th byte roaming related setting, default off */
    0
#ifdef __RAC_REPORT_LIMIT_AFTER_TRYALLPLMN__
    + 0x08  // 0x00 disable roaming broker, 0x08 enable roaming broker
#endif     

    ,  // end of character
    
    /* 11th byte: mobility management IMS voice termination, default disabled */
    1

    ,  // end of character

    /* 12th byte: voice domain preference for UTRAN, default CS voice only */
    1

};
#else
kal_uint8 const COMMON_NVRAM_EF_RAC_PREFERENCE_DEFAULT[] =
{
    /* Ripple: 20050513, Auto band, then turn on all supported bands. */
    //mtk02475: change to bitmap coding style, avoid enumarate all band setting combination
    0
#if defined(__EGSM900__) && defined(__DISABLE_EGSM__) //mtk02475: AS and L1 need keep EGSM compile option turn on, request RAC turn on PGSM only
    + 0x01
#else /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __PGSM900__
    + 0x01
#endif /* __PGSM900__ */
#ifdef __EGSM900__
    + 0x02
#endif /* __EGSM900__ */
#endif /* defined(__EGSM900__) && defined(__DISABLE_EGSM__) */
#ifdef __RGSM900__
    + 0x04
#endif /* __RGSM900__ */
#ifdef __DCS1800__
    + 0x08
#endif /* __DCS1800__ */
#ifdef __PCS1900__
    + 0x10
#endif /* __PCS1900__ */
#ifdef __GSM450__
    + 0x20
#endif /* __GSM450__ */
#ifdef __GSM850__
    + 0x80
#endif /* __GSM850__ */
    ,
/* 1th byte is PLMN selection mode(1) | Preferred Service in NMO III(2) | GPRS auto attach(1) | Reserved(3)  | PLMN list preference(1) */    
    // 0x80 /* PLMN selection mode and Preferred Service in NMO III */
    //mtk02475: merge MODEM project specific default value via compile option, set GPRS always on for single SIM modem project.
    //mtk02475: for NWSIM environment, set to GPRS always on for executing GCF TTCN
#ifdef __UE_SIMULATOR__
    0xD0    /* GPRS auto attach - always on */
#else /* __UE_SIMULATOR__ */
#if defined(__MMI_FMI__) || defined(__GEMINI__)
    0xC0    /* GPRS when needed */
#else /* __MMI_FMI__ || __GEMINI__ */
    0xD0    /* GPRS always on */
#endif /* __MMI_FMI__ || GEMINI__ */
#endif /* __UE_SIMULATOR__ */
#ifdef __PLMN_LIST_PREF_SUPPORT__
+ 0x00 /*PLMN_LIST_PREFERENCE: 0: ACCURACY FIRST, 1: SPEED_FIRST*/
#endif
#ifdef __3G_CSG_SUPPORT__
+ 0x00 /* CSG_AUTO_SEARCH_PREFERENCE: 0x0: DISABLE, 0x4: ENABLE */
#endif /* __3G_CSG_SUPPORT__ */
#ifdef __MM_INTEGRITY_PREF__
+ 0x00 /* MM INTEGRITY CHECK PREFERENCE: 0x00: integrity check enabled, 0x08: integrity check disabled when test SIM */
#endif
,
/* 3rd  byte is RAT mode*/
0
/* always disable LTE RAT whenver __MM_DISABLE_L__ flag is set */
#ifndef __MM_DISABLE_L__
#if defined(__LTE_RAT__)
| 0x04
#endif
#endif /* __MM_DISABLE_L__ */
#if defined(__UMTS_RAT__)
| 0x02
#endif
#if defined(__GSM_RAT__)
| 0x01
#endif
,

/* 4th  byte is IR preferred RAT and MM preferred RAT */
// MM preferred RAT 0x00 : RAT_NONE  0x01 : RAT_GSM 0x02 : RAT_UMTS 0x04 : RAT_LTE 
    0x00
    +
// IR preferred RAT 0x00 : RAT_NONE  0x10 : RAT_GSM 0x20 : RAT_UMTS  
    0x00
    , 

/* 5th  byte is first byte of UMTS preferred band, UMTS_PREFERRED_BAND_FIRST_BYTE */
// mtk02475: for MT6276/MT6573 UMTS band customization, need to default turn on all UMTS band instead of check UMTS band feature option
    0 // initial value


    + Support_UMTS_BAND_I



    + Support_UMTS_BAND_II



    + Support_UMTS_BAND_III



    + Support_UMTS_BAND_IV



    + Support_UMTS_BAND_V



    + Support_UMTS_BAND_VI



    + Support_UMTS_BAND_VII



    + Support_UMTS_BAND_VIII


#if 1
    ,  // end of character
#endif
    /* 6th  byte is second byte of UMTS preferred band, UMTS_PREFERRED_BAND_SECOND_BYTE */
    0 // initial value


    + Support_UMTS_BAND_IX



    + Support_UMTS_BAND_X


    + Support_UMTS_BAND_XI



    + Support_UMTS_BAND_XII



    + Support_UMTS_BAND_XIII



    + Support_UMTS_BAND_XIV



    + Support_UMTS_BAND_XV



    + Support_UMTS_BAND_XVI


#if 1 
    ,  // end of character
#endif
    /* 7th  byte is third byte of UMTS preferred band */                   
    0 // initial value


    + Support_UMTS_BAND_XVII



    + Support_UMTS_BAND_XVIII



    + Support_UMTS_BAND_XIX



    + Support_UMTS_BAND_XX



    + Support_UMTS_BAND_XXI



    + Support_UMTS_BAND_XXII



    + Support_UMTS_BAND_XXIII



    + Support_UMTS_BAND_XXIV


#if 1 
    ,  // end of character
#endif
    /* 8th  byte is fourth byte of UMTS preferred band */                   
    0 // initial value


    + Support_UMTS_BAND_XXV



    + Support_UMTS_BAND_XXVI



    + Support_UMTS_BAND_XXVII



    + Support_UMTS_BAND_XXVIII



    + Support_UMTS_BAND_XXIX



    + Support_UMTS_BAND_XXX



    + Support_UMTS_BAND_XXXI



    + Support_UMTS_BAND_XXXII


#if 1
    ,  // end of character
#endif
/* 9th byte is HSPA preference + GPRS transfer preference*/
    0
#ifdef __HSPA_PREFERENCE_SETTING__
    //mtk02475: default turn on maximum HSPA capability
#if defined(__UMTS_R7__)
    + 0x30
#elif defined(__HSUPA_SUPPORT__)
    + 0x20
#elif defined(__HSDPA_SUPPORT__)
    + 0x10
#else
    + 0x00  // 0x00 for HSPA_OFF, 0x10 for HSDPA_ON, 0x20 for HSDPA_HSUPA_ON, 0x30 for HSDPA & HSUPA & HSPAPLUS ON
#endif 
#endif /* __HSPA_PREFERENCE_SETTING__ */
#ifdef __GEMINI_MONITOR_PAGE_DURING_TRANSFER__
    + 0x00  // 0x00 for NO_PREEMPTION, 0x04 for PREEMPT_PEER_PS_TRANSFER
#endif /* __GEMINI_MONITOR_PAGE_DURING_TRANSFER__ */
#ifdef __MONITOR_PAGE_DURING_TRANSFER__
    + 0x00  // 0 for GPRS_PREFER, 1 for CALL prefer, // 2 for AS_OPTIMAL(reserved)
#endif /* __MONITOR_PAGE_DURING_TRANSFER__ */

    ,  // end of character

    /* 10th byte roaming related setting, default off */
    0
#ifdef __RAC_REPORT_LIMIT_AFTER_TRYALLPLMN__
    + 0x08  // 0x00 disable roaming broker, 0x08 enable roaming broker
#endif     

    ,  // end of character
    
    /* 11th byte: mobility management IMS voice termination, default disabled */
    1

    ,  // end of character

    /* 12th byte: voice domain preference for UTRAN, default CS voice only */
    1

};
#endif /* #ifdef __UMTS_TDD128_MODE__ */

kal_uint8 const COMMON_NVRAM_EF_SMSAL_COMMON_PARAM_DEFAULT[] =
{
#if defined (__CS_SERVICE__) && defined (__SMS_OVER_PS_SUPPORT__)
    0x01,               /* bearer service : CS Only */
#elif defined (__SMS_OVER_PS_SUPPORT__)
    0x00,               /* bearer service : PS Only */
#else
    0x01,               /* bearer service : CS Only */
#endif
    0x00, 0x00,         /* status report, reply path OFF */
    0x02,               /* VP: Relative format */
#ifdef __UNIFIED_MESSAGE_SIMBOX_SUPPORT__
    0x01, 0x01, 0x01,   /* mem1, mem2, mem3 */
#else/* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
    0x05, 0x05, 0x05,   /* mem1, mem2, mem3 */
#endif /* __UNIFIED_MESSAGE_SIMBOX_SUPPORT__ */
#ifdef __UE_SIMULATOR__
    0x01, 0x01,         /* CB setting - ON */
#else
    0x00, 0x01,         /* CB setting */
#endif
    0x00,               /* AT default profile ID */
    0x00,               /* First Octet */
    0x00,               /* Turn Off SMS FDN */
    0x00,               /* last_used_tp_mr */
    0xFF,               /* mem_capacity_available. Default 0xFF means memory available.*/
    0x00,               /* selected_msp */
    0x00                /* reserve */
};

/* Cell Broadcast Default Channel Setting. */
/* The channels set will not shown in MMI, but it will received CB if CB is turned on. */
/* This setting may be changed by customer. DON'T remove it. */
kal_uint8 const COMMON_NVRAM_EF_CB_DEFAULT_CH_DEFAULT[] =
{
    0xFF, 0xFF, /* default CH 1 , for example:  chanel 50 is 0x00, 0x32 */
    0xFF, 0xFF, /* default CH 2  */
    0xFF, 0xFF, /* default CH 3  */
    0xFF, 0xFF, /* default CH 4  */
    0xFF, 0xFF, /* default CH 5  */
    0xFF, 0xFF, /* default CH 6  */
    0xFF, 0xFF, /* default CH 7  */
    0xFF, 0xFF, /* default CH 8  */
    0xFF, 0xFF, /* default CH 9  */
    0xFF, 0xFF  /* default CH 10 */
};



//__MOBILE_BROADBAND_PROVISION_CONTEXT__
#ifdef __MOBILE_BROADBAND_PROVISION_CONTEXT__
nvram_ef_mobile_broadband_provision_context_struct const COMMON_NVRAM_EF_MOBILE_BROADBAND_PROVISION_CONTEXT_DEFAULT[] =
{
    /* Example Entry 1: 46692, internet */
    {
        1,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "internet",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46692",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied
    },

    /* Example Entry 2: 46601, fetnet01 */
    {
        2,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "internet",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46601",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied        
    },    

    /* Example Entry 3: 46697, internet */
    {
        3,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "internet",                //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46697",                   //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied        
    },    

    /* Example Entry 4: 46692, emome */
    {
        4,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "emome",                   //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        1,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46692" ,                  //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied        
    },
    
    /* Example Entry 5: empty */
    {
        5,                         //kal_uint32 context_id;
        1,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "vibo",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "46689",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        1                          //0: empty, 1: occupied
    },
    
    /* Example Entry 6: empty */
    {
        6,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },        

    /* Example Entry 7: empty */
    {
        7,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },
    
    /* Example Entry 8: empty */
    {
        8,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },            

    /* Example Entry 9: empty */
    {
        9,                         //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    },
    
    /* Example Entry 10:empty */
    {
        10,                        //kal_uint32 context_id;
        0,                         //kal_uint8  context_type;        //None, Internet, Vpn, Voice, VideoShare, Custom
        "",                        //kal_uint8  access_string[100];  
        "",                        //kal_uint8  user_name[32];
        "",                        //kal_uint8  pass_word[32];    
        0,                         //kal_uint8  compression;         //None, Enable
        0,                         //kal_uint8  auth_type;           //None, Pap, Chap, MsChapV2
        "",                        //kal_uint8  plmn_in_digit[7];    //Ex. '4','6','6','9','2','\0'
        0                          //0: empty, 1: occupied
    }
};
#endif /* __MOBILE_BROADBAND_PROVISION_CONTEXT__ */

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__)
#if defined (__MTK_UL1_FDD__)
/********************************************************/
/* MT6573 3G RF Customization for Modem Bin Update Tool */
/********************************************************/

#include "ul1d_custom_rf.h"
#include "ul1d_rf_public.h"
U_sUl1dRfCustomInputData const COMMON_NVRAM_EF_UL1_3G_RF_PARAMETER_DEFAULT[NVRAM_EF_UL1_3G_RF_PARAMETER_TOTAL]=
{
   {
      /* Start Pattern */
      0x0, /* can't use special pattern here */

      /* Structure Version */
      1,

      /* RF Type */
      UMTS_RF_TYPE,

      /* isDataUpdate */
      1,

#if defined (__UL1_HS_PLUS_PLATFORM__)
      /* proityOfNvramInCustomization */
      RF_SETTING_BY_NVRAM,
#endif
      
      /* umtsRfPaControlTimingOffset */
      {
         MAX_OFFSET,
         VM_OFFSET,
         VBIAS_OFFSET,
         DC2DC_OFFSET,
         VGA_OFFSET
      },

      /* umtsBsiBpiTiming */
      {
         /* RX window end timing */
         -TC_PR1,
         -TC_PR2,
         -TC_PR2B,

         /* RX window end timing */
         TC_PR3,
         TC_PR3A,

         /* TX window start timing */
         -TC_PT1,
         -TC_PT2,
         -TC_PT2B,

         /* TX window end timing */
         TC_PT3,
         TC_PT3A
      },

      /* umtsPdata */
      {
         /* Band 1 BPI data */
         PDATA_BAND1_PR1,
         PDATA_BAND1_PR2,
         PDATA_BAND1_PR2B,
         PDATA_BAND1_PR3,
         PDATA_BAND1_PR3A,
         PDATA_BAND1_PT1,
         PDATA_BAND1_PT2,
         PDATA_BAND1_PT2B,
         PDATA_BAND1_PT3,
         PDATA_BAND1_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND1_PR1,
         PDATA2_BAND1_PR2,
         PDATA2_BAND1_PR2B,
         PDATA2_BAND1_PR3,
         PDATA2_BAND1_PR3A,
#endif
         
         /* Band 2 BPI data */
         PDATA_BAND2_PR1,
         PDATA_BAND2_PR2,
         PDATA_BAND2_PR2B,
         PDATA_BAND2_PR3,
         PDATA_BAND2_PR3A,
         PDATA_BAND2_PT1,
         PDATA_BAND2_PT2,
         PDATA_BAND2_PT2B,
         PDATA_BAND2_PT3,
         PDATA_BAND2_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND2_PR1,
         PDATA2_BAND2_PR2,
         PDATA2_BAND2_PR2B,
         PDATA2_BAND2_PR3,
         PDATA2_BAND2_PR3A,
#endif
         
         /* Band 3 BPI data */
         PDATA_BAND3_PR1,
         PDATA_BAND3_PR2,
         PDATA_BAND3_PR2B,
         PDATA_BAND3_PR3,
         PDATA_BAND3_PR3A,
         PDATA_BAND3_PT1,
         PDATA_BAND3_PT2,
         PDATA_BAND3_PT2B,
         PDATA_BAND3_PT3,
         PDATA_BAND3_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND3_PR1,
         PDATA2_BAND3_PR2,
         PDATA2_BAND3_PR2B,
         PDATA2_BAND3_PR3,
         PDATA2_BAND3_PR3A,
#endif
         
         /* Band 4 BPI data */
         PDATA_BAND4_PR1,
         PDATA_BAND4_PR2,
         PDATA_BAND4_PR2B,
         PDATA_BAND4_PR3,
         PDATA_BAND4_PR3A,
         PDATA_BAND4_PT1,
         PDATA_BAND4_PT2,
         PDATA_BAND4_PT2B,
         PDATA_BAND4_PT3,
         PDATA_BAND4_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND4_PR1,
         PDATA2_BAND4_PR2,
         PDATA2_BAND4_PR2B,
         PDATA2_BAND4_PR3,
         PDATA2_BAND4_PR3A,
#endif
         
         /* Band 5 BPI data */
         PDATA_BAND5_PR1,
         PDATA_BAND5_PR2,
         PDATA_BAND5_PR2B,
         PDATA_BAND5_PR3,
         PDATA_BAND5_PR3A,
         PDATA_BAND5_PT1,
         PDATA_BAND5_PT2,
         PDATA_BAND5_PT2B,
         PDATA_BAND5_PT3,
         PDATA_BAND5_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND5_PR1,
         PDATA2_BAND5_PR2,
         PDATA2_BAND5_PR2B,
         PDATA2_BAND5_PR3,
         PDATA2_BAND5_PR3A,
#endif
         
         /* Band 6 BPI data */
         PDATA_BAND6_PR1,
         PDATA_BAND6_PR2,
         PDATA_BAND6_PR2B,
         PDATA_BAND6_PR3,
         PDATA_BAND6_PR3A,
         PDATA_BAND6_PT1,
         PDATA_BAND6_PT2,
         PDATA_BAND6_PT2B,
         PDATA_BAND6_PT3,
         PDATA_BAND6_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND6_PR1,
         PDATA2_BAND6_PR2,
         PDATA2_BAND6_PR2B,
         PDATA2_BAND6_PR3,
         PDATA2_BAND6_PR3A,
#endif
         
         /* Band 7 BPI data */
         PDATA_BAND7_PR1,
         PDATA_BAND7_PR2,
         PDATA_BAND7_PR2B,
         PDATA_BAND7_PR3,
         PDATA_BAND7_PR3A,
         PDATA_BAND7_PT1,
         PDATA_BAND7_PT2,
         PDATA_BAND7_PT2B,
         PDATA_BAND7_PT3,
         PDATA_BAND7_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND7_PR1,
         PDATA2_BAND7_PR2,
         PDATA2_BAND7_PR2B,
         PDATA2_BAND7_PR3,
         PDATA2_BAND7_PR3A,
#endif
         
         /* Band 8 BPI data */
         PDATA_BAND8_PR1,
         PDATA_BAND8_PR2,
         PDATA_BAND8_PR2B,
         PDATA_BAND8_PR3,
         PDATA_BAND8_PR3A,
         PDATA_BAND8_PT1,
         PDATA_BAND8_PT2,
         PDATA_BAND8_PT2B,
         PDATA_BAND8_PT3,
         PDATA_BAND8_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND8_PR1,
         PDATA2_BAND8_PR2,
         PDATA2_BAND8_PR2B,
         PDATA2_BAND8_PR3,
         PDATA2_BAND8_PR3A,
#endif
         
         /* Band 9 BPI data */
         PDATA_BAND9_PR1,
         PDATA_BAND9_PR2,
         PDATA_BAND9_PR2B,
         PDATA_BAND9_PR3,
         PDATA_BAND9_PR3A,
         PDATA_BAND9_PT1,
         PDATA_BAND9_PT2,
         PDATA_BAND9_PT2B,
         PDATA_BAND9_PT3,
         PDATA_BAND9_PT3A,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND9_PR1,
         PDATA2_BAND9_PR2,
         PDATA2_BAND9_PR2B,
         PDATA2_BAND9_PR3,
         PDATA2_BAND9_PR3A,
#endif
         
         /* Band 10 BPI data */
         PDATA_BAND10_PR1,
         PDATA_BAND10_PR2,
         PDATA_BAND10_PR2B,
         PDATA_BAND10_PR3,
         PDATA_BAND10_PR3A,
         PDATA_BAND10_PT1,
         PDATA_BAND10_PT2,
         PDATA_BAND10_PT2B,
         PDATA_BAND10_PT3,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA_BAND10_PT3A,
#else
         PDATA_BAND10_PT3A
#endif
#if defined (__UL1_HS_PLUS_PLATFORM__)
         PDATA2_BAND10_PR1,
         PDATA2_BAND10_PR2,
         PDATA2_BAND10_PR2B,
         PDATA2_BAND10_PR3,
         PDATA2_BAND10_PR3A,
         
         /* Band 11 BPI data */
         PDATA_BAND11_PR1,
         PDATA_BAND11_PR2,
         PDATA_BAND11_PR2B,
         PDATA_BAND11_PR3,
         PDATA_BAND11_PR3A,
         PDATA_BAND11_PT1,
         PDATA_BAND11_PT2,
         PDATA_BAND11_PT2B,
         PDATA_BAND11_PT3,
         PDATA_BAND11_PT3A,
         PDATA2_BAND11_PR1,
         PDATA2_BAND11_PR2,
         PDATA2_BAND11_PR2B,
         PDATA2_BAND11_PR3,
         PDATA2_BAND11_PR3A,
         
         /* Band 19 BPI data */
         PDATA_BAND19_PR1,
         PDATA_BAND19_PR2,
         PDATA_BAND19_PR2B,
         PDATA_BAND19_PR3,
         PDATA_BAND19_PR3A,
         PDATA_BAND19_PT1,
         PDATA_BAND19_PT2,
         PDATA_BAND19_PT2B,
         PDATA_BAND19_PT3,
         PDATA_BAND19_PT3A,
         PDATA2_BAND19_PR1,
         PDATA2_BAND19_PR2,
         PDATA2_BAND19_PR2B,
         PDATA2_BAND19_PR3,
         PDATA2_BAND19_PR3A
#endif
      },

      /* umtsBandIndicator */
      {
         RX_HIGHBAND1_INDICATOR,
         RX_HIGHBAND2_INDICATOR,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         RX_HIGHBAND3_INDICATOR,
#endif
         RX_LOWBAND1_INDICATOR,
         RX_LOWBAND2_INDICATOR
      },

      /* sUl1dRfRxLnaPortSel */
      {
         BAND1_CHANNEL_SEL,
         BAND2_CHANNEL_SEL,
         BAND3_CHANNEL_SEL,
         BAND4_CHANNEL_SEL,
         BAND5_CHANNEL_SEL,
         BAND6_CHANNEL_SEL,
         BAND8_CHANNEL_SEL,
         BAND9_CHANNEL_SEL,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         BAND10_CHANNEL_SEL,
         BAND11_CHANNEL_SEL,
         BAND19_CHANNEL_SEL,
#else
         BAND10_CHANNEL_SEL
#endif
#if defined (__UL1_HS_PLUS_PLATFORM__)
         BAND1_CHANNEL2_SEL,
         BAND2_CHANNEL2_SEL,
         BAND3_CHANNEL2_SEL,
         BAND4_CHANNEL2_SEL,
         BAND5_CHANNEL2_SEL,
         BAND6_CHANNEL2_SEL,
         BAND8_CHANNEL2_SEL,
         BAND9_CHANNEL2_SEL,
         BAND10_CHANNEL2_SEL,
         BAND11_CHANNEL2_SEL,
         BAND19_CHANNEL2_SEL
#endif
      },

      /* umtsTxPathSel */
      {
         BAND1_OUTPUT_SEL,
         BAND2_OUTPUT_SEL,
         BAND3_OUTPUT_SEL,
         BAND4_OUTPUT_SEL,
         BAND5_OUTPUT_SEL,
         BAND6_OUTPUT_SEL,
         BAND8_OUTPUT_SEL,
         BAND9_OUTPUT_SEL,
#if defined (__UL1_HS_PLUS_PLATFORM__)
         BAND10_OUTPUT_SEL,
         BAND11_OUTPUT_SEL,
         BAND19_OUTPUT_SEL
#else
         BAND10_OUTPUT_SEL
#endif
      },

      /* xPMU_PA_CONTROL */
      PMU_PASETTING,

#if defined (__UL1_HS_PLUS_PLATFORM__)
      /* umtsMprBackOff */
      {
         {
            MPR_BACK_OFF_HSDPA_BAND1 , MPR_BACK_OFF_HSDPA_BAND2 , MPR_BACK_OFF_HSDPA_BAND3 , MPR_BACK_OFF_HSDPA_BAND4 , MPR_BACK_OFF_HSDPA_BAND5 ,
            MPR_BACK_OFF_HSDPA_BAND6 , MPR_BACK_OFF_HSDPA_BAND7 , MPR_BACK_OFF_HSDPA_BAND8 , MPR_BACK_OFF_HSDPA_BAND9 , MPR_BACK_OFF_HSDPA_BAND10,
            MPR_BACK_OFF_HSDPA_BAND11, MPR_BACK_OFF_HSDPA_BAND12, MPR_BACK_OFF_HSDPA_BAND13, MPR_BACK_OFF_HSDPA_BAND14, MPR_BACK_OFF_HSDPA_BAND15,
            MPR_BACK_OFF_HSDPA_BAND16, MPR_BACK_OFF_HSDPA_BAND16, MPR_BACK_OFF_HSDPA_BAND17, MPR_BACK_OFF_HSDPA_BAND18, MPR_BACK_OFF_HSDPA_BAND19
         },
         {
            MPR_BACK_OFF_HSUPA_BAND1 , MPR_BACK_OFF_HSUPA_BAND2 , MPR_BACK_OFF_HSUPA_BAND3 , MPR_BACK_OFF_HSUPA_BAND4 , MPR_BACK_OFF_HSUPA_BAND5 ,
            MPR_BACK_OFF_HSUPA_BAND6 , MPR_BACK_OFF_HSUPA_BAND7 , MPR_BACK_OFF_HSUPA_BAND8 , MPR_BACK_OFF_HSUPA_BAND9 , MPR_BACK_OFF_HSUPA_BAND10,
            MPR_BACK_OFF_HSUPA_BAND11, MPR_BACK_OFF_HSUPA_BAND12, MPR_BACK_OFF_HSUPA_BAND13, MPR_BACK_OFF_HSUPA_BAND14, MPR_BACK_OFF_HSUPA_BAND15,
            MPR_BACK_OFF_HSUPA_BAND16, MPR_BACK_OFF_HSUPA_BAND16, MPR_BACK_OFF_HSUPA_BAND17, MPR_BACK_OFF_HSUPA_BAND18, MPR_BACK_OFF_HSUPA_BAND19
         }
      },
      
      /* RxD support bit map*/
      RX_DIVERSITY_ALWAYS_ON,
      
      /* Tx PA dirft compensation bit map*/
      PA_DIRFT_COMPENSATION,

      /*At MT6589+MT6320PMIC, Vrf18_1(MD1) can use bulk/LDO mode, this is the switch*/
      ULTRA_LOW_COST_EN,
      
      /*At MT6589/MT6280+OrionRF, temperature measurement enable switch */
      TEAMPERATURE_MEAS_EN,
#endif
      
      /* End Pattern */
      0x0, /* can't use special pattern here */
   }
};


U_sUl1IotCustomSupportStruct const COMMON_NVRAM_EF_UL1_IOT_CUSTOMIZATION_DEFAULT[NVRAM_EF_UL1_IOT_CUSTOMIZATION_TOTAL]=
{
   {
      KAL_FALSE,    /* ADAPT Customization */
      KAL_FALSE,    /* reserved1 */
      KAL_FALSE,    /* reserved2 */
      KAL_FALSE     /* reserved3 */
   }
};

#endif /* #if defined (__MTK_UL1_FDD__) */
#endif /* #if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__) */

#if defined (__UL1_HS_PLUS_PLATFORM__) || defined (__UL1_HS_PLATFORM__) 
nvram_ef_ul1_hspa_category_struct const COMMON_NVRAM_EF_UL1_HSPA_CATEGORY_DEFAULT[NVRAM_EF_UL1_HSPA_CATEGORY_TOTAL]=
{
   {24, 7}
};
#endif

#if defined (__UL1_PLATFORM__)
#if defined (__MTK_UL1_FDD__)
nvram_ef_ul1_rf_custpack_data_select_struct const COMMON_NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_DEFAULT[NVRAM_EF_UL1_RF_CUSTPACK_DATA_SELECT_TOTAL]=
{
    {1}
};

#include "ul1d_custom_rf.h"
#define MAX_AB(a,b) (a>b)? a : b
#define MIN_AB(a,b) (a<b)? a : b
nvram_ef_ul1_rf_custom_data_struct const COMMON_NVRAM_EF_UL1_RF_CUSTOM_DATA_DEFAULT[NVRAM_EF_UL1_RF_CUSTOM_DATA_TOTAL]=
{
    /* Default Band 1/2/5 */

    {
        /* Timing advance and postpone of RF window */
        MAX_AB(TC_SR1, TC_PR1),
        MAX_AB(TC_ST1, TC_PT1),
        MIN_AB(TC_SR3, TC_PR3),
        MIN_AB(TC_ST3, TC_PT3),
        /* Timing of PA control */
        MAX_OFFSET,
        (MAX_OFFSET - VM_OFFSET),
        (MAX_OFFSET - VBIAS_OFFSET),
        (MAX_OFFSET - DC2DC_OFFSET),
        (MAX_OFFSET - VGA_OFFSET),
        /* PA section usage */
        PA_SECTION,
        /* RF T/RX timing offset table */
        {
           -TC_SR1,
           -TC_SR2,
           -TC_SR2B,
           -TC_PR1,
           -TC_PR2,
           -TC_PR2B
        },
        {
           TC_SR3,
           TC_PR3,
           TC_PR3A
        },
        {
           -TC_ST1,
           -TC_ST2,
           -TC_ST2B,
           -TC_PT1,
           -TC_PT2,
           -TC_PT2B,
           0,
           0
        },
        {
           TC_ST3,
           TC_PT3,
           TC_PT3A,
           0,
           0
        },
        /* BPI data allocation */
        {
           {  /* FrequencyBand1  */
              {  PDATA_BAND1_PR1, PDATA_BAND1_PR2, PDATA_BAND1_PR2B, PDATA_BAND1_PR3, PDATA_BAND1_PR3A  } ,        /* RX */
              {  PDATA_BAND1_PT1, PDATA_BAND1_PT2, PDATA_BAND1_PT2B, PDATA_BAND1_PT3, PDATA_BAND1_PT3A  } ,        /* TX */
           }, /* FrequencyBand1  */
           {  {  PDATA_BAND1_PR1, PDATA_BAND1_PR2, PDATA_BAND1_PR2B, PDATA_BAND1_PR3, PDATA_BAND1_PR3A  } ,        /* RX */
              {  PDATA_BAND1_PT1, PDATA_BAND1_PT2, PDATA_BAND1_PT2B, PDATA_BAND1_PT3, PDATA_BAND1_PT3A  } ,        /* TX */
           }, /* FrequencyBand2  */
           {  {  PDATA_BAND2_PR1, PDATA_BAND2_PR2, PDATA_BAND2_PR2B, PDATA_BAND2_PR3, PDATA_BAND2_PR3A  } ,        /* RX */
              {  PDATA_BAND2_PT1, PDATA_BAND2_PT2, PDATA_BAND2_PT2B, PDATA_BAND2_PT3, PDATA_BAND2_PT3A  } ,        /* TX */
           }, /* FrequencyBand3 */
           {  {  PDATA_BAND3_PR1, PDATA_BAND3_PR2, PDATA_BAND3_PR2B, PDATA_BAND3_PR3, PDATA_BAND3_PR3A  } ,        /* RX */
              {  PDATA_BAND3_PT1, PDATA_BAND3_PT2, PDATA_BAND3_PT2B, PDATA_BAND3_PT3, PDATA_BAND3_PT3A  } ,        /* TX */
           }, /* FrequencyBand4 */
           {  {  PDATA_BAND4_PR1, PDATA_BAND4_PR2, PDATA_BAND4_PR2B, PDATA_BAND4_PR3, PDATA_BAND4_PR3A  } ,        /* RX */
              {  PDATA_BAND4_PT1, PDATA_BAND4_PT2, PDATA_BAND4_PT2B, PDATA_BAND4_PT3, PDATA_BAND4_PT3A  } ,        /* TX */
           }, /* FrequencyBand5  */
           {  {  PDATA_BAND5_PR1, PDATA_BAND5_PR2, PDATA_BAND5_PR2B, PDATA_BAND5_PR3, PDATA_BAND5_PR3A  } ,        /* RX */
              {  PDATA_BAND5_PT1, PDATA_BAND5_PT2, PDATA_BAND5_PT2B, PDATA_BAND5_PT3, PDATA_BAND5_PT3A  } ,        /* TX */
           }, /* FrequencyBand6 */
           {  {  PDATA_BAND6_PR1, PDATA_BAND6_PR2, PDATA_BAND6_PR2B, PDATA_BAND6_PR3, PDATA_BAND6_PR3A  } ,        /* RX */
              {  PDATA_BAND6_PT1, PDATA_BAND6_PT2, PDATA_BAND6_PT2B, PDATA_BAND6_PT3, PDATA_BAND6_PT3A  } ,        /* TX */
           }, /* FrequencyBand7 */
           {  {  PDATA_BAND7_PR1, PDATA_BAND7_PR2, PDATA_BAND7_PR2B, PDATA_BAND7_PR3, PDATA_BAND7_PR3A  } ,        /* RX */
              {  PDATA_BAND7_PT1, PDATA_BAND7_PT2, PDATA_BAND7_PT2B, PDATA_BAND7_PT3, PDATA_BAND7_PT3A  } ,        /* TX */
           }, /* FrequencyBand8  */
           {  {  PDATA_BAND8_PR1, PDATA_BAND8_PR2, PDATA_BAND8_PR2B, PDATA_BAND8_PR3, PDATA_BAND8_PR3A  } ,        /* RX */
              {  PDATA_BAND8_PT1, PDATA_BAND8_PT2, PDATA_BAND8_PT2B, PDATA_BAND8_PT3, PDATA_BAND8_PT3A  } ,        /* TX */
           }, /* FrequencyBand9 */
           {  {  PDATA_BAND9_PR1, PDATA_BAND9_PR2, PDATA_BAND9_PR2B, PDATA_BAND9_PR3, PDATA_BAND9_PR3A  } ,        /* RX */
              {  PDATA_BAND9_PT1, PDATA_BAND9_PT2, PDATA_BAND9_PT2B, PDATA_BAND9_PT3, PDATA_BAND9_PT3A  } ,        /* TX */
           }, /* FrequencyBand10 */
           {  {  PDATA_BAND10_PR1, PDATA_BAND10_PR2, PDATA_BAND10_PR2B, PDATA_BAND10_PR3, PDATA_BAND10_PR3A  } ,   /* RX */
              {  PDATA_BAND10_PT1, PDATA_BAND10_PT2, PDATA_BAND10_PT2B, PDATA_BAND10_PT3, PDATA_BAND10_PT3A  } ,   /* TX */
           }
        },
        /* DC2DC level and VM setting table */
        {
           DC2DC_H,
           DC2DC_M,
           DC2DC_L
        },
        {
           VM_H,
           VM_M,
           VM_L
        },
        /* RF Hign-band and Low-band receivers configurations */
        UMTSBand1,
        UMTSBand2,
        UMTSBand5
    }
};

#endif /* #if defined (__MTK_UL1_FDD__) */

#endif /* #if defined (__UL1_PLATFORM__) */

#define NVRAM_INTERNAL_USE

/* nvram default decleartion start */
#if defined(__NVRAM_COMPRESS_SUPPORT__) && !defined(NVRAM_AUTO_GEN)
    #include "nvram_cust_pack_default_value.c"
#else
    #if defined(__MMI_FMI__)
        #include "nvram_common_custpack.c"
        #include "nvram_user_custpack.c"
        #if defined(NEPTUNE_MMI)
            #include "nvram_mmi_cache_cust_pack.h"
        #endif
        #if !defined(NVRAM_AUTO_GEN)
        #include "nvram_custpack_table.c"
        #endif
    #endif  /* __MMI_FMI__ */
#endif /* __NVRAM_COMPRESS_SUPPORT__ */

#undef NVRAM_INTERNAL_USE

#endif /* !defined(NVRAM_NOT_PRESENT) && !defined(__L1_STANDALONE__) */

