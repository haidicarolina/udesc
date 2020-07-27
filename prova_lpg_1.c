#include <stdio.h>

//--------------------------------------------------------------
// EXERCICIO 4 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
/*
int main()
{
    int n, k;
    printf("Qtde numeros inteiros: \n");
    scanf("%d", &n);
    int v[n];
    printf("Qual numero sera verificado: \n");
    scanf("%d", &k);
    for (int i = 0; i < n; i++)
    {
        printf("Insira o %dº valor: \n", i+1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i]+v[j] == k)
            {
                printf("true, pois ");
                printf("%d + %d = %d\n", v[i], v[j], k);
                return 0;
            }
        }
    }
}
*/

void main()
{
    int n, maior_par = 0, qtde = 0, pares = 0;
    printf("Quantas luvas?: \n");
    scanf("%d", &n);
    int v[n];
    for (int i = 0; i < n; i++)
    {
        printf("Insira o tamanho da %d luva: \n", i+1);
        scanf("%d", &v[i]);
    }

    for (int i = 0; i < n; i++)
    {
        if (v[i] > maior_par)
        {
            maior_par = v[i];
        }
    }

    printf("Maior par: %d\n\n", maior_par);

    for (int i = 1; i <= maior_par; i++)
    {
        qtde = 0;
        for (int j = 0; j < n; j++)
        {
            if (v[j] == i)
            {
                qtde++;
            }
            if (qtde == 2)
            {
                pares++;
                qtde = 0;
            }
        }
    }

    printf("Total de pares: %d\n", pares);
}