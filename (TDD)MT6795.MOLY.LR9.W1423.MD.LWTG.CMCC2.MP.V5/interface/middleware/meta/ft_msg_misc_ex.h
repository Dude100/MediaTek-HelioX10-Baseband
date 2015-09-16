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
*  Modification Notice:
*  --------------------------
*  This software is modified by MediaTek Inc. and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   ft_msg_misc_ex.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of MISC_EX category of FT Library
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
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/

#ifndef __FT_MSG_MISC_EX_H__
#define __FT_MSG_MISC_EX_H__
#include "ft_msg_common.h"

typedef enum
{
     FT_MISC_EX_OP_GET_ERS_SIZE = 0
    ,FT_MISC_EX_OP_GET_ERS_DATA
    ,FT_MISC_EX_OP_GET_ERS_COUNT
    ,FT_MISC_EX_OP_GET_ERS_DATA_INFO_BY_INDEX
    ,FT_MISC_EX_OP_COPY_NVRAM_TO_BP_AREA
    ,FT_MISC_EX_OP_VERIFY_BP_AREA
    ,FT_MISC_EX_OP_OBSOLETED1
    ,FT_MISC_EX_OP_OBSOLETED2
    ,FT_MISC_EX_OP_BACKUP_TO_SDS
    ,FT_MISC_EX_OP_RAMDISK_CHECK_EXIST   /**< \brief check ram disk is existing or not */
    ,FT_MISC_EX_OP_RAMDISK_GET_SIZE      /**< \brief get ram disk size */
    ,FT_MISC_EX_OP_RAMDISK_READ          /**< \brief read from ram disk */
    ,FT_MISC_EX_OP_SET_COMMAND_TO_SYSTEM /**< \brief set/clr download flag */    
    ,FT_MISC_EX_OP_END
}FT_MISC_EX_CMD_TYPE;



typedef union
{
    kal_uint32 Dummy;
    kal_int32  m_i4ErsDataIndex;
    kal_uint8  u1BPAreaFastCheck;
    kal_uint32 mode;
    kal_uint32 m_u4RamDiskReqOffset;
    kal_uint32 m_u4SetCmd2System;
}FT_MISC_EX_CMD_U;

typedef struct
{
   kal_uint8 sec;
   kal_uint8 min;
   kal_uint8 hour;
   kal_uint8 day;
   kal_uint8 mon;
   kal_uint8 wday;
   kal_uint8 year;
}FT_MISC_EX_RCT_INFO_T;


typedef struct
{
  kal_uint32 m_u4TotalSize;
    kal_uint32 m_u4CurOffset;
    kal_bool   m_bLastFrm;


}FT_MISC_EX_GET_ERS_DATA_CNF_T;

typedef union
{

   kal_uint32 m_u4ErsDataSize;
   kal_int32   m_i4ErsDataCount;
   FT_MISC_EX_GET_ERS_DATA_CNF_T  m_rErsDataFrm;
   FT_MISC_EX_RCT_INFO_T    m_rErsDataTime;
   kal_uint32  m_u4BPStatus;
   kal_uint32  m_u4SDSStatus;
   kal_uint32  m_u4RamDiskSize;
   FT_MISC_EX_GET_ERS_DATA_CNF_T  m_rRamDiskFrm;   
   kal_int8    m_cRamDiskExist;   
}FT_MISC_EX_CNF_U;




typedef struct
{
    FT_H               header;
    FT_MISC_EX_CMD_TYPE     type;
    FT_MISC_EX_CMD_U     cmd;

}FT_MISC_EX_REQ;

typedef struct
{
    FT_H               header;
    FT_MISC_EX_CMD_TYPE   type;
    kal_uint32                status;
    FT_MISC_EX_CNF_U      result;
}FT_MISC_EX_CNF;

#endif // #ifndef __FT_MSG_MISC_EX_H__
