#include<iostream>
#include<string>
using namespace std;

class Student{
	private:
		string name;
		int age;
		float score;
	public:
		Student(string n, int a, float s){
			setName(n);
			setAge(a);
			setScore(s);	
		}
		string getName(){
			return name;
		}
		void setName(string n){
			if(!n.empty()) name = n;
			else name = "Unknown";
		}
		int getAge(){
			return age;
		}
		void setAge(int a){
			if (a>=0) age = a;
			else age = 0;
		}
		float getScore(){
			return score;
		}
		void setScore(float s){
			if (s >= 0 && s <= 10) score = s;
			else score = 0;
		
		}
		void display(){
			cout << "Name: " << name << ", Age: " << age << ", Score: " << score <<endl;
		}
};

int main(){
	Student stu("Nam", 21, 7.9);
	stu.display();
	stu.setName("Ban");
	stu.setAge(-1);
	stu.setScore(11);
	stu.display();
	return 0;
}
