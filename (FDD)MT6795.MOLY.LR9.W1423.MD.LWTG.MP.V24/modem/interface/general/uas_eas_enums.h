#ifndef _UAS_EAS_ENUMS_H
#define _UAS_EAS_ENUMS_H

#include "irat_common_enums.h"

/* MACRO goes here */
#define MAX_NUM_CELL_INFO_UTRA (16)
#define MAX_NUM_REDIRECTION_FREQ_UTRA (6)

typedef enum {
    CGI_INFO_NOT_CSG_CELL    = 0x00,
    CGI_INFO_CSG_CLOSED_CELL = 0x01,
    CGI_INFO_HYBRID_CELL     = 0x02,
} cell_type_enum;

#endif  /* UAS_EAS_ENUMS_H */
