#include <stdio.h>
#include <stdlib.h>

void main()
{
    int base, exp, i, resultado;
    printf("Base: ");
    scanf("%d", &base);
    printf("Expoente: ");
    scanf("%d", &exp);
    resultado = base;
    for(i = 1;i < exp;i++)
    {
        resultado = resultado * base;
    }
    printf("%d\n", resultado);
}