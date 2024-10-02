

#include "StdTypes.h"
#include "DIO_Int.h"
#include "MOTOR_Int.h"
#include "MOTOR_Cfg.h"
#include "MOTOR_Priv.h"


void MOTOR_Init(void)
{
	// future use
}


void MOTOR_Stop(MOTOR_t motor)
{	
	for(u8 x=0;x<NUM_OF_MOTORS;x++)
	{
		if(x==motor)
		{
			DIO_WritePin(MOTOR_Array[x][0],LOW);
			DIO_WritePin(MOTOR_Array[x][1],LOW);
		}
	}
	
}

void MOTOR_CW(MOTOR_t motor)
{
	for(u8 x=0;x<NUM_OF_MOTORS;x++)
	{
		if(x==motor)
		{
			DIO_WritePin(MOTOR_Array[x][0],HIGH);
			DIO_WritePin(MOTOR_Array[x][1],LOW);
		}
	}
}

void MOTOR_CCW(MOTOR_t motor)
{
	for(u8 x=0;x<NUM_OF_MOTORS;x++)
	{
		if(x==motor)
		{
			DIO_WritePin(MOTOR_Array[x][0],LOW);
			DIO_WritePin(MOTOR_Array[x][1],HIGH);
		}
	}
}
