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
 *   dramc_calib.h
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file is to define dramc calib
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * update auto-k for detecting RX/TX window size
 *
 * removed!
 * removed!
 * 1.update auto-k for SIP-Pin MUX and fix some bugs
 * 2.update MDL content
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

#ifndef __DRAMC_CALIB_H__
#define __DRAMC_CALIB_H__
/* ===================== */
/*   Included Files      */
/* ===================== */
/* ===================== */
/*   Prototypes          */
/* ===================== */
typedef enum {
    /* Pass */
    DRAMC_CAL_PASS = 0,
    DRAMC_CAL_TRY_GW,
    DRAMC_CAL_TRY_DLE,
    DRAMC_CAL_TRY_RX,
    DRAMC_CAC_TRY_TX,
    /* ==================================== */
    /* Fail Start */
    DRAMC_CAL_FAIL = 0x10000000,
    DRAMC_CAL_DRAM_TYPE_FAIL = 0x10000000,
    DRAMC_CAL_DRAM_INIT_FAIL,
    /* gating window calibration fail */
    DRAMC_CAL_GW_FAIL = 0x11000000,
    DRAMC_CAL_GW_FAIL_TUNING_NUM,
    DRAMC_CAL_GW_FAIL_BURST_LEN,
    DRAMC_CAL_GW_FAIL_DQS_GW_COARSE_MAX,
    DRAMC_CAL_GW_FAIL_OPT_VAL,
    DRAMC_CAL_GW_FAIL_CORSE_TUNE,
    DRAMC_CAL_GW_FAIL_FINE_TUNE,
    /* dle calibration fail */
    DRAMC_CAL_DLE_FAIL = 0x12000000,
    DRAMC_CAL_DLE_FAIL_OPT_VAL,
    /* RX DQS/DQ fail */
    DRAMC_CAL_RX_FAIL = 0x13000000,
    DRAMC_CAL_RX_FAIL_DQS,
    DRAMC_CAL_RX_FAIL_DQ,
    DRAMC_CAL_RX_FAIL_OPT_VAL,
    /* TX DQS/DQ fail */
    DRAMC_CAL_TX_FAIL = 0x14000000,
    DRAMC_CAL_TX_FAIL_DQS,
    DRAMC_CAL_TX_FAIL_DQ,
    DRAMC_CAL_TX_FAIL_DQM,
    DRAMC_CAL_TX_FAIL_OPT_VAL
} dramc_cal_err_code;

typedef struct {
    char *name;
    unsigned char curr_val;
    unsigned char opt_val;
    unsigned char factor_tbl_num;
    unsigned char *factor_tbl;
    dramc_cal_err_code (*factor_handler) (unsigned char);
} tuning_factor;

typedef struct {
    dramc_cal_err_code (*ett_print_banner) (unsigned int);
    dramc_cal_err_code (*ett_print_before_start_loop_zero) (void);
    dramc_cal_err_code (*ett_print_before_each_round_of_loop_zero) (void);
    dramc_cal_err_code (*ett_print_result) (unsigned int *);
    dramc_cal_err_code (*ett_print_after_each_round_of_loop_zero) (void);
    dramc_cal_err_code (*ett_calc_opt_value) (unsigned int, unsigned int *, unsigned int *);
    dramc_cal_err_code (*ett_print_after_finish_loop_n) (unsigned int);
    void (*ett_print_err_handler)(dramc_cal_err_code);
} print_callbacks;

#define ETT_TUNING_FACTOR_NUMS(x)   (sizeof(x)/sizeof(tuning_factor))

typedef struct {
    dramc_cal_err_code (*test_case) (unsigned int, unsigned int, void *);
    unsigned int start;
    unsigned int range;
    void *ext_arg;
} test_case;

#define ETT_TEST_CASE_NUMS(x)       (sizeof(x)/sizeof(test_case))

dramc_cal_err_code ett_recursive_factor_tuning(unsigned int n, tuning_factor *tuning_factors, print_callbacks *cbs);
dramc_cal_err_code dramc_calib(void);

#endif
