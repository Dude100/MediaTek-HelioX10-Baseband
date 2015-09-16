#!/usr/bin/perl -w

####################################
#
# Modified by mtk80507 2009/11/17
# Modification: Skip cheking SWITCHABLE_FEATURE related features
# E.g.: Feature 'GEMINI' is set as SWITCHABLE_FEATURE, that means it could be turned ON or OFF by customer
# 			'GEMINI' will be skipped from switchable checking
#				Note that there are some other features which have dependency with 'GEMINI' and SHOULD be changed along with it
#				BUT, such condition is not handled so error will occur
#				while in fact it is actually not 'error'
#       The modification made will bypass such features while 'ckmake'.
#
####################################

use strict;
use Cwd;
&Usage if ($#ARGV < 2);

my $theMF = $ARGV[0];
my $theMFBAK = $ARGV[1];
my $ChkFTsFile = $ARGV[2];

my %NewFTSetTbl = ();
my %OrgFTSetTbl = ();
my @ChkList = ();
my $dir = getcwd;

#******************************************************************************
# Read feature options which need to check
#******************************************************************************
open(CHKFILE, "<$ChkFTsFile") or die "Can NOT open $ChkFTsFile\n";
while(<CHKFILE>)
{
	chomp $_;
	$_ =~ s/\s*//g;
	unshift(@ChkList, uc($_));
}
close(CHKFILE);

#******************************************************************************
# Read Original feature set
#******************************************************************************
my $OrgFTSetTblRef = &ReadFTSet($theMFBAK, \%OrgFTSetTbl);

#******************************************************************************
# Skip check SWITCHABLE_FEATURE related features
#******************************************************************************
my @skipChkLst = &GetSkipChkLst($OrgFTSetTblRef);

#******************************************************************************
# Read New feature set
#******************************************************************************
my $NewFTSetTblRef = &ReadFTSet($theMF, \%NewFTSetTbl);

#******************************************************************************
# Prevent customer from switching options which can NOT be switched
# in any custom release package
#******************************************************************************
&DepChk($OrgFTSetTblRef, $NewFTSetTblRef, @ChkList);

exit 0;


sub ReadFTSet
{
	my ($file, $HashRef) = @_;
	open (FH, "<$file") or die "Can NOT open $file\n";
	while (<FH>)
	{
	  $HashRef->{$1} = uc($2) if (/^(\S+)\s*=\s*(\S+)/);
	}
	close FH;
	return $HashRef;
}

sub DepChk
{
	my ($OrgFTSetTblRef, $NewFTSetTblRef, @ChkList) = @_;
	foreach my $f (@ChkList)
	{
		if (exists $OrgFTSetTblRef->{SWITCHABLE_FEATURE} && 
				$OrgFTSetTblRef->{SWITCHABLE_FEATURE} =~ /^$f$/)
		{
			next;
		}
		if (exists $OrgFTSetTblRef->{SWITCHABLE_FEATURE_2ND} && 
				$OrgFTSetTblRef->{SWITCHABLE_FEATURE_2ND} =~ /^$f$/)
		{
			next;
		}
		
		if (exists $OrgFTSetTblRef->{$f} &&
				grep (/\b$f\b/, @skipChkLst))
		{
			next;
		}

		if (exists $OrgFTSetTblRef->{$f} && 
				exists $NewFTSetTblRef->{$f} && 
				($OrgFTSetTblRef->{$f} !~ /^$NewFTSetTblRef->{$f}$/))
		{
			die "$f can NOT be switched in custom release code base!!!\n";
		}
	}
}

sub Usage {
  print "perl SpecialDepChk.pl <New_MakeFile> <Org_MakeFile> <Check_Feature_List_File>\n";
  exit 1;
}


sub GetSkipChkLst
{
	# get the defined SWITCHABLE_FEATURE and the SWITCHABLE_FEATURE_2ND
	my ($HashRef) = @_;
	my @swtchLst = qw();
	if (exists $HashRef->{SWITCHABLE_FEATURE})
	{
		push (@swtchLst, $HashRef->{SWITCHABLE_FEATURE});
	}
	if (exists $HashRef->{SWITCHABLE_FEATURE_2ND})
	{
		push (@swtchLst, $HashRef->{SWITCHABLE_FEATURE_2ND});		
	}
	
	my @skpLst = qw();
	my $file = "$dir"."\\tools\\special_feature_dep.ini";
	open (FH, "<$file") or warn "Can NOT open $file\n";
	while (<FH>)
	{	
		if (/^#/) # skip parse the comment line which start with '#'
		{
			next; 
		}
		if (/\s?([\S]*)\s?:\s?(.*)/) # match with lines with 'XXX : xxxxx xxxx xxx' pattern 
		{
#			print "\<", $1, "\> depends on ", $2, "\n";
			my @tmpLst = qw();						
			if (grep (/\b$1\b/, @swtchLst))
			{
				@tmpLst = split (/\s+/, $2);
			}

			foreach (@tmpLst)
			{
				push (@skpLst, $_)
			}
		}
	}
	return @skpLst;
}

