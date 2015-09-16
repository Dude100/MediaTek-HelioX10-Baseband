
$afile=$ARGV[0];
$ifile=$ARGV[1];
#print "$afile\n";
$str = `type $ifile`;
#print "$str\n";
#$str =~ s/ /\n/g;
#print "$str\n";
@outstr=split(/ /,$str);
open NEWF,">$afile";
foreach (@outstr) {
	next if ($_!~ m/^\-[DI]/);
	print NEWF "$_\n";
}
#print NEWF $str;
close NEWF;
