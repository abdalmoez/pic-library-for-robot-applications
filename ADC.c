#include "Basic.h"

void main() {
   pinMode(&PORTB,B5,OUTPUT);
   pinMode(&PORTA,B0,INPUT);

   while(1){
     setBit(&PORTB,B5);
     Vdelay_ms(50 + ADC_Read(0));
     clearBit(&PORTB,B5);
     Vdelay_ms(50 + ADC_Read(0));
   }

}