
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
		i = l->A[i].prox;
		tam++;
	}
}
exibir(Lista *l){
	
	int i = l->inicio;
	printf("Lista:\n");
	while(i != INVALIDO){
		printf("%i\n", l->A[i].reg.chave);
		i = l->A[i].prox;
	}
}

int buscaSequencial(Lista *l, TIPOCHAVE ch){
	int i = l->inicio;
	while(i != INVALIDO && l->A[i].reg.chave < ch)	{
    i = l->A[i].prox;
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
l->dispo = l->A[l->dispo].prox;
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
	l->inicio = i;	
	}else{
		

	l->A[i].prox = l->A[ant].prox;	
	l->A[ant].prox = i;
	}
	
	return true;
}






bool excluirElemento(Lista *l, TIPOCHAVE ch){
	
	int ant = INVALIDO;
	int i = l->inicio;
	
	while(i != INVALIDO &&  l->A[i].reg.chave<ch){
		ant = i;
		i = l->A[i].prox;
	}
	if(i == INVALIDO || l->A[i].reg.chave != ch){
		return false;
	}
    if(ant == INVALIDO){
    	l->inicio = l->A[i].prox;
	}else{
		l->A[ant].prox = l->A[i].prox;
	}
	devolverNo(l, i);
	return true;
	
}

devolverNo(Lista* l, int j){
	l->A[j].prox = l->dispo;

}

reiniciarLista(Lista* l){
	iniciar(l);
}


main(){

Lista* l = (Lista*) malloc(sizeof(Lista));

Registro reg, reg1, reg2;
TIPOCHAVE ch = 12;
reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;


iniciar(l);
exibir(l);
inserirLisOrd(l, reg);
inserirLisOrd(l, reg1);
inserirLisOrd(l, reg2);
exibir(l);
excluirElemento(l, ch);
exibir(l);
reiniciarLista(l);
exibir(l);



}
