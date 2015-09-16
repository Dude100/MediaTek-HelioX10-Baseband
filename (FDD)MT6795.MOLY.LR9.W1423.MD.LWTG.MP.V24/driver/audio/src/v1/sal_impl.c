#include "kal_public_api.h"
#include "kal_general_types.h"
#include "reg_base.h"
#include "l1_interface.h"
#include "string.h"

#include "common_def.h"
//#include "speech_def.h"

//m#include "l1d_reg.h"

#include "sal_dsp.h"
#include "sal_def.h"

#include "l1audio_trace.h"

#include "sal_impl.h"

#define  TQ_WRAP_COUNT                       5000


extern uint32 L1I_GetTimeStamp( void );

#if defined(MT6280)
static struct{
	bool idle_pcm_record;
}sali_legacy;
#endif


//Need to add new pattern for MT6280
static const uint16 CodecSilencePattern[][17] = {
   {  0x4820,0xD617,0x0284,0x2480,0x9249,0x8924,0x8002,0x4924,       /* FR       */
      0x2492,0x0289,0x2480,0x9249,0x8924,0x8002,0x4924,0x2492,
      0x0009                                                   },
   {  0x4E20,0x875E,0x5473,0x8482,0x00E9,0x0000,0x0000         },    /* HR       */
   {  0x7A10,0x092D,0xB55F,0x7C06,0x185C,0xDE06,0x4230,0x0103,       /* EFR      */
      0xA012,0x001A,0x0000,0x0000,0x0D6C,0x0000,0x0000,0x0000  },
   {  0x00e2,0x5dfc,0xf095,0xcd4e,0x24da,0x0e04,0xf0fb,0x4f2e,       /* AMR12.2  */
      0x4430,0x9fa8,0x0319,0x56c0,0xc144,0x0278,0x70ea,0x0004  },
   {  0xe00a,0xf2e7,0x516b,0x19a1,0xc10d,0x145a,0x4c96,0x25e0,       /* AMR10.2  */
      0x5ce6,0x17b9,0x0982,0x225d,0x00c4                       },
   {  0x033c,0xe5cd,0xd9fb,0x387f,0x420c,0x8c99,0x58d7,0x1156,       /* AMR7.95  */
      0x397f,0x1074                                            },
   {  0xe00a,0xf2e7,0x9ac5,0x4433,0x185b,0x3e05,0xdc64,0xc886,       /* AMR7.4   */
      0xcd2e,0x0000                                            },
   {  0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,       /* AMR6.7   */
      0x0002                                                   },
   {  0xe00a,0xf2e7,0xb196,0xa8ae,0xbcb7,0x6fb9,0x0193,0x002e  },    /* AMR5.9   */
   {  0x3c0a,0x7e51,0x652c,0x5e91,0xd023,0xea5a,0x005b         },    /* AMR5.15  */
   {  0x3c0a,0x3e51,0x6529,0x3a49,0x977f,0x3565                },    /* AMR4.75  */
   {0xe00a,0xf2e7,0x7761,0x0486,0x0dd5,0xf47c,0x21b0,0xf547,0x0002},    /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000},     /* AMR-WB 6.60  */
   {0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000,0x0000}     /* AMR-WB 6.60  */
};

static const uint8 CodecPatternLength[] = {
   (uint8)((260 + 15) / 16),           /*  FR       */
   (uint8)((112 + 15) / 16 + 1),       /*  HR       */
   (uint8)((244 + 15) / 16),           /* EFR       */
   (uint8)((244 + 15) / 16),           /* AMR 12.2K */
   (uint8)((204 + 15) / 16),           /* AMR 10.2K */
   (uint8)((159 + 15) / 16),           /* AMR 7.95K */
   (uint8)((148 + 15) / 16),           /* AMR 7.4K  */
   (uint8)((134 + 15) / 16),           /* AMR 6.7K  */
   (uint8)((118 + 15) / 16),           /* AMR 5.9K  */
   (uint8)((103 + 15) / 16),           /* AMR 5.15K */
   (uint8)(( 95 + 15) / 16),           /* AMR 4.75K */
   (uint8)((132 + 15) / 16),           /* AMR-WB 6.60  */
   (uint8)((177 + 15) / 16),           /* AMR-WB 8.85  */
   (uint8)((253 + 15) / 16),           /* AMR-WB 12.65 */
   (uint8)((285 + 15) / 16),           /* AMR-WB 14.25 */
   (uint8)((317 + 15) / 16),           /* AMR-WB 15.85 */
   (uint8)((365 + 15) / 16),           /* AMR-WB 18.25 */
   (uint8)((397 + 15) / 16),           /* AMR-WB 19.85 */
   (uint8)((461 + 15) / 16),           /* AMR-WB 23.05 */
   (uint8)((477 + 15) / 16),           /* AMR-WB 23.85 */
};

const  uint16  DSP_2GSCH_MARGIN_TABLE[] = {
   0x38+(16<<10)+(2<<8),     /* 1.2 : FR        */
   0x38+(12<<10)+(2<<8),     /* 1.2 : HR        */
   0x38+(16<<10)+(2<<8),     /* 1.2 : EFR       */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 12.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 10.2  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.95  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 7.4   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 6.7   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.9   */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 5.15  */
   0x38+(16<<10)+(2<<8),     /* 1.2 : AMR 4.75  */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 6.60     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 8.85     */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 12.65    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 14.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 15.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 18.25    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 19.85    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.05    */
   0x96+(16<<10)+(2<<8),     /* AMR-WB 23.85    */
};

const  uint16  DSP_2GSCH_DELAY_TABLE_SUBCH0[13][2] =
{    /*  SE      SD  */                    /*   SE  SD   */
   { (0x00B5), 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090), 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B), 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046), 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1), 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C), 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077), 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052), 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D), 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8), 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083), 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E), 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039), 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};

const  uint16  DSP_2GSCH_DELAY_TABLE_SUBCH1[13][2] =
{      /*  SE      SD  */                       /*   SE  SD   */
   { (0x00B5)+0x25, 0x0139 },  /* T2 = 0 /13 */ /*  4.9 12.8  */
   { (0x0090)+0x25, 0x01B4 },  /* T2 = 1 /14 */ /*  3.9 11.8  */
   { (0x006B)+0x25, 0x018F },  /* T2 = 2 /15 */ /*  2.9 10.8  */
   { (0x0046)+0x25, 0x016A },  /* T2 = 3 /16 */ /*  1.9  9.8  */
   { (0x00C1)+0x25, 0x0145 },  /* T2 = 4 /17 */ /*  5.2 13.1  */
   { (0x009C)+0x25, 0x01C0 },  /* T2 = 5 /18 */ /*  4.2 12.1  */
   { (0x0077)+0x25, 0x019B },  /* T2 = 6 /19 */ /*  3.2 11.1  */
   { (0x0052)+0x25, 0x0176 },  /* T2 = 7 /20 */ /*  2.2 10.1  */
   { (0x002D)+0x25, 0x0151 },  /* T2 = 8 /21 */ /*  1.2 13.5  */
   { (0x00A8)+0x25, 0x01CC },  /* T2 = 9 /22 */ /*  4.5 12.5  */
   { (0x0083)+0x25, 0x01A8 },  /* T2 = 10/23 */ /*  3.5 11.5  */
   { (0x005E)+0x25, 0x0183 },  /* T2 = 11/24 */ /*  2.5 10.5  */
   { (0x0039)+0x25, 0x015E }   /* T2 = 12/25 */ /*  1.5 13.8  */
};



static struct{

uint8 device;
uint8 enc_mod;
uint8 dec_mod;
uint32 app_type;
uint8 sub_channel;
uint8 dtx;
uint32 ho_fn;
bool fwe;
bool fwe_ul;
bool fwe_dl;
bool resync_8k;
}sal_impl;

uint16 SALI_Get_Codec_Length( uint8 codec )
{
   if( codec >= 0x20 )
      codec = codec - 0x20 + 0x0B;
   if( codec < (sizeof(CodecPatternLength)/sizeof(CodecPatternLength[0])))
      return (uint16)CodecPatternLength[codec];
   else
      return 0;
}



void SALI_Fill_Enc_Silence( uint8 app_type, uint16 codec )
{
   const uint16 *pat_info;
   volatile uint16 *addr = 0;
   uint32 I, len;

	if(app_type == SAL_APP_TYPE_2GCall)
		addr = DSP_SPH_2G_SE_DATA_HDR;
	else if(app_type == SAL_APP_TYPE_3GCall)
		addr = DSP_SPH_3G_SE_DATA_HDR;
	else
		ASSERT(0);
   
   if( codec >= 0x20 )
      codec = codec - 0x20 + 0x0B;

   if( codec >= (sizeof(CodecPatternLength)/sizeof(CodecPatternLength[0])) )
      return;

   pat_info = CodecSilencePattern[codec];
   len = (uint16)CodecPatternLength[codec];

   *addr++ = 2;
   for( I = 0; I < len; I++ )
      *addr++ = *pat_info++;
}

void SALI_Set_2G_Sch_Delay(uint8 codec_mod, uint8 subchannel)
{
	uint16 n = (uint16)L1D_GetT2();
	uint16 delay = L1D_Get_Win_TQ_WRAP() - TQ_WRAP_COUNT ;
	uint16 delR, delW, delM;

	sal_impl.sub_channel = subchannel;

   if( n >= 13 )
      n -= 13;
   //MT6280, wayne, what is this for?? the speech mode num should be 3+8+9=20
   if (codec_mod>=0x20)
      codec_mod-=(0x20-0x0B);

   ASSERT(codec_mod<(sizeof(DSP_2GSCH_MARGIN_TABLE)/sizeof(DSP_2GSCH_MARGIN_TABLE[0])));
   {
      if (subchannel == 0)
      {
         delR = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][0];
         delW = DSP_2GSCH_DELAY_TABLE_SUBCH0[n][1];
      }
      else
      {
         delR = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][0];
         delW = DSP_2GSCH_DELAY_TABLE_SUBCH1[n][1];
         n += 13;
      }
      L1Audio_Msg_AM_DELAY_TABLE( n );
         delM = DSP_2GSCH_MARGIN_TABLE[codec_mod];		 
   }
   SALI_Set_Sch_Delay(delR, delW, delM, delay, SAL_UNKNOWN);
}

void SALI_Set_2G_Handover()
{
            uint32 fn = L1I_GetTimeStamp();
#if defined( NOT_HANDOVER_IN_SHORT_TIME )
            if( ( fn - sal_impl.ho_fn ) > 13 )//(0x1CC / 8) / 4.615 + 1 = 12.45
            /*do not set handover flag to work around DSP bug */
#endif
            *DSP_SPH_COD_CTRL |= 0x8;
			L1Audio_Msg_SAL_SET_VALUE_MULTI(SAL_DSP_VALUE_NAME(6), (fn - sal_impl.ho_fn)>13, *DSP_SPH_COD_CTRL, (uint16)(fn>>16), (uint16)fn, SAL_UNKNOWN);
			sal_impl.ho_fn = fn;
}

void SALI_Set_Sch_Delay(uint16 delR, uint16 delW, uint16 delM_DL, uint16 delO, uint16 delM_UL)
{
   *DSP_SPH_DEL_R = delR;
   *DSP_SPH_DEL_W = delW;
   *DSP_SPH_DEL_M_DL = delM_DL;
   *DSP_SPH_DEL_O = delO;
   *DSP_SPH_DEL_M_UL = delM_UL;

   	L1Audio_Msg_SAL_SET_VALUE_MULTI(SAL_DSP_VALUE_NAME(3), delR, delW, delM_DL, delO, delM_UL);
}


void SALI_Set_Device(uint8 dev)
{
sal_impl.device = dev;
}

void SALI_Config_SRC(uint8 apptype, bool isWB)
{
	//uint8 fwe = 0;
	uint8 dev = sal_impl.device;

   #define LIMITER_INIT_BIT    (1<<0)
   #define MIC1_UL_W2N_SRC_BIT (1<<1)
   #define MIC1_DL_W2N_SRC_BIT (1<<2)
   
   //#if _SAL_ENABLE_SW_SIDETONE_
   //#define SIDETONE_BIT        (1<<3)
   //#else
   #define SIDETONE_BIT        0
   //#endif


   #define BIT6                (1<<6) //wayne, second mic W2N
   #define BIT7                (1<<7) //wayne, ul n2w
   #define BIT8                (1<<8) //wayne, dl w2n
   #define BIT9                (1<<9)
   #define BIT10               (1<<10)
   #define BIT11               (1<<11)
   #define BIT12               (1<<12)
   #define BIT13               (1<<13)

   uint32 v = 0;
   
   switch(dev){
   case  SAL_DEV_NORMAL:
      if(isWB || sal_impl.fwe){
         v = SIDETONE_BIT;
      }else{
         v = SIDETONE_BIT + MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;
         #if _SAL_DUALMIC_SUPPORT_ //wayn come back
         v |= BIT6;
         #endif          
      }   
	  SALI_Set_Sph_8K_Mod(0);
      break;
   case  SAL_DEV_EARPHONE:
   case  SAL_DEV_LOUDSPK:
      if(isWB || sal_impl.fwe){
         v = 0;
      }else{
         v = MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;
      }
	  SALI_Set_Sph_8K_Mod(0);
      break;	  
   case  SAL_DEV_BT_EARPHONE_NB:
      if(isWB || sal_impl.fwe){
         v = BIT8 + BIT7;
      }else{
         v = 0;
      }
	  SALI_Set_Sph_8K_Mod(1);
      break;
   case  SAL_DEV_BT_EARPHONE_WB:
      if(isWB || sal_impl.fwe){
         v = 0;
      }else{
         v = MIC1_DL_W2N_SRC_BIT + MIC1_UL_W2N_SRC_BIT;
      }
	  SALI_Set_Sph_8K_Mod(1);
      break;  
   default:
       ASSERT_REBOOT(0);
   }

   L1Audio_Msg_AM_SRC1((*DSP_SPH_SFE_CTRL), isWB, dev);
   *DSP_SPH_SFE_CTRL = (v | (*DSP_SPH_SFE_CTRL & 0x9));
   L1Audio_Msg_AM_SRC2((*DSP_SPH_SFE_CTRL), isWB, dev);

   if(isWB)
      *DSP_SPH_8K_CTRL |= 0x8; 
   else
      *DSP_SPH_8K_CTRL &= ~0x8; 

   L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(4), *DSP_SPH_8K_CTRL);
   
}


void SALI_Enable_Codec(uint16 enc_mod, uint16 dec_mod)
{
	sal_impl.enc_mod = enc_mod;
	sal_impl.dec_mod = dec_mod;

  

   *DSP_SPH_COD_MODE = dec_mod | (enc_mod << 8);               

   *DSP_SPH_COD_VAD = (enc_mod>2)? 1:0;
   
   *DSP_SPH_COD_CTRL |= 0x33 ;
}

void SALI_Disable_Codec()
{
   *DSP_SPH_COD_CTRL &= 0xFF08;//dont clear the ho flag
}

//fsju
void SALI_Enable_Update_Codec_Now()
{
   // force update codec immediately
   *DSP_SPH_COD_CTRL |= 0xC000;
}

//fsju
void SALI_Disable_Update_Codec_Now()
{
   // do not update codec immediately
   *DSP_SPH_COD_CTRL &= 0x3FFF;
}

void SALI_Set_DSH(bool on)
{
	if(on)
		*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x0100;
	else
		*DSP_SPH_SCH_IMPROVE_CTRL |=  0x0100;

}


void SALI_LBK_Codec(bool on)
{
	if(on)
		*DSP_SPH_COD_CTRL |= 0x0700;		
	else
		*DSP_SPH_COD_CTRL &= ~0x0700;

	SALI_Set_DSH(!on);
}


void SALI_3G_SetDtx(bool on)
{
	sal_impl.dtx = on;
	
	if(on)
		*DSP_SPH_COD_CTRL |= 0x4 ;
	else
		*DSP_SPH_COD_CTRL &= ~0x4 ;
}

void SALI_Upd_3G_Enc_Rate(uint16 enc_mod)
{
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(0), enc_mod);
	*DSP_SPH_3G_SE_RATE = enc_mod;
}

void SALI_Upd_3G_Dec_Rate(uint16 dec_mod)
{
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(1), dec_mod);
	*DSP_SPH_3G_SD_RATE = dec_mod;
}

void SALI_Set_3G_TxType(uint16 tx_type)
{
	*DSP_SPH_3G_SE_DATA_HDR = tx_type & 0x3;
}

void SALI_Set_3G_RxType(uint16 rx_type)
{
	*DSP_SPH_3G_SD_DATA_HDR = rx_type & 0xE;
}
uint16 SALI_3G_GetValue(uint16 type)
{
	uint16 val = 0;
	
	switch(type)
	{
	case SAL_3G_VALUE_TX_CODEC_MODE:
		val = *DSP_SPH_Encoder_Used_Mode;
		break;
	case SAL_3G_VALUE_RX_CODEC_MODE:
		val = *DSP_SPH_Decoder_Used_Mode;
		break;
	case SAL_3G_VALUE_TX_TYPE:
		val = (*DSP_SPH_3G_SE_DATA_HDR) & 0x3;
		break;
	case SAL_3G_VALUE_RX_TYPE:
		val = (*DSP_SPH_3G_SD_DATA_HDR) & 0xE;//no need to shif right back 
		break;
	
	default:
		ASSERT_REBOOT(0);
	}

	return val;
}

volatile uint16* SALI_3G_GetAddr(uint16 type)
{
	volatile uint16* addr = 0;



	switch(type)
	{
	case SAL_3G_ADDR_TXHB:
		addr = DSP_SPH_3G_SE_DATA_HB;
		break;
	case SAL_3G_ADDR_RXHB:
		addr = DSP_SPH_3G_SD_DATA_HB;
		break;

	default:
		ASSERT_REBOOT(0);

	}

	return addr;
}

//ul_dl @ 0 : ul, 1 : dl
bool SALI_3G_CheckDataSync(uint8 ul_dl)
{
	bool bval = false;

	if(ul_dl == 0)
		bval = (*DSP_SPH_3G_SYNC_FLAG & 0x1) > 0;//ul is ready
	else if(ul_dl == 1)
		bval = (*DSP_SPH_3G_SYNC_FLAG & 0x2) == 0;//dl is cleaned by dsp
	else ASSERT_REBOOT(0);

	return bval;

}

//ready @ true : ready, false : empty
void SALI_3G_SetDataStatus(uint8 ul_dl, bool ready)
{
	if(ul_dl == 0){
		if(ready)
			*DSP_SPH_3G_SYNC_FLAG |= 0x1;
		else
			*DSP_SPH_3G_SYNC_FLAG &= 0xFFFE;			
	}
	else if(ul_dl == 1){
		if(ready)
			*DSP_SPH_3G_SYNC_FLAG |= 0x2;
		else
			*DSP_SPH_3G_SYNC_FLAG &= 0xFFFD;			
	}
	else
		ASSERT_REBOOT(0);
}

void SALI_3G_SetULUnsync()
{
	*DSP_SPH_3G_SYNC_FLAG |= 0x10;
}

void SALI_AppSpec_Control(uint8 app_type, uint8 on)
{

	#if !defined(MT6280)
	if(app_type == SAL_APP_TYPE_2GCall){
		if(on)
			*DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_2G;
		else
			*DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
	}
	
	if(app_type == SAL_APP_TYPE_3GCall){
		if(on)
			*DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_3G;
		else
			*DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
	}

	if(app_type == SAL_APP_TYPE_4GCall){
		if(on)
			*DSP_SPH_APP_MODE = SPH_APP_MODE_CALL_4G;
		else
			*DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
	}
	
	if(app_type == SAL_APP_TYPE_PCM_Router){
		if(on)
			*DSP_SPH_APP_MODE = SPH_APP_MODE_PCM_ROUNTER;
		else
			*DSP_SPH_APP_MODE = SPH_APP_MODE_NONE;
	}
	#endif


	switch(app_type)
	{
		case SAL_APP_TYPE_2GCall:
		case SAL_APP_TYPE_3GCall:
		case SAL_APP_TYPE_4GCall:
			if(on){
	   		*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x4000; //Enable DSH_2G_UL_CRC
	   		SALI_Set_DSH(true);//DSP debug mode loopback will turn it off without through SAL
			}
			else{
		   	*DSP_SPH_SCH_IMPROVE_CTRL |=  0x4000; 
			}
			break;

	}


}


void SALI_Set_3G(bool on)
{
	if(on)
		*DSP_SPH_3G_CTRL = 1;
	else
		*DSP_SPH_3G_CTRL = 0;
}

bool SALI_Check_3G()
{
	bool val = false;
	
	if(*DSP_SPH_3G_CTRL == 1)
		val = true;	

	return val;
}

void  SALI_VBI_Reset()          
{ 
	*SHARE2_M2DI1 = 0x0838; 
    L1Audio_Msg_VBI_RESET(); 
}

void  SALI_VBI_End()
{ 
	*SHARE2_M2DI1 = 0x0839;
    L1Audio_Msg_VBI_END(); 
}


void SALI_VM_Upd_Enc_Used(uint16 codec)	
{
	*DSP_SPH_Encoder_Used_Mode = codec;
}


void SALI_Bgsnd_Switch(bool on)
{
	if(on)
		*DSP_SPH_BGS_CTRL = 1;//initialize
	else
		*DSP_SPH_BGS_CTRL = 3;//finalize
}

bool SALI_Bgsnd_IsRunning()
{
	if(*DSP_SPH_BGS_CTRL == 2)
		return true;
	else
		return false;
}

bool SALI_Bgsnd_IsOFF()
{
	if(*DSP_SPH_BGS_CTRL == 0)
		return true;
	else
		return false;
}

void SALI_Bgsnd_Config(uint16 ulgain, uint16 dlgain, bool ulmix, bool dlmix)
{
	*DSP_SPH_BGS_MIX = (ulmix << 1) | dlmix;
	*DSP_SPH_BGS_UL_GAIN = ulgain;
	*DSP_SPH_BGS_DL_GAIN = dlgain;
}


//ul_dl @ 0 : ul, 1 : dl
volatile uint16* SALI_Bgsnd_GetBuf(uint8 ul_dl)
{
	volatile uint16* ptr;
	if(ul_dl == 0)
	ptr = DSP_DM_ADDR(AUX_PAGE_NUM, *DSP_SPH_BGS_ADDR_UL);
	else
	ptr = DSP_DM_ADDR(AUX_PAGE_NUM, *DSP_SPH_BGS_ADDR_DL);		
	
	return ptr;
}
//ul_dl @ 0 : ul, 1 : dl
uint16 SALI_Bgsnd_GetDataLen(uint8 ul_dl)
{
	uint16 len;
	if(ul_dl == 0)
		len = *DSP_SPH_BGS_LEN_UL;
	else
		len = *DSP_SPH_BGS_LEN_DL;
	return len;
}

void SALI_Init()
{
	sal_impl.ho_fn = 0;

	*DSP_SPH_HR_FR_CTRL = 0x0E;
	*DSP_SPH_SCH_IMPROVE_CTRL |= 0x4405;

	#if _SAL_DUALMIC_SUPPORT_
    *DSP_SPH_DUMIC_CTRL |= 0x0001;
  #endif 
  #if _SAL_MIC34_SUPPORT_
    *DSP_SPH_THIRDMIC_CTRL |= 0x0001;
    *DSP_SPH_FOURTHMIC_CTRL |= 0x0001;
  #endif
  
  
    
  sal_impl.resync_8k = true;//DSP allways supports, real control from L1's gps co-clock feature

	#if (defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6571)) || defined(MT6290) || defined(MT6595) || defined(MT6752)
	sal_impl.fwe = true;
	sal_impl.fwe_ul = true;
	sal_impl.fwe_dl = true;
	#else
	//turn off fwe for sample back
	sal_impl.fwe_ul = false;
	sal_impl.fwe_dl = false;
	sal_impl.fwe = false;
	#endif

#if defined(__ENABLE_SPEECH_DVT__)
    extern kal_bool Is_Sph_DVT_Enable_FWE(void);
    if (Is_Sph_DVT_Enable_FWE())
    {
        sal_impl.fwe = true;
	    sal_impl.fwe_ul = true;
	    sal_impl.fwe_dl = true;
	    sal_impl.resync_8k = false;
    }
    else
    {
        sal_impl.fwe_ul = false;
	    sal_impl.fwe_dl = false;
	    sal_impl.fwe = false;
	    sal_impl.resync_8k = false;
    }
#endif // defined(__ENABLE_SPEECH_DVT__)

	#if (defined(MT6280) || defined(MT6589))
		if(sal_impl.fwe)
   			*DSP_SPH_SCH_IMPROVE_CTRL |= 0x8000;
   		else
			*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x8000;
	#else
		if(sal_impl.resync_8k)
   			*DSP_SPH_SCH_IMPROVE_CTRL |= 0x8000;
   		else
			*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x8000;		
		if(sal_impl.fwe_ul)
   			*DSP_SPH_SCH_IMPROVE_CTRL |= 0x0010;
   		else
			*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x0010;		
		if(sal_impl.fwe_dl)
   			*DSP_SPH_SCH_IMPROVE_CTRL |= 0x0020;
   		else
			*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x0020;		
	#endif

	*DSP_SPH_DEBUG_ASSERT_CTRL |= 0x0020;
	
	//Workaround for FTA case [FTA][CRTU-G]TC_26.16.4_1_1 fail while 2g modem Tx unsync with speech
	//2g modem will fix this on MT6571 and later chips
	#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6290) || defined(MT6595) || defined(MT6752)
	SALI_Fill_Enc_Silence(SAL_APP_TYPE_2GCall, 0);
	#endif	

}

void SALI_Set_Sph_8K_Mod(uint8 mod)//0 normal, 1 bt
{
	if(mod == 1)
	*DSP_SPH_8K_CTRL = 0x2000 + (*DSP_SPH_8K_CTRL & 0x0fff);
	else
	*DSP_SPH_8K_CTRL = 0x8000 + (*DSP_SPH_8K_CTRL & 0x0fff);	
}



volatile uint16* SALI_GetFltCoefAddr(uint8 type)
{
	volatile uint16* addr = 0;
	
	switch(type)
	{
		case SALI_FLTCOEF_TYPE_SIDETONE:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_ST);//0x142 - 0x153 len:18
			break;
		case SALI_FLTCOEF_TYPE_BKF_NB_UL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_UL);//MT6280, 0161-018D len = 45
			break;
		case SALI_FLTCOEF_TYPE_BKF_NB_DL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_NB_DL);//MT6280, 018E-01BA len = 45
			break;
		case SALI_FLTCOEF_TYPE_BKF_WB_UL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_WB_UL);//01BB-0214, length = 90
			break;
		case SALI_FLTCOEF_TYPE_BKF_WB_DL:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_BKF_WB_DL);//0215-026E, length = 90
			break;
		case SALI_FLTCOEF_TYPE_SRC:
			addr = DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_SRC);
			break;	
		case SALI_FLTCOEF_TYPE_AGC:
			addr = DSP_PM_ADDR(3, 0x11A);//DSP_PM_ADDR(3, *DSP_SPH_FLT_COEF_ADDR_SRC) + SAL_FLTCOEFLEN_SRC;
			break;	
		case SALI_FLTCOEF_TYPE_DMNR_NB:
			addr = DSP_PM_ADDR(3, 0x400);
			break;
		case SALI_FLTCOEF_TYPE_DMNR_WB:
			addr = DSP_PM_ADDR(3, 0x42C);
			break;
		case SALI_FLTCOEF_TYPE_NOTCH:
			addr = DSP_PM_ADDR(3, 0x26F);
			break;
	
		default:
				ASSERT_REBOOT(0);
	}

	return addr;
}




void SALI_BKF_Switch(bool ul, bool dl)
{
	if(ul)
		*DSP_SPH_COMPEN_BLOCK_FILTER |= 0x0001;
	else
		*DSP_SPH_COMPEN_BLOCK_FILTER &= ~0x0001;

	if(dl)
		*DSP_SPH_COMPEN_BLOCK_FILTER |= 0x0002;
	else
		*DSP_SPH_COMPEN_BLOCK_FILTER &= ~0x0002;
	
}

static volatile uint16* sali_get_enh_ctrl(uint8 enh_mod)
{
	volatile uint16* sheriff = 0;

	switch(enh_mod){
		case SAL_ENH_AEC:
			sheriff = DSP_SPH_EES_CTRL;
			break;
		case SAL_ENH_NR_UL:
			sheriff = DSP_SPH_NR_CTRL;
			break;	
		case SAL_ENH_NR_DL:
			sheriff = DSP_SPH_DL_NR_CTRL;
			break;	
		case SAL_ENH_TDNC:
			sheriff = DSP_SPH_TDNC_CTRL;
			break;
		case SAL_ENH_DMNR:
			sheriff = DSP_SPH_DMNR_CTRL;
			break;
	default:
		ASSERT_REBOOT(false);
	}

	return sheriff;

}

void SALI_ENH_Switch(uint8 enh_mod, bool on)
{
	volatile uint16* sheriff;
	uint16 val;

	sheriff = (volatile uint16*)sali_get_enh_ctrl(enh_mod);
	val = *sheriff;
	val &= 0xfffc;

	if(on)
		*sheriff = val | 0x0001;//init
	else
		*sheriff = val | 0x0003;//off

}


bool SALI_ENH_IsReady(uint8 enh_mod)
{
	volatile uint16* sheriff;
	uint16 val;

	sheriff = (volatile uint16*)sali_get_enh_ctrl(enh_mod);
	val = *sheriff;
	val &= 0x0003;
	
	if(val == 2)
		return true;
	else
		return false;
}

bool SALI_ENH_IsIdle(uint8 enh_mod)
{
	volatile uint16* sheriff;
	uint16 val;

	sheriff = (volatile uint16*)sali_get_enh_ctrl(enh_mod);
	val = *sheriff;
	val &= 0x0003;
	
	if(*sheriff == 0)
		return true;
	else
		return false;
}

void sali_enh_toberemovedtodsp()
{
	*DSP_SPH_UL_COMFORT_NOISE_THRESHOLD = 32;
	*DSP_SPH_UL_COMFORT_NOISE_SHIFT = (uint16)-12;
}

//ul_dl : 0 -> ul, 1 -> dl
void SALI_ENH_PathEnable(uint8 ul_dl, bool on)
{
	sali_enh_toberemovedtodsp();

	if(ul_dl == 0)	{
		if(on)
			*DSP_SPH_ENH_UL_CTRL |= 0x0002;
		else
			*DSP_SPH_ENH_UL_CTRL &= ~0x0002;
	}
	else if(ul_dl == 1){
		if(on)
			*DSP_SPH_ENH_DL_CTRL |= 0x0004;
		else
			*DSP_SPH_ENH_DL_CTRL &= ~0x0004;
	}
	else
		ASSERT_REBOOT(false);
			
}

void SALI_ENH_Dynamic_Ctrl(bool on, Sal_Enh_Dynamic_t fea)
{
	if(on)
		*DSP_SPH_ENH_DYMANIC_SWITCH |= (1 << fea);
	else
		*DSP_SPH_ENH_DYMANIC_SWITCH &= ~(1 << fea);

	L1Audio_Msg_SAL_SET_VALUE_MULTI(SAL_DSP_VALUE_NAME(5), on, fea, *DSP_SPH_ENH_DYMANIC_SWITCH, SAL_UNKNOWN, SAL_UNKNOWN);
}

void SALI_ENH_Gain_Set_DL(uint16 val)
{
	*DSP_SPH_ENH_DL_GAIN = val;
}

volatile uint16* SALI_Parameter_GetAddr(uint8 type)
{
	volatile uint16* addr = 0;

	switch(type)
	{
		case SALI_PARAMETER_TYPE_COMMON:
			addr = DSP_DM_ADDR(5, *DSP_SPH_EMP_ADDR);
			break;
		case SALI_PARAMETER_TYPE_MODE_NB:
			addr = DSP_DM_ADDR(5, *DSP_SPH_EMP_ADDR) + SAL_PARAMETERLEN_COMMON;
			break;	
		case SALI_PARAMETER_TYPE_MODE_WB:
			#if defined(MT6280)
			addr = DSP_DM_ADDR(5, 0x374E);
			#else
			addr = DSP_DM_ADDR(5, *DSP_SPH_EMP_ADDR) + SAL_PARAMETERLEN_COMMON + SAL_PARAMETERLEN_MODE_NB;
			#endif
			break;	
		case SALI_PARAMETER_TYPE_MODE_INTERNAL:
			addr = DSP_SPH_ENH_INTERNAL_PAR_ADDR;
			break;
		default:
			ASSERT_REBOOT(false);
	}

	return addr;
}


bool SALI_Int_Resolve(uint16 iid, uint32* sph_int)
{
	uint32 val = 0;
	uint16 mask = 0;
	bool from_sph = true;

	switch(iid){

	case DSP_IID_SPEECH_UL_ID:
		mask = *DSP_SPH_D2C_UL_INT;
		if(mask & 0x0001){
			val += SAL_DSPINT_ID_REC_PCM;
			#if defined(MT6280) //idle record pcm or vm exclusively
			if(!sali_legacy.idle_pcm_record){//vm record control
				val -= SAL_DSPINT_ID_REC_PCM;
				val += SAL_DSPINT_ID_REC_VM;
			}
			#endif
		}
		if(mask & 0x0002){
			val += SAL_DSPINT_ID_REC_EPL;
			#if defined(MT6280) //call record pcm or epl exclusively
			if(*(SALI_Parameter_GetAddr(SALI_PARAMETER_TYPE_COMMON)) == 0){//dsp is not triggerring epl
				val -= SAL_DSPINT_ID_REC_EPL;
				val += SAL_DSPINT_ID_REC_PCM;
			}
			#endif
		}	
		if(mask & 0x0004)
			val += SAL_DSPINT_ID_PNW_UL;
		if(mask & 0x0008)
			val += SAL_DSPINT_ID_DACA_UL;
		if(mask & 0x0010)
			val += SAL_DSPINT_ID_3G_UL;
		if(mask & 0x0020)
			val += SAL_DSPINT_ID_BGS_UL;
		if(mask & 0x0080)
			val += SAL_DSPINT_ID_WARN_MSG_UL;
		if(mask & 0x0100)
			val += SAL_DSPINT_ID_VOLTE_UL;
		//add debugging queue here latter
		*DSP_SPH_D2C_UL_INT = 0;
		break;

	case DSP_IID_SPEECH_DL_ID:
		mask = *DSP_SPH_D2C_DL_INT;
		if(mask & 0x0001)
			val += SAL_DSPINT_ID_REC_VM;
		if(mask & 0x0004)
			val += SAL_DSPINT_ID_PNW_DL;
		if(mask & 0x0008)
			val += SAL_DSPINT_ID_DACA_DL;
		if(mask & 0x0010)
			val += SAL_DSPINT_ID_3G_DL;
		if(mask & 0x0020)
			val += SAL_DSPINT_ID_BGS_DL;
		if(mask & 0x0040)
			val += SAL_DSPINT_ID_AVBT;
		if(mask & 0x0080)
			val += SAL_DSPINT_ID_WARN_MSG_DL;
		if(mask & 0x0100)
			val += SAL_DSPINT_ID_VOLTE_DL;
		if(mask & 0x0200)
			val += SAL_DSPINT_ID_4G_DL;
		
		*DSP_SPH_D2C_DL_INT = 0;
		break;
		
	case DSP_IID_SPEECH_UL_ID2:
		val += SAL_DSPINT_ID_4G_UL;
		break;
		
	default:
		from_sph = false;
		//print warning message
		break;
	}
	
	*sph_int = val;
	return from_sph;
	
}


void SALI_PcmEx_Config(Sal_PCMEx_Config_t* cfg)
{
	if(cfg->type == SAL_PCMEX_TYPE_PNW){

		if(cfg->M2D_ul1)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT11;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT11;
		if(cfg->D2M_ul1)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT10;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT10;
		if(cfg->afterEnh_ul1)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT9;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT9;
			
		if(cfg->M2D_ul2)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT14;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT14;
		if(cfg->D2M_ul2)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT13;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT13;
		if(cfg->afterEnh_ul2)
			*DSP_SPH_PNW_CTRL_UL1 |= SAL_BIT12;
		else
			*DSP_SPH_PNW_CTRL_UL1 &= ~SAL_BIT12;
			
		if(cfg->M2D_ul3)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT2;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT2;
		if(cfg->D2M_ul3)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT1;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT1;
		if(cfg->afterEnh_ul3)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT0;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT0;
			
		if(cfg->M2D_ul4)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT5;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT5;
		if(cfg->D2M_ul4)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT4;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT4;		
		if(cfg->afterEnh_ul4)
			*DSP_SPH_PNW_CTRL_UL2 |= SAL_BIT3;
		else
			*DSP_SPH_PNW_CTRL_UL2 &= ~SAL_BIT3;
			
		if(cfg->M2D_dl)
			*DSP_SPH_PNW_CTRL_DL |= SAL_BIT11;
		else
			*DSP_SPH_PNW_CTRL_DL &= ~SAL_BIT11;		
		if(cfg->D2M_dl)
			*DSP_SPH_PNW_CTRL_DL |= SAL_BIT10;
		else
			*DSP_SPH_PNW_CTRL_DL &= ~SAL_BIT10;
		if(cfg->afterEnh_dl)
			*DSP_SPH_PNW_CTRL_DL |= SAL_BIT9;
		else
			*DSP_SPH_PNW_CTRL_DL &= ~SAL_BIT9;
		
		if(cfg->DMNR_cal)
			*DSP_SPH_DMNR_CTRL |= 0x0010;
		else
			*DSP_SPH_DMNR_CTRL &= ~0x0010;
		}
	else if(cfg->type == SAL_PCMEX_TYPE_DACA){
		if(cfg->band == SAL_PCM_NARROWBAND)
			*DSP_SPH_DACA_CTRL |= 0x0100;
		else
			*DSP_SPH_DACA_CTRL &= ~0x0100;
		}
	else if(cfg->type == SAL_PCMEX_TYPE_REC_NML){
			if(cfg->swi == SAL_PCMEX_SWITCH_ON){
				*DSP_SPH_PCM_REC_CTRL |= 0x0001;//how about EPL? MT6280 vs After
			}
			else{
				*DSP_SPH_PCM_REC_CTRL &= ~0x0001;//how about EPL? MT6280 vs After
			}	
			
				
			if(cfg->swi == SAL_PCMEX_SWITCH_ON && cfg->idle){
		    	*DSP_SPH_MUTE_CTRL |= 0x0002;
				#if defined(MT6280)
				sali_legacy.idle_pcm_record = true;
				*DSP_SPH_COD_CTRL |= 0x0800;//for mt6280 idle vm and pcm record
				#endif
			}
			else if(cfg->swi == SAL_PCMEX_SWITCH_OFF && cfg->idle){
				*DSP_SPH_MUTE_CTRL &= ~0x0002;
				#if defined(MT6280)
				sali_legacy.idle_pcm_record = false;
				*DSP_SPH_COD_CTRL &= ~0x0800;
				#endif
			}

		}
	else if(cfg->type == SAL_PCMEX_TYPE_REC_EPL){

			#if !defined(MT6280)
			if(cfg->swi == SAL_PCMEX_SWITCH_ON){
				*DSP_SPH_PCM_REC_CTRL |= 0x0002;//how about EPL? MT6280 vs After
			}
			else{
				*DSP_SPH_PCM_REC_CTRL &= ~0x0002;//how about EPL? MT6280 vs After
			}
			#endif
		}
	else if(cfg->type == SAL_PCMEX_TYPE_VOLTE){
			//need to set 4G flag here?
		}
	else 
		ASSERT_REBOOT(0);


		
	//an idle pnw, datacard or recording application
	if(cfg->idle && cfg->swi == SAL_PCMEX_SWITCH_ON){
	SALI_Config_SRC(SAL_APP_TYPE_3GCall, cfg->band == SAL_PCM_WIDEBAND);
	SALI_Set_Sch_Delay(cfg->delR, cfg->delW, cfg->delM, 0, SAL_UNKNOWN);
	SALI_VBI_Reset();
	}
	else if(cfg->idle && cfg->swi == SAL_PCMEX_SWITCH_OFF){
	SALI_VBI_End();
	}
}

bool SALI_PcmEx_IsCtrlClean(Sal_PcmEx_Type_t type)
{
	bool ret = false;

	if(type == SAL_PCMEX_TYPE_PNW)
		ret = (*DSP_SPH_PNW_CTRL_UL1 == 0) && (*DSP_SPH_PNW_CTRL_DL == 0);
	else if(type == SAL_PCMEX_TYPE_DACA)
		ret = (*DSP_SPH_DACA_CTRL == 0);

	return ret;
}

void SALI_PcmEx_SetCtrlClean(Sal_PcmEx_Type_t type)
{
	if(type == SAL_PCMEX_TYPE_PNW){
		*DSP_SPH_PNW_CTRL_UL1 = 0;
		*DSP_SPH_PNW_CTRL_DL = 0;
	}
	else if(type == SAL_PCMEX_TYPE_DACA)
		*DSP_SPH_DACA_CTRL = 0;
	
}


bool SALI_PcmEx_CheckState(uint8 ul_dl, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	volatile uint16* addr;
	bool ret = false;

	if(type == SAL_PCMEX_TYPE_PNW){
		if(ul_dl == 0)
			addr = DSP_SPH_PNW_CTRL_UL1;
		else
			addr = DSP_SPH_PNW_CTRL_DL;
		ret = ((*addr & 0xf) == sta);
	}

	else if(type == SAL_PCMEX_TYPE_DACA){
		if(ul_dl == 0)
			ret = ((*DSP_SPH_DACA_CTRL & 0xf) == sta);
		else
			ret = ( (*DSP_SPH_DACA_CTRL >> 4 & 0xf) == sta);
	}
	else if(type == SAL_PCMEX_TYPE_VOLTE){
		if(ul_dl == 0)
			ret = ((*DSP_SPH_EXTCOD_PEX_CTRL & 0xf) == sta);
		else
			ret = ( (*DSP_SPH_EXTCOD_PEX_CTRL >> 8 & 0xf) == sta);
	}
	

	return ret;

}


void SALI_PcmEx_SetState(uint8 ul_dl, Sal_PcmEx_Type_t type, Sal_PcmEx_State_t sta)
{
	volatile uint16* addr;

	if(sta != SAL_PCMEX_ON && sta != SAL_PCMEX_OFF)
		ASSERT_REBOOT(0);//should not be this state

	if(type == SAL_PCMEX_TYPE_PNW){
	
		if(ul_dl == 0)
			addr = DSP_SPH_PNW_CTRL_UL1;
		else
			addr = DSP_SPH_PNW_CTRL_DL;	

		if(sta == SAL_PCMEX_ON){
			*addr = (*addr & 0xfff0) + 1;
			*addr |= 0x01 << 8;
		}
		else if(sta == SAL_PCMEX_OFF){
			*addr &= 0xfff0;
			*addr &= ~(0x01 << 8);
		}

	}
	else if(type == SAL_PCMEX_TYPE_DACA){
		
		addr = DSP_SPH_DACA_CTRL;
		
		if(ul_dl == 0){
			if(sta == SAL_PCMEX_ON)
				*addr = (*addr & 0xfff0) + 1;
			else
				*addr &= 0xfff0;
		}
		else{
			if(sta == SAL_PCMEX_ON)
				*addr = (*addr & 0xff0f) + 0x0010;
			else
				*addr &= 0xff0f;
		}
			
	}
	else if(type == SAL_PCMEX_TYPE_VOLTE){

		addr = DSP_SPH_EXTCOD_PEX_CTRL;
		if(ul_dl == 0){
			if(sta == SAL_PCMEX_ON)
				*addr = (*addr & 0xfff0) + 1;
			else
				*addr &= 0xfff0;
		}
		else{
			if(sta == SAL_PCMEX_ON)
				*addr = (*addr & 0xf0ff) + 0x0100;
			else
				*addr &= 0xf0ff;
		}
		
	}
		
}

volatile uint16* SALI_PcmEx_GetBuf(Sal_PcmEx_BufId_t id)
{
	
	volatile uint16* addr = 0;

	switch(id){
		
		case SAL_PCMEX_PNW_BUF_UL1:
			addr = DSP_SPH_PNW_BUF_UL1;
			break;
		case SAL_PCMEX_PNW_BUF_UL2:
			addr = DSP_SPH_PNW_BUF_UL2;
			break;
		case SAL_PCMEX_PNW_BUF_UL3:
			addr = DSP_SPH_PNW_BUF_UL3;
			break;
		case SAL_PCMEX_PNW_BUF_UL4:
			addr = DSP_SPH_PNW_BUF_UL4;
			break;
		case SAL_PCMEX_PNW_BUF_DL1:
			addr = DSP_SPH_PNW_BUF_DL1;
			break;		
		case SAL_PCMEX_PNW_BUF_DL2:
			addr = DSP_SPH_PNW_BUF_DL2;
			break;
		case SAL_PCMEX_DACA_BUF_UL:
			addr = DSP_SPH_DACA_UL_BUF;
			break;
		case SAL_PCMEX_DACA_BUF_DL:
			addr = DSP_SPH_DACA_DL_BUF;
			break;
		case SAL_PCMEX_BUF_SE:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SE_BUF_PTR);
			break;
		#if !defined(MT6280)
		case SAL_PCMEX_BUF_SE2:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SE2_BUF_PTR);
			break;
		#endif
		case SAL_PCMEX_BUF_SD:
			addr = DSP_DM_ADDR(5, *DSP_SPH_SD_BUF_PTR);
			break;	
		case SAL_PCMEX_VOLTE_BUF_UL:
			addr = DSP_SPH_EXTCOD_BUF_UL;
			return addr;
			break;	
		case SAL_PCMEX_VOLTE_BUF_DL:
			addr = DSP_SPH_EXTCOD_BUF_DL;
			return addr;
			break;	

		default:
			ASSERT(0);
	}

	return DSP_DM_ADDR(AUX_PAGE_NUM, *addr);
}




uint16 SALI_PcmEx_GetBufLen(Sal_PcmEx_BufId_t id)
{
	uint16 len = 0;

	switch(id)
	{
		case SAL_PCMEX_PNW_BUF_UL1:
			len = *DSP_SPH_PNW_LEN_UL1;
			break;
		case SAL_PCMEX_PNW_BUF_UL2:
			len = *DSP_SPH_PNW_LEN_UL2;
			break;
		case SAL_PCMEX_PNW_BUF_UL3:
			len = *DSP_SPH_PNW_LEN_UL3;
			break;
		case SAL_PCMEX_PNW_BUF_UL4:
			len = *DSP_SPH_PNW_LEN_UL4;
			break;
		case SAL_PCMEX_PNW_BUF_DL1:
		case SAL_PCMEX_PNW_BUF_DL2:
			len = *DSP_SPH_PNW_LEN_DL;
			break;
		case SAL_PCMEX_BUF_SE:
			if(*DSP_SPH_BAND&(0x1<<DSP_SPH_BAND_FLAG_BIT_COD))//bit1 -> codec band, bit0 -> sch band
				len = 320;
			else
				len = 160;
			break;
		case SAL_PCMEX_BUF_SE2:
		case SAL_PCMEX_BUF_SD:
			if(*DSP_SPH_BAND&(0x1<<DSP_SPH_BAND_FLAG_BIT_SCH_DL))//bit1 -> codec band, bit0 -> sch band
				len = 320;
			else
				len = 160;
			break;
		case SAL_PCMEX_DACA_BUF_UL:
		case SAL_PCMEX_DACA_BUF_DL:
			if(*DSP_SPH_DACA_CTRL & 0x0100)
				len = 160;
			else
				len = 320;
			break;
		case SAL_PCMEX_VOLTE_BUF_UL:
		case SAL_PCMEX_VOLTE_BUF_DL:	
			len = *DSP_SPH_EXTCOD_PEX_LEN;
			break;			
		default:
			ASSERT(0);//or print waring message here
	}

	return len;
}

uint16 SALI_AGC_GetSWGain(uint8 mic)
{
	uint16 val = 0;
	
	if(mic == 0)
		val = *DSP_SPH_AGC_SW_GAIN1;
	else if(mic == 1)
		val = *DSP_SPH_AGC_SW_GAIN2;
	else
		ASSERT(0);

	return val;
}

void SALI_AGC_SetGain(uint16 val)
{
	*DSP_SPH_AGC_GAIN = val;
}

uint16 SALI_Sidetone_GetAdaptiveGain()
{
	uint16 val;

	val = *DSP_SPH_ST_ADAPT_GAIN;
	
	return val;

}

void SALI_Sidetone_SetGain(uint16 val)
{
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(8), val);
	*DSP_SPH_ST_VOL = val;
}

void SALI_Sidetone_Enable(bool ena)
{
	if(ena){
		*DSP_SPH_SFE_CTRL &= 0xfffe;
		*DSP_SPH_SFE_CTRL |= 0x0008;
		}
	else
		*DSP_SPH_SFE_CTRL &= 0xfff7;
	
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(9), *DSP_SPH_SFE_CTRL);
			
}

uint16 SALI_DGain_Get(uint8 ul_dl)
{
	volatile uint16* addr;

	if(ul_dl == 0)
		addr = DSP_SPH_UL_VOL;
	else
		addr = DSP_SPH_DL_VOL;

	return *addr;
}

void SALI_DGain_Set(uint8 ul_dl, uint16 val)
{
	volatile uint16* addr;

	if(ul_dl == 0)
		addr = DSP_SPH_UL_VOL;
	else
		addr = DSP_SPH_DL_VOL;

	*addr = val;
}

void SALI_VM_Config(Sal_VM_Config_t *cfg)
{
	if(cfg->swi == SAL_VM_SWITCH_ON){
		*DSP_SPH_COD_CTRL |= 0x0800;
		*DSP_SPH_SCH_IMPROVE_CTRL |= 0x08;
	}
	else{
		*DSP_SPH_COD_CTRL &= ~0x0800;
		*DSP_SPH_SCH_IMPROVE_CTRL &= ~0x08;
	}


	if(cfg->swi == SAL_VM_SWITCH_ON && cfg->idle == true){//idle vm record
		*DSP_SPH_MUTE_CTRL |= 0x0002;
		SALI_Config_SRC(SAL_APP_TYPE_3GCall, IsWBLink(cfg->codec));
		SALI_Enable_Codec(cfg->codec, cfg->codec);
		SALI_Set_Sch_Delay(cfg->delR, cfg->delW, cfg->delM, 0, SAL_UNKNOWN);
		SALI_VBI_Reset();
	}
	else if(cfg->swi == SAL_VM_SWITCH_OFF && cfg->idle == true){
		*DSP_SPH_MUTE_CTRL &= ~0x0002;
		SALI_VBI_End();
		SALI_Disable_Codec();
	}

}

//rat: 0 -> 2g, 1 -> 3g
void SALI_VM_GetFrame(uint8 rat, Sal_VM_Frame *vmfrm)
{
	vmfrm->enc_mode = *DSP_SPH_Encoder_Used_Mode;
	vmfrm->dec_mode = *DSP_SPH_Decoder_Used_Mode;

	vmfrm->dbgInfo_addr = DSP_SPH_VM_DBG_INFO;

	if(rat == 0){// 2g
	vmfrm->enc_hdr = *DSP_SPH_2G_SE_DATA_HDR;
	vmfrm->enc_hb_addr = DSP_SPH_2G_SE_DATA_HB;
	vmfrm->dec_hdr = *DSP_SPH_2G_SD_DATA_HDR;
	vmfrm->dec_hb_addr = DSP_SPH_2G_SD_DATA_HB;
	}
	else if(rat == 1){// 3g
	vmfrm->enc_hdr = *DSP_SPH_3G_SE_DATA_HDR;
	vmfrm->enc_hb_addr = DSP_SPH_3G_SE_DATA_HB;
	vmfrm->dec_hdr = *DSP_SPH_3G_SD_DATA_HDR;
	vmfrm->dec_hb_addr = DSP_SPH_3G_SD_DATA_HB;
	}

	vmfrm->enh_dbgInfo_addr = DSP_DM_ADDR(6, *DSP_SPH_ENH_DEBUG_ADDR);
	
}


void SALI_EPL_GetFrame(Sal_EPL_Frame *eplfrm)
{
	#if defined(MT6280)
	eplfrm->ul_pre_buf = DSP_DM_ADDR(7, 0x03C0);
	eplfrm->ul_pos_buf = DSP_DM_ADDR(7, 0x0280);
	eplfrm->dl_pre_buf = DSP_DM_ADDR(7, 0x0000);
	eplfrm->dl_pos_buf = DSP_DM_ADDR(7, 0x0140);
	eplfrm->ul2_pos_buf = DSP_DM_ADDR(5, 0x3400); 	
	#elif defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6290) || defined(MT6571)
	eplfrm->ul_pre_buf = DSP_DM_ADDR(7, *DSP_SPH_EPL_UL_PRE_BUF);
	eplfrm->ul_pos_buf = DSP_DM_ADDR(7, *DSP_SPH_EPL_UL_POS_BUF);
	eplfrm->dl_pre_buf = DSP_DM_ADDR(7, *DSP_SPH_EPL_DL_PRE_BUF);
	eplfrm->dl_pos_buf = DSP_DM_ADDR(7, *DSP_SPH_EPL_DL_POS_BUF);
	#else
	eplfrm->ul_pre_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_UL_PRE_BUF);
	eplfrm->ul_pos_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_UL_POS_BUF);
	eplfrm->dl_pre_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_DL_PRE_BUF);
	eplfrm->dl_pos_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_DL_POS_BUF);
	#endif
	#if defined(MT6280) || defined(MT6589) || defined(MT6572) || defined(MT6582) || defined(MT6592) || defined(MT6290)
	eplfrm->ul2_pos_buf = SALI_PcmEx_GetBuf(SAL_PCMEX_BUF_SE2);
	#elif defined(MT6571)
	eplfrm->ul2_pos_buf = DSP_DM_ADDR(7, *DSP_SPH_EPL_UL2_POS_BUF);
	#else
	eplfrm->ul2_pos_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_UL2_POS_BUF);
	#endif
	#if !defined(MT6280) && !defined(MT6589) && !defined(MT6572) && !defined(MT6582) && !defined(MT6592) && !defined(MT6290) && !defined(MT6571)
	eplfrm->ul3_pos_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_UL3_POS_BUF);
	eplfrm->ul4_pos_buf = DSP_DM_ADDR(8, *DSP_SPH_EPL_UL4_POS_BUF);
	#else
	eplfrm->ul3_pos_buf = *DSP_SPH_EPL_UL3_POS_BUF; //dummy
	eplfrm->ul4_pos_buf = *DSP_SPH_EPL_UL4_POS_BUF; //dummy
	#endif

	if(*DSP_SPH_EPL_BND & 0x1)
		eplfrm->ul_pre_len = 320;
	else
		eplfrm->ul_pre_len = 160;

	if(*DSP_SPH_EPL_BND & 0x2)
		eplfrm->ul_pos_len = 320;
	else
		eplfrm->ul_pos_len = 160;

	if(*DSP_SPH_EPL_BND & 0x4)
		eplfrm->dl_pre_len = 320;
	else
		eplfrm->dl_pre_len = 160;

	if(*DSP_SPH_EPL_BND & 0x8)
		eplfrm->dl_pos_len = 320;
	else
		eplfrm->dl_pos_len = 160;

	if(*DSP_SPH_EPL_BND & 0x10)
		eplfrm->ul2_pos_len = 320;
	else
		eplfrm->ul2_pos_len = 160;
		
	if(*DSP_SPH_EPL_BND & 0x20)
		eplfrm->ul3_pos_len = 320;
	else
		eplfrm->ul3_pos_len = 160;
	
	if(*DSP_SPH_EPL_BND & 0x40)
		eplfrm->ul4_pos_len = 320;
	else
		eplfrm->ul4_pos_len = 160;
	
}


void SALI_BT_Config(Sal_BT_Config *cfg)
{

	if(cfg->feed_cfg){

		*DSP_SPH_BT_MODE = (uint16)cfg->mode << 3;//set bt mode
		
		if(cfg->mode == SAL_BT_MODE_GAIN)
			*DSP_SPH_BT_MODE += cfg->gainmode_dl_gain & 0x7;

		if(cfg->mode == SAL_BT_MODE_LINEAR){
			*DSP_SPH_BT_CTRL = cfg->linear_ctrl & 0xf;//clear and set
			*DSP_SPH_BT_CTRL |= cfg->linear_reverse?0x10:0;
			*DSP_SPH_BT_CTRL |= (uint16)cfg->linear_ul_gain << 8;
		}

		
	}
	else{
		*DSP_SPH_BT_MODE = 0;
		*DSP_SPH_BT_CTRL = 0;
	}
	
}

bool SALI_BT_IsEnable()
{
	return ((*DSP_SPH_8K_CTRL & 0x2000) != 0);
}


void SALI_Mute_Ctrl(Sal_Mute_Point_t ctrl, bool mute)
{
	
	L1Audio_Msg_SAL_SET_VALUE_MULTI(SAL_DSP_VALUE_NAME(2), ctrl, mute, SAL_UNKNOWN, SAL_UNKNOWN, SAL_UNKNOWN);
	
		switch(ctrl)
		{
		case SAL_MUTE_UL_POS_EN:
			if(mute)
			*DSP_SPH_MUTE_CTRL |= 0x1;
			else
			*DSP_SPH_MUTE_CTRL &= ~0x0001;	
			break;
		case SAL_MUTE_UL_PRE_EN:
			if(mute)
			*DSP_SPH_MUTE_CTRL |= 0x4;
			else
			*DSP_SPH_MUTE_CTRL &= ~0x0004;
			break;
		case SAL_MUTE_UL_IN_EN:
			if(mute)
			*DSP_SPH_ENH_DYMANIC_SWITCH |= 0x1;
			else
			*DSP_SPH_ENH_DYMANIC_SWITCH &= ~0x0001;
			break;
		case SAL_MUTE_DL_PRE_SD:
			if(mute)
			*DSP_SPH_MUTE_CTRL |= 0x2;
			else
			*DSP_SPH_MUTE_CTRL &= ~0x0002;
			break;
		case SAL_MUTE_DL_PRE_EN:
			if(mute)
			*DSP_SPH_MUTE_CTRL |= 0x8;
			else
			*DSP_SPH_MUTE_CTRL &= ~0x0008;
			break;
		case SAL_MUTE_DL_8K:
			if(mute)
			*DSP_SPH_MUTE_CTRL |= 0x8000;
			else
			*DSP_SPH_MUTE_CTRL &= ~0x8000;
			break;
		default:
			break;
		}

}

bool SALI_Mute_Check(Sal_Mute_Point_t ctrl)
{
		uint16 val = 0;
		
		switch(ctrl)
		{
		case SAL_MUTE_UL_POS_EN:
			val = *DSP_SPH_MUTE_CTRL & 0x1;
			break;
		case SAL_MUTE_UL_PRE_EN:
			val = *DSP_SPH_MUTE_CTRL & 0X4;
			break;
		case SAL_MUTE_UL_IN_EN:
			val = *DSP_SPH_ENH_DYMANIC_SWITCH & 0x1;
			break;
		case SAL_MUTE_DL_PRE_SD:
			val = *DSP_SPH_MUTE_CTRL & 0x2;
			break;
		case SAL_MUTE_DL_PRE_EN:
			val = *DSP_SPH_MUTE_CTRL & 0x8;
			break;
		case SAL_MUTE_DL_8K:
			val = *DSP_SPH_MUTE_CTRL & 0x8000;
			break;	
		default:
			break;
		}

		return (val != 0);
}

void SALI_CTM_Switch(bool on)
{
	if(on)
		*DSP_SPH_CTM_CTRL = 0x1;
	else
		*DSP_SPH_CTM_CTRL = 0x2;
}

void SALI_CTM_SetGain(uint16 limit, uint16 update)
{
	*DSP_SPH_CTM_AMR_CODEBOOK_GAIN_LIMIT = limit;
	*DSP_SPH_CTM_AMR_CODEBOOK_GAIN_UPDATE = update;
}

uint16 SALI_CTM_GetValue(uint16 type)
{
	uint16 value = 0;
	switch(type)
	{
	case SAL_CTM_VALUE_TYPE_FACCH_REPORT:
		value = *DSP_SPH_CTM_BFI_FACCH_REPORT;
		break;
	case SAL_CTM_VALUE_TYPE_AMR_RX_RATE:
		value = *DSP_SPH_CTM_AMR_REAL_RX_TYPE;
		break;
	default:
		break;
	}
	return value;
}

bool SALI_CTM_IsIdle()
{
	return (*DSP_SPH_CTM_CTRL == 0);
}

bool SALI_CTM_IsOff()
{
	return (*DSP_SPH_CTM_CTRL == 2);
}

void SALI_AGC1_Config(Sal_AGC_Config_t *cfg)
{
	uint16 value = 0;
	if(cfg->main_switch)
		value |= 0x8000;
	if(cfg->gain_switch)
		value |= 0x2000;
	if(cfg->hpiir_switch)
		value |= 0x1000;
	if(cfg->vad_switch)
		value |= 0x0800;
	if(cfg->init_req)
		value |= 0x0008;

	if(cfg->cosim)
		value |= 0x0100;

	*DSP_SPH_AGC1_CTRL = value;
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(7), value);
}

void SALI_AGC2_Config(Sal_AGC_Config_t *cfg)
{
	uint16 value = 0;
	if(cfg->main_switch)
		value |= 0x8000;
	if(cfg->gain_switch)
		value |= 0x2000;
	if(cfg->hpiir_switch)
		value |= 0x1000;
	if(cfg->vad_switch)
		value |= 0x0800;
	if(cfg->init_req)
		value |= 0x0008;

	if(cfg->cosim)
		value |= 0x0100;

	*DSP_SPH_AGC2_CTRL = value;
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(10), value);
}

void SALI_AGC3_Config(Sal_AGC_Config_t *cfg)
{
	uint16 value = 0;
	if(cfg->main_switch)
		value |= 0x8000;
	if(cfg->gain_switch)
		value |= 0x2000;
	if(cfg->hpiir_switch)
		value |= 0x1000;
	if(cfg->vad_switch)
		value |= 0x0800;
	if(cfg->init_req)
		value |= 0x0008;

	if(cfg->cosim)
		value |= 0x0100;

	*DSP_SPH_AGC3_CTRL = value;
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(11), value);
}

void SALI_AGC4_Config(Sal_AGC_Config_t *cfg)
{
	uint16 value = 0;
	if(cfg->main_switch)
		value |= 0x8000;
	if(cfg->gain_switch)
		value |= 0x2000;
	if(cfg->hpiir_switch)
		value |= 0x1000;
	if(cfg->vad_switch)
		value |= 0x0800;
	if(cfg->init_req)
		value |= 0x0008;

	if(cfg->cosim)
		value |= 0x0100;

	*DSP_SPH_AGC4_CTRL = value;
	L1Audio_Msg_SAL_SET_VALUE(SAL_DSP_VALUE_NAME(12), value);
}

void SALI_NotchFilter_Enable(bool ena, bool thirdStageIIR)
{
	if(ena){
		*DSP_SPH_SFE_CTRL |= 0x200;
		*DSP_SPH_SFE_CTRL &= ~0x800;
		if(thirdStageIIR)
			*DSP_SPH_SFE_CTRL |= 0x400;
		else
			*DSP_SPH_SFE_CTRL &= ~0x400;
	}
	else
		*DSP_SPH_SFE_CTRL &= ~0x200;

}

void SALI_8K_Resync(bool ul, int16 ul_offset, bool dl, int16 dl_offset)
{
	if(ul){
		*DSP_SPH_8K_RESYNC_CTRL |= 0x1;
		*DSP_SPH_8K_RESYNC_OFFSET_UL = ul_offset;
		}	
		
	if(dl){
		*DSP_SPH_8K_RESYNC_CTRL |= 0x2;
		*DSP_SPH_8K_RESYNC_OFFSET_DL = dl_offset;
		}
}

void SALI_2G_SMR_Switch(bool on)
{
	if(on)
	{
		*DSP_SPH_SCH_IMPROVE_CTRL |= SALI_IMPROVE_2G_SMR;
	}
	else
	{
		*DSP_SPH_SCH_IMPROVE_CTRL &= ~SALI_IMPROVE_2G_SMR;
	}
}

void SALI_VOLTE_SetInfo(Sal_VOLTE_info_t info, uint16 val)
{
	switch(info){
		case SAL_VOLTE_INFO_JBM_OUT_SN:
			*DSP_SPH_VOLTE_JBM_OUT_SN = val;
			break;
		default:
			break;
	}
}

void SALI_GetWarnMsg(uint16 *ulcode, uint16 *dlcode)
{
	*ulcode = *DSP_SPH_WARN_MSG_UL;
	*dlcode = *DSP_SPH_WARN_MSG_DL;
}
