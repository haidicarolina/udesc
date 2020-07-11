/*
Faça um programa para cadastrar veículos. O programa deve conter um menu inicial com opções
para incluir um novo veículo, listar todos os veículos cadastrados e finalizar o programa.
A estrutura do veículo deve conter a placa, categoria (carro, moto, ônibus, caminhão,etc.),
modelo e o ano. Não pode haver veículos com placas idênticas. Use enumeradores para descrever
as categorias dos veículos
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 100

/**< DECLARAÇÃO DE VARIÁVEIS */

void menu();
void incluir();
void listar();
int sair();
void texto_do_menu();
void clrscr();
void popular_array_em_branco();
int quantos_clientes();
int VerificaPlaca( char[] );

enum Categorias {modelo_padrao, carro, moto, onibus, caminhao};

typedef struct{
    char placa[MAX];
    enum Categorias categoria;
    char modelo[MAX];
    int ano;
}Veiculos;

Veiculos veiculos[MAX];

/**< IMPRIME O MENU */

void texto_do_menu(){
    printf("--------------------------------------------------------\n");
    printf("----------------CADASTRO DE VEÍCULOS--------------------\n");
    printf("--------------------------------------------------------\n\n");
    printf("\t(1) Incluir um novo veículo.\n");
    printf("\t(2) Listar todos veículos.\n");
    printf("\t(3) Sair.\n\n");
    printf("\tUse os indicadores para escolher uma opcao: ");
}

/**< GARANTINDO QUE O VETOR ESTEJA LIMPO PARA USO */

void popular_array_em_branco(){
    int i;
    for(i=0;i<MAX;i++){
        veiculos[i].ano = 0;
        strcpy(veiculos[i].placa, "");
        veiculos[i].categoria = 0;
        strcpy(veiculos[i].modelo, "");
    }
}

/** FUNCAO FAZ PROCURA DA PLACA E TAMBEM RETORNA PROXIMA POSICAO NO ARRAY */

int VerificaPlaca(char* placa){

    for(int i = 0; i < MAX; i++){
        if(veiculos[i].placa == placa)
        {
            return 1;
        }
    }
    return 0;
}

/**< CONTA QUANTOS CLIENTES TEM NO VETOR CLIENTES */

int quantos_clientes(){
    int i, c=0;
    for(i=0;i<MAX;i++){
        if(veiculos[i].ano != 0){
            c++;
        }
    }
    return c;
}

/**< FAZ AS VERIFICAÇÕES LOGICAS PARA CADASTRO E INCLUI CLIENTE NO ARRAY CLIENTES */

void incluir(){
    
    int i, j, k, condicao_saida = 0;
    char placa[MAX];
    char userInput[MAX];
    while(1){
        clrscr();
        printf("--------------------------------------------------------\n");
        printf("--------------------INCLUIR VEÍCULO---------------------\n");
        printf("--------------------------------------------------------\n\n");
        printf("\n\n\tDigite uma Placa: ");
        sscanf(fgets(userInput, MAX-1, stdin),"%[^\n]", placa);
        if(VerificaPlaca(placa) == 0){
            for(int i = 0;i < MAX; i++)
            {
                if(veiculos[i].ano == 0)
                {
                    strcpy(veiculos[i].placa, placa);
                    fflush(stdin);
                    printf("\tDigite um Modelo: ");
                    sscanf(fgets(userInput, MAX-1, stdin),"%[^\n]", veiculos[i].modelo);
                    fflush(stdin);
                    printf("\tDigite uma Categoria (utilize os indices)\n");
                    printf("\t1) Carro\n\t2) Moto\n\t3) Onibus\n\t4) Caminhao ");
                    scanf("%u", &veiculos[i].categoria);
                    printf("\tDigite um Ano: ");
                    scanf("%d", &veiculos[i].ano);
                    fflush(stdin);
                    break;
                }
            }
            getchar();
            menu();
        }
    }
    
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}

/**< LIMPA A TELA */

void clrscr()
{
    system("@cls||clear");
}

/**< Finaliza o programa */

int sair(){
    clrscr();
    printf("--------------------------------------------------------\n");
    printf("--------------------FINALIZANDO PROGRAMA----------------\n");
    printf("--------------------------------------------------------\n\n");
    getchar();
    return 0;
}

/**< ITERAR TODO ARRAY CLIENTES E IMPRIMIR OS IDS DIFERENTES DE ZERO */

void listar(){
    int i;
    clrscr();
    printf("--------------------------------------------------------\n");
    printf("--------------------LISTAR VEÍCULOS---------------------\n");
    printf("--------------------------------------------------------\n\n");
    if(quantos_clientes() == 0){
        printf("Nenhum registro encontrado.\n");
    }else{
        for(i=0;i<MAX;i++){
            if(veiculos[i].ano != 0){
                printf("\tPlaca: %s\n", veiculos[i].placa);
                printf("\tModelo: %s\n", veiculos[i].modelo);
                printf("\tCategoria: %u\n", veiculos[i].categoria);
                printf("\tAno: %d\n\n", veiculos[i].ano);
            }
        }
    }
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}

/**< menu */

void menu(){
    int opcao = 0;
    char userInput[MAX];
    while(1){
        clrscr();
        texto_do_menu();
        sscanf(fgets(userInput, MAX-1, stdin),"%d", &opcao);
        if(opcao!=1 && opcao!=2 && opcao!=3){
            printf("\n\n\tDigite uma opcao valida.");
            getchar();
        }else{
            if(opcao == 1){ incluir(); break; }
            if(opcao == 2){ listar(); break; }
            if(opcao == 3){ sair(); break; }
        }
    }
}

int main(){
    popular_array_em_branco();
    menu();
    return 0;
}