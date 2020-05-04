#include<avr/io.h>
#include<util/delay.h>
#define DELAY 500

int PIN[12]= {PD2,PD3,PD4,PD5,PD6,PD7,PB0,PB1,PB2,PB3,PB4,PB5};
void initializationAsOutput(){

    //Port D data direction register set as OUTPUT
    DDRD=0xFF;
    //Port B data direction register set as OUTPUT
    DDRB=0xFF;
}


