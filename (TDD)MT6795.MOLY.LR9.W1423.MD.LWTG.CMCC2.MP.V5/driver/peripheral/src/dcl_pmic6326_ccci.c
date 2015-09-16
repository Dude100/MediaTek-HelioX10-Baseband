


#include 	"kal_public_api.h"
#include "kal_public_defs.h" //MSBB change #include 	"stack_msgs.h"
#include "stack_ltlcom.h" //MSBB change #include 	"app_ltlcom.h"       /* Task message communiction */
#include 	"drv_comm.h"
#include    "drvsignals.h"
#include 	"reg_base.h"
#include 	"intrCtrl.h"
#include	   "stack_ltlcom.h"       /*msg_send_ext_queue.....definitions*/
#include "kal_public_defs.h" //MSBB change #include	   "stack_config.h"        /*MOD_UART1_HISR,MOD_UART2_HISR*/
#include    "eint.h"
#include    "bmt.h"
#include    "drvsignals.h"
#include    "custom_hw_default.h"
#include "gpt_sw.h"

#include "kal_trace.h"
#include "dcl.h"
#include "dcl_pmu_sw.h"

// Define to enable UT:
// The UT program will cycle lock -> disable VSIM -> Set and enable VSIM -> Unlock
// at each GPT callback
//#define DEBUG_PMIC_CCCI_UT

// Define to disable share memory polling
//#define DEBUG_PMIC_CCCI_SKIP_SHARE_MEMORY_POLLING

// Define to lease the check criteria
#define DEBUG_PMIC_CCCI_LEASE_SHARE_MEMORY_POLLING_CHECK_CRITERIA

#if ( (defined(PMIC_6326_CCCI_REG_API))  )
#include "ccci.h"

pmic6326_share_mem_info *pPMIC6326ShareMemInfo;
kal_uint16 LastPMIC6326ExecuteTime = 0;
kal_uint8 LastPMIC6326OP;

#if defined(DEBUG_PMIC_CCCI_UT)
void pmic6326_ccci_ut_main(void);
void pmic6326_ccci_ut_timer_cb(void *parameter);
#endif // #if defined(DEBUG_PMIC_CCCI_UT)


void pmic6326_ccci_callback(CCCI_BUFF_T *buff)
{
	//pmic6326_ccci_msg *p_recv_msg;
	//pmic6326_ccci_msg_info *p_recv_msg_info;
	//buff->data[0];	// Magic number for mailbox
	ASSERT(buff->channel == CCCI_PMIC_ACK_CHANNEL);

	//p_recv_msg = (pmic6326_ccci_msg *)&(buff->data[1]);
    //p_recv_msg_info = (pmic6326_ccci_msg_info *)&(buff->reserved);

}

extern kal_uint32 L1I_GetTimeStamp(void);
static kal_uint32 pmic6326_ccci_curr_frame_tick;
static kal_uint32 pmic6326_ccci_prev_frame_tick;

void pmic6326_ccci_wait_ACK(pmic6326_ccci_op OP)
{
	volatile pmic6326_ccci_msg *p_recv_msg;
	volatile pmic6326_ccci_msg_info *p_recv_msg_info;

#if defined(DEBUG_PMIC_CCCI_SKIP_SHARE_MEMORY_POLLING)
	return;
#endif // DEBUG_PMIC_CCCI_SKIP_SHARE_MEMORY_POLLING

//	if ( (if_kal_hisr()) || (if_kal_lisr()) )
//	{
//		// We are in HISR or LISR
//	}
//	else
//	{
//
//	}
	// Polling share memory
	// p_recv_msg = &(pPMIC6326ShareMemInfo->ccci_msg);
	// p_recv_msg_info = &(pPMIC6326ShareMemInfo->ccci_msg_info);

	// Log current timestamp
	pmic6326_ccci_prev_frame_tick = L1I_GetTimeStamp();

	while (1)
	{
		// Polling share memory
		p_recv_msg = &(pPMIC6326ShareMemInfo->ccci_msg);
		p_recv_msg_info = &(pPMIC6326ShareMemInfo->ccci_msg_info);
#if defined(DEBUG_PMIC_CCCI_LEASE_SHARE_MEMORY_POLLING_CHECK_CRITERIA)
		if ( (p_recv_msg->pmic6326_op == OP) 
			)
#else // #if defined(DEBUG_PMIC_CCCI_LEASE_SHARE_MEMORY_POLLING_CHECK_CRITERIA)
		if ( (p_recv_msg->pmic6326_op == OP) &&
			(p_recv_msg->pmic6326_type == PMIC6326_RES)
			)
#endif // #if defined(DEBUG_PMIC_CCCI_LEASE_SHARE_MEMORY_POLLING_CHECK_CRITERIA)
		{
			// Get response
			LastPMIC6326ExecuteTime = p_recv_msg_info->pmic6326_exec_time;
			LastPMIC6326OP = p_recv_msg->pmic6326_op;
			p_recv_msg_info->pmic6326_exec_time = 0;
			p_recv_msg->pmic6326_op = PMIC6326_MAX;
			break;
		}
		else
		{
			// Should we sleep if we are in task context?
		}
		
		// Calculate the period we polling, if NOT reasonable, just show warning message
		pmic6326_ccci_curr_frame_tick = L1I_GetTimeStamp();
		if (pmic6326_ccci_curr_frame_tick >= pmic6326_ccci_prev_frame_tick)
		{
			if ( (pmic6326_ccci_curr_frame_tick - pmic6326_ccci_prev_frame_tick) > MAX_PMIC6326_CCCI_POLLING_PERIOD)
			{
				// Show warning message
				kal_prompt_trace(MOD_BMT,"PMIC6326 CCCI Interface get ACK from remote side timeout");
				break;
			}
		}
		else
		{
			kal_uint32 tmp;
			tmp = (0xFFFFFFFF - pmic6326_ccci_prev_frame_tick + pmic6326_ccci_curr_frame_tick +1);
			if (tmp > MAX_PMIC6326_CCCI_POLLING_PERIOD)
			{
				// Show warning message
				kal_prompt_trace(MOD_BMT,"PMIC6326 CCCI Interface get ACK from remote side timeout");
				break;
			}
		}
	}
}

void pmic6326_ccci_init(void)
{
#ifndef BY_PASS_PMIC_CCCI_DRIVER

	kal_uint32 addr;
	kal_uint32 size = 0;
	// 1. Get share memory info
	addr = ccci_query_sharemem_addr(CCCI_PMIC_CHANNEL, &size);
	
	// Make sure share memory size is larger than the share memory info structure
	ASSERT(size >= sizeof(pmic6326_share_mem_info));
	
	pPMIC6326ShareMemInfo = (pmic6326_share_mem_info *)addr;

	//ccci_init(CCCI_PMIC_CHANNEL, pmic6326_ccci_callback);
	ccci_init(CCCI_PMIC_ACK_CHANNEL, pmic6326_ccci_callback);

#if defined(DEBUG_PMIC_CCCI_UT)
	pmic6326_ccci_ut_main();
#endif // #if defined(DEBUG_PMIC_CCCI_UT)

#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}

// Send Lock/Unlock command to remote side
void pmic6326_ccci_lock(kal_bool lock){
#ifndef BY_PASS_PMIC_CCCI_DRIVER
	pmic6326_ccci_msg send_msg;
	
	send_msg.pmic6326_type = (kal_uint8)PMIC6326_REQ;
	send_msg.pmic6326_param1 = 0;
	send_msg.pmic6326_param2 = 0;
	if (lock == KAL_TRUE)
	{
		// Lock remote side
		send_msg.pmic6326_op = (kal_uint8)PMIC6236_LOCK;
	}
	else
	{
		// Unlock remote side
		send_msg.pmic6326_op = (kal_uint8)PMIC6326_UNLOCK;
	}
	ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&send_msg), 0);
	
	pmic6326_ccci_wait_ACK((pmic6326_ccci_op)send_msg.pmic6326_op);
#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}

// Select SIM LDO voltage and turn on SIM LDO
void dcl_pmic6326_ccci_vsim_sel_and_enable(kal_uint16 sel)
{
#ifndef BY_PASS_PMIC_CCCI_DRIVER
	pmic6326_ccci_msg send_msg;
	
	send_msg.pmic6326_op = (kal_uint8)PMIC6326_VSIM_SET_AND_ENABLE;	
	send_msg.pmic6326_type = (kal_uint8)PMIC6326_REQ;
	send_msg.pmic6326_param1 = (kal_uint8)sel;
	send_msg.pmic6326_param2 = 0;

	ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&send_msg), 0);
	
	pmic6326_ccci_wait_ACK((pmic6326_ccci_op)send_msg.pmic6326_op);
#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}

// Turn on/off SIM LDO voltage
void dcl_pmic6326_ccci_vsim_enable(kal_bool enable)
{
#ifndef BY_PASS_PMIC_CCCI_DRIVER
	pmic6326_ccci_msg send_msg;
	
	send_msg.pmic6326_op = (kal_uint8)PMIC6326_VSIM_ENABLE;	
	send_msg.pmic6326_type = (kal_uint8)PMIC6326_REQ;
	
	send_msg.pmic6326_param2 = 0;
	if (enable == KAL_FALSE)
	{
		// Turn off SIM LDO
		send_msg.pmic6326_param1 = 0;
	}
	else
	{
		// Turn on SIM LDO
		send_msg.pmic6326_param1 = 1;
	}

	ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&send_msg), 0);

	pmic6326_ccci_wait_ACK((pmic6326_ccci_op)send_msg.pmic6326_op);
#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}

// Select SIM2 LDO voltage and turn on SIM2 LDO
void dcl_pmic6326_ccci_vsim2_sel_and_enable(kal_uint16 sel)
{
#ifndef BY_PASS_PMIC_CCCI_DRIVER
	pmic6326_ccci_msg send_msg;
	
	send_msg.pmic6326_op = (kal_uint8)PMIC6326_VSIM2_SET_AND_ENABLE;	
	send_msg.pmic6326_type = (kal_uint8)PMIC6326_REQ;
	send_msg.pmic6326_param1 = (kal_uint8)sel;
	send_msg.pmic6326_param2 = 0;

	ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&send_msg), 0);
	
	pmic6326_ccci_wait_ACK((pmic6326_ccci_op)send_msg.pmic6326_op);
#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}

// Turn on/off SIM2 LDO voltage
void dcl_pmic6326_ccci_vsim2_enable(kal_bool enable)
{
#ifndef BY_PASS_PMIC_CCCI_DRIVER
	pmic6326_ccci_msg send_msg;
	
	send_msg.pmic6326_op = (kal_uint8)PMIC6326_VSIM2_ENABLE;	
	send_msg.pmic6326_type = (kal_uint8)PMIC6326_REQ;
	
	send_msg.pmic6326_param2 = 0;
	if (enable == KAL_FALSE)
	{
		// Turn off SIM LDO
		send_msg.pmic6326_param1 = 0;
	}
	else
	{
		// Turn on SIM LDO
		send_msg.pmic6326_param1 = 1;
	}

	ccci_mailbox_write_with_reserved(CCCI_PMIC_CHANNEL, *((kal_uint32 *)&send_msg), 0);

	pmic6326_ccci_wait_ACK((pmic6326_ccci_op)send_msg.pmic6326_op);
#endif // #ifndef BY_PASS_PMIC_CCCI_DRIVER
}



DCL_UINT32 vsim_vosel[]=
{
	PMU_VOLT_01_300000_V, PMU_VOLT_01_500000_V, PMU_VOLT_01_800000_V, PMU_VOLT_02_500000_V,
	PMU_VOLT_02_800000_V, PMU_VOLT_03_000000_V, PMU_VOLT_03_300000_V, PMU_VOLT_01_200000_V
};


PMU_PARAMETER_TABLE_ENTRY pmu_parameter_table[]=
{
	//BUCK group
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		},
	{ENC(LDO_BUCK_SET_VOLTAGE,VSIM2),		vsim_vosel,		NULL,				GETARRNUM(vsim_vosel)		}
};


extern PMU_CONTROL_HANDLER pmu_control_handler;
DCL_UINT16 pmu_parameter_size=0;

DCL_STATUS PMIC6326_ccci_control_handler(DCL_HANDLE handle,DCL_CTRL_CMD cmd,DCL_CTRL_DATA_T *data)
{
	DCL_UINT16	regVal;
	DCL_UINT32	val;

	switch(cmd)
	{
		case LDO_BUCK_SET_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetEn);
			switch(pLdoBuckCtrl->mod)
			{
				case VSIM:
				{
					dcl_pmic6326_ccci_vsim_enable((kal_bool)pLdoBuckCtrl->enable);
				}
				break;	
				case VSIM2:
				{
					dcl_pmic6326_ccci_vsim2_enable((kal_bool)pLdoBuckCtrl->enable);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
				break;					
			}			
		}
		break;	
		case LDO_BUCK_SET_VOLTAGE_EN:
		{
			PMU_CTRL_LDO_BUCK_SET_VOLTAGE_EN *pLdoBuckCtrl=&(data->rPMULdoBuckSetVoltageEn);
			regVal=PMU_Parameter_to_Value(ENC(cmd,pLdoBuckCtrl->mod),pLdoBuckCtrl->voltage);
			switch(pLdoBuckCtrl->mod)
			{
				case VSIM:
				{
					dcl_pmic6326_ccci_vsim_sel_and_enable(regVal);
				}
				break;	
				case VSIM2:
				{
					dcl_pmic6326_ccci_vsim2_sel_and_enable(regVal);
				}
				break;					
				default:				
				return STATUS_UNSUPPORTED;
				break;					
			}				
		}
		break;
		default:				
		return STATUS_UNSUPPORTED;
		break;
	}
}

void dcl_pmic6326_ccci_init(void)
{
	pmu_control_handler=PMIC6326_ccci_control_handler;
	pmu_parameter_size=GETARRNUM(pmu_parameter_table);

	pmic6326_ccci_init();

}


#if defined(DEBUG_PMIC_CCCI_UT)
kal_uint8 pmic6236_ccci_ut_gpt_handle;
kal_uint32 pmic6236_ccci_ut_count;
void pmic6326_ccci_ut_main(void)
{
	
	GPTI_GetHandle(&pmic6236_ccci_ut_gpt_handle);
	GPTI_StartItem(pmic6236_ccci_ut_gpt_handle,
				1000,
				pmic6326_ccci_ut_timer_cb,
				NULL);
}

void pmic6326_ccci_ut_timer_cb(void *parameter)
{
	if (pmic6236_ccci_ut_count == 0)
	{
		// Lock
		pmic6326_ccci_lock(KAL_TRUE);
	}
	else if (pmic6236_ccci_ut_count == 1)
	{
		// Turn off VSIM
		pmic6326_ccci_vsim_enable(KAL_FALSE);
	}
	else if (pmic6236_ccci_ut_count == 2)
	{
		// Set VSIM to 3.3V and turn on VSIM
		pmic6326_ccci_vsim_sel_and_enable(VSIM_3_3V);
	}
	else if (pmic6236_ccci_ut_count == 3)
	{
		// Unlock
		pmic6326_ccci_lock(KAL_FALSE);
	}
	pmic6236_ccci_ut_count++;
	if (pmic6236_ccci_ut_count == 4)
	{
		pmic6236_ccci_ut_count = 0;
	}
	GPTI_StartItem(pmic6236_ccci_ut_gpt_handle,
				100,
				pmic6326_ccci_ut_timer_cb,
				NULL);

}
#endif // #if defined(DEBUG_PMIC_CCCI_UT)


#endif // #if ( (defined(PMIC_6326_CCCI_REG_API))  )


