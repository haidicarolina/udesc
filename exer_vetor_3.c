#include <stdio.h>
#include <math.h>

//--------------------------------------------------------------
// EXERCICIO 3 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
void main()
{
    int qtdeDados = 0;
    scanf("%d", &qtdeDados);
    int vetorInt[qtdeDados];
    float media=0, desvioPadrao=0, variancia = 0, quociente, mediana;
    int qtdeModa = 0;
    int vetorModa[qtdeDados];

    //preencher com valores INT
    for (int i = 0; i < qtdeDados; i++)
    {
        scanf("%d", &vetorInt[i]);
    }

    //calculo da media e do peso
    for (int i = 0; i < qtdeDados; i++)
    {
        media += vetorInt[i];
    }

    media = media / qtdeDados;

    if (qtdeDados % 2 == 0)
    {
        mediana = (vetorInt[qtdeDados/2 - 1] + vetorInt[qtdeDados/2])/2;
    }else
    {
        mediana = vetorInt[(int) qtdeDados/2];
    }

    for(int i = 0; i < qtdeDados; i++)
    {
        for(int j = 0; j < qtdeDados; j++)
        {
            if (vetorInt[i] == vetorInt[j])
            {
                vetorModa[qtdeModa] = vetorInt[i];
                qtdeModa++;
            }            
        }
    }

    printf("mediana: %.2f\n", mediana);
    printf("Qtde de Moda: %.2f\n", qtdeModa);
    if (qtdeModa == 1)
    {
        printf("moda: %.2f\n", vetorModa[0]);
    }else if( qtdeModa > 1)
    {
        for(int i = 0; i < qtdeModa; i++)
        {
            printf("moda: %.2f\n", vetorModa[i]);
        }
    }

}