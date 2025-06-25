#include<stdio.h>

struct FuelInjector{
	float fuelRate;						//TY LE PHUN NHIEN LIEU
	char isActive;
};

struct Engine{
	int rpm; 							//TOC DO DONG CO
	float engineTemp;					//NHIET DO DONG CO
	struct FuelInjector injectors[4];
};

int main(){
	struct Engine engine;
	engine.rpm = 3000;
	engine.engineTemp = 85.5;
	engine.injectors[0] = (struct FuelInjector){10.5, 1};
	engine.injectors[1] = (struct FuelInjector){10.7, 1};
	engine.injectors[2] = (struct FuelInjector){0.0, 0};
	engine.injectors[3] = (struct FuelInjector){0.0, 0};
	
	printf("Engine RPM: %d\n", engine.rpm);
	printf("Engine Temperature: %.1f do C\n", engine.engineTemp);
	for (int i = 0; i < 4; i++){
		printf("Injector %d: Fuel Rate: %.1f ml/s, Active: %d\n",
				i + 1, engine.injectors[i].fuelRate, engine.injectors[i].isActive);
	}
	
	return 0;
	}

