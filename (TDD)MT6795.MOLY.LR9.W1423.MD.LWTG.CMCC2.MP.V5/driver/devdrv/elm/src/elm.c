#include "elm.h"
#include "ex_mem_manager.h"
#ifdef __MTK_TARGET__

#define __ELM_NONCACHED_DATA__ __attribute__((section ("NONCACHEDRW")))
__ELM_NONCACHED_DATA__ kal_uint32* elm_dbg_ptr;
__ELM_NONCACHED_DATA__ kal_uint32 elm_dbg_size;
__ELM_NONCACHED_DATA__ kal_uint32 elm_data_temp;

kal_uint32 elm_dbg_entry = KAL_FALSE;




#ifdef __ELM_RUNTIME_PROFILE__


#ifdef ELM_DADA_IN_TCM
#define ELM_INTERNAL __attribute__ ((zero_init, section ("INTSRAM_ZI")))
#else
#define ELM_INTERNAL
#endif

ELM_INTERNAL kal_uint32 elm_profile_history_idx = 0;
ELM_INTERNAL ELM_GENERNAL_PROFILE_T elm_profile_history[ELM_HISTORY_SIZE];
ELM_INTERNAL ELM_GENERNAL_PROFILE_T elm_profile_history_w_worst = {0,0,0,0,0};
ELM_INTERNAL ELM_GENERNAL_PROFILE_T elm_profile_history_r_worst = {0,0,0,0,0};
ELM_INTERNAL kal_uint32 elm_profile_w_latency;
ELM_INTERNAL kal_uint32 elm_profile_r_latency;
ELM_INTERNAL kal_uint32 elm_profile_target_caller = 0; //target caller maybe 2G or 3G or 4G
ELM_INTERNAL kal_uint32 elm_profile_cur_time = 0; //current FRC value
ELM_INTERNAL kal_uint32 elm_profile_prev_time = 0; //previous FRC value
ELM_INTERNAL kal_uint32 elm_profile_dur_time = 0; //duration time
ELM_INTERNAL kal_uint32 elm_profile_hw_is_init = 0; //PDN CLR?
ELM_INTERNAL kal_uint32 elm_profile_MD_status[3] = {0,0,0};

#ifdef __ELM_TEST__
ELM_INTERNAL ELM_PROFILE_TICK_T elm_profile_tick_per[ELM_HISTORY_SIZE];
ELM_INTERNAL kal_uint32 elm_profile_tick_cur_time = 0;
ELM_INTERNAL kal_uint32 elm_profile_tick_prev_time = 0;
ELM_INTERNAL kal_uint32 elm_tick_idex;
ELM_INTERNAL kal_uint32 elm_start_idex;
#endif //__ELM_TEST__

#endif //__ELM_RUNTIME_PROFILE__
#endif    /* __MTK_TARGET__ */

#if defined(MT6752)
#if defined(__MD1__)
// 1T bus = 3T CPU 
#define ELM_TRANS2NS(X) ((((X*1000*3)<<4)/CPU_CLOCK_MHZ)>>4)
#define ELM_PASS_READ_LATENCY (310+30)
#define ELM_PASS_WRITE_LATENCY (200+30)
#elif defined (__MD2__)
// 1T bus = 4T CPU
#define ELM_TRANS2NS(X) ((((X*1000*4)<<4)/CPU_CLOCK_MHZ)>>4)
#define ELM_PASS_READ_LATENCY (350+30)
#define ELM_PASS_WRITE_LATENCY (350+30)
#endif //__MD1__

#else //defined(MT6752)
// 1T bus = 3T CPU 
#define ELM_TRANS2NS(X) ((((X*1000*3)<<4)/CPU_CLOCK_MHZ)>>4)
#define ELM_PASS_READ_LATENCY (310+30)
#define ELM_PASS_WRITE_LATENCY (200+30)
#endif //defined(MT6572)
#define ELM_TAG_READ  (0x454C4D00)
#define ELM_TAG_WRITE (0x454C4D01)


kal_uint8 _ELM_latency_status(void)
{
#ifdef __ELM_RUNTIME_PROFILE__

	if(ELM_TRANS2NS(elm_profile_history_r_worst.avg_rlat) > ELM_PASS_READ_LATENCY)
	{
		return 0xAE; //EMI read latency may be too long
	}
	
	if(ELM_TRANS2NS(elm_profile_history_w_worst.avg_wlat) > ELM_PASS_WRITE_LATENCY)
	{
		return 0xBE; //EMI write latency may be too long
	}

	return 0xDE; // EMI read/write latency are OK.
	
#else
	return 0xFF; //no ELM info
#endif	
}

void _ELM_exception_saved(void)
{
#ifdef __ELM_RUNTIME_PROFILE__
	//ELM read worse case
	elm_data_temp = ELM_TAG_READ;
	EMM_WriteDbgInfo(EMM_ELM_READ_TAG, (void*)&elm_data_temp);	
	elm_data_temp = ELM_TRANS2NS(elm_profile_history_r_worst.avg_rlat);
	EMM_WriteDbgInfo(EMM_ELM_READ_R_ALAT_NS, (void*)&elm_data_temp);	
	EMM_WriteDbgInfo(EMM_ELM_READ_R_ALAT, (void*)&elm_profile_history_r_worst.avg_rlat);
	EMM_WriteDbgInfo(EMM_ELM_READ_R_TRANS, (void*)&elm_profile_history_r_worst.r_trans);
	EMM_WriteDbgInfo(EMM_ELM_READ_W_ALAT, (void*)&elm_profile_history_r_worst.avg_wlat);
	EMM_WriteDbgInfo(EMM_ELM_READ_W_TRANS, (void*)&elm_profile_history_r_worst.w_trans);
	EMM_WriteDbgInfo(EMM_ELM_READ_DURATION, (void*)&elm_profile_history_r_worst.duration);

	//ELM write worse case
	elm_data_temp= ELM_TAG_WRITE;
	EMM_WriteDbgInfo(EMM_ELM_WRITE_TAG, (void*)&elm_data_temp);
	elm_data_temp = ELM_TRANS2NS(elm_profile_history_w_worst.avg_wlat);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_W_ALAT_NS, (void*)&elm_data_temp);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_R_ALAT, (void*)&elm_profile_history_w_worst.avg_rlat);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_R_TRANS, (void*)&elm_profile_history_w_worst.r_trans);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_W_ALAT, (void*)&elm_profile_history_w_worst.avg_wlat);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_W_TRANS, (void*)&elm_profile_history_w_worst.w_trans);
	EMM_WriteDbgInfo(EMM_ELM_WRITE_DURATION, (void*)&elm_profile_history_w_worst.duration);
#endif	
}





#if 0 //for debugging and test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
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
#else
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
/* under construction !*/
/* under construction !*/
#endif


