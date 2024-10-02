
#include "StdTypes.h"
#include "DIO_Int.h"

const DIO_Pin_t LED_Array_on[8]={PINB0,PINB1,PINB2,PINB3,PINB4,PINB5,PINB6,PINB7};

void LED_Count(u8 i)
{
	for(char x=0;x<i;x++)
	{
		DIO_WritePin(LED_Array_on[x],HIGH);
	}
}

void ALL_LED_OFF(void)
{
	for(char x=0;x<8;x++)
	{
		DIO_WritePin(LED_Array_on[x],LOW);
	}
}

void LED_ON(u8 i)
{
	DIO_WritePin(LED_Array_on[i],HIGH);
}

void LED_off(u8 i)
{
	DIO_WritePin(LED_Array_on[i],LOW);
}

