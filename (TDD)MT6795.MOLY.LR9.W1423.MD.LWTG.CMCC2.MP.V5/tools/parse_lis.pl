#!/usr/bin/perl

$lisfile = $ARGV[0];
$output = $ARGV[1];

open (FILE_HANDLE, "<$lisfile") or die "Cannot open $lisfile\n";
  $backup = $/; undef $/;
  $reading = <FILE_HANDLE>;
  $/ = $backup;
close FILE_HANDLE;

open (W,">$output") or die "Cannot open output file $output:$!\n";
  
if ($reading =~ /Memory Map of the image/) {
  $reading = $';
  if ($reading =~ /==============/) {
    print W $`;
  } else {
    print W $reading;
  }
}
close W;

