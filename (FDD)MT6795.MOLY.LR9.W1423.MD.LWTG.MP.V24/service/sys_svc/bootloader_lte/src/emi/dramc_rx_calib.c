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
 *   dramc_rx_calib.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the rx dqs/dq skew calibration
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
 * update auto calibration code for MT6290M and MT6290
 *
 * removed!
 * removed!
 * 1.update auto-k for SIP-Pin MUX and fix some bugs
 * 2.update MDL content
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
/*   Configuration, Definition   */
/* ============================= */
// TODO: We Need to confirm minimum rx window
#if defined(__IC_SLT_LOADER__)
#define RX_MINI_WINDOW_SIZE     (42)
#else
#define RX_MINI_WINDOW_SIZE     (1)
#endif
/* ============================= */
/*   Prototypes                  */
/* ============================= */
/* RX DQS/DQ delay Prototype */
typedef struct _RXDQS_PERBIT_DLY_T
{
    S8 min_cur;
    S8 max_cur;
    S8 min_best;
    S8 max_best;
    U8 center;
    U8 dq_dly_last;
} RXDQS_PERBIT_DLY_T;

/* ============================= */
/*   Global Variables            */
/* ============================= */
static unsigned char dq_delay_per_bit[MAX_DQ_DATA_WIDTH];
static RXDQS_PERBIT_DLY_T dqs_perbit_dly[MAX_DQ_DATA_WIDTH];
static unsigned char dqs_delay[MAX_DQ_DATA_WIDTH/DQ_NUMBER_PER_DQS];
static unsigned int test_len = 0x100;
static unsigned char rx_dq_dly_tbl[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};
static unsigned char rx_dqs_dly_tbl[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
    64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79,
    80, 81, 82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95,
    96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111,
    112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122, 123, 124, 125, 126, 127
};

extern unsigned int dq_data_width;
extern unsigned int is_mt6290m;
#if defined(BL_ENABLE)
extern const LOG_LEVEL bootloader_debug_level;
#else
extern const RAMC_LOG_LEVEL bootloader_debug_level;
#endif

#define MAX_RX_DQDLY_TAPS   (sizeof(rx_dq_dly_tbl)/sizeof(unsigned char))
#define MAX_RX_DQSDLY_TAPS  (sizeof(rx_dqs_dly_tbl)/sizeof(unsigned char))
/* ============================= */
/*   Internal Function           */
/* ============================= */
/*
 * dramc_rx_calib_dbg_print: print dramc rx dq delay register
 * Return void
 */
static void dramc_rx_calib_dbg_print(void)
{
    if(LOG_DEBUG == bootloader_debug_level) {
        BL_PRINT(LOG_DEBUG, "*DQIDLY1 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY1));
        BL_PRINT(LOG_DEBUG, "*DQIDLY2 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY2));
        BL_PRINT(LOG_DEBUG, "*DQIDLY3 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY3));
        BL_PRINT(LOG_DEBUG, "*DQIDLY4 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY4));
        BL_PRINT(LOG_DEBUG, "*DQIDLY5 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY5));
        BL_PRINT(LOG_DEBUG, "*DQIDLY6 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY6));
        BL_PRINT(LOG_DEBUG, "*DQIDLY7 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY7));
        BL_PRINT(LOG_DEBUG, "*DQIDLY8 = 0x%x\r\n", DRV_Reg32(DRAMC_DQIDLY8));

        BL_PRINT(LOG_DEBUG, "*DRAMC_R0DELDLY = 0x%x\r\n", DRV_Reg32(DRAMC_R0DELDLY));
    }
}

/*
 * do_sw_rx_dly_dq: find the boundary by dq delay
 * Return dramc_cal_err_code
 * Description: this is step 1 of dramc rx dq/dqs skew calibration
    - find boundary value of dq delay when dqs delay is zero.
 */
static dramc_cal_err_code do_sw_rx_dly_dq(void)
{
    unsigned int i;
    unsigned int dq_delay_done[MAX_DQ_DATA_WIDTH];
    unsigned int dq_tap;
    unsigned int data;
    unsigned int dqidly[MAX_DQ_DATA_WIDTH>>2];
    unsigned int cmp_err = 0x00000000;

    dramc_rx_calib_dbg_print();

    /* set DQS delay to rx_dqs_dly_tbl[0] at first */
    DRV_WriteReg32(DRAMC_R0DELDLY, rx_dqs_dly_tbl[0]);

    // set DQ delay to rx_dq_dly_tbl[0].
    data = 0;
    for (i = 0; i < 4; i++) {
        data |= DRAMC_DQnIDLY(i, rx_dq_dly_tbl[0]);
    }
    for (i = 0; i < dq_data_width>>2; i++) {
        DRV_WriteReg32(DRAMC_DQIDLY(i), data);
    }

    // set DQ delay structure to 0x0.
    for (i = 0; i < dq_data_width; i++) {
        dq_delay_per_bit[i] = rx_dq_dly_tbl[0]; 
        dq_delay_done[i] = 0x0;
    }

    // delay DQ to find all failed 
    for(dq_tap = 0 ; dq_tap < MAX_RX_DQDLY_TAPS; dq_tap++) {
        
        /* set test patern length */
        DRV_WriteReg32(DRAMC_TEST2_1, 0x55000000);
        data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
        DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_2_PAT1(data & 0xAA) | DRAMC_TEST2_2_OFFSET(test_len));
        //Test Agent 2 write enabling, Test Agent 2 read enabling
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); 
        
        while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));
        /* From 6575, we need to wait 400 ns */
        BL_GPT_UDELAY(1);

        cmp_err = DRV_Reg32(DRAMC_CMP_ERR);
        BL_PRINT(LOG_DEBUG, "cmp_err:%x\r\n", cmp_err);
        DRV_ClrReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //disable test agent2 r/w
        // all dq is failed
        if (cmp_err == 0xFFFFFFFF) {
            break; 
        }

        // Avoid rx_dq_dly_tbl[dq_tap+1] overflow
        if (dq_tap != rx_dq_dly_tbl[MAX_RX_DQDLY_TAPS-1]) {
            /* Bit i compare result
             *     -Compare success & never fail before, record the delay value. (dq_delay_per_bit[i] = delay value)
             * -Compare fail. Record fail. (dq_delay_done[i] = 1)
             */
            for (i = 0; i < dq_data_width; i++)
            {
                if (!(cmp_err & (0x1 << i)) && dq_delay_done[i] == 0){
                    dq_delay_per_bit[i] = rx_dq_dly_tbl[dq_tap+1]; 
                } else { // found boundary value
                    dq_delay_done[i] = 1;
                }
                BL_PRINT(LOG_DEBUG, "%d)0x%x \r\n", i, dq_delay_per_bit[i]);
            }
            BL_PRINT(LOG_DEBUG, "\r\n");
            // calculate dqidly[i] value
            for (i = 0; i < dq_data_width; i += 4) {
                dqidly[i/4] = DRAMC_DQnIDLY(i+0, dq_delay_per_bit[i+0]) + DRAMC_DQnIDLY(i+1, dq_delay_per_bit[i+1])\
                            + DRAMC_DQnIDLY(i+2, dq_delay_per_bit[i+2]) + DRAMC_DQnIDLY(i+3, dq_delay_per_bit[i+3]);
                BL_PRINT(LOG_DEBUG, "dqidly[%d]=0x%x\r\n", i/4, dqidly[i/4]);
            }
            for (i = 0; i < dq_data_width>>2; i++) {
                DRV_WriteReg32(DRAMC_DQIDLY(i), dqidly[i]);
            }
        }
    }

    dramc_rx_calib_dbg_print();

    return DRAMC_CAL_PASS;
}

/*
 * do_sw_rx_find_dqs_center: find the dqs center
 * Return dramc_cal_err_code
 * Description: this is step 2 of dramc rx dq/dqs skew calibration
 */
static dramc_cal_err_code do_sw_rx_find_dqs_center(void)
{
    unsigned int i,j;
    unsigned int data;
    unsigned int dqs_input_delay;
    unsigned int cmp_err;

    // Intialize dqs_perbit_dly[i]
    for (i = 0; i < dq_data_width; i++) {
        dqs_perbit_dly[i].min_cur = -1;
        dqs_perbit_dly[i].max_cur = -1;
        dqs_perbit_dly[i].min_best = -1;
        dqs_perbit_dly[i].max_best = -1;
        dqs_perbit_dly[i].center = 0;
        dqs_perbit_dly[i].dq_dly_last = dq_delay_per_bit[i];
    }

    /* Find the minimum and maximum DQS input delay */
    for (i = 0; i < MAX_RX_DQSDLY_TAPS; i++)
    {
        dqs_input_delay = DRAMC_RxDELDLY_DELiDLY(0, rx_dqs_dly_tbl[i]) + DRAMC_RxDELDLY_DELiDLY(1, rx_dqs_dly_tbl[i])\
                             + DRAMC_RxDELDLY_DELiDLY(2, rx_dqs_dly_tbl[i]) + DRAMC_RxDELDLY_DELiDLY(3, rx_dqs_dly_tbl[i]);
        DRV_WriteReg32(DRAMC_R0DELDLY, dqs_input_delay);

        /* set test patern length */
        data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
        DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_2_PAT1(data) | DRAMC_TEST2_2_OFFSET(test_len));
        //Test Agent 2 write enabling, Test Agent 2 read enabling
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); 
        
        while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));

        /* From 6575, we need to wait 400 ns */
        BL_GPT_UDELAY(1);

        cmp_err = DRV_Reg32(DRAMC_CMP_ERR);
        DRV_ClrReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //disable test agent2 r/w

        /*
         * if bit x test pass the first time, record to min input delay. (dqs_per_bit[x].min_cur = delay value.)
         * If bit x already had min value and no max value and pass fail => max value is this delay-1. (dqs_per_bit[x].max_cur = delay value-1)
         * If bit x already had min value and no max value and pass and delay value = 127 => max value = 127 (dqs_per_bit[x].max_cur = 127)
         */
        
        for (j = 0; j < dq_data_width; j++)
        {
            if ((dqs_perbit_dly[j].min_cur == -1) && ((cmp_err&((U32)1<<j)) == 0x0))
            {
                // min pass delay
                dqs_perbit_dly[j].min_cur = rx_dqs_dly_tbl[i];
            }
            // we have already found minimum pass delay, but we haven't found maximum pass delay.
            if ((-1 != dqs_perbit_dly[j].min_cur) && (-1 == dqs_perbit_dly[j].max_cur))
            {
                // max pass delay
                if (0x0 != (cmp_err&((U32)1<<j))) {
                    dqs_perbit_dly[j].max_cur = rx_dqs_dly_tbl[i - 1];
                } else if (rx_dqs_dly_tbl[i] == rx_dqs_dly_tbl[MAX_RX_DQSDLY_TAPS-1]){ // find maximum predefined dqs delay
                    dqs_perbit_dly[j].max_cur = rx_dqs_dly_tbl[MAX_RX_DQSDLY_TAPS-1];
                } else {
                    // still not find maximum pass delay
                    continue;
                }

                // there may be more than 1 pass range, find the max range
                // ex: x11xxxxxx11111111111111xx...(get the second one)
                if ((dqs_perbit_dly[j].max_cur - dqs_perbit_dly[j].min_cur) > (dqs_perbit_dly[j].max_best - dqs_perbit_dly[j].min_best))
                {
                    dqs_perbit_dly[j].max_best = dqs_perbit_dly[j].max_cur;
                    dqs_perbit_dly[j].min_best = dqs_perbit_dly[j].min_cur;
                }
                // clear to find the next pass range if it has
                dqs_perbit_dly[j].max_cur = -1;
                dqs_perbit_dly[j].min_cur = -1;
            }

        }
    }

    /* Get dqs delay center per bit */
    for (j = 0; j < dq_data_width; j++) {
        if ((dqs_perbit_dly[j].max_best != -1) && (dqs_perbit_dly[j].min_best != -1)) {
            dqs_perbit_dly[j].center = (dqs_perbit_dly[j].max_best + dqs_perbit_dly[j].min_best) / 2;
            BL_PRINT(LOG_DEBUG, "dqs_perbit_dly[%d].center=0x%x\r\n", j, dqs_perbit_dly[j].center);
        }
    }

    return DRAMC_CAL_PASS;
}

/*
 * do_sw_rx_calc_opt_val: find the dqs and dq delay optimal value
 * Return dramc_cal_err_code
 * Description: this is step 3 of dramc rx dq/dqs skew calibration
 */
static dramc_cal_err_code do_sw_rx_calc_opt_val(void)
{
    unsigned int i, j;
    unsigned int data;
    unsigned int dq_dly_max;
    unsigned int max;

    // we get the delay value of the 4 DQS (max of center)
    for (i = 0; i < DQS_NUMBER; i++)
    {
        max = 0;
        // find the max of center for each dqs
        for (j = 0; j < DQ_NUMBER_PER_DQS; j++) {
            // check RX window Size
            if (RX_MINI_WINDOW_SIZE > 
                (signed int)dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].max_best - 
                (signed int)dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].min_best) {
                BL_PRINT(LOG_ERROR, "RX window size (%d) is smaller than %d\r\n",
                (signed int)dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].max_best - 
                (signed int)dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].min_best, RX_MINI_WINDOW_SIZE);
                return DRAMC_CAL_RX_FAIL_OPT_VAL;
            }
            if (dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].center > max) {
                max = dqs_perbit_dly[i*DQ_NUMBER_PER_DQS+j].center;
            }
        }
        // save dqs delay
        dqs_delay[i] = max;
        BL_PRINT(LOG_DEBUG, "dqs_delay[%d]=0x%x\r\n", i, max);
    }
    data = 0;
    for (i = 0; i < DQS_NUMBER; i++) {
/* For MT6290M, it is 16-bit DRAM. DQS0 => DQS2, DQS1 => DQS0. */
        if (TRUE == is_mt6290m) {
            if (0 == i) {
                data |= DRAMC_RxDELDLY_DELiDLY(0, dqs_delay[i]);
            } else if (1 == i) {
                data |= DRAMC_RxDELDLY_DELiDLY(2, dqs_delay[i]);
            } else {
                BL_PRINT(LOG_ERROR, "DQS Number(%d) should be smaller than 2\r\n", DQS_NUMBER);
                return DRAMC_CAL_RX_FAIL_DQS;           
            }
        } else {
            data |= DRAMC_RxDELDLY_DELiDLY(i, dqs_delay[i]);
        }
    }
    /* set dqs input delay */
    DRV_WriteReg32(DRAMC_R0DELDLY, data);
    DRV_WriteReg32(DRAMC_R1DELDLY, data);

    // delay DQ ,let dqsdly_ok_center == DQS_delay
    for (i = 0; i < dq_data_width; i += 4) {
        // every 4-bit dq have the same delay register address
        // dq_dly_max: taps for dq delay to be add
        for (j = 0; j < 4; j++) {
            dq_dly_max =  dqs_delay[i/DQ_NUMBER_PER_DQS] - dqs_perbit_dly[i+j].center;
            BL_PRINT(LOG_DEBUG, "1.bit:%d)dq_per_bit_dly:0x%x,dq_dly:0x%x\r\n", i + j, dqs_perbit_dly[i+j].dq_dly_last, dq_dly_max);
            data = dqs_perbit_dly[i+j].dq_dly_last + dq_dly_max;
            data = ((data > (rx_dq_dly_tbl[MAX_RX_DQDLY_TAPS-1])) ? (rx_dq_dly_tbl[MAX_RX_DQDLY_TAPS-1]) : data);
            dqs_perbit_dly[i+j].dq_dly_last = data;

            BL_PRINT(LOG_DEBUG, "2.bit:%d)dq_per_bit_dly:0x%x\r\n", i+j, dqs_perbit_dly[i+j].dq_dly_last);
        }
        data = 0;
        for (j = 0; j < 4; j++) {
            data |= DRAMC_DQnIDLY(i+j, dqs_perbit_dly[i+j].dq_dly_last);
        }
        DRV_WriteReg32(DRAMC_DQIDLY(i/4), data);
    }
    for (j = 0; j < dq_data_width; j++) {
        BL_PRINT(LOG_DEBUG, "%d)min:0x%x,max:0x%x\r\n",j, dqs_perbit_dly[j].min_best, dqs_perbit_dly[j].max_best);
    }

    /* Read DRAMC_base to make sure all data has been written to DRAMC register */
    DRV_Reg32(DRAMC_base);
    Data_Mem_Barrier();

    return DRAMC_CAL_PASS;
}

/*
 * do_sw_rx_print_result: print rx dq/dqs skew calibration result
 * Return void
 */
static void do_sw_rx_print_result(void)
{
    unsigned int i, j;

    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "        RX  DQS perbit delay software calibration \r\n");
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "1.0-%d bit dq delay value\r\n", dq_data_width - 1);
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "bit|     0  1  2  3  4  5  6  7  8  9\r\n");
    BL_PRINT(LOG_INFO, "--------------------------------------");
    for (i = 0; i < dq_data_width; i++)
    {
        j = i / 10;
        if (i == (j*10))
        {
            BL_PRINT(LOG_INFO, "\r\n");
            BL_PRINT(LOG_INFO, "%d |    ", i);
        }
        BL_PRINT(LOG_INFO, "%d ", dq_delay_per_bit[i]);
    }
    BL_PRINT(LOG_INFO, "\r\n--------------------------------------\r\n\r\n");
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "2.dqs window\r\nx=pass dqs delay value (min~max)center \r\ny=0-7bit DQ of every group\r\n");
    BL_PRINT(LOG_INFO, "input delay:");
    for (i = 0; i < DQS_NUMBER; i++) {
        BL_PRINT(LOG_INFO, "DQS%d =%d ", i, dqs_delay[i]);
    }
    BL_PRINT(LOG_INFO, "\r\n");
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    for (i = 0; i < DQS_NUMBER; i++) {
        BL_PRINT(LOG_INFO, "bit    DQS%d  opt  ", i);
    }
    BL_PRINT(LOG_INFO, "\r\n");
    for (i = 0; i < DQ_NUMBER_PER_DQS; i++)
    {
        for (j = 0; j < dq_data_width; j += 8) {
            BL_PRINT(LOG_INFO, "%d  (%d~%d)%d  ", \
                i+j,  dqs_perbit_dly[i+j].min_best, dqs_perbit_dly[i+j].max_best, dqs_perbit_dly[i+j].center);
        }
        BL_PRINT(LOG_INFO, "\r\n");
    }
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "3.dq delay value last\r\n");
    BL_PRINT(LOG_INFO, "==================================================================\r\n");
    BL_PRINT(LOG_INFO, "bit|     0  1  2  3  4  5  6  7  8  9\r\n");
    BL_PRINT(LOG_INFO, "--------------------------------------");
    for (i = 0; i < dq_data_width; i++)
    {
        j = i / 10;
        if (i == (j*10))
        {
            BL_PRINT(LOG_INFO, "\r\n");
            BL_PRINT(LOG_INFO, "%d |    ", i);
        }
        BL_PRINT(LOG_INFO, "%d ", dqs_perbit_dly[i].dq_dly_last);
    }
    BL_PRINT(LOG_INFO, "\r\n==================================================================\r\n");
}
/* ============================= */
/*   External Function           */
/* ============================= */

/* Description
  * RX DQ/DQS per bit calibration.
  * Registers
  * - DQIDLY[1:8] : one register had 4 settings (4bits: 0~15, unit 20ps) with corresponding DQx
  * - R0DELDLY : 4 settings for rank 0 DQS0~DQS3. 7 bits (0~127) with unit 30ps. 
  * - R1DELDLY : 4 settings for rank 1 DQS0~DQS3. 7 bits (0~127) with unit 30ps.
  * Algorithm
  * - Set DQS/DQ input delay to 0.
  * - Delay all DQs from 0 to 15 until all failed.
  * - Delay DQSs from 0 to 127 to find the pass range (min & max) of each DQ. Further find the largest pass range.
  * - For each DQS, find the largest middle value of corresponding DQ byte. Then use this value to set each DQS input delay.
  * - For each DQ, find the difference between original middle DQS delay and max DQS delay per byte. Then delay the difference more to align the middle of DQS per byte.
  */
dramc_cal_err_code do_sw_rx_dq_dqs_calib(void)
{
    dramc_cal_err_code result = DRAMC_CAL_PASS;

    /* Step 1: Delay dq to find dq delay boundary. */
    result = do_sw_rx_dly_dq();
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }
    // After step 1, dq_delay_per_bit[0:31] value non-zero mean the last valid settings when DQS input delay is 0. 
    // dq_delay_per_bit[0:31] value 0 means it is already failed when DQS input delay is 0. 
    // Also, current DQIDLY[1:8] settings is the setting of dq_delay_per_bit[0:31].
    // We got the dq input delay in dq_delay_per_bit[i]
    
    /* Step 2: find the dqs center */
    result = do_sw_rx_find_dqs_center();
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }
    /* Step 3: find the optimal value */
    result = do_sw_rx_calc_opt_val();
    if (DRAMC_CAL_FAIL <= result) {
        goto __end;
    }
    dramc_rx_calib_dbg_print();

__end:
    // finish we can put result now .
    do_sw_rx_print_result();

    return result;
}

