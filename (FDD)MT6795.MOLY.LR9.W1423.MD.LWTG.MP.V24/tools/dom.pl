
use Getopt::Long;

GetOptions("cfg|configs:s", "dox|Doc-o-MaticProjectFile:s");

$dom_exe = 'C:\\Program Files\\Doc-O-Matic 6 Professional\\dmcc.exe';

if( $opt_cfg !~ /html|pdf|chm|all/io )
{ # Not a valid argument
	if ($opt_cfg eq "")
	{
    print "\n\nError : Configuration must be specified by -cfg option.\n";
  }
  else
  {
    print "\n\nInvalid argument : '$opt_cfg'\n";
  }
  exit;
}

if( !$opt_dox )
{ # must specify a project file 
  print "\n\nMissing Doc-o-Matic project file. Use -dox to specify project file.\n";
  exit;
}

# change options to lowercase
$opt_cfg =~ s/HTML/html/igo;
$opt_cfg =~ s/PDF/pdf/igo;
$opt_cfg =~ s/CHM/chm/igo;
$opt_cfg =~ s/ALL/all/igo;

$cmd = "" ;
if ($opt_cfg eq "html")
{
	$cmd = "\"${dom_exe}\" -config \"MTKDocConfig-HTML\" -noshow -w3";
}
elsif ($opt_cfg eq "pdf")
{
	$cmd = "\"${dom_exe}\" -config \"MTKDocConfig-PDF\" -noshow -w3";
}
elsif ($opt_cfg eq "chm")
{
	$cmd = "\"${dom_exe}\" -config \"MTKDocConfig-CHM\" -noshow -w3";
}
else
{
	$cmd = "\"${dom_exe}\" -all -noshow -w3";
}
$cmd = "$cmd $opt_dox";
print "$cmd\n";
system($cmd);

$a = &getTime;
$t = time - $^T;

print "\n$a, Program took $t secs\n";




sub getTime()
{
	my ($sec, $min, $hour, $mday, $mon, $year) = localtime(time);
	my $timeStr;

	if (defined($_[0]) && ($_[0] ne ""))
	{
		# return timestamp as part of filename
		$timeStr = sprintf("%4.4d%2.2d%2.2d%2.2d%2.2d%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
	}
	else
	{
		$timeStr = sprintf("%4.4d/%2.2d/%2.2d %2.2d:%2.2d:%2.2d", $year+1900, $mon+1, $mday, $hour, $min, $sec);
	}
	
	return $timeStr;
}
