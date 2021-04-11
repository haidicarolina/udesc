/*
Trabalho 3: Implementação de Matrizes Esparsas
*/
#include "matriz_esparsa.h"

void mostra_EntradaMatriz( void *x ){
    Elemento *p = x;
	printf("%4d teste", p->info);
}

void main(int argc, char *argv[]){
	int i, j;
	int lin, col;
    EntradaMatriz x;
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);

    MatrizEsparsa me;
    Lista l;
    inicializa_matriz_esparsa( &me, lin, col );
	printf("Dados da matriz:\n");
	for( i = 0; i < lin ; i++){
		le_valor( me.multiLista, &l, i );
		//mostra_lista( l, mostra_int );
		for( j = 0 ; j < col; j++ ){
			le_valor( l, &x, j );
			printf("%4d ", x.info);
		}
		printf("\n");
		
	}
    mostra_matriz_esparsa( me, mostra_EntradaMatriz);
}