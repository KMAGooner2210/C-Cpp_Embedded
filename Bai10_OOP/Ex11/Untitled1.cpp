#include <iostream>
#include <cmath>

class Shape{
	public:
		virtual void draw() const = 0;
		virtual double getArea() const = 0;
		virtual ~Shape(){}
		
};

class Rectangle : public Shape {
	private:
		double width;
		double height;
	public:
		Rectangle(double w, double h) : width(w) , height(h) {}
		
		void draw() const override {
			std::cout << "Drawing Rectangle" << std::endl;
		}
		
		double getArea() const override {
			return width * height;
		}
};

class Circle : public Shape {
	private:
		double radius;
	public:
		Circle(double r) : radius(r){}
		
		void draw() const override{
			std::cout << "Drawing Circle" << std::endl;
		}
		
		double getArea() const override{
			return M_PI * radius * radius;
		}
};

int main(){
	Shape* shapes[] = {
		new Rectangle(4,5),
		new Circle(5)
	};
	
	for(int i = 0; i < 2; ++i){
		shapes[i]->draw();
		std::cout << "Area: " << shapes[i]->getArea() << std::endl;
	}
	
	for(int i = 0; i < 2; i++){
		delete shapes[i];
	}
	return 0;
}
