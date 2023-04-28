
#include <stdio.h>
#include <malloc.h>
#define MAX 50
#define true 1
#define false 1
#include "PilhaEstatica.h"



void iniciarPilha(Pilha* p){
	
	p->topo = -1;
}

int tamanhoPilha(Pilha* p){
	
	return p->topo + 1;
}

void exibirPilha(Pilha* p){
int i;
printf("Pilha:\n");

for(i=p->topo; i >= 0; i--){
printf("%c", p->A[i].letra);		
}	
	printf("\n");
	
}

int inserirElementoPilha(Pilha* p, Registrop reg){
	
	if(p->topo >= MAX-1){		
     return false;
	}else{
	
	p->topo++;
	p->A[p->topo] = reg; 
	return true;
	
	}
}

int removerElemento(Pilha* p, Registrop* reg){

if(p->topo == -1){
	return false;
}else{
	*reg = p->A[p->topo];
	p->topo--;
	return true;
 }
}

void reiniciarPilha(Pilha* p){
	
	iniciarPilha(p);
}

	
	/*
main(){

Pilha* p = (Pilha*) malloc(sizeof(Pilha));

Registrop reg, reg1, reg2;
Registrop* regPonteiro;
reg.chave = 40;
reg.letra = 'a';
reg1.chave = 12;
reg1.letra = 'b';
reg2.chave = 24;
reg2.letra = 'c';

iniciarPilha(p);
exibirPilha(p);
inserirElementoPilha(p, reg);
inserirElementoPilha(p, reg1);
inserirElementoPilha(p, reg2);
exibirPilha(p);
removerElemento(p, &regPonteiro);
exibirPilha(p);
reiniciarPilha(p);
exibirPilha(p);

	
}*/
