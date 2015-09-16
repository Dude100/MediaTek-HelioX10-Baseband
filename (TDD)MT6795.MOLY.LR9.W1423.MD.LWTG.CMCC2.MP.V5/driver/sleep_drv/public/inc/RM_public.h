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

/*******************************************************************************
 *
 * Filename:
 * ---------
 *    RM_public.h
 *
 * Project:
 * --------
 *    MT6280
 *
 * Description:
 * ------------
 *    Resource Management configuration
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/
#ifdef __CENTRALIZED_SLEEP_MANAGER__

#ifndef RM_PUBLIC_H
#define RM_PUBLIC_H

typedef enum
{
   /* Resource on MCU RM */
   RM_MCU_BASE = 0,

   /* Resource on MODEM RM */
   RM_MODEM_BASE = 10,
   RM_MODEM_DSP_1,
   RM_MODEM_DSP_2,
   RM_MODEM_L2_COPRO,
   NUMBER_OF_RM_MODEM
} RM_Module;

#if defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__))
typedef enum
{
    MD2AP,
    MD2DSP,
} MDTOPSM_PeerWakeup_Target;

typedef enum
{
	PWR_OFF,
	PWR_ON,
	PWR_CHANGE,
} sm_pwrstate_e;

typedef enum
{
    PLL_MSDC
} PLL_RQST;

typedef enum
{
    LTEL2,
    APPERI,
#ifdef MT6291
    HSPAL2SYS,
#endif
} MDTOPSM_Power_Domain;

#endif

typedef enum
{
   MODEM_TOPSM_EMI_REQ_GSM = 0x0,
   MODEM_TOPSM_EMI_REQ_UMTS = 0x1,
   MODEM_TOPSM_EMI_REQ_LTE = 0x2
} MODEM_TOPSM_EMI_REQ_MODULE;

void RM_Init( void );
void RM_Resource_Control( RM_Module module, kal_bool resource_on );
#if defined(MT6280)
void RM_Usb_Lock_Clock( kal_bool lock );
#endif
#if defined(MT6752) && defined(__MD2__)
void MD_TOPSM_UnGateMCUTOPSM(void);
#endif

#if defined(MT6290) || defined(MT6595) || (defined(MT6752) && defined(__MD1__))
void MD_TOPSM_PeerWakeup(MDTOPSM_PeerWakeup_Target target, kal_bool set);
void MD_TOPSM_PWR_SW_Control(MDTOPSM_Power_Domain pwr_dom, kal_bool enable);
void MD_TOPSM_SRCLK_SW_Control(kal_bool fOn);
#endif
kal_bool MODEM4G_TOPSM_WaitTimerAwake( void );
void MODEM_TOPSM_EMI_Request( MODEM_TOPSM_EMI_REQ_MODULE mod, kal_bool req );
void MODEM_TOPSM_EMI_RequestCheck( MODEM_TOPSM_EMI_REQ_MODULE mod );

#if defined(MT6290)
/******************************************************************************
*   Function : AP_TOPSM_PeerWakeup(kal_bool enable)
*   Description : This API will set/clear peer wakeup event from AP to MD
*   Parameter : kal_bool set (TRUE for set and FALSE for clear)
*   Return    : None
*   Note      :
******************************************************************************/
void AP_TOPSM_PeerWakeup(kal_bool set);


/******************************************************************************
*   Function : AP_TOPSM_PeerWakeupSta(void)
*   Description : This API will get peer wakeup status that wakeup event from AP to MD
*   Parameter : None
*   Return    : TRUE for AP wakeup MD and FALSE for no wakeup trigger
*   Note      :
******************************************************************************/
kal_bool AP_TOPSM_PeerWakeupMDSta();

#endif

#endif /* !RM_PUBLIC_H */
#endif /*__CENTRALIZED_SLEEP_MANAGER__*/
