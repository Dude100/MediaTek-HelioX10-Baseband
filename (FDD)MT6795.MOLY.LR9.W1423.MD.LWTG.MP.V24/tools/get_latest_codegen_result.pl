#!/usr/local/bin/perl
# 
# Copyright Statement:
# --------------------
# This software is protected by Copyright and the information contained
# herein is confidential. The software may not be copied and the information
# contained herein may not be used or disclosed except with the written
# permission of MediaTek Inc. (C) 2005
# 
# BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
# THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
# RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
# AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
# NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
# SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
# SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
# THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
# NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
# SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
# 
# BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
# LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
# AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
# OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
# MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
# 
# THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
# WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
# LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
# RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
# THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).


# process argument
($project, $modem, $flavor) = @ARGV;
die "Please specify the project name.\n" if ($project eq "");
die "please specify the modem type.\n" if ($modem eq "");

# get the conf file
$daily_build_conf_file_path = "\\\\mtkrs12\\Software_Management_Material\\Script\\3rd_party\\Scripts";

#check branch in verno file
$verno_path = "make";
$verno_file = $verno_path."\\Verno_".$project.".bld";

if (!-e $verno_file){
    $verno_file = $verno_path."\\Verno.bld";
}
-e $verno_file or die "Verno file does NOT exist!\nPlease check.\n";

# read the verno file
open FILE, $verno_file;
foreach $line (<FILE>){
    if ($line =~ /BRANCH\s*=\s*(\S*)/){
        $branch = $1;
        break;
    }
}

#get the daily build conf file according to the branch
$daily_build_conf_file_name = "daily_build_".$branch."_conf.ini";
$daily_build_conf_file = $daily_build_conf_file_path."\\".$daily_build_conf_file_name;

-e $daily_build_conf_file or die "Config file: $daily_build_conf_file does NOT exist!\nPlease check.\n";

# read the conf file
open FILE, $daily_build_conf_file;

foreach $line (<FILE>){
    if ($line =~ /^OF_BUILD_PATH\s*=\s*(\S*)/){
        $of_build_path = $1;
    }
    elsif ($line =~ /^CODE_BASE_WEEK\s*=\s*(\S*)/){
        $code_base_week = $1;
        # get the latest version if the week is not specified. 
        if ($code_base_week eq ""){
            $code_base_week = &getLatestCodebaseWeek();
        } 
    }
    elsif ($line =~ /^DEFAULT_PROJECT_GSM\s*=\s*(\S*)/){
        $default_project_gsm = $1;
    }
    elsif ($line =~ /^DEFAULT_PROJECT_GPRS\s*=\s*(\S*)/){
        $default_project_gprs = $1;
    }
    elsif ($line =~ /^DEFAULT_PROJECT_UMTS\s*=\s*(\S*)/){
        $default_project_umts = $1;
    }
    elsif ($line =~ /^DEFAULT_MODEM_GSM\s*=\s*(\S*)/){
        $default_modem_gsm = $1;
    }
    elsif ($line =~ /^DEFAULT_MODEM_GPRS\s*=\s*(\S*)/){
        $default_modem_gprs = $1;
    }
    elsif ($line =~ /^DEFAULT_MODEM_UMTS\s*=\s*(\S*)/){
        $default_modem_umts = $1;
    }
    elsif ($line =~ /^DEFAULT_FLAVOR_GSM\s*=\s*(\S*)/){
        $default_flavor_gsm = $1;
    }
    elsif ($line =~ /^DEFAULT_FLAVOR_GPRS\s*=\s*(\S*)/){
        $default_flavor_gprs = $1;
    }
    elsif ($line =~ /^DEFAULT_FLAVOR_UMTS\s*=\s*(\S*)/){
        $default_flavor_umts = $1;
    }
    elsif ($line =~ /^DEFAULT_STAGE_GSM\s*=\s*(\S*)/){
        $default_stage_gsm = $1;
    }
    elsif ($line =~ /^DEFAULT_STAGE_GPRS\s*=\s*(\S*)/){
        $default_stage_gprs = $1;
    }
    elsif ($line =~ /^DEFAULT_STAGE_UMTS\s*=\s*(\S*)/){
        $default_stage_umts = $1;
    }
}


# find the latest codebase in stage0/stage1/stage2 folders
@stages = qw(Stage0 Stage1 Stage2);

foreach $stage (@stages){
    if ($flavor eq ""){
        $codebase_path = $of_build_path ."\\".$code_base_week."_".$stage."\\".$project."_".$modem.".".$code_base_week."\\mcu";
    }
    else{
        $codebase_path = $of_build_path ."\\".$code_base_week."_".$stage."\\".$project."(".$flavor.")_".$modem.".".$code_base_week."\\mcu";
    }
    #print "try to find the codebase : $codebase_path\n";
    if (-d $codebase_path){
        $codebase_found = 1;
        print "codebase found: $codebase_path\n";
        last;
    }
}

# can not find the same project in latest official build, using the default project.
if (!$codebase_found){
    print "codebase not found, try to find the default project path.\n";
    if ($modem =~ /gsm/i){
        $project = $default_project_gsm;
        $modem = $default_modem_gsm;
        $flavor = $default_flavor_gsm;
        $stage = $default_stage_gsm;
    }
    elsif ($modem =~ /gprs/i){
        $project = $default_project_gprs;
        $modem = $default_modem_gprs;
        $flavor = $default_flavor_gprs;
        $stage = $default_stage_gprs;
    }
    else{ #UMTS , HSPA
        $project = $default_project_umts;
        $modem = $default_modem_umts;
        $flavor = $default_flavor_umts;
        $stage = $default_stage_umts;
    }
    
    if ($flavor eq ""){
        $codebase_path = $of_build_path ."\\".$code_base_week."_".$stage."\\".$project."_".$modem.".".$code_base_week."\\mcu";
    }
    else{
        $codebase_path = $of_build_path ."\\".$code_base_week."_".$stage."\\".$project."(".$flavor.")_".$modem.".".$code_base_week."\\mcu";
    }
    #print "try to find the the default codebase : $codebase_path\n";
    die "Can not find default $modem project path at $codebase_path." if (!-d $codebase_path);   
}


# find codegen pstrace_db folder
$codegen_path = "tst";
@codegen_db_folders = qw(database database_classb database_classb_umts);
$pstrace_db = "pstrace_db";

foreach $folder (@codegen_db_folders){
    if (-d $codebase_path."\\".$codegen_path."\\".$folder."\\".$pstrace_db){
        $pstrace_path = $codebase_path."\\".$codegen_path."\\".$folder."\\".$pstrace_db;
        $db_folder = $folder;        
        print "pstrace folder : $pstrace_path\n";
        last;
    }
}   

die "pstrace folder does NOT exist in $codebase_path\\$codegen_path!\nPlease check.\n" if ($pstrace_path eq "");




# identify local path
chomp($current_path = `cd`);
print "GET LOCAL PATH: $current_path\n";
#$p = Win32::GetCwd();

if ($current_path =~ /(.*)\\mcu(.*)/){
    $local_root_path = $1."\\mcu";
}
#for LSF
elsif($current_path  =~ /E:\\temp\\(MAUI|10A|11A)/){
    $local_root_path = $current_path;
}

#delete the log file generated before
system("del -Q $local_root_path\\copy_latest_codegen.log");

$local_pstrace_path = $local_root_path."\\".$codegen_path."\\".$db_folder."\\".$pstrace_db;

#print "local pstrace path : $local_pstrace_path\n";

# copy pstrace folder if do not have
if (!-d $local_pstrace_path){
    $need_to_copy = 1;
}
else{
    opendir (DIR, $local_root_path."\\".$codegen_path."\\".$db_folder);
    @files = readdir DIR;
    close DIR;
    
    $need_to_copy = 1;
    foreach $file (@files){
        if ($file =~ /BPLGUInfo(.*)/){
            $need_to_copy = 0;
            last;
        }
    }
    
}
if ($need_to_copy){
    print ("Copy the latest codegen result.\n");
    print ("xcopy /E /Y \"$pstrace_path\\\*\" \"$local_pstrace_path\\\*\"\n");
    system("xcopy /E /Y \"$pstrace_path\\\*\" \"$local_pstrace_path\\\*\" >nul");
    
    # write a file to identify do the copy latest codegen
    open FILE, ">$local_root_path\\copy_latest_codegen.log";
    close FILE;
}
else{
    print ("Do codegen successfully. Do nothing.\n");
}



#########################################################################################

sub getLatestCodebaseWeek{
    #TODO: need to filter out files
    opendir (DIR, $of_build_path);
    @folders = reverse sort readdir DIR;
    close DIR;
    foreach $folder (@folders){
        if ($folder =~ /W(\w*)\.(\w*)_(.*)/){
            $code_base_week = "W".$1.".".$2;
            last;
        }
    }
    return $code_base_week;
}