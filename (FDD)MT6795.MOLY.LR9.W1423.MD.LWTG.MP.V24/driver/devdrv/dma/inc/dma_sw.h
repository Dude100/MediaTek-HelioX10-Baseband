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
 *    dma_sw.h
 *
 * Project:
 * --------
 *   WR8_Software
 *
 * Description:
 * ------------
 *   This file is intended for DMA driver.
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _DMA_SW_H
#define _DMA_SW_H

/************************include chip dependent (configure) header file******************/
//PC: DMA driver owner should port chip by chip (user should not refer the chip dependency file)
#if defined(MT6280)
	#include "dma_config_mt6280.h"
#elif defined(MT6752)
	#include "dma_config_mt6589.h"
#elif defined(MT6582)
	#include "dma_config_mt6582.h"
#elif defined(MT6572)
	#include "dma_config_mt6572.h"
#elif defined(MT6571)
	#include "dma_config_mt6571.h"
#elif defined(MT6592)
	#include "dma_config_mt6592.h"	
#else
	#error "Need to port for new chip"
#endif // defined(MT6280)

#include "dma_internal.h"
/*======================================================================================*/

/****************************DMA SW data structure***************************************/
typedef enum {
    DMA_BYTE=0,
    DMA_SHORT,
    DMA_LONG
} DMA_TranSize;

typedef enum {
    DMA_HWTX,            	/*use DMA_HWMENU*/  					/*from RAM to register*/
    DMA_HWRX,            	/*use DMA_HWMENU*/ 						/*from register to RAM*/
    DMA_SWCOPY,          	/*use DMA_SWCOPYMENU*/  				/*from RAM to RAM*/
    DMA_FULLSIZE_TXRINGBUFF,/*use DMA_FULLSIZE_HWRINGBUFF_MENU*/    /*current usage only for Wrap DMA test item in SSDVT*/
    DMA_FULLSIZE_RXRINGBUFF /*use DMA_FULLSIZE_HWRINGBUFF_MENU*/	/*current usage only for Wrap DMA test item in SSDVT*/
} DMA_Type;

typedef struct
{
    kal_bool	burst_mode; 	/*burst mode = 0 ==> single mode*/
    kal_uint8   cycle;      	/*active only when (burst_mode == TRUE)*/
} DMA_TMODE;               

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     addr;
} DMA_HWMENU;

typedef struct
{
#if defined(__DMA_API_V2__)
    DMA_TMODE      TMOD;
#endif
    kal_uint32     srcaddr;
    kal_uint32     dstaddr;
#if defined(__DMA_API_V2__)
    kal_bool       fixed_raddr;
    kal_uint32     rsize;
    kal_bool       fixed_waddr;
    kal_uint32     wsize;
	kal_uint32     req_ack_connect;
	kal_uint32     req_ack_dir;
	kal_uint32     req_ack_ratio;	
#endif
} DMA_SWCOPYMENU;

typedef struct
{
    DMA_TMODE      TMOD;
    DMA_Master     master;
    kal_uint32     source;
    kal_uint32     destination;
    void           *WPPT; /*if ring buffer support, ==NULL==> not supprot*/
    void           *WPTO; /*if ring buffer support, ==NULL==> not supprot*/
#if defined(__DMA_API_V2__)	
    kal_bool       fixed_raddr;
    kal_uint32     rsize;
    kal_bool       fixed_waddr;
    kal_uint32     wsize;
	kal_uint32     req_ack_connect;
	kal_uint32     req_ack_dir;
	kal_uint32     req_ack_ratio;
#endif
} DMA_FULLSIZE_HWRINGBUFF_MENU;

typedef union
{
    DMA_HWMENU                    menu_hw;
	DMA_SWCOPYMENU                menu_swcopy;
    DMA_FULLSIZE_HWRINGBUFF_MENU  menu_fullsize_hw_ringbuff;
} DMA_MENU;

typedef struct
{
    DMA_Type       type;
    DMA_TranSize   size;					/*transfer unit size*/
    kal_uint32     count; 					/*transfer count, the total size should be count*size */
#if defined(__DMA_API_V2__)
    kal_bool       fixed_pattern;
#endif
    void           *menu;      			   	/*DMA_HWMENU,DMA_HWRINGBUFF_MENU,DMA_SWCOPYMENU,DMA_FULLSIZE_HWMENU or DMA_FULLSIZE_HWRINGBUFF_MENU*/
    void           (*callback)(void);      	/*if callback == NULL, interrupt disable*/
} DMA_INPUT;

#if  defined(__DMA_LOW_POWER__)
typedef struct
{
    kal_uint32   sleepDisable; 				/* when sleepDisable ==0 will gating DMA clock for power saving */	
} DMA_PWRCTRL;
#endif

typedef struct
{
    kal_uint32 len1;
	kal_uint32 len2;
	DMA_TranSize size;
} DMA_SAVE_PARAM;
/*======================================================================================*/

/*******************************DMA export macro*****************************************/
#if defined(__DMA_API_V2__)

#if defined(__MULTI_CORE_SHARED_DMA__) && defined(__DMA2_SUPPORT__)
/* AP side */
//Write DMA APB
#define DMA2_Start(_n)                  DRV_WriteReg32(DMA2_START(_n),DMA_START_BIT)
#define DMA2_Stop_Now(_n)               DRV_WriteReg32(DMA2_STOP(_n),DMA_STOP_BIT)
#define DMA2_Reset(_n,_m)             	DRV_WriteReg32(DMA2_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA2_Pause(_n)                	DRV_WriteReg32(DMA2_STOP(_n),DMA_PAUSE_BIT)
#define DMA2_Resume(_n)               	DRV_WriteReg32(DMA2_STOP(_n),0)
#define DMA2_Flush(_n)                	DRV_WriteReg32(DMA2_FLUSH(_n),1)
#define DMA2_ACKI(_n)                 	DRV_WriteReg32(DMA2_ACKINT(_n),DMA_ACKINT_BIT)
//Read DMA APB
#define DMA2_CheckRunStat(_n)           (DRV_Reg32(DMA2_START(_n)) == DMA_START_BIT)                
#define DMA2_CheckITStat(_n)            ((DRV_Reg32(DMA2_GLBST_INT) & DMA_GLBSTA_IT(_n))!=0)	
#define DMA2_WaitUntilRdy(_n)           while(DMA2_CheckRunStat(_n))
#define DMA2_GetCount(_n)             	DRV_Reg32(DMA2_COUNT(_n))

#endif //__MULTI_CORE_SHARED_DMA__ && __DMA2_SUPPORT__

/*MD side */
//Write DMA APB
#if defined(__DMA_LOW_POWER__)
#define DMA_Start(_n) 														\
	do {																	\
		extern DMA_PWRCTRL DMA_PWR;											\
		if(DMA_PWR.sleepDisable==0)											\
			ASSERT(0);														\
		DRV_WriteReg32(DMA_START(_n),DMA_START_BIT);						\
	} while(0)
#else
#define DMA_Start(_n) 					DRV_WriteReg32(DMA_START(_n),DMA_START_BIT)
#endif //__DMA_LOW_POWER__
#define DMA_Stop_Now(_n)                DRV_WriteReg32(DMA_STOP(_n),DMA_STOP_BIT)
#define DMA_Reset(_n,_m)             	DRV_WriteReg32(DMA_RESET(_n),_m?DMA_H_RST_BIT:DMA_W_RST_BIT)
#define DMA_Pause(_n)                	DRV_WriteReg32(DMA_STOP(_n),DMA_PAUSE_BIT)
#define DMA_Resume(_n)               	DRV_WriteReg32(DMA_STOP(_n),0)
#if defined(MT6572) || defined(MT6582) || defined(MT6571) || defined(MT6592) 
//[MOLY00010886]DMA design defect, DMA should be switched to old design by setting bit1 to 1
#define DMA_Flush(_n)                	DRV_WriteReg32(DMA_FLUSH(_n),3)
#else
#define DMA_Flush(_n)                	DRV_WriteReg32(DMA_FLUSH(_n),1)
#endif //MT6572 || MT6582
#define DMA_ACKI(_n)                 	DRV_WriteReg32(DMA_ACKINT(_n),DMA_ACKINT_BIT)
//Read DMA APB
#define DMA_CheckRunStat(_n)           ((DRV_Reg32(DMA_GLBST_RUNNING) & DMA_GLBSTA_RUN(_n))!=0) 
#define DMA_CheckITStat(_n)            ((DRV_Reg32(DMA_GLBST_INT) & DMA_GLBSTA_IT(_n))!=0)
#define DMA_WaitUntilRdy(_n)            while(DMA_CheckRunStat(_n))
#define DMA_GetCount(_n)                DRV_Reg32(DMA_COUNT(_n))

#endif    /* __DMA_API_V2__ */

extern void DMA_Config_Internal(kal_uint8 dma_no, DMA_INPUT *dma_menu, kal_bool fullsize, kal_bool b2w, kal_uint8 limit, kal_bool start);


#define DMA_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, KAL_FALSE, 0, start)
#define DMA_FullSize_Config(dma_no, dma_menu, start) DMA_Config_Internal(dma_no, dma_menu, KAL_TRUE, KAL_FALSE, 0, start)
#define DMA_Config_B2W(dma_no, dma_menu, start, b2w) DMA_Config_Internal(dma_no, dma_menu, KAL_FALSE, b2w, 0, start)

#define APB_DUMMY_READ() do {  } while(0)

#define DMA_GetVFIFO_Avail(ch)      	(DRV_Reg(DMA_FFCNT(ch)))
#define DMA_GetVFIFO_Roomleft(ch)   	(DRV_Reg(DMA_VFF_LEFT_SIZE(ch)) - 16 )             //VFF requires 16 bytes to do flush
#define IS_VFIFO_FULL(ch)           	(DRV_Reg32(DMA_VFF_LEFT_SIZE(ch)) < 16)            //VFF requires 16 bytes to do flush

//RX has two interrupt flag, TX only has one interrupt flag
#define DMA_EnableINT(ch)                                           \
    do {                                                            \
        if( (ch >= DMA_VFIFO_PHY_CH_S) &&                           \
            (( ch & 0x1 ) == ((DMA_CON_MASTER_UART1RX) & 0x1)) )  \
        {                                                           \
            DRV_Reg32(DMA_INT_EN(ch)) = 3;                          \
        }                                                           \
        else                                                        \
        {                                                           \
            DRV_Reg32(DMA_INT_EN(ch)) = 1;                          \
        }                                                           \
    } while(0)

#define DMA_DisableINT(ch)          	DRV_Reg32(DMA_INT_EN(ch)) = 0
#define DMA_TASK_PUSH(ch,data)      	while(IS_VFIFO_FULL(ch)); \
											DMA_PUSH(ch,data)
/*======================================================================================*/

/*******************************DMA export API*******************************************/
extern SSDVT_DMA_INT_CODE_ATTR void DMA_Stop(kal_uint8 channel);
extern void DMA_Run(kal_uint8 channel);
extern void DMA_WaitforDone(kal_uint8 channel);
extern void DMA_CleanUp(kal_uint8 channel);
#if defined(__DMA_LOW_POWER__)
extern void DMA_SleepEnable(kal_uint8 channel);
extern void DMA_SleepDisable(kal_uint8 channel);
#endif
extern SSDVT_DMA_INT_CODE_ATTR kal_uint8 DMA_FullSize_GetChannel(DMA_Master DMA_CODE);
extern SSDVT_DMA_INT_CODE_ATTR void DMA_FullSize_FreeChannel(kal_uint8 handle);
extern kal_uint8 DMA_GetChannel(DMA_Master DMA_CODE);
extern void DMA_FreeChannel(kal_uint8 handle);
extern void DMA_Quick_Config(kal_uint32 dma_no, kal_uint32 dst);
extern void DMA_Quick_Config_Bidir(  kal_uint32 dma_no, kal_uint32 dst, kal_uint32 src, kal_uint32 count, DMA_Type type );
extern void DMA_Ini(void);
extern kal_bool DMA_memcpy(const void *src, const void *dst, kal_uint32 length);
extern void DMA_SRC_Config(kal_uint32 dma_no, kal_uint32 src);
extern void DMA_DST_Config(kal_uint32 dma_no, kal_uint32 dst);
extern void DMA_Transfer_Size_Config( kal_uint8 dma_no, DMA_INPUT *dma_menu );
extern void DMA_Mode_Config(kal_uint8 dma_no, DMA_INPUT *dma_menu);
extern void DMA_Start_Config( kal_uint8 dma_no );
extern void DMA_VFF_Tx_Flush_Config(kal_uint32 dma_no, kal_bool hwflush_en);

// mcu/hal/peripheral/src/hif_legacy.c會使用到該兩APIs，問一下傳勝之後是否仍會有該feature,如果沒有的話就進行phase out ==> MT6572 SCIF will use it confirmed by 傳勝
//-------------------------should be phased out-----------------------------------------------------------------------------------
#if defined(__DMA_SUPPORT_CALLBACK_LISR__)
extern void DMA_Register_RT_CallBack ( kal_uint8 dma_no );
extern void DMA_Unregister_RT_CallBack ( kal_uint8 dma_no );
#endif
//================================================================================================================================

//--------------------------------------------------------------------------------------------------------------------------------
// 於project.mak中宣告DMA_UART_VIRTUAL_FIFO = TRUE，會帶動option.mak中定義下列__DMA_UART_VIRTUAL_FIFO__
#ifdef __DMA_UART_VIRTUAL_FIFO__
#include "uart_sw.h"
extern int DMA_Vfifo_SetChan(UART_PORT port);
extern void DMA_Vfifo_init(void);
extern void DMA_Vfifo_SetAdrs(kal_uint32 adrs, kal_uint32 len, DMA_VFIFO_UART ch, kal_bool IsTx );
extern void DMA_Vfifo_Flush(DMA_VFIFO_UART ch);
#endif   /* __DMA_UART_VIRTUAL_FIFO__ */
/*======================================================================================*/	

// mcu/middleware/mtkdebug/Sim60qbit.c會使用到該兩個APIs
//-------------------------should be phased out-----------------------------------------------------------------------------------
#if defined(__RTL_SIMULATION_FOR_60QBIT__)
extern void  test_dma_slowdown( void );
extern void test_dma_recover( void );
#endif //__RTL_SIMULATION_FOR_60QBIT__
//================================================================================================================================									  
#endif /* !_DMA_SW_H */
