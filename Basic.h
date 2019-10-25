//BASIC.H   COPYRIGHT ABDALMOEZ 2016
#ifndef BASIC
#define BASIC


#define INPUT 1
#define OUTPUT 0
#define HIGH 1
#define LOW 0
#define ADC_AS_Digital() ADCON1 = 0b00000110


void pinMode(unsigned short *port,
     unsigned short pin,unsigned short IO);
void setBit(unsigned short *port,
     unsigned short pin);
void clearBit(unsigned short *port,
     unsigned short pin);
void updatePort(unsigned short *port,
     unsigned short value);
unsigned short readPort(unsigned short volatile *port);

unsigned int UltraSonicSensor_Read(unsigned short *porttrig, const char pintrig,
     unsigned short *portecho, const char pinecho);//REQUIREMENT;PIN (ECHO) as Input
#endif

//EOF BASIC.H