#include <stdio.h>

void main()
{
    float salario, deducao, aliquota;
    
    printf("salario: ");
    scanf("%f", &salario);

    if(salario > 0 && salario <= 1903.98)
    {
        printf("Isento e R$%.2f", salario);
    }else if(salario > 1903.98 && salario <= 2826.65)
    {
        deducao = 142.8;
        aliquota = 0.075;
        salario -= (salario * aliquota - deducao);
        printf("%.2f e R$%.2f", aliquota*100, salario);
    }else if(salario > 2826.65 && salario <= 3751.05)
    {
        deducao = 354.8;
        aliquota = 0.15;
        salario -= (salario * aliquota - deducao);
        printf("%.2f e R$%.2f", aliquota*100, salario);
    }else if(salario > 3751.05 && salario <= 4664.68)
    {
        deducao = 636.13;
        aliquota = 0.225;
        salario -= (salario * aliquota - deducao);
        printf("%.2f e R$%.2f", aliquota*100, salario);
    }else if(salario > 4664.68)
    {
        deducao = 869.36;
        aliquota = 0.275;
        salario -= (salario * aliquota - deducao);
        printf("%.2f e R$%.2f", aliquota*100, salario);
    }else{
        printf("valor informado incorreto");
    }
    
}