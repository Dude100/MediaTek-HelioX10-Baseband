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
 *   dramc_dqs_gw.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the DRAMC gating window calibration
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
 * fix tx calibration and print more msg
 *
 * removed!
 * removed!
 * add print msg for auto-k
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
#if defined __SIP_RAM_SIZE__
#define TA2_DQS_GW_COUNTER      (0x80808080)
#else
#define TA2_DQS_GW_COUNTER      (0xFEFEFEFE)
#endif
#define DRAMC_CAL_GW_SELECT     (0)
#if defined(__IC_SLT_LOADER__)
#define GATING_WINDOW_MINI_SIZE (57*DQS_GW_FINE_MAX/128)
#else
#define GATING_WINDOW_MINI_SIZE (0)
#endif

#if DRAMC_CAL_GW_SELECT == 0
static dramc_cal_err_code cpu_read_test(unsigned int start, unsigned int len, void *ext_arg);
#elif DRAMC_CAL_GW_SELECT == 1
static dramc_cal_err_code dramc_ta2(unsigned int start, unsigned int len, void *ext_arg);
#endif
dramc_cal_err_code dqsi_gw_dly_coarse_factor_handler_rank0(unsigned char);
dramc_cal_err_code dqsi_gw_dly_fine_factor_handler_rank0(unsigned char);

/* ============================= */
/*   Global Variables            */
/* ============================= */
/* optimizate value */
static unsigned char opt_gw_coarse_value, opt_gw_fine_value;

/*
 * Coarse tune
 *  - Unit is DRAM Clock Cycle
 *  - DQSCTL1 (3 bits) (2T for 2X mode and 1T for 1X mode)
 *  - DQSGCTL (2 bits for each rank 2 DQS) (0.5T)
 */
/* DQS gating window (coarse) */
static unsigned char dqsi_gw_dly_coarse_tbl[] =
{
    #if defined(__EMI_MODE_2X__)
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31
    #elif defined(__EMI_MODE_1X__)
    /* Delay time of DQSCTL1[0] = 1 is the same as that of DQSGCTL[1] = 1, so we skip value when DQSCTL1[0] = 1 except of 30 and 31 */
    0, 1, 2, 3, 8, 9, 10, 11, 16, 17, 18, 19, 24, 25, 26, 27, 30, 31
    #else
        #error "Please define EMI DEVICE Type!"
    #endif
};

/*
 * Fine tune
 *  - one step delay is about 18 ns in MT6290
 */
/* DQS gating window (fine) */
static unsigned char dqsi_gw_dly_fine_tbl[] =
{
#if defined(__IC_SLT_LOADER__)
    0, /*1, 2, 3, 4, 5, 6, 7,*/
    8, /*9, 10, 11, 12, 13, 14, 15,*/
    16, /*17, 18, 19, 20, 21, 22, 23,*/
    24, /*25, 26, 27, 28, 29, 30, 31,*/
    32, /*33, 34, 35, 36, 37, 38, 39,*/
    40, /*41, 42, 43, 44, 45, 46, 47,*/
    48, /*49, 50, 51, 52, 53, 54, 55,*/
    56, /*57, 58, 59, 60, 61, 62, 63,*/
    64, /*65, 66, 67, 68, 69, 70, 71,*/
    72, /*73, 74, 75, 76, 77, 78, 79,*/
    80, /*81, 82, 83, 84, 85, 86, 87,*/
    88, /*89, 90, 91, 92, 93, 94, 95,*/
    96, /*97, 98, 99, 100, 101, 102, 103,*/
    104, /*105, 106, 107, 108, 109, 110, 111,*/
    112, /*113, 114, 115, 116, 117, 118, 119,*/
    120, /*121, 122, 123, 124, 125, 126, 127,*/
#else
    0, 1, 2, 3, 4, 5, 6, 7,
    8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23,
    24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39,
    40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55,
    56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71,
    72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87,
    88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103,
    104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127,
#endif
};

/* Define how many steps we have in coarse tune, fine tune */
#define DQS_GW_COARSE_MAX (sizeof(dqsi_gw_dly_coarse_tbl)/sizeof(unsigned char))
#define DQS_GW_FINE_MAX (sizeof(dqsi_gw_dly_fine_tbl)/sizeof(unsigned char))

/* store for gating window result */
static unsigned char dqs_gw[DQS_GW_COARSE_MAX][DQS_GW_FINE_MAX >> 3];
/* for current dqsi_gw_dly_coarse_tbl[dqs_gw_coarse], dqsi_gw_dly_fine_tbl[dqs_gw_fine] */
static int dqs_gw_coarse, dqs_gw_fine;

/* gating window tuning factors */
static tuning_factor dqs_gw_tuning_factors[] =
{
    {
        .name = "DQS Gating Window Delay (Fine Scale)",
        .curr_val = 0,
        .opt_val = 0,
        .factor_tbl_num = sizeof(dqsi_gw_dly_fine_tbl)/sizeof(unsigned char),
        .factor_tbl = dqsi_gw_dly_fine_tbl,
        .factor_handler = dqsi_gw_dly_fine_factor_handler_rank0,
    },
    {
        .name = "DQS Gating Window Delay (Coarse Scale)",
        .curr_val = 0,
        .opt_val = 0,
        .factor_tbl_num = sizeof(dqsi_gw_dly_coarse_tbl)/sizeof(unsigned char),
        .factor_tbl = dqsi_gw_dly_coarse_tbl,
        .factor_handler = dqsi_gw_dly_coarse_factor_handler_rank0,
    },
};

/* gating window test cases */
static test_case dqs_gw_test_cases[] = 
{
    #if DRAMC_CAL_GW_SELECT == 0
    {
        .test_case = cpu_read_test, //use dramc test agent 
        .start = DRAM_START, 
        .range = 0xA, 
        .ext_arg = (void *)0, //check_result, 1st run, no need to check the r/w value
    },
    #elif DRAMC_CAL_GW_SELECT == 1
    {
        .test_case = dramc_ta2, //use dramc test agent 
        .start = DRAM_START, 
        .range = 0xA, 
        .ext_arg = (void *)0, //check_result, 2nd run, it's need to check the r/w value
    },
    #endif
};

extern unsigned int dq_data_width;
extern unsigned int is_mt6290m;
/* ============================= */
/*   Internal Functions          */
/* ============================= */
#if DRAMC_CAL_GW_SELECT == 0
/*
 * Sequence_Read: Run Squence Read
 * @start: test start address
 * @len: test length
 * @ext_arg: extend argument (We didn't use this argument)
 * Return void
 */
static void Sequence_Read(unsigned int start, unsigned int len, void *ext_arg)
{
    unsigned int i;
    volatile unsigned int rval;  
    /* DQS gating window counter reset */
    DRV_SetReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);
    DRV_ClrReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);

    DDR_PHY_RESET();
    // ----------------------------------------------------------------------------
    // optimizaing loop for ARM
    // always write count-down-to-zero loops and use simple termination conditions
    // always use a counter of type unsigned int, and test for not equal to zero.
    // ----------------------------------------------------------------------------
    for (i = len; i != 0; i--) {
        rval = *(volatile unsigned int *)(start);
    }
    /* for set-but-not-used compile error. */
    if (rval) {}
}

/*
 * Do_Read_Test: Run Read Test
 * @start: test start address
 * @len: test length
 * @ext_arg: extend argument (We didn't use this argument)
 * Return error code.
 */
static dramc_cal_err_code Do_Read_Test(unsigned int start, unsigned int len, void *ext_arg)
{
    dramc_cal_err_code err = DRAMC_CAL_PASS;
    unsigned int expected_val = 0;
    unsigned int idx;

    if (DRV_Reg32(DRAMC_DDR2CTL)&DRAMC_DDR2CTL_FDIV2) {
        if (DRV_Reg32(DRAMC_ACTIM0)&DRAMC_ACTIM0_BL2) { // Burst Length = 4
            expected_val = 0x02020202 * len;
        } else if (DRV_Reg32(DRAMC_CONF1)&DRAMC_CONF1_BL4) { // Burst Length = 8
            expected_val = 0x04040404 * len;
        } else {
            BL_PRINT(LOG_ERROR, "Burst Length configuration is not support.\r\n");
            err = DRAMC_CAL_GW_FAIL_BURST_LEN;
            goto __end;
        }
    } else {
        if (!(DRV_Reg32(DRAMC_ACTIM0)&DRAMC_ACTIM0_BL2)) { // must be set to zero
            if (DRV_Reg32(DRAMC_CONF1)&DRAMC_CONF1_BL4) { // Burst Length = 4
                expected_val = 0x02020202 * len;
            } else { // Burst Length = 8
                expected_val = 0x04040404 * len;
            }
        } else {
            BL_PRINT(LOG_ERROR, "Burst Length configuration is not support.\r\n");
            err = DRAMC_CAL_GW_FAIL_BURST_LEN;
            goto __end;
        }
    }
    if (TRUE == is_mt6290m) {
        expected_val &= 0x0000FFFF;
    }

    // ----------------------------------------------------------------------------
    // optimizaing loop for ARM
    // always write count-down-to-zero loops and use simple termination conditions
    // always use a counter of type unsigned int, and test for not equal to zero.
    // ----------------------------------------------------------------------------
    for (idx = 2; idx != 0; idx--) {
        Sequence_Read(start,len,ext_arg);
        if (DRV_Reg32(DRAMC_DQSGNWCNT0/* 0x3C0 */) != expected_val) { // check DQS0 and DQS1 counter
                err = DRAMC_CAL_TRY_GW;
                goto __end;
            
        }
        if (DRV_Reg32(DRAMC_DQSGNWCNT1/* 0x3C4 */) != expected_val) { // check DQS2 and DQS3 counter
            err = DRAMC_CAL_TRY_GW;
            goto __end;
        }
    }
__end:

    return err;
}

/*
 * cpu_read_test: Run Cpu Read Test
 * @start: test start address
 * @len: test length
 * @ext_arg: extend argument (We didn't use this argument)
 * Return error code.
 */
static dramc_cal_err_code cpu_read_test(unsigned int start, unsigned int len, void *ext_arg)
{
   
    dramc_cal_err_code err = DRAMC_CAL_PASS;
    /* cpu read test */
    err = Do_Read_Test(start, len, ext_arg);

    DRV_SetReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);
    DRV_ClrReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);

    DDR_PHY_RESET();

    return err;
 
}

#elif DRAMC_CAL_GW_SELECT == 1
/*
 * dramc_ta2: Run DRAMC test agent 2.
 * @start: test start address
 * @len: test length
 * @ext_arg: extend argument (0: don't check read/write results; 1: check)
 * Return error code.
 */
static dramc_cal_err_code dramc_ta2(unsigned int start, unsigned int len, void *ext_arg)
{
    dramc_cal_err_code err = DRAMC_CAL_PASS;
    int check_result = (int)ext_arg;
    unsigned int data;

    /* set test patern length */
    data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
    DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_2_PAT1(data) | 0x3FF);

    // Trigger. Test Agent 2 write enabling, Test Agent 2 read enabling
    DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R);
    
    /* wait test agent 2 complete */
    while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));

    /* 
     * NoteXXX: Need to wait for at least 400 ns 
     *          After checking the simulation result, 
     *          there will be a delay on DLE_CNT_OK/DM_CMP_ERR updates after getting DM_CMP_CPT.
     *          i.e; After getting the complete status, need to wait for a while before reading DLE_CNT_OK/DM_CMP_ERR in the TESTRPT register.
     */
    BL_GPT_UDELAY(1);

    /* check test agent 2 comparison and dle-counter result */
    if (check_result) {
        if (DRV_Reg32(DRAMC_TESTRPT) & DRAMC_TESTRPT_DM_CMP_ERR) {
            err = DRAMC_CAL_TRY_GW;
        } else if (!(DRV_Reg32(DRAMC_TESTRPT) & DRAMC_TESTRPT_DLE_CNT_OK)) {
            err = DRAMC_CAL_TRY_GW;
        }
    }

    // Turn-off. Disable test agent2 r/w
    DRV_ClrReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R);
    
    //print("ext_arg:%x,err:%x\n",ext_arg,err);
    if ((int)ext_arg == 0xFFFFFFFF)
    {
        return err;
    }

    //print("[2]DRAMC_DQSGNWCNT0:%x,DRAMC_DQSGNWCNT1,%x\n",DRAMC_READ_REG(DRAMC_DQSGNWCNT0),DRAMC_READ_REG(DRAMC_DQSGNWCNT1));
    DDR_PHY_RESET();

    /* check gating window counter result */
    if (DRAMC_CAL_PASS == err) {
        if (TA2_DQS_GW_COUNTER == (DRV_Reg32(DRAMC_DQSGNWCNT0))
            && (TA2_DQS_GW_COUNTER == DRV_Reg32(DRAMC_DQSGNWCNT1))) {
            err = DRAMC_CAL_PASS;
        } else {
            err = DRAMC_CAL_TRY_GW;
        }
    }
    /* DQS gating window counter reset */
    DRV_SetReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);
    DRV_ClrReg32_NPW(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);
    Data_Mem_Barrier();

    return err;
}
#endif // endif DRAMC_CAL_GW_SELECT

/*
 * ett_print_dqs_gw_before_each_round_of_loop_zero: do something each recursive function
 * @n: recursive function density
 *      - zero means leaf
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_banner(unsigned int n)
{
    unsigned int i, j;
    if (n == ETT_TUNING_FACTOR_NUMS(dqs_gw_tuning_factors) - 1) {
        dqs_gw_coarse = 0; //from begin of coarse tune, reset to 0
        dqs_gw_fine = 0;   //from begin of fine tune, reset to 0
        for (i = 0; i < DQS_GW_COARSE_MAX; i++) {
            for (j = 0; j < DQS_GW_FINE_MAX >> 3; j++)
                dqs_gw[i][j] = 0;
        }

        /* 1.enable burst mode for gating window */
        /*   enable DQS gating window counter */
        DRV_SetReg32(DRAMC_DQSCTL1, DRAMC_DQSCTL1_DQSIENMODE);
        DRV_SetReg32_NPW(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTEN);
        Data_Mem_Barrier();
    }

    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dqs_gw_before_each_round_of_loop_zero: do something before most inner loop.
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_before_start_loop_zero(void) 
{
    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dqs_gw_before_each_round_of_loop_zero: do something before executing each loop at leaf. 
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_before_each_round_of_loop_zero(void) 
{
    /* DQS gating window counter reset */
    DRV_SetReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);
    DRV_ClrReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTRST);

    DDR_PHY_RESET();

    return DRAMC_CAL_PASS;
}

/*
 * __ett_print_dqs_gw_result: check gating window result
 * @test_cases: pointer to test case function
 * @nr_ts: number(s) of test case
 * @score: pointer to score
 * Return: exectuion result
 */
static dramc_cal_err_code __ett_print_dqs_gw_result(test_case *test_cases, int nr_ts, unsigned int * score)
{
    unsigned int i;
    dramc_cal_err_code result = DRAMC_CAL_PASS;

    *score = 1;
    for (i = 0; i < nr_ts; i++) {
        result = test_cases[i].test_case(test_cases[i].start, test_cases[i].range, test_cases[i].ext_arg);
        if (DRAMC_CAL_PASS != result) {
            *score = 0;
            break;
        }
    }
    /*
     * DQS GW calibration rule 1: Identify a pass-window with the max gw.
     */
    if (*score != 0) {
        // set 1 if *score is not zero.
        // dqs_gw_fine >> 3 is for 1 byte equal to 8 bits.
        // dqs_gw_fine&0x7 is for mod 8.
        dqs_gw[dqs_gw_coarse][dqs_gw_fine >> 3] |= (1 << (dqs_gw_fine&0x7));
    }

    dqs_gw_fine++;
    if (dqs_gw_fine >= DQS_GW_FINE_MAX) {
        dqs_gw_coarse++;
        // Guo-Huei Chang: It should be clear to zero. I don't know why use &= (DQS_GW_FINE_MAX - 1).
        dqs_gw_fine &= (DQS_GW_FINE_MAX - 1);
        
        // the coarse tune is larger than maximum value. the gating window clalibration settings have problem(s).
        if (dqs_gw_coarse > DQS_GW_COARSE_MAX) {
            BL_PRINT(LOG_ERROR, "Critical error!! dqs_gw_coarse > %d\r\n", DQS_GW_COARSE_MAX);
            result = DRAMC_CAL_GW_FAIL_DQS_GW_COARSE_MAX;
        }
    }
    

    return result;
}

/*
 * ett_print_dqs_gw_result_1: check current setting is passed.
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_result_1(unsigned int * score)
{
   return __ett_print_dqs_gw_result(dqs_gw_test_cases, ETT_TEST_CASE_NUMS(dqs_gw_test_cases), score);
}

/*
 * ett_print_dqs_gw_after_each_round_of_loop_zero: do something after finishing each loop at leaf.
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_after_each_round_of_loop_zero(void) 
{
    return DRAMC_CAL_PASS;
}

/*
 * nr_bit_set: Get the number of bits set in the given value.
 * @p_val: the pointer of value
 * @len: length of val, and unit is bit.
 * Return the number of bits set.
 */
static int nr_bit_set(void * p_val, unsigned int len)
{
    unsigned int i, cnt = 0;
    unsigned char * val = (unsigned char *)p_val;

    for (i = 0; i < len; i++) {
        // i >> 3 is for 1 byte equal to 8 bits.
        // i&0x7 is for mod 8.
        if (val[i >> 3] & (1 << (i&0x7))) {
            cnt++;
        }
    }

    return cnt;
}

/*
 * first_bit_set: Get the first bit set in the given value.
 * @p_val: the pointer of value
 * @len: length of val, and unit is bit.
 * Return the first bit set.
 */
static int first_bit_set(void * p_val, unsigned int len)
{
    unsigned int i;
    unsigned char * val = (unsigned char *)p_val;

    for (i = 0; i < len; i++) {
        // i >> 3 is for 1 byte equal to 8 bits.
        // i&0x7 is for mod 8.
        if (val[i >> 3] & (1 << (i&0x7))) {
            return i;
        }
    }

    return -1;
}

/*
 * ett_calc_dqs_gw_opt_value: calulate gating window optimum value
 * @n: recursive function density
 *      - zero means leaf
 * @score: pointer to current score
 * @high_score: pointer to highest score
 * Return: dramc_cal_err_code
 *
 */
/*
 * For Example: It should be one when the coarse tune value is 0x000F and the fine tune value is from 56 to 80.
 * =========================================================================================
 * coarse\fine  0    8   16   24   32   40   48   56   64   72   80   88   96  104  112  120
 * -----------------------------------------------------------------------------------------
 *      000C:|  0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
 *      000D:|  0    0    0    0    0    0    0    0    0    0    0    0    0    1    1    1
 *      000E:|  0    0    0    0    0    0    1    1    1    1    1    1    1    1    1    1
 *      000F:|  1    1    1    1    1    1    1    0    0    0    0    1    1    0    0    0
 *      0010:|  1    1    1    1    1    1    1    0    0    0    0    0    0    0    0    0
 *      0011:|  0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
 * =========================================================================================
 */
static dramc_cal_err_code ett_calc_dqs_gw_opt_value(unsigned int n, unsigned int *score, unsigned int *high_score)
{
    dramc_cal_err_code err = DRAMC_CAL_PASS;
    unsigned int i, c = 0, f, cnt, max=0;

    if (n == ETT_TUNING_FACTOR_NUMS(dqs_gw_tuning_factors) - 1) {
        for (i = 0; i < DQS_GW_COARSE_MAX; i++) {
                // find the max passed window
                cnt = nr_bit_set((void *)dqs_gw[i], DQS_GW_FINE_MAX);
                // Thinking about preamble.
                // We should choose 2nd corse tune if 1st and 2nd corse tune have the same fine tune numbers.
                // So, we should write "cnt > max" not "cnt >= max".
                if (cnt >= max) {
                    max = cnt;
                    c = i;
                }
        }
        if (max >= GATING_WINDOW_MINI_SIZE) {
            f = first_bit_set((void *)dqs_gw[c], DQS_GW_FINE_MAX) + max / 2;
            opt_gw_coarse_value = dqsi_gw_dly_coarse_tbl[c];
            opt_gw_fine_value = dqsi_gw_dly_fine_tbl[f];
            BL_PRINT(LOG_INFO, "Gating Window Corse Tune is %d, fine tune is %d(number is %d[%d-%d])\r\n", opt_gw_coarse_value, opt_gw_fine_value, max, first_bit_set((void *)dqs_gw[c], DQS_GW_FINE_MAX), first_bit_set((void *)dqs_gw[c], DQS_GW_FINE_MAX) + max - 1);

            /* setup the opt coarse value and fine value according to calibration result */
            err = dqsi_gw_dly_coarse_factor_handler_rank0(dqsi_gw_dly_coarse_tbl[c]);
            if (DRAMC_CAL_FAIL <= err) {
                BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
                goto __end;
            }
            err = dqsi_gw_dly_fine_factor_handler_rank0(dqsi_gw_dly_fine_tbl[f]);
            if (DRAMC_CAL_FAIL <= err) {
                BL_PRINT(LOG_ERROR, "Fail with [%s at %d]\r\n", __FILE__, __LINE__);
                goto __end;
            }
        }
        else {
            BL_PRINT(LOG_ERROR, "Cannot find any pass-window\r\n");
            BL_PRINT(LOG_ERROR, "dqs_gw\r\n");
            for (i = 0; i < DQS_GW_COARSE_MAX; i++) {
                for (c = 0; c < DQS_GW_FINE_MAX >> 3; c++) {
                    BL_PRINT(LOG_ERROR, "[%d][%d]:%d", i, c, dqs_gw[i][c]);
                }
            }
            BL_PRINT(LOG_ERROR, "dqs_gw\r\n");
            err = DRAMC_CAL_GW_FAIL_OPT_VAL;
        }
        /* disable DQS gating window counter */
        DRV_ClrReg32_NPW(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTEN);
        Data_Mem_Barrier();
    }
__end:

    return err;
}

/*
 * ett_print_dqs_gw_after_finish_loop_n: do something after finish one loop
 * @n: recursive function density
 *      - zero means leaf
 * Return: dramc_cal_err_code
 */
static dramc_cal_err_code ett_print_dqs_gw_after_finish_loop_n(unsigned int n) 
{
    return DRAMC_CAL_PASS;
}

/*
 * ett_print_dqs_gw_err_handler: do error handle if having any error.
 * @err: dramc_cal_err_code
 * Return: void
 */
static void ett_print_dqs_gw_err_handler(dramc_cal_err_code err)
{
    if (DRAMC_CAL_FAIL <= err) {
        /* disable DQS gating window counter */
        DRV_ClrReg32(DRAMC_SPCMD, DRAMC_SPCMD_DQSGCNTEN);

        DDR_PHY_RESET();
    }
}


/* ============================= */
/*   External Functions          */
/* ============================= */

/*
 * dqsi_gw_dly_coarse_factor_handler_rank0: set coarse tune gating window
 * @factor_value: coarse tune value
 * Return: dramc_cal_err_code
 */
dramc_cal_err_code dqsi_gw_dly_coarse_factor_handler_rank0(unsigned char factor_value)
{
    kal_uint32 value;
    kal_uint32 com_idx;

    // coarse tune maximum value is 31 (number is 32).
    if (32 <= (unsigned int)factor_value) {
        BL_PRINT(LOG_ERROR, "[%s at %d]. factor_value[%d] should be smaller than %d\r\n", \
            __FILE__, __LINE__, (unsigned int)factor_value, 32);
        return DRAMC_CAL_GW_FAIL_CORSE_TUNE;
    }
    value = (DRV_Reg32(DRAMC_DQSCTL1/* 0xE0 */) & (~DRAMC_DQSCTL1_DQSINCTL_MASK))   /* Reserve original values for DRAMC_DQSCTL1 */
        | DRAMC_DQSCTL1_DQSINCTL(factor_value >> 2);         /* DQSINCTL: DRAMC_DQSCTL1[26:24],       3bits */
    DRV_WriteReg32(DRAMC_DQSCTL1/* 0xE0 */, value);

    value = DRV_Reg32(DRAMC_DQSGCTL/* 0x124 */);
    for (com_idx = 0; com_idx < ((MAX_DQ_DATA_WIDTH / DQ_NUMBER_PER_DQS)>>1); com_idx++) {
        value &= ~(DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANKn_COMi(0, com_idx, DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0_MASK));  /* Reserve original values for DRAMC_DQSGCTL/ */
        value |= DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANKn_COMi(0, com_idx, factor_value); /* R0DQSG_COARSE_DLY_COM0/1: DRAMC_DQSGCTL[1:0]/[5:4], 2 bits */
    }
    DRV_WriteReg32_NPW(DRAMC_DQSGCTL/* 0x124 */, value);
    Data_Mem_Barrier();
    return DRAMC_CAL_PASS;
}

/*
 * dqsi_gw_dly_coarse_factor_handler_rank1: set coarse tune gating window
 * @factor_value: coarse tune value
 * Return: dramc_cal_err_code
 */
dramc_cal_err_code dqsi_gw_dly_coarse_factor_handler_rank1(unsigned char factor_value)
{
    kal_uint32 value;
    kal_uint32 com_idx;

    // coarse tune maximum value is 31 (number is 32).
    if (32 <= (unsigned int)factor_value) {
        BL_PRINT(LOG_ERROR, "[%s at %d]. factor_value[%d] should be smaller than %d\r\n", \
            __FILE__, __LINE__, (unsigned int)factor_value, 32);
        return DRAMC_CAL_GW_FAIL_CORSE_TUNE;
    }
    value = (DRV_Reg32(DRAMC_DQSCTL1/* 0xE0 */) & (~DRAMC_DQSCTL1_DQSINCTL_MASK))   /* Reserve original values for DRAMC_DQSCTL1 */
        | DRAMC_DQSCTL1_DQSINCTL(factor_value >> 2);         /* DQSINCTL: DRAMC_DQSCTL1[26:24],       3bits */
    DRV_WriteReg32(DRAMC_DQSCTL1/* 0xE0 */, value);


    value = DRV_Reg32(DRAMC_DQSGCTL/* 0x124 */);
    for (com_idx = 0; com_idx < ((MAX_DQ_DATA_WIDTH / DQ_NUMBER_PER_DQS)>>1); com_idx++) {
        value &= ~(DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANKn_COMi(1, com_idx, DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANK0_COM0_MASK));  /* Reserve original values for DRAMC_DQSGCTL/ */
        value |= DRAMC_DQSGCTL_DLY_SEL_RXDQS_RANKn_COMi(1, com_idx, factor_value); /* R1DQSG_COARSE_DLY_COM0/1: DRAMC_DQSGCTL[3:2]/[7:6], 2 bits */
    }
    DRV_WriteReg32_NPW(DRAMC_DQSGCTL/* 0x124 */, value);
    Data_Mem_Barrier();
    return DRAMC_CAL_PASS;
}

/*
 * dqsi_gw_dly_fine_factor_handler_rank0: set fine tune gating window
 * @factor_value: fine tune value
 * Return: dramc_cal_err_code
 */
dramc_cal_err_code dqsi_gw_dly_fine_factor_handler_rank0(unsigned char factor_value)
{
    kal_uint32 value;
    kal_uint32 dqs_idx;

    // fine tune value shouldn't be larger than DRAMC_RxDQSIEN_DQS0IEN_MASK.
    if (DRAMC_RxDQSIEN_DQS0IEN_MASK < (unsigned int)factor_value) {
        BL_PRINT(LOG_ERROR, "[%s at %d]. factor_value[%d] shouldn't be larger than %d]\r\n", \
            __FILE__, __LINE__, (unsigned int)factor_value, DRAMC_RxDQSIEN_DQS0IEN_MASK);
        return DRAMC_CAL_GW_FAIL_CORSE_TUNE;

    }

    value = DRV_Reg32(DRAMC_R0DQSIEN/* 0x94 */);
    for (dqs_idx = 0; dqs_idx < (MAX_DQ_DATA_WIDTH / DQ_NUMBER_PER_DQS); dqs_idx++) {
        value &= ~(DRAMC_RxDQSIEN_DQSiIEN(dqs_idx, DRAMC_RxDQSIEN_DQS0IEN_MASK));    /* Reserve original values for DRAMC_DQSIEN[31] */
        value |= DRAMC_RxDQSIEN_DQSiIEN(dqs_idx, factor_value); /* DQS[dqs_idx]IEN: DRAMC_DQSIEN[dqs_idx*8+6:dqs_idx*8], 7 bits */
    }
    DRV_WriteReg32_NPW(DRAMC_R0DQSIEN/* 0x94 */, value);
    Data_Mem_Barrier();
    return DRAMC_CAL_PASS;
}

/*
 * dqsi_gw_dly_fine_factor_handler_rank1: set fine tune gating window
 * @factor_value: fine tune value
 * Return: dramc_cal_err_code
 */
dramc_cal_err_code dqsi_gw_dly_fine_factor_handler_rank1(unsigned char factor_value)
{
    kal_uint32 value;
    kal_uint32 dqs_idx;

    // fine tune value shouldn't be larger than DRAMC_RxDQSIEN_DQS0IEN_MASK.
    if (DRAMC_RxDQSIEN_DQS0IEN_MASK < (unsigned int)factor_value) {
        BL_PRINT(LOG_ERROR, "[%s at %d]. factor_value[%d] shouldn't be larger than %d\r\n", \
            __FILE__, __LINE__, (unsigned int)factor_value, DRAMC_RxDQSIEN_DQS0IEN_MASK);
        return DRAMC_CAL_GW_FAIL_CORSE_TUNE;

    }
    value = DRV_Reg32(DRAMC_R1DQSIEN/* 0x98 */);
    for (dqs_idx = 0; dqs_idx < (MAX_DQ_DATA_WIDTH / DQ_NUMBER_PER_DQS); dqs_idx++) {
        value &= ~(DRAMC_RxDQSIEN_DQSiIEN(dqs_idx, DRAMC_RxDQSIEN_DQS0IEN_MASK));    /* Reserve original values for DRAMC_DQSIEN[31] */
        value |= DRAMC_RxDQSIEN_DQSiIEN(dqs_idx, factor_value); /* DQS[dqs_idx]IEN: DRAMC_DQSIEN[dqs_idx*8+6:dqs_idx*8], 7 bits */
    }
    DRV_WriteReg32_NPW(DRAMC_R1DQSIEN/* 0x98 */, value);
    Data_Mem_Barrier();
    return DRAMC_CAL_PASS;
}

/*
  * Main function : 
  *     - do DQS gating window calibration. 
  * Return : error code.
  * Related registers
  *     Coarse tune
  *         - Unit is DRAM Clock Cycle
  *         - DQSCTL1 (3 bits) (2T for 2X mode and 1T for 1X mode)
  *         - DQSGCTL (2 bits for each rank 2 DQS) (0.5T) 
  * Fine tune
  *         - Unit is about 18 ps
  *     - R0DQSIEN (7 bits for rank 0 each DQS)
  *         - R1DQSIEN (7 bits for rank 1 each DQS)
  * Algorithm  (DR algorithm tune coarse with fixed fine first. Then use the optimized coarse tune setting to find best fine tune.) (Calibration all DQS gating window one time.)
  *     - Scan the whole matrix with coarse tune (0~17) and fine tune (0~120 with step 8).
  *     - Select the coarse tune with max pass (if the same pass, select the one with larger coarse tune)
  *     - Select the fine tune as the center of continuous 1s.
*/
dramc_cal_err_code do_dqs_gw_calib_1(unsigned char * p_gw_coarse_value, unsigned char * p_gw_fine_value)
{
    int result;
    print_callbacks cbs = {
        .ett_print_banner = ett_print_dqs_gw_banner,
        .ett_print_before_start_loop_zero = ett_print_dqs_gw_before_start_loop_zero,
        .ett_print_before_each_round_of_loop_zero = ett_print_dqs_gw_before_each_round_of_loop_zero,
        .ett_print_result = ett_print_dqs_gw_result_1, //difference between do_dqs_gw_calib_2
        .ett_print_after_each_round_of_loop_zero = ett_print_dqs_gw_after_each_round_of_loop_zero,
        .ett_calc_opt_value = ett_calc_dqs_gw_opt_value,
        .ett_print_after_finish_loop_n = ett_print_dqs_gw_after_finish_loop_n,
        .ett_print_err_handler = ett_print_dqs_gw_err_handler,
    };
    /* Description :
     *      - Coarse tune calls fine tune recursively.
     *      - Main purpose is to create dqs_gw[][] matrix which stores the calibration result and print.
     * Output
     *                      0    8   16   24   32   40   48   56   64   72   80   88   96  104  112  120
     *      --------------------------------------------------------------------------------
     *      0000:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0001:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0002:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0003:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0004:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0005:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0006:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0007:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0008:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      0009:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      000A:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      000B:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      000C:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     *      000D:|    0    0    0    0    0    0    0    0    0    0    0    0    0    1    1    1
     *      000E:|    0    0    0    0    0    0    1    1    1    1    1    1    1    1    1    1
     *      000F:|    1    1    1    1    1    1    1    1    1    1    1    1    1    0    0    0
     *      0010:|    1    1    1    1    1    1    1    0    0    0    0    0    0    0    0    0
     *      0011:|    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0    0
     */
  
    if (ETT_TUNING_FACTOR_NUMS(dqs_gw_tuning_factors) > 0) {
        result = ett_recursive_factor_tuning(ETT_TUNING_FACTOR_NUMS(dqs_gw_tuning_factors)-1, dqs_gw_tuning_factors, &cbs);
    } else {
        return DRAMC_CAL_GW_FAIL_TUNING_NUM;
    }

    *p_gw_coarse_value = opt_gw_coarse_value;
    *p_gw_fine_value = opt_gw_fine_value;

    return result;
}

