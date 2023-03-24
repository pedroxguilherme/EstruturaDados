
#include <stdlib.h>
#include <stdio.h>
#include <locale.h>
#define tam 10

struct data{

int dia;
int mes;
int ano;
}


main(){
setlocale(LC_ALL, "Portuguese");	

struct data data1;	
char ch=  'c';
int vetor[10], c, a = 2;
int *din = malloc(sizeof(int));
int *p = &a;
*din = 6;



for(c = 0; c < tam; c++){
	vetor[c] = c + 10;
}
	for(c = 0; c < tam; c++){
	printf("%i\n", vetor[c]);	
}	

printf("______________________________________________________\n");


data1.ano = 2023;
data1.dia = 20;
data1.mes = 3;
printf("Data:\n");
printf("%d|%d|%d\n", data1.dia, data1.mes, data1.ano);
printf("______________________________________________________\n");




printf("Valor da variavel:%d\n", a);	
printf("Valor do endereço da variavel:%d\n", &a);		
printf("Valor do ponteiro:%d\n", *p);	
printf("Valor do endereço do ponteiro:%d\n", p);
printf("______________________________________________________\n");	





printf("Valor do char:%d\n", ch);	
printf("Valor do endereço da variavel char:%d\n", &ch);
printf("______________________________________________________\n");



printf("Valor da variavel dinamica:%d\n", *din);
printf("Valor do endereço da variavel dinamica:%d\n", din);
free(din);

}
