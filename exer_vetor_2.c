#include <stdio.h>
#include <math.h>


//--------------------------------------------------------------
// EXERCICIO 2 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
void main()
{
    int qtdeDados = 0;
    scanf("%d", &qtdeDados);
    int vetorInt[qtdeDados];
    float media=0, desvioPadrao=0, variancia = 0;

    //preencher com valores INT
    for (int i = 0; i < qtdeDados; i++)
    {
        scanf("%d", &vetorInt[i]);
    }

    //calculo da media
    for (int i = 0; i < qtdeDados; i++)
    {
        media += vetorInt[i];
    }

    media = media / qtdeDados;

    printf("media: %.2f\n", media);

    for (int i = 0; i < qtdeDados; i++)
    {
        variancia += pow(vetorInt[i]-media,2);
    }

    variancia = variancia/qtdeDados;

    desvioPadrao = sqrt(variancia);

    printf("desvio padrao: %.2f\n", desvioPadrao);

    printf("variancia: %.2f\n", variancia);

}