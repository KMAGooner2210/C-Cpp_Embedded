#include<stdio.h>
#include<stdinT.h>
#include<unistd.h>

volatile uint32_t button_count = 0;
volatile uint32_t led_state = 0;

void button_isr(void){
	button_count++;
	printf("Button Pressed! Count: %u\n", button_count);
}

int main(void){
	printf("Starting Counter....\n");
	
	while(1){
		button_isr();
		
		if(button_count >= 5){
			led_state != led_state;
			printf("Threshold reached! LED state: %s\n", led_state ? "ON" : "OFF");
			button_count = 0;
		}
		
		sleep(1);
		if(button_count >= 10) break;
	}
	
  printf("End.\n");
  return 0;
}

