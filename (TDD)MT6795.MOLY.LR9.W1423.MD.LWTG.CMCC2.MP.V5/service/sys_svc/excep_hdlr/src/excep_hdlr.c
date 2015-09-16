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
 *   excep_hdlr.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file provides typedefs and definiton for PS index trace.
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
 
#include "kal_public_api.h" //MSBB change #include "kal_release.h"
#include "ex_item.h"
#include "excep_hdlr.h"

extern kal_uint32 INT_Exception_SP;

sys_excep_hdlr_desc *desc_head = NULL;
extern kal_uint8 INT_Exception_Enter;

#if defined(__MTK_TARGET__)

#if defined(__ARMCC_VERSION)

#pragma arm
__asm unsigned int retrieve_curr_ctxt(excep_ctxt *ctxt)
{
    STR r0, [r0,#8]
    STR r1, [r0,#12]
    STR r2, [r0,#16]
    STR r3, [r0,#20]
    STR r4, [r0,#24]
    STR r5, [r0,#28]
    STR r6, [r0,#32]
    STR r7, [r0,#36]
    STR r8, [r0,#40]
    STR r9, [r0,#44]
    STR r10, [r0,#48]
    STR r11, [r0,#52]
    STR r12, [r0,#56]
    STR r13, [r0,#60]
    STR r14, [r0,#64]
    STR r15, [r0,#68]
    
    MRS r1, cpsr
    STR r1, [r0,#4]
    MRS r1, spsr
    STR r1, [r0]
    
    bx r14
}
#pragma

#elif defined(__GNUC__)

void retrieve_curr_ctxt(excep_ctxt *ctxt){

    __asm__(        
        ".code 32 \n\t"
        "STR %[value], [%[value],#8] \n\t"
        "STR r1, [%[value],#12] \n\t"
        "STR r2, [%[value],#16] \n\t"
        "STR r3, [%[value],#20] \n\t"
        "STR r4, [%[value],#24] \n\t"
        "STR r5, [%[value],#28] \n\t"
        "STR r6, [%[value],#32] \n\t"
        "STR r7, [%[value],#36] \n\t"
        "STR r8, [%[value],#40] \n\t"
        "STR r9, [%[value],#44] \n\t"
        "STR r10, [%[value],#48] \n\t"
        "STR r11, [%[value],#52] \n\t"
        "STR r12, [%[value],#56] \n\t"
        "STR r13, [%[value],#60] \n\t"
        "STR r14, [%[value],#64] \n\t"
        "STR r15, [%[value],#68] \n\t"
    
        "MRS r1, cpsr \n\t"
        "STR r1, [%[value],#4] \n\t"
        "MRS r1, spsr \n\t"
        "STR r1, [%[value]] \n\t"
    
        "bx r14 \n\t"
        : 
        : [value]"r" (ctxt) /* resiter r0 value. */
        : /* No clobbers */

    );
}

#endif /* __RVCT__ , __GNUC__ */
#endif /* __MTK_TARGET__ */

void sys_excep_hdlr_desc_init(sys_excep_hdlr_desc *hdlr_desc, sys_excep_hdlr hdlr)
{
    if(hdlr_desc==NULL || hdlr==NULL)
    {
        ASSERT(0);
    }
    memset(hdlr_desc, 0, sizeof(hdlr_desc));
    hdlr_desc->hdlr = hdlr;
}

int sys_excep_excep_hdlr_reg(sys_excep_hdlr_desc *hdlr_desc)
{
    sys_excep_hdlr_desc *desc = desc_head;
    
    if(hdlr_desc==NULL || hdlr_desc->next_desc!=NULL)
    {
        ASSERT(0);
    }
    
    if(desc==NULL)
    {
        desc_head = hdlr_desc;
    }
    else
    {
        for(; desc->next_desc!=0; desc=desc->next_desc);
        desc->next_desc = hdlr_desc;
    }

    return 0;
}

int sys_excep_hook(int excep_reason, int excep_addr, EX_CPU_REG_T *excep_reg)
{
    sys_excep_hdlr_desc *desc;
    sys_excep_param param = { 0 };
    
    param.excep_reason = excep_reason;
    param.excep_addr = excep_addr;
    param.excep_reg = excep_reg;
    
    for(desc=desc_head; desc; desc=desc->next_desc)
    {
        switch(desc->hdlr(&param))
        {
        case SYS_EXCEP_ACT_RETURN:
            return 1;
            break;
        case SYS_EXCEP_ACT_RETURN_NEXT:
            return 2;
            break;
        default:
            break;
        }
    }
    return 0; // return to exception handler
}

int retrieve_excep_ctxt(excep_ctxt *ctxt)
{
    unsigned int *excep_stack;
    
    if(ctxt==NULL) return -1;
    memset(ctxt, 0, sizeof(ctxt));
    
    if(INT_Exception_Enter>0)
    {
		if(ex_log_ptr)
		    excep_stack = (unsigned int*)ex_log_ptr->envinfo.stack_ptr;
        else
            excep_stack = (unsigned int*)INT_Exception_SP;
        
        /* exception type */
        switch (ex_log_ptr->header.ex_type)
        {
        case UNDEF_EXCEPTION:
        case SWI_EXCEPTION:
        case PREFETCH_EXCEPTION:
        case DATAABORT_EXCEPTION:
            excep_stack += 2;
            memcpy(&(ctxt->cpsr), excep_stack, sizeof(EX_CPU_REG_T));
            break;
         
        case ASSERT_FAIL_EXCEPTION:
        excep_stack += 5;
            memcpy(&(ctxt->r0), excep_stack, sizeof(unsigned int)*8);
            ctxt->pc = excep_stack[8];
            ctxt->sp = (unsigned int)(excep_stack+9);
            ctxt->cpsr = 0x1F;
            ctxt->spsr = 0x1F;
            break;
             
        case SYS_FATALERR_EXT_TASK_EXCEPTION:
        case SYS_FATALERR_EXT_BUF_EXCEPTION:
            memcpy(&(ctxt->r3), excep_stack, sizeof(unsigned int)*5);
            ctxt->pc = excep_stack[5];
            ctxt->sp = (unsigned int)(excep_stack+6);
            ctxt->cpsr = 0x1F;
            ctxt->spsr = 0x1F;
            break;

        default:
            return -1;
        }
    }
    else
    {
#if defined(__MTK_TARGET__)
        retrieve_curr_ctxt(ctxt);
#endif /* __MTK_TARGET__ */
    }
    
    ctxt->pc &= 0xFFFFFFFE;
    
    return 0;
}