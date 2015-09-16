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
 *    rf_desense_test.c
 *
 * Project:
 * --------
 *   Maui_Software
 *
 * Description:
 * ------------
 *   This Module defines the RF De-sense test driver.
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

#include "drv_features.h"
#include "drv_comm.h"
#include "rf_desense_test.h"
#include "reg_base.h"
#include "emi_hw.h"
#include "msdc_def.h"

#include "dcl.h"

#include "fs_type.h"
#include "MMI_features.h"
#include "TimerEvents.h"

#if defined(__MTK_INTERNAL__)

#ifdef __RF_DESENSE_TEST__
#pragma arm section code= "PRIMARY_ROCODE" rodata = "PRIMARY_RODATA"

static RF_DESENSE_MODE rf_desense_curr_mode = RF_DESENSE_MODE_BASE;

void
rf_desense_set_curr_mode(RF_DESENSE_MODE const mode) 
{
    rf_desense_curr_mode = mode;
}

RF_DESENSE_MODE
rf_desense_get_curr_mode(void) 
{
    return rf_desense_curr_mode;
}

/** Local function prototype
 *
 */
kal_bool rfdtCheckVBoostOnOff(void);

#ifdef __RF_DESENSE_EMI_MIN_CURRENT__
kal_bool rfdtCheckMinEMIDrivingCurrent(void);
#endif

#ifdef __RF_DESENSE_EMI_2MA_CTRL_CURRENT__
kal_bool rfdtCheckMinEMI2mADrivingCurrent(void);
#endif

kal_bool rfdtCheckMSDC4mADrivingCurrent(void);
kal_bool rfdtCheckMSDC8mADrivingCurrent(void);


/** \brief Print RF De-sense test check log.
 *
 */
void rfdtPrintCheckLog(void)
{
    kal_prompt_trace(MOD_MED, "[RF Desense] RF Desense Log Starts\n");

#ifdef __RF_DESENSE_EMI_MIN_CURRENT__
    // Print log of Minimum EMI driving current check
    if(rfdtCheckMinEMIDrivingCurrent())
    {
        kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum EMI driving current] Pass!\n");
    }
    else
    {
        kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum EMI driving current] Fail!\n");
    }
#endif  // End of #ifdef __RF_DESENSE_EMI_MIN_CURRENT__

#ifdef __RF_DESENSE_EMI_2MA_CTRL_CURRENT__
    // Print log of Minimum EMI 2mA driving current check
    if(rfdtCheckMinEMI2mADrivingCurrent())
    {
        kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum EMI 2mA driving current] Pass!\n");
    }
    else
    {
        kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum EMI 2mA driving current] Fail!\n");
    }
#endif  // End of #ifdef __RF_DESENSE_EMI_2MA_CTRL_CURRENT__

    /* Argus Lin MAUI_02605973
    Modify msdc driving current */
    switch(rf_desense_get_curr_mode())
    {
        case RF_DESENSE_MODE_MSDC_4MA:
            // Print log of Minimum MSDC 4mA driving current check
            if(rfdtCheckMSDC4mADrivingCurrent())
            {
                kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC 4mA driving current] Pass!\n");
            }
            else
            {
                kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC 4mA driving current] Fail!\n");
            }
            break;

        case RF_DESENSE_MODE_MSDC_8MA:
            /* Falling through */
        default:
            // Print log of Minimum MSDC 8mA driving current check
            if(rfdtCheckMSDC8mADrivingCurrent())
            {
                kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC 8mA driving current] Pass!\n");
            }
            else
            {
                kal_prompt_trace(MOD_MED, "[RF Desense] [Minimum MSDC 8mA driving current] Fail!\n");
            }
            break;
    }

    // Print log of VBoost On/Off check
    rfdtCheckVBoostOnOff();

    kal_prompt_trace(MOD_MED, "[RF Desense] RF Desense Log Ends\n");
}

#ifdef __RF_DESENSE_EMI_MIN_CURRENT__
kal_bool rfdtCheckMinEMIDrivingCurrent(void)
{
    kal_prompt_trace(MOD_MED, "[RF Desense] 4mA EMI driving\n");
    return KAL_TRUE;
}
#endif

#ifdef __RF_DESENSE_EMI_2MA_CTRL_CURRENT__
kal_bool rfdtCheckMinEMI2mADrivingCurrent(void)
{
    kal_prompt_trace(MOD_MED, "[RF Desense] 2mA EMI driving\n");
    return KAL_TRUE;
}
#endif

kal_bool rfdtCheckMSDC4mADrivingCurrent(void)
{
#ifdef __MSDC_4MA__

#if (defined(MT6236) || defined(MT6236B))

    if(0x0 == (DRV_Reg32(MSDC_IOCON) & 0x3F)){
        kal_prompt_trace(MOD_MED, "[RF Desense] 4mA MSDC driving\n");
        return KAL_TRUE;
    }

    return KAL_FALSE;

#endif

#endif

    return KAL_FALSE;
}

kal_bool rfdtCheckMSDC8mADrivingCurrent(void)
{
#ifdef __MSDC_8MA__

#if (defined(MT6236) || defined(MT6236B))

    if(0x12 == (DRV_Reg32(MSDC_IOCON) & 0x3F)){
        kal_prompt_trace(MOD_MED, "[RF Desense] 8mA MSDC driving\n");
        return KAL_TRUE;
    }

    return KAL_FALSE;

#endif

#endif

    return KAL_FALSE;
}

kal_bool rfdtCheckVBoostOnOff(void)
{
    // Check VBoost On/Off
#if (defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6253D) || defined(MT6253T))
    kal_uint16 val_16 = 0;
    kal_uint32 reg_32 = 0;
#endif

    kal_prompt_trace(MOD_MED, "[RF Desense] Check VBoost On/Off\n");

    // Set Vboost control register offset
#if (defined(MT6236) || defined(MT6236B))
    reg_32 = PMIC_BOOST_CON0;   // 0x801B0B00
#elif (defined(MT6253) || defined(MT6253D) || defined(MT6253T))
    reg_32 = PMIC_DRIVER_CON3;  // 0x8301088C
#else
    kal_prompt_trace(MOD_MED, "[RF Desense] Warning!: VBoost On/Off NOT checked\n");
    return KAL_FALSE;
#endif


#if (defined(MT6236) || defined(MT6236B) || defined(MT6253) || defined(MT6253D) || defined(MT6253T))
    // Read Vboost control register value
    val_16 = (*(volatile kal_uint16 *)reg_32);

    // Output Vboost control register value
    kal_prompt_trace(MOD_MED, "[RF Desense][Vboost mode][0x%08x b[1]=1 is ON, 0 is OFF, read value 0x%08x]\n", reg_32, val_16);

    return KAL_TRUE;
#endif
}

#define RF_DESENSE_FS_TIMEOUT       1000    //Duration of each read/write (ms)
#define RF_DESENSE_FS_BUFFER_LEN    512     //Size each read/write buffer (byte)
#define RF_DESENSE_FS_LOOP_NO       100     //Count number of read/write in each timeout
typedef void (*FuncPtr) (void);
extern void StartTimer(kal_int16 timerid, kal_int32 delay, FuncPtr funcPtr);
void rfdFsAccessHandler(void)
{
    FS_HANDLE SrcHandle = 0;
    FS_HANDLE DstHandle = 0;

    if (SrcHandle <= 0)
    {
        kal_int16 cardDrvLetter;
        WCHAR fname[20];
        cardDrvLetter = FS_GetDrive(FS_DRIVE_V_REMOVABLE, 1, FS_NO_ALT_DRIVE);
        kal_wsprintf(fname, "%c:\\%w", cardDrvLetter, L"fs.in");
        SrcHandle = FS_Open(fname, FS_READ_ONLY);
        if (SrcHandle > 0)
        {
            kal_wsprintf(fname, "%c:\\%w", cardDrvLetter, L"fs.out");
            FS_Delete(fname);
            DstHandle = FS_Open(fname, FS_READ_WRITE | FS_CREATE);
            if (DstHandle <= 0)
            {
                goto done;
            }
        }
    }

    if ((SrcHandle > 0) && (DstHandle > 0))
    {
        kal_int32 i, ret;
        kal_uint32 read, written;
        kal_uint8 buffer[RF_DESENSE_FS_BUFFER_LEN];

        for (i = 0; i < RF_DESENSE_FS_LOOP_NO; ++i)
        {
            ret = FS_Read(SrcHandle, buffer, RF_DESENSE_FS_BUFFER_LEN,  &read);
            if ((ret != FS_NO_ERROR) || (read <= 0))
            {
                goto done;
            }

            ret = FS_Write(DstHandle, buffer, read, &written);
            if ((ret != FS_NO_ERROR) || (written <= 0))
            {
                goto done;
            }
        }
    }

done:
    if (SrcHandle > 0)
    {
        FS_Close(SrcHandle);
        SrcHandle = 0;
    }

    if (DstHandle > 0)
    {
        FS_Close(DstHandle);
        DstHandle = 0;
    }

    StartTimer(SAT_500_TIMER, RF_DESENSE_FS_TIMEOUT, rfdFsAccessHandler);
}


#endif  // End of #ifdef __RF_DESENSE_TEST__
#endif  // End of #if defined(__MTK_INTERNAL__)
