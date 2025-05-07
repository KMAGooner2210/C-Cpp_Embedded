#include<stdio.h>
#ifdef DEBUG
#define DEBUG_PRINT(msg) printf("%s\n",msg)
#else
#define DEBUG_PRINT
#endif

int main(){
printf("This is debug message");
return 0;
}