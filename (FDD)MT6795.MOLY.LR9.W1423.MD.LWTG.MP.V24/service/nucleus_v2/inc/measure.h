/*============================================================================
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
*------------------------------------------------------------------------------
* Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
*============================================================================*/

#ifndef __MEASURE_H__
#define __MEASURE_H__

#define ENABLE_INTERRUPT_MAGIC                               0x00010000
#define DISABLE_INTERRUPT_MAGIC                              0x00020000
#define TCCT_Schedule_MAGIC_1                                0x00000001
#define TCCT_Schedule_MAGIC_2                                0x00000002
#define TCCT_Control_To_System_MAGIC_1                       0x00000003
#define TCCT_Control_To_System_MAGIC_2                       0x00000004
#define TCCT_Protect_MAGIC_1                                 0x00000005
#define TCCT_Protect_MAGIC_2                                 0x00000006
#define TCCT_Protect_MAGIC_3                                 0x00000007
#define TCCT_Protect_MAGIC_4                                 0x00000008
#define TCCT_Unprotect_MAGIC_1                               0x00000009
#define TCCT_Unprotect_MAGIC_2                               0x0000000A
#define TCCT_Unprotect_MAGIC_3                               0x0000000B
#define TCCT_Unprotect_Specific_MAGIC_1                      0x0000000C
#define TCCT_Unprotect_Specific_MAGIC_2                      0x0000000D
#define TCCT_Unprotect_Specific_MAGIC_3                      0x0000000E
#define TCCT_Protect_Switch_MAGIC_1                          0x0000000F
#define TCCT_Protect_Switch_MAGIC_2                          0x00000010
#define TCCT_Protect_Switch_MAGIC_3                          0x00000011
#define TCCT_Protect_Switch_MAGIC_4                          0x00000012
#define TCCT_Activate_HISR_MAGIC_1                           0x00000013
#define TCCT_Activate_HISR_MAGIC_2                           0x00000014
#define TCCT_HISR_Shell_MAGIC_1                              0x00000015
#define TCCT_HISR_Shell_MAGIC_2                              0x00000016
#define TCCT_HISR_Shell_MAGIC_3                              0x00000017
#define TCCT_Signal_Exit_MAGIC_1                             0x00000018
#define TCC_Task_Shell_MAGIC_1                               0x00000019
#define TMCT_Adjust_Timer_MAGIC_1                            0x0000001A
#define TMCT_Adjust_Timer_MAGIC_2                            0x0000001B
#define TMCT_Enable_Timer_MAGIC_1                            0x0000001C
#define TMCT_Enable_Timer_MAGIC_2                            0x0000001D

#define isrC_Main_MAGIC_1                                    0x0000001E
#define isrC_Main_MAGIC_2                                    0x0000001F
#define ssdbg1_main_MAGIC_1                                  0x00000020
#define ssdbg1_main_MAGIC_2                                  0x00000021
#define ssdbg1_main_MAGIC_3                                  0x00000022
#define ssdbg1_main_MAGIC_4                                  0x00000023

#define Protect_Interrupted_MAGIC_1                          0x00000024
#define Protect_Interrupted_MAGIC_2                          0x00000025

typedef struct MPoint
{
   NU_UINT timing;
   NU_UINT magic;
}MeasurePoint;

#if defined(NUCLEUS_TIMING_MEASURE)

extern void SetMeasurePoint(NU_UINT MagicNumber);
extern void SetStartingIndex();
extern void Protect_Interrupted();

#else

#define SetMeasurePoint(a) ;
#define SetStartingIndex() ;
#define Protect_Interrupted() ;

#endif
#endif /* __MEASURE_H__ */
