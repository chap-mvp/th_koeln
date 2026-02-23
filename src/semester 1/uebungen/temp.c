#include <stdio.h>

int main(){
    int a = 1;
    int b = 5;
    
    a = b - a;
    b = b - a;
    a = a + b;

    printf("[a: %d -> %d] \n[b: %d -> %d]", b, a, a, b);
}