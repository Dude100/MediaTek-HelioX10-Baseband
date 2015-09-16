#ifndef __PLL_MT6752_H__
#define __PLL_MT6589_H__

#define PLL_PLL_CON1           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x044))
#define PLL_PLL_CON2           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x048))
#define PLL_PLL_CON3           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x04C))

#define PLL_CLKSW_CKSEL0       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x060))
#define PLL_CLKSW_CKSEL1       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x064))
#define PLL_CLKSW_CKSEL2       ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x068))

#define PLL_CLKSW_FDIV0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x070))
#define PLL_CLKSW_FDIV1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x074))
#define PLL_CLKSW_FDIV2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x078))
#define PLL_CLKSW_FDIV3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x07C))
#define PLL_CLKSW_FDIV4        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x080))
#define PLL_CLKSW_FDIV5        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x084))
#define PLL_CLKSW_FDIV6        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x088))

#define PLL_DFS_CON7           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0AC))
#define PLL_DFS_CON8           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B0))
#define PLL_DFS_CON9           ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x0B4))

#define PLL_MDPLL_CON0         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x100))
#define PLL_MDPLL_CON1         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x104))
#define PLL_MDPLL_CON2         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x108))
#define PLL_MDPLL_CON3         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x10C))
#define PLL_MDPLL_CON4         ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x110))

#define PLL_MCUPLL_CON0        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x140))
#define PLL_MCUPLL_CON1        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x144))
#define PLL_MCUPLL_CON2        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x148))
#define PLL_MCUPLL_CON3        ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x14C))

#define PLL_WPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C0))
#define PLL_WPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C4))
#define PLL_WPLL_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1C8))
#define PLL_WPLL_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x1CC))

#define PLL_WHPLL_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x200))
#define PLL_WHPLL_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x204))

#define PLL_PLLTD_CON0          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x700))
#define PLL_PLLTD_CON1          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x704))
#define PLL_PLLTD_CON2          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x708))
#define PLL_PLLTD_CON3          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x70C))
#define PLL_PLLTD_CON4          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x710))
#define PLL_PLLTD_CON5          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x714))
#define PLL_PLLTD_CON6          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x718))
#define PLL_PLLTD_CON7          ((volatile kal_uint16*)(PLL_MIXEDSYS_base+0x71C))

#define PLL_MD_GLOBAL_CON1      ((volatile kal_uint32*)(CONFIG_base+0x45C))


static inline void __mt6589_int_set_pll_inline__(pll_init_mode mode)
{
    volatile kal_uint32 i = 0, reg_val = 0;
    /* __MD1__ and __MD2__ both use the same PLL init flow */

    // Sequence to enable PLL
    //wait 100us for CLKSQ and BIAS_LPF enable settle, but no need to wait when boot up

    // force 26M and PLL on
    *PLL_DFS_CON7 = 0x003F;  // 0x801200AC, bit 0~5 set to 1 to force 26M and PLL on

    // enable MTCMOS control 
    *PLL_PLL_CON3 = 0x8100; // 0x8012004C, bit 12, 4 set to 0 to enable MTCMOS control

    //wait 1us for MTCMOS isolation enable settle
    for( i = 0 ; i < 27 ; i++); // in 26Mhz

        // enable MTCMOS and TOPSM control 
        *PLL_PLL_CON3 = 0x0000; // 0x8012004C, bit 15, 8, 1 and 0 set to 0 to enable MTCMOS control

    // enable TOPSM control 
    *PLL_PLL_CON2 = 0x0000; // 0x80120048, bit 12, 10, 8, 6 and 2 set to 0 to enable TOPSM control

    // enable delay control 
    *PLL_PLLTD_CON0 = 0x0010; //0x80120700, bit 0 set to 0 to enable delay control

    //wait for 3us for mode change signal stable
    for( i = 0 ; i < 79 ; i++); // in 26Mhz

        //enable MDPLL and MDPLL2
        reg_val = *PLL_MDPLL_CON0;
    reg_val |= 0x8000;
    *PLL_MDPLL_CON0  = reg_val ; //0x80120100, bit 15 set to 1 to enable MDPLL and MDPLL2

    //enable MCUPLL and MCUPLL2
    reg_val = *PLL_MCUPLL_CON0;
    reg_val |= 0x8000;
    *PLL_MCUPLL_CON0  = reg_val ; //0x80120140, bit 15 set to 1 to enable MCUPLL1 and MCUPLL2

    //enable WPLL
    reg_val = *PLL_WPLL_CON0;
    reg_val |= 0x8000;
    *PLL_WPLL_CON0  = reg_val ; //0x801201C0, bit 15 set to 1 to enable WPLL 

    //enable WHPLL
    reg_val = *PLL_WHPLL_CON0;
    reg_val |= 0x8000;
    *PLL_WHPLL_CON0 = reg_val ; //0x80120200, bit 15 set to 1 to enable WHPLL 

    //wait 100us for MCUPLL, MCUPLL2, MDPLL, MDPLL2, WPLL and WHPLL settle 
    for( i = 0 ; i < 2631 ; i++); // in 26Mhz

        // enable FH delay control 
        *PLL_PLLTD_CON0= 0x0000; //0x80120700, bit 4 set to 0 to enable FH delay control

    //wait 1us for MDPLL, MDPLL2 calibration data save
    for( i = 0 ; i < 27 ; i++); // in 26Mhz

        /* To disable "disable AUTOK", 
         * for workaround of HW issue that MDPLL fbdiv will sync a temperorily unstable value at reset.
         * Using AUTOK for each reset, to avoid this unstablibility.
         */
#if 0	
/* under construction !*/
/* under construction !*/
/* under construction !*/
/* under construction !*/
#endif //#if 0	

    // Sequence to switch to PLL clocks as below:
    //Switch CR4 clock to 481MHz
    reg_val = *PLL_CLKSW_CKSEL0; // 0x80120060
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL0 = reg_val;

    // Set ghmdbus_pllck_sel
    reg_val = *PLL_MD_GLOBAL_CON1; // 0x8000045C
    reg_val |= 0x20000000;
    *PLL_MD_GLOBAL_CON1 = reg_val;

    //Switch MD bus clock to PLL
    reg_val = *PLL_CLKSW_FDIV0; // 0x80120070
    reg_val &= 0xF0FF;
    reg_val |= 0x0400;
    *PLL_CLKSW_FDIV0 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x10; // 0x80120088
    *PLL_CLKSW_FDIV6 |= 0x400;
    *PLL_CLKSW_FDIV6 &= 0xFBFF;

    reg_val = *PLL_CLKSW_CKSEL1; // 0x80120064
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL1 = reg_val;

    //Switch DSP clock to 240.5MHz from MCUPLL
    reg_val = *PLL_CLKSW_FDIV0;
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_FDIV0 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x10;
    *PLL_CLKSW_FDIV6 |= 0x400;
    *PLL_CLKSW_FDIV6 &= 0xFBFF;
    reg_val = *PLL_CLKSW_CKSEL0;
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_CKSEL0 = reg_val;

    //Switch MODEMSYS clock to 208MHz from MDPLL
    reg_val = *PLL_CLKSW_FDIV2; // 0x80120078
    reg_val &= 0xFF0F;
    reg_val |= 0x0020;
    *PLL_CLKSW_FDIV2 = reg_val;
    *PLL_CLKSW_FDIV6 |= 0x4;
    *PLL_CLKSW_FDIV6 |= 0x100;
    *PLL_CLKSW_FDIV6 &= 0xFEFF;

    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0xF0FF;
    reg_val |= 0x0200;
    *PLL_CLKSW_CKSEL2 = reg_val;

    //Switch WPLL clock to 245.76MHz(WPLL)
    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0x0FFF;
    reg_val |= 0x2000;
    *PLL_CLKSW_CKSEL2 = reg_val;

    //Switch MCUPLL clock to 250.25MHz(WHPLL)
    reg_val = *PLL_CLKSW_CKSEL2;
    reg_val &= 0xFF0F;
    reg_val |= 0x0040;
    *PLL_CLKSW_CKSEL2 = reg_val;

    // Disable Force on DPM PLL control for PLL
    *PLL_DFS_CON7 = 0x0000;
}

#endif  /* !__PLL_MT6752_H__ */
