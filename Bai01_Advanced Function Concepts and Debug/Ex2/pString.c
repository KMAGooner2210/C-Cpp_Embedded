#include<stdio.h>
#include<stdarg.h>

void print_string(const char *first,...){
	va_list ap;
	va_start(ap, first);
	const char *str = first;
	while(str != NULL){
		printf("%s\n",str);
		str = va_arg(ap, const char*);
	}
	va_end(ap);
}

int main(){
	print_string("KMA","DTVT","KETC",NULL);
	return 0;
	}