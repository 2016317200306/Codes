#include<stdio.h>

//����
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

//��ʼ��
void InitCLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
}

//����
void CreateCLinkList(LinkList L) {
    Node *rear,*s;
    int c;
    rear = L;
    scanf("%d",&c);
    while(c!=0) {
        s = (Node *)malloc(sizeof(Node));
        s->data = c;
        rear->next = s;
        rear = s;
        scanf("%d",&c);
    }
    rear->next = L;

}

//ͷָ��ϲ�
LinkList Merge_Head(LinkList La,LinkList Lb) {
    Node *p,*q;
    p = La;
    q = Lb;
    while(p->next!=La) p = p->next;
    while(q->next!=Lb) q = q->next;
    q->next = La;
    p->next = Lb->next;
    free(Lb);
    return La;
}

LinkList Merge_Tail(LinkList La,LinkList Lb) {
    Node *p;
    p  = La->next;
    La->next = Lb->next;
    free(Lb->next);
    Lb->next = p;
    return Lb;
}

int main() {
    LinkList a,b;
    InitCLinkList(&a);
    InitCLinkList(&b);
    CreateCLinkList(a);
    CreateCLinkList(b);
    Merge(a,b);


    return 0;
}
