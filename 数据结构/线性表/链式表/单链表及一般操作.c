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

//插入

//头插法
void CreateDromHead(LinkList L) {
    Node *s;
    char c;
    int flag = 1;
    while(flag) {
        c = getchar();
        if(c != '$') {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            s->next = L->next;
            L->next = s;
        }
        else flag = 0;
    }
}

//尾插法
void CreateFromTail(LinkList L) {
    Node *r,*s;
    char c;
    int flag = 1;
    r = L;
    while(flag) {
        c = getchar();
        if(c != '$') {
            s = (Node *)malloc(sizeof(Node));
            s->data = c;
            r->next = s;
            r = s;
        }
        else {
            flag = 0;
            r->next = NULL;
        }
    }
}

//查找

//按序号查找
Node *Get(LinkList L,int i) {
    int j;
    Node *p;
    if(i <= 0) return NULL;
    p = L;
    j = 0;
    while((p->next != NULL)&&(j < i)) {
        p = p->next;
        j++;
    }
    if(i == j) return p;
    else return NULL;
}


//按值查找
Node *Locate(LinkList L,int key) {
    Node *p;
    p = L->next;
    while(p != NULL) {
        if(p->data != key)  p = p->next;
        else break;
    }

    return p;
}

//求长度
int ListLength(LinkList L) {
    Node *p;
    p = L->next;
    int j = 0;
    while(p != NULL) {
        p = p->next;
        j++;
    }
    return j;
}


//删除
int Delete(LinkList L,int i,int *e) {
    Node *pre,*r;
    int k;
    pre = L;
    k = 0;
    while(pre->next!=NULL&&k < i - 1) {
        pre = pre->next;
        k++;
    }
    if(pre->next == NULL) {
        return 0;
    }
    r = pre->next;
    pre->next = r->next;
    *e = r->data;
    free(r);

    return 1;
}
