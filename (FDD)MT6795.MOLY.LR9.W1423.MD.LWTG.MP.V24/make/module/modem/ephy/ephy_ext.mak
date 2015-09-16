# Define source file lists to SRC_LIST
SRC_LIST = $(strip $(MODEM_FOLDER))/ephy/ephy_ext/ephy_rf_custom_data.c \
           $(strip $(MODEM_FOLDER))/ephy/ephy_ext/ephy_rf_custom_func.c \
           $(strip $(MODEM_FOLDER))/ephy/ephy_ext/ephy_rf_custom_error_check.c 

#  Define include path lists to INC_DIR
INC_DIR = $(strip $(MODEM_FOLDER))/ephy/ephy_ext

# Define the source file search paths to SRC_PATH
SRC_PATH = $(strip $(MODEM_FOLDER))/ephy/ephy_ext
