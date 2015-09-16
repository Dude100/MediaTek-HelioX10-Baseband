#!/usr/bin/perl
#
#  Copyright Statement:
#  --------------------
#  This software is protected by Copyright and the information contained
#  herein is confidential. The software may not be copied and the information
#  contained herein may not be used or disclosed except with the written
#  permission of MediaTek Inc. (C) 2011
#
#  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
#  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
#  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
#  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
#  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
#  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
#  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
#  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
#  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
#  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
#  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
#  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
#
#  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
#  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
#  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
#  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
#  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
#
#  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
#  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
#  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
#  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
#  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
#
#*****************************************************************************

use strict;
use warnings;
use Cwd;
use Cwd 'abs_path';
use Data::Dumper;
use File::Path;
use File::Basename;
use File::Compare;
use File::Copy;
use Getopt::Long;

my @_argv = ($0, @ARGV);
my $_argc = $#_argv + 1;

# -----------------------------------------------------------------------------

my $Version = "20110428";

# -----------------------------------------------------------------------------

# Workaround.
my @ExcludedLib = (
    # Function kal_mem_cpy will be placed in SECONDARY_ROM and be used before ready due to multiply definition from kal_release.h.
    'custom.lib',
    # In file variant.cpp, static variables of class type are used, and it results in indeterminate order of initialization.
    'gadget_lib.lib',
    # For customer do vendor release
    'gis.lib',
    'init.lib',
    # Different bin files in MAUI
    'che.lib',
    'bootloader.lib',
    'fota.lib',
    'sst_sec.lib',
    'ssf.lib',
    'lqt.lib',
    # ...
);

# Ignore the following libraries for checking (see checkLib).
my %IgnoredLib = (
    "verno.lib" => 1,
);

# -----------------------------------------------------------------------------

# Set default command.
my $Cmd_nm = "";
my $Cmd_readelf = "";
my $Cmd_strip = "";
my $Cmd_armar = "armar";
my $Cmd_armlink = "armlink";

# -----------------------------------------------------------------------------
# System Utilities

# Set default debug level.
my $DbgLevel = 1;

# Set default info level to display message in the screen.
my $InfoLevel = 0;

# Set current directory.
my $DirCur = cwd();

# Set default temporary directory.
my $DirTemp = $DirCur . "/pl_temp";

# Set default log file.
my $FileLog = $DirCur . "/" . basename(__FILE__) . ".log";
unlink($FileLog);

# Set default err file.
my $FileErr = $DirCur . "/" . basename(__FILE__) . ".err";
unlink($FileErr);

# Set default temporary file.
my $FileTmp = $DirCur . "/" . basename(__FILE__) . ".tmp";
unlink($FileTmp);

my $Current_time = time;

# Write file specified by a global variable $FileLog.
sub sysWriteLog
{
    my ($log) = @_;

    if (open(FILE_LOG, ">>" . $FileLog))
    {
        print(FILE_LOG $log);
        close(FILE_LOG);
    }
}

sub sysWriteErr
{
    my ($log) = @_;

    if (open(FILE_LOG, ">>" . $FileLog))
    {
        print(FILE_LOG $log);
        close(FILE_LOG);
    }
    if (open(FILE_ERR, ">>" . $FileErr))
    {
        print(FILE_ERR $log);
        close(FILE_ERR);
    }
}

BEGIN
{
    my $_dying = 0;
    my $_msg = "";
    my $_ptrSub = 0;
    my @_ptrArgs = ();

    sub sysDieRegister
    {
        my ($ptrSub, @ptrArgs) = @_;

        $_ptrSub = $ptrSub;
        @_ptrArgs = @ptrArgs;
    }

    sub sysDie
    {
        my ($msg) = @_;

        if (($_dying == 0) && $_ptrSub)
        {
            $_dying = 1;
            $_msg = $msg;
            $_ptrSub->(@_ptrArgs);
            $_dying = 0;
        }
        system("date/T >>" . $FileLog);
        system("time/T >>" . $FileLog);
        $msg = $_msg . "\n" . $msg if ($_dying);
        die($msg);
    }
}

# -----------------------------------------------------------------------------
# Basic Utilities

sub utlDump
{
    my ($level, $ptr) = @_;

    if (($level <= $InfoLevel) || ($level <= $DbgLevel))
    {
        my $msg = Dumper($ptr);

        print($msg) if ($level <= $InfoLevel);
        &sysWriteLog($msg) if ($level <= $DbgLevel);
    }
}

sub utlSrcLoc
{
    my ($level) = @_;
    my $filename = (caller($level + 1))[1];
    my $line = (caller($level))[2];
    my $subr = (caller($level + 1))[3];

    $subr =~ s/^.*://;
    return "[" . $filename . ":" . $subr . ":" . $line . "]";
}

sub utlLog
{
    my ($level, $msg) = @_;

    if (($level <= $InfoLevel) || ($level <= $DbgLevel))
    {
        print($msg) if ($level <= $InfoLevel);
        &sysWriteLog(&utlSrcLoc(1) . " " . $msg) if ($level <= $DbgLevel);
    }
}

sub utlErr
{
    my ($level, $msg) = @_;

    if (($level <= $InfoLevel) || ($level <= $DbgLevel))
    {
        print($msg) if ($level <= $InfoLevel);
        &sysWriteErr(&utlSrcLoc(1) . " Error: " . $msg) if ($level <= $DbgLevel);
    }
}

sub utlDie
{
    my ($msg, $level, $ignore) = @_;

    $ignore = 0 if (not defined($ignore));
    $level = 1 if (not defined($level));
    $msg = &utlSrcLoc($level) . " Error: " . $msg . "\n";
    &sysWriteErr($msg);
    &sysDie($msg) unless ($ignore);
}

sub utlExec
{
    my ($cmd) = @_;
    my $ret = "";

    $cmd = $cmd . " 2>" . $FileTmp;
    $ret = `$cmd`;

    if ($? != 0)
    {
        my @stderr = ();

        if (open(FILE_TEMP, $FileTmp))
        {
            @stderr = <FILE_TEMP>;
            close(FILE_TEMP);
        }
        &utlDie("Fail to execute command: \"" . $cmd . "\"\nSTDOUT: " . $ret . "\nSTDERR: @stderr\n", 2);
    }
    return split(/\n/, $ret);
}

sub utlSystem
{
    my ($cmd, $ignore) = @_;
    my $ret = "";
    my $status = 0;

    $ignore = 0 if (not defined($ignore));
    $cmd = $cmd . " 2>" . $FileTmp;
    $ret = `$cmd`;
    $status = $?;

    if ($status != 0)
    {
        my @stderr = ();
        my $msg = "";

        if (open(FILE_TMP, $FileTmp))
        {
            @stderr = <FILE_TMP>;
            close(FILE_TMP);
        }
        if (($ret ne "") || ("@stderr" ne "") || ($ignore <= 0))
        {
            $msg = "Fail to execute command: \"" . $cmd . "\"\nSTDOUT: " . $ret . "\nSTDERR: @stderr\n";
            print($msg) if ($ignore == 0);
            &sysWriteErr(&utlSrcLoc(1) . " Error: " . $msg);
        }
    }
    return $status;
}

# -----------------------------------------------------------------------------
# Utilities

sub utlTrim
{
    my ($str) = @_;

    $str =~ s/^\s+//;
    $str =~ s/\s+$//;

    return $str;
}

sub utlAbsPath
{
    my ($path) = @_;

    return abs_path($path);
}

sub utlRmTree
{
    my ($path, $ignore, $level) = @_;

    if (-e $path)
    {
        my @list = glob($path . "/*");

        $ignore = 1 if (not defined($ignore));
        $level = 2 if (not defined($level));

        foreach my $file (@list)
        {
            if (-d $file)
            {
                &utlRmTree($file, $ignore, $level + 1);
            }
            else
            {
                &utlDie("Fail to delete " . $file . " due to \"$!\"", $level, $ignore) unless (unlink($file));
            }
        }
        &utlDie("Fail to delete " . $path . " due to \"$!\"", $level, $ignore) unless (rmdir($path));
    }
}

sub utlMkDir
{
    my ($dir) = @_;

    if (! -d $dir)
    {
        mkdir($dir) or &utlDie("Fail to create " . $dir . " due to \"$!\"", 2);
    }
}

sub utlChDir
{
    my ($dir) = @_;

    chdir($dir) or &utlDie("Fail to change directory to " . $dir . " due to \"$!\"", 2);
}

sub utlRmFile
{
    my ($file) = @_;

    if (-e $file)
    {
        unlink($file) or &utlDie("Fail to delete " . $file . " due to \"$!\"", 2);
    }
}

sub utlCpFile
{
    my ($src, $dst) = @_;

    copy($src, $dst) or &utlDie("Fail to copy " . $src . " to " . $dst . " due to \"$!\"; please check available disk space", 2);
}

sub utlGetTimestamp
{
    my ($file) = @_;

    return (stat($file))[9];
}

# -----------------------------------------------------------------------------

sub copyFiles
{
    my ($dirSrc, $dirDst) = @_;
    &utlDie("Cannot find " . $dirSrc) unless (-e $dirSrc);
    &utlDie("Cannot find " . $dirDst) unless (-e $dirDst);

    my @fileList = glob($dirSrc . "/*");

    foreach my $src (@fileList)
    {
        &utlCpFile($src, $dirDst) if (-f $src);
    }
}

sub copyLib
{
    my ($ptrAryDir, $srcSuffix, $dstSuffix) = @_;

    foreach my $dirLib (@$ptrAryDir)
    {
        my $dirSrcLib = $dirLib . $srcSuffix;
        my $dirDstLib = $dirLib . $dstSuffix;

        &utlRmTree($dirDstLib);
        &utlMkDir($dirDstLib);
        &copyFiles($dirSrcLib, $dirDstLib);
    }
}

sub generateCppLibFile
{
    my ($ptrHahLib, $fileCppLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};
    my $ptrHahCppLibTab = $ptrHahLib->{ptrHahSymTable}->{ptrHahCppLibTab};

    open(FILE_CPP_LIB, ">" . $fileCppLib) or &utlDie("Cannot open " . $fileCppLib);

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . "/*.lib");

        foreach my $lib (@libList)
        {
            my $libName = basename($lib);

            next if ((not exists($ptrHahLibUsage->{$libName})) || (not exists($ptrHahCppLibTab->{$libName})));
            print(FILE_CPP_LIB $libName . "\n");
        }
    }

    close(FILE_CPP_LIB);
}

sub readCppLibFile
{
    my ($fileCppLib, $ptrHahSymTable) = @_;
    my $ptrHahCppLibTab = {};

    &utlLog(1, "Reading C++ libraries from " . $fileCppLib . "\n");
    open(FILE_CPP_LIB, "<" . $fileCppLib) or &utlDie("Cannot open " . $fileCppLib);

    foreach my $line (<FILE_CPP_LIB>)
    {
        if ($line =~ /(\S+)/)
        {
            $ptrHahCppLibTab->{$1} = 1;
        }
    }

    close(FILE_CPP_LIB);
    $ptrHahSymTable->{ptrHahCppLibTab} = $ptrHahCppLibTab;
}

use constant {
    SYM_DEF   => 1,
    SYM_UNDEF => 2
};

sub addEntrySymToObj
{
    my ($ptrHahSymTable, $sym, $type, $lib, $obj) = @_;
    my $ptrHahSymToObjTab = $ptrHahSymTable->{ptrHahSymToObjTab};

    if (not exists($ptrHahSymToObjTab->{$sym}))
    {
        $ptrHahSymToObjTab->{$sym} = {};
        $ptrHahSymToObjTab->{$sym}->{+SYM_DEF} = {};
        $ptrHahSymToObjTab->{$sym}->{+SYM_UNDEF} = {};
    }

    my $ptrHahLibObj = $ptrHahSymToObjTab->{$sym}->{$type};
    my $ptrHahMultiSymTab = $ptrHahSymTable->{ptrHahMultiSymTab};

    if ($ptrHahMultiSymTab && ($type == SYM_DEF) && (scalar keys(%$ptrHahLibObj) > 0))
    {
        &utlLog(3, "Multiply defined symbol " . $sym . " in " . $lib . "(" . $obj . ")\n");
        $ptrHahMultiSymTab->{$sym} = 1;
    }

    $ptrHahLibObj->{$lib} = {} if (not exists($ptrHahLibObj->{$lib}));
    $ptrHahLibObj->{$lib}->{$obj} = 1;
}

sub loadSymTableByNm
{
    my ($ptrHahSymTable, $lib, $libName, $type) = @_;
    my $ptrHahObjToSymTab = $ptrHahSymTable->{ptrHahObjToSymTab};
    my $ptrHahCppLibTab = $ptrHahSymTable->{ptrHahCppLibTab};
    my $obj = "";
    my @symTable = ();

    &utlDie("Assert") if (($type != SYM_DEF) && ($type != SYM_UNDEF));
    if ($type == SYM_DEF)
    {
        @symTable = &utlExec($Cmd_nm . " -g --defined-only " . $lib);
    }
    else
    {
        @symTable = &utlExec($Cmd_nm . " -g -u " . $lib);
    }

    foreach my $line (@symTable)
    {
        if ($line =~ /^(\S+):\s*$/)
        {
            $obj = $1;
            $ptrHahObjToSymTab->{$libName} = {} if (not exists($ptrHahObjToSymTab->{$libName}));
            if (not exists($ptrHahObjToSymTab->{$libName}->{$obj}))
            {
                $ptrHahObjToSymTab->{$libName}->{$obj} = {};
                $ptrHahObjToSymTab->{$libName}->{$obj}->{+SYM_DEF} = {};
                $ptrHahObjToSymTab->{$libName}->{$obj}->{+SYM_UNDEF} = {};
            }
        }
        elsif ($line =~ /\s+[^N]\s+(\S+)\s*$/)
        {
            my $sym = $1;
            &utlDie("Assert") if ($obj eq "");
            &utlLog(3, "Reading " . $sym . " from " . $libName . "(" . $obj . ")\n");
            $ptrHahObjToSymTab->{$libName}->{$obj}->{$type}->{$sym} = 1;
            &addEntrySymToObj($ptrHahSymTable, $sym, $type, $libName, $obj);
            $ptrHahCppLibTab->{$libName} = 1 if (($type == SYM_DEF) && ($sym =~ /^_Z/));
        }
    }
}

sub loadSymTable
{
    my ($ptrHahLib, $fileCppLib) = @_;
    my $ptrHahSymTable = $ptrHahLib->{ptrHahSymTable};

    if (not exists($ptrHahSymTable->{ptrHahObjToSymTab}))
    {
        my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
        my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};

        &utlLog(1, "Loading symbol tables...\n");

        $ptrHahSymTable->{ptrHahObjToSymTab} = {};
        $ptrHahSymTable->{ptrHahSymToObjTab} = {};
        $ptrHahSymTable->{ptrHahCppLibTab} = {};
        $ptrHahSymTable->{ptrHahMultiSymTab} = {};

        foreach my $dirSrcLib (@$ptrAryLibDir)
        {
            my @libList = glob($dirSrcLib . "/*.lib");

            foreach my $lib (@libList)
            {
                my $libName = basename($lib);

                next if (not exists($ptrHahLibUsage->{$libName}));

                &utlLog(1, "Loading " . $libName . "\n");
                &loadSymTableByNm($ptrHahSymTable, $lib, $libName, SYM_DEF);
                &loadSymTableByNm($ptrHahSymTable, $lib, $libName, SYM_UNDEF);
            }
        }
        &utlLog(3, "Dumping object to symbol table...\n");
        &utlDump(3, $ptrHahSymTable->{ptrHahObjToSymTab});
        &utlLog(3, "Dumping symbol to object table...\n");
        &utlDump(3, $ptrHahSymTable->{ptrHahSymToObjTab});

        &generateCppLibFile($ptrHahLib, $fileCppLib);
    }
}

sub generateDbgLibFile
{
    my ($ptrHahLib, $suffix, $ptrHahNoDbgLib, $fileDbgLib, $stripDebugCount) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};
    my $ptrHahCppLibTab = $ptrHahLib->{ptrHahSymTable}->{ptrHahCppLibTab};
    my $size = keys(%$ptrHahNoDbgLib);
    my $count = 0;
    my %libList = ();

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @list = glob($dirSrcLib . $suffix . "/*.lib");

        foreach my $lib (@list)
        {
            my $libName = basename($lib);

            $libList{$libName} = -s $lib;
        }
    }

    open(FILE_DBG_LIB, ">" . $fileDbgLib) or &utlDie("Cannot open " . $fileDbgLib);

    print(FILE_DBG_LIB "PLEASE ADD \";\" IN THE BEGINNING OF THE LINE IN ORDER TO REMOVE DEBUG INFO. OF A CORRESPONDING LIBRARY\n\n");

    foreach my $libName (sort { $libList{$b} <=> $libList{$a} } (keys(%libList)))
    {
        if (not exists($ptrHahLibUsage->{$libName}))
        {
            &utlLog(1, "NOT stripping " . $libName . " due to no use\n");
            next;
        }
        if (exists($ptrHahCppLibTab->{$libName}))
        {
            &utlLog(1, "NOT stripping " . $libName . " due to C++\n");
            next;
        }
        if (($size == 0) && ($count < $stripDebugCount))
        {
            $ptrHahNoDbgLib->{$libName} = 1;
            $count++;
        }
        if (exists($ptrHahNoDbgLib->{$libName}))
        {
            print(FILE_DBG_LIB "; " . $libName . " " . $libList{$libName} . "\n");
        }
        else
        {
            print(FILE_DBG_LIB $libName . " " . $libList{$libName} . "\n");
        }
    }

    close(FILE_DBG_LIB);
}

sub readDbgLibFile
{
    my ($fileDbgLib, $ptrHahNoDbgLib) = @_;

    &utlLog(1, "Reading debug-needed libraries from " . $fileDbgLib . "\n");

    open(FILE_DBG_LIB, "<" . $fileDbgLib) or &utlDie("Cannot open " . $fileDbgLib);

    foreach my $line (<FILE_DBG_LIB>)
    {
        if ($line =~ /^\s*;\s*(\S+)/)
        {
            $ptrHahNoDbgLib->{$1} = 1;
        }
    }

    close(FILE_DBG_LIB);
}

sub removeDebugInfoGut
{
    my ($ptrHahLib, $suffix) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};
    my $ptrHahNoDbgLib = $ptrHahLib->{ptrHahNoDbgLib};
    my $ptrHahCppLibTab = $ptrHahLib->{ptrHahSymTable}->{ptrHahCppLibTab};
    my $fileOpt = "__ARM_OPT__.txt";
    my $cwd = cwd();

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . $suffix . "/*.lib");

        foreach my $lib (@libList)
        {
            my $libName = basename($lib);

            if (exists($ptrHahLibUsage->{$libName}) && (not exists($ptrHahCppLibTab->{$libName})) && (exists($ptrHahNoDbgLib->{$libName})))
            {
                &utlLog(1, "Removing debug info of " . $libName . "\n");
                &utlMkDir($DirTemp);
                &utlChDir($DirTemp);

                my @objList = &utlExec($Cmd_armar . " -t " . $lib);

                if (&utlSystem($Cmd_armar . " -x " . $lib) == 0)
                {
                    my $done = 1;

                    foreach my $obj (@objList)
                    {
                        if (&utlSystem($Cmd_strip . " -d " . $obj) != 0)
                        {
                            $done = 0;
                            last;
                        }
                    }
                    if ($done)
                    {
                        open(FILE_OPT, ">" . $fileOpt) or &utlDie("Cannot open " . $fileOpt);
                        print(FILE_OPT "--create " . $lib . " @objList");
                        close(FILE_OPT);
                        &utlSystem($Cmd_armar . " --via " . $fileOpt);
                    }
                }

                &utlChDir($cwd);
                &utlRmTree($DirTemp);
            }
        }
    }
}

sub removeDebugInfo
{
    my ($ptrHahLib, $suffix, $fileCppLib, $fileDbgLib, $stripDebugCount) = @_;
    my $update = scalar keys(%{$ptrHahLib->{ptrHahLibNew}});

    if ((-e $fileCppLib) && ($update == 0))
    {
        &readCppLibFile($fileCppLib, $ptrHahLib->{ptrHahSymTable});
    }
    else
    {
        &loadSymTable($ptrHahLib, $fileCppLib);
    }
    &readDbgLibFile($fileDbgLib, $ptrHahLib->{ptrHahNoDbgLib}) if (-e $fileDbgLib);
    &generateDbgLibFile($ptrHahLib, $suffix, $ptrHahLib->{ptrHahNoDbgLib}, $fileDbgLib, $stripDebugCount);
    &removeDebugInfoGut($ptrHahLib, $suffix);
}

sub createDstLibDir
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $suffix = $ptrHahLib->{suffix};

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my $dirDstLib = $dirSrcLib . $suffix;

        &utlLog(1, "Creating " . $dirDstLib ."\n");
        &utlRmTree($dirDstLib);
        &utlMkDir($dirDstLib);
    }
}

sub removeDstLibDir
{
    my ($ptrHahLib, $suffix, $dstSuffix) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my $dirDstLib = $dirSrcLib . $suffix;

        if (-e $dirDstLib)
        {
            if ((not defined($dstSuffix)) || ($dstSuffix eq ""))
            {
                &utlRmTree($dirDstLib);
            }
            else
            {
                my $path = $dirSrcLib . $dstSuffix;

                &utlLog(1, "Removing " . $path . "\n");
                &utlRmTree($path);
                &utlLog(1, "Keeping partially-linked libraries in " . $path . "\n");
                if (not rename($dirDstLib, $path))
                {
                    &utlLog(1, "Fail to rename directory " . $dirDstLib . " to " . $path . " due to \"$!\"\n");
                    &utlLog(1, "Trying to copy files from " . $dirDstLib . " to " . $path . "\n");
                    &utlMkDir($path);
                    &copyFiles($dirDstLib, $path);
                    &utlRmTree($dirDstLib);
                }
            }
        }
    }
}

sub finalizeLib
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $suffix = $ptrHahLib->{suffix};
    my $suffix_bak = $ptrHahLib->{suffix_bak};

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my $dirDstLib = $dirSrcLib . $suffix;
        my $dirSrcBak = $dirSrcLib . $suffix_bak;

        &utlDie("Cannot find " . $dirDstLib) unless (-e $dirDstLib);
        &utlDie("Unexpected directory " . $dirSrcBak) if (-e $dirSrcBak);
        &utlMkDir($dirSrcBak);
        &copyFiles($dirSrcLib, $dirSrcBak);
        &copyFiles($dirDstLib, $dirSrcLib);
        &utlRmTree($dirSrcBak);
        &utlRmTree($dirDstLib);
    }
}

# -----------------------------------------------------------------------------

sub isPattern
{
    my ($str) = @_;

    return 1 if (($str ne "*") && ($str =~ /[*?]+/));
    return 0;
}

sub regExp
{
    my ($expr) = @_;

    $expr =~ s/\./\\./g;
    $expr =~ s/\*/.*/g;
    $expr =~ s/\?/./g;

    return $expr;
}

sub hasRule
{
    my ($ptrHahRuleGut, $lib, $obj) = @_;

    $lib = lc($lib);
    $obj = lc($obj);
    $lib = &regExp($lib) if (&isPattern($lib));
    $obj = &regExp($obj) if (&isPattern($obj));
    return 1 if (exists($ptrHahRuleGut->{$lib}) && exists($ptrHahRuleGut->{$lib}->{$obj}));
    return 0;
}

sub loadRule
{
    my ($ptrHahRuleGut, $lib, $obj) = @_;

    $lib = lc($lib);
    $obj = lc($obj);
    if (&isPattern($lib))
    {
        $ptrHahRuleGut->{regExpLib} = {} if (not exists($ptrHahRuleGut->{regExpLib}));
        $lib = &regExp($lib);
        $ptrHahRuleGut->{regExpLib}->{$lib} = 1;
    }
    $ptrHahRuleGut->{$lib} = {} if (not exists($ptrHahRuleGut->{$lib}));
    if (&isPattern($obj))
    {
        $ptrHahRuleGut->{$lib}->{regExpObj} = {} if (not exists($ptrHahRuleGut->{$lib}->{regExpObj}));
        $obj = &regExp($obj);
        $ptrHahRuleGut->{$lib}->{regExpObj}->{$obj} = 1;
    }
    $ptrHahRuleGut->{$lib}->{$obj} = 1;
}

sub writeRule
{
    my ($hdlFileRule, $lib, $obj) = @_;

    printf($hdlFileRule "%s(%s)\n", $lib, $obj) if ($hdlFileRule);
}

sub addRule
{
    my ($ptrHahRuleGut, $lib, $obj, $hdlFileRule) = @_;

    if (not &hasRule($ptrHahRuleGut, $lib, $obj))
    {
        &loadRule($ptrHahRuleGut, $lib, $obj);
        &writeRule($hdlFileRule, $lib, $obj);
    }
}

# Return 1 if a library is specified in RULE to exclude; otherwise, return 0.
sub isExcludedLib
{
    my ($ptrHahRuleGut, $lib) = @_;

    $lib = lc($lib);
    return 1 if (   (   exists($ptrHahRuleGut->{$lib})
                     && exists($ptrHahRuleGut->{$lib}->{"*"}))
                 || (   exists($ptrHahRuleGut->{"*"})
                     && exists($ptrHahRuleGut->{"*"}->{"*"})));

    foreach my $regExpLib (keys(%{$ptrHahRuleGut->{regExpLib}}))
    {
        if (($lib =~ /($regExpLib)/) && exists($ptrHahRuleGut->{$regExpLib}->{"*"}))
        {
            &loadRule($ptrHahRuleGut, $lib, "*");
            return 1;
        }
    }
    return 0;
}

# Return 1 if an object is specified in RULE to exclude; otherwise, return 0.
sub isExcludedObj
{
    my ($ptrHahRuleGut, $lib, $obj) = @_;

    $lib = lc($lib);
    $obj = lc($obj);
    return 1 if (   (   exists($ptrHahRuleGut->{$lib})
                     && (   exists($ptrHahRuleGut->{$lib}->{$obj})
                         || exists($ptrHahRuleGut->{$lib}->{"*"})))
                 || (   exists($ptrHahRuleGut->{"*"})
                     && exists($ptrHahRuleGut->{"*"}->{$obj}))
                 || (   exists($ptrHahRuleGut->{"*"})
                     && exists($ptrHahRuleGut->{"*"}->{"*"})));

    if (   exists($ptrHahRuleGut->{"*"})
 && exists($ptrHahRuleGut->{"*"}->{regExpObj}))
    {
        foreach my $regExpObj (keys(%{$ptrHahRuleGut->{"*"}->{regExpObj}}))
        {
            if ($obj =~ /($regExpObj)/)
            {
                &loadRule($ptrHahRuleGut, $lib, $obj);
                return 1;
            }
        }
    }

    foreach my $regExpLib (keys(%{$ptrHahRuleGut->{regExpLib}}))
    {
        if ($lib =~ /($regExpLib)/)
        {
            if (exists($ptrHahRuleGut->{$regExpLib}->{$obj}))
            {
                &loadRule($ptrHahRuleGut, $lib, $obj);
                return 1;
            }
            elsif (exists($ptrHahRuleGut->{$regExpLib}->{"*"}))
            {
                &loadRule($ptrHahRuleGut, $lib, "*");
                return 1;
            }
            elsif (exists($ptrHahRuleGut->{$regExpLib}->{regExpObj}))
            {
                foreach my $regExpObj (keys(%{$ptrHahRuleGut->{$regExpLib}->{regExpObj}}))
                {
                    if ($obj =~ /($regExpObj)/)
                    {
                        &loadRule($ptrHahRuleGut, $lib, $obj);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

sub readRuleFile
{
    my ($ptrHahRule) = @_;
    my $fileRule = $ptrHahRule->{fileRule};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    &utlLog(1, "Reading rule from " . $fileRule . "\n");

    open(FILE_RULE, "<" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    foreach my $line (<FILE_RULE>)
    {
        # library(object)
        if ($line =~ /^\s*([^\(\)\s]+)\s*\(\s*([^\(\)\s]+)\s*\)/)
        {
            my $lib = $1;
            my $obj = $2;

            &utlDie("Invalid rule: " . $line) if (($lib eq "*") && ($obj eq "*"));
            &loadRule($ptrHahRuleGut, $lib, $obj) if (not &hasRule($ptrHahRuleGut, $lib, $obj));
        }
    }

    close(FILE_RULE);

    &utlCpFile($fileRule, $ptrHahRule->{file});
}

sub parseScatterFile
{
    my ($fileScatter, $ptrHahRule) = @_;
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    &utlLog(1, "Parsing scatter file " . $fileScatter . " and outputting rules to " . $fileRule . "\n");

    open(FILE_RULE, ">" . $fileRule) or &utlDie("Cannot open " . $fileRule);
    open(FILE_SCATTER, "<" . $fileScatter) or &utlDie("Cannot open " . $fileScatter);

    foreach my $line (<FILE_SCATTER>)
    {
        if ($line =~ /^\s*(\S+\.o\S*)/i)
        {
            my $obj = $1;

            next if ($obj =~ /^\*\.o/i);
            &addRule($ptrHahRuleGut, "*", $obj, \*FILE_RULE);
        }
    }

    close(FILE_SCATTER);
    close(FILE_RULE);
}

sub generateFileNameList
{
    my ($file, $ptrAryFileName) = @_;

    open(FILE_INPUT, "<" . $file) or &utlDie("Cannot open " . $file);

    foreach my $line (<FILE_INPUT>)
    {
        my @optList = split(/\s+/, $line);

        foreach my $opt (@optList)
        {
            push(@$ptrAryFileName, basename($1) . ".lib") if ($opt =~ /(\S+)\.lib(\(\S+\)|$)/);
        }
    }

    close(FILE_INPUT);
}

sub readUserExclusionFile
{
    my ($ptrAryUserExclusionFile, $ptrHahRule) = @_;
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    foreach my $file (@$ptrAryUserExclusionFile)
    {
        my @nameList = ();

        &utlLog(1, "Reading user exclusion from " . $file . "\n");

        &generateFileNameList($file, \@nameList);
        foreach my $lib (@nameList)
        {
            &utlLog(1, "Will exclude " . $lib . "\n");
            &addRule($ptrHahRuleGut, $lib, "*", \*FILE_RULE);
        }
    }

    close(FILE_RULE);
}

sub readExclusionFile
{
    my ($fileExclusion, $ptrHahRule) = @_;
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    &utlLog(1, "Reading exclusion from " . $fileExclusion . "\n");

    open(FILE_EXCLUSION, "<" . $fileExclusion) or &utlDie("Cannot open " . $fileExclusion);
    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    foreach my $line (<FILE_EXCLUSION>)
    {
        # library object
        if ($line =~ /^\s*(\S+)\s+(\S+)/)
        {
            my $lib = $1;
            my $obj = $2;

            &utlLog(1, "Will exclude " . $lib . "(" . $obj . ")\n");
            &addRule($ptrHahRuleGut, $lib, $obj, \*FILE_RULE);
        }
    }

    close(FILE_RULE);
    close(FILE_EXCLUSION);
}

sub writeExcludedLib
{
    my ($ptrAryExcludedLib, $ptrHahRule) = @_;
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    &utlLog(1, "Writing built-in excluded libraries to " . $fileRule . "\n");

    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    foreach my $lib (@$ptrAryExcludedLib)
    {
        &utlLog(1, "Will exclude " . $lib . "\n");
        &addRule($ptrHahRuleGut, $lib, "*", \*FILE_RULE);
    }

    close(FILE_RULE);
}

sub writeHint
{
    my ($hdlFileHint, $lib, $obj, $sym) = @_;

    printf($hdlFileHint "%s %s %s\n", $lib, $sym, $obj) if ($hdlFileHint);
}

sub loadHint
{
    my ($ptrHahHintGut, $lib, $obj, $sym) = @_;

    $ptrHahHintGut->{$sym} = {} if (not exists($ptrHahHintGut->{$sym}));
    $ptrHahHintGut->{$sym}->{$obj} = {} if (not exists($ptrHahHintGut->{$sym}->{$obj}));
    $ptrHahHintGut->{$sym}->{$obj}->{$lib} = 1;
}

sub addHint
{
    my ($ptrHahHintGut, $lib, $obj, $sym, $hdlFileHint) = @_;

    if (   (not exists($ptrHahHintGut->{$sym}))
        || (not exists($ptrHahHintGut->{$sym}->{$obj}))
        || (not exists($ptrHahHintGut->{$sym}->{$obj}->{$lib})))
    {
        &loadHint($ptrHahHintGut, $lib, $obj, $sym);
        &writeHint($hdlFileHint, $lib, $obj, $sym);
    }
}

sub readHintFile
{
    my ($ptrHahHint, $ptrHahRule) = @_;
    my $fileHint = $ptrHahHint->{fileHint};
    my $ptrHahHintGut = $ptrHahHint->{ptrHahGut};
    my $toRule = $ptrHahHint->{toRule};
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};

    &utlLog(1, "Reading hint from " . $fileHint . "\n");

    open(FILE_HINT, "<" . $fileHint) or &utlDie("Cannot open " . $fileHint);
    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    foreach my $line (<FILE_HINT>)
    {
        # library symbol object
        if ($line =~ /^\s*(\S+)\s+(\S+)\s+(\S+)/)
        {
            my $lib = $1;
            my $sym = $2;
            my $obj = $3;

            &loadHint($ptrHahHintGut, $lib, $obj, $sym);
            &addRule($ptrHahRuleGut, $lib, $obj, \*FILE_RULE) if ($toRule);
        }
    }

    close(FILE_RULE);
    close(FILE_HINT);

    &utlCpFile($fileHint, $ptrHahHint->{file});
}

sub generateLinkOptFile
{
    my ($ptrHahLib, $ptrHahRuleGut, $fileLinkOpt, $fileOutput) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $fileOrig = $fileOutput . ".orig";
    my %libPath = ();

    &utlCpFile($fileLinkOpt, $fileOrig);

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . "/*.lib");

        foreach my $lib (@libList)
        {
            my $libName = basename($lib);

            if (exists($libPath{$libName}))
            {
                $libPath{$libName} = "";
            }
            else
            {
                $libPath{$libName} = $dirSrcLib;
            }
        }
    }

    my $suffix = $ptrHahLib->{suffix};
    my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};

    &utlLog(1, "Generating link option file " . $fileOutput . "\n");

    open(FILE_LINK_OPT, "<" . $fileLinkOpt) or &utlDie("Cannot open " . $fileLinkOpt);
    open(FILE_OUTPUT, ">" . $fileOutput) or &utlDie("Cannot open " . $fileOutput);

    foreach my $line (<FILE_LINK_OPT>)
    {
        my @optList = split(/\s+/, $line);

        foreach my $opt (@optList)
        {
            my $found = 0;

            if ($opt =~ /\.lib$/)
            {
                my $libName = basename($opt);

                if (exists($libPath{$libName}) && ($libPath{$libName} ne ""))
                {
                    if (($ptrHahRuleGut == 0) || (not &isExcludedLib($ptrHahRuleGut, $libName)))
                    {
                        my $lib = $libPath{$libName}. $suffix . "/" . $libName;

                        $lib =~ s/\//\\/g;
                        print(FILE_OUTPUT " " . $lib);
                        $found = 1;
                    }
                    $ptrHahLibUsage->{$libName} = 1;
                }
            }
            print(FILE_OUTPUT " " . $opt) unless ($found);
        }
        print(FILE_OUTPUT "\n");
    }

    close(FILE_OUTPUT);
    close(FILE_LINK_OPT);

    foreach my $libName (keys(%libPath))
    {
        &utlLog(1, "NOT using " . $libName . " in link option file " . $fileLinkOpt . "\n") if (not exists($ptrHahLibUsage->{$libName}));
    }
}

# -----------------------------------------------------------------------------

sub partialLinkLibGut
{
    my ($lib, $libName, $dirDstLib, $ptrHahLib, $ptrHahRuleGut, $hdlFileRule, $ptrHahHintGut, $hdlFileHint) = @_;
    my @objList = &utlExec($Cmd_armar . " -t " . $lib);
    my $linkedObj = "__" . $libName . "_linked__.obj";

    &utlLog(3, "Analyzing " . $lib . " with @objList\n");

    if (grep {$_ eq $linkedObj} @objList)
    {
        &utlLog(1, "Excluding " . $libName . " due to a linked object inside\n");
        &utlCpFile($lib, $dirDstLib . "/" . $libName);
    }
    elsif (&isExcludedLib($ptrHahRuleGut, $libName))
    {
        my $dstLib = $dirDstLib . "/" . $libName;

        &utlLog(1, "Excluding " . $libName . "\n");
        &utlCpFile($lib, $dstLib);
    }
    else
    {
        my $ptrAryPLObj = [];
        my $ptrAryNonPLObj = [];

        # Find out objects which can be partially linked according to rule.
        foreach my $obj (@objList)
        {
            if (&isExcludedObj($ptrHahRuleGut, $libName, $obj))
            {
                push(@$ptrAryNonPLObj, $obj);
            }
            else
            {
                push(@$ptrAryPLObj, $obj);
            }
        }
        if ($#$ptrAryPLObj < 1)
        {
            &utlLog(1, "Excluding " . $libName . " due to one object for partial link\n");
            &addRule($ptrHahRuleGut, $libName, "*", $hdlFileRule);
            &addHint($ptrHahHintGut, $libName, "*", "*", $hdlFileHint);
            &utlCpFile($lib, $dirDstLib . "/" . $libName);
        }
        else
        {
            my $fileOpt = "__ARM_OPT__.txt";
            my $cwd = cwd();
            my $err = 1;
            my $cmd = "";

            &utlRmTree($DirTemp);
            &utlMkDir($DirTemp);
            &utlChDir($DirTemp);

            $cmd = $Cmd_armar . " -x " . $lib;
            if (&utlSystem($cmd, -1) == 0)
            {
                # Partially link objects.
                &utlDie("Assert: need at least 2 objects for partial link") unless ($#$ptrAryPLObj > 0);
                $cmd = "@$ptrAryPLObj --partial --elf -o " . $linkedObj;
                open(FILE_OPT, ">" . $fileOpt) or &utlDie("Cannot open " . $fileOpt);
                print(FILE_OPT $cmd);
                close(FILE_OPT);
                &utlLog(1, $Cmd_armlink . " " . $cmd . "\n");
                $cmd = $Cmd_armlink . " --via " . $fileOpt . " >>" . $FileLog . " 2>&1";
                if (&utlSystem($cmd, -1) == 0)
                {
                    push(@$ptrAryNonPLObj, $linkedObj);

                    # Archive objects to create a library.
                    &utlLog(1, "Creating " . $libName . "\n");
                    &utlLog(2, "Creating " . $libName . " with @$ptrAryNonPLObj\n");
                    open(FILE_OPT, ">" . $fileOpt) or &utlDie("Cannot open " . $fileOpt);
                    printf(FILE_OPT "--create %s/%s @$ptrAryNonPLObj", $dirDstLib, $libName);
                    close(FILE_OPT);
                    $cmd = $Cmd_armar . " --via " . $fileOpt . " >>" . $FileLog . " 2>&1";
                    $err = 0 if (&utlSystem($cmd, -1) == 0);
                }
            }
            if ($err)
            {
                if ((-e $fileOpt) && open(FILE_OPT, $fileOpt))
                {
                    my @temp = <FILE_OPT>;

                    close(FILE_OPT);
                    &utlErr(1, "Dumping " . $fileOpt . ": @temp\n");
                }
                &utlLog(1, "Excluding " . $libName . " due to failure to execute \"" . $cmd . "\"\n");
                &utlCpFile($lib, $dirDstLib . "/" . $libName);
            }

            &utlChDir($cwd);
            &utlRmTree($DirTemp);
        }
    }
}

sub partialLinkLib
{
    my ($ptrHahLib, $ptrHahRule, $ptrHahHint, $ptrHahLibErr) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $suffix = $ptrHahLib->{suffix};
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};
    my $fileHint = $ptrHahHint->{file};
    my $ptrHahHintGut = $ptrHahHint->{ptrHahGut};

    &utlLog(1, "Partially linking objects in the same libraries...\n");
    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);
    open(FILE_HINT, ">>" . $fileHint) or &utlDie("Cannot open " . $fileHint);

    if ($ptrHahLibErr && (scalar keys(%$ptrHahLibErr) > 0))
    {
        foreach my $libName (keys(%$ptrHahLibErr))
        {
            foreach my $dirSrcLib (@$ptrAryLibDir)
            {
                my $lib = $dirSrcLib . "/" . $libName;

                if (-e $lib)
                {
                    my $dirDstLib = $dirSrcLib . $suffix;

                    &utlDie("Cannot find " . $dirSrcLib) unless (-e $dirSrcLib);
                    &utlDie("Cannot find " . $dirDstLib) unless (-e $dirDstLib);
                    &partialLinkLibGut($lib, $libName, $dirDstLib, $ptrHahLib, $ptrHahRuleGut, \*FILE_RULE, $ptrHahHintGut, \*FILE_HINT);
                }
            }
        }
    }
    else
    {
        my $ptrHahLibUsage = $ptrHahLib->{ptrHahLibUsage};

        foreach my $dirSrcLib (@$ptrAryLibDir)
        {
            my @libList = glob($dirSrcLib . "/*.lib");
            my $dirDstLib = $dirSrcLib . $suffix;

            &utlDie("Cannot find directory " . $dirDstLib) unless (-e $dirDstLib);

            foreach my $lib (@libList)
            {
                my $libName = basename($lib);

                if (not exists($ptrHahLibUsage->{$libName}))
                {
                    my $dstLib = $dirDstLib . "/" . $libName;

                    &utlLog(1, "Excluding " . $libName . " due to no use in the link option file\n");
                    &utlCpFile($lib, $dstLib);
                }
                else
                {
                    &partialLinkLibGut($lib, $libName, $dirDstLib, $ptrHahLib, $ptrHahRuleGut, \*FILE_RULE, $ptrHahHintGut, \*FILE_HINT);
                }
            }
        }
    }

    close(FILE_HINT);
    close(FILE_RULE);
}

use constant {
    LINK_NONE       =>  2,
    LINK_OK_STRIP   =>  1,
    LINK_OK         =>  0,
    LINK_OUT_OF_MEM => -1,
    LINK_UNKNOWN    => -2,
    LINK_FAIL       => -3,
};

# Parse an error file from final link.
sub parseErrorFile
{
    my ($ptrHahError) = @_;
    my $fileError = $ptrHahError->{file};
    my $ret = LINK_OK;

    $ptrHahError->{ptrHahObjSymErr} = {};
    $ptrHahError->{ptrHahLibSymErr} = {};
    $ptrHahError->{ptrHahLibObjRef} = {};
    $ptrHahError->{ptrHahLibErr} = {};

    &utlLog(1, "Parsing linking error from " . $fileError . "\n");
    open(FILE_ERROR, "<" . $fileError) or &utlDie("Cannot open " . $fileError);

    my $ptrHahObjSymErr = $ptrHahError->{ptrHahObjSymErr};
    my $ptrHahLibSymErr = $ptrHahError->{ptrHahLibSymErr};

    foreach my $line (<FILE_ERROR>)
    {
        if ($line =~ /^Error: L6218E: Undefined symbol (\S+) \(referred from __(\S+)_linked__.obj\)/)
        {
            $ptrHahLibSymErr->{$2} = {} if (not exists($ptrHahLibSymErr->{$2}));
            $ptrHahLibSymErr->{$2}->{$1} = SYM_UNDEF if (not exists($ptrHahLibSymErr->{$2}->{$1}));
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Error: L6218E: Undefined symbol (\S+) \(referred from (\S+)\)/)
        {
            $ptrHahObjSymErr->{$2} = {} if (not exists($ptrHahObjSymErr->{$2}));
            $ptrHahObjSymErr->{$2}->{$1} = SYM_UNDEF if (not exists($ptrHahObjSymErr->{$2}->{$1}));
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Error: L6200E: Symbol (\S+) multiply defined \(by __(\S+)_linked__.obj and __(\S+)_linked__.obj\)/)
        {
            $ptrHahLibSymErr->{$2} = {} if (not exists($ptrHahLibSymErr->{$2}));
            $ptrHahLibSymErr->{$2}->{$1} = SYM_DEF if (not exists($ptrHahLibSymErr->{$2}->{$1}));
            if ($2 ne $3)
            {
                $ptrHahLibSymErr->{$3} = {} if (not exists($ptrHahLibSymErr->{$3}));
                $ptrHahLibSymErr->{$3}->{$1} = SYM_DEF if (not exists($ptrHahLibSymErr->{$3}->{$1}));
            }
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Error: L6200E: Symbol (\S+) multiply defined \(by __(\S+)_linked__.obj and (\S+)\)/)
        {
            $ptrHahLibSymErr->{$2} = {} if (not exists($ptrHahLibSymErr->{$2}));
            $ptrHahLibSymErr->{$2}->{$1} = SYM_DEF if (not exists($ptrHahLibSymErr->{$2}->{$1}));
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Error: L6200E: Symbol (\S+) multiply defined \(by (\S+) and __(\S+)_linked__.obj\)/)
        {
            $ptrHahLibSymErr->{$3} = {} if (not exists($ptrHahLibSymErr->{$3}));
            $ptrHahLibSymErr->{$3}->{$1} = SYM_DEF if (not exists($ptrHahLibSymErr->{$3}->{$1}));
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Error: L6200E: Symbol (\S+) multiply defined \(by (\S+) and (\S+)\)/)
        {
            $ptrHahObjSymErr->{$2} = {} if (not exists($ptrHahObjSymErr->{$2}));
            $ptrHahObjSymErr->{$2}->{$1} = SYM_DEF if (not exists($ptrHahObjSymErr->{$2}->{$1}));
            $ptrHahObjSymErr->{$3} = {} if (not exists($ptrHahObjSymErr->{$3}));
            $ptrHahObjSymErr->{$3}->{$1} = SYM_DEF if (not exists($ptrHahObjSymErr->{$3}->{$1}));
            $ret = LINK_FAIL;
        }
        elsif ($line =~ /^Fatal error: L6000U: Out of memory/)
        {
            &utlLog(1, $line);
            $ret = LINK_OUT_OF_MEM;
            last;
        }
        elsif (   ($line =~ /^Error:/)
               || ($line =~ /^Fatal error:/))
        {
            &utlLog(0, $line);
            $ret = LINK_UNKNOWN;
            last;
        }
    }

    close(FILE_ERROR);
    return $ret;
}

sub finalLink
{
    my ($extraOption, $fileLinkOption, $ptrHahError) = @_;
    my $fileError = $ptrHahError->{file};
    my $fileOutput = $ptrHahError->{fileOutput};
    my $cmd = $Cmd_armlink . " " . $extraOption . " --via " . $fileLinkOption . " --errors " . $fileError;

    &utlLog(1, "Executing \"" . $cmd . "\"\n");
    &utlSystem($cmd, 1);
    &utlCpFile($fileError, $fileOutput) unless ($fileOutput eq "");
    return &parseErrorFile($ptrHahError);
}

BEGIN
{
    my $hasExcludedRedefinedSym = 0;

    sub ruleOutObjWithRedefinedSym
    {
        my ($ptrHahSymTable, $ptrHahRule, $ptrHahHint, $ptrHahLibErr) = @_;
        my $ptrHahMultiSymTab = $ptrHahSymTable->{ptrHahMultiSymTab};

        if (($hasExcludedRedefinedSym == 0) && $ptrHahMultiSymTab && (scalar keys(%$ptrHahMultiSymTab) > 0))
        {
            my $ptrHahSymToObjTab = $ptrHahSymTable->{ptrHahSymToObjTab};
            my $fileRule = $ptrHahRule->{file};
            my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};
            my $fileHint = $ptrHahHint->{file};
            my $ptrHahHintGut = $ptrHahHint->{ptrHahGut};

            open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);
            open(FILE_HINT, ">>" . $fileHint) or &utlDie("Cannot open " . $fileHint);

            foreach my $sym (keys(%$ptrHahMultiSymTab))
            {
                if ($sym !~ /^_Z/)
                {
                    my $ptrHahLibObj = $ptrHahSymToObjTab->{$sym}->{+SYM_DEF};

                    foreach my $lib (keys(%$ptrHahLibObj))
                    {
                        if (not &hasRule($ptrHahRuleGut, $lib, "*"))
                        {
                            foreach my $obj (keys(%{$ptrHahLibObj->{$lib}}))
                            {
                                if (not &hasRule($ptrHahRuleGut, $lib, $obj))
                                {
                                    &utlLog(1, "Adding rule to exclude " . $lib . "(" . $obj . ") due to redefinition of " . $sym . "\n");
                                    &addRule($ptrHahRuleGut, $lib, $obj, \*FILE_RULE);
                                    &addHint($ptrHahHintGut, $lib, $obj, $sym, \*FILE_HINT);
                                    $ptrHahLibErr->{$lib} = 1;
                                }
                            }
                        }
                    }
                }
            }

            close(FILE_HINT);
            close(FILE_RULE);

            $hasExcludedRedefinedSym = 1;
        }
    }
}

sub ruleOutCppLib
{
    my ($ptrHahSymTable, $ptrHahRule, $ptrHahHint, $ptrHahLibErr) = @_;
    my $ptrHahCppLibTab = $ptrHahSymTable->{ptrHahCppLibTab};

    if ($ptrHahCppLibTab && (scalar keys(%$ptrHahCppLibTab) > 0))
    {
        my $fileRule = $ptrHahRule->{file};
        my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};
        my $fileHint = $ptrHahHint->{file};
        my $ptrHahHintGut = $ptrHahHint->{ptrHahGut};

        open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);
        open(FILE_HINT, ">>" . $fileHint) or &utlDie("Cannot open " . $fileHint);

        foreach my $lib (keys(%$ptrHahCppLibTab))
        {
            if (not &hasRule($ptrHahRuleGut, $lib, "*"))
            {
                &utlLog(1, "Adding rule to exclude " . $lib . " due to C++\n");
                &addRule($ptrHahRuleGut, $lib, "*", \*FILE_RULE);
                &addHint($ptrHahHintGut, $lib, "*", "*", \*FILE_HINT);
                $ptrHahLibErr->{$lib} = 1;
            }
        }

        close(FILE_HINT);
        close(FILE_RULE);
    }
}

BEGIN
{
    my $hasExcludedCppLib = 0;

    sub handleObjSymErr
    {
        my ($ptrHahSymTable, $ptrHahRule, $ptrHahHint, $ptrHahError, $excludeCppLib) = @_;
        my $ptrHahObjSymErr = $ptrHahError->{ptrHahObjSymErr};

        if (scalar keys(%$ptrHahObjSymErr) > 0)
        {
            my $ptrHahSymToObjTab = $ptrHahSymTable->{ptrHahSymToObjTab};
            my $ptrHahCppLibTab = $ptrHahSymTable->{ptrHahCppLibTab};
            my $ptrHahLibObjRef = $ptrHahError->{ptrHahLibObjRef};

            foreach my $obj (keys(%$ptrHahObjSymErr))
            {
                foreach my $sym (keys(%{$ptrHahObjSymErr->{$obj}}))
                {
                    my $type = $ptrHahObjSymErr->{$obj}->{$sym};
                    my $ptrHahLibObj = $ptrHahSymToObjTab->{$sym}->{$type};

                    foreach my $lib (keys(%$ptrHahLibObj))
                    {
                        if (exists($ptrHahLibObj->{$lib}->{$obj}))
                        {
                            if (($hasExcludedCppLib == 1) || ($excludeCppLib == 0) || ($ptrHahCppLibTab == 0) || (not exists($ptrHahCppLibTab->{$lib})))
                            {
                                &utlLog(1, "Finding " . $obj . " with " . $sym . " from " . $lib . "\n");
                                $ptrHahLibObjRef->{$lib} = {} if (not exists($ptrHahLibObjRef->{$lib}));
                                $ptrHahLibObjRef->{$lib}->{$obj} = 1;
                            }
                        }
                    }
                }
            }
            if (($hasExcludedCppLib == 0) && $excludeCppLib)
            {
                &ruleOutCppLib($ptrHahSymTable, $ptrHahRule, $ptrHahHint, $ptrHahError->{ptrHahLibErr});
                $hasExcludedCppLib = 1;
            }
        }
    }
}

sub examineLibGut
{
    my ($lib, $ptrHahSymTable, $ptrHahRuleGut, $hdlFileRule, $ptrHahHintGut, $hdlFileHint, $ptrHahError) = @_;
    my $ptrHahSymToObjTab = $ptrHahSymTable->{ptrHahSymToObjTab};
    my $ptrHahSymErr = $ptrHahError->{ptrHahLibSymErr}->{$lib};
    my $ptrHahLibErr = $ptrHahError->{ptrHahLibErr};

    if (not &hasRule($ptrHahRuleGut, $lib, "*"))
    {
        &utlLog(1, "Examining " . $lib . "\n");

        foreach my $sym (keys(%$ptrHahSymErr))
        {
            my $type = $ptrHahSymErr->{$sym};

            foreach my $obj (keys(%{$ptrHahSymToObjTab->{$sym}->{$type}->{$lib}}))
            {
                if (not &hasRule($ptrHahRuleGut, $lib, $obj))
                {
                    &utlLog(1, "Adding rule to exclude " . $lib . "(" . $obj . ") due to error symbol " . $sym . "\n");
                    &addRule($ptrHahRuleGut, $lib, $obj, $hdlFileRule);
                    &addHint($ptrHahHintGut, $lib, $obj, $sym, $hdlFileHint);
                    $ptrHahLibErr->{$lib} = 1;
                }
            }
        }
    }
}

sub examineLibGutExt
{
    my ($libRef, $ptrHahSymTable, $ptrHahRuleGut, $hdlFileRule, $ptrHahHintGut, $hdlFileHint, $ptrHahError, $ptrHahRefObjSet) = @_;
    my $ptrHahObjToSymTab = $ptrHahSymTable->{ptrHahObjToSymTab};
    my $ptrHahSymToObjTab = $ptrHahSymTable->{ptrHahSymToObjTab};
    my $ptrHahLibErr = $ptrHahError->{ptrHahLibErr};
    my %excludedLib = ();
    my @refObjList = ();
    my $count = 0;

    &utlLog(1, "Searching libraries/objects for referred symbols to exclude...\n");

    foreach my $objRef (keys(%{$ptrHahError->{ptrHahLibObjRef}->{$libRef}}))
    {
        if (   (not exists($ptrHahRefObjSet->{$libRef}))
            || (not exists($ptrHahRefObjSet->{$libRef}->{$objRef})))
        {
            $ptrHahRefObjSet->{$libRef} = {} if (not exists($ptrHahRefObjSet->{$libRef}));
            $ptrHahRefObjSet->{$libRef}->{$objRef} = 1;
        }
        elsif ($ptrHahRefObjSet->{$libRef}->{$objRef} != 1)
        {
            next;
        }
        push(@refObjList, $libRef);
        push(@refObjList, $objRef);
    }
    $count = $#refObjList + 1;
    while ($count > 0)
    {
        my $refLib = shift(@refObjList);
        my $refObj = shift(@refObjList);
        my @symDef = keys(%{$ptrHahObjToSymTab->{$refLib}->{$refObj}->{+SYM_DEF}});

        &utlLog(2, "Defined symbols in " . $refLib . "(" . $refObj . "): @symDef\n");
        $ptrHahRefObjSet->{$refLib}->{$refObj} = 2;

        foreach my $symbol (@symDef)
        {
            my $ptrHahLibObjSymUndef = $ptrHahSymToObjTab->{$symbol}->{+SYM_UNDEF};
            my @libList = keys(%$ptrHahLibObjSymUndef);

            foreach my $lib (@libList)
            {
                if (not exists($excludedLib{$lib}))
                {
                    if (&hasRule($ptrHahRuleGut, $lib, "*"))
                    {
                        my @objList = keys(%{$ptrHahLibObjSymUndef->{$lib}});

                        foreach my $obj (@objList)
                        {
                            if ((not exists($ptrHahRefObjSet->{$lib})) || (not exists($ptrHahRefObjSet->{$lib}->{$obj})))
                            {
                                &utlLog(1, "Using " . $lib . "(" . $obj . ") to exclude objects due to reference to " . $symbol . " in " . $refLib . "(" . $refObj . ")\n");
                                push(@refObjList, $lib);
                                push(@refObjList, $obj);
                                $ptrHahRefObjSet->{$lib} = {} if (not exists($ptrHahRefObjSet->{$lib}));
                                $ptrHahRefObjSet->{$lib}->{$obj} = 1;
                            }
                        }
                    }
                    else
                    {
                        &utlLog(1, "Adding rule to exclude " . $lib . " due to reference to " . $symbol . " in " . $refLib . "(" . $refObj . ")\n");
                        &addRule($ptrHahRuleGut, $lib, "*", $hdlFileRule);
                        &addHint($ptrHahHintGut, $lib, "*", "*", $hdlFileHint);
                        $ptrHahLibErr->{$lib} = 1;
                        $excludedLib{$lib} = 1;
                    }
                }
            }
        }
        last if (scalar keys(%excludedLib));
        $count = $#refObjList + 1;
        &utlLog(2, "Referred objects(" . $count . "): @refObjList\n");
    }
}

sub examineLib
{
    my ($ptrHahSymTable, $ptrHahRule, $ptrHahHint, $ptrHahError) = @_;
    my $fileRule = $ptrHahRule->{file};
    my $ptrHahRuleGut = $ptrHahRule->{ptrHahGut};
    my $fileHint = $ptrHahHint->{file};
    my $ptrHahHintGut = $ptrHahHint->{ptrHahGut};
    my $ptrHahLibSymErr = $ptrHahError->{ptrHahLibSymErr};
    my $ptrHahLibObjRef = $ptrHahError->{ptrHahLibObjRef};
    my %refObjSet = ();

    open(FILE_HINT, ">>" . $fileHint) or &utlDie("Cannot open " . $fileHint);
    open(FILE_RULE, ">>" . $fileRule) or &utlDie("Cannot open " . $fileRule);

    # Handle error symbols.
    foreach my $lib (keys(%$ptrHahLibSymErr))
    {
        &examineLibGut($lib, $ptrHahSymTable, $ptrHahRuleGut, \*FILE_RULE, $ptrHahHintGut, \*FILE_HINT, $ptrHahError);
    }

    # Handle referred objects.
    foreach my $lib (keys(%$ptrHahLibObjRef))
    {
        &examineLibGutExt($lib, $ptrHahSymTable, $ptrHahRuleGut, \*FILE_RULE, $ptrHahHintGut, \*FILE_HINT, $ptrHahError, \%refObjSet);
    }

    close(FILE_RULE);
    close(FILE_HINT);
}

# -----------------------------------------------------------------------------

sub getDisplayValue
{
    my ($formatStr, $value) = @_;

    if ($formatStr =~ /!/)
    {
        return "on" if ($value);
        return "off";
    }
    return $value;
}

sub help
{
    my ($ptrHahOptDesc) = @_;

    printf("\nPartial Link Auto-Filter Script (%s) ver. %s\n", basename( __FILE__), $Version);
    printf("\nOptions:\n\n");

    foreach my $key (sort(keys(%$ptrHahOptDesc)))
    {
        printf("%s\n", $ptrHahOptDesc->{$key}->[1]);
        printf("\t\t%s", $ptrHahOptDesc->{$key}->[2]);
        printf(" (default: %s)", &getDisplayValue($ptrHahOptDesc->{$key}->[0], $ptrHahOptDesc->{$key}->[3])) if ($ptrHahOptDesc->{$key}->[3] ne "");
        printf("\n");
    }
    printf("\nAn example:\n\n");
    printf("Command: perl %s --lib-dir=build\\ASTRO36V3_DEMO\\tdd128dpa\\MT6236o\\lib --lib-dir=mtk_lib\\MT6236\\S00\\tdd128dpa\\CMCC_TD0200_SEGE --scatter-file=custom\\system\\ASTRO36V3_DEMO_BB\\scatASTRO36V3_DEMO_FOTA.txt --link-option-file=make\\~sortedLibs.tmp --nm=tools\\MinGW\\bin\\arm-none-eabi-nm.exe --readelf=tools\\MinGW\\bin\\arm-none-eabi-readelf.exe --strip=tools\\MinGW\\bin\\arm-none-eabi-strip.exe\n\n", __FILE__);
}

use constant {
    TYPE_AUTO    => 1,
    TYPE_NORMAL  => 2,
    TYPE_PARTIAL => 3,
};

sub getOption
{
    my ($ptrHahOpt, $ptrHahOptPath, $ptrHahOptPathMust) = @_;
    my %optDesc = (
        "ptrAryLibDir" => [ "lib-dir=s", "--lib-dir=", "a path to a library directory for partial link", "" ],
        "ptrAryUserExclusionFile" => [ "exclusion-file=s", "--exclusion-file=", "a path to a user exclusion file", "" ],
        "fileScatter" => [ "scatter-file=s", "--scatter-file=", "a path to a scatter file", "" ],
        "fileLinkOption" => [ "link-option-file=s", "--link-option-file=", "a path to a file with link options for final link", "" ],
        "dirInfo" => [ "info-dir=s", "--info-dir=", "a path to a directory to access info", $ptrHahOptPathMust->{dirInfo} ],
        "dirSave" => [ "save-dir=s", "--save-dir=", "a path to a directory to save log", $ptrHahOptPathMust->{dirSave} ],
        "dirTemp" => [ "temp-dir=s", "--temp-dir=", "a path to a temp directory", $ptrHahOptPathMust->{dirTemp} . "/pl_temp" ],
        "cmd_nm" => [ "nm=s", "--nm=", "a path to command nm", "" ],
        "cmd_readelf" => [ "readelf=s", "--readelf=", "a path to command readelf", "" ],
        "cmd_strip" => [ "strip=s", "--strip=", "a path to command strip", "" ],
        "cmd_armar" => [ "armar=s", "--armar=", "a path to command armar", $Cmd_armar ],
        "cmd_armlink" => [ "armlink=s", "--armlink=", "a path to command armlink", $Cmd_armlink ],
        "fileLinkErr" => [ "link-err-file=s", "--link-err-file=", "a path to a file to output link error", "" ],
        "reGenRule" => [ "regen-rule!", "--[no-]regen-rule", "re-generate rule", $ptrHahOpt->{reGenRule} ],
        "reGenHint" => [ "regen-hint!", "--[no-]regen-hint", "re-generate hint", $ptrHahOpt->{reGenHint} ],
        "hintToRule" => [ "hint-to-rule!", "--[no-]hint-to-rule", "convert hint to rule", $ptrHahOpt->{hintToRule} ],
        "excludeCppLib" => [ "exclude-cpp-lib!", "--[no-]exclude-cpp-lib", "exclude all C++ libraries when errors happen", $ptrHahOpt->{excludeCppLib} ],
        "passLimit" => [ "pass-limit=i", "--pass-limit=", "set limitation of the max. pass to resolve linking error", $ptrHahOpt->{passLimit} ],
        "simulate" => [ "simulate!", "--[no-]simulate", "run the whole process without modifying libraries", $ptrHahOpt->{simulate} ],
        "linkType" => [ "link-type=i", "--link-type=", "specify 1 for \"auto enabling partial link\", 2 for \"normal link\", or 3 for \"partial link\"", $ptrHahOpt->{linkType} ],
        "libSizeInfo" => [ "lib-size-info!", "--[no-]lib-size-info", "generate library size info", $ptrHahOpt->{libSizeInfo} ],
        "stripDebugInfo" => [ "strip-debug-info!", "--[no-]strip-debug-info", "strip debug info", $ptrHahOpt->{stripDebugInfo} ],
        "stripDebugCount" => [ "strip-debug-count=i", "--strip-debug-count=", "set default count to strip debug info if \"pl_debug.txt\" is not available", $ptrHahOpt->{stripDebugCount} ],
        "check" => [ "check!", "--[no-]check", "not to run if partial link is done last time", $ptrHahOpt->{check} ],
        "forcePartialLink" => [ "force-partial-link!", "--[no-]force-partial-link", "force to run partial link only", $ptrHahOpt->{forcePartialLink} ],
        "update" => [ "update!", "--[no-]update", "update libraries specified in \"--lib-dir=...\" with partially-linked ones", $ptrHahOpt->{update} ],
        "save" => [ "save!", "--[no-]save", "save partially-linked libraries", $ptrHahOpt->{save} ],
        "dbgLevel" => [ "debug-level=i", "--debug-level=", "set debug level", $DbgLevel ],
        "infoLevel" => [ "info-level=i", "--info-level=", "set how much information displays in the screen", $InfoLevel ],
        "help" => [ "help", "--help", "show this help", "" ],
    );

    if (!GetOptions(
        $optDesc{ptrAryLibDir}[0] => \@{$ptrHahOptPathMust->{ptrAryLibDir}},
        $optDesc{ptrAryUserExclusionFile}[0] => \@{$ptrHahOptPath->{ptrAryUserExclusionFile}},
        $optDesc{fileScatter}[0] => \$ptrHahOptPathMust->{fileScatter},
        $optDesc{fileLinkOption}[0] => \$ptrHahOptPathMust->{fileLinkOption},
        $optDesc{dirInfo}[0] => \$ptrHahOptPathMust->{dirInfo},
        $optDesc{dirSave}[0] => \$ptrHahOptPathMust->{dirSave},
        $optDesc{dirTemp}[0] => \$ptrHahOptPathMust->{dirTemp},
        $optDesc{cmd_nm}[0] => \$ptrHahOptPathMust->{cmd_nm},
        $optDesc{cmd_readelf}[0] => \$ptrHahOptPathMust->{cmd_readelf},
        $optDesc{cmd_strip}[0] => \$ptrHahOptPathMust->{cmd_strip},
        $optDesc{cmd_armar}[0] => \$ptrHahOptPath->{cmd_armar},
        $optDesc{cmd_armlink}[0] => \$ptrHahOptPath->{cmd_armlink},
        $optDesc{fileLinkErr}[0] => \$ptrHahOptPath->{fileLinkErr},
        $optDesc{reGenRule}[0] => \$ptrHahOpt->{reGenRule},
        $optDesc{reGenHint}[0] => \$ptrHahOpt->{reGenHint},
        $optDesc{hintToRule}[0] => \$ptrHahOpt->{hintToRule},
        $optDesc{excludeCppLib}[0] => \$ptrHahOpt->{excludeCppLib},
        $optDesc{passLimit}[0] => \$ptrHahOpt->{passLimit},
        $optDesc{simulate}[0] => \$ptrHahOpt->{simulate},
        $optDesc{linkType}[0] => \$ptrHahOpt->{linkType},
        $optDesc{libSizeInfo}[0] => \$ptrHahOpt->{libSizeInfo},
        $optDesc{stripDebugInfo}[0] => \$ptrHahOpt->{stripDebugInfo},
        $optDesc{stripDebugCount}[0] => \$ptrHahOpt->{stripDebugCount},
        $optDesc{check}[0] => \$ptrHahOpt->{check},
        $optDesc{forcePartialLink}[0] => \$ptrHahOpt->{forcePartialLink},
        $optDesc{update}[0] => \$ptrHahOpt->{update},
        $optDesc{save}[0] => \$ptrHahOpt->{save},
        $optDesc{dbgLevel}[0] => \$DbgLevel,
        $optDesc{infoLevel}[0] => \$InfoLevel,
        $optDesc{help}[0] => \$ptrHahOpt->{help}) || $ptrHahOpt->{help})
    {
        &help(\%optDesc);
        return 1;
    }

    foreach my $key (keys(%$ptrHahOptPath))
    {
        if (ref($ptrHahOptPath->{$key}) eq 'ARRAY')
        {
            for (my $i = 0; $i <= $#{$ptrHahOptPath->{$key}}; $i++)
            {
                $ptrHahOptPath->{$key}->[$i] = &utlTrim($ptrHahOptPath->{$key}->[$i]);
                &utlDie("Value of option " . $optDesc{$key}[1] . " cannot be empty") if ($ptrHahOptPath->{$key}->[$i] eq "");
                $ptrHahOptPath->{$key}->[$i] = &utlAbsPath($ptrHahOptPath->{$key}->[$i]);
            }
        }
        else
        {
            $ptrHahOptPath->{$key} = &utlTrim($ptrHahOptPath->{$key});
            if ($ptrHahOptPath->{$key} ne "")
            {
                if (($key eq "fileLinkErr") && (! -e $ptrHahOptPath->{$key}))
                {
                    my $path = dirname($ptrHahOptPath->{$key});
                    my $fileName = basename($ptrHahOptPath->{$key});

                    &utlDie("Cannot find " . $path) unless (-e $path);
                    $ptrHahOptPath->{$key} = &utlAbsPath($path) . "/" . $fileName;
                }
                else
                {
                    $ptrHahOptPath->{$key} = &utlAbsPath($ptrHahOptPath->{$key});
                }
            }
            elsif ($optDesc{$key}->[3] ne "")
            {
                $ptrHahOptPath->{$key} = $optDesc{$key}->[3];
            }
        }
    }
    foreach my $key (keys(%$ptrHahOptPathMust))
    {
        if (ref($ptrHahOptPathMust->{$key}) eq 'ARRAY')
        {
            my $ptrAryPath = [];

            &utlDie("Must specify " . $optDesc{$key}[1]) if ($#{$ptrHahOptPathMust->{$key}} < 0);
            for (my $i = 0; $i <= $#{$ptrHahOptPathMust->{$key}}; $i++)
            {
                my $path = $ptrHahOptPathMust->{$key}->[$i];

                $path = &utlTrim($path);
                &utlDie("Value of option " . $optDesc{$key}[1] . " cannot be empty") if ($path eq "");
                if (-e $path)
                {
                    push(@$ptrAryPath, &utlAbsPath($path));
                }
                else
                {
                    &utlLog(0, "Ignore " . $path . " due to no existence\n");
                }
            }
            &utlDie("No valid path is specified by option " . $optDesc{$key}[1]) unless ($#$ptrAryPath >= 0);
            $ptrHahOptPathMust->{$key} = $ptrAryPath;
        }
        else
        {
            $ptrHahOptPathMust->{$key} = &utlTrim($ptrHahOptPathMust->{$key});
            &utlDie("Value of option " . $optDesc{$key}[1] . " cannot be empty") if ($ptrHahOptPathMust->{$key} eq "");
            $ptrHahOptPathMust->{$key} = &utlAbsPath($ptrHahOptPathMust->{$key});
        }
    }

    if (   ($ptrHahOpt->{linkType} != TYPE_AUTO)
        && ($ptrHahOpt->{linkType} != TYPE_NORMAL)
        && ($ptrHahOpt->{linkType} != TYPE_PARTIAL))
    {
        &utlDie("Illegal value " . $ptrHahOpt->{linkType} . " for option " . $optDesc{linkType}[1]);
    }
    return 0;
}

sub formatCmd
{
    my ($cmd) = @_;

    $cmd =~ s/\(/"("/g;
    $cmd =~ s/\)/")"/g;

    return $cmd;
}

sub dumpOpt
{
    my ($ptrHah) = @_;

    foreach my $key (keys(%$ptrHah))
    {
        &utlLog(1, "-> " . $key . "\n");
        &utlDump(1, $ptrHah->{$key});
    }
}

BEGIN
{
    my $_file = "";

    sub setupErrorHandling
    {
        my ($file) = @_;

        &utlRmFile(dirname($file) . "/" . basename($FileErr));
        $_file = $file;
    }

    sub errorHandling
    {
        if ($_file ne "")
        {
            &utlCpFile($FileErr, $_file);
            &utlCpFile($FileErr, dirname($_file));
        }
    }
}

sub readIniFile
{
    my ($ptrHahIni) = @_;
    my $fileIni = $ptrHahIni->{file};
    my $ptrHahAttr = $ptrHahIni->{ptrHahAttr};
    my $ptrHahValue = $ptrHahIni->{ptrHahValue};
    my $ptrHahOnOff = $ptrHahIni->{ptrHahOnOff};

    if (-e $fileIni)
    {
        open(FILE_INI, "<" . $fileIni) or &utlDie("Cannot open " . $fileIni);
        
        foreach my $line (<FILE_INI>)
        {
            next if (($line =~ /^\s*$/) || ($line =~ /^\s*;/));

            # key = value
            if ($line =~ /^\s*(\S+)\s*=\s*([-]?\d+)/)
            {
                my $key = $1;
                my $value = $2;

                if (exists($ptrHahAttr->{$key}))
                {
                    $ptrHahAttr->{$key} = $value;
                }
                elsif (exists($ptrHahValue->{$key}))
                {
                    $ptrHahValue->{$key}->[0] = 1;
                    ${$ptrHahValue->{$key}->[1]} = $value;

                    if ($#{$ptrHahValue->{$key}} > 1)
                    {
                        my $found = 0;

                        for (my $i = 2; $i <= $#{$ptrHahValue->{$key}}; $i++)
                        {
                            if ($value == $ptrHahValue->{$key}->[$i])
                            {
                                $found = 1;
                                last;
                            }
                        }
                        &utlDie("Invalid value \"" . $value . "\" for " . $key . " in " . $fileIni) unless ($found);
                    }
                }
                elsif (exists($ptrHahOnOff->{$key}))
                {
                    if (($value == 1) || ($value == 0))
                    {
                        $ptrHahOnOff->{$key}->[0] = 1;
                        ${$ptrHahOnOff->{$key}->[1]} = $value;
                    }
                    else
                    {
                        &utlDie("Invalid value \"" . $value . "\" for " . $key . " in " . $fileIni . "; should be 0 for disable and 1 for enable");
                    }
                }
                else
                {
                    &utlDie("Invalid key \"" . $key . "\" in " . $fileIni);
                }
            }
            else
            {
                &utlDie("Unrecognized line \"" . $line . "\" in " . $fileIni);
            }
        }

        close(FILE_INI);
    }
}

sub writeIniFile
{
    my ($ptrHahIni) = @_;
    my $fileIni = $ptrHahIni->{file};
    my $flag = $ptrHahIni->{flag};
    my $ptrHahAttr = $ptrHahIni->{ptrHahAttr};
    my $ptrHahValue = $ptrHahIni->{ptrHahValue};
    my $ptrHahOnOff = $ptrHahIni->{ptrHahOnOff};

    if ($flag != 0)
    {
        open(FILE_INI, ">" . $fileIni) or &utlDie("Cannot open " . $fileIni);

        print(FILE_INI "\n; DO NOT MODIFY THE FOLLOWING INFORMATION\n\n");

        foreach my $key (keys(%$ptrHahAttr))
        {
            print(FILE_INI $key . "=" . $ptrHahAttr->{$key} . "\n");
        }

        print(FILE_INI "\n; UNCOMMENT THE FOLLOWING TO OVERRIDE CORRESPONDING SETTINGS BY REMOVING \";\"\n\n");

        foreach my $key (keys(%$ptrHahValue))
        {
            if ($ptrHahValue->{$key}->[0] != 0)
            {
                print(FILE_INI $key . "=" . ${$ptrHahValue->{$key}->[1]} . "\n");
            }
            else
            {
                print(FILE_INI "; " . $key . "=" . ${$ptrHahValue->{$key}->[1]} . "\n");
            }
        }
        foreach my $key (keys(%$ptrHahOnOff))
        {
            if ($ptrHahOnOff->{$key}->[0] != 0)
            {
                print(FILE_INI $key . "=" . ${$ptrHahOnOff->{$key}->[1]} . "\n");
            }
            elsif (${$ptrHahOnOff->{$key}->[1]})
            {
                print(FILE_INI "; " . $key . "=0\n");
            }
            else
            {
                print(FILE_INI "; " . $key . "=1\n");
            }
        }

        close(FILE_INI);
    }
}

sub setIni
{
    my ($ptrHahIni, $key, $value) = @_;

    $ptrHahIni->{ptrHahAttr}->{$key} = $value;
    $ptrHahIni->{flag} = 1;
}

sub syncLib
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $suffix = $ptrHahLib->{suffix};
    my $suffix_bak = $ptrHahLib->{suffix_bak};

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my $dirDstLib = $dirSrcLib . $suffix;
        my $dirSrcBak = $dirSrcLib . $suffix_bak;

        if ((-e $dirSrcBak) && (-e $dirDstLib))
        {
            my @libList = glob($dirSrcLib . "/*");

            foreach my $lib (@libList)
            {
                if (-f $lib)
                {
                    my $libName = basename($lib);
                    my $timestamp = &utlGetTimestamp($lib);
                    my $libDst = $dirDstLib . "/" . $libName;

                    if ((-e $libDst) && ($timestamp == &utlGetTimestamp($libDst)))
                    {
                        my $libSrcBak = $dirSrcBak . "/" . $libName;

                        if (-e $libSrcBak)
                        {
                            &utlLog(1, "Restoring " . $libName . "\n");
                            &utlCpFile($libSrcBak, $lib) if ($timestamp != &utlGetTimestamp($libSrcBak));
                        }
                    }
                }
            }
        }
        &utlRmTree($dirSrcBak);
        &utlRmTree($dirDstLib);
        &utlRmTree($dirSrcLib . $ptrHahLib->{suffix_dbg});
        &utlRmTree($dirSrcLib . $ptrHahLib->{suffix_save});
    }
}

sub checkLib
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $fileTimestamp = $ptrHahLib->{fileTimestamp};
    my $ptrHahLibNew = $ptrHahLib->{ptrHahLibNew};
    my $ptrHahLibUpdate = $ptrHahLib->{ptrHahLibUpdate};
    my %timestamp = ();

    # Load timestamp of each library.
    if (-e $fileTimestamp)
    {
        open(FILE_TS, "<" . $fileTimestamp) or &utlDie("Cannot open " . $fileTimestamp);

        foreach my $line (<FILE_TS>)
        {
            if ($line =~ /^\s*(\S+)\s*(\S+)/)
            {
                $timestamp{$1} = $2;
            }
        }

        close(FILE_TS);
    }

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . "/*.lib");

        foreach my $lib (@libList)
        {
            my $curTimestamp = (stat($lib))[9];
            my $libName = basename($lib);

            next if (exists($IgnoredLib{$libName}));

            if (not exists($timestamp{$libName}))
            {
                $ptrHahLibNew->{$libName} = 1;
            }
            elsif ($curTimestamp > $timestamp{$libName})
            {
                $ptrHahLibUpdate->{$libName} = 1;
            }
        }
    }
}

sub generateLibSize
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $ptrHahLibNew = $ptrHahLib->{ptrHahLibNew};
    my $ptrHahLibUpdate = $ptrHahLib->{ptrHahLibUpdate};
    my $dirLibSize = $ptrHahLib->{dirLibSize};

    &utlMkDir($dirLibSize);

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . "/*.lib");

        foreach my $lib (@libList)
        {
            my $libName = basename($lib);

            if (exists($ptrHahLibNew->{$libName}) || exists($ptrHahLibUpdate->{$libName}))
            {
                &utlLog(1, "Generating size info for " . $libName . "\n");
                &utlSystem($Cmd_armar . " --sizes " . $lib . " >" . $dirLibSize . "/" . $libName . ".txt");
            }
        }
    }
}

sub normalLinkStrip
{
    my ($ptrHanLib, $ptrHahError, $fileCppLib, $fileDbgLib, $fileLinkOption, $stripDebugCount) = @_;
    my $ret = 0;

    &copyLib($ptrHanLib->{ptrAryLibDir}, "", $ptrHanLib->{suffix});
    &removeDebugInfo($ptrHanLib, $ptrHanLib->{suffix}, $fileCppLib, $fileDbgLib, $stripDebugCount);
    $ret = &finalLink("", $fileLinkOption, $ptrHahError);
    &removeDstLibDir($ptrHanLib, $ptrHanLib->{suffix}, "") if ($ret == LINK_OK);
    return $ret;
}

sub partialLink
{
    my ($ptrHahOpt, $ptrHahOptPath, $ptrHahOptPathMust, $ptrHahLib, $ptrHahError, $fileCppLib, $fileDbgLib, $fileLinkOption) = @_;
    my %rule = (
        "file" => $ptrHahOptPathMust->{dirSave} . "/pl.rule",
        "fileRule" => $ptrHahOptPathMust->{dirInfo} . "/pl_rule.txt",
        "ptrHahGut" => {},
    );
    my %hint = (
        "file" => $ptrHahOptPathMust->{dirSave} . "/pl.hint",
        "fileHint" => $ptrHahOptPathMust->{dirInfo} . "/pl_hint.txt",
        "toRule" => $ptrHahOpt->{hintToRule},
        "ptrHahGut" => {},
        "use" => 1,
    );
    my $fileExclusion = $ptrHahOptPathMust->{dirInfo} . "/pl_exclusion.txt";
    my $pass = 0;
    my $ret = 1;

    # Remove temporary files.
    &utlRmFile($rule{file});
    &utlRmFile($hint{file});

    # Create temporary directories for partially-linked libraries.
    &createDstLibDir($ptrHahLib);

    if (($ptrHahOpt->{reGenRule} == 0) && (-e $rule{fileRule}))
    {
        &readRuleFile(\%rule);
    }
    else
    {
        # Parse scatter file and output rules to the rule file.
        &parseScatterFile($ptrHahOptPathMust->{fileScatter}, \%rule);

        # Read user exclusion file and output rules to the rule file.
        &readUserExclusionFile($ptrHahOptPath->{ptrAryUserExclusionFile}, \%rule);

        # Read exclusion file and output rules to the rule file.
        &readExclusionFile($fileExclusion, \%rule) if (-e $fileExclusion);

        # Write built-in excluded libraries to the rule file.
        &writeExcludedLib(\@ExcludedLib, \%rule);
    }

    # Read hint file and output rules to the rule file.
    &readHintFile(\%hint, \%rule) if (($ptrHahOpt->{reGenHint} == 0) && (-e $hint{fileHint}));

    # Generate a link option file.
    &generateLinkOptFile($ptrHahLib, $rule{ptrHahGut}, $ptrHahOptPathMust->{fileLinkOption}, $fileLinkOption);

    &utlLog(2, "Dumping hint...\n");
    &utlDump(2, $hint{ptrHahGut});
    &utlLog(2, "Dumping rule...\n");
    &utlDump(2, $rule{ptrHahGut});

    while ($pass < $ptrHahOpt->{passLimit})
    {
        $pass++;
        &utlLog(1, "Pass " . $pass . "...\n");

        # Set a file to output linking error.
        $ptrHahError->{file} = $ptrHahOptPathMust->{dirSave} . "/pl_error_" . $pass . ".log";

        if ($pass != 1)
        {
            &loadSymTable($ptrHahLib, $fileCppLib);
            &ruleOutObjWithRedefinedSym($ptrHahLib->{ptrHahSymTable}, \%rule, \%hint, $ptrHahError->{ptrHahLibErr});

            # Find out libraries where objects with error symbols are located.
            &utlLog(2, "Dumping errors from objects with symbols...\n");
            &utlDump(2, $ptrHahError->{ptrHahObjSymErr});
            &handleObjSymErr($ptrHahLib->{ptrHahSymTable}, \%rule, \%hint, $ptrHahError, $ptrHahOpt->{excludeCppLib});

            &utlLog(2, "Dumping errors from libraries with symbols...\n");
            &utlDump(2, $ptrHahError->{ptrHahLibSymErr});
            &examineLib($ptrHahLib->{ptrHahSymTable}, \%rule, \%hint, $ptrHahError);

            last unless (scalar keys(%{$ptrHahError->{ptrHahLibErr}}));
            &utlLog(3, "Dumping rule...\n");
            &utlDump(3, $rule{ptrHahGut});
        }

        # Partially link objects in the same libraries according to rule and linking error.
        $Current_time = time;
        system("echo T_S,partialLinkLib,P,$Current_time >> $ptrHahOptPathMust->{dirSave}/PlinkTime.log");
        &partialLinkLib($ptrHahLib, \%rule, \%hint, $ptrHahError->{ptrHahLibErr});
        $Current_time = time;
        system("echo T_E,partialLinkLib,P,$Current_time >> $ptrHahOptPathMust->{dirSave}/PlinkTime.log");

        # Link all by using command from a file specified in option.
        $ret = &finalLink("--mangled", $fileLinkOption, $ptrHahError);
        last if (($ret == LINK_OK) || ($ret == LINK_OUT_OF_MEM) || ($ret == LINK_UNKNOWN));
    }
    if ($ret == LINK_OUT_OF_MEM)
    {
        if ($ptrHahOpt->{stripDebugInfo})
        {
            &utlLog(0, "Trying link with debug info stripping due to \"Fatal error: L6000U: Out of memory.\"\n");
            $ptrHahError->{file} = $ptrHahOptPathMust->{dirSave} . "/pl_error_dbg.log";
            &copyLib($ptrHahLib->{ptrAryLibDir}, $ptrHahLib->{suffix}, $ptrHahLib->{suffix_dbg});
            &removeDebugInfo($ptrHahLib, $ptrHahLib->{suffix}, $fileCppLib, $fileDbgLib, $ptrHahOpt->{stripDebugCount});
            $ret = &finalLink("", $fileLinkOption, $ptrHahError);
            $ret = LINK_OK_STRIP if ($ret == LINK_OK);
            if (($ret == LINK_OK_STRIP) || ($ret == LINK_OUT_OF_MEM))
            {
                &removeDstLibDir($ptrHahLib, $ptrHahLib->{suffix}, "");
                $ptrHahLib->{suffix} = $ptrHahLib->{suffix_dbg};
            }
        }
    }
    if (($ret == LINK_OK) || ($ret == LINK_OK_STRIP) || ($ret == LINK_OUT_OF_MEM))
    {
        if ($ptrHahOpt->{simulate})
        {
            &removeDstLibDir($ptrHahLib, $ptrHahLib->{suffix}, $ptrHahLib->{suffix_save});
        }
        elsif ($ptrHahOpt->{update} == 0)
        {
            my $suffix = "";

            $suffix = $ptrHahLib->{suffix_save} if ($ptrHahOpt->{save});
            &removeDstLibDir($ptrHahLib, $ptrHahLib->{suffix}, $suffix);
            &utlCpFile($rule{file}, $rule{fileRule});
            &utlCpFile($hint{file}, $hint{fileHint});
        }
        else
        {
            &finalizeLib($ptrHahLib);
            &utlCpFile($rule{file}, $rule{fileRule});
            &utlCpFile($hint{file}, $hint{fileHint});
        }
    }
    elsif ($ret != LINK_OUT_OF_MEM)
    {
        &removeDstLibDir($ptrHahLib, $ptrHahLib->{suffix}, "");
        &removeDstLibDir($ptrHahLib, $ptrHahLib->{suffix_dbg}, "");
    }
    return $ret;
}

sub generateLibTimestamp
{
    my ($ptrHahLib) = @_;
    my $ptrAryLibDir = $ptrHahLib->{ptrAryLibDir};
    my $fileTimestamp = $ptrHahLib->{fileTimestamp};

    &utlLog(1, "Generating library timestamp\n");
    open(FILE_TS, ">" . $fileTimestamp) or &utlDie("Cannot open " . $fileTimestamp);

    foreach my $dirSrcLib (@$ptrAryLibDir)
    {
        my @libList = glob($dirSrcLib . "/*.lib");

        foreach my $lib (@libList)
        {
            my $timestamp = (stat($lib))[9];
            my $libName = basename($lib);

            print(FILE_TS $libName . " " . $timestamp . "\n");
        }
    }

    close(FILE_TS);
}

sub main
{  
	  $Current_time = time;
    my ($argc, $argv) = @_;
    # Set options.
    my %opt = (
        "reGenRule" => 1,
        "reGenHint" => 0,
        "hintToRule" => 1,
        "excludeCppLib" => 0,
        "passLimit" => 7,
        "simulate" => 0,
        "linkType" => TYPE_AUTO,
        "libSizeInfo" => 1,
        "stripDebugInfo" => 1,
        "stripDebugCount" => 8,
        "check" => 0,
        "forcePartialLink" => 0,
        "update" => 1,
        "save" => 0,
        "help" => 0,
    );
    # Set options with validated path values.
    my %optPath = (
        "ptrAryUserExclusionFile" => [],
        "cmd_armar" => "",
        "cmd_armlink" => "",
        "fileLinkErr" => "",
    );
    my %optPathMust = (
        "ptrAryLibDir" => [],
        "cmd_nm" => "",
        "cmd_readelf" => "",
        "cmd_strip" => "",
        "fileScatter" => "",
        "fileLinkOption" => "",
        "dirInfo" => cwd(),
        "dirSave" => cwd(),
        "dirTemp" => cwd(),
    );
    my $plink_start = time;
    my $plink_end = "";

    return 2 if (&getOption(\%opt, \%optPath, \%optPathMust));
    system("echo T_S,Plink,P,$Current_time > $optPathMust{dirSave}/PlinkTime.log");

    # Set global variables.
    $FileLog = $optPathMust{dirSave} . "/pl.log";
    system("date/T >" . $FileLog);
    system("time/T >>" . $FileLog);
    $FileErr = $optPathMust{dirSave} . "/pl.err";
    $FileTmp = $optPathMust{dirSave} . "/pl.tmp";
    $DirTemp = $optPathMust{dirTemp} . "/pl_temp";
    $Cmd_nm = &formatCmd($optPathMust{cmd_nm});
    $Cmd_readelf = &formatCmd($optPathMust{cmd_readelf});
    $Cmd_strip = &formatCmd($optPathMust{cmd_strip});
    $Cmd_armar = &formatCmd($optPath{cmd_armar});
    $Cmd_armlink = &formatCmd($optPath{cmd_armlink});

    # Show command line.
    &utlLog(1, "[@$argv]\n");

    &utlLog(1, "Dumping options...\n");
    &dumpOpt(\%opt);
    &dumpOpt(\%optPath);
    &dumpOpt(\%optPathMust);

    use constant {
        STATE_NONE              => 0,
        STATE_NORMAL_LINK       => 1,
        STATE_NORMAL_LINK_STRIP => 2,
        STATE_PARTIAL_LINK      => 3,
    };
    my %ini = (
        "file" => $optPathMust{dirInfo} . "/pl.ini",
        "flag" => 0,
        "ptrHahAttr" => {
            "state" => STATE_NONE,
            "link" => LINK_NONE,
        },
        "ptrHahValue" => {
            "pass_limit" => [ 0, \$opt{passLimit} ],
            "link_type" => [ 0, \$opt{linkType}, TYPE_AUTO, TYPE_NORMAL, TYPE_PARTIAL ],
            "strip_debug_count" => [ 0, \$opt{stripDebugCount} ],
        },
        "ptrHahOnOff" => {
            "regen_hint" => [ 0, \$opt{reGenHint} ],
            "exclude_cpp_lib" => [ 0, \$opt{excludeCppLib} ],
            "simulate" => [ 0, \$opt{simulate} ],
            "strip_debug_info" => [ 0, \$opt{stripDebugInfo} ],
            "check" => [ 0, \$opt{check} ],
            "force_partial_link" => [ 0, \$opt{forcePartialLink} ],
            "update" => [ 0, \$opt{update} ],
            "save" => [ 0, \$opt{save} ],
        },
    );
    my %lib = (
        "ptrAryLibDir" => $optPathMust{ptrAryLibDir},
        "suffix" => "__PARTIAL_LINK_TEMPORARY",
        "suffix_bak" => "__PARTIAL_LINK_SRC_BACKUP",
        "suffix_dbg" => "__PARTIAL_LINK_DBG",
        "suffix_save" => "__PARTIAL_LINK",
        "fileTimestamp" => $optPathMust{dirInfo} . "/pl_timestamp.txt",
        "dirLibSize" => $optPathMust{dirInfo} . "/pl_lib_size",
        "ptrHahLibNew" => {},
        "ptrHahLibUpdate" => {},
        "ptrHahLibUsage" => {},
        "ptrHahNoDbgLib" => {},
        "ptrHahSymTable" => {},
    );
    my %error = (
        "file" => "",
        "fileOutput" => $optPath{fileLinkErr},
        "ptrHahObjSymErr" => 0,
        "ptrHahLibSymErr" => 0,
        "ptrHahLibObjRef" => 0,
        "ptrHahLibErr" => 0,
    );
    my $fileCppLib = $optPathMust{dirInfo} . "/pl_cpp.txt";
    my $fileDbgLib = $optPathMust{dirInfo} . "/pl_debug.txt";
    my $fileLinkOption = $optPathMust{dirSave} . "/pl_link_opt.via";
    my $flagNormalLink = 0;
    my $flagPartialLink = 0;
    my $state = STATE_PARTIAL_LINK;
    my $link = LINK_UNKNOWN;
    my $ret = 1;

    # Register an error handling.
    &setupErrorHandling($error{fileOutput});
    &sysDieRegister(\&errorHandling);

    &utlRmFile($FileErr);
    &utlRmFile($FileTmp);
    &utlRmTree($DirTemp);

    &readIniFile(\%ini);
    &syncLib(\%lib);
    &checkLib(\%lib);
    &generateLibSize(\%lib) if ($opt{libSizeInfo});

    &dumpOpt(\%ini);
    &dumpOpt(\%lib);

    if (   ($opt{check} != 0)
        # Libraries are not updated.
        && (scalar keys(%{$lib{ptrHahLibNew}}) == 0)
        && (scalar keys(%{$lib{ptrHahLibUpdate}}) == 0)
        # Libraries were partially linked successfully last time.
        && ($ini{ptrHahAttr}->{state} == STATE_PARTIAL_LINK)
        && (   ($ini{ptrHahAttr}->{link} == LINK_OK)
            || ($ini{ptrHahAttr}->{link} == LINK_OK_STRIP)))
    {
        &utlLog(0, "Partial link is done last time\n");
        return 0;
    }

    # Decide what to do according to result from last time.
    if (   ($opt{forcePartialLink} == 0)
        # Stripping debug info is enabled.
        && ($opt{stripDebugInfo} != 0)
        # Libraries are not updated.
        && (scalar keys(%{$lib{ptrHahLibNew}}) == 0)
        && (scalar keys(%{$lib{ptrHahLibUpdate}}) == 0)
        # Libraries were stripped successfully last time.
        && (   (   ($ini{ptrHahAttr}->{state} == STATE_NORMAL_LINK_STRIP)
                && (   ($ini{ptrHahAttr}->{link} == LINK_OK)
                    || ($ini{ptrHahAttr}->{link} == LINK_OUT_OF_MEM)))
            || (   ($ini{ptrHahAttr}->{state} == STATE_PARTIAL_LINK)
                && (   ($ini{ptrHahAttr}->{link} == LINK_OK_STRIP)
                    || ($ini{ptrHahAttr}->{link} == LINK_OUT_OF_MEM)))))
    {
        $state = STATE_NORMAL_LINK_STRIP;
    }
    elsif (   ($opt{forcePartialLink} != 0)
           || ($opt{linkType} == TYPE_PARTIAL))
    {
        $state = STATE_PARTIAL_LINK;
    }
    else
    {
        $state = STATE_NORMAL_LINK;
    }

    while (1)
    {
        my $curState = $state;

        if ($curState == STATE_NORMAL_LINK)
        {
            &utlLog(0, "Trying normal link...\n");
            $flagNormalLink = 1;
            $error{file} = $optPathMust{dirSave} . "/pl_error_normal.log";
            $link = &finalLink("", $optPathMust{fileLinkOption}, \%error);
            if ($link == LINK_OUT_OF_MEM)
            {
                if ($opt{linkType} == TYPE_AUTO)
                {
                    $state = STATE_PARTIAL_LINK if ($flagPartialLink == 0);
                }
                elsif ($opt{linkType} == TYPE_NORMAL)
                {
                    $state = STATE_NORMAL_LINK_STRIP if ($opt{stripDebugInfo});
                }
            }
        }
        elsif ($curState == STATE_NORMAL_LINK_STRIP)
        {
            &utlLog(0, "Trying normal link with debug info stripping...\n");
            &generateLinkOptFile(\%lib, 0, $optPathMust{fileLinkOption}, $fileLinkOption);
            $error{file} = $optPathMust{dirSave} . "/pl_error_dbg.log";
            $link = &normalLinkStrip(\%lib, \%error, $fileCppLib, $fileDbgLib, $fileLinkOption, $opt{stripDebugCount});
        }
        elsif ($curState == STATE_PARTIAL_LINK)
        {
            &utlLog(0, "Trying partial link...\n");
            $flagPartialLink = 1;
            $link = &partialLink(\%opt, \%optPath, \%optPathMust, \%lib, \%error, $fileCppLib, $fileDbgLib, $fileLinkOption);
            $state = STATE_NORMAL_LINK if (($opt{forcePartialLink} == 0) && ($flagNormalLink == 0) && ($link != LINK_OK) && ($link != LINK_OK_STRIP) && ($link != LINK_OUT_OF_MEM));
        }
        if (($link == LINK_OK) || ($link == LINK_OK_STRIP))
        {
            &utlLog(0, "Succeed to link\n");
            &generateLibTimestamp(\%lib) unless ($opt{simulate});
            $ret = 0;
        }
        elsif ($link == LINK_OUT_OF_MEM)
        {
            &utlLog(0, "Fail to link due to \"Fatal error: L6000U: Out of memory.\"\n");
            next if ($state != $curState);
            &generateLibTimestamp(\%lib) if (($opt{simulate} == 0) && ($state == STATE_PARTIAL_LINK));
            if ($opt{stripDebugInfo})
            {
                &utlLog(0, "PLEASE EDIT \"pl_debug.txt\" TO REMOVE MORE DEBUG INFO FROM LIBRARIES\n");
            }
            else
            {
                &utlLog(0, "PLEASE ENABLE \"--strip-debug-info\" TO REMOVE DEBUG INFO OF LIBRARIES\n");
            }
        }
        else
        {
            &utlLog(0, "Fail to link\n");    
        }
        last if ($state == $curState);
    }
    &setIni(\%ini, "state", $state) if ($opt{update});
    &setIni(\%ini, "link", $link);
    &writeIniFile(\%ini) unless ($opt{simulate});
    system("date/T >>" . $FileLog);
    system("time/T >>" . $FileLog);
    $plink_end = time;
    $Current_time = time;
    system("echo T_E,Plink,P,$Current_time >> $optPathMust{dirSave}/PlinkTime.log");
    if ($ENV{MBIS_BUILD_TIME_TMP} =~ /mbis/)
    {
    	system("echo T_S,Plink,P,$plink_start >> $ENV{MBIS_BUILD_TIME_TMP}");
    	system("echo T_E,Plink,P,$plink_end >> $ENV{MBIS_BUILD_TIME_TMP}");
    }
    return $ret;
}

# -----------------------------------------------------------------------------

exit &main($_argc, \@_argv);
