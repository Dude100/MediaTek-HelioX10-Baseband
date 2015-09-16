# Define source file lists to SRC_LIST
SRC_LIST = service/hif/hmu/src/hmu.c
SRC_LIST += service/hif/hmu/src/hmu_conf_data.c


#  Define include path lists to INC_DIR
INC_DIR = interface/service/hif		\
		  service/hif/hmu/include	\
		  service/hif/interface
 
# Define the specified compile options to COMP_DEFS
COMP_DEFS = _HMU_

# Define the source file search paths to SRC_PATH
SRC_PATH = service/hif/hmu/src
