
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
#define max 50
#include "FilaEstatica.h"






void iniciarFila(Fila* f){

f->nroElemento = 0;
f->inicio = 0;

}

int tamanhoFila(Fila* f){
	
	return f->nroElemento;
}




void exibirFila(Fila* f){
int i = f->inicio;
int temp;
printf("Fila:\n");

for(temp = 0; temp < f->nroElemento; temp++){
	printf("%c", f->A[i].letra);
	i = (i + 1) % max;
	
}

printf("\n");

}

int inserirElementoFila(Fila* f, Registro reg){
	
    if(f->nroElemento >= max){
    	return false;
	}	
	int posicao = (f->inicio + f->nroElemento) % max;
	f->A[posicao] = reg;
	f->nroElemento++;
	return true;
	
}
int excluirElementoFila(Fila* f, Registrof* reg){
	if(f->nroElemento == 0){
		return false;
	}
	*reg = f->A[f->inicio];
	f->inicio = (f->inicio + 1) % max;
	f->nroElemento--;
	return true;
}


void reiniciarFila(Fila* f){
	iniciarFila(f);
}
/*
main(){
	
Fila* f = (Fila*) malloc(sizeof(Fila));	
	
Registrof reg, reg1, reg2, *reg3;

reg.chave = 40;
reg.letra = 'a';
reg1.chave = 12;
reg1.letra = 'b';
reg2.chave = 24;
reg2.letra = 'c';

iniciarFila(f);
exibirFila(f);
inserirElementoFila(f, reg);
inserirElementoFila(f, reg1);
inserirElementoFila(f, reg2);
exibirFila(f);	
excluirElementoFila(f, &reg3);
exibirFila(f);	


	
}*/
