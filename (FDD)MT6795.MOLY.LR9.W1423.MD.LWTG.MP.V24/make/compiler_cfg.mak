
# ******************************************
# re-configure CC and ARM path
# ******************************************
Special_Mod =gadget_adp
ifeq ($(filter $(strip $(COMPONENT)),$(strip $(Special_Mod))),)
  include $(strip $(TARGDIR))\log\infomake.log
endif

  DIR_ARM   =  C:\Progra~1\ARM\RVCT
  DIR_PRO_1021  =  $(DIR_ARM)\Programs\3.1\569
  DIR_PRO_569   =  $(DIR_ARM)\Programs\3.1\569_init
  
  DIR_DATA_1021 =  $(DIR_ARM)\Data\3.1\569
  DIR_DATA_569  =  $(DIR_ARM)\Data\3.1\569_init
ifeq ($(filter $(strip $(COMPONENT)),$(strip $(Special_Mod))),)  
ifneq ($(filter $(strip $(COMPONENT)),$(strip $(CUS_REL_SRC_COMP))),)  
  ifeq ($(strip $(RVCT_VERSION)),V31)
        DIR_TOOL       =  $(DIR_PRO_569)\win_32-pentium
        DIR_ARMLIB     =  $(DIR_DATA_569)\lib
        DIR_ARMINC     =  $(DIR_DATA_569)\include\windows
  endif
 CFLAGS := $(filter-out -D__FILE__=__MODULE__,$(strip $(CFLAGS)))
 CPLUSFLAGS :=$(filter-out -D__FILE__=__MODULE__,$(strip $(CPLUSFLAGS)))
else
 ifeq ($(strip $(COMPILER)),RVCT)
  DIR_TOOL       =  $(DIR_PRO_1021)\win_32-pentium
  DIR_ARMLIB     =  $(DIR_DATA_1021)\lib
  DIR_ARMINC     =  $(DIR_DATA_1021)\include\windows
  ifeq ($(filter -D__FILE__=__MODULE__,$(CFLAGS)),)
    CFLAGS += -D__FILE__=__MODULE__
  endif
  ifeq ($(filter -D__FILE__=__MODULE__,$(CPLUSFLAGS)),)
    CPLUSFLAGS += -D__FILE__=__MODULE__
  endif
 else
 CFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CFLAGS)))
 endif
endif
else
 ifeq ($(strip $(COMPILER)),RVCT)
  DIR_TOOL       =  $(DIR_PRO_1021)\win_32-pentium
  DIR_ARMLIB     =  $(DIR_DATA_1021)\lib
  DIR_ARMINC     =  $(DIR_DATA_1021)\include\windows
  ifeq ($(filter -D__FILE__=__MODULE__,$(CFLAGS)),)
  CFLAGS += -D__FILE__=__MODULE__
  endif
  ifeq ($(filter -D__FILE__=__MODULE__,$(CPLUSFLAGS)),)
    CPLUSFLAGS += -D__FILE__=__MODULE__
  endif
 else
  CFLAGS := $(filter-out --remove_unneeded_entities,$(strip $(CFLAGS)))
 endif
endif

COMPILE_MODE   =  INST16
ifeq ($(strip $(COMPILER)),RVCT)
  ifeq ($(strip $(COMPILE_MODE)),INST16)
     CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT)  # Thumb Mode(16bits), use tcc
     CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)    # ARM Mode(32bits), use armcc
     ASM         =  $(DIR_TOOL)\armasm.exe           # ARM assembler
     LIB         =  $(DIR_PRO_1021)\win_32-pentium\armar.exe            # Library tool
     BIN_CREATE  =  $(DIR_TOOL)\fromelf.exe          # Binary tool
  else
     ifeq ($(strip $(COMPILE_MODE)),INST32)
        CC          =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)  # ARM Mode(32bits), use armcc
        ASM         =  $(DIR_TOOL)\armasm.exe           # ARM assembler
        LIB         =  $(DIR_PRO_1021)\win_32-pentium\armar.exe            # Library tool
        BIN_CREATE  =  $(DIR_TOOL)\fromelf.exe          # Binary tool
     else
        CC          =  $(DIR_TOOL)\armcc.exe --thumb $(VFP_OPTION_SOFT) # Default tcc
        CC32        =  $(DIR_TOOL)\armcc.exe --arm $(VFP_OPTION)  # ARM Mode(32bits), use armcc
        ASM         =  $(DIR_TOOL)\armasm.exe           # ARM assembler
        LIB         =  $(DIR_PRO_1021)\win_32-pentium\armar.exe            # Library tool
        BIN_CREATE  =  $(DIR_TOOL)\fromelf.exe          # Binary tool
     endif
  endif
endif

#******************************************
