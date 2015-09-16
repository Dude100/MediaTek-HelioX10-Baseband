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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   tst_lmu_hw.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   Dummy driver for LMU HW
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$ 
 *
 * 11 07 2012 ken.liu
 * removed!
 * dhl module check-in.
 ****************************************************************************/
 
#ifndef __TST_LMU_HW_H__
#define __TST_LMU_HW_H__

#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)
  #error "LMU is not avaiable"
#else //#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)

#define LMU_Write_CSM_Addr_TS(reg_num, value)
#define LMU_Write_Short_Ary(ptr, ptr_length)
#define LMU_Write_Short_Word(word_data)

#define LMU_Write_Task_CSM(thread_id)
#if !defined(__FCORE__) || !defined(_LANGUAGE_ASM)
#define LMU_Write_ISR_CSM(isr_id)
#define LMU_Write_ISR_END_CSM(isr_id)
#define LMU_Write_ISR_END_RESUME_CSM(marker)
#else
#define LMU_Write_ISR_CSM(pReg, dReg)
#define LMU_Write_ISR_END_CSM(pReg, dReg)  
#define LMU_Write_ISR_END_RESUME_CSM(pReg, dReg)  
#endif

#endif  //#if defined(__TST_LMU_LOGGING__) || defined(USE_DNT_LOGGING)
#endif  //#ifndef __TST_LMU_HW_H__ 

