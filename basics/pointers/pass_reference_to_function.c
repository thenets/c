#include <stdio.h>
#include <stdlib.h>

void soma(int *, int, int);

int main () {
    int s, n1, n2;
    
    n1 = 6;
    n2 = 14;
    int *ps = &s;
    int **ps2 = &ps;
    
    printf("oi\n");
    
    soma(*ps2, n1, n2);
    
    printf("Soma = %d \n", s);
    
    getchar(); // pause
    
    return 0;
}

void soma(int *s, int n1, int n2) {
    *s = n1 + n2;
}