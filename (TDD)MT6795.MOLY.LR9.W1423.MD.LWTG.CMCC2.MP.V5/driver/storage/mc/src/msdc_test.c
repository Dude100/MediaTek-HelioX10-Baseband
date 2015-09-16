/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 * msdc_test.c
 *
 * Project:
 * --------
 *   MT6268ADVT
 *
 * Description:
 * ------------
 *   This file is used when doing msdc dvt, when enable __MSDC_BASIC_LOAD__, functions here will replace ssdbg1_main.
 *   The target of this file is to merge as many DVT loads into single test load as possible.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"      
#include "drv_features.h"
#if (defined( __MSDC_BASIC_LOAD__) || defined(DRV_MSDC_BT)) //this should be defined as global option, without this option, this file won't be compiled
#include "stack_common.h"
#include "stack_msgs.h"
#include "app_ltlcom.h"       /* Task message communiction */
#include "kal_public_api.h"
//guilin #include "tst_ltlcom.h"
#include "kal_debug.h"
#include "syscomp_config.h"
#include "task_config.h"      /* Task creation */
#include "cache_sw.h"
#include "stacklib.h"         /* Basic type for dll, evshed, stacktimer */

#include "event_shed.h"       /* Event scheduler */

#include "stack_timer.h"      /* Stack timer */

#include "string.h"
#include "uart_sw.h"

#include "stack_timer.h"      /* Stack timer */

#include <stdlib.h>

#include "stdio.h"
#include "uart_sw.h"
#include "fat_fs.h"
#include "msdc_def.h"
#include "sd_def.h"


#include "fs_gprot.h"
#include "config_hw.h"
#include "intrCtrl.h"

#include "dma_hw.h"
#include "dma_sw.h"

#include "pwic.h"

#include "dcl.h"
#include "dcl_msdc.h"
#include "eint.h"

//extern void srand(unsigned int seed);
//extern int rand(void);


#ifdef __CLKG_DEFINE__
#ifdef DRVPDN_CON1
#error "__CLKG_DEFINE__ & DRVPDN_CON1 are all defined"
#else
#define DRVPDN_CON1		CG_CON1
#endif

#ifdef DRVPDN_CON0
#error "__CLKG_DEFINE__ & DRVPDN_CON0 are all defined"
#else
#define DRVPDN_CON0		CG_CON0
#endif

#ifdef DRVPDN_CON1_MSDC
#error "__CLKG_DEFINE__ & DRVPDN_CON1_MSDC are all defined"
#else
#define DRVPDN_CON1_MSDC	CG_CON1_MSDC
#endif

#ifdef DRVPDN_CON0_MSDC2
#error "__CLKG_DEFINE__ & DRVPDN_CON0_MSDC2 are all defined"
#else
#define DRVPDN_CON0_MSDC2	CG_CON0_MSDC2
#endif

#ifdef DRVPDN_CON1_CLR
#error "__CLKG_DEFINE__ & DRVPDN_CON1_CLR are all defined"
#else
#define DRVPDN_CON1_CLR	CG_CLR1
#endif

#ifdef DRVPDN_CON1_SET
#error "__CLKG_DEFINE__ & DRVPDN_CON1_SET are all defined"
#else
#define DRVPDN_CON1_SET	CG_SET1
#endif
#endif


#define MSDC_DVT
#ifdef MSDC_DVT

#ifdef __MSDC_BASIC_LOAD__
typedef struct ssdbg1_context_struct_t
{
    stack_timer_struct  ssdbg1_timer0;
    stack_timer_struct  ssdbg1_base_timer;
    event_scheduler     *ssdbg1_event_scheduler_ptr;
    eventid             ssdbg1_event_id;
} ssdbg1_context_struct_t;

extern ssdbg1_context_struct_t ssdbg1_context;

typedef struct ssdbg2_context_struct_t
{
    stack_timer_struct  ssdbg2_timer0;

    stack_timer_struct  ssdbg2_base_timer;
    event_scheduler     *ssdbg2_event_scheduler_ptr;
    eventid             ssdbg2_event_id;
} ssdbg2_context_struct_t;

extern ssdbg2_context_struct_t ssdbg2_context;


typedef struct
{
    LOCAL_PARA_HDR
    kal_uint32 id;
} ssdbg1_localpara_struct;


#endif

#define LEN		32*1024
//#define LEN		512*1024
#define TIMES  100
//static kal_uint8 MyTxbuf[LEN];
//static kal_uint8 MyRxbuf[LEN];
//static kal_uint8 buffer[1024*8];
//static kal_uint32 fcount = 0;
#define BYTES_PER_ACCESS		17839
//#define WRITE_TEST
//#define CACHED_TEST

//#define NOT_4BYTES_ALIGN

__align(4) kal_uint8 r[LEN + 3], w[LEN + 3], w1[LEN + 3], r2[LEN + 3], w2[LEN + 3];

volatile kal_bool check_read_content = KAL_TRUE;
double	bestReadThroughput, worstReadThroughput, bestWriteThroughput, worstWriteThroughput;

#ifdef CACHED_TEST
kal_bool	cachedTest;
double	cachedBestReadThroughput, cachedWorstReadThroughput, cachedBestWriteThroughput, cachedWorstWriteThroughput;
#pragma arm section zidata = "CACHEDZI"
__align(4) kal_uint8 cached_r[LEN + 3], cached_w[LEN + 3];
#pragma arm section zidata
#endif

#ifdef __MSDC_BASIC_LOAD__
#define TESTBLNUMMAX 1024


kal_int32 testblnum = 32;
#define TESTLOOP 1
#define ADDREND 100
#define ADDREND2 (ADDREND*10)


//
// For each project, config gpio setting at first.
//
#ifdef MT6250
#define CMDGPIO 32
#define DATGPIO 31
#endif
#ifdef MT6255
#define CMDGPIO 86
#define DATGPIO 87
#endif
#ifdef MT6280
#define CMDGPIO 61
#define DATGPIO 62
#endif

#define CLKSRCNUM 4 // 0~3
#define SCLKFNUM 4 // 0~3,255

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
kal_uint32 msdc_sector_buf1[128] = {0};
kal_uint32 msdc_sector_buf2[128] = {0};
kal_uint32 msdc_sector_buf3[128] = {0};
kal_uint8 MSDC_Sector_guilin81[129 * 4] = {0};
kal_uint8 MSDC_Sector_guilin82[129 * 4] = {0};

kal_uint32	msdc_uncachedBuf1[TESTBLNUMMAX * 512 / 4];
kal_uint32	msdc_uncachedBuf2[TESTBLNUMMAX * 512 / 4];
#pragma arm section zidata, rwdata

kal_uint32 cachemsdc_sector_buf1[128] = {0};
kal_uint32 cachemsdc_sector_buf2[128] = {0};
kal_uint32 cachemsdc_uncachedBuf1[TESTBLNUMMAX * 512 / 4];
kal_uint32 cachemsdc_uncachedBuf2[TESTBLNUMMAX * 512 / 4];

extern kal_bool MSDC_useDMA4ByteBurst;
kal_uint32 test_clksrc;
kal_uint32 test_sclkf;
kal_uint32 testsectors;
kal_uint32 gspeed = 0;

typedef struct
{
    kal_int32 bit14;
    kal_int32 isread1;
    kal_int32 clksrc;
    kal_int32 sclkf;
    kal_int32 clock;
    kal_int32 addr;
    kal_int32 blnum;
    kal_int32 speed;
} CLKTEST;

CLKTEST test_statistic[1000];


#define ESCKEY (0x1b)

void msdc_dbg_print(char *fmt, ...);
void msdc_dbg_input(kal_uint32 *value);
void guilin_sleep(kal_uint32 x);
#endif

void dummyFunction(void) {}

#if defined(MSDC_SDIO_DVT) || defined(MSDC2_SDIO_DVT)
kal_bool waitingSDIOTest = KAL_TRUE;/*if SDIO test is doing, we have to make both task wait for SDIO test done*/
#else
kal_bool waitingSDIOTest = KAL_FALSE;
#endif

#ifdef MSDC2_SDIO_DVT
extern MSDC_HANDLE *msdc2_handle ;
#endif

#ifdef __MSDC_BASIC_LOAD__
/*
#if 1
void MSDC_DVT_readWrite(void)
{
    kal_int32 status;

    dbg_print("[%s %d]\r\n",__FUNCTION__,__LINE__);
    gMSDC_Handle->mIsInitMSDC = KAL_FALSE;
    gMSDC_Handle->mIsInitialized = KAL_FALSE;
    //MSDC_Initialize();
    //status=SD_Initialize();
    status = DclSD_Initialize();
    dbg_print("[%s %d]SD_Initialize=%d \r\n",__FUNCTION__,__LINE__,status);
    //status = MountDevice_NEW(&MSDC_Blk[0], 0, 0, 0);
    //dbg_print("[%s %d]MountDevice_NEW=%d \r\n",__FUNCTION__,__LINE__,status);
    status = SD_Initialize();
    //MSDC_PDNControl(0);


}
#else
void MSDC_DVT_readWrite(void)
{



#ifdef MULTIPLE_WRITE_TEST
	gMSDC_Handle->mIsPresent = KAL_TRUE;
	simple_multi_write_test();
	return;
#endif




	kal_int32 i,j, result = 0, count = 0;
	kal_uint32 access = 17893;
	FS_HANDLE hFile=0, wFile = 0;
	kal_wchar full_name[100];
	kal_uint32  file_size,len,total_len;
	kal_uint32 time_1,time_2;
	double rate;
	volatile kal_bool format = 0;
	kal_uint8 offset1 = 0,offset2 = 0;
	kal_uint32 timeUsedinFS;
	 int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

	kal_uint32	testTimes = 0;



	result = FS_TestMSDC(gMSDC_Handle);
	if(result < FS_NO_ERROR){
		dbg_print("memory card card not present %d !!\r\n", result);
		return;
        	while(1)
        		kal_sleep_task(1000);
	}

	card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);
            if (result < RTF_NO_ERROR)
            {
            	ASSERT(0);
            }


        }
        else{
        	dbg_print("memory card card not present!!\r\n");
        	return;
        	while(1)
        		kal_sleep_task(1000);
        }

#ifdef HW_FAST_FORMAT_TEST
	while(1){
		time_1 = drv_get_current_time();
		result = FS_GeneralFormat((WCHAR*) path, FS_FORMAT_HIGH, NULL);
		if(FS_NO_ERROR == result){
			time_2 = drv_get_current_time();
			dbg_print("format done %d, %f\n\r", time_2 - time_1, (double)(0.0005 * writeSectorsCount * 32000)/(double)(writeTimeCount));
			writeSectorsCount = writeTimeCount = 0;
			kal_sleep_task(1500);
		}
		else{
			dbg_print("format failed: %d \n\r", result);
			while(1)
        			kal_sleep_task(1000);

		}
	}
#endif
	//DumpDiskInfo("d:\\");
	kal_wsprintf(full_name, "%c:\\Write.bin", card);
	for(i=0;i<LEN+3;i++)
	{
		w[i+offset1] = i%256;
		r[i+offset2] = 0;

#ifdef	CACHED_TEST
		cached_w[i+offset1] = i%256;
		cached_r[i+offset2] = 0;
#endif

	}

#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif


	while(1){


#if 1//write

		count++;
		//Search_Dir(L"C:\\");
		FS_Delete(full_name);
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				cachedTest = KAL_FALSE;
			else
				cachedTest = KAL_TRUE;

			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n===========Cached Write Test Start(%d) ====================\r\n",count);
			else
#endif
		dbg_print("\r\n==================Write Test Start(%d) ====================\r\n",count);

		hFile = FS_Open(full_name, FS_CREATE|FS_READ_WRITE);
		if(hFile <= 0){
			dbg_print("open file failed \r\n");
			return ;
		}
		//ASSERT(hFile>0);

#if defined(NOT_4BYTES_ALIGN)
		// test W to B or B to W(DMA)
		offset1 = (kal_uint32)w % 4;
		if(offset1 == 0)
			offset1 = 1;
		else
			offset1 = 0;

		offset2 = (kal_uint32)r % 4;
		if(offset2 == 0)
			offset2 = 1;
		else
			offset2 = 0;
		for(i=0;i<LEN+3;i++)
		{
			w[i+offset1] = i%256;
			r[i+offset2] = 0;
		}
#endif
		i = 0;
		total_len = 0;

		kal_get_time(&time_1);
		//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2 = 0;
		//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
		while(1)
		{

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Write(hFile,cached_w+offset1,LEN,&len);
			else
#endif
			result = FS_Write(hFile,w+offset1,LEN,&len);
			total_len += len;
			i++;
			if(result < 0 ){
				if(result == RTF_DISK_FULL){
					dbg_print("Disk Full %d\r\n", total_len);
					FS_Close(hFile);
					return;
				}
				else{
					dbg_print("write fail %d at: %d \r\n",result, total_len);
					FS_Close(hFile);
					return;

					break;
				}
			}
			if(len != LEN){
				dbg_print("write length not correct \r\n");
				FS_Close(hFile);
				return;
			}
			if(i%TIMES == 0)
			{
				kal_get_time(&time_2);
			   rate = (double)(LEN*TIMES)/(double)(time_2-time_1);
				dbg_print("write[%d], total: %d, rate %f \r\n", i, total_len,rate/0.004615);
				//dbg_print("%d, %d, %d , %d\r\n", writeTime3 , writeTime4 , writeTime5,writeTime6);
				//readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2= 0;
				//writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestWriteThroughput || 0 == cachedBestWriteThroughput)
					cachedBestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstWriteThroughput || 0 == cachedWorstWriteThroughput)
					cachedWorstWriteThroughput = (rate/0.004615);
			}
			else
#endif
			{
				if((rate/0.004615) > bestWriteThroughput || 0 == bestWriteThroughput)
					bestWriteThroughput = (rate/0.004615);
				if((rate/0.004615) < worstWriteThroughput || 0 == worstWriteThroughput)
					worstWriteThroughput = (rate/0.004615);
			}

				kal_get_time(&time_1);


				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestWriteThroughput, cachedWorstWriteThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);

		dbg_print("\r\n==================Write Test End(%d) ====================\r\n",count);
#endif //write

#if 1 // read test

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				dbg_print("\r\n==========Cached Read Test Start(%d) ====================\r\n",count);
			else
#endif
		dbg_print("\r\n==================Read Test Start(%d) ====================\r\n",count);

		timeUsedinFS = 0;
		i = 0;
		total_len = 0;
		hFile = FS_Open(full_name, FS_READ_WRITE);
		if(hFile <= 0){
			dbg_print("FS open failed\r\n");
			return;
		}

		ASSERT(hFile>0);

		while(1){
			kal_get_time(&time_1);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				result = FS_Read(hFile,cached_r +offset1,LEN,&len);
			else
#endif
			result = FS_Read(hFile,r+offset2,LEN,&len);

			kal_get_time(&time_2);
			timeUsedinFS += (time_2 - time_1);
			i++;
			total_len += len;

			if(check_read_content)
			{
#ifdef	CACHED_TEST
				if(KAL_TRUE == cachedTest){
					for(j=0;j<len;j++){
						if(cached_r[j+offset2] != cached_w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							while(1);
						}

					}
				}
				else
#endif
				{
					for(j=0;j<len;j++){
						if(r[j+offset2] != w[j+offset1])
						{
							dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);
							FS_Close(hFile);
							return;
						}

					}
				}
				dbg_print(".");
#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest)
				memset(cached_r,0,sizeof(cached_r));
			else
#endif
				memset(r,0,sizeof(r));
			}
			if(result < 0){
				if(result != RTF_DISK_FULL){
					dbg_print("read fail %d, at: %d \r\n", result, total_len);
					FS_Close(hFile);
					return;
				}
				else{
					dbg_print("Disk Full \r\n");
					FS_Close(hFile);
					return;
				}
			}
			if(len != LEN){
				dbg_print("length not correct \r\n");
				FS_Close(hFile);
				return;
			}
			if(i%TIMES == 0){

			   rate = (double)(LEN*TIMES)/(double)timeUsedinFS;
				dbg_print("read[%d], total: %d, rate: %f \r\n", i, total_len,rate/0.004615);

#ifdef	CACHED_TEST
			if(KAL_TRUE == cachedTest){
				if((rate/0.004615) > cachedBestReadThroughput || 0 == cachedBestReadThroughput)
					cachedBestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < cachedWorstReadThroughput || 0 == cachedWorstReadThroughput)
					cachedWorstReadThroughput = (rate/0.004615);
			}
			else
#endif
			{
				if((rate/0.004615) > bestReadThroughput || 0 == bestReadThroughput)
					bestReadThroughput = (rate/0.004615);
				if((rate/0.004615) < worstReadThroughput || 0 == worstReadThroughput)
					worstReadThroughput = (rate/0.004615);
			}

				timeUsedinFS = 0;
				if(i == TIMES*5) break;
			}
		}
		FS_Close(hFile);

#ifdef	CACHED_TEST
		if(KAL_TRUE == cachedTest)
			dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestReadThroughput, cachedWorstReadThroughput);
		else
#endif
		dbg_print("\r\nbest: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);

		dbg_print("\r\n==================Read Test End(%d) ====================\r\n",count);
		FS_Delete(full_name);
#endif  // read test

		testTimes ++;
		if(5 == testTimes)
			return;
	}
   //=======================================//
}
#endif
*/

typedef struct
{
    kal_char name[16];
    kal_uint32 addr;
    kal_uint32 defval;
} REGTEST;

REGTEST regbuf[] =
{
    {"MSDC_CFG      ", MSDC_CFG, 0x04000020},
    {"MSDC_STA      ", MSDC_STA, 2},
    {"MSDC_INT      ", MSDC_INTR, 0},
    {"MSDC_PS       ", MSDC_PS, 0x01ff0008},

    {"MSDC_DAT      ", MSDC_DAT, 0xffffffff},
    {"MSDC_IOCON0   ", MSDC_IOCON, 0x010000c3},
    {"MSDC_IOCON1   ", MSDC_IOCON1, 0x00022022},

    {"SDC_CFG       ", SDC_CFG, 0x8000},
    {"SDC_CMD       ", SDC_CMD, 0},
    {"SDC_ARG       ", SDC_ARG, 0xffffffff},
    {"SDC_STA       ", SDC_STA, 0x8000},

    {"SDC_RESP0     ", SDC_RESP0, 0xffffffff},
    {"SDC_RESP1     ", SDC_RESP1, 0xffffffff},
    {"SDC_RESP2     ", SDC_RESP2, 0xffffffff},
    {"SDC_RESP3     ", SDC_RESP3, 0xffffffff},

    {"SDC_CMDSTA    ", SDC_CMDSTA, 0},
    {"SDC_DATSTA    ", SDC_DATSTA, 0},
    {"SDC_CSTA      ", SDC_CSTA, 0},
    {"SDC_IRQMASK0  ", SDC_IRQMASK0, 0},
    {"SDC_IRQMASK1  ", SDC_IRQMASK1, 0},

#if defined(__MSDC_SD_SDIO__)
    //{"SDIO_CFG      ",SDIO_CFG,0},
    //{"SDIO_STA      ",SDIO_STA,0},
#endif

    {"BOOT_CFG      ", MSDC_BOOT_CFG, 0},
    {"BOOT_STA      ", MSDC_BOOT_STA, 0},

    {"CLKACB_CFG    ", MSDC_CLKACB_CFG, 0x00020000},
#ifdef MT6255
    {"CLKACB_STA    ", MSDC_CLKACB_STA, 0x00020000},
    {"CLKACB_CRCSTA1", MSDC_CLKACB_CRCSTA1, 0x00020000},
    {"CLKACB_CRCSTA2", MSDC_CLKACB_CRCSTA2, 0x00020000},
#endif
};

kal_int32 sdtestgpio(void)
{
    DCL_HANDLE handle;
    int x;
    handle = DclGPIO_Open(DCL_GPIO, 10); // GPIO10
    DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
    DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);

    for (x = 100; x; x--)
    {
        DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
    }

    DclGPIO_Close(handle);

}

kal_int32 sdtestgpio2(void)
{
    kal_uint8 buf[30], input, offset;
    kal_int32 value, x;
    DCL_HANDLE handle;

    memset(buf, 0, sizeof(buf));
    msdc_dbg_print("input(GPIO)(ESC:exit):");
    offset = 0;

    while (1)
    {
        input = U_GetUARTByte(uart_port1);

        if (input >= '0' && input <= '9')
        {
            //input -= '0';
        }
        else if (input == 0x0d || input == 0x0a)
        {
            break;
        }
        else if (input == ESCKEY) //esc
        {
            return;
        }
        else
        {
            continue;
        }

        buf[offset++] = input;
        dbg_print("%c", input);
    }

    buf[30 - 1] = 0;
    value = -1;
    dbg_print("\r\n");
    sscanf(buf, "%d", &value);

    if (value >= 0)
    {
        handle = DclGPIO_Open(DCL_GPIO, value); // GPIO10
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_OUT, 0);
        DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        msdc_dbg_print("[%s %d]gpio=%d \r\n", __FUNCTION__, __LINE__, value);

        for (x = 1000000; x; x--)
        {
            DclGPIO_Control(handle, GPIO_CMD_WRITE_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_WRITE_LOW, 0);
        }

        DclGPIO_Close(handle);
    }


}



SDC_CMD_STATUS SD_ReadSingleBlock_MCU(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    kal_uint32 count, whileIndex;
    SDC_CMD_STATUS status;
    kal_uint32 value;

    count = MSDC_SD_BLOCK_SIZE;

#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif

    RESET_MSDC();

    if ((status = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        goto ERR_Exit;

    whileIndex = 0;

    while (1)
    {
        if (!MSDC_IS_FIFO_EMPTY)
        {
            value = MSDC_Reg32(MSDC_DAT);

            if ((kal_uint32)rxbuffer % 4)
                kal_mem_cpy(rxbuffer + whileIndex, (const void*)&value, 4);
            else
                *(rxbuffer + whileIndex) = value;

            whileIndex++;

            if (whileIndex >= count)
                break;
        }
    }

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;

    MSDC_CLR_FIFO();

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                dbg_print("[MSDC]CMD13 fail when singleBlockRead!");
                msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif
    MSDC_CLR_FIFO();
    RESET_MSDC();
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        // SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
        return status;
    }

}

SDC_CMD_STATUS SD_ReadSingleBlock_MCU_datto(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    kal_uint32 count, whileIndex;
    SDC_CMD_STATUS status;
    kal_uint16 sdc_datsta;
    //    msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x",__FUNCTION__,__LINE__,data_adrs,rxbuffer);
    count = MSDC_SD_BLOCK_SIZE;
#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif
    {
        DCL_HANDLE handle;
        handle = DclGPIO_Open(DCL_GPIO, DATGPIO);
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
        DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
        DclGPIO_Close(handle);
        guilin_sleep(10);
    }

    if ((status = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        goto ERR_Exit;

    whileIndex = 0;

    while (1) //for(whileIndex=0;whileIndex<count;whileIndex++)
    {
        sdc_datsta = MSDC_Reg(SDC_DATSTA);
        gMSDC_Handle->dat_sta = sdc_datsta;

        if (sdc_datsta & SDC_DATSTA_DATTO)
        {
            msdc_dbg_print("[%s %d]ERROR,sdc_datsta=0x%x", __FUNCTION__, __LINE__, sdc_datsta);
            status = ERR_DAT_TIMEOUT;
            goto ERR_Exit;
        }
        else if (sdc_datsta & SDC_DATSTA_DATCRCERR)
        {
            status = ERR_DAT_CRCERR;
            goto ERR_Exit;
        }

        if (!MSDC_IS_FIFO_EMPTY )
        {
            *(rxbuffer + whileIndex) = MSDC_Reg32(MSDC_DAT);
            whileIndex++;

            if (whileIndex >= count)
                break;
        }
    }

    //if ((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
    //	goto ERR_Exit;

    MSDC_CLR_FIFO();

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                dbg_print("[MSDC]CMD13 fail when singleBlockRead!");
                msdc_dbg_print("[%s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif
    MSDC_CLR_FIFO();
    RESET_MSDC();
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        // SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        msdc_dbg_print("[%s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
        return status;
    }

}
SDC_CMD_STATUS SD_ReadSingleBlock_MCU_datcrc(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    kal_uint32 count, whileIndex;
    SDC_CMD_STATUS status;
    kal_uint16 sdc_datsta;
    //    msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x",__FUNCTION__,__LINE__,data_adrs,rxbuffer);
    count = MSDC_SD_BLOCK_SIZE;
#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif

    if ((status = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        goto ERR_Exit;

    whileIndex = 0;

    while (1) //for(whileIndex=0;whileIndex<count;whileIndex++)
    {
        sdc_datsta = MSDC_Reg(SDC_DATSTA);
        gMSDC_Handle->dat_sta = sdc_datsta;

        if (sdc_datsta & SDC_DATSTA_DATCRCERR)
        {
            msdc_dbg_print("[%s %d]ERROR,sdc_datsta=0x%x", __FUNCTION__, __LINE__, sdc_datsta);
            status = ERR_DAT_CRCERR;
            goto ERR_Exit;
        }
        else if (sdc_datsta & SDC_DATSTA_DATTO)
        {
            status = ERR_DAT_TIMEOUT;
            goto ERR_Exit;
        }

        if (!MSDC_IS_FIFO_EMPTY)
        {
            *(rxbuffer + whileIndex) = MSDC_Reg32(MSDC_DAT);
            whileIndex++;

            if (whileIndex >= count)
                break;
        }

        if (whileIndex == 100 )
        {
            DCL_HANDLE handle;
            handle = DclGPIO_Open(DCL_GPIO, DATGPIO);
            DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
            DclGPIO_Close(handle);
            guilin_sleep(10);
        }
        else if (whileIndex == 110 )
        {
            DCL_HANDLE handle;
            handle = DclGPIO_Open(DCL_GPIO, DATGPIO);
            DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
            DclGPIO_Close(handle);
            guilin_sleep(10);
        }

    }

    //	if ((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
    //		goto ERR_Exit;

    MSDC_CLR_FIFO();

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                dbg_print("[MSDC]CMD13 fail when singleBlockRead!");
                msdc_dbg_print("[%s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif
    MSDC_CLR_FIFO();
    RESET_MSDC();
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        // SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        msdc_dbg_print("[%s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
        return status;
    }

}
SDC_CMD_STATUS SD_ReadSingleBlock_MCU_cmdto(kal_uint32 data_adrs, kal_uint32* rxbuffer)
{
    kal_uint32 count, whileIndex;
    SDC_CMD_STATUS status;
    kal_uint16 sdc_datsta;
    //    msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x",__FUNCTION__,__LINE__,data_adrs,rxbuffer);
    count = MSDC_SD_BLOCK_SIZE;
#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)rxbuffer);
#endif
    {
        DCL_HANDLE handle;
        handle = DclGPIO_Open(DCL_GPIO, CMDGPIO);
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_0, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
        DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
        DclGPIO_Close(handle);
        guilin_sleep(10);
    }

    if ((status = SD_Send_Cmd(SDC_CMD_CMD17, data_adrs)) != NO_ERROR)
        goto ERR_Exit;

    whileIndex = 0;

    while (1) //for(whileIndex=0;whileIndex<count;whileIndex++)
    {
        if (!MSDC_IS_FIFO_EMPTY )
        {
            *(rxbuffer + whileIndex) = MSDC_Reg32(MSDC_DAT);
            whileIndex++;

            if (whileIndex >= count)
                break;
        }

        sdc_datsta = MSDC_Reg(SDC_DATSTA);
        gMSDC_Handle->dat_sta = sdc_datsta;

        if (sdc_datsta >> 1)
        {
            msdc_dbg_print("[guilin %s %d]ERROR,sdc_datsta=0x%x", __FUNCTION__, __LINE__, sdc_datsta);
            break;
        }

    }

    //	if((status = SD_WaitDatRdyOrTo())!=NO_ERROR)
    //		goto ERR_Exit;

    MSDC_CLR_FIFO();

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                dbg_print("[MSDC]CMD13 fail when singleBlockRead!");
                msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));
    }
#endif
    MSDC_CLR_FIFO();
    RESET_MSDC();
    return NO_ERROR;
ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        DisableMSDC_DMA();
        RESET_MSDC();

        // SD_StopTrans(KAL_FALSE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        MSDC_CLR_FIFO();
        msdc_dbg_print("[guilin %s %d]data_adrs=0x%x rxbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, data_adrs, rxbuffer, status);
        return status;
    }

}

SDC_CMD_STATUS SD_WriteSingleBlock_MCU(kal_uint32 address, kal_uint32* txbuffer)
{
    SDC_CMD_STATUS status;
    kal_uint32 count, whileIndex, value;
#ifdef DRV_MSDC_FORCE_WAIT_FOR_PROG_R1B_MALFUNCTION
    kal_uint32 cardStatus = 0;
    kal_uint32 t1 = 0;
#endif
    kal_uint32 *ptr;
#if defined(MT6225)
    kal_bool is_aligned;
    ECO_VERSION eco;
    eco = INT_ecoVersion();
#endif

#ifdef DRV_MSDC_2_DLT_FOR_RD_WR
    kal_uint32 triedDLTTimes = 0;

retryDLT:
#endif

    RESET_MSDC();
    MSDC_CLR_FIFO();

    if (gSD->mWPEnabled)
        return ERR_WRITE_PROTECT;

    count = MSDC_SD_BLOCK_SIZE;

#if defined(MT6225)

    if (eco <= ECO_E3)
    {
        is_aligned = ((kal_uint32)txbuffer % 4 == 0);

        if (is_aligned)
        {
            ptr = txbuffer;
        }
        else
        {
            kal_mem_cpy(MSDC_Sector, txbuffer, 512);
            ptr = MSDC_Sector;
        }
    }
    else
    {
        ptr = txbuffer;
    }

#else
    ptr = txbuffer;
#endif

#ifdef DRV_LSD
    LSD_HostSetBuffer((kal_uint8 *)txbuffer);
#endif

    if ((status = SD_Send_Cmd(SDC_CMD_CMD24, address)) != NO_ERROR)
        goto ERR_Exit;

    if ((status = SD_CheckStatus()) != NO_ERROR)
        goto ERR_Exit;

    whileIndex = 0;

    while (1)
    {
        if (!MSDC_IS_FIFO_FULL)
        {
            if ((kal_uint32)txbuffer % 4)
                kal_mem_cpy(&value, (txbuffer + whileIndex), 4);
            else
                value = *(txbuffer + whileIndex);

            MSDC_WriteReg32(MSDC_DAT, value);

            whileIndex++;

            if (whileIndex >= count)
                break;
        }
    }

    if ((status = SD_WaitCardNotBusy(MSDC_DATA_TIMEOUT)) != NO_ERROR)
        goto ERR_Exit;

    if ((status = SD_WaitDatRdyOrTo()) != NO_ERROR)
        goto ERR_Exit;

#ifdef SD_STOP_SLOW
    {
        kal_uint32 cardStatus;
        whileIndex = 0x40000;

        while (SD_IS_R1B_BUSY && whileIndex)
            whileIndex--;

        whileIndex = 0x100;

        do
        {
            status = SD_GetStatus(gSD->mRCA, (kal_uint32*)&cardStatus);

            if (NO_ERROR != status)
            {
                dbg_print("[MSDC]CMD13 fail when singleBlockWrite!");
                msdc_dbg_print("[guilin %s %d]ERROR address=0x%x txbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, address, txbuffer, status);
                goto ERR_Exit;
            }

            whileIndex--;
        }
        while (((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) && (0 != whileIndex));

        if ((cardStatus & R1_CUR_STATE) >> 9 !=  TRAN_STA) //guilin
        {
            msdc_dbg_print("[guilin %s %d]ERROR cardStatus=0x%x", __FUNCTION__, __LINE__, cardStatus);
            return ERR_CMD_TIMEOUT; //guilin
        }
    }
#endif

    MSDC_CLR_FIFO();
    RESET_MSDC();

    return NO_ERROR;

ERR_Exit:
    {
        kal_uint32 tmp;

#ifdef MSDC_USE_INT
        kal_set_eg_events(gMSDC_Handle->MSDC_Events, 0, KAL_AND);
#endif
        RESET_MSDC();
        //SD_StopTrans(KAL_TRUE);
        SD_GetStatus(gSD->mRCA, (kal_uint32*)&tmp);
        MSDC_LSD_ReadReg32(SDC_DATSTA, &tmp);
        msdc_dbg_print("[guilin %s %d]address=0x%x txbuffer=0x%x error=0x%x", __FUNCTION__, __LINE__, address, txbuffer, status);
        return status;
    }

}

// ==================================================================================
//
// Test Case 1. Mount
//
//
//
// ==================================================================================
kal_int32 sdtestcase1(void)
{
    kal_int32 status;

    msdc_dbg_print("\r\n[%s %d]mount test...\r\n", __FUNCTION__, __LINE__);

#ifdef MT6255
    {
        DCL_HANDLE handle;

        msdc_dbg_print("[%s %d]MT6255 GPIO init...", __FUNCTION__, __LINE__);
        handle = DclGPIO_Open(DCL_GPIO, 9); // GPIO9-MC1INS
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_3, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
        DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
        DclGPIO_Close(handle);
        handle = DclGPIO_Open(DCL_GPIO, 84); // GPIO84-MC1WP
        DclGPIO_Control(handle, GPIO_CMD_SET_MODE_2, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
        DclGPIO_Control(handle, GPIO_CMD_SET_PULL_LOW, 0);
        DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
        DclGPIO_Close(handle);

        kal_sleep_task(400);

    }
#endif


    gMSDC_Handle->mIsInitMSDC = KAL_FALSE;
    gMSDC_Handle->mIsInitialized = KAL_FALSE;
    gMSDC_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK / 2;

    DclSD_Initialize();

    //status = MountDevice_NEW(&MSDC_Blk[0], 0, 0, 0);
    status = SD_Initialize();

    testsectors = gSD->mCSD.capacity / 512;

    msdc_dbg_print("[%s %d]size(sectors) = %d ,%d MB\r\n", __FUNCTION__, __LINE__, testsectors, gSD->mCSD.capacity / (1024 * 1024));

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return status;
}

kal_int32 sdtestcase2(void)
{
    kal_int32 size, i;
    msdc_dbg_print("\r\n[%s %d]reg default test...", __FUNCTION__, __LINE__);
    size = sizeof(regbuf) / sizeof(REGTEST);

    for (i = 0; i < size; i++)
    {
        msdc_dbg_print("[%s,0x%08x,0x%08x]=0x%08x", regbuf[i].name, regbuf[i].addr, regbuf[i].defval, MSDC_Reg32(regbuf[i].addr));
    }
}


// ==================================================================================
//
// Test Case 3. Single block read test
//
//
//
// ==================================================================================
kal_int32 sdtestcase3(kal_int32 addr , kal_uint32 *pbufr)
{
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2;

    sdtestgpio();

    do
    {

        time1 = drv_get_current_time();

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock(addr, pbufr);
        else
            status = SD_ReadSingleBlock(addr * 512, pbufr);

        time2 = drv_get_current_time();

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR, SD_ReadSingleBlock, %d", __FUNCTION__, __LINE__, status);
            break;
        }

        if (time2 != time1)
            msdc_dbg_print("[%s %d]OK, SD_ReadSingleBlock, %5d KB/S,time=%d,addr=%d", __FUNCTION__, __LINE__, (1 * 32768 * 5) / ((time2 - time1) * 10), (time2 - time1), addr);
        else
            msdc_dbg_print("[%s %d]OK, SD_ReadSingleBlock, time=0,addr=%d", __FUNCTION__, __LINE__, addr);


    }
    while (0);

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);


    return status;
}



// ==================================================================================
//
// Test Case 4. Single block write test
//
//
//
// ==================================================================================
kal_int32 sdtestcase4(kal_int32 addr , kal_uint32 *pbufw , kal_uint32 *pbufr)
{
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2;
    kal_int32 i, compare_error;

    for (i = 0; i < 512; i++)
        //pbufw[i]=((i+10)<<0)|((i+11)<<8)|((i+12)<<16)|((i+13)<<24);
        *((kal_uint8 *)pbufw + i) = rand() % 256;

    sdtestgpio();

    do
    {

        time1 = drv_get_current_time();

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_WriteSingleBlock(addr, pbufw);
        else
            status = SD_WriteSingleBlock(addr * 512, pbufw);

        time2 = drv_get_current_time();

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR, SD_WriteSingleBlock, %d", __FUNCTION__, __LINE__, status);
            break;
        }

        // readback compare
        compare_error = 0;

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock(addr, pbufr);
        else
            status = SD_ReadSingleBlock(addr * 512, pbufr);

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR, SD_ReadSingleBlock, %d", __FUNCTION__, __LINE__, status);
            break;
        }

        for (i = 0; i < 512; i++)
        {
            if (((kal_uint8 *)pbufw)[i] != ((kal_uint8 *)pbufr)[i])
            {
                msdc_dbg_print("[%s %d]ERROR, compare error:0x%x , 0x%x ,i=%d", __FUNCTION__, __LINE__, pbufw[i], pbufr[i], i);
                compare_error = 1;
                status = ERR_STATUS;
                break;
            }
        }

        if (compare_error == 0)
        {
            if (time2 != time1)
                msdc_dbg_print("[%s %d]OK,SD_WriteSingleBlock,readback compare ok,write= %5d KB/S , time=%d ,addr=%d", __FUNCTION__, __LINE__, (1 * 32768 * 5) / ((time2 - time1) * 10) , time2 - time1 , addr);
            else
                msdc_dbg_print("[%s %d]OK,SD_WriteSingleBlock,readback compare ok,time=0,addr=%d", __FUNCTION__, __LINE__, addr);
        }



    }
    while (0);

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return status;
}


// ==================================================================================
//
// Test Case 5. Multiple block read test
//
//
//
// ==================================================================================
kal_int32 sdtestcase5(kal_int32 addr , kal_uint32 *pbufr)
{
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2;

    sdtestgpio();

    do
    {

        time1 = drv_get_current_time();

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadMultiBlock(addr, pbufr, testblnum);
        else
            status = SD_ReadMultiBlock(addr * 512, pbufr, testblnum);

        time2 = drv_get_current_time();

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR, SD_ReadMultiBlock, %d", __FUNCTION__, __LINE__, status);
            break;
        }

        if (time2 != time1)
            msdc_dbg_print("[%s %d]OK,SD_ReadMultiBlock, %5d KB/S,addr=%d , blnum=%d", __FUNCTION__, __LINE__, (testblnum * 32768 * 5) / ((time2 - time1) * 10), addr, testblnum);
        else
            msdc_dbg_print("[%s %d]OK,SD_ReadMultiBlock, time=0,addr=%d , blnum=%d", __FUNCTION__, __LINE__, addr, testblnum);

        gspeed = (testblnum * 32768 * 5) / ((time2 - time1) * 10);


    }
    while (0);

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return status;
}

kal_int32 sdtestcase6(kal_int32 addr , kal_uint32 *pbufw , kal_uint32 *pbufr)
{
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2;

    kal_int32 i, compare_error;

    //srand(drv_get_current_tick());

    for (i = 0; i < 512 * testblnum; i++)
        //pbufw[i]=((i+20)<<0)|((i+21)<<8)|((i+22)<<16)|((i+23)<<24);
        //*((kal_uint8 *)pbufw + i) = i;
        *((kal_uint8 *)pbufw + i) = rand() % 256;

    sdtestgpio();

    do
    {

        time1 = drv_get_current_time();

        if (SD_CARD == gMSDC_Handle->mMSDC_type)
        {

            status = SD_SetPreEraseBlk(testblnum);

            if (status != NO_ERROR)
            {
                msdc_dbg_print("[%s %d]ERROR, pre erase fail!!, %d", __FUNCTION__, __LINE__, status);
                break;
            }
        }

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_WriteMultiBlock(addr, pbufw, testblnum);
        else
            status = SD_WriteMultiBlock(addr * 512, pbufw, testblnum);

        time2 = drv_get_current_time();

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR,SD_WriteMultiBlock,%d", __FUNCTION__, __LINE__, status);
            break;
        }

        // readback compare
        compare_error = 0;

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadMultiBlock(addr, pbufr, testblnum);
        else
            status = SD_ReadMultiBlock(addr * 512, pbufr, testblnum);

        if (status != NO_ERROR)
        {
            msdc_dbg_print("[%s %d]ERROR,SD_ReadMultiBlock,%d", __FUNCTION__, __LINE__, status);
            break;
        }

        for (i = 0; i < 128 * testblnum; i++)
        {
            if (pbufw[i] != pbufr[i])
            {
                msdc_dbg_print("[%s %d]ERROR, readback compare error:0x%x , 0x%x ,i=%d", __FUNCTION__, __LINE__, pbufw[i], pbufr[i], i);
                compare_error = 1;
                status = ERR_STATUS;
                break;
            }
        }

        if (compare_error == 0)
        {
            if (time2 != time1)
                msdc_dbg_print("[%s %d]OK,SD_WriteMultiBlock,readback compare ok,write= %5d KB/S , time=%d ,addr=%d , blnum=%d", __FUNCTION__, __LINE__, (testblnum * 32768 * 5) / ((time2 - time1) * 10) , time2 - time1 , addr, testblnum);
            else
                msdc_dbg_print("[%s %d]OK,SD_WriteMultiBlock,readback compare ok,time=0,addr=%d , blnum=%d", __FUNCTION__, __LINE__, addr, testblnum);
        }

        gspeed = (testblnum * 32768 * 5) / ((time2 - time1) * 10);



    }
    while (0);

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return status;
}

kal_int32 SD_setclk(kal_int32 wdata)//KHZ
{
    msdc_clk_setting cs, cs2;
    kal_int32 temp1, temp2;

    temp1 = 0;
    temp2 = 0x0fffffff;
    cs2.cardClk = 0;

    for (cs.sclkf = 0; cs.sclkf < 250; cs.sclkf ++)
    {
        for (cs.clksrc = 0; cs.clksrc < CLKSRCNUM; cs.clksrc ++)
        {
            cs.cardClk = gMsdcClksrcRate[cs.clksrc] / DIV_SCLKF(cs.sclkf);

            if (wdata >= cs.cardClk)
            {
                temp1 = wdata - cs.cardClk;

                if (temp1 <= temp2)
                {
                    temp2 = temp1;
                    cs2.cardClk = cs.cardClk;
                    cs2.clksrc = cs.clksrc;
                    cs2.sclkf = cs.sclkf;

                    if (temp1 == 0)
                        goto SD_setclk_return;
                }
            }
        }
    }

SD_setclk_return:

    if (cs2.cardClk)
    {
        MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_SIEN);
        BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)cs2.sclkf, MSDC_CFG_SCLKF);
        BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)cs2.clksrc, MSDC_CFG_CLKSRC);
        MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_SIEN);
        gMSDC_Handle->op_clock = cs2.cardClk;
        gMSDC_Handle->msdc_clock = gMsdcClksrcRate[cs2.clksrc];
        msdc_dbg_print("[%s %d]CLK=%d,CLKSRC=%d,SCLKF=%d,op_clock=%d,msdc_clock=%d", __FUNCTION__, __LINE__, cs2.cardClk, cs2.clksrc, cs2.sclkf, gMSDC_Handle->op_clock, gMSDC_Handle->msdc_clock);

        if (gMSDC_Handle->op_clock >= 25000)
        {
            MSDC_LSD_SetBits32(MSDC_IOCON, (1 << 10));
            msdc_dbg_print("[%s %d]HIGH SPEED", __FUNCTION__, __LINE__);
        }
        else
        {
            MSDC_LSD_ClearBits32(MSDC_IOCON, (1 << 10));
        }
    }

    return 0;
}


// ==================================================================================
//
// Test Case 7. Set clock/ODC
//
//
//
// ==================================================================================
kal_int32 sdtestcase7(void)
{
    kal_uint8 buf[30], input, offset = 0;
    kal_uint32 value = 0xFFFFFFFF, odc;

    dbg_print("1. Set clock.\r\n");
    dbg_print("2. Set ODC. \r\n");
    dbg_print("3. Set MPLL/26M.\r\n");

    dbg_print("input:");
    input = U_GetUARTByte(uart_port1);
    dbg_print("%c\r\n", input);

    switch (input)
    {

        case '1':
        {

            memset(buf, 0, sizeof(buf));
            msdc_dbg_print("\r\n[%s %d]clock test...", __FUNCTION__, __LINE__);
            msdc_dbg_print("[%s %d]msdc_clock=%d,op_clock=%d,MSDC_CFG=0x%x(CLKSRC=%d,SCLKF=%d)", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_clock, gMSDC_Handle->op_clock, MSDC_Reg32(MSDC_CFG), 0x3 & (MSDC_Reg32(MSDC_CFG) >> 3), 0x0ff & (MSDC_Reg32(MSDC_CFG) >> 8));
            msdc_dbg_print("input(KHz)(ESC:exit):");

            msdc_dbg_input(&value);

            if (value != 0xFFFFFFFF)
            {
                SD_setclk(value);
                msdc_dbg_print("\r\n set clock=%d(%d) KHz , press any key to exit...\r\n", value, gMSDC_Handle->op_clock);
                // enable 74 SD clk by s/w
                MSDC_SetBits32(MSDC_CFG, 0x80);

                //kal_sleep_task(2000);
                U_GetUARTByte(uart_port1);

                // stop SD clk by s/w
                MSDC_ClearBits32(MSDC_CFG, 0x80);
            }

        }
        break;

        case '2':
        {

            msdc_dbg_print("[%s %d]MSDC_IOCON=0x%x \r\n", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_IOCON));
            dbg_print("Choose ODC(4,8,12,16):");

            msdc_dbg_input(&value);

            if (value == 4)
                odc = MSDC_ODC_4MA;
            else if (value == 8)
                odc = MSDC_ODC_8MA;
            else if (value == 12)
                odc = MSDC_ODC_12MA;
            else if (value == 16)
                odc = MSDC_ODC_16MA;
            else
            {
                dbg_print("wrong argument\r\n");
                return -1;
            }

            MSDC_SetData32(
                MSDC_IOCON,
                MSDC_IOCON_ODCCFG0 | MSDC_IOCON_ODCCFG1,
                (odc << 3 | odc)
            );

        }
        break;

        case '3':
        {

#if defined(MT6280)

            if ((MSDC_Reg32(CLKSW_CKSEL1) & 0xF0) >> 4 == 1)
                msdc_dbg_print("[%s %d]26M\r\n", __FUNCTION__, __LINE__);
            else if ((MSDC_Reg32(CLKSW_CKSEL1) & 0xF0) >> 4 == 2)
                msdc_dbg_print("[%s %d]MPLL\r\n", __FUNCTION__, __LINE__);

            dbg_print("Choose 1.26M 2.MPLL");

            msdc_dbg_input(&value);

            switch (value)
            {

                case 1:
                {
                    MSDC_WriteReg32(CLKSW_CKSEL1, 0x2210);
                }
                break;

                case 2:
                {
                    //
                    // CLKSW_CKSEL1. MSDC clock source selection.
                    // [7:4]=2, MPLL
                    // [7:4]=1, system 26M
                    //
                    MSDC_WriteReg32(CLKSW_CKSEL1, 0x2220);
                    //
                    // CLKSW_FDIV1.
                    // [11:8]=0, 1 => clock gating.
                    // [11:8]=2, => divid by 2.
                    //
                    MSDC_WriteReg32(CLKSW_FDIV1, 0x2C0);

                    //
                    // CLKSW_FDIV6.
                    // b'10 = 0->1->0.
                    //
                    MSDC_WriteReg32(CLKSW_FDIV6, 0x015);
                    MSDC_WriteReg32(CLKSW_FDIV6, 0x415);
                    MSDC_WriteReg32(CLKSW_FDIV6, 0x015);
                }
                break;

                default:
                    dbg_print("Out of choice\r\n");
                    break;
            }



#else
            dbg_print("Not support\r\n");
#endif

        }
        break;

        default:
            break;
    }


}





kal_int32 sdtestcase8(void)
{
    kal_uint32 input;

    msdc_dbg_print("\r\n[%s %d]1-4 bit BUS test...", __FUNCTION__, __LINE__);
    msdc_dbg_print("[%d BIT]input(1:1bit ; 4:4bit ; ESC:exit):", (SDC_CFG_MDLEN & MSDC_Reg32(SDC_CFG)) ? 4 : 1 );

    msdc_dbg_input(&input);

    if (input == 1)
        gMSDC_Handle->trySingleLine = KAL_TRUE;
    else if (input == 4)
        gMSDC_Handle->trySingleLine = KAL_FALSE;


    msdc_dbg_print("\r\n re-mount...\r\n");

    kal_sleep_task(200);
    sdtestcase1();


}



// ==================================================================================
//
// Test Case 9. Stress test
//
//
//
// ==================================================================================
kal_int32 sdtestcase9(void)
{
    SDC_CMD_STATUS status = 0;
    kal_int32 loopIndex = 0, addr = 0, addrend = 10;
    kal_uint32 time1, time2;
    kal_int32 result = 0;
    kal_uint32 oknum = 0, errornum = 0;
    kal_uint8 str[30], input, offset;
    kal_uint32 value;

    memset(str, 0, sizeof(str));


    msdc_dbg_print("\r\n[%s %d]stress test...", __FUNCTION__, __LINE__);

    msdc_dbg_print("\r\n Input test loop: ");

    msdc_dbg_input(&value);

    //-------------------------------------------------------------------------
    addrend = value;

    for (addr = 0; addr < addrend; addr++)
    {

        //
        // Single read test.
        //
        status = sdtestcase3(addr, msdc_sector_buf1);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d\r\n", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;

    //-------------------------------------------------------------------------

    for (addr = 0; addr < addrend; addr++)
    {

        //
        // Single write with compare test.
        //
        status = sdtestcase4(addr, msdc_sector_buf1, msdc_sector_buf2);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d\r\n", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;



    //-------------------------------------------------------------------------
    for (addr = 0; addr < addrend * testblnum; addr += testblnum)
    {
        //
        // Multi read test.
        //
        status = sdtestcase5(addr, msdc_uncachedBuf1);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d\r\n", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;



    //-------------------------------------------------------------------------
    for (addr = 0; addr < addrend * testblnum; addr += testblnum)
    {
        //
        // Multi write with compare test.
        //
        status = sdtestcase6(addr, msdc_uncachedBuf1, msdc_uncachedBuf2);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }
    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d\r\n", __FUNCTION__, __LINE__, oknum, errornum);

    //-------------------------------------------------------------------------


    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return 0;
}



// ==================================================================================
//
// Test Case 0. Non-4N align test
//
//
//
// ==================================================================================
kal_int32 sdtestcase10(void)
{
    kal_int32 loopIndex, addr;
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2, result = KAL_TRUE;

    msdc_dbg_print("\r\n[%s %d]non-4N read single test...", __FUNCTION__, __LINE__);

    for (loopIndex = 0; loopIndex < 4; loopIndex++)
    {
        msdc_dbg_print("[%s %d]DMA test, addr = %x", __FUNCTION__, __LINE__, (kal_uint32 *)&msdc_sector_buf1[loopIndex]);
        status = sdtestcase3(0 , (kal_uint32 *)&msdc_sector_buf1[loopIndex]);

        if (status != NO_ERROR)
            result = 0;

        guilin_sleep(200);

        msdc_dbg_print("[%s %d]MCU test, addr = %x", __FUNCTION__, __LINE__, (kal_uint32 *)&msdc_sector_buf1[loopIndex]);
        status = SD_ReadSingleBlock_MCU(0 , (kal_uint32 *)&msdc_sector_buf1[loopIndex]);

        if (status != NO_ERROR)
            result = 0;

        guilin_sleep(200);
    }

    //---------------------------------------------------------------------------
    msdc_dbg_print("\r\n[%s %d]non-4N write single test...", __FUNCTION__, __LINE__);

    for (loopIndex = 0; loopIndex < 4; loopIndex++)
    {
        msdc_dbg_print("[%s %d]DMA test, addr = %x", __FUNCTION__, __LINE__, (kal_uint32 *)&msdc_sector_buf1[loopIndex]);
        status = sdtestcase4(0 , (kal_uint32 *)&msdc_sector_buf1[loopIndex], (kal_uint32 *)&msdc_sector_buf2[loopIndex]);

        if (status != NO_ERROR)
            result = 0;

        guilin_sleep(200);

        msdc_dbg_print("[%s %d]MCU test, addr = %x", __FUNCTION__, __LINE__, (kal_uint32 *)&msdc_sector_buf2[loopIndex]);
        status = SD_WriteSingleBlock_MCU(0 , (kal_uint32 *)&msdc_sector_buf1[loopIndex]);

        if (status != NO_ERROR)
            result = 0;

        guilin_sleep(200);
    }

    if (result == 0)
        msdc_dbg_print("\r\n[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("\r\n[%s]Result: PASS... ", __FUNCTION__);

}

// ==================================================================================
//
// Test Case 11. cache test
//
//
//
// ==================================================================================
kal_int32 sdtestcase11(void)
{
    kal_int32 loopIndex, addr, addrend;
    SDC_CMD_STATUS status;
    kal_uint32 time1, time2;
    kal_uint32 value = 0;
    kal_uint32 oknum = 0, errornum = 0;

    msdc_dbg_print("\r\n[%s %d]cache stress test...", __FUNCTION__, __LINE__);

    gMSDC_Handle->isCachedBuf = KAL_TRUE;

    msdc_dbg_input(&value);

    //-------------------------------------------------------------------------
    addrend = value;

    for (addr = 0; addr < addrend; addr++)
    {
        status = sdtestcase3(addr, cachemsdc_sector_buf1);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;



    //-------------------------------------------------------------------------
    //addrend = testsectors;
    //addrend = ADDREND;

    for (addr = 0; addr < addrend; addr++)
    {
        status = sdtestcase4(addr, cachemsdc_sector_buf1, cachemsdc_sector_buf2);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;

    //-------------------------------------------------------------------------
    //addrend = testsectors - testblnum;
    //addrend = ADDREND2;

    for (addr = 0; addr < addrend * testblnum; addr += testblnum)
    {
        status = sdtestcase5(addr, cachemsdc_uncachedBuf1);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);

    oknum = 0;
    errornum = 0;

    //-------------------------------------------------------------------------

    for (addr = 0; addr < addrend * testblnum; addr += testblnum)
    {
        status = sdtestcase6(addr, cachemsdc_uncachedBuf1, cachemsdc_uncachedBuf2);

        if (status == NO_ERROR)
            oknum++;
        else if (status != NO_ERROR)
        {
            errornum++;
            break;
        }

    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);
    oknum = 0;
    errornum = 0;

    //-------------------------------------------------------------------------
    gMSDC_Handle->isCachedBuf = KAL_FALSE;

    if (status != NO_ERROR)
        msdc_dbg_print("\r\n[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("\r\n[%s]Result: PASS... ", __FUNCTION__);

    return 0;

}


kal_int32 sdtestcase12(void)
{
    kal_int32 loopIndex;
    SDC_CMD_STATUS status;
    kal_uint32 oknum = 0, errornum = 0;

    msdc_dbg_print("\r\n[%s %d]mount stress test...", __FUNCTION__, __LINE__);

    for (loopIndex = 0; loopIndex < TESTLOOP; loopIndex++)
    {
        if (U_GetUARTByte_guilin(uart_port1) == ESCKEY)
        {
            msdc_dbg_print("[%s %d]ESC,mount stress test...END,OK=%d,ERROR=%d", __FUNCTION__, __LINE__, oknum, errornum);
            break;
        }

        if (sdtestcase1() == NO_ERROR)
        {
            oknum++;
            msdc_dbg_print("[%s %d]OK=%d,ERROR=%d,clksrc=%d,sclkf=%d,CLK=%d \r\n", __FUNCTION__, __LINE__, oknum, errornum, test_clksrc, test_sclkf, gMsdcClksrcRate[test_clksrc] / DIV_SCLKF(test_sclkf));
        }
        else
        {
            errornum++;
            msdc_dbg_print("[%s %d]OK=%d,ERROR=%d,clksrc=%d,sclkf=%d,CLK=%d \r\n", __FUNCTION__, __LINE__, oknum, errornum, test_clksrc, test_sclkf, gMsdcClksrcRate[test_clksrc] / DIV_SCLKF(test_sclkf));
        }
    }

    msdc_dbg_print("[%s %d]mount stress test...END,OK=%d,ERROR=%d", __FUNCTION__, __LINE__, oknum, errornum);

}


// ==================================================================================
//
// Test Case 13. Clock test
//
//
//
// ==================================================================================
kal_int32 sdtestcase13(kal_uint32 count)
{
    SDC_CMD_STATUS status;
    kal_int32 result = 0, oknum = 0, errornum = 0, errloop = 0, round;

    msdc_dbg_print("\r\n[%s %d]clock stress test...", __FUNCTION__, __LINE__);
    memset(test_statistic, 0, sizeof(test_statistic));

    for (test_clksrc = 0; test_clksrc < CLKSRCNUM; test_clksrc++)
    {

        for (test_sclkf = 0; test_sclkf < SCLKFNUM; test_sclkf++)
        {
            MSDC_LSD_ClearBits32(SDC_CFG, SDC_CFG_SIEN);
            BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)test_sclkf, MSDC_CFG_SCLKF);
            BitFieldWrite32((kal_uint32*)MSDC_CFG, (kal_uint32)test_clksrc, MSDC_CFG_CLKSRC);
            MSDC_LSD_SetBits32(SDC_CFG, SDC_CFG_SIEN);
            gMSDC_Handle->op_clock = gMsdcClksrcRate[test_clksrc] / DIV_SCLKF(test_sclkf);
            gMSDC_Handle->msdc_clock = gMsdcClksrcRate[test_clksrc];
            msdc_dbg_print("[%s %d]CLKSRC=%d,SCLKF=%d,op_clock=%d,msdc_clock=%d", __FUNCTION__, __LINE__, test_clksrc, test_sclkf, gMSDC_Handle->op_clock, gMSDC_Handle->msdc_clock);

            errloop = 0;

            status = sdtestcase21(count);

            if (status == NO_ERROR)
            {
                oknum++;
                msdc_dbg_print("[%s %d]OK=%d,CLKSRC=%d,SCLKF=%d,op_clock=%d,msdc_clock=%d", __FUNCTION__, __LINE__, oknum, test_clksrc, test_sclkf, gMSDC_Handle->op_clock, gMSDC_Handle->msdc_clock);
            }
            else
            {
                errornum++;
                msdc_dbg_print("[%s %d]ERROR=%d,CLKSRC=%d,SCLKF=%d,op_clock=%d,msdc_clock=%d\r\n", __FUNCTION__, __LINE__, errornum, test_clksrc, test_sclkf, gMSDC_Handle->op_clock, gMSDC_Handle->msdc_clock);
                goto END_TEST;
            }

        }
    }


    msdc_dbg_print("\r\n[%s %d]clock stress test...END\r\n", __FUNCTION__, __LINE__);

END_TEST:

    if (status != NO_ERROR)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

    return status;

}


kal_int32 sdtestcase14(void)
{
    kal_uint8 input;
    kal_uint32 value;

    msdc_dbg_print("[%s %d]CLKPAD_RED test...\r\n", __FUNCTION__, __LINE__);
    msdc_dbg_print("[%s %d]CLKPAD_RED=%d\r\n", __FUNCTION__, __LINE__, ((MSDC_Reg32(MSDC_CLKACB_CFG) & 0x80) >> 7));
    msdc_dbg_print("input(0:rising edge ; 1:falling edge)(ESC:exit):\r\n");

    msdc_dbg_input(&value);
    dbg_print("%c\r\n", value);

    if (value == 1)
    {
        MSDC_SetBits32(MSDC_CLKACB_CFG, 1 << 7);
    }
    else
    {
        MSDC_ClearBits32(MSDC_CLKACB_CFG, 1 << 7);
    }

    return 0;
}


// ==================================================================================
//
// Test Case 15. Format test
//
//
//
// ==================================================================================
kal_int32 sdtestcase15(void)
{
    kal_uint32 status;
    kal_uint32 boot_sector_offset, total_sectors;

    FS_MasterBootRecord *mbr;
    FS_BootRecord *bs;

    msdc_dbg_print("\r\n[%s %d]FAT fastformat test...", __FUNCTION__, __LINE__);

    do
    {

        mbr = (FS_MasterBootRecord *)msdc_sector_buf1;
        bs = (FS_BootRecord *)msdc_sector_buf2;

        total_sectors = gSD->mCSD.capacity / 512;

        //
        // 1. Create MBR.
        //
        boot_sector_offset = SDCreateMasterBootRecord(mbr, total_sectors);

        if (boot_sector_offset > 0)
        {

            //
            // 2. Write MBR.
            //
            status = WriteSectors(&MSDC_Blk[0], 0, 1, (void *)mbr);

            if (status != STATUS_OK)
            {
                msdc_dbg_print("[%s %d]FAT fastformat test...write MBR fail,%d", __FUNCTION__, __LINE__, status);
                break;
            }

            //
            // 3. Create boot sector.
            //
            if (SDCreateBootSector(bs, total_sectors, &mbr->PTable[0]) > 0)
            {

                //
                // 4. Write boot sector to boot_sector_offset
                //
                status = WriteSectors(&MSDC_Blk[0], boot_sector_offset, 1, bs);

                if (status != STATUS_OK)
                {
                    msdc_dbg_print("[%s %d]FAT fastformat test...write BS fail,%d", __FUNCTION__, __LINE__, status);
                    break;
                }

            }
            else
            {
                msdc_dbg_print("[%s %d]FAT fastformat test...boot sector fail!!!", __FUNCTION__, __LINE__);
            }
        }
        else
        {
            msdc_dbg_print("[%s %d]FAT fastformat test...boot sector offset is wrong!!!", __FUNCTION__, __LINE__);
        }

        //
        // 5. Finally, perform high level format.
        //    According to SD spec, 2G~32G card's start address is 0x2000
        //
        status = highlevelformat(&MSDC_Blk[0], boot_sector_offset);

        if (status != STATUS_OK)
            msdc_dbg_print("[%s %d]FAT fastformat test...highlevelformat error,%d", __FUNCTION__, __LINE__, status);
        else
            msdc_dbg_print("[%s %d]FAT fastformat test...END,%d", __FUNCTION__, __LINE__, status);

    }
    while (0);

    if (status != STATUS_OK)
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    else
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);

}


kal_int32 sdtestcase16(void)
{
    kal_int32 status;
    msdc_dbg_print("\r\n[%s %d]DMA.fix test...", __FUNCTION__, __LINE__);
    gMSDC_Handle->MSDC_fastFormat = KAL_TRUE;
    {
        kal_int32 loopIndex, addr, addrend;
        SDC_CMD_STATUS status;
        kal_uint32 time1, time2;

        msdc_dbg_print("[%s %d]write multi test...", __FUNCTION__, __LINE__);
        addrend = testsectors - testblnum;
        addr = 0;
        addrend = ADDREND2;
        //for(loopIndex = TESTLOOP; loopIndex; loopIndex--)
        //for(addr=0;addr<addrend;addr++)
        {
            kal_int32 i, compare_error;

            for (i = 0; i < 128 * 1; i++)
                msdc_sector_buf1[i] = ((i + 20 + addr) << 0) | ((i + 21 + addr) << 8) | ((i + 22 + addr) << 16) | ((i + 23 + addr) << 24);

            memset(msdc_uncachedBuf1, 0, sizeof(msdc_uncachedBuf1));
            time1 = drv_get_current_time();

            //status = SD_SetPreEraseBlk(testblnum);
            if (gSD->flags & SD_FLAG_HCS_SUPPORT)
                status = SD_WriteMultiBlock(addr, msdc_sector_buf1, testblnum);
            else
                status = SD_WriteMultiBlock(addr * 512, msdc_sector_buf1, testblnum);

            time2 = drv_get_current_time();
            msdc_dbg_print("[guilin %s %d]SD_WriteMultiBlock=%d,%d KB/S,addr=%d", __FUNCTION__, __LINE__, status, (testblnum * 32768 * 5) / ((time2 - time1) * 10), addr);

            if (status != NO_ERROR)
            {
                msdc_dbg_print("[%s %d]ERROR,SD_WriteMultiBlock,%d", __FUNCTION__, __LINE__, status);
                return;
            }

            //guilin_sleep(400);
            // readback compare
            compare_error = 0;
            time1 = drv_get_current_time();

            if (gSD->flags & SD_FLAG_HCS_SUPPORT)
                status = SD_ReadMultiBlock(addr, msdc_uncachedBuf2, testblnum);
            else
                status = SD_ReadMultiBlock(addr * 512, msdc_uncachedBuf2, testblnum);

            time2 = drv_get_current_time();
            msdc_dbg_print("[guilin %s %d]SD_ReadMultiBlock=%d,%d KB/S,addr=%d", __FUNCTION__, __LINE__, status, (testblnum * 32768 * 5) / ((time2 - time1) * 10), addr);

            if (status != NO_ERROR)
            {
                msdc_dbg_print("[%s %d]ERROR,SD_ReadMultiBlock,%d", __FUNCTION__, __LINE__, status);
                return;
            }

            for (i = 0; i < 128 * testblnum; i++)
            {
                if (msdc_sector_buf1[0] != msdc_uncachedBuf2[i])
                {
                    msdc_dbg_print("[%s %d]SD_WriteMultiBlock,readback compare error:write=0x%x , read=0x%x ,i=%d", __FUNCTION__, __LINE__, msdc_uncachedBuf1[i], msdc_uncachedBuf2[i], i);
                    compare_error = 1;
                    break;
                }
            }

            if (compare_error == 0)
            {
                msdc_dbg_print("[%s %d]SD_WriteMultiBlock,readback compare ok", __FUNCTION__, __LINE__);
            }
        }

    }


    gMSDC_Handle->MSDC_fastFormat = KAL_FALSE;
    msdc_dbg_print("[%s %d]DMA.fix test...END,%d", __FUNCTION__, __LINE__, status);


}

kal_int32 sdtestcase17(void)
{
    kal_int32 status, addr, cnt = 0;

    do
    {

        //--------------------------------------------------------------------
        msdc_dbg_print("\r\n[%s %d]DAT CRC test...", __FUNCTION__, __LINE__);

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock_MCU_datcrc(0, msdc_sector_buf1 );
        else
            status = SD_ReadSingleBlock_MCU_datcrc(0 * 512, msdc_sector_buf1 );

        msdc_dbg_print("[%s %d]sdc_datsta=0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->dat_sta);

        if (status != ERR_DAT_CRCERR)
            break;

        cnt++;

        {
            DCL_HANDLE handle;
            handle = DclGPIO_Open(DCL_GPIO, DATGPIO); // GPIO31-DAT0
            DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
            DclGPIO_Close(handle);
            guilin_sleep(100);
        }


        //--------------------------------------------------------------------
        msdc_dbg_print("\r\n[%s %d]DATTO test...", __FUNCTION__, __LINE__);

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock_MCU_datto(0, msdc_sector_buf1 );
        else
            status = SD_ReadSingleBlock_MCU_datto(0 * 512, msdc_sector_buf1 );

        msdc_dbg_print("[%s %d]sdc_datsta=0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->dat_sta);

        if (status != ERR_DAT_TIMEOUT)
            break;

        cnt++;

        {
            DCL_HANDLE handle;
            handle = DclGPIO_Open(DCL_GPIO, DATGPIO); // GPIO31-DAT0
            DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
            DclGPIO_Close(handle);
            guilin_sleep(100);
        }



        //--------------------------------------------------------------------
        msdc_dbg_print("\r\n[%s %d]CMDTO test...", __FUNCTION__, __LINE__);

        if (gSD->flags & SD_FLAG_HCS_SUPPORT)
            status = SD_ReadSingleBlock_MCU_cmdto(0, msdc_sector_buf1 );
        else
            status = SD_ReadSingleBlock_MCU_cmdto(0 * 512, msdc_sector_buf1 );

        msdc_dbg_print("[%s %d]sdc_cmdsta=0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->cmd_sta);

        if (status != ERR_CMD_TIMEOUT)
            break;

        cnt++;

        {
            DCL_HANDLE handle;
            handle = DclGPIO_Open(DCL_GPIO, CMDGPIO); // GPIO32-CMD
            DclGPIO_Control(handle, GPIO_CMD_SET_MODE_1, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_DIR_IN, 0);
            DclGPIO_Control(handle, GPIO_CMD_SET_PULL_HIGH, 0);
            DclGPIO_Control(handle, GPIO_CMD_ENABLE_PULL, 0);
            DclGPIO_Close(handle);
            guilin_sleep(100);
        }



        //--------------------------------------------------------------------

        msdc_dbg_print("[%s %d]CRC,CMDTO,DATTO test...END,%d", __FUNCTION__, __LINE__, status);

    }
    while (0);

    if (cnt == 3)
        msdc_dbg_print("\r\n[%s]Result: PASS... ", __FUNCTION__);
    else
        msdc_dbg_print("\r\n[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);

}
kal_int32 sdtestcase18(void)
{
    kal_int32 status, addr, loopIndex;
    kal_uint8 *p81, *p82;
    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n[%s %d]odd-size test...read_mcu", __FUNCTION__, __LINE__);
    addr = gSD->mBKNum - 1;

    if (addr < 0)addr = 0;

    loopIndex = 1;
    memset(msdc_sector_buf1, 0, sizeof(msdc_sector_buf1));
    memset(msdc_sector_buf2, 0xff, sizeof(msdc_sector_buf2));
    status = SD_SetBlength(512);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock_MCU(0, msdc_sector_buf1);
    else
        status = SD_ReadSingleBlock_MCU(0 * 512, msdc_sector_buf1);

    status = SD_SetBlength(511);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock_MCU(0, msdc_sector_buf2);
    else
        status = SD_ReadSingleBlock_MCU(0 * 512, msdc_sector_buf2);

    p81 = (kal_uint8 *)&msdc_sector_buf1[0];
    p82 = (kal_uint8 *)&msdc_sector_buf2[0];

    for (loopIndex = 0; loopIndex < 511; loopIndex++)
    {
        if (p81[loopIndex] != p82[loopIndex])
        {
            msdc_dbg_print("[%s %d]compare error: 0x%x , 0x%x ,i=%d ", __FUNCTION__, __LINE__, p81[loopIndex], p82[loopIndex], loopIndex);
            break;
        }
    }

    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n[%s %d]odd-size test...write_mcu", __FUNCTION__, __LINE__);
    memset(msdc_sector_buf1, 0, sizeof(msdc_sector_buf1));
    memset(msdc_sector_buf2, 0xff, sizeof(msdc_sector_buf2));
    memset(msdc_sector_buf3, 0, sizeof(msdc_sector_buf3));
    status = SD_SetBlength(512);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock_MCU(0, msdc_sector_buf1 );
    else
        status = SD_ReadSingleBlock_MCU(0 * 512, msdc_sector_buf1);

    for (loopIndex = 0; loopIndex < 512 / 4; loopIndex++)
        msdc_sector_buf2[loopIndex] = msdc_sector_buf1[loopIndex] + 0x01010101;

    status = SD_SetBlength(511);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_WriteSingleBlock_MCU(0, msdc_sector_buf2);
    else
        status = SD_WriteSingleBlock_MCU(0 * 512, msdc_sector_buf2);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock_MCU(0, msdc_sector_buf3);
    else
        status = SD_ReadSingleBlock_MCU(0 * 512, msdc_sector_buf3);

    p81 = (kal_uint8 *)&msdc_sector_buf3[0];
    p82 = (kal_uint8 *)&msdc_sector_buf2[0];

    for (loopIndex = 0; loopIndex < 511; loopIndex++)
    {
        if (p81[loopIndex] != p82[loopIndex])
        {
            msdc_dbg_print("[%s %d]compare error: 0x%x , 0x%x ,i=%d ", __FUNCTION__, __LINE__, p81[loopIndex], p82[loopIndex], loopIndex);
            break;
        }
    }

    //-------------------------------------------------------------------------
    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n[%s %d]odd-size test...read_dma", __FUNCTION__, __LINE__);
    memset(msdc_sector_buf1, 0, sizeof(msdc_sector_buf1));
    memset(msdc_sector_buf2, 0xff, sizeof(msdc_sector_buf2));
    status = SD_SetBlength(512);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock(0, msdc_sector_buf1);
    else
        status = SD_ReadSingleBlock(0 * 512, msdc_sector_buf1);

    status = SD_SetBlength(511);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock(0, msdc_sector_buf2);
    else
        status = SD_ReadSingleBlock(0 * 512, msdc_sector_buf2);

    p81 = (kal_uint8 *)&msdc_sector_buf1[0];
    p82 = (kal_uint8 *)&msdc_sector_buf2[0];

    for (loopIndex = 0; loopIndex < 511; loopIndex++)
    {
        if (p81[loopIndex] != p82[loopIndex])
        {
            msdc_dbg_print("[%s %d]compare error: 0x%x , 0x%x ,i=%d ", __FUNCTION__, __LINE__, p81[loopIndex], p82[loopIndex], loopIndex);
            break;
        }
    }

    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n[%s %d]odd-size test...write_dma", __FUNCTION__, __LINE__);
    memset(msdc_sector_buf1, 0, sizeof(msdc_sector_buf1));
    memset(msdc_sector_buf2, 0xff, sizeof(msdc_sector_buf2));
    memset(msdc_sector_buf3, 0, sizeof(msdc_sector_buf3));
    status = SD_SetBlength(512);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock(0, msdc_sector_buf1 );
    else
        status = SD_ReadSingleBlock(0 * 512, msdc_sector_buf1);

    for (loopIndex = 0; loopIndex < 512 / 4; loopIndex++)
        msdc_sector_buf2[loopIndex] = msdc_sector_buf1[loopIndex] + 0x01010101;

    status = SD_SetBlength(511);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);
    loopIndex = 1;

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_WriteSingleBlock(0, msdc_sector_buf2);
    else
        status = SD_WriteSingleBlock(0 * 512, msdc_sector_buf2);

    loopIndex = 1;

    if (gSD->flags & SD_FLAG_HCS_SUPPORT)
        status = SD_ReadSingleBlock(0, msdc_sector_buf3);
    else
        status = SD_ReadSingleBlock(0 * 512, msdc_sector_buf3);

    p81 = (kal_uint8 *)&msdc_sector_buf3[0];
    p82 = (kal_uint8 *)&msdc_sector_buf2[0];

    for (loopIndex = 0; loopIndex < 511; loopIndex++)
    {
        if (p81[loopIndex] != p82[loopIndex])
        {
            msdc_dbg_print("[%s %d]compare error: 0x%x , 0x%x ,i=%d ", __FUNCTION__, __LINE__, p81[loopIndex], p82[loopIndex], loopIndex);
            break;
        }
    }

    //-------------------------------------------------------------------------
    status = SD_SetBlength(512);
    msdc_dbg_print("[%s %d]SD_SetBlength=%d", __FUNCTION__, __LINE__, status);
    //-------------------------------------------------------------------------
    msdc_dbg_print("[%s %d]odd-size test...END,%d", __FUNCTION__, __LINE__, status);

}
kal_int32 sdtestcase19(void)
{
    kal_uint8 input;

    msdc_dbg_print("\r\n[%s %d]MSDC_useDMA4ByteBurst test...%d byte", __FUNCTION__, __LINE__, (MSDC_useDMA4ByteBurst == KAL_TRUE ? 4 : 1));
    msdc_dbg_print("input(1:1byte ; 4:4byte ; ESC:exit):");

    while (1)
    {
        input = U_GetUARTByte(uart_port1);

        if (input == '1')
        {
            MSDC_useDMA4ByteBurst = KAL_FALSE;
        }
        else if (input == '4')
        {
            MSDC_useDMA4ByteBurst = KAL_TRUE;
        }
        else if (input == 0x0d || input == 0x0a)
        {
            break;
        }
        else if (input == ESCKEY) //esc
        {
            return;
        }
        else
        {
            continue;
        }

        dbg_print("%c", input);
    }
}



// ==================================================================================
//
// Test Case 20. Erase test
//
//
//
// ==================================================================================
kal_int32 sdtestcase20(kal_uint32 startSector, kal_uint32 sectorNum)
{
    SDC_CMD_STATUS status;
    kal_uint32 i;
    kal_uint32 time1, time2;

    msdc_dbg_print("[%s %d]SD_FlushSectors %d, %d", __FUNCTION__, __LINE__, startSector, sectorNum);

    time1 = drv_get_current_time();
    status = SD_FlushSectors(startSector, sectorNum);
    time2 = drv_get_current_time();

    if (status == NO_ERROR)
    {
        msdc_dbg_print("[%s %d]OK=%d , time=%d \r\n", __FUNCTION__, __LINE__, status, time2 - time1);
        msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);
    }
    else
    {
        msdc_dbg_print("[%s %d]ERROR=%d , time=%d \r\n", __FUNCTION__, __LINE__, status, time2 - time1);
        msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
    }


    MSDC_PDNControl(KAL_FALSE);
}



kal_int32 sdtestcase21(kal_uint32 test_round)
{
    SDC_CMD_STATUS status;
    kal_uint32 i, addr, addrend, loopIndex, oknum, errornum, result, offset;
    msdc_dbg_print("[%s %d]start", __FUNCTION__, __LINE__);

    memset(test_statistic, 0, sizeof(test_statistic));

    oknum = 0;
    errornum = 0;
    offset = 0;

    //-------------------------------------------------------------------------
    for (testblnum = 1; testblnum < 1024; testblnum *= 2)
    {
        addrend = testblnum * test_round;

        for (addr = 0; addr < addrend; addr += testblnum)
        {
            status = sdtestcase5(addr, msdc_uncachedBuf1);

            if (status == NO_ERROR)
            {
                oknum++;
                test_statistic[offset].bit14 = (SDC_CFG_MDLEN & MSDC_Reg32(SDC_CFG)) ? 4 : 1;
                test_statistic[offset].isread1 = 1;
                test_statistic[offset].clksrc = 0x3 & (MSDC_Reg32(MSDC_CFG) >> 3);
                test_statistic[offset].sclkf = 0x0ff & (MSDC_Reg32(MSDC_CFG) >> 8);
                test_statistic[offset].clock = gMsdcClksrcRate[test_statistic[offset].clksrc] / DIV_SCLKF(test_statistic[offset].sclkf);
                test_statistic[offset].addr = addr;
                test_statistic[offset].blnum = testblnum;
                test_statistic[offset].speed = gspeed;
                gspeed = 0;
                offset++;
            }
            else
            {
                errornum++;
                msdc_dbg_print("[%s %d]ERROR, ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);
                return status;
            }
        }
    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);
    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n:index      bit  RW \t clksrc  sclkf    clock \t    addr \t   blnum \t  speed ");

    for (offset = 0; offset < test_round * 10; offset++)
    {
        msdc_dbg_print("[%3d]  %3d \t %c \t %3d \t %3d \t %6d \t %6d \t %6d \t %6d ",
                       offset,
                       test_statistic[offset].bit14,
                       test_statistic[offset].isread1 == 1 ? 'R' : 'W',
                       test_statistic[offset].clksrc,
                       test_statistic[offset].sclkf,
                       test_statistic[offset].clock,
                       test_statistic[offset].addr,
                       test_statistic[offset].blnum,
                       test_statistic[offset].speed );
    }

    //-------------------------------------------------------------------------
    memset(test_statistic, 0, sizeof(test_statistic));

    oknum = 0;
    errornum = 0;
    offset = 0;

WRITE_TEST:

    for (testblnum = 1; testblnum < 1024; testblnum *= 2)
    {
        addrend = testblnum * test_round;

        for (addr = 0; addr < addrend; addr += testblnum)
        {
            status = sdtestcase6(addr, msdc_uncachedBuf1, msdc_uncachedBuf2);

            if (status == NO_ERROR)
            {
                oknum++;
                test_statistic[offset].bit14 = (SDC_CFG_MDLEN & MSDC_Reg32(SDC_CFG)) ? 4 : 1;
                test_statistic[offset].isread1 = 2;
                test_statistic[offset].clksrc = 0x3 & (MSDC_Reg32(MSDC_CFG) >> 3);
                test_statistic[offset].sclkf = 0x0ff & (MSDC_Reg32(MSDC_CFG) >> 8);
                test_statistic[offset].clock = gMsdcClksrcRate[test_statistic[offset].clksrc] / DIV_SCLKF(test_statistic[offset].sclkf);
                test_statistic[offset].addr = addr;
                test_statistic[offset].blnum = testblnum;
                test_statistic[offset].speed = gspeed;
                gspeed = 0;
                offset++;
            }
            else
            {
                errornum++;
                msdc_dbg_print("[%s %d]ERROR, ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);
                return status;
            }

        }
    }

    msdc_dbg_print("[%s %d]ok=%d , error=%d", __FUNCTION__, __LINE__, oknum, errornum);
    oknum = 0;
    errornum = 0;

    //-------------------------------------------------------------------------
    msdc_dbg_print("\r\n:index      bit  RW \t clksrc  sclkf    clock \t    addr \t   blnum \t  speed ");

    for (offset = 0; offset < test_round * 10; offset++)
    {
        msdc_dbg_print("[%3d]  %3d \t %c \t %3d \t %3d \t %6d \t %6d \t %6d \t %6d ",

                       offset,
                       test_statistic[offset].bit14,
                       test_statistic[offset].isread1 == 1 ? 'R' : 'W',
                       test_statistic[offset].clksrc,
                       test_statistic[offset].sclkf,
                       test_statistic[offset].clock,
                       test_statistic[offset].addr,
                       test_statistic[offset].blnum,
                       test_statistic[offset].speed );
    }

END_TEST:

    testblnum = 32;

    return status;
}

kal_int32 sdtestcase22(void)
{
    SDC_CMD_STATUS status;
    kal_uint8 buf[30], input, offset;
    kal_uint32 value, cmdvalue = 0, cmdarg = 0x55;

    memset(buf, 0, sizeof(buf));
    msdc_dbg_print("\r\n[%s %d]SD CMD test...", __FUNCTION__, __LINE__);
    msdc_dbg_print("[%s %d]SDC_CMD=0x%x SDC_ARG=0x%x SDC_CMDSTA=0x%x SDC_RESP0=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_CMD), MSDC_Reg32(SDC_ARG), MSDC_Reg(SDC_CMDSTA), MSDC_Reg32(SDC_RESP0));
    msdc_dbg_print("input CMD(ESC:exit):");

    msdc_dbg_input(&value);

    if (value >= 0)
    {
        switch (value)
        {
            case 0 :
                cmdvalue = SDC_CMD_CMD0;
                cmdarg = 0;
                break;

            case 1 :
                cmdvalue = SDC_CMD_CMD1;
                cmdarg = 0;
                break;

            case 2 :
                cmdvalue = SDC_CMD_CMD2;
                cmdarg = 0;
                break;

            case 3 :
                cmdvalue = SDC_CMD_CMD3_SD;
                cmdarg = 0;
                break;

            case 7 :
                cmdvalue = SDC_CMD_CMD7;
                cmdarg = gSD->mRCA;
                break;

            case 8 :
                cmdvalue = SDC_CMD_CMD8;
                cmdarg = 0x1aa;
                break;

            case 9 :
                cmdvalue = SDC_CMD_CMD9;
                cmdarg = 0;
                break;

            case 13:
                cmdvalue = SDC_CMD_CMD13;
                cmdarg = gSD->mRCA;
                break;

            case 16:
                cmdvalue = SDC_CMD_CMD16;
                cmdarg = 0;
                break;

            case 17:
                cmdvalue = SDC_CMD_CMD17;
                cmdarg = 0;
                break;

            case 18:
                cmdvalue = SDC_CMD_CMD18;
                cmdarg = 0;
                break;

            case 41:
                cmdvalue = SDC_CMD_CMD41_SD;
                cmdarg = 0x40ff8000;
                break;

            case 42:
                cmdvalue = SDC_CMD_CMD42;
                cmdarg = 0;
                break;

            case 51:
                cmdvalue = SDC_CMD_ACMD51;
                cmdarg = 0x40FF8000;
                break;

            case 55:
                cmdvalue = SDC_CMD_CMD55;
                cmdarg = 0;
                break;

            default:
                cmdvalue = SDC_CMD_CMD0;
                cmdarg = 0;
                break;
        }

        status = SD_Send_Cmd(cmdvalue, cmdarg);
        msdc_dbg_print("SD_Send_Cmd=%d cmd=0x%x cmdarg=0x%x", status, cmdvalue, cmdarg);
        msdc_dbg_print("[%s %d]SDC_CMD=0x%x SDC_ARG=0x%x SDC_CMDSTA=0x%x SDC_RESP0=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_CMD), MSDC_Reg32(SDC_ARG), gMSDC_Handle->cmd_sta, MSDC_Reg32(SDC_RESP0));
    }


}




SDC_CMD_STATUS vSDIOInitialisation_Test(void)
{
    static DCL_STATUS fgControl;
    static SDIO_CTRL_SET_BLK_SIZE_T fgblksize;
    static DCL_SDIO_function_id_enum fgfunctionid;
    static kal_uint32 u4BlockSize;
    static kal_char u4PrintBuff[30];
    static SDIO_CTRL_REG_RW_T regReadWrite;
    kal_uint32 j;
    int tbttCount = 0;
    kal_uint32 mcrValue;
    SDIO_CTRL_DAT_RW_T datReadWrite;
    SDIO_CTRL_ENABLE_T enableInterrupt;
    kal_uint32  checkChipIdRevision;
    SDC_CMD_STATUS status;

    //fgControl = DclSDIO_Open(DCL_SDIO, DCL_SDIO_FLAGS_DEVICE_CARD1|DCL_SDIO_FLAGS_USAGE_CMD);

    //fgControl = DclSDIO_Control(handle_sdio, SDIO_CTRL_CMD_INIT,  (DCL_CTRL_DATA_T *)NULL);

    //MSDC_Initialize();

    MSDC_turnOnVMC(KAL_FALSE);
    guilin_sleep(1000);
    MSDC_turnOnVMC(KAL_TRUE);

    status = SDIO_Initialize();

    if (status != NO_ERROR)
    {
        msdc_dbg_print("[%s %d]sdio initialize fail!!%d\r\n", __FUNCTION__, __LINE__, status);
        return;
    }

    msdc_dbg_print("[%s %d]sdio initialize OK. %d\r\n", __FUNCTION__, __LINE__, status);

    /*
        fgblksize.function= SDIO_FUCN_1;
        fgblksize.size = 128;
        fgControl = DclSDIO_Control(handle_sdio,SDIO_CTRL_CMD_SET_BLK_SIZE,(DCL_CTRL_DATA_T *)&fgblksize);

        if (fgControl != ((DCL_STATUS)STATUS_OK)) {

            dbg_print("Error !!! SDIO Setting bulk size for function 1 Failed!\n");
        }
        else {
            dbg_print("SDIO Setting bulk size for function 1 passed!\n");

        }
    */
}

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 1
char str_buf[256] = {0};
kal_int32 str_num = 0;
kal_semid msdc_dbg_print_semid = NULL;

void msdc_dbg_print(char *fmt, ...)
{
    static kal_uint32 num = 0;

    va_list argp;

    if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()) && (KAL_FALSE == kal_if_lisr()) && (KAL_FALSE == kal_if_hisr()))
        if (msdc_dbg_print_semid == NULL)
            msdc_dbg_print_semid = kal_create_sem("msdc_dbg_print_semid_lock", 1);


    if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()) && (KAL_FALSE == kal_if_lisr()) && (KAL_FALSE == kal_if_hisr()))
    {
        if (msdc_dbg_print_semid)
            kal_take_sem(msdc_dbg_print_semid, 1);
    }


    snprintf(str_buf, 5, "%04d", str_num++);
    va_start(argp, fmt);
    _vsnprintf(&str_buf[4], (256 - 4), fmt, argp);
    va_end(argp);

    kal_prompt_trace(MOD_MSDC_HISR, "%s", str_buf);
    dbg_print("%s \r\n", str_buf);

    //    kal_bootup_trace

    if (KAL_FALSE == kal_query_systemInit() && (KAL_FALSE == INT_QueryExceptionStatus()) && (KAL_FALSE == kal_if_lisr()) && (KAL_FALSE == kal_if_hisr()))
    {
        if (msdc_dbg_print_semid)
            kal_give_sem(msdc_dbg_print_semid);
    }


}

kal_uint8 U_GetUARTByte(UART_PORT port)
{
   
   kal_uint8 data;
   kal_uint8 U_GetUARTByteWithTimeOut(UART_PORT port, kal_uint8* ch, kal_uint32 timeout_value);//liming add statement
   while(!U_GetUARTByteWithTimeOut(port,&data,0xffffffff));// for descrease code size  (U_GetUARTByte &U_GetUARTByteTimeout)
   return data;
}

void msdc_dbg_input(kal_uint32 *value)
{
    kal_uint32 result = 0;
    kal_uint8 str[30], input, offset;

    offset = 0;

    while (1)
    {
        input = U_GetUARTByte(DBG_PRINT_PORT);
	
        /*
        if (input >='0' && input <= '9') {

            //input -= '0';
        }
        else {

            if(input == 0x0d || input == 0x0a) {

                break;
            }
            else {

                if(input == ESCKEY)//esc
                    return;
                else
                    continue;

            }
        }
        */
        if (input == 0x0d || input == 0x0a)
            break;

        if (input == ESCKEY)
            return;

        str[offset++] = input;
        dbg_print("%c", input);
    }

    str[offset] = 0;

    dbg_print("\r\n");
    sscanf(str, "%d", value);
}


kal_uint32 msdc_get_uart_input()
{
    kal_uint8 buf[30], input, offset;
    kal_int32 value = 0;

    while (1)
    {

        input = U_GetUARTByte(uart_port1);

        //if(input >='0' && input <= '9')
        //{
        //input -= '0';
        //}
        //else if(input == 0x0d || input == 0x0a)
        if (input == 0x0d || input == 0x0a)
        {
            break;
        }
        else if (input == ESCKEY) //esc
        {
            return;
        }

        //else
        //{
        //    continue;
        //}

        buf[offset++] = input;
        dbg_print("%c", input);
    }

    buf[30 - 1] = 0;

    dbg_print("\r\n");
    sscanf(buf, "%x", &value);

    return value;
}


void guilin_sleep(kal_uint32 x)
{
    if ((kal_query_systemInit() == KAL_TRUE)
#ifdef  __TST_WRITE_TO_FILE__
            || (KAL_TRUE == INT_QueryExceptionStatus())
#endif
            || KAL_TRUE == FTL_isPollingMode()
       )
    {
        MSDC_GPTI_BusyWait(x * 5);
    }
    else
    {
        kal_sleep_task(x);
    }
}
void guilintest(void)
{
    msdc_dbg_print("[guilin %s %d]start", __FUNCTION__, __LINE__);

    msdc_dbg_print("[guilin %s %d]gSD->mSDC_ocr  =0x%x", __FUNCTION__, __LINE__, gSD->mSDC_ocr                 ); // gSD->mSDC_ocr  =0x80FF8000
    msdc_dbg_print("[guilin %s %d]gSD->mBKLength =0x%x", __FUNCTION__, __LINE__, gSD->mBKLength                ); // gSD->mBKLength =0x200
    msdc_dbg_print("[guilin %s %d]gSD->mBKNum    =0x%x", __FUNCTION__, __LINE__, gSD->mBKNum                   ); // gSD->mBKNum    =0xF3400
    msdc_dbg_print("[guilin %s %d]gSD->flags     =0x%x", __FUNCTION__, __LINE__, gSD->flags                    ); // gSD->flags     =0x3C
    msdc_dbg_print("[guilin %s %d]gSD->mRCA      =0x%x", __FUNCTION__, __LINE__, gSD->mRCA                     ); // gSD->mRCA      =0xB368
    msdc_dbg_print("[guilin %s %d]gSD->mState    =0x%x", __FUNCTION__, __LINE__, gSD->mState                   ); // gSD->mState    =0x3
    msdc_dbg_print("[guilin %s %d]gSD->mInactive =0x%x", __FUNCTION__, __LINE__, gSD->mInactive                ); // gSD->mInactive =0x0
    msdc_dbg_print("[guilin %s %d]gSD->bus_width =0x%x", __FUNCTION__, __LINE__, gSD->bus_width                ); // gSD->bus_width =0x4
    msdc_dbg_print("[guilin %s %d]gSD->mWPEnabled=0x%x", __FUNCTION__, __LINE__, gSD->mWPEnabled               ); // gSD->mWPEnabled=0x0
    msdc_dbg_print("[guilin %s %d]gSD->mIsLocked =0x%x", __FUNCTION__, __LINE__, gSD->mIsLocked                ); // gSD->mIsLocked =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCD_DAT3  =0x%x", __FUNCTION__, __LINE__, gSD->mCD_DAT3                 ); // gSD->mCD_DAT3  =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCMD8Resp =0x%x", __FUNCTION__, __LINE__, gSD->mCMD8Resp                ); // gSD->mCMD8Resp =0x0
    msdc_dbg_print("[guilin %s %d]gSD->sd_r      =0x%x", __FUNCTION__, __LINE__, gSD->sd_r                     ); // gSD->sd_r      =0x0
    msdc_dbg_print("[guilin %s %d]gSD->sd_w      =0x%x", __FUNCTION__, __LINE__, gSD->sd_w                     ); // gSD->sd_w      =0x0

    msdc_dbg_print("[guilin %s %d]CSD", __FUNCTION__, __LINE__);
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.tacc              =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.tacc                ); // gSD->mCSD.tacc              =0x5E
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.nsac              =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.nsac                ); // gSD->mCSD.nsac              =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.tran_speed        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.tran_speed          ); // gSD->mCSD.tran_speed        =0x32
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.ccc               =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ccc                 ); // gSD->mCSD.ccc               =0x5F5
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.w_blk_len         =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.w_blk_len           ); // gSD->mCSD.w_blk_len         =0x200
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.r_blk_len         =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.r_blk_len           ); // gSD->mCSD.r_blk_len         =0x200
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.max_w_blk_len     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.max_w_blk_len       ); // gSD->mCSD.max_w_blk_len     =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.max_r_blk_len     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.max_r_blk_len       ); // gSD->mCSD.max_r_blk_len     =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.w_blk_misali      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.w_blk_misali        ); // gSD->mCSD.w_blk_misali      =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.r_blk_misali      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.r_blk_misali        ); // gSD->mCSD.r_blk_misali      =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.w_blk_part        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.w_blk_part          ); // gSD->mCSD.w_blk_part        =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.r_blk_part        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.r_blk_part          ); // gSD->mCSD.r_blk_part        =0x1
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.erase_sec_size_mmc=0x%x", __FUNCTION__, __LINE__, gSD->mCSD.erase_sec_size_mmc  ); // gSD->mCSD.erase_sec_size_mmc=0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.erase_grp_size_mmc=0x%x", __FUNCTION__, __LINE__, gSD->mCSD.erase_grp_size_mmc  ); // gSD->mCSD.erase_grp_size_mmc=0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.wp_grp_size_mmc   =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.wp_grp_size_mmc     ); // gSD->mCSD.wp_grp_size_mmc   =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.erase_blk_en_sd   =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.erase_blk_en_sd     ); // gSD->mCSD.erase_blk_en_sd   =0x1
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.erase_sec_size_sd =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.erase_sec_size_sd   ); // gSD->mCSD.erase_sec_size_sd =0x80
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.wp_prg_size_sd    =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.wp_prg_size_sd      ); // gSD->mCSD.wp_prg_size_sd    =0x800
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.wp_grp_enable     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.wp_grp_enable       ); // gSD->mCSD.wp_grp_enable     =0x1
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.capacity          =%d MB", __FUNCTION__, __LINE__, gSD->mCSD.capacity / (1024 * 1024)); // gSD->mCSD.capacity          =0x1E680000
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.cmd_class         =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.cmd_class           ); // gSD->mCSD.cmd_class         =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.temp_wp           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.temp_wp             ); // gSD->mCSD.temp_wp           =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.perm_wp           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.perm_wp             ); // gSD->mCSD.perm_wp           =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.dsr_imp           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.dsr_imp             ); // gSD->mCSD.dsr_imp           =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.csd_ver           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.csd_ver             ); // gSD->mCSD.csd_ver           =0x0
    msdc_dbg_print("[guilin %s %d]gSD->mCSD.spec_ver          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.spec_ver            ); // gSD->mCSD.spec_ver          =0x0
    {
        guilin_sleep(30);
        msdc_dbg_print("[guilin %s %d]EXTCSD", __FUNCTION__, __LINE__);
#ifndef MSDC_MMC441_SUPPORT
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev1[183]            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev1[183 - 1]           );
#else
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev0[136]      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev0[136 - 1]     );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->enh_start_addr       =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->enh_start_addr      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->enh_size_mult[3]     =0x%x 0x%x 0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->enh_size_mult[2], gSD->mCSD.ext_csd->enh_size_mult[1], gSD->mCSD.ext_csd->enh_size_mult[0]    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->gp_size_mult[4]      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->gp_size_mult[11], gSD->mCSD.ext_csd->gp_size_mult[10], gSD->mCSD.ext_csd->gp_size_mult[9]    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->gp_size_mult[3]      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->gp_size_mult[8], gSD->mCSD.ext_csd->gp_size_mult[7], gSD->mCSD.ext_csd->gp_size_mult[6]    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->gp_size_mult[2]      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->gp_size_mult[5], gSD->mCSD.ext_csd->gp_size_mult[4], gSD->mCSD.ext_csd->gp_size_mult[3]    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->gp_size_mult[1]      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->gp_size_mult[2], gSD->mCSD.ext_csd->gp_size_mult[1], gSD->mCSD.ext_csd->gp_size_mult[0]    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->partition_settig     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->partition_settig    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->partition_attr       =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->partition_attr      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->max_enh_size_mult[3] =0x%x 0x%x 0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->max_enh_size_mult[2], gSD->mCSD.ext_csd->max_enh_size_mult[1], gSD->mCSD.ext_csd->max_enh_size_mult[0]);
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->partition_support    =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->partition_support   );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev1           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev1          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rst_function         =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rst_function        );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev2[5]        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev2[5 - 1]       );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rpmb_size_mul        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rpmb_size_mul       );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->fw_config            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->fw_config           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev3           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev3          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->user_wp              =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->user_wp             );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev4           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev4          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->boot_wp              =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->boot_wp             );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev5           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev5          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->erase_grp_def        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->erase_grp_def       );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev6           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev6          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->boot_bus_width       =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->boot_bus_width      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->boot_config_prot     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->boot_config_prot    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->partition_config     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->partition_config    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev7           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev7          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->erased_mem_cont      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->erased_mem_cont     );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev8           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev8          );
#endif
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->bus_width            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->bus_width            );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev2                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev2                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->high_speed           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->high_speed           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev3                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev3                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->power_class          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->power_class          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev4                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev4                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->cmd_set_rev          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->cmd_set_rev          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev5                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev5                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->cmd_set              =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->cmd_set              );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->ext_csd_rev          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->ext_csd_rev          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev7                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev7                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->ext_csd_ver          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->ext_csd_ver          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev8                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev8                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->card_type            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->card_type            );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev9                 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev9                 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->out_of_interrupt_time=0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->out_of_interrupt_time);
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->partition_switch_time=0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->partition_switch_time);
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->pwr_52_195           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->pwr_52_195           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->pwr_26_195           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->pwr_26_195           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->pwr_52_360           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->pwr_52_360           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->pwr_26_360           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->pwr_26_360           );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev10                =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev10                );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_r_4_26      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_r_4_26      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_w_4_26      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_w_4_26      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_r_8_26_4_52 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_r_8_26_4_52 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_w_8_26_4_52 =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_w_8_26_4_52 );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_r_8_52      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_r_8_52      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->min_perf_w_8_52      =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->min_perf_w_8_52      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->resv11               =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->resv11               );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->sec_count            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->sec_count            );

        guilin_sleep(30);
#ifndef MSDC_MMC441_SUPPORT
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev12[288]           =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev12[288 - 1]        );
#else
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev9[5]        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev9[5 - 1]     );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->hc_wp_grp_size       =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->hc_wp_grp_size    );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rel_wr_sec_c         =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rel_wr_sec_c      );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->erase_timeout_mult   =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->erase_timeout_mult);
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->hc_erase_grp_size    =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->hc_erase_grp_size );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->acc_size             =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->acc_size          );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->boot_size_mul        =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->boot_size_mul     );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev10          =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev10       );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->boot_info            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->boot_info         );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->mmc44_rev11[275]     =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->mmc44_rev11[275 - 1]  );
#endif
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->s_cmd_set            =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->s_cmd_set         );
        msdc_dbg_print("[guilin %s %d]gSD->mCSD.ext_csd->rev13[7]             =0x%x", __FUNCTION__, __LINE__, gSD->mCSD.ext_csd->rev13[7 - 1]          );
    }

    msdc_dbg_print("[guilin %s %d]CID", __FUNCTION__, __LINE__);
    msdc_dbg_print("[guilin %s %d]gSD->mCID.mid  =0x%x", __FUNCTION__, __LINE__, gSD->mCID.mid                 ); // gSD->mCID.mid  =0x1B
    msdc_dbg_print("[guilin %s %d]gSD->mCID.oid  =0x%x", __FUNCTION__, __LINE__, gSD->mCID.oid                 ); // gSD->mCID.oid  =0x534D
    msdc_dbg_print("[guilin %s %d]gSD->mCID.pnm  =%c%c%c%c%c%c", __FUNCTION__, __LINE__, gSD->mCID.pnm[0], gSD->mCID.pnm[1], gSD->mCID.pnm[2], gSD->mCID.pnm[3], gSD->mCID.pnm[4], gSD->mCID.pnm[5]);
    msdc_dbg_print("[guilin %s %d]gSD->mCID.prv  =0x%x", __FUNCTION__, __LINE__, gSD->mCID.prv                 ); // gSD->mCID.prv  =0x10
    msdc_dbg_print("[guilin %s %d]gSD->mCID.psn  =0x%x", __FUNCTION__, __LINE__, gSD->mCID.psn                 ); // gSD->mCID.psn  =0x7940C2
    msdc_dbg_print("[guilin %s %d]gSD->mCID.year =0x%x", __FUNCTION__, __LINE__, gSD->mCID.year                ); // gSD->mCID.year =0x7D8
    msdc_dbg_print("[guilin %s %d]gSD->mCID.month=0x%x", __FUNCTION__, __LINE__, gSD->mCID.month               ); // gSD->mCID.month=0x8

    msdc_dbg_print("[guilin %s %d]SCR", __FUNCTION__, __LINE__);
    msdc_dbg_print("[guilin %s %d]gSD->mSCR.dat_after_erase=0x%x", __FUNCTION__, __LINE__, gSD->mSCR.dat_after_erase     ); // gSD->mSCR.dat_after_erase=0x0
    msdc_dbg_print("[guilin %s %d]gSD->mSCR.security       =0x%x", __FUNCTION__, __LINE__, gSD->mSCR.security            ); // gSD->mSCR.security       =0x2
    msdc_dbg_print("[guilin %s %d]gSD->mSCR.bus_width      =0x%x", __FUNCTION__, __LINE__, gSD->mSCR.bus_width           ); // gSD->mSCR.bus_width      =0x5
    msdc_dbg_print("[guilin %s %d]gSD->mSCR.spec_ver       =0x%x", __FUNCTION__, __LINE__, gSD->mSCR.spec_ver            ); // gSD->mSCR.spec_ver       =0x1

    guilin_sleep(30);

    msdc_dbg_print("[guilin %s %d]Reg", __FUNCTION__, __LINE__);
    msdc_dbg_print("[guilin %s %d]MSDC_CFG=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_CFG));   // MSDC_CFG=0x1210031
    msdc_dbg_print("[guilin %s %d]MSDC_STA=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_STA));   // MSDC_STA=0x2
    msdc_dbg_print("[guilin %s %d]MSDC_PS=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_PS));     // MSDC_PS=0x1FF0008
    msdc_dbg_print("[guilin %s %d]MSDC_IOCON=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_IOCON)); // MSDC_IOCON=0x1280036
    msdc_dbg_print("[guilin %s %d]MSDC_IOCON1=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_IOCON1)); // MSDC_IOCON1=0x22222

    msdc_dbg_print("[guilin %s %d]SDC_CFG=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_CFG));       // SDC_CFG=0x50038200
    msdc_dbg_print("[guilin %s %d]SDC_CMD=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_CMD));       // SDC_CMD=0x97
    msdc_dbg_print("[guilin %s %d]SDC_ARG=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_ARG));       // SDC_ARG=0x20
    msdc_dbg_print("[guilin %s %d]SDC_IRQMASK0=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_IRQMASK0)); // SDC_IRQMASK0=0x7000F
    msdc_dbg_print("[guilin %s %d]SDC_IRQMASK1=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_IRQMASK1)); // SDC_IRQMASK1=0x0

    msdc_dbg_print("[guilin %s %d]SDIO_CFG=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(SDC_IRQMASK1 + 4)); // SDIO_CFG=0x0

    //    msdc_dbg_print("[guilin %s %d]MSDC_BOOT_CFG=0x%x",__FUNCTION__,__LINE__,MSDC_Reg32(MSDC_BOOT_CFG));    // MSDC_BOOT_CFG=0x0
    //    msdc_dbg_print("[guilin %s %d]MSDC_BOOT_IOCON=0x%x",__FUNCTION__,__LINE__,MSDC_Reg32(MSDC_BOOT_IOCON));// MSDC_BOOT_IOCON=0x0

    msdc_dbg_print("[guilin %s %d]MSDC_CLKACB_CFG=0x%x", __FUNCTION__, __LINE__, MSDC_Reg32(MSDC_CLKACB_CFG)); // MSDC_CLKACB_CFG=0x20000

    guilin_sleep(30);

    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_clock               =%d", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_clock                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->op_clock                 =%d", __FUNCTION__, __LINE__, gMSDC_Handle->op_clock                    );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->total_count              =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->total_count                 );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->timeout_period           =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->timeout_period              );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_input.type          =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_input.type             );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_input.size          =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_input.size             );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_input.count         =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_input.count            );
#if defined(__DMA_API_V2__)
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_input.fixed_pattern =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_input.fixed_pattern    );
#endif
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_menu.TMOD.burst_mode=0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_menu.TMOD.burst_mode   );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_menu.TMOD.cycle     =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_menu.TMOD.cycle        );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_menu.master         =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_menu.master            );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mMSDC_type               =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mMSDC_type                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mIsPresent               =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mIsPresent                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mIsInitialized           =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mIsInitialized              );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mIsChanged               =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mIsChanged                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->is_timeout               =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->is_timeout                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mIsPWDown                =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mIsPWDown                   );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->cmd_sta                  =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->cmd_sta                     );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->dat_sta                  =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->dat_sta                     );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->ins_level                =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->ins_level                   );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->timeout_count            =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->timeout_count               );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->is_poll                  =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->is_poll                     );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->is_aligned               =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->is_aligned                  );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->is_init_timeout          =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->is_init_timeout             );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->send_ilm                 =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->send_ilm                    );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_dmaport             =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_dmaport                );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->dataCrcError_count       =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->dataCrcError_count          );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->trySingleLine            =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->trySingleLine               );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->isCachedBuf              =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->isCachedBuf                 );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->cachedBufCopyPtr         =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->cachedBufCopyPtr            );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->tuningTopology           =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->tuningTopology              );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->MSDC_everPlugOut         =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->MSDC_everPlugOut            );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->MSDC_fastFormat          =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->MSDC_fastFormat             );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdcTimeoutDuration      =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdcTimeoutDuration         );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_clkTuneUpperBund    =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_clkTuneUpperBund       );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->mIsInitMSDC              =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->mIsInitMSDC                 );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->msdc_int                 =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->msdc_int                    );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->LISR_Entry_Count         =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->LISR_Entry_Count            );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDCMDIRQ_Entry_Count     =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDCMDIRQ_Entry_Count        );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDMCIRQ_Entry_Count      =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDMCIRQ_Entry_Count         );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDDATIRQ_Entry_Count     =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDDATIRQ_Entry_Count        );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDR1bIRQ_Entry_count     =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDR1bIRQ_Entry_count        );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDIOIRQ_Entry_Count      =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDIOIRQ_Entry_Count         );
    msdc_dbg_print("[guilin %s %d]gMSDC_Handle->SDPINIRQ_Entry_Count     =0x%x", __FUNCTION__, __LINE__, gMSDC_Handle->SDPINIRQ_Entry_Count        );

    msdc_dbg_print("[guilin %s %d]end", __FUNCTION__, __LINE__);
    guilin_sleep(30);

}


#endif


#endif //#ifdef __MSDC_BASIC_LOAD__

#ifdef __MSDC_SD_SDIO__

#ifdef MT6250
// MT5931(WS1556) === MT6250(WS1734)
// MT5931 POWER :        J763.2 (+3.6V ~ +4.2V)
#define MT5931_EN   12 //GPIO-12 , J802-14
#define MT5931_RST  19 //GPIO-19 , J802-6
#define MT5931_EINT 28 //GPIO-28 , J803-47
#define MT5931_EINT_NUM 1 //EINT1
#endif
#ifdef MT6255
// MT5931(WS1556) === MT6255(WS1632)
// MT5931 POWER :        J201-1 (+3.6V ~ +4.2V)
#define MT5931_EN   8 //GPIO-8 , JP1102-18
#define MT5931_RST  101 //GPIO-101 , JP1103-33
#define MT5931_EINT 1 //GPIO-1 , JP1102-4
#define MT5931_EINT_NUM 12 //EINT12
#endif
#ifdef MT6280
#define MT5931_EN   17 //GPIO-17 , 
#define MT5931_RST  51 //GPIO-101 , 
#define MT5931_EINT 0 //GPIO-1 , 
#define MT5931_EINT_NUM 0 //EINT12
extern const unsigned char WIFI_EINT_NO;
#endif

DCL_HANDLE handle_sdio;

#define TEST_PACKET_MIN_LENGTH 		(140)
#define TEST_PACKET_MAX_LENGTH		(1500)
#define MAX_TX_QUEUE_NUM 		16

#pragma arm section rwdata="DYNAMICCACHEABLERW_C", zidata="DYNAMICCACHEABLEZI_C"
static unsigned char ucDmaBuf[1500]; /*__HOTSPOT_SUPPORT__*/
#pragma arm section

typedef struct _NIC_HIF_TX_HEADER_T
{
    kal_uint16	u2TxByteCount;
    kal_uint8		ucEtherTypeOffset;
    kal_uint8		ucCSUMFlags;
    kal_uint32	dummy[3];
} NIC_HIF_TX_HEADER_T, *P_NIC_HIF_TX_HEADER_T;

typedef enum
{
    RANDOM = 0,
    DATA_FF,
    DATA_00,
    DATA_F0,
    DATA_0F,
    DATA_55,
    DATA_99,
    DATA_AA,
    DATA_66,
} Data_Pattern;

// MT5931
#define WCIR		(0x0000)
#define WHLPCR		(0x0004)
#define WSDIOCSR	(0x0008)
#define WHCR		(0x000c)
#define WHISR		(0x0010)
#define WHIER		(0x0014)
#define WASR		(0x0018)
#define WSICR		(0x001c)
#define WTSR0		(0x0020)
#define WTSR1		(0x0024)
#define WTDR0		(0x0028)
#define WTDR1		(0x002c)
#define	WRDR0		(0x0030)
#define WRDR1		(0x0034)
#define H2DSM0R		(0x0038)
#define H2DSM1R		(0x003c)
#define D2HRM0R		(0x0040)
#define D2HRM1R		(0x0044)
#define D2HRM2R		(0x0048)
#define WRPLR		(0x0050)
#define WEHTCR		(0x0054)

#define FWDLDR		(0x0080)
#define FWDLDSAR	(0x0084)
#define FWDLSR		(0x0088)
#define FWDLCMR0	(0x008c)
#define FWDLCMR1	(0x0090)

//4 CHIP ID Register
#define MCR_WCIR                            0x0000

//4 HIF Low Power Control  Register
#define MCR_WHLPCR                          0x0004

//4 Control  Status Register
#define MCR_WSDIOCSR                        0x0008
#define MCR_WSPICSR                         0x0008

//4 HIF Control Register
#define MCR_WHCR                            0x000C

//4 HIF Interrupt Status  Register
#define MCR_WHISR                           0x0010

//4 HIF Interrupt Enable  Register
#define MCR_WHIER                           0x0014

//4 Abnormal Status Register
#define MCR_WASR                            0x0018

//4 WLAN Software Interrupt Control Register
#define MCR_WSICR                           0x001C

//4 WLAN TX Status Register
#define MCR_WTSR0                           0x0020

//4 WLAN TX Status Register
#define MCR_WTSR1                           0x0024

//4 WLAN TX Data Register 0
#define MCR_WTDR0                           0x0028

//4 WLAN TX Data Register 1
#define MCR_WTDR1                           0x002C

//4 WLAN RX Data Register 0
#define MCR_WRDR0                           0x0030

//4 WLAN RX Data Register 1
#define MCR_WRDR1                           0x0034

//4 Host to Device Send Mailbox 0 Register
#define MCR_H2DSM0R                         0x0038

//4 Host to Device Send Mailbox 1 Register
#define MCR_H2DSM1R                         0x003c

//4 Device to Host Receive Mailbox 0 Register
#define MCR_D2HRM0R                         0x0040

//4 Device to Host Receive Mailbox 1 Register
#define MCR_D2HRM1R                         0x0044

//4 Device to Host Receive Mailbox 2 Register
#define MCR_D2HRM2R                         0x0048

//4 WLAN RX Packet Length Register
#define MCR_WRPLR                           0x0050

//4 EHPI Transaction Count Register
#define MCR_EHTCR                           0x0054

//4 Firmware Download Data Register
#define MCR_FWDLDR                          0x0080

//4 Firmware Download Destination Starting Address Register
#define MCR_FWDLDSAR                        0x0084

//4 Firmware Download Status Register
#define MCR_FWDLSR                          0x0088

//4 WLAN MCU Control & Status Register
#define MCR_WMCSR                           0x008c

//4 WLAN Firmware Download Configuration
#define MCR_FWCFG                           0x0090

#define BIT(x) (1 << (x))

//2 Definition in each register
//3 WCIR 0x0000
#define WCIR_WLAN_READY                  BIT(21)
#define WCIR_POR_INDICATOR               BIT(20)
#define WCIR_REVISION_ID                 BITS(16,19)
#define WCIR_CHIP_ID                     BITS(0,15)

#define MTK_CHIP_REV                     0x00005931
#define MTK_CHIP_MP_REVERSION_ID         0x0

//3 WHLPCR 0x0004
#define WHLPCR_FW_OWN_REQ_CLR            BIT(9)
#define WHLPCR_FW_OWN_REQ_SET            BIT(8)
#define WHLPCR_IS_DRIVER_OWN             BIT(8)
#define WHLPCR_INT_EN_CLR                BIT(1)
#define WHLPCR_INT_EN_SET                BIT(0)

//3 WSDIOCSR 0x0008
#define WSDIOCSR_SDIO_RE_INIT_EN         BIT(0)

//3 WSPICSR 0x0008
#define WCSR_SPI_MODE_SEL                BITS(3,4)
#define WCSR_SPI_ENDIAN_BIG              BIT(2)
#define WCSR_SPI_INT_OUT_MODE            BIT(1)
#define WCSR_SPI_DATA_OUT_MODE           BIT(0)

//3 WHCR 0x000C
#define WHCR_RX_ENHANCE_MODE_EN         BIT(16)
#define WHCR_MAX_HIF_RX_LEN_NUM         BITS(4,7)
#define WHCR_W_MAILBOX_RD_CLR_EN        BIT(2)
#define WHCR_W_INT_CLR_CTRL             BIT(1)
#define WHCR_MCU_DBG_EN                 BIT(0)
#define WHCR_OFFSET_MAX_HIF_RX_LEN_NUM  4

//3 WHISR 0x0010
#define WHISR_D2H_SW_INT                BITS(8,31)
#define WHISR_D2H_SW_ASSERT_INFO_INT    BIT(31)
#define WHISR_FW_OWN_BACK_INT           BIT(4)
#define WHISR_ABNORMAL_INT              BIT(3)
#define WHISR_RX1_DONE_INT              BIT(2)
#define WHISR_RX0_DONE_INT              BIT(1)
#define WHISR_TX_DONE_INT               BIT(0)


//3 WHIER 0x0014
#define WHIER_D2H_SW_INT                BITS(8,31)
#define WHIER_FW_OWN_BACK_INT_EN        BIT(4)
#define WHIER_ABNORMAL_INT_EN           BIT(3)
#define WHIER_RX1_DONE_INT_EN           BIT(2)
#define WHIER_RX0_DONE_INT_EN           BIT(1)
#define WHIER_TX_DONE_INT_EN            BIT(0)
#define WHIER_DEFAULT                   (WHIER_RX0_DONE_INT_EN    | \
        WHIER_RX1_DONE_INT_EN    | \
        WHIER_TX_DONE_INT_EN     | \
        WHIER_ABNORMAL_INT_EN    | \
        WHIER_D2H_SW_INT           \
                                        )


//3 WASR 0x0018
#define WASR_FW_OWN_INVALID_ACCESS      BIT(4)
#define WASR_RX1_UNDER_FLOW             BIT(3)
#define WASR_RX0_UNDER_FLOW             BIT(2)
#define WASR_TX1_OVER_FLOW              BIT(1)
#define WASR_TX0_OVER_FLOW              BIT(0)


//3 WSICR 0x001C
#define WSICR_H2D_SW_INT_SET            BITS(16,31)


//3 WRPLR 0x0050
#define WRPLR_RX1_PACKET_LENGTH         BITS(16,31)
#define WRPLR_RX0_PACKET_LENGTH         BITS(0,15)


//3 FWDLSR 0x0088
#define FWDLSR_FWDL_RDY                 BIT(8)
#define FWDLSR_FWDL_MODE                BIT(0)


//3 WMCSR 0x008c
#define WMCSR_CHIP_RST                  BIT(15) /* write */
#define WMCSR_DL_OK                     BIT(15) /* read */
#define WMCSR_DL_FAIL                   BIT(14)
#define WMCSR_PLLRDY                    BIT(13)
#define WMCSR_WF_ON                     BIT(12)
#define WMCSR_INI_RDY                   BIT(11)
#define WMCSR_WF_EN                     BIT(6)
#define WMCSR_SW_EN                     BIT(5)
#define WMCSR_SPLLEN                    BIT(4)
#define WMCSR_SPWREN                    BIT(3)
#define WMCSR_HSTOPIL                   BIT(2)
#define WMCSR_FWDLRST                   BIT(1)
#define WMCSR_FWDLEN                    BIT(0)


//3 FWCFG 0x0090
#define FWCFG_KSEL                      BITS(14,15)
#define FWCFG_FLEN                      BITS(0,13)

#define CFG_RESPONSE_POLLING_TIMEOUT            512
/* Type definition for WLAN STATUS */
typedef kal_uint32                 WLAN_STATUS, *P_WLAN_STATUS;

#define WLAN_STATUS_SUCCESS                     ((WLAN_STATUS) 0x00000000L)
#define WLAN_STATUS_FAILURE                     ((WLAN_STATUS) 0xC0000001L)

#define CFG_FW_LOAD_ADDRESS                     0xFF900000
#define CFG_FW_START_ADDRESS                    0x00000000
#define CMD_PKT_SIZE_FOR_IMAGE              2048 /* !< 2048 Bytes CMD payload buffer */

typedef struct _HIF_HW_TX_HEADER_T
{
    kal_uint16     u2TxByteCount;
    kal_uint8      ucEtherTypeOffset;
    kal_uint8      ucCSflags;
    kal_uint8      aucBuffer[4];
} HIF_HW_TX_HEADER_T, *P_HIF_HW_TX_HEADER_T;

#pragma arm section rwdata="DYNAMICCACHEABLERW_C", zidata="DYNAMICCACHEABLEZI_C"
__align(32) kal_uint8 wndrv_cmd_temp_buf[CMD_PKT_SIZE_FOR_IMAGE + 512];
#pragma arm section

#define HIF_HW_TX_HDR_SIZE                  OFFSET_OF(HIF_HW_TX_HEADER_T, aucBuffer[0])
#define OFFSET_OF(_type, _field)    ((kal_uint32)&(((_type *)0)->_field))
#define ALIGN_4(_value)             (((_value) + 3) & ~3u)
#define ALIGN_32(_value)             (((_value) + 31) & ~31u)
#define FUNC1_SDIO_BLK_SIZE (512)
#define DMA_THRESHOLD 128
#define SWITCH_TO_NONCACHEABLE 0
#define SWITCH_TO_CACHEABLE 1
kal_uint8 payload[1500];
kal_uint8 pucTXBuf[1500];
kal_uint8 pucRXBuf[1500];

kal_uint8 const mt5931_E3_Beta_loopback_firmware_hex[] =
{
    0x74, 0xDB, 0x7D, 0xB4, 0x6E, 0xA7, 0x12, 0xCE, 0x3C, 0x69, 0xFF, 0xD6, 0xF3, 0x13, 0x47, 0x60
    , 0xC7, 0x6E, 0x5C, 0xA1, 0x74, 0x29, 0x70, 0x0C, 0x6A, 0xA3, 0x42, 0x02, 0x6D, 0x1B, 0xCE, 0x6F
    , 0x2F, 0x07, 0x8A, 0x75, 0x63, 0xF8, 0xCD, 0x46, 0x3C, 0x43, 0x7E, 0x62, 0x24, 0x58, 0x19, 0x11
    , 0x10, 0x30, 0x84, 0x36, 0x0F, 0x06, 0x52, 0x71, 0x86, 0x5F, 0x09, 0x0F, 0x01, 0x8A, 0x51, 0x32
    , 0x84, 0xEE, 0xA8, 0x7F, 0xF8, 0xEF, 0xD8, 0xE7, 0x1E, 0xF1, 0xE5, 0x0D, 0x43, 0x69, 0x1F, 0xF7
    , 0x91, 0xC3, 0xFE, 0xA1, 0xA7, 0x30, 0x50, 0x9B, 0xED, 0xBC, 0xE6, 0x21, 0xFB, 0x58, 0xCD, 0xAD
    , 0x08, 0x34, 0xB4, 0x7E, 0x4B, 0xB1, 0x18, 0x21, 0xD6, 0x98, 0xE9, 0x16, 0x94, 0xFE, 0x11, 0x2E
    , 0xEC, 0xE6, 0x61, 0x25, 0xD2, 0x3C, 0x14, 0xDC, 0x36, 0xF3, 0x22, 0x35, 0xDF, 0xA7, 0xE7, 0x59
    , 0xA7, 0xDD, 0x1E, 0xF2, 0x4D, 0x1D, 0x93, 0xA2, 0x22, 0xDE, 0xE5, 0x05, 0x50, 0xA5, 0xE6, 0xCA
    , 0xC0, 0xEC, 0x76, 0x7E, 0x13, 0x8B, 0xBA, 0x3D, 0x4C, 0xC9, 0xCE, 0x6D, 0x50, 0x0F, 0x86, 0x3D
    , 0x51, 0x52, 0xB2, 0xB5, 0xE9, 0xA2, 0x32, 0x2B, 0x9E, 0xB4, 0x65, 0x8F, 0x60, 0x18, 0xF3, 0xEB
    , 0xE9, 0xEA, 0xD2, 0xEE, 0x81, 0xD0, 0x53, 0x44, 0x06, 0xBC, 0x43, 0x51, 0x2C, 0xA8, 0x9B, 0xEF
    , 0xB5, 0x4C, 0x87, 0x80, 0x02, 0x94, 0xFD, 0x25, 0x6F, 0x28, 0x9E, 0x84, 0xA0, 0xDA, 0x6F, 0xA3
    , 0x30, 0x9B, 0x68, 0xA3, 0x9E, 0x51, 0xBE, 0x1B, 0x49, 0x68, 0xBA, 0x09, 0x6E, 0xEF, 0xF9, 0x52
    , 0x8F, 0x97, 0x31, 0x3D, 0x77, 0xFF, 0x0C, 0xF1, 0x5A, 0xE4, 0x24, 0x3A, 0xCC, 0x44, 0x9E, 0xF6
    , 0x34, 0x69, 0x3B, 0x6E, 0xDE, 0xE1, 0x12, 0xA1, 0x1A, 0x3C, 0x18, 0xA3, 0x62, 0xB9, 0x8D, 0x3D
    , 0xAA, 0x9F, 0x38, 0x52, 0x9A, 0x76, 0x36, 0x39, 0xF3, 0x51, 0x01, 0xEE, 0xBC, 0xCF, 0x59, 0x26
    , 0x58, 0x2A, 0x25, 0xD5, 0x4E, 0x25, 0xF8, 0xBC, 0xC2, 0x94, 0x91, 0x17, 0x1B, 0x0B, 0x0F, 0xDF
    , 0x7B, 0x6A, 0x61, 0x39, 0xE0, 0x49, 0x0F, 0x31, 0x97, 0x1C, 0xC4, 0x20, 0xD6, 0x0B, 0xA6, 0xF4
    , 0xA5, 0x7A, 0xCC, 0xC4, 0x1D, 0x38, 0xEC, 0x32, 0x0A, 0x83, 0xE1, 0xB2, 0x64, 0x4F, 0x9F, 0x4C
    , 0x9A, 0x07, 0xC1, 0xC5, 0xEA, 0x1B, 0xAC, 0x14, 0x41, 0xB9, 0xEA, 0x0C, 0x3F, 0x6F, 0x27, 0xAF
    , 0x1B, 0x87, 0x56, 0x5E, 0xAE, 0xB6, 0xB6, 0x53, 0xA9, 0xC8, 0xA4, 0xC4, 0x98, 0x97, 0xA4, 0x0F
    , 0xAD, 0xB6, 0x89, 0x10, 0xAA, 0x99, 0xF5, 0x3C, 0xF7, 0x92, 0x09, 0x62, 0x95, 0xEC, 0x14, 0xE5
    , 0x81, 0x20, 0xC2, 0x8F, 0xCD, 0xD0, 0x68, 0x9F, 0x9A, 0xF5, 0x7E, 0x3B, 0x13, 0x8D, 0xC9, 0x81
    , 0x01, 0xC3, 0x39, 0xD9, 0xB5, 0x4C, 0xA4, 0x06, 0x7A, 0x76, 0xDE, 0x55, 0x53, 0x03, 0x3C, 0xA4
    , 0xBF, 0x24, 0x19, 0x96, 0xBE, 0xD5, 0x15, 0xB5, 0xAF, 0x76, 0x9F, 0x4D, 0x75, 0x4D, 0xE3, 0xA8
    , 0x03, 0xB0, 0x12, 0xE9, 0x45, 0x8D, 0xB3, 0x67, 0x50, 0xE5, 0xD3, 0x1C, 0xB5, 0x19, 0x32, 0x27
    , 0x63, 0x38, 0x11, 0x64, 0x19, 0xC7, 0x4E, 0xF4, 0xEE, 0x01, 0xAF, 0xB5, 0x03, 0x97, 0x69, 0x14
    , 0x97, 0x9E, 0x40, 0xEB, 0x04, 0xDD, 0x7C, 0xFD, 0xD0, 0xA6, 0x02, 0xD2, 0x30, 0x1B, 0x07, 0xBD
    , 0x72, 0xC7, 0xED, 0xB5, 0x59, 0x53, 0x9B, 0x97, 0x66, 0x3B, 0x07, 0x06, 0x78, 0x51, 0xE6, 0x06
    , 0xD2, 0xFE, 0x33, 0x1E, 0x73, 0xCC, 0x7C, 0x91, 0x66, 0x9A, 0xBA, 0x8E, 0x6E, 0x2B, 0x4D, 0x5E
    , 0x2D, 0x2C, 0x91, 0x3C, 0x8F, 0x23, 0xF6, 0x5D, 0x6F, 0xBF, 0x84, 0x9F, 0x0B, 0xF5, 0x81, 0x02
    , 0x0A, 0x4B, 0xDE, 0x16, 0x7A, 0x80, 0x18, 0x08, 0x5B, 0x2A, 0xFA, 0x3A, 0x6B, 0x36, 0x07, 0xCF
    , 0x84, 0xEE, 0xA8, 0x7F, 0xF8, 0xEF, 0xD8, 0xE7, 0x1E, 0xF1, 0xE5, 0x0D, 0x43, 0x69, 0x1F, 0xF7
    , 0x91, 0xC3, 0xFE, 0xA1, 0xA7, 0x30, 0x50, 0x9B, 0xED, 0xBC, 0xE6, 0x21, 0xFB, 0x58, 0xCD, 0xAD
    , 0x08, 0x34, 0xB4, 0x7E, 0x4B, 0xB1, 0x18, 0x21, 0xD6, 0x98, 0xE9, 0x16, 0x94, 0xFE, 0x11, 0x2E
    , 0x7A, 0xB7, 0xD9, 0x69, 0x2E, 0xC4, 0x19, 0xE7, 0x9B, 0x85, 0x9F, 0x3F, 0x31, 0x43, 0xA7, 0xCC
    , 0x84, 0xEE, 0xA8, 0x7F, 0xF8, 0xEF, 0xD8, 0xE7, 0x1E, 0xF1, 0xE5, 0x0D, 0x43, 0x69, 0x1F, 0xF7
    , 0x91, 0xC3, 0xFE, 0xA1, 0xA7, 0x30, 0x50, 0x9B, 0xED, 0xBC, 0xE6, 0x21, 0xFB, 0x58, 0xCD, 0xAD
    , 0x08, 0x34, 0xB4, 0x7E, 0x4B, 0xB1, 0x18, 0x21, 0xD6, 0x98, 0xE9, 0x16, 0x94, 0xFE, 0x11, 0x2E
    , 0x22, 0xEE, 0x34, 0x46, 0x5A, 0x19, 0xE1, 0x1A, 0x67, 0x74, 0x7A, 0xD2, 0xA2, 0xCB, 0x69, 0x5C
    , 0xA7, 0xDD, 0x1E, 0xF2, 0x4D, 0x1D, 0x93, 0xA2, 0x22, 0xDE, 0xE5, 0x05, 0x50, 0xA5, 0xE6, 0xCA
    , 0xC0, 0xEC, 0x76, 0x7E, 0x13, 0x8B, 0xBA, 0x3D, 0x4C, 0xC9, 0xCE, 0x6D, 0x50, 0x0F, 0x86, 0x3D
    , 0x83, 0x95, 0xFF, 0xA2, 0xA4, 0x31, 0xF5, 0x88, 0x38, 0x00, 0xB9, 0x27, 0xA3, 0x7B, 0xEF, 0x8A
    , 0x5C, 0x79, 0xF1, 0x26, 0x42, 0x2C, 0x68, 0x27, 0x40, 0x02, 0x52, 0x97, 0xD6, 0x51, 0x4D, 0x3F
    , 0xB5, 0x4C, 0x87, 0x80, 0x02, 0x94, 0xFD, 0x25, 0x6F, 0x28, 0x9E, 0x84, 0xA0, 0xDA, 0x6F, 0xA3
    , 0x30, 0x9B, 0x68, 0xA3, 0x9E, 0x51, 0xBE, 0x1B, 0x49, 0x68, 0xBA, 0x09, 0x6E, 0xEF, 0xF9, 0x52
    , 0x25, 0x15, 0x38, 0x2C, 0x07, 0xDB, 0x76, 0xC9, 0x7C, 0x2F, 0xC6, 0x60, 0x4F, 0xA2, 0xE3, 0xC4
    , 0x34, 0x69, 0x3B, 0x6E, 0xDE, 0xE1, 0x12, 0xA1, 0x1A, 0x3C, 0x18, 0xA3, 0x62, 0xB9, 0x8D, 0x3D
    , 0xAA, 0x9F, 0x38, 0x52, 0x9A, 0x76, 0x36, 0x39, 0xF3, 0x51, 0x01, 0xEE, 0xBC, 0xCF, 0x59, 0x26
    , 0x58, 0x2A, 0x25, 0xD5, 0x4E, 0x25, 0xF8, 0xBC, 0xC2, 0x94, 0x91, 0x17, 0x1B, 0x0B, 0x0F, 0xDF
    , 0x0B, 0x7D, 0x19, 0x57, 0xB6, 0xF2, 0x8C, 0x9B, 0xCA, 0x0B, 0xDC, 0x56, 0x1C, 0x63, 0x8D, 0x1D
    , 0xD2, 0xFE, 0x33, 0x1E, 0x73, 0xCC, 0x7C, 0x91, 0x66, 0x9A, 0xBA, 0x8E, 0x6E, 0x2B, 0x4D, 0x5E
    , 0x2D, 0x2C, 0x91, 0x3C, 0x8F, 0x23, 0xF6, 0x5D, 0x6F, 0xBF, 0x84, 0x9F, 0x0B, 0xF5, 0x81, 0x02
    , 0x2F, 0x27, 0x25, 0x17, 0x1D, 0x25, 0x03, 0x43, 0x4B, 0x34, 0x42, 0x74, 0x45, 0x67, 0xCE, 0x68
    , 0x34, 0x69, 0x3B, 0x6E, 0xDE, 0xE1, 0x12, 0xA1, 0x1A, 0x3C, 0x18, 0xA3, 0x62, 0xB9, 0x8D, 0x3D
    , 0xAA, 0x9F, 0x38, 0x52, 0x9A, 0x76, 0x36, 0x39, 0xF3, 0x51, 0x01, 0xEE, 0xBC, 0xCF, 0x59, 0x26
    , 0x58, 0x2A, 0x25, 0xD5, 0x4E, 0x25, 0xF8, 0xBC, 0xC2, 0x94, 0x91, 0x17, 0x1B, 0x0B, 0x0F, 0xDF
    , 0x3A, 0x95, 0xC8, 0x83, 0xF3, 0x0B, 0x46, 0x50, 0x95, 0xA5, 0x06, 0x15, 0xFB, 0x2B, 0x67, 0xE5
    , 0xD2, 0xFE, 0x33, 0x1E, 0x73, 0xCC, 0x7C, 0x91, 0x66, 0x9A, 0xBA, 0x8E, 0x6E, 0x2B, 0x4D, 0x5E
    , 0x2D, 0x2C, 0x91, 0x3C, 0x8F, 0x23, 0xF6, 0x5D, 0x6F, 0xBF, 0x84, 0x9F, 0x0B, 0xF5, 0x81, 0x02
    , 0xD3, 0xC1, 0x82, 0x91, 0x78, 0xA3, 0x12, 0x9F, 0xDD, 0xB1, 0xDE, 0x2E, 0xB5, 0x47, 0xD5, 0x51
    , 0x01, 0xDD, 0x20, 0x23, 0x97, 0x00, 0xE9, 0x45, 0x75, 0x69, 0xE2, 0xD1, 0xD7, 0xC5, 0x43, 0x36
    , 0x81, 0xA0, 0x4C, 0x6B, 0x02, 0x42, 0xC5, 0xEC, 0xCB, 0x94, 0x06, 0x3E, 0x13, 0xB1, 0x8F, 0x44
    , 0x81, 0xA0, 0x4C, 0x6B, 0x02, 0x42, 0xC5, 0xEC, 0xCB, 0x94, 0x06, 0x3E, 0x13, 0xB1, 0x8F, 0x44
    , 0xAC, 0xFB, 0x1F, 0x99, 0xF7, 0x6D, 0xAB, 0x37, 0x68, 0x2F, 0x95, 0x73, 0xE0, 0x84, 0x6E, 0x02
    , 0x81, 0xA0, 0x4C, 0x6B, 0x02, 0x42, 0xC5, 0xEC, 0xCB, 0x94, 0x06, 0x3E, 0x13, 0xB1, 0x8F, 0x44
    , 0xAD, 0x20, 0xFD, 0x61, 0x97, 0xF7, 0xBD, 0x96, 0xDD, 0xB9, 0x23, 0x12, 0xF9, 0xBE, 0x41, 0x58
    , 0x55, 0x42, 0x8E, 0x49, 0x16, 0xEF, 0xCB, 0xF5, 0x8C, 0x4E, 0x1D, 0x7C, 0x3C, 0x12, 0xF8, 0xA4
    , 0xA0, 0x08, 0xC3, 0x5F, 0x04, 0xF5, 0xAC, 0x42, 0x4F, 0x3D, 0x1D, 0x74, 0x80, 0x35, 0x6F, 0xFC
    , 0x99, 0x53, 0x85, 0xC0, 0x07, 0x4F, 0xD3, 0xE5, 0xF9, 0x04, 0xCE, 0xE7, 0xF9, 0x76, 0x61, 0xE0
    , 0x13, 0x6C, 0xC2, 0x84, 0x09, 0x87, 0x16, 0x13, 0x27, 0xFB, 0x15, 0x23, 0x47, 0x14, 0x82, 0x9D
    , 0x98, 0xE3, 0x5A, 0x96, 0x9D, 0xBF, 0xB5, 0x8B, 0x58, 0x71, 0x32, 0xC2, 0xDF, 0x43, 0x79, 0x1B
    , 0x25, 0x8B, 0x60, 0xBC, 0x49, 0x99, 0x03, 0x47, 0x37, 0xA1, 0x50, 0x44, 0x45, 0xF2, 0x2E, 0x33
    , 0x7D, 0x7E, 0x71, 0x29, 0xDA, 0x73, 0x58, 0xF3, 0x8A, 0x9B, 0xD7, 0xF1, 0x95, 0x92, 0x24, 0xE0
    , 0xE0, 0xA7, 0xC8, 0x5A, 0x78, 0x5C, 0xA0, 0x48, 0x8B, 0x97, 0xA0, 0x1A, 0xA1, 0xE9, 0xED, 0x5D
    , 0x82, 0xED, 0x1B, 0x5A, 0xDA, 0x1A, 0x64, 0x0F, 0x47, 0x55, 0x21, 0x65, 0xE7, 0x80, 0x8A, 0x20
    , 0x13, 0xA9, 0x1C, 0xE3, 0x64, 0xA4, 0xBA, 0x42, 0x06, 0x91, 0x0E, 0x57, 0x10, 0xF7, 0x04, 0x50
    , 0x08, 0xBF, 0xEA, 0xAC, 0xDA, 0xA4, 0x1F, 0x3D, 0xFC, 0xBF, 0xD4, 0x48, 0xE5, 0x02, 0x5F, 0xFA
    , 0x79, 0xD0, 0x2B, 0xAA, 0x45, 0xC4, 0x15, 0xB0, 0x4B, 0x2D, 0x81, 0xD0, 0xDA, 0x50, 0xDE, 0xB2
    , 0x4F, 0xB2, 0xCB, 0x50, 0x37, 0x9E, 0xFA, 0x43, 0xEC, 0x8D, 0xE0, 0xDF, 0x5E, 0x96, 0x4E, 0xDE
    , 0x45, 0x17, 0x77, 0xBE, 0x2C, 0x0E, 0xF1, 0x89, 0x92, 0x44, 0xDC, 0x3E, 0xC9, 0xBC, 0x9C, 0x8F
    , 0x33, 0x36, 0xD6, 0x51, 0xE0, 0xB9, 0xE0, 0x2E, 0xB9, 0x06, 0xC6, 0xF1, 0xE5, 0xCD, 0x86, 0xDB
    , 0x24, 0x2C, 0xFE, 0x98, 0x59, 0x63, 0x35, 0x73, 0x45, 0x54, 0xD4, 0x3C, 0x7B, 0x0E, 0x23, 0xFC
    , 0x5D, 0x94, 0xC9, 0x02, 0xB4, 0xC6, 0xAB, 0x0C, 0xF7, 0xC7, 0x7E, 0x7D, 0x69, 0x95, 0x47, 0xF0
    , 0x87, 0xD6, 0x7D, 0x7C, 0x2C, 0x18, 0x38, 0x0A, 0x61, 0x50, 0xD5, 0xA3, 0xEE, 0xEB, 0xBC, 0x14
    , 0x38, 0xA0, 0x4B, 0xAE, 0xC3, 0x65, 0x24, 0x9B, 0x54, 0x23, 0x1F, 0xE1, 0xCB, 0xA9, 0xCE, 0xB5
    , 0x8A, 0x42, 0x35, 0x7F, 0x1F, 0xED, 0xC1, 0x24, 0x9F, 0x7B, 0xB2, 0xB4, 0x8E, 0xA7, 0x44, 0x2B
    , 0xCE, 0x92, 0x9C, 0x00, 0xA1, 0x16, 0x35, 0x00, 0x62, 0x29, 0xCF, 0xB7, 0x45, 0x27, 0x49, 0x60
    , 0x9B, 0x61, 0x76, 0xE1, 0x2E, 0xBD, 0xE1, 0x7B, 0x12, 0x52, 0x10, 0xB9, 0xB6, 0xEB, 0x4B, 0xC1
    , 0x35, 0x95, 0x08, 0x7B, 0xD6, 0xD3, 0x8E, 0xBF, 0xB5, 0xCF, 0xD5, 0x34, 0x62, 0xFE, 0x0C, 0x08
    , 0xFA, 0x94, 0x18, 0x6E, 0x86, 0xB4, 0xA4, 0x2F, 0x97, 0xEB, 0xC4, 0xB3, 0x32, 0xEE, 0xEB, 0xB5
    , 0x13, 0x86, 0xD3, 0x68, 0x8C, 0xDE, 0x8C, 0xD4, 0x8D, 0xE7, 0xEF, 0x79, 0x00, 0x7C, 0xAE, 0x36
    , 0x79, 0xBF, 0x2E, 0x13, 0xF6, 0x58, 0x43, 0xB2, 0x3F, 0xD6, 0x2F, 0xCF, 0x51, 0x96, 0x19, 0x44
    , 0x29, 0xF8, 0x9A, 0xEE, 0x17, 0xFD, 0xCE, 0x42, 0xD4, 0x5C, 0x8B, 0xA4, 0x2B, 0x17, 0x5E, 0x51
    , 0xEE, 0x05, 0xC7, 0x54, 0xC9, 0xCE, 0x6E, 0x9D, 0x95, 0x8C, 0x96, 0x11, 0x9A, 0x29, 0x46, 0x21
    , 0x85, 0x96, 0xF8, 0xBA, 0xEC, 0x6F, 0x63, 0x00, 0x3D, 0x92, 0xD9, 0x92, 0xD3, 0x38, 0xDF, 0x95
    , 0x25, 0xBE, 0xAC, 0x59, 0x17, 0x0A, 0x9B, 0x0A, 0x5D, 0xDC, 0x4B, 0x8C, 0xF8, 0x67, 0x21, 0x5F
    , 0xD2, 0x20, 0xF7, 0xCF, 0x50, 0x84, 0x29, 0x51, 0xE3, 0xCD, 0xFF, 0x85, 0x40, 0x5C, 0x38, 0x93
    , 0x39, 0x6A, 0x44, 0x72, 0x32, 0x1C, 0xF9, 0xEC, 0xBB, 0x4E, 0x26, 0xF2, 0x05, 0x48, 0x79, 0x8C
    , 0x2E, 0xAA, 0x72, 0x6B, 0xCB, 0x24, 0x9E, 0x09, 0x27, 0x43, 0xE7, 0xEA, 0x1E, 0x3A, 0xB9, 0xBE
    , 0xA6, 0x3A, 0xBD, 0x3B, 0xD7, 0x16, 0x8A, 0x00, 0x8D, 0xF5, 0x6D, 0x91, 0x7D, 0x68, 0x91, 0x32
    , 0x88, 0xE5, 0x82, 0xAE, 0x24, 0xAC, 0x38, 0x07, 0x9F, 0x3F, 0x47, 0x93, 0xB2, 0x41, 0x1D, 0xBF
    , 0xD7, 0xFC, 0xF0, 0x12, 0x3F, 0xA1, 0xB5, 0xF1, 0xB4, 0x7B, 0x58, 0x94, 0x2A, 0x2F, 0xAE, 0xC2
    , 0x4D, 0xF3, 0xA6, 0x5A, 0x4D, 0xB9, 0x3F, 0x0E, 0xA1, 0x67, 0xE9, 0xAF, 0x03, 0xA5, 0xF3, 0x7F
    , 0x45, 0x85, 0x64, 0x3C, 0xE3, 0x2E, 0xA3, 0x31, 0x03, 0xD4, 0x3A, 0xF0, 0xB5, 0x94, 0xF9, 0x46
    , 0xCE, 0xA4, 0x72, 0xDC, 0x65, 0xD1, 0x59, 0xBE, 0x0B, 0xAD, 0xE5, 0x5D, 0xBA, 0x55, 0xE0, 0xC1
    , 0x82, 0x6E, 0x4A, 0x14, 0xC9, 0x55, 0xC6, 0xC0, 0x22, 0xF6, 0x57, 0x80, 0xF0, 0x02, 0xD9, 0xBD
    , 0x4C, 0x9D, 0x3C, 0xDC, 0xC7, 0x5F, 0xCA, 0xF0, 0x3E, 0xDA, 0xFF, 0xFE, 0x69, 0xAF, 0xDA, 0x38
    , 0x20, 0x0B, 0x14, 0x4F, 0xBB, 0x9B, 0xD0, 0xA4, 0x01, 0x63, 0x1F, 0x61, 0x24, 0x7F, 0x87, 0xB6
    , 0x47, 0xEA, 0x7E, 0xEA, 0x74, 0xA4, 0x00, 0xDC, 0x49, 0xE3, 0x3A, 0x3C, 0xEF, 0x67, 0xF6, 0xB7
    , 0x21, 0x09, 0x25, 0x96, 0x6F, 0xE8, 0x76, 0xEF, 0xF2, 0x6C, 0x6E, 0xF5, 0xCF, 0x06, 0x37, 0x24
    , 0x00, 0xF2, 0xA7, 0x27, 0x4B, 0xE3, 0xC3, 0x9C, 0x9E, 0x93, 0xB5, 0xA4, 0x11, 0x65, 0x06, 0x4C
    , 0x03, 0x97, 0x1D, 0x88, 0x3B, 0x14, 0x72, 0x5B, 0x52, 0xA5, 0xB8, 0x03, 0x68, 0xE5, 0xF1, 0x98
    , 0x06, 0x48, 0xF7, 0x3E, 0x33, 0x29, 0xE3, 0x04, 0xEB, 0xD7, 0xCD, 0x69, 0xD9, 0x8E, 0x84, 0x15
    , 0xBE, 0x21, 0xFC, 0x31, 0x99, 0x41, 0x58, 0x3C, 0x72, 0x6F, 0x73, 0x11, 0x43, 0x78, 0x5A, 0xF8
    , 0x71, 0xDC, 0x02, 0x10, 0x59, 0xC8, 0xB9, 0x03, 0xB8, 0x25, 0x60, 0xDF, 0x22, 0x45, 0x4F, 0xF0
    , 0x7E, 0x50, 0xDE, 0x54, 0x1F, 0x58, 0x8A, 0x5C, 0x93, 0xA9, 0x12, 0x2C, 0x95, 0x4C, 0x80, 0x5B
    , 0x32, 0x8A, 0x78, 0x2C, 0x9D, 0x58, 0x2C, 0xB9, 0x40, 0xCB, 0x64, 0xFB, 0x59, 0x1E, 0xE8, 0xBD
    , 0xBF, 0x64, 0x3F, 0x58, 0x76, 0xAE, 0xC2, 0xDF, 0x9A, 0x57, 0x69, 0xBB, 0x6C, 0xA0, 0x54, 0x0B
    , 0xCA, 0xCA, 0x6A, 0xB6, 0xA3, 0x79, 0x54, 0x48, 0x71, 0x67, 0x40, 0x3B, 0x8E, 0x59, 0x94, 0xFB
    , 0x31, 0xA6, 0xEE, 0xAF, 0x53, 0xC9, 0x24, 0xD6, 0x77, 0x4C, 0xE5, 0x34, 0xAD, 0x93, 0xD5, 0xCA
    , 0x24, 0x61, 0x09, 0x66, 0x42, 0x65, 0x27, 0x7B, 0x1D, 0x3C, 0x35, 0x06, 0xB9, 0xA9, 0x13, 0xE0
    , 0x9C, 0x08, 0xEC, 0x53, 0xB7, 0xAC, 0x71, 0x89, 0x2D, 0xEE, 0x34, 0xAE, 0x3E, 0x1D, 0x47, 0xDE
    , 0x42, 0x17, 0xBA, 0xB8, 0x83, 0x96, 0xE5, 0x91, 0x39, 0x7D, 0xBA, 0x6E, 0x51, 0x6A, 0x48, 0xC3
    , 0x4A, 0x9B, 0x12, 0x48, 0xA4, 0x5D, 0xD4, 0x29, 0xCA, 0x42, 0xC3, 0x75, 0xFE, 0xD9, 0xA1, 0x95
    , 0xD6, 0xE3, 0xB9, 0x24, 0xC2, 0xD5, 0x5F, 0xF7, 0xBF, 0xB8, 0x93, 0x68, 0xCA, 0xCD, 0xF3, 0x4D
    , 0xBA, 0x07, 0x63, 0xA6, 0x9D, 0xB1, 0x4D, 0x10, 0xF9, 0x61, 0xFB, 0x8C, 0x10, 0x27, 0x93, 0xEA
    , 0x4A, 0x8A, 0x61, 0x87, 0x6E, 0x16, 0x46, 0xD3, 0x14, 0xD3, 0x39, 0x9E, 0x0B, 0xB4, 0xE4, 0x10
    , 0xDE, 0x07, 0xE4, 0x69, 0x4F, 0xC2, 0x20, 0x09, 0x2B, 0x68, 0x4F, 0x9E, 0xF6, 0xD8, 0xCA, 0x9E
    , 0x8A, 0xBD, 0x1B, 0x4B, 0xC1, 0x3C, 0x0B, 0x4D, 0xB9, 0x3A, 0x48, 0x03, 0xBA, 0xB3, 0xD4, 0xDF
    , 0x7A, 0x93, 0x5D, 0x4D, 0x8A, 0xE7, 0x42, 0xF6, 0x73, 0x45, 0x1F, 0x36, 0xB6, 0xE0, 0xCB, 0xF6
    , 0x22, 0xE5, 0x5B, 0x64, 0x8B, 0x51, 0xB1, 0x55, 0xC6, 0x2A, 0xD0, 0xB6, 0xAB, 0x48, 0xDA, 0x66
    , 0xDF, 0xFD, 0xAF, 0x76, 0x47, 0x49, 0x03, 0x69, 0xB8, 0xF6, 0x05, 0x08, 0x40, 0x00, 0xFB, 0xF5
    , 0xB7, 0x65, 0x15, 0xD1, 0xCB, 0xD0, 0x0E, 0xFB, 0x9A, 0x38, 0xAF, 0x76, 0x23, 0x2D, 0x51, 0x3A
    , 0xFF, 0x5E, 0x56, 0xB9, 0x25, 0xD1, 0xCB, 0x94, 0xD0, 0x05, 0x92, 0x1D, 0xED, 0xCB, 0x70, 0xA6
    , 0x6B, 0x0F, 0x41, 0x41, 0x8B, 0x3F, 0x3E, 0xA7, 0x5B, 0x73, 0xD1, 0xE8, 0x62, 0x56, 0x73, 0x64
    , 0xB4, 0x4D, 0xF8, 0x99, 0x79, 0x39, 0xC1, 0xCD, 0xA0, 0xCA, 0x06, 0xF3, 0xF4, 0xCD, 0x66, 0x56
    , 0x75, 0xE8, 0x21, 0xF6, 0x9A, 0xE3, 0xB1, 0x2B, 0x5B, 0x0F, 0x9F, 0xDE, 0x7A, 0xA5, 0xD1, 0x3C
    , 0xE1, 0x11, 0x41, 0x8C, 0xCB, 0x9D, 0x25, 0x09, 0x4F, 0x2E, 0x83, 0x62, 0x9E, 0xCD, 0x77, 0x79
    , 0x82, 0x4C, 0xB0, 0xEA, 0x02, 0xE3, 0x66, 0x9D, 0x10, 0x13, 0x75, 0x8E, 0xEF, 0x82, 0x6F, 0xDA
    , 0xB4, 0xD6, 0x37, 0xD7, 0x6A, 0x26, 0x72, 0x62, 0x8F, 0x2D, 0xBD, 0xED, 0x23, 0xFE, 0xC4, 0xCE
    , 0x5E, 0x1E, 0x5B, 0xDF, 0xF1, 0xFD, 0x50, 0x71, 0xD9, 0xAF, 0xE9, 0xCB, 0x07, 0xAA, 0x7C, 0xC6
    , 0x34, 0x1A, 0x8A, 0x85, 0x25, 0x16, 0x1D, 0x55, 0x96, 0x5C, 0x8B, 0xA0, 0x6B, 0x54, 0xC5, 0x98
    , 0x80, 0x98, 0x4D, 0x45, 0x6A, 0x96, 0x3C, 0x1A, 0x1C, 0x8D, 0x8B, 0xB8, 0x6D, 0x91, 0x6B, 0x30
    , 0xEF, 0x11, 0x6D, 0x25, 0x84, 0x82, 0x9C, 0xD7, 0x6A, 0x18, 0x89, 0xCA, 0x88, 0xEA, 0x6F, 0x56
    , 0xBE, 0x82, 0x03, 0xC0, 0xA3, 0xBB, 0x22, 0xAA, 0x9E, 0x99, 0x7D, 0x9D, 0x1C, 0x06, 0x8E, 0x0C
    , 0x14, 0x0A, 0xC9, 0x18, 0x2D, 0x18, 0x8A, 0x3B, 0xC3, 0x88, 0x07, 0x19, 0x54, 0xD3, 0x2D, 0xC2
    , 0x64, 0x2B, 0x97, 0xB5, 0xED, 0x71, 0x19, 0xAA, 0xED, 0x34, 0xEC, 0xF9, 0xEE, 0x89, 0x33, 0x19
    , 0x2C, 0x33, 0x9D, 0xA7, 0x85, 0x98, 0x94, 0x3B, 0xE1, 0x5C, 0x5E, 0x53, 0x7F, 0x4A, 0x6B, 0xC4
    , 0x48, 0xF4, 0xBC, 0x44, 0x93, 0x78, 0xC8, 0xC0, 0xE3, 0xD9, 0x48, 0x59, 0xDE, 0xB5, 0xE8, 0x8F
    , 0xB1, 0x61, 0x4B, 0x67, 0xE6, 0x99, 0x47, 0x3E, 0x9A, 0xB7, 0x4D, 0x5C, 0x46, 0x0B, 0x4D, 0x5E
    , 0xDF, 0xE8, 0xB9, 0x2B, 0xC9, 0xF8, 0xD3, 0x87, 0x4F, 0xA2, 0x3D, 0x2E, 0x2A, 0x22, 0x2B, 0x4B
    , 0x23, 0x55, 0x7F, 0x0D, 0x0C, 0x20, 0xF4, 0x43, 0xCB, 0xF2, 0x31, 0x18, 0xD8, 0xC3, 0x0F, 0x0D
    , 0xF5, 0xEB, 0x70, 0xCD, 0xB0, 0xD0, 0xBA, 0x2A, 0x37, 0xFD, 0x24, 0x5A, 0xF6, 0x69, 0x1A, 0x38
    , 0x22, 0x49, 0xBC, 0xCE, 0x00, 0xCB, 0x6A, 0x2F, 0x6E, 0x98, 0x20, 0xDB, 0xE5, 0x8C, 0x0A, 0x0B
    , 0x5E, 0x99, 0x8D, 0xAB, 0x9B, 0xD3, 0x4B, 0x12, 0xBE, 0x35, 0x75, 0x95, 0xE7, 0xA4, 0xAA, 0xC5
    , 0x79, 0xB7, 0x9A, 0xB8, 0x3B, 0x86, 0x29, 0x15, 0xE5, 0x40, 0xE4, 0xC2, 0x85, 0xC2, 0x1B, 0xB5
    , 0x06, 0xAF, 0x05, 0x49, 0xAD, 0x8B, 0xCE, 0xAD, 0xCD, 0x91, 0xE5, 0xA8, 0x0F, 0x97, 0x7F, 0x1C
    , 0x42, 0x73, 0xAB, 0x1E, 0x5A, 0xEC, 0xA1, 0x31, 0x06, 0x6C, 0x80, 0x06, 0xE8, 0x03, 0x73, 0x4B
    , 0x45, 0x48, 0x46, 0x09, 0xE0, 0x7D, 0x6F, 0xD9, 0xCD, 0x66, 0xF6, 0x0F, 0xEC, 0x01, 0xE7, 0x84
    , 0xD9, 0xF0, 0x86, 0xF0, 0x5A, 0xE9, 0x10, 0xE4, 0xDC, 0x49, 0x03, 0xF4, 0x6C, 0x3B, 0xE4, 0xC3
    , 0x3B, 0xAE, 0x39, 0x77, 0xB1, 0x3E, 0x9F, 0x03, 0x4A, 0x09, 0xDA, 0xD8, 0xE0, 0x60, 0x2D, 0x3C
    , 0x77, 0x98, 0xC6, 0x36, 0xFB, 0x63, 0xD6, 0x4B, 0x99, 0xDB, 0x1F, 0x5B, 0xD2, 0x75, 0x21, 0xA2
    , 0x8E, 0xDD, 0x8F, 0x25, 0x38, 0x1E, 0xDE, 0xBA, 0x89, 0xB9, 0x58, 0x77, 0x7F, 0x6E, 0x7C, 0xA4
    , 0xD9, 0xA1, 0x4E, 0xF2, 0x9F, 0x77, 0x84, 0x09, 0x19, 0xEE, 0xBA, 0xB1, 0x73, 0x66, 0x35, 0xBD
    , 0x4B, 0x2A, 0x0F, 0x21, 0x08, 0x5B, 0xF2, 0xBA, 0x7C, 0xC3, 0xE6, 0xAF, 0xF0, 0x44, 0xDF, 0x10
    , 0x0D, 0x60, 0x16, 0x2F, 0xE6, 0x8D, 0x9D, 0x15, 0xB6, 0x05, 0x6C, 0x63, 0x6B, 0xBE, 0x9D, 0x5E
    , 0x7F, 0xBC, 0xFF, 0x38, 0xE4, 0x9E, 0xBA, 0x7A, 0xDB, 0x36, 0x87, 0x0C, 0x7D, 0x69, 0x45, 0xD6
    , 0xFA, 0x1B, 0xA0, 0x8D, 0xFD, 0xC4, 0xC8, 0xD6, 0x01, 0xE6, 0xB3, 0x87, 0xAC, 0xD3, 0xE5, 0xDC
    , 0x88, 0x43, 0x81, 0x89, 0x04, 0x2B, 0x43, 0x54, 0x77, 0x5D, 0x7E, 0x27, 0xF2, 0x3E, 0x02, 0xA4
    , 0xAC, 0x9B, 0x0F, 0xCB, 0x54, 0xD7, 0xA9, 0xE4, 0x2E, 0x08, 0x9A, 0x69, 0x28, 0x89, 0x4B, 0xF4
    , 0x19, 0x97, 0x5A, 0xB3, 0x56, 0xCD, 0xB7, 0x2C, 0x4A, 0xD5, 0xA1, 0x52, 0xF3, 0x7A, 0xB0, 0x71
    , 0x3A, 0xA2, 0x09, 0x01, 0x80, 0x54, 0x58, 0x61, 0x4C, 0xE5, 0x0F, 0x08, 0x1E, 0x47, 0xB6, 0x43
    , 0xC0, 0x88, 0x4A, 0xBD, 0xAB, 0x65, 0xCB, 0x32, 0x5C, 0xAA, 0x69, 0x9A, 0x42, 0x8E, 0x46, 0xB9
    , 0x64, 0x5C, 0x9A, 0x1F, 0xF8, 0xD6, 0x47, 0xC5, 0x49, 0x17, 0x17, 0x95, 0xAE, 0x8F, 0x9C, 0xC3
    , 0xC6, 0x9F, 0xAE, 0x3F, 0x72, 0x13, 0x72, 0xED, 0xD9, 0x35, 0x20, 0x6E, 0xAA, 0x8E, 0xAA, 0x58
    , 0x0A, 0xB2, 0x5C, 0x97, 0xA5, 0x44, 0xF9, 0x73, 0x43, 0x59, 0x8E, 0xD6, 0x05, 0x8A, 0x13, 0x79
    , 0xBC, 0xAA, 0x37, 0x60, 0x7B, 0xFA, 0xA1, 0x36, 0x14, 0x5D, 0xC9, 0xB3, 0x88, 0x92, 0x80, 0x59
    , 0xD7, 0x19, 0x6C, 0xC4, 0x4B, 0x4F, 0xC2, 0x6E, 0x1D, 0x8D, 0x8B, 0x04, 0x28, 0x28, 0x85, 0x15
    , 0x86, 0xEB, 0xD5, 0x3E, 0x39, 0x48, 0xDE, 0xF7, 0x1D, 0x59, 0xF9, 0x06, 0x77, 0xFD, 0x57, 0x5D
    , 0x66, 0x26, 0x10, 0x6D, 0x6B, 0xF7, 0xD5, 0x47, 0xBD, 0xCA, 0xF4, 0x3E, 0xBF, 0x01, 0x49, 0xBC
    , 0xE7, 0xF1, 0x24, 0xAE, 0x00, 0x55, 0x9B, 0xF1, 0x49, 0xAB, 0x4C, 0x50, 0x25, 0x11, 0x0E, 0x56
    , 0x51, 0x22, 0xD4, 0x52, 0xE2, 0x9E, 0x7F, 0x08, 0xB0, 0xD0, 0x33, 0xC1, 0x22, 0xD1, 0x54, 0xCA
    , 0x90, 0x7A, 0x22, 0x66, 0x8C, 0x28, 0xAF, 0x2D, 0x47, 0x7B, 0x8A, 0x11, 0xC5, 0x5D, 0x96, 0x66
    , 0x3A, 0x7B, 0x4B, 0x67, 0xA8, 0x30, 0x09, 0x5A, 0x06, 0xE0, 0xA8, 0xB3, 0xDB, 0x02, 0x21, 0x46
    , 0xCF, 0x60, 0x27, 0x19, 0x76, 0x58, 0x35, 0xBB, 0x8E, 0x0C, 0x09, 0x63, 0xD4, 0x40, 0x49, 0xF9
    , 0xC6, 0xA0, 0xA1, 0xFF, 0xAE, 0x36, 0xC8, 0x71, 0x7E, 0x82, 0xF9, 0xDC, 0x52, 0x10, 0x26, 0xF3
    , 0xF7, 0x1C, 0x66, 0xAC, 0x21, 0x2C, 0x5F, 0x9E, 0x69, 0xAF, 0xEA, 0x90, 0x34, 0x44, 0x01, 0x42
    , 0xBB, 0x7B, 0x57, 0x53, 0x2D, 0x26, 0x58, 0x60, 0x0A, 0x9E, 0xF5, 0x30, 0xF9, 0x8D, 0x08, 0x86
    , 0x32, 0x43, 0x4D, 0x85, 0xE0, 0x07, 0x54, 0x78, 0x49, 0x00, 0x40, 0x2B, 0x60, 0x18, 0x3A, 0x2A
    , 0xD6, 0xBE, 0x1B, 0x9E, 0x8F, 0x01, 0x92, 0x43, 0x1A, 0x1D, 0xDB, 0xB0, 0x06, 0xC4, 0x8A, 0x06
    , 0x49, 0x10, 0x9F, 0x85, 0x42, 0x12, 0x41, 0xE8, 0xDA, 0xF5, 0x73, 0x47, 0x58, 0xCF, 0x6D, 0x14
    , 0x0C, 0x1E, 0x9A, 0x20, 0x8B, 0x81, 0x36, 0xFD, 0x0D, 0xAC, 0x6A, 0x00, 0xAD, 0x52, 0xB7, 0x7A
    , 0x91, 0x64, 0x78, 0xD7, 0xDB, 0x7F, 0x9B, 0x31, 0xE1, 0xCB, 0x22, 0xD1, 0xD3, 0x41, 0xF5, 0xCE
    , 0x06, 0xCD, 0x13, 0x1E, 0x52, 0x39, 0x3B, 0xFD, 0x9F, 0x16, 0x1F, 0x7D, 0x60, 0x21, 0x28, 0x29
    , 0x10, 0x62, 0xB0, 0xE5, 0x9F, 0x43, 0x76, 0x92, 0x38, 0x5C, 0xE9, 0x31, 0x62, 0xD2, 0x24, 0x52
    , 0x70, 0xD4, 0xBA, 0x05, 0x6F, 0x17, 0x7A, 0x43, 0x09, 0xD9, 0x57, 0x67, 0x3C, 0x8F, 0x88, 0xE8
    , 0x22, 0x23, 0xAD, 0x68, 0x61, 0xCC, 0x8C, 0xF3, 0x94, 0x6F, 0x1C, 0x40, 0x38, 0xA9, 0x5A, 0xA5
    , 0xD5, 0x79, 0x2C, 0xDB, 0x21, 0x32, 0x5F, 0x11, 0xC4, 0x8F, 0xC2, 0x70, 0x41, 0x93, 0xF4, 0x91
    , 0xF8, 0xF5, 0xC5, 0x92, 0x05, 0xAA, 0xF7, 0x82, 0xB9, 0xD9, 0x7C, 0x5F, 0xE9, 0x62, 0xAB, 0x52
    , 0xDD, 0x98, 0xF1, 0xAE, 0x0B, 0x1C, 0x8F, 0x81, 0x22, 0xDF, 0x69, 0xBA, 0xFA, 0x51, 0xB5, 0xFC
    , 0x46, 0x1C, 0xCC, 0xA2, 0xDD, 0xD9, 0x12, 0xC5, 0xCC, 0xB6, 0xC7, 0x03, 0x57, 0x57, 0xEE, 0x5D
    , 0x66, 0x4A, 0xB6, 0x7B, 0x07, 0x9E, 0x2A, 0x1F, 0x06, 0x00, 0x9E, 0xC5, 0x9C, 0xC2, 0x70, 0x24
    , 0xE0, 0x8C, 0xF7, 0x13, 0x69, 0x93, 0x91, 0x39, 0x69, 0xFC, 0x47, 0xD6, 0xA0, 0xCE, 0xAA, 0xA6
    , 0xC9, 0x04, 0xDF, 0xA9, 0x60, 0x5A, 0x96, 0xA1, 0x2C, 0xC6, 0x2A, 0xA7, 0xE5, 0x65, 0x4D, 0xA9
    , 0x76, 0x0C, 0x6B, 0xBB, 0xAE, 0xB9, 0x58, 0x4F, 0x48, 0xE6, 0xD5, 0xDB, 0x04, 0x02, 0x2C, 0x50
    , 0xF6, 0xE3, 0x95, 0xCC, 0xDB, 0x4D, 0x67, 0xCB, 0xED, 0x1D, 0xEC, 0x81, 0x68, 0x69, 0x2E, 0xCD
    , 0x9A, 0x1F, 0xF6, 0x72, 0x53, 0x86, 0xBE, 0x73, 0x5F, 0xBE, 0x0E, 0x8E, 0x51, 0x06, 0xD4, 0xA5
    , 0x27, 0x3E, 0xEE, 0x6B, 0x3B, 0x07, 0xE6, 0xF2, 0x29, 0xA2, 0x83, 0x28, 0xA9, 0x81, 0x0C, 0xE5
    , 0x5F, 0xB6, 0x18, 0x35, 0x70, 0x45, 0x82, 0xC2, 0xEC, 0x65, 0x88, 0xD7, 0x05, 0xEE, 0x30, 0xA8
    , 0x3D, 0x3D, 0xAB, 0x3E, 0x7A, 0x3A, 0x1B, 0x5A, 0xC4, 0xD1, 0xF8, 0x3B, 0xB8, 0x8F, 0xB2, 0x20
    , 0xF9, 0xB4, 0x0F, 0xED, 0xB4, 0x83, 0x62, 0x85, 0x33, 0xBF, 0xE6, 0x21, 0xE3, 0x32, 0x1B, 0x24
    , 0xD8, 0x48, 0x62, 0x1B, 0x9C, 0xDD, 0x77, 0xFC, 0x6B, 0x4C, 0x76, 0x2A, 0x74, 0xB8, 0x9C, 0x57
    , 0x72, 0x64, 0x47, 0xF5, 0x14, 0x45, 0xC1, 0x62, 0xD5, 0x21, 0xC4, 0x91, 0x85, 0xCC, 0x61, 0xE4
    , 0x69, 0x92, 0x7D, 0x20, 0x9A, 0x60, 0x76, 0xEC, 0x07, 0x58, 0xD6, 0xB9, 0x0A, 0xCF, 0x64, 0x33
    , 0x28, 0x99, 0x93, 0xDE, 0x5A, 0x94, 0x6B, 0x25, 0x82, 0x77, 0x04, 0x4F, 0xFD, 0x02, 0x87, 0xD1
    , 0x41, 0x60, 0x3B, 0xDA, 0xF6, 0x30, 0x65, 0xE9, 0x53, 0xA8, 0xB8, 0xBB, 0xBE, 0x54, 0x97, 0x74
    , 0x15, 0x3D, 0xAD, 0x21, 0x01, 0xA0, 0xC5, 0x1C, 0x05, 0x6B, 0x55, 0x35, 0x81, 0x25, 0xFA, 0x81
    , 0x64, 0x94, 0xBD, 0xA5, 0xE9, 0x0F, 0xFC, 0xF2, 0x40, 0xA9, 0x20, 0xE1, 0x2C, 0xCC, 0x7A, 0xC7
    , 0xA4, 0x18, 0x6E, 0xCD, 0xDE, 0xFD, 0x17, 0xEE, 0xF9, 0x39, 0x10, 0x04, 0x9D, 0xDF, 0xBB, 0x72
    , 0x37, 0x5D, 0xBC, 0xF8, 0xE3, 0x59, 0x73, 0x40, 0x00, 0xC2, 0x28, 0x96, 0x41, 0x10, 0x34, 0x4D
    , 0x9C, 0x2C, 0x75, 0x5A, 0xF8, 0x24, 0x8E, 0x75, 0x0B, 0xD3, 0x72, 0x88, 0x91, 0x70, 0x7A, 0xCA
    , 0x74, 0x0F, 0x7F, 0xAD, 0x38, 0xE7, 0x27, 0xB9, 0x42, 0xA3, 0xA4, 0xDA, 0x7A, 0xFA, 0xE9, 0x15
    , 0xC6, 0xA2, 0x6E, 0xFE, 0x8F, 0xD6, 0x99, 0xBC, 0x29, 0x77, 0xC5, 0x16, 0x25, 0x00, 0x2A, 0x94
    , 0xB1, 0x6C, 0x3B, 0x59, 0xEC, 0xE9, 0x14, 0x0D, 0xD3, 0xFA, 0x50, 0xF8, 0x7C, 0x2C, 0x43, 0xA1
    , 0x9D, 0x16, 0xCF, 0x00, 0x7E, 0xD4, 0x6E, 0xB4, 0x8E, 0xEA, 0x88, 0x37, 0x13, 0xC5, 0x84, 0xD9
    , 0x5D, 0x77, 0xC8, 0x3C, 0x2B, 0x43, 0x04, 0x83, 0x61, 0xE8, 0x8A, 0x76, 0xAC, 0x68, 0xC4, 0xF8
    , 0x7B, 0xB5, 0xF8, 0x02, 0x2A, 0x8A, 0xD7, 0xD2, 0x60, 0x22, 0x64, 0x5A, 0xDC, 0x0B, 0xA7, 0x49
    , 0x18, 0x8F, 0xF5, 0x7C, 0xF5, 0x82, 0x3B, 0x6C, 0xC7, 0x2D, 0xD1, 0x4D, 0x48, 0x1B, 0x22, 0x88
    , 0x31, 0x8A, 0x42, 0x66, 0x25, 0x67, 0x9A, 0xAF, 0xAE, 0x9C, 0x61, 0x10, 0x29, 0x9B, 0xE6, 0xB9
    , 0xBD, 0xED, 0xD3, 0x80, 0x92, 0x2C, 0xAF, 0x19, 0x59, 0xDF, 0x54, 0x30, 0x87, 0x1A, 0x83, 0x73
    , 0xEF, 0x86, 0x1D, 0xAC, 0xAB, 0x5A, 0x46, 0x66, 0x8B, 0xF9, 0x55, 0x79, 0xA7, 0x1F, 0x9E, 0x03
    , 0x93, 0xF1, 0x55, 0xD0, 0x90, 0x7F, 0x46, 0x2A, 0x26, 0xD7, 0x72, 0xFF, 0x1C, 0x76, 0x45, 0x67
    , 0x96, 0xAB, 0x75, 0xED, 0x83, 0x63, 0x17, 0x27, 0xA3, 0xB4, 0x01, 0x98, 0xE0, 0x70, 0x07, 0x4E
    , 0xC2, 0x16, 0x0B, 0x20, 0x5B, 0xAD, 0x42, 0x31, 0xA2, 0x8A, 0x04, 0x58, 0xD5, 0x75, 0xF2, 0x2C
    , 0x51, 0x87, 0xF3, 0xA3, 0x81, 0xD9, 0x06, 0x91, 0x7E, 0xE5, 0x13, 0x71, 0xAD, 0x61, 0x6D, 0x29
    , 0xCB, 0xA5, 0x8A, 0x64, 0x3E, 0x92, 0xB0, 0x8C, 0x03, 0xCA, 0x2A, 0xDE, 0x36, 0x76, 0x2C, 0xB7
    , 0x44, 0xCB, 0x8B, 0xFF, 0xCF, 0x23, 0xF3, 0xD9, 0x4F, 0xE2, 0x94, 0x2A, 0xE5, 0x69, 0x97, 0xD7
    , 0xF2, 0xAC, 0x2D, 0x3B, 0x4C, 0xD6, 0x97, 0x72, 0xF7, 0x64, 0x13, 0x69, 0x47, 0x98, 0xE1, 0xCF
    , 0x7A, 0xAB, 0xDF, 0x45, 0xBC, 0x0C, 0x1F, 0x56, 0x07, 0xA9, 0xD0, 0x5E, 0xF2, 0xC7, 0xDB, 0x9D
    , 0x96, 0x16, 0x89, 0x24, 0x7D, 0xD1, 0x0A, 0x4F, 0x9D, 0x52, 0xFD, 0x87, 0x2B, 0xD9, 0x19, 0x74
    , 0x05, 0x33, 0x53, 0xCB, 0x6F, 0x89, 0x6D, 0x41, 0x19, 0x4D, 0x24, 0xEF, 0x0A, 0xB4, 0x72, 0x6E
    , 0xE3, 0x66, 0xE2, 0x15, 0x15, 0xDF, 0x02, 0x48, 0xCA, 0x1A, 0x0A, 0xCD, 0x1A, 0xE2, 0x3A, 0x94
    , 0x86, 0x62, 0xBC, 0x15, 0xC1, 0xD5, 0x29, 0xC8, 0x05, 0xA5, 0x81, 0x35, 0xFA, 0x07, 0x10, 0x7B
    , 0x13, 0xBA, 0x88, 0xD0, 0xF6, 0xDD, 0xC9, 0x0F, 0xFC, 0x0D, 0xA8, 0xB4, 0x1F, 0x45, 0x4B, 0x42
    , 0xE8, 0x0D, 0x33, 0x3D, 0x83, 0x7E, 0x1E, 0x80, 0x3D, 0x68, 0xF9, 0xB3, 0x09, 0x08, 0x14, 0x0D
    , 0x49, 0xBA, 0xC3, 0xEF, 0xA5, 0x8A, 0x0B, 0xF2, 0xB7, 0x4F, 0xFD, 0xB6, 0xDB, 0xB6, 0xE7, 0xC6
    , 0xB8, 0xF1, 0x00, 0x83, 0x8A, 0xF5, 0x06, 0xB8, 0x29, 0x51, 0xAF, 0x23, 0x43, 0xA7, 0xD9, 0x71
    , 0x13, 0x94, 0x2D, 0x90, 0xF0, 0xD4, 0xDC, 0x27, 0x89, 0xF6, 0xB0, 0x61, 0x5D, 0x0B, 0x84, 0xF8
    , 0x53, 0x28, 0x67, 0x52, 0x3E, 0x00, 0xBB, 0x8F, 0x03, 0x8D, 0x48, 0x0F, 0xFD, 0x15, 0xEA, 0x70
    , 0x69, 0x8A, 0xA2, 0x6B, 0xC8, 0xA3, 0xD5, 0x3A, 0xF7, 0x78, 0x60, 0x88, 0x96, 0x46, 0x1B, 0xAA
    , 0x83, 0x92, 0x8E, 0xE6, 0xA0, 0x66, 0x83, 0x1B, 0xD5, 0x1C, 0xD4, 0xE9, 0x25, 0xA0, 0xF4, 0xE1
    , 0x5C, 0x22, 0x7E, 0xDF, 0xFC, 0xB0, 0x9A, 0xBC, 0x25, 0x42, 0x31, 0xCE, 0xDC, 0xB7, 0xDD, 0x90
    , 0xFE, 0x30, 0x75, 0x02, 0xBF, 0xA0, 0x24, 0x3F, 0xFB, 0xF0, 0xDA, 0x95, 0x7C, 0xCF, 0x9E, 0x0B
    , 0xEA, 0x56, 0xD3, 0x55, 0xF8, 0x0D, 0x82, 0xCE, 0x73, 0x29, 0x0C, 0x36, 0xBF, 0xD0, 0x72, 0x0B
    , 0x44, 0x00, 0x6C, 0x05, 0xA9, 0x31, 0xE7, 0x0C, 0xF0, 0x2E, 0x8F, 0x93, 0xAB, 0x5B, 0xCE, 0x13
    , 0xAC, 0x4F, 0xBD, 0x14, 0x5D, 0x8B, 0x05, 0x78, 0x7E, 0x22, 0xF5, 0x22, 0xE2, 0xA8, 0x1E, 0x97
    , 0x3D, 0xFB, 0x52, 0xB8, 0x76, 0x78, 0x8D, 0xA1, 0xFB, 0x48, 0x2D, 0xED, 0x5E, 0x08, 0xBA, 0xB7
    , 0x83, 0x94, 0xF6, 0xC4, 0x18, 0x07, 0xD3, 0x57, 0xC8, 0xBB, 0x45, 0x28, 0xDC, 0xB4, 0x2F, 0xF8
    , 0xC8, 0x7D, 0x48, 0xC3, 0xA0, 0x11, 0x60, 0x2F, 0x34, 0x06, 0xB0, 0xFA, 0xBC, 0xCA, 0x2C, 0x71
    , 0x0F, 0x35, 0xF6, 0x73, 0xBF, 0x2D, 0xAF, 0x49, 0xB4, 0x45, 0x9A, 0x64, 0x32, 0xAA, 0x44, 0xA0
    , 0x66, 0x37, 0x52, 0x0A, 0xE0, 0xB2, 0xA4, 0x1D, 0x10, 0x90, 0x08, 0x85, 0x24, 0x79, 0x3B, 0x3A
    , 0xDD, 0x8F, 0x0C, 0x9F, 0x1E, 0xBD, 0x7F, 0xDF, 0x5E, 0xE7, 0x41, 0x73, 0x2D, 0xE5, 0xC7, 0xDC
    , 0xD3, 0xC5, 0x8B, 0x2A, 0x76, 0x2E, 0x8F, 0x42, 0x80, 0x9E, 0xC8, 0xBA, 0x19, 0x5D, 0xC7, 0xD6
    , 0x9E, 0x76, 0x55, 0xA0, 0x4B, 0xE3, 0x37, 0xBF, 0xE7, 0x36, 0xFC, 0xD8, 0xB4, 0xB5, 0x14, 0xA9
    , 0xD5, 0x0D, 0xB2, 0xD6, 0x6A, 0x95, 0xD3, 0xD0, 0x35, 0x8C, 0xCA, 0x70, 0x02, 0xE4, 0x15, 0xD9
    , 0x5C, 0x92, 0xE2, 0x6B, 0xAC, 0xED, 0xD4, 0x9E, 0x1A, 0x32, 0x59, 0x40, 0x09, 0xC4, 0xA5, 0xBF
    , 0x04, 0xD5, 0x53, 0x56, 0x70, 0x7C, 0xAC, 0x13, 0xF4, 0xB6, 0xFB, 0xF8, 0xFE, 0x3F, 0x18, 0x69
    , 0x2C, 0x02, 0x5E, 0xF8, 0x35, 0x94, 0xF7, 0xAE, 0x87, 0x9E, 0xB9, 0xAC, 0xE4, 0xF2, 0xFA, 0xEE
    , 0x3E, 0x23, 0x73, 0xE1, 0x55, 0x1E, 0xBA, 0x98, 0xE9, 0xB2, 0x7D, 0x75, 0x92, 0x24, 0xAD, 0xB2
    , 0xEB, 0x2D, 0x68, 0xDB, 0x0D, 0x5F, 0xE0, 0x3F, 0x71, 0x42, 0xFB, 0x0D, 0xD7, 0xA6, 0x2C, 0x47
    , 0xAA, 0x5F, 0xE0, 0x32, 0x89, 0x7C, 0x59, 0xEC, 0x27, 0x45, 0xF6, 0x94, 0x84, 0x85, 0xDF, 0xE3
    , 0x86, 0xDA, 0x08, 0x3C, 0xB9, 0x57, 0xEB, 0x62, 0x5F, 0x23, 0xC7, 0x85, 0x85, 0x5C, 0x0B, 0x34
    , 0x60, 0x2A, 0x9B, 0x01, 0x6C, 0xD6, 0xFD, 0x61, 0x81, 0xD7, 0xB8, 0xCC, 0x61, 0xFB, 0x38, 0x9E
    , 0xFD, 0x51, 0xA1, 0x80, 0xB8, 0xA0, 0x27, 0x9D, 0x92, 0xC2, 0xCC, 0xFC, 0x76, 0x1C, 0xF3, 0x7F
    , 0x5A, 0xEF, 0xFA, 0x26, 0x90, 0x2A, 0xB2, 0x92, 0x48, 0xB1, 0xE5, 0x3A, 0x68, 0xF9, 0x26, 0x72
    , 0x38, 0x2D, 0xA4, 0x23, 0xAE, 0xF7, 0x3B, 0xCC, 0x8C, 0xD3, 0xB0, 0x2E, 0xFF, 0x2C, 0xE0, 0xA1
    , 0xF5, 0xD1, 0x37, 0x98, 0x63, 0x83, 0xF2, 0x63, 0xBA, 0x3A, 0xF8, 0x98, 0xEF, 0xF7, 0x56, 0x04
    , 0x42, 0xB9, 0x3F, 0x06, 0xF9, 0xB7, 0x42, 0xA9, 0xB6, 0xFC, 0x1A, 0x01, 0x13, 0x12, 0x42, 0x60
    , 0xF1, 0xE1, 0xBB, 0xBF, 0x2A, 0x29, 0x6D, 0xFA, 0x2B, 0x58, 0x7E, 0xA6, 0x36, 0x8F, 0x8E, 0xD0
    , 0x7F, 0x56, 0xEE, 0xDF, 0x49, 0x3E, 0xD6, 0xA2, 0xF3, 0x54, 0x68, 0x7E, 0xB7, 0xD6, 0xDE, 0x90
    , 0xA8, 0xD9, 0xB6, 0x76, 0xF9, 0x77, 0x05, 0x73, 0x80, 0x4B, 0xD0, 0xB4, 0x64, 0xE7, 0xE4, 0x6C
    , 0x13, 0x4E, 0x21, 0x2D, 0x71, 0x5A, 0x8C, 0xDE, 0xC6, 0x3F, 0xD6, 0xDC, 0xB5, 0x41, 0x96, 0x92
    , 0x0D, 0x99, 0x5C, 0x09, 0x92, 0x73, 0x90, 0x9F, 0xC3, 0x13, 0xD9, 0x74, 0x94, 0xF9, 0xB5, 0x92
    , 0xFA, 0x1C, 0x8D, 0x4A, 0x69, 0x23, 0xA7, 0x16, 0x64, 0xA8, 0x11, 0x7E, 0x8B, 0x88, 0xD8, 0xD5
    , 0xE3, 0x21, 0xDB, 0xCB, 0xE8, 0x23, 0x1A, 0xB7, 0x4C, 0x35, 0x60, 0xAF, 0xBF, 0x08, 0x82, 0x72
    , 0x46, 0x95, 0xA7, 0x98, 0x5A, 0x3E, 0xC5, 0x69, 0x28, 0x1A, 0xD0, 0xA8, 0x77, 0x9C, 0x77, 0xC5
    , 0xDF, 0x17, 0x76, 0x13, 0x67, 0x69, 0x9E, 0x88, 0x95, 0x28, 0x74, 0xCC, 0xEE, 0x79, 0xAF, 0x70
    , 0x99, 0x01, 0xDC, 0xCF, 0xDB, 0xF2, 0x8B, 0xF0, 0x9F, 0x02, 0xE0, 0x3D, 0xCC, 0x19, 0x9B, 0x2A
    , 0x20, 0x01, 0x4A, 0xAC, 0x0F, 0x77, 0xB8, 0x23, 0x00, 0x0E, 0x65, 0xCF, 0xA5, 0xCF, 0x8B, 0x27
    , 0xDD, 0x18, 0x0A, 0x41, 0x78, 0xDE, 0x9D, 0x75, 0x21, 0xE9, 0xCF, 0x37, 0xC7, 0x53, 0x97, 0x3C
    , 0x89, 0x09, 0x47, 0x21, 0xF1, 0x50, 0xB4, 0x2D, 0x83, 0xE7, 0xE2, 0xBB, 0x36, 0x0B, 0x2B, 0xAE
    , 0x8C, 0xC0, 0xF9, 0x7A, 0x7D, 0x83, 0x7C, 0x9C, 0x1A, 0xB5, 0x23, 0xED, 0xC0, 0x1A, 0x51, 0x16
    , 0xDD, 0xB3, 0xB2, 0x42, 0x11, 0x87, 0x2E, 0x2D, 0x66, 0x57, 0x6A, 0x3B, 0x96, 0x2D, 0x1C, 0x7E
    , 0x0A, 0x73, 0x93, 0xCE, 0x9D, 0xD5, 0xB5, 0xEC, 0xC0, 0x29, 0x95, 0xD5, 0xF3, 0x36, 0x5B, 0x3A
    , 0xA3, 0xF2, 0x3F, 0xF4, 0x22, 0x25, 0x81, 0xD5, 0x15, 0xBD, 0x04, 0xF5, 0x3B, 0x44, 0x2B, 0xFE
    , 0x53, 0x84, 0xC6, 0xE3, 0xA1, 0x82, 0xFC, 0xC8, 0x61, 0x8C, 0x5F, 0xCC, 0x36, 0xDB, 0x90, 0x5A
    , 0x50, 0x8A, 0x03, 0xAB, 0xBB, 0xFF, 0x27, 0x5E, 0xE9, 0x54, 0x12, 0x6F, 0x96, 0x72, 0xF8, 0xCE
    , 0x21, 0xC5, 0xE6, 0x58, 0xA5, 0x23, 0xF8, 0x0D, 0x5E, 0x85, 0xC0, 0x6F, 0x61, 0x88, 0x3D, 0x23
    , 0x0D, 0xAE, 0xAE, 0xCB, 0x41, 0x8F, 0x8F, 0xA1, 0xFC, 0xE6, 0x38, 0x70, 0xE6, 0xF7, 0x6E, 0x9E
    , 0x50, 0x8A, 0x03, 0xAB, 0xBB, 0xFF, 0x27, 0x5E, 0xE9, 0x54, 0x12, 0x6F, 0x96, 0x72, 0xF8, 0xCE
    , 0xF5, 0xD1, 0x91, 0xDF, 0x5A, 0x77, 0x10, 0xC1, 0x8C, 0xC7, 0xCB, 0x16, 0x95, 0x85, 0x26, 0x98
    , 0x8C, 0x79, 0xD9, 0x1D, 0xB8, 0x29, 0xD4, 0xC9, 0x9C, 0x86, 0x9D, 0x5C, 0xE7, 0x72, 0x1D, 0xA0
    , 0x9D, 0xC8, 0x25, 0x48, 0x2A, 0x19, 0x6B, 0xCD, 0xC6, 0x6A, 0xE3, 0xD4, 0x9B, 0xB3, 0x99, 0x9A
    , 0x5E, 0xE9, 0x8E, 0x6B, 0xDD, 0x9B, 0xF1, 0x92, 0xDF, 0x39, 0x74, 0x4F, 0xDF, 0xFA, 0xA8, 0x98
    , 0xBD, 0xA6, 0x1A, 0x4C, 0x44, 0x71, 0x39, 0x26, 0x40, 0xE0, 0xCD, 0xAA, 0xD1, 0x93, 0x36, 0x11
    , 0xE8, 0xD8, 0x39, 0x7D, 0xF5, 0x96, 0xB6, 0x31, 0x8F, 0x0D, 0x2C, 0xD4, 0x35, 0xDA, 0x23, 0xE6
    , 0x7A, 0x92, 0x00, 0x4B, 0xB5, 0x36, 0x1B, 0xA2, 0x4F, 0xFB, 0x41, 0xD4, 0x5E, 0x94, 0x93, 0x2F
    , 0x6A, 0xE5, 0x36, 0xC8, 0xB0, 0x6C, 0x3E, 0xEC, 0x10, 0xA1, 0xD9, 0x0A, 0xD0, 0x1D, 0xD7, 0xAA
    , 0x31, 0xE5, 0x00, 0xBD, 0x74, 0xBB, 0x12, 0x2D, 0x74, 0xA6, 0xAC, 0xC1, 0x2C, 0xCC, 0x7C, 0xF2
    , 0x88, 0xAA, 0x4D, 0x3F, 0x0A, 0x22, 0xBA, 0x2E, 0x2B, 0x3B, 0x74, 0xBF, 0x53, 0xEF, 0xAE, 0x20
    , 0xDD, 0x09, 0x5A, 0xB5, 0xDA, 0xB2, 0x1B, 0x04, 0x29, 0x5D, 0x75, 0xF4, 0x4A, 0x89, 0x70, 0xC2
    , 0xB8, 0xF6, 0x64, 0x7A, 0x8A, 0x51, 0x5F, 0x05, 0x85, 0x52, 0x57, 0x0D, 0x7D, 0x9A, 0x0F, 0x3A
    , 0x20, 0xD1, 0x83, 0x54, 0x38, 0x5B, 0xB5, 0x2B, 0x3B, 0x71, 0x24, 0xCE, 0x08, 0x9B, 0x4F, 0x38
    , 0xCF, 0x92, 0x42, 0x66, 0x0C, 0x1C, 0x02, 0x29, 0x4C, 0x03, 0xF3, 0x87, 0x77, 0xB0, 0x88, 0xF7
    , 0x2C, 0x51, 0x36, 0x3C, 0x1C, 0x2D, 0xE5, 0x6C, 0x90, 0x24, 0x2E, 0x69, 0x90, 0x6F, 0x96, 0x81
    , 0x5B, 0x0D, 0x91, 0xBF, 0xC0, 0xFC, 0x2B, 0xBD, 0xF3, 0x77, 0x87, 0x45, 0x20, 0xB2, 0xEB, 0x56
    , 0x87, 0x64, 0x6B, 0xA3, 0xDA, 0x7F, 0x6F, 0x2B, 0x8F, 0x72, 0xE5, 0xA2, 0xB5, 0x1B, 0xC8, 0x06
    , 0xE1, 0xD9, 0x6C, 0xB3, 0x83, 0x2E, 0xB6, 0x25, 0xD7, 0x42, 0x7C, 0x57, 0x84, 0xA6, 0xDE, 0x3E
    , 0xE5, 0x97, 0xCF, 0xA3, 0x60, 0x66, 0x3A, 0xB7, 0xD9, 0x0E, 0xCC, 0xB0, 0xBF, 0x56, 0x81, 0x4A
    , 0xA4, 0x87, 0x50, 0x63, 0x1B, 0x94, 0xBE, 0x59, 0x86, 0x76, 0x20, 0xE5, 0xE4, 0x72, 0xF8, 0xCA
    , 0xEC, 0xBD, 0x5F, 0x18, 0x4D, 0x9E, 0x25, 0xBB, 0xF0, 0xC9, 0xAA, 0x1A, 0xAF, 0xAF, 0x17, 0xAA
    , 0x45, 0x46, 0x2F, 0xD6, 0xF2, 0xB8, 0xF5, 0x83, 0x17, 0xC6, 0xAC, 0xC6, 0x6B, 0x48, 0x49, 0xBA
    , 0x2A, 0xB5, 0xDE, 0x4F, 0x07, 0x41, 0xD3, 0xE7, 0x03, 0x79, 0xA0, 0xCF, 0x4C, 0x6C, 0xB7, 0x4F
    , 0x41, 0xDF, 0xEC, 0x14, 0xD0, 0x97, 0xF8, 0x93, 0x55, 0xA6, 0x2C, 0x13, 0x70, 0x5C, 0xE1, 0xDC
    , 0x78, 0x39, 0x3C, 0x68, 0x53, 0xE6, 0x67, 0x5A, 0x57, 0xC6, 0xDE, 0x3F, 0x2D, 0x73, 0x25, 0x58
    , 0xA8, 0x0B, 0xCA, 0xA0, 0xC9, 0xCF, 0xA2, 0x96, 0x02, 0xE4, 0x15, 0x66, 0xD1, 0x6A, 0x7C, 0x52
    , 0xA9, 0x60, 0xAE, 0xBF, 0x06, 0xB3, 0x3E, 0xB2, 0x3E, 0x07, 0x33, 0xCC, 0xD5, 0xB3, 0xDA, 0xF1
    , 0xB9, 0x1A, 0xD0, 0xB3, 0x1C, 0x3C, 0x28, 0xE2, 0x9B, 0x99, 0x83, 0xFF, 0xF2, 0xC3, 0xBC, 0xD1
    , 0xB8, 0x44, 0x8E, 0xA7, 0xDC, 0x8E, 0x9D, 0x64, 0x1B, 0x15, 0x00, 0x01, 0xC2, 0x0B, 0x7A, 0x72
    , 0x6F, 0xC5, 0xC7, 0xD1, 0x37, 0x3C, 0x23, 0x6E, 0x1F, 0x0D, 0xF2, 0xAF, 0x63, 0xBA, 0x6D, 0x3A
    , 0x53, 0x29, 0x35, 0x3D, 0x9F, 0x76, 0x02, 0x20, 0x45, 0x73, 0x4C, 0xAA, 0x7E, 0x06, 0xD5, 0xE6
    , 0xFC, 0x35, 0xFB, 0xC4, 0x2D, 0xEE, 0xDC, 0xD2, 0xE9, 0xAB, 0x8B, 0x73, 0x9C, 0xE1, 0xB0, 0x6D
    , 0xD5, 0x59, 0xF2, 0xEE, 0x70, 0x3C, 0x4B, 0x93, 0x76, 0x4B, 0x64, 0x4E, 0xAA, 0x9E, 0xE4, 0x5C
    , 0x87, 0xAC, 0x88, 0x68, 0x2A, 0x96, 0x8A, 0x18, 0xB2, 0x57, 0x31, 0x30, 0x87, 0x2F, 0x91, 0x29
    , 0xDF, 0xA8, 0x41, 0x94, 0x3B, 0x22, 0xE8, 0x90, 0xAC, 0xC4, 0x58, 0x59, 0x9A, 0x0B, 0x51, 0x8D
    , 0x14, 0xBE, 0xC4, 0x88, 0xD2, 0xA0, 0x6E, 0x5E, 0xDA, 0x74, 0xD7, 0x9D, 0xE5, 0xD9, 0x3B, 0x83
    , 0x2E, 0x06, 0xB7, 0xB7, 0x98, 0x59, 0x28, 0x94, 0x1D, 0x75, 0x2A, 0x9A, 0x07, 0x07, 0xFD, 0xC1
    , 0x2D, 0xB5, 0x29, 0x85, 0x87, 0x45, 0x06, 0xCF, 0xEE, 0x5C, 0x17, 0x65, 0x54, 0x21, 0xCE, 0x87
    , 0x1A, 0xBF, 0x70, 0x2C, 0xFB, 0xC8, 0x9F, 0x44, 0xF3, 0xA2, 0x1D, 0xF2, 0x74, 0x85, 0x2E, 0x23
    , 0xB8, 0x44, 0x8E, 0xA7, 0xDC, 0x8E, 0x9D, 0x64, 0x1B, 0x15, 0x00, 0x01, 0xC2, 0x0B, 0x7A, 0x72
    , 0x20, 0xA3, 0x54, 0x5C, 0x23, 0x4D, 0xA3, 0x22, 0x82, 0x83, 0xFA, 0x09, 0xE2, 0xFD, 0x54, 0xE1
    , 0x56, 0x74, 0xD6, 0x36, 0x45, 0xDB, 0x33, 0x2B, 0xFF, 0x5C, 0xBE, 0x4A, 0x44, 0x96, 0x9E, 0x4E
    , 0x05, 0x8B, 0xAC, 0x07, 0x29, 0xFC, 0xBB, 0x48, 0x03, 0x2C, 0xC9, 0x95, 0x9C, 0x18, 0x10, 0x02
    , 0x66, 0xC8, 0x8B, 0x2F, 0xA1, 0xCA, 0xB2, 0xAA, 0x3F, 0x89, 0x3A, 0xE5, 0x79, 0x7E, 0x94, 0x22
    , 0x1E, 0xBF, 0x51, 0xBF, 0x84, 0x5D, 0x44, 0xB8, 0xFC, 0xB1, 0x8F, 0xC8, 0x2B, 0x42, 0x8F, 0xCF
    , 0xFC, 0x35, 0xFB, 0xC4, 0x2D, 0xEE, 0xDC, 0xD2, 0xE9, 0xAB, 0x8B, 0x73, 0x9C, 0xE1, 0xB0, 0x6D
    , 0xD9, 0x33, 0xA4, 0x6D, 0xC6, 0xF5, 0xB3, 0xA5, 0xE2, 0xD3, 0x52, 0xB6, 0x80, 0x83, 0xBF, 0xA7
    , 0x87, 0x6A, 0xAB, 0xF9, 0xF8, 0x19, 0xB5, 0x54, 0x7B, 0xA5, 0x37, 0x80, 0xF5, 0x2C, 0x78, 0xF2
    , 0xEA, 0x7E, 0x85, 0x88, 0x6B, 0x2C, 0x5D, 0x9F, 0xBC, 0x8E, 0xE2, 0x4B, 0x2D, 0x78, 0xC9, 0x60
    , 0xA2, 0x84, 0x3B, 0x38, 0x8B, 0xEF, 0x34, 0x34, 0xBC, 0x62, 0x80, 0x38, 0x0B, 0xA6, 0x8C, 0x26
    , 0x87, 0xAC, 0x88, 0x68, 0x2A, 0x96, 0x8A, 0x18, 0xB2, 0x57, 0x31, 0x30, 0x87, 0x2F, 0x91, 0x29
    , 0xDF, 0xA8, 0x41, 0x94, 0x3B, 0x22, 0xE8, 0x90, 0xAC, 0xC4, 0x58, 0x59, 0x9A, 0x0B, 0x51, 0x8D
    , 0x2E, 0x4F, 0x10, 0x15, 0x2C, 0xF3, 0xE7, 0x07, 0xF5, 0xA7, 0x21, 0xC5, 0xFC, 0x7D, 0x20, 0x76
    , 0x73, 0x97, 0xB8, 0x79, 0x93, 0xA8, 0x89, 0xF0, 0xAD, 0x2B, 0x97, 0xD2, 0x2A, 0xA4, 0x2A, 0xCE
    , 0xCE, 0xB8, 0x2C, 0x87, 0x3C, 0x37, 0x6A, 0xDB, 0xB0, 0x38, 0x2D, 0x67, 0xC2, 0x3C, 0x42, 0x7F
    , 0xA3, 0x30, 0x9C, 0x98, 0x0D, 0xD8, 0x79, 0xF7, 0x34, 0x53, 0x9D, 0x97, 0xE3, 0x87, 0x62, 0x12
    , 0xF5, 0x4E, 0xC4, 0xDF, 0xA5, 0x64, 0xFB, 0xC2, 0xDA, 0xAE, 0xEA, 0x26, 0x44, 0xC4, 0xCE, 0x39
    , 0x36, 0x6C, 0x44, 0xD6, 0xE5, 0x73, 0x9D, 0x34, 0x48, 0xEB, 0x76, 0x0A, 0x19, 0x84, 0xD2, 0xD7
    , 0x33, 0xC1, 0x17, 0x3E, 0xC7, 0xCB, 0xDF, 0x55, 0xEC, 0x41, 0x2E, 0x92, 0xC2, 0xE9, 0x20, 0xD8
    , 0x63, 0xED, 0x96, 0xD8, 0x43, 0x7A, 0x9A, 0xE3, 0xFC, 0x4E, 0xD3, 0x5F, 0xD7, 0xBF, 0x46, 0x59
    , 0x1F, 0x9E, 0xEB, 0xF7, 0x49, 0x9F, 0x50, 0x8B, 0xF1, 0x4E, 0x83, 0x30, 0x0F, 0x3D, 0x63, 0x5B
    , 0x74, 0x8E, 0xCE, 0x94, 0xFB, 0x06, 0x54, 0x1B, 0x0B, 0x68, 0x7D, 0x13, 0xC8, 0x74, 0x89, 0xF7
    , 0x68, 0xB8, 0x39, 0x73, 0x7F, 0xC1, 0x78, 0xA0, 0xB5, 0xC8, 0x4D, 0x65, 0xE1, 0x87, 0x3D, 0xF4
    , 0x53, 0x3E, 0xA2, 0x35, 0xC7, 0x55, 0x99, 0x5A, 0xAB, 0xA2, 0x5E, 0xA8, 0x13, 0xE2, 0x9F, 0x12
    , 0x4F, 0x76, 0xCE, 0xF4, 0x85, 0x10, 0xC7, 0xB8, 0xEB, 0xF9, 0xDD, 0x66, 0x31, 0x33, 0x38, 0x1C
    , 0xE6, 0x87, 0x00, 0x44, 0x7E, 0x22, 0xF1, 0x8F, 0xF8, 0x8C, 0x73, 0xAF, 0x0C, 0x14, 0x3C, 0x54
    , 0xB2, 0x97, 0x10, 0xEA, 0xBC, 0xD0, 0x7B, 0x1C, 0x33, 0x6B, 0x64, 0x56, 0x1C, 0xE5, 0x6D, 0xBE
    , 0x3D, 0xA8, 0x8E, 0xA3, 0xCB, 0x20, 0xF0, 0xDA, 0xFB, 0xEE, 0xB8, 0x28, 0xDF, 0xB8, 0x35, 0xB7
    , 0x62, 0x4F, 0xF1, 0xFE, 0xB6, 0xE2, 0x4D, 0xFD, 0x43, 0x32, 0xCC, 0x11, 0x8B, 0x9A, 0x21, 0x2C
    , 0x8D, 0xBC, 0x6D, 0x91, 0xDB, 0x1B, 0x2E, 0x03, 0x41, 0xE6, 0xBA, 0x0B, 0x46, 0xD1, 0xE9, 0x9B
    , 0xF6, 0x73, 0x0B, 0x2A, 0x6A, 0xA4, 0xAC, 0x90, 0x97, 0xEA, 0x7D, 0x35, 0xD8, 0x21, 0x9C, 0xCD
    , 0x17, 0x2E, 0x17, 0x58, 0x97, 0x1B, 0x2C, 0xB4, 0x7E, 0x83, 0xB1, 0xDA, 0x49, 0x4D, 0x07, 0x6D
    , 0x1E, 0x48, 0xC2, 0xDA, 0xF2, 0x06, 0x2A, 0x76, 0xE8, 0xD9, 0x37, 0x69, 0x17, 0x65, 0x74, 0x83
    , 0xB8, 0xEA, 0x25, 0x53, 0xE1, 0xD2, 0x74, 0x81, 0x35, 0xD4, 0x71, 0x33, 0x2A, 0x6D, 0x57, 0x7E
    , 0xF6, 0xE4, 0x13, 0xA2, 0x03, 0xF8, 0x97, 0x76, 0xE6, 0xBF, 0xB0, 0x97, 0xD3, 0xF6, 0x33, 0x34
    , 0x8B, 0xB6, 0xD5, 0x29, 0xA4, 0x4E, 0xA5, 0xF9, 0xA6, 0x19, 0x42, 0x31, 0x56, 0x6E, 0x30, 0xC3
    , 0xF7, 0x66, 0x70, 0x44, 0x0A, 0xC1, 0xF5, 0xF7, 0x18, 0xA9, 0xB6, 0xAB, 0x7A, 0x01, 0x6D, 0x3D
    , 0xCF, 0xC1, 0x20, 0xD4, 0x50, 0x3D, 0xFB, 0xCB, 0x87, 0x53, 0x9D, 0x82, 0x38, 0x57, 0xE2, 0x8D
    , 0x68, 0xDF, 0x78, 0xE5, 0x62, 0x58, 0x62, 0x92, 0x3E, 0xFD, 0x5E, 0xA8, 0x35, 0x80, 0x93, 0xC6
    , 0x35, 0xF0, 0xA2, 0xA4, 0xBA, 0xAD, 0x7B, 0x72, 0x65, 0x75, 0xDA, 0x6F, 0x48, 0x91, 0x07, 0x70
    , 0x0C, 0x19, 0x5E, 0xA5, 0x8B, 0x0C, 0x9C, 0x84, 0xB5, 0xBA, 0x2D, 0x22, 0x2D, 0xAD, 0xB7, 0x0D
    , 0x56, 0xF0, 0x78, 0xA9, 0x75, 0x8E, 0x80, 0x96, 0x38, 0x9B, 0x30, 0xB8, 0xF0, 0xAE, 0xB2, 0xFD
    , 0xA6, 0x82, 0x47, 0x13, 0x4C, 0xB5, 0xC5, 0x99, 0xFF, 0xF9, 0x49, 0xB2, 0x09, 0x92, 0xCC, 0xA1
    , 0x3E, 0x3A, 0x17, 0x93, 0x4A, 0x45, 0x9A, 0xC0, 0x02, 0x52, 0x6A, 0x02, 0x19, 0x45, 0x94, 0x1C
    , 0x73, 0xD6, 0x1E, 0x52, 0xFF, 0x66, 0x12, 0x56, 0x05, 0xA9, 0xBC, 0xC5, 0x10, 0x14, 0x8F, 0x95
    , 0x08, 0x2D, 0x58, 0xC1, 0x34, 0x13, 0xDD, 0x93, 0x49, 0xC5, 0x73, 0x9D, 0x62, 0xC1, 0x4F, 0x24
    , 0x20, 0x34, 0x7A, 0x6E, 0x82, 0xE9, 0xAA, 0x96, 0x6E, 0x90, 0xA1, 0x8E, 0xB8, 0x03, 0x8D, 0x68
    , 0xFF, 0xA7, 0x47, 0xAB, 0xD0, 0x8D, 0x0C, 0xBF, 0xE0, 0x99, 0x40, 0xB8, 0x0C, 0xE7, 0x36, 0x94
    , 0xA1, 0x55, 0x0C, 0x97, 0xBD, 0xCD, 0x28, 0x99, 0xB6, 0x99, 0xD4, 0x69, 0x2E, 0x62, 0x4B, 0x41
    , 0x78, 0x57, 0x86, 0x16, 0xC4, 0xBC, 0x32, 0x8B, 0x02, 0xB1, 0x80, 0x7B, 0x27, 0x4A, 0x05, 0x43
    , 0xC7, 0x94, 0x1F, 0xED, 0x07, 0xB0, 0x1C, 0x9E, 0x64, 0xEF, 0xED, 0x16, 0x1C, 0xC8, 0xB3, 0x55
    , 0xF6, 0x78, 0x34, 0x9E, 0x6F, 0x37, 0x14, 0x1B, 0x4F, 0xE2, 0xDC, 0x1B, 0x77, 0xCE, 0x74, 0x1A
    , 0x2E, 0x3C, 0x0F, 0xCF, 0x0A, 0xDC, 0x31, 0x92, 0x23, 0x5C, 0x4E, 0x46, 0xFC, 0x42, 0xF1, 0xA7
    , 0x05, 0xFD, 0xB0, 0xFF, 0x32, 0xF6, 0xFB, 0xA6, 0x1F, 0x3D, 0x8C, 0x18, 0x38, 0x0F, 0x83, 0xFC
    , 0xEB, 0xFD, 0x51, 0xB8, 0x73, 0x39, 0x7A, 0x88, 0x0F, 0x2E, 0xFA, 0xF7, 0x78, 0xA3, 0x1B, 0x39
    , 0x49, 0xF6, 0xFB, 0xC4, 0xA6, 0x0C, 0x90, 0x31, 0x95, 0x06, 0x6F, 0x4F, 0x32, 0x0B, 0x85, 0xB2
    , 0xF6, 0x40, 0x15, 0x1D, 0x96, 0xB6, 0x10, 0x93, 0x10, 0xFC, 0x84, 0x5D, 0xB1, 0xBA, 0xEE, 0x4A
    , 0xBC, 0x25, 0x0B, 0xC7, 0x49, 0x42, 0x00, 0xF2, 0x74, 0xD6, 0x55, 0x82, 0x13, 0xF5, 0x3B, 0x03
    , 0x0D, 0x7C, 0x51, 0xBF, 0xEA, 0xB7, 0x32, 0x4C, 0x46, 0xA3, 0x33, 0xE6, 0x5F, 0x12, 0x74, 0x78
    , 0xBE, 0x61, 0xFE, 0x0E, 0x17, 0x00, 0x86, 0xDE, 0x57, 0x48, 0x29, 0xBB, 0xEF, 0xEE, 0x13, 0x0F
    , 0xEE, 0xA0, 0x19, 0xB1, 0xD1, 0x22, 0xBB, 0x36, 0x5E, 0x49, 0x2A, 0x58, 0x4D, 0x05, 0x2B, 0x27
    , 0xE0, 0x92, 0xE3, 0xDC, 0x58, 0x00, 0x29, 0x93, 0x78, 0xD8, 0xC6, 0xD3, 0xC7, 0x1B, 0x91, 0xFE
    , 0x43, 0xC5, 0x61, 0x19, 0x94, 0x6A, 0xD2, 0x37, 0xF9, 0xFF, 0xF8, 0x5D, 0x6E, 0x94, 0x03, 0x2F
    , 0x2F, 0xF9, 0xF8, 0xCA, 0xE5, 0x1C, 0xE8, 0xA8, 0x22, 0x33, 0xE7, 0xE1, 0x7F, 0xF0, 0x88, 0x34
    , 0x45, 0x0C, 0x72, 0x27, 0xB4, 0x6F, 0x7B, 0x7D, 0x7E, 0xC6, 0xC2, 0x05, 0xD6, 0xBB, 0x81, 0xB6
    , 0x8F, 0xFF, 0x25, 0xA5, 0x75, 0x13, 0x28, 0x2C, 0x13, 0x3C, 0x49, 0x59, 0x57, 0xF9, 0x04, 0x3A
    , 0x65, 0x04, 0x28, 0x16, 0xF1, 0x19, 0x32, 0x08, 0x32, 0xDA, 0x35, 0x2C, 0xEC, 0x52, 0x31, 0x6F
    , 0x67, 0xCD, 0xAF, 0xDB, 0x2E, 0xB1, 0xEA, 0x9A, 0x18, 0x59, 0x12, 0x0B, 0x46, 0xB6, 0x06, 0xDA
    , 0x85, 0x89, 0xE6, 0xE9, 0x7A, 0xA7, 0x14, 0xBE, 0x0D, 0x0D, 0xA8, 0xAF, 0x21, 0x86, 0x64, 0x09
    , 0xD4, 0xCE, 0x84, 0x93, 0xB8, 0x93, 0x55, 0x62, 0xB3, 0xA3, 0xA2, 0x0A, 0xCE, 0x23, 0x5F, 0xE4
    , 0x45, 0xF7, 0xDA, 0x0F, 0x8A, 0x7A, 0x8D, 0x28, 0x02, 0xDB, 0xED, 0x5C, 0x1C, 0x49, 0xF9, 0x72
    , 0x2A, 0xE3, 0x16, 0x61, 0xFF, 0xF4, 0xD7, 0x54, 0x50, 0x19, 0x50, 0xA8, 0x61, 0xFF, 0x59, 0xA9
    , 0x96, 0x93, 0x75, 0x89, 0xA4, 0x0E, 0x8E, 0x67, 0x08, 0xC6, 0x98, 0x4C, 0xF9, 0xFF, 0x84, 0x7D
    , 0x21, 0xD6, 0x48, 0xFA, 0x33, 0xF1, 0x52, 0x0C, 0x62, 0xEA, 0x80, 0xCB, 0xE1, 0xA0, 0x78, 0x04
    , 0x2D, 0xF0, 0xEB, 0x20, 0xC9, 0x65, 0xDD, 0xB3, 0xAC, 0x8A, 0x14, 0x0F, 0xCB, 0x37, 0xF0, 0x4A
    , 0xED, 0xCD, 0xA0, 0xA9, 0x9D, 0x28, 0x8C, 0xB8, 0xC7, 0x4A, 0xA5, 0x79, 0xE7, 0x3B, 0xC9, 0xBF
    , 0x59, 0xA2, 0xFE, 0xD7, 0x71, 0x37, 0x71, 0x20, 0x90, 0xB6, 0xC2, 0x19, 0x1C, 0x9C, 0x5F, 0x69
    , 0xF1, 0xF0, 0xE8, 0x64, 0x0F, 0x61, 0x53, 0x67, 0x49, 0x95, 0xEA, 0x76, 0x89, 0xED, 0x3D, 0x4F
    , 0xC1, 0xE1, 0x77, 0x77, 0xEB, 0xAF, 0x7A, 0xFA, 0xBB, 0x15, 0xFB, 0xFA, 0xE5, 0x0B, 0xD6, 0xC4
    , 0xB4, 0x7B, 0xC3, 0xA9, 0xE4, 0xDB, 0xEA, 0x40, 0xAC, 0x77, 0x08, 0xBB, 0xBD, 0xAC, 0x3D, 0x4C
    , 0x3A, 0x92, 0x39, 0x27, 0xD1, 0xF0, 0xB0, 0x4A, 0xF3, 0xAC, 0x34, 0x4E, 0x4E, 0x45, 0xD8, 0x58
    , 0x52, 0x7F, 0x1E, 0xFF, 0xAC, 0x36, 0xD3, 0x9C, 0xD0, 0xB3, 0x69, 0x89, 0x7E, 0x09, 0x72, 0xF6
    , 0x67, 0xB4, 0x2C, 0xB6, 0xD3, 0xD5, 0x9A, 0xCF, 0x02, 0xBB, 0x7C, 0xFE, 0x31, 0xCF, 0xF6, 0x16
    , 0x1B, 0xEC, 0xC7, 0x21, 0x0B, 0xA9, 0x2C, 0x09, 0xD6, 0x55, 0xEE, 0xF7, 0x0C, 0x57, 0x34, 0x04
    , 0xE3, 0x7C, 0x5B, 0x0D, 0x09, 0x61, 0xEE, 0x5B, 0x71, 0xFB, 0xC9, 0x07, 0xB0, 0x02, 0xB0, 0xF7
    , 0xA8, 0xD5, 0x23, 0x27, 0x5B, 0xB0, 0xC1, 0x14, 0x95, 0xA6, 0xB3, 0x9B, 0xDB, 0x20, 0xCD, 0xDE
    , 0x21, 0x36, 0x22, 0xAE, 0xE5, 0x4F, 0x49, 0x02, 0xD2, 0x4E, 0xDC, 0x90, 0x7A, 0x5E, 0xF4, 0xAD
    , 0xB6, 0xE7, 0xB3, 0x67, 0xDB, 0x26, 0x8C, 0xFF, 0x2F, 0x21, 0x59, 0xBF, 0x79, 0xDC, 0xAD, 0xD1
    , 0xEE, 0xD6, 0xB2, 0x5F, 0x6C, 0x17, 0x48, 0x06, 0xFC, 0xC2, 0x0B, 0x0C, 0x26, 0x0A, 0x82, 0x1B
    , 0xD3, 0xCC, 0x41, 0xAA, 0xA2, 0x8B, 0xCB, 0xB9, 0x91, 0x55, 0x3F, 0x5D, 0xA9, 0x69, 0xD0, 0xEC
    , 0x50, 0xE7, 0x97, 0x71, 0x00, 0xD7, 0xC3, 0xF3, 0xBF, 0x24, 0x71, 0xEB, 0x53, 0x4E, 0x5F, 0xD1
    , 0x66, 0x65, 0x0A, 0x61, 0xD5, 0x05, 0x91, 0xF8, 0x42, 0xC6, 0x90, 0x7F, 0xD9, 0xC2, 0xC3, 0x3E
    , 0xEC, 0x9F, 0x27, 0xB9, 0xB2, 0xE3, 0xBD, 0xC9, 0x8A, 0x7A, 0x5D, 0x10, 0x7D, 0x98, 0xF5, 0x3D
    , 0xAC, 0x69, 0x9E, 0x67, 0x79, 0xDA, 0xA9, 0x53, 0x8B, 0xDD, 0x18, 0xCD, 0xC5, 0x0F, 0x47, 0x71
    , 0x22, 0x26, 0xFB, 0xB1, 0xB7, 0xB9, 0x87, 0x78, 0x00, 0x09, 0x90, 0x7C, 0x6A, 0x64, 0xD2, 0x2D
    , 0x3D, 0x10, 0x4C, 0xA4, 0xF8, 0x8F, 0x61, 0x8F, 0xC8, 0x5F, 0x2E, 0xF8, 0x07, 0x17, 0x36, 0xC4
    , 0xB2, 0x5D, 0xEE, 0x93, 0x54, 0x53, 0x52, 0x31, 0xC0, 0x7E, 0xDA, 0xFA, 0x79, 0x95, 0x49, 0xED
    , 0x66, 0x6D, 0x31, 0xD5, 0x2C, 0xE9, 0xA1, 0x26, 0x0C, 0x47, 0x23, 0x42, 0x91, 0x3F, 0x14, 0x49
    , 0x1A, 0xC5, 0xEF, 0x7D, 0x9E, 0x8D, 0x37, 0x53, 0x06, 0xA7, 0xF2, 0x88, 0x5B, 0x64, 0xD5, 0xD7
    , 0xBD, 0x6A, 0x54, 0x2F, 0xA4, 0x56, 0x58, 0x0B, 0xCF, 0x65, 0x40, 0xBA, 0x37, 0x99, 0xCE, 0x88
    , 0x64, 0x91, 0xCC, 0x8A, 0x7E, 0x4C, 0x8C, 0x47, 0xA2, 0xBD, 0x04, 0x05, 0xB8, 0xCC, 0x62, 0xCD
    , 0x86, 0x15, 0x54, 0x83, 0x45, 0xC8, 0x07, 0xED, 0x69, 0xD3, 0xB4, 0x90, 0x6A, 0xCE, 0x1C, 0xAC
    , 0x1C, 0x82, 0x93, 0xDF, 0xEC, 0xCB, 0x61, 0xBC, 0x83, 0xA5, 0x54, 0xB9, 0x35, 0xC3, 0x88, 0xE4
    , 0x9F, 0xA8, 0x9F, 0xF1, 0x3C, 0x4F, 0x01, 0xED, 0xC9, 0x71, 0xF6, 0x7F, 0xD6, 0x8C, 0x4B, 0xBC
    , 0x2A, 0x9F, 0x28, 0xF7, 0x9A, 0x16, 0x8A, 0x00, 0xD1, 0x8F, 0x2A, 0x22, 0x3D, 0xD6, 0x7B, 0xB8
    , 0x3B, 0xA3, 0xAD, 0x71, 0x35, 0x1D, 0x72, 0xD3, 0xB7, 0xF1, 0x9A, 0x67, 0x19, 0x23, 0x1E, 0x1B
    , 0x2C, 0x27, 0xEE, 0x34, 0xF9, 0x45, 0x67, 0xB5, 0x1D, 0x2A, 0x9C, 0xA6, 0x5E, 0x66, 0x8D, 0x62
    , 0xB1, 0xEF, 0xB1, 0xD6, 0x5E, 0x2B, 0x91, 0x42, 0xB2, 0x8A, 0x74, 0x7B, 0x8B, 0xEF, 0xE2, 0x02
    , 0x38, 0x82, 0x34, 0x5B, 0xBF, 0x95, 0x4F, 0xBB, 0x70, 0xDC, 0x49, 0x17, 0xAC, 0x73, 0xD0, 0x65
    , 0x45, 0xA6, 0x22, 0xAF, 0x99, 0x76, 0x7A, 0xA8, 0x62, 0x40, 0x2F, 0xCF, 0x31, 0xCE, 0xDD, 0x74
    , 0x4F, 0x8A, 0x36, 0x6F, 0xB3, 0x9B, 0xBA, 0x51, 0x41, 0x2F, 0x85, 0x50, 0x74, 0xD5, 0x66, 0x01
    , 0x90, 0xED, 0x78, 0x4C, 0xC2, 0x03, 0x99, 0x59, 0x4B, 0x08, 0x26, 0x20, 0xC1, 0x6E, 0xF8, 0x41
    , 0x94, 0x73, 0x22, 0xEF, 0xD6, 0xB6, 0x1F, 0x64, 0x72, 0xB4, 0xEA, 0x7A, 0xFE, 0xEB, 0xB8, 0x21
    , 0xE5, 0x16, 0x43, 0xD8, 0x4B, 0xF9, 0x58, 0x8A, 0x50, 0x6E, 0x66, 0xF5, 0x60, 0x42, 0x4E, 0x74
    , 0x49, 0xC3, 0xE5, 0xBB, 0xF8, 0x82, 0x35, 0xAE, 0x61, 0x03, 0xAF, 0x5A, 0xA3, 0x06, 0xDE, 0x60
    , 0x66, 0xB3, 0xBC, 0x87, 0x98, 0xD3, 0xCF, 0x98, 0xF9, 0x34, 0x38, 0xC5, 0xF0, 0x52, 0xED, 0xA5
    , 0x01, 0x66, 0xFF, 0x80, 0x40, 0x88, 0xE9, 0x10, 0x38, 0x5F, 0xDF, 0xB3, 0x95, 0x38, 0xFF, 0x40
    , 0x22, 0xE5, 0x9B, 0xD8, 0xEA, 0xB5, 0x0B, 0x7C, 0x28, 0x18, 0xA1, 0x6B, 0xF7, 0x32, 0x7E, 0x20
    , 0xDD, 0xFB, 0xA3, 0xCA, 0xE4, 0x2F, 0xB0, 0x3D, 0x7F, 0x7A, 0x46, 0xBF, 0x5D, 0x93, 0x54, 0xCD
    , 0xC3, 0xFA, 0x1C, 0x3B, 0x19, 0xFC, 0xE9, 0xD8, 0xFB, 0xB2, 0xB4, 0x0C, 0xF6, 0x4F, 0xB6, 0x42
    , 0x61, 0xD5, 0x99, 0xEC, 0x56, 0xCF, 0xF3, 0x74, 0xD6, 0xC5, 0x10, 0x65, 0x27, 0x81, 0xD0, 0x42
    , 0x9D, 0xFC, 0x87, 0x07, 0xEA, 0x0C, 0x55, 0x8D, 0xBA, 0xE1, 0x72, 0x13, 0xBF, 0x4B, 0x4B, 0x26
    , 0xE0, 0xE7, 0xEC, 0xD1, 0xDA, 0x7F, 0xFC, 0xF1, 0x06, 0x6A, 0x56, 0xC4, 0xDC, 0xB2, 0x63, 0xB5
    , 0x75, 0xEE, 0xEC, 0xAC, 0x8C, 0xDC, 0x35, 0xE6, 0x73, 0x91, 0x36, 0x30, 0x76, 0x9C, 0x50, 0x30
    , 0xF7, 0x63, 0xE1, 0xFC, 0xE1, 0x15, 0x85, 0x42, 0xDD, 0x19, 0xA2, 0x1B, 0x3D, 0xF7, 0x8A, 0xB9
    , 0x93, 0x9F, 0x88, 0x07, 0x00, 0x09, 0x6B, 0xD9, 0x9B, 0xC1, 0x9C, 0x09, 0x45, 0xA9, 0x3C, 0x3E
    , 0x4C, 0xC4, 0x4D, 0x24, 0x79, 0x1A, 0xE1, 0xAA, 0x9E, 0x46, 0x46, 0xF4, 0xA5, 0xF0, 0x74, 0xFE
    , 0xB3, 0x3D, 0xF7, 0x3B, 0x02, 0xBA, 0x7C, 0x1C, 0x4D, 0xFB, 0x02, 0x0E, 0xFF, 0x89, 0xF9, 0xD9
    , 0xEB, 0x4D, 0x53, 0x19, 0x32, 0x37, 0xBD, 0x75, 0x2E, 0xBC, 0x4A, 0x4C, 0x03, 0xB4, 0xE6, 0xE3
    , 0x9A, 0xBE, 0xBD, 0x89, 0xEC, 0x0D, 0x38, 0xDA, 0x51, 0xC0, 0xC3, 0x5F, 0xFA, 0xEE, 0x2B, 0x35
    , 0x49, 0xF2, 0x15, 0x2D, 0x93, 0x14, 0x59, 0xB6, 0x8E, 0x23, 0x80, 0xD7, 0xBF, 0x4B, 0xF2, 0xDD
    , 0x44, 0x6A, 0x5F, 0x48, 0xA5, 0xC1, 0x6D, 0x4C, 0x2C, 0xB4, 0xF5, 0x02, 0x5C, 0x98, 0xE5, 0xD0
    , 0x11, 0xF8, 0xEA, 0xB5, 0xC3, 0x47, 0x39, 0xAC, 0x68, 0xC0, 0x98, 0x3F, 0x1E, 0x51, 0xCB, 0xE1
    , 0x88, 0x32, 0x45, 0x83, 0xD1, 0x62, 0x4D, 0xA3, 0x3F, 0x4A, 0xC7, 0xD6, 0x93, 0x6F, 0xE6, 0x47
    , 0x4A, 0x82, 0x34, 0x6D, 0xE4, 0x67, 0x9E, 0xB0, 0x83, 0x36, 0x84, 0x4A, 0xE2, 0x7C, 0xD2, 0x6A
    , 0x93, 0x9F, 0x88, 0x07, 0x00, 0x09, 0x6B, 0xD9, 0x9B, 0xC1, 0x9C, 0x09, 0x45, 0xA9, 0x3C, 0x3E
    , 0x98, 0x67, 0xCC, 0x9D, 0xD4, 0x01, 0x40, 0x25, 0x02, 0x17, 0xC0, 0xCF, 0x51, 0xD1, 0x24, 0x31
    , 0xAD, 0xAC, 0x92, 0x10, 0x75, 0xCB, 0x97, 0x05, 0x6C, 0xFE, 0x45, 0x4A, 0x03, 0xEA, 0xC6, 0x3C
    , 0xB1, 0xBA, 0x46, 0x61, 0xB4, 0x59, 0x5D, 0x12, 0x89, 0xA6, 0x43, 0x2C, 0xEE, 0x2A, 0x15, 0x63
    , 0x32, 0xC3, 0xEF, 0xBC, 0xAA, 0x12, 0x41, 0xC0, 0xD9, 0x3E, 0x18, 0x6D, 0x9B, 0x47, 0xE3, 0xEA
    , 0x4F, 0x12, 0x6F, 0xCB, 0x7F, 0x03, 0x5B, 0x48, 0x19, 0x52, 0x7A, 0xE6, 0xAD, 0x16, 0xFD, 0xCA
    , 0x79, 0x29, 0x4F, 0xC1, 0x3B, 0x78, 0x16, 0x66, 0x1A, 0x22, 0x92, 0x06, 0x23, 0xEC, 0x27, 0xDC
    , 0x60, 0x61, 0x42, 0x6E, 0x9C, 0x63, 0x75, 0x17, 0x9A, 0x97, 0xC3, 0x09, 0x60, 0x59, 0xFC, 0x81
    , 0x83, 0x96, 0xAA, 0x21, 0xD2, 0xF7, 0x26, 0x2E, 0xAF, 0xF4, 0xAA, 0x27, 0x82, 0x65, 0xD6, 0x44
    , 0xD8, 0x73, 0x04, 0x9C, 0xF1, 0xFD, 0x5C, 0xD0, 0x38, 0xB5, 0xB0, 0xAF, 0xA7, 0x54, 0xD6, 0xC3
    , 0xD0, 0xF8, 0xB8, 0x67, 0x19, 0xD3, 0x75, 0x91, 0x7B, 0x38, 0x3A, 0xD5, 0xF4, 0x38, 0x27, 0xBA
    , 0x09, 0xEA, 0x44, 0xF6, 0x4E, 0xB0, 0xA1, 0xD0, 0x2D, 0x5D, 0x65, 0x80, 0x92, 0x86, 0x2F, 0x30
    , 0x2B, 0x05, 0xC7, 0xDF, 0xB8, 0x13, 0x8C, 0xC2, 0x29, 0xF9, 0x18, 0x9B, 0x85, 0x1D, 0x29, 0xD3
    , 0x4B, 0xF5, 0x05, 0xAA, 0x17, 0x72, 0x13, 0xEE, 0x32, 0x80, 0x1C, 0xF3, 0x07, 0x5A, 0x39, 0x9F
    , 0xF4, 0xC6, 0x6A, 0xB6, 0x1F, 0xB4, 0x85, 0xF4, 0x7B, 0xE6, 0x18, 0xF5, 0x45, 0x10, 0x1B, 0x52
    , 0xF3, 0xD2, 0x35, 0xD8, 0xFF, 0xE4, 0x48, 0x50, 0xA1, 0xA0, 0x4E, 0x06, 0xEA, 0x84, 0xCF, 0xF4
    , 0xC7, 0x48, 0x64, 0xFF, 0x61, 0xFA, 0xDD, 0xA4, 0xAB, 0x25, 0xED, 0xCE, 0xF2, 0x0A, 0xE8, 0xAC
    , 0xF7, 0xCE, 0x2B, 0x09, 0x1F, 0xF3, 0xF6, 0xE2, 0xA2, 0xB7, 0x9E, 0xED, 0xDF, 0x93, 0x0D, 0x23
    , 0xEF, 0xCB, 0xA4, 0x16, 0x80, 0x22, 0x9B, 0x09, 0xAC, 0xDE, 0xE2, 0xD7, 0x93, 0x3E, 0x2D, 0x2F
    , 0x2D, 0x3B, 0xA6, 0x9D, 0x37, 0x51, 0xAB, 0x90, 0x07, 0xF1, 0x1B, 0xD9, 0x5F, 0xDD, 0x16, 0x47
    , 0x15, 0xFA, 0x3D, 0x2F, 0x05, 0x90, 0x07, 0xDD, 0x9C, 0xC2, 0x5D, 0x52, 0x60, 0xA4, 0x52, 0x21
    , 0x6E, 0x16, 0xBF, 0x26, 0x9F, 0x37, 0xE0, 0x3E, 0xF9, 0x98, 0x45, 0x00, 0x44, 0x37, 0x3E, 0xB7
    , 0x41, 0xED, 0x1A, 0xDF, 0xEF, 0x15, 0xDB, 0x54, 0xB4, 0x26, 0x61, 0x87, 0x48, 0x9F, 0x8B, 0xD3
    , 0x5E, 0x26, 0x59, 0xF4, 0x75, 0xCC, 0x47, 0xD0, 0xDA, 0xB8, 0x29, 0xDD, 0x15, 0xBE, 0x31, 0x34
    , 0x8A, 0x7F, 0xDC, 0x29, 0x76, 0x94, 0x8C, 0x65, 0xC8, 0xD8, 0x4A, 0x28, 0x4E, 0x90, 0xFA, 0xB4
    , 0x3E, 0x48, 0xD5, 0xA6, 0xCB, 0x36, 0x02, 0x30, 0xBB, 0xCA, 0xD2, 0xD0, 0x98, 0x2D, 0x6F, 0xD3
    , 0x3F, 0xE6, 0x2B, 0x40, 0x08, 0xE3, 0x28, 0x02, 0xA3, 0x3D, 0x3F, 0xDE, 0xCB, 0xE6, 0xF9, 0xC1
    , 0xA4, 0x7F, 0x75, 0x63, 0x48, 0x1C, 0xCA, 0xF0, 0x2D, 0x4A, 0xEF, 0x6E, 0xCE, 0x45, 0x40, 0xD2
    , 0xC5, 0x6A, 0x0C, 0x47, 0x11, 0x02, 0x8B, 0xBC, 0xD8, 0x34, 0x80, 0x23, 0xA9, 0xD3, 0x23, 0x9B
    , 0x72, 0xAA, 0x17, 0xAA, 0xB1, 0x56, 0x22, 0x21, 0xA3, 0xDD, 0xBB, 0x37, 0x81, 0x84, 0x39, 0xC7
    , 0x3F, 0xEC, 0x7D, 0xB0, 0xB2, 0x79, 0x70, 0x14, 0x9A, 0xF4, 0xD2, 0x9F, 0x10, 0x01, 0xF3, 0x25
    , 0xD5, 0x70, 0x3B, 0xD5, 0x38, 0x0C, 0x96, 0x57, 0xB4, 0x05, 0xB1, 0xD8, 0x04, 0xD7, 0x16, 0xB7
    , 0xFA, 0x69, 0xE8, 0x44, 0x1C, 0xF5, 0xE2, 0x6C, 0x97, 0xE4, 0x51, 0xD5, 0x3D, 0x51, 0xC3, 0x07
    , 0xF8, 0x4B, 0xD7, 0x7A, 0x4B, 0xC1, 0x27, 0x61, 0xBB, 0x46, 0xDE, 0xCE, 0x23, 0x37, 0xE7, 0x5E
    , 0xFF, 0xEE, 0x5F, 0x35, 0x52, 0x2C, 0x43, 0xDE, 0x83, 0xC9, 0x15, 0xC2, 0x11, 0x86, 0xA9, 0x67
    , 0x28, 0xBC, 0xB4, 0x29, 0xF9, 0x9F, 0x8D, 0x2D, 0x0B, 0xF5, 0x2A, 0x60, 0xBB, 0x48, 0x80, 0x54
    , 0x5F, 0x95, 0xE4, 0xFC, 0x5E, 0xFA, 0x24, 0xB3, 0xCC, 0xCF, 0x1D, 0xBF, 0x2F, 0x1C, 0x47, 0x13
    , 0x2F, 0xDE, 0xB2, 0x41, 0x1F, 0xB4, 0x40, 0xAB, 0x4B, 0xCB, 0x13, 0x13, 0x7F, 0xB2, 0x4A, 0xF3
    , 0x77, 0x9C, 0xF4, 0x07, 0xE1, 0x1D, 0x65, 0x1D, 0xB0, 0xCE, 0x48, 0xB0, 0x38, 0xEE, 0x20, 0x95
    , 0x2F, 0xCB, 0xFE, 0xAA, 0x88, 0xCF, 0xAF, 0x80, 0x85, 0x4F, 0xC9, 0xAD, 0x59, 0xBA, 0x0E, 0x94
    , 0xBF, 0x64, 0xEF, 0x2D, 0x10, 0xFF, 0x9F, 0x4C, 0x82, 0x00, 0x92, 0xB9, 0x96, 0xDE, 0x1E, 0x1A
    , 0xD0, 0x6E, 0x70, 0x07, 0x27, 0x76, 0x98, 0x11, 0xAA, 0x7E, 0x5F, 0xAC, 0x2C, 0x24, 0xA7, 0x89
    , 0xF0, 0xF6, 0xFA, 0xE4, 0x19, 0xA3, 0xB9, 0x34, 0x8C, 0xD1, 0xA5, 0x5A, 0xFE, 0x40, 0xE5, 0xBE
    , 0xE9, 0x21, 0x5A, 0x0F, 0x96, 0x87, 0x10, 0x73, 0xBC, 0x76, 0x92, 0x4B, 0xBB, 0xEB, 0x82, 0x3C
    , 0xBF, 0x8B, 0xF1, 0xE9, 0xB3, 0x87, 0xDC, 0x46, 0xD5, 0x06, 0x93, 0xF9, 0xA9, 0x5C, 0xDE, 0x39
    , 0x85, 0xA3, 0x02, 0x7C, 0x9D, 0x89, 0xC9, 0x83, 0xDB, 0x4C, 0x8F, 0x40, 0xA4, 0x2C, 0x9B, 0xE2
    , 0xD0, 0xFD, 0x4E, 0x0B, 0xE3, 0x58, 0x40, 0x3F, 0x97, 0x0D, 0x25, 0x8F, 0x3F, 0xF6, 0x64, 0xBB
    , 0x19, 0xBF, 0xE3, 0xF0, 0x29, 0x2F, 0xC3, 0x16, 0x75, 0x0E, 0x98, 0x8F, 0x30, 0x11, 0xF8, 0x92
    , 0xA2, 0x2A, 0x41, 0xD5, 0x16, 0xBC, 0x3C, 0x24, 0x16, 0x8D, 0x47, 0xC9, 0x06, 0xC6, 0x70, 0x16
    , 0x39, 0x37, 0xE2, 0x25, 0xF8, 0x98, 0xA1, 0xFB, 0x86, 0xB9, 0xD1, 0x86, 0x17, 0x49, 0xFD, 0x6F
    , 0x8A, 0x83, 0x92, 0xB2, 0xF3, 0xDE, 0xBC, 0x44, 0x0F, 0x9F, 0x08, 0xE9, 0x88, 0x40, 0x4E, 0xD2
    , 0x58, 0x68, 0x77, 0x89, 0xA9, 0x78, 0xBB, 0xEC, 0xA9, 0x07, 0x23, 0x3C, 0xA3, 0x12, 0x28, 0x71
    , 0x87, 0x05, 0x86, 0x8B, 0xC7, 0x6B, 0x7E, 0x9A, 0x2D, 0xE0, 0x6D, 0x95, 0x2F, 0xDA, 0x2E, 0x33
    , 0x42, 0x47, 0xFF, 0x41, 0x51, 0x1E, 0xB2, 0xB0, 0x07, 0xD9, 0x4D, 0x5D, 0x4F, 0xDC, 0x2F, 0xEB
    , 0xFA, 0x56, 0xB9, 0xDA, 0x53, 0x7D, 0x75, 0x40, 0xD6, 0xA7, 0x32, 0x66, 0xFF, 0x7A, 0xB8, 0xBF
    , 0x16, 0xB2, 0x51, 0x3D, 0x4D, 0x80, 0xFD, 0x1D, 0x11, 0x32, 0x57, 0xC9, 0x95, 0x4E, 0xAF, 0xC6
    , 0xB0, 0x19, 0xF8, 0xC0, 0x0B, 0x1F, 0xD3, 0x92, 0xAA, 0xF0, 0xA3, 0xEE, 0x7D, 0x2D, 0xA7, 0xA4
    , 0xB5, 0xC9, 0x45, 0x2E, 0x95, 0xF2, 0x38, 0x36, 0x49, 0x80, 0x9D, 0x9E, 0x95, 0x1D, 0x94, 0x57
    , 0x97, 0x55, 0x0B, 0xDC, 0x03, 0xC5, 0x57, 0xB2, 0x13, 0x39, 0xB2, 0x98, 0x5B, 0xAD, 0xF6, 0xF5
    , 0x51, 0xCD, 0xCB, 0x44, 0x54, 0xE8, 0xF7, 0xB5, 0xA4, 0xD6, 0x0F, 0xA1, 0x55, 0xB3, 0x40, 0x93
    , 0xC6, 0xF8, 0xE1, 0x45, 0x74, 0xDA, 0x65, 0xF3, 0x8A, 0xE9, 0x57, 0xEE, 0x9E, 0x82, 0xEE, 0xEA
    , 0x9B, 0x27, 0xE8, 0x34, 0x4E, 0x40, 0xE9, 0x99, 0x29, 0x22, 0x74, 0x92, 0x7E, 0x03, 0x8D, 0x08
    , 0x41, 0x8E, 0x7B, 0xA4, 0xBE, 0x17, 0x2F, 0x7F, 0xC1, 0xD4, 0xED, 0x45, 0x5A, 0xB3, 0x31, 0x67
    , 0x6D, 0x51, 0x39, 0xF4, 0x30, 0xD9, 0xFB, 0xB7, 0x87, 0xD8, 0x21, 0xB6, 0x2B, 0xAE, 0xBB, 0x76
    , 0xBD, 0xC3, 0x4F, 0x31, 0x65, 0x63, 0x89, 0x5C, 0xFD, 0xDE, 0x36, 0xB7, 0xD3, 0xD6, 0x65, 0xC5
    , 0xE7, 0x16, 0x1B, 0xEC, 0xF0, 0x3D, 0x47, 0x54, 0x66, 0x5E, 0xF0, 0x61, 0xB4, 0x00, 0x66, 0x13
    , 0xD6, 0x5E, 0xBD, 0xC7, 0xC8, 0x11, 0xE1, 0x80, 0x82, 0x7C, 0x3D, 0x00, 0x23, 0xC2, 0x34, 0xA9
    , 0x71, 0x66, 0xD7, 0x7E, 0x52, 0x45, 0x8E, 0xF2, 0xE7, 0x4B, 0x2C, 0x4A, 0x00, 0x8C, 0x28, 0xFD
    , 0xA2, 0xFC, 0xC8, 0x72, 0xAC, 0x55, 0x25, 0xAD, 0xE6, 0x85, 0x86, 0x78, 0x8D, 0xA2, 0x47, 0xF7
    , 0xA0, 0xCC, 0x03, 0xC0, 0xA3, 0x38, 0x7B, 0xD4, 0x7F, 0xD7, 0xE5, 0x58, 0xB4, 0x4D, 0x7B, 0xB8
    , 0x10, 0x53, 0x0D, 0x5F, 0x15, 0x14, 0xAC, 0x4E, 0x3D, 0x80, 0x45, 0x92, 0x34, 0xDF, 0x82, 0xF2
    , 0xCE, 0x2A, 0x25, 0x7B, 0xB7, 0x48, 0x36, 0xCF, 0xCE, 0x14, 0xCF, 0xB1, 0x82, 0xDE, 0x85, 0xAD
    , 0x51, 0x5E, 0x0C, 0x3F, 0xE6, 0xD2, 0x4C, 0x6E, 0x40, 0x35, 0xB9, 0x07, 0x45, 0x3F, 0x23, 0x44
    , 0x60, 0xD7, 0x78, 0x51, 0x44, 0x08, 0x43, 0x74, 0x17, 0xDD, 0x21, 0x7E, 0x04, 0xE9, 0x58, 0xF2
    , 0x0F, 0xBB, 0x1D, 0xDB, 0xA6, 0xE6, 0x3C, 0x72, 0xF1, 0x02, 0x1A, 0x66, 0x63, 0xAF, 0x4A, 0x0A
    , 0x7F, 0x46, 0x7C, 0x2C, 0x5B, 0xA9, 0x3A, 0x3A, 0xB3, 0x7A, 0x5F, 0xDF, 0x60, 0x49, 0xE8, 0xC0
    , 0xC2, 0x4B, 0x81, 0xAE, 0xD6, 0xDD, 0x4A, 0x46, 0x8C, 0xEB, 0xF3, 0x10, 0x5C, 0x90, 0x9B, 0x6F
    , 0x23, 0x1C, 0xD7, 0xAB, 0xB2, 0x70, 0x87, 0xA8, 0x80, 0xAB, 0xFF, 0xB0, 0x04, 0xAD, 0x40, 0xFE
    , 0x41, 0x29, 0xAE, 0xE6, 0xDD, 0xF1, 0xA8, 0x69, 0xA6, 0xA4, 0xF1, 0x67, 0x65, 0x8F, 0x7F, 0xC1
    , 0x41, 0x7E, 0xA2, 0xA0, 0xB1, 0x5D, 0x28, 0xC6, 0x04, 0x3B, 0x90, 0x0A, 0x22, 0x53, 0x16, 0x17
    , 0x0A, 0xEF, 0xDB, 0x63, 0xEA, 0xDB, 0x40, 0x1B, 0xF9, 0x14, 0xBC, 0xCB, 0x84, 0x98, 0x3E, 0xF7
    , 0x33, 0xEA, 0x14, 0x67, 0x52, 0x32, 0x6B, 0xAD, 0x6D, 0xE4, 0x0F, 0x62, 0x58, 0x6D, 0x8A, 0x3D
    , 0x6C, 0x55, 0xCB, 0x30, 0xD9, 0x36, 0xE9, 0x96, 0x18, 0x4E, 0x37, 0x69, 0xC9, 0x5A, 0xCD, 0xCB
    , 0x83, 0x22, 0x9D, 0xD5, 0xFA, 0xDC, 0xA7, 0xB7, 0x4D, 0xFC, 0x4D, 0x56, 0x70, 0xF6, 0x0F, 0xE9
    , 0x29, 0x4C, 0xC8, 0x19, 0xA1, 0x48, 0x8A, 0x03, 0x84, 0xA4, 0x08, 0xE9, 0xA8, 0x2C, 0x48, 0xAA
    , 0x04, 0x66, 0xCF, 0x46, 0x54, 0xC0, 0x20, 0xEA, 0x49, 0x70, 0x35, 0x7D, 0xDF, 0xA5, 0x55, 0x66
    , 0x76, 0xE9, 0x5A, 0xE1, 0xBA, 0x24, 0xF8, 0x99, 0x46, 0x51, 0x13, 0xD9, 0x28, 0xCD, 0xC8, 0x7D
    , 0xC5, 0x01, 0x33, 0x02, 0x9F, 0xA4, 0xFA, 0xAC, 0xB3, 0xCA, 0x79, 0xFE, 0x72, 0x40, 0x95, 0xA3
    , 0x7D, 0x03, 0x07, 0xC9, 0x0D, 0xE2, 0x5C, 0xB1, 0xCA, 0x18, 0x12, 0x33, 0x0B, 0x95, 0x98, 0x27
    , 0x1E, 0x55, 0x9B, 0x73, 0x8C, 0x21, 0xF1, 0x7B, 0xF5, 0x58, 0x3F, 0x9C, 0x16, 0xCB, 0xB6, 0x9D
    , 0x60, 0xC7, 0x06, 0x78, 0x07, 0x98, 0xBF, 0xE0, 0x1D, 0x05, 0x83, 0x0D, 0xFC, 0xDA, 0xA8, 0x1A
    , 0xAA, 0x20, 0x83, 0x65, 0xD7, 0x4E, 0x06, 0x21, 0x5B, 0x85, 0x31, 0xE1, 0x52, 0x60, 0xF9, 0xD9
    , 0xD9, 0x25, 0x9E, 0xFE, 0xE4, 0x90, 0x89, 0x2A, 0x2B, 0x7F, 0xB8, 0xAE, 0x23, 0xB7, 0xE1, 0x7A
    , 0x92, 0x70, 0x93, 0xC1, 0xDE, 0xF1, 0x87, 0x5B, 0x41, 0x18, 0xEA, 0xCF, 0x78, 0x2F, 0xDC, 0x3D
    , 0xD4, 0x59, 0xFA, 0xA6, 0xD9, 0xC3, 0x58, 0x5B, 0xF0, 0x45, 0xC2, 0x18, 0xD8, 0x98, 0x83, 0x47
    , 0x99, 0xDF, 0x12, 0x0F, 0x93, 0x4E, 0x95, 0x8B, 0x13, 0xDD, 0x16, 0x0E, 0xD4, 0x83, 0x1A, 0x14
    , 0x07, 0x3C, 0xC9, 0x93, 0x29, 0xF2, 0xA6, 0x58, 0x87, 0xE5, 0x31, 0x78, 0x8F, 0x8A, 0x4A, 0xFF
    , 0xF6, 0xA4, 0x4E, 0x9D, 0xA6, 0x6D, 0xC0, 0xAA, 0x54, 0xE1, 0x11, 0x73, 0x8F, 0xB0, 0x6B, 0xEF
    , 0x39, 0xD9, 0x14, 0xA2, 0xFD, 0xBE, 0x40, 0x29, 0x00, 0x39, 0x3B, 0xEF, 0xA7, 0xA3, 0x92, 0x64
    , 0xF4, 0x67, 0xF2, 0xA3, 0xF5, 0x8C, 0x36, 0x21, 0x8E, 0x3F, 0xA6, 0x29, 0xE8, 0x92, 0xC5, 0x55
    , 0xFF, 0x36, 0x7D, 0x05, 0x6E, 0x4A, 0x0C, 0x51, 0x30, 0x94, 0x2C, 0x74, 0xE9, 0xB9, 0xD2, 0x34
    , 0x36, 0xAC, 0x88, 0xF3, 0x4B, 0xBD, 0x31, 0xCF, 0xB1, 0x9D, 0x0F, 0x85, 0xC6, 0x5A, 0xAD, 0xB1
    , 0xD2, 0xCB, 0x87, 0x6C, 0x52, 0x87, 0x77, 0x17, 0x1E, 0xEE, 0x6E, 0x11, 0xE9, 0xA6, 0x24, 0x36
    , 0xD4, 0x60, 0x14, 0xD7, 0xCD, 0xAE, 0x07, 0xAA, 0xAE, 0xB0, 0x0C, 0xF0, 0x6C, 0x83, 0xEF, 0xEB
    , 0xA2, 0xD1, 0xF1, 0x19, 0x4C, 0x21, 0xA3, 0x17, 0x10, 0xCB, 0x59, 0x49, 0x91, 0x0F, 0x30, 0x09
    , 0x4F, 0xC5, 0x5C, 0x11, 0x53, 0x87, 0x69, 0xC4, 0x06, 0x5D, 0xA8, 0x06, 0x55, 0xD0, 0x84, 0xA3
    , 0x19, 0xBC, 0x86, 0x4B, 0xE5, 0xF2, 0x81, 0xF0, 0x74, 0x2B, 0x79, 0xB2, 0xCD, 0x1B, 0xA3, 0xBF
    , 0x5D, 0xDC, 0x71, 0xFC, 0xF3, 0xEC, 0x8B, 0x11, 0x94, 0xD3, 0x93, 0x6D, 0xE3, 0x27, 0xF8, 0x31
    , 0xCE, 0x1A, 0xBE, 0x2E, 0xE6, 0x2D, 0x8A, 0xFC, 0x85, 0x82, 0xE9, 0xEC, 0xF5, 0xD8, 0xE4, 0x7F
    , 0x3C, 0x87, 0x51, 0x97, 0x9F, 0x29, 0xD2, 0xE3, 0x24, 0x14, 0x87, 0x3B, 0x7F, 0x4D, 0x24, 0xB7
    , 0x44, 0xEC, 0x1E, 0x2D, 0xAD, 0x87, 0x0D, 0x73, 0xB2, 0x68, 0x20, 0x09, 0xAF, 0x02, 0xF1, 0x58
    , 0x49, 0x77, 0x23, 0xBA, 0xD4, 0xB3, 0x72, 0xA9, 0xED, 0x95, 0x36, 0xEC, 0x32, 0x79, 0xA8, 0x70
    , 0x27, 0x8A, 0x3B, 0x1C, 0x68, 0x07, 0x8E, 0xA5, 0xB8, 0xE3, 0x81, 0x57, 0xA4, 0x0A, 0x07, 0xEA
    , 0x4E, 0x44, 0x5F, 0x5E, 0x9D, 0xDF, 0x20, 0xA8, 0x5D, 0xD5, 0xBE, 0xED, 0xEA, 0xF9, 0x23, 0x31
    , 0x93, 0xF6, 0x34, 0xC8, 0x5B, 0xA5, 0x46, 0x25, 0xCD, 0xDD, 0x31, 0xCB, 0x9A, 0xAA, 0x0C, 0xD1
    , 0x6D, 0x5A, 0xB3, 0x65, 0x3C, 0xE0, 0x80, 0x67, 0xE8, 0x5C, 0x76, 0xCF, 0x36, 0x7F, 0xF0, 0x3B
    , 0xB9, 0x0F, 0xE8, 0x56, 0xCA, 0xDA, 0xDE, 0x47, 0xD2, 0x88, 0x90, 0xAC, 0xE8, 0x92, 0x22, 0x8A
    , 0x61, 0x1A, 0xFE, 0x21, 0x41, 0x6C, 0x25, 0x69, 0xDE, 0xD8, 0x33, 0xDF, 0x2A, 0xC4, 0xB4, 0xFC
    , 0x50, 0x56, 0x78, 0xCE, 0xE9, 0x6C, 0xEA, 0xBF, 0xEE, 0x50, 0xED, 0xC7, 0x96, 0xD9, 0x88, 0xD4
    , 0x83, 0xCB, 0x93, 0xFB, 0x7D, 0x3B, 0x04, 0xAC, 0x96, 0x7A, 0xAB, 0xFC, 0x2F, 0xCE, 0xD1, 0x68
    , 0xF0, 0x91, 0x87, 0xE0, 0x15, 0x93, 0xF7, 0x3A, 0x8D, 0xAB, 0xAD, 0xD8, 0x7F, 0x42, 0x76, 0xA4
    , 0x12, 0xD2, 0x54, 0x31, 0xB5, 0x79, 0xC1, 0xA1, 0xED, 0x6A, 0x38, 0x65, 0x8B, 0xDF, 0x6D, 0xD7
    , 0x48, 0x2C, 0xA4, 0x62, 0x9E, 0x1F, 0x0A, 0x3F, 0xB2, 0xB4, 0x1F, 0x92, 0xB7, 0xF9, 0x5A, 0x93
    , 0xF0, 0x1B, 0x67, 0x04, 0x60, 0x3A, 0x79, 0x01, 0x76, 0x40, 0xEE, 0x80, 0xF5, 0x19, 0x52, 0x2D
    , 0xA3, 0xE4, 0xCA, 0xEC, 0x4F, 0x4B, 0x09, 0x2C, 0xE2, 0x86, 0xD7, 0x6F, 0x35, 0x07, 0xC9, 0x77
    , 0xE6, 0x94, 0x65, 0xA4, 0x3A, 0xC1, 0xDD, 0xAF, 0x14, 0x80, 0x2D, 0xAD, 0x6B, 0xBC, 0x33, 0x5E
    , 0xE9, 0x80, 0x3B, 0xF3, 0xCA, 0x89, 0xCD, 0x39, 0xA9, 0xC4, 0xA7, 0x50, 0xE9, 0x40, 0x10, 0x12
    , 0x63, 0x17, 0xD0, 0xD0, 0x17, 0x9E, 0x7B, 0x7C, 0x50, 0x56, 0x27, 0x7B, 0x87, 0xEC, 0x90, 0x67
    , 0xF2, 0xF2, 0x67, 0x5F, 0x49, 0x5A, 0xAB, 0x2E, 0x80, 0xC1, 0xC9, 0x32, 0x19, 0xA4, 0xFC, 0x19
    , 0x59, 0x32, 0xFA, 0xE9, 0xA8, 0x99, 0xD7, 0x8C, 0x7A, 0x4E, 0x07, 0xCE, 0x7F, 0x16, 0x59, 0x47
    , 0x90, 0x4E, 0xEE, 0x8B, 0xFF, 0xBA, 0xE3, 0xB8, 0x3F, 0x02, 0xE8, 0xC4, 0x4A, 0x50, 0xBC, 0x2F
    , 0xC0, 0x95, 0x8D, 0xFE, 0xAF, 0xEB, 0x74, 0xF1, 0x42, 0x59, 0x20, 0x51, 0xA6, 0xAC, 0x49, 0xFF
    , 0x68, 0x47, 0x00, 0x04, 0x55, 0x93, 0xCD, 0x85, 0x7B, 0xE5, 0xD6, 0x8C, 0x3B, 0xEB, 0x66, 0x62
    , 0xB4, 0xD8, 0x67, 0x20, 0xCA, 0x11, 0x60, 0xE7, 0x71, 0xFC, 0xB4, 0x4E, 0x84, 0x94, 0x49, 0xE8
    , 0x4E, 0xE5, 0x84, 0x9F, 0x2A, 0x70, 0x1D, 0xF1, 0xD1, 0x4A, 0x9C, 0x5E, 0xDF, 0xF3, 0xA7, 0x50
    , 0x0B, 0x35, 0xF2, 0xC4, 0x1E, 0x8A, 0x9F, 0xD5, 0x7B, 0x16, 0xFA, 0x98, 0x71, 0x55, 0x6C, 0xC4
    , 0x4C, 0x17, 0x5E, 0xD4, 0x73, 0x2C, 0xA0, 0x4C, 0x14, 0xB8, 0x48, 0x51, 0x3F, 0xBF, 0x57, 0x30
    , 0x9D, 0x96, 0x11, 0x80, 0x40, 0x71, 0x3D, 0x17, 0x7D, 0x7E, 0xF3, 0xE6, 0xF3, 0x1D, 0x00, 0x73
    , 0x70, 0x35, 0x5B, 0x98, 0x02, 0xF0, 0x90, 0x9A, 0x20, 0x2D, 0x15, 0xE9, 0x14, 0x0E, 0x5A, 0x12
    , 0x00, 0x08, 0x27, 0xDF, 0x4D, 0x10, 0x52, 0xF2, 0x08, 0xF5, 0x94, 0x28, 0xED, 0x2E, 0x97, 0x07
    , 0x0D, 0xAE, 0xED, 0x83, 0xBC, 0x58, 0x6A, 0xFA, 0x54, 0xEA, 0x48, 0xDB, 0x97, 0xB8, 0xAA, 0x22
    , 0xA2, 0x07, 0xC6, 0x01, 0x7D, 0x55, 0x76, 0x1F, 0x9D, 0x21, 0x20, 0xF4, 0xF8, 0xF0, 0xA5, 0xF0
    , 0x5F, 0xB9, 0xAF, 0x7A, 0x79, 0xEB, 0x3E, 0x28, 0xCC, 0xD2, 0x20, 0x04, 0x2E, 0x1D, 0xF4, 0xD4
    , 0x1F, 0xFB, 0xC0, 0x93, 0xF9, 0x53, 0x32, 0xD0, 0x2F, 0x91, 0x78, 0x37, 0x59, 0x2E, 0x52, 0x2F
    , 0x50, 0x9B, 0xAE, 0x03, 0xC3, 0xEE, 0x80, 0xEE, 0xB2, 0x09, 0x86, 0x3D, 0x9C, 0xCF, 0xC4, 0xC3
    , 0xC9, 0x22, 0x41, 0x39, 0xC8, 0x8E, 0xA6, 0x48, 0x1E, 0x68, 0xD1, 0xC7, 0xB3, 0xA4, 0xCE, 0x3E
    , 0xC4, 0xEB, 0xAF, 0x09, 0xDD, 0x5B, 0xD0, 0xAC, 0x89, 0xE8, 0x8C, 0x66, 0x8C, 0x98, 0x23, 0xF6
    , 0x68, 0x36, 0xDB, 0x19, 0x86, 0x01, 0x70, 0x25, 0x7E, 0x70, 0x99, 0xF1, 0x62, 0x2D, 0x95, 0x4D
    , 0x36, 0x5E, 0x06, 0x2F, 0xBE, 0x3F, 0xAC, 0xC7, 0x35, 0x0A, 0xBE, 0x1A, 0x59, 0x6C, 0x81, 0x5F
    , 0xE5, 0x4D, 0xAA, 0x28, 0xC8, 0x69, 0x1F, 0x87, 0x52, 0xF3, 0x38, 0x99, 0x3D, 0x58, 0xCE, 0xD8
    , 0xF2, 0x19, 0xA8, 0xE0, 0x8B, 0xD4, 0xF5, 0xD3, 0x67, 0x6B, 0xF4, 0x3A, 0x19, 0x24, 0xB4, 0xAD
    , 0x0C, 0x1D, 0xC2, 0x89, 0x33, 0xC7, 0x6E, 0x6F, 0x07, 0x06, 0xAB, 0xB5, 0x28, 0x36, 0xDA, 0xE0
    , 0x02, 0x7B, 0xCE, 0x66, 0x1D, 0xB8, 0x83, 0xBD, 0x80, 0x9B, 0xEA, 0x11, 0x7E, 0x68, 0x2A, 0x51
    , 0xA8, 0x1F, 0x14, 0x2D, 0x04, 0xE1, 0x77, 0x2A, 0xB6, 0x98, 0xF0, 0x8C, 0xD0, 0x5F, 0x9C, 0x00
    , 0x80, 0x8E, 0x46, 0x85, 0x17, 0x27, 0x89, 0x63, 0xB2, 0x1E, 0xB2, 0xEB, 0x01, 0x5A, 0x75, 0xDE
    , 0x9F, 0x3F, 0xEC, 0x77, 0x70, 0x71, 0xA1, 0xE5, 0xC4, 0xC1, 0xFB, 0x89, 0x2E, 0x92, 0x29, 0xF2
    , 0x2A, 0x6D, 0x48, 0x8B, 0x17, 0x4B, 0xAA, 0x4D, 0x23, 0x1D, 0x38, 0x3A, 0xD5, 0x41, 0x62, 0xBF
    , 0xA9, 0x7B, 0x3E, 0x73, 0x08, 0xC2, 0x87, 0x00, 0xD5, 0x0F, 0x2A, 0x34, 0xCA, 0xA3, 0x59, 0x9B
    , 0x7C, 0x46, 0x1D, 0x59, 0xFB, 0xAC, 0x86, 0x2D, 0x6A, 0x77, 0x05, 0x9A, 0xD7, 0x28, 0xB6, 0xD5
    , 0xC3, 0xFA, 0x0E, 0x46, 0x91, 0xE7, 0xEF, 0xD6, 0xCC, 0x1B, 0x72, 0x94, 0x05, 0x00, 0xB9, 0x8D
    , 0xE6, 0x85, 0x22, 0x99, 0xB5, 0x94, 0x0C, 0x05, 0x6A, 0xEC, 0x82, 0x02, 0x0B, 0xE4, 0x44, 0xB9
    , 0xDF, 0x10, 0x95, 0xC7, 0x5C, 0xF9, 0x8B, 0x35, 0xF1, 0x87, 0xF6, 0xDA, 0x3E, 0xD6, 0x83, 0x64
    , 0xDE, 0x57, 0x7C, 0xF3, 0xDB, 0xF1, 0xE5, 0xE8, 0xD6, 0x43, 0xF3, 0x6E, 0xED, 0x3F, 0xC0, 0x13
    , 0x9F, 0x1D, 0x8E, 0x71, 0x20, 0xD1, 0x22, 0x99, 0x0B, 0x3E, 0x6A, 0x69, 0x1B, 0xFF, 0x3F, 0xD3
    , 0x31, 0xA9, 0x24, 0xBA, 0xAA, 0xA1, 0x0B, 0x68, 0xE1, 0x42, 0x04, 0xED, 0x9B, 0x6B, 0x0D, 0xD1
    , 0xCF, 0xC0, 0x79, 0x99, 0xCE, 0x8C, 0x42, 0x9E, 0x22, 0x32, 0xAF, 0x72, 0x65, 0x76, 0xDC, 0xA5
    , 0x3F, 0xE1, 0xC7, 0x39, 0xCB, 0xAF, 0xE2, 0xC8, 0x14, 0x3C, 0x41, 0xFE, 0x6F, 0x47, 0xE7, 0x0E
    , 0x85, 0xD9, 0x3A, 0x09, 0x7E, 0x6B, 0x53, 0x6A, 0xD7, 0xB2, 0xDF, 0x5D, 0xE2, 0x81, 0x29, 0x1A
    , 0xCF, 0x10, 0x86, 0xE2, 0x53, 0x3C, 0x7A, 0x69, 0xE5, 0x62, 0x38, 0x2B, 0x0F, 0x9E, 0x79, 0x40
    , 0x99, 0x3A, 0x16, 0x8E, 0xE6, 0x68, 0xF0, 0x61, 0xAC, 0x11, 0x45, 0xC2, 0x1D, 0x9E, 0x53, 0x79
    , 0x07, 0xD9, 0xCD, 0x58, 0xDF, 0x76, 0xAD, 0xA5, 0xF4, 0xB7, 0xEE, 0x3E, 0x7A, 0xB2, 0xC2, 0x32
    , 0x76, 0xDB, 0x15, 0xD6, 0x6B, 0x20, 0xF1, 0xA2, 0xDB, 0x00, 0x0C, 0xC8, 0xA7, 0xA5, 0xD9, 0x9A
    , 0x68, 0xF5, 0xF7, 0x7F, 0x47, 0xB4, 0x73, 0x0D, 0x37, 0x05, 0xA5, 0x77, 0xE3, 0x69, 0x5F, 0x0A
    , 0xFA, 0x94, 0x3D, 0xCD, 0x33, 0xBF, 0x55, 0xDE, 0xAD, 0x03, 0x6E, 0x3E, 0x13, 0x8E, 0x95, 0x71
    , 0xD4, 0xCC, 0xC2, 0x30, 0x85, 0x64, 0xED, 0x96, 0xFC, 0xF0, 0x4E, 0x11, 0x3E, 0x74, 0xA9, 0xD8
    , 0x2C, 0xBB, 0x5D, 0xAD, 0x49, 0xE1, 0x10, 0x31, 0xD1, 0x95, 0xFC, 0x77, 0x27, 0x8A, 0x4F, 0x51
    , 0x5F, 0x61, 0x5D, 0x45, 0x2D, 0xE3, 0x98, 0x64, 0x43, 0xA3, 0x51, 0xBB, 0x48, 0x1F, 0x42, 0xFF
    , 0xFB, 0x3A, 0x6A, 0x52, 0xE5, 0x90, 0xD0, 0x32, 0xC8, 0x56, 0x5B, 0x50, 0xC5, 0x94, 0x9E, 0xF4
    , 0x80, 0xAA, 0x5B, 0x6D, 0x52, 0x79, 0x65, 0x87, 0x42, 0x69, 0x22, 0xE2, 0x13, 0x44, 0x6C, 0x07
    , 0xC0, 0x13, 0xC7, 0xE2, 0xC9, 0xD6, 0x7C, 0x68, 0xB2, 0xCC, 0x12, 0x7D, 0x19, 0xC6, 0x69, 0xCC
    , 0x8C, 0x96, 0xF7, 0x49, 0x4C, 0x34, 0x9F, 0xBA, 0x46, 0x5D, 0xDF, 0x17, 0xA5, 0x6A, 0x42, 0xA2
    , 0xD1, 0x17, 0x04, 0xD6, 0x66, 0x39, 0xAD, 0x0D, 0x64, 0xD9, 0x21, 0xDD, 0x3B, 0x0E, 0xEA, 0x43
    , 0xA9, 0x02, 0x29, 0x15, 0x7E, 0xC3, 0x11, 0xA9, 0xC4, 0x0A, 0x55, 0x8E, 0x0B, 0xEF, 0xAE, 0x1E
    , 0x54, 0x56, 0x82, 0x3D, 0x88, 0xFB, 0x60, 0x1A, 0x6C, 0xF4, 0x98, 0x82, 0xD6, 0xAF, 0xBB, 0x39
    , 0x65, 0xDC, 0x9D, 0xD6, 0x4B, 0xA1, 0xE3, 0xFB, 0x49, 0x58, 0x41, 0x33, 0x25, 0x52, 0x9F, 0x84
    , 0xA1, 0x43, 0x1C, 0x48, 0x87, 0x09, 0xFF, 0x7E, 0x89, 0x25, 0x54, 0x9E, 0x30, 0x68, 0x26, 0x4C
    , 0xC7, 0xCE, 0x5F, 0xB5, 0xFB, 0x7F, 0x9B, 0xEB, 0xB0, 0xCF, 0x25, 0x78, 0x97, 0x96, 0x9D, 0xB9
    , 0x00, 0xD4, 0x29, 0x6E, 0x92, 0x3D, 0x18, 0xE5, 0x56, 0xE9, 0x55, 0x14, 0x6B, 0xFA, 0xD8, 0xF2
    , 0xE8, 0x4A, 0x8D, 0x5C, 0xBD, 0x27, 0x1D, 0x02, 0x78, 0x64, 0xE7, 0x85, 0x4A, 0x10, 0x0C, 0x27
    , 0xC0, 0xCE, 0xF6, 0xF3, 0x74, 0x57, 0x5C, 0x83, 0xA3, 0x27, 0x46, 0xE6, 0xB3, 0x00, 0x04, 0xCF
    , 0xBE, 0x64, 0x0A, 0xDE, 0xD0, 0xFB, 0xB6, 0x11, 0x71, 0x54, 0xCB, 0x7D, 0x30, 0x2F, 0x25, 0xBD
    , 0xD9, 0x7B, 0x00, 0xB4, 0x75, 0x5D, 0xEC, 0xA9, 0x81, 0xC3, 0x75, 0x16, 0x6C, 0xC6, 0xDD, 0xA2
    , 0x30, 0xF6, 0xD7, 0x64, 0xB4, 0x87, 0x09, 0x0E, 0x7C, 0xEF, 0x9C, 0xB9, 0xF4, 0xCE, 0x35, 0xF5
    , 0xB8, 0x4D, 0x06, 0x18, 0x5D, 0x2A, 0xBB, 0x67, 0xC2, 0xCB, 0xA6, 0x40, 0xD3, 0xFE, 0x7B, 0xCD
    , 0x19, 0x33, 0x08, 0x75, 0x38, 0xE5, 0x77, 0x09, 0x36, 0xAF, 0x85, 0x4D, 0xAC, 0xB7, 0xE0, 0xFC
    , 0x04, 0x16, 0xE6, 0x86, 0x2E, 0x49, 0x3E, 0x9F, 0x70, 0xC0, 0x35, 0xF8, 0x86, 0x88, 0x7F, 0xA8
    , 0x10, 0x36, 0x7D, 0xB0, 0xA2, 0xC7, 0x61, 0x81, 0xAA, 0x28, 0x48, 0x1D, 0xBF, 0xD3, 0x13, 0x29
    , 0x73, 0x8F, 0x5B, 0x4E, 0x5D, 0x71, 0x62, 0xAC, 0xD3, 0x8D, 0x41, 0xE5, 0x90, 0x7A, 0xFE, 0x83
    , 0x06, 0x6C, 0x38, 0x51, 0xEE, 0x5E, 0xBE, 0x9B, 0x97, 0xF2, 0x0A, 0xCC, 0xAD, 0xBD, 0x37, 0x53
    , 0x1C, 0x9F, 0x28, 0x87, 0xF8, 0x89, 0x5C, 0xB0, 0x23, 0x41, 0xA8, 0x59, 0x97, 0xC9, 0x01, 0x88
    , 0x5B, 0xA4, 0x7B, 0xBA, 0xAC, 0x33, 0xFC, 0x55, 0xC7, 0x24, 0x12, 0xB8, 0xFC, 0x5C, 0x9F, 0xE3
    , 0xFD, 0x14, 0x41, 0x6B, 0x9F, 0x49, 0x3C, 0x5D, 0xE5, 0x8E, 0xBD, 0x8D, 0x9E, 0x38, 0x1F, 0x34
    , 0xEA, 0xAB, 0x88, 0x13, 0xA0, 0x53, 0x4B, 0xB1, 0x91, 0xE7, 0x12, 0x9C, 0x56, 0x1E, 0xD9, 0x47
    , 0x92, 0x9C, 0x44, 0xE9, 0xC6, 0x82, 0xDC, 0x77, 0xB7, 0xC9, 0x7E, 0xF7, 0xF1, 0x23, 0xF2, 0xCE
    , 0xA8, 0x7B, 0x4A, 0x3B, 0x55, 0x29, 0x79, 0xBA, 0xBD, 0x1E, 0x9A, 0x22, 0x8F, 0xB1, 0x11, 0xDB
    , 0x81, 0x70, 0x7D, 0xCC, 0xA3, 0x06, 0x6B, 0x75, 0xF9, 0xDE, 0xBB, 0xD7, 0xF2, 0x45, 0x9C, 0x94
    , 0x32, 0xB2, 0xA4, 0x83, 0x3C, 0xCA, 0x8B, 0xEC, 0xB0, 0xD1, 0xDE, 0x93, 0x35, 0xDF, 0xD0, 0xFC
    , 0xDC, 0x0A, 0x4E, 0x08, 0x31, 0x10, 0x9E, 0x12, 0x4F, 0x78, 0xED, 0x47, 0x8C, 0x94, 0x11, 0x29
    , 0x76, 0x7F, 0x72, 0x50, 0x25, 0xE6, 0xAB, 0x73, 0x6B, 0xCC, 0x26, 0x46, 0xD7, 0xCA, 0x56, 0x48
    , 0x54, 0xCF, 0xD8, 0xE4, 0x93, 0x4A, 0x89, 0xCD, 0x13, 0xCB, 0x95, 0x9B, 0x3F, 0x32, 0x54, 0x18
    , 0xB7, 0x0D, 0xA1, 0x44, 0x97, 0x1D, 0x66, 0x22, 0x4E, 0x91, 0xE2, 0xB0, 0x6C, 0x76, 0x2C, 0x5F
    , 0xA0, 0xDB, 0x00, 0x56, 0x0E, 0x9D, 0x6E, 0xDC, 0x92, 0xA9, 0x79, 0x06, 0x04, 0x2E, 0xC8, 0x3C
    , 0x7D, 0x63, 0xA0, 0x0E, 0xFF, 0x3C, 0x96, 0x9D, 0x36, 0x74, 0x0F, 0x5A, 0xA2, 0xFD, 0x8B, 0xBE
    , 0x50, 0x76, 0xB1, 0x48, 0x77, 0x2B, 0xE1, 0xAE, 0x0E, 0xBB, 0x0F, 0x92, 0x3D, 0xBC, 0xD8, 0x97
    , 0x9D, 0x0B, 0x99, 0x8E, 0x04, 0x9E, 0x0A, 0x85, 0x3A, 0xCA, 0x05, 0xE8, 0xF6, 0xC2, 0x24, 0x70
    , 0xCF, 0x5C, 0xAD, 0x11, 0x19, 0xC6, 0xCA, 0x70, 0xAF, 0x38, 0x1D, 0x2B, 0xD0, 0x27, 0xC4, 0x44
    , 0xE9, 0xB9, 0x9B, 0x41, 0xBA, 0x9E, 0x72, 0x63, 0x67, 0x3D, 0xD5, 0xB4, 0xEC, 0x86, 0xED, 0xF5
    , 0x77, 0xFA, 0xCB, 0xDB, 0xAB, 0xAD, 0xCA, 0x1E, 0x19, 0xFD, 0x03, 0xA2, 0x81, 0x59, 0x26, 0x2B
    , 0xA8, 0x9B, 0x20, 0xAF, 0x66, 0x95, 0xDC, 0x67, 0x11, 0xF8, 0xB5, 0x85, 0x05, 0x26, 0x11, 0x53
    , 0x05, 0x90, 0x71, 0x27, 0xA1, 0x52, 0xAF, 0x0D, 0x00, 0x60, 0xFB, 0x20, 0x85, 0x6D, 0x54, 0xF1
    , 0x99, 0xF7, 0xF8, 0x03, 0x40, 0xE7, 0xF5, 0xE3, 0x2B, 0x4E, 0x18, 0x56, 0x81, 0x2C, 0xD9, 0x34
    , 0x17, 0x5A, 0x61, 0xF2, 0x9F, 0xE2, 0x2C, 0xAA, 0xA6, 0x9F, 0x08, 0xF6, 0xCD, 0xE7, 0x62, 0x7C
    , 0xEC, 0xA6, 0x86, 0x6F, 0x85, 0xBF, 0xAD, 0xB1, 0x7A, 0xBF, 0x0C, 0xC4, 0xBE, 0x13, 0x06, 0x1A
    , 0x0D, 0xE7, 0x55, 0xE7, 0xCF, 0xF1, 0xB1, 0x16, 0xDE, 0x8B, 0xCE, 0x55, 0x69, 0x8E, 0x50, 0x1B
    , 0x34, 0x01, 0x06, 0xA1, 0xD2, 0x5B, 0xE8, 0x8B, 0x37, 0x40, 0x2D, 0x3D, 0x0A, 0x86, 0x28, 0x53
    , 0x19, 0x75, 0xB3, 0x86, 0x10, 0x84, 0x91, 0x7C, 0xC0, 0x91, 0x98, 0x08, 0x18, 0xE8, 0x01, 0x53
    , 0xBD, 0xE2, 0xAD, 0xC5, 0x02, 0xE1, 0xF7, 0x2A, 0x9C, 0xE5, 0x8A, 0xCC, 0x80, 0xBD, 0x26, 0x63
    , 0x02, 0x62, 0xEE, 0x36, 0xD2, 0x47, 0x81, 0xFB, 0x1D, 0x79, 0xD2, 0xDF, 0x53, 0xDA, 0xD0, 0xC7
    , 0x5A, 0xDC, 0xE1, 0x18, 0x80, 0x00, 0x09, 0xE0, 0xAA, 0x85, 0xAE, 0x54, 0xA1, 0xB3, 0x22, 0x96
    , 0x0C, 0x79, 0x4E, 0xA1, 0xD8, 0x95, 0x94, 0xA4, 0xD8, 0x49, 0x55, 0x81, 0x41, 0xA4, 0x86, 0x6D
    , 0x3E, 0x32, 0x3E, 0x50, 0xFD, 0xDD, 0x74, 0x1F, 0x4E, 0xB6, 0xF6, 0x6C, 0x56, 0x1A, 0x8D, 0xCC
    , 0x81, 0xA0, 0xC7, 0x1C, 0x52, 0xF8, 0x50, 0x9C, 0x0D, 0xC4, 0x70, 0xE3, 0x0E, 0xC5, 0x9C, 0xDC
    , 0x3B, 0x92, 0xFA, 0xD1, 0x60, 0x83, 0xD4, 0xE2, 0xB0, 0x84, 0x84, 0xF6, 0xDD, 0xAC, 0x44, 0x4A
    , 0x98, 0xD9, 0x30, 0x95, 0x7A, 0xEF, 0x6B, 0x47, 0x51, 0x0C, 0x44, 0x54, 0x3D, 0x83, 0x26, 0x9A
    , 0x99, 0x19, 0x0A, 0x2C, 0xF9, 0xFE, 0xD7, 0x8F, 0x6C, 0xE9, 0x79, 0xAD, 0x7A, 0x1B, 0x2F, 0x92
    , 0x20, 0xA0, 0xCA, 0x11, 0x61, 0x18, 0x94, 0x4E, 0x4C, 0xD2, 0x05, 0x3D, 0x65, 0x08, 0xDE, 0xF2
    , 0x5D, 0x49, 0x61, 0xDE, 0x13, 0x71, 0x11, 0xCF, 0x89, 0x27, 0xD1, 0xCD, 0x2D, 0xE7, 0x4A, 0x70
    , 0x0F, 0x89, 0x56, 0x08, 0x93, 0xA1, 0x1C, 0x0B, 0xE1, 0x2A, 0xBD, 0xF6, 0x7E, 0xEF, 0x9F, 0xD8
    , 0x19, 0xB1, 0x78, 0x87, 0x88, 0xE8, 0x91, 0xCC, 0xB5, 0x73, 0x8F, 0x48, 0xDC, 0x91, 0xA1, 0xD0
    , 0xEB, 0xCC, 0x36, 0xBA, 0x3D, 0x7E, 0x3F, 0xC2, 0xF7, 0x7F, 0xB1, 0x54, 0x4D, 0xA9, 0x9E, 0xD9
    , 0xC1, 0xB8, 0x61, 0x2D, 0x35, 0x6C, 0x05, 0x12, 0x26, 0xBF, 0x71, 0x90, 0xAF, 0x0D, 0xF2, 0x42
    , 0x95, 0x67, 0x8D, 0x84, 0x95, 0x8D, 0x88, 0x47, 0xF2, 0x9A, 0x80, 0xAF, 0x27, 0x71, 0x7A, 0x14
    , 0x47, 0x41, 0xF8, 0xD9, 0xD2, 0x76, 0x4A, 0x6D, 0x3B, 0x90, 0xF8, 0x95, 0x5E, 0xBC, 0x81, 0x66
    , 0x17, 0x74, 0x03, 0xBD, 0x1B, 0x56, 0x81, 0x8E, 0x58, 0x75, 0x5E, 0x96, 0x3E, 0xCC, 0x97, 0x87
    , 0xD2, 0x84, 0x65, 0x76, 0xC7, 0xE1, 0x0D, 0xCB, 0xF5, 0x25, 0x18, 0xB7, 0xC2, 0x70, 0x03, 0xA0
    , 0xA9, 0xC5, 0x86, 0x79, 0x17, 0x2C, 0xB6, 0x45, 0xC4, 0xF7, 0x3F, 0x08, 0x70, 0xD7, 0x46, 0xDF
    , 0x1A, 0xED, 0xAC, 0xAE, 0x2E, 0xA7, 0x31, 0x9E, 0xD4, 0x56, 0xC0, 0x98, 0x23, 0x95, 0xDA, 0x61
    , 0x28, 0x05, 0x0F, 0xF7, 0xB5, 0x62, 0x44, 0x81, 0x3B, 0x7D, 0xAB, 0x73, 0x83, 0xDB, 0xF1, 0xED
    , 0x3D, 0x26, 0xB1, 0x22, 0x4A, 0x98, 0x08, 0xBB, 0xD2, 0x21, 0x5A, 0x5B, 0x7B, 0xA1, 0xEB, 0xEF
    , 0x47, 0xD9, 0x92, 0x65, 0x45, 0x97, 0xE7, 0xE4, 0x89, 0x02, 0xFD, 0x62, 0x75, 0x08, 0x32, 0x2E
    , 0x45, 0xE9, 0x8B, 0x17, 0xFD, 0x43, 0xC8, 0x6B, 0x5C, 0x12, 0x38, 0x0F, 0x5A, 0x55, 0x84, 0x85
    , 0x42, 0xD4, 0x71, 0xE1, 0xFF, 0xAF, 0x59, 0xC4, 0xED, 0xB2, 0xCD, 0x1A, 0xD9, 0x45, 0x7C, 0x94
    , 0x8A, 0x5B, 0x89, 0x31, 0x25, 0x41, 0xC5, 0x54, 0xE2, 0xE2, 0xCD, 0x99, 0xFF, 0x38, 0x89, 0xDF
    , 0xDD, 0x1B, 0xC1, 0xFC, 0xB8, 0x06, 0x4C, 0xFA, 0x8C, 0xF2, 0xDA, 0xE4, 0x22, 0x73, 0x1A, 0xA3
    , 0x53, 0x1D, 0x97, 0xCF, 0x21, 0x90, 0x42, 0xA4, 0x56, 0x17, 0x07, 0xF3, 0x3F, 0xA3, 0x1F, 0x10
    , 0x8A, 0x28, 0x57, 0x1C, 0x81, 0xC0, 0xEC, 0x2C, 0x7B, 0x1C, 0xFC, 0xE8, 0x13, 0xF1, 0xAB, 0x59
    , 0xA3, 0x6D, 0x0F, 0x65, 0xBD, 0x20, 0x01, 0x23, 0xA1, 0x08, 0x5E, 0x50, 0x37, 0xE0, 0x8B, 0x7D
    , 0x16, 0x26, 0x36, 0xE9, 0x7D, 0xC0, 0x08, 0xA1, 0xDB, 0xBF, 0xB4, 0x85, 0x4B, 0xF8, 0xE8, 0x6A
    , 0x73, 0xBD, 0x9C, 0x16, 0x47, 0xC0, 0x5A, 0x1C, 0x9E, 0xAD, 0x4F, 0xB2, 0x7C, 0x1B, 0x72, 0x12
    , 0xB0, 0xB5, 0x41, 0x5F, 0xAB, 0x93, 0x5B, 0xF5, 0x1A, 0x23, 0xEE, 0x9B, 0x1A, 0x1E, 0x43, 0x39
    , 0xC2, 0xBD, 0x9B, 0xAA, 0xEF, 0xE9, 0x26, 0xA6, 0xFE, 0xC1, 0x24, 0x24, 0xBF, 0xFB, 0xFC, 0x30
    , 0x32, 0x51, 0x30, 0x7C, 0x17, 0x3B, 0xC0, 0x81, 0xA6, 0xB3, 0x38, 0x03, 0xD9, 0x6B, 0x49, 0x43
    , 0xFB, 0x2E, 0x13, 0x99, 0x47, 0x19, 0xD8, 0x89, 0x59, 0xEB, 0x00, 0x44, 0x04, 0xA4, 0xC3, 0xA5
    , 0x34, 0x00, 0x6B, 0x7F, 0x91, 0x09, 0xB8, 0x2C, 0xCE, 0x09, 0xF0, 0xE1, 0x5A, 0x3F, 0x3A, 0xE2
    , 0x61, 0xE3, 0x67, 0x36, 0x80, 0xB5, 0x47, 0x35, 0x8E, 0x27, 0x1E, 0x71, 0x5E, 0xE9, 0x59, 0xE6
    , 0x6B, 0x4A, 0x88, 0xDA, 0x1B, 0x2F, 0x4B, 0x2C, 0x31, 0xEA, 0x5D, 0x58, 0x08, 0x87, 0x67, 0x3F
    , 0x59, 0x12, 0x0C, 0x39, 0xD3, 0x84, 0x5F, 0x3B, 0xB5, 0x29, 0x95, 0xC6, 0x58, 0xD7, 0xEA, 0x36
    , 0x0B, 0x0F, 0x31, 0x9B, 0xDE, 0xB6, 0xDD, 0xFE, 0x40, 0x4A, 0x90, 0x07, 0x6B, 0xC5, 0x7B, 0xF5
    , 0xA9, 0xDA, 0x7A, 0x5C, 0x15, 0x70, 0xA1, 0xBF, 0x56, 0x5D, 0x16, 0x69, 0x7E, 0x82, 0x60, 0xD6
    , 0xB9, 0xF8, 0x67, 0x03, 0x37, 0x4E, 0xB7, 0xD1, 0x8D, 0x7D, 0x27, 0x8F, 0xFE, 0x53, 0xC6, 0x03
    , 0x0E, 0xBE, 0x8D, 0x13, 0x08, 0xBE, 0x5A, 0xBD, 0x74, 0x67, 0xB6, 0xF8, 0x59, 0x02, 0xA6, 0x29
    , 0x6A, 0x51, 0x65, 0xA0, 0xE1, 0x7B, 0xDC, 0x87, 0x19, 0x3C, 0x85, 0x44, 0xB9, 0xAD, 0x36, 0xD0
    , 0xFC, 0xDC, 0x30, 0x26, 0xF9, 0x8C, 0x79, 0xCC, 0x2D, 0xC2, 0x73, 0x53, 0x0C, 0x54, 0x07, 0xF1
    , 0x6F, 0xAA, 0x9E, 0x80, 0x30, 0x79, 0xC1, 0xDF, 0xEF, 0x12, 0x29, 0x83, 0xAB, 0xCF, 0x9E, 0x7A
    , 0x95, 0x16, 0xDA, 0xCF, 0xBA, 0x31, 0x0D, 0xF1, 0xF5, 0x58, 0xA7, 0x49, 0x43, 0x73, 0x9E, 0x24
    , 0xAC, 0xF8, 0x85, 0x10, 0xD1, 0x7D, 0x7F, 0x1A, 0x41, 0x06, 0x75, 0xE0, 0xF5, 0x10, 0x84, 0x39
    , 0x2C, 0x1E, 0xB1, 0xDA, 0x15, 0x29, 0x66, 0x5F, 0x55, 0x7C, 0x5E, 0xF5, 0x14, 0xAF, 0x9D, 0x55
    , 0x50, 0x94, 0xB7, 0x11, 0xAD, 0xC6, 0x7D, 0x79, 0xFF, 0x12, 0xD5, 0x19, 0x8A, 0x54, 0x00, 0x19
    , 0x69, 0xAF, 0xD1, 0x76, 0xE9, 0x85, 0x8B, 0x24, 0xB0, 0xF7, 0x31, 0x1B, 0xEF, 0xC2, 0xD3, 0xA5
    , 0x7F, 0xC7, 0xC5, 0x76, 0x84, 0x8B, 0x54, 0xA4, 0x93, 0x98, 0x86, 0xB3, 0x26, 0x1C, 0x76, 0xD4
    , 0x8B, 0xDE, 0x2A, 0x49, 0xF1, 0xE2, 0x21, 0xC8, 0x8A, 0xE8, 0xB2, 0x3A, 0xE7, 0x67, 0x5E, 0x63
    , 0x26, 0x27, 0xF4, 0x03, 0x8C, 0xFC, 0xFE, 0x9C, 0x13, 0xF9, 0x51, 0x9C, 0xED, 0xDA, 0x19, 0x08
    , 0x6A, 0x14, 0x3A, 0xF0, 0x25, 0x92, 0xDF, 0x7E, 0x7A, 0xDC, 0x9E, 0x06, 0x7A, 0x1F, 0xCA, 0x5B
    , 0x4D, 0xB1, 0x57, 0x3A, 0x2E, 0x13, 0xB8, 0xD0, 0x42, 0x1E, 0xC9, 0xE2, 0xF4, 0x4C, 0x84, 0x4F
    , 0x5C, 0x04, 0xE4, 0xC6, 0xC2, 0x01, 0x99, 0x24, 0xA9, 0x53, 0xC3, 0x21, 0x24, 0x3C, 0x32, 0x0C
    , 0x64, 0xA3, 0x65, 0xD5, 0xB9, 0x76, 0x0C, 0x0A, 0x96, 0x09, 0x5F, 0x57, 0x3E, 0x68, 0xBB, 0x8B
    , 0x88, 0x34, 0xA7, 0xEE, 0xCC, 0x32, 0xEE, 0x63, 0x40, 0x77, 0x68, 0x6D, 0x0C, 0x6A, 0x9E, 0x1E
    , 0x9A, 0x57, 0x77, 0x66, 0xCB, 0x63, 0x45, 0x99, 0xD6, 0x4E, 0x90, 0xF9, 0x14, 0xA8, 0xAE, 0x41
    , 0xA3, 0x8C, 0x5E, 0xE2, 0xA0, 0x85, 0x25, 0xFF, 0x33, 0x7B, 0x6F, 0x1E, 0xAF, 0xAD, 0xE3, 0x37
    , 0xBE, 0x76, 0xD3, 0x82, 0x19, 0x39, 0x4A, 0x7F, 0xF7, 0x58, 0xFC, 0xF5, 0x07, 0xE9, 0x08, 0x90
    , 0xB9, 0x92, 0x55, 0x35, 0xD9, 0xC7, 0x8A, 0x1A, 0x38, 0x8A, 0xB5, 0xD5, 0xE5, 0x54, 0x84, 0x08
    , 0x53, 0x93, 0xBB, 0x15, 0x9B, 0x55, 0x9F, 0x53, 0x11, 0x3B, 0xC1, 0xA7, 0xC3, 0x1B, 0x87, 0xD3
    , 0x7B, 0xB7, 0x5E, 0x54, 0xC5, 0x00, 0xFB, 0x32, 0x95, 0x91, 0x6D, 0x32, 0x1C, 0xB3, 0x94, 0xB5
    , 0x0D, 0x8F, 0xA2, 0x84, 0x4F, 0x77, 0xF6, 0x0F, 0x57, 0x12, 0x8F, 0x51, 0xB2, 0x05, 0xC6, 0x86
    , 0x4B, 0x0E, 0x55, 0xCC, 0x39, 0xC1, 0x56, 0xF7, 0xB8, 0x90, 0xF5, 0x21, 0x45, 0x58, 0x5A, 0x3E
    , 0xE1, 0xAF, 0x85, 0xC6, 0x2E, 0x4B, 0x9D, 0x01, 0xF4, 0x76, 0x99, 0xD5, 0x5F, 0x83, 0x38, 0x2B
    , 0x6F, 0x44, 0xDE, 0x7D, 0x61, 0xF8, 0x70, 0x32, 0xE9, 0x6C, 0xC0, 0xBD, 0xA9, 0xC0, 0xA8, 0x5A
    , 0x1B, 0xE2, 0xA5, 0xF0, 0xF9, 0x25, 0xA3, 0x5C, 0x7E, 0xEC, 0x78, 0xFE, 0x67, 0x14, 0x31, 0x4F
    , 0x42, 0xFB, 0x61, 0x8B, 0x0C, 0x7A, 0xB4, 0xED, 0x65, 0x34, 0xE4, 0x2C, 0x01, 0x81, 0x46, 0xEF
    , 0x6D, 0xE0, 0x49, 0x25, 0xAA, 0x6F, 0xD1, 0x8E, 0x82, 0xC7, 0x9B, 0xEB, 0xEB, 0x54, 0x25, 0x7E
    , 0x4F, 0x5E, 0xE3, 0x11, 0x7C, 0xF7, 0x72, 0x18, 0x99, 0xD7, 0xCE, 0x83, 0x99, 0x24, 0x1D, 0x19
    , 0x8B, 0xCE, 0xAD, 0x44, 0xDE, 0xCE, 0x34, 0x65, 0xA1, 0x5D, 0x1F, 0x0F, 0x3E, 0x50, 0x3E, 0x9B
    , 0x8A, 0x82, 0xD2, 0x00, 0xC8, 0x84, 0x62, 0x9A, 0x66, 0xB1, 0x62, 0xCD, 0x01, 0x7A, 0x3B, 0xC6
    , 0xB2, 0x82, 0x3E, 0x93, 0xDF, 0xB4, 0xC0, 0x13, 0xAC, 0x7D, 0x6D, 0x57, 0xFB, 0x40, 0xD2, 0xD8
    , 0xCD, 0xE0, 0x88, 0x34, 0xF6, 0xC8, 0x4C, 0xE8, 0xA5, 0x0C, 0xA3, 0x1A, 0x5F, 0x61, 0x18, 0x72
    , 0x48, 0x17, 0xCD, 0x7A, 0x5E, 0xD8, 0x77, 0x58, 0x43, 0x92, 0x1E, 0x9F, 0xD4, 0x57, 0x74, 0x89
    , 0xF6, 0xDD, 0x5E, 0x7B, 0xFD, 0xA5, 0xE3, 0xC2, 0x3D, 0x53, 0xBF, 0x86, 0x75, 0x24, 0x32, 0x1A
    , 0x74, 0xF7, 0xEB, 0x3B, 0xC8, 0x6E, 0x77, 0xA6, 0x93, 0x61, 0xD4, 0x95, 0x81, 0xDC, 0x2A, 0xAC
    , 0xD5, 0x90, 0x9F, 0xBA, 0x64, 0x62, 0xBD, 0x70, 0x54, 0x3F, 0x87, 0xA8, 0xB2, 0x6C, 0x1F, 0xF0
    , 0x81, 0x43, 0x47, 0x17, 0x90, 0x4E, 0xE6, 0x73, 0x24, 0x86, 0x6A, 0x5B, 0xC0, 0xF6, 0xDF, 0x28
    , 0xF5, 0x25, 0x40, 0xF8, 0xB2, 0x2E, 0x96, 0xBF, 0xAA, 0xAA, 0xB1, 0x6D, 0xF6, 0xFC, 0xC9, 0x0E
    , 0xDF, 0x8D, 0x89, 0xF8, 0xD1, 0x4B, 0xAE, 0x01, 0xAF, 0x15, 0xCE, 0xC2, 0x50, 0x60, 0x37, 0x16
    , 0xE1, 0x35, 0xA2, 0xD4, 0xB8, 0xD6, 0x3B, 0x0F, 0xEF, 0x9C, 0x9B, 0xA0, 0x0D, 0xCE, 0x1E, 0xE7
    , 0x6C, 0x16, 0x85, 0xB0, 0xC9, 0xB5, 0xBB, 0x27, 0xB3, 0x14, 0x53, 0x93, 0x2F, 0x65, 0xE9, 0x24
    , 0xDA, 0x7B, 0x34, 0x09, 0x50, 0x88, 0x1A, 0xDF, 0x50, 0xBB, 0x1B, 0x35, 0xB4, 0xA5, 0x30, 0x20
    , 0x74, 0x31, 0x52, 0xA2, 0x1D, 0x59, 0x78, 0xBD, 0x1B, 0x0C, 0xB1, 0x29, 0xE6, 0xE3, 0x31, 0x3C
    , 0xF8, 0x22, 0xBE, 0xBF, 0x57, 0xE0, 0x02, 0xA8, 0xAC, 0xE6, 0x7D, 0x46, 0x6C, 0x96, 0x04, 0x97
    , 0x53, 0x68, 0x46, 0x2B, 0xD8, 0xE0, 0x04, 0xA4, 0xA9, 0x78, 0xCF, 0xB7, 0x77, 0xB5, 0xD6, 0x6E
    , 0x68, 0xDF, 0x7E, 0x3A, 0x68, 0x79, 0x0A, 0x13, 0x2E, 0x09, 0x89, 0xCB, 0x90, 0xC4, 0x1B, 0x4A
    , 0x0F, 0x89, 0x9E, 0xD8, 0xC9, 0xE5, 0xF3, 0x2C, 0x16, 0x27, 0xE3, 0xE2, 0xA5, 0xC4, 0x23, 0x86
    , 0x83, 0x65, 0x79, 0x1A, 0x06, 0x12, 0x3E, 0x84, 0x44, 0x42, 0x83, 0xA5, 0x14, 0x67, 0x47, 0x0B
    , 0x60, 0x34, 0x8D, 0x54, 0x75, 0x6B, 0xE9, 0xDD, 0x58, 0xEB, 0x09, 0x8C, 0x07, 0x80, 0x26, 0x52
    , 0x02, 0x43, 0xC8, 0x6B, 0x9E, 0xDF, 0xE4, 0x8B, 0xE1, 0xBF, 0x47, 0x1C, 0xCE, 0x27, 0x96, 0xAC
    , 0x90, 0xB8, 0x29, 0xC6, 0x34, 0x18, 0x67, 0x8C, 0x05, 0xEC, 0xBE, 0x04, 0x6E, 0x85, 0xE9, 0x04
    , 0x0C, 0x31, 0xB8, 0xD9, 0x09, 0x15, 0xAF, 0xAE, 0x0D, 0x6B, 0x96, 0x49, 0x88, 0x2C, 0x5F, 0xAD
    , 0x73, 0xA4, 0x6A, 0xAF, 0x22, 0xF7, 0xF3, 0xC5, 0x80, 0x38, 0xEE, 0x4D, 0xB8, 0x28, 0xA1, 0x20
    , 0x8D, 0xB8, 0x5B, 0x0A, 0x0D, 0xF5, 0x0A, 0x8C, 0xBE, 0x25, 0x80, 0xB2, 0x9F, 0xD3, 0x27, 0x85
    , 0x57, 0x75, 0x39, 0x2F, 0xC5, 0x04, 0x31, 0x96, 0x67, 0xFC, 0x9C, 0x00, 0xB9, 0xCC, 0x74, 0x51
    , 0x2B, 0x2E, 0x1E, 0x85, 0xF3, 0x5C, 0x7C, 0x8E, 0xA3, 0x5F, 0x26, 0xA3, 0xC3, 0xCC, 0x09, 0x04
    , 0xA1, 0xD0, 0x51, 0x2F, 0x96, 0x53, 0xB1, 0x50, 0xD8, 0x7F, 0x7E, 0x10, 0x0F, 0x75, 0xA0, 0x54
    , 0xF2, 0xC5, 0x99, 0xEA, 0x20, 0x87, 0x91, 0x0F, 0x60, 0x35, 0x88, 0xFE, 0xDF, 0xC1, 0xF1, 0xB1
    , 0x76, 0x5F, 0x1A, 0xAE, 0xCE, 0x8A, 0x69, 0xE0, 0x1F, 0xA5, 0x37, 0x1D, 0xC5, 0x30, 0x0E, 0xFB
    , 0x13, 0xC6, 0xC0, 0xDE, 0xD6, 0x92, 0xDF, 0x5B, 0x2E, 0x07, 0x42, 0xBE, 0xC9, 0x42, 0x76, 0x4D
    , 0xC4, 0x98, 0xB4, 0x21, 0x9D, 0x14, 0x73, 0xF3, 0x44, 0x80, 0x83, 0x67, 0x6D, 0x42, 0x21, 0xD5
    , 0x7E, 0xF1, 0xAC, 0x68, 0x4B, 0xF3, 0x5B, 0x0E, 0xCD, 0xBC, 0x40, 0xC5, 0xDD, 0x1F, 0xA6, 0x10
    , 0x2C, 0x4B, 0xC1, 0xA5, 0xFA, 0xAC, 0xCA, 0xED, 0xD2, 0x6B, 0xEA, 0x44, 0xAA, 0xFF, 0x91, 0x7F
    , 0x36, 0xDE, 0x4D, 0xA5, 0x0D, 0x16, 0x40, 0x4D, 0x29, 0xE6, 0xDD, 0xA6, 0x06, 0x37, 0xB6, 0x81
    , 0x09, 0x34, 0x05, 0xF1, 0x5C, 0x8B, 0x8B, 0x45, 0x5F, 0xC1, 0xA0, 0xF7, 0x48, 0x35, 0x27, 0x64
    , 0x2D, 0xC5, 0x58, 0x8B, 0xE1, 0xE3, 0x0C, 0x43, 0x65, 0x5E, 0x74, 0xF6, 0x34, 0x4F, 0xE2, 0x7D
    , 0x13, 0x30, 0x99, 0x67, 0xA3, 0x24, 0xE3, 0xA9, 0xAD, 0x5D, 0x89, 0xCA, 0xA6, 0x32, 0xCF, 0xF4
    , 0xAB, 0xC3, 0x36, 0xA5, 0x8E, 0xAE, 0xD6, 0x0D, 0x93, 0xFF, 0x22, 0xCD, 0x8F, 0xCA, 0xE6, 0x4E
    , 0xC8, 0xCC, 0x0C, 0xEC, 0x5B, 0x49, 0x41, 0xA0, 0xFE, 0x74, 0xC9, 0x2F, 0x27, 0xE6, 0x0B, 0x9E
    , 0xDB, 0xA6, 0x14, 0x44, 0x82, 0x97, 0x1D, 0xAA, 0xC3, 0x44, 0xC1, 0x1A, 0x16, 0xB4, 0xD9, 0xD4
    , 0x93, 0x00, 0xF1, 0x83, 0x46, 0x07, 0xAA, 0xD3, 0x0D, 0x9E, 0x01, 0xD2, 0xE2, 0x2B, 0xB7, 0x1E
    , 0xCC, 0x91, 0xDF, 0xF0, 0x41, 0x67, 0x82, 0x38, 0x05, 0x37, 0xC1, 0xE6, 0x15, 0xFA, 0x9E, 0x07
    , 0x66, 0x6A, 0x18, 0x37, 0x53, 0x16, 0xA3, 0x5C, 0xC3, 0x2C, 0x35, 0xDC, 0x57, 0xF4, 0xEB, 0xC8
    , 0x7F, 0xC8, 0xEB, 0x3F, 0x77, 0x13, 0xB3, 0x3F, 0x7A, 0x7A, 0x79, 0x65, 0x73, 0xA5, 0xA3, 0x72
    , 0xA4, 0x4B, 0x3C, 0x04, 0x05, 0x24, 0x5B, 0xDC, 0x0D, 0x5F, 0x91, 0xAE, 0xA6, 0xA5, 0x6E, 0x15
    , 0x06, 0x29, 0xD7, 0x28, 0x42, 0x42, 0xCA, 0xAC, 0xA0, 0x79, 0xF6, 0x68, 0x2B, 0xD2, 0x5E, 0xF9
    , 0x36, 0x1C, 0x65, 0xD6, 0x75, 0x78, 0xB9, 0xC2, 0x9C, 0xDF, 0x0A, 0xD0, 0xD1, 0x55, 0xA0, 0xA2
    , 0x74, 0xE0, 0x45, 0x0D, 0x66, 0x8C, 0x2B, 0xF3, 0x9B, 0x78, 0xD8, 0xCF, 0x48, 0xDC, 0x1C, 0x1F
    , 0x9A, 0xD8, 0xD8, 0xD9, 0xC4, 0x03, 0xE8, 0x15, 0x6E, 0x85, 0xB7, 0x4A, 0x6A, 0x73, 0xB3, 0xAF
    , 0x86, 0x0C, 0xD0, 0x5F, 0x06, 0xDE, 0x07, 0xF9, 0x95, 0x2A, 0x40, 0x7A, 0x5A, 0x96, 0x9F, 0x9B
    , 0xFA, 0x0F, 0xAD, 0x71, 0x52, 0x56, 0x89, 0xC0, 0x90, 0xA7, 0x3E, 0x1C, 0xA1, 0x61, 0x63, 0xE9
    , 0x99, 0x98, 0x63, 0x80, 0xF0, 0x7B, 0xD7, 0xDB, 0xEF, 0xC4, 0x62, 0x05, 0x43, 0xF5, 0xDF, 0xEF
    , 0xD0, 0xD3, 0x7D, 0x28, 0x02, 0xB9, 0x26, 0xB0, 0xA0, 0x90, 0xF8, 0x80, 0x98, 0xD6, 0xFA, 0xD4
    , 0x89, 0x79, 0xF2, 0x01, 0x90, 0x0B, 0xB8, 0x56, 0x44, 0xE7, 0x20, 0x5C, 0x70, 0x7C, 0x34, 0xF2
    , 0xD0, 0x7C, 0xF7, 0x00, 0xD6, 0x3C, 0x46, 0x5F, 0xBE, 0xF3, 0xC9, 0x5D, 0x5F, 0x6A, 0xB3, 0x6D
    , 0xC4, 0x90, 0x49, 0x5E, 0xF0, 0xD6, 0x04, 0x99, 0xDC, 0x76, 0xC8, 0xEE, 0x7F, 0x63, 0x26, 0x3F
    , 0x98, 0xE1, 0xFB, 0x5C, 0x76, 0x14, 0x20, 0x0E, 0x6D, 0xE5, 0xF7, 0xD5, 0x8C, 0x72, 0x9D, 0x9B
    , 0xF9, 0xEA, 0xD6, 0x0C, 0x1F, 0xD5, 0x31, 0x22, 0xDC, 0x9A, 0xA3, 0x56, 0x5B, 0xD6, 0xFD, 0x11
    , 0xB7, 0x7E, 0x13, 0x74, 0xAF, 0xAC, 0x28, 0xAA, 0x3F, 0xDF, 0x5F, 0x35, 0x02, 0xD3, 0x4F, 0x7B
    , 0x50, 0xB5, 0x80, 0xD8, 0x4E, 0xD9, 0x8D, 0x63, 0x1B, 0x69, 0xCF, 0x2E, 0xB2, 0xC5, 0x9D, 0x07
    , 0xBA, 0x65, 0xB9, 0x1E, 0x56, 0xAC, 0x5F, 0x56, 0x54, 0x1A, 0x4B, 0x47, 0xD0, 0xE3, 0x99, 0xA7
    , 0x7C, 0x29, 0x81, 0x11, 0x8D, 0xE1, 0xBC, 0x4D, 0x0F, 0x7F, 0x37, 0xFA, 0x69, 0x5B, 0x03, 0x47
    , 0x53, 0x1C, 0x2A, 0x8A, 0x6B, 0xA8, 0xF0, 0xCB, 0xDF, 0x3A, 0x8E, 0x72, 0x05, 0xBF, 0x60, 0x24
    , 0x0E, 0xFF, 0xF6, 0x90, 0xA0, 0xDC, 0xF1, 0x17, 0x20, 0xF2, 0x98, 0xF0, 0xA5, 0xDC, 0x50, 0x13
    , 0xD8, 0x5C, 0x7A, 0x2D, 0xC2, 0xC1, 0xFF, 0xF2, 0x11, 0x10, 0x09, 0xAB, 0xF3, 0xF0, 0xC3, 0x5C
    , 0x0A, 0x0B, 0xC8, 0x32, 0x19, 0x34, 0x93, 0xE4, 0x21, 0x57, 0x78, 0x32, 0xED, 0x51, 0x0A, 0xAC
    , 0x33, 0x02, 0x97, 0x83, 0xD7, 0x7B, 0x26, 0xD9, 0xB7, 0xBC, 0xCA, 0xCE, 0xE3, 0x0F, 0x38, 0xD5
    , 0xE2, 0x26, 0x4F, 0xAC, 0x0D, 0x77, 0x25, 0xF7, 0x68, 0x31, 0x70, 0x41, 0xE6, 0xCA, 0x1D, 0xDC
    , 0x9D, 0xD8, 0x83, 0x22, 0xFF, 0xB9, 0xC9, 0x27, 0xEB, 0xC6, 0x82, 0x6D, 0xFC, 0x45, 0x3D, 0x5C
    , 0x6D, 0x6B, 0x99, 0x9B, 0x46, 0x16, 0x96, 0x72, 0x5C, 0x2C, 0x5C, 0x24, 0x2D, 0xEC, 0xB5, 0x86
    , 0x29, 0x8A, 0x3A, 0x94, 0x69, 0x28, 0xD5, 0x5C, 0x0C, 0x0C, 0x20, 0x0D, 0x65, 0x02, 0x6E, 0x0F
    , 0xEF, 0xBA, 0x64, 0x88, 0x5C, 0x32, 0x9F, 0x45, 0xA3, 0xB1, 0x39, 0xB5, 0x72, 0x42, 0x94, 0x62
    , 0x72, 0xF0, 0x34, 0xDC, 0x37, 0xD9, 0x28, 0xEE, 0xE5, 0xB2, 0xF7, 0xA8, 0xEE, 0x22, 0x46, 0xD0
    , 0x59, 0x24, 0x4A, 0x97, 0x98, 0x00, 0x6D, 0x83, 0xC3, 0xE2, 0x38, 0x4E, 0x04, 0x4B, 0x08, 0x67
    , 0x06, 0xFB, 0xD3, 0xE0, 0x5A, 0xFB, 0x8A, 0xC8, 0x72, 0xB3, 0xE4, 0xBB, 0x7C, 0x59, 0xA0, 0x66
    , 0x9B, 0xB7, 0x0F, 0x16, 0xE3, 0xFC, 0xFC, 0x55, 0xDC, 0xE3, 0x98, 0x10, 0x66, 0xC3, 0x9B, 0x55
    , 0xBA, 0xA1, 0xC4, 0x00, 0x58, 0x30, 0xDD, 0x96, 0x48, 0x82, 0x58, 0xED, 0x56, 0x77, 0xE3, 0xFA
    , 0xF1, 0x3D, 0x09, 0xB7, 0x1A, 0x8F, 0xF2, 0xA2, 0x05, 0x2D, 0x1C, 0xAB, 0xA6, 0xE1, 0x5F, 0x44
    , 0xD8, 0x4A, 0x56, 0x16, 0xD4, 0xE7, 0x42, 0x35, 0x6F, 0x62, 0x09, 0xA9, 0x63, 0x99, 0xD9, 0x62
    , 0xE6, 0x65, 0x3F, 0xFA, 0xAF, 0x61, 0x83, 0x5C, 0x52, 0x5F, 0x51, 0x57, 0x82, 0x1B, 0xC9, 0xB0
    , 0xE1, 0x3C, 0x06, 0x90, 0xEE, 0xF8, 0x17, 0x85, 0x73, 0xC4, 0x6E, 0x9C, 0xA6, 0x23, 0x27, 0x43
    , 0x1B, 0x25, 0xC7, 0x6E, 0xD0, 0x6D, 0x68, 0x82, 0x92, 0x03, 0xA2, 0xEF, 0x3D, 0x6B, 0x50, 0x5A
    , 0x3A, 0x1D, 0xD3, 0x0F, 0x1C, 0x82, 0x92, 0x8B, 0x6A, 0x30, 0xD4, 0xF7, 0x8C, 0x7C, 0xE1, 0x3E
    , 0x83, 0xE3, 0xAB, 0x60, 0xB2, 0x5D, 0x06, 0xDA, 0x75, 0xB8, 0x0C, 0x31, 0x52, 0x6E, 0xD3, 0x0A
    , 0xFD, 0x08, 0x4D, 0x2C, 0x87, 0x4E, 0x1D, 0x5E, 0x5B, 0x46, 0x8A, 0xDA, 0x29, 0x0D, 0xD8, 0xE6
    , 0x75, 0x75, 0xF4, 0xA0, 0x79, 0xDC, 0xB9, 0xF8, 0xCE, 0xB0, 0x61, 0xF9, 0x45, 0x45, 0xE4, 0xFD
    , 0x56, 0x3F, 0xF7, 0x2E, 0xA7, 0xC6, 0x69, 0x12, 0xBB, 0xAF, 0x0A, 0x2A, 0x44, 0xEE, 0x5E, 0x9A
    , 0x65, 0x80, 0x4E, 0x68, 0x98, 0x54, 0xEB, 0x8B, 0x81, 0x3F, 0x41, 0x94, 0x13, 0x6B, 0x0F, 0x35
    , 0x13, 0x60, 0x0F, 0x6D, 0x7D, 0xB9, 0x40, 0x2E, 0xC4, 0x0C, 0xBD, 0x89, 0x8F, 0xB5, 0x23, 0xBB
    , 0x19, 0x63, 0x5F, 0x37, 0xB5, 0x70, 0xFE, 0x54, 0x8A, 0x73, 0x7E, 0x67, 0x50, 0x58, 0x81, 0x08
    , 0x5F, 0x13, 0xA7, 0x12, 0xC3, 0x60, 0x2A, 0x7E, 0x8E, 0x3B, 0x32, 0x21, 0xEF, 0xA8, 0xE0, 0xDE
    , 0xDA, 0x62, 0x73, 0x7F, 0xAE, 0xE5, 0xC4, 0x46, 0x9C, 0x54, 0x73, 0x15, 0x28, 0xD4, 0x14, 0x4A
    , 0x7B, 0x1B, 0xE3, 0xEB, 0x18, 0x65, 0xE8, 0x9C, 0x36, 0xFA, 0xA8, 0x97, 0xB2, 0x36, 0xB5, 0xDD
    , 0x49, 0x56, 0x4D, 0x81, 0x4A, 0x81, 0x32, 0x25, 0x50, 0xA4, 0x36, 0xE0, 0x36, 0x1C, 0x55, 0xE4
    , 0x8F, 0x03, 0x7F, 0x61, 0xD9, 0xDE, 0x64, 0x7E, 0xE4, 0x2E, 0xF2, 0xF3, 0xFC, 0x66, 0x4E, 0x30
    , 0x06, 0x9F, 0x4B, 0x9E, 0x0B, 0xE2, 0xBA, 0x93, 0xFD, 0x0F, 0xDD, 0xCE, 0xC9, 0x93, 0xE9, 0x3D
    , 0x17, 0x3F, 0xB7, 0x45, 0x51, 0x3F, 0x0A, 0x12, 0x30, 0xFE, 0xB4, 0xF3, 0x59, 0x8D, 0x67, 0x3B
    , 0x1B, 0x76, 0x6C, 0x08, 0x3C, 0x04, 0xC6, 0xCE, 0x48, 0x9C, 0x73, 0x5B, 0x80, 0xAA, 0x01, 0xB6
    , 0x45, 0x16, 0xDF, 0x8A, 0x39, 0x5A, 0xF1, 0x98, 0xE4, 0xD4, 0xC5, 0x9C, 0x59, 0xC3, 0xDC, 0x4C
    , 0x24, 0xC8, 0xFF, 0x1C, 0x63, 0x00, 0xBC, 0x7B, 0xC5, 0x4D, 0xA3, 0x11, 0xB7, 0x04, 0x49, 0xF7
    , 0x34, 0x68, 0x4D, 0xAF, 0x84, 0xDF, 0xCF, 0xDB, 0xCC, 0x79, 0xF7, 0x72, 0x35, 0xBA, 0x57, 0x78
    , 0x83, 0xBE, 0x82, 0x37, 0x3B, 0xC2, 0x6A, 0xE4, 0x3D, 0xFA, 0x6D, 0x21, 0xC7, 0x8C, 0x61, 0x7C
    , 0x9A, 0x69, 0xD6, 0x6C, 0xEA, 0x34, 0x36, 0x37, 0x1F, 0x1F, 0xE3, 0x3F, 0xD0, 0x34, 0xFE, 0x20
    , 0x87, 0xFD, 0xD1, 0x0A, 0x01, 0x1D, 0xB2, 0x27, 0x3E, 0x7B, 0x1C, 0x5B, 0xAE, 0x28, 0x18, 0x99
    , 0xB9, 0x94, 0x8E, 0xF7, 0xD7, 0x6A, 0x53, 0x5E, 0x15, 0xB9, 0x48, 0xA0, 0x0E, 0xAF, 0xEB, 0xAE
    , 0xEE, 0xBE, 0xE4, 0x55, 0x3A, 0x6C, 0xD9, 0xB9, 0xB8, 0x4D, 0xD0, 0x0E, 0x40, 0x45, 0x22, 0x7D
    , 0x24, 0xDB, 0x32, 0xEB, 0x77, 0xC7, 0x21, 0x1D, 0x6C, 0xDF, 0xEF, 0xEA, 0x0F, 0xD9, 0x2C, 0x7A
    , 0xA4, 0xA0, 0x2C, 0x8F, 0x03, 0x33, 0xE8, 0xB3, 0x6F, 0xF2, 0xC3, 0xA3, 0xC6, 0x08, 0x29, 0x38
    , 0xFA, 0x30, 0x35, 0xA1, 0x38, 0x39, 0x1F, 0xE3, 0xB9, 0xA1, 0x58, 0x12, 0x91, 0x18, 0x4A, 0x1C
    , 0xCC, 0x3D, 0xEA, 0xE6, 0xAA, 0x42, 0x5B, 0x28, 0x17, 0x15, 0xCE, 0x66, 0x09, 0xCA, 0x3F, 0x40
    , 0x86, 0x2E, 0x6F, 0x95, 0xA9, 0x62, 0xCB, 0x8B, 0x81, 0xBC, 0x57, 0x59, 0xF5, 0xA7, 0x13, 0x30
    , 0xF9, 0x5A, 0xF0, 0xA8, 0xEB, 0xFA, 0x90, 0x8D, 0x84, 0x15, 0xD7, 0xE2, 0x8C, 0xEB, 0x05, 0xFB
    , 0xF8, 0xCE, 0x59, 0xFE, 0x1F, 0x1D, 0x19, 0x04, 0x2B, 0x72, 0xEB, 0x24, 0x45, 0x50, 0x5D, 0x56
    , 0xCC, 0x97, 0xB4, 0x75, 0x2D, 0x31, 0x1F, 0xF4, 0x30, 0x7B, 0xF7, 0x27, 0x4A, 0x97, 0x65, 0x2D
    , 0xE6, 0xDE, 0xDB, 0xEE, 0x7A, 0x0E, 0x2B, 0x26, 0xD1, 0xEE, 0x0F, 0x61, 0x81, 0xAA, 0x10, 0x71
    , 0x72, 0xC0, 0xF4, 0xF5, 0x60, 0x81, 0xC2, 0xDE, 0x4D, 0xA8, 0xC7, 0x33, 0xEC, 0x6D, 0xE7, 0xC7
    , 0x6E, 0x46, 0xAD, 0x9C, 0x6B, 0x6F, 0x20, 0x1E, 0xE0, 0x77, 0x1F, 0x71, 0x94, 0x7A, 0x15, 0x05
    , 0xF0, 0xD7, 0xF0, 0x33, 0x70, 0x97, 0x0D, 0xB4, 0xB6, 0xD3, 0xBC, 0xA4, 0x50, 0x7A, 0x3C, 0x49
    , 0xE2, 0xE8, 0x0F, 0x3E, 0x21, 0xB7, 0x17, 0x95, 0x9E, 0x31, 0x62, 0xB2, 0x49, 0xE8, 0x4F, 0x1E
    , 0x86, 0xD4, 0xF9, 0xD5, 0x22, 0x89, 0x5B, 0x67, 0xE6, 0xDA, 0xFC, 0xA3, 0x3C, 0xFE, 0x5E, 0x8E
    , 0xF9, 0x4D, 0xF5, 0x24, 0x3C, 0x56, 0xE5, 0x26, 0xFD, 0x3D, 0xA1, 0xAA, 0x86, 0x99, 0x54, 0x87
    , 0x12, 0x85, 0x4D, 0x89, 0x64, 0x67, 0xD6, 0xCB, 0x8D, 0x40, 0xB7, 0xBA, 0x4A, 0x60, 0x8A, 0xE4
    , 0xCC, 0x01, 0x04, 0x11, 0xE2, 0x38, 0x9F, 0x7F, 0xD1, 0xB5, 0x82, 0xCF, 0xD8, 0x50, 0x02, 0xF6
    , 0x42, 0x2D, 0x63, 0x1B, 0x0D, 0x1A, 0xF9, 0xE5, 0x2A, 0x54, 0xCC, 0x7E, 0xDE, 0x43, 0x7B, 0xC9
    , 0xF0, 0xF5, 0xBD, 0x64, 0xA2, 0x79, 0x55, 0x90, 0x8E, 0x19, 0x44, 0xE9, 0x85, 0x18, 0x6C, 0x58
    , 0x9D, 0xA5, 0xCE, 0xF1, 0x38, 0xF0, 0xDD, 0x87, 0x4E, 0x72, 0xF0, 0x17, 0x09, 0xAC, 0xF6, 0x1B
    , 0xD0, 0x8B, 0x1B, 0x78, 0xBF, 0x63, 0xA4, 0x33, 0xF9, 0x44, 0x5D, 0xD9, 0x97, 0x28, 0x06, 0x5B
    , 0x4A, 0x26, 0xEB, 0xC0, 0x97, 0x1C, 0x67, 0x10, 0x65, 0x47, 0x7D, 0x52, 0x50, 0xE5, 0x55, 0x0F
    , 0x68, 0xC6, 0x93, 0x37, 0x44, 0xB1, 0xB3, 0x4A, 0xF4, 0x0D, 0xBE, 0x15, 0x27, 0x6C, 0xE5, 0xEC
    , 0x25, 0xDC, 0x65, 0xE9, 0x07, 0x1A, 0x6C, 0xA6, 0x0E, 0xB2, 0xDB, 0xDE, 0x75, 0xD0, 0xC3, 0x67
    , 0x41, 0xCB, 0x4F, 0x5F, 0x00, 0xF5, 0x1E, 0x94, 0x45, 0x7D, 0xCA, 0x0F, 0xBF, 0xC4, 0x04, 0x83
    , 0x9E, 0xBE, 0x25, 0xB1, 0x5E, 0x32, 0xBF, 0x4F, 0x28, 0x9B, 0x68, 0x2E, 0x5A, 0xE0, 0xD1, 0x4A
    , 0xF3, 0xB2, 0x9E, 0xA9, 0x27, 0xD6, 0x6D, 0x58, 0x2E, 0x34, 0x67, 0x6B, 0xB8, 0x39, 0x15, 0x3A
    , 0x10, 0xE3, 0xD8, 0x74, 0x28, 0x83, 0x5C, 0x2F, 0x7C, 0xF0, 0x3B, 0x76, 0xA6, 0xEE, 0x4E, 0xE4
    , 0x38, 0x70, 0xBA, 0x20, 0x17, 0x9D, 0x28, 0x03, 0x87, 0x67, 0x6F, 0x90, 0x6F, 0x78, 0xA1, 0xFF
    , 0x98, 0xD3, 0x82, 0xB6, 0x11, 0x4D, 0xFB, 0xF7, 0x8B, 0x85, 0x79, 0x01, 0x6B, 0x42, 0x68, 0x77
    , 0x01, 0x51, 0xA4, 0x69, 0x2C, 0x11, 0x91, 0x1E, 0xBD, 0x64, 0xD3, 0x80, 0x68, 0x95, 0xFC, 0x1B
    , 0x85, 0xA1, 0xD9, 0xEB, 0xD2, 0x63, 0xA5, 0x61, 0x2A, 0x40, 0x98, 0x2D, 0xB8, 0x44, 0xB6, 0x04
    , 0xED, 0x00, 0xDB, 0xA1, 0xDB, 0xE4, 0x6A, 0x62, 0xC9, 0x8C, 0xA6, 0xFF, 0xA2, 0xBA, 0xE7, 0x3E
    , 0x12, 0x58, 0x01, 0x37, 0xB0, 0xFA, 0xBB, 0xBB, 0x13, 0xAC, 0x10, 0x60, 0x2B, 0x4E, 0x8F, 0xCF
    , 0x22, 0xD5, 0xC9, 0xA8, 0x59, 0x7A, 0xC9, 0xEE, 0xC4, 0xA6, 0xAE, 0x51, 0xE0, 0xD8, 0x4C, 0xF2
    , 0xA0, 0xAA, 0x6B, 0xA0, 0x20, 0xE8, 0x99, 0xFF, 0xF6, 0xBF, 0x15, 0x3C, 0x6C, 0x23, 0xCC, 0x0B
    , 0xC8, 0xF2, 0xD2, 0x3F, 0x43, 0x97, 0x74, 0x03, 0x6C, 0x3E, 0xA7, 0xF8, 0xE5, 0xD2, 0x04, 0x04
    , 0x40, 0x37, 0xBE, 0x49, 0xD1, 0xAA, 0xCF, 0xA0, 0xAF, 0x0A, 0xDA, 0x75, 0x7E, 0x2B, 0x66, 0xE1
    , 0x35, 0x72, 0x2A, 0xAF, 0x5F, 0x72, 0x11, 0x12, 0xEB, 0x67, 0xC0, 0x35, 0xAC, 0xAB, 0x03, 0x09
    , 0xA4, 0x9A, 0x1C, 0x97, 0xC7, 0x76, 0xD2, 0x66, 0x5D, 0x4B, 0x70, 0xD2, 0x9C, 0xDF, 0x0D, 0xBE
    , 0x74, 0x46, 0x9D, 0x1B, 0xC2, 0xA8, 0x33, 0xF7, 0x7A, 0xAB, 0xE0, 0xB0, 0xC2, 0x5D, 0xDE, 0x80
    , 0xCA, 0xD3, 0x28, 0xC1, 0xEB, 0x64, 0xCE, 0xEB, 0x93, 0xB1, 0x9C, 0xE9, 0x58, 0x97, 0xB2, 0x57
    , 0x7C, 0xB2, 0xD4, 0xCC, 0xFE, 0xEF, 0x0B, 0x10, 0x11, 0xAF, 0x0B, 0x55, 0x22, 0x30, 0xFA, 0xC1
    , 0x17, 0x48, 0xBC, 0x14, 0x25, 0x12, 0x83, 0xD1, 0xB0, 0x08, 0x11, 0x1C, 0x41, 0x07, 0xF1, 0xA5
    , 0x7D, 0x04, 0x51, 0x9C, 0x2B, 0x85, 0x49, 0xAD, 0x67, 0x78, 0xD9, 0x9B, 0x3C, 0xB7, 0x54, 0xD8
    , 0xB3, 0xB5, 0x2B, 0x0B, 0xC1, 0xE9, 0xCF, 0xD7, 0xAF, 0x5E, 0x5D, 0x99, 0xED, 0x45, 0x79, 0xBD
    , 0x3D, 0x37, 0xE6, 0x6B, 0x08, 0xA4, 0x96, 0x05, 0x51, 0xB8, 0x8A, 0xA6, 0xE9, 0x40, 0x7B, 0x25
    , 0xF7, 0xE2, 0x8F, 0x0F, 0x8D, 0xF0, 0xC3, 0x9F, 0x7B, 0x26, 0xA3, 0xA3, 0x45, 0x0F, 0x30, 0x27
    , 0xBF, 0xB0, 0xB3, 0xA9, 0xF1, 0xA5, 0xC4, 0xF3, 0xDD, 0xCD, 0x24, 0xF5, 0x5C, 0xC3, 0xFE, 0x4F
    , 0xA2, 0xFD, 0xF1, 0x15, 0x4F, 0x3F, 0x50, 0xAF, 0xB8, 0x95, 0x72, 0x7A, 0x95, 0xCE, 0x1D, 0xFD
    , 0xA7, 0x85, 0xD0, 0x92, 0x05, 0xEE, 0x42, 0x7B, 0xD8, 0x3D, 0xEE, 0x9C, 0xDB, 0x81, 0xF6, 0x7F
    , 0x1D, 0x1F, 0xA8, 0xA9, 0x0A, 0xDB, 0xA8, 0xC3, 0xE2, 0x08, 0x7E, 0x49, 0x00, 0xFF, 0xC2, 0x11
    , 0x32, 0xF8, 0x90, 0xE4, 0x40, 0x93, 0x34, 0x3A, 0x17, 0x4A, 0xAB, 0x67, 0x76, 0x36, 0x62, 0x1D
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xDB, 0xD2, 0xFC, 0x49, 0xEA, 0x27, 0x1B, 0xDD, 0x5C, 0x12, 0x14, 0x16, 0x4F, 0x54, 0xD2, 0x53
    , 0x77, 0xC1, 0x2F, 0xEF, 0x0D, 0x4D, 0x10, 0x08, 0x69, 0xA6, 0xB9, 0x9B, 0xE4, 0xDF, 0xC1, 0x47
    , 0xC2, 0x1E, 0x6F, 0xC7, 0xAF, 0x94, 0x9E, 0xF5, 0xEE, 0xAB, 0x07, 0x52, 0x02, 0x76, 0xB6, 0x0C
    , 0x1E, 0x74, 0x26, 0x19, 0x75, 0x0E, 0x23, 0x6F, 0x7B, 0x10, 0x64, 0x45, 0x31, 0xF6, 0xAA, 0xA6
    , 0x53, 0x78, 0x9D, 0xB0, 0xBC, 0xB2, 0xC7, 0x95, 0xAD, 0x87, 0x6D, 0x00, 0x86, 0x3C, 0x51, 0x34
    , 0x8F, 0x74, 0x0F, 0x1E, 0x34, 0x71, 0x59, 0x06, 0x4B, 0x07, 0xA6, 0xCB, 0x5C, 0x30, 0x5E, 0xA6
    , 0xA8, 0x2A, 0xBB, 0x4C, 0x5C, 0xD6, 0xAB, 0x38, 0xD0, 0xE7, 0x17, 0x94, 0x68, 0x90, 0xF1, 0x8B
    , 0x43, 0x6B, 0x93, 0xC3, 0x3E, 0xD7, 0x8B, 0x25, 0x51, 0x49, 0x97, 0x2A, 0x07, 0x79, 0xA6, 0x44
    , 0x65, 0x9D, 0x8C, 0x50, 0xA6, 0xC7, 0x7E, 0x17, 0xE7, 0x4D, 0x28, 0x81, 0x03, 0x69, 0x9C, 0xF7
    , 0x31, 0xAB, 0xEB, 0x8C, 0x5E, 0x6F, 0x01, 0x10, 0x01, 0xB2, 0x0F, 0x16, 0x8B, 0xD4, 0x0A, 0x4F
    , 0x3F, 0x27, 0xA1, 0xB1, 0x08, 0x74, 0x74, 0x26, 0x16, 0x35, 0x6E, 0x0D, 0x43, 0x64, 0xEA, 0xAA
    , 0x83, 0x07, 0xB0, 0x47, 0x44, 0xDF, 0x80, 0x0D, 0x20, 0x4D, 0x0A, 0x97, 0x2D, 0x28, 0xE1, 0xF4
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xC2, 0x0A, 0xEA, 0x1A, 0xBC, 0xE4, 0x19, 0xFE, 0xDF, 0x12, 0x52, 0x61, 0xA6, 0xDA, 0x07, 0xB5
    , 0xCF, 0x97, 0x8D, 0xF4, 0xFE, 0x97, 0xB7, 0xEF, 0x1B, 0xE7, 0xA4, 0x45, 0xD1, 0x58, 0xBB, 0xB1
};



#pragma arm section zidata="NONCACHEDZI", rwdata="NONCACHEDRW"
__align(4) kal_uint8 sdiobuf[2048] = {0xff,};
#pragma arm section zidata, rwdata
kal_uint8 sdiobuf2[2048] = {0xff,};


void test_hisr(void)
{
    kal_uint32 sdc_intsta;
    dbg_print("interrupt callback\r\n");
    msdc_dbg_print("[%s %d]SDIO EINT12 \r\n", __FUNCTION__, __LINE__);

    //EINT_Set_Polarity(MT5931_EINT_NUM, KAL_FALSE);
    //call = 1;
    //SDIO_HISR_Entry();
}

kal_int32
kalDevReadWithSdioCmd52(
    kal_uint32          u4Register,
    kal_uint8 *         pucValue
)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;
    Data.rSDIOCMD52.func = DCL_SDIO_FUCN_0;
    Data.rSDIOCMD52.addr = u4Register;
    Status = DclSDIO_Control(handle_sdio, SDIO_CTRL_CMD_CMD52_READ, &Data);

    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevReadWithSdioCmd52() reports error: %d", Status);
        return -1;
    }
    else
    {
        *pucValue = Data.rSDIOCMD52.rdata;
        return 0;
    }
}

kal_int32
kalDevWriteWithSdioCmd52(
    kal_uint32          u4Register,
    kal_uint8         ucValue
)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;
    Data.rSDIOCMD52.func = DCL_SDIO_FUCN_0;
    Data.rSDIOCMD52.addr = u4Register;
    Data.rSDIOCMD52.wdata = ucValue;
    Status = DclSDIO_Control(handle_sdio, SDIO_CTRL_CMD_CMD52_WRITE, &Data);

    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevWriteWithSdioCmd52() reports error: %x", Status);
        return -1;
    }
    else
        return 0;
}

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
__align(4) kal_uint8 uvalue[4] = {0xff,};
#pragma arm section zidata, rwdata

kal_int32
kalDevRegRead (
    //IN  P_GLUE_INFO_T    prGlueInfo,
    kal_uint32          u4Register,
    kal_uint32 *        pu4Value
)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;

    //Setup and Excute CMD53
    Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
    Data.rSDIOCMD53.block = KAL_FALSE;
    Data.rSDIOCMD53.addr = u4Register;
    Data.rSDIOCMD53.buffer = (kal_uint32)&uvalue[0];
    Data.rSDIOCMD53.op = DCL_SDIO_FIX;
    Data.rSDIOCMD53.count = 4; //4*8 Bits
    /*Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_INIT,NULL);
    if (Status == FALSE) {
        ERRORLOG(("kalDevRegRead() CMD Init fail: %x", Status));
    }*/

    Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD53_READ, &Data);

    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevRegRead() reports error: %d", Status);
        return -1;
    }
    else
    {
        *pu4Value = ((kal_uint32)uvalue[3] << 24) + ((kal_uint32)uvalue[2] << 16) + ((kal_uint32)uvalue[1] << 8) + uvalue[0];
        return 0;
    }
}
kal_int32
kalDevRegWrite (
    //IN P_GLUE_INFO_T    prGlueInfo,
    kal_uint32          u4Register,
    kal_uint32          u4Value)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;

    uvalue[0] = (kal_uint8)u4Value & 0xFF;
    uvalue[1] = (kal_uint8)((u4Value >> 8) & 0xFF);
    uvalue[2] = (kal_uint8)((u4Value >> 16) & 0xFF);
    uvalue[3] = (kal_uint8)((u4Value >> 24) & 0xFF);
    //Setup and Excute CMD53
    Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
    Data.rSDIOCMD53.block = KAL_FALSE;
    Data.rSDIOCMD53.addr = u4Register;
    Data.rSDIOCMD53.buffer = (kal_uint32)&uvalue[0];
    Data.rSDIOCMD53.op = DCL_SDIO_FIX;
    Data.rSDIOCMD53.count = 4; //4*8 Bits
    /*Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_INIT,NULL);
    if (Status == FALSE) {
        ERRORLOG(("kalDevRegRead() CMD Init fail: %x", Status));
    }*/

    Status = DclSDIO_Control(handle_sdio, SDIO_CTRL_CMD_CMD53_WRITE, &Data);

    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevRegWrite() reports error: %d", Status);
        return -1;
    }
    else
    {
        return 0;
    }
}

int kalDevPortRead (
    //IN  P_GLUE_INFO_T   prGlueInfo,
    kal_uint16         u2Port,
    kal_uint16         u2Len,
    kal_uint8 *         pucBuf
    //IN  UINT_16         u2ValidOutBufSize
)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;
    kal_uint8 bNum = 0;
    kal_uint16 i;
    kal_uint32 u4TotalLen, u4Len;

#if 1
    u4Len = u2Len;

    while (u2Len >= FUNC1_SDIO_BLK_SIZE)
    {
        u2Len -= FUNC1_SDIO_BLK_SIZE;
        bNum++;
    }

    if (u2Len > 0 && bNum > 0)
    {
        bNum++;
    }

    if (bNum > 0)   // block mode
    {
        Data.rSDIOCMD53.block = KAL_TRUE;
        u4TotalLen = ALIGN_32(bNum * FUNC1_SDIO_BLK_SIZE);
        Data.rSDIOCMD53.count = bNum;
    }
    else if (u2Len > DMA_THRESHOLD)  //byte mode with DMA
    {
        Data.rSDIOCMD53.block = KAL_FALSE;
        u4TotalLen = ALIGN_32(u2Len);
        Data.rSDIOCMD53.count = u4TotalLen;
    }
    else   //byte mode wit MCU
    {
        u4TotalLen = ALIGN_32(u2Len);
        Data.rSDIOCMD53.block = KAL_FALSE;
        Data.rSDIOCMD53.count = u2Len;
    }

    if (u4TotalLen >= DMA_THRESHOLD
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
            && is_predef_dyna_c_region((kal_uint32)pucBuf, u4TotalLen)
#endif /* __ARM9_DCACHEABLE__ */
       )
    {
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
        dynamic_switch_cacheable_region((void *)&pucBuf, u4TotalLen, SWITCH_TO_NONCACHEABLE);
#endif /*__ARM9_DCACHEABLE__*/
        Data.rSDIOCMD53.buffer = (kal_uint32)pucBuf;
        Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
        Data.rSDIOCMD53.addr = u2Port;
        Data.rSDIOCMD53.op = DCL_SDIO_FIX;
        Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD53_READ, &Data);
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
        dynamic_switch_cacheable_region((void *)&pucBuf, u4TotalLen, SWITCH_TO_CACHEABLE);
#endif /*__ARM9_DCACHEABLE__*/
    }
    else
    {
        if (u4TotalLen >= DMA_THRESHOLD)
        {
            Data.rSDIOCMDREG.data = 1;

            if (STATUS_OK != DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_FORCEMCU_READ, &Data))
            {
                msdc_dbg_print("SDIO_CTRL_CMD_FORCEMCU_READ failed %s %d!!", __FUNCTION__, __LINE__);
            }
        }

        Data.rSDIOCMD53.buffer = (kal_uint32)pucBuf;
        Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
        Data.rSDIOCMD53.addr = u2Port;
        Data.rSDIOCMD53.op = DCL_SDIO_FIX;
        Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD53_READ, &Data);

        if (u4TotalLen >= DMA_THRESHOLD)
        {
            Data.rSDIOCMDREG.data = 0;

            if (STATUS_OK != DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_FORCEMCU_READ, &Data))
            {
                msdc_dbg_print("SDIO_CTRL_CMD_FORCEMCU_READ failed %s %d!!", __FUNCTION__, __LINE__);
            }
        }
    }

    //printk(KERN_INFO DRV_NAME"-- kalDevPortWrite-- ret=%d\n", ret);
    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevPortRead() reports error: %x", Status);
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }

#else
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
#endif /*__ARM9_DCACHEABLE__*/
/* under construction !*/
/* under construction !*/
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
#endif /*__ARM9_DCACHEABLE__*/
/* under construction !*/
/* under construction !*/
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
/* under construction !*/
#endif/*__ARM9_DCACHEABLE__*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
} /* end of kalDevPortRead() */

int
kalDevPortWrite (
    //IN P_GLUE_INFO_T  prGlueInfo,
    kal_uint16        u2Port,
    kal_uint16        u2Len,
    kal_uint8 *        pucBuf
    //IN UINT_16        u2ValidInBufSize
)
{
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS Status;
    kal_uint8 bNum = 0;
    kal_uint32 u4TotalLen, u4Len;

    u4Len = u2Len;

    //Setup and Excute CMD53
    /* Split buffer into multiple single block to workaround hifsys */
    while (u2Len >= FUNC1_SDIO_BLK_SIZE)
    {
        u2Len -= FUNC1_SDIO_BLK_SIZE;
        bNum++;
    }

    if (u2Len > 0 && bNum > 0)
    {
        bNum++;
    }

    if (bNum > 0)   // block mode
    {
        Data.rSDIOCMD53.block = KAL_TRUE;
        u4TotalLen = ALIGN_32(bNum * FUNC1_SDIO_BLK_SIZE);
        Data.rSDIOCMD53.count = bNum;
    }
    else   //byte mode
    {
        Data.rSDIOCMD53.block = KAL_FALSE;
        u4TotalLen = ALIGN_32(u4Len);
        Data.rSDIOCMD53.count = u4TotalLen;
    }

    if ((u4TotalLen - u4Len) >= sizeof(kal_uint32))
    {
        /* fill with single dword of zero as TX-aggregation termination */
        *(kal_uint32 *) (&((pucBuf)[ALIGN_4(u4Len)])) = 0;
    }

    if (u4TotalLen >= DMA_THRESHOLD
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
            && is_predef_dyna_c_region((kal_uint32)pucBuf, u4TotalLen)
#endif /* __ARM9_DCACHEABLE__ */
       )
    {
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
        dynamic_switch_cacheable_region((void *)&pucBuf, u4TotalLen, SWITCH_TO_NONCACHEABLE);
#endif /*__ARM9_DCACHEABLE__*/
        Data.rSDIOCMD53.buffer = (kal_uint32)pucBuf;
        Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
        Data.rSDIOCMD53.addr = u2Port;
        Data.rSDIOCMD53.op = DCL_SDIO_FIX;
        Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD53_WRITE, &Data);
#if defined (__ARM9_DCACHEABLE__) || defined (__DYNAMIC_SWITCH_CACHEABILITY__)
        dynamic_switch_cacheable_region((void *)&pucBuf, u4TotalLen, SWITCH_TO_CACHEABLE);
#endif /*__ARM9_DCACHEABLE__*/
    }
    else
    {
        if (u4TotalLen >= DMA_THRESHOLD)
        {
            Data.rSDIOCMDREG.data = 1;

            if (STATUS_OK != DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_FORCEMCU_WRITE, &Data))
            {
                msdc_dbg_print("SDIO_CTRL_CMD_FORCEMCU_WRITE failed %s %d!!", __FUNCTION__, __LINE__);
            }
        }

        Data.rSDIOCMD53.buffer = (kal_uint32)pucBuf;
        Data.rSDIOCMD53.func = DCL_SDIO_FUCN_1;
        Data.rSDIOCMD53.addr = u2Port;
        Data.rSDIOCMD53.op = DCL_SDIO_FIX;
        Status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD53_WRITE, &Data);

        if (u4TotalLen >= DMA_THRESHOLD)
        {
            Data.rSDIOCMDREG.data = 0;

            if (STATUS_OK != DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_FORCEMCU_WRITE, &Data))
            {
                msdc_dbg_print("SDIO_CTRL_CMD_FORCEMCU_WRITE failed %s %d!!", __FUNCTION__, __LINE__);
            }
        }
    }

    //printk(KERN_INFO DRV_NAME"-- kalDevPortWrite-- ret=%d\n", ret);
    if (Status != STATUS_OK)
    {
        msdc_dbg_print("kalDevPortWrite() reports error: %d", Status);
        return KAL_FALSE;
    }
    else
    {
        return KAL_TRUE;
    }
} /* end of kalDevPortWrite() */


kal_int32
wlanImageSectionDownload (
    // P_ADAPTER_T  prAdapter,
    kal_int32      u4DestAddr,
    kal_int32      u4ImgSecSize,
    kal_int8      *pucImgSecBuf
)
{


    kal_uint32 i, u4Value;
    P_HIF_HW_TX_HEADER_T prHifTxHeader;

    WLAN_STATUS u4Status = WLAN_STATUS_SUCCESS;

    kal_uint8 * pucDmaBuf;
    kal_uint32 u4TotalLen;
    kal_uint32 u4DmaLen;
    kal_uint32 u4DmaOffset;

    //ASSERT(prAdapter);
    //ASSERT(pucImgSecBuf);
    //ASSERT(u4ImgSecSize <= CMD_PKT_SIZE_FOR_IMAGE);

    msdc_dbg_print("wlanImageSectionDownload");
    //DBGLOG(INIT, TRACE, ("Destination: 0x%08x / Length: 0x%08x\n", u4DestAddr, u4ImgSecSize));
    msdc_dbg_print("Destination: 0x%08x / Length: 0x%08x", u4DestAddr, u4ImgSecSize);

    if (u4ImgSecSize == 0)
    {
        return WLAN_STATUS_SUCCESS;
    }

    // 1. Use TX coalescing buffer
    prHifTxHeader = (P_HIF_HW_TX_HEADER_T)(&wndrv_cmd_temp_buf[0]);

    // 2. Setup HIF_TX_HEADER
    //prHifTxHeader->u2TxByteCount = (UINT_16)(ALIGN_4(sizeof(HIF_HW_TX_HEADER_T) + u4ImgSecSize));
    prHifTxHeader->u2TxByteCount = (kal_uint16)(ALIGN_4(HIF_HW_TX_HDR_SIZE + u4ImgSecSize));
    prHifTxHeader->ucEtherTypeOffset = 0;
    prHifTxHeader->ucCSflags = 0;

    // 3. Copy payload
    memcpy((void *)prHifTxHeader->aucBuffer, (void *)pucImgSecBuf, u4ImgSecSize);

    // 3.1 add 4-bytes zero tail
    //kalMemZero(&(prHifTxHeader->aucBuffer[ALIGN_4(u4ImgSecSize)]), sizeof(HIF_HW_TX_HEADER_T));
    memset(&(prHifTxHeader->aucBuffer[ALIGN_4(u4ImgSecSize)]), 0, HIF_HW_TX_HDR_SIZE);

    // 4. Poll til FWDL_RDY = 1
    i = 0;

    while (1)
    {
        kalDevRegRead(MCR_FWDLSR, &u4Value);//HAL_MCR_RD(prAdapter, MCR_FWDLSR, &u4Value);

        if (u4Value & FWDLSR_FWDL_RDY)
        {
            //DBGLOG(INIT, TRACE, ("FWDL_RDY detected\n"));
            msdc_dbg_print("FWDL_RDY detected", u4DestAddr, u4ImgSecSize);
            break;
        }
        else if (i >= CFG_RESPONSE_POLLING_TIMEOUT)
        {
            //DBGLOG(INIT, ERROR, ("Waiting for FWDL_RDY: Timeout (0x%08X)\n", u4Value));
            msdc_dbg_print("Waiting for FWDL_RDY: Timeout (0x%x)", u4Value);
            u4Status = WLAN_STATUS_FAILURE;
            break;
        }
        else
        {
            i++;
            kal_sleep_task(10);
        }
    }

    // 5. Send firmware
    kalDevRegWrite(WEHTCR, ALIGN_4(prHifTxHeader->u2TxByteCount));//HAL_MCR_WR(prAdapter, WEHTCR, ALIGN_4(prHifTxHeader->u2TxByteCount));
    u4TotalLen = ALIGN_4(prHifTxHeader->u2TxByteCount);

    //HAL_PORT_WR(prAdapter,MCR_FWDLDR,u4TotalLen,(PUINT_8)prHifTxHeader,prAdapter->u4CoalescingBufCachedSize);
    if (u4TotalLen > 4)
    {
        kalDevRegWrite(WEHTCR, ALIGN_4(u4TotalLen));//HAL_MCR_WR(_prAdapter, WEHTCR, ALIGN_4(u4TotalLen));
    }

    if (kalDevPortWrite(MCR_FWDLDR, u4TotalLen, (kal_uint8 *)prHifTxHeader) == KAL_FALSE)
    {
        //HAL_SET_FLAG(_prAdapter, ADAPTER_FLAG_HW_ERR);
        //fgIsBusAccessFailed = TRUE;
        msdc_dbg_print("HAL_PORT_WR access fail! 0x%x\n", MCR_FWDLDR);
    }

    kalDevRegWrite(WEHTCR, 4);//HAL_MCR_WR(prAdapter, WEHTCR, 4);

    return u4Status;

}
void  wndrv_wifi_hifsys_init( void )
{
    //    P_ADAPTER_T prAdapter = wndrv_context.adpt_p;
    kal_uint32     u4Value;
    kal_uint32  counter = 0;

    do
    {
        kalDevRegWrite(WHLPCR, 0x00000200);//HAL_MCR_WR( prAdapter, WHLPCR, 0x00000200 );
        kalDevRegRead(WHLPCR, &u4Value);//HAL_MCR_RD(prAdapter, WHLPCR, &u4Value);

        //kal_sleep_task(10);
        if ( counter++ > 512 )
        {
            msdc_dbg_print("[eHPI test]Request FW-Own back failed! (times=%d)", counter );
            break;
            //ASSERT(0);
        }
    }
    while ( !(u4Value & 0x00000100) );

    kalDevRegWrite(WHIER, 0xffffff17);//HAL_MCR_WR( prAdapter, WHIER, 0xffffff17 );
}
int  wndrv_prepare_test( int test_number )
{
    unsigned int response = 0;
    //P_ADAPTER_T prAdapter = wndrv_context.adpt_p;
    kal_uint32 reg_value = 0;
    kal_uint32 ret;
    kal_uint32 loop_count = 0;

    msdc_dbg_print("wndrv_prepare_test():#%d", test_number);

    /* write test number */
    ret = kalDevRegWrite(H2DSM0R, (unsigned int)test_number);//HAL_MCR_WR( prAdapter, H2DSM0R, (unsigned int)test_number );

    if (ret == -1)
    {
        msdc_dbg_print("Reg write error\r\n");
    }


    /* interrupt firmware: H2D[31] */
    //    HAL_MCR_WR( prAdapter, WSICR, 1 << 31 );
    ret = kalDevRegWrite(WSICR, 0x80000000);//HAL_MCR_WR( prAdapter, WSICR, 0x80000000 );

    if (ret == -1)
    {
        msdc_dbg_print("Reg write error\r\n");
    }


    /* wait for response */
    while (1)
    {
        kalDevRegRead(WHISR, &reg_value);//HAL_MCR_RD( prAdapter, WHISR, &reg_value );

        if ( reg_value & (0x80000000) ) /* check bit_31 of WHISR */
        {
            kalDevRegRead(D2HRM0R, &response);//HAL_MCR_RD( prAdapter, D2HRM0R, &response );
            msdc_dbg_print("WHISR = [%x]", reg_value);
            msdc_dbg_print("response = [%x]", response);
            break;
        }
        else
        {
            kalDevRegWrite(WHIER, 0xffffff17);//HAL_MCR_WR( prAdapter, WHIER, 0xffffff17 ); /* enable interrupt */
            kal_sleep_task(1);//kalUdelay(10);

            //if ( loop_count++ > 500000 )
            if ( loop_count++ > 5120 )
            {
                msdc_dbg_print("Pollin WHISR fail");
                return -1;
            }

            msdc_dbg_print("Pollin WHISR...");
        }
    }

    if ( response == test_number + 1 )
    {
        return 0;
    }
    else if ( response == test_number - 1 )
    {
        return -1;
    }
    else /* unexpected response */
    {
        return -1;
    }
}

kal_int32 wndrv_generate_random_payload(unsigned char *buf, int len)
{
    int i;

    //randomize();

    for (i = 0 ; i < len ; i++)
        buf[i] = (unsigned char)(rand() & 0xff);

    return 0;
}

kal_int32 wndrv_generate_test_frame(unsigned char *buf,	int len, Data_Pattern type)
{
    // controls pattern (initialization included)
    //unsigned char test_cnt = 5;
    //unsigned char i;
    //    unsigned char *payload = NULL;
    unsigned short payload_s = 0;
    unsigned char *dst = buf;
    int offset = 0;
    NIC_HIF_TX_HEADER_T txHeader;
    //    payload = get_ctrl_buffer(1500);
    payload_s = len - sizeof(NIC_HIF_TX_HEADER_T);


    // attach NIC_HIF_TX_HEADER_T in the head

    txHeader.u2TxByteCount      = len;
    txHeader.ucEtherTypeOffset  = 0x0;//(sizeof(NIC_HIF_TX_HEADER_T) + 12) / 2;
    txHeader.ucCSUMFlags        = 0x0; // [UT = 0 / I = 0]
    txHeader.dummy[0]       = 0x0;
    txHeader.dummy[1]       = 0x0;
    txHeader.dummy[2]       = 0x0;

    kal_mem_cpy(&dst[offset], &txHeader, sizeof(NIC_HIF_TX_HEADER_T));
    offset += sizeof(NIC_HIF_TX_HEADER_T);

    // payload generation
    switch (type)
    {
        case RANDOM:
            if (payload_s > 0)
            {
                wndrv_generate_random_payload(&payload[0], payload_s);
            }

            break;

        case DATA_FF:
            memset (payload, 0xFF , payload_s);
            break;

        case DATA_00:
            memset (payload, 0x00 , payload_s);
            break;

        case DATA_F0:
            memset (payload, 0xF0 , payload_s);
            break;

        case DATA_0F:
            memset (payload, 0x0F , payload_s);
            break;

        case DATA_55:
            memset (payload, 0x55 , payload_s);
            break;

        case DATA_99:
            memset (payload, 0x99 , payload_s);
            break;

        case DATA_AA:
            memset (payload, 0xAA , payload_s);
            break;

        case DATA_66:
            memset (payload, 0x66 , payload_s);
            break;

        default:
            memset (payload, 0x11 , payload_s);
            break;
    }

    // memcpy for generated frame
    kal_mem_cpy(&dst[offset], &payload[0], payload_s);
    //    free_ctrl_buffer(payload);
    return 0;
}

void HAL_PORT_WR(kal_uint16 _u4Port, kal_uint16 _u4Len, kal_uint8 * _pucBuf)
{
    if (_u4Len > 4)
    {
        kalDevRegWrite( WEHTCR, ALIGN_4(_u4Len));
    }

    if (kalDevPortWrite(_u4Port, _u4Len, _pucBuf) == KAL_FALSE)
    {
        msdc_dbg_print("HAL_PORT_WR access fail! 0x%x\n", _u4Port);
    }
    else
    {
        /*fgResult = TRUE;*/
    }

    kalDevRegWrite( WEHTCR, 4);
}
void HAL_PORT_RD(kal_uint16 _u4Port, kal_uint16 _u4Len, kal_uint8 * _pucBuf)
{
    if (_u4Len > 4)
    {
        kalDevRegWrite(WEHTCR, ALIGN_4(_u4Len));
    }

    if (kalDevPortRead(_u4Port, _u4Len, _pucBuf) == KAL_FALSE)
    {
        msdc_dbg_print(" access fail! 0x%x\n", _u4Port);
    }
    else
    {
        /*fgResult = TRUE;*/
    }

    kalDevRegWrite( WEHTCR, 4);
}



kal_int32 SDIO_test_main_MT5931_SDIOISR( SD_BITWIDTH bus )
{
    DCL_CTRL_DATA_T sdiodata;
    DCL_CTRL_DATA_T Data;
    DCL_SDC_CMD_STATUS status = STATUS_OK;
    kal_uint32      counter, u4Status, u4Value, u4Pass = 0, u4FileSize, wndrv_firmware_loopback_size, u4Actual_length, reg_value, u4FwLoadAddr, i;
    kal_uint8 const *wndrv_firmware_loopback_p;
    kal_uint8  fgIsPass = 0;
    kal_uint16 u2Packet_Len;
    kal_uint8   TX_DMA = 0; //MCU
    kal_uint8   RX_DMA = 0; //MCU
    kal_uint8   data_type = 0;
    kal_uint32	u4DmaLen, u4DmaOffset1, u4DmaOffset2;
    kal_int32 ret;
    //    unsigned char *pucTXBuf = NULL;
    //    unsigned char *pucRXBuf = NULL;
    kal_uint32  loopback_times = 10;
    //    pucTXBuf = get_ctrl_buffer(1500);
    //    pucRXBuf = get_ctrl_buffer(1500);

POWER_ON_AGAIN:


    msdc_dbg_print("[%s %d]start,bus=%d", __FUNCTION__, __LINE__, bus);

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
    //-------------------------------------------------------------------------
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif


    //-------------------------------------------------------------------------
    DclSDIO_Initialize();
    handle_sdio = DclSDIO_Open(DCL_SDIO, DCL_SDIO_FLAGS_DEVICE_CARD1 | DCL_SDIO_FLAGS_USAGE_CMD | DCL_SDIO_FLAGS_SDIO1);
    msdc_dbg_print( "[%s %d]The SDIO handle_sdio is 0x%x", __FUNCTION__, __LINE__, handle_sdio);

    if ( handle_sdio  == DCL_HANDLE_INVALID )
    {
        msdc_dbg_print("[%s %d]ERROR \r\n", __FUNCTION__, __LINE__);
        return -1;
    }

    //-------------------------------------------------------------------------
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_INIT, NULL);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }

    //-------------------------------------------------------------------------
    status = SDIO_configure_bus(bus);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,bus=%d(0:1bit; 2:4bit)", __FUNCTION__, __LINE__, bus);
    }

    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMDREG.data = 128;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_MCUDMA_WRITE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }

    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_MCUDMA_READ, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,mcudma=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMDREG.data);
    }

    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMDREG.data = 20000; // 20000KHZ
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_SETCLK, &sdiodata);

    if (STATUS_OK == status)
    {
        sdiodata.rSDIOCMDREG.data = 0;
        status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_GETCLK, &sdiodata);

        if (STATUS_OK != status)
        {
            kal_prompt_trace(MOD_MSDC_HISR, "[guilin %s %d]ERROR", __FUNCTION__, __LINE__);
            return ;
        }
        else
        {
            kal_prompt_trace(MOD_MSDC_HISR, "[guilin %s %d]OK,SDIO_CTRL_CMD_GETCLK=%d", __FUNCTION__, __LINE__, sdiodata.rSDIOCMDREG.data);
        }
    }
    else
    {
        kal_prompt_trace(MOD_MSDC_HISR, "[guilin %s %d]ERROR", __FUNCTION__, __LINE__);
        return ;
    }

    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMDREG.data = 0;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CLKSRC_READ, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,clksrc=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMDREG.data);
    }

    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMDREG.data = 0;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_SCLKF_READ, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,sclkf=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMDREG.data);
    }

    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMDREG.data = 0;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CLKPADRED_READ, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,msdc_iocon.clkpadred=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMDREG.data);
    }

    //-------------------------------------------------------------------------
    msdc_dbg_print("[%s %d]CCCR TEST \r\n", __FUNCTION__, __LINE__);
    {
        kal_int32 i;

        for (i = 0; i < 0x14; i++)
        {
            sdiodata.rSDIOCMD52.func = DCL_SDIO_FUCN_0;
            sdiodata.rSDIOCMD52.addr = i;
            sdiodata.rSDIOCMD52.rdata = 0;
            status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD52_READ, &sdiodata);

            if (STATUS_OK != status)
            {
                msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
                return;
            }
            else
            {
                msdc_dbg_print("[%s %d]OK,CCCR[0x%x]=0x%x,R5=0x%x \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMD52.addr, sdiodata.rSDIOCMD52.rdata, sdiodata.rSDIOCMD52.r5_resp);
            }
        }
    }
    //-------------------------------------------------------------------------
    sdiodata.rSDIOCMD52.func = DCL_SDIO_FUCN_0;
    sdiodata.rSDIOCMD52.addr = 4;
    sdiodata.rSDIOCMD52.wdata = 3;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD52_WRITE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        sdiodata.rSDIOCMD52.func = DCL_SDIO_FUCN_0;
        sdiodata.rSDIOCMD52.addr = 4;
        sdiodata.rSDIOCMD52.rdata = 0;
        status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_CMD52_READ, &sdiodata);

        if (STATUS_OK != status)
        {
            msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
            return;
        }
        else
            msdc_dbg_print("[%s %d]OK,CCCR[0x%x]=0x%x,R5=0x%x \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOCMD52.addr, sdiodata.rSDIOCMD52.rdata, sdiodata.rSDIOCMD52.r5_resp);
    }

    //-------------------------------------------------------------------------
    msdc_dbg_print("[%s %d]SET BLOCKSIZE=512 \r\n", __FUNCTION__, __LINE__);
    sdiodata.rSDIOSetBlkSize.function = DCL_SDIO_FUCN_0;
    sdiodata.rSDIOSetBlkSize.size = 512;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_SET_BLK_SIZE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }

    sdiodata.rSDIOSetBlkSize.size = 0;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_GET_BLK_SIZE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,blocksize=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOSetBlkSize.size);
    }

    sdiodata.rSDIOSetBlkSize.function = DCL_SDIO_FUCN_1;
    sdiodata.rSDIOSetBlkSize.size = 512;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_SET_BLK_SIZE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }

    sdiodata.rSDIOSetBlkSize.size = 0;
    status = DclSDIO_Control (handle_sdio, SDIO_CTRL_CMD_GET_BLK_SIZE, &sdiodata);

    if (STATUS_OK != status)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }
    else
    {
        msdc_dbg_print("[%s %d]OK,blocksize=%d \r\n", __FUNCTION__, __LINE__, sdiodata.rSDIOSetBlkSize.size);
    }

    //guilin
    status = kalDevWriteWithSdioCmd52(4, 3); // enable sdio interrupt

    if (status != STATUS_OK)
    {
        msdc_dbg_print("[%s %d]Error,%d", __FUNCTION__, __LINE__, status);
        return;
    }

    //-------------------------------------------------------------------------

    //-------------------------------------------------------------------------
    /* 0. Read Chip ID */
    if (STATUS_OK != kalDevRegRead(WCIR, &u4Value)) //HAL_MCR_RD( prAdapter, WCIR, &u4Value );
    {
        msdc_dbg_print("[%s %d]Error", __FUNCTION__, __LINE__);
        return;
    }
    else
    {
        msdc_dbg_print("[eHPI test]Chip ID = %x", u4Value & 0xfffff );
    }

    /* 1.1 wait for INIT_RDY */
    i = 0;

    while (1)
    {
        kalDevRegRead(MCR_WMCSR, &u4Value);//HAL_MCR_RD(prAdapter, MCR_WMCSR, &u4Value);

        if (u4Value & WMCSR_INI_RDY)
        {
            msdc_dbg_print("INIT-RDY detected");
            break;
        }
        else if (i >= CFG_RESPONSE_POLLING_TIMEOUT)
        {
            msdc_dbg_print("Waiting for Init Ready bit: Timeout");
            u4Status = WLAN_STATUS_FAILURE;
            //ASSERT(u4Status == WLAN_STATUS_SUCCESS);
            return;
        }
        else
        {
            i++;
            kal_sleep_task(10);
        }
    }

    wndrv_firmware_loopback_size = sizeof(mt5931_E3_Beta_loopback_firmware_hex);
    u4FileSize = wndrv_firmware_loopback_size;
    /* 1.2 set KSEL/FLEN */
    msdc_dbg_print("1.2 set KSEL/FLEN = %d", u4FileSize);
    kalDevRegWrite(MCR_FWCFG, u4FileSize >> 6);//    HAL_MCR_WR(prAdapter, MCR_FWCFG, u4FileSize >> 6);
    /* 1.3 enable FWDL_EN */
    msdc_dbg_print("1.3 enable FWDL_EN");
    kalDevRegWrite(FWDLCMR0, WMCSR_FWDLEN | WMCSR_FWDLRST); //HAL_MCR_WR( prAdapter, FWDLCMR0, WMCSR_FWDLEN|WMCSR_FWDLRST);
    kalDevRegWrite(FWDLCMR0, WMCSR_FWDLEN);//HAL_MCR_WR( prAdapter, FWDLCMR0, WMCSR_FWDLEN);
    /* 1.4 wait for PLL_RDY */
    msdc_dbg_print("1.4 wait for PLL_RDY");
    i = 0;

    while (1)
    {
        kalDevRegRead(MCR_WMCSR, &u4Value);//HAL_MCR_RD(prAdapter, MCR_WMCSR, &u4Value);
        msdc_dbg_print("[%s %d]MCR_WMCSR=0x%x ", __FUNCTION__, __LINE__, u4Value);

        if (u4Value & WMCSR_PLLRDY)
        {
            msdc_dbg_print("PLL-RDY detected\n");
            break;
        }
        else if (i >= CFG_RESPONSE_POLLING_TIMEOUT)
        {
            msdc_dbg_print("Waiting for PLL Ready bit: Timeout\n");
            u4Status = WLAN_STATUS_FAILURE;
            //kal_sleep_task(1000);
            //goto POWER_ON_AGAIN;
            return;
        }
        else
        {
            i++;
            kal_sleep_task(10);
        }
    }

    /* 2.1 turn on HIFSYS firmware download mode */
    msdc_dbg_print("2.1 turn on HIFSYS firmware download mode");
    kalDevRegWrite(MCR_FWDLSR, FWDLSR_FWDL_MODE);//HAL_MCR_WR(prAdapter, MCR_FWDLSR, FWDLSR_FWDL_MODE);
    /* 2.2 set starting address */
    wndrv_firmware_loopback_p = mt5931_E3_Beta_loopback_firmware_hex;
    u4FwLoadAddr = CFG_FW_LOAD_ADDRESS;
    kalDevRegWrite(MCR_FWDLDSAR, u4FwLoadAddr);//HAL_MCR_WR(prAdapter, MCR_FWDLDSAR, u4FwLoadAddr);
    msdc_dbg_print("[eHPI test]0. Firmware Download" );

    for (i = 0; i < u4FileSize ; i += CMD_PKT_SIZE_FOR_IMAGE)
    {
        if (i + CMD_PKT_SIZE_FOR_IMAGE < u4FileSize)
            u4Actual_length = CMD_PKT_SIZE_FOR_IMAGE;
        else
            u4Actual_length = u4FileSize - i;

        //if(wlanImageSectionDownload(prAdapter,u4FwLoadAddr + i,u4Actual_length,(kal_uint8 *)wndrv_firmware_loopback_p + i) != WLAN_STATUS_SUCCESS)
        if (wlanImageSectionDownload(u4FwLoadAddr + i, u4Actual_length, (kal_uint8 *)wndrv_firmware_loopback_p + i) != WLAN_STATUS_SUCCESS)
        {
            msdc_dbg_print("Firmware scatter download failed!");
            return;
        }
    }

    /* 4.1 poll FWDL_OK & FWDL_FAIL bits */
    i = 0;

    while (1)
    {
        kalDevRegRead(MCR_WMCSR, &u4Value);//HAL_MCR_RD(prAdapter, MCR_WMCSR, &u4Value);
        msdc_dbg_print("[%s %d]MCR_WMCSR=0x%x ", __FUNCTION__, __LINE__, u4Value);

        if (u4Value & WMCSR_DL_OK)
        {
            msdc_dbg_print("DL_OK detected\n");
            break;
        }
        else if (i >= CFG_RESPONSE_POLLING_TIMEOUT)
        {
            msdc_dbg_print("Waiting for DL_OK/DL_FAIL bit: Timeout\n");
            u4Status = WLAN_STATUS_FAILURE;
            //ASSERT(u4Status == WLAN_STATUS_SUCCESS); //TODO(Nelson): error handling for this
            return;
        }
        else
        {
            i++;
            kal_sleep_task(10);
        }
    }

    /* 4.2 turn off HIFSYS download mode */
    kalDevRegWrite(MCR_FWDLSR, 0);//HAL_MCR_WR(prAdapter, MCR_FWDLSR, 0);

    /* 5. disable interrupt */
    kalDevRegWrite(MCR_WHLPCR, WHLPCR_INT_EN_CLR);//HAL_MCR_WR(prAdapter, MCR_WHLPCR, WHLPCR_INT_EN_CLR);//nicDisableInterrupt(prAdapter);

    msdc_dbg_print("wlanAdapterStart(): Waiting for Ready bit..\n");
    /* 6. check Wi-Fi FW asserts ready bit */
    i = 0;

    while (1)
    {
        kalDevRegRead(MCR_WCIR, &u4Value);//HAL_MCR_RD(prAdapter, MCR_WCIR, &u4Value);

        if (u4Value & WCIR_WLAN_READY)
        {
            msdc_dbg_print("Ready bit asserted\n");
            break;
        }
        else if (i >= CFG_RESPONSE_POLLING_TIMEOUT)
        {
            msdc_dbg_print("Waiting for Ready bit: Timeout\n");
            u4Status = WLAN_STATUS_FAILURE;
            //ASSERT(u4Status == WLAN_STATUS_SUCCESS); //TODO(Nelson): error handling for this
            return;
        }
        else
        {
            i++;
            kal_sleep_task(10);
        }
    }

    msdc_dbg_print("[eHPI test]1. Chip ID/Revision ID" );
    kalDevRegRead(WCIR, &reg_value );//HAL_MCR_RD( prAdapter, WCIR, &reg_value );
    msdc_dbg_print("[eHPI test]Chip ID/Revision ID = %x", reg_value );

    msdc_dbg_print("[eHPI test]2. Request FW-Own back" );
    kalDevRegWrite(MCR_WHLPCR, WHLPCR_INT_EN_SET);//HAL_MCR_WR(prAdapter, MCR_WHLPCR, WHLPCR_INT_EN_SET);


#if 1
    {
        DCL_HANDLE handle_eint1;

        //handle_eint1 = DclGPIO_Open(DCL_GPIO,MT5931_EINT); // MT5931,WIFI_EINT
        //DclGPIO_Control(handle_eint1,GPIO_CMD_SET_MODE_6,0);
        //DclGPIO_Control(handle_eint1,GPIO_CMD_SET_MODE_3,0);
        //DclGPIO_Close(handle_eint1);

        EINT_Registration( MT5931_EINT_NUM,
                           KAL_FALSE,     /* DbounceEn */
                           KAL_TRUE,    /* ACTPolarity */
                           test_hisr,
                           KAL_FALSE/* AutoUnmask */ );
        /* set new debounce value */
        EINTaddr(MT5931_EINT_NUM) |= 2;
        /* Set Software debounce time 0 */
        EINT_SW_Debounce_Modify(MT5931_EINT_NUM, 0);

        // James modify for setting GPIO52 enable
        kal_sleep_task(10);


    }
#endif
    msdc_dbg_print("[%s %d]", __FUNCTION__, __LINE__);
    wndrv_wifi_hifsys_init();
    ret = kalDevRegWrite(MCR_WHLPCR, WHLPCR_INT_EN_SET);

    if ( wndrv_prepare_test( 3 ) == -1 )    /* item 3 for intr loopback test */
    {
        msdc_dbg_print("Test #1: FW cannot do the test.\n");
        //ASSERT(0);
    }

#if 1
    /* Loopback test TXRX*/
    fgIsPass = 1;
    kalDevRegRead(WHCR, &reg_value);//HAL_MCR_RD( prAdapter, WHCR, &reg_value );
    kalDevRegWrite(WHCR, reg_value | 0x00010000);//HAL_MCR_WR( prAdapter, WHCR, reg_value | 0x00010000 ); //Enable RX_Enhance_Mode
    kalDevRegRead(WHCR, &reg_value);//HAL_MCR_RD( prAdapter, WHCR, &reg_value );
    msdc_dbg_print("WHCR: %x\n", reg_value);
    msdc_dbg_print("[eHPI test]>>WIFI HIFSYS Loopback test");

    u2Packet_Len = TEST_PACKET_MIN_LENGTH;

    do
    {
        u2Packet_Len = u2Packet_Len < TEST_PACKET_MAX_LENGTH ? u2Packet_Len += 4 : TEST_PACKET_MIN_LENGTH;
        data_type = u4Pass % 10;
        TX_DMA = (u4Pass + 3) % 3;
        RX_DMA = (u4Pass + 2) % 2;
        TX_DMA = 1;
        RX_DMA = 1;

        //TX with DMA or MCU Start
        if (TX_DMA)
        {
            u4DmaLen = u2Packet_Len;
            u4DmaOffset1 = CPU_CACHE_LINE_SIZE - ((kal_uint32)ucDmaBuf & CPU_CACHE_LINE_SIZE_MASK);

            //1. 32byte non-ailgn block
            if ( (u4DmaOffset1 != 0) && (u4DmaOffset1 != CPU_CACHE_LINE_SIZE) )
            {
                u4DmaLen -= u4DmaOffset1;
            }

            //2. 32byte-align block, Only 32byte-align block will be TX
            u4DmaOffset2 = u4DmaLen & CPU_CACHE_LINE_SIZE_MASK;
            //u4DmaLen -=u4DmaOffset2;
            // generate test frame
            wndrv_generate_test_frame(ucDmaBuf + u4DmaOffset1, u4DmaLen, (Data_Pattern) data_type);
            kalDevRegWrite(WEHTCR, ALIGN_32(u4DmaLen));//HAL_MCR_WR(prAdapter, WEHTCR, ALIGN_32(u4DmaLen));
            //kalDevPortWriteData( WTDR0, ALIGN_4(u4DmaLen), &ucDmaBuf[u4DmaOffset1] );
            HAL_PORT_WR( WTDR0, u4DmaLen, ucDmaBuf + u4DmaOffset1);
            kal_mem_cpy(pucTXBuf, ucDmaBuf + u4DmaOffset1, u4DmaLen);
            //3. remain 32byte non-align block
            /*pucTXBuf += u4DmaLen;
            u4DmaLen = u4DmaOffset2;

            if( u4DmaLen != 0)
            {
                kalDevPortWriteData(MCR_WTDR0, u4DmaLen, pucTXBuf);
            }*/
        }
        else
        {
            u4DmaLen = u2Packet_Len;
            u4DmaOffset1 = 0;
            wndrv_generate_test_frame(pucTXBuf, u4DmaLen, (Data_Pattern) data_type);
            kalDevRegWrite(WEHTCR, u4DmaLen);//HAL_MCR_WR( prAdapter, WEHTCR, u4DmaLen );
            HAL_PORT_WR( WTDR0, u4DmaLen, pucTXBuf);
        }

        //TX with DMA or MCU END

        counter = 0;

        while (1)
        {
            kalDevRegRead(WHISR, &reg_value);//HAL_MCR_RD( prAdapter, WHISR, &reg_value );

            if ( reg_value & 0x1 ) /* check TX0 TX1 done */
            {
                kalDevRegRead(WTSR0, &reg_value);//HAL_MCR_RD( prAdapter, WTSR0, &reg_value );
                //WNDRV_PROMPT_TRACE0( TRACE_INFO, "[eHPI test]>> TX Done");
            }
            else if ( reg_value & 0x2 ) /* check RX0 RX1 done */
            {
                kalDevRegRead(WTSR0, &reg_value);//HAL_MCR_RD( prAdapter, WTSR0, &reg_value );
                kal_sleep_task(10);
                kalDevRegRead(WRPLR, &reg_value);//HAL_MCR_RD( prAdapter, WRPLR, &reg_value );
                kalDevRegWrite(WEHTCR, reg_value);//HAL_MCR_WR( prAdapter, WEHTCR, reg_value );

                if (RX_DMA)
                {
                    u4DmaOffset1 = CPU_CACHE_LINE_SIZE - ((kal_uint32)ucDmaBuf & CPU_CACHE_LINE_SIZE_MASK);
                    reg_value = (reg_value + 31) & ~31u;
                    HAL_PORT_RD(WRDR0, reg_value, ucDmaBuf + u4DmaOffset1);
                    kal_mem_cpy(pucRXBuf, ucDmaBuf + u4DmaOffset1, u4DmaLen);
                }
                else
                {
                    HAL_PORT_RD(WRDR0, reg_value, &pucRXBuf[0]);
                }

                break;
            }
            else
            {
                kal_sleep_task(10);
                kalDevRegWrite(WHIER, 0xffffff17);//HAL_MCR_WR( prAdapter, WHIER, 0xffffff17 );

                if ( counter++ > 1024 )
                {
                    msdc_dbg_print("[eHPI test]>> loopback test fail");
                    fgIsPass = 0;
                    DclSDIO_Close(handle_sdio);//wlanAdapterStop(prAdapter);
                    return;
                }
            }
        }

        counter = 0;
        reg_value = 0;

        for (i = 0; i < (u4DmaLen - 16); i++)
        {
            u4Value = pucTXBuf[i + 16] - pucRXBuf[i + 12];

            if (u4Value == 0)
            {
                counter++;
            }
            else
            {
                reg_value ++;
                msdc_dbg_print("[eHPI test] Data Compare error, TX Mode: %x, RX Mode\n", TX_DMA, RX_DMA);
                return;//ASSERT(0);
            }
        }

        msdc_dbg_print("[eHPI test] Data Compare OK, TX Mode: %x, RX Mode\n", TX_DMA, RX_DMA);
        kalDevRegWrite(WHIER, 0xffffff17);//HAL_MCR_WR( prAdapter, WHIER, 0xffffff17 );
        kal_sleep_task(100);
        u4Pass++ ;
        msdc_dbg_print("[eHPI test]packets pass: %x", u4Pass );
    }
    while (u4Pass < loopback_times);

    if ( fgIsPass == 1 )
    {
        msdc_dbg_print("[eHPI test]Total packets pass: 0x%x", u4Pass );
        msdc_dbg_print("[eHPI test]Each Test Patern pass: 0x%x", u4Pass);
        msdc_dbg_print("[eHPI test]TX DMA->RX DMA pass: 0x%x", u4Pass );
        msdc_dbg_print("[eHPI test]TX DMA->RX MCU pass: 0x%x", u4Pass );
        msdc_dbg_print("[eHPI test]TX MCU->RX DMA pass: 0x%x", u4Pass );
        msdc_dbg_print("[eHPI test]TX MCU->RX MCU pass: 0x%x", u4Pass );
        msdc_dbg_print("[eHPI test]Packet size 200 - 1500 loop count: 0x%x", u4Pass);
    }

    DclSDIO_Close(handle_sdio);//wlanAdapterStop(prAdapter);
    //    free_ctrl_buffer(pucTXBuf);
    //    free_ctrl_buffer(pucRXBuf);
#endif

    msdc_dbg_print("[%s %d]END", __FUNCTION__, __LINE__);
}


#endif

#ifdef DRV_MSDC_BT

#define MSC_CFG		(MSDC_ADRS+0x60)
#define MSC_CMD	(MSDC_ADRS+0x64)

#define MSC_CFG_SIEN			0x0001
#define MSC_CFG_PMODE		0x8000

kal_uint8 msdc_dmaport, msdc_dmaport2;
DMA_INPUT msdc_input, msdc_input2;
DMA_HWMENU msdc_menu, msdc_menu2;
kal_uint32 tempReg;

#pragma arm section zidata = "NONCACHEDZI",  rwdata = "NONCACHEDRW"
kal_uint32 msdc_bt_buffer[128];
#pragma arm section zidata, rwdata

msdc_bt()
{
    kal_uint32 loopIndex2;
    kal_uint32 baseAddrSpace;
    dbg_print("MSDC_bt start\n\r");

    //baseAddrSpace = MSDC2_base - MSDC_base;

    /*turn on MSDC power gating*/
#ifdef __OLD_PDN_ARCH__
    DRVPDN_Disable(DRVPDN_CON1, DRVPDN_CON1_MSDC, PDN_MSDC);
#else
    DRVPDN_Disable(PDN_MSDC);
#endif

    //DRVPDN_Disable(DRVPDN_CON0,DRVPDN_CON0_MSDC2,PDN_MSDC2);

    if (NULL == msdc_dmaport)
    {
        msdc_dmaport = DMA_GetChannel(DMA_MSDC);
        msdc_menu.TMOD.burst_mode = KAL_TRUE;
        msdc_menu.TMOD.cycle = 0x4;
        msdc_menu.master = DMA_MSDC;
        msdc_menu.addr = (kal_uint32)msdc_bt_buffer;
        msdc_input.type = DMA_HWRX;
        msdc_input.size = DMA_LONG;
        msdc_input.count = 128;
        msdc_input.menu = &msdc_menu;


        //msdc_dmaport2 = DMA_GetChannel(DMA_MSDC2);
        //msdc_menu2.TMOD.burst_mode = KAL_TRUE;
        //msdc_menu2.TMOD.cycle = 0x4;
        //msdc_menu2.master = DMA_MSDC2;
        //msdc_menu2.addr = (kal_uint32)msdc_bt_buffer;
        //msdc_input2.type = DMA_HWRX;
        //msdc_input2.size = DMA_LONG;
        //msdc_input2.count = 128;
        //msdc_input2.menu = &msdc_menu2;

    }



    /*
    	0x81110000 = 0x1aa20021
    	0x81110004 = 0x2
    	0x81110010 = 0x010F0008
    	0x81110014 = 0x01000036
    	0x81110020 = 0x28038200
    	0x81110028 = 0x00048200
    	write 0x02898 to 0x81110024 to write single block in 4bit SD mode
    */

    /*
    	0x81110000 = 0x1aa20021
    	0x81110004 = 0x2
    	0x81110010 = 0x010F0008
    	0x81110014 = 0x01000036
    	0x81110020 = 0x28038200
    	0x81110028 = 0x0
    	write 0x0891 to 0x81110024 to read single block in 4bit SD mode
    */

    /*MSDC 1*/

    /*configure DMA*/
    msdc_input.type = DMA_HWTX;
    DMA_Config_B2W(msdc_dmaport, &msdc_input, KAL_TRUE, KAL_FALSE);
    DRV_WriteReg32(MSDC_CFG, 0x1aa20021);
    DRV_WriteReg32(MSDC_STA, 0x2);
    DRV_WriteReg32(MSDC_PS, 0x010F0008);
    DRV_WriteReg32(MSDC_IOCON, 0x01000036);
    DRV_WriteReg32(SDC_CFG, 0x28038200);
    DRV_WriteReg32(SDC_ARG, 0x00048200);
    DRV_WriteReg32(SDC_CMD, 0x02898);

    /*wait data transfer*/
    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    /*read out CMDSTA and DATSTA*/
    tempReg = DRV_Reg32(SDC_CMDSTA);
    tempReg = DRV_Reg32(SDC_DATSTA);

    DMA_Stop(msdc_dmaport);
    /*stop MSDC DMA and reset MSDC*/
    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_DRQEN);
    DRV_SetBits32(MSDC_CFG, MSDC_CFG_RST);

    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_RST);

    msdc_input.type = DMA_HWRX;
    DMA_Config_B2W(msdc_dmaport, &msdc_input, KAL_TRUE, KAL_FALSE);
    DRV_WriteReg32(MSDC_CFG, 0x1aa20021);
    DRV_WriteReg32(MSDC_STA, 0x2);
    DRV_WriteReg32(MSDC_PS, 0x010F0008);
    DRV_WriteReg32(MSDC_IOCON, 0x01000036);
    DRV_WriteReg32(SDC_CFG, 0x28038200);
    DRV_WriteReg32(SDC_ARG, 0x0);
    DRV_WriteReg32(SDC_CMD, 0x0891);

    /*wait data transfer*/
    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    /*read out CMDSTA and DATSTA*/
    tempReg = DRV_Reg32(SDC_CMDSTA);
    tempReg = DRV_Reg32(SDC_DATSTA);

    DMA_Stop(msdc_dmaport);
    /*stop MSDC DMA and reset MSDC*/
    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_DRQEN);
    DRV_SetBits32(MSDC_CFG, MSDC_CFG_RST);

    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_RST);

    /*MS test*/
    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_MSDC);
    DRV_SetBits(MSC_CFG, (MSC_CFG_PMODE | MSC_CFG_SIEN));
    DRV_WriteReg(MSC_CMD, 0x20200);

    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    DRV_SetBits32(MSDC_CFG, MSDC_CFG_RST);

    for (loopIndex2 = 0; 4000 > loopIndex2; loopIndex2++);

    DRV_ClearBits32(MSDC_CFG, MSDC_CFG_RST);


    /*MSDC 2*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    dbg_print("msdc_bt end\n\r");




}
#endif

#ifdef MSDC_SDIO_DVT
extern void test_sdio_ini(void );

void MSDC_DVT_SDIO_test(void)
{
    test_sdio_ini();
}
#endif

#ifdef MSDC2_SDIO_DVT
extern void test_sdio_ini(void );

void MSDC2_DVT_SDIO_test(void)
{
    test_sdio_ini();
}
#endif

#ifdef __MSDC_BASIC_LOAD__



void ssdbg1_main_msdc(task_entry_struct *task_entry_ptr)
{
    SDC_CMD_STATUS status;
    ilm_struct current_ilm;
    ssdbg1_localpara_struct *paraptr;
    kal_uint32 my_index;

    kal_uint32 i = 0;
    double	bestReadThroughput4Bit, worstReadThroughput4Bit, bestWriteThroughput4Bit, worstWriteThroughput4Bit;
    kal_uint32 offset = 0, blkaddr, idx, loop;
    char str[30];

    /*
    #ifdef MSDC_SDIO_DVT
    MSDC_DVT_SDIO_test();
    gMSDC_Handle->mIsInitialized = KAL_FALSE;
    waitingSDIOTest = KAL_FALSE;
    #endif

    if(waitingSDIOTest){
    kal_sleep_task(20);
    }
    */

    kal_get_my_task_index (&my_index);
    stack_set_active_module_id ( my_index, MOD_SSDBG1 );

    //
    // Initialize ILM, and timer
    //
    stack_init_timer(&ssdbg1_context.ssdbg1_timer0, "SSDBG1 Timer0", MOD_SSDBG1);

    stack_start_timer(&ssdbg1_context.ssdbg1_timer0, 0, 10);

    while (1)
    {
        kal_uint32 input, input2;
        kal_uint32 addr;

        MSDC_PDNControl(KAL_FALSE);

        dbg_print("\r\n");
        dbg_print("*********************************************************\r\n");
        dbg_print("*                                                       *\r\n");
        dbg_print("*                MT6280 MSDC Basicload                  *\r\n");
        dbg_print("*                                                       *\r\n");
        dbg_print("*********************************************************\r\n");

        dbg_print("============================\r\n");
        dbg_print(" 1  mount test...\r\n");
        dbg_print(" 2  reg default test...\r\n");
        dbg_print(" 3  read single test...\r\n");
        dbg_print(" 4  write single test...\r\n");
        dbg_print(" 5  read multi test...\r\n");
        dbg_print(" 6  write multi test...\r\n");
        dbg_print(" 7  set clock/odc...\r\n");
        dbg_print(" 8  1-4 bit BUS test...\r\n");
        dbg_print(" 9  read/write stress test...\r\n");
        dbg_print("10  non-4N test...\r\n");
        dbg_print("11  cache test...\r\n");
        dbg_print("12  mount stress test...\r\n");
        dbg_print("13  clock stress test...\r\n");
        dbg_print("14  CLKPAD_RED test...\r\n");
        dbg_print("15  FAT fastformat test...\r\n");
        dbg_print("16  DMA.fix test...\r\n");
        dbg_print("17  error test...\r\n");
        dbg_print("18  odd-size test...\r\n");
        dbg_print("19  burst type test...\r\n");
        dbg_print("20  erase test...\r\n");
        dbg_print("21  gpio test...\r\n");
        dbg_print("22  \r\n");
        dbg_print("23  throughput test...\r\n");
        dbg_print("24  SD CMD test...\r\n");
        dbg_print("25  MSDC initialize...\r\n");
        dbg_print("26  dump register...\r\n");
        dbg_print("27  set block number...\r\n");
        dbg_print("28  edit script...\r\n");
        dbg_print("29  sdio initialize test...\r\n");
        dbg_print("30  sdio read/write test...\r\n");
        dbg_print("31  sdio interrupt test...\r\n");
        dbg_print("32  sdio MT5931 1-bit test...\r\n");
        dbg_print("33  sdio MT5931 4-bit test...\r\n");
        dbg_print("34  memory card sequential read...\r\n");
        dbg_print("35  memory card sequential write...\r\n");
        dbg_print("36  memory card random read...\r\n");
        dbg_print("37  memory card random write...\r\n");
        dbg_print("============================\r\n");

        dbg_print("input:");
        //input = U_GetUARTByte(uart_port1);
        msdc_dbg_input(&input);
        dbg_print("%d\r\n", input);

        switch (input)
        {
            case 1:
                sdtestcase1();
                break;

            case 2:
                sdtestcase2();
                break;

            case 3:
                sdtestcase3(rand()%gSD->mCSD.capacity / 512 - 1, msdc_sector_buf1);;
                break;

            case 4:
                sdtestcase4(0, msdc_sector_buf1, msdc_sector_buf2);
                break;

            case 5:
                sdtestcase5(0, msdc_uncachedBuf1);
                break;

            case 6:
                sdtestcase6(0, msdc_uncachedBuf1, msdc_uncachedBuf2);
                break;

            case 7:
                sdtestcase7();
                break;

            case 8:
                sdtestcase8();
                break;

            case 9:
                sdtestcase9();
                break;

            case 10:
                sdtestcase10();
                break;

            case 11:
                sdtestcase11();
                break;

            case 12:
                sdtestcase12();
                break;

            case 13:
                dbg_print("Input a test round:");
                msdc_dbg_input(&input);
                dbg_print("%c\r\n", input);

                dbg_print("Input a count of one round:");
                msdc_dbg_input(&input2);
                dbg_print("%c\r\n", input2);

                for (i = 0; i < input; i++)
                {
                    status = sdtestcase13(input2);

                    if (status != NO_ERROR)
                        break;
                }

                break;

            case 14:
                sdtestcase14();
                break;

            case 15:
                sdtestcase15();
                break;

            case 16:
                sdtestcase16();
                break;

            case 17:
                sdtestcase17();
                break;

            case 18:
                sdtestcase18();
                break;

            case 19:
                sdtestcase19();
                break;

            case 20:
                sdtestcase20(0, testsectors);
                break;

            case 21:
                sdtestgpio2();
                break;

            case 22:

                break;

            case 23:
                dbg_print("Input a test round:");
                msdc_dbg_input(&input);
                dbg_print("%c\r\n", input);

                sdtestcase21(input);
                break;

            case 24:
                sdtestcase22();
                break;

            case 25:
                i = 0;
                gMSDC_Handle->mIsInitMSDC = KAL_FALSE;
                gMSDC_Handle->mIsInitialized = KAL_FALSE;
                gMSDC_Handle->msdc_clkTuneUpperBund = MSDC_CLOCK / 2;
                MSDC_PDNControl(KAL_FALSE);
                kal_sleep_task(1);



                MSDC_LSD_SetBits32(MSDC_CFG, MSDC_CFG_RST);

                while (MSDC_Reg32(MSDC_CFG) & 0x02)
                {
                    i++;
                }

                dbg_print("%d\r\n", i);

                DclSD_Initialize();
                break;

            case 26:

                dbg_print("\r\n0x");

                while (1)
                {
                    input = U_GetUARTByte(uart_port1);

                    if (input == 0x0d || input == 0x0a)
                        break;

                    if (input == ESCKEY)
                        return;

                    str[offset++] = input;
                    dbg_print("%c", input);
                }

                str[offset] = 0;

                dbg_print("\r\n");
                sscanf(str, "%x", &input2);

                dbg_print("\r\n %x", MSDC_Reg32(input2));
                break;

            case 27:
                dbg_print("input a block number:\r\n");
                msdc_dbg_input(&testblnum);
                dbg_print("%c\r\n", testblnum);
                break;

            case 28:
                dbg_print("input test case number:(ESC to cancel)\r\n");

                while (1)
                {

                    msdc_dbg_input(&input);



                }

                break;

            case 29:

                status = vSDIOInitialisation_Test();
                break;

            case 30:
                break;

            case 31:
                //status = vSDIOInterrupt_Test();
                break;

            case 32:
#ifdef __MSDC_SD_SDIO__
                gMSDC_Handle->trySingleLine = KAL_TRUE;
                SDIO_test_main_MT5931_SDIOISR(BIT_1W);
                dbg_print("\r\n\r\n");

                //gMSDC_Handle->trySingleLine = KAL_FALSE;
                //SDIO_test_main_MT5931_SDIOISR(BIT_4W);
                //dbg_print("\r\n\r\n");
#endif
                break;

            case 33:
#ifdef __MSDC_SD_SDIO__
                gMSDC_Handle->trySingleLine = KAL_FALSE;
                SDIO_test_main_MT5931_SDIOISR(BIT_4W);
                dbg_print("\r\n\r\n");
#endif

                break;

                //
                // sequential read.
                //
            case 34:

                dbg_print("\r\nStart address:");
                msdc_dbg_input(&input);
                dbg_print("%c\r\n", input);

                dbg_print("\r\nTransfer length:");
                msdc_dbg_input(&input2);
                dbg_print("%c\r\n", input2);



                break;

            case 35:

                break;

            case 36:

                break;

                //
                // random read/write.
                //
            case 37:

                while (1)
                {

                    idx = rand() % 4;
                    blkaddr = rand() % gSD->mCSD.capacity / 512 - 1;

                    testblnum = 1;
                    loop = rand() % 10;

                    for (i = 0; i < loop; i++)
                        testblnum *= 2;

                    if (blkaddr < 0)
                        blkaddr = 0;

                    if (blkaddr + testblnum >= gSD->mCSD.capacity / 512)
                        blkaddr = gSD->mCSD.capacity / 512 - testblnum - 1;

                    switch (idx)
                    {

                        case 0:
                            status = sdtestcase3(blkaddr, msdc_sector_buf1);

                            if (status != NO_ERROR)
                                goto EXIT;

                            break;

                        case 1:
                            status = sdtestcase4(blkaddr, msdc_sector_buf1, msdc_sector_buf2);

                            if (status != NO_ERROR)
                                goto EXIT;

                            break;

                        case 2:
                            status = sdtestcase5(blkaddr, msdc_uncachedBuf1);

                            if (status != NO_ERROR)
                                goto EXIT;

                            break;

                        case 3:
                            status = sdtestcase6(blkaddr, msdc_uncachedBuf1, msdc_uncachedBuf2);

                            if (status != NO_ERROR)
                                goto EXIT;

                            break;

                        default:
                            dbg_print("\r\nswitch error\r\n");
                            break;
                    }
                }

            EXIT:

                if (status != NO_ERROR)
                    msdc_dbg_print("[%s]Result: FAIL!!! (err=%d)", __FUNCTION__, status);
                else
                    msdc_dbg_print("[%s]Result: PASS... ", __FUNCTION__);


                break;

            default:
                break;
        }

    }

    while (1)
    {

        //MSDC_DVT_sleepModeCardDetectionTestMT6268A();
        //receive_msg_ext_q(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
        //msg_receive_extq(task_info_g[task_entry_ptr->task_indx].task_ext_qid, &current_ilm );
        msg_receive_extq(&current_ilm);

        switch (current_ilm.msg_id)
        {

            case MSG_ID_MSDC_CARD_DETECT_IND:
                MSDC_GetCardStatus(&MSDC_Blk[0], 0);
                bestReadThroughput = 0;
                worstReadThroughput = 0;
                bestWriteThroughput = 0;
                worstWriteThroughput = 0;
                dbg_print("card plug in/out");
                MSDC_Blk[0].trySingleLine = KAL_FALSE;
                MSDC_DVT_readWrite();
                bestReadThroughput4Bit = bestReadThroughput;
                bestReadThroughput = 0;
                worstReadThroughput4Bit = worstReadThroughput;
                worstReadThroughput = 0;
                bestWriteThroughput4Bit = bestWriteThroughput;
                bestWriteThroughput = 0;
                worstWriteThroughput4Bit = worstWriteThroughput;
                worstWriteThroughput = 0;
                MSDC_Blk[0].trySingleLine = KAL_TRUE;
                MSDC_Blk[0].mIsInitialized = KAL_FALSE;
                MSDC_DVT_readWrite();

                dbg_print("4 bit mode:");
                dbg_print("\r\nwrite best: %f, worst:%f\r\n", bestWriteThroughput4Bit, worstWriteThroughput4Bit);
                dbg_print("\r\nread best: %f, worst:%f\r\n", bestReadThroughput4Bit, worstReadThroughput4Bit);
                dbg_print("1 bit mode:");
                dbg_print("\r\nwrite best: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);
                dbg_print("\r\nread best: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);
                break;

            default:
                break;
        }

        free_ilm(&current_ilm);
    }
}


#ifdef DRV_MSDC_MT6238_SERIES
void MSDC2_DVT_readWrite(void);


void
ssdbg2_main_msdc( task_entry_struct * task_entry_ptr )
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#ifdef MSDC2_SDIO_DVT
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
}

void MSDC2_DVT_readWrite(void)
{
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(NOT_4BYTES_ALIGN)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if 0 // read & write testing
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if 1//write 
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(NOT_4BYTES_ALIGN)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //write
/* under construction !*/
#if 1 // read test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif  // read test
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

}
#else
void ssdbg2_main_msdc ( task_entry_struct * task_entry_ptr )
{
}
#endif
#endif

#else //this is the original MSDC test code full set

void ssdbg1_main_msdc ( task_entry_struct * task_entry_ptr )

{



#ifdef MULTIPLE_WRITE_TEST
    gMSDC_Handle->mIsPresent = KAL_TRUE;
    simple_multi_write_test();
    return;
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

    //MSDC_Initialize();
    //SD_Initialize();




#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else

    {
        kal_int32 i, j, result = 0, count = 0;
        kal_uint32 access = 17893;
        FS_HANDLE hFile = 0, wFile = 0;
        kal_wchar full_name[100];
        kal_uint32  file_size, len, total_len;
        kal_uint32 time_1, time_2;
        double rate;
        volatile kal_bool format = 0;
        kal_uint8 offset1 = 0, offset2 = 0;
        kal_uint32 timeUsedinFS;
        int card;
        kal_uint8 path[10];
        FS_DiskInfo info;

#if 0 //defined(MTK_FORMAT)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#ifdef TRANSCEND_CARD_ISSUE
        j = 0;

        if (gMSDC_Handle->mIsInitialized)
        {
            while (1)
            {
                result = FS_SdDrv.ReadSectors(gMSDC_Handle, 0x200, 4, w);
                //result = FS_SdDrv.ReadSectors(gMSDC_Handle,0x100000,4,w);
                //result = FS_SdDrv.ReadSectors(gMSDC_Handle,0x700000,4,w);
                result = FS_SdDrv.ReadSectors(gMSDC_Handle, 0xf02c80, 4, w);

                /*
                for(i = 0; i<10; i++){
                	w[i] = w[i]+1;
                }
                result = FS_SdDrv.WriteSectors(gMSDC_Handle,0xf04c80,4,w);
                result = FS_SdDrv.ReadSectors(gMSDC_Handle,0xf04c80,4,r);
                */
                for (i = 0; i < 10; i++)
                {
                    if (w[i] !=  x[i])
                    {
                        dbg_print("%d-th byte has different in %d-th turn,%d, %d\r\n", i, j + 1, result, clkNeedB4Data);
                    }
                }

                if (w[0] != x[0])
                {
                    errorCount ++;
                    dbg_print("error rate %d/%d\r\n", errorCount, j);
                }

                j++;

                if ((j & 0xff) == 0)
                {
                    dbg_print("finish %d-th turns\r\n", j);
                }

            }

        }
        else
        {
            while (1);
        }

#endif

#ifdef WRITE_ALL_ZERO_DATA
        j = 0;
        //if(gMSDC_Handle->mIsInitialized){
        DumpDiskInfo("d:\\");
        /*make all zero data*/
        kal_mem_set(allZeroDataArray, 0, 512);
        i = min(gSD->mCSD.capacity / 512, 50);

        for (j = 0; j < i; j++)
        {
            result = FS_SdDrv.WriteSectors(gMSDC_Handle, j, 1, allZeroDataArray);

            if (0 != result)
            {
                dbg_print("write %d-th sector fail \r\n", j);
                break;
            }
        }

        if (0 == result)
        {
            dbg_print("clear all sector to zero doen\r\n");
        }

        while (1);

        //}
        //else{
        //	while(1);
        //}
#endif


        result = FS_TestMSDC(gMSDC_Handle);

        if (result < FS_NO_ERROR)
        {
            dbg_print("memory card card not present %d !!\r\n", result);

            while (1)
                kal_sleep_task(1000);
        }

        card = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);

        if (card >= FS_NO_ERROR)
        {
            kal_wsprintf((WCHAR*) path, "%c:\\", card);

            result = FS_GetDiskInfo((WCHAR*) path, &info, FS_DI_BASIC_INFO | FS_DI_FREE_SPACE);

            if (result < RTF_NO_ERROR)
            {
                ASSERT(0);
            }


        }
        else
        {
            dbg_print("memory card card not present!!\r\n");

            while (1)
                kal_sleep_task(1000);
        }

#ifdef HW_FAST_FORMAT_TEST

        while (1)
        {
            time_1 = drv_get_current_time();
            result = FS_GeneralFormat((WCHAR*) path, FS_FORMAT_HIGH, NULL);

            if (FS_NO_ERROR == result)
            {
                time_2 = drv_get_current_time();
                dbg_print("format done %d, %f\n\r", time_2 - time_1, (double)(0.0005 * writeSectorsCount * 32000) / (double)(writeTimeCount));
                writeSectorsCount = writeTimeCount = 0;
                kal_sleep_task(1500);
            }
            else
            {
                dbg_print("format failed: %d \n\r", result);

                while (1)
                    kal_sleep_task(1000);

            }
        }

#endif
        //DumpDiskInfo("d:\\");
        kal_wsprintf(full_name, "%c:\\Write.bin", card);

        for (i = 0; i < LEN + 3; i++)
        {
            w[i + offset1] = i % 256;
            r[i + offset2] = 0;

#ifdef	CACHED_TEST
            cached_w[i + offset1] = i % 256;
            cached_r[i + offset2] = 0;
#endif

        }

#if defined(NOT_4BYTES_ALIGN)
        // test W to B or B to W(DMA)
        offset1 = (kal_uint32)w % 4;

        if (offset1 == 0)
            offset1 = 1;
        else
            offset1 = 0;

        offset2 = (kal_uint32)r % 4;

        if (offset2 == 0)
            offset2 = 1;
        else
            offset2 = 0;

        for (i = 0; i < LEN + 3; i++)
        {
            w[i + offset1] = i % 256;
            r[i + offset2] = 0;
        }

#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

        while (1)
        {

#if 0 // read & write testing
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif

#if 1//write 

            count++;
            //Search_Dir(L"C:\\");
            FS_Delete(full_name);
#ifdef	CACHED_TEST

            if (KAL_TRUE == cachedTest)
                cachedTest = KAL_FALSE;
            else
                cachedTest = KAL_TRUE;

            if (KAL_TRUE == cachedTest)
                dbg_print("\r\n===========Cached Write Test Start(%d) ====================\r\n", count);
            else
#endif
                dbg_print("\r\n==================Write Test Start(%d) ====================\r\n", count);

            hFile = FS_Open(full_name, FS_CREATE | FS_READ_WRITE);

            if (hFile <= 0)
                continue;

            //ASSERT(hFile>0);

#if defined(NOT_4BYTES_ALIGN)
            // test W to B or B to W(DMA)
            offset1 = (kal_uint32)w % 4;

            if (offset1 == 0)
                offset1 = 1;
            else
                offset1 = 0;

            offset2 = (kal_uint32)r % 4;

            if (offset2 == 0)
                offset2 = 1;
            else
                offset2 = 0;

            for (i = 0; i < LEN + 3; i++)
            {
                w[i + offset1] = i % 256;
                r[i + offset2] = 0;
            }

#endif
            i = 0;
            total_len = 0;

            kal_get_time(&time_1);

            //readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2 = 0;
            //writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
            while (1)
            {

#ifdef	CACHED_TEST

                if (KAL_TRUE == cachedTest)
                    result = FS_Write(hFile, cached_w + offset1, LEN, &len);
                else
#endif
                    result = FS_Write(hFile, w + offset1, LEN, &len);

                total_len += len;
                i++;

                if (result < 0 )
                {
                    if (result == RTF_DISK_FULL)
                        dbg_print("Disk Full %d\r\n", total_len);
                    else
                        dbg_print("write fail %d at: %d \r\n", result, total_len);

                    break;
                }

                if (len != LEN)
                    break;

                if (i % TIMES == 0)
                {
                    kal_get_time(&time_2);
                    rate = (double)(LEN * TIMES) / (double)(time_2 - time_1);
                    dbg_print("write[%d], total: %d, rate %f \r\n", i, total_len, rate / 0.004615);
                    //dbg_print("%d, %d, %d , %d\r\n", writeTime3 , writeTime4 , writeTime5,writeTime6);
                    //readSectorCount = writeSectorCount = readTime = writeTime = writeSectorCount2 = writeTime2= 0;
                    //writeTime3 = writeTime4 = writeTime5 = writeTime6 = 0;
#ifdef	CACHED_TEST

                    if (KAL_TRUE == cachedTest)
                    {
                        if ((rate / 0.004615) > cachedBestWriteThroughput || 0 == cachedBestWriteThroughput)
                            cachedBestWriteThroughput = (rate / 0.004615);

                        if ((rate / 0.004615) < cachedWorstWriteThroughput || 0 == cachedWorstWriteThroughput)
                            cachedWorstWriteThroughput = (rate / 0.004615);
                    }
                    else
#endif
                    {
                        if ((rate / 0.004615) > bestWriteThroughput || 0 == bestWriteThroughput)
                            bestWriteThroughput = (rate / 0.004615);

                        if ((rate / 0.004615) < worstWriteThroughput || 0 == worstWriteThroughput)
                            worstWriteThroughput = (rate / 0.004615);
                    }

                    kal_get_time(&time_1);


                    if (i == TIMES * 5) break;
                }
            }

            FS_Close(hFile);

#ifdef	CACHED_TEST

            if (KAL_TRUE == cachedTest)
                dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestWriteThroughput, cachedWorstWriteThroughput);
            else
#endif
                dbg_print("\r\nbest: %f, worst:%f\r\n", bestWriteThroughput, worstWriteThroughput);

            dbg_print("\r\n==================Write Test End(%d) ====================\r\n", count);
#endif //write

#if 1 // read test

#ifdef	CACHED_TEST

            if (KAL_TRUE == cachedTest)
                dbg_print("\r\n==========Cached Read Test Start(%d) ====================\r\n", count);
            else
#endif
                dbg_print("\r\n==================Read Test Start(%d) ====================\r\n", count);

            timeUsedinFS = 0;
            i = 0;
            total_len = 0;
            hFile = FS_Open(full_name, FS_READ_WRITE);

            if (hFile <= 0)
                continue;

            ASSERT(hFile > 0);

            while (1)
            {
                kal_get_time(&time_1);

#ifdef	CACHED_TEST

                if (KAL_TRUE == cachedTest)
                    result = FS_Read(hFile, cached_r + offset1, LEN, &len);
                else
#endif
                    result = FS_Read(hFile, r + offset2, LEN, &len);

                kal_get_time(&time_2);
                timeUsedinFS += (time_2 - time_1);
                i++;
                total_len += len;

                if (check_read_content)
                {
#ifdef	CACHED_TEST

                    if (KAL_TRUE == cachedTest)
                    {
                        for (j = 0; j < len; j++)
                        {
                            if (cached_r[j + offset2] != cached_w[j + offset1])
                            {
                                dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);

                                while (1);
                            }

                        }
                    }
                    else
#endif
                    {
                        for (j = 0; j < len; j++)
                        {
                            if (r[j + offset2] != w[j + offset1])
                            {
                                dbg_print("read not the same , at: %d, %d, %d, %d \r\n", total_len, j, offset2, offset1);

                                while (1);
                            }

                        }
                    }

                    dbg_print(".");
#ifdef	CACHED_TEST

                    if (KAL_TRUE == cachedTest)
                        memset(cached_r, 0, sizeof(cached_r));
                    else
#endif
                        memset(r, 0, sizeof(r));
                }

                if (result < 0)
                {
                    if (result != RTF_DISK_FULL)
                        dbg_print("read fail %d, at: %d \r\n", result, total_len);
                    else
                        dbg_print("Disk Full \r\n");
                }

                if (len != LEN)
                    break;

                if (i % TIMES == 0)
                {

                    rate = (double)(LEN * TIMES) / (double)timeUsedinFS;
                    dbg_print("read[%d], total: %d, rate: %f \r\n", i, total_len, rate / 0.004615);

#ifdef	CACHED_TEST

                    if (KAL_TRUE == cachedTest)
                    {
                        if ((rate / 0.004615) > cachedBestReadThroughput || 0 == cachedBestReadThroughput)
                            cachedBestReadThroughput = (rate / 0.004615);

                        if ((rate / 0.004615) < cachedWorstReadThroughput || 0 == cachedWorstReadThroughput)
                            cachedWorstReadThroughput = (rate / 0.004615);
                    }
                    else
#endif
                    {
                        if ((rate / 0.004615) > bestReadThroughput || 0 == bestReadThroughput)
                            bestReadThroughput = (rate / 0.004615);

                        if ((rate / 0.004615) < worstReadThroughput || 0 == worstReadThroughput)
                            worstReadThroughput = (rate / 0.004615);
                    }

                    timeUsedinFS = 0;

                    if (i == TIMES * 5) break;
                }
            }

            FS_Close(hFile);

#ifdef	CACHED_TEST

            if (KAL_TRUE == cachedTest)
                dbg_print("\r\nbest: %f, worst:%f\r\n", cachedBestReadThroughput, cachedWorstReadThroughput);
            else
#endif
                dbg_print("\r\nbest: %f, worst:%f\r\n", bestReadThroughput, worstReadThroughput);

            dbg_print("\r\n==================Read Test End(%d) ====================\r\n", count);
            FS_Delete(full_name);
#endif  // read test
        }

        //=======================================//

    }
#endif

}

#endif//MSDC_DVT
#endif//__MSDC_BASIC_LOAD__
