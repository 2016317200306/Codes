#include<stdio.h>

//定义
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

//初始化
void InitCLinkList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = *L;
}

//创建
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
