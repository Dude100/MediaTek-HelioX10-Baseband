/*****************************************************************************
 *
 * Filename:
 * ---------
 *   ft_fnc_misc.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *  Misc Function
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef _FT_FNC_MISC_H_
#define _FT_FNC_MISC_H_
#include "kal_public_api.h"
#include "l1_types_public.h"
#include "nvram_struct.h"

#define FT_SML_VALID        0x00
#define FT_SML_INVALID      0x01
#define FT_SML_NO_FILENAME  0x02

kal_uint32 FT_MiscCheckFunctionSupported(kal_uint32 query_op_code);
void FT_MISC_Operation(ilm_struct *ptrMsg);
kal_uint8  FT_MISC_SendCnf(FT_MISC_CNF *ft_misc_ret, peer_buff_struct *peer_buff);

extern int i4_ft_cur_misc_op;
extern kal_uint16 ft_gl_misc_token; 


bool ft_misc_cal_data_allocate_buf(void);
bool ft_misc_cal_data_read_from_nvram(void);
bool ft_misc_cal_data_read_from_nvram_cnf(nvram_read_cnf_struct*  cnf_result,
        peer_buff_struct*       peer_buff );
bool ft_misc_cal_data_write_to_nvram(void);
bool ft_misc_cal_data_write_to_nvram_cnf(nvram_write_cnf_struct*  cnf_result );
bool ft_misc_cal_data_get_checksum(kal_uint16 file_idx, 
                                   kal_uint16 rec_idx,
                                   kal_uint16 *pu2_checksum);
void ft_misc_cal_data_free_alloc_buf(void);
bool  ft_misc_cal_data_update_local_buf( kal_uint16 file_idx,
        	       kal_uint16 rec_idx, 
        	       kal_uint16 u2_checksum);
bool ft_misc_cal_data_del_from_local_buf(bool bOne);
bool ft_misc_cal_data_check(bool bOne);
#endif  // end of #ifndef _FT_FNC_MISC_H_
