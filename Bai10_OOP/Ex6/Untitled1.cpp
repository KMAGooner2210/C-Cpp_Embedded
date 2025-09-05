#include<iostream>

class Vehicle{
	protected:
		std::string brand;
		int year;
	
	public:	
		Vehicle(std::string b, int y) : brand(b), year(y) {}
		void displayInfo(){
			std::cout << "Brand: " << brand << ",Year: " << year;
		}
};

class Car : public Vehicle {
	private:
		int numDoors;
	
	public:	
		Car(std::string b, int y, int numDoors) : Vehicle(b, y), numDoors(numDoors) {}
		
		void displayInfo(){
			Vehicle::displayInfo();
			std::cout << ", Number of doors: " << numDoors << std::endl;
		}
};

int main(){
	Car car("Vinfast", 2025, 4);
	car.displayInfo();
	return 0;
}
