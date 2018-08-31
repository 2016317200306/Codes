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

//����

//ͷ�巨
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

//β�巨
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

//����

//����Ų���
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


//��ֵ����
Node *Locate(LinkList L,int key) {
    Node *p;
    p = L->next;
    while(p != NULL) {
        if(p->data != key)  p = p->next;
        else break;
    }

    return p;
}

//�󳤶�
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


//ɾ��
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
