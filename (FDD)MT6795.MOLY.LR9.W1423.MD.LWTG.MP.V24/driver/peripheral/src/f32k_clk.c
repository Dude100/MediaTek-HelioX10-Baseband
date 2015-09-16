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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    f32k_clk.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the F32K_CLK driver.
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
 * removed!
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
 *
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
 *
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
 *
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
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#include "kal_public_api.h"
#include "drv_features.h" 
#include "f32k_clk_sw.h"
#include "f32k_clk_hw.h"
#include "rtc_sw_new.h"
#include "rtc_hw.h"
#include "dcl.h"

#if !defined(DRV_F32K_CLK_OFF)
#if defined(DRV_F32K_INTERNAL_32K)
void F32K_XOSC32_EMB_setting(void)
{
    kal_uint16 reg_val;
    kal_uint32 wait_count;
    kal_uint16 key1 = DRV_F32K_Reg(RTC_POWERKEY1);
    kal_uint16 key2 = DRV_F32K_Reg(RTC_POWERKEY2);

    // wait CBUSY to idle
    wait_count = 0;
    while(wait_count < 0xffffffff)
    {
        if ((DRV_F32K_Reg(RTC_BBPU) & RTC_BBPU_CBUSY) == 0)
        {
            break;
        }
        wait_count++;
    }

    // config 32K setting    
    if ((key1 != RTC_POWERKEY1_KEY) || (key2 != RTC_POWERKEY2_KEY))
    {
        reg_val = DRV_F32K_Reg(RTC_XOSCCAL);

        if ((reg_val & 0x20) == 0x0) // XOSC32K 
        {   /*
             * set XOSCCALI to default value
             * set EOSC_CHOP_EN=1
             */
            reg_val = (RTC_OSC32_EOSC_CHOP_EN | F32K_XOSCCALI_DEF_VAL); 
        }
        else // DCXO, EOSC32
        {
            /*
             * set EOSCCALI to default value
             * set EOSC_CHOP_EN=1
             * config internal 32k setting to EMB_HW mode
             * RTC_OSC32_AMP_EN: valid bit in MT6255
             *                   reserved bit in MT6250
             */
            reg_val = (RTC_OSC32_EOSC_CHOP_EN | RTC_OSC32_AMP_EN | RTC_OSC32_XOSC32_ENB | F32K_EOSCCALI_DEF_VAL);
        }        

        wait_count = 0;     
        DRV_F32K_WriteReg(RTC_XOSCCAL, 0x1a57);
        while(wait_count < 0xffff)
        {    
            if (DRV_F32K_Reg(RTC_XOSCCAL) == 0x1a57)
                break;
        
            wait_count++;            
        }
       
        wait_count = 0;     
        DRV_F32K_WriteReg(RTC_XOSCCAL, 0x2b68);
        while(wait_count < 0xffff)
        {    
            if (DRV_F32K_Reg(RTC_XOSCCAL) == 0x2b68)
                break;
        
            wait_count++;            
        }

        wait_count = 0;     
        DRV_F32K_WriteReg(RTC_XOSCCAL, reg_val);
        while(wait_count < 0xffff)
        {    
            if (DRV_F32K_Reg(RTC_XOSCCAL) == reg_val)
                break;
        
            wait_count++;            
        }
    }

#if 0    
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif        
}
#endif //#if defined(DRV_F32K_INTERNAL_32K)

#if !defined(__MINI_BOOTLOADER__)
#if defined(DRV_F32K_INTERNAL_32K)

kal_bool F32K_Query_Is_XOSC32(void)
{
    DCL_HANDLE rtc_handler;
    RTC_CTRL_READ_XOSC_REG_T rtc_xosc32_config;
    
    rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);
    DclRTC_Control(rtc_handler, RTC_CMD_RELOAD, (DCL_CTRL_DATA_T *)NULL);

    DclRTC_Control(rtc_handler, RTC_CMD_WRITE_TRIGGER_WAIT, NULL);

    DclRTC_Control(rtc_handler, RTC_CMD_READ_XOSC_REG, (DCL_CTRL_DATA_T *)&rtc_xosc32_config);
    
    DclRTC_Close(rtc_handler); 
    
    if ((rtc_xosc32_config.XOSCValue & 0x20) == 0x0)
        return KAL_TRUE;
    else
        return KAL_FALSE;
}


kal_uint32 F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(kal_uint16 eosccal_value, kal_uint16 winset)
{
        kal_uint16 reg_value, reg_xosccal_value;
        kal_uint32 FQMTR_DATA, wait_count, latency_time_start;
       
        DCL_HANDLE rtc_handler;
        RTC_CTRL_WRITE_OSC32CON_REG_T rtc_osc32_con;

        
        reg_xosccal_value = DRV_F32K_Reg(RTC_XOSCCAL);
        reg_xosccal_value &= ~0x1f;
        reg_xosccal_value |= eosccal_value;
           
        rtc_handler = DclRTC_Open(DCL_RTC, FLAGS_NONE);

        rtc_osc32_con.OSC32CON_Reg = reg_xosccal_value;
        DclRTC_Control(rtc_handler, RTC_CMD_WRITE_OSC32CON_REG, (DCL_CTRL_DATA_T *)&rtc_osc32_con);
        DclRTC_Close(rtc_handler);        

        reg_value = FQMTR_RST;         
        DRV_F32K_WriteReg(FQMTR_CON0, reg_value); // Stop freq-meter 
        /* latency time (of FQMTR_BUSY bit eable) is 2 tick time of fixed clock 
           fixed clock is EOSC32 clock
        */
        latency_time_start = drv_get_current_time(); // 32k clock time tick
        wait_count = 0;
        while(wait_count < 0xffffffff)
        {
            if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 50) // 25*2 tick
                break;
            
            wait_count++;
        }

#if defined(DRV_F32K_FQMTR_AS_6255)        
        while(DRV_F32K_Reg(FQMTR_CON2) & FQMTR_BUSY);        
        reg_value = FQMTR_EN | winset;        
        DRV_F32K_WriteReg(FQMTR_CON0, reg_value); // start freq-meter         
#elif defined(DRV_F32K_FQMTR_AS_6250)
        while(DRV_F32K_Reg(FQMTR_CON0) & FQMTR_BUSY);
        reg_value = winset; 
        DRV_F32K_WriteReg(FQMTR_CON3, reg_value); // start freq-meter         
        reg_value = FQMTR_EN; 
        DRV_F32K_WriteReg(FQMTR_CON0, reg_value); // start freq-meter 
#endif 
        
        /* latency time (of FQMTR_BUSY bit eable) is 2 tick time of fixed clock 
           fixed clock is EOSC32 clock
        */
        latency_time_start = drv_get_current_time(); // 32k clock time tick
        wait_count = 0;
        while(wait_count < 0xffffffff)
        {
            if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 50) // 25*2 tick
                break;
            
            wait_count++;
        }

#if defined(DRV_F32K_FQMTR_AS_6255)          
        while(DRV_F32K_Reg(FQMTR_CON2) & FQMTR_BUSY);   
#elif defined(DRV_F32K_FQMTR_AS_6250)
        while(DRV_F32K_Reg(FQMTR_CON0) & FQMTR_BUSY);
#endif

        /* latency time (of get fqmtr_data ) is 1 tick time of test clock 
           test clock is 13M clock                                        
        */
        latency_time_start = drv_get_current_time();
        wait_count = 0;
        while(wait_count<0xffffffff)
        {
            if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 10) // 10 32K tick       
                break;
            
            wait_count++;
        }

#if defined(DRV_F32K_FQMTR_AS_6255)
        //FQMTR_DATA = ((DRV_F32K_Reg(FQMTR_CON3)&0x7fff)<<15)|((DRV_F32K_Reg(FQMTR_CON2)&0x7fff));
        FQMTR_DATA = DRV_F32K_Reg(FQMTR_CON2)&0x7fff;
#elif defined(DRV_F32K_FQMTR_AS_6250)
        FQMTR_DATA = DRV_F32K_Reg(FQMTR_CON2);
#endif

        return FQMTR_DATA;
}

kal_uint16 F32K_EOSC32_trimming(void)
{
    kal_uint16 reg_value;
    kal_uint16 eosccal_value_min, eosccal_value_med, eosccal_value_max;
    kal_uint32 FQMTR_Data_Min, FQMTR_Data_Med, FQMTR_Data_Max;

#if defined(DRV_F32K_FQMTR_AS_6255)
    DRV_F32K_WriteReg(FQMTR_CON0, FQMTR_EN); // enable freq-meter    
    // always count, FIXED clock = EOSC32_CK, TESTED clock= CLKSQ 13MHz
    reg_value =  FQMTR_COND_ON | FQMTR_FCKSEL_EOSC32K | FQMTR_TCKSEL_CLKSQ13M;  
    DRV_F32K_WriteReg(FQMTR_CON1, reg_value);   
#elif defined(DRV_F32K_FQMTR_AS_6250) 
    DRV_F32K_WriteReg(FQMTR_CON0, FQMTR_EN); // enable freq-meter    
    DRV_F32K_WriteReg(FQMTR_CON1, FQMTR_TCKSEL_EOSC32K); 
#endif

    //winset = FQMTR_WINSET_LV1;
    eosccal_value_min = F32K_EOSCCALI_MIN;
    eosccal_value_max = F32K_EOSCCALI_MAX;

#if defined(DRV_F32K_FQMTR_AS_6255)

    FQMTR_Data_Max = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_max, FQMTR_WINSET_LV1);

    FQMTR_Data_Min = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_min, FQMTR_WINSET_LV1);  

    if (IDLE_VAL_WITH_WINSET_LV1 < FQMTR_Data_Min)
    {
        //ASSERT(0);
        return eosccal_value_min;
    }
    
    if (FQMTR_Data_Max < IDLE_VAL_WITH_WINSET_LV1)
    {
        //ASSERT(0);
        return eosccal_value_max;        
    }
    
#elif defined(DRV_F32K_FQMTR_AS_6250)  

    FQMTR_Data_Min = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_max, FQMTR_WINSET_LV1);

    FQMTR_Data_Max = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_min, FQMTR_WINSET_LV1);  

    if (IDLE_VAL_WITH_WINSET_LV1 < FQMTR_Data_Min)
    {
        //ASSERT(0);
        return eosccal_value_max;
    }

    if (FQMTR_Data_Max < IDLE_VAL_WITH_WINSET_LV1)
    {
        //ASSERT(0);
        return eosccal_value_min;        
    }

#endif

    while (1) {
        eosccal_value_med = (eosccal_value_min + eosccal_value_max)>>1;
        
        if (eosccal_value_min == eosccal_value_med)
        {
            if ((IDLE_VAL_WITH_WINSET_LV1-FQMTR_Data_Min) > (FQMTR_Data_Max-IDLE_VAL_WITH_WINSET_LV1))
            {
                return eosccal_value_max;
            }
            else if ((IDLE_VAL_WITH_WINSET_LV1-FQMTR_Data_Min) < (FQMTR_Data_Max-IDLE_VAL_WITH_WINSET_LV1))
            {
                return eosccal_value_min;
            }
            else {
#if defined(DRV_F32K_FQMTR_AS_6255)                            
                FQMTR_Data_Min = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_min, FQMTR_WINSET_LV2);
                FQMTR_Data_Max = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_max, FQMTR_WINSET_LV2);
                if ((IDLE_VAL_WITH_WINSET_LV2-FQMTR_Data_Min) <= (FQMTR_Data_Max-IDLE_VAL_WITH_WINSET_LV2))
                {
                    return eosccal_value_min;
                }
                else {
                    return eosccal_value_max;
                }   
#elif defined(DRV_F32K_FQMTR_AS_6250)  
                return eosccal_value_min;
#endif
            }
        } 

        FQMTR_Data_Med = F32K_Get_FQMTR_DATA_For_EOSC32_Trimming(eosccal_value_med, FQMTR_WINSET_LV1);

        if (FQMTR_Data_Med < IDLE_VAL_WITH_WINSET_LV1)
        {
#if defined(DRV_F32K_FQMTR_AS_6255)        
            eosccal_value_min = eosccal_value_med;
            FQMTR_Data_Min = FQMTR_Data_Med;        
#elif defined(DRV_F32K_FQMTR_AS_6250)  
            eosccal_value_max = eosccal_value_med;
            FQMTR_Data_Max = FQMTR_Data_Med;    
#endif
        }
        else if (IDLE_VAL_WITH_WINSET_LV1 < FQMTR_Data_Med)
        {
#if defined(DRV_F32K_FQMTR_AS_6255)         
            eosccal_value_max = eosccal_value_med;       
            FQMTR_Data_Max = FQMTR_Data_Med;
#elif defined(DRV_F32K_FQMTR_AS_6250)  
            eosccal_value_min = eosccal_value_med;       
            FQMTR_Data_Min = FQMTR_Data_Med;
#endif
        }
        else 
        {
            return eosccal_value_med;
        }
        
    }
    //return 0xf; 
}

#endif //#if defined(DRV_F32K_INTERNAL_32K)


#if defined(DRV_F32K_SWITCH_32K)

kal_bool F32K_Query_Is_XOSC32(void)
{
    kal_uint16 reg_val;

    // read MD CHIP STATUS register
    reg_val = DRV_F32K_Reg(F32K_MD_CHIP_STATUS);
    if ((reg_val & F32K_SYS_PAD32K_BOND_EN) == F32K_SYS_PAD32K_BOND_EN)
    {
        return KAL_TRUE;
    }

    // read AP_F32K_SEL register
    reg_val = DRV_F32K_Reg(F32K_AP_F32K_SEL);
    if ((reg_val & F32K_AP_PAD32K_CK_EN) == F32K_AP_PAD32K_CK_EN)
    {
        return KAL_TRUE;
    }
    else
    {
        return KAL_FALSE;
    }
}

void F32K_Switch_32K_setting(void)
{
    kal_uint16 reg_value, fqmtr_data, f32k_md_status;
    kal_uint32 wait_count, latency_time_start;

    // read MD CHIP STATUS register
    f32k_md_status = DRV_F32K_Reg(F32K_MD_CHIP_STATUS);

    // init FIXED clock = PAD_32K, TESTED clock= 26MHZ
    reg_value = FQMTR_FCKSEL_PAD32K | FQMTR_TCKSEL_CLKSSQ26M;
    DRV_F32K_WriteReg(FQMTR_CON1, reg_value); 

    // reset FQMTR
    DRV_F32K_WriteReg(FQMTR_CON0, FQMTR_RST);

    latency_time_start = drv_get_current_time(); // 32k clock time tick
    wait_count = 0;
    while(wait_count < 0xffffffff)
    {
        if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 50) // 25*2 tick
            break;
        
        wait_count++;
    }

    while(DRV_F32K_Reg(FQMTR_CON1) & FQMTR_BUSY);   

    // set WINSET and enable FQMTR
    reg_value = FQMTR_EN | F32K_FQMTR_WINSET;
    DRV_F32K_WriteReg(FQMTR_CON0, reg_value);

    latency_time_start = drv_get_current_time(); // 32k clock time tick
    wait_count = 0;
    while(wait_count < 0xffffffff)
    {
        if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 50) // 25*2 tick
            break;
        
        wait_count++;
    }

    while(DRV_F32K_Reg(FQMTR_CON1) & FQMTR_BUSY); 

    latency_time_start = drv_get_current_time();
    wait_count = 0;
    while(wait_count<0xffffffff)
    {
        if (drv_get_duration_tick(latency_time_start, drv_get_current_time()) > 10) // 10 32K tick       
            break;
        
        wait_count++;
    }

    fqmtr_data = DRV_F32K_Reg(FQMTR_CON3);    

    if ((f32k_md_status & F32K_SYS_PAD32K_BOND_EN) == F32K_SYS_PAD32K_BOND_EN)
    {
        if ((FQMTR_PAD32K_LOWER_BOUND < fqmtr_data) && (fqmtr_data < FQMTR_PAD32K_UPPER_BOUND))
        {
            // chip is System pad_32K bonding and PAD_32K exist
            DRV_F32K_WriteReg32(F32K_AP_F32K_SEL, F32K_AP_PAD32K_CK_EN);
        }
        else 
        {
            // chip is System pad_32K bonding but PAD_32K don't exist
            ASSERT(0);
        }
    }
    else 
    {
        if ((FQMTR_PAD32K_LOWER_BOUND < fqmtr_data) && (fqmtr_data < FQMTR_PAD32K_UPPER_BOUND))
        {
            // chip isn't System pad_32K bonding and PAD_32K exist
            DRV_F32K_WriteReg32(F32K_AP_F32K_SEL, F32K_AP_PAD32K_CK_EN);
        }
    }

    // reset FQMTR to default value
    DRV_F32K_WriteReg(FQMTR_CON1, FQMTR_CON0_DEFAULT_VAL); 
    DRV_F32K_WriteReg(FQMTR_CON0, FQMTR_CON1_DEFAULT_VAL);

}


#endif //#if defined(DRV_F32K_SWITCH_32K)

#endif //#if !defined(__MINI_BOOTLOADER__)

#else //#if !defined(DRV_F32K_CLK_OFF)
void F32K_XOSC32_EMB_setting(void) {}
kal_bool F32K_Query_Is_XOSC32(void) {}
kal_uint16 F32K_EOSC32_trimming(void) {}
void F32K_Switch_32K_setting(void) {}

#endif //#if !defined(DRV_F32K_CLK_OFF)

