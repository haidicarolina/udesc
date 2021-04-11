#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Lista.h"

typedef struct EntradaMatriz {
    int coluna;
    int info;
}EntradaMatriz;

typedef struct MatrizEsparsa {
    Lista multiLista;
    int numColunas;
}MatrizEsparsa;

void inicializa_matriz_esparsa( MatrizEsparsa *me, int l, int c );
void mostra_matriz_esparsa( MatrizEsparsa m, void (*mostra)(void *)  );
int set_matriz_esparsa( MatrizEsparsa *p, int lin, int col, int valor);
int get_matriz_esparsa( MatrizEsparsa *p, int lin, int col, int valor);
int soma_matrizes_esparsa( MatrizEsparsa a, MatrizEsparsa b );
void desaloca_matriz_esparsa( MatrizEsparsa *p );