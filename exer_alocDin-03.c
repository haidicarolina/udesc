#include <stdlib.h>
#include <stdio.h>

int main() {
    int n;

    printf("Informe o número de elementos do vetor: ");
    scanf("%d",&n);

    int* v = calloc(n,sizeof(int));
    double* p = calloc(n,sizeof(double));

    for (int i = 0; i < n; i++) {
        printf("Informe o %dº valor do conjunto de dados: ", i + 1);
        scanf("%d",&v[i]);

        printf("Informe o %dº valor do peso: ", i + 1);
        scanf("%lf",&p[i]);
    }

    double soma = 0,pesos = 0;

    for (int i = 0; i < n; i++) {
        soma += v[i] * p[i];
        pesos += p[i];
    }

    free(v);
    free(p);

    printf("A média ponderada é: %f\n", soma / pesos);
}