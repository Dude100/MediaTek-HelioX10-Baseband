my $chkverno = $ARGV[0];
my $len = rindex $chkverno."\$", "\$";
if($len > 63)
{
		print "The verno message($len bytes) exceeds 63 bytes,please check it ASAP!\n";
		die;
}
else
{
	exit 0;	
}
