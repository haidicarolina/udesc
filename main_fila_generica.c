#include <stdio.h>
#include <stdlib.h>
#include "FilaGenerica.h"
//gcc main_fila_generica.c FilaGenerica.c -o teste
typedef struct{
	int x, y;
}Coordenada;

void mostra_float( void *x ){
	float *p = x;
	printf("%f\n", *p);
}

void mostra_coordenada( void *x ){
	Coordenada *p = x;
	printf("(%d, %d)\n", p->x, p->y);
}

int main(int argc, char *argv[]) {
	
	FilaGenerica f1;
	inicializa_fila( &f1, 4, sizeof(Coordenada) );
	mostra_fila( f1 , mostra_coordenada );
	
	Coordenada c;
	c.x = 3;
	c.y = 4;
	inserir( &f1, &c );
	mostra_fila( f1 , mostra_coordenada );
	
	c.x = 6;
	c.y = 6;
	inserir( &f1, &c );
	mostra_fila( f1 , mostra_coordenada );
	
	c.x = 7;
	c.y = 1;
	inserir( &f1, &c );
	mostra_fila( f1 , mostra_coordenada );
	
	desaloca_fila( &f1 );
	
	/*
	FilaGenerica f1;
	inicializa_fila( &f1, 4, sizeof(float) );
	mostra_fila( f1 , mostra_float );
	
	float x = 2;
	
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );
	
	x = 4;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );
	
	x = 8;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );
	
	x = 16;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );

	x = 32;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );	
	
	remover( &f1, &x);
	printf("Removi o %f...\n", x);
	mostra_fila( f1 , mostra_float );

	remover( &f1, &x);
	printf("Removi o %f...\n", x);
	mostra_fila( f1 , mostra_float );

	x = 32;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );
	
	x = 64;
	inserir( &f1, &x );
	mostra_fila( f1 , mostra_float );

	desaloca_fila( &f1 );
	*/
	
	return 0;
}
