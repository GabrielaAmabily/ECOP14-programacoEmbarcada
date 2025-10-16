#include "config.h"
#include "pic18f4520.h"
#include "lcd.h"
#include "keypad.h"

void lcdPosition(unsigned char linha, unsigned char coluna) {
    unsigned char pos;

    if (linha == 0) {
        pos = 0x80 + coluna;
    }
    if (linha == 1) {
        pos = 0xC0 + coluna;
    }
    lcdCommand(pos);
}

void main(void) {
    unsigned long int cont = 0;
    unsigned int tecla = 16; //adicionei
    lcdInit();
    kpInit(); //adicionei
    lcdCommand(0x80); //adicionei
    for (;;) {
        cont++;
        lcdPosition(1, 0);
        lcdData((((cont / 360000) % 24) / 10) + 48);
        lcdData((((cont / 360000) % 24) % 10) + 48);
        lcdData(':');
        lcdData((cont / 60000) % 6 + 48);
        lcdData((cont / 6000) % 10 + 48);
        lcdData(':');
        lcdData((cont / 1000) % 6 + 48);
        lcdData((cont / 100) % 10 + 48);
        //ciclo de 10ms +-.

        //ajustar horario
        kpDebounce();
        if (kpRead() != tecla) {
            tecla = kpRead();
            if (BitTst(tecla, 2)) cont += 100;
            if (BitTst(tecla, 3)) cont -= 100;
            if (BitTst(tecla, 4)) cont += 6000;
            if (BitTst(tecla, 5)) cont -= 6000;
            if (BitTst(tecla, 6)) cont += 360000;
            if (BitTst(tecla, 7)) cont -= 360000;
            
        }
    }
}