/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2012
*
*  BY OPENING THIS FILE, BUYER HEREBY UNEQUIVOCALLY ACKNOWLEDGES AND AGREES
*  THAT THE SOFTWARE/FIRMWARE AND ITS DOCUMENTATIONS ("MEDIATEK SOFTWARE")
*  RECEIVED FROM MEDIATEK AND/OR ITS REPRESENTATIVES ARE PROVIDED TO BUYER ON
*  AN "AS-IS" BASIS ONLY. MEDIATEK EXPRESSLY DISCLAIMS ANY AND ALL WARRANTIES,
*  EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE IMPLIED WARRANTIES OF
*  MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE OR NONINFRINGEMENT.
*  NEITHER DOES MEDIATEK PROVIDE ANY WARRANTY WHATSOEVER WITH RESPECT TO THE
*  SOFTWARE OF ANY THIRD PARTY WHICH MAY BE USED BY, INCORPORATED IN, OR
*  SUPPLIED WITH THE MEDIATEK SOFTWARE, AND BUYER AGREES TO LOOK ONLY TO SUCH
*  THIRD PARTY FOR ANY WARRANTY CLAIM RELATING THERETO. MEDIATEK SHALL ALSO
*  NOT BE RESPONSIBLE FOR ANY MEDIATEK SOFTWARE RELEASES MADE TO BUYER'S
*  SPECIFICATION OR TO CONFORM TO A PARTICULAR STANDARD OR OPEN FORUM.
*
*  BUYER'S SOLE AND EXCLUSIVE REMEDY AND MEDIATEK'S ENTIRE AND CUMULATIVE
*  LIABILITY WITH RESPECT TO THE MEDIATEK SOFTWARE RELEASED HEREUNDER WILL BE,
*  AT MEDIATEK'S OPTION, TO REVISE OR REPLACE THE MEDIATEK SOFTWARE AT ISSUE,
*  OR REFUND ANY SOFTWARE LICENSE FEES OR SERVICE CHARGE PAID BY BUYER TO
*  MEDIATEK FOR SUCH MEDIATEK SOFTWARE AT ISSUE.
*
*  THE TRANSACTION CONTEMPLATED HEREUNDER SHALL BE CONSTRUED IN ACCORDANCE
*  WITH THE LAWS OF THE STATE OF CALIFORNIA, USA, EXCLUDING ITS CONFLICT OF
*  LAWS PRINCIPLES.  ANY DISPUTES, CONTROVERSIES OR CLAIMS ARISING THEREOF AND
*  RELATED THERETO SHALL BE SETTLED BY ARBITRATION IN SAN FRANCISCO, CA, UNDER
*  THE RULES OF THE INTERNATIONAL CHAMBER OF COMMERCE (ICC).
*
*****************************************************************************/

/*******************************************************************************
 * Filename:
 * ---------
 *   brom_certificate.h
 *
 * Project:
 * --------
 *   BootROM
 *
 * Description:
 * ------------
 *   Structure definition of certificates
 *
 * Author:
 * -------
 * -------
 *
 * ==========================================================================
 * $Log$
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 *
 * removed!
 * removed!
 * Initial version of MT6290 bootloader.
 ****************************************************************************/

#ifndef BROM_CERTIFICATE_H
#define BROM_CERTIFICATE_H

#include <kal_general_types.h>

#define DA_MAX_BLOCKS	8
#define DA_BLOCK_SIZE	0xF000	//60KB

#define TOOL_CERT_MAGIC1	0x4C4F4F54	//TOOL
#define TOOL_CERT_MAGIC2	0x54524543	//CERT

#define ROOT_CERT_MAGIC1	0x544F4F52	//ROOT
#define ROOT_CERT_MAGIC2	0x54524543	//CERT

#define SCTRL_CERT_MAGIC1	0x4C544353	//SCTL
#define SCTRL_CERT_MAGIC2	0x54524543	//CERT

#define DA_HEAD_MAGIC1		0x41444144	//DADA
#define DA_HEAD_MAGIC2		0x44414548	//HEAD

#define ROOT_KEY_NUM	4
#define MEID_LENGTH		16
#define RSA_ENCRYPTED_LENGTH	256		//bytes

typedef struct {
	kal_uint16 hword[16];
}__attribute__((aligned(2), packed)) hash_t;

typedef struct {
	/* 2048 bit RSA public key (modulus and public exponent) */
	kal_uint16		modulus[128];
	kal_uint16		exponent[128];
	/* Montgomery coefficient */
	kal_uint16		m_coeff;
} __attribute__((aligned(2), packed)) private_key_t;

typedef struct {
	/* 2048 bit RSA public key (modulus and public exponent) */
	kal_uint16		modulus[128];
	kal_uint16		exponent[2];
	/* Montgomery coefficient */
	kal_uint16		m_coeff;
} __attribute__((aligned(2), packed)) public_key_t;

typedef struct {
	/*Magic number*/
	kal_uint32 magic1;
	kal_uint32 magic2;
	/* Version number  */
	kal_uint16		version;
	/* Chip */
	kal_char			chip[4];
	/* Subject is the related information of  the customer */
	kal_char		subject[32];
	/* SBC public key */
	public_key_t	sbc_key;
        /* SLA public key */
	public_key_t	sla_key;
        /* DAA public key */
	public_key_t	daa_key;
	/* DA hash*/
	hash_t da_hash[DA_MAX_BLOCKS];
        /* The signature used to verify the integrity and
	 * authority of the certificate
	 */	
       kal_uint16 signature[128];
} __attribute__((aligned(2), packed)) tool_cert_t;

typedef struct {
	/*Magic number*/
	kal_uint32 magic1;
	kal_uint32 magic2;
	/* Version number  */
	kal_uint16		version;
	/* Chip */
	kal_char			chip[4];
	/* Subject is the related information of  the customer */
	kal_char		subject[32];
	/* SBC public key */
	public_key_t	sbc_key;
	/* Root public keys */
	hash_t	root_key_hash[ROOT_KEY_NUM];
	/* The signature used to verify the integrity and
	 * authority of the certificate
	 */
	kal_uint16 signature[128];
} __attribute__((aligned(2), packed)) root_cert_t;

typedef struct {
	/*Magic number*/
	kal_uint32 magic1;
	kal_uint32 magic2;
       /* Version number  */
	kal_uint16		version;
       /* Chip */
	kal_char			chip[4];
	/* Subject is the related information of  the customer */
	kal_char		subject[32];
	/* SBC public key */
	public_key_t	sbc_key;
       /* HW ID */
       kal_uint8        meid[MEID_LENGTH];
       /* Secure control */
       kal_uint16       disable_sla:1,
                        disable_daa:1,
                        disable_sbc:1,
                        enable_jtag:1,
                        reserved:12;
        /* The signature used to verify the integrity and
	 * authority of the certificate
	 */
	kal_uint16 signature[128];
}__attribute__((aligned(2), packed)) sctrl_cert_t;

typedef struct {
	/*Magic number*/
	kal_uint32 magic1;
	kal_uint32 magic2;
	/*size(not include head and signature)*/
	kal_uint32 da_size;
	/*Number of DA blocks*/
	kal_uint32 blocks;
}__attribute__((aligned(2), packed)) da_head_t;

#endif	/* BROM_CERTIFICATE_H */
