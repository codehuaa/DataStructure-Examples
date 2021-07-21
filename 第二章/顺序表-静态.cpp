#include<stdio.h>

#define MaxSize 10
#define ElemType int

typedef struct {
    ElemType data[MaxSize];
    int length;
} SqList;


void InitList(SqList &L) {
    L.length = 0;
}


int main() {
    SqList L;
    InitList(L);
}



