/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	   ctm_params.h
 *
 * Project:
 * --------
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifdef __CTM_SUPPORT__

#ifndef _CTM_PARAMS_H_
#define _CTM_PARAMS_H_

//--------------------------------------------------------------------
//#define L1CTM_DEBUG_MODE    // used in ep_engine\ctm\*.*
                              // used in l1audio\l1ctm.c

   #if defined(L1CTM_DEBUG_MODE)
#define SAVE_ONLY_TTY_CHAR
      #ifdef SAVE_ONLY_TTY_CHAR
#define BURST_START_CHAR   '#'
#define BURST_END_CHAR     '*'
      #endif
   #endif /* L1CTM_DEBUG_MODE */

//--------------------------------------------------------------------
// Count number of continuous symblos burst without IDLE
// for detection of test case 7-2 (2006-06-15 Jinfa)
#define DYNAMIC_IDLE_MISS_HNDL_BIT7_CHEAT                // used in ctm_receiver.c
#define THRESHOLD_IDLE_MISS_HNDL_BIT7_CHEAT     20
//--------------------------------------------------------------------
// If handover happened, disable the IDLE MISS HANDLE mechanism ## 
// CTM characters
#define HANDOVER_DISABLE_IDLEMISS_HANDLE_NO     20       // Number of CTM characters

//--------------------------------------------------------------------
// Map all UTF code into Baudot code set (2006-06-28 Jinfa)
#define SUPER_BIT_CHEAT                                  // used in ctm_receiver.c
//--------------------------------------------------------------------
#define CPRM_MASK_DOWN_SAMP                     0x01
#define CPRM_MASK_BIT7_CHEAT                    0x02
#define CPRM_MASK_IDLE_MISS_HNDL                0x04

#define CPRM_MASK_REC_DL_PCM_OUT                0x08     // used in l1ctm.c
#define CPRM_MASK_REC_DL_PCM_IN                 0x10     // used in l1ctm.c
#define CPRM_MASK_REC_UL_PCM_OUT                0x20     // used in l1ctm.c
#define CPRM_MASK_REC_UL_PCM_IN                 0x40     // used in l1ctm.c
#define CPRM_MASK_REC_RX_BUF                    0x80     // used in l1ctm.c
#define CPRM_MASK_ALWAYS_NEGO_SUC               0x100    // used in l1ctm.c
#define CPRM_MASK_MORE_ENQUIRY                  0x200    // used in l1ctm.c

////////////////////////////////////////////
#define CPRM_BAUDOT_BIT_DURATION                176
#define CPRM_BFI_SHIFT                          2
#define CPRM_TH_RELIABILITY                     100
#define CPRM_NUM_MUTE_BIT                       25

#define CPRM_ALPHA                              32113
#define CPRM_ONE_MINUS_ALPHA                    655
#define CPRM_ALPHA2                             32440
#define CPRM_TH_A                               (8 + (10 << 8))
#define CPRM_AVE_EARLY_MUTED_BIT                250

#define CPRM_SCAL_FACTOR                        23170
#define CPRM_WAIT_SYNC_REL_THRESHOLD2           25265
#define CPRM_WAIT_SYNC_REL_THRESHOLD1           17500
#define CPRM_RESYNC_REL_THRESHOLD               26542

#define CPRM_THRESHOLD_RELIABILITY_FOR_XCORR    800
#define CPRM_THRESHOLD_RELIABILITY_FOR_XCORR2   8
#define CPRM_NUM_BITS                           (40 + (48 << 8))
#define CPRM_SEARCH_RANGE_PREAMBLE              80

#define CPRM_SEARCH_RANGE_RESYNC                40
#define CPRM_TH_SAMPLING_CORRECTION             40
#define CPRM_TONE_DEMOD_DOWN_SAMP               (CPRM_MASK_DOWN_SAMP)

   #if defined(MT6225)
#define CPRM_NULL_TH                            16500
#define CPRM_WAIT_SYNC_REL_THRESHOLD0           18500
#define CPRM_DELAY_SYNC_REL_THRESHOLD           12100
#define CPRM_CODEBOOK_GAIN_THRESHOLD            3000
#define CPRM_CODEBOOK_GAIN_VALUE                2300
   #elif defined(MT6229) || defined(MT6268T) || defined(TK6516) 
#define CPRM_NULL_TH                            20480
#define CPRM_WAIT_SYNC_REL_THRESHOLD0           20316
#define CPRM_DELAY_SYNC_REL_THRESHOLD           11796
#define CPRM_CODEBOOK_GAIN_THRESHOLD            4000
#define CPRM_CODEBOOK_GAIN_VALUE                2000
   #else
/*For BB which support SAIC*/
#define CPRM_NULL_TH                            20480
#define CPRM_WAIT_SYNC_REL_THRESHOLD0           20316
#define CPRM_DELAY_SYNC_REL_THRESHOLD           11796
#define CPRM_CODEBOOK_GAIN_THRESHOLD            3000
#define CPRM_CODEBOOK_GAIN_VALUE                2800
   #endif
////////////////////////////////////////////

#endif // _CTM_PARAMS_H_
#endif // __CTM_SUPPORT__

