#include <stdio.h>
#include <stdlib.h>

struct TireSensor {
	int sensorId;
	float pressure;
	float temperature;
	unsigned long timestamp;
};

int main(){
	struct TireSensor *sensor = malloc(sizeof(struct TireSensor));
	if (sensor == NULL){
		printf("Memory allocation failed!\n");
		return 1;
	}
	
	sensor->sensorId = 2;
	sensor->pressure = 230.0;
	sensor->temperature = 26.5;
	sensor->timestamp = 36000;
	
	printf("Tire Sensor ID: %d\n", sensor->sensorId);
	printf("Pressure: %.1f kPa\n", sensor->pressure);
	printf("Temperature: %.1f do C\n", sensor->temperature);
	printf("Timestamp: %lu ms\n", sensor->timestamp);
	
	free(sensor);
	return 0;
}
