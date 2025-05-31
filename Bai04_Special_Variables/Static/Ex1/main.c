#include<stdio.h>

void countCall(){
	static int count = 0;
	count++;
	printf("Call %d\n", count); 
	
	
}

int main(){
	countCall();
	countCall();
	countCall();
	return 0;
}

//count++ -> count tra ve gia tri tang con count ++ tra ve gia tri truoc khi tabg
//++count => count tra ve gia tri tabg ++count cung the
