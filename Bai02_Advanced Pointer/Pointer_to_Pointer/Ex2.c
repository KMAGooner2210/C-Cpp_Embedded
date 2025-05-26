#include<stdio.h>
#include<stdlib.h>

void allocate_string(char** str_ptr, int size){
	*str_ptr = malloc(size * sizeof(char));
	if(*str_ptr == NULL){
		printf("Cap phat bo nho that bai!");
		exit(1);
	}
}

int main(){
	char *str = NULL;
	allocate_string(&str, 20);
	
	if(str != NULL){
		printf("Cap phat bo nho thanh cong\n");
		snprintf(str, 20, "Hello KMA");
		printf("Chuoi sau khi gan: %s\n",str);
	}else{
		printf("Cap phat bo nho that bai.\n");
	}
	free(str);
	str = NULL;
	return 0;
	
}