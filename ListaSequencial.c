#define max 50

#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>

typedef int TIPOCHAVE;


typedef struct{	
TIPOCHAVE chave;
}Registro;


typedef struct{
	
Registro reg[max+1];
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
//pos = buscaSequencial(l, ch);  
//pos = buscaSentinela(l, ch);  
pos = buscaBinaria(l, ch);


if(pos == -1){
	return false;

}

	for(j = pos; j < l->nroElem-1; j++){
		l->reg[j] = l->reg[j + 1];
	
}
 
    l->nroElem--;
	return true;

}

reiniciarLista(Lista* l){
	l->nroElem = 0;	
}	
	
int buscaSentinela(Lista* l, TIPOCHAVE ch){
	int i = 0;
	l->reg[l->nroElem].chave = ch;
    while(l->reg[i].chave != ch){
 	i++;
	}
    if(i == l->nroElem){
	return -1;
	}
	else{
    return i;
	}
	
	
	
	
	
	
	
}	
	


bool inserirOrd(Lista* l, Registro reg){
	
	if(l->nroElem >= max){
		return false;
	}
	int pos = l->nroElem;
	while(pos > 0 && l->reg[pos-1].chave > reg.chave){
		
		l->reg[pos] = l->reg[pos-1];
		pos--;
	}
    
    l->reg[pos] = reg; 
	l->nroElem++;


	
}	
	
int buscaBinaria(Lista* l, TIPOCHAVE ch){
	int esq, dir, meio;
	esq = 0;
	dir = l->nroElem-1;
	
	
	while(esq <= dir){
		meio = ((esq + dir) / 2);
		if(l->reg[meio].chave == ch){
			return meio;
		}
		else{
			if(l->reg[meio].chave < ch){
				esq = meio + 1;
				
			}else{
				dir = meio - 1;
			}
		}	
	}
	return -1;	
}	
	
	
	
main(){

	
Lista* l = (Lista*) malloc(sizeof(Lista));
Registro reg;
TIPOCHAVE ch = 12;
Registro reg1;
Registro reg2;
reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;





iniciar(l);
inserirOrd(l, reg);
inserirOrd(l, reg1);
inserirOrd(l, reg2);
/*
inserir(l, reg, 0);
inserir(l, reg1, 1);
inserir(l, reg2, 2);
*/


exibir(l);
excluir(l, ch);
exibir(l);
reiniciarLista(l);
exibir(l);



}
