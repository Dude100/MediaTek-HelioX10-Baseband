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
 *   sdiotest.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   SDIO test code
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------

 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================ 
 ****************************************************************************/
 
// MTK 
#include "drv_features.h"
#include "drv_comm.h"
#include "msdc_reg_adap.h"
#include "reg_base.h" 
#include "intrCtrl.h"

// SDIO
#include "msdc_def.h"
#include "sd_def.h"
#include "sdio_def.h"
#include "sdio_test.h"
#include "sdio_sw.h"

#if (defined(__MSDC_SD_MMC__)&&defined(__MSDC_SD_SDIO__)) || defined(__MSDC2_SD_SDIO__)
extern cmd52_config_struct cmd52_config;
extern cmd53_config_struct cmd53_config;
#define WIFI_FUNC		1



__align(4) kal_uint8 buffer[1024];
extern __align(4) kal_uint8 sdio_cccr_reg[SDIO_CCCR_SIZE];
extern __align(4) kal_uint8 sdio_fbr_reg[SDIO_FBR_SIZE];
extern __align(4) kal_uint8 sdio_tuple[SDIO_MAX_FUCN_ID][SDIO_TUPLE_SIZE];
volatile kal_uint32 cmd = 0, arg = 0;
volatile kal_uint32 flag52 = 1, flag53 = 0, flag_SD = 0, flag_4bit = 1;
cmd52_config_struct cmd52_config;
cmd53_config_struct cmd53_config;
void SDIO_test_main2(void);
extern MSDC_HANDLE *msdc2_handle ;

void sdio_clr_int(void)
{
   UINT32      mcrValue;
   //SDIO_Register_Read_poll(SDIO_FUCN_1, MCR_ISAR, (kal_uint32*)&mcrValue , SDIO_FIX);   
   //NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);   
}
void test_hisr(void) 
{
   dbg_print("interrupt callback\r\n");	
   sdio_clr_int();							
}   
 

void test_sdio_ini(void)
{
	SDC_CMD_STATUS status;	
	kal_uint8 version;
	kal_uint16 tick;
	kal_bool ready;
	kal_uint32 retry_count=0;
	kal_uint32 block_size=0;
	
	
	/*initialize*/
	dbg_print("SDIO initilaization start\r\n");				
	status=SDIO_Initialize();
	dbg_print("SDIO initilaization end=%d\r\n", status);
	dbg_print("SDIO test start\r\n");
	
	/*CCCR verison*/	
	status=SDIO_read_CCCR_ver(&version);
	dbg_print("read CCCR ver status %d ver %d \r\n", status, version);								
	/*SDIO verison*/	
   status=SDIO_read_SDIO_ver(&version);
   dbg_print("read SDIO ver status %d ver %d \r\n", status, version);										
	/*SD verison*/	
	status=SDIO_read_SD_ver(&version);
   dbg_print("read SDIO SD status %d ver %d \r\n", status, version);								

	/* check card capability*/	
	status=SDIO_read_capacity();
	if(!status)
	{		
		dbg_print("SDC %d%\r\n", SDIO_support_SDC());							
		dbg_print("SMB %d%\r\n", SDIO_support_SMB());							
		dbg_print("SRW %d%\r\n", SDIO_support_SRW());							
		dbg_print("SBS %d%\r\n", SDIO_support_SBS());							
		dbg_print("S4MI %d%\r\n", SDIO_support_S4MI());							
		//dbg_print("E4MI %d%\r\n", SDIO_enable_E4MI(KAL_TRUE));							
		dbg_print("LSC %d%\r\n", SDIO_support_LSC());							
		dbg_print("4BLS %d%\r\n", SDIO_support_4BLS());										
	}
	else
	{
		dbg_print("read capacity %d failed \r\n", cmd52_config.adrs);						
	}	
		
	/* enable SDIO function*/	
	retry_count=0;
	
				
   /* set the block size of func1 to 128*/
			   	   						
	dbg_print("set function block size %d \r\n", 128);						
		
	status=SDIO_configure_BLK_size(SDIO_FUCN_1, 128);
	dbg_print("set block size (function 1) %d\r\n", status);												
	status=SDIO_configure_BLK_size(SDIO_FUCN_0, 128);
	dbg_print("set block size(function 0) %d\r\n", status);																
	
	// config the sdio controller
	MSDC_SetBits32(SDC_CFG, SDC_CFG_SDIO);// enable SDIO mode
	MSDC_WriteReg32(SDIO_CFG, 1); // enable SDIO interrupt
	
	// *****************************************//
	// always turn on the serial clock
	// MSDC_SetBits32(MSDC_CFG, MSDC_CFG_SCKON);
	// *****************************************//	

	
	
	status=SDIO_query_IO_id(SDIO_INTERFACE_WLAN);
	dbg_print("SDIO_INTERFACE_WLAN function id =%d\r\n", status);	
	
	status=SDIO_query_IO_id(SDIO_INTERFACE_WLAN);
	dbg_print("SDIO_INTERFACE_WLAN function id =%d\r\n", status);					  
	block_size=SDIO_query_BLK_size(SDIO_FUCN_1);
	dbg_print("function 1 block size =%d\r\n", block_size);					  
	
	SDIO_int_registration(SDIO_FUCN_1, test_hisr);
	status=SDIO_enable_IO_Int(SDIO_FUCN_0, KAL_TRUE);
	dbg_print("enable card int%d \r\n",status);		
	status=SDIO_enable_IO_Int(SDIO_FUCN_1, KAL_TRUE);
	dbg_print("enable function %d int%d \r\n",SDIO_FUCN_1, status);		
	/* read all configuration register of CCCR*/	
	status=SDIO_read_CCCR();
	dbg_print("read all CCCR=%d\r\n", status);
	status=SDIO_read_FBR(1);
	dbg_print("read all FBR=%d\r\n", status);	
	
	
	/*start WiFi test*/
#ifndef MSDC2_SDIO_DVT
	if(KAL_TRUE == gMSDC_Handle->mIsInitialized)
#else
	if(KAL_TRUE == msdc2_handle->mIsInitialized)
#endif
	{
		SDIO_test_main2();
		SDIO_test_main();	
	}
	else{
		return;
	}
	while(0)
	{
		if(flag52)
		{
			cmd52_config.rw = SDIO_READ;
			cmd52_config.func = 0;
			cmd52_config.raw = KAL_FALSE;
			cmd52_config.stop = KAL_FALSE;
			cmd52_config.adrs = 0;
			cmd52_config.data = 0;
			SDIO_Cmd52(&cmd52_config);
		}
		// check SMB first (Support Multi-Block)
		// config the block size
		if(flag53)
		{
			cmd53_config.rw = SDIO_READ;
			cmd53_config.func = 0;
			cmd53_config.block = KAL_FALSE;
			cmd53_config.buffer = (kal_uint32)buffer;
			cmd53_config.count = 4;
			cmd53_config.op = SDIO_INC;
			cmd53_config.adrs = 0;
			SDIO_Cmd53(&cmd53_config);
			//dbg_print("SDIO initilaization end=%d\r\n", status);
		}
	}
	
}



kal_bool IPC_2126_MCR_Read(kal_uint16 offset, kal_uint32 *pValue)
{  
	kal_bool status;
   #if 1
   status = SDIO_Register_Read(SDIO_FUCN_1, 
                      (kal_uint32) offset, 
                      pValue,
                      SDIO_FIX);
   return status;
   #else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
}
void IPC_2126_MCR_Read_N(kal_uint16 offset, kal_uint32 pValue, kal_uint32 count, kal_bool block )
{
	cmd53_config.rw = SDIO_READ;
	cmd53_config.func = WIFI_FUNC;
	cmd53_config.block = block;
	cmd53_config.buffer = (kal_uint32)pValue;
	cmd53_config.count = count;
	cmd53_config.op = SDIO_FIX;
	cmd53_config.adrs = (kal_uint32)offset;
	SDIO_Cmd53(&cmd53_config);

}
kal_bool IPC_2126_MCR_Write(kal_uint16 offset, kal_uint32 value)
{
	kal_uint32 tmp = value;
	kal_bool	status;
	#if 1
   status = SDIO_Register_Write(SDIO_FUCN_1, 
                      (kal_uint32) offset, 
                      value,
                      SDIO_FIX);
	
	return status;
   #else                                              
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
   #endif
}
void IPC_2126_MCR_Write_N(kal_uint16 offset, kal_uint32 value, kal_uint32 count, kal_bool block )
{
	cmd53_config.rw = SDIO_WRITE;
	cmd53_config.func = WIFI_FUNC;
	cmd53_config.block = block;
	cmd53_config.buffer = (kal_uint32)value;
	cmd53_config.count = count;	
	cmd53_config.op = SDIO_FIX;
	cmd53_config.adrs = (kal_uint32)offset;
	SDIO_Cmd53(&cmd53_config);

}
/*----------------------------------------------------------------*/
/*!
* \brief
*
* \param
* \return
*/
/*----------------------------------------------------------------*/
volatile kal_bool my_flag = 1;
volatile kal_bool my_flag_2 = 0;
__align(4) kal_uint8       value[1024]= {0xff};
int SDIO_test_main(void)
{
    kal_uint32      mcrValue;
    int         tbttCount = 0;
    kal_uint32 test_count=0;
    kal_bool pending;
         SDC_CMD_STATUS status;
    //SDIO_ARG    arg;

    kal_uint32  i;
    kal_uint32	loopTestIndex;

    /* Reset chip and enable all clocks */
    NIC_MCR_WRITE(NULL, MCR_SCR, (SCR_BB_MRST | SCR_MAC_RST |
                SCR_BB_SIORST | SCR_MAC_REGRST));
    NIC_MCR_WRITE(NULL, MCR_SCR, SCR_CLK_ALL_EN);
    NIC_MCR_READ(NULL, MCR_SCR, value);

    /* Here maybe need delay for OSC stable */
	 for(i=0;i<10000;i++);

    /* Check chip ID */
    NIC_MCR_READ(NULL, MCR_PCICR, &mcrValue);
    //printk("IPN2128 ChipIDVersion read test: [0x%08lX] \n", mcrValue);
    if ((mcrValue & CHIP_ID_MASK) != CHIP_ID_REV) {
        //printk(KERN_ALERT "IPN2128 not found... \n");
    }
    //if(my_flag)
    NIC_MCR_WRITE(NULL, MCR_SDCR, BITS(4,6)); /* Use enhanced mode */

    /* Reset TSF and enable TBTT interrupt */
    /* Set our local TSF timer to 0 */
    NIC_MCR_WRITE(NULL, MCR_TTAR1, 0);
    NIC_MCR_WRITE(NULL, MCR_TTAR2, 0);
    NIC_MCR_WRITE(NULL, MCR_TTAR0, TTAR0_TSF_TIMER_VALUE_CHANGE);

    /* Set the next TBTT time and the TBTT event generation period. */
    NIC_MCR_WRITE(NULL, MCR_NTTCR, ((100) &
        NTTCR_NEXT_TBTT_TIME) | (100 << 16));

    /* Enable the TBTT event generator. */
    NIC_MCR_WRITE(NULL, MCR_MPTCR, MPTCR_EN_COMP_NEXT_TBTT_TIME | MPTCR_TBTT_ENABLE);

    /* Enable interrupt */ //IER_PRE_TBTT_INT, IER_SDIO_ABNORMAL_INT
    NIC_MCR_WRITE(NULL, MCR_IER, IER_GLOBAL_ENABLE | IER_TBTT_INT);
    NIC_MCR_READ(NULL, MCR_IER, &mcrValue);

    /* In loop, cmd53 is repeated to test interrupt event with cmd53 read */
    while (1) 
    {
         
			/*cmd52_config.rw = SDIO_READ;
			cmd52_config.func = 0;
			cmd52_config.raw = KAL_FALSE;
			cmd52_config.stop = KAL_FALSE;
			cmd52_config.adrs = 5;
			cmd52_config.data = 0;
			SDIO_Cmd52(&cmd52_config);*/
       //status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  
		 //if(	pending != 0 )  
		 if(mcrValue!=0)
		 {
		 	tbttCount++;
		 	dbg_print("Int Pending %d \r\n", pending);								
		 	dbg_print("TBTT count %d \r\n", tbttCount);								
		 	NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
		 	dbg_print("ISAR %d \r\n", mcrValue);										 		
		 }
		 else 
		   NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
    	/*
        NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue); 
        if (mcrValue & ISAR_TBTT_INT) {
            tbttCount++;
            //printk("TBTT event occurs %d\n", tbttCount);
		*/
        if (tbttCount >= 10) break; /* 10sec */

    }

    /* Enable interrupt of abnormal interrupt */
    NIC_MCR_WRITE(NULL, MCR_IER, IER_GLOBAL_ENABLE | IER_SDIO_ABNORMAL_INT);
    NIC_MCR_READ(NULL, MCR_IER, &mcrValue);

#if 1
    /* Do illegal (byte/block) Read/Write to trigger abnormal interrupt */
    loopTestIndex = 30;
    while (loopTestIndex--) 
    {
			kal_uint8 test;
			
			dbg_print("start %d int test\r\n", test_count);										 		
        
			test = 0;

			test++;
        IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[0],8, KAL_FALSE);
        status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  
#ifndef MSDC2_SDIO_DVT
			if(MSDC_Reg(SDIO_STA) == 1)
#else
			if(MSDC_Reg(SDIO_STA2) == 1)
#endif
				test--;
        //NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
        //dbg_print("ISAR %d \r\n", mcrValue);										 		
			if(test)
				ASSERT(0);

			test++;
		  IPC_2126_MCR_Write_N(0x0128,(kal_uint32)&value[0],8, KAL_FALSE);
		  status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  
#ifndef MSDC2_SDIO_DVT
		  			if(MSDC_Reg(SDIO_STA) == 1)
#else
			if(MSDC_Reg(SDIO_STA2) == 1)
#endif
				test--;
        //NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
        //dbg_print("ISAR %d \r\n", mcrValue);										 		
			if(test)
				ASSERT(0);

			test++;
        IPC_2126_MCR_Write_N(0x0128,(kal_uint32)&value[0], 1, KAL_TRUE);
        status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  
#ifndef MSDC2_SDIO_DVT
			if(MSDC_Reg(SDIO_STA) == 1)
#else
			if(MSDC_Reg(SDIO_STA2) == 1)
#endif
				test--;
        NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
        //dbg_print("ISAR %d \r\n", mcrValue);										 		
			if(test)
				ASSERT(0);

        test++;
        IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[0], 1, KAL_TRUE);
        status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  
#ifndef MSDC2_SDIO_DVT
			if(MSDC_Reg(SDIO_STA) == 1)
#else
			if(MSDC_Reg(SDIO_STA2) == 1)
#endif
				test--;
        //NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
        //dbg_print("ISAR %d \r\n", mcrValue);										 		
			if(test)
				ASSERT(0);

 #if 0
 		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
      #if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
		#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
        if(my_flag_2)
        		break;
    }
#endif

    return 0;
} /* end of main() */

   
void SDIO_test_main2(void)
{
    UINT32      mcrValue;
    UINT32      tmcrValue;
    UINT32      i;
    UINT8       mcr[4];
    int         tbttCount;
    SDC_CMD_STATUS status;
    kal_uint32 j;
    
    
    /* Reset chip and enable all clocks */
    NIC_MCR_WRITE(NULL, MCR_SCR, (SCR_BB_MRST | SCR_MAC_RST |
                SCR_BB_SIORST | SCR_MAC_REGRST));
    for(j=0;j<100000;j++);                
    /* Here delay 1us to complete reset process */
    NIC_MCR_WRITE(NULL, MCR_SCR, SCR_CLK_ALL_EN);    
    /* Check chip ID */
    NIC_MCR_READ(NULL, MCR_PCICR, &mcrValue);
    IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[0], 4, KAL_TRUE);
   //SDIO_Register_Read(SDIO_FUCN_1, MCR_PCICR, (kal_uint32*)&tmcrValue, SDIO_FIX);
    //SDIO_Data_Read(SDIO_FUCN_1, MCR_PCICR, &mcr[0], SDIO_FIX, 4, KAL_FALSE);
    
    //printk("IPN2128 ChipIDVersion read test: [0x%08lX] \n", mcrValue);
    if ((mcrValue & CHIP_ID_MASK) != CHIP_ID_REV) {
        //printk(KERN_ALERT "IPN2128 not found... \n");
    }
    NIC_MCR_WRITE(NULL, MCR_SDCR, BITS(4,6)); /* Use enhanced mode */

    /* Reset TSF and enable TBTT interrupt */
    /* Set our local TSF timer to 0 */
    NIC_MCR_WRITE(NULL, MCR_TTAR1, 0);
    NIC_MCR_WRITE(NULL, MCR_TTAR2, 0);
    NIC_MCR_WRITE(NULL, MCR_TTAR0, TTAR0_TSF_TIMER_VALUE_CHANGE);

    /* Set the next TBTT time and the TBTT event generation period (20ms). */
    NIC_MCR_WRITE(NULL, MCR_NTTCR, ((100) &
        NTTCR_NEXT_TBTT_TIME) | (20 << 16));

    /* Enable the TBTT event generator. */
    NIC_MCR_WRITE(NULL, MCR_MPTCR, MPTCR_EN_COMP_NEXT_TBTT_TIME | MPTCR_TBTT_ENABLE);

    /* Enable interrupt */
    NIC_MCR_WRITE(NULL, MCR_IER, IER_GLOBAL_ENABLE | IER_TBTT_INT | IER_SDIO_ABNORMAL_INT);
 
#if 1
    /* In loop, cmd53 is repeated to test interrupt event with cmd53 read */
    tbttCount = 0;
    dbg_print("trigger interrupt during sigle block \r\n");
    while (1) 
    {
        kal_bool pending;
        //status=SDIO_check_IO_Int(SDIO_FUCN_1, &pending);  		 
        NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue);
        if (mcrValue & ISAR_TBTT_INT) 
        {
            kal_uint32 test_count;
            tbttCount++;
            dbg_print("TBTT event occurs %d\r\n", tbttCount);
            for(test_count=0;test_count<100;test_count++)
            {}
            if (tbttCount >= 100) break; /* 10sec */
        }       
    }
#endif

#if 1
    /* Read/Writel multiple block with TBTT interrupt */
    while (1) {
    	/*
        arg = BUILD_IO_RW_EXTENDED_ARG(SDIO_RWFLAG_WRITE,
            1, SDIO_IO_BLOCK_MODE, SDIO_IO_FIX_ADDR, 0x0128, 4);
        sdioCmd53ReadWrite(x_slot, arg, (__u8*)&value[0]);
		*/


      /*
        arg = BUILD_IO_RW_EXTENDED_ARG(SDIO_RWFLAG_READ,
            1, SDIO_IO_BLOCK_MODE, SDIO_IO_FIX_ADDR, 0x0128, 4);
        sdioCmd53ReadWrite(x_slot, arg, (__u8*)&value[0]);
		*/
		   dbg_print("trigger interrupt during multiple block \r\n");
			memset(value, 0, 1024);
		  IPC_2126_MCR_Write_N(0x0128,(kal_uint32)&value[0], 4, KAL_TRUE);
		  //memset(value, 0x5, 1024);
    		NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue); /* Clear TBTT Interrupt */
    		//IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[0], 128, KAL_FALSE);
    		//IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[128], 128, KAL_FALSE);
    		//IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[256], 128, KAL_FALSE);
    		//IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[384], 128, KAL_FALSE);
    		//memset(value, 0x5, 1024);
    		NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue); /* Clear TBTT Interrupt */
	     IPC_2126_MCR_Read_N(0x0128,(kal_uint32)&value[0], 4, KAL_TRUE);
	     NIC_MCR_READ(NULL, MCR_ISAR, &mcrValue); /* Clear TBTT Interrupt */
        NIC_MCR_READ(NULL, 0x118, &mcrValue);

        if(my_flag)
        		break;


    }
#endif

}
#endif


