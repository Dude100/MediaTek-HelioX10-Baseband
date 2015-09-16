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
 * sdio_gpd.h
 *
 * Project:
 * --------
 *   SDIO Device Firmware 
 *
 * Description:
 * ------------
 *   
 *
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef SDIO_GPD_H
#define SDIO_GPD_H

#include "sdio_fw_drv_config.h"


#define SDIO_GPDH_NODE_BYTE_SIZE 16

typedef struct _SDIO_GPDH_Node {
    struct {
        unsigned HWO:1;
        unsigned BDP:1;
        unsigned BPS:1;
        unsigned reserved0:4;
        unsigned IOC:1;
        unsigned checksum:8;
        unsigned reserved1:16;
    } DW0;

    struct _SDIO_GPDH_Node *next;
    kal_uint32 buffer_address;

    union {
	    struct {
            unsigned rx_buffer_length:16;
            unsigned extension_length:8;
            unsigned reserved2:8;
        } RX;
        unsigned long reserved3;
    } DW3;

} SDIO_GPDH_Node, *PSDIO_GPDH_Node;

#define SDIO_GPD_GET_HWO(GPD)                  (GPD->DW0.HWO)
#define SDIO_GPD_SET_HWO(GPD)                  (GPD->DW0.HWO=1)
#define SDIO_GPD_CLR_HWO(GPD)                  (GPD->DW0.HWO=0)
#define SDIO_GPD_GET_BDP(GPD)                  (GPD->DW0.BDP)
#define SDIO_GPD_SET_BDP(GPD)                  (GPD->DW0.BDP=1)
#define SDIO_GPD_CLR_BDP(GPD)                  (GPD->DW0.BDP=0)
#define SDIO_GPD_GET_BPS(GPD)                  (GPD->DW0.BPS)
#define SDIO_GPD_SET_BPS(GPD)                  (GPD->DW0.BPS=1)
#define SDIO_GPD_CLR_BSP(GPD)                  (GPD->DW0.BPS=0)
#define SDIO_GPD_GET_IOC(GPD)                  (GPD->DW0.IOC)
#define SDIO_GPD_SET_IOC(GPD)                  (GPD->DW0.IOC=1)
#define SDIO_GPD_CLR_IOC(GPD)                  (GPD->DW0.IOC=0)
#define SDIO_GPD_GET_BUFFER_LENGTH(GPD)        (GPD->DW3.RX.rx_buffer_length)
#define SDIO_GPD_SET_BUFFER_LENGTH(GPD, LEN)   (GPD->DW3.RX.rx_buffer_length=LEN)
#define SDIO_GPD_GET_EXTENSION_lENGTH(GPD)     (GPD->DW3.RX.extension_length)
#define SDIO_GPD_SET_EXTENSION_lENGTH(GPD, LEN) (GPD->DW3.RX.extension_length=LEN)
#define SDIO_GPD_GET_NEXT_HEADER(GPD)          (GPD->next)
#define SDIO_GPD_SET_NEXT_HEADER(GPD, NEXT)    (GPD->next=NEXT)
#define SDIO_GPD_GET_BUFFER_ADDRESS(GPD)       (GPD->buffer_address)
#define SDIO_GPD_SET_BUFFER_ADDRESS(GPD, ADDR) (GPD->buffer_address=ADDR)


typedef struct _SDIO_RX_BD {

    struct {
        unsigned EOL:1;        // end of list
        unsigned reserved0:7;
        unsigned checksum:8;
        unsigned reserved1:16;        
    } DW0;

    unsigned long next_bd_address;
    unsigned long data_address;

    struct {
        unsigned rx_buffer_length:16;
        unsigned bd_ext_length:8;
        unsigned reserved2:8;
    } DW3;

} SDIO_RX_BD, *PSDIO_RX_BD;

#define SDIO_GPD_RX_BD_GET_EOL(BD)             (BD->DW0.EOL)
#define SDIO_GPD_RX_BD_SET_EOL(BD)             (BD->DW0.EOL=1)
#define SDIO_GPD_RX_BD_CLR_EOL(BD)             (BD->DW0.EOL=0)
#define SDIO_GPD_RX_BD_GET_CHECKSUM(BD)        (BD->DW0.checksum)
#define SDIO_GPD_RX_BD_SET_CHECKSUM(BD, CHECKSUM)   (BD->DW0.checksum=checksum)
#define SDIO_GPD_RX_BD_GET_NEXT(BD)            (BD->next_bd_address)
#define SDIO_GPD_RX_BD_SET_NEXT(BD, NEXT)      (BD->next_bd_address=NEXT)
#define SDIO_GPD_RX_BD_GET_BUF_ADDR(BD)        (BD->data_address)
#define SDIO_GPD_RX_BD_SET_BUF_ADDR(BD, ADDR)  (BD->data_address=ADDR)
#define SDIO_GPD_RX_BD_GET_RX_BUF_LEN(BD)      (BD->DW3.rx_buffer_length)
#define SDIO_GPD_RX_BD_SET_RX_BUF_LEN(BD, LEN) (BD->DW0.rx_buffer_length=LEN)
#define SDIO_GPD_RX_BD_GET_RX_BD_EXT_LEN(BD)        (BD->DW3.bd_ext_length)
#define SDIO_GPD_RX_BD_SET_RX_BD_EXT_LEN(BD, LEN)   (BD->DW0.bd_ext_length=LEN)

#endif
