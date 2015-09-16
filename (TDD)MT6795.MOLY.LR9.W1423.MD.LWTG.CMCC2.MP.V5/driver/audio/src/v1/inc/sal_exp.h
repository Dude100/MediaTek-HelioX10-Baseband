#ifndef SAL_H
#define SAL_H
#include "common_def.h"

void SAL_Set_Device(uint32 dev);
void SAL_2G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel);
void SAL_2G_Handover(uint32 enc_mod, uint32 dec_mod, uint32 sub_channel);
void SAL_3G_Call_Open(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM);
void SAL_4G_Call_Open_temp(uint32 enc_mod, uint32 dec_mod, uint32 dtx, uint32 delR, uint32 delW, uint32 delM);
void SAL_3G_Upd_Enc_Cod(uint32 enc_mod);
void SAL_3G_Upd_Dec_Cod(uint32 dec_mod);
void SAL_2G_Call_Close(uint32 dsp_end);
void SAL_3G_Call_Close(uint32 dsp_end);
void SAL_4G_Call_Close_temp(uint32 dsp_end);
void SAL_4G_G_Codec_Call_Close(uint32 dsp_end);
//void SAL_4G_G_Codec_Open_DisableAMR(void);
//void SAL_4G_AMR_Call_Close(uint32 dsp_end);
void SAL_3G_Set_TxType(uint32 tx_type);
void SAL_3G_Set_RxType(uint32 rx_type);
volatile uint16* SAL_3G_GetAddr(uint16 type);
uint16 SAL_3G_GetValue(uint16 type);
bool SAL_3G_IsDLEmpty();
bool SAL_3G_IsULReady();
void SAL_3G_SetDLReady();
void SAL_3G_SetULEmpty();
void SAL_3G_SetULUnsync();
void SAL_3G_SetDtx(bool on);
void SAL_App_Open(uint32 delR, uint32 delW, uint32 delM);
void SAL_App_Close(uint32 dsp_end);
void SAL_Bgsnd_SetInit();
bool SAL_Bgsnd_IsRunning();
bool SAL_Bgsnd_IsIdle();
void SAL_Bgsnd_SetFinal();
void SAL_Bgsnd_Config(uint32 ulgain, uint32 dlgain, uint32 ulmix, uint32 dlmix);
volatile uint16* SAL_Bgsnd_GetBuf_DL();
uint32 SAL_Bgsnd_GetDataLen_DL();
volatile uint16* SAL_Bgsnd_GetBuf_UL();
uint32 SAL_Bgsnd_GetDataLen_UL();
void SAL_Dsp_Sph_Init();
volatile uint16* SAL_Sidetone_GetFltCoefAddr();
volatile uint16* SAL_Notch_GetFltCoefAddr();
volatile uint16* SAL_BKF_GetFltCoefAddr_NB_UL();
volatile uint16* SAL_BKF_GetFltCoefAddr_NB_DL();
volatile uint16* SAL_BKF_GetFltCoefAddr_WB_UL();
volatile uint16* SAL_BKF_GetFltCoefAddr_WB_DL();
void SAL_BKF_Switch(uint32 ul, uint32 dl);
volatile uint16* SAL_SRC_GetFltCoefAddr();
volatile uint16* SAL_AGC_GetFltCoefAddr();
void SAL_ENH_SetULPath(bool on);
void SAL_ENH_SetDLPath(bool on);
void SAL_ENH_SetInit(uint32 enh_mod);
void SAL_ENH_SetOff(uint32 enh_mod);
bool SAL_ENH_IsReady(uint32 enh_mod);
bool SAL_ENH_IsIdle(uint32 enh_mod);
void SAL_ENH_Dynamic_Ctrl(bool on, Sal_Enh_Dynamic_t fea);
void SAL_ENH_Gain_Set_DL(uint16 val);
volatile uint16* SAL_CommonPar_GetBuf();
volatile uint16* SAL_ModePar_GetBuf_NB();
volatile uint16* SAL_ModePar_GetBuf_WB();
volatile uint16* SAL_DMNR_GetFltCoefAddr_NB();
volatile uint16* SAL_DMNR_GetFltCoefAddr_WB();
void SAL_TST_Handler(int16 cmd);
bool SAL_DSPINT_Resolve(uint16 iid, uint32 * sph_int);
void SAL_PcmEx_Config(Sal_PCMEx_Config_t* cfg);
void SAL_PcmEx_SetStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
void SAL_PcmEx_SetStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SAL_PcmEx_CheckStateUL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SAL_PcmEx_CheckStateDL(Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SAL_PcmEx_IsCtrlClean(Sal_PcmEx_Type_t type);
void SAL_PcmEx_SetCtrlClean(Sal_PcmEx_Type_t type);//dangerous operation
volatile uint16* SAL_PcmEx_GetBuf(Sal_PcmEx_BufId_t id);
uint16 SAL_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id);
uint16 SAL_AGC_GetSWGain(uint8 mic); // 0 -> mic1, 1 -> mic2
bool SAL_3G_Mode();
void SAL_VM_Config(Sal_VM_Config_t * cfg);
void SAL_VM_GetFrame2G(Sal_VM_Frame * vmfrm);
void SAL_VM_GetFrame3G(Sal_VM_Frame * vmfrm);
void SAL_EPL_GetFrame(Sal_EPL_Frame * eplfrm);
void SAL_LBK_Codec(bool on);
uint16 SAL_Sidetone_GetAdaptiveGain();
void SAL_Sidetone_SetGain(uint16 val);
void SAL_Sidetone_Enable(bool ena);
uint16 SAL_DGain_Get_DL();
void SAL_DGain_Set_DL(uint16 val);
uint16 SAL_DGain_Get_UL();
void SAL_DGain_Set_UL(uint16 val);
void SAL_AGC_SetGain(uint16 val);
void SAL_BT_Config(Sal_BT_Config *cfg);
bool SAL_BT_IsEnable();
void SAL_Mute_Ctrl(Sal_Mute_Point_t ctrl, bool mute);
bool SAL_Mute_Check(Sal_Mute_Point_t ctrl);
void SAL_CTM_Switch(bool on);
void SAL_CTM_SetGain(uint16 limit, uint16 update);
uint16 SAL_CTM_GetValue(uint16 type);
bool SAL_CTM_IsIdle();
bool SAL_CTM_IsOff();
void SAL_AGC1_Config(Sal_AGC_Config_t *cfg);
void SAL_AGC2_Config(Sal_AGC_Config_t *cfg);
void SAL_AGC3_Config(Sal_AGC_Config_t *cfg);
void SAL_AGC4_Config(Sal_AGC_Config_t *cfg);
void SAL_NotchFilter_Enable(bool ena, bool thirdStageIIR);
void SAL_8K_Resync(bool ul, int16 ul_offset, bool dl, int16 dl_offset);
void SAL_GetWarnMsg(uint16 *ulcode, uint16 *dlcode);
void SAL_2G_SMR_Switch(bool on);
void SAL_VOLTE_SetInfo(Sal_VOLTE_info_t info, uint16 val);
volatile uint16* SAL_ENH_GetInternalParAddr();
void SAL_PCM_Router_Open(Sal_PCM_Router_t *pcmrt);
void SAL_PCM_Router_Close(uint32 dsp_end);

#include "sal_dsp.h"
//old school
#define SAL_KT1_FSM					(*DSP_SPH_KT1_FSM)
#define SAL_KT2_FSM					(*DSP_SPH_KT2_FSM)
#define SAL_KT_FORCE_8K				(*DSP_SPH_KT_FORCE_8K)
#define SAL_KT1_FREQ1				(*DSP_SPH_KT1_FREQ1)
#define SAL_KT1_FREQ2				(*DSP_SPH_KT1_FREQ2)
#define SAL_KT1_AMP					(*DSP_SPH_KT1_AMP)
#define SAL_KT2_FREQ1				(*DSP_SPH_KT2_FREQ1)
#define SAL_KT2_FREQ2				(*DSP_SPH_KT2_FREQ2)
#define SAL_KT2_AMP					(*DSP_SPH_KT2_AMP)
#define SAL_KT_ATT_GAIN				(*DSP_SPH_KT_ATT_GAIN)


//waiting for kill
   #define DP2_3G_debug_info0 (*DPRAM_base(0x1B7))
   #define DP2_3G_debug_info1 (*DPRAM_base(0x1B8))
   #define DP2_3G_debug_info7 (*DPRAM_base(0x1BE))



#endif
