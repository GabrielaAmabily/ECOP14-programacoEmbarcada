// corrigido 

#include <stdlib.h>
#include <stdio.h>

int main(){
    int tipo;
    float area;
    float preco;
    float descontoArea = 0;
    float descontoPreco = 0;

    printf("Tipo de Area: ");
    scanf("%d", &tipo);
    printf("Area: ");
    scanf("%f", &area);
    
    switch(tipo){
        case 1:
            preco = area/1000 * 50;
            break;
        case 2:
            preco = area/1000 * 100;
            break;
        case 3:
            preco = area/1000 * 150;
            break;
        case 4:
            preco = area/1000 * 250;
            break;     
    }
     printf("preco %.2f \n", preco);
   
    if(area > 2000){
        descontoArea = preco * 0.05;
        preco = (preco - descontoArea);
        printf("desc area %.2f \n", descontoArea);
    }
    
    if(preco > 750){
        descontoPreco = (preco - 750) * 0.1;
        printf("desc preco %.2f \n", descontoPreco);
         preco = (preco - descontoPreco);
    }

    printf("R$ %.2f", preco);
}
