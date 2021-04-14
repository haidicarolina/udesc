/*
Trabalho 3: Implementação de Matrizes Esparsas
*/
#include "matriz_esparsa.h"
#include <locale.h>

void main(int argc, char *argv[]){
	int i, j;
	int lin, col;
    MatrizEsparsa me;
    Lista l;
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);
    inicializa_matriz_esparsa( &me, lin, col );
    mostra_matriz_esparsa( me );
    printf("teste\n");
    set_matriz_esparsa( &me, 2, 1, 19);
    printf("teste\n");
    mostra_matriz_esparsa( me );


    desaloca_matriz_esparsa( &me );
}