<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaChar.h"
#include "Pilha.h"

#define MAX 30

int precedencia( char info );
int calcula_posfixa( char *expressao);

int main(int argc, char *argv[]){
	char entrada[MAX] = ""; //(5+9)*2+6*5
	char saida[MAX]= "";
    int string_len;
    PilhaChar p2;
    inicializa_pilha_char(&p2, MAX);
	printf("Digite uma formula: ");
	scanf("%[^\n]%*c", entrada); // leitura de qualquer caractere, exceto '\n'.
    printf("%s\n", entrada);
    string_len = strlen(entrada);

    int deu_erro = 0, i = 0, j = 0;
    char c, x;

    while ( i < string_len && !deu_erro)
    {
        c = entrada[i];
        if( c >= 48 && c <= 57){
            saida[j] = c;
            j++;
        }else if (c == '(')
        {
            empilha_char( &p2, c );
        }else if (c == ')')
        {
            while ( (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA) && ( x != '(' ) )
            {
                desempilha_char( &p2, &x);
                saida[j] = x;
                j++;
            }
            if (pilha_vazia_char( p2 ))
            {
                printf("Erro: ')' sem '('\n");
                deu_erro = 1;
            }else
            {
                desempilha_char( &p2, &x);
            }
        }else if( c == '+' ||  c == '-' ||  c == '*' ||  c == '/')
        {
            le_topo_char( p2, &x);
            if (pilha_vazia_char( p2 ) || (x == '('))
            {
                empilha_char( &p2, c );
            }else{
                while (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA && precedencia(x) >= precedencia(c))
                {
                    desempilha_char( &p2, &x);
                    saida[j] = x;
                    j++;
                }
                empilha_char( &p2, c );
            }
        }else
        {
            printf("\n\nErro: caractere inválido: %c", c);
            deu_erro = 1;
        }
        i++;
    }
    if (!deu_erro)
    {
        while ( (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA) && ( x != '(' ) )
        {
            desempilha_char( &p2, &x);
            saida[j] = x;
            j++;
        }
        if (pilha_vazia_char( p2 ))
        {
            saida[j] = '\n';
            printf("%s", saida);
            calcula_posfixa( saida );
        }else{
            printf("Erro: ')' sem '('\n");
        }
    }
    desaloca_pilha_char( &p2 );
    return 0;
}

int precedencia( char info ){
    if (info == '*' || info == '/') return 2;
    else if (info == '+' || info == '-') return 1;
    else if (info == '(') return 0;
}

int calcula_posfixa( char *expressao){
    Pilha p1;
    inicializa_pilha(&p1, MAX);
    int string_len = 0, i = 0, aux1 = 0, aux2 = 0;
    char c;
    printf("expressao: %s", expressao);
    string_len = strlen(expressao) - 1; // -1 para ignorar o \n que adicionamos antes
    printf("len: %d\n", string_len);
    while ( i < string_len){
        c = expressao[i];
        printf("caracter: %c\n", c);
        if( c >= 48 && c <= 57)
        {
            int numero = c - 48;
            empilha( &p1, numero );
        }else
        {
            desempilha( &p1, &aux2);
            desempilha( &p1, &aux1);
            if (expressao[i] == '+')
            {
                empilha(&p1, aux1+aux2);
            }else if (expressao[i] == '-')
            {
                empilha(&p1, aux1-aux2);
            }else if (expressao[i] == '*')
            {
                empilha(&p1, aux1*aux2);
            }else
            {
                empilha(&p1, aux1/aux2);
            }
        }
        i++;
    }
    desempilha( &p1, &aux1 );
    printf("valor final: %d\n", aux1);
    desaloca_pilha( &p1);
=======
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "PilhaChar.h"
#include "Pilha.h"

#define MAX 30

int precedencia( char info );
int calcula_posfixa( char *expressao);

int main(int argc, char *argv[]){
	char entrada[MAX] = "(2+4)*(9-2)/6"; // mudar para "" e descomentar as linhas de entrada (19 e 20)
	char saida[MAX]= "";
    int string_len;
    PilhaChar p2;
    inicializa_pilha_char(&p2, MAX);
	// printf("Digite uma formula: ");
	// scanf("%[^\n]%*c", entrada); // leitura de qualquer caractere, exceto '\n'.
    printf("%s\n", entrada);
    string_len = strlen(entrada);

    int deu_erro = 0, i = 0, j = 0;
    char c, x;

    while ( i < string_len && !deu_erro)
    {
        c = entrada[i];
        if( c >= 48 && c <= 57){
            saida[j] = c;
            j++;
        }else if (c == '(')
        {
            empilha_char( &p2, c );
        }else if (c == ')')
        {
            while ( (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA) && ( x != '(' ) )
            {
                desempilha_char( &p2, &x);
                saida[j] = x;
                j++;
            }
            if (pilha_vazia_char( p2 ))
            {
                printf("Erro: ')' sem '('\n");
                deu_erro = 1;
            }else
            {
                desempilha_char( &p2, &x);
            }
        }else if( c == '+' ||  c == '-' ||  c == '*' ||  c == '/')
        {
            le_topo_char( p2, &x);
            if (pilha_vazia_char( p2 ) || (x == '('))
            {
                empilha_char( &p2, c );
            }else{
                while (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA && precedencia(x) >= precedencia(c))
                {
                    desempilha_char( &p2, &x);
                    saida[j] = x;
                    j++;
                }
                empilha_char( &p2, c );
            }
        }else
        {
            printf("\n\nErro: caractere inválido: %c", c);
            deu_erro = 1;
        }
        i++;
    }
    if (!deu_erro)
    {
        while ( (le_topo_char( p2, &x) != ERRO_PILHA_VAZIA) && ( x != '(' ) )
        {
            desempilha_char( &p2, &x);
            saida[j] = x;
            j++;
        }
        if (pilha_vazia_char( p2 ))
        {
            saida[j] = '\n';
            printf("%s", saida);
            calcula_posfixa( saida );
        }else{
            printf("Erro: ')' sem '('\n");
        }
    }
    desaloca_pilha_char( &p2 );
    return 0;
}

int precedencia( char info ){
    if (info == '*' || info == '/') return 2;
    else if (info == '+' || info == '-') return 1;
    else if (info == '(') return 0;
}

int calcula_posfixa( char *expressao){
    Pilha p1;
    inicializa_pilha(&p1, MAX);
    int string_len = 0, i = 0, aux1 = 0, aux2 = 0;
    char c;
    printf("expressao: %s", expressao);
    string_len = strlen(expressao) - 1; // -1 para ignorar o \n que adicionamos antes
    printf("len: %d\n", string_len);
    while ( i < string_len){
        c = expressao[i];
        printf("caracter: %c\n", c);
        if( c >= 48 && c <= 57)
        {
            int numero = c - 48;
            empilha( &p1, numero );
        }else
        {
            desempilha( &p1, &aux2);
            desempilha( &p1, &aux1);
            if (expressao[i] == '+')
            {
                empilha(&p1, aux1+aux2);
            }else if (expressao[i] == '-')
            {
                empilha(&p1, aux1-aux2);
            }else if (expressao[i] == '*')
            {
                empilha(&p1, aux1*aux2);
            }else
            {
                empilha(&p1, aux1/aux2);
            }
        }
        i++;
    }
    desempilha( &p1, &aux1 );
    printf("valor final: %d\n", aux1);
    desaloca_pilha( &p1);
>>>>>>> dd2b7def938b321b19d26d010f6da908e83abb52
}