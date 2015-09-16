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
 *	csmcc_bc_defs.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   this file contains the constant and macro definition related bearer capability
 *   used in CSM(CC) module.
 *
 * Author:
 * -------
 * -------
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
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


#ifndef _CSMCC_BC_DEFS_H
#define _CSMCC_BC_DEFS_H

#include "csmcc_types.h"

#define CSMCC_MAX_BC_IE_LEN    14
#define CSMCC_MAX_LLC_IE_LEN   16
#define CSMCC_MAX_HLC_IE_LEN   3
 
/************** MSCAP MASKs *****************/
#define HR_SUPP_MASK         (kal_uint8)0x12
#define FR_V1_MASK           (kal_uint8)0x01
#define HR_V1_MASK           (kal_uint8)0x02  
#define FR_V2_MASK           (kal_uint8)0x04 
#define FR_V3_MASK           (kal_uint8)0x08
#define HR_V3_MASK           (kal_uint8)0x10
//MAUI_01966467
#if defined(__AMRWB_LINK_SUPPORT__)
#define FR_AMRWB_V5_MASK     (kal_uint8)0x02  
#endif
#ifdef __REL4__
/*[Cosine 070425] Refer to 26.103 */
#define SYS_ID_GSM      (kal_uint8)0x00
#define SYS_ID_UMTS     (kal_uint8)0x04
#endif /* (__REL4__)*/
#define CSD_MASK                   (kal_uint16)0x0100
#define TRANS_FAX_MASK             (kal_uint16)0x0200
#define NON_TRANS_FAX_MASK         (kal_uint16)0x0400
#define TRANS_SYNC_MASK            (kal_uint16)0x0800
#define NON_TRANS_SYNC_MASK        (kal_uint16)0x1000
#define TRANS_ASYNC_MASK           (kal_uint16)0x2000
#define NON_TRANS_ASYNC_MASK       (kal_uint16)0x4000
#define TRANS_PAD_MASK             (kal_uint16)0x8000
#define NON_TRANS_PAD_MASK         (kal_uint16)0x0001
#define TRANS_PACKET_MASK          (kal_uint16)0x0002
#define NON_TRANS_PACKET_MASK      (kal_uint16)0x0004
#define TCH_H_MASK                 (kal_uint8)0x10

/************** BIT MASKs *****************/

#define CSMCC_ONE_BIT_MASK			(kal_uint8)0X01
#define CSMCC_TWO_BIT_MASK			(kal_uint8)0X03
#define CSMCC_THREE_BIT_MASK		(kal_uint8)0X07
#define CSMCC_FOUR_BIT_MASK		(kal_uint8)0X0F
#define CSMCC_FIVE_BIT_MASK		(kal_uint8)0X1F
#define CSMCC_SIX_BIT_MASK			(kal_uint8)0X3F
#define CSMCC_SEVEN_BIT_MASK		(kal_uint8)0X7F


/************** BIT OFFSETs *****************/

#define CSMCC_ONE_BIT_OFFSET		  (kal_uint8)0X01
#define CSMCC_TWO_BIT_OFFSET		  (kal_uint8)0X02
#define CSMCC_THREE_BIT_OFFSET	  (kal_uint8)0X03
#define CSMCC_FOUR_BIT_OFFSET		  (kal_uint8)0X04
#define CSMCC_FIVE_BIT_OFFSET		  (kal_uint8)0X05
#define CSMCC_SIX_BIT_OFFSET		  (kal_uint8)0X06
#define CSMCC_SEVEN_BIT_OFFSET	  (kal_uint8)0X07

/* Bit masks for Bearer-Capability IE's */

#define CSMCC_PEER_BC_ITC_MASK            (kal_uint8) 0x07
#define CSMCC_PEER_BC_TM_MASK             (kal_uint8) 0x08
#define CSMCC_PEER_BC_RCR_MASK            (kal_uint8) 0x60
#define CSMCC_PEER_EXT_BIT_MASK           (kal_uint8) 0x80
#define CSMCC_PEER_BC_SVI_MASK            (kal_uint8) 0x0F
#define CSMCC_PEER_BC_ESTB_MASK           (kal_uint8) 0x01
#define CSMCC_PEER_BC_NIRR_MASK           (kal_uint8) 0x02
#define CSMCC_PEER_BC_CFG_MASK            (kal_uint8) 0x04
#define CSMCC_PEER_BC_DM_MASK             (kal_uint8) 0x08
#define CSMCC_PEER_BC_STR_MASK            (kal_uint8) 0x30
#define CSMCC_PEER_BC_COMP_MASK           (kal_uint8) 0x40
#define CSMCC_PEER_BC_SAP_MASK            (kal_uint8) 0x07
#define CSMCC_PEER_BC_RA_MASK             (kal_uint8) 0x18
#define CSMCC_PEER_BC_ORA_MASK            (kal_uint8) 0x18
#define CSMCC_PEER_BC_OITC_MASK           (kal_uint8) 0x60
#define CSMCC_PEER_BC_INB_MASK            (kal_uint8) 0X02     
#define CSMCC_PEER_BC_ASS_MASK            (kal_uint8) 0X04  
#define CSMCC_PEER_BC_LLI_MASK            (kal_uint8) 0X08
#define CSMCC_PEER_BC_MODE_MASK           (kal_uint8) 0X10 
#define CSMCC_PEER_BC_MF_MASK             (kal_uint8) 0X20
#define CSMCC_PEER_BC_HDR_MASK            (kal_uint8) 0X40
#define CSMCC_PEER_BC_SYNC_MASK           (kal_uint8) 0x01
#define CSMCC_PEER_BC_UIL1_MASK           (kal_uint8) 0x1E
#define CSMCC_PEER_BC_URT_MASK            (kal_uint8) 0x0F
#define CSMCC_PEER_BC_NDB_MASK            (kal_uint8) 0x10
#define CSMCC_PEER_BC_NEG_MASK            (kal_uint8) 0x20 
#define CSMCC_PEER_BC_NSB_MASK            (kal_uint8) 0x40
#define CSMCC_PEER_BC_PAR_MASK            (kal_uint8) 0x07
#define CSMCC_PEER_BC_NICR_MASK           (kal_uint8) 0x08
#define CSMCC_PEER_BC_NICT_MASK           (kal_uint8) 0x10
#define CSMCC_PEER_BC_INRT_MASK           (kal_uint8) 0x60
#define CSMCC_PEER_BC_MODT_MASK           (kal_uint8) 0x1F
#define CSMCC_PEER_BC_CE_MASK             (kal_uint8) 0x60
#define CSMCC_PEER_BC_FNUR_MASK           (kal_uint8) 0x1F
#define CSMCC_PEER_BC_OMT_MASK            (kal_uint8) 0x60
#define CSMCC_PEER_BC_MAXTC_MASK          (kal_uint8) 0x07
#define CSMCC_PEER_BC_ACSMCC_MASK         (kal_uint8) 0x78
#define CSMCC_PEER_BC_AIUR_MASK           (kal_uint8) 0x0F
#define CSMCC_PEER_BC_UIMI_MASK           (kal_uint8) 0x70
#define CSMCC_PEER_BC_AI_MASK             (kal_uint8) 0x0C
#define CSMCC_PEER_BC_ACCE_MASK           (kal_uint8) 0x70
#define CSMCC_PEER_BC_UIL2_MASK           (kal_uint8) 0x1F

/* Octets for BC IE's */
#define BC_OCTET3   		(kal_uint8)0
#define BC_OCTET3A  		(kal_uint8)1
#define BC_OCTET4   		(kal_uint8)2
#define BC_OCTET5   		(kal_uint8)3
#define BC_OCTET5A  		(kal_uint8)4
#define BC_OCTET5B  		(kal_uint8)5
#define BC_OCTET6   		(kal_uint8)6
#define BC_OCTET6A  		(kal_uint8)7
#define BC_OCTET6B  		(kal_uint8)8
#define BC_OCTET6C  		(kal_uint8)9
#define BC_OCTET6D  		(kal_uint8)10
#define BC_OCTET6E  		(kal_uint8)11
#define BC_OCTET6F  		(kal_uint8)12
#define BC_OCTET6G      (kal_uint8)13
#define BC_OCTET7       (kal_uint8)14
#define BC_OCTET_NONE   (kal_uint8)22
#define MAX_OCTET_BC 	(kal_uint8)16

/* Bit Masks for LLC IE's  */

#define CSMCC_PEER_LLC_ITC_MASK           (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_CS_MASK            (kal_uint8) 0x60
#define CSMCC_PEER_LLC_NI_MASK            (kal_uint8) 0x40
#define CSMCC_PEER_LLC_ITR_MASK           (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_TM_MASK            (kal_uint8) 0x60
#define CSMCC_PEER_LLC_RM_MASK            (kal_uint8) 0x7F
#define CSMCC_PEER_LLC_UIL1_MASK          (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_L1ID_MASK          (kal_uint8) 0x60
#define CSMCC_PEER_LLC_URT_MASK           (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_NEG_MASK           (kal_uint8) 0x20
#define CSMCC_PEER_LLC_SYNC_MASK          (kal_uint8) 0x40
#define CSMCC_PEER_LLC_FCR_MASK           (kal_uint8) 0x02
#define CSMCC_PEER_LLC_FCT_MASK           (kal_uint8) 0x04
#define CSMCC_PEER_LLC_NICR_MASK          (kal_uint8) 0x08
#define CSMCC_PEER_LLC_NICT_MASK          (kal_uint8) 0x10
#define CSMCC_PEER_LLC_INTR_MASK          (kal_uint8) 0x60
#define CSMCC_PEER_LLC_INBN_MASK          (kal_uint8) 0x02
#define CSMCC_PEER_LLC_ASS_MASK           (kal_uint8) 0x04
#define CSMCC_PEER_LLC_NLLI_MASK          (kal_uint8) 0x08
#define CSMCC_PEER_LLC_MOL1_MASK          (kal_uint8) 0x10
#define CSMCC_PEER_LLC_MFRM_MASK          (kal_uint8) 0x20
#define CSMCC_PEER_LLC_HDRF_MASK          (kal_uint8) 0x40
#define CSMCC_PEER_LLC_PAR_MASK           (kal_uint8) 0x07
#define CSMCC_PEER_LLC_NDB_MASK           (kal_uint8) 0x18
#define CSMCC_PEER_LLC_NSB_MASK           (kal_uint8) 0x60
#define CSMCC_PEER_LLC_MT_MASK            (kal_uint8) 0x3F
#define CSMCC_PEER_LLC_DUPM_MASK          (kal_uint8) 0x40
#define CSMCC_PEER_LLC_UL2P_MASK          (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_Q933U_MASK         (kal_uint8) 0x03
#define CSMCC_PEER_LLC_MOL2_MASK          (kal_uint8) 0x60
#define CSMCC_PEER_LLC_UL2PI_MASK         (kal_uint8) 0x7F
#define CSMCC_PEER_LLC_WS_MASK            (kal_uint8) 0x7F
#define CSMCC_PEER_LLC_UL3P_MASK          (kal_uint8) 0x1F
#define CSMCC_PEER_LLC_OL3PI_MASK         (kal_uint8) 0x7F
#define CSMCC_PEER_LLC_MOL3_MASK          (kal_uint8) 0x60
#define CSMCC_PEER_LLC_DPS_MASK           (kal_uint8) 0x0F
#define CSMCC_PEER_LLC_PWS_MASK           (kal_uint8) 0x7F
#define CSMCC_PEER_LLC_AL3PIM_MASK        (kal_uint8) 0x0F
#define CSMCC_PEER_LLC_AL3PIL_MASK        (kal_uint8) 0x0F

/* Octets for LLC IE's */
#define LLC_OCTET3   		(kal_uint8)0
#define LLC_OCTET3A  		(kal_uint8)1
#define LLC_OCTET4   		(kal_uint8)2
#define LLC_OCTET4A   	   (kal_uint8)10
#define LLC_OCTET5   		(kal_uint8)3
#define LLC_OCTET5A  		(kal_uint8)4
#define LLC_OCTET5B1  	   (kal_uint8)5
#define LLC_OCTET5B2  	   (kal_uint8)11
#define LLC_OCTET5C  		(kal_uint8)12
#define LLC_OCTET5D  		(kal_uint8)13
#define LLC_OCTET6   		(kal_uint8)6
#define LLC_OCTET6A1     	(kal_uint8)7
#define LLC_OCTET6A2  	   (kal_uint8)15
#define LLC_OCTET6B  		(kal_uint8)8
#define LLC_OCTET7         (kal_uint8)14
#define LLC_OCTET7A1       (kal_uint8)16
#define LLC_OCTET7A2       (kal_uint8)17
#define LLC_OCTET7A3       (kal_uint8)18
#define LLC_OCTET7B1       (kal_uint8)19
#define LLC_OCTET7B2       (kal_uint8)20
#define LLC_OCTET7C        (kal_uint8)21
#define LLC_OCTET_NONE     (kal_uint8)22

#define MAX_OCTET_LLC 	   (kal_uint8)18
#define TOTAL_LLC_OCTET    (kal_uint8)22
/* Bit Masks for HLC IE's */

#define CSMCC_PEER_HLC_PP_MASK          (kal_uint8) 0x03
#define CSMCC_PEER_HLC_INT_MASK         (kal_uint8) 0x1C
#define CSMCC_PEER_HLC_HLCI_MASK        (kal_uint8) 0x1F
#define CSMCC_PEER_HLC_EHLCI_MASK       (kal_uint8) 0x1F
#define CSMCC_PEER_HLC_INT_OFFSET       (kal_uint8)  2

#define CSMCC_MAX_RLP_IWS      (61)
#define CSMCC_MAX_RLP_MWS      (61)

#define CSMCC_MAX_DC_DICT_NUM  (65535)
#define CSMCC_MIN_DC_DICT_NUM  (512)
#define CSMCC_MAX_DC_STRING_LEN (250)
#define CSMCC_MIN_DC_STRING_LEN (6)

#define CSMCC_MIN_4800_BPS_T1  (44)
#define CSMCC_MIN_9600_BPS_T1  (38)
#define CSMCC_MIN_14400_BPS_T1 (42)

/* macro definition for accessing MS capability */

#define SPEECH_VER(mask) \
             ((CSMCC_PTR->mscap.speech_version & mask)>0)

#if defined(__AMRWB_LINK_SUPPORT__)
#define SPEECH_VER2(mask) \
             ((CSMCC_PTR->mscap.speech_version_byte2 & mask)>0)
#endif

#define DATA_CAP(mask) \
             ((CSMCC_PTR->mscap.data_cap & mask)>0)

#define ACC(mask) \
             ((CSMCC_PTR->mscap.acc & mask)>0)

/* [MAUI_01712442], Rel6, 24.008 10.5.4.5 Note1
 * Maximum number of traffic channels and acceptable channel coding shall be 
 * set to 0 if the request service is not supported in 2G.
 */
  
/* Note! Currently, we always fill MAX_TCH as 0. But if the capability changed 
 * some day in the future, rel6 Spec. shall be considered for UMTS only services
 * (check if CSMCC_PTR->umts_only_service = TRUE).
 */
#define GET_MAX_TCH (CSMCC_1_TCH)

#define ACC_CAP \
             ((CSMCC_PTR->mscap.acc & 0x08) + \
             ((CSMCC_PTR->mscap.acc & 0x04) >> 1) + \
             ((CSMCC_PTR->mscap.acc & 0x02) >> 1))

#ifdef __REL6__
#define GET_ACC \
	((CSMCC_PTR->umts_only_service == KAL_TRUE)? 0: ACC_CAP)
#else
#define GET_ACC ACC_CAP
#endif /*__REL6__*/

/* macro definition for store MS capability */
/* Use last byte to represent all supported UMTS codecs.*/
/*MAUI_02601973  remove REL_4 dependency*/
#define SET_MSCAP( data ) \
             CSMCC_PTR->mscap.speech_version = data[0];\
             CSMCC_PTR->mscap.speech_version_byte2 = data[1];\
             CSMCC_PTR->mscap.umts_supported_speech = data[2];\
             CSMCC_PTR->mscap.umts_supported_speech_byte2 = data[3];\
             CSMCC_PTR->mscap.data_cap = data[5]+(data[4] << 8);\
             CSMCC_PTR->mscap.acc = data[6];\
             CSMCC_PTR->mscap.disable_call = data[7];


#endif /* _CSMCC_BC_DEFS_H */

