#include<stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
int main(){
int x = 5, y = 3;
int result = MAX(x++,y++);
printf("result = %d,x = %d, y = %d\n",result,x,y);
return 0;
} 