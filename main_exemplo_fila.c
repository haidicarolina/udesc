#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"

int main(int argc, char *argv[]) {
	Fila f1;
	inicializa_fila( &f1, 4 );
	mostra_fila( f1 );
	
	inserir( &f1, 2 );
	mostra_fila( f1 );
	
	inserir( &f1, 4 );
	mostra_fila( f1 );
	
	inserir( &f1, 8 );
	mostra_fila( f1 );
	
	inserir( &f1, 16 );
	mostra_fila( f1 );

	inserir( &f1, 32 );
	mostra_fila( f1 );
	
	int x;
	
	remover( &f1, &x);
	printf("Removi o %d...\n", x);
	mostra_fila( f1 );

	remover( &f1, &x);
	printf("Removi o %d...\n", x);
	mostra_fila( f1 );

	inserir( &f1, 32 );
	mostra_fila( f1 );
	
	inserir( &f1, 64 );
	mostra_fila( f1 );

	desaloca_fila( &f1 );
	
	return 0;
}

