
#ifndef _TCM_ETCM_PTI_H
#define _TCM_ETCM_PTI_H

#include "kal_general_types.h"
#include "kal_public_defs.h"

/*etcm headers */
#include "tcm_etcm_def.h"
#include "tcm_etcm_msg_elm.h"
#include "tcm_etcm_cid.h"


#define ETCM_PTIV_MAX      (127)
#define ETCM_PTIV_MIN      (1)
#define ETCM_PTIV_MT       (0)

#define ETCM_PTI_COOKIE     (0x261A7F94)

/* network triggert */
#define ETCM_PTIV_IS_NW(p) (p == 0)
/* modem selft triggert */
#define ETCM_PTIV_IS_MD(p) (p > ETCM_PTIV_MAX)
/* UE triggert */
#define ETCM_PTIV_IS_UE(p) ( ( ETCM_PTIV_MIN <= p ) && (p <= ETCM_PTIV_MAX))

#define ETCM_PTIV_IS_ME(p) ( (!(ETCM_PTIV_IS_NW(p)) && (!(ETCM_PTIV_IS_MD(p)))) )

#define ETCM_PTIV_IS_MO(p) (  ETCM_PTIV_IS_UE(p))
#define ETCM_PTIV_IS_MT(p) (!(ETCM_PTIV_IS_MO(p)))

typedef enum etcm_pti_state_e {
    ETCM_PTI_ST_NULL,
    ETCM_PTI_ST_ALLOC,
    ETCM_PTI_ST_REQUESTED,
    ETCM_PTI_ST_RESPONDED,

    ETCM_PTI_ST_MAX
} etcm_pti_state_struct;

typedef enum etcm_pti_rsp_e {
    ETCM_PTI_RSP_NULL,
    ETCM_PTI_RSP_DROP,
    ETCM_PTI_RSP_POS,
    ETCM_PTI_RSP_NEG,
    ETCM_PTI_RSP_NEG_P, /* preempt */
    ETCM_PTI_RSP_MAX
} etcm_pti_rsp_struct;

typedef kal_uint8 etcm_ptiv_struct;

struct etcm_ptiMngr_s;

typedef etcm_pti_rsp_struct (*etcm_ptiGetRspMarkerCb) (etcm_msgElm_struct *msg);
typedef kal_bool (*etcm_ptiPutRejMsgCb)    (etcm_msgElm_struct *msg);

typedef struct etcm_ptiOperCb_s {
    etcm_ptiGetRspMarkerCb getRspCb;
    /*etcm_ptiPutRejMsgCb     putRejCb;*/
    /*etcm_msgElmOper_struct       *msgElmOper;*/
} etcm_ptiOperCb_struct;

typedef struct etcm_ptiElm_s {
    struct etcm_ptiMngr_s *mngr;

    etcm_ptiv_struct ptiv;
    etcm_pti_rsp_struct resp_marker;
    etcm_cid_struct cid;
    etcm_pti_state_struct state;
    etcm_pti_state_struct next;
    msg_type msg_id;
    etcm_ptiOperCb_struct        *operCb;
    kal_uint32 cookie;
} etcm_ptiElm_struct;

typedef struct etcm_ptiMngr_s {
    etcm_ptiv_struct ptiCurr;                         /* current pti has been assigned */
    kal_int16 n_allocPti;                             /* alloc pti  */
    etcm_ptiElm_struct ptiList[ETCM_PTIV_MAX + 1];    /* 127+1 */
} etcm_ptiMngr_struct;

etcm_pti_state_struct   etcm_ptiGetState        (etcm_ptiElm_struct *pti);
void                    etcm_ptiFree            (etcm_ptiElm_struct *pti);

kal_bool                etcm_ptiChgNextState    (etcm_ptiElm_struct *pti);
etcm_cid_struct         etcm_ptiGetCid          (etcm_ptiElm_struct *pti);
/* [enhancement][single mode phase 2] #4 - PTI is full */
etcm_ptiv_struct        etcm_ptiGetPtiv         (etcm_ptiElm_struct *pti);
etcm_pti_state_struct   etcm_ptiGetNextState    (etcm_ptiElm_struct *pti);
msg_type                etcm_ptiGetMsgId        (etcm_ptiElm_struct *pti);
kal_bool                etcm_ptiSetNextState    (etcm_ptiElm_struct *pti, etcm_pti_state_struct next);
kal_bool                etcm_ptiSetOperCb       (etcm_ptiElm_struct *pti, etcm_ptiOperCb_struct *operCb);
kal_bool                etcm_ptiElmIsValid      (etcm_ptiElm_struct *pti, etcm_ptiv_struct ptiv);
kal_bool                etcm_ptiElmIsNW         (etcm_ptiElm_struct *pti);
kal_bool                etcm_ptiElmIsMt         (etcm_ptiElm_struct *pti);
kal_bool                etcm_ptiElmHasResult    (etcm_ptiElm_struct *pti);
kal_bool                etcm_ptiIsMtPtiv        (etcm_ptiv_struct ptiv);
kal_bool                etcm_ptiElmChkCid       (etcm_ptiElm_struct *pti, etcm_cid_struct cid);

/* mngr */
etcm_ptiElm_struct      *etcm_ptiNewAlloc       (etcm_ptiMngr_struct *mngr, msg_type msg_id, etcm_cid_struct cid);
kal_bool                etcm_ptiProcess         (etcm_ptiElm_struct *pti, etcm_msgElm_struct *inMsg);
kal_uint8               etcm_ptiDoPreemption    (etcm_ptiMngr_struct *mngr, etcm_msgElm_struct *msg, etcm_cid_struct cid, etcm_ptiv_struct ptiv);
etcm_ptiElm_struct      *etcm_ptiGetElmByPtiv   (etcm_ptiMngr_struct *mngr, etcm_ptiv_struct ptiv);
kal_uint16              etcm_ptiGetFreeCount    (etcm_ptiMngr_struct *mngr);
etcm_ptiElm_struct      *etcm_ptiMtAlloc        (etcm_ptiMngr_struct *mngr, etcm_ptiv_struct ptiv);
etcm_ptiMngr_struct     *etcm_ptiGetMngr        (etcm_ptiElm_struct *pti);

#endif
