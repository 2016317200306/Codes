#include<stdio.h>

//����
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

//��ʼ��
void InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void Reverse(LinkList l) {
    Node *p,*q;
    p = l->next;
    l->next = NULL;
    while(p != NULL) {
        q = p->next;
        p->next = l->next;
        l->next = p;
        p = q;
    }
}
