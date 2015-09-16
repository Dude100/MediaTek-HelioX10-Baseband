


#if !defined(__SMART_PHONE_MODEM__)

#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"

#include "dcl.h"

#include "afe.h"

#if defined(__ENABLE_SPEECH_DVT__)
extern kal_bool Is_Sph_DVT_BT_Mode_NB(void);
#endif // defined(__ENABLE_SPEECH_DVT__)

#define WriteREG(_addr, _value) (*(volatile kal_uint32 *)(_addr) = (_value))


// ----------------------------------------------------------------------------
// Register Definition
// ----------------------------------------------------------------------------

#if defined(MT6589)

// #define AP_AUDSYS_BASE   0xA2070000

#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AUDIO_TOP_CON3                  (AP_AUDSYS_base + 0x000c)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)
#define AFE_DAC_CON1                    (AP_AUDSYS_base + 0x0014)
#define AFE_I2S_CON                     (AP_AUDSYS_base + 0x0018)
#define AFE_DAIBT_CON0                  (AP_AUDSYS_base + 0x001c)
                                        
#define AP_AFE_CONN0                       (AP_AUDSYS_base + 0x0020)
#define AP_AFE_CONN1                       (AP_AUDSYS_base + 0x0024)
#define AP_AFE_CONN2                       (AP_AUDSYS_base + 0x0028)
#define AP_AFE_CONN3                       (AP_AUDSYS_base + 0x002c)
#define AP_AFE_CONN4                       (AP_AUDSYS_base + 0x0030)

#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)
#define AFE_I2S_CON2                    (AP_AUDSYS_base + 0x0038)
#define AFE_MRGIF_CON                   (AP_AUDSYS_base + 0x003c)

#define AFE_SIDDETONE_DEBUG             (AP_AUDSYS_base + 0x01D0)
#define AFE_SIDDETONE_MON               (AP_AUDSYS_base + 0x01D4)
#define AFE_SIDDETONE_CON0              (AP_AUDSYS_base + 0x01E0)
#define AFE_SIDDETONE_COEFF             (AP_AUDSYS_base + 0x01E4)
#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)
#define AFE_SIDDETONE_GAIN              (AP_AUDSYS_base + 0x01EC)
#define AFE_SGEN_CON0                   (AP_AUDSYS_base + 0x01F0)
                                        
#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)


#define AFE_GAIN2_CON0                  (AP_AUDSYS_base + 0x0428)
#define AFE_GAIN2_CON                   (AP_AUDSYS_base + 0x0438)
#define AFE_GAIN2_CON2                  (AP_AUDSYS_base + 0x0440)

#define PCM_INTF_CON1                   (AP_AUDSYS_base + 0x0530)
#define PCM_INTF_CON2                   (AP_AUDSYS_base + 0x0538)
#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)
#define FOC_ROM_SIG                     (AP_AUDSYS_base + 0x0630)

#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)

#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)

#define AP_AFE_CONN0                       (AP_AUDSYS_base + 0x0020)
#define AP_AFE_CONN1                       (AP_AUDSYS_base + 0x0024)
#define AP_AFE_CONN2                       (AP_AUDSYS_base + 0x0028)
#define AP_AFE_CONN3                       (AP_AUDSYS_base + 0x002c)
#define AP_AFE_CONN4                       (AP_AUDSYS_base + 0x0030)

#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)

#define AFE_ADDA_DL_SRC2_CON0           (AP_AUDSYS_base + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (AP_AUDSYS_base + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (AP_AUDSYS_base + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (AP_AUDSYS_base + 0x0118)
#define AFE_ADDA_TOP_CON0               (AP_AUDSYS_base + 0x0120)
#define AFE_ADDA_UL_DL_CON0             (AP_AUDSYS_base + 0x0124)

#define AFE_ADDA_NEWIF_CFG0             (AP_AUDSYS_base + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (AP_AUDSYS_base + 0x013C)


#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)

#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)

#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)

#elif defined(MT6595)

#define AUDIO_PWR                       (CKSYS_BASE     + 0x629c)
#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)
#define AFE_DAC_CON1                    (AP_AUDSYS_base + 0x0014)

#define AP_AFE_CONN0                       (AP_AUDSYS_base + 0x0020)
#define AP_AFE_CONN1                       (AP_AUDSYS_base + 0x0024)
#define AP_AFE_CONN2                       (AP_AUDSYS_base + 0x0028)
#define AP_AFE_CONN3                       (AP_AUDSYS_base + 0x002c)
#define AP_AFE_CONN4                       (AP_AUDSYS_base + 0x0030)

#define AP_AFE_CONN5                       (AP_AUDSYS_base + 0x005C)
#define AP_AFE_CONN6                       (AP_AUDSYS_base + 0x00BC)


#define AFE_I2S_CON                     (AP_AUDSYS_base + 0x0018)
#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)
#define AFE_I2S_CON2                    (AP_AUDSYS_base + 0x0038)
#define AFE_I2S_CON3                    (AP_AUDSYS_base + 0x004C)


#define AFE_ADDA_DL_SRC2_CON0           (AP_AUDSYS_base + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (AP_AUDSYS_base + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (AP_AUDSYS_base + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (AP_AUDSYS_base + 0x0118)
#define AFE_ADDA_UL_DL_CON0             (AP_AUDSYS_base + 0x0124)

#define AFE_ADDA_NEWIF_CFG0             (AP_AUDSYS_base + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (AP_AUDSYS_base + 0x013C)


#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)
#define AFE_SGEN_CON0                   (AP_AUDSYS_base + 0x01F0)


#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)

#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)

#elif defined(MT6752)

#define AUDIO_PWR                       (CKSYS_BASE     + 0x629c)

// #define AP_AUDSYS_BASE   0xA1220000

#define AUDIO_TOP_CON0                  (AP_AUDSYS_base + 0x0000)
#define AUDIO_TOP_CON1                  (AP_AUDSYS_base + 0x0004)
#define AUDIO_TOP_CON2                  (AP_AUDSYS_base + 0x0008)
#define AUDIO_TOP_CON3                  (AP_AUDSYS_base + 0x000C)
#define AFE_DAC_CON0                    (AP_AUDSYS_base + 0x0010)
#define AFE_DAC_CON1                    (AP_AUDSYS_base + 0x0014)
#define AFE_I2S_CON                     (AP_AUDSYS_base + 0x0018)
#define AFE_DAIBT_CON0                  (AP_AUDSYS_base + 0x001C)
                                        
#define AP_AFE_CONN0                    (AP_AUDSYS_base + 0x0020)
#define AP_AFE_CONN1                    (AP_AUDSYS_base + 0x0024)
#define AP_AFE_CONN2                    (AP_AUDSYS_base + 0x0028)
#define AP_AFE_CONN3                    (AP_AUDSYS_base + 0x002C)
#define AP_AFE_CONN4                    (AP_AUDSYS_base + 0x0030)

#define AP_AFE_CONN5                    (AP_AUDSYS_base + 0x005C)
#define AP_AFE_CONN6                    (AP_AUDSYS_base + 0x00BC)

#define AP_AFE_CONN7                    (AP_AUDSYS_base + 0x0460)
#define AP_AFE_CONN8                    (AP_AUDSYS_base + 0x0464)
#define AP_AFE_CONN9                    (AP_AUDSYS_base + 0x0468)
#define AP_AFE_CONN10                   (AP_AUDSYS_base + 0x046C)

#define AFE_I2S_CON1                    (AP_AUDSYS_base + 0x0034)
#define AFE_I2S_CON2                    (AP_AUDSYS_base + 0x0038)
#define AFE_MRGIF_CON                   (AP_AUDSYS_base + 0x003C)
#define AFE_I2S_CON3                    (AP_AUDSYS_base + 0x004C)

#define AFE_ADDA_DL_SRC2_CON0           (AP_AUDSYS_base + 0x0108)
#define AFE_ADDA_DL_SRC2_CON1           (AP_AUDSYS_base + 0x010C)
#define AFE_ADDA_UL_SRC_CON0            (AP_AUDSYS_base + 0x0114)
#define AFE_ADDA_UL_SRC_CON1            (AP_AUDSYS_base + 0x0118)

#define AFE_ADDA_UL_DL_CON0             (AP_AUDSYS_base + 0x0124)
#define AFE_ADDA_NEWIF_CFG0             (AP_AUDSYS_base + 0x0138)
#define AFE_ADDA_NEWIF_CFG1             (AP_AUDSYS_base + 0x013C)

#define AFE_SIDDETONE_DEBUG             (AP_AUDSYS_base + 0x01D0)
#define AFE_SIDDETONE_MON               (AP_AUDSYS_base + 0x01D4)
#define AFE_SIDDETONE_CON0              (AP_AUDSYS_base + 0x01E0)
#define AFE_SIDDETONE_COEFF             (AP_AUDSYS_base + 0x01E4)
#define AFE_SIDDETONE_CON1              (AP_AUDSYS_base + 0x01E8)
#define AFE_SIDDETONE_GAIN              (AP_AUDSYS_base + 0x01EC)

#define AFE_SGEN_CON0                   (AP_AUDSYS_base + 0x01F0)
#define AFE_TOP_CON0                    (AP_AUDSYS_base + 0x0200)

#define AFE_GAIN2_CON0                  (AP_AUDSYS_base + 0x0428)
#define AFE_GAIN2_CONN                  (AP_AUDSYS_base + 0x0438)
#define AFE_GAIN2_CONN2                 (AP_AUDSYS_base + 0x0440)
#define AFE_GAIN2_CONN3                 (AP_AUDSYS_base + 0x0444)

#define PCM_INTF_CON1                   (AP_AUDSYS_base + 0x0530)
#define PCM_INTF_CON2                   (AP_AUDSYS_base + 0x0538)
#define PCM_INTF_CON                    (AP_AUDSYS_base + 0x053C)
//#define FOC_ROM_SIG                     (AP_AUDSYS_base + 0x0630)


#endif 
// ----------------------------------------------------------------------------
// Register Setting for different scenario 
// ----------------------------------------------------------------------------


#if defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)

void PMIC_AudioConfig_Loopback(void)
{
	kal_uint32 addr;
	kal_uint16 data;
	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
	PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;
	
	setVal.offset = (0<<31) | addr; 
	setVal.value = data; 

	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

	// 	0x0102 bit[0] to be 1, eable clock source	
	/*
	getVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0001);
	setVal.offset = ((0<<31) | 0x0102); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	*/
	
	// 	0x010C 0x0100 0x0100 Turn on clock
	getVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value | 0x0100);
	setVal.offset = ((0<<31) | 0x010C); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// 	0x010C 0x0100 0x0100 Turn on clock
	#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
	#endif 
	setVal.offset = ((0<<31) | 0x402C); 
	setVal.value = (0x0000);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4024); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
    {   // 8k setting
        setVal.value = (0x0330);
    }
    else
#endif // defined(__ENABLE_SPEECH_DVT__)
    {   // 16k setting
        setVal.value = (0x3330);	// 16k : 0x3330, 8k : 0x0330
    }
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4028); 
	setVal.value = (0x3c2f);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4002); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
    {   // 8k setting
        setVal.value = (0x0000);
    }
    else
#endif // defined(__ENABLE_SPEECH_DVT__)
    {   // 16k setting
        setVal.value = (0x0004);    // 16k : 0x0004, 8k : 0x0000
    }
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


	// sine tone generation
	setVal.offset = ((0<<31) | 0x4004); 
	setVal.value = (0x0000); // loopback 	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	/*
	setVal.offset = ((0<<31) | 0x4010); 
	setVal.value = (0x9010);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	*/
	// sine tone generation 
	
	setVal.offset = ((0<<31) | 0x4016); 
	setVal.value = (0x0100);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x4000); 
	setVal.value = (0x0003);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0700); 
	setVal.value = (0x79A0);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0702); 
	setVal.value = (0x0200);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0704); 
	setVal.value = (0x00F3);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0706); 
	setVal.value = (0x0000);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	setVal.offset = ((0<<31) | 0x0710); 
	setVal.value = (0x0208);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x0708); 
	setVal.value = (0x007c);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070A); 
	setVal.value = (0x2214);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070C); 
	setVal.value = (0xF5BA);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x070E); 
	setVal.value = (0x25B0);	
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

}

#elif defined(MT6595)
void PMIC_AudioConfig(void)
{

	DCL_HANDLE handle;
	PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
	PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;

	handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);

// ====== here set analog part (voice uplink CH0/CH2 12 dB)			
// 0x0680	0x0000	[0] RG_AUDGLB_PWRDN_VA32 = 0	
// Enable AUDGLB
	setVal.offset = ((0<<31) | 0x0680); 
	setVal.value = (0x0);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x015A	0x0001	[0] RG_CLKSQ_EN_AUD=1	
// Enable CLKSQ
	getVal.offset = ((0<<31) | 0x015A); 
	DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
	setVal.value = (getVal.value| 0x0001);
	setVal.offset = ((0<<31) | 0x015A); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x068C	0x0400	[10] RG_AUDADCCLKRSTB=1	
// Enable ADC CLK
	setVal.offset = ((0<<31) | 0x068C); 
	setVal.value = (0x0400);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x069C	0x000F	[3:1] RG_AUDMICBIAS0VREF=111 
//                      [0] RG_AUDPWDBMICBIAS0=1	
// Enable MICBIAS0 (2.7V)
	setVal.offset = ((0<<31) | 0x069C); 
	setVal.value = (0x000F);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x069E	0x000F	[3:1] RG_AUDMICBIAS2VREF=111 
//                      [0] RG_AUDPWDBMICBIAS2=1	
// Enable MICBIAS2 (2.7V)
	setVal.offset = ((0<<31) | 0x069E); 
	setVal.value = (0x000F);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x06AC	0x0007	[5:4] RG_LCLDO18_ENC_VOSEL=00    
//                      [2] RG_LCLDO18_ENC_REMOTE_SENSE=1 
//                      [0] RG_LCLDO18_ENC_EN=1 
//                      [1] RG_LCLDO18_ENC_PDDIS_EN=1  
//                      [7:6] RG_LCLDO19_ADC_VOSEL=00	
// Enable LCLDO18_ENC (1.8V), Remote-Sense. Set LCLDO19_ADC voltage 1.9V
	setVal.offset = ((0<<31) | 0x06AC); 
	setVal.value = (0x0007);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x06AE	0x2277	[2] RG_LCLDO19_ADCCH0_1_REMOTE_SENSE=1 
//                      [0] RG_LCLDO19_ADCCH0_1_EN=1 
//                      [6] RG_LCLDO19_ADCCH_2_REMOTE_SENSE=1 
//                      [4] RG_LCLDO19_ADCCH_2_EN=1
//                      [1] RG_LCLDO19_ADCCH0_1_PDDIS_EN=1 
//                      [5]RG_LCLDO19_ADCCH_2_PDDIS_EN=1 
//                      [9] RG_LCLDO19_ADCCH_3_PDDIS_EN=1 
//                      [13] RG_LCLDO19_ADCCH_4_PDDIS_EN=1		
// Enable LCLDO19_ADCCH0_1, Remote-Sense. Enable LCLDO19_ADCCH_2, Remote-Sense
	setVal.offset = ((0<<31) | 0x06AE); 
	setVal.value = (0x2277);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x06A2	0x0022	[2:0] RG_AUDPREAMPCH0_1GAIN=010
//                      [6:4] RG_AUDPREAMPCH_2GAIN=010
// Set PGA CH0_1 gain = 12dB; Set PGA CH_2 gain = 12dB
	setVal.offset = ((0<<31) | 0x06A2); 
	setVal.value = (0x0033);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0686	0x0051	[5:4] RG_AUDPREAMPCH0_1INPUTSEL=01 
//                      [0] RG_AUDPREAMPCH0_1ON=1 
//                      [6] RG_AUDPREAMPCH_2ON=1
// Enable PGA CH0_1 (CH0 in); Enable PGA CH_2
	setVal.offset = ((0<<31) | 0x0686); 
	setVal.value = (0x0051);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0688	0x0055	[2:1]RG_AUDADCCH0_1INPUTSEL=10 
//                      [0] RG_AUDADCCH0_1PWRUP=1 
//                      [6:5]RG_AUDADCCH_2INPUTSEL=10 
//                      [4] RG_AUDADCCH_2PWRUP=1
// Enable ADC CH0_1 (PGA in); Enable ADC CH_2 (PGA in)
	setVal.offset = ((0<<31) | 0x0688); 
	setVal.value = (0x0055);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// here set digital part ------------
// 0x015C 	0x0003	CKSQ Enable	important
	setVal.offset = ((0<<31) | 0x015C); 
	setVal.value = (0x0003);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal); 

// 	0x013C	AUD clock power down released	important
	setVal.offset = ((0<<31) | 0x013C); 
	setVal.value = (0x3000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2014	0x0000	[14] digital mic clock divider reset
//                      [7] power down adda/anc clock
//                      [5] power down up link1 clock
//                      [4] power down down link clock
//                      [2] power down whole afe clock
// power on clock
	setVal.offset = ((0<<31) | 0x2014); 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x204A	0x0000	[15] power down anc clk
//                      [13] Power down adc2 clock ( up link2 )
// power on ADC clk
	setVal.offset = ((0<<31) | 0x204A); 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2012	0x0000	[15] loopback test 2 ( DL rx data to UL tx)
//                      [14] loopback test1 ( UL tx sdata to DL rx)
//                      [13] anc loopback test2 (ANC rx data to ANC tx)
//                      [12] anc loopback test1 (ANC tx sdata to ANC rx)
//                      [11:10] UL 2 dmic low power mode ch2
//                      [9:8] UL 2 dmic low power mode ch1
//                      [7] dmic 48k sel ch2 (3p25m ADC FS)
//                      [6] dmic 48k sel ch1 (3p25m ADC FS)
//                      [5:4] UL 1 dmic low power mode ch2
//                      [3:2] UL 1 dmic low power mode ch1
//                      [1] mtk tx src from sine gen
//                      [0] dl src from sine gen
// configure ADC setting
	setVal.offset = ((0<<31) | 0x2012); // TODO: position is okey?? 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2020	0x0006 sdm audio fifo clock power on	DAC
	setVal.offset = ((0<<31) | 0x2020); 
	setVal.value = (0x0006);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x201c	0xc3a1 scrambler clock on enable	DAC	
	setVal.offset = ((0<<31) | 0x201c); 
	setVal.value = (0xc3a1);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
// 0x2020	0x0003 sdm power on	DAC
	setVal.offset = ((0<<31) | 0x2020); 
	setVal.value = (0x0003);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
// 0x2020	0x000b sdm fifo enable	DAC	
	setVal.offset = ((0<<31) | 0x2020); 
	setVal.value = (0x000b);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2008	0x001e set attenuation gain	SDM
	setVal.offset = ((0<<31) | 0x2008); 
	setVal.value = (0x001e);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// -----------------------------------------------------------------

// 0x2000	0x0001	[0] afe enable	turn on afe
	setVal.offset = ((0<<31) | 0x2000); 
	setVal.value = (0x0001);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200A	0x000a	[13:11] digimic ch1 clk phase sel
//                      [10:8] digimic ch2 clk phase sel
//                      [7] digital_mic to wire mode
//                      [6] digital mic on ch2
//                      [5] digital mic on ch1
//                      [4:3] up link1 ch2 voice mode
//                      [2:1] up link1 ch1 voice mode
//                      voice mode: 0: 8k, 1:16k, 2:32k,3:48k
// UL1 configure
	setVal.offset = ((0<<31) | 0x200A);
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x0000);
	}
	else 
#endif
	{
#if MDAFE_DVT_CASE1 // 32k
		setVal.value = (0x0014);
#elif MDAFE_DVT_CASE3 // 8k
		setVal.value = (0x0000);
#else // 16k
		setVal.value = (0x000A);
#endif 
	}
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200C	0x0001	[2] DAC loop back to ADC
//                      [1] digital mic mode
//                      [0] up link 1 src on
// power on uplink
	setVal.offset = ((0<<31) | 0x200C);
	setVal.value = (0x0001);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	// 0x2002	0x3800	[15:12] DL sample rate
	// 							0: 8k.
	// 							1: 11.025k.
	// 							2: 12k.
	// 							3: 16k.
	// 							4: 22.05k.
	// 							5: 24k.
	// 							6: 32k.
	// 							7: 44.1k.
	// 							8: 48k.
	// 							Other : 8k
		setVal.offset = ((0<<31) | 0x2002); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x0300);
	}
	else 
#endif
	{
#if MDAFE_DVT_CASE1 // 32k
		setVal.value = (0x6300);
#elif MDAFE_DVT_CASE3 // 8k
		setVal.value = (0x0300);
#else // 16k
		setVal.value = (0x3300);
#endif
	}
		DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2038	0x3380	[15:12]
//                      0 : time slot1=384, time slot2=23 @ 64K interval (8k)
//                      1 : time slot1= 272, time slot2=23 @ 88.2K interval.
//                      2 : time slot1= 246, time slot2=27 @ 96K interval.
//                      3 : time slot1= 181, time slot2=23 @ 128K interval. (16k)
//                      4 : time slot1= 125, time slot2=23 @ 176.4K interval.
//                      5 : time slot1= 111, time slot2=27 @ 192K interval.
//                      6 : time slot1= 79, time slot2=24 @ 256K interval. (32k)
//                      7 : time slot1= 51, time slot2=23 @ 352.8K interval.
//                      8 : time slot1= 47, time slot2=24 @ 384K interval. (48k)
//                      others : time slot1=up8x_rxif_sync_cnt_table[8:0], time slot2 = up8x_rxif_sync_search_table[4:0].
	setVal.offset = ((0<<31) | 0x2038); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x0330);
	}
	else 
#endif
	{
#if MDAFE_DVT_CASE1 // 32k
		setVal.value = (0x6330);
#elif MDAFE_DVT_CASE3 // 8k
		setVal.value = (0x0330);
#else // 16k
		setVal.value = (0x3330);
#endif
	}
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	setVal.offset = ((0<<31) | 0x203C); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x302f);
	}
	else 
#endif
	{	
#if MDAFE_DVT_CASE1 // 32k
		setVal.value = (0x382f);
#elif MDAFE_DVT_CASE3 // 8k
		setVal.value = (0x302f);
#else // 16k
		setVal.value = (0x342f);
#endif
	}
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2004	0x0001	[0] down link src on	
	setVal.offset = ((0<<31) | 0x2004);  // TODO: ???
	setVal.value = (0x0001);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

	// FIXME: for test
/*	
    setVal.offset = ((0<<31) | 0x2040);
    setVal.value = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x2042);
    setVal.value = (0x0101);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x2012);
	setVal.value = (0x4000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
*/	
// ============here set analog part (voice HS playback)				
// AUDNVREGGLB_CFG0	0x0680	0x0000	[0] RG_AUDGLB_PWRDN_VA32 = 1'b0	
// Enable AUDGLB
	setVal.offset = ((0<<31) | 0x0680); 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG7	0x2098	0x8909	[15] lmn_val_cfg_en
//                                      [14:8] l_200k_val_cfg
//                                      [6:0] l_300k_val_cfg
// Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x2098); 
	setVal.value = (0x8909);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG8	0x209a	0x0909	[14:8] l_394k_val_cfg
//                                      [6:0] l_591k_val_cfg	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x209a); 
	setVal.value = (0x0d0d);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG9	0x209c	0x1309	[14:8] l_800k_val_cfg
//                                      [6:0] m_200k_val_cfg"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x209c); 
	setVal.value = (0x0d10);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG10	0x209e	0x0909	[14:8] m_300k_val_cfg
//                                      [6:0] m_394k_val_cfg"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x209e); 
	setVal.value = (0x1010);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG11	0x20a0	0x0915	[14:8] m_591k_val_cfg
//                                      [6:0] m_800k_val_cfg"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20a0); 
	setVal.value = (0x1010);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG12	0x20a2	0x1414	[14:8] n_200k_val_cfg
//                                      [6:0] n_300k_val_cfg"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20a2); 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG13	0x20a4	0x1414	[14:8] n_394k_val_cfg
//                                      [6:0] n_591k_val_cfg"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20a4); 
	setVal.value = (0x0000);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG14	0x20a6	0x009c	[14:8] n_800k_val_cfg
//                                      [7:0] rg_mode_ch_dly_time"	Classh CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20a6); 
	setVal.value = (0x009c);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG26	0x20be	0x9313	[15] xy_val_cfg_en
//                                      [14:8] x_200k_val_cfg
//                                      [6:0] x_300k_val_cfg"	NCP CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20be); 
	setVal.value = (0x8d0d);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG27	0x20c0	0x1313	[14:8] x_394k_val_cfg
//                                      [6:0] x_591k_val_cfg"	NCP CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20c0); 
	setVal.value = (0x0d0d);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG28	0x20c2	0x1315	[14:8] x_800k_val_cfg
//                                      [6:0] y_200k_val_cfg"	NCP CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20c2); 
	setVal.value = (0x0d10);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG29	0x20c4	0x1515	[14:8] y_300k_val_cfg
//                                      [6:0] y_394k_val_cfg"	NCP CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20c4); 
	setVal.value = (0x1010);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG30	0x20c6	0x1515	[14:8] y_591k_val_cfg
//                                      [6:0] y_800k_val_cfg"	NCP CK fix 591KHz
	setVal.offset = ((0<<31) | 0x20c6); 
	setVal.value = (0x1010);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG1	0x208c	0x0024	"[5] en_manual_mode
//                                      [4] clk_200k_en_man
//                                      [3] en_13_man
//                                      [2] en_12_man
//                                      [1] en_23_man
//                                      [0] en_11_man"	Classh SW mode
	setVal.offset = ((0<<31) | 0x208c); 
	setVal.value = (0x0024);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG2	0x208e	0x2f90	[15:8] rg_cfa1
//                                      [7:0] rg_cfa2"	frame base size & cfifo delay
	setVal.offset = ((0<<31) | 0x208e); 
	setVal.value = (0x2f90);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG3	0x2090	0x1104	[15:8] rg_sdm_delay
//                                      [5:0] rg_5ms_cnt"	sdm delay control and mute frame number setting
	setVal.offset = ((0<<31) | 0x2090); 
	setVal.value = (0x1104);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG4	0x2092	0x2412	[15:8] rg_200k_cnt
//                                      [7:0] rg_ck1_valid_cnt"	Soft start control
	setVal.offset = ((0<<31) | 0x2092); 
	setVal.value = (0x2412);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG5	0x2094	0x0201	[14] rg_ckgatepost_timeout_en
//                                      [13:8] rg_ckgatepost_timeout
//                                      [6] rg_ckgatewait_timeout_en
//                                      [5:0] rg_ckgatewait_timeout"	CK gate time out control
	setVal.offset = ((0<<31) | 0x2094); 
	setVal.value = (0x0201);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG6	0x2096	0x2800	[15:11] rg_levelup_time
//                                      [10] rg_adith
//                                      [9] rg_dither_en
//                                      [8:6] rg_dither_fixed_ck0_ACK1
//                                      [5:3] rg_dither_fixed_ck0_ACK2
//                                      [2:0] rg_dither_fixed_ck0_ACK3"	level up delay time and dither
	setVal.offset = ((0<<31) | 0x2096); 
	setVal.value = (0x2800);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG21	0x20b4	0xa108	[15] rg_aud_intgain（1:use CFG21 gain; 0: use ZCD gain）
//                                      [14:10] rg_audhsgain
//                                      [9:5] rg_audhprgain
//                                      [4:0] rg_audhplgain"	ClassH gain
	setVal.offset = ((0<<31) | 0x20b4); 
	setVal.value = (0xa108);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG22	0x20b6	0x06db	[15:0] rg_fs_1over3	ClassH 1/3 threshold
	setVal.offset = ((0<<31) | 0x20b6); 
	setVal.value = (0x06db);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG23	0x20b8	0x0bd6	[15:0] rg_fs_1over2	ClassH 1/2 threshold
	setVal.offset = ((0<<31) | 0x20b8); 
	setVal.value = (0x0bd6);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG24	0x20ba	0x1492	[15:0] rg_fs_2over3	ClassH 2/3 threshold
	setVal.offset = ((0<<31) | 0x20ba); 
	setVal.value = (0x1492);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG25	0x20bc	0x1740	[15] rg_use_classh_rnd
//                                      [14:8] rg_ncp_ck1_valid_cnt
//                                      [7] rg_ncp_adither
//                                      [6] rg_ncp_dither_en
//                                      [5:3] rg_ncp_dither_fixed_ck0_ACK1_2P
//                                      [2:0] rg_ncp_dither_fixed_ck0_ACK2_2P"	NCP dither
	setVal.offset = ((0<<31) | 0x20bc); 
	setVal.value = (0x1740);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AFE_CLASSH_CFG0	0x208a	0xd518	[15] da_ncp_en
//                                      [14] ncp_on
//                                      [13] mode2_enable
//                                      [12] rg_mode_c_posttimeout_en
//                                      [11:10] rg_classh_mode
//                                      [9] rg_pv_use_250us
//                                      [8] da_pwd_dcdc
//                                      [6] cfifo_loopback_test
//                                      [5] cfifo_input_sel
//                                      [4] upsrc_bypass_cfifo
//                                      [3] anc_bypass_cfifo
//                                      [2] cfifo_en
//                                      [1] voice_mode
//                                      [0] classh_on
// NCP on
	setVal.offset = ((0<<31) | 0x208a); 
	setVal.value = (0xd518);
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


//delay 250us			
	AFE_DELAY(250);
// AFE_CLASSH_CFG0	0x208a	0xd419	"[15] da_ncp_en
//                                      [14] ncp_on
//                                      [13] mode2_enable
//                                      [12] rg_mode_c_posttimeout_en
//                                      [11:10] rg_classh_mode
//                                      [9] rg_pv_use_250us
//                                      [8] da_pwd_dcdc
//                                      [6] cfifo_loopback_test
//                                      [5] cfifo_input_sel
//                                      [4] upsrc_bypass_cfifo
//                                      [3] anc_bypass_cfifo
//                                      [2] cfifo_en
//                                      [1] voice_mode
//                                      [0] classh_on"	ClassH on
	setVal.offset = ((0<<31) | 0x208a); 
	setVal.value = (0xd419); // [REMIND] NCP is already on
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

//delay 250us	
	AFE_DELAY(250);

// AFE_CLASSH_CFG1	0x208c	0x0021	[5] en_manual_mode
//                                      [4] clk_200k_en_man
//                                      [3] en_13_man
//                                      [2] en_12_man
//                                      [1] en_23_man
//                                      [0] en_11_man"	Classh SW mode 1X
	setVal.offset = ((0<<31) | 0x208c); 
	setVal.value = (0x0021); // [REMIND] NCP is already on
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

//delay 250us
	AFE_DELAY(250);

// AUDLDO_NVREG_CFG0	0x06AA	0x0028	[5] RG_LCLDO_DEC_REMOTE_SENSE_VA18 = 1'b1
//                                      [3] RG_LCLDO_DEC_EN_VA32 = 1'b1"	Enable cap-less LDOs (1.6V)
	setVal.offset = ((0<<31) | 0x06AA); 
	setVal.value = (0x0028); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AUDLDO_NVREG_CFG0	0x06AA	0x0068	[6] RG_NVREG_EN_VAUDP32 = 1'b1	Enable NV regulator (-1.6V)
	setVal.offset = ((0<<31) | 0x06AA); 
	setVal.value = (0x0068); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
	setVal.offset = ((0<<31) | 0x066e);  // TODO: for 6331 E2 
	setVal.value = (0x001F); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	

// ZCD_CON0	0x0400	0x0000	[0] RG_AUDZCDENABLE = 1'b0	Disable AUD_ZCD
	setVal.offset = ((0<<31) | 0x0400); 
	setVal.value = (0x0000); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AUDBUF_CFG0	0x0664	0xE008	[15] RG_AUDHPRSCDISABLE_VAUDP32 = 1'b1
//                              [14] RG_AUDHPLSCDISABLE_VAUDP32 = 1'b1
//                              [13] RG_AUDHSSCDISABLE_VAUDP32 = 1'b1 
//                              [4:3] RG_AUDHSMUXINPUTSEL_VAUDP32 = 2'b01"
// "Disable headphone, voice and short-ckt protection. HP MUX is opened, voice MUX is set mute"
	setVal.offset = ((0<<31) | 0x0664); 
	setVal.value = (0xE008); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// IBIASDIST_CFG0	0x0676	0x0092	[9] RG_AUDIBIASPWRDN_VAUDP32 = 0	Enable IBIST
	setVal.offset = ((0<<31) | 0x0676); 
	setVal.value = (0x0092); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// send 00 0404 0F9F 
// ; ZCD_CON2 / Set HPR/HPL gain as minimum (~ -40dB)
	setVal.offset = ((0<<31) | 0x0404); 
	setVal.value = (0x0F9F); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ZCD_CON3	0x0406	0x001F	[4:0] RG_AUDHSGAIN = 5'b11111	Set voice gain as minimum (~ -40dB)
	setVal.offset = ((0<<31) | 0x0406); 
	setVal.value = (0x001F); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// send 00 0666 0900 
// ; AUDBUF_CFG1 / De_OSC of HP and enable output STBENH
	setVal.offset = ((0<<31) | 0x0666); 
	setVal.value = (0x0900); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AUDBUF_CFG2	0x0668	0x0022	[1] RG_HSOUTPUTSTBENH_VAUDP32 = 1'b1	De_OSC of voice, enable output STBENH
	setVal.offset = ((0<<31) | 0x0668); 
	setVal.value = (0x0022); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// send 00 0664 E009 
// ; AUDBUF_CFG0 / Enable voice driver
	setVal.offset = ((0<<31) | 0x0664); 
	setVal.value = (0xE009); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

//	send 00 0666 0940 
//	; AUDBUF_CFG1 / Enable pre-charge buffer
	setVal.offset = ((0<<31) | 0x0666); 
	setVal.value = (0x0940); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// AUDCLKGEN_CFG0	0x0678	0x5501	[0] RG_RSTB_DECODER_VA32 = 1'b1	Enable AUD_CLK
	setVal.offset = ((0<<31) | 0x0678); 
	setVal.value = (0x5501); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AUDDAC_CFG0	0x0662	0x0009	[3] RG_AUD_DAC_PWL_UP_VA32 = 1'b1
//                              [0] RG_AUDDACLPWRUP_VAUDP32 = 1'b1"	Enable L-ch Audio DAC
	setVal.offset = ((0<<31) | 0x0662); 
	setVal.value = (0x0009); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ; ======================Apply digital DC compensation value to DAC=========================

//Apply digital DC compensation value to DAC				
// AUDBUF_CFG0	0x0664	0xE010	[4:3] RG_AUDHSMUXINPUTSEL_VAUDP32 = 2'b10	Switch voice MUX to audio DAC
	setVal.offset = ((0<<31) | 0x0664); 
	setVal.value = (0xE010); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// AUDBUF_CFG0	0x0664	0xE011	[0] RG_AUDHSPWRUP_VAUDP32 = 1'b1	Enable voice driver
	setVal.offset = ((0<<31) | 0x0664); 
	setVal.value = (0xE011); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

//	send 00 0666 0900 
//	; AUDBUF_CFG1 / Disable pre-charge buffer
	setVal.offset = ((0<<31) | 0x0666); 
	setVal.value = (0x0900); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
//	send 00 0668 0020
//	; AUDBUF_CFG2 / Disable De_OSC of voice
	setVal.offset = ((0<<31) | 0x0668); 
	setVal.value = (0x0020); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
// ZCD_CON3	0x0406	0x0009	[4:0] RG_AUDHSGAIN = 5'b01001	Set voice gain as 0dB
	setVal.offset = ((0<<31) | 0x0406); 
	setVal.value = (0x0489); 
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
	
}

#elif defined(MT6752)

void PMIC_AudioConfig(void)
{

    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);


// ================
// ====== DL ======
// ================

// ====== Audio Downlink Power on procedure

// 0x0274   0x0001  [0] RG_CLKSQ_EN_AUD = 1'b1
// Enable CLKSQ 26MHz
    getVal.offset = ((0<<31) | 0x0274);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x0274);
    setVal.value  = (getVal.value | 0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0276   0x0001  [15:0] TOP_CLKSQ_SET = 16'b0000000000000001
// Turn on 26MHz source clock
    getVal.offset = ((0<<31) | 0x0276);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x0276);
    setVal.value  = (getVal.value | 0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x023C   0x3800  [15:0] TOP_CLKSQ_SET = 16'b0011100000000000 = 0x3800
// Turn on AUDNCP_CLKDIV engine clock. Turn on AUD 26M.
    getVal.offset = ((0<<31) | 0x023C);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x023C);
    setVal.value  = (getVal.value | 0x7800); // ori val=0x3800
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 250us
    AFE_DELAY(250);

// 0x2014   0x0000  AUDIO_TOP_CON0
//                  [15] fifo_auto_rst_ctl = 1'b0
//                  [14] afe_ck_div_rst_ctl = 1'b0
//                   [7] pdn_afe_ctl = 1'b0
//                   [6] pdn_dac_ctl = 1'b0
//                   [5] pdn_adc_ctl = 1'b0
//                   [2] pwr_clk_dis_ctl = 1'b0
// Audio system digital clock power down release
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ====== Set digital part

// 0x2020   0x0006  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b0
//                  [2] cci_acd_mode = 1'b1 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b0
// sdm audio fifo clock power on
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x201C   0xC3A1  AFUNC_AUD_CON0
//                     [15] cci_aud_anack_sel = 1'b1
//                  [14:12] cci_audio_fifo_wptr = 3'b100
//                      [9] cci_rand_en = 1'b1
//                      [8] cci_splt_scrmb_clk_on = 1'b1
//                      [7] cci_splt_scrmb_on = 1'b1
//                      [5] cci_zero_pad_disable = 1'b1
//                      [0] cci_scrambler_en = 1'b1
// scrambler clock on enable
    setVal.offset = ((0<<31) | 0x201C);
    setVal.value  = (0xC3A1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2020   0x0003  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b0
//                  [2] cci_acd_mode = 1'b0 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b1
// sdm power on
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2020   0x000B  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b1
//                  [2] cci_acd_mode = 1'b0 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b1
// sdm fifo enable
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2008   0x001E  AFE_DL_SDM_CON1
//                  [5:0] attgain_ctl = 6'b011110
// set attenuation gain
    setVal.offset = ((0<<31) | 0x2008);
    setVal.value  = (0x001E);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2000   0x0001  AFE_UL_DL_CON0
//                  [15] afe_ul_lr_swap = 1'b0
//                  [14] afe_dl_lr_swap = 1'b0
//                   [0] afe_on = 1'b1        
//afe enable
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200a   0x000A  AFE_UL_SRC_CON0_H
//                     [15] c_comb_out_sin_gen_ctl = 1'b0
//                  [13:11] c_digmic_phase_sel_ch2_ctl = 3'b000
//                   [10:8] c_digmic_phase_sel_ch1_ctl = 3'b000
//                      [7] c_two_digital_mic_ctl = 1'b0
//                      [6] ul_mode_3p25m_ch2_ctl = 1'b0
//                      [5] ul_mode_3p25m_ch1_ctl = 1'b0
//                    [4:3] ul_voice_mode_ch2_ctl = 2'b10
//                    [2:1] ul_voice_mode_ch1_ctl = 2'b10
// UL sample rate and mode configure
    setVal.offset = ((0<<31) | 0x200a);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    {
        setVal.value = (0x0000);
    }
    else
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x0014);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0000);
#else // 16k
        setVal.value = (0x000A);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200C   0x0001  AFE_UL_SRC_CON0_L
//                  [5] digmic_3p25m_1p625m_sel_ctl = 1'b0
//                  [2] ul_loop_back_mode_ctl = 1'b0
//                  [1] ul_sdm_3_level_ctl = 1'b0
//                  [0] ul_src_on_tmp_ctl = 1'b1
//UL turn on
    setVal.offset = ((0<<31) | 0x200C);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2038   0x3330  AFE_PMIC_NEWIF_CFG0
//                  [15:12] rg_up8x_rxif_dl_2_input_mode = 4'b0011
//                          0 : time slot1=384, time slot2=23 @ 64K interval (8k)
//                          1 : time slot1= 272, time slot2=23 @ 88.2K interval.
//                          2 : time slot1= 246, time slot2=27 @ 96K interval.
//                          3 : time slot1= 181, time slot2=23 @ 128K interval. (16k)
//                          4 : time slot1= 125, time slot2=23 @ 176.4K interval.
//                          5 : time slot1= 111, time slot2=27 @ 192K interval.
//                          6 : time slot1= 79, time slot2=24 @ 256K interval. (32k)
//                          7 : time slot1= 51, time slot2=23 @ 352.8K interval.
//                          8 : time slot1= 47, time slot2=24 @ 384K interval. (48k)
//                          others : time slot1=up8x_rxif_sync_cnt_table[8:0], time slot2 = up8x_rxif_sync_search_table[4:0].
//                   [11:8] rg_up8x_rxif_invalid_sync_check_round = 4'b0011
//                    [7:4] rg_up8x_rxif_sync_check_round = 4'b0011
    setVal.offset = ((0<<31) | 0x2038);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    { 
        setVal.value = (0x0330);
    }
    else 
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x6330);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0330);
#else // 16k
        setVal.value = (0x3330);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x203C   0x342f  AFE_PMIC_NEWIF_CFG2
// Reference MT6595
	setVal.offset = ((0<<31) | 0x203C); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x302f);
	}
	else 
#endif
	{	
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
		setVal.value = (0x382f);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
		setVal.value = (0x302f);
#else // 16k
		setVal.value = (0x342f);
#endif
	}
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2002   0x3300  AFE_DL_SRC2_CON0_H
//                  [15:12] dl_2_input_mode_ctl = 4'b0011
//                    [9:8] dl_2_output_sel_ctl = 2'b11
    setVal.offset = ((0<<31) | 0x2002);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    { 
        setVal.value = (0x0300);
    }
    else 
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x6300);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0300);
#else // 16k
        setVal.value = (0x3300);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2004   0x0001  AFE_DL_SRC2_CON0_L
//                  [0] dl_2_src_on_tmp_ctl_pre = 1'b1
//turn on dl
    setVal.offset = ((0<<31) | 0x2004);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// ====== special for sine gen table

// 0x2012   0x0000  AFE_TOP_CON0 = 0
//set DL in normal path, not from sine gen table
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2040   0x0080  AFE_SGEN_CFG0
//                  [15:12] c_amp_div_ch1_ctl = 4'b0000
//                   [11:8] c_amp_div_ch2_ctl = 4'b0000
//                      [7] c_dac_en_ctl = 1'b1
//                      [6] c_mute_sw_ctl = 1'b0
//                    [3:0] c_sine_mode_ch1_ctl = 4'b0000
    setVal.offset = ((0<<31) | 0x2040);
    setVal.value  = (0x0080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2042   0x0101  AFE_SGEN_CFG1
//                  [12:8] c_freq_div_ch2_ctl = 5'b00001
//                   [4:0] c_freq_div_ch1_ctl = 5'b00001
    setVal.offset = ((0<<31) | 0x2042);
    setVal.value  = (0x0101);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// ====== here set analog part (voice HS playback)

// 0x0CEE   0x0002  AUDDEC_ANA_CON8
//                  [1] RG_AUDGLB_PWRDN_VA28 = 1'b1	
// Enable AUDGLB
// Reference MT6595, set to 0
    setVal.offset = ((0<<31) | 0x0CEE);
    setVal.value  = (0x0000);//(0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0274   0x0001  TOP_CLKSQ, has done at beginning
//    getVal.offset = ((0<<31) | 0x0274);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0274);
//    setVal.value  = (getVal.value | 0x0001);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D10   0x0001  AUDNCP_CLKDIV_CON1
//                  [0] RG_DIVCKS_ON = 1'b1
// Turn on DA_600K_NCP_VA18
    setVal.offset = ((0<<31) | 0x0D10);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D12   0x002B  AUDNCP_CLKDIV_CON2
//                  [8:0] RG_DIVCKS_PRG = 9'b000101011
// Set NCP clock as 604kHz, 26MHz/43 = 604KHz
    setVal.offset = ((0<<31) | 0x0D12);
    setVal.value  = (0x002B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D0E   0x0001  AUDNCP_CLKDIV_CON0
//                  [0] RG_DIVCKS_CHG = 1'b1
// Toggle RG_DIVCKS_CHG	
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D14   0x0000  AUDNCP_CLKDIV_CON3
//                  [0] RG_DIVCKS_PWD_NCP_ST_SEL = 2'b00
// Set NCP soft start mode as default mode
    setVal.offset = ((0<<31) | 0x0D14);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D14   0x0000  AUDNCP_CLKDIV_CON3
//                  [0] RG_DIVCKS_PWD_NCP = 1'b0	
// Enable NCP
    setVal.offset = ((0<<31) | 0x0D14);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x0840  AUDDEC_ANA_CON6
//                  [11] RG_HCLDO_REMOTE_SENSE_VA18 = 1'b1
//                   [6] RG_HCLDO_EN_VA18 = 1'b1
// Enable cap-less HC LDO (1.5V)
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x0840);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// 0x0CEA   0x28C0  AUDDEC_ANA_CON6
//                  [13] RG_LCLDO_REMOTE_SENSE_VA18 = 1'b1
//                   [7] RG_LCLDO_EN_VA18 = 1'b1
//Enable cap-less LC LDO (1.5V)
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x28C0);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEC   0x8000  AUDDEC_ANA_CON7
//                  [15] RG_NVREG_EN_VAUDP15 = 1'b1
// Enable NV regulator (-1.5V)
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0800   0x0000  ZCD_CON0
//                  [0] RG_AUDZCDENABLE = 1'b0
//Disable AUD_ZCD
    setVal.offset = ((0<<31) | 0x0800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEC   0x8400  AUDDEC_ANA_CON7
//                  [10:7] RG_AUDPMU_RESERVED_VA18 = 4'b1000
// Short AUD_REFN ESD resistor
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE080  AUDDEC_ANA_CON0
//                   [15] RG_AUDHPRSCDISABLE_VAUDP15 = 1'b1
//                   [14] RG_AUDHPLSCDISABLE_VAUDP15 = 1'b1
//                   [13] RG_AUDHSSCDISABLE_VAUDP15 = 1'b1 
//                  [8:7] RG_AUDHSMUXINPUTSEL_VAUDP15 = 2'b01
// Disable headphone, voice and short-ckt protection. HP MUX is opened, voice MUX is set mute.
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x28C0  AUDDEC_ANA_CON6
//                  [0] RG_AUDIBIASPWRDN_VAUDP15 = 0
// Enable IBIST
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x28C0);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CE6   0x0400  AUDDEC_ANA_CON4
//                  [15:8] RG_ABIDEC_RESERVED_VAUDP15 = 8'b00000100
// Enable HS drivers bias circuit
    setVal.offset = ((0<<31) | 0x0CE6);
    setVal.value  = (0x0400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 50us
    AFE_DELAY(50);

// 0x0806   0x001F  ZCD_CON3
//                  [4:0]RG_AUDHSGAIN = 5'b11111
// Set voice gain as minimum (~ -40dB)
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x001F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CE0   0x1000  AUDDEC_ANA_CON1
//                  [12] RG_HSOUTPUTSTBENH_VAUDP15 = 1'b1
// De_OSC of voice, enable output STBENH
    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x1000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x28C2  AUDDEC_ANA_CON6
//                  [1] RG_RSTB_DECODER_VA28 = 1'b1
// Enable AUD_CLK
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x2BC6);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE089  AUDDEC_ANA_CON0
//                  [3] RG_AUD_DAC_PWL_UP_VA28 = 1'b1
//                  [0] RG_AUDDACLPWRUP_VAUDP15 = 1'b1
// Enable Audio DAC
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE089);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ====== Apply digital DC compensation value to DAC								

// 0x0CDE   0xE109  AUDDEC_ANA_CON0
//                  [8:7] RG_AUDHSMUXINPUTSEL_VAUDP15 = 2'b10
// Switch HS MUX to audio DAC
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE109);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE119  AUDDEC_ANA_CON0
//          [4] RG_AUDHSPWRUP_VAUDP15 = 1'b1
// Enable voice driver
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE119);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 50us
    AFE_DELAY(50);

// 0x0CEC   0x8000  AUDDEC_ANA_CON7
//                  [15] RG_AUDPMU_RESERVED_VA18 = 4'b0000
// Open AUD_REFN ESD resistor
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0806   0x0009  ZCD_CON3
//                  [4:0] RG_AUDHSGAIN = 5'b01001
// Set HS gain to 0dB, step by step
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x0009);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 250us
    AFE_DELAY(250);


// ================
// ====== UL ======
// ================
// MIC0 and MIC2 are ON

// 0x0A40   0x0301  LDO_VCON1
    setVal.offset = ((0<<31) | 0x0A40);
    setVal.value  = (0x0301);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0A04   0x8102  LDO_CON2
    setVal.offset = ((0<<31) | 0x0A04);
    setVal.value  = (0x8102);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEE   0x0002  AUDDEC_ANA_CON8
//                  [1] RG_AUDGLB_PWRDN_VA28 = 1'b1	
// Enable AUDGLB
// Reference MT6595, set to 0
    setVal.offset = ((0<<31) | 0x0CEE);
    setVal.value  = (0x0000);//(0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0274   0x0001  TOP_CLKSQ, has done at beginning
//    getVal.offset = ((0<<31) | 0x0274);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0274);
//    setVal.value  = (getVal.value | 0x0001);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x0005  AUDDEC_ANA_CON6
//        =>0x0004
// script do not do this...
//    getVal.offset = ((0<<31) | 0x0CEA);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0CEA);
//    setVal.value  = (getVal.value | 0x0004);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF6   0x0000  AUDENC_ANA_CON3
    setVal.offset = ((0<<31) | 0x0CF6);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x0105  AUDDEC_ANA_CON6
//        =>0x0104
//    getVal.offset = ((0<<31) | 0x0CEA);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0CEA);
//    setVal.value  = (getVal.value | 0x2BC6);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x2BC6);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEC   0x0006  AUDDEC_ANA_CON7
//    getVal.offset = ((0<<31) | 0x0CEC);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0CEC);
//    setVal.value  = (getVal.value | 0x8006);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D02   0x0201  AUDENC_ANA_CON9
    setVal.offset = ((0<<31) | 0x0D02);
    setVal.value  = (0x0201);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF0   0x0041  AUDENC_ANA_CON0
    setVal.offset = ((0<<31) | 0x0CF0);
    setVal.value  = (0x0041);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF2   0x00C1  AUDENC_ANA_CON1
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x00C1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D0C   0x0002  AUDENC_ANA_CON15
    setVal.offset = ((0<<31) | 0x0D0C);
    setVal.value  = (0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D0C   0x0033  AUDENC_ANA_CON15
    setVal.offset = ((0<<31) | 0x0D0C);
    setVal.value  = (0x0033);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF6   0x0800  AUDENC_ANA_CON3
    setVal.offset = ((0<<31) | 0x0CF6);
    setVal.value  = (0x0800);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF0   0x0541  AUDENC_ANA_CON0
    setVal.offset = ((0<<31) | 0x0CF0);
    setVal.value  = (0x0541);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CF2   0x05C1  AUDENC_ANA_CON1
    setVal.offset = ((0<<31) | 0x0CF2);
    setVal.value  = (0x05C1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0238   0xCEFC  TOP_CKPDN_CON0
// on or off?
    getVal.offset = ((0<<31) | 0x0238);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x0238);
    setVal.value  = (getVal.value & 0x86FC);//(0x86FC);//(0xCEFC);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2014   0x0040  AUDIO_TOP_CON0
// down-link power down => should not do

// 0x2012   0x0000  AFE_TOP_CON0
// has done at beginning

// 0x2000   0x0001  AFE_UL_DL_CON0
// has done at beginning

// 0x200A   0x000A  AFE_UL_SRC_CON0_H
// has done at beginning

// 0x200C   0x0001  AFE_UL_SRC_CON0_L
// has done at beginning

}

#endif


// void l1sp_configApAfeHwForBt(void)
void ApAudSys_config_forBt(void)
{
#if defined(MT6589)

	// GPIO set to external
	/*
	WriteREG(0xA00050D0, 0x5000 ); // GPIO_DIR13 
	WriteREG(0xA00050E0, 0x0001 ); // GPIO_DIR14
	WriteREG(0xA0005EC0, 0x1248 ); // GPIO_MODE2C, 
	*/
	
	// MAIN setting for interconnection
	WriteREG(AUDIO_TOP_CON0, 0x00004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	WriteREG(AFE_DAC_CON0, 0x00000001);

	WriteREG(AP_AFE_CONN1, 0x00000000); 
	WriteREG(AP_AFE_CONN2, 0x00000000); 	
	WriteREG(AP_AFE_CONN3, 0x00400000); // i14, o2 
	WriteREG(AP_AFE_CONN4, 0x00000000); 

	WriteREG(AFE_GAIN2_CON0, 0x0000c801);
	WriteREG(AFE_GAIN2_CON, 0x01040000); // MD1
	WriteREG(AFE_GAIN2_CON2, 0x000000C0);

	
	WriteREG(AFE_DAIBT_CON0, 0x105F);
	WriteREG(AFE_MRGIF_CON, 0x00900001);
	
	// MD2
	WriteREG(PCM_INTF_CON1, 0x0000006F);
	// WriteREG(PCM_INTF_CON2, 0x00000000);
	// MD1
	WriteREG(PCM_INTF_CON, 0x0000000F);
#elif defined(MT6572)
// no hw pcm to BT
#elif defined(MT6582)
// no hw pcm to BT
#endif
}


#if defined(MT6752)
void PMIC_AudioConfigForAPAUDSYSDVT(void)
{

    DCL_HANDLE handle;
    PMU_CTRL_MISC_SET_REGISTER_VALUE setVal;
    PMU_CTRL_MISC_GET_REGISTER_VALUE getVal;

    handle = DclPMU_Open(DCL_PMU, FLAGS_NONE);


// ================
// ====== DL ======
// ================

// ====== Audio Downlink Power on procedure

// 0x0274   0x0001  [0] RG_CLKSQ_EN_AUD = 1'b1
// Enable CLKSQ 26MHz
    getVal.offset = ((0<<31) | 0x0274);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x0274);
    setVal.value  = (getVal.value | 0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0276   0x0001  [15:0] TOP_CLKSQ_SET = 16'b0000000000000001
// Turn on 26MHz source clock
    getVal.offset = ((0<<31) | 0x0276);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x0276);
    setVal.value  = (getVal.value | 0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x023C   0x3800  [15:0] TOP_CLKSQ_SET = 16'b0011100000000000 = 0x3800
// Turn on AUDNCP_CLKDIV engine clock. Turn on AUD 26M.
    getVal.offset = ((0<<31) | 0x023C);
    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
    setVal.offset = ((0<<31) | 0x023C);
    setVal.value  = (getVal.value | 0x7800); // ori val=0x3800
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 250us
    AFE_DELAY(250);

// 0x2014   0x0000  AUDIO_TOP_CON0
//                  [15] fifo_auto_rst_ctl = 1'b0
//                  [14] afe_ck_div_rst_ctl = 1'b0
//                   [7] pdn_afe_ctl = 1'b0
//                   [6] pdn_dac_ctl = 1'b0
//                   [5] pdn_adc_ctl = 1'b0
//                   [2] pwr_clk_dis_ctl = 1'b0
// Audio system digital clock power down release
    setVal.offset = ((0<<31) | 0x2014);
    setVal.value  = (0xC000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ====== Set digital part

// 0x2020   0x0006  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b0
//                  [2] cci_acd_mode = 1'b1 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b0
// sdm audio fifo clock power on
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0006);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x201C   0xC3A1  AFUNC_AUD_CON0
//                     [15] cci_aud_anack_sel = 1'b1
//                  [14:12] cci_audio_fifo_wptr = 3'b100
//                      [9] cci_rand_en = 1'b1
//                      [8] cci_splt_scrmb_clk_on = 1'b1
//                      [7] cci_splt_scrmb_on = 1'b1
//                      [5] cci_zero_pad_disable = 1'b1
//                      [0] cci_scrambler_en = 1'b1
// scrambler clock on enable
    setVal.offset = ((0<<31) | 0x201C);
    setVal.value  = (0xC3A1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2020   0x0003  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b0
//                  [2] cci_acd_mode = 1'b0 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b1
// sdm power on
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x0003);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2020   0x000B  AFUNC_AUD_CON2
//                  [7] cci_aud_dac_ana_mute = 1'b0
//                  [4] cci_audio_fifo_clkin_inv = 1'b0
//                  [3] cci_audio_fifo_enable = 1'b1
//                  [2] cci_acd_mode = 1'b0 
//                  [1] cci_afifo_clk_pwdb = 1'b1
//                  [0] cci_acd_func_rstb = 1'b1
// sdm fifo enable
    setVal.offset = ((0<<31) | 0x2020);
    setVal.value  = (0x000B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2008   0x001E  AFE_DL_SDM_CON1
//                  [5:0] attgain_ctl = 6'b011110
// set attenuation gain
    setVal.offset = ((0<<31) | 0x2008);
    setVal.value  = (0x001E);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2000   0x0001  AFE_UL_DL_CON0
//                  [15] afe_ul_lr_swap = 1'b0
//                  [14] afe_dl_lr_swap = 1'b0
//                   [0] afe_on = 1'b1        
//afe enable
    setVal.offset = ((0<<31) | 0x2000);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200a   0x000A  AFE_UL_SRC_CON0_H
//                     [15] c_comb_out_sin_gen_ctl = 1'b0
//                  [13:11] c_digmic_phase_sel_ch2_ctl = 3'b000
//                   [10:8] c_digmic_phase_sel_ch1_ctl = 3'b000
//                      [7] c_two_digital_mic_ctl = 1'b0
//                      [6] ul_mode_3p25m_ch2_ctl = 1'b0
//                      [5] ul_mode_3p25m_ch1_ctl = 1'b0
//                    [4:3] ul_voice_mode_ch2_ctl = 2'b10
//                    [2:1] ul_voice_mode_ch1_ctl = 2'b10
// UL sample rate and mode configure
    setVal.offset = ((0<<31) | 0x200a);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    {
        setVal.value = (0x0000);
    }
    else
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x0014);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0000);
#else // 16k
        setVal.value = (0x000A);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x200C   0x0001  AFE_UL_SRC_CON0_L
//                  [5] digmic_3p25m_1p625m_sel_ctl = 1'b0
//                  [2] ul_loop_back_mode_ctl = 1'b0
//                  [1] ul_sdm_3_level_ctl = 1'b0
//                  [0] ul_src_on_tmp_ctl = 1'b1
//UL turn on
//    setVal.offset = ((0<<31) | 0x200C);
//    setVal.value  = (0x0001);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2038   0x3330  AFE_PMIC_NEWIF_CFG0
//                  [15:12] rg_up8x_rxif_dl_2_input_mode = 4'b0011
//                          0 : time slot1=384, time slot2=23 @ 64K interval (8k)
//                          1 : time slot1= 272, time slot2=23 @ 88.2K interval.
//                          2 : time slot1= 246, time slot2=27 @ 96K interval.
//                          3 : time slot1= 181, time slot2=23 @ 128K interval. (16k)
//                          4 : time slot1= 125, time slot2=23 @ 176.4K interval.
//                          5 : time slot1= 111, time slot2=27 @ 192K interval.
//                          6 : time slot1= 79, time slot2=24 @ 256K interval. (32k)
//                          7 : time slot1= 51, time slot2=23 @ 352.8K interval.
//                          8 : time slot1= 47, time slot2=24 @ 384K interval. (48k)
//                          others : time slot1=up8x_rxif_sync_cnt_table[8:0], time slot2 = up8x_rxif_sync_search_table[4:0].
//                   [11:8] rg_up8x_rxif_invalid_sync_check_round = 4'b0011
//                    [7:4] rg_up8x_rxif_sync_check_round = 4'b0011
    setVal.offset = ((0<<31) | 0x2038);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    { 
        setVal.value = (0x0330);
    }
    else 
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x6330);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0330);
#else // 16k
        setVal.value = (0x3330);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x203C   0x342f  AFE_PMIC_NEWIF_CFG2
// Reference MT6595
//???
	setVal.offset = ((0<<31) | 0x203C); 
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		setVal.value = (0x302f);
	}
	else 
#endif
	{	
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
		setVal.value = (0x382f);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
		setVal.value = (0x302f);
#else // 16k
		setVal.value = (0x342f);
#endif
	}
	DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2002   0x3300  AFE_DL_SRC2_CON0_H
//                  [15:12] dl_2_input_mode_ctl = 4'b0011
//                    [9:8] dl_2_output_sel_ctl = 2'b11
    setVal.offset = ((0<<31) | 0x2002);
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    { 
        setVal.value = (0x0300);
    }
    else 
#endif
    {
#if (MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K) // 32k
        setVal.value = (0x6300);
#elif (MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K) // 8k
        setVal.value = (0x0300);
#else // 16k
        setVal.value = (0x3300);
#endif
    }
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2004   0x0001  AFE_DL_SRC2_CON0_L
//                  [0] dl_2_src_on_tmp_ctl_pre = 1'b1
//turn on dl
    setVal.offset = ((0<<31) | 0x2004);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// ====== special for sine gen table

// 0x2012   0x0000  AFE_TOP_CON0 = 0
//set DL in normal path, not from sine gen table
    setVal.offset = ((0<<31) | 0x2012);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2040   0x0080  AFE_SGEN_CFG0
//                  [15:12] c_amp_div_ch1_ctl = 4'b0000
//                   [11:8] c_amp_div_ch2_ctl = 4'b0000
//                      [7] c_dac_en_ctl = 1'b1
//                      [6] c_mute_sw_ctl = 1'b0
//                    [3:0] c_sine_mode_ch1_ctl = 4'b0000
    setVal.offset = ((0<<31) | 0x2040);
    setVal.value  = (0x0080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x2042   0x0101  AFE_SGEN_CFG1
//                  [12:8] c_freq_div_ch2_ctl = 5'b00001
//                   [4:0] c_freq_div_ch1_ctl = 5'b00001
    setVal.offset = ((0<<31) | 0x2042);
    setVal.value  = (0x0101);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// ====== here set analog part (voice HS playback)

// 0x0CEE   0x0002  AUDDEC_ANA_CON8
//                  [1] RG_AUDGLB_PWRDN_VA28 = 1'b1	
// Enable AUDGLB
// Reference MT6595, set to 0
    setVal.offset = ((0<<31) | 0x0CEE);
    setVal.value  = (0x0000);//(0x0002);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0274   0x0001  TOP_CLKSQ, has done at beginning
//    getVal.offset = ((0<<31) | 0x0274);
//    DclPMU_Control(handle, MISC_GET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&getVal);
//    setVal.offset = ((0<<31) | 0x0274);
//    setVal.value  = (getVal.value | 0x0001);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D10   0x0001  AUDNCP_CLKDIV_CON1
//                  [0] RG_DIVCKS_ON = 1'b1
// Turn on DA_600K_NCP_VA18
    setVal.offset = ((0<<31) | 0x0D10);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D12   0x002B  AUDNCP_CLKDIV_CON2
//                  [8:0] RG_DIVCKS_PRG = 9'b000101011
// Set NCP clock as 604kHz, 26MHz/43 = 604KHz
    setVal.offset = ((0<<31) | 0x0D12);
    setVal.value  = (0x002B);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D0E   0x0001  AUDNCP_CLKDIV_CON0
//                  [0] RG_DIVCKS_CHG = 1'b1
// Toggle RG_DIVCKS_CHG	
    setVal.offset = ((0<<31) | 0x0D0E);
    setVal.value  = (0x0001);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D14   0x0000  AUDNCP_CLKDIV_CON3
//                  [0] RG_DIVCKS_PWD_NCP_ST_SEL = 2'b00
// Set NCP soft start mode as default mode
    setVal.offset = ((0<<31) | 0x0D14);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0D14   0x0000  AUDNCP_CLKDIV_CON3
//                  [0] RG_DIVCKS_PWD_NCP = 1'b0	
// Enable NCP
    setVal.offset = ((0<<31) | 0x0D14);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x0840  AUDDEC_ANA_CON6
//                  [11] RG_HCLDO_REMOTE_SENSE_VA18 = 1'b1
//                   [6] RG_HCLDO_EN_VA18 = 1'b1
// Enable cap-less HC LDO (1.5V)
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x0841);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);


// 0x0CEA   0x28C0  AUDDEC_ANA_CON6
//                  [13] RG_LCLDO_REMOTE_SENSE_VA18 = 1'b1
//                   [7] RG_LCLDO_EN_VA18 = 1'b1
//Enable cap-less LC LDO (1.5V)
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x28C1);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEC   0x8000  AUDDEC_ANA_CON7
//                  [15] RG_NVREG_EN_VAUDP15 = 1'b1
// Enable NV regulator (-1.5V)
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0800   0x0000  ZCD_CON0
//                  [0] RG_AUDZCDENABLE = 1'b0
//Disable AUD_ZCD
    setVal.offset = ((0<<31) | 0x0800);
    setVal.value  = (0x0000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEC   0x8400  AUDDEC_ANA_CON7
//                  [10:7] RG_AUDPMU_RESERVED_VA18 = 4'b1000
// Short AUD_REFN ESD resistor
    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8400);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE080  AUDDEC_ANA_CON0
//                   [15] RG_AUDHPRSCDISABLE_VAUDP15 = 1'b1
//                   [14] RG_AUDHPLSCDISABLE_VAUDP15 = 1'b1
//                   [13] RG_AUDHSSCDISABLE_VAUDP15 = 1'b1 
//                  [8:7] RG_AUDHSMUXINPUTSEL_VAUDP15 = 2'b01
// Disable headphone, voice and short-ckt protection. HP MUX is opened, voice MUX is set mute.
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE080);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x28C0  AUDDEC_ANA_CON6
//                  [0] RG_AUDIBIASPWRDN_VAUDP15 = 0
// Enable IBIST
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x28C0);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CE6   0x0400  AUDDEC_ANA_CON4
//                  [15:8] RG_ABIDEC_RESERVED_VAUDP15 = 8'b00000100
// Enable HS drivers bias circuit
    setVal.offset = ((0<<31) | 0x0CE6);
    setVal.value  = (0x0700);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 50us
    AFE_DELAY(50);

    setVal.offset = ((0<<31) | 0x0804);
    setVal.value  = (0x0F9F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0806   0x001F  ZCD_CON3
//                  [4:0]RG_AUDHSGAIN = 5'b11111
// Set voice gain as minimum (~ -40dB)
    setVal.offset = ((0<<31) | 0x0806);
    setVal.value  = (0x001F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CE0   0x1000  AUDDEC_ANA_CON1
//                  [12] RG_HSOUTPUTSTBENH_VAUDP15 = 1'b1
// De_OSC of voice, enable output STBENH
    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x0480);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x1480);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CEA   0x28C2  AUDDEC_ANA_CON6
//                  [1] RG_RSTB_DECODER_VA28 = 1'b1
// Enable AUD_CLK
//    setVal.offset = ((0<<31) | 0x0CEA);
//    setVal.value  = (0x2BC6);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE089  AUDDEC_ANA_CON0
//                  [3] RG_AUD_DAC_PWL_UP_VA28 = 1'b1
//                  [0] RG_AUDDACLPWRUP_VAUDP15 = 1'b1
// Enable Audio DAC
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE090);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// ====== Apply digital DC compensation value to DAC								

// 0x0CDE   0xE109  AUDDEC_ANA_CON0
//                  [8:7] RG_AUDHSMUXINPUTSEL_VAUDP15 = 2'b10
// Switch HS MUX to audio DAC
//    setVal.offset = ((0<<31) | 0x0CDE);
//    setVal.value  = (0xE109);
//    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0CDE   0xE119  AUDDEC_ANA_CON0
//          [4] RG_AUDHSPWRUP_VAUDP15 = 1'b1
// Enable voice driver
    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x14A0);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// delay 50us
    AFE_DELAY(50);

// 0x0CEC   0x8000  AUDDEC_ANA_CON7
//                  [15] RG_AUDPMU_RESERVED_VA18 = 4'b0000
// Open AUD_REFN ESD resistor
    setVal.offset = ((0<<31) | 0x0CEA);
    setVal.value  = (0x2AC2);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

// 0x0806   0x0009  ZCD_CON3
//                  [4:0] RG_AUDHSGAIN = 5'b01001
// Set HS gain to 0dB, step by step
    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xE09F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xF49F);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xF4FF);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    AFE_DELAY(50);

    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x1480);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CE0);
    setVal.value  = (0x0480);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CDE);
    setVal.value  = (0xF4EF);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CE6);
    setVal.value  = (0x0300);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0CEC);
    setVal.value  = (0x8000);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);

    setVal.offset = ((0<<31) | 0x0804);
    setVal.value  = (0x0489);
    DclPMU_Control(handle, MISC_SET_REGISTER_VALUE, (DCL_CTRL_DATA_T *)&setVal);
// delay 250us
    AFE_DELAY(250);
}
#endif //#if defined(MT6572)


void ApAudSys_config(void)
{
	
#if defined(IC_MODULE_TEST)
	// For SLT test, these register settings would affect the AFE test case.
#else   // Normal usage, IC_MODULE_TEST

#if defined(MT6589)
	// for second modem with slave mode
	// vSetASRC
	// WriteREG(AFE_ASRC_CON1, 0x00000cb2);
	// WriteREG(AFE_ASRC_CON2, 0x00400000);
	// WriteREG(AFE_ASRC_CON3, 0x00400000);
	// WriteREG(AFE_ASRC_CON4, 0x00000cb2);
	// WriteREG(AFE_ASRC_CON7, 0x00000659);
	
	// vASRCEnable
	// WriteREG(AFE_ASRC_CON6, 0x00000000);
	// WriteREG(AFE_ASRC_CON0, 0x06003030);

	// MAIN setting for interconnection
	WriteREG(AUDIO_TOP_CON0, 0x00004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	WriteREG(AFE_DAC_CON0, 0x00000001);
	WriteREG(AP_AFE_CONN1, 0x02000000); // MD2
	WriteREG(AP_AFE_CONN2, 0x24000200); // MD2	
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1
	WriteREG(AP_AFE_CONN4, 0x00012001); // MD1

	// sidetone
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);
	

	// MD2
	WriteREG(PCM_INTF_CON1, 0x0000006F);
	// WriteREG(PCM_INTF_CON2, 0x00000000);
	// MD1
	WriteREG(PCM_INTF_CON, 0x0000000F);

	// i2s to external dac
	WriteREG(AFE_I2S_CON1, 0x00000409); //dac 16k
	WriteREG(AFE_I2S_CON2, 0x00000409); //adc 16k


#elif defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)


	WriteREG(AUDIO_TOP_CON0, 0x60004000);
	WriteREG(AFE_TOP_CON0, 0x00000000);
	
	// MAIN setting for interconnection
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, i14->o3
	WriteREG(AP_AFE_CONN4, 0x00012001); // MD1, i4->o18, i3->o17, i14->o4

	// sidetone
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);

	// MD1
#if defined(__ENABLE_SPEECH_DVT__)
    if (Is_Sph_DVT_BT_Mode_NB())
    {   // 8k setting
        WriteREG(PCM_INTF_CON, 0x00000007);
        
	    // new interface with SRC	
	    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03F87201);
	    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580);
        
	    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x03001823);
	    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
		
	    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001);
	    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    }
    else
#endif // defined(__ENABLE_SPEECH_DVT__)
    {   // 16k setting
        WriteREG(PCM_INTF_CON, 0x0000000F); // 16k: 0x0000000F, 8k: 0x00000007
        
	    // new interface with SRC	
	    WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03F87201);
	    WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580);
        
	    WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x33001823); // DL 16k : 0x33001823, DL 8k : 0x03001823
	    WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
		
	    WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // UL 16k : 0x000A0001, UL 8k : 0x00000001
	    WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    }
	
	WriteREG(AFE_ADDA_TOP_CON0, 0x00000000);
	WriteREG(AFE_I2S_CON1, 0x0000040B); //I2S out, 要和ADDA一起開,位置在0x0034
	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001);
	WriteREG(AFE_DAC_CON0, 0x00000001); // keep in last, confirm by Andrew

	PMIC_AudioConfig_Loopback();

#elif defined(MT6595)

	// [RIMIND] Require by ShihHsin Tai, 	0x1000_629c = 32’b1101 
	WriteREG(AUDIO_PWR, 	0x0000000D);
	
   WriteREG(AUDIO_TOP_CON0, 0x00004000); // 0x11220000
	 
	// MAIN setting for interconnection
#if MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3
	WriteREG(AP_AFE_CONN3, 0x0021000); 
	//WriteREG(AP_AFE_CONN4, 0x00012001); // by pass ASRC
	WriteREG(AP_AFE_CONN5, 0x00084001);
#elif APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K
	WriteREG(AP_AFE_CONN3, 0x08001000);  // [27]i14->o03, [12]i14->o00
	WriteREG(AP_AFE_CONN6, 0x00012000);  // [16]i21 -> o4, [13]i21->o01
#else
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, i14->o3
	WriteREG(AP_AFE_CONN4, 0x00012001); // MD1, i4->o18, i3->o17, i14->o4
#endif

#if APAUDSYS_DVT_8K
	WriteREG(AFE_SGEN_CON0, 0xac0e20e1); //sine gen from 017, 018
#elif APAUDSYS_DVT_16K
	WriteREG(AFE_SGEN_CON0, 0xac3e23e1); //sine gen from 017, 018
#elif APAUDSYS_DVT_32K
	WriteREG(AFE_SGEN_CON0, 0xac8e28e1); //sine gen from 017, 018
#endif

	// sidetone disable 
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);

	// AP PCM setting
#if APAUDSYS_DVT_RF2 	// ASRC
#if APAUDSYS_DVT_16K
	WriteREG(AP_AUDSYS_base + 0x0704, 0x0004c2c0);
	WriteREG(AP_AUDSYS_base + 0x0708, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x070c, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x0710, 0x0004c2c0);
	WriteREG(AP_AUDSYS_base + 0x071c, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x0718, 0x00bf188f);
	WriteREG(AP_AUDSYS_base + 0x0700, 0x06003031);
	WriteREG(AP_AUDSYS_base + 0x0744, 0x0004c2c0);
	WriteREG(AP_AUDSYS_base + 0x0748, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x074c, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x0750, 0x0004c2c0);
	WriteREG(AP_AUDSYS_base + 0x075c, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x0758, 0x00bf188f);
	WriteREG(AP_AUDSYS_base + 0x0740, 0x03003031);
#elif APAUDSYS_DVT_32K	
	WriteREG(AP_AUDSYS_base + 0x0704, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x0708, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x070c, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x0710, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x071c, 0x000130b0);
	WriteREG(AP_AUDSYS_base + 0x0718, 0x00bf188f);
	WriteREG(AP_AUDSYS_base + 0x0700, 0x06003031);
	WriteREG(AP_AUDSYS_base + 0x0744, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x0748, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x074c, 0x00400000);
	WriteREG(AP_AUDSYS_base + 0x0750, 0x00026160);
	WriteREG(AP_AUDSYS_base + 0x075c, 0x000130b0);
	WriteREG(AP_AUDSYS_base + 0x0758, 0x00bf188f);
	WriteREG(AP_AUDSYS_base + 0x0740, 0x03003031);
#endif

#if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K
   WriteREG(PCM_INTF_CON, 0x00000017);
#elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K
	WriteREG(PCM_INTF_CON, 0x00000007);
#else // 16 k
	WriteREG(PCM_INTF_CON, 0x0000000F); // 16k: 0x0000004F, 8k: 0x00000007
#endif

#else // AFIFO

	// MD1 PCMsetting
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{ 
		WriteREG(PCM_INTF_CON, 0x00000047);
	}
	else 
#endif
	{

#if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K
   	WriteREG(PCM_INTF_CON, 0x00000057);
#elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K
		WriteREG(PCM_INTF_CON, 0x00000047);
#else
		WriteREG(PCM_INTF_CON, 0x0000004F); // 16k: 0x0000004F, 8k: 0x00000007
#endif
	}

#endif // APAUDSYS_DVT_RF2


	// new interface
	// WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03F87201);
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013c

	// ADDA
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{
		WriteREG(AFE_I2S_CON1, 0x0000009);
		WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		
		WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
		WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
		WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
	}
	else 
#endif
		{
#if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K // 32k
		WriteREG(AFE_DAC_CON1, 0x00000800);
		WriteREG(AFE_I2S_CON1, 0x00000809);
		WriteREG(AFE_I2S_CON3, 0x00000809);	

		WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
		WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
		WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
#elif MDAFE_DVT_CASE2 || APAUDSYS_DVT_16K // 16k
		WriteREG(AFE_DAC_CON1, 0x00000400);
		WriteREG(AFE_I2S_CON1, 0x00000409);
		WriteREG(AFE_I2S_CON3, 0x00000409);
			
		WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
		WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
		WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
#elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K// 8k
		WriteREG(AFE_DAC_CON1, 0x00000000);
		WriteREG(AFE_I2S_CON1, 0x00000009);
		WriteREG(AFE_I2S_CON3, 0x00000009);

		WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
		WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
		WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
#else // 16k
		WriteREG(AFE_I2S_CON1, 0x00000409);
		WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		
		WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
		WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
		WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
#endif
	}

	// I2S0 and GPIO Setting
#if MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K
	// add one more GPIO for input 	
	(*(volatile kal_uint32 *)(0xA0005B00) |= (0x70)); // bit[7:4] I2S 0 Driving power
	WriteREG((0xa0005720), 0x00000489);
	WriteREG((0xa0005730), 0x0000104A);
	WriteREG(AFE_I2S_CON, 0x10000009); // add inverse
#endif

	WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010

	PMIC_AudioConfig();

#elif defined(MT6752)
//==============================
//  For MT6752 Start
//==============================

	// [RIMIND] Require by ShihHsin Tai, 	0x1000_629c = 32’b1101 
	WriteREG(AUDIO_PWR, 	0x0000000D);

	WriteREG(AUDIO_TOP_CON0, 0x00004000); //script=0x60004000
	WriteREG(AFE_TOP_CON0, 0x00000000); //not in script
	//WriteREG(AFE_DAC_CON0, 0x00000001); // 0x11220010, not in script

	// MAIN setting for interconnection
#if MDAFE_DVT_CASE1 || MDAFE_DVT_CASE2 || MDAFE_DVT_CASE3
	WriteREG(AP_AFE_CONN0, 0x00000000); // from script
	WriteREG(AP_AFE_CONN1, 0x02000000); // MD2, I09->O03
	WriteREG(AP_AFE_CONN2, 0x24000200); // MD2,	I04->O08, I03->O07, I09->O04
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, I14->O03
	WriteREG(AP_AFE_CONN4, 0x00012001); // MD1, I04->O18, I03->O17, I14->O04
	WriteREG(AP_AFE_CONN5, 0x00000000);
	WriteREG(AP_AFE_CONN6, 0x00000000);
#elif APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K
    #if APAUDSYS_DVT_RF2
	WriteREG(AP_AFE_CONN0, 0x00000000);
	WriteREG(AP_AFE_CONN1, 0x02000000); // MD2, I09->O03
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x00000000);
	WriteREG(AP_AFE_CONN4, 0x00000000);
	WriteREG(AP_AFE_CONN5, 0x00000000);
	WriteREG(AP_AFE_CONN6, 0x00000000);
	WriteREG(AP_AFE_CONN9, 0x00200000); // MD2, I22->O04
    #else //#if APAUDSYS_DVT_RF2
	WriteREG(AP_AFE_CONN0, 0x00000000);
	WriteREG(AP_AFE_CONN1, 0x00000000);
	WriteREG(AP_AFE_CONN2, 0x00000000);
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, I14->O03
	WriteREG(AP_AFE_CONN4, 0x00000000);
	WriteREG(AP_AFE_CONN5, 0x00000000);
	WriteREG(AP_AFE_CONN6, 0x00010000); // MD1, I21->O04
	#endif //#if APAUDSYS_DVT_RF2
#else
	WriteREG(AP_AFE_CONN0, 0x00000000); // from script
	WriteREG(AP_AFE_CONN1, 0x02000000); // MD2, I09->O03
	WriteREG(AP_AFE_CONN2, 0x24000200); // MD2,	I04->O08, I03->O07, I09->O04
	WriteREG(AP_AFE_CONN3, 0x08000000); // MD1, I14->O03
	WriteREG(AP_AFE_CONN4, 0x00012001); // MD1, I04->O18, I03->O17, I14->O04
	WriteREG(AP_AFE_CONN5, 0x00000000);
	WriteREG(AP_AFE_CONN6, 0x00000000);
#endif

#if APAUDSYS_DVT_8K
	WriteREG(AFE_SGEN_CON0, 0x8C0A40A8); //sinegen: O13 and O14,  8k, ch2 (08k/64)*4=500Hz, ch1 (08k/64)*8=1kHz
#elif APAUDSYS_DVT_16K
	WriteREG(AFE_SGEN_CON0, 0x8C4A44A8); //sinegen: O13 and O14, 16k, ch2 (16k/64)*4=1kHz, ch1 (16k/64)*8=2kHz
#elif APAUDSYS_DVT_32K
	WriteREG(AFE_SGEN_CON0, 0x8C8A48A8); //sinegen: O13 and O14, 32k, ch2 (32k/64)*4=2kHz, ch1 (32k/64)*8=4kHz
#endif

//#if MDAFE_DVT_CASE3
//	WriteREG(AFE_SGEN_CON0, 0x8C0E20E1); //sinegen: O13 and O14,  8k, ch2 64/2, ch1 64/1
//#elif MDAFE_DVT_CASE2
//	WriteREG(AFE_SGEN_CON0, 0x8C4E24E1); //sinegen: O13 and O14, 16k, ch2 64/2, ch1 64/1
//#elif MDAFE_DVT_CASE1
//	WriteREG(AFE_SGEN_CON0, 0x8C8E28E1); //sinegen: O13 and O14, 32k, ch2 64/2, ch1 64/1
//#endif

	// sidetone
	WriteREG(AFE_SIDDETONE_CON1, 0x00000000);
	
	// AP PCM setting
#if APAUDSYS_DVT_RF2

    // Only ASRC
    // TBD...
    #if APAUDSYS_DVT_16K
        //ASRC1 chset0 for TX2 O26 O27
    	WriteREG(AP_AUDSYS_base + 0x0504, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x0508, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x050c, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x0510, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x0518, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x051C, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x0500, 0x06003031);
        //ASRC4 chset0 for TX O7 O8
        //ASRC4 chset1 for RX I9 I22
    	WriteREG(AP_AUDSYS_base + 0x06C4, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x06C8, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06CC, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06D0, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x06D8, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x06DC, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x06C0, 0x06003031);
    #elif APAUDSYS_DVT_32K	
        //ASRC1 chset0 for TX2 O26 O27
    	WriteREG(AP_AUDSYS_base + 0x0504, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x0508, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x050c, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x0510, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x0518, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x051C, 0x0000CB20);
    	WriteREG(AP_AUDSYS_base + 0x0500, 0x06003031);
        //ASRC4 chset0 for TX O7 O8
        //ASRC4 chset1 for RX I9 I22
    	WriteREG(AP_AUDSYS_base + 0x06C4, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x06C8, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06CC, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06D0, 0x00019640);
    	WriteREG(AP_AUDSYS_base + 0x06D8, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x06DC, 0x0000CB20);
    	WriteREG(AP_AUDSYS_base + 0x06C0, 0x06003031);
    #elif APAUDSYS_DVT_8K	
        //ASRC1 chset0 for TX2 O26 O27
    	WriteREG(AP_AUDSYS_base + 0x0504, 0x00065900);
    	WriteREG(AP_AUDSYS_base + 0x0508, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x050c, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x0510, 0x00065900);
    	WriteREG(AP_AUDSYS_base + 0x0518, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x051C, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x0500, 0x06003031);
        //ASRC4 chset0 for TX O7 O8
        //ASRC4 chset1 for RX I9 I22
    	WriteREG(AP_AUDSYS_base + 0x06C4, 0x00065900);
    	WriteREG(AP_AUDSYS_base + 0x06C8, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06CC, 0x00400000);
    	WriteREG(AP_AUDSYS_base + 0x06D0, 0x00065900);
    	WriteREG(AP_AUDSYS_base + 0x06D8, 0x007F188F);
    	WriteREG(AP_AUDSYS_base + 0x06DC, 0x00032C80);
    	WriteREG(AP_AUDSYS_base + 0x06C0, 0x06003031);
    #endif
    #if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K
        WriteREG(PCM_INTF_CON1, 0x00000037); // MD2
        WriteREG(PCM_INTF_CON,  0x00000017); // MD1
    #elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K
        WriteREG(PCM_INTF_CON1, 0x00000027); // MD2
    	WriteREG(PCM_INTF_CON,  0x00000007); // MD1
    #else // 16 k
        WriteREG(PCM_INTF_CON1, 0x0000002F); // MD2
    	WriteREG(PCM_INTF_CON,  0x0000000F); // MD1
    #endif

#else //#if APAUDSYS_DVT_RF2

    #if USE_ASRC
        // TBD...
        #if APAUDSYS_DVT_16K
            //ASRC2 chset0 for TX O17 O18
            //ASRC2 chset1 for RX I14 I21
        	WriteREG(AP_AUDSYS_base + 0x0704, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0708, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x070C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0710, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0718, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x071C, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0700, 0x06003031);
            //ASRC3 chset0 for TX2 O23 O24
            //ASRC3 chset1 for TX3 O25
        	WriteREG(AP_AUDSYS_base + 0x0744, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0748, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x074C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0750, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0758, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x075C, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0740, 0x06003031);
        #elif APAUDSYS_DVT_32K	
            //ASRC2 chset0 for TX O17 O18
            //ASRC2 chset1 for RX I14 I21
        	WriteREG(AP_AUDSYS_base + 0x0704, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0708, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x070C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0710, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0718, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x071C, 0x0000CB20);
        	WriteREG(AP_AUDSYS_base + 0x0700, 0x06003031);
            //ASRC3 chset0 for TX2 O23 O24
            //ASRC3 chset1 for TX3 O25
        	WriteREG(AP_AUDSYS_base + 0x0744, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0748, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x074C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0750, 0x00019640);
        	WriteREG(AP_AUDSYS_base + 0x0758, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x075C, 0x0000CB20);
        	WriteREG(AP_AUDSYS_base + 0x0740, 0x06003031);
        #elif APAUDSYS_DVT_8K	
            //ASRC2 chset0 for TX O17 O18
            //ASRC2 chset1 for RX I14 I21
        	WriteREG(AP_AUDSYS_base + 0x0704, 0x00065900);
        	WriteREG(AP_AUDSYS_base + 0x0708, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x070C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0710, 0x00065900);
        	WriteREG(AP_AUDSYS_base + 0x0718, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x071C, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0700, 0x06003031);
            //ASRC3 chset0 for TX2 O23 O24
            //ASRC3 chset1 for TX3 O25
        	WriteREG(AP_AUDSYS_base + 0x0744, 0x00065900);
        	WriteREG(AP_AUDSYS_base + 0x0748, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x074C, 0x00400000);
        	WriteREG(AP_AUDSYS_base + 0x0750, 0x00065900);
        	WriteREG(AP_AUDSYS_base + 0x0758, 0x007F188F);
        	WriteREG(AP_AUDSYS_base + 0x075C, 0x00032C80);
        	WriteREG(AP_AUDSYS_base + 0x0740, 0x06003031);
        #endif
        #if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K
            WriteREG(PCM_INTF_CON1, 0x00000037); // MD2
            WriteREG(PCM_INTF_CON,  0x00000017); // MD1
        #elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K
            WriteREG(PCM_INTF_CON1, 0x00000027); // MD2
        	WriteREG(PCM_INTF_CON,  0x00000007); // MD1
        #else // 16 k
            WriteREG(PCM_INTF_CON1, 0x0000002F); // MD2
        	WriteREG(PCM_INTF_CON,  0x0000000F); // MD1
        #endif
    #else //#if USE_ASRC
    	// MD1 PCMsetting
        #if defined(__ENABLE_SPEECH_DVT__)
        	if (Is_Sph_DVT_BT_Mode_NB())
        	{ 
            	WriteREG(PCM_INTF_CON1, 0x00000067); // MD2
        		WriteREG(PCM_INTF_CON,  0x00000047); // MD1
        	}
        	else 
        #endif
        	{
        #if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K
            	WriteREG(PCM_INTF_CON1, 0x00000077); // MD2
           		WriteREG(PCM_INTF_CON,  0x00000057); // MD1
        #elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K
            	WriteREG(PCM_INTF_CON1, 0x00000067); // MD2
        		WriteREG(PCM_INTF_CON,  0x00000047); // MD1
        #else
            	WriteREG(PCM_INTF_CON1, 0x0000006F); // MD2
        		WriteREG(PCM_INTF_CON,  0x0000004F); // MD1
        #endif
        	}
    #endif //#if USE_ASRC

#endif //#if APAUDSYS_DVT_RF2
//	// MD2
//	WriteREG(PCM_INTF_CON1, 0x0000006F);
//	// WriteREG(PCM_INTF_CON2, 0x00000000);
//	// MD1
//	WriteREG(PCM_INTF_CON,  0x0000004F);


	// new interface
	// WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03F87201);
	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013c

	// ADDA
#if defined(__ENABLE_SPEECH_DVT__)
	if (Is_Sph_DVT_BT_Mode_NB())
	{
		//WriteREG(AFE_I2S_CON1, 0x0000009);
		//WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		//
		//WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
		//WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		//WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
		//WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
    	WriteREG(AFE_I2S_CON1, 0x00000009);

    	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    	WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
	}
	else 
#endif
	{
#if MDAFE_DVT_CASE1 || APAUDSYS_DVT_32K // 32k
		//WriteREG(AFE_DAC_CON1, 0x00000800);
		//WriteREG(AFE_I2S_CON1, 0x00000809);
		//WriteREG(AFE_I2S_CON3, 0x00000809);	
        //
		//WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		//WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
		//WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		//WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
		//WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
    	WriteREG(AFE_I2S_CON1, 0x00000809);
		//WriteREG(AFE_I2S_CON3, 0x00000809);	

    	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00140001); // 0x11220114
    	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x6f001821); // 0x11220108
    	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    	WriteREG(AFE_DAC_CON1, 0x00000800); //0x11220014, from script
#elif MDAFE_DVT_CASE2 || APAUDSYS_DVT_16K // 16k
		//WriteREG(AFE_DAC_CON1, 0x00000400);
		//WriteREG(AFE_I2S_CON1, 0x00000409);
		//WriteREG(AFE_I2S_CON3, 0x00000409);
		//	
		//WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		//WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
		//WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		//WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
		//WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_I2S_CON1, 0x00000409);
		//WriteREG(AFE_I2S_CON3, 0x00000409);

    	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
    	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
    	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script
#elif MDAFE_DVT_CASE3 || APAUDSYS_DVT_8K// 8k
		//WriteREG(AFE_DAC_CON1, 0x00000000);
		//WriteREG(AFE_I2S_CON1, 0x00000009);
		//WriteREG(AFE_I2S_CON3, 0x00000009);
        //
		//WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		//WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
		//WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		//WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
		//WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
    	WriteREG(AFE_I2S_CON1, 0x00000009);
		//WriteREG(AFE_I2S_CON3, 0x00000009);

    	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x00000001); // 0x11220114
    	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x0f001821); // 0x11220108
    	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    	WriteREG(AFE_DAC_CON1, 0x00000000); //0x11220014, from script
#else // 16k
		//WriteREG(AFE_I2S_CON1, 0x00000409);
		//WriteREG(AFE_ADDA_UL_DL_CON0, 0x1); // 0x11220124
		//
		//WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
		//WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
		//WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
		//WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
    	WriteREG(AFE_I2S_CON1, 0x00000409);

    	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
    	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
    	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
    	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);

    	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
    	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script

    	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124

    	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script
#endif
	}
//	WriteREG(AFE_I2S_CON1, 0x00000409);
//
//	WriteREG(AFE_ADDA_UL_SRC_CON0, 0x000A0001); // 0x11220114
//	WriteREG(AFE_ADDA_UL_SRC_CON1, 0x00000000);
//	WriteREG(AFE_ADDA_DL_SRC2_CON0, 0x3f001821); // 0x11220108
//	WriteREG(AFE_ADDA_DL_SRC2_CON1, 0xFFFF0000);
//
//	WriteREG(AFE_ADDA_NEWIF_CFG0, 0x03f87200); // 0x11220138, from script
//	WriteREG(AFE_ADDA_NEWIF_CFG1, 0x03117580); // 0x1122013C, from script
//
//	WriteREG(AFE_ADDA_UL_DL_CON0, 0x00000001); // 0x11220124
//		
//	WriteREG(AFE_DAC_CON1, 0x00000400); //0x11220014, from script


	//WriteREG(AFE_I2S_CON, 0x10000009); //0x11220018,  from script
	WriteREG(AFE_DAC_CON0, 0x00001001); // 0x11220010, from script, power on

#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // No UL, DL is output by earphone
	PMIC_AudioConfigForAPAUDSYSDVT();
#else //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)
    // Normal phone call
	PMIC_AudioConfig();
#endif //#if (APAUDSYS_DVT_8K || APAUDSYS_DVT_16K || APAUDSYS_DVT_32K)

//==============================
//  For MT6752 End
//==============================

#endif // chip base define

#endif  // IC_MODULE_TEST

	
}
#endif // !defined(__SMART_PHONE_MODEM__)


