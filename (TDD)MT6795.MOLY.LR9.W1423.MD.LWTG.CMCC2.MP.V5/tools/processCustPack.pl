#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2008
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
# To process CustImgNamesExt and put image information to ExtractObj.ini.
#******************************************************************************
# Subroutine: Usage
#******************************************************************************
sub usage {
  print "perl processCustPack.pl CustImgNamesExt ExtractObj.ini\n";
  exit 1;
}

$CustImgNamesExt = $ARGV[0];
$NvramLidSize = $ARGV[1];
$NvramTmp = $ARGV[2];
$NvramCustPack = $ARGV[3];
$CustomWapCustPack = $ARGV[4];
$CustpackAudio = $ARGV[5];
$ThemeRes = $ARGV[6];
$outputdir = $ARGV[7];
$CustomPack = $ARGV[8];
$templateCustomPack = $ARGV[9];
$database = $ARGV[10];
$symfile = $ARGV[11];
$InputCustomPackPath = $ARGV[12];
$CustVenusTheme = $ARGV[13];
$NvramCustPackCerts = $ARGV[14];
$NvramCustPackJavaCerts = $ARGV[15];
if (defined $ARGV[16]) {
$IfWapSupport = $ARGV[16];
}
$theme_file = 0;
$lid_name = 0;
$lid_file = 0;
$wap_num = 0;
$wap_data = 0;
$wap_file = 0;
chomp($cwd = `cd`);
if ($cwd =~ /.*\\$/){
  chop($cwd);
}




#$backup = $/;
#undef $/;
#$reading=<F>;
#$/ = $backup;
#close(F);

# Convert to absolute path
#$reading =~ s/=\s+"(\S)/= "$cmd$1/g;

if (-e "$templateCustomPack") {
  if($templateCustomPack =~ /(.+)\\custpack\.ini/i){
    $originalCustPackPath = $1;
  }
  system ("move /y $templateCustomPack $originalCustPackPath\\~custpack.ini");
}
open (File,"<$originalCustPackPath\\~custpack.ini") || die "Cannot open the reference custpack file:$!\n";
$backup = $/;
undef $/;
$template=<File>;
$/ = $backup;
close(File);

my $isLCMMI = 0;
if($CustImgNamesExt =~ /plutommi/i)
{
  $isLCMMI = 0;
}
elsif($CustImgNamesExt =~ /lcmmi/i)
{
  $isLCMMI = 1;
}

open (W,">$CustomPack") || die "Cannot open $CustomPack:$!\n";

# [Setting]
print W "[Setting]\n";
print W "Input_CustPack_ROM_PATH = \"$cwd\\$InputCustomPackPath\\CUSTPACK_ROM\"\n";
print W "OutputBin_PATH = \"$cwd\\$outputdir\\CUSTPACK_ROM\"\n";
print W "Database_PATH = \"$cwd\\$database\"\n";
if (-e $database) {
  system("copy /y $database $outputdir");
} else {
  print "Warning! $database does not exist!\n";
}
# Get CustPackResPreamble from sym file or Execution Region CUSTPACK_ROM from lis file.
open (FILE,"<$symfile") || die "Cannot find SYM file:$!\n";
while (<FILE>) {
  if ($_ =~ /(.+?)\s*\w+\s*CustPackResPreamble/) {
  	$StartAddress = $1;
  }
  if ($_ =~ /(.+?)\s*\w+\s*LangPackResPreamble/) {
  	$LangPack_StartAddress = $1;
  }
}
close (FILE);
print W "StartAddress = \"$StartAddress\"\n";
print W "CUSTPACK_Version = \"0001\"\n";
#print W "Input_ThirdROM_PATH = \"$cwd\\$InputCustomPackPath\\THIRD_ROM\"\n";
#print W "Output_ThirdROM_PATH = \"$cwd\\$outputdir\\THIRD_ROM\"\n";
#if(0 == $isLCMMI){
#  print W "LangPack_StartAddress = \"$LangPack_StartAddress\"\n";
#  print W "Input_LANG_PACK_ROM_PATH = \"$cwd\\$InputCustomPackPath\\LANG_PACK_ROM\"\n";
#  print W "Output_LANG_PACK_PATH = \"$cwd\\$outputdir\\LANG_PACK_ROM\"\n";
#}
#if (-e "$cwd\\$InputCustomPackPath\\THIRD_ROM") {
#  print W "ThirdROM_Exist = TRUE\n\n";
#} else {
#  print W "ThirdROM_Exist = FALSE\n\n";
#}
print W ";set Disable_WAP = 1 for Low Cost MMI\n";
if ($IfWapSupport == 1) {
  print W "Disable_WAP = 0\n\n";
} else {
  print W "Disable_WAP = 1\n\n";
}

if($CustImgNamesExt =~ /plutommi/i)
{
  print W "LCMMI = 0\n\n";
}
elsif($CustImgNamesExt =~ /lcmmi/i)
{
  print W "LCMMI = 1\n\n";
}

if ($template =~ /(.+)\[Image\]/isg) {
	$template = $';#'
#  print W $1;
}

# [Image]
# Process custom\app\$(strip $(BOARD_VER))\nvram_cust_pack.c to get LID and NVRAM variable names.

open (F,"<$CustImgNamesExt") || die "Cannot open CustImgNamesExt $CustImgNamesExt:$!\n";

while(<F>)
{
   if (m/(\S+)\s+=\s+\"(\S+)\"/)
   {
   $reading .= $1 . " = " . '"' . $cwd . '\\' . $2 . '"' . "\n";
   }
}
close(F);
print W "[Image]\n";
print W $reading;
# [Font]
#if (0 == $isLCMMI){
#  my $fontReading;
#  my $countFont = 0;
#  open (FONTEXT,"<$CustFontNamesExt") || die "Cannot open CustFontNamesExt $CustFontNamesExt:$!\n";
#  while(<FONTEXT>)
#  {
#  	if (m/(\S+)\s+=\s+\"(\S+)\"/)
#  	{
#  		$fontReading .= $1 . " = " . '"' . $cwd . '\\' . $2 . '"' . "\n";
#  		$countFont++;
#  	}
#  }
#  close(F);
#  if($countFont > 0){
#  	print W "[Font]\n";
#  	print W $fontReading;
#  }
#}
# [Theme]
# Process plutommi\Customer\CustResource\ThemeRes.c to get MMI_theme names.
#open (F,"<$ThemeRes") || die "Cannot open ~ThemeRes.c $ThemeRes:$!\n";
#$backup = $/;
#undef $/;
#$reading=<F>;
#$/ = $backup;
#close(F);


if ($ThemeRes =~ /.+\\(.+?)\.bin/ig) {
  print "$ThemeRes\n";
  if (-e "$ThemeRes\\$1") {
    print W "\n[Theme]\n";
    print W "THEME_FILE = \"$cwd\\$ThemeRes\\$1\"\n";
  }
  elsif(-e "$ThemeRes") {
  	print W "\n[Theme]\n";
    print W "THEME_FILE = \"$cwd\\$ThemeRes\"\n";
  }
  else{
    print "Skip write Theme\n";
  }
}
#if ($reading =~ /const MMI_theme \*mtk_MMI_themes\[.*\]\s*=\s*\{\s*(.+\s*.+\s*.+\s*.+\s*)\}/){
#  $mmi_theme = $1;
#  $theme_file++;
#  print W "THEME_FILE$theme_file = MMI_theme\n";
#} elsif ($reading =~ /const theme_details_struct mtk_MMI_themes\[.*\]=\{\s*(.+?)\};/is) {
#  $theme_details_struct = $1;
#  $theme_file++;
#  print W "THEME_FILE$theme_file = theme_details_struct\n";
#}
#const theme_details_struct mtk_MMI_themes[ 3 ]={
#if (defined $mmi_theme){
#  while ($mmi_theme =~ /.+&(.+?)[,\s]/){
#    $mmi_theme = $';
#    $theme_file++;
#    print W "THEME_FILE$theme_file = \"$outputdir\\$1\.bin\"\n";
#  }
#}
#if (defined $theme_details_struct){
#  while ($theme_details_struct =~ /.+&(.+?)[,\s]/){
#    $theme_details_struct = $';
#    $theme_file++;
#    print W "THEME_FILE$theme_file = \"$outputdir\\$1\.bin\"\n";
#  }
#}

# [AutoGenAudio]
open (Custpackaudio,"<$CustpackAudio") || die "Cannot open CustAdoNamesExt $CustpackAudio:$!\n";

my $readingfile = '';


while(<Custpackaudio>)
{
   if (m/(\S+)\s+=\s+\"(\S+)\"/)
   {
   $readingfile .= $1 . " = " . '"' . $cwd . '\\' . $2 . '"' . "\n";
  }
}

print $cwd,"\n";
close(Custpackaudio);
print W "[AutoGenAudio]\n";
print W $readingfile;

#[venus theme]
print W "\n";
if(-e $CustVenusTheme){
  open (CUSTVENUSTHEME,"<$CustVenusTheme") || die "Cannot open VenusTheme.ini\n";
  $backup = $/;
  undef $/;
  my $reading = <CUSTVENUSTHEME>;
  $/ = $backup;
  close CUSTVENUSTHEME;
  print W $reading;
}

open (nvramtmp,"<$NvramTmp") || die "Cannot open ~nvram_tmp.c\n";
$backup = $/;
undef $/;
my $reading = <nvramtmp>;
$orig_reading = $reading;
$/ = $backup;
close nvramtmp;

# [NVRAM]
# Process custom\app\$(strip $(BOARD_VER))\nvram_cust_pack.c to get NVRAM and LID variable names.
$count = 0;
open (NvramLidSize,"<$NvramLidSize") || die "Cannot open ~nvram_lid_size.log, please execute nvram_auto_gen first:$!\n";
while (<NvramLidSize>)
{
  if (/(\d+)\s*(\d+)\s*(\w.+\w)\s*\bCUSTPACK\b/){
  	if(!defined $nvram_name{$3}) {
  		$count++;
  	  $nvram_name{$3} = $count;
  	} else {
  	  next;
  	}
  }
}
close(NvramLidSize);

open (nvramtmp,"<$NvramTmp") || die "Cannot open ~nvram_tmp.c\n";
$backup = $/;
undef $/;
my $reading = <nvramtmp>;
$orig_reading = $reading;
$/ = $backup;
close nvramtmp;

print W "\n[NVRAM]\n";
print W "\;the order of following LID_NAME and LID_FILE must be same as their appearing in nvram_cust_pack.c\n";
print W "\;plz note that sometimes some of them will disappear because of different compile combinations\n";
# Add LID_NAME

while ($reading =~ /\{\s*(NVRAM_[\w\d]+)\s*,\s*([^,]+),\s*([^,]+),\s*([^,]+),\s*[^,]+,\s*[^,]+,\s*([^,]+),[^\}]+\}\s*/)
{
   $reading =$';#'

   my %this_app            = ();
   $this_app{APPLICATION}  = $1;
   $this_app{UNIT_SIZE}    = $2;
   $this_app{RECORD_NUM}   = $3;
   $this_app{NVRAM_VALUE}  = $4;
   $this_app{APP_NAME}     = $5;
   next unless ($this_app{APP_NAME} =~ /\"/);

   $this_app{UNIT_SIZE}    =~ s/\s//g;
   $this_app{RECORD_NUM}   =~ s/\s//g;
   $this_app{APP_NAME}     =~ s/^\"(.+)\\0\"$/$1/;
   if (defined $nvram_name{"$this_app{APPLICATION}"}){
     $lid_count{$nvram_name{"$this_app{APPLICATION}"}} = $this_app{APPLICATION};
   }
}

for ($i=1;$i<=$count;$i++){
  $lid_name++;
  print W "LID_NAME$lid_name = \"$lid_count{$i}\"\n";
}

# Add LID_FILE
open (NvramCustPack,"<$NvramCustPack") || die "Cannot open ~nvram_cust_pack.c\n";
$backup = $/;
undef $/;
my $reading = <NvramCustPack>;
$/ = $backup;
close NvramCustPack;

if ($reading =~ /const custpack_nvram_header custpack_nvram_ptr\s*=\s*\{.+?\{(.+?)\}/s) {
  $nvram_variable = $1;
}

while($nvram_variable =~ /(\w+)[,|\s]/){
	$nvram_variable=$';#'
	$lid_file++;
  print W "LID_FILE$lid_file = \"$cwd\\$outputdir\\BIN\\$1\.bin\"\n";
}

# Process custom\common\custom_wap_cust_pack.c to get custpack_wap_ptr variable names.
open (F2,"<$CustomWapCustPack") || die "Cannot open ~custom_wap_cust_pack.c $CustomWapCustPack:$!\n";
$backup = $/;
undef $/;
$reading=<F2>;
$/ = $backup;
close(F2);

if ($reading =~ /typedef struct\s*\{([\w|\s|;|\*]+)\}\s*wap_custpack_header/) {
	$wap_custpack_header = $1;
	$wap_custpack_num_use = $1;
}

if ($reading =~ /const wap_custpack_header custpack_wap_ptr\s*=\s*\{([\w|\s|,|&]+)\}/) {
	$custpack_wap_ptr = $1;
}

if (defined $ARGV[16]) {
  print W "\n\[WAP\]\n";
  while($wap_custpack_num_use =~ /\s*(.+?)\s*const/){
    $wap_custpack_num_use = $';#'
    $wap_num++;
  }
  print W "WAP DATA NUM = $wap_num\n";
}

while($wap_custpack_header =~ /\s*(.+?)\s*const/){
  $wap_custpack_header = $';#'
  $wap_data++;
  print W "WAP_DATA$wap_data = \"$1\"\n";  
}

while($custpack_wap_ptr =~ /&(.+?)[,|\s]/){
  $custpack_wap_ptr = $';#'
  $wap_file++;
  print W "WAP_FILE$wap_file = \"$cwd\\$outputdir\\BIN\\$1.bin\"\n";  
}

if(-e $NvramCustPackCerts){
  $cafolder="${outputdir}\\root_ca";
  if(!-e $cafolder){
    $command="md $cafolder";
    system("$command");
  }
  open (CERTFILEHANDL,"<$NvramCustPackCerts") || die "Cannot open ~custom_custpack_certs.c $NvramCustPackCerts:$!\n";
  $backup = $/;
  undef $/;
  $reading=<CERTFILEHANDL>;
  $/ = $backup;
  close(CERTFILEHANDL);
  $reading =~ /custpack_root_ca_header_struct\s+custpack_root_ca\s+=\s*\{(.+?)\}\;/s;
  @hotlines = split /\n/,$1;
  $cert_file_num = 0;
  $namelist = 1;
  for $line(@hotlines){
    if($line =~ /^\s*$/){
      next;
    }
    if($line =~ /^#line/){
      next;
    }
    if($line =~ /^\s*\}\s*$/){
      next;
    }
    if($line =~ /^\s*\{\s*$/){
      next;
    }
    if($line =~ /^\s*\(*(\d+)\)*,\s*$/){
      $cert_file_num = $1;
      next;
    }
    @sections = split /,/,$line;
    $cert_name;
    $cert_format;
    $cert_domain;
    $cert_readonly;
    if($sections[0] =~ /^\s*\{+\s*(\S+)\s*$/){
      $cert_name = $1;
    }
    else{
      print "Get cert name error.\n";
    }
    if($sections[2] =~ /\s*\((\d+)\)\s*/){
      $cert_format = $1;
    }
    else{
      print "Get format section error.\n";
    }
    if($sections[3] =~ /\s*\((\d+)\)\s*/){
      $cert_domain = $1;
    }
    else{
      print "Get domain section error.\n";
    }
    if($sections[4] =~ /\s*\((\d+)\)\s*/){
      $cert_readonly = $1;
    }
    else{
      print "Get readonly setion error.\n";
    }
    $cert_content;
    if($reading =~ /${cert_name}\[\] \=\s*\{(.+?)\}/s){
      $cert_content = $1;
    }
    $certs{$namelist}=[$cert_format,$cert_domain,$cert_readonly,$cert_content,$cert_name];
    $namelist++;
  }
  print W "\n\n";
  # Certificate
  print W "\;Certificate\n";
  print W "\;The following section is an example\n";
  print W "\[Certificate\]\n";
  print W "\; File number need to match the number of files listed below\n";
  print W "CERT_FILE_NUM=${cert_file_num}\n\n";
  print W "\; Domain : 0 for manufacture (default), 1 for operator, 2 for 3rd party\n";
  print W "\; Format : 0 for X.509 certificate (default), 1 for WTLS\n";
  for (sort by_number keys %certs){
    print W "CERT_FILE".$_."_FORMAT = ".$certs{$_}[0]."\n";
    print W "CERT_FILE".$_."_DOMAIN = ".$certs{$_}[1]."\n";
    print W "CERT_FILE".$_."_READONLY = ".$certs{$_}[2]."\n";
    $cert_filename = $outputdir."\\root_ca\\".$certs{$_}[4]."\.der";
    open CERTFILE,">$cert_filename" or die "Can not open $cert_filename\n";
    binmode CERTFILE;
    while($certs{$_}[3] =~ /(0x\S\S)/){
      $cerl=$1;
      $cerl=hex $1;
      $certs{$_}[3] =~ s/(0x\S\S)/ /;
      print CERTFILE pack("c1", $cerl);
    }
    close CERTFILE;
    print W "CERT_FILE".$_." = $cwd\\".$cert_filename."\n";
  }
}
else{
  print "not exits $NvramCustPackCerts\n";
}
undef %certs;
print W "\n";
if(-e $NvramCustPackJavaCerts){
  print "Java certs\n";
  $cafolder="${outputdir}\\java_ca";
  if(!-e $cafolder){
    $command="md $cafolder";
    system("$command");
  }
  open (CERTFILEHANDL,"<$NvramCustPackJavaCerts") || die "Cannot open ~custom_custpack_java_certs.c $NvramCustPackJavaCerts:$!\n";
  $backup = $/;
  undef $/;
  $reading=<CERTFILEHANDL>;
  $/ = $backup;
  close(CERTFILEHANDL);
  $reading =~ /custpack_java_root_ca_header_struct\s+custpack_java_root_ca\s+=\s*\{(.+?)\}\;/s;
  @hotlines = split /\n/,$1;
  $cert_file_num = 0;
  $namelist = 1;
  for $line(@hotlines){
    if($line =~ /^\s*$/){
      next;
    }
    if($line =~ /^#line/){
      next;
    }
    if($line =~ /^\s*\}\s*$/){
      next;
    }
    if($line =~ /^\s*\{\s*$/){
      next;
    }
    if($line =~ /^\s*\(*(\d+)\)*,\s*$/){
      $cert_file_num = $1;
      next;
    }
    @sections = split /,/,$line;
    $cert_name;
    $cert_format;
    $cert_domain;
    $cert_readonly;
    if($sections[0] =~ /^\s*\{+\s*(\S+)\s*$/){
      $cert_name = $1;
    }
    else{
      print "Get cert name error.\n";
    }
    if($sections[2] =~ /\s*\((\d+)\)\s*/){
      $cert_format = $1;
    }
    else{
      print "Get format section error.\n";
    }
    if($sections[3] =~ /\s*\((\d+)\)\s*/){
      $cert_domain = $1;
    }
    else{
      print "Get domain section error.\n";
    }
    if($sections[4] =~ /\s*\((\d+)\)\s*/){
      $cert_readonly = $1;
    }
    else{
      print "Get readonly setion error.\n";
    }
    $cert_content;
    if($reading =~ /${cert_name}\[\] \=\s*\{(.+?)\}/s){
      $cert_content = $1;
    }
    $certs{$namelist}=[$cert_format,$cert_domain,$cert_readonly,$cert_content,${cert_name}];
    $namelist++;
  }

  print W "\[JAVA Certificate\]\n";
  print W "\; File number need to match the number of files listed below\n";
  print W "CERT_FILE_NUM=${cert_file_num}\n";
  print W "\; Domain : 0 for manufacture (Default), 1 for operator, 2 for 3rd party\n";

  for (sort by_number keys %certs){
    print W "CERT_FILE".$_."_FORMAT = ".$certs{$_}[0]."\n";
    print W "CERT_FILE".$_."_DOMAIN = ".$certs{$_}[1]."\n";
    print W "CERT_FILE".$_."_READONLY = ".$certs{$_}[2]."\n";
    $cert_filename = $outputdir."\\java_ca\\".$certs{$_}[4]."\.cer";
    open CERTFILE,">$cert_filename" or die "Can not open $cert_filename\n";
    binmode CERTFILE;
    while($certs{$_}[3] =~ /(0x\S\S)/){
      $cerl=$1;
      $cerl=hex $1;
      $certs{$_}[3] =~ s/(0x\S\S)/ /;
      print CERTFILE pack("c1", $cerl);
    }
    close CERTFILE;
    print W "CERT_FILE".$_." = $cwd\\".$cert_filename."\n";
  }
}

if (!defined $ARGV[16]) {
  if ($template =~ /(.+)\;Variable/isg) {
    print W "\n\;Variable";
  }
} else {
  if ($template =~ /(.+)\[Variable\]/isg) {
	  $template = $';#'
    print W "\n\[Variable\]";	
    print W $template;
  }
}

close(W);


sub by_number {
  if($a < $b){-1} elsif($a > $b){1} else {0};
}