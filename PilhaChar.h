<<<<<<< HEAD
#define ERRO_PILHA_VAZIA - 1
#define ERRO_PILHA_CHEIA - 2

typedef struct{
	char *dados;
	int topo;
	int capacidade;
}PilhaChar;

void inicializa_pilha_char( PilhaChar *p, int c );
int pilha_vazia_char( PilhaChar p );
int pilha_cheia_char( PilhaChar p );
int empilha_char( PilhaChar *p, char info );
int desempilha_char( PilhaChar *p, char *info );
int le_topo_char( PilhaChar p, char *info );
void mostra_pilha_char( PilhaChar p );
void desaloca_pilha_char( PilhaChar *p );

=======
#define ERRO_PILHA_VAZIA - 1
#define ERRO_PILHA_CHEIA - 2

typedef struct{
	char *dados;
	int topo;
	int capacidade;
}PilhaChar;

void inicializa_pilha_char( PilhaChar *p, int c );
int pilha_vazia_char( PilhaChar p );
int pilha_cheia_char( PilhaChar p );
int empilha_char( PilhaChar *p, char info );
int desempilha_char( PilhaChar *p, char *info );
int le_topo_char( PilhaChar p, char *info );
void mostra_pilha_char( PilhaChar p );
void desaloca_pilha_char( PilhaChar *p );

>>>>>>> dd2b7def938b321b19d26d010f6da908e83abb52
