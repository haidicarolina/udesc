#include <stdio.h>

//--------------------------------------------------------------
// EXERCICIO 5 - AULA 29/06/2020
// https://github.com/allanrodrigol/linguagem-programacao/blob/master/03%20-%20Vari%C3%A1veis%20compostas.pdf
//--------------------------------------------------------------
int main()
{
    int v[5] = {1,2,3,4,5};
    int s[5] = {0,0,0,0,0};

    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i != j)
            {
                if(s[i] == 0)
                {
                    s[i] = v[j];
                }else{
                    s[i] *= v[j];
                }
            }   
        }
        if (i == 0)
        {
            printf("[%d,", s[i]);
        }else if(i<4)
        {
            printf("%d,", s[i]);
        }else
        {
            printf("%d]\n", s[i]);
        }   
    }
}