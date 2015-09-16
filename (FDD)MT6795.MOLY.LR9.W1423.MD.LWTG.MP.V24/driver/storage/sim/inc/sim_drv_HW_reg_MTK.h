#ifndef __SIM_DRV_HW_REG_MTK_H__
#define __SIM_DRV_HW_REG_MTK_H__

//#if ( (!defined(MT6208)) && (!defined(FPGA)) && (!defined(MT6205)) && (!defined(MT6205B)) && (!defined(MT6218)) )
#if !defined(DRV_SIM_REG_6208_SERIES) && !defined(DRV_SIM_REG_6205B_SERIES)
/*MT6218B || MT6219 || MT6217 || MT6226 || MT6227 || MT6228 || MT6229*/
	#ifdef SIM_NAMING_FROM_0_ADDRESS

	#ifdef SIM_base
  #undef SIM_base
	#endif
  #define SIM_base SIM0_base

	#ifdef SIM2_base
  #undef SIM2_base
	#endif
  #define SIM2_base SIM1_base

	#endif //SIM_NAMING_FROM_0_ADDRESS


   #define 	ACK_NULL_CHAR		0x60
   
   #define 	SIM_CTRL		   (SIM_base+0x0)
   #define 	SIM_CONF		   (SIM_base+0x4)
   #define 	SIM_BRR			(SIM_base+0x8)
   #define 	SIM_IRQEN		(SIM_base+0x10)
   #define 	SIM_STS			(SIM_base+0x14)
   
   #define 	SIM_RETRY		(SIM_base+0x20)
   #define 	SIM_TIDE	   	(SIM_base+0x24)
  
   #define 	SIM_DATA		   (SIM_base+0x30)
   #define 	SIM_COUNT		(SIM_base+0x34)
   
   #define 	SIM_ATIME		(SIM_base+0x40)
   #define 	SIM_DTIME		(SIM_base+0x44)
   #define 	SIM_TOUT		   (SIM_base+0x48)
   
   #define 	SIM_INS  		(SIM_base+0x60)
   #define 	SIM_IMP3  		(SIM_base+0x64)
   #define 	SIM_SW1  		(SIM_base+0x68)
   #define 	SIM_SW2  		(SIM_base+0x6c)
   #define 	SIM_REG_STATUS		(SIM_base+0x74)


   /*
   	This is the most important define to combine single SIM and multiple SIM macro.
   	In DRV_SIM_ALL_SOLUTION_BUILT, single SIM driver's macro will use this variable, too.
   	DRV_SIM_BUILD_SINGLE_SIM is only defined in simd.c and usim_drv.c before including this header file.
   */
extern kal_uint32 simBaseAddr, simBaseAddrSpace;
#ifdef DRV_SIM_BUILD_SINGLE_SIM
#define	SIM0_BASE_ADDR_MTK	(simBaseAddr )
#else
   /*in DRV_SIM_ALL_SOLUTION_BUILT, we use two variables, starting address and adress space, to calculate the actual address*/
   //#define	SIM0_BASE_ADDR_MTK	(simBaseAddr + (simBaseAddrSpace * simInterface))
   #define	SIM0_BASE_ADDR_MTK	(hw_cb->mtk_baseAddr)
#endif

   
   #define 	SIM_CTRL_MTK		   	0x0
   #define 	SIM_CONF_MTK		   	0x4
   #define 	SIM_BRR_MTK			0x8
   #define 	SIM_IRQEN_MTK			0x10
   #define 	SIM_STS_MTK			0x14
   #define       SIM_CLR_STA                    0x18
   
   #define 	SIM_RETRY_MTK			0x20
   #define 	SIM_TIDE_MTK	   		0x24
  
   #define 	SIM_DATA_MTK		   	0x30
   #define 	SIM_COUNT_MTK			0x34
   
   #define 	SIM_ATIME_MTK			0x40
   #define 	SIM_DTIME_MTK			0x44
   #define 	SIM_TOUT_MTK		   	0x48
   #define 	SIM_EXT_TIME_MTK		0x54
   #define 	SIM_INS_MTK  			0x60
   #define 	SIM_IMP3_MTK  			0x64
   #define 	SIM_SW1_MTK  			0x68
   #define 	SIM_SW2_MTK  			0x6c
   #define 	SIM_STATUS_MTK		0x74

   

   //SIM_CTRL
   #define 	SIM_CTRL_SIMON		   0x0001
   #define 	SIM_CTRL_HALT		   0x0002   /* Enable Clk stop mode or disable */
   #define	SIM_CTRL_WRST			0x0004	/* Trigger a warm reset */
   #define	SIM_CTRL_SWRST			0x0080	/* Enable SWRST for SIMIF */   
   
   //SIM_CONF
   #define 	SIM_CONF_RXHSK		   0x0001
   #define 	SIM_CONF_TXHSK		   0x0002
   #define 	SIM_CONF_CLKPO		   0x0004
   #define 	SIM_CONF_SINV		   0x0008
   #define 	SIM_CONF_SDIR		   0x0010
   #define 	SIM_CONF_ODDPARITY	0x0020
   #define 	SIM_CONF_SIMSEL		0x0040
   #define 	SIM_CONF_TOUTEN		0x0080
   #define 	SIM_CONF_T0EN		   0x0200
   #define 	SIM_CONF_HFEN		   0x0400
   #define 	SIM_CONF_T1EN		   0x0100
   #define 	SIM_CONF_RSTCTL		0x8000   

   #define 	SIM_CONF_RXDISABLE	0x0800
   #define 	SIM_CONF_TXDISABLE	0x1000   
   #define  SIM_CONF_Direct		0x0000
   #define  SIM_CONF_InDirect	   0x0038
   
   //SIM_BRR
   #define 	SIM_BRR_CLKMSK		      0x0003
   #define 	SIM_BRR_CLK_Div2	      0x0000
   #define 	SIM_BRR_CLK_Div4	      0x0001
   #define 	SIM_BRR_CLK_Div8	      0x0002
   #define 	SIM_BRR_CLK_Div12	      0x0003
   
   #define 	SIM_BRR_ETUMSK		      0x07FC
   #define 	SIM_BRR_BAUDMSK			0x000C
//#if ( (defined(MT6218B)) || (defined(MT6219)))
#if defined(DRV_SIM_REG_BAUD_6218B_SERIES)
   #define 	SIM_BRR_BAUD_Div372		(0x16<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(0x03<<2)		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(0x01<<2)		//F=512, D=16
#else /*!Mt6218B,MT6219*/
   #define 	SIM_BRR_BAUD_Div372		(372<<2)		//F=372, D=1
   #define 	SIM_BRR_BAUD_Div64		(64<<2)		//F=512, D=8
   #define 	SIM_BRR_BAUD_Div32		(32<<2)		//F=512, D=16
   #define	SIM_BRR_BAUD_Div16		(16<<2)		//F=512,D=32
   #define	SIM_BRR_BAUD_Div8		(8<<2)		//F=512,D=64
#endif   /*MT6218B,MT6219*/

   //SIM_IRQEN
   #define 	SIM_IRQEN_TX		      0x0001
   #define 	SIM_IRQEN_RX		      0x0002
   #define 	SIM_IRQEN_OV		      0x0004
   #define 	SIM_IRQEN_TOUT		      0x0008
   #define 	SIM_IRQEN_TXERR		   0x0010
   #define 	SIM_IRQEN_NATR		      0x0020
   #define 	SIM_IRQEN_SIMOFF        0x0040
   #define 	SIM_IRQEN_T0END         0x0080
   #define 	SIM_IRQEN_RXERR         0x0100
#if defined(__SIM_DRV_ENABLE_SWRST__)
   #define	SIM_IRQEN_SWRST 			0x1000
   #define	SIM_IRQEN_ALL				(0x01bf|SIM_IRQEN_SWRST)
   #define	SIM_IRQEN_ALLOFF			0x0000
   /* SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT,SIM_IRQEN_OV,SIM_IRQEN_RX*/
   #define	SIM_IRQEN_Normal			(0x013e|SIM_IRQEN_SWRST)
   /*SIM_IRQEN_T0END,SIM_IRQEN_TXErr,SIM_IRQEN_TOUT*/		
   #define	SIM_IRQEN_CMDNormal		(0x019e|SIM_IRQEN_SWRST)
   /*#define 	SIM_IRQEN_CMDNormal	   0x019c*/
   #define	SIM_IRQEN_CMDDMANormal		(0x019c|SIM_IRQEN_SWRST)
   #define	USIM_IRQEN_ATR 			(SIM_IRQEN_RX|SIM_IRQEN_NATR|SIM_IRQEN_SWRST)
   #define	USIM_IRQEN_NORMAL 		(SIM_STS_RX|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_TXERR|SIM_STS_RXERR|SIM_IRQEN_SWRST)
   
#else   
   #define 	SIM_IRQEN_ALL		      0x01bf
   #define 	SIM_IRQEN_ALLOFF	      0x0000
   /* SIM_IRQEN_TXErr, SIM_IRQEN_NATR, SIM_IRQEN_TOUT,SIM_IRQEN_OV,SIM_IRQEN_RX*/
   #define 	SIM_IRQEN_Normal	      0x013e
   /*SIM_IRQEN_T0END,SIM_IRQEN_TXErr,SIM_IRQEN_TOUT*/		
   #define 	SIM_IRQEN_CMDNormal	   0x019e
   /*#define 	SIM_IRQEN_CMDNormal	   0x019c*/
   #define 	SIM_IRQEN_CMDDMANormal	   0x019c
   #define	USIM_IRQEN_ATR				(SIM_IRQEN_RX|SIM_IRQEN_NATR)
   #define 	USIM_IRQEN_NORMAL			(SIM_STS_RX|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_TXERR|SIM_STS_RXERR)
 
#endif /* End of #if defined(__SIM_DRV_ENABLE_SWRST__)*/
   #define 	USIM_IRQEN_CMD_T1			(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_RXERR| \
   											SIM_STS_OV|SIM_STS_TOUT)
   #define 	USIM_IRQEN_CMD_T1_RX		(SIM_STS_EDCERR|SIM_STS_T1END|SIM_STS_OV|SIM_STS_TOUT|SIM_STS_RX)   
   #define 	USIM_IRQEN_CMD_T1_TX		(SIM_STS_T1END)
   
   //SIM_STS
   #define 	SIM_STS_TX		         0x0001
   #define 	SIM_STS_RX		         0x0002
   #define 	SIM_STS_OV		         0x0004
   #define 	SIM_STS_TOUT		      0x0008
   #define 	SIM_STS_TXERR		      0x0010
   #define 	SIM_STS_NATR		      0x0020
   #define 	SIM_STS_SIMOFF		      0x0040
   #define 	SIM_STS_T0END           0x0080
   #define 	SIM_STS_RXERR           0x0100
   #define 	SIM_STS_T1END				0x0200
   #define	SIM_STS_EDCERR				0x0400
#if defined(__SIM_DRV_ENABLE_SWRST__)
   #define	SIM_STS_SWRST 			   0x1000
#endif /* End of #if defined(__SIM_DRV_ENABLE_SWRST__)*/   
   //SIM_TOUT
   #define 	SIM_TOUT_MSK		      0x3fff
   
   //SIM_RETRY
   #define 	SIM_RETRY_RXMASK	      0x0007
   #define 	SIM_RETRY_TXMASK	      0x0700
   
   //SIM_TIDE
   #define 	SIM_TIDE_RXMASK		   0x000f
   #define 	SIM_TIDE_TXMASK		   0x0f00
   
   //SIM_COUNT
   #define 	SIM_COUNT_MASK		      0x000f
   
   //SIM_INS
   #define 	SIM_INS_MASK  		      0x00ff
   #define 	SIM_INS_INSD  		      0x0100
   
   //SIM_IMP3
   #define  SIM_IMP3_MASK           0x01ff

   // SIM_STATUS
   #define	SIM_STATUS_EDC				0x40
   #define	SIM_STATUS_ACK				0x20
   #define 	SIM_STATUS_NACK			0x10
   #define	SIM_STATUS_IDLE			0x01
   #define	SIM_STATUS_INS				0x02
   #define	SIM_STATUS_SW1				0x04
   #define	SIM_STATUS_SW2				0x08

   #define SIM_TX_DELAY_LEN			0x4
   #define SIM_TX_DELAY_LOOP			4000
#endif   /*MT6218B*/

#if defined (DRV_SIM_6575_SERIES)
#define SIM1_PMIC_GPIO_RST_DIR_OFFSET              0x0010
#define SIM2_PMIC_GPIO_RST_DIR_OFFSET              0x0018
#define SIM1_PMIC_GPIO_RST_MODE_OFFSET              0x0108
#define SIM2_PMIC_GPIO_RST_MODE_OFFSET              SIM1_PMIC_GPIO_RST_MODE_OFFSET
#define SIM1_PMIC_GPIO_RST_DOUT_OFFSET             0x0090
#define SIM2_PMIC_GPIO_RST_DOUT_OFFSET             0x0098
#define SIM1_PMIC_GPIO_RST_AP_MODE_OFFSET           0x0100
#define SIM2_PMIC_GPIO_RST_AP_MODE_OFFSET           SIM1_PMIC_GPIO_RST_AP_MODE_OFFSET


#define SIM_PMIC_GPIO_SET_OFFSET 0X0002
#define SIM_PMIC_GPIO_CLR_OFFSET 0X0004

#define SIM1_PMIC_GPIO_DIR 14
#define SIM2_PMIC_GPIO_DIR 0
#define SIM1_PMIC_GPIO_MODE 3
#define SIM2_PMIC_GPIO_MODE 9
#define SIM1_PMIC_GPIO_DOUT 14
#define SIM2_PMIC_GPIO_DOUT 0
#define SIM1_PMIC_GPIO_AP_MODE 6
#define SIM2_PMIC_GPIO_AP_MODE 12

#endif
#if defined (DRV_SIM_6572_SERIES)
#define SIM1_PMIC_GPIO_RST_DIR_OFFSET              0x0000
#define SIM2_PMIC_GPIO_RST_DIR_OFFSET              0x0008
#define SIM1_PMIC_GPIO_RST_MODE_OFFSET              0x00D8
#define SIM2_PMIC_GPIO_RST_MODE_OFFSET              SIM1_PMIC_GPIO_RST_MODE_OFFSET
#define SIM1_PMIC_GPIO_RST_DOUT_OFFSET             0x0080
#define SIM2_PMIC_GPIO_RST_DOUT_OFFSET             0x0088
#define SIM1_PMIC_GPIO_RST_AP_MODE_OFFSET           0x00D0
#define SIM2_PMIC_GPIO_RST_AP_MODE_OFFSET           SIM1_PMIC_GPIO_RST_AP_MODE_OFFSET


#define SIM_PMIC_GPIO_SET_OFFSET 0X0002
#define SIM_PMIC_GPIO_CLR_OFFSET 0X0004

#define SIM1_PMIC_GPIO_DIR 15
#define SIM2_PMIC_GPIO_DIR 1
#define SIM1_PMIC_GPIO_MODE 0
#define SIM2_PMIC_GPIO_MODE_CLK 3
#define SIM2_PMIC_GPIO_MODE 6
#define SIM1_PMIC_GPIO_DOUT 15
#define SIM2_PMIC_GPIO_DOUT 1
#define SIM1_PMIC_GPIO_AP_MODE 3
#define SIM2_PMIC_GPIO_AP_MODE 9

#endif

#if (defined(MT6752) && defined(__MD2__))
   #define	SIM_ATR_STA_AL   0x200
   #define	SIM_ATR_STA_IR   0x100
#elif defined(DRV_SIM_6572_SERIES)
   #define	SIM_ATR_STA_AL   0x200
   #define	SIM_ATR_STA_IR   0x100
//#elif defined(DRV_SIM_6575_SERIES)
//   #define	SIM_ATR_STA_AL   0x100
//   #define	SIM_ATR_STA_IR   0x80
#else   
   #define	SIM_ATR_STA_AL   0x200
   #define	SIM_ATR_STA_IR   0x100
#endif

#endif /*__SIM_DRV_HW_REG_MTK_H__*/
