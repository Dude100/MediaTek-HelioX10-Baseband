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
 *    ast_hif_hw_custom.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file contains common code for AST HIF adaptation layer.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================*/
#if defined(__AST_TL1_TDD__) && (defined(MT6575)||defined(MT6577)||defined(MT6589))

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "intrCtrl.h" 
#include "drv_comm.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "dcl.h"
#include "gpio_sw.h"
#include "eint.h"
#include "l1_interface.h"
#include "ast_hif_hw.h"
#include "hif_hal.h"
#include "reg_base.h"
#include "ast_hif_hw_custom.h"

HIF_HANDLE ast_hif_hw_handle = 0;
char ast_gpio_rst_pin;
char ast_gpio_wakeup_pin;
kal_uint32 ast_hif_port;

////////////////////////////////////////////////////////////////////////////////////////////////////
// Below is hif hardware interface
////////////////////////////////////////////////////////////////////////////////////////////////////

#if !defined(AST_HIF_HW_INIT_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_init(AST_HIF_HW_CONFIG_T* pConfigParam)
{
    DCL_HANDLE gpio_handle;
    GPIO_CTRL_SET_CLK_OUT_T gpio_clk_data;
    ASSERT(pConfigParam != NULL);
    
    ast_gpio_wakeup_pin = gpio_ast_wakeup_pin;
    ast_gpio_rst_pin = gpio_ast_rst_pin;

    //enable 32k to AST1001
    gpio_handle = DclGPIO_Open(DCL_GPIO_CLK, AST_GPIO_CLK32K_MODULE);
    gpio_clk_data.u2ClkNum=AST_GPIO_CLK32K_MODULE;
    gpio_clk_data.u2Mode=mode_f32k_ck;
    DclGPIO_Control(gpio_handle,GPIO_CMD_SET_CLK_OUT,(DCL_CTRL_DATA_T*)&gpio_clk_data);
    DclGPIO_Close(gpio_handle);	
    
    ast_hif_port = AST_HIF_PORT;
    ast_hif_hw_handle = hif_open(AST_HIF_PORT);
    
    ASSERT(ast_hif_hw_handle);
    
    ast_hif_hw_power_ctrl(KAL_TRUE);
    
    ast_hif_hw_config(pConfigParam);
	{
		HIF_REALTIME_CALLBACK_T HifRealTimeCB;
		HifRealTimeCB.realtime_callback_en = KAL_TRUE;
	    hif_ioctl(ast_hif_hw_handle,HIF_IOCTL_REALTIME_CALLBACK,&HifRealTimeCB);
    }
    
    ast_hif_hw_power_ctrl(KAL_FALSE);
    return AST_HIF_HW_RESULT_OK;
}
#endif

AST_HIF_HW_RESULT ast_hif_hw_config(AST_HIF_HW_CONFIG_T* pConfigParam)
{
    HIF_CONFIG_T pHIFConfig;
    pHIFConfig.hif_time_c2ws = pConfigParam->hif_time_c2ws;
    pHIFConfig.hif_time_c2wh = pConfigParam->hif_time_c2wh;
    pHIFConfig.hif_time_wst = pConfigParam->hif_time_wst;
    pHIFConfig.hif_time_c2rs = pConfigParam->hif_time_c2rs;
    pHIFConfig.hif_time_c2rh = pConfigParam->hif_time_c2rh;
    pHIFConfig.hif_time_rlt = pConfigParam->hif_time_rlt;
    pHIFConfig.hif_time_chw = 0;
    pHIFConfig.hif_base_clk = pConfigParam->hif_base_clk;
    pHIFConfig.hif_bus_width = pConfigParam->hif_bus_width;
    
    hif_config(ast_hif_hw_handle, &pHIFConfig);
    return AST_HIF_HW_RESULT_OK;
}

AST_HIF_HW_RESULT ast_hif_hw_power_ctrl(kal_bool bPowerOn)
{
    if (bPowerOn)
    {
        HIF_ULTRA_HIGH_CTRL_T UltraHighCtrl;
        HIF_REALTIME_CALLBACK_T HifRealTimeCB;
        hif_power_ctrl(ast_hif_hw_handle, KAL_TRUE);
        UltraHighCtrl.ultra_high_en = KAL_TRUE;
        hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_ULTRA_HIGH_CTRL, &UltraHighCtrl);
        HifRealTimeCB.realtime_callback_en = KAL_TRUE;
        hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_REALTIME_CALLBACK,&HifRealTimeCB);
    }
    else
    {
        hif_power_ctrl(ast_hif_hw_handle, KAL_FALSE);
    }
    return AST_HIF_HW_RESULT_OK;
}

AST_HIF_HW_RESULT ast_hif_hw_write(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB)
{
    HIF_RESULT result;
    switch (type)
    {
    case AST_HIF_HW_TYPE_A0H_CPU:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0H_DMA:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0H_DMA, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_CPU:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_DMA:
        result = hif_write(ast_hif_hw_handle, HIF_TYPE_A0L_DMA, addr, size, fCB);
        break;
    default:
        ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
    return (AST_HIF_HW_RESULT)result;
}

AST_HIF_HW_RESULT ast_hif_hw_read(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB)
{
    HIF_RESULT result;
    switch (type)
    {
    case AST_HIF_HW_TYPE_A0H_CPU:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0H_CPU, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0H_DMA:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0H_DMA, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_CPU:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0L_CPU, addr, size, fCB);
        break;
    case AST_HIF_HW_TYPE_A0L_DMA:
        result = hif_read(ast_hif_hw_handle, HIF_TYPE_A0L_DMA, addr, size, fCB);
        break;
    default:
        ASSERT(0);
        result = HIF_RESULT_INVALID_ARGUMENT;
        break;
    }
    return (AST_HIF_HW_RESULT)result;
}

#if !defined(AST_HIF_HW_REG_EINT_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_reg_eint(AST_HIF_HW_EINT_T* pEintParam)
{
    DCL_HANDLE gpio_handle;
    // register interrupt

    EINT_Set_Sensitivity(AST_EINT_NO, LEVEL_SENSITIVE);
    EINT_Set_Polarity(AST_EINT_NO, KAL_FALSE);
    EINT_Registration(AST_EINT_NO, KAL_FALSE, KAL_FALSE, pEintParam->fINTCB/*ast_hif_hw_eint_isr*/, KAL_TRUE);

    EINT_Set_Sensitivity(AST_WAKEUP_EINT_NO, EDGE_SENSITIVE);
    EINT_Set_Polarity(AST_WAKEUP_EINT_NO, KAL_TRUE);
    EINT_Registration(AST_WAKEUP_EINT_NO, KAL_FALSE, KAL_TRUE, pEintParam->fWakeUpCB, KAL_TRUE);

    EINT_Set_Sensitivity(AST_RFCONF_EINT_NO, LEVEL_SENSITIVE);
    EINT_Set_Polarity(AST_RFCONF_EINT_NO, KAL_TRUE);
	/* clear original debounce value */
	EINTaddr(AST_RFCONF_EINT_NO) &= ~EINT_CON_DEBOUNCE;
	/* set new debounce value */
	EINTaddr(AST_RFCONF_EINT_NO) |= (1 | EINT_CON_DEBOUNCE_EN);
    EINT_Registration(AST_RFCONF_EINT_NO, KAL_TRUE, KAL_TRUE, pEintParam->fRFConfCB, KAL_TRUE);
    return AST_HIF_HW_RESULT_OK;
}
#endif

kal_bool ast_hif_hw_query_power_state(void)
{
    HIF_POWER_STATE_T power_state;
    hif_ioctl(ast_hif_hw_handle, HIF_IOCTL_QUERY_POWER_STATE, &power_state);
    return power_state.hif_power_on;
}

#if !defined(AST_HIF_HW_SET_GPIO_BY_PROJECT)
AST_HIF_HW_RESULT ast_hif_hw_set_gpio(char value, char pin)
{
    DCL_HANDLE handle;
    handle=DclGPIO_Open(DCL_GPIO, pin);	
    if(0==value)
        DclGPIO_Control(handle,GPIO_CMD_WRITE_LOW,0);
    else if(1==value)
        DclGPIO_Control(handle,GPIO_CMD_WRITE_HIGH,0);
    else
    {
        DclGPIO_Close(handle);
        ASSERT(0);
    }
    DclGPIO_Close(handle);
    return AST_HIF_HW_RESULT_OK;
}
#endif

#endif
// END
