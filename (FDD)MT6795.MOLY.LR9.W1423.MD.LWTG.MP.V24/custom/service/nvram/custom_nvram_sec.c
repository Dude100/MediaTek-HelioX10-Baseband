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
 * custom_nvram_sec.c
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#if !defined(NVRAM_NOT_PRESENT)

#include <string.h>
#include <stdio.h>

#include "kal_general_types.h"
#include "custom_nvram_sec.h"

#ifdef __NVRAM_SECRET_DATA__
#include "kal_public_api.h"
#endif

#include "nvram_lid_statistics.h"       /* NVRAM_SECUPACK_SIZE */

#ifndef __OPTR_NONE__
#include "op_custom_nvram_sec.h"
#endif

extern kal_bool SST_Get_NVRAM_Key(kal_uint32 *p_key, kal_uint32 *p_addr, kal_uint32 *p_len);
/*
 * CUST PARA Configuration                                                 
 */ 
#ifdef __CUST_PARA_SUPPORT__

/* WARNING!! DO NOT remove g_CustParaCfg or modify its name */

__attribute__((section("CUST_PARA"))) const CustPara_ST g_CustParaCfg=
{
    0xFF
};

/* WARNING!! DO NOT remove g_CustParaCfg_Tail or modify its name */
__attribute__((section("CUST_PARA_TAIL"))) kal_uint32  g_CustParaCfg_Tail;
#endif /* __CUST_PARA_SUPPORT__ */

#ifdef __NVRAM_SECRET_DATA__
/* Please do not modify this */
#define SECRET_DATA_PADDING_PATTERN  {0XE9A4B5A4, 0XEBB973A4, 0XE9A4FAA9, 0X79AC44A5}

/********************************************************************************
 *  This structure will be protected by chip dependent algorithm
 *************************************************************/
// __attribute__((section("PRIMARY_RODATA")))
const CUST_SECRET_DATA_ST custom_secret_data =
{
    /*  This key is used to encrypt the data transfered between metatool and target.
        We suggest custom must change this key and make it secretly if possible.  */
    {
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
        0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
    },
    /* ------ Custom can add other secret data here -----*/

    /* please do not remove this member or modify it, to support AES 16 byte alignment */
    SECRET_DATA_PADDING_PATTERN
};

#endif

#if defined(NVRAM_AUTO_GEN)

#include "custom_nvram_extra.h" /* SML_STATE_UNLOCK */

/********************************************************************************
 *  This key is used to encrypt (software) the data with NVRAM_ATTR_CONFIDENTIAL
 *  in NVRAM , we suggest custom must change this key and make it secretly if possible
 *************************************************************/
const kal_uint8 custom_secret_key[NVRAM_SECRET_KEY_SIZE] = {0x31, 0x32, 0x61, 0x62, 0x63, 0x64, 0x65, 0x66};

const kal_uint8 NVRAM_SECURE_PARA[SEC_RO_PARA_TOTAL] =
{
    0x01
};


#ifdef __SECURE_USB_DOWNLOAD__
const kal_uint8 custom_symmetric_key[NVRAM_SECRET_KEY_MAX_SIZE] =
{
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x0C, 0x0D, 0x0E, 0x0F
};
const T_Customer_Public_Key custom_asymmetric_key =
{
    2, 64, 0x0051, 8,
    {0x0001, 0x0001},
    {
        0x002A, 0x178D, 0xBCB4, 0xC985, 0xD21E, 0x2A71, 0xDBE4, 0x1E27, 
        0x29CD, 0x2285, 0x65B3, 0x6596, 0x2B4C, 0x8266, 0x057B, 0xB911, 
        0x283D, 0x1912, 0xB02D, 0x2B15, 0xB61D, 0x8DB9, 0xC1D9, 0x069C, 
        0xA352, 0xD7F6, 0x0EAB, 0x46EB, 0xB0CE, 0xAEC5, 0x842C, 0x92B1, 
        0x94FC, 0xD410, 0x60F5, 0x8F2C, 0x186A, 0x9527, 0xF40A, 0x4DF9, 
        0xA31D, 0x86C0, 0x7464, 0xB57C, 0x600A, 0xB37A, 0x02FB, 0xD0A6, 
        0x6399, 0xB779, 0x96A7, 0x9B5E, 0x2E8D, 0x0247, 0xA844, 0x28EE, 
        0x26B6, 0xAF64, 0x7C49, 0xC924, 0xD8DF, 0x5FBA, 0xEBAA, 0xB74F
    }
};
#endif /* __SECURE_USB_DOWNLOAD__ */

/*
 * typedef struct {
 *      kal_uint32  magic_head;                                 -> 4
 *      sml_category_meta_struct    cat[SML_SUPPORT_CAT_SIZE];  -> ( 4 *  7)
 *      sml_control_key_struct      key[SML_SUPPORT_CAT_SIZE];  -> ( 9 *  7)
 *      kal_uint8   code_cat_n[SML_CFG_CAT_N_SIZE];             -> (30 *  3)
 *      kal_uint8   code_cat_ns[SML_CFG_CAT_NS_SIZE];           -> (30 *  4)
 *      kal_uint8   code_cat_sp[SML_CFG_CAT_SP_SIZE];           -> (30 *  4)
 *      kal_uint8   code_cat_c[SML_CFG_CAT_C_SIZE];             -> (30 *  5)
 *      kal_uint8   code_cat_sim[SML_CFG_CAT_SIM_SIZE];         -> (30 *  8)
 *      kal_uint8   code_cat_ns_sp[SML_CFG_CAT_NS_SP_SIZE];     -> ( 5 * 10)
 *      kal_uint8   code_cat_sim_c[SML_CFG_CAT_SIM_C_SIZE];     -> (10 * 10)
 *      kal_uint8   range_cat_ns[SML_CAT_NS_RANGE_SIZE];        -> 2
 *      kal_uint32 magic_tail;                                  -> 4
 *  } sml_context_struct;                                       -> 971
 */

const nvram_sml_context_struct NVRAM_EF_SML_DEFAULT = 
{       
        SML_MAGIC_HEAD_VALUE, 
    #ifdef CUSTOM_SML_DEFAULT
         CUSTOM_SML_DEFAULT
    #else /* CUSTOM_SML_DEFAULT */
        {{SML_STATE_UNLOCK,SML_RETRY_COUNT_N_CAT,0,0},     /* Category N */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_NS_CAT ,0,0},   /* Category NS */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_SP_CAT ,0,0},   /* Category SP */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_C_CAT ,0,0},    /* Category C */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_SIM_CAT ,0,0},  /* Category SIM */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_NS_CAT ,0,0},   /* Link NS-SP */
        {SML_STATE_UNLOCK,SML_RETRY_COUNT_C_CAT ,0,0}},    /* Link SIM-C */
        {{SML_KEY_EMPTY,{0x21,0x43,0x65,0x87,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x65,0x87,0x21,0x43,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x11,0x11,0x22,0x22,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x33,0x33,0x44,0x44,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x55,0x55,0x66,0x66,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x77,0x77,0x88,0x88,0xFF,0xFF,0xFF,0xFF}},
        {SML_KEY_EMPTY,{0x99,0x99,0x00,0x00,0xFF,0xFF,0xFF,0xFF}}},
        /* Category N code */
        {0xc1,0xc1,0xc1,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF,
         0xFF,0xFF,0xFF},	
        /* Category NS code */
        {0xc2,0xc2,0xc2,0xc2,
         0xFF,0xFF,0xFF,0xFF},
        /* Category SP code */
        {0xc3,0xc3,0xc3,0xc3,
         0xFF,0xFF,0xFF,0xFF},
        /* Category C code */
        {0xc4,0xc4,0xc4,0xc4,0xc4,
         0xFF,0xFF,0xFF,0xFF,0xFF},
        /* Category SIM code */
        {0xc5,0xc5,0xc5,0xc5,0xc5,0xc5,0xc5,0xc5,
         0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},
        /* Link Category NS-SP */
        {0xc6,0xc6,0xc6,0xc6,0xc6,
         0xFF,0xFF,0xFF,0xFF,0xFF},
        /* Link Category SIM-C */
        {0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,0xc7,
         0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF},        
         /* NS Range size */
        {0xFF,0xFF},
    #endif /* CUSTOM_SML_DEFAULT */
        SML_MAGIC_TAIL_VALUE        
};

const nvram_sml_tmo_context_struct NVRAM_EF_SML_TMO_DEFAULT = 
{       
         {0x00,0x01,0x00,0x00},                             /* version */
         SML_PROTECTION_SCHEME_HMAC_SHA256,                 /* protection scheme */
         SML_TMO_STATE_PERMANENT_LOCK,                          /* state */
         {0x00, 0x3C},                                      /* length (60) */
         {0x31,0x02,0x60,0x00,0x54,0x4D},                   /* MCC/MNC/GID */
         {0,0},                                             /* reserved */
         {0,0,0,0,0,0,0,0},                                 /* start time */
         {0,0,0,0},                                         /* end time */
         {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,   /* MAC or signature */
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
          0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
};


/* --Boundry - Custom SecuPack Default Values--  */

/* --Boundry - Custom SecuPack Default Values--  */

#else /* NVRAM_AUTO_GEN */

#include "nvram_sec.h"

/*
 * Local variable
 */
static int X;
static int hashIndex = 0;

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_sec_ro_size
 * DESCRIPTION
 *  
 * PARAMETERS
 *  void
 * RETURNS
 *  
 *****************************************************************************/
kal_uint32 custom_nvram_sec_ro_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
#ifdef __SECURE_RO_ENABLE__    
    return sizeof(SEC_RO_ST);
#else
    return 0;
#endif
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_sec_ro_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint32 custom_nvram_secupack_size(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NVRAM_SECUPACK_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_secupack_total
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint32 custom_nvram_secupack_total(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NVRAM_SECUPACK_TOTAL;
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_sec_ro_size
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
kal_uint32 custom_nvram_key_len(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    return NVRAM_SECRET_KEY_SIZE;
}

/*****************************************************************************
 * FUNCTION
 *  IV_generator
 * DESCRIPTION
 *
 * PARAMETERS
 *  void
 * RETURNS
 *
 *****************************************************************************/
int custom_nvram_IV_generator(void)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    /*
     * f(x)=A*|X-B|+C
     * if(X>B)
     * hashIndex = (A*(X-B)+C)%256;
     * else
     * hashIndex = (A*(B-X)+C)%256;
     */
    return hashIndex;
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_get_key
 * DESCRIPTION
 *  
 * PARAMETERS
 *  init_key        [?]     
 *  keys            [?]     
 * RETURNS
 *  void
 *****************************************************************************/
void custom_nvram_get_key(char *init_key, unsigned char *keys)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    nvram_get_key(init_key, keys);
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_encrypt
 * DESCRIPTION
 *  
 * PARAMETERS
 *  keys                [?]         
 *  buffer              [?]         
 *  length              [IN]        
 *  scrambleIndex       [IN]        
 * RETURNS
 *  void
 *****************************************************************************/
void custom_nvram_encrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    X = scrambleIndex;
    nvram_encrypt(keys, buffer, length, custom_nvram_IV_generator);
}


/*****************************************************************************
 * FUNCTION
 *  custom_nvram_decrypt
 * DESCRIPTION
 *
 * PARAMETERS
 *  keys                [?]
 *  buffer              [?]
 *  length              [IN]
 *  scrambleIndex       [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void custom_nvram_decrypt(unsigned char const *keys, unsigned char *buffer, unsigned int length, int scrambleIndex)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    X = scrambleIndex;
    nvram_decrypt(keys, buffer, length, custom_nvram_IV_generator);
}

/*****************************************************************************
 * FUNCTION
 *  custom_nvram_get_database_key
 * DESCRIPTION
 *  to get the custom database key
 * PARAMETERS
 *  key_buffer          [OUT]   the output buffer to save key
 *  buffer_size         [IN]    the size of key buffer
 * RETURNS
 *  0: Fail
 *  n: the lenghth of database key
 *****************************************************************************/
kal_int32 custom_nvram_get_database_key(kal_uint8 *key_buffer, kal_uint32 buffer_size)
{
#ifdef __NVRAM_SECRET_DATA__
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/
    CUST_SECRET_DATA_ST* tmp_buffer;

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/
    if (buffer_size < NVRAM_DATABASE_KEY_SIZE)
    {
        return 0;
    }

    buffer_size = sizeof(custom_secret_data);

    tmp_buffer = (CUST_SECRET_DATA_ST*) get_ctrl_buffer(buffer_size);

#ifdef __MTK_TARGET__
    if (SST_Get_NVRAM_Key((kal_uint32*)&custom_secret_data, (kal_uint32*) tmp_buffer, &buffer_size))
   	{
        memcpy(key_buffer, tmp_buffer->m_custom_database_key, NVRAM_DATABASE_KEY_SIZE);

        buffer_size = NVRAM_DATABASE_KEY_SIZE;
   	}
   	else
   	{
       	buffer_size = 0;
   	}
#else
    memcpy(key_buffer, custom_secret_data.m_custom_database_key, NVRAM_DATABASE_KEY_SIZE);
#endif /* __MTK_TARGET__ */

    free_ctrl_buffer((kal_uint8*)tmp_buffer);

    return buffer_size;
#else
	  return 0;
#endif
}


/*****************************************************************************
 * FUNCTION
 *  mmi_sml_auto_key_gen_implemetation
 * DESCRIPTION
 *  automatic key generation
 * PARAMETERS
 *  key              [IN]
 * RETURNS
 *  void
 *****************************************************************************/
void mmi_sml_auto_key_gen_implemetation(unsigned char *key)
{
    /*----------------------------------------------------------------*/
    /* Local Variables                                                */
    /*----------------------------------------------------------------*/

    /*----------------------------------------------------------------*/
    /* Code Body                                                      */
    /*----------------------------------------------------------------*/

    /* return 1234 as default key */
    /* please implement this function for automatic key generation */
    /* the generated key length should at least 8 digits and also has null-terminator */
    key[0] = 0x31;
    key[1] = 0x32;
    key[2] = 0x33;
    key[3] = 0x34;
    key[4] = 0x35;
    key[5] = 0x36;
    key[6] = 0x37;
    key[7] = 0x38;
    key[8] = 0;
}
#endif /* NVRAM_AUTO_GEN */

#endif /* !defined(NVRAM_NOT_PRESENT) */
