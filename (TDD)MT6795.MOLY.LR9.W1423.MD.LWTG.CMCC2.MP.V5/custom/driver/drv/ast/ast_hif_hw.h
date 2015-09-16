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
 *    ast_hif_hw.h
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
#ifndef __HIF_HW_H__
#define __HIF_HW_H__

#if defined(__AST_TL1_TDD__) && (defined(MT6575)||defined(MT6577)||defined(MT6589))
#include "ast_hif_hw_custom.h"

extern char gpio_ast_rst_pin;           
extern char gpio_ast_cs_pin;
extern char gpio_ast_clk32k_pin;
extern char gpio_ast_intr_pin;
extern char gpio_ast_wakeup_intr_pin;
extern char gpio_ast_rfconf_intr_pin;
extern char gpio_ast_wakeup_pin;

extern unsigned char AST_EINT_NO;
extern unsigned char AST_WAKEUP_EINT_NO;
extern unsigned char AST_RFCONF_EINT_NO;

extern char ast_gpio_rst_pin;
extern char ast_gpio_wakeup_pin;
extern kal_uint32 ast_hif_port;

typedef void (*AST_HIF_HW_CALLBACK)(void);

typedef enum
{
    AST_HIF_HW_RESULT_OK = 0,
    AST_HIF_HW_RESULT_ERROR_OTHERS = 1,
    AST_HIF_HW_RESULT_NOT_SUPPORTED = 2,
    AST_HIF_HW_RESULT_INVALID_ARGUMENT = 4,
    AST_HIF_HW_RESULT_HIF_NOT_POWERON = 5
} AST_HIF_HW_RESULT;

typedef enum
{
    AST_HIF_HW_TYPE_A0H_CPU,
    AST_HIF_HW_TYPE_A0H_DMA,
    AST_HIF_HW_TYPE_A0L_CPU,
    AST_HIF_HW_TYPE_A0L_DMA,
} AST_HIF_HW_TYPE;

typedef struct
{
    kal_uint32 hif_time_c2ws;
    kal_uint32 hif_time_c2wh;
    kal_uint32 hif_time_wst;
    kal_uint32 hif_time_c2rs;
    kal_uint32 hif_time_c2rh;
    kal_uint32 hif_time_rlt;
    kal_uint32 hif_base_clk;
    kal_uint32 hif_bus_width;
} AST_HIF_HW_CONFIG_T;

typedef struct
{
    AST_HIF_HW_CALLBACK fINTCB;
    AST_HIF_HW_CALLBACK fWakeUpCB;
    AST_HIF_HW_CALLBACK fRFConfCB;
} AST_HIF_HW_EINT_T;

AST_HIF_HW_RESULT ast_hif_hw_init(AST_HIF_HW_CONFIG_T* pConfigParam);
AST_HIF_HW_RESULT ast_hif_hw_config(AST_HIF_HW_CONFIG_T* pConfigParam);
AST_HIF_HW_RESULT ast_hif_hw_write(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB);
AST_HIF_HW_RESULT ast_hif_hw_read(AST_HIF_HW_TYPE type, kal_uint32 addr, kal_uint32 size, AST_HIF_HW_CALLBACK fCB);
AST_HIF_HW_RESULT ast_hif_hw_power_ctrl(kal_bool bPowerOn);
AST_HIF_HW_RESULT ast_hif_hw_reg_eint(AST_HIF_HW_EINT_T* pEintParam);
AST_HIF_HW_RESULT ast_hif_hw_set_gpio(char value, char pin);
kal_bool ast_hif_hw_query_power_state(void);

#endif

#endif
