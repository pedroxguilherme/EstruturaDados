
#include <stdio.h>
#include <stdlib.h>
#define true 1
#define false 0

typedef int TIPOCHAVE;
typedef int bool;


typedef struct aux{
	
TIPOCHAVE chave;
struct aux *esq;
struct aux *dir;	
}NO;


typedef NO* PONT;




PONT iniciaArvore(){
	return NULL;
}


PONT adiciona(PONT raiz, PONT no){
	if(raiz == NULL){
		return no;	
	}
	if(no->chave < raiz->chave)
	{
	raiz->esq = adiciona(raiz->esq, no);			
	}else{
	raiz->dir = adiciona(raiz->dir, no);		
	}
	return raiz;
	
}

PONT criaNovoNo(TIPOCHAVE ch){
PONT novoNo = (PONT) malloc(sizeof(NO))	;
novoNo->dir= NULL;
novoNo->esq = NULL;
novoNo->chave = ch;
return novoNo;	
}







PONT pesquisa(PONT raiz, TIPOCHAVE ch){
	if(raiz == NULL){
		return NULL;
	}
	if(raiz->chave == ch){
		return raiz;
	}
	if(raiz->chave > ch){	
	return pesquisa(raiz->esq, ch);
}
	return pesquisa(raiz->dir, ch);
	
	
	
}


int contArvore(PONT raiz){

	if(raiz == NULL){
			return 0;
	}
	return (contArvore(raiz->esq) + 1 + contArvore(raiz->dir));


}

PONT buscaNo(PONT raiz, TIPOCHAVE ch, PONT* pai){
	PONT atual = raiz;
	*pai = NULL;
	while(atual){
		if(atual->chave == ch){
			return atual;
		}
		*pai = atual;
		if(ch < atual->chave)
		
         atual = atual->esq;
         else{
         atual = atual->dir;	
		 }	
	}
	return NULL;
}


PONT removerNo(PONT raiz, TIPOCHAVE ch){
	
	PONT pai, no, p, q;
	no = buscaNo(raiz, ch, &pai);
	if(no == NULL){
		return raiz;
	}
	
	if(!no->dir || !no->esq){
		if(!no->esq){
			q = no->dir
		}	
	}
	else{
	 p = no;
	 q = no->esq;	
	 while(q->dir){
	 p = q;
	 q = q->dir;	
     }
	 if(p != no){
	 	p->dir = q->esq;
	 	q->esq = no->dir;
	 }
	q->dir = no->dir	
	}
	if(!pai){
		free(no);
		return q;
	}
	if(ch < pai->chave){
		pai->esq = q;
		
	}else{
		pai->dir = q;
	}
	free(no);
	return raiz;
}




















void exibirArvore(PONT raiz){
	
	if(raiz != NULL){
		printf("%i", raiz->chave);
		printf("(");
		exibirArvore(raiz->esq);
		exibirArvore(raiz->dir);
		printf(")");
		
	}
}







void main(){


PONT r = iniciaArvore();
PONT no = criaNovoNo(23);
r = adiciona(r, no);
no = criaNovoNo(12);
r = adiciona(r, no);
no = criaNovoNo(24);
r = adiciona(r, no);


PONT p = pesquisa(r, 12);
//printf("%i", contArvore(r));
//exibirArvore(r);

}


