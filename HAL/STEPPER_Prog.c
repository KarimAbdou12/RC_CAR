/*
 * STEPPER_Prog.c
 *
 * Created: 12/13/2023 10:02:17 AM
 *  Author: Magic
 */ 



#include "StdTypes.h"
#include "DIO_Int.h"
#include "STEPPER_Int.h"
#include "STEPPER_Cfg.h"

#define  F_CPU   8000000
#include <util/delay.h>

/* full 4 step -- half 8 step */

void STEPPER_Bipoler_CW (void) 
{
	DIO_WritePin(COIL1A_BI,HIGH);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,HIGH);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,HIGH);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
}

void STEPPER_Bipoler_CCW (void) 
{
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,HIGH);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,LOW);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,HIGH);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_BI,HIGH);
	DIO_WritePin(COIL1B_BI,LOW);
	DIO_WritePin(COIL2A_BI,LOW);
	DIO_WritePin(COIL2B_BI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
}

void Bi_polar_quadrant (void)
{
	u8 i=0;
	for(i=0;i<=11;i++)
	{
		STEPPER_Bipoler_CCW();
	}
	
}

void Bi_polar_three_quartes_of_cycle (void)
{
	u8 i=0;
	for(i=0;i<=37;i++)
	{
		STEPPER_Bipoler_CCW();
	}
	
} 

void Bi_polar_halfcycle (void)
{
	u8 i=0;
	for(i=0;i<=24;i++)
	{
		STEPPER_Bipoler_CCW();
	}
	
}

void Bi_polar_fullcycle (void)
{
	u8 i=0;
	for(i=0;i<=49;i++)
	{
		STEPPER_Bipoler_CCW();
	}
}


void STEPPER_Unipoler_CW (void)
{
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
}

void STEPPER_Unipoler_CCW (void) 
{
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
}

void STEPPER_Unipoler_CW_HS (void)
{
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
}

void STEPPER_Unipoler_CCW_HS (void)
{
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,HIGH);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,LOW);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,HIGH);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,LOW);
	
	_delay_ms(STEPPER_DELAY);
	
	DIO_WritePin(COIL1A_UNI,HIGH);
	DIO_WritePin(COIL1B_UNI,LOW);
	DIO_WritePin(COIL2A_UNI,LOW);
	DIO_WritePin(COIL2B_UNI,HIGH);
	
	_delay_ms(STEPPER_DELAY);
}
