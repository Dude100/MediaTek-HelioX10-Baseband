#!/usr/bin/perl

my $DebugPrint    = 0;

#****************************************************************************
# subroutine:  custom_EMI_release_h_file_body
# return:      
#****************************************************************************
sub custom_EMI_release_h_file_body
{
    my ($CUSTOM_MEM_DEV_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $emi_clk_config_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api) = @_;
    my $emi_clk_str;
    my $emi_device_mode;

    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS'))
    {
        $emi_clk_str = sprintf("#define __EMI_CLK_%sMHZ__", $emi_clk_config_LOCAL);
        if ($emi_clk_str =~ /\./)
        {
            $emi_clk_str =~ s/\./_/;
        }
    }
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} =~ /LPDDR2/)
    {
        $emi_device_mode = "#define __EMI_DEVICE_LPDDR2__\n#define __EMI_MODE_2X__";
    }
    elsif ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} =~ /LPDDR/)
    {
        $emi_device_mode = "#define __EMI_DEVICE_LPDDR1__\n#define __EMI_MODE_1X__";
    }
    else
    {
        &error_handler("MEMORY_DEVICE_TYPE:$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} didn't support yet!", __FILE__, __LINE__);
    }

    print "MDL info:$COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'}\n" if ($DebugPrint == 1);

    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_RELEASE_H__
#define __CUSTOM_EMI_RELEASE_H__
/********************************************
 * Include.
 ********************************************/
#include "kal_general_types.h"
$cus_include
/********************************************
 * Definition.
 ********************************************/
/**
  * Define EMI's clock rate.
  * comes from EMI_CLK definition in custom_MemoryDevice.h, or highest freq in MDL 
  */
$emi_clk_str

/**
  * Define memory's mode.
  */
$emi_device_mode

/**
  * Define RAM size in Bytes.
  */
#define EMI_EXTSRAM_SIZE ((($COMM_MDL_INFO_LOCAL->{1}->{'Size (Mb)'})>>3)<<20)
$cus_def
/********************************************
 * Enum.
 ********************************************/
$cus_enum
/********************************************
 * Struct.
 ********************************************/
$cus_struct
/********************************************
 * Exposed APIs.
 ********************************************/
$cus_api
#endif /* __CUSTOM_EMI_RELEASE_H__ */

__TEMPLATE

    return $template;
}


#****************************************************************************
# subroutine:  custom_EMI_release_h_90_file_body
# return:      
#****************************************************************************
sub custom_EMI_release_h_90_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL) = @_;
    my ($cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);

    return &custom_EMI_release_h_file_body($CUSTOM_MEM_DEV_OPTIONS_LOCAL, $COMM_MDL_INFO_LOCAL, $emi_clk_config_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);
}

#****************************************************************************
# subroutine:  custom_EMI_h_file_body
# return:      
#****************************************************************************
sub custom_EMI_h_file_body
{
    ### EMI register value for each MCP
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api) = @_;
    my ($combo_mem_emi_reg, $combo_mem_emi_reg_clk);
    my $emi_reg_bb_key_ref;
    my $clk, $first_parse_clk;
    my $mtk_emi_info;
    
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        my $def_pre = undef;
        undef $mtk_emi_info;
        undef $first_parse_clk;

        $combo_mem_emi_reg .= <<"__TEMPLATE";
/*
 * EMI register value definition
 * EMI/MEM configuration information of MCP$combo_idx
 */
__TEMPLATE
        $def_pre = "#define DRAM_VENDOR_MCP$combo_idx";
        $combo_mem_emi_reg .= $def_pre;
        $combo_mem_emi_reg .= " " x (47 - length($def_pre));
        $combo_mem_emi_reg .= " (\"$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Vendor'}\")\n";
        $def_pre = "#define DRAM_PART_NUMBER_MCP$combo_idx";
        $combo_mem_emi_reg .= $def_pre;
        $combo_mem_emi_reg .= " " x (47 - length($def_pre));
        $combo_mem_emi_reg .= " (\"$MDL_INFO_LIST_LOCAL->[$_]->{0}->{'Part Number'}\")\n";
        my $emi_reg_bb_key_ref = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{$MAKEFILE_OPTIONS_LOCAL->{'platform'}};
        foreach my $emi_key (sort keys %{$emi_reg_bb_key_ref})
        {
            if ($emi_key =~ /(\d+)MHZ EMI Driving/)
            {
                $clk = $1;
                if (! defined $first_parse_clk)
                {
                    $first_parse_clk = $clk;
                }
                if (! defined $combo_mem_emi_reg_clk)
                {
                    $combo_mem_emi_reg_clk = "#if defined(__EMI_CLK_$clk\MHZ__)\n";
                }
                else
                {
                    $combo_mem_emi_reg_clk .= "#elif defined(__EMI_CLK_$clk\MHZ__)\n";
                }
                my $emi_clk_dri = $emi_key;
                foreach my $emi_key (sort keys %{$emi_reg_bb_key_ref->{$emi_clk_dri}})
                {
                    my $val = $emi_reg_bb_key_ref->{$emi_clk_dri}->{$emi_key};
                    if (($val ne 'x') && ($val ne 'X') && ($val ne ''))
                    {
                        $def_pre = "#define $emi_key\_MCP$combo_idx";
                        $combo_mem_emi_reg_clk .= $def_pre;
                        # for alignment
                        $combo_mem_emi_reg_clk .= " " x (47 - length($def_pre));
                        $combo_mem_emi_reg_clk .= " ($val)\n";
                    }

                    if ($first_parse_clk == $clk)
                    {
                        $mtk_emi_info .= "    unsigned int " . lc($emi_key) . ";\n";
                    }
                }
            }
            else
            {
                my $val = $emi_reg_bb_key_ref->{$emi_key};
                $def_pre = "#define $emi_key\_MCP$combo_idx";
                if (($val ne 'x') && ($val ne 'X') && ($val ne ''))
                {
                    $combo_mem_emi_reg .= $def_pre;
                    # for alignment
                    $combo_mem_emi_reg .= " " x (47 - length($def_pre));
                    $combo_mem_emi_reg .= " ($val)\n";
                }
                $mtk_emi_info .= "    unsigned int " . lc($emi_key) . ";\n";
            }
        }
        $combo_mem_emi_reg_clk .= "#endif /* __EMI_CLK_$clk\MHZ__ */\n";

        $combo_mem_emi_reg .= <<"__TEMPLATE";

$combo_mem_emi_reg_clk
/*
 * End of EMI/MEM configuration information of MCP$combo_idx
 */
__TEMPLATE

        undef $combo_mem_emi_reg_clk;
    }

    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_H__
#define __CUSTOM_EMI_H__
/********************************************
 * Include.
 ********************************************/
$cus_include
/********************************************
 * Definition.
 ********************************************/
$combo_mem_emi_reg
$cus_def
/********************************************
 * Enum.
 ********************************************/
typedef enum {
    DRAMType_Invalid = 0x0,
    DRAMType_DDR,
    DRAMType_DDR2,
    DRAMType_DDR_166M,
    DRAMType_DDR_200M,
    DRAMType_DDR2_166M,
    DRAMType_DDR2_200M,
    DRAMType_LPDDR = 0x800,
    DRAMType_LPDDR2,
    DRAMType_LPDDR_166M,
    DRAMType_LPDDR_200M,
    DRAMType_LPDDR2_166M,
    DRAMType_LPDDR2_200M,
    DRAMType_DDR_166M_SIP = 0x1000,
    DRAMType_DDR_200M_SIP,
    DRAMType_DDR2_166M_SIP,
    DRAMType_DDR2_200M_SIP,
    DRAMType_LPDDR_SIP = 0x1800,
    DRAMType_LPDDR2_SIP,
    DRAMType_LPDDR_166M_SIP,
    DRAMType_LPDDR_200M_SIP,
    DRAMType_LPDDR2_166M_SIP,
    DRAMType_LPDDR2_200M_SIP,
    DRAMType_End = 0x42424242
} DRAMType;
$cus_enum
/********************************************
 * Struct.
 ********************************************/
typedef struct {
    DRAMType ramType;
$mtk_emi_info} MTK_EMI_Info;
$cus_struct
/********************************************
 * Exposed APIs.
 ********************************************/
$cus_api
#endif /* end of __CUSTOM_EMI_H__ */
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_h_90_file_body
# return:      
#****************************************************************************
sub custom_EMI_h_90_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL, $MCP_LIST_LOCAL) = @_;
    my ($cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);

    $cus_def = <<"__TEMPLATE";
/* Initial EMI Definition */
#define USE_DUAL_RANK_DDR
#define DRAM_START          (0x00000000)

#define MAX_DQ_DATA_WIDTH   (32)

#define DQ_NUMBER_PER_DQS   (8)
#define DQS_NUMBER          (dq_data_width / DQ_NUMBER_PER_DQS)
#define TX_STEPS            (8)   // This value is obtained by measurement of waveform for the relationship between DQS and CLK.
__TEMPLATE

    $cus_api = <<"__TEMPLATE";
kal_int8 custom_InitDRAM(void);
__TEMPLATE

    return &custom_EMI_h_file_body($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);
}

#****************************************************************************
# subroutine:  custom_EMI_info_h_file_body
# return:      
#****************************************************************************
sub custom_EMI_info_h_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $emi_clk_config_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api) = @_;
    my $combo_mem_emi_info_struct;
    my $combo_mem_emi_type;

    $combo_mem_emi_type = "DRAMType_";
    if ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{MEMORY_DEVICE_TYPE} =~ /[A-Za-z]*DDR[0-9]*/)
    {
        $combo_mem_emi_type .= $&;
    }
    if (($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{FLASH_ACCESS_TYPE} eq 'SYNC_ACCESS') && ($CUSTOM_MEM_DEV_OPTIONS_LOCAL->{RAM_ACCESS_TYPE} eq 'SYNC_ACCESS'))
    {
        $combo_mem_emi_type .= sprintf("_%sM", $emi_clk_config_LOCAL);
    }
    if ($MAKEFILE_OPTIONS_LOCAL->{'sip_ram_size'} ne "NONE") {
        $combo_mem_emi_type .= "_SIP";       
    }
    for (1..$CUSTOM_MEM_DEV_OPTIONS_LOCAL->{COMBO_MEM_ENTRY_COUNT})
    {
        my $combo_idx = $_ - 1;
        $combo_mem_emi_info_struct .= <<"__TEMPLATE";
    {
        .ramType = $combo_mem_emi_type,
__TEMPLATE
        my $emi_reg_bb_key_ref = $MDL_INFO_LIST_LOCAL->[$_]->{0}->{$MAKEFILE_OPTIONS_LOCAL->{'platform'}};
        foreach my $emi_key (sort keys %{$emi_reg_bb_key_ref})
        {
            if ($emi_key =~ /(\d+)MHZ EMI Driving/)
            {
                my $emi_clk_dri = $emi_key;
                foreach my $emi_key (sort keys %{$emi_reg_bb_key_ref->{$emi_clk_dri}})
                {
                    my $val = $emi_reg_bb_key_ref->{$emi_clk_dri}->{$emi_key};
                    if (($val ne 'x') && ($val ne 'X') && ($val ne ''))
                    {
                        my $emi_info_def = "$emi_key\_MCP$combo_idx";
                        $combo_mem_emi_info_struct .= "        ." . lc($emi_key) . " = " . $emi_info_def . ",\n";
                    }
                }
            }
            else
            {
                my $val = $emi_reg_bb_key_ref->{$emi_key};
                if (($val ne 'x') && ($val ne 'X') && ($val ne ''))
                {
                    my $emi_info_def = "$emi_key\_MCP$combo_idx";
                    $combo_mem_emi_info_struct .= "        ." . lc($emi_key) . " = " . $emi_info_def . ",\n";
                }
            }
        }
        $combo_mem_emi_info_struct .= "    },\n";
    }
    my $template = <<"__TEMPLATE";
#ifndef __CUSTOM_EMI_INFO_H__
#define __CUSTOM_EMI_INFO_H__
/********************************************
 * Include.
 ********************************************/
#include "custom_EMI_release.h"
#include "custom_EMI.h"
$cus_include
/********************************************
 * Definition.
 ********************************************/
$cus_def
/********************************************
 * Enum.
 ********************************************/
$cus_enum
/********************************************
 * Struct.
 ********************************************/
MTK_EMI_Info EMI_INFO[] = {
$combo_mem_emi_info_struct
}; /* End of EMI_INFO struct */
$cus_struct
/********************************************
 * Exposed APIs.
 ********************************************/
$cus_api

#endif /* __CUSTOM_EMI_INFO_H__ */
__TEMPLATE

    return $template;
}

#****************************************************************************
# subroutine:  custom_EMI_info_h_90_file_body
# return:      
#****************************************************************************
sub custom_EMI_info_h_90_file_body
{
    my ($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $COMM_MDL_INFO_LOCAL, $PART_NUMBER_LOCAL, $CUSTOM_MEMORY_DEVICE_HDR_LOCAL, $LPSDRAM_CHIP_SELECT_LOCAL, $emi_clk_config_LOCAL, $emi_nor_cmd_num_max_LOCAL, $emi_psram_cmd_num_max_LOCAL) = @_;
    my ($cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);

    return &custom_EMI_info_h_file_body($MAKEFILE_OPTIONS_LOCAL, $CUSTOM_MEM_DEV_OPTIONS_LOCAL, $MDL_INFO_LIST_LOCAL, $emi_clk_config_LOCAL, $cus_include, $cus_def, $cus_enum, $cus_struct, $cus_api);
}

return 1;
