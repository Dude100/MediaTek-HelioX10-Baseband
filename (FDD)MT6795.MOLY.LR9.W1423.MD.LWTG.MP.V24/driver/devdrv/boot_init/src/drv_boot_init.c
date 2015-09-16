/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   drv_boot_init.c
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Boot_Init Related Functions
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/
#include "abm_init.h"
#include "arm7_init.h"
#include "bootrom_init.h"
#include "busmon_init.h"
#include "ca7_init.h"
#include "ccif_init.h"
#include "cldma_init.h"
#include "cr4pcmon_init.h"
#include "dbgsys_init.h"
#include "ehpi_master_init.h"
#include "ehpi_slave_init.h"
#include "gdma_init.h"
#include "gpio_init.h"
#include "gptm_init.h"
#include "i2c_init.h"
#include "ipsec_init.h"
#include "led_init.h"
#include "ltel2_init.h"
#include "mdcaif_init.h"
#include "mdcirq_init.h"
#include "msdc_init.h"
#include "nfi_init.h"
#include "nic_init.h"
#include "nli_init.h"
#include "pfc_init.h"
#include "rtc_init.h"
#include "sdio_init.h"
#include "spi_init.h"
#include "trace_init.h"
#include "u2_init.h"
#include "u3_init.h"
#include "uart_init.h"
#include "usim_init.h"

 /*************************************************************************
* FUNCTION
*  boot_init_clock
*
* DESCRIPTION
*  This function serves as a central place holder to call each IP's clock
*  init function
*
* RETURNS
*
*************************************************************************/
void boot_init_clock()
{
    /* IPs with both bus and non-bus clock */
    boot_init_msdc_clock();
    boot_init_nic_clock();
    boot_init_spi_clock();
    boot_init_u2_clock();
    boot_init_u3_clock();

    /* IPs with only non-bus clock */
    boot_init_arm7_clock();
    boot_init_ca7_clock();
    boot_init_dbgsys_clock();
    boot_init_trace_clock();

    /* IPs with only bus clock */
    boot_init_abm_clock();
    boot_init_bootrom_clock();
    boot_init_busmon_clock();
    boot_init_ccif_clock();
    boot_init_cldma_clock();
    boot_init_cr4pcmon_clock();
    boot_init_ehpi_master_clock();
    boot_init_ehpi_slave_clock();
    boot_init_gdma_clock();
    boot_init_gpio_clock();
    boot_init_gptm_clock();
    boot_init_i2c_clock();
    boot_init_ipsec_clock();
    boot_init_led_clock();
    boot_init_ltel2_clock();
    boot_init_mdcaif_clock();
    boot_init_mdcirq_clock();
    boot_init_nfi_clock();
    boot_init_nli_clock();
    boot_init_pfc_clock();
    boot_init_rtc_clock();
    boot_init_sdio_clock();
    boot_init_uart_clock();
    boot_init_usim_clock();
}
