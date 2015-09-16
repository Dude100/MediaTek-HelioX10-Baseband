#! /usr/bin/perl -w 

use strict;
use warnings;
use diagnostics;
   
 
$ENV{'ENCODE_BUFFER_SIZE'} = "4000";
 
$ENV{'SUPPORT_VERSION'} = "2";
$ENV{'SUPPORT_GENERATE_ALTERNATIVE_COMMONFILES'} = "1";
$ENV{'SUPPORT_GENERATE_ALTERNATIVE_COMMONFILES_PREFIX'}="";
$ENV{'GEN_COMMON_FILE_ONLY'}="1";
   
 
print "OS: $^O\n";

my $result;
my $command;
my $input = "";

if ( $^O eq "MSWin32" )
{
  $command = "mtkasn.exe $input";
  $result = system $command;  
}
elsif ($^O eq "linux") 
{
  system "chmod 777 ./mtkasn";
  $command = "./mtkasn $input";
  $result = system $command;
}
else
{
   my $final_error_msg = "the tool cannot run on $^O system\n";
   print $final_error_msg;
   exit(1);
}

delete $ENV{'SUPPORT_VERSION'};
delete $ENV{'SUPPORT_GENERATE_ALTERNATIVE_COMMONFILES'};
delete $ENV{'SUPPORT_GENERATE_ALTERNATIVE_COMMONFILES_PREFIX'}; 
delete $ENV{'ENCODE_BUFFER_SIZE'};
delete $ENV{'GEN_COMMON_FILE_ONLY'}; 


exit(0);

