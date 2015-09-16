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
#  drv_feature_check.pl
#
# Description: 
# ------------
#  this script is used to do mmi feature check.
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
#  2007/03/11   Create.
#

#BEGIN { push @INC, 'U:/00MyPerlLib'}  # add additional library path
#package XXX;  
use strict;

#******************************************************************************
# Global Data
#******************************************************************************
my $returnErrorCode = 0;        # return error code or not
my $genLogTogether = 0;         # gen all logs in the same folder or not

my $g_mcuPath = '.';
my $headerFilename = "MMI_features.h";
my $switchFilename = "MMI_features_switch.h";
my $headerFilepath = 'plutommi/mmi/inc';
my $switchFilepath = 'plutommi/mmi/inc';

my $checkcfg = 'TRUE';       # check feature configuration or NOT

# list the modules which their *.inc will be added into include path
my @includeMod = ('plutommi');       # include *.inc

# additional path for include files
my @addIncPath = ();
                  
# additional include files      
my @addIncFiles = ();

# additional lines
my @addLines = ();

# additional features to watch
my @addFeaturesToWatch = ();

# remove temp file or not
my $g_removeTempFile = 1;

# also process disabled features or not
my $alsoProcessDisabledFeatures = 1;

# compiler
my $compiler = "armcc";
my $viaOption = "--via";

my $macro_on = "__ON__";
my $macro_off = "__OFF__";
my $macro_auto = "__AUTO__";

my $checkMainFilename;
my $logFilename;

my %featureList = ();
my @sortedAllFeatures = ();
my @defFeatures = ();
my @undefFeatures = ();
my %mismatchCFG = ();           # structure: { mismatch-cfg => [0] original config }
                                #                              [1] result config
my $allFeatureCount;
my $defFeatureCount;
my $undefFeatureCount;
my $separation = "***********************************************************************";

my $switch;
my $mmidrvfile;
#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my @fileData = ();
my $logPath = "";
my $prjName = "";
my %ignoredCFG = ();
my $mismatchCount;
my $buildFolder="";

#******************************************************************************
# Program Start
#******************************************************************************

# get project name from input argument
if (scalar(@ARGV) == 0)
{
    my @usage = ();
    push @usage, "\nUsage 1: 'drv_feature_check.pl <project name> <compiler> <via option> <feature filename> <switch filename> <checkCfg : TRUE, FALSE> <returnErrorOrNot> <MMI or DRV> <MMI_DEF_DEFS make file> <output path>'\n\n";
    push @usage, "Usage 2: 'drv_feature_check.pl <project name> <compiler> <via option> <filename> <filename> <checkCfg : TRUE, FALSE> <returnErrorOrNot> <MMI or DRV> <MMI_DEF_DEFS make file> <output path>'\n\n";
    push @usage, "e.g. 'drv_feature_check.pl DRAGONFLY_DEMO armcc --via plutommi/mmi/inc/mmi_features.h plutommi/mmi/inc/mmi_features.h FALSE 0'\n\n";
    die join('', @usage);
}
else
{
    ($buildFolder, $prjName, $compiler, $viaOption, 
        $headerFilename, $switchFilename, $checkcfg, $returnErrorCode, $mmidrvfile, $switch, $logPath) = @ARGV;
 
    $headerFilename = &splitPathName($headerFilename, \$headerFilepath);
    $switchFilename = &splitPathName($switchFilename, \$switchFilepath);
    push @addIncPath, $headerFilepath;
    push @addIncPath, $switchFilepath;
}

if ($switch =~ /DRV/ig)
{
	open FILEHANDLE, "<$g_mcuPath/$headerFilepath/$headerFilename" or die "Cannot read $g_mcuPath/$headerFilepath/$headerFilename";
	my @includeList = <FILEHANDLE>;
	close FILEHANDLE;
	my $Backup = $/;
	undef $/;
	my $fileContent = "";
	foreach my $line (@includeList)
	{
		if ($line =~ /\#include \"(\S+)\"/)
		{
			if (-e "$g_mcuPath/$headerFilepath/$1")
			{
				open INPUTHANDLE, "<$g_mcuPath/$headerFilepath/$1";
				my $content = <INPUTHANDLE>;
				close INPUTHANDLE;
				$content =~ s/\#ifndef\s+(__DRV_FEATURES_\w+_H__)\n\#define\s+(__DRV_FEATURES_\w+_H__)/#ifndef $1/i;
				$fileContent .= "$content\n";
			}
			else
			{
				warn "Miss $g_mcuPath/$headerFilepath/$1\n";
			}
		}
	}
	$/ = $Backup;
	if (-e "$g_mcuPath/$switchFilepath/$switchFilename")
	{
		warn "$g_mcuPath/$switchFilepath/$switchFilename shound not exist, overwrite !\n";
	}
	open FILEHANDLE, ">$g_mcuPath/$switchFilepath/$switchFilename" or die "Cannot write $g_mcuPath/$switchFilepath/$switchFilename\n";
	print FILEHANDLE $fileContent;
	close FILEHANDLE;
}

print "\nstart Drv feature check...\n";

# all logs in the same folder
$logFilename = $switchFilename;
$logFilename = $headerFilename if ($switchFilename =~ /^MMI_features_switch\.h$/i);
if ($logPath eq "")
{
    if ($genLogTogether)
    {
        $logPath = "$g_mcuPath/build";
        $logFilename = "$logPath/".splitFilename($logFilename, 0)."$prjName.log";
    }
    # each log in its own project folder
    else
    {
        $logPath = "$g_mcuPath/$buildFolder/bin/log";
        $logFilename = "$logPath/".splitFilename($logFilename, 0).".log";
    }
}
else
{
    $logFilename = "$logPath/".splitFilename($logFilename, 0).".log";
}


# get all feature list
my @featureFileList = ("$g_mcuPath/$headerFilepath/$headerFilename",
                       "$g_mcuPath/$switchFilepath/$switchFilename");
&getFeatureList(\@featureFileList, \%featureList);

@sortedAllFeatures = sort(keys(%featureList));

# add additional features to watch
push @sortedAllFeatures, @addFeaturesToWatch;

# get preprocess result
&getMacroPreprocessResult($headerFilename, \%featureList, \@sortedAllFeatures,
                            \@defFeatures, \@undefFeatures);

$allFeatureCount = @sortedAllFeatures;
$defFeatureCount = @defFeatures;
$undefFeatureCount = @undefFeatures;

# check CFG
$mismatchCount = checkConfig("$g_mcuPath/$switchFilepath/$switchFilename", 
                                \%featureList, \%ignoredCFG, \%mismatchCFG);

# output results
genLog($logFilename, \%mismatchCFG, \@defFeatures, \%featureList,
        \@undefFeatures, \@sortedAllFeatures, $switch, $mmidrvfile);

# verify result
my @tmpList = ();
push @tmpList, splitPathName($_, 0) foreach @featureFileList;
print "\n[".join(', ', @tmpList)."]\n";
print "All feature count = $allFeatureCount\nDefined count = $defFeatureCount\nUndef count = $undefFeatureCount\n";

print "\n[$switchFilename]\n";
print "Mismatch Config count = $mismatchCount\n\n";
print "DRV Feature Check - ";

if ($returnErrorCode && $mismatchCount)
{
    print "Fail\n(Mismatch Config count = $mismatchCount, please check $logFilename)\n";
    exit 1;
}
print "Done\n";
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
sub getMacroPreprocessResult()
{
    my ($targetFilename, $featureList_href, $sortedAllFeatures_aref,
        $defFeatures_aref, $undefFeatures_aref) = @_;

    my $checkMainFilename = "$g_mcuPath/$switchFilepath/~".splitFilename($targetFilename, 0)."_check";    
    
    # generate XXX_check.c
    print "generate feature check file...\n";    
    genCheckDotC("$checkMainFilename.c", $targetFilename, $sortedAllFeatures_aref);
    
    # validate features
    print "validate features...\n";
    processCheckDotC($checkMainFilename, "-E");
    
    # check def/undef features in pre-processed file
    print "check def/undef features for $targetFilename...\n";
    checkFeatures("$checkMainFilename.obj", $featureList_href, $sortedAllFeatures_aref, $defFeatures_aref, $undefFeatures_aref);
    
    if ($g_removeTempFile)
    {
        unlink("$checkMainFilename.c");
        unlink("$checkMainFilename.obj");
    }    
}


#******************************************************************************
# FUNCTION
#  getFeatureList
# DESCRIPTION
#  get features from *.h (has exceptions, e.g. CFG_xxx, etc.)
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub getFeatureList()
{
    my ($fileList_aref, $featureList_href) = @_;

    foreach my $filePathname (@{$fileList_aref})
    {
        open(hFile, "<$filePathname") or die "can't open $filePathname";
        @fileData = <hFile>;
        close(hFile);
        
        my $filename = splitPathName($filePathname, 0);
        print "get feature list from $filename...\n";
        my $fileWrapper = uc $filename;
        $fileWrapper =~ s/\./_/;
        foreach my $line (@fileData)
        {
            my $feature = "";
            
            # also process marked "//" features or not
            if ($alsoProcessDisabledFeatures)
            {
                if ($line =~ /^([\s]*([\/]{2,})?[\s]*)(#define[\s]+)([\w_]+)([\s]*)/)
                {
                    $feature = $4;
                }
            }
            else
            {
                if ($line =~ /^([\s]*)(#define[\s]+)([\w_]+)([\s]*)/)
                {
                    $feature = $3;
                }
            }
            
            # ignore empty one
            if ($feature ne "")
            {
                if (($feature !~ /^((CFG_)|(OP_WARNING))/) &&       # skip CFG_XXX, OP_WARNING_XXX
                    ($feature !~ /^(([_]*$fileWrapper[_]*)|(__MMI_FEATURES__))$/))     # skip file wrapper, e.g. __XXX_H__
                {
                    ${$featureList_href}{$feature} = "";
                }
            }
        }    
    } 
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
    my $filename;
    my $headerFilename;
    my @fileData;
    my $pUserData;  # reference to data array
    
    ($filename, $headerFilename, $pUserData) = @_;
        
    open(hFile, ">$filename") or die "can't open $filename";
       
    foreach my $line (@addLines)
    {
        print hFile $line;
    }
       
    # write header part
    
    foreach my $inc (@addIncFiles)
    {
        print hFile "#include \"$inc\"\n";
    }
    
    print hFile "#include \"$headerFilename\"\n\n" if ($headerFilename ne "");
    
    # write start tag    
    print hFile "static void * feature_check[] = {\n"; 
    
    foreach my $data (@$pUserData)
    {
        print hFile "(void *)$data,\n";
    }
    
    # write end tag
    print hFile "(void *)\"END FEATURE LIST\"};\n";
    
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
    my ($checkMainFilename, $compileOptions) = @_;
        
    my $infoFilename = "$g_mcuPath/$buildFolder/bin/log/info.log";
    print "infoFilename = $infoFilename\n";
    my $defTmpFilename = "$checkMainFilename.def";
    my $incTmpFilename = "$checkMainFilename.inc";
    my @fileData;
    my $inSection = 0;
    my $incPaths = "";
    my $commonOptions = "";
    
    my $count = 0;
              
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
    
        if ($line =~ /(^[^\[][^\s][^\n]*)/)
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
                    $inc = "$g_mcuPath/$inc";
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
#    foreach my $mod (@includeMod)
#    {
#        my @incFiles = ();
#        if (&getFileList("$g_mcuPath/$buildFolder/bin/module/$mod/*.inc /s", \@incFiles) > 0)
#        {
#            foreach my $incFilename (@incFiles)
#            {
#                open(hFile, "<$incFilename") or die "can't open $incFilename";
#                @fileData = <hFile>;
#                close(hFile);
#                
#                foreach my $line (@fileData)
#                {
#                    if ($line =~ /(^[^\s]+)([\s]*$)/)
#                    {
#                        $incPaths = "$incPaths\n-I$g_mcuPath/$1";
#                    }
#                }     
#            }       
#        }
#    }
    
    # additional inc path
    foreach my $inc (@addIncPath)
    {
        $incPaths = "$incPaths\n-I$g_mcuPath/$inc";
    }    
    
    # read macro from *.def
#    foreach my $mod (@includeMod)
#    {
#        my @defFiles = ();
#        if (&getFileList("$g_mcuPath/$buildFolder/bin/module/$mod/*.def /s", \@defFiles) > 0)
#        {
#            foreach my $defFilename (@defFiles)
#            {
#                open(hFile, "<$defFilename") or die "can't open $defFilename";
#                @fileData = <hFile>;
#                close(hFile);
#                
#                foreach my $line (@fileData)
#                {
#                    if ($line =~ /(^[^\s]+)([\s]*$)/)
#                    {
#                        $commonOptions = "$commonOptions\n-D$1";
#                    }
#                }
#            }            
#        }
#    }    
    
    #print "$commonOptions\n";
    open(hFile, ">$defTmpFilename") or die "can't open $defTmpFilename";
    print hFile "$commonOptions\n";
    close(hFile);
    
    #print "$incPaths\n";
    open(hFile, ">$incTmpFilename") or die "can't open $incTmpFilename";
    if($compiler =~/GCC/i)
    {
    	$incPaths =~ s/\\/\//g;
    }
    print hFile "$incPaths\n";
    close(hFile);    
    
	my $result = 0;
    if($compiler =~/GCC/i)
    {
    	$result = system("\"$compiler\" $checkMainFilename.c -o $checkMainFilename.obj $compileOptions $viaOption$defTmpFilename $viaOption$incTmpFilename");    
    }
    else
    {
    	$result = system("\"$compiler\" $checkMainFilename.c -o $checkMainFilename.obj $compileOptions $viaOption $defTmpFilename $viaOption $incTmpFilename");    
    }
    exit 1 if ($result);
    if ($g_removeTempFile)
    {
        unlink("$defTmpFilename");
        unlink("$incTmpFilename");
    }
    
    # post-process *.obj
    open(hFile, "<$checkMainFilename.obj") or die "can't open $checkMainFilename.obj\n";
    @fileData = <hFile>;
    close(hFile);
    
    # remove multi-CR/LF
    my $tmpStr = join('',@fileData);
    $tmpStr =~ s/\n([\s]+)\n/\n\n/g;
    open(hFile, ">$checkMainFilename.obj") or die "can't open $checkMainFilename.obj\n";
    print hFile $tmpStr;
    close(hFile);
}


#******************************************************************************
# FUNCTION
#  checkConfig
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  none
#******************************************************************************
sub checkConfig()
{
    my $switchFilePathname;
    my $featureHash_ref;
    my $ignoredCFG_ref;
    my $mismatchCFG_ref;
    
    my @fileData;
    my %cfgHash = ();
    my @cfgList = ();
    
    ($switchFilePathname, $featureHash_ref, $ignoredCFG_ref, 
        $mismatchCFG_ref) = @_;
    
    open(hFile, "<$switchFilePathname") or die "can't open $switchFilePathname\n";
    @fileData = <hFile>;
    close(hFile);
    
    # generate cfgHash from featureHash
    while (my ($feature, $value) = each (%{$featureHash_ref}))
    {
        # remove head and tail '_'
        $feature =~ s/(^[_]*)|([_]*$)//g;
        $feature = "CFG_"."$feature";
        
        $value =~ s/[\s]*//g;             # remove empty
        $value =~ s/(^[\(]*)|([\)]*$)//g; # remove headh '(' and tail ')'        
        
        $cfgHash{$feature} = $value;
    }
    
    foreach my $line (@fileData)
    {
        # get CFG_XXX
        if ($line =~ /^[\s]*\#define[\s]*(CFG_[\w_]*)[\s]*([^\n\/]*)/)
        {
            my $cfg = $1;
            my $value = $2;
            my $mismatchValue = "";

            $value =~ s/[\s]*//g;             # remove empty
            $value =~ s/(^[\(]*)|([\)]*$)//g; # remove headh '(' and tail ')' 
            
            # only check on/off type (skip auto and value type)
            if (($value =~ /^(($macro_on)|($macro_off))$/) && !(${$ignoredCFG_ref}{$cfg}))
            {
                if (exists $cfgHash{$cfg})
                {
                    # cfg = OFF, bug feature is defined
                    if ($value eq $macro_off)
                    {
                        $mismatchValue = $macro_on;             
                    }
                    # cfg != feature value
                    elsif ($value ne $cfgHash{$cfg})
                    {
                        $mismatchValue = $cfgHash{$cfg};
                    }
                }
                # cfg = ON, but feature is undef
                elsif ($value eq $macro_on)
                {
                    $mismatchValue = $macro_off;
                }
                
                if ($mismatchValue ne "")
                {
                    ${$mismatchCFG_ref}{$cfg}[0] = $value;  # original config
                    ${$mismatchCFG_ref}{$cfg}[1] = $mismatchValue;
                }
            }
        }
    }
    
    # filter out non-target CFG_xxx
    if ($checkcfg eq 'TRUE')
    {
	    my $switchMainFilename = &splitPathName($switchFilePathname, 0);
	    my %tmpMismatchCFG = %{$mismatchCFG_ref};
	    my @tmpMismatchList = keys(%tmpMismatchCFG);
	    my @tmpDefinedMismatch = ();
	    my @tmpUndefMismatch = ();
	    &getMacroPreprocessResult($switchMainFilename, \%tmpMismatchCFG, \@tmpMismatchList,
	                                \@tmpDefinedMismatch, \@tmpUndefMismatch);    
	    foreach my $cfg (@tmpUndefMismatch)
	    {
	        delete ${$mismatchCFG_ref}{$cfg}; # remove from hash
	    }
    }
    # return mismatch count
    return (scalar(keys(%{$mismatchCFG_ref})));
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
    my $filename;           # preprocessed object filename
    my $pFeatureList;       # reference to hash of feature list,
                            # after this call, only contains defined features
    my $pSortedAllFeatures; # reference to array of sorted all features
    my $pDefFeatures;       # reference to array of defined features
    my $pUndefFeatures;     # reference to array of undefined features

    my @fileData;
    my $isFeature = 0;
    my $featureIndex;
    my $defFeature;
    
    ($filename, $pFeatureList, $pSortedAllFeatures, 
        $pDefFeatures, $pUndefFeatures) = @_;
    
    open(hFile, "<$filename") or die "can't open $filename";
    @fileData = <hFile>;
    close(hFile);
    
    foreach my $line (@fileData)
    {
        if ($isFeature)
        {
            if ($line =~ /(^\(void \*\)[\s]*)([^,]*)([\s]*,$)/)
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
                print "[Not Processed] \"$line\"\n";
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
    my $logFilePathname;
    my $mismatchCFG_href;
    my $defFeatures_aref;
    my $featureData_href;
    my $undefFeatures_aref;
    my $sortedAllFeatures_aref;

    my $col1LenMax = 0;
    my $mismatchCount;
    my $allFeatureCount;
    my $defFeatureCount;
    my $undefFeatureCount;
    my $mismatchPrompt = "";
    my $switch;
    my $mmidrvfile;
        
    ($logFilePathname, $mismatchCFG_href, $defFeatures_aref,
        $featureData_href, $undefFeatures_aref, $sortedAllFeatures_aref, $switch, $mmidrvfile) = @_;
    
    open(hLogFile, ">$logFilePathname") or die "can't open $logFilePathname\n";
    
    open(MMI_DRV_DEFS, ">>$mmidrvfile") or die "1 can't open $mmidrvfile\n";
    if ($switch =~ /MMI/ig) {
    	print MMI_DRV_DEFS "MMI_DEFS = \\\n";
    }
    if ($switch =~ /DRV/ig) {
    	print MMI_DRV_DEFS "DRV_DEFS = \\\n";
		if (-e "$g_mcuPath/$switchFilepath/$switchFilename")
		{
			unlink "$g_mcuPath/$switchFilepath/$switchFilename";
		}
		else
		{
			warn "Fail in $g_mcuPath/$switchFilepath/$switchFilename\n";
		}
    }
    if ($switch =~ /OPTR/ig) {
    	print MMI_DRV_DEFS "OPTR_DEFS = \\\n";
    }
    
    $mismatchCount = keys(%{$mismatchCFG_href});
    $allFeatureCount = @$sortedAllFeatures_aref;
    $defFeatureCount = @$defFeatures_aref;
    $undefFeatureCount = @$undefFeatures_aref;
    
    # result: summary
    print hLogFile "\n$separation\n[Summary]\n$separation\n\n";
    print hLogFile "Mismatch Config count = $mismatchCount\n";
    print hLogFile "Defined Feature count = $defFeatureCount\n";
    print hLogFile "Undefined Feature count = $undefFeatureCount\n";
    print hLogFile "All Feature count = $allFeatureCount\n";    
    print hLogFile "\n";
    
    # result: mismatch Configs
    
    # calculate max. length of config name
    foreach my $feature (keys(%{$mismatchCFG_href}))
    {
        $col1LenMax = length($feature) if (length($feature)>$col1LenMax);
    }
    
    if ($mismatchCount)
    {
        if ($returnErrorCode)
        {
            $mismatchPrompt = " *error*";
        }
        else
        {
            $mismatchPrompt = " *warning*";
        }
    }
    
    print hLogFile "\n$separation\n[Mismatch Configs ($mismatchCount)]$mismatchPrompt\n$separation\n\n";
    print hLogFile sprintf("%-*s%-15s%s\n", $col1LenMax+8, "<CFG name>", "<original>", "<result>") if ($mismatchCount);
    print hLogFile "-----------------------------------------------------------------------\n" if ($mismatchCount);
    foreach my $feature (keys(%{$mismatchCFG_href}))
    {
        print hLogFile sprintf("%-*s%-15s%s\n", $col1LenMax+8, $feature, 
                            ${$mismatchCFG_href}{$feature}[0], ${$mismatchCFG_href}{$feature}[1]);
    }
    print hLogFile "\n";
    
    
    $col1LenMax = 0;
    foreach my $feature (@$sortedAllFeatures_aref)
    {
        $col1LenMax = length($feature) if (length($feature)>$col1LenMax);
    }
    
    # result: Defined Features
    print hLogFile "\n$separation\n[Defined Features ($defFeatureCount/$allFeatureCount)]\n$separation\n\n";
    foreach my $feature (@$defFeatures_aref)
    {
        print hLogFile sprintf("[D] %-*s%s\n", $col1LenMax+8, 
                            $feature, ${$featureData_href}{$feature});
        # Print to MMI_DEFS or DRV_DEFS
        print MMI_DRV_DEFS "$feature \\\n";
    }
    print hLogFile "\n\n";
    print MMI_DRV_DEFS "\n\n";
    close MMI_DRV_DEFS;
    
    # result: Undefined Features
    print hLogFile "$separation\n[Undefined Features ($undefFeatureCount/$allFeatureCount)]\n$separation\n\n";
    foreach my $feature (@$undefFeatures_aref)
    {
        print hLogFile "[U] $feature\n";
    }
    print hLogFile "\n\n";
    
    # result: All Detected Features
    print hLogFile "$separation\n[All Detected Features ($allFeatureCount)]\n$separation\n\n";
    foreach my $feature (@$sortedAllFeatures_aref)
    {
        print hLogFile "$feature\n";
    }
    print hLogFile "\n";
    
    close(hLogFile);
    print "log generated at $logFilePathname\n";
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
    unlink("$tmpFilename");

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

