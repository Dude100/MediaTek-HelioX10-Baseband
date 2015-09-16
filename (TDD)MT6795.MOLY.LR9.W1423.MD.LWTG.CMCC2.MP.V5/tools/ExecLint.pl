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
# 
#################################################################################

  use Win32::Process;
  use Win32;
  use File::Basename;


# ..\make\comp.mak

# mount net use from  G to Z except M: K: U: , T:
# W:\ is first priority

my $CheckPath;
my $result="FALSE";
my $gotNetDrvChar;


my $lintcfgfile = $ARGV[0];
my $viaFile = $ARGV[1] ;
#print  "ExecLint.pl #56: via  file      = $ARGV[1] \n";

my $sourceFile = $ARGV[2] ;
#print  "ExecLint.pl #60: source C  file = $ARGV[2] \n";

my $net_readonly_dir;
my $lint;


my $complintlogdir;
my $component;
my $cwd;
my $fulllogpath;
my $fulltoolspath;


######################################################################

chomp($cwd = `cd`);
#print "cwd==$cwd\n";
#print "complintlogdir==$complintlogdir\n";


#print "lintcfgfile == $lintcfgfile \n";


open(F, "<$lintcfgfile")  or die "  $! $lintcfgfile   \n";

while (<F>)
{ 	
  # print "$_";
  
  if (/\s*Net_ReadOnly_DIR\s*=\s*(\S+)\s*/)
  {
  	  $net_readonly_dir =   $1;  	
  	  #print "net_readonly_dir == $net_readonly_dir \n";
  }
   elsif (/\s*COMPLINTLOGDIR\s*=\s*([\.]+)(\S+)\s*/)
  {   
     $complintlogdir = $2;
     #print "complintlogdir = $complintlogdir\n";
  }
       elsif (/\s*COMPONENT\s*=\s*(\S+)\s*/)
  {   
     $component = $1;
     #print "component = $component\n";
  };   

    
};

close(F);

if ( "$complintlogdir" eq "")
{
  exit 110;
}

#######################

#print " net_readonly_dir == $net_readonly_dir \n";
#print " LINT = $lint \n";


#######################

# print "ExecLint.pl line 92 \n";

#print "cwd == $cwd\n";

$fulllogpath = "$cwd"."$complintlogdir\\";
$fulltoolspath = "$cwd\\"."tools\\";


#print "complintlogdir == $complintlogdir\n";


print "perl tools\\splitfile.pl "."$fulllogpath"."TMP_LNT.lnt $viaFile \n";
system "perl tools\\splitfile.pl "."$fulllogpath"."TMP_LNT.lnt $viaFile \n";



print  "$net_readonly_dir"."lint-nt.exe +v -zero -i"."$net_readonly_dir"."   $fulllogpath"."TMP_LNT.lnt "."$fulltoolspath"."cd_me1.lnt co-ads.lnt  +os("."$fulllogpath"."$component"."\.log) +oe("."$fulllogpath"."$component"."\.log)  $sourceFile	\n";
system  "$net_readonly_dir"."lint-nt.exe +v -zero -i"."$net_readonly_dir"."   $fulllogpath"."TMP_LNT.lnt "."$fulltoolspath"."cd_me1.lnt co-ads.lnt  +os("."$fulllogpath"."$component"."\.log) +oe("."$fulllogpath"."$component"."\.log)  $sourceFile	\n";


   

