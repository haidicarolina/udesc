#include <stdio.h>

void main()
{
    int n, i, v1, v2, aux;

    printf("quantos numeros reais? ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("digitar um numero: ");

        if (i==0)
        {
            scanf("%d", &v1);
        }

        if (i==1)
        {
            scanf("%d", &v2);
        }

        if(i>1)
        {
            scanf("%d", &aux);
            if( aux > v2)
            {
                if(v2 > v1)
                {
                    v1 = v2;
                }
                v2 = aux;
            }else if( aux > v1)
            {
                v1 = aux;
            }
        }
    }
    printf("%d e %d", v1,v2);
}