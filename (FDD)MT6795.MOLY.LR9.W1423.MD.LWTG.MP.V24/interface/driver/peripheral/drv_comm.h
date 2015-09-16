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
 *    drv_comm.h
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This file is intends for driver common interface.
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
 * update NPW Driver API for MT6595
 *
 * 12 10 2012 po.hu
 * removed!
 * .
 *
 * removed!
 * removed!
 * add dbg_flush and corresponding drvtest
 * 
 * removed!
 * removed!
 * Integration change(non-devdrv/non-sys_drv driver part-2)
 *
 * 06 11 2012 jy.lan
 * removed!
 * .
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * Qinghua Yu check in global enum (MSG & SAP) at modem_dev.
 *
 * removed!
 * removed!
 * fix build error
 *
 * removed!
 * removed!
 * fix build error
 *
 * 11 11 2011 jy.lan
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
 * .
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
 * add NFI bus mutex
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
 *    Rev 1.24   Jul 11 2005 17:41:48   mtk00288
 * add DEVICE_ID
 * Resolution for 11921: [LPWR][Add feature]Add LPWR module
 *
 *    Rev 1.23   20 Jun 2005 20:00:32   mtk00502
 * add MT6226/MT6227 compile option
 * Resolution for 11617: [DRV][New Feature]Add MT6226/M6227 compile option
 *
 *    Rev 1.22   May 17 2005 00:29:10   BM_Trunk
 * Karlos:
 * add copyright and disclaimer statement
 *
 *    Rev 1.21   Mar 19 2005 14:49:34   mtk00502
 * add 6228 compile option
 * Resolution for 10304: [Drirver][New Fearture]Support MT6228
 *
 *    Rev 1.20   Jan 18 2005 00:34:22   BM
 * append new line in W05.04
 *
 *    Rev 1.19   Dec 10 2004 12:12:18   mtk00479
 * Add parentheses for the parameters of macro ()
 * Resolution for 9089: [Drv][Optimization]Add parentheses for the parameters of macro
 *
 *    Rev 1.18   Oct 12 2004 11:34:12   mtk00479
 * Add compile option of MT6217
 * Resolution for 8195: [Drv][NewFeature]Add compile option of MT6217
 *
 *    Rev 1.17   May 13 2004 22:15:40   mtk00479
 * Add for USB charging
 * Resolution for 5419: [Drv][AddFeature]Add USB charging function
 *
 *    Rev 1.16   Mar 25 2004 15:01:16   mtk00288
 * Add driver timing debug functions.
 * Resolution for 4496: [DRV][Add Feature]add driver timing debug functions
 *
 *    Rev 1.15   Mar 12 2004 14:00:30   mtk00502
 * define a macro to send msg
 * Resolution for 4231: [BMT][New Feature]add a function to translate voltage to temperature
 *
 *    Rev 1.14   Feb 27 2004 20:14:52   mtk00502
 * add 6219 compilt option
 * Resolution for 4005: [Driver][New Feature]add 6219 compile option
 *
 *    Rev 1.13   Feb 19 2004 19:51:30   mtk00502
 * to solve assert during RTC power on
 * Resolution for 3956: [Driver][New feature]solve assert during RTC power on
 *
 *    Rev 1.12   Feb 05 2004 18:57:28   mtk00288
 * add DRV_COMM_REG2_USBMS_PWRON definition
 * Resolution for 3839: [MMI USB DRV L4 UEM TST BMT] [New Feature] USB device integration
 *
 *    Rev 1.11   Dec 25 2003 10:03:36   mtk00479
 * Remove compile option of MT6205B for DRV_COMM_REG2_NORMAL_RESET and DRV_COMM_REG2_CHRPWRON.
 * Resolution for 3588: [Drv][BugFix]Remove compile option of MT6205B for DRV_COMM_REG2_NORMAL_RESET and DRV_COMM_REG2_CHRPWRON.
 *
 *    Rev 1.10   Oct 31 2003 15:27:24   mtk00502
 * add 6218B compile option
 * Resolution for 3233: [Driver][New Feature] Add 6218B compile option
 *
 *    Rev 1.8   Oct 02 2003 21:01:26   mtk00288
 * add the power on cause bit in DRV_COMM_REG2 register
 * Resolution for 3045: [DRV][Bugfix]Adjust the priority of power on cause
 *
 *    Rev 1.7   Jun 18 2003 22:37:28   mtk00288
 * Driver customize
 * Resolution for 2052: [DRV][Customize]Driver customize for different requirements
 *
 *    Rev 1.6   Jun 12 2003 16:10:22   mtk00288
 * add MT6218 definitions
 * Resolution for 1952: [Drivers][add Feature]MT6218 Peripherals driver
 *
 *    Rev 1.5   Apr 16 2003 21:43:24   mtk00288
 * add "()" in DRV_Reg&DRV_WriteReg macro
 * Resolution for 1547: [Drivers][Add Feature]Add MT6205B drivers
 *
 *    Rev 1.4   Feb 27 2003 16:41:48   mtk00288
 * add a macro(DRV_BuildPrimitive) to send primitive for driver.
 * Resolution for 1098: Add Accessory(AUX) Task to MAUI project
 *
 *    Rev 1.3   Feb 21 2003 15:40:02   mtk00288
 * extern dbg_print function, when DRV_DEBUG define
 * Resolution for 1011: Create ADC scheduler
 *
 *    Rev 1.2   Jan 23 2003 22:03:40   mtk00288
 * remove unnecessary comments.
 * Resolution for 491: BMT task and PMIC driver
 *
 *    Rev 1.1   Dec 16 2002 11:38:28   mtk00288
 * add kal_uint16 into DRV_WriteReg macro
 * Resolution for 9: Read/Write Register access
 *
 *    Rev 1.0   Nov 30 2002 19:49:58   admin
 * Initial revision.
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by ClearCase. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/



#ifndef __DRV_COMM_H__
#define __DRV_COMM_H__

#ifndef __CATEGORY_MODEM__
#include "drv_features.h"
#endif 
#include "kal_general_types.h"
#include "kal_public_defs.h"
#include "md_drv_sap.h"
#ifndef __CATEGORY_MODEM__
#include "reg_base.h"
#endif 
#include "kal_trace.h"

#if defined(DRV_MISC_LOW_COST_PROJ)
   #define __LOW_COST_PROJECT__
#endif



typedef enum {
    	io_low=0,
	   io_high
} IO_level;



typedef enum {
    	DEV_DMA=0,
    	DEV_USB,
    	DEV_GCU,
    	DEV_CHE,
    	DEV_PPP,
    	DEV_GPT,
    	DEV_KP,
    	DEV_GPIO,
    	DEV_UART1,
    	DEV_UART2,
    	DEV_UART3,
    	DEV_SIM,
    	DEV_PWM,
    	DEV_PWM2,
    	DEV_ALTER,
    	DEV_LCD,
    	DEV_MSDC,
    	DEV_TRC,
    	DEV_NFI,
    	DEV_B2SPI,
    	DEV_IRDA,
    	DEV_ADC,
    	DEV_RTC,
    	DEV_DIV,
    	DEV_FCS,
    	DEV_RZLB,
    	DEV_CRZ,
    	DEV_TV_OUT,
    	DEV_IPP,
    	DEV_PNG,
    	DEV_GIF,
    	DEV_GCMQ,
    	DEV_G2D,
    	DEV_MP4,
    	DEV_JPEG,
    	DEV_PRZ,
    	DEV_RESZ,
    	DEV_ISP,
    	DEV_DCT,
    	DEV_IMGDMA,
    	DEV_DRZ,
    	DEV_MSDC2,
    	DEV_SIM2,
      DEV_ROTDMA,
      DEV_CAM104M,
      DEV_LCD104M,
    	DEV_MAX_ID,
		DEV_NULL_ID = 0xfe
} DEVICE_ID_ENUM;



typedef void (* VOID_FUNC)(void);

//#define __DRV_COMM_REG_DBG__
#ifdef __DRV_COMM_REG_DBG__

#define MAX_DRV_COMM_REG_DBG_INFO_SIZE 2048	/*must be 2^n*/

typedef struct{
   kal_uint8       write_flag;
   kal_uint16      line_number;
   kal_uint32      reg_addr;
   kal_uint32      reg_value;
   kal_uint32      time_log;
}DRV_COMM_REG_DBG_DATA;

typedef struct{
   DRV_COMM_REG_DBG_DATA   	dbg_data[MAX_DRV_COMM_REG_DBG_INFO_SIZE];
   kal_uint16     		      dbg_data_idx;
}DRV_REG_DBG_STRUCT;

#define DRV_DBG_WriteReg(addr,data)    drv_reg_dbg_trace_write16(__LINE__, addr, data)

#define DRV_DBG_Reg(addr)      drv_reg_dbg_trace_read16(__LINE__, addr)

#define DRV_DBG_WriteReg32(addr,data)  drv_reg_dbg_trace_write32(__LINE__, addr, data)

#define DRV_DBG_Reg32(addr)     drv_reg_dbg_trace_read32(__LINE__, addr)

#define DRV_DBG_WriteReg8(addr,data)   drv_reg_dbg_trace_write8(__LINE__, addr, data)

#define DRV_DBG_Reg8(addr)      drv_reg_dbg_trace_read8(__LINE__, addr)

#define DRV_DBG_ClearBits(addr,data)     {\
   kal_uint16 temp;\
   temp = DRV_DBG_Reg(addr);\
   temp &=~(data);\
   DRV_DBG_WriteReg(addr,temp);\
}

#define DRV_DBG_SetBits(addr,data)     {\
   kal_uint16 temp;\
   temp = DRV_DBG_Reg(addr);\
   temp |= (data);\
   DRV_DBG_WriteReg(addr,temp);\
}

#define DRV_DBG_SetData(addr, bitmask, value)     {\
   kal_uint16 temp;\
   temp = (~(bitmask)) & DRV_DBG_Reg(addr);\
   temp |= ((value) & (bitmask));\
   DRV_DBG_WriteReg(addr,temp);\
}

#define DRV_DBG_ClearBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_DBG_Reg32(addr);\
   temp &=~(data);\
   DRV_DBG_WriteReg32(addr,temp);\
}

#define DRV_DBG_SetBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_DBG_Reg32(addr);\
   temp |= (data);\
   DRV_DBG_WriteReg32(addr,temp);\
}

#define DRV_DBG_SetData32(addr, bitmask, value)     {\
   kal_uint32 temp;\
   temp = (~(bitmask)) & DRV_DBG_Reg32(addr);\
   temp |= ((value) & (bitmask));\
   DRV_DBG_WriteReg32(addr,temp);\
}

#define DRV_DBG_ClearBits8(addr,data)     {\
   kal_uint8 temp;\
   temp = DRV_DBG_Reg8(addr);\
   temp &=~(data);\
   DRV_DBG_WriteReg8(addr,temp);\
}

#define DRV_DBG_SetBits8(addr,data)     {\
   kal_uint8 temp;\
   temp = DRV_DBG_Reg8(addr);\
   temp |= (data);\
   DRV_DBG_WriteReg8(addr,temp);\
}

#define DRV_DBG_SetData8(addr, bitmask, value)     {\
   kal_uint8 temp;\
   temp = (~(bitmask)) & DRV_DBG_Reg8(addr);\
   temp |= ((value) & (bitmask));\
   DRV_DBG_WriteReg8(addr,temp);\
}

extern void drv_reg_dbg_trace_write16(kal_uint16 line, kal_uint32 addr, kal_uint32 data);
extern void drv_reg_dbg_trace_write32(kal_uint16 line, kal_uint32 addr, kal_uint32 data);
extern void drv_reg_dbg_trace_write8(kal_uint16 line, kal_uint32 addr, kal_uint32 data);
extern kal_uint16 drv_reg_dbg_trace_read16(kal_uint16 line, kal_uint32 addr);
extern kal_uint32 drv_reg_dbg_trace_read32(kal_uint16 line, kal_uint32 addr);
extern kal_uint32 drv_reg_dbg_trace_read8(kal_uint16 line, kal_uint32 addr);

#endif //__DRV_COMM_REG_DBG__

#define DRV_WriteReg(addr,data)     ((*(volatile kal_uint16 *)(addr)) = (kal_uint16)(data))
#define DRV_Reg(addr)               (*(volatile kal_uint16 *)(addr))
#define DRV_WriteReg32(addr,data)     ((*(volatile kal_uint32 *)(addr)) = (kal_uint32)(data))
#define DRV_Reg32(addr)               (*(volatile kal_uint32 *)(addr))
#define DRV_WriteReg8(addr,data)     ((*(volatile kal_uint8 *)(addr)) = (kal_uint8)(data))
#define DRV_Reg8(addr)               (*(volatile kal_uint8 *)(addr))

#define DRV_SetReg8(addr, data)     (DRV_WriteReg8(addr, DRV_Reg8(addr)|(data)))
#define DRV_ClrReg8(addr, data)     (DRV_WriteReg8(addr, DRV_Reg8(addr)&~(data)))
#define DRV_SetReg(addr, data)      (DRV_WriteReg(addr, DRV_Reg(addr)|(data)))
#define DRV_ClrReg(addr, data)      (DRV_WriteReg(addr, DRV_Reg(addr)&~(data)))
#define DRV_SetReg32(addr, data)    (DRV_WriteReg32(addr, DRV_Reg32(addr)|(data)))
#define DRV_ClrReg32(addr, data)    (DRV_WriteReg32(addr, DRV_Reg32(addr)&~(data)))

#if defined(MT6290)
    #define SOREG_OFFSET 0xF0000000   //Strongly Order Region
#else
    #define COMMON_PLATFORM_MAP
#endif


/* DRV_WriteReg32_NPW, DRV_WriteReg32_NPW_RB provide non-post-write operation
   Abbreviation:
       NPW: Non Post Write
       RB : Read Back
   Description:
       1. DRV_WriteReg32_NPW: In System with strongly order memory attribute
          (write response from target hardware IP), we just write the data
          into the strongly order region (write_addr | 0xF000_0000)
       2. DRV_WriteReg32_NPW: In System without strongly order memory attribute,
          we write the data into the write_addr and read the write_addr
          back to avoid the write data is buffered in bus fabric
       3. DRV_WriteReg32_NPW_RB: In some hardware IP design, reading the 
          write_addr has some side-effects, in order to avoid this situation, 
          DRV_WriteReg32_NPW_RB is provided and the read_addr of 
          DRV_WriteReg32_NPW_RB is assigned by the user.
          User must confirm that all previous write operations are finished 
          before the data of read_addr ready.
          For example, write_addr in IP-A, read_addr in IP-B can't make sure the
          IP-A write operation is finished. write_addr/read_addr must be in the 
          same IP.
       4. DRV_WriteReg32_NPW_RB: For system with strongly order memory
          attribute, DRV_WriteReg32_NPW_RB does NOT read the read_addr
          (the same behavior with DRV_WriteReg32_NPW).
       5. Memory barrier operations (DMB/DSB in ARM Arch.) are not included in 
          DRV_WriteReg32_NPW_RB and DRV_WriteReg32_NPW.
 */

#if defined(MT6290)
    #define DRV_WriteReg32_NPW_RB(write_addr, data, read_addr)         \
        DRV_WriteReg32(((kal_uint32)(write_addr))|SOREG_OFFSET, data);
    #define DRV_WriteReg32_NPW(write_addr, data)                       \
        DRV_WriteReg32_NPW_RB(write_addr, data, write_addr)
    #define DRV_SetReg32_NPW(write_addr, data)  \
        DRV_WriteReg32(((kal_uint32)(write_addr))|SOREG_OFFSET, DRV_Reg32(write_addr) | (data))
    #define DRV_ClrReg32_NPW(write_addr, data)  \
        DRV_WriteReg32(((kal_uint32)(write_addr))|SOREG_OFFSET, DRV_Reg32(write_addr) & (~(data)))
#elif defined(COMMON_PLATFORM_MAP)
    #define DRV_WriteReg32_NPW_RB(write_addr, data, read_addr)         \
    do{                                                                \
        if((write_addr)>=0x88000000U && (write_addr)<=0x8FFFFFFFU)     \
        {                                                              \
            DRV_WriteReg32((write_addr)&(~(0x08000000)), (data));      \
        }                                                              \
        else if( ((write_addr)>>28)==0xB )                             \
        {                                                              \
            DRV_WriteReg32((write_addr)&(~(0x10000000)), (data));      \
        }                                                              \
        /* Strongly Order: 0x80000000~0x87FFFFFF/0xA0000000 */         \
        else if( (((write_addr)>>28)==8) || (((write_addr)>>28)==0xA) )    \
        {                                                              \
            DRV_WriteReg32((write_addr), (data));                      \
        }                                                              \
        else                                                           \
        {                                                              \
            ASSERT(0);                                                 \
        }                                                              \
    }while(0);

    #define DRV_WriteReg32_NPW(write_addr, data)                       \
        DRV_WriteReg32_NPW_RB(write_addr, data, write_addr)
    #define DRV_SetReg32_NPW(write_addr, data)                         \
        DRV_WriteReg32_NPW(((kal_uint32)(write_addr)), DRV_Reg32(write_addr) | (data))
    #define DRV_ClrReg32_NPW(write_addr, data)                         \
        DRV_WriteReg32_NPW(((kal_uint32)(write_addr)), DRV_Reg32(write_addr) & (~(data)))
#else
	/* TBC */
	#error "NPW API: unsupported CHIP"
#endif /* end of TK6280/MT6290/others */

#define DRV_ClearBits(addr,data)     {\
   kal_uint16 temp;\
   temp = DRV_Reg(addr);\
   temp &=~(data);\
   DRV_WriteReg(addr,temp);\
}

#define DRV_SetBits(addr,data)     {\
   kal_uint16 temp;\
   temp = DRV_Reg(addr);\
   temp |= (data);\
   DRV_WriteReg(addr,temp);\
}

#define DRV_SetData(addr, bitmask, value)     {\
   kal_uint16 temp;\
   temp = (~(bitmask)) & DRV_Reg(addr);\
   temp |= ((value) & (bitmask));\
   DRV_WriteReg(addr,temp);\
}

#define DRV_ClearBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_Reg32(addr);\
   temp &=~(data);\
   DRV_WriteReg32(addr,temp);\
}

#define DRV_SetBits32(addr,data)     {\
   kal_uint32 temp;\
   temp = DRV_Reg32(addr);\
   temp |= (data);\
   DRV_WriteReg32(addr,temp);\
}

#define DRV_SetData32(addr, bitmask, value)     {\
   kal_uint32 temp;\
   temp = (~(bitmask)) & DRV_Reg32(addr);\
   temp |= ((value) & (bitmask));\
   DRV_WriteReg32(addr,temp);\
}

#define DRV_ClearBits8(addr,data)     {\
   kal_uint8 temp;\
   temp = DRV_Reg8(addr);\
   temp &=~(data);\
   DRV_WriteReg8(addr,temp);\
}

#define DRV_SetBits8(addr,data)     {\
   kal_uint8 temp;\
   temp = DRV_Reg8(addr);\
   temp |= (data);\
   DRV_WriteReg8(addr,temp);\
}

#define DRV_SetData8(addr, bitmask, value)     {\
   kal_uint8 temp;\
   temp = (~(bitmask)) & DRV_Reg8(addr);\
   temp |= ((value) & (bitmask));\
   DRV_WriteReg8(addr,temp);\
}

#define DRV_BuildPrimitive(_ilm,_srcid,_dstid,_msgid,_data) \
{\
   _ilm->src_mod_id = _srcid;\
   _ilm->sap_id = DRIVER_PS_SAP;\
   _ilm->dest_mod_id = _dstid;\
   _ilm->msg_id = _msgid;\
   _ilm->local_para_ptr = (local_para_struct *)_data;\
   _ilm->peer_buff_ptr = NULL;\
}

#define DRV_SendPrimitive(_ilm,_srcid,_dstid,_msgid,_data, _sap_id) \
{\
   _ilm->src_mod_id = _srcid;\
   _ilm->sap_id = _sap_id;\
   _ilm->dest_mod_id = _dstid;\
   _ilm->msg_id = _msgid;\
   _ilm->local_para_ptr = (local_para_struct *)_data;\
   _ilm->peer_buff_ptr = NULL;\
}

extern void Fast_Memcpy(void *srcaddr, void *dstaddr, kal_uint32 leng);
extern void Fast_SherifWrite(void *srcaddr,void *dstaddr,kal_uint32 len);
extern void Fast_SherifRead(void *srcaddr,void *dstaddr,kal_uint32 len);
// MoDIS parser skip start
extern kal_uint32 SaveAndSetIRQMask(void);
extern void RestoreIRQMask(kal_uint32);
extern boot_mode_type Drv_query_boot_mode(void);
// MoDIS parser skip end
extern kal_uint32 drv_get_current_time(void);
extern kal_uint32 drv_get_duration_tick(kal_uint32 previous_time, kal_uint32 current_time);
extern kal_uint32 drv_get_duration_ms(kal_uint32 previous_time);

// MoDIS parser skip start
/// NFI bus mutex
void get_NFI_bus(void);
void free_NFI_bus(void);

#if defined(DRV_DEBUG) || defined(ATEST_DRV_ENABLE)
extern void dbg_print(char *fmt,...);
extern void dbg_printWithTime(char *fmt,...);
extern void dbg_flush(void);
#endif   /*DRV_DEBUG*/
// MoDIS parser skip end

#ifdef DRV_MEMORY_TRACE_DEBUG

   #define MAX_DRV_DBG_INFO_SIZE 2048
   typedef enum {
      NAND_READ_START,
      NAND_READ_STOP,
      DRV_DBG_MAX_ID
   } DRV_DBG_ID;

   typedef struct{
      kal_uint16      tag;
      kal_uint32      time;
      kal_uint32      data1;
      kal_uint32      data2;
   }DRV_DBG_DATA;

   typedef struct{
      DRV_DBG_DATA   dbg_data[MAX_DRV_DBG_INFO_SIZE];
   kal_uint16     dbg_data_idx;
   }DRV_DBG_STRUCT;

extern void drv_dbg_trace(kal_uint16 index, kal_uint32 time, kal_uint32 data1, kal_uint32 data2);
#endif   /*DRV_MEMORY_TRACE_DEBUG*/

#if defined(__MTK_TARGET__)
#if defined(__RVCT__)
/* This marco is to get the reture address of the caller function. */
#define DRV_GET_RET_ADDR(retAddr)  {\
   retAddr = __return_address();\
}

/* This marco is to provide a for loop delay with the count as the parameter. 
   To add NOP is to prevent it from being optimized. */
#define DRV_FOR_LOOP(_count) \
{\
   kal_uint32 loop;\
   for (loop=0;loop<_count;loop++)\
   {\
      __nop();\
      }\
   }\
}\

#elif defined(__GNUC__)

/* This marco is to get the reture address of the caller function. */
/* GCC has function to support this */
#define DRV_GET_RET_ADDR(retAddr)  {\
   retAddr = __builtin_return_address (0);\
}

/* This marco is to provide a for loop delay with the count as the parameter. 
   To add NOP is to prevent it from being optimized. */
#define DRV_FOR_LOOP(_count) \
{\
   kal_uint32 loop;\
   for (loop=0;loop<_count;loop++)\
   {\
      __nop();\
      }\
   }\
}\
        
#else   /* __RVCT__ */

/* This marco is to get the reture address of the caller function. */
#define DRV_GET_RET_ADDR(retAddr)  {\
           __asm {\
            MOV retAddr,lr\
        }\
}

/* This marco is to provide a for loop delay with the count as the parameter. 
   To add NOP is to prevent it from being optimized. */
#define DRV_FOR_LOOP(_count) \
{\
   kal_uint32 loop;\
   for (loop=0;loop<_count;loop++)\
   {\
      __asm {\
        NOP\
      }\
   }\
}\

#endif  /* __RVCT__ */

#else //#if defined(__MTK_TARGET__)

#define DRV_GET_RET_ADDR(retAddr)

#define DRV_FOR_LOOP(_count)

#endif //#if defined(__MTK_TARGET__)
/*************************************************************************
   APIs for driver debugging 
*************************************************************************/
// MoDIS parser skip start
#if defined(__TST_MODULE__)|| defined(L1_SIM)
#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)
INLINE_MODIFIER INLINE void drv_trace0(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type)
{
   return;
}
INLINE_MODIFIER INLINE void drv_trace1(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1)
{
   return;
}
INLINE_MODIFIER INLINE void drv_trace2(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2)
{
   return;
}
INLINE_MODIFIER INLINE void drv_trace4(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4)
{
   return;
}
INLINE_MODIFIER INLINE void drv_trace8(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4,
                kal_uint32 data5, kal_uint32 data6, kal_uint32 data7, kal_uint32 data8)
{
   return;
}
#else  /*#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)*/
extern void drv_trace0(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type);
extern void drv_trace1(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1);
extern void drv_trace2(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2);
extern void drv_trace4(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4);
extern void drv_trace8(trace_class_enum trc_class, kal_uint32 msg_index, const char *arg_type, kal_uint32 data1, kal_uint32 data2, kal_uint32 data3, kal_uint32 data4,
                kal_uint32 data5, kal_uint32 data6, kal_uint32 data7, kal_uint32 data8);
#endif /*#if defined(MTK_KAL_MNT) || defined(KAL_ON_OSCAR) || defined(MCD_DLL_EXPORT) || defined(L1_SIM)*/
#else // #if defined(__TST_MODULE__)|| defined(L1_SIM)
#define drv_trace0(...)
#define drv_trace1(...)
#define drv_trace2(...)
#define drv_trace4(...)
#define drv_trace8(...)
#endif // #if defined(__TST_MODULE__)|| defined(L1_SIM)

extern kal_uint8 drv_dummy_return(void);
// MoDIS parser skip end
#endif   /*__DRV_COMM_H__*/
