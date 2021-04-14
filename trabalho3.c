/*
Trabalho 3: Implementação de Matrizes Esparsas
*/
#include "matriz_esparsa.h"
#include <locale.h>

void main(int argc, char *argv[]){
	int i, j, get;
	int lin, col;
    MatrizEsparsa me, me1, matriz_soma;
    Lista l;
	
	printf("Digite o numero de linhas: ");
	scanf("%d", &lin);
	printf("Digite o numero de colunas: ");
	scanf("%d", &col);
    inicializa_matriz_esparsa( &me, lin, col );
    inicializa_matriz_esparsa( &me1, lin, col );
    set_matriz_esparsa( &me1, 0, 1, 4);
    set_matriz_esparsa( &me, 2, 2, 3);
    set_matriz_esparsa( &me, 4, 2, 2);
    set_matriz_esparsa( &me, 3, 3, 3);
    set_matriz_esparsa( &me, 3, 4, 15);
    set_matriz_esparsa( &me, 1, 4, 7);
    // set_matriz_esparsa( &me1, 0, 0, 1);
    set_matriz_esparsa( &me1, 3, 3, 3);
    set_matriz_esparsa( &me1, 3, 4, 15);
    set_matriz_esparsa( &me1, 1, 3, 7);
    mostra_matriz_esparsa( me );
    mostra_matriz_esparsa( me1 );
    get = get_matriz_esparsa( &me, 3, 3);
    printf("get: %d\n", get);
    get = get_matriz_esparsa( &me, 3, 4);
    printf("get: %d\n", get);
    get = get_matriz_esparsa( &me, 1, 4);
    printf("get: %d\n", get);
    get = get_matriz_esparsa( &me, 2, 1);
    printf("get: %d\n", get);
    matriz_soma = soma_matrizes_esparsa( &me, &me1, lin, col);
    mostra_matriz_esparsa( matriz_soma );

    desaloca_matriz_esparsa( &me );
}