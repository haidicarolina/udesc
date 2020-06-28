#include <stdio.h>

int main() { 
    int k, n;
    int f = 1;
    do {
        printf("Qual a sua idade? ");
        scanf("%d", &n);
    }while( n < 0 );
    if (n >= 18)
    {
        printf("Maior de idade");
    }else
    {
        printf("Menor de idade");
    }
}