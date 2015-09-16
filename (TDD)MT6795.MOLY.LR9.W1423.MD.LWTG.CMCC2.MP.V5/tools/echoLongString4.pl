#!/usr/local/bin/perl
$OUTPUT = $ARGV[0];
shift(@ARGV);

@INPUT = @ARGV;

@new_output = sort @INPUT;

if(-e $OUTPUT) {
	open(W,">>$OUTPUT") or die "Cannot open $OUTPUT";
} else {
	open(W,">$OUTPUT") or die "Cannot open $OUTPUT";
}

foreach (@new_output) {
  print W "$_ ";
}
print W "\n";
close(W);




