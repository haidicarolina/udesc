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

    double soma = 0;

    for (int i = 0; i < n; i++) {
        soma += pow(*(v + i) - media,2);
    }

    free(v);

    double variancia = soma / (n - 1);
    double desvio = sqrt(variancia);

    printf("Média: %f\n", media);
    printf("Variância: %f\n", variancia);
    printf("Desvio padrão: %f\n", desvio);
}