/*
Trabalho 3: Implementação de Matrizes Esparsas
*/
#include "matriz_esparsa.h"

void main(int argc, char *argv[]){
	int i, j;
	int lin, col;
    EntradaMatriz x;
    MatrizEsparsa me;
    Lista l;
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);
    inicializa_matriz_esparsa( &me, lin, col );
    mostra_matriz_esparsa( me );
}