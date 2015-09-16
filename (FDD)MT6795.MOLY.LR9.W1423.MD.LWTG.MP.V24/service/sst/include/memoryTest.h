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
 *   ex_item.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *	Header file for exception handling
 *
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef _MEMORY_TEST_H
#define _MEMORY_TEST_H

/************************************
  *
  * High-level feature options.
  *
  ***********************************/

#if !defined(MT6251)
#define EMI_PERFORMANCE_TEST
#endif /* !MT6251 */


/************************************
  *
  * Definition
  *
  ***********************************/ 
// EMI_PERFORMANCE_TEST_SIZE must >= EMI_STABILITY_TEST_SIZE

#if defined(MT6276) 

#define EMI_PERFORMANCE_TEST_SIZE 1024 // over this value might cause 60Qb assert
#define EMI_STABILITY_TEST_SIZE 256

#elif defined(MT6256) || defined(MT6255)

#define EMI_PERFORMANCE_TEST_SIZE 512
#define EMI_STABILITY_TEST_SIZE 256

#elif defined(MT6268)

#define EMI_PERFORMANCE_TEST_SIZE 512
#define EMI_STABILITY_TEST_SIZE 256

#elif defined(MT6236) || defined(MT6236B) || defined(MT6238) || defined(MT6239) || defined(MT6235) || defined(MT6235B) /* MT6276 || MT6256 || MT6268 */

#define EMI_PERFORMANCE_TEST_SIZE 512
#define EMI_STABILITY_TEST_SIZE 256

#elif defined(MT6253E) || defined(MT6253L) || defined(MT6252) || defined(MT6252H) || defined(MT6253T) || defined(MT6253) || defined(MT6268A) || defined(MT6270A) /* MT6276 || MT6256 || MT6268 */

#define EMI_PERFORMANCE_TEST_SIZE 256
#define EMI_STABILITY_TEST_SIZE 256

#else /* MT6276 || MT6256 || MT6268 */

/**
  * MT6225 || MT6268T || MT6268H || MT6223 || MT6223P
  */
  
#define EMI_PERFORMANCE_TEST_SIZE (KEY_STREAM_LEN)
#define EMI_STABILITY_TEST_SIZE 128

#endif /* MT6276 || MT6256 || MT6268 */


/************************************
  *
  * Enum
  *
  ***********************************/

typedef enum ADV_RAM_TEST_OPTION
{
    ADV_RAM_TEST_OPTION_TEST_DURATION
}ADV_RAM_TEST_OPTION_T;



#endif /* _MEMORY_TEST_H */


