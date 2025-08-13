#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Tabela ASCII\n");

    //moldura de cima
    printf("%c", 201);
    for (int i = 0; i < 114; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 187);
    printf("\n");

    ////////////tabela///////////
    for(int i=48; i<=247; i+=10){
        printf("%c", 186);//moldura
        for(int j =0; j<10; j++){
            printf("    %3d = %c", i+j, i);
        }
        printf("    %c", 186);//moldura
        printf("\n");
    }

    //moldura de baixo
    printf("%c", 200);
    for (int i = 0; i < 114; i++)
    {
        printf("%c", 205);
    }
    printf("%c", 188);
    printf("\n");

    return 0; 
}
