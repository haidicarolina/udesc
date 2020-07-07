#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void main()
{
    int palpite, tentativas=0, numeroMentalizado, teste, valorMax = 100, valorMin = 0;
    printf("Qual o numero mentalizado? ");
    scanf("%d", &numeroMentalizado);

    do{
        tentativas++;
        srand(time(NULL));
        palpite = valorMin + rand() % (valorMax - valorMin);
        printf("Palpite: %d\n", palpite);
        if(palpite == numeroMentalizado)
            break;
        printf("Diga se o palpite eh Maior ou Menor!!\n1 - Menor\n2 - Maior\nR: ");
        scanf("%d", &teste);
        if(teste == 1)
            valorMin = palpite;
            //printf("valor minimo = %d\n", valorMin);
        if(teste == 2)
            valorMax = palpite;
            //printf("valor maximo = %d\n", valorMax);
        
    } while (1);
    printf("Numero total de tentativs: %d\n\n", tentativas);
}