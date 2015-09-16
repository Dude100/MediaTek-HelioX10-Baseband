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
 *  psipeer_pun.h
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
 *  FILENAME : psipeer_pun.h
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
#ifndef _PSIPEER_PUN_H
#define _PSIPEER_PUN_H

#define panstruct_size(x) 2
IMP unsigned int panstruct_bits(void *);
IMP void panstruct_alloc(void *);
IMP void panstruct_dealloc(void *);
IMP unsigned int panstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int panstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define egprs_params_struct_size(x) 1
IMP unsigned int egprs_params_struct_bits(void *);
IMP void egprs_params_struct_alloc(void *);
IMP void egprs_params_struct_dealloc(void *);
IMP unsigned int egprs_params_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int egprs_params_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int extensionstruct_bits(void *);
IMP void extensionstruct_alloc(void *);
IMP void extensionstruct_dealloc(void *);
IMP unsigned int extensionstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int extensionstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprscelloptionsstruct_bits(void *);
IMP void gprscelloptionsstruct_alloc(void *);
IMP void gprscelloptionsstruct_dealloc(void *);
IMP unsigned int gprscelloptionsstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprscelloptionsstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define perchseqstruct_size(x) 2
IMP unsigned int perchseqstruct_bits(void *);
IMP void perchseqstruct_alloc(void *);
IMP void perchseqstruct_dealloc(void *);
IMP unsigned int perchseqstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int perchseqstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pccchorgparamstruct_size(x) 2
IMP unsigned int pccchorgparamstruct_bits(void *);
IMP void pccchorgparamstruct_alloc(void *);
IMP void pccchorgparamstruct_dealloc(void *);
IMP unsigned int pccchorgparamstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pccchorgparamstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define sgsnr_mscr_struct_size(x) 1
IMP unsigned int sgsnr_mscr_struct_bits(void *);
IMP void sgsnr_mscr_struct_alloc(void *);
IMP void sgsnr_mscr_struct_dealloc(void *);
IMP unsigned int sgsnr_mscr_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sgsnr_mscr_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi1msg_bits(void *);
IMP void psi1msg_alloc(void *);
IMP void psi1msg_dealloc(void *);
IMP unsigned int psi1msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi1msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define cellidentificationstruct_size(x) 8
IMP unsigned int cellidentificationstruct_bits(void *);
IMP void cellidentificationstruct_alloc(void *);
IMP void cellidentificationstruct_dealloc(void *);
IMP unsigned int cellidentificationstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cellidentificationstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int nongprscelloption_bits(void *);
IMP void nongprscelloption_alloc(void *);
IMP void nongprscelloption_dealloc(void *);
IMP unsigned int nongprscelloption_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nongprscelloption_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int reffreqstruct_bits(void *);
IMP void reffreqstruct_alloc(void *);
IMP void reffreqstruct_dealloc(void *);
IMP unsigned int reffreqstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int reffreqstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int reffreqliststruct_bits(void *);
IMP void reffreqliststruct_alloc(void *);
IMP void reffreqliststruct_dealloc(void *);
IMP unsigned int reffreqliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int reffreqliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int cellallocationliststruct_bits(void *);
IMP void cellallocationliststruct_alloc(void *);
IMP void cellallocationliststruct_dealloc(void *);
IMP unsigned int cellallocationliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int cellallocationliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprsmobileallocationsstruct_bits(void *);
IMP void gprsmobileallocationsstruct_alloc(void *);
IMP void gprsmobileallocationsstruct_dealloc(void *);
IMP unsigned int gprsmobileallocationsstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsmobileallocationsstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gprsmobileallocationsliststruct_bits(void *);
IMP void gprsmobileallocationsliststruct_alloc(void *);
IMP void gprsmobileallocationsliststruct_dealloc(void *);
IMP unsigned int gprsmobileallocationsliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gprsmobileallocationsliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define nonhoppingpcccchstruct_size(x) 3
IMP unsigned int nonhoppingpcccchstruct_bits(void *);
IMP void nonhoppingpcccchstruct_alloc(void *);
IMP void nonhoppingpcccchstruct_dealloc(void *);
IMP unsigned int nonhoppingpcccchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nonhoppingpcccchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int nonhoppingpccchlist_bits(void *);
IMP void nonhoppingpccchlist_alloc(void *);
IMP void nonhoppingpccchlist_dealloc(void *);
IMP unsigned int nonhoppingpccchlist_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nonhoppingpccchlist_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define hoppingpccchstruct_size(x) 2
IMP unsigned int hoppingpccchstruct_bits(void *);
IMP void hoppingpccchstruct_alloc(void *);
IMP void hoppingpccchstruct_dealloc(void *);
IMP unsigned int hoppingpccchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int hoppingpccchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int hoppingpccchlist_bits(void *);
IMP void hoppingpccchlist_alloc(void *);
IMP void hoppingpccchlist_dealloc(void *);
IMP unsigned int hoppingpccchlist_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int hoppingpccchlist_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int mahoppingpccchlist_bits(void *);
IMP void mahoppingpccchlist_alloc(void *);
IMP void mahoppingpccchlist_dealloc(void *);
IMP unsigned int mahoppingpccchlist_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int mahoppingpccchlist_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pccchstruct_bits(void *);
IMP void pccchstruct_alloc(void *);
IMP void pccchstruct_dealloc(void *);
IMP unsigned int pccchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pccchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pccchdesliststruct_bits(void *);
IMP void pccchdesliststruct_alloc(void *);
IMP void pccchdesliststruct_dealloc(void *);
IMP unsigned int pccchdesliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pccchdesliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi2msg_bits(void *);
IMP void psi2msg_alloc(void *);
IMP void psi2msg_dealloc(void *);
IMP unsigned int psi2msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi2msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int sercellparastruct_bits(void *);
IMP void sercellparastruct_alloc(void *);
IMP void sercellparastruct_dealloc(void *);
IMP unsigned int sercellparastruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int sercellparastruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int gencellparastruct_bits(void *);
IMP void gencellparastruct_alloc(void *);
IMP void gencellparastruct_dealloc(void *);
IMP unsigned int gencellparastruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int gencellparastruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi3msg_bits(void *);
IMP void psi3msg_alloc(void *);
IMP void psi3msg_dealloc(void *);
IMP unsigned int psi3msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi3msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define chgrpstruct_size(x) 2
IMP unsigned int chgrpstruct_bits(void *);
IMP void chgrpstruct_alloc(void *);
IMP void chgrpstruct_dealloc(void *);
IMP unsigned int chgrpstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int chgrpstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int channelgroupstruct_bits(void *);
IMP void channelgroupstruct_alloc(void *);
IMP void channelgroupstruct_dealloc(void *);
IMP unsigned int channelgroupstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int channelgroupstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi4msg_bits(void *);
IMP void psi4msg_alloc(void *);
IMP void psi4msg_dealloc(void *);
IMP unsigned int psi4msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi4msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int nc_meas_para_struct_bits(void *);
IMP void nc_meas_para_struct_alloc(void *);
IMP void nc_meas_para_struct_dealloc(void *);
IMP unsigned int nc_meas_para_struct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int nc_meas_para_struct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi5msg_bits(void *);
IMP void psi5msg_alloc(void *);
IMP void psi5msg_dealloc(void *);
IMP unsigned int psi5msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi5msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psimsgstruct_bits(void *);
IMP void psimsgstruct_alloc(void *);
IMP void psimsgstruct_dealloc(void *);
IMP unsigned int psimsgstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psimsgstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int bcchcarstruct_bits(void *);
IMP void bcchcarstruct_alloc(void *);
IMP void bcchcarstruct_dealloc(void *);
IMP unsigned int bcchcarstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int bcchcarstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pbcchdescstruct_bits(void *);
IMP void pbcchdescstruct_alloc(void *);
IMP void pbcchdescstruct_dealloc(void *);
IMP unsigned int pbcchdescstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pbcchdescstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#define pwrcontparastruct_size(x) 3
IMP unsigned int pwrcontparastruct_bits(void *);
IMP void pwrcontparastruct_alloc(void *);
IMP void pwrcontparastruct_dealloc(void *);
IMP unsigned int pwrcontparastruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pwrcontparastruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int apbcchstruct_bits(void *);
IMP void apbcchstruct_alloc(void *);
IMP void apbcchstruct_dealloc(void *);
IMP unsigned int apbcchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int apbcchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int ppbcchstruct_bits(void *);
IMP void ppbcchstruct_alloc(void *);
IMP void ppbcchstruct_dealloc(void *);
IMP unsigned int ppbcchstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int ppbcchstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi13msg_bits(void *);
IMP void psi13msg_alloc(void *);
IMP void psi13msg_dealloc(void *);
IMP unsigned int psi13msg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi13msg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psixstruct_bits(void *);
IMP void psixstruct_alloc(void *);
IMP void psixstruct_dealloc(void *);
IMP unsigned int psixstruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psixstruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psimsgliststruct1_bits(void *);
IMP void psimsgliststruct1_alloc(void *);
IMP void psimsgliststruct1_dealloc(void *);
IMP unsigned int psimsgliststruct1_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psimsgliststruct1_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psimsgliststruct_bits(void *);
IMP void psimsgliststruct_alloc(void *);
IMP void psimsgliststruct_dealloc(void *);
IMP unsigned int psimsgliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psimsgliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int unpsimsgliststruct_bits(void *);
IMP void unpsimsgliststruct_alloc(void *);
IMP void unpsimsgliststruct_dealloc(void *);
IMP unsigned int unpsimsgliststruct_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int unpsimsgliststruct_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int pktpsistatus_bits(void *);
IMP void pktpsistatus_alloc(void *);
IMP void pktpsistatus_dealloc(void *);
IMP unsigned int pktpsistatus_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int pktpsistatus_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

IMP unsigned int psi3bismsg_bits(void *);
IMP void psi3bismsg_alloc(void *);
IMP void psi3bismsg_dealloc(void *);
IMP unsigned int psi3bismsg_pack(kal_uint8 *, void *, unsigned int);
IMP unsigned int psi3bismsg_unpack(void *, kal_uint8 *, unsigned int, unsigned int, void *);

#endif 


