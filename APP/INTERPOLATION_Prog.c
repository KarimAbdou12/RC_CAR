
#include "StdTypes.h"
#include "Math.h"
#include "KEYPAD_Int.h"
#include "LCD_Int.h"


void Interpolation_Init (void)
{
	Welcome();
}

void Repeat (void)
{
	LCD_Clear();
	LCD_SetCursor(1,1);
	LCD_WriteString("1st x_axis:");
	LCD_SetCursor(2,1);
	LCD_WriteString("1st y_axis:");
	LCD_SetCursor(3,1);
	LCD_WriteString("2nd x_axis:");
	LCD_SetCursor(4,1);
	LCD_WriteString("2nd y_axis:");
	
	
}

void Interpolation_Runnable (void)
{
	static u16 arr_point[6];
	static u8 flag=0x55;
	static u8 i=0;
	static u8 num=0;
	u8 k;
	if(0x55==flag)
	{
		Repeat();
		flag=0XAA;
	}
	
	k=KEYPAD_GetKey();
	if(k!=NO_KEY)
	{
		
		if(k>='0'&&k<='9')
		{
			num=num*10+k-'0';
			
			switch (i)
			{
				case 0:
				LCD_SetCursor(1,12);
				LCD_WriteChar(k);
				break;
				case 1:
				LCD_SetCursor(2,12);
				LCD_WriteChar(k);
				
				break;
				case 2:
				LCD_SetCursor(3,12);
				LCD_WriteChar(k);
				
				break;
				case 3:
				LCD_SetCursor(4,12);
				LCD_WriteChar(k);
				
				break;
				case 4:
				
				LCD_SetCursor(1,15);
				LCD_WriteChar(k);
				
				break;
				
			}
			
			
		}
		if(k=='=')
		{
			arr_point[i]=num;
			num=0;
			i++;
			if(6==i)
			{
				LCD_SetCursor(2,1);
				LCD_WriteString("req y_axis:");
				arr_point[i]=Interpolation_Calc(arr_point[0],arr_point[1],arr_point[2],arr_point[3],arr_point[4]);
				LCD_WriteNumber(arr_point[i]);
			}
			
		}
		if(k=='c')
		{
			Repeat();
		}
		
		
	}
	
}
