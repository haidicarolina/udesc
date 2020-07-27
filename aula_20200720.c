#include<stdio.h>
//alocação dinâmica de memória
int main() {
    int v[] = {5,6,7,8,9,10};
    printf("%p\n", v);
    printf("%d\n", v[0]);
    printf("%d\n", *v);
    printf("%p\n", v+3);
    printf("%d\n", *(v+0)); // = v[0]
    printf("%d\n", *(v+1)); // = v[1]
    printf("%d\n", *(v+2)); // = v[2]
    printf("%d\n", *(v+3)); // = v[3]
    printf("%d\n", *(v+4)); // = v[4]
    printf("%d\n", *(v+5)); // = v[5]
    printf("%p\n", v+0);
    printf("%p\n", v+1);
    printf("%p\n", v+2);
    printf("%p\n", v+3);
    printf("%p\n", v+4);
    printf("%p\n", v+5);

}