#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFER_SIZE 20

/*
1. Faça um programa que leia um arquivo texto contendo valores numéricos separados por <tab>.
Em seguida, o programa deve alimentar uma matriz AM x N gerada dinamicamente a partir do número
M de linhas e N colunas existentes no arquivo texto. Por fim, deve ser gerada uma matriz transposta
Mt N x M e gravá-la em outro arquivo.
○ Exemplo, dado o arquivo "1 2 3\n4 5 6", a saída esperada é uma matriz "1 4\n2 5\n3\n6".

~~~~~~~~~~~~ NÃO TERMINADO AINDA ~~~~~~~~~~~~

*/

//gcc exer_arquivos-01.c -o teste

int main() {
    char buffer[BUFFER_SIZE];
    char matriz[4][4];
    FILE *arquivo = fopen("entrada_dados.txt","r");
    while (fgets(buffer, sizeof buffer, arquivo) != NULL)
    {
        for (int i = 0; i < strlen(buffer); i++)
        {
            for (int j = 0; j < strlen(buffer); j++)
            {
                if (buffer[j] >= 48 && buffer[j] <= 57)
                {
                    matriz[i][j] = atoi(buffer+j);
                    printf("%d ", matriz[i][j]);
                }
            }
            printf("\n");
        }
    }

    printf("%ld\n", strlen(matriz[4]));

    if (feof(arquivo)){
        printf("\nChegou no fim do arquivo.\n");
    }else{
        printf("código interrompido.\n");
    }

    fclose(arquivo);
}
