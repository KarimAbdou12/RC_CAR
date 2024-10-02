/*
 * PUSH_BUTTONS_Prg.c
 *
 * Created: 9/27/2024 5:28:13 PM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "DIO_Int.h"
#include "PUSH_BUTTONS_Int.h"
#include "PUSH_BUTTONS_Cfg.h"
#include "PUSH_BUTTONS_Priv.h"


BUTTON_MODE_t Get_Buttton_Status (BUTTON_t button)
{
	BUTTON_MODE_t button_status=OFF;
	DIO_PinVoltage_t volt=HIGH;
	for(BUTTON_t i=0;i<NUM_OF_BUTTONS;i++)
	{
		if(i==button)
		{
			volt=DIO_ReadPin(ButtonsArray[i][constant_index_for_ButtonsArray]);
		}
		
	}
	if(volt==LOW)
	{
		button_status=ON;
	}
	
	return button_status;
}



BUTTON_MODE_t Get_forward_Button (void)
{
	BUTTON_MODE_t button_status=OFF;
	DIO_PinVoltage_t volt=HIGH;
	volt=DIO_ReadPin(BMF);
	
	if(volt==LOW)
	{
		button_status=ON;
	}
	
	return button_status;
}

BUTTON_MODE_t Get_Back_Button (void)
{
	BUTTON_MODE_t button_status=OFF;
	DIO_PinVoltage_t volt=HIGH;
	volt=DIO_ReadPin(BMB);
	if(volt==LOW)
	{
		button_status=ON;
	}
	
	return button_status;
}


BUTTON_MODE_t Get_Left_Button (void)
{
	BUTTON_MODE_t button_status=OFF;
	DIO_PinVoltage_t volt=HIGH;
	volt=DIO_ReadPin(BML);
	if(volt==LOW)
	{
		button_status=ON;
	}
	
	return button_status;
}


BUTTON_MODE_t Get_Right_Button (void)
{
	BUTTON_MODE_t button_status=OFF;
	DIO_PinVoltage_t volt=HIGH;
	
	volt=DIO_ReadPin(BMR);
	if(volt==LOW)
	{
		button_status=ON;
	}
	
	return button_status;
}