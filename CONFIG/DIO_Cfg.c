/*
 * DIO_Cfg.c
 *
 * Created: 12/9/2023 6:28:40 AM
 *  Author: Magic
 */ 


#include "StdTypes.h"
#include "DIO_Int.h"
#include "DIO_Cfg.h"

/*========================================
 >> DON'T USE CONFG. IN #INCLUDE IN ANY FILE 
 >> Don't make func. in confg. file

==========================================*/


// >> edit status for pin 
// >> most popular config. array & struct

// global array


	/* OUTPUT,INFREE,INPULL*/ 
const DIO_PinStatus_t DIO_PinsStatusArray[TOTAL_PINS]={
	OUTPUT,      /* Port A Pin 0 ADC0*/
	OUTPUT,      /* Port A Pin 1 ADC1*/
	OUTPUT,      /* Port A Pin 2 */
	OUTPUT,      /* Port A Pin 3 */
	OUTPUT,      /* Port A Pin 4 */
	OUTPUT,      /* Port A Pin 5 */
	OUTPUT,      /* Port A Pin 6 */
	OUTPUT,      /* Port A Pin 7 ADC7*/
	OUTPUT,      /* Port B Pin 0   / */
	OUTPUT,      /* Port B Pin 1   /*/
	OUTPUT,		 /* Port B Pin 2 / INT2*///INPULL
	OUTPUT,		 /* Port B Pin 3   /OC0*/
	OUTPUT,		 /* Port B Pin 4 /ss*/
	OUTPUT,		 /* Port B Pin 5 //mosi*/
	OUTPUT,		 /* Port B Pin 6 /miso*/
	OUTPUT,		 /* Port B Pin 7 clk*/
	OUTPUT,		 /* Port C Pin 0 */
	OUTPUT,		 /* Port C Pin 1 */
	OUTPUT,		 /* Port C Pin 2 */
	OUTPUT,		 /* Port C Pin 3 */
	OUTPUT,		 /* Port C Pin 4 */
	OUTPUT,		 /* Port C Pin 5 */
	OUTPUT,		 /* Port C Pin 6 */
	OUTPUT,		 /* Port C Pin 7 */
	INPULL,		 /* Port D Pin 0 */
	INPULL,		 /* Port D Pin 1 */
    INPULL,      /* Port D Pin 2 /INT0*///INPULL
	INPULL,      /* Port D Pin 3 / INT1 *///INPULL
	INPULL,		 /* Port D Pin 4  OC1B*/
	INPULL,		 /* Port D Pin 5 OC1A*/
	INPULL,		 /* Port D Pin 6 /   ICP*///INFREE
	INPULL		 /* Port D Pin 7 */
};