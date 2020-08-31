#include <stdlib.h>
#include <stdio.h>

#define MAX 20
/*
5. Faça um programa que leia duas cadeia de caracteres e, em seguida, o programa deve retornar
true se a segunda cadeia estiver contida na primeira (substring), caso contrário deve retornar
false. Não deve ser utilizado nenhuma função de manipulação de strings da biblioteca string.h.
○ Exemplo 1, dadas as strings "abcd" e "cd", a saída esperada é true.
○ Exemplo 2, dadas as strings "abcd" e "cb", a saída esperada é false.
*/


void main()
{
    char caracter1[MAX];
    char caracter2[MAX];
    int aux, cont = 0;
    printf("digite uma cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter1);
    printf("digite outra cadeia de caracter: ");
    scanf("%[^\n]%*c", caracter2);
    for (int i = 0; i < MAX; i++)
    {
        if(*(caracter2+i) == 0){
            break;
        }
        cont++;
    }

    printf("tamanho do caracter2: %d\n", cont);
    
    for (int i = 0; i < MAX; i++)
    {
        aux = 0;
        if(*(caracter1+i) == 0){
            break;
        }
        for (int j = 0; j < cont; j++)
        {
            if(*(caracter2+j) == *(caracter1+i)){
                aux++;
            }
        }
        if (aux == cont)
        {
            break;
        }
    }

    aux == cont ? printf("true\n") : printf("false\n");//operador ternário
    
}