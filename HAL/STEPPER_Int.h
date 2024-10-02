/*
 * STEPPER_Int.h
 *
 * Created: 12/13/2023 10:02:35 AM
 *  Author: Magic
 */ 


#ifndef STEPPER_INT_H_
#define STEPPER_INT_H_

void STEPPER_Bipoler_CW (void);// 4 step
void STEPPER_Bipoler_CCW (void);

void Bi_polar_quadrant (void);
void Bi_polar_three_quartes_of_cycle (void);
void Bi_polar_halfcycle (void);
void Bi_polar_fullcycle (void);


void STEPPER_Unipoler_CCW (void);
void STEPPER_Unipoler_CW (void);

void STEPPER_Unipoler_CW_HS (void); //8 step (half step) == 4 step full step >> 8 step ( half step is best -->> increase reselution )
void STEPPER_Unipoler_CCW_HS (void);



#endif /* STEPPER_INT_H_ */