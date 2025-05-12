#include<stdio.h>
#include<assert.h>
#include<string.h>

void print_String(char *str){
	assert(str != NULL);
	printf("Length: %s\n",strlen(str));
	
}

int main(){
	char *test = NULL;
	print_String(test);
	return 0;
}