#include <stdio.h>
#include <stdlib.h>

void main()
{
    int num1, num2, i, resultado=1;

    printf("Numero 1: ");
    scanf("%d", &num1);
    printf("Numero 2: ");
    scanf("%d", &num2);

    do
    {
        num1 -= num2;
        resultado++;
    }while (num1 - num2 >= num2);

    printf("%d\n", resultado);
    
}