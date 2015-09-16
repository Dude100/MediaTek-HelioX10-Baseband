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
 *   srd_dl_ctrl.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __BOOT_CERT_PATTERN_H__
#define __BOOT_CERT_PATTERN_H__


#include "GFH_defs.h"
#include "br_GFH_error.h"
#include "br_GFH.h"
#include "br_GFH_file_info.h"

/* Structure embedded in binary for V1 */
typedef struct {
   kal_char      m_identifier[16];
   kal_uint32    m_ver;
   kal_uint32    m_dl_ctrl_addr;
   kal_char      m_dl_ctrl_pattern[128];

} MTK_SRDInfo_v01_ST;


/* Structure embedded in binary for V2 */
typedef struct {
   kal_char      m_identifier[16];
   kal_uint32    m_ver;
   kal_uint32    m_dl_ctrl_addr;
   kal_char      m_dl_ctrl_pattern[128];
   kal_char      m_dl_c_chksum[32];

} MTK_SRDInfo_v02_ST;



typedef struct
{
    GFH_Header              dl_ctrl_content;
    kal_char                pattern1[128];
    kal_char                pattern2[128];
    kal_char                pattern3[128];
    kal_char                pattern4[128];
}GFH_BOOT_CERT_CTRL_CONTENT_v1;


typedef struct
{
    GFH_FILE_INFO_v1                dl_ctrl_fileinfo;
    GFH_BOOT_CERT_CTRL_CONTENT_v1   dl_ctrl_content;

}DL_CTRL_FORMAT_ST;


/* ------------------------------------ */
/* Extern data & function */
/* ------------------------------------ */
#if defined(__BOOT_CERT_V1__)
extern const MTK_SRDInfo_v01_ST g_SRD_INFO;
#elif defined(__BOOT_CERT_V2__)
extern const MTK_SRDInfo_v02_ST g_SRD_INFO;
#endif 
extern const DL_CTRL_FORMAT_ST DL_CTRL_BIN;



#endif   /* __BOOT_CERT_PATTERN_H__ */

