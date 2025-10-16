#include <xc.h>
#include "pic18f4520.h"

#define _XTAL_FREQ 8000000UL

void main(void) {
    // Configuração inicial
    TRISA = 0x00;  // saída
    TRISD = 0x00;  // saída (segmentos do display)
    TRISE = 0x00;  // saída
    BitClr(INTCON2, 7); // liga pull-up
    ADCON1 = 0x0E;      // portas digitais

    // Ativa 1º display (exemplo: RA5)
    BitSet(PORTA, 5);

    while (1) {
        PORTD = 0x4F; // número 3
        __delay_ms(1000);

        PORTD = 0x5B; // número 2
        __delay_ms(1000);

        PORTD = 0x6F; // número 9
        __delay_ms(1000);
    }
}
