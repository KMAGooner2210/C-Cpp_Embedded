#include<stdio.h>
#include<stdarg.h>

int sum_int(int count,...){
	va_list ap;
	va_start(ap, count);
	int total = 0;
	for(int i=0; i<count; i++){
		total += va_arg(ap,int);
	}
	va_end(ap);
	return total;
}

double sum_double(int count,...){
	va_list ap;
	va_start(ap,count);
	double total = 0.0;
	for(int i=0; i<count; i++){
		total += va_arg(ap,double);
	}
	va_end(ap);
	return total;
}

int main(){
	printf("Sum of integers: %d\n",sum_int(3, 1, 2, 3));
	printf("Sum of double: %.2f\n",sum_double(3, 1.5, 2.5, 3.5));
	return 0;
}
		