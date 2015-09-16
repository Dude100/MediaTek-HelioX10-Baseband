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
 *   ft_msg.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Messages definition of FT task
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
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
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

#ifndef FT_MSG_H
#define FT_MSG_H


#include "kal_public_api.h"
#include "med_struct.h"
#include "fs_type.h"
#include "kal_general_types.h"
#include "ft_msg_common.h"

/*******************************************************************************
*
*  Message structures defined for NVRAM Interface
*
*******************************************************************************/

typedef struct {
   FT_H			header;
   kal_uint32	dummy;
} FT_NVRAM_GET_DISK_INFO_REQ;

typedef struct {
   FT_H			header;
   kal_uint8	status;
   kal_uint32	diskfilesize;
   kal_uint32	freespace;
   kal_uint32	overhead;
} FT_NVRAM_GET_DISK_INFO_CNF;

typedef struct
{
   FT_H            header;
   kal_uint8       poweron_mode;
}ft_nvram_startup_req_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint8       status;
}ft_nvram_startup_cnf_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint8       reset_category;
   kal_uint16      file_idx;
}ft_nvram_reset_req_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint8       status;
}ft_nvram_reset_cnf_struct_T;

/********************************************
* Generic Primitives for READ/WRITE NVRAM
********************************************/
typedef struct
{
   FT_H            header;
   kal_uint16      file_idx;
   kal_uint16      para;
   kal_uint8       status; 
} ft_nvram_read_cnf_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint16      file_idx;
   kal_uint16      para;
   kal_uint8       ciphered_data_valid;
   kal_uint8       ciphered_data[4];
} ft_nvram_read_req_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint16      file_idx;
   kal_uint16      para;
   kal_uint16      rec_amount;         /*  total record to read */
   kal_uint8       *buffer;            /*  buffer to fill in data */
   kal_uint32      buf_size;           /*  buffer size */

} ft_nvram_read_sm_req_struct_T;


typedef struct
{
   FT_H            header;
   kal_uint16      file_idx;
   kal_uint16      para;
   kal_uint8       status;
} ft_nvram_write_cnf_struct_T;

typedef struct
{
   FT_H            header;
   kal_uint16      file_idx;
   kal_uint16      para;
   kal_uint8       msg_num;
   kal_uint8       msg_idx;
} ft_nvram_write_req_struct_T;

typedef struct {
	FT_H			header;
	kal_uint8		lock_en;
} ft_nvram_lock_req_struct_T;

typedef struct {
	FT_H			header;
	kal_uint8		status;
} ft_nvram_lock_cnf_struct_T;
  
/*******************************************************************************
*
*  Message structures defined for BaseBand Interface
*
*******************************************************************************/
typedef enum
{
     FT_MT_UNKNOWN =0,
     FT_MT6305,
     FT_MT6318,
     FT_MT6326,
     FT_PMIC_END
}ft_PMICType;

typedef enum
{
	FT_BaseBandReg = 0,
	FT_PMICReg	
}ft_RegisterType;
typedef struct
{
  FT_H                  header;
  kal_uint32            addr;
} ft_RegisterRead_req_T;

typedef struct
{
  FT_H                  header;
  kal_uint16            value;
  kal_uint8             status;
} ft_RegisterRead_cnf_T;

typedef struct
{
  FT_H                  header;
  kal_uint32            addr;
  kal_uint16            value;
} ft_RegisterWrite_req_T;

typedef struct
{
  FT_H                  header;
  kal_uint8             status;
} ft_RegisterWrite_cnf_T;
typedef struct
{
  FT_H                  header;
  kal_uint32            addr;
} ft_PMICRegisterRead_req_T;
typedef struct
{
  FT_H                  header;
  kal_uint16            value;
  kal_uint8             status;
} ft_PMICRegisterRead_cnf_T;
typedef struct
{
  FT_H                  header;
  kal_uint32            addr;
  kal_uint16            value;
} ft_PMICRegisterWrite_req_T;
typedef struct
{
  FT_H                  header;
  kal_uint8             status;
} ft_PMICRegisterWrite_cnf_T;

typedef struct
{
  FT_H                  header;
  kal_uint8             Sel;
  kal_uint16            Meacount; 
} ft_FtADC_GetMeaData_req_T;
typedef struct
{
  FT_H                  header;
  kal_uint32            value;
  kal_uint8             status;
} ft_FtADC_GetMeaData_cnf_T;

/*******************************************************************************
*
*  Message structures defined for FAT Interface
*
*******************************************************************************/

#define FT_FAT_ERR_PATH_TOO_LONG	-500
#define FT_FAT_ERR_PATH_RESTRICTION	-501
#define FT_FAT_ERR_DIR_NOT_EXIST	-502
#define FT_FAT_ERR_ACTION_NOT_SUPPORT - 503

typedef enum {
	 FT_FAT_OP_OPEN = 1
	,FT_FAT_OP_READ = 2
	,FT_FAT_OP_WRITE = 4
	,FT_FAT_OP_CLOSE = 8
	,FT_FAT_OP_FILESIZE
	,FT_FAT_OP_DELETE
	,FT_FAT_OP_MOVE
	,FT_FAT_OP_FIND_FILE
	,FT_FAT_OP_FIND_FILE_RECURSIVE
	,FT_FAT_OP_FIND_DIR_RECURSIVE
	,FT_FAT_OP_GET_DISK_INFO
	,FT_FAT_OP_RMDIR
	,FT_FAT_OP_GET_DRIVE_TYPE
	,FT_FAT_OP_END
}FT_FAT_OP;

typedef struct
{
	FT_H		header;
	FT_FAT_OP	fat_op;
	FS_HANDLE	fs_handle;
	kal_int32	offset;
	kal_uint8	last_frame;
	kal_int32	status;

}FT_FAT_OPERATION;

typedef struct {
	kal_uint32	Type;
	kal_uint32	SectorsPerCluster;
	kal_uint32	TotalClusters;
	kal_uint32	FreeClusters;
}FT_FAT_DiskInfo_T;

typedef struct {
	kal_int32	filesize;
}FT_FAT_FILESIZE;

/*******************************************************************************
*
*  Message structures defined for Version Info Interface
*
*******************************************************************************/

typedef struct {
	FT_H		header;
}FT_VER_INFO_REQ;

typedef struct {
	FT_H		header;
	kal_uint8	bb_chip[64];
	kal_uint8	eco_ver[4];
	kal_uint8	dsp_fw[64];
	kal_uint8	dsp_patch[64];
	kal_uint8	sw_ver[64];
	kal_uint8	hw_ver[64];
	kal_uint8	melody_ver[64];
}FT_VER_INFO_CNF;

/*******************************************************************************
*
*  Message structures defined for ready confirm
*
*******************************************************************************/

typedef struct {
	FT_H			header;
	kal_uint32		dummy;		// extend alignment to 4 bytes
}FT_IS_ALIVE_REQ;

typedef struct {
	FT_H			header;
	kal_uint32		dummy;		// extend alignment to 4 bytes
}FT_IS_ALIVE_CNF;

/*******************************************************************************
*
*  Message structures defined for power off command
*
*******************************************************************************/

typedef struct {
	FT_H			header;
	kal_uint32		dummy;			// extend alignment to 4 bytes
}FT_POWER_OFF_REQ;

/*******************************************************************************
*
*  Message structures defined for checking META_DLL version 
*
*******************************************************************************/

typedef struct {
	FT_H			header;
	kal_uint32		meta_ver_from_pc;
	kal_uint8		dummy[256];
}FT_CHECK_META_VER_REQ;

typedef struct {
	FT_H			header;
	kal_uint32		meta_ver_required_by_target;
	kal_uint8		dummy[256];
}FT_CHECK_META_VER_CNF;


#include "ft_msg_fta.h"
#include "ft_msg_ftc.h"
#include "ft_msg_l1rf.h"
#include "ft_msg_misc.h"
#include "ft_msg_misc_ex.h"
#include "ft_msg_ul1rf.h"
#include "ft_msg_util.h"
#include "ft_msg_lterf.h"
#endif

