#ifndef _L1AUDIO_SPH_TRC_H
#define _L1AUDIO_SPH_TRC_H

#if !defined(GEN_FOR_PC)
#if defined(__TST_MODULE__) || defined(__CUSTOM_RELEASE__)
    #include "l1audio_sph_trc_gen.h"
#endif /* TST Trace Defintion */
#endif


#define TRACE_GROUP_VM    TRACE_GROUP_1
#define TRACE_GROUP_EPL   TRACE_GROUP_2

BEGIN_TRACE_MAP(MOD_L1AUDIO_SPH_SRV)

   // Debug trace for VOC
   TRC_MSG(VM_DATA, "VM data")
   TRC_MSG(RECORD_LENGTH, "Recording VM length = %u bytes")
   TRC_MSG(SET_EPL_PARA, "EPL common parameter0 is set to %d")
   TRC_MSG(EPL_PARA_ERROR, "Invalid EPL common parameter0")
   TRC_MSG(DEBUG_NUMBER, "Debug number = %d")

END_TRACE_MAP(MOD_L1AUDIO_SPH_SRV)

#endif





