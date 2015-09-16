/*!
 *  @file uartcore_task.c
 *  @author Ansel Liao <ansel.liao@mediatek.com>
 *  @version 1.0
 *  @section LICENSE
 *
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
 *  @section DESCRIPTION
 *  This file provides main functions of uartcore
 */

#include "kal_general_types.h"
#include "kal_public_api.h"
#include "syscomp_config.h"
#include "hmu.h"
#include "hmu_conf_data.h"

typedef enum{
	UART_EN_Q = 0,
	UART_DE_Q = 1,
	UART_EN_Q_LIGHT = 2,
	UART_DE_Q_ALL = 3,
} drv_uart_en_q_or_de_q;

extern void *uart_tgpd_head[3];
extern void *uart_rgpd_head[3];
extern void *uart_tgpd_tail[3];
extern void *uart_rgpd_tail[3];
extern kal_uint32 uart_open_event;
extern void uart_en_q_de_q_with_mutex(UART_PORT port, kal_bool tx_or_rx, kal_bool en_q_or_de_q, void *p_ior_head, void *p_ior_tail);

static void uart_core_task_main(task_entry_struct* task_entry_ptr)
{
	ilm_struct current_ilm;
	kal_uint32 rt_event, uart_event;
	kal_uint32 count = 0;

	kal_set_active_module_id(MOD_UARTCORE);
	kal_mem_set(&current_ilm, 0, sizeof(ilm_struct));

	while(1)
	{
		//dbg_print("=========>uartcore_task_main\r\n");

		// msg_receive_extq will block, therefore we poll if any message exist first
		while(msg_get_extq_messages() > 0)
		{
			if(msg_receive_extq(&current_ilm) != KAL_TRUE)
			{
				break;
			}

			switch (current_ilm.msg_id)
			{
				default:
					break;
			}

			destroy_ilm(&current_ilm);
		}
			// wait some open uart port first time;
		if(uart_open_event <= 0){
			uart_event = hmu_hifeg_wait(HIF_DRV_EG_UART_IND_EVENT);
		}
		if((HIF_DRV_EG_UART_IND_EVENT & uart_event) || uart_open_event>0){
		// Wait someone notify HMU to wake up HIF.
		rt_event = hmu_hifeg_wait(HIF_DRV_EG_HIF_TICK_EVENT_UART);
		if((HIF_DRV_EG_HIF_TICK_EVENT_UART & rt_event))
		{
			count++;
			if(0 == (count % 1) )
			{
				if(uart_tgpd_head[uart_port1] != uart_tgpd_tail[uart_port1])
					uart_en_q_de_q_with_mutex(uart_port1, UART_TX, UART_DE_Q, NULL, NULL);
			
				if(uart_rgpd_head[uart_port1] != uart_rgpd_tail[uart_port1])
					uart_en_q_de_q_with_mutex(uart_port1, UART_RX, UART_DE_Q, NULL, NULL);
#if defined(__FLAVOR_MULTI_MODE_ROUTER__) || defined(__FLAVOR_SINGLE_MODE_ROUTER__)
	//in Router product. SUART0 is AP  own, so it should not be init here.
#else
				if(uart_tgpd_head[uart_port2] != uart_tgpd_tail[uart_port2])
					uart_en_q_de_q_with_mutex(uart_port2, UART_TX, UART_DE_Q, NULL, NULL);
			
				if(uart_rgpd_head[uart_port2] != uart_rgpd_tail[uart_port2])
					uart_en_q_de_q_with_mutex(uart_port2, UART_RX, UART_DE_Q, NULL, NULL);
#endif
			}
		}
	}
}
}


static kal_bool uart_core_task_init(void)
{
	dbg_print("=========>uartcore_task_init\r\n");

	return KAL_TRUE;
}


static kal_bool uart_core_task_reset(void)
{
	dbg_print("=========>uartcore_task_reset\r\n");

	// Do task's reset here.
	// Notice that: shouldn't execute modules reset handler since
	// stack_task_reset() will do.
	return KAL_TRUE;
}


static kal_bool uart_core_task_end(void)
{
	dbg_print("=========>uartcore_task_end\r\n");

	// Do task's termination here.
	// Notice that: shouldn't execute modules reset handler since
	// stack_task_end() will do.
	return KAL_TRUE;
}


kal_bool uart_core_create(comptask_handler_struct **handle)
{
	static const comptask_handler_struct uart_core_handler_info =
	{
		uart_core_task_main,		/* task entry function */
		uart_core_task_init,		/* task initialization function */
//		NULL,				/* task configuration function */
		uart_core_task_reset,		/* task reset handler */
//		uart_core_task_end		/* task termination handler */
	};
	
    uart_open_event = 0;
	dbg_print("=========>uartcore_create\r\n");

	*handle = (comptask_handler_struct *) &uart_core_handler_info;

	return KAL_TRUE;
}
