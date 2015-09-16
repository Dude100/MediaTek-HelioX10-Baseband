#ifndef __DRV_PCM_H__
#define __DRV_PCM_H__

#include "dcl.h"


/*****************************************************************************
 *  					 Symbol/Type Definition 	                         *
 *****************************************************************************/
typedef enum
{
	PCM_MOD1=0,
	PCM_MOD2,
	PCM_MOD3,
} pcm_mode_sel;

typedef enum
{
	PCM_BUF_TYPE_A=0, 
	PCM_BUF_TYPE_B,
} pcm_buf_type;

typedef enum
{
	PCM_SR_2_NS=0,
	PCM_SR_8_NS,
	PCM_SR_0P1_MS,
	PCM_SR_0P5_MS,
	PCM_SR_1_MS,
	PCM_SR_8P4_MS,
	PCM_SR_33_MS,
	PCM_SR_134_MS,
} pc_sr_sel;


//  real sample rate = MCU_CK/(2^N)
//  pcm_config.sample_rate  0  1  2  3  4  5  6  7
//            N            10 12 16 18 19 22 24 26
//MCU_CK = 50MHz (FPGA) / 500MHz(ASIC)

typedef struct pcm_config_t{
	pcm_mode_sel	pcm_mode;
	pcm_buf_type	buf_mode;
	kal_uint8	sample_rate;
	kal_uint8	pc_pair;
	kal_uint32	pc_diff;
	kal_uint32	buf_addr;
} pcm_config;



/*******************************************************************************
 * PFN_DCL_CALLBACK
 *******************************************************************************/
typedef void     (*pfCallback)(void);


/*****************************************************************************
 *						 function declaration                                *
 *****************************************************************************/
void drv_pcm_reset(void);
DCL_STATUS drv_pcm_initialize(void);
DCL_STATUS drv_pcm_set_config(pcm_config *pcm_cfg);  //please reserve 2*0xFFF0 bytes dram area and set the start address
void drv_pcm_get_config(pcm_config *pcm_cfg);
void drv_pcm_start_capture(void);
void drv_pcm_stop_capture(void);
kal_uint32 drv_pcm_get_cur_ptr(void);
void drv_pcm_get_pc_pair(kal_uint8 num, kal_uint32 *pc0, kal_uint32 *pc1);
void drv_pcm_get_cid_pair(kal_uint8 num, kal_uint32 *cid0, kal_uint32 *cid1);
kal_uint8 drv_pcm_check_buf_wrap(void);
DCL_STATUS drv_pcm_register_callback(pfCallback callback);

#if (defined(MT6752) && defined(__MD2__))
#define RESTART_PCMON
#else
#define RESTART_PCMON restartPCMon()
void restartPCMon(void);
#endif

extern const kal_uint32 g_PCMON_CTRL_REG;
extern const kal_uint32 g_PCMON_MODE2_VALUE;

#endif /* end of __DRV_PCM_H__ */
