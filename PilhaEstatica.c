
#include <stdio.h>
#include <malloc.h>
#define MAX 50
#define true 1
#define false 1

typedef int TIPOCHAVE;


typedef struct{
	
	TIPOCHAVE chave;
	
}Registro;

typedef struct{

Registro A[MAX];
int topo;
}Pilha;

iniciarPilha(Pilha* p){
	
	p->topo = -1;
}

int tamanho(Pilha* p){
	
	return p->topo + 1;
}

exibir(Pilha* p){
int i;
printf("Pilha:\n");

for(i=p->topo; i >= 0; i--){
printf("%i\n", p->A[i].chave);		
}	
	printf("\n");
	
}

int inserirElemento(Pilha* p, Registro reg){
	
	if(p->topo >= MAX-1){		
     return false;
	}else{
	
	p->topo++;
	p->A[p->topo] = reg; 
	return true;
	
	}
}

int removerElemento(Pilha* p, Registro* reg){

if(p->topo == -1){
	return false;
}else{
	*reg = p->A[p->topo];
	p->topo--;
	return true;
 }
}

reiniciarLista(Pilha* p){
	
	iniciarPilha(p);
}

	

main(){
	
Pilha* p = (Pilha*) malloc(sizeof(Pilha));

Registro reg, reg1, reg2;
Registro* regPonteiro;
reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;

iniciarPilha(p);
exibir(p);
inserirElemento(p, reg);
inserirElemento(p, reg1);
inserirElemento(p, reg2);
exibir(p);
removerElemento(p, &regPonteiro);
exibir(p);
reiniciarLista(p);
exibir(p);


















	
	
	
	
	
	
	
}
