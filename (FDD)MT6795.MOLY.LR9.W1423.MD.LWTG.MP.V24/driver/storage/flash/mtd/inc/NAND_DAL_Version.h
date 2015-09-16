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
 *  NAND_DAL_VERSION.H
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *   DAL and FDM version definition
 *
 * Author:
 * -------
 * -------
 *
 *==============================================================================
 *              HISTORY
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
#ifndef NAND_DAL_VERSION_H
#define NAND_DAL_VERSION_H

// Define Max satck size for demand paging
#define MAX_DEMAND_STACK_USED_BY_NAND_DRIVER		500
 
#if defined __NAND_FDM_50__

#define FDM_MARK 'F'
/* FDM version information */
#if defined(__NANDFDM_MULTI_INSTANCE__)
  #if defined(__NANDFDM_TOTAL_BBM__)
    #define FDM_VERSION     0x52
    #define FDM_MAJOR_VER   (5)
    #define FDM_MINOR_VER1  (2)
    #define FDM_MINOR_VER2  (0)
  #else
    #define FDM_VERSION     0x51
    #define FDM_MAJOR_VER   (5)
    #define FDM_MINOR_VER1  (1)
    #define FDM_MINOR_VER2  (0)
  #endif //defined(__NANDFDM_TOTAL_BBM__)
#else
  #define FDM_VERSION     0x50
  #define FDM_MAJOR_VER   (5)
  #define FDM_MINOR_VER1  (0)
  #define FDM_MINOR_VER2  (0)
  #define FDM_MINOR_VER2_EN_REPLACECNT (1)
#endif // defined(__NANDFDM_MULTI_INSTANCE__)
#define DAL_MARK 'D'
#if defined(__NFI_VERSION3_1__)
  #define DAL_MAJOR_VER   (0)
  #if defined(__ECC_8_BIT_SUPPORT__) && defined(__NAND_MDL_APPEND__)
  #define DAL_MINOR_VER1  (1)
  #else
  #define DAL_MINOR_VER1  (0)
  #endif
  #if defined(MT6255) || defined(MT6280)
  	#define DAL_VERISON     0x05	// ECC 8 bits
    #define DAL_MINOR_VER2  (5)  	  	
  #elif defined(MT6256)
  	#define DAL_VERISON     0x03	// ECC 12 bits
    #define DAL_MINOR_VER2  (3)  	  	
  #else
  	#define DAL_VERISON     0x02  // ECC 4 bit for MT6276
    #define DAL_MINOR_VER2  (2)  	
  #endif
#else
  #define DAL_VERISON     0x01
  #define DAL_MAJOR_VER   (0)
  #define DAL_MINOR_VER1  (0)
  #define DAL_MINOR_VER2  (1)
#endif


#endif /*__NAND_FDM_50__*/
#endif /*NAND_DAL_VERSION_H*/
