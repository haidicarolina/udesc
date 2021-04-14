#include "matriz_esparsa.h"

int compara_matriz_esparsa( void *x, void *y ){
    EntradaMatriz *a = x, *b = y; // void* --> EntradaMatriz*
    printf("a->coluna - b->coluna: %d", a->coluna - b->coluna);
    return a->coluna - b->coluna;
}

void mostra_EntradaMatriz( void *x ){     // mostra um float...
    EntradaMatriz *p = x;
    printf("(%d,%d)\n", p->coluna, p->info); // a partir de um void*
}

void inicializa_matriz_esparsa( MatrizEsparsa *ml, int linhas, int colunas ){
    int i;
    inicializa_lista( &ml->multiLista, sizeof(Lista));
    for (i = 0; i < linhas; i++) {
        Lista c1;
        inicializa_lista( &c1, sizeof(EntradaMatriz) );
		insere_fim( &ml->multiLista, &c1 );
    }
    ml->numColunas = colunas;
}

void set_matriz_esparsa( MatrizEsparsa *ml, int lin, int col, int data ){
    Lista linha;
    le_valor( ml->multiLista, &linha, lin );

    EntradaMatriz entrada, aux;
    entrada.info = data;
    entrada.coluna = col;

    int index = busca( linha, &entrada, compara_matriz_esparsa);
    if (index != -1){
        if(data == 0)
            remove_pos(&linha, &entrada, index);
        else
            modifica_valor(linha, &entrada, index);
    }
    else{
        if (data != 0)
            insere_ordem(&linha, &entrada, compara_matriz_esparsa);
    }
    modifica_valor( ml->multiLista, &linha, lin);
}

void mostra_matriz_esparsa( MatrizEsparsa m){
    int i, j, k;
    Lista l;
    EntradaMatriz x;
	printf("Dados da matriz (%dx%d):\n", m.multiLista.qtd, m.numColunas);
	for( i = 0; i < m.multiLista.qtd ; i++){
        Lista linha;
        le_valor(m.multiLista, &linha, i);
        //mostra_lista(linha, mostra_EntradaMatriz);
        int col_atual = 0;
        for(j=0;j<linha.qtd;j++){
            le_valor( linha, &x, j);
            for( k = col_atual ; k < x.coluna ; k++){
                printf("%3d", 0);
            }
            printf("%3d", x.info);
            col_atual += x.coluna + 1;
        }
        for(k = col_atual; k < m.numColunas; k++)
            printf("%3d", 0);
        printf("\n");

    }
}

void desaloca_matriz_esparsa( MatrizEsparsa *m) {
    int i;
    for(i=0;i< m->multiLista.qtd; i++){
        Lista linha;
        le_valor(m->multiLista, &linha, i);
        desaloca_lista( &linha );
    }
    desaloca_lista( &m->multiLista );
}