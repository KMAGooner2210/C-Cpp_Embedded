#include <stdio.h>

struct Data {
	char a;
	int b;
	double c;
	short d;
};

struct DataOptimized {
	double c;
	int b;
	short d;
	char a;
};

struct DataPacked {
	char a;
	int b;
	double c;
	short d;
} __attribute__((packed));

int main(){
	printf("Kich thuoc struct Data: %zu bytes\n", sizeof(struct Data));
	printf("Kich thuoc struct DataOptimized: %zu bytes\n", sizeof(struct DataOptimized));
	printf("Kich thuoc struct DataPacked: %zu bytes\n", sizeof(struct DataPacked));
	return 0;
}
