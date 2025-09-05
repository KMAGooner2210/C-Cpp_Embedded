#include <iostream>

class DynamicArray {
	private:
		int* data;
		int size;
	
	public:
		DynamicArray(int s) : size(s){
			
			if(s <= 0){
				size = 0;
				data = NULL;
				std::cout << "Invalid size, array not created" << std::endl;
				return;
			}
			
			data = new int[size];
			for(int i = 0; i < size; ++i){
				data[i] = i + 1;
			}
		}
		
		~DynamicArray(){
			if (data != NULL){
				delete[] data;
				std::cout << "Destructor called" << std::endl;
			}
		}
		
		void display() const{
			if(size == 0 || data == NULL){
				std::cout <<"Array is empty" << std::endl;
				return;
			}
			std::cout <<"Array: ";
			for(int i = 0; i < size; ++i){
				std::cout << data[i] << " ";
			}
			std::cout << std::endl;
		}
};

int main(){
	
	DynamicArray arr(5);
	arr.display();
	return 0;
}
