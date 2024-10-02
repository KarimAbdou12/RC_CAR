/*
 * revision_project.c
 *
 * Created: 9/11/2024 11:41:39 AM
 * Author : Karim Abdou
 */ 


#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Int.h"
#include "ECU_Int.h"
#include "PUSH_BUTTONS_Int.h"
#include "UART_Int.h"
#include "STEPPER_Int.h"
#include "LCD_Int.h"
#include "KEYPAD_Int.h"
#include "CALCULATOR_Int.h"
#include "ADC_Int.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "ULTRASONIC_Int.h"
#include "Sensors_Int.h"
#include "Math.h"
#include "UART_Service.h"
#include "RGB_Int.h"
#include "MOTOR_Int.h"
#include "SERVO_Int.h"
#include "INTERPOLATION_Int.h"
#include "FIRESYSTEM_Int.h"
#include "SMART_HOME_Int.h"


#define  F_CPU   8000000
#include <util/delay.h>


int main(void)
{
	DIO_Init();
	
    while (1) 
    {
		MOVE_Runnable();
    }
	
}

