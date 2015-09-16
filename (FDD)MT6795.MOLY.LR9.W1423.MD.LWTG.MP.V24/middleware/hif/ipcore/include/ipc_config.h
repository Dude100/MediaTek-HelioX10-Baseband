#if defined(__L1_STANDALONE__) || defined(__L1EDPS_ENABLE__)
/*
	For L1-only mode, L4 related modules are not included.

	__L1_STANDALONE__ : Used in 23G
	__L1EDPS_ENABLE__ : Used in 4G
*/
#else

/************************* IP Core Modue Begin ******************/
#if defined(__UMTS_RAT__) || defined(__GSM_RAT__)
IPC_MODULE_ID(MOD_RATDM)
IPC_MODULE_PREFIX(ratdm_multimode)
#if defined(__GEMINI__) || defined(__SGLTE__)
IPC_MODULE_ID(MOD_RATDM_2)
IPC_MODULE_PREFIX(ratdm_multimode)
#if (GEMINI_PLUS >= 3)
IPC_MODULE_ID(MOD_RATDM_3)
IPC_MODULE_PREFIX(ratdm_multimode)
#if (GEMINI_PLUS >= 4)
IPC_MODULE_ID(MOD_RATDM_4)
IPC_MODULE_PREFIX(ratdm_multimode)
#endif /* GEMINI_PLUS >= 4 */
#endif /* GEMINI_PLUS >= 3 */
#endif /* __GEMINI__ */
#endif /* __UMTS_RAT__ || __GSM_RAT__ */
/************************* IP Core Modue End ******************/
/************************* IP Core Modue Begin ******************/
#if defined(__LTM_MULTI_ENABLE__)
IPC_MODULE_ID(MOD_LTM)
IPC_MODULE_PREFIX(ltm_multi)
#endif
/************************* IP Core Modue End ******************/
/************************* IP Core Modue Begin ******************/
IPC_MODULE_ID(MOD_UPCM)
IPC_MODULE_PREFIX(upcm)
/************************* IP Core Modue End ******************/
/************************* IP Core Modue Begin ******************/
#if defined(__LTM_SIMULATION_SUPPORT__)
IPC_MODULE_ID(MOD_LTM_SIM)
IPC_MODULE_PREFIX(lms)
#endif
/************************* IP Core Modue End ******************/
/************************* IP Core Modue Begin ******************/
#if defined(__LTM_EPDCP_SIMULATION_SUPPORT__)
IPC_MODULE_ID(MOD_EPDCP)
IPC_MODULE_PREFIX(ltm_epdcp)
#endif
/************************* IP Core Modue End ******************/

#endif /* __L1_STANDALONE__ || __L1EDPS_ENABLE__ */
