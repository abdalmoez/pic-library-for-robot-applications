//BASIC.C   COPYRIGHT ABDALMOEZ 2016
#include "Basic.h"

void pinMode(unsigned short *port,
     unsigned short pin,unsigned short IO){
  if(port == &PORTA)
  {
    if (IO == OUTPUT)
       TRISA &= ~(1<<pin);
    else TRISA |= (1<<pin);
  } else if(port == &PORTB)
  {
    if (IO == OUTPUT)
       TRISB &= ~(1<<pin);
    else TRISB |= (1<<pin);
  } else if(port == &PORTC)
  {
    if (IO == OUTPUT)
       TRISC &= ~(1<<pin);
    else TRISC |= (1<<pin);
  }
}

unsigned short _PORTA = 0;
unsigned short _PORTB = 0;
unsigned short _PORTC = 0;

void setBit(unsigned short *port,
     unsigned short pin){
     if (port == &PORTA)
     {
        _PORTA |= (1<<pin) & (~TRISA);
        PORTA = _PORTA;
     }else if (port == &PORTB)
     {
        _PORTB |= (1<<pin) & (~TRISB);
        PORTB = _PORTB;
     }else if (port == &PORTC)
     {
        _PORTC |= (1<<pin) & (~TRISC);
        PORTC = _PORTC;
     }
}

void clearBit(unsigned short *port,
     unsigned short pin){
     if (port == &PORTA)
     {
        _PORTA &= ~(1<<pin);
        PORTA = _PORTA;
     }else if (port == &PORTB)
     {
        _PORTB &= ~(1<<pin);
        PORTB = _PORTB;
     }else if (port == &PORTC)
     {
        _PORTC &= ~(1<<pin);
        PORTC = _PORTC;
     }
}

void updatePort(unsigned short *port,unsigned short value)
{
     if (port == &PORTA)
     {
        _PORTA = value & (~TRISA);
        PORTA = _PORTA;
     }else if (port == &PORTB)
     {
        _PORTB = value & (~TRISB);
        PORTB = _PORTB;
     }else if (port == &PORTC)
     {
        _PORTC = value & (~TRISC);
        PORTC = _PORTC;
     }
}

unsigned short readPort(unsigned short *port)
{
     if (port == &PORTA)
        return (_PORTA & (~TRISA)) | (PORTA & TRISA);
     else if (port == &PORTB)
        return (_PORTB & (~TRISB)) | (PORTB & TRISB);
     else if (port == &PORTC)
        return (_PORTC & (~TRISC)) | (PORTC & TRISC);
}

unsigned int UltraSonicSensor_Read(unsigned short *porttrig,
         const char pintrig,unsigned short *portecho, const char pinecho)
{
    unsigned int a;
    T1CON = 0x10;               //Initialize Timer Module
    TMR1H = 0;                  //Sets the Initial Value of Timer
    TMR1L = 0;                  //Sets the Initial Value of Timer

    setBit(porttrig,pintrig);           //TRIGGER HIGH
    Delay_us(10);               //10uS Delay
    clearBit(porttrig,pintrig);         //TRIGGER LOW

    while(!((*portecho) & 1<<pinecho)); //Waiting for Echo
    T1CON.F0 = 1;                       //Timer Starts
    while((*portecho) & 1<<pinecho);    //Waiting for Echo
    T1CON.F0 = 0;                       //Timer Stops

    a = (TMR1L | (TMR1H<<8));           //Reads Timer Value
    a = a*8000/(58.82*__FOSC__);                //Converts Time to Distance 88,23(12Mhz)
    return a + 1;  //Calibration
}