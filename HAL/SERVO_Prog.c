
#include "StdTypes.h"
#include "Timers.h"
#include "SERVO_Int.h"

#include "DIO_Int.h"



u8 cst=8;



void Servo_SetAngle(u8 angle) // Timer 1
{
	OCR1B=499+((angle*(u32)2000)/180);
}




/******** FOR Servo ************/

// PWM on PINC4 by using timer0 normal mode 

// tick time = 1Ms , full time req = 20000 Ms

// 20000/250= 80 over flow 
// 1000/ 250 = 2 over flow
// 2000/250 = 6 over flow
// 1500/250 = 4 over flow 

// 2 over flow that refer to 0 positon 
// 4 over flow that refer to 90 position 
// 8 over flow that refer to 180 position

void stepper_timer0_normal_mode (void)
{
	static u8 flag=0;
	
	if (flag==0)
	{
		DIO_WritePin(PINC4,HIGH);
		
	}
	else if (flag==cst)
	{
		DIO_WritePin(PINC4,LOW);
		
	}
	
	flag++;
	
	if(flag==80)
	{
		flag=0;
		DIO_WritePin(PINC4,HIGH);
	}
	
}


/********************************/

void servo_timer0_init(void)
{
	sei();
	TIMER0_Init(TIMER0_NORMAL_MODE,TIMER0_SCALER_8); // enable mode
	TIMER0_OC0Mode(OC0_DISCONNECTED);
	TIMER0_OV_InterruptEnable();
	TCNT0=6;
	Timer0_OVF_SetCallBack(stepper_timer0_normal_mode);
}

void servo_timer0_Runnable(u8 position)
{
	 cst=position;
}

