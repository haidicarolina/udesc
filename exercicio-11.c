#include <stdio.h>

void main()
{
    int resto=0, primo, i, verifica=0;
    printf("Termo: ");
    scanf("%d", &primo);
    for(i=2;i<=primo/2;i++)
    {
        resto = primo % i;
        printf("%d/%d   Resto:%d\n", primo, i, resto);
        if(resto == 0)
            verifica++;
    }
    printf("verifica: %d\n", verifica);
    if(verifica == 0)
        printf("sim");
    else
        printf("nao");
    
}