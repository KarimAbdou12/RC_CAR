


#ifndef LEDS_INT_H_
#define LEDS_INT_H_


typedef enum
{
	_1st_led,
	_2nd_led,
	_3rd_led,
	_4th_led,
	
}Led_num_t;


#define _1st_led  PINC5
#define _2nd_led  PINC6
#define _3rd_led  PINC7
#define _4th_led  PINC3



void LED_On (Led_num_t num);
void LED_Off (Led_num_t num);



#endif /* LEDS_INT_H_ */