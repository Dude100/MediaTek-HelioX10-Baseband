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
/*******************************************************************************
 * Filename:
 * ---------
 *    sim_vsim_dummy_driver.h
 *
 * Project:
 * --------
 *    Wisdom
 *
 * Description:
 * ------------
 *    This file defines the data structure, enum and constant for dummy driver
 *
 * Author:
 * -------
 * -------
 *
 *******************************************************************************/
#ifndef SIM_VSIM_DUMMY_DRIVER_H
#define SIM_VSIM_DUMMY_DRIVER_H

#define DF_META_DATA_LEN 22
#define EF_META_DATA_LEN 15
#define EF_FILE_DATA_START sizeof(sim_vsim_file_meta_struct)

typedef struct
{
    /* The first 32 bytes */
    kal_uint8 fcp_length;
    kal_uint8 fcp_tmp[31];
    /* ------32 bytes ------ */
} sim_vsim_file_meta_struct;

typedef struct
{
    sim_vsim_file_meta_struct meta_data;
	kal_uint8 current_file_idx[2];
    kal_uint8 sim_status[22];   /* Store SIM status of current DF */	
} sim_vsim_context_struct;

#ifdef __GEMINI__ /*mtk01612: support_on_gemini*/
extern kal_uint16 L1vsim_Cmd(kal_uint8 *txData, kal_uint16 txSize, kal_uint8 *rxData, kal_uint16 *rxSize, kal_uint8 simInterface);
#else
extern kal_uint16 L1vsim_Cmd(kal_uint8 *txData, kal_uint16 txSize, kal_uint8 *rxData, kal_uint16 *rxSize);
#endif

#endif /* SIM_VSIM_DUMMY_DRIVER_H */ 

