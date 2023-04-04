
#include <stdio.h>
#include <malloc.h>

#define true 1
#define false 0
#define max 50


typedef int bool;
typedef int TIPOCHAVE;

typedef struct{
	
TIPOCHAVE chave;	
}Registro;


typedef struct{
	
Registro A[max];
int inicio;
int nroElemento;		
}Fila;

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
	printf("%i\n", f->A[i].chave);
	i = (i + 1) % max;
	
}



}

bool inserirElementoFila(Fila* f, Registro reg){
	
    if(f->nroElemento >= max){
    	return false;
	}	
	int posicao = (f->inicio + f->nroElemento) % max;
	f->A[posicao] = reg;
	f->nroElemento++;
	return true;
	
}
bool excluirElementoFila(Fila* f, Registro* reg){
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


main(){
	
Fila* f = (Fila*) malloc(sizeof(Fila));	
	
Registro reg, reg1, reg2, *reg3;

reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;

iniciarFila(f);
exibirFila(f);
inserirElementoFila(f, reg);
inserirElementoFila(f, reg1);
inserirElementoFila(f, reg2);
exibirFila(f);	
excluirElementoFila(f, &reg3);
exibirFila(f);	
reiniciarFila(f);

	
}
