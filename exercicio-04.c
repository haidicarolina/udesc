#include <stdio.h>

void main()
{
    int l1, l2, l3;
    printf("Lado 1: ");
    scanf("%d", &l1);
    printf("Lado 2: ");
    scanf("%d", &l2);
    printf("Lado 3: ");
    scanf("%d", &l3);

    if(l1 + l2 <= l3 || l1 + l3 <= l2 || l2+ l3 <= l1 || l1 <= 0 || l2 <= 0 || l3 <= 0)
    {
        printf("Valores nao formam um triangulo.\n");
    }else if(l1 == l2 && l2 == l3)
    {
        printf("equilatero");
    }else if(l1 != l2 && l1 != l3 && l2 != l3)
    {
        printf("escaleno");
    }else if(l1 == l2 || l1 == l3 || l2 == l3)
    {
        printf("isosceles");
    }
}