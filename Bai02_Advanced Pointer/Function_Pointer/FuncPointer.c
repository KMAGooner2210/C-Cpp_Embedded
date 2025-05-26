#include<stdio.h>

int add(int a,int b){
	return a + b;
}

int sub(int a, int b){
	return a - b;
}

int multiply(int a, int b){
	return a * b;
}

int div(int a, int b){
	if(b==0){
	printf("Loi!!");
	return 0;
	}
	return a / b;
}

int(*operation[])(int,int)={add, sub, multiply, div};

int calculate(int a,int b, int operation_index){
	if(operation_index < 0 || operation_index > 3){
	printf("Phep toan loi!!");
	return 0;
	}
	return operation[operation_index](a, b);
}

int main(){

int a, b, operation_index;
char continue_cal;

do{
	printf("Nhap 2 so a va b: ");
	scanf("%d %d",&a, &b);
	printf("Nhap chi so phep toan(0: cong, 1: tru, 2: nhan, 3: chia): ");
	scanf("%d", &operation_index);
	
	int result = calculate(a, b, operation_index);
	if(operation_index >= 0 || operation_index <= 3){
		printf("Ket qua: ");
		switch(operation_index){
			case 1: printf("%d + %d = %d",a, b, result); break;
			case 2: printf("%d - %d = %d",a, b, result); break;
			case 3: printf("%d * %d = %d",a, b, result); break;
			case 4: if(b !=0 ) printf("%d / %d = %d",a, b,result);
			        break;
			}
		}
	printf("Tiep tuc? (y/n): ");
	scanf(" %c",&continue_cal);
}while (continue_cal == 'y' || continue_cal == 'Y');
return 0;
}
			
	

