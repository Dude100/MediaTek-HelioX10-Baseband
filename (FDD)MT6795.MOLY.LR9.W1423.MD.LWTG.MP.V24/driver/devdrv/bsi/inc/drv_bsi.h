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
 *   drv_bsi.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   BSI (Baseband Serial Interface) Driver
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
 * add BSI mutex
 *
 * removed!
 * removed!
 * [TRUNK] add failWrite BSI-PMIC API for reset test
 *
 * removed!
 * removed!
 * [TRUNK] BSI-PMIC driver update after testing on MT6339 ES1
 *
 * removed!
 * removed!
 * [TRUNK] add BSI-PMIC driver design and .mak
 ****************************************************************************/

#ifndef __DRV_REG_H__
#define __DRV_REG_H__

#include <bsi_reg.h>

// BSICTRL MAC
#define BSI_MAC_STOP                    (1UL <<  0)
#define BSI_MAC_RD_EN                   (1UL <<  4)

#define BSI_MAC_RD_EN_BIT_OFFSET        (4)
#define BSI_MAC_STATUS_BIT_OFFSET       (8)
#define BSI_MAC_CS_SEL_BIT_OFFSET       (12)
#define BSI_MAC_PORT_SEL_BIT_OFFSET     (13)

#define BSI_MAC_RD_EN_MASK              (0x00000010)
#define BSI_MAC_CS_SEL_MASK             (0x00001000)
#define BSI_MAC_PORT_SEL_MASK           (0x0000E000)

#define BSI_MAC_RDINT_STS_BIT           (1UL << 0)
#define BSI_MAC_RDINT_EN                (1UL << 8)

#define BSI_MAC_RDATA_3532_OFFSET       (0)
#define BSI_MAC_RDATA_3532_MASK         (0xF << BSI_MAC_RDATA_3532_OFFSET)

#define SET_BSI_MAC_CTRL(_port, _cs, _op) \
        do{ \
            kal_uint32 tmp; \
            tmp = (DRV_Reg32(BSI_MAC_CTRL_REG) & (~(BSI_MAC_RD_EN_MASK | BSI_MAC_CS_SEL_MASK | BSI_MAC_PORT_SEL_MASK))); \
            DRV_WriteReg32(BSI_MAC_CTRL_REG, (tmp | (_port << BSI_MAC_PORT_SEL_BIT_OFFSET) | (_cs << BSI_MAC_CS_SEL_BIT_OFFSET) | (_op << BSI_MAC_RD_EN_BIT_OFFSET)) ); \
        } while(0)
#define SET_BSI_MAC_READ_EVENT          do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_CTRL_REG); \
                                            DRV_WriteReg32(BSI_MAC_CTRL_REG, (BSI_MAC_RD_EN | tmp)); \
                                        } while(0)
#define SET_BSI_MAC_WRITE_EVENT         do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_CTRL_REG); \
                                            DRV_WriteReg32(BSI_MAC_CTRL_REG, ((~BSI_MAC_RD_EN) & tmp)); \
                                        } while(0)
#define STOP_MAC_MODE_EVENT             do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_CTRL_REG); \
                                            DRV_WriteReg32(BSI_MAC_CTRL_REG,(BSI_MAC_STOP | tmp)); \
                                        } while(0)
#define SET_BSI_MAC_CS_SEL(_cs)         do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_CTRL_REG); \
                                            if ( _cs == 0 ) \
                                                DRV_WriteReg32(BSI_MAC_CTRL_REG, ((~(_cs << BSI_MAC_CS_SEL_BIT_OFFSET)) & tmp)); \
                                            else if ( _cs == 1 ) \
                                                DRV_WriteReg32(BSI_MAC_CTRL_REG, ((_cs << BSI_MAC_CS_SEL_BIT_OFFSET) | tmp)); \
                                            else \
                                                ASSERT(0); \
                                        } while(0)
#define SET_BSI_MAC_PORT_SEL(_port)     do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_CTRL_REG); \
                                            DRV_WriteReg32(BSI_MAC_CTRL_REG, ((_port << BSI_MAC_PORT_SEL_BIT_OFFSET) | tmp)); \
                                        } while(0)
#define ENABLE_BSI_MAC_RDINT            do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_RDINT_REG); \
                                            DRV_WriteReg32(BSI_MAC_RDINT_REG, (BSI_MAC_RDINT_EN | tmp)); \
                                        } while(0)
#define DISABLE_BSI_MAC_RDINT           do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_RDINT_REG); \
                                            DRV_WriteReg32(BSI_MAC_RDINT_REG, ((~BSI_MAC_RDINT_EN) & tmp)); \
                                        } while(0)
#define CLEAR_MAC_RDINT_STS             do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_MAC_RDINT_REG); \
                                            DRV_WriteReg32(BSI_MAC_RDINT_REG, (BSI_MAC_RDINT_STS_BIT | tmp)); \
                                        } while(0)
// BSICTRL IMM
#define BSI_IMM_STOP                    (1UL <<  0)
#define BSI_IMM_RD_EN                   (1UL <<  4)

#define BSI_IMM_RD_EN_BIT_OFFSET        (4)
#define BSI_IMM_STATUS_BIT_OFFSET       (8)
#define BSI_IMM_CS_SEL_BIT_OFFSET       (12)
#define BSI_IMM_PORT_SEL_BIT_OFFSET     (13)

#define BSI_IMM_RD_EN_MASK              (0x00000010)
#define BSI_IMM_CS_SEL_MASK             (0x00001000)
#define BSI_IMM_PORT_SEL_MASK           (0x0000E000)

#define BSI_IMM_RDINT_STS_BIT           (1UL << 0)
#define BSI_IMM_RDINT_EN                (1UL << 8)

#define BSI_IMM_RDATA_3532_OFFSET       (0)
#define BSI_IMM_RDATA_3532_MASK         (0xF << BSI_IMM_RDATA_3532_OFFSET)


#define SET_BSI_IMM_CTRL(_port, _cs, _op) \
        do{ \
            kal_uint32 tmp; \
            tmp = (DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG) & (~(BSI_IMM_RD_EN_MASK | BSI_IMM_CS_SEL_MASK | BSI_IMM_PORT_SEL_MASK))); \
            DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, (tmp | (_port << BSI_IMM_PORT_SEL_BIT_OFFSET) | (_cs << BSI_IMM_CS_SEL_BIT_OFFSET) | (_op << BSI_IMM_RD_EN_BIT_OFFSET)) ); \
        } while(0)
#define SET_BSI_IMM_READ_EVENT          do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, (BSI_IMM_RD_EN | tmp)); \
                                        } while(0)
#define SET_BSI_IMM_WRITE_EVENT         do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, ((~BSI_IMM_RD_EN) & tmp)); \
                                        } while(0)
#define STOP_IMM_MODE_EVENT             do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG,(BSI_IMM_STOP | tmp)); \
                                        } while(0)
#define SET_BSI_IMM_CS_SEL(_cs)         do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG); \
                                            if ( _cs == 0 ) \
                                                DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, ((~(_cs << BSI_IMM_CS_SEL_BIT_OFFSET)) & tmp)); \
                                            else if ( _cs == 1 ) \
                                                DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, ((_cs << BSI_IMM_CS_SEL_BIT_OFFSET) | tmp)); \
                                            else \
                                                ASSERT(0); \
                                        } while(0)
#define SET_BSI_IMM_PORT_SEL(_port)     do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_CTRL_REG, ((_port << BSI_IMM_PORT_SEL_BIT_OFFSET) | tmp)); \
                                        } while(0)
#define ENABLE_BSI_IMM_RDINT            do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_RDINT_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_RDINT_REG, (BSI_IMM_RDINT_EN | tmp)); \
                                        } while(0)
#define DISABLE_BSI_IMM_RDINT           do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_RDINT_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_RDINT_REG, ((~BSI_IMM_RDINT_EN) & tmp)); \
                                        } while(0)
#define CLEAR_IMM_RDINT_STS             do{ \
                                            kal_uint32 tmp; \
                                            tmp = DRV_Reg32(BSI_APB2CRF_IMM_RDINT_REG); \
                                            DRV_WriteReg32(BSI_APB2CRF_IMM_RDINT_REG, (BSI_IMM_RDINT_STS_BIT | tmp)); \
                                        } while(0)

typedef enum
{
    BSI_WRITE_EVENT = 0,
    BSI_READ_EVENT = 1
}BSI_EVENT_TYPE;


// BSISPI CTRL
// BSISPI_PORT_PARAM_REG:
#define BSISPI_MIPI_EN_OFFSET           (0)
#define BSISPI_BSI_MODE_OFFSET          (1)
#define BSISPI_SINGLE_DIR_OFFSET        (3)
#define BSISPI_CLSNINT_EN_OFFSET        (4)
#define BSISPI_DBG_EN_OFFSET            (5)
#define BSISPI_READ_PHASE_OFFSET        (6)
#define BSISPI_RESET_MODE_OFFSET        (8)
#define BSISPI_IO_MODE_OFFSET           (16)
#define BSISPI_SW_CS_SEL_OFFSET         (17)

#define BSISPI_MIPI_EN_MASK             (0x00000001)
#define BSISPI_BSI_MODE_MASK            (0x00000006)
#define BSISPI_SINGLE_DIR_MASK          (0x00000008)
#define BSISPI_CLSNINT_EN_MASK          (0x00000010)
#define BSISPI_DBG_EN_MASK              (0x00000020)
#define BSISPI_READ_PHASE_MASK          (0x000000C0)
#define BSISPI_RESET_MODE_MASK          (0x00000100)
#define BSISPI_IO_MODE_MASK             (0x00010000)
#define BSISPI_SW_CS_SEL_MASK           (0x00020000)

// BSISPI_ICx_PARAM1_REG:
#define BSISPI_CLK_POL_OFFSET           (0)
#define BSISPI_CLK_SPD_OFFSET           (2)
#define BSISPI_CS_LEN_OFFSET            (5)
#define BSISPI_CS_POL_OFFSET            (7)
#define BSISPI_RD_CLK_SPD_OFFSET        (8)
#define BSISPI_RD_TRANS_CLKON_OFFSET    (11)
#define BSISPI_RD_TRANS_LEN_OFFSET      (12)
#define BSISPI_IDLE_CNT_OFFSET          (16)
#define BSISPI_WLEN_OFFSET              (24)

#define BSISPI_CLK_POL_MASK             (0x00000003)
#define BSISPI_CLK_SPD_MASK             (0x0000001C)
#define BSISPI_CS_LEN_MASK              (0x00000060)
#define BSISPI_CS_POL_MASK              (0x00000080)
#define BSISPI_RD_CLK_SPD_MASK          (0x00000700)
#define BSISPI_RD_TRANS_CLKON_MASK      (0x00000800)
#define BSISPI_RD_TRANS_LEN_MASK        (0x0000F000)
#define BSISPI_IDLE_CNT_MASK            (0x001F0000)
#define BSISPI_WLEN_MASK                (0x1F000000)

// BSISPI_ICx_PARAM2_REG:
#define BSISPI_RD_TRANS_CS_WAVEFORM_OFFSET (0)
#define BSISPI_RD_RDATA_CS_POL_OFFSET      (15)
#define BSISPI_RD_WLEN_OFFSET              (16)
#define BSISPI_RD_RLEN_OFFSET              (24)

#define BSISPI_RD_TRANS_CS_WAVEFORM_MASK   (0x00007FFF)
#define BSISPI_RD_RDATA_CS_POL_MASK        (0x00008000)
#define BSISPI_RD_WLEN_MASK                (0x001F0000)
#define BSISPI_RD_RLEN_MASK                (0x3F000000)

typedef enum
{
    BSISPI_READ_PHASE0 = 0,
    BSISPI_READ_PHASE1 = 1,
    BSISPI_READ_PHASE2 = 2,
    BSISPI_READ_PHASE3 = 3 
}BSISPI_READ_PHASE_TYPE;

typedef enum
{
    BSISPI_1BIT_PER_CYCLE = 0,
    BSISPI_2BIT_PER_CYCLE = 1,
    BSISPI_3BIT_PER_CYCLE = 2,
    BSISPI_BSI_MODE_RESERVED = 3
}BSISPI_BSI_MODE_TYPE;

#define BSISPI_RD_TRANS_CLKON    (0x1)
#define BSISPI_CS_POL_INV_EN     (0x1)

typedef enum
{
    BSISPI_LONG_PULSE = 0,
    BSISPI_SHORT_PULSE = 1,
    BSISPI_LONG_PULSE_ALIGN = 2,
    BSISPI_CS_SHAPE_RESEVED = 3
}BSISPI_CS_SHAPE_TYPE;

typedef enum
{
    BSISPI_CLK_DIV2 = 0,
    BSISPI_CLK_DIV4 = 1,
    BSISPI_CLK_DIV6 = 2,
    BSISPI_CLK_DIV8 = 3,
    BSISPI_CLK_DIV12 = 4,
    BSISPI_CLK_DIV16 = 5,
    BSISPI_CLK_DIV24 = 6,
    BSISPI_CLK_DIV32 = 7
}BSISPI_CLK_SPD_TYPE;

typedef enum
{
    BSISPI_TRUE_CLK_POL = 0,
    BSISPI_INV_CLK_POL = 1,
    BSISPI_TRUE_CLK_POL_PRE_PULSE = 2,
    BSISPI_INV_CLK_POL_PRE_PULSE = 3
}BSISPI_CLK_POL_TYPE;

#define BSISPI_RD_RDATA_CS_POL_HIGH    (0x1)

// BSICTRL Operations
#define GET_BSI_MAC_STATUS() ((DRV_Reg32(BSI_MAC_CTRL_REG) >> BSI_MAC_STATUS_BIT_OFFSET) & 0x1)
#define SET_BSI_MAC_WRITE_DATA(_wdata) DRV_WriteReg32(BSI_MAC_WDATA_REG, _wdata)
#define GET_BSI_MAC_RD_INT_STATUS() ((DRV_Reg32(BSI_MAC_RDINT_REG) & BSI_MAC_RDINT_STS_BIT) >> 0)
#define GET_BSI_MAC_READ_DATA_3100() DRV_Reg32(BSI_MAC_RDATA_3100_REG)
#define GET_BSI_MAC_READ_DATA_3532() DRV_Reg32(BSI_MAC_RDATA_3532_REG)
#define GET_BSI_MAC_READ_DATA() ((DRV_Reg32(BSI_MAC_RDATA_3532_REG) << 32) | DRV_Reg32(BSI_MAC_RDATA_3100_REG))

#define GET_BSI_IMM_STATUS() ((DRV_Reg32(BSI_APB2CRF_IMM_CTRL_REG) >> BSI_IMM_STATUS_BIT_OFFSET) & 0x1)
#define SET_BSI_IMM_WRITE_DATA(_wdata) DRV_WriteReg32(BSI_APB2CRF_IMM_WDATA_REG, _wdata)
#define GET_BSI_IMM_RD_INT_STATUS() ((DRV_Reg32(BSI_APB2CRF_IMM_RDINT_REG) & BSI_IMM_RDINT_STS_BIT) >> 0)
#define GET_BSI_IMM_READ_DATA_3100() DRV_Reg32(BSI_APB2CRF_IMM_RDATA_3100_REG)
#define GET_BSI_IMM_READ_DATA_3532() DRV_Reg32(BSI_APB2CRF_IMM_RDATA_3532_REG)
#define GET_BSI_IMM_READ_DATA() ((DRV_Reg32(BSI_APB2CRF_IMM_RDATA_3532_REG) << 32) | DRV_Reg32(BSI_APB2CRF_IMM_RDATA_3100_REG))


/*****************************************************************************
 *                       function declaration                                *
 *****************************************************************************/
/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic_init
*
* DESCRIPTION
*  This function is to initialize BSI SPI controller for PMIC.
*
* PARAMETERS
*  None.
*
* RETURNS
*  None.
*
*------------------------------------------------------------------------*/
extern void drv_bsi_pmic_init(void);

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_write
*
* DESCRIPTION
*  This function is to write MT6339 PMIC register through BSI.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*  val  - data to be written into MT6339 PMIC address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
extern void drv_bsi_pmic6339_reg_write(kal_uint8 reg, kal_uint16 val);

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_failWrite
*  (Only for BSI reset testing, not for normal use)
*
* DESCRIPTION
*  This function is to write MT6339 PMIC register through BSI
*  with incorrect number of transfer bits.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*  val  - data to be written into MT6339 PMIC address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
extern void drv_bsi_pmic6339_reg_failWrite(kal_uint8 reg, kal_uint16 val);

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_pmic6339_reg_read
*
* DESCRIPTION
*  This function is to read MT6339 PMIC register through BSI.
*
* PARAMETERS
*  reg  - MT6339 PMIC register address. (8 bits)
*
* RETURNS
*  value which from MT6339 PMIC address. (16 bits)
*
*------------------------------------------------------------------------*/
extern kal_uint16 drv_bsi_pmic6339_reg_read(kal_uint8 reg);

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_a60386_reg_write
*
* DESCRIPTION
*  This function is to write A60386 register through BSI.
*
* PARAMETERS
*  reg  - A60386 register address. (12 bits)
*  val  - data to be written into A60386 address. (16 bits)
*
* RETURNS
*  None
*
*------------------------------------------------------------------------*/
extern void drv_bsi_a60386_reg_write(kal_uint16 reg, kal_uint16 val);

/*-----------------------------------------------------------------------*
* FUNCTION
*  drv_bsi_a60386_reg_read
*
* DESCRIPTION
*  This function is to read A60386 register through BSI.
*
* PARAMETERS
*  reg  - A60386 register address. (12 bits)
*
* RETURNS
*  value which from A60386 address. (16 bits)
*
*------------------------------------------------------------------------*/
extern kal_uint16 drv_bsi_a60386_reg_read(kal_uint16 reg);

extern void drv_bsi_dump_reg();

#endif  /* end of __DRV_BSI_H__ */
