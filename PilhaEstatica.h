#ifndef PILHAESTATICA_H
#define PILHAESTATICA_H
#define MAX 50
typedef int TIPOCHAVE;

typedef struct{
	char letra;
    TIPOCHAVE chave;
	
}Registrop;

typedef struct{

Registrop A[MAX];
int topo;
}Pilha;


void iniciarPilha(Pilha*);
int tamanhoPilha(Pilha*);
void exibirPilha(Pilha*);
int inserirElementoPilha(Pilha*, Registrop);
int removerElemento(Pilha*, Registrop*);
void reiniciarPilha(Pilha*);


#endif 
