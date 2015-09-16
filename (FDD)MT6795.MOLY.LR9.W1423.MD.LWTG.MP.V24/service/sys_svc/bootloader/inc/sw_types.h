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
 *   sw_types.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   Common type and structure definition
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
 
#ifndef __SW_TYPES_H
#define __SW_TYPES_H


/*
 * general definitions
 */
typedef signed char                       int8;
typedef signed short                      int16;
typedef signed long                       int32;
typedef signed int                        intx;
typedef unsigned char                     uint8;
typedef unsigned short                    uint16;
typedef unsigned long                     uint32;
typedef unsigned int                      uintx;
                                          
typedef unsigned char                     U8;
typedef signed char                       S8;
typedef unsigned short                    U16;
typedef signed short                      S16;
typedef unsigned int                      U32;
typedef signed int                        S32;
                                          
typedef unsigned char                     US8;
typedef unsigned short                    US16;
typedef unsigned int                      US32;

typedef volatile unsigned char *          P_U8;
typedef volatile signed char *            P_S8;
typedef volatile unsigned short *         P_U16;
typedef volatile signed short *           P_S16;
typedef volatile unsigned int *           P_U32;
typedef volatile signed int *             P_S32;
                                          
typedef volatile const unsigned char *    CONST_P_U8;
typedef volatile const signed char *      CONST_P_S8;
typedef volatile const unsigned short *   CONST_P_U16;
typedef volatile const signed short *     CONST_P_S16;
typedef volatile const unsigned int *     CONST_P_U32;
typedef volatile const signed int *       CONST_P_S32;

#if !defined(WIN32)
typedef unsigned long long                U64;
typedef signed long long                  S64;
typedef unsigned long long *              P_U64;
typedef signed long long *                P_S64;
#endif

#ifndef __cplusplus
typedef unsigned char  bool;
#endif

/*
 * Definitions for BOOLEAN
 */

#define FALSE          0
#define TRUE           1

#include "kal_general_types.h"

#endif
