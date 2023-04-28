#include <stdio.h>
#include "PilhaEstatica.h"
#include "FilaEstatica.h"
#include <ctype.h>





main(){


Pilha* p = (Pilha*) malloc(sizeof(Pilha));
Fila* f = (Fila*) malloc(sizeof(Fila));
Registrop reg;
Registrof reg1;
char s[50];
int i;
printf("Frase:");
gets(s);	

for(i = 0; s[i] < 50; i++){
	

	reg.letra = s[i];
	reg1.letra = s[i];
	inserirElementoFila(f, reg1);	
	inserirElementoPilha(p, reg);	
	
}



exibirFila(f);
exibirPilha(p);

}
