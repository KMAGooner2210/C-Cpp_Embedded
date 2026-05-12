// ## **Ex9.	Kiểm Tra Nhiều Bit Cùng Được Set**
// o	Yêu cầu: Viết hàm kiểm tra xem tất cả các bit ở các vị trí cho trước trong một số nguyên không dấu có đều được set (bằng 1) hay không.
// ```
// o	Ví dụ: 
// 	Input: value = 12 (nhị phân: 00001100), positions = [2, 3]
// 	Output: true (cả bit 2 và 3 đều là 1)
// 	Input: value = 12 (nhị phân: 00001100), positions = [2, 4]
// 	Output: false (bit 4 là 0)
// o	Gợi ý: Tạo mask bằng OR, sau đó dùng AND và so sánh.
// ```
#include<stdio.h>
#include<conio.h>
#include<stdint.h>
#include<stdbool.h>

bool check_Bit_Set(uint8_t value, int positions[], int size){
	uint8_t mask = 0;
	for(int i =0; i < size; i++){
		if(positions[i] >= 0 && positions[i] <=7){
			mask |= (1 << positions[i]);
		}else{
			printf("Vi tri %d khong hop le (phai tu 0 den 7)\n", positions[i]);
			return false;
		}
	}
	return (value & mask) == mask;
}

int main(){
	uint8_t val;
	int num;
	char ch;
	
	while(1){
		printf("Nhap mot so nguyen khong dau (0 den 255): ");
		if(scanf("%hhu",&val) != 1){
			while(getchar() != '\n');
			printf("Gia tri khong hop le, nhap lai! \n");
			continue;
		}
		
		printf("Nhap so luong vi tri bit can kiem tra: ");
		if(scanf("%d", &num) != 1 || num < 0 || num > 7){
			printf("So luong khong hop le, nhan lai! \n");
			continue;
		}
		
		int pos[num];
		printf("Nhap cac vi tri bit can kiem tra (0 den 7): ");
		for(int i = 0; i < num; i++){
			if(scanf("%d",&pos[i]) != 1){
				while(getchar() != '\n');
				printf("Vi tri khong hop le, nhap lai! \n");
				break;
			}
		}
		
		bool result = check_Bit_Set(val,pos,num);
		printf("Input: Value = %hhu (nhi phan: ", val);
		for(int i = 7; i >= 0; i--){
			printf("%d", (val >> i) & 1);
			if(i % 4 == 0) printf(" ");
		}
		printf("), positions = [");
        for (int i = 0; i < num; i++) {
            printf("%d", pos[i]);
            if (i < num - 1) printf(", ");
        }
        printf("]\n");
        printf("Output: %s\n", result ? "true" : "false"); printf("Nhan ESC de thoat, ky tu khac de tiep tuc.\n");
  ch = getch();
  if(ch == 27){
  	break;
  }
}
  printf("End.\n");
  return 0;
}
	

