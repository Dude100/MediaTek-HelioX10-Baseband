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
 *   SST_intrCtrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   Header file for non-release version of interrupt control.
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
#ifndef __SST_INTRCTRL_H__
#define __SST_INTRCTRL_H__

#include "emi_sw.h"
#include "us_timer.h"
#include "reg_base.h"
#if defined(__CR4__)
#include "cp15_int.h"
#endif

#define __HARD_REAL_TIME_CHECK__

#if defined(MT6238) || defined(MT6239)
#define SET_HW_LIMIT() EMI_DISABLE_GMC_HIGHPRIO(1, 1, 0)
#elif defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
#define SET_HW_LIMIT() EMI_Set_GMCBW_HardMode()
#else
#define SET_HW_LIMIT() 
#endif 

#if defined(__DYNAMICALLY_SET_EMI_ARB_SOFT_MODE__)
#define RESTORE_HW_LIMIT() EMI_Set_GMCBW_SoftMode()
#else
#define RESTORE_HW_LIMIT() 
#endif 

//temp enlarge 60 qbit to 110 bit to avoid unknown timing check fail.
#if defined(MT6595)
//for DRAM DVFS(Dynamic voltage frequency switch) impact
//60+50
#define SST_HR_DUR (110) 
#elif (defined(MT6752) && defined(__MD1__))
//for DRAM DVFS(Dynamic voltage frequency switch) impact
//60+5
#define SST_HR_DUR (65)
#elif (defined(MT6752) && defined(__MD2__))
// K2 MD2 hard real time adjustment
#define SST_HR_DUR (120) 
#else
#define SST_HR_DUR (60)
#endif



//#endif

#if defined(TK6280)
#define SST_IRQ_MASK (0x00000080)
#else
#define SST_IRQ_MASK (0x000000C0)
#endif


#if defined(__CR4__)
#define GET_AND_SAVED_TIME(v) do{\
                                 CP15_PMU_GET_CYCLE_CNT(IRQMaskCounter); \
                                 IRQMaskValue = v;\
                              }while(0)

#define GET_CURRENT_TIME(v) do{\
                                CP15_PMU_GET_CYCLE_CNT(v); \
                             }while(0)

#define GET_SAVED_TIME(v,s)  do{\
                                v = IRQMaskCounter;\
                                s = IRQMaskValue;\
                             }while(0)
                             
#define GET_DURATION(d,t1,t2) do{\
                                 d = ((t2) >= (t1)) ? ((t2) - (t1)) : (0xFFFFFFFF - (t1) + (t2));\
                              }while(0)

#if defined(MCU_480M)

#if SST_HR_DUR==110
#define IRQ_DISABLE_MAX_DURATION    51303    /* ((((110/13)*12)*480)/0.95)=51303 cycle at 480M */
#elif SST_HR_DUR==120
#define IRQ_DISABLE_MAX_DURATION    55966    /* ((((120/13)*12)*480)/0.95)=55966 cycle at 480M */
#elif SST_HR_DUR==65
#define IRQ_DISABLE_MAX_DURATION    30315    /* ((((65/13)*12)*480)/0.95)=30315 cycle at 480M */
#else
#define IRQ_DISABLE_MAX_DURATION    27983    /* ((((60/13)*12)*480)/0.95)=27983 cycle at 480M */
#endif//SST_HR_DUR
#define CPU_CYC_CNT_IN_1QBIT        466      /* ((((1/13)*12)*480)/0.95)=466 cycle at 480M */

/* The reason to add number of CPU cycles in 1 QBit in CPU cycle to QBit translation is to avoid */
/* QBit is under-estimated in integer calcuation and may get the result "59QBit". This is confusing */
#define TRANS_TO_QBIT(d,s) do{\
                              d = ((((((s + CPU_CYC_CNT_IN_1QBIT)*95)/100)/480)*13)/12);\
                           }while(0)
                           
#else    /* !MCU_480M */

//#error "Unspecific MCU Clock"
#define IRQ_DISABLE_MAX_DURATION    ((unsigned int)((((SST_HR_DUR*12*CPU_CLOCK_MHZ)/13))/0.95))
#define CPU_CYC_CNT_IN_1QBIT        ((unsigned int)(((12*CPU_CLOCK_MHZ)/13)/0.95))
/* The reason to add number of CPU cycles in 1 QBit in CPU cycle to QBit translation is to avoid */
/* QBit is under-estimated in integer calcuation and may get the result "59QBit". This is confusing */
#define TRANS_TO_QBIT(d,s) do{\
                              d = ((((((s + CPU_CYC_CNT_IN_1QBIT)*95)/100)/CPU_CLOCK_MHZ)*13)/12);\
                           }while(0)


#endif    /* MCU_480M */

#elif defined(__HW_US_TIMER_SUPPORT__) /* !__CR4__ */
#define GET_AND_SAVED_TIME(v) do{\
                                 IRQMaskCounter = ust_get_current_time();\
                                 IRQMaskValue = v;\
                              }while(0)

#define GET_CURRENT_TIME(v) do{\
                                v = ust_get_current_time();\
                             }while(0)

#define GET_SAVED_TIME(v,s)  do{\
                                v = IRQMaskCounter;\
                                s = IRQMaskValue;\
                             }while(0)
                             
#define GET_DURATION(d,t1,t2) do{\
                                 d = ((t2) >= (t1)) ? ((t2) - (t1)) : (USCNT_WRAP - (t1) + (t2));\
                              }while(0)

#define TRANS_TO_QBIT(d,s) do{\
                              d = (((s)*13)/12);\
                              }while(0)

#if SST_HR_DUR==110
#define IRQ_DISABLE_MAX_DURATION    102  /* (110/13)*12=102 us */
#elif SST_HR_DUR==120
#define IRQ_DISABLE_MAX_DURATION    110    /* (120/13)*12=110 us */
#elif SST_HR_DUR==65
#define IRQ_DISABLE_MAX_DURATION    60    /* (65/13)*12=60 us */
#else
#define IRQ_DISABLE_MAX_DURATION    56    /* (60/13)*12=56 us */
#endif

#else /* !__CR4__ && !__HW_US_TIMER_SUPPORT__ */

#define GET_AND_SAVED_TIME(v) do{\
                                v |= *(volatile kal_uint16 *)(TDMA_base + 0x00) << 16;\
                             }while(0)

#define GET_CURRENT_TIME(v) do{\
                                v = *(volatile kal_uint16 *)(TDMA_base + 0x00);\
                                if(v == 0) {\
                                   v = *(volatile kal_uint16 *)(TDMA_base + 0x00);\
                                }\
                             }while(0)

#define GET_SAVED_TIME(v,s)  do{\
                                v=s>>16;\
                             }while(0)

#define GET_DURATION(d,t1,t2) do{\
                                 if(t2 >= t1)\
                                 {\
                                    d=t2-t1;\
                                 } else {\
                                    d = *(volatile kal_uint16 *)(TDMA_base + 0x04);\
                                    d = (d - t1) +t2;\
                                 }\
                              }while(0)

#define TRANS_TO_QBIT(d,s) do{\
                              d = s;\
                           }while(0)

#define IRQ_DISABLE_MAX_DURATION    SST_HR_DUR

#endif /* __CR4__ */

#endif /* __SST_INTRCTRL_H__ */
