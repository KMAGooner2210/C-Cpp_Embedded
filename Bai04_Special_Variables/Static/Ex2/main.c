#include<stdio.h>

int trackMax(int value){
	static int max = 0;
	if(value > max){
		max = value;
	}
	return max;	
	}
	
int main(){
	printf("Max: %d\n",trackMax(5));
	printf("Max: %d\n",trackMax(10));
	printf("Max: %d\n",trackMax(7));
	return 0;
}

