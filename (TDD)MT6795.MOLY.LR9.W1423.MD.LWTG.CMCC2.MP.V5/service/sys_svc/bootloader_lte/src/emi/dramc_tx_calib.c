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
 *   dramc_tx_calib.c
 *
 * Project:
 * --------
 *   MT6290
 *
 * Description:
 * ------------
 *  This file implements the dramc calibration of TX DQ/DQS skew.
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
 * 1.add EMI/RAMC fine clock off feature
 * 2.update initial dram
 * 3.enable SSC with -8%
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
 * fix dramc auto calibration for TX to change from unsigned to signed variable
 *
 * removed!
 * removed!
 * fix tx calibration and print more msg
 *
 * removed!
 * removed!
 * update auto-k for detecting RX/TX window size
 *
 * removed!
 * removed!
 * add mempll calib code
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
#include "dramc_dqs_gw.h"
#include "dramc_calib.h"

/* ============================= */
/*   Configuration, Definition   */
/* ============================= */
// TODO: We Need to confirm minimum tx window
#if defined(__IC_SLT_LOADER__)
#define TX_MINI_WINDOW_SIZE     (16)
#else
#define TX_MINI_WINDOW_SIZE     (1)
#endif

/* ============================= */
/*   Prototypes                  */
/* ============================= */
/* TX DQS/DQ delay Prototype */
typedef struct _TXDQS_PERBYTE_DLY_T
{
    S8 first_dqdly_pass;
    S8 last_dqdly_pass;
    S8 total_dqdly_pass;
    S8 first_dqsdly_pass;
    S8 last_dqsdly_pass;
    S8 total_dqsdly_pass;
    U8 best_dqdly;
    U8 best_dqsdly;
    U8 dq;
    U8 dqs;
} TXDQS_PERBYTE_DLY_T;

/* ============================= */
/*   Global Variables            */
/* ============================= */
/* optimal value */
static unsigned int opt_tx_dq[4];
static unsigned int opt_tx_dqs;
static unsigned int opt_tx_dqm;

/* dq output delay table */
static unsigned char tx_dq_dly_tbl[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};
/* dqs output delay table */
static unsigned char tx_dqs_dly_tbl[] = {
    0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15
};

extern unsigned int dq_data_width;
extern unsigned int is_mt6290m;

#define MAX_TX_DQDLY_TAPS   (sizeof(tx_dq_dly_tbl)/sizeof(unsigned char))
#define MAX_TX_DQSDLY_TAPS  (sizeof(tx_dqs_dly_tbl)/sizeof(unsigned char))
/* ============================= */
/*   Internal Functions          */
/* ============================= */
static void calib_clk_output_dly_factor_handler(unsigned int value)
{
    unsigned int data;

    //adjust CLK output delay
    data = DRV_Reg32(DRAMC_PADCTL1);
    data = data & (~DRAMC_PADCTL1_CLKDLY_MASK);
    data = data | DRAMC_PADCTL1_CLKDLY(value);
    DRV_WriteReg32(DRAMC_PADCTL1, data);

    data = DRV_Reg32(DRAMC_CLK1DELAY);
    data = data & (~DRAMC_CLK1DELAY_CLK1DLY_MASK);
    data = data | DRAMC_CLK1DELAY_CLK1DLY(value);
    DRV_WriteReg32_NPW(DRAMC_CLK1DELAY, data);
    Data_Mem_Barrier();
}

static void calib_cmd_addr_output_dly_factor_handler(unsigned int value)
{
    unsigned int data;
    //adjust CMD delay
    data = DRV_Reg32(DRAMC_CMDDLY0);
    data &= ~(DRAMC_CMDDLY(RA3DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA2DLY, DRAMC_CMMDLY_MASK)\
                 | DRAMC_CMDDLY(RA1DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA0DLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(RA3DLY, value) | DRAMC_CMDDLY(RA2DLY, value)\
            | DRAMC_CMDDLY(RA1DLY, value) | DRAMC_CMDDLY(RA0DLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY0, data);

    data = DRV_Reg32(DRAMC_CMDDLY1);
    data &= ~(DRAMC_CMDDLY(RA7DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA6DLY, DRAMC_CMMDLY_MASK)\
                 | DRAMC_CMDDLY(RA5DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA4DLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(RA7DLY, value) | DRAMC_CMDDLY(RA6DLY, value)\
            | DRAMC_CMDDLY(RA5DLY, value) | DRAMC_CMDDLY(RA4DLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY1, data);

    data = DRV_Reg32(DRAMC_CMDDLY2);
    data &= ~(DRAMC_CMDDLY(RA11DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA10DLY, DRAMC_CMMDLY_MASK)\
            | DRAMC_CMDDLY(RA9DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA8DLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(RA11DLY, value) | DRAMC_CMDDLY(RA10DLY, value)\
            | DRAMC_CMDDLY(RA9DLY, value) | DRAMC_CMDDLY(RA8DLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY2, data);

    data = DRV_Reg32(DRAMC_CMDDLY3);
    data &= ~(DRAMC_CMDDLY(BA2DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(BA1DLY, DRAMC_CMMDLY_MASK)\
                 | DRAMC_CMDDLY(BA0DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA12DLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(BA2DLY, value) | DRAMC_CMDDLY(BA1DLY, value)\
            | DRAMC_CMDDLY(BA0DLY, value) | DRAMC_CMDDLY(RA12DLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY3, data);

    data = DRV_Reg32(DRAMC_CMDDLY4);
    data &= ~(DRAMC_CMDDLY(CASDLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RASDLY, DRAMC_CMMDLY_MASK)\
                 | DRAMC_CMDDLY(CKEDLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(CSDLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(CASDLY, value) | DRAMC_CMDDLY(RASDLY, value)\
            | DRAMC_CMDDLY(CKEDLY, value) | DRAMC_CMDDLY(CSDLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY4, data);

    data = DRV_Reg32(DRAMC_CMDDLY5);
    data &= ~(DRAMC_CMDDLY(ODTDLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA13DLY, DRAMC_CMMDLY_MASK)\
                 | DRAMC_CMDDLY(WEDLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RESETDLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(ODTDLY, value) | DRAMC_CMDDLY(RA13DLY, value)\
            | DRAMC_CMDDLY(WEDLY, value) | DRAMC_CMDDLY(RESETDLY, value);
    DRV_WriteReg32(DRAMC_CMDDLY5, data);

    data = DRV_Reg32(DRAMC_DQSCAL0);
    data &= ~(DRAMC_CMDDLY(RA14DLY, DRAMC_CMMDLY_MASK) | DRAMC_CMDDLY(RA15DLY, DRAMC_CMMDLY_MASK));
    data |= DRAMC_CMDDLY(RA14DLY, value) | DRAMC_CMDDLY(RA15DLY, value);
    DRV_WriteReg32_NPW(DRAMC_DQSCAL0, data);
    Data_Mem_Barrier();
}

/* ============================= */
/*   External Functions          */
/* ============================= */
/* Description
  * TX DQ/DQS per byte calibration
  * Related registers
  * - PADCTL3 : DQS[0:3]ODLY (0x10011014)
  *     - 4 bits (0~15)
  *     - 1 step 20ps.
  * - PADCTL2 : DQM[0:3]DLY (0x10011010)
  *     - 4 bits (0~15)
  *     - 1 step 20ps.
  * - DQODLY[1:4] : DQ[0:31]DLY (0x10011200~0x1001120c)
  *     - 4 bits (0~15)
  *     - 1 step 20ps
  * - DRAMC_PADCTL1 
  *         - bit 27~bit 24 : clock delay.
  * - DRAMC_CMDDLY[0:5], DRAMC_DQSCAL0
  *     - Address/cmd delay
  * Algorithm
  * - Set DQ/DQM output delay to 0 and loop DQS output delay value from 0 to 15. Check the pass range.
  * - Set DQS output delay value to 0 and loop DQ/DQM output delay value from 0 to 15. Check the pass range.
  * - If two pass range equal, set both output delay to 8.
  * - If not equal, add (delay difference)/2 to the one with larger pass range.
  */
dramc_cal_err_code do_sw_tx_dq_dqs_calib(void)
{
    TXDQS_PERBYTE_DLY_T dqs_perbyte_dly[DQS_NUMBER];
    unsigned int data;
    unsigned int byte_idx, bit_idx;
    int idx;
    unsigned int cur_dly;
    unsigned int test_len = 0x3FF;
    unsigned int cmp_err_1;
    unsigned int dq;
    unsigned int finish_count;
    unsigned char dly_dqs_gw_coarse, dly_dqs_gw_fine;

    /* 0. Initialize Variable */
    for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
        dqs_perbyte_dly[byte_idx].first_dqdly_pass = 0;
        dqs_perbyte_dly[byte_idx].last_dqdly_pass = -1;
        dqs_perbyte_dly[byte_idx].first_dqsdly_pass = 0;
        dqs_perbyte_dly[byte_idx].last_dqsdly_pass = -1;
        dqs_perbyte_dly[byte_idx].best_dqdly= -1;
        dqs_perbyte_dly[byte_idx].best_dqsdly= -1;
        dqs_perbyte_dly[byte_idx].dq= 0;
        dqs_perbyte_dly[byte_idx].dqs= 0;
        dqs_perbyte_dly[byte_idx].total_dqdly_pass= 0;
        dqs_perbyte_dly[byte_idx].total_dqsdly_pass= 0;
    }
   
    /* 1. Tx DQS/DQ all zero*/
    /* 1.1 Set DQS & DQM output delay to zero */
    for (byte_idx = 0; byte_idx < 4; byte_idx++) {
        DRV_ClrReg32(DRAMC_PADCTL3, DRAMC_PADCTL3_DQSiDLY(byte_idx, DRAMC_PADCTL3_DQSDLY_MASK));
        DRV_ClrReg32(DRAMC_PADCTL2, DRAMC_PADCTL2_DQMiDLY(byte_idx, DRAMC_PADCTL2_DQMDLY_MASK));
    }
    /* 1.2 Set DQ output delay to zero */
    for (byte_idx = 0; byte_idx < 4; byte_idx++) {
        DRV_WriteReg32(DRAMC_DQODLY(byte_idx), 0x0);
    }

    // used for early break
    finish_count = 0;
    /* 2. fix DQ delay = 0, delay DQS to find the pass range  */
    for (idx = MAX_TX_DQSDLY_TAPS - 1; idx >= 0; idx--) {
        cur_dly = tx_dqs_dly_tbl[idx];
        /* 2.1 Set dqs delay */
        data = DRV_Reg32(DRAMC_PADCTL3);
        for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
/* For MT6290 SIP DRAM, it is 16-bit DRAM. DQS0 => DQS2, DQS1 => DQS0. */
            if (TRUE == is_mt6290m) {
                if (0 == byte_idx) {
                    data &= ~(DRAMC_PADCTL3_DQSiDLY(0, DRAMC_PADCTL3_DQSDLY_MASK));
                    data |= DRAMC_PADCTL3_DQSiDLY(0, cur_dly);
                } else if (1 == byte_idx) {
                    data &= ~(DRAMC_PADCTL3_DQSiDLY(2, DRAMC_PADCTL3_DQSDLY_MASK));
                    data |= DRAMC_PADCTL3_DQSiDLY(2, cur_dly);
                } else {
                    BL_PRINT(LOG_ERROR, "DQS Number(%d) should be smaller than 2\r\n", DQS_NUMBER);
                    return DRAMC_CAL_TX_FAIL_DQS;
                }
            } else {
                data &= ~(DRAMC_PADCTL3_DQSiDLY(byte_idx, DRAMC_PADCTL3_DQSDLY_MASK));
                data |= DRAMC_PADCTL3_DQSiDLY(byte_idx, cur_dly);
            }
        }
        DRV_WriteReg32(DRAMC_PADCTL3, data);
        
        /* 2.2 adjust CMD & ADDR & CLK output delay and then calibrate gating window */
        //adjust CMD addr output delay
        calib_cmd_addr_output_dly_factor_handler(cur_dly);
        //adjust CLK delay
        calib_clk_output_dly_factor_handler(cur_dly);
        //gating window calibration
        do_dqs_gw_calib_1(&dly_dqs_gw_coarse, &dly_dqs_gw_fine);

        /* 2.3 use test agent to find the pass range */
        /* set test patern length*/
        DRV_WriteReg32(DRAMC_TEST2_1, 0x55000000);

        data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
        DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_2_PAT1(data & 0xAA) | DRAMC_TEST2_2_OFFSET(test_len));

        //Test Agent 2 write enabling
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W); //enable write
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //enable read
        while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));
        /* From 6575, we need to wait 400ns, but in MT6290, we should not wait 400 ns */
        //delay_a_while(400);
        cmp_err_1 = DRV_Reg32(DRAMC_CMP_ERR);
        DRV_ClrReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //disable test agent2 r/w
        BL_PRINT(LOG_DEBUG, "DQS Delay = %d, cmp_err_1 = %x \r\n", cur_dly, cmp_err_1);

        /* 2.4 Find the dqs last pass */
        for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++)
        {
            if (dqs_perbyte_dly[byte_idx].last_dqsdly_pass == -1)
            {
                if ( !((cmp_err_1) & (0xFF << (byte_idx * 8))) )
                {
                    dqs_perbyte_dly[byte_idx].last_dqsdly_pass = cur_dly;
                    finish_count++;
                    BL_PRINT(LOG_DEBUG, "dqs_perbyte_dly.last_dqsdly_pass[%d]=%d,  finish count=%d \r\n", byte_idx, dqs_perbyte_dly[byte_idx].last_dqsdly_pass, finish_count);
                }
            }
        }

        // If finish_count is equal to DQS_NUMBER, it means fine all dqs last pass
        if (DQS_NUMBER == finish_count) {
            break;
        }
    }
        
    /* 3. Fix DQS delay = 0, delay DQ to find the pass range  */
    /* 3.1 adjust CMD & ADDR & CLK output delay and calibrate gating window */
    for (byte_idx = 0; byte_idx < 4; byte_idx++) {
        DRV_ClrReg32(DRAMC_PADCTL3, DRAMC_PADCTL3_DQSiDLY(byte_idx, DRAMC_PADCTL3_DQSDLY_MASK));
    }
    //adjust CMD addr output delay
    calib_cmd_addr_output_dly_factor_handler(0);
    //adjust CLK delay
    calib_clk_output_dly_factor_handler(0);
    //gating window calibration
    do_dqs_gw_calib_1(&dly_dqs_gw_coarse, &dly_dqs_gw_fine);

    // used for early break
    finish_count = 0;
    /* 3.2 delay DQ to find the pass range */
    for (idx = MAX_TX_DQDLY_TAPS - 1; idx >= 0; idx--) {
        cur_dly = tx_dq_dly_tbl[idx];
        /* 3.2.1 delay DQ output delay */
        data = DRV_Reg32(DRAMC_PADCTL2);
        for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
/* For MT6290 SIP DRAM, it is 16-bit DRAM. DQM0 => DQM2, DQM1 => DQM0. */
            if (TRUE == is_mt6290m) {
                if (0 == byte_idx) {
                    data &= ~(DRAMC_PADCTL2_DQMiDLY(0, DRAMC_PADCTL2_DQMDLY_MASK));
                    data |= DRAMC_PADCTL2_DQMiDLY(0, cur_dly);
             
                } else if (1 == byte_idx) {
                    data &= ~(DRAMC_PADCTL2_DQMiDLY(2, DRAMC_PADCTL2_DQMDLY_MASK));
                    data |= DRAMC_PADCTL2_DQMiDLY(2, cur_dly);
                } else {
                    BL_PRINT(LOG_ERROR, "DQM Number(%d) should be smaller than 2\r\n", DQS_NUMBER);
                    return DRAMC_CAL_TX_FAIL_DQM;
                } 
            } else {
                data &= ~(DRAMC_PADCTL2_DQMiDLY(byte_idx, DRAMC_PADCTL2_DQMDLY_MASK));
                data |= DRAMC_PADCTL2_DQMiDLY(byte_idx, cur_dly);
            }
        }
        DRV_WriteReg32(DRAMC_PADCTL2/* 0x10 */, data);
        data = 0;
        for (bit_idx = 0; bit_idx < DQ_NUMBER_PER_DQS; bit_idx++) {
            data |= DRAMC_DQnODLY(bit_idx, cur_dly);
        }
        for (byte_idx = 0; byte_idx < 4; byte_idx++) {
            DRV_WriteReg32(DRAMC_DQODLY(byte_idx), data); // Set dq[7+byte*8:byte*8] delay
        }

        BL_PRINT(LOG_DEBUG, "0x%x = 0x%x\n", (kal_uint32)DRAMC_DQODLY(0), DRV_Reg32(DRAMC_DQODLY(0)));
        /* 3.2.2 use test agent to find the pass range */
        /* set test patern length*/
        DRV_WriteReg32(DRAMC_TEST2_1, 0x55000000);
        data = DRV_Reg32(DRAMC_TEST2_2) >> DRAMC_TEST2_2_PAT1_SHIFT;
        DRV_WriteReg32(DRAMC_TEST2_2, DRAMC_TEST2_2_PAT1(data & 0xAA) | DRAMC_TEST2_2_OFFSET(test_len));
        //Test Agent 2 write enabling
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W); //enable write
        DRV_SetReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //enable read
        while(!(DRV_Reg32(DRAMC_TESTRPT)&DRAMC_TESTRPT_DM_CMP_CPT));
        //delay_a_while(400);
        cmp_err_1 = DRV_Reg32(DRAMC_CMP_ERR);
        BL_PRINT(LOG_DEBUG, "DQ Delay = %d, cmp_err_1 = %x\r\n", cur_dly, cmp_err_1);
        DRV_ClrReg32(DRAMC_CONF2, DRAMC_CONF2_TEST2W | DRAMC_CONF2_TEST2R); //disable test agent2 r/w

        /* 3.2.3 Find the dq last pass */
        for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
            if (dqs_perbyte_dly[byte_idx].last_dqdly_pass == -1) {
                if ( !(cmp_err_1 & (0xFF << (byte_idx * 8))) ) {
                    dqs_perbyte_dly[byte_idx].last_dqdly_pass = cur_dly;                        
                    finish_count++;
                    BL_PRINT(LOG_DEBUG, "dqs_perbyte_dly.last_dqdly_pass[%d]=%d,  finish count=%d \r\n", byte_idx, dqs_perbyte_dly[byte_idx].last_dqdly_pass, finish_count);   
                }                    
            }
        }

        // If finish_count is equal to DQS_NUMBER, it means fine all dq last pass
        if (DQS_NUMBER == finish_count) {
            break;
        }
    }

    /* 4. get optimal value */
    /* 
     * find the middle of the pass range of DQ and DQS
     * if the middle of the pass range is in the DQ, the delay of (DQS,DQ) is (0,DQ), 
     * if the middle of the pass range is in the DQS the delay of (DQS,DQ) is (DQS,0)
     * Considering DQS/DQ and CLK delay, we add TX_STEPS.
     */
    for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
        dqs_perbyte_dly[byte_idx].total_dqsdly_pass = dqs_perbyte_dly[byte_idx].last_dqsdly_pass - dqs_perbyte_dly[byte_idx].first_dqsdly_pass + 1;
        dqs_perbyte_dly[byte_idx].total_dqdly_pass = dqs_perbyte_dly[byte_idx].last_dqdly_pass - dqs_perbyte_dly[byte_idx].first_dqdly_pass + 1;
        BL_PRINT(LOG_INFO, "total_dqsdly_pass:%x ", dqs_perbyte_dly[byte_idx].total_dqsdly_pass);
        BL_PRINT(LOG_INFO, "total_dqdly_pass:%x ", dqs_perbyte_dly[byte_idx].total_dqdly_pass);
        if (TX_MINI_WINDOW_SIZE > dqs_perbyte_dly[byte_idx].total_dqdly_pass + dqs_perbyte_dly[byte_idx].total_dqsdly_pass) {
            BL_PRINT(LOG_ERROR, "TX window size (%d+%d) is smaller than %d\r\n",
                dqs_perbyte_dly[byte_idx].total_dqsdly_pass, dqs_perbyte_dly[byte_idx].total_dqdly_pass, TX_MINI_WINDOW_SIZE);
            return DRAMC_CAL_TX_FAIL_OPT_VAL;
        }
        if (dqs_perbyte_dly[byte_idx].total_dqdly_pass == dqs_perbyte_dly[byte_idx].total_dqsdly_pass) {
            dqs_perbyte_dly[byte_idx].dqs = dqs_perbyte_dly[byte_idx].dq = TX_STEPS; 
        } else if (dqs_perbyte_dly[byte_idx].total_dqdly_pass > dqs_perbyte_dly[byte_idx].total_dqsdly_pass) {
            dqs_perbyte_dly[byte_idx].dqs = 0 + TX_STEPS; 
            dqs_perbyte_dly[byte_idx].dq += (dqs_perbyte_dly[byte_idx].total_dqdly_pass - dqs_perbyte_dly[byte_idx].total_dqsdly_pass)/2 + TX_STEPS; 
            if (dqs_perbyte_dly[byte_idx].dq > 0xf) {
                BL_PRINT(LOG_DEBUG, "warning:byte %d,dq:%x", byte_idx, dqs_perbyte_dly[byte_idx].dq);
            }
        } else {
            dqs_perbyte_dly[byte_idx].dqs += (dqs_perbyte_dly[byte_idx].total_dqsdly_pass - dqs_perbyte_dly[byte_idx].total_dqdly_pass)/2 + TX_STEPS; 
            if (dqs_perbyte_dly[byte_idx].dqs > 0xf) {
                BL_PRINT(LOG_DEBUG, "warning:byte %d,dqs:%x", byte_idx, dqs_perbyte_dly[byte_idx].dqs);
            }
            dqs_perbyte_dly[byte_idx].dq = 0 + TX_STEPS; 
        }
        BL_PRINT(LOG_INFO, "byte:%x, (DQS,DQ)=(%x,%x)\r\n", byte_idx,dqs_perbyte_dly[byte_idx].dqs, dqs_perbyte_dly[byte_idx].dq);
    }

    /* 5. write result into register */
    data = 0;
    for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
/* For MT6290 SIP DRAM, it is 16-bit DRAM. DQM0 => DQM2, DQM1 => DQM0. */
        if (TRUE == is_mt6290m) {
            if (0 == byte_idx) {
                data |= DRAMC_PADCTL2_DQMiDLY(0, dqs_perbyte_dly[byte_idx].dqs);
         
            } else if (1 == byte_idx) {
                data |= DRAMC_PADCTL2_DQMiDLY(2, dqs_perbyte_dly[byte_idx].dqs);
            } else {
                BL_PRINT(LOG_ERROR, "DQM Number(%d) should be smaller than 2\r\n", DQS_NUMBER);
                return DRAMC_CAL_TX_FAIL_DQM;
            }
        } else {
            data |= DRAMC_PADCTL2_DQMiDLY(byte_idx, dqs_perbyte_dly[byte_idx].dqs);
        }
    }
    DRV_WriteReg32(DRAMC_PADCTL2/* 0x10 */, data);
    opt_tx_dqm = data;
    for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++)
    {
        dq = dqs_perbyte_dly[byte_idx].dq;
/* 
 * For MT6290 SIP DRAM, it is 16-bit DRAM. 
 * DQ0 => DQ0, DQ1 => DQ1, DQ2 => DQ2, DQ3 => DQ3
 * DQ4 => DQ8, DQ5 => DQ9, DQ6 => DQ10, DQ7 => DQ11
 * DQ8 => DQ16, DQ9 => DQ17, DQ10 => DQ18, DQ11 => DQ19
 * DQ12 => DQ24, DQ13 => DQ25, DQ14 => DQ26, DQ15 => DQ27
 */
        if (TRUE == is_mt6290m) {
            data = 0;
            // DQ[3:0] & DQ[11:8]
            for (bit_idx = 0; bit_idx < 4; bit_idx++) {
                data |= DRAMC_DQnODLY((byte_idx << 3) + bit_idx, dq);
            }
            DRV_WriteReg32(DRAMC_DQODLY(byte_idx << 1), data);
            data = 0;
            // DQ[7:4] & DQ[15:12]
            for (bit_idx = 0; bit_idx < 4; bit_idx++) {
                data |= DRAMC_DQnODLY(((byte_idx + 1) << 3) + bit_idx, dq);
            }
            DRV_WriteReg32(DRAMC_DQODLY((byte_idx << 1) + 1), data);
        } else {
            data = 0;
            for (bit_idx = 0; bit_idx < DQ_NUMBER_PER_DQS; bit_idx++) {
                data |= DRAMC_DQnODLY((byte_idx << 3) + bit_idx, dq);
            }
            DRV_WriteReg32(DRAMC_DQODLY(byte_idx), data);
        }
            opt_tx_dq[byte_idx] = data;

    }
    data = 0;
    for (byte_idx = 0; byte_idx < DQS_NUMBER; byte_idx++) {
/* For MT6290 SIP DRAM, it is 16-bit DRAM. DQS0 => DQS2, DQS1 => DQS0. */
        if (TRUE == is_mt6290m) {
            if (0 == byte_idx) {
                data |= DRAMC_PADCTL3_DQSiDLY(0, dqs_perbyte_dly[byte_idx].dqs);
            } else if (1 == byte_idx) {
                data |= DRAMC_PADCTL3_DQSiDLY(2, dqs_perbyte_dly[byte_idx].dqs);
            } else {
                BL_PRINT(LOG_ERROR, "DQS Number(%d) should be smaller than 2\r\n", DQS_NUMBER);
                return DRAMC_CAL_TX_FAIL_DQS;
            }
        } else { 
            data |= DRAMC_PADCTL3_DQSiDLY(byte_idx, dqs_perbyte_dly[byte_idx].dqs);
        }
    }
    opt_tx_dqs = data;
    DRV_WriteReg32_NPW(DRAMC_PADCTL3/* 0x14 */, data);
    BL_PRINT(LOG_INFO, "%x,data:%x\r\n",(kal_uint32)DRAMC_PADCTL3, DRV_Reg32(DRAMC_PADCTL3));
    Data_Mem_Barrier();

    return DRAMC_CAL_PASS;
}
