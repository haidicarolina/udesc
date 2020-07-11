#include <stdio.h>

int n;

int fibo(int base){
    if(base==0)
        return 0;
    else if(base==1)
        return 1;
    else
        return fibo(base-2)+fibo(base-1);
}

int main()
{
    printf("Fibonacci de: ");
    scanf("%d", &n);
    int fibonacci = fibo(n);
    printf("Fibonacci de %d eh %d\n", n, fibonacci);
    return 0;
}