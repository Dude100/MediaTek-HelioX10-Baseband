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

/*******************************************************************************
 * Filename:
 * ---------
 *   drv_mdcirq.h
 *
 * Project:
 * --------
 *   TATAKA
 *
 * Description:
 * ------------
 *   Low level interrupt controller driver
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
 * UESIM, cirq support
 *
 * removed!
 * removed!
 * mdcirq register definition re-arch
 ****************************************************************************/

#ifndef __DRV_MDCIRQ_H__
#define __DRV_MDCIRQ_H__
#include "kal_public_api.h"
#include "isrentry.h"
#include "drv_mdcirq_reg.h"

#if MDCIRQ_128_64_VERSION
#define MDCIRQ_REG_ADDR_INDEX(base_addr, irqid)                              \
    ((base_addr) + ((irqid/32)<<2))


#define MDCIRQ_WRITE_REG_INDEX(base_addr, index, value)                      \
    DRV_WriteReg32((base_addr) + ((index)<<2), value)

#define MDCIRQ_READ_REG_INDEX(base_addr, index)                              \
    DRV_Reg32((base_addr) + ((index)<<2))

#define MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, index, value)                  \
    DRV_WriteReg32_NPW((base_addr) + ((index)<<2), value)


#else /* else of MDCIRQ_128_64_VERSION */
#define MDCIRQ_REG_ADDR_INDEX(base_addr, irqid)                              \
    ((base_addr) - ((irqid/32)<<2))


#define MDCIRQ_WRITE_REG_INDEX(base_addr, index, value)                      \
    DRV_WriteReg32((base_addr) - ((index)<<2), value)

#define MDCIRQ_READ_REG_INDEX(base_addr, index)                              \
    DRV_Reg32((base_addr) - ((index)<<2))

#define MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, index, value)                  \
    DRV_WriteReg32_NPW((base_addr) - ((index)<<2), value)


#endif /* end of "else of MDCIRQ_128_64_VERSION" */


#define MDCIRQ_WriteReg32_Vector(base_addr, vector, value)                   \
do{                                                                          \
    MDCIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), value)                  \
}while(0)



#define MDCIRQ_WriteReg32_Vector_NPW(base_addr, vector, value)               \
do{                                                                          \
    MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), value)              \
}while(0)


#define MDCIRQ_SetRegBit_Vector(base_addr, vector)                           \
do{                                                                          \
	kal_uint32 tmp;                                                          \
	tmp = MDCIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) | (1UL<<((vector)%32)); \
    MDCIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), tmp);                   \
}while(0)																	 \

#define MDCIRQ_SetRegBit_Vector_NPW(base_addr, vector)                       \
do{                                                                          \
	kal_uint32 tmp;                                                          \
	tmp = MDCIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) | (1UL<<((vector)%32)); \
    MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), tmp);              \
}while(0)



#define MDCIRQ_ClrRegBit_Vector(base_addr, vector)                           \
do{ 																		 \
    kal_uint32 tmp;                                                          \
    tmp = MDCIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) & (~(1<<((vector)%32))); \
    MDCIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), tmp);                   \
}while(0)


#define MDCIRQ_ClrRegBit_Vector_NPW(base_addr, vector)                       \
do{ 																		 \
	kal_uint32 tmp; 														 \
	tmp = MDCIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) & (~(1<<((vector)%32))); \
	MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), tmp);              \
}while(0)


#define MDCIRQ_GetRegBit_Vector(base_addr, vector)                           \
    ((MDCIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) >> ((vector)%32)) & 1)



#define MDCIRQ_WrSetRegBit_Vector(base_addr, vector)                         \
do{ 																		 \
    MDCIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), 1<<((vector)%32));     \
}while(0)


#define MDCIRQ_WrSetRegBit_Vector_NPW(base_addr, vector)                     \
do{ 																		 \
    MDCIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), 1<<((vector)%32)); \
}while(0)

#define MDCIRQ_WrClrRegBit_Vector(base_addr, vector)                         \
	MDCIRQ_WrSetRegBit_Vector(base_addr, vector)

#define MDCIRQ_WrClrRegBit_Vector_NPW(base_addr, vector)                     \
	MDCIRQ_WrSetRegBit_Vector_NPW(base_addr, vector)


typedef void (*lisr_entry)(void);

/* extern functions/variables */
#if (ESIM_BUILD_CONFIG != ESIM_MULTI_MODE_ON_OSCAR) && (ESIM_BUILD_CONFIG != ESIM_SINGLE_MODE_ON_OSCAR)
extern irqlisr_entry lisr_dispatch_tbl[MAX_ISR_NUM];
#endif


#endif /* end of __DRV_MDCIRQ_H__ */

