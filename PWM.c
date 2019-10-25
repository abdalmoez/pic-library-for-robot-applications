#include "Basic.c

void main() {
   
   ADC_Init();
   pinMode(&PORTA,B0,INPUT);

   PWM1_Init(5000);
   PWM2_Init(5000);
   PWM1_Start();
   PWM2_Start();
   while(1){
	   // 0 -> Duty: 0%
	   // 255 -> Duty: 100%
      PWM1_Set_Duty(ADC_Read(0) / 4);
      PWM2_Set_Duty( (  1023 - ADC_Read(0)  ) / 4);
   }
   PWM1_Stop();
   PWM2_Stop();
}

