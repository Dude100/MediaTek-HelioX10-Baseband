#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2005
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
#
#*****************************************************************************
#
# Filename: 
# ---------
#  MauiInfo.pm
#
# Description: 
# ------------
#  this script is used to handle MAUI related info.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#
# Log: 
# -----
#  2010/02/10   Create.
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
package MauiInfo;  
use strict;

#******************************************************************************
# Global Data
#******************************************************************************
my $f_cacheIncPath = 1;

my $g_prjName = '';
my $g_mcuPath = ".";
my @g_incMods = ("plutommi", "venusmmi");
my @g_incPath = ();

my $g_isCompileInfoReady = 0;
my $g_removeTempFile = 1;



return 1; # return true

#******************************************************************************
# FUNCTION
#  setInfo
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub setInfo()
{
    ($g_mcuPath, $g_prjName) = @_;
}


#******************************************************************************
# FUNCTION
#  setIncMods
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub setIncMods()
{
    @g_incMods = @_;
}


#******************************************************************************
# FUNCTION
#  getIncPath
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub getIncPath()
{
    my ($incFile) = @_;
    
    if (!$g_isCompileInfoReady)
    {
        &readCompileInfo(\@g_incMods, \@g_incPath, 0);
        $g_isCompileInfoReady = 1;
    }
    
    return searchIncPath($incFile, \@g_incPath);
    
}



#******************************************************************************
# Local Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  searchIncPath
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
my %incCacheHash = ();
sub searchIncPath()
{
    my ($incFile, $incPath_aref) = @_;
    
    if ($f_cacheIncPath)
    {
        return $incCacheHash{$incFile} if (defined $incCacheHash{$incFile});
    }
    
    foreach my $incPath (@{$incPath_aref})
    {
        my $filepath = "$incPath\\$incFile";
        if (-e $filepath)
        {
            $incCacheHash{$incFile} = $incPath if ($f_cacheIncPath);
            return $incPath;
        }
    }
    return "";
}


#******************************************************************************
# FUNCTION
#  readCompileInfo
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub readCompileInfo()
{
    my ($incMod_aref, $incPath_aref, $def_aref) = @_;
    
    if ($g_prjName eq "")
    {
        push @{$incPath_aref}, ".";     # no project specified, just put current dir to inc path
        print "[Warning] no compile info!\n";
        return;
    }
    
    my $infoFilename = "$g_mcuPath\\build\\$g_prjName\\log\\info.log";
    
    my %defHash = ();
    my %incHash = ();   
    
    my $inSection;
    if ($incPath_aref || $def_aref)
    {
        # read common options and common include path from info.log     
        open(hFile, "<$infoFilename") or die "can't open $infoFilename";
        my @fileData = <hFile>;
        close(hFile);
           
        foreach my $line (@fileData)
        {
            if ($line =~ /\[ COMMON OPTION \]/)
            {
                $inSection = 1;
                next;
            }
            elsif ($line =~ /\[ COMMON INCLUDE PATH \]/)
            {
                $inSection = 2;
                next;
            }
        
            if ($line =~ /(^[^\[][^\s]*)/)
            {           
                if ($inSection == 1)
                {
                    #print "$1\n";
                    if ($def_aref && !(defined $defHash{$1}))
                    {
                        push @{$def_aref}, $1;
                        $defHash{$1} = 1;
                    }
                }
                elsif ($inSection == 2)
                {
                    my $incPath = "$1";
                    
                    if ($incPath !~ /:/)
                    {
                        $incPath = "$g_mcuPath\\$incPath";
                    }
                    #print "$incPath\n";
                    
                    if ($incPath_aref && !(defined $incHash{$incPath}))
                    {
                        push @{$incPath_aref}, $incPath;
                        $incHash{$incPath} = 1;
                    }
                }
            }
            else            
            {
                $inSection = 0;
            }
        }
    }
    
    # read inc from *.inc
    if ($incPath_aref)
    {
        foreach my $myMod (@{$incMod_aref})
        {
            my @incFiles = ();
            if (&getFileList("$g_mcuPath\\make\\$myMod\\*.inc", 1, \@incFiles) > 0)
            {
                foreach my $incFilename (@incFiles)
                {
                    open(hFile, "<$incFilename") or die "can't open $incFilename";
                    my @fileData = <hFile>;
                    close(hFile);
                    
                    foreach my $line (@fileData)
                    {
                        if ($line =~ /(^[^\s]+)([\s]*$)/)
                        {
                            my $incPath = "$g_mcuPath\\$1";
                            #$incPaths = "$incPaths\n-I$g_mcuPath\\$1";
                            if (!(defined $incHash{$incPath}))
                            {
                                push @{$incPath_aref}, $incPath;
                                $incHash{$incPath} = 1;
                            }                            
                        }
                    }
                }            
            }
            else
            {
                print "[Warning] can't find *.inc for $myMod\n";
            }
        } 
    }   
    
    # read macro from *.def
    if ($def_aref)
    {
        foreach my $myMod (@{$incMod_aref})
        {
            my @defFiles = ();
            if (&getFileList("$g_mcuPath\\make\\$myMod\\*.def", 1, \@defFiles) > 0)
            {
                foreach my $defFilename (@defFiles)
                {
                    open(hFile, "<$defFilename") or die "can't open $defFilename";
                    my @fileData = <hFile>;
                    close(hFile);
                    
                    foreach my $line (@fileData)
                    {
                        if ($line =~ /(^[^\s]+)([\s]*$)/)
                        {
                            #$commonOptions = "$commonOptions\n-D$1";
                            if (!(defined $defHash{$1}))
                            {
                                push @{$def_aref}, $1;
                                $defHash{$1} = 1;
                            }                            
                        }
                    }
                }            
            }
            else
            {
                print "[Warning] can't find *.def for $myMod\n";
            }        
        }    
    }
}


#******************************************************************************
# FUNCTION
#  getFileList
# DESCRIPTION
#  get file/path list for given search string
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub getFileList()
{
    my $rootDir;
    my $incSubDir; # include sub dir (1) or not (0)
    my $fileList_ref;
    
    ($rootDir, $incSubDir, $fileList_ref) = @_;
    
    my @fileData = ();

    # get file list
    my $tmpFilename = "~tmpFile.lst";
    
    my $dirStr = "$rootDir /b";
    $dirStr .= " /s" if ($incSubDir);

    system("dir ".$dirStr." > $tmpFilename");
    open(hFile, "<$tmpFilename") or die "[ERROR] can't open $tmpFilename\n";
    @fileData = <hFile>;
    close(hFile);
    system("del $tmpFilename") if ($g_removeTempFile);

    foreach my $line (@fileData)
    {
        my $name = $line;
        push @{$fileList_ref}, $name if ($name !~ /^[\s]*$/);
        #print "$name";
    }
    return scalar(@{$fileList_ref});
}

