/*
Exercicio - 3

Faça um programa para manter as informações de uma agenda de contatos utilizando estruturas e
vetores. O programa deve conter um menu inicial com 5 opções: i) incluir um novo contato; ii)
excluir um contato existente; iii) alterar um contato existente; iv) listar todos os contatos
cadastrados; e v) finalizar o programa. A estrutura do contato deve conter um código de
identificação, nome, e-mail e celular.
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

#define MAX 100  ///**<Um valor que será usado durante o programa e podemos alterar aqui, caso necessário  */
#define ID_MAXIMO 10000
#define ID_MINIMO 1

/**< DECLARAÇÃO DE VARIÁVEIS */

void menu();
void incluir();
void excluir();
void listar();
int sair();
void texto_do_menu();
void clrscr();
void popular_array_em_branco();
int retorna_posicao_no_array(int);
int quantos_contatos();

/**< CRIAR A ESTRUTURA Contato */

typedef struct{
    int id;
    char nome[MAX];
    char email[MAX];
    char celular[MAX];
}Contato;

/**< CRIANDO VETOR Contato */

Contato contatos[MAX];

/**< GARANTINDO QUE O VETOR ESTEJA LIMPO PARA USO */

void popular_array_em_branco(){
    int i;
    for(i=0;i<MAX;i++){
        contatos[i].id = 0;
        strcpy(contatos[i].nome, "");
        strcpy(contatos[i].email, "");
        strcpy(contatos[i].celular, "");
    }
}

/**< CONTA QUANTOS contatos TEM NO VETOR contatos */

int quantos_contatos(){
    int i, c=0;
    for(i=0;i<MAX;i++){
        if(contatos[i].id != 0){
            c++;
        }
    }
    return c;
}

/**< FAZ AS VERIFICAÇÕES LOGICAS PARA CADASTRO E INCLUI Contato NO ARRAY contatos */

void incluir(){
    int i, j, k, condicao_saida = 0;
    int id = 0;
    char userInput[MAX];
    while(1){
        clrscr();
        printf("--------------------------------------------------------\n");
        printf("--------------------INCLUIR contatos--------------------\n");
        printf("--------------------------------------------------------\n\n");
        i = quantos_contatos();
        printf("\tQtde de contatos: %d", i);
        printf("\n\n\tDigite um ID valido (1-10000)\n");
        printf("\tID:\t");
        sscanf(fgets(userInput, MAX-1, stdin),"%d", &id);
        if(id == 0){
            printf("\n\tID invalido.\n\n");
            break;
        }
        for(k=0;k<MAX;k++){
            if(id == contatos[k].id){
                condicao_saida = 1;
            }
        }
        if(condicao_saida == 0){
            for(j=0;j<MAX;j++){
                if(id >= ID_MINIMO && id <= ID_MAXIMO){
                    if(contatos[i].id == 0){
                        contatos[i].id = id;
                        printf("\tNome:\t");
                        fflush(stdin);
                        sscanf(fgets(userInput, MAX-1, stdin),"%[^\n]", contatos[i].nome);
                        printf("\tEmail:\t");
                        fflush(stdin);
                        sscanf(fgets(userInput, MAX-1, stdin),"%s", contatos[i].email);
                        printf("\tCel.:\t");
                        fflush(stdin);
                        sscanf(fgets(userInput, MAX-1, stdin),"%s", contatos[i].celular);
                        fflush(stdin);
                    }
                    break;
                }else{
                    printf("\n\tNumero fora do range (1-10000).\n");
                    break;
                }
            }
        }else{
            printf("\n\tID ja cadastrado.\n\n");
        }
        break;
    }
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}

/**< SOBRESCREVE A POSIÇÃO DO ID INFORMADO NO ARRAY contatos*/

void excluir(){
    clrscr();
    int id = 0, i,g=0, n, s=0, cond1=0;
    char userInput[MAX];
    printf("--------------------------------------------------------\n");
    printf("--------------------EXCLUIR contatos--------------------\n");
    printf("--------------------------------------------------------\n\n");
    if(quantos_contatos() == 0){
        printf("Nenhum registro encontrado.\n");
    }else{
        printf("\tDigite um ID valido (max de 5 digitos inteiros)\n");
        printf("\tID: ");
        sscanf(fgets(userInput, MAX-1, stdin),"%d", &id);
        if(id == 0){
            printf("\n\tID nao pode ser nulo.\n\n");
        }else if(id<1 || id > 10000){
            printf("\tID fora do range.\n\n");
        }else{
            for(i=0;i<quantos_contatos();i++){
                g = quantos_contatos() - i; /**< g = quantos contatos que preciso iterar para sobrescrever o Contato que quero "deletar"*/
                if(id == contatos[i].id){
                    while(s!=1){
                        printf("\n\tConfirmar a exclusao do Contato:\n");
                        printf("\tID: %d\n\tNome: %s\n", contatos[i].id, contatos[i].nome);
                        printf("\t(1) Confirmar.\n\t(2) Sair.\n\t");
                        sscanf(fgets(userInput, MAX-1, stdin),"%d", &n);
                        if(n!=1 && n!=2){
                            printf("\n\tDigite 1 para confirmar ou 2 para sair.");
                        }else if(n==2){
                            cond1 = 1;
                            s = 1;
                            break;
                        }else{
                            while(g!=0){
                                g--;
                                contatos[i].id = contatos[i+1].id;
                                strcpy(contatos[i].nome, contatos[i+1].nome);
                                strcpy(contatos[i].email , contatos[i+1].email);
                                strcpy(contatos[i].celular , contatos[i+1].celular);
                                i++;
                            }
                            s = 1;
                        }
                    }
                }else if(cond1 == 1){
                    break;
                }
            }
        }
    }
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}

/**< EDITA AS INFORMAÇÕES DO ID NO ARRAY contatos */

void alterar(){
    int id,i;
    char userInput[MAX];
    clrscr();
    printf("--------------------------------------------------------\n");
    printf("--------------------ALTERAR contatos--------------------\n");
    printf("--------------------------------------------------------\n\n");
    if(quantos_contatos() == 0){
        printf("Nenhum registro encontrado.\n");
    }else{
        printf("\tDigite um ID valido (max de 5 digitos inteiros)\n");
        printf("\tID: ");
        sscanf(fgets(userInput, MAX-1, stdin),"%d", &id);
        if(id == 0){
            printf("\tid invalido");
        }else if(id < 1 || id > 10000){
            printf("\tid invalido");
        }else{
            for(i=0;i<MAX;i++){
                if(id == contatos[i].id){
                    printf("\n\tDados do Contato\n");
                    printf("\tID: %d\n", id);
                    printf("\tNome: %s\n", contatos[i].nome);
                    printf("\tEmail: %s\n", contatos[i].email);
                    printf("\tCelular: %s\n\n", contatos[i].celular);
                    printf("--------------------------------------------------------\n\n");
                    printf("\t(Caso nao queira alterar, deixe em branco e de Enter)\n\n");
                    printf("\tDigite os novos valores.\n");
                    printf("\tNome:\t");
                    fflush(stdin);
                    sscanf(fgets(userInput, MAX-1, stdin),"%[^\n]", contatos[i].nome);
                    printf("\tEmail:\t");
                    fflush(stdin);
                    sscanf(fgets(userInput, MAX-1, stdin),"%s", contatos[i].email);
                    printf("\tCel.:\t");
                    fflush(stdin);
                    sscanf(fgets(userInput, MAX-1, stdin),"%s", contatos[i].celular);
                    fflush(stdin);
                    break;
                }else if( i == MAX -1){
                    printf("\n\tID não encontrado.\n");
                }
            }
        }
    }
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}

/**< ITERAR TODO ARRAY contatos E IMPRIMIR OS IDS DIFERENTES DE ZERO */

void listar(){
    int i;
    clrscr();
    printf("--------------------------------------------------------\n");
    printf("--------------------LISTAR contatos---------------------\n");
    printf("--------------------------------------------------------\n\n");
    if(quantos_contatos() == 0){
        printf("Nenhum registro encontrado.\n");
    }else{
        for(i=0;i<MAX;i++){
            if(contatos[i].id != 0){
                printf("\tID: %d\n", contatos[i].id);
                printf("\tNome: %s\n", contatos[i].nome);
                printf("\tEmail: %s\n", contatos[i].email);
                printf("\tCelular: %s\n\n", contatos[i].celular);
            }
        }
    }
    printf("\n\n\tPara voltar ao menu, pressione Enter.");
    getchar();
    menu();
}



int sair(){
    clrscr();
    printf("--------------------------------------------------------\n");
    printf("--------------------FINALIZANDO PROGRAMA----------------\n");
    printf("--------------------------------------------------------\n\n");
    getchar();
    return 0;
}

/**< LIMPA A TELA */

void clrscr()
{
    system("@cls||clear");
}

/**< IMPRIME O MENU */

void texto_do_menu(){
    printf("--------------------------------------------------------\n");
    printf("----------------CADASTRO DE contatos--------------------\n");
    printf("--------------------------------------------------------\n\n");
    printf("\t(1) Incluir um novo Contato.\n");
    printf("\t(2) Excluir um Contato existente.\n");
    printf("\t(3) Alterar um Contato existente.\n");
    printf("\t(4) Listar todos contatos.\n");
    printf("\t(5) Sair.\n\n");
    printf("\tUse os indicadores para escolher uma opcao: ");
}

/**< VERIFICA O QUE O USUÁRIO QUER FAZER NO PROGRAMA */

void menu(){
    int opcao = 0;
    char userInput[MAX];
    while(1){
        clrscr();
        texto_do_menu();
        sscanf(fgets(userInput, MAX-1, stdin),"%d", &opcao);
        if(opcao!=1 && opcao!=2 && opcao!=3 && opcao!=4 && opcao!=5){
            printf("\n\n\tDigite uma opcao valida.");
            getchar();
        }else{
            if(opcao == 1){ incluir(); break; }
            if(opcao == 2){ excluir(); break; }
            if(opcao == 3){ alterar(); break; }
            if(opcao == 4){ listar(); break; }
            if(opcao == 5){ sair(); break; }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Portuguese"); /**<habilita a acentuação para o português  */
    popular_array_em_branco();
    menu();
    return 0;
}