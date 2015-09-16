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
#*   scatFrame.pm
#*
#* Project:
#* --------
#*
#*
#* Description:
#* ------------
#*   This script is to generate the frame of memory layout 
#*   and provides the flow of generation
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
BEGIN { push @INC, './tools/' }  # add additional library path
use sysGenUtility;
use FileInfoParser;
package scatFrame;
#****************************************************************************
# oo >>>  Finished
#****************************************************************************
return 1;

#****************************************************************************
# scatFrame Version
#****************************************************************************
sub scatFrame_verno
{
    return " m0.01";
           # m0.01 , 20120528 by mei, Support path and filename case sensitive on Linux
           # v0.02 , 20120519 by mei, support Read BB folder first to get config input
           # v0.01 , 20120513 by mei, initial version
}
#****************************************************************************
# Constants
#****************************************************************************
#****************************************************************************
# Global Variables
#****************************************************************************
#****************************************************************************
# Input Parameters
#****************************************************************************
use constant InputSections => 0;
#SCAT Type
use constant MAIN          => 0;
use constant BL            => 1;
use constant EXT_BL        => 2;
use constant FOTA          => 3;
#****************************************************************************
# subroutines
#****************************************************************************
#scatFrame::GetPath("ROM", scatFrame::InputSections)
sub GetPath
{
    my ($strKey, $nType) = @_;
    my $strPath = undef;
    my $strMAINConfig = "scat_config/";
    my %PathMap = ("InputSections"     => "InputSections/",
                  );
    if($nType == InputSections)
    {
        $strPath = $strMAINConfig . $PathMap{InputSections}.$strKey."/";
    }
    else
    {
        &scatFrame_die("[GetPath]Unsupport Type", __FILE__, __LINE__);
    }
    return $strPath;
}

sub GetConfigInput
{
    my ($RegionName, $strFileName, $nType, $bb_folder) = @_;
    my $strFile = &GetPath($RegionName, $nType) . $strFileName;
    my $strCustomFolder = $bb_folder . "/";
    my $strDefaultFolder = "custom/system/Template/";
    my $strInput = $strDefaultFolder . $strFile;
    $strInput = $strCustomFolder.$strFile if(-e  $strCustomFolder.$strFile);
    return $strInput;
}

sub GenInputSections
{
    my ($InputSection_aref, $Indef_href) = @_;
    my $strContent;
    foreach my $item (@$InputSection_aref)
    {
        my $strModuleName = $item->[$Indef_href->{ModuleName}];
        my $strAttribute = $item->[$Indef_href->{Attribute}];
        $strModuleName =~ s/\s//g;
        next if($strModuleName eq "");
        my @AttrTemp = split(/\s+/, $strAttribute);
        if($strModuleName =~ /.lib$|.a$/ and $strModuleName !~ /^\*|\;/)
        {
            $strModuleName = "*".$strModuleName;
        }
        my @Attr;
        foreach my $strAttr (@AttrTemp)
        {
            if($strAttr =~ /^RO$|^RW$|^ZI$|^RO-CODE$|^RO-DATA$/)
            {
                $strAttr = "+".$strAttr;
            }
            push @Attr, $strAttr;
        }
        $strContent .= ' 'x8 . $strModuleName . " (". join(", ", @Attr) . ")\n";
    }
    return $strContent;
}


#****************************************************************************
# subroutine:  scatFrame_die
# sample code: (message, __FILE__, __LINE__)
# input:       $error_msg, $file, $line_no
#****************************************************************************
sub scatFrame_die
{
    my ($error_msg, $file, $line_no) = (@_);
    &sysUtil::error_handler($error_msg, $file, $line_no, 'scatFrame');    
}