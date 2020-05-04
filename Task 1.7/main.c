#define F_CPU 12000000UL
#include<avr/io.h>
#include<util/delay.h>
#include "initialization.h"
#include "UART_Handler.h"

#define DELAY_SLOW 1000
#define DELAY_FAST 100
void LED_Animation_Speed_Slow(int *);
void LED_Animation_Speed_FAST(int *);
void debug_message(char *);


int main(){
    uart_init();
    int PIN[12]= {PD2,PD3,PD4,PD5,PD6,PD7,PB0,PB1,PB2,PB3,PB4,PB5};
    portInitialization();
    unsigned char userInput;
    while(1){
        userInput=uart_receive();
        uart_transmission(userInput);

        switch(userInput){
            case 's':
                debug_message("This is Slow Animation\n\r");
                LED_Animation_Speed_Slow(PIN);
                break;
            case 'f':
                debug_message("This is Fast Animation\n\r");
                LED_Animation_Speed_FAST(PIN);
                break;

        }

    }

}


void debug_message(char *msg){
    int i=0;
    for(i=0;msg[i]!='\0';i++){
        uart_transmission(msg[i]);
    }
}

void LED_Animation_Speed_Slow(int *PIN){
    int i;
    for(i=0;i<6;i++){
            //Port D pin[i] High
            PORTD|= (1<<PIN[i]);
            _delay_ms(DELAY_SLOW);
        }
    for(i=6;i<12;i++){
            //Port B pin[i] High
            PORTB|= (1<<PIN[i]);
            _delay_ms(DELAY_SLOW);
        }

        //Port B as low
    for(i=11;i>=6;i--){
            PORTB &= ~(1<<PIN[i]);
            _delay_ms(DELAY_SLOW);
        }
        //Port D as low
    for(i=5;i>=0;i--){
            PORTD &= ~(1<<PIN[i]);
            _delay_ms(DELAY_SLOW);
    }

}

void LED_Animation_Speed_FAST(int *PIN){
    int i=0;
    for(i=0;i<6;i++){
            //Port D pin[i] High
            PORTD|= (1<<PIN[i]);
            _delay_ms(DELAY_FAST);
        }
    for(i=6;i<12;i++){
            //Port B pin[i] High
            PORTB|= (1<<PIN[i]);
            _delay_ms(DELAY_FAST);
        }

        //Port B as low
    for(i=11;i>=6;i--){
            PORTB &= ~(1<<PIN[i]);
            _delay_ms(DELAY_FAST);
        }
        //Port D as low
    for(i=5;i>=0;i--){
            PORTD &= ~(1<<PIN[i]);
            _delay_ms(DELAY_FAST);
    }

}
