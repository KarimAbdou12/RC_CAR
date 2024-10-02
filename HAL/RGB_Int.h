/*
 * RGB_Int.h
 *
 * Created: 3/16/2024 9:42:51 PM
 *  Author: Magic
 */ 


#ifndef RGB_INT_H_
#define RGB_INT_H_

extern u8 RGB_Colors[12][3];
void RGB_Init (void);
void Moving_All_Color(void);
void RGB_COLOR (u8 ind);
void RGB_OFF (void);
void RGB_DIO_PIN (u8 rgb_color);
void RGB_OFF (void);

#endif /* RGB_INT_H_ */