#include "pic18f4520.h"
#include "config.h"
#include "lcd.h"
#include "rtc.h"
#include "serial.h"

void main(void) {
    float i;
    unsigned char dadoSerial;
    unsigned char comando_ativo;
    unsigned char digitos[6];
    unsigned char cont_digitos = 0;

    //Inicializacoes
    lcdInit();
    serialInit();
    rtcInit();

    //inicia com valor de data e hora 
    rtcPutSeconds(0);
    rtcPutMinutes(0);
    rtcPutHours(0);
    rtcPutDate(20);
    rtcPutMonth(10);
    rtcPutYear(25);

    for (;;) {
        dadoSerial = serialRead();
        if (dadoSerial != 0) { //Se dado e valido
            if (dadoSerial == 'D' || dadoSerial == 'H') {
                comando_ativo = dadoSerial;
                cont_digitos = 0;
            } else {
                digitos[cont_digitos] = dadoSerial;
                cont_digitos++;

                if (cont_digitos == 6) {

                    unsigned char v1, v2, v3;
                    v1 = ((((digitos[0])/ 10) % 10) + 48) * 10 + (digitos[1])/ 10) % 10) + 48); 
                    v2 = ((((digitos[2])/ 10) % 10) + 48) * 10 + (digitos[3])/ 10) % 10) + 48); 
                    v3 = ((((digitos[4])/ 10) % 10) + 48) * 10 + (digitos[5])/ 10) % 10) + 48); 
                    if (comando_ativo == 'H') {
                        rtcPutHours( v1 ); //hh
                        rtcPutMinutes(v2); // mm
                        rtcPutSeconds(v3); // ss
                    } else if (comando_ativo == 'D') {
                        rtcPutDate(v1); // dd
                        rtcPutMonth(v2); // mm
                        rtcPutYear(v3); // yy
                    }
                }
                // Reinicia 
                   cont_digitos = 0;
            }
        }
        //Le horario do RTC
        lcdCommand(0x80);
        lcdData(((rtcGetHours() / 10) % 10) + 48);
        lcdData((rtcGetHours() % 10) + 48);
        lcdData(':');
        lcdData(((rtcGetMinutes() / 10) % 10) + 48);
        lcdData((rtcGetMinutes() % 10) + 48);
        lcdData(':');
        lcdData(((rtcGetSeconds() / 10) % 10) + 48);
        lcdData((rtcGetSeconds() % 10) + 48);

        lcdCommand(0xC0);
        lcdData(((rtcGetDate() / 10) % 10) + 48);
        lcdData((rtcGetDate() % 10) + 48);
        lcdData(':');
        lcdData(((rtcGetMonth() / 10) % 10) + 48);
        lcdData((rtcGetMonth() % 10) + 48);
        lcdData(':');
        lcdData(((rtcGetYear() / 10) % 10) + 48);
        lcdData((rtcGetYear() % 10) + 48);

        for (i = 0; i < 1000; i++);
    }



}

