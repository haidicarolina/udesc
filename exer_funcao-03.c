#include <stdlib.h>
#include <stdio.h>

int fibo(int base){
    if(base==0)
        return 0;
    else if(base==1)
        return 1;
    else
        return fibo(base-2)+fibo(base-1);
}

void main()
{
    int n = 0;
    printf("digite um termo: ");
    scanf("%d", &n);
    int fibonacci = fibo(n);
    printf("Fibonacci de %d eh %d\n", n, fibonacci);
}