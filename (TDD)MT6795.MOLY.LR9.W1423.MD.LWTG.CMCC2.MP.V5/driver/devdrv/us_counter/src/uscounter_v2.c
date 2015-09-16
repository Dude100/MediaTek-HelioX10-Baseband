/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   uscounter.c
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   This function implements uscounter.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

/*******************************************************************************
 * Include header files
 *******************************************************************************/

#include "kal_public_api.h"
#include "reg_base.h"
#include "us_timer.h"
#include "l1_interface.h"
//#include "kal_general_types.h"
#include "sleepdrv_interface.h"
#include "intrCtrl.h"       /* for SaveAndSetIRQMask */
#include "devdrv_ls.h"      /* for section declaration */
#if defined(__HW_OSTICK_CNT__)
#include "ostd_private.h"  /* for HW Frame Counter */
#endif /* __HW_OSTICK_CNT__ */
#if !defined(__CENTRALIZED_SLEEP_MANAGER__)
#include "drvpdn.h"
#endif /* __CENTRALIZED_SLEEP_MANAGER__ */

#if defined(__HW_US_TIMER_SUPPORT__)

#if defined(__ALIGN_2G_CLOCK__)
static kal_uint32 Pre_USCNTI DEVDRV_LS_INTSRAM_ZI = 0;
static kal_uint32 FrameCount DEVDRV_LS_INTSRAM_ZI = 0;
#elif !defined(__HW_OSTICK_CNT__)
static kal_uint32 Pre_USCNTI   DEVDRV_LS_INTSRAM_ZI = 0;
static kal_uint64 Total_USCNTI DEVDRV_LS_INTSRAM_ZI = 0;
#endif

/*************************************************************************
* FUNCTION
*  USC_Start
*
* DESCRIPTION
*  This function starts the uscounter.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Start()
{

#ifdef ESIM_BUILD_CONFIG
   HW_WRITE(USCNT_CON, 1);
#elif !defined(__CENTRALIZED_SLEEP_MANAGER__)
  #define FRC_CON                  (TOPSM_base+0x80)

  #if defined(MT6290)
    #define ALC_CON                  (0x90000000UL)
    DRV_Reg32(FRC_CON) = 0x72080001;
    DRV_Reg32(ALC_CON) = 0x00000001;
  #elif defined(MT6595)||(defined(MT6752)&&defined(__MD1__))
    #define ALC_CON                  ((volatile kal_uint32*)BASE_ADDR_ALC)
    PDN_CLR(PDN_TOPSM);
    DRV_Reg32(FRC_CON) = 0x11530001;
    DRV_Reg32(ALC_CON) = 0x00000001;
  #endif /* MTxxxx */

#else
    MD_TOPSM_EnableFRC();
#endif
}

/*************************************************************************
* FUNCTION
*  USC_Stop
*
* DESCRIPTION
*  This function stops the uscounter.
*
* PARAMETERS
*  none
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Stop()
{
#ifdef ESIM_BUILD_CONFIG
   HW_WRITE(USCNT_CON, 1);
#else
   kal_uint32 SHOULD_NOT_STOP_US_COUNTER = 0;
   ASSERT(SHOULD_NOT_STOP_US_COUNTER);
   //DRV_WriteReg32(BASE_ADDR_MDTOPSM+0x80, 1);
#endif   
}

/*************************************************************************
* FUNCTION
*  USC_Cal_32KFM
*
* DESCRIPTION
*  This function calibrates the uscounter.
*
* PARAMETERS
*  Cal_32K       -    32K crystal counts
*  Cal_26M       -    counts of 26M clock when 32K crystal count to Cal_32K
*
* RETURNS
*  none
*
*************************************************************************/
void USC_Cal_32KFM( kal_uint32 Cal_32K, kal_uint32 Cal_26M)
{
    double Ratio;
    Ratio = ((double)Cal_26M)* ( ((double)USCNT_FREQ) * ( (double)(1<<18) ) / 26000000 ) / ((double)Cal_32K);
    HW_WRITE(F32K_FM, (kal_uint32)(Ratio)); 
}

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
#endif

/*************************************************************************
* FUNCTION
*  USC_Get_TimeStamp
*
* DESCRIPTION
*  This function calculate the frame number.
*
* PARAMETERS
*  none
*
* RETURNS
*  Frame number since system power up
*
*************************************************************************/
kal_uint32 DEVDRV_LS_INTSRAM_ROCODE USC_Get_TimeStamp( void )
{
#if defined(__ALIGN_2G_CLOCK__)

    kal_uint32 uscnti,curFrame,_savedMask;
    
    _savedMask = SaveAndSetIRQMask();
    
    uscnti= ust_get_current_time();
    if (uscnti >= Pre_USCNTI) {
        curFrame = USCNT_TO_FRAME( uscnti - Pre_USCNTI ); // dur/3250/(120/26)
    } else {
        curFrame = USCNT_TO_FRAME((USCNT_WRAP - Pre_USCNTI) + uscnti);
    }
    FrameCount += curFrame;
    
    Pre_USCNTI += FRAME_TO_USCNT(curFrame);

    if( Pre_USCNTI > USCNT_WRAP )
    {
        Pre_USCNTI -= USCNT_WRAP;
    }
    
    RestoreIRQMask(_savedMask);
    
    return FrameCount;

#else

    kal_uint32 uscnti,curFrame,_savedMask;

    _savedMask = SaveAndSetIRQMask();

#if defined(__HW_OSTICK_CNT__)
    HW_WRITE(OST_CMD, CMD_MAGIC_VALUE | 0x02);
    curFrame = HW_READ(OST_TIMER_CNT_R);
#else
    uscnti= ust_get_current_time();

    if (uscnti >= Pre_USCNTI) {
        Total_USCNTI += (uscnti - Pre_USCNTI);
    } else {
        Total_USCNTI += ((USCNT_WRAP - Pre_USCNTI) + uscnti);
    }    

    Pre_USCNTI = uscnti;

    curFrame = USCNT_TO_FRAME(Total_USCNTI);
#endif

    RestoreIRQMask(_savedMask);


    return curFrame;
#endif
}

#endif //__HW_US_TIMER_SUPPORT__

