#ifndef FILAESTATICA_H
#define FILAESTATICA_H
#define max 50

typedef int TIPOCHAVE;


typedef struct{
TIPOCHAVE chave;
char letra;
	
}Registrof;


typedef struct{
	
Registrof A[max];
int inicio;
int nroElemento;		
}Fila;





void iniciarFila(Fila*);
int tamanhoFila(Fila*);
void exibirFila(Fila*);
int inserirElementoFila(Fila*, Registrof);
int excluirElementoFila(Fila*, Registrof*);
void reiniciarFila(Fila*);


#endif 
