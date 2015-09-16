/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2011
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
 *   exp_SphFasTypDef.h
 *
 * Project:
 * --------
 *   Maui_sw
 *
 * Description:
 * ------------
 *   Header file of Speech FAS Type Definition
 *
 * Author:
 * -------
 * -------
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#define SPH_UINT32 kal_uint32
#define SPH_INT32  kal_uint32
#define SPH_UINT16 kal_uint16
#define SPH_INT16  kal_int16
#define SPH_UCHAR  kal_uint8

#define SPH_ENH_MODE_NUM  8
#define SPH_ENH_MODE_BKF  0
#define SPH_ENH_MODE_AEC  1
#define SPH_ENH_MODE_NDC  2
#define SPH_ENH_MODE_DMNR 3
#define SPH_ENH_MODE_DGA  4
#define SPH_ENH_MODE_PLC  5
#define SPH_ENH_MODE_AGC  6
#define SPH_ENH_MODE_TDNC 7


#define SPH_BAND_MODE_NUM 2
#define SPH_FLT_SET_NUM SPH_BAND_MODE_NUM

#define SPH_MLBK_CASE_NUM   7
#define SPH_MLBK_CASE_FS   0
#define SPH_MLBK_CASE_HS   1
#define SPH_MLBK_CASE_WFS1265  2
#define SPH_MLBK_CASE_FREE_FS 3
#define SPH_MLBK_CASE_AFS122 4
#define SPH_MLBK_CASE_EFS 5
#define SPH_MLBK_CASE_FREE_WFS1265 6

#define SPH_FIX_DEV_BAND_NB 0
#define SPH_FIX_DEV_BAND_WB 1
#define SPH_FIX_DEV_BAND_DYNAMIC 2

#define SPH_P2W_UNDEF 0     //undefined
#define SPH_P2W_VOIP 1       //VOIP
#define SPH_P2W_ENH_CAL 2   //enhancement calibration

typedef enum {
   SPH_MLBK_RESULT_FAIL = 0,
   SPH_MLBK_RESULT_STOP
}SPH_MLBK_RESULT;

#if defined(__DUAL_MIC_SUPPORT__)
typedef struct 
{ 	 
   SPH_UINT16 *pi2Par;
   SPH_UINT32 u4Len;
}SAC_SphDMNRPar_t;
#endif

typedef struct 
{ 	 
   //Engineer mode parameters(common, len=12)
   SPH_INT16 *pi2EMPCom;
   SPH_UINT32 u4EMPComLen;
   
   //Sidetone filter coefs and tap number (NB+WB)
   SPH_INT16 *pi2StFltCoef[SPH_FLT_SET_NUM];
   SPH_UINT32 au4StFltTap[SPH_FLT_SET_NUM];
}SAC_SphComPar_t;

typedef struct 
{ 	    
   //Engineer mode parameters(mode, len=16)
   SPH_INT16 *pi2EMPMode;
   SPH_UINT32 u4EMPModeLen;
   
   //Device mode
   SPH_UINT32 u4DevMode;
   
    //device band config
   SPH_UINT32 u4VbiBndCfg;
   SPH_UINT32 u4DaiBndCfg;

   //Block filter coefs and tap number (NB+WB)
   SPH_INT16 *pi2BlkFltCoefUl[SPH_FLT_SET_NUM], *pi2BlkFltCoefDl[SPH_FLT_SET_NUM];
   SPH_UINT32 au4BlkFltTapUl[SPH_FLT_SET_NUM], au4BlkFltTapDl[SPH_FLT_SET_NUM];
}SAC_SphModePar_t;

typedef struct 
{ 	 
   SPH_UINT32 u4CodModUl, u4CodModDl;
}SAC_Sph2GCallPar_t;

typedef struct 
{ 	 
   SPH_UINT32 u4DelR, u4DelW;
   SPH_UINT32 u4CodModUl, u4CodModDl; 
   SPH_UINT32 u4Dtx;
  
}SAC_Sph3GCallPar_t;

typedef struct 
{ 	 
   SPH_UINT32 u4DelR, u4DelW;
   SPH_UINT32 u4CodModUl, u4CodModDl; 
   SPH_UINT32 u4RAT;//2:3GTo2G, 1:2GTo3G, 0: 3G intra
   SPH_UINT32 u4Dtx;
}SAC_SphHandoverPar_t;

//Wego Follow up, provide API codec rate change

typedef struct 
{ 	 
    SPH_UINT32 bWb;
    //SPH_UINT32 u4Voip; // 0: not VOIP task, 1: VOIP task
    SPH_UINT32 u4Format; // 0: no task, 1: VOIP task, 2: enhancement calibration
    SPH_UINT32 u4CfgUl; // Bit0: before/after ENH(0: before ENH, 1: after ENH) Bit1:enable D2M path (0: not enable, 1: enable)  Bit2:enable M2D path (0: not enable, 1:enable)
    SPH_UINT32 u4CfgDl; // Bit0: before/after ENH(0: before ENH, 1: after ENH) Bit1:enable D2M path (0: not enable, 1: enable)  Bit2:enable M2D path (0: not enable, 1:enable)      
}SAC_SphP2WPar_t;

typedef struct 
{
    SPH_UINT32 bWb;	 // 0: NB, 1: WB
    SPH_UINT32 u4Ctm; // 0: not CTM Task, 1: CTM Task   
    SPH_UINT32 u4CfgUl; // Bit0: before/after ENH(0: before ENH, 1: after ENH) Bit1:enable D2M path (0: not enable, 1: enable)  Bit2:enable M2D path (0: not enable, 1:enable)
    SPH_UINT32 u4CfgDl; // Bit0: before/after ENH(0: before ENH, 1: after ENH) Bit1:enable D2M path (0: not enable, 1: enable)  Bit2:enable M2D path (0: not enable, 1:enable)  
}SAC_SphP4WPar_t;

typedef struct 
{ 	 
   SPH_UINT32 u4BtMod;
   SPH_UINT32 u4BtDgUl,u4BtDgDl;
   SPH_UINT32 u4BitRev;
}SAC_SphBluetoothPar_t;

typedef struct 
{
   SPH_UINT32 au4SwitchUl[SPH_ENH_MODE_NUM];
   SPH_UINT32 au4SwitchDl[SPH_ENH_MODE_NUM];
}SAC_SphEnhancementPar_t;

typedef struct 
{
   SPH_UINT32 u4Wb;
}SAC_SphBtCordlessPar_t;

typedef struct 
{
   SPH_UINT32 u4Wb;
}SAC_SphAcousticTestPar_t;

typedef struct 
{ 	 
   SPH_UINT32 u4RingBufLen;
   SPH_UCHAR *pucRingBuf;
   SPH_UCHAR *pucWritePtr;
}SAC_SphBkgSoundPar_t;

// Daniel
typedef struct 
{ 	 
    //SPH_UINT32 u4WbPcm;                      // 0: not Wb pcm, 1: Wb pcm
    SPH_UINT32 u4RecMode;        //0-> mono, 1 -> stereo; renaming   u4DualMic;      // 0: no dual mic, 1: dual mic
    
}SAC_SphRecordPcmPar_t;

typedef struct 
{
   SPH_UINT32 u4RecCodUl, u4RecCodDl;     // Codec Mode
   SPH_UINT32 u4VmStr;                    // bit0: MdmDbg, bit1: So, bit2: Epl, bit3: FWLA, bit4: Abf
   SPH_UINT32 u4Dtx;
    //SPH_UINT32 u4AbfCal;				   //0: Abf calibration off, 1: Abf calibration on
}SAC_SphRecordVmPar_t;

typedef struct 
{ 	 
   SPH_UCHAR *pucRingBuf;
   SPH_UCHAR *pucWritePtr;
   SPH_UINT32 u4RingBufLen;
   SPH_UINT32 u4PlyMod;                    // play format: 0:VM (SAC to SPH)
   SPH_UINT32 u4WbPcm;                     // 0: not Wb pcm, 1: Wb pcm
}SAC_SphPlayPar_t;


typedef struct 
{ 	 
   SPH_INT32 i4SphDbgInfo2, i2SphDbgInfo3;
   SPH_INT16 *pi2MdmAmr;
}MDM_SphVmLg_t;


typedef struct 
{ 	 
	 SPH_UINT32 u4DisCirc;
   SPH_UINT32 u4Flt;
   SPH_UINT32 u4Flt2;
}SAC_SphFWLAPar_t;

typedef struct
{
   SPH_UCHAR *pucBufPtr;
   SPH_UCHAR *pucNxtStrPtr;
   SPH_UINT32 u4Len;
}SAS_SphOutputPar_t;

typedef struct
{
   SPH_UCHAR *pucBufPtr;
   SPH_UCHAR *pucNxtStrPtr;
   SPH_UINT32 u4Len;
   SPH_UINT32 u4Wb;
}SAS_RecPcmRequestReadUlData_t;    

typedef struct
{
   SPH_UCHAR *pucOutputBufPtr;
   SPH_UCHAR *pucInputBufPtr;
   SPH_UINT32 u4Len;
}SAS_PCM2Way_ExchangeData_t;


typedef struct
{
   SPH_UCHAR *pucDlBufPtr;
   SPH_UINT32 u4RxTyp, u4CodModDl;
   SPH_UINT32 u4DlMaxLen;
}SAS_3GCallRequestWriteDlData_t;

typedef struct
{
   SPH_UCHAR *pucUlBufPtr;
   SPH_UINT32 u4TxTyp, u4CodModUl;
   SPH_UINT32 u4UlLen;
}SAS_3GCallRequestReadUlData_t;

typedef struct
{
   SPH_UCHAR *pucOutputUlBufPtr;
   SPH_UCHAR *pucInputUlBufPtr;
   SPH_UINT32 u4Len;
}SAS_PCM4Way_ExchangeUlData_t;

typedef struct
{
   SPH_UCHAR *pucOutputDlBufPtr;
   SPH_UCHAR *pucInputDlBufPtr;
   SPH_UINT32 u4Len;
   SPH_UINT32 u4BFI;
}SAS_PCM4Way_ExchangeDlData_t;

typedef struct
{
   SPH_UCHAR *pucOutputUlBufPtr;
   SPH_UINT32 u4Len;
}SAS_PCM2Way_ExchangeUlData_t;

typedef struct
{
   SPH_UCHAR *pucInputDlBufPtr;
   SPH_UINT32 u4Len;
}SAS_PCM2Way_ExchangeDlData_t;

typedef struct
{
   SPH_UCHAR *pucInputUlBufPtr;
   SPH_UINT32 u4Len;
}SAS_DataCard_RequestWriteUlData_t;

typedef struct
{
   SPH_UCHAR *pucOutputDlBufPtr;
   SPH_UINT32 u4Len;
}SAS_DataCard_RequestReadDlData_t;

typedef struct
{
   SPH_UINT32 u4CodGainLim;
   SPH_UINT32 u4CodGainUpd;
}SAC_SphCtmPar_t;

typedef struct
{
   SPH_UINT32 u4Len;
   SPH_UCHAR *puc3GL1Ptr;
}SAC_Sph3GL1Info_t;

typedef struct
{
   SPH_INT32 i4StopFrm;
   SPH_UCHAR *pucRingBuf;
   SPH_UCHAR *pucWritePtr;
   SPH_UINT32 u4RingBufLen;
}SAC_SphSputPar_t;

typedef struct{
   SPH_UINT32 u4AGC_MODE; //Up to now, only Mode 0 is available.
   SPH_UINT32 u4AGC_MAX_PGA_GAIN_CH1; //only bits: 000000 ~ 111111 is mapped to -20dB ~ 43dB
   SPH_UINT32 u4AGC_MIN_PGA_GAIN_CH1; //only bits: 000000 ~ 111111 is mapped to -20dB ~ 43dB
   SPH_UINT32 u4AGC_MAX_PGA_GAIN_CH2; //only bits: 000000 ~ 111111 is mapped to -20dB ~ 43dB
   SPH_UINT32 u4AGC_MIN_PGA_GAIN_CH2; //only bits: 000000 ~ 111111 is mapped to -20dB ~ 43dB   
}SPH_AGC_t;

typedef struct{
	 void*           pBuf;
	 unsigned int    u4BufLength;
	 void*           pWrite;
	 void*           pRead;
	 unsigned int    u4Time;
	 unsigned int    u4SamplingRate; // = 32000, or 44100, or 48000
	 unsigned int    u4ChannelNum;   // = 2
	 unsigned int    u4OutputDevice; // eAUD_OUTDEV_DAC,eAUD_OUTDEV_MCU
}AUD_Buf_t;
