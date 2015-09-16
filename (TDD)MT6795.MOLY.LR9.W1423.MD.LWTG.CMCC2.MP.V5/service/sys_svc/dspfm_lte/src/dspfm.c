/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2013
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
 *   dspfm.c
 *
 * Project:
 * --------
 *   Moly
 *
 * Description:
 * ------------
 *   LTE DSP file management
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
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "kal_public_api.h"
#include "bl_loader.h"
#include "bl_BootInfo.h"
#include "br_GFH_file_info.h"
#include "br_GFH_parser.h"
#include "br_GFH_error.h"
#include "br_GFH_dsp_info.h"
#include "maui_GFH_body.h"
#include "FTL.h"
#include "dspfm.h"
#include "dspfm_public.h"
#ifdef __CCCIFS_SUPPORT__
#include "fs_func.h"
#endif
#ifndef __MAUI_BASIC__
#include "dspfm_trace.h"
#endif

#if defined(MTK_SLEEP_ENABLE) && defined(__X_BOOTING__)
#define SDIO_TEMP_SLEEP_LOCK
#endif

#ifdef SDIO_TEMP_SLEEP_LOCK
#include "sleepdrv_interface.h"
extern kal_uint8 SDIO_debug_flow_handle;
#endif

#if defined(ATEST_ENABLE) && defined(ATEST_DRV_DSPFM)
#define PRINT dbg_print
#else
#define PRINT
#endif

/*
 * Use DHL logging.
 */
#ifndef __MAUI_BASIC__
    #define dspfm_trace_error(...) dhl_trace(TRACE_ERROR, DHL_USER_FLAG_NONE, __VA_ARGS__)
    #define dspfm_trace_warn(...) dhl_trace(TRACE_WARNING, DHL_USER_FLAG_NONE, __VA_ARGS__)
    #define dspfm_trace_info(...)  dhl_trace(TRACE_INFO, DHL_USER_FLAG_NONE, __VA_ARGS__)
    #define dspfm_trace_func(...)  dhl_trace(TRACE_FUNC, DHL_USER_FLAG_NONE, __VA_ARGS__)
#else
    #define dspfm_trace_error(...)
    #define dspfm_trace_warn(...)
    #define dspfm_trace_info(...)
    #define dspfm_trace_func(...)
#endif

#define PAGE_BUFFER_SIZE              (0x1000)        //page 4KB
#define ALIGN_4B_MASK                   (0x3)

#define DSP_FILE_PATH       "W:\\dsp_5_wl_n.bin"
#define CHIP_ID_LEN            6    //MTXXXX
#define PLT_ID_LEN              10    //MTXXXX_SXX
#define PROJ_ID_LEN             6    //WXX.XX

typedef struct{
    kal_bool m_found;
    kal_uint32 m_file_len;
    kal_uint32 m_content_offset;
    kal_uint32 m_begin_page;
    kal_uint32 m_bound_page;
    kal_int32 m_errno;
    kal_char m_dsp_project_id[64];
    kal_char m_dsp_build_time[64];
}dspfm_fileinfo_t;

typedef struct{
    GFH_FILE_INFO_v1 GFHFileInfo;
    GFH_DSP_INFO_v1 GFHDspInfo;
}LTE_DSP_GFH;

extern kal_char* release_verno(void);
extern kal_char* release_bb_chip(void);
extern kal_char* release_bb_sw_ver(void);
extern void dbg_print(kal_char *fmt, ...);
extern BL_Info_Wrapper_st g_pass_info;
extern FTL_FuncTbl ftlFuncTbl;
extern const MAUI_GFH g_maui_gfh;

static kal_mutexid g_dspfm_mutex;
static kal_bool g_dspfm_opened = KAL_FALSE;
static dspfm_fileinfo_t g_dsp_fileinfo = {KAL_FALSE, 0, 0, 0};

#ifdef __CCCIFS_SUPPORT__
static FS_HANDLE f_dsp;
#else
kal_uint32 page_buffer[PAGE_BUFFER_SIZE/4];
#endif /*__CCCIFS_SUPPORT__*/

kal_uint32 dspfm_get_DSP_GFH_length(void)
{
    return sizeof(LTE_DSP_GFH);    
}

kal_bool dspfm_get_fw_ver(kal_char **str)
{
    //This function should be called after DSP boots up
    if(g_dsp_fileinfo.m_found != KAL_TRUE){
        return KAL_FALSE;
    }else{
        *str = g_dsp_fileinfo.m_dsp_project_id;
        return KAL_TRUE;
    }
}

kal_bool dspfm_get_fw_btime(kal_char **str)
{
    //This function should be called after DSP boots up
    if(g_dsp_fileinfo.m_found != KAL_TRUE){
        return KAL_FALSE;
    }else{
        *str = g_dsp_fileinfo.m_dsp_build_time;
        return KAL_TRUE;
    }
}

static kal_bool dspfm_dsp_ver_check(void *dsp_gfh_ptr)
{
    kal_uint8 chip_id[CHIP_ID_LEN];
    kal_uint8 maui_plt_id[PLT_ID_LEN], maui_proj_id[PROJ_ID_LEN];
    kal_uint8 dsp_plt_id[PLT_ID_LEN], dsp_proj_id[PROJ_ID_LEN];
    GFH_DSP_INFO_v1 *pDspInfo;
    kal_char *verno = release_verno();
    kal_char *bb_chip = release_bb_chip();
    kal_char *bb_sw_ver = release_bb_sw_ver();
    kal_uint32 status;
    kal_uint32 i;

    //Try to find DSP info
    status = GFH_Find((kal_uint32)dsp_gfh_ptr, GFH_DSP_INFO, (void *)&pDspInfo);
    if(status != B_OK)
    {
        //Assert if we cannot find DSP GFH 
        EXT_ASSERT(0, status, 0, 0);
    }

    //Find the chip id of primary rom
    for(i=0; *(bb_chip+i)!= 0 ; i++){

        if(*(bb_chip+i) == 'M' && *(bb_chip+i+1) == 'T')
        {
            memcpy(chip_id, (bb_chip+i), sizeof(chip_id));
            break;    
        }
    }

    //Construct the platform id of primary rom
    sprintf(maui_plt_id, "%.6s_%.3s", chip_id, bb_sw_ver);

    //Find the project id of primary rom
    for(i=0; *(verno+i) !=0; i++){

        if(*(verno+i) == 'W')
        {
            memcpy(maui_proj_id, (verno+i), sizeof(maui_proj_id));
            break;
        }
    }

    //Find the platform id of dsp
    for(i=0; i<sizeof(pDspInfo->m_platform_id); i++){

        if(pDspInfo->m_platform_id[i] == 'M' && 
            pDspInfo->m_platform_id[i+1] == 'T' )
        {
            memcpy(dsp_plt_id, &pDspInfo->m_platform_id[i], sizeof(dsp_plt_id));
            break;    
        }
    }
    if(i == sizeof(pDspInfo->m_platform_id)){
        dspfm_trace_error(DSPFM_DSP_GFH_NO_PLT_ID);
    }    

    //Find the project id of dsp
    for(i=0; i<sizeof(pDspInfo->m_project_id); i++){

        if(pDspInfo->m_project_id[i] == 'W')
        {
            memcpy(dsp_proj_id, &pDspInfo->m_project_id[i], sizeof(dsp_proj_id));
            break;    
        }
    }
    if(i == sizeof(pDspInfo->m_project_id)){
        dspfm_trace_error(DSPFM_DSP_GFH_NO_PROJ_ID);
    } 

    //Check platform id is matched, ortherwise assert
    EXT_ASSERT(memcmp(maui_plt_id, dsp_plt_id, sizeof(dsp_plt_id)) == 0, 0, 0, 0);

    //Check project id is matched, otherwise warning
    if(memcmp(maui_proj_id, dsp_proj_id, sizeof(dsp_proj_id)) != 0){
        dspfm_trace_warn(DSPFM_DSP_PROJ_ID_NOT_MATCH);
    }

    //Store DSP info
    memcpy(g_dsp_fileinfo.m_dsp_project_id, pDspInfo->m_project_id, sizeof(pDspInfo->m_project_id));
    memcpy(g_dsp_fileinfo.m_dsp_build_time, pDspInfo->m_build_time, sizeof(pDspInfo->m_build_time));
    
_end:

    return KAL_TRUE;
}


#if defined(__MODEM_ONLY__) ||  defined(__USB_FW_DL_SUPPORT__)

static void dspfm_get_gfh_file_info()
{
    GFH_FILE_INFO_v1 *pGFHFileInfo = (GFH_FILE_INFO_v1 *)LTE_DSP_BIN_BASE;

    /* Sanity test of GFH */
    if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
    {
        dspfm_trace_error(DSPFM_INVALID_GFH_FILE_INFO);
        PRINT("DSPFM:Invalid GFH File Info\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_INVALID_GFH;
        goto _error;
    }

    /* Check file type */
    if(pGFHFileInfo->m_file_type != LTE_DSP_ROM){
        dspfm_trace_error(DSPFM_WRONG_GFH_FILE_TYPE);
        PRINT("DSPFM:file_type is not LTE_DSP_ROM\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_WRONG_GFH_TYPE;
        goto _error;
    }

    /* Check DSP version */
    if(dspfm_dsp_ver_check(pGFHFileInfo) != KAL_TRUE){
        dspfm_trace_error(DSPFM_VERSION_CHECK_FAIL);
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_VERSION_CHECK_FAIL;
        goto _error;
    }

    /* Setup DSP file info*/
    g_dsp_fileinfo.m_found = KAL_TRUE;
    g_dsp_fileinfo.m_content_offset = pGFHFileInfo->m_content_offset;
    g_dsp_fileinfo.m_file_len = pGFHFileInfo->m_file_len;

_error:
    
    return;
}


void dspfm_init()
{
    g_dspfm_mutex = kal_create_mutex("dspfm_mutex");
    
    //Read the DSP file info from GFH
    dspfm_get_gfh_file_info();

    return;
}

/*!
 *  @brief  Open DSP file
 *  @param  none
 *  @return >0 - size of DSP image(not include GFH)
 *              <=0 - error code
 */
kal_int32 dspfm_open()
{
    //Return error if dsp image not found
    if(g_dsp_fileinfo.m_found == KAL_FALSE){       
        return g_dsp_fileinfo.m_errno;
    }

    if(g_dspfm_opened == KAL_FALSE){

        kal_take_mutex(g_dspfm_mutex);
        g_dspfm_opened = KAL_TRUE;
        kal_give_mutex(g_dspfm_mutex);
    }

    return g_dsp_fileinfo.m_file_len - g_dsp_fileinfo.m_content_offset;
}

/*!
 *  @brief  Read size of data to ptr from offset
 *  @param  ptr - destination addr
 *                offset - data offset 
 *                size - data size
 *  @return 0 - success
 *              <0 - error code
 */
kal_int32 dspfm_read(kal_uint32 ptr, kal_uint32 offset, kal_uint32 size)
{
    kal_uint32 r_offset = offset + g_dsp_fileinfo.m_content_offset;

    //DSP file should be opened before read
    if(g_dspfm_opened == KAL_FALSE){
        dspfm_trace_error(DSPFM_FILE_NOT_OPEN);
        return DSPFM_ERR_DSP_FILE_NOT_OPEND;
    }

    if(ptr & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_PTR_NOT_ALIGN);
        PRINT("DSPFM:ptr not aligned\r\n");
        return DSPFM_ERR_DSP_PTR_NOT_4B_ALIGN;
    }

    if(offset & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_OFFSET_NOT_ALIGN);
        PRINT("DSPFM:offset not aligned\r\n");
        return DSPFM_ERR_DSP_OFFSET_NOT_4B_ALIGN;
    }

    //Read data should not exceed file size
    if(r_offset + size >  g_dsp_fileinfo.m_file_len){
        dspfm_trace_error(DSPFM_LENGTH_TOO_LARGE);
        return DSPFM_ERR_DSP_EXCEED_FILE_SIZE;
    }

    //Copy data to user's buffer
    memcpy((kal_uint32 *)ptr, (kal_uint32 *)((kal_uint32)LTE_DSP_BIN_BASE+r_offset), size);
    
    return 0;
}


/*!
 *  @brief  Close DSP file 
 *  @param  none
 *  @return none
 */
void dspfm_close()
{
    if(g_dspfm_opened == KAL_TRUE){

        kal_take_mutex(g_dspfm_mutex);
        g_dspfm_opened = KAL_FALSE;
        kal_give_mutex(g_dspfm_mutex);
    }
}


#elif defined(__CCCIFS_SUPPORT__)

static void dspfm_get_gfh_file_info()
{
    WCHAR FileName[256];
    LTE_DSP_GFH dsp_gfh;
    kal_uint32 ret;
    kal_uint32 read_size;    

    kal_wsprintf(FileName, "%s\0", DSP_FILE_PATH);
    
    f_dsp = FS_Open(FileName, FS_READ_ONLY);

    if(f_dsp < 0){
        dspfm_trace_error(DSPFM_FILE_NOT_OPEN);
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_FILE_OPEN_FAIL;
    }

    ret = FS_Read(f_dsp, (void *)&dsp_gfh, sizeof(LTE_DSP_GFH), &read_size);
    if(ret != FS_NO_ERROR){
        dspfm_trace_error(DSPFM_FILE_READ_FAILED);
        PRINT("DSPFM:Cannot read GFH from file\n\r");
        g_dsp_fileinfo.m_errno =  DSPFM_ERR_DSP_GFH_READ_FAIL;
        goto _error;
    }

    /* Sanity test of GFH */
    if( GFH_FILE_INFO_IsValid(&dsp_gfh.GFHFileInfo) != B_OK )
    {
        dspfm_trace_error(DSPFM_INVALID_GFH_FILE_INFO);
        PRINT("DSPFM:Invalid GFH File Info\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_INVALID_GFH;
        goto _error;
    }

    /* Check file type */
    if(dsp_gfh.GFHFileInfo.m_file_type != LTE_DSP_ROM){
        dspfm_trace_error(DSPFM_WRONG_GFH_FILE_TYPE);
        PRINT("DSPFM:file_type is not LTE_DSP_ROM\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_WRONG_GFH_TYPE;
        goto _error;
    }

    /* Check DSP version */
    if(dspfm_dsp_ver_check(&dsp_gfh) != KAL_TRUE){
        dspfm_trace_error(DSPFM_VERSION_CHECK_FAIL);
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_VERSION_CHECK_FAIL;
        goto _error;
    }

    /* Setup DSP file info*/
    g_dsp_fileinfo.m_found = KAL_TRUE;
    g_dsp_fileinfo.m_content_offset = dsp_gfh.GFHFileInfo.m_content_offset;
    g_dsp_fileinfo.m_file_len = dsp_gfh.GFHFileInfo.m_file_len;

_error:

    FS_Close(f_dsp);
    return;

}


/*!
 *  @brief  Init DSP file manager
 *  @param  none
 *  @return none
 */
void dspfm_init()
{   
    g_dspfm_mutex = kal_create_mutex("dspfm_mutex");

    //Read the DSP file info from GFH
    dspfm_get_gfh_file_info();

    return;
}

/*!
 *  @brief  Open DSP file
 *  @param  none
 *  @return >0 - size of DSP image(not include GFH)
 *              <=0 - error code
 */
kal_int32 dspfm_open()
{
    WCHAR FileName[256];
    kal_uint32 ret;

    if(g_dspfm_opened == KAL_FALSE){

        //Return error if dsp image not found
        if(g_dsp_fileinfo.m_found == KAL_FALSE){       
            return g_dsp_fileinfo.m_errno;
        }

        kal_wsprintf(FileName, "%s\0", DSP_FILE_PATH);
        f_dsp = FS_Open(FileName, FS_READ_ONLY);

        if(f_dsp < 0){
            dspfm_trace_error(DSPFM_FILE_NOT_OPEN);
            return DSPFM_ERR_DSP_FILE_OPEN_FAIL;
        }

        kal_take_mutex(g_dspfm_mutex);
        g_dspfm_opened = KAL_TRUE;
        kal_give_mutex(g_dspfm_mutex);

    }

    //return dsp file size
    return g_dsp_fileinfo.m_file_len - g_dsp_fileinfo.m_content_offset;
    
}

/*!
 *  @brief  Read size of data to ptr from offset
 *  @param  ptr - destination addr
 *                offset - data offset 
 *                size - data size
 *  @return 0 - success
 *              <0 - error code
 */
kal_int32 dspfm_read(kal_uint32 ptr, kal_uint32 offset, kal_uint32 size)
{
    kal_uint32 ret;
    kal_uint8 *dptr = (kal_uint32 *)ptr;
    kal_uint32 read_size;    
    kal_uint32 real_offset = offset+g_dsp_fileinfo.m_content_offset;

    //DSP file should be opened before read
    if(g_dspfm_opened == KAL_FALSE){
        dspfm_trace_error(DSPFM_FILE_NOT_OPEN);
        return DSPFM_ERR_DSP_FILE_NOT_OPEND;
    }

    if(ptr & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_PTR_NOT_ALIGN);
        PRINT("DSPFM:ptr not aligned\r\n");
        return DSPFM_ERR_DSP_PTR_NOT_4B_ALIGN;
    }

    if(offset & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_OFFSET_NOT_ALIGN);
        PRINT("DSPFM:offset not aligned\r\n");
        return DSPFM_ERR_DSP_OFFSET_NOT_4B_ALIGN;
    }

    if(real_offset+size > g_dsp_fileinfo.m_file_len){
        dspfm_trace_error(DSPFM_LENGTH_TOO_LARGE);
        return DSPFM_ERR_DSP_EXCEED_FILE_SIZE;
    }

    //Set the file pointer to offset
    if(FS_Seek( f_dsp, real_offset, FS_FILE_BEGIN) < 0){
        dspfm_trace_error(DSPFM_FILE_SEEK_FAILED);
        PRINT("DSPFM:file seek fail\r\n");
        return DSPFM_ERR_DSP_FILE_SEEK_FAIL;
    }

    //Read file data
    while(size > 0){
        ret = FS_Read(f_dsp, (void *)dptr, size, &read_size);
        if(ret != FS_NO_ERROR){
            dspfm_trace_error(DSPFM_FILE_READ_FAILED);
            return DSPFM_ERR_DSP_READ_DATA_FAIL;
        }

        size -= read_size;
        dptr += read_size;
    };

    return DSPFM_OK;
}

/*!
 *  @brief  Close DSP file 
 *  @param  none
 *  @return none
 */
void dspfm_close()
{
    if(g_dspfm_opened == KAL_TRUE){

        kal_take_mutex(g_dspfm_mutex);
        FS_Close(f_dsp);
        g_dspfm_opened = KAL_FALSE;
        kal_give_mutex(g_dspfm_mutex);
    }
#ifdef SDIO_TEMP_SLEEP_LOCK    
    SleepDrv_SleepEnable(SDIO_debug_flow_handle);
#endif
}

#else /* !__CCCIFS_SUPPORT__ && !__MODEM_ONLY__*/

static kal_uint32 dspfm_get_start_page(kal_uint32 pageNo, kal_uint32 length, kal_uint32 *pNextPage)
{
    kal_uint32  page_size = ftlFuncTbl.FTL_GetPageSize();
    kal_uint32  page_per_block;
    kal_bool goodBlockChecked = KAL_FALSE;

    page_per_block = ftlFuncTbl.FTL_GetBlockSize(0, NULL)/page_size;

    if((length%page_size) != 0)
    {
        return KAL_FALSE;
    }
    
    while(length)
    {
        if(!goodBlockChecked)
        {
            while( ftlFuncTbl.FTL_CheckGoodBlock(pageNo/page_per_block, NULL) == FTL_ERROR_BAD_BLOCK )
            {
                /* Skip the bad block */
                dspfm_trace_func(DSPFM_FLASH_BAD_BLOCK, pageNo/page_per_block);
                PRINT("\n\rDSPFM:Bad block at block %d\n\r", pageNo/page_per_block);

                pageNo = (pageNo/page_per_block+1)*page_per_block;
            }

            goodBlockChecked = KAL_TRUE;
        }
        pageNo++;
        length -= page_size;

        /* Looking for the next good block */
        if ( (pageNo % page_per_block)==0 )
        {
            goodBlockChecked = KAL_FALSE;   
        }
    }

    if(pNextPage)
    {
        *pNextPage = pageNo;
    }

    return KAL_TRUE;
}

/*!
 *  @brief  Read data from specified page to ptr
 *  @param  ptr - destination memory
 *                pageNo - start page to read
 *                length - data length
 *  @return KAL_BOOL
 */
static kal_bool dspfm_read_data(kal_uint32 ptr, kal_uint32 pageNo, kal_uint32 length, kal_uint32 *pNextPage)
{
    kal_uint32  page_size = ftlFuncTbl.FTL_GetPageSize();
    kal_uint32  page_per_block;

    kal_bool goodBlockChecked = KAL_FALSE;

    page_per_block = ftlFuncTbl.FTL_GetBlockSize(0, NULL)/page_size;

    if((length%page_size) != 0)
    {
        return KAL_FALSE;
    }

    if(length == 0)
    {
        return KAL_TRUE;
    }

    while(length)
    {
        if(!goodBlockChecked)
        {
            while( ftlFuncTbl.FTL_CheckGoodBlock(pageNo/page_per_block, NULL) == FTL_ERROR_BAD_BLOCK )
            {
                /* Skip the bad block */
                dspfm_trace_func(DSPFM_FLASH_BAD_BLOCK, pageNo/page_per_block);
                PRINT("\n\rDSPFM:Bad block at block %d\n\r", pageNo/page_per_block);

                pageNo = (pageNo/page_per_block+1)*page_per_block;
            }

            goodBlockChecked = KAL_TRUE;
        }

        if( ftlFuncTbl.FTL_ReadPage(pageNo/page_per_block, pageNo%page_per_block, (kal_uint32*)ptr, NULL) != FTL_SUCCESS )
        {
            dspfm_trace_error(DSPFM_READ_FLASH_FAILED, pageNo/page_per_block, pageNo%page_per_block);
            PRINT("DSPFM:Read error at block %d, page %d\n\r", pageNo/page_per_block, pageNo%page_per_block);
            return KAL_FALSE;
        }

        pageNo++;
        length -= page_size;
        ptr += page_size;

        /* Looking for the next good block */
        if ( (pageNo % page_per_block)==0 )
        {
            goodBlockChecked = KAL_FALSE;   
        }
    }

    if(pNextPage)
    {
        *pNextPage = pageNo;
    }

    return KAL_TRUE;
}

static void dspfm_get_gfh_file_info()
{
    GFH_FILE_INFO_v1 *pGFHFileInfo;
    kal_uint32 page_size = ftlFuncTbl.FTL_GetPageSize();
    kal_uint32 flashBeginPage = g_dsp_fileinfo.m_begin_page;
    kal_uint32 flashBoundPage = g_dsp_fileinfo.m_bound_page;

    pGFHFileInfo = (GFH_FILE_INFO_v1*)page_buffer;

    /* DSP GFH_info should be smaller than one page */
    ASSERT(sizeof(LTE_DSP_GFH) <= page_size);

    /* Read first page (GFH Info) to internal page buffer */
    if( dspfm_read_data((kal_uint32)pGFHFileInfo, flashBeginPage, page_size, NULL) == KAL_FALSE )
    {
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_GFH_READ_FAIL;
        goto _error;
    }

    /* Sanity test of GFH */
    if( GFH_FILE_INFO_IsValid(pGFHFileInfo) != B_OK )
    {
        dspfm_trace_error(DSPFM_INVALID_GFH_FILE_INFO);
        PRINT("DSPFM:Invalid GFH File Info\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_INVALID_GFH;
        goto _error;
    }

    /* Make sure the length of the data is still in the region */
    if( (pGFHFileInfo->m_file_len+page_size-1)/page_size > (flashBoundPage - flashBeginPage +1) )
    {
        dspfm_trace_error(DSPFM_FILE_SIZE_TOO_LARGE);
        PRINT("DSPFM:file_len>bound_addr\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_FILE_SIZE_TOO_LARGE;
        goto _error;
    }

    /* Check file type */
    if(pGFHFileInfo->m_file_type != LTE_DSP_ROM){
        dspfm_trace_error(DSPFM_WRONG_GFH_FILE_TYPE);
        PRINT("DSPFM:file_type is not LTE_DSP_ROM\n\r");
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_WRONG_GFH_TYPE;
        goto _error;
    }

    /* Check DSP version */
    if(dspfm_dsp_ver_check(pGFHFileInfo) != KAL_TRUE){
        dspfm_trace_error(DSPFM_VERSION_CHECK_FAIL);
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_VERSION_CHECK_FAIL;
        goto _error;
    }

    /* Setup DSP file info*/
    g_dsp_fileinfo.m_found = KAL_TRUE;
    g_dsp_fileinfo.m_content_offset = pGFHFileInfo->m_content_offset;
    g_dsp_fileinfo.m_file_len = pGFHFileInfo->m_file_len;

_error:
    
    return;
}

/*!
 *  @brief  Search the flash layout structure to find the binary region of DSP
 *  @param  start - page index of the region start
 *                bound - page index of the region start
 *  @return KAL_BOOL
 */
static kal_bool dspfm_get_dsp_region(kal_uint32 *start, kal_uint32 *end) 
{
    kal_uint32 i;
    FlashLayout *pFlashLayout = (FlashLayout*)&g_pass_info.m_bl_flash_layout;

    if(g_pass_info.m_bl_maui_share_data.m_bl_magic_head != BL_INFO_V1){
        
        return KAL_FALSE;
    }

    for( i=0 ;i<pFlashLayout->regionCount; i++ )
    {
        if( pFlashLayout->region[i].binaryType == LTE_DSP_ROM )
        {
            *start = pFlashLayout->region[i].u.nandEmmc.startPage;
            *end = pFlashLayout->region[i].u.nandEmmc.boundPage;
            return KAL_TRUE;
        }
    }

    return KAL_FALSE;
}

/*!
 *  @brief  Init DSP file manager
 *  @param  none
 *  @return none
 */
void dspfm_init()
{
    kal_uint32 start, end;

    g_dspfm_mutex = kal_create_mutex("dspfm_mutex");

    //Init FTL
    ftlFuncTbl.FTL_Init(NULL);

    if(dspfm_get_dsp_region(&start, &end) != KAL_TRUE){
        g_dsp_fileinfo.m_errno = DSPFM_ERR_DSP_REGION_NOT_FOUND;
        dspfm_trace_error(DSPFM_REGION_NOT_FOUND);
        PRINT("DSPFM:Cannot find DSP region in Flashlayout\r\n");
    }else{
        g_dsp_fileinfo.m_begin_page = start;
        g_dsp_fileinfo.m_bound_page = end;
    }

    dspfm_get_gfh_file_info();
    
}

/*!
 *  @brief  Open DSP file
 *  @param  none
 *  @return >0 - size of DSP image(not include GFH)
 *              <=0 - error code
 */
kal_int32 dspfm_open()
{
    //Return error if dsp image not found
    if(g_dsp_fileinfo.m_found == KAL_FALSE){       
        return g_dsp_fileinfo.m_errno;
    }

    if(g_dspfm_opened == KAL_FALSE){

        kal_take_mutex(g_dspfm_mutex);
        g_dspfm_opened = KAL_TRUE;
        kal_give_mutex(g_dspfm_mutex);
    }

    return g_dsp_fileinfo.m_file_len - g_dsp_fileinfo.m_content_offset;
}

/*!
 *  @brief  Read size of data to ptr from offset
 *  @param  ptr - destination addr
 *                offset - data offset 
 *                size - data size
 *  @return 0 - success
 *              <0 - error code
 */
kal_int32 dspfm_read(kal_uint32 ptr, kal_uint32 offset, kal_uint32 size)
{
    kal_uint32 page_size = ftlFuncTbl.FTL_GetPageSize();
    kal_uint32 r_offset = offset + g_dsp_fileinfo.m_content_offset;
    kal_uint32 next_page;
    kal_uint32 h_size=0, t_size=0, m_size = 0;
    kal_uint32 h_page=0, t_page=0;
    kal_uint32 *page_buf = NULL;

    //DSP file should be opened before read
    if(g_dspfm_opened == KAL_FALSE){
        dspfm_trace_error(DSPFM_FILE_NOT_OPEN);
        return DSPFM_ERR_DSP_FILE_NOT_OPEND;
    }

    if(ptr & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_PTR_NOT_ALIGN);
        PRINT("DSPFM:ptr not aligned\r\n");
        return DSPFM_ERR_DSP_PTR_NOT_4B_ALIGN;
    }

    if(offset & ALIGN_4B_MASK){
        dspfm_trace_error(DSPFM_OFFSET_NOT_ALIGN);
        PRINT("DSPFM:offset not aligned\r\n");
        return DSPFM_ERR_DSP_OFFSET_NOT_4B_ALIGN;
    }

    //Read data should not exceed file size
    if(r_offset + size >  g_dsp_fileinfo.m_file_len){
        dspfm_trace_error(DSPFM_LENGTH_TOO_LARGE);
        return DSPFM_ERR_DSP_EXCEED_FILE_SIZE;
    }

    //Need to handle the unaligned head and tail of the read data
    //If start addr does not align to page size
    h_page = r_offset / page_size;
    if(r_offset % page_size != 0){
        h_size = page_size - (r_offset % page_size);
    }

    t_page = (r_offset + size) / page_size;
    //If end addr does not align to page size
    if((r_offset + size)% page_size != 0){
        t_size = (r_offset + size)% page_size;
    }

    //Calculate the start page of the data
    next_page = r_offset /page_size;
    if(dspfm_get_start_page(g_dsp_fileinfo.m_begin_page, (r_offset /page_size) *page_size, &next_page) == KAL_FALSE){
        return DSPFM_ERR_DSP_GET_START_PAGE_FAIL;
    }
    PRINT("DSPFM:Head size %d, page %d, tail size %d, page %d, start page %d\r\n", h_size, h_page, t_size, t_page, next_page);

    if(h_page == t_page){

        page_buf = (kal_uint32 *)get_ctrl_buffer(PAGE_BUFFER_SIZE);
            
        if( dspfm_read_data((kal_uint32)page_buf, next_page, page_size, &next_page) == KAL_FALSE )
        {
            free_ctrl_buffer((void *)page_buf);
            return DSPFM_ERR_DSP_READ_DATA_FAIL;
        }
        
        memcpy((kal_uint32 *)ptr, (kal_uint32 *)((kal_uint32)page_buf+(r_offset % page_size)), size);
        PRINT("DSPFM:Read data to %x, next page %d\r\n", ptr, next_page);
        ptr += size;

        free_ctrl_buffer((void *)page_buf);

    }else{

        m_size = size - h_size - t_size;

        //Handle the head part
        if(h_size){
            
            page_buf = (kal_uint32 *)get_ctrl_buffer(PAGE_BUFFER_SIZE);
            
            if( dspfm_read_data((kal_uint32)page_buf, next_page, page_size, &next_page) == KAL_FALSE )
            {
                free_ctrl_buffer((void *)page_buf);
                return DSPFM_ERR_DSP_READ_HEAD_DATA_FAIL;
            }
            
            memcpy((kal_uint32 *)ptr, (kal_uint32 *)((kal_uint32)page_buf+(r_offset % page_size)), h_size);
            PRINT("DSPFM:Read head part to %x, next page %d\r\n", ptr, next_page);
            ptr += h_size;

            free_ctrl_buffer((void *)page_buf);
        }

        //Read page aligned part

        if(m_size){
            
            if( dspfm_read_data(ptr, next_page, m_size, &next_page) == KAL_FALSE ){
                return DSPFM_ERR_DSP_READ_DATA_FAIL;
            }
            PRINT("DSPFM:Read aligned part to %x, next_page %d\r\n", ptr, next_page);
            ptr += m_size;       
        }

        //Handle the tail part
        if(t_size){

            page_buf = (kal_uint32 *)get_ctrl_buffer(PAGE_BUFFER_SIZE);

            if( dspfm_read_data((kal_uint32)page_buf, next_page, page_size, &next_page) == KAL_FALSE )
            {
                free_ctrl_buffer((void *)page_buf);
                return DSPFM_ERR_DSP_READ_TAIL_DATA_FAIL;
            }
            
            memcpy((kal_uint32 *)ptr, page_buf, t_size);
            PRINT("DSPFM:Read tail part to %x, size %d, next_page %d\r\n", ptr, t_size, next_page);
            ptr += t_size;

            free_ctrl_buffer((void *)page_buf);
        }

    }
    
    return 0;
}

/*!
 *  @brief  Close DSP file 
 *  @param  none
 *  @return none
 */
void dspfm_close()
{
    if(g_dspfm_opened == KAL_TRUE){

        kal_take_mutex(g_dspfm_mutex);
        g_dspfm_opened = KAL_FALSE;
        kal_give_mutex(g_dspfm_mutex);
    }
}

#endif 
