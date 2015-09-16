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
 *   dramc_calib.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the dramc calibration flow and framwork
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
 * 	Update SLT loader Macro: __IC_SLT__ change to __IC_SLT_LOADER__
 * 	Update SLT DRAMC Test Cases
 *
 * removed!
 * removed!
 * 	Update SLT loader Macro: __IC_SLT__ change to __IC_SLT_LOADER__
 * 	Update SLT DRAMC Test Cases
 *
 * removed!
 * removed!
 * update auto-k for detecting RX/TX window size
 *
 * removed!
 * removed!
 * Rollback auto-k changelist 173182
 *
 * removed!
 * removed!
 * update auto calibration code for MT6290M and MT6290
 *
 * removed!
 * removed!
 * 1. add custom folder for MT6290M
 * 2. update custom_EMI.h and custom_EMI_release.h with emigen
 * 3. update custom_EMI_INFO.h with manual check in
 * 4. update cfggen
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

/* ============================= */
/*   Included Files              */
/* ============================= */
#include "bl_dramc_drv.h"
#include "dramc_dqs_gw.h"
#include "dramc_dle_calib.h"
#include "dramc_rx_calib.h"
#include "dramc_tx_calib.h"
#include "dramc_calib.h"
#if defined(__IC_SLT_LOADER__)
#include "slt_dramc.h"
#endif

/* ============================= */
/*   Global Variables            */
/* ============================= */
static unsigned char opt_gw_coarse_value0, opt_gw_fine_value0;
#ifdef USE_DUAL_RANK_DDR
static unsigned char opt_gw_coarse_value1, opt_gw_fine_value1;
#endif // end of USE_DUAL_RANK_DDR

static unsigned int opt_rx_dqs0;
#ifdef USE_DUAL_RANK_DDR
static unsigned int opt_rx_dqs1;
#endif // end of USE_DUAL_RANK_DDR

static unsigned int score, high_score;

unsigned int dq_data_width;
extern unsigned int is_mt6290m;
/* ============================= */
/*   Internal Function           */
/* ============================= */

/* ============================= */
/*   External Function           */
/* ============================= */
/*
 * ett_recursive_factor_tuning: ett recursive function framework
 * @n: remain n depth
 * @tuning_factors: tunning factor
 * @cbs: call back function
 * Return Result
 *      - dramc_cal_err_code
 */
dramc_cal_err_code ett_recursive_factor_tuning(unsigned int n, tuning_factor *tuning_factors, print_callbacks *cbs)
{
    unsigned int i;
    int result = 0;
    unsigned int each_loop_score = 0;

    //Print banner.
    result = cbs->ett_print_banner(n);
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }

    if (n == 0) {
        //Before starting the most inner loop, print something.
        result = cbs->ett_print_before_start_loop_zero();
        if (DRAMC_CAL_FAIL <= result) {
            goto __end;
        }
    }

    for (i = 0; i < tuning_factors[n].factor_tbl_num; i++) {
        //adjust factor steps
        result = tuning_factors[n].factor_handler(tuning_factors[n].factor_tbl[i]);
        if (DRAMC_CAL_FAIL <= result) {
            goto __end;
        }
        //set the current factor steps
        tuning_factors[n].curr_val = tuning_factors[n].factor_tbl[i];
        if (n == 0) {//The most inner loop
            //Before each round of the most inner loop, print something.
            result = cbs->ett_print_before_each_round_of_loop_zero();
            if (DRAMC_CAL_FAIL <= result) {
                goto __end;
            }
            //run test code
            result = cbs->ett_print_result(&each_loop_score);
            score += each_loop_score;
            if (DRAMC_CAL_FAIL <= result) {
                goto __end;
            }
            //After each round of the most inner loop, print something.
            result = cbs->ett_print_after_each_round_of_loop_zero();
            if (DRAMC_CAL_FAIL <= result) {
                goto __end;
            }
        } else {//Other loops. Call this function recursively.
            result = ett_recursive_factor_tuning(n - 1, tuning_factors, cbs);
            if (DRAMC_CAL_FAIL <= result) {
                goto __end;
            }
        }
    }

    result = cbs->ett_calc_opt_value(n, &score, &high_score);
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }

    //After finishing the each loop, print something.
    result = cbs->ett_print_after_finish_loop_n(n);
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }

__end:
    cbs->ett_print_err_handler(result);

    return result;
}

/*
 * dramc_calib: Do DRAMC calibration.
 * Return error code;
 */
dramc_cal_err_code dramc_calib(void)
{
    dramc_cal_err_code err = DRAMC_CAL_PASS;

#define CHIP_CONFIG_0   (BASE_ADDR_MDCFGCTL + 0xFF00)
    #define CHIP_CONFIG_0_BOPT_SIP      (1 << 31)
    if (TRUE == is_mt6290m) {
        dq_data_width = 16;
    } else {
        dq_data_width = 32;
    }

    /* do calibration for DQS gating window (phase 1) for rank 0*/
    err = do_dqs_gw_calib_1(&opt_gw_coarse_value0, &opt_gw_fine_value0);
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    #if DRAMC_LOAD_BOARD_TEST
    DclGPIO_Control(slt_dramc_gpio[slt_dramc_gpio_idx++], GPIO_CMD_WRITE_HIGH, 0);
    #endif

    BL_PRINT(LOG_INFO, "rank 0 coarse = %d\r\n", opt_gw_coarse_value0);
    BL_PRINT(LOG_INFO, "rank 0 fine = %d\r\n", opt_gw_fine_value0);
    /* do DLE calibration */
    err = do_dle_calib();
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    #if DRAMC_LOAD_BOARD_TEST
    DclGPIO_Control(slt_dramc_gpio[slt_dramc_gpio_idx++], GPIO_CMD_WRITE_HIGH, 0);
    #endif
    /* do SW RX calibration for DQ/DQS input delay */
    err = do_sw_rx_dq_dqs_calib();
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    #if DRAMC_LOAD_BOARD_TEST
    DclGPIO_Control(slt_dramc_gpio[slt_dramc_gpio_idx++], GPIO_CMD_WRITE_HIGH, 0);
    #endif
    opt_rx_dqs0 = DRV_Reg32(DRAMC_R0DELDLY);
#ifdef USE_DUAL_RANK_DDR
    if ( DRV_Reg32(EMI_CONA)&EMI_CONA_DUAL_RANK_EN )      // Check dual ranks.
    {
        //make sure we in chip select 1. Swap CS0 and CS1.
        DRV_SetReg32(DRAMC_RKCFG, DRAMC_RKCFG_RKSWAP);
        /* do calibration for DQS gating window (phase 1) for rank 1*/
        err = do_dqs_gw_calib_1(&opt_gw_coarse_value1, &opt_gw_fine_value1);
        if (DRAMC_CAL_FAIL <= err) {
            BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
            goto dramc_calib_exit;
        }

        BL_PRINT(LOG_INFO, "rank 1 coarse = %d\r\n", opt_gw_coarse_value1);
        BL_PRINT(LOG_INFO, "rank 1 fine = %d\r\n", opt_gw_fine_value1);
            /* do DLE calibration */
        err = do_dle_calib();
        if (DRAMC_CAL_FAIL <= err) {
            BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
            goto dramc_calib_exit;
        }
        /* do SW RX calibration for DQ/DQS input delay */
        err = do_sw_rx_dq_dqs_calib();
        if (DRAMC_CAL_FAIL <= err) {
            BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
            goto dramc_calib_exit;
        }
        opt_rx_dqs1 = DRV_Reg32(DRAMC_R0DELDLY);

        err = dqsi_gw_dly_coarse_factor_handler_rank1(opt_gw_coarse_value1);
        if (DRAMC_CAL_FAIL <= err) {
            BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
            goto dramc_calib_exit;
        }
        err = dqsi_gw_dly_fine_factor_handler_rank1(opt_gw_fine_value1);
        if (DRAMC_CAL_FAIL <= err) {
            BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
            goto dramc_calib_exit;
        }

        DRV_WriteReg32(DRAMC_R1DELDLY, opt_rx_dqs1);
        //swap back
        //make sure we in chip select 0 now
        DRV_ClrReg32(DRAMC_RKCFG, DRAMC_RKCFG_RKSWAP);
    }
#endif // end of USE_DUAL_RANK_DDR
    err = dqsi_gw_dly_coarse_factor_handler_rank0(opt_gw_coarse_value0);
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    err = dqsi_gw_dly_fine_factor_handler_rank0(opt_gw_fine_value0);
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    DRV_WriteReg32(DRAMC_R0DELDLY, opt_rx_dqs0);

     /* do SW TX calibration for DQ/DQS output delay */
    err = do_sw_tx_dq_dqs_calib();
    if (DRAMC_CAL_FAIL <= err) {
        BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
        goto dramc_calib_exit;
    }
    #if DRAMC_LOAD_BOARD_TEST
    DclGPIO_Control(slt_dramc_gpio[slt_dramc_gpio_idx++], GPIO_CMD_WRITE_HIGH, 0);
    #endif
dramc_calib_exit:

    return err;
}



