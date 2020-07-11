#include <stdio.h>

//--------------------------------------------------------------
// EXERCICIO 6 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
int mdc(int A, int B)
{
    int resto;

    while(B != 0)
    {
        resto = A % B;
        A = B;
        B = resto;
    }
    return A;
}

int main()
{
    int n, aux, saida;
    printf("Qual o tamanho do vetor? ");
    scanf("%d", &n);
    printf("Insira os numeros para verificar o MDC\n");
    int v[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &v[i]);
    }
    if (n == 2)
    {
        saida = mdc(v[0], v[1]);
    }else if(n >= 3)
    {
        aux = mdc(v[0], v[1]);
        for (int i = 1; i < n; i++)
        {
            saida = mdc(v[i], aux);
            aux = mdc(v[i], v[i+1]);
        }
    }
    
    printf("%d", saida);
}