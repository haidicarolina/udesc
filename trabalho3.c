/*
Trabalho 3: Implementação de Matrizes Esparsas
Alunos: Cristiano Kair e Haidi C. B. Branco.
*/
#include <stdio.h>
#include <stdlib.h>
#include "matriz_esparsa.h"

void menu();
void menu_programa();
void cria_matriz();
void mostra_matriz();
void modifica_matriz();

void main(int argc, char *argv[]){
    menu();
}
void menu() {
    int menu;
    printf("Digite a opcao desejada: \n 1 - Criar matriz \n 2 - Mostrar matriz \n 3 - Modificar matriz \n 4 - Somar matrizes \n 5 - Remover matriz \n 6 - Sair \n");
    printf("Opcao: ");
    scanf("%d", &menu);

    switch(menu) {
        case 1: {
            cria_matriz();
            break;
        }
        case 2: {
           mostra_matriz();
           break;
        }
        case 3: {
            modifica_matriz();
            break;
        }
        case 4: {
            //funcao para somar matrizes
            break;
        }
        case 5: {
            //funcao para remover matriz
            break;
        }
        case 6: {
            printf("---- Sair ----");
            break;
        }
        default: {
            printf("Opcao desconhecida, o programa sera encerrado \n");
            break;
        }
    }
}

void menu_programa() {
    int menu;
    printf(" -- fim -- ")
    printf("Digite a opcao desejada: 1 - Retornar para o menu \n 2 - Sair \n Opcao: ");
    scanf("%d", &menu);
    if (menu == 1) {
        menu();
    }
    else {
        printf(" -- fim -- ");
        break;
    }
}

void cria_matriz() {
	int lin, col;
    MatrizEsparsa me;

	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);
    inicializa_matriz_esparsa( &me, lin, col );
    mostra_matriz_esparsa( me );

    menu_programa();
}

void mostra_matriz() {

    menu_programa();
}

void modifica_matriz() {

    menu_programa();
}
