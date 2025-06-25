#include<stdio.h>
#include<string.h>

union Data{
	int intVal;
	float floatVal;
	char stringVal[20];
};

int main(){
	union Data data;
	
	data.intVal = 100;
	printf("Int value: %d\n", data.intVal);
	printf("Float value: %f\n", data.floatVal);
	printf("String value: %s\n", data.stringVal);
	printf("\n");
	
	data.floatVal = 12.34;
	printf("Float value: %.2f\n",data.floatVal);
	printf("Int value: %d\n", data.intVal);
	printf("String value: %s\n", data.stringVal);
	printf("\n");
	
	strcpy(data.stringVal, "KMA!");
	printf("String value: %s\n", data.stringVal);
	printf("Int value: %d\n", data.intVal);
	printf("Float value: %f\n", data.floatVal);
	
	return 0;
}

