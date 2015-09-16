#!/usr/bin/perl
#
# Filename: 
# ---------
#  DataManipulation.pl
#
# Description: 
# ------------
#  Functions for data manipulation.
#
# Auther: 
# -------
#  Shinn Lin
# 
# Note:
# -----
#  none.
#
# Log: 
# -----
#  2007/05/04   Create.
#

#BEGIN { push @INC, 'U:\\00MyPerlLib'}  # add additional library path
package DataManipulation;                           # declare package library
use strict;

#******************************************************************************
# Global Data
#******************************************************************************

#******************************************************************************
# Export Function
#******************************************************************************

return 1; # return true

#******************************************************************************
# FUNCTION
#  clone
# DESCRIPTION
#  clone data from source to destination
# PARAMETERS
#  para 1 - reference to source data
#  para 2 - reference to destination data
# RETURNS
#  none
#******************************************************************************
sub clone()
{
    my $src_ref;
    my $dest_ref;
    
    ($src_ref, $dest_ref) = @_;
    
    # check if types of src and dest are the same
    die "can't clone different type [".ref($src_ref)."][".ref($dest_ref)."]\n" if (ref($src_ref) ne ref($dest_ref));

    # clone reference-to-hash
    if (ref($src_ref) eq "HASH")
    {
        %{$dest_ref} = ();
        while (my ($key, $value) = (each %{$src_ref}))
        {
            if(ref($value) eq "HASH")
            {
                %{${$dest_ref}{$key}} = ();
                clone( $value, \%{${$dest_ref}{$key}});
            }
            elsif (ref($value) eq "ARRAY")
            {
                @{${$dest_ref}{$key}} = ();
                clone( $value, \@{${$dest_ref}{$key}});
            }
            else
            {
                ${$dest_ref}{$key} = $value;
            }
        }
    }
    # clone reference-to-array
    elsif (ref($src_ref) eq "ARRAY")
    {
        @{$dest_ref} = ();
        for (my $i=0; $i<scalar(@{$src_ref}); $i++)
        {
            if(ref(${$src_ref}[$i]) eq "HASH")
            {
                %{${$dest_ref}[$i]} = ();
                clone( ${$src_ref}[$i], \%{${$dest_ref}[$i]});
            }
            elsif (ref(${$src_ref}[$i]) eq "ARRAY")
            {
                @{${$dest_ref}[$i]} = ();
                clone( ${$src_ref}[$i], \@{${$dest_ref}[$i]});
            }
            else
            {
                ${$dest_ref}[$i] = ${$src_ref}[$i];
            }
        }
    }
    else
    {
        $$src_ref = $$dest_ref;
    }
}


sub printObject()
{
    my $src_ref;
    
    ($src_ref) = @_;
    
    # clone reference-to-hash
    if (ref($src_ref) eq "HASH")
    {
        while(my ($key, $value) = (each %{$src_ref}))
        {
            print $src_ref."[".$key."] = ".$value."\n";
            if((ref($value) eq "HASH") || (ref($value) eq "ARRAY"))
            {
                &printObject($value);
            }
        }
    }
    # clone reference-to-array
    elsif(ref($src_ref) eq "ARRAY")
    {
        for (my $i=0; $i<scalar(@{$src_ref}); $i++)
        {
            print $src_ref."[".$i."] = ".${$src_ref}[$i]."\n";
            if((ref(${$src_ref}[$i]) eq "HASH") || (ref(${$src_ref}[$i]) eq "ARRAY"))
            {
                &printObject(${$src_ref}[$i]);
            }
        }
    }
    else
    {
    }
}


#******************************************************************************
# Internal Data
#******************************************************************************


#******************************************************************************
# Program Start
#******************************************************************************



#******************************************************************************
# Internal Function
#******************************************************************************

#******************************************************************************
# FUNCTION
#  xxx
# DESCRIPTION
#  xxx
# PARAMETERS
#  xxx
# RETURNS
#  xxx
#******************************************************************************


#******************************************************************************
# FUNCTION
#  timeCheck
# DESCRIPTION
#  print current time (in sec.) and time-difference to previous check if exists
# PARAMETERS
#  none
# RETURNS
#  current time and time difference if exists (both in sec.)
#******************************************************************************
my $timePrev = 0;
sub timeCheck()
{
    my $prePrintStr;
    my $postPrintStr;   
    my $timeCurr = time();
    my $timeDiff = 0;
    
    ($prePrintStr, $postPrintStr) = @_;
    
    print "$prePrintStr" if ($prePrintStr ne "");
    print "[Time: ".$timeCurr." sec.";
    if ($timePrev > 0) # previous-time exists
    {
        $timeDiff = $timeCurr - $timePrev;
        print "(Diff = $timeDiff)";
    }
    print "]";
    print "$postPrintStr" if ($postPrintStr ne "");
    print "\n\n";
    $timePrev = $timeCurr;
    return $timeDiff;
}
