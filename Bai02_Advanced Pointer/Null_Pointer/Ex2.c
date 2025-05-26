#include<stdio.h>
#include<stdlib.h>

int* findValue(int arr[],int size, int valFound){
	for(int i =0; i < size; i++){
		if(arr[i] == valFound){
		return &arr[i];
		}
	}
	return NULL;
}

int main(){
	int numbers[]={22,10,15,10};
	int size = sizeof(numbers) / sizeof(numbers[0]);
	
	int *found_ptr = findValue(numbers,4,22);
	if(found_ptr != NULL){
		printf("Tim thay gia tri: %d tai dia chi: %p\n",*found_ptr, (void*)found_ptr);
		}else{
		printf("Khong tim thay gia tri");
		}
		return 0;
	}
		