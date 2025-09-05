#include<iostream>

class Complex{
	private:
		double real;
		double imag;
		
	public:
			Complex(double r = 0, double i = 0) : real(r) , imag(i){}
			
			Complex operator+(const Complex& other) const{
				return Complex(real + other.real, imag + other.imag);
			}
			
			friend std::ostream& operator<<(std::ostream& os, const Complex& c){
				os << "(" << c.real << " + " << c.imag << "i)";
				return os;
			}	
};

int main(){
	Complex c1(3, 4);
	Complex c2(1, 2);
	Complex sum = c1 + c2;
	
	std::cout << "Complex 1: " << c1 << std::endl;
	std::cout << "Complex 2: " << c2 << std::endl;
	std::cout << "Sum: " << sum << std::endl;
	return 0;
}
