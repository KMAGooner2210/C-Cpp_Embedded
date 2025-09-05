#include<iostream>

class Counter {

	public:
		static int count;
		
		Counter() {
			count++;
			std::cout << "So doi tuong: " << count << std::endl;
		}
		
		~Counter(){
			count--;
			std::cout << "So doi tuong: " << count << std::endl;
		}
		
		static void showCount(){
			std::cout << "So doi tuong: " << count << std::endl;
		}
};

int Counter::count = 0;
int main(){
	//Hien thi doi tuong ban dau
	Counter::showCount();
	
	//Tao doi tuong
	Counter c1;
	Counter c2;
	
	//Hien thi doi tuong sau khi tao
	Counter::showCount();
	
	Counter c3;
	
	Counter::showCount();
	return 0;
}
