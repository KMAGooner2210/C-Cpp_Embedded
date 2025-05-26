
#include <stdio.h>

int main()
{
    int x = 10,  y =22;
    const int * ptr = &x;
    printf("Gia tri ma ptr tro toi la: %d\n",*ptr);
    ptr =&y;
    // Loi: *ptr=&y;
    printf("Gia tri ma ptr tro toi luc sau la: %d",*ptr);
    // Loi: *ptr=30;
    return 0;
}
//-----Con tro tro toi hang so-----//
//-----Gia tri giu nguyen-Dia chi thay doi-----//
