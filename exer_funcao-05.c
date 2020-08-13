#include <stdio.h>
#include <string.h>

void inverter(char *palavra){
    printf("%d\n", *palavra);
    if (*palavra)
    {
        inverter(palavra+1);
        putchar(*palavra);
    }
}

void main() {
    inverter("asdf");
    printf("\n");
}