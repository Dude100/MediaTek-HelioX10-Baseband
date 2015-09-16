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
 *   l1_interface.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file implements layer1 inteface function for system initialization usage
 *
 * Author:
 * -------
 * -------
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 *
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*************************************************************************
 * Include Statements
 *************************************************************************/
#include "l1_interface.h"
#include "l1_interface_reg.h"

#if MD_DRV_IS_UDVT_FH_SUPPORT
#include "l1_fh_interface.h"
#endif

/*************************************************************************
 * Function and variable declaration
 *************************************************************************/

// These functions may be called at system bootup time,
// so we need to keep the code and data in primary MAUI
void L1D_HW_TDMA_AUX_TIME_SETUP(kal_uint16 event0, kal_uint16 event1)
{
   kal_uint16 d16 = (kal_uint16)HW_READ(TDMA_AUXEVENA);
   HW_WRITE(TDMA_AUXEV0, event0);
   HW_WRITE(TDMA_AUXEV1, event1);
   HW_WRITE(TDMA_AUXEVENA, (d16|0x3));
}
/* ------------------------------------------------------------------------- */

kal_uint16 L1D_TDMA_GET_TQCNT( void )
{
   return HW_READ(TQ_CURRENT_COUNT);
}
/* ------------------------------------------------------------------------- */

kal_uint16 L1D_HW_TDMA_GET_TQWRAP( void )
{
   return HW_READ(TQ_WRAP);
}
/* ------------------------------------------------------------------------- */

kal_uint32 L1D_HW_TDMA_GET_32KCNT( void )
{
   return HW_READ(RTCCOUNT);
}
/* ------------------------------------------------------------------------- */

/*************************************************************************
 * FUNCTION
 *    HW_TDMA_Start
 *
 * DESCRIPTION
 *    This function powers on TDMA module.
 *
 * PARAMETERS
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
void HW_TDMA_Start(void)
{
   HW_WRITE( PDN_CLR2, PDN_CON_TDMA ); /*power on TDMA*/
}

/*************************************************************************
 * FUNCTION
 *    HW_TDMA_Enable_CTIRQ1
 *
 * DESCRIPTION
 *    This function enable TDMA module CTIRQ1.
 *
 * PARAMETERS
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *
 *************************************************************************/
void HW_TDMA_Enable_CTIRQ1(void)
{
   kal_uint32 dX;

   HW_TDMA_Start();
   HW_WRITE(CTIRQ1, MD_DRV_TQ_CTIRQ1);
   HW_WRITE(TQ_WRAP, MD_DRV_TQ_WRAP_COUNT-1);
   HW_WRITE(TQ_EVENT_VALID, MD_DRV_TQ_VALIDATE_COUNT);
   dX  = HW_READ(EVENT_ENA(0));
   dX |= 0x2;
   HW_WRITE(EVENT_ENA(0), dX);
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void MD_DRV_L1D_PWR_SLEEP( void )
{
#if MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
   HW_WRITE( PDN_SET2,      SLPOFF&MODEMSYS_MASK );
   HW_WRITE( MD2G_PDN_SET0, SLPOFF&MD2G_MASK1    );
   HW_WRITE( MD2G_PDN_SET2, SLPOFF&MD2G_MASK2    );
   HW_WRITE( PDN_CLR2,      SLPON &MODEMSYS_MASK );
   HW_WRITE( MD2G_PDN_CLR0, SLPON &MD2G_MASK1    );
   HW_WRITE( MD2G_PDN_CLR2, SLPON &MD2G_MASK2    );
#elif MD_DRV_IS_CHIP_MT6575
   HW_WRITE( PDN_SET2,      SLPOFF&MCUSYS_MASK1  );
   HW_WRITE( PDN_SET3,      SLPOFF&MCUSYS_MASK2  );
   HW_WRITE( MD2G_PDN_SET1, SLPOFF&MD2G_MASK     );
   HW_WRITE( PDN_CLR2,      SLPON &MCUSYS_MASK1  );
   HW_WRITE( PDN_CLR3,      SLPON &MCUSYS_MASK2  );
   HW_WRITE( MD2G_PDN_CLR1, SLPON &MD2G_MASK     );
#elif MD_DRV_IS_CHIP_MT6573
   HW_WRITE( PDN_SET2,      SLPOFF&MCUSYS_MASK   );
   HW_WRITE( MD2G_PDN_SET1, SLPOFF&MD2G_MASK     );
   HW_WRITE( PDN_CLR2,      SLPON &MCUSYS_MASK   );
   HW_WRITE( MD2G_PDN_CLR1, SLPON &MD2G_MASK     );
   HW_WRITE( AP_PDN_CLR1,   SLPON &APMCUSYS_MASK );
#elif MD_DRV_IS_CHIP_MT6276
   HW_WRITE( PDN_SET2,      SLPOFF&MCUSYS_MASK   );
   HW_WRITE( MD2G_PDN_SET1, SLPOFF&MD2G_MASK     );
   HW_WRITE( PDN_CLR2,      SLPON &MCUSYS_MASK   );
   HW_WRITE( MD2G_PDN_CLR1, SLPON &MD2G_MASK     );
#else
   #error "Please check PDN related settings"
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void MD_DRV_L1D_DisableAllIRQ( void )
{
   HW_WRITE( EVENT_ENA(0), (HW_READ(EVENT_ENA(0))&0x0000)|MD_DRV_EVTENA0_SLOW_EN_SEL );
   HW_WRITE( EVENT_ENA(1), (HW_READ(EVENT_ENA(1))&0x0080) );
   HW_WRITE( EVENT_ENA(2), 0x0000 );
   HW_WRITE( EVENT_ENA(3), 0x0000 );
   HW_WRITE( EVENT_ENA(4), 0x0000 );
   HW_WRITE( EVENT_ENA(5), 0x0000 );
   HW_WRITE( EVENT_ENA(6), 0x0000 );
   #if MD_DRV_IS_TXPC_CL_AUXADC_SUPPORT
   HW_WRITE( EVENT_ENA(7), (HW_READ(EVENT_ENA(7))&0x0003) );
   #endif
   #if MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
   HW_WRITE( EVENT_ENA(8), 0x0000 );
   HW_WRITE( EVENT_ENA(9), 0x0000 );
   #endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void MD_DRV_L1D_Exit( void )
{
   MD_DRV_L1D_PWR_SLEEP();
   MD_DRV_L1D_DisableAllIRQ();
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/*************************************************************************
 * FUNCTION
 *    HW_wait_32k_start
 *
 * DESCRIPTION
 *    This function use 13M to calibrate 32k clock
 *
 * PARAMETERS
 *    None
 *
 * RETURNS
 *    None
 *
 * GLOBALS AFFECTED
 *    None
 *
 * NOTES
 *    IS_FM_ON_26M_CHIP is defiend in l1d_cid.h, we should request L1D to update them
 *
 *************************************************************************/
#if MD_DRV_IS_CHIP_MT6276 || MD_DRV_IS_CHIP_MT6573 || MD_DRV_IS_CHIP_MT6575 || MD_DRV_IS_CHIP_MT6250 || MD_DRV_IS_CHIP_MT6280 || MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
#define FM_RESULT_UPPER_BOUND    1900
#define FM_RESULT_LOWER_BOUND    1300
#else
#error "Please check upper/lower bound of FM result"
#endif

void HW_wait_32k_start(void)
{
#if MD_DRV_IS_CENTRALIZED_SMM_CHIP

   #ifdef __UE_SIMULATOR__
#undef   FRC_CMD_MAGIC_VALUE
#define  FRC_CMD_MAGIC_VALUE            0x62760000
   #endif

   /*CSMM use 26M to calibrate 32K at TOPSM HW module*/
   kal_uint32 result;
   int count = 0;
   int waiting_32k_count = 80000;
   kal_uint32 tmp_T0 = 0, tmp_T1 = 0, tmp_D0 = 0, tmp_D1 = 0;

   /* Enable FRC for FM. */
   HW_WRITE( SM_FRC_CON, (FRC_CMD_MAGIC_VALUE+0x00000001) );
   HW_WRITE( SM_FM_CAL, 2 ); /*calibrate 2T 32K, ideal got 1586.9T 26M*/

   while(count < waiting_32k_count)
   {
      /* Enable FM and no need to Unmask FM INT. */
      HW_WRITE(SM_FM_CON, 0x11);

      /* Polling until FM_EN bit is cleared. */
      while((HW_READ(SM_FM_CON) & 0x1)) ;

      tmp_T0 = (HW_READ(SM_FM_T0)) & 0xFFFFFF;
      tmp_D0 = (HW_READ(SM_FM_T0)) >> 24;
      tmp_T1 = (HW_READ(SM_FM_T1)) & 0xFFFFFF;
      tmp_D1 = (HW_READ(SM_FM_T1)) >> 24;
      if( tmp_T1 > tmp_T0 )
      {
         result = (tmp_T1*26+tmp_D1) - (tmp_T0*26+tmp_D0);
      }
      else /* 1MHz FRC wrap case: */
      {
         result = ((tmp_T1+0x1000000)*26+tmp_D1) - (tmp_T0*26+tmp_D0);
      }
      if( FM_RESULT_LOWER_BOUND < result && result < FM_RESULT_UPPER_BOUND )
      {
         /* Clear INT of FM. Need to set bit[4] to mask it. */
         HW_WRITE(SM_FM_CON, 0x110);
         break;
      }
      count++;
   }
#else
   #error "Please implement HW_wait_32k_start() for non-centralized-sleep-mode chip"
#endif
}
/*=======================================================================*/

/*************************************************************************
 *    Interface to enable the frequency for the UDVT load
 *************************************************************************/
#if MD_DRV_IS_UDVT_FH_SUPPORT
extern const unsigned int FH_table_UDVT[]; /*Freqency hopping table*/
unsigned int MPLL_FH_idx = 0 ;
static L1DFHParamUDVT l1dfh_udvt;

static void FH_init_FHtable( void );
static void ReSet_MPLLFH_FHSTR( void );
static void FH_set_fhset( unsigned short win_idx, sFHset* _fhset );

   #if MD_DRV_IS_CHIP_MT6583_MD1 || MD_DRV_IS_CHIP_MT6583_MD2 || MD_DRV_IS_CHIP_MT6572 || MD_DRV_IS_CHIP_MT6290 || MD_DRV_IS_CHIP_MT6595 || MD_DRV_IS_CHIP_MT6752_MD1 || MD_DRV_IS_CHIP_MT6752_MD2
const unsigned int FH_table_UDVT[] =
{
   0x500, 0x4F4, 0x4E8, 0x4DC, 0x4D0, 0x4C4, 0x4B8, 0x4AD,  //0 ~7
   0x4A1, 0x495, 0x489, 0x47D, 0x471, 0x466, 0x45A, 0x44E,  //8 ~15
   0x442, 0x436, 0x42A, 0x41F, 0x413, 0x407, 0x3FB, 0x3EF,  //16~23
   0x3E3, 0x3D8, 0x3CC, 0x3C0, 0x3B4, 0x3A8, 0x39C, 0x390,  //24~31
   0x385, 0x379, 0x36D, 0x361, 0x355, 0x349, 0x33E, 0x332,  //32~39
   0x326, 0x31A, 0x30E, 0x302, 0x2F7, 0x2EB, 0x2DF, 0x2D3,  //40~47
   0x2C7, 0x2BB, 0x2B0, 0x2A4, 0x298, 0x28C, 0x280, 0x274,  //48~55
   0x268, 0x25D, 0x251, 0x245, 0x239, 0x22D, 0x221, 0x216,  //56~63
};
   #else
const unsigned int FH_table_UDVT[] =
{
   0,    5,    7,    10,   12,   14,   17,   20,    //0~7
   25,   29,   32,   33,   36,   39,   42,   44,    //8~15
   47,   50,   52,   56,   60,   62,   63,   65,    //16~23
   68,   71,   76,   80,   81,   83,   84,   92,    //24~31
   125,  134,  137,  142,  144,  159,  209,  243,   //32~39
   252,  259,  262,  277,  284,  291,  294,  298,   //40~47
   301,  323,  328,  337,  345,  354,  361,  367,   //48~55
   370,  375,  379,  386,  393,  404,  415,  423,   //56~63
};
   #endif

#define FH_table_UDVT_SIZE  (sizeof(FH_table_UDVT)/sizeof(int))

static void MD_DRV_WAIT_TIME_QB( short time_qb )
{
   unsigned short  last_qb, cur_qb;
   short  qb_diff, qb_remain;

   qb_remain = time_qb;
   last_qb = HW_READ( TQ_CURRENT_COUNT );
   while( qb_remain>0 )
   {  cur_qb = HW_READ( TQ_CURRENT_COUNT );
      qb_diff = cur_qb-last_qb;
      qb_remain -= (qb_diff<0) ? 1 : qb_diff;
      last_qb = cur_qb;
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void SetupMPLLFH( void )
{
   ReSet_MPLLFH_FHSTR();

   if( MPLL_FH_idx%FH_table_UDVT_SIZE < 32)
   {  l1dfh_udvt.FHset_Modem.fh_set_l = 1 << (MPLL_FH_idx%FH_table_UDVT_SIZE);
      l1dfh_udvt.FHset_Modem.fh_set_h = 0;
   }
   else
   {  l1dfh_udvt.FHset_Modem.fh_set_l = 0;
      l1dfh_udvt.FHset_Modem.fh_set_h = 1 << ((MPLL_FH_idx%FH_table_UDVT_SIZE)-32);
   }
   MPLL_FH_idx++;

   FH_set_fhset( 0 , &l1dfh_udvt.FHset_Modem );

   HW_WRITE( TQ_BIAS_CONT, 0 );
   HW_WRITE( TDMA_FHSTR(0), 256 );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void FH_init_FHtable(void)
{
   int i;
   unsigned int d16;

   /*Indicate write FH table at addr 0*/
   HW_WRITE( TDMA_FHCON(2), TDMA_FHCON2_DEFAULT );

   /*Write FH table*/
   for( i = 0 ; i < FH_table_UDVT_SIZE; i++ )
   {  d16 = TDMA_FHCON3_DEFAULT_INT | FH_table_UDVT[i];
      HW_WRITE( TDMA_FHCON(3), d16 );
      MD_DRV_WAIT_TIME_QB(1);
   }
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void ReSet_MPLLFH_FHSTR( void )
{
   int i;

   for( i = 0; i < 6; i++ )
   {  HW_WRITE(TDMA_FHSTR(i), MD_DRV_TQ_MAXIMUM);  }

}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

static void FH_set_fhset( unsigned short win_idx, sFHset* _fhset )
{
   /*MNPLL*/
   HW_WRITE( MNPLL_FHSET(win_idx,0), (  _fhset->fh_set_l      & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,1), ( (_fhset->fh_set_l>>16) & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,2), (  _fhset->fh_set_h      & 0xFFFF) );
   HW_WRITE( MNPLL_FHSET(win_idx,3), ( (_fhset->fh_set_h>>16) & 0xFFFF) );
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */
#endif

void Frequency_hopping_enable( void )
{
#if MD_DRV_IS_UDVT_FH_SUPPORT
   int d16;
   sFHset FHset = { (1 << FREE_RUN_BASE), 0 }; // -1%

   /*Enable DDS. Let RG_MDDS_EN[0] = 1*/
   /*It is done in INT_SetPLL()*/

   /*Power on TDMA*/
   HW_TDMA_Start();

   /*Init TQ_WRAP and Event validate*/
   HW_WRITE( TQ_WRAP, MD_DRV_TQ_WRAP_COUNT-1 );
   HW_WRITE( TQ_EVENT_VALID, MD_DRV_TQ_VALIDATE_COUNT );

   /*Low index of FH_table_UDVT first*/
   d16 = HW_READ(TDMA_FHCON(0));
   d16 &= TDMA_FHCON0_MASK;
   HW_WRITE( TDMA_FHCON(0), d16 );

   /*MNPLL free run range*/
   L1D_SET_MNPLL_FREE_RUN_RANGE();

   /*EFPLL free run range*/
   L1D_SET_EFPLL_FREE_RUN_RANGE();

   /*MNPLL FH type*/
   L1D_SET_MNPLL_FH_TYPE();

   /*EFPLL FH type*/
   L1D_SET_EFPLL_FH_TYPE();

   /*Reset FH TDMA timer*/
   ReSet_MPLLFH_FHSTR();

   /*init frequency hopping table*/
   FH_init_FHtable();

   FH_set_fhset( 0, &FHset );
   HW_WRITE( TQ_BIAS_CONT, 0 );
   HW_WRITE( TDMA_FHSTR(0), 0 );
#endif
}
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

void L1D_Xmode_Latch(void)
{
   unsigned short d16;
   unsigned short ctrl       = 0x1C3F;                               // SCTRL_IMOD(0,29);
   unsigned long  data       = 0x0FBDD4D0;                           // CW251[D19]:DCXO_XMODE_LATCH = 0x1
   volatile long  addr;
   unsigned long  BSI_base80 = 0x83070000;
   unsigned long  dummy_read;

   /*   init BSI   */
   HW_WRITE( PDN_CLR2, PDN_CON_BSI );
   HW_WRITE( PDN_CLR4, PDN_CON_BSI );

   d16  = HW_READ( ((APBADDR)  (BSI_base80+0x0C08)) );        // BSI_IO_CON
   d16 &= ~( 0x1<<8 );                                        /* clear RESET_MODE (bit 8) */
   HW_WRITE( ((APBADDR)  (BSI_base80+0x0C08)), d16 );         // BSI_IO_CON

   /*   immediately send  BSI */
   HW_WRITE( ((APBADDR32)(BSI_base80+0x0000)), 0x0008001 );   // HW_WRITE( BSI_CON, SCTRL_IMOD_MAIN );
   addr = (long)((APBADDR)  (BSI_base80+0x0004));             // BSI_Dn_CON(0);
   HW_WRITE( (APBADDR)addr, ctrl );  addr += 4;
   HW_WRITE( (APBADDR32)(addr), (data) );                     // HW_WRITE_BSI_DATA( addr, data );

   dummy_read = HW_READ( (APBADDR32)(addr) );

   HW_WRITE( ((APBADDR)  (BSI_base80+0x0508)), 0x8000 );      // HW_WRITE( GSM_BSI_ACTUPT, 0x8000 );

   dummy_read = HW_READ( (APBADDR32)(addr) ); 
   (void)dummy_read;

   HW_WRITE( ((APBADDR32)(BSI_base80+0x0000)), 0x8401 );      // HW_WRITE( BSI_CON, SCTRL_IMOD_SEND );

   /*  immediately mode end  */
   HW_WRITE( ((APBADDR32)(BSI_base80+0x0000)), 0x0008001  );  // HW_WRITE( BSI_CON,  SCTRL_MAIN );
   HW_WRITE( ((APBADDR32)(BSI_base80+0x0500)), 0xFFFFFFFF );  // MT6280 is 42
   HW_WRITE( ((APBADDR32)(BSI_base80+0x0504)), 0x000003FF );

}

/*=======================================================================*/
