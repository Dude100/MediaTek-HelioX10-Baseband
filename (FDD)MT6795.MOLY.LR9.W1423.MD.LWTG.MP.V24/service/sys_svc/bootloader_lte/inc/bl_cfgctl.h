/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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

/*******************************************************************************
 * Filename:
 * ---------
 *   bl_cfgclt.h
 *
 * Project:
 * --------
 *   Bootloader
 *
 * Description:
 * ------------
 *   MDCFGCTL header file
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * .
 ****************************************************************************/

#ifndef _BL_CFGCTL_H
#define _BL_CFGCTL_H

#include <reg_base.h>

#define BASE_CFGCTL             BASE_ADDR_MDCFGCTL

//Register offset
#define REG_MISC_OWN                (BASE_CFGCTL+0x28)
#define REG_AXI_OWN                  (BASE_CFGCTL+0x2C)
#define REG_APAHB_OWN             (BASE_CFGCTL+0x30)
#define REG_APPERIAPB_OWN      (BASE_CFGCTL+0x34)
#define REG_MDAHB_OWN             (BASE_CFGCTL+0x38)
#define REG_MDPERIAPB_OWN     (BASE_CFGCTL+0x3C)
#define REG_CFGAPB_OWN            (BASE_CFGCTL+0x40)
#define REG_SW_MISC                   (BASE_CFGCTL + 0x50)

//====================OWN BIT==========================

//MISC OWN
#define SPI_OWN                         (0x1<<0)
#define AUXADC_OWN                 (0x1<<1)

//AXI OWN
#define MODEM_3G_0                  (0x1<<0)
#define MODEM_3G_1                  (0x1<<1)
#define MODEM_2G_0                  (0x1<<2)
#define MODEM_2G_1                  (0x1<<3)
#define MODEM_TDD                    (0x1<<5)
#define LTE_PHY                          (0x1<<6)
#define LTE_MAC                          (0x1<<7)
#define AP_DEBUG_APB               (0x1<<8)
#define MD_DEBUG_APB               (0x1<<9)
#define MD_CACHE_DEBUG           (0x1<<12)
#define APAHB                              (0x1<<14)   //useless
#define MDAHB                              (0x1<<15)  //useless

//APAHB OWN
#define APPERI_APB                     (0x1<<2)  //useless
#define EHPI_SLAVE                     (0x1<<3)  //useless
#define APMCU_APB                     (0x1<<4)  //useless
#define USB30_MAC                      (0x1<<6)
#define USB30_PHY                      (0x1<<7)
#define SPI_REG                           (0x1<<9)
#define USB20_MAC                      (0x1<<10)
#define USB20_PHY                      (0x1<<11)
#define MSDC_0                            (0x1<<12)
#define MSDC_1                            (0x1<<13)
#define AP_VPORT                        (0x1<<14)

//APPERIAPB OWN
#define EHPI_HOST                      (0x1<<0)   //HIF 0
#define APNFI                              (0x1<<3)
#define MDNFI                              (0x1<<4)
#define NLI_ARB                          (0x1<<5)
#define IPSEC                               (0x1<<6)
#define NIC                                  (0x1<<7)
#define TZCCIF                            (0x1<<8)
#define APCCIF                            (0x1<<9)
#define MDCCIF                            (0x1<<10)
#define AP_CLDMA                       (0x1<<11)
#define MD_CLDMA                       (0x1<<12)
#define PFC                                  (0x1<<13)
#define AP_RSTCTL                      (0x1<<14)
#define APPERI_MBIST                 (0x1<<15)

//MDAHB OWN
#define MD_TCM                            (0x1<<0)
#define MDPERI_APB                     (0x1<<2)  //useless
#define MDINFRA_APB                  (0x1<<3) 
#define MDMCU_APB                     (0x1<<4) 
#define MDCFG_APB                      (0x1<<8) //useless
#define MEM_APB                          (0x1<<9)
#define SDIO                                 (0x1<<12)
#define MD_VPORT                        (0x1<<14)
#define BOOTROM                          (0x1<<15)

//MDPERIAPB OWN
#define MDPERI_MISC                  (0x1<<0)
#define MDPERI_DBGMON            (0x1<<1)
#define USIM_0                            (0x1<<2)
#define USIM_1                            (0x1<<3)
#define MDUART                           (0x1<<4)
#define SHARED_UART0               (0x1<<5)
#define SHARED_UART1               (0x1<<6)
#define SDIO_CISCC                     (0x1<<7)
#define AP_LED                            (0x1<<8)
#define MD_LED                            (0x1<<9)
#define MD_GPTM                         (0x1<<10)
#define I2C                                   (0x1<<11)
#define MD_GDMA                        (0x1<<12)
#define MD_CIRQ                          (0x1<<13)
#define RTC                                   (0x1<<14)
#define MDPERI_MBIST                (0x1<<15)

//CFGAPB OWN
#define MD_CFGCTL                     (0x1<<0)
#define MD_CLKCTL                      (0x1<<1)
#define MD_RSTCTL                      (0x1<<2)
#define MD_TOPSM                       (0x1<<3)
#define MD_OST                           (0x1<<4)
#define DBGSYS                            (0x1<<5)
#define MD_DBG_MONITOR          (0x1<<6)
#define MDGPIO_EINT                  (0x1<<7)
#define AP_CFGCTL                      (0x1<<8)
#define AP_CLKCTL                       (0x1<<9)
#define TOP_MISC                        (0x1<<10)
#define AP_TOPSM                       (0x1<<11)
#define AP_OST                            (0x1<<12)
#define PLL_CTL                           (0x1<<13)
#define EFUSE                              (0x1<<14)
#define APGPIO_EINT                  (0x1<<15)

//=====================OWN MASK======================

//MISC OWN
#define SPI_OWN_MASK                      (SPI_OWN | (SPI_OWN << 16))               
#define AUXADC_OWN_MASK              (AUXADC_OWN | (AUXADC_OWN << 16))

//AXI OWN
#define MODEM_3G_0_MASK                (MODEM_3G_0 | (MODEM_3G_0 << 16))                             (0x1<<0)
#define MODEM_3G_1_MASK                (MODEM_3G_1 | (MODEM_3G_1 << 16))           
#define MODEM_2G_0_MASK                (MODEM_2G_0 | (MODEM_2G_0 << 16))           
#define MODEM_2G_1_MASK                (MODEM_2G_1 | (MODEM_2G_1 << 16))           
#define MODEM_TDD_MASK                  (MODEM_TDD | (MODEM_TDD << 16))           
#define LTE_PHY_MASK                        (LTE_PHY | (LTE_PHY << 16))           
#define LTE_MAC_MASK                       (LTE_MAC | (LTE_MAC << 16))           
#define AP_DEBUG_APB_MASK            (AP_DEBUG_APB | (AP_DEBUG_APB << 16))           
#define MD_DEBUG_APB_MASK            (MD_DEBUG_APB | (MD_DEBUG_APB << 16))           
#define MD_CACHE_DEBUG_MASK        (MD_CACHE_DEBUG | (MD_CACHE_DEBUG << 16))           
#define APAHB_MASK                           (APAHB | (APAHB << 16))           
#define MDAHB_MASK                          (MDAHB | (MDAHB << 16))           

//APAHB OWN
#define APPERI_APB_MASK                  (APPERI_APB | (APPERI_APB << 16))               
#define EHPI_SLAVE_MASK                  (EHPI_SLAVE | (EHPI_SLAVE << 16))               
#define APMCU_APB_MASK                   (APMCU_APB | (APMCU_APB << 16))               
#define USB30_MAC_MASK                   (USB30_MAC | (USB30_MAC << 16))               
#define USB30_PHY_MASK                    (USB30_PHY | (USB30_PHY << 16))               
#define SPI_REG_MASK                         (SPI_REG | (SPI_REG << 16))               
#define USB20_MAC_MASK                   (USB20_MAC | (USB20_MAC << 16))               
#define USB20_PHY_MASK                   (USB20_PHY | (USB20_PHY << 16))               
#define MSDC_0_MASK                         (MSDC_0 | (MSDC_0 << 16))               
#define MSDC_1_MASK                         (MSDC_1 | (MSDC_1 << 16))               
#define AP_VPORT_MASK                     (AP_VPORT | (AP_VPORT << 16))               

//APPERIAPB OWN
#define EHPI_HOST_MASK                   (EHPI_HOST | (EHPI_HOST << 16))      
#define APNFI_MASK                           (APNFI | (APNFI << 16))      
#define MDNFI_MASK                           (MDNFI | (MDNFI << 16))      
#define NLI_ARB_MASK                       (NLI_ARB | (NLI_ARB << 16))      
#define IPSEC_MASK                           (IPSEC | (IPSEC << 16))      
#define NIC_MASK                               (NIC | (NIC << 16))      
#define TZCCIF_MASK                          (TZCCIF | (TZCCIF << 16))      
#define APCCIF_MASK                         (APCCIF | (APCCIF << 16))      
#define MDCCIF_MASK                         (MDCCIF | (MDCCIF << 16))      
#define AP_CLDMA_MASK                    (AP_CLDMA | (AP_CLDMA << 16))      
#define MD_CLDMA_MASK                    (MD_CLDMA | (MD_CLDMA << 16))      
#define PFC_MASK                               (PFC | (PFC << 16))      
#define AP_RSTCTL_MASK                   (AP_RSTCTL | (AP_RSTCTL << 16))      
#define APPERI_MBIST_MASK              (APPERI_MBIST | (APPERI_MBIST << 16))      

//MDAHB OWN
#define MD_TCM_MASK                        (MD_TCM | (MD_TCM << 16))               
#define MDPERI_APB_MASK                 (MDPERI_APB | (MDPERI_APB << 16))               
#define MDINFRA_APB_MASK              (MDINFRA_APB | (MDINFRA_APB << 16))               
#define MDMCU_APB_MASK                  (MDMCU_APB | (MDMCU_APB << 16))               
#define MDCFG_APB_MASK                  (MDCFG_APB | (MDCFG_APB << 16))               
#define MEM_APB_MASK                      (MEM_APB | (MEM_APB << 16))               
#define SDIO_MASK                             (SDIO | (SDIO << 16))               
#define MD_VPORT_MASK                    (MD_VPORT | (MD_VPORT << 16))               
#define BOOTROM_MASK                      (BOOTROM | (BOOTROM << 16))               

//MDPERIAPB OWN
#define MDPERI_MISC_MASK              (MDPERI_MISC | (MDPERI_MISC << 16))
#define MDPERI_DBGMON_MASK         (MDPERI_DBGMON | (MDPERI_DBGMON << 16))
#define USIM_0_MASK                        (USIM_0 | (USIM_0 << 16))
#define USIM_1_MASK                        (USIM_1 | (USIM_1 << 16))
#define MDUART_MASK                       (MDUART | (MDUART << 16))
#define SHARED_UART0_MASK           (SHARED_UART0 | (SHARED_UART0 << 16))
#define SHARED_UART1_MASK           (SHARED_UART1 | (SHARED_UART1 << 16))
#define SDIO_CISCC_MASK                 (SDIO_CISCC | (SDIO_CISCC << 16))
#define AP_LED_MASK                        (AP_LED | (AP_LED << 16))
#define MD_LED_MASK                        (MD_LED | (MD_LED << 16))
#define MD_GPTM_MASK                     (MD_GPTM | (MD_GPTM << 16))
#define I2C_MASK                               (I2C | (I2C << 16))
#define MD_GDMA_MASK                     (MD_GDMA | (MD_GDMA << 16))
#define MD_CIRQ_MASK                      (MD_CIRQ | (MD_CIRQ << 16))
#define RTC_MASK                              (RTC | (RTC << 16))
#define MDPERI_MBIST_MASK            (MDPERI_MBIST | (MDPERI_MBIST << 16))

//CFGAPB_AP_OWN
#define MD_CFGCTL_MASK                  (MD_CFGCTL | (MD_CFGCTL << 16))
#define MD_CLKCTL_MASK                   (MD_CLKCTL | (MD_CLKCTL << 16))
#define MD_RSTCTL_MASK                   (MD_RSTCTL | (MD_RSTCTL << 16))
#define MD_TOPSM_MASK                   (MD_TOPSM | (MD_TOPSM << 16))
#define MD_OST_MASK                        (MD_OST | (MD_OST << 16))
#define DBGSYS_MASK                        (DBGSYS | (DBGSYS << 16))
#define MD_DBG_MONITOR_MASK       (MD_DBG_MONITOR | (MD_DBG_MONITOR << 16))
#define MDGPIO_EINT_MASK              (MDGPIO_EINT | (MDGPIO_EINT << 16))
#define AP_CFGCTL_MASK                   (AP_CFGCTL | (AP_CFGCTL << 16))
#define AP_CLKCTL_MASK                   (AP_CLKCTL | (AP_CLKCTL << 16))
#define TOP_MISC_MASK                     (TOP_MISC | (TOP_MISC << 16))
#define AP_TOPSM_MASK                    (AP_TOPSM | (AP_TOPSM << 16))
#define AP_OST_MASK                         (AP_OST | (AP_OST << 16))
#define PLL_CTL_MASK                        (PLL_CTL | (PLL_CTL << 16))
#define EFUSE_MASK                           (EFUSE | (EFUSE << 16))
#define APGPIO_EINT_MASK               (APGPIO_EINT | (APGPIO_EINT << 16))

//=====================MD OWN======================

//MISC OWN
#define SPI_OWN_MD                         (SPI_OWN << 16)
#define AUXADC_OWN_MD                  (AUXADC_OWN << 16)

//AXI OWN
#define MODEM_3G_0_MD                   (MODEM_3G_0 << 16)                 
#define MODEM_3G_1_MD                   (MODEM_3G_1 << 16)                  
#define MODEM_2G_0_MD                   (MODEM_2G_0 << 16)                 
#define MODEM_2G_1_MD                   (MODEM_2G_1 << 16)                  
#define MODEM_TDD_MD                     (MODEM_TDD << 16)                    
#define LTE_PHY_MD                           (LTE_PHY << 16)                         
#define LTE_MAC_MD                          (LTE_MAC << 16)                          
#define AP_DEBUG_APB_MD                (AP_DEBUG_APB << 16)               
#define MD_DEBUG_APB_MD               (MD_DEBUG_APB << 16)               
#define MD_CACHE_DEBUG_MD           (MD_CACHE_DEBUG << 16)          
#define APAHB_MD                              (APAHB << 16)                              
#define MDAHB_MD                              (MDAHB << 16)          

//APAHB OWN
#define APPERI_APB_MD                   (APPERI_APB << 16)
#define EHPI_SLAVE_MD                    (EHPI_SLAVE << 16)
#define APMCU_APB_MD                    (APMCU_APB << 16)
#define USB30_MAC_MD                    (USB30_MAC << 16)
#define USB30_PHY_MD                     (USB30_PHY << 16)
#define SPI_REG_MD                         (SPI_REG << 16)
#define USB20_MAC_MD                    (USB20_MAC << 16)
#define USB20_PHY_MD                     (USB20_PHY << 16)
#define MSDC_0_MD                           (MSDC_0 << 16)
#define MSDC_1_MD                           (MSDC_1 << 16)
#define AP_VPORT_MD                       (AP_VPORT << 16)

//APPERIAPB OWN
#define EHPI_HOST_MD                     (EHPI_HOST << 16)
#define APNFI_MD                             (APNFI << 16)
#define MDNFI_MD                            (MDNFI << 16)
#define NLI_ARB_MD                         (NLI_ARB << 16)
#define IPSEC_MD                             (IPSEC << 16)
#define NIC_MD                                 (NIC << 16)
#define TZCCIF_MD                           (TZCCIF << 16)
#define APCCIF_MD                           (APCCIF << 16)
#define MDCCIF_MD                          (MDCCIF << 16)
#define AP_CLDMA_MD                      (AP_CLDMA << 16)
#define MD_CLDMA_MD                     (MD_CLDMA << 16)
#define PFC_MD                                 (PFC << 16)
#define AP_RSTCTL_MD                     (AP_RSTCTL << 16)
#define APPERI_MBIST_MD               (APPERI_MBIST << 16)

//MDAHB OWN
#define MD_TCM_MD                         (MD_TCM << 16)
#define MDPERI_APB_MD                  (MDPERI_APB << 16)
#define MDINFRA_APB_MD               (MDINFRA_APB << 16)
#define MDMCU_APB_MD                   (MDMCU_APB << 16)
#define MDCFG_APB_MD                   (MDCFG_APB << 16)
#define MEM_APB_MD                       (MEM_APB << 16)
#define SDIO_MD                              (SDIO << 16)
#define MD_VPORT_MD                     (MD_VPORT << 16)
#define BOOTROM_MD                       (BOOTROM << 16)

//MDPERIAPB OWN
#define MDPERI_MISC_MD                (MDPERI_MISC << 16)
#define MDPERI_DBGMON_MD           (MDPERI_DBGMON << 16)
#define USIM_0_MD                          (USIM_0 << 16)
#define USIM_1_MD                          (USIM_1 << 16)
#define MDUART_MD                         (MDUART << 16)
#define SHARED_UART0_MD             (SHARED_UART0 << 16)
#define SHARED_UART1_MD             (SHARED_UART1 << 16)
#define SDIO_CISCC_MD                   (SDIO_CISCC << 16)
#define AP_LED_MD                          (AP_LED << 16)
#define MD_LED_MD                          (MD_LED << 16)
#define MD_GPTM_MD                       (MD_GPTM << 16)
#define I2C_MD                                 (I2C << 16)
#define MD_GDMA_MD                      (MD_GDMA << 16)
#define MD_CIRQ_MD                        (MD_CIRQ << 16)
#define RTC_MD                                (RTC << 16)
#define MDPERI_MBIST_MD              (MDPERI_MBIST << 16)

//CFGAPB OWN
#define MD_CFGCTL_MD                    (MD_CFGCTL << 16)
#define MD_CLKCTL_MD                     (MD_CLKCTL << 16)
#define MD_RSTCTL_MD                    (MD_RSTCTL << 16)
#define MD_TOPSM_MD                     (MD_TOPSM << 16)
#define MD_OST_MD                          (MD_OST << 16)
#define DBGSYS_MD                          (DBGSYS << 16)
#define MD_DBG_MONITOR_MD         (MD_DBG_MONITOR << 16)
#define MDGPIO_EINT_MD                (MDGPIO_EINT << 16)
#define AP_CFGCTL_MD                    (AP_CFGCTL << 16)
#define AP_CLKCTL_MD                     (AP_CLKCTL << 16)
#define TOP_MISC_MD                      (TOP_MISC << 16)
#define AP_TOPSM_MD                     (AP_TOPSM << 16)
#define AP_OST_MD                          (AP_OST << 16)
#define PLL_CTL_MD                         (PLL_CTL << 16)
#define EFUSE_MD                            (EFUSE << 16)
#define APGPIO_EINT_MD                (APGPIO_EINT << 16)

//=====================AP OWN======================

//MISC OWN                     
#define SPI_OWN_AP                        SPI_OWN                 
#define AUXADC_OWN_AP                 AUXADC_OWN              
                                                      
//AXI OWN                                         
#define MODEM_3G_0_AP                  MODEM_3G_0              
#define MODEM_3G_1_AP                  MODEM_3G_1              
#define MODEM_2G_0_AP                  MODEM_2G_0              
#define MODEM_2G_1_AP                  MODEM_2G_1              
#define MODEM_TDD_AP                    MODEM_TDD               
#define LTE_PHY_AP                          LTE_PHY                 
#define LTE_MAC_AP                         LTE_MAC                 
#define AP_DEBUG_APB_AP              AP_DEBUG_APB            
#define MD_DEBUG_APB_AP              MD_DEBUG_APB            
#define MD_CACHE_DEBUG_AP          MD_CACHE_DEBUG          
#define APAHB_AP                             APAHB                   
#define MDAHB_AP                            MDAHB                   
                                                      
//APAHB OWN                     
#define APPERI_APB_AP                   APPERI_APB              
#define EHPI_SLAVE_AP                   EHPI_SLAVE              
#define APMCU_APB_AP                    APMCU_APB               
#define USB30_MAC_AP                    USB30_MAC               
#define USB30_PHY_AP                    USB30_PHY               
#define SPI_REG_AP                         SPI_REG                 
#define USB20_MAC_AP                    USB20_MAC               
#define USB20_PHY_AP                    USB20_PHY               
#define MSDC_0_AP                          MSDC_0                  
#define MSDC_1_AP                          MSDC_1                  
#define AP_VPORT_AP                       AP_VPORT                
                                                      
//APPERIAPB OWN               
#define EHPI_HOST_AP                     EHPI_HOST               
#define APNFI_AP                             APNFI                   
#define MDNFI_AP                            MDNFI                   
#define NLI_ARB_AP                         NLI_ARB                 
#define IPSEC_AP                             IPSEC                   
#define NIC_AP                                 NIC                     
#define TZCCIF_AP                           TZCCIF                  
#define APCCIF_AP                          APCCIF                  
#define MDCCIF_AP                          MDCCIF                  
#define AP_CLDMA_AP                     AP_CLDMA                
#define MD_CLDMA_AP                     MD_CLDMA                
#define PFC_AP                                PFC                     
#define AP_RSTCTL_AP                    AP_RSTCTL               
#define APPERI_MBIST_AP               APPERI_MBIST            
                                                      
//MDAHB OWN                               
#define MD_TCM_AP                         MD_TCM                  
#define MDPERI_APB_AP                  MDPERI_APB              
#define MDINFRA_APB_AP               MDINFRA_APB             
#define MDMCU_APB_AP                   MDMCU_APB               
#define MDCFG_APB_AP                   MDCFG_APB               
#define MEM_APB_AP                       MEM_APB                 
#define SDIO_AP                              SDIO                    
#define MD_VPORT_AP                     MD_VPORT                
#define BOOTROM_AP                       BOOTROM                 
                                                      
//MDPERIAPB OWN                            
#define MDPERI_MISC_AP                MDPERI_MISC             
#define MDPERI_DBGMON_AP           MDPERI_DBGMON           
#define USIM_0_AP                          USIM_0                  
#define USIM_1_AP                          USIM_1                  
#define MDUART_AP                         MDUART                  
#define SHARED_UART0_AP             SHARED_UART0            
#define SHARED_UART1_AP             SHARED_UART1            
#define SDIO_CISCC_AP                   SDIO_CISCC              
#define AP_LED_AP                          AP_LED                  
#define MD_LED_AP                          MD_LED                  
#define MD_GPTM_AP                       MD_GPTM                 
#define I2C_AP                                 I2C                     
#define MD_GDMA_AP                      MD_GDMA                 
#define MD_CIRQ_AP                        MD_CIRQ                 
#define RTC_AP                                RTC                     
#define MDPERI_MBIST_AP              MDPERI_MBIST            
                                                      
//CFGAPB OWN                    
#define MD_CFGCTL_AP                   MD_CFGCTL               
#define MD_CLKCTL_AP                   MD_CLKCTL               
#define MD_RSTCTL_AP                   MD_RSTCTL               
#define MD_TOPSM_AP                    MD_TOPSM                
#define MD_OST_AP                        MD_OST                  
#define DBGSYS_AP                         DBGSYS                  
#define MD_DBG_MONITOR_AP        MD_DBG_MONITOR          
#define MDGPIO_EINT_AP               MDGPIO_EINT             
#define AP_CFGCTL_AP                   AP_CFGCTL               
#define AP_CLKCTL_AP                    AP_CLKCTL               
#define TOP_MISC_AP                     TOP_MISC                
#define AP_TOPSM_AP                    AP_TOPSM                
#define AP_OST_AP                         AP_OST                  
#define PLL_CTL_AP                        PLL_CTL                 
#define EFUSE_AP                           EFUSE                   
#define APGPIO_EINT_AP               APGPIO_EINT             

//======================================
//Exported function
//======================================
extern void bl_cfgctl_ownership_init(void);
extern void bl_cfgctl_clear_misc();
extern void bl_cfgctl_set_misc(kal_uint32 data);
extern kal_uint32 bl_cfgctl_save_and_set_usbown(kal_uint32 own);
extern void bl_cfgctl_restore_usbown(kal_uint32 own);

#endif /*_BL_CFGCTL_H*/

