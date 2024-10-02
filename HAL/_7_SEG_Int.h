/*
 * _7_SEG_MLX_Int.h
 *
 * Created: 9/19/2024 1:31:48 AM
 *  Author: Magic
 */ 


#ifndef _7_SEG_MLX_INT_H_
#define _7_SEG_MLX_INT_H_

#define ENABLE_1ST_DIGIT	(u8)0
#define ENABLE_2ND_DIGIT	(u8)1

#define SEGMENT_DISPLAY_PORT PORTD



void _7_SEG_2DIG_DISPLAY (u8 num);//Common Cathode 
/* 2 BCD CONNECTED IN THE SAME PORT */
void _7_SEG_DIS_BCD (u8 num);

#endif /* _7_SEG_MLX_INT_H_ */