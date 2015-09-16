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
 *   drv_arm7cirq.h
 *
 * Project:
 * --------
 *   MOLY Software
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
 ****************************************************************************/

#ifndef __DRV_ARM7CIRQ_H__
#define __DRV_ARM7CIRQ_H__
#include "kal_public_api.h"
#include "isrentry.h"
#include "drv_arm7cirq_reg.h"

#define ARM7CIRQ_REG_ADDR_INDEX(base_addr, irqid)                              \
    (base_addr)

#define ARM7CIRQ_WRITE_REG_INDEX(base_addr, index, value)                      \
    DRV_WriteReg32(base_addr, value)

#define ARM7CIRQ_READ_REG_INDEX(base_addr, index)                              \
    DRV_Reg32(base_addr)

#define ARM7CIRQ_WRITE_REG_INDEX_NPW(base_addr, index, value)                  \
    DRV_WriteReg32_NPW(base_addr, value)

#define ARM7CIRQ_WriteReg32_Vector(base_addr, vector, value)                   \
do{                                                                            \
    ARM7CIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), value)                  \
}while(0)

#define ARM7CIRQ_WriteReg32_Vector_NPW(base_addr, vector, value)               \
do{                                                                            \
    ARM7CIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), value)              \
}while(0)

#define ARM7CIRQ_SetRegBit_Vector(base_addr, vector)                           \
do{                                                                            \
	kal_uint32 tmp;                                                            \
	tmp = ARM7CIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) | (1UL<<((vector)%32)); \
    ARM7CIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), tmp);                   \
}while(0)

#define ARM7CIRQ_SetRegBit_Vector_NPW(base_addr, vector)                       \
do{                                                                            \
	kal_uint32 tmp;                                                            \
	tmp = ARM7CIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) | (1UL<<((vector)%32)); \
    ARM7CIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), tmp);               \
}while(0)

#define ARM7CIRQ_ClrRegBit_Vector(base_addr, vector)                           \
do{                                                                            \
    kal_uint32 tmp;                                                            \
    tmp = ARM7CIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) & (~(1<<((vector)%32))); \
    ARM7CIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), tmp);                   \
}while(0)

#define ARM7CIRQ_ClrRegBit_Vector_NPW(base_addr, vector)                       \
do{                                                                            \
	kal_uint32 tmp;                                                            \
	tmp = ARM7CIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) & (~(1<<((vector)%32))); \
	ARM7CIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), tmp);               \
}while(0)

#define ARM7CIRQ_GetRegBit_Vector(base_addr, vector)                           \
    ((ARM7CIRQ_READ_REG_INDEX(base_addr, ((vector)/32)) >> ((vector)%32)) & 1)

#define ARM7CIRQ_WrSetRegBit_Vector(base_addr, vector)                         \
do{                                                                            \
    ARM7CIRQ_WRITE_REG_INDEX(base_addr, ((vector)/32), 1<<((vector)%32));      \
}while(0)

#define ARM7CIRQ_WrSetRegBit_Vector_NPW(base_addr, vector)                     \
do{                                                                            \
    ARM7CIRQ_WRITE_REG_INDEX_NPW(base_addr, ((vector)/32), 1<<((vector)%32));  \
}while(0)

#define ARM7CIRQ_WrClrRegBit_Vector(base_addr, vector)                         \
	ARM7CIRQ_WrSetRegBit_Vector(base_addr, vector)

#define ARM7CIRQ_WrClrRegBit_Vector_NPW(base_addr, vector)                     \
	ARM7CIRQ_WrSetRegBit_Vector_NPW(base_addr, vector)


typedef void (*lisr_entry)(void);


#endif /* end of __DRV_ARM7CIRQ_H__ */
