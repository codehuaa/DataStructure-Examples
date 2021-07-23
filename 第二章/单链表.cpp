#include<stdio.h>
#include<stdlib.h>

#define Element int

typedef struct LNode {
    Element data;
    struct LNode *next;
}LNode, *LinkList;


// init the linklist
bool InitList(LinkList &L) {
    L = (LNode *)malloc(sizeof(LNode));
    if(L == NULL)   // there's no enough memory
        return false;
    L->next = NULL;
    return true;
}

// get element at specify position
LNode * getElem(LinkList L, int index) {
    if(index < 0) return NULL; // illegal index
    LNode *p = L;
    int j = 0; // the index of current node
    while(p != NULL && j < index) {
        p = p->next;
        ++j;
    }
    return p;
}

// get the location of e
LNode * LocateElem(LinkList L, Element e) {
    LNode *p = L;
    while(p != NULL && p->data != e) p = p->next;
    return p;
}

//insert next node
bool InsertNextNode(LNode *p, Element e) {
    if(p == NULL) return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//insert prior node
bool InsertPriorNode(LNode *p, Element e) {  // some problem when p is the last node (no necessary to reslove here)
    if(p == NULL) return false;
    LNode *s = (LNode*)malloc(sizeof(LNode));
    // 1、insert s after p
    s->next = p->next;
    p->next = s;
    // 2、then exchange data between s and p
    s->data = p->data;
    p->data = s->data;
    return true;
}


// insert node at specify location
bool ListInsert(LinkList L, int index, Element e) {
    if(index < 1)   return false;  // illegal index
    LNode *p = getElem(L, index - 1);
    return InsertNextNode(p, e);
}

int Length(LinkList L) {
    int len = 0;
    LNode *p = L;
    while(p->next != NULL) {
        p = p->next;
        ++len;
    }
    return len;
}

// show all list
void ShowList(LinkList L) {
    LNode *p = L->next;
    if(p == NULL) {
        printf("LinkList is empty");
    } else {
        printf("LinkList: ");
        while(p->next != NULL) {
            printf("%d ", p->data);
            p = p->next;
        }
        printf("%d", p->data);
    }
    printf(".\n");
}

int main()
{
    LinkList L;
    InitList(L);
    ListInsert(L, 1, 13);
    ListInsert(L, 2, 23);
    ListInsert(L, 3, 33);
    ShowList(L);
    printf("%d\n", Length(L));
}