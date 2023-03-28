
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
Pont cabeca;
}Lista; 






iniciarLista(Lista* l){
	l->cabeca = (Pont) malloc(sizeof(Elemento));
	l->cabeca->prox = l->cabeca;
}

int tamanho(Lista* l){
	int tam = 0;
	Pont end = l->cabeca->prox;
	while(end != l->cabeca){
		
		tam++;
		end = end->prox;	
	}
	return tam;
}

exibirLista(Lista* l){
	
	Pont end = l->cabeca->prox;
	printf("Lista:\n");
	while(end != l->cabeca){
		printf("%i\n", end->reg.chave);
		end = end->prox;
	}
	printf("\n");
}

Pont buscaSentinela(Lista* l, TIPOCHAVE ch){
	Pont pos = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	
	while(pos->reg.chave != ch){
		pos = pos->prox;
	}
	if(pos != l->cabeca ){
		return pos;
	}
	return NULL;
}

Pont buscaSentinelaOrd(Lista* l, TIPOCHAVE ch){
	
	Pont pos = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	
	while(pos->reg.chave < ch ){
		pos = pos->prox;
	}
	if(pos != l->cabeca){
		return pos;
	}
	return NULL;
}
Pont buscaSeqAux(Lista* l, TIPOCHAVE ch, Pont* ant){
	
	*ant = l->cabeca;
	Pont atual = l->cabeca->prox;
	l->cabeca->reg.chave = ch;
	while(atual->reg.chave<ch){
		
		*ant = atual;
		atual = atual->prox;	
	}
	if(atual->reg.chave == ch && atual != l->cabeca){
		return atual;
	}
	return NULL;
}


bool adicionarElemento(Lista* l, Registro reg){
	Pont ant, i;
	i = buscaSeqAux(l, reg.chave, &ant);
	if(i != NULL){
		return false;
	}
	i = (Pont) malloc(sizeof(Elemento));
	i->reg = reg;
	i->prox = ant->prox;
	ant->prox = i;
	return true;
}

bool removerElemento(Lista* l, TIPOCHAVE ch){
	Pont ant, i;
	i = buscaSeqAux(l, ch, &ant);
	if(i == NULL){
		return false;
	}
	ant->prox = i->prox;
	free(i);
}

reiniciarLista(Lista* l){
	Pont end = l->cabeca->prox;
	while(end != l->cabeca){
		Pont apagar = end;
		end = end->prox;
		free(apagar);
	}
	
}





main(){
	
Lista* l = (Lista*) malloc(sizeof(Lista));

Registro reg, reg1, reg2;
TIPOCHAVE ch = 12;
reg.chave = 40;
reg1.chave = 12;
reg2.chave = 24;

iniciarLista(l);
exibirLista(l);

adicionarElemento(l, reg);	
adicionarElemento(l, reg1);	
adicionarElemento(l, reg2);	
exibirLista(l);
removerElemento(l, ch);
exibirLista(l);
reiniciarLista(l);

}
