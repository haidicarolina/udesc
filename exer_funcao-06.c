#include <stdio.h>
#include <string.h>

//Faça um programa que, dado dois números inteiros x e y, retorne o máximo divisor comum entre os
//números. Utilize uma função recursiva para realizar o cálculo do máximo divisor comum.

int mdc(int x, int y){
    if ((x >= y) && (x%y == 0)) return y;
    else if( x < y ) return mdc(y,x);
    else return mdc(y, x%y );
}

void main() {
    printf("%d\n", mdc(180,240));
}