#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    int n;

    printf("Informe o número de elementos do vetor: ");
    scanf("%d",&n);

    int *v = calloc(n,sizeof(int));
    double media = 0;

    //Solicita o conjunto de dados e calcula a média
    for (int i = 0; i < n; i++) {
        printf("Informe o %dº valor: ", i + 1);
        scanf("%d",v + i);
        
        media += *(v + i);
    }

    media /= n;

    //Ordena o vetor para obter a mediana
    //Método chamado bubble-sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (*(v + i) > *(v + j)) {
                int troca = *(v + i);
                
                *(v + i) = *(v + j);
                *(v + j) = troca;
            }
        }
    }

    //Calcula a mediana do conjunto de dados
    int mediana = *(v + (n / 2));
    
    int moda = *v,ocorrencias = 0;

    //Calcula a moda do conjunto de dados
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

    double desvio,variancia = 0;

    //Calcula a variância e o desvio padrão do conjunto de dados
    for (int i = 0; i < n; i++) {
        variancia += pow(*(v + i) - media,2);
    }

    variancia /= (n - 1);
    desvio = sqrt(variancia);

    double z[n];

    //Calcula o z-score para cada amostra do conjunto de dados
    for (int i = 0; i < n; i++) {
        *(z + i) = (*(v + i) - media) / desvio;
    }

    printf("Valores: {");

    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : ", %d",*(v + i));
    }

    printf("}\n");

    printf("Média: %f\n", media);
    printf("Mediana: %d\n", mediana);
    printf("Moda: %d\n", moda);
    printf("Variância: %f\n", variancia);
    printf("Desvio padrão: %f\n", desvio);

    printf("Z-score: {");

    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%f" : ", %f",*(z + i));
    }

    printf("}\n");

    int ini = 0;
    int fim = 0;

    for (int q = 1; q <= 3; q++) {
        printf("%dº quartil: {",q);

        ini = fim;

        switch (q) {
        case 1:
            fim = n * 0.25;
            break;
        case 2:
            fim = n * 0.75;
            break;
        case 3:
            fim = n;
            break;
        }
       
        for (int i = ini; i < fim; i++) {
            printf(i == ini ? "%d" : ", %d", *(v + i));
        }

        printf("}\n");
    }
   
    free(v);
}