#include<stdio.h>
int main(){
	int x = 10, y = 22;
	int * const ptr = &x;
	printf("Gia tri cua ban dau la: %d\n",*ptr);
	*ptr = 25;
	//Loi: ptr = &y;
	printf("Gia tri luc sau la: %d\n",*ptr);
	return 0;
}
//-----Hang con tro tro toi kieu du lieu-----//
//-----Dia chi giu nguyen - Gia tri thay doi-----//
