#include<stdio.h>
#include<stdlib.h>

#define InitSize 10
#define ElemType int

typedef struct {
    ElemType *data;
    int MaxSize;
    int length;
} SqList;


void InitList(SqList &L) {
    // 用malloc函数申请一片连续的存储空间
    L.data = (ElemType*)malloc(sizeof(ElemType) * InitSize);
    L.length = 0;
    L.MaxSize = InitSize;
}

void IncreaseSize(SqList &L, int len) {
    ElemType *oldArray = L.data;   // oldArray指向旧存储空间的数据
    L.data = (ElemType*)malloc(sizeof(ElemType) * (L.MaxSize + len));   // 使用malloc重新分配数据
    for(int i = 0; i < L.length; ++i) {
        L.data[i] = oldArray[i];
    }
    L.MaxSize += len;
    free(oldArray);  // 使用free释放空间
}


int main() {
    SqList L;
    InitList(L);
}


