#include <stdio.h>
#include <stdlib.h>

int global_init = 42;       
int global_uninit;           
static int static_init = 10; 
static int static_uninit;    

void my_function(int param) {
    int local_var = 5;      
    int *dynamic_var = malloc(sizeof(int)); 
    *dynamic_var = 100;
    printf("Local: %d, Dynamic: %d\n", local_var, *dynamic_var);
    free(dynamic_var);
}

int main() {
    my_function(20);
    return 0;
}

/*********
1.Bien global_init duoc luu o dau ?
2.Bien global_uninit duoc luu o dau ?
3.Bien static_init va static_uninit duoc luu o dau ?
4.Bien param va local_var duoc luu o dau >
5.Bien dynamic_var va vung nho ma no tro toi duoc luu o dau ?
**********/
