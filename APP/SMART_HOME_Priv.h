



#ifndef SMART_HOME_PRIV_H_
#define SMART_HOME_PRIV_H_

u8 Read_Task (u8*str);
u8 Seperate_string_num(u8*frame_rec,u8*num,u8*str);
u8 String_Compare (u8*str,u8 ind);
u8 convert_str_to_num(u8*str);
Frame_error_t Read_Frame(u8*frame_rec);

void SH_ROOMLED_ON (u32 led);
void SH_ROOMLED_OFF (u32 led);
void SH_OPEN_DOOR (u32 motor);
void SH_CLOSE_DOOR (u32 motor);
void SH_OPEN_FAN (u32 motor);
void SH_CLOSE_FAN (u32 motor);
void RGB_ON_DIO (u32 color);
void RGB_ON_PWM (u32 color);
void RGB_OFF_DIO(u32 color);
void RGB_OFF_PWM (void);
void SERVO_CONFG (u32 position);
void Stepper_Moving (u32 position);


#endif /* SMART_HOME_PRIV_H_ */