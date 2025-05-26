#include<stdio.h>
int main(){
	int *ptr;
	int arr[5]={1,2,3,4,5};
	printf("Size: %zu bytes\n",sizeof(ptr));
	printf("Size: %zu bytes\n",sizeof(*ptr));
	printf("Size: %zu bytes\n",sizeof(arr));
	return 0;
}
