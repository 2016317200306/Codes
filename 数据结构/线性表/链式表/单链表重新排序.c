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

void change(LinkList l) {
    Node *p,*q,*pl,*pre;
    if(l->next == NULL) return 0;
    pl = l->next;
    pre = pl;
    p = pl->next;
    //˳�μ�����нڵ�,�Ա�pl->dataС�ķ���ͷ�ڵ�󣬴�Ĳ�������
    while(p) {
        q = p->next;
        if(p->data >= pl->data) {pre = p;p = q;}
        else {pre->next = p->next;p->next = l->next;l->next = p;p = q;}
    }
}
