#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, i, resultado=0;

    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);

    for(i = 0; i < num2; i++)
    {
        resultado += num1;
    }
    printf("%d\n", resultado);
}