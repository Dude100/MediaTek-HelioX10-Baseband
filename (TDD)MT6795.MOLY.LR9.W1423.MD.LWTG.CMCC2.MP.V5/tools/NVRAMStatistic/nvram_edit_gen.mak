# NVRAM Editor
.PHONY: NVRAM_EDITOR_H_TO_DB 

include make/cmd_cfg.mak


nvram_auto_gen_path := $(strip $(NVRAM_AUTO_GEN_PATH))/nvram_auto_gen

ifeq ($(strip $(OS_VERSION)),MSWin32)
  nvram_dir_list := driver\common middleware\common modem\common\ps service\nvram
	
  def_h += $(foreach DIR,$(nvram_dir_list), \
    $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_def.h dir custom\$(DIR)\*_nvram_def.h /b),$(FILE)) \
  )
  tmp_def_h = $(strip $(def_h))
  
  editor_h += $(foreach DIR,$(nvram_dir_list), \
    $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_editor.h dir custom\$(DIR)\*_nvram_editor.h /b),$(FILE)) \
  )
  tmp_editor_h = $(strip $(editor_h))

  def_c +=$(foreach DIR,$(nvram_dir_list), \
    $(foreach FILE,$(shell if exist custom\$(DIR)\*_nvram_def.c dir custom\$(DIR)\*_nvram_def.c /b),$(FILE)) \
  )

  def_obj := $(patsubst %, %.obj, $(basename $(notdir $(def_c))))
  tbl_list += logical_data_item_table_core \
    logical_data_item_table_internal \
    logical_data_item_table_factory \
    logical_data_item_table_exception \
					$(patsubst %, logical_data_item_table_%, $(subst _nvram_def.obj,,$(def_obj)))

  ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
    ifneq ($(filter custom,$(CUS_REL_MTK_COMP)),)
        NVRAM_OBJ_LIST += $(patsubst %,$(strip $(CUS_MTK_LIB))\libcustom.a(%.obj), $(basename $(notdir $(def_c)))) $(CUS_MTK_LIB)\libcustom.a(nvram_data_items.obj) $(CUS_MTK_LIB)\libcustom.a(fs_quota.obj)
    else
      ifneq ($(filter custom,$(COMPLIST)),)
            NVRAM_OBJ_LIST += $(patsubst %,$(strip $(COMPLIBDIR))\libcustom.a(%.obj), $(basename $(notdir $(def_c)))) $(COMPLIBDIR)\libcustom.a(nvram_data_items.obj) $(COMPLIBDIR)\libcustom.a(fs_quota.obj)
      endif
    endif
    ifneq ($(filter nvram,$(CUS_REL_MTK_COMP)),)
        NVRAM_OBJ_LIST += $(strip $(CUS_MTK_LIB))\libnvram.a(nvram_factory_config.obj)
    else
      ifneq ($(filter nvram,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\libnvram.a(nvram_factory_config.obj)
      endif
    endif
  else
    ifneq ($(filter custom,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(patsubst %,$(strip $(COMPLIBDIR))\libcustom.a(%.obj), $(basename $(notdir $(def_c)))) $(COMPLIBDIR)\libcustom.a(nvram_data_items.obj) $(COMPLIBDIR)\libcustom.a(fs_quota.obj)
    endif
    ifneq ($(filter nvram,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\libnvram.a(nvram_factory_config.obj)
    endif
  endif


  ifneq ($(strip $(MMI_VERSION)),EMPTY_MMI)
    ifeq ($(strip $(CUSTOM_RELEASE)),TRUE)
      ifneq ($(filter custom,$(COMPLIST)),)
        ifneq ($(filter custom,$(CUS_REL_MTK_COMP)),)
          NVRAM_OBJ_LIST += $(strip $(CUS_MTK_LIB))\libcustom.a(nvram_common_config.obj) $(strip $(CUS_MTK_LIB))\libcustom.a(nvram_user_config.obj)
        else
          NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\libcustom.a(nvram_common_config.obj) $(strip $(COMPLIBDIR))\libcustom.a(nvram_user_config.obj)
        endif
      endif  
    else
      ifneq ($(filter custom,$(COMPLIST)),)
        NVRAM_OBJ_LIST += $(strip $(COMPLIBDIR))\libcustom.a(nvram_common_config.obj) $(strip $(COMPLIBDIR))\libcustom.a(nvram_user_config.obj)
      endif
    endif

    tbl_list +=logical_data_item_table_common_app logical_data_item_table_cust
  endif

  tbl_list +=g_fs_quota_init g_nvram_custpack_init

  NVRAM_LNK_OPT := $(patsubst %, --keep=%, $(tbl_list))
else
  
  nvram_dir_list := driver/common middleware/common modem/common/ps

  def_h := $(foreach DIR, $(nvram_dir_list), $(subst custom/$(DIR)/,,$(wildcard custom/$(DIR)/*_nvram_def.h)))

  editor_h := $(foreach DIR, $(nvram_dir_list), $(subst custom/$(DIR)/,,$(wildcard custom/$(DIR)/*_nvram_editor.h)))

  def_c := $(foreach DIR, $(nvram_dir_list), $(wildcard custom/$(DIR)/*_nvram_def.c))
  
endif

NVRAM_EDITOR_H_TO_DB:
	@$(ECHO) -n $(nvram_auto_gen_path)/nvram_editor.h
	@$(ECHO) -n OS_VERSION = $(OS_VERSION)

ifeq ($(strip $(OS_VERSION)),MSWin32)
	@echo #ifdef GEN_FOR_PC >  $(nvram_auto_gen_path)/nvram_editor.h
	@echo #ifndef __NVRAM_EDITOR_H__ >>	$(nvram_auto_gen_path)/nvram_editor.h
	@echo #define __NVRAM_EDITOR_H__ >>	$(nvram_auto_gen_path)/nvram_editor.h

	@echo  tmp_def_h = $(tmp_def_h)
  ifneq ($(words $(tmp_def_h)),0)
	@for %%f in ($(tmp_def_h)) do echo #include "%%f" >> $(nvram_auto_gen_path)/nvram_editor.h
  endif

	@$(ECHO) -n tmp_editor_h = $(tmp_editor_h)
  ifneq ($(words $(tmp_editor_h)),0)
	@for %%f in ($(tmp_editor_h)) do echo #include "%%f" >> $(nvram_auto_gen_path)/nvram_editor.h
  endif

	@echo #endif >>  $(nvram_auto_gen_path)/nvram_editor.h
	@echo #endif >>  $(nvram_auto_gen_path)/nvram_editor.h

	@${CAT} $(nvram_auto_gen_path)/nvram_editor.h
else	
	@$(ECHO) -n \#ifdef GEN_FOR_PC >  $(nvram_auto_gen_path)/nvram_editor.h
	@$(ECHO) -n \#ifndef __NVRAM_EDITOR_H__ >>	$(nvram_auto_gen_path)/nvram_editor.h
	@$(ECHO) -n \#define __NVRAM_EDITOR_H__ >>	$(nvram_auto_gen_path)/nvram_editor.h
	
	@$(ECHO) -n def_h = $(def_h)
    ifneq ($(words $(def_h)),0)
		@for f in $(def_h); \
		do \
		$(ECHO) -n  \#include \"$$f\" >>  $(nvram_auto_gen_path)/nvram_editor.h;\
		done
    endif	

	@$(ECHO) -n editor_h = $(editor_h)
    ifneq ($(words $(editor_h)),0)
		@for f in $(editor_h); \
		do \
		$(ECHO) -n  \#include \"$$f\" >>  $(nvram_auto_gen_path)/nvram_editor.h;\
		done
    endif
		@$(ECHO) -n \#endif >>  $(nvram_auto_gen_path)/nvram_editor.h
		@$(ECHO) -n \#endif >>  $(nvram_auto_gen_path)/nvram_editor.h

endif  


	
