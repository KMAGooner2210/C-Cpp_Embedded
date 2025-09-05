#include<iostream>

class Circle{
	private:
		double radius;
	public:
		Circle(double r): radius(r){}
		
		double getDTich() const{
			return 3.1416 * radius * radius;
		}
		
		double getCVi() const {
			return 2 * 3.1415 * radius;
		}
};

int main(){
	Circle c(5.0);
	
	std::cout << "Dien tich: " << c.getDTich() << std::endl;
	std::cout << "Chu vi: " << c.getCVi() << std::endl;
	
	return 0;
 }
