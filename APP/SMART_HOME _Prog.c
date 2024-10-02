

#include "StdTypes.h"
#include "DIO_Int.h"
#include "UART_Service.h"
#include "LCD_Int.h"
#include "LEDS_Int.h"
#include "LEDS_Config.h"
#include "MOTOR_Int.h"
#include "SERVO_Int.h"
#include "RGB_Int.h"
#include "SMART_HOME_Int.h"
#include "SMART_HOME_Priv.h"



#define  F_CPU   8000000
#include <util/delay.h>





Task_t tasks[20]={	{(u8*)"ledon",SH_ROOMLED_ON},		//1
					{(u8*)"ledoff",SH_ROOMLED_OFF},		//2
					{(u8*)"opendoor",SH_OPEN_DOOR},		//3
					{(u8*)"closedoor",SH_CLOSE_DOOR},	//4
					{(u8*)"rgbon",RGB_ON_PWM},	
					{(u8*)"rgbon",RGB_ON_PWM},			
					{(u8*)"rgbon",RGB_ON_PWM},		
					{(u8*)"rgbon",RGB_ON_PWM},				
					{(u8*)"rgbon",RGB_ON_PWM},		
					{(u8*)"rgbon",RGB_ON_PWM},			
					{(u8*)"rgbon",RGB_ON_PWM},		
					{(u8*)"rgboff",RGB_ON_PWM},
					{(u8*)"servo",SERVO_CONFG},
					{(u8*)"stepper",Stepper_Moving},		
					};
								
						
						
// compare string if it'sn't same return  problem in frame
// call
//tasks[i].str for compare 

//tasks[3].fptr(3);
// string space num

//u8*frame_rec[15];
u8*dframe_rec[20];

u8 doorflag=0;

void Stepper_Moving (u32 position)
{
	if(45 == position)
	{
		Bi_polar_quadrant(); 
	}
	else if(position==90)
	{
		Bi_polar_halfcycle();
	}
	else if(position==135)
	{
		Bi_polar_three_quartes_of_cycle();
	}
	else if(position==180)
	{
		Bi_polar_fullcycle();
	}
	return ;
}

void SERVO_CONFG (u32 position)
{
	servo_timer0_init();
	
	if(0==position)
	{
		servo_timer0_Runnable(_0_position);
	}
	else if(90==position)
	{
		servo_timer0_Runnable(_90_position);
	}
	else if(180==position)
	{
		servo_timer0_Runnable(_180_position);
	}
}

void RGB_OFF_DIO(u32 color)
{
	RGB_OFF();
}

void RGB_ON_DIO (u32 color)
{
	RGB_DIO_PIN(color);
}

void RGB_ON_PWM (u32 color)
{
	RGB_Init();
	
	LCD_WriteNumber(color);
	
	switch (color)
	{
		case 'w':
		RGB_COLOR(0);
		break;
		
		case 'r':
		RGB_COLOR(1);
		break;
		
		case 'g':
		RGB_COLOR(2);
		break;
		 
		case 'B':
		RGB_COLOR(3);
		break;
		
		case 'y':
		RGB_COLOR(4);
		break;
		
		case 'm':
		RGB_COLOR(5);
		break;
		
		case 'b':
		RGB_COLOR(6);
		break;
		
	}
}


void SH_ROOMLED_ON (u32 led)
{
	switch (led)
	{
		case 1 :
		LED_On(_1st_led);
		break;
		
		case 2 :
		LED_On(_2nd_led);
		break;
		
		case 3 :
		LED_On(_3rd_led);
		break;
		
	}
}



void SH_ROOMLED_OFF (u32 led)
{
	switch (led)
	{
		case 1 :
		LED_Off(_1st_led);
		break;
		
		case 2 :
		LED_Off(_2nd_led);
		break;
		
		case 3 :
		LED_Off(_3rd_led);
		break;
		
	}
}

void SH_OPEN_FAN (u32 motor)
{
	MOTOR_CW(M6);
}

void SH_CLOSE_FAN (u32 motor)
{
	MOTOR_Stop(M6);
}


void SH_OPEN_DOOR (u32 motor)
{
	if(doorflag==0)
	{
		doorflag=1;
		MOTOR_CW(M5);
		_delay_ms(1000);
		MOTOR_Stop(M5);
	}
	
	
}

void SH_CLOSE_DOOR (u32 motor)
{
	if(doorflag==1)
	{
		doorflag=0;
		MOTOR_CCW(M5);
		_delay_ms(1000);
		MOTOR_Stop(M5);
	}
	
	
}

u8 String_Compare (u8*str,u8 ind) // done
{
	u8 i=0;
	for(i=0;str[i];i++)
	{
		if((str[i])!=(tasks[ind].str[i]))
		{
			return 0; 
		}
	}
	
	LCD_WriteString("str ok");
	return 1;
}

u8 convert_str_to_num(u8*str) // done
{
	u8 num=0;
	u8 i;
	for(i=0;str[i]!='*';i++)
	{
		num=num*10+(str[i]-'0');
	}
	return num;
}


u8 Seperate_string_num(u8*frame_rec,u8*num,u8*str)
{
	u8 i=0;
	u8 j=0;
	u8 color_ch[7]={'w','r','g','B','y','m','b'};
	//frame_rec[i]!=' '
	while((frame_rec[i])!='*') //space ' ' <<<<<<<<<<<<<<<<<<<<<<<<<<<<<
	{
		if(i>15)
		{
			return 0; // frame error
		}
		str[i]=frame_rec[i];
		i++;
	}
	str[i]=0;
	LCD_WriteString(str);// <<<<<<<<<<<<<<<<<
	i++; //space <<<<<<<<<<<<<<<<<<<<<<<<< space >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	while(frame_rec[i]!=0)
	{
		if(i>15)
		{
			return 0; // frame error
		}
		if( (frame_rec[i]>='0') && (frame_rec[i]<='9') )
		{
			num[j]=frame_rec[i];
			i++;
			j++;
		}
		else if(frame_rec[i]>='A'&&frame_rec[i]<='z')
		{
			num[j]=frame_rec[i];
			i++;
			j++;
			return 2; // char for color
		}
		else
		{
			return 0; // frame error
		}
	}
	num[j]='*'; // indaix for end of num
	return 1; // frame is good & seperation is done
}

u8 Read_Task (u8*str)
{
	static u8 i;
	u8 task_status;
	for(i=0;i<20; i++)
	{
		task_status=String_Compare(str,i);
		if(1==task_status)
		{
			return i;
		}
	}
	return 255; // for not found
}

Frame_error_t Read_Frame(u8*frame_rec)
{
	//u8 i=0;
	//u8 errror;
	u8 str[10];
	u8 num[3];
	u8 fr_error=25;
	u8 ordered_task;
	u8 num_of_order;
	
	
	
	fr_error=Seperate_string_num(frame_rec,num,str);  // done 
	if(0==fr_error)
	{
		return FRAME_ERROR; 
	}
	ordered_task=Read_Task(str); // task 
	if(255==ordered_task)
	{
		return NOT_FOUND_TASK;
	}
	if(fr_error==1) // for convert to number
	{
		num_of_order=convert_str_to_num(num);
	}
	else if(2==fr_error) // char for color
	{
		num_of_order=num[0];
	}
	
	//LCD_WriteNumber(ordered_task);
	
	
	tasks[ordered_task].fptr(num_of_order); // call func. 
	//NEGARAB LED ON NE3MEL WAHDA KEDA M3 EL STRUCT
	
	
	
}


void Smart_Home_Init (void)
{
	
}

void Smart_Home_Runnable (void)
{
	UART_ReceiveString(frame_rec);
	Read_Frame(frame_rec);
}

// range num 