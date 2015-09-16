/*============================================================================*/
/* eCall ANSI C fixed-point reference source code                             */
/*                                                                            */
/* File:         ecall_defines.h                                              */
/* Version:      8.6.0 (Rel8) / 9.4.0 (Rel9)                                  */
/* Date:         2011-02-08                                                   */
/* Description:  constants and common data structures                         */
/*----------------------------------------------------------------------------*/

#ifndef ECALL_DEFINES_H_
#define ECALL_DEFINES_H_

#include <limits.h>

//#define __ECALL_MODEM_SUPPORT_PSAP__

/*============================================================================*/
/* General conventions                                                        */
/*----------------------------------------------------------------------------*/

typedef enum { False, True } Bool;
typedef enum { Minus = -1, Zero, Plus } Tern;

typedef signed char          Int8;        /*  8 bit signed variable           */
typedef signed short int     Int16;       /* 16 bit signed variable           */
typedef signed int           Int32;       /* 32 bit signed variable           */

typedef unsigned char        Ord1;        /*  1 bit variable                  */
typedef unsigned char        Ord8;        /*  8 bit unsigned variable         */
typedef unsigned short int   Ord16;       /* 16 bit unsigned variable         */
typedef unsigned int         Ord32;       /* 32 bit unsigned variable         */

#define MAX(a,b) ((a)>(b) ? (a) : (b))    /* macro: maximum                   */
#define MIN(a,b) ((a)<(b) ? (a) : (b))    /* macro: minimum                   */
#define ABS(a)   ((a)< 0 ? -(a) : (a))    /* macro: absolute value            */
#define SIGN(a)  ((a)< 0 ? (-1) : (1))    /* macro: sign                      */

#ifndef PCM_LENGTH
#define PCM_LENGTH        (160)           /* length of PCM frame in samples   */
#endif
#ifndef MSD_MAX_LENGTH
#define MSD_MAX_LENGTH    (140)           /* length of MSD message in bytes   */
#endif
#ifndef PCM_MIN
#define PCM_MIN           (SHRT_MIN)      /* minimum PCM value                */
#endif
#ifndef PCM_MAX
#define PCM_MAX           (SHRT_MAX)      /* maximum PCM value                */
#endif

/*============================================================================*/
/* Synchronization                                                            */
/*----------------------------------------------------------------------------*/

#define SYNC_BADCHECK     (3)             /* sync consecutive bad check       */
#define SYNC_BADTRACK     (4)             /* sync consecutive bad track       */
#define SYNC_IDXLEN       (75)            /* sync index length                */
#define SYNC_THRESHOLD    (10e6)          /* sync threshold                   */

#define LOCK_RESYNC       (2)             /* messages to lock after sync loss */
#define LOCK_START_UL     (2)             /* START messages to lock sync (UL) */
#define LOCK_START_DL     (3)             /* START messages to lock sync (DL) */
#define FAIL_RESTART      (3)             /* START messages to restart        */

#define NRF_WAKEUP        (3)             /* number of wakeup frames          */
#define NRF_SYNC          (13)            /* number of sync frames            */
#define NRF_OBSERVE       (10)            /* number of sync observer frames   */
#define NRF_RESYNC        (60)            /* resync frames after sync loss    */

#define NRS_CHECK         (480)           /* number of samples to check       */
#define NRS_TRACK         (240)           /* number of samples to track       */
#define NRS_CP            (2)             /* number of samples next to peaks  */

#define PNSEQ_OSF         (22)            /* oversampling of PN sequence      */
#define PEAK_DIST_PP      (30*PNSEQ_OSF)  /* distance outer positive peaks    */
#define PEAK_DIST_NN      (54*PNSEQ_OSF)  /* distance negative peaks          */
#define PEAK_DIST_PN      (12*PNSEQ_OSF)  /* distance positive to negative    */

/*============================================================================*/
/* Uplink/Downlink format                                                     */
/*----------------------------------------------------------------------------*/

#define ARQ_MAX           (8)             /* number of redundancy versions    */
#define NRB_TAIL          (3)             /* number of encoder tail bits      */
#define NRB_CRC           (28)            /* order of CRC polynomial          */

#define NRB_INFO          (8*MSD_MAX_LENGTH)
#define NRB_INFO_CRC      (8*MSD_MAX_LENGTH + NRB_CRC)
#define NRB_CODE_ARQ      (1380)
#define NRB_CODE_BUFFER   (3*(8*MSD_MAX_LENGTH + NRB_CRC) + 4*NRB_TAIL)

#define SET_LLMSG         (16)            /* set size lower-layer messages    */
#define SET_HLMSG         (16)            /* set size higher-layer messages   */

#define NRF_DLDATA        (3)             /* downlink data frames             */
#define NRF_DLMUTE1LL     (3)             /* 1st muting lower-layer message   */
#define NRF_DLMUTE1HL     (1)             /* 1st muting higher-layer message  */
#define NRF_DLCHUNK       (NRF_SYNC + NRF_DLMUTE1HL + 2*NRF_DLDATA)

/*============================================================================*/
/* IVS/PSAP processing                                                        */
/*----------------------------------------------------------------------------*/

#define NRF_MEMCTRL       (7)
#define NRS_MEMSYNC       (508 + 38*NRS_CP)

#define IVS_NUMSEND       (5)             /* number of SEND messages          */
#define IVS_THRESHOLD     (40000)         /* threshold for control messages   */
#define IVS_GOSTART       (6)             /* threshold for unreliable START   */
#define IVS_TXFAST        (10)            /* fast modulator NACK condition    */
#define IVS_TXINC         (87)            /* sample increment at restart      */

#define PSAP_NUMSTART     (500)           /* number of START messages         */
#define PSAP_NUMACK       (5)             /* number of ACK messages           */
#define PSAP_NUMHLACK     (5)             /* number of HLACK messages         */
#define PSAP_THRESHOLD    (40)            /* threshold for modulator type     */

#define FEC_VAR           (30206)         /* variance: 1/4550000 in Q37       */
#define FEC_MEAN          (0xB9999A)      /* mean: 5.8 in Q21                 */
#define FEC_ITERATIONS    (8)             /* number of decoder iterations     */
#define FEC_STATES        (8)             /* number of decoder states         */

#define IntLLR            Int16
#define LLR_MAX           ((Int32)(0x7fff-1))
#define LOGEXP_RES        (401)           /* resolution of logexp table       */
#define LOGEXP_DELTA      (-6)            /* internal Q-factor                */
#define LOGEXP_QIN        (8)             /* input Q-factor of LLR values     */

#endif
