//#pragma O0

#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "hif_hal.h"
#include "hif_v2_internal.h"
#include "eint.h"
#include "intrCtrl.h"
#include "dma_sw.h"
#include "dma_hw.h"
#include "drv_comm.h"
#include "drv_hisr.h"
#include "init.h"
#if defined(__AST_TL1_TDD__)
#include "ast_hif_hw.h"
#endif
#if defined(DRV_HIF_SUPPORT) && defined(DRV_HIF_V2)

#if defined (MT6255) || defined(MT6256)//chip version query type modify for MT6255,MT6256 only
static SW_SECVERSION chip_version;
#endif
static kal_bool hif_eco_support = KAL_FALSE;

// Global variables
static kal_bool hif_power_on[HIF_ENGINE_COUNT] = {KAL_FALSE, KAL_FALSE};
static HIF_INTERNAL_HANDLE_T hif_internal_handle[HIF_ENGINE_COUNT];
static volatile kal_uint8 hif_sysdma_id[HIF_ENGINE_COUNT];
static DMA_INPUT hif_dma_input[HIF_ENGINE_COUNT];
static DMA_HWMENU hif_dma_menu[2];

static kal_bool hif_config_done[2] = {KAL_FALSE};

//static kal_hisrid hif_hisr_id[HIF_ENGINE_COUNT];
static HIF_CALLBACK hif_cb[HIF_ENGINE_COUNT] = {0};

#ifdef MTK_SLEEP_ENABLE
static kal_uint8 hif_sleepMode_handle[HIF_ENGINE_COUNT] = {0xFF, 0xFF};
extern void L1SM_SleepDisable( kal_uint8 handle );
extern void L1SM_SleepEnable( kal_uint8 handle );
extern kal_uint8 L1SM_GetHandle(void);
#endif
kal_eventgrpid  hif_events;
extern void SLA_CustomLogging(kal_char *customJob, kal_int32 saAction);

void hif_init(void)
{
    // Init structure.
    memset(hif_internal_handle, 0, sizeof(hif_internal_handle));
#if defined (HIF0_CHANNEL_SUPPORT)
    // Init HIF interrupr
    IRQ_Register_LISR(IRQ_HIF_CODE, hif0_lisr, "HIF0 ISR");
    IRQSensitivity(IRQ_HIF_CODE, LEVEL_SENSITIVE);
    //hif_hisr_id[0] = kal_create_hisr("HIF0_HISR", 0, 1024, hif0_hisr, KAL_TRUE);
    DRV_Register_HISR(DRV_HIF0_HISR_ID, hif0_hisr);
    IRQUnmask(IRQ_HIF_CODE);
#endif
#if defined (HIF1_CHANNEL_SUPPORT)
    IRQ_Register_LISR(IRQ_HIF_1_CODE, hif1_lisr, "HIF1 ISR");
    IRQSensitivity(IRQ_HIF_1_CODE, LEVEL_SENSITIVE);
    //hif_hisr_id[1] = kal_create_hisr("HIF1_HISR", 0, 1024, hif1_hisr, KAL_TRUE);
    DRV_Register_HISR(DRV_HIF1_HISR_ID, hif1_hisr);
    IRQUnmask(IRQ_HIF_1_CODE);
#endif

    /* DMA initialization */
#if defined (HIF0_CHANNEL_SUPPORT)
    hif_sysdma_id[0] = DMA_GetChannel(DMA_HIF0);
    hif_dma_menu[0].TMOD.burst_mode = KAL_FALSE;
    hif_dma_menu[0].master = DMA_HIF0;
    hif_dma_menu[0].addr = 0;
#endif
#if defined (HIF1_CHANNEL_SUPPORT)
    hif_sysdma_id[1] = DMA_GetChannel(DMA_HIF1);
    hif_dma_menu[1].TMOD.burst_mode = KAL_FALSE;
    hif_dma_menu[1].master = DMA_HIF1;
    hif_dma_menu[1].addr = 0;
#endif
    // Configure DMA
    //hif_dma_input.size = DMA_SHORT;
    hif_dma_input[0].count = 0;
    hif_dma_input[0].callback = NULL;
    hif_dma_input[1].count = 0;
    hif_dma_input[1].callback = NULL;
    //hif_dma_input.menu = (void*) &hif_dma_menu;

    //define ECO solution for MT6256E4,MT6575E2, MT6255E2 or MTK later chips
    
    #if defined(MT6255) || defined(MT6256)//MT6255 and MT6256 support query chip version
        chip_version = INT_SW_SecVersion(); //Query chip version
    #endif
         
    #if defined(__AST_TL1_TDD__)  //HIF ECO only support for TDD project
      #if defined(MT6575_S01)
          hif_eco_support = KAL_FALSE;
      #elif defined(MT6752)
          hif_eco_support = KAL_TRUE;
      #elif defined(MT6255) //MT6255E2 support HIF ECO
          if(SW_SEC_0 != chip_version)
          {
              hif_eco_support = KAL_TRUE;
          }
      #elif defined(MT6256) //MT6256E4,MT6256E5 support HIF ECO
          if(SW_SEC_1 == chip_version) //SW_SEC_0: MT6256E2,E3,E4, SW_SEC_1: MT6256E5
          {
    	      hif_eco_support = KAL_TRUE;
          }
    	#endif
    #endif
    
    hif_events = kal_create_event_group("HIFDrv");
}

HIF_HANDLE hif_open(kal_uint32 port)
{
  #if defined(__AST_TL1_TDD__) && defined(HIF1_CHANNEL_SUPPORT)
    kal_uint32 dedicated_engine_id=0;
  #else
  kal_uint32 EngineIndex;
  #endif
    //ASSERT(port < HIF_MAX_PORT_NUM);
    if (port >= HIF_MAX_PORT_NUM)
        return 0;
//for TDD project
#if defined(__AST_TL1_TDD__) && defined(HIF1_CHANNEL_SUPPORT)
  if(port == ast_hif_port)
  {
      dedicated_engine_id=1; //for TD,use port 1,this engine have high priority interrupt.
  }
  else
  {
      dedicated_engine_id=0; //for WiFi or other module,use port 0,this engine would not have high priority interrupt.
  }
  hif_internal_handle[dedicated_engine_id].user = 1;
  hif_internal_handle[dedicated_engine_id].engine_id = dedicated_engine_id;
  hif_internal_handle[dedicated_engine_id].port = port;
  hif_internal_handle[dedicated_engine_id].A0H_CPU_BUSY = KAL_FALSE;
  hif_internal_handle[dedicated_engine_id].A0L_CPU_BUSY = KAL_FALSE; 
  hif_internal_handle[dedicated_engine_id].DMA_BUSY = KAL_FALSE; 
  #ifdef MTK_SLEEP_ENABLE
  if(0xFF == hif_sleepMode_handle[dedicated_engine_id])  //lock MD
  {
      hif_sleepMode_handle[dedicated_engine_id] = L1SM_GetHandle();
  }  
  #endif
  return (HIF_HANDLE)(&hif_internal_handle[dedicated_engine_id]);
#else
  //save this for NON-TDD project
    for (EngineIndex=0; EngineIndex<HIF_ENGINE_COUNT; EngineIndex++)
    {
        if (hif_internal_handle[EngineIndex].user == 0)
        {
            // Found an available engine.
            hif_internal_handle[EngineIndex].user = 1;
            hif_internal_handle[EngineIndex].engine_id = EngineIndex;
            hif_internal_handle[EngineIndex].port = port;
            hif_internal_handle[EngineIndex].A0H_CPU_BUSY = KAL_FALSE;
            hif_internal_handle[EngineIndex].A0L_CPU_BUSY = KAL_FALSE;
            hif_internal_handle[EngineIndex].DMA_BUSY = KAL_FALSE;
            #ifdef MTK_SLEEP_ENABLE
            if(0xFF == hif_sleepMode_handle[EngineIndex])  //lock MD
            {
                hif_sleepMode_handle[EngineIndex] = L1SM_GetHandle();				
            }  
            #endif  
            return (HIF_HANDLE)(&hif_internal_handle[EngineIndex]);
        }
    }
    return (HIF_HANDLE)(NULL);
#endif
}

HIF_RESULT hif_close(HIF_HANDLE handle)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle != NULL);
    if(pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pHandle->user != 0);
    if(pHandle->user == 0)
        return HIF_RESULT_INVALID_HANDLE;
    hif_config_done[pHandle->engine_id] = KAL_FALSE;
    pHandle->user = 0;
    pHandle->engine_id = 0;
    pHandle->port = 0;
    return HIF_RESULT_OK;
}

HIF_RESULT hif_config(HIF_HANDLE handle, HIF_CONFIG_T* pConfigParam)
{
    kal_uint32 save_irq_mask;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle != NULL);
    if(pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pHandle->user != 0);
    if(pHandle->user == 0)
        return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(pConfigParam != NULL);
    if(pConfigParam == NULL)
	    return HIF_RESULT_INVALID_ARGUMENT;
    pHandle->config = *pConfigParam;

    save_irq_mask = SaveAndSetIRQMask();
    NLI_ARB_SET_LPCE_SEL(pHandle->port, pHandle->engine_id);
    #if defined(NFI_HIF_SHAREPIN_SUPPORT)
    NFI_HIF_SHR_PIN_CFG;
    #endif
    RestoreIRQMask(save_irq_mask);

    switch (pHandle->config.hif_base_clk)
    {
    #if defined(MT6276)
    case 122:
        break;
    #elif defined(MT6256)||defined(MT6255)
        case 104:
            break;
    #elif defined(MT6575)||defined(MT6577)
        case 99:
            break;
    #elif defined(MT6280)
        case 80:
            break;
    #elif defined(MT6752)
        case 133:
            break;
    #endif
    default:
        ASSERT(0);
        //return HIF_RESULT_INVALID_ARGUMENT;
    }
//set HIF register
    switch (pHandle->config.hif_bus_width)
    {
    case 8:
    case 16:
        SET_HIF_BUS_WIDTH(pHandle->engine_id, pHandle->config.hif_bus_width);
        break;
    default:
        //ASSERT(0);
        return HIF_RESULT_INVALID_ARGUMENT;
    }
	//for V2,set LCD timing,set HIF_TIME0_REG/HIF_TIME1_REG

    SET_HIF_CE2WR_SETUP_TIME (pHandle->engine_id, pHandle->config.hif_time_c2ws);
    SET_HIF_CE2WR_HOLD_TIME  (pHandle->engine_id, pHandle->config.hif_time_c2wh);
    SET_HIF_CE2RD_SETUP_TIME (pHandle->engine_id, pHandle->config.hif_time_c2rs);
    SET_HIF_CE2RD_HOLD_TIME  (pHandle->engine_id, pHandle->config.hif_time_c2rh);
    SET_HIF_WRITE_WAIT_STATE (pHandle->engine_id, pHandle->config.hif_time_wst);
    SET_HIF_READ_LATENCY_TIME(pHandle->engine_id, pHandle->config.hif_time_rlt);
    SET_HIF_CS_HIGH_WIDTH_TIME(pHandle->engine_id, pHandle->config.hif_time_chw);

    hif_config_done[pHandle->engine_id] = KAL_TRUE;
    return HIF_RESULT_OK;
}

HIF_RESULT hif_power_ctrl(HIF_HANDLE handle, kal_bool bPowerOn)
{
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    kal_uint32 save_irq_mask;
    //ASSERT(pHandle);
    if(pHandle == NULL)
        return HIF_RESULT_INVALID_HANDLE;
    save_irq_mask = SaveAndSetIRQMask();
    if (bPowerOn)
    {
        #if defined MT6752
        if((!hif_power_on[pHandle->engine_id]) || CHECK_HIF_POWER_DOWN)
        #else
        if(!hif_power_on[pHandle->engine_id])
        #endif
        {
            HIF_POWER_ON(pHandle->engine_id);
            
            #if defined(MT6752) //MD HIF re-init MD HIF module, NLI module when power on
            if(hif_config_done[pHandle->engine_id])
            {
                hif_config(handle, &(pHandle->config));
                if(pHandle->ultra_high_en)
                {
                    SET_HIF_ULTRA(pHandle->engine_id, 1);
                }    
            }        
            #endif
            hif_power_on[pHandle->engine_id] = KAL_TRUE;
        }
    }
    else
    {
        hif_power_on[pHandle->engine_id] = KAL_FALSE;
        HIF_POWER_OFF(pHandle->engine_id);
    }
    RestoreIRQMask(save_irq_mask);
    return HIF_RESULT_OK;
}

#ifdef __MTK_TARGET__
#if defined(MT6752)
PRAGMA_BEGIN_COMPILER_OPTIMIZE_TIME
__attribute__ ((section ("INTSRAM_ROCODE"))) 
#endif
#endif
HIF_RESULT hif_mcu_write_fast(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size)
{
    kal_uint32 index = 0;
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    kal_uint32 hif_ultra_old; //set HIF ultra high for MCU mode
    kal_uint32 save_irq_mask;
    #endif
    HIF_RESULT result = HIF_RESULT_OK;
    volatile kal_uint8 index_delay; 
    
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;

    //Set A0H_CPU_BUSY or A0L_CPU_BUSY flag
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    save_irq_mask = SaveAndSetIRQMask();
    if(type == HIF_TYPE_A0H_CPU)
    {
      ASSERT(!pHandle->A0H_CPU_BUSY);
      pHandle->A0H_CPU_BUSY = KAL_TRUE;
    }
    else
    {
      ASSERT(!pHandle->A0L_CPU_BUSY);
      pHandle->A0L_CPU_BUSY = KAL_TRUE;			
    }
    hif_ultra_old = GET_HIF_ULTRA(pHandle->engine_id);	
    if(hif_ultra_old != 1)
    {	
      SET_HIF_ULTRA(pHandle->engine_id, 0x1);
      //GET_HIF_ULTRA(pHandle->engine_id);
    }
    RestoreIRQMask(save_irq_mask);
    #endif
	  
    if(hif_eco_support && pHandle->DMA_BUSY)
    {                    
      SET_HIF_MCU_ACS_REQ(pHandle->engine_id);
      while(PIF_BUSY(pHandle->engine_id));
      for(index_delay=0; index_delay<10; index_delay++);	//wait 30 CPU clock
      SET_HIF_MCU_ACS_STA(pHandle->engine_id);
    }
    if ((pHandle->config.hif_bus_width == 8) && (type == HIF_TYPE_A0H_CPU))
    {
      for (index = 0; index < size; index++)
      {
        *(volatile kal_uint8*)(HIF_PORT_MCU_A0_HIGH_ADDR(pHandle->engine_id)) = *(volatile kal_uint8*)(((kal_uint8*)(addr)) + index);
      }	       
    }
    else if ((pHandle->config.hif_bus_width == 8) && (type == HIF_TYPE_A0L_CPU))
    {
      for (index = 0; index < size; index++)
      {
        *(volatile kal_uint8*)(HIF_PORT_MCU_A0_LOW_ADDR(pHandle->engine_id)) = *(volatile kal_uint8*)(((kal_uint8*)(addr)) + index);
      }	       
    }
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    else if( (pHandle->config.hif_bus_width == 16) && (type == HIF_TYPE_A0H_CPU))
    {
      for (index = 0; index < size/2; index++)
      {
        *(volatile kal_uint16*)(HIF_PORT_MCU_A0_HIGH_ADDR(pHandle->engine_id)) = *(volatile kal_uint16*)(((kal_uint16*)(addr)) + index);
      }
    }
    else if( (pHandle->config.hif_bus_width == 16) && (type == HIF_TYPE_A0L_CPU))
    {
      for (index = 0; index < size/2; index++)
      {
        *(volatile kal_uint16*)(HIF_PORT_MCU_A0_LOW_ADDR(pHandle->engine_id)) = *(volatile kal_uint16*)(((kal_uint16*)(addr)) + index);
      }
    }
    #endif	  
    else
    {
      //ASSERT(0);
      result = HIF_RESULT_INVALID_ARGUMENT;
    }    
    if(hif_eco_support && pHandle->DMA_BUSY)
    {	
      CLEAR_HIF_MCU_ACS_REQ_STA(pHandle->engine_id);
    }

    //Clear A0H_CPU_BUSY or A0L_CPU_BUSY flag
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    if(type == HIF_TYPE_A0H_CPU)
    {
      pHandle->A0H_CPU_BUSY = KAL_FALSE;
    }
    else
    {
      pHandle->A0L_CPU_BUSY = KAL_FALSE;
    }	  
	  
    if(hif_ultra_old != 1)
    {
      save_irq_mask = SaveAndSetIRQMask(); //restore hif ultra orignal setting	
      SET_HIF_ULTRA(pHandle->engine_id, hif_ultra_old);
      RestoreIRQMask(save_irq_mask);
    }
    #endif
    return result;
}	

#ifdef __MTK_TARGET__
#if defined(MT6752)
__attribute__ ((section ("INTSRAM_ROCODE"))) 
#endif
#endif
HIF_RESULT hif_mcu_read_fast(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size)
{
    kal_uint32 index = 0;
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    kal_uint32 hif_ultra_old; //set HIF ultra high for MCU mode
    kal_uint32 save_irq_mask;
    #endif
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    volatile kal_uint8 index_delay;

    //Set A0H_CPU_BUSY or A0L_CPU_BUSY flag
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    save_irq_mask = SaveAndSetIRQMask();
    if(type == HIF_TYPE_A0H_CPU)
    {
      ASSERT(!pHandle->A0H_CPU_BUSY);
      pHandle->A0H_CPU_BUSY = KAL_TRUE;
    }
    else
    {
      ASSERT(!pHandle->A0L_CPU_BUSY);
      pHandle->A0L_CPU_BUSY = KAL_TRUE;			
    }
    
    hif_ultra_old = GET_HIF_ULTRA(pHandle->engine_id);	
    if(hif_ultra_old != 1)
    {	
      SET_HIF_ULTRA(pHandle->engine_id, 0x1);
      //GET_HIF_ULTRA(pHandle->engine_id);
    }
    RestoreIRQMask(save_irq_mask);
    #endif 
	  
    if(hif_eco_support  && pHandle->DMA_BUSY)
    {                    
      SET_HIF_MCU_ACS_REQ(pHandle->engine_id);
      while(PIF_BUSY(pHandle->engine_id));
      for(index_delay=0; index_delay<10; index_delay++);	//wait 30 CPU clock
      SET_HIF_MCU_ACS_STA(pHandle->engine_id);
    }
    if ((pHandle->config.hif_bus_width == 8) && (type == HIF_TYPE_A0H_CPU))
    {
      for (index = 0; index < size; index++)
      {
        *(volatile kal_uint8*)(kal_uint8*)(((kal_uint8*)addr)+index) = *(volatile kal_uint8*)(HIF_PORT_MCU_A0_HIGH_ADDR(pHandle->engine_id));
      }	       
    }
    else if ((pHandle->config.hif_bus_width == 8) && (type == HIF_TYPE_A0L_CPU))
    {
      for (index = 0; index < size; index++)
      {
        *(volatile kal_uint8*)(kal_uint8*)(((kal_uint8*)addr)+index) = *(volatile kal_uint8*)(HIF_PORT_MCU_A0_LOW_ADDR(pHandle->engine_id));
      }	       
    }
    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    else if( (pHandle->config.hif_bus_width == 16) && (type == HIF_TYPE_A0H_CPU))
    {
      for (index = 0; index < size/2; index++)
      {
        *(volatile kal_uint16*)(kal_uint16*)(((kal_uint16*)addr)+index) = *(volatile kal_uint16*)(HIF_PORT_MCU_A0_HIGH_ADDR(pHandle->engine_id));
      }
    }
    else if( (pHandle->config.hif_bus_width == 16) && (type == HIF_TYPE_A0L_CPU))
    {
      for (index = 0; index < size/2; index++)
      {
        *(volatile kal_uint16*)(kal_uint16*)(((kal_uint16*)addr)+index) = *(volatile kal_uint16*)(HIF_PORT_MCU_A0_LOW_ADDR(pHandle->engine_id));
      }
    }
    #endif	  
    else
    {
      //ASSERT(0);
      result = HIF_RESULT_INVALID_ARGUMENT;
    }    
    if(hif_eco_support  && pHandle->DMA_BUSY)
    {	
      CLEAR_HIF_MCU_ACS_REQ_STA(pHandle->engine_id);
    }

    #if !defined(__MD_HIF_AST8BIT_OPT__)  //Optiomize for MT6752+AST3001
    //Clear A0H_CPU_BUSY or A0L_CPU_BUSY flag
    if(type == HIF_TYPE_A0H_CPU)
    {
      pHandle->A0H_CPU_BUSY = KAL_FALSE;
    }
    else
    {
      pHandle->A0L_CPU_BUSY = KAL_FALSE;
    }	  

    if(hif_ultra_old != 1)
    {
      save_irq_mask = SaveAndSetIRQMask(); //restore hif ultra orignal setting	
      SET_HIF_ULTRA(pHandle->engine_id, hif_ultra_old);
      RestoreIRQMask(save_irq_mask);
    }
    #endif
    return result;

}
#ifdef __MTK_TARGET__
#if defined(MT6752)
PRAGMA_END_COMPILER_OPTIMIZE_TIME 
#endif
#endif

HIF_RESULT hif_dma_write_internal(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    kal_uint32 retrieved_events;
    ENABLE_HIF_INTR(pHandle->engine_id);
    pHandle->DMA_BUSY = KAL_TRUE;
    #ifdef MTK_SLEEP_ENABLE
    L1SM_SleepDisable(hif_sleepMode_handle[pHandle->engine_id]);//unlock MD sleep mode
    #endif
    if (fCB == NULL)
    {
      if(!(kal_if_lisr()||kal_if_hisr()))
      {
        //Clear the evnet for pHandle->engine_id HIF for task level
        kal_set_eg_events(hif_events, ~(1 << pHandle->engine_id), KAL_AND);
      }
      else 
        ASSERT(0); //HIF DMA blocking mode is not allowed in LISR or HISR
    }
    // Setup HIF.
    //SET_HIF_BUS_WIDTH(pHandle->engine_id, pHandle->config.hif_bus_width);
    SET_HIF_WRITE(pHandle->engine_id);
    if(type == HIF_TYPE_A0H_DMA)
    {
      SET_HIF_A0_HIGH(pHandle->engine_id);
    }
    else if(type == HIF_TYPE_A0L_DMA)
    {	
      SET_HIF_A0_LOW(pHandle->engine_id);
    }
    SET_HIF_DAMOUNT(pHandle->engine_id, size);
    // Set DMA address.
/*
    PDMA_SET_BUF_ADDR(pHandle->engine_id, addr);
    PDMA_SET_RW_DIRECTION(pHandle->engine_id, 0); // 1:read; 0: write
    PDMA_SET_BUF_LEN(pHandle->engine_id, size);
    PDMA_SET_BURST_LEN(pHandle->engine_id, 7);

    PDMA_START(pHandle->engine_id); //Start DMA
*/
    //dma config
    SLA_CustomLogging("HDM",1);//set for debug
    #if (defined(MT6752) && !defined(__ANDROID_MODEM__))
    hif_dma_menu[pHandle->engine_id].addr = addr + 0x80000000;
    #else
    hif_dma_menu[pHandle->engine_id].addr = addr;
    #endif
    hif_dma_input[pHandle->engine_id].count  = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
    hif_dma_input[pHandle->engine_id].type = DMA_HWTX;
    hif_dma_input[pHandle->engine_id].size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
    hif_dma_input[pHandle->engine_id].callback = NULL;
    hif_dma_input[pHandle->engine_id].menu = (void*) &hif_dma_menu[pHandle->engine_id];
    DMA_Config(hif_sysdma_id[pHandle->engine_id], &hif_dma_input[pHandle->engine_id], KAL_TRUE);

    // Set fCB as HIF interrupt callback.
    hif_cb[pHandle->engine_id] = fCB;
    // Start HIF
    START_HIF(pHandle->engine_id);

    if (fCB == NULL)
    {
      if(!(kal_if_lisr()||kal_if_hisr()))
        {
          kal_retrieve_eg_events(hif_events, (1<<pHandle->engine_id), KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);
          pHandle->DMA_BUSY = KAL_FALSE;
        }
    else 
      ASSERT(0); //HIF DMA blocking mode is not allowed in LISR or HISR
    }
    return result;
}
HIF_RESULT hif_write(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
       
    #if defined (MT6255)    
      kal_bool cb_en = KAL_FALSE;
      if(SW_SEC_0 == chip_version)
      {
        if ((type == HIF_TYPE_A0H_DMA)||(type == HIF_TYPE_A0L_DMA))
          {
            type --; // change from DMA to CPU
            if(fCB)
              cb_en = KAL_TRUE;
          }
      }
    #endif

    if ((type == HIF_TYPE_A0H_DMA) || (type == HIF_TYPE_A0L_DMA))
    { 
        SLA_CustomLogging("H_W",2);//set for debug
    }
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
    if((pHandle == NULL)||(pHandle->user == 0))
      return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(size != 0);
    //ASSERT((pHandle->config.hif_bus_width==8)? 1 : (size%2==0));
    if ((size == 0) || (!((pHandle->config.hif_bus_width==8)? 1 : (size%2==0))))
      return HIF_RESULT_INVALID_ARGUMENT;
    //ASSERT(hif_power_on[pHandle->engine_id] == KAL_TRUE);
    if (hif_power_on[pHandle->engine_id] == KAL_FALSE)
      return HIF_RESULT_HIF_NOT_POWER_ON;
    //check if DMA is busy,to avoid re-entry DMA mode.
    if ((type == HIF_TYPE_A0H_DMA)||(type == HIF_TYPE_A0L_DMA))
    {
        ASSERT(!pHandle->DMA_BUSY);
        ASSERT(fCB);
    }
    if(type == HIF_TYPE_A0H_CPU||type == HIF_TYPE_A0L_CPU)
      result = hif_mcu_write_fast( handle, type, addr, size);
    else if(type == HIF_TYPE_A0H_DMA||type == HIF_TYPE_A0L_DMA)
      result = hif_dma_write_internal(handle, type, addr, size, fCB);

    #if defined (MT6255)
      if(SW_SEC_0 == chip_version)
        {    
          if((result == HIF_RESULT_OK) && (cb_en))
          fCB();
        }
    #endif

    return result;
}

HIF_RESULT hif_dma_read_internal(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    kal_uint32 retrieved_events;
    // Enable HIF interrupt.
    ENABLE_HIF_INTR(pHandle->engine_id);
    pHandle->DMA_BUSY = KAL_TRUE;
    #ifdef MTK_SLEEP_ENABLE
    L1SM_SleepDisable(hif_sleepMode_handle[pHandle->engine_id]);//unlock MD sleep mode
    #endif
    
    if (fCB == NULL)
    {
      if(!(kal_if_lisr()||kal_if_hisr()))
        {
          //Clear the evnet for pHandle->engine_id HIF for task level
          kal_set_eg_events(hif_events, ~(1 << pHandle->engine_id), KAL_AND);
        }
      else 
      ASSERT(0); //HIF DMA blocking mode is not allowed in LISR or HISR
    }
    // Setup HIF.
    //SET_HIF_BUS_WIDTH(pHandle->engine_id, pHandle->config.hif_bus_width);
    SET_HIF_READ(pHandle->engine_id);
    if(type == HIF_TYPE_A0H_DMA)
    {
      SET_HIF_A0_HIGH(pHandle->engine_id);
    }
    else if(type == HIF_TYPE_A0L_DMA)
    {	
      SET_HIF_A0_LOW(pHandle->engine_id);
    }
    SET_HIF_DAMOUNT(pHandle->engine_id, size);
/*              // Set DMA address.
    PDMA_SET_BUF_ADDR(pHandle->engine_id, addr);
    PDMA_SET_RW_DIRECTION(pHandle->engine_id, 1); // 1:read; 0: write
    PDMA_SET_BUF_LEN(pHandle->engine_id, size);
    PDMA_SET_BURST_LEN(pHandle->engine_id, 7);

    PDMA_START(pHandle->engine_id); //Start DMA
*/
    //dma config
    SLA_CustomLogging("HDM",1);//set for debug
    #if (defined(MT6752) && !defined(__ANDROID_MODEM__))
    hif_dma_menu[pHandle->engine_id].addr = addr + 0x80000000;
    #else
    hif_dma_menu[pHandle->engine_id].addr = addr;
    #endif
    hif_dma_input[pHandle->engine_id].count  = (pHandle->config.hif_bus_width == 16) ? (size >> 1) : size;
    hif_dma_input[pHandle->engine_id].type = DMA_HWRX;
    hif_dma_input[pHandle->engine_id].size = (pHandle->config.hif_bus_width == 16) ? DMA_SHORT : DMA_BYTE;
    hif_dma_input[pHandle->engine_id].callback = NULL;
    hif_dma_input[pHandle->engine_id].menu = (void*) &hif_dma_menu[pHandle->engine_id];
    DMA_Config(hif_sysdma_id[pHandle->engine_id], &hif_dma_input[pHandle->engine_id], KAL_TRUE);

    // Set fCB as HIF interrupt callback.
    hif_cb[pHandle->engine_id] = fCB;

    // Start HIF
    START_HIF(pHandle->engine_id);
    if (fCB == NULL)
    {
      if(!(kal_if_lisr()||kal_if_hisr()))
      {
        kal_retrieve_eg_events(hif_events, (1<<pHandle->engine_id), KAL_OR_CONSUME, &retrieved_events, KAL_SUSPEND);
            	      pHandle->DMA_BUSY = KAL_FALSE;
      }
      else 
        ASSERT(0); //HIF DMA blocking mode is not allowed in LISR or HISR
    }	
   return result;
}
HIF_RESULT hif_read(HIF_HANDLE handle, HIF_TYPE type, kal_uint32 addr, kal_uint32 size, HIF_CALLBACK fCB)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    
    #if defined (MT6255)     
    kal_bool cb_en = KAL_FALSE;
      if(SW_SEC_0 == chip_version)
      {
        if ((type == HIF_TYPE_A0H_DMA)||(type == HIF_TYPE_A0L_DMA))
        {
          type --; // change from DMA to CPU
          if(fCB)
            cb_en = KAL_TRUE;
        }
      }
    #endif

    if ((type == HIF_TYPE_A0H_DMA) || (type == HIF_TYPE_A0L_DMA))
    { 
        SLA_CustomLogging("H_R",2);//set for debug
    }
	
    //ASSERT(pHandle != NULL);
    //ASSERT(pHandle->user != 0);
    if((pHandle == NULL)||(pHandle->user == 0))
      return HIF_RESULT_INVALID_HANDLE;
    //ASSERT(size != 0);
    //ASSERT((pHandle->config.hif_bus_width==8)? 1 : (size%2==0));
    if ((size == 0) || (!((pHandle->config.hif_bus_width==8)? 1 : (size%2==0))))
      return HIF_RESULT_INVALID_ARGUMENT;
       
    if (hif_power_on[pHandle->engine_id] == KAL_FALSE)
      return HIF_RESULT_HIF_NOT_POWER_ON;
        
    //check if DMA is busy,to avoid re-entry DMA mode.
    if ((type == HIF_TYPE_A0H_DMA)||(type == HIF_TYPE_A0L_DMA))
    {
        ASSERT(!pHandle->DMA_BUSY);
        ASSERT(fCB);
    }
      
    //On HIF ECO Chip, blocking DMA mode is not allowed 
    if(hif_eco_support)
    {
      if(type == HIF_TYPE_A0H_DMA||type == HIF_TYPE_A0L_DMA)
      ASSERT(fCB);
    }
    if(type == HIF_TYPE_A0H_CPU||type == HIF_TYPE_A0L_CPU)
      result = hif_mcu_read_fast(handle, type, addr, size);
    else if(type == HIF_TYPE_A0H_DMA||type == HIF_TYPE_A0L_DMA)
      result = hif_dma_read_internal( handle, type, addr, size, fCB);

    #if defined (MT6255)
      if(SW_SEC_0 == chip_version)
      {    
        if((result == HIF_RESULT_OK) && (cb_en))
        fCB();
      }
    #endif
    return result;
}

void hif0_lisr(void)
{
#if defined (HIF0_CHANNEL_SUPPORT)
      IRQMask(IRQ_HIF_CODE);
#endif
    //(*(volatile kal_uint32*)HIF_INTSTA_REG(0)) = 0;//hif int status,write clear
    HIF_INT_CLEAR(0);
    hif_internal_handle[0].DMA_BUSY = KAL_FALSE;
    #ifdef MTK_SLEEP_ENABLE
    L1SM_SleepEnable(hif_sleepMode_handle[0]);//lock MD sleep mode
    #endif
    
    if(hif_internal_handle[0].realtime_callback == KAL_TRUE)
    {
      if(hif_cb[0])
      {
        hif_cb[0]();
      }
        #if defined (HIF0_CHANNEL_SUPPORT)
        IRQUnmask(IRQ_HIF_CODE);
        #endif  
    }
    else
      drv_active_hisr((kal_uint8)DRV_HIF0_HISR_ID);
}

void hif0_hisr(void)
{
    if (hif_cb[0])
    {
      hif_cb[0]();
    }
    kal_set_eg_events(hif_events, 1, KAL_OR);
#if defined (HIF0_CHANNEL_SUPPORT)
      IRQUnmask(IRQ_HIF_CODE);
    #endif
}

void hif1_lisr(void)
{
#if defined (HIF1_CHANNEL_SUPPORT)	
    IRQMask(IRQ_HIF_1_CODE);
#endif
    //(*(volatile kal_uint32*)HIF_INTSTA_REG(1)) = 0;//hif int status,write clear
    HIF_INT_CLEAR(1);
    hif_internal_handle[1].DMA_BUSY = KAL_FALSE;
    #ifdef MTK_SLEEP_ENABLE
    L1SM_SleepEnable(hif_sleepMode_handle[1]);//lock MD sleep mode
    #endif
    SLA_CustomLogging("HDM",0);//set for debug
    
    if(hif_internal_handle[1].realtime_callback == KAL_TRUE)
    {
      if(hif_cb[1])
      {
        hif_cb[1]();
      }
      #if defined (HIF1_CHANNEL_SUPPORT)
      IRQUnmask(IRQ_HIF_1_CODE);
      #endif
    }
    else
      drv_active_hisr((kal_uint8)DRV_HIF1_HISR_ID);
}

void hif1_hisr(void)
{
    if (hif_cb[1])
    {
      hif_cb[1]();
    }
    kal_set_eg_events(hif_events, 2, KAL_OR);
#if defined (HIF1_CHANNEL_SUPPORT)
    IRQUnmask(IRQ_HIF_1_CODE);
#endif
}

void hif_wait_for_idle(kal_uint32 engine_id)
{
    while(HIF_BUSY(engine_id));
}

HIF_RESULT hif_ioctl(HIF_HANDLE handle, HIF_IOCTL_CODE code, void* pParam)
{
    HIF_RESULT result = HIF_RESULT_OK;
    HIF_INTERNAL_HANDLE_T* pHandle = (HIF_INTERNAL_HANDLE_T*) handle;
    //ASSERT(pHandle);
    if(pHandle == NULL)
      return HIF_RESULT_INVALID_HANDLE;
    switch (code)
    {
      case HIF_IOCTL_QUERY_TIMING_SUPPORT:
      {
        HIF_QUERY_TIMING_SUPPORT_T* pTimingSupport = (HIF_QUERY_TIMING_SUPPORT_T*) pParam;
        //ASSERT(pTimingSupport);
        if (pTimingSupport == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        pTimingSupport->c2ws_support = KAL_TRUE;
        pTimingSupport->c2wh_support = KAL_TRUE;
        pTimingSupport->wst_support = KAL_TRUE;
        pTimingSupport->c2rs_support = KAL_TRUE;
        pTimingSupport->c2rh_support = KAL_TRUE;
        pTimingSupport->rlt_support = KAL_TRUE;
        pTimingSupport->chw_support = KAL_TRUE;
      }
      break;
      case HIF_IOCTL_ULTRA_HIGH_CTRL:
      {
        HIF_ULTRA_HIGH_CTRL_T* pUltraHighCtrl = (HIF_ULTRA_HIGH_CTRL_T*) pParam;
        kal_uint32 save_irq_mask;
            
        //ASSERT(pUltraHighCtrl);
        if (pUltraHighCtrl == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
            if (pUltraHighCtrl->ultra_high_en == KAL_TRUE)
          {
            save_irq_mask = SaveAndSetIRQMask();
            SET_HIF_ULTRA(pHandle->engine_id, 1);
                pHandle->ultra_high_en = KAL_TRUE;
            RestoreIRQMask(save_irq_mask);
          }
          else
          {
            save_irq_mask = SaveAndSetIRQMask();
            SET_HIF_ULTRA(pHandle->engine_id, 0);
                pHandle->ultra_high_en = KAL_FALSE;
            RestoreIRQMask(save_irq_mask);
          }
      }
      break;
      case HIF_IOCTL_QUERY_CLOCK_SUPPORT:
      {
        HIF_QUERY_CLOCK_SUPPORT_T* pColckSupport = (HIF_QUERY_CLOCK_SUPPORT_T*) pParam;
        //ASSERT(pColckSupport);
        if (pColckSupport == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        #if defined(MT6276)
          pColckSupport->clock[0] = 122;
        #elif defined(MT6256)||defined(MT6255)
          pColckSupport->clock[0] = 104;
            #elif defined(MT6575)||defined(MT6577)
          pColckSupport->clock[0] = 99;
            #elif defined(MT6280)
              pColckSupport->clock[0] = 80;
            #elif defined(MT6752)
              pColckSupport->clock[0] = 133;
        #endif
        pColckSupport->clock[1] = 0;
        pColckSupport->clock[2] = 0;
        pColckSupport->clock[3] = 0;
      }
      break;
      case HIF_IOCTL_GET_PARAM:
      {
        HIF_CONFIG_T* pHIFParam = (HIF_CONFIG_T*) pParam;
        //ASSERT(pHIFParam);
        if (pHIFParam == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        *pHIFParam = pHandle->config;
            /*
            pHIFParam->hif_time_c2ws = pHandle->config.hif_time_c2ws;
            pHIFParam->hif_time_c2wh = pHandle->config.hif_time_c2wh;
            pHIFParam->hif_time_wst = pHandle->config.hif_time_wst;
            pHIFParam->hif_time_c2rs = pHandle->config.hif_time_c2rs;
            pHIFParam->hif_time_c2rh = pHandle->config.hif_time_c2rh;
            pHIFParam->hif_time_rlt = pHandle->config.hif_time_rlt;
            pHIFParam->hif_base_clk = pHandle->config.hif_base_clk;
            pHIFParam->hif_bus_width = pHandle->config.hif_bus_width;
            */
      }
      break;
      case HIF_IOCTL_QUERY_CAPABILITY:
      {
        HIF_CAPABILITY_T* pCapability = (HIF_CAPABILITY_T*) pParam;
        //ASSERT(pCapability);
        if (pCapability == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        pCapability->transfer_length_min = 1;
        pCapability->transfer_length_max = 65536;
      }
      break;
      case HIF_IOCTL_QUERY_POWER_STATE:
      {
        HIF_POWER_STATE_T* pPowerState = (HIF_POWER_STATE_T*) pParam;
        if (pPowerState == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        pPowerState->hif_power_on = hif_power_on[pHandle->engine_id];
      }
      break;
      case HIF_IOCTL_REALTIME_CALLBACK:
      {
        HIF_REALTIME_CALLBACK_T* pRealtimeCallback = (HIF_REALTIME_CALLBACK_T*) pParam;
        //ASSERT(pRealtimeCallback);
        if (pRealtimeCallback == NULL)
        {
          result = HIF_RESULT_INVALID_ARGUMENT;
          break;
        }
        if (pRealtimeCallback->realtime_callback_en == KAL_TRUE)
        {
          pHandle->realtime_callback=KAL_TRUE;
        }
        else
        {
          pHandle->realtime_callback=KAL_FALSE;
        }
      }
      break;
      default:
      //ASSERT(0);
      result = HIF_RESULT_NOT_SUPPORTED;
      break;
    }
    return result;
}

#endif
