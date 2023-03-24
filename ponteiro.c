

#define tam 10

main(){
int a = 3, b = 5;
int *p = &a, *q = &b;	
*p = *p + *q; //8
*q = *p - *q;//3
*p = *p - *q;//5


printf("%d, %d", a, b);
	
	
	
}

