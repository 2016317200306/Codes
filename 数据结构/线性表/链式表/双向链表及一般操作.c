#include<stdio.h>

typedef struct DNode {
    int data;
    struct DNode *prior,*next;
}DNode,*Doublelist;

//插入
int DlinkIns(Doublelist L,int i,int e) {
    DNode *s,*p;
    //检查i位置是否合法
    //找到i结点并让指针指向它
    s = (DNode *)malloc(sizeof(DNode));
    if(s) {
        s->data = e;
        s->prior = p->prior;
        p->prior->next = s;
        s->next = p;
        p->prior = s;
        return 1;
    }
    else return 0;
}

//删除
int DlinkDelete(Doublelist L,int i,int *e) {
    DNode *p;
    //检查i是否合法
    //找到i结点并让指针指向它
    *e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    free(p);
    return 1;
}
