#include <stdlib.h>
#include <stdio.h>

int multiplica(int a, int b){
    if(b == 1) return a;
    else return a + multiplica(a, b-1);
}

void main(){
    int mult = 0, fator = 0;
    printf("digite um numero a ser o multiplicando: ");
    scanf("%d", &mult);
    printf("digite um numero a ser o fator multiplicador: ");
    scanf("%d", &fator);
    int vezes = multiplica(mult,fator);
    printf("%d\n", vezes);
}