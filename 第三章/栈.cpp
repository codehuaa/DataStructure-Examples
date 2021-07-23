#include<stdio.h>

#define Element int
#define MaxSize 10

typedef struct {
    Element data[MaxSize];
    int top;
}SqStack;

// init 
void InitStack(SqStack &S) {
    S.top = -1;
}

// is empty?
bool isEmpty(SqStack S) {
    return S.top == -1;
}

// push
bool Push(SqStack &S, Element e) {
    if(S.top == MaxSize - 1) return false; // full
    S.data[++S.top] = e;
    return true;
}

// pop
bool Pop(SqStack &S, Element &e) {
    if(isEmpty(S)) return false; // empty
    e = S.data[S.top--];
    return true;
}

// get top
bool GetTop(SqStack S, Element &e) {
    if(isEmpty(S)) return false;  // empty
    e = S.data[S.top--];
    return true;
}



int main()
{
    SqStack S;
    InitStack(S);
    Push(S, 1);
    Element d;
    if(GetTop(S, d)) printf("%d", d);
}