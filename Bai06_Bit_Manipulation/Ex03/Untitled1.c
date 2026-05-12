// ## **Ex3. Đặt Bit Thứ n** 
// o	Yêu cầu: Viết hàm đặt (set) bit thứ n của một số nguyên không dấu thành 1
// ```
// o	Ví dụ: 
// 	Input: value = 5 (nhị phân: 00000101), n = 3
// 	Output: 13 (nhị phân: 00001101)
// ```
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
