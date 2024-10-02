

#include "StdTypes.h"
#include "UART_Int.h"
#include "UART_Service.h"

#include "LCD_Int.h"


void UART_SendString(u8*str) // send for this func. it will send this string ( synsch. blocking ) 
{
	u8 i;
	for (i=0;str[i];i++)
	{
		UART_Send(str[i]);
	}
	
}

void UART_ReceiveString(u8*str) // you will send str fir it & it will full it ( synch. blocking )
{
	u8 i=0;
	str[i]=UART_Receive();
	for (;str[i]!=13;)
	{
		i++;
		str[i]=UART_Receive();
	}
	str[i]=0;
	//LCD_WriteString("done ok");
}

void UART_SendNumber(u32 num) // send nom. for this func. it will send this nom. ( synsch. blocking ) 
{
	u8*p=&num;
	UART_Send(p[0]);
	UART_Send(p[1]);
	UART_Send(p[2]);
	UART_Send(p[3]);
	/*
	UART_Send((u8)num);
	UART_Send((u8)(num>>8));
	UART_Send((u8)(num>>16));
	UART_Send((u8)(num>>24));
	*/
}



/********************************************************/

static void TX_Func(void);
u8*TX_Str;
u8*RX_Str;
static flag=1;

// send asynch.
void UART_SendStringAsynch(u8*str)
{
	if(flag==1) 
	{
		TX_Str=str; // we put str in buffer
		UART_SendNoBlock(str[0]); // send 1st char 
		UART_TX_InterruptEnable(); // turn on interrupt
		UART_TX_SetCallBack(TX_Func); 
		flag=0;
	}	
}

static void TX_Func(void)
{
	static u8 i=1;
	
	if (TX_Str[i]) // cond. true if char it != zero
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
		flag=1;
	}
	
	
}


// receive asynch.
static void RX_Func(void);

void UART_ReceiveStringAsynch(u8*str) // you will send str fir it & it will full it ( asynch. noblocking )
{
	UART_RX_InterruptEnable(); // turn on interrrupt
	UART_RX_SetCallBack(RX_Func);
	RX_Str=str;
}

static void RX_Func(void)
{
	static u8 i;
	RX_Str[i]=UART_ReceiveNoBlock();
	i++;
}

/*
Frame_t frame;
Frame_t Dframe;
static u8 R_Flag;
static void RX_Func2 (void);
static u8 dataFlags[5];

void BCM_Init(void)// BASIC COMUNICATION MODULE
{
	UART_RX_InterruptEnable();
	UART_RX_SetCallBack(RX_Func2);
	
}

void BCM_Runnable(void)
{
	u16 sumCal=0;
	if (flag==1)
	{
		
		flag=0;
		for(u8 i=0;i<5;i++)
		{
			sumCal+=Dframe.arr[i];
			dataFlags[i]=1;
		}
		if(Dframe.Sum==sumCal)
		{
			R_Flag=1;
		}
		else
		{
			R_Flag=0;
		}
	}
	
}


BCMerror_t BCM_GetIntensity(u8*pintensity)
{
	BCMerror_t error=OK;
	if(dataFlags[4]==1)
	{
		if (R_Flag==1)
		{
			*pintensity=Dframe.Intensity;
		}
		else if (R_Flag==0)
		{
			error=SUM_ERROR;
		}
		dataFlags[4]=0;
	}
	else
	{
		error=IN_PROGRESS;
	}
	
	
	return error;
}

static void RX_Func2 (void)
{
	static u8 i;
	frame.arr[i]=UART_ReceiveNoBlock();
	i++;
	if(i==7)
	{
		for (u8 j=0;j<70;j++)
		{
			Dframe.arr[j]=frame.arr[j];
		}
		i=0;
		flag=1;
	}
	
}*/