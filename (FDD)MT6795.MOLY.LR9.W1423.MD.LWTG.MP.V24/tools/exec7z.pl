#!/usr/local/bin/perl

use Win32;

my $cwd = Win32::GetCwd();

my $upper_cwd = $cwd;

my $upper_folder;

print " cwd == \"$cwd\" \n";


if ( $cwd =~ /[\s\w]*\\([\s\w]+)/ )
{
	 if ( "$1" ne "" )
	 {
	   print "I got upper folder  == \"$1\" \n";
	   $upper_folder = "$1";
	 } else
	 {
	  print " We can not match upper folder \n";	 	
	 }
} else
{
	 print " We can not match upper folder \n";	 	
}

  $upper_cwd =~  s/$upper_folder//;
  $upper_folder   =~  s/\s/_/;

if ( -e "c:\\progra~1\\7-zip\\7z.exe" )
{
	system "date/t & time/t";
	print "cd build & del *.obj /s /q ";
	system "cd build & del *.obj /s /q ";
	print "c:\\progra~1\\7-zip\\7z.exe  a -mx=5 -r ${upper_cwd}${upper_folder}.7z $cwd \n";
  system "c:\\progra~1\\7-zip\\7z.exe  a -mx=5 -r ${upper_cwd}${upper_folder}.7z $cwd \n";
  system "date/t & time/t";
	
} else
{
	print " c:\\progra~1\\7-zip\\7z.exe not found \n";
}



exit 0;
