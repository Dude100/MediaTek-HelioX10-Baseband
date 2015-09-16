CATEGORY_INCDIRS += interface/service/fsm
CATEGORY_INCDIRS += interface/service/flc2

CATEGORY_INCDIRS += $(strip $(MODEM_FOLDER))/interface/general \
                    $(strip $(MODEM_FOLDER))/interface/l4 \
                    $(strip $(MODEM_FOLDER))/interface/l4misc \
                    $(strip $(MODEM_FOLDER))/interface/mcd/include \
                    $(strip $(MODEM_FOLDER))/l4/include \
                    $(strip $(MODEM_FOLDER))/l4/atci/include \
                    $(strip $(MODEM_FOLDER))/l4/l4c/include/common \
                    $(strip $(MODEM_FOLDER))/l4/l4c/include/proc \
                    $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
                    $(strip $(MODEM_FOLDER))/l4/uem/include \
                    $(strip $(MODEM_FOLDER))/l4/phb/include \
                    $(strip $(MODEM_FOLDER))/l4/csm/cc/include \
                    $(strip $(MODEM_FOLDER))/l4/csm \
                    $(strip $(MODEM_FOLDER))/l4/tcm/etcm/include \
                    $(strip $(MODEM_FOLDER))/l4/smsal/include \
                    $(strip $(MODEM_FOLDER))/l4/tcm/rat_tcm/inc \
                    $(strip $(MODEM_FOLDER))/l4/csm/ss/asn1/gen/include \
                    $(strip $(MODEM_FOLDER))/l4/smu/include \
                    $(strip $(MODEM_FOLDER))/l4/rac/common/include \
                    $(strip $(MODEM_FOLDER))/l4/rac/ugrac/include \
                    $(strip $(MODEM_FOLDER))/interface/asn/rr/include \
                    $(strip $(MODEM_FOLDER))/l4/smslib/include \
                    $(strip $(MODEM_FOLDER))/gl1/l1_dm/l1d_ext

ifneq ($(strip $(EUTRAN_MODE_SUPPORT)),NONE)
  CATEGORY_INCDIRS += $(strip $(MODEM_FOLDER))/l4/rac/erac/include
endif             

ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R8_SUPPORT)
  CATEGORY_INCDIRS += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext
else
  ifeq ($(strip $(UMTS_RELEASE_SUPPORT)),UMTS_R7_SUPPORT)
    CATEGORY_INCDIRS += $(strip $(MODEM_FOLDER))/ul1/ul1_hs_plus/ul1d_ext
  else
    ifneq ($(filter $(strip $(PLATFORM)),$(UL1_HS_PLATFORM)),)
      CATEGORY_INCDIRS += $(strip $(MODEM_FOLDER))/ul1/ul1_hs/ul1d_ext
    endif
  endif
endif

CATEGORY_DEFS += 
