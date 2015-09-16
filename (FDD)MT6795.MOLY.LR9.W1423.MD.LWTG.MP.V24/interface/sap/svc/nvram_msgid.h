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
 *  Copyright Statement:
 *  --------------------
 *  This software is protected by Copyright and the information contained
 *  herein is confidential. The software may not be copied and the information
 *  contained herein may not be used or disclosed except with the written
 *  permission of MediaTek Inc. (C) 2001
 *
 *******************************************************************************/

 /*******************************************************************************
 * Filename:
 * ---------
 *   nvram.sap
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   NVRAM related message identity definition
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
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!! 
 *==============================================================================
 *******************************************************************************/
#include "module_msg_range.h"

#ifndef _NVRAM_MSG_H
#define _NVRAM_MSG_H

MODULE_MSG_BEGIN( MSG_ID_NVRAM_CODE_BEGIN )
#ifdef __BUILD_DOM__
/**************************************************************************************
 * Description
 * <pre>
 *  This message is used to get NVRAM state so that L4C could go on the protocol
 *  startup procedure.
 * </pre>
 * Note
 *   L4C -> NVRAM
 * See Also
 *   Local Parameter: nvram_startup_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_STARTUP_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  If initialization failed, NVRAM will response NVRAM_STARTUP_CNF primitive
 *  along with an error number described the reason. Otherwise, NVRAM keeps silent.
 * </pre>
 * Note
 *   NVRAM -> L4C
 * See Also
 *   Local Parameter: nvram_startup_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_STARTUP_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  NVRAM_RESET_REQ should be sent to NVRAM task to reset data items, i.e., logical data items,
 *  could be a single data item or a certain category of data item.
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_reset_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_RESET_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  NVRAM_RESET_CNF returns the result of NVRAM_RESET_REQ. The return status is encoded in errno.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_reset_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_RESET_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Reads a data item given by its logical data item ID. For linear fixed EF, a valid
 *  record index must be provided.
 *  PS. The index of first record is 1
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_read_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_READ_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns actual content of the specified data item. Result of the corresponding
 *  read primitive is also returned in errno.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_read_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_READ_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Writes a transparent EF given by its logical data item ID. For linear fixed EF,
 *  a valid record index must be provided.
 *  1.  For linear fixed EF, the index of first record is 1.
 *  2.  NVRAM Layer frees the buffer immediately after written.
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_write_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the corresponding write primitive. Return status is encoded in errno.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_write_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_CNF

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_write_imei_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_IMEI_REQ

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_write_imei_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_IMEI_CNF

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_read_sm_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_READ_SM_REQ

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_read_sm_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_READ_SM_CNF

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_write_sm_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_SM_REQ

/**************************************************************************************
 * Description
 * <pre>
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_write_sm_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_WRITE_SM_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Turn on or turn off the NVRAM software lock.
 * </pre>
 * Note
 *   APP -> NVRAM
 * See Also
 *   Local Parameter: nvram_set_lock_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_SET_LOCK_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the corresponding SET LOCK primitive. Return status is encoded
 *  in following ENUM
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_set_lock_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_SET_LOCK_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  1. Create a backup image of nvram into backup partition
 *  2. Clear the data in backup partition
 * </pre>
 * Note
 *   App -> NVRAM
 * See Also
 *   Local Parameter: nvram_create_image_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_CREATE_IMAGE_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the corresponding CREATE IMAGE primitive.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_create_image_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_CREATE_IMAGE_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Recover the data in backup partition back to NVRAM
 * </pre>
 * Note
 *   App -> NVRAM
 * See Also
 *   Local Parameter: nvram_recover_image_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_RECOVER_IMAGE_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the corresponding RECOVER IMAGE primitive.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_recover_image_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_RECOVER_IMAGE_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Verify the data in backup partition to check the data integrity.
 *  There are three steps.
 *  1. Check the status of image (close or broken)
 *  2. Check the checksum of image.
 *  3. Compare the value with NVRAM's
 *  NVRAM also provides a fast mode to execute the step 1 only.
 * </pre>
 * Note
 *   App -> NVRAM
 * See Also
 *   Local Parameter: nvram_verify_image_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_VERIFY_IMAGE_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the corresponding VERIFY IMAGE primitive.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_verify_image_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_VERIFY_IMAGE_CNF

/**************************************************************************************
 * Description
 * <pre>
 *  Suspend the NVRAM task, you can assign the time in structure
 *  ex:
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_suspend_req_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_SUSPEND_REQ

/**************************************************************************************
 * Description
 * <pre>
 *  Returns the result of the suspend request.
 * </pre>
 * Note
 *   NVRAM -> App
 * See Also
 *   Local Parameter: nvram_suspend_cnf_struct
 **************************************************************************************/
#define MSG_ID_NVRAM_SUSPEND_CNF

/**************************************************************************************
* Description
* <pre>
*  Backup FAT data items to SDS
* </pre>
* Note
*   App -> NVRAM
* See Also
*   Local Parameter: nvram_sds_req_struct
**************************************************************************************/
#define MSG_ID_NVRAM_SDS_REQ


/**************************************************************************************
* Description
* <pre>
*  Returns the result of the backup to SDS request.
* </pre>
* Note
*   NVRAM -> App
* See Also
*   Local Parameter: nvram_sds_cnf_struct
**************************************************************************************/
#define MSG_ID_NVRAM_SDS_CNF

/**************************************************************************************
* Description
* <pre>
*  Backup FAT data items to SDS
* </pre>
* Note
*   App -> NVRAM
* See Also
*   Local Parameter: nvram_bin_region_req_struct
**************************************************************************************/
#define MSG_ID_NVRAM_BIN_REGION_REQ

/**************************************************************************************
* Description
* <pre>
*  Returns the result of the backup to AP BIN region request.
* </pre>
* Note
*   NVRAM -> App
* See Also
*   Local Parameter: nvram_bin_region_cnf_struct
**************************************************************************************/
#define MSG_ID_NVRAM_BIN_REGION_CNF

#else

    MSG_ID_NVRAM_STARTUP_REQ = MSG_ID_NVRAM_CODE_BEGIN,
    MSG_ID_NVRAM_STARTUP_CNF,
    MSG_ID_NVRAM_RESET_REQ,
    MSG_ID_NVRAM_RESET_CNF,
    MSG_ID_NVRAM_READ_REQ,
    MSG_ID_NVRAM_READ_CNF,
    MSG_ID_NVRAM_WRITE_REQ,
    MSG_ID_NVRAM_WRITE_CNF,
    MSG_ID_NVRAM_WRITE_IMEI_REQ,
    MSG_ID_NVRAM_WRITE_IMEI_CNF,
    MSG_ID_NVRAM_READ_SM_REQ,
    MSG_ID_NVRAM_READ_SM_CNF,
    MSG_ID_NVRAM_WRITE_SM_REQ,
    MSG_ID_NVRAM_WRITE_SM_CNF,
    MSG_ID_NVRAM_SET_LOCK_REQ,
    MSG_ID_NVRAM_SET_LOCK_CNF,
    MSG_ID_NVRAM_CREATE_IMAGE_REQ,
    MSG_ID_NVRAM_CREATE_IMAGE_CNF,
    MSG_ID_NVRAM_RECOVER_IMAGE_REQ,
    MSG_ID_NVRAM_RECOVER_IMAGE_CNF,
    MSG_ID_NVRAM_VERIFY_IMAGE_REQ,
    MSG_ID_NVRAM_VERIFY_IMAGE_CNF,
    MSG_ID_NVRAM_SUSPEND_REQ,
    MSG_ID_NVRAM_SUSPEND_CNF,
    MSG_ID_NVRAM_SDS_REQ,
    MSG_ID_NVRAM_SDS_CNF,
    MSG_ID_NVRAM_BIN_REGION_REQ,
    MSG_ID_NVRAM_BIN_REGION_CNF,
    MSG_ID_NVRAM_RESERVED_1,
    MSG_ID_NVRAM_RESERVED_2,
    MSG_ID_NVRAM_RESERVED_3,
    MSG_ID_NVRAM_RESERVED_4,
    MSG_ID_NVRAM_RESERVED_5,
    MSG_ID_NVRAM_RESERVED_6,
    MSG_ID_NVRAM_MAX,
    MSG_ID_NVRAM_CODE_END = MSG_ID_NVRAM_MAX,

#endif
MODULE_MSG_END( MSG_ID_NVRAM_CODE_TAIL )

#endif  //_NVRAM_MSG_H
