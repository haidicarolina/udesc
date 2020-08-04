#include <stdlib.h>
#include <stdio.h>

#define TAMANHO 2

void main(){

    //int **a = (int**) malloc(5 * sizeof(int*));
    int *a = (int*) calloc(TAMANHO, sizeof(int));

    a[0] = 10;
    a[1] = 20;

    for (int i = 0; i < TAMANHO; i++)
    {
        printf("%d\t", a[i]);
        printf("%p\n", &a[i]);
    }

    a = realloc(a,sizeof(int) * TAMANHO * 2);
    
    for (int i = 0; i < TAMANHO * 2; i++)
    {
        printf("%d\t", a[i]);
        printf("%p\n", &a[i]);
    }
/*
    for (int i = 0; i < TAMANHO; i++)
    {
        //a[i] = (int*) malloc(sizeof(int));
        a[i] = i+1;
    }

    for (int i = 0; i < TAMANHO; i++)
    {
        //printf("Valor em b[%d]: %d\n",i,b[i]);
        printf("Valor em a[%d]: %d\n",i,a[i]);

        //printf("Endereço de b[%d]: %p\n",i,&b[i]);
        printf("Endereço de a[%d]: %p\n",i,&a[i]);
    }
*/
    free(a);
}