#define max 5

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;


typedef struct{	
TIPOCHAVE chave;
int idade;
}Registro;


typedef struct{
	
Registro reg[max];
int nroElem;
}Lista;



iniciar(Lista* l){
	
l->nroElem = 0;	
	
}



exibir(Lista* l){
int i;
printf("Lista:");
for(i = 0; i < l->nroElem; i++){
	
	printf("%d ", l->reg[i].idade);
    printf("\n");
}
}


int buscaSequencial(Lista* l, TIPOCHAVE ch){
int i = 0;

while(i < l->nroElem){
	
	if(ch == l->reg[i].chave){
	return i;
	
	}else{
		i++;
	}
	
}
return -1;
}

bool inserir(Lista* l, Registro reg, int i){
	int j;
	
	if(i > l->nroElem || i < 0 || l->nroElem == max){
		return false;
	}
	else{
		for(j = l->nroElem; j < i; j-- ){
			
			l->reg[j] = l->reg[j-1];
		}
		l->reg[i] = reg;
		l->nroElem++;
		return true;
	}
	
	
	
	
	
	
	
	
}	
	
bool excluir(Lista* l, TIPOCHAVE ch){

int j;
int pos = buscaSequencial(l, ch);
if(pos = -1){
	return false;
}else{
	for(j = pos; j < l->nroElem; j++){
		l->reg[j] = l->reg[j + 1];
	}
	
	return true;
}




	
}	
	
	
reiniciarLista(Lista* l){
	l->nroElem = 0;	
}	
	





main (){

	
Lista* l = (Lista*) malloc(sizeof(Lista));
Registro reg;
reg.idade = 18;
TIPOCHAVE ch = 0;



iniciar(l);




inserir(l, reg, 0);
exibir(l);

bool c1 = buscaSequencial(l, ch);
printf("%d", c1);
//bool c1 = excluir(l, ch);
//printf("%d", c1);
exibir(l);









}
