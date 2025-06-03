#include<stdio.h>
#include<setjmp.h>

void delay(double seconds){
	double start = 0;
	while(start < seconds){
		start++;
	}
}

typedef enum{
	FULL,
	LOW,
	CRITICAL
}FuelState;

jmp_buf env;

void check_fuel_level(int fuel_percent){
	if(fuel_percent < 20){
		
		printf("CRITICAL: Fuel level = %d%%, initiating emergency mode!\n",fuel_percent);
		longjmp(env, 1); //nhay ve diem setjmp khi muc nhien lieu nguy cap
		
	}else if(fuel_percent < 70){
		
		printf("LOW: Fuel level = %d%%, refuel !\n",fuel_percent);
		
	}else{
		printf("FULL: Fuel level = %d%%\n",fuel_percent);
	}
}

int main(){
	int fuel_percent = 80;
	FuelState state = FULL;
	
	if(setjmp(env) == 0){
		printf("Check fuel level");
		while(1){
			switch(state){
				case FULL:
					check_fuel_level(fuel_percent);
					delay(2);
					fuel_percent -= 20;
					if(fuel_percent < 70) state = LOW;
					break;
					
				case LOW:
					check_fuel_level(fuel_percent);
					delay(2);
					fuel_percent -= 20;
					if(fuel_percent < 20) state = CRITICAL;
					break;
					
				case CRITICAL:
					check_fuel_level(fuel_percent);
					break;
				}
			}
		}else{
			printf("Emergency mode: Logging Error and Reset.\n");
			fuel_percent = 100;
			state = FULL;
			printf("RESET.Fuel level = %d%%\n", fuel_percent);
		}
		
		return 0;
	
}

