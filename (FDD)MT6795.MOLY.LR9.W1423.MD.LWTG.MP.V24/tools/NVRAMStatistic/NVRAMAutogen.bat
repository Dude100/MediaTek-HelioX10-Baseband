@echo off
path ..\..\tools;..\..\..\tools;..\..\..\Tools\MSYS\bin;..\..\..\..\Tools\MSYS\bin;..\..\Tools\MinGW\bin;..\..\..\Tools\MinGW\bin;..\..\..\tools\MinGW\lib\gcc-lib\mingw32\3.3.1;..\debug;.\debug;..\..\..\Tools;%path%;
if  .%1==.  goto NVRAM_AUTO_GEN_ERROR_1

if %WISDOM_CUSTOM_BUILD%INTERNAL==INTERNAL set WISDOM_CUSTOM_BUILD=FALSE

if %WISDOM_CUSTOM_BUILD%==TRUE (set MSYS_FOLDER=MSYS_WISDOM) else set MSYS_FOLDER=MSYS
if %WISDOM_CUSTOM_BUILD%==TRUE (if not exist tools\%MSYS_FOLDER% (if exist tools\MSYS (rename tools\MSYS %MSYS_FOLDER%)))

SET NVRAM_AUTO_GEN_PATH=..\..\%7\..\nvram_auto_gen
SET NVRAM_DEBUG_PATH=%NVRAM_AUTO_GEN_PATH%\debug

echo %NVRAM_AUTO_GEN_PATH%

cd Tools\NVRAMStatistic
if not exist %NVRAM_AUTO_GEN_PATH%\debug mkdir %NVRAM_AUTO_GEN_PATH%\debug
cd src

SET ERROR_LOG=..\..\..\%7\log\nvram_gen.log
SET FULL_LOG=..\..\..\%7\log\nvram_gen_full_log.log
SET NVRAM_AUTO_GEN_PATH=..\..\..\%7\..\nvram_auto_gen
SET NVRAM_DEBUG_PATH=%NVRAM_AUTO_GEN_PATH%\debug
SET CKSYSDRV_PATH=..\..\..\%7\..\cksysdrv

echo %NVRAM_AUTO_GEN_PATH%

if not exist %NVRAM_AUTO_GEN_PATH% mkdir %NVRAM_AUTO_GEN_PATH%
if not exist %CKSYSDRV_PATH% mkdir %CKSYSDRV_PATH%

if exist %ERROR_LOG% del %ERROR_LOG%
if exist %FULL_LOG% del %FULL_LOG%

if exist %NVRAM_DEBUG_PATH%\*.d del %NVRAM_DEBUG_PATH%\*.d
if exist %NVRAM_DEBUG_PATH%\nvram_auto_gen.dep del %NVRAM_DEBUG_PATH%\nvram_auto_gen.dep

echo Parameter 1 = %1 >> %FULL_LOG%
echo Parameter 2 = %2 >> %FULL_LOG%
echo Parameter 3 = %3 >> %FULL_LOG%
echo Parameter 4 = %4 >> %FULL_LOG%
echo Parameter 5 = %5 >> %FULL_LOG%
echo Parameter 6 = %6 >> %FULL_LOG%
echo Parameter 7 = %7 >> %FULL_LOG%

echo ************************************************************ >> %FULL_LOG%
echo ************* Start to Generate NVRAM Info ***************** >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
echo [NVRAM Auto Gen]

if .%5==.VENDOR (
  if .%6==.TRUE goto VDR
)
if .%5==.LEVEL2_OBJ (
  if not .%6==.FALSE goto SRC
)
if exist %NVRAM_DEBUG_PATH%\nvram_data_items.o del %NVRAM_DEBUG_PATH%\nvram_data_items.o
:SRC
if not .%5==. (echo LEVEL = %5 >> ..\..\%7\..\nvram_auto_gen\include\custom_option.txt)
if not .%6==. (echo CUSTOM_RELEASE = %6 >> ..\..\%7\..\nvram_auto_gen\include\custom_option.txt)
if exist %NVRAM_DEBUG_PATH%\nvram_auto_gen.exe    del %NVRAM_DEBUG_PATH%\nvram_auto_gen.exe
if exist %NVRAM_DEBUG_PATH%\mmi_cache_gen.exe     del %NVRAM_DEBUG_PATH%\mmi_cache_gen.exe
if exist %NVRAM_DEBUG_PATH%\nvram_common_config.o del %NVRAM_DEBUG_PATH%\nvram_common_config.o
if exist %NVRAM_DEBUG_PATH%\nvram_cust_pack.o     del %NVRAM_DEBUG_PATH%\nvram_cust_pack.o
if exist %NVRAM_DEBUG_PATH%\nvram_gen_util.o      del %NVRAM_DEBUG_PATH%\nvram_gen_util.o
:VDR
if not .%5==. (echo LEVEL = %5 >> ..\..\%7\..\nvram_auto_gen\include\custom_option.txt)
if not .%6==. (echo CUSTOM_RELEASE = %6 >> ..\..\%7\..\nvram_auto_gen\include\custom_option.txt)
if exist %NVRAM_DEBUG_PATH%\nvram_auto_gen.exe    del %NVRAM_DEBUG_PATH%\nvram_auto_gen.exe
if exist %NVRAM_DEBUG_PATH%\mmi_cache_gen.exe     del %NVRAM_DEBUG_PATH%\mmi_cache_gen.exe
if exist %NVRAM_DEBUG_PATH%\nvram_user_config.o   del %NVRAM_DEBUG_PATH%\nvram_user_config.o

if exist %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h   del %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
if exist %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h   copy %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h

echo #ifndef NVRAM_AUTO_GEN                    >      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo #error NVRAM AUTO GEN not executed       >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo generate nvram_lid_statistics.h success >> %FULL_LOG%

echo #ifndef NVRAM_LID_STATISTIC_H             >      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #define NVRAM_LID_STATISTIC_H            >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #ifndef NVRAM_NOT_PRESENT                >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #ifndef NVRAM_AUTO_GEN                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #ifndef __RESOURCE_GEN_                  >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #ifndef GEN_FOR_PC                       >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #error "nvram_auto_gen fail!"            >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #define NVRAM_OTP_SIZE    10             >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #define NVRAM_OTP_TOTAL   1              >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #define NVRAM_CUSTPACK_TOTAL  13         >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #define NVRAM_SECUPACK_SIZE  973         >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h
echo #endif                                   >>      %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h

echo generate nvram_lid_statistics_bak.h success >> %FULL_LOG%

rem Always generate nvram_gen_trc.h to avoid nvram auto gen false alarm due to codegen fail
if exist %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h   del %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h
echo typedef enum {                     >>      %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h
echo    _NVRAM_EF_SYS_LID = 0,          >>      %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h  
echo    NVRAM_TRC_LID_TOTAL             >>      %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h 
echo }nvram_trc_lid_enum;               >>      %NVRAM_AUTO_GEN_PATH%\nvram_gen_trc.h 

echo generate nvram_gen_trc.h success >> %FULL_LOG%


rem Modify custom\common\hal\nvram\nvram_cust_pack.c to avoid include nvram_cuspack_table.c in AUTO gen stage
echo *********************************************************** >> %FULL_LOG%
echo ********  Generate fake nvram_custpack_table.c      ******* >> %FULL_LOG%
echo *********************************************************** >> %FULL_LOG%


rem :jump_sp_1
rem if not exist %3\operator_mmi_cache_config.c goto gen_op
rem echo #include "operator_mmi_cache_config.c" > operator_mmi_cache_wrapper.c
rem goto make_nvram
rem 
rem :gen_op
rem echo ************************************************************ >> %FULL_LOG%
rem echo ******************  Gen operator config file *************** >> %FULL_LOG%
rem echo ************************************************************ >> %FULL_LOG%
rem echo #include "nvram_mmi_cache_defs.h"         >      operator_mmi_cache_wrapper.c
rem echo #ifndef NVRAM_AUTO_GEN                   >>      operator_mmi_cache_wrapper.c
rem echo #error "nvram_auto_gen fail!"            >>      operator_mmi_cache_wrapper.c
rem echo #endif                                   >>      operator_mmi_cache_wrapper.c
rem if %4 == 1 goto jump_sp_2
rem echo mmi_cache_byte_entry operator_mmi_cache_byte[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, "", "" ,"", "" ,""}}; >> operator_mmi_cache_wrapper.c
rem echo mmi_cache_short_entry operator_mmi_cache_short[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, 0xFF, "", "", "", "", "", ""}}; >> operator_mmi_cache_wrapper.c
rem echo mmi_cache_double_entry operator_mmi_cache_double[] = {{0xFF, NVRAM_APP_RESERVED, NVRAM_CACHE_ID_RESERVED, KAL_FALSE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, "", "", "", "", "", "", "", "", "", "", "", ""}}; >> operator_mmi_cache_wrapper.c
rem 
rem echo generate operator_mmi_cache_wrapper.c success >> %FULL_LOG%

:jump_sp_2

:make_mmi_cache
echo     [mmi_cache_gen]
echo ************************************************************ >> %FULL_LOG%
echo ******************  Build mmi_cache_gen.exe   ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
..\..\%MSYS_FOLDER%\bin\make -s -j 1 mmi_cache_gen 1>>%FULL_LOG% 2>>%ERROR_LOG%
type %ERROR_LOG% >> %FULL_LOG%
if not exist %NVRAM_DEBUG_PATH%\mmi_cache_gen.exe goto NVRAM_AUTO_GEN_ERROR_2

:execute_mmi_cache
echo ************************************************************ >> %FULL_LOG%
echo ******************  Execute mmi_cache_gen.exe ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
%NVRAM_DEBUG_PATH%\mmi_cache_gen.exe %1 %2 %NVRAM_AUTO_GEN_PATH% 1>>%FULL_LOG% 2>>%ERROR_LOG%  
if %errorlevel% EQU 0 (
	type %ERROR_LOG% >> %FULL_LOG%
	echo execute mmi_cache_gen done >> %FULL_LOG%
) else (
	type %ERROR_LOG% >> %FULL_LOG%
	goto NVRAM_AUTO_GEN_ERROR_2
)

:make_nvram
echo     [nvram_auto_gen]
echo ************************************************************ >> %FULL_LOG%
echo ******************  Build nvram_auto_gen.exe   ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
..\..\%MSYS_FOLDER%\bin\make -s -j 1 nvram_auto_gen NVRAM_DEBUG_PATH=%NVRAM_DEBUG_PATH% 1>>%FULL_LOG% 2>>%ERROR_LOG%
type %ERROR_LOG% >> %FULL_LOG%
if not exist %NVRAM_DEBUG_PATH%\nvram_auto_gen.exe goto NVRAM_AUTO_GEN_ERROR_2

if exist %NVRAM_DEBUG_PATH%\fs_quota_entry_dump.o del %NVRAM_DEBUG_PATH%\fs_quota_entry_dump.o
if exist %NVRAM_DEBUG_PATH%\fs_quota_entry_dump.exe del %NVRAM_DEBUG_PATH%\fs_quota_entry_dump.exe

:execute_nvram
echo ************************************************************ >> %FULL_LOG%
echo ******************  Execute nvram_auto_gen.exe ************* >> %FULL_LOG%
echo ************************************************************ >> %FULL_LOG%
%NVRAM_DEBUG_PATH%\nvram_auto_gen.exe %1 %2 %NVRAM_AUTO_GEN_PATH% 1>>%FULL_LOG% 2>>%ERROR_LOG%  
if %errorlevel% EQU 0 (
	type %ERROR_LOG% >> %FULL_LOG%
	echo execute nvram_auto_gen done >> %FULL_LOG%
	del %ERROR_LOG%
) else (
	type %ERROR_LOG% >> %FULL_LOG%
	goto NVRAM_AUTO_GEN_ERROR_2
)

echo     [fs_quota_entry_dump]


rem if exist ..\..\..\%7\log\fs_quota_entry_dump.log del ..\..\..\%7\log\fs_quota_entry_dump.log
rem ..\..\%MSYS_FOLDER%\bin\make -s -j 1 fs_quota_entry_dump 2> ..\..\..\%7\log\fs_quota_entry_dump.log

rem if not exist %NVRAM_DEBUG_PATH%\fs_quota_entry_dump.exe goto FS_QUOTA_GEN_ERROR_1
rem fs_quota_entry_dump.exe

if %errorlevel% EQU 2 (
	goto FS_QUOTA_GEN_ERROR_2
)

rem ************************************************************
rem ************* Both Procedure finished      *****************
rem ************************************************************
perl ..\..\pack_dep_gcc.pl %NVRAM_DEBUG_PATH%\nvram_auto_gen.dep %NVRAM_DEBUG_PATH% tools\NVRAMStatistic\src
cd ..\..\..\

echo --
echo Complete!!
goto done

rem ************************************************************
rem ************** Error Handling and Messages *****************
rem ************************************************************
:NVRAM_AUTO_GEN_ERROR_1
copy %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo Miss arguments!
goto NVRAM_AUTO_GEN_ERROR

:NVRAM_AUTO_GEN_ERROR_2
copy %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo NVRAM_AUTO_GEN_ERROR_2 >> %FULL_LOG%
echo Error in NVRAM Generating Process!!
echo Please Check nvram_gen_full_log.log!!
type %FULL_LOG%
cd ..\..\..\
:NVRAM_AUTO_GEN_ERROR
exit 3

:NVRAM_COMPRESS_ERROR
copy %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics_bak.h %NVRAM_AUTO_GEN_PATH%\nvram_lid_statistics.h
echo NVRAM_COMPRESS_ERROR >> %FULL_LOG%
exit 3

:FS_QUOTA_GEN_ERROR_1
cd ..\..\..\
echo Error in FS_QUOTA Generating Process!!
echo Please Check fs_quota_entry_dump.log!!
type .\%7\log\fs_quota_entry_dump.log
exit 3

:FS_QUOTA_GEN_ERROR_2
cd ..\..\..\
echo Please set APP_STORAGE_IN_SYS_DRV as TRUE for those projects which disable phone drive! >> %FULL_LOG%
echo Error in compile option dependency check!!
echo Error in compile option dependency check!! >> %FULL_LOG%
exit 3

:done
exit 0
