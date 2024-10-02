
#include "StdTypes.h"
#include "ADC_Int.h"
#include "LCD_Int.h"
#include "KEYPAD_Int.h"
#include "Sensors_Int.h"


#define  F_CPU   8000000
#include <util/delay.h>


void Normal_Mode (u16 temp)
{
	u8 remainder=0;	
	remainder=temp%10;
	temp=temp/10;
	LCD_SetCursor(1,7);
	LCD_WriteString("NORMAL");
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder);
	
	LCD_WriteString("      ");
	
	// motor off
	//leds off
	
}

void Heat_Mode (u16 temp,u16 pres_smoke)
{
	u8 remainder_temp=0;
	remainder_temp=temp%10;
	temp=temp/10;
	
	LCD_SetCursor(1,7);
	LCD_WriteString("HEAT");
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder_temp);
	LCD_WriteString("      ");
	LCD_SetCursor(2,15);
	LCD_WriteNumber(pres_smoke);
	LCD_WriteString("      ");
	
	 // fan on
	 //y led on
	
}

void Fire_Mode (u16 temp,u16 pres_smoke)
{
	u8 remainder_temp=0;
	remainder_temp=temp%10;
	temp=temp/10;
	
	LCD_SetCursor(1,7);
	LCD_WriteString("FIRE");
	LCD_WriteString("      ");
	LCD_SetCursor(2,1);
	LCD_WriteNumber(temp);
	LCD_WriteChar('.');
	LCD_WriteNumber(remainder_temp);
	LCD_WriteString("      ");
	LCD_SetCursor(2,15);
	LCD_WriteNumber(pres_smoke);
	LCD_WriteString("      ");
	
	
	// pump on
	//R led on
}


void FireSystem_Init (void)
{
	
}

void FireSystem_Runnable (void)
{
	static u16 temp=0;
	static u16 pres_smoke=0;
	
	temp=TEMP_Read();
	pres_smoke = ADC_Read(CH_7);
	pres_smoke=((u32)pres_smoke*100)/1023;
	
	if(pres_smoke>60)
	{
		Fire_Mode(temp,pres_smoke);
	}
	else if(temp>500)
	{
		Heat_Mode(temp,pres_smoke);
	}
	else if(temp<500)
	{
		Normal_Mode(temp);
	}
	
}