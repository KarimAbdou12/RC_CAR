/*
 * Sensor_Int.h
 *
 * Created: 2/14/2024 11:42:28 AM
 *  Author: Magic
 */ 


#ifndef SENSOR_INT_H_
#define SENSOR_INT_H_


u16 TEMP_Read(void);
u8 POT_Read(void);
u16 Pressure_Read(void);
void pressur_Runnable (void);


#endif /* SENSOR_INT_H_ */