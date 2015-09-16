use strict;
use File::Basename;

my ($fileOut,$depDir,$hList,$hTempFOlder) = @ARGV;

if ($#ARGV < 3)
{
	print "pack_dep_gcc.pl output_filename dep_input_dir htogether_list header_temp\n";
	die "DIE\n";
}

$hTempFOlder =~ s/^\.\///;
my %Hpath;
my %header_list;
if (defined $hList && -d "$hTempFOlder") {
  open HEADER_LIST,"<$hList" or die "Error: cannot open $hList";
  while(<HEADER_LIST>) {
    if ($_ =~ /cp(\s+)(\S+)(\s+)(\S+)/) {
      my $origi_file = $2;
      $origi_file =~ s/^\.\///;
      my $headerF = basename($origi_file);
      $Hpath{"$hTempFOlder/$headerF"} = $origi_file;
    }
  }
  close HEADER_LIST;
}

my $depContent;
opendir DIRHANDLE, "$depDir" or die "Cannot open dir $depDir: $!";
my @fileList = readdir DIRHANDLE;
closedir DIRHANDLE;
foreach my $file (sort @fileList)
{
	next if (($file eq ".") || ($file eq ".."));
	if ($file =~ /\.d$/i)
	{
		ParseDep(\$depContent, "$depDir/$file");
	}
}
exit 0 if($depContent eq "");
open OUTPUTHANDLE, ">$fileOut" or die "Cannot write $fileOut\n";
print OUTPUTHANDLE "$depContent";
close OUTPUTHANDLE;

sub ParseDep
{
	my $refContent = shift @_;
	my $fileInput = shift @_;
	my $Backup = $/;
	undef $/;
	open INPUTHANDLE, "<$fileInput" or die "Cannot open file $fileInput\n";
	my $fileContent = <INPUTHANDLE>;
	close INPUTHANDLE;
	$/ = $Backup;
	$fileContent =~ s/\\\n//gs;
	$fileContent =~ s/\\/\//gs;
	my @fileList = split(/\s+/, $fileContent);
	my $index = 0;
	while (($fileList[$index] =~ /^\s*(\/)?$/) && ($index <= $#fileList))
	{
		$index++;
	}
	if ($index <= $#fileList)
	{
		$fileList[$index] =~ s/(\S*\/)?(\S+?)\.(o|obj)\:/$2.obj\:/i;
		$$refContent .= "#UPDATE#\n";
		$$refContent .= $fileList[$index];
		$index++;
		while ($index <= $#fileList)
		{
			my $line;
			my $file = $fileList[$index];
			if (defined $Hpath{$file}){
				$line = "	" . $Hpath{$file};
			} else {
				$line = "	" . $file;
			}
			#$line = "	" . $fileList[$index];
			$line =~ s/\s*(\S*\/)?(\S+?)\.(o|obj)\:\s*//i;
			if ($line =~ /tools[\\\/]gcc/i)
			{
				++$index;
				next;
			}elsif(defined $header_list{"$line"})
			{
				++$index;
				next;
			}
			$$refContent .= "$line \\\n";
			$header_list{"$line"} = 1;
			$index++;
		}
		while ($$refContent =~ /\s*\\\n$/)
		{
			$$refContent =~ s/\s*\\\n$/\n/;
		}
		$$refContent .= "#ENDUPDATE#\n";
	}
	else
	{
		print "Unexpected file: " . $fileInput . "\n";
	}
}
