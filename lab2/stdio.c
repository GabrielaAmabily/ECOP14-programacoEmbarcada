#include "stdio.h"
#include "lcd.h"

void printf(char msg[32]) {
    char i;
    int count = 1;
    
    lcdCommand(0x80);
    for (i = 0; i < 31; i++) {
        if(msg[i]=='\0'){
            break;
        }
        if(msg[i]=='\n'){
            lcdCommand(0xC0);
            count = 0;
            i++;
        }
        if(count && i > 16)
            lcdCommand(0xC0);
            
        lcdData(msg[i]);
      
    }
    for (;;);
}