/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   bus_monitor_mt6280.h
 *
 * Project:
 * --------
 *   MAUI
 *
 * Description:
 * ------------
 *   Header file for MT6280 EMI BUS monitor control.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#if !defined(__EMI_BUS_MONITOR_MT6280_H__)
#define __EMI_BUS_MONITOR_MT6280_H__


/* RHR Add */
#include "reg_base.h"
#include "kal_general_types.h"
#include "kal_public_api.h"



#define SEL_EMI_CYCLE_SET		0x00000800
#define BUS_MON_CLK_ON_SET	0x00000080


/*******************************************************************************
 * Define constants.
 *******************************************************************************/

/*
 * M0 : CPU
 * M1 : AP SYS
 * M2 : MODEM SYS
 * M3 : MDP SYS
 */
enum { CPU = 0x1, AP_SYS = 0x2, MODEM_SYS = 0x4, MDP_SYS = 0x08, DUMMY_READ = 0x80 };

enum { Read_Write = 0x0, Read_Only = 0x1, Write_Only = 0x2 };

// different from ARM11:  INC8_4B, WR8_4B
enum { SINGLE_1B = 0x40, SINGLE_2B = 0x50, SINGLE_4B = 0x60, SINGLE_8B = 0x70,
       INC2_4B = 0x61, INC2_8B = 0x71, INC3_4B = 0x62, INC3_8B = 0x72, 
       INC4_4B = 0x63, INC4_8B = 0x73, INC5_4B = 0x64, INC6_4B = 0x65, 
       INC7_4B = 0x66, INC8_4B = 0x67, WR2_8B = 0x31, WR4_8B = 0x33, WR8_4B = 0x27 };

/*******************************************************************************
 * Define data structures.
 *******************************************************************************/

/* data structure for EMI transaction counts */
typedef struct _EBM_TCNT_LOG_T
{
    kal_uint32 bus_ccnt;
    kal_uint32 trans_all_cnt;
    kal_uint32 trans_cnt;
    kal_uint32 word_all_cnt;
    kal_uint32 word_cnt;
    kal_uint32 busy_all_cnt;
    kal_uint32 busy_cnt;
} EBM_TCNT_LOG_T;

/* data structure for EMI transaction type */
typedef struct _EBM_TTYPE_LOG_T
{
    kal_uint32 ttype1, ttype2, ttype3, ttype4, ttype5, ttype6;
} EBM_TTYPE_LOG_T;

/* data structure for EMI transcation log */
typedef struct _EBM_LOG_T
{
    EBM_TCNT_LOG_T tcnt;
    EBM_TTYPE_LOG_T ttype;
} EBM_LOG_T;


/*******************************************************************************
 * Define macros.
 *******************************************************************************/

#define EBM_SEL_MASTER(c, m)    \
        do {    \
            if ((c) == 1) { \
                *EMI_BMEN = (*EMI_BMEN & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 2) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xffffff00) | (m); \
            } else if ((c) == 3) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 4) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xffffff00) | (m); \
            } else if ((c) == 5) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 6) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xffffff00) | (m); \
            } else if ((c) == 7) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 8) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xffffff00) | (m); \
            } else if ((c) == 9) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 10) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xffffff00) | (m); \
            } else if ((c) == 11) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 12) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xffffff00) | (m); \
            } else if ((c) == 13) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 14) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xffffff00) | (m); \
            } else if ((c) == 15) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 16) {  \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0xffffff00) | (m); \
            } else if ((c) == 17) {  \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 18) {  \
                *EMI_MSEL9 = (*EMI_MSEL9 & 0xffffff00) | (m); \
            } else if ((c) == 19) {  \
                *EMI_MSEL9 = (*EMI_MSEL9 & 0xff00ffff) | ((m) << 16); \
            } else if ((c) == 20) {  \
                *EMI_MSEL10 = (*EMI_MSEL10 & 0xffffff00) | (m); \
            } else if ((c) == 21) {  \
                *EMI_MSEL10 = (*EMI_MSEL10 & 0xff00ffff) | ((m) << 16); \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_SEL_TTYPE(c, t) \
        do {    \
            if ((c) == 1) { \
                *EMI_BMEN = (*EMI_BMEN & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 2) {  \
                *EMI_MSEL = (*EMI_MSEL & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 3) {  \
                *EMI_MSEL = (*EMI_MSEL & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 4) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 5) {  \
                *EMI_MSEL2 = (*EMI_MSEL2 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 6) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 7) {  \
                *EMI_MSEL3 = (*EMI_MSEL3 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 8) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 9) {  \
                *EMI_MSEL4 = (*EMI_MSEL4 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 10) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 11) {  \
                *EMI_MSEL5 = (*EMI_MSEL5 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 12) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 13) {  \
                *EMI_MSEL6 = (*EMI_MSEL6 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 14) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 15) {  \
                *EMI_MSEL7 = (*EMI_MSEL7 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 16) {  \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 17) {  \
                *EMI_MSEL8 = (*EMI_MSEL8 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 18) {  \
                *EMI_MSEL9 = (*EMI_MSEL9 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 19) {  \
                *EMI_MSEL9 = (*EMI_MSEL9 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else if ((c) == 20) {  \
                *EMI_MSEL10 = (*EMI_MSEL10 & 0xffff00ff) | ((kal_uint32)(t) << 8); \
            } else if ((c) == 21) {  \
                *EMI_MSEL10 = (*EMI_MSEL10 & 0x00ffffff) | ((kal_uint32)(t) << 24); \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_SET_RW_REQ(v) \
        {\
        	*EMI_BMEN = (*EMI_BMEN & 0xffffffcf) | ((v) << 4);\
        }
        
#define EBM_Start() \
        {\
        	*EMI_BMEN |= 0x401;\
        }

#define EBM_Pause_LOG() \
        {\
        	*EMI_BMEN |= 2;\
        }

#define EBM_Check_Overrun() ((*EMI_BMEN&0x100)==0?KAL_FALSE:KAL_TRUE)

#define EBM_GET_TCNT_LOG(c, l)   \
        do {    \
        	(l)->bus_ccnt = *EMI_BCNT;  \
        	(l)->trans_all_cnt = *EMI_TACT; \
        	(l)->word_all_cnt = *EMI_WACT;  \
        	(l)->busy_all_cnt = *EMI_BACT;  \
            if ((c) == 1) { \
                (l)->trans_cnt = *EMI_TSCT; \
                (l)->word_cnt = *EMI_WSCT;  \
                (l)->busy_cnt = *EMI_BSCT;  \
            } else if ((c) == 2) {  \
                (l)->trans_cnt = *EMI_TSCT2; \
                (l)->word_cnt = *EMI_WSCT2;  \
                (l)->busy_cnt = 0;  \
            } else if ((c) == 3) {  \
                (l)->trans_cnt = *EMI_TSCT3; \
                (l)->word_cnt = *EMI_WSCT3;  \
                (l)->busy_cnt = 0;  \
            } else {    \
                ASSERT(0);  \
            }   \
        } while (0)

#define EBM_GET_TTYPE_LOG(l)    \
        do {    \
            (l)->ttype1 = *(EMI_TTYPE1);    \
            (l)->ttype2 = *(EMI_TTYPE2);    \
            (l)->ttype3 = *(EMI_TTYPE3);    \
            (l)->ttype4 = *(EMI_TTYPE4);    \
            (l)->ttype5 = *(EMI_TTYPE5);    \
            (l)->ttype6 = *(EMI_TTYPE6);    \
        } while (0)

#define EBM_Clear_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffc;\
        }

#define EBM_Restart_Counter() \
        {\
        	*EMI_BMEN &= 0xfffffffd;\
        }

// for MT6255 add:
#define EBM_Clock_On() \
        {\
        	*EMI_BMEN |= BUS_MON_CLK_ON_SET ;\
        }

// for MT6255 add:
#define EBM_SEL_EMI_CYCLE() \
        {\
        	*EMI_BMEN |= SEL_EMI_CYCLE_SET ;\
        }

/*******************************************************************************
 * Implement abstration interface.
 *******************************************************************************/
/*
#define EBM_INIT()  \
        do {    \
            EBM_Clear_Counter();    \
            EBM_SEL_MASTER(1, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_MASTER(2, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_MASTER(3, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_MASTER(4, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_MASTER(5, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_MASTER(6, MCU_IBUS|MCU_DBUS);    \
            EBM_SEL_TTYPE(1, SINGLE_1B);    \
            EBM_SEL_TTYPE(2, SINGLE_2B);    \
            EBM_SEL_TTYPE(3, SINGLE_4B);    \
            EBM_SEL_TTYPE(4, INC4_4B);    \
            EBM_SEL_TTYPE(5, INC8_4B);      \
            EBM_SEL_TTYPE(6, WR8_4B);      \
            EBM_SET_RW_REQ(Read_Write);     \
        } while (0)
*/

/* To Marvin: Standard setting, for SWLA EBM-addon; 
							will be used in sst_concurrent_utility.c:Enable_Normal_EMI_Monitor() 
 */
#define EBM_INIT()  \
        do {    \
            EBM_Clock_On();    \
            EBM_Clear_Counter();    \
            EBM_SEL_MASTER(1, CPU);    \
            EBM_SEL_MASTER(2, AP_SYS);    \
            EBM_SEL_MASTER(3, MODEM_SYS);    \
            EBM_SEL_MASTER(4, 0);    \
            EBM_SEL_MASTER(5, 0);    \
            EBM_SEL_MASTER(6, 0);    \
            EBM_SEL_TTYPE(1, 0);    \
            EBM_SEL_TTYPE(2, 0);    \
            EBM_SEL_TTYPE(3, 0);    \
            EBM_SEL_TTYPE(4, 0);    \
            EBM_SEL_TTYPE(5, 0);      \
            EBM_SEL_TTYPE(6, 0);      \
            EBM_SET_RW_REQ(Read_Write);     \
        } while (0)

#define EBM_START() \
        do {    \
            EBM_Start();    \
        } while (0)

#define EBM_PAUSE() \
        do {    \
            EBM_Pause_LOG();    \
        } while (0)

#define EBM_GET_MCU_IBUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(1, &((l)->tcnt)); \
        } while (0)

#define EBM_GET_MCU_DBUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(2, &((l)->tcnt)); \
            EBM_GET_TTYPE_LOG(&((l)->ttype));   \
        } while (0)

#define EBM_GET_MCU_BUS_LOG(l)  \
        do {    \
            kal_bool ret;   \
            ret = EBM_Check_Overrun();  \
            ASSERT(ret == KAL_FALSE);   \
            EBM_GET_TCNT_LOG(3, &((l)->tcnt)); \
            EBM_GET_TTYPE_LOG(&((l)->ttype));   \
        } while (0)
        
#define EBM_RESUME()    \
        do {    \
            EBM_Restart_Counter();  \
        } while (0)

#define EBM_STOP()  \
        do {    \
            EBM_Clear_Counter() \
        } while (0)

#endif  /* !__EMI_BUS_MONITOR_MT6280_H__ */

