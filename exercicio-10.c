#include <stdio.h>

void main()
{
    int n, i, maior, menor, aux;
    float total;

    printf("quantos numeros reais? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("informar numero: ");
        scanf("%d", &aux);
        if(i == 0)
        {
            maior = aux;
            menor = maior;
        }
        if(i>=1)
        {
            if(aux < menor)
            {
                menor = aux;
            }
            if(aux > maior)
            {
                maior = aux;
            }
        }
        total += aux;
    }
    printf("Maior=%d, Menor=%d, Media=%.2f", maior, menor, total/n);
}