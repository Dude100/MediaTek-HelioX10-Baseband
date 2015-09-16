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
#  hExpand.pl
#
# Description: 
# ------------
#  this script is used to expand files included by #include.
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
#  2008/06/30   Create.
#  2010/01/29   Correct header exclusion (all filename to lower case)
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
#package XXX;  
use strict;

#******************************************************************************
# Global Data
#******************************************************************************

my $lineRedirect            = 1;    # add '#line' in expanded file to redirect warning/error msg
my $g_removeTempFile        = 1;

# these two only work when $lineRedirect = 0
my $removeCommentOrNot      = 1;    # for correct #line redirect, should disable this
my $removeConsecutiveEmpty  = 0;    # no much size difference

my $g_nodeThreshold = 40;

my @targetFileList = ();
my $g_prjName = '';
my $g_mcuPath = ".";
my $g_outputPath = ".";

my $logFilename = "hExpand.log";
my $logPath = ".";
my $logFileHandle;

my $valSuccess          = 0;
my $valAlreadyIncluded  = 1;
my $valFileNotFound     = 2;
my $valRecursiveInclude = 3;
my $valOthers           = 4;

my $idxPath         = 1;
my $idxAlwaysInc    = 2;
my $idxIncluded     = 3;
my %g_incInfo = ();     # { filename => [1] path
                        #               [2] always include or not
                        #               [3] included or not}

my @g_incPath = ();

my %g_targetFileHash = ();
my @nonExpandList = ("ps_trace.h");
my %g_nonExpandList = ();

my @incDeeps = ();
my %incTreeHash = ();
my $g_totalIncCount = 0;
my $g_forceNotExpand = 0; # if set to 1, force NOT to expand #include

my $foundFileList = {};     # found list
my $notFoundFileList = {};  # not found list


#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************

#******************************************************************************
# Program Start
#******************************************************************************

if (@ARGV)
{
    ($g_mcuPath, $g_outputPath, $g_prjName, @targetFileList) = @ARGV;
}
else
{
    die "\nUsage: 'hExpand.pl <mcu path> <output path> <prj name> <target filename>'\n".
        "   e.g. hExpand.pl \\server\\w08.20\\mcu \\server\\w08.20\\mcu\\expandOutput superman29v31_demo mmi_include.h\n";
}

open($logFileHandle, ">$logPath\\$logFilename") or die "can't open $logPath\\$logFilename!\n";

printBoth("\n[start hExpand]\n\n");

&timeCheck();

# prepare non-expand list
foreach my $file (@nonExpandList)
{
    $g_nonExpandList{lc $file} = 1;
}

my @incMods = ("plutommi", "kal");
&readCompileInfo(\@incMods, \@g_incPath, 0);

$g_targetFileHash{$_} = 1 foreach (@targetFileList);

foreach my $targetFile (@targetFileList)
{
    printLog("[$targetFile]\n");
    
    my @resultData = ();
    @incDeeps = ();
    %incTreeHash = ();
    $g_totalIncCount = 0;
    %g_incInfo = ();

    my $fileHandle;
    my $outputFile = "$g_outputPath\\$targetFile";
    open($fileHandle, ">$outputFile");

    # copy original header file to output folder
    copyOriginalHeader($targetFile);
    
    # add compile option for MoDIS
    print $fileHandle "#ifdef WIN32\n";
    print $fileHandle "#include \"_".$targetFile."\"\n";
    print $fileHandle "#else\n";

    my $nodeCount = 0;
    &expandInc($fileHandle, $targetFile, 0, \$nodeCount);
   
    #&findMismatchIf(\@resultData);
    
    # end of compile option for MoDIS
    print $fileHandle "#endif /* WIN32 */\n\n";
    
    close($fileHandle);
    printBoth("\n[hExpand.pl] $outputFile generated!\n\n");

    &timeCheck();
}


close($logFileHandle);   # log file

exit 0;

#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  copyOriginalHeader
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub copyOriginalHeader()
{
    my ($incFile) = @_;
    
    my $incPath = &searchIncPath($incFile, \@g_incPath);

    open(hFile, "<$incPath\\$incFile") or die "can't open $incPath\\$incFile\n";
    my @fileData = <hFile>;
    close(hFile);
    
    open(hFile, ">$g_outputPath\\_".$incFile) or die "can't open $g_outputPath\\_".$incFile."\n";
    
    # add redirect info
    my $incPrintPathName = "$incPath\\$incFile";
    $incPrintPathName =~ s/\\/\\\\/g;
    print hFile "#line 0 \"$incPrintPathName\"\n" if ($lineRedirect);
    print hFile join('', @fileData);
    close(hFile);
}


#******************************************************************************
# FUNCTION
#  expandInc
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  0: success, 1: already included, 2: file not found, 3: recursive include
#******************************************************************************
sub expandInc()
{
    my ($fileHandle, $incFile, $alwaysExpand, $nodeCount_ref) = @_;
    $incFile = lc $incFile;
          
    my $incPath = "";
    my @fileData = ();
    my $printStr;
        
    printLog("[$incFile] check if include required\n");
    
    if (!(defined $g_incInfo{$incFile}))
    {
        # get path for every file's 1st entry
        
        $incPath = &searchIncPath($incFile, \@g_incPath);
        if ($incPath eq "")
        {
            printLog("[Warning] can't find path for $incFile\n");
            return $valFileNotFound;
        }
        $g_incInfo{$incFile}[$idxPath] = $incPath;
               
        # check for include condition
        open(hFile, "<$incPath\\$incFile") or die "can't open $incPath\\$incFile\n";
        @fileData = <hFile>;
        close(hFile);
        $g_incInfo{$incFile}[$idxIncluded] = 0;
        if (&getIncWrapper(\@fileData) eq "")
        {
            $g_incInfo{$incFile}[$idxAlwaysInc] = 1;
        }
        else
        {
            $g_incInfo{$incFile}[$idxAlwaysInc] = 0;
        }
        printLog("[$incFile] ifAlwaysInc = ".$g_incInfo{$incFile}[$idxAlwaysInc]."\n");
    }
    else
    {
        # just return if this inc is already included
        return $valAlreadyIncluded if ($g_incInfo{$incFile}[$idxIncluded]);
        $incPath = $g_incInfo{$incFile}[$idxPath];
    }

    if (defined $incTreeHash{$incFile})
    {
        printLog("[Warning] recursive include!\n");
        return $valRecursiveInclude;
    }

    $printStr = "//[hExpand.pl][$incFile] expanded (".join('->', @incDeeps)."->)\n";
    printLog($printStr);
    #print $fileHandle $printStr;

    $g_totalIncCount++;
    printBoth("[$g_totalIncCount][$incFile] included\n");
    
    # mark as included if appropriate
    $g_incInfo{$incFile}[$idxIncluded] = 1 if (!$alwaysExpand);
    printLog("//[hExpand.pl][$incFile][alwaysExpand] = $alwaysExpand, [included] = ".$g_incInfo{$incFile}[$idxIncluded]."\n");
       
    if (scalar(@fileData) == 0)
    {
        open(hFile, "<$incPath\\$incFile") or die "can't open $incPath\\$incFile\n";
        @fileData = <hFile>;
        close(hFile);
    }

    my @incOrderList = ();
    if (!$lineRedirect)
    {
        @fileData = &removeComment(\@fileData) if ($removeCommentOrNot);    
        @fileData = &removeConsecutiveEmpty(\@fileData) if ($removeConsecutiveEmpty);
    }
    else
    {
        # find inc order first
        my @tmpData = &removeComment(\@fileData);
        foreach my $line (@tmpData)
        {
            if ($line =~ /^[\s]*\#include[\s]+([<\"])[\s]*([\w\.]+)[\s]*\1/)
            {
                push @incOrderList, lc $2;
            }
        }
    }

    # add line redirect
    my $incPrintPathName = "$incPath\\$incFile";
    $incPrintPathName =~ s/\\/\\\\/g;
    print $fileHandle "#line 1 \"$incPrintPathName\"\n" if ($lineRedirect);
    
    my $iMax = $#fileData;
    my $conditionalInclude = 0;
    my $ifDeeps = 0;
    my $nodeMax = 0;    # max node counts
    for (my $i=0; $i<=$iMax; $i++)
    {
        my $line = $fileData[$i];
        if ($line =~ /^[\s]*\#include[\s]+([<\"])[\s]*([\w\.]+)[\s]*\1/)
        {
            my $inc = lc $2;
            
            # make sure we get correct #include (not in comments)
            if ($lineRedirect)
            {
                if ($inc ne $incOrderList[0])
                {
                    print $fileHandle $line;
                    next;                
                }
                else
                {
                    shift @incOrderList;  # remove from list
                }
            }
            
            # bypass all target files, since we'll expand them one by one
            if ((defined $g_targetFileHash{$inc}) || $g_forceNotExpand || (defined $g_nonExpandList{$inc}))
            {
                printLog("[$inc] not to include");
                print $fileHandle $line;
                next;
            }
            
            printLog("[$inc] found\n");

            push @incDeeps, $incFile;
            $incTreeHash{$incFile} = 1;

            my $nodeCount = 0;
            my $res = expandInc($fileHandle, $inc, ($alwaysExpand || $conditionalInclude), \$nodeCount);           
            my $tmpLine = "";

            #if ($conditionalInclude && !$alwaysExpand)
            {
                # get tree node counts
                printLog("//[hExpand.pl][$inc]\t[nodes = $nodeCount]\t[".join('->', @incDeeps)."]\n");
            }

            pop @incDeeps;
            delete $incTreeHash{$incFile};                
             
            if ($res == $valSuccess)
            {
                # do nothing
                $nodeMax = $nodeCount if ($nodeCount > $nodeMax);
                ($$nodeCount_ref) += 1 + $nodeCount;    # calculate tree-node count
                $tmpLine = "#line ".($i+1)." \"$incPrintPathName\"\n" if ($lineRedirect);
            }
            elsif ($res == $valAlreadyIncluded)
            {
                $printStr = "//[hExpand.pl][$inc] already included (".join('->', @incDeeps).")\n";
                #print $fileHandle $printStr;
                printLog($printStr);
                $tmpLine = "//$line" if ($lineRedirect);
            }
            elsif ($res == $valFileNotFound)
            {
                $printStr = "//[hExpand.pl][$inc] file not found\n";
                #print $fileHandle $printStr;
                printLog($printStr);
                $tmpLine = $line;    # file not found, keep #include "xxx"
            }
            elsif ($res == $valRecursiveInclude)
            {
                $printStr = "//[hExpand.pl][$inc] recursive include (".join('->', @incDeeps).")\n";
                #print $fileHandle $printStr;
                printLog($printStr);
                $tmpLine = "//$line" if ($lineRedirect);
            }
            print $fileHandle $tmpLine;
        }
        else
        {
            if ($line =~ /^[\s]*\#ifndef[\s]+([\w]+)/)
            {
                $ifDeeps++;
                my $wrapper = $1;
                if ((defined $fileData[$i+1]) && ($fileData[$i+1] =~ /^[\s]*\#define[\s]+$wrapper[^\w]+/) &&
                    ($wrapper =~ /_h[_]*$/i))
                {
                    printLog("//[hExpand.pl][wrapper] $wrapper\n");
                }
                else
                {
                    $conditionalInclude = $ifDeeps if ($conditionalInclude == 0);
                }
            }
            elsif ($line =~ /^[\s]*\#if/)
            {
                $ifDeeps++;
                $conditionalInclude = $ifDeeps if ($conditionalInclude == 0);
            }
            elsif ($line =~ /^[\s]*\#endif/)
            {
                if ($conditionalInclude == $ifDeeps)
                {
                    $conditionalInclude = 0;
                }
                $ifDeeps--;
            }
            elsif ($line =~ /<hExpand[\s]+noExpand[\s]*>/i)
            {
                $g_forceNotExpand = 1;
            }
            elsif ($line =~ /<\/hExpand>/i)
            {
                $g_forceNotExpand = 0;
            }

            print $fileHandle $line;
        }
    }
    
    if (($$nodeCount_ref - $nodeMax) >= $g_nodeThreshold)
    {
        printLog("//[hExpand.pl][$incFile][diff lt node threshold]\t[$$nodeCount_ref][$nodeMax][".($$nodeCount_ref - $nodeMax)."]\n");
    }
    
    print $fileHandle "\n";
    return $valSuccess;
}


#******************************************************************************
# FUNCTION
#  getIncWrapper
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub getIncWrapper()
{
    my ($fileData_aref) = @_;
    
    my @tmpData = &removeComment($fileData_aref);
    
    # remove beginning '#include'
    my $iMax = $#tmpData;
    for (my $i=0; $i<=$iMax; $i++)
    {
        my $line = $tmpData[$i];
        if ($line =~ /^[\s]*\#include/)
        {
        }
        elsif ($line =~ /^[\s]*$/)
        {
            # skip empty lines
        }
        elsif ($line =~ /^[\s]*\#if/)
        {
            @tmpData = @tmpData[$i..$iMax];
            last;
        }
    }
    
    my $str = join('', @tmpData);
    if ($str =~ /^[\s]*\#ifndef[\s]+([\w]+).*?\#endif[\s]*$/s)
    {
        # print "[$1] inc wrapper\n";
        return $1;
    }
    return "";
}


#******************************************************************************
# FUNCTION
#  removeComment
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub removeComment()
{
    my ($fileData_aref) = @_;
    
    my @outData = ();
    
    # remove '//'
    foreach my $line (@{$fileData_aref})
    {
        push @outData, $line if ($line !~ /^[\s]*\/\//);
    }
    
    my $tmpStr = join('', @outData);
    
    $tmpStr =~ s/(?<!\\)\/\*.*?\*\///sg;
    @outData = split("\n", $tmpStr);
    @outData = map {$_."\n"} @outData;
    return @outData;
}


#******************************************************************************
# FUNCTION
#  removeConsecutiveEmpty
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************
sub removeConsecutiveEmpty()
{
    my ($fileData_aref) = @_;
    
    my $tmpStr = join('', @{$fileData_aref});
    $tmpStr =~ s/\n{3,}/\n\n/sg;
    my @outData = split("\n", $tmpStr);
    @outData = map {$_."\n"} @outData;
    return @outData;    
}


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
sub searchIncPath()
{
    my ($incFile, $incPath_aref) = @_;
    
    if (defined $notFoundFileList->{$incFile})
    {
        return "";   
    }
    my $incPath = $foundFileList->{$incFile};
    if (defined $incPath)
    {
        return $incPath if (-e "$incPath\\$incFile")
    }
    
    foreach my $incPath (@{$incPath_aref})
    {
        my $filepath = "$incPath\\$incFile";
        if (-e $filepath)
        {
            $foundFileList->{$incFile} = $incPath;
            return $incPath;
        }
    }
    
    $notFoundFileList->{$incFile} = 1;
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


#******************************************************************************
# FUNCTION
#  timeCheck
# DESCRIPTION
#  print current time (in sec.) and time-difference to previous check if exists
# PARAMETERS
#  none
# RETURNS
#  current time and time difference if exists (both in sec.)
#******************************************************************************
my @timePrev = ();
sub timeCheck()
{
    my @timeCurr = localtime(time);
    printBoth("[Time: ".&timeInSec(\@timeCurr)." sec.");
    if (@timePrev > 0) # previous-time exists
    {
        printBoth("(Diff = ".&timeDiffInSec(\@timeCurr, \@timePrev).")");
    }
    printBoth("]\n");
    @timePrev = @timeCurr;    
}


#******************************************************************************
# FUNCTION
#  timeDiffInSec
# DESCRIPTION
#  get time difference in sec.
# PARAMETERS
#  para 1 - reference to time1 in localtime array format
#  para 2 - reference to time2 in localtime array format
# RETURNS
#  time difference in sec.
#******************************************************************************
sub timeDiffInSec()
{
    my $time1;
    my $time2;
    my $timeDiff;
    
    ($time1, $time2) = @_;
    
    $timeDiff = timeInSec($time1) - timeInSec($time2);
    if ($timeDiff < 0)
    {
        return (-$timeDiff);
    }
    return $timeDiff;
}


#******************************************************************************
# FUNCTION
#  timeInSec
# DESCRIPTION
#  time in sec.
# PARAMETERS
#  para - time in localtime array format
# RETURNS
#  time in sec.
#******************************************************************************
sub timeInSec()
{
    my @daysInMon = (31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);
    my $sec = $_[0][0];
    my $min = $_[0][1];
    my $hour = $_[0][2];
    my $day = $_[0][3];
    my $mon = $_[0][4]+1;
    my $year = $_[0][5];
    my $timeInSec;    
    
    if (isLeapYear($year+1900))
    {
        $daysInMon[1] = 29;
        $timeInSec = (((($year*366+$mon*$daysInMon[$mon-1]+$day)*24 + $hour)*60 + $min)*60 + $sec);
    }
    else
    {
        $timeInSec = (((($year*365+$mon*$daysInMon[$mon-1]+$day)*24 + $hour)*60 + $min)*60 + $sec);
    }
    return $timeInSec;
}


#******************************************************************************
# FUNCTION
#  isLeapYear
# DESCRIPTION
#  is input year leap-year
# PARAMETERS
#  year
# RETURNS
#  leap-year or not
#******************************************************************************
sub isLeapYear()
{
    my $year = $_[0];
    
    if (($year%4 == 0) && ($year%100 != 0))
    {
        return 1;
    }
    return 0;
}


sub findMismatchIf()
{
    my ($data_aref) = @_;
    
    my $nestNum = 0;
    my %nestHash = ();

    printLog("\n[findMismatchIf]\n");

    foreach my $line (@{$data_aref})
    {
        if ($line =~ /^[\s]*\#if/)
        {
            $nestNum++;
            $nestHash{$nestNum} = $line;
            #printLog("[$nestNum][+] $line");
            printLog("$line");
        }
        elsif ($line =~ /^[\s]*\#endif/)
        {
            #printLog("[$nestNum][-] $nestHash{$nestNum}");
            delete $nestHash{$nestNum};
            $nestNum--;
        }
    }
    my @nestIdx = sort keys(%nestHash);

    foreach my $idx (@nestIdx)
    {
        printLog("[$idx] $nestHash{$idx}\n");
    }
}

sub printBoth()
{
    my ($str) = @_;
    print $str;
    print $logFileHandle $str;
}

sub printLog()
{
    my ($str) = @_;
    print $logFileHandle $str;
}


sub trim()
{
    my ($str) = @_;
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}
