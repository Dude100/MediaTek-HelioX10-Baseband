#!/usr/bin/env perl 
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
# 

require v5.8.6;
use Cwd;
use File::Copy;
use File::Path;
use File::Basename;
use if ($^O eq "MSWin32"), Win32API::Registry => qw(:ALL);

# for mbis start stamp
$build_time_sec = time;
($sec, $min, $hour, $mday, $mon, $year) = localtime($build_time_sec);
$build_time_string = sprintf("%4.4d.%2.2d.%2.2d.%2.2d.%2.2d.%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);


$plat = "";
@arguments = ();
$project = "";
$action = "";
$m_in_lsf = 0;
$local_q = 0;
@mOpts = ();
$fullOpts = "";
$level = "";
$relDir = "";
$ini = "build/make.ini";
$myMF = "build.mak";
$enINI = 1;
($#ARGV < 0) && &Usage;
(($#ARGV < 1) && ($enINI == 0)) && &Usage;
my $concatenate_proj_mak = "";
my $newMoDIS = 0;
my $bypassMoDIS = 0;
my $atMoDIS = 0;
my $newUESim = 0;
my $pureMoDIS = 0;
my $packMoDIS = 0;
my $modisDir = "";
my $target_option = "";
my $chk_cmd = 0;
my $copro_config = "FALSE";
$eutran_mode_support = "";

$dummyvm = 0;
$disable_ib = 1;

#mbis default enable
$mbis = "tools/mbis.pl";
$arg_mbis_en = "FALSE";
$arg_mbis_en_obj_log = "FALSE";
$arg_mbis_en_save_log = "FALSE";
$mbis_arg_exist = 0;
$mbis_en = "FALSE";
$mbis_en_obj_log = "FALSE";
$mbis_en_save_log = "FALSE";
@mbis_arg = ();
if ($^O eq "MSWin32") {
	if ($ENV{'LTE_DOMAIN'} eq "TRUE") {
		$mbis_conf_file = "\\\\mtklwafs01\\moly\\wcpsm\\config\\mbis_conf.ini";
	}
	else {
		$mbis_conf_file = "\\\\glbfs14\\sw_releases\\mbis\\scripts\\MBIS_conf.ini";
	}
}
$mbis_conf_file = "/mtkeda/wcpsm/mbis/config/mbis_conf.ini" if($^O eq "linux");
@orgARGVwithFlavor = ();
$mbis_num_proc = 0;
$mbis_target_build_with_Modis = 0;
@levels = qw(level2_src level2_obj level1 vendor);
@actions = qw(md_rename errc_gen getusr new update remake clean codegen nvram_auto_gen bootloader emiclean emigen sysgen sys_auto_gen sys_mem_gen ckmemlayout drv_feature_check viewlog rel c,r c,u ckcr removecode scan check_scan check check_dep remake_dep update_dep clean_codegen slim_codegen slim_update genlog findpad elfpatch gendsp cksysdrv nvram_auto_gen rmdebugobj cust_menu_tree_check genmoduleinfo gen_modlibtbl ximgen gen_bt_switch_info gendummylis gendummysym echo_dspinfo video_mem_gen umts_gen asngen asngen_l4 asnregen slim_mcddll lte_mcddll eas_gen memquery cga);

@projects = qw(l1s gsm gprs basic umts hspa udvt tdd128 tdd128dpa tdd128hspa);
@orgARGV = @ARGV;
@orgARGVwithFlavor = @orgARGV;
$flavor = "DEFAULT";
$localq_disk = "z:";
$makeFolder = "make/";
$OSversion = $^O;
$branch_info = "";

if ($^O eq "MSWin32")
{
	$makeCmd = "tools/make.exe";
}
else
{
	$makeCmd = "make";
}

if ($ENV{'MTK_INTERNAL'} eq 'TRUE') {
	# MTK_INTERNAL is a internal environment flag
} elsif (($ENV{'USERDOMAIN'} =~ /MTK|PMT|MBJ|MSZ|MTI|WISE|MEDIATEK|MWS|GCN|APJ/i) && ($ENV{'USERDNSDOMAIN'} =~ /MEDIATEK\.INC/i)) {
	warn "Current user is from MTK internal, but the environment MTK_INTERNAL != TRUE\nPlease check ! Build script will continue after 30 sec.\n";
	sleep 30;
	$ENV{'MTK_INTERNAL'} = 'TRUE';
}

if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "mtk_tools/Internal_function.pm")) {
	require mtk_tools::Internal_function;
}

$no_pcibt = "FALSE";
$no_ltelib = "FALSE"; #temp add
$no_ltecgen = "FALSE";
$VarioationProj_name = "";

if(($ENV{'REDIRECT_OUT_DIR'} eq 'TRUE') && (defined $ENV{'OUT_DIR'})){
	print "$ENV{'OUT_DIR'} \n";
	system("mkdir -p $ENV{'OUT_DIR'}/build") if (!-d "$ENV{'OUT_DIR'}/build");
	system("mkdir -p $ENV{'OUT_DIR'}/build_internal") if (!-d "$ENV{'OUT_DIR'}/build_internal");
	system("ln -sf $ENV{'OUT_DIR'}/build build");
	system("ln -sf $ENV{'OUT_DIR'}/build_internal build_internal");
}

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^(p|pl|pla|plat|platf|platfo|platfor|platform)=(\w+)/i) {
    $plat = $2;
  } elsif ($ARGV[0] =~ /^(c|cu|cus|cust|custo|custom)=(\w+)/i) {
    $custom = $2;
  } elsif ($ARGV[0] =~ /-md/i) {
  } elsif ($ARGV[0] =~ /-copro/i) {
    $copro_config = "TRUE";
  } elsif ($ARGV[0] =~ /-modis/i) {
    $newMoDIS = 1;
  } elsif ($ARGV[0] =~ /-forcemodis/i) {
    $bypassMoDIS = -1;
  } elsif ($ARGV[0] =~ /-atmodis/i) {
    $atMoDIS = 1;
  } elsif ($ARGV[0] =~ /-puremodis/i) {
    $pureMoDIS = 1;
  } elsif ($ARGV[0] =~ /-no_puremodis/i) {
    $pureMoDIS = -1;
  } elsif ($ARGV[0] =~ /-packmodis/i) {
    $packMoDIS = 1;
  } elsif ($ARGV[0] =~ /-no_packmodis/i) {
    $packMoDIS = -1;
  } elsif ($ARGV[0] =~ /-uesim/i) {
    $newUESim = 1;
  } elsif ($ARGV[0] =~ /-dummyvm/i) {
    $dummyvm = 1;
  } elsif ($ARGV[0] =~ /-release/i) {
    $modisDir = "Release";
  } elsif ($ARGV[0] =~ /-debug/i) {
    $modisDir = "Debug";
  } elsif ($ARGV[0] =~ /-h/i) {
    &Usage;
  } elsif ($ARGV[0] =~ /^-(o|op|opt)=(.*)$/i) {
    $fullOpts = "CMD_ARGU=$2";
    @mOpts = split(",", $2);
  } elsif ($ARGV[0] =~ /-lsf/i) {
    $m_in_lsf = 1;
  } elsif ($ARGV[0] =~ /-no_lsf/i) {
    $not_enter_lsf = 1;
  } elsif ($ARGV[0] =~ /-localq/i) {
    $local_q = 1;
  } elsif ($ARGV[0] =~ /-localpath/i) {
    $local_p = 1;
  } elsif ($ARGV[0] =~ /-disable_ib/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-no_ib/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-bm/i) {
    $disable_ib = 1;
  } elsif ($ARGV[0] =~ /-klocwork/i) {
    $RUN_KLOCWORK = 1;
  } elsif ($ARGV[0] =~ /-disk=(.*)/i) {
    $localq_disk = $1;
  } elsif ($ARGV[0] =~ /-chkcmd/i) {
    $chk_cmd = 1;
  }elsif ($ARGV[0] =~ /^-mbis=(.*)$/i) {
    # mbis get argument
    @mbis_arg = split(",", $1);
    &mbis_parse_arg;
  } elsif ($ARGV[0] =~ /-no_cgen/i) {
    $target_option = "REMAKE_WITH_CGEN=FALSE";
  }
  #Add for daily build
  elsif ($ARGV[0] =~ /-dbld/i) {
    $daily_build = 1;
  }
  elsif ($ARGV[0] =~ /(-no_pcibt|-no_pc)\b/i) {
    $no_pcibt = "TRUE";
  }
  elsif ($ARGV[0] =~ /-no_ltelib/i) {
    $no_ltelib = "TRUE";
    $no_ltecgen = "TRUE";
  }
  elsif($ARGV[0] =~ /^-test=(.*)$/i){
  	$VarioationProj_name = $1;
	  $VarioationProj_fullPath = "make/variation/${VarioationProj_name}.mak";
	  &cktheMF($VarioationProj_fullPath);
  }
  elsif($ARGV[0] =~ /^-branch=(.*)$/i){
  	$branch_info = $1;
  }
  else {
    foreach $m (@projects) {
      if (lc($ARGV[0]) eq $m) {
        $project = $m;
        $project_makefile = "${custom}_${project}";
        shift(@ARGV);
        last;
      } elsif (lc($ARGV[1]) eq $m) {
        $project = $m;
        $custom = $ARGV[0];
        $project_makefile = "${custom}_${project}";
        shift(@ARGV);
        shift(@ARGV);
        last;
      }
    }

    #if (($project eq "") && ($enINI == 1) && (-e $ini)) {
    #  open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
    #  while (<FILE_HANDLE>) {
    #    if (/^(\S+)\s*=\s*(\S+)/) {
    #      $keyname = $1;
    #      $${keyname} = $2;
    #    }
    #  }
    #  close FILE_HANDLE;
    #  print "custom=$custom; FLAVOR=$flavor; project=$project\n";
    #  $custom = $custom."($flavor)";
    #}
    if ($custom =~ /^(\w+)\((\w+)\)$/i) # match <custom>(<flavor>)=>SUPERMAN29_DEMO(FLAVOR)
    {
        $custom = $1;
        $flavor = $2;
        $project_makefile = "${custom}_${project}($flavor)";
        writeMakeINI();
    }
    if($ARGV[0] =~ /(.+)\.mak/i){
      $project_makefile = $1;
      writeMakeINI();
      shift(@ARGV);
    }   
    if (($project_makefile eq "") && ($enINI == 1) && (-e $ini)) {
      open (FILE_HANDLE, "<$ini") or die "cannot open $ini\n";
      while (<FILE_HANDLE>) {
        if (/^(\S+)\s*=\s*(\S+)/) {
          $keyname = $1;
          $${keyname} = $2;
        }
      }
      print "project_makefile=$project_makefile\n";
      close FILE_HANDLE;
    }

    if($project_makefile =~ /\W/){
      ($project_name,$flavor) = split (/\W/, $project_makefile);
    }
    else
    {
      $project_name = $project_makefile;
    }
    print "project_name = $project_name\n";
    print "flavor = $flavor\n";
    ($project_makefile eq "") && (die "Unrecognized \"$ARGV[0]\" or \"$ARGV[1]\"\nOr try $myCmd -h\n");

    if ($#ARGV != -1) {
      if ($ARGV[0] =~ /^[ucrUCR]$/) {
        ($action = "clean") if ($ARGV[0] =~ /^[cC]$/);
        ($action = "update") if ($ARGV[0] =~ /^[uU]$/);
        ($action = "remake") if ($ARGV[0] =~ /^[rR]$/);
        shift(@ARGV);
        @arguments = @ARGV;
        @ARGV = ();
        last;
      } else {
        if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
        {
          unshift(@actions, "bm_new", "notify","warn_notify", "cq_notify", "err_out", "db_notify",  "db_modis_notify", "bm_remake", "bm_update", "patch", "patch_hal", "find", "rm_cleanroom", "ckmake", "gendoc");
          unshift(@actions, "cmmgen");
          unshift(@actions, "cfggen","ckmemlayout2");
        }
        if ((-d "MoDIS_VC9/MoDIS_lib") || (-d "mtk_rel/${original_project_name}/${original_flavor}/MoDIS_lib"))
        {
          unshift(@actions, "new_modis", "sys_mem_gen_modis", "new_uesim", "sys_mem_gen_uesim");
          unshift(@actions, "gen_modis", "gen_uesim") if (-e "MoDIS_VC9/createMoDIS.pl");
          unshift(@actions, "codegen_modis", "clean_codegen_modis", "umts_gen_modis", "codegen_uesim", "clean_codegen_uesim", "umts_gen_uesim", "distclean_modis", "distclean_uesim");
          unshift(@actions, "remake_modis", "clean_modis", "update_modis", "remake_uesim", "clean_uesim", "update_uesim");
          unshift(@actions, "c,r_modis", "c,u_modis", "c,r_uesim", "c,u_uesim");
          unshift(@actions, "scan_modis");
          if ($^O eq "MSWin32")
          {
            unshift(@actions, "at_modis", "ap_modis", "ap_uesim");
          }
          unshift(@actions, "rel_modis");
        }
        unshift(@actions, "new_viti", "bm_new_viti", "remake_viti") if (-d "hal/viti");
        foreach $act (@actions) {
          if (lc($ARGV[0]) eq $act) {
            $action = $act;
            if (($act eq "bm_update") || ($act eq "bm_remake")) {
              ($action = "update") if ($act eq "bm_update");
              ($action = "remake") if ($act eq "bm_remake");
              ($fullOpts eq "") ? ($fullOpts = "CMD_ARGU=-k") : ($fullOpts .= ",-k");
              push(@mOpts, "-k");
            }
            shift(@ARGV);
            @arguments = @ARGV;
            @ARGV = ();
            last;
          }
        }
      }
    }
    ($action eq "") && (die "Unrecognized \"$ARGV[0]\"\nLack off one of (@actions)\nOr try $myCmd -h\n");
    ($#ARGV != -1) && (die "Unrecognized \"@ARGV\"\nPlease check again or try $myCmd -h\n");
    if ($action eq "rel" || $action eq "ckcr" || $action eq "rel_modis") {
      $relDir = $arguments[0];
      shift(@arguments);
      ($#arguments == -1) && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      foreach $arg (@levels) {
        if (lc($arguments[0]) eq $arg) {
          $level = $arg;
          shift(@arguments);
          last;
        }
      }
      ($level eq "") && die "Lack off release level(@levels).\nOr try $myCmd -h\n";
      ($#arguments != -1) && (warn "Unrecognized \"@arguments\"\n");
    }
    if ($action eq "removecode") {
      $remove_dir = $arguments[0];
    }
    last;
  }
  shift(@ARGV);
}
(!-d "make")&&(die "Folder \"make\" does NOT exist!\nPlease help to check.\n");
if(($ENV{'REDIRECT_OUT_DIR'} eq 'TRUE') && (defined $ENV{'OUT_DIR'})){
	$hostname = `hostname`;
	system("perl -e \"print \'COMPUTERNAME=$hostname\';\" > \"${project_makefile}_cf.log\"");
}

if ($action =~ /^(bm_new|bm_update|bm_remake)$/i)
{
  $ENV{"PCIBT_NO_STOP"} = "TRUE";
}

if (($action !~ /_(modis|uesim)$/i) && ($action =~ /new|c,r|remake/i) && ($^O eq "MSWin32"))
{
  print "[Error:] Target build on Windows is not avaliable, please use the linux server to build Target!!\n";
  exit 1;
}

if (($action =~ /^(new|rel)_(modis|uesim)$/i) || (($action =~ /^(bm_)?new$/i) && ($newMoDIS || $newUESim)))
{
	if ($pureMoDIS == 0)
	{
		print "Auto turn on -puremodis when make $action\n";
		$pureMoDIS = 1;
	}
}

if ((-e "mtk_tools/Perl") && ($] >= 5.008006)){
	use lib "mtk_tools/Perl";
	use Net::SMTP;
}

if (($local_q == 1) && ($local_p != 1)) {
  chomp(my $cwd = cwd());
  $cwd =~ s/\//\\/g;
  system("subst $localq_disk $cwd");
  chdir("$localq_disk");
  print "cwd = $cwd\n";
}

chomp($cwd = cwd());
if ($cwd =~ /\s+/)
{
  $arrow = $cwd;
  $arrow =~ s/\s/\^/g;
  $arrow =~ s/[^\^]/ /g;
  print "\n$cwd\n";
  print "$arrow\n";
  print "Space is not a legal character for a folder name.\nPlease check it !!\n";
  exit 1;
}

sub cktheMF
{
  $the_makefile = $_[0];
  (!-e $the_makefile) && (die "$the_makefile does NOT exist!\nPlease help to check.\n");
  open (FILE_HANDLE, "<$the_makefile") or die "Cannot open $the_makefile. Please check if the file is READ-ONLY or not exists.\n";
  while (<FILE_HANDLE>){
    if (/^(\w+)\b\s*=\s*(\S+)/) {
      $keyname = lc($1);
      $${keyname} = $2;
    }
  }
  close FILE_HANDLE;
  return 0;
}

# read the feature option from variation load makefile (ex: flavor)
if ($VarioationProj_name ne "") {
	&cktheMF($VarioationProj_fullPath);
}

# set the project folder path
my $projectFolder = "build/${project_name}/$flavor";
my $copro_folder = "md_copro";
if($copro_config eq "TRUE") {
	$projectFolder = $projectFolder . "/$copro_folder";
	$target_option .= " NEED_BUILD_MD_OFFLOAD_COPRO=$copro_config";
	$no_ltelib = "TRUE";
	$no_ltecgen = "TRUE";
}
#add build action for md copy to alps
if ($action =~ /^md_rename$/i){
  if($branch_info eq "") {
    print "[Error:] Please use the -branch=xxx to assign the branch info!!!\n";
    exit 1;
  }
  elsif($^O eq "MSWin32")
  {
    print "[Error:] md_rename action only support on the Linux!!!\n";
    exit 1;
  }
  else{
    $dest_folder = "$projectFolder/md_rename/$branch_info";
    rmtree($dest_folder) or die "Cannot delete folder $dest_folder\n" if (-d $dest_folder);
    mkpath($dest_folder) or die "Cannot create folder $dest_folder\n" if (!-d $dest_folder);
    $result = system("perl mtk_tools/cp_md_to_alps.pl $projectFolder $branch_info  > $projectFolder/md_rename/$branch_info/md_rename.log 2>&1");
    if ($result){
      print "[Error:] md_rename fail, please check $projectFolder/md_rename/$branch_info/md_rename.log!!!\n";
      exit $result >> 8;
    }
    else
    {
      print "\n\n[NOTICE]\n";
      print "The modem files were renamed and copied to folder [\"$dest_folder/temp_modem\"].\n";
      print "You can start using them in your Smartphone developement.\n\n";
      exit 0;
    }
  }
}

if ($chk_cmd == 1) 
{
print "\n$projectFolder\n";
exit 0;
}
$original_projectFolder = $projectFolder;
writeMakeINI();
$tmpFolder = "$projectFolder/tmp";
if ($action =~ /_(modis|uesim)$/i)
{
	if ((-d "$projectFolder/MoDIS") && ($action =~ /new/i) && ($m_in_lsf != 1)) 
	{
			rmtree("$projectFolder/MoDIS");
	}
	if ((-d "$projectFolder/UESim") && ($action =~ /new/i) && ($m_in_lsf != 1)) 
	{
			rmtree("$projectFolder/UESim");
	}
	($projectFolder, $tmpFolder) = &MoDIS_xgen_check($action);
}
$targetFolder = "$projectFolder/bin";
$logFolder = "$targetFolder/log";

# delete temp. files in make folder before executing build command
$plat = "NONE";
$enFile = "${makeFolder}${project_name}_en.def";
$disFile = "${makeFolder}${project_name}_dis.def";
$theVerno = "${makeFolder}Verno.bld";
$toolsFolder = "tools/";
$MTKtoolsFolder = "mtk_tools/";
$ori_prj_make_full_path = "${makeFolder}${project_makefile}.mak";
$theMF = $ori_prj_make_full_path;
&cktheMF($theMF);
if(defined $project_makefile_ext && $project_makefile_ext ne "NONE"){
	$theMF_ext = "make/custom_config/${project_makefile_ext}.mak";
	&cktheMF($theMF_ext);
}
if(defined $modem_spec && $modem_spec ne "NONE"){
	$theMF_modem = "make/modem_spec/${modem_spec}.mak";
	&cktheMF($theMF_modem);
}

# read the MD copro setting from variation makefile
if($copro_config eq "TRUE") {
	$VarioationProj_name = $md_offload_copro;
	$VarioationProj_fullPath = "make/variation/${VarioationProj_name}.mak";
	print "[MD COPRO PROJECT] = $md_offload_copro\n";
}

if ($eutran_mode_support eq "NONE"){
 $no_ltelib = "TRUE";
 $no_ltecgen = "TRUE";
}

if ((-e "label.ini") && (!-d "modem/lte_sec") && ($no_ltelib eq "FALSE") && ($no_ltecgen eq "FALSE") && ($flavor!~ /BASIC/i) &&
    (($action =~ /getusr/i) || ($action =~ /new/i) || ($action =~ /update/i) || ($action =~ /remake/i) || ($action =~ /codegen/i) || ($action =~ /c,u/i) || ($action =~/c,r/i))) {
  if (-e "mtk_tools/USR/LTEUSR_Initial.pl") {
  $result = system("perl mtk_tools/USR/LTEUSR_Initial.pl $project_name $flavor");
  exit 1 if ($result);
  }
  else
  {	
    die "[Error:] mtk_tools/USR/LTEUSR_Initial.pl is not exist!!\n";
  }
  die "[Error:] mtk_rel/$project_name/$flavor/MoDIS_lib is not exist, $project_name($flavor) can't build modis!!\n" if (($action =~ /_(modis)$/i) && (!-d "mtk_rel/$project_name/$flavor/MoDIS_lib"));
  die "[Error:] mtk_rel/$project_name/$flavor/UESim_lib is not exist, $project_name($flavor) can't build uesim!!\n" if (($action =~ /_(uesim)$/i) && (!-d "mtk_rel/$project_name/$flavor/UESim_lib"));
  die "[Error:] mtk_rel/$project_name/$flavor/lib is not exist, $project_name($flavor) can't build target!!\n" if (($action !~ /_(uesim|modis)$/i) && (!-d "mtk_rel/$project_name/$flavor/lib"));
  
  
}

if ((-e "label.ini") && (!-e "make/rel/hq/USR.txt")&&
    (($action =~ /getusr/i) || ($action =~ /new/i) || ($action =~ /update/i) || ($action =~ /remake/i) || ($action =~ /codegen/i) || ($action =~ /c,u/i) || ($action =~/c,r/i))){
#	$no_ltelib = "TRUE";
  if (-e "mtk_tools/USR/CBrUSR_Initial.pl") {
  $result = system("perl mtk_tools/USR/CBrUSR_Initial.pl $project_name $flavor $original_flavor");
  exit 1 if ($result);
  }
  else
  {
  	die "[Error:] mtk_tools/USR/CBrUSR_Initial.pl is not exist!!\n";
  }
  die "[Error:] mtk_rel/$project_name/$flavor/MoDIS_lib is not exist, $project_name($flavor) can't build modis!!\n" if (($action =~ /_(modis)$/i) && (!-d "mtk_rel/$project_name/$flavor/MoDIS_lib"));
  die "[Error:] mtk_rel/$project_name/$flavor/UESim_lib is not exist, $project_name($flavor) can't build uesim!!\n" if (($action =~ /_(uesim)$/i) && (!-d "mtk_rel/$project_name/$flavor/UESim_lib"));
  die "[Error:] mtk_rel/$project_name/$flavor/lib is not exist, $project_name($flavor) can't build target!!\n" if (($action !~ /_(uesim|modis)$/i) && (!-d "mtk_rel/$project_name/$flavor/lib"));
}


print "clean $tmpFolder/*.*\n";
my @delTempFile = glob("$tmpFolder/*.*");
unlink(@delTempFile) or die "[make.pl][Error:] Remove failed @delTempFile $!" if(@delTempFile);
mkpath($tmpFolder) or die "[make.pl][Error:] Can Not create $tmpFolder! $!" if(!-d "$tmpFolder");
mkpath($logFolder) or die "[make.pl][Error:] Can Not create $logFolder! $!" if(!-d "$logFolder");
mkpath($targetFolder) or die "[make.pl][Error:] Can Not create $targetFolder! $!" if(!-d "$targetFolder");

# generate custom.bld
&genCustombld();

# concatenate the project makefiles and the result is placed on build/$project/$flavorn/bin.
# In here, the gen_concatenate_proj target does NOT do PCIBT.
$concatenate_proj_mak = "${targetFolder}/~${project_makefile}.mak";
my $gen_concate_option = "";
$gen_concate_option = $target_option;
if ($action =~ /_(modis|uesim)$/i) {
	$gen_concate_option .= " MODIS_CONFIG=TRUE";
}
$gen_concate_option .= " NO_PCIBT=TRUE";
if ($action =~ /new/i and -e "$concatenate_proj_mak") {
	unlink($concatenate_proj_mak) or die "[make.pl][Error:] Remove failed $concatenate_proj_mak $!";
}

my $return_code = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor \"VARIATION_PROJ=$VarioationProj_name\" $gen_concate_option gen_concatenate_proj");
die "Error: concatenate project makefiles failed." if(($return_code >> 8) ne 0);
(!-e $concatenate_proj_mak) && (die "$concatenate_proj_mak does NOT exist!\nPlease help to check.\n");
print "concatenate_proj_mak = $concatenate_proj_mak\n";
$theMF = $concatenate_proj_mak;
&cktheMF($theMF);
exit 0 if($action eq "getusr");

# for initial mbis config 
&mbis_init;
&mbis_start_probe;
# mbis options
system("echo MBIS_EN=$mbis_en >> $tmpFolder/~buildinfo.tmp");
system("echo MBIS_EN_OBJ_LOG=$mbis_en_obj_log >> $tmpFolder/~buildinfo.tmp");
system("echo NO_LTELIB=$no_ltelib >> $tmpFolder/~buildinfo.tmp");
system("echo NO_LTECGEN=$no_ltecgen >> $tmpFolder/~buildinfo.tmp");
system("echo NO_PCIBT=$no_pcibt >> $tmpFolder/~buildinfo.tmp");
system("echo VARIATION_PROJ=$VarioationProj_name >> $tmpFolder/~buildinfo.tmp");
system("echo NEED_BUILD_MD_OFFLOAD_COPRO=$copro_config >> $tmpFolder/~buildinfo.tmp");

if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
  if ($m_in_lsf != 1) {
    # Before executing actions, dump environment information to the build.log
    if(-e "./SubReleaseConfig.ini")
    {
      print "copy ./SubReleaseConfig.ini $targetFolder";
      #copy("./SubReleaseConfig.ini $targetFolder");
    }
    system("echo USERNAME=$ENV{'USERNAME'} > $targetFolder/build.log");
    system("perl -e \"print \'START TIME=\';\" >> $targetFolder/build.log");
    system("perl tools/time.pl -n >> $targetFolder/build.log");
  }
}


# Get network path
open (FILE_HANDLE, ">$tmpFolder/~net_path.tmp") or die "Cannot open $tmpFolder/~net_path.tmp";
if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
{
	$net_path = &get_net_path;
	print FILE_HANDLE "NET_PATH = $net_path\n";
}
close FILE_HANDLE;

if(-e $theVerno)
{
  open (FILE_HANDLE, "<$theVerno") or die "cannot open $theVerno\n";
  while (<FILE_HANDLE>) {
    if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)) {
      $keyname = lc($1);
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;
}

die "Please define VERNO in project makefile or $theVerno." if($verno eq "");
if ($verno =~ /\s+/) {
  $arrow = $verno;
  $arrow =~ s/\s/\^/g;
  $arrow =~ s/[^\^]/ /g;
  print "\n$verno\n";
  print "$arrow\n";
  print "Space is not a legal character for VERNO name.\nPlease check it !!\n\n";
  exit 1;
}

# let lsf to get the version of this job 
$ENV{VERNO} = "$verno";

# Get custom_release value
  open (FILE_HANDLE, "<make/Custom.bld") or die "Cannot open make/Custom.bld\n";
  while (<FILE_HANDLE>) {
    if (/^(\S+)\s*=\s*(\S+)/) {
      $keyname = lc($1);
      if(defined($${keyname}) && $${keyname} ne ""){
        next;
      }
      #defined($${keyname}) && warn "$1 redefined in $thefile!\n";
      $${keyname} = uc($2);
    }
  }
  close FILE_HANDLE;

# To check if FLAVOR length is less than 36 bytes
die "ERROR: FLAVOR name should be less than 36 characters.\n" if(length($flavor)>36);
die "ERROR: ORIGINAL_PROJECT_NAME name should be less than 128 characters.\n" if(length($original_project_name)>128);
die "ERROR: ORIGINAL_FLAVOR name should be less than 36 characters.\n" if(length($original_flavor)>36);
die "ERROR: ORIGINAL_VERNO name should be less than 64 characters.\n" if(defined $original_verno && length($original_verno)>64);

if ($^O ne "MSWin32")
{
  @tools_Dirs = qw(tools/);
}
else
{
  @tools_Dirs = qw(tools/ tools/MinGW tools/MSYS);
}


push (@tools_file,$makeCmd);
if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
{
  $VerCmd = "make/verifyCus.mak";
  push (@tools_file,$VerCmd);
}

foreach $tools_Dirs (@tools_Dirs)
{
  if (!-d $tools_Dirs)
  {
    warn "$tools_Dirs folder does NOT exist!\n";
    &cp_3rdpartyTool;
  }
}

foreach $tools_file (@tools_file)
{
  if (!-e $tools_file)
  {
    warn "$tools_file does NOT exist!\n";
    &cp_3rdpartyTool;
  }
}

my $strBypassMoDIS = 0;
my $notify_list;
if ($^O eq "MSWin32") {
	if ($ENV{'LTE_DOMAIN'} eq "TRUE") {
		$notify_list = "\\\\mtklwafs01\\moly\\wcpsm\\config\\bm_conf.ini";
	}
	else {
		$notify_list = "\\\\glbfs14\\sw_releases\\3rd_party\\Scripts\\BM_conf.ini";
	}
}
$notify_list = "/mtkeda/wcpsm/bm/config/bm_conf.ini" if($^O eq "linux");
if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "$notify_list")) {
  %BM_conf = iniToHash($notify_list);
  $BM_LIST=$BM_conf{'romizing_server'}->{'BM_LIST'};
  $BuildInfoServer=$BM_conf{'BUILD_INFORMATION'}->{'SERVER'};
  $LICENSE_FILE = $BM_conf{'NODELOCKED_LICENSE'}->{'LICENSE_FILE'};
  if ($bypassMoDIS > -1)
  {
    $strBypassMoDIS = $BM_conf{'MODIS_RULE'}->{'MODIS_BYPASS'};
  }
}


  if ($ENV{"NUMBER_OF_PROCESSORS"} > 1) {
      $PROCESS_NUM = $ENV{"NUMBER_OF_PROCESSORS"};
      $license_num = -1;
      # Check if license number is enough.
      if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && ($compiler ne "GCC")) {
        if (!-e "$LICENSE_FILE") {
          $license_num += 1;
          system ("lmutil lmstat -f compiler>$logFolder/license.log 2>$logFolder/license.log");
          open (FILE_HANDLE, "$logFolder/license.log");
          while (<FILE_HANDLE>) {
            if ($_ =~ /.+ (\d+) licenses .+ (\d+) .+/) {
              $license_num = $license_num + $1 - $2;
            }
          }
          close(FILE_HANDLE);
        }
        if (($license_num > 0) && ($license_num < $PROCESS_NUM)) {
          $PROCESS_NUM = ($license_num%2) ? int($license_num/2)+1 : int($license_num/2);
        }
      }

      if ($fullOpts eq "") {
        $fullOpts = "CMD_ARGU=-j$PROCESS_NUM";
      } else {
        $fullOpts .= ",-j$PROCESS_NUM";
      }

      if ($mbis_en eq "TRUE")
      {
        $mbis_num_proc = $PROCESS_NUM;
      }
  }


if ($fullOpts ne "") {
# Fix build errors when "parallel jobs processing" fuction enabled by argument "-o|-op|-opt" in command line
  my @temp = @mOpts;
  @mOpts = ();
  foreach (@temp)
  {
    if ($_ =~ /^\s*(-j|--jobs)/)
    {
      $fullOpts .= ",$_";
    }
    else
    {
      push(@mOpts,$_);
    }
  }
# End
  $fullOpts =~ s/"/\\"/g;
# $fullOpts = "\"$fullOpts\"";
  $fullOpts =~ s/,/ /g;
# $makeCmd .= " " . join(" ", @mOpts) . " $fullOpts ";
  $makeCmd .= " " . join(" ", @mOpts);
}


if ($m_in_lsf == 1) {
  die "NOT IN LSF SERVER!\n" if ($ENV{"LS_ADMINNAME"} eq "");
  $computerName = $ENV{"COMPUTERNAME"};
  if ($local_q != 1) {
    system("echo set LAST_SUBMITTED_CF=$computerName >  build/last_cf.log");
    $ENV{"TMP"} = "e:\\temp";
    $ENV{"TEMP"} = "e:\\temp";
    mkdir("e:/temp") if (!-d "e:/temp");
  }
  $ENV{"INLSF"} = $computerName;
}

# Check if the node-locked license still works.
$LICENSE_FILE = $BM_conf{'NODELOCKED_LICENSE'}->{'LICENSE_FILE'};
$ARM_COMPILER = $BM_conf{'NODELOCKED_LICENSE'}->{'ARM_COMPILER'};
$nodelock_fail = 0;

if($compiler ne "GCC"){
	if (-e "$logFolder/license_check.log") {
		unlink("$logFolder/license_check.log") or die "Remove failed $!";
	}
	if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && ($ENV{"USERDOMAIN"} =~ /MTK/i) && (-e "$LICENSE_FILE")) {
		$orig_ARMLMD_LICENSE_FILE = $ENV{"ARMLMD_LICENSE_FILE"};
		$ENV{"ARMLMD_LICENSE_FILE"} = $LICENSE_FILE;
		system("$ARM_COMPILER 2>$logFolder/license_check.log");
		open(license_check_file, "<$logFolder/license_check.log") or die "Cannot open $logFolder/license_check.log";
		$backup = $/; undef $/;
		$log_content = <license_check_file>;
		$/ = $backup;
		if ($log_content =~ /FLEXlm error:/i) {
			$nodelock_fail = 1;
		}
		close(license_check_file);

		if ($nodelock_fail == 1) {
			$email_list = $BM_conf{'NODELOCKED_LICENSE'}->{'MAIL_LIST'};
			$smtp = Net::SMTP->new('smtp.mediatek.inc');
			$smtp->mail(lc(getlogin()));
			map { $smtp->recipient($_); } split(/,/, $email_list);
			$smtp->data();
			$smtp->datasend("Subject:[ERROR: Nodelocked License Failed on $ENV{COMPUTERNAME}].\n");
			$smtp->datasend("$log_content\n\n");
			$smtp->quit;
			system("echo ERROR: Nodelocked License Failed on $ENV{COMPUTERNAME} >> $logFolder/license_check.log");
		} else {
			system("echo License Check Successfully on COMPUTERNAME=$ENV{COMPUTERNAME} > $logFolder/license_check.log");
		}
		$ENV{"ARMLMD_LICENSE_FILE"}=$orig_ARMLMD_LICENSE_FILE;
	}
}

if ($bypassMoDIS > -1)
{
  $bypassMoDIS = int(eval($strBypassMoDIS));
}

if ($ENV{COMPUTERNAME} =~ /mtks(cf|ib)/i) {
  $m_in_lsf = 1;
}

if (($m_in_lsf == 0) && ($not_enter_lsf != 1))
{
  if ($action =~ /^(bm_new|bm_update|bm_remake)$/i)
  {
    system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor drv_feature_check") && exit 1;
  }
  if (($action =~ /new/i) && ($action !~ /new_viti/i) && ($ENV{"SESSIONNAME"} ne "") &&
    ($ENV{"LSF_BINDIR"} ne "") && ($project !~ /BASIC/i) && ($project !~ /L1S/i) && ($project !~ /UDVT/i) && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {

    chomp($cwd = cwd());
    if ($cwd =~ /^[abg-z]/i) {
      &pre_gen() if (($pureMoDIS == 1) || ((lc($action) ne "new_modis") && (lc($action) ne "new_uesim")));
      $env_last_S_CF = "";
      $lastSC = "build/last_cf.log";
      if ((-e $lastSC) && (open(LOGF, "${lastSC}"))) {
        while (<LOGF>) {
          if (/set LAST_SUBMITTED_CF=(\S+)/) {
            $env_last_S_CF = $1;
            last;
          }
        }
        close(LOGF);
      }
#    $ENV{"NUMBER_OF_PROCESSORS"} = 1;
      if ($mbis_en eq "TRUE")
      {
        $mbis_time = time;
        system("echo T_S,DISPATCH_CF,P,$mbis_time >>$ENV{MBIS_BUILD_TIME_TMP}");
      }
      my $result = 0;
      if ($env_last_S_CF eq "") {
         $result = system("bsub -I \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
      } else {
        if (($output = `bhosts ${env_last_S_CF} mtkcf 2>&1`) =~ / Bad host name, host group name or cluster name/)
        {
          $result = system("bsub -I \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
        }
        else
        {
          $result = system("bsub -I -m \"${env_last_S_CF}+2 mtkcf+1\" \"perl $net_path\\m_cp2lsf.pl\" \"$net_path\" @orgARGV");
        }
      }
      &writeINI;
      exit $result >> 8;
    } else {
      # make new in local E: driver
      if (($ENV{"SESSIONNAME"} ne "") && ($ENV{"LSF_BINDIR"} ne "") && ($compiler eq "RVCT") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {
        &localq;
      }
    }
  } else {
    if ($action !~ /ckmake|check|notify|patch|patch_hal|modis|uesim|sysgen|sys_auto_gen|emigen|nvram_auto_gen|find|rel|cmmgen|removecode|ckcr|elfpatch|codegen|gendsp|viewlog|genmoduleinfo|gen_bt_switch_info|viti|memquery/ig) {
      if (($ENV{"SESSIONNAME"} ne "") && ($ENV{"LSF_BINDIR"} ne "") && ($compiler eq "RVCT") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')) {
        $local_path = "";
        $current_path=Win32::GetCwd();
        if($current_path=~/^([A-CG-Z]:)(.*)/i)
        {
          my $tmp_string1=$1;
          my $tmp_string2=$2;
          my @tmp_str2=`net use $tmp_string1`;
          my ($tmp_str3)=($tmp_str2[1]=~/\s+(\\\\.*)\s*$/);
          $net_path = lc("\\\\".$ENV{"COMPUTERNAME"}."\\E\\home");
          $tmp_str3=lc($tmp_str3);
          if ($tmp_str3 eq $net_path) {
            $local_path = "E:\\home\\$tmp_string2";
            chdir("E:\\home\\$tmp_string2");
          }
        }
        if ($local_path ne "") {
          &localq($local_path);
        }else{
          &localq();
        }
      }
    }
  }
}


if ($action eq "c,r") {
	@theAct = qw(clean remake);
} elsif ($action eq "c,u") {
	@theAct = qw(clean update);
} elsif ($action eq "c,r_modis") {
	@theAct = ("clean_modis remake_modis");
} elsif ($action eq "c,u_modis") {
	@theAct = ("clean_modis update_modis");
} else {
	@theAct = ($action);
}
if ($newMoDIS == 1) {
# make sure set $mbis_target_build_with_Modis should be after localq
	$mbis_target_build_with_Modis = 1;
	if ($action =~ /^c,r(_modis|_uesim)?$/) {
		push(@theAct, "clean_modis remake_modis");
	} elsif ($action =~ /^c,u(_modis|_uesim)?$/) {
		push(@theAct, "clean_modis update_modis");
	} else {
		my $action2 = $action;
		$action2 =~ s/_(modis|uesim)$//ig;
		push(@theAct, $action2 . "_modis");
	}
}
if ($newUESim == 1) {
	$mbis_target_build_with_Modis = 1;
	if ($action =~ /^c,r(_modis|_uesim)?$/) {
		push(@theAct, "clean_uesim remake_uesim");
	} elsif ($action =~ /^c,u(_modis|_uesim)?$/) {
		push(@theAct, "clean_uesim update_uesim");
	} else {
		my $action2 = $action;
		$action2 =~ s/_(modis|uesim)$//ig;
		push(@theAct, $action2 . "_uesim");
	}
}


if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
  # Before executing actions, dump environment information to the build.log
  if(-e "./SubReleaseConfig.ini")
  {
    print "copy ./SubReleaseConfig.ini $targetFolder";
    copy("./SubReleaseConfig.ini", $targetFolder);
  }
  system("perl -e \"print \'BUILD START TIME=\';\" >> $targetFolder/build.log");
  system("perl tools/time.pl -n >> $targetFolder/build.log");
  system("echo NUMBER_OF_PROCESSORS=$ENV{\"NUMBER_OF_PROCESSORS\"} >>$targetFolder/build.log");
  &mbis_info_probe;
}

# check current working folder length
# if it is too long, it will cause build error. The max length is defined 90 characters.
chomp($cwd = cwd());
$len = length($cwd);
$folder_limit = 90;
if($^O eq "MSWin32" && $len > $folder_limit)
{
	if ($cwd =~ /.+\\(.+)/) {
		$folder_name = $1;
	}
	print "Folder: $cwd\n";
	print "Error: The folder length from $folder_name($len characters) exceeds $folder_limit characters. Please reduce folder lengths!\n";
	exit 1;
}

# notify error setting
# mtkeda folder is a tools sharefolder on Linux
my $mtkeda_wcpsm_folder = "/mtkeda/wcpsm";
my $error_notify_path;
$error_notify_path = "${mtkeda_wcpsm_folder}/error_notify/" if($^O eq "linux");
$error_notify_path = "\\\\mtkrs12\\Software_Management_Material\\Script\\Error_Notify\\" if($^O eq "MSWin32");
my $notify_err_pl = "${error_notify_path}notify_err.pl";

my $result = 0;
my %saw;
@theAct = grep (!$saw{$_}++, @theAct);
foreach my $action (@theAct) {
  $ENV{"ACTION"} = $action;
  if ($action =~ /_(modis|uesim)$/i)
  {
    ($projectFolder, $tmpFolder) = &MoDIS_xgen_check($action);
  }
  if ($action ne "ckcr") {
	if (open FILE_HANDLE, ">$tmpFolder/~buildinfo.tmp")
	{
		my $timeStr = &CurrTimeStr;
		my $dbg_timeStr = $timeStr;
		$dbg_timeStr =~ s/ /_/g;
		$dbg_timeStr =~ s/:/_/g;
		$dbg_timeStr =~ s/\//_/g;
		print FILE_HANDLE "PROJECT_NAME=$project_name\n";
		print FILE_HANDLE "FLAVOR=$flavor\n";
		print FILE_HANDLE "APLAT=$plat\n";
		print FILE_HANDLE "$fullOpts\n";
		print FILE_HANDLE "BUILD_DATE_TIME=$timeStr\n";
		# mbis options
		print FILE_HANDLE "MBIS_EN=$mbis_en\n";
		print FILE_HANDLE "MBIS_EN_OBJ_LOG=$mbis_en_obj_log\n";
		print FILE_HANDLE "DBG_BUILD_DATE_TIME=$dbg_timeStr\n";
		print FILE_HANDLE "NO_LTELIB=$no_ltelib\n";
		print FILE_HANDLE "NO_LTECGEN=$no_ltecgen\n";
		print FILE_HANDLE "NO_PCIBT=$no_pcibt\n";
		print FILE_HANDLE "VARIATION_PROJ=$VarioationProj_name\n";
		print FILE_HANDLE "NEED_BUILD_MD_OFFLOAD_COPRO=$copro_config\n";
		close FILE_HANDLE;
	}
	else
	{
		warn "Fail to write $tmpFolder/~buildinfo.tmp: $!\n";
	}
  }

  if ($action =~ /\b(clean)_(modis|uesim)\b/) {
    if ($#arguments != -1) {
      system("echo DO_CLEAN_MODULE=TRUE > $tmpFolder/~cleanmod.tmp");
      system("echo CLEAN_MODS=@arguments >> $tmpFolder/~cleanmod.tmp");
    }
  }
  if ($action eq "clean") {
    if ($#arguments != -1) {
      system("echo DO_CLEAN_MODULE=TRUE > $tmpFolder/~cleanmod.tmp");
      system("echo CLEAN_MODS=@arguments >> $tmpFolder/~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor cleanmod");
    } else {
      system("echo DO_CLEAN_MODULE=FALSE > $tmpFolder/~cleanmod.tmp");
      system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor cleanall");
    }
  } elsif (($action eq "remake") || ($action =~ /\b(remake)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_REMAKE_MODULE=TRUE > $tmpFolder/~remakemod.tmp");
      system("echo REMAKE_MODS=@arguments >> $tmpFolder/~remakemod.tmp");
    }
  } elsif (($action eq "update") || ($action =~ /\b(gen|update)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_UPDATE_MODULE=TRUE > $tmpFolder/~updatemod.tmp");
      system("echo UPDATE_MODS=@arguments >> $tmpFolder/~updatemod.tmp");
    }
  } elsif (($action eq "scan") || ($action =~ /\b(scan)_(modis|uesim)\b/)) {
    if ($#arguments != -1) {
      system("echo DO_SCAN_MODULE=TRUE > $tmpFolder/~scanmod.tmp");
      system("echo SCAN_MODS=@arguments >> $tmpFolder/~scanmod.tmp");
    }
  } elsif (($action eq "new") || ($action eq "bm_new") || ($action eq "codegen") || ($action =~ /_(modis|uesim)\b/)) {
    # empty here to run through BT switch
  } elsif ($action eq "check_scan") {
    if ($#arguments != -1) {
      system("echo DO_SCAN_MODULE=TRUE > $tmpFolder/~scanmod.tmp");
      system("echo SCAN_MODS=@arguments >> $tmpFolder/~scanmod.tmp");
    }
    system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor CHECK_SCAN=TRUE scan");
  } elsif ($action eq "check") {
    system("perl ${toolsFolder}parse_comp_err.pl $projectFolder FALSE $tmpFolder TRUE");
  } elsif ($action eq "notify") {
    system("perl ${notify_err_pl} bm_notify");
  } elsif ($action eq "warn_notify") {
    system("perl ${notify_err_pl} warn_notify");
  } elsif ($action eq "cq_notify") {
    system("perl ${notify_err_pl} cq_notify");  
  } elsif ($action eq "err_out") {
    system("perl ${notify_err_pl} err_out");
  } elsif ($action eq "db_notify") {
    system("perl ${notify_err_pl} db_notify");
  } elsif ($action eq "db_modis_notify") {
    system("perl ${notify_err_pl} db_modis_notify");
  } elsif ($action eq "patch") {
    system("perl ${MTKtoolsFolder}patch_file.pl @arguments");
  } elsif ($action eq "patch_hal") {
    system("perl ${MTKtoolsFolder}patch_tool_HAL.pl $project_name @arguments");
  } elsif ($action eq "find") {
    system("cqperl ${MTKtoolsFolder}find_file.pl $theMF $theVerno @arguments");
  } elsif ($action eq "rm_cleanroom") {
    &rm_cleanroom();
  } elsif ($action eq "check_dep") {
    	&Usage if (!@arguments);
    	&writeINI;
    	system("perl tools/GetDepMod.pl ./ \"$theMF\" $project_name $flavor @arguments") && exit 1;
    	exit 0;
  } elsif ($action =~ /update_dep|remake_dep/i) {
    	&Usage if (!@arguments);
    	print "Scanning dependency modules...\n";
    	my $output;
    	if (($output = `perl tools/GetDepMod.pl ./ \"$theMF\" $project_name $flavor @arguments 2>&1`) =~ /=+DEPENDENCY MODULE\(S\)=+\n(.*)\n/)
    	{
    		@arguments = split(/\s+/,$1);
    		$action = "update" if ($action eq "update_dep");
    		$action = "remake" if ($action eq "remake_dep");
    		print "The following module(s) will be rebuilt!\n";
    		print "===========================================================\n";
    		print "@arguments","\n";
    		print "===========================================================\n";
    		redo; # redo to generate ${makeFolder}~remakemod.tmp
    	}
    	else
    	{
    		print $output;
    		&writeINI;
    		exit 1;
    	}
  } elsif ($action =~ /_viti/i) {
    $result = system("perl ${MTKtoolsFolder}build_viti.pl $project_name $flavor \"$theMF\" $tmpFolder $action @arguments");
    exit 1 if($result != 0);
  } elsif ($action eq "viewlog") {
    die "$logFolder does NOT exist\n" if (!-d $logFolder);
    if ($#arguments != -1) {
      foreach my $argu (@arguments) {
        if (-e "${logFolder}\\${argu}.log") {
          system("start ${logFolder}\\${argu}.log");
        } elsif (-e "${logFolder}\\${argu}_classb.log") {
          system("start ${logFolder}\\${argu}_classb.log");
        } else {
          warn "${logFolder}\\${argu}.log does NOT exist\n";
        }
      }
    } else {
      while ($argu = <$logFolder\\*.log>) {
        system("start ${argu}") if (-e "${argu}");
      }
    }
  } elsif ($action eq "rel") {
    #(!-e $disFile) && (die "$disFile does NOT exist!\nPlease help to check.\n");
    if (!-e $enFile) {
      warn "$enFile does NOT exist!\nCreate an EMPTY $enFile\n";
      sleep 2;
      system "copy /y nul $enFile > nul";
    }
    my $result = system("$makeCmd -f${makeFolder}custom_release.mak -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level ckcr");    
    if($result){
      print "ckcr fail\n";
      exit 1;
    }
    system("echo LEVEL=$level >> $tmpFolder\\~buildinfo.tmp");
    system("echo DUMMYVM=TRUE >> $tmpFolder\\~buildinfo.tmp") if ($dummyvm == 1);
    $result = system("$makeCmd -f${makeFolder}custom_release.mak custom_release -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level");
    &writeINI;
    exit 1 if ($result);
    exit 0;
  } elsif ($action eq "ckcr") {
    my $result = system("$makeCmd -f${makeFolder}custom_release.mak -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level ckcr");    
    if($result){
      print "ckcr fail\n";
      exit 1;
    }
  } elsif ($action eq "removecode") {
    print "${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor REMOVE_DIR=$remove_dir $action";
    system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor REMOVE_DIR=$remove_dir $action");
  } elsif (($action eq "gendoc") && ($#arguments != -1)) {
    system("echo DO_GENDOC_MODULE=TRUE > $tmpFolder\\~gendocmod.tmp");
    system("echo GENDOC_MODS=@arguments >> $tmpFolder\\~gendocmod.tmp");
  } elsif ($action eq "memquery") {
    if ($#arguments != -1) {
      system("echo @arguments > $tmpFolder/~memquery.tmp");
    }
    system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor memquery");
  } else {
    if ($action !~ /^ckmake$/i) {
      $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option ckmake");
      die "Error: ckmake failed!!!\n" if($result != 0);
    }
    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option $action");
    if($result != 0) {
      &error_handle;
    } else{
      &mbis_success if ($mbis_en eq "TRUE");
      if (($custom_release eq "FALSE") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')&& (-e "mtk_tools\\Internal_function.pm")) {
        die "AAPMC parser Error!!!\n" if ($result != 0)
      }
    }
    next;
  }

  if (($action eq "remake") || ($action eq "update") || ($action eq "new") || ($action eq "bm_new") || ($action eq "scan") || ($action eq "codegen") || ($action =~ /^new_(modis|uesim)$/i)) {
    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option ckmake");
    die "Error: ckmake failed!!!\n" if($result != 0);
  }
  if (($action eq "remake") || ($action eq "update") || ($action eq "new") || ($action eq "bm_new") || ($action eq "scan")) {
    if ($action eq "bm_new") {
      system("echo BM_NEW=TRUE >> $tmpFolder/~buildinfo.tmp");
      #Add for daily build
      if ($daily_build){
        system("echo DAILY_BUILD=TRUE >> $tmpFolder/~buildinfo.tmp");
      }
      $result = system("${makeCmd} -f${makeFolder}${myMF} -k -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option new");
    } else {
      $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option $action");
    }
    if ($result == 0) {
      if (($custom_release eq "FALSE") && ($ENV{'MTK_INTERNAL'} eq 'TRUE')&& (-e "mtk_tools\\Internal_function.pm")) {
        $result = &AAPMC::Parse_AAPMCLog($AAPMCLOG,$project_name,$flavor,"$theMF");
        die "AAPMC parser Error!!!\n" if ($result != 0)
      }
      &mbis_success if ($mbis_en eq "TRUE");
    } else {
      &error_handle;
    }
    last if ($mbis_target_build_with_Modis != 1);
  } elsif ($action =~ /_(modis|uesim)\b/) {
    $result = &MoDIS_build_process($action);
  } elsif ($action eq "codegen") {
    $result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor code_generate");
    #mbis end probe
    if ($result == 0) {
      &mbis_success if ($mbis_en eq "TRUE");
    }
  }
  if ($result != 0) {
    system("perl $mbis -i SUCCESSFUL_BUILD,0") if ($mbis_en eq "TRUE");
    print "Failed in $action\n";
    last;
  }
}
# [Linux] temporarily add
unlink("nul") if($^O eq "linux" && -e "nul");
unlink("NUL") if($^O eq "linux" && -e "NUL");
&writeINI;
if (($m_in_lsf != 1) && ($mbis_target_build_with_Modis == 1))
{
  &mbis_end_probe;
}
#die "make.pl\n" if ($result != 0);
exit $result >> 8;

sub MoDIS_build_process
{
	my $modis_action = shift @_;
	my $modis_result = 0;
	if ($bypassMoDIS < 1)
	{
		system("perl $mbis -t T_S,M_TOTAL,M_P") if ($mbis_en eq "TRUE");
		my $modis_option = $target_option . " MODIS_CONFIG=TRUE PARTIAL_SOURCE=FALSE";
		if (($modisDir ne "") && ($modisDir ne "undef")) {
			$modis_option .= " MODIS_MODE=$modisDir";
		} else {
			$modisDir = "undef";
		}
		$modis_action =~ s/\b(bm)_//ig;
		if ($modis_action =~ /_uesim\b/) {
			$modis_action =~ s/_uesim\b/_modis/g;
			$modis_option .= " UE_SIMULATOR=TRUE";
		}
		my $modis_cwd = cwd();
		$modis_cwd =~ s/\//\\/g if ($^O eq "MSWin32");
		my $modis_subst = "";
		if (($^O eq "MSWin32") && ($modis_action !~ /^(gen|clean|scan|ap|at|rel)_(modis|uesim)$/i)) {
			foreach my $disk (k..z) {
				if (system("subst $disk: $modis_cwd >NUL 2>&1") == 0) {
					$modis_subst = $disk;
					last;
				}
			}
			if ($modis_subst ne "") {
				print "MoDIS subst disk for $modis_cwd is $modis_subst:\n";
				chdir("$modis_subst:");
			} else {
				warn "Warning: Execute subst for MoDIS fail !\n";
			}
		}
		if ($modis_action eq "rel_modis")
		{
			if ($pureMoDIS == 1)
			{
				if (!-e $enFile) {
					warn "$enFile does NOT exist!\nCreate an EMPTY $enFile\n";
					open FILE_HANDLE, ">$enFile";
					close FILE_HANDLE;
				}
				#mkpath("$relDir/make") if (! -d "$relDir/make");
				$modis_result = system("$makeCmd -f${makeFolder}custom_release.mak -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor RELEASE_DIR_O=$relDir LEVEL=$level $modis_option MODIS_CONFIG=FALSE base nvramautogen_rel files_list obj_list build_rel done");
			}
			if ($modis_result == 0)
			{
				chdir("MoDIS_VC9");
				if (lc($level) eq "level2_src") {
					$modis_result = system("perl modisReleaseL2src.pl ../$theMF");
				} elsif (lc($level) eq "level2_obj") {
					$modis_result = system("perl modisReleaseL2obj.pl ../$theMF");
				} elsif (lc($level) eq "vendor") {
					$modis_result = system("perl modisReleaseVendor.pl ../$theMF");
				}
				chdir("..");
			}
		}
		elsif ($modis_action ne "at_modis")
		{
			$modis_action = "new $modis_action" if ($pureMoDIS == 1);
			$modis_result = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $modis_option $modis_action");
		}
		chdir($modis_cwd);
		system("subst $modis_subst: /D >NUL") if ($modis_subst ne "");
		if ($modis_result == 0)
		{
			if ($modis_action =~ /\b(new|remake|update)_(modis|uesim)\b/) {
				system("perl $mbis -i SUCCESSFUL_BUILD,1") if ($mbis_en eq "TRUE");
				#rel_atMoDIS
			}
			if (($modis_action eq "at_modis") || ($atMoDIS == 1))
			{
				chdir("$modis_cwd\\MoDIS_VC9");
				$modis_result = system("perl modisAutoTest.pl at_modis $modisDir ..\\$theMF ..\\$theVerno");
				chdir("$modis_cwd");
			}
		}
		system("perl $mbis -t T_E,M_TOTAL,M_P") if ($mbis_en eq "TRUE");
	} else {
		print "Skip $modis_action for MoDIS\n";
		$modis_result = 9 << 8;
	}
	return $modis_result;
}

sub MoDIS_xgen_check
{
	my $modis_action = shift @_;
	my $result_projectFolder = "build/${project_name}/$flavor";
	my $result_tmpFolder = "$result_projectFolder/tmp";
	if ($modis_action =~ /_(modis|uesim)$/i)
	{
		my $flag_packMoDIS = $packMoDIS;
		my $path_packMoDIS;
		$path_packMoDIS = "MoDIS" if ($modis_action =~ /_(modis)$/i);
		$path_packMoDIS = "UESim" if ($modis_action =~ /_(uesim)$/i);
		$path_packMoDIS .= "/_BUILD_XGEN";
		if ($modis_action =~ /^new_(modis|uesim)$/i)
		{
			if (($pureMoDIS != -1) && ($packMoDIS != -1))
			{
				$flag_packMoDIS = 1;
			}
		}
		elsif ($pureMoDIS == 1)
		{
			die "Error: -puremodis cannot be used with make $modis_action\n";
		}
		if ($flag_packMoDIS == 0)
		{
			if (-d "$result_projectFolder/$path_packMoDIS")
			{
				print "Auto turn on -packmodis when $result_projectFolder/$path_packMoDIS is found\n";
				$flag_packMoDIS = 1;
			}
		}
		if ($flag_packMoDIS == 1)
		{
			$result_projectFolder .= "/" . $path_packMoDIS;
			$target_option =~ s/\bPROJDIR=\S+//g;
			$target_option .= " PROJDIR=./$result_projectFolder";
			$result_tmpFolder = "$result_projectFolder/tmp";
			if ($result_projectFolder ne $projectFolder)
			{
				mkpath($result_projectFolder) if (! -d $result_projectFolder);
				foreach my $file (glob "$projectFolder/*")
				{
					next if (-d $file);
					copy($file, $result_projectFolder);
				}
			}
			if ($result_tmpFolder ne $tmpFolder)
			{
				mkpath($result_tmpFolder) if (! -d $result_tmpFolder);
				foreach my $file (glob "$tmpFolder/*")
				{
					next if (-d $file);
					copy($file, $result_tmpFolder);
				}
			}
		}
	}
	return ($result_projectFolder, $result_tmpFolder);
}

#usage:
#      my %hash=iniToHash('/tmp/myini.ini');
#      print $hash{'TITLE'}->{'Name'},"\n";
#
sub iniToHash {
  open(MYINI, $_[0]);
  my %hash;
  my $hashref;

  while(<MYINI>)
  {
    next if ((/^\s*$/) || (/^\s*#/));
    if (/^\s*\[(.+)\]/)
    {
      $hashref = $hash{$1} ||= {};
    }
    elsif (/^\s*(\S+)\s*=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $2;
    }
    elsif (/^\s*(\S+)\s*\+=\s*(.+)\s*$/)
    {
      $hashref->{$1} = $hashref->{$1} . " $2";
    }
  }

  close MYINI;
  return %hash;
}

#******************************************************************************
## FUNCTION
##  Xcopy
## DESCRIPTION   
#   Copy a directory including sub directories excluding that match a certain regex
## ...
## ...
##******************************************************************************
#
sub Xcopy
{
	my ($from_dir, $to_dir) = @_;
	opendir my($dir), $from_dir or die "[Error:] Could not open dir '$from_dir': $!";
	for my $file (readdir $dir)
	{
		next if ($file =~/\.$/ || $file =~/\b\.\.\b/ );
		my $src = "$from_dir/$file";
		my $dest = "$to_dir/$file";

		if(!-d $to_dir)
		{
			mkdir($to_dir) or die "[Error:] Create folder '$to_dir' failed: $!";
		}

		if(-d $src)
		{
			&copy_dir($src, $dest);
		}
		else
		{
			copy($src, $dest) or die "[Error:] copy '$src' to '$dest' failed: $!";
		}
	}
	closedir($dir);
}

sub rm_cleanroom {
  my @script_path = qw(
			\\\\mtkrs12/Software_Management_Material/Script/3rd_party/Scripts/rm_cleanroom/rm_cleanroom.pl
			\\\\mtkrfs01/Public1/3rd_party/Scripts/rm_cleanroom/rm_cleanroom.pl
			\\\\glbfs14/WCP/sw_releases/3rd_party/Scripts/rm_cleanroom/rm_cleanroom.pl
     );
                   
  foreach (@script_path)
  {
    next if (!-e);
    system("perl $_");
    last;
  }
}

sub CurrTimeStr {
  my($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
  return (sprintf "%4.4d/%2.2d/%2.2d %2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min);
}

sub cp_3rdpartyTool
{
	if ($ENV{'MTK_INTERNAL'} eq 'TRUE')
	{
		if (-e "tools/thirdParties.pl")
		{
			print("perl tools/thirdParties.pl -cp \n");
			system("perl tools/thirdParties.pl -cp");
		}
		else
		{
			warn "tools/thirdParties.pl does NOT exist!\n";
			exit 1;
		}
	}
	else
	{
		warn "Lack off thirdParties tools!\n";
		warn "Please refer to document: SOP_Third_Party_Package_Installation!\n";
		exit 1;
	}
}

sub Usage_OLD {

  warn << "__END_OF_USAGE";

Usage:
  ./make.sh ["customer"|"mt62xx"] project action [modules]|file1[ file2[ ...]] | \@files
  ./m       ["customer"|"mt62xx"] project action [modules]|file1[ file2[ ...]] | \@files

Description:
  customer   = MTK                   (Default customer)
             = firefly_demo(flavor)  (FIREFLY_DEMO(FLAVOR) project)
             = [mt6217|mt6219|mt6226|mt6227|mt6228|mt6229] (EVB only)
             = ...

  project    = l1s             (Layer 1 stand-alone)
             = gsm             (GSM only)
             = gprs            (GPRS only)
             = umts            (GPRS+UMTS)
             = hspa            (GPRS+UMTS+HSPA)
             = tdd128          (GPRS+TDD128)
             = tdd128dpa       (GPRS+TDD128+HSDPA)
             = tdd128hspa      (GPRS+TDD128+HSPA)
             = basic           (Basic Framework)

  action     = new             (codegen, clean, update) (default)
             = update or u     (scan, compile, link)
             = slim_update     (scan, compile, link without generating mcddll)
             = remake or r     (compile, link)
             = clean or c      (clean)
             = cci or clean_codegen (clean codegen intermedia files)
             = c,u             (clean then update)
             = c,r             (clean then remake)
             = codegen         (codegen)
             = slim_codegen    (codegen without generating mcddll)
             = mcddll_update   (codegen and generate mcddll)
             = slim_mcddll     (generate mcddll without codegen)
             = viewlog         (open edit to view build log)
             = emigen          (emigen)
             = emiclean        (emiclean)
             = check_dep       (check dependency module(s) after source(s)/header(s) changed)
             = remake_dep      (check_dep, remake)
             = update_dep      (check_dep, update)

  module(s)  = modules' name   (kal, l1, ...)
   => OPTIONAL when action is one of (clean c remake r update u c,r c,u)

  file1      = changed source/header's name (init\\include\\init.h, ...)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and \@files is NOT specified

  \@files     = Specify more changed sources/headers via a file (change list)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and file1 is NOT specified

Example:
  ./make.sh "firefly17_demo(DEFAULT)" gprs new
  ./make.sh "milan_demo(FULL_VERSION)" gprs c,u custom
  ./m "milan_demo(FULL_VERSION)" gprs r drv custom
__END_OF_USAGE

  exit 1;
}

sub Usage {

  warn << "__END_OF_USAGE";

Usage:
  ./make.sh ["project makefile"] action [modules]|file1[ file2[ ...]] | \@files
  ./m       ["project makefile"] action [modules]|file1[ file2[ ...]] | \@files

Description:
  project makefile = firefly_demo.mak          (FIREFLY_DEMO Default customer)
                   = firefly_demo(flavor).mak  (FIREFLY_DEMO(FLAVOR) project)
                   = ...

  action     = new             (codegen, clean, update) (default)
             = update or u     (scan, compile, link)
             = slim_update     (scan, compile, link without generating mcddll)
             = remake or r     (compile, link)
             = clean or c      (clean)
             = cci or clean_codegen (clean codegen intermedia files)
             = c,u             (clean then update)
             = c,r             (clean then remake)
             = codegen         (codegen)
             = slim_codegen    (codegen without generating mcddll)
             = mcddll_update   (codegen and generate mcddll)
             = slim_mcddll     (generate mcddll without codegen)
             = viewlog         (open edit to view build log)
             = emigen          (emigen)
             = emiclean        (emiclean)
             = check_dep       (check dependency module(s) after source(s)/header(s) changed)
             = remake_dep      (check_dep, remake)
             = update_dep      (check_dep, update)

  module(s)  = modules' name   (kal, l1, ...)
   => OPTIONAL when action is one of (clean c remake r update u c,r c,u)

  file1      = changed source/header's name (init\\include\\init.h, ...)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and \@files is NOT specified

  \@files     = Specify more changed sources/headers via a file (change list)
   => VALID ONLY when action is one of (check_dep remake_dep update_dep)
   => MANDATORY when action is one of (check_dep remake_dep update_dep) and file1 is NOT specified

Example:
  ./make.sh "firefly17_demo_gprs(DEFAULT).mak" new
  ./make.sh "milan_demo_gprs(FULL_VERSION).mak" c,u custom
  ./m "milan_demo_gprs(FULL_VERSION).mak" r drv custom
__END_OF_USAGE

  exit 1;
}

sub writeINI {

  &writeMakeINI();
  if (($action ne "ckmake") && ($action ne "drv_feature_check")) {
    system("echo LOCAL_MACHINE=%COMPUTERNAME% >>$targetFolder/build.log");
    system("echo PROJECT_NAME=$project_name>>$targetFolder/build.log");
    system("echo PLATFORM=$plat>>$targetFolder/build.log");
    system("echo FLAVOR=$flavor>>$targetFolder/build.log");
    system("echo VERNO=$verno>>$targetFolder/build.log");
    system("echo ARMLMD_LICENSE_FILE=%ARMLMD_LICENSE_FILE%>>$targetFolder/build.log");
    system("perl tools/init/echo.pl -n COMMAND=make \"@orgARGV\">>$targetFolder/build.log");
    system("perl -e \"print \'BUILD END TIME=\'\">>$targetFolder/build.log");
    system("perl tools/time.pl -n>>$targetFolder/build.log");
    $time_num=time;
    #mbis end probe
    # to aviod be called twice when enable lsf 
    if (($m_in_lsf != 1)&&($mbis_target_build_with_Modis != 1))
    { 
      &mbis_end_probe;
    }
    #if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-d "$BuildInfoServer")) {
      #system("copy /y .\\build\\${custom}\\build.log $BuildInfoServer\\$verno\_$time_num\.log >nul");
    #}
  }
}

sub writeMakeINI{
	if(($ENV{'REDIRECT_OUT_DIR'} ne 'TRUE') || (!defined $ENV{'OUT_DIR'})){
    mkpath("build") if(!-d "build");
  }
  if ($enINI == 1) {
    open (FILE_HANDLE, ">$ini") or die "cannot open $ini\n";
    print FILE_HANDLE "project_makefile = $project_makefile\n";
    print FILE_HANDLE "project_folder = ". $original_projectFolder."\n";
    close FILE_HANDLE;
  }
}

sub pre_gen
{
	print "pre gen\n";
	if(defined($level) && ($level =~ /VENDOR/i)){
		print "Skip pre_gen for vendor release.\n";
		return 0;
	}
	print "Before submitting into CF machines, pre-check the Makefile, sys_auto_gen\n";
	$ENV{"ACTION"} = "sys_auto_gen";
	my @f = glob("$tmpFolder/~*.tmp *.d");
	if(@f){
		unlink(@f) or die "Remove failed $!";
	}
	if (open FILE_HANDLE, ">$tmpFolder/~buildinfo.tmp")
	{
		my $timeStr = &CurrTimeStr;
		my $dbg_timeStr = $timeStr;
		$dbg_timeStr =~ s/ /_/g;
		$dbg_timeStr =~ s/:/_/g;
		$dbg_timeStr =~ s/\//_/g;
		print FILE_HANDLE "PROJECT_NAME=$project_name\n";
		print FILE_HANDLE "FLAVOR=$flavor\n";
		print FILE_HANDLE "APLAT=$plat\n";
		print FILE_HANDLE "BUILD_DATE_TIME=$timeStr\n";
		# mbis options
		print FILE_HANDLE "MBIS_EN=$mbis_en\n";
		print FILE_HANDLE "MBIS_EN_OBJ_LOG=$mbis_en_obj_log\n";
		print FILE_HANDLE "DBG_BUILD_DATE_TIME=$dbg_timeStr\n";
		print FILE_HANDLE "NO_LTELIB=$no_ltelib\n";
		print FILE_HANDLE "NO_LTECGEN=$no_ltecgen\n";
		print FILE_HANDLE "NO_PCIBT=$no_pcibt\n";
		print FILE_HANDLE "VARIATION_PROJ=$VarioationProj_name\n";
		print FILE_HANDLE "NEED_BUILD_MD_OFFLOAD_COPRO=$copro_config\n";
		close FILE_HANDLE;
	}
	else
	{
		warn "Fail to write $tmpFolder/~buildinfo.tmp: $!\n";
	}
	if( ($action eq "new_modis") or ($action eq "new_uesim")) {
		$target_option .= " MODIS_CONFIG=TRUE";
	}
	$preTestResult = system("${makeCmd} -f${makeFolder}${myMF} -r -R PROJECT_NAME=$project_name \"PROJECT_MAKEFILE=$theMF\" FLAVOR=$flavor $target_option sys_auto_gen");
#  (&writeINI && exit 1) if ($preTestResult != 0);
	if ($preTestResult != 0) {
		&writeINI;
		exit 1;
	}
	print "Pass pre-check for Makefile and sys_auto_gen\n";
#  (exit 1) if ($preTestResult != 0);
#  print "Pass mtegen\n";
}

sub localq
{
  my ($islocalpath) = @_;
  my $result = 0;
  print "Check if localq is available .... ";
	unlink("$logFolder/localq.log") if (-e "$logFolder/localq.log");
  #system("bjobs -u all -q localq >localq.log 2>nul");
	system("bhosts $ENV{\"COMPUTERNAME\"} >$logFolder/localq.log 2>nul");
	open(LOCALQ, "$logFolder/localq.log") || die "Can not open $logFolder/localq.log!";
  while (<LOCALQ>) {
  	next if ($_ =~ /HOST_NAME/ig);
  	$_ =~ /(\S+)\s+(\S+)\s+(\S+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)\s+(\d+)/ig;
  	$STATUS = $2;
  	$MAX = $4;
  	$NJOBS = $5;
  }
  close LOCALQ;
  if (($NJOBS < $MAX) && ($STATUS =~ /ok/ig)) {
    print "YES\n";
    print "Enter the local queue.\n";
    if (($action =~ /new/i) && ((($action ne "new_modis") && ($action ne "new_uesim")) || ($pureMoDIS == 1))) {
      &pre_gen();
    }
    if ($islocalpath ne "") {
      if ($RUN_KLOCWORK eq 1) {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq -localpath @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq -localpath @orgARGV");
      } else {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq -localpath @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq -localpath @orgARGV");
      }
    }else{
      if ($RUN_KLOCWORK eq 1) {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I kwinject --detach Cgen.exe,DrvGen.exe -T kwinject.trace perl make.pl -lsf -localq @orgARGV");
      } else {
        print "bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq @orgARGV\n";
        $result = system("bsub -q localq -m $ENV{\"COMPUTERNAME\"} -I perl make.pl -lsf -localq @orgARGV");
      }
    }
    &writeINI;
    exit $result >> 8;
  } else {
    print "NO\n";
  }
}

sub get_net_path
{
  my $path;
  my $current_path = cwd();
  if ($^O eq "MSWin32"){
    $current_path =~ s/\//\\/g;
    if ($current_path=~/^([ABDG-Z]:)(.*)/i) {
    	my $disk = $1;
    	my $folder = $2;
    	$folder =~ s/\\$//;
    	my @disk = `net use $disk`;
    	if ($#disk != -1) {
    		$disk[1]=~/\s+(\\\\.*)\s*$/;
    		$path = $1.$folder;
    	} else {
    		@disk = `subst`;
    		my $subst_folder;
    		foreach my $subdisk (@disk) {
    			$subdisk =~ s/\s*$//;
    			if ($subdisk =~ /($disk.*)\s*\=\>\s*(.*)/i){
    				$subst_folder= $2;
    				$subst_folder =~ s/://;
    			}
    		}
    		if ($subst_folder =~ /^UNC\\(.+)/) {
    			$path = "\\\\".$1;
    		} else {
    			if ($subst_folder ne "") {
    				$path = "\\\\".$ENV{"COMPUTERNAME"}."\\".$subst_folder.$folder;
    			} else {
    				$path = "\\\\".$ENV{"COMPUTERNAME"}."\\".$disk.$folder;
    			}
    		}
    	}
    } elsif ($current_path=~/^([CEF]):(.*)/i) {
  	  my $disk = $1;
  	  my $folder = $2;
  	  if ($ENV{"USERNAME"} =~ /wcxbm/ig) {
  		  $path = "\\\\".$ENV{"COMPUTERNAME"}."\\".$disk."\$\$".$folder;
  	  } else {
  		  $path = "\\\\".$ENV{"COMPUTERNAME"}."\\".$disk.$folder;
  	  }
    }
  }else{
    $path = $current_path;
  }
  $path =~ s/://g;
  print "path=$path\n";
  return $path;
}

sub mbis_start_probe
{
  my $mbis_log_folder;

  if ($mbis_en eq "TRUE")
  {
    if (!defined($ENV{"MBIS_BUILD_TIME_TMP"}) || !defined($ENV{"MBIS_BUILD_TIME_LOG"}) || !defined($ENV{"MBIS_BUILD_INFO_LOG"}))
    {
      $mbis_log_folder = "$logFolder/mbis";
      if (!-d "$mbis_log_folder")
      {
				mkpath($mbis_log_folder) or die "Create Folder $mbis_log_folder Faild $!";
      }
      else
      {
        # delete last log file
        if ($mbis_en_save_log ne "TRUE")
        {
					my @f = glob("$mbis_log_folder/*.log");
					unlink(@f) or die "Remove failed $!" if(@f);
					my @f = glob("$mbis_log_folder/*.tmp");
					unlink(@f) or die "Remove failed $!" if(@f);
        }
      }

      if (!defined($ENV{MBIS_BUILD_TIME_TMP}))
      {
        $ENV{MBIS_BUILD_TIME_TMP} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "time" . ".tmp";
        #set title of mbis time tmp file
        system("echo Time Stamp,Item Name,Type,Time>>$ENV{MBIS_BUILD_TIME_TMP}");
        system("echo T_S,TOTAL,A,$build_time_sec >>$ENV{MBIS_BUILD_TIME_TMP}");
      }

      if (!defined($ENV{MBIS_BUILD_TIME_LOG}))
      {
        $ENV{MBIS_BUILD_TIME_LOG} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "time" . ".log";
        #set title of mbis time tmp file
        system("echo Item Name,Type,Start Time,End Time,Duration Time>>$ENV{MBIS_BUILD_TIME_LOG}");
      }

      if (!defined($ENV{MBIS_BUILD_INFO_LOG}))
      {
        $ENV{MBIS_BUILD_INFO_LOG} = $mbis_log_folder . "/". $build_time_string . "_" . "mbis" . "_" . "info" . ".log";
        #set title of mbis time tmp file
        system("echo Information Name,Information Content>>$ENV{MBIS_BUILD_INFO_LOG}");
        system("echo BUILD_START_DATATIME,$build_time_string>>$ENV{MBIS_BUILD_INFO_LOG}");
      }
      system("perl $mbis -s \"@orgARGVwithFlavor\"");
    }
  }
  else
  {
    # MBIS_BUILD_TIME_TMP must not be null for makefile expand the command
    $ENV{MBIS_BUILD_TIME_TMP}=tmp;
  }
}

sub mbis_info_probe
{
  if ($mbis_en eq "TRUE")
  {
    if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "$mbis_conf_file"))
    {
      %mbis_conf = iniToHash($mbis_conf_file);
      $pilot_bm_list = $mbis_conf{'INIT_CONF'}->{'BM_LIST'};
      if ($pilot_bm_list =~ /$ENV{USERNAME}/i)
      {
         system("perl $mbis -i BM_BUILD,1");
      }
      else
      {
         system("perl $mbis -i BM_BUILD,0");
      }
    }
    
		$cur_path=cwd(); 
    system("perl $mbis -i BUILD_FOLDER,\"$cur_path\"");
    if($^O eq" MSWin32") {
      system("perl $mbis -i BUILD_MACHINE,$ENV{COMPUTERNAME}");
    }else{
      $hostname = `hostname`;
      system("perl $mbis -i BUILD_MACHINE,$hostname");
    }
    system("perl $mbis -i CUSTOM_RELEASE,$custom_release");
    if ($mbis_num_proc == 0)
    {
      $mbis_num_proc = $ENV{"NUMBER_OF_PROCESSORS"};
    }
    system("perl $mbis -i NUMBER_OF_PROCESSORS,$mbis_num_proc");
    system("perl $mbis -i LSF,$m_in_lsf");
    system("perl $mbis -i COMPILER,$compiler");
    system("perl $mbis -i USER,$ENV{USERNAME}");
    system("perl $mbis -i PROJECT_NAME,$project_name");
    system("perl $mbis -i FLAVOR,$flavor");
    system("perl $mbis -i VERNO,$verno");
    system("perl $mbis -i PLATFORM,$plat");
    system("perl $mbis -i PID,$$");
    if (-e "make/rel/hq/USR.txt") 
    {
      system("perl $mbis -i CODEBASE,FULL");
    }
    else
    {
      system("perl $mbis -i CODEBASE,RELEASE");
      if (-d "make/rel/sub_ps") 
      {
        system("perl $mbis -i REL_PACKAGE,SUB_PS");
      }
      else
      {
        system("perl $mbis -i REL_PACKAGE,SUB_L4");
      }
    }
    if (-e "dailybuild.txt") 
    {
      system("perl $mbis -i DAILY_BUILD_PRODUCER,1");
    }
    else
    {
      system("perl $mbis -i DAILY_BUILD_PRODUCER,0");
    }
    if (-e "ewsprebuild.txt") 
    {
      system("perl $mbis -i EWS_PREBUILD_PRODUCER,1");
    }
    else
    {
      system("perl $mbis -i EWS_PREBUILD_PRODUCER,0");
    }
    my @folder_cnt = <./build/*/*>;
    my $fld_cnt = 0;
    foreach (@folder_cnt){
     $fld_cnt ++ if(-d "$_");
    }
    system("perl $mbis -i NUMBER_OF_PROJECT_FOLDER,$fld_cnt");
  }
}

sub mbis_end_probe
{
  if ($mbis_en eq "TRUE")
  { 
    system("perl $mbis -e");
  }
}

sub mbis_parse_arg
{
  $mbis_arg_exist = 1;
  foreach $arg (@mbis_arg)
  {
    if ($arg =~ /^en_mbis$/i)
    {
      $arg_mbis_en = "TRUE";
    }
    elsif ($arg =~ /^dis_mbis$/i)
    {
      $arg_mbis_en = "FALSE";
    }
    elsif ($arg =~ /^dis_obj$/i)
    {
      $arg_mbis_en_obj_log = "FALSE";
    }
    elsif ($arg =~ /^en_obj$/i)
    {
      $arg_mbis_en_obj_log = "TRUE";      
    }
    elsif ($arg =~ /^save_log$/i)
    {
      $arg_mbis_en_save_log = "TRUE";
    }
    else
    {
      # with error command
      $mbis_arg_exist = 0;
      return ;
    }
  }

  if ($arg_mbis_en ne "TRUE")
  {
    $arg_mbis_en_obj_log = "FALSE";
    $arg_mbis_en_save_log = "FALSE";
  }

}

sub mbis_init
{
  if (($ENV{'MTK_INTERNAL'} eq 'TRUE') && (-e "$mbis_conf_file"))
  {
    %mbis_conf = iniToHash($mbis_conf_file);
    $mbis_bm_list = $mbis_conf{'INIT_CONF'}->{'BM_LIST'};
    $mbis_project_list = $mbis_conf{'INIT_CONF'}->{'PROJECT_LIST'};
    @mbis_project_array=split /,/, $mbis_project_list;
    $mbis_en = $mbis_conf{'INIT_CONF'}->{'EN_ALL_PROJECT'};
    $mbis_en_obj_log = $mbis_conf{'INIT_CONF'}->{'EN_OBJ_LOG'};
    # force all project enable mbis
    # enable obj log for BM only
    if ($mbis_en eq "TRUE")
    {
      # check bm list
      if ($mbis_bm_list =~ /$ENV{USERNAME}/i)
      {
        $mbis_en = "TRUE";
        $mbis_en_obj_log = "TRUE";
      }
      else
      {
        $mbis_en = "TRUE";
        $mbis_en_obj_log = "FALSE";
      }
    }

    # deal with mbis option from arg
    if ($mbis_en eq "TRUE")
    {
      print("MBIS init enable\n");
      if ($mbis_en_obj_log eq "TRUE")
      {
        print("MBIS obj log enable\n");
      }
 
      if ($mbis_arg_exist == 1)
      {
        $mbis_en = $arg_mbis_en;
        $mbis_en_obj_log = $arg_mbis_en_obj_log;
        $mbis_en_save_log = $arg_mbis_en_save_log;
        if ($mbis_en eq "TRUE")
        {
          print("MBIS arg enable\n");
        }
        else
        {
          print("MBIS arg disable\n");
        }
      }
    }
    else
    {
      $mbis_en_obj_log = "FALSE";
      $mbis_en_save_log = "FALSE";
      print("MBIS init disable\n");
    }
  }
}

sub mbis_success
{
  my $build_custom_folder;
  my @files;
  my $elfname;
  my $elfsize;
  # get elf size
  $build_custom_folder = "$targetFolder";
  opendir (DIR, $build_custom_folder) or die "no folder : $build_custom_folder";
  my @files = grep {/^$project_name.*\.elf$/}  readdir DIR;
  close DIR;
  if (@files == 1)
  {
    $elfname = pop @files;
    # add elf file name 
    system("perl $mbis -i ELF_FILE,$elfname");
    $elfsize = -s "$build_custom_folder\\$elfname";
    # add elf file size
    system("perl $mbis -i ELF_SIZE,$elfsize");
  }

  # add success flag
  system("perl $mbis -i SUCCESSFUL_BUILD,1");
}

sub chk_vc9
{
	my $Register = "SOFTWARE\\Microsoft\\VCExpress\\9.0\\Setup\\VC";
	my ($key, $type, $data);
	RegOpenKeyEx(HKEY_LOCAL_MACHINE, $Register, 0, KEY_READ, $key) or return 0;
	if (RegQueryValueEx($key, "ProductDir", [], $type, $data, []))
	{
		if (($data ne "") && (-e $data))
		{
			return 1;
		}
	}
	RegCloseKey($key) or die "Can't close HKEY_LOCAL_MACHINE\n";
	return 0;
}

sub error_handle
{
	my $build_folder = "$targetFolder";
	opendir (DIR, $build_folder) or die "no folder : $build_folder\n";
	my @files = grep {/.+\.bin$/}  readdir DIR;
	close DIR;
	my $flag = 0;
	foreach (@files) {
		next if($_ =~ /BOOTLOADER/i);
		my $bin_file = $build_folder."/$_";
		if (-d "$bin_file") {
			rmtree($bin_file);
			$flag = 1;
		} elsif(-e "$bin_file") {
			unlink($bin_file) or die "Remove failed $!";
			$flag = 1;
		}
	}
	print "Some errors happened during the build process. Delete the binary file\n" if($flag);
# [Linux] temporarily add
	unlink("nul") if($^O eq "linux" && -e "nul");
	unlink("NUL") if($^O eq "linux" && -e "NUL");
	exit 1;
}

sub genCustombld{
  $bldPathName = "$projectFolder/Custom.bld";
  if(-e "make/rel/hq/USR.txt"){
    $bldValue = "FALSE";
  }
  else{
    $bldValue = "TRUE";
  }
  if(-e $bldPathName){
    open BLDFILE,"<$projectFolder/Custom.bld" or die "Can not open $projectFolder/Custom.bld";
    while(<BLDFILE>){
      if(/CUSTOM_RELEASE = $bldValue/){
        close BLDFILE;
        return 0;
      }
    }
    close BLDFILE;
  }
  open BLDFILE,">$projectFolder/Custom.bld" or die "Can not open $projectFolder/Custom.bld";
  print BLDFILE "CUSTOM_RELEASE = $bldValue\n";
  close BLDFILE;
}
