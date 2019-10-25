#include "Basic.h"

void main() {

   ADC_AS_Digital();
   pinMode(&PORTA,0,INPUT);
   pinMode(&PORTA,1,OUTPUT);
   
   while(1){
     if (RA0_bit)
       setBit(&PORTA,B1);
     Delay_Ms(500);
     clearBit(&PORTA,B1);
     Delay_Ms(500);
   }

}