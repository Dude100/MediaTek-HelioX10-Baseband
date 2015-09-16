/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         modemx.h                                                     */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  IVS and PSAP structures and functions (header file)          */
/*----------------------------------------------------------------------------*/

#ifndef MODEMX_H_
#define MODEMX_H_

#include <stdio.h>
#include <string.h>

#include "ecall_defines.h"
#include "ecall_control.h"
#include "ecall_modem.h"
#include "ecall_sync.h"
#include "ecall_fec.h"
#include "ecall_rom.h"

#include "kal_public_api.h"
#include "kal_trace.h"
#include "l1sp_trc.h"

/* callback functions: to be implemented by the user application */

void Abort(const char *format, ...);
void LogInfo(const char *format, ...);

/*============================================================================*/
/* IVS declarations                                                           */
/*----------------------------------------------------------------------------*/

typedef enum {
  IVSEVENT_SENDINGSTART,
  IVSEVENT_SENDINGMSD,
  IVSEVENT_RESTARTMSD,
  IVSEVENT_CONTROLSYNC,
  IVSEVENT_CONTROLLOCK,
  IVSEVENT_LLACKRECEIVED,
  IVSEVENT_HLACKRECEIVED,
  IVSEVENT_IDLEPOSTRESET,
  IVSEVENT_IDLEPOSTSTART,
  IVSEVENT_TIMEOUT,
  IVSEVENT_NACKRECEIVED
} IvsEvent;

/* callback functions: to be implemented by the user application */

void IvsCatchEvent(IvsEvent ie);
void IvsReceiveHlack(const Ord8 data);

/*----------------------------------------------------------------------------*/

void IvsReset(const Ord8 *msd, int length);
void IvsProcess(Int16 *pcm);
void IvsSendStart(void);

void IvsRxReset(void);
void IvsRxProcess(const Int16 *pcm);

void IvsTxReset(const Ord8 *msd, int length);
void IvsTxProcess(Int16 *pcm);
void IvsTxState(Int16 msg, Int16 metric, Bool syncLock);

/*----------------------------------------------------------------------------*/

typedef enum {
  IvsIdle,
  IvsTrigger,
  IvsStart,
  IvsSendMsd,
  IvsAck,
  IvsHlack
} IvsState;

typedef struct {
  IvsState   state;       /* IVS transmitter state */
  CtrlTxData ctrl;        /* IVS control struct */
  ModState   mod;         /* IVS modulator struct */

  Int16 rv;               /* redundancy version */
  Int16 ulN;              /* uplink number of frames */
  Int16 ulIndex;          /* uplink frame counter */
  Int16 ulDelay;          /* uplink transmit offset in samples */
  Int16 dlMsgOld;         /* previous control message */

  Bool  pendingStart;     /* indicates pending START message */
  Int16 overallNack;      /* cumulative NACK count */

  Int16 stateCnt[SET_LLMSG + SET_HLMSG+1];
  Int16 stateIgn[SET_LLMSG + SET_HLMSG+1];

  Ord1  memCode[NRB_CODE_BUFFER];
  Int16 memDelay[2*PCM_LENGTH];
} IvsTxData;

typedef struct {
  IvsState   state;       /* IVS receiver state */
  CtrlRxData ctrl;        /* IVS control struct */
  SyncState  sync;        /* IVS sync struct */

  Int16 dlData;           /* downlink message symbol */
  Int16 dlIndex;          /* donwlink frame counter */
  Int16 dlMsgCnt;         /* downlink message counter */

  Int16 memCtrl[NRF_MEMCTRL*PCM_LENGTH];
  Int32 memSync[NRS_MEMSYNC];
} IvsRxData;

typedef struct {
  IvsRxData rx;           /* IVS receiver struct */
  IvsTxData tx;           /* IVS transmitter struct */
} IvsData;

// KH: add for integration
void IvsInit(void *addr);
void IvsDeinit(void);
int IvsGetMemSize(void);
IvsState IvsTxGetState(void);
IvsState IvsRxGetState(void);

void PsapInit(void *addr);
void PsapDeinit(void);
int PsapGetMemSize(void);

/*============================================================================*/
/* PSAP declarations                                                          */
/*----------------------------------------------------------------------------*/

typedef enum {
  PSAPEVENT_SENDINGSTART,
  PSAPEVENT_SENDINGRESTART,
  PSAPEVENT_SENDINGLLACK,
  PSAPEVENT_SENDINGHLACK,
  PSAPEVENT_CONTROLSYNC,
  PSAPEVENT_CONTROLLOCK,
  PSAPEVENT_MSDSYNC,
  PSAPEVENT_MSDRECEIVED,
  PSAPEVENT_IDLEPOSTRESET,
  PSAPEVENT_IDLEPOSTSTART,
  PSAPEVENT_IDLEPOSTLLACK,
  PSAPEVENT_IDLEPOSTHLACK,
  PSAPEVENT_TIMEOUT
} PsapEvent;

/* callback functions: to be implemented by the user application */

void PsapCatchEvent(PsapEvent pe);
void PsapReceiveMsd(const Ord8 *msd, int length);

/*----------------------------------------------------------------------------*/

void PsapReset(void);
void PsapProcess(Int16 *pcm);
void PsapSendStart(void);
void PsapSendHlack(const Ord8 data);

void PsapRxReset(void);
void PsapRxProcess(const Int16 *pcm);
void PsapRxUplink(const Int16 *pcm);
void PsapRxDownlink(void);
void PsapRxSetMod(const SyncState *sync, ModState *mod);

void PsapTxReset(void);
void PsapTxProcess(Int16 *pcm);

/*----------------------------------------------------------------------------*/

typedef enum {
  PsapIdle,
  PsapTrigger,
  PsapStart,
  PsapNack,
  PsapAck,
  PsapHlack
} PsapState;

typedef struct {
  PsapState  state;       /* PSAP receiver state */
  CtrlRxData ctrl;        /* PSAP control struct */
  SyncState  sync;        /* PSAP sync struct */
  ModState   mod;         /* PSAP modulator struct */

  Int16 rv;               /* redundancy version */
  Int16 ulN;              /* uplink number of frames without muting */
  Int16 ulIndex;          /* uplink frame counter */
  Int16 mgIndex;          /* uplink position in muting gap table */
  Int16 ulTrials;         /* uplink decoding trails */
  Int16 ulSyncTail;       /* sync observation counter after sync success */

  Ord8  dlHlackData;      /* downlink higher-layer message (4 bits) */
  Int16 dlData;           /* downlink message symbol */
  Int16 dlIndex;          /* donwlink frame counter */
  Int16 dlMsgCnt;         /* downlink message counter */

  Ord8   *msd;            /* MSD in byte representation */
  Ord1   *msdBin;         /* MSD in binary representation */
  Int16  *memCtrl;        /* buffer for control and data demodulation */
  IntLLR *memCode;        /* soft bit buffer for decoding */

  char buffer[0
    + sizeof(IntLLR)* NRB_CODE_ARQ
    + sizeof(Int16) * NRF_MEMCTRL*PCM_LENGTH
    + sizeof(Int32) * NRS_MEMSYNC
    + sizeof(Int32) * 2*(NRF_SYNC+1)];
} PsapRxData;

typedef struct {
  CtrlTxData ctrl;        /* PSAP control struct */
} PsapTxData;

typedef struct {
  PsapRxData rx;          /* PSAP receiver struct */
  PsapTxData tx;          /* PSAP transmitter struct */
} PsapData;

PsapData* PsapGetData(void);

#endif
