#include <stdlib.h>
#include <stdio.h>

int dividir(int a, int b){
    if(b == 1) return 1;
    else if(a < b) return 0;
    else return 1 + dividir(a-b, b);
}

void main(){

    int div = 0, fator = 0;
    printf("digite um numero a ser o dividendo: ");
    scanf("%d", &div);
    printf("digite um numero a ser o fator divisor: ");
    scanf("%d", &fator);
    if (fator > 0)
    {
        int n = dividir(div,fator);
        printf("%d\n", n);
    }else
    {
        printf("\n*****\nvalores inválidos\n*****\n\n");
    }
    
    
}