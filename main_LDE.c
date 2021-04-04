#include <stdio.h>
#include <stdlib.h>
#include "LDE.h"

//gcc main_LDE.c LDE.c -o teste

void mostra_float( void *x ){     // mostra um float...
  float *p = x;
  printf("%f\n", *p ); // a partir de um void*
}

int main(int argc, char *argv[]) {
	LDE lde1;
	inicializa_LDE( &lde1, sizeof(float) );
    mostra_LDE( lde1, mostra_float);

    float num = 10.5;
    insere_inicio( &lde1, &num);
    mostra_LDE( lde1, mostra_float);

    num = 7.997;
    insere_inicio( &lde1, &num);
    mostra_LDE( lde1, mostra_float);

    num = 3.14;
    insere_inicio( &lde1, &num);
    mostra_LDE( lde1, mostra_float);

    num = 883.14;
    insere_fim( &lde1, &num);
    mostra_LDE( lde1, mostra_float);

    num = 55.55;
    insere_pos( &lde1, &num, 2);
    mostra_LDE( lde1, mostra_float);

    remove_inicio(&lde1, &num);
    mostra_LDE( lde1, mostra_float);

    float num2;
    remove_pos( &lde1, &num2, 2);
    mostra_LDE( lde1, mostra_float);

    mostra_LDE_inverso( lde1, mostra_float);

}
