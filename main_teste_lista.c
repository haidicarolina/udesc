#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

typedef struct{
	int codigo;
	char descricao[20];
}Produto;

void mostra_produto( void *x ){     // mostra um float...
  Produto *p = x;
  printf("(%d,%s)\n", p->codigo, p->descricao ); // a partir de um void*
}

int compara_produto_codigo( void *x, void *y ){
   Produto *a = x, *b = y; // void* --> Produto*

   return a->codigo - b->codigo;
}


int main(int argc, char *argv[]) {
	Lista l1;
	inicializa_lista( &l1, sizeof(Produto) );
	mostra_lista( l1, mostra_produto );
	printf("Quantidade de produtos: %d\n", conta_elementos( l1 ));
	
	Produto p1 = {999, "Caderno"};
	insere_ordem( &l1, &p1, compara_produto_codigo );
	mostra_lista( l1, mostra_produto );
	printf("Quantidade de produtos: %d\n", conta_elementos( l1 ));
	
	Produto p2 = {123, "Caneta"};
	insere_ordem( &l1, &p2, compara_produto_codigo );
	mostra_lista( l1, mostra_produto );
	printf("Quantidade de produtos: %d\n", conta_elementos( l1 ));
	
	Produto p3 = {456, "Borracha"};
	insere_ordem( &l1, &p3, compara_produto_codigo );
	mostra_lista( l1, mostra_produto );
	printf("Quantidade de produtos: %d\n", conta_elementos( l1 ));
	
	Produto x = {123, "Caneta"};
	
	/*
	// Questão 2 da Lista de Exercícios
	
	int idx = busca( l1, &x, compara_produto_codigo );
	if( idx == -1 )
		printf("Produto nao encontrado.\n");
	else
		printf("Produto encontrado no indice %d.\n", idx);
	*/
	
	desaloca_lista( &l1 );
	mostra_lista( l1, mostra_produto );
	printf("Quantidade de produtos: %d\n", conta_elementos( l1 ));

	return 0;
}
