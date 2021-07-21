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

bool ListInsert(SqList &L, int index, int e) {  // 此处index是位数，即下标+1
    if(index < 1 || index > L.length+1) { // index不合法
        return false;
    }
    if(L.length >= MaxSize) {  // 顺序表满了
        return false;
    }

    for(int i = L.length; i >= index; --i) {
        L.data[i] = L.data[i-1];
    }
    L.data[index-1] = e;
    L.length++;
    return true;
}

bool ListDelete(SqList &L, int index, int &e) {
    if(index < 1 || index > L.length) {
        return false;
    }
    e = L.data[index-1];
    for(int i = index; i < L.length; ++i) {
        L.data[i-1] = L.data[i];
    }
    L.length--;
    return true;
}

ElemType GetElem(SqList L, int index) {
    return L.data[index-1];
}

int LocationElem(SqList L, int e) {
    for(int i = 0; i < L.length; ++i) {
        if(L.data[i] = e) return i+1;
    }
    return -1;
}

int main() {
    SqList L;
    InitList(L);
    for(int i = 0; i < 10; ++i) {
        if(ListInsert(L, i+1, i)) {
            printf("insert successfully, %d at %d\n", i, i+1);
        } else {
            printf("insert fatal");
        }
    }
    for(int i = 0; i < L.length; ++i) {
        printf("%d ", L.data[i]);
    }
    printf("\n");

    int e = -1; // 用来保存删除的值
    if(ListDelete(L, 4, e)) {
        printf("delete success, element deleted is %d\n", e);
    } else {
        printf("delete fatal\n");
    }

}



