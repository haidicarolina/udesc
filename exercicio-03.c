#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 30

void main() {

    char situacao[MAX];
    char dado[MAX];
    int saida = 0;
    do {
        
        printf("Qual situacao? ");
        gets(situacao);

        if(strcmp(situacao, "sol") == 0)
        {
            saida = 1;
            printf("Qual nivel de umidade? ");
            gets(dado);

            if (strcmp(dado, "elevada") == 0)
            {
                printf("nao\n");
            }else if( strcmp(dado, "normal") == 0)
            {
                printf("sim\n");
            }else
            {
                printf("informacao irrelevante\n");
            }
        }else if(strcmp(situacao, "nuvens") == 0)
        {
            saida = 1;
            printf("sim\n");
        }else if(strcmp(situacao, "chuva") == 0)
        {
            saida = 1;
            printf("O vento esta forte ou fraco? ");
            gets(dado);

            if (strcmp(dado, "fraco") == 0)
            {
                printf("sim\n");
            }else if( strcmp(dado, "forte") == 0)
            {
                printf("nao\n");
            }else
            {
                printf("informacao irrelevante\n");
            }
        }else{
            printf("situacao irrelevante\n");
        }

    }while( saida != 1 );
}