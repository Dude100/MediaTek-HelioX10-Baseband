/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         ecall_control.h                                              */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  control message functions (header file)                      */
/*----------------------------------------------------------------------------*/

#ifndef ECALL_CONTROL_H_
#define ECALL_CONTROL_H_

#include "ecall_defines.h"
#include "ecall_sync.h"


typedef enum {
  DlMsgNoop = -2,
  DlMsgReset,
  DlMsgStart,
  DlMsgNack,
  DlMsgAck,
  DlMsgSend,
  DlMsgHlack = SET_LLMSG + SET_HLMSG
} DlData;

typedef enum {
  CtrlRxIdle,
  CtrlRxSync,
  CtrlRxLock,
  CtrlTxIdle,
  CtrlTxSend
} PortState;

typedef enum {
  PortUndef,
  PortIvs,
  PortPsap
} PortOwner;


/*============================================================================*/
/* Control structures                                                         */
/*----------------------------------------------------------------------------*/

typedef struct {
  Int16 dlData;           /* message symbol */
  Int16 dlIndex;          /* message frame counter */
} CtrlTxPort;

typedef struct {
  Int16 dlData;           /* detected message symbol */
  Int16 dlMetric;         /* receiver metric */
} CtrlRxPort;

typedef struct {
  union {
    CtrlTxPort tx;        /* port control transmitter */
    CtrlRxPort rx;        /* port control receiver */
  } u;
  PortState state;        /* port state */
  PortOwner owner;        /* port owner identification */
  Bool invert;            /* port inversion flag */
} CtrlPort;

typedef struct {
  CtrlPort port;          /* port struct */
} CtrlTxData;

typedef struct {
  CtrlPort port;          /* port struct */

  SyncState *sync;        /* pointer to sync struct */
  Int16 *buffer;          /* pointer to control receiver buffer */

  Tern  dlRead;           /* sync indication (ternary variable) */
  Int16 dlIndex;          /* internal frame counter */
  Int16 dlSyncLock;       /* number of sync events required */
} CtrlRxData;


/*============================================================================*/
/* Control functions                                                          */
/*----------------------------------------------------------------------------*/

const char* CtrlPortName(PortOwner);
void CtrlSync(CtrlRxData*, const Int16*);

void CtrlTxReset(CtrlTxData*, PortOwner);
void CtrlTxProcess(CtrlTxData*, Int16*);
void CtrlTxMod(Int16*, Int16, Int16);

void CtrlRxReset(CtrlRxData*, PortOwner, SyncState*, Int16*, Int16);
void CtrlRxProcess(CtrlRxData*, const Int16*);
Int16 CtrlRxDemod(const Int16*, Int16*);

#endif
