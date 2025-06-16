#include<stdio.h>
#include<conio.h>

unsigned char bitSet(unsigned char val, int n){
	unsigned char mask = 1 << n;
	return val | mask;
}

int main(){
	unsigned char test;
	int pos;
	char ch;
	
	while(1){
		printf("Nhap val: ");
		scanf("%hhu",&test);
		
		printf("Nhap pos: ");
		scanf("%d",&pos);
		
		printf("Input: val = %hhu , pos = %d\n", test, pos);
		unsigned char result = bitSet(test,pos);
		printf("Output: %hhu\n",result);
		
		printf("Nhap ESC de dung, ky tu khac de tiep tuc.\n");
		ch = getch();
		if(ch == 27){
			break;
		}	
	}
	printf("End.\n");
	return 0;
}
