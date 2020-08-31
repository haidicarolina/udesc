#include <stdlib.h>
#include <stdio.h>

#define MAX 20
/*
1. Faça um programa que leia uma cadeia de caracteres e, em seguida, o programa deve contar a
quantidade de espaços em branco desta cadeia. Não deve ser utilizada nenhuma função de
manipulação de strings da biblioteca string.h.
○ Exemplo 1, dada a string "abc", a saída esperada é 0.
○ Exemplo 2, dada a string "a b c", a saída esperada é 3.
*/


void main()
{
    char caracter[MAX];
    int total = 0, aux = 0;
    printf("digite uma cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter);
    for (int i = 0; i < MAX; i++)
    {
        if (*(caracter+i) == 32)
        {
            aux++;
        }else{
            total+=aux;
            aux=0;
        }
    }
    printf("total de espaço em branco: %d\n", total);
}