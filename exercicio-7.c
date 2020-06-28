#include <stdio.h>

void main()
{
    int nDado, i;
    printf("Qual numero: ");
    scanf("%d", &nDado);
    if (nDado < 0)
    {
        printf("informar valor positivo");
    }else{
        for(i = 0; i <= nDado; i = i+2)
        {
            printf("%d", i);
            if (i < nDado)
            {
                printf(", ");
            }
        }
    }
}