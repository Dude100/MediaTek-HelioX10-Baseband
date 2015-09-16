#ifndef CMMB_CUSTOM_IF_H
#define CMMB_CUSTOM_IF_H

#define INTERFACE_SPIONLY
#define INNO_DOWNLOAD_FROM_BB

//This define to indicate Innofidei cmmb chip using 26M clk or 20M clk. 
//Because different clk should download different firmware.
//The following define can define "INNO_26M_FW" or "INNO_20M_FW"
#define INNO_26M_FW	

#ifdef __CUST_NEW__

extern const char gpio_cmmb_power_on_pin;
extern const char gpio_cmmb_reset_pin;
extern const char gpio_cmmb_spi_eint_pin;
extern const char gpio_cmmb_spi_cs_n_pin;
extern const char gpio_cmmb_spi_sck_pin;
extern const char gpio_cmmb_spi_mosi_pin;
extern const char gpio_cmmb_spi_miso_pin;

extern const char gpio_cmmb_spi_eint_pin_M_EINT;
extern const char gpio_cmmb_reset_pin_M_GPIO;
extern const char gpio_cmmb_power_on_pin_M_GPIO;
extern const char gpio_cmmb_spi_cs_n_pin_M_SPI_CS_N;
extern const char gpio_cmmb_spi_sck_pin_M_SPI_SCK;
extern const char gpio_cmmb_spi_mosi_pin_M_SPI_MOSI;
extern const char gpio_cmmb_spi_miso_pin_M_SPI_MISO;

#define CMMB_GPIO_RESET_PIN     gpio_cmmb_reset_pin
#define CMMB_GPIO_POWER_ON_PIN  gpio_cmmb_power_on_pin
#define CMMB_SPI_EINT_GPIO_PIN  gpio_cmmb_spi_eint_pin
#define CMMB_SPI_CS_N_GPIO_PIN  gpio_cmmb_spi_cs_n_pin
#define CMMB_SPI_SCK_GPIO_PIN   gpio_cmmb_spi_sck_pin
#define CMMB_SPI_MOSI_GPIO_PIN  gpio_cmmb_spi_mosi_pin
#define CMMB_SPI_MISO_GPIO_PIN  gpio_cmmb_spi_miso_pin

#define CMMB_SPI_EINT_PIN_MODE  gpio_cmmb_spi_eint_pin_M_EINT
#define CMMB_GPIO_RESET_MODE    gpio_cmmb_reset_pin_M_GPIO
#define CMMB_GPIO_PWR_ON_MODE   gpio_cmmb_power_on_pin_M_GPIO
#define CMMB_SPI_CS_N_PIN_MODE  gpio_cmmb_spi_cs_n_pin_M_SPI_CS_N
#define CMMB_SPI_SCK_PIN_MODE   gpio_cmmb_spi_sck_pin_M_SPI_SCK
#define CMMB_SPI_MOSI_PIN_MODE  gpio_cmmb_spi_mosi_pin_M_SPI_MOSI
#define CMMB_SPI_MISO_PIN_MODE  gpio_cmmb_spi_miso_pin_M_SPI_MISO

#else //__CUST_NEW__

	enum
	{
	  //SDIO
	  CMMB_GPIO_MCCM0_PIN    =  67,
	  CMMB_GPIO_MCDA0_PIN    =  68,
	  CMMB_GPIO_MCDA1_PIN    =  69,
	  CMMB_GPIO_MCDA2_PIN    =  70,
	  CMMB_GPIO_MCDA3_PIN    =  71,
	  CMMB_GPIO_MCCK_PIN     =  72,

	  CMMB_GPIO_POWER_ON_PIN  =  83,
	  CMMB_GPIO_RESET_PIN     =  62,

	  CMMB_SPI_CS_N_GPIO_PIN   = 63,
	  CMMB_SPI_SCK_GPIO_PIN    = 59,
	  CMMB_SPI_MOSI_GPIO_PIN   = 61,
	  CMMB_SPI_MISO_GPIO_PIN   = 60,

	  CMMB_SPI_EINT_GPIO_PIN   = 48

	};
#endif //__CUST_NEW__

extern void cmmb_power_on_custom(void);
extern void cmmb_power_off_custom(void);

#endif
