#include <stdio.h>
#include <conio.h>
#include <string.h>

#define MAX 30

//Comentario teste
void main() {

    char name[MAX];
    int saida = 0;
    float temperatura;
    float fusao;
    float ebulicao;
    do {
        
        printf("Qual elemento? ");
        gets(name);

        if(strcmp(name, "agua") == 0)
        {
            saida = 1;
            fusao = 0.0;
            ebulicao = 100.0;
            printf("Qual temperatura? ");
            scanf("%f", &temperatura);
            if (temperatura <= fusao)
            {
                printf("Estado Solido");
            }else if( temperatura > fusao && temperatura < ebulicao)
            {
                printf("Estado Liquido");
            }else
            {
                printf("Estado Gasoso");
            }
        }else if(strcmp(name, "etanol") == 0)
        {
            saida = 1;
            fusao = 78.37;
            ebulicao = -114.1;
            printf("Qual temperatura? ");
            scanf("%f", &temperatura);
            if (temperatura <= fusao)
            {
                printf("Estado Solido");
            }else if( temperatura > fusao && temperatura < ebulicao)
            {
                printf("Estado Liquido");
            }else
            {
                printf("Estado Gasoso");
            }
        }else if(strcmp(name, "ferro") == 0)
        {
            saida = 1;
            fusao = 1538;
            ebulicao = 2862;
            printf("Qual temperatura? ");
            scanf("%f", &temperatura);
            if (temperatura <= fusao)
            {
                printf("Estado Solido");
            }else if( temperatura > fusao && temperatura < ebulicao)
            {
                printf("Estado Liquido");
            }else
            {
                printf("Estado Gasoso");
            }
        }else if(strcmp(name, "ouro") == 0)
        {
            saida = 1;
            fusao = 1064;
            ebulicao = 2700.0;
            printf("Qual temperatura? ");
            scanf("%f", &temperatura);
            if (temperatura <= fusao)
            {
                printf("Estado Solido");
            }else if( temperatura > fusao && temperatura < ebulicao)
            {
                printf("Estado Liquido");
            }else
            {
                printf("Estado Gasoso");
            }
        }else if(strcmp(name, "mercurio") == 0)
        {
            saida = 1;
            fusao = -38.83;
            ebulicao = 356.7;
            printf("Qual temperatura? ");
            scanf("%f", &temperatura);
            if (temperatura <= fusao)
            {
                printf("Estado Solido");
            }else if( temperatura > fusao && temperatura < ebulicao)
            {
                printf("Estado Liquido");
            }else
            {
                printf("Estado Gasoso");
            }
        }

    }while( saida != 1 );
}