use strict;
use Cwd qw(abs_path getcwd);

my $flag_print = 0;
my $flag_create = 2;
my $flag_modis = 0;
if ($ARGV[0] =~ /^--append$/i)
{
	$flag_create = 1;
	shift @ARGV;
}
elsif ($ARGV[0] =~ /^--extract$/i)
{
	$flag_create = 0;
	shift @ARGV;
}
elsif ($ARGV[0] =~ /^--modis$/i)
{
	$flag_modis = 2;
	shift @ARGV;
}

if ($#ARGV < 3)
{
	die "Usage: pack_dep_gen.pl output.dep target.obj input/parse/dir regular_expression [file_prefix]\n";
}

my $depFile = shift @ARGV;
my $objFile = shift @ARGV;
my $depDirs = shift @ARGV;
my $filters = shift @ARGV;
my $preDirs = shift @ARGV;

my $current = getcwd();
$current =~ s/\\/\//g;
$current =~ s/\/$//g;
$current = quotemeta($current);
$preDirs .= "/" if ($preDirs ne "");

if ($flag_create > 0)
{
	my @cgenDep;
	&CollectDepend(\@cgenDep, $depFile, $depDirs, $filters);
	print "\n" if ($flag_modis == 0);
	&WriteDepend(\@cgenDep, $depFile, $objFile, $preDirs);
}
else
{
	&ExtractDepend($depFile, $depDirs);
}

sub CollectDepend
{
	my $refArray = shift;
	my $outputDep = shift;
	my $inputDir = shift;
	my $exprRule = shift;

	my $DIRHANDLE;
	my $FILEHANDLE;
	if (opendir($DIRHANDLE, $inputDir))
	{
	}
	else
	{
		print "Skip for opendir " . $inputDir . "\n";
		return 0;
	}
	my @fileDep = readdir $DIRHANDLE;
	closedir $DIRHANDLE;
	print "Processing" if ($flag_modis == 0);
	foreach my $dep (@fileDep)
	{
		next if ($dep !~ /$exprRule\b/i);
		if ($outputDep =~ /\b${dep}$/)
		{
			next if ($flag_create != 1);
		}
		print " " . $dep if ($flag_modis == 0);
		my $line;
		open $FILEHANDLE, "<$inputDir/$dep";
		if ($dep =~ /\.lis$/i)
		{
			# for cgen.exe -src or xcopy
			while ($line = <$FILEHANDLE>)
			{
				if ($line =~ /^(\S+\.\w+)\s*$/i)
				{
					my $src = $1;
					push @$refArray, $src;
				}
			}
		}
		elsif ($dep =~ /mmi_copy\.log$/i)
		{
			# for ResGenerator_OP
			my $log_flag;
			my $path;
			while ($line = <$FILEHANDLE>)
			{
				my $src;
				if ($line =~ /^\s*(.+?)\s*copied from (\S+) to \S+/i)
				{
					my $line2 = $1;
					$path = $2;
					$log_flag = "";
					if ($line2 =~ /^.*?\((\w+\.\w+)\)$/)
					{
						$src = $1;
					}
					elsif ($line2 =~ /^\w+\.\w+$/)
					{
						$src = $line2;
					}
					elsif ($line2 =~ /^.*?\(\*\.(\w+)\)$/)
					{
						$log_flag = $1;
					}
				}
				elsif ($log_flag ne "")
				{
					if ($line =~ /(\S+?\.$log_flag)\s*$/i)
					{
						$src = $1;
					}
				}
				else
				{
					$log_flag = "";
					$path = "";
				}
				if (($src ne "") && ($path ne ""))
				{
					$path =~ s/^\\//;
					$src = $path . "\\" . $src;
					push @$refArray, $src;
				}
			}
		}
		elsif ($dep =~ /\.log$/i)
		{
			# for MoDIS cl.exe or pregen log
			while ($line = <$FILEHANDLE>)
			{
				my $line2;
				$line =~ s/[\r\n]//g;
				if ($line =~ /\[Dependency\]\s*(.*?)\s*$/i)
				{
					$line2 = $1;
				}
				elsif ($line =~ /Note: including file:\s*(.*?)\s*$/i)
				{
					$line2 = $1;
				}
				elsif ($line =~ /Parsing\s+File\s*:\s*(.*?)\s*$/i)
				{
					$line2 = $1;
				}
				elsif ($line =~ /Processing archive:\s*(.*?)\s*$/i)
				{
					$line2 = $1;
				}
				elsif ($line =~ /^Res:\s*(\S+\.\w+)\s*$/i)
				{
					$line2 = $1;
				}
				elsif ($line =~ /^==VenusXML Begin==\s+\[(\S+\.\w+)\]\s*$/i)
				{
					$line2 = $1;
				}
				next if ($line2 =~ /(Program Files)|(Microsoft Visual Studio)/i);
				foreach my $src (split(/\s+/, $line2))
				{
					#if (($src ne "") && ($src !~ /\.obj$/i))
					if ($src =~ /\.(c|cpp)$/i)
					{
						unshift(@$refArray, $src);
					}
					elsif ($src ne "")
					{
						push(@$refArray, $src);
					}
				}
				if ($line2 =~ /\\(Audio|Image)\.zip$/i)
				{
					# for resgen
					$line2 =~ s/\\(Audio|Image)\.zip$//i;
					print "\n" if ($flag_modis == 0);
					my @resDep;
					&CollectDepend(\@resDep, $outputDep, $line2, "_file_list\.ini");
					$line2 =~ s/^(\w+mmi\\+Customer\\+ResGenerator\\+).*$/$1/i;
					foreach my $src (@resDep)
					{
						if ($src =~ /\\+Customer\\+Images\\+\w+\\+(Main|Sub)LCD\\+/i) {
						} elsif ($src =~ /\\+Customer\\+Audio\\+(PLUTO|NEPTUNE)\\+\w+\\+/i) {
						} else {
							push @$refArray, $line2 . $src;
						}
					}
				}
			}
		}
		elsif ($dep =~ /\.ini$/i)
		{
			# for audio_file_list.ini binary_file_list.ini images_file_list.ini
			while ($line = <$FILEHANDLE>)
			{
				next if ($line =~ /^\[.+\]\s*$/i);
				if ($line =~ /^file name\s*\w+\s*=\s*(.*?)\s*$/i)
				{
					push @$refArray, $1;
				}
			}
		}
		else
		{
			# for Target armcc.exe
			while ($line = <$FILEHANDLE>)
			{
				next if ($line =~ /(Program Files)|(Microsoft Visual Studio)/i);
				next if ($line =~ /^\#/i);
				$line =~ s/[\r\n]//g;
				$line =~ s/^\s*(\S+\:)?\s*(.*?)\s*(\\)?$/$2/;
				foreach my $src (split(/\s+/, $line))
				{
					next if ($src =~ /mcd[\\\/]include[\\\/]mcd_l3\.h/i);
					if (($src ne "") && ($src !~ /[\\\/]~/) && ($src !~ /^~/))
					{
						if ($src =~ /\.(c|cpp)$/i)
						{
							unshift(@$refArray, $src);
						}
						else
						{
							push(@$refArray, $src);
						}
					}
				}
			}
		}
		close $FILEHANDLE;
	}
}

sub WriteDepend
{
	my $refArray = shift;
	my $outputDep = shift;
	my $targetDep = shift;
	my $prefixDir = shift;
	my $objFirst = 1;
	my $outText;
	my %saw;
	my @fileDep = grep (!$saw{$_}++, @$refArray);
	my %fileSrc;
	my %fileObj;
	foreach my $dep (@fileDep)
	{
		if ($dep ne "")
		{
			$dep = $prefixDir . $dep if ($dep !~ /^[a-zA-Z]:\\/);
			$dep =~ s/[\\\/]+/\//g;
			$dep =~ s/\/\.\//\//g;
			$dep =~ s/^\.\///;
			while ($dep =~ /\w+\/\.\.\//)
			{
				$dep =~ s/\w+\/\.\.\///;
			}
			while ($dep =~ /^(\/)?\.\.\//)
			{
				$dep =~ s/^(\/)?\.\.\///;# remove "..\"
			}
			while ($dep =~ /^\w\:\/\.\.\//)
			{
				$dep =~ s/^(\w\:\/)\.\.\//$1/;# remove "k:\..\"
			}
			$dep =~ s/^$current\///i;
			if ($flag_modis)
			{
				$dep =~ s/^[k-z]\:[\/]+//i;# for subst
				if ($dep =~ /.+\/(\S+?)\.(c|cpp)$/i)
				{
					$fileSrc{lc($1)} = $dep;
					if ($^O eq "MSWin32")
					{
						$fileSrc{lc($1)} =~ s/\//\\/g;
					}
					next;
				}
				elsif ($dep =~ /.+\/(\S+?)\.obj$/i)
				{
					$fileObj{lc($1)} = $fileSrc{lc($1)};
					next;
				}
				elsif ($dep =~ /\/auto_header\.h/i)
				{
					next;
				}
			}
			next if (! -e $dep);
			# skip temp file
			next if ($dep =~ /\~\w+\.tmp/i);
			next if ($dep =~ /\/\w+_dep\/\w+\.det/i);
			next if ($dep =~ /\bverno\/verno\.h/i);
			next if ($dep =~ /\bheader_temp\/\S+\.h/i);
			next if ($dep =~ /\/temp\/ref_list\/ref_list_\S+\.txt/i);
			next if ($dep =~ /\/Customer\/ResGenerator\/temp\//i);
			next if ($dep =~ /\/Customer\/ResGenerator\/debug\//i);
			next if ($dep =~ /\/Customer\/Res_MMI\//i);
			next if ($dep =~ /\/Customer\/Res_MMI_XML\//i);
			next if ($dep =~ /\/asn1\/asn1_src\/(mcd_)?dbme\.asn/i);
			if ($dep =~ /\/PlmnEnum\.h/i)
			{
				next if ($outputDep =~ /\/codegen_dep\/\w+\.d/i);
				next if ($outputDep =~ /\/xml_parser\.d/i);
			}
			if ($dep =~ /\/Customer\/CustomerInc\/mmi_rp_mmi3dresource_def\.h/i)
			{
				next if ($outputDep =~ /\/codegen_dep\/\w+\.d/i);
			}
			if (($^O eq "MSWin32") && ($flag_modis))
			{
				$dep =~ s/\//\\/g;
			}
			if ($objFirst)
			{
				$outText .= "	$dep";
				$objFirst = 0;
			}
			else
			{
				$outText .=  " \\\n		$dep";
			}
		}
	}
	my $FILEHANDLE;
	open $FILEHANDLE, ">$outputDep" or die "Fail to write $outputDep\n";
	if ($flag_modis)
	{
		foreach my $key (keys %fileSrc)
		{
			next if (exists $fileObj{$key});
			my $value = $fileSrc{$key};
			$outText .=  " \\\n		$value";
			print "include " . $value . " for " . $key ."\n" if ($flag_print);
		}
		foreach my $key (sort keys %fileObj)
		{
			print $FILEHANDLE "#UPDATE#\n";
			print $FILEHANDLE $key . ".obj: " . $fileObj{$key} . " \\\n	";
			print $FILEHANDLE $outText . "\n";
			print $FILEHANDLE "#ENDUPDATE#\n";
		}
	}
	else
	{
		print $FILEHANDLE $targetDep . ":";
		print $FILEHANDLE $outText . "\n";
	}
	close $FILEHANDLE;
}

sub ExtractDepend
{
	my $inputDep = shift;
	my $outputDir = shift;
	my $FILEHANDLE;
	open $FILEHANDLE, "<$inputDep" or die "Fail to open $inputDep\n";
	my @fileDep = <$FILEHANDLE>;
	close $FILEHANDLE;
	my $targetDep;
	foreach my $line (@fileDep)
	{
		if ($line =~ /\#UPDATE\#/i)
		{
		}
		elsif ($line =~ /^(\S+?):\s*(\S+)\s*\\?/)
		{
			if ($targetDep ne "")
			{
				close $FILEHANDLE;
				$targetDep = "";
			}
			$targetDep = $1;
			$targetDep =~ s/^.*\\//;
			$targetDep =~ s/\.\w+$/.det/;
			open $FILEHANDLE, ">$outputDir/$targetDep" or die "Fail to write $outputDir/$targetDep\n";
			print $FILEHANDLE "\#UPDATE\#\n";
			print $FILEHANDLE $line;
		}
		elsif ($line =~ /^\s*(\S+)\s*\\?/)
		{
			print $FILEHANDLE $line;
		}
	}
	if ($targetDep ne "")
	{
		close $FILEHANDLE;
		$targetDep = "";
	}
}
