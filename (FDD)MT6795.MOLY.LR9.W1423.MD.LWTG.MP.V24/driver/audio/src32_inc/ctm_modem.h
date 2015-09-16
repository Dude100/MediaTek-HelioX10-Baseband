/*******************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*******************************************************************************/

/*******************************************************************************
 *
 * Filename:
 * ---------
 *	   ctm_modem.h
 *
 * Project:
 * --------
 *   
 *
 * Description:
 * ------------
 *   
 *
 * Author:
 * -------
 *	
 *
 *==============================================================================
 * 				HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *==============================================================================
 *******************************************************************************/
 
#ifdef __CTM_SUPPORT__

#ifndef __CTM_MODEM_H
#define __CTM_MODEM_H

uint32 ctm_modem_mem_req(void);
void ctm_modem_init(uint8 *buf, uint32 buf_len, CTM_Param *ctm_param);
uint16 ctm_modem_get_flags(void);

void baudot_demod(const uint16 *pcm_in_buf, uint16 *ctmFlags, uint8 *utf8_code);
void ctm_receiver(const uint16 *pcm_in_buf, uint8 bfi, uint16 *ctmFlags, uint8 *utf8_code);
void baudot_mod(uint8 utf8_code, uint16 *pcm_in_buf,uint16 *ctmFlags);
void ctm_transmitter(uint8 utf8_code, uint16 *pcm_in_buf,uint16 *ctmFlags);
void baudot_demod_reset(void);

//*** CMF(CTM Modem Flags)

// Baudot Demodulator
#define CMF_BAUDOT_IN_DETECTED      0x1
#define CMF_BAUDOT_IN_CHAR          0x2

// CTM Receiver
#define CMF_CTM_RX_EARLY_MUTE       0x4
#define CMF_CTM_RX_DETECTED         0x8
#define CMF_CTM_RX_CHAR             0x10

// Baudot Modulator
#define CMF_BAUDOT_OUT_BITS_READY   0x40
#define CMF_BAUDOT_OUT_NEAR_EMPTY   0x80

// CTM Transmitter
#define CMF_CTM_TX_BITS_READY       0x100
#define CMF_CTM_TX_NEAR_EMPTY       0x200

#endif // __CTM_MODEM_H

#endif // __CTM_SUPPORT__
