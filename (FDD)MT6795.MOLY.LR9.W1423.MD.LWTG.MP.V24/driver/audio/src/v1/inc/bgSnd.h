
#ifndef __BGSNG_H__
#define __BGSNG_H__

#define BGSND_RB_DEFAULT_THRESHOLD    1024

/*
int32 BGSND_GetFreeSpace(void);
void BGSND_WriteData(kal_uint8 *srcBuf, kal_int32 bufLen);

void BGSND_ConfigULMixer(kal_bool bULSPHFlag, kal_int8 ULSNDGain );
void BGSND_ConfigDLMixer(kal_bool bDLSPHFlag, kal_int8 DLSNDGain );
void BGSND_Start(void (*bgSnd_hisrHandler)(void), void (*bgSnd_offHandler)(void), kal_uint8 ULGainLevel , kal_uint8 DLGainLevel);
void BGSND_Stop(void);
void BGSND_Close(void);
void BGSND_INIT(void);
*/

typedef enum { 
	BGSND_DL_PROCESS = 0, //you cannot change the value since I use "1-type" to switch either.
	BGSND_UL_PROCESS = 1, 
}BGSND_PROCESS_TYPE;


typedef enum {
	EXT_SRC_STATE_IDLE = 0,
	EXT_SRC_STATE_RUN, 
	EXT_SRC_STATE_FLUSHING,
   EXT_SRC_STATE_FLUSHING_OVER,
	EXT_SRC_STATE_STOPPING,
}EXT_SRC_STATE_TYPE;


int32 EXT_BGSND_GetFreeSpace(uint32 id, BGSND_PROCESS_TYPE type);
int32 EXT_BGSND_GetDataCount(uint32 id, BGSND_PROCESS_TYPE type);
void EXT_BGSND_WriteSrcBuffer(uint32 id, kal_uint8 *srcBuf, kal_int32 bufLen, BGSND_PROCESS_TYPE type);
void EXT_BGSND_WriteExtBuffer(uint32 id, int gain, BGSND_PROCESS_TYPE type);

void EXT_BGSND_ConfigMixer(int id, kal_bool bSPHFlag, kal_int8 SNDGain, BGSND_PROCESS_TYPE type);
uint32 EXT_BGSND_Start(void (*offHdr)(void),
                       void (*DLHisr)(void),       //move data from src -> ext
                       void (*ULHisr)(void),       //move data from src -> ext    
                       kal_int8 DLSNDGain,
                       kal_int8 ULSNDGain                       
                       /*,                       
                       void (*EventHandler)(void)*/);
void EXT_BGSND_Flush(uint32 id);
void EXT_BGSND_Close(uint32 id);                       

uint32 EXT_BGSND_init();

EXT_SRC_STATE_TYPE EXT_BGSND_GetStatus(int id,  BGSND_PROCESS_TYPE enULDL);

#endif //__BGSNG_H__
