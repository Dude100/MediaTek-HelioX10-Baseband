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

my @drvs = ("W","X","Y","Z","G","H","I","J","L","N","O","P","Q","R","S","V");

my $CheckPath;
my $result="FALSE";
my $gotNetDrvChar;

my $complintlogdir;
my $component;
#print  " \$argv[0]= $ARGV[0] \n";

#$(COMPLINTLOGDIR)

$complintlogdir = $ARGV[1];
$component = $ARGV[2];



#######################


foreach $adrv ( @drvs )
{
  if ( $result ne "TRUE" ) 
  {
    $CheckPath = $adrv;
#    print " drv == $adrv \n";    
    &checkLoop;
    $idx++;
  } else
  {
    break;
  }    
}

#######################


my $env_tmp = $ENV{TMP};

if ( $env_tmp !~ /\\$/ )
{
	  $env_tmp = "$env_tmp"."\\";
}	



#if( ! -e "$env_tmp"."aa.lnt" )
#{
#  print("copy tools\\aa.lnt $env_tmp \n");
#  system("copy tools\\aa.lnt $env_tmp  \n");
#}





open(F, ">$ARGV[0]")  or die $!;

  print F "Net_ReadOnly_DIR = $FullCheckPath\n";
  print F "COMPLINTLOGDIR = $complintlogdir\n";
  print F "COMPONENT = $component\n";

close(F);


   


###############################################

sub checkLintFile {  
  if ( -d $_[0] )
  {
    if (( -e $_[0]."lint-nt.exe" ) &&  ( -e $_[0]."co-ads.lnt" )  )
    {
       return "TRUE";	    	
    } else
    {
       return "FALSE";	    	
    }  	  	
  } else 
  {  	
    return "FALSE";	
  } 
}
########################################
sub checkLoop {	
  $FullCheckPath =  $CheckPath.":\\";
  if ( -d $FullCheckPath )
  {
     $result = &checkLintFile( $FullCheckPath );
   
     if ( $result eq "TRUE" )
     {
      	 $gotNetDrvChar = $CheckPath;
      	 #print " Lint Net Drv == $gotNetDrvChar \n";
          return;
     }	
  } else
  {   
    system "net use "."$CheckPath".": /delete  \n";   # delete Unavailable NET driver   
    print " cmd==". " net use "."$CheckPath".": \\\\srdfs01\\lint  \n";   
    system "net use "."$CheckPath".": \\\\srdfs01\\lint  \n"; 
  }

  if ( -d $FullCheckPath )
  {
     $result = &checkLintFile( $FullCheckPath ); 
     if ( $result eq "TRUE" )
     {
        $gotNetDrvChar = $CheckPath;
    	  print " Lint Net Drv == $gotNetDrvChar \n";
    	  return;
     }    
  }

} # sub checkLoop
