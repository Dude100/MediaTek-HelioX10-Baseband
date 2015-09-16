#!/usr/local/bin/perl
$OUTPUT = shift(@ARGV);
#print "$OUTPUT\n";

$ITEM = shift(@ARGV);
#print "$ITEM\n";

@INPUT = @ARGV;
#print "@INPUT\n";

#@new_output = sort @INPUT;
#print "@new_output\n";

foreach my $file (@INPUT) {
  if ((-e $file) && (open(FILE_HANDLER,"<$file")))
  {
    while(<FILE_HANDLER>) {
      if($_ !~ /^\s/) {
        if($_ !~ /.+\s$/) {
          push @output, $_;
        } else {
          chomp;
          push @output, $_;
        }
      }
    }
    close(FILE_HANDLER);
  }
  else
  {
    print STDERR "[Error] fail to open $file\n";
  }
}

my %saw;
@output = grep (!$saw{$_}++, @output);
if(-e $OUTPUT) {
	open(W,">>$OUTPUT") or die "Cannot open $OUTPUT";
} else {
	open(W,">$OUTPUT") or die "Cannot open $OUTPUT";
}
foreach my $def (@output)
{
	print W "$ITEM$def\n";
}
close(W);

