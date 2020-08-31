#include <stdlib.h>
#include <stdio.h>

#define MAX 20
/*
4. Faça um programa que leia uma cadeia de caracteres e, em seguida, o programa deve retornar
true se a cadeia de caracteres forma um número inteiro, caso contrário deve retornar false. A
verificação deve considerar a existência ou não de separadores de milhar para o idioma português.
Não deve ser utilizado nenhuma função de manipulação de strings da biblioteca string.h.
○ Exemplo 1, dada a string "-150", a saída esperada é true.
○ Exemplo 2, dada a string "-150.0", a saída esperada é false.
*/


void main()
{
    char caracter[MAX];
    int aux = 0;
    printf("digite uma cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter);
    for (int i = 0; i < MAX; i++)
    {
        if(*(caracter+i) == 0){
            break;
        }
        if (*(caracter+i) == 46)
        {
            aux = 1;
        }
    }
    aux == 1 ? printf("false\n") : printf("true\n");//operador ternário
    
}