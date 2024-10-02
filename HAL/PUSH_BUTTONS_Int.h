/*
 * PUSH_BUTTONS_Int.h
 *
 * Created: 9/27/2024 5:28:03 PM
 *  Author: Karim Abdou
 */ 


#ifndef PUSH_BUTTONS_INT_H_
#define PUSH_BUTTONS_INT_H_


typedef enum 
{
	OFF,
	ON	
}BUTTON_MODE_t;

typedef enum
{
	B1=0,
	B2,
	B3,
	B4,
	B5,
	B6,
	B7,
	B8,
	B9,
	B10
}BUTTON_t;



BUTTON_MODE_t Get_Buttton_Status (BUTTON_t button);
BUTTON_MODE_t Get_forward_Button (void);
BUTTON_MODE_t Get_Back_Button (void);
BUTTON_MODE_t Get_Left_Button (void);
BUTTON_MODE_t Get_Right_Button (void);


#endif /* PUSH_BUTTONS_INT_H_ */