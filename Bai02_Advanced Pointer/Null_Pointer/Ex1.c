#include<stdio.h>
#include<stdlib.h>

int main(){
	int* ptr;
	ptr = NULL;
	if(ptr == NULL){
		printf("Con tro la NULL.\n");
	}else{
		printf("Con tro khong phai la NULL.\n");
	}
	return 0;
}