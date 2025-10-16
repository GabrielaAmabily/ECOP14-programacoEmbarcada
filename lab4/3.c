#include <xc.h>
#include "pic18f4520.h"

#define _XTAL_FREQ 8000000UL

void delay_ms(unsigned int ms) {
    while(ms--) __delay_ms(1);
}

void main(void) {
    // Configuração inicial
    TRISA = 0x00;
    TRISD = 0x00;
    TRISE = 0x00;

    BitClr(INTCON2, 7); // ativa pull-up
    ADCON1 = 0x0E;

    TRISB = 0x30; // RB4 e RB5 como entrada
    PORTB = 0x00;

    // Ativa 1º display (exemplo RA5)
    BitSet(PORTA, 5);

    while (1) {
        // Tecla A (RB4)
        if (!BitTst(PORTB, 4)) {
            delay_ms(20); // debounce
            if (!BitTst(PORTB, 4)) {
                PORTD = 0x77; // mostra 'A'
                while(!BitTst(PORTB,4)); // espera soltar
                delay_ms(20);
            }
        }

        // Tecla B (RB5)
        if (!BitTst(PORTB, 5)) {
            delay_ms(20);
            if (!BitTst(PORTB, 5)) {
                PORTD = 0x6F; // mostra '9'
                while(!BitTst(PORTB,5));
                delay_ms(20);
            }
        }
    }
}
