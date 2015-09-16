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
 *    usim_dummy_driver.h
 *
 * Project:
 * --------
 *    MONZA
 *
 * Description:
 * ------------
 *    This file defines the data structure, enum and constant for dummy driver
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef USIM_DUMMY_DRIVER_H
#define USIM_DUMMY_DRIVER_H

/* Driver related*/
#include "drv_comm.h"
#include "dcl.h"

#define MODIS_USIM_FILE_PREFIX 23
#define MODIS_USIM_HEAD_SPACE 185
#define MODIS_USIM_PIN1_OFFSET (MODIS_USIM_HEAD_SPACE)
#define MODIS_USIM_PIN2_OFFSET (MODIS_USIM_PIN1_OFFSET + 8)
#define MODIS_USIM_PUK1_OFFSET (MODIS_USIM_PIN2_OFFSET + 8)
#define MODIS_USIM_PUK2_OFFSET (MODIS_USIM_PUK1_OFFSET + 8)
#define MODIS_USIM_PIN1_COUNT_OFFSET (MODIS_USIM_PUK2_OFFSET + 8)
#define MODIS_USIM_PIN2_COUNT_OFFSET (MODIS_USIM_PIN1_COUNT_OFFSET + 1)
#define MODIS_USIM_PUK1_COUNT_OFFSET (MODIS_USIM_PIN2_COUNT_OFFSET + 1)
#define MODIS_USIM_PUK2_COUNT_OFFSET (MODIS_USIM_PUK1_COUNT_OFFSET + 1)

/* AUTHENTICATE cmd/response data len */
#define AUTH_3G_CONTEXT_LEN 34
#define AUTH_GSM_CONTEXT_LEN 17
#define AUTH_RES_LEN 16
#define AUTH_CK_LEN 16
#define AUTH_IK_LEN 16
#define AUTH_KC_LEN 8
#define AUTH_SRES_LEN 4

typedef struct
{
    kal_uint8 pin1_key_ref;
    kal_uint8 pin2_key_ref;
    kal_bool is_pin1_enabled;
    kal_bool is_pin2_enabled;
} usim_pin_data_struct;

#define USIM_TOTAL_SFI 31

#define GSM_ACCESS_TOTAL_SFI 3

extern kal_uint16 L1usim_Cmd(kal_uint8 *, kal_uint32 *, kal_uint8 *, kal_uint32 *);

#ifdef __SIM_UNIT_TEST__
extern void L1usim_reset_pin_counter(kal_bool pin1_enabled, kal_bool pin2_enabled);
#endif

#endif /* USIM_DUMMY_DRIVER_H */ 

