#include<stdio.h>
#include<stdin.h>

#define STATUS_REG (*(volatile uint32_t *)0x40010000)

int main(void){
	while(1){
		if(STATUS_REG & (1 << 3)){
			printf("Bit 3 is set!\n");
			break;
		}
	}
	return 0;
}
