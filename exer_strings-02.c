#include <stdlib.h>
#include <stdio.h>

#define MAX 20
/*
2. Altere o programa do exercício 1 para considerar os espaços adjacentes apenas como uma unidade
na contagem. Também não deve ser utilizado nenhuma função de manipulação de strings contida
na biblioteca string.h.
○ Exemplo 1, dada a string "abc", a saída esperada é 0.
○ Exemplo 2, dada a string "a   b c", a saída esperada é 2.
*/


void main()
{
    char caracter[MAX];
    int total = 0, aux = 0;
    printf("digite uma cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter);
    for (int i = 0; i < MAX; i++)
    {
        if ( *(caracter+i) == 32 && *(caracter+i-1) != 32)
        {
            aux++;
        }else{
            total+=aux;
            aux=0;
        }
    }
    printf("total de espaço em branco: %d\n", total);
}