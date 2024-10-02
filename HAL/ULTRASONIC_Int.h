

#ifndef ULTRASONIC_INT_H_
#define ULTRASONIC_INT_H_

typedef enum{
	ULTRA1_TR,
	ULTRA2_TR,
	ULTRA3_TR,
	ULTRA4_TR
	}Ultra_TR_t;

#define ULTRA1_TR  PINC0
#define ULTRA2_TR  PINC1
#define ULTRA3_TR  PINC2
#define ULTRA4_TR  PINC3
 
typedef enum
 {
	 Ultrasonic1=1,
	 Ultrasonic2,
	 Ultrasonic3,
	 Ultrasonic4
}Ultra_num_t;


extern volatile u8 ULTRA_Flag;
extern volatile u16 t1,t2;
extern u16 distance;

void ULTRASONIC_Init(void);

void ULTRASONIC_Runnable(void);

u16 ULTRASONIC_Getdistance(u8 ultra);

void ULTRASONIC_GetdistanceAll(u16* distanceAll);

u16 ultrasonic_kit (void);


#endif /* ULTRASONIC_INT_H_ */