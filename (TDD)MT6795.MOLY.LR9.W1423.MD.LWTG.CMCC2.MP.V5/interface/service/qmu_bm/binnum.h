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
 *   binnum.h
 *
 * Project:
 * --------
 *   MOLY
 *
 * Description:
 * ------------
 *
 *
 * Author:
 * -------
 * -------
 *   
 *
 * ==========================================================================
 * $Log$
 ****************************************************************************/
/**
 * 	@file binnum.h
 *	@brief binary number utilities 
 *	@author Howard Chen
 * 
 */
#ifndef BINNUM_DEF
#define BINNUM_DEF

#define BU_LOG2(_v)				(((_v)==64)? 6:					\
									((_v)==32)? 5: 				\
										((_v)==16)? 4: 			\
											((_v)==8)? 3: 		\
												((_v)==4)? 2: 	\
													((_v)==2)? 1:	\
														((_v)==0)? 0: -1)

#define BU_T_MSK(_n)				((1<<(_n))-1)
#define BU_F_MSK(_ms,_ls)			(BU_T_MSK((_ms)-(_ls)+1)<<(_ls))
#define BU_B_MSK(_n)				(1 << (_n))
#define BU_WID(_ms,_ls)				((_ms)-(_ls)+1)

#define BU_ALN(_i, _n)				((_i) & ~BU_T_MSK(_n))

#define BU_RUP(_i, _n)				BU_ALN((_i)+BU_T_MSK(_n), _n)

/**
 *	@brief trucate <_i> to <_n> bits
 */
#define BU_TRU(_i, _n)				((_i) & BU_T_MSK(_n))

/**
 *	@brief get (<_ms>:<_ls>) field
 */
#define BU_G_FLD(_i,_ms,_ls)	    (((_i)<<(31-(_ms))) >> (31- (_ms) + (_ls)))

/**
 *	@brief or (<_ms>:<_ls>) field
 */
#define BU_O_FLD(_i,_ms,_ls,_v)   	((_i)|((BU_TRU(_v,BU_WID(_ms,_ls))<<(_ls))))

/**
 *	@brief clean (<_ms>:<_ls>) field
 */
#define BU_C_FLD(_i,_ms,_ls)		((_i) & ~BU_F_MSK(_ms,_ls))

/**
 *	@brief replace (<_ms>:<_ls>) field with <_v>
 */
#define BU_R_FLD(_i,_ms,_ls,_v)		((((_i)&~BU_F_MSK(_ms,_ls)))|((BU_TRU(_v,BU_WID(_ms,_ls))<<(_ls))))
/**
 *	@brief get <_n> bit
 */
#define BU_G_BIT(_i,_n)				BU_G_FLD(_i, _n, _n)

/**
 *	@brief or <_n> bit with 0x1
 */
#define BU_O_BIT(_i,_n)				((_i) |(1 << (_n)))

/**
 *	@brief clean <_n> bit
 */
#define BU_C_BIT(_i,_n)				((_i) & ~BU_B_MSK(_n))

/**
 *	@brief replace <_n> bit with <_v>
 */
#define BU_R_BIT(_i,_n,_v)			(((_i)&~BU_B_MSK(_n))|(((_v)&0x1)<<(_n)))

#endif
