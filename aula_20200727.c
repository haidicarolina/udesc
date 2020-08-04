#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAMANHO 5

void* realocar(void* origem, size_t n) {
    //size_t é uma constante para unsigned long
    //aloca dinamicamente um espaço de memória com tamanho n
    void* destino = malloc(n);
    //copia n bytes do ponteiro de origem para o destino
    memcpy(destino,origem,n);
    //retorna o novo espaço de memória recém alocado
    return destino;
}

int main() {
    int **a = (int**) malloc(TAMANHO * sizeof(int*));

    for(int i = 0; i < TAMANHO; i++) {
        a[i] = (int*) malloc(sizeof(int));
        *a[i] = i + 1;
    }

    //Somente copia os dados, incluindo ponteiros.
    //int **b = realocar(a,TAMANHO * 2 * sizeof(int*));
    
    //Duplica todos os endereços de cada posição do vetor.
    int **b = (int**) malloc(TAMANHO * 2 * sizeof(int*));

    for (int i = 0; i < TAMANHO; i++) {
        //Somente copia os dados, incluindo ponteiros (similar à função realocar).
        //b[i] = a[i];
        
        //Duplica todos os endereços de cada posição do vetor.
        b[i] = (int*) malloc(sizeof(int));
        *b[i] = *a[i];
    }

    //Se for só copiado os dados, incluindo ponteiros, a atualização de a irá refletir em b.
    //Do contrário, a e b interagem com endereços de memória distintos e um não afeta o outro.
    for (int i = 0; i < TAMANHO; i++) {
        *a[i] = TAMANHO - i;
    }

    for (int i = 0; i < TAMANHO; i++) {
        printf("Valor em b[%d]: %d\n",i,*b[i]);
        printf("Valor em a[%d]: %d\n",i,*a[i]);

        printf("Endereço de b[%d]: %p\n",i,b[i]);
        printf("Endereço de a[%d]: %p\n",i,a[i]);
    }
}