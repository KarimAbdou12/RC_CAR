


#ifndef UART_SERVICE_H_
#define UART_SERVICE_H_


typedef union{
	u8 arr[7];
	struct{
		u8 LedIdx;
		u8 Red;
		u8 Green;
		u8 Blue;
		u8 Intensity;
		u16 Sum;
	};
	
}Frame_t;
/*
typedef enum{
	OK,
	SUM_ERROR,
	IN_PROGRESS
}BCMerror_t;*/



/* synch function  blocking*/
void UART_SendString(u8*str);
void UART_ReceiveString(u8*str);
void UART_SendStringAsynch(u8*str);
void UART_ReceiveStringAsynch(u8*str);
void UART_SendNumber(u32 num);


#endif /* UART_SERVICE_H_ */