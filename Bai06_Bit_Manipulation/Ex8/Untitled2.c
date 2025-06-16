#include<stdio.h>
#include<conio.h>
#include<stdint.h>
uint8_t setMultipleBits(uint8_t value, const int positions[], int size){
	uint8_t mask = 0;
	for(int i = 0; i < size; i++){
		if(positions[i] >= 0 && positions[i] < 8){
			mask |= (1 << positions[i]);
		}
	}
	uint8_t result = value | mask;
	return result;
}

int main(){
  uint8_t val;
  int num;
  int pos[8];	
  char ch;
  while(1){  

  printf("Nhap gia tri nguyen khong dau (value): ");
  if(scanf("%hhu",&val) != 1){
  	printf("Loi: Gia tri khong hop le!\n");
  	while (getchar() != '\n');
  	return 1;
  }
  
  printf("Nhap so luong vi tri bit can set len 1: ");
  if(scanf("%d",&num) != 1 || num < 0 || num > 8){
  	printf("Loi: So luong vi tri khong hop le!\n");
  	while (getchar() != '\n');
  	return 1;
  }
  
  printf("Nhap cac vi tri bit: ");
  for(int i = 0; i < num; i++){
  	if(scanf("%d", &pos[i]) != 1){
  		printf("Loi: Vi tri khong hop le!\n");
  		while (getchar() != '\n');
  		return 1;
	}
	if(pos[i] < 0 || pos[i] > 7){
		printf("Loi: Vi tri %d khong hop le (phai tu 0 den 7)!\n", pos[i]);
		while (getchar() != '\n');
		return 1;
	}
}
  
  uint8_t res = setMultipleBits(val,pos,num);
  
  printf("Input: value = %u, position = [", val);
  for(int i = 0; i < num; i++){
  	printf("%d", pos[i]);
  	if(i < num - 1) printf(", ");
  }
  printf("]\n");
  printf("Output: %u\n", res);

  printf("Nhan ESC de thoat, ky tu khac de tiep tuc.\n");
  ch = getch();
  if(ch == 27){
  	break;
  }
}
  printf("End.\n");
  return 0;
}

