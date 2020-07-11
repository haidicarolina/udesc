#include <stdio.h>
#include <math.h>

//--------------------------------------------------------------
// EXERCICIO 1 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
void main()
{
    int qtdeDados = 0;
    scanf("%d", &qtdeDados);
    int vetorInt[qtdeDados];
    float vetorFloat[qtdeDados], media, peso;

    //preencher com valores INT
    for (int i = 0; i < qtdeDados; i++)
    {
        scanf("%d", &vetorInt[i]);
    }

    //preencher com valores FLOAT + calculo da media e do peso
    for (int i = 0; i < qtdeDados; i++)
    {
        scanf("%f", &vetorFloat[i]);
        media += vetorInt[i] * vetorFloat[i];
        peso += vetorFloat[i];
    }

    media = media / peso;

    printf("media aritmetica ponderada: %.2f", media);
    
}