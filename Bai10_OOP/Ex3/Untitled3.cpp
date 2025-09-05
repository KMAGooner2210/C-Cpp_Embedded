#include<iostream>
#include<string>

class Car{
	private:
	std::string brand;
	int year;
	double price;
	
	public:
		//Constructor mac dinh
		Car() : brand("Unknown"), year(0), price(0.0) {};
		
		//Constructor co tham so
		Car(std:: string b, int y, double p) : brand{b}, year{y}, price{p}{}
		
		void display() const{
			std::cout << "Car: " << brand << ", Year: " << year << ",Price: " << price << std::endl;
		}
};
int main(){
	Car car1;
	car1.display();
	
	Car car2("Kia", 2022, 250000.0);
	car2.display();
	
	return 0;

}
