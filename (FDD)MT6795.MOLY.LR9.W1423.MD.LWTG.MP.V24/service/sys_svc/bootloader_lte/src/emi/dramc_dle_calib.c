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
 *   dramc_dle_calib.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the dramc dle calibration
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
 * 	Add DRAMC SLT test cases
 *
 * removed!
 * removed!
 * 1. Add compile flag for sync to FlashTool and HVT
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
 * 1. update mempll init 
 * a. multi-pll mode
 * b. mempll1
 * c. seal-ring mode
 * d. auto detection to  distinguish between MT6290 and MT6290M.
 * 2. update dram ac timing for tRPab
 *
 * removed!
 * removed!
 * update auto calibration code for MT6290M and MT6290
 *
 * removed!
 * removed!
 * fix dramc auto-k
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
#include "dramc_calib.h"

/* ============================= */
/*   Definition, Configuration   */
/* ============================= */
#define DRAMC_DLE_CALC_SELECT   (2)

static dramc_cal_err_code dle_factor_handler(unsigned char factor_value);
#if (DRAMC_DLE_CALC_SELECT == 1) || (DRAMC_DLE_CALC_SELECT == 0)
#define GDMA_FDCSR0 (BASE_ADDR_MDGDMA + 0x10)
#define GDMA_FDCR0  (BASE_ADDR_MDGDMA + 0x20)
#define GDMA_FDSAR0 (BASE_ADDR_MDGDMA + 0x24)
#define GDMA_FDDAR0 (BASE_ADDR_MDGDMA + 0x28)
static dramc_cal_err_code dramc_dma_test(unsigned int start, unsigned int len, void *ext_arg);
#endif
#if (DRAMC_DLE_CALC_SELECT == 2) || (DRAMC_DLE_CALC_SELECT == 0)
static dramc_cal_err_code cpu_dle_test(unsigned int start, unsigned int len, void *ext_arg);
#endif
#if (DRAMC_DLE_CALC_SELECT == 3) || (DRAMC_DLE_CALC_SELECT == 0)
static dramc_cal_err_code dramc_ta1(unsigned int start, unsigned int len, void *ext_arg);
#endif // endif DRAMC_DLE_CALC_SELECT

/* ============================= */
/*   Global Variables            */
/* ============================= */
/* optimum dle calibrating value */
static char opt_dle_value = -1;
/* for current dle_result[global_dle_value] */
static int global_dle_value;

/* dle calibrating table */
static unsigned char dle_tbl[] =
{
    /* DLE: 0x0~0xf */
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

#if defined(__IC_SLT_LOADER__)
static const unsigned char dle_pass_tbl[] =
{
    4, 5, 6, 7, 8
};
#endif

/* Define how many steps we have in dle */
#define DLE_MAX     (sizeof(dle_tbl)/sizeof(unsigned char))

/* store for dle result */
static unsigned int dle_result[DLE_MAX];

/* dle tuning factors */
static tuning_factor dle_tuning_factors[] = 
{
    {
        .name = "DLE",
        .curr_val = 0,
        .opt_val = 0,
        .factor_tbl_num = sizeof(dle_tbl)/sizeof(char),
        .factor_tbl = dle_tbl,
        .factor_handler = dle_factor_handler,
    },
};

/* dle calibrating test cases */
static test_case dle_test_cases[] = 
{
    // TODO: we should use CPU or dma, but CPU or dma cannot calibrate dle now.
    #if (DRAMC_DLE_CALC_SELECT == 1) || (DRAMC_DLE_CALC_SELECT == 0)
    {
        .test_case = dramc_dma_test,
        .start = DRAM_START, 
        .range = 0x80, 
        .ext_arg = (void *)0xFFFFFFFF,
    },
    #endif
    #if (DRAMC_DLE_CALC_SELECT == 2) || (DRAMC_DLE_CALC_SELECT == 0)
    {
        .test_case = cpu_dle_test,
        .start = DRAM_START, 
        .range = 0x80, 
        .ext_arg = (void *)0xFFFFFFFF,
    },
    #endif
    #if (DRAMC_DLE_CALC_SELECT == 3) || (DRAMC_DLE_CALC_SELECT == 0)
    {
        .test_case = dramc_ta1,
        .start = DRAM_START, 
        .range = 0x7FF, 
        .ext_arg = (void *)0xFFFFFFFF,
    },
    #endif
};

/* ============================= */
/*   Internal Functions          */
/* ============================= */

#if (DRAMC_DLE_CALC_SELECT == 1) || (DRAMC_DLE_CALC_SELECT == 0)
/*
 * dramc_dma_test: Run DMA Copy
 * @start: test start address
 * @len: test length
 * @ext_arg: extend argument (We didn't use this argument)
 * Return DMA copy result
 * Note: dramc_dma_test can find left boundary dle only on MT6290.
 */
static dramc_cal_err_code dramc_dma_test(unsigned int start, unsigned int len, void *ext_arg)
{
    dramc_cal_err_code err =  DRAMC_CAL_PASS;
    unsigned int i;

    unsigned int * src_buffp1;
    unsigned int * dst_buffp1;

    src_buffp1 = (unsigned int *)(start - sizeof(unsigned int));
    dst_buffp1 = (unsigned int *)(start + len - sizeof(unsigned int));

    // ----------------------------------------------------------------------------
    // optimizaing loop for ARM
    // always write count-down-to-zero loops and use simple termination conditions
    // always use a counter of type unsigned int, and test for not equal to zero.
    // ----------------------------------------------------------------------------  
    for (i = len/sizeof(unsigned int); i != 0; i--) {
        src_buffp1[i] = i;
        dst_buffp1[i] = 0;
    }
    // using "DMB" instruction let all written data send to DRAM.
    Data_Mem_Barrier();
    //memset(dst_buffp1, 0, len);

    // Other BU needs to customize this part. Or use dramc_ta1() instead.
    // when DRAMC's BL=4, we should send 5*(BL=4)(min), and DRAMC's BL=8, we should send 3*(BL=8)(min).
    DRV_SetReg32(GDMA_FDCSR0, (0x1 << 9)); //basic DMA mode
    DRV_WriteReg32(GDMA_FDCR0, 0x0000C0A0);
    DRV_WriteReg32(GDMA_FDSAR0, start);
    DRV_WriteReg32(GDMA_FDDAR0, start + len);
    DRV_WriteReg32(GDMA_FDCR0, (DRV_Reg32(GDMA_FDCR0) & 0x0000FFFF) | len << 16);
    DRV_SetReg32(GDMA_FDCR0, 0x1); //start dma

    while(DRV_Reg32(GDMA_FDCSR0)&0x1);

    for (i = len/sizeof(unsigned int); i != 0; i--) {
        if (dst_buffp1[i] != i) {
            //print("0x%p: 0x%x != 0x%x\n", src_buffp1[i], dst_buffp1[i], i);
            err = DRAMC_CAL_TRY_DLE;
            break;
        }
    }

    return err;
}
#endif
#if (DRAMC_DLE_CALC_SELECT == 2) || (DRAMC_DLE_CALC_SELECT == 0)
/*
 * cpu_dle_test
 *  @start start address for dle test
 *  @len size of memory for dle test
 *  @ext_arg extend argument (We didn't use this argument)
 * Return cpu dle test result
 *  - dramc_cal_err_code
 * Note: cpu_dle_test can find left boundary dle only on MT6290.
 */
static dramc_cal_err_code cpu_dle_test(unsigned int start, unsigned int len, void *ext_arg)
{
    dramc_cal_err_code err = DRAMC_CAL_PASS;
    unsigned int i;

    volatile unsigned int * buffp = (volatile unsigned int *)(start - sizeof(unsigned int));

    // ----------------------------------------------------------------------------
    // optimizaing loop for ARM
    // always write count-down-to-zero loops and use simple termination conditions
    // always use a counter of type unsigned int, and test for not equal to zero.
    // ----------------------------------------------------------------------------
    for (i = len >> 2; i != 0; i--) {
        buffp[i] = i;
    }
    // using "DMB" instruction let all written data send to DRAM.
    Data_Mem_Barrier();
    for (i = len >> 2; i != 0; i--) {
        if (i != buffp[i]) {
            err = DRAMC_CAL_TRY_DLE;
            break;
        }
    }

    return err;
}
#endif
#if (DRAMC_DLE_CALC_SELECT == 3) || (DRAMC_DLE_CALC_SELECT == 0)
/*
 * dramc_ta1
 * @start start address for dle test
 * @len size of memory for dle test
 * @ext_arg extend argument
 * Return 
 * Note: dramc_ta1 can find left and right boundary dle, but this result is not really EMI to DDRPHY's delay.
 */
static dramc_cal_err_code dramc_ta1(unsigned int start, unsigned int len, void *ext_arg)
{
    dramc_cal_err_code err =  DRAMC_CAL_PASS;
    int check_result = (int)ext_arg;
    unsigned int data;

    /* set test patern length*/
    data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
    DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_1_PAT0(data) | DRAMC_TEST2_2_OFFSET(len));
    DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST1); //Test Agent1

    while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));

    /*
     * NoteXXX: Need to wait for at least 400 ns
     *          After checking the simulation result,
     *          there will be a delay on DLE_CNT_OK/DM_CMP_ERR updates after getting DM_CMP_CPT.
     *          i.e; After getting the complete status, need to wait for a while before reading DLE_CNT_OK/DM_CMP_ERR in the TESTRPT register.
     */
    BL_GPT_UDELAY(1);
    if (check_result) {
        if (DRV_Reg32(DRAMC_TESTRPT) & DRAMC_TESTRPT_DM_CMP_ERR) {
            err = DRAMC_CAL_TRY_DLE;
        }
    }

    DRV_ClrReg32_NPW(DRAMC_CONF2, DRAMC_CONF2_TEST1); //disable test agent1
    Data_Mem_Barrier();

    if ((int)ext_arg == 0xFFFFFFFF) {
        return err;
    }

    return DRAMC_CAL_PASS;

}
#endif // endif DRAMC_DLE_CALC_SELECT

/*
 * dle_factor_handler
 * @factor_value dle tuning value
 * Return dramc_cal_err_code
 */
static dramc_cal_err_code dle_factor_handler(unsigned char factor_value)
{
    // dle value should be smaller than 15.
    if (16 <= (unsigned int)factor_value) {
        BL_PRINT(LOG_ERROR, "[%s at %d]. factor_value[%d] should be smaller than %d\r\n", \
            __FILE__, __LINE__, (unsigned int)factor_value, 16);
        return DRAMC_CAL_GW_FAIL_CORSE_TUNE;
    }
    DRV_WriteReg32(DRAMC_DDR2CTL/* 0x7C */, 
             (DRV_Reg32(DRAMC_DDR2CTL/* 0x7C */) & (~DRAMC_DDR2CTL_DATLAT_MASK))  /* Reserve original values for DRAMC_DDR2CTL[0:3, 7:31] */
        | DRAMC_DDR2CTL_DATLAT(factor_value & 0x7));         /* DATLAT: DRAMC_DDR2CTL[4:6], 3 bits */

    DRV_WriteReg32_NPW(DRAMC_PADCTL4/* 0xE4 */, 
             (DRV_Reg32(DRAMC_PADCTL4/* 0xE4 */) & (~DRAMC_PADCTL4_DATLAT3))  /* Reserve original values for DRAMC_DDR2CTL[0:3, 5:31] */
        | (((factor_value >> 3) & 0x1)?DRAMC_PADCTL4_DATLAT3:0));          /* DATLAT3: DRAMC_PADCTL1[4], 1 bit */
    Data_Mem_Barrier();

    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dle_banner: do something each recursive function
 * @n: recursive function density
 *      - zero means leaf
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dle_banner(unsigned int n) 
{
    if (n == ETT_TUNING_FACTOR_NUMS(dle_tuning_factors) - 1) {
        global_dle_value = 0;
    }

    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dle_before_start_loop_zero: do something before most inner loop.
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dle_before_start_loop_zero(void) 
{
    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dle_before_each_round_of_loop_zero: do something before executing each loop at leaf. 
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dle_before_each_round_of_loop_zero(void) 
{
    DDR_PHY_RESET();

    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dle_result: check gating window result
 * @test_cases: pointer to test case function
 * @nr_ts: number(s) of test case
 * @score: pointer to score
 * Return: exectuion result
 */
static dramc_cal_err_code ett_print_dle_result(unsigned int * score) 
{
    unsigned int i;
    dramc_cal_err_code result = DRAMC_CAL_PASS;

    *score = 1;
    for ( i = 0 ; i < ETT_TEST_CASE_NUMS(dle_test_cases); i++) {
        result = dle_test_cases[i].test_case(dle_test_cases[i].start, dle_test_cases[i].range, dle_test_cases[i].ext_arg);
        if (DRAMC_CAL_PASS == result) {
            if (i == (ETT_TEST_CASE_NUMS(dle_test_cases)-1)) {
                BL_PRINT(LOG_DEBUG, "%d:1\r\n", i);
                dle_result[global_dle_value++] = *score; 
            }
        } else {
            BL_PRINT(LOG_DEBUG, "%d:0\r\n", i);
            *score = 0;
            dle_result[global_dle_value++] = *score; 
            break;
        }
    }

    return result;
}

/*
 * ett_print_dle_after_each_round_of_loop_zero: do something after finishing each loop at leaf.
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dle_after_each_round_of_loop_zero(void) 
{
    // TODO: why?
    BL_GPT_UDELAY(1);
    return DRAMC_CAL_PASS;
}

/*
 * ett_calc_dle_opt_value: calulate dle optimum value
 * @n: recursive function density
 *      - zero means leaf
 * @score: pointer to current score
 * @high_score: pointer to highest score
 * Return: dramc_cal_err_code
 *
 */
/*
 * TODO: we should check dle unbroken.
 * For Example: It should be one when dle value is six.
 * =========================================================================================
 *      |   0    1    2    3    4    5    6    7    8    9   10   11   12   13   14   15
 * -----------------------------------------------------------------------------------------
 * dle  |   0    0    0    0    1    1    0    1    0    0    0    0    0    0    0    0
 * =========================================================================================
 */
static dramc_cal_err_code ett_calc_dle_opt_value(unsigned int n, unsigned int *score, unsigned int *high_score) 
{
    unsigned int ix;
    dramc_cal_err_code err = DRAMC_CAL_PASS;

    if (n == ETT_TUNING_FACTOR_NUMS(dle_tuning_factors) - 1) {
        opt_dle_value = -1;
        for(ix = 1; ix < dle_tuning_factors[0].factor_tbl_num; ix++){
            if (dle_result[ix - 1] == 1 && dle_result[ix] == 1){
                if ((signed char)dle_tbl[ix] > ((signed char)opt_dle_value)) {
                    opt_dle_value = dle_tbl[ix];
                }
                break;
            }
        }
        #if defined(__IC_SLT_LOADER__)
        for (ix = 0; ix < sizeof(dle_pass_tbl); ix++) {
            if (dle_pass_tbl[ix] == opt_dle_value) {
                break;
            }
        }
        if (sizeof(dle_pass_tbl) <= ix) {
            BL_PRINT(LOG_ERROR, "opt_dle (%d) is unexpected value ( ", opt_dle_value);
            for (ix = 0; ix < sizeof(dle_pass_tbl); ix++) {
                BL_PRINT(LOG_ERROR, "%d ", dle_pass_tbl[ix]);
            }
            BL_PRINT(LOG_ERROR, ")\r\n");
            return DRAMC_CAL_DLE_FAIL_OPT_VAL;
        }
        #endif
        BL_PRINT(LOG_INFO, "dle result:");
        for (ix = 0; ix < DLE_MAX; ix++) {
            BL_PRINT(LOG_INFO, "%d:%d ", ix, dle_result[ix]);
        }
        BL_PRINT(LOG_INFO, "\r\n");

        /* setup the opt dle value according to calibration result */
        if ((-1 < (signed char)opt_dle_value) && (16 > (signed char)opt_dle_value)) {
            BL_PRINT(LOG_INFO, "opt_dle value:%d\r\n", opt_dle_value);
            err = dle_factor_handler(opt_dle_value);
            if (DRAMC_CAL_FAIL <= err) {
                BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
                return DRAMC_CAL_GW_FAIL_CORSE_TUNE;
            }
            return DRAMC_CAL_PASS;
        } else {
            BL_PRINT(LOG_ERROR, "cannot find opt_dle value\r\n");
            return DRAMC_CAL_DLE_FAIL_OPT_VAL;
        }
    }

    return err;
}

/*
 * ett_print_dle_after_finish_loop_n: do something after finish one loop
 * @n: recursive function density
 *      - zero means leaf
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dle_after_finish_loop_n(unsigned int n) 
{
    if (n == 0) {
        BL_PRINT(LOG_DEBUG, "\r\n");
    }
    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dqs_gw_err_handler: do error handle if having any error.
 * @err: dramc_cal_err_code
 * Return: void
 */
static void ett_print_dle_err_handler(dramc_cal_err_code result)
{

}

/* ============================= */
/*   External Functions          */
/* ============================= */
/*
 * Related Registers (Latency between DRAMC and PHY)
 *  - PADCTL4  bit4     DATLAT[3]
 *  - DDR2CTL  bit6~4   DATLAT[2:0]
 * Algorithm
 *  -  Set DLE from 4 to 14 and check if data is correct. Then find two consecutive settings with comparison OK and use the second setting.
 */
dramc_cal_err_code do_dle_calib(void) {

    print_callbacks cbs = {
        .ett_print_banner = ett_print_dle_banner,
        .ett_print_before_start_loop_zero = ett_print_dle_before_start_loop_zero,
        .ett_print_before_each_round_of_loop_zero = ett_print_dle_before_each_round_of_loop_zero,
        .ett_print_result = ett_print_dle_result,
        .ett_print_after_each_round_of_loop_zero = ett_print_dle_after_each_round_of_loop_zero,
        .ett_calc_opt_value = ett_calc_dle_opt_value,
        .ett_print_after_finish_loop_n = ett_print_dle_after_finish_loop_n,
        .ett_print_err_handler = ett_print_dle_err_handler,
    };

/*
  * Main function
  * - Create dle_result[]
  * Output
  * -   idx: 0  or 1
  */
    if (ETT_TUNING_FACTOR_NUMS(dle_tuning_factors) > 0) {
        return ett_recursive_factor_tuning(ETT_TUNING_FACTOR_NUMS(dle_tuning_factors)-1, dle_tuning_factors, &cbs);
    }

    return DRAMC_CAL_DLE_FAIL;
}

