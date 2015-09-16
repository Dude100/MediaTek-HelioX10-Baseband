/*****************************************************************************
*  Copyright Statement:
*  --------------------
*  This software is protected by Copyright and the information contained
*  herein is confidential. The software may not be copied and the information
*  contained herein may not be used or disclosed except with the written
*  permission of MediaTek Inc. (C) 2001
*
*****************************************************************************/

/*****************************************************************************
 *
 * Filename:
 * ---------
 *   dcl_kbd.h
 *
 * Project:
 * --------
 *   Maui
 *
 * Description:
 * ------------
 *   Header file of DCL (Driver Common Layer) for KBD.
 *
 * Author:
 * -------
 * -------
 *
 *============================================================================
 *             HISTORY
 * Below this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *------------------------------------------------------------------------------
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 *
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 * removed!
 *------------------------------------------------------------------------------
 * Upper this line, this part is controlled by PVCS VM. DO NOT MODIFY!!
 *============================================================================
 ****************************************************************************/

#include "drv_features.h"
#include "dcl.h"
#include 	"drv_comm.h"
#include    "reg_base.h"
#include    "intrCtrl.h" 
#include    "drv_hisr.h"
#include "keypad.h"
#include "keypad_sw.h"
#include "keypad_hw.h"
#include    "drv_trc.h"
#include "kal_general_types.h"
#include "kal_trace.h"
#include "kal_public_api.h"
    
#ifndef DRV_KP_OFF
#if !defined(DRV_KBD_NOT_EXIST)

#define DCL_HKBD_IS_HANDLE_MAGIC(handl_) ((handl_)& DCL_HKBD_MAGIC_NUM)
#define DCL_HKBD_GET_DEV(handle_) ((handle_) & (~DCL_HKBD_MAGIC_NUM))

KBDH_EVENT_FUNC      DclHKBD_Event_cb = NULL;

static void kbd_get_status_reg(HKBD_CTRL_STA_MAP_T *pkeypad_status);
static void Kbd_LISR(void);
static void Kbd_HisrEntry(void);
extern const keypad_customize_function_struct *keypad_GetFunc(void);
static kal_bool kbd_IsKeyPress(kal_uint8 key);
static kal_bool PowerKey_Press(void);
#if defined(JOGBALL_SUPPORT)
extern void Jogball_Init(void);
extern void Jogball_Reset(void);
#endif //#if defined(JOGBALL_SUPPORT)


// internal api
static void kbd_get_status_reg(HKBD_CTRL_STA_MAP_T *pkeypad_status)
   {
	kal_uint32 initstatus = 0xFFFFFFFF;
	pkeypad_status->kbdmap_reg = initstatus;
	pkeypad_status->kbdmap_reg1= initstatus;
	pkeypad_status->kbdmap_reg2= initstatus;
  
#if defined(DRV_KBD_32KEYS_EQ_BELOW) || defined(FPGA) 
      pkeypad_status->kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
#elif defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg = ( ((kal_uint32)(DRV_Reg(KP_MID_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_LOW_KEY))) );
#if defined(DRV_KBD_32KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = (kal_uint32)(DRV_Reg(KP_HI_KEY)); 
#elif defined(DRV_KBD_48KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = ( ((kal_uint32)(DRV_Reg(KP_HI_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) ); 
#elif defined(DRV_KBD_64KEYS_ABOVE) 
      pkeypad_status->kbdmap_reg1 = ( ((kal_uint32)(DRV_Reg(KP_MID2_KEY) << 16))|((kal_uint32)(DRV_Reg(KP_MID1_KEY))) ); 
      pkeypad_status->kbdmap_reg2 = (kal_uint32)(DRV_Reg(KP_HI_KEY)); 
#endif 
#endif
   }

/*************************************************************************
* FUNCTION                                                            
*	kbd_IsKeyPressed
*
* DESCRIPTION                                                           
*	
*	This function queries if a specific key is Pressed
*
* PARAMETERS
*  key        - Key ID to query
*
* RETURNS
*  KAL_TRUE   - The specific key is pressed
*  KAL_FALSE  - The specific key is NOT pressed or NOT supported
*
* GLOBALS AFFECTED
*
*************************************************************************/
kal_bool kbd_IsKeyPress(kal_uint8 key)
{
   kal_uint32 num_key, i;
   kal_uint16 u4KeyReg = 0;
   kal_bool fgKeyPressed = KAL_FALSE;
   const keypad_customize_function_struct *keypadCustomFunc = NULL;
   const keypad_struct *keypad_comm_def = NULL;
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
   kal_bool btmp = KAL_TRUE;
   kal_uint32 j, k;
   kal_uint16 reg, checkRow, bit;
   kal_uint8      key_bit_map[72] = {0};
#endif //#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above

   if(keypad_comm_def == NULL)
   	{
   		keypadCustomFunc=keypad_GetFunc();
   		keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
   	}
   
   num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
   for (i=0;i<num_key;i++){
      if ( key == keypad_comm_def->keypad[i] ){ //key supported
#if defined(__EXTEND_QWERTY_KEYPAD__) //assume it only support fot 32 key above
         if(i >= kbd_allkeys) //GPO or GND
         {
            for(k=0; k<kbd_allkeys; ) //i already ++ in inner loop
            {
               // base on key register offset = 4 sequentially
               reg = DRV_KBD_Reg(KP_LOW_KEY + ((k>>4) <<2) );//  i/16 --> n-th register,  *4 --> register offset.
               for(j=0; j<16 && k<kbd_allkeys; j++, k++)
               {
                  bit = (reg >> (k&0xF) ) & 0x1; // select (i&0xF)-th bit in this register
                  if(key_bit_map[k] != bit)
                  {
                     key_bit_map[k] = bit; // put this bit into array
                  }
               }
            }
            // check which column is all low
            for(checkRow=0; checkRow<KBD_ROW; checkRow++)
            {
               btmp = (kal_bool)(btmp & ((key_bit_map[checkRow*KBD_COLUMN + (i%KBD_COLUMN) ] == 1) ? KAL_FALSE : KAL_TRUE)); //if one key not press, we know this column not all low.
            }
            if(btmp == KAL_TRUE)
            {
               fgKeyPressed = KAL_TRUE; 
            }
            return fgKeyPressed;
         }
#endif
         // don't need to take care of key number define, num_key has information in it.
         if(i < 16) // key pressed
         {
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY);
         }
         else if(i < 32)
         {
            i -= 16;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x4);
         }
         else if(i < 48)
         {
            i -= 32;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x8);
         }
         else if(i < 64)
         {
            i -= 48;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0xC);
         }
         else
         {
            i -= 64;
            u4KeyReg = DRV_KBD_Reg(KP_LOW_KEY + 0x10);
         }
         
         if( (u4KeyReg & (1 << i)) == 0)
         {
            fgKeyPressed = KAL_TRUE;
         }
         
         if(fgKeyPressed)
         {
#if !defined(LOW_COST_SUPPORT)
            drv_trace1(TRACE_GROUP_2, KBD_KEY_QUERY_PRESSED, key);
#endif // #if !defined(LOW_COST_SUPPORT)
            return KAL_TRUE;
         }
         else
         {
            break;
         }
      }
   }
#if !defined(LOW_COST_SUPPORT)
   drv_trace1(TRACE_GROUP_2, KBD_KEY_QUERY_NOT_PRESSED, key);
#endif // #if !defined(LOW_COST_SUPPORT)
   return KAL_FALSE;	
}

/*
* FUNCTION
*	   PowerKey_Pressed
*
* DESCRIPTION                                                           
*   	This function is to check if power key is pressed 
*
* CALLS  
*
* PARAMETERS
*	   None
*	
* RETURNS
*	   return keypressed result
*
* GLOBALS AFFECTED
*     None
*/

kal_bool PowerKey_Press(void)
{
   kal_uint32 i;
   kal_uint16 pwrkey_reg=0;
   kal_uint16 pwrkey_bit=0;
   kal_uint16 powerkey_status=0;
   kal_uint32 num_key;
   const keypad_customize_function_struct *keypadCustomFunc = NULL;
   const keypad_struct *keypad_comm_def = NULL;
	if(keypad_comm_def == NULL)
	{
	keypadCustomFunc=keypad_GetFunc();
	keypad_comm_def = keypadCustomFunc->keypad_Get_Data();
	}
   num_key = sizeof(keypad_comm_def->keypad)/sizeof(kal_uint8);
   for(i=0;i<num_key;i++)
   {
      if(keypad_comm_def->keypad[i]==keypad_comm_def->powerkey_position)
      {
         pwrkey_reg=(i/16);         
         pwrkey_bit=0x0001 <<(i&0xf);
         break;
      }     
   }   
#if defined(DRV_KBD_MUX_WITH_GPIO)
   /* Need a delay to wait 32KHz sample for keypad scan. */
   for(i=0;i<1000000;i++)
   {
   }
#endif /* KBD_MUX_WITH_GPIO */
   switch(pwrkey_reg)
   {
       case low_key:
         powerkey_status= DRV_KBD_Reg(KP_LOW_KEY);
         break;
#if defined(DRV_KBD_32KEYS_ABOVE) || defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      case medium_key:
         powerkey_status= DRV_KBD_Reg(KP_MID_KEY);               
         break;
#endif          
#if defined(DRV_KBD_48KEYS_ABOVE) || defined(DRV_KBD_64KEYS_ABOVE)
      case medium_key1:
         powerkey_status= DRV_KBD_Reg(KP_MID1_KEY);
         break;
#endif          
#if defined(DRV_KBD_64KEYS_ABOVE)
      case medium_key2:
         powerkey_status= DRV_KBD_Reg(KP_MID2_KEY);               
         break;
#endif          
      case high_key:
         powerkey_status= DRV_KBD_Reg(KP_HI_KEY);
         break;
      default:
         ASSERT(0);
         break;     
   }
        
   if((DRV_KBD_Reg(KP_STS) & KP_STS_KEYPRESS) && 
       ((~powerkey_status)&(pwrkey_bit))//((~DRV_KBD_Reg(KP_LOW_KEY))&(PWRKEY_index))
     )
   {
      return KAL_TRUE;
   }
   else
      return KAL_FALSE;  
        
    
}   

void Kbd_LISR(void)
{
  #if defined(__EXTEND_QWERTY_KEYPAD__) 
  KBD_MASKIRQ;
	#endif  //#if defined(__EXTEND_QWERTY_KEYPAD__)
   drv_active_hisr(DRV_KP_HISR_ID);
}

void Kbd_HisrEntry(void)
{      
	if(NULL != DclHKBD_Event_cb)
		DclHKBD_Event_cb(DCL_EVENT_HKBD_STATUS_CHANGE, 0);
      	else
		ASSERT(0);
}

#if defined(DRV_KBD_MUX_WITH_GPIO) && defined(DRV_GPIO_REG_AS_6225)
static char KBD_GPO_ReturnMode(char port)
{
	DCL_HANDLE handle;
	DCL_CTRL_DATA_T data;
	handle=DclGPIO_Open(DCL_GPO,port);
	DclGPIO_Control(handle,GPO_CMD_RETURN_MODE,&data);
	DclGPIO_Close(handle);
	return data.oReturnMode.u1RetMode;
}

static void KBD_GPIO_PullenSetup(kal_uint16 pin, kal_bool enable)
{
	DCL_HANDLE handle;
	handle=DclGPIO_Open(DCL_GPIO,pin);
	if(KAL_FALSE==enable)
		DclGPIO_Control(handle,GPIO_CMD_DISABLE_PULL,0);
	else
		DclGPIO_Control(handle,GPIO_CMD_ENABLE_PULL,0);
	DclGPIO_Close(handle);
}
#endif

DCL_STATUS DclHKBD_Initialize(void)
{

#if defined(DRV_KBD_MUX_WITH_GPIO) && defined(DRV_GPIO_REG_AS_6225)
   if ((2==KBD_GPO_ReturnMode(35)) || (2==KBD_GPO_ReturnMode(36)))
   {
	  KBD_GPIO_PullenSetup(35, KAL_FALSE);
	  KBD_GPIO_PullenSetup(36, KAL_FALSE);
	  DRV_KBD_SetBits(0x80000700, 0x0002);
   }
#endif

	DRV_Register_HISR(DRV_KP_HISR_ID, Kbd_HisrEntry);
	IRQ_Register_LISR(IRQ_KPAD_CODE, Kbd_LISR,"KBD handler");

	DRV_KBD_WriteReg(KP_DEBOUNCE,KP_DEBOUNCE_TIME);/*16ms*/

	IRQSensitivity(IRQ_KPAD_CODE,EDGE_SENSITIVE);

	IRQUnmask(IRQ_KPAD_CODE);
#if defined(JOGBALL_SUPPORT)
	Jogball_Init();
#endif

#if !defined(KBD_DETECT_ONLY_ONE_KEY) && defined(__EXTRA_A_B_KEY_SUPPORT__)
	if ( EINT_CheckHWDebounce(EINT_A_KEY) )
	EINT_Registration(EINT_A_KEY, KAL_TRUE, LEVEL_LOW, EXT_A_EINT_HISR, KAL_TRUE);
	else
	EXTRA_EINT_Registration(EINT_A_KEY, LEVEL_LOW, EXT_A_EINT_HISR, KAL_TRUE);

	if ( EINT_CheckHWDebounce(EINT_B_KEY) )
	EINT_Registration(EINT_B_KEY, KAL_TRUE, LEVEL_LOW, EXT_B_EINT_HISR, KAL_TRUE);
	else
	EXTRA_EINT_Registration(EINT_B_KEY, LEVEL_LOW, EXT_B_EINT_HISR, KAL_TRUE);
	EINT_Mask(EINT_A_KEY);
	EINT_Mask(EINT_B_KEY);
	EINT_Set_HW_Debounce(EINT_A_KEY, 50);
	EINT_Set_HW_Debounce(EINT_B_KEY, 50);
#endif

	DclHKBD_Event_cb =NULL;
	return STATUS_OK;

}

DCL_HANDLE DclHKBD_Open(DCL_DEV dev, DCL_FLAGS flags)
{
	if((DCL_KBD != dev) )
	{
		ASSERT(0);
		return DCL_HANDLE_INVALID;
	}
	
	return (DCL_HANDLE)DCL_HKBD_MAGIC_NUM; 
}

DCL_STATUS DclHKBD_Close(DCL_HANDLE handle){	return STATUS_OK;}


DCL_STATUS DclHKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
	if( (DCL_HKBD_IS_HANDLE_MAGIC(handle) == 0) )
	   {
	   	  ASSERT(0);
	      return DCL_HANDLE_INVALID;
	   }
	  
	switch (cmd)
	{
		case HKBD_CMD_GET_KEY_NUMBER:
			{
				HKBD_CTRL_KNUM_T  *pCtrlQKN;  
				pCtrlQKN = &(data->rKBDCtrlKNUM);
				pCtrlQKN->u2KeyNum = kbd_allkeys;//kbd_allkeys define in keypad_sw.h
				break;
			}
			 
		case HKBD_CMD_GET_KEY_STA_MAP:
			{
				HKBD_CTRL_STA_MAP_T  *pCtrlSMAP;  
				pCtrlSMAP = &(data->rKBDCtrlStaMap);
				kbd_get_status_reg(pCtrlSMAP);
				break;
			}
	
		case HKBD_CMD_GET_KEY_STATUS:
			{
				HKBD_CTRL_KEY_STA_T* pCtrlKeySta;
				pCtrlKeySta = &(data->rKBDCtrlKeySta);
				pCtrlKeySta->sta = kbd_IsKeyPress(pCtrlKeySta->key);
				break;	
			}
		
		case HKBD_CMD_GET_POWER_KEY_STATUS:
			{
				HKBD_CTRL_POWKEY_T* pCtrlKeySta;
				pCtrlKeySta = &(data->rKBDCtrlPowerKeySta);
				pCtrlKeySta->fgPKP = PowerKey_Press();
				break;
			}
			default:
			break;
				
	}
	return STATUS_OK;
}


DCL_STATUS DclHKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, KBDH_EVENT_FUNC callback)
{
	if(DCL_EVENT_HKBD_STATUS_CHANGE == event)
		DclHKBD_Event_cb = callback;
	else
		return STATUS_INVALID_EVENT;
	
	return STATUS_OK;

}


#else

#ifdef DRV_KBD_ALWAYS_PWRKEY_PRESS
kal_bool kbd_IsKeyPress(kal_uint8 key){return KAL_TRUE;}
kal_bool PowerKey_Press(void){return KAL_TRUE;}
#else
kal_bool kbd_IsKeyPress(kal_uint8 key){return KAL_FALSE;}
#endif
DCL_STATUS DclHKBD_RegisterCallback(DCL_HANDLE handle, DCL_EVENT event, KBDH_EVENT_FUNC callback){return STATUS_INVALID_EVENT;}
DCL_STATUS DclHKBD_Close(DCL_HANDLE handle){	return STATUS_OK;}

DCL_HANDLE DclHKBD_Open(DCL_DEV dev, DCL_FLAGS flags){return STATUS_UNSUPPORTED;}
DCL_STATUS DclHKBD_Control(DCL_HANDLE handle, DCL_CTRL_CMD cmd, DCL_CTRL_DATA_T *data)
{
#ifdef DRV_KBD_ALWAYS_PWRKEY_PRESS
	switch (cmd)
	{
		case HKBD_CMD_GET_KEY_STATUS:
			{
				HKBD_CTRL_KEY_STA_T* pCtrlKeySta;
				pCtrlKeySta = &(data->rKBDCtrlKeySta);
				pCtrlKeySta->sta = kbd_IsKeyPress(pCtrlKeySta->key);
				break;	
			}
		case HKBD_CMD_GET_POWER_KEY_STATUS:
			{
				HKBD_CTRL_POWKEY_T* pCtrlKeySta;
				pCtrlKeySta = &(data->rKBDCtrlPowerKeySta);
				pCtrlKeySta->fgPKP = PowerKey_Press();
				break;
			}
		default:
			break;			
	}
	return STATUS_OK;
#else
	return STATUS_INVALID_CMD;
#endif
}

#endif

#endif
