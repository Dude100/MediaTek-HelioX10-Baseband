#ifdef __LTE_RAT__ 
		#ifdef __UMTS_FDD_MODE__
			#include "log2SD_Catcher_filters_4G_FDD.ini"
		#elif defined __UMTS_TDD128_MODE__ 
			#include "log2SD_Catcher_filters_4G_TDD.ini"
		#endif
#elif defined (__UMTS_TDD128_MODE__)
		#include "log2SD_Catcher_filters_TDD.ini"
#elif defined (__UMTS_RAT__)
		#include "log2SD_Catcher_filters_FDD.ini"
#else
		#include "log2SD_Catcher_filters_2G_FDD.ini"
#endif
