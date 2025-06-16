#include<stdio.h>
#include<stdbool.h>
#include <conio.h>
bool isBitSet(unsigned char val,int n){
	unsigned int mask = 1 << n;
	return (val & mask) != 0;
}

int main() {
    unsigned char test;
    int pos;
    char ch;
    while(1){
	
    printf("Nhap value: ");
    scanf("%hhu",&test);
    
    printf("Nhap position: ");
    scanf("%d",&pos);
    
    printf("Input: value = %u, n = %d\n", test, pos);
    printf("Output: %s\n", isBitSet(test, pos) ? "true" : "false");
    
 	printf("Nhan ESC de dung, hoac ky tu khac de tiep tuc...\n");
        ch = getch(); 
        if (ch == 27) { 
            break;
        }
        printf("\n");
    }

    printf("Program ended.\n");
    return 0;
}
