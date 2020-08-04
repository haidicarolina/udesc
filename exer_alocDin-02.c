#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 5
/*
Faça um programa que encontre o maior e menor inteiro dentro de um vetor inteiros alocado
dinamicamente. Em seguida, deve ser exibido o maior e menor inteiro e a soma dos dois. Todas as
operações de manipulação do vetor deve ser realizado a partir da aritmética de ponteiros.
*/
void main()
{
    int *a = (int*) calloc(TAMANHO, sizeof(int));
    int maior = 0, menor = 0;

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("Digite um numero inteiro: ");
        scanf("%d", &a[i]);
        if (i==0)
        {
            maior = *(a+i);
            menor = maior;
        }

        if (*(a+i) > maior)
        {
            maior = *(a+i);
        }
        else if(*(a+i) < menor)
        {
            menor = *(a+i);
        }

    }

    free(a);

    printf("Menor e Maior: %d e %d\n", menor, maior);
    printf("Soma: %d\n", menor + maior);
}