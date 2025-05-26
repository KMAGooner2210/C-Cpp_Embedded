#include<stdio.h>

int main(){

	int var = 10;
	int *ptr=&var;
	int **pptr=&ptr;
	
	printf("Gia tri cua var(truy cap truc tiep):%d\n",var);
	printf("Gia tri cua var(qua con tro *ptr):%d\n",*ptr);
	printf("Gia tri cua var(qua con tro **pptr):%d\n",**pptr);
	
	return 0;
}