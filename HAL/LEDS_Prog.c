
#include "StdTypes.h"
#include "DIO_Int.h"
#include "LEDS_Config.h"
#include "LEDS_Int.h"


void LED_On (Led_num_t num)
{
	DIO_WritePin(num,HIGH);
}

void LED_Off (Led_num_t num)
{
	DIO_WritePin(num,LOW);
}
