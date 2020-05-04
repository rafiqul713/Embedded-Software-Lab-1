#define F_CPU 16000000UL // set frequency 
#include<avr/io.h>
#include<util/delay.h>
#include "initialization.h"

int main(){
    int i;
    initializationAsOutput();

    while(1){
        for(i=0;i<6;i++){
            //Port D pin[i] High
            PORTD|= (1<<PIN[i]);
            _delay_ms(DELAY);
        }
        for(i=6;i<12;i++){
            //Port B pin[i] High
            PORTB|= (1<<PIN[i]);
            _delay_ms(DELAY);
        }

        //Port B as low
        for(i=11;i>=6;i--){
            PORTB &= ~(1<<PIN[i]);
            _delay_ms(DELAY);
        }
        //Port D as low
        for(i=5;i>=0;i--){
            PORTD &= ~(1<<PIN[i]);
            _delay_ms(DELAY);
        }

    }




}
