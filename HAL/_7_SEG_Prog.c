/*
 * _7_seg_MLX_Prog.c
 *
 * Created: 9/19/2024 1:31:18 AM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "_7_SEG_Int.h"

#define	F_CPU	8000000
#include <util/delay.h>


// Common Cathode 
void _7_SEG_2DIG_DISPLAY (u8 num)
{
	const u8 arr[10]={0X3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
	
	SET_BIT(PORTC,ENABLE_1ST_DIGIT);
	CLR_BIT(PORTC,ENABLE_2ND_DIGIT);
	SEGMENT_DISPLAY_PORT=arr[num%10];
	
	_delay_ms(10);
	
	SET_BIT(PORTC,ENABLE_2ND_DIGIT);
	CLR_BIT(PORTC,ENABLE_1ST_DIGIT);
	
	SEGMENT_DISPLAY_PORT=arr[num/10];
	
	_delay_ms(10);
}

/* 2 BCD CONNECTED IN THE SAME PORT */
void _7_SEG_DIS_BCD (u8 num)
{
	u8 d0=num%10;
	u8 d1=num/10;
	
	PORTB = d1<<4|d0;
}

/* Lissa m3maltha4 di *//*
void _7_SEG_DIS_BCD_HEX (u8 num)
{
	if(num>=10&&num<=15)
	{
		PORTB = num;
	}
	else
	{
		u8 d0=num%10;
		u8 d1=num/10;
		
		PORTB = ; // write F 3ady
	}
	
}*/