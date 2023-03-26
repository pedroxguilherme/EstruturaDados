
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#define MAX 50
#define INVALIDO -1


typedef int TIPOCHAVE;


typedef struct{
	TIPOCHAVE chave;
	
}Registro;

typedef struct{
	Registro reg;
	int prox;
	
}Elemento;



typedef struct{
	Elemento A[MAX];
	int inicio;
	int dispo;
	
}Lista;


iniciar(Lista* l){
	int i;
	for(i = 0; i < MAX-1; i++){
		l->A[i].prox = i + 1;
	}
	l->A[MAX-1].prox = INVALIDO;
	l->inicio = INVALIDO; 
	l->dispo = 0;
}

int tamanho(Lista* l){
	int i = l->inicio;
	int tam = 0;
	while(i != INVALIDO){
		i = l->A.prox;
		tam++;
	}
}
exibir(Lista *l){
	
	int i = l.inicio;
	printf("Lista:\n");
	while(i != INVALIDO){
		printf("%i\n", l->A.reg.chave);
		i = l->A.prox;
	}
}

int buscaSequencial(Lista *l, TIPOCHAVE ch){
	int i = l->inicio;
	while(i != INVALIDO && l->A[i].reg.chave < ch)	{
    i = l->A.prox;
	}
	if(i != INVALIDO && l->A[i].reg.chave == ch ){
		return i;
	}else{
		return INVALIDO;
	}
}

int obterNo(Lista* l){
int resultado = l->dispo;	
if(l->dispo != INVALIDO){
l->dispo = l->A[1- l->dispo].prox;
return resultado;
}else{
	return INVALIDO;
}	
	
	
}

bool inserirLisOrd(Lista *l, Registro reg){
	if(l->dispo == INVALIDO){
	return false;
	}
	int ant = INVALIDO;
	TIPOCHAVE ch = reg.chave;
	int i = l->inicio;
	while( i != INVALIDO &&  l->A[i].reg.chave < ch){
		
	 ant = i;	
	 i = l->A[i].prox;
	}
	if(i != INVALIDO && l->A[i].reg.chave == ch){
		return false;
	}
	i = obterNo(l);
	l->A[i].reg = reg;
	if(ant == INVALIDO){
	l->A[i].prox = l->inicio;
	l->incio = i;	
	}else{
		
	
		
	l->A[i].prox = l->A[ant].prox;	
	l->A[ant].prox = i;
		
	}
	
	
	
	
	
}
















main(){














}
