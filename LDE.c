#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LDE.h"

void inicializa_LDE( LDE *p, int t ){
   p->tamInfo = t;
   p->cabeca = NULL;
   p->qtd = 0;
}

int LDE_vazia ( LDE l ){
   return l.cabeca == NULL;
}

EleDuplo *aloca_EleDuplo( void *info, int tam ){
	EleDuplo *p = malloc( sizeof(EleDuplo) );
	if( p == NULL )
    	return NULL; // Erro, falta de mem�ria!
	p->info = malloc( tam );
	if( p->info == NULL ){
		free(p);
		return NULL; // Erro, falta de mem�ria!
	} 
	memcpy( p->info, info, tam );
	return p;
}

/*---------------------------------------ALTERAR--------------------*/
/*---------------------------------------ALTERADO-------------------*/
int insere_inicio( LDE *p, void *info ){
    EleDuplo *novo = aloca_EleDuplo( info, p->tamInfo );
    if( novo == NULL )
        return 0; // Erro, falta de mem�ria!
    novo->suc = p->cabeca;
    p->cabeca = novo;
    p->qtd++;
    novo->ant = NULL;
    if( novo->suc != NULL) // <------------- ALTERAÇÃO 
        novo->suc->ant = novo; // <------------- ALTERAÇÃO 
    return 1; // Sucesso!
}

/*---------------------------------------ALTERAR--------------------*/
/*---------------------------------------ALTERADO-------------------*/
int remove_inicio( LDE *p, void *info ){
    if( LDE_vazia( *p ) )
        return ERRO_LDE_VAZIA;

    EleDuplo *aux = p->cabeca;
    memcpy( info, aux->info, p->tamInfo );
    p->cabeca = aux->suc;
    free( aux->info );
    free( aux );
    p->qtd--;
    if(p->cabeca != NULL) // <------------- ALTERAÇÃO 
        p->cabeca->ant = NULL; // <------------- ALTERAÇÃO 
    return 1; // Sucesso!
}

/*---------------------------------------ALTERAR--------------------*/
/*---------------------------------------ALTERADO-------------------*/
int insere_fim( LDE *p, void *info ){
    if( LDE_vazia( *p ) )
        return insere_inicio( p, info );
    EleDuplo *aux = p->cabeca;
    while( aux->suc != NULL )
        aux = aux->suc;
    EleDuplo *novo = aloca_EleDuplo( info, p->tamInfo );
    if( novo == NULL )
        return 0; // Erro, falta de mem�ria!
    aux->suc = novo;
    novo->suc = NULL;
    p->qtd++;
    novo->ant = aux; // <------------- ALTERAÇÃO 
    return 1; // Sucesso!
}

int remove_fim( LDE *p, void *info ){
   if( LDE_vazia( *p ) )
      return ERRO_LDE_VAZIA;
   if( p->qtd == 1 )
      return remove_inicio( p, info );
   EleDuplo *aux = p->cabeca;
   while( aux->suc->suc != NULL )
      aux = aux->suc;
   EleDuplo *ultimo = aux->suc;
   memcpy( info, ultimo->info, p->tamInfo );
   free( ultimo->info );
   free( ultimo );
   aux->suc = NULL;
   p->qtd--;
   return 1; // Sucesso!
}

/*---------------------------------------ALTERAR--------------------*/
/*---------------------------------------ALTERADO-------------------*/
int insere_pos( LDE *p, void *info , int pos ){
    if( pos < 0 || pos > p->qtd )
        return ERRO_POS_INVALIDA;
    if( pos == 0 )
        return insere_inicio( p, info );
    EleDuplo *aux = p->cabeca;
    int cont;
    for( cont = 0 ; cont < pos-1 ; cont++ )
        aux = aux->suc; // Vai at� EleDuplo em pos-1
    EleDuplo *novo = aloca_EleDuplo( info, p->tamInfo );
    if( novo == NULL )
        return 0; // Erro, falta de mem�ria!
    novo->suc = aux->suc;
    aux->suc = novo;
    p->qtd++;
    if( novo->suc != NULL) // <------------- ALTERAÇÃO 
        novo->suc->ant = novo; // <------------- ALTERAÇÃO 
    novo->ant = aux; // <------------- ALTERAÇÃO 
    return 1; // Sucesso!
}

/*---------------------------------------ALTERAR--------------------*/
/*---------------------------------------ALTERADO-------------------*/
int remove_pos( LDE *p, void *info , int pos ){
   if( LDE_vazia( *p ) )
      return ERRO_LDE_VAZIA;

   if( pos < 0 || pos >= p->qtd )
      return ERRO_POS_INVALIDA;
	
   if( pos == 0 )
      return remove_inicio( p, info );
      
   EleDuplo *aux = p->cabeca;
   int cont;
   for( cont = 0 ; cont < pos-1 ; cont++ )
      aux = aux->suc; // Vai at� pos-1
	
   EleDuplo *x = aux->suc;
   aux->suc = x->suc;
   aux->suc->ant = aux; // <------------- ALTERAÇÃO 
   memcpy( info, x->info, p->tamInfo );
   free( x->info );
   free( x );
   p->qtd--;
   return 1; // Sucesso!
}

int le_valor( LDE l, void *info , int pos ){
   if( LDE_vazia( l ) )
      return ERRO_LDE_VAZIA;

   if( pos < 0 || pos >= l.qtd )
      return ERRO_POS_INVALIDA;
		
   EleDuplo *aux = l.cabeca;
   int cont;
   for( cont = 0 ; cont < pos ; cont++ )
      aux = aux->suc; // Vai at� EleDuplo em pos
	
   memcpy( info, aux->info, l.tamInfo );
   return 1; // Sucesso!
}

int modifica_valor( LDE l, void *info , int pos ){
   if( LDE_vazia( l ) )
      return ERRO_LDE_VAZIA;

   if( pos < 0 || pos >= l.qtd )
      return ERRO_POS_INVALIDA;
		
   EleDuplo *aux = l.cabeca;
   int cont;
   for( cont = 0 ; cont < pos ; cont++ )
      aux = aux->suc; // Vai at� EleDuplo em pos
	
   memcpy( aux->info, info, l.tamInfo );
   return 1; // Sucesso!
}

int insere_ordem( LDE *p, void *info , int (*compara)(void*, void*) ){

  EleDuplo *aux = p->cabeca;
  int cont = 0;

  while(aux != NULL && compara(info, aux->info) > 0){
    aux = aux->suc;
    cont++;
  }

  return insere_pos( p, info, cont );

}

void mostra_LDE_inverso( LDE l, void (*mostra)(void *) ){
    if( LDE_vazia( l ) )
        printf("LDE vazia!\n");
    else{
        EleDuplo *p = l.cabeca;
        while( p->suc != NULL )
            p = p->suc;
        printf("Dados da LDE:\n");
        int i = l.qtd-1;
        while( p != NULL && i >= 0){
            printf("[%d] ", i);
            i--;
            mostra( p->info ); // Invoca��o por callback
            p = p->ant;
        }
    }
}

void mostra_LDE( LDE l, void (*mostra)(void *) ){
  if( LDE_vazia( l ) )
    printf("LDE vazia!\n");
  else{
    printf("Dados da LDE:\n");
    EleDuplo *p = l.cabeca;
    int i = 0;
    while( p != NULL ){
    	printf("[%d] ", i);
    	i++;
    	mostra( p->info ); // Invoca��o por callback
    	p = p->suc;
    }
  }
}

int conta_EleDuplos( LDE l ){
	int cont = 0;
	EleDuplo *aux = l.cabeca;
	while( aux != NULL ){
		cont++;
		aux = aux->suc;
	}
	return cont;
}

void desaloca_LDE( LDE *p ){
	EleDuplo *aux = p->cabeca;
	while( aux != NULL ){
		EleDuplo *prox = aux->suc;
		free(aux->info);
		free(aux);
		aux = prox;
	}
	p->cabeca = NULL;
	p->qtd = 0;
}
