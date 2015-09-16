/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
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
 *    dcl_gpt.c
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   This Module defines DCL (Driver Common Layer) of the GPT driver.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 *
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features_gpt.h"
#include "drv_comm.h"
#include "drv_gpt.h"
#include "intrCtrl.h"
#include "us_timer.h"


#include "dcl_gpt.h"
#include "dcl_gpt_hw.h"
#include "dcl.h"
#include "drv_hisr.h"
#include "devdrv_ls.h"
#include "kal_general_types.h"
#include "kal_public_api.h"
#include "drvpdn.h"


//#define DCL_GPT_INTERFACE
//#ifdef  DCL_GPT_INTERFACE

#if !defined(DRV_GPT_OFF)

/*****************************************************************************
 *                        Symbol/Type Definition                             *
 *****************************************************************************/
//DCL_GPT_CB  this software gpt provide register callback function.
#define DCL_GPT_CB_MAGIC_NUM                (0x02000000)
#define DCL_GPT_BW_MAGIC_NUM                (0x04000000)
#define DCL_FGPT_MAGIC_NUM                  (0x08000000)
#define DCL_GPT_CBUS_MAGIC_NUM              (0x10000000)
#define DCL_GPT_DEBUG_MAGIC_NUM             (0x20000000)

#define DCL_GPT_CB_TICK2US                  (10000U)
#define DCL_GPT_CBUS_TICK2US                (1U)

#if defined(MT6290)
  #define MDGPTM_PDN_SET() PDN_SET(PDN_MDGPTM);
  #define MDGPTM_PDN_CLR() PDN_CLR(PDN_MDGPTM);
#else  /* MT6290 */
  #define MDGPTM_PDN_SET() PDN_SET(PDN_GPT);
  #define MDGPTM_PDN_CLR() PDN_CLR(PDN_GPT);
#endif /* MT6290 */

/*****************************************************************************
 *                         Macro Function Definition                           *
 *****************************************************************************/

#define DCL_GPT_CB_IS_HANDLE_MAGIC(handl_)    ((handl_)& DCL_GPT_CB_MAGIC_NUM)
#define DCL_GPT_CB_GET_DEV(handle_)           ((handle_) & (~DCL_GPT_CB_MAGIC_NUM))
#define DCL_GPT_CBUS_IS_HANDLE_MAGIC(handl_)  ((handl_)& DCL_GPT_CBUS_MAGIC_NUM)
#define DCL_GPT_DEBUG_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_GPT_DEBUG_MAGIC_NUM)
#define DCL_GPT_DEBUG_GET_DEV(handle_)        ((handle_) & (~DCL_GPT_DEBUG_MAGIC_NUM))
#define DCL_GPT_BUS_CLOCK_ON()                      \
    do{                                             \
        if(KAL_FALSE == gpt_bus_clock_en)           \
        {                                           \
            MDGPTM_PDN_CLR();                       \
            gpt_bus_clock_en = KAL_TRUE;            \
        }                                           \
    }while(0);
#if defined(__EVENT_BASED_TIMER__) /* OST as os tick */
    #define DCL_GPT_BUS_CLOCK_OFF()                 \
    do{                                             \
        if(KAL_TRUE == gpt_bus_clock_en)            \
        {                                           \
            MDGPTM_PDN_SET();                       \
            gpt_bus_clock_en = KAL_FALSE;           \
        }                                           \
    }while(0);
#else /* __EVENT_BASED_TIMER__, GPT as OS tick */
    #define DCL_GPT_BUS_CLOCK_OFF()
#endif /* */

#define DCL_GPT_IS_USED() ((KAL_TRUE == gptCBUS_running) || (0!=gptCB_status) || (NULL!=gpt_DEBUG_head.next))

#define DCL_GPT_BUS_CLOCK_TRY_OFF()                     \
    if(!DCL_GPT_IS_USED()) { DCL_GPT_BUS_CLOCK_OFF(); }

/*****************************************************************************
 *                         Structure/Type Definition                         *
 *****************************************************************************/
typedef struct gptimer_instance{
	kal_uint32 ticks;
	void (*gptimer_func)(void *parameter);
	void *param;
	struct gptimer_instance *next;
}gpt_inst;

/*****************************************************************************
 *                         Global/External Variable                          *
 *****************************************************************************/
kal_bool gpt_bus_clock_en = KAL_FALSE;

/* For mini-second Callback Function */
static kal_uint32   gptCB_status;               /* 1,activated ,0:de-activated */
static kal_uint32   gptCB_ticks;                /* CB gpt current ticks number */
static kal_uint32   gptCB_users;                /* Indicate the current registered GPT users */
static kal_uint8    gptCB_used[MAX_GPT_ITEMS];  /* 0: Not registered by user, 1: Registerd by used */
static gptimer_item gptCB_items[MAX_GPT_ITEMS]; /* gpt callback function instance */


/* For micro-second Callback Function */
static kal_bool     gptCBUS_used    = KAL_FALSE;
static kal_bool     gptCBUS_running = KAL_FALSE;
static gptimer_item gptCBUS_instance;

/* For micro-second Debug Callback Function */
static kal_uint32   gpt_DEBUG_users;                /* Indicate the current registered GPT users */
static gpt_inst     gpt_DEBUG_head;                 /* BSS section, default field value == 0 */
static kal_uint8    gpt_DEBUG_used[MAX_GPT_ITEMS];  /* 0: Not registered by user, 1: Registerd by used */
static gpt_inst     gpt_DEBUG_items[MAX_GPT_ITEMS]; /* gpt callback function instance */
#if defined (__MTK_TARGET__) && !defined(__GPTDEBUG_HISR_DISABLE__) && defined(__LTE_RAT__)
static kal_hisrid   gpt_debug_hisr;
#endif

/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/
void GPTCB_10MS_HISR(void);
void GPTCB_US_HISR(void);
void GPTCB_DEBUG_HISR(void);
static kal_bool GPTCB_StartItem(DCL_HANDLE module,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter);
static void GPTCB_StopItem(DCL_HANDLE module);
static void GPT_DEBUG_Insert(kal_uint32 indx, kal_uint32 tick,void (*gptimer_func)(void *),void *parameter);
static void GPT_DEBUG_Stop(kal_uint32 indx);


/*****************************************************************************
 *                        debug informaiton                                  *
 *****************************************************************************/
//#define __DRV_GPT_TRACE__ 1
#if defined(__DRV_GPT_TRACE__)

#define IFDEF_GPT_TRACE(x) x

#define MAX_GPT_HISR_DBG_INFO_SIZE 128
typedef struct
{
    kal_uint16      tag;
    kal_uint32      enter_time;
    kal_uint32      leave_time;
} GPT_HISR_DBG_DATA;
typedef struct{
   GPT_HISR_DBG_DATA       dbg_data[MAX_GPT_HISR_DBG_INFO_SIZE];
   kal_uint16             dbg_data_idx;
}
GPT_HISR_DBG_STRUCT;

GPT_HISR_DBG_STRUCT    GPT_HISR_DBG_INFO_DATA;
#define GPT_DBG(a, b, c) GPT_hisr_dbg_trace(a,b, c);
void GPT_hisr_dbg_trace(kal_uint32 index, kal_uint32 time1, kal_uint32 time2)
{
    kal_uint32 savedMask;
    savedMask = SaveAndSetIRQMask();
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].tag = (kal_uint16)index;
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].enter_time = time1;
    GPT_HISR_DBG_INFO_DATA.dbg_data[GPT_HISR_DBG_INFO_DATA.dbg_data_idx].leave_time = time2;
    GPT_HISR_DBG_INFO_DATA.dbg_data_idx = (GPT_HISR_DBG_INFO_DATA.dbg_data_idx+1)%MAX_GPT_HISR_DBG_INFO_SIZE;
    RestoreIRQMask(savedMask);
    /*
    kal_prompt_trace(MOD_DRVKBD, "index=%d, time=%d, time2=%d", index, time, time2);
    */
}
#else  /* __DRV_GPT_TRACE__ */
#define GPT_DBG(a, b, c) ;
#define IFDEF_GPT_TRACE(x)
#endif  /* __DRV_GPT_TRACE__ */

//#define GPT_CB_MEASURE_TIME 1
#if defined(GPT_CB_MEASURE_TIME)
/* to measure time */
#if defined(__CR4__)
#include "cp15_int.h"
#elif defined(__MTK_MMU_V2__) /* __CR4__*/
#include "mpu_mtk_mmu_v2_int.h"
#endif /* __MTK_MMU_V2__ */
#define IFDEF_GPT_CB_MEASURE_TIME(x) x
kal_uint32 gpt_cb_enter_time[MAX_GPT_ITEMS];
kal_uint32 gpt_cb_leave_time[MAX_GPT_ITEMS];
kal_uint32 gpt_uscb_enter_time;
kal_uint32 gpt_uscb_leave_time;

#else  /* GPT_CB_MEASURE_TIME */

#define IFDEF_GPT_CB_MEASURE_TIME(x)
#endif /* GPT_CB_MEASURE_TIME */

/*[end]***********************************debug informaiton end *****************************/

void GPT_ERROR_CB(void *p)
{
    kal_uint32 CANNOT_FIND_GPT_CB_HANDLER = 0;
    ASSERT(CANNOT_FIND_GPT_CB_HANDLER);
}

/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 10ms LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
void GPTCB_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    drv_active_hisr(DRV_GPT1_HISR_ID);
}

/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 1us LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_US_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
    drv_active_hisr(DRV_GPT2_HISR_ID);
}

/*-----------------------------------------------------------------------*
*                                                                            
*                        GPT 1us LISR function,                                  
*                pass to gpt_hw layer as a function pointer     
*                                                                        
*------------------------------------------------------------------------*/
void GPT_DEBUG_Lisr(kal_uint32 vector)
{
    /*ASSERT( (MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER) == vector) || \
            (MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER) == vector)          );*/
#if defined(MT6290) && defined(__ARM7EJ_S__)
    IRQClearInt(vector);
#endif /* end of "defined(MT6290) && defined(__ARM7EJ_S__)" */
#if defined (__MTK_TARGET__) && !defined(__GPTDEBUG_HISR_DISABLE__) && defined(__LTE_RAT__)
	kal_activate_hisr(gpt_debug_hisr);
#endif
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Initialize
*
* DESCRIPTION
*  This function is to initialize SW GPT module. 
*
* PARAMETERS
*    DCL_STATUS_OK
*
* RETURNS
*  none
*
*------------------------------------------------------------------------*/
DCL_STATUS DclSGPT_Initialize(void)
{
    kal_uint8 index;

    DCL_GPT_BUS_CLOCK_ON();
    /* GPT hardware reset */
    drv_gpt_reset();
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER), GPTCB_Lisr, "GPTCBMS");
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER), GPTCB_US_Lisr, "GPTCBUS");
    IRQ_Register_LISR(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER), GPT_DEBUG_Lisr, "GPTDEBUG");

#if defined (__MTK_TARGET__) && !defined(__GPTDEBUG_HISR_DISABLE__) && defined(__LTE_RAT__)
    gpt_debug_hisr = kal_init_hisr(GPT_DEBUG_HISR);
#endif

    /* set gpt CB timer */
    drv_gpt_set_timer(DRV_GPT_CALLBACK_TIMER, DCL_GPT_CB_TICK2US, MDGPT_CTRL_MODE_REPEAT);

    /* set gpt CBUS timer */
    drv_gpt_set_timer(DRV_GPT_CBUS_TIMER, DCL_GPT_CBUS_TICK2US, MDGPT_CTRL_MODE_REPEAT);

    /* set gpt Debug timer, tick unit = us */
    drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, DCL_GPT_CBUS_TICK2US, MDGPT_CTRL_MODE_ONESHOT);

    /* set OS timer */
    drv_gpt_set_timer(DRV_GPT_SYSTEM_TIMER, KAL_MICROSECS_PER_TICK, MDGPT_CTRL_MODE_REPEAT);

    /* gptCB variables are initialized in BSS reset procedure */

    /* Register the GPT CB HISR */
    DRV_Register_HISR(DRV_GPT1_HISR_ID, GPTCB_10MS_HISR);
    DRV_Register_HISR(DRV_GPT2_HISR_ID, GPTCB_US_HISR);

    for (index = 0; index < MAX_GPT_ITEMS; index++)
    {
        gptCB_items[index].gptimer_func = GPT_ERROR_CB;
        gpt_DEBUG_items[index].gptimer_func = GPT_ERROR_CB;
    }

    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_CALLBACK_TIMER));
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_CBUS_TIMER));
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER));
    IRQUnmask(MDGPT_INTR_ID(DRV_GPT_SYSTEM_TIMER));
    DCL_GPT_BUS_CLOCK_OFF();
    
    return STATUS_OK;
}

/*-----------------------------------------------------------------------
* FUNCTION
*  DclSGPT_Open
*
* DESCRIPTION
*  This function is to open the SW GPT module and get a handle. Note that 
* multiple opens are allowed.
*
* PARAMETERS
*    eDev - only valid for DCL_GPT1
*    flags - no sepcial flags is needed. Please use FLAGS_NONE
*
* RETURNS
*    DCL_HANDLE_INVALID - Open failed.
*  other value - a valid handle
*
*------------------------------------------------------------------------*/
DCL_HANDLE DclSGPT_Open(DCL_DEV eDev, DCL_FLAGS flags)
{
    kal_uint32 savedMask;
    kal_int32 i;
    if (DCL_GPT_CB==eDev)
    {
        savedMask = SaveAndSetIRQMask();
        for (i=0; i < MAX_GPT_ITEMS; i++)
        {
            if (gptCB_used[i] == 0)
            {
                gptCB_used[i] = 1;
                gptCB_users++;
                RestoreIRQMask(savedMask);
                return DCL_GPT_CB_MAGIC_NUM|i;
            }
        }
        RestoreIRQMask(savedMask);
        // The case that we do NOT return in the loop:
        // Indicate there is NO GPT handle!!!!!
        ASSERT(i < MAX_GPT_ITEMS);
        // return invalid handle
        return DCL_HANDLE_OCCUPIED;
    }
    else if (DCL_GPT_CB_MS==eDev)
    {
        savedMask = SaveAndSetIRQMask();
        if( KAL_FALSE == gptCBUS_used )
        {
            gptCBUS_used = KAL_TRUE;
            RestoreIRQMask(savedMask);
            return DCL_GPT_CBUS_MAGIC_NUM;
        }
        RestoreIRQMask(savedMask);
        
        return DCL_HANDLE_OCCUPIED;
    }
    else if (DCL_GPT_DEBUG==eDev)
    {
        savedMask = SaveAndSetIRQMask();
        for (i=0; i < MAX_GPT_ITEMS; i++)
        {
            if (gpt_DEBUG_used[i] == 0)
            {
                gpt_DEBUG_used[i] = 1;
                gpt_DEBUG_users++;
                RestoreIRQMask(savedMask);
                return DCL_GPT_DEBUG_MAGIC_NUM|i;
            }
        }
        RestoreIRQMask(savedMask);
		ASSERT( gpt_DEBUG_users < MAX_GPT_ITEMS );
        // return invalid handle
        return DCL_HANDLE_OCCUPIED;
    }
    else
    {
        kal_uint32 Invaild_GPT_DEV_Type = 0;

        ASSERT(Invaild_GPT_DEV_Type);
        return DCL_HANDLE_INVALID;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_ReadData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_WriteData
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
   return STATUS_UNSUPPORTED;
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Configure
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_RegisterCallback
*
* DESCRIPTION
*  This function is not supported for the SW GPT module now.
*
* PARAMETERS
*    N/A
*
* RETURNS
*    STATUS_UNSUPPORTED
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
   return STATUS_UNSUPPORTED;
}


/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Control
*
* DESCRIPTION
*  This function is to send command to control the SW GPT module.
*
* PARAMETERS
*    handle - a valid handle return by DclSGPT_Open()
*  cmd   - a control command for GPT module
*          1. SGPT_CMD_START: to start a GPT timer
*          2. SGPT_CMD_STOP: to stop a GPT timer
*  data - for 1. SGPT_CMD_START: pointer to a SGPT_CTRL_START_T structure
*             2. SGPT_CMD_STOP: a NULL pointer
*
* RETURNS
*    STATUS_OK - command is executed successfully.
*    STATUS_FAIL - command is failed.
*  STATUS_INVALID_CMD - It's a invalid command.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    DCL_UINT32 gpt_unknown_command = 0;
    DCL_UINT8  gpt_handle = 0;
    kal_uint32 savedMask;
    gpt_handle = DCL_GPT_CB_GET_DEV(handle) & 0x1F;
    
    if(DCL_GPT_CB_IS_HANDLE_MAGIC(handle))
    {
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                kal_bool ret_b;
                SGPT_CTRL_START_T  *prStart;

                prStart = &(data->rSGPTStart);
                
                //test if callback function is null.
                ASSERT( NULL!=prStart->pfCallback );

                savedMask = SaveAndSetIRQMask();
                DCL_GPT_BUS_CLOCK_ON();
                RestoreIRQMask(savedMask);
                ret_b = GPTCB_StartItem(gpt_handle, prStart->u2Tick, prStart->pfCallback, prStart->vPara);
                if (ret_b == KAL_TRUE)
                {
                    return STATUS_OK;
                }
                else
                {
                    return STATUS_FAIL;
                }
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:
                GPTCB_StopItem(gpt_handle);
                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
    }
    else if(DCL_GPT_CBUS_IS_HANDLE_MAGIC(handle))
    {
        ASSERT( KAL_TRUE == gptCBUS_used );
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

                //test if callback function is null.
                ASSERT( NULL!=prStart->pfCallback );

                savedMask = SaveAndSetIRQMask();
                if( KAL_TRUE == gptCBUS_running )
                {
                    RestoreIRQMask(savedMask);
                    return STATUS_FAIL;
                }
                gptCBUS_instance.tick = prStart->u2Tick*1000; // 1 ms duration
                gptCBUS_instance.gptimer_func = prStart->pfCallback;
                gptCBUS_instance.parameter = prStart->vPara;
                gptCBUS_running = KAL_TRUE;

                DCL_GPT_BUS_CLOCK_ON();
                drv_gpt_set_timer(DRV_GPT_CBUS_TIMER, gptCBUS_instance.tick, MDGPT_CTRL_MODE_ONESHOT);
                drv_gpt_start_timer(DRV_GPT_CBUS_TIMER);
                RestoreIRQMask(savedMask);

                return STATUS_OK;
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:

                savedMask = SaveAndSetIRQMask();
                drv_gpt_stop_timer(DRV_GPT_CBUS_TIMER);
                gptCBUS_running = KAL_FALSE;
                DCL_GPT_BUS_CLOCK_TRY_OFF();
                RestoreIRQMask(savedMask);

                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
    }
    else if(DCL_GPT_DEBUG_IS_HANDLE_MAGIC(handle))
    {
        switch(cmd)
        {
            case SGPT_CMD_START:
            {
                SGPT_CTRL_START_T  *prStart;
                prStart = &(data->rSGPTStart);

				GPT_DEBUG_Insert(DCL_GPT_DEBUG_GET_DEV(handle), prStart->u4Tick, prStart->pfCallback, prStart->vPara);

                return STATUS_OK;
            }
            //break; we can return in any case.
            case SGPT_CMD_STOP:
				GPT_DEBUG_Stop(DCL_GPT_DEBUG_GET_DEV(handle));
                return STATUS_OK;
            default:
                ASSERT(gpt_unknown_command);
                return STATUS_INVALID_CMD;
        }
	}
    else
    {
        kal_uint32 Error_DCL_HANDLE = 0;
        //if assert happen here, that means DCL_HANDLE pass in is wrong!
        ASSERT(Error_DCL_HANDLE);
        return DCL_HANDLE_INVALID;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION
*  DclSGPT_Close
*
* DESCRIPTION
*  This function is to close the SW GPT module.
*
* PARAMETERS
*    handle  - hanlde previous got from DclSGPT_Open()
*
* RETURNS
*    DCL_STATUS_OK - successfully close the SW GPT module.
*    DCL_STATUS_fail - fails to close the SW GPT module.
*
*------------------------------------------------------------------------*/

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
    DCL_UINT8 gpt_handle;
    kal_uint32 savedMask;
    gpt_handle=DCL_GPT_CB_GET_DEV(*handle) & 0x1F;
    
    if(DCL_GPT_CB_IS_HANDLE_MAGIC(*handle))
    {
        // Make sure the GPT handle is activated
        ASSERT(gptCB_used[gpt_handle]);    

        savedMask = SaveAndSetIRQMask();
        
        if( gptCB_status & (1<<gpt_handle) )
        {
            GPTCB_StopItem(gpt_handle);
        }
        
        gptCB_used[gpt_handle] = 0;
        gptCB_users--;
        
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        
        *handle = EMPTY_GPT_CB_HANDLER;
        return STATUS_OK;
    }
    else if(DCL_GPT_CBUS_IS_HANDLE_MAGIC(*handle))
    {
        savedMask = SaveAndSetIRQMask();
        if( KAL_TRUE == gptCBUS_running )
        {
            drv_gpt_stop_timer(DRV_GPT_CBUS_TIMER);
            gptCBUS_running = KAL_FALSE;
        }
        gptCBUS_used = KAL_FALSE;
        *handle = EMPTY_GPT_CB_HANDLER;
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        return STATUS_OK;
    }
    else if(DCL_GPT_DEBUG_IS_HANDLE_MAGIC(*handle))
    {
		gpt_inst *iter;
        savedMask = SaveAndSetIRQMask();
		iter = gpt_DEBUG_head.next;
		while(NULL!=iter)
		{
			if(iter == &gpt_DEBUG_items[gpt_handle])
			{
				GPT_DEBUG_Stop(gpt_handle);
				break;
			}
		}
        gpt_DEBUG_used[gpt_handle] = 0;
        gpt_DEBUG_users--;
        *handle = EMPTY_GPT_CB_HANDLER;
        DCL_GPT_BUS_CLOCK_TRY_OFF();
        RestoreIRQMask(savedMask);
        return STATUS_OK;
    }
    else
    {
        kal_uint32 Invalid_DCL_GPT_HANDLE = 0;
        ASSERT(Invalid_DCL_GPT_HANDLE);
        return STATUS_INVALID_DCL_HANDLE;
    }
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*    GPTCB_StartItem
*
* DESCRIPTION                                                           
*       GPT CB start a item.
*
* CALLS  
*
* PARAMETERS
*        handler = instance number
*           tick = the delay(the unit is 10ms)
*  gptimer_func = the callback function when the tick is reached.
*     parameter = the parameter inputed into gptimer_func
*
* RETURNS
*    KAL_TRUE, start item successfully
*  KAL_FALSE, start item fail
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
static kal_bool GPTCB_StartItem(DCL_HANDLE handler,kal_uint16 tick,void (*gptimer_func)(void *),void *parameter)
{
    kal_uint32 savedMask;  

    if (gptCB_status & (1<<handler))
    {
        return KAL_FALSE;
    }
   
    savedMask = SaveAndSetIRQMask();

    gptCB_items[handler].tick = gptCB_ticks + tick;
    gptCB_items[handler].gptimer_func = gptimer_func;
    gptCB_items[handler].parameter = parameter;
   
    if(0 == gptCB_status)
    {
        drv_gpt_start_timer(DRV_GPT_CALLBACK_TIMER);
    }
    gptCB_status |= (1<<handler);
    
    RestoreIRQMask(savedMask);

    return KAL_TRUE;
}

/*-----------------------------------------------------------------------

* FUNCTION                                                            
*    GPTCB_StopItem
*
* DESCRIPTION                                                           
*       GPT CB stop a item.
*
* CALLS  
*
* PARAMETERS
*    handler = instance number
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
static void GPTCB_StopItem(DCL_HANDLE handler)
{
    kal_uint32 savedMask;

    ASSERT(gptCB_used[handler]);
    
    savedMask = SaveAndSetIRQMask();
   
    gptCB_status &= ~(1<<handler);
    
    if(0==gptCB_status)
    {
        gptCB_ticks = 0;
        drv_gpt_stop_timer(DRV_GPT_CALLBACK_TIMER);
        DCL_GPT_BUS_CLOCK_TRY_OFF();
    }
    RestoreIRQMask(savedMask);
}

static void GPT_DEBUG_Insert(kal_uint32 indx, kal_uint32 tick, void (*fp)(void *) ,void *parameter)
{
	kal_uint32 savedMask;
	kal_uint32 elapsed, time; /* elapsed: current - start time; time: eariest time-out setting */
	gpt_inst *iter = gpt_DEBUG_head.next;

    ASSERT( NULL!=fp );
    gpt_DEBUG_items[indx].gptimer_func = fp;
    gpt_DEBUG_items[indx].param = parameter;

    savedMask = SaveAndSetIRQMask();

	elapsed = drv_gpt_get_data(DRV_GPT_DEBUG_TIMER);
    drv_gpt_stop_timer(DRV_GPT_DEBUG_TIMER);

	if( (NULL == gpt_DEBUG_head.next))
	{
		gpt_DEBUG_head.next = &gpt_DEBUG_items[indx];
		time = tick;
        DCL_GPT_BUS_CLOCK_ON();
	}
	else if((iter->ticks-elapsed) > tick)
	{
		gpt_DEBUG_items[indx].next = iter;
		gpt_DEBUG_head.next = &gpt_DEBUG_items[indx];
		iter->ticks -= elapsed + tick;
		time = tick;
	}
	else
	{
		time = iter->ticks - elapsed;
		tick -= time;
		iter->ticks = time;
		while( NULL != iter->next )
		{
			if(iter->next->ticks > tick)
			{
				gpt_DEBUG_items[indx].next = iter->next;
				gpt_DEBUG_items[indx].next->ticks -= tick;
				iter->next = &gpt_DEBUG_items[indx];
				break;
			}
			iter = iter->next;
			tick -= iter->ticks;
		}
		if(NULL == iter->next)
		{
			gpt_DEBUG_items[indx].next = NULL;
			iter->next = &gpt_DEBUG_items[indx];
		}
	}
	gpt_DEBUG_items[indx].ticks = tick;

    //test if callback function is null.
    drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, time, MDGPT_CTRL_MODE_ONESHOT);
    drv_gpt_start_timer(DRV_GPT_DEBUG_TIMER);

    RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPT_DEBUG_Stop
*
* DESCRIPTION                                                           
*    Remove Debug Timer Instance from queue
*
* CALLS  
*
* PARAMETERS
*    indx = instance number
*
* RETURNS
*    None
*
*------------------------------------------------------------------------*/
static void GPT_DEBUG_Stop(kal_uint32 indx)
{
	kal_uint32 savedMask;
	gpt_inst *iter = &gpt_DEBUG_head;

    savedMask = SaveAndSetIRQMask();

	while( (iter->next!=&gpt_DEBUG_items[indx]) && (NULL!=iter->next) )
	{
		iter = iter->next;
	}
	ASSERT(NULL!=iter->next);

	if(iter == &gpt_DEBUG_head)
	{
	    kal_uint32 elapsed;
	    elapsed = drv_gpt_get_data(DRV_GPT_DEBUG_TIMER);
        drv_gpt_stop_timer(DRV_GPT_DEBUG_TIMER);
		IRQClearInt(MDGPT_INTR_ID(DRV_GPT_DEBUG_TIMER));

	    gpt_DEBUG_head.next = gpt_DEBUG_items[indx].next;
		if(NULL != gpt_DEBUG_head.next)
		{
			gpt_DEBUG_head.next->ticks = gpt_DEBUG_head.next->ticks - elapsed + gpt_DEBUG_items[indx].ticks ;
            drv_gpt_set_timer(DRV_GPT_DEBUG_TIMER, gpt_DEBUG_head.next->ticks, MDGPT_CTRL_MODE_ONESHOT);
            drv_gpt_start_timer(DRV_GPT_DEBUG_TIMER);
		}
		else
		{
            DCL_GPT_BUS_CLOCK_TRY_OFF();
		}
	}
	else
	{
		if(NULL != gpt_DEBUG_items[indx].next)
		{
			gpt_DEBUG_items[indx].next->ticks += gpt_DEBUG_items[indx].ticks;
		}
		iter->next = iter->next->next;
	}
	gpt_DEBUG_items[indx].next = NULL;
    RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_10MS_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 10ms
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_10MS_HISR(void)
{
    kal_uint8 index; 
    kal_uint32 savedMask;
    kal_uint32 checkMask = 0xFFFFFFFF;
    IFDEF_GPT_TRACE(kal_uint32 time1);
    IFDEF_GPT_TRACE(kal_uint32 time2);

    gptCB_ticks++;
    
    // Bit matched method to check if a GPT items is activated
    // Search whole GPT items
    for (index = 0; (index < MAX_GPT_ITEMS)&&(gptCB_status&checkMask); index++)
    {
        savedMask = SaveAndSetIRQMask();
        if( (gptCB_status & (1 << index)) && (gptCB_ticks >= gptCB_items[index].tick) )
        {
            gptCB_status &= ~(1<<index);
            RestoreIRQMask(savedMask);
            IFDEF_GPT_TRACE(time1 = ust_get_current_time());
#if defined(__CR4__)
            IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_cb_enter_time[index]));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
            IFDEF_GPT_CB_MEASURE_TIME(gpt_cb_enter_time[index]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
            gptCB_items[index].gptimer_func(gptCB_items[index].parameter);
#if defined(__CR4__)
            IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_cb_leave_time[index]));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
            IFDEF_GPT_CB_MEASURE_TIME(gpt_cb_leave_time[index]=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
            IFDEF_GPT_TRACE(time2 = ust_get_current_time());
            GPT_DBG(index, time1, time2);
        }
        else
        {
            RestoreIRQMask(savedMask);
        }
        checkMask ^= (1 << index);
    }

    savedMask = SaveAndSetIRQMask();

    if (gptCB_status == 0)
    {
        // UT Test road test.
        gptCB_ticks = 0;
        drv_gpt_stop_timer(DRV_GPT_CALLBACK_TIMER);
        DCL_GPT_BUS_CLOCK_TRY_OFF();
    }
    RestoreIRQMask(savedMask);
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_Debug_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 1us
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
void GPTCB_DEBUG_HISR(void)
{
//	if(NULL != gpt_DEBUG_head.next->gptimer_func)
	{
	    gpt_DEBUG_head.next->gptimer_func(gpt_DEBUG_head.next->param);
	}
#if !defined(ATEST_DRV_ENABLE) && !defined(DSPFNC_DSP_SWTRACER)
    ASSERT(0);
#endif /* !ATEST_DRV_ENABLE */
}

/*-----------------------------------------------------------------------
* FUNCTION                                                            
*    GPTCB_US_HISR
*
* DESCRIPTION                                                           
*       GPT Callback HISR : 10ms
*
* CALLS
*
* PARAMETERS
*    void
*
* RETURNS
*    None
*
* GLOBALS AFFECTED
*   external_global
*------------------------------------------------------------------------*/
DEVDRV_LS_INTSRAM_ROCODE void GPTCB_US_HISR(void)
{
    kal_uint32 savedMask;

    savedMask = SaveAndSetIRQMask();
    if( KAL_TRUE == gptCBUS_running )
    {
        gptCBUS_running = KAL_FALSE;
        RestoreIRQMask(savedMask);
#if defined(__CR4__)
        IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_uscb_enter_time));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
        IFDEF_GPT_CB_MEASURE_TIME(gpt_uscb_enter_time=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
        gptCBUS_instance.gptimer_func(gptCBUS_instance.parameter);
#if defined(__CR4__)
        IFDEF_GPT_CB_MEASURE_TIME(CP15_PMU_GET_CYCLE_CNT(gpt_uscb_leave_time));
#elif defined(__MTK_MMU_V2__) /* __CR4__ */
        IFDEF_GPT_CB_MEASURE_TIME(gpt_uscb_leave_time=CACHE_FREE_RUN_CYCLE_COUNTER_GET_CYCLE());
#endif /* __MTK_MMU_V2__ */
    }
    else
    {
        RestoreIRQMask(savedMask);
    }
    savedMask = SaveAndSetIRQMask();
    DCL_GPT_BUS_CLOCK_TRY_OFF();
    RestoreIRQMask(savedMask);
}

#else /* else of !defined(DRV_GPT_OFF) */

DCL_STATUS DclSGPT_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclSGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclSGPT_Close(DCL_HANDLE *handle)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Initialize(void)
{
    return STATUS_UNSUPPORTED;
}

DCL_HANDLE DclFGPT_Open(DCL_DEV dev, DCL_FLAGS flags)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_ReadData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_WriteData(DCL_HANDLE handle, DCL_BUFF *buff, DCL_BUFF_LEN *buf_len, DCL_OPTIONS options)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Configure(DCL_HANDLE handle, DCL_CONFIGURE_T *configure)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
    return STATUS_UNSUPPORTED;
}

DCL_STATUS DclFGPT_Close(DCL_HANDLE handle)
{
    return STATUS_UNSUPPORTED;
}
#endif /* end of else of !defined(DRV_GPT_OFF) */

DCL_HANDLE DclHGPT_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_Control(DCL_HANDLE handle, HGPT_CMD cmd, HGPT_CTRL *data){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, PFN_DCL_CALLBACK callback){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHGPT_Close(DCL_HANDLE handle){return STATUS_UNSUPPORTED;}

//#endif 

