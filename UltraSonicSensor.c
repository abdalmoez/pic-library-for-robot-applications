#include "Basic.h"

  unsigned long a;
  char txt[7];

void main()
{
  UART1_Init(9600);
  Delay_Ms(100);
  
  pinMode(&PORTB,B4);         //RB4 as Input PIN (ECHO)


  while(1)
  {
    a = UltraSonicSensor_Read(&PORTB,B0,&PORTB,B4);
    if(a>=2 && a<=400)          //Check whether the result is valid or not
    {
      IntToStr(a,txt);
      UART1_Write_Text(txt);
    }
    else
    {
      UART1_Write_Text("  0");
    }
    Delay_ms(400);
  }
}