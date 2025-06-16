#include<stdio.h>
#include<conio.h>

unsigned char toggleBit(unsigned char val, int n){
	unsigned char mask = 1 << n;
	return val ^ mask;
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
		printf("Input: val: %hhu, pos: %d\n", test, pos);
		printf("Output: %u\n", toggleBit(test, pos));
		
		printf("Nhan ESC de thoat, ky tu khac de tiep tuc!\n");
		ch = getch();
		if(ch == 27){
			break;
		}	
	}
	printf("End.\n");
	return 0;
}
