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

void mostra_matriz_esparsa( MatrizEsparsa m, void (*mostra)(void *)  ){
    int i, j;
    Elemento *p = m.multiLista.cabeca;
    Elemento *k = m.multiLista.cabeca->info;
	
	printf("Dados da matriz (%dx%d):\n", m.multiLista.qtd, m.numColunas);

	for( i = 0 ; i < m.multiLista.qtd; i++ ){
		for( j = 0; j < m.numColunas ; j++ ){
            // printf("j < m->numColunas: %d < %d", j, m->numColunas);
            // printf("%4d", 15);
			mostra( k->info );
            if (k != NULL) k = k->proximo;
        }
        p = p->proximo;
		printf("\nteste1");
	}
	printf("\nteste2");
}