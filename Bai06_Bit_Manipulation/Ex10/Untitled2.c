// ## **Ex10.	Tìm Bit 1 Thấp Nhất**
// o	Yêu cầu: Viết hàm tìm vị trí của bit 1 thấp nhất (tính từ 0) trong biểu diễn nhị phân của một số nguyên không dấu. Nếu không có bit 1, trả về -1.
// ```
// o	Ví dụ: 
// 	Input: 5 (nhị phân: 00000101)
// 	Output: 0 (bit 1 thấp nhất ở vị trí 0)
// 	Input: 8 (nhị phân: 00001000)
// 	Output: 3
// 	Input: 0 (nhị phân: 00000000)
// 	Output: -1
// o	Gợi ý: Sử dụng value & (-value) để lấy bit thấp nhất, sau đó tìm vị trí bằng cách lặp hoặc mẹo logarit.
// ```
#include<stdio.h>
#include<conio.h>
#include<stdint.h>
#include<stdbool.h>

int find_Lowest_Set_Bit(uint8_t value){
	if(value == 0){
		return -1;
	}
	
	uint8_t lowestBit = value & (-value);
	int position = 0;
	
	while(lowestBit != 1){
		lowestBit >>= 1;
		position++;
	} 
	return position;
}

void print_Binary(uint8_t value){
	for(int i = 7; i >= 0; i--){
		printf("%d", (value >> i) & 1);
		if (i > 0 && i % 4 == 0) printf(" ");
	}
}

int main(){
	uint8_t val;
	char ch;
	
	while(1){
		printf("Nhap so nguyen khong dau: ");
		if(scanf("%hhu",&val) != 1){
			while(getchar() != '\n');
			printf("Gia tri khong hop le, nhap lai.\n");
			continue;
		}	
		
		int result = find_Lowest_Set_Bit(val);
		printf("Input: Value = %hhu (nhi phan: ",val);
		print_Binary(val);
		printf(")\n");
		printf("Output: %d\n", result);
		
		printf("Nhan ESC de thoat, nhan ky tu khac de tiep tuc.\n");
		while(getchar() != '\n');
		ch = getch();
		if (ch == 27){
			break;
		}
	}
	printf("End.\n");
	return 0;
}
