#include<stdio.h>

union Value1 {
	char arr[10];
	int i;
	double d;
};

union Value2 {
	char arr[11];
	int i;
	short s;
};

union Value3 {
	char arr[7];
	int i;
	double d;
	short s;
} __attribute__((packed));
int main(){
	printf("Kich thuoc cua union Value1: %zu bytes\n", sizeof(union Value1));
	printf("Kich thuoc cua union Value2: %zu bytes\n", sizeof(union Value2));
	printf("Kich thuoc cua union Value3: %zu bytes\n", sizeof(union Value3));
	return 0;
}
