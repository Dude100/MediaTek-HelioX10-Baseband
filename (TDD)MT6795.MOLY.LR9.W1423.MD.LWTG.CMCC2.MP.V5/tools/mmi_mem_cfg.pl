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
#  mmi_mem_cfg.pl
#
# Description: 
# ------------
#  XXX.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#  valid dependency :
#  base = 10 + base(cui)
#  fg = 100 + fg(cui)
#  fg = 100 + base(cui) + fg(cui)
#
# Log: 
# -----
#  2010/07/27   Create.
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
#package XXX;                           # declare package library
use strict;
use Text::Balanced qw(extract_bracketed);

#******************************************************************************
# Global Data
#******************************************************************************
my $g_memCfgFile = "";
my $g_outputPathC = ".\\";
my $g_outputPathH = ".\\";
my $g_opAppDataH = "mmi_rp_app_data.h";
my $g_opAppDataDefH = "mmi_rp_app_data_def.h";
my $g_opAppDataC = "mmi_rp_app_data.c";
my $g_opAppMemCfgH = "mmi_rp_app_mem_config.h";

my @g_appDataHDefaultInc = ("MMI_features.h", "MMIDataType.h", "vfx_sys_config.h");

my %g_reserveWord = ("max" => 1, "min" => 1);

my $g_tagFg     = "fg";
my $g_tagBase   = "base";
my $g_tagHeap   = "heap";
my $g_tagHeapShrink = "heap_shrink";
my $g_tagHeapSource = "heap_source";
my $g_tagExtraBase = "extra_base";
my $g_tagCui    = "cui";
my $g_tagId     = "id";
my $g_tagStr    = "str";
my $g_tagInc    = "inc";
my $g_tagConc   = "concurrent";
my $g_tagConcWOrder   = "concurrent_w_order";

my $g_tagAppFg  = "app_fg";
my $g_tagCuiBase = "cui_base";
my $g_tagCuiFg  = "cui_fg";
my $g_tagTotal  = "total";

# used to distinguish non-ordered concurrent or concurrent w/ order
my %g_concValue = ($g_tagConc => 1, $g_tagConcWOrder => 2);

# vrt memory
my $g_tagAppType = "app_type";
my $g_tagVrtMemFactor = "vrt_mem_factor";
my $g_vrtMemUnitSize = "VRT_MEM_UNIT_SIZE";         # provided by Jimmy later
my $g_vrtMemFactorDefault = "0";

my %g_prefix = ("base"  => "ASM_BASE_SIZE_", 
                "extra_base"  => "ASM_EXTRA_BASE_SIZE_", 
                "fg"    => "ASM_FG_SIZE_",
                "heap"  => "ASM_HEAP_SIZE_",
                "heap_shrink"  => "ASM_HEAP_SHRINK_SIZE_",
                "total" => "ASM_TOTAL_SIZE_",
                "app_fg" => "ASM_APP_FG_SIZE_",
                "cui_base" => "ASM_CUI_BASE_SIZE_",
                "cui_fg" => "ASM_CUI_FG_SIZE_",
                "totalNum"  => "ASM_TOTAL_NUM_",
                "concBase"  => "ASM_CONC_BASE_SIZE_",
                "concFg"    => "ASM_CONC_FG_SIZE_",
                "concTotal"   => "ASM_CONC_TOTAL_SIZE_",
                "resBase"   => "RESOURCE_BASE_",
                "resEnd"    => "RESOURCE_BASE_",
                );
my %g_postfix = ("resEnd"   => "_END");

my $g_mcuPath = ".\\";

my $g_errorFlag = 0;
my $g_errorData = "";

#******************************************************************************
# Export Function
#******************************************************************************

#******************************************************************************
# Internal Data
#******************************************************************************
my %memInfo = ();
my %concInfo = ();
my %undefInfo = ();

#******************************************************************************
# Program Start
#******************************************************************************

die getHelp() if (@ARGV == 0);
{
    my $pathC;
    my $pathH;
    my $mcuPath;
    ($g_memCfgFile, $mcuPath, $pathC, $pathH) = @ARGV;
    $g_mcuPath      = $mcuPath;
    $g_outputPathC  = $pathC if ($pathC ne "");
    $g_outputPathH  = $pathH if ($pathH ne "");
    
    # make sure path ends with "\\"
    $g_mcuPath      = $g_mcuPath."\\" if ($g_mcuPath !~ /\\$/);
    $g_outputPathC  = $g_outputPathC."\\" if ($g_outputPathC !~ /\\$/);
    $g_outputPathH  = $g_outputPathH."\\" if ($g_outputPathH !~ /\\$/);
}

&readCfgFile($g_memCfgFile, \%memInfo, \%concInfo);
&processDependency(\%memInfo, \%concInfo, \%undefInfo);

&genAppMemCfgH(\%memInfo, \%concInfo, "$g_outputPathH$g_opAppMemCfgH");
&genAppDataC(\%memInfo, \%concInfo, "$g_outputPathC$g_opAppDataC");
&genAppDataH(\%memInfo, \%concInfo, \%undefInfo, "$g_outputPathH$g_opAppDataH", "$g_outputPathH$g_opAppDataDefH");

0;
#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  xxx
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************

sub genAppMemCfgH()
{
    my ($memInfo_href, $concInfo_href, $file) = @_;
    
    open(hFile, ">$file") or die "can't open $file\n";
    print hFile getFileHeaderStr(splitPathName($file));
    
    my $hMacro = uc "__".splitPathName($file)."__";
    $hMacro =~ s/\./_/;
    print hFile "#ifndef $hMacro\n".
                "#define $hMacro\n\n\n";
    
    my @sortedID = sort keys(%{$memInfo_href});

    my @tagList = ($g_tagHeap, $g_tagHeapShrink, $g_tagExtraBase, $g_tagBase, $g_tagFg, $g_tagTotal, $g_tagAppFg, $g_tagCuiFg, $g_tagCuiBase);
    foreach my $tag (@tagList)
    {
        print hFile "/* $tag */\n";
        print hFile "typedef union {\n";
        foreach my $id (@sortedID)
        {
            print hFile "    kal_uint8 ".$id."[".$g_prefix{$tag}.$id." + 4];\n" if (defined ${$memInfo_href}{$id}{$tag});
        }
        print hFile "    kal_uint8 dummy;\n";
        print hFile "} app_asm_pool_".$tag."_union;\n\n";
    }

    # << app_asm_pool_sub_union >>
    print hFile "typedef union {\n";

    # for each ap
    foreach my $id (@sortedID)
    {
        my $value;
        next if ($id =~ /^(((SRV|CUI|VCUI)_)|(\s*$))/);
        
        $value = $g_prefix{"total"}.$id;
        print hFile "    kal_uint8 ".$id."[APPLIB_MEM_AP_POOL_SIZE_CONFIG(".$value.")];\n";
    }
    # app concurrent
    foreach my $conc (sort keys (%{$concInfo_href}))
    {
        my $concStr = join('_', split(',', $conc));
        my $concTotal = $g_prefix{"concTotal"}.$concStr;
        print hFile "    kal_uint8 CONC_".$concStr."[APPLIB_MEM_AP_POOL_SIZE_CONFIG(".$concTotal.")];\n";
    }

    print hFile "    kal_uint8 DEFAULT_POOL[APPLIB_MEM_AP_POOL_SIZE_CONFIG(APPLIB_MEM_AP_POOL_DEFAULT_SIZE)];\n".
                "} app_asm_pool_sub_union;\n\n";

    # << app_asm_pool_global_union >>
    print hFile "typedef union {\n";
    my $totalStr = "";
    foreach my $id (@sortedID)
    {
        next if (${$memInfo_href}{$id}{$g_tagHeapSource} ne "global");
        $totalStr .= "+" if $totalStr ne "";
        $totalStr .= "APPLIB_MEM_AP_POOL_SIZE_CONFIG(".$g_prefix{"heap_shrink"}.$id.")";
        print hFile "    kal_uint8 ".$id."[APPLIB_MEM_AP_POOL_SIZE_CONFIG(".$g_prefix{"heap_shrink"}.$id.")];\n";
    }
    print hFile "    kal_uint8 sum_total[".$totalStr."];\n" if($totalStr ne "");
    print hFile "    kal_uint8 dummy;\n".
                "} app_asm_pool_global_union;\n\n";
    
    print hFile "#endif /* $hMacro */\n\n";
    close(hFile);
}

sub genAppDataC()
{
    my ($memInfo_href, $concInfo_href, $file) = @_;
    
    open(hFile, ">$file") or die "can't open $file\n";
    print hFile getFileHeaderStr(splitPathName($file));
    print hFile getAppDataCHead();
    
    # mmi_app_info
    print hFile "const mmi_app_info_struct mmi_app_info[] = {\n";
    foreach my $id (sort keys(%{$memInfo_href}))
    {
        my $resBase     = $g_prefix{"resBase"}."$id";
        my $resEnd      = $g_prefix{"resEnd"}."$id".$g_postfix{"resEnd"};
        my $strId       = ${$memInfo_href}{$id}{$g_tagStr};
        my $baseSize    = $g_prefix{"base"}.$id;
        my $fgSize      = $g_prefix{"fg"}.$id;
        my $heapSize    = $g_prefix{"heap"}.$id;
        my $heapShrinkSize = "0";
        my $vrtMemFactor = ${$memInfo_href}{$id}{$g_tagVrtMemFactor};
        $heapShrinkSize = $g_prefix{"heap_shrink"}.$id if (defined ${$memInfo_href}{$id}{$g_tagHeapShrink});
        $baseSize .= "+".$g_prefix{"heap_shrink"}.$id if (defined ${$memInfo_href}{$id}{$g_tagHeapShrink});
        print hFile "\t{$resBase,\t$resEnd,\t$strId,\t$baseSize,\t$fgSize,\t$heapSize,\t$heapShrinkSize,\t$vrtMemFactor},\n";
    }
    print hFile "0" if (scalar(keys(%{$memInfo_href})) == 0);   # if no APP declared, give empty struct
    print hFile "};\n\n";
        
    print hFile getAppDataCTail();
    close(hFile);
}


sub printAppDataEnum
{
    my ($tagStr, $dataStr, $memInfo_href, $concInfo_href, $undefInfo_href, $hFile, $hashPrinted) = @_;

    #check if already printed
    if (defined $hashPrinted->{$tagStr})
    {
        return;
    }

    # search dataStr for possible tags, and print them recursively
    my @tagFound = $dataStr =~ m{ ASM_(HEAP|HEAP_SHRINK|BASE|FG|TOTAL|EXTRA_BASE|APP_FG|CUI_BASE|CUI_FG)_SIZE_(\w+) }gx;

    for(my $i=0; $i<=$#tagFound; $i+=2) 
    {
        my $loopId = $tagFound[$i+1];
        my $loopType = lc $tagFound[$i];
        
        my $loopValue = &removeMacroSign(${$memInfo_href}{$loopId}{$loopType});
        
        printAppDataEnum($g_prefix{$loopType}.$loopId, $loopValue, $memInfo_href, $concInfo_href, $undefInfo_href, $hFile, $hashPrinted);
    }    

    # after all refered tag are print, print this one, and add into hash
    $hashPrinted->{$tagStr} = 1;

    print hFile "    $tagStr = ($dataStr),\n";
}


sub genAppDataH()
{
    my ($memInfo_href, $concInfo_href, $undefInfo_href, $file, $fileDef) = @_;

    open(hFile, ">$file") or die "can't open $file\n";
    print hFile getFileHeaderStr(splitPathName($file));
    
    my $hMacro = uc "__".splitPathName($file)."__";
    $hMacro =~ s/\./_/;
    print hFile "#ifndef $hMacro\n";
    print hFile "#define $hMacro\n\n";

    # add inc header
    my @incArray = @g_appDataHDefaultInc;
    my %incHash = ();
    $incHash{$_} = 1 foreach (@incArray);
    
    # each inc will be included orderly only once
    foreach my $id (sort keys(%{$memInfo_href}))
    {
        if (${$memInfo_href}{$id}{$g_tagInc} ne "")
        {
            ${$memInfo_href}{$id}{$g_tagInc} =~ s/[\s]+//g; # remove space
            my @incArrayTmp = split(',', ${$memInfo_href}{$id}{$g_tagInc});
            foreach my $inc (@incArrayTmp)
            {
                if (!defined $incHash{$inc})
                {
                    push @incArray, $inc;
                    $incHash{$inc} = 1;
                }
            }            
        }
    }
    print hFile "#include \"".$_."\"\n" foreach @incArray;
    print hFile "\n";
    
    # macro for max(a, b) and min(a, b)
    print hFile "#undef max\n".
                "#undef min\n\n".
                "/* __SKIP_MACRO_EXPANSION__ is used in objcheck.pl to get more readable output */\n".
                "#ifdef __SKIP_MACRO_EXPANSION__\n".
                "// undef macro to skip here\n".
                "#else\n".
                "#define max(_a, _b) (((_a) > (_b)) ? (_a) : (_b))\n".
                "#define max1(_1) (_1)\n".
                "#define max3(_1, _2, _3) max(_1, max(_2, _3))\n".
                "#define max4(_1, _2, _3, _4) max(_1, max3(_2, _3, _4))\n".
                "#define max5(_1, _2, _3, _4, _5) max(_1, max4(_2, _3, _4, _5))\n".
                "#define max6(_1, _2, _3, _4, _5, _6) max(_1, max5(_2, _3, _4, _5, _6))\n".
                "#define max7(_1, _2, _3, _4, _5, _6, _7) max(_1, max6(_2, _3, _4, _5, _6, _7))\n".
                "#define max8(_1, _2, _3, _4, _5, _6, _7, _8) max(_1, max7(_2, _3, _4, _5, _6, _7, _8))\n".
                "#define max9(_1, _2, _3, _4, _5, _6, _7, _8, _9) max(_1, max8(_2, _3, _4, _5, _6, _7, _8, _9))\n".
                "#define min(_a, _b) (((_a) > (_b)) ? (_b) : (_a))\n".
                "#define ASM_FG_EXTRA(_vrt_mem_factor)\t((U32)(((_vrt_mem_factor)*".$g_vrtMemUnitSize.")+0.5))\n".
                "#endif /* __SKIP_MACRO_EXPANSION__ */\n\n";

    print hFile "enum {\n";
    
    my %printedHash = ();
    
    # undefined features
    print hFile "    /* undefined features */\n";
    foreach my $id (sort keys(%{$undefInfo_href}))
    {
        my @tagList = ($g_tagBase, $g_tagFg, "total");
        foreach my $tag (@tagList)
        {
            print hFile "    ".$g_prefix{$tag}."$id = (0),\n";
            $printedHash{$g_prefix{$tag}.$id} = 1;
        }
        print hFile "\n";
    }
    
    # each app
    foreach my $id (sort keys(%{$memInfo_href}))
    {
        print hFile "    /* $id */\n";

        # << heap/extra_base/base/fg/total memory size >>
        my @tagList = ($g_tagHeap, $g_tagHeapShrink, $g_tagExtraBase, $g_tagBase, $g_tagAppFg, $g_tagCuiFg, $g_tagCuiBase, $g_tagTotal, $g_tagFg);
        foreach my $tag (@tagList)
        {
            if (defined ${$memInfo_href}{$id}{$tag})
            {
                my $dataStr = &removeMacroSign(${$memInfo_href}{$id}{$tag});
                printAppDataEnum($g_prefix{$tag}.$id, $dataStr, $memInfo_href, $concInfo_href, $undefInfo_href, \*hFile, \%printedHash);
            }
        }
        print hFile "\n";
    }
        
    # total number of APP declared
    print hFile "    /* total number of APP declared */\n".
                "    ".$g_prefix{"totalNum"}."APP = (".scalar(keys(%{$memInfo_href}))."),\n\n";
        
    # concurrent info
    print hFile "    /* concurrent info */\n";
    foreach my $conc (sort keys (%{$concInfo_href}))        
    {
        my $concNameBase = $g_prefix{"concBase"}.join('_', split(',', $conc));
        my $concNameFg = $g_prefix{"concFg"}.join('_', split(',', $conc));
        my $concNameTotal = $g_prefix{"concTotal"}.join('_', split(',', $conc));
        my $concType = ${$concInfo_href}{$conc};

        $conc = &removeMacroSign($conc);
        if ($concType eq $g_concValue{$g_tagConc})
        {
            # concurrent w/o order
            my $valueBase;
            my $valueFg;
            $valueBase = join(' + ', map {$g_prefix{"base"}."$_"} split(',', $conc));
            my @tmp = map {$g_prefix{"fg"}."$_"} split(',', $conc);
            $valueFg = &xferToPair("max", \@tmp);
                    
            print hFile "    ".$concNameBase." = (".$valueBase."),\n";
            print hFile "    ".$concNameFg." = (".$valueFg."),\n";
            print hFile "    ".$concNameTotal." = (".$valueBase." + ".$valueFg."),\n\n";
        }
        # concurrent w/ order
        else
        {
            my $valueWOrder;
            my @valueArray = ();
            my @concArray = split(',', $conc);
            my $baseStr = $g_prefix{"base"}.$concArray[0];
            push @valueArray, $baseStr." + ".$g_prefix{"fg"}.$concArray[0];
            for (my $i=1; $i<scalar(@concArray); $i++)
            {
                $baseStr .= " + ".$g_prefix{"base"}.$concArray[$i];
                push @valueArray, $baseStr." + ".$g_prefix{"fg"}.$concArray[$i];
            }
            $valueWOrder = &xferToPair("max", \@valueArray);
            print hFile "    ".$concNameTotal." = (".$valueWOrder."),\n\n";
        }
    }
    print hFile "    ASM_SIZE_ENUM_MAX\n";
    print hFile "};\n";
    print hFile "\n";
    print hFile "#include \"".splitPathName($fileDef)."\"\n";
    print hFile "#endif /* $hMacro */\n\n";
    close(hFile);

    open(hFile, ">$fileDef") or die "can't open $fileDef\n";
    print hFile getFileHeaderStr(splitPathName($fileDef));
    
    $hMacro = uc "__".splitPathName($fileDef)."__";
    $hMacro =~ s/\./_/;
    print hFile "#ifndef $hMacro\n";
    print hFile "#define $hMacro\n\n";

    print hFile getAppDataHTail();    

    print hFile "#endif /* $hMacro */\n\n";
    close(hFile);
}


sub xferToPair()
{
    my ($prefix, $in_aref) = @_;
    my $outStr = "";
    
    if ((scalar @{$in_aref}) <= 1)
    {
        $outStr = join('', @{$in_aref});
    }
    else
    {
        my @tmp = @{$in_aref};
        $outStr = ", ".pop(@tmp).")";
        $outStr = $prefix."(".pop(@tmp).$outStr;
        while (scalar @tmp)
        {
            $outStr = $prefix."(".pop(@tmp).", $outStr)";
        }
    }
    #print "[xferToPair] $outStr\n";
    return $outStr;
}

sub removeMacroSign()
{
    my ($str) = @_;

    $str =~ s/\$\((.+?)\)/$1/g;
    
    return $str;
}


sub readCfgFile()
{
    my ($file, $memInfo_href, $concInfo_href) = @_;
    
    open(hFile, "<$file") or die "can't open $file\n";
    foreach my $line (<hFile>)
    {
        my $id = "";
        while ($line =~ /\[([\w]+)\]([^\[]+)/g)
        {
            my $attr = lc $1;
            my $val = &trim($2);
            #print "[attr] $attr\t[val] $val\n";
            
            if ($memInfo_href)
            {
                if ($attr eq $g_tagId)
                {
                    $id = $val;
                }
                elsif (($attr eq $g_tagConc) || ( $attr eq $g_tagConcWOrder))
                {
                    my $conc = $val;
                    my @concArray = ();
                    $conc =~ s/[\s]+//g; # remove space first to prevent from wrong sort result
                    
                    # sort in order to filter same concurrent situation
                    if ($attr eq $g_tagConc)
                    {
                        @concArray = sort split(',', $conc);  
                        $conc = join(',', @concArray);
                    }
                    if ($concInfo_href)
                    {
                        ${$concInfo_href}{$conc} = $g_concValue{$attr};
                    }
                }
                else
                {
                    # id is always 1st
                    ${$memInfo_href}{$id}{$attr} = $val if ($id ne "");
                }
            }
        }
        
        # assign default value
        if ($id ne "")
        {           
            # app type => "pluto"
            if (!defined ${$memInfo_href}{$id}{$g_tagAppType})
            {
                ${$memInfo_href}{$id}{$g_tagAppType} = "pluto";
                ${$memInfo_href}{$id}{$g_tagVrtMemFactor} = "0";
            }
            else
            # vrt mem factor => "$g_vrtMemFactorDefault"
            {
                ${$memInfo_href}{$id}{$g_tagVrtMemFactor} = "$g_vrtMemFactorDefault" if (!defined ${$memInfo_href}{$id}{$g_tagVrtMemFactor});
            }

            # heap source/shrink value check
            if (!defined ${$memInfo_href}{$id}{$g_tagHeapSource})
            {
                ${$memInfo_href}{$id}{$g_tagHeapSource} = "app";
            }
                       
            if (${$memInfo_href}{$id}{$g_tagHeapSource} eq "global")
            {
                if (!defined ${$memInfo_href}{$id}{$g_tagHeapShrink})
                {
                    $g_errorFlag = 1;
                    ${$memInfo_href}{$id}{$g_tagHeapSource} = "app";
                }
            }
            else
            {
                if (defined ${$memInfo_href}{$id}{$g_tagHeapShrink})
                {
                    $g_errorFlag = 1;
                    delete(${$memInfo_href}{$id}{$g_tagHeapShrink});
                }
            }
        }
    }
    close(hFile);
}


sub processDependency()
{
    my ($memInfo_href, $concInfo_href, $undefInfo_href) = @_;

    # get undefInfo for concInfo
    foreach my $conc (sort keys(%{$concInfo_href}))
    {
        my $tmp = $conc;
        $tmp =~ s/\$\(.+\)//g;  # skip all $(...)
        #while ($tmp =~ /(^?|\W)([a-z]\w*)($?|\W)/ig)
        for my $symbol (split(/,/, $tmp))
        {
            #my $symbol = $2;
            if (!defined $g_reserveWord{$symbol})   # skip reserve word
            {
                # add to undefInfo
                ${$undefInfo_href}{$symbol} = 1 if (!defined ${$memInfo_href}{$symbol});
            }
        }
    }
     
    foreach my $id (sort keys(%{$memInfo_href}))
    {
        my $heapStr     = "";
        my $heapShrinkStr = "";
        my $extraStr    = "";
        my $appFgStr    = "";
        my $cuiBaseStr  = "";
        my $cuiTotalStr = "";
        my $cuiFgStr    = "";
        my @datas;

        my $baseStr     = "";
        my $fgStr       = "";
        my $totalStr    = "";

        # collect all necessary information        
        $heapStr    = $g_prefix{$g_tagHeap}.$id         if (defined ${$memInfo_href}{$id}{$g_tagHeap});
        $heapShrinkStr = $g_prefix{$g_tagHeapShrink}.$id if (defined ${$memInfo_href}{$id}{$g_tagHeapShrink});
        $extraStr   = $g_prefix{$g_tagExtraBase}.$id    if (defined ${$memInfo_href}{$id}{$g_tagExtraBase});

        $appFgStr   = ${$memInfo_href}{$id}{$g_tagFg}   if (defined ${$memInfo_href}{$id}{$g_tagFg});
        if (${$memInfo_href}{$id}{$g_tagVrtMemFactor} ne "0")
        {
            $appFgStr .= " + " if ($appFgStr ne "");
            $appFgStr .= "ASM_FG_EXTRA(".${$memInfo_href}{$id}{$g_tagVrtMemFactor}.")";
        }
        
        if (defined ${$memInfo_href}{$id}{$g_tagCui})
        {
            ($cuiBaseStr, $cuiFgStr, $cuiTotalStr) = &getTypeValue($memInfo_href, $undefInfo_href, ${$memInfo_href}{$id}{$g_tagCui}, "all");
            if ($cuiTotalStr eq "")
            {
                $cuiTotalStr = "$g_prefix{$g_tagCuiBase}$id + $g_prefix{$g_tagCuiFg}$id";
            }
            elsif ($cuiFgStr eq "")
            {
                $cuiFgStr = "max($cuiTotalStr, $g_prefix{$g_tagCuiBase}$id)-$g_prefix{$g_tagCuiBase}$id";
            }
        }

        # ready to go
        
        # << base memory size >>
        if (!defined ${$memInfo_href}{$id}{$g_tagBase})
        {
            # << base memory size >> = heap + extra_base + base(cui)
            @datas = ();
            # if source != "global" add to base
            if ($heapStr ne "")
            {
                if (${$memInfo_href}{$id}{$g_tagHeapSource} eq "global")
                {
                    push(@datas, "(".$heapStr."-".$heapShrinkStr.")");
                }
                else
                {
                    push(@datas, $heapStr);
                }
            }
            push(@datas, $extraStr) if ($extraStr ne "");
            push(@datas, $g_prefix{$g_tagCuiBase}.$id) if ($cuiBaseStr ne "");
            $baseStr = join(" + ", @datas);
        }
        else
        {
            # << base memory size >> = base
            $baseStr = ${$memInfo_href}{$id}{$g_tagBase};
        }

        # << fg memory size >> = max(fg-base(cui), fg(cui))
        @datas = ();
        if ($appFgStr ne "" && $cuiFgStr ne "")
        {
            push(@datas, "max(max($g_prefix{$g_tagAppFg}$id, $g_prefix{$g_tagCuiBase}$id) - $g_prefix{$g_tagCuiBase}$id, $g_prefix{$g_tagCuiFg}$id)");
        }
        elsif ($appFgStr ne "")
        {
            push(@datas, $g_prefix{$g_tagAppFg}.$id);
        }
        elsif ($cuiFgStr ne "")
        {
            push(@datas, $g_prefix{$g_tagCuiFg}.$id);
        }
        $fgStr = join(" + ", @datas);

        # << total memory size >>= base + fg
        $totalStr = $g_prefix{$g_tagBase}.$id." + ".$g_prefix{$g_tagFg}.$id;
        
        #print "[$id]\nH   $heapStr\nE   $extraStr\nAF  $appFgStr\nCB  $cuiBaseStr\nCT  $cuiTotalStr\nCF  $cuiFgStr\n";
        #print "B  $baseStr\n";
        #print "F  $fgStr\n";
        #print "T  $totalStr\n";

        $extraStr   = ${$memInfo_href}{$id}{$g_tagExtraBase} if (defined ${$memInfo_href}{$id}{$g_tagExtraBase});
        
        @datas = ($baseStr, $fgStr, $totalStr, $extraStr, $appFgStr, $cuiBaseStr, $cuiFgStr);
        for(my $i=0; $i<=$#datas; $i++)
        {
            my $tempStr = $datas[$i];
            
            # check for correctness of dependency ID
            while ($tempStr =~ /(base|fg|total)\(([\w]+)\)/g)
            {
                my $depId = $2;
                if (!defined ${$memInfo_href}{$depId})
                {
                    # dependency ID not exists
                    ${$undefInfo_href}{$depId} = 1;
                }
            }
            # replace dependency of base mem.
            $tempStr =~ s/base\(([\w]+)\)/$g_prefix{"base"}$1/g;
            $tempStr =~ s/fg\(([\w]+)\)/$g_prefix{"fg"}$1/g;
            $tempStr =~ s/total\(([\w]+)\)/$g_prefix{"total"}$1/g;
            $tempStr = "0" if ($tempStr eq "");
            
            $datas[$i] = $tempStr;
        } 
               
        ${$memInfo_href}{$id}{$g_tagBase}       = $datas[0];
        ${$memInfo_href}{$id}{$g_tagFg}         = $datas[1];
        ${$memInfo_href}{$id}{$g_tagTotal}      = $datas[2];
        
        ${$memInfo_href}{$id}{$g_tagHeap}       = "0" if (!defined ${$memInfo_href}{$id}{$g_tagHeap});
        ${$memInfo_href}{$id}{$g_tagExtraBase}  = $datas[3] if (defined ${$memInfo_href}{$id}{$g_tagExtraBase});
        ${$memInfo_href}{$id}{$g_tagAppFg}      = $datas[4] if ($appFgStr ne "");
        ${$memInfo_href}{$id}{$g_tagCuiBase}    = $datas[5] if ($cuiBaseStr ne "");
        ${$memInfo_href}{$id}{$g_tagCuiFg}      = $datas[6] if ($cuiFgStr ne "");
    }
}

sub splitStr()
{
    my ($string, $d) = @_;
    my @params = ();
    my $prevStr;
    
    while ($string) {
        $prevStr = $string;
        
        if ($string =~ /^([^(]*?)\s*$d/) {
            push @params, $1;
            $string =~ s/^\Q$1\E\s*$d?\s*//;
        } else {
            my ($ext, $pre);
            ($ext, $string, $pre) = extract_bracketed($string,'()','[^()]*');

            #print "ext=$ext, s=$string, pre=$pre\n";
            
            if ($ext eq "") {
                push @params, $string;
                $string = ""
            } else {
                push @params, "$pre$ext";
                $string =~ s/^\s*$d\s*//;
            }
        }
    }

    return @params;    
}

sub getTypeValue_r()
{
    my ($string, $type, $memInfo_href) = @_;
    
    my $f;
    my $delim;
    my $content;
    my $strlen = length($string);
    
    my $retStr = "";

    if ($string =~ /^([A-Z0-9\_]+$)/) {
        if ($type eq "all") {
            if (!defined ${$memInfo_href}{$string}) {
                return ("0", "0", "0");
            }
            return ("$g_prefix{base}$string", "$g_prefix{fg}$string", "$g_prefix{total}$string");
        } else {
            if (!defined ${$memInfo_href}{$string}) {
                return "0";
            }
            return "$g_prefix{$type}$string";
        }
    }

    if ($string =~ /^\s*max\s*\(\s*(.+?)\s*\)\s*$/) {
        $f = "or";
        $delim = ",";
        $content = $1;
    } elsif ($string =~ /^\s*\(\s*(.+?)\s*\)\s*$/) {
        $f = "and";
        $delim = "\\+";
        $content = $1;
    } else {
        $f = "and";
        $delim = "\\+";
        $content = $string;
    }
    
    my @list = &splitStr($content, $delim);
    my $listLen = $#list+1;
    my $maxStr;
    if ($listLen==2) {
        $maxStr = "max";
    } else {
        $maxStr = "max$listLen";
    }
    
    # for debug
    if (0) {
        print "\ng:$string,t=$type\n";
        print "f=$f,d=$delim,c=$content\n";
        my $sss;
        for $sss (@list) {
            print "d: $sss\n";   
        }
        print "\n";
    }

    if ($f eq "or") {

        if ($type eq "base") {
            return "$maxStr(".join(",", map { getTypeValue_r($_, "base", $memInfo_href) } @list).")";
        } elsif ($type eq "fg") {
            my $strTotal = "$maxStr(".join(",", map { getTypeValue_r($_, "total", $memInfo_href) } @list).")";
            my $strBase  = "$maxStr(".join(",", map { getTypeValue_r($_, "base", $memInfo_href) } @list).")";
            return "max(".$strBase.",".$strTotal.")-".$strBase;
        } elsif ($type eq "total") {
            return "$maxStr(".join(",", map { getTypeValue_r($_, "total", $memInfo_href) } @list).")";
        } elsif ($type eq "all") {
            my $strTotal = "$maxStr(".join(",", map { getTypeValue_r($_, "total", $memInfo_href) } @list).")";
            my $strBase  = "$maxStr(".join(",", map { getTypeValue_r($_, "base", $memInfo_href) } @list).")";
            return ($strBase, "", $strTotal);
        }
        
    } elsif ($f eq "and") {
        
        if ($type eq "base") {
            return join("+", map { getTypeValue_r($_, "base", $memInfo_href) } @list);
        } elsif ($type eq "fg") {
            return "$maxStr(".join(",", map { getTypeValue_r($_, "fg", $memInfo_href) } @list).")";
        } elsif ($type eq "total") {
            my $strBase  = join("+", map { getTypeValue_r($_, "base", $memInfo_href) } @list);
            my $strFg    = "$maxStr(".join(",", map { getTypeValue_r($_, "fg", $memInfo_href) } @list).")";
            return $strBase."+".$strFg;
        } elsif ($type eq "all") {
            my $strBase  = join("+", map { getTypeValue_r($_, "base", $memInfo_href) } @list);
            my $strFg    = "$maxStr(".join(",", map { getTypeValue_r($_, "fg", $memInfo_href) } @list).")";
            return ($strBase, $strFg, "");
        }
    }

    return "";   
}

sub getTypeValue()
{
    my ($memInfo_href, $undefInfo_href, $str, $type) = @_;
    my $outStr = $str;
    
    #print "[$type] $str\n";
    $str =~ s/\$\(.+\)//g;  # skip all $(...)
    # get all valid IDs
    while ($str =~ /(^||\W)([a-z]\w*)($||\W)/ig)
    {
        my $id = "$2";
        #print "[ID] $id\n";
        if (!defined $g_reserveWord{$id})
        {
            #print "[ID] $id\n";
            
            # log undefined ID
            if (!defined ${$memInfo_href}{$id})
            {
                #print "[undef ID] $id\n";
                ${$undefInfo_href}{$id} = 1;
            }
        }
    }

    return &getTypeValue_r($outStr, "all", $memInfo_href);
}

sub getAppDataCHead()
{
    my $str = << "__STR__";
#include "MMIDataType.h"
#include "mmi_rp_app_data.h"
#include "mmi_rp_all_defs.h"


__STR__
    return $str;
}

sub getAppDataCTail()
{
    my $str = << "__STR__";
    
/*****************************************************************************
 * FUNCTION
 *  mmi_app_info_array_size
 * DESCRIPTION
 *  Get size of mmi_app_info[] array 
 * PARAMETERS
 *  void
 * RETURNS
 *  Number of elements
 *****************************************************************************/
U32 mmi_app_info_array_size(void)
{
    return sizeof(mmi_app_info)/sizeof(mmi_app_info_struct);
}
__STR__
    return $str;
}

sub getAppDataHTail()
{
    my $str = << "__STR__";
    
    
/* mmi_app_info_struct structure declaration */
typedef struct {
    U16 baseId;
    U16 baseIdMax;
    U16 name;
    U32 base_size;
    U32 fg_size;
    U32 heap_size;
    U32 heap_shrink_size;
    FLOAT vrt_mem_factor;
} mmi_app_info_struct;

/* extern declaration to use the mmi_app_info array */
extern const mmi_app_info_struct mmi_app_info[];

/* extern declaration to use the mmi_app_info_array_size() function to get the number of  elements */
extern U32 mmi_app_info_array_size(void);

__STR__
    return $str;
}

sub getFileHeaderStr()
{
    my ($filename) = @_;
    my $str = << "__STR__";
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

/*******************************************************************************
 * Filename:
 * ---------
 *   $filename
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Resource populate function generated by XML resgen
 *
 * Author:
 * -------
 *   MTK resgenerator XML parser
 *
 *******************************************************************************/    
__STR__
    return $str;
}


sub trim()
{
    my $str;
    ($str) = @_;
    
    $str =~ s/(^\s*)|(\s*$)//g;
    return $str;
}


sub splitPathName()
{
    my $pathname;
    my $path_ref;
    
    ($pathname, $path_ref) = @_;
    
    if ($pathname =~ /(^.*)\\([^\\\/]+$)/)
    {
        #print "path [$1] filename[$2]\n";
        $$path_ref = $1 if ($path_ref != 0);
        return $2;
    }
    else
    {
        die "can't split path/name from $pathname\n";
    }
}

sub getHelp()
{
    my $helpStr = << "__HELP_STR__";

Usage:
        mmi_mem_cfg.pl <memory config file> <mcu path> <src output path> <header output path>
__HELP_STR__

    return $helpStr;
}
