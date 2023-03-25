#define max 5

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;


typedef struct{	
TIPOCHAVE chave;
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
printf("Lista:\n");

for(i = 0; i < l->nroElem; i++){
	
	printf("%d ", l->reg[i].chave);
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

int j, pos;
pos = buscaSequencial(l, ch);  
if(pos == -1){
	return false;

}

	for(j = pos; j < l->nroElem; j++){
		l->reg[j] = l->reg[j + 1];
	
}
 
    l->nroElem--;
	return true;

}




	

	
	
reiniciarLista(Lista* l){
	l->nroElem = 0;	
}	
	





main (){

	
Lista* l = (Lista*) malloc(sizeof(Lista));
Registro reg;
TIPOCHAVE ch = 0;
Registro reg1;
Registro reg2;
reg.chave = 0;
reg1.chave = 1;
reg2.chave = 2;





iniciar(l);




inserir(l, reg, 0);
inserir(l, reg1, 1);
inserir(l, reg2, 2);
exibir(l);
excluir(l, ch);
exibir(l);
reiniciarLista(l);
exibir(l);












}
