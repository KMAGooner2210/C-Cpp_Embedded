#include<stdio.h>

void delay(double seconds){
	double start = 0;
	while(start < seconds){
		start++;
	}
}

typedef enum{
	NORMAL,
	WARNING,
	CRITICAL
} SensorState;

int main(){
	
	int temperature = 80;
	SensorState state = NORMAL;
	
	while(1){
		switch(state){
			case NORMAL:
				
				if(temperature > 100){
					state = WARNING;
					goto skip_delay; 
				}
				
				printf("NORMAL: Temperature = %d C degree\n",temperature);
				delay(2);
				temperature += 10;
				break;
				
			case WARNING:
				
				if(temperature > 120){
					state = CRITICAL;
					goto skip_delay;
				}
				
				printf("WARNING: Temperature = %d C degree, reduce engine load!\n", temperature);
				delay(2);
				temperature += 10;
				break;
				
			case CRITICAL:
				
				printf("CRITICAL: Temperature = %d C degree, shutting down!\n",temperature);
				goto cleanup;
				}
				
			skip_delay:;
			}
			
		cleanup:
			printf("System shutdown: Logging error and resetting sensor.\n");
			temperature = 0;
			state = NORMAL;
			printf("Sensor reset.Temperature = %d C degree\n", temperature);

			return 0;
}
