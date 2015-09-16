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
#  mmi_res_check.pl
#
# Description: 
# ------------
#  this script is used to do mmi resource check.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#  none.
#
# Log: 
# -----
#  2010/02/09   Create.
#

BEGIN { push @INC, 'tools\\', '.\\'}  # add additional library path
#package XXX;  
use strict;
use File::stat;
use IO::Handle;
use MauiInfo;

use DataManipulation;   # for debug usage

#******************************************************************************
# Global Data
#******************************************************************************
my $f_useTempRes = 1;
my $f_stdOutToLog = 1;
my $f_parseIncludeInc = 0;
my $f_onlyGenDefaultMacro = 1;  # only gen for @defaultIncList
my $f_onlyParseMemoryRes = 1;   # only parse xml w/ <MEMORY/> tag

my $resRangeDefPath = "plutommi\\mmi\\inc";
my $resRangeDefFile = "mmi_res_range_def.h";
my $mcuPath = ".";
my $prjName = "";

my $outputPath = "";
my $logFilename = "";

my $compiler = "armcc";
my $viaOption = "--via";

my @defaultIncList = ("GlobalConstants.h", "lcd_sw_inc.h");

my %resHash = ();
my %incHash = ();   # hash for all inc

my $idx_dir = 0;    # %resHash index for res file dir
my $idx_inc = 1;    # %resHash index for inc files used in that res file

my $totalExecuteTime = 0;

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my $oriStdout;

#******************************************************************************
# Program Start
#******************************************************************************

#die getHelp() if (@ARGV == 0);

($outputPath) = @ARGV;

$prjName = &getPrjName();

$outputPath = ".\\build\\$prjName\\xml\\macro" if ($outputPath eq "");
$logFilename = ".\\build\\$prjName\\log\\mmi_res_check.log";

print "\n[mmi_res_check.pl] start ...\n\n";
# redirect output to log file
if ($f_stdOutToLog)
{
    open($oriStdout, ">&STDOUT"); # save original STDOUT
    open(STDOUT, ">$logFilename") or die "can't open $logFilename\n";
}

# 1st time stamp
$totalExecuteTime += &DataManipulation::timeCheck();

&MauiInfo::setInfo($mcuPath, $prjName);
&MauiInfo::setIncMods(qw{"plutommi" "venusmmi"});

# prepare output path
system("mkdir $outputPath") if (!(-e $outputPath));

# get all res files
&getResFileList("$mcuPath\\$resRangeDefPath\\$resRangeDefFile") if (!$f_onlyGenDefaultMacro);

# get inc path for default inc files
foreach my $inc (@defaultIncList)
{
    $inc = lc $inc;
    my $path = lc &MauiInfo::getIncPath($inc);   
    if (!(defined $incHash{"$path\\$inc"}))
    {
        $incHash{"$path\\$inc"} = 1;
    }
}
$totalExecuteTime += &DataManipulation::timeCheck("", "\t(get default inc path)");

# get inc for all res files
if (!$f_onlyGenDefaultMacro)
{
    # getResInc will only keep res file w/ <MEMORY/> tag
    &getResInc(\%resHash, \%incHash);
    $totalExecuteTime += &DataManipulation::timeCheck("", "\t(getResInc\(\))");
}

# skip mmi_features.h
my $skipFile = lc &MauiInfo::getIncPath("mmi_features.h")."\\mmi_features.h";
delete $incHash{$skipFile};

# time diff.
$totalExecuteTime += &DataManipulation::timeCheck("", "\t(mmi_res_check pre-processing)");

foreach my $inc (keys %incHash)
{
    # TODO: if we wanna check timestamp to see whether re-gen log or not, 
    #       we should check its .res and all *.h dependencies
   
    system("perl $mcuPath\\tools\\mmi_feature_check.pl $prjName $compiler $viaOption $inc $inc FALSE 0 $outputPath");

    # time diff.
    $totalExecuteTime += &DataManipulation::timeCheck("", "\t(".&splitPathName($inc).")");
}

#&DataManipulation::printObject(\%resHash);

if (!$f_onlyGenDefaultMacro)
{
    foreach my $file (keys %resHash)
    {
        my $resFile = $resHash{$file}[$idx_dir]."\\".$file;
        #print "resFile : ".$resFile."\n";
        system("tools\\python25\\python.exe tools\\py\\prexml.py $resFile $resFile");
    }
    $totalExecuteTime += &DataManipulation::timeCheck("", "\t(prexml for <MEMORY/> tag)");
}

print "\n[Time: total = $totalExecuteTime sec.]\n";
if ($f_stdOutToLog)
{
    close(STDOUT);
    open(STDOUT, ">&", $oriStdout);  # restore STDOUT
}

print "\n[mmi_res_check.pl] end (execution time: $totalExecuteTime sec., see mmi_res_check.log for detail)\n";

exit 0;

#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  getMacroPreprocessResult
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************

sub getPrjName()
{
    my $prjName = "";
    if ((defined $ENV{"CUSTOMER"}) && ($ENV{"CUSTOMER"} ne "PLUTO"))
    {
        $prjName = $ENV{"CUSTOMER"};
    }
    elsif (-e "make.ini")
    {
        open (hFile, "<make.ini") or die "can't open make.ini\n";
        if (join('', <hFile>) =~ /\n\s*custom\s+\=\s+([\w]+)\n/i)
        {
            $prjName = $1;
        }
        close(hFile);
    }
    return $prjName;
}

sub getResInc()
{
    my ($resHash_ref, $incHash_ref) =  @_;
    
    foreach my $file (keys(%{$resHash_ref}))
    {
        my $dir = ${$resHash_ref}{$file}[$idx_dir];
        
        print "==> $file\n";
        
        open(hFile, "<$dir\\$file") or die "can't open $dir\\$file!\n";
        my $fileDataStr = join('', <hFile>);
        close(hFile);

        # only keep res file w/ <MEMORY/> tag
        if ($f_onlyParseMemoryRes && ($fileDataStr !~ /\s+<MEMORY\s+/i))
        {
            delete ${$resHash_ref}{$file};
            next;
        }

        while ($fileDataStr =~ /<INCLUDE4XML\s+file\s*\=\s*([\"\'])([^\1]+?)\1\s*\/>/g)
        #while ($fileDataStr =~ /<INCLUDE\s+file\s*\=\s*([\"\'])([^\1]+?)\1\s*\/>/g)
        {
            my @incFiles = split(',', lc $2);
            foreach my $incFile (@incFiles)
            {
                my $incPath = "";
                ${$resHash_ref}{$file}[$idx_inc]{$incFile} = "";                
                if ($incFile =~ /\\/)
                {
                    ${$incHash_ref}{$incFile} = 1 if ($incHash_ref);  
                }
                else
                {
                    $incPath = lc &MauiInfo::getIncPath($incFile);                
                    ${$incHash_ref}{$incPath."\\".$incFile} = 1 if ($incHash_ref);
                }
                print "\t\t$incFile\t($incPath)\n";
            }
        }
        
        if ($f_parseIncludeInc)
        {
            while ($fileDataStr =~ /(^|\n)\#include\s+\"([^\"]+)\"/g)
            {
                my $incFile = lc &trim($2);
                my $incPath = "";
                ${$resHash_ref}{$file}[$idx_inc]{$incFile} = "";
                if ($incFile =~ /\\/)
                {
                    ${$incHash_ref}{$incFile} = 1 if ($incHash_ref);  
                }
                else
                {
                    $incPath = lc &MauiInfo::getIncPath($incFile);                   
                    ${$incHash_ref}{$incPath."\\".$incFile} = 1 if ($incHash_ref);
                }
                print "\t\t$incFile\t($incPath)\n";                
            }
        }
    }
}


sub getResFileList()
{
    my ($defFilename) = @_;
    
    my $pathListStr;
    
    if (!$f_useTempRes)
    {    
        open(hFile, "<$defFilename") or die "can't open $defFilename!\n";
        my @fileData = <hFile>;
        close(hFile);
        
        my @pathList = ();
        
        foreach my $line (@fileData)
        {
            if ($line =~ /^\s*RESOURCE_BASE_TABLE_ITEM_PATH\s*\([\w]+\s*,\s*\"([^\"]+)\"\s*\)/)
            {
                my $path = &trim($1);
                $path =~ s/\\\\/\\/g;
                push @pathList, "$mcuPath\\plutommi\\".$path."\\*.res";
            }
        }
        $pathListStr = join(' ', @pathList);
    }
    else
    {
        $pathListStr = "$mcuPath\\plutommi\\Customer\\ResGenerator\\temp\\res\\*.c";
    }
    print "\$pathListStr = ".$pathListStr."\n";
             
    my @list = ();
    &getFileList($pathListStr, \@list);

    foreach my $pathName (@list)
    {
        my $dir;
        my $file = splitPathName($pathName, \$dir);
        $resHash{$file}[$idx_dir] = $dir;
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
    my $dirStr;
    my $fileList_ref;
    
    ($dirStr, $fileList_ref) = @_;
    
    my @fileData = ();

    # get file list
    my $tmpFilename = "~tmpFile.lst";
    
    system("dir ".$dirStr." > $tmpFilename");
    open(hFile, "<$tmpFilename") or die "[ERROR] can't open $tmpFilename\n";
    @fileData = <hFile>;
    close(hFile);
    system("del $tmpFilename");

    my $currDir = "";
    foreach my $line (@fileData)
    {
        if ($line =~ /^[\s]*Directory of[\s]+([^\n]+)/i)
        {
            $currDir = $1;
            #print "[dir] $currDir\n";
        }
        elsif ($line =~ /[\s]+File\(s\)[\s]+/)
        {
            $currDir = "";
        }
        elsif ($currDir ne "")
        {
            # [time] [size] [filename]  <= dir result
            if ($line =~ /\d\d:\d\d[\s]+([\d,]+)[\s]+([^\n]+)/)
            {
                my $size = $1;
                my $name = $2;
                #print "[size] $size\t[name] $name\n";
                push @{$fileList_ref}, "$currDir\\$name";
            }
        }
    }
    return scalar(@{$fileList_ref});
}

sub trim()
{
    my ($str) = @_;
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}


#******************************************************************************
# FUNCTION
#  splitPathName
# DESCRIPTION
#  split given filename to filename and path
# PARAMETERS
#  $filename [IN] - filename
#  $refSubFilename [OUT] - reference to path, may be NULL
# RETURNS
#  filename
#******************************************************************************
sub splitPathName()
{
    my $pathname;
    my $path_ref;
    
    ($pathname, $path_ref) = @_;
    
    if ($pathname =~ /(^.*)[\\\/]([^\\\/]+$)/)
    {
        #print "path [$1] filename[$2]\n";
        $$path_ref = $1 if ($path_ref != 0);
        return $2;
    }
    else
    {
        $$path_ref = '.' if ($path_ref != 0);   # current dir
        return $pathname;
    }
}


sub getHelp()
{
    my $help = << "__HELP";
    
Usage: mmi_res_check.pl <output path>
__HELP
    return $help;
}


#******************************************************************************
# FUNCTION
#  splitFilename
# DESCRIPTION
#  split given filename to main and sub
# PARAMETERS
#  $filename [IN] - filename
#  $refSubFilename [OUT] - reference to sub filename, may be NULL
# RETURNS
#  main filename
#******************************************************************************
sub splitFilename()
{
    my $filename;
    my $refSubFilename = "";
    my $mainFilename = "";
    
    ($filename, $refSubFilename) = @_;
    
    if ($filename =~ /([^\s]*)(\.)([^\.]*$)/)
    {
        #print "$filename [$1][$3]\n";
        $mainFilename = "$1";
        $$refSubFilename = "$3" if ($refSubFilename != 0);
    }
    return $mainFilename;
}
