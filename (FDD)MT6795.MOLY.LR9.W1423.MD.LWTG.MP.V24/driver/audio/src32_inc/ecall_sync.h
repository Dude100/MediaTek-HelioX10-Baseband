/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         ecall_sync.h                                                 */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  synchronization functions (header file)                      */
/*----------------------------------------------------------------------------*/

#ifndef ECALL_SYNC_H_
#define ECALL_SYNC_H_

#include "ecall_defines.h"


typedef struct {
  Int32 amplitude[2];       /* amplitudes (average, maximum) */
  Int32 shape[2*NRS_CP+1];  /* shape of peak causing a sync event */

  Bool  flag;               /* indicates sync success */
  Int16 delay;              /* synchronization delay */
  Int16 npeaks;             /* number of sync peaks detected */
  Int16 npeaksChk;          /* number of sync peaks detected by sync check */
} SyncSub;

typedef struct {
  Int32 *mem;               /* memory for sync */
  Int32 *memWakeup;         /* memory for wakeup tone detector */

  SyncSub syncPos;          /* regular sync (non-inverted) */
  SyncSub syncNeg;          /* inverted sync */

  Int32 amplitude[3];       /* amplitudes (average, maximum, memory) */
  Int32 shape[2*NRS_CP+1];  /* shape of peak causing a sync event */

  Bool flag;                /* indicates sync success */
  Bool invert;              /* indicates sync inversion */
  Bool resync;              /* indicates resynchronization event */

  Int16 delay;              /* synchronization delay */
  Int16 delayMem;           /* synchronization delay (memory) */
  Int16 npeaks;             /* number of sync peaks detected */
  Int16 npeaksMem;          /* number of sync peaks detected (memory) */
  Int16 events;             /* number of subsequent equal sync events */

  Tern  check;              /* indicates sync check result (ternary variable) */
  Int16 checkCnt;           /* counter for subsequent sync check failures */
  Int16 index;              /* frame reference for sync evaluation */
} SyncState;


/*============================================================================*/
/* Sync functions                                                             */
/*----------------------------------------------------------------------------*/

void SyncReset(SyncState*, Int32*, Int32*);
void SyncSubReset(SyncSub*);

void Sync(SyncState*, const Int16*, const char*, Bool);
void SyncCheck(SyncState*, const Int16*, const char*);
void SyncTrack(SyncState*, Bool);

void SyncFilter(SyncState*, const Int16*, Bool);

void SyncSubPut(const SyncState*, SyncSub*);
void SyncSubGet(SyncState*, const SyncSub*);
void SyncSubCpy(const SyncSub*, SyncSub*);

void SyncSubRun(SyncSub*, const char*,
                const Int32*, const Int32*, const Int32*, const Int32*);
void SyncSubChk(SyncSub*, const char*,
                const Int32*, const Int32*, const Int32*, const Int32*, Int16);

Int16 PeakUpdate(const Int32*, const Int32*, Int16);
void PeakCheck(SyncSub*, const char*, const Bool*, const Int16*,
               const Int32*, const Int32*, const Int32*,
               Int16, Int16, Int16, Int16);

void ToneDetect(SyncState*, const Int16*);

#endif
