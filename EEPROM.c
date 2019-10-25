
void main(){

   EEPROM_Write(0x50,5);
   Delay_Ms(20);
   if ( EEPROM_Read(0x50) == 5)
     setBit(&PORTB,B5);
   else  setBit(&PORTB,B4);

}

