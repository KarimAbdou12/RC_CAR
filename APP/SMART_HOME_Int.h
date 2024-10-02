

#ifndef SMART_HOME_INT_H_
#define SMART_HOME_INT_H_

extern u8*frame_rec[20];

typedef struct  
{
	u8 *str;
	void (*fptr)(u32);
	
}Task_t;


typedef enum{
	NOT_FOUND_TASK,
	FRAME_ERROR,
	WELL
}Frame_error_t;


void Smart_Home_Init (void);
void Smart_Home_Runnable (void);



u8 String_Compare (u8*str,u8 ind);


#endif /* SMART_HOME_INT_H_ */