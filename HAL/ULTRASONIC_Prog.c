
#include "StdTypes.h"
#include "DIO_Int.h"
#include "Timers.h"
#include "Timers_Services.h"
#include "ULTRASONIC_Int.h"
#include "LCD_Int.h"

#define  F_CPU   8000000
#include <util/delay.h>


volatile u8 ULTRA_Flag=0;
volatile u8 ultra_ind_flag=0;
volatile u16 t1,t2;
u16 distance;
u16 Distance_Buffer[4]={0,0,0,0};
	
u16 dis1=0;



/*
static void f2 (void) // done
{
	static u8 c=0;
	c++;
	ultra_ind_flag++;
	
	if(ULTRA_Flag==0)
	{
		t1=ICR1;
		ULTRA_Flag=1;
		Timer1_InputCaptureEdge(FALLING);
	}
	else if(ULTRA_Flag==1)
	{
		t2=ICR1;
		ULTRA_Flag=2;
		Timer1_ICU_InterruptDisable();
	}
	
	LCD_SetCursor(2,1);
	LCD_WriteNumber(ultra_ind_flag);
}

void ULTRASONIC_Init(void) // done
{
	 sei();
	 Timer1_Init(TIMER1_NORMAL_MODE,TIMER1_SCALER_8);
	 Timer1_ICU_SetCallBack(f2);
}

void Ultrasonic_TR_ON (Ultra_TR_t TR_PIN)
{
	TCNT1=0;
	DIO_WritePin(TR_PIN,HIGH);
	_delay_ms(10);
	DIO_WritePin(TR_PIN,LOW);
	Timer1_InputCaptureEdge(RISING);
	Timer1_ICU_InterruptEnable();
	ULTRA_Flag=0;
}


void ULTRASONIC_Runnable(void) // done
{
	static u8 start_flag=0;
	u16 dis1=0;
	u16 dis2=0;
	u16 dis3=0;
	u16 dis4=0;
	
	
	if(0==start_flag)
	{
		TIMER0_Init(TIMER0_CTC_MODE,TIMER0_SCALER_8);
		TIMER0_OC_InterruptEnable();
		OCR0=50;
		start_flag=1;
	}
	
	switch (ultra_ind_flag)
	{
		case 0 :
		Ultrasonic_TR_ON(ULTRA1_TR);
		break;
		case 2:
		dis1=(t2-t1)/58;
		Ultrasonic_TR_ON(ULTRA2_TR);
		break;
		
		case 4:
		dis2=(t2-t1)/58;
		Ultrasonic_TR_ON(ULTRA3_TR);
		break;
		
		case 6:
		dis3=(t2-t1)/58;
		Ultrasonic_TR_ON(ULTRA4_TR);
		break;
		
		case 8:
		dis4=(t2-t1)/58;
		Distance_Buffer[0]=dis1;
		Distance_Buffer[1]=dis2;
		Distance_Buffer[2]=dis3;
		Distance_Buffer[3]=dis4;
		ultra_ind_flag=0;
		break;
		
		default:
		return;
		break;
	}
	
		
}

u16 ULTRASONIC_Getdistance(Ultra_num_t ultra)
{
	u16 distance_ultra=0;
	switch (ultra)
	{
		case Ultrasonic1:
		distance_ultra=Distance_Buffer[0];
		break;
		case Ultrasonic2:
		distance_ultra=Distance_Buffer[1];
		break;
		case Ultrasonic3:
		distance_ultra=Distance_Buffer[2];
		break;
		case Ultrasonic4:
		distance_ultra=Distance_Buffer[3];
		break;
	}
	return distance_ultra;
}

void ULTRASONIC_GetdistanceAll(u16* distanceAll)
{
	u8 ind;
	for(ind=0;ind<4;ind++)
	{
		distanceAll[ind]=Distance_Buffer[ind];
	}
}

ISR(TIMER0_OC_vect)
{
	ULTRASONIC_Runnable();
}
ISR(TIMER0_OV_vect)
{
	
}

/* for ultrasonic on kit */
/*
u16 ultrasonic_kit (void)
{
	 u16 dis;
	 TCNT1=0;
	 DIO_WritePin(PINC0,HIGH);
	 _delay_ms(10);
	 DIO_WritePin(PINC0,LOW);
	 Timer1_InputCaptureEdge(RISING);
	 Timer1_ICU_InterruptEnable();
	 ULTRA_Flag=0;
	 while(ULTRA_Flag<2);
	 dis=(t2-t1)/58;
	 LCD_WriteString("ergd");
	 LCD_WriteNumber(dis);
	 return dis;
	 
	 // main
		dis=ultrasonic_kit();
		LCD_SetCursor(2,1);
		LCD_WriteNumber(dis);
		LCD_WriteString("   ");
}
*/