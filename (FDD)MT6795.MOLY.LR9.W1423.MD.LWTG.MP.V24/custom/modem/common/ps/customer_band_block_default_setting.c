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
/*
**   Includes
*/

#ifdef __BAND_BLOCK__

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "customer_band_block_default_setting.h"

/* =============================================================================

[Description]

kal_uint8 rr_band_block_table[] = {
      0xff, 0xff, 0xff, 0xff, 0xff ...
      ----------------  ----  ----
          MCC + MNC     Band  Emergency
              |           |       |
              |           |       --> 0x01 => TRUE
              |           |           0x00 => FALSE
              |           |
              |           ----> 0x00 => GSM 850
              |                 0x01 => GSM 900
              |                 0x02 => GSM 1800
              |                 0x03 => GSM 1900
              |
              -----> 0x00, 0x0f, 0xff => all country
                     0x73, 0x2f, 0xff => all networks in MCC = 732
                     0x73, 0x20, 0x1f => MCC = 732, MNC = 01f


[For example]

Do NOT apply:
-------------------------------------
kal_uint8 rr_band_block_table[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, //1st set
    0xff, 0xff, 0xff, 0xff, 0xff, //2nd set
              ...   
    0xff, 0xff, 0xff, 0xff, 0xff  //10th set
};

Table for Chile Entel:
-------------------------------------
kal_uint8 rr_band_block_table[] = {
      0x00, 0x0f, 0xff, 0x00, 0x01,        => Block GSM band 850 for all country
      0xff, 0xff, 0xff, 0xff, 0xff,           (emergency call allowed)
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff  
};

Table for Colombia Tigo:
-------------------------------------
kal_uint8 rr_band_block_table[] = {
      0x73, 0x2f, 0xff, 0x00, 0x01,        => Block GSM band 850 for MCC 732
      0xff, 0xff, 0xff, 0xff, 0xff,           (emergency call allowed)
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff,
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff  
};

Table for GTM, ESV, HND Claro 850MHz band block:
-------------------------------------
kal_uint8 rr_band_block_table[] = {
      0x70, 0x40, 0x3f, 0x03, 0x01,        => Block GSM band 1900 for MCC 704, MNC 03
      0x70, 0x60, 0x4f, 0x03, 0x01,        => Block GSM band 1900 for MCC 706, MNC 04
      0x70, 0x8f, 0xff, 0x00, 0x01,        => Block GSM band 850 for MCC 708, 706, 704
      0x70, 0x6f, 0xff, 0x00, 0x01,           (emergency call all allowed)
      0x70, 0x4f, 0xff, 0x00, 0x01,
      0xff, 0xff, 0xff, 0x00, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff, 
      0xff, 0xff, 0xff, 0xff, 0xff 
};
      
============================================================================= */

#define RR_MAX_BAND_BLOCK_LIST_SIZE 10 /* MAX for 10; DO NOT modify it! */

kal_uint8 rr_band_block_table[] = 
{
    0xff, 0xff, 0xff, 0xff, 0xff, /* 1st set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 2nd set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 3rd set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 4th set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 5th set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 6th set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 7th set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 8th set */
    0xff, 0xff, 0xff, 0xff, 0xff, /* 9th set */
    0xff, 0xff, 0xff, 0xff, 0xff  /* 10th set */
};


//void rr_init_default_band_block_value(kal_uint8 *data);

/*****************************************************************************
* FUNCTION
*  rr_init_default_band_block_value
*
* DESCRIPTION
*   This function is used to initialize the default band block settings at the
*   first power-on of the MS.
*   Then, we could modify the data by accessing NVRAM (NVRAM editor).
*
* PARAMETERS
*   kal_uint8 *data - input NULL data pool
*
* RETURNS
*
* GLOBALS AFFECTED
*   None
*****************************************************************************/
void rr_init_default_band_block_value(kal_uint8 *data)
{
    kal_uint8 i = 0;

    /* write length */
    data[i] = RR_MAX_BAND_BLOCK_LIST_SIZE;
        
    /* init all data */
    for (i = 0; i < (RR_MAX_BAND_BLOCK_LIST_SIZE*5); i++)
    {
        /* write data */
        data[i + 1] = rr_band_block_table[i];
    }
}

#endif /* __BAND_BLOCK__ */

