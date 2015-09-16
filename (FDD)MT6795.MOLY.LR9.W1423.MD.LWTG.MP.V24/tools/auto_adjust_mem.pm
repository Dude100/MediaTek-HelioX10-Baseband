#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2006
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************
#*
#* Filename:
#* ---------
#*   auto_adjust_mem.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This module collects the subroutines for common utility. 
#*       
#*
#* Author:
#* -------
#*   Qmei Yang (mtk03726)
#*
#****************************************************************************/
#****************************************************************************
# Included Modules
#****************************************************************************
use strict;
#****************************************************************************
# Constants
#****************************************************************************
my $AAPMC_VERNO     = " m0.02";
                  #  m0.02, Support load view size insufficient error code
                  #  m0.01, Support folder on Linux
                  #  v0.03, Add AAPMC::Copyer to support theone architecture
                  #  v0.02, 20120425 by mei, add one error code
                  #  v0.01, initial version

return 1;

#****************************************************************************
# Package :  ERR
#****************************************************************************
package ERR;
use constant NO_MODIFY        => 0;
use constant MODIFY_SUCCESS   => 1;
use constant CANNOT_ADJUST    => 2;
use constant AAPMCLOG_SUCCESS => 3;
use constant AUTOCONFIG_SELF_MODIFY_SUCCESS => 4;
use constant NO_NEED_TO_UPDATE => 5;

use constant ERR_MODIFYFAIL   => 101;
use constant ERR_UNEXPECTED   => 102; #default exit
use constant ERR_MODIFYDUPLICATED => 103;
use constant ERR_LOADVIEWSIZE_INSUFFICIENT => 104;

sub QueryErrMeaning
{
    my ($ERR) = @_;
    return "[$ERR]NO_MODIFY, PASS" if($ERR == NO_MODIFY);
    return "[$ERR]MODIFY_SUCCESS, PASS" if($ERR == MODIFY_SUCCESS);
    return "[$ERR]CANNOT_ADJUST, FAIL" if($ERR == CANNOT_ADJUST);
    return "[$ERR]AAPMCLOG_SUCCESS, PASS" if($ERR == AAPMCLOG_SUCCESS);
    return "[$ERR]AUTOCONFIG_SELF_MODIFY_SUCCESS, PASS" if($ERR == AUTOCONFIG_SELF_MODIFY_SUCCESS);
    return "[$ERR]NO_NEED_TO_UPDATE, PASS" if($ERR == NO_NEED_TO_UPDATE);
    return "[$ERR]MODIFYFAIL, FAIL" if($ERR == ERR_MODIFYFAIL);
    return "[$ERR]UNEXPECTED, FAIL" if($ERR == ERR_UNEXPECTED);
    return "[$ERR]MODIFY DUPLICATED, FAIL" if($ERR == ERR_MODIFYDUPLICATED);
    return "[$ERR]LOADVIEWSIZE_INSUFFICIENT, FAIL" if($ERR == ERR_LOADVIEWSIZE_INSUFFICIENT);
}

#****************************************************************************
# Package :  AUTO_ADJUST
#****************************************************************************
package AUTO_ADJUST;
#****************************************************************************
# subroutine:  AUTO_ADJUST::ChangeDefineValue
#              aim to change #define value
# input:       $strFilePath: file path
#              %ChangeListHash={$strName, $strValue}
#              After changing, it should look like: #define $strName $strValue
# output:      $bModified: ERR::NO_MODIFY= no change, ERR::MODIFY_SUCCESS=modified
# SampleCode: 
#    my %ChangeList;
#    $ChangeList{'name1'} = "value1";
#    $ChangeList{'name2'} = "value2";
#    &AUTO_ADJUST::ChangeDefineValue($CUSTOM_FEATURE_CONFIG_H, \%ChangeList);
# or &AUTO_ADJUST::ChangeDefineValue($CUSTOM_FEATURE_CONFIG_H, {'name1'=>'value1',});
#****************************************************************************
sub ChangeDefineValue
{
    my ($strFilePath, $ChangeListHash_href) = @_;
    open (FILE_HANDLE, $strFilePath) or &autoadjust_die("Cannot open $strFilePath\n", __FILE__, __LINE__);
    my $reading = "";
    my $bModified = ERR::ERR_MODIFYFAIL;
    
    while (<FILE_HANDLE>) 
    {
        my $strLine = $_;
        foreach my $strName (keys %$ChangeListHash_href)
        {
            my $strValue = $ChangeListHash_href->{$strName};
            if($strLine =~ /^#define\s+($strName)\s+(\S+)/ or 
               $strLine =~ /\/\/\s*#define\s+($strName)\s+/ or 
               $strLine =~ /\/\/\s*#define\s+($strName)$/)
            {
              next if(hex($strValue) == hex($2));
              $strLine = "#define $strName $strValue\n";
              $bModified = ERR::MODIFY_SUCCESS;
            }
        }
        $reading .= $strLine;
    }
    close FILE_HANDLE;
    
    open (FILE_HANDLE, ">$strFilePath") or &autoadjust_die("Cannot open $strFilePath\n", __FILE__, __LINE__);
    print FILE_HANDLE $reading;
    close FILE_HANDLE;
    #print $bModified == 0 ? "No change\n" : "Modified\n";
    return $bModified;
}


#****************************************************************************
# subroutine:  AUTO_ADJUST::ModifyByChangeRecord
# input:       $strFolderPath: folder path before mcu\
#              Reference of @ChangeRecord = [$strFilePath, %ChangeListHash, %P4Info]
#              $bNeedBackup: 0=no need backup, 1=need backup
# output:      $err: ERR::NO_MODIFY= no change, ERR::MODIFY_SUCCESS=modified
# Note:        Backup the file before modifying. If no change, delete backup file.
#              Backup file name=File.beforeAutoAdj.timestamp.[rand=3 digits]
#              eg. ABC.h.beforeAutoAdj.1322408801.282
#****************************************************************************
sub ModifyByChangeRecord
{
    my ($strFolderPath, $ChangeRecord_ref, $bNeedBackup) = @_;
    my $strFileName = $ChangeRecord_ref->[0];
    my $TheOneBackupPath = AAPMC_COPYER::TheOneBackup($strFolderPath, $strFileName);
    my $BackupPath = AAPMC_COPYER::AAPMCBackup($strFolderPath, $strFileName) if ($bNeedBackup ==1);
    my $filepath = $strFolderPath . $strFileName;
    my $err = &ChangeDefineValue($filepath, $ChangeRecord_ref->[1]);
    unlink $BackupPath if($bNeedBackup ==1 and $err == ERR::NO_MODIFY);
    unlink $TheOneBackupPath if($err == ERR::NO_MODIFY);
    return $err;
}

#****************************************************************************
# subroutine:  AUTO_ADJUST::CreateP4InfoTemplate
# input:       $strOwner_ID: P4 ID
#              $strProject:  Project Name
#              $strPurpose:  CR Purpose
#              $strAdjustmentResult: Change List
# output:      Reference of %P4Info
#****************************************************************************
sub CreateP4InfoTemplate
{
    my ($strOwner_ID, $strProject, $strPurpose, $strAdjustmentResult) = @_;
    my %P4Info = ( "OWNER_ID" => $strOwner_ID,
                   "CR_DESCRIPTION" => "[$strProject]$strPurpose\n$strAdjustmentResult" );
    return \%P4Info;
}
#****************************************************************************
# subroutine:  AUTO_ADJUST::GetP4Info
# input:       Reference of %P4Info
# output:      $strOwner_ID: P4 Owner ID
#              $strCR_Description: CR description for 1 modification
#****************************************************************************
sub GetP4Info
{
    my ($P4Info_ref) = @_;
    my ($strOwner_ID, $strCR_Description);
    if($P4Info_ref)
    {
        $strOwner_ID       = $P4Info_ref->{OWNER_ID};
        $strCR_Description = $P4Info_ref->{CR_DESCRIPTION};
    }
    return ($strOwner_ID, $strCR_Description);
}

#****************************************************************************
# subroutine:  error_handler
# input:       $error_msg:     error message
#****************************************************************************
sub error_handler
{
    my ($error_msg, $file, $line_no, $strTitle) = @_;
       
    my $final_error_msg = "$strTitle ERROR: $error_msg at $file line $line_no : $!\n";
    print $final_error_msg;
    die $final_error_msg;
}
sub autoadjust_die
{
    my ($error_msg, $file, $line_no) = @_;
    &error_handler($error_msg, $file, $line_no, 'AUTO ADJUST MEM');
}


#****************************************************************************
# Package :  AAPMCLogParser
#****************************************************************************
package AAPMCLogParser;
use Storable qw/lock_retrieve lock_nstore/;

my $g_FileArchieve = undef;
my $g_DBInfo_ref   = undef; # %DBInfoTable

#****************************************************************************
# subroutine:  AAPMCLogParser::Open
# input:       $strLogPath: AAPMC.log's path
# output:      $err: ERR::ERR_UNEXPECTED=  Load failed
#                    ERR::AAPMCLOG_SUCCESS=Load successfully
#****************************************************************************
sub Open
{
    my ($strLogPath) = @_;
    my $err = ERR::ERR_UNEXPECTED;
    if(!-e $strLogPath)
    {
        my %Empty = ('AAPMCLog' => ());
        lock_nstore \%Empty, $strLogPath;
    }
    my $g_FileArchieve = lock_retrieve $strLogPath;
    if($g_FileArchieve)
    {
        $g_DBInfo_ref = $g_FileArchieve->{'AAPMCLog'};
        $err = ERR::AAPMCLOG_SUCCESS;
    }
    return $err;
}
#****************************************************************************
# subroutine:  AAPMCLogParser::Close
# input:       $strLogPath: AAPMC.log's path
# output:      $err: ERR::ERR_UNEXPECTED=  Load failed
#                    ERR::AAPMCLOG_SUCCESS=Load successfully
#****************************************************************************
sub Close
{
    my ($strLogPath) = @_;
    my $err = ERR::ERR_UNEXPECTED;
    if(-e $strLogPath)
    {
        my %Temp = ('AAPMCLog' => $g_DBInfo_ref);
        lock_nstore \%Temp, $strLogPath;
        $err = ERR::AAPMCLOG_SUCCESS;
    }
    return $err;
}
#****************************************************************************
# subroutine:  AAPMCLogParser::AddOneChangeRecord
# input:       $ChangeFilePath: The file is going to be modified. (store its path by mcu\... without folder information)
#              $ChangeList_ref: Reference of %ChangeListHash={$strName, $strValue}
#              $P4Info_ref: Reference of %P4Info = {$OwnerID, $CR_Description} => You can create by &AUTO_ADJUST::CreateP4InfoTemplate
# output:      $err: ERR::ERR_MODIFYDUPLICATED : Can't add the same key ChangeList more than twice
#                    ERR::AAPMCLOG_SUCCESS     : Add successfully
#****************************************************************************
sub AddOneChangeRecord
{
    my ($ChangeFilePath, $ChangeList_ref, $P4Info_ref) = @_;
    my $err = ERR::ERR_UNEXPECTED;
    #Trim the string before mcu\ in which mcu should be the last mcu
    if($ChangeFilePath =~ /\S+(mcu\S+)/)
    {
        $ChangeFilePath = $1;
    }
    if(0 == &isModified($ChangeFilePath, $ChangeList_ref))
    {
        #Key=TimeStamp, Value=0: $ChangeFilePath
        #                     1: %ChangeList
        #                     2: %P4Info
        $g_DBInfo_ref->{&GetTimeStamp()} = [ $ChangeFilePath, $ChangeList_ref, \%$P4Info_ref ];
        $err = ERR::AAPMCLOG_SUCCESS;
    }
    else
    {
        $err = ERR::ERR_MODIFYDUPLICATED;
    }
    return $err;
}
#****************************************************************************
# subroutine: AAPMCLogParser::isModified : Called by AddOneChangeRecord()
# input:      $strChangeFilePath: The file is going to be modified. (store its path by mcu\... without folder information)
#             $ChangeList_ref: Reference of %ChangeListHash={$strName, $strValue}
# output:     $isModified: 0=never modified before, 1= it has been modified
# comment: in the same file, if ChangeList's option existed, then return duplicated modification.
#****************************************************************************
sub isModified
{
    my ($strChangeFilePath, $ChangeList_ref) = @_;
    my $isModified = 0; # 0=no, 1=yes;
    if($g_DBInfo_ref)
    {
        while (my ($timestamp, $aChange) = each (%$g_DBInfo_ref))
        {
            if(($aChange->[0] eq $strChangeFilePath))
            {
                foreach my $option (keys %$ChangeList_ref)
                {
                    if(exists $aChange->[1]{$option})
                    {
                        $isModified = 1;
                        last;
                    }
                }
            }
        }
    }
    #print $isModified==0 ? "never modified\n" : "has been modified\n";
    return $isModified;
}
#****************************************************************************
# subroutine:  AAPMCLogParser::GetAllRecordsIndex
# input:       x
# output:      $err: ERR::ERR_UNEXPECTED: no records in DBInfo.
#                    ERR::AAPMCLOG_SUCCESS
#              Reference of @ChangeRecords: an array of all timestamps 
#****************************************************************************
sub GetAllRecordsIndex
{
    my @ChangeRecords;
    my $err = ERR::ERR_UNEXPECTED;
    if($g_DBInfo_ref)
    {
       map {push (@ChangeRecords, $_);} keys %$g_DBInfo_ref;
       $err = ERR::AAPMCLOG_SUCCESS;
    }
    return ($err, \@ChangeRecords);
}


#****************************************************************************
# subroutine:  AAPMCLogParser::GetByIndex
# input:       $Index: timestamp
#              $Type: AAPMCLogParser::FILEPATH
#                     AAPMCLogParser::CHANGELIST
#                     AAPMCLogParser::P4Info
#                     AAPMCLogParser::RECORD 
# output:   1. $err=ERR::ERR_UNEXPECTED=no data in DBInfo
#                   ERR::AAPMCLOG_SUCCESS
#           2. if $Type=AAPMCLogParser::FILEPATH,   return strChangeFilePath
#                 $Type=AAPMCLogParser::CHANGELIST, return Reference of %ChangeList
#                 $Type=AAPMCLogParser::P4INFO,     return Reference of %P4Info, 
#                                                   you may use AUTO_ADJUST::GetP4Info to get P4Info
#                 $Type=AAPMCLogParser::RECORD,     return Reference of %ChangeRecord
#                 else, return undef with ERR::ERR_UNEXPECTED
#****************************************************************************
use constant FILEPATH      => 0;
use constant CHANGELIST    => 1;
use constant P4INFO        => 2;
use constant RECORD        => 3;
sub GetByIndex
{
    my ($Index, $Type) = @_;
    if($g_DBInfo_ref)
    {
        if($Type < RECORD)
        {
            return ($g_DBInfo_ref->{$Index}[$Type]); 
        }
        elsif($Type == RECORD)
        {
            return ($g_DBInfo_ref->{$Index}); # @ChangeRecord
        }
    }
    return undef;
}

#****************************************************************************
# subroutine:  AAPMCLogParser::GetTimeStamp
# input:       x
# output:      string of timestamp with rand(1000)
#              eg. 1322408801.282
#****************************************************************************
sub GetTimeStamp
{
    return time().".".int(rand(1000));
}

#****************************************************************************
# Package :  AAPMC_COPYER
#****************************************************************************
package AAPMC_COPYER;

use constant THEONE        => "theone";
use constant CONFIG        => "conf";

use File::Copy;
#****************************************************************************
# subroutine:  AAPMC_COPYER::AAPMCBackup
# input:       
# output:     
#****************************************************************************
sub AAPMCBackup
{
    my ($strBuildFolder, $strFileName) = @_;
    #Backup for AutoAdj
    $strBuildFolder .= '/' if($strBuildFolder !~ /\/$/);
    my $OrgFilePath = $strBuildFolder.$strFileName;
    my $BackupPath = $OrgFilePath.".beforeAutoAdj".&AAPMCLogParser::GetTimeStamp();
    copy($OrgFilePath, $BackupPath);
    return $BackupPath;
}
sub TheOneBackup
{
    my ($strBuildFolder, $strFileName) = @_;
    #Backup for the one
    $strBuildFolder .= '/' if($strBuildFolder !~ /\/$/);
    my $OrgFilePath = $strBuildFolder.$strFileName;
    my $BackupPath = $OrgFilePath.".".THEONE;
    if(!-e $BackupPath)
    {
        copy($OrgFilePath, $BackupPath);
    }
    return $BackupPath;
}

#****************************************************************************
# subroutine:  AAPMC_COPYER::IsNeededToCopy
# purpose: before m sysgen, build flow needs to know if it needs to copy the files 
#          from custom\system\[BB]\
# input:   1. $strBuild_FolderPath : build folder for custom\system
#          2. $strBB_FolderPath : custom\system\[BB]
#          3. $strFileName : filename without .conf or .theone for querying if it is needed to copy
# output:  undef = no need to copy
#          1 = needed to copy
#****************************************************************************
sub IsNeededToCopy
{
    my ($strBuild_FolderPath, $strBB_FolderPath, $strFileName) = @_;
    my $bNeededToCopy = undef;
    $strBuild_FolderPath .= '/' if($strBuild_FolderPath !~ /\/$/);
    $strBB_FolderPath .= '/' if($strBB_FolderPath !~ /\/$/);
    
    my $strBuildFile = $strBuild_FolderPath . $strFileName;
    my $strBBFile = $strBB_FolderPath . $strFileName ."." .CONFIG;
    my $strTheOneFile = $strBuild_FolderPath . $strFileName . "." . THEONE;
    if(-e $strBuildFile)
    {
        if(-e $strTheOneFile)
        {
            $bNeededToCopy = &CompareFile($strBBFile, $strTheOneFile);
        }
        else
        {
            $bNeededToCopy = 1;
        }
    }
    else
    {
        $bNeededToCopy = 1;
    }
    return $bNeededToCopy;
}
#****************************************************************************
# subroutine:  AAPMC_COPYER::CompareFile
# input:   1. strSrcPath
#          2. strDestPath
# output:  undef = no different
#          1 = have some difference
#****************************************************************************
sub CompareFile
{
    my ($strSrcPath, $strDestPath) = @_;
    my $bDeff = undef;
    my $strSrcContent = &GetFileContent($strSrcPath);
    my $strDestContent = &GetFileContent($strDestPath);
    $bDeff = 1 if($strSrcContent ne $strDestContent);
    return $bDeff;
    
}
#****************************************************************************
# subroutine:  AAPMC_COPYER::GetFileContent
# input:   strFilePath
# output:  strFileContent after chomp
#****************************************************************************
sub GetFileContent
{
    my ($strFilePath) = @_;
    my $content;
    open FILE, "<$strFilePath" or &AUTO_ADJUST::error_handler("$strFilePath: open file error!", __FILE__, __LINE__, 'AAPMC_COPYER::GetFileContent');
    {
        local $/;
        $content = <FILE>;
    }
    close FILE;
    chomp($content);
    return $content;
}
