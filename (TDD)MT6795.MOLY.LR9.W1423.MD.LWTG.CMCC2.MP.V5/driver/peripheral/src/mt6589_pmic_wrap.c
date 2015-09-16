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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *  mt6589_pmic_wrap.c
 *
 * Project:
 * --------
 *  Maui_Software
 *
 * Description:
 * ------------
 *	This is mt6589 pmic wrapper driver
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "dcl.h" 
#include "mt6589_pmic_wrap_hw.h"
#include "mt6589_pmic_wrap_sw.h"
#include "dcl_pmic6320_hw.h"
#include "reg_peri_pwrap_bridge.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
static inline kal_uint32 wait_for_wacs_fsm_idle(kal_uint32 x)
{
    // Current WACS FSM state is IDLE State
    return (GET_WACS_FSM(x) != WACS_FSM_IDLE_STATE);
}

static inline kal_uint32 wait_for_wacs_fsm_wfvldclr(kal_uint32 x)
{
    // WFVLDCLR, wait for valid flag clearing
    return (GET_WACS_FSM(x) != WACS_FSM_WFVLDCLR_STATE); 
}

static inline kal_uint32 wait_for_man_wfvldclr(kal_uint32 x)
{
    // WFVLDCLR (wait for valid flag clearing)
    return  (GET_MAN_FSM(x) != MAN_FSM_WFVLDCLR_STATE) ;
}

static inline kal_uint32 wait_for_man_idle_and_noreq(kal_uint32 x)
{
    // No MAN request is awaiting grant, Current MAN FSM state is IDLE.
    return ((GET_MAN_REQ(x) != 0x00) || (GET_MAN_FSM(x) != MAN_FSM_IDLE_STATE));
}

static inline kal_uint32 wait_for_wacs_fsm_idle_and_sync_idle(kal_uint32 x)
{
    // Wait until SYNC module is IDLE and FSM state is IDLE
    return ((GET_WACS_FSM(x) != WACS_FSM_IDLE_STATE) || (GET_SYNC_IDLE(x) != WACS_SYNC_MODULE_IDLE));
}

static inline kal_uint32 wait_for_wrap_fsm_idle_and_spi_read_data_counter_zero(kal_uint32 x)
{
    // Wrapper FSM state is IDLE, Remaining SPI read data counter for wrapper is zero.
    return ((GET_WRAP_FSM(x) != WRAP_FSM_IDLE_STATE) || (GET_WRAP_CH_DLE_RESTCNT(x) != 0x0));
}

static inline kal_uint32 wait_for_cipher_ready(kal_uint32 x)
{
    // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
    return (x != 0x01) ;
}

static inline kal_uint32 wait_for_sync_idle(kal_uint32 x)
{
    // Wait until SYNC module is IDLE
    return (GET_SYNC_IDLE(x) != WACS_SYNC_MODULE_IDLE);
}

static inline kal_uint32 wait_for_staupd_idle(kal_uint32 x)
{
    // Current STAUPD FSM is IDLE State
    return (GET_STAUPD_FSM(x) != STAUPD_FSM_IDLE_STATE) ;
}

static inline kal_uint32 wait_for_wrap_req_counter_zero(kal_uint32 x)
{
    // Remaining WRAP request counter for wrapper is zero
    return (GET_WRAP_AG_DLE_RESTCNT(x) != 0) ;
}

static inline kal_uint32 wait_for_state_ready_init(loop_condition_fp fp, kal_uint32 timeout_us, kal_uint32 pmic_wrap_register, kal_uint32 *read_reg)
{
//    kal_uint32 start_time_ns = 0, timeout_ns = 0;
    kal_uint32 reg_rdata = 0x0;
    kal_uint32 saved_current_time = 0;
    saved_current_time = drv_get_current_time();
    // start_time_ns = _pwrap_get_current_time();
    // timeout_ns = _pwrap_time2ns(timeout_us);
    do
    {
        reg_rdata = PMIC_WRAP_DRV_Reg32(pmic_wrap_register);

        //if (_pwrap_timeout_ns(start_time_ns, timeout_ns))
        if(drv_get_duration_tick(saved_current_time, drv_get_current_time()) > 2) // NEED TO CHECK (64us)
        {
            ASSERT(0);
            return PMIC_WRAP_TIME_OUT_FAIL;
        }
    }while(fp(reg_rdata));
    
    if(read_reg)
    {
        *read_reg = reg_rdata;
    }
    return 0;
}


static inline kal_uint32 wait_for_state_ready(loop_condition_fp fp, kal_uint32 timeout_us, kal_uint32 pmic_wrap_register, kal_uint32 *read_reg)
{
//    kal_uint32 start_time_ns = 0, timeout_ns = 0;
    kal_uint32 reg_rdata;
    kal_uint32 saved_current_time = 0;
    saved_current_time = drv_get_current_time();
    // struct pmic_wrap_obj *pwrap_obj = g_pmic_wrap_obj;
    // start_time_ns = _pwrap_get_current_time();
    // timeout_ns = _pwrap_time2ns(timeout_us);
    do
    {
        reg_rdata = PMIC_WRAP_DRV_Reg32(pmic_wrap_register);
        if(GET_INIT_DONE0( reg_rdata ) != WACS_INIT_DONE_FINISHED)
        {
            ASSERT(0);
            return PMIC_WRAP_NOT_INIT_DONE;
        }

        //if (_pwrap_timeout_ns(start_time_ns, timeout_ns))
        if(drv_get_duration_tick(saved_current_time, drv_get_current_time()) > 2) // NEED TO CHECK (64us)
        {
            ASSERT(0);
            return PMIC_WRAP_TIME_OUT_FAIL;
        }        
    }while(fp(reg_rdata));
    if(read_reg)
    {
        *read_reg = reg_rdata;
    }
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_Init(void)
// Description : Initialize PMIC_WRAP, PPB, PMIC_DEWRAP
//   Parameter : None
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_Init(void)
{
    kal_uint32 sub_return;
    kal_uint32 rdata;

    //###############################
    // Reset related modules
    // PMIC_WRAP, PERI_PWRAP_BRIDGE, PWRAP_SPICTL
    //###############################
    PMIC_WRAP_DRV_SetBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_SetBits32(PERI_GLOBALCON_RST1, 0x04); // Reset PERI_PWRAP_BRIDGE

    // *WDT_SWSYSRST = 0x88000000 | (*WDT_SWSYSRST | (0x1 << 11) & 0x00ffffff );
    rdata = PMIC_WRAP_DRV_Reg32(WDT_SWSYSRST);
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, 0x88000000 | ((rdata | (0x1 << 11)) & 0x00FFFFFF));
    //###############################
    // Toggle PERI_PWRAP_BRIDGE reset
    //###############################

    PMIC_WRAP_DRV_ClearBits32(INFRA_GLOBALCON_RST0, 0x80); // Reset PMIC_WRAP
    PMIC_WRAP_DRV_ClearBits32(PERI_GLOBALCON_RST1, 0x04); // Reset PERI_PWRAP_BRIDGE
    // *WDT_SWSYSRST = 0x88000000 | (*WDT_SWSYSRST & ~(0x1 << 11) & 0x00ffffff );
    rdata = PMIC_WRAP_DRV_Reg32(WDT_SWSYSRST);
    PMIC_WRAP_DRV_WriteReg32(WDT_SWSYSRST, 0x88000000 | ((rdata & ~(0x1 << 11)) & 0x00FFFFFF));
    
    //###############################
    // Enable DCM
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DCM_EN, 0x01); // Enable internal DCM. When PMIC_WRAP is in idle state, clock will be gated.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DCM_DBC_PRD, 0x00); // Disable Debounce Period at Entering DCM Mode.

    //###############################
    // Reset SPISLV
    //###############################
    DrvPWRAP_ResetSPISLV();

    //###############################
    // Enable WACS2
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x01); // Wrapper circuit is enable, and new request can be accepted once wrapper is available.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, 0x08); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_EN, 0x01); // Wrapper Access (#2) enable.

    //###############################
    // TBD: Set SPI_CK freq = 66MHz
    //###############################
    // *CLK_CFG_8 = (*CLK_CFG_8 & ~0x7) | 0x5;
//	PMIC_WRAP_DRV_WriteReg32(CLK_CFG_8, 0x01); // Set SPI_CK freq = 69Mhz
    rdata = PMIC_WRAP_DRV_Reg32(CLK_CFG_8);
    PMIC_WRAP_DRV_WriteReg32(CLK_CFG_8, (rdata & ~0x7) | 0x5); // Set SPI_CK freq = 69Mhz

    //###############################
    // SIDLY setting
    //###############################
    sub_return = DrvPWRAP_InitSIDLY();
    if( sub_return != 0 )  {
        ASSERT(0);
        /* TERR="[SetSIDLY] DrvPWRAP_SetSIDLY() fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_SIDLY_FAIL;
    }

    //###############################
    // SPI Waveform Configuration
    //###############################
//    sub_return = DrvPWRAP_InitRegClk(PMIC_WRAP_REG_CLOCK_36MHZ); // 0:safe mode, 1:18MHz, 2:36MHz
    sub_return = DrvPWRAP_InitRegClk(PMIC_WRAP_REG_CLOCK_SAFE_MODE); // 0:safe mode, 1:18MHz, 2:36MHz
    if(sub_return != 0)  {
        ASSERT(0);
        /* TERR="Error: [DrvPWRAP_InitRegClk] fail, sub_return=%x", sub_return*/
        return PMIC_WRAP_INIT_REG_CLK_FAIL;
    }

    //###############################
    // Enable PMIC
    // (May not be necessary, depending on S/W partition)
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, WRP_CKPDN, 0x00, &rdata); // Set WRAPPER CKPDN register no power down
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, WRP_RST_CON, 0x00, &rdata); // Disable Reset, let module work

    //###############################
    // Enable DIO mode
    //###############################
    sub_return = DrvPWRAP_InitDio(KAL_TRUE); // Enable SPI dual I/O mode.
    if(sub_return != 0)  {
        ASSERT(0);
        /* TERR="Error: [EnableDIO] DrvPWRAP_InitDio(1) fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_DUAL_MODE_FAIL;
    }

    //###############################
    // Enable Encryption
    //###############################
    sub_return = DrvPWRAP_InitCIPHER(); // Initial CIPHER
    if(sub_return != 0)  {
        ASSERT(0);        
        /* TERR="Error: [EnableEncryption] DrvPWRAP_InitCIPHER fail, return=%x, exp=0", sub_return */
        return PMIC_WRAP_INIT_CIPHER_FAIL;
    }

    //###############################
    // Write test using WACS2
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_WRITE_TEST, DEW_WRITE_TEST_VALUE, &rdata); // Write Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_WRITE_TEST, 0x00, &rdata);
    if(rdata != DEW_WRITE_TEST_VALUE)  {
        /* TERR="Error: [WriteTest] fail, rdata=%x, exp=0xa55a", rdata*/
        ASSERT(0);        
        return PMIC_WRAP_WRITE_TEST_FAIL;
    }

    //###############################
    // Signature Checking - Using Write Test Register
    // should be the last to modify WRITE_TEST
    //###############################
    //DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_WRITE_TEST, DEW_WRITE_TEST_VALUE, &rdata);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_ADR, DEW_WRITE_TEST);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_VALUE, DEW_WRITE_TEST_VALUE);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_MODE, 0x01);

    //###############################
    // Signature Checking - Using CRC
    // should be the last to modify WRITE_TEST
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x01, &rdata); // Enable CRC calculation circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x01); // Enable CRC calculation circuit
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_MODE, 0x00); // Check CRC value
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIG_ADR, DEW_CRC_VAL); // The signature address @PMIC side to be automatically checked. STAUPD circuit will fetch from address every STAUPD_PRD time.

    //###############################
    // PMIC_WRAP enables
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_ALL); // HIPRIO_ARB enable for each source
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_RRARB_EN, 0x07); // HIPRIO_ARB enable for each source (2:Reserved, 1:KP, 0:EINT)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_EN, 0x01);
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_EN, 0x01);  // Already enabled
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_IN_EN, 0x01); // Enable switch for event input processing circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_DST_EN, 0xFFFF); // Enable switch for each event destination output.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x05);  // Periodic status update timing (period) selection 98.5us
    //PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x01); // 20us
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_GRPEN, 0xFF); // Enable switch for each status update group.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WDT_UNIT, 0x0F); // Watch Dog timer unit selection. (5ms ~ 7.5ms)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WDT_SRC_EN, 0xFFFFFFFF); // Watch dog timer source enable. (ALL)
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_TIMER_EN, 0x01); // Timer clock enable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INT_EN, 0x7FFFFFFF); // Interrupt enable for each source, except for [31] debug_int.

    //###############################
    // PERI_PWRAP_BRIDGE enables
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_IORD_ARB_EN, 0x7F); // INORDER_ARB enable for each source
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_EN, 0x01);
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WDT_UNIT, 0x0F); // Watch Dog timer unit selection. (5ms ~ 7.5ms)
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WDT_SRC_EN, 0xFFFF); // Watch dog timer source enable. (ALL)
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_TIMER_EN, 0x01); // Timer clock enable.
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INT_EN, 0x7FF); // Interrupt enable for each source, except for [11] debug_int. (NEED TO CHECK)

    //###############################
    // PMIC_DEWRAP enables
    //###############################
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_EVENT_OUT_EN, 0x01, &rdata); // Enable EVENT output.
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_EVENT_SRC_EN, 0xFFFF, &rdata); // Enable each EVENT source respectively.

    //###############################
    // Initialization Done
    //###############################
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE0, 0x01); // Initialization is finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE1, 0x01); // Initialization is finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE2, 0x01); // Initialization is finished.
            
    //###############################
    // Should be configured by MD MCU
    //###############################  
    // PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE0, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_INIT_DONE1, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INIT_DONE3, 0x01);
    // PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_INIT_DONE4, 0x01);

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_WACS2_NoChk()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS2_NoChk(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata) // No check INIT DONE, for INIT usage
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    if(NULL == rdata) return PMIC_WRAP_INVALID_ARGUMENT;
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16; // Wrapper Access: address[15:1]

    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready_init(wait_for_wacs_fsm_wfvldclr, 60, PMIC_WRAP_WACS2_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }
        
        *rdata = GET_WACS2_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS0()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
//kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
kal_uint32 DrvPWRAP_WACS0(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, 60, PMIC_WRAP_WACS0_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }    

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, 60, PMIC_WRAP_WACS0_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            return return_value;
        }    
        
        *rdata = (kal_uint16)GET_WACS0_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS0_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_WACS1()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
//kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
kal_uint32 DrvPWRAP_WACS1(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint16 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF

    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance   
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, 60, PMIC_WRAP_WACS1_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }    
    
    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, 60, PMIC_WRAP_WACS1_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            return return_value;
        }          

        *rdata = (kal_uint16)GET_WACS1_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS1_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS2()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS2(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;
    kal_uint32 savedMask = 0;
    
    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF

#if !defined(__UBL__) && !defined(__FUE__)
	savedMask = SaveAndSetIRQMask();
#endif //#if !defined(__UBL__) && !defined(__FUE__)

    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        // GuoXin Add
        #if !defined(__UBL__) && !defined(__FUE__)	
        RestoreIRQMask(savedMask);
        #endif //#if !defined(__UBL__) && !defined(__FUE__)	
        return return_value;
    }        

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, 60, PMIC_WRAP_WACS2_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);
            // GuoXin Add
            #if !defined(__UBL__) && !defined(__FUE__)	
            RestoreIRQMask(savedMask);
            #endif //#if !defined(__UBL__) && !defined(__FUE__)	
            return return_value;
        }          

        *rdata = GET_WACS2_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WACS2_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    

#if !defined(__UBL__) && !defined(__FUE__)	
    RestoreIRQMask(savedMask);
#endif //#if !defined(__UBL__) && !defined(__FUE__)		

    return 0; 
}


//--------------------------------------------------------
//    Function : DrvPWRAP_WACS3()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS3(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, 60, PERI_PWRAP_BRIDGE_WACS3_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }  

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, 60, PERI_PWRAP_BRIDGE_WACS3_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }

        *rdata = GET_WACS3_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS3_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0; 
}

//--------------------------------------------------------
//    Function : DrvPWRAP_WACS4()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_WACS4(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 wacs_write;
    kal_uint32 wacs_adr;
    kal_uint32 return_value;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF
    
    // Argument process
    wacs_write  = write << 31;
    wacs_adr    = (adr >> 1) << 16;
    
    // Check IDLE & INIT_DONE in advance
    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle, 60, PERI_PWRAP_BRIDGE_WACS4_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }

    // Send Command
    PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_CMD, wacs_write | wacs_adr | wdata);
    if(write == PMIC_WRAP_READ) // Read
    {
        return_value = wait_for_state_ready(wait_for_wacs_fsm_wfvldclr, 60, PERI_PWRAP_BRIDGE_WACS4_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }
        
        *rdata = GET_WACS4_RDATA(reg_rdata); // Read Data
        PMIC_WRAP_DRV_WriteReg32(PERI_PWRAP_BRIDGE_WACS4_VLDCLR, 0x01); // Write 1 to clear valid flag.
    }    
    
    return 0; 
}

//--------------------------------------------------------
//    Function : DrvPWRAP_InitDio()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitDio(kal_bool dio_en)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_DIO_EN, dio_en, &rdata); // Enable dual I/O mode for SPI slave.

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);
        return return_value;
    }  

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, dio_en); // Eable / Disable SPI dual I/O mode
    // Read Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        ASSERT(0);        
        /* TERR="Error: [DrvPWRAP_InitDio][Read Test] fail, dio_en = %x, READ_TEST rdata=%x, exp=0x5aa5", dio_en, rdata */
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_SwitchDio()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_SwitchDio(kal_bool dio_en)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 sub_return;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)  
    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_DIO_EN, dio_en, &rdata); // Disable / Enable dual I/O mode for SPI slave.
  
    if(sub_return != 0)  {
        /* TERR="Error: [DrvPWRAP_SwitchDio][Set DEW_DIO_EN] DrvPWRAP_WACS2 fail, return=%x, exp=0x0", sub_return*/
        ASSERT(0);        
        return PMIC_WRAP_SWITCH_DIO_FAIL;    
    }

    return_value = wait_for_state_ready(wait_for_wacs_fsm_idle_and_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }  

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, dio_en); // Eable / Disable SPI dual I/O mode
    // Read Test
    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0, &rdata);
    if((sub_return != 0) || (rdata != DEW_READ_TEST_VALUE)){
        /* TERR="Error: [DrvPWRAP_SwitchDio][Read Test] DrvPWRAP_WACS2() fail, dio_en = %x, return=%x, exp=0, rdata=%x, exp=0x5aa5", dio_en, sub_return, rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap

    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_SwitchMux()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_SwitchMux(kal_uint8 mux_sel_new )
{
    kal_uint8 mux_sel_old;
//    kal_uint32 rdata;
    kal_uint32 return_value;

    // Return if no change is necessary
    mux_sel_old = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_MUX_SEL); // Read SPI controller source selection
    if(mux_sel_new == mux_sel_old)
    {  
        return;
    }
  
    // Disable OLD, wait OLD finish
    // Switch MUX, then enable NEW
    if(mux_sel_new == SPI_MANUAL_MODE)
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x00); // Wrapper circuit is disabled, but the current transaction will be finished.
        return_value = wait_for_state_ready(wait_for_man_idle_and_noreq, 60, PMIC_WRAP_WRAP_STA, 0);
        // NEED TO CHECK
        if(return_value != 0)
        {
            ASSERT(0);
        } 
        
        
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, SPI_MANUAL_MODE); // SPI is controlled in manual mode.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x01); // Manual mode circuit is enable
    }
    else
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x00); // Manual mode circuit is disabled
        return_value = wait_for_state_ready(wait_for_man_idle_and_noreq, 60, PMIC_WRAP_MAN_RDATA, 0);
        // NEED TO CHECK        
        if(return_value != 0)
        {
            ASSERT(0);
        }         

        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, SPI_AUTO_MODE); // SPI is controlled by automatic wrapper
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x01); // Wrapper circuit is enable, and new request can be accepted once wrapper is available
    }

    return ;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_InitCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitCIPHER( void )
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)


    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_KEY_SEL, 0x01); // All keys are hard-wired
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_IV_SEL, 0x02); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_LOAD, 0x01); // CIPHER Load Key & IV
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x01); // CIPHER Engine Start

    // Config CIPHER @ PMIC
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x01,  &rdata); // Enabl CIPHER Soft Reset
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x00,  &rdata); // Disble CIPHER Soft Reset
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_KEY_SEL, 0x01,  &rdata); // All keys are hard-wired
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_IV_SEL,  0x02,  &rdata); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_LOAD,    0x01,  &rdata); // CIPHER Load Key & IV
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_START,   0x01,  &rdata); // CIPHER Engine Start

    return_value = wait_for_state_ready_init(wait_for_cipher_ready, 60, PMIC_WRAP_CIPHER_RDY, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
 
    do
    {
        DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_CIPHER_RDY, 0x00, &rdata); // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
        #if 0 // NEED TO CHECK       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif
    }while(rdata != 0x1); // Cipher_ready

    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x01, &rdata); // CIPHER Mode Enable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x01); // CIPHER Mode Enable

    // Read Test
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_InitCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_EnableCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_EnableCIPHER( void )
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

    //Make sure CIPHER engine is idle
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_START, 0x00, &rdata); // CIPHER Engine Stop

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x00); // CIPHER Engine Stop

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x00); // CIPHER Mode Disable
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_KEY_SEL, 0x01); // All keys are hard-wired
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_IV_SEL, 0x02); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_LOAD, 0x01); // CIPHER Load Key & IV
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x01); // CIPHER Engine Start

    // Config CIPHER @ PMIC
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x01,  &rdata); // Enable CIPHER Soft Reset
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_SWRST,   0x00,  &rdata); // Disble CIPHER Soft Reset
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_KEY_SEL, 0x01,  &rdata); // All keys are hard-wired
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_IV_SEL,  0x02,  &rdata); // Set 0 to choose manual initial vector, otherwise, choose other Hard-wired initial vectors.
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_LOAD,    0x01,  &rdata); // CIPHER Load Key & IV
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_START,   0x01,  &rdata); // CIPHER Engine Start

    return_value = wait_for_state_ready_init(wait_for_cipher_ready, 60, PMIC_WRAP_CIPHER_RDY, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    do
    {
        DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_CIPHER_RDY, 0x00, &rdata); // Wait until CIPHER Data Ready (Data should be ready before enable CIPHER_MODE)
        #if 0 // NEED TO CHECK       
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
        #endif        
    }while(rdata != 0x01); // Cipher_ready

    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x01, &rdata); // CIPHER Mode Enable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x01); // CIPHER Mode Enable

    // Read Test
    DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_EnableCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_DisableCIPHER()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_DisableCIPHER(void)
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 return_value;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

    //Disable CIPHER MODE
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CIPHER_MODE, 0x00, &rdata); // CIPHER MODE Disable

    return_value = wait_for_state_ready_init(wait_for_wacs_fsm_idle_and_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    } 

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_MODE, 0x00); // CIPHER Mode Disable
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_START, 0x00); // CIPHER Engine Stop
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x01); // Enable CIPHER Soft Reset
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CIPHER_SWRST, 0x00); // Disble CIPHER Soft Reset 

    // Read Test
    DrvPWRAP_WACS2(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
    if(rdata != DEW_READ_TEST_VALUE)
    {
        /* TERR="Error: [DrvPWRAP_DisableCIPHER][Read Test] fail, READ_TEST rdata=%x, exp=0x5aa5", rdata */
        ASSERT(0);        
        return PMIC_WRAP_READ_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
    return 0;
}


//--------------------------------------------------------
//    Function : DrvPWRAP_InitSIDLY()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitSIDLY(void) // Init SPI Input Data Stobe timing
{
    kal_uint32 arb_en_backup;
    kal_uint32 rdata;
    kal_uint32 ind;
    kal_uint32 result;
    kal_uint32 result_faulty;

    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)

    // Scan all SIDLY by Read Test
    result = 0;
    for(ind = 0 ; ind < 4 ; ind++)
    {
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, ind); // SPI input data strobe timing control.
        // DEW_READ_TEST: This is a dummy register used to test read access.
        DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, DEW_READ_TEST, 0x00, &rdata);
        if(rdata == DEW_READ_TEST_VALUE)
        {
            /* TINFO="[DrvPWRAP_InitSIDLY][Read Test] pass, SIDLY=%x", ind */
            // Record pass SI delay
            result |= (0x1 << ind);
        }
    }

    // Config SIDLY according to result
    result_faulty = 0;
    switch(result)
    {
        // Only 1 pass, choose it
        case 0x1:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00); // SPI input data strobe timing control.
        break;
        
        case 0x2:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;
        
        case 0x4:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x02);
        break;
        
        case 0x8:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x03);
        break;

        // Two pass, choose the one on SIDLY boundary
        case 0x3:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00);
        break;
        
        case 0x6:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01); // No boundary, choose smaller one
        break;
        
        case 0xc:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x03);
        break;

        // Three pass, choose the middle one
        case 0x7:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;
        
        case 0xe:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x02);
        break;
        
        // Four pass, choose the smaller middle one
        case 0xf:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x01);
        break;

        // pass range not continuous, should not happen
        default:
            PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_SIDLY, 0x00);
            result_faulty = 0x1;
        break;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap

    if(result_faulty == 0)
    {
        return 0;
    }
    else
    {
        /* TERR="Error: [DrvPWRAP_InitSIDLY] Fail, result=%x", result */
        ASSERT(0);
        return result_faulty;
    }
}


//--------------------------------------------------------
//    Function : DrvPWRAP_ResetSPISLV()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_ResetSPISLV(void) // Reset SPI Slave
{
//    kal_uint32 rdata;
    kal_uint32 return_value;

    // This driver does not using DrvPWRAP_SwitchMux
    // because the remaining requests are expected to fail anyway
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, 0x00); // HIPRIO_ARB disable for each source.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_WRAP_EN, 0x00); // Wrapper circuit is disabled, but the current transcation will be finished.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, 0x01); // SPI is controlled in manual mode.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x01); // Manual mode circuit is enable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_DIO_EN, 0x00); // SPI dual I/O mode is disable.

    /* SPI Reset Pattern */
    // Pull CS to low, CS will keep low  for at least (1.5+WDATA[3:0])TSPI_CK before next OP command is executed.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_CSL  << 8)); // Write OP_CSL, 
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS to reset counter
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_CSH  << 8)); // Write OP_CSH
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
    // Output 1 byte in single mode  
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, (OP_WR << 13) | (OP_OUTS << 8)); // Write OP_OUTS
   
    return_value = wait_for_state_ready_init(wait_for_sync_idle, 60, PMIC_WRAP_WACS2_RDATA, 0);
    // NEED TO CHECK
    if(return_value != 0)
    {
        ASSERT(0);
    }
    
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_EN, 0x00); // Manual mode circuit is disable.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MUX_SEL, 0x00); // SPI is controlled by automatic wrapper.
}


//--------------------------------------------------------
//    Function : DrvPWRAP_EventTest()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_EventTest( void )
{
    kal_uint32 rdata;
    kal_uint32 sub_return;

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_STACLR, 0xFFFF); // Write 1 to clear corresponding EVENT_STA bit.

    sub_return = DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_EVENT_TEST, 0x01, &rdata); // Write 1 to generate an EVENT.
    if(sub_return != 0)
    {  
        /* TERR="Error: [DrvPWRAP_EventTest][DrvPWRAP_WACS2] fail, return=%x, exp=0x0", sub_return*/
        ASSERT(0);
        return PMIC_WRAP_WRITE_FAIL;    
    }

    // Delay 10us (NEED TO CHECK) delay at least 2us
    #ifndef FPGA_6320
    #if 0 // Anderson 2012/07/22
/* under construction !*/
/* under construction !*/
    #endif
    #else
        for(i = 0 ; i< 0x20 ; i++);
    #endif

    rdata = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_EVENT_STA); // When a EVENT has been received, the corresponding EVENT_STA will be asserted. (For debug)
    if((rdata & 0x8000) != 0x8000) // Check Debug Event
    {
        /* TERR="Error: [DrvPWRAP_EventTest] fail, PMIC_WRAP_EVENT_STA rdata=%x, exp=0x8000", rdata */
        ASSERT(0);        
        return PMIC_WRAP_DEW_EVENT_TEST_FAIL;
    }

    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_EVENT_STACLR, 0xFFFF); // Write 1 to clear corresponding EVENT_STA bit.
    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_Man()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_Man(kal_uint32 write, kal_uint32 op, kal_uint32 wdata, kal_uint32 *rdata)
{
    kal_uint32 reg_rdata;
    kal_uint32 man_write;
    kal_uint32 man_op;
    kal_uint32 return_value;

    reg_rdata = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_MAN_RDATA); // Manual Read Data
    if(GET_MAN_FSM( reg_rdata) != MAN_FSM_IDLE_STATE) //IDLE State
    {
        ASSERT(0);
        return PMIC_WRAP_MANUAL_MODE_NOT_IDLE;
    }

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((op   & ~(0x1f)) != 0)  return PMIC_WRAP_INVALID_OP; // OP should no larger than 0xFFFF
    if((wdata & ~(0xff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFF    

    man_write = write << 13;
    man_op    = op << 8;
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_CMD, man_write | man_op | wdata);

    if(write == OP_RD)
    {
        return_value = wait_for_state_ready_init(wait_for_man_wfvldclr, 60, PMIC_WRAP_MAN_RDATA, &reg_rdata);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        }         
 
        *rdata = GET_MAN_RDATA(reg_rdata);
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_MAN_VLDCLR, 0x01);        
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_ManAccess()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_ManAccess(kal_uint32 write, kal_uint32 adr, kal_uint32 wdata, kal_uint32 *rdata )
{
    kal_uint32 man_wdata;
    kal_uint32 man_rdata;

    // Check argument validation
    if((write & ~(0x1))    != 0)  return PMIC_WRAP_INVALID_RW; // Write should be 1 bit
    if((adr   & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_ADDR; // Address should no larger than 0xFFFF
    if((wdata & ~(0xffff)) != 0)  return PMIC_WRAP_INVALID_WDATA; // Write DATA should be no larger than 0xFFFF  

    DrvPWRAP_SwitchMux(SPI_MANUAL_MODE); // Switch to Manual Mode
    DrvPWRAP_Man(OP_WR,  OP_CSH,  0x00, &man_rdata);
    DrvPWRAP_Man(OP_WR,  OP_CSL,  0x00, &man_rdata);
    man_wdata = adr >> 1;
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
    man_wdata = (adr >> 9) | (write << 7);
    DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
    DrvPWRAP_Man(OP_WR,  OP_CSH,  0x00, &man_rdata);

    DrvPWRAP_Man(OP_WR,  OP_CSL,  0x00, &man_rdata);
    if(write == PMIC_WRAP_WRITE)
    {
        man_wdata = wdata;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
        man_wdata = wdata >> 8;
        DrvPWRAP_Man(OP_WR,  OP_OUTD, (man_wdata & 0xff), &man_rdata);
    }
    else
    {
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);
        *rdata = GET_MAN_RDATA(man_rdata);
        DrvPWRAP_Man(OP_RD,  OP_IND, 0, &man_rdata);
        *rdata |= (GET_MAN_RDATA(man_rdata) << 8);
    }
    DrvPWRAP_Man(OP_WR, OP_CSH, 0, &man_rdata);

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_StaUpdTrig()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_StaUpdTrig(kal_uint32 mode) // NEED TO CHECK (WHAT Purpose? MODE:0->? 1->?) // No Need Implement
{
    // kal_uint32 man_rdata;
    kal_uint32 return_value;

    // Wait for FSM to be IDLE
    return_value = wait_for_state_ready_init(wait_for_staupd_idle, 60, PMIC_WRAP_STAUPD_STA, 0);
    if(return_value != 0)
    {
        ASSERT(0);        
        return return_value;
    }       

    // Trigger FSM
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_MAN_TRIG, 0x01); // Set 1 to manually trigger Status Update Circuit

    // Check if FSM is in REQ
    if(GET_STAUPD_FSM(PMIC_WRAP_DRV_Reg32(PMIC_WRAP_STAUPD_STA)) != STAUPD_FSM_REQ_STATE) // Current STAUPD FSM is REQ State
    {
        ASSERT(0);
        return PMIC_WRAP_STAUPD_FSM_NOT_IDLE;
    }

    // If mode==1, only return after new status is updated.
    if(mode == 1)
    {
        return_value = wait_for_state_ready_init(wait_for_staupd_idle, 60, PMIC_WRAP_STAUPD_STA, 0);
        if(return_value != 0)
        {
            ASSERT(0);            
            return return_value;
        } 
    }

    return 0;
}

//--------------------------------------------------------
//    Function : DrvPWRAP_AlignCRC()
// Description : 
//   Parameter : 
//      Return : 
//--------------------------------------------------------
void DrvPWRAP_AlignCRC(void)
{
    kal_uint32 rdata;
//    kal_uint32 reg_rdata;
    kal_uint32 arb_en_backup;
    kal_uint32 staupd_prd_backup;
    kal_uint32 return_value;

    //Backup Configuration & Set New Ones
    arb_en_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_HIPRIO_ARB_EN); // Backup HIPRIO_ARB enable bitmap
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, HARB_HPRIO_WACS2); // HIPRIO_ARB enable for each source. (Set WACS2 highest priority)
    staupd_prd_backup = PMIC_WRAP_DRV_Reg32(PMIC_WRAP_STAUPD_PRD);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, 0x00); // Disable Periodic status update timing (period) selection.

    // reset CRC
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x00, &rdata); // Disable CRC calculation circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x00); // Disable CRC calculation circuit.

    return_value = wait_for_state_ready_init(wait_for_wrap_req_counter_zero, 60, PMIC_WRAP_WRAP_STA, 0);
    //  NEED TO CHECK
    if(return_value != 0)
    {
        ASSERT(0);
    }

    // Enable CRC
    DrvPWRAP_WACS2(PMIC_WRAP_WRITE, DEW_CRC_EN, 0x01, &rdata); // Enable CRC calculation circuit.
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CRC_EN, 0x01); // Enable CRC calculation circuit.

    //restore Configuration
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_STAUPD_PRD, staupd_prd_backup);
    PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_HIPRIO_ARB_EN, arb_en_backup); // Restore HIPRIO_ARB enable bitmap
}

//--------------------------------------------------------
//    Function : DrvPWRAP_InitRegClk()
// Description : 
//   Parameter : int regck_sel
//      Return : 
//--------------------------------------------------------
kal_uint32 DrvPWRAP_InitRegClk(kal_uint32 regck_sel) // 0:safe mode, 1:18MHz, 2:36MHz
{
    kal_uint32 wdata;
    kal_uint32 rdata;

    // Set reg clk freq
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, TOP_CKCON2, 0x00, &rdata); // Read Top clock control register 2

    if(regck_sel == PMIC_WRAP_REG_CLOCK_18MHZ)  
    {
//		wdata = rdata | 0x8000; // 32K
        wdata = (rdata & ~(0x3 << 10)) | (0x1 << 10);
    }
    else
    {
//        wdata = rdata & ~(0x8000); // 26Mhz
        wdata = (rdata & ~(0x3 << 10));
    }

    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_WRITE, TOP_CKCON2, wdata, &rdata); // Write RG_FQMTR_CKSEL (FQMTR clock source select)
    DrvPWRAP_WACS2_NoChk(PMIC_WRAP_READ, TOP_CKCON2,     0, &rdata); // Read again
    if(rdata != wdata) 
    {
        /* TERR="Error: [DrvPWRAP_InitRegClk] PMIC_TOP_CKCON2 Write [15]=1 Fail, rdata=%x", rdata*/
        ASSERT(0);        
        return PMIC_WRAP_WRITE_FAIL;
    }

    // Config SPI Waveform according to reg clk
    if(regck_sel == PMIC_WRAP_REG_CLOCK_18MHZ) 
    { 
        //18MHz
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x0C); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x04); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x0C); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x00); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x00); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
    }else if(regck_sel == PMIC_WRAP_REG_CLOCK_36MHZ)
    { 
        //36MHz    
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x04); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x00); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x04); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x00); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x00); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
    }else 
    { 
        //Safe mode
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT, 0x0F); // Extend CS high time to be at least (1+CSHEXT[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_WRITE, 0x0F); // Extend CS high time to be at least (1+CSHEXT_WRITE[3:0])T of SPI CLK.
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSHEXT_READ, 0x0F); // Extend CS high time to be at least (1+CSHEXT_READ[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_START, 0x0F); // Extend CS low time after CSL command to be at least (1.5+CSLEXT_START[3:0])T of SPI CLK
        PMIC_WRAP_DRV_WriteReg32(PMIC_WRAP_CSLEXT_END, 0x0F); // Extend CS low time before CSH command to be at least (1.5+CSLEXT_END[3:0])T of SPI CLK
    }

    return 0;
}
