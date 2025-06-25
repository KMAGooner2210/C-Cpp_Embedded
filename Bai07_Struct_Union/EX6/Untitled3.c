#include<stdio.h>
#include<string.h>

typedef struct{
	int sensorId;
	char sensorName[50];
	float value;
}Sensor;

typedef struct{
	char vehicleId[20];
	int numSensors;
	Sensor sensors[10];
}Vehicle;

typedef Sensor* SensorPtr;

int main(){
	Vehicle car;
	
	strcpy(car.vehicleId, "VN221");
	car.numSensors = 3;
	
	car.sensors[0].sensorId = 01;
	strcpy(car.sensors[0].sensorName, "Engine Temperature");
	car.sensors[0].value - 85.5;
	
	car.sensors[1].sensorId = 02;
	strcpy(car.sensors[1].sensorName, "Tire pressure");
	car.sensors[1].value = 2.4;
	
	car.sensors[2].sensorId = 03;
	strcpy(car.sensors[2].sensorName, "Fuel Level");
	car.sensors[2].value = 75.0;
	
	printf("=== Vehicle Information ===\n");
	printf("Vehicle ID: %s\n", car.vehicleId);
	printf("Number of sensors: %d\n", car.numSensors);
	printf("Sensor Details:\n");
	for(int i =0; i < car.numSensors; i++){
		printf("Sensor %d:\n", i + 1);
        printf("  ID: %d\n", car.sensors[i].sensorId);
        printf("  Name: %s\n", car.sensors[i].sensorName);
        printf("  Value: %.1f\n", car.sensors[i].value);
	}
	
	SensorPtr sensorPtr = &car.sensors[0];
    printf("\nTruy cap sensor 1:\n");
    printf("  ID: %d\n", sensorPtr->sensorId);
    printf("  Name: %s\n", sensorPtr->sensorName);
    printf("  Value: %.1f\n", sensorPtr->value);

    return 0;
}

