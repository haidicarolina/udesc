/*
Exercicio - 1

Faça um programa que leia o nome de um produto, o preço e a quantidade comprada
e armazene estas informações em uma estrutura. Em seguida, o programa deve escrever
o nome do produto, quantidade, preço unitário e o valor total a ser pago, considerando
que são oferecidos diferentes descontos com base no número de unidades compradas.
Os descontos concedidos devem respeitar tabela a seguir:
    a.Até 5 unidades: sem desconto
    b.De 6 a 15 unidades: 10% de desconto
    c.Acima de 16 unidades: 20% de desconto*/

#include <stdio.h>

#define MAX 100
#define DESC10 0.9
#define DESC20 0.8

typedef struct{
    char nome[MAX];
    float preco;
    int qtde;
}Produtos;

Produtos produto;

void main()
{
    printf("Nome de um produto: ");
    scanf("%s", produto.nome);
    printf("Preço: ");
    scanf("%f", &produto.preco);
    printf("Quantidade: ");
    scanf("%d", &produto.qtde);

    printf("\nNome do produto: %s", produto.nome);
    printf("\nQuantide: %d", produto.qtde);

    if (produto.qtde <= 5)
    {
        printf("\nPreço unitário: %.2f", produto.preco);
        printf("\n\nTotal: %.2f\n", produto.preco*produto.qtde);
    }else if(produto.qtde > 5 && produto.qtde <= 15)
    {
        printf("\nPreço unitário: %.2f", produto.preco * DESC10);
        printf("\n\nTotal: %.2f\n", (produto.preco*produto.qtde) * DESC10);
    }else if(produto.qtde > 16)
    {
        printf("\nPreço unitário: %.2f", produto.preco * DESC20);
        printf("\nTotal: %.2f\n", (produto.preco*produto.qtde) * DESC20);
    }
}