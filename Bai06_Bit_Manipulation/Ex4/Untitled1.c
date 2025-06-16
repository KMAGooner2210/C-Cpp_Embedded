#include<stdio.h>
#include<conio.h>

unsigned char clearBit(unsigned char val, int n){
	
	if (n < 0 || n >= 32) { //Gia su he 32bit
        printf("Loi: Vi tri bit phai tu 0 den 31!\n");
        return val; 
    }
	unsigned char mask = 1 << n;
	return val &~ mask;
}

int main(){
	char ch;
	unsigned char test;
    int pos;
	
	while(1){
		printf("Nhap val: ");
		scanf("%hhu",&test);
		printf("Nhap pos: ");
		scanf("%d",&pos);
		printf("Input:  val: %hhu, pos: %d\n",test,pos);
		printf("Output: %hhu\n", clearBit(test,pos));
		
		printf("Nhan ESC de thoat, nhan ky tu khac de tiep tuc!\n");
		ch = getch();
		if(ch == 27){
			break;
		}
	}
	printf("End.\n");
	return 0;
}
