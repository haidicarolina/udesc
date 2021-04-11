#include "matriz_esparsa.h"

void inicializa_matriz_esparsa( MatrizEsparsa *multi, int linhas, int colunas ){
    Lista c1;
    Lista l1 = multi->multiLista;
    int i, j;
    EntradaMatriz x;
    inicializa_lista( &l1, sizeof(Lista));
    for (i = 0; i < linhas; i++) {
        inicializa_lista( &c1, sizeof(EntradaMatriz) );
        for ( j = 0; j < colunas; j++){
			printf("M[%d, %d]: ", i, j);
			scanf("%d", &x.info);
            x.coluna = j;
			insere_fim( &c1, &x );
        }
		insere_fim( &l1, &c1 );
    }
    multi->multiLista = l1;
    multi->numColunas = colunas;
}

void mostra_matriz_esparsa( MatrizEsparsa m){
    int i, j;
    EntradaMatriz x;
    Lista l;
	
	printf("Dados da matriz (%dx%d):\n", m.multiLista.qtd, m.numColunas);
	for( i = 0; i < m.multiLista.qtd ; i++){
		le_valor( m.multiLista, &l, i );
		for( j = 0 ; j < m.numColunas; j++ ){
			le_valor( l, &x, j );
			printf("%4d ", x.info);
		}
		printf("\n");
	}
}