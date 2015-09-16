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

my $lisfile="make\\bootloader\\bootloader.lis";
my $pthfile="make\\bootloader\\bootloader.pth";
my $incfile="make\\bootloader\\bootloader.inc";

while ($#ARGV != -1) {
  if ($ARGV[0] =~ /^board_ver=(\w+)/i) {
    $board_ver = $1;
  } elsif ($ARGV[0] =~ /^themf=([\w|\\||\/|\.]+)/i) {
    $themf = $1;
  } else {
    &Usage;
  }
  shift(@ARGV);
}

(!defined($board_ver) || ($board_ver eq "") || (!-d ".\\custom\\system\\${board_ver}")) && &Usage;

die "$themf does NOT exist\n" if (!-e $themf);
open (FILE_HANDLE, "<$themf") or die "Cannot open $themf\n";
while (<FILE_HANDLE>) {
  if (/^(\S+)\s*=\s*(\S+)/) {
    $keyname = lc($1);
    defined($${keyname}) && warn "$1 redefined in $themf!\n";
    $${keyname} = uc($2);
  }
}
close FILE_HANDLE;

open (file,"+<$lisfile") || die "cannot open $lisfile\n";   
truncate file, 0;

my $reading = "";

# Bootloader System
my $thatdir = "bootloader\\src";
opendir THATDIR, $thatdir;
@allfiles1 = grep -T, map "$thatdir/$_", readdir THATDIR;
closedir THATDIR;

foreach $elem (@allfiles1) {
	$elem =~ s/\//\\/g;
	if ($elem =~ m/[a-zA-Z0-9_\.\\\/]*\.[csCS]$/) {	
     $reading .= "$elem\n";
   }
}

$reading .= "custom\\system\\${board_ver}\\custom_emi.c\n";
$reading .= "sss\\interface\\src\\SSS_interface.c\n";
$reading .= "custom\\system\\${board_ver}\\custom_blconfig.c\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\gpio_drv.c\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\keypad_def.c\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\usb_custom.c\n";
$reading .= "custom\\system\\${board_ver}\\custom_flash.c\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\codegen\\gpio_var.c\n" if (-e "custom\\drv\\misc_drv\\${board_ver}\\codegen\\gpio_var.c");
$reading .= "custom\\drv\\common_drv\\gpio_setting.c\n";
$reading .= "drv\\src\\gpio.c\n";
$reading .= "custom\\drv\\common_drv\\pwic_cust.c\n";
$reading .= "init\\src\\cp15.s\n";
$reading .= "init\\src\\cache.c\n";
$reading .= "drv\\src\\nand_mtd_fdm50.c\n";
$reading .= "drv\\src\\nand_dal.c\n";
$reading .= "drv\\src\\NAND_DevConfig.c\n";
$reading .= "interface\\l1interface\\l1_interface.c\n";
$reading .= "init\\GFH\\public\\br_GFH_parser.c\n";
$reading .= "init\\GFH\\public\\br_GFH_file_info.c\n";
$reading .= "sss\\interface\\crypto\\export\\public\\br_crypto_platform.c\n";
$reading .= "drv\\src\\flash_mtd_sf_common.c\n";
$reading .= "init\\src\\dmdsp_init.c\n";

# CARD Download
if ($card_download eq "TRUE") {
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\msdc_custom.c\n" if (-e "custom\\drv\\misc_drv\\${board_ver}\\msdc_custom.c");
  $reading .= "drv\\src\\msdc.c\n";
  $reading .= "drv\\src\\sd.c\n";
  $reading .= "drv\\src\\sd_drv.c\n";
  $reading .= "drv\\src\\msdc_fake_kal.c\n";
  #$reading .= "drv\\display\\src\\mt6236lcd\\lcd_if_6236.c\n";
  $reading .= "drv\\display\\src\\lcd_if.c\n";
  $reading .= "lqt\\src\\lcd_lqt.c\n";
  $reading .= "lcd.c\n";
  
  # For Backlight
  $reading .= "drv\\src\\pwic.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\alerterdrv.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\pwmdrv.c\n";
  $reading .= "drv\\src\\rtc.c\n";
  $reading .= "drv\\src\\rwg.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\uem_gpio.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\custom_equipment.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\custom_hw_default.c\n";
  $reading .= "custom\\drv\\misc_drv\\${board_ver}\\codegen\\uem_drv.c\n";
    
  #$reading .= "drv\\src\\pwm.c\n";
  
  $reading .= "plutommi\\Framework\\GDI\\GDISrc\\gdi_image_alpha_bmp_v2_internal.c\n";
  $reading .= "plutommi\\Framework\\GDI\\GDISrc\\gdi_image_alpha_bmp_v2_core.c\n";
}


$reading .= "drv\\src\\keypad_bl.c\n";
$reading .= "drv\\src\\pmu_bl.c\n";
$reading .= "drv\\src\\pmu6236_bl.c\n";
$reading .= "drv\\src\\pmu6253_bl.c\n";
$reading .= "drv\\src\\pmu6253el_bl.c\n";
$reading .= "drv\\src\\pmu6255_bl.c\n";
$reading .= "drv\\src\\pmu6276_bl.c\n";
$reading .= "drv\\src\\pmu6251_bl.c\n";
$reading .= "drv\\src\\upmu_common_bl.c\n";
$reading .= "drv\\src\\pwm_bl.c\n";

$reading .= "custom\\drv\\misc_drv\\${board_ver}\\pmu_custom.c\n" if (-e "custom\\drv\\misc_drv\\${board_ver}\\pmu_custom.c");;
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\codegen\\pmic_drv.c\n" if (-e "custom\\drv\\misc_drv\\${board_ver}\\codegen\\pmic_drv.c");
$reading .= "drv\\src\\pmic_MT6255PMU_drv.c\n";
$reading .= "drv\\src\\pmic_MT6276PMU_drv.c\n";
$reading .= "drv\\src\\pmic_MT6251PMU_drv.c\n";

$reading .= "init\\CBR\\CBR.c\n";

seek(file, 0, 0);
print file $reading;
close file;
     
open (file,"+<$pthfile") || die "cannot open $pthfile\n";   
truncate file, 0;
$reading  = "custom\\system\\${board_ver}\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\codegen\n";
$reading .= "custom\\drv\\common_drv\n";
$reading .= "bootloader\\src\n";
$reading .= "drv\\src\n";
$reading .= "sss\\interface\\src\n";
$reading .= "init\\src\n";
$reading .= "init\\CBR\n";
$reading .= "interface\\l1interface\n";
$reading .= "init\\GFH\\public\n";
$reading .= "drv\\display\\src\\mt6236lcd\n";
$reading .= "drv\\display\\src\n";
$reading .= "plutommi\\Framework\\GDI\\GDISrc\n";
$reading .= "lqt\\src\n";
$reading .= "sss\\interface\\crypto\\export\\public\n";

seek(file, 0, 0);
print file $reading;
close file;

open (file,"+<$incfile") || die "cannot open $incfile\n";
truncate file, 0;
$reading  = "bootloader\\inc\n";
$reading .= "inc\n";
$reading .= "init\\include\n";
$reading .= "init\\CBR\n";
$reading .= "drv\\include\n";
$reading .= "dp_engine\\che\\include\n";
$reading .= "applib\\misc\\include\n";
$reading .= "custom\\drv\\misc_drv\\${board_ver}\\codegen\n";
$reading .= "custom\\system\\${board_ver}\n";
$reading .= "fota\\inc\n";
$reading .= "ssf\\inc\n";
$reading .= "custom\\common\n";
$reading .= "kal\\Efs\\include\n";
$reading .= "interface\\l1interface\n";
$reading .= "interface\\hwdrv\n";
$reading .= "dsp_ram\n";
$reading .= "drv\\display\\include\\mt6236lcd\n";
$reading .= "drv\\display\\include\n";
$reading .= "plutommi\\Framework\\GDI\\GDIInc\n";
$reading .= "sss\\interface\\inc\n";
$reading .= "init\\GFH\\public\n";
$reading .= "init\\ftl\n";
$reading .= "sss\\interface\\crypto\\export\\public\n";
seek(file, 0, 0);
print file $reading;
close file;

exit 0;

sub Usage {
  warn " Usage:\n";
  warn "     $0 board_ver=MT6226_EVB\n";
  exit 1;
}
