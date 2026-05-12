// ## **Ex5.	Đảo Bit Thứ n**

// o	Yêu cầu: Viết hàm đảo (toggle) bit thứ n của một số nguyên không dấu (từ 0 thành 1 hoặc 1 thành 0).
// ```
// o	Ví dụ: 
// 	Input: value = 5 (nhị phân: 00000101), n = 3
// 	Output: 13 (nhị phân: 00001101)
// 	Input: value = 13 (nhị phân: 00001101), n = 3
// 	Output: 5 (nhị phân: 00000101)
// o	Gợi ý: Sử dụng toán tử XOR (^).
// ```
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
