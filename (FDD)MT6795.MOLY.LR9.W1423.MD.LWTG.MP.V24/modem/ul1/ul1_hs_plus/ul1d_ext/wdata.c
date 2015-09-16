/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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
 * wdata.c
 *
 * Project:
 * --------
 * MT6268
 *
 * Description:
 * ------------
 * Variables/Arrays for customer to make their own configurations.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *----------------------------------------------------------------------------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *----------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*===============================================================================*/

#include "kal_general_types.h"
#include "ul1d_custom_rf.h"
#include "ul1d_rf_public.h"
#include "ul1d_rf_common.h"
#include "ul1d_rf_cid.h"
#include "wcustomdata.h"
#include "ul1cal.h"
#if (IS_3G_MIPI_SUPPORT)
#include "ul1d_custom_mipi.h"
#endif
#if (IS_3G_ET_SUPPORT)
#include "mml1_custom_mipi.h"
#endif

/*===============================================================================*/

#if defined(__MTK_TARGET__)

#define __ATTRIBUTE_SECTION__(_s) __attribute__ ((section(#_s)))
#define __ATTRIBUTE_ALIGNED__(_a) __attribute__ ((aligned((_a))))
#define __ATTRIBUTE_ZI__          __attribute__ ((zero_init))

#else

#define __ATTRIBUTE_SECTION__(_s)
#define __ATTRIBUTE_ALIGNED__(_a) 
#define __ATTRIBUTE_ZI__  

#endif 

#define __SECTION_INTSRAM_RODATA__   //Removed due to AutoTCM __ATTRIBUTE_SECTION__(INTSRAM_RODATA)
#define __SECTION_INTSRAM_ROCODE__   //Removed due to AutoTCM __ATTRIBUTE_SECTION__(INTSRAM_ROCODE)
#define __SECTION_INTSRAM_ZI__       //Removed due to AutoTCM __ATTRIBUTE_SECTION__(INTSRAM_ZI)
#define __SECTION_INTSRAM_RW__       //Removed due to AutoTCM __ATTRIBUTE_SECTION__(INTSRAM_RW)

#define __SECTION_NONCACHEDZI__      __ATTRIBUTE_SECTION__(NONCACHEDZI) __ATTRIBUTE_ZI__
#define __SECTION_NONCACHEDRW__      __ATTRIBUTE_SECTION__(NONCACHEDRW) 

#define __SECTION_DYNAMICCACHEABLEZI_C__   __ATTRIBUTE_SECTION__(DYNAMICCACHEABLEZI_C) __ATTRIBUTE_ZI__


#define MAX_DIST(m,n) (((m)>(n))?(m):(n))
#define MIN_DIST(m,n) (((m)<(n))?(m):(n))

/*Notes: due to use SR(T)1,PR(T)1,SR(T)3,PR(T)3 for max and min distance calculating, which is
         used for the RF timer setting, so must make sure the SR1,PR1 must larger than other
         event timing, and PT1,ST1 is smaller than other event timing, even in ul1d_custom_rf.h
         you can set like SR2>SR1 */
#define MAX_RX_START_OFFSET MAX_DIST(TC_SR1, TC_PR1)
#define MAX_TX_START_OFFSET MAX_DIST(TC_ST1, TC_PT1)
#define MAX_RX_END_OFFSET MAX_DIST(TC_SR3, TC_PR3A)
#define MAX_TX_END_OFFSET MAX_DIST(TC_ST3, TC_PT3A)
#define MIN_RX_END_OFFSET MIN_DIST(TC_SR3, TC_PR3)
#define MIN_TX_END_OFFSET MIN_DIST(TC_ST3, TC_PT3)

#define MAX_MODE_START_OFFSET MAX_DIST(TC_SR2B, TC_ST2C)

#if IS_URF_MT6162 || IS_URF_MT6162_DUAL
kal_int16 delay_LDO    = (TC_ST1-TC_ST2)*8;
kal_int16 delay_DFMLDO = (TC_ST2-TC_ST2B)*8;

__SECTION_INTSRAM_RW__
kal_int16 delay_TXDFM  = (TC_ST2B-TC_ST2C)*8;
kal_int16 delay_PLL    = (TC_ST2C)*8;
#endif

kal_int16 max_rx_start_offset = MAX_RX_START_OFFSET;
kal_int16 max_tx_start_offset = MAX_TX_START_OFFSET;

kal_int16 max_txcal_start_offset = TC_ST_CAL;

kal_int16 max_rx_end_offset = MAX_RX_END_OFFSET;
kal_int16 max_tx_end_offset = MAX_TX_END_OFFSET;

__SECTION_INTSRAM_RW__
kal_int16 min_rx_end_offset = MIN_RX_END_OFFSET;


__SECTION_INTSRAM_RW__
kal_int16 min_tx_end_offset = MIN_TX_END_OFFSET;

kal_uint8 max_rx_end_reg_idx;
kal_int16 min_rx_off_evt_cancel_margin;

//Add for R8 to support RXD and Dual cell
kal_int16 max_rx_dc_reconfig_offset = TC_DC_SR1;
kal_int16 max_rxd_start_offset = MAX_DIST(TC_RXD_SR1, TC_PR1_2); 
kal_int16 min_rxd_end_offset = MIN_DIST(TC_RXD_SR3, TC_PR3_2);
//kal_int16 max_rxd_start_offset = MAX_DIST(TC_RXD_SR1, TC_PR1); 
//kal_int16 min_rxd_end_offset = MIN_DIST(TC_RXD_SR3, TC_PR3)

kal_uint16 max_offset   = MAX_OFFSET;

__SECTION_INTSRAM_RW__
kal_uint16 vm_offset    = (MAX_OFFSET - VM_OFFSET);
kal_uint16 vbias_offset = (MAX_OFFSET - VBIAS_OFFSET);
kal_uint16 dc2dc_offset = (MAX_OFFSET - DC2DC_OFFSET);
kal_uint16 vga_offset   = (MAX_OFFSET - VGA_OFFSET);
#if IS_3G_MIPI_SUPPORT
kal_bool is_3g_mipi_enable = IS_3G_MIPI_ENABLE;
#endif
#if IS_URF_MT6169
/*Only for MT6169 temperature check, since the temperature curve had been changed from -65 to 90 in 
  new 6290 project. If you want to adjust TADC curve, you may need to adjust this two constat
  also, to avoid the miss-match check assert. 
  TDAC_DIFF_90_DEGREE is 664(90 degree) - 320(-10 degree).
  TDAC_DIFF_65_DEGREE is 533(65 degree) - 307(-10 degree).
  tdac_threshold is the average of TDAC_DIFF_90_DEGREE and TDAC_DIFF_65_DEGREE */
#define    TDAC_DIFF_90_DEGREE (344) /*RIO5 Proto3 measurement value, by SA/Tim */
#define    TDAC_DIFF_65_DEGREE (226)
kal_uint32 tdac_threshold = (((TDAC_DIFF_90_DEGREE - TDAC_DIFF_65_DEGREE) >> 1) + TDAC_DIFF_65_DEGREE);
#endif
#if IS_3G_ET_SUPPORT
kal_bool is_3g_et_enable = (IS_3G_ET_ENABLE);
kal_uint32 etCwValueDumpAllTable[UL1_MIPI_ET_CW_NUM];
kal_uint32 etCwNum   = UL1_MIPI_ET_CW_NUM;
kal_uint32 etBsiPort = UL1_MIPI_PORT_ET;
kal_uint32 etUsid    = MIPI_USID_ET;
#endif

kal_uint8  pa_section = PA_SECTION;

kal_int16  UMTS_RX_START_TQ_TABLE[9] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TC_SR1,
   /* TQ_SLOT_BEGIN(i) + */ -TC_SR2,
   /* TQ_SLOT_BEGIN(i) + */ -TC_SR2B,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR1,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR2,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR2B,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR1_2, //Add for RXD
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR2_2, //Add for RXD
   /* TQ_SLOT_BEGIN(i) + */ -TC_PR2B_2 //Add for RXD
};


__SECTION_INTSRAM_RW__
kal_int16  UMTS_RX_END_TQ_TABLE[5] =
{
   /* TQ_SLOT_BEGIN(i) + */ TC_SR3,
   /* TQ_SLOT_BEGIN(i) + */ TC_PR3,
   /* TQ_SLOT_BEGIN(i) + */ TC_PR3A,
   /* TQ_SLOT_BEGIN(i) + */ TC_PR3_2,  //Add for RXD
   /* TQ_SLOT_BEGIN(i) + */ TC_PR3A_2  //Add for RXD
};


kal_int16  UMTS_TX_START_TQ_TABLE[7] =
{
   /* TQ_SLOT_BEGIN(i) + */ -TC_ST1,
   /* TQ_SLOT_BEGIN(i) + */ -TC_ST2,
   /* TQ_SLOT_BEGIN(i) + */ -TC_ST2B,
   /* TQ_SLOT_BEGIN(i) + */ -TC_ST2C,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PT1,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PT2,
   /* TQ_SLOT_BEGIN(i) + */ -TC_PT2B
};

kal_int16  UMTS_TX_END_TQ_TABLE[3] =
{
   /* TQ_SLOT_BEGIN(i) + */ TC_ST3,
   /* TQ_SLOT_BEGIN(i) + */ TC_PT3,
   /* TQ_SLOT_BEGIN(i) + */ TC_PT3A
};

//Add following table to support RXD and Dual Cell
#if IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
kal_int16  UMTS_RX_DC_RECONFIG_TQ_TABLE[3] =
#else
kal_int16  UMTS_RX_DC_RECONFIG_TQ_TABLE[2] =
#endif
{
   -TC_DC_SR1,
   -TC_DC_SR2,
#if IS_URF_MT6167 || IS_URF_MT6166 || IS_URF_MT6169
   -TC_DC_SR2B,
#endif
};

#if IS_RF_RXD_SUPPORT
kal_int16  UMTS_RXD_START_TQ_TABLE[7] =
{
   -TC_RXD_SR1,
   -TC_PR1,
   -TC_PR2,
   -TC_PR2B,
   -TC_PR1_2,
   -TC_PR2_2,
   -TC_PR2B_2
};

kal_int16  UMTS_RXD_END_TQ_TABLE[5] =
{
   TC_RXD_SR3,
   TC_PR3,
   TC_PR3A,
   TC_PR3_2,
   TC_PR3A_2
};
#endif

//Notes: UMTS_PDATA_TABLE is used to determine which pin is for Rx and which pin is for Tx
//       so can't put other data except BPI here
BPI_data_type  UMTS_PDATA_TABLE[][2][5] =
{     /* FrequencyBand0  */
   {  {  PDATA_BAND1_PR1, PDATA_BAND1_PR2, PDATA_BAND1_PR2B, PDATA_BAND1_PR3, PDATA_BAND1_PR3A  } ,   /* RX */
      {  PDATA_BAND1_PT1, PDATA_BAND1_PT2, PDATA_BAND1_PT2B, PDATA_BAND1_PT3, PDATA_BAND1_PT3A  } ,   /* TX */
   }, /* FrequencyBand1  */
   {  {  PDATA_BAND1_PR1, PDATA_BAND1_PR2, PDATA_BAND1_PR2B, PDATA_BAND1_PR3, PDATA_BAND1_PR3A  } ,   /* RX */
      {  PDATA_BAND1_PT1, PDATA_BAND1_PT2, PDATA_BAND1_PT2B, PDATA_BAND1_PT3, PDATA_BAND1_PT3A  } ,   /* TX */
   }, /* FrequencyBand2  */
   {  {  PDATA_BAND2_PR1, PDATA_BAND2_PR2, PDATA_BAND2_PR2B, PDATA_BAND2_PR3, PDATA_BAND2_PR3A  } ,   /* RX */
      {  PDATA_BAND2_PT1, PDATA_BAND2_PT2, PDATA_BAND2_PT2B, PDATA_BAND2_PT3, PDATA_BAND2_PT3A  } ,   /* TX */
   }, /* FrequencyBand4 */
   {  {  PDATA_BAND4_PR1, PDATA_BAND4_PR2, PDATA_BAND4_PR2B, PDATA_BAND4_PR3, PDATA_BAND4_PR3A  } ,   /* RX */
      {  PDATA_BAND4_PT1, PDATA_BAND4_PT2, PDATA_BAND4_PT2B, PDATA_BAND4_PT3, PDATA_BAND4_PT3A  } ,   /* TX */
   }, /* FrequencyBand5  */
   {  {  PDATA_BAND5_PR1, PDATA_BAND5_PR2, PDATA_BAND5_PR2B, PDATA_BAND5_PR3, PDATA_BAND5_PR3A  } ,   /* RX */
      {  PDATA_BAND5_PT1, PDATA_BAND5_PT2, PDATA_BAND5_PT2B, PDATA_BAND5_PT3, PDATA_BAND5_PT3A  } ,   /* TX */
   }, /* FrequencyBand8  */                                                                                
   {  {  PDATA_BAND8_PR1, PDATA_BAND8_PR2, PDATA_BAND8_PR2B, PDATA_BAND8_PR3, PDATA_BAND8_PR3A  } ,   /* RX */
      {  PDATA_BAND8_PT1, PDATA_BAND8_PT2, PDATA_BAND8_PT2B, PDATA_BAND8_PT3, PDATA_BAND8_PT3A  } ,   /* TX */
   }
};


//Notes: UMTS_PDATA2_TABLE is used to determine which pin is for RXD
//       so can't put other data except BPI here

__SECTION_INTSRAM_RW__
BPI_data_type  UMTS_PDATA2_RX_TABLE[][5] =
{  /* FrequencyBand0  */
   {  PDATA2_BAND1_PR1, PDATA2_BAND1_PR2, PDATA2_BAND1_PR2B, PDATA2_BAND1_PR3, PDATA2_BAND1_PR3A  } ,   /* RX */
   /* FrequencyBand1  */
   {  PDATA2_BAND1_PR1, PDATA2_BAND1_PR2, PDATA2_BAND1_PR2B, PDATA2_BAND1_PR3, PDATA2_BAND1_PR3A  } ,   /* RX */
   /* FrequencyBand2  */
   {  PDATA2_BAND2_PR1, PDATA2_BAND2_PR2, PDATA2_BAND2_PR2B, PDATA2_BAND2_PR3, PDATA2_BAND2_PR3A  } ,   /* RX */
   /* FrequencyBand4 */
   {  PDATA2_BAND4_PR1, PDATA2_BAND4_PR2, PDATA2_BAND4_PR2B, PDATA2_BAND4_PR3, PDATA2_BAND4_PR3A  } ,   /* RX */
   /* FrequencyBand5  */
   {  PDATA2_BAND5_PR1, PDATA2_BAND5_PR2, PDATA2_BAND5_PR2B, PDATA2_BAND5_PR3, PDATA2_BAND5_PR3A  } ,   /* RX */
   /* FrequencyBand8  */                                                                                
   {  PDATA2_BAND8_PR1, PDATA2_BAND8_PR2, PDATA2_BAND8_PR2B, PDATA2_BAND8_PR3, PDATA2_BAND8_PR3A  } ,   /* RX */
};

#if IS_3G_TAS_SUPPORT

U_sUl1dRfTasData UMTS_TAS_RF_TABLE =
{
 /*umtsTasMask*/
 {
  UMTS_TAS_BPI_PIN_MASK
 },
 /*umtsTasPdata*/
 {
  PDATA_Band1_TAS1,
  PDATA_Band1_TAS2,
  PDATA_Band1_TAS3,
  PDATA_Band2_TAS1,
  PDATA_Band2_TAS2,
  PDATA_Band2_TAS3,
  PDATA_Band3_TAS1,
  PDATA_Band3_TAS2,
  PDATA_Band3_TAS3,
  PDATA_Band4_TAS1,
  PDATA_Band4_TAS2,
  PDATA_Band4_TAS3,
  PDATA_Band5_TAS1,
  PDATA_Band5_TAS2,
  PDATA_Band5_TAS3,
  PDATA_Band6_TAS1,
  PDATA_Band6_TAS2,
  PDATA_Band6_TAS3,
  PDATA_Band7_TAS1,
  PDATA_Band7_TAS2,
  PDATA_Band7_TAS3,
  PDATA_Band8_TAS1,
  PDATA_Band8_TAS2,
  PDATA_Band8_TAS3,
  PDATA_Band9_TAS1,
  PDATA_Band9_TAS2,
  PDATA_Band9_TAS3,
  PDATA_Band10_TAS1,
  PDATA_Band10_TAS2,
  PDATA_Band10_TAS3,
  PDATA_Band11_TAS1,
  PDATA_Band11_TAS2,
  PDATA_Band11_TAS3,
  PDATA_Band19_TAS1,
  PDATA_Band19_TAS2,
  PDATA_Band19_TAS3
 }
};


BPI_data_type  UMTS_TAS_PDATA_TABLE[][UL1_ANTENNA_NUM+1] =
{     /* Non-used  */
   {   
      {  0, PDATA_Band1_TAS1, PDATA_Band1_TAS2, PDATA_Band1_TAS3}
   }, /* RX_HIGHBAND1_INDICATOR  */
   {   
      {  0, PDATA_Band1_TAS1, PDATA_Band1_TAS2, PDATA_Band1_TAS3}
   }, /* RX_HIGHBAND2_INDICATOR  */
   {   
      {  0, PDATA_Band2_TAS1, PDATA_Band2_TAS2, PDATA_Band2_TAS3}
   }, /* RX_HIGHBAND3_INDICATOR */
   {   
      {  0, PDATA_Band4_TAS1, PDATA_Band4_TAS2, PDATA_Band4_TAS3}
   }, /* RX_LOWBAND1_INDICATOR  */
   {   
      {  0, PDATA_Band5_TAS1, PDATA_Band5_TAS2, PDATA_Band5_TAS3}
   }, /* RX_LOWBAND2_INDICATOR  */                                                                                
   {   
      {  0, PDATA_Band8_TAS1, PDATA_Band8_TAS2, PDATA_Band8_TAS3}
   }
};


#endif/*IS_3G_TAS_SUPPORT*/

kal_uint8 DC2DC[3/*pa_mode*/] = 
{
   DC2DC_H,
   DC2DC_M,
   DC2DC_L
};

kal_uint8 VM_data[3/*pa_mode*/] = 
{
   VM_H,
   VM_M,
   VM_L
};


/* mtk02653: For checking the notch tuning scenario (cases) */
/* and also checking whether wrong customer setting exists. */
kal_uint8 band1_ch_sel =  BAND1_CHANNEL_SEL;
kal_uint8 band2_ch_sel =  BAND2_CHANNEL_SEL;
kal_uint8 band3_ch_sel =  BAND3_CHANNEL_SEL;
kal_uint8 band4_ch_sel =  BAND4_CHANNEL_SEL;

__SECTION_INTSRAM_RW__
kal_uint8 band5_ch_sel =  BAND5_CHANNEL_SEL;
kal_uint8 band6_ch_sel =  BAND6_CHANNEL_SEL;
kal_uint8 band8_ch_sel =  BAND8_CHANNEL_SEL;
kal_uint8 band9_ch_sel =  BAND9_CHANNEL_SEL;
kal_uint8 band10_ch_sel = BAND10_CHANNEL_SEL;
kal_uint8 band11_ch_sel = BAND10_CHANNEL_SEL;
kal_uint8 band19_ch_sel = BAND19_CHANNEL_SEL;

#if IS_RF_RXD_SUPPORT
kal_uint8 band1_ch2_sel =  BAND1_CHANNEL2_SEL;
kal_uint8 band2_ch2_sel =  BAND2_CHANNEL2_SEL;
kal_uint8 band3_ch2_sel =  BAND3_CHANNEL2_SEL;
kal_uint8 band4_ch2_sel =  BAND4_CHANNEL2_SEL;
kal_uint8 band5_ch2_sel =  BAND5_CHANNEL2_SEL;
kal_uint8 band6_ch2_sel =  BAND6_CHANNEL2_SEL;
kal_uint8 band8_ch2_sel =  BAND8_CHANNEL2_SEL;
kal_uint8 band9_ch2_sel =  BAND9_CHANNEL2_SEL;
kal_uint8 band10_ch2_sel = BAND10_CHANNEL2_SEL;
kal_uint8 band11_ch2_sel = BAND11_CHANNEL2_SEL;
kal_uint8 band19_ch2_sel = BAND19_CHANNEL2_SEL;
#endif

kal_bool pmu_pasetting = PMU_PASETTING;
kal_bool ultra_low_cost= ULTRA_LOW_COST_EN;
kal_bool TM_enable = TEAMPERATURE_MEAS_EN;
kal_bool VPA_mode_setting = VPA_FPWM_MODE;

#if defined (__UMTS_R8__) 
/** [20130429 LY] replace 0xFFFFFFFF by custom setting to avoid false alarm of cal. data download */
//Should be quered by Band, customize in rf_custim.h to indicate support of RXD
#if IS_URF_MT6169
kal_uint32 rxd_support_mask = (((BAND1_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND1_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<0 : 0) |
                              (((BAND2_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND2_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<1 : 0) |
                              (((BAND3_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND3_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<2 : 0) |
                              (((BAND4_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND4_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<3 : 0) |
                              (((BAND5_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND5_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<4 : 0) |
                              (((BAND6_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND6_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<5 : 0) |
                              (((BAND8_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND8_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<7 : 0) |
                              (((BAND9_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND9_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))? 1<<8 : 0) |
                              (((BAND10_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND10_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))?1<<9: 0) |
                              (((BAND11_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND11_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))?1<<10:0) |
                              (((BAND19_CHANNEL2_SEL!=NON_USED_BAND)&&(BAND19_CHANNEL2_SEL!=NON_USED_BAND_ORIGIN))?1<<18:0);
#else
kal_uint32 rxd_support_mask = ((BAND1_CHANNEL2_SEL!=NON_USED_BAND)? 1<<0 : 0) |
                              ((BAND2_CHANNEL2_SEL!=NON_USED_BAND)? 1<<1 : 0) |
                              ((BAND3_CHANNEL2_SEL!=NON_USED_BAND)? 1<<2 : 0) |
                              ((BAND4_CHANNEL2_SEL!=NON_USED_BAND)? 1<<3 : 0) |
                              ((BAND5_CHANNEL2_SEL!=NON_USED_BAND)? 1<<4 : 0) |
                              ((BAND6_CHANNEL2_SEL!=NON_USED_BAND)? 1<<5 : 0) |
                              ((BAND8_CHANNEL2_SEL!=NON_USED_BAND)? 1<<7 : 0) |
                              ((BAND9_CHANNEL2_SEL!=NON_USED_BAND)? 1<<8 : 0) |
                              ((BAND10_CHANNEL2_SEL!=NON_USED_BAND)?1<<9 : 0) |
                              ((BAND11_CHANNEL2_SEL!=NON_USED_BAND)?1<<10: 0) |
                              ((BAND19_CHANNEL2_SEL!=NON_USED_BAND)?1<<18: 0);
#endif
kal_uint32 rx_diversity_always_on = RX_DIVERSITY_ALWAYS_ON;
kal_uint32 pa_dirft_bitmap        = PA_DIRFT_COMPENSATION;
#endif

kal_uint8 ul1d_BandInfo[5] ={ RX_HIGHBAND1_INDICATOR,
                              RX_HIGHBAND2_INDICATOR,
                              RX_HIGHBAND3_INDICATOR,
                              RX_LOWBAND1_INDICATOR,
                              RX_LOWBAND2_INDICATOR};
	
kal_uint8 band_output_sel[20]={TX_NULL_BAND,
                               BAND1_OUTPUT_SEL,
                               BAND2_OUTPUT_SEL,
                               BAND3_OUTPUT_SEL,
                               BAND4_OUTPUT_SEL,
                               BAND5_OUTPUT_SEL,
                               BAND6_OUTPUT_SEL,
                               TX_NULL_BAND,
                               BAND8_OUTPUT_SEL,
                               BAND9_OUTPUT_SEL,
                               BAND10_OUTPUT_SEL,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               TX_NULL_BAND,
                               BAND19_OUTPUT_SEL};

kal_bool is_rf_setting_by_nvram = RF_SETTING_BY_NVRAM;
                                      
/* mtk02653: */
/* Pre-processing compiler option concerning to supported RF band mode  */
/* to see if there is any wrong customer configurations.                */











//kevin phase3 for COSIM RF
/* To fit the case once user who does not use Modem Bin Update tool but modifies makefile/ul1d_custom_rf.h band setting and rebuild */
U_sUl1dRfCustomInputData UMTS_RF_CUSTOM_INPUT_DATA =
{
   /* Start Pattern */
   0x1234ABCD,

   /* Structure Version */
   1,

   /* RF Type */
   UMTS_RF_TYPE,

   /* isDataUpdate */
   1,

#if defined (__UL1_HS_PLUS_PLATFORM__)
   /* proityOfNvramInCustomization */
   RF_SETTING_BY_NVRAM,
#endif

   /* umtsRfPaControlTimingOffset */
   {
      MAX_OFFSET,
      VM_OFFSET,
      VBIAS_OFFSET,
      DC2DC_OFFSET,
      VGA_OFFSET
   },

   /* umtsBsiBpiTiming */
   {
      /* RX window end timing */
      -TC_PR1,
      -TC_PR2,
      -TC_PR2B,

      /* RX window end timing */
      TC_PR3,
      TC_PR3A,

      /* TX window start timing */
      -TC_PT1,
      -TC_PT2,
      -TC_PT2B,

      /* TX window end timing */
      TC_PT3,
      TC_PT3A
   },

   /* umtsPdata */
   {
      /* Band 1 BPI data */
      PDATA_BAND1_PR1,
      PDATA_BAND1_PR2,
      PDATA_BAND1_PR2B,
      PDATA_BAND1_PR3,
      PDATA_BAND1_PR3A,
      PDATA_BAND1_PT1,
      PDATA_BAND1_PT2,
      PDATA_BAND1_PT2B,
      PDATA_BAND1_PT3,
      PDATA_BAND1_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND1_PR1,
      PDATA2_BAND1_PR2,
      PDATA2_BAND1_PR2B,
      PDATA2_BAND1_PR3,
      PDATA2_BAND1_PR3A,
   #endif
      
      /* Band 2 BPI data */
      PDATA_BAND2_PR1,
      PDATA_BAND2_PR2,
      PDATA_BAND2_PR2B,
      PDATA_BAND2_PR3,
      PDATA_BAND2_PR3A,
      PDATA_BAND2_PT1,
      PDATA_BAND2_PT2,
      PDATA_BAND2_PT2B,
      PDATA_BAND2_PT3,
      PDATA_BAND2_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND2_PR1,
      PDATA2_BAND2_PR2,
      PDATA2_BAND2_PR2B,
      PDATA2_BAND2_PR3,
      PDATA2_BAND2_PR3A,
   #endif
      
      /* Band 3 BPI data */
      PDATA_BAND3_PR1,
      PDATA_BAND3_PR2,
      PDATA_BAND3_PR2B,
      PDATA_BAND3_PR3,
      PDATA_BAND3_PR3A,
      PDATA_BAND3_PT1,
      PDATA_BAND3_PT2,
      PDATA_BAND3_PT2B,
      PDATA_BAND3_PT3,
      PDATA_BAND3_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND3_PR1,
      PDATA2_BAND3_PR2,
      PDATA2_BAND3_PR2B,
      PDATA2_BAND3_PR3,
      PDATA2_BAND3_PR3A,
   #endif
      
      /* Band 4 BPI data */
      PDATA_BAND4_PR1,
      PDATA_BAND4_PR2,
      PDATA_BAND4_PR2B,
      PDATA_BAND4_PR3,
      PDATA_BAND4_PR3A,
      PDATA_BAND4_PT1,
      PDATA_BAND4_PT2,
      PDATA_BAND4_PT2B,
      PDATA_BAND4_PT3,
      PDATA_BAND4_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND4_PR1,
      PDATA2_BAND4_PR2,
      PDATA2_BAND4_PR2B,
      PDATA2_BAND4_PR3,
      PDATA2_BAND4_PR3A,
   #endif
      
      /* Band 5 BPI data */
      PDATA_BAND5_PR1,
      PDATA_BAND5_PR2,
      PDATA_BAND5_PR2B,
      PDATA_BAND5_PR3,
      PDATA_BAND5_PR3A,
      PDATA_BAND5_PT1,
      PDATA_BAND5_PT2,
      PDATA_BAND5_PT2B,
      PDATA_BAND5_PT3,
      PDATA_BAND5_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND5_PR1,
      PDATA2_BAND5_PR2,
      PDATA2_BAND5_PR2B,
      PDATA2_BAND5_PR3,
      PDATA2_BAND5_PR3A,
   #endif
      
      /* Band 6 BPI data */
      PDATA_BAND6_PR1,
      PDATA_BAND6_PR2,
      PDATA_BAND6_PR2B,
      PDATA_BAND6_PR3,
      PDATA_BAND6_PR3A,
      PDATA_BAND6_PT1,
      PDATA_BAND6_PT2,
      PDATA_BAND6_PT2B,
      PDATA_BAND6_PT3,
      PDATA_BAND6_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND6_PR1,
      PDATA2_BAND6_PR2,
      PDATA2_BAND6_PR2B,
      PDATA2_BAND6_PR3,
      PDATA2_BAND6_PR3A,
   #endif      
      
      /* Band 7 BPI data */
      PDATA_BAND7_PR1,
      PDATA_BAND7_PR2,
      PDATA_BAND7_PR2B,
      PDATA_BAND7_PR3,
      PDATA_BAND7_PR3A,
      PDATA_BAND7_PT1,
      PDATA_BAND7_PT2,
      PDATA_BAND7_PT2B,
      PDATA_BAND7_PT3,
      PDATA_BAND7_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND7_PR1,
      PDATA2_BAND7_PR2,
      PDATA2_BAND7_PR2B,
      PDATA2_BAND7_PR3,
      PDATA2_BAND7_PR3A,
   #endif
      
      /* Band 8 BPI data */
      PDATA_BAND8_PR1,
      PDATA_BAND8_PR2,
      PDATA_BAND8_PR2B,
      PDATA_BAND8_PR3,
      PDATA_BAND8_PR3A,
      PDATA_BAND8_PT1,
      PDATA_BAND8_PT2,
      PDATA_BAND8_PT2B,
      PDATA_BAND8_PT3,
      PDATA_BAND8_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND8_PR1,
      PDATA2_BAND8_PR2,
      PDATA2_BAND8_PR2B,
      PDATA2_BAND8_PR3,
      PDATA2_BAND8_PR3A,
   #endif      
      
      /* Band 9 BPI data */
      PDATA_BAND9_PR1,
      PDATA_BAND9_PR2,
      PDATA_BAND9_PR2B,
      PDATA_BAND9_PR3,
      PDATA_BAND9_PR3A,
      PDATA_BAND9_PT1,
      PDATA_BAND9_PT2,
      PDATA_BAND9_PT2B,
      PDATA_BAND9_PT3,
      PDATA_BAND9_PT3A,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND9_PR1,
      PDATA2_BAND9_PR2,
      PDATA2_BAND9_PR2B,
      PDATA2_BAND9_PR3,
      PDATA2_BAND9_PR3A,
   #endif      
      
      /* Band 10 BPI data */
      PDATA_BAND10_PR1,
      PDATA_BAND10_PR2,
      PDATA_BAND10_PR2B,
      PDATA_BAND10_PR3,
      PDATA_BAND10_PR3A,
      PDATA_BAND10_PT1,
      PDATA_BAND10_PT2,
      PDATA_BAND10_PT2B,
      PDATA_BAND10_PT3,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA_BAND10_PT3A,
   #else
      PDATA_BAND10_PT3A
   #endif

   #if defined (__UL1_HS_PLUS_PLATFORM__)
      PDATA2_BAND10_PR1,
      PDATA2_BAND10_PR2,
      PDATA2_BAND10_PR2B,
      PDATA2_BAND10_PR3,
      PDATA2_BAND10_PR3A,

      /* Band 11 BPI data */
      PDATA_BAND11_PR1,
      PDATA_BAND11_PR2,
      PDATA_BAND11_PR2B,
      PDATA_BAND11_PR3,
      PDATA_BAND11_PR3A,
      PDATA_BAND11_PT1,
      PDATA_BAND11_PT2,
      PDATA_BAND11_PT2B,
      PDATA_BAND11_PT3,
      PDATA_BAND11_PT3A,
      PDATA2_BAND11_PR1,
      PDATA2_BAND11_PR2,
      PDATA2_BAND11_PR2B,
      PDATA2_BAND11_PR3,
      PDATA2_BAND11_PR3A,

      /* Band 19 BPI data */
      PDATA_BAND19_PR1,
      PDATA_BAND19_PR2,
      PDATA_BAND19_PR2B,
      PDATA_BAND19_PR3,
      PDATA_BAND19_PR3A,
      PDATA_BAND19_PT1,
      PDATA_BAND19_PT2,
      PDATA_BAND19_PT2B,
      PDATA_BAND19_PT3,
      PDATA_BAND19_PT3A,
      PDATA2_BAND19_PR1,
      PDATA2_BAND19_PR2,
      PDATA2_BAND19_PR2B,
      PDATA2_BAND19_PR3,
      PDATA2_BAND19_PR3A
   #endif      
   },

   /* umtsBandIndicator */
   {
      RX_HIGHBAND1_INDICATOR,
      RX_HIGHBAND2_INDICATOR,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      RX_HIGHBAND3_INDICATOR,  //HB3 is invalid for chips that supports 4 bands. Ex: MT6166
   #endif
      RX_LOWBAND1_INDICATOR,
      RX_LOWBAND2_INDICATOR
   },

   /* sUl1dRfRxLnaPortSel */
   {
      BAND1_CHANNEL_SEL,
      BAND2_CHANNEL_SEL,
      BAND3_CHANNEL_SEL,
      BAND4_CHANNEL_SEL,
      BAND5_CHANNEL_SEL,
      BAND6_CHANNEL_SEL,
      BAND8_CHANNEL_SEL,
      BAND9_CHANNEL_SEL,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      BAND10_CHANNEL_SEL,
      BAND11_CHANNEL_SEL,
      BAND19_CHANNEL_SEL,
   #else
      BAND10_CHANNEL_SEL
   #endif

      //BANDx_CHANNEL2_SEL is invalid for non-RxD chips. Ex: MT6166
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      BAND1_CHANNEL2_SEL,   
      BAND2_CHANNEL2_SEL,
      BAND3_CHANNEL2_SEL,
      BAND4_CHANNEL2_SEL,
      BAND5_CHANNEL2_SEL,
      BAND6_CHANNEL2_SEL,
      BAND8_CHANNEL2_SEL,
      BAND9_CHANNEL2_SEL,
      BAND10_CHANNEL2_SEL,
      BAND11_CHANNEL2_SEL,
      BAND19_CHANNEL2_SEL
   #endif
   },

   /* umtsTxPathSel */
   {
      BAND1_OUTPUT_SEL,
      BAND2_OUTPUT_SEL,
      BAND3_OUTPUT_SEL,
      BAND4_OUTPUT_SEL,
      BAND5_OUTPUT_SEL,
      BAND6_OUTPUT_SEL,
      BAND8_OUTPUT_SEL,
      BAND9_OUTPUT_SEL,
   #if defined (__UL1_HS_PLUS_PLATFORM__)
      BAND10_OUTPUT_SEL,
      BAND11_OUTPUT_SEL,
      BAND19_OUTPUT_SEL
   #else
      BAND10_OUTPUT_SEL
   #endif
   },

   /* xPMU_PA_CONTROL */
   PMU_PASETTING,

#if defined (__UL1_HS_PLUS_PLATFORM__)   
   /* umtsMprBackOff */
   {
      {
         MPR_BACK_OFF_HSDPA_BAND1 , MPR_BACK_OFF_HSDPA_BAND2 , MPR_BACK_OFF_HSDPA_BAND3 , MPR_BACK_OFF_HSDPA_BAND4 , MPR_BACK_OFF_HSDPA_BAND5 ,
         MPR_BACK_OFF_HSDPA_BAND6 , MPR_BACK_OFF_HSDPA_BAND7 , MPR_BACK_OFF_HSDPA_BAND8 , MPR_BACK_OFF_HSDPA_BAND9 , MPR_BACK_OFF_HSDPA_BAND10,
         MPR_BACK_OFF_HSDPA_BAND11, MPR_BACK_OFF_HSDPA_BAND12, MPR_BACK_OFF_HSDPA_BAND13, MPR_BACK_OFF_HSDPA_BAND14, MPR_BACK_OFF_HSDPA_BAND15,
         MPR_BACK_OFF_HSDPA_BAND16, MPR_BACK_OFF_HSDPA_BAND17, MPR_BACK_OFF_HSDPA_BAND18, MPR_BACK_OFF_HSDPA_BAND19, MPR_BACK_OFF_HSDPA_BAND19
      },
      {
         MPR_BACK_OFF_HSUPA_BAND1 , MPR_BACK_OFF_HSUPA_BAND2 , MPR_BACK_OFF_HSUPA_BAND3 , MPR_BACK_OFF_HSUPA_BAND4 , MPR_BACK_OFF_HSUPA_BAND5 ,
         MPR_BACK_OFF_HSUPA_BAND6 , MPR_BACK_OFF_HSUPA_BAND7 , MPR_BACK_OFF_HSUPA_BAND8 , MPR_BACK_OFF_HSUPA_BAND9 , MPR_BACK_OFF_HSUPA_BAND10,
         MPR_BACK_OFF_HSUPA_BAND11, MPR_BACK_OFF_HSUPA_BAND12, MPR_BACK_OFF_HSUPA_BAND13, MPR_BACK_OFF_HSUPA_BAND14, MPR_BACK_OFF_HSUPA_BAND15,
         MPR_BACK_OFF_HSUPA_BAND16, MPR_BACK_OFF_HSUPA_BAND17, MPR_BACK_OFF_HSUPA_BAND18, MPR_BACK_OFF_HSUPA_BAND19, MPR_BACK_OFF_HSUPA_BAND19
      }
   },
#endif
   
   /* RxD support bit map*/
   RX_DIVERSITY_ALWAYS_ON,
   
   /* Tx PA dirft compensation bit map*/
   PA_DIRFT_COMPENSATION,

   /*At MT6589+MT6320PMIC, Vrf18_1(MD1) can use bulk/LDO mode, this is the switch*/
   ULTRA_LOW_COST_EN,

   /*At MT6589/MT6280+OrionRF, temperature measurement enable switch */
   TEAMPERATURE_MEAS_EN,

   /*isDrdiNvramSaved, default set this to KAL_FALSE. Not support for customer change*/
   KAL_FALSE, 

   /*DRDI combined index, for second time and after all usage*/
   0xFFFF,
  
   /* Baseband Idle Mode RXD Feature enable Default ON */
#ifdef __IDLE_MODE_RXD_DEFAULT_ENABLE__
	 KAL_TRUE,
#else
	 KAL_FALSE,
#endif

#if IS_3G_TX_POWER_OFFSET_SUPPORT
   /*    Tx power offset */
   {
      TPO_3G_ENABLE,
      TPO_3G_META_ENABLE,
      TPO_3G_TABLE_ON_MASK,
      {
         TPO_3G_BIT_NUM_FOR_TABLE_0,
         TPO_3G_BIT_NUM_FOR_TABLE_1
      }
   },
#endif /* IS_3G_TX_POWER_OFFSET_SUPPORT */

#if IS_3G_FDD_RX_PATH_SELECTION_SUPPORT
   {
      KAL_FALSE,
      ANT_RX_BOTH,
   },
#endif /*IS_3G_FDD_RX_PATH_SELECTION_SUPPORT*/

   /* End Pattern */
   0xABCD1234
};
/*------------- Single Software Load for Multiple Components Compatible -------------*/
kal_uint8 ul1custom_debug_enable = UL1CUSTOM_DEBUG_ENABLE;
kal_uint8 ul1custom_gpio_set_nums = UL1CUSTOM_GPIO_SET_NUMS;
kal_uint8 ul1custom_adc_set_nums = UL1CUSTOM_ADC_SET_NUMS;
kal_uint8 ul1custom_nvram_barcode_set_nums = UL1CUSTOM_NVRAM_BARCODE_SET_NUMS;
kal_uint8 ul1custom_gpio_nums_in_calc = UL1CUSTOM_GPIO_NUMS_IN_CALC;
kal_uint8 ul1custom_ADC_nums_in_calc = UL1CUSTOM_ADC_NUMS_IN_CALC;
kal_uint8 ul1custom_nvram_barcode_nums_in_calc = UL1CUSTOM_NVRAM_BARCODE_NUMS_IN_CALC;
kal_uint8 ul1custom_first_index = UL1CUSTOM_FIRST_INDEX;
kal_uint8 ul1custom_second_index = UL1CUSTOM_SECOND_INDEX;
kal_uint8 ul1custom_third_index = UL1CUSTOM_THIRD_INDEX;
kal_uint8 ul1custom_first_index_base = UL1CUSTOM_FIRST_INDEX_BASE;
kal_uint8 ul1custom_gpio_num_of_detect_pins_in_use = UL1CUSTOM_GPIO_NUM_OF_DETECT_PINS_IN_USE;
kal_uint8 ul1custom_adc_level_total = UL1CUSTOM_ADC_LEVEL_TOTAL;
kal_uint8 ul1custom_barcode_read_digit_num = UL1CUSTOM_BARCODE_READ_DIGIT_NUM;
kal_uint8 ul1custom_barcode_digit_value_1 = UL1CUSTOM_BARCODE_DIGIT_VALUE_1;
kal_uint8 ul1custom_barcode_digit_value_2 = UL1CUSTOM_BARCODE_DIGIT_VALUE_2;
kal_uint8 ul1custom_barcode_digit_value_3 = UL1CUSTOM_BARCODE_DIGIT_VALUE_3;
kal_uint8 ul1custom_max_rf_support_band_num = UL1CUSTOM_MAX_RF_SUPPORT_BAND_NUM;
kal_uint8 ul1custom_adc_calibrate_enable = UL1CUSTOM_ADC_CALIBARTE_ENABLE;
kal_uint8 ul1custom_adc_bits = UL1CUSTOM_ADC_BITS;
kal_uint16 ul1custom_adc_meas_count_2_order = UL1CUSTOM_ADC_MEAS_COUNT_2_ORDER;
kal_uint16 ul1custom_total_set_nums = UL1CUSTOM_TOTAL_SET_NUMS;
kal_uint32 ul1custom_adc_max_input_voltage = UL1CUSTOM_ADC_MAX_INPUT_VOLTAGE;
/*------------- Single Software Load for Multiple Components Compatible -------------*/

#ifdef MT6589
#ifdef SWEFUSE_SKIP
kal_bool sw_efuse_check_skip = KAL_TRUE;
#else
kal_bool sw_efuse_check_skip = KAL_FALSE;
#endif
#endif

/** DCXO/VCTCXO switch by difinition of AFC_VCXO*/
#if defined (AFC_VCXO)
const kal_bool ul1d_afc_vcxo_support = KAL_TRUE;
#else
const kal_bool ul1d_afc_vcxo_support = KAL_FALSE;
#endif
