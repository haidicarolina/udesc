#include <stdio.h>

#define QTDENOTAS 4
#define BIMESTRES  3
#define NOTAS  2

//--------------------------------------------------------------
// FOR
//--------------------------------------------------------------
/*
void main()
{
    double nota, soma = 0.0;

    for (int i = 0; i < QTDENOTAS; i++)
    {
        printf("digite nota: \n");
        scanf("%lf", &nota);

        soma += nota;
    }
     
    soma /= QTDENOTAS;

    printf("Media: %lf\n", soma);

}

//--------------------------------------------------------------
// VETOR
//--------------------------------------------------------------
void main()
{
    float soma, notas[QTDENOTAS] = {};

    for (int i = 0; i < QTDENOTAS; i++)
    {
        printf("Digite uma nota: \n");
        scanf("%f", &notas[i]);
        soma += notas[i];
    }
     
    soma /= QTDENOTAS;

    for (int i = 0; i < QTDENOTAS; i++)
    {
        printf("Nota %d: %.2f\n", i+1, notas[i]);
    }    

    printf("Media: %lf\n", soma);
    
}
*/

void main()
{
    float notas[BIMESTRES][NOTAS], soma = 0, media = 0;

    for (int i = 0; i < BIMESTRES; i++)
    {
        printf("BIMESTRE       %d\n", i + 1);
        soma = 0;
        for (int j = 0; j < NOTAS; j++)
        {
            printf("    Digite uma nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);

            soma += notas[i][j];
        }
        media += soma / NOTAS;
    }

    media /= BIMESTRES;
    printf("Media anual: %.2f\n", media);

    for (int i = 0; i < BIMESTRES; i++)
    {
        soma = 0;
        for (int j = 0; j < NOTAS; j++)
        {
            soma += notas[i][j];
        }

        printf("Media do Bimestre %d: %.2f\n", i, soma / NOTAS);
    }
    
}