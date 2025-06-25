#include<stdio.h>
#include<string.h>

enum SalaryType { HOURLY, FIXED};

union Salary {
	float hourlyRate;
	double fixedSalary;
};

struct Employee{
	int id;
	char name[50];
	enum SalaryType sType;
	union Salary salary;
};

typedef struct Employee Employee;
typedef struct Employee* EmPtr;

void printEmployee( const Employee* emp, double* totalS ,float hours){
	printf("ID: %d, Ten: %s, ",emp->id, emp->name);
	if(emp->sType == HOURLY){
		double monthlySalary = emp->salary.hourlyRate * hours;
		printf("Loai luong: Theo gio - Luong gio: %.2f, Luong thang: %.2f\n", emp->salary.hourlyRate, monthlySalary);
		*totalS += monthlySalary;
	}else{
		printf("Loai luong: Co dinh - Luong thang: %.2f\n",emp->salary.fixedSalary);
		*totalS += emp->salary.fixedSalary;
	}
}

int main(){
	Employee employees[5];
	float hours = 160.0;
	double totalS = 0.0;
	
	employees[0].id = 01;
	strcpy(employees[0].name, "Mai Thanh Tung");
	employees[0].sType = HOURLY;
	employees[0].salary.hourlyRate = 15.5;
	
	employees[1].id = 02;
	strcpy(employees[1].name, "Mac Duc Loc");
	employees[1].sType = HOURLY;
	employees[1].salary.hourlyRate = 12.75;
	
	employees[2].id = 03;
	strcpy(employees[2].name, "Mac Duc Long");
	employees[2].sType = HOURLY;
	employees[2].salary.hourlyRate = 19.75;
	
	employees[3].id = 04;
	strcpy(employees[3].name, "Hoang Duc Long");
	employees[3].sType = FIXED;
	employees[3].salary.fixedSalary = 5000.0;
	
	employees[4].id = 05;
	strcpy(employees[4].name, "Hoang Duc Nam");
	employees[4].sType = FIXED;
	employees[4].salary.fixedSalary = 6000.0;
	
	printf("Thong tin nhan vien:\n");
	for(int i = 0; i < 5; i++) {
		printEmployee(&employees[i], &totalS, hours);
	}
	printf("\nTong luong phai tra: %.2f\n", totalS);
	return 0;
}
