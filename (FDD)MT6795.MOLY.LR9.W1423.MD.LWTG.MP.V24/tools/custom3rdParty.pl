#!/usr/bin/perl -w

# According to your environment, please reset these three lines.
$sevenZipPath = "C:\\Progra~1\\7-Zip";   # According to your environment, please reset this lines.
$convertPath = "C:\\Progra~1\\ImageMagick-6.3.6-Q16";   # According to your environment, please reset this lines.
die "7zip folder $sevenZipPath did NOT exist\n" if (!-d $sevenZipPath);
die "convert folder $convertPath did NOT exist\n" if (!-d $convertPath);

$sevenZipFile = "${sevenZipPath}\\7za.exe";
$convertFile = "${convertPath}\\convert.exe";
die "7zip file $sevenZipFile did NOT exist\n" if (!-e $sevenZipFile);
die "convert file $convertFile did NOT exist\n" if (!-e $convertFile);

$MinGWPath = "C:\\MinGW";  # According to your environment, please reset this lines.
die "MinGW folder $MinGWPath did NOT exist\n" if (!-d $MinGWPath);

#********************************************************************
# confirm package
#********************************************************************
my $local_path = `cd`;
chomp $local_path;
my $make_path = $local_path."\\make";

my $package = "";
system ("dir $make_path\\rel_*.mak /b >rel.tmp");

open(F, "rel.tmp") || die "Can not open tmp file!";
while(<F>)
{
	chomp;
	if ($_ =~ /_(OBJ)_/i)
	{
		$package = $1;
		last;
	}
}
close(F);
system ("del /q rel.tmp");

#********************************************************************
# confirm which tool needed in OBJ package 
#********************************************************************
if ($package !~ /OBJ/i)
{
	$MSYSPath = "C:\\MSYS";  # According to your environment, please reset this lines.
	die "MSYS folder $MSYSPath did NOT exist\n" if (!-d $MSYSPath);
	$MSYSPath .= "\\1.0";
	die "MSYS folder $MSYSPath did NOT exist\n" if (!-d $MSYSPath);

	@mapDirs = (
	 [ "${MinGWPath}\\bin", qw(tools\MinGW\bin) ],
	 [ "${MinGWPath}\\lib", qw(tools\MinGW\lib) ],
	 [ "${MinGWPath}\\include", qw(tools\MinGW\include) ],
	 [ "${MSYSPath}\\bin", qw(tools\MSYS\bin) ],
	 [ "${MSYSPath}\\etc", qw(tools\MSYS\etc) ],
	);
}

#********************************************************************
# copy MinGW, MSYS directories
#********************************************************************
for $i (0 .. $#mapDirs) 
{
  die "Folder $mapDirs[$i][0] did NOT exist\n" if (!-d $mapDirs[$i][0]);
  print("Copy folder $mapDirs[$i][0] to $mapDirs[$i][1]\n");
  system("mkdir $mapDirs[$i][1]") if (!-d $mapDirs[$i][1]);
  system("xcopy /Y /Q /S $mapDirs[$i][0] $mapDirs[$i][1]");
}

#********************************************************************
# copy make.exe, 7za.exe, convert.exe
#********************************************************************
$MinGWMake = "${MinGWPath}\\bin\\mingw32-make.exe";
die "MinGW file $MinGWMake did NOT exist\n" if (!-e $MinGWMake);
@mapFiles = (
 [ $MinGWMake, qw(tools make.exe) ],
 [ $sevenZipFile, qw(lcmmi\Customer\ResGenerator 7za.exe) ],
 [ $convertFile, qw(lcmmi\Customer\ResGenerator convert.exe) ],
 [ $sevenZipFile, qw(plutommi\Customer\ResGenerator 7za.exe) ],
 [ $convertFile, qw(plutommi\Customer\ResGenerator convert.exe) ], 
);

for $i (0 .. $#mapFiles) {
  if (-d $mapFiles[$i][1]) {
    print("Copy file $mapFiles[$i][0] to $mapFiles[$i][1]\\$mapFiles[$i][2]\n");
    system("copy /Y $mapFiles[$i][0] $mapFiles[$i][1]\\$mapFiles[$i][2] > nul 2>&1");
  }
}

system ("tools\\chk_env.exe");

exit 0;

