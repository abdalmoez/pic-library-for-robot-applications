#include "Basic.h"

void main()
{
   pinMode(&PORTB,B0,OUTPUT);
   pinMode(&PORTB,B1,OUTPUT);
   while(1){
	setBit(&PORTB,B0);
	Delay_Ms(500);
	setBit(&PORTB,B1);
	Delay_Ms(500);
	clearBit(&PORTB,B0);
	Delay_Ms(500);
	clearBit(&PORTB,B1);
	Delay_Ms(500);
   }

}