#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    srand(time(NULL));
    
    int numeroGerado = rand() % 100;
    int palpite, tentativas=0;

    do
    {
        printf("Palpite: ");
        scanf("%d", &palpite);
        if(palpite > numeroGerado)
            printf("Numero gerado eh menor\n");
        if(palpite < numeroGerado)
            printf("Numero gerado eh maior\n");
        tentativas++;
    } while (palpite != numeroGerado);
    printf("%d", tentativas);
}