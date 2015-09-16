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
#******************************************************************************
# Module Use
#******************************************************************************
use File::Copy;
use File::Path;
use File::Spec;
my $dev_nul = File::Spec->devnull();
#******************************************************************************
# Subroutine: Usage
#******************************************************************************
sub usage {
  print "perl custominfo.pl <Makefile>\n";
  exit 1;
}

#******************************************************************************
# Check input arguments
#******************************************************************************
&Usage if ($#ARGV == -1);
$thefile = $ARGV[0];

die "$thefile does NOT exist\n" if (!-e $thefile);
if ($thefile =~ /make\/(\w+)_(\w+)\((\w+)\)\.mak/i) {
  $custom = uc($1);
  $project = lc($2);
  print " custom = $custom\n project = $project \n flavor = $3 \n";
}

($custom eq "") && &Usage;
($project eq "") && &Usage;

open (FILE_HANDLE, "<$thefile") or die "Cannot open $thefile\n";
while (<FILE_HANDLE>) {
  if ((/^([^\#]*)\#?.*/) && ($1 =~ /^(\w+)\s*=\s*(.*\S)\s*$/)){
    $keyname = lc($1);
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;

if (($mmi_version eq "NEPTUNE_MMI") || ($mmi_version eq "NEPTUNE_COLOR_MMI")) {
  $mmidir = "lcmmi";
} else {
  $mmidir = "plutommi";
}

#******************************************************************************
# Section for
# >>> Copy default files to project folder
#******************************************************************************
if (defined $touch_panel_shortcut_support) {
  if ($touch_panel_shortcut_support eq "TRUE") {
    copy("custom/common/touch_panel_shortcut_custom.c.tmp", "custom/app/$board_ver/touch_panel_shortcut_custom.c");
    copy("custom/common/touch_panel_shortcut_custom.h.tmp", "custom/app/$board_ver/touch_panel_shortcut_custom.h");
  }
}

if (-d "${mmidir}/Customer/Images/decoder/RGB565") {
	copy("copy ${mmidir}/Customer/Images/decoder/RGB565/*.*", "${mmidir}/Customer/Images");
}

#******************************************************************************
# Procress for JAVA
#******************************************************************************
my @thatdirs;

if (($project ne "basic") && ($project ne "l1s") && defined($j2me_support)) {
  if ($j2me_support ne "NONE") {
    if ($j2me_support eq "JBLENDIA") {
      push(@thatdirs, "j2me/JBLENDIA");
      $j2me_boardBB = $board_ver;
    } elsif ($j2me_support eq "JBLENDIA_MVM") {
      push(@thatdirs, "j2me/jblendia_mvm");
      $j2me_boardBB = $board_ver;
    } elsif ($j2me_support eq "JBED") {
    	push(@thatdirs, "j2me/JBED");
    	$j2me_boardBB = $board_ver;
    } elsif ($j2me_support eq "NEMO") {
    	push(@thatdirs, "j2me/NEMO");
    	$j2me_boardBB = $board_ver;
      if ($original_flavor !~ /\bNONE\b/i) {
        $j2me_boardBB = "${board_ver}\($original_flavor\)";
      }    	 	
    }elsif($j2me_support eq "IJET"){
      push(@thatdirs, "j2me/IJET");
      $j2me_boardBB = $board_ver;
      if ($original_flavor !~ /\bNONE\b/i) {
        $j2me_boardBB = "${board_ver}\($original_flavor\)";
      }
    } elsif ($j2me_support eq "MTK_DUMMY_MVM") {
    	push(@thatdirs, "j2me/DUMMY");
    	$j2me_boardBB = $board_ver;
    } else {
      push(@thatdirs, "j2me/DUMMY");
      $j2me_boardBB = $board_ver;
      if ($original_flavor !~ /\bNONE\b/i) {
        $j2me_boardBB = "${board_ver}\($original_flavor\)";
      }
    }
    my $j2meFolder = $j2me_support;
    if($j2me_support eq "MTK_DUMMY_MVM"){
      $j2meFolder = "DUMMY";
    }
    if (!-e "custom/j2me/$j2meFolder/$j2me_boardBB/j2me_custom_option.h") {
      if (-e "custom/j2me/$j2meFolder/_DEFAULT_BB/_j2me_custom_option.h") {
        copy("custom/j2me/$j2meFolder/_DEFAULT_BB/_j2me_custom_option.h", "custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_option.h");
      }
    } else {
    	if (-e "custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_option.h") {
      	unlink("custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_option.h");
      }
    }

    if (!-e "custom/j2me/$j2meFolder/$j2me_boardBB/j2me_custom_param.h") {
      if (-e "custom/j2me/$j2meFolder/_DEFAULT_BB/_j2me_custom_param.h") {
        copy("custom/j2me/$j2meFolder/_DEFAULT_BB/_j2me_custom_param.h", "custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_param.h");
      }
    } else {
      if (-e "custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_param.h") {
      	unlink("custom/j2me/$j2meFolder/_DEFAULT_BB/j2me_custom_param.h");
      }
    }
  }
}

foreach $t (@thatdirs) {
  $thatdir = "custom/$t";
  $defaultBB =  "$thatdir/_DEFAULT_BB";
  $boardBB = "${thatdir}/${board_ver}";
  if ($j2me_support eq "IJET") {
    $j2me_boardBB = $boardBB;
    if (($original_flavor !~ /\bNONE\b/i) && (!-e "${thatdir}/${board_ver}\($original_flavor\)")) {
      print "${thatdir}/${board_ver}\($original_flavor\) does not exist. Please execute romizing first.\n";
      exit(1);
    }
    if ($original_flavor !~ /\bNONE\b/i) {
      if (-e "${thatdir}/${board_ver}\($original_flavor\)") {
        $j2me_boardBB = "${thatdir}/${board_ver}\($original_flavor\)";
      }
    }
  }elsif ($j2me_support eq "NEMO") {
    $j2me_boardBB = $boardBB;
    if (($original_flavor !~ /\bNONE\b/i) && (!-e "${thatdir}/${board_ver}\($original_flavor\)")) {
      print "${thatdir}/${board_ver}\($original_flavor\) does not exist. Please execute romizing first.\n";
      exit(1);
  }
    if ($original_flavor !~ /\bNONE\b/i) {
      if (-e "${thatdir}/${board_ver}\($original_flavor\)") {
        $j2me_boardBB = "${thatdir}/${board_ver}\($original_flavor\)";
      }
    }
  }
  if ($j2me_support eq "JBLENDIA" || $j2me_support eq "JBLENDIA_MVM") {
    
    $gameGenDir = "$defaultBB/jblend_preinstall";
    $gameExe = "DirRomizer.exe";
    $gamePapay = "PapayaPik.exe";
    $gameConfig = "PapayaPik.cfg";
    $gameGenFile = "${gameGenDir}/$gameExe";
    $certRomizer = "certRomizer.exe";
    $certRomizerFile = "${gameGenDir}/$certRomizer";
    $certRomizerString = $certRomizerFile;
    if ((-d $defaultBB) && (-d $gameGenDir) && (-e $gameGenFile)) {
      chdir($gameGenDir);
      $gamecfg = "../../$board_ver/$gameConfig";
      $gamecfgdir = "../../$board_ver";
      if (-e $gamecfg) {
      	unlink("$gamecfg");
      }
      if (!-e $gamecfg) {
      	mkpath("$gamecfgdir") if (!-e $gamecfgdir);
        copy($gameConfig, $gamecfg);
        open (GAME_CFG_H, ">>$gamecfg") or die "Cannot open $gamecfg\n";
        $jarcnt = 1;
        if (((-d "../../$board_ver") && (<../../$board_ver/*.jar>)) ||
            (!((($mmi_version eq "PLUTO_MMI")||($mmi_version eq "COSMOS_MMI")||($mmi_version eq "NEPTUNE_MMI")||($mmi_version eq "NEPTUNE_COLOR_MMI")) &&
             ($empty_resource eq "FALSE")))) {
          while ($jarname = <../../${board_ver}/*.jar>) {
            $jadname = $jarname;
            $jadname =~ s/\.jar/\.jad/;
            ($jadname = "") if (!-e $jadname);
            print GAME_CFG_H "MIDletSuite-$jarcnt: $jadname , $jarname\n";
            $jarcnt++;
          }
        } else {
          while ($jarname = <../*.jar>) {
            $jadname = $jarname;
            $jadname =~ s/\.jar/\.jad/;
            ($jadname = "") if (!-e $jadname);
            print GAME_CFG_H "MIDletSuite-$jarcnt: $jadname , $jarname\n";
            $jarcnt++;
          }
        }
        close GAME_CFG_H;
      }
      unlink("./rom/*");
      print("$gamePapay -config $gamecfg\n");
      system("$gamePapay -config $gamecfg");
      print("$gameExe rom\n");
      system("$gameExe rom > $dev_nul");
      move("kjava_sys_data_content.c", "../../$board_ver");
      move("kjava_sys_data_content.h", "../../$board_ver");
      # back to mcu folder
      chdir("../../../../..");
    }
    # For certRomizer.exe
    if (-e "$boardBB/kjava_sys_ext_cert.c") {
      unlink("$boardBB/kjava_sys_ext_cert.c");
    }
    if (-e "$defaultBB/kjava_sys_ext_cert.c") {
      unlink("$defaultBB/kjava_sys_ext_cert.c");
    }

    if (-e $certRomizerFile) {
    	if (<$boardBB/cert/*.cer>) {
    		while (<$boardBB/cert/*.cer>) {
    			$certRomizerString = $certRomizerString." ".$_;
    		}
        system("$certRomizerString > $boardBB/kjava_sys_ext_cert.c");
    	} elsif (<$gameGenDir/cert/*.cer>){
    		  while (<$gameGenDir/cert/*.cer>) {
    			  $certRomizerString = $certRomizerString." ".$_;
    		  }
    		  system("$certRomizerString > $defaultBB/kjava_sys_ext_cert.c");
      }
    }
  } else {   
    $gameGenDir = "$defaultBB/builtin_game_generator";
    $gameExe = "DefaultGameGen.exe";
    $gameGenFile = "${gameGenDir}/$gameExe";
    $ori_board_ver = $board_ver;
    if ($original_flavor !~ /\bNONE\b/i) {
      $board_ver = "${board_ver}\($original_flavor\)";
    }
    if ((-d $defaultBB) && (-d $gameGenDir) && (-e $gameGenFile)) {
      chdir($gameGenDir);
      if (((-d "../../$board_ver") && ((<../../$board_ver/*.jar>) || (<../../$board_ver/*.jad>))) ||
          (!((($mmi_version eq "PLUTO_MMI")||($mmi_version eq "COSMOS_MMI")||($mmi_version eq "NEPTUNE_MMI")||($mmi_version eq "NEPTUNE_COLOR_MMI")) ))) {
         if ((-d "../../$board_ver") && ((-e "../../$board_ver/_main.ks") && (-e "../../$board_ver/_policy.txt") && (-e "../../$board_ver/_tck.ks") )) {
           print("$gameExe -certfolder -setpath ./setting -inputSystem ../../$board_ver -inputMidlet ../../$board_ver -output ../../$board_ver -create -logpath ../../$board_ver\n");
           system("$gameExe -certfolder -setpath ./setting -inputSystem ../../$board_ver -inputMidlet ../../$board_ver -output ../../$board_ver -create -logpath ../../$board_ver");
                    } else {
           print("$gameExe -certfolder -setpath ./setting -inputSystem .. -inputMidlet ../../$board_ver -output ../../$board_ver -create -logpath ../../$board_ver\n");
           system("$gameExe -certfolder -setpath ./setting -inputSystem .. -inputMidlet ../../$board_ver -output ../../$board_ver -create -logpath ../../$board_ver");
           
         }
      } else {
         if ((-d "../../$board_ver") && ((-e "../../$board_ver/_main.ks") && (-e "../../$board_ver/_policy.txt") && (-e "../../$board_ver/_tck.ks") )) {
           print("$gameExe -certfolder -setpath ./setting -inputSystem ../../$board_ver -inputMidlet .. -output ../../$board_ver -create -logpath ..\n");
           system("$gameExe -certfolder -setpath ./setting -inputSystem ../../$board_ver -inputMidlet .. -output ../../$board_ver -create -logpath ..");
           
         } else {
           print("$gameExe -certfolder -setpath ./setting -inputSystem .. -inputMidlet .. -output .. -create -logpath ..\n");
           system("$gameExe -certfolder -setpath ./setting -inputSystem .. -inputMidlet .. -output .. -create -logpath ..");
           
         }
      }
      # back to mcu folder
      chdir("../../../../..");
    } else {
      print("Skip to generate JAVA game due to no $gameGenFile\n");
    }
    $board_ver = $ori_board_ver;
  }

}

exit(0);

