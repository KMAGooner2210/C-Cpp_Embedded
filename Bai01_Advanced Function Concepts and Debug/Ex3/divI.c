#include<stdio.h>
#include<assert.h>
int divide(int a,int b){
	assert(b!=0);
	return a/b;
}

int main(){
int a=10;
int b= 0;
int result = divide(a,b);
return 0;
}

