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

void BinAdd(LinkList l) {   //��l��Ŷ�����������ʵ��+1����
    Node *q,*r,*s;
    q = l->next;
    r = l;
    while(q != NULL) { //�������һ��ֵ��Ϊ0�Ľڵ�
        if(q->data == 0)    r = q;
        q = q->next;
    }
    if(r != l)  r->data = 1; //�����һ����ֵΪ0
    else {
        s = (Node *)malloc(sizeof(Node)); //�����½ڵ������λ
        s->data = 1;    //ֵ��Ϊ1
        s->next = l->next;
        l->next = s;
        r = s;
    }
    r = r->next;
    while(r != NULL) {
        r->data = 0;
        r = r->next;
    }
}
