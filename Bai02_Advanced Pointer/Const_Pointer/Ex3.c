#include<stdio.h>
void pVal(const int * const ptr){
	printf("Gia tri la: %d\n",*ptr);
	// *ptr = 40; Loi: khong the thay doi gia tri
	// ptr = NULL; Loi: khong the thay doi dia chi
}
int main(){
	int x = 22;
	const int * const ptr = &x;
	pVal(ptr);
	return 0; 
}
