#include<iostream>
#include<string>

class Book {
	private:
		std::string title;
		std::string author;
		double price;
		
	public:
		Book(std::string t, std::string a, double p) : title(t), author(a), price(p) {}
		Book(const Book& other) : title(other.title), author(other.author), price(other.price){}
		
		void display() const{
			std::cout << "Book: " << title << ", Author: " << author << ", Price: " << price << std::endl;
		}
};

int main() {
	Book book1(std::string("The hobbit") , std::string("Ben"), 29.99);
	
	//Sao chep book1 bang copy constructor
	Book book2 = book1;
	
	book1.display();
	std::cout << "Copied Book: ";
	book2.display();
	
	return 0;
}

