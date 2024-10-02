/*
 * PUSH_BUTTON_Cfg.c
 *
 * Created: 9/27/2024 5:31:35 PM
 *  Author: Karim Abdou
 */ 

#include "StdTypes.h"
#include "DIO_Int.h"
#include "PUSH_BUTTONS_Int.h"
#include "PUSH_BUTTONS_Cfg.h"
#include "PUSH_BUTTONS_Priv.h"


const BUTTON_t ButtonsArray[NUM_OF_BUTTONS][1]={{PIND2},{PIND3},{PIND4},{PIND5}};