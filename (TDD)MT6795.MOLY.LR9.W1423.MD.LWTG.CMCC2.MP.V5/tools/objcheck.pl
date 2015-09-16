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
#  objcheck.pl
#
# Description: 
# ------------
#  this script is used to check run-time values, e.g. 'size of each element of union'.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#  Support Status
#  1. union/struct      (o)
#  2. multi-setting     (o)
#
# Log: 
# -----
#  2008/02/22   Create.
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
#package XXX;  
use strict;

#******************************************************************************
# Global Data
#******************************************************************************
my $g_settingFilename = "objcheck.txt";
my $g_logFile = "objcheck.log";
my $g_logCompileFile = "objcheck.compile.log";
my $g_htmlFile = "objcheck.html";

my $g_prjName = '';
my $g_mcuPath = ".";

# remove temp file or not
my $g_removeTempFile = 1;

# also process disabled features or not
my $g_alsoProcessDisabledFeatures = 1;

my $g_compiler = 'armcc';   # default compiler
my $g_viaOption = '--via';  # default 'via' option

my $local_run = 1;          # in local folder (1) or in mcu folder (0)

my $checkMainFilename;

my $separation = "***********************************************************************";

my $magicNumber = "26598088";

my $str_objcheck = "objcheck";
my $str_info = "info";
my $str_removeTmpFile = "removeTmpFile";
my $str_alsoProcessDisabledFeatures = "alsoProcessDisabledFeatures";
my $str_mcuPath = "mcuPath";
my $str_prjName = "prjName";
my $str_filename = "filename";
my $str_path = "path";
my $str_type = "type";
my $str_parsingInc = "parsingInc";
my $str_addModuleInc = "addModuleInc";
my $str_addIncPath = "addIncPath";
my $str_addIncFiles = "addIncFiles";
my $str_addLines = "addLines";
my $str_addPostLines = "addPostLines";
my $str_addFeaturesToWatch = "addFeaturesToWatch";

# tag name and in-tag/end-tag handler
my %xmlTags = ( $str_objcheck           => \&objcheck_tag_hdlr,
                $str_info               => \&info_tag_hdlr, 
                $str_addModuleInc       => \&addModuleInc_tag_hdlr, 
                $str_addIncPath         => \&addIncPath_tag_hdlr,
                $str_addIncFiles        => \&addIncFiles_tag_hdlr, 
                $str_addLines           => \&addLines_tag_hdlr,
                $str_addPostLines       => \&addPostLines_tag_hdlr,
                $str_addFeaturesToWatch => \&addFeaturesToWatch_tag_hdlr);

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my %settingData = ();

#******************************************************************************
# Program Start
#******************************************************************************

# get project name from input argument
if (scalar(@ARGV) == 0)
{
    my @usage = ();
    push @usage, "\nUsage 1:\n'objcheck.pl <project name> <compiler> <via option>'\n";
    push @usage, "e.g. 'objcheck.pl DRAGONFLY_DEMO armcc --via'\n\n";
    push @usage, "Usage 2: (in local directory)\n'objcheck.pl local <compiler> <via option>'\n";
    die join('', @usage);
}
else
{
    ($g_prjName, $g_compiler, $g_viaOption) = @ARGV;       
}

if ($g_prjName !~ /^local$/i)
{
    $g_settingFilename = "tools\\".$g_settingFilename;
    $local_run = 0;
}

$g_logFile = "build\\$g_prjName\\log\\".$g_logFile if (!$local_run);
system("del $g_logFile") if (-e "$g_logFile");

$g_logCompileFile = "build\\$g_prjName\\log\\".$g_logCompileFile if (!$local_run);
system("del $g_logCompileFile") if (-e "$g_logCompileFile");

$g_htmlFile = "build\\$g_prjName\\log\\".$g_htmlFile if (!$local_run);
system("del $g_htmlFile") if (-e "$g_htmlFile");

print "\nobjcheck: Start\n";

# write parameter
open(hFile, ">>$g_logCompileFile") or die "can't open $g_logCompileFile";
print hFile "===========================================================\n";
print hFile "$g_prjName\n";
print hFile "$g_compiler\n";
print hFile "$g_viaOption\n";
print hFile "===========================================================\n";
close(hFile);    

# start processing
&getSettings($g_settingFilename, \%settingData);
print "objcheck: Log generated to $g_logFile\n";

&runMemLayout($g_htmlFile);
print "objcheck: Html generated to $g_htmlFile\n";

print "objcheck: End\n\n";

exit 0;


#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  startCheck
# DESCRIPTION
#  start obj check
# PARAMETERS
#  
# RETURNS
#  none
#******************************************************************************
sub startCheck()
{
    my $settingData_href;

    ($settingData_href) = @_;
    
    my $targetFilepath = ${$settingData_href}{$str_path};
    my $targetFilename = ${$settingData_href}{$str_filename};
    my $parsingInc = ${$settingData_href}{$str_parsingInc};
    my @fileData = ();
    my $type;
    my $retVal = 0;

    # list the modules which their *.inc will be added into include path
    my $includeMod = ${$settingData_href}{$str_addModuleInc};    # include *.inc
        
    # additional path for include files
    my $addIncPath = ${$settingData_href}{$str_addIncPath};
    unshift @{${$settingData_href}{$str_addIncPath}}, $targetFilepath;
                      
    # additional include files      
    my $addIncFiles = ${$settingData_href}{$str_addIncFiles};       #("mmi_features.h");
    
    # additional lines
    my $addLines = ${$settingData_href}{$str_addLines};
       
    # additional features to watch
    my $addFeaturesToWatch = ${$settingData_href}{$str_addFeaturesToWatch};

    print "objcheck: [$targetFilename] Begin\n";
    
    while (($type = shift @{${$settingData_href}{$str_type}}) ne "")
    {
        my %featureList = ();
        my @unionInOrder = ();
        my @sortedAllFeatures = ();
        my @defFeatures = ();
        my @undefFeatures = ();
        my $allFeatureCount;
        my $defFeatureCount;
        my $undefFeatureCount;
        
        $checkMainFilename = "~".splitFilename($targetFilename, 0)."_check";
        my $checkTmpMainFilename = "$checkMainFilename"."_tmp";      
        my $checkFile = "$g_mcuPath\\$targetFilepath\\$targetFilename";
        
        # get all feature list
        if (!(-e $checkFile))
        {
            print "objcheck: [Warning] $checkFile not exist!\n";
            return;
        }
        
        open(hFile, "<$checkFile") or die "can't open $checkFile";
        @fileData = <hFile>;
        close(hFile);
    
        print "objcheck:   ($type) Begin\n";
        &timeCheck("    --> ", "");
        print "objcheck:     --> Reading...\n";
    
        if ($type eq 'macro')       
        {
            # get macros
            getMacro(\@fileData, \%featureList);
            push @sortedAllFeatures, sort(keys(%featureList));        
        }
        elsif ($type eq 'obj')
        {
            # get union from target file
            my @targetUnionInOrder = ();
            getUnion(\@fileData, \@targetUnionInOrder) if ($parsingInc == 0);

            #####
            # At this stage, we only need compile option (check member of union is turned on)
            # To speed up the -E and reading, try to modify array size to const
            #####

            # gen shrinked target file
            my $shrinkTargetFilename = "~".splitFilename($targetFilename, 0)."_shrink.h";
            open(hShrinkFile, ">$shrinkTargetFilename") or die "can't open $shrinkTargetFilename";
            foreach my $line (@fileData)
            {
                if ($line =~ /([^\[]*)\[([^\]]*)\](\;.*)/)
                {
                    print hShrinkFile $1 . "[1]" . $3 . "\n";
                }
                else
                {
                    print hShrinkFile "$line";
                }
            }
            close(hShrinkFile);

            # gen pre-processed tmp file   
            genCheckDotC($type . "_expand", "$checkTmpMainFilename.c", $shrinkTargetFilename, \@sortedAllFeatures, $settingData_href);
            processCheckDotC($checkTmpMainFilename, "-E", $settingData_href, $g_removeTempFile);
            $checkFile = "$checkTmpMainFilename.obj";

            # remove shrinked target file
            if ($g_removeTempFile)
            {
                system("del $shrinkTargetFilename") if (-e "$shrinkTargetFilename");
            }

            if (!(-e $checkFile))
            {
                my $timeCost = &timeCheck("    --> ", "");
                my $logTitle = "$targetFilename\t($type) (timeCost=$timeCost sec.)\n ($g_mcuPath\\$targetFilepath)";
                genLogInfo($type, $g_logFile, $logTitle, "Skip due to compile error, check $g_logCompileFile");
                print "objcheck:     [Error] compile error! skip\n";
                next;
            }

            # read pre-processed file
            open(hFile, "<$checkFile") or die "can't open $checkFile";
            @fileData = <hFile>;
            close(hFile);      
    
            # get union from pre-processed file (means it really exists)
            my %unionTmp = ();
            getUnion(\@fileData, \@unionInOrder, \%unionTmp);
                        
            if ($parsingInc == 0)
            {
                foreach my $targetUnion (@targetUnionInOrder)
                {
                    # if targetUnion really exists
                    push @sortedAllFeatures, $targetUnion if (defined ${unionTmp}{$targetUnion});
                }
            }
            else
            {
                push @sortedAllFeatures, @unionInOrder if (scalar(@unionInOrder));
            }
        }
        elsif ($type eq 'obj2')
        {
            #####
            # no compile option, no need to pre-process.
            #####
            
            # get union from target file
            my @targetUnionInOrder = ();
            getUnion(\@fileData, \@targetUnionInOrder);

            foreach my $targetUnion (@targetUnionInOrder)
            {
                push @sortedAllFeatures, $targetUnion;
            }            
        }
        else
        {
            print "[objcheck.pl][Warning] $type not supported!\n";
            next;
        }
           
        # add additional features to watch
        push @sortedAllFeatures, @{$addFeaturesToWatch} if (defined $addFeaturesToWatch);
        
        $allFeatureCount = @sortedAllFeatures;
           
        # generate XXX_check.c
        print "objcheck:     --> Generating...\n";
        genCheckDotC($type, "$checkMainFilename.c", $targetFilename, \@sortedAllFeatures, $settingData_href);
        
        # validate features
        print "objcheck:     --> Compiling...\n";
        my $compileOption = "-c";
        $compileOption = "-E" if ($type eq 'macro');
        processCheckDotC($checkMainFilename, $compileOption, $settingData_href, $g_removeTempFile);

        if (!(-e "$checkMainFilename.obj"))
        {
            my $timeCost = &timeCheck("    --> ", "");
            my $logTitle = "$targetFilename\t($type) (timeCost=$timeCost sec.)\n ($g_mcuPath\\$targetFilepath)";
            genLogInfo($type, $g_logFile, $logTitle, "Skip due to compile error, check $g_logCompileFile");
            print "objcheck:     [Error] compile error! skip\n";
            next;
        }
        
        # check def/undef features in pre-processed file
        print "objcheck:     --> Checking...\n";
        checkFeatures($type, "$checkMainFilename.obj", \%featureList, \@sortedAllFeatures, \@defFeatures, \@undefFeatures);
        $defFeatureCount = @defFeatures;
        $undefFeatureCount = @undefFeatures;
        
        if ($g_removeTempFile)
        {
            system("del $checkMainFilename.c") if (-e "$checkMainFilename.c");
            system("del $checkMainFilename.obj") if (-e "$checkMainFilename.obj");
            system("del $checkTmpMainFilename.c") if (-e "$checkTmpMainFilename.c");
            system("del $checkTmpMainFilename.obj") if (-e "$checkTmpMainFilename.obj");        
        }    
        
        # output results
        my $timeCost = &timeCheck("    --> ", "");
        my $logTitle = "$targetFilename\t($type) (timeCost=$timeCost sec.)\n ($g_mcuPath\\$targetFilepath)";
        genLog($type, $g_logFile, $logTitle, \@defFeatures, \%featureList,
                \@undefFeatures, \@sortedAllFeatures);
        print "objcheck:     --> Log generated\n";
        
        # verify result
        if ($allFeatureCount != ($defFeatureCount+$undefFeatureCount))
        {
            print "[Error] all feature count($allFeatureCount) != defined count($defFeatureCount) + undef count($undefFeatureCount)\n";
                $retVal = 1;
        }
        else
        {
                print "objcheck:     Done! ([$targetFilename] [$type] defined count = $defFeatureCount)\n";
        }
        print "objcheck:   ($type) End\n";
    }

    print "objcheck: [$targetFilename] End\nobjcheck:\n";
    return $retVal;
}

#******************************************************************************
# FUNCTION
#  genCheckDotC
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub genCheckDotC()
{
    my $type;
    my $filename;
    my $targetFilename;
    my @fileData;
    my $pUserData;  # reference to data array
    my $settingData_href;
    
    ($type, $filename, $targetFilename, $pUserData, $settingData_href) = @_;
        
    open(hFile, ">$filename") or die "can't open $filename";
       
    print hFile "// addLines\n";
    foreach my $line (@{${$settingData_href}{$str_addLines}})
    {
        print hFile "$line\n";
    }

    print hFile "// addLines by type\n";
    foreach my $line (@{${$settingData_href}{$str_addLines . "_" . $type}})
    {
        print hFile "$line\n";
    }
       
    # write header part
    
    print hFile "// addIncFiles\n";
    foreach my $inc (@{${$settingData_href}{$str_addIncFiles}})
    {
        print hFile "#include \"$inc\"\n";
    }
    
    print hFile "#include \"$targetFilename\"\n\n";
    
    foreach my $data (@{${$settingData_href}{$str_addPostLines}})
    {
        print hFile $data;
    }
    
    # write start tag    
    print hFile "\nvoid * feature_check[] = {\n"; 
    
    if ($type eq 'macro')
    {
        foreach my $data (@$pUserData)
        {
            print hFile "(void *)$data,\n";
        }
        
        # write end tag
        print hFile "(void *)\"END FEATURE LIST\"\n";
    }
    elsif (($type eq 'obj') || ($type eq 'obj2'))
    {
        print hFile "(void *)0x$magicNumber,\n";
        
        foreach my $data (@$pUserData)
        {
            print hFile "(void *)($data),\n";
        }
        
        # write end tag
        print hFile "(void *)0x$magicNumber\n";
    }
    else
    {
        print hFile "0\n";
    }

    print hFile "};\n";
    close(hFile);
}


#******************************************************************************
# FUNCTION
#  processCheckDotC
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub processCheckDotC()
{
    my $mainFilename;
    my $compileOptions;
    my $settingData_href;
    my $removeTmpFile;
    
    ($mainFilename, $compileOptions, $settingData_href, $removeTmpFile) = @_;
    
    my $includeMod = ${$settingData_href}{$str_addModuleInc};    # include *.inc       
    my $addIncPath = ${$settingData_href}{$str_addIncPath};
    
    my $infoFilename = "$g_mcuPath\\build\\$g_prjName\\log\\info.log";
    my $batFilename = "~makeCheck.bat";
    my $defTmpFilename = "$mainFilename.def";
    my $incTmpFilename = "$mainFilename.inc";
    my @fileData;
    my $inSection = 0;
    my $incPaths = "";
     
    my $count = 0;    
    my $commonOptions = "";

    # read common options and common include path from info.log     
    open(hFile, "<$infoFilename") or die "can't open $infoFilename";
    @fileData = <hFile>;
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
                $commonOptions = "$commonOptions\n-D$1";
            }
            elsif ($inSection == 2)
            {
                my $inc = "$1";
                
                if ($inc !~ /:/)
                {
                    $inc = "$g_mcuPath\\$inc";
                }
                #print "$inc\n";
                $incPaths = "$incPaths\n-I$inc";
            }
        }
        else            
        {
            $inSection = 0;
        }
    }
    
    # read inc from *.inc
    foreach my $myMod (@{$includeMod})
    {
        my @incFiles = ();
        if (&getFileList("$g_mcuPath\\build\\$g_prjName\\module\\$myMod\\*.inc", 1, \@incFiles) > 0)
        {
            foreach my $incFilename (@incFiles)
            {
                open(hFile, "<$incFilename") or die "can't open $incFilename";
                @fileData = <hFile>;
                close(hFile);
                
                foreach my $line (@fileData)
                {
                    if ($line =~ /(^[^\s]+)([\s]*$)/)
                    {
                        $incPaths = "$incPaths\n-I$g_mcuPath\\$1";
                    }
                }
            }            
        }
        else
        {
            print "[Warning] can't find *.inc for $myMod\n";
        }
    }
    
    # additional inc path
    foreach my $inc (@{$addIncPath})
    {
        $incPaths = "$incPaths\n-I$g_mcuPath\\$inc";
    }     
    
    # read macro from *.def
    foreach my $myMod (@{$includeMod})
    {
        my @defFiles = ();
        if (&getFileList("$g_mcuPath\\build\\$g_prjName\\module\\$myMod\\*.def", 1, \@defFiles) > 0)
        {
            foreach my $defFilename (@defFiles)
            {
                open(hFile, "<$defFilename") or die "can't open $defFilename";
                @fileData = <hFile>;
                close(hFile);
                
                foreach my $line (@fileData)
                {
                    if ($line =~ /(^[^\s]+)([\s]*$)/)
                    {
                        $commonOptions = "$commonOptions\n-D$1";
                    }
                }
            }            
        }
        else
        {
            print "[Warning] can't find *.def for $myMod\n";
        }        
    }
  
    #print "$commonOptions\n";
    open(hFile, ">$defTmpFilename") or die "can't open $defTmpFilename";
    print hFile "$commonOptions\n";
    close(hFile);
    
    #print "$incPaths\n";
    open(hFile, ">$incTmpFilename") or die "can't open $incTmpFilename";
    print hFile "$incPaths\n";
    close(hFile);    

    # prepare for compiler output    
    open(hFile, ">>$g_logCompileFile") or die "can't open $g_logCompileFile";
    print hFile "===========================================================Begin\n";
    print hFile "[Processing...](".${$settingData_href}{$str_filename}.")\n";
    close(hFile);    

    open(hFile, ">$batFilename") or die "can't open $batFilename\n";
    print hFile "\@echo off\n";
    print hFile "$g_compiler $mainFilename.c -o $mainFilename.obj $compileOptions $g_viaOption $defTmpFilename $g_viaOption $incTmpFilename 2>>$g_logCompileFile\n";
    print hFile "\@echo on\n";
    close(hFile);   
   
    #&timeCheck();
    system("$batFilename");    
    #&timeCheck();

    # end compiler output    
    open(hFile, ">>$g_logCompileFile") or die "can't open $g_logCompileFile";
    print hFile "=============================================================End\n\n";
    close(hFile);    

    # remove empty lines for -E
    if ($compileOptions =~ /-e([\s]+|$)/i)
    {
        open(hFile, "<$mainFilename.obj") or die "can't open $mainFilename.obj\n";
        my $tmp = join('',<hFile>);
        close(hFile);
        $tmp =~ s/\n([\s]+)\n/\n\n/g;    # reduce multi-CR/LF
        open(hFile, ">$mainFilename.obj") or die "can't open $mainFilename.obj for write\n";
        print hFile $tmp;
        close(hFile);
    }
        
    if ($removeTmpFile)
    {
        system("del $batFilename");        
        system("del $defTmpFilename");
        system("del $incTmpFilename");
    }    
}


#******************************************************************************
# FUNCTION
#  checkFeatures
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub checkFeatures()
{
    my $type;               # 'obj' or 'macro'
    my $filename;           # preprocessed object filename
    my $pFeatureList;       # reference to hash of feature list
    my $pSortedAllFeatures; # reference to array of sorted all features
    my $pDefFeatures;       # reference to array of defined features
    my $pUndefFeatures;     # reference to array of undefined features

    my @fileData;
    my $isFeature = 0;
    my $featureIndex;
    my $defFeature;
    
    ($type, $filename, $pFeatureList, $pSortedAllFeatures, 
        $pDefFeatures, $pUndefFeatures) = @_;  
       
    if ($type eq 'macro')
    {       
        open(hFile, "<$filename") or die "can't open $filename";
        @fileData = <hFile>;
        close(hFile);

        open(hFile, ">>$g_logCompileFile") or die "can't open $g_logCompileFile";
        print hFile "===========================================================Begin\n";
        print hFile "[checkFeatures](".$filename.":".$type.")\n";

        foreach my $line (@fileData)
        {
            if ($isFeature)
            {
                if ($line =~ /(^\(void \*\)[\s]*)(.*?)([\s]*,$)/)
                {
                    $defFeature = $$pSortedAllFeatures[$featureIndex];
                    
                    if ($2 eq $defFeature)
                    {
                        # undefined symbols ("_XXX_" shows) 
                        
                        push @$pUndefFeatures, $2;
                       
                        # remove it from feature list
                        delete $$pFeatureList{$2};
                        
                        #print "[U] $2\n";                      
                    }
                    else
                    {
                        # process defined symbols
                        
                        push @$pDefFeatures, $defFeature;
                        
                        # update value of feature list
                        $$pFeatureList{$defFeature} = $2;
                        
                        #print "[D] $defFeature = $2\n";       
                    }         
                }
                # end of feature list
                elsif ($line =~ /"END FEATURE LIST"}/)
                {
                    $isFeature = 0;
                }            
                elsif ($line !~ /^[\s]*$/)
                {
                    print hFile "[Not Processed] \"$line\"\n";
                }
                
                #print "[$featureIndex] $$pSortedAllFeatures[$featureIndex] $line\n";
                $featureIndex++;
            }
    
            # check if begining of feature list
            if ($line =~ /feature_check\[\]/)
            {
                $isFeature = 1;
                $featureIndex = 0;
            }
        }
        
        print hFile "=============================================================End\n\n";
        close(hFile);    
    }    
    else    # 'obj'
    {
        open(hFile, "<$filename") or die "can't open $filename";
        binmode(hFile);
        my $binData;
        my $status = '';
        while (read(hFile, $binData, 4))
        {
            if ($status eq 'start')
            {
                my $value = ascii2dec_le($binData);
                if ($value == hex($magicNumber))
                {
                    #print "END\n";
                    last;
                }
                
                $defFeature = $$pSortedAllFeatures[$featureIndex];
                $featureIndex++;
                
                push @$pDefFeatures, $defFeature;
                # update value of feature list
                $$pFeatureList{$defFeature} = $value;
                #print "$defFeature = $value\n";
            }
    
            # begin of array
            if (ascii2dec_le($binData) == hex($magicNumber))
            {
                $status = 'start';
                $featureIndex = 0;
                #print "Start\n";
            }
        }
        close(hFile);
    }

}


#******************************************************************************
# FUNCTION
#  getSettings
# DESCRIPTION
#  get settings from file
# PARAMETERS
#  $filename        [IN] - setting file pathname
#  $targetHash_ref  [IN] - reference to target hash
# RETURNS
#  none
#******************************************************************************
sub getSettings()
{
    my $filename;
    my $settingData_href;

    ($filename, $settingData_href) = @_;
    
    my @fileData;
    #my %settingData = ();    
        
    open(hFile, "<$filename") or die "can't open $filename\n";
    @fileData = <hFile>;
    close(hFile);
    
    # parse setting file
    parseXmlLineData(\@fileData, \%xmlTags, $settingData_href);
}


sub objcheck_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;
    
    #print "tag hdlr [0]\n";
    
    &startCheck($para_href);
    %{$para_href} = ();     # reset setting data
}


sub info_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;
    
    #print "tag hdlr [1]\n";
    
    while (my ($attr, $value) = each(%{$$taginfo_aref[0]}))
    {
        #print "    attr [$attr] = $value\n";
        ${$para_href}{$str_filename}    = $value if ($attr eq $str_filename);
        ${$para_href}{$str_path}        = $value if ($attr eq $str_path);
        ${$para_href}{$str_parsingInc}  = $value if ($attr eq $str_parsingInc);
        if ($attr eq $str_type)
        {
            push @{${$para_href}{$str_type}}, split(',', $value);
        }
        
        $g_mcuPath = $value if (($attr eq $str_mcuPath) && ($str_mcuPath ne ""));
        $g_prjName = $value if (($attr eq $str_prjName) && ($str_prjName ne ""));
        $g_removeTempFile = $value if ($attr eq $str_removeTmpFile);
        $g_alsoProcessDisabledFeatures = $value if ($attr eq $str_alsoProcessDisabledFeatures);
    }
}

sub addModuleInc_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [2]\n";
    push @{${$para_href}{$str_addModuleInc}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addModuleInc}})."\n";
}

sub addIncPath_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [3]\n";
    push @{${$para_href}{$str_addIncPath}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addIncPath}})."\n";
}

sub addIncFiles_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [4]\n";
    push @{${$para_href}{$str_addIncFiles}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(', ',@{${$para_href}{$str_addIncFiles}})."\n";
}

sub addLines_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    my $type = undef;

    # attribute
    while (my ($attr, $value) = each(%{$$taginfo_aref[0]}))
    {
        $type = $value if (($attr eq $str_type) && ($str_type ne ""));
    }

    #print "tag hdlr [5]\n";
    if (!defined($type))
    {
        push @{${$para_href}{$str_addLines}}, trim($_) foreach (@{$$taginfo_aref[1]});
    }
    else
    {
        push @{${$para_href}{$str_addLines . "_" . $type}}, trim($_) foreach (@{$$taginfo_aref[1]});
    }
    #print join(' ',@{${$para_href}{$str_addLines}})."\n";
}

sub addPostLines_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    push @{${$para_href}{$str_addPostLines}}, trim($_)."\n" foreach (@{$$taginfo_aref[1]});    
}

sub addFeaturesToWatch_tag_hdlr()
{
    my $taginfo_aref;
    my $para_href;
    
    ($taginfo_aref, $para_href) = @_;

    #print "tag hdlr [6]\n";
    push @{${$para_href}{$str_addFeaturesToWatch}}, trim($_) foreach (@{$$taginfo_aref[1]});
    #print join(' ',@{${$para_href}{$str_addFeaturesToWatch}})."\n";
}


#******************************************************************************
# FUNCTION
#  getUnion
# DESCRIPTION
#  get union from file
# PARAMETERS
#  
# RETURNS
#  none
#******************************************************************************
sub getUnion()
{
    my $srcDataRef;
    my $dataARef;
    my $dataHRef;
    
    ($srcDataRef, $dataARef, $dataHRef) = @_;
         
    # remove comments
    my $tmpStr = join('', @{$srcDataRef});
    $tmpStr =~ s/(\/\*.*?\*\/)//gs; # remove all C comments
    $tmpStr =~ s/(\/\/.*)//g;       # remove all C++ comments                 
                                                   
    # find union
    while ($tmpStr =~ /[\s]+typedef[\s]+(union|struct)[\s]*\{([^\{\}]+?)\}[\s]*([\*]*)[\s]*([\w]+)[\s]*\;/sg)
    {
        #my $typedef = $1;
        my $type = $1;
        my $data = $2;      
        my $ptrStr = $3;
        my $unionName = $4;
        my $str = "";
       
        #print "====>>> [$unionName][$typedef] [$type] [$ptrStr]\n";
        $str = "sizeof($unionName)";
        push @{$dataARef}, $str if (defined $dataARef);
        ${$dataHRef}{$str} = "" if (defined $dataHRef);
                
        my @dataArray = ();
        @dataArray = split(';', $data);
        foreach my $line (@dataArray)
        {
            # [^:] => exclude bit-field
            if (($line =~ /[^:]+[\s]+[\*]*([\w]+)[\s]*$/) ||
                ($line =~ /[^:]+[\s]+[\*]*([\w]+)[\s]*\[[^\]]+\][\s]*$/))
            
            {
                if ($type eq 'union' || $type eq 'struct')
                {
                    $str = "sizeof(($ptrStr($unionName *)0)->$1)";
                    push @{$dataARef}, $str if (defined $dataARef);
                    ${$dataHRef}{$str} = "" if (defined $dataHRef);
                }
            }
        }
    }
}



sub getMacro()
{
    my $srcDataRef;
    my $dataHRef;
    
    ($srcDataRef, $dataHRef) = @_;
    
    foreach my $line (@{$srcDataRef})
    {
        my $feature = "";
        
        # also process marked "//" features or not
        if ($g_alsoProcessDisabledFeatures)
        {
            if ($line =~ /^([\s]*([\/]{2,})?[\s]*)(#define[\s]+)([\w_]+)([\s]+)([\w\(\)]+)/)
            {
                $feature = $4;
            }
        }
        else
        {
            if ($line =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]+)([\w\(\)]+)/)
            {
                $feature = $3;
            }
        }   
        
        if ($feature ne "")
        {
            ${$dataHRef}{$feature} = "";
        }
    }         
}


#******************************************************************************
# FUNCTION
#  parseXmlLineData
# DESCRIPTION
#  parse XML data lines (usage ref. ffcheck_any.pl)
# PARAMETERS
#  $lineData_aref - ref. to array of line data
#  $interestXmlTags_aref - ref. to hash of interested xml tags
#  $taginfo_href - reference to tag info hash  {tag => [0] {attr => value}}
#                                                   [1] [] data lines
# RETURNS
#  none
#******************************************************************************
sub parseXmlLineData()
{
    my $lineData_aref;          # ref. to xml line data
    my $xmlTags_href;           # ref. to interested xml tags
    my $para_href;              # ref. to user parameter
          
    ($lineData_aref, $xmlTags_href, $para_href) = @_;
   
    my $inXmlTag = 0;
    my $currTag = "";  
    my @tagStack = ();
    my %taginfo;                # parsed tag info
                                # {tag => [0] {attr => value}}
                                #         [1] [] data lines
    my %attrInfo = ();
   
    foreach my $line (@$lineData_aref)
    {       
        %taginfo = ();
        if (($line =~ /(^[ \t]*\#)|(^[\s]*$)/) && ($inXmlTag == 0))
        {
            # ignore comments or empty line, except in Xml tag processing
        }
        elsif ($line =~ /(<)([^>]+)(>)/)
        {
            my $tagData = $2;
            my $newTag;
    
            %attrInfo = ();
    
            ($inXmlTag, $newTag) = processTagInt($tagData, \%taginfo);
            #print "ret val = $inXmlTag new[$newTag] curr[$currTag]\n";
            #print "${$xmlTags_href}{$newTag}\n" if (exists ${$xmlTags_href}{$newTag});
            
            %attrInfo = %{$taginfo{$newTag}[0]} if (defined($taginfo{$newTag}[0]));
            
            if ($inXmlTag == 0)
            {
                if (exists ${$xmlTags_href}{$newTag})
                {
                    # if tag found and hdlr exists, execute the hdlr after whole tag processed
                    ${$xmlTags_href}{$newTag}($taginfo{$newTag}, $para_href) if (${$xmlTags_href}{$newTag} != 0);
                }
                
                pop @tagStack if ($newTag eq $currTag);
            }            
            # update tag for in-tag process
            elsif ($newTag ne $currTag)     # && ($inXmlTag == 1)
            {
                push @tagStack, $currTag if ($currTag ne "");
                $currTag = $newTag;
            }
        }
        elsif ($line =~ /([^\n]+)(\n$)/)
        {
            if ($inXmlTag == 1)
            {
                $line =~ s/(^\s*)|(\s*$)//g;
                push @{$taginfo{$currTag}[1]}, $line if ($line ne "");

                %{$taginfo{$currTag}[0]} = %attrInfo;

                if (exists ${$xmlTags_href}{$currTag})
                {
                    # if tag found and hdlr exists, execute the hdlr after whole tag processed
                    ${$xmlTags_href}{$currTag}($taginfo{$currTag}, $para_href);
                }
            }
        }
    }    
}


#******************************************************************************
# FUNCTION
#  processTag
# DESCRIPTION
#  process tag 
# PARAMETERS
#  para 1 - tag to process
#  para 2 - reference to attribute hash  {tag => {attr => value}}
# RETURNS
#  success (tag name) or not ("")
#******************************************************************************
sub processTagInt()
{
    my $tagToProcess;       # tag to process
    my $result_href;        # reference to result hash
           
    ($tagToProcess, $result_href) = @_;

    my $tagName = "";
    my $inTag = 0;
    
    $tagToProcess =~ s/(^[\s]*)|([\s]*$)//g;
    if ($tagToProcess =~ /^([\w_]+)$/i)
    {
        # start of tag
        $tagName = $1;
        $inTag = 1;
    }
    elsif ($tagToProcess =~ /^\/[ \t]*([\w_]+)$/i)
    {
        # end of tag
        $tagName = $1;
    }
    elsif ($tagToProcess =~ /(^[\w_]+)[ \t]+(([\w_]+[ \t]*=[ \t]*([\"\'])[^\4]+\4[ \t]*)+)(\/?$)/i)
    {
        #print "$tagToProcess\n";
        my @attrAll = split(' ',$2);
        $tagName = $1;
        
        # if tag ends with '/'
        $inTag = 1 if ($5 ne '/');
        
        # parse each attr
        foreach my $attr (@attrAll)
        {
            #print "[$attr]\n";
            if ($attr =~ /([\w_]+)[ \t]*=[ \t]*([\"\'])([^\2]+)\2/i)
            {
                ${$result_href}{$tagName}[0]{$1} = $3;
                #print "[$tagName] [$1] [$3]\n"; 
            }
        }
    }
    else
    {
        #print "[$tagToProcess] not processed\n";
    }

    return ($inTag, $tagName);
}


sub ascii2dec_le()
{
    my $input;
    
    ($input) = @_;
    
    my $output = ord(substr($input, 3, 1))*256*256*256+
                 ord(substr($input, 2, 1))*256*256+
                 ord(substr($input, 1, 1))*256+
                 ord(substr($input, 0, 1));
    #print "$input = $output";
}


#******************************************************************************
# FUNCTION
#  splitFilename
# DESCRIPTION
#  xxx
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
        if ($refSubFilename != 0)
        {
            $$refSubFilename = "$3";
        }
    }
    return $mainFilename;
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
#  genLog
# DESCRIPTION
#  xxx
# PARAMETERS
#  $filename [IN] - log file pathname
# RETURNS
#  none
#******************************************************************************
sub genLog()
{
    my $type;
    my $logFilePathname;
    my $logTitle;
    my $defFeatures_aref;
    my $featureData_href;
    my $undefFeatures_aref;
    my $sortedAllFeatures_aref;
    
    ($type, $logFilePathname, $logTitle, $defFeatures_aref, $featureData_href,
        $undefFeatures_aref, $sortedAllFeatures_aref) = @_;
    
    my $col1LenMax;
    my $col2LenMax;
    my $allFeatureCount;
    my $defFeatureCount;
    my $undefFeatureCount;    
    
    # append file
    open(hLogFile, ">>$logFilePathname") or die "can't open $logFilePathname";
    
    $allFeatureCount = @$sortedAllFeatures_aref;
    $defFeatureCount = @$defFeatures_aref;
    $undefFeatureCount = @$undefFeatures_aref;    
    
    # title
    print hLogFile "\n$separation\n $logTitle\n$separation\n";    
       
    # result: Defined Features
    print hLogFile "\n$separation\n[Defined Values ($defFeatureCount/$allFeatureCount)]\n$separation\n\n";
    if ($type eq 'macro')
    {
        $col1LenMax = 0;
        $col2LenMax = 0;
        foreach my $feature (@$sortedAllFeatures_aref)
        {
            # get max. len of feature name
            $col1LenMax = length($feature) if (length($feature)>$col1LenMax);
            
            # get max. len of feature value
            $col2LenMax = length(${$featureData_href}{$feature}) if (length(${$featureData_href}{$feature})>$col2LenMax);
        }      

        foreach my $feature (@$defFeatures_aref)
        {
            print hLogFile sprintf("[D] %-*s%s\n", $col1LenMax+8, 
                                $feature, ${$featureData_href}{$feature});
        }
    }
    else
    {
        my %nameHash = ();
        my %dataHash = ();
        
        # prepare data
        $col1LenMax = 0;
        $col2LenMax = 0;       
        foreach my $data (@$defFeatures_aref)
        {
            my $name = "";
            my $field = "";
            
            if ($data =~ /sizeof\((\w+)\)/)
            {
                $name = $1;
                $nameHash{$name} = ${$featureData_href}{$data};
            }
            elsif ($data =~ /sizeof\(\(\((\w+) \*\)0\)->(\w+)\)/)
            {
                $name = $1;
                $field = $2;
                $dataHash{$name}{$field} = ${$featureData_href}{$data};

                # get max. len of feature name
                my $nameField = $name."->".$field;
                my $value = ${$featureData_href}{$data};
                $col1LenMax = length($nameField) if (length($nameField)>$col1LenMax);
                
                # get max. len of feature value
                $col2LenMax = length($value) if (length($value)>$col2LenMax);                
            }
        }
       
        foreach my $name (sort keys(%nameHash))
        {
            print hLogFile sprintf("[D] %-*s%*s\n", $col1LenMax+8, 
                                    $name, $col2LenMax+2, $nameHash{$name});
            foreach my $field (sort {sortByValueDescending(\%{$dataHash{$name}})} keys(%{$dataHash{$name}}))
            {
                print hLogFile sprintf("[D] %-*s%*s\n", $col1LenMax+8, 
                                    $name."->".$field, $col2LenMax+2, $dataHash{$name}{$field});
            }
        }
    }
    print hLogFile "\n\n";
        
    close(hLogFile);    
}

sub genLogInfo()
{
    my $type;
    my $logFilePathname;
    my $logTitle;
    my $logText;
    
    ($type, $logFilePathname, $logTitle, $logText) = @_;
    
    # append file
    open(hLogFile, ">>$logFilePathname") or die "can't open $logFilePathname";
    
    # title
    print hLogFile "\n$separation\n $logTitle\n$separation\n";    
    
    # text
    print hLogFile $logText."\n";
    
    print hLogFile "\n\n";
        
    close(hLogFile);    
}

sub sortByValueDescending 
{
    my ($hash_ref) = @_;
    return ${$hash_ref}{$b} <=> ${$hash_ref}{$a};
}

sub trim()
{
    my $str;
    ($str) = @_;
    
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
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
my $timePrev = 0;
sub timeCheck()
{
    my $prePrintStr;
    my $postPrintStr;   
    my $timeCurr = time();
    my $timeDiff = 0;
    
    ($prePrintStr, $postPrintStr) = @_;
    
    print "objcheck: ";
    print "$prePrintStr" if ($prePrintStr ne "");
    print "[Time: ".$timeCurr." sec.";
    if ($timePrev > 0) # previous-time exists
    {
        $timeDiff = $timeCurr - $timePrev;
        print "(Diff = $timeDiff)";
    }
    print "]";
    print "$postPrintStr" if ($postPrintStr ne "");
    print "\n";
    $timePrev = $timeCurr;
    return $timeDiff;
}

sub runMemLayout
{
    my $htmlFile;
    my $batFilename = "~objcheck_runmem.bat";

    ($htmlFile) = @_;

    open(hFile, ">$batFilename") or die "can't open $batFilename\n";
    print hFile "\@echo off\n";
    print hFile "tools\\python25\\python tools\\py\\parse_mem_cfg.py --mcu . --proj $g_prjName 1>$htmlFile 2>>$g_logCompileFile\n";
    print hFile "\@echo on\n";
    close(hFile);   
   
    #&timeCheck();
    system("$batFilename");    
    #&timeCheck();

    system("del $batFilename");
}
