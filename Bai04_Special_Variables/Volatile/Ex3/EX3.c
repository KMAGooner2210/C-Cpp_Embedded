#include<stdio.h>
#include<stdint.h>

#define GPIO_OUT_REG (*(volatile uint32_t *)0x40020000)

volatile uint8_t led_state = 0;

void timer_isr(void){
	led_state = !led_state;
}

int main(void){
	while(1){
		timer_isr();
		if(led_state){
		
		GPIO_OUT_REG |= (1<<0); //Bat led (bit0)
		printf("Led on\n");
	}else{
		GPIO_OUT_REG &= ~(1<<0);
		printf("Led off\n");
	}
	for(volatile int i =0;i < 1000000; i++);
}
return 0;
}
