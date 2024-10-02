

#include "StdTypes.h"
#include "PUSH_BUTTONS_Int.h"
#include "MOTOR_Int.h"
#include "MOTOR_Cfg.h"


void MOVE_Init(void)
{
	
}


void FORWARD(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
}

void BACK(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
}

void RIGHT(void)
{
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
	
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
	
}

void LEFT(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	
	MOTOR_Stop(M3);
	MOTOR_Stop(M4);
}

void CYCLE_RIGHT(void)
{
	MOTOR_CCW(M1);
	MOTOR_CCW(M2);
	MOTOR_CCW(M3);
	MOTOR_CCW(M4);
}

void CYCLE_LEFT(void)
{
	MOTOR_CW(M1);
	MOTOR_CW(M2);
	MOTOR_CW(M3);
	MOTOR_CW(M4);
}


void MOVE_Runnable(void)
{
	while(Get_forward_Button()==ON)
	{
		FORWARD();
	}
	while(Get_Back_Button()==ON)
	{
		BACK();
	}
	while(Get_Right_Button()==ON)
	{
		RIGHT();
	}
	while(Get_Left_Button()==ON)
	{
		LEFT();
	}
	MOTOR_Stop(M1);
	MOTOR_Stop(M2);
	MOTOR_Stop(M3);
	MOTOR_Stop(M4);
}
