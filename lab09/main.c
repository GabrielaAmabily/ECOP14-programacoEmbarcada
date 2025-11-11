#include "config.h"
#include "pic18f4520.h"
#include "ssd.h"
#include "keypad.h"

void main(void) {
    unsigned char tecla, tecla1 , ultimaTecla = 0;
    unsigned char unidades = 0, dezenas = 0;

    ssdInit();
    kpInit();

    for (;;) {
        ssdUpdate();
        kpDebounce();
        tecla1 = kpRead1(); //mostrar
        ssdDigit(tecla1, 0); //mostrar
        
        
        tecla = kpRead(); //mostrar
        //(BitTst(tecla, 1))
        
        if (tecla != 0 && ultimaTecla == 0) {
            // tira a contagem contínua
            unidades++;
            if (unidades == 10) {
                unidades = 0;
                dezenas++;
            }
            if (dezenas == 10) {
                dezenas = 0;
            }
        }

        ultimaTecla = tecla; // guarda estado anterior

        ssdDigit(unidades, 2);
        ssdDigit(dezenas, 3);
        
        
    }
}
