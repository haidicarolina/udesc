/*
Exercicio - 4

Faça um programa que, dadas as posições e dimensões de dois retângulos em um plano
bidimensional, retorne a área de intersecção entre eles. Se não houver intersecção, deve retornar 0.
Use estruturas para representar os retângulos em 2D.
○ Exemplo: dado os retângulos abaixo, a área de intersecção é 6.
        r1 = { .y = 1, .x = 4, .largura = 3, .altura = 3 }
        r2 = { .y = 0, .x = 5, .largura = 4, .altura = 3 }


x+
^
|
|
|
|
|_______________> y+
0,0


*/

/**< CRIAR A ESTRUTURA RETANGULO */
#include <stdio.h>

typedef struct{
    int y;
    int x;
    int largura;
    int altura;
}Retuangulo;

void main()
{
    int altInters = 0, largInters = 0, areaInters = 0;
    int PontosX1, PontosX2;

    Retuangulo r1, r2;
    r1.y = 1;
    r1.x = 4;
    r1.largura = 3;
    r1.altura = 3;

    r2.y = 0;
    r2.x = 5;
    r2.largura = 4;
    r2.altura = 3;
    
    altInters = r1.x+r1.altura - r2.x;
    largInters = r2.y+r2.largura - r1.y;

    areaInters = altInters * largInters;

    if (areaInters > 0)
    {
        printf("area de interseccao de: %d", areaInters);
    }

}