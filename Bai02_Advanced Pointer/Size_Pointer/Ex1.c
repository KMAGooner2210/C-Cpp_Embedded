#include<stdio.h>
int main(){
	int *iPtr;
	char *cPtr;
	printf("Size cua con tro la: %zu bytes\n",sizeof(*iPtr));
	printf("Size cua con tro la: %zu bytes\n",sizeof(*cPtr));
	printf("Size cua con tro la: %zu bytes\n",sizeof(iPtr));
	printf("Size cua con tro la: %zu bytes\n",sizeof(cPtr));
	return 0;
}
