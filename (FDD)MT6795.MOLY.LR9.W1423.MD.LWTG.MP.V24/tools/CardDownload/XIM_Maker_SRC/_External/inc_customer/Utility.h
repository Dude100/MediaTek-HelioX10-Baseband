/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2006
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

#ifndef _UTILITY_H_
#define _UTILITY_H_

#pragma warning(disable:4786)

#include <string>
#include <vector>
#include "br_GFH.h"
#include "br_GFH_file_info.h"
#include "br_GFH_dl_package_info.h"

using namespace std;





typedef struct
{
    GFH_FILE_INFO_v1        gfh_file_info;
    GFH_DL_PACKAGE_INFO_v2  gfh_dl_package_info;
} DL_PACKAGE_GFH;

bool CreateHeaderXIM(const int ImageDevice,
                     const string& platformID,
                     const string& projectID,
                     const bool debugFlagBL,
                     const int IMFileSize,
                     const int signatureSize,
                     DL_PACKAGE_GFH& XIM_header,
                     GFH_DL_PACKAGE_EXTRA_INFO* extraInfo,
                     unsigned int extraInfoSize);

bool ReadIMFileAndHeaderSize(IM_FORMAT imFormat, const string& IMFile, 
                             vector<unsigned char>& content,int& header_size);

unsigned int GetFileSize(const string &filename);

bool GetFileContent(vector<unsigned char> &content, const string &filename);

bool IsNandBootInROMINFO(const vector<unsigned char>& content);

bool CompareWithoutCaseSensitive(string source, string target);
bool FindStringWithoutCaseSensitive(string source, string target);

bool GetOperationFromINI(const string& binTypeName, const string& configFile, int& operation);
bool GetStartAddrFromINI(const string& binTypeName, const string& configFile, 
						 GFH_DL_PACKAGE_EXTRA_INFO* extraInfo, 
						 int indexOfExtraInfo, unsigned int& startAddr);
bool GetSizeFromINI(const string& binTypeName, const string& configFile, unsigned int& size);
bool FillExtraInfoByBinType(const string& configFile, const IM_FORMAT& imFormat,
							const string& binType, const GFH_FILE_TYPE& binTypeEnum,
						    GFH_DL_PACKAGE_EXTRA_INFO* extraInfo, int& indexOfExtraInfo);

bool CheckAllBinFileInfoByDevice(const IM_FORMAT imFormat, 
									  const GFH_DL_PACKAGE_EXTRA_INFO* extraInfo,
									  int extraInfoSize);


//void InitBinTypeMTK(vector<string>& binTypeVector, vector<GFH_FILE_TYPE>& binTypeEnumVector);
unsigned int HexStrToUnsignedInt(string str);
bool GetProfileSectionFromINI(const string& configFile, vector<string>& sections);

typedef enum
{
	MTK_BIN_UNKNOWN = 0,
	MTK_BIN_MAUI,
	MTK_BIN_RESOUCE,
	MTK_BIN_CUSTOM,
	MTK_BIN_FILE_SYSTEM
}MTK_BIN_TYPE_E;

MTK_BIN_TYPE_E CheckBinType(const string& binName);
GFH_FILE_TYPE GetMauiFileTypeByString(const string& str);
GFH_FILE_TYPE GetCutomeFileTypeByString(const string& str);
#endif
