<<<<<<< HEAD
#include <stdio.h>
#include <stdlib.h>
#include "PilhaChar.h"

void inicializa_pilha_char( PilhaChar *p, int c ){
	p->dados = malloc( sizeof(char) * c );
	p->capacidade = c;
	p->topo = -1;	
}

int pilha_vazia_char( PilhaChar p ){
	return p.topo == -1;
}

int pilha_cheia_char( PilhaChar p ){
	return p.topo == p.capacidade - 1;
}

int empilha_char( PilhaChar *p, char info ){
	if( pilha_cheia_char( *p ) )
		return ERRO_PILHA_CHEIA;
	
	p->topo++;
	p->dados[p->topo] = info;
	return 1; // Sucesso	
}

int desempilha_char( PilhaChar *p, char *info ){
	if( pilha_vazia_char( *p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo_char( PilhaChar p, char *info ){
	if( pilha_vazia_char( p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p.dados[p.topo];
	return 1; // Sucesso
}

void mostra_pilha_char( PilhaChar p ){
	if( pilha_vazia_char( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha: ");
		for( i = 0; i <= p.topo ; i++ )
			printf("%c", p.dados[i]);
		printf("\n\n");
	}
}

void desaloca_pilha_char( PilhaChar *p ){
	free( p->dados );
}

=======
#include <stdio.h>
#include <stdlib.h>
#include "PilhaChar.h"

void inicializa_pilha_char( PilhaChar *p, int c ){
	p->dados = malloc( sizeof(char) * c );
	p->capacidade = c;
	p->topo = -1;	
}

int pilha_vazia_char( PilhaChar p ){
	return p.topo == -1;
}

int pilha_cheia_char( PilhaChar p ){
	return p.topo == p.capacidade - 1;
}

int empilha_char( PilhaChar *p, char info ){
	if( pilha_cheia_char( *p ) )
		return ERRO_PILHA_CHEIA;
	
	p->topo++;
	p->dados[p->topo] = info;
	return 1; // Sucesso	
}

int desempilha_char( PilhaChar *p, char *info ){
	if( pilha_vazia_char( *p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p->dados[p->topo];
	p->topo--;
	return 1; // Sucesso
}

int le_topo_char( PilhaChar p, char *info ){
	if( pilha_vazia_char( p ) )
		return ERRO_PILHA_VAZIA;
		
	*info = p.dados[p.topo];
	return 1; // Sucesso
}

void mostra_pilha_char( PilhaChar p ){
	if( pilha_vazia_char( p ) )
		printf("Pilha vazia!\n\n");
	else{
		int i;
		printf("Dados da pilha: ");
		for( i = 0; i <= p.topo ; i++ )
			printf("%c", p.dados[i]);
		printf("\n\n");
	}
}

void desaloca_pilha_char( PilhaChar *p ){
	free( p->dados );
}

>>>>>>> dd2b7def938b321b19d26d010f6da908e83abb52
