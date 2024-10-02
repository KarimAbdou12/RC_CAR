/*
 * KEYPAD_Cfg.h
 *
 * Created: 2/4/2024 6:31:54 PM
 *  Author: Magic
 */ 


#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#define  ROW   4
#define  COL   4

#define  FIRST_OUTPUT  PINB4
#define  FIRST_INPUT   PIND2

#define  NO_KEY   't'

#ifdef KEYPAD_PROG

u8 KeysArray[ROW][COL]={{'7','8','9','/'},
{'4','5','6','*'},
{'1','2','3','-'},
{'c','0','=','+'}
};

#endif


#endif /* KEYPAD_CFG_H_ */