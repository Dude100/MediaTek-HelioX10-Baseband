/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2008
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
 *   br_GFH_error.h
 *
 * Project:
 * --------
 *   GFH
 *
 * Description:
 * ------------
 *   GFH error code 
 *
 * Author:
 * -------
 * -------
 *
 ****************************************************************************/
#ifndef __BR_GFH_ERROR_H__
#define __BR_GFH_ERROR_H__

#define B_OK                                            0x0000
#define E_ERROR                                         0x00FF

//==============================================================================
// Public GFH status code, from 0x8000 to 0x80FF
// Note: DO NOT CHANGE IT!!
//==============================================================================

#define E_GFH_HANDLE_NOT_INIT                           0x8000
#define E_GFH_NOT_FOUND                                 0x8001
#define E_GFH_INVALID_PARAM                             0x8002
#define E_GFH_CALLBACK_MAP_IS_FULL                      0x8003
#define E_GFH_INVALID_SIZE                              0x8004
#define E_GFH_FILE_INFO_NOT_FOUND                       0x8005
#define E_GFH_FILE_INFO_INVALID_CONTENT_OFFSET          0x8006
#define E_GFH_FILE_INFO_INVALID_FILE_LEN                0x8007
#define E_GFH_FILE_INFO_INVALID_SIG_LEN                 0x8008
#define E_GFH_FILE_INFO_FILE_LEN_EXCEED_MAX_SIZE        0x8009
#define E_GFH_FILE_INFO_INVALID_JUMP_OFFSET             0x800A
#define E_GFH_CALLBACK_NOT_EXIST                        0x800B
#define E_GFH_BUF_ADDR_NOT_32BITS_ALIGNED               0x800C

#endif /* __GFH_ERROR_H__ */

