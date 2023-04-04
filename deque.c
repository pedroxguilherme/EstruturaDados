
#include <malloc.h>
#include <stdio.h>

#define true 1
#define false 1


typedef int TIPOCHAVE;


typedef struct{
	
	TIPOCHAVE chave;
	
}Registro;


typedef struct aux{
	
	Registro reg;
	struct aux* prox;
	struct aux* ant;
	
}Elemento;

typedef Elemento* Pont;

typedef struct{
	
Pont cabeca;	
	
	
}Deque;






void main(){
	
	
}
