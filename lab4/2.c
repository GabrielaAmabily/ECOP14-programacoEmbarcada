#include <xc.h>
#include "pic18f4520.h"

#define _XTAL_FREQ 8000000UL

void main(void) {
    TRISD = 0x00; // LEDs na porta D
    PORTD = 0x00;

    while (1) {
        for (int i = 0; i < 8; i++) {
            BitSet(PORTD, i);   // acende LED i
            __delay_ms(2000);   // espera 2s
        }

        PORTD = 0x00;           // apaga todos
        __delay_ms(2000);
    }
}
