#include "config.h"
#include "pic18f4520.h"

void main(void) {

    TRISA = 0x00; //configura porta A como saída
    TRISD = 0x00; //configura porta D como saída
    TRISE = 0x00; //configura porta E como saída
    BitClr(INTCON2, 7); //liga pull up
    ADCON1 = 0x0E; //config AD
    float i; // i para for
    BitSet(PORTA, 5); //ativa o 1o display
    BitSet(PORTA, 2); //ativa o 2o display
    BitSet(PORTE, 0); //ativa o 3o display
    BitSet(PORTE, 2); //ativa o 4o display


    //parte1 
    /*
    BitSet(PORTD, 0); //liga o 1o led
    BitSet(PORTD, 1); //liga o 2o led
    BitSet(PORTD, 2); //desliga o 3o led
    BitSet(PORTD, 3);
    BitClr(PORTD, 4); 
    BitClr(PORTD, 5); 
    BitSet(PORTD, 6); 
    BitClr(PORTD, 7); */


    //parte 1.2
    /*
    for (;;) {
        for (i = 0; i < 8000; i++) {
            PORTD = 0x5B;
        }
        for (i = 0; i < 8000; i++) {
            PORTD = 0x6F;
        }
    }*/



    //parte 2
    /*
    for (;;) {
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 0);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 1);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 2);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 3);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 4);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 5);
        }
        for (i = 0; i < 8000; i++) {
            BitSet(PORTD, 6);
        }
        for (i = 0; i < 8000; i++) {
            PORTD = 0x00;
        }
    }*/


    //parte 3 
    BitClr(INTCON2, 7); //liga pull up
    ADCON1 = 0x0E; //config AD
    TRISB = 0xFE; //config porta para ler teclas A e B
    PORTB = 0x00; //config porta para ler teclas A e B


    for (;;) {
        if (!BitTst(PORTB, 4)) {
            PORTD = 0x77; // mostra 'A'
        }
        else if (!BitTst(PORTB, 5)) {
            PORTD = 0x6F; // mostra '9'
        }
        else{
            PORTD = 0x00;
        }
    }


}
