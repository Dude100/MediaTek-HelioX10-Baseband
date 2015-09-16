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

// XIMMaker.cpp : Defines the entry point for the console application.
//


#pragma warning(disable:4786)

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <Windows.h>
#include <fstream>
#include "boost/foreach.hpp"
#include "boost/shared_ptr.hpp"
#include "XGetopt.h"
#include "br_GFH_dl_package_info.h"
#include "DigitalSignature.h"
#include "Utility.h"


#define MAX_EXTRA_INFO_NUM       16

using std::ios_base;
using std::vector;
using std::string;
using std::ifstream;
using std::ofstream;
using std::cout;
using std::endl;
using std::equal;
using std::copy;
using boost::shared_ptr;




static bool AddCurrentDirPathStr(string& file)
{
    vector<char> currentDir(1024, 0);
    
    GetCurrentDirectory(currentDir.size(), &currentDir[0]);    
    file = string(&currentDir[0]) + '\\' + file;
    
    return true;
}

static bool CheckFilePathAbsolute(const string *filepath)
{

	// two kind of path will be regarded as absolute path
	// has :\ , ex: C:\...
	// has \\ , ex: \\xxxxx
	if(filepath->rfind("\\\\") != string::npos || filepath->rfind(":\\") != string::npos)
	{
		return true;
	}
	else
       return false;
}

static bool ParseArguments(int argc, char* argv[], 
                           string& INI_File,
                           string& IM_file, 
                           string& XIM_file)
{
    int arg;
    
    while ((arg = getopt(argc, argv, "s:i:o:")) != EOF)
    {
        switch (arg)
        {
        case 's':
            INI_File = optarg;
			cout << "Get INI File settings" << endl;
            break;
        case 'i':
            IM_file = optarg;
			cout << "Get IM File settings" << endl;
            break;            
        case 'o':
            XIM_file = optarg;
			cout << "Get XIM File settings" << endl;
            break;
        default:
            cout << "WARNING: no handler for option -" << arg << endl;
            return false;
        }
    }

    if (INI_File.empty())
    {
        cout << "Please specify a config file with \"-s\" option" << endl;
        return false;
    }    
    
    if (IM_file.empty())
    {
        cout << "Please specify an input file with \"-i\" option" << endl;
        return false;
    }
    
    if (XIM_file.empty())
    {
        cout << "Please specify an output file with \"-o\" option" << endl;
        return false;
    }
    
    // Add current directory path before the file name
	if(!CheckFilePathAbsolute(&INI_File))
		AddCurrentDirPathStr(INI_File);
	printf("INI_file:%s\n", INI_File.c_str());

	if(!CheckFilePathAbsolute(&IM_file))
       AddCurrentDirPathStr(IM_file);
	printf("IM_file:%s\n", IM_file.c_str());

	if(!CheckFilePathAbsolute(&XIM_file))
	   AddCurrentDirPathStr(XIM_file);    
	printf("XIM_file:%s\n", XIM_file.c_str());


    return true;
}

static bool FileExists(const char *fileName)
{
    return (GetFileAttributes(fileName) != 0xFFFFFFFF);
}

static bool CheckFileExists(const string& file)
{
    if (!FileExists(file.c_str()))
    {
        /*
        string filename = file;
        AddCurrentDirPathStr(filename);
        if (!FileExists(filename.c_str()))
        {*/
            cout << file << " does not exist!" << endl;
            return false;
        /*
        }        
        exist_file = filename;
        */
    }
    return true;
}

void STR2M1(char *str, unsigned short *m1, unsigned int &m1_len) {
    char *p;
    // parse STR to m1 array 
    for(m1_len=0, p=strtok(str, ", \t\r\n"); NULL!=p; m1_len++, p=strtok(NULL, ", \t\r\n")) {
        m1[m1_len] = (unsigned short)(strtoul(p, NULL, 16)&0x0000FFFF);
    }
}

static bool GetConfig(const string& configFile,
                      int&    IM_format,
                      string& platform_id,
                      string& project_id,
                      bool&   BL_debug_flag)              
{
    if(false == CheckFileExists(configFile))
    {
        cout << "ERROR: CheckFileExists() fail!" << endl;
        return false;
    }

	vector<string> sections;
	bool result = GetProfileSectionFromINI(configFile, sections);
	if(!result)
	{
		printf("Fail!\n");
	}
	
	int ret = 0;		

    //
    //  Reade INI file for [XIMGenerator Config] 
    //              
    string sectionName = "XIMGenerator Config";        
    // get IM_format [Must]
    {		
		//IM_format = 1;	// default is NAND
		IM_format = IM_NOR;  // default is NOR or serial Flash
		vector<char> buf(256, 0);
        ret = ::GetPrivateProfileString(sectionName.c_str(), 
                   "ImageDevice", "", &buf[0], buf.size(), configFile.c_str());  
		string imageDevice(&buf[0]);

		if(FindStringWithoutCaseSensitive(imageDevice, "NAND"))
		{
			IM_format = IM_NAND;
		}
		/*
		if(FindStringWithoutCaseSensitive(imageDevice, "NOR"))
		{
			IM_format = 0;
		}
		*/
    }
    // get platform_id [Must]
    {
        vector<char> buf(256, 0);
        ret = ::GetPrivateProfileString(sectionName.c_str(), 
                   "Handset_platform_id_to_apply", "", &buf[0], buf.size(), configFile.c_str());     
        platform_id = reinterpret_cast<char *>(&buf[0]);
        // Check the length of platform ID
        if(platform_id.size() >= 128)
        {
            cout << "ERROR: \"Handset_platform_id_to_apply\" can't accept more than 127 characters." << endl;
            return false;
        }
    }
    // get project_id [Must]
    {
        vector<char> buf(256, 0);
        ret = ::GetPrivateProfileString(sectionName.c_str(), 
                   "Handset_project_id_to_apply", "", &buf[0], buf.size(), configFile.c_str());            
        project_id = reinterpret_cast<char *>(&buf[0]);
        // Check the length of project ID
        if(project_id.size() >= 64)
        {
            cout << "ERROR: \"Handset_project_id_to_apply\" can't accept more than 63 characters." << endl;
            return false;
        }
    }
    // get BL Debug flag [Optional]
    {
		BL_debug_flag = false;
		vector<char> buf(256, 0);
        ret = ::GetPrivateProfileString(sectionName.c_str(), 
			"BL_Debug", "", &buf[0], buf.size(), configFile.c_str());  
		string bootloaderDebugFlag(&buf[0]);
		if(FindStringWithoutCaseSensitive(bootloaderDebugFlag, "ON"))
		{
			cout << "BL Debug ON" << endl;                
			BL_debug_flag = true;
		}		           
    }
    
       
    return true;
}


static bool AppendSignature(const int sigSize,
                            const DL_PACKAGE_GFH& header,
                            const vector<unsigned char>& IMContent,
                            const unsigned int IMHeaderSize,
                            vector<unsigned char>& XIM_content)
{
    vector<unsigned char> sig1(sigSize, 0);
    vector<unsigned char> sig2(sigSize, 0);

    // copy DL_PACKAGE_GFH
    CopyMemory(&XIM_content[0], &header, sizeof(DL_PACKAGE_GFH));   
    
    // copy .IM content
    CopyMemory(&XIM_content[sizeof(DL_PACKAGE_GFH)], &IMContent[0], IMContent.size() );
    
    // Sign (DL_PACKAGE_GFH header + NAND Image Header)
    if(!Sign(&XIM_content[0], sizeof(DL_PACKAGE_GFH)+IMHeaderSize, &sig1[0]))
		return false;
    // Sign (DL_PACKAGE_GFH header + .IM file)
    if(!Sign(&XIM_content[0], sizeof(DL_PACKAGE_GFH)+IMContent.size(), &sig2[0]))
		return false;

    // copy signature
    CopyMemory(&XIM_content[sizeof(DL_PACKAGE_GFH)+IMContent.size()], &sig1[0], sigSize);
    CopyMemory(&XIM_content[sizeof(DL_PACKAGE_GFH)+IMContent.size()+sigSize], &sig2[0], sigSize);

    return true;
}

static bool SaveXIMContent(vector<unsigned char>& XIMContent, string& filename)
{
    ofstream out(filename.c_str(), ofstream::binary | ofstream::out);
    if (!out.is_open())
    {
        cout << "Cannot open \"" << filename << "\"" << endl;
        return false;
    }

    out.write(reinterpret_cast<const char *>(&XIMContent[0]), XIMContent.size());
    out.close();          
    return true;
}

static bool GetAllBinFileInfoByDevice(string& configFile, IM_FORMAT imFormat, 
                                      GFH_DL_PACKAGE_EXTRA_INFO* extraInfo, int extraInfoSize)
{
    if(false == CheckFileExists(configFile))
    {
        cout << "ERROR: CheckFileExists() fail!" << endl;
        return false;
    }
	
	if(imFormat != IM_NAND && imFormat != IM_NOR)
	{
		cout << "ERROR: Unknown IM_FORMAT !" << endl;
        return false;
	}
	
	const unsigned int REMAP_BASE = 0x08000000;
    memset(extraInfo, 0, sizeof(GFH_DL_PACKAGE_EXTRA_INFO)*extraInfoSize);    
	int index = 0;	// index for GFH_DL_PACKAGE_EXTRA_INFO count
	
	vector<string> sectionVectorINI;
	if(!GetProfileSectionFromINI(configFile, sectionVectorINI))
	{
		return false;
	}
	
	for(int i = 0; i < sectionVectorINI.size(); i++)
	{
		MTK_BIN_TYPE_E binType = CheckBinType(sectionVectorINI[i]);
		if(MTK_BIN_UNKNOWN == binType)
		{
			continue;
		}
		else
		{
			switch(binType)
			{
			case MTK_BIN_MAUI:
				if( !FillExtraInfoByBinType(configFile, imFormat,
					sectionVectorINI[i].c_str(), GetMauiFileTypeByString(sectionVectorINI[i]),
					extraInfo, index))
				{
					cout << "ERROR: Fill extraInfo fail!" << endl;
					return false;
				}
				break;
			case MTK_BIN_RESOUCE:
				if( !FillExtraInfoByBinType(configFile, imFormat,
					sectionVectorINI[i].c_str(), V_RESOURCE_BINARY,
					extraInfo, index))
				{
					cout << "ERROR: Fill extraInfo fail!" << endl;
					return false;
				}	
				break;
			case MTK_BIN_CUSTOM:
				if( !FillExtraInfoByBinType(configFile, imFormat,
					sectionVectorINI[i].c_str(), GetCutomeFileTypeByString(sectionVectorINI[i]),
					extraInfo, index))
				{
					cout << "ERROR: Fill extraInfo fail!" << endl;
					return false;
				}
				break;

			case MTK_BIN_FILE_SYSTEM:
				if( !FillExtraInfoByBinType(configFile, imFormat,
					sectionVectorINI[i].c_str(), V_FILE_SYSTEM_BINARY,
					extraInfo, index))
				{
					cout << "ERROR: Fill extraInfo fail!" << endl;
					return false;
				}
				break;

			default:
				cout << "ERROR: UNKNOWN TYPE BIN" << endl;
				return false;				
			}

			if(index >= extraInfoSize)
			{
				cout << "WARNING: Too many different bin file types !" << endl;
				return false;
			}
		}
	}
	
    return true;
}







static void DisplayExeVer(void)
{

	TCHAR szFullPath[MAX_PATH];
	DWORD dwVerInfoSize = 0;
	DWORD dwVerHnd;
	VS_FIXEDFILEINFO * pFileInfo;

    GetModuleFileName(NULL, szFullPath, sizeof(szFullPath));
	dwVerInfoSize = GetFileVersionInfoSize(szFullPath, &dwVerHnd);
    if (dwVerInfoSize)
	{
		// If we were able to get the information, process it:
        HANDLE  hMem;
        LPVOID  lpvMem;
        unsigned int uInfoSize = 0;
		hMem = GlobalAlloc(GMEM_MOVEABLE, dwVerInfoSize);
		lpvMem = GlobalLock(hMem);
		GetFileVersionInfo(szFullPath, dwVerHnd, dwVerInfoSize, lpvMem);
		
		::VerQueryValue(lpvMem, (LPTSTR)("\\"), (void**)&pFileInfo, &uInfoSize);
		WORD m_nFileVersion[4];
		
		
		// Product version from the FILEVERSION of the version info resource 
		m_nFileVersion[0] = HIWORD(pFileInfo->dwFileVersionMS); 
		m_nFileVersion[1] = LOWORD(pFileInfo->dwFileVersionMS);
		m_nFileVersion[2] = HIWORD(pFileInfo->dwFileVersionLS);
		m_nFileVersion[3] = LOWORD(pFileInfo->dwFileVersionLS); 
          
      
		cout << "------------------------------" << endl;
		cout << "XIM_Maker.exe Ver:" << m_nFileVersion[0] << "." << m_nFileVersion[1] << "." << m_nFileVersion[2] << endl;
		cout << "------------------------------" << endl;

        GlobalUnlock(hMem);
        GlobalFree(hMem);

	}
	else
	{
        cout << "[Warning] GetFileVersionInfoSize failed" << endl;
		return;
	}
}


int main(int argc, char* argv[])
{   
    //
    // 1. Parse the command line arguments
    //
    string strINI;  // config file
    string strIM;   // input .IM file
    string strXIM;  // output .XIM file
	
	// dump version information
	DisplayExeVer();


    if(false == ParseArguments(argc, argv, strINI, strIM, strXIM))
    {
        cout << "ERROR: ParseArguments() fail! " << endl;
        return 1;
    }

    //
    // 2. Get general info from config file
    //
    int IMFormat;
    string platformID;
    string projectID;  
    bool   debugFlagBL;
    if(false == GetConfig(strINI, IMFormat, platformID, projectID, debugFlagBL))
    {
        cout << "ERROR: GetConfig() fail!" << endl;
        return 2;
    }
    
    //
    // 3. Get device dependent info from config file
    //    
    GFH_DL_PACKAGE_EXTRA_INFO extraInfo[MAX_EXTRA_INFO_NUM];
    memset(extraInfo, 0, sizeof(GFH_DL_PACKAGE_EXTRA_INFO)*MAX_EXTRA_INFO_NUM);
    if(false == GetAllBinFileInfoByDevice(strINI, (IM_FORMAT)IMFormat, 
                                          extraInfo, MAX_EXTRA_INFO_NUM ))
    {
        cout << "ERROR: GetAllBinFileInfoByDevice() fail!" << endl;
        return 3;
    }


	// 3.1: check if the bin update rules are matched
	if(false == CheckAllBinFileInfoByDevice((IM_FORMAT)IMFormat, 
                                          extraInfo, MAX_EXTRA_INFO_NUM))
    {
		cout << "ERROR: CheckAllBinFileInfoByDevice() fail!" << endl;
		return 3;
	}
    
    //
    // 4. Read .IM file and parse the NAND Image Header
    //
    vector<unsigned char> IMContent;
    int IMHeaderSize = 0;        
    if(false == ReadIMFileAndHeaderSize((IM_FORMAT)IMFormat, strIM, 
                                        IMContent,IMHeaderSize))
    {
        cout << "ERROR: ReadIMFileAndHeaderSize() fail" << endl;
        return 4;
    }

    //
    // 5. Create DL_PACKAGE_GFH header
    //    
    int sigSize = GetSigLen();     
    DL_PACKAGE_GFH XIMHeader;
    if(false == CreateHeaderXIM(IMFormat, platformID, projectID, debugFlagBL,
                                IMContent.size(), sigSize, XIMHeader, extraInfo,
                                MAX_EXTRA_INFO_NUM))
    {
        cout << "ERROR: CreateHeaderXIM() fail!" << endl;
        return 5;
    }

    //
    // 6. Sign (DL_PACKAGE_GFH+ NAND Image Header) AND (.IM file without NAND Image Header)
    //
    vector<unsigned char> XIMOutputContent( 
                 sizeof(DL_PACKAGE_GFH)+IMContent.size()+2*sigSize , 0);    
    if(false == AppendSignature(sigSize, XIMHeader, IMContent, IMHeaderSize ,XIMOutputContent))
    {
        cout << "ERROR: AppendSignature() fail!" << endl;
        return 6;
    }

    //
    // 7. Save XIM content
    //
    if(false == SaveXIMContent(XIMOutputContent, strXIM))
    {
        cout << "ERROR: SaveXIMContent() fail!" << endl;
        return 7;
    }

    cout << "Succesfully generate " << strXIM << " file" << endl;
    return 0;
}



