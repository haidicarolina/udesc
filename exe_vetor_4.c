#include <stdio.h>

int main()
{
    int n = 4, k = 17;
    int v[4] = {10,15,3,7};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (v[i]+v[j] == k)
            {
                printf("%d + %d = %d\n", v[i], v[j], k);
                printf("verdadeiro\n");
                return 0;
            }
        }
    }
}