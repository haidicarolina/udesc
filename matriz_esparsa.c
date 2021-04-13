#include "matriz_esparsa.h"

int compara_matriz_esparsa( void *x, void *y ){
    EntradaMatriz *a = x, *b = y; // void* --> EntradaMatriz*
    printf("a->coluna - b->coluna: %d", a->coluna - b->coluna);
    return a->coluna - b->coluna;
}

void inicializa_matriz_esparsa( MatrizEsparsa *multi, int linhas, int colunas ){
    int i;
    inicializa_lista( &multi->multiLista, sizeof(Lista));
    for (i = 0; i < linhas; i++) {
        Lista c1;
        inicializa_lista( &c1, sizeof(EntradaMatriz) );
		insere_fim( &multi->multiLista, &c1 );
    }
    multi->numColunas = colunas;
}

int set_matriz_esparsa( MatrizEsparsa *multi, int lin, int col, int info ){
    EntradaMatriz entrada, aux;
    entrada.info = info;
    entrada.coluna = col;
    int i, j;
    Lista l;
    i = le_valor( multi->multiLista, &l, lin );
    j = le_valor( l, &aux, col );
    printf("i: %d j: %d\n", i,j);
    aux = entrada;
    if (j > 0)
        insere_ordem( &l, &aux, compara_matriz_esparsa );
    else
        insere_fim( &l, &aux );

}

void mostra_matriz_esparsa( MatrizEsparsa m){
    int i, j;
    EntradaMatriz x;
    Lista l;
	
	printf("Dados da matriz (%dx%d):\n", m.multiLista.qtd, m.numColunas);
	for( i = 0; i < m.multiLista.qtd ; i++){
		le_valor( m.multiLista, &l, i );
		for( j = 0 ; j < m.numColunas; j++ ){
			if(le_valor( l, &x, j ) == 1){
			    printf("%4d ", x.info);
            }else{
			    printf("%4d ", 0);
            }
		}
		printf("\n");
	}
}