#include<iostream>
#include<string>

class Employee{
	private:
		std::string name;
		double salary;
		
	public:
		Employee() : name(" "), salary(0.0){}
		
		Employee& setInfo(std::string n, double s){
			this->name = n;
			this->salary = s;
			return *this;
		}	
		
		void display() const{
			std::cout << "Name: " << name << ", Salary: " << salary << std::endl;
		}
};

int main(){
	Employee emp;
	emp.setInfo("Tung", 10000000).display();
	return 0;
}
