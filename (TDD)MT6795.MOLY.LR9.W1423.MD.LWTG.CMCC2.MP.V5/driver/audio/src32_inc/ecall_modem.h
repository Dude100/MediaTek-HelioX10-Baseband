/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         ecall_modem.h                                                */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  modulator and demodulator functions (header file)            */
/*----------------------------------------------------------------------------*/

#ifndef ECALL_MODEM_H_
#define ECALL_MODEM_H_

#include "ecall_defines.h"


typedef enum {
  ModUndef,
  Mod3bit4smp,
  Mod3bit8smp
} ModType;

typedef struct {
  ModType type;      /* identifies modulator type */

  Int16 bpsym;       /* bits per symbol */
  Int16 spmf;        /* samples per modulation frame */
  Int16 mfpf;        /* modulation frames per frame = PCM_LENGTH/spmf */
  Int16 decpos1;     /* position 1st decoding trial */
  Int16 decpos2;     /* position 2nd decoding trial */
  Int16 wutperiod;   /* wakeup tone period in samples */
  Int16 nfmute1;     /* number of muting frames 1st interval */
  Int16 nfmute4;     /* number of muting frames 4th interval */
  Int16 nfmuteall;   /* number of muting frames total */
  Int16 nfdata;      /* number of data frames = NRB_CODE_ARQ/(mfpf*bpsym) */

  const Int16 *ulPulse;
  const Int16 *ulPulseMatch;
  const Int16 *mgTable;
  const Int16 *wakeupSin;
  const Int16 *wakeupCos;
} ModState;


/*============================================================================*/
/* Modem functions                                                            */
/*----------------------------------------------------------------------------*/

void SetModState(ModState*, ModType);

void IvsTransmitter(const ModState*, const Ord1*, Int16*, Int16, Int16);
void PsapReceiver(const ModState*, const Int16*, IntLLR*);

void SymbolMod(const ModState*, Int16, Int16*);
void SymbolDemod(const ModState*, const Int16*, IntLLR*);

void Byte2Bit(const Ord8*, Ord1*, Int16);
void Bit2Byte(const Ord1*, Ord8*, Int16);

Int32 MpyLacc(Int32, Int16);

#endif
