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
 * custom_nvram_sec.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This file is intends for NVRAM security customization.
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
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
 * removed!
 * removed!
 *
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
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef CUSTOM_NVRAM_SEC_H
#define CUSTOM_NVRAM_SEC_H

#include "kal_general_types.h"

/* for MS_SECURITY */
#define NVRAM_EDITOR_NUM_OF_BYTE_KEY   8
#define NVRAM_EDITOR_NUM_OF_BYTE_NP    3
//#define NVRAM_EDITOR_NUM_NP            3
#define NVRAM_EDITOR_NUM_OF_BYTE_NSP   5
#define NVRAM_EDITOR_NUM_NSP           3
#define NVRAM_EDITOR_NUM_GID           20
#define NVRAM_EDITOR_NUM_OF_BYTE_IMSI  9
#define NVRAM_EDITOR_NUM_PIN1          8
#define NVRAM_EDITOR_NUM_OF_BYTE_ICCID  10

typedef struct
{
    kal_uint8 security_indication;
    kal_uint8 phone_key[NVRAM_EDITOR_NUM_OF_BYTE_KEY];
    kal_uint8 last_imsi[NVRAM_EDITOR_NUM_OF_BYTE_IMSI];
    kal_uint8 pin1[NVRAM_EDITOR_NUM_PIN1];
    kal_uint8 pin1_valid;
    kal_uint8 phone_lock_verified;
    kal_uint8 iccid[NVRAM_EDITOR_NUM_OF_BYTE_ICCID];
} smu_security_info_struct;

/* --------------------------
 * Beginning of SML Configuration
 * --------------------------- */
#define NVRAM_SECRET_KEY_SIZE 		8
#define NVRAM_DATABASE_KEY_SIZE     64  /* must be multiple of 16 */

/*
 * the basic unit of categories
 */
#define SML_SIZE_OF_CAT_N      3 /* MCC/MNC */
#define SML_SIZE_OF_CAT_NS     4 /* MCC/MNC + HLR */
#define SML_SIZE_OF_CAT_SP     4 /* MCC/MNC + GID1 */
#define SML_SIZE_OF_CAT_C      5 /* MCC/MNC + GID1 + GID2 */
#define SML_SIZE_OF_CAT_SIM    8 /* IMSI */
/* Define the maximum suppot categories */
#define SML_MAX_SUPPORT_CAT_N       10
#define SML_MAX_SUPPORT_CAT_NS     2
#define SML_MAX_SUPPORT_CAT_SP     2
#define SML_MAX_SUPPORT_CAT_C       2
#define SML_MAX_SUPPORT_CAT_SIM     2
/* Define the total size of each category */
#define SML_CFG_CAT_N_SIZE          (SML_MAX_SUPPORT_CAT_N * SML_SIZE_OF_CAT_N)
#define SML_CFG_CAT_NS_SIZE         (SML_MAX_SUPPORT_CAT_NS * SML_SIZE_OF_CAT_NS)
#define SML_CFG_CAT_SP_SIZE         (SML_MAX_SUPPORT_CAT_SP * SML_SIZE_OF_CAT_SP)
#define SML_CFG_CAT_C_SIZE          (SML_MAX_SUPPORT_CAT_C * SML_SIZE_OF_CAT_C)
#define SML_CFG_CAT_SIM_SIZE        (SML_MAX_SUPPORT_CAT_SIM * SML_SIZE_OF_CAT_SIM)
/* Define the support category size */
#define SML_SUPPORT_CAT_SIZE    7 /* SML_CAT_SIZE in sml_cat_enum */

/*
 * Key management behavior
 *
 * the maximum control key length in bcd, i.e., double in digits
 * this value shall not be smaller than MAX_SIM_PASSWD_LEN-1, which is the maximum length of PIN
 */
#ifdef __EXTEND_SML_KEY_LEN__
#define SML_MAX_SUPPORT_KEY_LEN     16
#else
#define SML_MAX_SUPPORT_KEY_LEN     8 /* in byte */
#endif


/*
 * Linked Category Support
 */
#define SML_SIZE_OF_LINK_NS_SP          5  /* MCC/MNC + HLR+ GID1 */
#define SML_SIZE_OF_LINK_SIM_C          10 /* IMSI + GID1 + GID2 */
/* Define the maximum support num of categories */
#define SML_MAX_SUPPORT_LINK_NS_SP      2
#define SML_MAX_SUPPORT_LINK_SIM_C      2
/* define the total size of link category */
#define SML_CFG_CAT_NS_SP_SIZE          (SML_SIZE_OF_LINK_NS_SP * SML_MAX_SUPPORT_LINK_NS_SP)
#define SML_CFG_CAT_SIM_C_SIZE          (SML_SIZE_OF_LINK_SIM_C * SML_MAX_SUPPORT_LINK_SIM_C)

/*
 * Range Support
 */
#define SML_CAT_NS_RANGE_SIZE           2   /* ex: 00FF 0~255 for HLR */

/*
 * Automatically Lock
 */
#define SML_AUTOLOCK_NUM_N_CATEGORY     SML_MAX_SUPPORT_N_CAT
#define SML_AUTOLOCK_NUM_NS_CATEGORY    SML_MAX_SUPPORT_NS_CAT
#define SML_AUTOLOCK_NUM_SP_CATEGORY    SML_MAX_SUPPORT_SP_CAT
#define SML_AUTOLOCK_NUM_C_CATEGORY     SML_MAX_SUPPORT_C_CAT
#define SML_AUTOLOCK_NUM_SIM_CATEGORY   SML_MAX_SUPPORT_SIM_CAT

/*
 * Maximum Retry Count
 */
#define SML_MAX_RETRY_COUNT             5
#define SML_RETRY_TIMEOUT               3 /* in sec */
#define SML_RETRY_COUNT_N_CAT           SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_NS_CAT          SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_SP_CAT          SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_C_CAT           SML_MAX_RETRY_COUNT
#define SML_RETRY_COUNT_SIM_CAT         SML_MAX_RETRY_COUNT

// TMO SML

#include "cust_chl_interface.h"

/* The following size are referend from TMO SIM lock blob format */
#define SML_TMO_SIZE_OF_VERSION             4
#define SML_TMO_SIZE_OF_LENGTH              2
#define SML_TMO_SIZE_OF_MCC_MNC             4
#define SML_TMO_SIZE_OF_GID                 2
#define SML_TMO_SIZE_OF_MCC_MNC_GID         6
#define SML_TMO_SIZE_OF_RESERVED            2
#define SML_TMO_SIZE_OF_START_TIME          8
#define SML_TMO_SIZE_OF_END_TIME            4
#define SML_TMO_SIZE_OF_VERIFICATION_CODE   256

#define SML_TMO_SIZE_OF_MAC                 32
#define SML_TMO_SIZE_OF_SIGNATURE           256

#define SML_TMO_MAX_SLB_SIZE                NVRAM_EF_SIM_LOCK_SIZE

/* Invalid SML context obj length */
#define SML_TMO_INVALID_CONTEXT_OBJ_LENGTH  0xFFFF

#define SML_TMO_MAX_SHARED_KEY_LENGTH       MAX_CUST_CHL_SYM_KEY_LEN
#define SML_TMO_MAX_ENCRYPTED_KEY_LENGTH    MAX_CUST_CHL_ASYM_KEY_LEN

#define SML_TMO_NVRAM_ACCESS_ID_UPDATE_VERIFICATION_CODE  0xFD
#define SML_TMO_NVRAM_ACCESS_ID_UPDATE_SLB                0xFC
#define SML_TMO_NVRAM_ACCESS_ID_RESET_SLB                 0xFB
#define SML_TMO_NVRAM_ACCESS_ID_TEMP_UNLOCK_EXPIRE        0xFA

#define SML_TMO_TIMEOUT_PERIODIC_CHECK      (KAL_TICKS_1_SEC*10)//(12*60*KAL_TICKS_1_MIN)     /* 12 hours */

#define SML_TMO_TIMER_INDEX_PERIODIC_CHECK          0x01

typedef struct {
    kal_uint8   version[SML_TMO_SIZE_OF_VERSION];                       /* 4 */
    kal_uint8   protection_scheme;                                      /* 1 */
    kal_uint8   state;                                                  /* 1 */
    kal_uint8   length[SML_TMO_SIZE_OF_LENGTH];                         /* 2 */
    kal_uint8   mcc_mnc_gid[SML_TMO_SIZE_OF_MCC_MNC_GID];               /* 6 */
    kal_uint8   reserved[SML_TMO_SIZE_OF_RESERVED];                     /* 2 */
    kal_uint8   start_time[SML_TMO_SIZE_OF_START_TIME];                 /* 8 */
    kal_uint8   end_time[SML_TMO_SIZE_OF_END_TIME];                     /* 4 */
    kal_uint8   verification_code[SML_TMO_SIZE_OF_VERIFICATION_CODE];   /* 256 */
} sml_tmo_context_struct;                                            /* 284 */
typedef sml_tmo_context_struct nvram_sml_tmo_context_struct;



/* General control key structure */
typedef struct {
    kal_uint8 state;    /* Default Value or NULL */
    kal_uint8 key[SML_MAX_SUPPORT_KEY_LEN];
} sml_control_key_struct;

/* General lock structure */
typedef struct {
    kal_uint8 state;                    /* sml_state_enum */
    kal_uint8 retry_count;              /* SML_RETRY_COUNT_X_CAT */
    kal_uint8 autolock_count;           /* SML_AUTOLOCK_NUM_X_CAT */
    kal_uint8 num;                      /* num of valid sets */
} sml_category_meta_struct;

typedef struct {
    kal_uint32  magic_head;                                 /* 4 */
    sml_category_meta_struct    cat[SML_SUPPORT_CAT_SIZE];  /* (4 * 7) */
    sml_control_key_struct      key[SML_SUPPORT_CAT_SIZE];  /* (9 * 7) */
    kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];             /* (30 * 3)*/
    kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];           /* (30 * 4)*/
    kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];           /* (30 * 4)*/
    kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];             /* (30 * 5)*/
    kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];         /* (30 * 8)*/
    kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];     /* (5 * 10)*/
    kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];     /* (10 * 10)*/
    kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE];        /* 2 */
    kal_uint32 magic_tail;                                  /* 4 */
} sml_context_struct;                                       /* 971 */
typedef sml_context_struct nvram_sml_context_struct;


/* the magic number of file header and tail */
#define SML_MAGIC_HEAD_VALUE            (sizeof(sml_context_struct))
#define SML_MAGIC_TAIL_VALUE              0x26598088

/* the SML flags */
#define SML_FLAG_CAT_N             0x01
#define SML_FLAG_CAT_NS            0x02
#define SML_FLAG_CAT_SP            0x04
#define SML_FLAG_CAT_C             0x08
#define SML_FLAG_CAT_SIM           0x10
/* --------------------------
 * End of SML Configuration
 * --------------------------- */

#if !defined(NVRAM_NOT_PRESENT)
#ifdef __cplusplus
extern "C"
{
#endif /* __cplusplus */

#ifdef __SECURE_RO_ENABLE__
#include "nvram_lid_statistics.h"
#endif
#include "nvram_defs.h" /* NVRAM_MSP_ALIGNMENT */

/*
 * CUST PARA Configuration
 */
#ifdef __CUST_PARA_SUPPORT__
typedef struct {
	kal_uint8	dummy[4096]; /* defined by customer */
} CustPara_ST;
#endif


/*
 * Secure RO Version
 * Whenever nvram_sml_context_struct's size or members are changed,
 * be sure to assign an unique version number to SEC_RO_STRUCT_VER.
 * Otherwise, PC side tool has no idea how to compose it
 */
#ifndef __SECURE_USB_DOWNLOAD__
#define SEC_RO_STRUCT_VER		  1
#else
#define SEC_RO_STRUCT_VER		  2
#endif

/*
 * Secure RO
 */
typedef enum
{
    SEC_RO_PARA_DBG_PORT,
    SEC_RO_PARA_TOTAL
}sec_ro_para_enum;

typedef struct
{
    kal_uint8  m_custom_database_key[NVRAM_DATABASE_KEY_SIZE];
    /* -------- custom can add other secret data here ------------------- */


    /* please do not remove this member, to support AES 16 byte alignment */
    kal_uint32 padding[NVRAM_MSP_ALIGNMENT>>2];
} CUST_SECRET_DATA_ST;


#ifdef __SECURE_RO_ENABLE__

#define NVRAM_SECRET_KEY_MAX_SIZE	128

#ifdef __SECURE_USB_DOWNLOAD__

#define  M1_MAX_KEY_LEN             128

typedef struct t_Customer_Public_Key
{
   kal_uint32 nELen;
   kal_uint32 nNLen;
   kal_uint16 MCoeff;
   kal_uint16 nCutLength;
   kal_uint16 E_Key[M1_MAX_KEY_LEN];
   kal_uint16 N_Key[M1_MAX_KEY_LEN]; /* 256, 512, 1024 bit */
} T_Customer_Public_Key;

#define NVRAM_ASYMMETRIC_KEY_MAX_SIZE	sizeof(T_Customer_Public_Key)
#define SEC_RO_MAGIC_HEAD_VALUE         (0x26598088)
#define SEC_RO_MAGIC_TAIL_LEN			16
#define SEC_RO_MAGIC_TAIL_VALUE		"MTK_SEC_RO_TAIL"
#endif /* __SECURE_USB_DOWNLOAD__ */

typedef struct
{

    /* --- FIXED section BEGIN ----------------------------------------------- */

    /* NOTICE!! This section is FIXED. */
    /* DO NOT delete any member, add new member or change data type and size. */

    /* a unique version to identify SEC_RO_T structure layout */
    kal_uint32 m_sec_ro_ver;

    /* custom secret key */
    kal_uint8  m_custom_secret_key[NVRAM_SECRET_KEY_SIZE];

    /* custom secret key len */
    kal_uint32 m_custom_secret_key_len;

    kal_uint8  m_custom_para[SEC_RO_PARA_TOTAL];

    kal_uint8  m_custom_secupack[NVRAM_SECUPACK_SIZE];

#ifdef __SECURE_USB_DOWNLOAD__

    /*  Please do not remove this field, or the USB download would fail
        1. make m_custom_symmetric_key is 4 byte aglinment
        2. secure checking */
    kal_uint32 m_custom_magic_head;

    /* custom symmetric key */
    kal_uint8 m_custom_symmetric_key[NVRAM_SECRET_KEY_MAX_SIZE];

    /* custom symmetric key len */
    kal_uint32 m_custom_symmetric_key_len;

    /* custom asymmetric key */
    T_Customer_Public_Key m_custom_asymmetric_key;

    /* custom asymmetric key len */
    kal_uint32 m_custom_asymmetric_key_len;

    /* Secure RO magic tail */
    kal_uint8  m_custom_magic_tail[SEC_RO_MAGIC_TAIL_LEN];
#endif /* __SECURE_USB_DOWNLOAD__ */

    /* --- FIXED section END -------------------------------------------------*/

    /* please do not remove this member, to support AES 16 byte alignment */
    kal_uint8 padding[NVRAM_MSP_ALIGNMENT];

} SEC_RO_ST;

#endif /* __SECURE_RO_ENABLE__ */

#if !defined(__SECURE_RO_ENABLE__)
extern const kal_uint8 NVRAM_SECUPACK_DEFAULT[];
extern const kal_uint8 NVRAM_CUSTOM_KEY[];
#endif /* !__SECURE_RO_ENABLE__ */
extern kal_uint32 secupack_total_to_verify;
extern void custom_nvram_get_key(char *init_key, unsigned char *keys);
extern void custom_nvram_encrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex);
extern void custom_nvram_decrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex);

extern kal_uint32 custom_nvram_sec_ro_size(void);
extern kal_uint32 custom_nvram_secupack_size(void);
extern kal_uint32 custom_nvram_secupack_total(void);
extern kal_uint32 custom_nvram_key_len(void);
extern kal_int32 custom_nvram_get_database_key(kal_uint8 *key_buffer, kal_uint32 buffer_size);

#if defined(NVRAM_AUTO_GEN)
extern const nvram_sml_context_struct NVRAM_EF_SML_DEFAULT;
extern const nvram_sml_tmo_context_struct NVRAM_EF_SML_TMO_DEFAULT;
extern const kal_uint8 custom_secret_key[];
extern const CUST_SECRET_DATA_ST custom_secret_data;
extern const kal_uint8 NVRAM_SECURE_PARA[];
#ifdef __SECURE_USB_DOWNLOAD__
extern const kal_uint8 custom_symmetric_key[];
extern const T_Customer_Public_Key custom_asymmetric_key;
#endif
#endif


#ifdef __cplusplus
}
#endif
#endif /* !defined(NVRAM_NOT_PRESENT) */
#endif /* CUSTOM_NVRAM_SEC_H */

