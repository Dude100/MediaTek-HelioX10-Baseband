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

/*******************************************************************************
 * Filename:
 * ---------
 *   upcm_enum.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
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
 * .
 *
 ****************************************************************************/
/*
 * =====================================================================================
 *
 *       Filename:  upcm_enum.h
 *
 *    Description:  UPCM (User plane connection manager exported header file)
 *                  ENUM values for trace.
 *
 *        Created: 2012/3/19 �W�� 11:20:22
 *
 *        Author:  mtk01641 (moja)
 * =====================================================================================
 */
#ifndef  UPCM_ENUM_INC
#define  UPCM_ENUM_INC

#define MAX_EPSB_NUM 16

typedef enum
{
    IP_TYPE_MISC,
    IP_TYPE_V4,
    IP_TYPE_V6,
}ip_type_e;

/*
 * bit 0:Indicate if test mode is activate.
 * bit 1:Indicate if test loop is closed.
 * bit 2: BUFFER_IP_PDU
 * bit 3: Drop UL/DL SDUs
 */
typedef enum
{
    TEST_FLAG_MODE   = 0x01,
    TEST_FLAG_LOOP   = 0x02,
    TEST_FLAG_BUFFER = 0x04,
    TEST_FLAG_DROP   = 0x08,
}upcm_test_flag_e;

/* 
 * Used for trace
 */
typedef enum
{
    UPCM_NORMAL = 0,
    UPCM_TEST   = TEST_FLAG_MODE,
    UPCM_LOOP   = TEST_FLAG_LOOP,
    UPCM_BUF    = TEST_FLAG_BUFFER,
    UPCM_DROP   = TEST_FLAG_DROP,
    UPCM_TEST_LOOP          = UPCM_TEST | UPCM_LOOP,
    UPCM_TEST_BUF           = UPCM_TEST | UPCM_BUF,
    UPCM_TEST_DROP          = UPCM_TEST | UPCM_DROP,
    UPCM_LOOP_BUF           = UPCM_LOOP | UPCM_BUF,
    UPCM_LOOP_DROP          = UPCM_LOOP | UPCM_DROP,
    UPCM_BUF_DROP           = UPCM_BUF  | UPCM_DROP,
    UPCM_TEST_LOOP_BUF      = UPCM_TEST | UPCM_LOOP  | UPCM_BUF,
    UPCM_TEST_LOOP_DROP     = UPCM_TEST | UPCM_LOOP  | UPCM_DROP,
    UPCM_TEST_BUF_DROP      = UPCM_TEST | UPCM_BUF   | UPCM_DROP,
    UPCM_LOOP_BUF_DROP      = UPCM_LOOP | UPCM_BUF   | UPCM_DROP,
    UPCM_TEST_LOOP_BUF_DROP = UPCM_TEST | UPCM_LOOP  | UPCM_BUF   | UPCM_DROP,
}upcm_test_e;

typedef enum
{
    TACT_DELAYTIMER_RUNNING,
    TACT_DELAYTIMER_TIMEOUT,
    TACT_BUFFER,
    TACT_LOOPBACK,
    TACT_DISCARD,
    TACT_DELIVER_TO_UPPER,
}upcm_test_act_e;

typedef enum
{
    UBACT_ACTIVE,
    UBACT_DEACTIVE,
}upcm_bearer_act_e;

typedef enum
{
    UPCM_SUSPEND,
    UPCM_RESUME,
}upcm_sus_res_e;

typedef enum
{
    UPT_Open,
    UPT_Close,
}upcm_act_test_mode_e;

typedef enum
{
    UPT_AlreadyAct,
    UPT_NotAct,
    UPT_AlreadyClose,
    UPT_AlreadyOpen,
    UPT_HasPDN,
    UPT_HasMoreThan1PDN,
}upcm_test_mode_fail_code_e;

#endif   /* ----- #ifndef UPCM_ENUM_INC  ----- */

