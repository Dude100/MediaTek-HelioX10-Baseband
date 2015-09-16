#ifdef TASK_PRIORITY_MACRO

#define TASK_PRIORITY_DRVTEST              KAL_PRIORITY_CLASS5
#define TASK_PRIORITY_SSTESTA              (KAL_PRIORITY_CLASS1 + 1)
#define TASK_PRIORITY_SSTESTB              (KAL_PRIORITY_CLASS0 + 4)
#define TASK_PRIORITY_DRVTEST_GPIO         (KAL_PRIORITY_CLASS5 + 3)
#define TASK_PRIORITY_DRVTEST_EINT         (KAL_PRIORITY_CLASS5 + 4)
#define TASK_PRIORITY_DRVTEST_GPT          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_GPT2         (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_LMAC_AT              (KAL_PRIORITY_CLASS5 + 5) // lmac auto test
#define TASK_PRIORITY_DRVTEST_SPIC_1       (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_SPIC_2       (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_NFI_PRIMARY  (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_NFI_MINOR    (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_GDMA         (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_RSTCTL       (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_CPU          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_USIM         (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_USIM2        (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_ATHIF_TASK0          (KAL_PRIORITY_CLASS5 + 8)
#define TASK_PRIORITY_ATHIF_TASK1          (KAL_PRIORITY_CLASS5 + 9)
#define TASK_PRIORITY_DRVTEST_CORESIGHT    (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_DEM          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_PFC          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_UART         (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_MSDC         (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_DSPFM        (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_IDC          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_BUSMON       (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_BSI          (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_DORMANT      (KAL_PRIORITY_CLASS5 + 5)
#define TASK_PRIORITY_DRVTEST_EMI 	       (KAL_PRIORITY_CLASS5 + 5)

#else /* else of TASK_PRIORITY_MACRO */

MODULE_ID_FOR_PRINT_TRACE(MOD_DRVTEST)
//Do not add setting before this line !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_GPT
task_index(INDX_DT_GPT) 
task_module_map(INDX_DT_GPT, MOD_DT_GPT)
task_name("DTGPT")
task_queue_name("DTGPT Q")
task_priority(TASK_PRIORITY_DRVTEST_GPT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_gpt_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GPT */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_GPT
task_index(INDX_DT_GPT2) 
task_module_map(INDX_DT_GPT2, MOD_DT_GPT_TWO)
task_name("DTGPT2")
task_queue_name("DTGPT2 Q")
task_priority(TASK_PRIORITY_DRVTEST_GPT2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_gpt_task2_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GPT */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_MSDC
task_index(INDX_MSDC) 
task_module_map(INDX_MSDC, MOD_MSDC)
task_name("MSDC")
task_queue_name("MSDC Q")
task_priority(TASK_PRIORITY_DRVTEST_MSDC, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_msdc_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

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
#endif

#endif /* end of ATEST_DRV_MSDC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_USIM
task_index(INDX_DT_USIM) 
task_module_map(INDX_DT_USIM, MOD_DT_USIM)
task_name("DTUSIM")
task_queue_name("DTUSIM Q")
task_priority(TASK_PRIORITY_DRVTEST_USIM, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
task_create_function(drvtest_usim_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(3)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GPT */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_USIM
task_index(INDX_DT_USIM2) 
task_module_map(INDX_DT_USIM2, MOD_DT_USIM2)
task_name("DTUSIM2")
task_queue_name("DTUSIM2 Q")
task_priority(TASK_PRIORITY_DRVTEST_USIM2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
task_create_function(drvtest_usim_task2_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(40)
task_internal_queue_size(3)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GPT */
/*************************Task CFG END******************/

#ifdef ATEST_DRV_LMAC
/* LMAC auto test module */
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_LMAC_AT) 
/*module_type and mod_task_g*/
task_module_map(INDX_LMAC_AT, MOD_LMAC_AT)

/*task's parameters*/
task_name("LMAC_AT")
task_queue_name("LMAC_AT_Q")
task_priority(TASK_PRIORITY_LMAC_AT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(262144)
task_create_function(lmac_at_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
#endif /* ATEST_DRV_LMAC */


/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_SPIC
task_index(INDX_DT_SPIC_1)
task_module_map(INDX_DT_SPIC_1, MOD_DT_SPIC_ONE)
task_name("DTSPIC_1")
task_queue_name("DTSPIC_1 Q")
task_priority(TASK_PRIORITY_DRVTEST_SPIC_1, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_spic_task_1_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_SPIC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_SPIC
task_index(INDX_DT_SPIC_2)
task_module_map(INDX_DT_SPIC_2, MOD_DT_SPIC_TWO)
task_name("DTSPIC_2")
task_queue_name("DTSPIC_2 Q")
task_priority(TASK_PRIORITY_DRVTEST_SPIC_2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_spic_task_2_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_SPIC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_NFI
task_index(INDX_DT_NFI_PRIMARY)
task_module_map(INDX_DT_NFI_PRIMARY, MOD_DT_NFI_PRIMARY)
task_name("DTNFI_PRIMARY")
task_queue_name("DTNFI_PRIMARY Q")
task_priority(TASK_PRIORITY_DRVTEST_NFI_PRIMARY, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_nfi_task_1_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_NFI */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_NFI
task_index(INDX_DT_NFI_MINOR)
task_module_map(INDX_DT_NFI_MINOR, MOD_DT_NFI_MINOR)
task_name("DTNFI_MINOR")
task_queue_name("DTNFI_MINOR Q")
task_priority(TASK_PRIORITY_DRVTEST_NFI_MINOR, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_nfi_task_2_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_NFI */
/*************************Task CFG END******************/

/*************************Task L2 Cipher Copro AT Begin****************/
#ifdef  ATEST_DRV_L2_CIPHER
/*task_indx_type*/
#define TASK_PRIORITY_L2_COPRO_AT_TASK0        (KAL_PRIORITY_CLASS20+1)
task_index(INDX_L2_COPRO_AT)
/*module_type and mod_task_g*/
task_module_map(INDX_L2_COPRO_AT, MOD_L2_COPRO_AT)

/*task's parameters*/
task_name("L2_COPRO_AT")
task_queue_name("QL2_COPRO_AT")
task_priority(TASK_PRIORITY_L2_COPRO_AT_TASK0, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(8192)
task_create_function(l2_copro_at_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_L2_CIPHER */
/*************************Task L2 copro AT END******************/

#ifdef ATEST_SS
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_SSTESTA) 
/*module_type and mod_task_g*/
task_module_map(INDX_SSTESTA, MOD_SSTESTA_A)
task_module_map(INDX_SSTESTA, MOD_SSTESTA_B)
task_module_map(INDX_SSTESTA, MOD_SSTESTA_C)

/*task's parameters*/
task_name("SS1")
task_queue_name("SST1 Q")
task_priority(TASK_PRIORITY_SSTESTA, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(8192)
task_create_function(sstest_task1_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(90)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M | USB_M)

/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
task_index(INDX_SS_T2) 
task_module_map(INDX_SS_T2, MOD_SSTESTB)
task_name("SST2")
task_queue_name("SST2 Q")
task_priority(TASK_PRIORITY_SSTESTB, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(sstest_task2_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
#endif /* end of ATEST_SS */

/*************************Task GDMA CFG Begin****************/
#ifdef ATEST_DRV_GDMA
task_index(INDX_DT_GDMA) 
task_module_map(INDX_DT_GDMA, MOD_DT_GDMA)
task_name("DTGDMA")
task_queue_name("DTGDMA Q")
task_priority(TASK_PRIORITY_DRVTEST_GDMA, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_gdma_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GDMA */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_EMI
task_index(INDX_DT_EMI) 
task_module_map(INDX_DT_EMI, MOD_DT_EMI)
task_name("DTEMI")
task_queue_name("DTEMI Q")
task_priority(TASK_PRIORITY_DRVTEST_EMI, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_emi_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_EMI */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_RSTCTL
task_index(INDX_DT_RSTCTL) 
task_module_map(INDX_DT_RSTCTL, MOD_DT_RSTCTL)
task_name("DTRSTCTL")
task_queue_name("DTRSTCTL Q")
task_priority(TASK_PRIORITY_DRVTEST_RSTCTL, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_rstctl_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_RSTCTL */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_CPU
task_index(INDX_DT_CPU) 
task_module_map(INDX_DT_CPU, MOD_DT_CPU)
task_name("DTCPU")
task_queue_name("DTRCPU Q")
task_priority(TASK_PRIORITY_DRVTEST_CPU, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(2048)
task_create_function(drvtest_cpu_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_CPU */
/*************************Task CFG END******************/

#ifdef ATEST_DRV_HIF
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_ATHIF_TASK0) 
/*module_type and mod_task_g*/
task_module_map(INDX_ATHIF_TASK0, MOD_ATHIFT0)

/*task's parameters*/
task_name("ATHIFT0")
task_queue_name("QATHIFT0")
task_priority(TASK_PRIORITY_ATHIF_TASK0, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(athif_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
/*************************Task CFG Begin****************/
/*task_indx_type*/
task_index(INDX_ATHIF_TASK1) 
/*module_type and mod_task_g*/
task_module_map(INDX_ATHIF_TASK1, MOD_ATHIFT1)

/*task's parameters*/
task_name("ATHIFT1")
task_queue_name("QATHIFT1")
task_priority(TASK_PRIORITY_ATHIF_TASK1, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(athif_dataflow_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
/*************************Task CFG END******************/
#endif /*ATEST_DRV_HIF*/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_GPIO
task_index(INDX_DT_GPIO) 
task_module_map(INDX_DT_GPIO, MOD_DT_GPIO)
task_name("DTGPIO")
task_queue_name("DTGPIO Q")
task_priority(TASK_PRIORITY_DRVTEST_GPIO, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_gpio_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_GPIO */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_EINT
task_index(INDX_DT_EINT) 
task_module_map(INDX_DT_EINT, MOD_DT_EINT)
task_name("DTEINT")
task_queue_name("DTEINT Q")
task_priority(TASK_PRIORITY_DRVTEST_EINT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_eint_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_EINT */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_CORESIGHT
task_index(INDX_DT_CORESIGHT) 
task_module_map(INDX_DT_CORESIGHT, MOD_DT_CORESIGHT)
task_name("DTCORESIGHT")
task_queue_name("DTCORESIGHT Q")
task_priority(TASK_PRIORITY_DRVTEST_CORESIGHT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(8192)
task_create_function(drvtest_coresight_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /*ATEST_DRV_CORESIGHT*/
/*************************Task CFG END******************/

/*************************Task MAC PHY COSIM Begin****************/
#ifdef  ATEST_DRV_MAC_PHY_COSIM
/*task_indx_type*/
task_index(INDX_MAC_PHY_COSIM)
/*module_type and mod_task_g*/
task_module_map(INDX_MAC_PHY_COSIM, MOD_MAC_PHY_COSIM)

/*task's parameters*/
task_name("MAC_PHY_COSIM")
task_queue_name("QL2_MAC_PHY_COSIM")
task_priority((KAL_PRIORITY_CLASS20+1), KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(mac_phy_cosim_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_MAC_PHY_COSIM */
/*************************Task MAC PHY COSIM END******************/

/*************************Task L2 HW logging test Begin****************/
#ifdef  ATEST_L2_HW_LOGGING
/*task_indx_type*/
task_index(INDX_l2_HW_LOGGING_AT)
/*module_type and mod_task_g*/
task_module_map(INDX_l2_HW_LOGGING_AT, MOD_L2_HW_LOGGING_AT)

/*task's parameters*/
task_name("L2_HW_LOGGING_AT")
task_queue_name("QL2_HW_LOGGING_AT")
task_priority((KAL_PRIORITY_CLASS20+1), KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(l2_hw_logging_at_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(20)
task_internal_queue_size(20)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_L2_HW_LOGGING */
/*************************Task L2 HW logging test END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_DEM
task_index(INDX_DT_DEM) 
task_module_map(INDX_DT_DEM, MOD_DT_DEM)
task_name("DTDEM")
task_queue_name("DTDEM Q")
task_priority(TASK_PRIORITY_DRVTEST_DEM, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(8192)
task_create_function(drvtest_dem_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /*ATEST_DRV_DEM*/
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_PFC
task_index(INDX_DT_PFC)
task_module_map(INDX_DT_PFC, MOD_DT_PFC)
task_name("DTPFC")
task_queue_name("DTRPFC Q")
task_priority(TASK_PRIORITY_DRVTEST_PFC, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_pfc_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_PFC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_UART
task_index(INDX_DT_UART)
task_module_map(INDX_DT_UART, MOD_DT_UART)
task_name("DTUART")
task_queue_name("DTUART Q")
task_priority(TASK_PRIORITY_DRVTEST_UART, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_uart_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_UART */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_IDC
task_index(INDX_DT_IDC)
task_module_map(INDX_DT_IDC, MOD_DT_IDC)
task_name("DTIDC")
task_queue_name("DTIDC Q")
task_priority(TASK_PRIORITY_DRVTEST_IDC, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_idc_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(30)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_IDC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_BUSMON
task_index(INDX_DT_BUSMON)
task_module_map(INDX_DT_BUSMON, MOD_DT_BUSMON)
task_name("BUSMON")
task_queue_name("BUSMON Q")
task_priority(TASK_PRIORITY_DRVTEST_BUSMON, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_busmon_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_BUSMON */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_DORMANT
task_index(INDX_DT_DORMANT)
task_module_map(INDX_DT_DORMANT, MOD_DT_DORMANT)
task_name("DORMANT")
task_queue_name("DORMANT Q")
task_priority(TASK_PRIORITY_DRVTEST_DORMANT, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_dormant_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_DORMANT */
/*************************Task CFG END******************/


/*************************Task CFG Begin****************/
#ifdef ATEST_STRESS_TEST
task_index(INDX_ST_HIF_CTL)
task_module_map(INDX_ST_HIF_CTL, MOD_ST_HIF_CTL)
task_name("ST_HIF_CTL")
task_queue_name("ST_Q_HIF_CTL")
task_priority(KAL_PRIORITY_CLASS5, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_hif_control_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_HIF_DATA)
task_module_map(INDX_ST_HIF_DATA, MOD_ST_HIF_DATA)
task_name("ST_HIF_DATA")
task_queue_name("ST_Q_HIF_DATA")
task_priority(KAL_PRIORITY_CLASS5+1, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_hif_data_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_MAIN)
task_module_map(INDX_ST_MAIN, MOD_ST_MAIN)
task_name("ST_MAIN")
task_queue_name("ST_Q_M")
task_priority(KAL_PRIORITY_CLASS5+5, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(dp_lb_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_ZERO)
task_module_map(INDX_ST_ZERO, MOD_ST_ZERO)
task_name("ST_ZERO")
task_queue_name("ST_Q_ZERO")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_ONE)
task_module_map(INDX_ST_ONE, MOD_ST_ONE)
task_name("ST_ONE")
task_queue_name("ST_Q_ONE")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_TWO)
task_module_map(INDX_ST_TWO, MOD_ST_TWO)
task_name("ST_TWO")
task_queue_name("ST_Q_TWO")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_THREE)
task_module_map(INDX_ST_THREE, MOD_ST_THREE)
task_name("ST_THREE")
task_queue_name("ST_Q_THREE")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_FOUR)
task_module_map(INDX_ST_FOUR, MOD_ST_FOUR)
task_name("ST_FOUR")
task_queue_name("ST_Q_FOUR")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_FIVE)
task_module_map(INDX_ST_FIVE, MOD_ST_FIVE)
task_name("ST_FIVE")
task_queue_name("ST_Q_FIVE")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_SIX)
task_module_map(INDX_ST_SIX, MOD_ST_SIX)
task_name("ST_SIX")
task_queue_name("ST_Q_SIX")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_SEVEN)
task_module_map(INDX_ST_SEVEN, MOD_ST_SEVEN)
task_name("ST_SEVEN")
task_queue_name("ST_Q_SEVEN")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

task_index(INDX_ST_EIGHT)
task_module_map(INDX_ST_EIGHT, MOD_ST_EIGHT)
task_name("ST_EIGHT")
task_queue_name("ST_Q_EIGHT")
task_priority(KAL_PRIORITY_CLASS5+2, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(stress_test_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)

#endif /* end of ATEST_STRESS_TEST */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_SLT
task_index(INDX_SLT_00)
task_module_map(INDX_SLT_00, MOD_ST_00)
task_name("SLT_00")
task_queue_name("ST_Q_SLT")
task_priority(KAL_PRIORITY_CLASS5+100, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(32*1024)
task_create_function(slt_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_SLT */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_DSPFM
task_index(INDX_DT_DSPFM)
task_module_map(INDX_DT_DSPFM, MOD_DT_DSPFM)
task_name("DTDSPFM")
task_queue_name("DTDSPFM Q")
task_priority(TASK_PRIORITY_DRVTEST_DSPFM, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(4096)
task_create_function(drvtest_dspfm_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_PFC */
/*************************Task CFG END******************/

/*************************Task CFG Begin****************/
#ifdef ATEST_DRV_BSI
task_index(INDX_DT_BSI) 
task_module_map(INDX_DT_BSI, MOD_DT_BSI)
task_name("DTBSI")
task_queue_name("DTBSI_Q")
task_priority(TASK_PRIORITY_DRVTEST_BSI, KAL_TASK_INITIAL_PRIORITY)
task_stack_size(1024)
task_create_function(drvtest_bsi_task_create)
task_stack_internalRAM(KAL_FALSE)
task_external_queue_size(10)
task_internal_queue_size(0)
task_boot_mode(NORMAL_M)
#endif /* end of ATEST_DRV_BSI */
/*************************Task CFG END******************/




#endif /* end of TASK_PRIORITY_MACRO */

