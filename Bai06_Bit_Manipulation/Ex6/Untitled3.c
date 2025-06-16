#include<stdio.h>
#include<conio.h>

char * decToBin(unsigned char binVal){
	static char bin[9];
	bin[8]='\0';
	for(int i = 7; i >= 0; i--){
		if(binVal & (1<<i)){
			bin[7-i] = '1';
		}else{
			bin[7-i] = '0';
		}
	}
	return bin;
}

unsigned int countBit(unsigned char val){
	unsigned int count = 0;
	for(int i = 7; i >= 0; i--){
		if(val & (1<<i)){
			count++;
		}
	}
	return count;
}

int main(){
	char ch;
	unsigned char test;
	while(1){
		printf("Nhap gia tri tu 0 den 255: ");
        scanf("%hhu", &test);
        
       
        printf("Input: value: %hhu, binary: %s\n", test, decToBin(test));
        
        printf("Output: So bit 1 la: %d\n", countBit(test));


        printf("Nhan ESC de dung, ky tu khac de tiep tuc.\n");
        ch = getchar();
        if (ch == 27) { 
            break;
        }
    }
    printf("End.\n");
    return 0;
}
	

