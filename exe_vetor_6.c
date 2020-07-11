#include <stdio.h>

int main()
{
    int v[3] = {46,56,14};
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