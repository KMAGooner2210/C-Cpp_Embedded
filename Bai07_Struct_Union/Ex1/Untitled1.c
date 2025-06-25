#include<stdio.h>

struct TireSensor{
	int sensorId;
	float temperature;
	float pressure;
	unsigned long timestamp; //thoi gian lay mau
};

int main(){
	struct TireSensor sensor;
	sensor.sensorId = 1;
	sensor.temperature = 25.5;
	sensor.pressure = 101.3;
	sensor.timestamp = 36000; //10p: 36000s thoi gian lay mau
	
	printf("Sensor ID: %d\n", sensor.sensorId);
	printf("Temperature: %.1f do C\n", sensor.temperature);
	printf("Pressure: %.1f kPa\n", sensor.pressure);
	printf("Timestamp: %lu\n", sensor.timestamp);
	
	return 0;
}
