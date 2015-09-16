/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2005
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

/*****************************************************************************
 *
 * Filename:
 * ---------
 *    drv_features_chip_select.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is merged for all driver features.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * $Log$
 *
 * removed!
 * removed!
 * .add driver feature option for K2MD2 project
 *
 * removed!
 * removed!
 * add MT6752 driver feature header file
 *
 * removed!
 * removed!
 * add MT6291 driver feature definition
 *
 * removed!
 * removed!
 * Add MT6589 MD2 common driver settings: feature selection
 *
 * removed!
 * removed!
 * ROME Porting
 *
 * removed!
 * removed!
 * add for MT6595 common driver
 *
 * removed!
 * removed!
 * chip rename:MT7208 to MT6290
 * 
 * removed!
 * removed!
 * Integration change(non-devdrv/non-sys_drv driver part-2)
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * Merge drv features from MT6255_DVT branch to MAUI
 *
 * removed!
 * removed!
 * <saved by Perforce>
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 * removed!
 * removed!
 * .
 *
 *
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClaseCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifndef __DRV_FEATURES_CHIP_SELSECT_H__
#define __DRV_FEATURES_CHIP_SELSECT_H__

#if defined(MT6268)
   #include "drv_features_6268.h"
   /*Above is MT6268T*/
#elif defined(MT6268T)
   #include "drv_features_6268t.h"
   /*Above is MT6268T*/
#elif defined(MT6268H)
   #include "drv_features_6268h.h"
   /*Above is MT6268H*/
#elif defined(MT6268A)
   #include "drv_features_6268A.h"
   /*Above is MT6268A*/
#elif defined(MT6235)
   #include "drv_features_6235.h"
   /*Above is MT6235*/   
#elif defined(MT6235B)
   #include "drv_features_6235B.h"
   /*Above is MT6235B*/   
#elif defined(MT6236)
   #include "drv_features_6236.h"
   /*Above is MT6236*/   
#elif defined(MT6236B)
   #include "drv_features_6236B.h"
   /*Above is MT6236B*/   
#elif defined(TK6516)
   #include "drv_features_tk6516.h"
   /*Above is TK6516*/
#elif defined(MT6516)
   #include "drv_features_mt6516.h"
   /*Above is MT6516*/
#elif defined(MT6253T)
   #include "drv_features_6253t.h"
   /* Above is MT6253T */
#elif defined(MT6253)
   #include "drv_features_6253.h"
   /* Above is MT6253 */
#elif defined(MT6253E)
   #include "drv_features_6253E.h"
   /* Above is MT6253E */
#elif defined(MT6253L)
   #include "drv_features_6253L.h"
   /* Above is MT6253L */
#elif defined(MT6255)
   #include "drv_features_6255.h"
   /* Above is MT6255 */   
#elif defined(MT6922)
   #include "drv_features_6922.h"
   /* Above is MT6255 */    
#elif defined(MT6250)
   #include "drv_features_6250.h"
   /* Above is MT6250 */ 
#elif defined(MT6280)
   #include "drv_features_6280.h"
   /* Above is MT6280 */ 
#elif defined(MT6270A)
   #include "drv_features_6270A.h"
   /* Above is MT6270A */
#elif defined(MT6256)
   #include "drv_features_6256.h"
   /* Above is MT6256 */
#elif defined(MT6276)
   #include "drv_features_6276.h"
   /* Above is MT6276 */
#elif defined(MT6251)
   #include "drv_features_6251.h"
   /* Above is MT6251 */
#elif defined(MT6252)
   #include "drv_features_6252.h"
   /* Above is MT6252 */
#elif defined(MT6252H)
   #include "drv_features_6252H.h"
   /* Above is MT6252H */
#elif defined(MT6573)
   #include "drv_features_6573.h"
   /* Above is MT6573 */
#elif defined(MT6575)
   #include "drv_features_6575.h"
   /* Above is MT6575 */
#elif defined(MT6577)
   #include "drv_features_6577.h"
   /* Above is MT6577 */
#elif defined(MT6290)
   #include "drv_features_6290.h"
   /* Above is MT6290 */
#elif defined(MT6291)
   #include "drv_features_6291.h"
   /* Above is MT6291 */
#elif defined(MT6595)
   #include "drv_features_6595.h"
   /* Above is MT6595 */
#elif defined(MT6752) && defined(__MD1__)
   #include "drv_features_6752.h"
   /* Above is MT6589 */
#elif defined(MT6752) && defined(__MD2__)
   #include "drv_features_6752md2.h"
   /* Above is MT6589 */
#else
   #error "The chip type is non-supported"
#endif   /*End of all chips*/


#endif   /*End __DRV_FEATURES_CHIP_SELSECT_H__*/
