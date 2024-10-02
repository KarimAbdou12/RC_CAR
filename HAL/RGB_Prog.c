
#include "StdTypes.h"
#include "DIO_Int.h"
#include "Timers.h"
#include "RGB_Int.h"
#include "RGB_Cfg.h"


#define  F_CPU   8000000
#include <util/delay.h>


u8 RGB_Colors[12][3]={{255,255,255},// white
{255,0,0},// red
{0,255,0},// green
{0,0,255},//blue
{255,255,0},//yellow
{255,0,255},//move
{0,255,255},//baby blue
{153,255,255},
{255,128,0},
{255,51,153},
{153,51,255},
{255,0,127}
};


/*************** DIO PINS ( no PWM ) *********************/ 

void RGB_DIO_PIN (u8 rgb_color)
{
	switch (rgb_color)
	{
		case 'w':
		DIO_WritePin(red_pin,HIGH);
		DIO_WritePin(green_pin,HIGH);
		DIO_WritePin(blue_pin,HIGH);
		break;
		
		case 'r':
		DIO_WritePin(red_pin,HIGH);
		DIO_WritePin(green_pin,LOW);
		DIO_WritePin(blue_pin,LOW);
		break;
		
		case 'g':
		DIO_WritePin(red_pin,LOW);
		DIO_WritePin(green_pin,HIGH);
		DIO_WritePin(blue_pin,LOW);
		break;
		
		case 'B':
		DIO_WritePin(red_pin,LOW);
		DIO_WritePin(green_pin,LOW);
		DIO_WritePin(blue_pin,HIGH);
		break;
		
		case 'y':
		DIO_WritePin(red_pin,HIGH);
		DIO_WritePin(green_pin,HIGH);
		DIO_WritePin(blue_pin,LOW);
		break;
		
		case 'm':
		DIO_WritePin(red_pin,HIGH);
		DIO_WritePin(green_pin,LOW);
		DIO_WritePin(blue_pin,HIGH);
		break;
		
		case 'b':
		DIO_WritePin(red_pin,LOW);
		DIO_WritePin(green_pin,HIGH);
		DIO_WritePin(blue_pin,HIGH);
		break;
	}
	
}

void RGB_OFF (void)
{
	DIO_WritePin(red_pin,LOW);
	DIO_WritePin(green_pin,LOW);
	DIO_WritePin(blue_pin,LOW);
}
/*********************************************/

/*********** RGB PWM ***********************/

void RGB_Init (void)
{
	TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	TIMER0_OC0Mode(OC0_NON_INVERTING);// ocp
	//TIMER0_SetCompareUnit(255); // write register compare match
	
	Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8); // TOP
	Timer1_OCRA1Mode(OCRA_NON_INVERTING); // toggle on it
	Timer1_OCRB1Mode(OCRB_NON_INVERTING);// toggle on it
	ICR1=255;
}

void RGB_COLOR (u8 ind)
{
	
	OCR1B=RGB_Colors[ind][0]; // red
	OCR1A=RGB_Colors[ind][1]; //green
	TIMER0_SetCompareUnit(RGB_Colors[ind][2]);// blue
	
	
	
}

void RGB_OFF_PWM (void)
{
	OCR1B=0; // red
	OCR1A=0; //green
	TIMER0_SetCompareUnit(0);
}

void Moving_All_Color(void)
{
	static u8 ind=0;
	
	OCR1B=RGB_Colors[ind][0]; // red
	OCR1A=RGB_Colors[ind][1]; //green
	TIMER0_SetCompareUnit(RGB_Colors[ind][2]);// blue
	
	ind++;
	_delay_ms(1500);
	if(12==ind)
	{
		ind=0;
	}
}

/********************************/