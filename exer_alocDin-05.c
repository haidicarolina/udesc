#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Informe o número de elementos do vetor: ");
    scanf("%d",&n);

    int *v = calloc(n,sizeof(int));
    double media = 0;

    for (int i = 0; i < n; i++) {
        printf("Informe o %dº valor: ", i + 1);
        scanf("%d",v + i);

        media += *(v + i);
    }

    media /= n;

    //ordena o vetor para obter a mediana
    //bubble-sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(v + i) > *(v + j)) {
                int troca = *(v + i);
                
                *(v + i) = *(v + j);
                *(v + j) = troca;
            }
        }
    }

    int mediana = *(v + (n / 2));
    
    int moda,ocorrencias = 0;

    for (int i = 0; i < n - 1; i++) {
        int soma = 0;
        
        for (int j = i  + 1; j < n; j++) {
            if (*(v + i) == *(v + j)) {
                soma++;
            }
        }

        if (soma > ocorrencias) {
            ocorrencias = soma;
            moda = *(v + i);
        }
    }

    free(v);

    printf("Média: %f\n", media);
    printf("Mediana: %d\n", mediana);
    printf("Moda: %d\n", moda);
}