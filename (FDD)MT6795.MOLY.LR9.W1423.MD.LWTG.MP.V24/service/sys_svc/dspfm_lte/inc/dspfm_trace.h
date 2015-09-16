#ifndef _DSPFM_TRACE_H
#define _DSPFM_TRACE_H

#ifndef GEN_FOR_PC
 #include "stack_config.h"
#endif /* GEN_FOR_PC */

#include "dhl_trace.h"
#include "dhl_def.h"

#if !defined(GEN_FOR_PC)
#if defined(__DHL_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "dspfm_trace_gen.h"
#endif /* TST Trace Defintion */
#endif

BEGIN_TRACE_MAP(MOD_DSPFM)
   TRC_MSG(DSPFM_REGION_NOT_FOUND, "[DSPFM] Cannot find DSP region in flash layout")
   TRC_MSG(DSPFM_FILE_NOT_OPEN, "[DSPFM] DSP file not opened ")
   TRC_MSG(DSPFM_PTR_NOT_ALIGN, "[DSPFM] DSP ptr not aligned ")
   TRC_MSG(DSPFM_OFFSET_NOT_ALIGN, "[DSPFM] DSP offset not aligned  ")
   TRC_MSG(DSPFM_INVALID_GFH_FILE_INFO, "[DSPFM] Invalid GFH file info")
   TRC_MSG(DSPFM_FILE_SIZE_TOO_LARGE, "[DSPFM] DSP file size exceeds bound page")
   TRC_MSG(DSPFM_WRONG_GFH_FILE_TYPE, "[DSPFM] GFH file type is not LTE_DSP_ROM ")
   TRC_MSG(DSPFM_LENGTH_TOO_LARGE, "[DSPFM] Read length exceeds file size ")
   TRC_MSG(DSPFM_READ_FLASH_FAILED, "[DSPFM] Read error at block %d, page %d")
   TRC_MSG(DSPFM_FLASH_BAD_BLOCK, "[DSPFM] Bad block at block %d")
   TRC_MSG(DSPFM_FILE_READ_FAILED, "[DSPFM] DSP file read failed")
   TRC_MSG(DSPFM_FILE_SEEK_FAILED, "[DSPFM] DSP file seek failed")
   TRC_MSG(DSPFM_VERSION_CHECK_FAIL, "[DSPFM] DSP version check failed")
   TRC_MSG(DSPFM_MAUI_GFH_NO_PLT_ID, "[DSPFM] MAUI platform id not found")
   TRC_MSG(DSPFM_MAUI_GFH_NO_PROJ_ID, "[DSPFM] MAUI project id not found")
   TRC_MSG(DSPFM_DSP_GFH_NO_FOUND, "[DSPFM] DSP GFH file info not found")   
   TRC_MSG(DSPFM_DSP_GFH_NO_PLT_ID, "[DSPFM] DSP platform id not found")
   TRC_MSG(DSPFM_DSP_GFH_NO_PROJ_ID, "[DSPFM] DSP project id not found")   
   TRC_MSG(DSPFM_DSP_PLT_ID_NOT_MATCH, "[DSPFM] DSP platform id is not matched")  
   TRC_MSG(DSPFM_DSP_PROJ_ID_NOT_MATCH, "[DSPFM] DSP project id is not matched")  
END_TRACE_MAP(MOD_DSPFM)   

#endif
