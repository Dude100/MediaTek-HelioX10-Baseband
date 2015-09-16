#ifndef __PCM_REG_H__
#define __PCM_REG_H__

#include <reg_base.h>
#include <intrCtrl.h>


/* Register Address Definition */
#define PCMON_BASE          (BASE_ADDR_MDPCMON)
//#define PCM_CODA_VERSION    (MDPCM_BASE)

#define PCMON_CTRL_0    			(PCMON_BASE + 0x0U)
	#define PCMON_ETM_ENABLE   		(1U<<20)
	#define PCMON_MOD1		   		(0U<<0)
	#define PCMON_MOD2		   		(1U<<0)
	#define PCMON_MOD3		   		(2U<<0)
	#define PCMON_SRSEL_10     		(0U<<4)
	#define PCMON_SRSEL_12     		(1U<<4)
	#define PCMON_SRSEL_16     		(2U<<4)
	#define PCMON_SRSEL_18     		(3U<<4)
	#define PCMON_SRSEL_19     		(4U<<4)
	#define PCMON_SRSEL_22     		(5U<<4)
	#define PCMON_SRSEL_24     		(6U<<4)
	#define PCMON_SRSEL_26     		(7U<<4)
	//Sanple rate selection is MCUCLK/(2^N)
	#define PCMON_DIFF(n)      		(n<<8)
	//PC difference n is 2*(1~128)
	#define PCMON_N_PAIR(n)    		(((n) - 1) << 16)
#define PCMON_CTRL_1    			(PCMON_BASE + 0x4U)
	#define PCMON_BUS_MON_STOP	    (1U<<31)
	#define PCMON_BUS_STOP_RESTART  (1U<<0)
/* n = 0~31 */
#define PCMON_PC_(n)      			(PCMON_BASE + ((n))*0x8U + 0x10U)
#define PCMON_CID_(n)     			(PCMON_BASE + ((n))*0x8U + 0x14U)

#define PCMON_INTR_ID          		(MD_IRQID_PCMON)
#define PCMON_HDMA_INTR_ID			(MD_IRQID_MDGDMA3)

#define MDGDMA_BASE          		(BASE_ADDR_MDGDMA)

#define GDMA_HDCSR4					(MDGDMA_BASE + 0x110U)
	#define HDMA_CS16B_EN_8x 		(1U<<15)
	#define HDMA_CS_EN_8x	 		(1U<<8)

#define GDMA_HDSR	    			(MDGDMA_BASE + 0x120U)
	#define HDMA_STAT1_8x    		(1U<<24)   //HDMA ch8 buffer0 status. 0:inactive 1:active
	#define HDMA_STAT0_8x    		(1U<<8)	   //HDMA ch8 buffer1 status. 0:inactive 1:active

#define GDMA_HDCPR					(MDGDMA_BASE + 0x124U)
	#define HDMA_HCURR_PTRR_8x 		(1U<<8)    //HDMA Ch8 current pointer. 0:buffer0 1:buffer1

#define GDMA_HDCTRR8				(MDGDMA_BASE + 0x240U)
	#define HDMA_RX_SEL1_8x   		(1U<<31)   //Buffer1 RX mode. 0:Tx mode 1:Rx mode default is Rx
	#define HDMA_RX_SEL0_8x   		(1U<<30)   //Buffer0 RX mode. 0:Tx mode 1:Rx mode default is Rx
	#define HBST_SIZE_8x_4B  		(2U<<13)   //HDMA Ch8 Burst size is 4 transfer bytes
	#define HBST_SIZE_8x_8B   		(3U<<13)   //HDMA Ch8 Burst size is 8 transfer bytes
	#define HBST_SIZE_8x_16B  		(4U<<13)   //HDMA Ch8 Burst size is 16 transfer bytes
	#define HDEV_BUS_WIDTH_8x_1B 	(0U<<6)    //HDMA Ch8 Device Bus Width is 1 bytes
	#define HDEV_BUS_WIDTH_8x_2B 	(1U<<6)    //HDMA Ch8 Device Bus Width is 2 bytes
	#define HDEV_BUS_WIDTH_8x_4B 	(2U<<6)    //HDMA Ch8 Device Bus Width is 4 bytes
	#define HDMEM_BUS_WIDTH_8x_1B	(0U<<4)	   //HDMA Ch8 Memory Bus Width is 1 bytes
	#define HDMEM_BUS_WIDTH_8x_2B	(1U<<4)	   //HDMA Ch8 Memory Bus Width is 2 bytes
	#define HDMEM_BUS_WIDTH_8x_4B	(2U<<4)	   //HDMA Ch8 Memory Bus Width is 4 bytes
	#define HDMA_STOP_8x			(1U<<2)	   //STOP HDMA Ch8

#define GDMA_HDC0R8					(MDGDMA_BASE + 0x244U) //This register is used to control buffer0
	#define HDMA_RESUME0_8x		 	(1U<<1)
	#define GDMA_HDMA_START_8x 		(1U)

#define GDMA_HDC1R8					(MDGDMA_BASE + 0x248U) //This register is used to control buffer1
	#define HDMA_RESUME1_8x		  	(1U<<1)
	#define GDMA_HDMA_START1_8X 	(1U)

#define GDMA_HPRGA0R8				(MDGDMA_BASE + 0x24CU) //This register is used to set address of buffer0

#define GDMA_HPRGA1R8				(MDGDMA_BASE + 0x250U) //This register is used to set address of buffer1

#define GDMA_HDCCR8					(MDGDMA_BASE + 0x254U)

#define GDMA_HDCPR8					(MDGDMA_BASE + 0x258U)

#define GDMA_GISAR4					(MDGDMA_BASE + 0x610U) 
	#define HDMA_DONE_8x			(1U<<0)

#define GDMA_GIMRK4					(MDGDMA_BASE + 0x630U)
	#define HDMA_DONE3_INTM			(0x1 << 0)
	


#endif /* end of __PCM_REG_H__ */
