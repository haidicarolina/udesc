#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MatrizDinamica.h"
#include "FilaGenerica.h"

//-----------------------------------
//Alunos: Cristiano, Haidi
//-----------------------------------

#define False 0
#define True 1
//gcc trabalho2.c MatrizDinamica.c FilaGenerica.c -o teste

typedef struct{
	int linha, coluna, distancia;
}Coordenada;

void mostra_coordenada( void *x ){
	Coordenada *p = x;
	printf("(%d, %d, %d)\n", p->linha, p->coluna, p->distancia);
}

void main(int argc, char *argv[]){
    //--------------------------------------------------
    //ENTRADA DE DADOS DA MATRIZ
    //--------------------------------------------------
    int i=0,j=0,k=0,lin,col,ini_l,ini_c,fim_l,fim_c;
    MatrizDinamica m1, m2;
    FILE *arquivo = fopen("entrada_dados.txt","r");    
    if (arquivo != NULL)
    {
        fscanf(arquivo, "%d %d ", &lin, &col);
        inicializa_matriz( &m1, lin, col);
        inicializa_matriz( &m2, lin, col);
        while (fscanf(arquivo, "%d ", &k) != EOF)
        {
            modifica_matriz(&m1, i,j,k);
            j++;
            if (j==col)
            {
                i++;
                j = 0;
            }
            if (i==lin)
            {
                fscanf(arquivo, "%d %d %d %d ", &ini_l, &ini_c, &fim_l, &fim_c);
            }
        }
    }
    FilaGenerica f1; // cria a fila
    inicializa_fila( &f1, 10, sizeof(Coordenada)); //inicializa a fila
    Coordenada c; // cria a coordenada
    ini_l--; //ajuste dos inputs no indice da matriz
    ini_c--; //ajuste dos inputs no indice da matriz
    fim_l--; //ajuste dos inputs no indice da matriz
    fim_c--; //ajuste dos inputs no indice da matriz
    c.linha = ini_l; // alimenta a coordenada inicial
    c.coluna = ini_c; // alimenta a coordenada inicial
    c.distancia = 0; // alimenta a coordenada inicial
    modifica_matriz(&m2, ini_l, ini_c, 1); // altera matriz sencundária
    inserir( &f1, &c ); // insere coordenada na Fila
    int achou = False; // atribui 0 para a variável "achou"
    int temp1 = 0,temp2 = 0; // variáveis temporárias 
    while (!fila_vazia(f1) && !achou)
    {
        remover( &f1, &c);
        if (c.linha == fim_l && c.coluna == fim_c) // se chegou ao final do labirinto
        {
            achou = True;
        }else
        {
            i = c.linha;
            j = c.coluna;
            int d = c.distancia;
            // printf("FOR DE: i: %d,j: %d, d:%d\n", i, j, d);
            for (int g = 0; g < 8; g+=2) // vai percorrer as direções para achar adjacentes
            {
                int vet[8] = { i-1,j, i+1,j, i,j-1, i,j+1 };//matriz com as direções: ^ v < >

                if (vet[g] >= 0 &&
                    vet[g+1] >= 0 && 
                    vet[g] <= lin-1 &&
                    vet[g+1] <= col-1)
                {
                    printf("vet[%d]: %d vet[%d]: %d\n",g,g+1, vet[g], vet[g+1]);
                    temp1 = m1.dados[vet[g]][vet[g+1]];
                    temp2 = m2.dados[vet[g]][vet[g+1]];                    
                }
                if (temp1 == 1 &&   // se é um caminho do labirinto
                    i >=0 &&        // se está dentro dos limites da matriz
                    i < lin &&      // se está dentro dos limites da matriz
                    temp2 == 0)     // se célula ainda não foi visitada
                {
                    m2.dados[vet[g]][vet[g+1]] = 1;
                    c.linha = vet[g];
                    c.coluna = vet[g+1];
                    c.distancia = d+1;
                    inserir( &f1, &c);
                    temp1 = 0;
                    temp2 = 0;
                }
            }
        }
    }
    if (achou)
    {
        printf("Distancia: %d\n", c.distancia);
    }else
    {
        printf("nao tem caminho possivel.\n");
    }
    
    // mostra_matriz( m1 );
    // mostra_matriz( m2 );
    desaloca_matriz( &m1 );
    desaloca_matriz( &m2 );
    desaloca_fila( &f1 );
    fclose(arquivo);
}