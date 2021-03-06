#include<stdio.h>

//定义
typedef struct Node {
    struct Node * next;
    int data;
}Node,*LinkList;

//初始化
void InitList(LinkList *L) {
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
}

void BinAdd(LinkList l) {   //用l存放二进制数，并实现+1操作
    Node *q,*r,*s;
    q = l->next;
    r = l;
    while(q != NULL) { //查找最后一个值域为0的节点
        if(q->data == 0)    r = q;
        q = q->next;
    }
    if(r != l)  r->data = 1; //将最后一个赋值为0
    else {
        s = (Node *)malloc(sizeof(Node)); //申请新节点存放最高位
        s->data = 1;    //值域赋为1
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
