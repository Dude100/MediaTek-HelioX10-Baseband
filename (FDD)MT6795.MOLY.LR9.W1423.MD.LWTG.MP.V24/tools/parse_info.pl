#!/usr/bin/perl
# To parse info.log to get compile options and including paths.
$infolog = $ARGV[0];
$comp = $ARGV[1];
$inc = $ARGV[2];
$mtksub = $ARGV[3];

open (FILE_HANDLE, "<$infolog") or die "Cannot open info.log\n";
my @data = split('\[',join('',<FILE_HANDLE>));
foreach my $set (@data) {
  next if($set =~ /^\s*$/);
  if($set =~ /COMMON OPTION \]/) {
    $common_compile_option = substr($set,$+[0]);
  } elsif($set =~ /COMMON INCLUDE PATH \]/) {
    $common_include_path = substr($set,$+[0]);
  } else {
    die "Unknown instruction $set";
  }
}
close FILE_HANDLE;
#print $common_compile_option."\n";
open (W,">$comp") or die "Cannot open output file $comp:$!\n";
  print W $common_compile_option;
close W;

$index=index($common_include_path,$ENV{"RVCT22INC"});
$length=length($ENV{"RVCT22INC"});
substr($common_include_path,$index,$length,"");

open (W,">$inc") or die "Cannot open output file $inc:$!\n";
  print W $common_include_path;
close W;
open (W,">$mtksub") or die "Cannot open output file $mtksub:$!\n";
  @common_compile_option = split('\s', $common_compile_option);
  foreach (@common_compile_option) {
  next if ($_ eq "");
  print W "-D$_\n";
  }
  @common_include_path = split('\s', $common_include_path);
  foreach (@common_include_path) {
  next if ($_ eq "");
  print W "-I..\\mediatek\\$_\n";
  }
close W;
