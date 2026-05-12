// ## **Ex1.	Chuyển Đổi Số Thập Phân Sang Nhị Phân**
// o	Yêu cầu: Viết hàm chuyển số thập phân (unsigned int) sang biểu diễn nhị phân dưới dạng chuỗi (string).
// ```
// o	Ví dụ: 

// 	Input: 5
// 	Output: "00000101" (giả sử 8 bit)
// 	Input: 13
// 	Output: "00001101"
// o	Gợi ý: Sử dụng phép dịch bit (>>), toán tử AND (&) và lặp để kiểm tra từng bit.
// ```
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
