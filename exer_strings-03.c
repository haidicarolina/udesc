#include <stdlib.h>
#include <stdio.h>

#define MAX 20
/*
3. Faça um programa que leia uma cadeia de caracteres e, em seguida, o programa deve retornar a
mesma cadeia de caracteres com todas as letras em maiúsculo. Não deve ser utilizado nenhuma
função de manipulação de strings da biblioteca string.h.
○ Exemplo 1, dada a string "abc", a saída esperada é "ABC".
○ Exemplo 2, dada a string "AbC", a saída esperada é "ABC".
*/


void main()
{
    char caracter[MAX];
    printf("digite uma cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter);
    for (int i = 0; i < MAX; i++)
    {
        if(*(caracter+i) == 0){
            break;
        }
        if ( *(caracter+i) >= 97 && *(caracter+i) <= 122)
        {
            printf("%c", *(caracter+i)-32);
        }else{
            printf("%c", *(caracter+i));
        }
    }
    printf("\n");
}