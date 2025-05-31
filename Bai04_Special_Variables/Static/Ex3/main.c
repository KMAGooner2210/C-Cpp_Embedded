#include<stdio.h>

void increaseCounter();
int getCounter();

extern int counter;

int main(){
	increaseCounter();
	increaseCounter();
	increaseCounter();
	
	printf("Counter: %d\n", getCounter());
	// Loi: printf("Direct counter: %d\n", counter);
	return 0;
}
