#ifndef __DCL_15_SEGMENT_H__
#define __DCL_15_SEGMENT_H__
#include "dcl.h"

/****************************************************/

typedef enum {
	GPIO_LED1,
	GPIO_LED2
}LED_NUM;

typedef enum{
	LED_CMD_FLICKER,
	LED_CMD_DIMMING,
	LED_CMD_BRIGHTING
	
}LED_CTRL_CMD;

typedef struct
{
	kal_uint8 Char_D;
	kal_uint8 Char_C;
	kal_uint8 Char_B;
	kal_uint8 Char_A;
}char_to_display;

/****************************************************/
extern DCL_STATUS gpio_led_init(void);

/*************************************************************************
* FUNCTION
*  gpio_led_control
*
* DESCRIPTION
*  This function is to control led display
*
* PARAMETERS
*	
*
* RETURN VALUES:
*	STATUS_OK
*
*************************************************************************/

extern DCL_STATUS gpio_led_control(LED_NUM led_num, LED_CTRL_CMD cmd, kal_uint16 freq);

/*************************************************************************
* FUNCTION
*  gpio_15_segment_led_init
*
* DESCRIPTION
*  This function is to init 15-segment
*
* PARAMETERS
*	
*
* RETURN VALUES:
*	STATUS_OK
*
*************************************************************************/

extern DCL_STATUS gpio_15_segment_led_init(void);

/*************************************************************************
* FUNCTION
*  gpio_15_segment_led_control
*
* DESCRIPTION
*  This function is to control 15-segment
*
* PARAMETERS
*	
*
* RETURN VALUES:
*	STATUS_OK
*
*************************************************************************/

extern DCL_STATUS gpio_15_segment_led_control(kal_uint8 word1, kal_uint8 word2);



#endif
