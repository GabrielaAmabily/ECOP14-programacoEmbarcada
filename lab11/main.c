#include "pic18f4520.h"
#include "config.h"
#include "ssd.h"
#include "timer.h"
#include "keypad.h"
#include "adc.h"

char flag;
char tecla = 0;
unsigned int ADvalor = 0;

void Int(void) __interrupt() {

    // Timer
    if (BitTst(INTCON, 2)) {
        timerReset(5000);
        BitClr(INTCON, 2);
        flag = 1;
    }

    // Interrupção AD
    if (BitTst(PIR1, 6)) {
        ADvalor  = ADRESH;
        ADvalor <<= 8;
        ADvalor |= ADRESL;
        BitClr(PIR1, 6);
    }
}

void main(void){
    unsigned char k;
    ssdInit();
    kpInit();
    adcInit();
    timerInit();

    BitClr(RCON, 7);
    BitSet(INTCON, 7);
    BitSet(INTCON, 6);
    BitSet(INTCON, 5);
    BitSet(PIE1, 6);   // habilita interrupção AD

    for (;;) {
        ssdUpdate();
        kpDebounce();
        //???????
        k = kpRead();
        //if(k != 0){tecla = k;}
        
        ssdDigit(k,0);

        ssdDigit((ADvalor / 100) % 10, 1);
        ssdDigit((ADvalor / 10) % 10, 2);
        ssdDigit(ADvalor % 10, 3);

        //conversao AD
        ADCON0 |= 0x02;

        while (!flag);
        flag = 0;
    }
}
