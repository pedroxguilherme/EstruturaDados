
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 1

typedef int TIPOCHAVE;


typedef struct{

TIPOCHAVE chave;	
	
}Registro;

typedef struct aux{
Registro reg;
struct aux* prox;	
}Elemento;

typedef Elemento* Pont;

typedef struct{
Pont topo;		
}Pilha;



void iniciarPilha(Pilha* p){
	
	p->topo = NULL;
}

int tamanho(Pilha* p){
	
Pont end = p->topo;;	
int tam = 0;	
	while(end != NULL){
		tam++;
		end->prox;
	}
	
return tam;	
}

int pilhaVazia(Pilha* p){
	
	
	if(p->topo == NULL){
		return true;
	}
	return false;
}

void exibirPilha(Pilha* p){
	Pont pos = p->topo;
	printf("Pilha:\n");
	while(pos != NULL){
	printf("%i\n", pos->reg.chave);
	pos = pos->prox;	
	}
	printf("\n");
}





int inserirElemento(Pilha* p, Registro reg){
	
	Pont novo = (Pont) malloc(sizeof(Elemento));
	novo->reg = reg;
	novo->prox = p->topo;
	p->topo = novo;
	return true;
}
// Exvluir Elemento do topo da pilha
int excluirElemento(Pilha* p, Registro* reg){
	if(p->topo == NULL){
		return false;
	}
	*reg = p->topo->reg;
	Pont apagar = p->topo;
	p->topo = p->topo->prox;
	free(apagar);
}
void reiniciarPilha(Pilha* p){
	
	Pont end = p->topo;
	
	while(end != NULL){
		Pont apagar = end;
		end = end->prox;
		free(apagar);
	}
}











main(){
	
	Pilha* p = (Pilha*) malloc(sizeof(Pilha));
	
	Registro reg, reg1, reg2;
	Registro* reg4;
	
	reg.chave = 5;
    reg1.chave = 7;
    reg2.chave = 10;

	iniciarPilha(p);
	exibirPilha(p);
	inserirElemento(p, reg);
	inserirElemento(p, reg1);
	inserirElemento(p, reg2);
	exibirPilha(p);
	excluirElemento(p, &reg4);
	printf("%i\n", reg4);
	reiniciarPilha(p);
	
	
	
}
