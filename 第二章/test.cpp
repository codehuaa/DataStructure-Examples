#include<stdio.h>

void func1(int* a) {
    *a = 100;
}

int main() {
    int a = 1;
    int* b;
    func1(b);
    printf("%d", *b);
}