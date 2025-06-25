#include<stdio.h>
#include<string.h>

enum ResultType { NUMERIC, STATUS};

union TestResult {
	float numericVal;
	char status[4];
};

struct SensorTest{
	int sensorID;
	char sensorName[50];
	enum ResultType resultType;
	union TestResult result;
};

int main(){
	struct SensorTest sensors[3];
	
	sensors[0].sensorID = 1;
	strcpy(sensors[0].sensorName, "Engine Temperature");
	sensors[0].resultType = NUMERIC;
	sensors[0].result.numericVal = 85.5;
	
	sensors[1].sensorID = 2;
	strcpy(sensors[1].sensorName, "Tire Pressure");
	sensors[1].resultType = NUMERIC;
	sensors[1].result.numericVal = 2.4;
	
	sensors[2].sensorID = 3;
	strcpy(sensors[2].sensorName, "Brake System");
	sensors[2].resultType = STATUS;
	strcpy(sensors[2].result.status,"OK");
	
	printf("=== Sensor Test Results ===\n");
	for(int i =0; i < 3; i++){
		printf("Sensor ID: %d\n",sensors[i].sensorID);
		printf("Sensor Name: %s\n",sensors[i].sensorName);
		printf("Result: ");
		
		if(sensors[i].resultType == NUMERIC){
			printf("%.1f\n",sensors[i].result.numericVal);
		}else if(sensors[i].resultType == STATUS){
			printf("%s\n", sensors[i].result.status);
		}
		printf("\n");
	}
	
	return 0;
}
