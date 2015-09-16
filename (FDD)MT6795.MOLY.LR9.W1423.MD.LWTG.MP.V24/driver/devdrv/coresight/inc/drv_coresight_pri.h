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
 *   drv_coresight_pri.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Coresight driver header file
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
 * [MOLY] DNT Modification
 *
 * removed!
 * removed!
 * [MOLY] DNT Modification for 6290E1, sync back to MOLY TRUNK from FIRSTCALL BRANCH
 *
 * removed!
 * removed!
 * [MOLY Trunk] DNT Modification for ASIC
 ****************************************************************************/
#define NEW_DNT_ADDRESS_SPACE

#ifndef __FPGA__
#define CNP_PARKING_IOMUX_TO_GPIO_INPUT_MODE
#endif

#define CNP_CONTROL_PIN_CAPTURE_MODE  GPIO_CMD_WRITE_HIGH
#define CNP_CONTROL_PIN_PLAYBACK_MODE GPIO_CMD_WRITE_LOW


#define ATB_CLOCK                   (65*1000*1000) // 65MHz
#define STP_CLOCK                   (130*1000*1000) // 130MHz
#define STP_DIVIDE_BY_CR4            1.62175 // MSBB (no divide) -> 130/80.16
#define CR4_CLOCK                   (80160*1000) // 80.16MHz
#define CR4_CLOCK_1US_DIV           CR4_CLOCK/1000000
#define CR4_CLOCK_1MS_DIV           CR4_CLOCK/1000

//###########################################################################//
//  DSP C2CRF Control                                                        //
//###########################################################################//
#define BASE_ADDR_CORE_APB_FCORE1   (0xB6500000)
#define BASE_ADDR_CORE_DMAIF_FCORE1 (0xB6501000)



//###########################################################################//
//  Trace Function Control                                                   //
//###########################################################################//
#define APPERISYS_TRACE_CTRL        (BASE_ADDR_APMISC + 0x90)
#define IO_CAPTURE_MODE             (1) // bit 0
#define IO_PLAYBACK_MODE            (0) // bit 0

//###########################################################################//
//  IP : Trace Top                                                           //
//###########################################################################//
#ifdef __FPGA__ // FPGA
#define TRACE_TOP_BASE_ADDRESS      (BASE_ADDR_MDDBGAPB + 0x00318000) // bit15 : 1 (B931_8000)
#else
#define TRACE_TOP_BASE_ADDRESS      (BASE_ADDR_MDDBGAPB + 0x00418000) // B941_8000
#endif

#define TRACE0_ADDR_OFFSET          (0x0000) //bit14 => 0 for trace unit 0
#define TRACE1_ADDR_OFFSET          (0x4000) //bit14 => 1 for trace unit 1
#define TRACE01_ADDR_DIFF           (TRACE1_ADDR_OFFSET - TRACE0_ADDR_OFFSET)


#define TPIU_BASE_ADDRESS           (TRACE_TOP_BASE_ADDRESS + TRACE0_ADDR_OFFSET + 0x0000) // [13:12] 00,  0xB9318000/0xB931C000 0xB9418000/0xB941C000
#define TRACE_FUNNEL                (TRACE_TOP_BASE_ADDRESS + TRACE0_ADDR_OFFSET + 0x1000) // [13:12] 01,  0xB9319000/0xB931D000 0xB9419000/0xB941D000
#define STP_BASE_ADDRESS            (TRACE_TOP_BASE_ADDRESS + TRACE0_ADDR_OFFSET + 0x2000) // [13:12] 10,  0xB931A000/0xB931E000 0xB941A000/0xB941E000
#define ATB_LIMITER_BASE_ADDR       (TRACE_TOP_BASE_ADDRESS + TRACE0_ADDR_OFFSET + 0x3800) // [13:11] 111, 0xB931B800/0xB931F800 0xB941B800/0xB941F800
#define TRACE_APB_MISC_BASE_ADDR    (TRACE_TOP_BASE_ADDRESS + TRACE0_ADDR_OFFSET + 0x3000) // [13:11] 110, 0xB931B000/0xB931F000 0xB941B000/0xB941F000

//===========================================================================//
//  Bandwidth Limiter CSR                                                    //
//===========================================================================//
#define ATBBWL_EN_REG_ADDR          (ATB_LIMITER_BASE_ADDR)

//===========================================================================//
//  Trace Funnel                                                             //
//===========================================================================//
#define CSTF_CONTROL                (TRACE_FUNNEL + 0x000)
#define MINUMUM_HOLD_TIME_15        (14 << 8)
#define MINUMUM_HOLD_TIME_1         (0 << 8)

#define ENABLE_SLAVE_PORT0          (1 << 0)
#define ENABLE_SLAVE_PORT1          (1 << 1)
#define ENABLE_SLAVE_PORT2          (1 << 2)
#define ENABLE_SLAVE_PORT3          (1 << 3)
#define ENABLE_SLAVE_PORT4          (1 << 4)
#define ENABLE_SLAVE_PORT5          (1 << 5)
#define ENABLE_SLAVE_PORT6          (1 << 6)
#define ENABLE_SLAVE_PORT7          (1 << 7)
// Ch0
// 0 : ADCC
// 1 : x
// 2 : x
// 3 : patgen0
// 4 : patgen1
// 5 : x
// 6 : x 
// 7: flush master
#define CH0_CONNECTED_PORT          (0x80)
// Ch1
// 0 : ADCC
// 1 : L2C
// 2 : DSP
// 3 : patgen0
// 4 : patgen1
// 5 : 3g_0
// 6: 3g_1
// 7: flush master
#define CH1_CONNECTED_PORT          (0xFF)


#define CSTF_PRIO_CONTROL           (TRACE_FUNNEL + 0x004)
// 0 gets highest priority and 7 gets the lowest priority
//[23:21] PriPort 7 7th port priority value.
//[20:18] PriPort 6 6th port priority value.
//[17:15] PriPort 5 5th port priority value.
//[14:12] PriPort 4 4th port priority value.
//[11:9]  PriPort 3 3rd port priority value.
//[8:6]   PriPort 2 2nd port priority value.
//[5:3]   PriPort 1 2st port priority value.
//[2:0]   PriPort 0 1th port priority value.




#define CSTF_ITATBCTR0              (TRACE_FUNNEL + 0xEF8)
#define ATVALID                     (0x00000001)
#define AFREADY                     (0x00000002)



#define CSTF_IT_CONTROL             (TRACE_FUNNEL + 0xF00)
#define ENABLE_INTEGRATION_MODE     (1 << 0)
#define DISABLE_INTEGRATION_MODE    (0 << 0)




//===========================================================================//
//  TPIU                                                                     //
//===========================================================================//
#define TPIU_CURRENT_PORT_SIZE_REG  (TPIU_BASE_ADDRESS + 0x004)
#define PORT_SIZE_16                (1 << 15)
#define TPIU_FFCR_REG		         (TPIU_BASE_ADDRESS + 0x304)
#define TPIU_FOnMan                 (1 << 6) //Manually generate a flush of the system. Setting this bit causes a flush to be generated
#define TPIU_FOnFlIn                (1 << 4)
#define TPIU_EnFCont                (1 << 1)
#define TPIU_IT_MODE_CONTROL        (TPIU_BASE_ADDRESS + 0xF00)





//===========================================================================//
//  STP                                                                      //
//===========================================================================//
#define STP_CONTROL_REG             (STP_BASE_ADDRESS + 0x00)
#define STP_ENA                     (1 << 8) // Serial Trace Port Enable
#define PG_ENA                      (1 << 9) // Pattern Gen Enable


#define STP_LINK_COUNT              (STP_BASE_ADDRESS + 0x04)
#define LNK_SCOUNT_32769            (0x8000)
#define LNK_SCOUNT_1                (0x0000)
#define LNK_TCOUNT_8                (8 << 16)
#define LNK_TCOUNT_9                (9 << 16)

#define STP_LINK_TINT               (STP_BASE_ADDRESS + 0x14)
#define LNK_TINTERVAL_16            (0x00E)
#define LNK_TINTERVAL_4096          (0xFFE)

#define STP_FLUSHTH                 (STP_BASE_ADDRESS + 0x18)
#define FLUSHTH_4095                (0xFFF)
#define FLUSHTH_4094                (0xFFE)

#define STP_PG_TEST_0               (STP_BASE_ADDRESS + 0x40)
#define STP_PG_TEST_1               (STP_BASE_ADDRESS + 0x44)
#define STP_PG_TEST_2               (STP_BASE_ADDRESS + 0x48)
#define STP_PG_TEST_3               (STP_BASE_ADDRESS + 0x4C)





//===========================================================================//
//  MISC                                                                     //
//===========================================================================//
#define TRACE_PORT3_ATID            (TRACE_APB_MISC_BASE_ADDR + 0x00)
#define TRACE_PORT4_ATID            (TRACE_APB_MISC_BASE_ADDR + 0x04)
#define TRACE_PORT5_ATID            (TRACE_APB_MISC_BASE_ADDR + 0x08)
#define TRACE_PORT6_ATID            (TRACE_APB_MISC_BASE_ADDR + 0x0C)
#define TRACE_PORT7_ATID            (TRACE_APB_MISC_BASE_ADDR + 0x10)
#define DNT_STP_MISC                (TRACE_APB_MISC_BASE_ADDR + 0x14)

#define DNT_MISC_CTRL               (TRACE_APB_MISC_BASE_ADDR + 0x18)
#define SW_FLUSH_EN                 (1 << 0)
#define SW_FLUSH_DISABLE            (0 << 0)
#define SW_TPIU_FLUSH               (1 << 1)



#define DNT_PATGEN_CONFIG           (TRACE_APB_MISC_BASE_ADDR + 0x20)
#define PATGEN1_DONE                (1 << 21)
#define PATGEN1_INC_ONE             (0 << 18)
#define PATGEN1_DEC_ONE             (1 << 18)
#define PATGEN1_INC_PAT             (6 << 18)
#define PATGEN1_INIT                (1 << 17)
#define PATGEN1_START               (1 << 16)
#define PATGEN0_DONE                (1 << 5)
#define PATGEN0_INC_ONE             (0 << 2)
#define PATGEN0_DEC_ONE             (1 << 2)
#define PATGEN0_INC_PAT             (6 << 2)
#define PATGEN0_INIT                (1 << 1)
#define PATGEN0_START               (1 << 0)


#define DNT_PATGEN0_LENGTH          (TRACE_APB_MISC_BASE_ADDR + 0x24)
#define DNT_PATGEN1_LENGTH          (TRACE_APB_MISC_BASE_ADDR + 0x28)
#define DNT_PATGEN0_INIT_VAL        (TRACE_APB_MISC_BASE_ADDR + 0x30)
#define DNT_PATGEN0_INC_VAL         (TRACE_APB_MISC_BASE_ADDR + 0x34)
#define DNT_PATGEN1_INIT_VAL        (TRACE_APB_MISC_BASE_ADDR + 0x38)
#define DNT_PATGEN1_INC_VAL         (TRACE_APB_MISC_BASE_ADDR + 0x3C)

#define DNT_MONITOR_MEM_CTRL        (TRACE_APB_MISC_BASE_ADDR + 0x60)
#define MONITOR_WPTR_MASK           (0x03FF0000) // bit 25:16
#define FILTER_RULE3_EN             (1 << 11)
#define FILTER_RULE2_EN             (1 << 10)
#define FILTER_RULE1_EN             (1 << 9)
#define FILTER_RULE0_EN             (1 << 8)
#define MONITOR_FULL_STOP_EN        (1 << 2)
#define MONITOR_WPTR_CLR            (1 << 1)
#define MONITOR_READ                (1 << 0)


#define DNT_MONITOR_MEM_RADDR       (TRACE_APB_MISC_BASE_ADDR + 0x64)
#define DNT_MONITOR_MEM_RDATA       (TRACE_APB_MISC_BASE_ADDR + 0x68)
#define DNT_MONITOR_FILTER_RULE01   (TRACE_APB_MISC_BASE_ADDR + 0x70)
#define DNT_MONITOR_FILTER_RULE23   (TRACE_APB_MISC_BASE_ADDR + 0x74)



//===========================================================================//
//  SERDES Control                                                           //
//===========================================================================//
#define SERDES_BOARD_CTRL           (TRACE_APB_MISC_BASE_ADDR + 0x84)
#define SERDES_TEST_IF              (1 << 31)
#define SERDES_TEST_MODE_SCAN       (0 << 11)
#define SERDES_TEST_MODE_INC        (1 << 11)
#define SERDES_TEST_MODE_DEC        (2 << 11)
#define SERDES_TEST_MODE_MIXED      (3 << 11)
#define PRBSEN                      (1 << 10) // TLK3101 PRBSEN pin
#define LOOPEN                      (1 << 9)  // TLK3101 LOOPEN pin
#define LCKREFN                     (1 << 8)  // TLK3101 LCKREFN pin
#define SERDES_ERROR_NUM_MASK       (0x1F << 3)
#define SERDES_ERROR_NUM_SHIFT      (3)
#define SERDES_TEST_FAIL            (1 << 2)
#define SERDES_TEST_DONE            (1 << 1)
#define SERDES_TEST_EN              (1 << 0)




//===========================================================================//
//  LOCL/UNLOCK Protection for CoreSight IP                                  //
//===========================================================================//

#define CORESIGHT_LOCK_AC_REG    0xFB0
#define CORESIGHT_LOCK_ST_REG    0xFB4

#define CORESIGHT_CONST_KEYLOCK  0x0
#define CORESIGHT_CONST_KEYRELE  0xC5ACCE55
#define CORESIGHT_CONST_UNLOCK   0x0
#define CORESIGHT_CONST_LOCKED   0x2
#define CORESIGHT_MASK_LOCK      0x00000002

//===========================================================================//
//  Other Misc                                                               //
//===========================================================================//
#define TOPSM_FRC_CON          	   	(BASE_ADDR_MDTOPSM + 0x80)  /* Free Running Counter Control Register (with Magic Word: 0x6276xxxx) */
#define TOPSM_FRC_VAL_R        	   	(BASE_ADDR_MDTOPSM+0x88)  /* Free Running Counter Current Value */


//===========================================================================//
//  DNT Register Read/Write Macro Redifine                                   //
//===========================================================================//
#define TRACE_WriteReg32(addr, path, data) (path? DRV_WriteReg32((addr) | TRACE01_ADDR_DIFF, data) : DRV_WriteReg32(addr, data))
                                         
#define TRACE_ReadReg32(addr, path)        (path? DRV_Reg32((addr) | TRACE01_ADDR_DIFF) : DRV_Reg32(addr))



#if 0 //move api to publif
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


//===========================================================================//
//  DRV Extern Function Protype                                              //
//===========================================================================//
kal_int32 MISC_CoreSight_Module_Lock_By_Addr(kal_uint32 lock_access_addr, kal_uint32 lock_status_addr, kal_uint32 uDNTSel);
kal_int32 MISC_CoreSight_Module_Unlock_By_Addr(kal_uint32 lock_access_addr, kal_uint32 lock_status_addr, kal_uint32 uDNTSel);
kal_int32 MISC_CoreSight_Module_Lock(kal_uint32 addr, kal_uint32 uDNTSel);
kal_int32 MISC_CoreSight_Module_Unlock(kal_uint32 addr, kal_uint32 uDNTSel);


void TF_init(eSIB_Configure_mode SIB_Configure_mode);

void CNP_iomux_sel(eSIB_Configure_mode SIB_Configure_mode);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


