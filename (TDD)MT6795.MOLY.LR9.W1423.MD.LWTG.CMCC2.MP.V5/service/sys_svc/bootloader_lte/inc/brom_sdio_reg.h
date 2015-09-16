#ifndef __HIF_SDIOREG_H__
#define __HIF_SDIOREG_H__

#include "brom_sdio_org_reg.h" 



#define SDIO_CTRL_HGFCR      ORG_SDIO_HGFCR       
#define SDIO_IRQ_HGFISR      ORG_SDIO_HGFISR        
#define SDIO_IRQ_HGFIER      ORG_SDIO_HGFIER        
                          
//#define SDIO_SP_HSDBDLSR      ORG_SDIO_HSDBDLSR   
#define SDIO_SP_HSDLSR       ORG_SDIO_HSDLSR
#define SDIO_SP_HCSDCR       ORG_SDIO_HCSDCR 
#define SDIO_SP_HDBGCR       ORG_SDIO_HDBGCR        
                          
#define SDIO_IRQ_FISR        ORG_SDIO_HWFISR        
#define SDIO_IRQ_FIER        ORG_SDIO_HWFIER        
#define SDIO_IRQ_UL_FRE0SR   ORG_SDIO_HWFTE0SR      
#define SDIO_IRQ_UL_FRE0ER   ORG_SDIO_HWFTE0ER                                 
#define SDIO_IRQ_DL_FTE0SR   ORG_SDIO_HWFRE0SR      
#define SDIO_IRQ_DL_FTE1SR   ORG_SDIO_HWFRE1SR      
#define SDIO_IRQ_DL_FTE0ER   ORG_SDIO_HWFRE0ER      
#define SDIO_IRQ_DL_FTE1ER   ORG_SDIO_HWFRE1ER      
                          
#define SDIO_IRQ_FICR        ORG_SDIO_HWFICR        
#define SDIO_CTRL_FCR        ORG_SDIO_HWFCR   

#define SDIO_QMU_UL_DCR       ORG_SDIO_HWTDCR    
#define SDIO_QMU_UL_PCCR      ORG_SDIO_HWTPCCR   

// TxQ0 is removed, use  TxQ1 in HW as TxQ0 in SW
//#define SDIO_QMU_ULQ0_SAR     ORG_SDIO_HWFTQ0SAR 
#define SDIO_QMU_ULQ0_SAR     ORG_SDIO_HWFTQ1SAR 
#define SDIO_QMU_ULQ1_SAR     ORG_SDIO_HWFTQ2SAR 
#define SDIO_QMU_ULQ2_SAR     ORG_SDIO_HWFTQ3SAR 
#define SDIO_QMU_ULQ3_SAR     ORG_SDIO_HWFTQ4SAR 
#define SDIO_QMU_ULQ4_SAR     ORG_SDIO_HWFTQ5SAR 
#define SDIO_QMU_ULQ5_SAR     ORG_SDIO_HWFTQ6SAR 
#define SDIO_QMU_ULQ6_SAR     ORG_SDIO_HWFTQ7SAR 
                                               
                                               
#define SDIO_QMU_DLQ0_SAR     ORG_SDIO_HWFRQ0SAR 
#define SDIO_QMU_DLQ1_SAR     ORG_SDIO_HWFRQ1SAR 
#define SDIO_QMU_DLQ2_SAR     ORG_SDIO_HWFRQ2SAR 
#define SDIO_QMU_DLQ3_SAR     ORG_SDIO_HWFRQ3SAR 

#define SDIO_MB_H2DRM0R      ORG_SDIO_H2DRM0R     
#define SDIO_MB_H2DRM1R      ORG_SDIO_H2DRM1R     
#define SDIO_MB_D2HSM0R      ORG_SDIO_D2HSM0R     
#define SDIO_MB_D2HSM1R      ORG_SDIO_D2HSM1R     
#define SDIO_MB_D2HSM2R      ORG_SDIO_D2HSM2R  

#define SDIO_QMU_DLQ0_CR      ORG_SDIO_HWRQ0CR 
#define SDIO_QMU_DLQ1_CR      ORG_SDIO_HWRQ1CR 
#define SDIO_QMU_DLQ2_CR      ORG_SDIO_HWRQ2CR 
#define SDIO_QMU_DLQ3_CR      ORG_SDIO_HWRQ3CR 
                                               
#define SDIO_QMU_DLP_LFACR    ORG_SDIO_HWRLFACR                                                        
#define SDIO_CTRL_DMACR      ORG_SDIO_HWDMACR 
#define SDIO_CTRL_FIOCDR     ORG_SDIO_HWFIOCDR
#define SDIO_CTRL_TOCR      ORG_SDIO_HSDIOTOCR					

#define SDIO_QMU_ULQ_CNTR0  ORG_SDIO_HWFTSR0
#define SDIO_QMU_ULQ_CNTR1  ORG_SDIO_HWFTSR1



/**
 *  @brief  Configuration value Definition
 */ 
/* Only use in SDIO_CTRL_HGFCR */
#define SDIO_DB_HIF_SEL          ORG_SDIO_DB_HIF_SEL    
#define SDIO_SPI_MODE            ORG_SDIO_SPI_MODE      
#define SDIO_EHPI_MODE           ORG_SDIO_EHPI_MODE   
#define SDIO_HINT_AS_FW_OB       ORG_SDIO_HINT_AS_FW_OB
#define SDIO_CARD_IS_18V         ORG_SDIO_CARD_IS_18V
#define SDIO_INT_TER_CYC_MASK    ORG_SDIO_INT_TER_CYC_MASK  
#define SDIO_HCLK_NO_GATED       ORG_SDIO_HCLK_NO_GATED   
#define SDIO_FORCE_SD_HS         ORG_SDIO_FORCE_SD_HS   
#define SDIO_SDIO_HCLK_DIS       ORG_SDIO_SDIO_HCLK_DIS 
#define SDIO_SPI_HCLK_DIS        ORG_SDIO_SPI_HCLK_DIS    
#define SDIO_EHPI_HCLK_DIS       ORG_SDIO_EHPI_HCLK_DIS 
#define SDIO_PB_HCLK_DIS         ORG_SDIO_PB_HCLK_DIS   
#define SDIO_PAD_CR_SET_BY_FW    ORG_SDIO_PAD_CR_SET_BY_FW   


/* Only use in SDIO_CTRL_FCR */
#define SDIO_W_FUNC_RDY          ORG_SDIO_W_FUNC_RDY      
#define SDIO_UDL_DESC_CHKSUM_EN  ORG_SDIO_TRX_DESC_CHKSUM_EN  
#define SDIO_UDL_DESC_CHKSUM_12  ORG_SDIO_TRX_DESC_CHKSUM_12 
#define SDIO_UL_CS_OFLD_EN       ORG_SDIO_TX_CS_OFLD_EN   
#define SDIO_DL_IPV6_CS_OFLD_EN  ORG_SDIO_RX_IPV6_CS_OFLD_EN  
#define SDIO_DL_IPV4_CS_OFLD_EN  ORG_SDIO_RX_IPV4_CS_OFLD_EN  
#define SDIO_DL_TCP_CS_OFLD_EN   ORG_SDIO_RX_TCP_CS_OFLD_EN 
#define SDIO_DL_UDP_CS_OFLD_EN   ORG_SDIO_RX_UDP_CS_OFLD_EN
#define SDIO_UL_NO_HEADER        ORG_SDIO_TX_NO_HEADER 
#define SDIO_DL_NO_TAIL          ORG_SDIO_RX_NO_TAIL
 

/* Only use in SDIO_CTRL_DMACR */
#define SDIO_AHB_1KBNDRY_PRTCT   ORG_SDIO_AHB_1KBNDRY_PRTCT 
#define SDIO_DEST_BST_TYP        ORG_SDIO_DEST_BST_TYP    
#define SDIO_DMA_BST_SIZE        ORG_SDIO_DMA_BST_SIZE    

/* Only use in SDIO_CTRL_FIOCDR */
    // TxQ0 is removed, use  TxQ1 in HW as TxQ0 in SW
#define SDIO_ULQ0_IOC_DIS        ORG_SDIO_TXQ1_IOC_DIS   
#define SDIO_ULQ_IOC_DIS(n)      ORG_SDIO_TXQ_IOC_DIS(n)
#define SDIO_DLQ0_IOC_DIS        ORG_SDIO_RXQ0_IOC_DIS   
#define SDIO_DLQ_IOC_DIS(n)      ORG_SDIO_RXQ_IOC_DIS(n) 

/* Only use in SDIO_CTRL_TOCR */
#define SDIO_TIMEOUT_NUM         ORG_SDIO_TIMEOUT_NUM
#define SDIO_RD_TIMEOUT_EN       ORG_SDIO_RD_TIMEOUT_EN


#define SDIO_WR_TIMEOUT_EN       ORG_SDIO_WR_TIMEOUT_EN

/* Only use in SDIO_CTRL_SPCR */
#define SDIO_CMD_SAMPLE          ORG_SDIO_CMD_SAMPLE
#define SDIO_DAT0_SAMPLE         ORG_SDIO_DAT0_SAMPLE
#define SDIO_DAT1_SAMPLE         ORG_SDIO_DAT1_SAMPLE
#define SDIO_DAT2_SAMPLE         ORG_SDIO_DAT2_SAMPLE
#define SDIO_DAT3_SAMPLE         ORG_SDIO_DAT3_SAMPLE



/**
 *  @brief  General Interrupt value Definition
 */ 
/* Only use in ORG_SDIO_HGFISR */
#define SDIO_DRV_CLR_DB_IOE    ORG_SDIO_DRV_CLR_DB_IOE   
#define SDIO_DRV_SET_DB_IOE    ORG_SDIO_DRV_SET_DB_IOE   
#define SDIO_SET_RES           ORG_SDIO_SET_RES      
#define SDIO_SET_ABT           ORG_SDIO_SET_ABT      
#define SDIO_DB_INT            ORG_SDIO_DB_INT       
#define SDIO_CRC_ERROR_INT     ORG_SDIO_CRC_ERROR_INT
#define SDIO_CHG_TO_18V_REQ	   ORG_SDIO_CHG_TO_18V_REQ


/* Only use in ORG_SDIO_HWFISR */
#define SDIO_DRV_SET_FW_OWN    ORG_SDIO_DRV_SET_FW_OWN   
#define SDIO_DRV_CLR_FW_OWN    ORG_SDIO_DRV_CLR_FW_OWN   
#define SDIO_D2HSM2R_RD        ORG_SDIO_D2HSM2R_RD     
#define SDIO_RD_TIMEOUT        ORG_SDIO_RD_TIMEOUT     
#define SDIO_WR_TIMEOUT        ORG_SDIO_WR_TIMEOUT     
#define SDIO_UL_EVENT_0        ORG_SDIO_TX_EVENT_0     
#define SDIO_DL_EVENT_0        ORG_SDIO_RX_EVENT_0     
#define SDIO_DL_EVENT_1        ORG_SDIO_RX_EVENT_1     
                                   
#define SDIO_H2D_SW_INT0       ORG_SDIO_H2D_SW_INT0    
#define SDIO_H2D_SW_INT(n)     ORG_SDIO_H2D_SW_INT(n)  




/**
 *  @brief  FW Set Interrupt to Host value Definition
 */
/* Only use in ORG_SDIO_HWFICR */
#define SDIO_FW_OWN_BACK_SET   ORG_SDIO_FW_OWN_BACK_SET  
#define SDIO_FW_OWN            ORG_SDIO_FW_OWN_READ  
#define SDIO_D2H_SW_INT0       ORG_SDIO_D2H_SW_INT0    
#define SDIO_D2H_SW_INT(n)     ORG_SDIO_D2H_SW_INT(n)    




/**
 *	@brief	Queue Related Interrupt value Definition
 */    
    // TxQ0 is removed, use  TxQ1 in HW as TxQ0 in SW
#define SDIO_ULQ0_RDY			 ORG_SDIO_TXQ1_RDY			
#define SDIO_ULP0_OVERFLOW		 ORG_SDIO_TXP1_OVERFLOW		
#define SDIO_ULQ0_CHKSUM_ERR	 ORG_SDIO_TXQ1_CHKSUM_ERR	
#define SDIO_ULQ0_LEN_ERR	     ORG_SDIO_TXQ1_LEN_ERR	
#define SDIO_ULQ_RDY(n)	         ORG_SDIO_TXQ_RDY(n)			
#define SDIO_ULP_OVERFLOW(n)	 ORG_SDIO_TXP_OVERFLOW(n)	
#define SDIO_ULQ_CHKSUM_ERR(n)   ORG_SDIO_TXQ_CHKSUM_ERR(n)
#define SDIO_ULQ_LEN_ERR(n)      ORG_SDIO_TXQ_LEN_ERR(n)


#define SDIO_DLQ0_DONE			 ORG_SDIO_RXQ0_DONE			
#define SDIO_DLP0_UNDERFLOW	     ORG_SDIO_RXP0_UNDERFLOW	
#define SDIO_DLQ0_CHKSUM_ERR     ORG_SDIO_RXQ0_CHKSUM_ERR
#define SDIO_DLP0_OVERFLOW	     ORG_SDIO_RXP0_OVERFLOW	
#define SDIO_DLQ0_OWN_CLEAR	     ORG_SDIO_RXQ0_OWN_CLEAR	
#define SDIO_DLQ0_LEN_ERR	     ORG_SDIO_RXQ0_LEN_ERR
#define SDIO_DLQ_DONE(n)		 ORG_SDIO_RXQ_DONE(n)		
#define SDIO_DLP_UNDERFLOW(n)	 ORG_SDIO_RXP_UNDERFLOW(n)	
#define SDIO_DLQ_CHKSUM_ERR(n)   ORG_SDIO_RXQ_CHKSUM_ERR(n)
#define SDIO_DLP_OVERFLOW(n)	 ORG_SDIO_RXP_OVERFLOW(n)	
#define SDIO_DLQ_OWN_CLEAR(n)	 ORG_SDIO_RXQ_OWN_CLEAR(n)	
#define SDIO_DLQ_LEN_ERR(n)	     ORG_SDIO_RXQ_LEN_ERR(n)	



/**
 *	@brief	Queue Related value Definition
 */ 

#define SDIO_QMU_ULQ_SAR_n(q_num)  ORG_SDIO_TQSAR_n(q_num)     
#define SDIO_QMU_DLQ_SAR_n(q_num)  ORG_SDIO_RQSAR_n(q_num)     
#define SDIO_QMU_DLQ_CR_n(q_num)   ORG_SDIO_RQCR_n(q_num)   
                                     
    // TxQ0 is removed, use  TxQ1 in HW as TxQ0 in SW
#define SDIO_QMU_ULQ0_STOP         ORG_SDIO_TXQ1_STOP
#define SDIO_QMU_ULQ0_START        ORG_SDIO_TXQ1_START   
#define SDIO_QMU_ULQ0_RESUME       ORG_SDIO_TXQ1_RESUME
#define SDIO_QMU_ULQ0_STATUS       ORG_SDIO_TXQ1_STATUS  
#define SDIO_QMU_ULQ_STOP(n)       ORG_SDIO_TXQ_STOP(n)  
#define SDIO_QMU_ULQ_START(n)      ORG_SDIO_TXQ_START(n) 
#define SDIO_QMU_ULQ_RESUME(n)     ORG_SDIO_TXQ_RESUME(n)
#define SDIO_QMU_ULQ_STATUS(n)     ORG_SDIO_TXQ_STATUS(n)
                                     
#define SDIO_QMU_ULQ_INC_CNT       ORG_SDIO_INC_TQ_CNT     
#define SDIO_QMU_ULQ_INDEX         ORG_SDIO_TQ_INDEX 
#define SDIO_QMU_ULQ_INDEX_OFFSET  ORG_SDIO_TQ_INDEX_OFFSET
#define SDIO_QMU_ULQ_CNT_RESET     ORG_SDIO_TQ_CNT_RESET 

                                
#define SDIO_QMU_DLQ_STOP          ORG_SDIO_RXQ_STOP   
#define SDIO_QMU_DLQ_START         ORG_SDIO_RXQ_START  
#define SDIO_QMU_DLQ_RESUME        ORG_SDIO_RXQ_RESUME 
#define SDIO_QMU_DLQ_STATUS        ORG_SDIO_RXQ_STATUS    


#define SDIO_QMU_DLP0_LEN_FIFO_AVAIL_CNT         ORG_SDIO_RX0_LEN_FIFO_AVAIL_CNT                               
#define SDIO_QMU_DLP_LEN_FIFO_AVAIL_CNT(n)       ORG_SDIO_RX_LEN_FIFO_AVAIL_CNT(n)    
#define SDIO_QMU_DLP_LEN_FIFO_AVAIL_CNT_OFFSET   ORG_SDIO_RX_LEN_FIFO_AVAIL_CNT_OFFSET   



#define SDIO_ULQ0_CNT_NOW       ORG_SDIO_TQ0_CNT_NOW
#define SDIO_ULQ1_CNT_NOW	    ORG_SDIO_TQ1_CNT_NOW
#define SDIO_ULQ2_CNT_NOW	    ORG_SDIO_TQ2_CNT_NOW
#define SDIO_ULQ3_CNT_NOW	    ORG_SDIO_TQ3_CNT_NOW
#define SDIO_ULQ4_CNT_NOW	    ORG_SDIO_TQ4_CNT_NOW
#define SDIO_ULQ5_CNT_NOW	    ORG_SDIO_TQ5_CNT_NOW
#define SDIO_ULQ6_CNT_NOW	    ORG_SDIO_TQ6_CNT_NOW
#define SDIO_ULQ7_CNT_NOW	    ORG_SDIO_TQ7_CNT_NOW

#define SDIO_ULQ_CNT_NOW_n(q_num)   ORG_SDIO_TQ_CNT_NOW_n(q_num)

#endif





