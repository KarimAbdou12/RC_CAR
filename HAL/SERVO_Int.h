

#ifndef SERVO_INT_H_
#define SERVO_INT_H_


void Servo_SetAngle(u8 angle);

void servo_timer0_init(void);
void servo_timer0_Runnable(u8 position);
//extern u8 ch;

#define _0_position 2
#define _90_position 5
#define _180_position 8

//void stepper_timer0_normal_mode (void);

#endif /* SERVO_INT_H_ */