
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>


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
Pont inicio;
}Lista;


iniciarLista(Lista* l){
l->inicio = NULL;	
}

int tamanho(Lista* l){
Pont end = l->inicio; 
int tam = 0;

while(end != NULL){
	tam++;
	end = end->prox;
}





	
	
}

exibirLista(Lista* l){
	Pont end = l->inicio;
	printf("Lista:\n");
	while(end != NULL){
		printf("%i\n", end->reg.chave);
        end = end->prox;
}
printf("\n");	
	
}

Pont buscaSequencial(Lista* l, TIPOCHAVE ch){
Pont pos = l->inicio;

while(pos != NULL){
	if(pos->reg.chave == ch){
		return pos;
	}
}
return NULL; 
}


Pont buscaOrdenada(Lista* l, TIPOCHAVE ch){
Pont pos = l->inicio;	
while(pos != NULL && pos->reg.chave < ch){
	pos = pos->prox;
}
if(pos != NULL && pos->reg.chave == ch){
	return pos;  
}	
return NULL;

}

Pont buscaSequencialExc(Lista* l, TIPOCHAVE ch, Pont* ant){

*ant = NULL;	
Pont atual = l->inicio; 	
	
while(atual != NULL && atual->reg.chave < ch){
	
	*ant = atual;
	atual = atual->prox;
}	
if(atual !=NULL && atual->reg.chave == ch){
	return atual;
}	
return NULL;	
	
	
}


bool inserirElemListaOrd(Lista* l, Registro reg){
TIPOCHAVE ch = reg.chave;
Pont i, ant;
i = buscaSequencialExc(l, ch, &ant);	
if(i != NULL){
	return false;
}

i = (Pont) malloc(sizeof(Elemento));
i->reg = reg;

if(ant == NULL){
	i->prox = l->inicio;
	l->inicio = i;
}else{
	 i->prox = ant->prox;
     ant->prox = i;
}

	
	

	
}

bool excluirElemento(Lista *l, TIPOCHAVE ch){

Pont ant, i;
i = buscaSequencialExc(l, ch, &ant);
if(i == NULL){
	return false;
}

if(ant != NULL){
ant->prox = i->prox;	
}else{
l->inicio= i->prox;		
}
free(i);
return true;	
}

reiniciarLista(Lista* l){
	Pont i = l->inicio;
	while(i != NULL){
	Pont apagar = i;
	i = i->prox;
	free(i);
	
		
		
		
		
	}
	
	
}


main(){
	
Lista* l = (Lista*) malloc(sizeof(Lista));

Registro reg, reg1, reg2;
TIPOCHAVE ch = 12;
reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;
Pont ant, r;

iniciarLista(l);
exibirLista(l);
inserirElemListaOrd(l, reg);
inserirElemListaOrd(l, reg1);
inserirElemListaOrd(l, reg2);
exibirLista(l);
excluirElemento(l, ch);
exibirLista(l);
reiniciarLista(l);
}
