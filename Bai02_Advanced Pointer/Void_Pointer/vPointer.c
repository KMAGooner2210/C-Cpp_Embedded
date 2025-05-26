#include<stdio.h>
#include<stdlib.h>

void print_value(void* data,int type){
	switch(type){
	case 0: 
		printf("Int value: %d\n",*(int*)data);
		break;
	case 1:
		printf("Float value: %f\n",*(float*)data);
		break;
	case 2:
		printf("Char value: %c\n",*(char*)data);
	default:
		printf("Invalid!");
	}
}

int main(){

void* ptr = malloc(sizeof(int));
if(ptr == NULL){
	printf("Memory Allocation Failed\n");
	return 1;
}

*(int*)ptr = 42;
print_value(ptr, 0);
free(ptr);

return 0;
}
