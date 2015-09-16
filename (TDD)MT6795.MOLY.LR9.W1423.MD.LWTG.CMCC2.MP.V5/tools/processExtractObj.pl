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
  print "perl processExtractObj.pl ProcdFile ExtractObj.ini\n";
  exit 1;
}

#$NvramCustPack = $ARGV[0];
$NvramLidSize = $ARGV[0];
$NvramTmp = $ARGV[1];
$CustomWapCustPack = $ARGV[2];
$custom = $ARGV[3];
$project = $ARGV[4];
$outputdir = $ARGV[5];
$ExtractObjFile = $ARGV[6];
$var=0;
$new_line = "";
chomp($cwd = `cd`);
if ($cwd =~ /.*\\$/){
  chop($cwd);
}

# Process ~nvram_lid_size.log to get custpack needed LID names.
# Use LID names to get LID variable names from ~nvram_tmp.c.

open (F1,"<$NvramLidSize") || die "Cannot open ~nvram_lid_size.log, please execute nvram_auto_gen first:$!\n";
while (<F1>)
{
  if (/(\d+)\s*(\d+)\s*(\w.+\w)\s*\bCUSTPACK\b/){
  	$nvram_name{$3} = 1;
  }
}
close(F1);

open (nvramtmp,"<$NvramTmp") || die "Cannot open ~nvram_cust_pack.c\n";
$backup = $/;
undef $/;
$reading = <nvramtmp>;
$/ = $backup;
close nvramtmp;

open (ExtractObjFile,">$ExtractObjFile") || die "Cannot open $ExtractObjFile:$!\n";
print ExtractObjFile "[VAR_NAME]\n";

if ($reading =~ /const custpack_nvram_header custpack_nvram_ptr\s*=\s*\{.+?\{(.+?)\}/s) {
  $nvram_variable = $1;
}

while($nvram_variable =~ /(\w+)[,|\s]/){
	$nvram_variable=$';
	$var++;
  print ExtractObjFile "Var$var = \"$1\"\n";
}

# Process custom\common\custom_wap_cust_pack.c to get custpack_wap_ptr variable names.
open (F2,"<$CustomWapCustPack") || die "Cannot open $CustomWapCustPack:$!\n";
$backup = $/;
undef $/;
$reading=<F2>;
$/ = $backup;
close(F2);

if ($reading =~ /const wap_custpack_header custpack_wap_ptr\s*=\s*\{([\w|\s|,|&]+)\}/) {
	$custpack_wap_ptr = $1;
}

while($custpack_wap_ptr =~ /&(.+?)[,|\s]/){
  $custpack_wap_ptr = $';
  $var++;
  print ExtractObjFile "Var$var = \"$1\"\n";  
}

# Write [EXTRACTOBJ_PERL_SCRIPT] section to extractObj.ini
print ExtractObjFile "\n\[EXTRACTOBJ_PERL_SCRIPT\]\n";
print ExtractObjFile "CUSTOM = \"$custom\"\n";
print ExtractObjFile "PROJECT = \"$project\"\n";
print ExtractObjFile "OUTPUTDIR = \"$cwd\\$outputdir\"\n";
print ExtractObjFile "OBJ1 = \"custom_wap_cust_pack.obj\"\n";
print ExtractObjFile "OBJ2 = \"nvram_cust_pack.obj\"\n";
close(ExtractObjFile);

