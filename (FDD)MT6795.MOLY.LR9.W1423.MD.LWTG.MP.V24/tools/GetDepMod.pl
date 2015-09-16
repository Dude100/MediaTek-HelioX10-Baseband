#!/usr/bin/perl -w
#use strict;
use File::Basename;
use Cwd;

&Usage() if ($#ARGV < 3);

my $DEBUG = 0; # debug for normal info.
my $DEBUG1 = 0; # debug for parsing .dep file
my $InterMode = 0; # turn ON/OFF interaction mode

my $time = 0;
$time = time if($DEBUG);

chomp($CWD = cwd());
$CWD =~ s/\\$// if ($CWD =~ /\\$/);
print "[CWD]: ",$CWD,"\n" if ($DEBUG);

my ($CODEBASE_PATH,$PROJECT_NAME,$FLAVOR,$MODEM_TYPE,@CHANGE_SET) = @ARGV;
my @DEP_MODS = ();

$CODEBASE_PATH = (dirname($CODEBASE_PATH) =~ /:/)? $CODEBASE_PATH : "$CWD/$CODEBASE_PATH";
die "$CODEBASE_PATH does NOT exist, PLEASE check it!!!\n" if (!-d $CODEBASE_PATH);

if ((@CHANGE_SET == 1) && $CHANGE_SET[0] =~ /^\s*@(.*)/)
{
	@CHANGE_SET = ();
	open (FH, "<$1") or die "can NOT open $1!!!\n";
	while(<FH>)
	{
		chomp;
		push (@CHANGE_SET, $_);
	}
	close (FH);
	&Usage() if (!@CHANGE_SET);
}

print "[CHANGE_SET]: @CHANGE_SET\n" if ($DEBUG);

chdir($CODEBASE_PATH);
foreach my $f (@CHANGE_SET)
{
	die "$f does NOT exist, PLEASE check it!!!\n" if (!-e $f);
}

open (MF,"<make/${PROJECT_NAME}_${MODEM_TYPE}(${FLAVOR}).mak") or die "can NOT open make/${PROJECT_NAME}_${MODEM_TYPE}(${FLAVOR}).mak!!!\n";
while(<MF>)
{
	if (/^\s*(\w+)\s*=\s*(\w+)/)
	{
		my $keyname = uc($1);
		$${keyname} = uc($2);
	}
}
close (MF);
my @tmp = &NOTExistDEPMods("build/${PROJECT_NAME}_${MODEM_TYPE}/$FLAVOR/bin/dep", 
                           &GetSRCMods("build/${PROJECT_NAME}_${MODEM_TYPE}/$FLAVOR/bin/log/infomake.log"));

print "[NOTExistDEPMods]: @tmp\n" if ($DEBUG && @tmp);

if (@tmp)
{
	print "\n===========================================================\n";
	print "@tmp";
	print "\n===========================================================\n";
	my $msg = "The above " . ((@tmp == 1)? "module's" : "modules'") . " .dep file NOT exists";

	if ($InterMode)
	{
		my $flag = 1;
		while(1)
		{
			if ($flag)
			{
				print "$msg!!!\n".
				      "WARNING: *** Execute the action \"check_dep/remake_dep/update_dep\" may get the wrong result!!!\n";
				$flag = 0;
		  }
	    print "Do you really want to go ahead? (Y/N): ";
			my $choice = <STDIN>;
			last if ($choice =~ /^\s*(Y|YES)\s*$/i);
			exit 1 if ($choice =~ /^\s*(N|NO)\s*$/i);
		}
	}
	else
	{
		print "$msg!!!\n".
		      "Execute the action \"check_dep/remake_dep/update_dep\" may get the wrong result!!!\n".
		      "PLEASE use action \"scan\" to generate" . ((@tmp == 1)? " its dependency file" : " their dependency files") . "!!!\n";
    exit 1;
	}
}

print "Scanning dependency modules...\n";
@DEP_MODS = &GetDEPMods("build/${PROJECT_NAME}_${MODEM_TYPE}/$FLAVOR/bin/dep", \@CHANGE_SET);
if (@DEP_MODS)
{
	print "===================DEPENDENCY MODULE(S)===================\n";
	print "@DEP_MODS\n";
}
else
{
	print "NOT found dependency modules!!!\n";
}

$time = time - $time if ($DEBUG);
print "Time Comsumption: $time\n" if ($DEBUG);


sub GetDEPMods
{
	my ($deppath, $change_set_ref) = @_;
	my @result = ();
	while(<$deppath/*.dep>)
	{
		my $depfile = $_;
		print $depfile,"\n" if ($DEBUG1);
		my $module = basename($_, '.dep');
		next if ($module eq "codegen" || $module eq "resgen" || $module eq "nvram_auto_gen");
		my $tar = '';
		open(FH, "<$depfile") or die "can NOT open $depfile!!!\n";
		while(<FH>)
		{
			chomp;
			next if (/^\s*#/);
			next if ($_ eq '');
			print $_,"\n"	if ($DEBUG1);
      $_ =~ s/\//\\/g;
#			if (/^\s*((\w+)\.obj:)?\s+(\w+(\\\w+)*\\\w+\.\w+)(\s+\\)?$/)
#			if (/^\s*((.+)\.obj:)?\s+(.+(\\.+)*\\.+\.\w+)(\s+\\)?$/)

			if (/^\s*((\S+)\.(?:obj|o|db):)?\s+(\S+(\\\S+)*\\\S+\.\w+)(\s+\\)?$/)
			{
				# ------------------------------------------------------
				# $2: target, $3: dependency
				# sourcename.obj:	dir1\dir2\...\dirN\headername.(h|hpp)
				# ------------------------------------------------------
				# $3: dependency
				# dir1\dir2\...\dirN\headername.(h|hpp)
				# ------------------------------------------------------
				my $dep = $3;
				$dep =~ s/\//\\/g;
				$dep =~ s/\\/\\\\/g;
				my $dep_head = (/^\s*(\S+)\.(?:obj|o|db):/)? 1:0;
				$tar = $1 if ($dep_head);
				print "[target: dependency] \$tar: $tar\n" if ($DEBUG1 && $dep_head);
				print "[dependency] \$tar: $tar\n" if ($DEBUG1 && !$dep_head);

				foreach my $i (@$change_set_ref)
				{	
					$i =~s/\//\\/g;
					if ($i =~ /$dep/i)
					{
						push (@result, $module) if (!grep(/^$module$/i, @result));
					}
					elsif (basename($i) =~ /^$tar\.(c|cpp|s|arm)\b$/i)
					{
						push (@result, $module) if (!grep(/^$module$/i, @result));
					}
					else
					{
						next;
					}
				}
			}
			elsif ($tar eq '')
			{
				die "Incorrect content in dependency file \"$depfile\"!!!\n";
			}
			else
			{
				print "Match Failed Line:	*** ",$_,"\n" if ($DEBUG1);
				next;
			}
		}
		close(FH);
	}
	return @result;
}

sub GetSRCMods
{
	my $infomakelog = shift;
	my @allSRCMods = ();
	open (INFOMAKELOG, "<$infomakelog") or die "can NOT open $infomakelog!!!\n";
	while(<INFOMAKELOG>)
	{
		chomp;
		if (/^\s*COMPLIST\s*=\s*(.*)\s*/)
		{
			my $COMPLIST = $1;
			@allSRCMods = split(/\s+/,$COMPLIST);
			last;
		}
	}
	close (INFOMAKELOG);
	return \@allSRCMods;
}

sub NOTExistDEPMods
{
	my ($deppath, $arr_ref) = @_;
	my @DEPMods = ();
	foreach my $d (@$arr_ref)
	{
		push (@DEPMods, $d) if (!-e "$deppath/$d.dep");
	}
	return @DEPMods;
}

sub Usage
{
	my $script = basename($0);
  print <<"__EOFUSAGE";

Usage: $script CODEBASE PROJECT_NAME MODEM_TYPE <file1[ file2[ ...]] | \@files>

CODEBASE         Specify the code path
PROJECT_NAME     Specify project name, such as TIANYU28_DEMO etc...
MODEM_TYPE       Specify modem type, such as l1s, basic, gsm, gprs, umts etc...
file1            Specify the changed source/header
\@files           Specify more changed sources/headers via a file (change list)
__EOFUSAGE
  exit 1;
}