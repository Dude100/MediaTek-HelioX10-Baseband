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
 *   drv_pcmon.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * Barry Hong
 *   
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * [PCMon] Add s/w version check for ROME
 *
 * removed!
 * removed!
 * [PCMon] Enable PCMon by default.
 ****************************************************************************/


#include "drv_comm.h"
#include "irqid.h"

#include "pcmon_reg.h"
#include "drv_pcmon.h"
#include "intrCtrl.h"

#include "dcl.h"
#include "drv_hisr.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "init.h"

#if !defined(DRV_PCM_OFF)

/*****************************************************************************
 *						 SYMBOL Definition                                   *
 *****************************************************************************/
#define PCM_BUF_SIZE_UNIT	0xFFF0
#define PCM_BUF_SIZE_2UNIT (2 * 0xFFF0)
#define HDMA_BASIC_MODE_NO_CS	0x00000200
#define HDMA_RX_CFG				0xC00080A0

#define PCMON_MODE2_DEFAULT (PCMON_MOD2 | PCMON_DIFF(0) | PCMON_ETM_ENABLE)

/*****************************************************************************
 *						 Global/External Variable                            *
 *****************************************************************************/
static pfCallback pfHPCMCallback[1U];
static kal_uint32   irq_status;
static kal_uint32   buf_end_addr, buf_start_addr;
volatile static pcm_buf_type _pcm_buf_type = 0;
volatile static kal_uint32 _pcm_buf_size = 0;
volatile static kal_uint32 _pcm_buf_half_size = 0;
volatile static kal_uint32 _pcm_buf_addr = 0;
volatile static kal_uint32 _pcm_isr_cnt = 0;

const kal_uint32 g_PCMON_CTRL_REG = PCMON_CTRL_0;
const kal_uint32 g_PCMON_MODE2_VALUE = PCMON_MODE2_DEFAULT;

/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
//function declaration.
void drv_pcm_hisr(void);



/*****************************************************************************
 *						 LISR/HISR/Callback Functions                        *
 *****************************************************************************/
static void drv_default_callback(void)
{
	kal_uint32 ASSERT_IN_PCM_DEFAULT_CALLBACK = 0;
	ASSERT(ASSERT_IN_PCM_DEFAULT_CALLBACK); 
	return;
}

/*****************************************************************************
 *						 Basic Driver Implementation						 *
 *****************************************************************************/


/*-----------------------------------------------------------------------*
* FUNCTION                                                            
*	drv_pcm_lisr
*
* DESCRIPTION                                                           
*   	PCM interrupt handler (LISR)
*
* CALLS  
*	It is called when PCM interrupt is coming
*
* PARAMETERS
*	None
*	
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
void drv_pcm_lisr(kal_uint32 v)
{
	ASSERT(PCMON_HDMA_INTR_ID == v);
	IRQMask(PCMON_HDMA_INTR_ID);
	drv_active_hisr(DRV_PCMON_HISR_ID);
}



/*-----------------------------------------------------------------------

* FUNCTION
*  drv_pcm_initialize
*
* DESCRIPTION
*  This function is to initialize SW PCMON module. 
*
* PARAMETERS
*	none
*
* RETURNS
*  none
*
*------------------------------------------------------------------------*/
DCL_STATUS drv_pcm_initialize(void)
{
	/* PCMON hardware reset */
	drv_pcm_reset();
	IRQ_Register_LISR(PCMON_HDMA_INTR_ID, drv_pcm_lisr, "PCMCB");

	/* Register the PCMON CB HISR */
	DRV_Register_HISR(DRV_PCMON_HISR_ID, drv_pcm_hisr);

	IRQUnmask(PCMON_HDMA_INTR_ID);

	_pcm_buf_addr = 0;
	
	return STATUS_OK;
}




/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_reset
*
* DESCRIPTION
*  This function is to reset the hardware PCMON module.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_reset(void)
{
//	DRV_WriteReg32(0xbf420024, DRV_Reg32(0xbf420024) | (1 << 26));       //set PCM reset bit map
//	DRV_WriteReg32(0xbf420020, 0x25930000);                              //trigger cmd
//	DRV_WriteReg32(0xbf420024, DRV_Reg32(0xbf420024) & ~(1 << 26));      //clear PCM reset bit map
//	DRV_WriteReg32(0xbf420020, 0x25930000);                              //trigger cmd
	
	//clear PCM FIFO wrap around error status
	IRQSensitivity(PCMON_HDMA_INTR_ID, LEVEL_SENSITIVE);
	IRQClearInt(PCMON_HDMA_INTR_ID);
	
	pfHPCMCallback[0] = drv_default_callback;
}


void drv_pcm_init_hdma(kal_uint32 buf_addr)
{
	DRV_WriteReg32(GDMA_HDCSR4, (DRV_Reg32(GDMA_HDCSR4) & 0xFFFF0000) | HDMA_BASIC_MODE_NO_CS);
	DRV_WriteReg32(GDMA_HDCTRR8, HDMA_RX_CFG);
	DRV_WriteReg32(GDMA_HPRGA0R8, buf_addr);							//buffer 0 addr
	DRV_WriteReg32(GDMA_HPRGA1R8, (buf_addr+PCM_BUF_SIZE_UNIT));	  	//buffer 1 addr
	DRV_WriteReg32(GDMA_HDC0R8, (PCM_BUF_SIZE_UNIT<<16)); //b0 size
	DRV_WriteReg32(GDMA_HDC1R8,    (PCM_BUF_SIZE_UNIT<<16)); //b1 size
	DRV_WriteReg32(GDMA_GIMRK4, (DRV_Reg32(GDMA_GIMRK4) & ~HDMA_DONE3_INTM)); //enable interrupt
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_set_config
*
* DESCRIPTION
*  This function is to configure the pcmon .
*
* PARAMETERS
*	pcm_cfg: PCMON config parameters
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
DCL_STATUS drv_pcm_set_config(pcm_config *pcm_cfg)
{
	ASSERT(( pcm_cfg != NULL) && (((DRV_Reg32(PCMON_CTRL_0) & PCMON_ETM_ENABLE) == 0) && ((DRV_Reg32(GDMA_HDSR) & (HDMA_STAT0_8x | HDMA_STAT1_8x)) == 0)));
	switch	(pcm_cfg->pcm_mode)
	{
		case 0:
			if (pcm_cfg == NULL) 
			{
				return STATUS_INVALID_CONFIGURATION;  //parameter incorrect
			}
			else
			{
				//set mode 1 and sample rate
				//ctrl_reg = (PCMON_MOD1 || (pcm_cfg->sample_rate << 4));      
				DRV_WriteReg32(PCMON_CTRL_0, (PCMON_MOD1 | (pcm_cfg->sample_rate << 4)));

				_pcm_buf_type = pcm_cfg->buf_mode;
				_pcm_buf_half_size = _pcm_buf_size / 2;
				buf_end_addr = (pcm_cfg->buf_addr + PCM_BUF_SIZE_UNIT);
				buf_start_addr = pcm_cfg->buf_addr;

				//set HDMA basic mode/transfer size/burst rate/buffer addr and size
				drv_pcm_init_hdma(pcm_cfg->buf_addr);
			}
			break;

		case 1:
			if (pcm_cfg->pc_diff == 0) 
			{
				return STATUS_INVALID_CONFIGURATION;  //parameter incorrect
			}
			else
			{
				DRV_WriteReg32(PCMON_CTRL_0, (PCMON_MOD2 | (pcm_cfg->pc_diff << 8)));
			}
			break;

		case 2:
			if (pcm_cfg == NULL) 
			{
				return STATUS_INVALID_CONFIGURATION;  //parameter incorrect
			}
			else
			{
				//set mode 3 and sample rate
				DRV_WriteReg32(PCMON_CTRL_0, (PCMON_MOD3 | (pcm_cfg->sample_rate << 4) | (pcm_cfg->pc_diff << 8) | (pcm_cfg->pc_pair << 16)));

				_pcm_buf_type = pcm_cfg->buf_mode;

				//set HDMA basic mode/transfer size/burst rate/buffer addr and size
				drv_pcm_init_hdma(pcm_cfg->buf_addr);
			}
			break;

		default:
			break;

	}
	return STATUS_OK;
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_get_config
*
* DESCRIPTION
*  This function is to get configure info of pcmon .
*
* PARAMETERS
*	pcm_cfg: PCMON config parameters
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_get_config(pcm_config *pcm_cfg)
{
	kal_uint32 ctrl_reg=0;
	//ASSERT( *pcm_cfg != NULL );

	ctrl_reg = DRV_Reg32(PCMON_CTRL_0);
	pcm_cfg->pcm_mode = (kal_uint8)(ctrl_reg & 0x00000007);
	pcm_cfg->buf_mode = _pcm_buf_type;
	pcm_cfg->sample_rate = (kal_uint8)((ctrl_reg & 0x00000070) >> 4);
	pcm_cfg->pc_pair = (kal_uint8)((ctrl_reg & 0x00070000) >> 16);
	pcm_cfg->pc_diff = ((ctrl_reg & 0x00007F00) >> 8);
	pcm_cfg->buf_addr = _pcm_buf_addr;
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_start_capture
*
* DESCRIPTION
*  This function is to start the pcm capture.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_start_capture(void)
{
	ASSERT(((DRV_Reg32(PCMON_CTRL_0) & PCMON_ETM_ENABLE) == 0) && ((DRV_Reg32(GDMA_HDSR) & (HDMA_STAT0_8x | HDMA_STAT1_8x)) == 0)); //ETM BUS already enable

	//enable HDMA
	DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0
	DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1

	//clear PCM FIFO wrap around error status
	IRQClearInt(PCMON_INTR_ID);

	//enable ETM BUS and re-enable PCM if stopped by BUSMON
	DRV_WriteReg32(PCMON_CTRL_0, (DRV_Reg32(PCMON_CTRL_0) & 0xFFEFFFFF) | PCMON_ETM_ENABLE);  //enable ETM BUS
	DRV_WriteReg32(PCMON_CTRL_1, (DRV_Reg32(PCMON_CTRL_1) & 0x7FFFFFFE) | PCMON_BUS_STOP_RESTART);  //reenable PCM

}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_stop_capture  
*
* DESCRIPTION
*  This function is to stop the PCMON.
*
* PARAMETERS
*	None
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_stop_capture(void)
{
	//disable ETM BUS and triger BUSMON Stop
	DRV_WriteReg32(PCMON_CTRL_0, (DRV_Reg32(PCMON_CTRL_0) & 0xFFEFFFFF) );  //disable ETM BUS
	DRV_WriteReg32(PCMON_CTRL_1, (DRV_Reg32(PCMON_CTRL_1) | PCMON_BUS_MON_STOP));  //trigger BUSMON Stop
	
	//stop HDMA
	DRV_WriteReg32(GDMA_HDCTRR8,(DRV_Reg32(GDMA_HDCTRR8) & 0xFFFFFFFB)); //Stop HDMA8

	IRQMask(PCMON_HDMA_INTR_ID);
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_get_cur_ptr  
*
* DESCRIPTION
*  This function is to get the current pointer after stop capture.
*
* PARAMETERS
*	None
*
* RETURNS
*	Cnt: currnt count
*
*------------------------------------------------------------------------*/
kal_uint32 drv_pcm_get_cur_ptr(void)
{
	kal_uint32 reg;
	reg = DRV_Reg32(GDMA_HDCCR8);
	if ((reg & 0xFFFF) == 0xFFF0)	//current counter is in buf1
	{
		return (DRV_Reg32(GDMA_HPRGA0R8) + ((reg & 0xFFFF0000) >> 16) + (reg & 0xFFFF) - 1);
	}
	else //current counter is in buf0 (include warp around case)
	{
		return (DRV_Reg32(GDMA_HPRGA0R8) + (reg & 0xFFFF) - 1);
	}
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_get_pc_pair  
*
* DESCRIPTION
*  This function is to get difference PC pair
*
* PARAMETERS
*	num: Pair number
*	PC0: PC 0
*	PC1: PC 1
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1)
{
	ASSERT((num <= 15));

	*pc0 = DRV_Reg32(PCMON_PC_(num));
	*pc1 = DRV_Reg32(PCMON_PC_(num+1));
}

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_get_cid_pair  
*
* DESCRIPTION
*  This function is to get CID pair correspond to PC pair num
*
* PARAMETERS
*	num: Pair number
*	cid0: CID 0
*	cid1: CID 1
*
* RETURNS
*	None
*
*------------------------------------------------------------------------*/
void drv_pcm_get_cid_pair(kal_uint8 num, kal_uint32 *cid0, kal_uint32 *cid1)
{
	ASSERT((num <= 15));

	*cid0 = DRV_Reg32(PCMON_CID_(num));
	*cid1 = DRV_Reg32(PCMON_CID_(num+1));
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_check_buf_wrap  
*
* DESCRIPTION
*  This function is to get PCMON FIFO wrap around status
*
* PARAMETERS
*	None
*
* RETURNS
*	0:	No FIFO wrap around happen
*	1:  FIFO wrap around
*
*------------------------------------------------------------------------*/
kal_uint8 drv_pcm_check_buf_wrap(void)
{
	if (DRV_Reg32(MDCIRQ_ISAR3100) & (0x1 << 30))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}


/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_pcm_register_callback
*
* DESCRIPTION
*  This function is to set callback function for the HW PCM module.
*
* PARAMETERS
*  callback - the callback function when PCMON buffer is half/full filled
*
* RETURNS
*  STATUS_OK - successfully register the callback function.
*
*------------------------------------------------------------------------*/
DCL_STATUS drv_pcm_register_callback(pfCallback callback)
{
	ASSERT( callback );
	pfHPCMCallback[0] = callback;
	return STATUS_OK;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*	drv_pcm_hisr
*
* DESCRIPTION                                                           
*   	PCM Callback HISR
*
* CALLS
*
* PARAMETERS
*	void
*
* RETURNS
*	None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/

void drv_pcm_hisr(void)
{
	kal_uint32 savedMask;
	kal_uint32 hdma8_status, buf0_addr, buf1_addr;

	savedMask = SaveAndSetIRQMask();
	irq_status = DRV_Reg32(GDMA_GISAR4);
	DRV_WriteReg32(GDMA_GISAR4, irq_status);
	RestoreIRQMask(savedMask);

	IRQClearInt(PCMON_HDMA_INTR_ID);
	IRQUnmask(PCMON_HDMA_INTR_ID);

	if (irq_status & HDMA_DONE_8x)
	{
		hdma8_status = DRV_Reg32(GDMA_HDSR);	
		if (_pcm_buf_type == PCM_BUF_TYPE_A)
		{


			
			if ((hdma8_status & HDMA_STAT1_8x) && (hdma8_status & HDMA_STAT0_8x)) //all buffer complete
			{
			}
			else if ((hdma8_status & HDMA_STAT1_8x) && !(hdma8_status & HDMA_STAT0_8x)) //buffer0 complete and buffer1 is working
			{
				buf0_addr = (kal_uint32)DRV_Reg32(GDMA_HPRGA0R8);
				if ((buf0_addr + PCM_BUF_SIZE_UNIT) >= (buf_start_addr + _pcm_buf_half_size)) //half full
				{
					if ((buf0_addr + PCM_BUF_SIZE_2UNIT) >= buf_end_addr) //full
					{
						DRV_WriteReg32(GDMA_HPRGA0R8, buf_start_addr);
						DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0								
					}
					else
					{
						DRV_WriteReg32(GDMA_HPRGA0R8, buf0_addr + (2 * PCM_BUF_SIZE_UNIT));                           //set next buffer address
						DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0							
					}
					pfHPCMCallback[0]();				
				}
				else
				{
					DRV_WriteReg32(GDMA_HPRGA0R8, buf0_addr + (2 * PCM_BUF_SIZE_UNIT));                           //set next buffer address
					DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0							
				}
			}
			else if (!(hdma8_status & HDMA_STAT1_8x) && (hdma8_status & HDMA_STAT0_8x)) //buffer1 complete and buffer0 is working
			{
				buf1_addr = (kal_uint32)DRV_Reg32(GDMA_HPRGA1R8);
				if ((buf1_addr + PCM_BUF_SIZE_UNIT) >= (buf_start_addr + _pcm_buf_half_size)) //half full
				{
					if ((buf1_addr + PCM_BUF_SIZE_2UNIT) >= buf_end_addr) //full
					{
						DRV_WriteReg32(GDMA_HPRGA1R8, buf_start_addr);
						DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1
					}
					else
					{
						DRV_WriteReg32(GDMA_HPRGA1R8, buf1_addr + (2 * PCM_BUF_SIZE_UNIT));                           //set next buffer address
						DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1
					}
					pfHPCMCallback[0]();				
				}
				else
				{
					DRV_WriteReg32(GDMA_HPRGA1R8, buf1_addr + (2 * PCM_BUF_SIZE_UNIT));                           //set next buffer address
					DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1
				}
			}
			else
			{
			}
		}
		else //buf type B
		{
			_pcm_buf_addr++ ;		
			if ((hdma8_status & HDMA_STAT1_8x) && (hdma8_status & HDMA_STAT0_8x))
			{
			}
			else if ((hdma8_status & HDMA_STAT1_8x) && !(hdma8_status & HDMA_STAT0_8x)) //buff1 active, restart buff0
			{
//				buf0_addr = (kal_uint32)DRV_Reg32(GDMA_HPRGA0R8);
//				if (buf0_addr + PCM_BUF_SIZE_2UNIT >= buf_end_addr)
//				{
//					pfHPCMCallback[0]();
//				}
//				else
//				{
//					DRV_WriteReg32(GDMA_HPRGA0R8, buf0_addr + (2 * PCM_BUF_SIZE_UNIT)); 						  //set next buffer address
//					DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0							
//				}
				DRV_WriteReg32(GDMA_HDC0R8,(DRV_Reg32(GDMA_HDC0R8) & 0xFFFFFFFE) | GDMA_HDMA_START_8x); //start HDMA Buf0
				
			}
			else if (!(hdma8_status & HDMA_STAT1_8x) && (hdma8_status & HDMA_STAT0_8x)) //buff0 active, restart buff1
			{
//				buf1_addr = (kal_uint32)DRV_Reg32(GDMA_HPRGA1R8);
//				if ((buf1_addr + PCM_BUF_SIZE_2UNIT) >= buf_end_addr) //full
//				{
//					pfHPCMCallback[0]();
//				}
//				else
//				{
//					DRV_WriteReg32(GDMA_HPRGA1R8, buf1_addr + (2 * PCM_BUF_SIZE_UNIT)); 						  //set next buffer address
//					DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1
//				}
				DRV_WriteReg32(GDMA_HDC1R8,(DRV_Reg32(GDMA_HDC1R8) & 0xFFFFFFFE) | GDMA_HDMA_START1_8X); //start HDMA Buf1
			}
		}
	}
}

INLINE void restartPCMon(void)
{
    kal_uint32 to_enable = 0;

#if defined(MT6290)
    to_enable = 1;
#elif defined(MT6595)
    if (INT_SW_SecVersion() == SW_SEC_0)
        to_enable = 1;
#endif

    if (to_enable) {
        DRV_Reg32(PCMON_CTRL_1) = PCMON_BUS_MON_STOP;
        DRV_Reg32(PCMON_CTRL_1) = 0;
        DRV_Reg32(PCMON_CTRL_1) = PCMON_BUS_STOP_RESTART;
        DRV_Reg32(PCMON_CTRL_0) = PCMON_MODE2_DEFAULT;
    }
}

#else /*!defined(DRV_PCM_OFF)*/

#endif /*!defined(DRV_PCM_OFF)*/

//void startSystemTimer(void){
//	IRQUnmask(MDGPT_INTR_ID(DRV_GPT_SYSTEM_TIMER));
//	drv_pcm_start_timer(DRV_GPT_SYSTEM_TIMER);
//}

