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
 *
 * Filename:
 * ---------
 *   dcmgr.h
 *
 * Project:
 * --------
 *   MAUI (MT6226/MT6227/MT6228/MT6229)
 *
 * Description:
 * ------------
 *   Dynamic Code Manager for dynamic code relocation into TCM(internal SRAM)
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 * removed!
 *
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

/*****************************************************************************
*  Maintenance / Configuration Notes
*  ================================================================================
*   
*  Definitions :
*  ==============
*   
*  DYNAMIC_CODE_NUM         : Total number of DCM candidates (regardless of DCM 
*                             target pool)
*  DYNAMIC_CODE_XXX         : Identity number of DCM candidate, must be an
*                             incremental number
*                             Note, must not change the pre-fix DYNAMIC_CODE_
*  DCM_TARGET_NUM           : Total number DCM target pools
*  DCM_TARGET_ADDRESSx      : Start Address of DCM target pool x, must be consistent
*                             with scattter file
*  DCM_TARGET_SIZEx         : Size of DCM target pool x
*
*  DCM_SCAT_CODEx_AVAILABLE : The xth DCM identity is available for certain BB-chip
*  
*  DCM_TARGET_CONFIGURE     : Specify DCM target pool of the entire DCM candidates
*                             according to their identity
*                          
*  SOP to add-in a new DCM candidates :
*  =====================================
*  New candidate, DYNAMIC_CODE_EXAMMPLE
*
*  STEP 1 :  increment DYNAMIC_CODE_NUM by 1 and define identity number for 
*            new DCM candidate
*
*            #define DYNAMIC_CODE_NUM        N
*            #define DYNAMIC_CODE_EXAMMPLE  (N-1)
*            
*  STEP 2 :  edit scatter file
*
*  STEP 3 :  change the DCM_TARGET_NUM, and create DCM_TARGET_ADDRESSx
*            together with DCM_TARGET_SIZEx in case of new DCM target pool 
*            is needed
*            
*  STEP 4 :  define DCM_SCAT_CODEN_AVAILABLE for specific BB-chip if it
*            is not common candidates
*  
*  STEP 5 :  specify DCM target pool ID for all DCM candidates
*            Despite of availability, each DCM ID must be specified with a 
*            DCM target pool, 0 if unavailable
*
*  STEP 6 :  edit dcmgr.c, declare the correspondence linker symbol, and 
*            assign as an entry of DCM_linker_symbols_by_dynamic_code_id[].
*
*  STEP 7 :  in case of new DCM target pool added, create a new entry 
*            for the following array in dcmgr.c
*            current_dynamic_code_id[]
*            DCM_target_pool_addr[]
*            DCM_target_pool_size[]
*
*****************************************************************************/

#ifndef __DCMGR_H
#define __DCMGR_H

#include "kal_general_types.h"

#if defined(__MTK_TARGET__)

/*
 * Define chips dependency.
 */

#if defined(MT6228)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6229) || defined(MT6230)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6268T)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6268H)
#define MT6228_SERIES_DCMGR
#endif

#if defined(MT6238) || defined(MT6239)
#define MT6238_SERIES_DCMGR
#endif

#if defined(MT6235) || defined(MT6235B)
#define MT6235_SERIES_DCMGR
#endif

#if defined(MT6226) || defined(MT6227) || defined(MT6226M) || defined(MT6226D)
#define MT6227_SERIES_DCMGR
#endif

#if defined(MT6223) || defined(MT6223P)
#define MT6223_SERIES_DCMGR
#endif

#if defined(MT6227D)
#define MT6227_SERIES_DCMGR
#endif

#if defined(MT6253T) || defined(MT6253)
#define MT6253_SERIES_DCMGR
#endif

#if defined(MT6236) || defined(MT6236B)
#define MT6236_SERIES_DCMGR
#endif

#if defined(MT6252)
#define MT6252_SERIES_DCMGR
#endif

/*
 * Define constants.
 */

/* invalid value */
#define DCMGR_INVALID_VAL   (0xFFFFFFFF)

/* mask to convert dynamic code ID to suitable pool index */
#define DYNAMIC_POOL_ID_MASK  (0xFF)

#if defined(__DYNAMIC_CODE_MANAGER__)

/* DCM users should use __DYNAMIC_CODE_MANAGER__ but DYNAMIC_CODE_MANAGER */
#define DYNAMIC_CODE_MANAGER

/* define dynamic code information */
#define DYNAMIC_CODE_NUM      23
#define DYNAMIC_CODE_NONE     -1
#define DYNAMIC_CODE_AMR515   0
#define DYNAMIC_CODE_G3D      1
#define DYNAMIC_CODE_CTM      2
#define DYNAMIC_CODE_G729     3
#define DYNAMIC_CODE_SBC      4
#define DYNAMIC_CODE_BCODE    5
#define DYNAMIC_CODE_REVERB   6
#define DYNAMIC_CODE_RESAMPLE 7
#define DYNAMIC_CODE_JPEG_ENC 8
#define DYNAMIC_CODE_JPEG_DEC 9
#define DYNAMIC_CODE_VRENGINE 10
#define DYNAMIC_CODE_MP4DEC_B 11
#define DYNAMIC_CODE_MP4ENC_B 12
#define DYNAMIC_CODE_264DEC_B 13
#define DYNAMIC_CODE_MP4DEC_S 14
#define DYNAMIC_CODE_MP4ENC_S 15
#define DYNAMIC_CODE_264DEC_S 16
#define DYNAMIC_CODE_MP4DEC_C 17 /* only for MT6225 now */
#define DYNAMIC_CODE_MP4ENC_C 18   /* only for MT6225 now */
#define DYNAMIC_CODE_264DEC_C 19   /* only for MT6253 now */
#define DYNAMIC_CODE_RVDEC_B  20
#define DYNAMIC_CODE_RVDEC_S  21
#define DYNAMIC_CODE_RVDEC_C  22

#if defined(MT6228_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE2$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        2
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE2$$Base)
#define DCM_TARGET_SIZE2      0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6238_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5010F000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5010C800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */


/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6235_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		3
#define DCM_TARGET_ADDRESS1   		0x5010F000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5010C800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */
#define DCM_TARGET_ADDRESS3   		0x50108C00
#define DCM_TARGET_SIZE3      		0x3C00      /* 15KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE14_AVAILABLE   /* H264B */
#define DCM_SCAT_CODE15_AVAILABLE   /* MP4ENCS */
#define DCM_SCAT_CODE16_AVAILABLE   /* MP$DECS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,3,3,3,2,2,2,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6268A)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5011B000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50118800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6268)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x50116000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50113800
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6270A)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5012F000 
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x5012C800  
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */


#elif defined(MT6227_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE6_AVAILABLE   /* BCODE */
#define DCM_SCAT_CODE7_AVAILABLE   /* REVERB */
#define DCM_SCAT_CODE8_AVAILABLE   /* RESAMPLE */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */


/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,1,1,1,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6225)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE18$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        2
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE18$$Base)
#define DCM_TARGET_SIZE2      0xd90      /* 3KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE14_AVAILABLE   /* H264B */
#define DCM_SCAT_CODE18_AVAILABLE   /* MP4DEC_CODE */
#define DCM_SCAT_CODE19_AVAILABLE   /* MP4ENC */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,1,1,1,0,0,0,2,2,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6253_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        3
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE1$$Base)
#define DCM_TARGET_SIZE1      0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_CODE17$$Base)
#define DCM_TARGET_SIZE2      0xd90      /* 3KB */
#define DCM_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_CODE12$$Base)
#define DCM_TARGET_SIZE3      0x9600      /* 37.5KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE12_AVAILABLE   /* MP4ENCB */
#define DCM_SCAT_CODE13_AVAILABLE   /* MP4DECB */
#define DCM_SCAT_CODE16_AVAILABLE   /* MP4ENCS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */
#define DCM_SCAT_CODE18_AVAILABLE   /* MP4DEC_CODE */
#define DCM_SCAT_CODE19_AVAILABLE   /* MP4ENC */
#define DCM_SCAT_CODE20_AVAILABLE   /* H264C */
#define DCM_SCAT_CODE22_AVAILABLE   /* RVDECS */
#define DCM_SCAT_CODE23_AVAILABLE   /* RVDECC */

/* 
 * setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
 * 3 : DCM target pool 3
 */
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,3,1,0,0,3,2,2,2,3,0,2,3

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6223_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE3$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        1
#define DCM_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_CODE3$$Base)
#define DCM_TARGET_SIZE1      0x1280      /* 4736 Bytes */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE7_AVAILABLE   /* REVERB */
#define DCM_SCAT_CODE8_AVAILABLE   /* RESAMPLE */
#define DCM_SCAT_CODE9_AVAILABLE   /* JPG_ENC */
#define DCM_SCAT_CODE10_AVAILABLE   /* JPG_DEC */
/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
*/
#define DCM_TARGET_CONFIGURE  0,0,1,0,1,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6252_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_CODE1$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE17$$Base;
extern kal_uint32 Image$$DYNAMIC_CODE12$$Base;

/* define target pool information */
#define DCM_TARGET_NUM        3

#define DCM_TARGET_ADDRESS1   0x0
#define DCM_TARGET_SIZE1      0x0
#define DCM_TARGET_ADDRESS2   0x0
#define DCM_TARGET_SIZE2      0x0
#define DCM_TARGET_ADDRESS3   0x0
#define DCM_TARGET_SIZE3      0x0

/* 
 * setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
 * 3 : DCM target pool 3
 */
#define DCM_TARGET_CONFIGURE  1,0,1,1,1,0,0,0,0,0,1,3,1,0,0,3,2,2,2,3,0,2,3

/* ---------------------------------------------------------------------------------- */

#elif defined(MT6236_SERIES_DCMGR)

/* define target pool information */
#define DCM_TARGET_NUM        		2
#define DCM_TARGET_ADDRESS1   		0x5010B000
#define DCM_TARGET_SIZE1      		0x5000      /* 20KB */
#define DCM_TARGET_ADDRESS2   		0x50110000
#define DCM_TARGET_SIZE2      		0x2800      /* 10KB */

/* dynamic code availability on scatter file */
#define DCM_SCAT_CODE1_AVAILABLE   /* AUD_AMR515 */
#define DCM_SCAT_CODE2_AVAILABLE   /* G3D */
#define DCM_SCAT_CODE3_AVAILABLE   /* AUD_CTM */
#define DCM_SCAT_CODE4_AVAILABLE   /* AUD_G729 */
#define DCM_SCAT_CODE5_AVAILABLE   /* AUD_SBC */
#define DCM_SCAT_CODE11_AVAILABLE   /* VRENGINE */
#define DCM_SCAT_CODE15_AVAILABLE   /* MP4DECS */
#define DCM_SCAT_CODE17_AVAILABLE   /* H264S */
#define DCM_SCAT_CODE22_AVAILABLE   /* RVDECS */

/* setup target pool by code id
 * 0 : DCM candidate unavailable
 * 1 : DCM target pool 1
 * 2 : DCM target pool 2
*/
#define DCM_TARGET_CONFIGURE  1,2,1,1,1,0,0,0,0,0,1,0,0,0,2,0,2,0,0,0,0,2,0

#else

#error Overlay region for dynamic code relocation should be determined for new chipset

#endif

#endif /* __DYNAMIC_CODE_MANAGER__ */

/* ---------------------------------------------------------------------------------- */

#if defined(__DCM_WITH_COMPRESSION__)

/* define compressed dynamic code ID information */
#define DYNAMIC_CODE_COMPRESS_NUM          6
#define DYNAMIC_CODE_COMPRESS_END          0x106
#define DYNAMIC_CODE_COMPRESS_BEGIN        0x100
#define DYNAMIC_CODE_COMPRESS_NONE         -1
#define DYNAMIC_CODE_COMPRESS_SBC          DYNAMIC_CODE_COMPRESS_BEGIN //0x100
#define DYNAMIC_CODE_COMPRESS_RESAMPLE     (DYNAMIC_CODE_COMPRESS_BEGIN+1) //0x101
#define DYNAMIC_CODE_COMPRESS_BESLOUDNESS  (DYNAMIC_CODE_COMPRESS_BEGIN+2) //0x102
#define DYNAMIC_CODE_COMPRESS_MP4DEC_C     (DYNAMIC_CODE_COMPRESS_BEGIN+3) //0x103
#define DYNAMIC_CODE_COMPRESS_H264DEC_C     (DYNAMIC_CODE_COMPRESS_BEGIN+4) //0x104
#define DYNAMIC_CODE_COMPRESS_MP4ENC_C     (DYNAMIC_CODE_COMPRESS_BEGIN+5) //0x104

/* DCM with compression user RO size 
 * !CAUTION!
 * The defined RO size should be close to the linked size of each user
 * Following definitions would be parsed by sysgen.
 * Please do not change it without notice to sysgen owner.
 */

/* Video */
#define DYNAMIC_CODE_COMPRESS_H264DEC_RO_SIZE       0x14000
#define DYNAMIC_CODE_COMPRESS_MP4DEC_RO_SIZE        0x1E000
#define DYNAMIC_CODE_COMPRESS_MP4ENC_RO_SIZE        0x11800

/* Audio */
#define DYNAMIC_CODE_COMPRESS_BESLOUDNESS_RO_SIZE   0x3400
#define DYNAMIC_CODE_COMPRESS_RESAMPLE_RO_SIZE      0x1800
#define DYNAMIC_CODE_COMPRESS_SBC_RO_SIZE           0x2000

/* DCM with compression user RO size 
 * !CAUTION!
 * The defined RO size should be something close to the linked size of each user
 * Above definitions would be parsed by sysgen.
 * Please do not change it without notice to sysgen owner.
 */

#if defined(MT6252_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;

/* dynamic code availability on scatter file */
#if defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __BT_A2DP_PROFILE__ */

#if defined(__BT_AUDIO_VIA_SCO__)
#define DCM_COMP_SCAT_RESAMPLE_AVAILABLE       /* RESAMPLE with compression */
#endif /* __BT_AUDIO_VIA_SCO__ */

#if defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __BES_LOUDNESS_SUPPORT__ */

#if defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

/* define target pool information */
#define DCM_COMP_TARGET_NUM        3

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#elif defined(DCM_COMP_SCAT_RESAMPLE_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#else
#define DCM_COMP_TARGET_ADDRESS1   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE1      0x0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#define DCM_COMP_TARGET_SIZE2      0x3400      /* 13KB */
#else
#define DCM_COMP_TARGET_ADDRESS2   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE2      0x0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#else
#define DCM_COMP_TARGET_ADDRESS3   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE3      0x0
#endif

/* 
 * setup target pool by code id
 * 0 : DCM with compression candidate unavailable
 * 1 : DCM with compression target pool 1
 * 2 : DCM with compression target pool 2
 * 3 : DCM with compression target pool 3
 */
#define DCM_COMP_TARGET_CONFIGURE  1,1,2,3,3,3

#elif defined(MT6253_SERIES_DCMGR)

extern kal_uint32 Image$$DYNAMIC_COMP_SBC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_RESAMPLE$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_BESLOUDNESS$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4DEC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_MP4ENC$$Base;
extern kal_uint32 Image$$DYNAMIC_COMP_H264DEC$$Base;

/* dynamic code availability on scatter file */
#if defined(__BT_A2DP_PROFILE__)
#define DCM_COMP_SCAT_SBC_AVAILABLE            /* SBC with compression  */
#endif /* __BT_A2DP_PROFILE__ */

#if defined(__BT_AUDIO_VIA_SCO__)
#define DCM_COMP_SCAT_RESAMPLE_AVAILABLE       /* RESAMPLE with compression */
#endif /* __BT_AUDIO_VIA_SCO__ */

#if defined(__BES_LOUDNESS_SUPPORT__)
#define DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE    /* BESLOUDNESS with compression */
#endif /* __BES_LOUDNESS_SUPPORT__ */

#if defined(__MPEG4_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4DEC_AVAILABLE         /* MP4DEC with compression */
#endif /* __MPEG4_DEC_SW_SUPPORT__ */

#if defined(__MPEG4_ENC_SW_SUPPORT__)
#define DCM_COMP_SCAT_MP4ENC_AVAILABLE         /* MP4ENC with compression */
#endif /* __MPEG4_ENC_SW_SUPPORT__ */

#if defined(__H264_DEC_SW_SUPPORT__)
#define DCM_COMP_SCAT_H264DEC_AVAILABLE        /* H264DEC with compression */
#endif /* __H264_DEC_SW_SUPPORT__ */

/* define target pool information */
#define DCM_COMP_TARGET_NUM        3

#if defined(DCM_COMP_SCAT_SBC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_SBC$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#elif defined(DCM_COMP_SCAT_RESAMPLE_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS1   ((kal_uint32)&Image$$DYNAMIC_COMP_RESAMPLE$$Base)
#define DCM_COMP_TARGET_SIZE1      0x2000      /* 8KB */
#else
#define DCM_COMP_TARGET_ADDRESS1   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE1      0x0
#endif

#if defined(DCM_COMP_SCAT_BESLOUDNESS_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS2   ((kal_uint32)&Image$$DYNAMIC_COMP_BESLOUDNESS$$Base)
#define DCM_COMP_TARGET_SIZE2      0x3400      /* 13KB */
#else
#define DCM_COMP_TARGET_ADDRESS2   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE2      0x0
#endif

#if defined(DCM_COMP_SCAT_MP4DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_MP4ENC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_MP4ENC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#elif defined(DCM_COMP_SCAT_H264DEC_AVAILABLE)
#define DCM_COMP_TARGET_ADDRESS3   ((kal_uint32)&Image$$DYNAMIC_COMP_H264DEC$$Base)
#define DCM_COMP_TARGET_SIZE3      0x21000      /* 135KB */
#else
#define DCM_COMP_TARGET_ADDRESS3   DCMGR_INVALID_VAL
#define DCM_COMP_TARGET_SIZE3      0x0
#endif

/* 
 * setup target pool by code id
 * 0 : DCM with compression candidate unavailable
 * 1 : DCM with compression target pool 1
 * 2 : DCM with compression target pool 2
 * 3 : DCM with compression target pool 3
 */
#define DCM_COMP_TARGET_CONFIGURE  1,1,2,3,3,3

#else

#error Overlay region for dynamic code relocation with compression should be determined for new chipset

#endif /* MTxxxx_SERIES_DCMGR */

#endif /* __DCM_WITH_COMPRESSION__ */

/* Dynamic code manager for relocate code into the overlay TCM region */
void DCM_Load( kal_int32 dynamic_code_id, kal_uint32 **remaining_buf, kal_uint32 *buf_size );
void DCM_Unload( kal_int32 dynamic_code_id );
kal_bool DCM_Isloaded( kal_int32 dynamic_code_id );
kal_bool DCM_IsAvailable( kal_int32 dynamic_code_id );

#endif /* __MTK_TARGET__ */

#endif  /* !__DCMGR_H */

