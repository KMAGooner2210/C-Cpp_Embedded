#include<stdio.h>
#include<string.h>
#include<conio.h>
char * decToBin(unsigned char val){
	static char bin[9];
	bin[8] = '\0';
	
	for(int i = 7; i >= 0; i--){
		if(val & (1 << i)){
			bin[7-i] = '1';
		}else{
			bin[7-i] = '0';
		}
	}
	return bin;
}

int main(){
	unsigned char test;
	char ch;
	while(1){
	
	printf("Input: ");
	scanf("%hhu",&test);
	printf("Output: %s\n",decToBin(test));
	
	printf("Nhan ESC de dung, ky tu khac de tiep tuc.\n");
	ch = getch();
	if(ch == 27){
		break;
	}
}
	printf("End.\n");
	return 0;
}
