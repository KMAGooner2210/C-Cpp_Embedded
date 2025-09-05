#include<iostream>
using namespace std;

class Rectangle{
	private:
		double length;
		double width;
		
	public:
		Rectangle(double l, double w){
			length = l;
			width = w;
		}
		double ChuVi(){
			return (length + width) * 2;
		}
		double DienTich(){
			return length * width;
		}
};

int main(){
	Rectangle rec(3,4);
	cout << "Chu vi: " << rec.ChuVi() << endl;
	cout << "Dien tich: " << rec.DienTich() << endl;
	return 0;
	
}
