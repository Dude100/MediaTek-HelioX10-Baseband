/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         ecall_rom.h                                                  */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  ROM data arrays (header file)                                */
/*----------------------------------------------------------------------------*/

#ifndef ECALL_ROM_H_
#define ECALL_ROM_H_

#include "ecall_defines.h"


/*============================================================================*/
/* Synchronization                                                            */
/*----------------------------------------------------------------------------*/

extern const Int16 wakeupSin500[16];
extern const Int16 wakeupCos500[16];
extern const Int16 wakeupSin800[10];
extern const Int16 wakeupCos800[10];

extern const Int16 syncPulseForm[5];
extern const Int16 syncSequence[15];
extern const Int16 syncIndexPreamble[SYNC_IDXLEN];
extern const Int16 syncFrame[10*PCM_LENGTH];

/*============================================================================*/
/* Uplink/Downlink format                                                     */
/*----------------------------------------------------------------------------*/

extern const Int16 indexBits[24];

extern const Int16 m4smp_ulPulse[16];
extern const Int16 m8smp_ulPulse[32];
extern const Int16 m4smp_ulPulseMatch[64];
extern const Int16 m8smp_ulPulseMatch[128];

extern const Int16 m4smp_mgTable[66];
extern const Int16 m8smp_mgTable[116];

extern const Int16 dlPcmData[4][NRF_DLDATA*PCM_LENGTH];
extern const Int16 dlPcmDataMatch[4][NRF_DLDATA*PCM_LENGTH];

/*============================================================================*/
/* FEC encoder/decoder                                                        */
/*----------------------------------------------------------------------------*/

extern const Ord16 stateTrans[16];
extern const Ord16 revStateTrans[16];
extern const Ord1  outputParity[16];

extern const Ord1  crcPolynomial[NRB_CRC+1];
extern const Ord1  scramblingSeq[NRB_INFO_CRC];
extern const Ord16 interleaverSeq[NRB_INFO_CRC];
extern const Ord16 redVerIndex[8][NRB_CODE_ARQ];

extern const IntLLR logExpTable[LOGEXP_RES];

#endif
