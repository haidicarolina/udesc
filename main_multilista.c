#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

void mostra_int( void *x ){
	printf("%d\n", *(int*)x);
}

void mostra_lista_especial( void *x ){
	Lista *p = x;
	mostra_lista( *p, mostra_int );
}

int main(int argc, char *argv[]) {
	int i, j;
	int lin, col, x;
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);
	
	Lista multi, l;
	inicializa_lista( &multi, sizeof(Lista) );
	
	for( i = 0; i < lin ; i++){
		inicializa_lista( &l, sizeof(int) );
		for( j = 0 ; j < col; j++ ){
			printf("M[%d, %d]: ", i, j);
			scanf("%d", &x);
			insere_fim( &l, &x );
		}
		insere_fim( &multi, &l );
	}
	
	//mostra_lista( multi, mostra_lista_especial );
	
	printf("Dados da matriz:\n");
	for( i = 0; i < lin ; i++){
		le_valor( multi, &l, i );
		//mostra_lista( l, mostra_int );
		for( j = 0 ; j < col; j++ ){
			le_valor( l, &x, j );
			printf("%4d", x);
		}
		printf("\n");
		
	}
	
	// Liberando a mem�ria...
	for( i = 0; i < lin ; i++){
		le_valor( multi, &l, i );
		desaloca_lista( &l );
	}
	desaloca_lista( &multi );
	
	return 0;
}
