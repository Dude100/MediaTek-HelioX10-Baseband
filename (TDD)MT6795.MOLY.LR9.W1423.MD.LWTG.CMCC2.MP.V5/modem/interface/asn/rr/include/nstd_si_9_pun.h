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
 *  nstd_si_9_pun.h
 *
 * Project:
 * --------
 *  MAUI
 *
 * Description:
 * ------------
 *  
 *
 * Author:
 * -------
 *  
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *------------------------------------------------------------------------------
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/

/********************************************************************************
*  Copyright Statement:
*  --------------------
*
*  This product has been developed using a protocol stack
*  developed by Sasken Communication Technologies Limited.
*
********************************************************************************/


/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2002
*
*******************************************************************************
 *  FILENAME : nstd_si_9_pun.h
 *  SYNOPSIS : Functions for encoding/decoding.
 *
 *                      R E V I S I O N    H I S T O R Y
 *
 */
#ifdef MTK_PEER 
#define IMP __declspec(dllimport) 
#else 
#define IMP 
#endif 
#ifndef _NSTD_SI_9_PUN_H
#define _NSTD_SI_9_PUN_H

IMP unsigned int infotype_struct_bits(void *);
IMP void infotype_struct_alloc(void *);
IMP void infotype_struct_dealloc(void *);
IMP unsigned int infotype_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int infotype_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int POSITION_bits(void *);
IMP void POSITION_alloc(void *);
IMP void POSITION_dealloc(void *);
IMP unsigned int POSITION_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int POSITION_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int positions_struct_bits(void *);
IMP void positions_struct_alloc(void *);
IMP void positions_struct_dealloc(void *);
IMP unsigned int positions_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int positions_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int SCHEDINFO_bits(void *);
IMP void SCHEDINFO_alloc(void *);
IMP void SCHEDINFO_dealloc(void *);
IMP unsigned int SCHEDINFO_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int SCHEDINFO_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int schedinfo_struct_bits(void *);
IMP void schedinfo_struct_alloc(void *);
IMP void schedinfo_struct_dealloc(void *);
IMP unsigned int schedinfo_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int schedinfo_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int SI_9_REST_OCT_bits(void *);
IMP void SI_9_REST_OCT_alloc(void *);
IMP void SI_9_REST_OCT_dealloc(void *);
IMP unsigned int SI_9_REST_OCT_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int SI_9_REST_OCT_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int si_9_struct_bits(void *);
IMP void si_9_struct_alloc(void *);
IMP void si_9_struct_dealloc(void *);
IMP unsigned int si_9_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int si_9_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


