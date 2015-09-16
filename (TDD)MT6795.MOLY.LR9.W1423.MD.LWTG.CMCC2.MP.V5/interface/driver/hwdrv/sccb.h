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
 *   sccb.h
 *
 * Project:
 * --------
 *   MT6219
 *
 * Description:
 * ------------
 *   SCCB interface
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
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 * removed!
 *
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 *
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
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
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 * removed!
 * removed!
 *
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/


#ifndef __SCCB_H__
#define __SCCB_H__

#include "dcl.h"

#include "kal_general_types.h"

#if 0
#if (defined(MT6219)||defined(MT6228)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
/* under construction !*/
#endif // #if (defined(MT6219)||defined(MT6228)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230))
/* under construction !*/
#if ( defined(MT6219)||defined(MT6228)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230)\
      ||defined(MT6225)||defined(MT6223)||defined(MT6223P)||defined(MT6235)||defined(MT6235B)||defined(MT6238)||defined(MT6239)||defined(MT6268A)\
      ||defined(MT6239)||defined(MT6253T)||defined(MT6253)||defined(MT6236)||defined(MT6236B) )
/* under construction !*/
#endif // SCCB_XXX API supported platforms list
/* under construction !*/
#endif

#if 0
#if defined(__SCCB_MODULE_V1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (!defined(MT6219))
/* under construction !*/
#endif // #if (!defined(MT6219))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230)||defined(MT6223)||defined(MT6223P))
/* under construction !*/
#endif // #if (defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D)||defined(MT6229)||defined(MT6230)||defined(MT6223)||defined(MT6223P))
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__SCCB_MODULE_V1__)
#endif

#if 0
#ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#else // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #ifdef __CUST_NEW__
/* under construction !*/
#endif //#if 0

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0


// SCCB PINS definition


#ifdef __CUST_NEW__
//#include "gpio_sw.h"
extern const char gpio_sccb_serial_clk_pin;
extern const char gpio_sccb_serial_data_pin;
#endif // #ifdef __CUST_NEW__


#if 0
#if (defined(MT6276))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#elif (defined(MT6256))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif
/* under construction !*/
#if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
  #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
  #else // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
  #endif // #ifdef __CUST_NEW__
#endif // #if (defined(MT6219)||defined(MT6226)||defined(MT6226M)||defined(MT6226D)||defined(MT6227)||defined(MT6227D))
/* under construction !*/
#if (defined(MT6228)||defined(MT6229)||defined(MT6230))
  #ifdef __CUST_NEW__
    #if (defined(DVT_TEST))
/* under construction !*/
/* under construction !*/
    #else // #if (defined(DVT_TEST))
/* under construction !*/
/* under construction !*/
    #endif // #if (defined(DVT_TEST))
  #else // #ifdef __CUST_NEW__
    #if (defined(DVT_TEST))
/* under construction !*/
/* under construction !*/
    #else // #if (defined(DVT_TEST))
/* under construction !*/
/* under construction !*/
    #endif // #if (defined(DVT_TEST))
  #endif // #ifdef __CUST_NEW__
#endif // #if (defined(MT6228)||defined(MT6229)||defined(MT6230))
/* under construction !*/
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6223))
  #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
  #else // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
  #endif // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
#endif // #if (defined(DRV_GPIO_REG_AS_6223))
/* under construction !*/
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6225))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif // #if (defined(DRV_GPIO_REG_AS_6225))
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6238))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
#endif // #if (defined(DRV_GPIO_6238_SERIES))
/* under construction !*/
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6235))
   #ifdef __CUST_NEW__
     #if defined(EMPTY_MMI)
/* under construction !*/
/* under construction !*/
     #else // #if defined(EMPTY_MMI)
/* under construction !*/
/* under construction !*/
      #endif // #if defined(EMPTY_MMI)
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
#endif // #if (defined(DRV_GPIO_6235_SERIES))
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6268A))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
#endif // #if (defined(DRV_GPIO_REG_AS_6268A))
/* under construction !*/
#if(defined(DRV_GPIO_REG_AS_6268))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #endif // #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
#endif // #if(defined(DRV_GPIO_REG_AS_6268))
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6253T))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif // #if (defined(DRV_GPIO_REG_AS_6253T))
/* under construction !*/
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6253E)&&defined(MT6253E)&&defined(__SERIAL_SENSOR_V1_SUPPORT__))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#elif (defined(DRV_GPIO_REG_AS_6253E)&&defined(MT6253E))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6253E)&&defined(MT6253L))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
   #endif /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif 
/* under construction !*/
#if (defined(DRV_GPIO_REG_AS_6236))
   #ifdef __CUST_NEW__
/* under construction !*/
/* under construction !*/
   #else /* __CUST_NEW__ */
/* under construction !*/
/* under construction !*/
#endif /*__CUST_NEW__*/
/* under construction !*/
/* under construction !*/
#endif // #if (defined(DRV_GPIO_REG_AS_6236))
/* under construction !*/
#endif
///Bin: added to patch build error
#ifndef SCCB_SERIAL_CLK_PIN
   #define SCCB_SERIAL_CLK_PIN		gpio_sccb_serial_clk_pin
#endif

#ifndef SCCB_SERIAL_DATA_PIN
   #define SCCB_SERIAL_DATA_PIN		gpio_sccb_serial_data_pin
#endif

#if 0
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#if defined(__SCCB_MODULE_V1__)
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif // #if defined(__SCCB_MODULE_V1__)
#endif //#if 0

#endif // #ifndef __SCCB_H__

