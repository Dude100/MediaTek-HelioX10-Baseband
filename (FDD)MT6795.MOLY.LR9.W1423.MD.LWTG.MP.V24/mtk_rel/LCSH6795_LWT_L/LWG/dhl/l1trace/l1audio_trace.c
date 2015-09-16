#ifdef L1_CATCHER

#include "TrcMod.h"

#if defined(__MTK_TARGET__)
  #if defined (__ARMCC_VERSION)
    #pragma diag_suppress 177
  #elif defined (__GNUC__)
    #pragma GCC diagnostic ignored "-Wunused-variable"
  #endif
#endif

/****************/
/* Filter array */
/****************/
unsigned char L1Audio_Trace_Filter[5] =
		{ 0x1, 0x3, 0x0, 0x0, 0x0 };
/***********************/
/* Set filter function */
/***********************/
void Set_L1Audio_Filter(unsigned char *setting)
{
	int i;

	for(i=0; i<5; i++)
		L1Audio_Trace_Filter[i] = setting[i];
}

#endif
