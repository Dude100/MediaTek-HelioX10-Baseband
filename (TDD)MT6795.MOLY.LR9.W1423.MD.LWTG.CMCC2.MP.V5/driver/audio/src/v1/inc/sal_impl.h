#ifndef SAL_IMPL_H
#define SAL_IMPL_H
#include "common_def.h"
#include "sal_def.h"

#define IsWBLink(speech_codec) ((speech_codec) >= 0x20) //wayne come back


#define SALI_FLTCOEF_TYPE_SIDETONE  0
#define SALI_FLTCOEF_TYPE_BKF_NB_UL 1
#define SALI_FLTCOEF_TYPE_BKF_NB_DL 2
#define SALI_FLTCOEF_TYPE_BKF_WB_UL 3
#define SALI_FLTCOEF_TYPE_BKF_WB_DL 4
#define SALI_FLTCOEF_TYPE_SRC 5
#define SALI_FLTCOEF_TYPE_AGC 6
#define SALI_FLTCOEF_TYPE_DMNR_NB 7
#define SALI_FLTCOEF_TYPE_DMNR_WB 8
#define SALI_FLTCOEF_TYPE_NOTCH  9

#define SALI_PARAMETER_TYPE_COMMON 0
#define SALI_PARAMETER_TYPE_MODE_NB 1
#define SALI_PARAMETER_TYPE_MODE_WB 2
#define SALI_PARAMETER_TYPE_MODE_INTERNAL 3

//Improve Ctrl
#define SALI_IMPROVE_2G_SMR SAL_BIT1

uint16 SALI_Get_Codec_Length( uint8 codec );
void SALI_Fill_Enc_Silence( uint8 app_type, uint16 codec );
void SALI_Set_2G_Sch_Delay(uint8 codec_mod, uint8 subchannel);
void SALI_Set_2G_Handover();
void SALI_Set_Sch_Delay(uint16 delR, uint16 delW, uint16 delM_DL, uint16 delO, uint16 delM_UL);
void SALI_Set_Device(uint8 dev);
void SALI_Config_SRC(uint8 apptype, uint8 codec);
void SALI_Enable_Codec(uint16 enc_mod, uint16 dec_mod);
void SALI_Disable_Codec();
void SALI_Enable_Update_Codec_Now();
void SALI_Disable_Update_Codec_Now();
void SALI_3G_SetDtx(bool on);
void SALI_Set_3G_TxType(uint16 tx_type);
void SALI_Set_3G_RxType(uint16 rx_type);
uint16 SALI_3G_GetValue(uint16 type);
volatile uint16* SALI_3G_GetAddr(uint16 type);
bool SALI_3G_CheckDataSync(uint8 ul_dl);
void SALI_3G_SetDataStatus(uint8 ul_dl, bool ready);
void SALI_Upd_3G_Enc_Rate(uint16 enc_mod);
void SALI_Upd_3G_Dec_Rate(uint16 dec_mod);
void SALI_AppSpec_Control(uint8 app_type, uint8 on);
void SALI_Set_3G(bool on);
void  SALI_VBI_Reset();
void  SALI_VBI_End();
void SALI_VM_Upd_Enc_Used(uint16 codec);
void SALI_Bgsnd_Switch(bool on);
bool SALI_Bgsnd_IsRunning();
bool SALI_Bgsnd_IsOFF();
void SALI_Bgsnd_Config(uint16 ulgain, uint16 dlgain, bool ulmix, bool dlmix);
volatile uint16* SALI_Bgsnd_GetBuf(uint8 ul_dl);
uint16 SALI_Bgsnd_GetDataLen(uint8 ul_dl);
void SALI_Init();
void SALI_Set_Sph_8K_Mod(bool on);
volatile uint16* SALI_GetFltCoefAddr(uint8 type);
void SALI_BKF_Switch(bool ul, bool dl);
void SALI_ENH_Switch(uint8 enh_mod, bool on);
bool SALI_ENH_IsReady(uint8 enh_mod);
bool SALI_ENH_IsIdle(uint8 enh_mod);
void sali_enh_toberemovedtodsp();
void SALI_ENH_PathEnable(uint8 ul_dl, bool on);
void SALI_ENH_Dynamic_Ctrl(bool on, Sal_Enh_Dynamic_t fea);
void SALI_ENH_Gain_Set_DL(uint16 val);
volatile uint16* SALI_Parameter_GetAddr(uint8 type);

bool SALI_Int_Resolve(uint16 iid, uint32* sph_int);
void SALI_PcmEx_Config(Sal_PCMEx_Config_t* cfg);
void SALI_PcmEx_SetState(uint8 ul_dl, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SALI_PcmEx_CheckState(uint8 ul_dl, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta);
bool SALI_PcmEx_IsCtrlClean(Sal_PcmEx_Type_t type);
void SALI_PcmEx_SetCtrlClean(Sal_PcmEx_Type_t type);//dangerous operation
volatile uint16* SALI_PcmEx_GetBuf(Sal_PcmEx_BufId_t id);
uint16 SALI_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id);
uint16 SALI_AGC_GetSWGain(uint8 mic);
bool SALI_Check_3G();
void SALI_VM_Config(Sal_VM_Config_t * cfg);
void SALI_VM_GetFrame(uint8 rat, Sal_VM_Frame * vmfrm);
void SALI_EPL_GetFrame(Sal_EPL_Frame * eplfrm);
void SALI_LBK_Codec(bool on);
uint16 SALI_Sidetone_GetAdaptiveGain();
void SALI_Sidetone_SetGain(uint16 val);
void SALI_Sidetone_Enable(bool ena);
uint16 SALI_DGain_Get(uint8 ul_dl);
void SALI_DGain_Set(uint8 ul_dl, uint16 val);
void SALI_AGC_SetGain(uint16 val);
void SALI_BT_Config(Sal_BT_Config *cfg);
bool SALI_BT_IsEnable();
void SALI_Mute_Ctrl(Sal_Mute_Point_t ctrl, bool mute);
bool SALI_Mute_Check(Sal_Mute_Point_t ctrl);
void SALI_CTM_Switch(bool on);
void SALI_CTM_SetGain(uint16 limit, uint16 update);
uint16 SALI_CTM_GetValue(uint16 type);
bool SALI_CTM_IsIdle();
bool SALI_CTM_IsOff();
void SALI_AGC1_Config(Sal_AGC_Config_t *cfg);
void SALI_AGC2_Config(Sal_AGC_Config_t *cfg);
void SALI_AGC3_Config(Sal_AGC_Config_t *cfg);
void SALI_AGC4_Config(Sal_AGC_Config_t *cfg);
void SALI_NotchFilter_Enable(bool enable, bool thirdStageIIR);
void SALI_8K_Resync(bool ul, int16 ul_offset, bool dl, int16 dl_offset);
void SALI_GetWarnMsg(uint16 *ulcode, uint16 *dlcode);
void SALI_3G_SetULUnsync();
void SALI_2G_SMR_Switch(bool on);
void SALI_VOLTE_SetInfo(Sal_VOLTE_info_t info, uint16 val);
#endif
