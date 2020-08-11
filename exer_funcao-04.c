#include <stdlib.h>
#include <stdio.h>

int fat(int base){
    if (base==1)
        return 1;
    else
        return base * fat(base-1);
}

void main()
{
    int n = 0;
    printf("digite um termo a ser fatorado: ");
    scanf("%d", &n);
    int fatorial = fat(n);
    printf("%d! = %d\n", n, fatorial);
}