#include <stdio.h>

void main()
{
    int nTab, nDado, i;
    printf("Qual tabuada: ");
    scanf("%d", &nDado);
    if (nDado < 0)
    {
        printf("informar valor positivo");
    }else{
        for(i = 0; i < 11; i++)
        {
            nTab = i * nDado;
            printf("%d x %d = %d", i, nDado, nTab);
            if (i < 10)
            {
                printf(", ");
            }        
        }
    }
}