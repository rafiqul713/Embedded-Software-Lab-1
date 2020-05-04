#include<avr/io.h>
#include<util/delay.h>


void portInitialization(){

    //Port D data direction register set as OUTPUT
    DDRD=0xFF;
    //Port B data direction register set as OUTPUT
    DDRB=0xFF;
}

