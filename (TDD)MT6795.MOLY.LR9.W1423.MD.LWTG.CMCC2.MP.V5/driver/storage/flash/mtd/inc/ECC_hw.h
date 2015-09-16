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
 *   ECC_hw.h
 *
 * Project:
 * --------
 *   Device Test
 *
 * Description:
 * ------------
 *   Item test - ECC module test.
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
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#ifndef __ECC_HW_H__
#define __ECC_HW_H__
//Add for RHR
    #include "reg_base.h"
//Add for RHR    
/*******************************************************************************
 * ECC address definition
 *******************************************************************************/

#define ECC_ENCCON      ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0000))
#define ECC_ENCCNFG     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0004))
#define ECC_ENCDIADDR   ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0008))
#define ECC_ENCIDLE     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x000C))
#define ECC_ENCPAR0     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0010))
#define ECC_ENCPAR1     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0014))
#define ECC_ENCPAR2     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0018))
#define ECC_ENCPAR3     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x001C))
#define ECC_ENCPAR4     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0020))
#define ECC_ENCSTA      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0024))
#define ECC_ENCIRQEN    ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0028))
#define ECC_ENCIRQSTA   ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x002C))

#define ECC_DECCON      ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0100))
#define ECC_DECCNFG     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0104))
#define ECC_DECDIADDR   ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0108))
#define ECC_DECIDLE     ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x010C))
#define ECC_DECFER      ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0110))
#define ECC_DECENUM     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0114))
#define ECC_DECDONE     ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0118))
#define ECC_DECEL0      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x011C))
#define ECC_DECEL1      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0120))
#define ECC_DECEL2      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0124))
#define ECC_DECEL3      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0128))
#define ECC_DECEL4      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x012C))
#define ECC_DECEL5      ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x0130))
#define ECC_DECIRQEN    ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0134))
#define ECC_DECIRQSTA   ((volatile UINT16P)(BASE_ADDR_NFIECC_MD+0x0138))
#define ECC_FDMADDR     ((volatile UINT32P)(BASE_ADDR_NFIECC_MD+0x013C))


/*******************************************************************************
 * ECC register definition
 *******************************************************************************/
/* ECC_ENCON */
#define ENC_EN             (0x0001)

/* ECC_ENCCNFG */
#define ECC_CNFG_ECC4          (0x0000)
#define ECC_CNFG_ECC6          (0x0001)
#define ECC_CNFG_ECC8          (0x0002)
#define ECC_CNFG_ECC10         (0x0003)
#define ECC_CNFG_ECC12         (0x0004)
#define ECC_CNFG_ECC_MASK      (0x00000007)

#define ECC_CNFG_NFI           (0x0010)
#define ECC_CNFG_MODE_MASK     (0x0010)

#define ECC_CNFG_META3         (0x10180000)
#define ECC_CNFG_META6         (0x10300000)
#define ECC_CNFG_META8         (0x10400000)

#define ENC_CNFG_MSG_MASK  (0x1FFF0000)
#define ENC_CNFG_MSG_SHIFT (0x10)

/* ECC_ENCIDLE */
#define ENC_IDLE           (0x0001)

/* ECC_ENCSTA */
#define STA_FSM            (0x001F)
#define STA_COUNT_PS       (0xFF10)
#define STA_COUNT_MS       (0x3FFF0000)

/* ECC_ENCIRQEN */
#define ENC_IRQEN          (0x0001)

/* ECC_ENCIRQSTA */
#define ENC_IRQSTA         (0x0001)

/* ECC_DECCON */
#define DEC_EN             (0x0001)

/* ECC_DECCNFG */
#define DEC_CNFG_ECC4          (0x0000)
#define DEC_CNFG_ECC6          (0x0001)
#define DEC_CNFG_ECC8          (0x0002)
#define ECC_CNFG_ECC10         (0x0003)
#define ECC_CNFG_ECC12         (0x0004)
//#define ECC_CNFG_ECC_MASK      (0x00000007)
#define DEC_CNFG_NFI           (0x0010)
//#define DEC_CNFG_META6         (0x10300000)
//#define ENC_CNFG_META8         (0x10400000)

#define DEC_CNFG_BURST		   (0x00100)
#define DEC_CNFG_FER           (0x01000)
#define DEC_CNFG_EL            (0x02000)
#define DEC_CNFG_CORRECT       (0x03000)
#define DEC_CNFG_TYPE_MASK     (0x03000)

#define DEC_CNFG_EMPTY_EN      (0x80000000)

#define DEC_CNFG_META3         (0x10800000) /* 8 bit ECC in 16 byte spare area */
#define DEC_CNFG_META6         (0x107E0000) /* 6 bit ECC in 16 byte spare area  */
#define DEC_CNFG_META8         (0x10740000) /* 4 bit ECC in 16 byte spare area  */
#define DEC_CNFG_META8_26      (0x10A80000) /* 8 bit ECC 8 byte FDM in 26 byte spare area  */

#define DEC_CNFG_CODE_MASK     (0x1FFF0000)
#define DEC_CNFG_CODE_SHIFT    (0x10)

/* ECC_DECIDLE */
#define DEC_IDLE              (0x0001)

/* ECC_DECFER */
#define DEC_FER0               (0x0001)
#define DEC_FER1               (0x0002)
#define DEC_FER2               (0x0004)
#define DEC_FER3               (0x0008)
#define DEC_FER4               (0x0010)
#define DEC_FER5               (0x0020)
#define DEC_FER6               (0x0040)
#define DEC_FER7               (0x0080)

/* ECC_DECENUM */
#define ERR_NUM0               (0x0000000F)
#define ERR_NUM1               (0x000000F0)
#define ERR_NUM2               (0x00000F00)
#define ERR_NUM3               (0x0000F000)
#define ERR_NUM4               (0x000F0000)
#define ERR_NUM5               (0x00F00000)
#define ERR_NUM6               (0x0F000000)
#define ERR_NUM7               (0xF0000000)

/* ECC_DECDONE */
#define DEC_DONE0               (0x0001)
#define DEC_DONE1               (0x0002)
#define DEC_DONE2               (0x0004)
#define DEC_DONE3               (0x0008)
#define DEC_DONE4               (0x0010)
#define DEC_DONE5               (0x0020)
#define DEC_DONE6               (0x0040)
#define DEC_DONE7               (0x0080)

/* ECC_DECIRQEN */
#define DEC_IRQEN          (0x0001)

/* ECC_DECIRQSTA */
#define DEC_IRQSTA         (0x0001)

/************************************************************************
 * Macro definition
 ************************************************************************/
#define WAIT_ENC_READY \
do {\
   while(!(*ECC_ENCIDLE & ENC_IDLE));\
} while(0);

#define WAIT_ENC_PARITY_READY \
do {\
   while(*ECC_ENCSTA & STA_COUNT_MS);\
} while(0);

#define WAIT_DEC_READY \
do {\
   while(!(*ECC_DECIDLE & DEC_IDLE));\
} while(0);

#define START_ECC_DEC \
do{\
   *ECC_DECCON = 0;\
   *ECC_DECCON = DEC_EN;\
}while(0);

#define STOP_ECC_DEC \
do{\
   *ECC_DECCON = 0;\
}while(0);

#define START_ECC_ENC \
do{\
   *ECC_ENCCON = 0;\
   *ECC_ENCCON = ENC_EN;\
}while(0);

#define STOP_ECC_ENC \
do{\
   *ECC_ENCCON = 0;\
}while(0);

#define GET_ECC_ERRNUM(val)\
do{\
   val = *ECC_DECENUM;\
}while(0);

#define GET_ECC_ERRDONE(val) \
do{\
   val = *ECC_DECDONE;\
}while(0);


#define ECC_PARITY_NUM  (156)

#endif /* __ECC_HW_H__ */
